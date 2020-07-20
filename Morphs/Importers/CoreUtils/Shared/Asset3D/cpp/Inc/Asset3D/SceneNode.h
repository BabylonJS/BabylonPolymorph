/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <queue>
#include <unordered_set>

#include <Asset3D/Mesh.h>
#include <Asset3D/Animation.h>
#include <Asset3D/BoundingBox.h>
#include <Asset3D/ITraversable.h>

namespace Babylon
{
    namespace Transcoder
    {
        class MaterialDescriptor;
        class Mesh;
        class Camera;
        class Light;

        class SceneNode : public ITraversableWithName
        {
        public:
            SceneNode();
            SceneNode(const Babylon::Utils::Math::Matrix& transform, const BoundingBox& boundingBox);

            SceneNode(const SceneNode&) = delete;
            std::shared_ptr<SceneNode> Clone() const;

            void SetTransform(const Babylon::Utils::Math::Matrix& transform) { m_transform = transform; }
            const Babylon::Utils::Math::Matrix& GetTransform() const { return m_transform; }

            void SetBoundingBox(const BoundingBox& boundingBox) { m_boundingBox = boundingBox; }
            const BoundingBox& GetBoundingBox() const { return m_boundingBox; }

            // Children
            std::shared_ptr<SceneNode> CreateChildNode();
            std::shared_ptr<SceneNode> CreateChildNode(const Babylon::Utils::Math::Matrix& transform, const BoundingBox& boundingBox);
            void AddChildNode(std::shared_ptr<SceneNode> childNode) { m_children.push_back(std::move(childNode)); }
            const std::vector<std::shared_ptr<SceneNode>>& GetChildren() const { return m_children; }

            // Mesh
            const std::shared_ptr<Mesh>& GetMesh() const { return m_mesh; }
            void SetMesh(std::shared_ptr<Mesh> mesh) { m_mesh = std::move(mesh); }
            bool HasMesh() const { return static_cast<bool>(m_mesh); }
            const std::shared_ptr<Mesh>& CreateMesh() { return (m_mesh = std::make_shared<Mesh>()); }

            // Bounding Box
            inline void SetBoundingBoxAndTransform(const BoundingBox& boundingBox, const Babylon::Utils::Math::Matrix& transform);
            void CalculateBoundingBox();
            virtual BoundingBox CalcTopDownBounds(const Babylon::Utils::Math::Matrix&) const;

            bool HasNonTriangleGeometry() const;

            size_t GetNodeCount() const { return m_children.size(); }
            size_t GetMeshCount() const { return m_mesh ? 1 : 0; }
            size_t GetGeometryCount() const { return m_mesh ? m_mesh->GetGeometries().size() : 0; }
            size_t GetTriangleCount() const;

            size_t GetTotalNodeCount() const { return TotalCount(&SceneNode::GetNodeCount); }
            size_t GetTotalGeometryCount() const { return TotalCount(&SceneNode::GetGeometryCount); }
            size_t GetTotalMeshCount() const { return TotalCount(&SceneNode::GetMeshCount); }
            size_t GetTotalTriangleCount() const { return TotalCount(&SceneNode::GetTriangleCount); }

            // Compares two SceneNodes for matching BoundingBox, Transform, and Hierarchy.
            bool Compare(const SceneNode& other) const;
            bool Compare(const SceneNode* other) const;

            size_t GetVertexCount() const;
            size_t GetVertexBufferMemory() const;

            size_t GetIndexCount() const;
            size_t GetIndexBufferMemory() const;

            size_t GetTextureCount() const;
            size_t GetTextureMemory() const;

            bool HasSkeleton() const { return m_skeletonId != Animation::NullSkeletonID; }
            Animation::SkeletonID GetSkeletonID() const { return m_skeletonId; }
            void SetSkeletonID(Animation::SkeletonID id) { m_skeletonId = id; }

            const std::shared_ptr<Camera> GetCamera() const;
            void SetCamera(std::shared_ptr<Camera> camera);

            const std::shared_ptr<Light> GetLight() const;
            void SetLight(std::shared_ptr<Light> light);

            const std::vector<float>& GetMorphWeights() const { return m_morphWeights; }
            void SetMorphWeights(const std::vector<float>& weights) { m_morphWeights = weights; }

            friend class Asset3D; // let Asset3D do anything as it sort of "owns" us

        protected:
            std::unordered_set<std::shared_ptr<TextureDescriptor>> GetUniqueTextures() const;
            inline size_t TotalCount(std::function<size_t(SceneNode const*)> countFn) const;

            Babylon::Utils::Math::Matrix m_transform;
            BoundingBox m_boundingBox;

            std::vector<std::shared_ptr<SceneNode>> m_children;
            std::shared_ptr<Mesh> m_mesh;
            std::shared_ptr<Camera> m_camera;
            std::shared_ptr<Light> m_light;
            Animation::SkeletonID m_skeletonId = Animation::NullSkeletonID;

            std::vector<float> m_morphWeights;
        };

        class ISceneNodeUtils
        {
        public:
            template<typename Fn>
            static void BFS(const SceneNode* root, Fn fnCallback)
            {
                std::queue<const SceneNode*> nodeQueue;
                nodeQueue.push(root);

                while (!nodeQueue.empty())
                {
                    const SceneNode* const sceneNode = nodeQueue.front(); nodeQueue.pop();

                    if (fnCallback(sceneNode))
                    {
                        for (const auto& it : sceneNode->GetChildren())
                        {
                            nodeQueue.push(it.get());
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }

            template<typename Fn>
            static void DFS(const SceneNode* root, Fn fnCallback, const SceneNode* parent = nullptr)
            {
                fnCallback(root, parent);

                for (const auto& node : root->GetChildren())
                {
                    DFS(node.get(), fnCallback, root);
                }
            }
        };
    }
}

inline void Babylon::Transcoder::SceneNode::SetBoundingBoxAndTransform(const BoundingBox& boundingBox, const Babylon::Utils::Math::Matrix& transform)
{
    m_boundingBox = boundingBox;
    m_transform = transform;
}

inline std::shared_ptr<Babylon::Transcoder::SceneNode> Babylon::Transcoder::SceneNode::CreateChildNode(
    const Babylon::Utils::Math::Matrix& transform,
    const BoundingBox& boundingBox)
{
    auto child = std::make_shared<SceneNode>(transform, boundingBox);
    m_children.push_back(child);
    return child;
}

inline std::shared_ptr<Babylon::Transcoder::SceneNode> Babylon::Transcoder::SceneNode::CreateChildNode()
{
    auto child = std::make_shared<SceneNode>();
    m_children.push_back(child);
    return child;
}

inline size_t Babylon::Transcoder::SceneNode::TotalCount(std::function<size_t(Babylon::Transcoder::SceneNode const*)> countFn) const
{
    size_t ret = countFn(this);
    for (const auto& child : m_children)
    {
        ret += child->TotalCount(countFn);
    }

    return ret;
}