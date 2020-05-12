/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "Asset3D/Asset3D.h"
#include "PluginSDK/IOutputStreamFactory.h"

#include "GLTFSDK/IStreamWriter.h"

#include "ExporterGLTF/Asset3DToGLTFConverter.h"

namespace Babylon
{
    namespace Transcoder
    {
        class GLTFExportOptions;

        class ExporterGLTF
        {
        public:
            static void ExportStatic(Asset3DPtr asset3D, std::string const& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress = nullptr, Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {});

            static void Export(const Asset3D& asset3d, std::unique_ptr<const Microsoft::glTF::IStreamWriter>&& streamWriter, const std::string& assetName, const GLTFExportOptions& options, Framework::ICancellationTokenPtr cancellationToken = nullptr);
        };

        class GLTFWriter : public IGLTFWriter
        {
        public:
            GLTFWriter(const std::string& assetName, std::unique_ptr<const Microsoft::glTF::IStreamWriter>&& streamWriter);

            void WriteImage(Microsoft::glTF::Document& document, const std::vector<uint8_t>& data,
                const std::string& id, const std::string& mimeType, const std::string& extension) override;

            void Finalize(Microsoft::glTF::Document& document, const Microsoft::glTF::ExtensionSerializer& extensionSerializer) override;

            Microsoft::glTF::BufferBuilder& GetBufferBuilder() override { return m_bufferBuilder; }
        private:
            const std::string m_assetName;
            Microsoft::glTF::BufferBuilder m_bufferBuilder;
        };
    }
}
