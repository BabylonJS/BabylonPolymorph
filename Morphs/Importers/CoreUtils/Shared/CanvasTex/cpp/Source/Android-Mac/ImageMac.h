#pragma once

#include <CanvasTex/Image.h>
#include "TextureMetadata.h"
#include "TextureConversion.h"
#include <gli/image.hpp>

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

class ImageBase::ImageImplementation
{
public:

    size_t width;
    size_t height;
    size_t rowPitch;
    size_t slicePitch;
    TextureFormat format;

    uint8_t* pixels;

    void SetGliImage(gli::image image)
    {
        width = image.extent().x;
        height = image.extent().y;
        rowPitch = width * gli::block_size(image.format());
        slicePitch = rowPitch * height;
        pixels = static_cast<uint8_t*>(image.data());
        format = GetCanvasTextureFormat(image.format());
    }
};

} // namespace CanvasTex
