/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/


#include "CoreUtilsPch.h"
#include <sstream>
#include <CoreUtils/BabylonTelemetryException.h>

// We undefine the macro in the cpp so as to avoid expansion in the definition of the
// BabylonException constructors.
#undef BabylonException

DEFINE_TRACE_AREA(BabylonTelemetryException, 0);

namespace Babylon
{

namespace Utils
{

//--------------------------------------------------------------------------------

void sendNoThrowTelemetry(std::string file, int line, std::string exceptionMessage) noexcept
{
    std::stringstream ss;
    ss << "{ ";
    ss <<   "\"ExceptionMessage\": \"" << exceptionMessage << "\", ";
    ss <<   "\"ExceptionFileName\": \"" << file << "\", ";
    ss <<   "\"ExceptionLineNumber\": " << std::to_string(line);
    ss << " }";;

    try
    {
        if (auto telemetryManager = TelemetrySingleton::get())
        {
            telemetryManager->SendEvent("BabylonException", ss.str());
            return;
        }
        else
        {
            TRACE_INFO(BabylonTelemetryException, "TelemetrySingleton not initialized. Failed to send exception data: '%s'", ss.str().c_str());
        }
    }
    catch (std::exception const& e)
    {
        TRACE_ERROR(BabylonTelemetryException, "An exception was thrown while sending a Telemetry event. Exception: '%s' \n Telemetry data: '%s'", e.what(), ss.str().c_str());
    }
    catch (...)
    {
        TRACE_ERROR(BabylonTelemetryException, "An unknown exception was thrown while sending a Telemetry event. Telemetry data: '%s'", ss.str().c_str());
    }
}

//--------------------------------------------------------------------------------

BabylonTelemetryException::BabylonTelemetryException(std::string file, int line, std::string const& message, bool assert)
    : BabylonException(message, assert)
{
    // telemetry send event
    sendNoThrowTelemetry(file, line, message);
}

#ifdef _WIN32

BabylonTelemetryException::BabylonTelemetryException(std::string file, int line, DWORD win32Error, std::string const& message, bool assert)
    : BabylonException(win32Error, message, assert)
{
    // Telemetry send event.
    sendNoThrowTelemetry(file, line, message);
}

BabylonTelemetryException::BabylonTelemetryException(std::string file, int line, HRESULT hr, std::string const& message, bool assert)
    : BabylonException(hr, message, assert)
{
    // telemetry send event
    sendNoThrowTelemetry(file, line, message);
}

#endif

//--------------------------------------------------------------------------------

} // namespace Utils

  //--------------------------------------------------------------------------------

} // namespace Babylon
