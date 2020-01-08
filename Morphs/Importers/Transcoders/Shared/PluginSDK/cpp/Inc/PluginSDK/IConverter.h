/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <stdint.h>

namespace Spectre
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
            virtual void ConversionCompleted(SpectreAsyncStatus status) = 0;
            virtual void FrameCreated(Spectre::Framework::Frame* frame, uint32_t size) = 0;
        };
    }
}