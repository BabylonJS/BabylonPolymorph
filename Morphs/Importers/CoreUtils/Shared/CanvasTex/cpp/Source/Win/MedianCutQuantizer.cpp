/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CanvasTexPch.h"

#include "MedianCutQuantizer.h"

#include <algorithm>
#include <tuple>
#include <vector>
#include <list>
#include <ostream>
#include <map>

#include <wrl/client.h>

#include <CoreUtils/Assert.h>
#include <CoreUtils/SmartThrow.h>

#include "WindowsCommon.h"


namespace
{
    // Do not automatically add colors to the palette based on coverage if they are this
    // close to another color already in the palette which occurs more frequently
    static constexpr uint32_t kMaxDistPalette = 16;

    // Discord any colors that are this close to other colors already in the palette
    // before performing median cut.
    static constexpr uint32_t kMaxDistMedianCut = 512;

    struct ColorBGRA
    {
        ColorBGRA(uint8_t b, uint8_t g, uint8_t r, uint8_t a) :
            b(b), g(g), r(r), a(a)
        {
        }

        ColorBGRA(uint32_t bgra) :
            b(static_cast<uint8_t>(bgra >> 24)),
            g(static_cast<uint8_t>(bgra >> 16)),
            r(static_cast<uint8_t>(bgra >> 8)),
            a(static_cast<uint8_t>(bgra >> 0))
        {
        }

        static uint32_t Distance(const ColorBGRA& lhs, const ColorBGRA& rhs)
        {
            const auto bDiff = lhs.b - rhs.b;
            const auto gDiff = lhs.g - rhs.g;
            const auto rDiff = lhs.r - rhs.r;
            const auto aDiff = lhs.a - rhs.a;

            return
                2 * bDiff * bDiff +
                4 * gDiff * gDiff +
                3 * rDiff * rDiff +
                1 * aDiff * aDiff;
        }

        uint32_t ToUint32() const
        {
            return a << 24 | r << 16 | g << 8 | b;
        }

        uint8_t MaxComponentValue() const
        {
            return std::max({ b, g, r, a });
        }

        bool operator<(const ColorBGRA& other) const
        {
            return std::tie(b, g, r, a) < std::tie(other.b, other.g, other.r, other.a);
        }

        bool operator==(const ColorBGRA& other) const
        {
            return std::tie(b, g, r, a) == std::tie(other.b, other.g, other.r, other.a);
        }

        uint8_t b;
        uint8_t g;
        uint8_t r;
        uint8_t a;
    };

    struct Color
    {
        Color(const float b, const float g, const float r, const float a) :
            b(b),
            g(g),
            r(r),
            a(a)
        {
        }

        explicit Color(const ColorBGRA& color) :
            b(color.b / 255.0f),
            g(color.g / 255.0f),
            r(color.r / 255.0f),
            a(color.a / 255.0f)
        {
        }

        Color Clamped() const
        {
            return Color(
                std::min(1.0f, std::max(0.0f, b)),
                std::min(1.0f, std::max(0.0f, g)),
                std::min(1.0f, std::max(0.0f, r)),
                std::min(1.0f, std::max(0.0f, a))
            );
        }

        ColorBGRA ToColorBGRA() const
        {
            return ColorBGRA(
                static_cast<uint8_t>(std::min(1.0f, std::max(0.0f, b)) * 255.0f + 0.5f),
                static_cast<uint8_t>(std::min(1.0f, std::max(0.0f, g)) * 255.0f + 0.5f),
                static_cast<uint8_t>(std::min(1.0f, std::max(0.0f, r)) * 255.0f + 0.5f),
                static_cast<uint8_t>(std::min(1.0f, std::max(0.0f, a)) * 255.0f + 0.5f)
            );
        }

        Color operator*(const float multiplier) const
        {
            return Color(b * multiplier, g * multiplier, r * multiplier, a * multiplier);
        }

        Color operator+(const Color& other) const
        {
            return Color(b + other.b, g + other.g, r + other.r, a + other.a);
        }

        Color operator-(const Color& other) const
        {
            return Color(b - other.b, g - other.g, r - other.r, a - other.a);
        }

        float b;
        float g;
        float r;
        float a;
    };

    struct ColorBounds
    {
        ColorBounds() :
            min(0xFFFFFFFF),
            max(0x00000000)
        {
        }

        void Extend(ColorBGRA color)
        {
            min.b = std::min(min.b, color.b);
            min.g = std::min(min.g, color.g);
            min.r = std::min(min.r, color.r);
            min.a = std::min(min.a, color.a);

            max.b = std::max(max.b, color.b);
            max.g = std::max(max.g, color.g);
            max.r = std::max(max.r, color.r);
            max.a = std::max(max.a, color.a);
        }

