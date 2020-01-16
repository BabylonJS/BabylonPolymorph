/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include <CanvasTex/CanvasTex.h>
#include "ScratchImage.h"
#include "TextureCompression.h"
#include "GliIncludes.h"

#include "../CanvasTexUtils.h"

#include <CoreUtils/StringUtils.h>
#include <gli/convert.hpp>


namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

bool IsCompressed(TextureFormat format)
{
    auto gliFormat = GetGliTextureFormat(format);
    if (gliFormat == gli::FORMAT_UNDEFINED)
    {
        throw Babylon::Utils::BabylonException(std::string("CanvasTex::IsCompressed - Invalid texture format ") + std::to_string(std::underlying_type_t<TextureFormat>(format)));
    }
    return gli::is_compressed(GetGliTextureFormat(format));
}

//---------------------------------------------------------------------------------------------------------------------

bool IsTgaFile(
    const void* pSource,
    size_t size)
{
    // TODO: Implement this
    // It is not implemented, but we don't want to throw an exception here or all non-TGA files will fail to load.
    // The Windows implementation of this function calls GetMetadataFromTGAMemory in the DirectXTex SDK in DirectXTexTGA.cpp
    // Perhaps we can get inspiration from this
    // https://github.com/Microsoft/DirectXTex/blob/8480f4fe5ae06924e8a58695fe9ee30a7b685b10/DirectXTex/DirectXTexTGA.cpp
    return false;
}

//---------------------------------------------------------------------------------------------------------------------

