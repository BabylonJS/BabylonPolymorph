/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include <CanvasTex/CanvasTex.h>

#include <wrl/client.h>

#include <DirectXTex.h>
#include <wincodec.h>

#include <CoreUtils/SmartThrow.h>

#include "../CanvasTexUtils.h"

#include "FormatConversion.h"
#include "Image.h"
#include "TextureMetadata.h"
#include "ScratchImage.h"
#include "DxDevice.h"
#include "MedianCutQuantizer.h"
#include "WindowsCommon.h"


namespace
{
    //Note: see comment in SaveToMemory function definition

    /*class GlobalLockGuard
    {
    public:
        GlobalLockGuard(HGLOBAL hGlobal) : m_hGlobal(hGlobal), m_lockedData(::GlobalLock(hGlobal))
        {
        }

        ~GlobalLockGuard()
        {
            if (m_lockedData)
            {
                ::GlobalUnlock(m_hGlobal);
            }
        }

        void* const m_lockedData;

    private:
        const HGLOBAL m_hGlobal;
    };*/

    void EncodeIndexedPngToStream(const CanvasTex::ConstImage& image,
        Microsoft::WRL::ComPtr<IWICImagingFactory> pWicFactory,
        Microsoft::WRL::ComPtr<IWICStream> pWicStream)
    {
        const auto imageWidth = image.GetWidth();
        const auto imageHeight = image.GetHeight();

        Microsoft::WRL::ComPtr<IWICBitmap> pWicBitmap;
        Spectre::Utils::ThrowIfFailed(pWicFactory->CreateBitmap(
            static_cast<UINT>(imageWidth),
            static_cast<UINT>(imageHeight),
            GUID_WICPixelFormat8bppIndexed,
            WICBitmapCacheOnDemand,
            &pWicBitmap));

        CanvasTex::MedianCutQuantizer::QuantizeImage(image.GetPixels(), imageWidth, imageHeight, image.GetRowPitch(), pWicBitmap.Get(), 256);

        WICPixelFormatGUID outputFormat;
        Spectre::Utils::ThrowIfFailed(pWicBitmap->GetPixelFormat(&outputFormat));

        Microsoft::WRL::ComPtr<IWICBitmapEncoder> pEncoder;
        Spectre::Utils::ThrowIfFailed(pWicFactory->CreateEncoder(GUID_ContainerFormatPng, nullptr, &pEncoder));
        Spectre::Utils::ThrowIfFailed(pEncoder->Initialize(pWicStream.Get(), WICBitmapEncoderNoCache));

        Microsoft::WRL::ComPtr<IWICBitmapFrameEncode> pFrameEncode;
        Spectre::Utils::ThrowIfFailed(pEncoder->CreateNewFrame(&pFrameEncode, nullptr));
        Spectre::Utils::ThrowIfFailed(pFrameEncode->Initialize(nullptr));
        Spectre::Utils::ThrowIfFailed(pFrameEncode->SetSize(static_cast<UINT>(imageWidth), static_cast<UINT>(imageHeight)));
        Spectre::Utils::ThrowIfFailed(pFrameEncode->SetPixelFormat(&outputFormat));
        Spectre::Utils::ThrowIfFailed(pFrameEncode->WriteSource(pWicBitmap.Get(), nullptr));
        Spectre::Utils::ThrowIfFailed(pFrameEncode->Commit());
        Spectre::Utils::ThrowIfFailed(pEncoder->Commit());
    }

