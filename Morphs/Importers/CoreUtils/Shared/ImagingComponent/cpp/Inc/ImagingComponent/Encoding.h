/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <vector>

#include <Framework/TextureWriter.h>

#include <CanvasTex/CanvasTex.h>

namespace Spectre
{
namespace ImagingV1
{

enum class [[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]] TextureFormat
{
    BC3_UNORM = 0,
    BGRA32 = 1,
    BC5_UNORM = 2,
    BC7_UNORM = 3,
    PNG = 4,
    MEMFILE_AUTO = 5,   // Use with Resize & EncodeAs... methods to auto select appropriate memory file loader
    PNG256 = 6,
    JPEG = 7
};

}  // namespace ImagingV1
}  // namespace Spectre

namespace Spectre
{
namespace ImagingV1
{
namespace ImagingComponent
{

// Temporarily supress the deprecation warning so we can used a deprecated enum to declare a deprecated API
#pragma warning(push)
#pragma warning(disable: 4996)

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
std::vector<uint8_t> EncodeAsPNG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat format,
    bool save = false,
    const std::wstring& fileName = L""
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
std::vector<uint8_t> EncodeAsJPG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat format,
    bool save = false,
    const std::wstring& fileName = L""
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
std::vector<uint8_t> EncodeAsRAW(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat srcFormat,
    TextureFormat dstFormat,
    uint32_t* heightOut = nullptr,
    uint32_t* widthOut = nullptr,
    uint32_t* strideOut = nullptr,
    bool useGPU = true
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
std::vector<uint8_t> Resize(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat format,
    uint32_t newHeight,
    uint32_t newWidth
);

#pragma warning(pop)

} // namespace ImagingComponent
} // namespace ImagingV1
} // namespace Spectre

//---------------------------------------------------------------------------------------------------------------------

namespace Spectre
{
namespace ImagingV2
{
namespace ImagingComponent
{

std::vector<uint8_t> EncodeAsPNG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save = false,
    const std::wstring& fileName = L""
);

std::vector<uint8_t> EncodeAsDDS(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat srcFormat,
    Framework::TextureSegment::EFormat dstFormat
);

std::vector<uint8_t> EncodeAsPNG256(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save = false,
    const std::wstring& fileName = L""
);

std::vector<uint8_t> EncodeAsJPG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save = false,
    const std::wstring& fileName = L""
);

bool HasAlphaChannel(
    void* data,
    const uint32_t size,
    const Framework::TextureSegment::EFormat srcFormat
);

std::vector<uint8_t> EncodeToMemory(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat srcFormat,
    Framework::TextureSegment::EFormat dstFormat,
    uint32_t* heightOut = nullptr,
    uint32_t* widthOut = nullptr,
    uint32_t* strideOut = nullptr,
    bool useGPU = true
);

std::vector<uint8_t> Resize(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    uint32_t newHeight,
    uint32_t newWidth
);

} // namespace ImaginineComponent
} // namespace ImagingV2
} // namespace Spectre
