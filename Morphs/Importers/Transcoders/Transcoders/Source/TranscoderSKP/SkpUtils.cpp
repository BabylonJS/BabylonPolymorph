/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"

#include <CoreUtils/Platform.h>

#include "SkpUtils.h"

#if CANVAS_CAN_USE_SKP()

#include <CoreUtils/SmartThrow.h>

#include <SketchUpAPI/model/component_definition.h>
#include <SketchUpAPI/model/component_instance.h>
#include <SketchUpAPI/model/drawing_element.h>
#include <SketchUpAPI/model/edge.h>
#include <SketchUpAPI/model/face.h>
#include <SketchUpAPI/model/group.h>
#include <SketchUpAPI/model/layer.h>
#include <SketchUpAPI/model/material.h>
#include <SketchUpAPI/model/rendering_options.h>
#include <SketchUpAPI/model/texture_writer.h>
#include <SketchUpAPI/model/typed_value.h>

using namespace Babylon::Transcoder;
using namespace Babylon::Utils;

void SkpUtils::CheckResult(SUResult res)
{
    if (res != SU_ERROR_NONE)
    {
        throw BabylonException("Sketchup API call returned an error: " + ToString(res));
    }
}

std::string SkpUtils::ToString(SUResult res)
{
    switch (res)
    {
    case SU_ERROR_NONE:
        return "SU_ERROR_NONE: Success";

    case SU_ERROR_NULL_POINTER_INPUT:
        return "SU_ERROR_NULL_POINTER_INPUT: A pointer for a required input was NULL.";

    case SU_ERROR_INVALID_INPUT:
        return "SU_ERROR_INVALID_INPUT: An API object input to the function was not created properly.";

    case SU_ERROR_NULL_POINTER_OUTPUT:
        return "SU_ERROR_NULL_POINTER_OUTPUT: A pointer for a required output was NULL.";

    case SU_ERROR_INVALID_OUTPUT:
        return "SU_ERROR_INVALID_OUTPUT: An API object to be written with output from the function was not created properly.";

    case SU_ERROR_OVERWRITE_VALID:
        return "SU_ERROR_OVERWRITE_VALID: Indicates that an input object reference already references an object where it was expected to be SU_INVALID.";

    case SU_ERROR_GENERIC:
        return "SU_ERROR_GENERIC: Indicates an unspecified error.";

    case SU_ERROR_SERIALIZATION:
        return "SU_ERROR_SERIALIZATION: Indicate an error occurred during loading or saving of a file.";

    case SU_ERROR_OUT_OF_RANGE:
        return "SU_ERROR_OUT_OF_RANGE: An input contained a value that was outside the range of allowed values.";

    case SU_ERROR_NO_DATA:
        return "SU_ERROR_NO_DATA: The requested operation has no data to return to the user. This usually occurs when a request is made for data that is only available conditionally.";

    case SU_ERROR_INSUFFICIENT_SIZE:
        return "SU_ERROR_INSUFFICIENT_SIZE: Indicates that the size of an output parameter is insufficient.";

    case SU_ERROR_UNKNOWN_EXCEPTION:
        return "SU_ERROR_UNKNOWN_EXCEPTION: An unknown exception occurred.";

    case SU_ERROR_MODEL_INVALID:
        return "SU_ERROR_MODEL_INVALID: The model requested is invalid and cannot be loaded.";

    case SU_ERROR_MODEL_VERSION:
        return "SU_ERROR_MODEL_VERSION: The model cannot be loaded or saved due to an invalid version.";

    case SU_ERROR_LAYER_LOCKED:
        return "SU_ERROR_LAYER_LOCKED: The layer that is being modified is locked.";

    case SU_ERROR_DUPLICATE:
        return "SU_ERROR_DUPLICATE: The user requested an operation that would result in duplicate data.";

    case SU_ERROR_PARTIAL_SUCCESS:
        return "SU_ERROR_PARTIAL_SUCCESS: The requested operation was not fully completed but it returned an intermediate successful result.";

    case SU_ERROR_UNSUPPORTED:
        return "SU_ERROR_UNSUPPORTED: The requested operation is not supported.";

    case SU_ERROR_INVALID_ARGUMENT:
        return "SU_ERROR_INVALID_ARGUMENT: An argument contains invalid information.";

    default:
        return "Unrecognized SUResult enum value";
    }
}