    DirectX::TEX_FILTER_FLAGS FilterOptionsToTexFilterFlags(CanvasTex::FilterOptions filterOptions)
    {
        switch (filterOptions)
        {
        case CanvasTex::FilterOptions::Box:
            return DirectX::TEX_FILTER_BOX;
        case CanvasTex::FilterOptions::SeparateAlpha:
            return DirectX::TEX_FILTER_SEPARATE_ALPHA;
        default:
            throw Spectre::Utils::SpectreException("CanvasTex::FilterOptionsToTexFilterFlags - Unknown FilterOptions.");
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

bool IsCompressed(
    TextureFormat fmt)
{
    return DirectX::IsCompressed(Internal::TextureFormatToDxgiFormat(fmt));
}

//---------------------------------------------------------------------------------------------------------------------

bool IsTgaFile(
    const void* pSource,
    size_t size)
{
    DirectX::TexMetadata unusedMetadata;
    if (DirectX::GetMetadataFromTGAMemory(pSource, size, unusedMetadata) == S_OK)
    {
        return true;
    }

    return false;
}

//---------------------------------------------------------------------------------------------------------------------

bool GetMetadataFromMemory(
    const void* pSource,
    size_t size,
    Spectre::Framework::ImageReader reader,
    TextureMetadata& metadata)
{
    HRESULT hr = E_FAIL;
    switch (reader)
    {
    case Spectre::Framework::ImageReader::DDS:
        hr = DirectX::GetMetadataFromDDSMemory(pSource, size, DirectX::DDS_FLAGS_NONE, metadata.GetImplementation());
        break;
    case Spectre::Framework::ImageReader::TGA:
        hr = DirectX::GetMetadataFromTGAMemory(pSource, size, metadata.GetImplementation());
        break;
    case Spectre::Framework::ImageReader::WIC:
        hr = DirectX::GetMetadataFromWICMemory(pSource, size, DirectX::WIC_FLAGS_IGNORE_SRGB, metadata.GetImplementation());
        break;
    case Spectre::Framework::ImageReader::PSD:
    case Spectre::Framework::ImageReader::UNKNOWN:
    default:
        break;
    }

    return (hr == S_OK);
}

//---------------------------------------------------------------------------------------------------------------------

LoadResult LoadFromMemory(
    const void* pSource,
    size_t size,
    Spectre::Framework::ImageReader reader,
    TextureMetadata* metadata,
    ScratchImage& image)
{
    // All PNG images should be handled by WIC
    // Some other formats can be handled by WIC, but TGA or DDS require separate Load* functions

    auto metadataImplementation = metadata != nullptr ? &metadata->GetImplementation() : nullptr;

    HRESULT hr = E_FAIL;
    switch (reader)
    {
    case Spectre::Framework::ImageReader::DDS:
    {
        hr = DirectX::LoadFromDDSMemory(pSource, size, DirectX::DDS_FLAGS_NONE, metadataImplementation, image.GetImplementation());
        return (hr == S_OK ? LoadResult::LoadSuccessful : LoadResult::LoadFailed);
    }
    case Spectre::Framework::ImageReader::TGA:
    {
        hr = DirectX::LoadFromTGAMemory(pSource, size, metadataImplementation, image.GetImplementation());
        return (hr == S_OK ? LoadResult::LoadSuccessful : LoadResult::LoadFailed);
    }
    case Spectre::Framework::ImageReader::WIC:
    {
        hr = DirectX::LoadFromWICMemory(pSource, size, DirectX::WIC_FLAGS_IGNORE_SRGB, metadataImplementation, image.GetImplementation());
        return (hr == S_OK ? LoadResult::LoadSuccessful : LoadResult::LoadFailed);
    }
    case Spectre::Framework::ImageReader::PSD:
        return LoadResult::NotSupportedType;
    case Spectre::Framework::ImageReader::UNKNOWN:
        return LoadResult::NotSupportedType;
    default:
        return LoadResult::UnknownReaderType;
    }
}

//---------------------------------------------------------------------------------------------------------------------

std::function<void(IPropertyBag2*)> GetPropsCallbackPngFilterNone()
{
    return [&](IPropertyBag2* props)
    {
        PROPBAG2 options[1] = { 0 };
        options[0].pstrName = L"FilterOption";

        VARIANT varValues[1];
        varValues[0].vt = VT_UI1;
        varValues[0].bVal = WICPngFilterNone;

        (void)props->Write(1, options, varValues);
    };
}

//---------------------------------------------------------------------------------------------------------------------

DirectX::WICCodecs OutputFormatToWicCodecs(OutputFormat format)
{
    switch (format)
    {
    case CanvasTex::OutputFormat::Png:
        return DirectX::WIC_CODEC_PNG;
    case CanvasTex::OutputFormat::Jpeg:
        return DirectX::WIC_CODEC_JPEG;
    case CanvasTex::OutputFormat::Bmp:
        return DirectX::WIC_CODEC_BMP;
    case CanvasTex::OutputFormat::Unknown:
    default:
        throw Spectre::Utils::SpectreException("CanvasTex::OutputFormatToWicCodecs - Unknown OutputFormat.");
    }
}

//---------------------------------------------------------------------------------------------------------------------

void SaveToMemory(
    const ConstImage& image,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::function<void(size_t, void*)>& postSaveCallback)
{
    if (outputFormat == OutputFormat::Png256)
    {
        auto saveCallback = [&outputFormat, &postSaveCallback](const ConstImage& imageToSave)
        {
            Microsoft::WRL::ComPtr<IStream> pStream;
            Spectre::Utils::ThrowIfFailed(CreateStreamOnHGlobal(nullptr, true, &pStream));

            Microsoft::WRL::ComPtr<IWICImagingFactory> pWicFactory;
            Spectre::Utils::ThrowIfFailed(Internal::GetImagingFactory(&pWicFactory));

            Microsoft::WRL::ComPtr<IWICStream> pWicStream;
            Spectre::Utils::ThrowIfFailed(pWicFactory->CreateStream(&pWicStream));
            Spectre::Utils::ThrowIfFailed(pWicStream->InitializeFromIStream(pStream.Get()));

            EncodeIndexedPngToStream(imageToSave, pWicFactory, pWicStream);

            STATSTG stats;
            Spectre::Utils::ThrowIfFailed(pStream->Stat(&stats, STATFLAG::STATFLAG_DEFAULT));

            if (stats.cbSize.HighPart > 0)
            {
                throw Spectre::Utils::SpectreException(HRESULT_FROM_WIN32(ERROR_FILE_TOO_LARGE), "The created PNG was too large");
            }

            // Note: this commented code avoids an extra copy of the Png data by accessing the
            // IStream's HGLOBAL. However, this requires UWP apps to be able to use GlobalLock
            // and GlobalUnlock Win32 functions which were not enabled until SDK version 15063.
            // Can be renabled once VS2015 support is no longer required.

            /*HGLOBAL hGlobal;
            Spectre::Utils::ThrowIfFailed(GetHGlobalFromStream(pStream.Get(), &hGlobal));

            {
                GlobalLockGuard globalLockGuard(hGlobal);

                if (auto data = globalLockGuard.m_lockedData)
                {
                    postSaveCallback(static_cast<size_t>(stats.cbSize.QuadPart), data);
                }
                else
                {
                throw Spectre::Utils::SpectreException(::GetLastError(), "Unable to lock HGLOBAL used during creation of indexed PNG");
                }
            }*/

            LARGE_INTEGER seekOffset = { { 0 } };
            Spectre::Utils::ThrowIfFailed(pStream->Seek(seekOffset, STREAM_SEEK_SET, nullptr));

            std::unique_ptr<uint8_t[]> buffer = std::make_unique<uint8_t[]>(stats.cbSize.LowPart);

            DWORD bytesRead;
            Spectre::Utils::ThrowIfFailed(pStream->Read(buffer.get(), stats.cbSize.LowPart, &bytesRead));

            if (bytesRead == stats.cbSize.LowPart)
            {
                postSaveCallback(stats.cbSize.LowPart, buffer.get());
            }
            else
            {
                throw Spectre::Utils::SpectreException(E_FAIL, "Unable to copy entire WIC stream to temporary buffer");
            }
        };

        PrepareAndProcess(image, outputTextureFormat, saveCallback);
    }
    else
    {
        // If the input format is BC3 and the output format is PNG, use PNG "None" filter for better compression
        std::function<void(IPropertyBag2*)> customProperties = nullptr;
        if (image.GetFormat() == TextureFormat::Bc3Unorm && outputFormat == OutputFormat::Png)
        {
            customProperties = GetPropsCallbackPngFilterNone();
        }

        auto saveCallback = [&outputFormat, &customProperties, &postSaveCallback](const ConstImage& imageToSave)
        {
            DirectX::Blob blob;
            Spectre::Utils::ThrowIfFailed(
                DirectX::SaveToWICMemory(
                    imageToSave.CGetImplementation(),
                    DirectX::WIC_FLAGS_NONE,
                    DirectX::GetWICCodec(OutputFormatToWicCodecs(outputFormat)),
                    blob,
                    nullptr,
                    customProperties),
                "CanvasTex::SaveToMemory - SaveToWICMemory failed");

            postSaveCallback(blob.GetBufferSize(), blob.GetBufferPointer());
        };

        PrepareAndProcess(image, outputTextureFormat, saveCallback);
    }
}

void SaveToMemory(
    const ScratchImage& images,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::function<void(size_t, void*)>& postSaveCallback)
{
    if (outputFormat == OutputFormat::DDS)
    {
        auto& imagesImpl = images.CGetImplementation();

        DirectX::Blob blob;
        Spectre::Utils::ThrowIfFailed(
            DirectX::SaveToDDSMemory(
                imagesImpl.GetImages(),
                imagesImpl.GetImageCount(),
                imagesImpl.GetMetadata(),
                DirectX::DDS_FLAGS::DDS_FLAGS_NONE,
                blob),
            "CanvasTex::GenerateMipMappedImage - SaveToDDSMemory failed");

        postSaveCallback(blob.GetBufferSize(), blob.GetBufferPointer());
    }
    else
    {
        if (images.GetImageCount() > 1)
        {
            throw Spectre::Utils::SpectreException("ImageCount > 1 only supported for DDS");
        }

        SaveToMemory(images.GetImage(0, 0), outputTextureFormat, outputFormat, postSaveCallback);
    }
}

//---------------------------------------------------------------------------------------------------------------------

void SaveToFile(
    const ConstImage& image,
    TextureFormat outputTextureFormat,
    OutputFormat outputFormat,
    const std::wstring& fileName)
{
    if (outputFormat == OutputFormat::Png256)
    {
        auto saveCallback = [&outputFormat, &fileName](const ConstImage& imageToSave)
        {
            Microsoft::WRL::ComPtr<IWICImagingFactory> pWicFactory;
            Spectre::Utils::ThrowIfFailed(Internal::GetImagingFactory(&pWicFactory));

            Microsoft::WRL::ComPtr<IWICStream> pWicStream;
            Spectre::Utils::ThrowIfFailed(pWicFactory->CreateStream(&pWicStream));
            Spectre::Utils::ThrowIfFailed(pWicStream->InitializeFromFilename(fileName.c_str(), GENERIC_WRITE));

            EncodeIndexedPngToStream(imageToSave, pWicFactory, pWicStream);
        };

        PrepareAndProcess(image, outputTextureFormat, saveCallback);
    }
    else
    {
        // If the input format is BC3 and the output format is PNG, use PNG "None" filter for better compression
        std::function<void(IPropertyBag2*)> customProperties = nullptr;
        if (image.GetFormat() == TextureFormat::Bc3Unorm && outputFormat == OutputFormat::Png)
        {
            customProperties = GetPropsCallbackPngFilterNone();
        }

        auto saveCallback = [&outputFormat, &fileName, &customProperties](const ConstImage& imageToSave)
        {
            Spectre::Utils::ThrowIfFailed(
                DirectX::SaveToWICFile(
                    imageToSave.CGetImplementation(),
                    DirectX::WIC_FLAGS_NONE,
                    DirectX::GetWICCodec(OutputFormatToWicCodecs(outputFormat)),
                    fileName.empty() ? nullptr : fileName.c_str(),
                    nullptr,
                    customProperties),
                "CanvasTex::SaveToFile - SaveToWICFile failed");
        };

        PrepareAndProcess(image, outputTextureFormat, saveCallback);
    }
}

//---------------------------------------------------------------------------------------------------------------------

void Resize(
    const ConstImage& srcImage,
    size_t width,
    size_t height,
    ScratchImage& image)
{
    Spectre::Utils::ThrowIfFailed(
        DirectX::Resize(
            srcImage.CGetImplementation(),
            width,
            height,
            DirectX::TEX_FILTER_FANT,
            image.GetImplementation()),
        "CanvasTex::Resize - Resize failed");
}

//---------------------------------------------------------------------------------------------------------------------

void Convert(
    const ConstImage& srcImage,
    TextureFormat format,
    ScratchImage& image)
{
    Spectre::Utils::ThrowIfFailed(
        DirectX::Convert(
            srcImage.CGetImplementation(),
            Internal::TextureFormatToDxgiFormat(format),
            DirectX::TEX_FILTER_DEFAULT,
            DirectX::TEX_THRESHOLD_DEFAULT,
            image.GetImplementation()),
        "CanvasTex::Convert - Conversion failed");
}

//---------------------------------------------------------------------------------------------------------------------

void Decompress(
    const ConstImage& cImage,
    TextureFormat format,
    ScratchImage& image)
{
    Spectre::Utils::ThrowIfFailed(
        DirectX::Decompress(
            cImage.CGetImplementation(),
            Internal::TextureFormatToDxgiFormat(format),
            image.GetImplementation()),
        "CanvasTex::Decompress - Decompression failed"
    );
}

//---------------------------------------------------------------------------------------------------------------------

DWORD CompressionOptionsToDirectXTex(CompressionOptions options)
{
    if (options == CompressionOptions::Bc7Use3Subsets)
    {
        return DirectX::TEX_COMPRESS_BC7_USE_3SUBSETS;
    }

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------

void Compress(
    const ConstImage& srcImage,
    TextureFormat format,
    CompressionOptions compressionOptions,
    bool useGpu,
    ScratchImage& cImage)
{
    DWORD compress = CompressionOptionsToDirectXTex(compressionOptions);

    Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
    if (format == TextureFormat::Bc7Unorm &&
        useGpu &&
        Internal::CreateDXDevice(&pDevice))
    {
        Spectre::Utils::ThrowIfFailed(
            DirectX::Compress(
                pDevice.Get(),
                srcImage.CGetImplementation(),
                Internal::TextureFormatToDxgiFormat(format),
                compress,
                0,
                cImage.GetImplementation()),
            "CanvasTex::Compress - GPU BC7 compression failed");
    }
    else
    {
        Spectre::Utils::ThrowIfFailed(
            DirectX::Compress(
                srcImage.CGetImplementation(),
                Internal::TextureFormatToDxgiFormat(format),
                0,
                0,
                cImage.GetImplementation()),
            "CanvasTex::Compress - Compression failed");
    }
}

void Compress(
    const ScratchImage& srcImages,
    TextureFormat format,
    ScratchImage& outImages,
    bool useGpu
)
{
    auto& srcImagesImpl = srcImages.CGetImplementation();

    Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
    if (useGpu && Internal::CreateDXDevice(&pDevice))
    {
        Spectre::Utils::ThrowIfFailed(
            DirectX::Compress(
                pDevice.Get(),
                srcImagesImpl.GetImages(),
                srcImagesImpl.GetImageCount(),
                srcImagesImpl.GetMetadata(),
                Internal::TextureFormatToDxgiFormat(format),
                DirectX::TEX_COMPRESS_DEFAULT,
                1,
                outImages.GetImplementation()),
            "CanvasTex::GenerateMipMappedImage - Compress failed");
    }
    else
    {
        Spectre::Utils::ThrowIfFailed(
            DirectX::Compress(
                srcImagesImpl.GetImages(),
                srcImagesImpl.GetImageCount(),
                srcImagesImpl.GetMetadata(),
                Internal::TextureFormatToDxgiFormat(format),
                DirectX::TEX_COMPRESS_DEFAULT,
                1,
                outImages.GetImplementation()),
            "CanvasTex::GenerateMipMappedImage - Compress failed");
    }
}

//---------------------------------------------------------------------------------------------------------------------

void GenerateMipMaps(
    const ConstImage& baseImage,
    ScratchImage& mipChain,
    FilterOptions filterOptions)
{
    Spectre::Utils::ThrowIfFailed(
        DirectX::GenerateMipMaps(
            baseImage.CGetImplementation(),
            FilterOptionsToTexFilterFlags(filterOptions),
            0,
            mipChain.GetImplementation()),
        "CanvasTex::GenerateMipMaps - Failed to generate MIP chain");
}

}  // namespace CanvasTex
