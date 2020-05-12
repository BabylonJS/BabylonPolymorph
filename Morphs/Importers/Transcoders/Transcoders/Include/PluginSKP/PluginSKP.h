/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Platform.h>

// Define a macro to enable use of SKP Importer
#if defined(HAS_SKP_LIB) && (CANVAS_PLATFORM_IS_WINDOWS() && defined(_M_X64)) || (CANVAS_PLATFORM_IS_WINRT() && defined(_M_ARM64)) || (CANVAS_PLATFORM_IS_WIN32() && defined(_M_IX86))
#   define CANVAS_CAN_USE_SKP() 1
#else
#   define CANVAS_CAN_USE_SKP() 0
#endif

#if CANVAS_CAN_USE_SKP()

#include <unordered_map>

#include <PluginSDK/FractionalProgressCallback.h>

namespace Babylon
{
    namespace Transcoder
    {
        class Asset3D;
        class IResourceServer;

        std::shared_ptr<Asset3D> ImportSKP(
            const std::string& filename,
            IResourceServer* resourceServer,
            FractionalProgressCallback progress = nullptr,
            Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr,
            const std::unordered_map<std::string, std::string>& options = {},
            uint64_t* streamSize = nullptr);
    }
}

#endif