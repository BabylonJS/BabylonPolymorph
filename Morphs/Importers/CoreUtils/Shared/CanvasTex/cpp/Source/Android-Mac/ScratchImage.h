//
//  ScratchImage.h
//  CanvasTex.macOS.CPP
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#pragma once

#include <CanvasTex/ScratchImage.h>
#include "TextureLoaders.h"
#include "TextureConversion.h"
#include "ImageMac.h"
#include "GliIncludes.h"
#include <gli/make_texture.hpp>

namespace CanvasTex
{

class ScratchImage::ScratchImageImplementation
{
public:
    const uint8_t* GetPixels() const
    {
        return static_cast<const uint8_t*>(m_texture.data());
    }

    uint8_t* GetPixels()
    {
        return static_cast<uint8_t*>(m_texture.data());
    }

    void SetImage(const gli::texture& texture)
    {
        m_texture = texture;

        m_metadata.width = GetWidth();
        m_metadata.height = GetHeight();
        m_metadata.rowPitch = GetRowPitch();
        m_metadata.slicePitch = GetSlicePitch();
        m_metadata.depth = 1;
        m_metadata.arraySize = texture.faces();
        m_metadata.format = GetCanvasTextureFormat(texture.format());
        m_metadata.mipLevels = texture.levels();
    }

    TextureMetadataBase::TextureMetadataImplementation const& GetMetadata() const
    {
        return m_metadata;
    }

    size_t GetWidth() const { return m_texture.extent().x; }
    size_t GetHeight() const { return m_texture.extent().y; }
    size_t GetRowPitch() const { return GetWidth() * gli::detail::bits_per_pixel(m_texture.format()) / 8; }
    size_t GetSlicePitch() const { return GetRowPitch() * GetHeight(); }
    size_t GetPixelsSize() const { return m_texture.size(); }
    TextureFormat GetFormat() const { return GetCanvasTextureFormat(m_texture.format()); }

    void InitializeFromImage(const ImageBase::ImageImplementation& imgImpl)
    {
        auto gliFormat = GetGliTextureFormat(imgImpl.format);
        if (gliFormat == gli::FORMAT_UNDEFINED)
        {
            throw Spectre::Utils::SpectreException(std::string("ScratchImage::InitializeFromImage - Invalid texture format") + std::to_string(std::underlying_type_t<TextureFormat>(imgImpl.format)));
        }

        // TODO: Detect whether to make a texture2d, texture1d, or texture3d.
        // Also determine the correct value for the Levels argument when we have mipmaps working.
        auto texture = gli::make_texture2d(gliFormat, gli::extent2d(imgImpl.width, imgImpl.height), 1);
        memcpy(texture.data(), imgImpl.pixels, texture.size());

        SetImage(texture);
    }

    gli::texture m_texture;
    TextureMetadataBase::TextureMetadataImplementation m_metadata;
};

} // namespace CanvasTex
