/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include <ImagingComponent/Encoding.h>

#include <CoreUtils/Memory.h>

#include <CanvasTex/CanvasTex.h>

#include "Common.h"

//-----------------------------------------------------------------------------

namespace Spectre
{
namespace ImagingV2
{
namespace ImagingComponent
{
namespace
{

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAs(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save,
    const std::wstring& fileName,
    CanvasTex::OutputFormat outputFormat)
{
    CanvasTex::Image img;
    CanvasTex::ScratchImage result;

    if (format == Framework::TextureSegment::EFormat::kPNG ||
        format == Framework::TextureSegment::EFormat::kUnknown)
    {
        // it's a memory file
        Internal::ReadFromMemoryFile(data, size, img, result);
    }
    else
    {
        // it's raw data
        img.SetWidth(width);
        img.SetHeight(height);
        img.SetRowPitch(stride);
        img.SetSlicePitch(size);
        img.SetPixels(static_cast<uint8_t*>(data));

        switch (format)
        {
        case Framework::TextureSegment::EFormat::kBC3_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc3Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC5_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc5Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC7_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc7Unorm);
            break;
        case Framework::TextureSegment::EFormat::kFormatBGRA32:
            img.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
            break;
        default:
            throw Spectre::Utils::SpectreException("Unknown format");
        }
    }

