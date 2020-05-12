/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <CoreUtils/Math/SimpleMath.h>
#include <CoreUtils/Memory.h>
#include <CanvasTex/CanvasTex.h>
#include <ImagingComponent/ImagingComponent.h>
#include <Asset3D/TextureDescriptor.h>
#include <Asset3D/MaterialDescriptor.h>

using namespace Babylon::Transcoder;

namespace
{
    using TextureFlags = Babylon::Framework::TextureSegment::EFlag;

    RenderingMode DetectRenderingModeFromDiffuse(const MaterialLayer* const diffuseLayer)
    {
        if (diffuseLayer)
        {
            uint8_t textureFlags = 0;

            if (diffuseLayer->Texture)
            {
                // BUG 14764631: missing alpha mode MASK information due to kFlag_TextureHasActiveAlpha flag not being set
                auto diffuseBgra = diffuseLayer->Texture->EncodeToBGRA();

                // Check for alpha after BGRA encoding:
                Babylon::ImagingV2::ImagingComponent::ProcessAlphaFlagsForBGRAImage(diffuseLayer->Texture->GetData(), diffuseLayer->Texture->GetSizeInBytes(), diffuseBgra.Data.data(), diffuseBgra.Width, diffuseBgra.Height, diffuseBgra.RowPitch, textureFlags);
            }

            if (diffuseLayer->Texture &&
                (textureFlags & TextureFlags::kFlag_TextureHasActiveAlpha) == TextureFlags::kFlag_TextureHasActiveAlpha)
            {
                return RenderingMode::Mask;
            }
            else if (diffuseLayer->Color && diffuseLayer->Color->A() < 1.0f)
            {
                // Entire material is semi-transparent, therefore Blend
                return RenderingMode::Blend;
            }
        }

        // No Alpha detected anywhere, therefore Opaque
        return RenderingMode::Opaque;
    }

    RenderingMode DetectRenderingMode(RenderingMode renderingMode, const MaterialLayer* const diffuseLayer)
    {
        switch (renderingMode)
        {
        case RenderingMode::Opaque:
        case RenderingMode::Mask:
        case RenderingMode::Blend:
            // Valid, do nothing
            return renderingMode;

        case RenderingMode::MaskBlend:
            return RenderingMode::Mask;

        case RenderingMode::Default:
            return DetectRenderingModeFromDiffuse(diffuseLayer);

        default:
            throw Babylon::Utils::BabylonException("Unrecognized RenderingMode");
        }
    }

    std::shared_ptr<TextureDescriptor> GenerateLegacyShaderGlossinessChannelIfNeeded(const std::shared_ptr<TextureDescriptor>& sgTexture)
    {
        // Bug Fix
        // Bug 12741514:  Non-compliant code in GLTF shader.
        //
        // The legacy PBR shader was generating a custom glossiness channel for
        // SG textures with a pure-0xff alpha channel.  To make the
        // shader compliant, but retain the look of Remix content which
        // relied on that behaviour, we replicate it here by generating
        // the same glossiness data in the SG texture.

        //  The legacy PBR shader treated images with a pure white alpha channel
        //  as a special case (ie. image had alpha, but no "active" alpha).  In that case,
        //  the shader would generate a glossiness value as a function of RGB.
        //
        //  That behaviour made the shader non-compliant with GLTF 2.0 spec.
        //
        //  Decision:  Make the shader compliant, and to avoid changing all the content up on
        //  Remix, we will reproduce that behaviour in the SG texture glossiness channel.
        //

        // Make sure alpha flags are set, if they aren't already.
        // TODO: Correct flags should be set in importers before reaching exporter
        Babylon::Transcoder::BGRAImage bgra = { std::vector<uint8_t>(0), 0,0,0 };

        if (sgTexture->GetFlags() == 0)
        {
            uint8_t imageAlphaFlags = 0;
            bgra = sgTexture->EncodeToBGRA();
            Babylon::ImagingV2::ImagingComponent::ProcessAlphaFlagsForBGRAImage(sgTexture->GetData(), sgTexture->GetSizeInBytes(), bgra.Data.data(), bgra.Width, bgra.Height, bgra.RowPitch, imageAlphaFlags);
            sgTexture->SetFlags(imageAlphaFlags);
        }

        if ((sgTexture->GetFlags() & TextureFlags::kFlag_TextureHasActiveAlpha) != TextureFlags::kFlag_TextureHasActiveAlpha)
        {
            // Expand the texture if it hasn't already been
            if (bgra.Data.size() == 0)
            {
                bgra = sgTexture->EncodeToBGRA();
            }

            MaterialConversionUtils::GenerateLegacyGlossiness(bgra);

            //  Update the texture with this new data
            auto data = std::make_unique<uint8_t[]>(bgra.Data.size());
            memcpy_s(data.get(), bgra.Data.size(), bgra.Data.data(), bgra.Data.size());

            uint8_t flags = static_cast<uint8_t>(
                Babylon::Framework::TextureSegment::EFlag::kFlag_AlphaValid |
                Babylon::Framework::TextureSegment::EFlag::kFlag_TextureHasActiveAlpha);

            auto texture = std::make_shared<TextureDescriptor>(
                std::move(data),
                bgra.Data.size(),
                bgra.Width,
                bgra.Height,
                bgra.Width * 4,
                Babylon::Framework::TextureSegment::EFormat::kFormatBGRA32,
                flags
                );
            texture->SetName(sgTexture->GetName());

            return texture;
        }

        return sgTexture;
    }
}

