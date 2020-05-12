/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Asset3D/Asset3D.h>
#include "GLTFSDK/IStreamReader.h"

namespace Babylon
{
    namespace Transcoder
    {
        class GLTFImportOptions;

        class ImporterGLTF
        {
        public:
            static std::shared_ptr<Asset3D> Import(
                const std::shared_ptr<Microsoft::glTF::IStreamReader>& resourceReader,
                std::shared_ptr<std::istream> stream,
                Framework::ICancellationTokenPtr cancellationToken,
                const GLTFImportOptions& options);

        private:
            static std::string ParseJson(std::istream& stream);
        };
    }
}
