/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#ifndef _ATOMIC_
#include <atomic>
#endif // _ATOMIC_

#ifndef _MUTEX_
#include <mutex>
#endif // _MUTEX_

#ifndef _FUNCTIONAL_
#include <functional>
#endif // _FUNCTIONAL_

#ifndef _MAP_
#include <map>
#endif // _MAP_

#ifndef _STRING_
#include <string>
#endif // _STRING_

#include "IConfigurationManager.h"
#include "ConfigurationValue.h"

namespace Spectre
{
    namespace Utils
    {
        //----------------------------------------------------------
        class JsonConfigurationManager : public IConfigurationManager
        {
        public:
            explicit JsonConfigurationManager(ConfigurationStateID id, IConfigurationManagerPtr parent);
            virtual ~JsonConfigurationManager();

            virtual int AddHandler(ConfigurationPropertyChangeHandler propertyChangeHandler) override;
            virtual void RemoveHandler(int token) override;

            virtual ConfigurationString SerializeConfiguration(ConfigurationDomain domain = kConfigurationDomain_Standard) override;
            virtual ConfigurationString SerializeConfiguration(std::vector<std::wstring> ordering,
                                                               ConfigurationDomain domain = kConfigurationDomain_Standard) override;

            /// \brief
            /// Loads properties from a serialized configuration into the configuration manager.
            ///
            /// If a key already exists in the configuration manager the value will be updated to the one
            /// in the loaded configuration as long as the types are the same. If they are not the same
            /// type then the manager will throw an exception and will not accept the new value.
            ///
            /// If a key does not already exist in the configuration manager, the new property will be created
            /// if loadPolicy is ModifyAdd; otherwise the new property is ignored and a warning diagnostic message is issued.
            virtual void LoadConfiguration(ConfigurationString_ configuration, LoadPolicy policy = LoadPolicy::Modify) override;

            /// Clears the current configuration.
            virtual void ClearConfiguration() override;

            virtual bool GetBool(ConfigurationPropertyName_ propertyName, bool defaultValue = false) const override;
            virtual int GetInt(ConfigurationPropertyName_ propertyName, int defaultValue = 0) const override;
            virtual double GetDouble(ConfigurationPropertyName_ propertyName, double defaultValue = 0.0) const override;
            virtual float GetFloat(ConfigurationPropertyName_ propertyName, float defaultValue = 0.0f) const override;
            virtual ConfigurationString GetString(ConfigurationPropertyName_ propertyName, ConfigurationString defaultValue = L"") const override;

            virtual QueryResult TryGetBool(ConfigurationPropertyName_ propertyName, bool& result) const override;
            virtual QueryResult TryGetInt(ConfigurationPropertyName_ propertyName, int& result) const override;
            virtual QueryResult TryGetDouble(ConfigurationPropertyName_ propertyName, double& result) const override;
            virtual QueryResult TryGetFloat(ConfigurationPropertyName_ propertyName, float& result) const override;
            virtual QueryResult TryGetString(ConfigurationPropertyName_ propertyName, ConfigurationString& result) const override;

            /// Setting a property triggers the registered ConfigurationPropertyChangeHandlers, except for
            /// when handlers of a property change are being processed. Therefore you shall avoid setting
            /// properties from ConfigurationPropertyChangeHandlers.
            virtual PlacementResult SetBool(ConfigurationPropertyName_ propertyName, bool value, LoadPolicy policy = LoadPolicy::ModifyAdd) override;
            virtual PlacementResult SetInt(ConfigurationPropertyName_ propertyName, int value, LoadPolicy policy = LoadPolicy::ModifyAdd) override;
            virtual PlacementResult SetDouble(ConfigurationPropertyName_ propertyName, double value, LoadPolicy policy = LoadPolicy::ModifyAdd) override;
            virtual PlacementResult SetFloat(ConfigurationPropertyName_ propertyName, float value, LoadPolicy policy = LoadPolicy::ModifyAdd) override;
            virtual PlacementResult SetString(ConfigurationPropertyName_ propertyName, ConfigurationString value, LoadPolicy policy = LoadPolicy::ModifyAdd) override;

            virtual bool HasProperty(ConfigurationPropertyName_ propertyName) const override;
            virtual EConfigurationPropertyType GetPropertyType(ConfigurationPropertyName_ propertyName) const override;

            std::vector<ConfigurationPropertyName> GetKeys() const override;
            std::vector<ConfigurationPropertyName> GetKeys(const ConfigurationDomain& domain) const override;

        protected:
            mutable std::mutex m_mutex;

            // Mapping from domain names onto the root-level json value that holds the corresponding domain properties.
            mutable std::map<ConfigurationDomain, ConfigurationValue> m_domainProperties;

            std::mutex m_mutexHandlers;
            std::map<int, ConfigurationPropertyChangeHandler> m_propertyChangeHandlers;
            std::atomic_flag    m_insideTriggerHandlers = ATOMIC_FLAG_INIT; // See notes in the implementation of TriggerHandlers().

            // Template functions for setting and getting a value of a particular type.
            template <typename T> PlacementResult SetValue(ConfigurationPropertyName_ propertyName, T value, LoadPolicy policy);
            template <typename T> QueryResult TryGetValue(ConfigurationPropertyName_ propertyName, T& result) const;

            // Template functions to assist with querying values from Json and querying whether a Json::value is a particular type.
            // These are implemented using template specialization.
            template <typename T> static T GetJsonValue(const ConfigurationValue& value);
            template <typename T> static bool IsJsonType(const ConfigurationValue& value);


        private:
            void TriggerHandlers(ConfigurationPropertyName_ changedProp);
            EConfigurationPropertyType GetValueType(const ConfigurationValue& property) const;
        };

    } // namespace Utils
} // namespace Spectre
