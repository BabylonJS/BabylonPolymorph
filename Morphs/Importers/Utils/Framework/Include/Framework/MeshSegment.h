/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Endian.h>
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

        class HalfFloat;

        /**
         * Common header used for all Geometry related data. The header provides information about
         * what other data is availabe in the stream (see MeshBaseSegment::Type).
         */
        struct MeshBaseSegment
        {
            enum EVersion
            {
                kVersion0 = 0x10002000
            };

            enum EFormat
            {
                kHasUV0 = 0x00000001,
                kHasUV1 = 0x00000002,
                kHasUV2 = 0x00000004,
                kHasUV3 = 0x00000008,
                kHasNormals = 0x00000010,
                kHasTangents = 0x00000020,
                kHasIndices = 0x00000040,
                kHasColor = 0x00000080,
                kHasPosition = 0x00000100,
                kHasBoundingBox = 0x00000200,
                kHasJointData = 0x00000400,
                kHasMorphTargets = 0x00000800,
                kHasBigIndices = 0x10000000,

                kFormatMaskAllFlags = kHasUV0 | kHasUV1 | kHasUV2 | kHasUV3 | kHasNormals | kHasTangents |
                kHasIndices | kHasColor | kHasPosition | kHasBoundingBox | kHasJointData | kHasMorphTargets |
                kHasBigIndices
            };

            enum Type
            {
                kTypeGeometry = 0,          /**< Data is of type GeometrySegmentData */
                kTypeNode = 1,              /**< Data is of type NodeSegmentData */
                kTypeSkeleton = 2,          /**< Data is of type SkeletonSegmentData */
                kTypeInstance = 3           /**< Data is of type MeshInstanceSegmentData */
            };

            // TODO: Change this to a named enum and remove it from struct
            struct Flags
            {
                enum
                {
                    kDisabled =                    0x0001, /**< Segment is disabled and should not be rendered */
                    // The following flag was added so that models uploaded to Remix before vertex color support
                    // was added will still render the same as before the change.
                    kDisplayVertexColors =         0x0002, /**< Vertex colors should not be rendered unless set */
                    kMinecraftMesh =               0x0004, /**< Flag showing mesh was generated in Minecraft */
                    kMultiMaterialMesh =           0x0008, /**< Flag indicating that segment was part of a multi-material mesh */
                    kNoTransform =                 0x0010, /*Flag indicating that segment has no transform and should be collapsed to Geometry */
                    kOriginalTopologyLineLoop =    0x0020, /*Flag indicating that the underlying geometry is a LineLoop */
                    kOriginalTopologyTriangleFan = 0x0040, /*Flag indicating that the underlying geometry is a TriangleFan */
                    kOriginalTopologyIndexed =     0x0080, /*Flag indicating that the underlying geometry was indexed */
                };
            };

            uint32_t Version;       /**< Version of format (for future extensibility). */

            uint8_t Type;           /**< Type of mesh. This dictates what the rest of the data looks like */
            uint8_t Reserved0[3];

            uint32_t MeshID;        /**< ID of the mesh segment (eg. hash of name) */
            uint32_t ParentID;      /**< ID of parent mesh, or 0 if no parent */
        };

        /*
        * Represents an empty hierarchy node, which contains only an ID, parent ID and the transform
        */
        struct NodeSegment : MeshBaseSegment
        {
            float     Transform[16];     /**< 4x4 transform matrix */
            float    BoundsCenter[3];   /**< X,Y,Z bounding box center position */
            float    BoundsExtents[3];  /**< X,Y,Z bounding box extents */
        };

        /*
        * Represents a complete Skeleton
        */
        struct SkeletonSegment : MeshBaseSegment
        {
            uint16_t NumJoints;
            uint16_t Reserved00;

            /// 'NumJoints' Joint items immediately follow this struct in memory
            struct Joint
            {
                uint32_t Id;
                int32_t ParentJointIndex;
                float InverseBindMatrix[16];
                float Transform[16];
            };
        };

        /**
        * MeshSkeletonBinding specifies a skeleton that this mesh is bound to
        */
        struct MeshSkeletonBinding : ExtensionHeader
        {
            uint32_t SkeletonID;    /**< ID of the skeleton which this mesh is bound to */
        };

        /**
        * Represents a Mesh segment in the Common Object Format's in-memory
        * representation. This is a raw binary representation.
        */
        struct MeshSegment : MeshBaseSegment
        {
            uint32_t MaterialID;    /**< ID of the material to apply to this mesh (0 if no material) */
            uint32_t NumVertices;   /**< Number of vertices */
            uint32_t NumIndices;    /**< Number of indices */
            uint32_t FormatMask;    /**< Bit mask indicating what data is available (see Format) */

            uint32_t OffsetToFirstExtensionHeader;  /**< Offset in bytes from start of buffer to first ExtensionHeader (0 if not present) */
            uint32_t OffsetPos;                     /**< Offset in bytes from start of buffer to position data (0 if not present) */
            uint32_t OffsetUV0;                     /**< Offset in bytes from start of buffer to UV0 data (0 if not present) */
            uint32_t OffsetUV1;                     /**< Offset in bytes from start of buffer to UV1 data (0 if not present) */
            uint32_t OffsetNormals;                 /**< Offset in bytes from start of buffer to Normal data (0 if not present) */
            uint32_t OffsetColors;                  /**< Offset in bytes from start of buffer to Color data (0 if not present) */
            uint32_t OffsetTangents;                /**< Offset in bytes from start of buffer to Tangent data (0 if not present) */
            uint32_t OffsetIndices;                 /**< Offset in bytes from start of buffer to Indices (0 if not present) */
            uint32_t OffsetJointIndices;            /**< Offset in bytes from start of buffer to Joint Indices. 4 per index, uint8_t size (0 if not present) */
            uint32_t OffsetJointWeights;            /**< Offset in bytes form start of buffer to Joint Weights. 4 per index, uint8_t size (0 if not present) */

            uint16_t Flags;                 /**< Flags specific to the mesh segment */
            uint16_t Padding1;
            float     Transform[16];         /**< 4x4 transform matrix */
            float    BoundsCenter[3];       /**< X,Y,Z bounding box center position */
            float    BoundsExtents[3];      /**< X,Y,Z bounding box extents */

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

        /**
        * Represents an Instance segment which contains transform information, material ID
        * and a flag to specify if the MeshID is to be interpreted as a primitve ID.
        */
        struct MeshInstanceSegment : NodeSegment
        {
            uint32_t    SourceMeshID;       /**< ID of the mesh this segment is an instance of. */
            uint32_t    Padding0;
            uint32_t    MaterialID;         /**< ID of the material to apply to this mesh (0 if no material) */
            uint8_t     IsPrimitive;        /**< Reserved for future use, if non zero interpret meshID as primitive type. */
            uint8_t     HasBoundingBox;     /**< Flag to specify if a bounding box is present on the instance. */
            uint16_t    Padding1;
        };

        //////////////////////////////////////////////////////////////////////////

#if (__BYTE_ORDER == __LITTLE_ENDIAN)
        struct MeshSegmentBigEndian : MeshSegment
        {
            // Helper methods

            inline bool IsValid() const;
            inline uint32_t GetMeshID() const;
            inline uint32_t GetParentID() const;
            inline uint32_t GetNumVertices() const;
            inline uint32_t GetNumIndices() const;
            inline uint32_t GetFormatMask() const;
            inline uint32_t GetMaterialID() const;
            inline uint32_t GetSkeletonID() const;
            inline uint16_t GetFlags() const;

            /**
             * Array Length = sizeof(float) * 3 * NumVertices;
             *
             * \return Position array. It contains 3 floats for vertex (X, Y, Z)
             */
            inline const float* GetDataPosition() const;

            /**
             * Array Length = sizeof(float) * 2 * NumVertices;
             *
             * \return The UV0 array. It contains 2 floats per vertex (U, V)
             */
            inline const float* GetDataUV0() const;

            /**
             * Array Length = sizeof(float) * 2 * NumVertices;
             *
             * \return The UV1 array. It contains 2 floats per vertex (U, V)
             */
            inline const float* GetDataUV1() const;

            /**
             * Array Length = sizeof(HalfFloat) * 3 * NumVertices;
             *
             * \return The Normal array. It contains 3 half floats per vertex (x, y, z)
             */
            inline const HalfFloat* GetDataNormals() const;

            /**
             * Array Length = sizeof(RGBA) * NumVertices;
             *
             * \return The vertex color array
             */
            inline const RGBA* GetDataColors() const;

            /**
             * Array Length = sizeof(HalfFloat) * 3 * NumVertices;
             *
             * \return The tangents array
             */
            inline const HalfFloat* GetDataTangents() const;

            /**
             * Array Length = sizeof(uint8_t) * 4 * NumVertices;
             *
             * \return The joint weights array
             */
            inline const uint8_t* GetJointWeights() const;

            /**
             * Array Length = sizeof(uint8_t) * 4 * NumVertices;
             *
             * \return The joint indices array
             */
            inline const uint8_t* GetJointIndices() const;

            /**
             * Array Length = sizeof(ShortIndex) * NumIndices;
             *
             * \return Index array. Valid only if ((FormatMask & kHasBigIndices) == 0)
             */
            inline const ShortIndex* GetDataShortIndices() const;

            /**
             * Array Length = sizeof(LongIndex) * NumIndices;
             *
             * \return Index array. Valid only if ((FormatMask & kHasBigIndices) == kHasBigIndices)
             */
            inline const LongIndex* GetDataLongIndices() const;
        };

        inline bool MeshSegmentBigEndian::IsValid() const { return Endian::FromNetworkU32(Version) == kVersion0 && OffsetPos != 0; }
        inline uint32_t MeshSegmentBigEndian::GetMeshID() const { return Endian::FromNetworkU32(MeshID); }
        inline uint32_t MeshSegmentBigEndian::GetParentID() const { return Endian::FromNetworkU32(ParentID); }
        inline uint32_t MeshSegmentBigEndian::GetNumVertices() const { return Endian::FromNetworkU32(NumVertices); }
        inline uint32_t MeshSegmentBigEndian::GetNumIndices() const { return Endian::FromNetworkU32(NumIndices); }
        inline uint32_t MeshSegmentBigEndian::GetFormatMask() const { return Endian::FromNetworkU32(FormatMask); }
        inline uint32_t MeshSegmentBigEndian::GetMaterialID() const { return Endian::FromNetworkU32(MaterialID); }
        inline uint16_t MeshSegmentBigEndian::GetFlags() const { return Endian::FromNetworkU16(Flags); }

        inline const float* MeshSegmentBigEndian::GetDataPosition() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasPosition) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<float const*>(Base() + Endian::FromNetworkU32(OffsetPos));
        }

        inline const float* MeshSegmentBigEndian::GetDataUV0() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasUV0) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<float const*>(Base() + Endian::FromNetworkU32(OffsetUV0));
        }

        inline const float* MeshSegmentBigEndian::GetDataUV1() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasUV1) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<float const*>(Base() + Endian::FromNetworkU32(OffsetUV1));
        }

        inline const HalfFloat* MeshSegmentBigEndian::GetDataNormals() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasNormals) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<HalfFloat const*>(Base() + Endian::FromNetworkU32(OffsetNormals));
        }

        inline const RGBA* MeshSegmentBigEndian::GetDataColors() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasColor) == 0
                || (Endian::FromNetworkU16(Flags) & Flags::kDisplayVertexColors) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<RGBA const*>(Base() + Endian::FromNetworkU32(OffsetColors));
        }

        inline const HalfFloat* MeshSegmentBigEndian::GetDataTangents() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasTangents) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<HalfFloat const*>(Base() + Endian::FromNetworkU32(OffsetTangents));
        }

        inline const uint8_t* MeshSegmentBigEndian::GetJointWeights() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasJointData) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<uint8_t const*>(Base() + Endian::FromNetworkU32(OffsetJointWeights));
        }

        inline const uint8_t* MeshSegmentBigEndian::GetJointIndices() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasJointData) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<uint8_t const*>(Base() + Endian::FromNetworkU32(OffsetJointIndices));
        }

        inline const ShortIndex* MeshSegmentBigEndian::GetDataShortIndices() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasBigIndices) == kHasBigIndices)
            {
                return nullptr;
            }
            return reinterpret_cast<ShortIndex const*>(Base() + Endian::FromNetworkU32(OffsetIndices));
        }

        inline const LongIndex* MeshSegmentBigEndian::GetDataLongIndices() const
        {
            if ((Endian::FromNetworkU32(FormatMask) & kHasBigIndices) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<LongIndex const*>(Base() + Endian::FromNetworkU32(OffsetIndices));
        }

        //////////////////////////////////////////////////////////////////////////

        struct SkeletonSegmentLittleEndian : SkeletonSegment
        {
            inline uint16_t GetNumJoints() const { return NumJoints; }

            struct JointLittleEndian: Joint
            {
                inline uint32_t GetId() const                      { return Id; }
                inline int32_t GetParentJointIndex() const         { return ParentJointIndex; }
                inline Babylon::Utils::Math::Matrix GetInverseBindMatrix() const    { return Babylon::Utils::Math::Matrix(InverseBindMatrix); }
                inline Babylon::Utils::Math::Matrix GetTransform() const            { return Babylon::Utils::Math::Matrix(Transform); }
            }
            JointData[];
        };

        //////////////////////////////////////////////////////////////////////////

        struct MeshSegmentLittleEndian : MeshSegment
        {
            // Helper methods

            inline bool IsValid() const;
            inline uint32_t GetMeshID() const;
            inline uint32_t GetParentID() const;
            inline uint32_t GetNumVertices() const;
            inline uint32_t GetNumIndices() const;
            inline uint32_t GetFormatMask() const;
            inline bool HasFormat(MeshBaseSegment::EFormat format) const;
            inline uint32_t GetMaterialID() const;

            /**
            * Get associated skeleton ID, if this mesh is bound to a skeleton
            *
            * CAUTION: Only use this on validated data - this function dereferences pointers
            * This is safe to use on MeshSegments which have passed through Engine::Parser since it validates data ranges.
            *
            * \return The skeleton ID
            */
            inline uint32_t GetSkeletonID() const;

            /**
            * \return The first extension header
            */
            inline ExtensionHeaderLittleEndian const* GetFirstExtensionHeader() const;

            inline uint16_t GetFlags() const;

            /**
             * Array Length = sizeof(float) * 3 * NumVertices;
             *
             * \return Position array. It contains 3 floats for vertex (X, Y, Z)
             */
            inline const float* GetDataPosition() const;

            /**
             * Array Length = sizeof(float) * 2 * NumVertices;
             *
             * \return The UV0 array. It contains 2 floats per vertex (U, V)
             */
            inline const float* GetDataUV0() const;

            /**
             * Array Length = sizeof(float) * 2 * NumVertices;
             *
             * \return The UV1 array. It contains 2 floats per vertex (U, V)
             */
            inline const float* GetDataUV1() const;

            /**
             * Array Length = sizeof(HalfFloat) * 3 * NumVertices;
             *
             * \return The Normal array. It contains 3 half floats per vertex (x, y, z)
             */
            inline const HalfFloat* GetDataNormals() const;

            /**
             * Array Length = sizeof(RGBA) * NumVertices;
             *
             * \return The vertex color array
             */
            inline const RGBA* GetDataColors() const;

            /**
             * Array Length = sizeof(HalfFloat) * 3 * NumVertices;
             *
             * \return The tangents array
             */
            inline const HalfFloat* GetDataTangents() const;

           /**
            * Array Length = sizeof(uint8_t) * 4 * NumVertices;
            *
            * \return The joint weights array
            */
            inline const uint8_t* GetJointWeights() const;

            /**
             * Array Length = sizeof(uint8_t) * 4 * NumVertices;
             *
             * \return The joint indices array
             */
            inline const uint8_t* GetJointIndices() const;

            /**
             * Array Length = sizeof(ShortIndex) * NumIndices;
             *
             * \return Index array. Valid only if ((FormatMask & kHasBigIndices) == 0)
             */
            inline const ShortIndex* GetDataShortIndices() const;

            /**
             * Array Length = sizeof(LongIndex) * NumIndices;
             *
             * \return Index array. Valid only if ((FormatMask & kHasBigIndices) == kHasBigIndices)
             */
            inline const LongIndex* GetDataLongIndices() const;
        };


        inline bool MeshSegmentLittleEndian::IsValid() const { return Version == kVersion0 && OffsetPos != 0; }
        inline uint32_t MeshSegmentLittleEndian::GetMeshID() const { return MeshID; }
        inline uint32_t MeshSegmentLittleEndian::GetParentID() const { return ParentID; }
        inline uint32_t MeshSegmentLittleEndian::GetNumVertices() const { return NumVertices; }
        inline uint32_t MeshSegmentLittleEndian::GetNumIndices() const { return NumIndices; }
        inline uint32_t MeshSegmentLittleEndian::GetFormatMask() const { return FormatMask; }
        inline uint32_t MeshSegmentLittleEndian::GetMaterialID() const { return MaterialID; }
        inline uint16_t MeshSegmentLittleEndian::GetFlags() const { return Flags; }

        inline bool MeshSegmentLittleEndian::HasFormat(MeshBaseSegment::EFormat format) const
        {
            uint32_t format32 = static_cast<uint32_t>(format);
            return (FormatMask & format32) == format32;
        }

        inline ExtensionHeaderLittleEndian const* MeshSegmentLittleEndian::GetFirstExtensionHeader() const
        {
            if (OffsetToFirstExtensionHeader == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<ExtensionHeaderLittleEndian const*>(Base() + OffsetToFirstExtensionHeader);
        }

        inline uint32_t MeshSegmentLittleEndian::GetSkeletonID() const
        {
            if (auto firstHeader = GetFirstExtensionHeader())
            {
                if (auto extensionHeader = firstHeader->FindFirstHeaderByType(ExtensionHeader::kMeshSkeletonBinding))
                {
                    auto skeletonBinding = reinterpret_cast<MeshSkeletonBinding const*>(extensionHeader);
                    return skeletonBinding->SkeletonID;
                }
            }
            return 0;
        }

        inline const float* MeshSegmentLittleEndian::GetDataPosition() const
        {
            if ((FormatMask & kHasPosition) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<float const*>(Base() + OffsetPos);
        }

        inline const float* MeshSegmentLittleEndian::GetDataUV0() const
        {
            if ((FormatMask & kHasUV0) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<float const*>(Base() + OffsetUV0);
        }

        inline const float* MeshSegmentLittleEndian::GetDataUV1() const
        {
            if ((FormatMask & kHasUV1) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<float const*>(Base() + OffsetUV1);
        }

        inline const HalfFloat* MeshSegmentLittleEndian::GetDataNormals() const
        {
            if ((FormatMask & kHasNormals) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<HalfFloat const*>(Base() + OffsetNormals);
        }

        inline const RGBA* MeshSegmentLittleEndian::GetDataColors() const
        {
            if ((FormatMask & kHasColor) == 0
                || (Flags & Flags::kDisplayVertexColors) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<RGBA const*>(Base() + OffsetColors);
        }

        inline const HalfFloat* MeshSegmentLittleEndian::GetDataTangents() const
        {
            if ((FormatMask & kHasTangents) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<HalfFloat const*>(Base() + OffsetTangents);
        }

        inline const uint8_t* MeshSegmentLittleEndian::GetJointWeights() const
        {
            if ((FormatMask & kHasJointData) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<uint8_t const*>(Base() + OffsetJointWeights);
        }

        inline const uint8_t* MeshSegmentLittleEndian::GetJointIndices() const
        {
            if ((FormatMask & kHasJointData) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<uint8_t const*>(Base() + OffsetJointIndices);
        }

        inline const ShortIndex* MeshSegmentLittleEndian::GetDataShortIndices() const
        {
            if ((FormatMask & kHasBigIndices) == kHasBigIndices)
            {
                return nullptr;
            }
            return reinterpret_cast<ShortIndex const*>(Base() + OffsetIndices);
        }

        inline const LongIndex* MeshSegmentLittleEndian::GetDataLongIndices() const
        {
            if ((FormatMask & kHasBigIndices) == 0)
            {
                return nullptr;
            }
            return reinterpret_cast<LongIndex const*>(Base() + OffsetIndices);
        }

        //////////////////////////////////////////////////////////////////////////

        struct MeshInstanceSegmentLittleEndian : MeshInstanceSegment
        {
            inline uint32_t GetSourceMeshID() const;
            inline uint32_t GetMeshID() const;
            inline uint32_t GetParentID() const;
            inline bool GetIsPrimitive() const;
            inline bool GetHasBoundingBox() const;
        };

        inline uint32_t MeshInstanceSegmentLittleEndian::GetSourceMeshID() const { return SourceMeshID; }
        inline uint32_t MeshInstanceSegmentLittleEndian::GetMeshID() const { return MeshID; }
        inline uint32_t MeshInstanceSegmentLittleEndian::GetParentID() const { return ParentID; }
        inline bool MeshInstanceSegmentLittleEndian::GetIsPrimitive() const { return IsPrimitive != 0; }
        inline bool MeshInstanceSegmentLittleEndian::GetHasBoundingBox() const { return HasBoundingBox != 0; }
#else
#error Need to Implement for Big Endian
#endif

    } // End namespace Framework

} // End namespace Babylon

#pragma warning( pop )