/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <ImagingComponent/ImagingComponent.h>
#include <PluginSDK/TranscodeOptions.h>
#include <ExporterTexture/ExporterTexture.h>
#include <Asset3D/TextureDescriptor.h>

#include <sstream>

DEFINE_TRACE_AREA(ExporterTexture, 0);

using namespace Babylon::Transcoder;

void ExportTextures(ExporterTexture::TextureType typedToExport, std::shared_ptr<Asset3D> asset3D, std::string const& assetName, IOutputStreamFactory* streamFactory, Babylon::Framework::ICancellationTokenPtr cancellationToken)
{
    BabylonUnusedParameter(assetName);

    std::map<std::string, std::vector<uint8_t>> textures;

    ExporterTexture exporter(typedToExport, textures, cancellationToken);
    exporter.Export(*asset3D);

    for (auto& t : textures)
    {
        auto texFile = streamFactory->CreateStream(t.first);
        texFile->write( (char*)t.second.data(), t.second.size() );
    }
}


void ExporterTexture::ExportStaticPNG( Asset3DPtr asset3D, std::string const& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress, Babylon::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);
    return ExportTextures(ExporterTexture::TextureType::PNG, asset3D, assetName, streamFactory, cancellationToken);
}

void ExporterTexture::ExportStaticJPG( Asset3DPtr asset3D, std::string const& assetName, IOutputStreamFactory* streamFactory, FractionalProgressCallback progress, Babylon::Framework::ICancellationTokenPtr cancellationToken, const std::unordered_map<std::string, std::string>& options)
{
    TranscodeOptions transcodeOptions;
    transcodeOptions.Parse(options);
    return ExportTextures(ExporterTexture::TextureType::JPG, asset3D, assetName, streamFactory, cancellationToken);
}

ExporterTexture::ExporterTexture(
    ExporterTexture::TextureType typeToExport,
    std::map<std::string, std::vector<uint8_t>>& textures,
    Babylon::Framework::ICancellationTokenPtr cancellationToken) :
    m_extension(".png"),
    m_textureType(typeToExport),
    m_textures(textures),
    m_cancellationToken(cancellationToken)
{
    if (m_cancellationToken == nullptr)
    {
        m_cancellationToken = Babylon::Framework::MakeNullCancellationToken();
    }

    m_textures.clear();

    switch (m_textureType)
    {
    case TextureType::JPG: m_extension = ".jpg"; break;
    case TextureType::PNG: m_extension = ".png"; break;
    }
}

void ExporterTexture::ExportLeaf(MaterialDescriptor& material)
{
    for (const auto& texture : material.GetTextures())
    {
        ExportTexture(*texture.second, texture.first);
    }
}

void ExporterTexture::ExportTexture(const TextureDescriptor& texture, const LayerType layer)
{
    m_cancellationToken->CheckCancelledAndThrow();

    // generate correct filename extension for layer type
    std::string texLayerType;
    switch (layer)
    {
        case LayerType::kDiffuse:
            texLayerType = ".diff";
            break;
        case LayerType::kEmissive:
            texLayerType = ".emiss";
            break;
        case LayerType::kSpecularGlossiness:
            texLayerType = ".spec";
            break;
        case LayerType::kNormal:
            texLayerType = ".norm";
            break;
        case LayerType::kDepth:
            texLayerType = ".depth";
            break;
        case LayerType::kOcclusion:
            texLayerType = ".occl";
            break;
        case LayerType::kDetail:
            texLayerType = ".detail";
            break;
        default:
            texLayerType = ".diff";
            break;
    }

    std::stringstream sstream;
    sstream << "tex_" << texture.GetIdString() << "_" << texture.GetName() << texLayerType << m_extension;

    const auto fileName = sstream.str();

    if (m_textureType == TextureType::PNG)
    {
        m_textures[fileName] = texture.EncodeToPNG();
    }
    else if (m_textureType == TextureType::JPG)
    {
        m_textures[fileName] = texture.EncodeToJPEG();
    }
    else
    {
        throw Utils::BabylonException("Unsupported format");
    }
}