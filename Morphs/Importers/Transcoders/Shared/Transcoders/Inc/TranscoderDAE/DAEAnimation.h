/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <CoreUtils/GLTFSkins.h>
#include <CoreUtils/Math/SimpleMath.h>

#include <TranscoderDAE/DAEToAsset3DWriter.h>

#include "COLLADAFWUniqueId.h"

namespace Babylon
{
	namespace Transcoder
	{
		struct DAESkinData {

			std::string name;
			Babylon::Utils::Math::Matrix bindShapeMatrix;
			std::vector<Babylon::Utils::Math::Matrix> inverseBindMatrices;
			Microsoft::glTF::AccessorType type;
			std::vector<uint32_t*> jointIndices;
			std::vector<float*> weights;

			~DAESkinData() {
				/// free ressources allocated inside DAESkinControllerDataConverter.cpp
				/// TODO - Replace allocated array with std::unique_ptr<vector<>>
				for (uint32_t* i : jointIndices) if (i) free(i);
				for (float* i : weights) if (i) free(i);
			}

			inline int getNumberOfComponents() {
				switch (type) {
				case Microsoft::glTF::AccessorType::TYPE_SCALAR:
					return 1;
				case Microsoft::glTF::AccessorType::TYPE_VEC2:
					return 2;
				case Microsoft::glTF::AccessorType::TYPE_VEC3:
					return 3;
				case Microsoft::glTF::AccessorType::TYPE_VEC4:
				case Microsoft::glTF::AccessorType::TYPE_MAT2:
					return 4;
				case Microsoft::glTF::AccessorType::TYPE_MAT3:
					return 9;
				case Microsoft::glTF::AccessorType::TYPE_MAT4:
					return 16;
				}
				return 0;
			}
		};

		struct DAEAnimationData {
			std::vector<float> inputs;
			std::vector<float> outputs;
		};


	}
}
