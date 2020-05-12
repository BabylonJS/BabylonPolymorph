/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#include "ICurve.h"
#endif // COREUTILS_ICURVE_H_INCLUDED

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            /// \brief ITweenable class provides interface that all tweenable types must implement
            class ITweenable
            {
            public:
                virtual ~ITweenable() = default;

                /// Tween interface specifies how custom types should be animated
                /// \param value - time progress where 0 is start and 1 is end
                /// \param curve - interface that provides mechanism for interpolation
                /// \returns True if underlying variable is alive or False if no one hold strong reference to it
                virtual bool Tween(double value, const ICurve* curve) = 0;
            };

        }// end Tweening
    } // end Utils
}// end Babylon
