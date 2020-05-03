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

#include <TranscoderDAE/Asset3DColladaFWWriter.h>

namespace Babylon
{
	namespace Transcoder
	{
		template<typename F = COLLADAFW::Object, typename T = SceneNode>
		class AbstractDAEConverter {

		protected:
			Asset3DWriterContext* m_context;

		public:
			AbstractDAEConverter(Asset3DWriterContext * context) :
				m_context(context)
			{
			}

			~AbstractDAEConverter() {
			}

			inline std::shared_ptr<T> GetNode(const F* from) {
				if (m_context) {
					m_context->CheckCancelledAndThrow();
				}
				return  this->Convert(from);
			}

			inline Asset3DWriterContext* getContext() { return m_context; }

			virtual std::shared_ptr<T> Convert(const F* from) = 0;
		};

	}
}
