/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once
#include <Transcoders.h>
#include <JTSDK/IConsumer.h>

namespace Babylon
{
    namespace Transcoder
    {
        class Asset3D;

        class JTConsumer : JTSDK::IConsumer {

        public :
            int ConsumeAssembly(JtkAssembly CurrNode, int Level, JtkClientData* data);
            int ConsumePart(JtkPart* CurrNode, int Level, JtkClientData* data);
            int ConsumeInstance(JtkInstance CurrNode, int Level, JtkClientData* data);
        };

        std::shared_ptr<Asset3D> ImportJT(const std::string& filename, IResourceServer* resourceServer, FractionalProgressCallback progress = nullptr, Babylon::Framework::ICancellationTokenPtr cancellationToken = nullptr, const std::unordered_map<std::string, std::string>& options = {}, uint64_t* streamSize = nullptr);
    }
}
