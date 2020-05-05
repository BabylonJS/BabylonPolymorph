/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAEFXConverter.h>

using namespace Babylon::Transcoder;

std::shared_ptr<MaterialDescriptor> DAEMaterialConverter::Convert(const COLLADAFW::Material * colladaMaterial) {
	std::shared_ptr<MaterialDescriptor> material = std::make_shared<MaterialDescriptor>();
	return material;
}
