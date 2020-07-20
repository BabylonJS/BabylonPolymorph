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
		class DAETextureBuilder;
		class DAEMaterialBuilder;

		/// IMAGE converter
		class DAEImageConverter : public DAEAbstractConverter<COLLADAFW::Image, DAETextureBuilder> {
		public:
			DAEImageConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAETextureBuilder> Convert(const COLLADAFW::Image* from);
		};

		/// Material converter
		class DAEEffectConverter : public DAEAbstractConverter<COLLADAFW::Effect, DAEMaterialBuilder> {
		public:
			DAEEffectConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}

			std::shared_ptr<DAEMaterialBuilder> Convert(const COLLADAFW::Effect* from);

		private:
			std::shared_ptr<MaterialDescriptor::LayerInfo> SetLayer(const COLLADAFW::EffectCommon* effectCommon, const COLLADAFW::ColorOrTexture* src, std::shared_ptr<DAEMaterialBuilder> material);
		};

	}
}
