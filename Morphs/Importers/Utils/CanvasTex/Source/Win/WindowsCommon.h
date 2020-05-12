/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <wincodec.h>

namespace CanvasTex
{
namespace Internal
{
    HRESULT GetImagingFactory(IWICImagingFactory** factory);
}  // namespace Internal
}  // namespace CanvasTex
