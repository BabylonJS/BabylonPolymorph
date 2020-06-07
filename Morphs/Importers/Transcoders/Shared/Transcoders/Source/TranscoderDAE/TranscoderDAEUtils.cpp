/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAENodeBuilder.h>

#include <COLLADAFWRotate.h>
#include <COLLADAFWTranslate.h>
#include <COLLADAFWScale.h>
#include <COLLADAFWLookat.h>

Babylon::Utils::Math::Matrix  Babylon::Transcoder::toBabylonMatrix(COLLADABU::Math::Matrix4 colladaMatrix) {

	const COLLADABU::Math::Real* m[4];
	m[0] = colladaMatrix[0];
	m[1] = colladaMatrix[1];
	m[2] = colladaMatrix[2];
	m[3] = colladaMatrix[3];

	/**
	 * The Babylon math library packs matrices in a row major order.
	 * According to specification "Matrices in COLLADA are column matrices in the mathematical sense".
	 * we then need to transpose.
	 */

	return Babylon::Utils::Math::Matrix(m[0][0], m[1][0], m[2][0], m[3][0],
		m[0][1], m[1][1], m[2][1], m[3][1],
		m[0][2], m[1][2], m[2][2], m[3][2],
		m[0][3], m[1][3], m[2][3], m[3][3]);	
}

COLLADABU::Math::Matrix4  Babylon::Transcoder::getMatrixFromTransform(const COLLADAFW::Transformation* transform, float assetScale) {
	switch (transform->getTransformationType()) {
	case COLLADAFW::Transformation::ROTATE: {
		COLLADAFW::Rotate* rotate = (COLLADAFW::Rotate*)transform;
		COLLADABU::Math::Vector3 axis = rotate->getRotationAxis();
		axis.normalise();
		double angle = rotate->getRotationAngle();
		return COLLADABU::Math::Matrix4(COLLADABU::Math::Quaternion(COLLADABU::Math::Utils::degToRad(angle), axis));
	}
	case COLLADAFW::Transformation::TRANSLATE: {
		COLLADAFW::Translate* translate = (COLLADAFW::Translate*)transform;
		const COLLADABU::Math::Vector3& translation = translate->getTranslation();
		COLLADABU::Math::Matrix4 translationMatrix;
		translationMatrix.makeTrans(translation);
		translationMatrix.scaleTrans(assetScale);
		return translationMatrix;
	}
	case COLLADAFW::Transformation::SCALE: {
		COLLADAFW::Scale* scale = (COLLADAFW::Scale*)transform;
		const COLLADABU::Math::Vector3& scaleVector = scale->getScale();
		COLLADABU::Math::Matrix4 scaleMatrix;
		scaleMatrix.makeScale(scaleVector);
		return scaleMatrix;
	}
	case COLLADAFW::Transformation::MATRIX: {
		COLLADAFW::Matrix* transformMatrix = (COLLADAFW::Matrix*)transform;
		COLLADABU::Math::Matrix4 matrix = transformMatrix->getMatrix();
		matrix.scaleTrans(assetScale);
		return matrix;
	}
	case COLLADAFW::Transformation::LOOKAT: {
		COLLADAFW::Lookat* lookAt = (COLLADAFW::Lookat*)transform;
		const COLLADABU::Math::Vector3& eye = lookAt->getEyePosition();
		const COLLADABU::Math::Vector3& center = lookAt->getInterestPointPosition();
		const COLLADABU::Math::Vector3& up = lookAt->getUpAxisDirection();
		COLLADABU::Math::Matrix4 lookAtMatrix = COLLADABU::Math::Matrix4::IDENTITY;
		if ((eye.x != center.x) || (eye.y != center.y) || (eye.z != center.z)) {
			COLLADABU::Math::Vector3 z = (eye - center);
			z.normalise();
			COLLADABU::Math::Vector3 x = up.crossProduct(z);
			x.normalise();
			COLLADABU::Math::Vector3 y = z.crossProduct(x);
			y.normalise();
			lookAtMatrix.setAllElements(
				x.x, y.x, z.x, 0,
				x.y, y.y, z.y, 0,
				x.z, y.z, z.z, 0,
				-(x.x * eye.x + x.y * eye.y + x.z * eye.z),
				-(y.x * eye.x + y.y * eye.y + y.z * eye.z),
				-(z.x * eye.x + z.y * eye.y + z.z * eye.z),
				1);
			lookAtMatrix = lookAtMatrix.inverse();
			lookAtMatrix = lookAtMatrix.transpose();
		}
		lookAtMatrix.scaleTrans(assetScale);
		return lookAtMatrix;
	}
	}
	return COLLADABU::Math::Matrix4::IDENTITY;
}

float Babylon::Transcoder::sum_kahan(float *x, int N) {
	float s = x[0];
	float c = 0.0;
	for (int i = 1; i < N; i++) {
		float y = x[i] - c;
		float t = s + y;
		c = (t - s) - y;
		s = t;
	}
	return s;
}

std::vector<COLLADAFW::UniqueId> Babylon::Transcoder::findRoots(std::vector<COLLADAFW::UniqueId>& elements, DAEToAsset3DWriterContext* context) {
	/// build a list of corresponding builders
	std::vector<DAENodeBuilder*> base;
	base.reserve(elements.size());
	for (auto id : elements) {
		base.push_back(context->getNodeLibrary()[id].get());
	}
	std::vector<COLLADAFW::UniqueId> result;
	for (auto b : base) {
		if (b && (b->GetParent() == nullptr || !std::count(base.begin(), base.end(), b->GetParent()))) {
			result.push_back(b->GetUniqueId());
		}
	}
	return result;
}
