/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <stddef.h>

namespace Spectre
{
    namespace Transcoder
    {
        class ITranscoderBuffer
        {
        public:
            virtual size_t GetBufferSize() const = 0;
            virtual const void* GetBufferPtr() = 0;
        };
    } // Transcoder
} // Spectre