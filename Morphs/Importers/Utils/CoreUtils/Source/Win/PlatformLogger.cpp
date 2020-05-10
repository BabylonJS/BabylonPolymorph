/********************************************************
 *                                                      *
 *   Copyright (C) Microsoft. All rights reserved.      *
 *                                                      *
 ********************************************************/

#include "../CoreUtilsPch.h"

#include "../PlatformLogger.h"

#include <iostream>

namespace Trace
{
    void PrintLogMessage(const char* message)
    {
        std::cout << message << std::flush;
    }

}  // namespace Trace