        ColorBGRA Dimensions() const
        {
            return ColorBGRA(max.b - min.b, max.g - min.g, max.r - min.r, max.a - min.a);
        }

        ColorBGRA min;
        ColorBGRA max;
    };

    struct ColorBox
    {
        ColorBox(const std::vector<ColorBGRA>& colors)
            : colors(colors)
        {
            for (auto& color : colors)
            {
                bounds.Extend(color);
            }
        }

        ColorBGRA CenterColor() const
        {
            return ColorBGRA(
                static_cast<uint8_t>((bounds.max.b + bounds.min.b) / 2),
                static_cast<uint8_t>((bounds.max.g + bounds.min.g) / 2),
                static_cast<uint8_t>((bounds.max.r + bounds.min.r) / 2),
                static_cast<uint8_t>((bounds.max.a + bounds.min.a) / 2)
            );
        }

        ColorBounds bounds;
        std::vector<ColorBGRA> colors;
    };

    // https://en.wikipedia.org/wiki/Median_cut
    std::list<ColorBox> MedianCut(ColorBox& box)
    {
        ColorBGRA dimensions = box.bounds.Dimensions();
        if (dimensions.a == dimensions.MaxComponentValue())
        {
            std::sort(box.colors.begin(), box.colors.end(), [](const ColorBGRA& lhs, const ColorBGRA& rhs) -> bool
            {
                return std::tie(lhs.a, lhs.g, lhs.r, lhs.b) < std::tie(rhs.a, rhs.g, rhs.r, rhs.b);
            });
        }
        else if (dimensions.g == dimensions.MaxComponentValue())
        {
            std::sort(box.colors.begin(), box.colors.end(), [](const ColorBGRA& lhs, const ColorBGRA& rhs) -> bool
            {
                return std::tie(lhs.g, lhs.a, lhs.r, lhs.b) < std::tie(rhs.g, rhs.a, rhs.r, rhs.b);
            });
        }
        else if (dimensions.r == dimensions.MaxComponentValue())
        {
            std::sort(box.colors.begin(), box.colors.end(), [](const ColorBGRA& lhs, const ColorBGRA& rhs) -> bool
            {
                return std::tie(lhs.r, lhs.a, lhs.g, lhs.b) < std::tie(rhs.r, rhs.a, rhs.g, rhs.b);
            });
        }
        else
        {
            std::sort(box.colors.begin(), box.colors.end(), [](const ColorBGRA& lhs, const ColorBGRA& rhs) -> bool
            {
                return std::tie(lhs.b, lhs.a, lhs.g, lhs.r) < std::tie(rhs.b, rhs.a, rhs.g, rhs.r);
            });
        }

        auto median = std::next(box.colors.begin(), box.colors.size() / 2);

        std::list<ColorBox> cut;
        cut.emplace_back(std::vector<ColorBGRA>(box.colors.begin(), median));
        cut.emplace_back(std::vector<ColorBGRA>(median, box.colors.end()));

        return cut;
    }

    std::vector<ColorBGRA> GetPalette(const std::vector<ColorBGRA>& colors, uint32_t nColors)
    {
        ColorBox fullBox(colors);

        std::list<ColorBox> boxes = MedianCut(fullBox);

        while (boxes.size() < nColors)
        {
            auto largestBoxIt = boxes.begin();

            for (auto it = boxes.begin(); it != boxes.end(); ++it)
            {
                auto& box = *it;
                if (box.bounds.Dimensions().MaxComponentValue() >= largestBoxIt->bounds.Dimensions().MaxComponentValue())
                {
                    largestBoxIt = it;
                }
            }

            auto split = MedianCut(*largestBoxIt);
            boxes.erase(largestBoxIt);
            boxes.splice(boxes.end(), split);
        }

        std::vector<ColorBGRA> paletteColors;
        for (auto& box : boxes)
        {
            paletteColors.push_back(box.CenterColor());
        }

        return paletteColors;
    }

    bool FindCloseColor(const std::vector<ColorBGRA>& palette, const ColorBGRA& color, const uint16_t maxDistance, uint8_t& index)
    {
        index = 0;
        for (auto paletteColor : palette)
        {
            if (ColorBGRA::Distance(color, paletteColor) < maxDistance)
            {
                return true;
            }
            index++;
        }
        return false;
    }

