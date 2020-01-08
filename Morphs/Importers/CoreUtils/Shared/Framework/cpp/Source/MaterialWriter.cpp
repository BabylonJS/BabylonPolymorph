/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.        *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/MaterialWriter.h>

#include <functional>
#include <vector>

#include <Framework/Types.h>
#include <Framework/MaterialSegment.h>
#include <Framework/FormatWriterUtils.h>

namespace Spectre
{
    namespace Framework
    {
        namespace V1
        {
            class MaterialWriter : public IMaterialWriter, public CommonFrameWriter
            {

            private:
                static const uint32_t sVERSION = 1;

            public:
                MaterialWriter();
                virtual ~MaterialWriter();

                virtual void BeginFrame(
                    std::shared_ptr<IBuffer> const& outputBuffer,
                    uint32_t numMaterials,
                    EByteOrder byteOrder);

                virtual Frame* EndFrame();

                virtual void BeginMaterial(uint32_t materialId);
                virtual void EndMaterial();

                virtual void SetDiffuseABGR(uint32_t difColour,
                                            uint32_t difTexture,
                                            SamplerDefinition sampler);

                virtual void SetSpecularABGR(uint32_t specColour,
                                             uint32_t specTexture,
                                             SamplerDefinition sampler);

                virtual void SetEmissiveABGR(uint32_t emisColour,
                                             uint32_t emisTexture,
                                             SamplerDefinition sampler,
                                             float intensity);

                virtual void SetNormal(uint32_t normalMap, SamplerDefinition sampler);

                virtual void SetDepth(uint32_t depthMap, SamplerDefinition sampler);

                virtual void SetOcclusion(uint32_t occlusionMap, SamplerDefinition sampler);

                virtual void SetDetail(uint32_t detailMap, SamplerDefinition sampler);

                virtual uint32_t WriteSampler(SamplerDefinition const& sampler,
                                              std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer);

                void WriteAllSamplers(uint32_t headerOffset, std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer);

                virtual void SetShaderType(MaterialDefinition::EShaderType shaderType);

                virtual void SetSpectreRenderingMode(MaterialDefinition::SpectreRenderingMode mode);

                virtual void AppendSpectreRenderingOption(MaterialDefinition::SpectreRenderingOption option);

                virtual void SetSpectreRenderingOptions(MaterialDefinition::SpectreRenderingOptions options);

                virtual MaterialDefinition::SpectreRenderingOptions GetSpectreRenderingOptions() const;

                virtual MaterialDefinition::SpectreRenderingMode GetSpectreRenderingMode() const;

                virtual bool HasSpectreRenderingOption(MaterialDefinition::SpectreRenderingOption options) const;

                virtual uint32_t GetVersion() const
                {
                    return sVERSION;
                }

            protected:
                inline bool IsValidMaterial() const { return m_materialId != 0; }

                void Reset()
                {
                    // don't call DoReset here.
                    m_materialId = 0;
                    m_totalSamplers = 0;
                    m_diffuseColour = 0;
                    m_diffuseTexture = 0;
                    m_diffuseSamplerOffset = 0;
                    //Reset the Diffuse Sampler Data
                    m_diffuseSampler = {};

                    m_specularColour = 0;
                    m_specularTexture = 0;
                    m_specularSamplerOffset = 0;
                    //Reset the Specular Sampler Data
                    m_specularSampler = {};

                    m_emissiveIntensity = 1.0f;
                    m_emissiveColour = 0;
                    m_emissiveTexture = 0;
                    m_emissiveSamplerOffset = 0;
                    //Reset the Emissive Sampler Data
                    m_emissiveSampler = {};

                    m_normalMap = 0;
                    m_normalSamplerOffset = 0;
                    //Reset the Normal Sampler Data
                    m_normalSampler = {};

                    m_depthMap = 0;
                    m_depthSamplerOffset = 0;
                    //Reset the Depth Sampler Data
                    m_depthSampler = {};

                    m_occlusionMap = 0;
                    m_occlusionSamplerOffset = 0;
                    //Reset the Occlusion Sampler Data
                    m_occlusionSampler = {};

                    m_detailMap = 0;
                    m_detailSamplerOffset = 0;
                    //Reset the Detail Sampler Data
                    m_detailSampler = {};

                    m_formatMask = 0;
                    m_shaderType = 0;
                }

            private:
                MaterialWriter(const MaterialWriter& rhs);

                // Working buffers
                uint32_t m_materialId;
                uint32_t m_totalSamplers;

