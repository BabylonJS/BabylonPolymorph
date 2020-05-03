/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>

#include <TranscoderDAE\DAEGeometryConverter.h>
#include <earcut.hpp>

#include <iostream>

using namespace Babylon::Transcoder;

#define __VEC3_TRANSFER(ptr,v) v.x = *(ptr++); v.y = *(ptr++); v.z = *(ptr);
#define __AVERAGE_INC(v,b,n) b + (v - b) / n
#define __VEC3_AVERAGE_INC(ptr, v,n) v.x = __AVERAGE_INC(*(ptr++),v.x,n); v.y = __AVERAGE_INC(*(ptr++),v.y,n); v.z = __AVERAGE_INC(*(ptr),v.z,n);


std::shared_ptr<Mesh> DAEMeshConverter::Convert(const COLLADAFW::Mesh* colladaMesh) {
	
	std::shared_ptr<Mesh> mesh = nullptr;

	const COLLADAFW::MeshPrimitiveArray& meshPrimitives = colladaMesh->getMeshPrimitives();
	size_t meshPrimitivesCount = meshPrimitives.getCount();
	if (meshPrimitivesCount > 0) {

		mesh = std::make_shared<Mesh>();
		mesh->SetName(colladaMesh->getName());

		/**
		 * sources are shared by several primitives, then we do not copy the whole array
		 * we rebind the indices and we use APPEND methods instead of setting the whole array once
		 */
		const COLLADAFW::MeshVertexData& colladaPositions = colladaMesh->getPositions();
		const COLLADAFW::FloatArray* positionValues = colladaPositions.getFloatValues();
		const float* colladaXyz = positionValues->getData();

		const int colladaPositionIndicesCount = positionValues->getCount() / 3; /// stride is ALWAYS 3 for position
		int indicesBindingCount = colladaPositionIndicesCount;
		unsigned int* indicesBinding = (unsigned int*)malloc(indicesBindingCount * sizeof(unsigned int)) ;
		if (!indicesBinding) {
			throw std::bad_alloc();
		}

		for (size_t i = 0; i < meshPrimitivesCount; i++) {
			COLLADAFW::MeshPrimitive* colladaPrimitive = meshPrimitives[i];
			
			/// this is the place to find the corresponding material.
			int materialId = colladaPrimitive->getMaterialId();
			std::shared_ptr<MaterialDescriptor> material = nullptr;

			/// time to build the geometry 
			std::shared_ptr<Geometry> geometry = material ? std::make_shared<Geometry>(material): std::make_shared<Geometry>();

			/// default topology is triangle
			GeometryTopology topo = GeometryTopology::kTriangles;
			
			/// do we potentially tesselate surface, such polygon
			bool shouldTriangulate = false;

			/**
			 * Geometric primitives, which assemble values from the inputs into vertex attribute data.
			 * Can be any combination of the following in any order :
			 * <lines>, <linestrips>, <polygons>, <polylist>, <triangles>, <trifans>, and <tristrips>
			 */
			COLLADAFW::MeshPrimitive::PrimitiveType type = colladaPrimitive->getPrimitiveType();
			switch (type) {
				case COLLADAFW::MeshPrimitive::LINES:
					/// Contains line primitives.
				case COLLADAFW::MeshPrimitive::LINE_STRIPS:
					/// Contains line-strip primitives
					topo = GeometryTopology::kLines;
					break;
				case COLLADAFW::MeshPrimitive::POLYLIST:
					/// Contains polygon primitives that cannot contain holes.
				case COLLADAFW::MeshPrimitive::POLYGONS:
					/// Contains polygon primitives which may contain holes.
					shouldTriangulate = true;
				case COLLADAFW::MeshPrimitive::TRIANGLES:
					/// Contains triangle primitives
				case COLLADAFW::MeshPrimitive::TRIANGLE_STRIPS:
					/// Contains triangle-strip primitives
				case COLLADAFW::MeshPrimitive::TRIANGLE_FANS:
					/// Contains triangle-fan primitives
					break;
				case COLLADAFW::MeshPrimitive::POINTS:
					topo = GeometryTopology::kPoints;
					break;
				default:
				break;
			}

			geometry->SetTopology(topo);

			/// position indices is the face indexing 
			COLLADAFW::UIntValuesArray & colladaPrimitiveIndices = colladaPrimitive->getPositionIndices();
			size_t colladaPrimitiveIndicesCount = colladaPrimitiveIndices.getCount();

			/// mark the indices as unused if 0xFFFFFFFF 
			memset(indicesBinding, 0xFF, indicesBindingCount * sizeof(unsigned int));

			/// do we need to compute normals ?
			bool colladaHasNormals = colladaPrimitive->hasNormalIndices();
			const float * colladaNXyz= colladaHasNormals ? colladaMesh->getNormals().getFloatValues()->getData() : nullptr ;
			COLLADAFW::UIntValuesArray& colladaNormalsIndices = colladaPrimitive->getNormalIndices();
			std::vector<Babylon::Utils::Math::Vector3> normals;
			std::vector<int> normalPerVertices;

			Babylon::Utils::Math::Vector3 v3_cache0(0, 0, 0);
			int k = 0;
			const float* xPtr = nullptr;
			for (size_t i0 = 0; i0 < colladaPrimitiveIndicesCount; i0++) {
				unsigned int j = colladaPrimitiveIndices[i0];
				
				if (indicesBinding[j] == 0xFFFFFFFF) {
					xPtr = colladaXyz + j * 3; /// stride ils always xyz
					__VEC3_TRANSFER(xPtr,v3_cache0)
					geometry->AddPosition(v3_cache0);
					
					if (colladaHasNormals) {
						/// let use the normals at the same index
						xPtr = colladaNXyz + colladaNormalsIndices[i0] * 3; /// stride ils always xyz
						__VEC3_TRANSFER(xPtr, v3_cache0)
						normals.push_back(v3_cache0);
						normalPerVertices.push_back(1);
					}
					indicesBinding[j] = k++;
				}
				else {
					
					if (colladaHasNormals) {
						/// we incrementaly average the normals
						xPtr = colladaNXyz + colladaNormalsIndices[i0] * 3; /// stride ils always xyz
						int o = indicesBinding[j];
						Babylon::Utils::Math::Vector3& n = normals[o];
						int N = normalPerVertices[o] + 1;
						__VEC3_AVERAGE_INC(xPtr,n, N) 
						normalPerVertices[o] = N;
					}
				}
				geometry->AddIndex(indicesBinding[j]);
			}

			if (colladaHasNormals) {

				/// we Normalize and push normals to geometry
				std::vector<Babylon::Utils::Math::Vector3>::iterator it = normals.begin();
				while (it != normals.end())
				{
#ifdef __USE_V3_NORMALIZE
					(*it).Normalize();
#else
					/// USE custom function instead of Normalize() to keep control on warning.
					float l = sqrt(((*it).x * (*it).x) + ((*it).y * (*it).y) + ((*it).z * (*it).z));
					if (l == 0 || isinf(l)) {
						std::cout << "wrong normals value.." << "\r\n";
					} else {
						(*it).x = (*it).x / l;
						(*it).y = (*it).y / l;
						(*it).z = (*it).z / l;
					}
#endif
					geometry->AddNormal(*it);
					it++;
				}
			}


			// add extra indices if we need to triangulate
			if (shouldTriangulate) {
				size_t faceCount = colladaPrimitive->getFaceCount();
				for (size_t f = 0; f < faceCount; f++) {
					size_t verticeCount = colladaPrimitive->getGroupedVerticesVertexCount(f);
					if (verticeCount > 3) {
						/// this is the place to use earcut
						///	first project onto a 2D surface
						/// then triangulate
					}
				}
			}

			/// populate Tangents
			if (colladaPrimitive->hasTangentIndices()) {
			}

			/// populate Colors
			if (colladaPrimitive->hasColorIndices()) {
			}

			/// populate UVs
			if (colladaPrimitive->hasUVCoordIndices()) {
			}

			mesh->AddGeometry(std::move(*geometry));
		}
		free(indicesBinding);
	}
	return mesh;
}
