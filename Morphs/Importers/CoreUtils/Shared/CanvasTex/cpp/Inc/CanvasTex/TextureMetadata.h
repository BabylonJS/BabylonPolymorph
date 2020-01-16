/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <memory>

#include <CanvasTex/Format.h>

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

class TextureMetadataBase
{
public:
    class TextureMetadataImplementation;
};

//---------------------------------------------------------------------------------------------------------------------

class ConstTextureMetadata : public TextureMetadataBase
{
public:
    ConstTextureMetadata();
    ~ConstTextureMetadata();

    ConstTextureMetadata(const ConstTextureMetadata& other);
    ConstTextureMetadata& operator=(const ConstTextureMetadata& other) = delete;

    ConstTextureMetadata(const std::shared_ptr<const TextureMetadataImplementation>& impl);

    size_t GetWidth() const;

    size_t GetHeight() const;

    size_t GetDepth() const;

    size_t GetArraySize() const;

    size_t GetMipLevels() const;

    TextureFormat GetFormat() const;

    bool IsCubemap() const;

    const TextureMetadataImplementation& CGetImplementation() const;

private:
    std::shared_ptr<const TextureMetadataImplementation> m_impl;
};

//---------------------------------------------------------------------------------------------------------------------

class TextureMetadata : public TextureMetadataBase
{
public:

    TextureMetadata();
    ~TextureMetadata();

    TextureMetadata(const TextureMetadata& other);
    TextureMetadata& operator=(const TextureMetadata& other);

    TextureMetadata(TextureMetadata&& other);
    TextureMetadata& operator=(TextureMetadata&& other);

    TextureMetadata(const std::shared_ptr<TextureMetadataImplementation>& impl);

    TextureMetadata(const ConstTextureMetadata& constMeta);

    operator ConstTextureMetadata() const;

    void SetWidth(size_t width);
    size_t GetWidth() const;

    void SetHeight(size_t height);
    size_t GetHeight() const;

    void SetDepth(size_t depth);
    size_t GetDepth() const;

    void SetArraySize(size_t size);
    size_t GetArraySize() const;

    void SetMipLevels(size_t mipLevels);
    size_t GetMipLevels() const;

    void SetFormat(TextureFormat format);
    TextureFormat GetFormat() const;

    bool IsCubemap() const;

    TextureMetadataImplementation& GetImplementation();
    const TextureMetadataImplementation& CGetImplementation() const;

private:
    std::shared_ptr<TextureMetadataImplementation> m_impl;
};

}  // namespace CanvasTex
