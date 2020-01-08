/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <vector>

namespace Spectre
{
namespace ImagingV1
{
namespace ImagingComponent
{

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
std::vector<uint8_t> CreateSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
void SaveAsSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth,
    const std::wstring& fileName
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

std::vector<uint8_t> CreateSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth
);

void SaveAsSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth,
    const std::wstring& fileName
);

} // namespace ImaginineComponent
} // namespace ImagingV2
} // namespace Spectre
