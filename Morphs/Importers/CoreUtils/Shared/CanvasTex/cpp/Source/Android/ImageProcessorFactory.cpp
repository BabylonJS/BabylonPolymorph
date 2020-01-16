/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "ImageProcessorFactory.h"
#include "ImageProcessorJPEG.h"
#include "ImageProcessorPNG.h"
#include "IImageProcessor.h"
#include "png.h"

// Factory Class to create PNG or JPEG objects depending on the signature
namespace CanvasTex
{
    bool inline check_if_png(const void* data) {
        constexpr size_t sigSize = 8;
        png_byte pngSig[sigSize];
        memcpy(pngSig, data, sigSize);
        return (png_sig_cmp(pngSig, 0, sigSize) == 0);
    }

    bool inline check_if_jpeg(const void* data) {
        constexpr size_t sigSize = 3;
        return (strncmp((const char*)data, "\xFF\xD8\xFF", sigSize) == 0);
    }

    ImageFileType ImageProcessorFactory::getImageType(const void* data)
    {
        // .jpg signature:  0xFF 0xD8 0xFF
        // .png signature:  0x89 0x50 0x4E 0x47 0x0D 0x0A 0x1A 0x0A
        if (check_if_png(data))
        {
            return ImageFileType::Png;
        }
        else if (check_if_jpeg(data))
        {
            return ImageFileType::Jpeg;
        }

        return ImageFileType::Unknown;
    }

    std::unique_ptr<IImageProcessor> ImageProcessorFactory::createImageProcessor(const void* data)
    {
        ImageFileType type = ImageProcessorFactory::getImageType(data);
        return createImageProcessor(type);
    }

    std::unique_ptr<IImageProcessor> ImageProcessorFactory::createImageProcessor(ImageFileType imageFileType)
    {
        if (imageFileType == ImageFileType::Jpeg)
        {
            return std::make_unique<ImageProcessorJPEG>();
        }
        else if (imageFileType == ImageFileType::Png)
        {
            return std::make_unique<ImageProcessorPNG>();
        }

        return nullptr;
    }
} // End namespace CanvasTex