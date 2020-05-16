/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <TranscoderDAE/DAEToAsset3DWriter.h>

namespace Babylon
{
	namespace Transcoder
	{
		template<typename T>
		class DAEAsset3DBuilder {

		protected:
			DAEToAsset3DWriterContextPtr m_context;
			std::string m_name;

		public:
			DAEAsset3DBuilder(DAEToAsset3DWriterContextPtr context) :
				m_context(context)
			{
			}

			~DAEAsset3DBuilder() {
			}

			inline DAEToAsset3DWriterContextPtr GetContext() { return m_context; }
			inline std::string GetName() { return m_name; }

			inline DAEAsset3DBuilder& WithName(std::string name) {
				m_name = std::move(name);
				return *this;
			}

			virtual std::shared_ptr<T> Build() = 0 ;
		};

		template<typename T>
		class DAEAsset3DBuilderWithCache : public DAEAsset3DBuilder<T> {
		protected:
			std::shared_ptr<T> m_cache;
		public:
			DAEAsset3DBuilderWithCache(DAEToAsset3DWriterContextPtr context) :
				DAEAsset3DBuilder(context),
				m_cache(nullptr)
			{
			}

			std::shared_ptr<T> Build() {
				if (!m_cache) {
					m_cache = BuildCache();
				}
				return m_cache;
			}

			inline DAEMaterialBuilder& ClearCache() {
				m_cache = nullptr;
				return *this;
			}

			virtual std::shared_ptr<T> BuildCache() = 0;
		};
	}
}
