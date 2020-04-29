/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>

#include <TranscoderDAE/AbstractDAEConverter.h>
#include <Asset3D/Geometry.h>
#include <COLLADAFWGeometry.h>

namespace Babylon
{
	namespace Transcoder
	{
		class IResourceServer;

		class DAEGeometryConverter : public AbstractDAEConverter<COLLADAFW::Geometry, Geometry> {
		public:
			DAEGeometryConverter(IResourceServer* resourceServer, Framework::ICancellationTokenPtr cancellationToken) : 
				AbstractDAEConverter(resourceServer, cancellationToken) {
			}
			Geometry * Convert(const COLLADAFW::Geometry * from);
		};

	}
}
