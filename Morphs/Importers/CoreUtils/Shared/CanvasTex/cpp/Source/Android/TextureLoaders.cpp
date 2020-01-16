/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TextureLoaders.h"
#include "TextureConversion.h"
#include "IImageProcessor.h"
#include "ImageProcessorFactory.h"
#include "GliIncludes.h"
#include <fstream>
#include <cstring>
#include <CoreUtils/Trace.h>
#include "CImg.h"

DEFINE_TRACE_AREA(CanvasTex, 0);

namespace CanvasTex
{
    gli::texture loadImage(const void* pSource, size_t inLength)
    {
        if (IsDDS(pSource))
        {
            // super special-case DDS loading.
            return LoadDDS(pSource, inLength);
        }

        // ImageType is passed as unknown and has to be derived from pSource
        auto imageProcessorPtr = ImageProcessorFactory::createImageProcessor(pSource);
        if (imageProcessorPtr != nullptr)
        {
            MetadataInfo metadataInfo = imageProcessorPtr->getImageMetadata(pSource, inLength);
            auto width = metadataInfo.width;
            auto height = metadataInfo.height;

            constexpr size_t channels = 4;
            constexpr size_t bytesPerPixel = 4;

            gli::texture2d texture(gli::FORMAT_BGRA8_UNORM_PACK8, gli::extent2d(width, height), 1 /* Levels */);

            auto decompressedImg = imageProcessorPtr->decompressImage(pSource, inLength);

            // swap R and B channels so it becomes BGRA instead of RGBA
            uint8_t* offsetInPixels = static_cast<uint8_t*>(texture.data());
            size_t numOfPixels = height * width * channels / bytesPerPixel;
            for (size_t y = 0; y < numOfPixels; ++y)
            {
                offsetInPixels[0] = decompressedImg.at(y * bytesPerPixel + 2); // Blue
                offsetInPixels[1] = decompressedImg.at(y * bytesPerPixel + 1); // Green
                offsetInPixels[2] = decompressedImg.at(y * bytesPerPixel + 0); // Red
                offsetInPixels[3] = decompressedImg.at(y * bytesPerPixel + 3); // Alpha

                offsetInPixels = offsetInPixels + 4;
            }

            return texture;
        }

        return gli::texture();
    }

    bool imageGetMetadata(const void* pSource, size_t inLength, TextureMetadata& metadata)
    {
        // ImageType is passed as unknown and has to be derived from pSource
        auto imageProcessorPtr = ImageProcessorFactory::createImageProcessor(pSource);
        if (imageProcessorPtr != nullptr)
        {
            MetadataInfo metadataInfo = imageProcessorPtr->getImageMetadata(pSource, inLength);
            metadata.SetWidth(metadataInfo.width);
            metadata.SetHeight(metadataInfo.height);
            return true;
        }

        return false;
    }

    gli::texture imageConvert(const uint8_t* pSource, size_t width, size_t height, TextureFormat format)
    {
        throw Babylon::Utils::BabylonException("ImageConvert is not implemented");
    }

    bool saveImageToMemory(const uint8_t* pSource, OutputFormat outputFormat,
                          size_t width, size_t height, TextureFormat format, std::vector<uint8_t> &imageData)
    {
        auto imageProcessorPtr = ImageProcessorFactory::createImageProcessor(outputFormat);
        if (imageProcessorPtr != nullptr)
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
                TRACE_INFO(CanvasTex, "MakePixelFormatDescFromTextureFormat threw unexpected exception. Error: %s", e.what());
                return false;
            }

            const size_t bytesPerPixel = 4;
            std::unique_ptr<uint8_t[]> pixels = Convert32(pSource, width, height, bytesPerPixel * width, inputDesc, nativeDesc);
            try
            {
                imageData = imageProcessorPtr->compressImage(pixels.get(), width, height);
                return true;
            }
            catch (const std::runtime_error& e)
            {
                TRACE_INFO(CanvasTex, "Could not read the pSource. Error: %s", e.what());
                return false;
            }
        }

        return false;
    }

    bool saveImageToFile(const uint8_t* pSource, OutputFormat outputFormat,
                        size_t width, size_t height, TextureFormat format, const std::string& fileName)
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

    gli::texture resizeImage(const void* pSource, size_t srcWidth, size_t srcHeight,
                            TextureFormat srcFormat, size_t targetWidth, size_t targetHeight)
    {

        TextureFormat nativeFormat = TextureFormat::R8g8b8a8Unorm;
        CanvasPixelFormatDesc32 nativeDesc;
        CanvasPixelFormatDesc32 inputDesc;
        try
        {
            MakePixelFormatDescFromTextureFormat(nativeDesc, nativeFormat);
            MakePixelFormatDescFromTextureFormat(inputDesc, srcFormat);
        }
        catch (const std::runtime_error& e)
        {
            TRACE_INFO(CanvasTex, "MakePixelFormatDescFromTextureFormat threw unexpected exception. Error: %s", e.what());
            return gli::texture();
        }

        constexpr size_t bytesPerPixel = 4;
        std::unique_ptr<uint8_t[]> pixels = Convert32(reinterpret_cast<const uint8_t*>(pSource), srcWidth, srcHeight,
                                                      bytesPerPixel * srcWidth, inputDesc, nativeDesc);

        constexpr size_t channels = 4;
        // CImg Input pixels should be in RRGGBBAA order(non-interleaved)
        std::vector<uint8_t> non_interleaved;
        non_interleaved.reserve(srcWidth * srcHeight * channels);

        int noOfPixels = srcWidth * srcHeight;
        // converting from RGBARGBA to RRGGBBAA
        for (int i = 0, j = 0; i < noOfPixels * 4; i = i + 4, j++)
        {
            non_interleaved[j] = *(pixels.get() + i);
            non_interleaved[j + noOfPixels] = *(pixels.get() + i + 1);
            non_interleaved[j + 2 * noOfPixels] = *(pixels.get() + i + 2);
            non_interleaved[j + 3 * noOfPixels] = *(pixels.get() + i + 3);
        }

        cimg_library::CImg<uint8_t> image = cimg_library::CImg<uint8_t>(non_interleaved.data(), srcWidth, srcHeight, 1 /* depth */, 4 /* channels */);
        constexpr int interplolationType = 6; // Lanczos interpolation

        try
        {
            image.resize(targetWidth, targetHeight, 1 /* depth */, channels, interplolationType);

            gli::texture2d texture(gli::FORMAT_BGRA8_UNORM_PACK8, gli::extent2d(targetWidth, targetHeight), 1 /* Levels */);

            // resize image returns pixels in non-interleaved and hence should be interleaved
            uint8_t* interleavedImgPixelsPtr = static_cast<uint8_t*>(texture.data());

            unsigned char* imagePtr = image.data();
            unsigned long targetSizePerChannel = targetWidth * targetHeight;
            // for each channel, convert each pixel
            for (size_t channel = 0; channel < 4; channel++)
            {
                for (unsigned long offsetInPixels = 0; offsetInPixels < targetSizePerChannel; offsetInPixels++)
                {
                    *(interleavedImgPixelsPtr + offsetInPixels * 4 + channel) = *(imagePtr + channel * targetSizePerChannel + offsetInPixels);
                }
            }
            return texture;
        }
        catch (const std::exception& e)
        {
            TRACE_INFO(CanvasTex, "Could not resize Image to desired dimensions. Error: %s", e.what());
            return gli::texture();
        }
    }
}