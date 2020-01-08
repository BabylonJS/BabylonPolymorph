/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <Asset3D/MaterialConversionUtils.h>
#include <CoreUtils/Gltf.h>
#include <CoreUtils/Memory.h>
#include <ImagingComponent/ImagingComponent.h>

#include <GLTFSDK/PBRUtils.h>

using namespace Spectre::Transcoder;
using namespace Spectre::Utils::Math;

using TexturePair = std::tuple<std::shared_ptr<TextureDescriptor>, std::shared_ptr<TextureDescriptor>>;

using SpecularGlossinessValue = Microsoft::glTF::SpecularGlossinessValueTypeless<Spectre::Utils::Math::Color>;
using MetallicRoughnessValue  = Microsoft::glTF::MetallicRoughnessValueTypeless<Spectre::Utils::Math::Color>;

// Used by glTF SDK PBR Utils to access colour channel data in a consistent manner
namespace Spectre
{
    namespace Utils
    {
        namespace Math
        {
            constexpr float R(const Color& color)
            {
                return color.R();
            }

            constexpr float G(const Color& color)
            {
                return color.G();
            }

            constexpr float B(const Color& color)
            {
                return color.B();
            }
        }
    }
}

namespace
{
    // Use the glTF SDK ToGamma function rather than Spectre::Utils::Math::Color::ToGammaRGB to
    // match existing Transcoders behaviour (glTF SDK has a more accurate colour space conversion)
    using Microsoft::glTF::Math::ToGamma;

    // Use the glTF SDK ToLinear function rather than Spectre::Utils::Math::Color::ToLinearRGB to
    // match existing Transcoders behaviour (glTF SDK has a more accurate colour space conversion)
    using Microsoft::glTF::Math::ToLinear;

    class ConverterDefaultAccessor final
    {
    public:
        Spectre::Utils::Math::Color operator()(uint32_t, uint32_t) const
        {
            return { 1.0f, 1.0f, 1.0f, 1.0f };
        }
    };

    class ConverterTextureAccessorSRGB final
    {
    public:
        ConverterTextureAccessorSRGB(Spectre::Transcoder::BGRAImage&& image) :
            m_image(std::move(image))
        {
        }

