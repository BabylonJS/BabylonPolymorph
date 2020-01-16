/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once
#include <CoreUtils/SmartThrow.h>

namespace Babylon
{
    namespace Transcoder
    {
        struct TranscoderResourceServerException : public
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
            Babylon::Utils::BabylonTelemetryException
#else
            Babylon::Utils::BabylonException(message, assert)
#endif
        {
            TranscoderResourceServerException(std::string const& message, bool assert = false) :
                Babylon::Utils::BabylonException(message, assert)
            {}

            TranscoderResourceServerException(std::string file, int line, std::string const& message, bool assert = false) :
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
                Babylon::Utils::BabylonTelemetryException(file, line, message, assert)
            {}
#else
                Babylon::Utils::BabylonException(message, assert)
            {
                BabylonUnusedParameter(file);
                BabylonUnusedParameter(line);
            }
#endif
        };
    }
}

