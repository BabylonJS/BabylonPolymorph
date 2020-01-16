/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#ifndef _FUNCTIONAL_
#include <functional>
#endif // _FUNCTIONAL_

#ifndef _MAP_
#include <map>
#endif // _MAP_

#include <list>

#ifndef _STRING_
#include <string>
#endif // _STRING_

#include <memory>
#include <vector>

#include <CoreUtils/Pointers.h>

namespace Babylon
{
    namespace Utils
    {
        /// \brief
        /// A configuration property name is a unique string that specifies an individual property, and should be in one of the following forms:
        ///     "Value"
        ///     "Category.Value"
        ///     "/DomainName/Category.Value"
        ///
        /// For example:
        ///     "Lighting.Light0.Intensity"
        ///     "PostFX.SpecialEffect.Enabled"
        ///     "/ViewerPreferences/WindowSettings.Width"
        ///
        /// See ConfigurationDomain
        using ConfigurationPropertyName = std::wstring;

        /// ConfigurationPropertyName in preferred function argument passing style.
        using ConfigurationPropertyName_ = const ConfigurationPropertyName&;

        using ConfigurationPropertyChangeHandler = std::function<void(ConfigurationPropertyName_)>;

        /// \brief
        /// A configuration domain allows properties to be grouped into separate domains so that they can be accessed or loaded/saved separately.
        ///
        /// A domain specifier can be used on a property key name to specify what domain the property is stored in.
        /// A property key is of the form: "/DomainName/Group.Subgroup.Property"
        /// For example:
        ///      "/ViewerPreferences/WindowSize.X"
        ///      "/Internal/RenderDevice.Passes.DepthOnly"
        ///
        /// The domain specifier is optional: properties in the standard default domain are of the form:
        ///      "Group.Subgroup.Property"
        /// For example:
        ///      "Lighting.Light0.Color"
        ///
        /// The leading slash allows quick determination (at least relative to string-based json standards!) of whether a given property
        /// key has a domain specifier. If it has a leading slash, it must also have a second slash after the domain.
        using ConfigurationDomain = std::wstring;

        extern const ConfigurationDomain kConfigurationDomain_Standard;
        extern const ConfigurationDomain kConfigurationDomain_Internal;

        /// \brief
        /// Identifier for a specific configuration state instance.
        ///
        /// The numeric value is unique within the context of an Engine, but
        /// are not unique across multiple Engine instances.
        using ConfigurationStateID = int;

        static constexpr ConfigurationStateID kConfigurationStateID_Default = 1;
        static constexpr ConfigurationStateID kConfigurationStateID_None = 0;

        /// String encoding of configuration using JSON format.
        using ConfigurationString = std::wstring;
        using ConfigurationString_ = const ConfigurationString&;


        enum class EConfigurationPropertyType
        {
            kUnknown,
            kDouble,
            kInteger,
            kBoolean,
            kString
        };

        enum class QueryResult
        {
            OK_KeyExists,                   // Property value was retrieved.
            FAIL_KeyExistsValueWrongType,   // Value could not be retrieved because property is the wrong type.
            FAIL_KeyDoesNotExist,           // Value could not be retrieved because property name does not exist.
            FAIL_UnknownError               // Property value could not be retrieved owing to unknown error.
        };

        enum class PlacementResult
        {
            OK_Added,                       // Property was added and its value set to the requested value.
            OK_Modified,                    // Existing property had value set to requested value.
            OK_Unchanged,                   // Existing property was already at requested value. No change.
            FAIL_KeyExists,                 // Property already exists and behaviour is 'Add', so it was not changed.
            FAIL_KeyDoesNotExist,           // Property does not exist and behviour is 'Modify', so it was not created.
            FAIL_KeyExistsValueWrongType,   // Property exists but is not the requested type, so it cannot be changed.
            FAIL_UnknownError               // Property value could not be set owing to unknown problem.
        };


        //----------------------------------------------------------

