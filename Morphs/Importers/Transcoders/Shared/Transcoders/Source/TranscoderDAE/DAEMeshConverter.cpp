/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>

#include <TranscoderDAE\DAECoreConverter.h>
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

		std::string semantic;
		COLLADAFW::UIntValuesArray& indices;
		const float* values;
		const size_t size;
		size_t stride;
		std::vector<T>& target;
		bool mayEqualsValues;

		size_t _itemSize;
		size_t _targetSize;
		float* _tmp;

		FeatureAccessor(std::string semantic, COLLADAFW::UIntValuesArray& i, const float* values, const size_t size, int stride, std::vector<T>& target, bool mayEqualValues = false, float padding = 1) :
			indices(i),
			values(values),
			size(size),
			stride(stride),
			target(target),
			mayEqualsValues(mayEqualValues),
			_itemSize(stride * sizeof(float)),
			_targetSize(sizeof(T)) {

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
			/// note in the way we use it inside a loop a is ALWAYS greater than b.
			uint32_t ia = indices[a];
			uint32_t ib = indices[b];
			if (ia == ib) return true;
			/**
			 * here we have different index, wich lead potentially to differents values 
			 * As we want to duplicate vertices with different features value we may test the value
			 * to see if different.
			 */
			return mayEqualsValues ? memcmp(values + ia * stride, values + ib * stride, _itemSize) == 0 : false;
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

		std::string name = colladaMesh->getName();
		meshbuilderPtr->WithName(name.empty() ? colladaMesh->getOriginalId() : name);

		/// loop over primitives
		for (size_t i = 0; i < meshPrimitivesCount; i++) {

			COLLADAFW::MeshPrimitive* colladaPrimitive = meshPrimitives[i];
			
			/// this is the place to find the corresponding default material for the geometry
			std::string materialName = colladaPrimitive->getMaterial();
			COLLADAFW::MaterialId materialId = colladaPrimitive->getMaterialId();

			/// time to build the geometry 
			std::shared_ptr<DAEGeometryBuilder> geometryBuilder = std::make_shared<DAEGeometryBuilder>(ctx);
			geometryBuilder->WithMaterialName(materialName);

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
			std::vector<std::shared_ptr<std::vector<Babylon::Utils::Math::Vector3>>> colorsCache;
			std::vector<std::shared_ptr<std::vector<Babylon::Utils::Math::Vector2>>> uvsCache;

			/// features to be parsed
			std::vector<std::shared_ptr<IFeatureAccessor>> features;

			const COLLADAFW::FloatArray* colladaPositionValues = colladaMesh->getPositions().getFloatValues();
			auto positionAccess = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector3>>("",colladaPrimitive->getPositionIndices(), colladaPositionValues->getData(), colladaPositionValues->getCount(), 3, verticesCache, _GEOM_TEST_POSITION_VALUE);
			features.push_back(positionAccess);

			if (topo != GeometryTopology::kLines && topo != GeometryTopology::kPoints) {
			
				if (colladaPrimitive->hasNormalIndices()) {
					const COLLADAFW::FloatArray* colladaValues = colladaMesh->getNormals().getFloatValues();
					auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector3>>("", colladaPrimitive->getNormalIndices(), colladaValues->getData(), colladaValues->getCount(), 3, normalsCache, _GEOM_TEST_NORMAL_VALUE);
					features.push_back(accessor);
				}

				if (colladaPrimitive->hasTangentIndices()) {
					const COLLADAFW::FloatArray* colladaValues = colladaMesh->getTangents().getFloatValues();
					auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector4>>("", colladaPrimitive->getTangentIndices(), colladaValues->getData(), colladaValues->getCount(), 3, tangentsCache, _GEOM_TEST_TANGENT_VALUE, 1);
					features.push_back(accessor);
				}

#ifdef _IMPORT_MATERIAL
				if (colladaPrimitive->hasUVCoordIndices()) {
					COLLADAFW::IndexListArray& indicesArray = colladaPrimitive->getUVCoordIndicesArray();
					size_t arrayCount = indicesArray.getCount();
					const COLLADAFW::FloatArray* colladaValues = colladaMesh->getUVCoords().getFloatValues();
					for (size_t j = 0; j < arrayCount; j++) {
						std::shared_ptr < std::vector<Babylon::Utils::Math::Vector2>> uvset = std::make_shared<std::vector<Babylon::Utils::Math::Vector2>>();
						uvsCache.push_back(uvset);
						auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector2>>("", indicesArray[j]->getIndices(), colladaValues->getData(), colladaValues->getCount(), 2, *uvset, _GEOM_TEST_TEXTCOORD_VALUE);
						features.push_back(accessor);
					}
				}
#endif
			}

#ifdef _IMPORT_MATERIAL
			if (colladaPrimitive->hasColorIndices()) {
				COLLADAFW::IndexListArray& indicesArray = colladaPrimitive->getColorIndicesArray();
				size_t arrayCount = indicesArray.getCount();
				const COLLADAFW::FloatArray* colladaValues = colladaMesh->getColors().getFloatValues();
				for (size_t j = 0; j < arrayCount; j++) {
					std::shared_ptr < std::vector<Babylon::Utils::Math::Vector3>> colorset = std::make_shared<std::vector<Babylon::Utils::Math::Vector3>>();
					colorsCache.push_back(colorset);
					auto accessor = std::make_shared<FeatureAccessor<Babylon::Utils::Math::Vector3>>("", indicesArray[j]->getIndices(), colladaValues->getData(), colladaValues->getCount(), 3, *colorset, _GEOM_TEST_COLOR_VALUE);
					features.push_back(accessor);
				}
			}
#endif

			/// position indices is the face indexing 
			COLLADAFW::UIntValuesArray & colladaPrimitiveIndices = colladaPrimitive->getPositionIndices();
			size_t colladaPrimitiveIndicesCount = colladaPrimitiveIndices.getCount();


			/// serve as cache to vertices infos while building. Key is the collada index of the vertex. 
			std::map<uint32_t, std::vector<VertexBinding>> vertexMaping;
			/// miscellaneous variables
			size_t v, k=0;
			int64_t index;
			unsigned int totalVertexCount = 0;
			unsigned int vertexCount = 0;

			unsigned int face = 0;
			unsigned int startFace = 0;
			unsigned int faceVertexCount = colladaPrimitive->getGroupedVerticesVertexCount(face);

			for (size_t fi = 0; fi < colladaPrimitiveIndicesCount; fi++) {

				if (shouldTriangulate) {

					/**
					 * This work over 99% of the case found in the COLLADA FILE - convex, not holes poly. However, it's NOT follow the norm.
					 * we should use another triangulation algorithm instead.
					 */
					if (vertexCount == faceVertexCount) {
						if (vertexCount > 3) {
							size_t end = indicesCache.size() - 2;
							size_t a = indicesCache[startFace];
							size_t b = indicesCache[end++];
							size_t c = indicesCache[end];

							indicesCache[end] = a;
							indicesCache.push_back(b);
							indicesCache.push_back(c);
							totalVertexCount += 2;
						}
						face++;
						faceVertexCount = colladaPrimitive->getGroupedVerticesVertexCount(face);
						startFace = totalVertexCount;
						vertexCount = 0;
					} else if (vertexCount > 3) {
						size_t end = indicesCache.size() - 2;
						size_t a = indicesCache[startFace];
						size_t b = indicesCache[end++];
						size_t c = indicesCache[end];

						indicesCache[end] = a;
						indicesCache.push_back(b);
						indicesCache.push_back(c);
						totalVertexCount += 2;
					}
				}
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
						
						for (int f = 0; f < features.size(); f++) {
							std::shared_ptr<IFeatureAccessor> a = features[f];

							if (!a->equals(fi, l)) {
								index = INDICE_NONE;
								break;
							}
						}

					} while (--p < stack.size() && index == INDICE_NONE);
				}

				/// do not found any corresponding vertex (
				if (index == INDICE_NONE) {
					for (int f = 0; f != features.size(); f++) {
						std::shared_ptr<IFeatureAccessor> a = features[f];
						a->move(fi);
					}
					index = k++;
					vertexMaping[v].push_back(VertexBinding(index,fi));
				}

				/// finally add the index
				indicesCache.push_back(index);
				totalVertexCount++;
				vertexCount++;
			}

			if (shouldTriangulate) {
				/// close last poly
				if (vertexCount > 3) {
					size_t end = indicesCache.size() - 2;
					size_t a = indicesCache[startFace];
					size_t b = indicesCache[end++];
					size_t c = indicesCache[end];

					indicesCache[end] = a;
					indicesCache.push_back(b);
					indicesCache.push_back(c);
					totalVertexCount += 2;
				}
			}

