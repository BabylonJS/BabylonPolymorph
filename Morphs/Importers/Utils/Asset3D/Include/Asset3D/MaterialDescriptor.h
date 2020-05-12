/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Asset3D/ITraversable.h>
#include <Asset3D/MaterialConversionUtils.h>
#include <Asset3D/MaterialLayer.h>
#include <CoreUtils/Math/SimpleMath.h>
#include <Framework/Enums.h>

namespace Babylon
{
    namespace Transcoder
    {
        class TextureDescriptor;

        using LayerType = Babylon::Framework::TextureMaterialLayer;

        using RenderingMode = Framework::MaterialDefinition::BabylonRenderingMode;
        using RenderingOption = Framework::MaterialDefinition::BabylonRenderingOption;
        using RenderingOptions = Framework::MaterialDefinition::BabylonRenderingOptions;

        /// \brief
        /// MaterialDescriptor describes the material properties to be used when rendering mesh instances.
        ///
        /// OVERVIEW
        /// --------
        /// A MaterialDescriptor contains a number of layers, indexed by the enum LayerType. An
        /// individual layer is described by the struct MaterialDescriptor::LayerInfo, and can be
        /// accessed using the GetLayer method.
        class MaterialDescriptor : public ITraversableWithName
        {
        public:
            using LayerInfo = Babylon::Transcoder::MaterialLayer;

            MaterialDescriptor();
            MaterialDescriptor(bool defaultLayers);

            // Layers
            const std::shared_ptr<LayerInfo>& GetLayer(LayerType layerType) const { return m_layers[static_cast<size_t>(layerType)]; }
            std::shared_ptr<LayerInfo> AddLayer(LayerType layerType) { return m_layers[static_cast<size_t>(layerType)] = std::make_shared<LayerInfo>(); }
            std::shared_ptr<LayerInfo> GetOrAddLayer(LayerType layerType) { auto layer = GetLayer(layerType); return layer ? layer : AddLayer(layerType); }

            AlbedoWorkflowPair GetOrGenerateSpecGloss();
            AlbedoWorkflowPair GetOrGenerateMetalRough();

            // Utility functions to gather all Layers/Colors/Textures, these will only include non-null items
            std::map<LayerType, std::shared_ptr<LayerInfo>> GetLayers() const;
            std::map<LayerType, Utils::Math::Color> GetColors() const;
            std::map<LayerType, std::shared_ptr<TextureDescriptor>> GetTextures() const;

            // Flags
            void SetRenderingMode(RenderingMode mode) { m_renderingMode = mode; }
            RenderingMode GetRenderingMode() const { return m_renderingMode; }
            void SetRenderingOptions(RenderingOptions options) { m_renderingOptions = options; }
            void SetRenderingOption(RenderingOption option) { m_renderingOptions |= option; }
            bool HasRenderingOption(RenderingOption option) const { return (m_renderingOptions & option) == option; }
            RenderingOptions GetRenderingOptions() const { return m_renderingOptions; }

            // Helpers for specific factors/coefficients
            void SetMetalRoughFactors(float metallicFactor, float roughnessFactor)
            {
                GetLayer(LayerType::kMetallicRoughness)->SetColor(Utils::Math::Color(1.0f, roughnessFactor, metallicFactor));
            }
            float GetRoughnessFactor() const { return GetLayer(LayerType::kMetallicRoughness)->Color->G(); }
            float GetMetallicFactor() const { return GetLayer(LayerType::kMetallicRoughness)->Color->B(); }

            float GetAlphaCutoff() const { return m_alphaCutoff; }
            void SetAlphaCutoff(float cutoff) { m_alphaCutoff = cutoff; }

            // Hacks
            void EnsureHeightMapConversion() const; // TODO: Shouldn't really be const, but Engine is currently relying on this
            bool ShouldOverwriteGLTFFactors() const;
            void ConvertFromLegacy();

        private:
            std::array<std::shared_ptr<LayerInfo>, static_cast<size_t>(LayerType::kNumLayers)> m_layers;

            RenderingMode m_renderingMode = RenderingMode::Default; // Alpha-mode
            RenderingOptions m_renderingOptions = RenderingOption::None; // Mostly Engine hacks

            float m_alphaCutoff = 0.5f; // Applies when renderingMode is BabylonRenderingMode::Mask
        };
    }
}

inline float SmoothnessToSpecularPower(float smoothness)
{
    // Convert perceptual smoothness [0,1] into cosine specular power using the transfer function used by
    // Marmoset Toolbag and Unity 5. For further information see: Marmoset documentation, Unity documentation
    // and standard shaders, and Knald (normal map generator) documentation: https://s3.amazonaws.com/docs.knaldtech.com/knald/1.0.0/lys_power_drops.html
    return powf(10.0f / log2(smoothness * 0.968f + 0.03f), 2.0f);
}

inline float SpecularPowerToSmoothness(float specularPower)
{
    if (specularPower == 0.0f)
    {
        return 0.0f;
    }

    // The function is used to smoothen the Specular color of a material.
    // It doesn't make any physical sense but it makes things look nicer =)f
    return (exp2(10.f / (-sqrtf(specularPower))) - 0.03f) / 0.968f;
}
