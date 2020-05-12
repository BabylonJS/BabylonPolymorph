/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#ifndef _UNORDERED_MAP_
#include <unordered_map>
#endif // _UNORDERED_MAP_

#ifndef _STRING_
#include <string>
#endif // _STRING_

namespace Babylon
{
    namespace Utils
    {
        class ConfigurationValue {
        public:
            typedef std::unordered_map<std::wstring, ConfigurationValue> ConfigObject;

            enum ContentType {
                String,
                Integer,
                Double,
                Float,
                Boolean,
                Object
            };

            ConfigurationValue();

            ~ConfigurationValue();

            ContentType GetType() const;

            bool IsObject() const;
            bool IsInt() const;
            bool IsDouble() const;
            bool IsString() const;
            bool IsBool() const;
            bool HasKey(const wchar_t* key) const;

            std::wstring GetString() const;
            int GetInteger() const;
            double GetDouble() const;
            float GetFloat() const;
            bool GetBool() const;
            ConfigurationValue& GetContent(std::wstring key) const;
            std::vector<std::wstring> GetKeys();

            template <typename T> T GetValue();
            template <typename T> void SetValue(std::wstring key, T value);


        private:
            ContentType m_contentType;
            std::wstring m_strContent;
            int m_intContent;
            double m_dContent;
            float m_fContent;
            bool m_bContent;
            mutable ConfigObject m_oContent;

            template <typename T> void SetValue(T value);

        };

        template<>
        inline std::wstring ConfigurationValue::GetValue()
        {
            return m_strContent;
        }

        template<>
        inline int ConfigurationValue::GetValue()
        {
            return m_intContent;
        }

        template<>
        inline double ConfigurationValue::GetValue()
        {
            return m_dContent;
        }

        template<>
        inline float ConfigurationValue::GetValue()
        {
            return m_fContent;
        }

        template<>
        inline bool ConfigurationValue::GetValue()
        {
            return m_bContent;
        }

        template<typename T>
        inline void ConfigurationValue::SetValue(std::wstring key, T value)
        {
            m_oContent[key.c_str()].SetValue<T>(value);
        }

        template<>
        inline void ConfigurationValue::SetValue(bool value)
        {
            m_bContent = value;
            m_contentType = Boolean;
        }

        template<>
        inline void ConfigurationValue::SetValue(int value)
        {
            m_intContent = value;
            m_contentType = Integer;
        }

        template<>
        inline void ConfigurationValue::SetValue(double value)
        {
            m_dContent = value;
            m_contentType = Double;
        }

        template<>
        inline void ConfigurationValue::SetValue(float value)
        {
            m_fContent = value;
            m_contentType = Float;
        }

        template<>
        inline void ConfigurationValue::SetValue(std::wstring value)
        {
            m_strContent = value;
            m_contentType = String;
        }
    }
}
