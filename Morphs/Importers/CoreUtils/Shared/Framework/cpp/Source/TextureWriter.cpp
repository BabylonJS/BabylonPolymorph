/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.        *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/TextureWriter.h>

#include <functional>
#include <string>

#include <Framework/TextureSegment.h>
#include <Framework/Types.h>
#include <Framework/FormatWriterUtils.h>

namespace Spectre
{
    namespace Framework
    {
        namespace V1
        {

            class TextureWriter : public ITextureWriter, public CommonFrameWriter
            {
            private:
                static const uint32_t sVERSION = 1;

            public:
                TextureWriter(EncodeBGRAFunc encodeFunc);
                virtual ~TextureWriter();

                virtual void BeginFrame(
                    std::shared_ptr<IBuffer> const& outputBuffer,
                    uint32_t numTextures,
                    EByteOrder byteOrder,
                    EFrameQuality quality) override;

                virtual Frame* EndFrame() override;

                virtual void* AddTextureRAW(
                    uint32_t textureId,
                    uint32_t width,
                    uint32_t height,
                    uint32_t pixelStride,
                    uint32_t lineStride,
                    uint8_t flags) override;

                virtual void* AddTextureEncoded(
                    uint32_t textureId,
                    uint32_t width,
                    uint32_t height,
                    uint32_t pixelStride,
                    uint32_t lineStride,
                    uint32_t size,
                    TextureSegment::EFormat format,
                    uint8_t flags) override;

                virtual void AddTexture(
                    const std::string&  textureName,
                    const std::string&  texturePath,
                    uint32_t            textureId,
                    ImageReader         reader,
                    void*               encodedData,
                    uint32_t            encodedDataSizeInBytes,
                    int                 textureCompression,
                    uint32_t            lod) override;

                virtual uint32_t GetVersion() const override
                {
                    return sVERSION;
                }

            protected:

                EncodeBGRAFunc m_encodeFunc;
            };

            //---------------------------------------------------------------------
            TextureWriter::TextureWriter(EncodeBGRAFunc encodeFunc) :
                m_encodeFunc(encodeFunc)
            {
            }

            //---------------------------------------------------------------------
            TextureWriter::~TextureWriter()
            {
            }

            //---------------------------------------------------------------------
            void TextureWriter::BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numTextures,
                EByteOrder byteOrder,
                EFrameQuality quality)
            {
                this->DoReset();
                this->SetFrameQualityLevel(quality);
                this->DoBeginFrame(outputBuffer, numTextures, byteOrder, kFrameTexture);
            }

            //---------------------------------------------------------------------
            Frame* TextureWriter::EndFrame()
            {
                return this->DoEndFrame();
            }

            //---------------------------------------------------------------------
            void* TextureWriter::AddTextureRAW(
                uint32_t textureId,
                uint32_t width,
                uint32_t height,
                uint32_t pixelStride,
                uint32_t lineStride,
                uint8_t flags)
            {
                if (width >= 65535)
                {
                    throw Utils::SpectreInvalidArgException("Width cannot be greater than 65535");
                }
                if (height >= 65535)
                {
                    throw Utils::SpectreInvalidArgException("Height cannot be greater than 65535");
                }
                if (pixelStride >= 255)
                {
                    throw Utils::SpectreInvalidArgException("PixelStride must be less then 255");
                }

                // Write the header...

                uint32_t totalSizeInBytes = sizeof(TextureSegment) + lineStride * height;

                uint32_t offset = m_outputBuffer->ReserveSpace(totalSizeInBytes, 4);
                m_savedItemOffsets.push_back(offset);
                ++m_numItems;

                TextureSegment* pHdr =
                    reinterpret_cast<TextureSegment*>(m_outputBuffer->GetBuffer(offset));

                pHdr->Version = m_byteSwapU32(TextureSegment::kVersion0);
                pHdr->Flags = flags;
                pHdr->TextureID = m_byteSwapU32(textureId);
                pHdr->SizeInBytes = m_byteSwapU32(totalSizeInBytes);
                pHdr->DepthInPixels = m_byteSwapU16(0);
                pHdr->HeightInPixels = m_byteSwapU16(static_cast<uint16_t>(height));
                pHdr->WithInPixels = m_byteSwapU16(static_cast<uint16_t>(width));
                pHdr->PixelStrideInBytes = static_cast<uint8_t>(pixelStride);
                pHdr->LineStrideInBytes = m_byteSwapU16(static_cast<uint16_t>(lineStride));
                pHdr->Format = TextureSegment::kFormatBGRA32;

                uint32_t dataOffset = offset + sizeof(TextureSegment);
                pHdr->OffsetData = m_byteSwapU32(sizeof(TextureSegment));

                return m_outputBuffer->GetBuffer(dataOffset);
            }

