/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "TextureLoaders.h"
#include "GliIncludes.h"

namespace CanvasTex
{
      typedef struct
     {
       size_t width;
       size_t height;
     } MetadataInfo;

    class IImageProcessor
    {
    public:
        IImageProcessor() {}
        virtual ~IImageProcessor() {}

        virtual std::vector<uint8_t> decompressImage(const void* pSource, size_t inLength) const = 0;

        virtual std::vector<uint8_t> compressImage(const uint8_t* pSource, size_t width, size_t height) const = 0;

        virtual MetadataInfo getImageMetadata(const void* pSource, size_t inLength) const = 0;
    };
} // End namespace CanvasTex