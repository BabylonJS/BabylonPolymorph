/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "PluginSDKPch.h"

#include <PluginSDK/ExporterBase.h>

#include <Asset3D/Asset3D.h>
#include <Asset3D/Asset3DTraverser.h>

using namespace Babylon::Transcoder;

void ExporterBase::Export(Asset3D& asset)
{
    Asset3DTraverser traverser;
    traverser.Traverse(*this, asset);
}

void ExporterBase::ProcessAsset3DBeforeChildren(Asset3D& asset3D)
{
    PushTransform(asset3D.GetTransform());
    ExportNodeDownwardPass(asset3D);
}

void ExporterBase::ProcessAsset3DAfterChildren(Asset3D& asset3D)
{
    ExportNodeUpwardPass(asset3D);
    PopTransform();
}

void ExporterBase::ProcessSceneNodeBeforeChildren(SceneNode& sceneNode)
{
    PushTransform(sceneNode.GetTransform());
    ExportNodeDownwardPass(sceneNode);
}

void ExporterBase::ProcessSceneNodeAfterChildren(SceneNode& sceneNode)
{
    ExportNodeUpwardPass(sceneNode);
    PopTransform();
}

void ExporterBase::ProcessMeshBeforeMaterialAndGeometry(SceneNode& sceneNode, Mesh& mesh)
{
    ExportNodeDownwardPass(sceneNode, mesh);
}

void ExporterBase::ProcessMeshAfterMaterialAndGeometry(SceneNode& sceneNode, Mesh& mesh)
{
    ExportNodeUpwardPass(sceneNode, mesh);
}

void ExporterBase::ProcessMesh(SceneNode&, Mesh& mesh)
{
    if(!TestAndSetAlreadyExported(MeshesExported, &mesh))
    {
        ExportLeaf(mesh);
    }
}

void ExporterBase::ProcessGeometry(SceneNode&, Mesh&, Geometry& geometry)
{
    if(!TestAndSetAlreadyExported(GeometriesExported, &geometry))
    {
        ExportLeaf(geometry);
    }
}

void ExporterBase::ProcessMaterial(MaterialDescriptor& material)
{
    if(!TestAndSetAlreadyExported(MaterialsExported, &material))
    {
        ExportLeaf(material);
    }
}

void ExporterBase::ProcessTexture(TextureDescriptor& texture)
{
    if(!TestAndSetAlreadyExported(TexturesExported, &texture))
    {
        ExportLeaf(texture);
    }
}
