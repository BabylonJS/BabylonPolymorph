/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAEAnimationConverter.h>
#include <COLLADAFWSkinControllerData.h>
#include <CoreUtils/GLTFSkins.h>

DEFINE_TRACE_AREA(DAESkinControllerDataConverter, 0);

using namespace Babylon::Transcoder;

std::shared_ptr<DAESkinData> DAESkinControllerDataConverter::Convert(const COLLADAFW::SkinControllerData* colladaControllerData) {
	
	///  cache the list of skins
	std::shared_ptr<DAESkinData> skin = std::make_shared<DAESkinData>();

	COLLADAFW::UniqueId uniqueId = colladaControllerData->getUniqueId();
	skin->name = NAME_OR_ID(colladaControllerData);

	/// Write ibindShapeMatrix
	skin->bindShapeMatrix = toBabylonMatrix(colladaControllerData->getBindShapeMatrix());

	/// Write inverseBindMatrices 
	const COLLADAFW::Matrix4Array& matrixArray = colladaControllerData->getInverseBindMatrices();
	size_t matrixArrayCount = matrixArray.getCount();

	for (size_t i = 0; i < matrixArrayCount; i++) {
		skin->inverseBindMatrices.push_back(toBabylonMatrix(matrixArray[i]));
	}

	/// Cache joint and weight data
	/// COLLADA can have different numbers of joints for a single vertex
	/// We have to make this uniform across all vertices to make it into a GLTF primitive attribute
	const COLLADAFW::UIntValuesArray& jointsPerVertexArray = colladaControllerData->getJointsPerVertex();

	size_t totalVertices = 0;
	size_t  maxJointsPerVertex = 0;
	for (size_t i = 0; i < jointsPerVertexArray.getCount(); i++) {
		size_t jointsPerVertex = jointsPerVertexArray[i];
		totalVertices += jointsPerVertex;
		maxJointsPerVertex = std::max(maxJointsPerVertex, jointsPerVertex);
	}


	Microsoft::glTF::AccessorType type;
	if (maxJointsPerVertex == 1) {
		type = Microsoft::glTF::AccessorType::TYPE_SCALAR;
	} else if (maxJointsPerVertex == 2) {
		type = Microsoft::glTF::AccessorType::TYPE_VEC2;
	} else if (maxJointsPerVertex == 3) {
		type = Microsoft::glTF::AccessorType::TYPE_VEC3;
	} else if (maxJointsPerVertex == 4) {
		type = Microsoft::glTF::AccessorType::TYPE_VEC4;
	} else if (maxJointsPerVertex <= 9) {
		type = Microsoft::glTF::AccessorType::TYPE_MAT3;
		maxJointsPerVertex = 9;
	} else if (maxJointsPerVertex <= 16) {
		type = Microsoft::glTF::AccessorType::TYPE_MAT4;
		maxJointsPerVertex = 16;
	} else {
		TRACE_WARN(DAESkinControllerDataConverter, "There is no Asset3D type accessor type big enough to store this many joint influences - discard controller %s", uniqueId.toAscii());
		return false;
	}

	size_t vertexCount = colladaControllerData->getVertexCount();
	size_t offset = 0;
	const COLLADAFW::IntValuesArray& jointIndicesArray = colladaControllerData->getJointIndices();
	const COLLADAFW::UIntValuesArray& weightIndicesArray = colladaControllerData->getWeightIndices();
	const COLLADAFW::FloatOrDoubleArray& weightsArray = colladaControllerData->getWeights();

	/// TODO - Replace allocated array with std::unique_ptr<vector<>>
	for (size_t i = 0; i < vertexCount; i++) {
		unsigned int jointsPerVertex = jointsPerVertexArray[i];
		uint32_t* joint = new uint32_t[maxJointsPerVertex];
		float* weight = new float[maxJointsPerVertex];
		for (size_t j = 0; j < maxJointsPerVertex; j++) {
			if (j < jointsPerVertex) {
				unsigned int jointIndex = jointIndicesArray[j + offset];
				joint[j] = jointIndex;
				unsigned int weightIndex = weightIndicesArray[j + offset];
				float weightValue = 0;
				if (weightsArray.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_FLOAT) {
					weightValue = weightsArray.getFloatValues()->getData()[weightIndex];
				}
				else if (weightsArray.getType() == COLLADAFW::FloatOrDoubleArray::DATA_TYPE_DOUBLE) {
					weightValue = (float)weightsArray.getDoubleValues()->getData()[weightIndex];
				}
				weight[j] = weightValue;
			}
			else {
				joint[j] = 0;
				weight[j] = 0;
			}
		}
		offset += jointsPerVertex;
		skin->jointIndices.push_back(joint);
		skin->weights.push_back(weight);
		skin->type = type;
	}
	return skin;
}
