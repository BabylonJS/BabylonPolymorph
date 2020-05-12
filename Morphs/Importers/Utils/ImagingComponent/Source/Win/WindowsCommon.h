/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <wincodec.h>

namespace Babylon
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
}  // namespace Babylon
