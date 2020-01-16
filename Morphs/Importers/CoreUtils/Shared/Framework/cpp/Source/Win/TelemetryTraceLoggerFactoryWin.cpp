/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/TelemetryTraceLoggerFactory.h>

#include "TelemetryTraceLoggerWin.h"

namespace Babylon
{
    namespace Utils
    {
        std::shared_ptr<Babylon::Utils::ITelemetryTraceLogger> BABYLON_SDK_CALL CreateTelemetryTraceLogger()
        {
            return std::make_shared<TelemetryTraceLoggerWin>();
        }
    }
}