#include <CanvasTex/TextureMetadata.h>
#include "TextureMetadata.h"

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::ConstTextureMetadata() : m_impl()
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::~ConstTextureMetadata()
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata::ConstTextureMetadata(const ConstTextureMetadata& other) : m_impl(other.m_impl)
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
    return m_impl->format;
}

//---------------------------------------------------------------------------------------------------------------------

bool ConstTextureMetadata::IsCubemap() const
{
    return m_impl->arraySize > 1;
}

//---------------------------------------------------------------------------------------------------------------------

const TextureMetadataBase::TextureMetadataImplementation& ConstTextureMetadata::CGetImplementation() const
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata() : m_impl(std::make_shared<TextureMetadataBase::TextureMetadataImplementation>())
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::~TextureMetadata()
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(const TextureMetadata& other) : m_impl(other.m_impl)
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata& TextureMetadata::operator=(const TextureMetadata& other)
{
    if(this != &other)
    {
        m_impl = other.m_impl;
    }

    return *this;
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(TextureMetadata&& other) : m_impl(std::move(other.m_impl))
{

}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata& TextureMetadata::operator=(TextureMetadata&& other)
{
    if(this != &other)
    {
        m_impl = std::move(other.m_impl);
    }

    return *this;
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(const std::shared_ptr<TextureMetadataImplementation>& impl) : m_impl(impl)
{
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadata::TextureMetadata(const ConstTextureMetadata& constMeta) : m_impl(std::make_shared<TextureMetadataBase::TextureMetadataImplementation>(constMeta.CGetImplementation()))
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
}

//---------------------------------------------------------------------------------------------------------------------

size_t TextureMetadata::GetMipLevels() const
{
    return 1;
}

//---------------------------------------------------------------------------------------------------------------------

void TextureMetadata::SetFormat(TextureFormat format)
{
    m_impl->format = format;
}

//---------------------------------------------------------------------------------------------------------------------

TextureFormat TextureMetadata::GetFormat() const
{
    return m_impl->format;
}

//---------------------------------------------------------------------------------------------------------------------

bool TextureMetadata::IsCubemap() const
{
    return m_impl->arraySize > 1;
}

//---------------------------------------------------------------------------------------------------------------------

TextureMetadataBase::TextureMetadataImplementation& TextureMetadata::GetImplementation()
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

const TextureMetadataBase::TextureMetadataImplementation& TextureMetadata::CGetImplementation() const
{
    return *m_impl;
}

}  // namespace CanvasTex
