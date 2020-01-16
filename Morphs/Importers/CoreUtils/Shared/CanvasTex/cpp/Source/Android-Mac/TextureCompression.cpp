//
// Copyright (C) Microsoft.  All rights reserved.
//

#include "TextureCompression.h"
#include "ScratchImage.h"
#include <CanvasTex/Image.h>
#include <gli/core/bc.hpp>
#include <gli/convert.hpp>

namespace
{

//---------------------------------------------------------------------------------------------------------------------

// TODO: Can we infer the BlockType from the DecompressFunction (which takes a BlockType* as argument)?
template <class BlockType, typename DecompressFunction>
gli::texture2d DecompressBcxUnorm(const CanvasTex::ConstImage& cImage, const gli::extent2d& blockExtent, DecompressFunction decompressFunction)
{
    auto impl = cImage.CGetImplementation();

    gli::texture2d outputTexture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::extent2d(cImage.GetWidth(), cImage.GetHeight()), 1);

    // TextureMetadataImplementation doesn't have miplevels?

    const BlockType* sourceDataAsBlock = reinterpret_cast<const BlockType*>(cImage.GetPixels());

    gli::extent2d TexelCoord;
    gli::extent2d BlockCoord;
    gli::extent2d LevelExtent(impl.width, impl.height);
    gli::extent2d LevelExtentInBlocks = glm::max(gli::extent2d(1, 1), LevelExtent / blockExtent);
    for(BlockCoord.y = 0, TexelCoord.y = 0; BlockCoord.y < LevelExtentInBlocks.y; ++BlockCoord.y, TexelCoord.y += blockExtent.y)
    {
        for(BlockCoord.x = 0, TexelCoord.x = 0; BlockCoord.x < LevelExtentInBlocks.x; ++BlockCoord.x, TexelCoord.x += blockExtent.x)
        {
            const BlockType *block = sourceDataAsBlock + (BlockCoord.y * LevelExtentInBlocks.x + BlockCoord.x);
            const gli::detail::texel_block4x4 DecompressedBlock = decompressFunction(*block);

            gli::extent2d DecompressedBlockCoord;
            for(DecompressedBlockCoord.y = 0; DecompressedBlockCoord.y < glm::min(4, LevelExtent.y); ++DecompressedBlockCoord.y)
            {
                for(DecompressedBlockCoord.x = 0; DecompressedBlockCoord.x < glm::min(4, LevelExtent.x); ++DecompressedBlockCoord.x)
                {
                    outputTexture.store(TexelCoord + DecompressedBlockCoord, 0, glm::u8vec4(glm::round(DecompressedBlock.Texel[DecompressedBlockCoord.y][DecompressedBlockCoord.x] * 255.0f)));
                }
            }
        }
    }

    return outputTexture;
}

} // namespace

namespace CanvasTex
{

//---------------------------------------------------------------------------------------------------------------------

gli::texture2d DecompressBc1Unorm(const ConstImage& cImage)
{
    gli::extent3d tempExtent = gli::block_extent(gli::FORMAT_RGBA_DXT1_UNORM_BLOCK8);
    gli::extent2d blockExtent(tempExtent.x, tempExtent.y);
    return DecompressBcxUnorm<gli::detail::bc1_block>(cImage, blockExtent, gli::detail::decompress_bc1_block);
}

//---------------------------------------------------------------------------------------------------------------------

gli::texture2d DecompressBc2Unorm(const ConstImage& cImage)
{
    gli::extent3d tempExtent = gli::block_extent(gli::FORMAT_RGBA_DXT3_UNORM_BLOCK16);
    gli::extent2d blockExtent(tempExtent.x, tempExtent.y);
    return DecompressBcxUnorm<gli::detail::bc2_block>(cImage, blockExtent, gli::detail::decompress_bc2_block);
}

//---------------------------------------------------------------------------------------------------------------------

gli::texture2d DecompressBc3Unorm(const ConstImage& cImage)
{
    gli::extent3d tempExtent = gli::block_extent(gli::FORMAT_RGBA_DXT5_UNORM_BLOCK16);
    gli::extent2d blockExtent(tempExtent.x, tempExtent.y);
    return DecompressBcxUnorm<gli::detail::bc3_block>(cImage, blockExtent, gli::detail::decompress_bc3_block);
}

} // namespace CanvasTex
