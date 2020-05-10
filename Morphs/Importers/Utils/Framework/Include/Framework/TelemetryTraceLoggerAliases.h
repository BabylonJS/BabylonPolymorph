/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <memory>
#include <CoreUtils/BabylonSDK.h>
#include <Framework/Types.h>

namespace Babylon
{
    namespace Utils
    {
        class ITelemetryTraceLogger;
        using TelemetryTraceLoggerClientCallback = std::function<void BABYLON_SDK_CALL(const char* eventName, const char* jsonData)>;
        using TelemetryTraceLoggerFactoryFunctionType = std::function<std::shared_ptr<ITelemetryTraceLogger> BABYLON_SDK_CALL()>;
    }
}
