/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"

#include <string>

#include <CoreUtils/Assert.h>

// We undefine the macro in the cpp so as to avoid expansion in the definition of the
// BabylonException constructors.
#undef BabylonException

DEFINE_TRACE_AREA(SmartThrow, 0);

namespace Babylon
{

namespace Utils
{

BabylonException::BabylonException(std::string const& message, bool assert)
    : std::runtime_error(message)
    , m_message(message)
#ifdef _WIN32
    , m_win32Error(0)
    , m_hr(S_OK)
#endif
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing BabylonException with message '%s'", message.c_str());
        BabylonAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing BabylonException with message '%s'", message.c_str());
    }
}

#ifdef _WIN32

BabylonException::BabylonException(DWORD win32Error, std::string const& message, bool assert) :
    std::runtime_error(message.c_str()),
    m_message(message),
    m_win32Error(win32Error),
    m_hr(HRESULT_FROM_WIN32(win32Error))
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing BabylonException with message '%s' and win32 error %u", message.c_str(), m_win32Error);
        BabylonAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing BabylonException with message '%s' and win32 error %u", message.c_str(), m_win32Error);
    }
}

BabylonException::BabylonException(HRESULT hr, std::string const& message, bool assert) :
    std::runtime_error(message.c_str()),
    m_message(message),
    m_win32Error(0),
    m_hr(hr)
{
    if (assert)
    {
        TRACE_WARN(SmartThrow, "Throwing BabylonException with message '%s' and HRESULT error 0x%.8x", message.c_str(), hr);
        BabylonAssert(false);
    }
    else
    {
        TRACE_IMPORTANT(SmartThrow, "Throwing BabylonException with message '%s' and HRESULT error 0x%.8x", message.c_str(), hr);
    }
}

#endif

} // namespace Utils

} // namespace Babylon
