/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <CoreUtils/Assert.h>
#include <CoreUtils/SpectreSal.h>

namespace Spectre
{
    namespace Framework
    {

        class IBuffer
        {
        public:
            virtual ~IBuffer() {}

            /**
             * Return a pointer to the raw buffer. Caller can optionally specify an offset from the
             * start of the buffer to access. If 0 is specified (the default) then the entire buffer is
             * returned.
             */
            virtual void* GetBuffer(uint32_t atOffset = 0) = 0;

            /**
             * Write raw data into the buffer with the specified alignment.
             * The method will return the offset in bytes from the start of the buffer, where the data
             * was written
             */
            virtual uint32_t WriteDataRaw(_In_reads_(sizeInBytes) const void* data, uint32_t sizeInBytes, uint32_t align) = 0;

            /**
             * Reserve a contiguous section of the buffer large enough to fit the specified number of bytes.
             * The method return the OFFSET in the buffer where the reservation starts from
             */
            virtual uint32_t ReserveSpace(uint32_t sizeInBytes, uint32_t align) = 0;

            /**
            * Trim the specified number of bytes from the end of the buffer. This has the effect of shrinking the buffer.
            */
            virtual void TrimBytes(uint32_t numBytes) = 0;

            /**
             * Return the offset in the buffer of the specified header
             */
            virtual uint32_t OffsetOf(const void* ptr) const = 0;

            /**
             * Return the total size of the buffer in bytes
             */
            virtual uint32_t GetSizeInBytes() const = 0;
        };

        class NullBuffer : public IBuffer
        {
        public:
            virtual ~NullBuffer() {}

            virtual void* GetBuffer(uint32_t atOffset = 0)
            {
                SpectreUnusedParameter(atOffset);
                return nullptr;
            }

            virtual uint32_t WriteDataRaw(_In_reads_(sizeInBytes) const void* data, uint32_t sizeInBytes, uint32_t align)
            {
                SpectreUnusedParameter(data);
                SpectreUnusedParameter(sizeInBytes);
                SpectreUnusedParameter(align);
                return 0;
            }

            virtual uint32_t ReserveSpace(uint32_t sizeInBytes, uint32_t align)
            {
                SpectreUnusedParameter(sizeInBytes);
                SpectreUnusedParameter(align);
                return 0;
            }

            virtual void TrimBytes(uint32_t numBytes)
            {
                SpectreUnusedParameter(numBytes);
            }

            virtual uint32_t OffsetOf(const void* ptr) const
            {
                SpectreUnusedParameter(ptr);
                return 0;
            }

            virtual uint32_t GetSizeInBytes() const
            {
                return 0;
            }
        };

    } // End namespace Framework

} // End namespace Spectre
