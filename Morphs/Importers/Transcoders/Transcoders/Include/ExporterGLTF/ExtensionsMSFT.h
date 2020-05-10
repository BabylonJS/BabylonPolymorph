/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <GLTFSDK/ExtensionHandlers.h>

namespace Babylon
{
    namespace Transcoder
    {
        constexpr const char* MSFT_LOD = "MSFT_lod";
        constexpr const char* MSFT_LOD_IDS_KEY = "ids";

        constexpr const char* MSFT_TEXTURE_DDS = "MSFT_texture_dds";
        constexpr const char* FILE_EXT_DDS = "dds";
        constexpr const char* MIMETYPE_DDS = "image/vnd-ms.dds";

        constexpr const char* MSFT_PACKING_NORMALROUGHNESSMETALLIC    = "MSFT_packing_normalRoughnessMetallic";
        constexpr const char* MSFT_PACKING_OCCLUSIONROUGHNESSMETALLIC = "MSFT_packing_occlusionRoughnessMetallic";

        Microsoft::glTF::ExtensionSerializer GetMSFTKHRExtensionSerializer();

        struct MSFT_lod : Microsoft::glTF::Extension
        {
            std::vector<std::string> ids;

            std::unique_ptr<Extension> Clone() const override
            {
                return std::make_unique<MSFT_lod>(*this);
            }

            bool IsEqual(const Extension& rhs) const override
            {
                const auto other = dynamic_cast<const MSFT_lod*>(&rhs);

                return other != nullptr
                    && this->ids == other->ids;
            }
        };

        struct MSFT_texture_dds : Microsoft::glTF::Extension
        {
            MSFT_texture_dds(std::string imageId) : imageId(std::move(imageId)) {}

            std::string imageId;

            std::unique_ptr<Extension> Clone() const override
            {
                return std::make_unique<MSFT_texture_dds>(*this);
            }

            bool IsEqual(const Extension& rhs) const override
            {
                const auto other = dynamic_cast<const MSFT_texture_dds*>(&rhs);

                return other != nullptr
                    && this->imageId == other->imageId;
            }
        };

        struct MSFT_packing_normalRoughnessMetallic : Microsoft::glTF::Extension
        {
            Microsoft::glTF::Material::NormalTextureInfo normalRoughnessMetallicTexture;

            std::unique_ptr<Extension> Clone() const override
            {
                return std::make_unique<MSFT_packing_normalRoughnessMetallic>(*this);
            }

            bool IsEqual(const Extension& rhs) const override
            {
                const auto other = dynamic_cast<const MSFT_packing_normalRoughnessMetallic*>(&rhs);

                return other != nullptr
                    && this->normalRoughnessMetallicTexture == other->normalRoughnessMetallicTexture;
            }
        };

        struct MSFT_packing_occlusionRoughnessMetallic : Microsoft::glTF::Extension
        {
            Microsoft::glTF::Material::OcclusionTextureInfo occlusionRoughnessMetallicTexture;
            Microsoft::glTF::Material::OcclusionTextureInfo roughnessMetallicOcclusionTexture;
            Microsoft::glTF::Material::NormalTextureInfo normalTexture;

            std::unique_ptr<Extension> Clone() const override
            {
                return std::make_unique<MSFT_packing_occlusionRoughnessMetallic>(*this);
            }

            bool IsEqual(const Extension& rhs) const override
            {
                const auto other = dynamic_cast<const MSFT_packing_occlusionRoughnessMetallic*>(&rhs);

                return other != nullptr
                    && this->occlusionRoughnessMetallicTexture == other->occlusionRoughnessMetallicTexture
                    && this->roughnessMetallicOcclusionTexture == other->roughnessMetallicOcclusionTexture
                    && this->normalTexture == other->normalTexture;
            }
        };
    }
}