    if (!save)
    {
        auto outEncoding = CanvasTex::TextureFormat::B8g8r8a8Unorm;

        if (outputFormat == CanvasTex::OutputFormat::DDS)
        {
            switch (format)
            {
            case Framework::TextureSegment::EFormat::kBC3_UNORM:
                outEncoding = CanvasTex::TextureFormat::Bc3Unorm;
                break;
            case Framework::TextureSegment::EFormat::kBC5_UNORM:
                outEncoding = CanvasTex::TextureFormat::Bc5Unorm;
                break;
            case Framework::TextureSegment::EFormat::kBC7_UNORM:
                outEncoding = CanvasTex::TextureFormat::Bc7Unorm;
                break;
            case Framework::TextureSegment::EFormat::kFormatBGRA32:
                outEncoding = CanvasTex::TextureFormat::B8g8r8a8Unorm;
                break;
            default:
                throw Spectre::Utils::SpectreException("Unknown format");
            }
        }

        std::vector<uint8_t> bytes;
        CanvasTex::SaveToMemory(img, outEncoding, outputFormat, [&bytes](size_t size, void* ptr)
        {
            bytes.resize(size);
            memcpy(bytes.data(), ptr, size);
        });

        return bytes;
    }
    else
    {
        CanvasTex::SaveToFile(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, outputFormat, fileName);
        return std::vector<uint8_t>();
    }
}

using CanvasTex::TextureFormat;

bool TextureFormatHasAlpha(TextureFormat format)
{
    if (format == TextureFormat::R32g32b32Typeless
        || format == TextureFormat::R32g32b32Float
        || format == TextureFormat::R32g32b32Uint
        || format == TextureFormat::R32g32b32Sint
        || format == TextureFormat::R32g32Typeless
        || format == TextureFormat::R32g32Float
        || format == TextureFormat::R32g32Uint
        || format == TextureFormat::R32g32Sint
        || format == TextureFormat::R32g8x24Typeless
        || format == TextureFormat::D32FloatS8x24Uint
        || format == TextureFormat::R32FloatX8x24Typeless
        || format == TextureFormat::X32TypelessG8x24Uint
        || format == TextureFormat::R11g11b10Float
        || format == TextureFormat::R16g16Typeless
        || format == TextureFormat::R16g16Float
        || format == TextureFormat::R16g16Unorm
        || format == TextureFormat::R16g16Uint
        || format == TextureFormat::R16g16Snorm
        || format == TextureFormat::R16g16Sint
        || format == TextureFormat::R32Typeless
        || format == TextureFormat::D32Float
        || format == TextureFormat::R32Float
        || format == TextureFormat::R32Uint
        || format == TextureFormat::R32Sint
        || format == TextureFormat::R24g8Typeless
        || format == TextureFormat::D24UnormS8Uint
        || format == TextureFormat::R24UnormX8Typeless
        || format == TextureFormat::X24TypelessG8Uint
        || format == TextureFormat::R8g8Typeless
        || format == TextureFormat::R8g8Unorm
        || format == TextureFormat::R8g8Uint
        || format == TextureFormat::R8g8Snorm
        || format == TextureFormat::R8g8Sint
        || format == TextureFormat::R16Typeless
        || format == TextureFormat::R16Float
        || format == TextureFormat::D16Unorm
        || format == TextureFormat::R16Unorm
        || format == TextureFormat::R16Uint
        || format == TextureFormat::R16Snorm
        || format == TextureFormat::R16Sint
        || format == TextureFormat::R8Typeless
        || format == TextureFormat::R8Unorm
        || format == TextureFormat::R8Uint
        || format == TextureFormat::R8Snorm
        || format == TextureFormat::R8Sint
        || format == TextureFormat::R1Unorm
        || format == TextureFormat::R9g9b9e5Sharedexp
        || format == TextureFormat::R8g8B8g8Unorm
        || format == TextureFormat::G8r8G8b8Unorm
        || format == TextureFormat::B5g6r5Unorm
        || format == TextureFormat::B8g8r8x8Unorm
        || format == TextureFormat::B8g8r8x8Typeless
        || format == TextureFormat::B8g8r8x8UnormSrgb)
    {
        // These formats do not have alpha channels
        return false;
    }

    // Remaining formats either have alpha, or we are unsure, so return true to be safe
    return true;
}

}  // namespace <anonymous>

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> Resize(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    uint32_t newHeight,
    uint32_t newWidth)
{
    CanvasTex::Image img;
    CanvasTex::ScratchImage result;

    if (format == Framework::TextureSegment::EFormat::kPNG ||
        format == Framework::TextureSegment::EFormat::kUnknown)
    {
        // it's a memory file
        CanvasTex::ScratchImage imgScratch;
        Internal::ReadFromMemoryFile(data, size, img, imgScratch);
        if (CanvasTex::IsCompressed(img.GetFormat()))
        {
            CanvasTex::Decompress(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, result);
            img = result.GetImage(0, 0);
        }
        else if (img.GetFormat() != CanvasTex::TextureFormat::B8g8r8a8Unorm)
        {
            CanvasTex::Convert(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, result);
            img = result.GetImage(0, 0);
        }
        else
        {
            result = std::move(imgScratch);
        }
    }
    else
    {
        // it's raw data
        img.SetWidth(width);
        img.SetHeight(height);
        img.SetRowPitch(stride);
        img.SetFormat(CanvasTex::TextureFormat::Bc3Unorm);
        img.SetSlicePitch(size);
        img.SetPixels(static_cast<uint8_t*>(data));

        switch (format)
        {
        case Framework::TextureSegment::EFormat::kBC3_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc3Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC5_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc5Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC7_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc7Unorm);
            break;
        case Framework::TextureSegment::EFormat::kFormatBGRA32:
            img.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
            break;
        default:
            throw Spectre::Utils::SpectreException("Unknown format");
        }

        if (CanvasTex::IsCompressed(img.GetFormat()))
        {
            CanvasTex::Decompress(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, result);
            img = result.GetImage(0, 0);
        }
        // N.B. Pretty sure this code will never be reached!
        // Convert to our format BGRA 32 Bpp if needed.
        else if (img.GetFormat() != CanvasTex::TextureFormat::B8g8r8a8Unorm)
        {
            CanvasTex::Convert(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, result);
            img = result.GetImage(0, 0);
        }
    }

    CanvasTex::ScratchImage resizeResult;
    CanvasTex::Resize(img, newWidth, newHeight, resizeResult);

    std::vector<uint8_t> bytes(resizeResult.GetPixelsSize());
    memcpy_s(bytes.data(), bytes.size(), resizeResult.GetPixels(), resizeResult.GetPixelsSize());