    uint8_t FindClosestColor(const std::vector<ColorBGRA>& palette, const ColorBGRA& color)
    {
        uint8_t closestMatch = 0;
        uint32_t matchDistance = std::numeric_limits<uint32_t>::max();

        uint8_t i = 0;
        for (auto& paletteColor : palette)
        {
            if (color == paletteColor)
            {
                return i;
            }

            uint32_t distance = ColorBGRA::Distance(color, paletteColor);

            if (distance < matchDistance)
            {
                closestMatch = i;
                matchDistance = distance;
            }
            i++;
        }
        return closestMatch;
    }

    // https://en.wikipedia.org/wiki/Floyd–Steinberg_dithering
    void ApplyFloydSteinbergDither(std::vector<Color>& colorsFloat, const Color& error, size_t index,
        const size_t width, const size_t height, const size_t x, const size_t y)
    {
        auto error7_16 = error * (7.0f / 16.0f);
        auto error3_16 = error * (3.0f / 16.0f);
        auto error5_16 = error * (5.0f / 16.0f);
        auto error1_16 = error * (1.0f / 16.0f);

        if (x + 1 < width)
        {
            colorsFloat[index + 1] = (colorsFloat[index + 1] + error7_16).Clamped();
        }

        if (y + 1 < height)
        {
            if (x - 1 > 0)
            {
                colorsFloat[index + width - 1] = (colorsFloat[index + width - 1] + error3_16).Clamped();
            }
            colorsFloat[index + width] = (colorsFloat[index + width] + error5_16).Clamped();
            if (x + 1 < width)
            {
                colorsFloat[index + width + 1] = (colorsFloat[index + width + 1] + error1_16).Clamped();
            }
        }
    }

    std::vector<uint8_t> DitherDiscardMatch(const std::vector<ColorBGRA>& colors, const std::vector<ColorBGRA>& palette, const size_t width, const size_t height)
    {
        // Optimization: https://www.linkedin.com/pulse/suppressing-floyd-steinberg-dithering-error-propagation-larry-bank
        // Maximum error where we will discard the error, this dramatically improves
        // processing time and also reduces the "speckles" issue, however a value which is
        // too large will cause banding like in an undithered image.
        //   64 = Definitely too large
        //   32 = Borderline
        //   16 = Very good
        // Best value is probably somewhere between 16 and 32
        const uint32_t kMaxDistDiscardError = 16;

        std::vector<Color> colorsFloat(colors.begin(), colors.end());
        std::vector<uint8_t> palettedImage(width * height);

        for (size_t y = 0; y < height; y++)
        {
            auto lineoffset = y * width;
            for (size_t x = 0; x < width; x++)
            {
                auto index = x + lineoffset;

                auto originalColor = colors[index];

                uint8_t matchIndex;
                auto match = FindCloseColor(palette, originalColor, kMaxDistDiscardError, matchIndex);

                if (match)
                {
                    palettedImage[index] = matchIndex;
                    continue;
                }

                // Dither step
                auto oldColor = colorsFloat[index].ToColorBGRA();

                auto closestColorIndex = FindClosestColor(palette, oldColor);
                palettedImage[index] = closestColorIndex;

                auto newColor = palette[closestColorIndex];

                auto error = Color(oldColor) - Color(newColor);

                ApplyFloydSteinbergDither(colorsFloat, error, index, width, height, x, y);
            }
        }

        return palettedImage;
    }

    bool ApplyPaletteToImage(
        IWICBitmap* pDest,
        const std::vector<ColorBGRA>& originalColors,
        const std::vector<ColorBGRA>& colorPalette,
        const size_t width,
        const size_t height)
    {
        Microsoft::WRL::ComPtr<IWICImagingFactory> pFactory;
        Babylon::Utils::ThrowIfFailed(CanvasTex::Internal::GetImagingFactory(&pFactory));

        auto palettedColors = DitherDiscardMatch(originalColors, colorPalette, width, height);

        Microsoft::WRL::ComPtr<IWICPalette> thePalette;
        Babylon::Utils::ThrowIfFailed(pFactory->CreatePalette(&thePalette));

        auto pColors = std::make_unique<WICColor[]>(colorPalette.size());

        size_t i = 0;
        for (auto& paletteColor : colorPalette)
        {
            pColors[i] = paletteColor.ToUint32();
            i++;
        }

        Babylon::Utils::ThrowIfFailed(thePalette->InitializeCustom(pColors.get(), static_cast<uint32_t>(colorPalette.size())));
        pDest->SetPalette(thePalette.Get());

        WICRect rect = { 0,0, (INT)width, (INT)height };
        Microsoft::WRL::ComPtr<IWICBitmapLock> targetData;
        Babylon::Utils::ThrowIfFailed(pDest->Lock(&rect, WICBitmapLockWrite, &targetData));

        UINT bufSize;
        UINT strideDest;
        BYTE *pRowDest;
        Babylon::Utils::ThrowIfFailed(targetData->GetDataPointer(&bufSize, &pRowDest));
        Babylon::Utils::ThrowIfFailed(targetData->GetStride(&strideDest));

        // Second loop: fill indexed bitmap
        int pixelIndex = 0;

        for (UINT y = 0; y < height; y++)    // For each row...
        {
            auto pPixelDest = pRowDest;

            for (UINT x = 0; x < width; x++)    // ...for each pixel...
            {
                uint8_t index = palettedColors[pixelIndex];
                pixelIndex++;

                // ...and put index in the destination bitmap.
                *pPixelDest++ = index;
            }

            pRowDest += strideDest;
        }

        return true;
    }
}

