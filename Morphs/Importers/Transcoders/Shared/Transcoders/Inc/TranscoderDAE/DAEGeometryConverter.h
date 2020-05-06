/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEConverter.h>
#include <Asset3D/Mesh.h>
#include <COLLADAFWGeometry.h>
#include <COLLADAFWMesh.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAEMeshConverter : public DAEAbstractConverter<COLLADAFW::Mesh, Mesh> {
		public:
			DAEMeshConverter(DAEToAsset3DWriterContext* context) :
				DAEAbstractConverter(context) {
			}
			std::shared_ptr<Mesh> Convert(const COLLADAFW::Mesh* from);
		};

	}
}
