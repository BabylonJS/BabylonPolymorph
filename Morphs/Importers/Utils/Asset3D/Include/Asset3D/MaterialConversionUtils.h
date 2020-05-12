/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Asset3D/MaterialLayer.h>
#include <Asset3D/TextureDescriptor.h>

#include <tuple>

namespace Babylon
{
    namespace Transcoder
    {
        struct AlbedoWorkflowPair
        {
            std::shared_ptr<MaterialLayer> Albedo;
            std::shared_ptr<MaterialLayer> Workflow;
        };

        namespace MaterialConversionUtils
        {
            AlbedoWorkflowPair SpecGlossToMetalRough(const std::shared_ptr<const MaterialLayer>& diffuseLayer,   const std::shared_ptr<const MaterialLayer>& specGlossLayer);
            AlbedoWorkflowPair MetalRoughToSpecGloss(const std::shared_ptr<const MaterialLayer>& baseColorLayer, const std::shared_ptr<const MaterialLayer>& metalRoughLayer);

            void GenerateLegacyGlossiness(BGRAImage& bgra);
        }
    }
}