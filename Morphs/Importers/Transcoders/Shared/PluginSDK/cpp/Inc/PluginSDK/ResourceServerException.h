/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once
#include <CoreUtils/SmartThrow.h>

namespace Spectre
{
    namespace Transcoder
    {
        struct TranscoderResourceServerException : public
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
            Spectre::Utils::SpectreTelemetryException
#else
            Spectre::Utils::SpectreException(message, assert)
#endif
        {
            TranscoderResourceServerException(std::string const& message, bool assert = false) :
                Spectre::Utils::SpectreException(message, assert)
            {}

            TranscoderResourceServerException(std::string file, int line, std::string const& message, bool assert = false) :
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
                Spectre::Utils::SpectreTelemetryException(file, line, message, assert)
            {}
#else
                Spectre::Utils::SpectreException(message, assert)
            {
                SpectreUnusedParameter(file);
                SpectreUnusedParameter(line);
            }
#endif
        };
    }
}

