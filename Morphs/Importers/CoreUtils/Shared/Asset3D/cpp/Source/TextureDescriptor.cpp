/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#include "Asset3DPch.h"

#include <Asset3D/TextureDescriptor.h>
#include <CoreUtils/Memory.h>
#include <ImagingComponent/ImagingComponent.h>
#include <ImagingComponent/Processing.h>

using namespace Babylon::Transcoder;
using namespace Babylon::ImagingV2;

DEFINE_TRACE_AREA(TextureDescriptor, 0);

namespace
{
    std::vector<uint8_t> EncodeTo(
        TextureContainer container,
        TextureEncoding targetEncoding,
        TextureEncoding currentEncoding,
        uint8_t* data,
        uint32_t dataSize,
        uint32_t width,
        uint32_t height,
        uint32_t stride)
    {
        switch (container)
        {
        case TextureContainer::PNG:
            switch (targetEncoding)
            {
            case TextureEncoding::kPNG:
                return ImagingComponent::EncodeAsPNG(
                    data,
                    dataSize,
                    height,
                    width,
                    stride,
                    currentEncoding,
                    false);
            case TextureEncoding::kPNG256:
                return ImagingComponent::EncodeAsPNG256(
                    data,
                    dataSize,
                    height,
                    width,
                    stride,
                    currentEncoding,
                    false);
            default:
                throw Babylon::Utils::BabylonException("Invalid TextureEncoding for PNG container");
            }
        case TextureContainer::JPEG:
            return ImagingComponent::EncodeAsJPG(
                data,
                dataSize,
                height,
                width,
                stride,
                currentEncoding,
                false);
        case TextureContainer::DDS:
            return ImagingComponent::EncodeAsDDS(
                data,
                dataSize,
                height,
                width,
                stride,
                currentEncoding,
                targetEncoding);
        default:
            return ImagingComponent::EncodeToMemory(
                data,
                dataSize,
                height,
                width,
                stride,
                currentEncoding,
                targetEncoding);
        }
    }
}

TextureDescriptor::TextureDescriptor(std::unique_ptr<uint8_t[]>&& data, size_t size)
    : ITraversableWithName(),
      m_data(std::move(data)),
      m_sizeInBytes(static_cast<uint32_t>(size)),
      m_height(0),
      m_width(0),
      m_lineStrideInBytes(0),
      m_format(Babylon::Framework::TextureSegment::EFormat::kUnknown),
      m_flags(0),
      m_dataSource(DataSource::MemoryFile)
{
    // Try to get width and height from the data, rather than defaulting to 0's
    if (m_sizeInBytes > 0)
    {
        ImagingComponent::TryGetImageWidthHeight(m_data.get(), m_sizeInBytes, m_width, m_height);
    }
}

TextureDescriptor::TextureDescriptor(std::unique_ptr<uint8_t[]>&& data, size_t size,
        uint32_t width, uint32_t height, uint32_t lineStrideInBytes, Babylon::Framework::TextureSegment::EFormat format, uint8_t flags)
    : ITraversableWithName(),
    m_data(std::move(data)),
    m_sizeInBytes(static_cast<uint32_t>(size)),
    m_height(height),
    m_width(width),
    m_lineStrideInBytes(lineStrideInBytes),
    m_format(format),
    m_flags(flags),
    m_dataSource(DataSource::RawMemory)
{
}

std::vector<uint8_t> Babylon::Transcoder::TextureDescriptor::EncodeTo(TextureContainer container, TextureEncoding encoding, uint32_t width, uint32_t height) const
{
    if (width != m_width || height != m_height)
    {
        // Resize, and convert to BGRA32
        auto bytes = ImagingComponent::Resize(
            m_data.get(),
            m_sizeInBytes,
            m_height,
            m_width,
            m_lineStrideInBytes,
            m_format,
            height,
            width
        );

        return ::EncodeTo(container, encoding, TextureEncoding::kFormatBGRA32, bytes.data(), static_cast<uint32_t>(bytes.size()), width, height, width * 4);
    }

    return ::EncodeTo(container, encoding, m_format, m_data.get(), m_sizeInBytes, m_width, m_height, m_lineStrideInBytes);
}

