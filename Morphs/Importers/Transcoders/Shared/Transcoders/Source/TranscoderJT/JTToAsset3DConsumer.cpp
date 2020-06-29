/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <JtkShape.h>
#include <JtkEntityFactory.h>

#include <TranscoderJT/JTToAsset3DConsumer.h>
#include <TranscoderJT/GeometryBuilder.h>
#include <TranscoderJT/MeshBuilder.h>
#include <TranscoderJT/TranscoderJTUtils.h>

using namespace Babylon::Utils::Math;
using namespace Babylon::Transcoder;


namespace
{

    std::shared_ptr<MaterialBuilder<JTToAsset3DConsumer>> HandleMaterial(JTToAsset3DConsumer* consumer, JtkMaterial* jtkMaterial);

    template<typename T>
    std::vector<T> ToVector(const float* data, size_t count)
    {
        std::vector<T> collection(count);

        auto dataIndex = data;
        for (size_t i = 0; i < count; i++)
        {
            collection[i] = T(dataIndex);
            dataIndex += sizeof(T) / sizeof(float);
        }

        return collection;
    }

    std::shared_ptr<GeometryBuilder<JTToAsset3DConsumer>> ConsumeShape(JTToAsset3DConsumer* consumer, JtkShape* partShape, int LOD) {

        // we limit the number of LOD function of Asset3D capabilities. Current version DO NOT support LOD, then LOD 0 is taken as reference.
        if (LOD >= _GEOM_LOD_COUNT_MAX) {
            return nullptr;
        }

        std::shared_ptr<GeometryBuilder<JTToAsset3DConsumer>> geomBuilderPtr = std::make_shared<GeometryBuilder<JTToAsset3DConsumer>>(consumer);

        JtkVertexPool* Pool = NULL;

        float* Verts = NULL;
        int VertCount = 0;
        float* Norms = NULL;
        int NormCount = 0;
        float* Colors = NULL;
        int ColorCount = 0;
        float* Textures[8];
        int TexCount[8];

        for (int i = 0; i < 8; i++)
        {
            Textures[i] = NULL;
            TexCount[i] = 0;
        }

        partShape->getVertexPool(Pool);

        std::vector<uint32_t> indices;

        if (Pool)
        {
            Pool->getInternals(Verts, VertCount, Norms, NormCount, Colors, ColorCount, Textures, TexCount);

            unsigned int nPrims = 0;
            unsigned int* primStartingIndices = NULL;
            unsigned int* vertexPoolIndices = NULL;
            unsigned int numIndices = 0;

            partShape->getInternals(nPrims, primStartingIndices, vertexPoolIndices, numIndices);

 
            // vertices are compressed using a similar algorithm than the edgebreaker one
            // if two consecutive edge are not equal (no matter the orientation), then we have a triangle faces.
            for (unsigned int x = 0; x < nPrims; x++)
            {
                bool odd = false;
                for (unsigned int l = primStartingIndices[x]; l < primStartingIndices[x + 1]-2; l++)
                {
                    unsigned int i =l;
                    unsigned int a = vertexPoolIndices[i];
                    unsigned int b = vertexPoolIndices[i + 1];
                    unsigned int c = vertexPoolIndices[i + 2];

                    if (a != c) {

                        indices.push_back(odd?c:a);
                        indices.push_back(b);
                        indices.push_back(odd?a:c);
                    }
                    odd = !odd;
                }
            }

            geomBuilderPtr->WithTopology(GeometryTopology::kTriangles)
                .WithPositions(ToVector<Vector3>(Verts, VertCount))
                .WithNormals(ToVector<Vector3>(Norms, NormCount))
                .WithColors(std::vector<uint32_t>(Colors,Colors+ColorCount))
                .WithIndices(std::move(indices));

            JtkEntityFactory::deleteMemory(primStartingIndices);
            JtkEntityFactory::deleteMemory(vertexPoolIndices);

            JtkEntityFactory::deleteMemory(Verts);
            JtkEntityFactory::deleteMemory(Norms);
            JtkEntityFactory::deleteMemory(Colors);
            for (int i = 0; i < 8; i++)
            {
                if (Textures[i] != NULL)
                {
                    JtkEntityFactory::deleteMemory(Textures[i]);
                }
            }

            // MATERIALS are located into Attributes
            JtkMaterial* m;
            std::shared_ptr<MaterialBuilder<JTToAsset3DConsumer>> materialBuilderPtr = nullptr;
            if (partShape->getAttrib(0, (JtkAttrib*&)m, JtkEntity::JtkMATERIAL)) {
                materialBuilderPtr = HandleMaterial(consumer, m);
                if (materialBuilderPtr) {
                    geomBuilderPtr->WithMaterial(materialBuilderPtr);
                }
            }
        }
 
        return geomBuilderPtr;
    }

#define SET_COLOR(colorType) if(v){ materialBuilderPtr->With##colorType(SetColorLayer(v));JtkEntityFactory::deleteMemory(v);v = nullptr;}
   
    std::shared_ptr<MaterialDescriptor::LayerInfo> SetColorLayer(float* v) {
        std::shared_ptr<MaterialDescriptor::LayerInfo> layer = std::make_shared<LayerInfo>();
        layer->SetColor(Babylon::Utils::Math::Color(*v, *(v + 1), *(v + 2), *(v + 3)));
        return layer;
    }

