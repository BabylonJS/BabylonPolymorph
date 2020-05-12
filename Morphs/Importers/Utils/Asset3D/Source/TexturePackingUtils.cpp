/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <Asset3D/TexturePackingUtils.h>

#include <Asset3D/MaterialLayer.h>
#include <Asset3D/TextureDescriptor.h>
#include <CoreUtils/Memory.h>
#include <ImagingComponent/ImagingComponent.h>

using namespace Babylon::Transcoder;
using namespace Babylon::Utils::Math;

namespace
{
    class PackerDefaultNormalAccessor final
    {
    public:
        PackerDefaultNormalAccessor() :
            m_value(Babylon::Utils::Math::Color(0.5f, 0.5f, 0.5f, 1.0f).BGRA())
        {
        }

        const uint8_t* operator()(uint32_t, uint32_t) const
        {
            return reinterpret_cast<const uint8_t*>(&m_value);
        }

        uint32_t m_value;
    };

    class PackerDefaultMetalRoughAccessor final
    {
    public:
        PackerDefaultMetalRoughAccessor() :
            m_value(Babylon::Utils::Math::Color(0.0f, 1.0f, 0.0f, 1.0f).BGRA())
        {
        }

        const uint8_t* operator()(uint32_t, uint32_t) const
        {
            return reinterpret_cast<const uint8_t*>(&m_value);
        }

        uint32_t m_value;
    };

    class PackerTextureAccessor final
    {
    public:
        PackerTextureAccessor(Babylon::Transcoder::BGRAImage&& image) :
            m_image(std::move(image))
        {
        }

        const uint8_t* operator()(uint32_t x, uint32_t y) const
        {
            size_t offset = (x * 4U) + (y * m_image.RowPitch);

            // Texture image format is BGRA in 'byte-order'
            return &m_image.Data[offset];
        }

    private:
        const Babylon::Transcoder::BGRAImage m_image;
    };

    struct ConvertedTextureData
    {
        ConvertedTextureData(size_t dataSize) :
            m_dataSize(dataSize),
            m_data(std::make_unique<uint8_t[]>(m_dataSize))
        {
        }

        const size_t m_dataSize;
        std::unique_ptr<uint8_t[]> m_data;
    };

    template<typename FnNormal, typename FnMetalRough>
    ConvertedTextureData MergeNormalAndMetalRough(const uint32_t textureWidth, const uint32_t textureHeight, FnNormal fnNormal, FnMetalRough fnMetalRough)
    {
        size_t index = 0;

        const auto pixelSize = sizeof(uint32_t);
        const auto pixelBytes = pixelSize * textureWidth * textureHeight;

        ConvertedTextureData generatedData(pixelBytes);

        for (uint32_t y = 0U; y < textureHeight; ++y)
        {
            for (uint32_t x = 0U; x < textureWidth; ++x)
            {
                // BGRA values
                auto normal     = fnNormal(x, y);     // [0] = normal.z  [1] = normal.y  [2] = normal.x [3] = N/A
                auto metalRough = fnMetalRough(x, y); // [0] = metallic  [1] = roughness [2] = N/A      [3] = N/A

                uint32_t normalMetalRough =
                    metalRough[1] << 0  | // Blue  = roughness
                    normal[1]     << 8  | // Green = normal.y
                    normal[2]     << 16 | // Red   = normal.x
                    metalRough[0] << 24;  // Alpha = metallic

                memcpy_s(generatedData.m_data.get() + index, pixelBytes - index, &normalMetalRough, sizeof(normalMetalRough));

                index += pixelSize;
            }
        }

        return generatedData;
    }

