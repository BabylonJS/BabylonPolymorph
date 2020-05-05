/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "TranscodersPch.h"

#include <TranscoderDAE/TranscoderDAEConfig.h>
#include <TranscoderDAE/TranscoderDAEUtils.h>
#include <TranscoderDAE/DAEFXConverter.h>

#include <coreUtils/streamUtils.h>

#include <COLLADAFWImage.h>

using namespace Babylon::Transcoder;

std::shared_ptr<TextureDescriptor> DAEImageConverter::Convert(const COLLADAFW::Image* colladaImage) {

    std::shared_ptr<TextureDescriptor> textureDesc = nullptr;

	const COLLADABU::URI imageUri = colladaImage->getImageURI();

	COLLADABU::URI resolvedPath = COLLADABU::URI::nativePathToUri(m_context->getBasePath() + imageUri.originalStr());

    if (auto textureStream = m_context->getRessourceServer()->RequestResource(resolvedPath.getURIString()))
    {
        size_t textureSize = 0;
        auto textureData = Babylon::Utils::ReadStreamIntoUniquePtr(*textureStream, textureSize);

        textureDesc = std::make_shared<TextureDescriptor>(std::move(textureData), textureSize);
        textureDesc->SetName(colladaImage->getName());
    }

	return textureDesc;
}