std::string SkpUtils::ToString(SUStringRef&& suString)
{
    size_t length = 0;
    CheckResult(SUStringGetUTF8Length(suString, &length));

    if (length == 0)
    {
        CheckResult(SUStringRelease(&suString));
        return "";
    }

    std::vector<char> stringBuffer(length + 1); // +1 to include null terminator
    size_t charsCopied = 0;
    CheckResult(SUStringGetUTF8(suString, length, &stringBuffer[0], &charsCopied));

    CheckResult(SUStringRelease(&suString));
    return std::string(&stringBuffer[0]);
}

std::string SkpUtils::GetName(const SUComponentDefinitionRef& suComponentDefinition)
{
    SUStringRef suString = SU_INVALID;
    CheckResult(SUStringCreate(&suString));
    CheckResult(SUComponentDefinitionGetName(suComponentDefinition, &suString));
    return ToString(std::move(suString));
}

std::string SkpUtils::GetName(const SUComponentInstanceRef& suComponentInstance)
{
    SUStringRef suString = SU_INVALID;
    CheckResult(SUStringCreate(&suString));
    CheckResult(SUComponentInstanceGetName(suComponentInstance, &suString));
    return ToString(std::move(suString));
}

std::string SkpUtils::GetName(const SUGroupRef& suGroup)
{
    SUStringRef suString = SU_INVALID;
    CheckResult(SUStringCreate(&suString));
    CheckResult(SUGroupGetName(suGroup, &suString));
    return ToString(std::move(suString));
}

std::string SkpUtils::GetName(const SUMaterialRef& suMaterial)
{
    SUStringRef suString = SU_INVALID;
    CheckResult(SUStringCreate(&suString));
    CheckResult(SUMaterialGetName(suMaterial, &suString));
    return ToString(std::move(suString));
}

std::string SkpUtils::GetComponentDefinitionGuid(const SUComponentDefinitionRef& componentDefinition)
{
    SUStringRef suString = SU_INVALID;
    CheckResult(SUStringCreate(&suString));
    CheckResult(SUComponentDefinitionGetGuid(componentDefinition, &suString));
    return ToString(std::move(suString));
}

bool SkpUtils::DrawingElementHasMaterial(const SUDrawingElementRef& currentElement)
{
    SUMaterialRef currentMaterial = SU_INVALID;
    return (SUDrawingElementGetMaterial(currentElement, &currentMaterial) == SU_ERROR_NONE);
}

bool SkpUtils::IsVisible(const SUDrawingElementRef& drawingElement)
{
    bool drawingElementHidden = false;
    CheckResult(SUDrawingElementGetHidden(drawingElement, &drawingElementHidden));
    if (drawingElementHidden)
    {
        return false;
    }

    SULayerRef layer = SU_INVALID;
    if (SUDrawingElementGetLayer(drawingElement, &layer) == SU_ERROR_NONE)
    {
        bool layerVisible = false;
        CheckResult(SULayerGetVisibility(layer, &layerVisible));

        if (!layerVisible)
        {
            return false;
        }
    }

    return true;
}

bool SkpUtils::IsVisible(const SUGroupRef& group)
{
    return IsVisible(SUGroupToDrawingElement(group));
}

bool SkpUtils::IsVisible(const SUComponentInstanceRef& componentInstance)
{
    return IsVisible(SUComponentInstanceToDrawingElement(componentInstance));
}

