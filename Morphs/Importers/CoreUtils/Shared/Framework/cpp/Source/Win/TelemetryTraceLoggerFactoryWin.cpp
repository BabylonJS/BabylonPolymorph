/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/TelemetryTraceLoggerFactory.h>

#include "TelemetryTraceLoggerWin.h"

namespace Spectre
{
    namespace Utils
    {
        std::shared_ptr<Spectre::Utils::ITelemetryTraceLogger> SPECTRESDK_CALL CreateTelemetryTraceLogger()
        {
            return std::make_shared<TelemetryTraceLoggerWin>();
        }
    }
}