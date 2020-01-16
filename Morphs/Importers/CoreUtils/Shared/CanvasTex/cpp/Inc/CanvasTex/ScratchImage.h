/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include <CanvasTex/Format.h>
#include <CanvasTex/Image.h>
#include <CanvasTex/TextureMetadata.h>
#include <CoreUtils/Optional.h>
#include <memory>

namespace CanvasTex
{
    class ScratchImage final
    {
    public:
        class ScratchImageImplementation;

        ScratchImage();
        ~ScratchImage();

        ScratchImage(const ScratchImage& other) = delete;
        ScratchImage& operator=(const ScratchImage& other) = delete;

        ScratchImage(ScratchImage&& other);
        ScratchImage& operator=(ScratchImage&& other);

        void InitializeFromImage(const Image& srcImage);

        void Release();

        ConstTextureMetadata GetMetadata() const;

        ConstImage GetImage(size_t item, size_t mip) const;

        size_t GetImageCount() const;

        const uint8_t* GetPixels() const;
        uint8_t* GetPixels();

        size_t GetPixelsSize() const;

        ScratchImageImplementation& GetImplementation();
        const ScratchImageImplementation& CGetImplementation() const;

    private:
        std::shared_ptr<ScratchImageImplementation> m_impl;
    };
}  // namespace CanvasTex