                uint32_t m_diffuseColour;    // The full size of the TextureSegment in bytes
                uint32_t m_diffuseTexture;
                uint32_t m_diffuseSamplerOffset;
                SamplerDefinition m_diffuseSampler;

                uint32_t m_specularColour;
                uint32_t m_specularTexture;
                uint32_t m_specularSamplerOffset;
                SamplerDefinition m_specularSampler;

                uint32_t m_emissiveColour;
                uint32_t m_emissiveTexture;
                uint32_t m_emissiveSamplerOffset;
                float m_emissiveIntensity;
                SamplerDefinition m_emissiveSampler;

                uint32_t m_normalMap;
                uint32_t m_normalSamplerOffset;
                SamplerDefinition m_normalSampler;

                uint32_t m_depthMap;
                uint32_t m_depthSamplerOffset;
                SamplerDefinition m_depthSampler;

                uint32_t m_occlusionMap;
                uint32_t m_occlusionSamplerOffset;
                SamplerDefinition m_occlusionSampler;

                uint32_t m_detailMap;
                uint32_t m_detailSamplerOffset;
                SamplerDefinition m_detailSampler;

                uint32_t m_formatMask;

                uint32_t m_shaderType;
            };

            //---------------------------------------------------------------------
            MaterialWriter::MaterialWriter()
            {
                Reset();
            }

            //---------------------------------------------------------------------
            MaterialWriter::~MaterialWriter()
            {
            }

            //---------------------------------------------------------------------
            void MaterialWriter::BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numMaterials,
                EByteOrder byteOrder)
            {
                this->DoReset();
                this->DoBeginFrame(outputBuffer, numMaterials, byteOrder, kFrameMaterial);
            }

            //---------------------------------------------------------------------
            Frame* MaterialWriter::EndFrame()
            {
                return this->DoEndFrame();
            }

            //---------------------------------------------------------------------
            void MaterialWriter::BeginMaterial(uint32_t materialId)
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("MaterialWriter::BeginMaterial: You must call BeginFrame first");
                }
                if (m_materialId != 0)
                {
                    throw Utils::SpectreFailException("Call to BeginMaterial without a call to EndMaterial");
                }
                if (materialId == 0)
                {
                    throw Utils::SpectreInvalidArgException("Invalid materialId of 0 specified");
                }

