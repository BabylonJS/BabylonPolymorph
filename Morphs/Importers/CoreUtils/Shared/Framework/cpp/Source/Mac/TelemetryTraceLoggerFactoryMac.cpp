/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/TelemetryTraceLoggerFactory.h>

#include "TelemetryTraceLoggerMac.h"

namespace Spectre
{
    namespace Utils
    {
        std::shared_ptr<ITelemetryTraceLogger> SPECTRESDK_CALL CreateTelemetryTraceLogger()
        {
            return std::make_shared<TelemetryTraceLoggerMac>();
        }
    }
}