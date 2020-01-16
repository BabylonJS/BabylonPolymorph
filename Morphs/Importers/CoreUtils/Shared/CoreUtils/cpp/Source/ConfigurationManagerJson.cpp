/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <string>
#include <unordered_set>

#include <CoreUtils/ConfigurationManagerJson.h>
#include <CoreUtils/Assert.h>
#include <CoreUtils/Trace.h>
#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/ScopeWarden.h>
#include <CoreUtils/RapidJson.h>

DEFINE_TRACE_AREA(ConfigurationManager, 0);

namespace Babylon
{
    namespace Utils
    {
        using namespace Babylon::rapidjson;

        typedef GenericDocument<UTF16<>> JDocument;
        typedef GenericValue<UTF16<>> JValue;
        typedef GenericStringBuffer<UTF16<>> JStringBuffer;
        typedef Writer<JStringBuffer, UTF16<>> JWriter;

        //----------------------------------------------------------
        JsonConfigurationManager::JsonConfigurationManager(ConfigurationStateID id, IConfigurationManagerPtr parent) :
            IConfigurationManager(id, parent)
        {
        }

        //----------------------------------------------------------
        JsonConfigurationManager::~JsonConfigurationManager()
        {
        }

        //----------------------------------------------------------
        int JsonConfigurationManager::AddHandler(ConfigurationPropertyChangeHandler propertyChangeHandler)
        {
            std::lock_guard<std::mutex> lock(m_mutexHandlers);

            auto max_id = 0;
            auto iterator = m_propertyChangeHandlers.rbegin();
            if (iterator != m_propertyChangeHandlers.rend())
            {
                max_id = iterator->first;
                max_id++;
            }

            m_propertyChangeHandlers[max_id] = propertyChangeHandler;
            return max_id;
        }

        //----------------------------------------------------------
        void JsonConfigurationManager::RemoveHandler(int token)
        {
            std::lock_guard<std::mutex> lock(m_mutexHandlers);

            m_propertyChangeHandlers.erase(token);
        }

        /// <summary>
        /// Add a new json member
        /// </summary>
        /// <param name="writer">RapidJson writer</param>
        /// <param name="name">json property name</param>
        /// <param name="value">Configuration value</param>
        //----------------------------------------------------------
        template <typename JWriter>
        void AddJsonMember(JWriter& writer, std::wstring name, ConfigurationValue& value)
        {
            writer.String(name.c_str());
            switch (value.GetType())
            {
            case ConfigurationValue::Boolean:
                writer.Bool(value.GetBool());
                break;
            case ConfigurationValue::Integer:
                writer.Int(value.GetInteger());
                break;
            case ConfigurationValue::Double:
                writer.Double(value.GetDouble());
                break;
            case ConfigurationValue::Float:
                writer.Double(value.GetFloat());
                break;
            case ConfigurationValue::String:
                writer.String(value.GetString().c_str());
                break;
            case ConfigurationValue::Object:
                break;
            }
        }

        /// <summary>
        /// Write new json members from Configuration values
        /// </summary>
        /// <param name="writer">RapidJson writer</param>
        /// <param name="content">Configuration content object</param>
        //----------------------------------------------------------
        template <typename JWriter>
        void AddJsonMembers(JWriter& writer, ConfigurationValue& content)
        {
            std::vector<std::wstring> keys = content.GetKeys();

            for (auto const& name : keys)
            {
                auto& value = content.GetContent(name);
                if (value.IsObject())
                {
                    writer.String(name.c_str());
                    writer.StartObject();
                    AddJsonMembers(writer, value);
                    writer.EndObject();
                }
                else
                {
                    AddJsonMember(writer, name, value);
                }
            }
        }

