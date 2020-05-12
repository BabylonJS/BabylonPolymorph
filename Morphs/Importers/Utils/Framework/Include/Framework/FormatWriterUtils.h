/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#pragma once

#include <Framework/IBuffer.h>
#include <Framework/Types.h>
#include <Framework/MemoryBuffer.h>
#include <Framework/Frame.h>
#include <Framework/Plugin.h>

#include <CoreUtils/BabylonSDK.h>

#include <cstdint>
#include <memory>

namespace Babylon
{
    namespace Framework
    {
        /**
        * Class to provide functionality common to all writers. Not for external use unless you really want to.
        */
        class CommonFrameWriter
        {
        protected:
            CommonFrameWriter();

            void DoBeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                int itemCount,
                EByteOrder byteOrder,
                EFrameType frameType);

            Frame* DoEndFrame();
            void DoReset();

            inline void SetFrameQualityLevel(EFrameQuality quality)
            {
                m_quality = quality;
            }

        protected:

            /// Add an extension header to a queue to be written later (by calling FlushExtensionHeaders)
            template< typename T >
            inline void AddExtensionHeader(ExtensionHeader::EType type, T extensionType)
            {
                // first header added will be last in chain
                bool lastInChain = m_extensionHeadersBuffers.empty();

                extensionType.Type = uint8_t(type);
                extensionType.OffsetToNextExtensionHeader = m_byteSwapU32(lastInChain ? 0 : sizeof(T));

                auto newBuffer = std::make_shared<MemoryBuffer>();
                newBuffer->WriteDataRaw(&extensionType, sizeof(T));
                m_extensionHeadersBuffers.push_back(newBuffer);
            }

            /// Flush any linked segments to the output buffer
            uint32_t FlushExtensionHeaders();

        protected:
            std::vector<std::shared_ptr<MemoryBuffer>> m_extensionHeadersBuffers;

            std::shared_ptr<IBuffer> m_outputBuffer;
            uint32_t m_frameStartOffset;                // Offset in output buffer where frame started (for frame concatenation)
            uint32_t m_expectedItemCount;               // Number of items we expect to have
            uint32_t m_numItems;
            EFrameQuality m_quality = EFrameQuality::kHigh;

            std::vector<uint32_t> m_savedItemOffsets;
            std::function<uint16_t(uint16_t)> m_byteSwapU16;
            std::function<uint32_t(uint32_t)> m_byteSwapU32;
            std::function<float(float)> m_byteSwapFloat;
        };
    } // End namespace Cool

} // End namespace Babylon
