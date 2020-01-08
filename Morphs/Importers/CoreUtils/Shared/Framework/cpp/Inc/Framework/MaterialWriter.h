/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#pragma once

#include <Framework/IBuffer.h>
#include <Framework/Types.h>
#include <Framework/MemoryBuffer.h>

#include <CoreUtils/SpectreSDK.h>

#include <cstdint>
#include <memory>

namespace Spectre
{
    namespace Framework
    {
        /**
         * Use the MaterialWriter to help you serialize out material data in the
         * common object format.
         */
        class SPECTRESDK_API IMaterialWriter
        {

        public:
            virtual ~IMaterialWriter() {}

            virtual void BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numMaterials,
                EByteOrder byteOrder) = 0;

            virtual Frame* EndFrame() = 0;

            virtual void BeginMaterial(uint32_t materialId) = 0;
            virtual void EndMaterial() = 0;

            virtual void SetDiffuseABGR(uint32_t difColour,
                uint32_t difTexture,
                SamplerDefinition sampler) = 0;

            virtual void SetSpecularABGR(uint32_t specColour,
                uint32_t specTexture,
                SamplerDefinition sampler) = 0;

            virtual void SetEmissiveABGR(uint32_t emisColour,
                uint32_t emisTexture,
                SamplerDefinition sampler,
                float intensity) = 0;

            virtual void SetNormal(uint32_t normalMap, SamplerDefinition sampler) = 0;

            virtual void SetDepth(uint32_t depthMap, SamplerDefinition sampler) = 0;

            virtual void SetOcclusion(uint32_t occlusionMap, SamplerDefinition sampler) = 0;

            virtual void SetDetail(uint32_t detailMap, SamplerDefinition sampler) = 0;

            virtual void SetShaderType(MaterialDefinition::EShaderType) = 0;

            virtual void SetSpectreRenderingMode(MaterialDefinition::SpectreRenderingMode mode) = 0;

            virtual void AppendSpectreRenderingOption(MaterialDefinition::SpectreRenderingOption option) = 0;

            virtual void SetSpectreRenderingOptions(MaterialDefinition::SpectreRenderingOptions options) = 0;

            virtual MaterialDefinition::SpectreRenderingMode GetSpectreRenderingMode() const = 0;

            virtual MaterialDefinition::SpectreRenderingOptions GetSpectreRenderingOptions() const = 0;

            virtual bool HasSpectreRenderingOption(MaterialDefinition::SpectreRenderingOption option) const = 0;

            virtual uint32_t GetVersion() const = 0;

        protected:
            virtual uint32_t WriteSampler(SamplerDefinition const& sampler, std::shared_ptr<IBuffer> const& outputBuffer) = 0;
        };

        SPECTRESDK_API IMaterialWriter* MaterialWriterCreate();
        SPECTRESDK_API void MaterialWriterDestroy(IMaterialWriter*& pWriter);

    } // End namespace Cool

} // End namespace Spectre
