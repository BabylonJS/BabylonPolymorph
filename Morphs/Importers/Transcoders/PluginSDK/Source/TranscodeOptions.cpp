/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "PluginSDKPch.h"

#include <PluginSDK/TranscodeOptions.h>

#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/StringUtils.h>
#include <Framework/ITelemetryTraceLogger.h>

#include <iostream>
#include <sstream>

DEFINE_TRACE_AREA(TranscodeOptions, 0);

using namespace Babylon::Transcoder;

std::string TranscodeOptions::GenerateHelp() const
{
    size_t maxOptionLength = 40; // Help options will be tabbed to 40 characters at a minimum
    for (const auto& option : m_options)
    {
        maxOptionLength = std::max(maxOptionLength, option.second.name.length());
    }

    std::stringstream sstr;
    for (const auto& option : m_options)
    {
        sstr << option.second.name << std::string((maxOptionLength - option.second.name.length()) + 4, ' ') << option.second.help << "\n";
    }
    return sstr.str();
}

void TranscodeOptions::Parse(const std::unordered_map<std::string, std::string>& inputOptions)
{
    // For each optionValue (input options, should be a subset of all available options)
    for (const auto& inputOption : inputOptions)
    {
        // Find option using case-insensitive search i.e. inputOption key 'validate' matches m_options['Validate']
        auto option = m_options.find(Utils::ToLower(inputOption.first));

        if (option != m_options.end())
        {
            // Pass the inputOption value in lowercase to the deserializer, i.e. "TRUE" becomes "true"
            option->second.deserializer(Utils::ToLower(inputOption.second));
        }
        else
        {
            // Throw an exception if an input option was specified that is not supported
            TRACE_WARN(TranscodeOptions, "Unrecognized Transcode option: %s", inputOption.first.c_str());
        }
    }
}

void TranscodeOptions::AddOption(TranscodeOption&& option)
{
    auto key = Utils::ToLower(option.name);
    m_options.emplace(std::move(key), std::move(option));
}