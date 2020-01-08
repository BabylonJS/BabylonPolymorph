/********************************************************
 *                                                      *
 *   Copyright (C) Microsoft. All rights reserved.      *
 *                                                      *
 ********************************************************/

#include "../PlatformLogger.h"

#include <stdio.h>

namespace Trace
{
    void PrintLogMessage(const char* message)
    {
        printf("%s", message);
    }

}  // namespace Trace
