/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include <ImagingComponent/ImagingComponent.h>

#include <CoreUtils/Trace.h>
#include <CoreUtils/Memory.h>

#include <CanvasTex/CanvasTex.h>

DEFINE_TRACE_AREA(ImagingComponent_Processing, Trace::Info);

//---------------------------------------------------------------------------------------------------------------------

namespace Spectre
{
namespace ImagingV2
{
namespace ImagingComponent
{
namespace
{

//---------------------------------------------------------------------------------------------------------------------

// Grey
const uint8_t defaultTexture[Spectre::ImagingV2::ImagingComponent::kDefaultTextureSize] =
{
    0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff,  0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0xff,
    0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd,  0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xcd, 0xfd,
    0xfd, 0xfd, 0xfd, 0x00, 0x00, 0x00, 0x00, 0x00,  0xbf, 0xac, 0x71, 0xc4, 0x00, 0x1e, 0x00, 0x95,
    0xf0, 0x59, 0xb9, 0x3b, 0x5d, 0x00, 0x00, 0x00,  0x70, 0x18, 0x1b, 0x1e, 0x5d, 0x00, 0x00, 0x00,
    0xa0, 0xed, 0x59, 0xc0, 0xfa, 0x7f, 0x00, 0x00,  0x81, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x37, 0x00, 0x00, 0x00, 0xfd, 0xfd, 0xfd, 0xfd
};

//---------------------------------------------------------------------------------------------------------------------

enum class FileReader
{
    DDS,
    TGA,
    WIC,
    PSD,
    UNKNOWN
};

//---------------------------------------------------------------------------------------------------------------------

enum class EImageFileAlphaContent : uint8_t
{
    kUnknown = 0,   // The alpha content of the file could not be determined
    kNone = 1,
    kAlpha = 2
};

//---------------------------------------------------------------------------------------------------------------------

struct ImageFileContent
{
    EImageFileAlphaContent alphaContent = EImageFileAlphaContent::kUnknown;
    FileReader readerType = FileReader::WIC;
};

//---------------------------------------------------------------------------------------------------------------------

// Logs details about each texture loaded for a model.
// Details include whether or not the texture contains an alpha channel,
// file path, compression type initially requested, compression
// type eventually selected, height, width, pixel depth and file size.
void LogTextureData(
    const std::string& name,
    const std::string& filePath,
    TextureCompressionType compressionTypeSelected,
    uint64_t sizeInBytes,
    uint32_t width,
    uint32_t height,
    uint32_t depth,
    EImageFileAlphaContent alphaType,
    uint8_t alphaMin,
    uint8_t alphaMax)
{
    std::string humanReadable_selectedCompressionType = "Not Available";
    switch (compressionTypeSelected)
    {
    case TextureCompressionType::None:
        humanReadable_selectedCompressionType = "None";
        break;
    case TextureCompressionType::BC3:
        humanReadable_selectedCompressionType = "BC3";
        break;
    case TextureCompressionType::BC5:
        humanReadable_selectedCompressionType = "BC5";
        break;
    case TextureCompressionType::BC7:
        humanReadable_selectedCompressionType = "BC7";
        break;
    case TextureCompressionType::PNG:
        humanReadable_selectedCompressionType = "PNG";
        break;
    case TextureCompressionType::PNG256:
        humanReadable_selectedCompressionType = "PNG256";
        break;
    case TextureCompressionType::JPEG:
        humanReadable_selectedCompressionType = "JPEG";
        break;
    }

    std::string humanReadableAlpha;
    switch (alphaType)
    {
    default:
    case EImageFileAlphaContent::kUnknown:
        humanReadableAlpha = "Unknown";
        break;
    case EImageFileAlphaContent::kNone:
        humanReadableAlpha = "None";
        break;
    case EImageFileAlphaContent::kAlpha:
        humanReadableAlpha = "Alpha";
        break;
    }

    TRACE_IMPORTANT(ImagingComponent_Processing, "\n"); // Make texture data readable
    TRACE_IMPORTANT(ImagingComponent_Processing, "Details for texture: %s", name.c_str());
    TRACE_IMPORTANT(ImagingComponent_Processing, "Path:  %s", filePath.c_str());
    TRACE_IMPORTANT(ImagingComponent_Processing, "File size: %llud kB", sizeInBytes / 1024);
    TRACE_IMPORTANT(ImagingComponent_Processing, "Compression selected: %s ", humanReadable_selectedCompressionType.c_str());
    TRACE_IMPORTANT(ImagingComponent_Processing, "Dimensions: %u x %u ", width, height);
    TRACE_IMPORTANT(ImagingComponent_Processing, "Alpha Type: %s", humanReadableAlpha.c_str());
    TRACE_IMPORTANT(ImagingComponent_Processing, "Alpha Range: [%u,%u]", static_cast<unsigned int>(alphaMin), static_cast<unsigned int>(alphaMax));
    TRACE_IMPORTANT(ImagingComponent_Processing, "Depth (Volume/Array): %u", depth);
}

//---------------------------------------------------------------------------------------------------------------------

// Checks to see if there is an alpha channel e.g. RGBA and not RGB
ImageFileContent DetectImageFileAlphaType(
    void* data,
    uint32_t sizeInBytes)
{
    // Alpha recognition now supported for both PNG and TGA formats. If we get neither of these files then we presume alpha is invalid.
    ImageFileContent result;

    // PNG DETECTION
    {
        // A PNG file header has these exact characters as the first 8 bytes.
        // To check we are reading a legitimate PNG file we want to check this matches.
        const int kPNGSignatureLength = 8;
        const int kPNGMinimumLength = 32;

        if (sizeInBytes >= kPNGMinimumLength)
        {
            const uint8_t kPNGHeader[kPNGSignatureLength] = { 137, 80, 78, 71, 13, 10, 26, 10 };

            // The constant index value to access the bit depth and color type in the
            // IHDR chunk of a PNG file both values are one byte long. The bitDepth should
            // be between 1-16 and the colorType can be: 0, 2, 3, 4 or 6.
            // http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html
            // http://www.libpng.org/pub/png/spec/1.2/PNG-Structure.html
            // "https://en.wikipedia.org/wiki/Portable_Network_Graphics#Critical_chunks" for reference.
            const int kColorTypeIndex = 25;
            const uint8_t* byteStream = static_cast<const uint8_t*>(data);

            if (memcmp(byteStream, kPNGHeader, kPNGSignatureLength) == 0)
            {
                //Set it to an initially incorrect values as neither 0 or -1 are viable types for
                //color value.
                uint8_t colorTypeValue = static_cast<uint8_t>(-1);

                // Get the color value from the file header
                colorTypeValue = byteStream[kColorTypeIndex];

                // Refer to http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html
                // For how the color type maps to the different texture styles.
                switch (colorTypeValue)
                {
                    case 0:
                    case 2:
                        // Color used 24bpp RGB/BGR only
                        result.alphaContent = EImageFileAlphaContent::kNone; break;

                    case 4:
                    case 6:
                        // Color used 32bpp includes alpha channel RGBA/BGRA
                        result.alphaContent = EImageFileAlphaContent::kAlpha; break;

                    case 3:
                        // If the image is using a palleted type. I'm am unsure how this works exactly.
                        // Does it have 3 or 4 channels or something completely different.
                    default:
                        result.alphaContent = EImageFileAlphaContent::kUnknown;
                }

                // Return the alpha support for this PNG file.
                return result;
            }// end if
        }// end outer if
    } // end scope

    // TGA DETECTION
    {
        // The length of the TGA signature we are looking for.
        const int kTGASignatureLength = 16;
        // Make sure the data we have is long enough so we don't extend boundaries.
        const int kTGAMinimumLength = 32;
        // There are 2 final bytes after the signature at the end of the file.
        const int kTGAFooterLength = 2;
        // The location the index the bitDepth is stored in the file header.
        const int kBitDepthIndex = 16;

        if (sizeInBytes >= kTGAMinimumLength)
        {
            const uint8_t* byteStream = static_cast<const uint8_t*>(data);

            // Reads TRUEVISION-XFILE in binary. Only TGA version 2 contains a footer so we only support alpha for this version.
            const uint8_t kTGASignatureFooter[kTGASignatureLength + 1] = "TRUEVISION-XFILE";

            // Calculate the offset where we want to read the signature from
            const uint32_t kTGASignatureOffset = sizeInBytes - kTGASignatureLength - kTGAFooterLength;
            const uint8_t* byteStreamFooter = byteStream + kTGASignatureOffset;

            if (memcmp(byteStreamFooter, kTGASignatureFooter, kTGASignatureLength) == 0)
            {
                uint8_t bitDepthValue = static_cast<uint8_t>(0);

                bitDepthValue = byteStream[kBitDepthIndex];

                if (bitDepthValue == 24)
                {
                    result.alphaContent = EImageFileAlphaContent::kNone;
                }
                else if (bitDepthValue == 32)
                {
                    result.alphaContent = EImageFileAlphaContent::kAlpha;
                }
                else
                {
                    result.alphaContent = EImageFileAlphaContent::kUnknown;
                }

                // Return the alpha support for this TGA file.
                return result;
            }// end if
        }// end outer if
    } // end scope

    // TODO: Need to add support for DDS files in the future.

    // If not returned before this return the default unknown value.
    return result;
}

//---------------------------------------------------------------------------------------------------------------------

// Helper class x,y accessor
struct ImageXY
{
    ImageXY(const CanvasTex::Image& img) : _img(img)
    {
    }