void CanvasTex::MedianCutQuantizer::QuantizeImage(const uint8_t* const sourceData, const size_t width, const size_t height, const size_t stride, IWICBitmap* const pDest, const uint32_t nMaxColors)
{
    // Only support palette of 2-256 colors
    BabylonAssert(nMaxColors >= 2);
    BabylonAssert(nMaxColors <= 256);

    std::vector<ColorBGRA> colors;
    colors.reserve(width * height);

    const uint8_t* rowSource = sourceData;

    // First loop: gather color information
    for (uint16_t y = 0; y < height; y++)    // For each row...
    {
        auto pPixelSource = rowSource;

        for (uint16_t x = 0; x < width; x++)    // ...for each pixel...
        {
            const uint8_t b = *pPixelSource++;
            const uint8_t g = *pPixelSource++;
            const uint8_t r = *pPixelSource++;
            const uint8_t a = *pPixelSource++;

            colors.emplace_back(b, g, r, a);
        }

        rowSource += stride;
    }

    // Count occurrences of each color
    std::map<ColorBGRA, uint32_t> colorCounts;
    for (const ColorBGRA& color : colors)
    {
        colorCounts[color]++;
    }

    std::vector<ColorBGRA> uniqueColors;
    for (auto& colorCount : colorCounts)
    {
        uniqueColors.push_back(colorCount.first);
    }

    std::vector<ColorBGRA> palette;

    if (uniqueColors.size() <= nMaxColors)
    {
        palette = std::move(uniqueColors);
    }
    else
    {
        std::vector<std::pair<ColorBGRA, uint32_t>> sortedColorCounts(colorCounts.begin(), colorCounts.end());
        std::sort(sortedColorCounts.begin(), sortedColorCounts.end(), [](const std::pair<ColorBGRA, uint32_t>& lhs, const std::pair<ColorBGRA, uint32_t>& rhs) -> bool
        {
            return lhs.second > rhs.second;
        });

        const auto paletteProportionalArea = width * height / nMaxColors;
        const auto halfPaletteProportionalArea = paletteProportionalArea / 2;
        std::vector<ColorBGRA> infrequentColors;
        for (auto& colorCount : sortedColorCounts)
        {
            if (colorCount.second > paletteProportionalArea)
            {
                // Covers more than 1/nMaxColors of the image so goes straight in the palette
                palette.push_back(colorCount.first);
            }
            else if (
                colorCount.second > halfPaletteProportionalArea &&
                palette.size() < nMaxColors / 2)
            {
                // Covers more than 1/(nMaxColors*2) of the image, goes in the palette if it's not super similar to colours we already put in
                bool closeMatch = false;
                for (auto& paletteColor : palette)
                {
                    if (ColorBGRA::Distance(colorCount.first, paletteColor) < kMaxDistPalette)
                    {
                        closeMatch = true;
                        break;
                    }
                }

                if (!closeMatch)
                {
                    palette.push_back(colorCount.first);
                }
            }
            else
            {
                infrequentColors.push_back(colorCount.first);
            }
        }

        auto colorIsWithinMaxDistMedianCut = [&palette](const ColorBGRA& value)
        {
            for (auto& paletteColor : palette)
            {
                if (ColorBGRA::Distance(value, paletteColor) < kMaxDistMedianCut)
                {
                    return true;
                }
            }

            return false;
        };

        infrequentColors.erase(
            std::remove_if(infrequentColors.begin(), infrequentColors.end(), colorIsWithinMaxDistMedianCut),
            infrequentColors.end());

        auto mc = GetPalette(std::vector<ColorBGRA>(infrequentColors.begin(), infrequentColors.end()), static_cast<uint32_t>(nMaxColors - palette.size()));
        palette.insert(palette.end(), mc.begin(), mc.end());
    }

    // Write the new image
    ApplyPaletteToImage(pDest, colors, palette, width, height);
}
