/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "ITweenable.h"

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#include "ICurve.h"
#endif // COREUTILS_ICURVE_H_INCLUDED

#include "TweenOptions.h"

#if !defined(COREUTILS_ASSERT_H_INCLUDED)
#include "../Assert.h"
#endif // COREUTILS_ASSERT_H_INCLUDED

#if !defined(_ATOMIC_)
#include <atomic>
#endif // _ATOMIC_

#if !defined(_CHRONO_)
#include <chrono>
#endif // _CHRONO_

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            /// \brief Tween struct provides a context for the Tween session and API for cancellation
            ///
            /// Tween is created by TweenManager and returned as a shared pointer to callers.
            /// Tween struct contains context data that is used internally by TweenManager and
            /// cancellation API that can be used by the callers should they wish to stop the animation.
            class Tween
            {
                friend class TweenManager;

            public:
                /// Tween can be canceled at any time after it's created
                /// If tween is canceled FinishedCallback will be triggered,
                /// as long as tween has not been finished already
                void Cancel()
                {
                    Cancelled = true;
                }

            private:
                /// A constructor
                ///
                /// \param options - tween options containing all data required to create a tween
                /// \param curve - shared pointer to ICurve implementation with shape of the interpolation
                template<class T>
                Tween(TweenOptions<T> options, std::unique_ptr<ICurve> curve) :
                    Curve(std::move(curve)),
                    LoopDuration(options.LoopDuration),
                    LoopCount(options.LoopCount),
                    LoopType(options.LoopType),
                    ProgressCallback(options.ProgressCallback),
                    FinishedCallback(options.FinishedCallback),
                    Cancelled(false)
                {
                }

                std::unique_ptr<ICurve>                 Curve;          ///<    Shared pointer to interpolation curve
                std::chrono::steady_clock::time_point   StartTime;      ///<    Start time assigned to tween on the construction
                std::chrono::steady_clock::duration     LoopDuration;   ///<    Duration of tween's single loop , passed from TweenOptions<T>
                int                                     LoopCount;      ///<    Number of loops, each of LoopDuration, passed from TweenOptions<T>
                TweenLoopType                           LoopType;       ///<    Looping type passed from TweenOptions<T>
                std::unique_ptr<ITweenable>             TweenableType;  ///<   In order for a variable to be tweenable it must implement ITweenable interface, look for TweenProperty for more info

                const std::function<void(double)>       ProgressCallback;   ///<    Progress callback passed from TweenOptions, progress argument is in range 0-1, 0 meaning position is at begin value, 1 value is at end value
                const std::function<void()>             FinishedCallback;   ///<    Progress callback passed from TweenOptions

                std::atomic<bool>                       Cancelled;          ///<    Cancellation flag
            };
        }// end Tweening
    }// end Utils
}// end Babylon
