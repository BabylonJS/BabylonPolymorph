//
//  TextureMetadata.h
//  CanvasTex.macOS.CPP
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#pragma once

#include <CanvasTex/Format.h>
#include <CanvasTex/TextureMetadata.h>

namespace CanvasTex
{
    class TextureMetadataBase::TextureMetadataImplementation
    {
    public:
        size_t width;
        size_t height;
        size_t rowPitch;
        size_t slicePitch;
        size_t depth;
        size_t arraySize;
        size_t mipLevels;
        TextureFormat format;
    };
}
