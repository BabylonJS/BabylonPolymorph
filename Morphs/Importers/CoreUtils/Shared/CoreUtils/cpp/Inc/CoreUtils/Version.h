/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <functional>
#include <CoreUtils/SpectreSDK.h>

namespace Spectre
{
    namespace Utils
    {
        // Get the CoreUtils package version string
        const char* SPECTRESDK_CALL GetPackageVersion();

    } // End namespace Utils

} // End namespace