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

	const COLLADAFW::MeshPrimitiveArray& meshPrimitives = colladaMesh->getMeshPrimitives();
	size_t meshPrimitivesCount = meshPrimitives.getCount();
	if (meshPrimitivesCount > 0) {

		mesh = std::make_shared<Mesh>();
		mesh->SetName(colladaMesh->getName());

		/**
		 * sources are shared by several primitives, then we do not copy the whole array
		 * we rebind the indices and we use APPEND methods instead of setting the whole array once
		 */
		const COLLADAFW::MeshVertexData& positions = colladaMesh->getPositions();
		const COLLADAFW::FloatArray* positionValues = positions.getFloatValues();
		const float* xyz = positionValues->getData();

		const int positionIndicesCount = positionValues->getCount() / 3; /// stride is ALWAYS 3 for position
		int indicesBindingCount = positionIndicesCount;
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
			COLLADAFW::UIntValuesArray & primitiveIndices = colladaPrimitive->getPositionIndices();
			size_t primitiveIndicesCount = primitiveIndices.getCount();

			/// mark the indices as unused if 0xFFFFFFFF 
			memset(indicesBinding, 0xFF, positionIndicesCount * sizeof(unsigned int));

			Babylon::Utils::Math::Vector3 v3_cache0(0, 0, 0);
			int k = 0;
			for (int i = 0; i < primitiveIndicesCount; i++) {
				unsigned int j = primitiveIndices[i];
				if (indicesBinding[j] == 0xFFFFFFFF) {
					const float* xPtr = xyz + j * 3;
					v3_cache0.x = *(xPtr);
					v3_cache0.y = *(xPtr + 1);
					v3_cache0.z = *(xPtr + 2);
					geometry->AddPosition(v3_cache0);
					indicesBinding[j] = k++;
				}
				geometry->AddIndex(indicesBinding[j]);
			}

			// add extra indices if we need to triangulate
			if (shouldTriangulate) {
				size_t faceCount = colladaPrimitive->getFaceCount();
				int i = 0;
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

				/// mesh related
				const COLLADAFW::MeshVertexData& data = colladaMesh->getNormals();
				const COLLADAFW::FloatArray* values = data.getFloatValues();
				const float * valuePtr = values->getData();
				
				/// primitive
				COLLADAFW::UIntValuesArray& indices = colladaPrimitive->getNormalIndices();
				size_t count = indices.getCount();

				/// check if indicesBinding if enought large 
				if (count > indicesBindingCount) {
					void* tmp = realloc(indicesBinding, count * sizeof(unsigned int));
					if (!tmp) {
						free(indicesBinding);
						throw std::bad_alloc();
					} 
					indicesBinding = (unsigned int*)tmp;
					indicesBindingCount = count;
				}
				/// mark the indices as unused if 0xFFFFFFFF 
				memset(indicesBinding, 0xFF, count * sizeof(unsigned int));

				k = 0;
				for (int i = 0; i < count; i++) {
					unsigned int j = indices[i];
					if (indicesBinding[j] == 0xFFFFFFFF) {
						const float* xPtr = valuePtr + j * 3;
						v3_cache0.x = *(xPtr);
						v3_cache0.y = *(xPtr + 1);
						v3_cache0.z = *(xPtr + 2);
						geometry->AddNormal(v3_cache0);
						indicesBinding[j] = k++;
					}
				}
			}

			/// populate Tangents
			if (colladaPrimitive->hasTangentIndices()) {
				/// mesh related 
				const COLLADAFW::MeshVertexData& data = colladaMesh->getTangents();
				const COLLADAFW::FloatArray* values = data.getFloatValues();
				const float* valuePtr = values->getData();

				/// primitive
				COLLADAFW::UIntValuesArray& indices = colladaPrimitive->getTangentIndices();
				size_t count = indices.getCount();

				/// check if indicesBinding if enought large 
				if (count > indicesBindingCount) {
					void* tmp = realloc(indicesBinding, count * sizeof(unsigned int));
					if (!tmp) {
						free(indicesBinding);
						throw std::bad_alloc();
					}
					indicesBinding = (unsigned int*)tmp;
					indicesBindingCount = count;
				}
				/// mark the indices as unused if 0xFFFFFFFF 
				memset(indicesBinding, 0xFF, count * sizeof(unsigned int));

				/// Note : Collada is providing a 3 dimensional tangent
				Babylon::Utils::Math::Vector4 v4_cache0(0, 0, 0, 1);
				k = 0;
				for (int i = 0; i < count; i++) {
					unsigned int j = indices[i];
					if (indicesBinding[j] == 0xFFFFFFFF) {
						const float* xPtr = valuePtr + j * 3;
						v4_cache0.x = *(xPtr);
						v4_cache0.y = *(xPtr + 1);
						v4_cache0.z = *(xPtr + 2);
						geometry->AddTangent(v4_cache0);
						indicesBinding[j] = k++;
					}
				}
			}

			/// populate Colors
			if (colladaPrimitive->hasColorIndices()) {
				/// mesh related 
				const COLLADAFW::MeshVertexData& data = colladaMesh->getColors();
				const COLLADAFW::FloatArray* values = data.getFloatValues();
				const float* valuePtr = values->getData();
				/// primitive
				COLLADAFW::IndexListArray& indexList = colladaPrimitive->getColorIndicesArray();
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

