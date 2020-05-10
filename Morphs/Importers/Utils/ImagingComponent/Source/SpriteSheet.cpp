/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include <ImagingComponent/ImagingComponent.h>

namespace Babylon
{
namespace ImagingV2
{
namespace ImagingComponent
{
namespace
{

//---------------------------------------------------------------------------------------------------------------------

struct SpriteSheetFromFramesResult
{
    std::vector<uint8_t> pixels;
    uint32_t imageSize;
    uint32_t imageHeight;
    uint32_t frameSize;
};

//---------------------------------------------------------------------------------------------------------------------

// Move the individual frame data arrays into one buffer creating a vertical spritesheet to be encoded.
SpriteSheetFromFramesResult CreateSpriteSheetFromFrames(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth)
{
    static const uint32_t sizeOfRGBA = 4;

    SpriteSheetFromFramesResult result;

    uint32_t frameCount = (uint32_t)allFramesData.size();
    result.imageHeight = frameHeight * frameCount;
    result.frameSize= frameHeight * frameWidth * sizeOfRGBA * sizeof(uint8_t);
    result.imageSize = result.frameSize * frameCount;
    result.pixels.resize(result.imageSize);

    for (uint32_t i = 0; i < frameCount; ++i)
    {
        memcpy(&result.pixels[i * result.frameSize], allFramesData[i], result.frameSize);
    }

    return result;
}

}  // namespace <anonymous>

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> CreateSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth)
{
    auto spriteSheet = CreateSpriteSheetFromFrames(allFramesData, frameHeight, frameWidth);

    return EncodeAsPNG(
        spriteSheet.pixels.data(),
        spriteSheet.imageSize,
        spriteSheet.imageHeight,
        frameWidth,
        frameWidth * 4,
        Framework::TextureSegment::EFormat::kFormatBGRA32);
}

//---------------------------------------------------------------------------------------------------------------------

void SaveAsSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth,
    const std::wstring& fileName)
{
    auto spriteSheet = CreateSpriteSheetFromFrames(allFramesData, frameHeight, frameWidth);

    EncodeAsPNG(
        spriteSheet.pixels.data(),
        spriteSheet.imageSize,
        spriteSheet.imageHeight,
        frameWidth,
        frameWidth * 4,
        Framework::TextureSegment::EFormat::kFormatBGRA32,
        true,
        fileName);
}

}  // namespace ImagingComponent
}  // namespace ImagingV2
}  // namespace Babylon

//---------------------------------------------------------------------------------------------------------------------

namespace Babylon
{
namespace ImagingV1
{
namespace ImagingComponent
{

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> CreateSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth)
{
    return ImagingV2::ImagingComponent::CreateSpriteSheet(allFramesData, frameHeight, frameWidth);
}

//---------------------------------------------------------------------------------------------------------------------

void SaveAsSpriteSheet(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameHeight,
    uint32_t frameWidth,
    const std::wstring& fileName)
{
    ImagingV2::ImagingComponent::SaveAsSpriteSheet(allFramesData, frameHeight, frameWidth, fileName);
}

}  // namespace ImagingComponent
}  // namespace ImagingV1
}  // namespace Babylon
