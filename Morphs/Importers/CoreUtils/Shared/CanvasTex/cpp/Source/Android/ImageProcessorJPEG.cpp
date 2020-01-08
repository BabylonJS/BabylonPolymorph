/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TextureLoaders.h"
#include "ImageProcessorJPEG.h"
#include <CoreUtils/SmartThrow.h>
extern "C" {
#include "turbojpeg.h"
}

namespace CanvasTex
{
    std::vector<uint8_t> ImageProcessorJPEG::decompressImage(const void* pSource, size_t inLength) const
    {
        tjhandle jpegDecompressor = tjInitDecompress();
        if (jpegDecompressor == nullptr)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::decompressImage - Cannot initiate tjInitDecompress");
        }

        // wrapping jpegDecompressor inside a smart pointer
        std::unique_ptr<void, std::function<void(tjhandle)>>
            jpegDecompressor_ptr_smart(jpegDecompressor, [](tjhandle jpegDecompressorPtr)
                                                         {
                                                             tjDestroy(jpegDecompressorPtr);
                                                         }
                                      );

        int jpegSubsamp = 0, width = 0, height = 0;
        unsigned char* compressedImage = reinterpret_cast<unsigned char*>(const_cast<void*>(pSource));
        int result = tjDecompressHeader2(jpegDecompressor, compressedImage, inLength, &width, &height, &jpegSubsamp);
        if (result != 0)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::decompressImage - Cannot read header info");
        }

        constexpr size_t channels = 4;
        unsigned long decompressedImageSize = width * height * channels;
        std::vector<unsigned char> decompressedImage(decompressedImageSize);
        result = tjDecompress2(jpegDecompressor, compressedImage, inLength, decompressedImage.data(), width, 0 /*pitch*/, height, TJPF_BGRA, TJFLAG_FASTDCT);

        if (result != 0)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::decompressImage - Cannot read jpeg data");
        }

        return decompressedImage;
    }

    std::vector<uint8_t> ImageProcessorJPEG::compressImage(const uint8_t* pSource, size_t width, size_t height) const
    {
        tjhandle jpegCompressor = tjInitCompress();
        if (jpegCompressor == nullptr)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::compressImage - Cannot initiate tjInitCompress");
        }

        // wrapping jpegCompressor inside a smart pointer
        std::unique_ptr<void, std::function<void(tjhandle)>>
            jpegCompressor_ptr_smart(jpegCompressor, [](tjhandle jpegCompressorPtr)
                                                     {
                                                         tjDestroy(jpegCompressorPtr);
                                                     }
                                    );

        // tjBufSize is used to pre-allocate memory with appropriate size
        unsigned long maxSizeOfCompressedImg = tjBufSize(width, height, TJSAMP_444);
        std::vector<uint8_t> compressedImage(maxSizeOfCompressedImg);
        auto compressedImagePtr = compressedImage.data();
        unsigned char* decompressedImage = reinterpret_cast<unsigned char*>(const_cast<uint8_t*>(pSource));
        const int JPEG_QUALITY = 100;
        unsigned long int jpegSize = 0;

        // TODO: VSO# 18115767 - Verify whether alpha channel is present or not before sending TJPF_RGBA as the type
        int result = tjCompress2(jpegCompressor, decompressedImage, width, 0 /*pitch*/, height, TJPF_RGBA,
                                &compressedImagePtr, &jpegSize, TJSAMP_444, JPEG_QUALITY, TJFLAG_FASTDCT | TJFLAG_NOREALLOC);

        if (result != 0)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::compressImage - Cannot compress to jpeg");
        }

        compressedImage.resize(jpegSize);
        compressedImage.shrink_to_fit();
        return compressedImage;
    }

    MetadataInfo ImageProcessorJPEG::getImageMetadata(const void* pSource, size_t inLength) const
    {
        tjhandle jpegGetMetadataHandle = tjInitDecompress();
        if (jpegGetMetadataHandle == nullptr)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::getImageMetadata - Cannot initiate tjInitDecompress");
        }

        // wrapping jpegGetMetadataHandle inside a smart pointer
        std::unique_ptr<void, std::function<void(tjhandle)>>
            jpegGetMetadataHandle_ptr_smart(jpegGetMetadataHandle, [](tjhandle jpegGetMetadataHandlePtr)
                                                     {
                                                         tjDestroy(jpegGetMetadataHandlePtr);
                                                     }
                                           );

        int jpegSubsamp = 0, width = 0, height = 0;
        unsigned char* compressedImage = reinterpret_cast<unsigned char*>(const_cast<void*>(pSource)); // compressedImage from above
        int result = tjDecompressHeader2(jpegGetMetadataHandle, compressedImage, inLength, &width, &height, &jpegSubsamp);

        if (result != 0)
        {
            throw Spectre::Utils::SpectreException("ImageProcessorJPEG::getImageMetadata - Cannot read header info");
        }

        MetadataInfo metadata;
        metadata.width = width;
        metadata.height = height;

        return metadata;
    }
} // End namespace CanvasTex