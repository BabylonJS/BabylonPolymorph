/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include "TextureMetadata.h"

#include <CanvasTex/Format.h>
#include <CanvasTex/TextureMetadata.h>

#include <DirectXTex.h>

#include "FormatConversion.h"

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::ConstTextureMetadata() : m_impl(std::make_shared<const TextureMetadataImplementation>())
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::~ConstTextureMetadata() = default;

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::ConstTextureMetadata(const ConstTextureMetadata& other) : m_impl(std::make_shared<const TextureMetadataImplementation>(*other.m_impl))
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::ConstTextureMetadata(const std::shared_ptr<const TextureMetadataImplementation>& impl) : m_impl(impl)
{
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstTextureMetadata::GetWidth() const
{
    return m_impl->width;
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstTextureMetadata::GetHeight() const
{
    return m_impl->height;
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstTextureMetadata::GetDepth() const
{
    return m_impl->depth;
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstTextureMetadata::GetArraySize() const
{
    return m_impl->arraySize;
}

//---------------------------------------------------------------------------------------------------------------------

size_t ConstTextureMetadata::GetMipLevels() const
{
    return m_impl->mipLevels;
}

//---------------------------------------------------------------------------------------------------------------------

TextureFormat ConstTextureMetadata::GetFormat() const
{
    return Internal::DxgiFormatToTextureFormat(m_impl->format);
}

//---------------------------------------------------------------------------------------------------------------------

bool ConstTextureMetadata::IsCubemap() const
{
    return m_impl->IsCubemap();
}

//---------------------------------------------------------------------------------------------------------------------

const ConstTextureMetadata::TextureMetadataImplementation& ConstTextureMetadata::CGetImplementation() const
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata() : m_impl(std::make_shared<TextureMetadataImplementation>())
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::~TextureMetadata() = default;

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(const TextureMetadata& other) : m_impl(std::make_shared<TextureMetadataImplementation>(*other.m_impl))
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata& TextureMetadata::operator=(const TextureMetadata& other)
{
    if (this != &other)
    {
        *m_impl = *other.m_impl;
    }
    return *this;
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(TextureMetadata&& other) = default;

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata& TextureMetadata::operator=(TextureMetadata&& other) = default;

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(const std::shared_ptr<TextureMetadataImplementation>& impl) : m_impl(impl)
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(const ConstTextureMetadata& constMeta) : m_impl(std::make_shared<TextureMetadataImplementation>(constMeta.CGetImplementation()))
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::operator ConstTextureMetadata() const
{
    return ConstTextureMetadata(m_impl);
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetWidth(size_t width)
{
    m_impl->width = width;
}

//---------------------------------------------------------------------------------------------------------------------

size_t TextureMetadata::GetWidth() const
{
    return m_impl->width;
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetHeight(size_t height)
{
    m_impl->height = height;
}

//---------------------------------------------------------------------------------------------------------------------

size_t TextureMetadata::GetHeight() const
{
    return m_impl->height;
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetDepth(size_t depth)
{
    m_impl->depth = depth;
}

//---------------------------------------------------------------------------------------------------------------------

size_t TextureMetadata::GetDepth() const
{
    return m_impl->depth;
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetArraySize(size_t size)
{
    m_impl->arraySize = size;
}

//---------------------------------------------------------------------------------------------------------------------

size_t TextureMetadata::GetArraySize() const
{
    return m_impl->arraySize;
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetMipLevels(size_t mipLevels)
{
    m_impl->mipLevels = mipLevels;
}

//---------------------------------------------------------------------------------------------------------------------

size_t TextureMetadata::GetMipLevels() const
{
    return m_impl->mipLevels;
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetFormat(TextureFormat format)
{
    m_impl->format = Internal::TextureFormatToDxgiFormat(format);
}

//---------------------------------------------------------------------------------------------------------------------

TextureFormat TextureMetadata::GetFormat() const
{
    return Internal::DxgiFormatToTextureFormat(m_impl->format);
}

//---------------------------------------------------------------------------------------------------------------------

bool TextureMetadata::IsCubemap() const
{
    return m_impl->IsCubemap();
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadataImplementation& TextureMetadata::GetImplementation()
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

const TextureMetadata::TextureMetadataImplementation& TextureMetadata::CGetImplementation() const
{
    return *m_impl;
}

}  // namespace CanvasTex
