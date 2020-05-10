#pragma once


#if !defined (Babylon_TELEMETRY_EXCEPTION_H_INCLUDED)
#define Babylon_TELEMETRY_EXCEPTION_H_INCLUDED

#include <string>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/ITelemetryManager.h>

// We undefine the macro in the cpp so as to avoid expansion in the definition of BabylonException and ThrowIfFailed.
#undef BabylonException
#undef ThrowIfFailed

namespace Babylon
{
namespace Utils
{

struct BabylonTelemetryException : public BabylonException
{
    BabylonTelemetryException(std::string file, int line, std::string const& message, bool assert = false);
#ifdef _WIN32
    BabylonTelemetryException(std::string file, int line, DWORD win32Error, std::string const& message, bool assert = false);
    BabylonTelemetryException(std::string file, int line, HRESULT hr, std::string const& message, bool assert = false);
#endif
};

struct BabylonTelemetryInvalidArgException : public BabylonTelemetryException
{
    BabylonTelemetryInvalidArgException(std::string file, int line, std::string const& message, bool assert = false)
#ifdef _WIN32
        : BabylonTelemetryException(file, line, E_INVALIDARG, message, assert)
#else
        : BabylonTelemetryException(file, line, message, assert)
#endif
    {}
};

struct BabylonTelemetryFailException : public BabylonTelemetryException
{
    BabylonTelemetryFailException(std::string file, int line, std::string const& message, bool assert = false)
#ifdef _WIN32
        : BabylonTelemetryException(file, line, E_FAIL, message, assert)
#else
        : BabylonTelemetryException(file, line, message, assert)
#endif
    {}
};

struct BabylonTelemetryNotImplException : public BabylonTelemetryException
{
    BabylonTelemetryNotImplException(std::string file, int line, std::string const& message, bool assert = false)
#ifdef _WIN32
        : BabylonTelemetryException(file, line, E_NOTIMPL, message, assert)
#else
        : BabylonTelemetryException(file, line, message, assert)
#endif
    {}
};

#ifdef _WIN32

inline void ThrowIfFailed(std::string file, int line, HRESULT hr)
{
    if (FAILED(hr))
    {
        throw BabylonTelemetryException(file, line, hr, "Thrown from ThrowIfFailed.", false);
    }
}

inline void ThrowIfFailed(std::string file, int line, HRESULT hr, const char* customMessage)
{
    if (FAILED(hr))
    {
        throw BabylonTelemetryException(file, line, hr, customMessage, false);
    }
}

#endif

} // namespace Utils
} // namespace Babylon

#endif // Babylon_TELEMETRY_EXCEPTION_H_INCLUDED
