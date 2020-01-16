#include <CoreUtils/SmartThrow.h>
#include <Foundation/Foundation.h>
#include <ImageIO/ImageIO.h>
#include <CoreUtils/Platform.h>
#include <Accelerate/Accelerate.h>

#if CANVAS_PLATFORM_IS_IOS()
#include <MobileCoreServices/MobileCoreServices.h>
#endif

#include "GliIncludes.h"
#include "TextureLoaders.h"
#include "TextureConversion.h"
#include <string>
#include <fstream>
#include <iostream>
#include <CoreUtils/Trace.h>

DEFINE_TRACE_AREA(CanvasTex, 0);

namespace CanvasTex
{
    namespace
    {
        using CFMutableDataPtr = std::unique_ptr<__CFData, decltype(CFRelease)*>;

        using CGDataProviderPtr = std::unique_ptr<CGDataProvider, decltype(CGDataProviderRelease)*>;
        using CGImageSourcePtr = std::unique_ptr<CGImageSource, decltype(CFRelease)*>;
        using CGImageDestinationPtr = std::unique_ptr<CGImageDestination, decltype(CFRelease)*>;
        using CGImagePtr = std::unique_ptr<CGImage, decltype(CGImageRelease)*>;
        using CGColorSpacePtr = std::unique_ptr<CGColorSpace, decltype(CGColorSpaceRelease)*>;

        using vImageConverterPtr = std::unique_ptr<vImageConverter, decltype(vImageConverter_Release)*>;

        struct vImageBufferDataDeleter
        {
            void operator()(void* data)
            {
                free(data);
            }
        };
        using vImageBufferDataGuard = std::unique_ptr<void, vImageBufferDataDeleter>;

        CFStringRef TextureFormatToUtiFormat(OutputFormat format)
        {
            switch (format)
            {
                case OutputFormat::Jpeg:
                    return kUTTypeJPEG;
                case OutputFormat::Png:
                    return kUTTypePNG;
                default:
                    throw std::runtime_error("CGImageSaveImageToMemory has an unsupported format");
            }
        }

        const vImage_CGImageFormat& GetCGImageRGBA8888Format()
        {
            static CGColorSpacePtr s_rgba8888ColorSpace(nullptr, &CGColorSpaceRelease);
            static vImage_CGImageFormat s_rgba8888Format;
            static std::once_flag s_flag;

            std::call_once(s_flag, []()
                           {
                               const size_t targetBytesPerPixel = 4;
                               const size_t targetBitsPerComponent = 8;
                               const size_t targetBitsPerPixel = targetBytesPerPixel * targetBitsPerComponent;

                               s_rgba8888ColorSpace = CGColorSpacePtr(CGColorSpaceCreateDeviceRGB(),
                                                                      &CGColorSpaceRelease);

                               s_rgba8888Format =
                               {
                                   (uint32_t)targetBitsPerComponent,              // bitsPerComponent
                                   (uint32_t)targetBitsPerPixel,                  // bitsPerPixel
                                   s_rgba8888ColorSpace.get(),                        // colorSpace
                                   kCGImageAlphaLast | kCGBitmapByteOrder32Big,   // bitmapInfo
                                   0,                                             // version
                                   NULL,                                          // decode
                                   kCGRenderingIntentDefault                      // renderingIntent
                               };

                           });

            return s_rgba8888Format;
        }

        vImage_CGImageFormat CGImageFormatFromCGImage(CGImageRef image)
        {
            vImage_CGImageFormat format =
            {
                (uint32_t)CGImageGetBitsPerComponent(image),  // bitsPerComponent
                (uint32_t)CGImageGetBitsPerPixel(image),      // bitsPerPixel
                CGImageGetColorSpace(image),                  // colorSpace
                CGImageGetBitmapInfo(image),                  // bitmapInfo
                0,                                            // version
                CGImageGetDecode(image),                      // decode
                kCGRenderingIntentDefault                     // renderingIntent
            };

            return format;
        }

        vImage_Buffer vImageBufferFromGliTexture(gli::texture2d& texture)
        {
            gli::texture2d::extent_type extents = texture.extent();

            vImage_Buffer buffer =
            {
                texture.data(),                // data
                (vImagePixelCount)extents[1],  // height
                (vImagePixelCount)extents[0],  // width
                texture.size() / extents[1]    // rowBytes
            };

            return buffer;
        }
    }

