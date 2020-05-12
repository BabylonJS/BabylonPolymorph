/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

namespace Babylon
{
    namespace Transcoder
    {
        class IAsset3DProcessor;
        class Asset3D;
        class SceneNode;
        class Mesh;

        class Asset3DTraverser
        {
        public:
            void Traverse(IAsset3DProcessor& processor, Asset3D& asset3d);

            void Traverse(IAsset3DProcessor& processor, SceneNode& sceneNode);

            void Traverse(IAsset3DProcessor& processor, SceneNode& sceneNode, Mesh& mesh);

            size_t GetDepth() const;

        private:
            size_t m_depth = 0;
        };
    }
}
