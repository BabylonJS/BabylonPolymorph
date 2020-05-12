/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>

#include <CanvasTex/CanvasTex.h>

namespace Babylon
{
namespace ImagingV2
{
namespace ImagingComponent
{
namespace Internal
{

void ReadFromMemoryFile(
    void* data,
    uint32_t size,
    CanvasTex::Image& img,
    CanvasTex::ScratchImage& result
);

}  // namespace Internal
}  // namespace ImagingComponent
}  // namespace ImagingV2
}  // namespace Babylon
