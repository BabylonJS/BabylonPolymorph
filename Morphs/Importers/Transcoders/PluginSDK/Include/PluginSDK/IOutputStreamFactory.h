/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <string>
#include <memory>
#include <PluginSDK/FractionalProgressCallback.h>

namespace Babylon
{
    namespace Transcoder
    {
        /// Common std::ostream creation interface used by all 'ExportStatic' methods
        class IOutputStreamFactory
        {
        public:
            virtual ~IOutputStreamFactory() = default;

            /// Implementing code must construct a std::ostream for the given streamName (e.g. return std::make_shared<std::ofstream>(streamName); )
            virtual std::shared_ptr<std::ostream> CreateStream(const std::string& streamName) = 0;
        };
    }
};