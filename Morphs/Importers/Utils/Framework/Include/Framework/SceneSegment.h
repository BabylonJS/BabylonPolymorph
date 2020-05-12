/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <Framework/Types.h>

namespace Babylon
{
    namespace Framework
    {

        // Common header used by all items (definition segments) within a Scene frame
        struct SceneItemCommonHeader
        {
            enum class ESceneItemType : uint8_t
            {
                kScene = 0,    // SceneDefinition
                kLight = 1,    // LightDefinition
                kCamera = 2    // CameraDefinition
            };

            ESceneItemType  Type; // uint8_t
            uint8_t         Reserved0;

            uint16_t        Version;    // Version of format (for future extensibility).
                                        // The value is defined by the EVersion in the corresponding definition based on the Type field
                                        // For example, if Type==kScene then the value is given by SceneDefinition::EVersion.
        };

        struct SceneDefinition : SceneItemCommonHeader
        {
            enum EVersion
            {
                kVersion0 = 0x1000
            };

            // The scale factor applied to the scene relative to its original authored size.
            float       ScaleFactor;

            // The scene's system unit measured in centimetres, independent of any scaling due to ScaleFactor.
            // For example, if the scene is modeled in metres (where 1.0 scene units represents one metre)
            // then SystemUnit will be 100. If the scene is modeled in inches then SystemUnit will be 2.54.
            float       SystemUnit;

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

#if (__BYTE_ORDER == __LITTLE_ENDIAN)

        struct SceneSegmentBigEndian : SceneDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Endian::FromNetworkU32(Version) == kVersion0; }
        };

        struct SceneSegmentLittleEndian : SceneDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Version == kVersion0; }
            inline float GetScaleFactor() const { return ScaleFactor; }
            inline float GetSystemUnit() const { return SystemUnit; }
        };


#else
#error Need to Implement for Big Endian
#endif


        struct LightDefinition : SceneItemCommonHeader
        {
            enum EVersion
            {
                kVersion0 = 0x1000
            };

            enum class EType : uint8_t
            {
                kPoint,
                kSpot
            };

            EType Type;
            uint8_t Reserved0;
            uint8_t Reserved1;
            uint8_t Reserved2;
            uint32_t LightID;
            uint32_t ParentID;
            float ColorRed;
            float ColorGreen;
            float ColorBlue;
            float Intensity;
            float Angle;
            float Radius;

        protected:
            inline const char* Base() const
            {
                return reinterpret_cast<const char*>(this);
            }
        };

#if (__BYTE_ORDER == __LITTLE_ENDIAN)

        struct LightSegmentBigEndian : LightDefinition
        {
            // Helper methods
            inline bool IsValid() const { return Endian::FromNetworkU32(Version) == kVersion0; }
        };

        struct LightSegmentLittleEndian : LightDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Version == kVersion0; }
            inline EType GetType() const { return Type; }
            inline uint32_t GetLightID() const { return LightID; }
            inline uint32_t GetParentID() const { return ParentID; }
            inline float GetColourRed() const { return ColorRed; }
            inline float GetColourGreen() const { return ColorGreen; }
            inline float GetColourBlue() const { return ColorBlue; }
            inline float GetIntensity() const { return Intensity; }
            inline float GetAngle() const { return Angle; }
            inline float GetRadius() const { return Radius; }
        };

#else
#error Need to Implement for Big Endian
#endif

        // Empty structure - reserved for future expansion
        struct CameraDefinition : SceneItemCommonHeader
        {
            enum EVersion
            {
                kVersion0 = 0x1000
            };

            uint32_t Version;
        };

        struct CameraSegmentBigEndian : CameraDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Endian::FromNetworkU32(Version) == kVersion0; }
        };

        struct CameraSegmentLittleEndian : CameraDefinition
        {
            // Helper methods
            inline bool IsValid() const{ return Version == kVersion0; }
        };

        //////////////////////////////////////////////////////////////////////////


    } // End namespace Framework

} // End namespace Babylon
