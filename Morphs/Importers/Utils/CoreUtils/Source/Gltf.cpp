/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "CoreUtilsPch.h"

#include <GLTFSDK/ExtrasDocument.h>
#include <GLTFSDK/Serialize.h>
#include <GLTFSDK/Constants.h>
#include <GLTFSDK/MicrosoftGeneratorVersion.h>

#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/Gltf.h>
#include <CoreUtils/Version.h>
#include <CoreUtils/Trace.h>
#include <CoreUtils/Math/BabylonMath.h>

DEFINE_TRACE_AREA(GltfTrace, 0);

namespace
{
    std::string GetMissingExtensionMessage(const char* extensionName)
    {
        std::stringstream sstream;
        sstream << "Extension '" << extensionName << "' found but no handler registered";
        return sstream.str();
    }
}

namespace Babylon
{
namespace Utils
{
namespace glTF
{
    //  Define a cutoff version number for categorizing Canvas-created GLTF files as "legacy" or not
    constexpr const char* kFirstGLTFCompliantVersion = "2.4.1.1";

    //  Test whether a deserialized GLTF document predates GLTF shader compliance.
    //  This test can be used to decide whether any material conversion is required for
    //  visual continuity.
    bool BABYLON_SDK_CALL IsLegacyGLTFDocument(const Microsoft::glTF::Document& theDocument)
    {
        const Microsoft::glTF::Asset& gltfAsset = theDocument.asset;
        Microsoft::glTF::MicrosoftGeneratorVersion thisVersion(gltfAsset.generator);
        Microsoft::glTF::MicrosoftGeneratorVersion firstCompliantVersion(kFirstGLTFCompliantVersion);

        //  Return whether we wrote it, and it's older than the first version with a compliant shader.
        bool isLegacy = (thisVersion.IsMicrosoftGenerator() && (thisVersion < firstCompliantVersion));

        if (isLegacy)
        {
            const char *str1 = gltfAsset.generator.c_str();
            const char *str2 = kFirstGLTFCompliantVersion;
            TRACE_INFO(GltfTrace, "GLTF Document flagged as legacy:  %s < %s", str1, str2);
        }

        return isLegacy;
    }