    return bytes;
}

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAsDDS(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat srcFormat,
    Framework::TextureSegment::EFormat dstFormat)
{
    auto dataBGRA = EncodeToMemory(
        data,
        size,
        height,
        width,
        stride,
        srcFormat,
        Spectre::Framework::TextureSegment::EFormat::kFormatBGRA32);

    CanvasTex::Image img;
    img.SetWidth(width);
    img.SetHeight(height);
    img.SetRowPitch(width * 4);
    img.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
    img.SetSlicePitch(dataBGRA.size());
    img.SetPixels(static_cast<uint8_t*>(dataBGRA.data()));

    CanvasTex::TextureFormat compressionFormat = CanvasTex::TextureFormat::Unknown;
    switch (dstFormat)
    {
    case Framework::TextureSegment::EFormat::kBC3_UNORM:
        compressionFormat = CanvasTex::TextureFormat::Bc3Unorm;
        break;
    case Framework::TextureSegment::EFormat::kBC5_UNORM:
        compressionFormat = CanvasTex::TextureFormat::Bc5Unorm;
        break;
    case Framework::TextureSegment::EFormat::kBC7_UNORM:
        compressionFormat = CanvasTex::TextureFormat::Bc7Unorm;
        break;
    default:
        throw Spectre::Utils::SpectreException("Unsupported format for DDS");
    }

    CanvasTex::ScratchImage mipChainSI;
    CanvasTex::GenerateMipMaps(img, mipChainSI, CanvasTex::FilterOptions::SeparateAlpha);

    CanvasTex::ScratchImage mipChainCompressed;
    CanvasTex::Compress(mipChainSI, compressionFormat, mipChainCompressed);

    std::vector<uint8_t> bytes;
    CanvasTex::SaveToMemory(mipChainCompressed, compressionFormat, CanvasTex::OutputFormat::DDS, [&bytes](size_t size, void* ptr)
    {
        bytes.assign(
            static_cast<uint8_t*>(ptr),
            static_cast<uint8_t*>(ptr) + size);
    });

    return bytes;
}

std::vector<uint8_t> EncodeAsPNG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save,
    const std::wstring& fileName)
{
    return EncodeAs(
        data,
        size,
        height,
        width,
        stride,
        format,
        save,
        fileName,
        CanvasTex::OutputFormat::Png
    );
}

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAsPNG256(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save,
    const std::wstring& fileName)
{
    SpectreUnusedParameter(save);
    SpectreUnusedParameter(fileName);
    CanvasTex::Image img;
    CanvasTex::ScratchImage result;

    if (format == Framework::TextureSegment::EFormat::kPNG || format == Framework::TextureSegment::EFormat::kUnknown)
    {
        // it's a memory file
        Internal::ReadFromMemoryFile(data, size, img, result);
    }
    else
    {
        // it's raw data
        img.SetWidth(width);
        img.SetHeight(height);
        img.SetRowPitch(stride);
        img.SetSlicePitch(size);
        img.SetPixels(static_cast<uint8_t*>(data));

        switch (format)
        {
        case Framework::TextureSegment::EFormat::kBC3_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc3Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC5_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc5Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC7_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc7Unorm);
            break;
        case Framework::TextureSegment::EFormat::kFormatBGRA32:
            img.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
            break;
        default:
            throw Spectre::Utils::SpectreException("Unknown format");
        }
    }

    std::vector<uint8_t> bytes;

    CanvasTex::SaveToMemory(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, CanvasTex::OutputFormat::Png256, [&bytes](size_t size, void* ptr)
    {
        bytes.assign(
            static_cast<uint8_t*>(ptr),
            static_cast<uint8_t*>(ptr) + size);
    });

    return bytes;
}

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAsJPG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat format,
    bool save,
    const std::wstring& fileName)
{
    return EncodeAs(
        data,
        size,
        height,
        width,
        stride,
        format,
        save,
        fileName,
        CanvasTex::OutputFormat::Jpeg
    );
}

//---------------------------------------------------------------------------------------------------------------------