        Spectre::Utils::Math::Color operator()(uint32_t x, uint32_t y) const
        {
            size_t offset = (x * 4U) + (y * m_image.RowPitch);

            // Texture image format is BGRA in 'byte-order'
            const float b = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset++]);
            const float g = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset++]);
            const float r = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset++]);
            const float a = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset]);

            // Convert RGB channels from sRGB to Linear colour space
            return { ToLinear(r), ToLinear(g), ToLinear(b), a };
        }

    private:
        const Spectre::Transcoder::BGRAImage m_image;
    };

    class ConverterTextureAccessorLinear final
    {
    public:
        ConverterTextureAccessorLinear(Spectre::Transcoder::BGRAImage&& image) :
            m_image(std::move(image))
        {
        }

        Spectre::Utils::Math::Color operator()(uint32_t x, uint32_t y) const
        {
            size_t offset = (x * 4U) + (y * m_image.RowPitch);

            // Texture image format is BGRA in 'byte-order'
            const float b = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset++]);
            const float g = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset++]);
            const float r = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset++]);
            const float a = Microsoft::glTF::Math::ByteToFloat(m_image.Data[offset]);

            return { r, g, b, a };
        }

    private:
        const Spectre::Transcoder::BGRAImage m_image;
    };

    struct ConvertedMaterialData
    {
        ConvertedMaterialData(size_t dataSize) :
            m_dataSize(dataSize),
            m_dataAlbedo(std::make_unique<uint8_t[]>(m_dataSize)),
            m_dataWorkflow(std::make_unique<uint8_t[]>(m_dataSize))
        {
        }

        const size_t m_dataSize;
        std::unique_ptr<uint8_t[]> m_dataAlbedo;
        std::unique_ptr<uint8_t[]> m_dataWorkflow;
    };

    template<typename FnDiffuse, typename FnSpecular>
    ConvertedMaterialData ConvertMaterialSGToMR(const SpecularGlossinessValue& sg, const uint32_t textureWidth, const uint32_t textureHeight, FnDiffuse fnDiffuse, FnSpecular fnSpecular)
    {
        size_t index = 0;

        const auto pixelSize = sizeof(uint32_t);
        const auto pixelBytes = pixelSize * textureWidth * textureHeight;

        ConvertedMaterialData generatedData(pixelBytes);

        for (uint32_t y = 0U; y < textureHeight; ++y)
        {
            for (uint32_t x = 0U; x < textureWidth; ++x)
            {
                auto sgCopy = sg;

                const auto diffusePixel = fnDiffuse(x, y);
                sgCopy.diffuse *= diffusePixel;
                sgCopy.opacity *= diffusePixel.A();

                const auto specularPixel = fnSpecular(x, y);
                sgCopy.specular *= specularPixel;
                sgCopy.glossiness *= specularPixel.A();

                const auto mrValue = Microsoft::glTF::SGToMR<Spectre::Utils::Math::Color>(sgCopy);

                {
                    const Spectre::Utils::Math::Color baseColour(ToGamma(mrValue.base.R()), ToGamma(mrValue.base.G()), ToGamma(mrValue.base.B()), mrValue.opacity);
                    const uint32_t value = baseColour.BGRA();
                    memcpy_s(generatedData.m_dataAlbedo.get() + index, pixelBytes - index, &value, sizeof(value));
                }

                {
                    const Spectre::Utils::Math::Color metallicRoughness(0.0f, mrValue.roughness, mrValue.metallic, 1.0f);
                    const uint32_t value = metallicRoughness.BGRA();
                    memcpy_s(generatedData.m_dataWorkflow.get() + index, pixelBytes - index, &value, sizeof(value));
                }

                index += pixelSize;
            }
        }

        return generatedData;
    }

    template<typename FnBaseColor, typename FnMetalRough>
    ConvertedMaterialData ConvertMaterialMRToSG(const MetallicRoughnessValue& mr, const uint32_t textureWidth, const uint32_t textureHeight, FnBaseColor fnBaseColor, FnMetalRough fnMetalRough)
    {
        size_t index = 0;

        const auto pixelSize = sizeof(uint32_t);
        const auto pixelBytes = pixelSize * textureWidth * textureHeight;

        ConvertedMaterialData generatedData(pixelBytes);

        for (uint32_t y = 0U; y < textureHeight; ++y)
        {
            for (uint32_t x = 0U; x < textureWidth; ++x)
            {
                auto mrCopy = mr;

                const auto baseColorPixel = fnBaseColor(x, y);
                mrCopy.base      *= baseColorPixel;
                mrCopy.opacity   *= baseColorPixel.A();

                const auto metalRoughPixel = fnMetalRough(x, y);
                mrCopy.metallic  *= metalRoughPixel.B();
                mrCopy.roughness *= metalRoughPixel.G();

                const auto sgValue = Microsoft::glTF::MRToSG<Spectre::Utils::Math::Color>(mrCopy);

                {
                    const Spectre::Utils::Math::Color diffuse(ToGamma(sgValue.diffuse.R()), ToGamma(sgValue.diffuse.G()), ToGamma(sgValue.diffuse.B()), sgValue.opacity);
                    const uint32_t value = diffuse.BGRA();
                    memcpy_s(generatedData.m_dataAlbedo.get() + index, pixelBytes - index, &value, sizeof(value));
                }

                {
                    const Spectre::Utils::Math::Color specGloss(ToGamma(sgValue.specular.R()), ToGamma(sgValue.specular.G()), ToGamma(sgValue.specular.B()), sgValue.glossiness);
                    const uint32_t value = specGloss.BGRA();
                    memcpy_s(generatedData.m_dataWorkflow.get() + index, pixelBytes - index, &value, sizeof(value));
                }

                index += pixelSize;
            }
        }

        return generatedData;
    }

    SpecularGlossinessValue ToGltfSpecGlossValue(const Color& diffuse, const Color& specular)
    {
        SpecularGlossinessValue sgValue;
        sgValue.diffuse    = diffuse;
        sgValue.opacity    = diffuse.A();
        sgValue.specular   = specular;
        sgValue.glossiness = specular.A();
        return sgValue;
    }

    MetallicRoughnessValue ToGltfMetalRoughValue(const Color& baseColor, const Color& metalRough)
    {
        MetallicRoughnessValue mrValue;
        mrValue.base      = baseColor;
        mrValue.opacity   = baseColor.A();
        mrValue.metallic  = metalRough.B();
        mrValue.roughness = metalRough.G();
        return mrValue;
    }

    void CopyLayerTextureAttributes(const MaterialLayer& source, MaterialLayer& target)
    {
        target.UVSetIndex       = source.UVSetIndex;
        target.Sampler          = source.Sampler;
        target.TextureTransform = source.TextureTransform;

        if (target.Texture)
        {
            target.Texture->SetName(source.Texture->GetName());
            target.Texture->SetExtensions(source.Texture->GetExtensions());
            target.Texture->SetExtras(source.Texture->GetExtras());
        }
    }

    TexturePair SpecGlossToMetalRough(
        const SpecularGlossinessValue& sgFactors,
        const std::shared_ptr<const TextureDescriptor>& diffuseTexture,
        const std::shared_ptr<const TextureDescriptor>& specGlossTexture
    )
    {
        uint32_t width  = 0;
        uint32_t height = 0;

        std::function<::ConvertedMaterialData(const SpecularGlossinessValue&, const uint32_t, const uint32_t)> fnCreateTextureData;

        if (diffuseTexture && specGlossTexture)
        {
            width  = std::max(diffuseTexture->GetWidthInPixels(), specGlossTexture->GetWidthInPixels());
            height = std::max(diffuseTexture->GetHeightInPixels(), specGlossTexture->GetHeightInPixels());

            auto diffuse   = diffuseTexture->EncodeToBGRA(width, height);
            auto specGloss = specGlossTexture->EncodeToBGRA(width, height);

            // If either of a texture's dimensions is smaller than the other texture's, resize it to the maximum.
            // It is possible for both textures to be resized, for example if they are 1024x512 and 512x1024 respectively.
            fnCreateTextureData = std::bind(&::ConvertMaterialSGToMR<ConverterTextureAccessorSRGB, ConverterTextureAccessorSRGB>,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3,
                ConverterTextureAccessorSRGB(std::move(diffuse)),
                ConverterTextureAccessorSRGB(std::move(specGloss)));
        }
        else if (diffuseTexture)
        {
            auto diffuse = diffuseTexture->EncodeToBGRA();
            width = diffuse.Width;
            height = diffuse.Height;

            fnCreateTextureData = std::bind(&::ConvertMaterialSGToMR<ConverterTextureAccessorSRGB, ConverterDefaultAccessor>,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3,
                ConverterTextureAccessorSRGB(std::move(diffuse)),
                ConverterDefaultAccessor());
        }
        else if (specGlossTexture)
        {
            auto specGloss = specGlossTexture->EncodeToBGRA();
            width = specGloss.Width;
            height = specGloss.Height;

            fnCreateTextureData = std::bind(&::ConvertMaterialSGToMR<ConverterDefaultAccessor, ConverterTextureAccessorSRGB>,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3,
                ConverterDefaultAccessor(),
                ConverterTextureAccessorSRGB(std::move(specGloss)));
        }

        ConvertedMaterialData materialData = fnCreateTextureData(sgFactors, width, height);

        return TexturePair(
            std::make_shared<TextureDescriptor>(std::move(materialData.m_dataAlbedo),
                materialData.m_dataSize, width, height, width * 4U, Spectre::Framework::TextureSegment::EFormat::kFormatBGRA32),
            std::make_shared<TextureDescriptor>(std::move(materialData.m_dataWorkflow),
                materialData.m_dataSize, width, height, width * 4U, Spectre::Framework::TextureSegment::EFormat::kFormatBGRA32)
        );
    }

    TexturePair MetalRoughToSpecGloss(
        const MetallicRoughnessValue& mrFactors,
        const std::shared_ptr<const TextureDescriptor>& baseColorTexture,
        const std::shared_ptr<const TextureDescriptor>& metalRoughTexture
    )
    {
        uint32_t width = 0;
        uint32_t height = 0;

        std::function<::ConvertedMaterialData(const MetallicRoughnessValue&, const uint32_t, const uint32_t)> fnCreateTextureData;

        if (baseColorTexture && metalRoughTexture)
        {
            width  = std::max(baseColorTexture->GetWidthInPixels(), metalRoughTexture->GetWidthInPixels());
            height = std::max(baseColorTexture->GetHeightInPixels(), metalRoughTexture->GetHeightInPixels());

            auto baseColor  = baseColorTexture->EncodeToBGRA(width, height);
            auto metalRough = metalRoughTexture->EncodeToBGRA(width, height);

            // If either of a texture's dimensions is smaller than the other texture's, resize it to the maximum.
            // It is possible for both textures to be resized, for example if they are 1024x512 and 512x1024 respectively.
            fnCreateTextureData = std::bind(&::ConvertMaterialMRToSG<ConverterTextureAccessorSRGB, ConverterTextureAccessorLinear>,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3,
                ConverterTextureAccessorSRGB(std::move(baseColor)),
                ConverterTextureAccessorLinear(std::move(metalRough)));
        }
        else if (baseColorTexture)
        {
            auto baseColor = baseColorTexture->EncodeToBGRA();
            width  = baseColor.Width;
            height = baseColor.Height;

            fnCreateTextureData = std::bind(&::ConvertMaterialMRToSG<ConverterTextureAccessorSRGB, ConverterDefaultAccessor>,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3,
                ConverterTextureAccessorSRGB(std::move(baseColor)),
                ConverterDefaultAccessor());
        }
        else if (metalRoughTexture)
        {
            auto metalRough = metalRoughTexture->EncodeToBGRA();
            width  = metalRough.Width;
            height = metalRough.Height;

            fnCreateTextureData = std::bind(&::ConvertMaterialMRToSG<ConverterDefaultAccessor, ConverterTextureAccessorLinear>,
                std::placeholders::_1,
                std::placeholders::_2,
                std::placeholders::_3,
                ConverterDefaultAccessor(),
                ConverterTextureAccessorLinear(std::move(metalRough)));
        }

        ConvertedMaterialData materialData = fnCreateTextureData(mrFactors, width, height);

        return TexturePair(
            std::make_shared<TextureDescriptor>(std::move(materialData.m_dataAlbedo),
                materialData.m_dataSize, width, height, width * 4U, Spectre::Framework::TextureSegment::EFormat::kFormatBGRA32),
            std::make_shared<TextureDescriptor>(std::move(materialData.m_dataWorkflow),
                materialData.m_dataSize, width, height, width * 4U, Spectre::Framework::TextureSegment::EFormat::kFormatBGRA32)
        );
    }
}

