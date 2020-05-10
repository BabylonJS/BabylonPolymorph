/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

namespace Babylon
{
namespace Utils
{

    void SetThreadName(uint32_t threadId, char const* threadName);
}
}

#ifndef _WIN32
uint32_t GetCurrentThreadId();
#endif
