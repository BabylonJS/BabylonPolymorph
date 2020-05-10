/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Enums.h>
#include <Framework/Frame.h>
#include <Framework/MemoryBuffer.h>
#include <Framework/Types.h>
#include <Framework/FormatWriterUtils.h>
#include <Framework/Plugin.h>

#include <CoreUtils/BabylonSDK.h>

#include <cstdint>
#include <memory>

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

namespace Babylon
{
    namespace Framework
    {

        enum class ImageReader
        {
            UNKNOWN,
            DDS,
            TGA,
            WIC,
            PSD,
        };

        enum class TextureLOD : uint8_t
        {
            // Only generate texture for original size (or up to MaxDimension, whichever is smaller)
            kOriginalOnly = 1,

            // Generate 2 levels of LODs - usually: actualSize, 1024
            k2Level = 2,

            // Generate 3 levels of LODs - usually: actualSize, 1024, 128
            k3Level = 3,

            kMaxMips = 3
        };

        // Helper function, to convert LOD ID to number of mips that need to be generated
        inline int TextureLODToNumMips(TextureLOD lod)
        {
            return static_cast<int>(lod);
        }

        // Structure specifying options for when images are being processed.
        struct TextureProcessingOptions
        {
            // Type of reader to use - ie. what format is source data in
            ImageReader Reader = ImageReader::DDS;

            // Texture compression to apply to the texture
            int         TextureCompression = TextureCompressionType::None;

            // Maximum dimension for the texture (any axis)
            int         MaxDimension = 4096;

            // The LOD processing to perform
            TextureLOD  LOD = TextureLOD::kOriginalOnly;

            // The type of Material Layer to which the texture is associated
            TextureMaterialLayer LayerType = TextureMaterialLayer::kDiffuse;

            // Scale Factor to be applied to texture
            // e.g. bump factor, make a surface more or less bumpy.
            float ScaleFactor = 1.0f;
        };

        class BABYLON_SDK_API ITextureWriter;

        typedef std::function<void BABYLON_SDK_CALL (
            const std::string&              textureName,
            const std::string&              texturePath,
            uint32_t                        textureId,
            void*                           data,
            uint32_t                        sizeInBytes,
            std::vector<ITextureWriter*>&   writers,
            const TextureProcessingOptions& options
            )> EncodeBGRAFunc;

        typedef std::function<void BABYLON_SDK_CALL (
            uint32_t                        textureId,
            uint32_t                        width,
            uint32_t                        height,
            uint32_t                        lineStride,
            TextureSegment::EFormat         format,
            uint8_t                         flags,
            void*                           data,
            uint32_t                        sizeInBytes,
            std::vector<ITextureWriter*>&   writers,
            const TextureProcessingOptions& options
            )> EncodeRAWBGRAFunc;

        /**
         * Use the TextureWriter to help you serialize out texture data in your
         * desired format
         */
        class BABYLON_SDK_API ITextureWriter
        {
        public:
            virtual ~ITextureWriter() {}

            virtual void BeginFrame(
                std::shared_ptr<IBuffer> const&     outputBuffer,
                uint32_t                            numTextures,
                EByteOrder                          byteOrder,
                EFrameQuality                       quality = EFrameQuality::kHigh) = 0;

            virtual Frame* EndFrame() = 0;

            virtual void* AddTextureRAW(
                uint32_t    textureId,
                uint32_t    width,
                uint32_t    height,
                uint32_t    pixelStride,
                uint32_t    lineStride,
                uint8_t     flags) = 0;

            virtual void* AddTextureEncoded(
                uint32_t                textureId,
                uint32_t                width,
                uint32_t                height,
                uint32_t                pixelStride,
                uint32_t                lineStride,
                uint32_t                size,
                TextureSegment::EFormat format,
                uint8_t                 flags) = 0;

            virtual void AddTexture(
                const std::string&  textureName,
                const std::string&  texturePath,
                uint32_t            textureId,
                ImageReader         reader,
                void*               encodedData,
                uint32_t            encodedDataSizeInBytes,
                int                 textureCompression,
                uint32_t            lod) = 0;

            virtual uint32_t GetVersion() const = 0;
        };

        BABYLON_SDK_API ITextureWriter* TextureWriterCreate(EncodeBGRAFunc encodeFunc);
        BABYLON_SDK_API void TextureWriterDestroy(ITextureWriter*& pWriter);

    } // End namespace Framework

} // End namespace Babylon
