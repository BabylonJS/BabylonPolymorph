/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <Framework/TelemetryTraceLoggerFactory.h>
#include "TelemetryTraceLoggerAndroid.h"

namespace Spectre
{
    namespace Utils
    {
        std::shared_ptr<ITelemetryTraceLogger> SPECTRESDK_CALL CreateTelemetryTraceLogger()
        {
            return std::make_shared<TelemetryTraceLoggerAndroid>();
        }
    }
}