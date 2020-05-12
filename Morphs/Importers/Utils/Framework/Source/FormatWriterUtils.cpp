/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.        *
*                                                       *
********************************************************/

#include "FrameworkPch.h"

#include <Framework/FormatWriterUtils.h>

#include <functional>
#include <vector>

namespace Babylon
{
    namespace Framework
    {
        //------------------------------------------------------------------------------------------------
        CommonFrameWriter::CommonFrameWriter()
        {
            m_numItems = m_expectedItemCount = 0;
        }

        //------------------------------------------------------------------------------------------------
        void CommonFrameWriter::DoBeginFrame(
            std::shared_ptr<IBuffer> const& outputBuffer,
            int itemCount,
            EByteOrder byteOrder,
            EFrameType frameType)
        {
            if (outputBuffer == nullptr)
            {
                throw Utils::BabylonInvalidArgException("CommonFrameWriter::BeginFrame: No output buffer provided");
            }

            if (m_outputBuffer != nullptr)
            {
                throw Utils::BabylonFailException("CommonFrameWriter::BeginFrame: You must call EndFrame() to close the previous frame, before starting a new frame");
            }

            if (itemCount <= 0)
            {
                throw Utils::BabylonInvalidArgException("CommonFrameWriter::BeginFrame Need at least one item");
            }

            m_numItems = 0;
            m_expectedItemCount = itemCount;

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
            if (byteOrder == kBigEndian)
            {
                m_byteSwapU32 = Endian::ToNetworkU32;
                m_byteSwapU16 = Endian::ToNetworkU16;
                m_byteSwapFloat = [](float arg)
                {
                    uint32_t lArg = Endian::ToNetworkU32(*(uint32_t *)&(arg));
                    return *(float *)&lArg;
                };
            }
            else
            {
                m_byteSwapU32 = [](uint32_t arg) { return arg; };
                m_byteSwapU16 = [](uint16_t arg) { return arg; };
                m_byteSwapFloat = [](float arg) { return arg; };
            }
#elif (__BYTE_ORDER == __BIG_ENDIAN)
            if (byteOrder == Raw::kLittleEndian)
            {
                m_byteSwapU32 = Endian::FromNetworkU32;
                m_byteSwapU16 = Endian::FromNetworkU16;
                m_byteSwapFloat = [](float arg)
                {
                    uint32_t lArg = Endian::FromNetworkU32(*(uint32_t *)&(arg));
                    return *(float *)&lArg;
                };
            }
            else
            {
                m_byteSwapU32 = [](uint32_t arg) { return arg; };
                m_byteSwapU16 = [](uint16_t arg) { return arg; };
                m_byteSwapFloat = [](float arg) { return arg; };
            }
#else
#error Must be Little or Big endian
#endif

            m_outputBuffer = outputBuffer;
            m_frameStartOffset = outputBuffer->GetSizeInBytes();
            m_savedItemOffsets.clear();

            // Write header

            FrameUncompressed hdr;
            memset(&hdr, 0, sizeof(hdr));

            hdr.Marker = m_byteSwapU32(kFrameMarker);
            hdr.Signature = m_byteSwapU32(kFrameSignature);
            hdr.Version = m_byteSwapU32(kFrameVersion1);
            hdr.NumItems = m_byteSwapU16((uint16_t)m_expectedItemCount);

            hdr.Type = (uint8_t)frameType;
            hdr.Compression = (uint8_t)EFrameCompression::kUncompressed;
            hdr.Quality = (uint8_t)m_quality;

            m_outputBuffer->WriteDataRaw(&hdr, sizeof(hdr), 4);
            m_outputBuffer->ReserveSpace(sizeof(uint32_t) * itemCount, 4); // Reserve space for offset table
        }

        uint32_t CommonFrameWriter::FlushExtensionHeaders()
        {
            uint32_t firstExtensionHeaderOffset = 0;
            if (m_extensionHeadersBuffers.size())
            {
                // If we have linked segments, write them out in push_front order (i.e. reversed) to preserve chaining
                firstExtensionHeaderOffset = m_outputBuffer->GetSizeInBytes();
                for (auto it = m_extensionHeadersBuffers.rbegin(); it != m_extensionHeadersBuffers.rend(); it++)
                {
                    m_outputBuffer->WriteDataRaw(it->get()->GetBuffer(), it->get()->GetSizeInBytes(), 4);
                }
                m_extensionHeadersBuffers.clear();
            }
            return firstExtensionHeaderOffset;
        }

        //------------------------------------------------------------------------------------------------
        Frame* CommonFrameWriter::DoEndFrame()
        {
            if (m_outputBuffer == nullptr)
            {
                throw Utils::BabylonFailException("CommonFrameWriter::EndFrame: You must call BeginFrame first");
            }

            if (m_numItems != m_expectedItemCount)
            {
                throw Utils::BabylonFailException("CommonFrameWriter::EndFrame: the number of items added does not match the value specified in BeginFrame()");
            }

            // Forces frames to be four bytes aligned.
            m_outputBuffer->ReserveSpace(0, 4);

            uint32_t totalSize = m_outputBuffer->GetSizeInBytes() - m_frameStartOffset;

            // Patch the offsets...

            FrameUncompressed* pHdr = static_cast<FrameUncompressed*>(m_outputBuffer->GetBuffer(m_frameStartOffset));

            pHdr->SizeInBytes = m_byteSwapU32(totalSize);
            pHdr->Quality = (uint8_t)m_quality; // Update quality, in case it has changed....

            for (uint32_t i = 0; i < m_savedItemOffsets.size(); ++i)
            {
                uint32_t offset = m_savedItemOffsets[i] - m_frameStartOffset;

                BabylonAssertExpr(offset != 0, "CommonFrameWriter::EndFrame - Offset for item is 0! It cannot be 0");
                pHdr->Offsets[i] = m_byteSwapU32(offset);
            }

            // Free resources
            m_savedItemOffsets.clear();

            return pHdr;
        }

        //------------------------------------------------------------------------------------------------
        void CommonFrameWriter::DoReset()
        {
            m_expectedItemCount = 0;
            m_savedItemOffsets.clear();
            m_extensionHeadersBuffers.clear();
            m_outputBuffer = nullptr;
        }

    }//Namespace Framework

}// Namespace Babylon
