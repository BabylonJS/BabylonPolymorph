/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <GLTFSDK/Math.h>
#include <CoreUtils/Math/SimpleMath.h>

using namespace Spectre::Utils::Math;

namespace Spectre
{
    namespace Transcoder
    {
        class TransformMatrixUtils
        {
        public:
            static Matrix CreateTransformationMatrix(const Microsoft::glTF::Vector3& scale, const Microsoft::glTF::Vector3& translation, const Microsoft::glTF::Quaternion& rotation)
            {
                Matrix scaleMatrix(Matrix::CreateScale(scale.x, scale.y, scale.z));
                Matrix translateMatrix(Matrix::CreateTranslation(translation.x, translation.y, translation.z));
                Matrix rotationMatrix(Matrix::CreateFromQuaternion(Utils::Math::Quaternion(rotation.x, rotation.y, rotation.z, rotation.w)));

                // GLTF 2.0 requires scale to be applied first, then rotation, then translation
                return scaleMatrix * rotationMatrix * translateMatrix;
            }
        };
    }
}