/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include "ScratchImage.h"

#include <CanvasTex/Format.h>
#include <CanvasTex/ScratchImage.h>

#include <DirectXTex.h>

#include "Image.h"
#include "TextureMetadata.h"

namespace CanvasTex
{
    ScratchImage::ScratchImage()
        : m_impl{ std::make_shared<ScratchImageImplementation>() }
    {
    }

    ScratchImage::~ScratchImage() = default;

    ScratchImage::ScratchImage(ScratchImage&& other) = default;

    ScratchImage& ScratchImage::operator=(ScratchImage&& other) = default;

    void ScratchImage::InitializeFromImage(const Image& srcImage)
    {
        Spectre::Utils::ThrowIfFailed(m_impl->InitializeFromImage(srcImage.CGetImplementation()));
    }

    void ScratchImage::Release()
    {
        m_impl->Release();
    }

    ConstTextureMetadata ScratchImage::GetMetadata() const
    {
        auto metaImplementation = static_cast<const ConstTextureMetadata::TextureMetadataImplementation*>(&m_impl->GetMetadata());
        return ConstTextureMetadata(std::shared_ptr<const TextureMetadataBase::TextureMetadataImplementation>(m_impl, metaImplementation));
    }

    ConstImage ScratchImage::GetImage(size_t item, size_t mip) const
    {
        auto imageImplementation = static_cast<const ConstImage::ImageImplementation*>(m_impl->GetImage(mip, item, 0));
        return ConstImage(std::shared_ptr<const ImageBase::ImageImplementation>(m_impl, imageImplementation));
    }

    size_t ScratchImage::GetImageCount() const
    {
        return m_impl->GetImageCount();
    }

    const uint8_t* ScratchImage::GetPixels() const
    {
        return m_impl->GetPixels();
    }

    uint8_t* ScratchImage::GetPixels()
    {
        return m_impl->GetPixels();
    }

    size_t ScratchImage::GetPixelsSize() const
    {
        return m_impl->GetPixelsSize();
    }

    ScratchImage::ScratchImageImplementation& ScratchImage::GetImplementation()
    {
        return *m_impl;
    }

    const ScratchImage::ScratchImageImplementation& ScratchImage::CGetImplementation() const
    {
        return *m_impl;
    }

}  // namespace CanvasTex
