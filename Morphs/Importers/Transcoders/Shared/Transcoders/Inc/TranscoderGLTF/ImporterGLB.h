/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "Asset3D/Asset3D.h"
#include "GLTFSDK/GLBResourceReader.h"

namespace Babylon
{
    namespace Transcoder
    {
        class ImporterGLB
        {
        public:
            static std::shared_ptr<Asset3D> Import(
                const std::shared_ptr<Microsoft::glTF::IStreamReader>& streamReader,
                std::shared_ptr<std::istream> glbStream,
                Framework::ICancellationTokenPtr cancellationToken,
                const std::unordered_map<std::string, std::string>& options);
        };
    }
}
