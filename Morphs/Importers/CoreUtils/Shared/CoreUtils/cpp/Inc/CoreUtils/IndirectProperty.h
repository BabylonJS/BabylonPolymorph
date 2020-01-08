/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

#include "Property.h"

#include <CoreUtils/SmartThrow.h>

namespace Spectre
{
    namespace Utils
    {
        /// \brief IndirectProperty derives from Property<T> and provides a mechanism for setting and
        /// getting values via setter and getter function pointers.
        ///
        /// It works well as a proxy for wrapping API into property interface so it can be passed to
        /// TweenManager for creating tweens.
        template<class T>
        class IndirectProperty : public IProperty<T>
        {
        public:
            /// A constructor
            ///
            /// \param setMethod - function pointer for setting value, function pointer for getter is null in this case
            IndirectProperty(const std::function<void(const T& )>& setMethod) :
                m_setter(setMethod)
            {
            }

            /// A constructor
            ///
            /// \param setMethod - function pointer for setting value
            /// \param getMethod - function pointer for getting value
            IndirectProperty(const std::function<void(T)>& setMethod,
                             const std::function<T()>& getMethod) :
                m_setter(setMethod),
                m_getter(getMethod)
            {
            }

            virtual ~IndirectProperty() = default;

            virtual void Set(const T& val)
            {
                m_setter(val);
            }

            virtual T Get() const
            {
                if (m_getter)
                {
                    return m_getter();
                }
                throw Spectre::Utils::SpectreException("Getter has not been set");
            }

            void operator=(const T& val) { Set(val); }
            operator T () const { return Get(); }

        private:
            std::function<void(const T&)>   m_setter;
            std::function<T()>              m_getter;
        };

        template<typename ValueType>
        using PropertyConnection = std::shared_ptr<::Spectre::Utils::IProperty<ValueType>>;

    }// end Utils
}// end Spectre