    //  For legacy models, rewrite their materials to retain the legacy look in GLTF compliant viewers
    void BABYLON_SDK_CALL OverrideLegacyGLTFMaterial(Microsoft::glTF::Material& material, LegacyMode mode)
    {
        const char *mtlName = material.name.c_str();
        TRACE_INFO(GltfTrace, "Overwriting GLTF material %s to reflect legacy Canvas rendering", mtlName);

        if (material.HasUnregisteredExtension(Microsoft::glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME))
        {
            throw Babylon::Utils::BabylonException(GetMissingExtensionMessage(Microsoft::glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME));
        }

        //  Legacy rendering did not multiply textures by factors, so make sure that's an identity operation:
        if (!material.emissiveTexture.textureId.empty())    material.emissiveFactor = Microsoft::glTF::Color3(1.0f, 1.0f, 1.0f);
        if (!material.normalTexture.textureId.empty())      material.normalTexture.scale = 1.0f;
        if (!material.occlusionTexture.textureId.empty())   material.occlusionTexture.strength = 1.0f;

        if (mode == EngineLoader)
        {
            if (!material.metallicRoughness.baseColorTexture.textureId.empty()) material.metallicRoughness.baseColorFactor = Microsoft::glTF::Color4(1.0f, 1.0f, 1.0f, 1.0f);
            if (!material.metallicRoughness.metallicRoughnessTexture.textureId.empty())
            {
                material.metallicRoughness.metallicFactor = 1.0f;
                material.metallicRoughness.roughnessFactor = 1.0f;
            }
        }

        if (material.HasExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>())
        {
            auto& sgExtension = material.GetExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>();
            if (!sgExtension.diffuseTexture.textureId.empty())  sgExtension.diffuseFactor = Microsoft::glTF::Color4(1.0f, 1.0f, 1.0f, 1.0f);
            if (!sgExtension.specularGlossinessTexture.textureId.empty())
            {
                sgExtension.glossinessFactor = 1.0f;
                sgExtension.specularFactor = Microsoft::glTF::Color3(1.0f, 1.0f, 1.0f);
            }
        }

        //  Legacy rendering assumed sRGB factors and converted to linear.  So force linear factors.
        //
        //  Decision:  we will not do colour space conversion as part of this, so that the result
        //  will not change visually in legacy (non GLTF-compliant) viewers.  It's not correct, but
        //  it does make rollout easier as it means we don't have to coordinate updates to all of the
        //  viewer endpoints.
        //
        /** DISABLING COLOR SPACE CONVERSION
        material.emissiveFactor = material.emissiveFactor.ToLinear();
        material.specularGlossiness.specularFactor = material.specularGlossiness.specularFactor.ToLinear();
        material.specularGlossiness.diffuseFactor = c4ToLinear(material.specularGlossiness.diffuseFactor);
        material.metallicRoughness.baseColorFactor = c4ToLinear(material.metallicRoughness.baseColorFactor);

        material.emissiveFactor.Clamp(0.0f, 1.0f);
        material.specularGlossiness.specularFactor.Clamp(0.0f, 1.0f);
        **/

        //  Legacy rendering did no backface culling, treating all materials as doublesided:
        material.doubleSided = true;

        //  Figure out whether there are any non-default factors which do NOT have a corresponding texture.
        //  These have not been overwritten, and are still in sRGB space.  We want to tag the
        //  material to flag this, in case it's useful later.
        bool sRGBFactorsAreActive = false;

        const Microsoft::glTF::Color3 blackColor3 = { 0.0f, 0.0f, 0.0f };
        const Microsoft::glTF::Color3 whiteColor3 = { 1.0f, 1.0f, 1.0f };
        const Microsoft::glTF::Color4 whiteColor4 = { 1.0f, 1.0f, 1.0f, 1.0f };

        if ((material.emissiveTexture.textureId.empty() && (material.emissiveFactor != blackColor3)) ||
            (material.metallicRoughness.baseColorTexture.textureId.empty() && (material.metallicRoughness.baseColorFactor != whiteColor4) && mode == EngineLoader))
        {
            sRGBFactorsAreActive = true;
        }
        else if (material.HasExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>())
        {
            auto& sgExtension = material.GetExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>();
            if ((sgExtension.diffuseTexture.textureId.empty() && (sgExtension.diffuseFactor != whiteColor4)) ||
                (sgExtension.specularGlossinessTexture.textureId.empty() && (sgExtension.specularFactor != whiteColor3)))
            {
                sRGBFactorsAreActive = true;
            }
        }

        //  Tag the material so we can detect it later, mostly for DevOps troubleshooting
        if (!HasSRGBFactors(material))
        {
            Microsoft::glTF::ExtrasDocument gltfExtras;
            gltfExtras.SetMemberValue(kMetadataGammaFactors, sRGBFactorsAreActive);
            material.extras = Microsoft::glTF::Serialize(gltfExtras.GetDocument());
        }
    }

    bool BABYLON_SDK_CALL HasSRGBFactors(const Microsoft::glTF::Material& material)
    {
        return ((!material.extras.empty()) && (Microsoft::glTF::ExtrasDocument(material.extras.c_str()).GetMemberValueOrDefault<bool>(kMetadataGammaFactors)));
    }

