/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "Tween.h"
#include "TweenProperty.h"
#include "../Pointers.h"
#include "../Property.h"

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#include "ICurve.h"
#endif // COREUTILS_ICURVE_H_INCLUDED

#include "CurveFactory.h"
#include "TweenOptions.h"

#if !defined(_MUTEX_)
#include <mutex>
#endif // _MUTEX_

#if !defined(_MEMORY_)
#include <memory>
#endif // _MEMORY_

namespace Babylon
{
    namespace Utils
    {
        namespace Tweening
        {
            /// \brief IClock is a simple interface for getting current time
            struct IClock
            {
                virtual std::chrono::time_point<std::chrono::high_resolution_clock> Now() = 0;
                virtual ~IClock() = default;
            };

            // Allow some types to have template specializations to allow their own pre-processing
            // of input. For example a Quaternion will want to decide what the to value is depending
            // on whether the client has asked to go shortest or longest distance between the values.
            template <typename T>
            void ApplyTweenPreprocess(T& from, T& to, TweenDirection tweenDirection)
            {
                BabylonUnusedParameter(from);
                BabylonUnusedParameter(to);
                BabylonUnusedParameter(tweenDirection);
            }
            /// \brief HighPerfClock implements IClock interface
            ///
            /// HighPerfClock is a default implementation used by TweenManager.
            struct HighPerfClock : IClock
            {
                virtual ~HighPerfClock() = default;

                virtual std::chrono::time_point<std::chrono::high_resolution_clock> Now()
                {
                    return std::chrono::high_resolution_clock::now();
                }
            };

            /// \brief TweenManager is responsible for creating and updating tweens
            ///
            /// TweenManager provides a simple API for creating and updating tweens.
            /// To create tween, call CreateTween API passing tween options and type of interpolation curve.
            /// Tweens are stored internally and are all updated when Update API is called.
            class TweenManager
            {
            public:
                /// A constructor
                ///
                /// \param internalClock - shared pointer to IClock implementation
                ///         by default creates HighPerfClock which is using standard chrono clock
                explicit TweenManager(std::shared_ptr<IClock> internalClock = std::make_shared<HighPerfClock>())  :
                    m_internalClock(internalClock)
                {
                }

                /// Update function should be called to update all the tweets, sort of tick function
                void Update();


                /// CreateTween creates Tween, adds it to internal list and returns a handle to the caller
                ///
                /// \param options - collection of options needed to create a tween
                /// \param curveType - type of the interpolation to use for tweening
                /// \param transformFunction - transformation for converting data to and from internal interpolation type
                ///     using DefaultTransformation by default, which is only a pass-through
                /// \returns tween - shared pointer to Tween, that can be used for cancellation
                template <typename T, typename Transformation = Tweening::TransformationDefault<T>>
                TweenPtr CreateTween(
                    const TweenOptions<T>&  options,
                    CurveType               curveType,
                    Transformation          transformFunction = Transformation())
                {
                    return CreateTween(options, m_curveFactory.GetCurve(curveType), transformFunction);
                }

                /// CreateTween creates Tween, adds it to internal list and returns a handle to the caller
                ///
                /// \param options - collection of options needed to create a tween
                /// \param curve - the interpolation curve to use for tweening
                /// \param transformFunction - transformation for converting data to and from internal interpolation type
                ///     using DefaultTransformation by default, which is only a pass-through
                /// \returns tween - shared pointer to Tween, that can be used for cancellation
                template <typename T, typename Transformation = Tweening::TransformationDefault<T>>
                TweenPtr CreateTween(
                    const TweenOptions<T>&  options,
                    std::unique_ptr<ICurve> curve,
                    Transformation          transformFunction = Transformation())
                {
                    auto tween = TweenPtr(new Tween(options, std::move(curve)));
                    tween->StartTime = m_internalClock->Now();

                    if (options.Value != nullptr)
                    {
                        auto const& value = *(options.Value); // Get the underlying value;
                        auto from = value;
                        auto to = options.FinalValue;

                        ApplyTweenPreprocess(from, to, options.Direction);
                        tween->TweenableType = GetTweenProperty(options.Value, from, to, transformFunction);
                    }
                    else if (options.Property != nullptr)
                    {
                        auto const& propertyValue = *(options.Property); //   Get the underlying Property<T>
                        auto from = propertyValue.Get();
                        auto to = options.FinalValue;

                        ApplyTweenPreprocess(from, to, options.Direction);
                        tween->TweenableType = GetTweenProperty(options.Property, from, to, transformFunction);
                    }
                    else
                    {
                        throw BabylonException("Tween options must have either value or property not null");
                    }

                    // Add the new tween to the staging vector to be added to m_tweens at the next update
                    {
                        std::lock_guard<std::mutex> lock(m_mutex);
                        m_tweensToAdd.push_back(tween);
                    }

                    return tween;
                }

            private:
                std::vector<TweenPtr> m_tweens;                 ///< List of active tweens
                std::vector<TweenPtr> m_tweensToAdd;            ///< List of tweens added between calls to update.
                CurveFactory            m_curveFactory;         ///< Factory to create ICurve* from curve type enumeration
                std::mutex              m_mutex;
                std::shared_ptr<IClock> m_internalClock;
            };
        }// end Tweening
    }// end Utils
}// end Babylon
