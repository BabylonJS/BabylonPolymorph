/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#include "ITweenable.h"

#include <CoreUtils/DirectProperty.h>
#include <CoreUtils/IndirectProperty.h>

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

#if !defined(_MEMORY_)
#include <memory>
#endif // _MEMORY_

#include <cmath>

namespace Spectre
{
    namespace Utils
    {
        namespace Tweening
        {
            /// Transform class is used by TweenProperty to convert
            /// tweened data to different space for the interpolation.
            /// Going to spherical coordinate system is an example.
            /// Default transformation class works as a simple pass through,
            /// no values are changed.
            /// In order to create you own transformation add class
            /// that implements Input and Output conversions to your type.
            /// Trans
            template<class T>
            class TransformationDefault
            {
            public:
                T Input(T v)
                {
                    return v;
                }

                T Output(T v)
                {
                    return v;
                }
            };

            template<typename T>
            inline T RoundToNearestRepresentable(double value)
            {
                static_assert(std::is_integral<T>::value, "T must be of an integral type");
                return static_cast<T>(std::round(value));
            }

            template<>
            inline double RoundToNearestRepresentable(double value)
            {
                return value;
            }

            template<>
            inline float RoundToNearestRepresentable(double value)
            {
                return static_cast<float>(value);
            }

            /// Interpolation template function for type T
            /// If you want to tween your user default type you must implement
            /// specialization of this function for your type
            /// See TweenPropertySpecializations.h for a reference
            template<typename T>
            T Interpolate(T from, T to, double remappedTime)
            {
                return RoundToNearestRepresentable<T>((to - from) * remappedTime + from);
            }

            /// \brief TweenPropertyBase is a base class for all animated properties that implements ITweenable interface
            ///
            /// TweenProperty contains all the context required for tweening i.e. start value, end value and animated property
            /// or animated value - this class works with both properties and plain types.
            /// In order to create Tween on TweenManager we must create TweenProperty<T>.
            /// If you want to tween a user defined type, you must create function template specialization for Interpolate
            /// function for your type that is called in Tween() function. See TweenPropertySpecializations.h for a reference.
            template <typename T, typename Transformation = TransformationDefault<T>>
            class TweenProperty : public ITweenable
            {
            public:
                friend class TweenManager;

                /// A constructor
                /// \param value - shared pointer to property of T type that we want to animate
                /// \param from - start value of animation
                /// \param to - end value of animation
                TweenProperty(const std::shared_ptr<IProperty<T>>& value,
                                  T from,
                                  T to,
                                  Transformation transform = Transformation()) :
                    m_property(value),
                    m_from(from),
                    m_to(to),
                    m_transform(transform)
                {
                    m_from = m_transform.Input(m_from);
                    m_to = m_transform.Input(m_to);
                }

                /// A constructor
                /// \param value - shared pointer to value of T type that we want to animate
                /// \param from - start value of animation
                /// \param to - end value of animation
                TweenProperty(const std::shared_ptr<T>& value,
                                  T from,
                                  T to,
                                  Transformation transform = Transformation()) :
                    m_value(value),
                    m_from(from),
                    m_to(to),
                    m_transform(transform)
                {
                    m_from =    m_transform.Input(m_from);
                    m_to =      m_transform.Input(m_to);
                }

                virtual ~TweenProperty() = default;

            protected:
                /// This function does 3 things:
                /// 1. Remaps time using curve
                /// 2. Interpolates value using remapped time
                /// 3. Updates current value

                /// \param normalizedTimeProgress - normalized time coming in range 0-1, where 0 means start and 1 end of the animation
                /// \param curve - interpolation shape
                /// \returns True if bound variable is still alive and False if no one holds strong reference to it
                virtual bool Tween(double normalizedTimeProgress, const ICurve* curve) override
                {
                    /// Remap time using chosen curve
                    auto remappedTime = curve->Remap(normalizedTimeProgress);

                    /// Interpolate between from and to values
                    auto newValue = Interpolate(m_from, m_to, remappedTime);

                    /// Set new value
                    return Set(newValue);
                }

                /// This function will check if tweened value is still alive,
                /// then it will convert value from internal interpolation  to output space
                /// and then update the underlying value.
                /// \param newValue - new internal interpolation value
                /// \returns True if value is still alive, or False if underlying data has expired
                bool Set(T newValue)
                {
                    /// TweenProperty always uses m_value OR m_propery
                    ///     which means one of these weak pointers gets assigned nullptr in the constructor
                    /// expired() is used here to check two cases:
                    ///  a) if weak_ptr was assigned to nullptr
                    ///  b) if weak_ptr is pointing to shared_ptr that is no longer shared
                    if (m_property.expired() && m_value.expired())
                    {
                        return false;
                    }

                    newValue = m_transform.Output(newValue);

                    if (auto prop = m_property.lock())
                    {
                        prop->Set(newValue);
                    }
                    else if (auto value = m_value.lock())
                    {
                        *value = newValue;
                    }
                    return true;
                }

                std::weak_ptr<IProperty<T>> m_property; ///<    property to be animated. Either property or value is set - not both.
                std::weak_ptr<T>            m_value;    ///<    value to be animated. Either property or value is set - not both.
                T                           m_from;     ///<    start value of the tween
                T                           m_to;       ///<    end value of the tween
                Transformation              m_transform;///<    Transformation class is used to convert data to internal format
                                                        ///<    for interpolation and then convert back to the output type
                                                        ///<    it's useful for polar, spherical interpolations and applying gamma curves.
                                                        ///<    User can create a default transform class that will convert to and from other space.
            };

            /// Helper function that converts shared pointer to type T to TweenProperty of type T
            template<typename T, typename Transform>
            std::unique_ptr<TweenProperty<T, Transform>> GetTweenProperty(
                std::shared_ptr<T> property,
                T from,
                T to,
                Transform transform)
            {
                return std::make_unique<TweenProperty<T, Transform>>(property, from, to, transform);
            }

            /// Helper function that converts shared pointer to Property of type T to TweenProperty of type T
            template<typename T, typename Transform>
            std::unique_ptr<TweenProperty<T, Transform>> GetTweenProperty(
                std::shared_ptr<IProperty<T>> property,
                T from,
                T to,
                Transform transform)
            {
                return std::make_unique<TweenProperty<T, Transform>>(property, from, to, transform);
            }

            /// Helper function that creates indirect property
            template<typename TValue, typename TObject>
            std::shared_ptr<::Spectre::Utils::IProperty<TValue>>
                CreateIndirectProperty(
                    std::weak_ptr<TObject> instance,
                    void (TObject::*setter)(TValue value),
                    TValue(TObject::*getter)() const
                    )
            {
                auto weakThis = instance; // instance->shared_from_this();
                return std::make_shared<::Spectre::Utils::IndirectProperty<TValue>>(
                    [setter, weakThis](TValue v)
                {
                    if (auto ptr = weakThis.lock())
                    {
                        TObject* rawPtr = ptr.get();
                        (rawPtr->*setter)(v);
                    }
                },

                    [getter, weakThis]()
                {
                    if (auto ptr = weakThis.lock())
                    {
                        TObject* rawPtr = ptr.get();
                        return (rawPtr->*getter)();
                    }
                    else
                    {
                        return TValue();
                    }
                }
                );
            }
        }// end Tweening
    }// end Utils
}// end Spectre
