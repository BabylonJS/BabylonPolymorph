#include <CanvasTex/ScratchImage.h>
#include "ScratchImage.h"
#include "ImageMac.h"
#include <vector>
#include <gli/texture2d_array.hpp>
#include <gli/texture_cube.hpp>

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

ScratchImage::ScratchImage() : m_impl(std::make_shared<ScratchImageImplementation>())
{
}

//---------------------------------------------------------------------------------------------------------------------

ScratchImage::~ScratchImage() = default;

//---------------------------------------------------------------------------------------------------------------------

ScratchImage::ScratchImage(ScratchImage&& other) : m_impl(std::move(other.m_impl))
{
}

//---------------------------------------------------------------------------------------------------------------------

ScratchImage& ScratchImage::operator=(ScratchImage&& other)
{
    if(this != &other)
    {
        m_impl = std::move(other.m_impl);
    }

    return *this;
}

//---------------------------------------------------------------------------------------------------------------------

void ScratchImage::InitializeFromImage(const Image& srcImage)
{
    m_impl->InitializeFromImage(srcImage.CGetImplementation());
}

//---------------------------------------------------------------------------------------------------------------------

void ScratchImage::Release()
{
}

//---------------------------------------------------------------------------------------------------------------------

ConstTextureMetadata ScratchImage::GetMetadata() const
{
    auto metaImpl = static_cast<const ConstTextureMetadata::TextureMetadataImplementation*>(&m_impl->GetMetadata());
    return ConstTextureMetadata(std::shared_ptr<const TextureMetadataBase::TextureMetadataImplementation>(m_impl, metaImpl));
}

// //---------------------------------------------------------------------------------------------------------------------

 ConstImage ScratchImage::GetImage(size_t item, size_t mip) const
 {
     gli::texture& texture = m_impl->m_texture;

     // It seems that the behaviour of CanvasTex is that the item is an index into layers or faces.
     // ScratchImage does not directly support arrays of cubemaps.
     if (texture.layers() > 1 && texture.faces() > 1)
     {
         throw Spectre::Utils::SpectreException(std::string("ScratchImage::GetImage - Does not support arrays of cubemaps"));
     }

     switch (m_impl->m_texture.target())
     {
     case gli::TARGET_1D:
     case gli::TARGET_2D:
         {
             if (item != 0)
             {
                 throw Spectre::Utils::SpectreException(std::string("ScratchImage::GetImage - Non-zero 'item' for non-array texture"));
             }

             // index == miplevel
             auto t2d = gli::texture2d(texture);
             auto gliImage = t2d[mip];

             Image image;
             ImageBase::ImageImplementation& imageImpl = image.GetImplementation();
             imageImpl.SetGliImage(gliImage);

             return ConstImage(image);
         }
         break;

     case gli::TARGET_1D_ARRAY:
     case gli::TARGET_2D_ARRAY:
         {
             auto t2da = gli::texture2d_array(texture);
             auto gliImage = t2da[item][mip];

             Image image;
             ImageBase::ImageImplementation& imageImpl = image.GetImplementation();
             imageImpl.SetGliImage(gliImage);

             return ConstImage(image);
         }
         break;

     case gli::TARGET_CUBE:
         {
             auto cube = gli::texture_cube(texture);
             auto gliImage = cube[item][mip];

             Image image;
             ImageBase::ImageImplementation& imageImpl = image.GetImplementation();
             imageImpl.SetGliImage(gliImage);

             return ConstImage(image);

         }
         break;

     case gli::TARGET_3D:
         throw Spectre::Utils::SpectreException("ScratchImage::GetImage - Not implemented for 3D textures");
         break;

     default:
         throw Spectre::Utils::SpectreException(std::string("ScratchImage::GetImage - Unknown texture target ") + std::to_string(m_impl->m_texture.target()));
     }

 }

//---------------------------------------------------------------------------------------------------------------------

size_t ScratchImage::GetImageCount() const
{
    if (m_impl->m_texture.layers() > 1 && m_impl->m_texture.faces() > 1)
    {
        throw Spectre::Utils::SpectreException(std::string("ScratchImage::GetImageCount - Does not support arrays of cubemaps"));
    }

    return std::max(m_impl->m_texture.layers(), m_impl->m_texture.faces()) * m_impl->m_texture.levels();
}

//---------------------------------------------------------------------------------------------------------------------

const uint8_t* ScratchImage::GetPixels() const
{
    return m_impl->GetPixels();
}

//---------------------------------------------------------------------------------------------------------------------

uint8_t* ScratchImage::GetPixels()
{
    return m_impl->GetPixels();
}

//---------------------------------------------------------------------------------------------------------------------

size_t ScratchImage::GetPixelsSize() const
{
    return m_impl->GetPixelsSize();
}

//---------------------------------------------------------------------------------------------------------------------

ScratchImage::ScratchImageImplementation& ScratchImage::GetImplementation()
{
    return *m_impl;
}

//---------------------------------------------------------------------------------------------------------------------

const ScratchImage::ScratchImageImplementation& ScratchImage::CGetImplementation() const
{
    return *m_impl;
}

}  // namespace CanvasTex