    gli::texture loadImage(void const* pSource, size_t inLength)
    {
        if (IsDDS(pSource))
        {
            // super special-case DDS loading.
            return LoadDDS(pSource, inLength);
        }

        CGDataProviderPtr dataProvider(CGDataProviderCreateWithData(NULL, pSource, inLength, NULL),
                                       &CGDataProviderRelease);
        if(!dataProvider)
        {
            return gli::texture();
        }

        CGImageSourcePtr imageSource(CGImageSourceCreateWithDataProvider(dataProvider.get(), NULL),
                                     &CFRelease);
        if (!imageSource)
        {
            return gli::texture();
        }

        CGImagePtr image(CGImageSourceCreateImageAtIndex(imageSource.get(), 0, NULL),
                         &CGImageRelease);
        if (!image)
        {
            return gli::texture();
        }

        size_t width = CGImageGetWidth(image.get());
        size_t height = CGImageGetHeight(image.get());

        vImage_CGImageFormat inputFormat = CGImageFormatFromCGImage(image.get());
        vImage_CGImageFormat rgba8888Format = GetCGImageRGBA8888Format();

        vImage_Error error;
        vImageConverterPtr converter(vImageConverter_CreateWithCGImageFormat(&inputFormat, &rgba8888Format, NULL, kvImageNoFlags, &error),
                                     &vImageConverter_Release);
        if(error != kvImageNoError)
        {
            return gli::texture();
        }

        vImage_Buffer sourceBuffer;
        error = vImageBuffer_InitWithCGImage(&sourceBuffer, &inputFormat, NULL, image.get(), kvImageNoFlags);
        vImageBufferDataGuard sourceBufferDataPtr(sourceBuffer.data);

        if(error != kvImageNoError)
        {
            return gli::texture();
        }

        size_t rgba8888BytesPerPixel = rgba8888Format.bitsPerPixel / 8;
        std::unique_ptr<uint8_t[]> rgba8888pixels = std::make_unique<uint8_t[]>(height * width * rgba8888BytesPerPixel);
        vImage_Buffer rgba8888Buffer =
        {
            rgba8888pixels.get(),          // data
            (vImagePixelCount)height,      // height
            (vImagePixelCount)width,       // width
            width * rgba8888BytesPerPixel  // rowBytes
        };

        error = vImageConvert_AnyToAny(converter.get(), &sourceBuffer, &rgba8888Buffer, NULL, kvImageNoFlags);

        if(error != kvImageNoError)
        {
            return gli::texture();
        }

        gli::texture2d texture(gli::FORMAT_BGRA8_UNORM_PACK8, gli::extent2d(width, height), 1);
        vImage_Buffer textureBuffer = vImageBufferFromGliTexture(texture);

        uint8_t permutation[] = {2, 1, 0, 3};
        error = vImagePermuteChannels_ARGB8888(&rgba8888Buffer, &textureBuffer, permutation, kvImageNoFlags);

        if(error != kvImageNoError)
        {
            return gli::texture();
        }

        return texture;
    }

    bool imageGetMetadata(void const* pSource, size_t inLength, TextureMetadata& metadata)
    {
        NSData* data = [NSData dataWithBytes:pSource length:inLength];
        CGImageSourcePtr imageSource(CGImageSourceCreateWithData((CFDataRef)data, NULL),
                                     &CFRelease);
        if (!imageSource)
        {
            return false;
        }

        CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource.get(), 0, NULL);
        if (imageProperties == NULL)
        {
            return false;
        }

        CFNumberRef imageWidth = (CFNumberRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyPixelWidth);
        CFNumberRef imageHeight = (CFNumberRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyPixelHeight);
        CFRelease(imageProperties);

        int w = 0;
        int h = 0;

        CFNumberGetValue(imageWidth, kCFNumberIntType, &w);
        CFNumberGetValue(imageHeight, kCFNumberIntType, &h);

        metadata.SetWidth(w);
        metadata.SetHeight(h);

