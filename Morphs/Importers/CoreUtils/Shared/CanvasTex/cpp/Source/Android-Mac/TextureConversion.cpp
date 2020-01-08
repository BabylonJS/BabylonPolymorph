//
// Copyright (C) Microsoft.  All rights reserved.
//

#include "GliIncludes.h"
#include <gli/copy.hpp>
#include "TextureConversion.h"
#import "TextureLoaders.h"

#define THROW_IF_FALSE(condition, ...) if (!(condition)) {throw Spectre::Utils::SpectreException(#condition " is false in " __FILE__ " at line " _STRINGIZE(__LINE__) " : " __VA_ARGS__); }


namespace CanvasTex
{

    void MakePixelFormatDesc32FromUnorm(CanvasPixelFormatDesc32& desc, int redPos, int greenPos, int bluePos, int alphaPos)
    {
        desc.bitsPerPixel = 32;

        desc.shiftDown[CanvasPixelFormatDesc32::RedIndex] = 8*redPos;
        desc.shiftUp[CanvasPixelFormatDesc32::RedIndex] = 0;

        desc.shiftDown[CanvasPixelFormatDesc32::GreenIndex] = 8*greenPos;
        desc.shiftUp[CanvasPixelFormatDesc32::GreenIndex] = 0;

        desc.shiftDown[CanvasPixelFormatDesc32::BlueIndex] = 8*bluePos;
        desc.shiftUp[CanvasPixelFormatDesc32::BlueIndex] = 0;

        desc.shiftDown[CanvasPixelFormatDesc32::AlphaIndex] = 8*alphaPos;
        desc.shiftUp[CanvasPixelFormatDesc32::AlphaIndex] = 0;
    }

    void MakePixelFormatDescFromTextureFormat(CanvasPixelFormatDesc32& desc, TextureFormat format)
    {
        switch (format)
        {
            case TextureFormat::B8g8r8a8Unorm:
            case TextureFormat::B8g8r8a8UnormSrgb:
                // BGRA
                MakePixelFormatDesc32FromUnorm(desc, 2, 1, 0, 3);
                break;

            case TextureFormat::R8g8b8a8Unorm:
            case TextureFormat::R8g8b8a8UnormSrgb:
                // RGBA
                MakePixelFormatDesc32FromUnorm(desc, 0, 1, 2, 3);
                break;

            default:
                throw std::runtime_error("Unsupported format for Desc.");
        }
    }

    inline uint32_t NormalizeComponent32(uint32_t pixel, int shiftDown, int shiftUp)
    {
        const uint32_t mask = 0xFF << shiftDown;
        uint32_t p = pixel & mask;
        p >>= shiftDown;
        p <<= shiftUp;
        return p;
    }

    inline uint32_t StoreComponent32(uint32_t const& pixel, uint32_t component, int shiftDown, int shiftUp)
    {
        uint32_t c = component >> shiftUp;
        c <<= shiftDown;
        return pixel | c;
    }

    uint32_t ConvertPixel32(uint32_t pixel, CanvasPixelFormatDesc32 const& inputDesc, CanvasPixelFormatDesc32 const& outputDesc)
    {
        uint32_t outputPixel = 0;

        for (int i = 0; i < 4; ++i)
        {
            uint32_t component = NormalizeComponent32(pixel, inputDesc.shiftDown[i], inputDesc.shiftUp[i]);
            outputPixel = StoreComponent32(outputPixel, component, outputDesc.shiftDown[i], outputDesc.shiftUp[i]);
        }

        return outputPixel;
    }

    std::unique_ptr<uint8_t[]> Convert32(
             const uint8_t* pSource,
             size_t width,
             size_t height,
             size_t bytesPerRow,
             CanvasPixelFormatDesc32 const& inputDesc,
             CanvasPixelFormatDesc32 const& outputDesc)
    {
        std::unique_ptr<uint8_t[]> outputPixels = std::make_unique<uint8_t[]>(bytesPerRow * height);
        const uint32_t* inputPixels = reinterpret_cast<const uint32_t*>(pSource);

        uint32_t* output32 = reinterpret_cast<uint32_t*>(&outputPixels[0]);

        for (size_t y = 0; y < height; ++y)
        {
            for (size_t x = 0; x < width; ++x)
            {
                size_t offset = y*width + x;
                uint32_t pin = inputPixels[offset];
                output32[offset] = ConvertPixel32(pin, inputDesc, outputDesc);
            }
        }

        return outputPixels;
    }