    //  Warn of unsupported GLTF features (to date)
    void BABYLON_SDK_CALL EmitNonComplianceWarnings(const Microsoft::glTF::Material& material, bool isComplianceEnabled)
    {
        if (material.HasUnregisteredExtension(Microsoft::glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME))
        {
            throw Babylon::Utils::BabylonException(GetMissingExtensionMessage(Microsoft::glTF::KHR::Materials::PBRSPECULARGLOSSINESS_NAME));
        }

        const char *mtlName = material.name.c_str();

        auto emitFactorWarning = [mtlName](const char *factorName)
        {
            TRACE_WARN(GltfTrace, "[GLTF COMPLIANCE WARNING] Material %s: %s factor(s) currently unsupported as texture multipliers.  Ignoring.", mtlName, factorName);
        };

        // Engine now supports material factors and single-sided geometry when in glTF compliance mode
        if (!isComplianceEnabled)
        {
            if (!material.emissiveTexture.textureId.empty() && material.emissiveFactor != Microsoft::glTF::Color3(1.0f, 1.0f, 1.0f))
            {
                emitFactorWarning("Emissive");
            }

            if (material.HasExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>())
            {
                auto& sgExtension = material.GetExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>();
                if (!sgExtension.diffuseTexture.textureId.empty() && sgExtension.diffuseFactor != Microsoft::glTF::Color4(1.0f, 1.0f, 1.0f, 1.0f))
                {
                    emitFactorWarning("Diffuse");
                }
                if (!sgExtension.specularGlossinessTexture.textureId.empty() && sgExtension.glossinessFactor != 1.0f)
                {
                    emitFactorWarning("Glossiness");
                }
            }

            if (!material.normalTexture.textureId.empty() && material.normalTexture.scale != 1.0f)
            {
                emitFactorWarning("NormalScale");
            }

            if (!material.occlusionTexture.textureId.empty() && material.occlusionTexture.strength != 1.0f)
            {
                emitFactorWarning("OcclusionStrength");
            }

            if (!material.metallicRoughness.baseColorTexture.textureId.empty() && material.metallicRoughness.baseColorFactor != Microsoft::glTF::Color4(1.0f, 1.0f, 1.0f, 1.0f))
            {
                emitFactorWarning("BaseColor");
            }

            if (!material.metallicRoughness.metallicRoughnessTexture.textureId.empty() && material.metallicRoughness.metallicFactor != 1.0f)
            {
                emitFactorWarning("Metallic");
            }

            if (!material.metallicRoughness.metallicRoughnessTexture.textureId.empty() && material.metallicRoughness.roughnessFactor != 1.0f)
            {
                emitFactorWarning("Roughness");
            }
        }
    }

    bool BABYLON_SDK_CALL IsSpecularGlossinessMaterial(const Microsoft::glTF::Material& material)
    {
        return material.HasExtension<Microsoft::glTF::KHR::Materials::PBRSpecularGlossiness>();
    }

    bool BABYLON_SDK_CALL IsUnlitMaterialImplied(const Microsoft::glTF::MeshPrimitive& meshPrimitive)
    {
        const bool isPointsOrLines =
            meshPrimitive.mode == Microsoft::glTF::MESH_LINES ||
            meshPrimitive.mode == Microsoft::glTF::MESH_LINE_STRIP ||
            meshPrimitive.mode == Microsoft::glTF::MESH_LINE_LOOP ||
            meshPrimitive.mode == Microsoft::glTF::MESH_POINTS;

        return isPointsOrLines && !meshPrimitive.HasAttribute(Microsoft::glTF::ACCESSOR_NORMAL);
    }

    //  Query for all joint nodes in a document
    std::set<std::string> BABYLON_SDK_CALL GetJoints(const Microsoft::glTF::Document& document)
    {
        std::set<std::string> joints;

        for (auto& skin : document.skins.Elements())
        {
            //joints.insert(skin.skeletonId);  Ignoring, based on input from Gary Hsu.  It's an optional field, and not clearly defined.  Suspect it will disappear from the spec.
            joints.insert(skin.jointIds.begin(), skin.jointIds.end());
        }

        return joints;
    }

    float BABYLON_SDK_CALL GenerateLegacyGlossinessValue(const Babylon::Utils::Math::Color& color)
    {
        constexpr Math::Vector3 kHDTVRec709_RGBLuminanceCoefficients(0.2126f, 0.7152f, 0.0722f);

        // Adapted from similar code in StandardShaderCommon.ps.hlsl: use specular RGB luma to control surface smoothness
        const float specularLuma = Math::Saturate(color.ToVector3().Dot(kHDTVRec709_RGBLuminanceCoefficients));
        const float specularLumaAdjusted = specularLuma * 0.95f; // Coefficient of 0.95 used to enforce a maximum smoothness value

        return specularLumaAdjusted;
    }

