/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <memory>

#include <Asset3D/Asset3D.h>
#include <Asset3D/TextureDescriptor.h>
#include <PluginSDK/IResourceServer.h>

namespace Babylon
{
    namespace Transcoder
    {
        class TextureFactory;

        /*
        * The class is used to parse a text file containing 3D asset data.
        * Child classes need to implement ProcessNonEmptyLine() and FinalizeFile()
        * to control the creation of different Descriptors to be encoded to BXF.
        */
        class IParser
        {
        public:
            explicit IParser(IResourceServer& resourceServer) :
                m_resourceServer(resourceServer)
            {
            }

        protected:
            IResourceServer& m_resourceServer;
        };
    }
}
