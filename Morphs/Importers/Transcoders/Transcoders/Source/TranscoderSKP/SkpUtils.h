/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/Platform.h>
#include <PluginSKP/PluginSKP.h>

#if CANVAS_CAN_USE_SKP()

#include <Asset3D/Asset3D.h>
#include <CoreUtils/Math/SimpleMath.h>

#include <SketchUpAPI/color.h>
#include <SketchUpAPI/common.h>
#include <SketchUpAPI/geometry.h>
#include <SketchUpAPI/model/defs.h>
#include <SketchUpAPI/model/model.h>
#include <SketchUpAPI/transformation.h>

#include <string>

namespace Babylon
{
    namespace Transcoder
    {
        namespace SkpUtils
        {
            enum class Side
            {
                Front,
                Back,
                Both,
            };

            enum class EdgeDisplayMode
            {
                NoEdges,
                AllEdges,
                StandaloneOnly,
            };

            // Utility functions
            void CheckResult(SUResult res);
            std::string ToString(SUResult res);
            std::string ToString(SUStringRef&& suString);

            std::string GetName(const SUComponentDefinitionRef& suComponentDefinition);
            std::string GetName(const SUComponentInstanceRef& suComponentInstance);
            std::string GetName(const SUGroupRef& suGroup);
            std::string GetName(const SUMaterialRef& suMaterial);
            std::string GetComponentDefinitionGuid(const SUComponentDefinitionRef& componentDefinition);

            bool DrawingElementHasMaterial(const SUDrawingElementRef& currentElement);

            bool IsVisible(const SUDrawingElementRef& drawingElement);
            bool IsVisible(const SUGroupRef& group);
            bool IsVisible(const SUComponentInstanceRef& componentInstance);
            bool IsVisible(const SUFaceRef& face);
            bool IsVisible(const SUEdgeRef& edge);

            long GetTextureId(const SUTextureWriterRef& suTextureWriterRef, const SUFaceRef& suFaceRef, SUDrawingElementRef ancestorElement, Side side);

            int32_t GetRenderingOptionValue(SURenderingOptionsRef renderingOptions, const char* key);

            // SKP to A3D conversion functions
            Babylon::Utils::Math::Vector3 ToVector3(const SUVector3D& suVector3d);
            Babylon::Utils::Math::Vector3 ToVector3(const SUPoint3D& suPoint3d);
            Babylon::Utils::Math::Matrix ToMatrix(const SUTransformation& suTransform);
            Babylon::Utils::Math::Color ToColor(const SUColor& suColor);
            Babylon::Utils::Math::Color ToColor(SUTypedValueRef&& suTypedValueRef);

            Babylon::Utils::Math::Color GetMaterialColor(const SUMaterialRef& suMaterial);

            Babylon::Utils::Math::Matrix GetTransform(const SUGroupRef& group);
            Babylon::Utils::Math::Matrix GetTransform(const SUComponentInstanceRef& componentInstance);

            Babylon::Transcoder::Asset3D::UnitInCentimeter GetUnitInCentimeter(const SUModelRef& suModel);
            Babylon::Transcoder::Asset3D::UnitInCentimeter SUModelUnitsToUnitInCentimeter(const SUModelUnits& suModelUnits);

            std::shared_ptr<MaterialDescriptor> GetDefaultMaterial(const SURenderingOptionsRef& suRenderingOptions, Side side);
            std::shared_ptr<MaterialDescriptor> GetDefaultMaterialEdge();

            SUMaterialRef GetEffectiveMaterial(const SUFaceRef& face, SkpUtils::Side side, SUDrawingElementRef ancestorElement);

            size_t CountEntities(SUEntitiesRef entities);
        }
    }
}

namespace std
{
    template<>
    struct hash<SUMaterialRef>
    {
        inline size_t operator()(const SUMaterialRef& material) const
        {
            return Babylon::Utils::HashArgs(material.ptr);
        }
    };
};

inline bool operator==(const SUMaterialRef& a, const SUMaterialRef& b)
{
    return (a.ptr == b.ptr);
}

#endif