    inline uint8_t At(size_t x, size_t y) const
    {
        x = (x <= 0) ? 0 : x >= _img.GetWidth() ? _img.GetWidth() - 1 : x;
        y = (y <= 0) ? 0 : y >= _img.GetHeight() ? _img.GetHeight() - 1 : y;
        return *(_img.GetPixels() + (_img.GetRowPitch() * y) + (x * 4));
    }

    CanvasTex::Image _img;
};

//---------------------------------------------------------------------------------------------------------------------

void ConvertHeightMapToNormalMap(
    CanvasTex::Image& image,
    float scale)
{
    std::vector<uint8_t> buffer(image.GetSlicePitch());
    uint8_t* data = buffer.data();

    ImageXY imageXY(image);

    for (size_t v = 0; v < image.GetHeight(); v++)
    {
        for (size_t u = 0; u < image.GetWidth(); u++)
        {
            data = buffer.data() + (u * 4) + (v * image.GetRowPitch());

            uint8_t tl = imageXY.At(u - 1, v - 1);
            uint8_t  t = imageXY.At(u, v - 1);
            uint8_t tr = imageXY.At(u + 1, v - 1);

            uint8_t  l = imageXY.At(u - 1, v);
            //uint8_t  m = localImg.xy(u, v);
            uint8_t  r = imageXY.At(u + 1, v);

            uint8_t bl = imageXY.At(u - 1, v + 1);
            uint8_t  b = imageXY.At(u, v + 1);
            uint8_t br = imageXY.At(u + 1, v + 1);

            /*
            Coordinates are laid out as follows:
                tl |  t  | tr
            ----+-----+----
                l |  m  |  r
            ----+-----+----
                bl |  b  | br
            */

            // The Sobel X kernel is:
            //
            // [ 1.0  0.0  -1.0 ]
            // [ 2.0  0.0  -2.0 ]
            // [ 1.0  0.0  -1.0 ]
            int Gx = tl - tr + (2 * l) - (2 * r) + bl - br;

            // The Sobel Y kernel is:
            //
            // [  1.0    2.0    1.0 ]
            // [  0.0    0.0    0.0 ]
            // [ -1.0   -2.0   -1.0 ]
            int Gy = tl + (2 * t) + tr - bl - (2 * b) - br;

            Spectre::Utils::Math::Vector3 N(static_cast<float>(-Gx), static_cast<float>(-Gy), 255.0f * scale);
            N.Normalize();

            data[0] = static_cast<uint32_t>((N.z * 127.5f) + 127.5f) & 0xFF;  // B
            data[1] = static_cast<uint32_t>((N.y * 127.5f) + 127.5f) & 0xFF;  // G
            data[2] = static_cast<uint32_t>((N.x * 127.5f) + 127.5f) & 0xFF;  // R
            data[3] = 255;                                                 // A
        }
    }

    // overwrite the original image
    memcpy_s(image.GetPixels(), image.GetSlicePitch(), buffer.data(), image.GetSlicePitch());
}

//---------------------------------------------------------------------------------------------------------------------

bool IsImageGrayScale(
    const uint32_t pixelArray[],
    size_t width,
    size_t height,
    double percentageMatch = 1.0f)
{
    double validPixels = 0.0f;
    const size_t NumPixels = height*width;
    const uint32_t* Pixel = reinterpret_cast<const uint32_t*>(pixelArray);
    for (size_t i = 0;
        i < NumPixels;
        i++, Pixel++)
    {
        uint8_t b = static_cast<uint8_t>((*Pixel >> 16) & 0xFF);
        uint8_t g = static_cast<uint8_t>((*Pixel >> 8) & 0xFF);
        uint8_t r = static_cast<uint8_t>((*Pixel >> 0) & 0xFF);
        if ((r == g) && (g == b))
        {
            validPixels++;
        }
        else
        {
            if (percentageMatch == 1.0f)
                return false; // early out if 100% match required
        }
    }

    return ((validPixels / NumPixels) >= percentageMatch);
}

//---------------------------------------------------------------------------------------------------------------------

void FindMinMaxAlpha(
    const uint32_t pixelArray[],
    size_t width,
    size_t height,
    size_t strideBytes,
    uint8_t& outAlphaMin,
    uint8_t& outAlphaMax,
    bool earlyExit = false)
{
    // Start with min/max at opposite extremes, then calculate the actual alpha range.
    uint8_t alphaMin = 0xff;
    uint8_t alphaMax = 0x00;

    const uint8_t* pixelByteArray = reinterpret_cast<const uint8_t*>(pixelArray);
    for (size_t y = 0; y < height; y++)
    {
        const uint32_t* rowPixels = reinterpret_cast<const uint32_t*>(pixelByteArray + strideBytes * y);
        for (size_t x = 0; x < width; x++)
        {
            uint32_t pixel = rowPixels[x];
            uint8_t alpha = uint8_t(pixel >> 24);
            alphaMin = std::min(alpha, alphaMin);
            alphaMax = std::max(alpha, alphaMax);

            if (earlyExit && (alphaMin < alphaMax))
            {
                // If earlyExit = true, we don't need to find the exact min and max values;
                // Instead, exit as soon as we know there are two pixels with different alpha values
                outAlphaMin = alphaMin;
                outAlphaMax = alphaMax;
                return;
            }
        }
    }

    outAlphaMin = alphaMin;
    outAlphaMax = alphaMax;
}

//---------------------------------------------------------------------------------------------------------------------

// Context for the texture processing functions. Maintains information about the texture
// and allows for convenient passing between methods.
struct Context
{
    ImageFileContent imageFileContent;

