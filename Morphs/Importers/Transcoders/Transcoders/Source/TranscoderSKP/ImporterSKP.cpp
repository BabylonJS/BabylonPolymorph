/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TranscodersPch.h"
#include "ImporterSKP.h"

#include <CoreUtils/Platform.h>
#if CANVAS_CAN_USE_SKP()

#include <SketchUpAPI/common.h>
#include <SketchUpAPI/initialize.h>
#include <SketchUpAPI/model/component_definition.h>
#include <SketchUpAPI/model/component_instance.h>
#include <SketchUpAPI/model/drawing_element.h>
#include <SketchupAPI/model/edge.h>
#include <SketchUpAPI/model/entities.h>
#include <SketchupAPI/geometry.h>
#include <SketchupAPI/geometry/vector3d.h>
#include <SketchUpAPI/model/group.h>
#include <SketchUpAPI/model/layer.h>
#include <SketchUpAPI/model/loop.h>
#include <SketchUpAPI/model/image_rep.h>
#include <SketchUpAPI/model/material.h>
#include <SketchUpAPI/model/mesh_helper.h>
#include <SketchUpAPI/model/rendering_options.h>
#include <SketchUpAPI/model/typed_value.h>
#include <SketchUpAPI/model/uv_helper.h>
#include <SketchupAPI/model/vertex.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>
#include <CoreUtils/Memory.h>
#include <CoreUtils/StreamUtils.h>
#include <CoreUtils/Trace.h>

#include <PluginSKP/PluginSKP.h>

using namespace Babylon::Transcoder;
using namespace Babylon::Utils;

DEFINE_TRACE_AREA(ImporterSKP, 0);

namespace
{
    // Turn STQ data into UV floats (V is inverted)
    // https://forums.sketchup.com/t/how-to-map-stq-to-st/8843/6
    Babylon::Utils::Math::Vector2 ToVector2UV(const SUPoint3D& point)
    {
        // point.x = S, point.y = T, point.z = Q
        return Babylon::Utils::Math::Vector2(
            static_cast<float>( point.x / point.z), //  S/Q
            static_cast<float>(-point.y / point.z)  // -T/Q
        );
    }

    // Note: SKP and Asset3D use different coordinate systems and we need to convert between the two.
    // This function provides the rotation matrix to do that.
    // SketchUp uses a right-handed system with positive X facing out of the screen and positive Y to the right
    // Viewer uses a left-handed sytem with positive X facing out of the screen and positive Y up
    Babylon::Utils::Math::Matrix GetCoordinateSystemTransformationMatrix()
    {
        return Babylon::Utils::Math::Matrix(
           -1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f
        );
    }
}

ImporterSKP::~ImporterSKP()
{
    if (SUIsValid(m_suModel))
    {
        SUModelRelease(&m_suModel);
    }

    if (SUIsValid(m_suTextureWriter))
    {
        SUTextureWriterRelease(&m_suTextureWriter);
    }

    // Terminate the API when done using it
    SUTerminate();
}

// Build an Asset3d from a SketchUp model (buffer data)
std::shared_ptr<Asset3D> ImporterSKP::ImportToAsset3D(std::shared_ptr<std::istream> stream, UpdateReporter* progress, Babylon::Framework::ICancellationTokenPtr cancellationToken)
{
    // Note: there are only two ways to load a Sketchup file:
    //   a) SUModelCreateFromFile   (takes an absolute file path)
    //   b) SUModelCreateFromBuffer (takes a buffer)
    // We have to use SUModelCreateFromBuffer because we will not always know the absolute file path,
    // therefore we must read the whole stream into memory
    size_t length = 0;
    auto data = Babylon::Utils::ReadStreamIntoUniquePtr(*stream, length);

    // Initialize SketchUp API
    SUInitialize();
    m_cancellationToken = cancellationToken;

    m_progressReporter = progress;

    // Load the model from the buffer
    SkpUtils::CheckResult(SUModelCreateFromBuffer(&m_suModel, data.get(), length));
    SkpUtils::CheckResult(SUTextureWriterCreate(&m_suTextureWriter));
    SkpUtils::CheckResult(SUModelGetRenderingOptions(m_suModel, &m_suRenderingOptions));

    // Create the root of the asset3d object
    auto asset3d = std::make_shared<Asset3D>();

    // Set the Asset3D system unit
    asset3d->SetSystemUnit(SkpUtils::GetUnitInCentimeter(m_suModel));

    // Set required model transform (coordinate switch + translation to origin + camera roll compensation)
    asset3d->SetTransform(GetCoordinateSystemTransformationMatrix());

    // TODO: Add the SKP scene's camera to the asset3d

    // Export the model
    ExportModel(*asset3d);

    return asset3d;
}

