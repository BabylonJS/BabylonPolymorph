/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <numeric>

#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/SceneNode.h>
#include <Asset3D/TextureDescriptor.h>

// NOTE: "SceneNode" is used by Engine, so we need to use something else here
DEFINE_TRACE_AREA(Asset3D_SceneNode, 0);

using namespace Babylon::Transcoder;

SceneNode::SceneNode(const Babylon::Utils::Math::Matrix& transform, const BoundingBox& boundingBox)
    : ITraversableWithName(), m_transform(transform), m_boundingBox(boundingBox)
{
}

SceneNode::SceneNode()
    : SceneNode(Babylon::Utils::Math::Matrix::Identity, BoundingBox::Zero)
{
}

std::shared_ptr<SceneNode> SceneNode::Clone() const
{
    auto clone = std::make_shared<SceneNode>();

    // ITraversable & ITraversableWithName
    clone->SetExtras(GetExtras());
    clone->SetExtensions(GetExtensions());
    clone->SetName(GetName());

    clone->m_transform = m_transform;
    clone->m_boundingBox = m_boundingBox;

    // Children are also SceneNodes, so must be individually cloned
    for (const auto& child : m_children)
    {
        clone->m_children.push_back(child->Clone()); 
    }

    clone->m_mesh         = m_mesh;
    clone->m_camera       = m_camera;
    clone->m_skeletonId   = m_skeletonId;
    clone->m_morphWeights = m_morphWeights;

    return clone;
}

size_t SceneNode::GetTriangleCount() const
{
    size_t result(0);
    for (auto child : m_children)
    {
        result += child->GetTriangleCount();
    }

    if (m_mesh)
    {
        result += m_mesh->GetTriangleCount();
    }

    return result;
}

BoundingBox SceneNode::CalcTopDownBounds(const Babylon::Utils::Math::Matrix& transform) const
{
    BoundingBox box;
    Utils::Math::Matrix ourTransform = GetTransform()*transform;
    for (auto child : m_children)
    {
        box.Update(child->CalcTopDownBounds(ourTransform));
    }

    if (m_mesh)
    {
        box.Update(m_mesh->CalcTopDownBounds(ourTransform));
    }
    return box;
}

void SceneNode::CalculateBoundingBox()
{
    m_boundingBox = BoundingBox::Uninitialized;

    for (auto child : m_children)
    {
        child->CalculateBoundingBox();
        BoundingBox childBoundingBox = child->GetBoundingBox();
        childBoundingBox.Transform(child->GetTransform());
        m_boundingBox.Update(childBoundingBox);
    }

    if (m_mesh)
    {
        m_mesh->CalculateBoundingBox();
        m_boundingBox.Update(m_mesh->GetBoundingBox());
    }
}

bool SceneNode::Compare(SceneNode const& other) const
{
    bool areEqual = true;

    TRACE_INFO(Asset3D_SceneNode, "Started Comparing Nodes with id=%u and id=%u.", GetId(), other.GetId());

    if (GetTransform() == other.GetTransform())
    {
        TRACE_INFO(Asset3D_SceneNode, "Transformation is the same.");
    }
    else
    {
        areEqual = false;
        TRACE_INFO(Asset3D_SceneNode, "Transformation is different.");
        auto trans = GetTransform();
        TRACE_INFO(Asset3D_SceneNode, "[%f,%f,%f](ours)", trans[0], trans[1], trans[2]);
        trans = other.GetTransform();
        TRACE_INFO(Asset3D_SceneNode, "[%f,%f,%f](theirs)", trans[0], trans[1], trans[2]);
    }

    if (GetBoundingBox() == other.GetBoundingBox())
    {
        TRACE_INFO(Asset3D_SceneNode, "Bounding boxes are the same.")
    }
    else
    {
        areEqual = false;
        TRACE_INFO(Asset3D_SceneNode, "Bounding boxes are different.");
        auto bb = GetBoundingBox();
        TRACE_INFO(Asset3D_SceneNode, "[%f,%f,%f]-[%f,%f,%f] (ours)", bb.GetCenter()[0], bb.GetCenter()[1], bb.GetCenter()[2],
                                                                bb.GetExtents()[0], bb.GetExtents()[1], bb.GetExtents()[2]);
        bb = other.GetBoundingBox();
        TRACE_INFO(Asset3D_SceneNode, "[%f,%f,%f]-[%f,%f,%f] (theirs)", bb.GetCenter()[0], bb.GetCenter()[1], bb.GetCenter()[2],
                                                                bb.GetExtents()[0], bb.GetExtents()[1], bb.GetExtents()[2]);
    }

    auto otherChildren = other.m_children;
    if (m_children.size() != otherChildren.size())
    {
        TRACE_INFO(
            Asset3D_SceneNode,
            "Nodes with id=%u and id=%u do not have the same number of children. %zu vs %zu",
            GetId(),
            other.GetId(),
            m_children.size(),
            otherChildren.size());
        return false;
    }

    for (size_t i = 0; i < m_children.size(); ++i)
    {
        auto child = m_children[i];
        auto otherChild = other.m_children[i];
        areEqual &= child->Compare(otherChild.get());
    }

    if (m_mesh && other.m_mesh)
    {
        // If both this and other have a mesh, compare
        areEqual &= m_mesh->Compare(*other.m_mesh);
    }
    else if (m_mesh || other.m_mesh)
    {
        // Either this or other has a mesh, but not both
        return false;
    }

    return areEqual;
}

