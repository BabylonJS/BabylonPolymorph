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

class ImageBase
{
public:
    class ImageImplementation;
};

//---------------------------------------------------------------------------------------------------------------------

class ConstImage : public ImageBase
{
public:
    ConstImage();
    ~ConstImage();

    ConstImage(const ConstImage& other);
    ConstImage& operator=(const ConstImage& other) = delete;

    ConstImage(const std::shared_ptr<const ImageImplementation>& impl);

    size_t GetWidth() const;

    size_t GetHeight() const;

    TextureFormat GetFormat() const;

    size_t GetRowPitch() const;

    size_t GetSlicePitch() const;

    const uint8_t* GetPixels() const;
    uint8_t* GetPixels();

    const ImageImplementation& CGetImplementation() const;

private:
    std::shared_ptr<const ImageImplementation> m_impl;
};

//---------------------------------------------------------------------------------------------------------------------

class Image : public ImageBase
{
public:
    Image();
    ~Image();

    Image(const Image& other);
    Image& operator=(const Image& other);

    Image(Image&& other);
    Image& operator=(Image&& other);

    Image(const std::shared_ptr<ImageImplementation>& impl);

    Image(const ConstImage& constImage);

    operator ConstImage() const;

    void SetWidth(size_t width);
    size_t GetWidth() const;

    void SetHeight(size_t height);
    size_t GetHeight() const;

    void SetFormat(TextureFormat format);
    TextureFormat GetFormat() const;

    void SetRowPitch(size_t rowPitch);
    size_t GetRowPitch() const;

    void SetSlicePitch(size_t slicePitch);
    size_t GetSlicePitch() const;

    void SetPixels(uint8_t* pixels);
    const uint8_t* GetPixels() const;
    uint8_t* GetPixels();

    ImageImplementation& GetImplementation();
    const ImageImplementation& CGetImplementation() const;

private:
    std::shared_ptr<ImageImplementation> m_impl;
};

}  // namespace CanvasTex
