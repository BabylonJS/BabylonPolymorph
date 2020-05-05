/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/AbstractDAEConverter.h>
#include <Asset3D/SceneNode.h>
#include <COLLADAFWScene.h>

namespace Babylon
{
	namespace Transcoder
	{

		class DAEVirtualSceneConverter : public AbstractDAEConverter<COLLADAFW::VisualScene, Asset3D> {
		public:
			DAEVirtualSceneConverter(Asset3DWriterContext* context) :
				AbstractDAEConverter(context) {
			}
			std::shared_ptr<Asset3D> Convert(const COLLADAFW::VisualScene* from);
			std::shared_ptr<SceneNode> Convert(const COLLADAFW::Node * from);
		};

	}
}