    // True if the raw image pixel width is a multiple of 4
    bool isWidthMultipleOf4 = false;

    // True if the raw image pixel height is a multiple of 4
    bool isHeightMultipleOf4 = false;

    // Metadata extracted form the source image
    CanvasTex::TextureMetadata metadata;

    // Source image
    CanvasTex::ScratchImage source;

    // Image after any conversions applied.
    CanvasTex::ScratchImage result;

    // Image after mip chain has been generated
    CanvasTex::ScratchImage resultWithFullMipChain;

    // Pointer to the scratch image (no need to FREE. it points to either source, or result)
    CanvasTex::ScratchImage* pScratchImage = nullptr;

    uint8_t flags = 0;
    uint8_t alphaMin = 0x00;
    uint8_t alphaMax = 0xff;

    // True if the original image was compressed, and we successfully decompressed it
    bool decompressed = false;

    // True if the original image was in a non-standard format and we converted it to RGBA32
    bool converted = false;

    int textureCompression = TextureCompressionType::None;
};

//---------------------------------------------------------------------------------------------------------------------

// Helper function - try to determine texture file type by header value and then load
void RetryLoadFromMemory(
    void* data,
    uint32_t sizeInBytes,
    Context& contextOut)
{
    auto imageType = DetectImageReader((uint8_t*)data, sizeInBytes);

    if (LoadFromMemory(data, sizeInBytes, imageType, &contextOut.metadata, contextOut.source) != CanvasTex::LoadResult::LoadSuccessful)
    {
        TRACE_IMPORTANT(ImagingComponent_Processing, "Unable to determine Image File Type");

        CanvasTex::Image defaultImage;
        defaultImage.SetHeight(2);
        defaultImage.SetWidth(2);
        defaultImage.SetRowPitch(8);
        defaultImage.SetSlicePitch(16);
        defaultImage.SetFormat(CanvasTex::TextureFormat::B8g8r8a8UnormSrgb);
        defaultImage.SetPixels((uint8_t*)&defaultTexture[0]);

        // No alpha in default image
        ImageFileContent fileContent;
        fileContent.alphaContent = EImageFileAlphaContent::kNone;
        contextOut.imageFileContent = fileContent;

        contextOut.source.InitializeFromImage(defaultImage);
    }
}

//---------------------------------------------------------------------------------------------------------------------

void DetectImageAlpha(
    uint8_t* imageData,
    size_t imageWidth,
    size_t imageHeight,
    size_t imageRowPitch,
    CanvasTex::TextureFormat imageFormat,
    EImageFileAlphaContent& alphaContent,
    uint8_t& imageFlags)
{
    uint8_t alphaMin = 0x00; // Assume full-range alpha by default
    uint8_t alphaMax = 0xff;

    if (imageFormat == CanvasTex::TextureFormat::B8g8r8a8Unorm ||
        imageFormat == CanvasTex::TextureFormat::R8g8b8a8Unorm)
    {
        const uint32_t* pixelArray = reinterpret_cast<const uint32_t*>(imageData);
        // We don't need to know the exact min and max values, only whether min < max and hence image has
        // at least two pixels with different alpha values, so pass in true for earlyExit
        FindMinMaxAlpha(pixelArray, imageWidth, imageHeight, imageRowPitch, alphaMin, alphaMax, true);

        if (alphaMin == 0xff) //255
        {
            // Alpha channel is exactly white.
            // In current assets this is often caused by a 24-bit PNG being loaded, and the LoadFromWICMemory() adds an alpha channel filled to maximum value (0xff)
            // In this case, regard the alpha as not being part of the source data.
            // TODO: we need to detect and distinguish the various cases more correctly:
            // a) common case of alpha channel not containing authored data but instead being added due to various format conversions
            // b) rare case of alpha channel being intentionally supplied as full white (e.g. as Unity style Specular map with gloss 100% throughout, for perfect mirror)
            alphaContent = EImageFileAlphaContent::kNone;
        }
    }

    // If there's a valid alpha channel in the texture and there are pixels where the opacity is
    // non-zero, flag the texture as having alpha. This can be used to apply alpha blending to the
    // material
    if (alphaMax != 0x00 &&
        (alphaContent == EImageFileAlphaContent::kAlpha ||
            alphaContent == EImageFileAlphaContent::kUnknown)) // part of the texture is transparent
    {
        imageFlags |= Spectre::Framework::TextureSegment::EFlag::kFlag_TextureHasActiveAlpha;
    }

    if (alphaContent == EImageFileAlphaContent::kAlpha)
    {
        imageFlags |= Spectre::Framework::TextureSegment::EFlag::kFlag_AlphaValid;
    }
}

//---------------------------------------------------------------------------------------------------------------------

void DetectImageAlphaFromChannelType(ImagingV2::ImagingComponent::AlphaChannelType alphaType,
    EImageFileAlphaContent& alphaContent,
    uint8_t& imageFlags)
{
    if (alphaType == AlphaChannelType::Opaque)
    {
        // Alpha channel is exactly white.
        // In current assets this is often caused by a 24-bit PNG being loaded, and the LoadFromWICMemory() adds an alpha channel filled to maximum value (0xff)
        // In this case, regard the alpha as not being part of the source data.
        // TODO: we need to detect and distinguish the various cases more correctly:
        // a) common case of alpha channel not containing authored data but instead being added due to various format conversions
        // b) rare case of alpha channel being intentionally supplied as full white (e.g. as Unity style Specular map with gloss 100% throughout, for perfect mirror)
        alphaContent = EImageFileAlphaContent::kNone;
    }

    // If there's a valid alpha channel in the texture and there are pixels where the opacity is
    // non-zero, flag the texture as having alpha. This can be used to apply alpha blending to the
    // material
    if (alphaType != AlphaChannelType::Transparent &&
        (alphaContent == EImageFileAlphaContent::kAlpha ||
            alphaContent == EImageFileAlphaContent::kUnknown)) // part of the texture is transparent
    {
        imageFlags |= Spectre::Framework::TextureSegment::EFlag::kFlag_TextureHasActiveAlpha;
    }

    if (alphaContent == EImageFileAlphaContent::kAlpha)
    {
        imageFlags |= Spectre::Framework::TextureSegment::EFlag::kFlag_AlphaValid;
    }
}

//---------------------------------------------------------------------------------------------------------------------

// Helper function which takes care of loading the image and performing any necessary conversion
void LoadImage(
    Framework::ImageReader reader,
    void* data,
    uint32_t sizeInBytes,
    int textureCompression,
    Context& contextOut)
{
    // Check the content of the file to find whether or not the texture has a legitimate alpha channel.
    contextOut.imageFileContent = DetectImageFileAlphaType(data, sizeInBytes);
    contextOut.textureCompression = textureCompression;

    if (LoadFromMemory(data, sizeInBytes, reader, &contextOut.metadata, contextOut.source) != CanvasTex::LoadResult::LoadSuccessful)
    {
        TRACE_IMPORTANT(ImagingComponent_Processing, "Image not processed correctly - retry based on File Headers");

        RetryLoadFromMemory(data, sizeInBytes, contextOut);
    }

    if (contextOut.source.GetImageCount() == 0)
    {
        throw Utils::SpectreException("No images are available in the file.");
    }

    const auto pixelFormat = CanvasTex::TextureFormat::B8g8r8a8Unorm;

    // Need to uncompress if compressed format.
    if (CanvasTex::IsCompressed(contextOut.metadata.GetFormat()))
    {
        contextOut.decompressed = true;
        CanvasTex::Decompress(contextOut.source.GetImage(0, 0), pixelFormat, contextOut.result);
    }
    // Convert to our format BGRA 32 Bpp if needed.
    else if (contextOut.metadata.GetFormat() != pixelFormat)
    {
        contextOut.converted = true;
        CanvasTex::Convert(contextOut.source.GetImage(0, 0), pixelFormat, contextOut.result);
    }

    if (contextOut.decompressed || contextOut.converted)
    {
        contextOut.pScratchImage = &contextOut.result;
    }
    else
    {
        contextOut.pScratchImage = &contextOut.source;
    }

    // Only deal with one image currently.
    CanvasTex::Image image = contextOut.pScratchImage->GetImage(0, 0);

    // Update context alphaContent and flags:
    DetectImageAlpha(image.GetPixels(), image.GetWidth(), image.GetHeight(), image.GetRowPitch(), image.GetFormat(), contextOut.imageFileContent.alphaContent, contextOut.flags);
}

//---------------------------------------------------------------------------------------------------------------------

// Helper function which takes an image that has already been loaded and generates the output data for the specified LOD
void GenerateSingleLod(
    uint32_t textureId,
    uint32_t lod,
    Framework::ITextureWriter* writer,
    Context& context)
{
    const int bytesPerPixel = 4;

    if (lod >= context.pScratchImage->GetMetadata().GetMipLevels())
    {
        //lod = context.pScratchImage->GetMetadata().mipLevels - 1;
        return;
    }

    CanvasTex::Image sourceImage = context.pScratchImage->GetImage(0, lod);

    // Must check each lod to determine if BC3 can be applied
    bool isWidthMultipleOf4 = sourceImage.GetWidth() % 4 == 0;
    bool isHeightMultipleOf4 = sourceImage.GetHeight() % 4 == 0;
    bool canCompressBC = isWidthMultipleOf4 && isHeightMultipleOf4;

    auto textureCompression = context.textureCompression;
    if (textureCompression != TextureCompressionType::PNG &&
        !canCompressBC)
    {
        textureCompression = TextureCompressionType::None;
    }

    if (textureCompression == TextureCompressionType::BC3 ||
        textureCompression == TextureCompressionType::BC5 ||
        textureCompression == TextureCompressionType::BC7 )
    {
        CanvasTex::ScratchImage resultImage;

        // For now we use BC3 which is 8-bit format (1 byte per pixel)
        CanvasTex::TextureFormat compressionFormat = CanvasTex::TextureFormat::Bc3Unorm;
        Framework::TextureSegment::EFormat textureFormat = Spectre::Framework::TextureSegment::EFormat::kBC3_UNORM;
        switch (textureCompression)
        {
        case BC3:
        {
            compressionFormat = CanvasTex::TextureFormat::Bc3Unorm;
            textureFormat = Spectre::Framework::TextureSegment::EFormat::kBC3_UNORM;
            break;
        }
        case BC5:
        {
            compressionFormat = CanvasTex::TextureFormat::Bc5Unorm;
            textureFormat = Spectre::Framework::TextureSegment::EFormat::kBC5_UNORM;
            break;
        }
        case BC7:
        {
            compressionFormat = CanvasTex::TextureFormat::Bc7Unorm;
            textureFormat = Spectre::Framework::TextureSegment::EFormat::kBC7_UNORM;
            break;
        }
        }
        int bytesPerCompressedPixel = 1;

        CanvasTex::Compress(sourceImage, compressionFormat, CanvasTex::CompressionOptions::Bc7Use3Subsets, true, resultImage);

        context.metadata = resultImage.GetMetadata();
        uint32_t strideUncompressed = static_cast<uint32_t>(context.metadata.GetWidth() * bytesPerPixel);
        uint32_t strideCompressed = static_cast<uint32_t>(context.metadata.GetWidth() * bytesPerCompressedPixel);

        void* destinationBuffer = writer->AddTextureEncoded(
            textureId,
            static_cast<uint32_t>(context.metadata.GetWidth()),
            static_cast<uint32_t>(context.metadata.GetHeight()),
            bytesPerPixel, // Currently unused
            strideUncompressed,
            static_cast<uint32_t>(resultImage.GetPixelsSize()),
            textureFormat,
            context.flags
        );
        memcpy(destinationBuffer, resultImage.GetPixels(), context.metadata.GetHeight() * strideCompressed);
    }
    else if (textureCompression == TextureCompressionType::PNG)
    {
        uint32_t strideUncompressed = static_cast<uint32_t>(context.metadata.GetWidth() * bytesPerPixel);

        CanvasTex::SaveToMemory(
            sourceImage,
            CanvasTex::TextureFormat::B8g8r8a8Unorm,
            CanvasTex::OutputFormat::Png,
            [&](size_t size, void* ptr)
            {
                void* destinationBuffer = writer->AddTextureEncoded(
                    textureId,
                    static_cast<uint32_t>(context.metadata.GetWidth()),
                    static_cast<uint32_t>(context.metadata.GetHeight()),
                    bytesPerPixel, // Currently unused
                    strideUncompressed,
                    static_cast<uint32_t>(size),
                    Spectre::Framework::TextureSegment::EFormat::kPNG,
                    context.flags
                );

                memcpy(destinationBuffer, ptr, size);
            }
        );
    }
    else if (textureCompression == TextureCompressionType::None)
    {
        // Copy the converted image to the destination buffer.
        uint32_t stride = static_cast<uint32_t>(sourceImage.GetWidth() * bytesPerPixel);
        void* destinationBuffer = writer->AddTextureRAW(
            textureId,
            static_cast<uint32_t>(sourceImage.GetWidth()),
            static_cast<uint32_t>(sourceImage.GetHeight()),
            bytesPerPixel,
            stride,
            context.flags
            );
        memcpy(destinationBuffer, sourceImage.GetPixels(), sourceImage.GetHeight() * stride);
    }
    else
    {
        throw Utils::SpectreException("Unsupported texture compression type");
    }
}

//---------------------------------------------------------------------------------------------------------------------

uint32_t CalculateMipLevel(
    Context& context,
    uint32_t lod,
    uint32_t minimumMip)
{
    // given a 'beihai' lod (0, 1, 2) compute the most appropriate mip level for the
    // image, that most closely matches the request LOD.

    const int kMaxLOD = 3;
    uint32_t numPixels[kMaxLOD] = { 0xFFFFFFFF, 512, 64 };

    // LOD 0 is original texture size...
    if (lod == 0)
        return 0;

    auto meta = context.pScratchImage->GetMetadata();

    // We look for Mip that is closest to the requested size, but favor images smaller.

    size_t bestDistance = 0xFFFFFFFF;
    size_t bestMip = 0;
    for (size_t i = minimumMip + 1; i < meta.GetMipLevels(); ++i)
    {
        auto image = context.pScratchImage->GetImage(0, i);
        size_t size = image.GetHeight();
        if (image.GetWidth() > size)
        {
            size = image.GetWidth();
        }

        size_t distance = numPixels[lod] - size;
        if (distance < bestDistance)
        {
            bestDistance = distance;
            bestMip = i;
        }
    }

    return (uint32_t)bestMip;
}

//---------------------------------------------------------------------------------------------------------------------

void GenerateAllLods(
    uint32_t textureId,
    uint32_t numLods,
    std::vector<Framework::ITextureWriter*> &writers,
    Context &context,
    const Framework::TextureProcessingOptions& options)
{
    CanvasTex::Image image = context.pScratchImage->GetImage(0, 0);

    if (options.LayerType == Spectre::Framework::TextureMaterialLayer::kNormal)
    {
        ConvertGrayscaleNormalMap(image, options.ScaleFactor);
    }

    //todo: from here, must be decoded i.e. not BC3
    // Always generate Mip Chain if Lod is required
    if (numLods > 1)
    {
        CanvasTex::GenerateMipMaps(context.pScratchImage->GetImage(0, 0), context.resultWithFullMipChain);
        context.source.Release();
        context.result.Release();

        context.pScratchImage = &context.resultWithFullMipChain;
    }

    if (writers.size() != numLods)
    {
        throw Utils::SpectreException("ImagingComponent::ProcessLODs:Insufficient Writers");
    }

    // Generate each requested LOD
    uint32_t minimumMip = 0;
    for (uint32_t i = 0; i < numLods; ++i)
    {
        uint32_t selectedMip = CalculateMipLevel(context, i, minimumMip);

        if (writers[i] != nullptr)
        {
            GenerateSingleLod(textureId, selectedMip, writers[i], context);
        }
        else
        {
            TRACE_IMPORTANT(ImagingComponent_Processing, "ProcessLODs: Texture %ui - No writer provided for LOD=%ui", textureId, i); // Make texture data readable
        }

        // Update minimum mip
        minimumMip = selectedMip;
    }
}

//---------------------------------------------------------------------------------------------------------------------

uint8_t GetCorrectedAlphaValue(
    uint8_t alphaValue,
    AlphaChannelType expectedAlphaType,
    float alphaCutOff)
{
    switch (expectedAlphaType)
    {
    case AlphaChannelType::Opaque:
        return 255;
    case AlphaChannelType::Binary:
        return (alphaValue >= (255.0f * alphaCutOff)) ? 255 : 0;
    case AlphaChannelType::Transparent:
        return 0;
    case AlphaChannelType::GrayscaleVariance:
        // Any value is acceptable for grayscale - don't rewrite
    default:
        // Unknown alpha channel type - don't rewrite
        return alphaValue;
    }
}

} // End private namespace

//---------------------------------------------------------------------------------------------------------------------

const uint8_t* GetDefaultTexture()
{
    return defaultTexture;
}

void EncodeBGRA(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    Framework::ImageReader reader,
    void* data,
    uint32_t sizeInBytes,
    Framework::ITextureWriter* writer,
    int textureCompression,
    uint32_t lod)
{
    Context context;
    LoadImage(reader, data, sizeInBytes, textureCompression, context);

    GenerateSingleLod(textureId, lod, writer, context);

    // Log the texture data at this stage
    LogTextureData(
        textureName,
        texturePath,
        static_cast<TextureCompressionType>(textureCompression),
        sizeInBytes,
        static_cast<uint32_t>(context.metadata.GetWidth()),
        static_cast<uint32_t>(context.metadata.GetHeight()),
        static_cast<uint32_t>(context.metadata.GetDepth()),
        context.imageFileContent.alphaContent,
        context.alphaMin,
        context.alphaMax);
}

//---------------------------------------------------------------------------------------------------------------------

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
    const Framework::TextureProcessingOptions& options)
{
    if (writers.empty())
    {
        throw Utils::SpectreException("ProcessRAWLODs: No writers provided");
    }

    Context context;
    //populate context for RAW texture data
    context.metadata.SetWidth(width);
    context.metadata.SetHeight(height);
    context.flags = flags;
    context.textureCompression = options.TextureCompression;

    // BC3 must be decompressed to BGRA for mipmap generation
    if (format == Framework::TextureSegment::kPNG)
    {
        // PNG
        CanvasTex::TextureMetadata metadata;
        auto loadResult = CanvasTex::LoadFromMemory(data, sizeInBytes, Framework::ImageReader::WIC, &metadata, context.result);

        if (loadResult != CanvasTex::LoadResult::LoadSuccessful)
        {
            throw Spectre::Utils::SpectreException("Failed to load image from memory.");
        }
    }
    else
    {
        CanvasTex::Image img;
        img.SetWidth(width);
        img.SetHeight(height);
        img.SetRowPitch(lineStride);
        img.SetSlicePitch(sizeInBytes);
        img.SetPixels(static_cast<uint8_t*>(data));
        img.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);

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

        if (CanvasTex::IsCompressed(img.GetFormat()) == true)
        {
            CanvasTex::Decompress(img, CanvasTex::TextureFormat::B8g8r8a8Unorm, context.result);
        }
        else
        {
            // already in "BGRA" Format
            context.result.InitializeFromImage(img);
        }
    }