bool GetMetadataFromMemory(
    const void* pSource,
    size_t size,
    Babylon::Framework::ImageReader reader,
    TextureMetadata& metadata)
{
    switch (reader)
    {
        case Babylon::Framework::ImageReader::DDS:
        {
            gli::texture texture = loadImage(pSource, size);
            if (!texture.empty())
            {
                ScratchImage image;
                image.GetImplementation().SetImage(texture);
                metadata = image.GetMetadata();
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        case Babylon::Framework::ImageReader::TGA:
        case Babylon::Framework::ImageReader::WIC:
        case Babylon::Framework::ImageReader::PSD:
        case Babylon::Framework::ImageReader::UNKNOWN:
        default:
            return imageGetMetadata(pSource, size, metadata);
            break;
    }

}

//---------------------------------------------------------------------------------------------------------------------

LoadResult LoadFromMemory(
    const void* pSource,
    size_t size,
    Babylon::Framework::ImageReader reader,
    TextureMetadata* metadata,
    ScratchImage& image)
{
    if (pSource == nullptr || size == 0)
    {
        return LoadResult::LoadFailed;
    }

    gli::texture texture = loadImage(pSource, size);
    if (!texture.empty())
    {
        image.GetImplementation().SetImage(texture);
        if (metadata)
        {
            *metadata = image.GetMetadata();
        }
        return LoadResult::LoadSuccessful;
    }
    else
    {
        return LoadResult::LoadFailed;
    }
}

//---------------------------------------------------------------------------------------------------------------------

void SaveToMemory(
    const ConstImage& image,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::function<void(size_t, void*)>& postSaveCallback)
{
    if (outputFormat != OutputFormat::Png && outputFormat != OutputFormat::Jpeg)
    {
        throw Babylon::Utils::BabylonNotImplException("SaveToMemory - Only PNG or Jpeg.");
    }

    auto saveCallback = [&outputFormat, &postSaveCallback](const ConstImage& image)
    {
        const uint8_t* pixels = image.GetPixels();
        if (pixels == NULL)
        {
            return;
        }

        std::vector<uint8_t> imageData;
        if (saveImageToMemory(pixels, outputFormat, image.GetWidth(), image.GetHeight(), image.GetFormat(), imageData))
        {
            postSaveCallback(imageData.size(), imageData.data());
        }
        else
        {
            throw Babylon::Utils::BabylonException("CanvasTex::SaveToMemory - saveImageToMemory failed");
        }
    };

    PrepareAndProcess(image, outputTextureFormat, saveCallback);

}

//---------------------------------------------------------------------------------------------------------------------

void SaveToMemory(
    const ScratchImage& images,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::function<void(size_t, void*)>& postSaveCallback)
{
    if (images.GetImageCount() > 1)
    {
        throw Babylon::Utils::BabylonException("ImageCount > 1 not supported");
    }

    SaveToMemory(images.GetImage(0, 0), outputTextureFormat, outputFormat, postSaveCallback);
}

//---------------------------------------------------------------------------------------------------------------------

void SaveToFile(
    const ConstImage& image,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::wstring& fileName)
{
    if (outputFormat != OutputFormat::Png && outputFormat != OutputFormat::Jpeg)
    {
        throw Babylon::Utils::BabylonNotImplException("SaveToFile - Only PNG or Jpeg.");
    }

    auto saveCallback = [&outputFormat, fileNameUtf8 = Babylon::Utils::WStringToString(fileName)](const ConstImage& image)
    {
        const uint8_t* pixels = image.GetPixels();
        if (pixels == NULL)
        {
            return;
        }

        if (!saveImageToFile(pixels, outputFormat, image.GetWidth(), image.GetHeight(), image.GetFormat(), fileNameUtf8))
        {
            throw Babylon::Utils::BabylonException("CanvasTex::SaveToFile - saveImageToFile failed");
        }
    };

    PrepareAndProcess(image, outputTextureFormat, saveCallback);
}

//---------------------------------------------------------------------------------------------------------------------

void Resize(
    const ConstImage& srcImage,
    size_t width,
    size_t height,
    ScratchImage& image)
{
    gli::texture texture = resizeImage(srcImage.GetPixels(), srcImage.GetWidth(), srcImage.GetHeight(), srcImage.GetFormat(), width, height);
    if (!texture.empty())
    {
        image.GetImplementation().SetImage(texture);
    }
    else
    {
        throw Babylon::Utils::BabylonException("CanvasTex::Resize - ResizeImage failed");
    }
}

//---------------------------------------------------------------------------------------------------------------------

void Convert(
    const ConstImage& srcImage,
    TextureFormat format,
    ScratchImage& image)
{
    // gli includes some image conversion functionality, but it requires a gli::texture source which would
    // require copying the texture into a gli::texture first
    CanvasPixelFormatDesc32 srcDesc;
    CanvasPixelFormatDesc32 dstDesc;
    MakePixelFormatDescFromTextureFormat(srcDesc, srcImage.GetFormat());
    MakePixelFormatDescFromTextureFormat(dstDesc, format);

    auto pixels = Convert32(srcImage.GetPixels(), srcImage.GetWidth(), srcImage.GetHeight(), srcImage.GetRowPitch(), srcDesc, dstDesc);

    ImageBase::ImageImplementation imageImpl;
    imageImpl.format = format;
    imageImpl.width = srcImage.GetWidth();
    imageImpl.height = srcImage.GetHeight();
    imageImpl.pixels = pixels.get();
    imageImpl.rowPitch = srcImage.GetRowPitch();
    imageImpl.slicePitch = srcImage.GetSlicePitch();

    image.GetImplementation().InitializeFromImage(imageImpl);

    // TODO: The following code uses the gli library to try and convert the texture format and then swizzle the colours
    // This should be able to do something similar to what the code above does, but it needs to be made more robust (supporting non-u8vec4 colours?)
    // convert only converts between formats, it does not swizzle colours.  Conversion from RGBA to BGRA just copies the texture.
    // swizzle will swizzle from one format into another, but only with compatible formats (that this code does not test).
    //    auto gliFormat = GetGliTextureFormat(format);
    //    texture = gli::convert(texture, gliFormat);
    //    auto info = gli::detail::get_format_info(gliFormat);
    //    texture.swizzle<glm::u8vec4>(info.Swizzles);
}


void Decompress(
    const ConstImage& cImage,
    TextureFormat format,
    ScratchImage& image)
{

    gli::texture2d texture;

    switch(cImage.GetFormat())
    {
        case TextureFormat::Bc1Unorm:
        case TextureFormat::Bc1UnormSrgb:
        {
            texture = DecompressBc1Unorm(cImage);
            break;
        }
        case TextureFormat::Bc3Unorm:
        case TextureFormat::Bc3UnormSrgb:
        {
            texture = DecompressBc3Unorm(cImage);
            break;
        }
        case TextureFormat::Bc2Unorm:
        case TextureFormat::Bc2UnormSrgb:
        {
            texture = DecompressBc2Unorm(cImage);
            break;
        }
        case TextureFormat::Bc7Unorm:
        case TextureFormat::Bc7UnormSrgb:
        default:
            throw Babylon::Utils::BabylonNotImplException(std::string("Decompress is not implemented for format ") + std::to_string(std::underlying_type_t<TextureFormat>(cImage.GetFormat())));
    }

    // TODO: Do we need to convert or swizzle the pixels in this texture to match the provided format?
    // Why does the Decompress function even take a format?  All uses of this code that care will eventually
    // run through a conversion process to convert or swizzle the bits.

    auto gliFormat = GetGliTextureFormat(format);
    if(texture.format() != gliFormat)
    {
        texture = gli::convert(texture, gliFormat);
        auto info = gli::detail::get_format_info(gliFormat);
        texture.swizzle<glm::u8vec4>(info.Swizzles);
    }

    image.GetImplementation().SetImage(texture);
}

//---------------------------------------------------------------------------------------------------------------------

void Compress(
    const ConstImage& srcImage,
    TextureFormat format,
    CompressionOptions compressionOptions,
    bool useGpu,
    ScratchImage& cImage)
{
    throw Babylon::Utils::BabylonNotImplException("Compress is not implemented.");
}

//---------------------------------------------------------------------------------------------------------------------

void Compress(
    const ScratchImage& srcImage,
    TextureFormat format,
    ScratchImage& cImage,
    bool useGpu)
{
    throw Babylon::Utils::BabylonNotImplException("Compress is not implemented.");
}

//---------------------------------------------------------------------------------------------------------------------

void GenerateMipMaps(
    const ConstImage& baseImage,
    ScratchImage& mipChain,
    FilterOptions filterOptions)
{
    throw Babylon::Utils::BabylonNotImplException("GenerateMipMaps is not implemented.");
}

}  // namespace CanvasTex