// Methods to walk the model and load the geometry, uvs, and materials/textures
void ImporterSKP::ExportModel(SceneNode& sceneNode)
{
    // Get the model to export
    SUEntitiesRef m_suModelentities;
    SkpUtils::CheckResult(SUModelGetEntities(m_suModel, &m_suModelentities));

    CountEntities(m_suModelentities);
    ExportEntities(m_suModelentities, sceneNode, SU_INVALID);
    m_progressReporter->ReportCompletedParsing(1.0f);
}

void ImporterSKP::CountEntities(SUEntitiesRef entities)
{
    // Groups
    size_t groupCount = 0;
    SkpUtils::CheckResult(SUEntitiesGetNumGroups(entities, &groupCount));
    if (groupCount > 0)
    {
        std::vector<SUGroupRef> groups(groupCount);
        SkpUtils::CheckResult(SUEntitiesGetGroups(entities, groupCount, groups.data(), &groupCount));

        for (auto group : groups)
        {
            if (SkpUtils::IsVisible(group))
            {
                CountGroup(group);
            }
        }
    }

    // Component Instances
    size_t instanceCount = 0;
    SkpUtils::CheckResult(SUEntitiesGetNumInstances(entities, &instanceCount));
    if (instanceCount > 0)
    {
        std::vector<SUComponentInstanceRef> instances(instanceCount);
        SkpUtils::CheckResult(SUEntitiesGetInstances(entities, instanceCount, instances.data(), &instanceCount));

        for (auto instance : instances)
        {
            if (SkpUtils::IsVisible(instance))
            {
                CountComponentInstance(instance);
            }
        }
    }

    // Faces
    size_t faceCount = 0;
    SkpUtils::CheckResult(SUEntitiesGetNumFaces(entities, &faceCount));
    m_totalEntities += faceCount;

    // Edges
    auto edgeDisplayMode = static_cast<SkpUtils::EdgeDisplayMode>(SkpUtils::GetRenderingOptionValue(m_suRenderingOptions, "EdgeDisplayMode"));
    if (edgeDisplayMode != SkpUtils::EdgeDisplayMode::NoEdges)
    {
        bool standaloneOnly = (edgeDisplayMode == SkpUtils::EdgeDisplayMode::StandaloneOnly);
        size_t edgeCount = 0;
        SkpUtils::CheckResult(SUEntitiesGetNumEdges(entities, standaloneOnly, &edgeCount));
        
        m_totalEntities += edgeCount;
    }
}

void ImporterSKP::CountGroup(SUGroupRef group)
{
    // Export the children of this SUGroupRef
    SUEntitiesRef suEntities = SU_INVALID;
    SkpUtils::CheckResult(SUGroupGetEntities(group, &suEntities));
    CountEntities(suEntities);
}

void ImporterSKP::CountComponentInstance(SUComponentInstanceRef componentInstance)
{
    SUComponentDefinitionRef componentDefinition = SU_INVALID;
    SkpUtils::CheckResult(SUComponentInstanceGetDefinition(componentInstance, &componentDefinition));
    auto componentDefinitionGuid = SkpUtils::GetComponentDefinitionGuid(componentDefinition);

    auto it = m_componentDefinitions.find(componentDefinitionGuid);
    if (it == m_componentDefinitions.end())
    {
        SUEntitiesRef entities = SU_INVALID;
        SkpUtils::CheckResult(SUComponentDefinitionGetEntities(componentDefinition, &entities));
        CountEntities(entities);
    }
}