bool HasAlphaChannel(void* data, const uint32_t size, const Framework::TextureSegment::EFormat srcFormat)
{
    CanvasTex::Image img;
    if (srcFormat == Framework::TextureSegment::EFormat::kPNG ||
        srcFormat == Framework::TextureSegment::EFormat::kPNG256 ||
        srcFormat == Framework::TextureSegment::EFormat::kUnknown)
    {
        // It's a memory file
        CanvasTex::ScratchImage imgScratch;
        Internal::ReadFromMemoryFile(data, size, img, imgScratch);
        return TextureFormatHasAlpha(img.GetFormat());
    }

    // Otherwise it's raw data
    switch (srcFormat)
    {
    case Framework::TextureSegment::EFormat::kBC3_UNORM:
        return TextureFormatHasAlpha(TextureFormat::Bc3Unorm);
    case Framework::TextureSegment::EFormat::kBC5_UNORM:
        return TextureFormatHasAlpha(TextureFormat::Bc5Unorm);
    case Framework::TextureSegment::EFormat::kBC7_UNORM:
        return TextureFormatHasAlpha(TextureFormat::Bc7Unorm);
    case Framework::TextureSegment::EFormat::kFormatBGRA32:
        return TextureFormatHasAlpha(TextureFormat::B8g8r8a8Unorm);
    case Framework::TextureSegment::EFormat::kJPEG:
        return false;
    default:
        // Unknown format
        return true;
    }

    return true;
}

std::vector<uint8_t> EncodeToMemory(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    Framework::TextureSegment::EFormat srcFormat,
    Framework::TextureSegment::EFormat dstFormat,
    uint32_t* heightOut,
    uint32_t* widthOut,
    uint32_t* strideOut,
    bool useGPU)
{
    SpectreAssert(dstFormat != Framework::TextureSegment::EFormat::kPNG &&
                  dstFormat != Framework::TextureSegment::EFormat::kUnknown);

    CanvasTex::Image img;
    CanvasTex::ScratchImage result;

    if (srcFormat == Framework::TextureSegment::EFormat::kPNG ||
        srcFormat == Framework::TextureSegment::EFormat::kUnknown)
    {
        // it's a memory file
        CanvasTex::ScratchImage imgScratch;
        Internal::ReadFromMemoryFile(data, size, img, imgScratch);

        if (CanvasTex::IsCompressed(img.GetFormat()))
        {
            CanvasTex::Decompress(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, result);
        }
        else
        {
            result = std::move(imgScratch);
        }
    }
    else
    {
        img.SetWidth(width);
        img.SetHeight(height);
        img.SetRowPitch(stride);
        img.SetFormat(CanvasTex::TextureFormat::Bc3Unorm);
        img.SetSlicePitch(size);
        img.SetPixels(static_cast<uint8_t*>(data));

        switch (srcFormat)
        {
        case Framework::TextureSegment::EFormat::kBC3_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc3Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC5_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc5Unorm);
            break;
        case Framework::TextureSegment::EFormat::kBC7_UNORM:
            img.SetFormat(CanvasTex::TextureFormat::Bc7Unorm);
            break;
        case Framework::TextureSegment::EFormat::kFormatBGRA32:
            img.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
            break;
        default:
            throw Spectre::Utils::SpectreException("Unknown format");
        }

        if (CanvasTex::IsCompressed(img.GetFormat()) == true)
        {
            CanvasTex::Decompress(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, result);
        }
        else
        {
            // already in "BGRA" Format
            result.InitializeFromImage(img);
        }
    }

    if (widthOut)
    {
        *widthOut = (uint32_t)img.GetWidth();
    }

    if (heightOut)
    {
        *heightOut = (uint32_t)img.GetHeight();
    }

    CanvasTex::TextureFormat compressionFormat = CanvasTex::TextureFormat::Bc3Unorm;
    switch (dstFormat)
    {
    case Framework::TextureSegment::EFormat::kBC3_UNORM:
    {
        compressionFormat = CanvasTex::TextureFormat::Bc3Unorm;
        break;
    }
    case Framework::TextureSegment::EFormat::kBC5_UNORM:
    {
        compressionFormat = CanvasTex::TextureFormat::Bc5Unorm;
        break;
    }
    case Framework::TextureSegment::EFormat::kBC7_UNORM:
    {
        compressionFormat = CanvasTex::TextureFormat::Bc7Unorm;
        break;
    }
    case Framework::TextureSegment::EFormat::kFormatBGRA32:
        compressionFormat = CanvasTex::TextureFormat::B8g8r8a8Unorm;
        break;
    default:
        compressionFormat = CanvasTex::TextureFormat::Unknown;
    }

    std::vector<uint8_t> bytes;

    CanvasTex::Image const& sourceImage = result.GetImage(0, 0);
    if (sourceImage.GetFormat() == compressionFormat)
    {
        // already decompressed
        bytes.resize(result.GetPixelsSize());
        memcpy_s(bytes.data(), bytes.size(), result.GetPixels(), result.GetPixelsSize());

        if (strideOut)
        {
            *strideOut = (uint32_t)sourceImage.GetRowPitch();
        }
    }
    else
    {
        CanvasTex::ScratchImage resultImage;
        if (CanvasTex::IsCompressed(compressionFormat) == true)
        {
            CanvasTex::Compress(sourceImage, compressionFormat, CanvasTex::CompressionOptions::None, useGPU, resultImage);
        }
        else
        {
            CanvasTex::Convert(sourceImage, compressionFormat, resultImage);
        }

        bytes.resize(resultImage.GetPixelsSize());
        memcpy_s(bytes.data(), bytes.size(), resultImage.GetPixels(), resultImage.GetPixelsSize());

        if (strideOut)
        {
            *strideOut = (uint32_t)resultImage.GetImage(0, 0).GetRowPitch();
        }
    }

    return bytes;
}

}  // namespace ImagingComponent
}  // namespace ImagingV2
}  // namespace Spectre

