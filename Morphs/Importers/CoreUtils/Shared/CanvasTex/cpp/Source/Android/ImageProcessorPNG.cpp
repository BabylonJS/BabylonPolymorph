/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "TextureLoaders.h"
#include "ImageProcessorPNG.h"
#include <CoreUtils/SmartThrow.h>
#include "png.h"

namespace
{
    typedef struct
    {
        png_bytep bufferPtr;
        png_uint_32 bufferSize;
        png_uint_32 currentPos;
    } MEMORY_READ_STATE;

    typedef struct
    {
        std::vector<png_byte> buffer;
    } MEMORY_WRITE_STATE;

    void readFromInputStream(png_structrp png_ptr, png_bytep data, png_size_t length)
    {
        MEMORY_READ_STATE* readSrc = static_cast<MEMORY_READ_STATE*>(png_get_io_ptr(png_ptr));
        if (length > (readSrc->bufferSize - readSrc->currentPos))
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG readFromInputStream failed");
        }
        memcpy(data, readSrc->bufferPtr + readSrc->currentPos, length);
        readSrc->currentPos += length;
    }

    void writeToOutputStream(png_structp png_ptr, png_bytep data, png_size_t length)
    {
        MEMORY_WRITE_STATE* writeDest = static_cast<MEMORY_WRITE_STATE*>(png_get_io_ptr(png_ptr));
        writeDest->buffer.insert(writeDest->buffer.end(), data, data + length);
    }
}

