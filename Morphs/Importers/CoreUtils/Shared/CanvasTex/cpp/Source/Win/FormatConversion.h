/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <CanvasTex/Format.h>

#include <dxgi.h>

namespace CanvasTex
{
namespace Internal
{

DXGI_FORMAT TextureFormatToDxgiFormat(TextureFormat format);

TextureFormat DxgiFormatToTextureFormat(DXGI_FORMAT format);

}  // namespace Internal
}  // namespace CanvasTex
