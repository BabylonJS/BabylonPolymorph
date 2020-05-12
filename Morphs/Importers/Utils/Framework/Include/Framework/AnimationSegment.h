/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Types.h>

#if !defined(COREUTILS_SIMPLEMATH_H_INCLUDED)
#include <CoreUtils/Math/SimpleMath.h>
#endif // COREUTILS_SIMPLEMATH_H_INCLUDED

#pragma warning( push )
// Disable warning C4200: nonstandard extension used: zero-sized array in struct/union
#pragma warning( disable:4200 )

namespace Babylon
{
    namespace Framework
    {

        /**
         * Header common to all animation types, used to find out what type of animation
         * is in the data, and hence how to parse it.
         */
        struct AnimationHeader
        {
            enum EVersion
            {
                kVersion0 = 0x10001000
            };

            enum EType
            {
                kSkinned = 0,
            };

            uint32_t Version;       /**< Version of format (for future extensibility). */
            uint8_t Type;           /**< Type of animation */
            uint8_t Reserved0[3];
            uint32_t ID;            /**< Animation ID */
        };

        /**
        * Header for a skinned animation. A skinned animation consists of 1 or more joints animated over a period of
        * time. We only include data for joints with changing data over time. Joints don't need to contain data for the
        * full animation
        */
        struct AnimationSkinned : AnimationHeader
        {
            enum EChunkType
            {
                kAligned = 0,       // Obsolete - do not use
                kFixedTimeStep = 1,
                kQuantized = 2,
                kCurves = 3,

                kUnknown = 0xff
            };

            /// kFixedTimeStep
            struct FixedTimeStepChunk
            {
                uint16_t JointIndex;        ///< Which joint does this chunk apply to?
                uint16_t FrameCount;        ///< Number of key-frames stored in this chunk (must be non-zero)

                /// 'FrameCount' JointData items immediately follow this struct in memory
                /// The time range of each frame 'i' is the half-closed interval:
                ///
                ///   [A, B)
                ///
                /// ...where A = StartTime + (EndTime-StartTime) *  i    / FrameCount
                ///      and B = StartTime + (EndTime-StartTime) * (i+1) / FrameCount
                struct JointData
                {
                    float Translation[3];       ///< Translation data for this chunk
                    float Rotation[4];          ///< Rotation data for this chunk
                    float Scale[3];             ///< Scale data for this chunk
                };
            };

#if 0
            // kQuantized - separately quantized streams of T/R/S/time data
            struct QuantizedChunk
            {
                /* QuantizedChunks describe up to four quantized streams of data, packed sequentially in the following order:

                |___stream_______|_dim_|___min_range___|___max_range___|___misc___________________________________________________________|
                | d(Time)        | 1D  |  0.0          | MaxDeltaTime  |                                                                  |
                | d(Translation) | 3D  | MinDeltaTrans | MaxDeltaTrans | different quantization range per component                       |
                | d(Scale)       | 3D  | MinDeltaScale | MaxDeltaScale | quantization range same for all components                       |
                | Rotation       | 3D  | -1.0          | 1.0           | "smallest three" encoding + 2 extra bits to encode max component |

                Multi-dim streams are stored in an interleaved format (i.e. x,y,z,x,y,z,...)
                No padding bits between successive streams within one QuantizedChunk
                "Smallest three" encoding described here: http://gafferongames.com/networked-physics/snapshot-compression/
                */

                float Time0;                            ///< Start time in seconds
                float MaxDeltaTime;                     ///< Max time delta in seconds

                float Translation0[3];                  ///< Start position
                float MinDeltaTrans[3];                 ///< Min translation delta
                float MaxDeltaTrans[3];                 ///< Max translation delta

                float Scale0[3];
                float MinDeltaScale;                    ///< Min bound of scaling range
                float MaxDeltaScale;                    ///< Max bound of scaling range

                uint8_t BitsPerTimeSubdivision;         ///< Number of bits per time delta, or 0 if time-step is fixed
                uint8_t BitsPerTranslationComponent;    ///< Number of bits per component of translation data, or 0 if translation is fixed
                uint8_t BitsPerRotationComponent;       ///< Number of bits per component of rotation data, or 0 if rotation is fixed
                uint8_t BitsPerScaleComponent;          ///< Number of bits per component of scale data, or 0 if scaling is fixed
            };
#endif

            uint32_t SkeletonID;            ///< ID of skeleton we target
            float StartTime;                ///< Start time range of playable animation in seconds
            float EndTime;                  ///< End time range of playable animation in seconds
            uint32_t Padding0;
            uint32_t ChunkCount;            ///< Number of chunks

            /// 'ChunkCount' ChunkHeader items immediately follow this struct in memory
            struct ChunkHeader
            {
                uint8_t ChunkType;           ///< Member of EChunkType determining which sub-type this is
                uint8_t Padding0[3];
                uint32_t ChunkDataOffset;    ///< Offset in bytes to the raw frame data, relative to this struct
            };
        };

        //////////////////////////////////////////////////////////////////////////

#if (__BYTE_ORDER == __LITTLE_ENDIAN)

        namespace SUM = Babylon::Utils::Math;

        struct AnimationHeaderLittleEndian : AnimationHeader
        {
            inline EVersion GetVersion() const          { return EVersion(Version); }
            inline EType GetType() const                { return EType(Type); }
            inline uint32_t GetID() const               { return ID; }
        };

        struct AnimationSkinnedLittleEndian : AnimationSkinned
        {
            struct ChunkHeaderLittleEndian : ChunkHeader
            {
                EChunkType GetChunkType() const                 { return EChunkType(ChunkType); }
                uint32_t GetChunkDataOffset() const             { return ChunkDataOffset; }

                template<typename T> T const* GetChunkData() const  { return (T const*)(uintptr_t(this) + ChunkDataOffset); }
                template<typename T> T*       GetChunkData()        { return (T*)(uintptr_t(this) + ChunkDataOffset); }
            };

            struct FixedTimeStepChunkLittleEndian : FixedTimeStepChunk
            {
                struct JointDataLittleEndian : JointData
                {
                    inline SUM::Vector3 GetTranslation() const      { return SUM::Vector3(Translation); }
                    inline SUM::Quaternion GetRotation() const      { return SUM::Quaternion(Rotation); }
                    inline SUM::Vector3 GetScale() const            { return SUM::Vector3(Scale); }
                };

                inline uint32_t GetChunkDataSize() const        { return uint32_t(sizeof(AnimationSkinned::FixedTimeStepChunk) + sizeof(AnimationSkinned::FixedTimeStepChunk::JointData) * FrameCount); }
                inline uint16_t GetJointIndex() const           { return JointIndex; }
                inline uint16_t GetFrameCount() const           { return FrameCount; }
                JointDataLittleEndian FrameData[];
            };

            inline uint32_t GetSkeletonID() const           { return SkeletonID; }
            inline float GetStartTime() const               { return StartTime; }
            inline float GetEndTime() const                 { return EndTime; }
            inline uint32_t GetChunkCount() const           { return ChunkCount; }
            ChunkHeaderLittleEndian ChunkHeaders[];
        };

#else
#error Need to Implement for Little Endian
#endif

    } // End namespace Framework

} // End namespace Babylon

#pragma warning( pop )