            //---------------------------------------------------------------------

            void* TextureWriter::AddTextureEncoded(
                uint32_t textureId,
                uint32_t width,
                uint32_t height,
                uint32_t pixelStride,
                uint32_t lineStride,
                uint32_t size,
                TextureSegment::EFormat format,
                uint8_t flags)
            {
                if (width > 0xffff)
                {
                    throw Utils::SpectreInvalidArgException("Width must be less than 65536");
                }
                if (height > 0xffff)
                {
                    throw Utils::SpectreInvalidArgException("Height must be less than 65536");
                }
                if (pixelStride > 255)
                {
                    throw Utils::SpectreInvalidArgException("PixelStride must be less than 256");
                }
                // Write the header...

                uint32_t totalSizeInBytes = sizeof(TextureSegment) + size;

                uint32_t offset = m_outputBuffer->ReserveSpace(totalSizeInBytes, 4);
                m_savedItemOffsets.push_back(offset);
                ++m_numItems;

                TextureSegment* pHdr =
                    reinterpret_cast<TextureSegment*>(m_outputBuffer->GetBuffer(offset));

                pHdr->Version = m_byteSwapU32(TextureSegment::kVersion0);
                pHdr->Flags = flags;
                pHdr->TextureID = m_byteSwapU32(textureId);
                pHdr->SizeInBytes = m_byteSwapU32(totalSizeInBytes);
                pHdr->DepthInPixels = m_byteSwapU16(0);
                pHdr->HeightInPixels = m_byteSwapU16(static_cast<uint16_t>(height));
                pHdr->WithInPixels = m_byteSwapU16(static_cast<uint16_t>(width));
                pHdr->PixelStrideInBytes = static_cast<uint8_t>(pixelStride);
                pHdr->LineStrideInBytes = m_byteSwapU16(static_cast<uint16_t>(lineStride));
                pHdr->Format = static_cast<uint8_t>(format);

                uint32_t dataOffset = offset + sizeof(TextureSegment);
                pHdr->OffsetData = m_byteSwapU32(sizeof(TextureSegment));

                return m_outputBuffer->GetBuffer(dataOffset);
            }

            //---------------------------------------------------------------------

            void TextureWriter::AddTexture(
                const std::string&  textureName,
                const std::string&  texturePath,
                uint32_t            textureId,
                ImageReader         reader,
                void*               encodedData,
                uint32_t            encodedDataSizeInBytes,
                int                 textureCompression,
                uint32_t            lod)
            {
                TextureProcessingOptions options;
                options.TextureCompression = textureCompression;
                options.Reader = reader;
                switch (lod)
                {
                    case 0:
                        options.LOD = TextureLOD::kOriginalOnly;
                        break;
                    case 1:
                        options.LOD = TextureLOD::k2Level;
                        break;
                    case 2:
                        options.LOD = TextureLOD::k3Level;
                        break;
                    default:
                        options.LOD = TextureLOD::kOriginalOnly;
                }

                // :TODO: This method needs to change to process multiple LODs in parallel

                std::vector<ITextureWriter*> writers;
                writers.push_back(this);
                m_encodeFunc(
                    textureName,
                    texturePath,
                    textureId,
                    encodedData,
                    encodedDataSizeInBytes,
                    writers,
                    options);
            }

        } // End V1 namespace

        SPECTRESDK_API ITextureWriter* TextureWriterCreate(EncodeBGRAFunc encodeFunc)
        {
            return new V1::TextureWriter(encodeFunc);
        }

        SPECTRESDK_API void TextureWriterDestroy(ITextureWriter*& pWriter)
        {
            if (pWriter == nullptr)
                return;

            delete pWriter;
            pWriter = nullptr;
        }

    } // Namespace Framework

} // Namespace Spectre
