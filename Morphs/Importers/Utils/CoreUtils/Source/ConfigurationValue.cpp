/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"
#include "CoreUtils/ConfigurationValue.h"

using namespace Babylon::Utils;

ConfigurationValue::ConfigurationValue(): m_contentType(ConfigurationValue::Object)
{
}

ConfigurationValue::~ConfigurationValue()
{
}

ConfigurationValue::ContentType ConfigurationValue::GetType() const
{
    return m_contentType;
}

bool ConfigurationValue::IsObject() const
{
    return m_contentType == ConfigurationValue::Object;
}

bool ConfigurationValue::IsInt() const
{
    return m_contentType == ConfigurationValue::Integer;
}

bool ConfigurationValue::IsDouble() const
{
    return m_contentType == ConfigurationValue::Double;
}

bool ConfigurationValue::IsString() const
{
    return m_contentType == ConfigurationValue::String;
}

bool ConfigurationValue::IsBool() const
{
    return m_contentType == ConfigurationValue::Boolean;
}

bool ConfigurationValue::HasKey(const wchar_t* key) const
{
    return m_oContent.find(key) != m_oContent.end();
}

std::wstring ConfigurationValue::GetString() const
{
    return m_strContent;
}

int ConfigurationValue::GetInteger() const
{
    return m_intContent;
}

double ConfigurationValue::GetDouble() const
{
    return m_dContent;
}

float ConfigurationValue::GetFloat() const
{
    return m_fContent;
}

bool ConfigurationValue::GetBool() const
{
    return m_bContent;
}

ConfigurationValue& ConfigurationValue::GetContent(std::wstring key) const
{
    return m_oContent[key];
}

std::vector<std::wstring> ConfigurationValue::GetKeys()
{
    std::vector<std::wstring> keys;
    keys.reserve(m_oContent.size());
    for (const auto&kvp : m_oContent)
    {
        keys.push_back(kvp.first);
    }
    return keys;
}
