/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "GLTFSDK/IStreamWriter.h"

#include <PluginSDK/IOutputStreamFactory.h>

namespace Spectre
{
    namespace Transcoder
    {
        class IStreamWriterOSFAdapter : public Microsoft::glTF::IStreamWriter
        {
        public:
            IStreamWriterOSFAdapter(IOutputStreamFactory& outputStreamFactory)
                : m_outputStreamFactory(outputStreamFactory)
            {
            }

            std::shared_ptr<std::ostream> GetOutputStream(const std::string& filename) const override
            {
                return m_outputStreamFactory.CreateStream(filename);
            }

        private:
            IOutputStreamFactory& m_outputStreamFactory;
        };
    }
}