AlbedoWorkflowPair MaterialConversionUtils::SpecGlossToMetalRough(const std::shared_ptr<const MaterialLayer>& diffuseLayer, const std::shared_ptr<const MaterialLayer>& specGlossLayer)
{
    auto baseColorLayer  = std::make_shared<MaterialLayer>();
    auto metalRoughLayer = std::make_shared<MaterialLayer>();

    auto sgFactors = ToGltfSpecGlossValue(*diffuseLayer->Color, *specGlossLayer->Color);

    if (!diffuseLayer->Texture && !specGlossLayer->Texture)
    {
        auto mrFactors = Microsoft::glTF::SGToMR<Spectre::Utils::Math::Color>(sgFactors);

        baseColorLayer->SetColor(Color(mrFactors.base.R(), mrFactors.base.G(), mrFactors.base.B(), mrFactors.opacity));
        metalRoughLayer->SetColor(Color(1.0f, mrFactors.roughness, mrFactors.metallic, 1.0f));
    }
    else
    {
        TexturePair metalRoughTextures = ::SpecGlossToMetalRough(sgFactors, diffuseLayer->Texture, specGlossLayer->Texture);
        baseColorLayer->Texture  = std::get<0>(metalRoughTextures);
        baseColorLayer->SetColor(Color(Color::White));
        metalRoughLayer->Texture = std::get<1>(metalRoughTextures);
        metalRoughLayer->SetColor(Color(Color::White));

        if (diffuseLayer->Texture)
        {
            CopyLayerTextureAttributes(*diffuseLayer, *baseColorLayer);
        }
        else
        {
            CopyLayerTextureAttributes(*specGlossLayer, *baseColorLayer);
        }

        if (specGlossLayer->Texture)
        {
            CopyLayerTextureAttributes(*specGlossLayer, *metalRoughLayer);
        }
        else
        {
            CopyLayerTextureAttributes(*diffuseLayer, *metalRoughLayer);
        }
    }

    return AlbedoWorkflowPair({ baseColorLayer, metalRoughLayer });
}