bool SkpUtils::IsVisible(const SUFaceRef& face)
{
    return IsVisible(SUFaceToDrawingElement(face));
}

bool SkpUtils::IsVisible(const SUEdgeRef& edge)
{
    return IsVisible(SUEdgeToDrawingElement(edge));
}

long SkpUtils::GetTextureId(const SUTextureWriterRef& suTextureWriterRef, const SUFaceRef& suFaceRef, SUDrawingElementRef ancestorElement, Side side)
{
    long textureIdFront = 0, textureIdBack = 0;
    SUTextureWriterLoadFace(suTextureWriterRef, suFaceRef, &textureIdFront, &textureIdBack);

    long textureId = side == SkpUtils::Side::Front ? textureIdFront : textureIdBack;

    // If are unable to get a valid texture id, try pulling the texture from the ancestor element
    // Note: According to Sketchup, the texture id is only valid if its value is a positive integer that is greater than zero.
    if (textureId <= 0)
    {
        SkpUtils::CheckResult(SUTextureWriterLoadEntity(suTextureWriterRef, SUDrawingElementToEntity(ancestorElement), &textureId));
    }

    return textureId;
}

int32_t SkpUtils::GetRenderingOptionValue(SURenderingOptionsRef renderingOptions, const char* key)
{
    int32_t value = 0;
    SUTypedValueRef optionRef = SU_INVALID;

    CheckResult(SUTypedValueCreate(&optionRef));
    CheckResult(SURenderingOptionsGetValue(renderingOptions, key, &optionRef));
    CheckResult(SUTypedValueGetInt32(optionRef, &value));
    CheckResult(SUTypedValueRelease(&optionRef));

    return value;
}

Math::Vector3 SkpUtils::ToVector3(const SUVector3D& suVector3d)
{
    return Math::Vector3(
        static_cast<float>(suVector3d.x),
        static_cast<float>(suVector3d.y),
        static_cast<float>(suVector3d.z)
    );
}

Math::Vector3 SkpUtils::ToVector3(const SUPoint3D& suPoint3d)
{
    return Math::Vector3(
        static_cast<float>(suPoint3d.x),
        static_cast<float>(suPoint3d.y),
        static_cast<float>(suPoint3d.z)
    );
}

Math::Matrix SkpUtils::ToMatrix(const SUTransformation& suTransform)
{
    float transformValues[16];
    std::transform(suTransform.values, suTransform.values + 16, transformValues, [](double d) { return static_cast<float>(d); });

    return Math::Matrix(transformValues);
}

Math::Color SkpUtils::ToColor(const SUColor& suColor)
{
    return Math::Color(
        suColor.red   / 255.0f,
        suColor.green / 255.0f,
        suColor.blue  / 255.0f,
        suColor.alpha / 255.0f
    );
}

Math::Color SkpUtils::ToColor(SUTypedValueRef&& suTypedValueRef)
{
    SUColor colorValue;
    CheckResult(SUTypedValueGetColor(suTypedValueRef, &colorValue));
    CheckResult(SUTypedValueRelease(&suTypedValueRef));
    return ToColor(colorValue);
}

Math::Color SkpUtils::GetMaterialColor(const SUMaterialRef& suMaterial)
{
    SUColor colorValue;
    CheckResult(SUMaterialGetColor(suMaterial, &colorValue));
    return ToColor(colorValue);
}

Math::Matrix SkpUtils::GetTransform(const SUGroupRef& group)
{
    SUTransformation suTransform;
    CheckResult(SUGroupGetTransform(group, &suTransform));
    return ToMatrix(suTransform);
}

Math::Matrix SkpUtils::GetTransform(const SUComponentInstanceRef& componentInstance)
{
    SUTransformation suTransform;
    CheckResult(SUComponentInstanceGetTransform(componentInstance, &suTransform));
    return ToMatrix(suTransform);
}

