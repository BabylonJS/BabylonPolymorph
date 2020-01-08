/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <string>

#include <CoreUtils/Assert.h>

// We undefine the macro in the cpp so as to avoid expansion in the definition of the
// SpectreException constructors.
#undef SpectreException

DEFINE_TRACE_AREA(SmartThrow, 0);

namespace Spectre
{

namespace Utils
{

SpectreException::SpectreException(std::string const& message, bool assert)
    : std::runtime_error(message)
    , m_message(message)
#ifdef _WIN32
    , m_win32Error(0)
    , m_hr(S_OK)
#endif
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing SpectreException with message '%s'", message.c_str());
        SpectreAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing SpectreException with message '%s'", message.c_str());
    }
}

#ifdef _WIN32

SpectreException::SpectreException(DWORD win32Error, std::string const& message, bool assert) :
    std::runtime_error(message.c_str()),
    m_message(message),
    m_win32Error(win32Error),
    m_hr(HRESULT_FROM_WIN32(win32Error))
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing SpectreException with message '%s' and win32 error %u", message.c_str(), m_win32Error);
        SpectreAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing SpectreException with message '%s' and win32 error %u", message.c_str(), m_win32Error);
    }
}

SpectreException::SpectreException(HRESULT hr, std::string const& message, bool assert) :
    std::runtime_error(message.c_str()),
    m_message(message),
    m_win32Error(0),
    m_hr(hr)
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing SpectreException with message '%s' and HRESULT error 0x%.8x", message.c_str(), hr);
        SpectreAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing SpectreException with message '%s' and HRESULT error 0x%.8x", message.c_str(), hr);
    }
}

#endif

} // namespace Utils

} // namespace Spectre
