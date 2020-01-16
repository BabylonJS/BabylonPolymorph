//
//  TextureLoaders.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#pragma once

#include <CanvasTex/Format.h>
#include <CanvasTex/CanvasTex.h>
#include "GliIncludes.h"
#include "TextureMetadata.h"
#include <vector>

namespace CanvasTex
{
    gli::texture loadImage(void const* pSource, size_t inLength);

    bool imageGetMetadata(void const* pSource, size_t inLength, TextureMetadata& metadata);

    gli::texture imageConvert(const uint8_t* pSource, size_t width, size_t height, TextureFormat format);

    bool saveImageToMemory(const uint8_t* pSource, OutputFormat outputFormat, size_t width, size_t height, TextureFormat format, std::vector<uint8_t> &imageData);

    bool saveImageToFile(const uint8_t* pSource, OutputFormat outputFormat, size_t width, size_t height, TextureFormat format, const std::string& fileName);

    gli::texture resizeImage(void const* pSource, size_t srcWidth, size_t srcHeight, TextureFormat srcFormat, size_t targetWidth, size_t targetHeight);
} // namespace CanvasTex
