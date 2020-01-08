/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once
#include <stdint.h>
#include <memory>
#include <vector>

namespace Lift
{
    namespace Spectre
    {
        namespace Transcoder
        {
            // TODO:    Add a generic (templated) enum to string conversion, so we can use that to generate
            //          file extension automatically.
            enum class SupportedModelTypes
            {
                FBX = 0,
                ThreeMF = 1
            };

            class IExporter
            {
            public:
                virtual std::shared_ptr<std::vector<uint8_t>> Export(const void* buffer, uint32_t buffersizeinbytes) = 0;
            };
        }

    }
}
