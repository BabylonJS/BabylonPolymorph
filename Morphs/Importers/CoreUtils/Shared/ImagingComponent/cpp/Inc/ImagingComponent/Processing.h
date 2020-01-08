/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <Framework/TextureWriter.h>
#include <CanvasTex/Image.h>

namespace Spectre
{
namespace ImagingV1
{
namespace ImagingComponent
{

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
void EncodeBGRA(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    Framework::ImageReader reader,
    void* data,
    uint32_t sizeInBytes,
    Framework::ITextureWriter* writer,
    int textureCompression,
    uint32_t lod
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
void ProcessRAWLODs(
    uint32_t textureId,
    uint32_t width,
    uint32_t height,
    uint32_t lineStride,
    Framework::TextureSegment::EFormat format,
    uint8_t flags,
    void* data,
    uint32_t sizeInBytes,
    std::vector<Framework::ITextureWriter*>& writers,
    const Framework::TextureProcessingOptions& options
);

[[deprecated("The ImagingV1 API is deprecated. Please switch to V2.")]]
void ProcessLODs(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    void* data,
    uint32_t sizeInBytes,
    std::vector<Framework::ITextureWriter*>& writers,
    const Framework::TextureProcessingOptions& options
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

const uint32_t kDefaultTextureSize = 96;

const uint8_t* GetDefaultTexture();

void EncodeBGRA(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    Framework::ImageReader reader,
    void* data,
    uint32_t sizeInBytes,
    Framework::ITextureWriter* writer,
    int textureCompression,
    uint32_t lod
);

void EncodeBGRAForAllLODsFromMemory(
    uint32_t textureId,
    uint32_t width,
    uint32_t height,
    uint32_t lineStride,
    Framework::TextureSegment::EFormat format,
    uint8_t flags,
    void* data,
    uint32_t sizeInBytes,
    std::vector<Framework::ITextureWriter*>& writers,
    const Framework::TextureProcessingOptions& options
);

void EncodeBGRAForAllLODs(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    void* data,
    uint32_t sizeInBytes,
    std::vector<Framework::ITextureWriter*>& writers,
    const Framework::TextureProcessingOptions& options
);

// Enum for parsing alpha channel of an image to determine what kind of alpha values it contains
// Typically used to determine appropriate rendering mode for a material
enum class AlphaChannelType
{
    GrayscaleVariance,      // Contains some non-black (0) and non-white (255) values (e.g. 65, 170, etc)
    Binary,                 // Contains only black and white values, i.e. pixel is either transparent or opaque (Mask)
    Transparent,            // Contains only black (0) values, i.e. texture is completely transparent
    Opaque,                 // Contains only white (255) values, i.e. texture is completely opaque
    Unknown                 // Typically used if alpha channel couldn't be processed for some reason
};

AlphaChannelType DetectImageAlphaChannelType(
    const uint8_t* imageData,  /*Pixel array after BGRA conversion*/
    const size_t imageWidth,
    const size_t imageHeight,
    const CanvasTex::TextureFormat imageFormat
);

void ProcessAlphaFlagsForBGRAImage(
    void* imageData, /* Data must include header to enable determination of filetype: PNG or TGA. i.e. Texture file data before BGRA conversion*/
    size_t imageDataSize,
    void* imagePixels, /*Pixel array after BGRA conversion*/
    uint32_t imageWidth,
    uint32_t imageHeight,
    uint32_t imageRowPitch,
    uint8_t& imageAlphaFlags
);

bool ConvertGrayscaleNormalMap(CanvasTex::Image& img, float scale = 1.0f);

void ProcessAlphaFlagsUsingAlphaChannelType(
    void* imageData, /* Data must include header to enable determination of filetype: PNG or TGA. i.e. Texture file data before BGRA conversion*/
    size_t imageDataSize,
    uint8_t& imageAlphaFlags,
    ImagingV2::ImagingComponent::AlphaChannelType alphaType
);

bool RewriteAlphaChannel(
    uint8_t* imageData,
    const size_t imageWidth,
    const size_t imageHeight,
    const CanvasTex::TextureFormat imageFormat,
    const AlphaChannelType expectedAlphaType,
    const float alphaCutOff
);

} // namespace ImaginineComponent
} // namespace ImagingV2
} // namespace Spectre
