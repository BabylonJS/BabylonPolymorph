/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Enums.h>
#include <Framework/Types.h>
#include <CoreUtils/Assert.h>

namespace Spectre
{
    namespace Framework
    {

        /**
         * Represents the Material definition in the Common Object Format's in-memory representation.
         * This is a raw binary representation.
         */
        struct MaterialDefinition
        {
            enum SpectreRenderingMode : uint8_t
            {
                Default             = 0,        // Mode is unspecified: runtime can choose rendering mode based on texture flags, etc.

                Opaque              = 1,        // Opaque. Occludes everything behind it.

                Mask                = 2,        // OpaqueMask. Alpha value used to determine whether samples are opaque (present) or invisible (absent).
                Blend               = 3,        // TransparentBlend. Standard "alpha blend" mode.
                MaskBlend           = 4,        // Beihai "combined mask and blend" mode.
                Add                 = 5,        // Reserved for future use
                Multiply            = 6,        // Reserved for future use
            };

            using SpectreRenderingOptions = uint16_t;

            enum SpectreRenderingOption : SpectreRenderingOptions
            {
                None                    = 0b00000000'00000000,

                WorkflowMetalness       = 0b00000000'00000001,      // Denotes MetallicRoughness PBR workflow
                WorkflowSpecGloss       = 0b00000000'00000010,      // Denotes SpecularGlossiness PBR workflow
                WorkflowReserved        = 0b00000000'00000100,
                MicrosurfaceRoughness   = 0b00000000'00001000,      // Reserved for future use -- if enabled then the microsurface uses a roughness map; otherwise it uses a gloss (smoothness) map.
                GLTFMaterial            = 0b00000000'00010000,      // This is a GLTF material
                GLTFNonCompliant        = 0b00000000'00100000,      // This is a legacy GLTF material that needs to be transformed to be compliant
                SingleSided             = 0b00000000'01000000,      // This material is singlesided (if not set the material is assumed to be doublesided)
                Unlit                   = 0b00000000'10000000,      // This material should be rendered with an unlit shader
                GLTFNonCompliantNormals = 0b00100000'00000000,      // This is a material which uses legacy normal direction (opposite to GLTF spec)
                BlendOpaqueDepthWrite   = 0b01000000'00000000,      // Experimental -- used with the 'Blend' rendering mode, enables depth buffer write for 100% opaque pixels via separate render pass
                OpacityFresnel          = 0b10000000'00000000,      // Experimental
            };

            enum EVersion
            {
                kVersion0 = 0x10003000
            };

            enum EFormat
            {
                kHasDiffuse = 0x00000001,
                kHasSpecular = 0x00000002,
                kHasNormal = 0x00000004,
                kHasDepth = 0x00000008,
                kHasEmissive = 0x00000010,
                kHasOcclusion = 0x00000020,
                kHasDetail = 0x00000040
            };

            uint32_t Version;

            uint32_t FormatMask;
            uint32_t MaterialID;
            uint32_t NumSamplers;

            uint32_t DiffuseColour;
            uint32_t DiffuseMap;
            uint32_t DiffuseSamplerOffset;

            uint32_t SpecularColour;
            uint32_t SpecularMap;
            uint32_t SpecularSamplerOffset;

            uint32_t EmissiveColour;
            float    EmissiveIntensity;
            uint32_t EmissiveMap;
            uint32_t EmissiveSamplerOffset;

            uint32_t NormalMap;
            uint32_t NormalSamplerOffset;

            uint32_t DepthMap;
            uint32_t DepthSamplerOffset;

            uint32_t OcclusionMap;
            uint32_t OcclusionSamplerOffset;

            uint32_t DetailMap;
            uint32_t DetailSamplerOffset;

            // Deprecated
            enum EShaderType
            {
                kStandardShader = 0x00000001,
                kGlassShader = 0x00000002,
                kHairShader = 0x00000004
            };

            /// Layout:
            /// (MSB) xxxxxxxx mmmmmmmm oooooooo oooooooo (LSB)
            /// o = options
            /// m = mode
            /// x = unused
            uint32_t ShaderType;

            void SetSpectreRenderingMode(SpectreRenderingMode mode)
            {
                SetSpectreRenderingMode(ShaderType, mode);
            }

            void AppendSpectreRenderingOption(SpectreRenderingOption option)
            {
                AppendSpectreRenderingOption(ShaderType, option);
            }

            void SetSpectreRenderingOptions(SpectreRenderingOptions options)
            {
                auto mask = 0b11111111'11111111'00000000'00000000;
                auto bitPackedMask = ShaderType & mask;

                ShaderType = bitPackedMask | static_cast<uint32_t>(options);
            }

            SpectreRenderingMode GetSpectreRenderingMode() const
            {
                return GetSpectreRenderingMode(ShaderType);
            }

