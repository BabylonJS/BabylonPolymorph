/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include "GLTFSDK/IStreamReader.h"

#include <PluginSDK/IResourceServer.h>
#include "TranscoderException.h"

namespace Babylon
{
    namespace Transcoder
    {
        class IStreamReaderRSAdapter : public Microsoft::glTF::IStreamReader
        {
        public:
            IStreamReaderRSAdapter(IResourceServer* resourceServer)
                : m_resourceServer(resourceServer)
            {
            }

            std::shared_ptr<std::istream> GetInputStream(const std::string& filename) const override
            {
                std::shared_ptr<std::istream> stream;
                try
                {
                    stream = m_resourceServer->RequestResource(filename);
                }
                catch (const std::exception& ex)
                {
                    throw TranscoderResourceFailedException(ex.what());
                }

                if (stream == nullptr)
                {
                    throw TranscoderResourceFailedException("resource not found or empty. " + filename);
                }

                return stream;
            }

        private:
            IResourceServer* const m_resourceServer;
        };
    }
}
