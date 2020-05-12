/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "Common.h"

#include <CanvasTex/CanvasTex.h>

#include <ImagingComponent/Detection.h>

//---------------------------------------------------------------------------------------------------------------------

namespace Babylon
{
namespace ImagingV2
{
namespace ImagingComponent
{
namespace Internal
{

//---------------------------------------------------------------------------------------------------------------------

void ReadFromMemoryFile(
    void* data,
    uint32_t size,
    CanvasTex::Image& img,
    CanvasTex::ScratchImage& result)
{
    Framework::ImageReader reader = DetectImageReader((uint8_t*)data, size);

    CanvasTex::TextureMetadata metadata;
    auto loadResult = LoadFromMemory(data, size, reader, &metadata, result);

    if (loadResult != CanvasTex::LoadResult::LoadSuccessful)
    {
        throw Babylon::Utils::BabylonException("Failed to load image from memory.");
    }

    img = result.GetImage(0, 0);
}

}  // namespace Internal
}  // namespace ImagingComponent
}  // namespace ImagingV2
}  // namespace Babylon