// Documentation: https://help.sketchup.com/en/working-components-sketchup
// Group:     a single instance of a collection of geometry.
// Component: a named collection of geometry that can exist at multiple locations within the model. Each instance
//            is a repetition of all others. A change to one instance changes all other instances.
//
// This function is called recursively, working down through groups, components, and then faces (which can be in
// a Group, ComponentInstance, or both). Example hierarchy:
//
// Model
//    Group(1)
//       ComponentInstance(A)
//           Faces(A)
//    Group(2)
//       ComponentInstance(A)
//           Faces(A)
//    Faces(B)
//
// See also: void CSkpExporter::ExportEntities(SUEntitiesRef entities)
void ImporterSKP::ExportEntities(SUEntitiesRef entities, SceneNode& sceneNode, SUDrawingElementRef ancestorElement)
{
    // Groups
    size_t groupCount = 0;
    SkpUtils::CheckResult(SUEntitiesGetNumGroups(entities, &groupCount));
    if (groupCount > 0)
    {
        std::vector<SUGroupRef> groups(groupCount);
        SkpUtils::CheckResult(SUEntitiesGetGroups(entities, groupCount, groups.data(), &groupCount));

        for (auto group : groups)
        {
            if (SkpUtils::IsVisible(group))
            {
                ExportGroup(group, sceneNode, ancestorElement);
            }
        }
    }

    // Component Instances
    size_t instanceCount = 0;
    SkpUtils::CheckResult(SUEntitiesGetNumInstances(entities, &instanceCount));
    if (instanceCount > 0)
    {
        std::vector<SUComponentInstanceRef> instances(instanceCount);
        SkpUtils::CheckResult(SUEntitiesGetInstances(entities, instanceCount, instances.data(), &instanceCount));

        for (auto instance : instances)
        {
            if (SkpUtils::IsVisible(instance))
            {
                ExportComponentInstance(instance, sceneNode, ancestorElement);
            }
        }
    }

    auto mesh = std::make_shared<Mesh>();

    // Faces
    size_t faceCount = 0;
    SkpUtils::CheckResult(SUEntitiesGetNumFaces(entities, &faceCount));
    if (faceCount > 0)
    {
        std::vector<SUFaceRef> faces(faceCount);
        SkpUtils::CheckResult(SUEntitiesGetFaces(entities, faceCount, faces.data(), &faceCount));

        ExportFaces(*mesh, faces, ancestorElement);
    }

    // Edges
    auto edgeDisplayMode = static_cast<SkpUtils::EdgeDisplayMode>(SkpUtils::GetRenderingOptionValue(m_suRenderingOptions, "EdgeDisplayMode"));
    if (edgeDisplayMode != SkpUtils::EdgeDisplayMode::NoEdges)
    {
        bool standaloneOnly = (edgeDisplayMode == SkpUtils::EdgeDisplayMode::StandaloneOnly);
        size_t edgeCount = 0;
        SkpUtils::CheckResult(SUEntitiesGetNumEdges(entities, standaloneOnly, &edgeCount));
        if (edgeCount > 0)
        {
            std::vector<SUEdgeRef> edges(edgeCount);
            SkpUtils::CheckResult(SUEntitiesGetEdges(entities, standaloneOnly, edgeCount, edges.data(), &edgeCount));
            ExportEdges(*mesh, edges);
        }
    }

    if (!mesh->GetGeometries().empty())
    {
        sceneNode.SetMesh(std::move(mesh));
    }

    // TODO: Sample SKP Exporter also exports 'Images', is this relevant?
    //    SUEntitiesGetNumImages + SUEntitiesGetImages
}

