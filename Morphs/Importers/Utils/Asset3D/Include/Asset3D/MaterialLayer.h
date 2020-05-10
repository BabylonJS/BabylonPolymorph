/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Optional.h>
#include <CoreUtils/Math/SimpleMath.h>

#include <Framework/Enums.h>

#include <memory>

namespace Babylon
{
    namespace Transcoder
    {
        class TextureDescriptor;

        /// MaterialLayer describes a single layer within a MaterialDescriptor, indexed by the enum LayerType.
        struct MaterialLayer
        {
            /// TextureSampler describe how UV coordinates will be interpreted when mapping a texture onto a mesh
            struct TextureSampler
            {
                float translationU = 0.0f;                                       ///< U translation
                float translationV = 0.0f;                                       ///< V translation
                float scaleU = 1.0f;                                             ///< U scaling
                float scaleV = 1.0f;                                             ///< V scaling
                Framework::AddressMode wrapU = Framework::AddressMode::kWrap;    ///< Wrapping behavior for the U coordinate
                Framework::AddressMode wrapV = Framework::AddressMode::kWrap;    ///< Wrapping behavior for the V coordinate
                Utils::Optional<Framework::FilterMode> filter = Framework::FilterMode::kBilinear; ///< Filtering behavior for the texture

                bool operator==(const TextureSampler& other) const
                {
                    return ((translationU == other.translationU)
                        && (translationV == other.translationV)
                        && (scaleU == other.scaleU)
                        && (scaleV == other.scaleV)
                        && (wrapU == other.wrapU)
                        && (wrapV == other.wrapV)
                        && (filter == other.filter));
                }
            };

            void SetColor(uint32_t color) { Color = std::make_shared<Utils::Math::Color>(Utils::Math::Color::FromRGBA(color)); }
            void SetColor(Utils::Math::Color&& color) { Color = std::make_shared<Utils::Math::Color>(std::move(color)); }

            /// Optional RGBA color for this layer (NULL means "color not set")
            std::shared_ptr<Utils::Math::Color> Color;

            /// Scalar texture multiplier  (ONLY VALID for kNormal, kOcclusion)
            float Coefficient = 0.0f;

            /// Optional texture for this layer (NULL means "texture not set")
            std::shared_ptr<TextureDescriptor> Texture;

            /// Texture UV set to use for texture (ONLY VALID when Texture is set)
            uint32_t UVSetIndex = 0;

            /// Texture sampler settings for this layer (ONLY VALID when Texture is set)
            // TODO: GLTF allows instancing of samplers, however we de-instance them currently
            TextureSampler Sampler;

            /// Texture transform matrix (ONLY VALID when Texture is set)
            Utils::Math::Matrix TextureTransform;
        };
    }
}