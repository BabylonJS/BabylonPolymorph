/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include <wrl/client.h>

// This should ideally return std::vector<uint8_t>. To make that happen we need to
// implement IStream backed by a vector, use that as the destination for writing
// and then take over the ownership of the vector. This way no extra copies would be
// introduced and the API would become consistent with rest of the library. Also
// the API would become cross-platform.

namespace Spectre
{
namespace ImagingV1
{
namespace ImagingComponent
{

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
Microsoft::WRL::ComPtr<IStream> CreateGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
void SaveAsGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride,
    const std::wstring& fileName
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
void SaveAsGif(
    Microsoft::WRL::ComPtr<IStream> const& imageStream,
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

Microsoft::WRL::ComPtr<IStream> CreateGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride
);

void SaveAsGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride,
    const std::wstring& fileName
);

void SaveAsGif(
    Microsoft::WRL::ComPtr<IStream> const& imageStream,
    const std::wstring& fileName
);

} // namespace ImaginineComponent
} // namespace ImagingV2
} // namespace Spectre
