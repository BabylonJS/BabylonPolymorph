/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>

#include <TranscoderDAE/AbstractDAEConverter.h>
#include <Asset3D/Mesh.h>
#include <COLLADAFWGeometry.h>
#include <COLLADAFWMesh.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAEMeshConverter : public AbstractDAEConverter<COLLADAFW::Mesh, Mesh> {
		public:
			DAEMeshConverter(Asset3DWriterContext* context) :
				AbstractDAEConverter(context) {
			}
			std::shared_ptr<Mesh> Convert(const COLLADAFW::Mesh* from);
		};

	}
}
