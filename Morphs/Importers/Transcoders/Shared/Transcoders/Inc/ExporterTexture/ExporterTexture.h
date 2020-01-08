/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Asset3D/Asset3D.h>
#include <PluginSDK/ExporterBase.h>
#include <PluginSDK/IOutputStreamFactory.h>

namespace Spectre
{
    namespace Transcoder
    {
        class ExporterTexture : public ExporterBase
        {
        public:
            enum class TextureType
            {
                JPG = 0,
                PNG = 1
            };

        public:
            static void ExportStaticPNG(Asset3DPtr asset3D, std::string const& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress = nullptr, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {});
            static void ExportStaticJPG(Asset3DPtr asset3D, std::string const& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress = nullptr, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {});
            explicit ExporterTexture(TextureType typeToExport,
                std::map<std::string, std::vector<uint8_t>>& textures,
                Framework::ICancellationTokenPtr cancellationToken = nullptr);

            virtual void ExportLeaf(MaterialDescriptor& texture) override;

        protected:
            void ExportTexture(const TextureDescriptor& texture, const LayerType layer);

            std::string m_extension;
            TextureType m_textureType;
            std::map<std::string, std::vector<uint8_t>>& m_textures;
            Framework::ICancellationTokenPtr m_cancellationToken;
        };
    }
}