        /// <summary>
        /// Write new json members from Configuration values in desired ordering
        /// </summary>
        /// <param name="writer">RapidJson writer</param>
        /// <param name="content">Configuration content object</param>
        //----------------------------------------------------------
        template <typename JWriter>
        void AddJsonMembers(JWriter& writer, ConfigurationValue& content, const std::vector<std::wstring>& ordering)
        {
            std::vector<std::wstring> keys = content.GetKeys();
            std::vector<std::wstring> orderedKeys;

            for (auto const& orderkey : ordering)
            {
                auto it = std::find(keys.begin(), keys.end(), orderkey);
                if (it != keys.end())
                {
                    orderedKeys.push_back(*it);
                }
            }

            for (auto const& name : orderedKeys)
            {
                auto& value = content.GetContent(name);
                if (value.IsObject())
                {
                    writer.String(name.c_str());
                    writer.StartObject();
                    AddJsonMembers(writer, value);
                    writer.EndObject();
                }
                else
                {
                    AddJsonMember(writer, name, value);
                }
            }
        }

        /// <summary>
        /// Serialize Configuration values to JSON string
        /// </summary>
        /// <param name="configValue">Configuration Value</param>
        //----------------------------------------------------------
        std::wstring Serialize(ConfigurationValue& configValue)
        {
            JStringBuffer buffer;
            JWriter writer(buffer);
            writer.StartObject();
            AddJsonMembers(writer, configValue);
            writer.EndObject();
            return std::wstring(buffer.GetString());
        }

        /// <summary>
        /// Serialize Configuration values to JSON string in order specified by "ordering"
        /// </summary>
        /// <param name="configValue">Configuration Value</param>
        //----------------------------------------------------------
        std::wstring Serialize(ConfigurationValue& configValue, std::vector<std::wstring> ordering)
        {
            JStringBuffer buffer;
            JWriter writer(buffer);
            writer.StartObject();
            AddJsonMembers(writer, configValue, ordering);
            writer.EndObject();
            return std::wstring(buffer.GetString());
        }

        //----------------------------------------------------------
        ConfigurationString JsonConfigurationManager::SerializeConfiguration(ConfigurationDomain domain)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            auto& jsonProperties = m_domainProperties[domain];
            ConfigurationString result = Serialize(jsonProperties);
            return result;
        }

