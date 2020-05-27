/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/DAECoreConverter.h>
#include <TranscoderDAE/DAETextureBuilder.h>
#include <COLLADAFWImage.h>

using namespace Babylon::Transcoder;



std::shared_ptr<DAETextureBuilder> DAEImageConverter::Convert(const COLLADAFW::Image* colladaImage) {

	const COLLADABU::URI imageUri = colladaImage->getImageURI();
	COLLADABU::URI resolvedPath = COLLADABU::URI::nativePathToUri(m_context->getBasePath() + imageUri.originalStr());

	std::shared_ptr<DAETextureBuilder> builder = std::make_shared<DAETextureBuilder>(getContext());

	builder->WithPath(resolvedPath.uriDecode(resolvedPath.getURIString())).WithName(colladaImage->getName());

	return builder;
}
