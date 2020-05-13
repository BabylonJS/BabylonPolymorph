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

namespace {

	struct IFeatureAccessor {
		virtual bool equals(const size_t a, const size_t b) const = 0;
		virtual void move(const size_t a) const = 0;
	};

	template<typename T>
	struct FeatureAccessor : public IFeatureAccessor {

		COLLADAFW::UIntValuesArray& indices;

		const float* values;
		const size_t size;
		size_t stride;
		std::vector<T>& target;
		bool mayEqualsValues;

		size_t _itemSize;
		size_t _targetSize;
		float* _tmp;

		FeatureAccessor(COLLADAFW::UIntValuesArray& i, const float* values, const size_t size, int stride, std::vector<T>& target, bool mayEqualValues = false, float padding = 1) :
			indices(i),
			values(values),
			size(size),
			stride(stride),
			target(target),
			mayEqualsValues(mayEqualValues),
			_itemSize(stride * sizeof(float)),
			_targetSize(sizeof(T) / sizeof(float)) {

			_tmp = _targetSize > _itemSize ? new float[_targetSize] : nullptr;
			if (_tmp) {
				memset(_tmp, padding, _targetSize);
			}
		}

		~FeatureAccessor() {
			if (_tmp) {
				delete[] _tmp;
			}
		}

		bool equals(const size_t a, const size_t b) const {
			if (a == b) return true;
			uint32_t ia = indices[a];
			uint32_t ib = indices[b];
			if (ia == ib) return true;
			return mayEqualsValues ? memcmp(values + ia * stride, values + ib * stride, _itemSize) : false;
		}

		void move(const size_t a) const {
			if (stride) {
				uint32_t ia = indices[a];
				const float* ptr = values + ia * stride;
				if (_tmp) {
					ptr = (const float*) memcpy(_tmp, ptr, _itemSize);
				}
				target.push_back(T(ptr));
			}
		}
	};

#define INDICE_NONE -1

	struct VertexBinding {

		int32_t buildedVertexIndice;
		int32_t line;

		VertexBinding() :
			buildedVertexIndice(INDICE_NONE),
			line(INDICE_NONE) {
		}

		VertexBinding(int32_t builded, int32_t line) :
			buildedVertexIndice(builded),
			line(line) {
		}
	};
}

