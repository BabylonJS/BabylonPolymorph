/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <Transcoders.h>
#include <JTSDK\IConsumer.h>

namespace Babylon
{
    namespace Transcoder
    {
        class JTConsumerContext {


        };

		typedef JTConsumerContext * JTConsumerContextPtr;

        class JTConsumer : public JTSDK::IConsumer {

		private:
			JTConsumerContext m_context;

		public:
			JTConsumer(IResourceServer* resourceServer, const std::unordered_map<std::string, std::string>& options, Framework::ICancellationTokenPtr cancellationToken);
			~JTConsumer();

			inline const JTConsumerContextPtr getContext() { return &(this->m_context); }
		};
    }
}
