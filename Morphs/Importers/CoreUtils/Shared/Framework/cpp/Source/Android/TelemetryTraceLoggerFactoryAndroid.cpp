/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <Framework/TelemetryTraceLoggerFactory.h>
#include "TelemetryTraceLoggerAndroid.h"

namespace Babylon
{
    namespace Utils
    {
        std::shared_ptr<ITelemetryTraceLogger> BABYLONSDK_CALL CreateTelemetryTraceLogger()
        {
            return std::make_shared<TelemetryTraceLoggerAndroid>();
        }
    }
}