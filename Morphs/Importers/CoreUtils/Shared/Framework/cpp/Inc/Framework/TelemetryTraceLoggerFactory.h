/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <memory>

#include <CoreUtils/SpectreSDK.h>

namespace Spectre
{
    namespace Utils
    {
        // Forward declare
        class ITelemetryTraceLogger;

        // Use this to get a TelemetryTraceLogger
        std::shared_ptr<Spectre::Utils::ITelemetryTraceLogger> SPECTRESDK_CALL CreateTelemetryTraceLogger();
    }
}