Asset3D::UnitInCentimeter SkpUtils::GetUnitInCentimeter(const SUModelRef& suModel)
{
    SUModelUnits suModelUnits;
    CheckResult(SUModelGetUnits(suModel, &suModelUnits));
    return SUModelUnitsToUnitInCentimeter(suModelUnits);
}

Asset3D::UnitInCentimeter SkpUtils::SUModelUnitsToUnitInCentimeter(const SUModelUnits& suModelUnits)
{
    switch (suModelUnits)
    {
    case SUModelUnits_Inches:
        return Asset3D::SYSTEMUNIT_INCH;

    case SUModelUnits_Feet:
        return Asset3D::SYSTEMUNIT_FOOT;

    case SUModelUnits_Millimeters:
        return Asset3D::SYSTEMUNIT_MILLIMETER;

    case SUModelUnits_Centimeters:
        return Asset3D::SYSTEMUNIT_CENTIMETER;

    case SUModelUnits_Meters:
        return Asset3D::SYSTEMUNIT_METER;

    default:
        throw BabylonException("Unrecognized SUModelUnits value");
    }
}

std::shared_ptr<MaterialDescriptor> SkpUtils::GetDefaultMaterial(const SURenderingOptionsRef& suRenderingOptions, SkpUtils::Side side)
{
    BabylonAssert(side != SkpUtils::Side::Both);

    SUTypedValueRef value = SU_INVALID;
    CheckResult(SUTypedValueCreate(&value));

    const char* faceColorKey = side == SkpUtils::Side::Front ? "FaceFrontColor" : "FaceBackColor";
    CheckResult(SURenderingOptionsGetValue(suRenderingOptions, faceColorKey, &value));

    auto material = std::make_shared<MaterialDescriptor>(false);
    material->SetName(side == SkpUtils::Side::Front ? "DefaultMaterialFront" : "DefaultMaterialBack");
    material->AddLayer(LayerType::kBaseColor)->SetColor(ToColor(std::move(value)));
    material->AddLayer(LayerType::kMetallicRoughness)->SetColor({ 0.0f, 1.0f, 0.0f, 0.0f });
    material->SetRenderingMode(RenderingMode::Opaque);
    material->SetRenderingOption(RenderingOption::GLTFMaterial);
    material->SetRenderingOption(RenderingOption::SingleSided);

    return material;
}

SUMaterialRef SkpUtils::GetEffectiveMaterial(const SUFaceRef& face, SkpUtils::Side side, SUDrawingElementRef ancestorElement)
{
    BabylonAssert(side != SkpUtils::Side::Both);

    SUMaterialRef material = SU_INVALID;
    if (side == SkpUtils::Side::Front)
    {
        SUFaceGetFrontMaterial(face, &material);
    }
    else
    {
        SUFaceGetBackMaterial(face, &material);
    }

    if (SUIsInvalid(material) && SUIsValid(ancestorElement))
    {
        SUMaterialRef ancestorMaterial = SU_INVALID;
        CheckResult(SUDrawingElementGetMaterial(ancestorElement, &ancestorMaterial));
        BabylonAssert(SUIsValid(ancestorMaterial));
        material = ancestorMaterial;
    }

    return material;
}

std::shared_ptr<MaterialDescriptor> SkpUtils::GetDefaultMaterialEdge()
{
    auto material = std::make_shared<MaterialDescriptor>(false);
    material->SetName("DefaultMaterialEdge");
    material->AddLayer(LayerType::kBaseColor)->SetColor(Math::Color(Math::Color::Black));
    material->AddLayer(LayerType::kMetallicRoughness)->SetColor({ 0.0f, 1.0f, 0.0f, 0.0f });
    material->SetRenderingOption(RenderingOption::GLTFMaterial);
    material->SetRenderingOption(RenderingOption::SingleSided);
    material->SetRenderingMode(RenderingMode::Opaque);

    return material;
}

#endif