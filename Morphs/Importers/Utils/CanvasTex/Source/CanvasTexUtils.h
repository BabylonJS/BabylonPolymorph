/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <CanvasTex/CanvasTex.h>


namespace CanvasTex
{
    template<typename Fn>
    void PrepareAndProcess(const ConstImage& image, TextureFormat textureFormat, const Fn& fn)
    {
        if (textureFormat == TextureFormat::Unknown)
        {
            textureFormat = TextureFormat::B8g8r8a8Unorm;
        }

        if (IsCompressed(image.GetFormat()))
        {
            ScratchImage uncompressed;
            Decompress(image, textureFormat, uncompressed);

            fn(uncompressed.GetImage(0, 0));
        }
        else if (image.GetFormat() != textureFormat)
        {
            ScratchImage converted;
            Convert(image, textureFormat, converted);

            fn(converted.GetImage(0, 0));
        }
        else
        {
            fn(image);
        }
    }
}