    std::shared_ptr<MaterialBuilder<JTToAsset3DConsumer>> HandleMaterial(JTToAsset3DConsumer * consumer, JtkMaterial* jtkMaterial) {

        auto materialBuilderPtr = std::make_shared<MaterialBuilder<JTToAsset3DConsumer>>(consumer);
        // A four element floating point array whose elements respectively refer to the red, green, blue, and alpha aspects of the OpenGL color.
        float* v = nullptr;
        if (jtkMaterial->getAmbientColor(v)) {
            SET_COLOR(Ambient);
        }
        if (jtkMaterial->getEmissionColor(v)) {
            SET_COLOR(Emissive);
        }
        if (jtkMaterial->getDiffuseColor(v)) {
            SET_COLOR(Diffuse);
        }
        if (jtkMaterial->getSpecularColor(v)) {
            SET_COLOR(Specular);
        }
        return materialBuilderPtr;
    }
}


int JTToAsset3DConsumer::ConsumeAssembly(JtkAssembly* node) {
	return Jtk_OK;
}

int JTToAsset3DConsumer::ConsumePart(JtkPart* node) {

    std::shared_ptr<MeshBuilder<JTToAsset3DConsumer>> meshBuilderPtr = std::make_shared<MeshBuilder<JTToAsset3DConsumer>>(this);

    JtkString name = node->name();
    if (!name.isEmpty()) {
        meshBuilderPtr->WithName(JtkString2String(name));
    }

    // Register the builder model
    JTUniqueId id;
    if (node->getId(id)) {

        // MATERIALS are located into Attributes
        JtkMaterial* m;
        std::shared_ptr<MaterialBuilder<JTToAsset3DConsumer>> materialBuilderPtr = nullptr;
        if (node->getAttrib(0, (JtkAttrib*&)m, JtkEntity::JtkMATERIAL)) {
            materialBuilderPtr = HandleMaterial(this, m);
        }

        std::vector<std::shared_ptr< Asset3DBuilder<Geometry, JTToAsset3DConsumer>>> geometries;

        // GEOMETRY
        int partNumShapeLODs = -1;
        partNumShapeLODs = node->numPolyLODs();
        for (int lod = 0; lod < partNumShapeLODs; lod++)
        {
            int   partNumShapes = -1;
            partNumShapes = node->numPolyShapes(lod);
            for (int shNum = 0; shNum < partNumShapes; shNum++)
            {
                JtkShape* partShape = NULL;
                node->getPolyShape(partShape, lod, shNum);
                if (partShape)
                {
                    auto gb = ConsumeShape(this, partShape, lod);
                    if (gb) {
                        // register the material if none has been set
                        if (materialBuilderPtr && !gb->GetMaterial()) {
                            gb->WithMaterial(materialBuilderPtr);
                        }
                        geometries.push_back(gb);
                    }
                }
            }
        }

        // apply geometries to mesh
        meshBuilderPtr->WithGeometries(std::move(geometries));

        // register the mesh builder
        GetMeshBuilderLibrary()[id] = meshBuilderPtr;

        // bake the geometry and register the meh
        std::shared_ptr<Mesh> mesh = meshBuilderPtr->Build();
        GetMeshLibrary()[id] = mesh;

        // BEGIN TODO -> Move the code 
        // build a node based on geometry
        std::shared_ptr<SceneNode> nodePtr = std::make_shared<SceneNode>();
        nodePtr->SetMesh(mesh);
        nodePtr->SetName(meshBuilderPtr->GetName());

        // apply tronsformation (located into Attributes)
        JtkTransform* t;
        if (node->getAttrib(0, (JtkAttrib*&)t, JtkEntity::JtkTRANSFORM)) {
            nodePtr->SetTransform(toBabylonMatrix(t));
        }

        // register the node
        GetNodeLibrary()[id] = nodePtr;
        // END TODO -> Move the code 
    }

	return Jtk_OK;
}


int JTToAsset3DConsumer::ConsumeInstance(JtkInstance* node) {
    
    JtkHierarchy* model = node->original();
    JTUniqueId id;
    if (model->getId(id)) {
        auto l = GetMeshLibrary()[id];
        if (l) {
            std::shared_ptr<SceneNode> nodePtr = std::make_shared<SceneNode>();
            nodePtr->SetMesh(l);
            nodePtr->SetName(l->GetName());

            JtkTransform* t;
            if (node->getAttrib(0, (JtkAttrib*&)t, JtkEntity::JtkTRANSFORM)) {
                nodePtr->SetTransform(toBabylonMatrix(t));
            }

            JtkMaterial* m;
            if (node->getAttrib(0, (JtkAttrib*&)m, JtkEntity::JtkMATERIAL)) {
            }

            if (node->getId(id)) {
                GetNodeLibrary()[id] = nodePtr;
            }
        }
    }

    return Jtk_OK;
}

std::shared_ptr<Asset3D> JTToAsset3DConsumer::ProduceAsset3D() {
    std::shared_ptr<Asset3D> root = std::make_shared<Asset3D>();

    for (auto it = m_nodeLibrary.begin(); it != m_nodeLibrary.end(); ++it) {
        root->AddChildNode(it->second);
    }
    return root;
}