    context.pScratchImage = &context.result;

    uint32_t numLods = static_cast<uint32_t>(options.LOD);
    GenerateAllLods(textureId, numLods, writers, context, options);
}

//---------------------------------------------------------------------------------------------------------------------

void EncodeBGRAForAllLODs(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    void* data,
    uint32_t sizeInBytes,
    std::vector<Framework::ITextureWriter*>& writers,
    const Framework::TextureProcessingOptions& options)
{
    SpectreUnusedParameter(textureName);
    SpectreUnusedParameter(texturePath);

    if (writers.empty())
    {
        throw Utils::SpectreException("ProcessLODs: No writers provided");
    }

    Context context;
    LoadImage(options.Reader, data, sizeInBytes, options.TextureCompression, context);

    uint32_t numLods = static_cast<uint32_t>(options.LOD);
    GenerateAllLods(textureId, numLods, writers, context, options);
}

//---------------------------------------------------------------------------------------------------------------------

AlphaChannelType DetectImageAlphaChannelType(
    const uint8_t* imageData,  /*Pixel array after BGRA conversion*/
    const size_t imageWidth,
    const size_t imageHeight,
    const CanvasTex::TextureFormat imageFormat
)
{
    SpectreAssert(imageFormat == CanvasTex::TextureFormat::B8g8r8a8Unorm ||
        imageFormat == CanvasTex::TextureFormat::R8g8b8a8Unorm);

    if (imageFormat == CanvasTex::TextureFormat::B8g8r8a8Unorm ||
        imageFormat == CanvasTex::TextureFormat::R8g8b8a8Unorm)
    {
        bool hasWhite = false;
        bool hasBlack = false;

        const uint8_t* imageDataCopy = imageData;

        for (size_t y = 0; y < imageHeight; y++)
        {
            for (size_t x = 0; x < imageWidth; x++, imageDataCopy += 4) // Increment pointer to next pixel
            {
                uint8_t alpha = imageDataCopy[3];

                if (alpha == 0)
                {
                    // Black alpha value
                    hasBlack = true;
                }
                else if (alpha == 255)
                {
                    // White alpha value
                    hasWhite = true;
                }
                else
                {
                    // Alpha value is neither white nor black - semi-transparent
                    return AlphaChannelType::GrayscaleVariance;
                }
            }
        }

        // We did not encounter any non-white/ non-black values
        if (hasBlack)
        {
            if (hasWhite)
            {
                return AlphaChannelType::Binary;
            }

            return AlphaChannelType::Transparent;
        }

        SpectreAssert(hasWhite);
        return AlphaChannelType::Opaque;
    }

    return AlphaChannelType::Unknown;
}

//---------------------------------------------------------------------------------------------------------------------

void ProcessAlphaFlagsForBGRAImage(
    void* imageData,
    size_t imageDataSize,
    void* imagePixels,
    uint32_t imageWidth,
    uint32_t imageHeight,
    uint32_t imageRowPitch,
    uint8_t& imageAlphaFlags
    )
{
    if ((imageData != nullptr) && (imageDataSize > 0) && (imagePixels != nullptr))
    {
        ImageFileContent imageFileContent = DetectImageFileAlphaType(imageData, static_cast<uint32_t>(imageDataSize));
        DetectImageAlpha(static_cast<uint8_t*>(imagePixels), imageWidth, imageHeight, imageRowPitch, CanvasTex::TextureFormat::B8g8r8a8Unorm, imageFileContent.alphaContent, imageAlphaFlags);
    }
}

//---------------------------------------------------------------------------------------------------------------------

void ProcessAlphaFlagsUsingAlphaChannelType(
    void* imageData,
    size_t imageDataSize,
    uint8_t& imageAlphaFlags,
    ImagingV2::ImagingComponent::AlphaChannelType alphaType)
{
    if ((imageData != nullptr) && (imageDataSize > 0))
    {
        ImageFileContent imageFileContent = DetectImageFileAlphaType(imageData, static_cast<uint32_t>(imageDataSize));
        DetectImageAlphaFromChannelType(alphaType, imageFileContent.alphaContent, imageAlphaFlags);
    }
}

//---------------------------------------------------------------------------------------------------------------------

// Rewrites alpha channel of image to match expected alpha channel type, e.g. Opaque, Mask
// If an unexpected value is encountered (e.g. grey value when expected type is Opaque),
// that value is rewritten to match expected type (e.g. 255 if Opaque)
bool RewriteAlphaChannel(
    uint8_t* imageData,
    const size_t imageWidth,
    const size_t imageHeight,
    const CanvasTex::TextureFormat imageFormat,
    const AlphaChannelType expectedAlphaType,
    const float alphaCutOff
)
{
    if (imageFormat != CanvasTex::TextureFormat::B8g8r8a8Unorm &&
        imageFormat != CanvasTex::TextureFormat::R8g8b8a8Unorm)
    {
        return false;
    }

    if (expectedAlphaType == AlphaChannelType::GrayscaleVariance)
    {
        // Return false because nothing was rewritten
        // Grayscale variance means any value is acceptable; no need to rewrite
        return false;
    }

    bool channelRewritten = false;
    for (size_t y = 0; y < imageHeight; y++)
    {
        for (size_t x = 0; x < imageWidth; x++, imageData += 4) // Increment pointer to next pixel
        {
            uint8_t newAlpha = GetCorrectedAlphaValue(imageData[3], expectedAlphaType, alphaCutOff);
            if (imageData[3] != newAlpha)
            {
                imageData[3] = newAlpha;
                channelRewritten = true;
            }
        }
    }

    return channelRewritten;
}

//---------------------------------------------------------------------------------------------------------------------
bool ConvertGrayscaleNormalMap(CanvasTex::Image& image, float scale)
{
    bool imageWasModified = false;
    if (IsImageGrayScale((uint32_t*)(image.GetPixels()), image.GetWidth(), image.GetHeight()))
    {
        // normal Heightmap detected! convert to a normal color map
        ConvertHeightMapToNormalMap(image, scale);
        imageWasModified = true;
    }
    return imageWasModified;
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

void EncodeBGRA(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    Framework::ImageReader reader,
    void* data,
    uint32_t sizeInBytes,
    Framework::ITextureWriter* writer,
    int textureCompression,
    uint32_t lod)
{
    ImagingV2::ImagingComponent::EncodeBGRA(
        textureName,
        texturePath,
        textureId,
        reader,
        data,
        sizeInBytes,
        writer,
        textureCompression,
        lod);
}

//---------------------------------------------------------------------------------------------------------------------

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
    const Framework::TextureProcessingOptions& options)
{
    ImagingV2::ImagingComponent::EncodeBGRAForAllLODsFromMemory(
        textureId,
        width,
        height,
        lineStride,
        format,
        flags,
        data,
        sizeInBytes,
        writers,
        options);
}

//---------------------------------------------------------------------------------------------------------------------

void ProcessLODs(
    const std::string& textureName,
    const std::string& texturePath,
    uint32_t textureId,
    void* data,
    uint32_t sizeInBytes,
    std::vector<Framework::ITextureWriter*>& writers,
    const Framework::TextureProcessingOptions& options)
{
    ImagingV2::ImagingComponent::EncodeBGRAForAllLODs(
        textureName,
        texturePath,
        textureId,
        data,
        sizeInBytes,
        writers,
        options);
}

}  // namespace ImagingComponent
}  // namespace ImagingV1
}  // namespace Spectre