namespace CanvasTex
{
    std::vector<uint8_t> ImageProcessorPNG::decompressImage(const void* pSource, size_t inLength) const
    {
        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL /* error_ptr */, NULL /* error_fn */, NULL /* warn_fn */);
        if (png_ptr == nullptr)
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::decompressImage - Create png_struct failed");
        }
        // wrapping png_ptr inside a smart pointer
        std::unique_ptr<png_struct, std::function<void(png_structp)>>
            png_smart_ptr(png_ptr, [](png_structp pngptr)
                                   {
                                       png_destroy_read_struct(&pngptr, NULL, NULL);
                                   }
                         );

        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (info_ptr == nullptr)
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::decompressImage - Create png_info struct failed");
        }
        // wrapping info_ptr inside a smart pointer
        std::unique_ptr<png_info, std::function<void(png_infop)>>
            info_ptr_smart(info_ptr, [&png_ptr](png_infop infoptr)
                                     {
                                         png_destroy_info_struct(png_ptr, &infoptr);
                                     }
                          );

        if (setjmp(png_jmpbuf(png_ptr)))
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::decompressImage - Error during Init I/O");
        }

        MEMORY_READ_STATE memory_read_state;
        memory_read_state.bufferPtr = reinterpret_cast<png_bytep>(const_cast<void*>(pSource));
        memory_read_state.bufferSize = inLength;
        memory_read_state.currentPos = 0;

        png_set_read_fn(png_ptr, &memory_read_state, readFromInputStream);

        // reads the header
        png_read_info(png_ptr, info_ptr);

        auto width = png_get_image_width(png_ptr, info_ptr);
        auto height = png_get_image_height(png_ptr, info_ptr);
        constexpr size_t bytesPerPixel = 4;

        png_uint_32 bitDepth = png_get_bit_depth(png_ptr, info_ptr);
        png_uint_32 channels = png_get_channels(png_ptr, info_ptr);
        png_uint_32 colorType = png_get_color_type(png_ptr, info_ptr);

        // paletted images are expanded to RGB
        if (colorType == PNG_COLOR_TYPE_PALETTE)
        {
            png_set_palette_to_rgb(png_ptr);
        }

        // grayscale images of less than 8 are converted to 8 bits
        if (colorType == PNG_COLOR_TYPE_GRAY && bitDepth < 8)
        {
            png_set_expand_gray_1_2_4_to_8(png_ptr);
        }

        // grayscale image to 24 bits RGB
        if (colorType == PNG_COLOR_TYPE_GRAY ||
            colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
        {
            png_set_gray_to_rgb(png_ptr);
        }

        // Appends alpha channel after RGB - converts to 32 bits
        if (colorType == PNG_COLOR_TYPE_RGB || colorType == PNG_COLOR_TYPE_GRAY ||
            colorType == PNG_COLOR_TYPE_PALETTE)
        {
            png_set_add_alpha(png_ptr, static_cast<png_uint_32>(0xff), PNG_FILLER_AFTER);
            channels = 4;
        }

        if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
        {
            png_set_tRNS_to_alpha(png_ptr);
        }

        // We dont support 16 bit precision. So if the image has 16 bits - round it to 8
        if (bitDepth == 16)
        {
            png_set_strip_16(png_ptr);
        }

        png_set_interlace_handling(png_ptr);
        png_read_update_info(png_ptr, info_ptr);

        std::vector<png_bytep> row_pointers(height * sizeof(png_bytep));

        std::vector<uint8_t> png_data(width * height * channels);

        for (size_t i = 0; i < height; i++)
            row_pointers[i] = png_data.data() + i * width * bytesPerPixel;

        // reads the entire image
        png_read_image(png_ptr, row_pointers.data());

        return png_data;
    }

    std::vector<uint8_t> ImageProcessorPNG::compressImage(const uint8_t* pSource, size_t width, size_t height) const
    {
        // TODO: VSO# 18115767 - Verify whether alpha channel is present or not
        constexpr size_t channels = 4;
        constexpr size_t bitsPerComponent = 8;
        constexpr size_t bitDepth = 8;

        png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL /* error_ptr */, NULL /* error_fn */, NULL /* warn_fn */);
        if (png_ptr == nullptr)
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::compressImage - Create png write struct failed");
        }
        // wrapping png_ptr inside a smart pointer
        std::unique_ptr<png_struct, std::function<void(png_structp)>>
            png_smart_ptr(png_ptr, [](png_structp pngptr)
                                   {
                                       png_destroy_write_struct(&pngptr, NULL);
                                   }
                         );

        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (info_ptr == nullptr)
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::compressImage - Create png info_ptr struct failed");
        }
        // wrapping info_ptr inside a smart pointer
        std::unique_ptr<png_info, std::function<void(png_infop)>>
            info_ptr_smart(info_ptr, [&png_ptr](png_infop infoptr)
                                     {
                                         png_destroy_info_struct(png_ptr, &infoptr);
                                     }
                          );

        if (setjmp(png_jmpbuf(png_ptr)))
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::compressImage - Error during Init I/O");
        }
        png_set_IHDR(png_ptr, info_ptr, width, height, bitDepth,
            PNG_COLOR_TYPE_RGBA,
            PNG_INTERLACE_NONE,
            PNG_COMPRESSION_TYPE_DEFAULT,
            PNG_FILTER_TYPE_DEFAULT);

        std::vector<uint8_t*> rows(height);
        for (size_t y = 0; y < height; ++y)
            rows[y] = const_cast<uint8_t*>(pSource) + y * width * 4;
        png_set_rows(png_ptr, info_ptr, &rows[0]);

        MEMORY_WRITE_STATE memory_write_state;
        unsigned long maxbufferSize = height * width * bitDepth * channels / bitsPerComponent;
        memory_write_state.buffer.reserve(maxbufferSize);
        png_set_write_fn(png_ptr, &memory_write_state, writeToOutputStream, NULL);
        png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

        return memory_write_state.buffer;
    }

    MetadataInfo ImageProcessorPNG::getImageMetadata(const void* pSource, size_t inLength) const
    {
        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL /* error_ptr */, NULL /* error_fn */, NULL /* warn_fn */);
        if (png_ptr == nullptr)
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::getImageMetadata - Create png_struct failed");
        }
        // wrapping png_ptr inside a smart pointer
        std::unique_ptr<png_struct, std::function< void(png_structp)>>
            png_smart_ptr(png_ptr, [](png_structp pngptr)
                                   {
                                        png_destroy_read_struct(&pngptr, NULL, NULL);
                                   }
                          );

        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (info_ptr == nullptr)
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::getImageMetadata - Create png_info struct failed");
        }
        // wrapping info_ptr inside a smart pointer
        std::unique_ptr<png_info, std::function<void(png_infop)>>
            info_ptr_smart(info_ptr, [&png_ptr](png_infop infoptr)
                                     {
                                         png_destroy_info_struct(png_ptr, &infoptr);
                                     }
                          );

        if (setjmp(png_jmpbuf(png_ptr)))
        {
            throw Spectre::Utils::SpectreFailException("ImageProcessorPNG::getImageMetadata - Error during Init I/O");
        }

        MEMORY_READ_STATE memory_read_state;
        memory_read_state.bufferPtr = reinterpret_cast<png_bytep>(const_cast<void*>(pSource));
        memory_read_state.bufferSize = inLength;
        memory_read_state.currentPos = 0;

        png_set_read_fn(png_ptr, &memory_read_state, readFromInputStream);

        // reads the header
        png_read_info(png_ptr, info_ptr);

        MetadataInfo metadata;
        metadata.width = png_get_image_width(png_ptr, info_ptr);
        metadata.height = png_get_image_height(png_ptr, info_ptr);

        return metadata;
    }
} // End namespace CanvasTex