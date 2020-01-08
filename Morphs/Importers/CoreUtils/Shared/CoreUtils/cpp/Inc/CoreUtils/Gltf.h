/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

//  This is a home for GLTF utils which are not suitable for an OSS-ready GLTFSDK

#include <CoreUtils/SpectreSDK.h>

#include <GLTFSDK/GLTF.h>
#include <GLTFSDK/Document.h>
#include <GLTFSDK/ExtensionsKHR.h>

#include <CoreUtils/Trace.h>

#include <set>

namespace Spectre
{
    namespace Utils
    {
        namespace Math
        {
            struct Color;
            struct Matrix;
        }

        namespace glTF
        {
            // Define extras tag for glTF::Materials to mark it as legacy
            constexpr const char* kMetadataGammaFactors = "MSFT_sRGBFactors";

            // Define extras tag for glTF::Mesh to mark it as Minecraft
            constexpr const char* kMinecraftExtrasAttributeName = "MSFT_minecraftMesh";

            constexpr const char* kExtensionsDefault = "glTF::default";
            constexpr const char* kExtensionsRootGltfKey = "glTF::Extensions_root";
            constexpr const char* kExtensionsDefaultSceneKey = "glTF::Extensions_scene_default";

            constexpr Microsoft::glTF::MinFilterMode GetDefaultMinFilterMode()
            {
                // Default to LINEAR_MIPMAP_LINEAR filtering if no minification property was present in the glTF manifest
                return Microsoft::glTF::MinFilter_LINEAR_MIPMAP_LINEAR;
            }

            constexpr Microsoft::glTF::MagFilterMode GetDefaultMagFilterMode()
            {
                // Default to LINEAR filtering if no magnification property was present in the glTF manifest
                return Microsoft::glTF::MagFilter_LINEAR;
            }

            enum LegacyMode
            {
                Transcoder,
                EngineLoader
            };

            // For reporting animation metadata during load
            class AnimationMetadata
            {
            public:
                // NOTE: Must be kept in sync with Spectre::Engine::AnimationManager::AnimationSupport (Animation/AnimationManager.h)
                enum eSupport : unsigned int
                {
                    kSupported,     // Animation consists of supported types only.  Can play.
                    kUnsupported,   // Animation consists of unsupported types only.  Cannot play.
                    kMixed          // Some unsupported data was found.  Anim may not play as intended.
                };

                // NOTE: Must be kept in sync with Spectre::Engine::AnimationManager::AnimationType (Animation/AnimationManager.h)
                enum eType : unsigned int
                {
                    kNone = 0x0,
                    kSkinned = 0x1,
                    kNode = 0x2,
                    kMorph = 0x4
                };

                static constexpr size_t kInvalid = std::numeric_limits<size_t>::max();

                AnimationMetadata() :
                    m_animIndex(kInvalid),
                    m_animSupport(kUnsupported) {};

                AnimationMetadata(std::string name, std::string id, size_t index, eSupport support) :
                    m_animName(name),
                    m_animID(id),
                    m_animIndex(index),
                    m_animSupport(support) {};

                static eSupport SPECTRESDK_CALL GetSupport(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::Animation& animation);
                static eType SPECTRESDK_CALL GetType(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::Animation& animation);

                std::string m_animName;    // GLTF (optional) name field
                std::string m_animID;      // ID (unique to file load)
                size_t      m_animIndex;   // Animation index (kInvalid if not playable)
                eSupport    m_animSupport; // Indicates support level for types of animation found
            };

            void SPECTRESDK_CALL EmitNonComplianceWarnings(const Microsoft::glTF::Material& material, bool isComplianceEnabled);
            bool SPECTRESDK_CALL IsLegacyGLTFDocument(const Microsoft::glTF::Document& theDocument);
            void SPECTRESDK_CALL OverrideLegacyGLTFMaterial(Microsoft::glTF::Material& material, LegacyMode mode = EngineLoader);
            bool SPECTRESDK_CALL IsSpecularGlossinessMaterial(const Microsoft::glTF::Material& material);
            bool SPECTRESDK_CALL IsUnlitMaterialImplied(const Microsoft::glTF::MeshPrimitive& meshPrimitive);
            bool SPECTRESDK_CALL HasSRGBFactors(const Microsoft::glTF::Material& material);
            std::set<std::string> SPECTRESDK_CALL GetJoints(const Microsoft::glTF::Document& gltfDocument);

            // Note: color argument must be in sRGB space
            float SPECTRESDK_CALL GenerateLegacyGlossinessValue(const Spectre::Utils::Math::Color& color);

            // Create the glTF texture transform matrix for KHR_texture_transform extension
            Spectre::Utils::Math::Matrix GetTextureTransformMatrix(const Microsoft::glTF::KHR::TextureInfos::TextureTransform& textureTransform); bool TryGetTextureTransform(const Spectre::Utils::Math::Matrix& matrix, Microsoft::glTF::TextureInfo& textureInfo);

            // Set the glTF textureTransform values from matrix into textureInfo (KHR_texture_transform extension)
            bool TryGetTextureTransform(const Spectre::Utils::Math::Matrix& matrix, Microsoft::glTF::TextureInfo& textureInfo);

        } // ns Gltf
    } // ns Utils
} // ns Spectre

