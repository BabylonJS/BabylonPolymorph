/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>

#include <wincodec.h>

namespace CanvasTex
{
    namespace MedianCutQuantizer
    {
        void QuantizeImage(const uint8_t* const sourceData, const size_t width, const size_t height, const size_t stride, IWICBitmap* const pDest, const uint32_t nMaxColors);
    }
}
