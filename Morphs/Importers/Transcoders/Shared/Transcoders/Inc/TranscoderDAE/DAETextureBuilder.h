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
		class DAETextureBuilder : public DAEAsset3DBuilder<TextureDescriptor> {

		private:
			std::string m_path;
			std::shared_ptr<TextureDescriptor> m_cache;

		public:
			DAETextureBuilder(DAEToAsset3DWriterContextPtr context) : DAEAsset3DBuilder(context),
				m_path(""),
				m_cache(nullptr)
			{
			}

			std::shared_ptr<TextureDescriptor> Build() {

				if (!m_cache) {
					DAEToAsset3DWriterContextPtr ctx = GetContext();
					if (auto textureStream = ctx->getRessourceServer()->RequestResource(m_path))
					{
						size_t textureSize = 0;
						auto textureData = Babylon::Utils::ReadStreamIntoUniquePtr(*textureStream, textureSize);
						m_cache = std::make_shared<TextureDescriptor>(std::move(textureData), textureSize);
						uint32_t lineStride = m_cache->GetLineStrideInBytes();

						m_cache->SetName(GetName());
					}
				}
				return m_cache;
			}

			inline DAETextureBuilder & WithPath(std::string path) {
				m_path = path;
				return *this;
			}

			inline DAETextureBuilder& ClearCache() {
				m_cache = nullptr;
				return *this;
			}
		};
	}
}
