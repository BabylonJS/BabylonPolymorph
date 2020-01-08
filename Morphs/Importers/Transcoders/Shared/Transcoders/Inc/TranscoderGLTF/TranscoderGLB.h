/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/FractionalProgressCallback.h>

namespace Spectre
{
    namespace Transcoder
    {
        class Asset3D;
        class IResourceServer;

        std::shared_ptr<Asset3D> ImportGLB(const std::string& filename, IResourceServer* resourceServer, FractionalProgressCallback progress = nullptr, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {}, uint64_t* streamSize = nullptr);
    }
}
