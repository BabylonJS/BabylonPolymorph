/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <memory>

#include <CoreUtils/BabylonSDK.h>

namespace Babylon
{
    namespace Utils
    {
        // Forward declare
        class ITelemetryTraceLogger;

        // Use this to get a TelemetryTraceLogger
        std::shared_ptr<Babylon::Utils::ITelemetryTraceLogger> BABYLON_SDK_CALL CreateTelemetryTraceLogger();
    }
}