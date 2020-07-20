/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <map>
#include <PluginSDK\IResourceServer.h>
#include <Framework\Pointers.h>

#include <Asset3D/SceneNode.h>

#include <COLLADAFWUniqueId.h>
#include <COLLADAFWObject.h>

#include <TranscoderDAE/DAEToAsset3DWriter.h>
#include <TranscoderDAE/DAEAsset3DBuilder.h>

namespace Babylon
{
	namespace Transcoder
	{
		template<typename F>
		class DAEAbstractHandler {

		protected:
			DAEToAsset3DWriterContext* m_context;

		public:
			DAEAbstractHandler(DAEToAsset3DWriterContext* context) :
				m_context(context)
			{
			}

			~DAEAbstractHandler() {
			}

			inline DAEToAsset3DWriterContext* getContext() { return m_context; }

			virtual bool Handle(const F* from) = 0;
		};


		template<typename F, typename T>
		class DAEAbstractConverter : public DAEAbstractHandler<F> {

		public:
			DAEAbstractConverter(DAEToAsset3DWriterContext * context) : DAEAbstractHandler<F>(context)
			{
			}

			~DAEAbstractConverter() {
			}

			bool Handle(const F* from) {
				if (m_context) {
					m_context->CheckCancelledAndThrow();
				}
				return this->Convert(from) != nullptr;
			}

			inline std::shared_ptr<T> GetNode(const F* from) {
				if (m_context) {
					m_context->CheckCancelledAndThrow();
				}
				return  this->Convert(from);
			}

			virtual std::shared_ptr<T> Convert(const F* from) = 0;
		};

	}
}
