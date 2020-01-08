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
#include "ExporterGLTF/GLTFExportOptions.h"

namespace Spectre
{
    namespace Transcoder
    {
        class ExporterGLB
        {
        public:
            static void ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress = nullptr, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {});

            static void Export(const Asset3D& asset3d, std::shared_ptr<const Microsoft::glTF::IStreamWriter> streamWriter, const std::string& assetName, const GLTFExportOptions& options = {}, Spectre::Framework::ICancellationTokenPtr cancellationToken = nullptr);
        };

        class GLBWriter : public IGLTFWriter
        {
        public:
            GLBWriter(std::string assetName, std::shared_ptr<const Microsoft::glTF::IStreamWriter> streamWriter);

            void WriteImage(Microsoft::glTF::Document& document, const std::vector<uint8_t>& data,
                const std::string& id, const std::string& mimeType, const std::string&) override;

            void Finalize(Microsoft::glTF::Document& document, const Microsoft::glTF::ExtensionSerializer& extensionSerializer) override;

            Microsoft::glTF::BufferBuilder& GetBufferBuilder() override { return m_bufferBuilder; }
        private:
            const std::string m_assetName;
            Microsoft::glTF::BufferBuilder m_bufferBuilder;
        };
    }
}
