/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <GLTFSDK/ExtensionsKHR.h>
#include <GLTFSDK/GLBResourceWriter.h>
#include <GLTFSDK/Serialize.h>

#include <PluginSDK/IOutputStreamFactory.h>

#include "ExporterGLTF/ExporterGLB.h"
#include "ExporterGLTF/Asset3DToGLTFConverter.h"
#include "TranscoderGLTF/IStreamWriterOSFAdapter.h"

DEFINE_TRACE_AREA(ExporterGLB, 0);

using namespace Microsoft;
using namespace Babylon::Transcoder;

GLBWriter::GLBWriter(std::string assetName, std::shared_ptr<const glTF::IStreamWriter> streamWriter)
    : m_assetName(std::move(assetName)),
      m_bufferBuilder(glTF::BufferBuilder(std::make_unique<glTF::GLBResourceWriter>(streamWriter)))
{
    m_bufferBuilder.AddBuffer(glTF::GLB_BUFFER_ID);
}

void GLBWriter::WriteImage(glTF::Document& document, const std::vector<uint8_t>& data,
    const std::string& id, const std::string& mimeType, const std::string&)
{
    auto& bufferView = m_bufferBuilder.AddBufferView(data);

    glTF::Image image;
    image.id = id;
    image.bufferViewId = bufferView.id;
    image.mimeType = mimeType;

    document.images.Append(std::move(image));
}

void GLBWriter::Finalize(glTF::Document& document, const Microsoft::glTF::ExtensionSerializer& extensionSerializer)
{
    m_bufferBuilder.Output(document);

    // If there are no meshes to render (empty scene), remove all buffers
    if (document.meshes.Size() == 0)
    {
        TRACE_WARN(ExporterGLB, "Warning: No meshes found.  This file will only be an empty scene.");
        document.buffers.Clear();
    }

    const auto gltfManifest = Serialize(document, extensionSerializer);

    dynamic_cast<glTF::GLBResourceWriter&>(m_bufferBuilder.GetResourceWriter()).Flush(gltfManifest, m_assetName + "." + glTF::GLB_EXTENSION);
}

void ExporterGLB::ExportStatic(Asset3DPtr asset3D, const std::string& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress, Babylon::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options)
{
    auto writer = std::make_unique<IStreamWriterOSFAdapter>(*streamFactory);
    Export(*asset3D.get(), std::move(writer), assetName, GLTFExportOptions::ParseOptions(options), cancellationToken);
}


void ExporterGLB::Export(const Asset3D& asset3d, std::shared_ptr<const glTF::IStreamWriter> streamWriter, const std::string& assetName, const GLTFExportOptions& options, Babylon::Framework::ICancellationTokenPtr cancellationToken)
{
    Asset3DToGLTFConverter converter(asset3d, options, cancellationToken);

    GLBWriter glbWriter(assetName, streamWriter);
    converter.Write(glbWriter);
}
