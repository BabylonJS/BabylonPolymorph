/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>

namespace Babylon
{
    namespace Framework
    {
        namespace Endian
        {
            inline uint32_t ToNetworkU32(uint32_t v)
            {
                uint32_t a = v & 0xFF;
                uint32_t b = (v >> 8) & 0xFF;
                uint32_t c = (v >> 16) & 0xFF;
                uint32_t d = (v >> 24) & 0xFF;
                return (a << 24) | (b << 16) | (c << 8) | d;
            }

            inline uint16_t ToNetworkU16(uint16_t v)
            {
                uint16_t a = v & 0xFF;
                uint16_t b = (v >> 8) & 0xFF;
                return (a << 8) | b;
            }

            inline uint8_t ToNetworkU8(uint8_t v)
            {
                return v;
            }

            inline uint32_t FromNetworkU32(uint32_t v)
            {
                return ToNetworkU32(v);
            }

            inline uint16_t FromNetworkU16(uint16_t v)
            {
                return ToNetworkU16(v);
            }

            inline uint8_t FromNetworkU8(uint8_t v)
            {
                return v;
            }

        } // namespace Endian

    } // namespace Framework

} // namespace Babylon
