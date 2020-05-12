/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <Asset3D/Asset3D.h>
#include <Asset3D/SceneNode.h>
#include <Asset3D/Mesh.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>

namespace Babylon
{
    namespace Transcoder
    {
        class IAsset3DProcessor
        {
        public:
            /*
            * Process the Asset by traversing the hierarchy and processing individual components in two passes.
            *   - A downward pass in which every encountered node is processed and then its children.
            *   - An upward pass in which every node is processed and then its parent is processed.
            *     Leaf nodes are not processed during this pass.
            *
            * Call order:
            *     - ProcessAsset3DBeforeChildren
            *         - ProcessSceneNodeBeforeChildren
            *             - ProcessMeshBeforeMaterialAndGeometry
            *                 - ProcessMesh
            *                     - ProcessGeometry
            *                         - ProcessMaterial
            *                             - ProcessTexture
            *             - ProcessMeshAfterMaterialAndGeometry
            *         - ProcessSceneNodeAfterChildren
            *     - ProcessAsset3DAfterChildren
            */
            virtual ~IAsset3DProcessor() = default;

            // TODO: Can these methods pass by const-ref?

            // Processes the given Asset3D before its children are processed.
            // It is the first method to be called during an Asset3D processing.
            virtual void ProcessAsset3DBeforeChildren(Asset3D&) {}

            // Processes the given Asset3D after its children are processed.
            // It is the last method to be called during an Asset3D processing.
            virtual void ProcessAsset3DAfterChildren(Asset3D&) {}

            // Processes the given Scene Node before its children are processed.
            virtual void ProcessSceneNodeBeforeChildren(SceneNode&) {}

            // Processes the given Scene Node after its children are processed.
            virtual void ProcessSceneNodeAfterChildren(SceneNode&) {}

            // Processes the given Mesh before its children are processed.
            virtual void ProcessMeshBeforeMaterialAndGeometry(SceneNode&, Mesh&) {}

            // Processes the given Mesh after its children are processed.
            virtual void ProcessMeshAfterMaterialAndGeometry(SceneNode&, Mesh&) {}

            // Processes the given Mesh.
            virtual void ProcessMesh(SceneNode&, Mesh&) {}

            // Processes the given Geometry.
            virtual void ProcessGeometry(SceneNode&, Mesh&, Geometry&) {}

            // Processes the given Material before its children are processed.
            virtual void ProcessMaterial(MaterialDescriptor&) {}

            // Processes the given Texture.
            virtual void ProcessTexture(TextureDescriptor&) {}
        };
    }
}
