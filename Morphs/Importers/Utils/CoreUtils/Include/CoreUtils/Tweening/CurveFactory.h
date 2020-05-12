/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(_MEMORY_)
#include <memory>
#endif // _MEMORY_

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#include "ICurve.h"
#endif // COREUTILS_ICURVE_H_INCLUDED

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            enum class CurveType
            {
                Linear,
                QuadraticEaseIn,
                QuadraticEaseOut,
                QuadraticEaseInOut,
                ExponentiaEaseIn,
                ExponentiaEaseOut,
                ExponentiaEaseInOut,
                SineEaseIn,
                SineEaseOut,
                SineEaseInOut,
                BackEaseIn,
                BackEaseOut,
                BackEaseInOut,
                BounceEaseIn,
                BounceEaseOut,
                BounceEaseInOut,
                ElasticEaseIn,
                ElasticEaseOut,
                ElasticEaseInOut
            };

            class CurveFactory
            {
            public:
                std::unique_ptr<ICurve> GetCurve(CurveType type);
            };
        }// end Tweening
    } // end Utils
}// end Babylon
