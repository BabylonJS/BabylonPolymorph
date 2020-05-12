/********************************************************
 *                                                      *
 *   Copyright (C) Microsoft. All rights reserved.      *
 *                                                      *
 ********************************************************/

#include "CanvasTexPch.h"

#include "Image.h"

#include <CanvasTex/Format.h>
#include <CanvasTex/Image.h>

#include <DirectXTex.h>

#include "FormatConversion.h"

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

ConstImage::ConstImage() : m_impl(std::make_shared<const ImageImplementation>())
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstImage::~ConstImage() = default;

//---------------------------------------------------------------------------------------------------------------------

ConstImage::ConstImage(const ConstImage& other) : m_impl(std::make_shared<const ImageImplementation>(*other.m_impl))
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstImage::ConstImage(const std::shared_ptr<const ImageImplementation>& impl) : m_impl(impl)
{
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstImage::GetWidth() const
{
    return m_impl->width;
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstImage::GetHeight() const
{
    return m_impl->height;
}

//---------------------------------------------------------------------------------------------------------------------

TextureFormat ConstImage::GetFormat() const
{
    return Internal::DxgiFormatToTextureFormat(m_impl->format);
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstImage::GetRowPitch() const
{
    return m_impl->rowPitch;
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstImage::GetSlicePitch() const
{
    return m_impl->slicePitch;
}

//---------------------------------------------------------------------------------------------------------------------

const uint8_t* ConstImage::GetPixels() const
{
    return m_impl->pixels;
}

//---------------------------------------------------------------------------------------------------------------------

uint8_t* ConstImage::GetPixels()
{
    return m_impl->pixels;
}

//---------------------------------------------------------------------------------------------------------------------

const ConstImage::ImageImplementation& ConstImage::CGetImplementation() const
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

Image::Image() : m_impl(std::make_shared<ImageImplementation>())
{
}

//---------------------------------------------------------------------------------------------------------------------

Image::~Image() = default;

//---------------------------------------------------------------------------------------------------------------------

Image::Image(const Image& other) : m_impl(std::make_shared<ImageImplementation>(*other.m_impl))
{
}

//---------------------------------------------------------------------------------------------------------------------

Image& Image::operator=(const Image& other)
{
    if (this != &other)
    {
        *m_impl = *other.m_impl;
    }
    return *this;
}

//---------------------------------------------------------------------------------------------------------------------

Image::Image(Image&& other) = default;

//---------------------------------------------------------------------------------------------------------------------

Image& Image::operator=(Image&& other) = default;

//---------------------------------------------------------------------------------------------------------------------

Image::Image(const std::shared_ptr<ImageImplementation>& impl) : m_impl(impl)
{
}

//---------------------------------------------------------------------------------------------------------------------

Image::Image(const ConstImage& constImage) : m_impl(std::make_shared<ImageImplementation>(constImage.CGetImplementation()))
{
}

//---------------------------------------------------------------------------------------------------------------------

Image::operator ConstImage() const
{
    return ConstImage(m_impl);
}

//---------------------------------------------------------------------------------------------------------------------

void Image::SetWidth(size_t width)
{
    m_impl->width = width;
}

//---------------------------------------------------------------------------------------------------------------------

size_t Image::GetWidth() const
{
    return m_impl->width;
}

//---------------------------------------------------------------------------------------------------------------------

void Image::SetHeight(size_t height)
{
    m_impl->height = height;
}

//---------------------------------------------------------------------------------------------------------------------

size_t Image::GetHeight() const
{
    return m_impl->height;
}

//---------------------------------------------------------------------------------------------------------------------

void Image::SetFormat(TextureFormat format)
{
    m_impl->format = Internal::TextureFormatToDxgiFormat(format);
}

//---------------------------------------------------------------------------------------------------------------------

TextureFormat Image::GetFormat() const
{
    return Internal::DxgiFormatToTextureFormat(m_impl->format);
}

//---------------------------------------------------------------------------------------------------------------------

void Image::SetRowPitch(size_t rowPitch)
{
    m_impl->rowPitch = rowPitch;
}

//---------------------------------------------------------------------------------------------------------------------

size_t Image::GetRowPitch() const
{
    return m_impl->rowPitch;
}

//---------------------------------------------------------------------------------------------------------------------

void Image::SetSlicePitch(size_t slicePitch)
{
    m_impl->slicePitch = slicePitch;
}

//---------------------------------------------------------------------------------------------------------------------

size_t Image::GetSlicePitch() const
{
    return m_impl->slicePitch;
}

//---------------------------------------------------------------------------------------------------------------------

void Image::SetPixels(uint8_t* pixels)
{
    m_impl->pixels = pixels;
}

//---------------------------------------------------------------------------------------------------------------------

const uint8_t* Image::GetPixels() const
{
    return m_impl->pixels;
}

//---------------------------------------------------------------------------------------------------------------------

uint8_t* Image::GetPixels()
{
    return m_impl->pixels;
}

//---------------------------------------------------------------------------------------------------------------------

Image::ImageImplementation& Image::GetImplementation()
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

const Image::ImageImplementation& Image::CGetImplementation() const
{
    return *m_impl;
}

}  // namespace CanvasTex