        return true;
    }

    gli::texture imageConvert(const uint8_t* pSource, size_t width, size_t height, TextureFormat format)
    {
        //@TODO: We will need to convert the individual pixels to the target format
        // Hint: Use Accelerate Framework and the vImage functions
        throw Spectre::Utils::SpectreException("CGImageConvert is not implemented");
    }

    CGImageRef ConvertImageDataToImageRef(const void* pSource, size_t width, size_t height)
    {
        size_t bytesPerPixel = 4;
        size_t bitsPerComponent = 8;
        size_t bitsPerPixel = bitsPerComponent * bytesPerPixel;
        size_t bytesPerRow = bytesPerPixel * width;
        size_t bytesPerImage = bytesPerRow * height;

        CGDataProviderPtr dataProvider(CGDataProviderCreateWithData(NULL, pSource, bytesPerImage, NULL),
                                       &CGDataProviderRelease);
        if(!dataProvider)
        {
            return NULL;
        }

        CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
        return CGImageCreate(width,
                             height,
                             bitsPerComponent,
                             bitsPerPixel,
                             bytesPerRow,
                             colorSpace,
                             kCGImageAlphaLast | kCGBitmapByteOrder32Big,
                             dataProvider.get(),
                             NULL,
                             false,
                             kCGRenderingIntentDefault);
    }

    bool saveImageToMemory(const uint8_t* pSource, OutputFormat outputFormat, size_t width, size_t height, TextureFormat format, std::vector<uint8_t> &imageData)
    {
        TextureFormat nativeFormat = TextureFormat::R8g8b8a8Unorm;
        CanvasPixelFormatDesc32 nativeDesc;
        CanvasPixelFormatDesc32 inputDesc;
        try
        {
            MakePixelFormatDescFromTextureFormat(nativeDesc, nativeFormat);
            MakePixelFormatDescFromTextureFormat(inputDesc, format);
        }
        catch (const std::runtime_error& e)
        {
            // unsupported format
            TRACE_INFO(CanvasTex, "MakePixelFormatDescFromTextureFormat threw unexpected exception. Error: %s", e.what());
            return false;
        }

        const size_t bytesPerPixel = 4;
        std::unique_ptr<uint8_t[]> pixels = Convert32(pSource, width, height, bytesPerPixel * width, inputDesc, nativeDesc);

        CGImagePtr image(ConvertImageDataToImageRef(pixels.get(), width, height),
                         &CGImageRelease);
        if (!image)
        {
            return false;
        }

        CFMutableDataPtr destinationData(CFDataCreateMutable(kCFAllocatorDefault, 0),
                                         &CFRelease);

        CGImageDestinationPtr destination(CGImageDestinationCreateWithData(destinationData.get(), TextureFormatToUtiFormat(outputFormat), 1, NULL),
                                          &CFRelease);
        CGImageDestinationAddImage(destination.get(), image.get(), 0);
        CGImageDestinationFinalize(destination.get());

        size_t size = CFDataGetLength(destinationData.get());
        const void* bytes = CFDataGetMutableBytePtr(destinationData.get());

        imageData.resize(size);
        memcpy(imageData.data(), bytes, size);

        return true;
    }

    bool saveImageToFile(const uint8_t* pSource, OutputFormat outputFormat, size_t width, size_t height, TextureFormat format, const std::string& fileName)
    {
        std::vector<uint8_t> imageData;
        if (saveImageToMemory(pSource, outputFormat, width, height, format, imageData))
        {
            std::ofstream stream(fileName, std::ios::binary | std::ios::out);
            stream.write(reinterpret_cast<const char*>(imageData.data()), imageData.size());
            stream.close();
            return true;
        }

        return false;
    }

    // @todo use srcFormat to behave differently depending on source image's pixel format
    gli::texture resizeImage(void const* pSource, size_t srcWidth, size_t srcHeight, TextureFormat srcFormat, size_t targetWidth, size_t targetHeight)
    {
        CGImagePtr image(ConvertImageDataToImageRef(pSource, srcWidth, srcHeight),
                         &CGImageRelease);
        if (!image)
        {
            return gli::texture();
        }

        vImage_CGImageFormat format = CGImageFormatFromCGImage(image.get());

        vImage_Buffer sourceBuffer;
        vImage_Error error = vImageBuffer_InitWithCGImage(&sourceBuffer, &format, NULL, image.get(), kvImageNoFlags);
        vImageBufferDataGuard sourceBufferDataPtr(sourceBuffer.data);

        if(error != kvImageNoError)
        {
            return gli::texture();
        }

        gli::texture2d texture(gli::FORMAT_BGRA8_UNORM_PACK8, gli::extent2d(targetWidth, targetHeight), 1);
        vImage_Buffer textureBuffer = vImageBufferFromGliTexture(texture);

        error = vImageScale_ARGB8888(&sourceBuffer, &textureBuffer, NULL, kvImageHighQualityResampling);
        if(error != kvImageNoError)
        {
            return gli::texture();
        }

        return texture;
    }

} // namespace CanvasTex