MaterialDescriptor::MaterialDescriptor() : MaterialDescriptor(true)
{
}

MaterialDescriptor::MaterialDescriptor(bool defaultLayers) : ITraversableWithName()
{
    if (defaultLayers)
    {
        AddLayer(LayerType::kDiffuse)->SetColor({ 0.5f, 0.5f, 0.5f, 1.0f });
        AddLayer(LayerType::kSpecularGlossiness)->SetColor({ 0.0f, 0.0f, 0.0f, 1.0f });
    }
}

AlbedoWorkflowPair MaterialDescriptor::GetOrGenerateSpecGloss()
{
    auto& diffuseLayer   = m_layers[static_cast<size_t>(LayerType::kDiffuse)];
    auto& specGlossLayer = m_layers[static_cast<size_t>(LayerType::kSpecularGlossiness)];

    if (!diffuseLayer && !specGlossLayer)
    {
        auto& baseColorLayer = m_layers[static_cast<size_t>(LayerType::kBaseColor)];
        auto& metalRoughLayer = m_layers[static_cast<size_t>(LayerType::kMetallicRoughness)];
        auto sgLayers = MaterialConversionUtils::MetalRoughToSpecGloss(baseColorLayer, metalRoughLayer);

        diffuseLayer   = sgLayers.Albedo;
        specGlossLayer = sgLayers.Workflow;
    }

    return AlbedoWorkflowPair({ diffuseLayer, specGlossLayer });
}

AlbedoWorkflowPair MaterialDescriptor::GetOrGenerateMetalRough()
{
    auto& baseColorLayer  = m_layers[static_cast<size_t>(LayerType::kBaseColor)];
    auto& metalRoughLayer = m_layers[static_cast<size_t>(LayerType::kMetallicRoughness)];

    if (!baseColorLayer && !metalRoughLayer)
    {
        auto& diffuseLayer   = m_layers[static_cast<size_t>(LayerType::kDiffuse)];
        auto& specGlossLayer = m_layers[static_cast<size_t>(LayerType::kSpecularGlossiness)];
        auto mrLayers = MaterialConversionUtils::SpecGlossToMetalRough(diffuseLayer, specGlossLayer);

        baseColorLayer  = mrLayers.Albedo;
        metalRoughLayer = mrLayers.Workflow;
    }

    return AlbedoWorkflowPair({ baseColorLayer, metalRoughLayer });
}

std::map<LayerType, std::shared_ptr<MaterialDescriptor::LayerInfo>> MaterialDescriptor::GetLayers() const
{
    std::map<LayerType, std::shared_ptr<LayerInfo>> layers;
    for (size_t i = 0; i < static_cast<size_t>(LayerType::kNumLayers); i++)
    {
        if (m_layers[i])
        {
            layers.insert({ static_cast<LayerType>(i), m_layers[i] });
        }
    }
    return layers;
}

