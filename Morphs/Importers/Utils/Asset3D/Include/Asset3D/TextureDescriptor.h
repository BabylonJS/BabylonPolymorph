/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <memory>

#include <Asset3D/ITraversable.h>
#include <Framework/Frame.h>
#include <Framework/TextureWriter.h>

namespace Babylon
{
    namespace Transcoder
    {
        enum class TextureContainer : uint8_t
        {
            None,
            PNG,
            JPEG,
            DDS
        };

        using TextureEncoding = Babylon::Framework::TextureSegment::EFormat;

        struct BGRAImage
        {
            BGRAImage() : Width(0), Height(0), RowPitch(0) {}

            BGRAImage(std::vector<uint8_t>&& vec, uint32_t width, uint32_t height, uint32_t rowPitch) :
                Data(std::move(vec)), Width(width), Height(height), RowPitch(rowPitch) {}

            BGRAImage(size_t size, uint32_t width, uint32_t height, uint32_t rowPitch) :
                Data(std::vector<uint8_t>(size)), Width(width), Height(height), RowPitch(rowPitch) {}

            std::vector<uint8_t> Data;
            uint32_t Width;
            uint32_t Height;
            uint32_t RowPitch;
        };

        class TextureDescriptor : public ITraversableWithName
        {
        public:
            TextureDescriptor(std::unique_ptr<uint8_t[]>&& data, size_t size);

            TextureDescriptor(std::unique_ptr<uint8_t[]>&& data, size_t size, uint32_t width, uint32_t height,
                uint32_t lineStrideInBytes, Babylon::Framework::TextureSegment::EFormat format, uint8_t flags = 0);

            Framework::TextureSegment::EFormat GetFormat() const { return m_format; }

            enum class DataSource
            {
                MemoryFile,     ///< Texture is stored as a file in memory
                RawMemory       ///< Texture is stored as a decoded image (pixel format specified elsewhere)
            };

            inline uint8_t GetFlags() const { return m_flags; }
            inline void SetFlags(uint8_t flags)  {  m_flags |= flags; }
            inline DataSource GetDataSource() const { return m_dataSource; }
            inline uint8_t* GetData() const { return m_data.get(); }
            inline uint32_t GetSizeInBytes() const { return m_sizeInBytes; }
            inline uint32_t GetHeightInPixels() const { return m_height; }
            inline uint32_t GetWidthInPixels() const { return m_width; }
            inline uint32_t GetLineStrideInBytes() const { return m_lineStrideInBytes; }

            std::vector<uint8_t> EncodeTo(TextureContainer container, TextureEncoding encoding, uint32_t width, uint32_t height) const;
            std::vector<uint8_t> EncodeTo(TextureContainer container, TextureEncoding encoding) const;

            std::vector<uint8_t> EncodeToPNG() const { return EncodeToPNG(m_width, m_height); }
            std::vector<uint8_t> EncodeToPNG256() const { return EncodeToPNG256(m_width, m_height); }
            std::vector<uint8_t> EncodeToJPEG() const { return EncodeToJPEG(m_width, m_height); }
            std::vector<uint8_t> EncodeToDDSBC5() const { return EncodeToDDSBC5(m_width, m_height); }
            std::vector<uint8_t> EncodeToDDSBC7() const { return EncodeToDDSBC7(m_width, m_height); }

            std::vector<uint8_t> EncodeToPNG(   uint32_t width, uint32_t height) const { return EncodeTo(TextureContainer::PNG,  TextureEncoding::kPNG,       width, height); }
            std::vector<uint8_t> EncodeToPNG256(uint32_t width, uint32_t height) const { return EncodeTo(TextureContainer::PNG,  TextureEncoding::kPNG256,    width, height); }
            std::vector<uint8_t> EncodeToJPEG(  uint32_t width, uint32_t height) const { return EncodeTo(TextureContainer::JPEG, TextureEncoding::kJPEG,      width, height); }
            std::vector<uint8_t> EncodeToDDSBC5(uint32_t width, uint32_t height) const { return EncodeTo(TextureContainer::DDS,  TextureEncoding::kBC5_UNORM, width, height); }
            std::vector<uint8_t> EncodeToDDSBC7(uint32_t width, uint32_t height) const { return EncodeTo(TextureContainer::DDS,  TextureEncoding::kBC7_UNORM, width, height); }

            BGRAImage EncodeToBGRA() const;
            BGRAImage EncodeToBGRA(uint32_t width, uint32_t height) const;
            bool HasAlphaChannel() const;

            void ConvertGrayscaleToNormalMap();

        private:
            std::vector<uint8_t> EncodeTo(TextureContainer container, TextureEncoding encoding, uint32_t width, uint32_t height, uint8_t* data, TextureEncoding dataEncoding) const;

            std::unique_ptr<uint8_t[]> m_data;
            uint32_t m_sizeInBytes;

            uint32_t m_height;
            uint32_t m_width;
            uint32_t m_lineStrideInBytes;

            Babylon::Framework::TextureSegment::EFormat m_format;

            uint8_t             m_flags;
            DataSource          m_dataSource;

        };
    }
}
