/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <PluginSDK/IResourceServer.h>

#include <CoreUtils/StreamUtils.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Trace.h>

DEFINE_TRACE_AREA(ResourceServer, 0);

namespace Babylon
{
    namespace Transcoder
    {
        // std::ifstream implementation of Babylon::Transcoder::IResourceServer, which is needed for Import
        // Should be constructed with a path that has a trailing slash: '/' or '\\'
        class ResourceServer : public Babylon::Transcoder::IResourceServer
        {
        public:
            ResourceServer(std::string baseDirectory)
                : m_baseDirectory(std::move(baseDirectory))
            {
            }

            virtual std::shared_ptr<std::istream> RequestResource(const std::string& path) const
            {
                auto relativePath = Babylon::Utils::IsPathRelative(path) ? path : Babylon::Utils::GetPathFileName(path);
                auto absolutePath = m_baseDirectory + relativePath;
                TRACE_INFO(ResourceServer, "Reading: %s", absolutePath.c_str());

                auto istream = Babylon::Utils::CreateSharedInputFileStream(absolutePath, std::ios::binary);
                if (istream->fail())
                {
                    TRACE_WARN(ResourceServer, "Failed to read: %s", absolutePath.c_str());
                    return nullptr;
                }
                return istream;
            }
        private:
            std::string m_baseDirectory;
        };
    }
}
