/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEConverter.h>
#include <Asset3D/SceneNode.h>
#include <COLLADAFWScene.h>
#include <COLLADAFWNode.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAENodeConverter : public DAEAbstractConverter<COLLADAFW::Node, SceneNode> {
		public:
			DAENodeConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<SceneNode> Convert(const COLLADAFW::Node* from);
			std::shared_ptr<SceneNode> Convert(const COLLADAFW::Node* colladaNode, std::shared_ptr<SceneNode> node);
			std::shared_ptr<SceneNode> ConvertBreadthFirst(const COLLADAFW::NodePointerArray* nodes, std::shared_ptr<SceneNode> node = nullptr);
		};

		class DAEVirtualSceneConverter : public DAEAbstractConverter<COLLADAFW::VisualScene, Asset3D> {
		public:
			DAEVirtualSceneConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<Asset3D> Convert(const COLLADAFW::VisualScene* from);
		};

	}
}