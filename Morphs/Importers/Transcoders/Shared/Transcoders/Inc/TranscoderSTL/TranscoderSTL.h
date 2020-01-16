/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderSTL/StlAsciiParser.h>
#include <PluginSDK/FractionalProgressCallback.h>

namespace Babylon
{
    namespace Transcoder
    {
        class Asset3D;

        enum class StlFileType
        {
            Ascii,
            Binary,
            Unknown
        };

        std::shared_ptr<Asset3D> ImportSTL(const std::string& filename, IResourceServer* resourceServer, FractionalProgressCallback progress = nullptr, Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {}, uint64_t* streamSize = nullptr);

        StlFileType GetStlFileType(std::shared_ptr<std::istream> stream);
    }
}
