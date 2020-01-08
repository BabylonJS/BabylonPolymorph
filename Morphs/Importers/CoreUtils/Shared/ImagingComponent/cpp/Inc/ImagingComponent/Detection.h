/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>

#include <Framework/TextureWriter.h>

namespace Spectre
{
namespace ImagingV1
{
namespace ImagingComponent
{

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
Framework::ImageReader DetectImageReaderFromHeader(
    uint8_t* data,
    uint32_t sizeInBytes
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
bool TryGetImageWidthHeight(
    void* data,
    uint32_t size,
    uint32_t& width,
    uint32_t& height
);

} // namespace ImaginineComponent
} // namespace ImagingV1
} // namespace Spectre

//---------------------------------------------------------------------------------------------------------------------

namespace Spectre
{
namespace ImagingV2
{
namespace ImagingComponent
{

Framework::ImageReader DetectImageReader(
    uint8_t* data,
    uint32_t sizeInBytes
);

bool TryGetImageWidthHeight(
    void* data,
    uint32_t size,
    uint32_t& width,
    uint32_t& height
);

} // namespace ImaginineComponent
} // namespace ImagingV2
} // namespace Spectre