bool SceneNode::HasNonTriangleGeometry() const
{
    if (m_mesh)
    {
        for (const auto& geo : m_mesh->GetGeometries())
        {
            if (geo.GetTopology() != GeometryTopology::kTriangles)
            {
                return true;
            }
        }
    }

    for (const auto& child : m_children)
    {
        if (child->HasNonTriangleGeometry())
        {
            return true;
        }
    }

    return false;
}

bool SceneNode::Compare(SceneNode const* other) const
{
    if (!other)
    {
        TRACE_INFO(Asset3D_SceneNode, "Comparing an Asset to a null Asset is not valid.");
        return false;
    }

    return Compare(*other);
}

size_t SceneNode::GetVertexCount() const
{
    size_t totalVertices = 0;
    for (auto& child : m_children)
    {
        totalVertices += child->GetVertexCount();
    }

    if (m_mesh)
    {
        totalVertices += m_mesh->GetVertexCount();
    }
    return totalVertices;
}

size_t SceneNode::GetVertexBufferMemory() const
{
    size_t size = 0;
    for (auto& child : m_children)
    {
        size += child->GetVertexBufferMemory();
    }

    if (m_mesh)
    {
        for (auto& geometry : m_mesh->GetGeometries())
        {
            size += geometry.GetVertexBufferSize();
        }
    }
    return size;
}

size_t SceneNode::GetIndexCount() const
{
    size_t totalIndex = 0;
    for (auto& child : m_children)
    {
        totalIndex += child->GetIndexCount();
    }

    if (m_mesh)
    {
        totalIndex += m_mesh->GetIndexCount();
    }
    return totalIndex;
}

size_t SceneNode::GetIndexBufferMemory() const
{
    size_t size = 0;
    for (auto& child : m_children)
    {
        size += child->GetIndexBufferMemory();
    }

    if (m_mesh)
    {
        for (auto& geometry : m_mesh->GetGeometries())
        {
            size += sizeof(uint32_t) * geometry.GetIndexCount();
        }
    }
    return size;
}

size_t SceneNode::GetTextureCount() const
{
    return GetUniqueTextures().size();
}

size_t SceneNode::GetTextureMemory() const
{
    size_t memory = 0;
    auto textures = GetUniqueTextures();

    for (const auto& texture : GetUniqueTextures())
    {
        memory += texture->GetSizeInBytes();
    }

    return memory;
}

const std::shared_ptr<Camera> SceneNode::GetCamera() const
{
    return m_camera;
}

void SceneNode::SetCamera(std::shared_ptr<Camera> camera)
{
    m_camera = std::move(camera);
}

std::unordered_set<std::shared_ptr<TextureDescriptor>> SceneNode::GetUniqueTextures() const
{
    std::unordered_set<std::shared_ptr<TextureDescriptor>> textures;

    if (m_mesh)
    {
        for (const auto& geometry : m_mesh->GetGeometries())
        {
            if (geometry.GetMaterial()) {
                for (auto& texture : geometry.GetMaterial()->GetTextures())
                {
                    textures.insert(texture.second);
                }
            }
        }
    }

    for (const auto& child : m_children)
    {
        auto childTextures = child->GetUniqueTextures();
        textures.insert(
            std::make_move_iterator(childTextures.begin()),
            std::make_move_iterator(childTextures.end()));
    }

    return textures;
}