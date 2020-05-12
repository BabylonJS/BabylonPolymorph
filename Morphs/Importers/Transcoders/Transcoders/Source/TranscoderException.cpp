#include "TranscodersPch.h"
#include <TranscoderException.h>
#include <CoreUtils/BabylonTelemetryException.h>


#undef TranscoderException

namespace Babylon
{
    namespace Transcoder
    {

        TranscoderException::TranscoderException(std::string const& message, bool assert) :
            Babylon::Utils::BabylonException(message, assert)
        {}

        TranscoderException::TranscoderException(std::string file, int line, std::string const& message, bool assert) :
#if FEATURE_TELEMETRYEXCEPTIONSENABLED
            Babylon::Utils::BabylonTelemetryException(file, line, "Hardware Version: " + Babylon::Engine::g_hardwareVersion + "Error Message: " + message, assert)
        {}
#else
            TranscoderException(message, assert)
        {
            BabylonUnusedParameter(file);
            BabylonUnusedParameter(line);
        }
#endif
    }
}