void ImporterSKP::ExportGroup(SUGroupRef group, SceneNode& parentNode, SUDrawingElementRef ancestorElement)
{
    // Create an Asset3D::SceneNode for this SUGroupRef and set the transform
    auto sceneNode = parentNode.CreateChildNode();
    sceneNode->SetName(SkpUtils::GetName(group));
    sceneNode->SetTransform(SkpUtils::GetTransform(group));

    SUDrawingElementRef currentElement = SUGroupToDrawingElement(group);

    // If the current element doesn't have a valid material, use the ancestor element instead
    if (!SkpUtils::DrawingElementHasMaterial(currentElement))
    {
        currentElement = ancestorElement;
    }

    // Export the children of this SUGroupRef
    SUEntitiesRef suEntities = SU_INVALID;
    SkpUtils::CheckResult(SUGroupGetEntities(group, &suEntities));
    ExportEntities(suEntities, *sceneNode, currentElement);
}

void ImporterSKP::ExportComponentInstance(SUComponentInstanceRef componentInstance, SceneNode& parentNode, SUDrawingElementRef ancestorElement)
{
    auto name = SkpUtils::GetName(componentInstance);
    auto transform = SkpUtils::GetTransform(componentInstance);

    SUComponentDefinitionRef componentDefinition = SU_INVALID;
    SkpUtils::CheckResult(SUComponentInstanceGetDefinition(componentInstance, &componentDefinition));
    auto componentDefinitionGuid = SkpUtils::GetComponentDefinitionGuid(componentDefinition);

    auto it = m_componentDefinitions.find(componentDefinitionGuid);
    if (it == m_componentDefinitions.end())
    {
        // Create an Asset3D::SceneNode for this SUComponentInstanceRef and set the transform
        auto sceneNode = parentNode.CreateChildNode();
        sceneNode->SetName(name);
        sceneNode->SetTransform(transform);

        SUDrawingElementRef currentElement = SUComponentInstanceToDrawingElement(componentInstance);

        // If the current element doesn't have a valid material, use the ancestor element instead
        if (!SkpUtils::DrawingElementHasMaterial(currentElement))
        {
            currentElement = ancestorElement;
        }

        ExportComponentInstanceProvider(componentDefinition, *sceneNode, currentElement);
        m_componentDefinitions.insert({ componentDefinitionGuid, sceneNode });
    }
    else
    {
        auto definition = it->second;
        auto sceneNode = definition->Clone();
        sceneNode->SetName(name);
        sceneNode->SetTransform(transform);
        parentNode.AddChildNode(sceneNode);
    }
}

void ImporterSKP::ExportComponentInstanceProvider(SUComponentDefinitionRef componentDefinition, SceneNode& sceneNode, SUDrawingElementRef ancestorElement)
{
    SUEntitiesRef entities = SU_INVALID;
    SkpUtils::CheckResult(SUComponentDefinitionGetEntities(componentDefinition, &entities));
    ExportEntities(entities, sceneNode, ancestorElement);
}

void ImporterSKP::ExportFaces(Mesh& mesh, const std::vector<SUFaceRef>& faces, SUDrawingElementRef ancestorElement)
{
    typedef std::unordered_map<SUMaterialRef, std::vector<SUFaceRef>> MaterialToFaceMap;

    MaterialToFaceMap materialToFacesBoth;
    MaterialToFaceMap materialToFacesFront;
    MaterialToFaceMap materialToFacesBack;

    auto addFace = [](MaterialToFaceMap& materialToFaces, SUMaterialRef material, SUFaceRef face)
    {
        auto pair = materialToFaces.insert({ material, {} }).first;
        pair->second.push_back(face);
    };

    for (auto face : faces)
    {
        if (SkpUtils::IsVisible(face))
        {
            SUMaterialRef materialFront = SkpUtils::GetEffectiveMaterial(face, SkpUtils::Side::Front, ancestorElement);
            SUMaterialRef materialBack = SkpUtils::GetEffectiveMaterial(face, SkpUtils::Side::Back, ancestorElement);
            if (SUIsValid(materialFront) && SUIsValid(materialBack) && materialFront == materialBack)
            {
                addFace(materialToFacesBoth, materialFront, face);
            }
            else
            {
                addFace(materialToFacesFront, materialFront, face);
                addFace(materialToFacesBack, materialBack, face);
            }
        }

        auto visitedPercent = ++m_visitedEntities / static_cast<float>(m_totalEntities);
        m_progressReporter->ReportCompletedParsing(visitedPercent);
        m_cancellationToken->CheckCancelledAndThrow();
    }

    auto addGeometry = [&](MaterialToFaceMap& materialToFaces, SkpUtils::Side side)
    {
        for (const auto& pair : materialToFaces)
        {
            const auto& material = GetMaterial(pair.first, side, pair.second[0], ancestorElement);
            AddFacesGeometry(mesh, std::move(material), pair.second, side);
            m_cancellationToken->CheckCancelledAndThrow();
        }
    };

    addGeometry(materialToFacesBoth, SkpUtils::Side::Both);
    addGeometry(materialToFacesFront, SkpUtils::Side::Front);
    addGeometry(materialToFacesBack, SkpUtils::Side::Back);
}