    // -------------------------------------------------------------------
    // DDS


    struct GliToTextureFormatDesc
    {
        TextureFormat format;
    };

    static GliToTextureFormatDesc const GliToTextureFormatTable[] =
    {
        {TextureFormat::Unknown},               //FORMAT_R4G4_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA4_UNORM,
        {TextureFormat::Unknown},               //FORMAT_BGRA4_UNORM,
        {TextureFormat::Unknown},               //FORMAT_R5G6B5_UNORM,
        {TextureFormat::Unknown},               //FORMAT_B5G6R5_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGB5A1_UNORM,
        {TextureFormat::Unknown},               //FORMAT_BGR5A1_UNORM,
        {TextureFormat::Unknown},               //FORMAT_A1RGB5_UNORM,

        {TextureFormat::Unknown},               //FORMAT_R8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_R8_SNORM,
        {TextureFormat::Unknown},               //FORMAT_R8_USCALED,
        {TextureFormat::Unknown},               //FORMAT_R8_SSCALED,
        {TextureFormat::Unknown},               //FORMAT_R8_UINT,
        {TextureFormat::Unknown},               //FORMAT_R8_SINT,
        {TextureFormat::Unknown},               //FORMAT_R8_SRGB,

        {TextureFormat::Unknown},               //FORMAT_RG8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RG8_SNORM,
        {TextureFormat::Unknown},               //FORMAT_RG8_USCALED,
        {TextureFormat::Unknown},               //FORMAT_RG8_SSCALED,
        {TextureFormat::Unknown},               //FORMAT_RG8_UINT,
        {TextureFormat::Unknown},               //FORMAT_RG8_SINT,
        {TextureFormat::Unknown},               //FORMAT_RG8_SRGB,

        {TextureFormat::Unknown},               //FORMAT_RGB8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGB8_SNORM,
        {TextureFormat::Unknown},               //FORMAT_RGB8_USCALED,
        {TextureFormat::Unknown},               //FORMAT_RGB8_SSCALED,
        {TextureFormat::Unknown},               //FORMAT_RGB8_UINT,
        {TextureFormat::Unknown},               //FORMAT_RGB8_SINT,
        {TextureFormat::Unknown},               //FORMAT_RGB8_SRGB,

        {TextureFormat::Unknown},               //FORMAT_BGR8_UNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGR8_SNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGR8_USCALED_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGR8_SSCALED_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGR8_UINT_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGR8_SINT_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGR8_SRGB_PACK8,

        {TextureFormat::R8g8b8a8Unorm},         //FORMAT_RGBA8_UNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA8_SNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA8_USCALED_PACK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA8_SSCALED_PACK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA8_UINT_PACK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA8_SINT_PACK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA8_SRGB_PACK8,

        {TextureFormat::B8g8r8a8Unorm},         //FORMAT_BGRA8_UNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGRA8_SNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGRA8_USCALED_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGRA8_SSCALED_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGRA8_UINT_PACK8,
        {TextureFormat::Unknown},               //FORMAT_BGRA8_SINT_PACK8,
        {TextureFormat::B8g8r8a8UnormSrgb},     //FORMAT_BGRA8_SRGB_PACK8,

        {TextureFormat::Unknown},               //FORMAT_ABGR8_UNORM_PACK32,
        {TextureFormat::Unknown},               //FORMAT_ABGR8_SNORM_PACK32,
        {TextureFormat::Unknown},               //FORMAT_ABGR8_USCALED_PACK32,
        {TextureFormat::Unknown},               //FORMAT_ABGR8_SSCALED_PACK32,
        {TextureFormat::Unknown},               //FORMAT_ABGR8_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_ABGR8_SINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_ABGR8_SRGB_PACK32,

        {TextureFormat::Unknown},               //FORMAT_RGB10A2_UNORM_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB10A2_SNORM_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB10A2_USCALE_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB10A2_SSCALE_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB10A2_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB10A2_SINT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_BGR10A2_UNORM_PACK32,
        {TextureFormat::Unknown},               //FORMAT_BGR10A2_SNORM_PACK32,
        {TextureFormat::Unknown},               //FORMAT_BGR10A2_USCALE_PACK32,
        {TextureFormat::Unknown},               //FORMAT_BGR10A2_SSCALE_PACK32,
        {TextureFormat::Unknown},               //FORMAT_BGR10A2_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_BGR10A2_SINT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_R16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_R16_SNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_R16_USCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_R16_SSCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_R16_UINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_R16_SINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_R16_SFLOAT_PACK16,

        {TextureFormat::Unknown},               //FORMAT_RG16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RG16_SNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RG16_USCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RG16_SSCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RG16_UINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RG16_SINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RG16_SFLOAT_PACK16,

        {TextureFormat::Unknown},               //FORMAT_RGB16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGB16_SNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGB16_USCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGB16_USCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGB16_UINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGB16_SINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGB16_SFLOAT_PACK16,

        {TextureFormat::Unknown},               //FORMAT_RGBA16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA16_SNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA16_USCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA16_SSCALED_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA16_UINT_PACK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA16_SINT_PACK16,
        {TextureFormat::R16g16b16a16Float},     //FORMAT_RGBA16_SFLOAT_PACK16,

        {TextureFormat::Unknown},               //FORMAT_R32_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_R32_SINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_R32_SFLOAT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_RG32_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RG32_SINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RG32_SFLOAT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_RGB32_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB32_SINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB32_SFLOAT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_RGBA32_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA32_SINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA32_SFLOAT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_R64_UINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_R64_SINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_R64_SFLOAT_PACK64,

        {TextureFormat::Unknown},               //FORMAT_RG64_UINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_RG64_SINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_RG64_SFLOAT_PACK64,

        {TextureFormat::Unknown},               //FORMAT_RGB64_UINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_RGB64_SINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_RGB64_SFLOAT_PACK64,

        {TextureFormat::Unknown},               //FORMAT_RGBA64_UINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_RGBA64_SINT_PACK64,
        {TextureFormat::Unknown},               //FORMAT_RGBA64_SFLOAT_PACK64,

        {TextureFormat::Unknown},               //FORMAT_RG11B10_UFLOAT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_RGB9E5_UFLOAT_PACK32,

        {TextureFormat::Unknown},               //FORMAT_D16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_D24_UNORM,
        {TextureFormat::Unknown},               //FORMAT_D32_UFLOAT,
        {TextureFormat::Unknown},               //FORMAT_S8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_D16_UNORM_S8_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_D24_UNORM_S8_UINT_PACK32,
        {TextureFormat::Unknown},               //FORMAT_D32_SFLOAT_S8_UINT_PACK64,

        {TextureFormat::Unknown},               //FORMAT_RGB_DXT1_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGB_DXT1_SRGB_BLOCK8,
        {TextureFormat::Bc1Unorm},              //FORMAT_RGBA_DXT1_UNORM_BLOCK8,
        {TextureFormat::Bc1UnormSrgb},          //FORMAT_RGBA_DXT1_SRGB_BLOCK8,
        {TextureFormat::Bc2Unorm},              //FORMAT_RGBA_DXT3_UNORM_BLOCK16,
        {TextureFormat::Bc2UnormSrgb},          //FORMAT_RGBA_DXT3_SRGB_BLOCK16,
        {TextureFormat::Bc3Unorm},              //FORMAT_RGBA_DXT5_UNORM_BLOCK16,
        {TextureFormat::Bc3UnormSrgb},          //FORMAT_RGBA_DXT5_SRGB_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_R_ATI1N_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_R_ATI1N_SNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RG_ATI2N_UNORM_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_RG_ATI2N_SNORM_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_RGB_BP_UFLOAT_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_RGB_BP_SFLOAT_BLOCK16,
        {TextureFormat::Bc7Unorm},              //FORMAT_RGB_BP_UNORM,
        {TextureFormat::Bc7UnormSrgb},          //FORMAT_RGB_BP_SRGB,

        {TextureFormat::Unknown},               //FORMAT_RGB_ETC2_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGB_ETC2_SRGB_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ETC2_PUNCHTHROUGH_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ETC2_PUNCHTHROUGH_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ETC2_UNORM_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ETC2_SRGB_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_R11_EAC_UNORM,
        {TextureFormat::Unknown},               //FORMAT_R11_EAC_SNORM,
        {TextureFormat::Unknown},               //FORMAT_RG11_EAC_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RG11_EAC_SNORM,

        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC4X4_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC4X4_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC5X4_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC5X4_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC5X5_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC5X5_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC6X5_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC6X5_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC6X6_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC6X6_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC8X5_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC8X5_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC8X6_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC8X6_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC8X8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC8X8_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X5_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X5_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X6_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X6_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X8_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X10_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC10X10_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC12X10_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC12X10_SRGB,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC12X12_UNORM,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ASTC12X12_SRGB,

        {TextureFormat::Unknown},               //FORMAT_RGB_PVRTC1_8X8_UNORM_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGB_PVRTC1_8X8_SRGB_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGB_PVRTC1_16X8_UNORM_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGB_PVRTC1_16X8_SRGB_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC1_8X8_UNORM_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC1_8X8_SRGB_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC1_16X8_UNORM_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC1_16X8_SRGB_BLOCK32,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC2_4X4_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC2_4X4_SRGB_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC2_8X4_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA_PVRTC2_8X4_SRGB_BLOCK8,

        {TextureFormat::Unknown},               //FORMAT_RGB_ETC_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGB_ATC_UNORM_BLOCK8,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ATCA_UNORM_BLOCK16,
        {TextureFormat::Unknown},               //FORMAT_RGBA_ATCI_UNORM_BLOCK16,

        {TextureFormat::R8Unorm},               //FORMAT_L8_UNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_A8_UNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_LA8_UNORM_PACK8,
        {TextureFormat::Unknown},               //FORMAT_L16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_A16_UNORM_PACK16,
        {TextureFormat::Unknown},               //FORMAT_LA16_UNORM_PACK16,

        {TextureFormat::Unknown},               //FORMAT_BGRX8_UNORM,
        {TextureFormat::Unknown},               //FORMAT_BGRX8_SRGB,

        {TextureFormat::Unknown},               //FORMAT_RG3B2_UNORM,
    };

