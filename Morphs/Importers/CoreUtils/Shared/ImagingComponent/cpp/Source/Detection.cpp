/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include <ImagingComponent/Detection.h>

#include <CanvasTex/CanvasTex.h>

namespace Spectre
{
namespace ImagingV2
{
namespace ImagingComponent
{

//---------------------------------------------------------------------------------------------------------------------

Framework::ImageReader DetectImageReader(
    uint8_t* data,
    uint32_t sizeInBytes)
{
    if (sizeInBytes < 18)
    {
        return Framework::ImageReader::UNKNOWN;
    }

    // TGA - http://www.fileformat.info/format/tga/egff.htm
    // The length of the TGA signature.
    const int kTGASignatureLength = 16;
    // There are 2 final bytes after the signature at the end of the file.
    const int kTGAFooterLength = 2;
    // Reads TRUEVISION-XFILE in binary. Only TGA version 2 contains a footer.
    const uint8_t kTGASignatureFooter[kTGASignatureLength + 1] = "TRUEVISION-XFILE";

    // Calculate the offset where we want to read the signature from
    const uint32_t kTGASignatureOffset = sizeInBytes - kTGASignatureLength - kTGAFooterLength;
    const uint8_t* byteStreamFooter = data + kTGASignatureOffset;

    if (memcmp(byteStreamFooter, kTGASignatureFooter, kTGASignatureLength) == 0)
    {
        return Framework::ImageReader::TGA;
    }

    // A bit more expensive check for TGA before giving up
    if (CanvasTex::IsTgaFile(data, sizeInBytes))
    {
        return Framework::ImageReader::TGA;
    }

    switch (data[0])
    {
    case (uint8_t)'\xFF': // JPG - http://www.fileformat.info/format/jpeg/egff.htm
    {
        return (!memcmp(data, "\xFF\xD8", 2)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case (uint8_t)'\x89': // PNG - http://www.w3.org/TR/PNG/#5Introduction
    {
        return (!memcmp(data, "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A", 8)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case 'B': // BMP - http://www.fileformat.info/format/bmp/egff.htm
    {
        return ((data[1] == 'M')) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case 'D': // DDS - https://msdn.microsoft.com/en-us/library/windows/desktop/bb943991(v=vs.85).aspx
    {
        return (!memcmp(data, "DDS ", 4)) ?
            Framework::ImageReader::DDS : Framework::ImageReader::UNKNOWN;
    }
    case 'G': // GIF - http://www.fileformat.info/format/gif/egff.htm
    {
        return (!memcmp(data, "GIF87a", 6) ||
                !memcmp(data, "GIF89a", 6)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case 'I': // TIFF - http://www.fileformat.info/format/tiff/egff.htm
    {
        return (!memcmp(data, "\x49\x49\x2A\x00", 4)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case 'M': // TIFF - http://www.fileformat.info/format/tiff/egff.htm
    {
        return (!memcmp(data, "\x4D\x4D\x00\x2A", 4)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case 'R': // WEBP - https://en.wikipedia.org/wiki/WebP
    {
        return (!memcmp(data, "RIFF", 4) &&
                !memcmp((data + 8), "WEBP", 4)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    case '8': // PSD - https://www.adobe.com/devnet-apps/photoshop/fileformatashtml/
    {
        return (!memcmp(data, "8BPS", 4)) ?
            Framework::ImageReader::PSD : Framework::ImageReader::UNKNOWN;
    }
    case '\0': // ICO - https://msdn.microsoft.com/en-us/library/ms997538.aspx
    {
        return (!memcmp(data, "\x00\x00\x01\x00", 4) ||
                !memcmp(data, "\x00\x00\x02\x00", 4)) ?
            Framework::ImageReader::WIC : Framework::ImageReader::UNKNOWN;
    }
    default:
        return Framework::ImageReader::UNKNOWN;
    }
}

//---------------------------------------------------------------------------------------------------------------------

bool TryGetImageWidthHeight(
    void* data,
    uint32_t size,
    uint32_t& width,
    uint32_t& height
)
{
    width = 0;
    height = 0;

    if (data != nullptr)
    {
        Framework::ImageReader reader = DetectImageReader((uint8_t*)data, size);

        CanvasTex::TextureMetadata metadata;
        metadata.SetHeight(0);
        metadata.SetWidth(0);

        bool success = GetMetadataFromMemory(data, size, reader, metadata);

        if (success)
        {
            height = (uint32_t)metadata.GetHeight();
            width = (uint32_t)metadata.GetWidth();
            return true;
        }
    }

    return false;
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

//---------------------------------------------------------------------------------------------------------------------

Framework::ImageReader DetectImageReaderFromHeader(
    uint8_t* data,
    uint32_t sizeInBytes)
{
    return ImagingV2::ImagingComponent::DetectImageReader(data, sizeInBytes);
}

//---------------------------------------------------------------------------------------------------------------------

bool TryGetImageWidthHeight(
    void* data,
    uint32_t size,
    uint32_t& width,
    uint32_t& height)
{
    return ImagingV2::ImagingComponent::TryGetImageWidthHeight(data, size, width, height);
}

}  // namespace ImagingComponent
}  // namespace ImagingV1
}  // namespace Spectre