void ImporterSKP::ExportEdges(Mesh& mesh, const std::vector<SUEdgeRef>& edges)
{
    std::vector<Vector3> positions;

    for (auto& edge : edges)
    {
        bool isSoft = false;
        bool isSmooth = false;
        SkpUtils::CheckResult(SUEdgeGetSoft(edge, &isSoft));
        SkpUtils::CheckResult(SUEdgeGetSmooth(edge, &isSmooth));

        // If the edge is visible and is neither a soft edge or a smooth one
        // Soft - "hides" the edge, but doesn't blend the shadows, because the edge is still there
        // Smooth - blends the shadows between the connected faces that share the edge
        if(SkpUtils::IsVisible(edge) && !isSoft && !isSmooth)
        {
            // Get Vertex data
            SUVertexRef startVert = SU_INVALID, endVert = SU_INVALID;
            SUPoint3D startPt = SU_INVALID, endPt = SU_INVALID;
            SkpUtils::CheckResult(SUEdgeGetStartVertex(edge, &startVert));
            SkpUtils::CheckResult(SUEdgeGetEndVertex(edge, &endVert));
            SkpUtils::CheckResult(SUVertexGetPosition(startVert, &startPt));
            SkpUtils::CheckResult(SUVertexGetPosition(endVert, &endPt));

            positions.push_back(SkpUtils::ToVector3(startPt));
            positions.push_back(SkpUtils::ToVector3(endPt));
        }

        auto visitedPercent = ++m_visitedEntities / static_cast<float>(m_totalEntities);
        m_progressReporter->ReportCompletedParsing(visitedPercent);
        m_cancellationToken->CheckCancelledAndThrow();
    }

    if (!positions.empty())
    {
        if (!m_defaultMaterialEdge)
        {
            m_defaultMaterialEdge = SkpUtils::GetDefaultMaterialEdge();
        }

        Geometry edgeGeometry(m_defaultMaterialEdge);
        edgeGeometry.SetTopology(GeometryTopology::kLines);
        edgeGeometry.SetPositions(positions);

        mesh.AddGeometry(std::move(edgeGeometry));
    }
}

