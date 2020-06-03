/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEAnimation.h>
#include <TranscoderDAE/DAEConverter.h>
#include <TranscoderDAE/DAENodeAnimationBuilder.h>
#include <TranscoderDAE/DAESkeletalAnimationBuilder.h>
#include <TranscoderDAE/DAESkeletonBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAESkeletalAnimationConverter : public DAEAbstractConverter<COLLADAFW::Animation, DAESkeletalAnimationBuilder> {
		public:
			DAESkeletalAnimationConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAESkeletalAnimationBuilder> Convert(const COLLADAFW::Animation* from);
		};

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

		class DAESkinControllerConverter : public DAEAbstractConverter<COLLADAFW::SkinController, DAESkeletonBuilder> {
		public:
			DAESkinControllerConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<DAESkeletonBuilder> Convert(const COLLADAFW::SkinController* from);
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
