/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <Framework/ITelemetryTraceLogger.h>
#include <Framework/TelemetryTraceLoggerFactory.h>

#include "TelemetryTraceLoggerMac.h"

namespace Babylon
{
    namespace Utils
    {
        std::shared_ptr<ITelemetryTraceLogger> BABYLONSDK_CALL CreateTelemetryTraceLogger()
        {
            return std::make_shared<TelemetryTraceLoggerMac>();
        }
    }
}