std::vector<uint8_t> Babylon::Transcoder::TextureDescriptor::EncodeTo(TextureContainer container, TextureEncoding encoding) const
{
    return ::EncodeTo(container, encoding, m_format, m_data.get(), m_sizeInBytes, m_width, m_height, m_lineStrideInBytes);
}

bool TextureDescriptor::HasAlphaChannel() const
{
    return ImagingComponent::HasAlphaChannel(m_data.get(), m_sizeInBytes, m_format);
}

void TextureDescriptor::ConvertGrayscaleToNormalMap()
{
    auto bgra = EncodeToBGRA();

    CanvasTex::Image image;
    image.SetHeight(bgra.Height);
    image.SetWidth(bgra.Width);
    image.SetRowPitch(bgra.RowPitch);
    image.SetSlicePitch(bgra.Data.size());
    image.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
    image.SetPixels(bgra.Data.data());

    bool modified = Babylon::ImagingV2::ImagingComponent::ConvertGrayscaleNormalMap(image, 1.0f);

    if (modified)
    {
        //  Update the texture with the modified data
        auto data = std::make_unique<uint8_t[]>(bgra.Data.size());
        memcpy_s(data.get(), bgra.Data.size(), image.GetPixels(), bgra.Data.size());

        m_data = std::move(data);
        m_sizeInBytes = static_cast<uint32_t>(bgra.Data.size());
        m_width = bgra.Width;
        m_height = bgra.Height;
        m_lineStrideInBytes = bgra.RowPitch;
        m_format = Framework::TextureSegment::EFormat::kFormatBGRA32;
    }
}

BGRAImage TextureDescriptor::EncodeToBGRA() const
{
    BGRAImage result;
    result.Width = 0;
    result.Height = 0;
    result.RowPitch = 0;

    result.Data = ImagingComponent::EncodeToMemory(
        m_data.get(),
        m_sizeInBytes,
        m_height,
        m_width,
        m_lineStrideInBytes,
        m_format,
        Babylon::Framework::TextureSegment::EFormat::kFormatBGRA32,
        &result.Height,
        &result.Width,
        &result.RowPitch);

    return result;
}

BGRAImage TextureDescriptor::EncodeToBGRA(uint32_t width, uint32_t height) const
{
    if (width == m_width && height == m_height)
    {
        return EncodeToBGRA();
    }

    BGRAImage result;
    result.Width    = width;
    result.Height   = height;
    result.RowPitch = width * 4;
    result.Data     = ImagingComponent::Resize(
        m_data.get(),
        m_sizeInBytes,
        m_height,
        m_width,
        m_lineStrideInBytes,
        m_format,
        height,
        width);

    return result;
}

void TextureDescriptor::InvertY() {

    /// NOTE : we may optimize memory comsumption when image is already stored as rawdada
    auto bgra = EncodeToBGRA();

    CanvasTex::Image image;
    image.SetHeight(bgra.Height);
    image.SetWidth(bgra.Width);
    image.SetRowPitch(bgra.RowPitch);
    image.SetSlicePitch(bgra.Data.size());
    image.SetFormat(CanvasTex::TextureFormat::B8g8r8a8Unorm);
    image.SetPixels(bgra.Data.data());

    bool modified = Babylon::ImagingV2::ImagingComponent::InvertY(image);

    if (modified)
    {
        //  Update the texture with the modified data
        auto data = std::make_unique<uint8_t[]>(bgra.Data.size());
        memcpy_s(data.get(), bgra.Data.size(), image.GetPixels(), bgra.Data.size());

        m_data = std::move(data);
        m_sizeInBytes = static_cast<uint32_t>(bgra.Data.size());
        m_width = bgra.Width;
        m_height = bgra.Height;
        m_lineStrideInBytes = bgra.RowPitch;
        m_format = Framework::TextureSegment::EFormat::kFormatBGRA32;
    }
}