//---------------------------------------------------------------------------------------------------------------------

namespace Spectre
{
namespace ImagingV1
{
namespace ImagingComponent
{
namespace
{

// Temporarily supress the deprecation warning so we can used a deprecated enum to define a deprecated API
#pragma warning(push)
#pragma warning(disable: 4996)

//---------------------------------------------------------------------------------------------------------------------

[[deprecated]]
Framework::TextureSegment::EFormat ToTextureSegmentFormat(TextureFormat format)
{
    switch (format)
            {
    case TextureFormat::BC3_UNORM:
        return Framework::TextureSegment::EFormat::kBC3_UNORM;
    case TextureFormat::BGRA32:
        return Framework::TextureSegment::EFormat::kFormatBGRA32;
    case TextureFormat::BC5_UNORM:
        return Framework::TextureSegment::EFormat::kBC5_UNORM;
    case TextureFormat::BC7_UNORM:
        return Framework::TextureSegment::EFormat::kBC7_UNORM;
    case TextureFormat::PNG:
        return Framework::TextureSegment::EFormat::kPNG;
    case TextureFormat::MEMFILE_AUTO:
        return Framework::TextureSegment::EFormat::kUnknown;
    default:
        throw Utils::SpectreException("Cannot convert TextureFormat to TextureSegment::EFormat - unknown TextureFormat");
            }
        }

}  // namespace <anonymous>

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAsPNG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat format,
    bool save,
    const std::wstring& fileName)
{
    return ImagingV2::ImagingComponent::EncodeAsPNG(
        data,
        size,
        height,
        width,
        stride,
        ToTextureSegmentFormat(format),
        save,
        fileName);
}

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAsJPG(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat format,
    bool save,
    const std::wstring& fileName)
        {
    return ImagingV2::ImagingComponent::EncodeAsJPG(
        data,
        size,
        height,
        width,
        stride,
        ToTextureSegmentFormat(format),
        save,
        fileName);
        }

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> EncodeAsRAW(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat srcFormat,
    TextureFormat dstFormat,
    uint32_t* heightOut,
    uint32_t* widthOut,
    uint32_t* strideOut,
    bool useGPU)
{
    return ImagingV2::ImagingComponent::EncodeToMemory(
        data,
        size,
        height,
        width,
        stride,
        ToTextureSegmentFormat(srcFormat),
        ToTextureSegmentFormat(dstFormat),
        heightOut,
        widthOut,
        strideOut,
        useGPU);
    }

//---------------------------------------------------------------------------------------------------------------------

std::vector<uint8_t> Resize(
    void* data,
    uint32_t size,
    uint32_t height,
    uint32_t width,
    uint32_t stride,
    TextureFormat format,
    uint32_t newHeight,
    uint32_t newWidth)
{
    return ImagingV2::ImagingComponent::Resize(
        data,
        size,
        height,
        width,
        stride,
        ToTextureSegmentFormat(format),
        newHeight,
        newWidth);
}

#pragma warning(pop)

}  // namespace ImagingComponent
}  // namespace ImagingV1
}  // namespace Spectre
