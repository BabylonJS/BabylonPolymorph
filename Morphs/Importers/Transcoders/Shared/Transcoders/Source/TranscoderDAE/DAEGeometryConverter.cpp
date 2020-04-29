/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"
#include <TranscoderDAE\DAEGeometryConverter.h>
#include <earcut.hpp>

using namespace Babylon::Transcoder;

std::shared_ptr<Mesh> DAEMeshConverter::Convert(const COLLADAFW::Mesh* colladaMesh) {
	
	std::shared_ptr<Mesh> mesh = nullptr;

	const COLLADAFW::MeshVertexData& positions = colladaMesh->getPositions();
	const COLLADAFW::FloatArray * positionValues = positions.getFloatValues();
	const float* xyz = positionValues->getData();

	const COLLADAFW::MeshPrimitiveArray& meshPrimitives = colladaMesh->getMeshPrimitives();
	size_t meshPrimitivesCount = meshPrimitives.getCount();
	if (meshPrimitivesCount > 0) {
		
		for (size_t i = 0; i < meshPrimitivesCount; i++) {
			COLLADAFW::MeshPrimitive* colladaPrimitive = meshPrimitives[i];
			
			/// this is the place to find the corresponding material.
			int materialId = colladaPrimitive->getMaterialId();
			std::shared_ptr<MaterialDescriptor> material = nullptr;

			/// time to build the geometry 
			std::shared_ptr<Geometry> geometry = std::make_shared<Geometry>(material);

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

			/** 
			 * populate positions
			 * position are shared by several primitives, then we do not copy the whole array 
			 * we reassign the indices and we use APPEND methods instead  
			 */
			COLLADAFW::UIntValuesArray & indices = colladaPrimitive->getPositionIndices();
			size_t indicesCount = indices.getCount();
			/// mappedVertices is used to reassign new indexes
			size_t toAlloc = (positionValues->getCount() / 3) * sizeof(unsigned int);
			unsigned int* mappedIndices = (unsigned int*)malloc(toAlloc);
			/// mark the indices as unused if 0xFFFFFFFF 
			memset(mappedIndices, 0xFF, toAlloc);

			for (int i = 0; i < indicesCount; i++) {
				unsigned int j = indices[i];
				if (mappedIndices[j] == 0xFFFFFFFF) {
					const float* xPtr = xyz + j * 3;
					Babylon::Utils::Math::Vector3 tmp(xPtr);
					geometry->AddPosition(tmp);
					mappedIndices[j] = i;
				}
				geometry->AddIndex(mappedIndices[j]);
			}

			/// prepare indices
			if (shouldTriangulate) {
				/// verify for each faces that we have triangle
				size_t faceCount = colladaPrimitive->getFaceCount();
				for (int f = 0; f < faceCount; f++) {
					size_t verticeCount = colladaPrimitive->getGroupedVerticesVertexCount(f);
					if (verticeCount > 3) {
						/// this is the place to use earcut
						///	first project onto a 2D surface
						/// then triangulate
					}
				}
			}

			/// populate Normals
			if (colladaPrimitive->hasNormalIndices()) {
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

			free(mappedIndices);
		}
	}
	return mesh;
}

