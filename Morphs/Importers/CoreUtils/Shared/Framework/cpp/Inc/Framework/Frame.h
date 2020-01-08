/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Endian.h>
#include <Framework/Types.h>
#include <CoreUtils/Assert.h>
#include <CoreUtils/SmartThrow.h>

namespace Spectre
{
    namespace Framework
    {
        enum EFrameType : uint8_t
        {
            kFrameUnknown = 0,
            kFrameGeom = 1,
            kFrameAnim = 2,
            kFrameTexture = 3,
            kFrameMaterial = 4,
            kFrameMetadata = 5,
            kFrameScene = 6,
        };

        /**
         * Allows the caller to request a particular endian' for the data
         */
        enum EByteOrder
        {
            kBigEndian = 0,         /**< ABCD - Same as Network Byte Order */
            kLittleEndian = 1,      /**< DCBA - Ie. x86 CPUs */
        };

        enum
        {
            kFrameMarker = 0x434F4F4C,          /**< 'COOL' */
            kFrameSignature = 0x4C004654,       /**< L_FT */

            // The frame version is comprised of Major.Minor. Upper 16 bits are major, lower 16 bits are minor.
            // Newer versions MUST be > then all older versions.

            kFrameVersion1 = 0x10010000         /**< Frame quality, detail */
        };

        /*
        * Valid types of compression for the frame data
        * See: https://msdn.microsoft.com/en-us/library/windows/desktop/hh920921(v=vs.85).aspx
        */
        enum class EFrameCompression
        {
            kUncompressed = 0x0,        /**< Uncompressed data */
            kXPRESS_HUFF = 0x1,         /**< Compress using XPRESS-HUFF. Fast compression/decompression, low resources, low ratio*/
            kLZMS = 0x2,                /**< Compress using LZMS, Slow compression, medium resources, high ratio*/
        };

        /*
        * Quality level of the frame. Cool streams support simplified data (LODs), and this is indicated by
        * quality levels. A low quality frame, contains approximate, or simplified data.
        */
        enum class EFrameQuality : uint8_t
        {
            kLow = 0x0,
            kMedium = 0x1,
            kHigh = 0x2
        };

        /**
        * Represents an in-memory frame.
        * Frames can be compressed or uncompressed.
        * If a frame is uncompressed, FrameUncompressed defines the layout.
        * If a frame is compressed, FrameCompressed defines the layout. The data must first be uncompressed before accessing
        */
        struct Frame
        {
            uint32_t    Marker;         /**< Unique frame marker indicating start of a frame */
            uint32_t    Signature;      /**< 2nd Unique frame marker indicating start of a frame */
            uint32_t    Version;        /**< Frame version number */

            uint8_t     Compression;    /**< Compression algorithm used for frame */
            uint8_t     Type;           /**< Type of frame (see EFrameType) */
            uint8_t     Quality;        /**< Quality level of the data in this frame. See EFrameQuality */
            uint8_t     Reserved;

            uint32_t    Reserved2;

            uint8_t     GUID[16];       /**< Global Unique ID of the data contained in this frame */
            uint32_t    SizeInBytes;    /**< Total size in bytes of frame, including frame header. Allows skipping the whole frame */
        };

        /*
        * Compressed frame definition.
        */
        struct FrameCompressed : Frame
        {
            uint32_t    UncompressedSizeInBytes; /**< Size in bytes of the uncompressed frame */
            uint32_t    CompressedData[1];
        };

        /*
        * Uncompressed frame definition
        */
        struct FrameUncompressed : Frame
        {
            uint16_t                Reserved1;
            uint16_t                NumItems;       /**< Number of 'items' in the frame */
            uint32_t                Offsets[1];     /**< Offset array to the 'items' (uint32 * numItems). This is offset from the start of the frame. */
        };

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
        struct FrameBigEndian : FrameUncompressed
        {
            template<typename T>
            inline const T* GetItemByIndex(uint32_t idx) const
            {
                if (idx >= GetNumItems())
                {
                    throw Spectre::Utils::SpectreException("Frame::GetItemByIndex - Invalid index specified.");
                }

                uint32_t offset = Endian::FromNetworkU32(Offsets[idx]);

                // Check that we would not return a ptr to an object that lies outside the bounds
                // of the frame in memory. This doesn't check whether the memory at the specified
                // offset is a valid object of type T, but it's still a useful check for an incorrect frame.
                if (offset + sizeof(T) > GetSizeInBytes())
                {
                    throw Spectre::Utils::SpectreException("Frame::GetItemByIndex - Object outside bounds of frame. Bad data.");
                }

                return reinterpret_cast<const T*>(reinterpret_cast<const char*>(this) + offset);
            }

            inline uint32_t GetNumItems() const
            {
                return Endian::FromNetworkU16(NumItems);
            }

            inline uint32_t GetSizeInBytes() const
            {
                return Endian::FromNetworkU32(SizeInBytes);
            }

            inline uint32_t GetType() const
            {
                return Type;
            }

            inline EFrameQuality GetQuality() const
            {
                return (EFrameQuality)Quality;
            }

            inline EFrameCompression GetCompression() const
            {
                return (EFrameCompression)Compression;
            }

            inline uint32_t GetVersion() const
            {
                return Endian::FromNetworkU32(Version);
            }

        };

        struct FrameLittleEndian : FrameUncompressed
        {
            template<typename T>
            inline const T* GetItemByIndex(uint32_t idx) const
            {
                if (idx >= GetNumItems())
                {
                    throw Utils::SpectreException("Frame::GetItemByIndex - Invalid index specified.");
                }

                uint32_t offset = Offsets[idx];

                // Check that we would not return a ptr to an object that lies outside the bounds
                // of the frame in memory. This doesn't check whether the memory at the specified
                // offset is a valid object of type T, but it's still a useful check for an incorrect frame.
                if (offset + sizeof(T) > GetSizeInBytes())
                {
                    throw Utils::SpectreException("Frame::GetItemByIndex - Object outside bounds of frame. Bad data.");
                }

                return reinterpret_cast<const T*>(((size_t)this) + offset);
            }

            inline uint32_t GetNumItems() const
            {
                return NumItems;
            }

            inline uint32_t GetSizeInBytes() const
            {
                return SizeInBytes;
            }

            inline uint32_t GetType() const
            {
                return Type;
            }

            inline EFrameQuality GetQuality() const
            {
                return (EFrameQuality)Quality;
            }

            inline EFrameCompression GetCompression() const
            {
                return (EFrameCompression)Compression;
            }

            inline uint32_t GetVersion() const
            {
                return Version;
            }
        };
#else
#error Need to Implement for Big Endian
#endif

    } // End namespace Framework

} // End namespace Spectre
