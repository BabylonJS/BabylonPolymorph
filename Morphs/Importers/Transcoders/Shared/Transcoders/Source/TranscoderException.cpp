#include "TranscodersPch.h"
#include <TranscoderException.h>
#include <CoreUtils/SpectreTelemetryException.h>


#undef TranscoderException

namespace Spectre
{
    namespace Transcoder
    {

        TranscoderException::TranscoderException(std::string const& message, bool assert) :
            Spectre::Utils::SpectreException(message, assert)
        {}

        TranscoderException::TranscoderException(std::string file, int line, std::string const& message, bool assert) :
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
            Spectre::Utils::SpectreTelemetryException(file, line, "Hardware Version: " + Spectre::Engine::g_hardwareVersion + "Error Message: " + message, assert)
        {}
#else
            TranscoderException(message, assert)
        {
            SpectreUnusedParameter(file);
            SpectreUnusedParameter(line);
        }
#endif
    }
}
