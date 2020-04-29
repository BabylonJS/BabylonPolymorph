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

namespace Babylon
{
	namespace Transcoder
	{
		template<typename F = COLLADAFW::Object, typename T = SceneNode>
		class AbstractDAEConverter {

		private:
			Babylon::Framework::ICancellationTokenPtr m_cancellationToken;
			IResourceServer * m_resourceServer;

		public:
			AbstractDAEConverter(IResourceServer * resourceServer, Babylon::Framework::ICancellationTokenPtr cancellationToken) :
				m_cancellationToken(cancellationToken),
				m_resourceServer(resourceServer)
			{
			}

			~AbstractDAEConverter() {
			}

			inline std::shared_ptr<T*> GetNode(const F* from) {
				if (m_cancellationToken) {
					m_cancellationToken->CheckCancelledAndThrow();
				}
				T * t = this->Convert(from);
				return std::make_shared<T*>(t);
			}

			virtual T* Convert(const F* from) = 0;
		};

	}
}