    static_assert(sizeof(GliToTextureFormatTable) / sizeof(GliToTextureFormatTable[0]) == gli::FORMAT_COUNT, "GLI error: format descriptor list doesn't match number of supported formats");


    bool IsDDS(void const* pSource)
    {
        return (memcmp(pSource, "DDS ", 4) == 0);
    }

    TextureFormat GetCanvasTextureFormat(gli::format format)
    {
        THROW_IF_FALSE(format >= gli::FORMAT_FIRST && format <= gli::FORMAT_LAST);
        auto result = GliToTextureFormatTable[format - gli::FORMAT_FIRST];
        return result.format;
    }

    gli::format GetGliTextureFormat(TextureFormat format)
    {
        for (int i = 0; i < gli::FORMAT_COUNT; ++i)
        {
            if (GliToTextureFormatTable[i].format == format)
            {
                return static_cast<gli::format>(i + gli::FORMAT_FIRST);
            }
        }
        return gli::FORMAT_UNDEFINED;
    }

    gli::texture LoadDDS(void const* pSource, size_t inLength)
    {
        // Catch any exceptions thrown in gli since this does get called in places that have poor exception handling in the NativeViewer.
        // TODO: Move a try/catch up higher in the stack in all instances where it is called so the exception information can propagate
        // up to the caller, maybe.
        try
        {
            return gli::load_dds(static_cast<const char*>(pSource), inLength);
        }
        catch(...)
        {
            return gli::texture();
        }
    }

} // namespace CanvasTex
