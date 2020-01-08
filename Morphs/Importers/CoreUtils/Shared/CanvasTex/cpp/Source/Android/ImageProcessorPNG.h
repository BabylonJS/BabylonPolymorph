/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "IImageProcessor.h"

namespace CanvasTex
{
    class ImageProcessorPNG : public IImageProcessor
    {
    public:
        ImageProcessorPNG() = default;
        virtual ~ImageProcessorPNG() = default;

        virtual std::vector<uint8_t> decompressImage(const void* pSource, size_t inLength) const override;

        virtual std::vector<uint8_t> compressImage(const uint8_t* pSource, size_t width, size_t height) const override;

        virtual MetadataInfo getImageMetadata(const void* pSource, size_t inLength) const override;
    };
} // End namespace CanvasTex