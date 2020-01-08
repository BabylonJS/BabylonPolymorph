/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <stack>
#include <set>

#include <Asset3D/IAsset3DProcessor.h>

namespace Spectre
{
    namespace Transcoder
    {
        class ExporterBase : public IAsset3DProcessor
        {
        public:
            virtual ~ExporterBase() {}

            void Export(Asset3D& asset);

            virtual void ProcessAsset3DBeforeChildren(Asset3D& asset3D) override;
            virtual void ProcessAsset3DAfterChildren(Asset3D& asset3D) override;
            virtual void ProcessSceneNodeBeforeChildren(SceneNode& sceneNode) override;
            virtual void ProcessSceneNodeAfterChildren(SceneNode& sceneNode) override;

            virtual void ProcessMeshBeforeMaterialAndGeometry(SceneNode& sceneNode, Mesh& mesh) override;
            virtual void ProcessMeshAfterMaterialAndGeometry(SceneNode& sceneNode, Mesh& mesh) override;

            virtual void ProcessMesh(SceneNode& sceneNode, Mesh& mesh) override;
            virtual void ProcessGeometry(SceneNode& sceneNode, Mesh& mesh, Geometry& geometry) override;
            virtual void ProcessMaterial(MaterialDescriptor& material) override;
            virtual void ProcessTexture(TextureDescriptor& texture) override;

        protected:
            virtual void ExportNodeDownwardPass(Asset3D&) {}
            virtual void ExportNodeUpwardPass(Asset3D&) {}

            virtual void ExportNodeDownwardPass(SceneNode&) {}
            virtual void ExportNodeUpwardPass(SceneNode&) {}

            virtual void ExportNodeDownwardPass(SceneNode&, Mesh&) {}
            virtual void ExportNodeUpwardPass(SceneNode&, Mesh&) {}

            virtual void ExportLeaf(Mesh&)                     {}
            virtual void ExportLeaf(Geometry&)                 {}
            virtual void ExportLeaf(MaterialDescriptor&)       {}
            virtual void ExportLeaf(TextureDescriptor&)        {}

            inline Utils::Math::Matrix GetGlobalTransform() const
            {
                return m_transforms.empty() ? Utils::Math::Matrix::Identity : m_transforms.top();
            }

            inline void PushTransform(Utils::Math::Matrix nodeTransform)
            {
                m_transforms.push(nodeTransform * GetGlobalTransform());
            }

            inline void PopTransform()
            {
                SpectreAssert(!m_transforms.empty());
                m_transforms.pop();
            }

            std::stack<Utils::Math::Matrix> m_transforms;

            // Keep track of which shared resources have already been exported to avoid duplications
            template<class T>
            bool TestAndSetAlreadyExported(std::set<T>& set,T item)
            {
                if(set.count(item) > 0)
                {
                    return true;
                }
                set.insert(item);
                return false;
            }
            std::set<MaterialDescriptor*> MaterialsExported;
            std::set<TextureDescriptor*> TexturesExported;
            std::set<Geometry*> GeometriesExported;
            std::set<Mesh*> MeshesExported;
        };
    }
}
