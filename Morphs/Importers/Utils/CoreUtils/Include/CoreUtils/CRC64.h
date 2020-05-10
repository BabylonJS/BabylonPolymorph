/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <stdint.h>

namespace Babylon
{
    namespace Utils
    {
        namespace CRC64
        {
            enum class Checksum : uint64_t;

            extern const uint64_t k_CRC64Table[256];

            Checksum HashByte(Checksum crc, uint8_t byte);

            Checksum HashBytes(Checksum crc, const uint8_t* pData, size_t dataSize);

            Checksum Hash2Bytes(Checksum crc, uint16_t bytes);

            Checksum Hash4Bytes(Checksum crc, uint32_t bytes);
        };
    } // namespace Utils
} // namespace Babylon
