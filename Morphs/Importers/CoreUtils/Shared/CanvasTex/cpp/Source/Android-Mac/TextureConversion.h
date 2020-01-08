//
// Copyright (C) Microsoft.  All rights reserved.
//

#pragma once

#include <CanvasTex/Format.h>
#include <CanvasTex/CanvasTex.h>
#include "GliIncludes.h"
#include "TextureLoaders.h"

namespace CanvasTex
{
    class CanvasPixelFormatDesc32
    {
    public:
        constexpr static int RedIndex   = 0;
        constexpr static int GreenIndex = 1;
        constexpr static int BlueIndex  = 2;
        constexpr static int AlphaIndex = 3;

        int bitsPerPixel;

        // mask = 0xFF << shiftDown

        int shiftDown[4];
        int shiftUp[4];
    };

    std::unique_ptr<uint8_t[]> Convert32(
             const uint8_t* pSource,
             size_t width,
             size_t height,
             size_t bytesPerRow,
             CanvasPixelFormatDesc32 const& inputDesc,
             CanvasPixelFormatDesc32 const& outputDesc);

    void MakePixelFormatDescFromTextureFormat(CanvasPixelFormatDesc32& desc, TextureFormat format);

    bool IsDDS(void const* pSource);
    gli::texture LoadDDS(void const* pSource, size_t inLength);

    TextureFormat GetCanvasTextureFormat(gli::format format);
    gli::format GetGliTextureFormat(TextureFormat foramt);

}