    std::shared_ptr<TextureDescriptor> PackNormalRoughnessMetallic(
        const std::shared_ptr<const TextureDescriptor>& normalTexture,
        const std::shared_ptr<const TextureDescriptor>& metalRoughTexture
    )
    {
        uint32_t width = 0;
        uint32_t height = 0;

        std::function<::ConvertedTextureData(const uint32_t, const uint32_t)> fnCreateTextureData;

        if (normalTexture && metalRoughTexture)
        {
            width = std::max(normalTexture->GetWidthInPixels(), metalRoughTexture->GetWidthInPixels());
            height = std::max(normalTexture->GetHeightInPixels(), metalRoughTexture->GetHeightInPixels());

            auto normal = normalTexture->EncodeToBGRA(width, height);
            auto metalRough = metalRoughTexture->EncodeToBGRA(width, height);

            // If either of a texture's dimensions is smaller than the other texture's, resize it to the maximum.
            // It is possible for both textures to be resized, for example if they are 1024x512 and 512x1024 respectively.
            fnCreateTextureData = std::bind(&::MergeNormalAndMetalRough<PackerTextureAccessor, PackerTextureAccessor>,
                std::placeholders::_1,
                std::placeholders::_2,
                PackerTextureAccessor(std::move(normal)),
                PackerTextureAccessor(std::move(metalRough)));
        }
        else if (normalTexture)
        {
            auto normal = normalTexture->EncodeToBGRA();
            width = normal.Width;
            height = normal.Height;

            fnCreateTextureData = std::bind(&::MergeNormalAndMetalRough<PackerTextureAccessor, PackerDefaultMetalRoughAccessor>,
                std::placeholders::_1,
                std::placeholders::_2,
                PackerTextureAccessor(std::move(normal)),
                PackerDefaultMetalRoughAccessor());
        }
        else if (metalRoughTexture)
        {
            auto metalRough = metalRoughTexture->EncodeToBGRA();
            width = metalRough.Width;
            height = metalRough.Height;

            fnCreateTextureData = std::bind(&::MergeNormalAndMetalRough<PackerDefaultNormalAccessor, PackerTextureAccessor>,
                std::placeholders::_1,
                std::placeholders::_2,
                PackerDefaultNormalAccessor(),
                PackerTextureAccessor(std::move(metalRough)));
        }

        ConvertedTextureData textureData = fnCreateTextureData(width, height);

        return std::make_shared<TextureDescriptor>(std::move(textureData.m_data),
            textureData.m_dataSize, width, height, width * 4U, Babylon::Framework::TextureSegment::EFormat::kFormatBGRA32);
    }

    void CopyLayerTextureAttributes(const MaterialLayer& source, MaterialLayer& target)
    {
        target.UVSetIndex = source.UVSetIndex;
        target.Sampler = source.Sampler;
        target.TextureTransform = source.TextureTransform;

        if (target.Texture)
        {
            target.Texture->SetExtensions(source.Texture->GetExtensions());
            target.Texture->SetExtras(source.Texture->GetExtras());
        }
    }
}

std::shared_ptr<MaterialLayer> TexturePackingUtils::PackNormalRoughnessMetallic(const std::shared_ptr<const MaterialLayer>& normalLayer, const std::shared_ptr<const MaterialLayer>& metalRoughLayer)
{
    std::shared_ptr<TextureDescriptor> normalTexture     = normalLayer     ? normalLayer->Texture     : nullptr;
    std::shared_ptr<TextureDescriptor> metalRoughTexture = metalRoughLayer ? metalRoughLayer->Texture : nullptr;

    if (!normalTexture && !metalRoughTexture)
    {
        return nullptr;
    }

    auto normalMetalRoughTexture = ::PackNormalRoughnessMetallic(normalTexture, metalRoughTexture);

    auto normalMetalRoughLayer = std::make_shared<MaterialLayer>();
    normalMetalRoughLayer->Texture = normalMetalRoughTexture;

    if (normalLayer)
    {
        CopyLayerTextureAttributes(*normalLayer, *normalMetalRoughLayer);
    }
    else if (metalRoughLayer)
    {
        CopyLayerTextureAttributes(*metalRoughLayer, *normalMetalRoughLayer);
    }

    std::string textureName;
    if (normalLayer && normalLayer->Texture)
    {
        textureName = normalLayer->Texture->GetName();
    }

    if (metalRoughLayer && metalRoughLayer->Texture)
    {
        textureName += metalRoughLayer->Texture->GetName();
    }

    normalMetalRoughLayer->Texture->SetName(textureName);

    return normalMetalRoughLayer;
}