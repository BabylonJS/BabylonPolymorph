/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#define COREUTILS_ICURVE_H_INCLUDED

namespace Spectre
{
    namespace Utils
    {
        namespace Tweening
        {
            /// \brief ICurve provides interface for interpolating from A to B using various shapes
            class ICurve
            {
            public:

                /// This is the function that will be implemented by various classes
                /// to provide different time interpolation curves.
                virtual double Remap(double progress) const = 0;

                virtual ~ICurve()
                {
                }
            };

        }// end Tweening
    } // end Utils
}// end Spectre

#endif // COREUTILS_ICURVE_H_INCLUDED
