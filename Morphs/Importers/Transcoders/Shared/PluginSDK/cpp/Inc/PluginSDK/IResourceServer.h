/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/TranscoderTextStream.h>

namespace Spectre
{
    namespace Transcoder
    {
        class IResourceServer
        {
        public:
            virtual ~IResourceServer() = default;

            /// Implementors must provide this blocking method to return the resource (or nullptr if the resource couldn't be located)
            virtual std::shared_ptr<std::istream> RequestResource(const std::string& fileName) const = 0;

            std::shared_ptr<TranscoderTextStream> RequestTextFileResource(const std::string& fileName) const
            {
                if (auto stream = RequestResource(fileName))
                {
                    //Decorate the incoming stream without copying it
                    return std::make_shared<TranscoderTextStream>(stream);
                }
                return nullptr;
            }
        };
    }
}