std::shared_ptr<DAEMeshBuilder> DAEMeshConverter::Convert(const COLLADAFW::Mesh* colladaMesh) {
	
	std::shared_ptr<DAEMeshBuilder> meshbuilderPtr;

	const COLLADAFW::MeshPrimitiveArray& meshPrimitives = colladaMesh->getMeshPrimitives();
	size_t meshPrimitivesCount = meshPrimitives.getCount();
	if (meshPrimitivesCount > 0) {

        /// get the context
		DAEToAsset3DWriterContextPtr ctx = getContext();

		/// get the up axis reference
		COLLADAFW::FileInfo::UpAxisType upAxis = ctx->getUpAxisType();

		/// create the mesh builder.
		meshbuilderPtr = std::make_shared<DAEMeshBuilder>(ctx);
		meshbuilderPtr->WithName(colladaMesh->getName());


		/// loop over primitives
		for (size_t i = 0; i < meshPrimitivesCount; i++) {

			COLLADAFW::MeshPrimitive* colladaPrimitive = meshPrimitives[i];
			
			/// this is the place to find the corresponding default material for the geometry
			int materialId = colladaPrimitive->getMaterialId();
			std::shared_ptr<MaterialDescriptor> defaultMaterialPtr = nullptr;

			/// time to build the geometry 
			std::shared_ptr<DAEGeometryBuilder> geometryBuilder = std::make_shared<DAEGeometryBuilder>(ctx);
			if (defaultMaterialPtr) {
				geometryBuilder->WithDefaultMaterial(defaultMaterialPtr);
			}

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
			geometryBuilder->WithTopology(topo);

			/// building targets
			std::vector<uint32_t> indicesCache;
			std::vector<Babylon::Utils::Math::Vector3> verticesCache;
			std::vector<Babylon::Utils::Math::Vector3> normalsCache;
			std::vector<Babylon::Utils::Math::Vector4> tangentsCache;
			std::vector<std::vector<Babylon::Utils::Math::Vector3>> colorsCache;
			std::vector<std::vector<Babylon::Utils::Math::Vector2>> uvsCache;

			/// features to be parsed
			std::vector<std::shared_ptr<IFeatureAccessor>> features;
	
			const COLLADAFW::FloatArray* colladaPositionValues = colladaMesh->getPositions().getFloatValues();
			auto positionAccess = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector3>>( colladaPrimitive->getPositionIndices(), colladaPositionValues->getData(), colladaPositionValues->getCount(), 3, verticesCache);
			features.push_back(positionAccess);

			if (colladaPrimitive->hasNormalIndices()) {
				const COLLADAFW::FloatArray* colladaValues = colladaMesh->getNormals().getFloatValues();
				auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector3>>(colladaPrimitive->getNormalIndices(), colladaValues->getData(), colladaValues->getCount(), 3, normalsCache, true);
				features.push_back(accessor);
			}

			if (colladaPrimitive->hasTangentIndices()) {
				const COLLADAFW::FloatArray* colladaValues = colladaMesh->getTangents().getFloatValues();
				auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector4>>(colladaPrimitive->getTangentIndices(), colladaValues->getData(), colladaValues->getCount(), 3, tangentsCache, false, 1);
				features.push_back(accessor);
			}

			if (colladaPrimitive->hasColorIndices()) {
				COLLADAFW::IndexListArray& indicesArray = colladaPrimitive->getColorIndicesArray();
				size_t arrayCount = indicesArray.getCount();
				const COLLADAFW::FloatArray* colladaValues = colladaMesh->getColors().getFloatValues();
				for (size_t j = 0; j < arrayCount; j++) {
					colorsCache.push_back(std::vector<Babylon::Utils::Math::Vector3>());
					std::vector<Babylon::Utils::Math::Vector3> colorset = colorsCache[j];
					auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector3>>(indicesArray[j]->getIndices(), colladaValues->getData(), colladaValues->getCount(), 3, colorset);
					features.push_back(accessor);
				}
			}

			if (colladaPrimitive->hasUVCoordIndices()) {
				COLLADAFW::IndexListArray& indicesArray = colladaPrimitive->getUVCoordIndicesArray();
				size_t arrayCount = indicesArray.getCount();
				const COLLADAFW::FloatArray* colladaValues = colladaMesh->getUVCoords().getFloatValues();
				for (size_t j = 0; j < arrayCount; j++) {
					uvsCache.push_back(std::vector<Babylon::Utils::Math::Vector2>());
					std::vector<Babylon::Utils::Math::Vector2>& uvset = uvsCache[j];
					auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector2>>(indicesArray[j]->getIndices(), colladaValues->getData(), colladaValues->getCount(), 2, uvset);
					features.push_back(accessor);
				}
			}

			/// position indices is the face indexing 
			COLLADAFW::UIntValuesArray & colladaPrimitiveIndices = colladaPrimitive->getPositionIndices();
			size_t colladaPrimitiveIndicesCount = colladaPrimitiveIndices.getCount();

			//// add extra indices if we need to triangulate
			//if (shouldTriangulate) {
			//	size_t faceCount = colladaPrimitive->getFaceCount();
			//	for (size_t f = 0; f < faceCount; f++) {
			//		size_t verticeCount = colladaPrimitive->getGroupedVerticesVertexCount(f);
			//		if (verticeCount > 3) {
			//			///	first project onto a 2D surface
			//			/// then triangulate
			//		}
			//	}
			//}


			/// serve as cache to vertices infos while building. Key is the collada index of the vertex. 
			std::map<uint32_t, std::vector<VertexBinding>> vertexMaping;
			/// miscellaneous variables
			size_t v, k=0;
			int64_t index;

			for (size_t fi = 0; fi < colladaPrimitiveIndicesCount; fi++) {

				/// indice of vertex
				v = colladaPrimitiveIndices[fi];
				/// new allocated index
				index = INDICE_NONE;
				/// get the vertex info
				std::vector<VertexBinding> & stack = vertexMaping[v];
				if (stack.size()) {
					
					/// this is the place to find corresponding vertex by feature equality
					size_t p = 0;
					do {
						int32_t l = stack[p].line;
						index = stack[p].buildedVertexIndice;
						
						for (int f = 0; f != features.size(); f++) {
							std::shared_ptr<IFeatureAccessor> a = features[f];

							if (!a->equals(fi, l)) {
								index = INDICE_NONE;
								break;
							}
						}

					} while (--p < stack.size() && index == -1);
				}

				/// do not found any corresponding vertex (
				if (index < 0) {
					for (int f = 0; f != features.size(); f++) {
						std::shared_ptr<IFeatureAccessor> a = features[f];
						a->move(fi);
					}
					index = k++;
					vertexMaping[v].push_back(VertexBinding(index,fi));
				}

				/// finally add the index
				indicesCache.push_back(index);
			}


			///// serve as cache to vertices infos while building. Key is the collada index of the vertex. 
			//std::map<uint32_t, std::vector<VertexInfos>> vertexMaping;


			///// do we need to compute normals ?
			//bool colladaPrimitiveHasNormals = colladaPrimitive->hasNormalIndices();
			//COLLADAFW::UIntValuesArray & colladaNormalsIndices = colladaPrimitive->getNormalIndices();
			//size_t colladaNormalIndicesCount = colladaNormalsIndices.getCount();

			///// miscelaneous declarations
			//Babylon::Utils::Math::Vector3 v3_cache0(0, 0, 0);
			//Babylon::Utils::Math::Vector3 v3_cache1(0, 0, 0);
			//Babylon::Utils::Math::Vector3 v3_cache2(0, 0, 0);
			//Babylon::Utils::Math::Vector3 v3_cache3(0, 0, 0);
			//const float* xPtr = nullptr;
			//const float* xPtr1 = nullptr;

			//uint32_t countUniqueVertex = 0;
			//int32_t ni = -1;
			//int32_t index = -1;
			//size_t j3 = 0;

			///** 
			// * loop over all the indices of primitives. Indices are supposed to be arranged by 3 as they might define triangle.
			// * However, primitive such Polygon and Polyline are often used with potentially more than 3 vertices per faces.
			// * Regarding the normals, COLLADA files often define more than one normal per vertex (normal per face approach). 
			// * In this case, it's mean the vertex MUST be duplicated in order to keep one to one relationship between vertex and normels (so on tangents).
			// */
			//for (size_t i0 = 0; i0 < colladaPrimitiveIndicesCount; i0++) {

			//	/// indice of vertex
			//	j = colladaPrimitiveIndices[i0];
			//	j3 = j * 3; /// xyz stride

			//	/// indice of normal : -1 means none
			//	ni = -1;
			//	/// new allocated index
			//	index = -1;
			//	/// get the vertex info
			//	std::vector<VertexInfos>& stack = vertexMaping[j];

			//	/// do we found an info ?
			//	if (stack.size() != 0) {

			//		if (colladaPrimitiveHasNormals) {
			//			/**
			//			 * Logic here is to get back to one to one relationship between vertex and normal.
			//			 * to achieve this, we keep track the different vertex/normal couple.
			//			 * normal is defines has beeing equals IF the index is the same (trivial) OR if the values are the same
			//			 */
			//			for (int p = 0; p != stack.size(); p++) {

			//				/// verify normal index - work on the case where normal is -1 also
			//				if (stack[p].normal == ni) {
			//					index = stack[p].vertex;
			//					break;
			//				}

			//				/// verify if the normals are equals.
			//				ni = colladaNormalsIndices[i0];

			//				xPtr = colladaNXyz + ni * 3;
			//				xPtr1 = colladaNXyz + stack[p].normal * 3;
			//				if (memcmp(xPtr, xPtr1, sizeof(float) * 3) == 0) {
			//					index = stack[p].vertex;
			//					break;
			//				}
			//			}
			//		}
			//		else {
			//			/// optimized path when normal are not available
			//			index = stack[0].vertex;
			//		}
			//	} 

			//	/// do not found any corresponding vertex (index != -1) ?
			//	if (index < 0) {

			//		/// Add new position
			//		xPtr = colladaXyz + j3; /// stride is always xyz
			//		__VEC3_TRANSFER(upAxis, xPtr, v3_cache0)
			//		verticesCache.push_back(v3_cache0);
			//		//geometry->AddPosition(v3_cache0);

			//		/// Add coresponding Normals. As transcoder, we DO NOT build normal if none defined.
			//		if (colladaPrimitiveHasNormals) {
			//			ni = colladaNormalsIndices[i0];
			//			if (ni >= colladaNormalCount) {
			//				/// corrupted data
			//				continue;
			//			}
			//			xPtr = colladaNXyz + ni * 3; /// stride is always xyz
			//			__VEC3_TRANSFER(upAxis, xPtr, v3_cache0)
			//			float l = v3_cache0.Length();
			//			switch (topo) {
			//			case(GeometryTopology::kTriangles): {
			//				/// zero length normals ?
			//				if (l == 0) {
			//					/// this is serious data error. Try to recover computing face normal
			//					size_t fi = i0 / 3;
			//					xPtr = colladaXyz + colladaPrimitiveIndices[fi++] * 3;
			//					__VEC3_TRANSFER(upAxis, xPtr, v3_cache1)
			//					xPtr = colladaXyz + colladaPrimitiveIndices[fi++] * 3;
			//					__VEC3_TRANSFER(upAxis, xPtr, v3_cache2)
			//					xPtr = colladaXyz + colladaPrimitiveIndices[fi] * 3;
			//					__VEC3_TRANSFER(upAxis, xPtr, v3_cache3)
			//					v3_cache0 = (v3_cache2 - v3_cache1).Cross(v3_cache3 - v3_cache1);
			//					l = v3_cache0.Length();
			//				}
			//				/// not normalized ?
			//				if (l != 1) {
			//					/// easy to fix
			//					v3_cache0.Normalize();
			//				}
			//				normalsCache.push_back(v3_cache0);
			//				break;
			//			}
			//			case(GeometryTopology::kLines):
			//			case(GeometryTopology::kPoints): {
			//				if (l) {
			//					/// not normalized ?
			//					if (l != 1) {
			//						/// easy to fix
			//						v3_cache0.Normalize();
			//					}
			//					normalsCache.push_back(v3_cache0);
			//				}
			//				else {
			//					/// zero length normals, then invalidate whole primitive
			//					colladaPrimitiveHasNormals = false;
			//				}
			//			}
			//			}
			//		}

			//		/// save the vertex infos
			//		index = k++;
			//		vertexMaping[j].push_back(VertexInfos(index, ni));
			//		countUniqueVertex++;
			//	}
			//	/// finally add the index
			//	indicesCache.push_back(index);
			//}

			geometryBuilder->WithIndices(std::move(indicesCache))
							.WithPositions(std::move(verticesCache))
							.WithNormals(std::move(normalsCache))
							.WithTangents(std::move(tangentsCache));

			/// populate UVs
			if (colladaPrimitive->hasUVCoordIndices()) {
				for (size_t j = 0; j != uvsCache.size(); j++) {
					geometryBuilder->WithUvs(std::move(uvsCache[i]), i);
				}
			}

			/// finally add geometry model to the current mesh builder
			meshbuilderPtr->WithGeometry(geometryBuilder);
		}
	}
	return meshbuilderPtr;
}