void ImporterSKP::AddFacesGeometry(Mesh& mesh, std::shared_ptr<MaterialDescriptor> material, const std::vector<SUFaceRef>& faces, SkpUtils::Side side)
{
    bool hasTexture = static_cast<bool>(material->GetLayer(LayerType::kBaseColor)->Texture);
    Geometry geometry{ std::move(material) };

    for (const auto& face : faces)
    {
        SUMeshHelperRef meshHelper = SU_INVALID;
        SkpUtils::CheckResult(SUMeshHelperCreate(&meshHelper, face));

        size_t vertexCount = 0;
        SkpUtils::CheckResult(SUMeshHelperGetNumVertices(meshHelper, &vertexCount));
        if (vertexCount == 0)
        {
            TRACE_WARN(ImporterSKP, "Face with 0 vertices.");
            continue;
        }

        size_t triangleCount = 0;
        SkpUtils::CheckResult(SUMeshHelperGetNumTriangles(meshHelper, &triangleCount));
        if (triangleCount == 0)
        {
            TRACE_WARN(ImporterSKP, "Face with 0 triangles.");
            continue;
        }

        // Get triangle indices.
        const size_t indexCount = triangleCount * 3;
        size_t count = 0;

        std::vector<size_t> indices(indexCount);
        SkpUtils::CheckResult(SUMeshHelperGetVertexIndices(meshHelper, indexCount, indices.data(), &count));

        std::vector<SUPoint3D> positions(vertexCount);
        SkpUtils::CheckResult(SUMeshHelperGetVertices(meshHelper, vertexCount, positions.data(), &count));

        std::vector<SUVector3D> normals(vertexCount);
        SkpUtils::CheckResult(SUMeshHelperGetNormals(meshHelper, vertexCount, normals.data(), &count));

        std::vector<SUPoint3D> coords;
        if (hasTexture)
        {
            coords.resize(vertexCount);
            if (side == SkpUtils::Side::Front || side == SkpUtils::Side::Both)
            {
                SkpUtils::CheckResult(SUMeshHelperGetFrontSTQCoords(meshHelper, vertexCount, coords.data(), &count));
            }
            else
            {
                SkpUtils::CheckResult(SUMeshHelperGetBackSTQCoords(meshHelper, vertexCount, coords.data(), &count));
            }
        }

        SkpUtils::CheckResult(SUMeshHelperRelease(&meshHelper));

        for (size_t i = 0; i < indices.size(); i += 3)
        {
            auto index0 = indices[i];
            auto index1 = indices[i + 1];
            auto index2 = indices[i + 2];

            auto position0 = SkpUtils::ToVector3(positions[index0]);
            auto position1 = SkpUtils::ToVector3(positions[index1]);
            auto position2 = SkpUtils::ToVector3(positions[index2]);

            auto normal0 = SkpUtils::ToVector3(normals[index0]);
            auto normal1 = SkpUtils::ToVector3(normals[index1]);
            auto normal2 = SkpUtils::ToVector3(normals[index2]);

            if (side == SkpUtils::Side::Front || side == SkpUtils::Side::Both)
            {
                geometry.AddPosition(position0);
                geometry.AddPosition(position1);
                geometry.AddPosition(position2);

                geometry.AddNormal(normal0);
                geometry.AddNormal(normal1);
                geometry.AddNormal(normal2);

                if (hasTexture)
                {
                    geometry.AddUv0(ToVector2UV(coords[index0]));
                    geometry.AddUv0(ToVector2UV(coords[index1]));
                    geometry.AddUv0(ToVector2UV(coords[index2]));
                }
            }
            else
            {
                geometry.AddPosition(position0);
                geometry.AddPosition(position2);
                geometry.AddPosition(position1);

                geometry.AddNormal(-normal0);
                geometry.AddNormal(-normal2);
                geometry.AddNormal(-normal1);

                if (hasTexture)
                {
                    geometry.AddUv0(ToVector2UV(coords[index0]));
                    geometry.AddUv0(ToVector2UV(coords[index2]));
                    geometry.AddUv0(ToVector2UV(coords[index1]));
                }
            }
        }
    }

    if (geometry.HasPositions())
    {
        mesh.AddGeometry(std::move(geometry));
    }
}

