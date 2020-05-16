/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once


#include <TranscoderDAE/DAEAsset3DBuilder.h>
#include <coreUtils/streamUtils.h>

#include <PluginSDK/IResourceServer.h>
#include <Asset3D/MaterialDescriptor.h>

namespace Babylon
{
	namespace Transcoder
	{
		class DAETextureBuilder : public DAEAsset3DBuilderWithCache<TextureDescriptor> {

		private:
			std::string m_path;

		public:
			DAETextureBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilderWithCache(context),
				m_path(""){
			}

			std::shared_ptr<TextureDescriptor> BuildCache() {
				std::shared_ptr<TextureDescriptor> td;
				DAEToAsset3DWriterContextPtr ctx = GetContext();
				if (auto textureStream = ctx->getRessourceServer()->RequestResource(m_path))
				{
					size_t textureSize = 0;
					auto textureData = Babylon::Utils::ReadStreamIntoUniquePtr(*textureStream, textureSize);
					td = std::make_shared<TextureDescriptor>(std::move(textureData), textureSize);
					uint32_t lineStride = td->GetLineStrideInBytes();
					td->SetName(GetName());
				}
				return td;
			}

			inline DAETextureBuilder & WithPath(std::string path) {
				m_path = path;
				return *this;
			}
		};
	}
}
