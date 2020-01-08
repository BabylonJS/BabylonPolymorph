/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/


#include "CoreUtilsPch.h"
#include <sstream>
#include <CoreUtils/SpectreTelemetryException.h>

// We undefine the macro in the cpp so as to avoid expansion in the definition of the
// SpectreException constructors.
#undef SpectreException

DEFINE_TRACE_AREA(SpectreTelemetryException, 0);

namespace Spectre
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
            telemetryManager->SendEvent("SpectreException", ss.str());
            return;
        }
        else
        {
            TRACE_INFO(SpectreTelemetryException, "TelemetrySingleton not initialized. Failed to send exception data: '%s'", ss.str().c_str());
        }
    }
    catch (std::exception const& e)
    {
        TRACE_ERROR(SpectreTelemetryException, "An exception was thrown while sending a Telemetry event. Exception: '%s' \n Telemetry data: '%s'", e.what(), ss.str().c_str());
    }
    catch (...)
    {
        TRACE_ERROR(SpectreTelemetryException, "An unknown exception was thrown while sending a Telemetry event. Telemetry data: '%s'", ss.str().c_str());
    }
}

//--------------------------------------------------------------------------------

SpectreTelemetryException::SpectreTelemetryException(std::string file, int line, std::string const& message, bool assert)
    : SpectreException(message, assert)
{
    // telemetry send event
    sendNoThrowTelemetry(file, line, message);
}

#ifdef _WIN32

SpectreTelemetryException::SpectreTelemetryException(std::string file, int line, DWORD win32Error, std::string const& message, bool assert)
    : SpectreException(win32Error, message, assert)
{
    // Telemetry send event.
    sendNoThrowTelemetry(file, line, message);
}

SpectreTelemetryException::SpectreTelemetryException(std::string file, int line, HRESULT hr, std::string const& message, bool assert)
    : SpectreException(hr, message, assert)
{
    // telemetry send event
    sendNoThrowTelemetry(file, line, message);
}

#endif

//--------------------------------------------------------------------------------

} // namespace Utils

  //--------------------------------------------------------------------------------

} // namespace Spectre
