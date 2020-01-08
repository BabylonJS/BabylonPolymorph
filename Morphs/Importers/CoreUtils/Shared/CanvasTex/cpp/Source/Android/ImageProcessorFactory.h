/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <iostream>
#include "IImageProcessor.h"

namespace CanvasTex {

    typedef OutputFormat ImageFileType;

    class ImageProcessorFactory
    {
    public:
        static ImageFileType getImageType(const void* data);

        static std::unique_ptr<IImageProcessor> createImageProcessor(const void* data);

        static std::unique_ptr<IImageProcessor> createImageProcessor(ImageFileType type);
    };
}