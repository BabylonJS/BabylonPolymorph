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

#include <SketchUpAPI/model/component_instance.h>
#include <SketchUpAPI/model/face.h>

#include <CoreUtils/Math/SimpleMath.h>

#include <PluginSDK/UpdateReporter.h>

#include "SkpUtils.h"

namespace Babylon
{
    namespace Transcoder
    {
        class ImporterSKP
        {
        public:
            ~ImporterSKP();

            std::shared_ptr<Asset3D> ImportToAsset3D(std::shared_ptr<std::istream> stream, UpdateReporter* progress, Babylon::Framework::ICancellationTokenPtr cancellationToken);

        private:
            void ExportModel(SceneNode& sceneNode);
            void ExportEntities(SUEntitiesRef entities, SceneNode& sceneNode, SUDrawingElementRef ancestorElement);

            void ExportGroup(SUGroupRef group, SceneNode& sceneNode, SUDrawingElementRef ancestorElement);
            void ExportComponentInstance(SUComponentInstanceRef instance, SceneNode& sceneNode, SUDrawingElementRef ancestorElement);
            void ExportComponentInstanceProvider(SUComponentDefinitionRef definition, SceneNode& sceneNode, SUDrawingElementRef ancestorElement);

            void ExportFaces(Mesh& mesh, const std::vector<SUFaceRef>& faces, SUDrawingElementRef ancestorElement);
            void ExportEdges(Mesh& mesh, const std::vector<SUEdgeRef>& edges);

            void AddFacesGeometry(Mesh& mesh, std::shared_ptr<MaterialDescriptor> material, const std::vector<SUFaceRef>& faces, SkpUtils::Side side);

            std::shared_ptr<MaterialDescriptor> GetMaterial(SUMaterialRef suMaterial, SkpUtils::Side side, SUFaceRef suFace, SUDrawingElementRef ancestorElement);
            std::shared_ptr<TextureDescriptor> GetTexture(long textureHandle);

            void CountEntities(SUEntitiesRef entities);
            void CountGroup(SUGroupRef group);
            void CountComponentInstance(SUComponentInstanceRef instance);

        private:
            SUModelRef m_suModel = SU_INVALID;
            SUTextureWriterRef m_suTextureWriter = SU_INVALID;
            SURenderingOptionsRef m_suRenderingOptions = SU_INVALID;
            UpdateReporter* m_progressReporter;
            Babylon::Framework::ICancellationTokenPtr m_cancellationToken;
            size_t m_totalEntities = 0;
            size_t m_visitedEntities = 0;

            std::unordered_map<std::string, std::shared_ptr<SceneNode>> m_componentDefinitions;

            std::shared_ptr<MaterialDescriptor> m_defaultMaterialFront;
            std::shared_ptr<MaterialDescriptor> m_defaultMaterialBack;
            std::shared_ptr<MaterialDescriptor> m_defaultMaterialEdge;
 
            std::unordered_map<SUMaterialRef, std::shared_ptr<MaterialDescriptor>> m_materialsSingleSided;
            std::unordered_map<SUMaterialRef, std::shared_ptr<MaterialDescriptor>> m_materialsDoubleSided;

            std::unordered_map<long, std::shared_ptr<TextureDescriptor>> m_textures;
        };
    }
}

#endif