#ifdef _GEOM_NORMAL_POST_PROCESS
			for (int j = 0; j != normalsCache.size(); j++) {
#ifdef _GEOM_NORMAL_CLEAR_ZERO
				if (normalsCache[j].LengthSquared() == 0) {
					normalsCache.clear();
					break;
				}
#endif
#ifdef _GEOM_NORMAL_NORMALIZE
				normalsCache[j].Normalize();
#endif
			}
#endif
			geometryBuilder->WithIndices(std::move(indicesCache))
							.WithPositions(std::move(verticesCache))
							.WithNormals(std::move(normalsCache))
							.WithTangents(std::move(tangentsCache));

#ifdef _IMPORT_MATERIAL

			/// populate UVs
			if (colladaPrimitive->hasUVCoordIndices()) {
				for (size_t j = 0; j != uvsCache.size(); j++) {
					auto tmp = *uvsCache[j];
					/**
					 * according to Asset3D First image pixel (UV coordinates origin) corresponds to the upper left corner of the image. 
					 * according to Collada For texture coordinates, COLLADA’s right-handed coordinate system applies; therefore, an ST texture coordinate of [0,0] maps to the lower-left texel of a texture image
					 * WARNING : COLLADA exporter are known to export uv coordinate outside the [0,1] range.. then we better to find another place to transform -> at the source (data of the texture).
					 */
					if (_INVERT_Y_MODE == InvertYMode::UVLevel) {
						for (k = 0; k != tmp.size(); k++) {
							tmp[k].y = 1.0 - tmp[k].y;
						}
					}
					geometryBuilder->WithUvs(std::move(tmp), j);
				}
			}
#endif
			/// finally add geometry model to the current mesh builder
			meshbuilderPtr->WithGeometry(geometryBuilder);
		}
	}
	return meshbuilderPtr;
}

