/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "Tween.h"
#include "TweenProperty.h"

#include "../DirectProperty.h"

#if !defined(COREUTILS_ICURVE_H_INCLUDED)
#include "ICurve.h"
#endif // COREUTILS_ICURVE_H_INCLUDED

#include "CurveFactory.h"

namespace Spectre
{
    namespace Utils
    {
        namespace Tweening
        {
            /// \enum Different types of looping
            enum class TweenLoopType
            {
                Repeat,     ///< Animation goes from A to B (each A to B animation will take a duration time)
                Bounce      ///< Animation will go from A to B, then change direction and go from B to A, the process will repeat
                            ///< (each A to B, B to A animation will take a duration time)
            };

            /// \enum Direction of the tweening
            enum class TweenDirection
            {
                /// These only really matter for wrapping tweens that don't exist in an infinite space.
                /// Points, Colors and Vectors will always take the shortest path.
                /// Rotations will take the given direction i.e shortest rotation will always be less than 180degrees.
                /// Going the longest distance will include any full rotations.
                Natural,    /// Take the natural path from the current value to the request value, numerically...
                Shortest    /// Take the shortest path from the current value to the requested value.
            };

            /// \brief TweenOptions struct is a container of data required to create a tween
            ///
            /// In order to create a tween you must create a TweenOptions<T> struct where T is type of the variable that you want
            /// to animate. TweenOptions have two constructors that assign required data. The rest of the data members are set to
            /// default values.
            ///
            /// Once TweenOptions<T> struct is created, it can be passed to TweenManager to create a Tween.
            template<class T>
            struct TweenOptions
            {
                /// A constructor
                ///
                /// \param value - shared pointer to variable that we want to animate
                /// \param animationFinalValue - The final value of the animated variable.
                /// \param direction - How the tween should get from the current value to the final value
                ///         TweenDirection::Natural will take the natural numerical path between the two value.
                ///         TweenDirection::Shortest will take the shortest path between the two values.
                ///
                ///         Point, Colors and vectors don't have a shorter path than the natural given path as
                ///         they live in an infinite space.
                ///         Rotations however live in a finite space from 0 to 359 degrees. An orientation of 270 degrees
                ///         around an axis can also be interpreted as a -90 degree rotation around the same axis. 270 degrees
                ///         is the natural path and -90 degrees is the shortest path.
                TweenOptions(
                    std::shared_ptr<T> const& value,
                    T animationFinalValue,
                    TweenDirection direction) :
                    Value(value),
                    Property(nullptr),
                    FinalValue(animationFinalValue),
                    Direction(direction),
                    LoopDuration(std::chrono::seconds(1)),
                    LoopCount(1),
                    LoopType(Tweening::TweenLoopType::Repeat),
                    ProgressCallback(nullptr),
                    FinishedCallback(nullptr)
                {
                }

                /// A constructor
                ///
                /// \param prop - shared pointer to Property of the variable that we want to animate
                /// \param animationFinalValue - The final value of the animated variable.
                /// \param direction - How the tween should get from the current value to the final value
                ///         TweenDirection::Natural will take the natural numerical path between the two value.
                ///         TweenDirection::Shortest will take the shortest path between the two values.
                ///
                ///         Point, Colors and vectors don't have a shorter path than the natural given path as
                ///         they live in an infinite space.
                ///         Rotations however live in a finite space from 0 to 359 degrees. An orientation of 270 degrees
                ///         around an axis can also be interpreted as a -90 degree rotation around the same axis. 270 degrees
                ///         is the natural path and -90 degrees is the shortest path.
                TweenOptions(
                    std::shared_ptr<IProperty<T>> const& prop,
                    T animationFinalValue,
                    TweenDirection direction) :
                    Value(nullptr),
                    Property(prop),
                    FinalValue(animationFinalValue),
                    Direction(direction),
                    LoopDuration(std::chrono::seconds(1)),
                    LoopCount(1),
                    LoopType(Tweening::TweenLoopType::Repeat),
                    ProgressCallback(nullptr),
                    FinishedCallback(nullptr)
                {
                }

                std::shared_ptr<T>                              Value;        ///<    Shared pointer to variable that we want to tween, Value or Property should be set, not both
                std::shared_ptr<IProperty<T>>                   Property;     ///<    Shared pointer to property that we want to tween, Value or Property should be set, not both
                T                                               FinalValue;   ///<    Value of where animation should end

                ///     How the tween should get from the current value to the final value
                ///     TweenDirection::Natural will take the natural numerical path between the two value.
                ///     TweenDirection::Shortest will take the shortest path between the two values.
                ///
                ///     Point, Colors and vectors don't have a shorter path than the natural given path as
                ///     they live in an infinite space.
                ///     Rotations however live in a finite space from 0 to 359 degrees. An orientation of 270 degrees
                ///     around an axis can also be interpreted as a -90 degree rotation around the same axis. 270 degrees
                ///     is the natural path and -90 degrees is the shortest path.
                TweenDirection                                  Direction;

                std::chrono::high_resolution_clock::duration    LoopDuration; ///<    Duration of a single loop of a tween, by default 1 second
                int                                             LoopCount;    ///<    Number of loops, each of LoopDuration, by default 1
                TweenLoopType                                   LoopType;     ///<    Type of looping, by default no looping
                std::function<void(double)>                     ProgressCallback; ///<    Callback that returns progress in range 0-1, where 0 if animation value is at begin position, and 1 if animation value is at the end position
                std::function<void()>                           FinishedCallback; ///<    Callback triggered when animation finished. If looping is enabled it will only be triggered if Tween is cancelled.
            };

        }// end Tweening
    }// end Utils
}// end Spectre
