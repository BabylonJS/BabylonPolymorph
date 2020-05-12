/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <unordered_map>

#include <CoreUtils/RapidJson.h>

#include <Asset3D/Asset3D.h>
#include <PluginSDK/IResourceServer.h>
#include <PluginSDK/IOutputStreamFactory.h>
#include <PluginSDK/FractionalProgressCallback.h>

#include <Framework/Cancellation.h>
#include <Framework/TelemetryTraceLoggerAliases.h>

#include "Transcoders.h"

namespace
{
    std::string GetString(const Babylon::rapidjson::Value& jsonValue)
    {
        Babylon::rapidjson::StringBuffer stringBuffer;
        Babylon::rapidjson::Writer<Babylon::rapidjson::StringBuffer> writer(stringBuffer);
        jsonValue.Accept(writer);
        return stringBuffer.GetString();
    }

    std::unordered_map<std::string, std::string> GetOptionValuesFromJSON(const char* json)
    {
        std::unordered_map<std::string, std::string> optionValues;

        if (json == nullptr || std::strlen(json) == 0)
        {
            return optionValues;
        }

        Babylon::rapidjson::Document document;
        if (document.Parse(json).HasParseError())
        {
            // The input is not valid JSON.
            throw Babylon::Utils::BabylonException("JSON options are invalid due to bad JSON formatting");
        }

        for (auto& entry : document.GetObject())
        {
            if (entry.value.IsString())
            {
                // If it's a string, call GetString so that we get 'Foo' and not '"Foo"'
                optionValues[entry.name.GetString()] = entry.value.GetString();
            }
            else
            {
                // If it's not a string, use rapidjson::Writer so that we can get a string version
                optionValues[entry.name.GetString()] = GetString(entry.value);
            }
        }

        return optionValues;
    }

    bool GetEnableTelemetryTraceLoggerFromOptions(std::unordered_map<std::string, std::string>& options)
    {
        auto enableTelemetry = options.find("EnableTelemetryTraceLogger");
        if (enableTelemetry != options.end())
        {
            bool enabled = enableTelemetry->second == "true";
            options.erase("EnableTelemetryTraceLogger");
            return enabled;
        }
        else
        {
            // Default to "on" if not specified in json options
            return true;
        }
    }
}

namespace Babylon
{
    namespace Transcoder
    {
        Asset3DPtr Import(
            const std::string& importFormat,
            const std::string& importFilename,
            IResourceServer* importResourceServer,
            FractionalProgressCallback progress,
            Babylon::Framework::ICancellationTokenPtr cancellationToken,
            const char* jsonConfig,
            Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType traceLoggerFactory)
        {
            auto options = GetOptionValuesFromJSON(jsonConfig);
            auto enableTelemetry = GetEnableTelemetryTraceLoggerFromOptions(options);

            return Import(
                importFormat,
                importFilename,
                importResourceServer,
                options,
                progress,
                cancellationToken,
                enableTelemetry,
                traceLoggerFactory
            );
        }

        void Export(
            const std::string& exportFormat,
            Asset3DPtr asset3D,
            const std::string& exportAssetName,
            IOutputStreamFactory* outputStreamFactory,
            FractionalProgressCallback progress,
            Babylon::Framework::ICancellationTokenPtr cancellationToken,
            const char* jsonConfig,
            Babylon::Utils::TelemetryTraceLoggerFactoryFunctionType traceLoggerFactory)
        {
            auto options = GetOptionValuesFromJSON(jsonConfig);
            auto enableTelemetry = GetEnableTelemetryTraceLoggerFromOptions(options);

            return Export(
                exportFormat,
                asset3D,
                exportAssetName,
                outputStreamFactory,
                options,
                progress,
                cancellationToken,
                enableTelemetry,
                traceLoggerFactory
            );
        }
    }
}