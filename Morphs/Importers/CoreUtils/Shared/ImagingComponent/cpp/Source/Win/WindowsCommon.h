/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <wincodec.h>

namespace Spectre
{
namespace ImagingV2
{
namespace ImagingComponent
{
namespace Internal
{

HRESULT GetImagingFactory(IWICImagingFactory** factory);

}  // namespace Internal
}  // namespace ImagingComponent
}  // namespace Imaging
}  // namespace Spectre
