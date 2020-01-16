/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

namespace Babylon {
    namespace Transcoder {
        enum class MtlLineType
        {
            newmtl = 1,

            // Texture maps
            TextureDiffuse = 2,
            TextureSpecular,
            TextureEmissive,
            TextureNormal,
            TextureDetail,

            // Material Color and illumination statements
            ColorDiffuse,
            Opacity,
            ColorSpecular,
            SpecularExponent,

            // Not supported lines
            //map_Ns, // Specular
            //disp, // Scalar texture used to deform the surface
            //decal, // Scalar {"", procedural texture} file texture used to replace the material color with the texture color
            //refl,
            //Ni, // Optical density
            //d, // Dissolve
            //illum, // Illumination Model
            //Tf, // Transmission Filter
            //sharpness, // Sharpness of Reflections
        };
    }
}