        /// \brief
        /// IConfigurationManager is an interface to a configuration manager that provides a collection or
        /// "property bag" of key-value properties, along with serialization support.
        ///
        /// The keys are property names (see ConfigurationPropertyName).
        /// The values are of various types (see EConfigurationPropertyType).
        class IConfigurationManager :
            public std::enable_shared_from_this<IConfigurationManager>
        {
        public:
            explicit IConfigurationManager(ConfigurationStateID id, const IConfigurationManagerPtr& parent);
            virtual ~IConfigurationManager();

            ConfigurationStateID GetID() const;
            IConfigurationManagerPtr GetParent() const;

            virtual int AddHandler(ConfigurationPropertyChangeHandler propertyChangeHandler) = 0;
            virtual void RemoveHandler(int token) = 0;

            /// Serializes all properties in the specified domain into a string.
            virtual ConfigurationString SerializeConfiguration(ConfigurationDomain domain = kConfigurationDomain_Standard) = 0;
            virtual ConfigurationString SerializeConfiguration(std::vector<std::wstring> ordering,
                ConfigurationDomain domain = kConfigurationDomain_Standard) = 0;

            /// Enumeration of available loading policies, specifying the behaviour for loading properties from serialized source.
            enum class LoadPolicy
            {
                /// Modify any existing properties that match the properties being loaded,
                /// but do not add any new properties (a diagnostic warning is issued via debug output)
                Modify,

                /// Modify any existing properties that match the properties being loaded,
                /// and add any new properties that are needed.
                ModifyAdd,

                /// Add new properties but do not modify existing properties
                Add,
            };

            /// \brief
            /// Loads the serialized configuration into all properties specified.
            ///
            /// If the configuration contains properties from multiple domains then all properties will be
            /// loaded, each into the appropriate domain.
            virtual void LoadConfiguration(ConfigurationString_ configuration, LoadPolicy policy = LoadPolicy::Modify) = 0;

            virtual void ClearConfiguration() = 0;

            /// Returns the domain corresponding to the specified property name.
            virtual ConfigurationDomain GetDomain(ConfigurationPropertyName_ propertyName) const;

            /// The "Get(Type)" functions retrieve the value for a specified configuration property, and if the
            /// property does not exist (or is the wrong type) they return a default value.
            virtual bool GetBool(ConfigurationPropertyName_ propertyName, bool defaultValue = false) const = 0;
            virtual int GetInt(ConfigurationPropertyName_ propertyName, int defaultValue = 0) const = 0;
            virtual double GetDouble(ConfigurationPropertyName_ propertyName, double defaultValue = 0.0) const = 0;
            virtual float GetFloat(ConfigurationPropertyName_ propertyName, float defaultValue = 0.0f) const = 0;
            virtual std::wstring GetString(ConfigurationPropertyName_ propertyName, std::wstring defaultValue = L"") const = 0;

            /// The "TryGet(Type)" functions try to retrieve the value of a specified configuration property.
            /// If successful the value is placed in an 'out' parameter. If unsuccesful the 'out' paramter is
            /// not altered. The functions return a QueryResult which can be used to determine whether the value
            /// was placed into the 'out' parameter, and if not to determine why this was not possible.
            virtual QueryResult TryGetBool(ConfigurationPropertyName_ propertyName, bool& result) const = 0;
            virtual QueryResult TryGetInt(ConfigurationPropertyName_ propertyName, int& result) const = 0;
            virtual QueryResult TryGetDouble(ConfigurationPropertyName_ propertyName, double& result) const = 0;
            virtual QueryResult TryGetFloat(ConfigurationPropertyName_ propertyName, float& result) const = 0;
            virtual QueryResult TryGetString(ConfigurationPropertyName_ propertyName, std::wstring& result) const = 0;

            /// The "Set(Type)" functions attempt to set a specified configuration property to a new value. They return
            /// a PlacementResult which describes what happened (whether the attempt to set the new value was successful or
            /// not, and if not why it was not possible).
            /// The functions operate in one of three modes:
            /// - 'Add' : Create the new property and set its value, but only if it does not exist already.
            /// - 'ModifyAdd' : Set the property's new value it it already exists. Create it if it does not exist.
            /// - 'Modify' : Set the property's new value if it already exists, but if not then do not create it.
            virtual PlacementResult SetBool(ConfigurationPropertyName_ propertyName, bool value, LoadPolicy policy = LoadPolicy::ModifyAdd) = 0;
            virtual PlacementResult SetInt(ConfigurationPropertyName_ propertyName, int value, LoadPolicy policy = LoadPolicy::ModifyAdd) = 0;
            virtual PlacementResult SetDouble(ConfigurationPropertyName_ propertyName, double value, LoadPolicy policy = LoadPolicy::ModifyAdd) = 0;
            virtual PlacementResult SetFloat(ConfigurationPropertyName_ propertyName, float value, LoadPolicy policy = LoadPolicy::ModifyAdd) = 0;
            virtual PlacementResult SetString(ConfigurationPropertyName_ propertyName, std::wstring value, LoadPolicy policy = LoadPolicy::ModifyAdd) = 0;

            virtual bool HasProperty(ConfigurationPropertyName_ propertyName) const = 0;
            virtual EConfigurationPropertyType GetPropertyType(ConfigurationPropertyName_ propertyName) const = 0;

            void ToggleBool(ConfigurationPropertyName_ propertyName);

            template<typename EnumType>
            EnumType GetEnum(ConfigurationPropertyName_ propertyName, EnumType defaultValue = EnumType())
            {
                return static_cast<EnumType>(GetInt(propertyName, int(defaultValue)));
            }

            template<typename EnumType>
            void SetEnum(ConfigurationPropertyName_ propertyName, EnumType enumValue)
            {
                SetInt(propertyName, int(enumValue));
            }

            /// \brief
            /// Get all the configuration property keys regardless of domain
            virtual std::vector<ConfigurationPropertyName> GetKeys() const = 0;

            /// \brief
            /// Get all the configuration property keys for the specified domain
            virtual std::vector<ConfigurationPropertyName> GetKeys(const ConfigurationDomain& domain) const = 0;

            IConfigurationManager() = default;
            IConfigurationManager(const IConfigurationManagerPtr&) = delete;
            IConfigurationManager& operator=(const IConfigurationManagerPtr&) = delete;

        protected:
            std::list<std::weak_ptr<IConfigurationManager>> GetChildren() const
            {
                return m_children;
            }

        private:
            const ConfigurationStateID m_id;
            IConfigurationManagerPtr m_parent;
            std::list<std::weak_ptr<IConfigurationManager>> m_children;
        };

        using ConfigurationState = IConfigurationManager;

    } // namespace Utils
} // namespace Babylon
