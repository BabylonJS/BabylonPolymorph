#pragma once


#if !defined (SPECTRE_TELEMETRY_EXCEPTION_H_INCLUDED)
#define SPECTRE_TELEMETRY_EXCEPTION_H_INCLUDED

#include <string>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/ITelemetryManager.h>

// We undefine the macro in the cpp so as to avoid expansion in the definition of SpectreException and ThrowIfFailed.
#undef SpectreException
#undef ThrowIfFailed

namespace Spectre
{
namespace Utils
{

struct SpectreTelemetryException : public SpectreException
{
    SpectreTelemetryException(std::string file, int line, std::string const& message, bool assert = false);
#ifdef _WIN32
    SpectreTelemetryException(std::string file, int line, DWORD win32Error, std::string const& message, bool assert = false);
    SpectreTelemetryException(std::string file, int line, HRESULT hr, std::string const& message, bool assert = false);
#endif
};

struct SpectreTelemetryInvalidArgException : public SpectreTelemetryException
{
    SpectreTelemetryInvalidArgException(std::string file, int line, std::string const& message, bool assert = false)
#ifdef _WIN32
        : SpectreTelemetryException(file, line, E_INVALIDARG, message, assert)
#else
        : SpectreTelemetryException(file, line, message, assert)
#endif
    {}
};

struct SpectreTelemetryFailException : public SpectreTelemetryException
{
    SpectreTelemetryFailException(std::string file, int line, std::string const& message, bool assert = false)
#ifdef _WIN32
        : SpectreTelemetryException(file, line, E_FAIL, message, assert)
#else
        : SpectreTelemetryException(file, line, message, assert)
#endif
    {}
};

struct SpectreTelemetryNotImplException : public SpectreTelemetryException
{
    SpectreTelemetryNotImplException(std::string file, int line, std::string const& message, bool assert = false)
#ifdef _WIN32
        : SpectreTelemetryException(file, line, E_NOTIMPL, message, assert)
#else
        : SpectreTelemetryException(file, line, message, assert)
#endif
    {}
};

#ifdef _WIN32

inline void ThrowIfFailed(std::string file, int line, HRESULT hr)
{
    if (FAILED(hr))
    {
        throw SpectreTelemetryException(file, line, hr, "Thrown from ThrowIfFailed.", false);
    }
}

inline void ThrowIfFailed(std::string file, int line, HRESULT hr, const char* customMessage)
{
    if (FAILED(hr))
    {
        throw SpectreTelemetryException(file, line, hr, customMessage, false);
    }
}

#endif

} // namespace Utils
} // namespace Spectre

#endif // SPECTRE_TELEMETRY_EXCEPTION_H_INCLUDED
