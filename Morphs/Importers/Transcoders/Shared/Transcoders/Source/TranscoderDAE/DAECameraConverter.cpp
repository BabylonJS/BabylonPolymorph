/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <TranscoderDAE/DAECoreConverter.h>
#include <TranscoderDAE/DAECameraBuilder.h>
#include <COLLADAFWCamera.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAECameraBuilder> DAECameraConverter::Convert(const COLLADAFW::Camera* colladaCamera) {
	std::shared_ptr<DAECameraBuilder> builder = nullptr;
	
	switch (colladaCamera->getCameraType()) {
	case COLLADAFW::Camera::CameraType::ORTHOGRAPHIC : {
		builder = std::make_shared<DAECameraBuilder>(getContext());
		builder->WithProjectionType(ProjectionType::kOrthographic);
		float x, y;
		switch (colladaCamera->getDescriptionType()) {
		case COLLADAFW::Camera::UNDEFINED:
			builder->WithXMag(1.0).WithYMag(1.0);
			break;
		case COLLADAFW::Camera::ASPECTRATIO_AND_X:
			// fall through to single X if aspect ratio is zero
			if (colladaCamera->getAspectRatio().getValue() != 0) {
				x = (float)colladaCamera->getXMag().getValue();
				builder->WithXMag(x).WithYMag(x / (float)colladaCamera->getAspectRatio().getValue());
				break;
			}
		case COLLADAFW::Camera::SINGLE_X:
			builder->WithXMag((float)colladaCamera->getXMag().getValue()).WithYMag(1.0);
			break;
		case COLLADAFW::Camera::SINGLE_Y:
			builder->WithXMag(1.0).WithYMag((float)colladaCamera->getYMag().getValue());
			break;
		case COLLADAFW::Camera::X_AND_Y:
			builder->WithXMag((float)colladaCamera->getXMag().getValue()).WithYMag((float)colladaCamera->getYMag().getValue());
			break;
		case COLLADAFW::Camera::ASPECTRATIO_AND_Y:
			y = (float)colladaCamera->getYMag().getValue();
			builder->WithXMag(y * (float)colladaCamera->getAspectRatio().getValue()).WithYMag(y);
			break;
		};
		break;
	}
	case COLLADAFW::Camera::CameraType::PERSPECTIVE:
	{
		builder = std::make_shared<DAECameraBuilder>(getContext());
		builder->WithProjectionType(ProjectionType::kPerspective);
		float x = (float)(colladaCamera->getXFov().getValue() * (M_PI / 180.0));
		float y = (float)(colladaCamera->getYFov().getValue() * (M_PI / 180.0));
		float aspectRatio = (float)colladaCamera->getAspectRatio().getValue();
		switch (colladaCamera->getDescriptionType()) {
		case COLLADAFW::Camera::UNDEFINED:
		case COLLADAFW::Camera::SINGLE_X:
			builder->WithYFov(1.0);
			break;
		case COLLADAFW::Camera::SINGLE_Y:
			builder->WithYFov(y);
			break;
		case COLLADAFW::Camera::X_AND_Y:
			builder->WithYFov(y).WithAspectRatio(x / y);
			break;
		case COLLADAFW::Camera::ASPECTRATIO_AND_X:
			builder->WithYFov(x / aspectRatio).WithAspectRatio(y);
			break;
		case COLLADAFW::Camera::ASPECTRATIO_AND_Y:
			builder->WithYFov(y).WithAspectRatio(aspectRatio);
			break;
		}
		break;
	}
	}
	if (builder) {
		float scale = getContext()->getScaleMeter();
		builder->WithZFar((float)colladaCamera->getFarClippingPlane().getValue() * scale)
			.WithZNear((float)colladaCamera->getNearClippingPlane().getValue() * scale)
			.WithName(colladaCamera->getName() == "" ? colladaCamera->getOriginalId() : colladaCamera->getName());
	}
	return builder;
}
