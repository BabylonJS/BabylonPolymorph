/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAECoreConverter.h>
#include <TranscoderDAE/DAECameraBuilder.h>
#include <COLLADAFWCamera.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAECameraBuilder> DAECameraConverter::Convert(const COLLADAFW::Camera* colladaCamera) {
	std::shared_ptr<DAECameraBuilder> builder = std::make_shared<DAECameraBuilder>(getContext());
	switch (colladaCamera->getCameraType()) {
	case COLLADAFW::Camera::CameraType::ORTHOGRAPHIC : {
		builder->WithProjectionType(ProjectionType::kOrthographic)
			.WithZFar((float)colladaCamera->getFarClippingPlane())
			.WithZNear((float)colladaCamera->getNearClippingPlane())
			.WithXMag((float)colladaCamera->getXMag())
			.WithYMag((float)colladaCamera->getYMag()).WithName(colladaCamera->getName());
			break;
	}
	case COLLADAFW::Camera::CameraType::PERSPECTIVE:
	default:
	{
		builder->WithProjectionType(ProjectionType::kPerspective)
			.WithZFar((float)colladaCamera->getFarClippingPlane())
			.WithZNear((float)colladaCamera->getNearClippingPlane())
			.WithYFov((float)colladaCamera->getYFov())
			.WithAspectRatio((float)colladaCamera->getAspectRatio()).WithName(colladaCamera->getName());
	}
	}
	return builder;
}
