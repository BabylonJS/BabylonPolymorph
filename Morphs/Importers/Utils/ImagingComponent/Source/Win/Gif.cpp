/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include <ImagingComponent/Gif.h>

#include <wrl/client.h>
#include <wincodec.h>

#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/Assert.h>

#include "WindowsCommon.h"


using namespace Babylon::Utils;
using namespace Microsoft::WRL;

//---------------------------------------------------------------------------------------------------------------------

namespace Babylon
{
namespace ImagingV2
{
namespace ImagingComponent
{

//---------------------------------------------------------------------------------------------------------------------

void AppendGifFrame(
    ComPtr<IWICBitmapEncoder> const& encoder,
    ComPtr<IWICImagingFactory> const& factory,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride,
    uint8_t* frame)
{
    const WICPixelFormatGUID pixelFormat = GUID_WICPixelFormat32bppBGRA;

    ComPtr<IWICBitmap> frameBitmap;
    ThrowIfFailed(
        factory->CreateBitmapFromMemory(
            frameWidth,
            frameHeight,
            pixelFormat,
            frameStride,
            frameBufferSize,
            frame,
            &frameBitmap));

    ComPtr<IWICBitmapFrameEncode> frameEncode = nullptr;
    ThrowIfFailed(encoder->CreateNewFrame(&frameEncode, nullptr));
    ThrowIfFailed(frameEncode->Initialize(nullptr));
    ThrowIfFailed(frameEncode->SetSize(frameWidth, frameHeight));
    ThrowIfFailed(frameEncode->WriteSource(frameBitmap.Get(), nullptr));
    ThrowIfFailed(frameEncode->Commit());
}

//---------------------------------------------------------------------------------------------------------------------

void AppendGifFrame(
    ComPtr<IWICBitmapEncoder> const& encoder,
    ComPtr<IWICImagingFactory> const& factory,
    ComPtr<IWICBitmapFrameDecode> const& frameDecode)
{
    BabylonUnusedParameter(factory);
    ComPtr<IWICBitmapFrameEncode> frameEncode = nullptr;
    ThrowIfFailed(encoder->CreateNewFrame(&frameEncode, nullptr));
    ThrowIfFailed(frameEncode->Initialize(nullptr));

    uint32_t width;
    uint32_t height;
    ThrowIfFailed(frameDecode->GetSize(&width, &height));
    ThrowIfFailed(frameEncode->SetSize(width, height));
    ThrowIfFailed(frameEncode->WriteSource(frameDecode.Get(), nullptr));
    ThrowIfFailed(frameEncode->Commit());
}

//---------------------------------------------------------------------------------------------------------------------

void WriteGifOnStream(
    ComPtr<IWICStream> const& outpurStream,
    ComPtr<IWICImagingFactory> const& factory,
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride)
{
    ComPtr<IWICBitmapEncoder> encoder = nullptr;
    ThrowIfFailed(factory->CreateEncoder(GUID_ContainerFormatGif, nullptr, &encoder));
    ThrowIfFailed(encoder->Initialize(outpurStream.Get(), WICBitmapEncoderNoCache));

    // Append all frames.
    for each(auto frame in allFramesData)
    {
        AppendGifFrame(encoder, factory, frameBufferSize, frameHeight, frameWidth, frameStride, frame);
    }

    // Write the image.
    ThrowIfFailed(encoder->Commit());
}

//---------------------------------------------------------------------------------------------------------------------

ComPtr<IStream> CreateGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride)
{
    ComPtr<IWICImagingFactory> factory;
    ThrowIfFailed(Internal::GetImagingFactory(&factory));

    ComPtr<IStream> memoryStream = nullptr;
    ThrowIfFailed(CreateStreamOnHGlobal(nullptr, true, &memoryStream));
    IWICStream* memoryGifStream = nullptr;
    ThrowIfFailed(factory->CreateStream(&memoryGifStream));
    ThrowIfFailed(memoryGifStream->InitializeFromIStream(memoryStream.Get()));

    WriteGifOnStream(
        memoryGifStream,
        factory.Get(),
        allFramesData,
        frameBufferSize,
        frameHeight,
        frameWidth,
        frameStride);

    return memoryStream;
}

//---------------------------------------------------------------------------------------------------------------------

void SaveAsGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride,
    const std::wstring& fileName)
{
    ComPtr<IWICImagingFactory> factory;
    ThrowIfFailed(Internal::GetImagingFactory(&factory));

    ComPtr<IWICStream> fileStream;
    ThrowIfFailed(factory->CreateStream(&fileStream));
    ThrowIfFailed(fileStream->InitializeFromFilename(fileName.c_str(), GENERIC_WRITE));

    WriteGifOnStream(
        fileStream.Get(),
        factory.Get(),
        allFramesData,
        frameBufferSize,
        frameHeight,
        frameWidth,
        frameStride);
}

//---------------------------------------------------------------------------------------------------------------------

void SaveAsGif(
    ComPtr<IStream> const& imageStream,
    const std::wstring& fileName)
{
    ComPtr<IWICImagingFactory> factory;
    ThrowIfFailed(Internal::GetImagingFactory(&factory));

    ComPtr<IWICBitmapDecoder> decoder;

    ThrowIfFailed(
        factory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &decoder));

    uint32_t frameCount;
    ThrowIfFailed(decoder->GetFrameCount(&frameCount));

    ComPtr<IWICStream> gifStream;
    ThrowIfFailed(factory->CreateStream(&gifStream));
    ThrowIfFailed(gifStream->InitializeFromFilename(fileName.c_str(), GENERIC_WRITE));

    ComPtr<IWICBitmapEncoder> encoder = nullptr;
    ThrowIfFailed(factory->CreateEncoder(GUID_ContainerFormatGif, nullptr, &encoder));
    ThrowIfFailed(encoder->Initialize(gifStream.Get(), WICBitmapEncoderNoCache));

    for (uint32_t i = 0; i < frameCount; ++i)
    {
        ComPtr<IWICBitmapFrameDecode> frameDecode;
        ThrowIfFailed(decoder->GetFrame(i, &frameDecode));

        AppendGifFrame(encoder, factory, frameDecode.Get());
    }

    ThrowIfFailed(encoder->Commit());
    CoUninitialize();
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

Microsoft::WRL::ComPtr<IStream> CreateGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride)
{
    return ImagingV2::ImagingComponent::CreateGif(allFramesData, frameBufferSize, frameHeight, frameWidth, frameStride);
}

//---------------------------------------------------------------------------------------------------------------------

void SaveAsGif(
    std::vector<uint8_t*> const& allFramesData,
    uint32_t frameBufferSize,
    uint32_t frameHeight,
    uint32_t frameWidth,
    uint32_t frameStride,
    const std::wstring& fileName)
{
    ImagingV2::ImagingComponent::SaveAsGif(allFramesData, frameBufferSize, frameHeight, frameWidth, frameStride, fileName);
}

//---------------------------------------------------------------------------------------------------------------------

void SaveAsGif(
    Microsoft::WRL::ComPtr<IStream> const& imageStream,
    const std::wstring& fileName)
{
    ImagingV2::ImagingComponent::SaveAsGif(imageStream, fileName);
}

}  // namespace ImagingComponent
}  // namespace ImagingV1
}  // namespace Babylon
