/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <GLTFSDK/ExtensionsKHR.h>
#include <GLTFSDK/GLTFResourceWriter.h>
#include <GLTFSDK/Serialize.h>

#include <PluginSDK/IOutputStreamFactory.h>

#include "ExporterGLTF/ExporterGLTF.h"
#include "ExporterGLTF/Asset3DToGLTFConverter.h"
#include "TranscoderGLTF/IStreamWriterOSFAdapter.h"

DEFINE_TRACE_AREA(ExporterGLTF, 0);

using namespace Microsoft;
using namespace Babylon::Transcoder;

namespace
{
    glTF::BufferBuilder InitializeBufferBuilder(const std::string& assetName, std::unique_ptr<const glTF::IStreamWriter>&& streamWriter)
    {
        auto resourceWriter = std::make_unique<glTF::GLTFResourceWriter>(std::move(streamWriter));
        resourceWriter->SetUriPrefix(assetName + "_");
        return glTF::BufferBuilder(std::move(resourceWriter));
    }
}

GLTFWriter::GLTFWriter(const std::string& assetName, std::unique_ptr<const glTF::IStreamWriter>&& streamWriter)
    : m_assetName(assetName), m_bufferBuilder(InitializeBufferBuilder(assetName, std::move(streamWriter)))
{
    m_bufferBuilder.AddBuffer();
}

void GLTFWriter::WriteImage(glTF::Document& document, const std::vector<uint8_t>& data,
    const std::string& id, const std::string& mimeType, const std::string& extension)
{
    glTF::Image image;
    image.id = id;
    image.uri = id + "." + extension;
    image.mimeType = mimeType;

    m_bufferBuilder.GetResourceWriter().WriteExternal(image.uri, data);
    document.images.Append(std::move(image));
}

void GLTFWriter::Finalize(glTF::Document& document, const glTF::ExtensionSerializer& extensionSerializer)
{
    m_bufferBuilder.Output(document);

    // If there are no meshes to render (empty scene), remove all buffers
    if (document.meshes.Size() == 0)
    {
        TRACE_WARN(ExporterGLTF, "Warning: No meshes found.  This file will only be an empty scene.");
        document.buffers.Clear();
    }

    const auto gltfManifest = glTF::Serialize(document, extensionSerializer, glTF::SerializeFlags::Pretty);
    m_bufferBuilder.GetResourceWriter().WriteExternal(m_assetName + "." + glTF::GLTF_EXTENSION, gltfManifest.c_str(), gltfManifest.length());
}

void ExporterGLTF::ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress, Babylon::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options)
{
    auto writer = std::make_unique<IStreamWriterOSFAdapter>(*streamFactory);
    Export(*asset3D.get(), std::move(writer), assetName, GLTFExportOptions::ParseOptions(options), cancellationToken);
}

void ExporterGLTF::Export(const Asset3D& asset3d, std::unique_ptr<const glTF::IStreamWriter>&& streamWriter, const std::string& assetName, const GLTFExportOptions& options, Babylon::Framework::ICancellationTokenPtr cancellationToken)
{
    Asset3DToGLTFConverter converter(asset3d, options, cancellationToken);

    GLTFWriter gltfWriter(assetName, std::move(streamWriter));
    converter.Write(gltfWriter);
}
