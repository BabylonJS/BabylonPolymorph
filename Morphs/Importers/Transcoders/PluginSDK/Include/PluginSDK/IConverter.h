/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <stdint.h>

namespace Babylon
{
    namespace Framework
    {
        struct Frame;
    }

    namespace Transcoder
    {
        class IConverter
        {
        public:
            virtual void ConversionCompleted(BabylonAsyncStatus status) = 0;
            virtual void FrameCreated(Babylon::Framework::Frame* frame, uint32_t size) = 0;
        };
    }
}