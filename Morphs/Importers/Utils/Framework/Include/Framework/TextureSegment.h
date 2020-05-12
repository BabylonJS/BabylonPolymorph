/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Endian.h>
#include <Framework/Types.h>

namespace Babylon
{
    namespace Framework
    {

        /**
         * Represents a Texture (either wholly or in part) in the Common Object
         * Format's in-memory representation. This is a raw binary representation.
         */
        struct TextureSegment
        {
            enum EVersion
            {
                kVersion0 = 0x10002000
            };

            enum EFormat : int32_t
            {
                kFormatBGRA32 = 0,
                kBC3_UNORM = 1,
                kBC5_UNORM = 2,
                kBC7_UNORM = 3,
                kPNG = 4,
                kPNG256 = 5,
                kJPEG = 6,
                kFormatCount,
                kUnknown = static_cast<int32_t>(0xffffffff)
            };

            enum ELod
            {
                kLodLowDetail = 0,
                kLodMediumDetail = 1,
                kLodFullDetail = 2,
            };

            enum EFlag : uint8_t
            {
                kFlag_AlphaValid = 0x01,
                kFlag_TextureHasActiveAlpha = 0x02
            };

            uint32_t Version;           /**< Version of format (for future extensibility). */

            uint8_t  Flags;             /** EFlag */
            uint8_t  Reserved0;
            uint8_t  Reserved1;
            uint8_t  Reserved2;

            uint32_t TextureID;         /**< ID of the texture */
            uint32_t SizeInBytes;       /**< The full size of the TextureSegment in bytes */

            uint8_t  Format;            /**< What format is the texture stored in */
            uint8_t  Padding0[3];

            uint16_t WithInPixels;
            uint16_t HeightInPixels;
            uint16_t DepthInPixels;

            uint8_t PixelStrideInBytes;
            uint8_t Padding1;

            uint32_t LineStrideInBytes;

            uint32_t OffsetData;        /**< Offset in bytes from start of buffer to the texture data */

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

        //////////////////////////////////////////////////////////////////////////

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
        struct TextureSegmentBigEndian : TextureSegment
        {
            // Helper methods

            inline bool IsValid() const
            {
                return Endian::FromNetworkU32(Version) == kVersion0 && OffsetData != 0;
            }

            inline EFormat GetFormat() const
            {
                return (EFormat)Endian::FromNetworkU32(Format);
            }

            inline uint32_t GetTextureID() const
            {
                return Endian::FromNetworkU32(TextureID);
            }

            inline uint32_t GetPixelStride() const
            {
                return PixelStrideInBytes;
            }

            inline uint32_t GetLineStride() const
            {
                return Endian::FromNetworkU32(LineStrideInBytes);
            }

            inline uint32_t GetWidthInPixels() const
            {
                return Endian::FromNetworkU16(WithInPixels);
            }

            inline uint32_t GetHeightInPixels() const
            {
                return Endian::FromNetworkU16(HeightInPixels);
            }

            inline uint32_t GetDepthInPixels() const
            {
                return Endian::FromNetworkU16(DepthInPixels);
            }

            inline const void* GetData() const
            {
                return Base() + Endian::FromNetworkU32(OffsetData);
            }
        };


        struct TextureSegmentLittleEndian : TextureSegment
        {
            // Helper methods

            inline bool IsValid() const
            {
                return Version == kVersion0 && OffsetData != 0;
            }

            inline EFormat GetFormat() const
            {
                return (EFormat)Format;
            }

            inline uint32_t GetTextureID() const
            {
                return TextureID;
            }

            inline uint32_t GetPixelStride() const
            {
                return PixelStrideInBytes;
            }

            inline uint32_t GetLineStride() const
            {
                return LineStrideInBytes;
            }

            inline uint32_t GetWidthInPixels() const
            {
                return WithInPixels;
            }

            inline uint32_t GetHeightInPixels() const
            {
                return HeightInPixels;
            }

            inline uint32_t GetDepthInPixels() const
            {
                return DepthInPixels;
            }

            inline const void* GetData() const
            {
                return Base() + OffsetData;
            }
        };
#else
#error Need to Implement for Little Endian
#endif

    } // End namespace Framework
} // End namespace Babylon
