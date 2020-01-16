/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>

namespace Babylon
{
    namespace Framework
    {
        enum class MaterialLayer : uint8_t
        {
            kAlbedo = 0,   // Could be Diffuse+Alpha       or BaseColor+Alpha    depending on the value of m_BabylonRenderingMode
            kEmissive = 1,
            kWorkflow = 2, // Could be Specular+Glossiness or Metallic+Roughness depending on the value of m_BabylonRenderingMode
            kNormal = 3,
            kDepth = 4,
            kOcclusion = 5,
            kDetail = 6,
            kNumLayers
        };

        // Material Layers to which a texture could be associated
        enum class TextureMaterialLayer : uint8_t
        {
            kDiffuse = 0,
            kEmissive = 1,
            kSpecularGlossiness = 2,
            kNormal = 3,
            kDepth = 4,
            kOcclusion = 5,
            kDetail = 6,
            kBaseColor = 7,
            kMetallicRoughness = 8,
            kNumLayers
        };

        enum class FilterMode : uint8_t
        {
            kPoint = 1,
            kBilinear = 2,
            kTrilinear = 3,
            kMinPoint_MagPoint_MipPoint = kPoint,
            kMinPoint_MagPoint_MipLinear = 4,
            kMinPoint_MagLinear_MipPoint = 5,
            kMinPoint_MagLinear_MipLinear = 6,
            kMinLinear_MagPoint_MipPoint = 7,
            kMinLinear_MagPoint_MipLinear = 8,
            kMinLinear_MagLinear_MipPoint = kBilinear,
            kMinLinear_MagLinear_MipLinear = kTrilinear,
        };

        enum class AddressMode : uint8_t
        {
            kClamp = 1,
            kWrap = 2,
            kMirroredWrap = 3
        };
    }
}