    AnimationMetadata::eType BABYLON_SDK_CALL AnimationMetadata::GetType(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::Animation& animation)
    {
        auto skeletalJointNodeIds = Babylon::Utils::glTF::GetJoints(gltfDocument);

        unsigned int animationType = 0;

        for (size_t j = 0; j < animation.channels.Size(); j++)
        {
            auto& channel = animation.channels[j];
            const char *warningMsg = "[GLTF COMPLIANCE WARNING] Ignoring unsupported %s animation(s): Animation %s Channel %s.";

            if (channel.target.path == Microsoft::glTF::TargetPath::TARGET_WEIGHTS)
            {
                animationType |= AnimationMetadata::kMorph;
                TRACE_WARN(GltfTrace, warningMsg, "morph", animation.id.c_str(), animation.channels[j].id.c_str());
            }
            else if (skeletalJointNodeIds.find(channel.target.nodeId) == skeletalJointNodeIds.end())
            {
                // Found animation targeting a non-joint node
                animationType |= AnimationMetadata::kNode;
                TRACE_WARN(GltfTrace, warningMsg, "node", animation.id.c_str(), animation.channels[j].id.c_str());
            }
            else
            {
                animationType |= AnimationMetadata::kSkinned;
            }
        }

        return static_cast<AnimationMetadata::eType>(animationType);
    }

    //  This is primarily to support Office's animation UI by reporting on animation types encountered during load.
    AnimationMetadata::eSupport BABYLON_SDK_CALL AnimationMetadata::GetSupport(const Microsoft::glTF::Document& gltfDocument, const Microsoft::glTF::Animation& animation)
    {
        bool skeletonAnimationFound = false;
        bool morphAnimationFound = false;
        bool nodeAnimationFound = false;

        auto animationType = AnimationMetadata::GetType(gltfDocument, animation);
        if (animationType & AnimationMetadata::kSkinned)
        {
            skeletonAnimationFound = true;
        }
        if (animationType & AnimationMetadata::kNode)
        {
            nodeAnimationFound = true;
        }
        if (animationType & AnimationMetadata::kMorph)
        {
            morphAnimationFound = true;
        }

        //  Is the animation playable with current Engine implementation?
        //  Even if it is, was any unsupported data encountered during load and ignored?
        if (skeletonAnimationFound)
        {
            return ( !(nodeAnimationFound || morphAnimationFound) )
                ? AnimationMetadata::eSupport::kSupported
                : AnimationMetadata::eSupport::kMixed;
        }
        return AnimationMetadata::eSupport::kUnsupported;
    }

    Babylon::Utils::Math::Matrix GetTextureTransformMatrix(const Microsoft::glTF::KHR::TextureInfos::TextureTransform& textureTransform)
    {
        auto translation = Babylon::Utils::Math::Matrix::CreateTranslation(textureTransform.offset.x, textureTransform.offset.y, 0.0f);
        auto rotation = Babylon::Utils::Math::Matrix::CreateRotationZ(-textureTransform.rotation);
        auto scale = Babylon::Utils::Math::Matrix::CreateScale(textureTransform.scale.x, textureTransform.scale.y, 1.0f);
        Babylon::Utils::Math::Matrix transform = scale * rotation * translation;
        return transform;
    }

    bool TryGetTextureTransform(const Babylon::Utils::Math::Matrix& matrix, Microsoft::glTF::TextureInfo& textureInfo)
    {
        if (matrix != Babylon::Utils::Math::Matrix::Identity)
        {
            Babylon::Utils::Math::Vector3 scale;
            Babylon::Utils::Math::Quaternion rotation;
            Babylon::Utils::Math::Vector3 position;
            if (matrix.Decompose(scale, rotation, position))
            {
                auto textureTransform = std::make_unique<Microsoft::glTF::KHR::TextureInfos::TextureTransform>();

                textureTransform->offset.x = position.x;
                textureTransform->offset.y = position.y;
                textureTransform->scale.x = scale.x;
                textureTransform->scale.y = scale.y;
                textureTransform->rotation = 2.0f * acosf(rotation.w);

                // NOTE: We don't propagate the extension's texCoord value through the loader/engine at present so we leave it 'unspecified' here.
                // That prevents it from being serialized/exported, so the model will use the UV set associated with the texture (which will render correctly).
                // We also don't support the implementation note at https://github.com/KhronosGroup/glTF/tree/master/extensions/2.0/Khronos/KHR_texture_transform
                // regarding fallback UV sets for clients that don't have the extension.

                textureInfo.SetExtension(std::move(textureTransform));
                return true;
            }
            else
            {
                TRACE_WARN(GltfTrace, "Error extracting texture transformation components from matrix");
            }
        }

        return false;
    }

} // ns Gltf
} // ns Utils
} // ns Babylon
