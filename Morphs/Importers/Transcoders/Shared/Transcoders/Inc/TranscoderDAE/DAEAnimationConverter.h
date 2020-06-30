/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAnimation.h>
#include <TranscoderDAE/DAEConverter.h>
#include <TranscoderDAE/DAENodeAnimationBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAEAnimationConverter : public DAEAbstractConverter<COLLADAFW::Animation, DAEAnimationData> {
		public:
			DAEAnimationConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAEAnimationData> Convert(const COLLADAFW::Animation* from);
		};

		class DAEMorphConverter : public DAEAbstractConverter<COLLADAFW::MorphController, DAENodeAnimationBuilder> {
		public:
			DAEMorphConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAENodeAnimationBuilder> Convert(const COLLADAFW::MorphController* from);
		};

		class DAESkinControllerConverter : public DAEAbstractConverter<COLLADAFW::SkinController, DAESkinController> {
		public:
			DAESkinControllerConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAESkinController> Convert(const COLLADAFW::SkinController* from);
		};


		class DAESkinControllerDataConverter : public DAEAbstractConverter<COLLADAFW::SkinControllerData, DAESkinData> {
		public:
			DAESkinControllerDataConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAESkinData> Convert(const COLLADAFW::SkinControllerData* from);
		};

	}
}
#pragma once
