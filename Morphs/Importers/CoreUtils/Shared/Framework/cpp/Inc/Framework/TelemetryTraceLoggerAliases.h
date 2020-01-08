/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <memory>
#include <CoreUtils/SpectreSDK.h>
#include <Framework/Types.h>

namespace Spectre
{
    namespace Utils
    {
        class ITelemetryTraceLogger;
        using TelemetryTraceLoggerClientCallback = std::function<void SPECTRESDK_CALL(const char* eventName, const char* jsonData)>;
        using TelemetryTraceLoggerFactoryFunctionType = std::function<std::shared_ptr<ITelemetryTraceLogger> SPECTRESDK_CALL()>;
    }
}
