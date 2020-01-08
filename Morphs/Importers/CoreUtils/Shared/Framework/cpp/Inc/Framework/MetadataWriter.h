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
         * Use the IMetadataWriter to help you serialize out metadata about an object
         */
        class SPECTRESDK_API IMetadataWriter
        {

        public:
            virtual ~IMetadataWriter() {}

            virtual void BeginFrame(
                std::shared_ptr<IBuffer> const& outputBuffer,
                uint32_t numItems,
                EByteOrder byteOrder) = 0;

            virtual Frame* EndFrame() = 0;

            virtual void BeginMetadata(uint32_t id, const char* name) = 0;
            virtual void EndMetadata() = 0;

            virtual uint32_t GetVersion() const = 0;
        };

        SPECTRESDK_API IMetadataWriter* MetadataWriterCreate();
        SPECTRESDK_API void MetadataWriterDestroy(IMetadataWriter*& pWriter);

    } // End namespace Cool

} // End namespace Spectre
