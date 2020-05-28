/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <TranscoderDAE/DAECoreConverter.h>
#include <TranscoderDAE/DAELightBuilder.h>
#include <COLLADAFWLight.h>

using namespace Babylon::Transcoder;

std::shared_ptr<DAELightBuilder> DAELightConverter::Convert(const COLLADAFW::Light* colladaLight) {
	
	std::shared_ptr<DAELightBuilder> builder = std::make_shared<DAELightBuilder>(getContext());

	switch (colladaLight->getLightType()) {
	case COLLADAFW::Light::AMBIENT_LIGHT:
		builder->WithType(LightType::AMBIENT);
		break;
	case COLLADAFW::Light::DIRECTIONAL_LIGHT:
		builder->WithType(LightType::DIRECTIONAL);
		break;
	case COLLADAFW::Light::POINT_LIGHT:
		builder->WithType(LightType::POINT)
			.WithConstantAttenuation((float)colladaLight->getConstantAttenuation())
			.WithLinearAttenuation((float)colladaLight->getLinearAttenuation())
			.WithQuadraticAttenuation((float)colladaLight->getQuadraticAttenuation());
		break;
	}

	auto c = colladaLight->getColor();
	builder->WithColor(c.getRed(), c.getGreen(), c.getBlue(), c.getAlpha());

	return builder;
}
