/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <Asset3D/Asset3DTraverser.h>

#include <Asset3D/IAsset3DProcessor.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/SceneNode.h>
#include <Asset3D/Mesh.h>
#include <Asset3D/Geometry.h>
#include <Asset3D/MaterialDescriptor.h>
#include <Asset3D/TextureDescriptor.h>

void Babylon::Transcoder::Asset3DTraverser::Traverse(IAsset3DProcessor& processor, Asset3D& asset3d)
{
    processor.ProcessAsset3DBeforeChildren(asset3d);

    for (auto& child : asset3d.GetChildren())
    {
        m_depth++;
        Traverse(processor, *child);
        m_depth--;
    }

    if (asset3d.HasMesh())
    {
        Traverse(processor, asset3d, *asset3d.GetMesh());
    }

    processor.ProcessAsset3DAfterChildren(asset3d);
}

void Babylon::Transcoder::Asset3DTraverser::Traverse(IAsset3DProcessor& processor, SceneNode& sceneNode)
{
    processor.ProcessSceneNodeBeforeChildren(sceneNode);

    for (auto& child : sceneNode.GetChildren())
    {
        m_depth++;
        Traverse(processor, *child);
        m_depth--;
    }

    if (sceneNode.HasMesh())
    {
        Traverse(processor, sceneNode, *sceneNode.GetMesh());
    }

    processor.ProcessSceneNodeAfterChildren(sceneNode);
}

void Babylon::Transcoder::Asset3DTraverser::Traverse(IAsset3DProcessor& processor, SceneNode& sceneNode, Mesh& mesh)
{
    processor.ProcessMeshBeforeMaterialAndGeometry(sceneNode, mesh);

    processor.ProcessMesh(sceneNode, mesh);

    for (auto& geometry : mesh.GetGeometries())
    {
        processor.ProcessGeometry(sceneNode, mesh, geometry);

        const auto& material = geometry.GetMaterial();
        processor.ProcessMaterial(*material);

        for (auto& texture : material->GetTextures())
        {
            processor.ProcessTexture(*texture.second);
        }
    }

    processor.ProcessMeshAfterMaterialAndGeometry(sceneNode, mesh);
}

size_t Babylon::Transcoder::Asset3DTraverser::GetDepth() const
{
    return m_depth;
}