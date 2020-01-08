/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <CanvasTex/Image.h>
#include <DirectXTex.h>

namespace CanvasTex
{
    class ImageBase::ImageImplementation : public ::DirectX::Image
    {
    };
}  // namespace CanvasTex
