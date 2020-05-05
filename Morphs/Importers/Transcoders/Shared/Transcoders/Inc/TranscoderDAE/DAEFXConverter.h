/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/AbstractDAEConverter.h>
#include <Asset3D/MaterialDescriptor.h>

#include <COLLADAFWMaterial.h>

namespace Babylon
{
	namespace Transcoder
	{
		/// IMAGE converter
		class DAEImageConverter : public AbstractDAEConverter<COLLADAFW::Image, TextureDescriptor> {
		public:
			DAEImageConverter(Asset3DWriterContext* context) :
				AbstractDAEConverter(context) {
			}
			std::shared_ptr<TextureDescriptor> Convert(const COLLADAFW::Image* from);
		};

		/// Material converter
		class DAEMaterialConverter : public AbstractDAEConverter<COLLADAFW::Material, MaterialDescriptor> {
		public:
			DAEMaterialConverter(Asset3DWriterContext* context) :
				AbstractDAEConverter(context) {
			}
			std::shared_ptr<MaterialDescriptor> Convert(const COLLADAFW::Material* from);
		};

	}
}