        ConfigurationString JsonConfigurationManager::SerializeConfiguration(std::vector<std::wstring> ordering, ConfigurationDomain domain)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            auto& jsonProperties = m_domainProperties[domain];
            ConfigurationString result = Serialize(jsonProperties, ordering);
            return result;
        }

        /// <summary>
        /// Compare Json value type with Configuration value type
        /// </summary>
        /// <param name="value">Json Value</param>
        /// <param name="configValue">Configuration Value</param>
        //----------------------------------------------------------
        bool IsSameValueType(const JValue& value, ConfigurationValue configValue)
        {
            switch (configValue.GetType())
            {
            case ConfigurationValue::Boolean:
                return value.IsBool();
            case ConfigurationValue::Integer:
            case ConfigurationValue::Double:
            case ConfigurationValue::Float:
                return value.IsNumber();
            case ConfigurationValue::Object:
                return  value.IsObject();
            case ConfigurationValue::String:
                return value.IsString();
            }
            return false;
        }

        /// <summary>
        /// Add new Configuration object from Json value
        /// </summary>
        /// <param name="value">Json Value</param>
        /// <param name="configValue">Configuration Value</param>
        /// <param name="key">Property name</param>
        //----------------------------------------------------------
        void SetObjectValue(const JValue& value, ConfigurationValue& configValue, std::wstring key)
        {
            if (value.IsString())
            {
                const std::wstring& valueString = std::wstring(value.GetString());
                configValue.SetValue(key, valueString);
            }
            else if (value.IsInt())
            {
                configValue.SetValue(key, value.GetInt());
            }
            else if (value.IsDouble())
            {
                configValue.SetValue(key, value.GetDouble());
            }
            else if (value.IsFloat())
            {
                configValue.SetValue(key, value.GetFloat());
            }
            else if (value.IsBool())
            {
                configValue.SetValue(key, value.GetBool());
            }
            else
            {
                const std::wstring valueKey = L"Value";
                auto& newValue = configValue.GetContent(key);

                auto it = value.FindMember(valueKey.c_str());
                if (it != value.MemberEnd())
                {
                    SetObjectValue(it->value, newValue, valueKey);
                }
            }
        }

        /// <summary>
        /// Deserializes the configuration.
        /// </summary>
        /// <param name="configuration">The configuration.</param>
        //----------------------------------------------------------
        void JsonConfigurationManager::LoadConfiguration(ConfigurationString_ configuration, LoadPolicy policy)
        {
            try
            {
                JDocument configurationProperties;
                std::unordered_set<ConfigurationPropertyName> changedProps;
                configurationProperties.Parse(configuration.c_str());
                if (configurationProperties.HasParseError())
                {
                    auto error = configurationProperties.GetParseError();
                    auto offset = configurationProperties.GetErrorOffset();
                    throw BabylonException("Error parsing configuration: Parse error code " + std::to_string(error) + " at input offset " + std::to_string(offset));
                }
                else
                {
                    // Now that we have parsed the input properties. lock the mutex.
                    std::lock_guard<std::mutex> lock(m_mutex);

                    // If values already exist as part of the configuration then here we want to manually filter the results of the
                    // changes we are trying to load into the configuration
                    for (const auto& iter : configurationProperties.GetObject())
                    {
                        const auto& key = iter.name.GetString();
                        auto& value = configurationProperties[key];

                        auto& jsonProperties = m_domainProperties[GetDomain(key)];
                        if (jsonProperties.HasKey(key) && policy != LoadPolicy::Add)
                        {
                            // If the configuration manager already contains this key then we want to update the value stored
                            auto& property = jsonProperties.GetContent(key);
                            bool updateValueFailed = false;

                            // There are potentially times where we want the property types to be different in order to allow
                            // json object types to go to raw number types but this is more of a legacy issue from filling out
                            // the debug menu.
                            if (IsSameValueType(value, property))
                            {
                                // Both 'integer' and 'double' are regarded as 'number' for purposes of the above type test.
                                // To allow automatic conversion from integer values (stored in json generated by web)
                                // into double values (expected by the more strongly-typed json configuration manager on C++),
                                // we promote integers to doubles where the destination is already a double.
                                if (value.IsInt() && property.IsDouble())
                                {
                                    auto i = value.GetInt();
                                    auto d = static_cast<double>(i);
                                    jsonProperties.SetValue(key, d);
                                }
                                else
                                {
                                    SetObjectValue(value, jsonProperties, key);
                                }
                            }
                            else if (value.IsObject() || property.IsObject())
                            {
                                if (value.IsObject())
                                {
                                    const std::wstring valueKey = L"Value";
                                    auto it = value.FindMember(valueKey.c_str());
                                    if (it != value.MemberEnd())
                                    {
                                        // If the underlying value type is the same as the property type.
                                        // then we are happy to overwrite the current property stored with the object.
                                        if (IsSameValueType(it->value, property))
                                        {
                                            SetObjectValue(value, jsonProperties, key);
                                        }
                                        else
                                        {
                                            // Failed value in object is different type than
                                            // property stored in configuration
                                            updateValueFailed = true;
                                        }
                                    }
                                    else
                                    {
                                        // Failed object doesn't contain "value" property
                                        updateValueFailed = true;
                                    }
                                }
                                else if (property.IsObject())
                                {
                                    const std::wstring valueKey = L"Value";
                                    if (property.HasKey(valueKey.c_str()))
                                    {
                                        // If the underlying value type is the same as the property type.
                                        // then we are happy to overwrite the value of the object with the new
                                        // value
                                        auto& propertyValue = property.GetContent(valueKey);
                                        if (IsSameValueType(value, propertyValue))
                                        {
                                            SetObjectValue(value, property, valueKey);
                                        }
                                        else
                                        {
                                            // Failed value from loaded configuration is
                                            // different than the value stored in the object
                                            updateValueFailed = true;
                                        }
                                    }
                                    else
                                    {
                                        // Failed No value parameter found in object.
                                        // Something has gone wrong if there is no value
                                        // stored in the object so in this case we are happy
                                        // to replace the currently stored object with the
                                        // given object.
                                        SetObjectValue(value, property, key);
                                        auto outputKey = LexicalCast<std::string>(key);
                                        std::string output = "WARNING: Object stored in ConfigurationManager with key<" + outputKey + "> has no value. Property has been replaced with loaded value.\n";
                                        TRACE_IMPORTANT(ConfigurationManager, output.c_str());
                                    }
                                }
                            }
                            else
                            {
                                updateValueFailed = true;
                            }

                            // If we failed to update the value then we Output the debug string.
                            // Throwing an exception would interrupt the loading of the JSON here.
                            // We just want to warn the user that the value in the configuration wasn't
                            // replaced due to an issue.
                            if (updateValueFailed)
                            {
                                auto outputKey = LexicalCast<std::string>(key);
                                std::string output = "WARNING: Object stored in ConfigurationManager with key<" + outputKey + "> was not replaced by loaded configuration due to an error.\n";
                                TRACE_IMPORTANT(ConfigurationManager, output.c_str());
                            }
                            else
                            {
                                changedProps.insert(key);
                            }
                        }
                        else
                        {
                            // If code execution got to here then either the key wasn't found, or it WAS found but the policy was "Add"
                            // which means that the user wanted to add new keys but not modify existing ones.
                            if (policy == LoadPolicy::ModifyAdd)
                            {
                                // If the configuration manager doesn't contain this key then we want to add it to the json properties property
                                SetObjectValue(value, jsonProperties, key);
                                changedProps.insert(key);
                            }
                            else
                            {
                                auto outputKey = LexicalCast<std::string>(key);
                                std::string output;
                                if (policy == LoadPolicy::Modify)
                                {
                                    output = "WARNING: Unknown property stored in serialized configuration with name <" + outputKey + "> was ignored because load policy is 'Modify' rather than 'Add' or 'ModifyAdd'\n";
                                }
                                else
                                {
                                    // If code execution reaches here then key was found, but policy is 'Add'.
                                    output = "WARNING: Property with name <" + outputKey + "> is already in configuration and load policy is 'Add', so the new value was not loaded\n";
                                }
                                TRACE_IMPORTANT(ConfigurationManager, output.c_str());
                            }
                        }
                    }
                }

                // Trigger handlers for every property that was successfully loaded. (NOTE: They may have been loaded but not changed. The load function
                // does not currently check whether properties are left unchanged or not during loading).
                for (const auto& prop : changedProps)
                {
                    TriggerHandlers(prop);
                }
            }
            catch (...)
            {
                TRACE_IMPORTANT(ConfigurationManager, "Failed to deserialise the JSON configuration. Check the configuration format.");
                throw;
            }
        }

        //----------------------------------------------------------
        void JsonConfigurationManager::ClearConfiguration()
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            m_domainProperties.clear();
            m_domainProperties[kConfigurationDomain_Standard] = ConfigurationValue();
            m_domainProperties[kConfigurationDomain_Internal] = ConfigurationValue();

            // TODO: Set this to trigger handlers to inform clients that all properties have been cleared.
        }

        //----------------------------------------------------------
        bool JsonConfigurationManager::GetBool(const ConfigurationPropertyName& propertyName, bool defaultValue) const
        {
            bool result;
            if (TryGetValue(propertyName, result) == QueryResult::OK_KeyExists)
            {
                return result;
            }
            else
            {
                return defaultValue;
            }
        }

        //----------------------------------------------------------
        int JsonConfigurationManager::GetInt(const ConfigurationPropertyName& propertyName, int defaultValue) const
        {
            int result;

            if (TryGetValue(propertyName, result) == QueryResult::OK_KeyExists)
            {
                return result;
            }
            else
            {
                return defaultValue;
            }
        }

        //----------------------------------------------------------
        double JsonConfigurationManager::GetDouble(const ConfigurationPropertyName& propertyName, double defaultValue) const
        {
            double result;

            if (TryGetValue(propertyName, result) == QueryResult::OK_KeyExists)
            {
                return result;
            }
            else
            {
                return defaultValue;
            }
        }

        //----------------------------------------------------------
        float JsonConfigurationManager::GetFloat(const ConfigurationPropertyName& propertyName, float defaultValue) const
        {
            // Note: lock is inside GetDouble() so this is thread safe.
            auto doubleValue = GetDouble(propertyName, defaultValue);
            return static_cast<float>(doubleValue);
        }

        //----------------------------------------------------------
        std::wstring JsonConfigurationManager::GetString(const ConfigurationPropertyName& propertyName, std::wstring defaultValue) const
        {
            std::wstring result;
            if (TryGetValue(propertyName, result) == QueryResult::OK_KeyExists)
            {
                return result;
            }
            else
            {
                return defaultValue;
            }
        }

        template <typename T> QueryResult JsonConfigurationManager::TryGetValue(const ConfigurationPropertyName& propertyName, T& result) const
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            auto& jsonProperties = m_domainProperties[GetDomain(propertyName)];
            if (!jsonProperties.HasKey(propertyName.c_str()))
            {
                if (auto parent = GetParent())
                {
                    JsonConfigurationManager& parentJSON = static_cast<JsonConfigurationManager&>(*parent);
                    return parentJSON.TryGetValue<T>(propertyName, result);
                }
                else
                {
                    return QueryResult::FAIL_KeyDoesNotExist;
                }
            }

            auto& property = jsonProperties.GetContent(propertyName);
            if (property.IsObject())
            {
                const std::wstring valueKey = L"Value";
                if (property.HasKey(valueKey.c_str()))
                {
                    auto& object = property.GetContent(valueKey);
                    if (IsJsonType<T>(object))
                    {
                        result = GetJsonValue<T>(object);
                        return QueryResult::OK_KeyExists;

                    }
                }
                return QueryResult::FAIL_KeyExistsValueWrongType;

            }
            else if (!IsJsonType<T>(property))
            {
                return QueryResult::FAIL_KeyExistsValueWrongType;
            }

            result = property.GetValue<T>();
            return QueryResult::OK_KeyExists;
        }

        QueryResult JsonConfigurationManager::TryGetBool(const ConfigurationPropertyName& propertyName, bool& result) const
        {
            return TryGetValue(propertyName, result);
        }

        QueryResult JsonConfigurationManager::TryGetInt(const ConfigurationPropertyName& propertyName, int& result) const
        {
            return TryGetValue(propertyName, result);
        }

        QueryResult JsonConfigurationManager::TryGetDouble(const ConfigurationPropertyName& propertyName, double& result) const
        {
            return TryGetValue(propertyName, result);
        }

        QueryResult JsonConfigurationManager::TryGetFloat(const ConfigurationPropertyName& propertyName, float& result) const
        {
            // Note: lock is inside GetDouble() (called by TryGetDouble) so this is thread safe.
            double doubleValue;
            auto QueryResult = TryGetDouble(propertyName, doubleValue);
            if (QueryResult == QueryResult::OK_KeyExists)
            {
                result = static_cast<float>(doubleValue);
            }
            return QueryResult;
        }

        QueryResult JsonConfigurationManager::TryGetString(const ConfigurationPropertyName& propertyName, std::wstring& result) const
        {
            return TryGetValue(propertyName, result);
        }

        PlacementResult JsonConfigurationManager::SetBool(const ConfigurationPropertyName& propertyName, bool value, LoadPolicy policy)
        {
            return SetValue(propertyName, value, policy);
        }

        PlacementResult JsonConfigurationManager::SetInt(const ConfigurationPropertyName& propertyName, int value, LoadPolicy policy)
        {
            return SetValue(propertyName, value, policy);
        }

        PlacementResult JsonConfigurationManager::SetDouble(const ConfigurationPropertyName& propertyName, double value, LoadPolicy policy)
        {
            return SetValue(propertyName, value, policy);
        }

        PlacementResult JsonConfigurationManager::SetFloat(const ConfigurationPropertyName& propertyName, float value, LoadPolicy policy)
        {
            return SetValue(propertyName, double{ value }, policy);
        }

        PlacementResult JsonConfigurationManager::SetString(const ConfigurationPropertyName& propertyName, std::wstring value, LoadPolicy policy)
        {
            return SetValue(propertyName, value, policy);
        }

        template <> bool JsonConfigurationManager::GetJsonValue<bool>(const ConfigurationValue& value)
        {
            return value.GetBool();
        }

        template <> int JsonConfigurationManager::GetJsonValue<int>(const ConfigurationValue& value)
        {
            return value.GetInteger();
        }

        template <> std::wstring JsonConfigurationManager::GetJsonValue<std::wstring>(const ConfigurationValue& value)
        {
            return value.GetString();
        }

        template <> double JsonConfigurationManager::GetJsonValue<double>(const ConfigurationValue& value)
        {
            return value.GetDouble();
        }

        template <> bool JsonConfigurationManager::IsJsonType<int>(const ConfigurationValue& value)
        {
            return value.IsInt();
        }

        template <> bool JsonConfigurationManager::IsJsonType<double>(const ConfigurationValue& value)
        {
            return value.IsDouble();
        }

        template <> bool JsonConfigurationManager::IsJsonType<bool>(const ConfigurationValue& value)
        {
            return value.IsBool();
        }

        template <> bool JsonConfigurationManager::IsJsonType<std::wstring>(const ConfigurationValue& value)
        {
            return value.IsString();
        }

        template <typename T> PlacementResult JsonConfigurationManager::SetValue(const ConfigurationPropertyName& propertyName, T value, LoadPolicy policy)
        {
            PlacementResult result;
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                auto propName = GetDomain(propertyName);
                auto& jsonProperties = m_domainProperties[propName];
                if (jsonProperties.HasKey(propertyName.c_str()))
                {
                    if (policy != LoadPolicy::Add)
                    {
                        auto& property = jsonProperties.GetContent(propertyName);
                        if (property.IsObject())
                        {
                            const std::wstring valueKey = L"Value";
                            if (property.HasKey(valueKey.c_str()))
                            {
                                auto& object = property.GetContent(valueKey);
                                if (IsJsonType<T>(object))
                                {
                                    if (GetJsonValue<T>(object) != value)
                                    {
                                        property.SetValue(valueKey, value);
                                        result = PlacementResult::OK_Modified;
                                    }
                                    else
                                    {
                                        result = PlacementResult::OK_Unchanged;
                                    }
                                }
                                else
                                {
                                    result = PlacementResult::FAIL_KeyExistsValueWrongType;
                                }
                            }
                            else
                            {
                                // Key is an object but does not contain a value property so cannot be set.
                                result = PlacementResult::FAIL_KeyExistsValueWrongType;
                            }
                        }
                        else if (IsJsonType<T>(property))
                        {
                            if (GetJsonValue<T>(property) != value)
                            {
                                jsonProperties.SetValue(propertyName, value);
                                result = PlacementResult::OK_Modified;
                            }
                            else
                            {
                                result = PlacementResult::OK_Unchanged;
                            }
                        }
                        else
                        {
                            // Property already exists but isn't the same type, so we cannot modify it
                            result = PlacementResult::FAIL_KeyExistsValueWrongType;
                        }
                    }
                    else
                    {
                        // Policy is 'Add', but the config value is already loaded.
                        result = PlacementResult::FAIL_KeyExists;
                    }
                }
                else
                {
                    // property doesn't exist in loaded config. Add it if load policy is 'Add' or 'ModifyAdd', otherwise do nothing and return appropriate result
                    if (policy == LoadPolicy::Add || policy == LoadPolicy::ModifyAdd)
                    {
                        jsonProperties.SetValue(propertyName, value);
                        result = PlacementResult::OK_Added;
                    }
                    else
                    {
                        result = PlacementResult::FAIL_KeyDoesNotExist;
                    }
                }
            }

            if (result == PlacementResult::OK_Added || result == PlacementResult::OK_Modified)
            {
                TriggerHandlers(propertyName);
            }

            return result;
        }

        //----------------------------------------------------------
        bool JsonConfigurationManager::HasProperty(const ConfigurationPropertyName& propertyName) const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            auto& jsonProperties = m_domainProperties[GetDomain(propertyName)];
            return jsonProperties.HasKey(propertyName.c_str());
        }

        //----------------------------------------------------------
        EConfigurationPropertyType JsonConfigurationManager::GetPropertyType(const ConfigurationPropertyName& propertyName) const
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            auto type = EConfigurationPropertyType::kUnknown;

            if (!propertyName.empty())
            {
                auto& jsonProperties = m_domainProperties[GetDomain(propertyName)];
                if (jsonProperties.HasKey(propertyName.c_str()))
                {
                    type = GetValueType(jsonProperties.GetContent(propertyName));
                }
            }

            return type;
        }

        //----------------------------------------------------------
        void JsonConfigurationManager::TriggerHandlers(const ConfigurationPropertyName& prop)
        {
            if (!m_insideTriggerHandlers.test_and_set())
            {
                // Until the need for making m_mutexHandlers recursive is proven, i.e.
                // as a minimal fix that doesn't mask other errors, we need to flag the
                // fact that we're in here, so that at least we ourselves don't try to
                // call TriggerHandlers() recursively.
                // Note that the above check is here as a matter of convenience, because
                // TriggerHandlers() is private and only called from one location,
                // SetValue(). Otherwise the check should be made at the location of
                // call and we should have an assert here.
                // This measure was necessary because of issue 8711531.

                // No matter what way we're exiting this scope, we must stop ignoring
                // calls to TriggerHandlers().
                SCOPE_WARDEN(insideTriggerHandlersGuard, { m_insideTriggerHandlers.clear(); });

                std::lock_guard<std::mutex> lock(m_mutexHandlers);

                for (const auto& handler : m_propertyChangeHandlers)
                {
                    handler.second(prop);
                }
            }
            else
            {
                TRACE_WARN(ConfigurationManager,
                    "A recursive call to TriggerHandlers() with property name '%ls' was ignored.",
                    prop.c_str());
            }
        }

        //----------------------------------------------------------
        EConfigurationPropertyType JsonConfigurationManager::GetValueType(const ConfigurationValue& property) const
        {
            auto jsonType = property.GetType();

            // Constant needed for accessing values in an object
            const std::wstring valueKey = L"Value";
            switch (jsonType)
            {
            case ConfigurationValue::Double:
                return EConfigurationPropertyType::kDouble;
            case ConfigurationValue::Integer:
                return EConfigurationPropertyType::kInteger;
            case ConfigurationValue::Boolean:
                return EConfigurationPropertyType::kBoolean;
            case ConfigurationValue::String:
                return EConfigurationPropertyType::kString;
            case ConfigurationValue::Object:
            {
                if (property.HasKey(valueKey.c_str()))
                {
                    return GetValueType(property.GetContent(valueKey));
                }
                else
                {
                    return EConfigurationPropertyType::kUnknown;
                }
            }
            default:
                return EConfigurationPropertyType::kUnknown;
            }
        }

        std::vector<ConfigurationPropertyName> JsonConfigurationManager::GetKeys() const
        {
            std::vector<ConfigurationPropertyName> keys;

            for (const auto& domainProperty : m_domainProperties)
            {
                auto keysDomain = GetKeys(domainProperty.first);

                keys.insert(keys.end(),
                    std::make_move_iterator(keysDomain.begin()),
                    std::make_move_iterator(keysDomain.end()));
            }

            return keys;
        }

        std::vector<ConfigurationPropertyName> JsonConfigurationManager::GetKeys(const ConfigurationDomain& domain) const
        {
            auto it = m_domainProperties.find(domain);

            if (it != m_domainProperties.end())
            {
                return it->second.GetKeys();
            }

            return {};
        }

    } // End namespace Engine

} // End namespace Babylon
