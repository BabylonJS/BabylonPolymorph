/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>

#include <TranscoderDAE\DAEGeometryConverter.h>
#include <earcut.hpp>

#include <iostream>

using namespace Babylon::Transcoder;

/// internal struct to hold vertex info while parsing.
union VertexInfos {

	struct {
		int32_t vertex;
		int32_t normal;
	} indices;

	int64_t key;

	VertexInfos() {
		key = 0;
	}

	VertexInfos(uint32_t vertex, uint32_t normal) {
		indices.vertex = vertex;
		indices.normal = normal;
	}
};


std::shared_ptr<Mesh> DAEMeshConverter::Convert(const COLLADAFW::Mesh* colladaMesh) {
	
	std::shared_ptr<Mesh> mesh = nullptr;

	const COLLADAFW::MeshPrimitiveArray& meshPrimitives = colladaMesh->getMeshPrimitives();
	size_t meshPrimitivesCount = meshPrimitives.getCount();
	if (meshPrimitivesCount > 0) {

        /// get the context
		Asset3DWriterContextPtr ctx = getContext();

		/// get the up axis reference
		COLLADAFW::FileInfo::UpAxisType upAxis = ctx->getUpAxisType();

		/// build the mesh.
		mesh = std::make_shared<Mesh>();
		mesh->SetName(colladaMesh->getName());

		/**
		 * sources are shared by several primitives, then we do not copy the whole array
		 * we rebind the indices and we use APPEND methods instead of setting the whole array once
		 */
		const COLLADAFW::MeshVertexData& colladaPositions = colladaMesh->getPositions();
		const COLLADAFW::FloatArray* positionValues = colladaPositions.getFloatValues();
		const float* colladaXyz = positionValues->getData();
		const float* colladaNXyz = colladaMesh->hasNormals()? colladaMesh->getNormals().getFloatValues()->getData() : nullptr;

		/// loop over primitives
		for (size_t i = 0; i < meshPrimitivesCount; i++) {

			COLLADAFW::MeshPrimitive* colladaPrimitive = meshPrimitives[i];
			
			/// this is the place to find the corresponding material.
			int materialId = colladaPrimitive->getMaterialId();
			std::shared_ptr<MaterialDescriptor> material = nullptr;

			/// time to build the geometry 
			std::shared_ptr<Geometry> geometry = material ? std::make_shared<Geometry>(material): std::make_shared<Geometry>();

			/// default topology is triangle
			GeometryTopology topo = GeometryTopology::kTriangles;
			
			/// do we potentially tesselate surface, such polygon ?
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

			/// Set the topology of the geometry object.
			geometry->SetTopology(topo);
			
			/// position indices is the face indexing 
			COLLADAFW::UIntValuesArray & colladaPrimitiveIndices = colladaPrimitive->getPositionIndices();
			size_t colladaPrimitiveIndicesCount = colladaPrimitiveIndices.getCount();

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

			/// serve as cache to vertices infos while building. Key is the collada index of the vertex. 
			std::map<uint32_t, std::vector<VertexInfos>> vertexMaping;

			/// do we need to compute normals ?
			bool colladaPrimitiveHasNormals = colladaPrimitive->hasNormalIndices();
			
			/// miscelaneous declarations
			COLLADAFW::UIntValuesArray& colladaNormalsIndices = colladaPrimitive->getNormalIndices();
			Babylon::Utils::Math::Vector3 v3_cache0(0, 0, 0);
			int k = 0;
			const float* xPtr = nullptr;
			const float* xPtr1 = nullptr;

			uint32_t countUniqueVertex = 0;
			int32_t ni = -1;
			int32_t index = -1;
			uint32_t j = 0;

			/** 
			 * loop over all the indices of primitives. Indices are supposed to be arranged by 3 as they might define triangle.
			 * However, primitive such Polygon and Polyline are often used with potentially more than 3 vertices per faces.
			 * Regarding the normals, COLLADA files often define more than one normal per vertex (normal per face approach). 
			 * In this case, it's mean the vertex MUST be duplicated in order to keep one to one relationship between vertex and normels (so on tangents).
			 */
			for (size_t i0 = 0; i0 < colladaPrimitiveIndicesCount; i0++) {
				
				/// indice of vertex
				j = colladaPrimitiveIndices[i0];
				/// indice of normal : -1 means none
				ni = -1;
				/// new allocated index
				index = -1;
				/// get the vertex info
				std::vector<VertexInfos>& stack = vertexMaping[j];
				/// do we found an info ?
				if (stack.size() != 0) {

					if (colladaPrimitiveHasNormals) {
						/**
						 * Logic here is to get back to ono to one relationship between vertex and normal.
						 * to achieve this, we keep track the different vertex/normal couple.
						 * normal is defines has beeing equals IF the index is the same (trivial) OR if the values are the same
						 */
						for (int p = 0; p != stack.size(); p++) {

							/// verify normal index - work on the case where normal is -1 also
							if (stack[p].indices.normal == ni) {
								index = stack[p].indices.vertex;
								break;
							}

							/// verify if the normals are equal to optimize. using direct memory compare to optimize..
							ni = colladaNormalsIndices[i0];
							xPtr = colladaNXyz + ni * 3;
							xPtr1 = colladaNXyz + stack[p].indices.normal * 3;
							if (memcmp(xPtr, xPtr1, sizeof(float) * 3) == 0) {
								index = stack[p].indices.vertex;
								break;
							}
						}
					}
					else {
						/// optimized path when normal are not available
						index = stack[0].indices.vertex;
					}
				} 

				/// do not found any corresponding vertex (index != -1) ?
				if (index < 0) {

					/// Add new position
					xPtr = colladaXyz + j * 3; /// stride ils always xyz
					__VEC3_TRANSFER(upAxis, xPtr, v3_cache0)
					geometry->AddPosition(v3_cache0);

					/// Add coresponding Normals. As transcoder, we DO NOT build normal if none defined.
					if (colladaPrimitiveHasNormals) {
						ni = colladaNormalsIndices[i0];
						xPtr = colladaNXyz + ni * 3; /// stride is always xyz
						__VEC3_TRANSFER(upAxis, xPtr, v3_cache0)

						/// ensure normalized.
						v3_cache0.Normalize();
						geometry->AddNormal(v3_cache0);
					}

					/// save the vertex infos
					index = k++;
					vertexMaping[j].push_back(VertexInfos(index, ni));
					countUniqueVertex++;
				}
				/// finally add the index
				geometry->AddIndex(index);
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

			/// finally add geometry to the current mesh
			mesh->AddGeometry(std::move(*geometry));
		}
	}
	return mesh;
}