AlbedoWorkflowPair MaterialConversionUtils::MetalRoughToSpecGloss(const std::shared_ptr<const MaterialLayer>& baseColorLayer, const std::shared_ptr<const MaterialLayer>& metalRoughLayer)
{
    auto diffuseLayer   = std::make_shared<MaterialLayer>();
    auto specGlossLayer = std::make_shared<MaterialLayer>();

    auto mrFactors = ToGltfMetalRoughValue(*baseColorLayer->Color, *metalRoughLayer->Color);

    if (!baseColorLayer->Texture && !metalRoughLayer->Texture)
    {
        auto sgFactors = Microsoft::glTF::MRToSG(mrFactors);

        diffuseLayer->SetColor(Color(sgFactors.diffuse.R(), sgFactors.diffuse.G(), sgFactors.diffuse.B(), sgFactors.opacity));
        specGlossLayer->SetColor(Color(sgFactors.specular.R(), sgFactors.specular.G(), sgFactors.specular.B(), sgFactors.glossiness));
    }
    else
    {
        TexturePair specGlossTextures = ::MetalRoughToSpecGloss(mrFactors, baseColorLayer->Texture, metalRoughLayer->Texture);
        diffuseLayer->Texture   = std::get<0>(specGlossTextures);
        diffuseLayer->SetColor(Color(Color::White));
        specGlossLayer->Texture = std::get<1>(specGlossTextures);
        specGlossLayer->SetColor(Color(Color::White));

        if (baseColorLayer->Texture)
        {
            CopyLayerTextureAttributes(*baseColorLayer, *diffuseLayer);
        }
        else
        {
            CopyLayerTextureAttributes(*specGlossLayer, *diffuseLayer);
        }

        if (metalRoughLayer->Texture)
        {
            CopyLayerTextureAttributes(*metalRoughLayer, *specGlossLayer);
        }
        else
        {
            CopyLayerTextureAttributes(*baseColorLayer, *specGlossLayer);
        }
    }

    return AlbedoWorkflowPair({ diffuseLayer, specGlossLayer });
}

// GLTF Compliance:
// Mimic the glossiness channel generated in Engine's legacy (non-GLTF) shader.
void MaterialConversionUtils::GenerateLegacyGlossiness(BGRAImage& bgra)
{
    uint8_t* const data = bgra.Data.data();

    for (size_t i = 0U; i < bgra.Data.size(); i += 4U)
    {
        const auto colour = Utils::Math::Color(DirectX::PackedVector::XMUBYTEN4(data + i));
        const auto colourGlossinessValue = Utils::glTF::GenerateLegacyGlossinessValue(colour);

        bgra.Data[i + 3] = Microsoft::glTF::Math::FloatToByte(colourGlossinessValue);
    }
}