            SpectreRenderingOptions GetSpectreRenderingOptions() const
            {
                return static_cast<SpectreRenderingOptions>(ShaderType & 0b00000000'00000000'11111111'11111111);
            }

            bool HasSpectreRenderingOption(SpectreRenderingOption option) const
            {
                return TestSpectreRenderingOption(ShaderType, option);
            }

            static void AppendSpectreRenderingOption(uint32_t& shaderType, SpectreRenderingOption option)
            {
                shaderType |= static_cast<uint32_t>(option);
            }

            static void SetSpectreRenderingMode(uint32_t& shaderType, SpectreRenderingMode mode)
            {
                auto shifted = static_cast<uint32_t>(mode) << 2 * 8;
                shaderType &= 0b00000000'00000000'11111111'11111111;        // Remove old rendering mode
                shaderType |= shifted;
            }

            static bool TestSpectreRenderingOption(uint32_t shaderType, SpectreRenderingOption option)
            {
                return (GetSpectreRenderingOptions(shaderType) & option) == option;
            }

            static SpectreRenderingMode GetSpectreRenderingMode(uint32_t shaderType)
            {
                auto shifted = static_cast<uint8_t>(shaderType >> 2 * 8);
                return static_cast<SpectreRenderingMode>(shifted);
            }

            static SpectreRenderingOptions GetSpectreRenderingOptions(uint32_t shaderType)
            {
                return static_cast<SpectreRenderingOptions>(shaderType);            // Just return the lower 16 bits
            }

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

        struct SamplerDefinition
        {
            using EFilterMode = Spectre::Framework::FilterMode;
            using EAddressMode = Spectre::Framework::AddressMode;

            EFilterMode FilterMode;
            EAddressMode UAddress;
            EAddressMode VAddress;
            EAddressMode WAddress;
            uint32_t BorderColour;
            float UOffset;
            float VOffset;
            float UTiling;
            float VTiling;

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

        //////////////////////////////////////////////////////////////////////////

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
#define MATERIAL_GET_API(_name) inline const SamplerDefinition* Get ## _name ## SamplerData() const\
        {\
        if ((Endian::FromNetworkU32(FormatMask) & kHas ## _name) == 0)\
            {\
                return nullptr;\
            }\
            return reinterpret_cast<SamplerDefinition const*>(Base() + Endian::FromNetworkU32(_name ## SamplerOffset));\
        }\
        inline uint32_t Get ## _name ## Texture() const { return Endian::FromNetworkU32(_name ## Map); }

        struct MaterialSegmentBigEndian : MaterialDefinition
        {
            // Helper methods
            inline bool IsValid() const { return Endian::FromNetworkU32(Version) == kVersion0; }
            inline uint32_t GetFormat() const { return Endian::FromNetworkU32(FormatMask); }
            inline uint32_t GetMaterialID() const { return Endian::FromNetworkU32(MaterialID); }
            inline uint32_t GetShaderType() const { return Endian::FromNetworkU32(ShaderType); }

            inline uint32_t GetDiffuseColour() const { return Endian::FromNetworkU32(DiffuseColour); }
            inline uint32_t GetSpecularColour() const { return Endian::FromNetworkU32(SpecularColour); }
            inline uint32_t GetEmissiveColour() const { return Endian::FromNetworkU32(EmissiveColour); }

            MATERIAL_GET_API(Diffuse);
            MATERIAL_GET_API(Specular);
            MATERIAL_GET_API(Emissive);
            MATERIAL_GET_API(Normal);
            MATERIAL_GET_API(Depth);
            MATERIAL_GET_API(Occlusion);
            MATERIAL_GET_API(Detail);
        };
#undef MATERIAL_GET_API


#define MATERIAL_GET_API(_name) inline const SamplerDefinition* Get ## _name ## SamplerData() const\
        {\
        if ((FormatMask & kHas ## _name) == 0)\
        {\
        return nullptr; \
        }\
        return reinterpret_cast<SamplerDefinition const*>(Base() + _name ## SamplerOffset); \
        }\
        inline uint32_t Get ## _name ## Texture() const { return _name ## Map; }

        struct MaterialSegmentLittleEndian : MaterialDefinition
        {
            // Helper methods
            inline bool IsValid() const { return Version == kVersion0; }
            inline uint32_t GetFormat() const { return FormatMask; }
            inline uint32_t GetMaterialID() const { return MaterialID; }

            inline uint32_t GetDiffuseColour() const { return DiffuseColour; }
            inline uint32_t GetSpecularColour() const { return SpecularColour; }
            inline uint32_t GetEmissiveColour() const { return EmissiveColour; }

            MATERIAL_GET_API(Diffuse);
            MATERIAL_GET_API(Specular);
            MATERIAL_GET_API(Emissive);
            MATERIAL_GET_API(Normal);
            MATERIAL_GET_API(Depth);
            MATERIAL_GET_API(Occlusion);
            MATERIAL_GET_API(Detail);
        };
#undef MATERIAL_GET_API


#else
#endif

    } // End namespace Framework

} // End namespace Spectre
