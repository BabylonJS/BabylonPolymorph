/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderPLY/PLYParser.h>

namespace Babylon
{
    namespace Transcoder
    {
        class Asset3D;

        std::shared_ptr<Asset3D> ImportPLY(const std::string& filename, IResourceServer* resourceServer, FractionalProgressCallback progress = nullptr, Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {}, uint64_t* streamSize = nullptr);
    }
}