                Reset();
                m_materialId = materialId;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::EndMaterial()
            {
                if (m_outputBuffer == nullptr)
                {
                    throw Utils::SpectreFailException("NULL output buffer");
                }
                if (!IsValidMaterial())
                {
                    throw Utils::SpectreFailException("Need to call BeginMaterial first");
                }

                // Copy the serialized streams to the output buffer

                MaterialDefinition segment;
                memset(&segment, 0, sizeof(segment));

                segment.Version = m_byteSwapU32(MaterialDefinition::kVersion0);
                segment.MaterialID = m_byteSwapU32(m_materialId);
                segment.NumSamplers = m_byteSwapU32(m_totalSamplers);

                segment.FormatMask = m_byteSwapU32(m_formatMask);
                segment.Version = m_byteSwapU32(MaterialDefinition::kVersion0);
                segment.MaterialID = m_byteSwapU32(m_materialId);
                segment.DiffuseColour = m_byteSwapU32(m_diffuseColour);
                segment.DiffuseMap = m_byteSwapU32(m_diffuseTexture);
                segment.SpecularColour = m_byteSwapU32(m_specularColour);
                segment.SpecularMap = m_byteSwapU32(m_specularTexture);
                segment.EmissiveColour = m_byteSwapU32(m_emissiveColour);
                segment.EmissiveIntensity = m_byteSwapFloat(m_emissiveIntensity);
                segment.EmissiveMap = m_byteSwapU32(m_emissiveTexture);
                segment.NormalMap = m_byteSwapU32(m_normalMap);
                segment.DepthMap = m_byteSwapU32(m_depthMap);
                segment.OcclusionMap = m_byteSwapU32(m_occlusionMap);
                segment.DetailMap = m_byteSwapU32(m_detailMap);
                segment.ShaderType = m_byteSwapU32(m_shaderType);

                // Write header...
                uint32_t headerOffset = m_outputBuffer->WriteDataRaw(&segment, sizeof(segment), 4);

                // Save material offset

                m_savedItemOffsets.push_back(headerOffset);
                ++m_numItems;

                uint32_t totalSizeInBytes = sizeof(MaterialDefinition);

                SpectreUnusedParameter(totalSizeInBytes);

                WriteAllSamplers(headerOffset, m_outputBuffer);

                MaterialDefinition* pHeader = static_cast<MaterialDefinition*>(m_outputBuffer->GetBuffer(headerOffset));
                pHeader->NormalSamplerOffset = m_byteSwapU32(pHeader->NormalSamplerOffset);
                pHeader->DiffuseSamplerOffset = m_byteSwapU32(pHeader->DiffuseSamplerOffset);
                pHeader->SpecularSamplerOffset = m_byteSwapU32(pHeader->SpecularSamplerOffset);
                pHeader->DepthSamplerOffset = m_byteSwapU32(pHeader->DepthSamplerOffset);
                pHeader->EmissiveSamplerOffset = m_byteSwapU32(pHeader->EmissiveSamplerOffset);
                pHeader->OcclusionSamplerOffset = m_byteSwapU32(pHeader->OcclusionSamplerOffset);
                pHeader->DetailSamplerOffset = m_byteSwapU32(pHeader->DetailSamplerOffset);

                // Reset the state
                m_materialId = 0;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::WriteAllSamplers(uint32_t headerOffset,
                                                  std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer)
            {
                SpectreUnusedParameter(outputBuffer);

                // Write the offsets
                uint32_t diffuseOffset = 0;
                uint32_t specularOffset = 0;
                uint32_t normalOffset = 0;
                uint32_t depthOffset = 0;
                uint32_t emissiveOffset = 0;
                uint32_t occlusionOffset = 0;
                uint32_t detailOffset = 0;

                normalOffset = WriteSampler(m_normalSampler, m_outputBuffer);
                diffuseOffset = WriteSampler(m_diffuseSampler, m_outputBuffer);
                specularOffset = WriteSampler(m_specularSampler, m_outputBuffer);
                depthOffset = WriteSampler(m_depthSampler, m_outputBuffer);
                emissiveOffset = WriteSampler(m_emissiveSampler, m_outputBuffer);
                occlusionOffset = WriteSampler(m_occlusionSampler, m_outputBuffer);
                detailOffset = WriteSampler(m_detailSampler, m_outputBuffer);

                // Patch the offsets (these are relative to the material header, not the frame)...
                MaterialDefinition* pHeader = static_cast<MaterialDefinition*>(m_outputBuffer->GetBuffer(headerOffset));
                pHeader->NormalSamplerOffset = normalOffset == 0 ? normalOffset : (normalOffset - headerOffset);
                pHeader->DiffuseSamplerOffset = diffuseOffset == 0 ? diffuseOffset : (diffuseOffset - headerOffset);
                pHeader->SpecularSamplerOffset = specularOffset == 0 ? specularOffset : (specularOffset - headerOffset);
                pHeader->DepthSamplerOffset = depthOffset == 0 ? depthOffset : (depthOffset - headerOffset);
                pHeader->EmissiveSamplerOffset = emissiveOffset == 0 ? emissiveOffset : (emissiveOffset - headerOffset);
                pHeader->OcclusionSamplerOffset = occlusionOffset == 0 ? occlusionOffset : (occlusionOffset - headerOffset);
                pHeader->DetailSamplerOffset = detailOffset == 0 ? detailOffset : (detailOffset - headerOffset);
            }

            //---------------------------------------------------------------------
            // <summary>
            // Write and byte swap the specified sampler to the output buffer
            // </summary>
            uint32_t MaterialWriter::WriteSampler(SamplerDefinition const& sampler,
                                                  std::shared_ptr<Spectre::Framework::IBuffer> const& outputBuffer)
            {
                auto offset = outputBuffer->WriteDataRaw(&sampler, sizeof(SamplerDefinition), 4);
                SamplerDefinition* pSampler = (SamplerDefinition*)outputBuffer->GetBuffer(offset);

                // 32 bit Values
                pSampler->BorderColour = m_byteSwapU32(pSampler->BorderColour);

                // Floats
                pSampler->UOffset = m_byteSwapFloat(pSampler->UOffset);
                pSampler->UTiling = m_byteSwapFloat(pSampler->UTiling);
                pSampler->VOffset = m_byteSwapFloat(pSampler->VOffset);
                pSampler->VTiling = m_byteSwapFloat(pSampler->VTiling);

                // 8 bit values
                pSampler->FilterMode = pSampler->FilterMode;
                pSampler->UAddress = pSampler->UAddress;
                pSampler->VAddress = pSampler->VAddress;
                pSampler->WAddress = pSampler->WAddress;

                return offset;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetDiffuseABGR(uint32_t difColour,
                                                uint32_t difTexture,
                                                SamplerDefinition sampler)
            {
                m_diffuseColour = difColour;
                m_diffuseTexture = difTexture;
                m_diffuseSampler = sampler;
                m_formatMask |= MaterialDefinition::kHasDiffuse;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetSpecularABGR(uint32_t specColour,
                                                 uint32_t specTexture,
                                                 SamplerDefinition sampler)
            {
                m_specularColour = specColour;
                m_specularTexture = specTexture;
                m_specularSampler = sampler;
                m_formatMask |= MaterialDefinition::kHasSpecular;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetEmissiveABGR(uint32_t emisColour,
                                                 uint32_t emisTexture,
                                                 SamplerDefinition sampler,
                                                 float intensity)
            {
                m_emissiveColour = emisColour;
                m_emissiveTexture = emisTexture;
                m_emissiveSampler = sampler;
                m_emissiveIntensity = intensity;
                m_formatMask |= MaterialDefinition::kHasEmissive;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetNormal(uint32_t normalMap, SamplerDefinition sampler)
            {
                m_normalMap = normalMap;
                m_normalSampler = sampler;
                m_formatMask |= MaterialDefinition::kHasNormal;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetDepth(uint32_t depthMap, SamplerDefinition sampler)
            {
                m_depthMap = depthMap;
                m_depthSampler = sampler;
                m_formatMask |= MaterialDefinition::kHasDepth;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetOcclusion(uint32_t occlusionMap, SamplerDefinition sampler)
            {
                m_occlusionMap = occlusionMap;
                m_occlusionSampler = sampler;
                m_formatMask |= MaterialDefinition::kHasOcclusion;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetDetail(uint32_t detailMap, SamplerDefinition sampler)
            {
                m_detailMap = detailMap;
                m_detailSampler = sampler;
                m_formatMask |= MaterialDefinition::kHasDetail;
            }

            //---------------------------------------------------------------------
            void MaterialWriter::SetShaderType(MaterialDefinition::EShaderType shaderType)
            {
                m_shaderType = shaderType;
            }

            void MaterialWriter::SetSpectreRenderingMode(MaterialDefinition::SpectreRenderingMode mode)
            {
                auto shifted = static_cast<uint32_t>(mode) << 2 * 8;
                m_shaderType |= shifted;
            }

            MaterialDefinition::SpectreRenderingMode MaterialWriter::GetSpectreRenderingMode() const
            {
                auto shifted = static_cast<uint8_t>(m_shaderType >> 2 * 8);
                return static_cast<MaterialDefinition::SpectreRenderingMode>(shifted);
            }

            void MaterialWriter::SetSpectreRenderingOptions(MaterialDefinition::SpectreRenderingOptions options)
            {
                auto mask = 0b11111111'11111111'00000000'00000000;
                auto bitPackedMask = m_shaderType & mask;

                m_shaderType = bitPackedMask + options;
            }

            MaterialDefinition::SpectreRenderingOptions MaterialWriter::GetSpectreRenderingOptions() const
            {
                return static_cast<MaterialDefinition::SpectreRenderingOptions>(m_shaderType);
            }

            void MaterialWriter::AppendSpectreRenderingOption(MaterialDefinition::SpectreRenderingOption options)
            {
                auto shifted = static_cast<uint16_t>(options);
                m_shaderType |= shifted;
            }

            bool MaterialWriter::HasSpectreRenderingOption(MaterialDefinition::SpectreRenderingOption options) const
            {
                auto shifted = static_cast<uint32_t>(m_shaderType);
                auto storedOptions = static_cast<MaterialDefinition::SpectreRenderingOption>(shifted);

                if (options == MaterialDefinition::None)
                {
                    return storedOptions == 0;
                }

                return (storedOptions & options) > 0;
            }


        } // Namespace V1

        SPECTRESDK_API IMaterialWriter* MaterialWriterCreate()
        {
            return new V1::MaterialWriter();
        }

        SPECTRESDK_API void MaterialWriterDestroy(IMaterialWriter*& pWriter)
        {
            if (pWriter == nullptr)
                return;

            delete pWriter;
            pWriter = nullptr;
        }

    }//Namespace Framework

}// Namespace Spectre
