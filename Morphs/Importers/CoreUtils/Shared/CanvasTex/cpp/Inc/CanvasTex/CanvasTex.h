/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <Framework/TextureWriter.h>

#include <CanvasTex/Format.h>
#include <CanvasTex/TextureMetadata.h>
#include <CanvasTex/Image.h>
#include <CanvasTex/ScratchImage.h>

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

enum class LoadResult : uint32_t
{
    UnknownReaderType,
    NotSupportedType,
    LoadSuccessful,
    LoadFailed,
};

enum class OutputFormat
{
    Unknown = 0,
    Png,
    Png256,
    Jpeg,
    Bmp,
    DDS
};

enum class CompressionOptions
{
    None = 0x0,
    Bc7Use3Subsets = 0x1,
};

enum class FilterOptions : uint8_t
{
    Box,
    SeparateAlpha
};

//---------------------------------------------------------------------------------------------------------------------

bool IsCompressed(TextureFormat format);

bool IsTgaFile(
    const void* pSource,
    size_t size);

bool GetMetadataFromMemory(
    const void* pSource,
    size_t size,
    Spectre::Framework::ImageReader reader,
    TextureMetadata& metadata);

LoadResult LoadFromMemory(
    const void* pSource,
    size_t size,
    Spectre::Framework::ImageReader reader,
    TextureMetadata* metadata,
    ScratchImage& image);

void SaveToMemory(
    const ConstImage& image,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::function<void(size_t, void*)>& postSaveCallback);

void SaveToMemory(
    const ScratchImage& srcImages,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::function<void(size_t, void*)>& postSaveCallback);

void SaveToFile(
    const ConstImage& image,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::wstring& fileName);

void Resize(
    const ConstImage& srcImage,
    size_t width,
    size_t height,
    ScratchImage& image);

void Convert(
    const ConstImage& srcImage,
    TextureFormat format,
    ScratchImage& image);

void Decompress(
    const ConstImage& cImage,
    TextureFormat format,
    ScratchImage& image);

void Compress(
    const ConstImage& srcImage,
    TextureFormat format,
    CompressionOptions compressionOptions,
    bool useGpu,
    ScratchImage& cImage);

void Compress(
    const ScratchImage& srcImages,
    TextureFormat format,
    ScratchImage& outImages,
    bool useGpu = true
);

void GenerateMipMaps(
    const ConstImage& baseImage,
    ScratchImage& mipChain,
    FilterOptions filterOptions = FilterOptions::Box);

}  // namespace CanvasTex