std::shared_ptr<MaterialDescriptor> ImporterSKP::GetMaterial(SUMaterialRef suMaterial, SkpUtils::Side side, SUFaceRef suFace, SUDrawingElementRef ancestorElement)
{
    if (SUIsInvalid(suMaterial))
    {
        BabylonAssert(side != SkpUtils::Side::Both);
        auto& defaultMaterial = side == SkpUtils::Side::Front ? m_defaultMaterialFront : m_defaultMaterialBack;
        if (!defaultMaterial)
        {
            defaultMaterial = SkpUtils::GetDefaultMaterial(m_suRenderingOptions, side);
        }
        return defaultMaterial;
    }

    auto& materials = (side == SkpUtils::Side::Both ? m_materialsDoubleSided : m_materialsSingleSided);
    auto result = materials.insert({ suMaterial, nullptr });
    if (!result.second)
    {
        return result.first->second;
    }

    SUMaterialType suMaterialType;
    SkpUtils::CheckResult(SUMaterialGetType(suMaterial, &suMaterialType));

    auto material = std::make_shared<MaterialDescriptor>(false);
    material->SetName(SkpUtils::GetName(suMaterial));
    material->SetRenderingOption(RenderingOption::GLTFMaterial);
    if (side != SkpUtils::Side::Both)
    {
        material->SetRenderingOption(RenderingOption::SingleSided);
    }

    bool useOpacity = false;
    bool drawnTransparent = false;
    SkpUtils::CheckResult(SUMaterialGetUseOpacity(suMaterial, &useOpacity));
    SkpUtils::CheckResult(SUMaterialIsDrawnTransparent(suMaterial, &drawnTransparent));
    RenderingMode mode = (useOpacity || drawnTransparent) ? RenderingMode::Blend : RenderingMode::Opaque;
    material->SetRenderingMode(mode);
    material->AddLayer(LayerType::kMetallicRoughness)->SetColor({ 0.0f, 1.0f, 0.0f, 0.0f });

    auto baseColorLayer = material->AddLayer(LayerType::kBaseColor);
    switch (suMaterialType)
    {
    case SUMaterialType_Colored:
        baseColorLayer->SetColor(SkpUtils::GetMaterialColor(suMaterial).ToLinearRGB());
        break;

    case SUMaterialType_Textured:
        baseColorLayer->Texture = GetTexture(SkpUtils::GetTextureId(m_suTextureWriter, suFace, ancestorElement, side));
        if (useOpacity)
        {
            double alpha = 1.0;
            SUMaterialGetOpacity(suMaterial, &alpha);
            baseColorLayer->SetColor(Math::Color(1, 1, 1, static_cast<float>(alpha)));
        }
        break;

    case SUMaterialType_ColorizedTexture:
        baseColorLayer->SetColor(SkpUtils::GetMaterialColor(suMaterial).ToLinearRGB());
        baseColorLayer->Texture = GetTexture(SkpUtils::GetTextureId(m_suTextureWriter, suFace, ancestorElement, side));
        break;
    }

    result.first->second = std::move(material);

    return result.first->second;
}

std::shared_ptr<TextureDescriptor> ImporterSKP::GetTexture(long textureHandle)
{
    auto result = m_textures.insert({ textureHandle, nullptr });
    if (!result.second)
    {
        return result.first->second;
    }

    // Generate a new TextureDescriptor
    SUImageRepRef suImageRep = SU_INVALID;
    SkpUtils::CheckResult(SUImageRepCreate(&suImageRep));

    SkpUtils::CheckResult(SUTextureWriterGetImageRep(m_suTextureWriter, textureHandle, &suImageRep));

    // TODO: Is this necessary?
    SkpUtils::CheckResult(SUImageRepConvertTo32BitsPerPixel(suImageRep));

    size_t sizeInBytes = 0, bitsPerPixel = 0;
    SkpUtils::CheckResult(SUImageRepGetDataSize(suImageRep, &sizeInBytes, &bitsPerPixel));

    size_t width = 0, height = 0;
    SkpUtils::CheckResult(SUImageRepGetPixelDimensions(suImageRep, &width, &height));

    std::vector<SUByte> suTextureData(sizeInBytes);
    SkpUtils::CheckResult(SUImageRepGetData(suImageRep, sizeInBytes, suTextureData.data()));

    SkpUtils::CheckResult(SUImageRepRelease(&suImageRep));

    auto textureData = std::make_unique<uint8_t[]>(sizeInBytes);
    memcpy_s(textureData.get(), suTextureData.size(), suTextureData.data(), suTextureData.size());

    auto texture = std::make_shared<TextureDescriptor>(
        std::move(textureData),
        sizeInBytes,
        static_cast<uint32_t>(width),
        static_cast<uint32_t>(height),
        static_cast<uint32_t>(width * 4),
        Babylon::Framework::TextureSegment::EFormat::kFormatBGRA32
        );

    result.first->second = std::move(texture);

    return result.first->second;
}

#endif