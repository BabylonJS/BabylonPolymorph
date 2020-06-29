/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace Babylon
{
	namespace Transcoder
	{

		/** pre-declaration */
		template<typename TAsset, typename TContext>
		class Asset3DInstanceBuilder;

		/** Builder base class */
		template<typename TAsset, typename TContext>
		class Asset3DBuilder {

		protected:
			TContext * m_context;
			std::string m_name;
		public:
			Asset3DBuilder(TContext * context) :
				m_context(context)
			{
			}

			~Asset3DBuilder() {
			}

			inline TContext * GetContext() { return m_context; }
			inline std::string GetName() { return m_name; }

			inline Asset3DBuilder& WithName(std::string name) {
				m_name = std::move(name);
				return *this;
			}

			virtual std::shared_ptr<TAsset> Build(std::shared_ptr<TAsset> existingAsset = nullptr) = 0;
		};

		template<typename TAsset, typename TContext>
		class Asset3DBuilderWithCache : public Asset3DBuilder<TAsset,TContext> {
		protected:
			std::shared_ptr<TAsset> m_cache;
		public:
			Asset3DBuilderWithCache(TContext* context) :
				Asset3DBuilder(context),
				m_cache(nullptr)
			{
			}

			std::shared_ptr<TAsset> Build(std::shared_ptr<TAsset> existingAsset = nullptr) {
				if (!m_cache) {
					m_cache = BuildCache(existingAsset);
				}
				return m_cache;
			}

			inline Asset3DBuilderWithCache & ClearCache() {
				m_cache = nullptr;
				return *this;
			}

			virtual std::shared_ptr<TAsset> BuildCache(std::shared_ptr<TAsset> existingAsset = nullptr) {
				return existingAsset;
			}
		};
	}
}
