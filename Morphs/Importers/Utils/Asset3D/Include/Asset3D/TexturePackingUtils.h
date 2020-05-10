/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace Babylon
{
    namespace Transcoder
    {
        struct MaterialLayer;

        namespace TexturePackingUtils
        {
            std::shared_ptr<MaterialLayer> PackNormalRoughnessMetallic(const std::shared_ptr<const MaterialLayer>& normalLayer, const std::shared_ptr<const MaterialLayer>& metalRoughLayer);
        }
    }
}