std::map<LayerType, Babylon::Utils::Math::Color> MaterialDescriptor::GetColors() const
{
    std::map<LayerType, Utils::Math::Color> colors;
    for (size_t i = 0; i < static_cast<size_t>(LayerType::kNumLayers); i++)
    {
        auto& layer = m_layers[i];
        if (layer && layer->Color)
        {
            colors.insert({ static_cast<LayerType>(i), *layer->Color });
        }
    }
    return colors;
}

std::map<LayerType, std::shared_ptr<TextureDescriptor>> MaterialDescriptor::GetTextures() const
{
    std::map<LayerType, std::shared_ptr<TextureDescriptor>> textures;
    for (size_t i = 0; i < static_cast<size_t>(LayerType::kNumLayers); i++)
    {
        auto& layer = m_layers[i];
        if (layer && layer->Texture)
        {
            textures.insert({ static_cast<LayerType>(i), layer->Texture });
        }
    }
    return textures;
}

void MaterialDescriptor::EnsureHeightMapConversion() const
{
    auto normalLayer = m_layers[static_cast<size_t>(LayerType::kNormal)];
    if (normalLayer && normalLayer->Texture)
    {
        normalLayer->Texture->ConvertGrayscaleToNormalMap();
    }
}

bool MaterialDescriptor::ShouldOverwriteGLTFFactors() const
{
    //  GLTF Compliance:
    //  Legacy materials look different in GLTF-compliant renderers.
    //  Rewrite their materials on output so they look the same.
    //  Rewrite conditions:
    //      The material comes from a non-GLTF format, OR
    //      It comes from GLTF, but from versions we know are non-compliant.
    bool isGLTFMaterial = (m_renderingOptions & RenderingOption::GLTFMaterial) != 0;
    bool isNotCompliant = (m_renderingOptions & RenderingOption::GLTFNonCompliant) != 0;
    return (!isGLTFMaterial || isNotCompliant);
}

void MaterialDescriptor::ConvertFromLegacy()
{
    if (ShouldOverwriteGLTFFactors())
    {
        auto& diffuse = m_layers[static_cast<size_t>(LayerType::kDiffuse)];
        if (diffuse)
        {
            if (diffuse->Texture)
            {
                diffuse->SetColor(Utils::Math::Color(Utils::Math::Color::White));
            }
            else if (diffuse->Color && *diffuse->Color != Utils::Math::Color::White)
            {
                diffuse->SetColor(diffuse->Color->ToLinearRGB());
            }
        }

        auto& specGloss = m_layers[static_cast<size_t>(LayerType::kSpecularGlossiness)];
        if (specGloss)
        {
            if (specGloss->Texture)
            {
                specGloss->SetColor(Utils::Math::Color(Utils::Math::Color::White));
                specGloss->Texture = GenerateLegacyShaderGlossinessChannelIfNeeded(specGloss->Texture);
            }
            else if (specGloss->Color && *specGloss->Color != Utils::Math::Color::White)
            {
                specGloss->SetColor(specGloss->Color->ToLinearRGB());
            }
        }

        auto& normal = m_layers[static_cast<size_t>(LayerType::kNormal)];
        if (normal)
        {
            if (normal->Texture)
            {
                normal->Texture->ConvertGrayscaleToNormalMap();
            }
            normal->Coefficient = 1.0f;
        }

        auto& emissive = m_layers[static_cast<size_t>(LayerType::kEmissive)];
        if (emissive)
        {
            if (emissive->Texture)
            {
                emissive->SetColor(Utils::Math::Color(Utils::Math::Color::White));
            }
            else if (emissive->Color && *emissive->Color != Utils::Math::Color::Black)
            {
                emissive->SetColor(emissive->Color->ToLinearRGB());
            }
        }
        auto& occlusion = m_layers[static_cast<size_t>(LayerType::kOcclusion)];
        if (occlusion)
        {
            occlusion->Coefficient = 1.0f;
        }

        m_renderingMode    = DetectRenderingMode(m_renderingMode, diffuse.get());
        // Finally set m_renderingOptions to indicate that we have a GLTF compliant material
        m_renderingOptions = RenderingOption::GLTFMaterial;
    }
}