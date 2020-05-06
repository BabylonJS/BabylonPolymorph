/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEConverter.h>
#include <Asset3D/MaterialDescriptor.h>

#include <COLLADAFWMaterial.h>
#include <COLLADAFWTexture.h>
#include <COLLADAFWSampler.h>
#include <COLLADAFWEffect.h>
#include <COLLADAFWEffectCommon.h>

namespace Babylon
{
	namespace Transcoder
	{
		/// IMAGE converter
		class DAEImageConverter : public DAEAbstractConverter<COLLADAFW::Image, TextureDescriptor> {
		public:
			DAEImageConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<TextureDescriptor> Convert(const COLLADAFW::Image* from);
		};

		/// Material converter
		class DAEEffectConverter : public DAEAbstractConverter<COLLADAFW::Effect, MaterialDescriptor> {
		public:
			DAEEffectConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}

			std::shared_ptr<TextureDescriptor> fromColladaTexture(const COLLADAFW::EffectCommon* effectCommon, COLLADAFW::Texture colladaTexture);
			std::shared_ptr<TextureDescriptor> fromColladaTexture(const COLLADAFW::EffectCommon* effectCommon, COLLADAFW::SamplerID samplerId);

			std::shared_ptr<MaterialDescriptor> Convert(const COLLADAFW::Effect* from);
		};

	}
}
