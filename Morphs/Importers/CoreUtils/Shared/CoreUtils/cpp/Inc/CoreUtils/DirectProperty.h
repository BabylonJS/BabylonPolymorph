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

namespace Spectre
{
    namespace Utils
    {
        /// \brief DirectProperty derives from Property<T> and provides a mechanism for setting and
        /// getting value stored inside the class.
        ///
        /// At the moment this class is not the most exciting in the world.
        /// It serves as a wrapper over a custom type T with Set and Get functions.
        /// It provides some C# like convenience for getting and setting values with no need of calling set and get,
        /// but unlike C# provides NO access control to setters and getters (private, public), cannot be defined
        /// declaratively - you must provide setter and getter in the constructor while you instantiate the class.
        ///
        template<class T>
            class DirectProperty : public IProperty<T>
            {
            public:
                DirectProperty(const T& val)
                    : m_propertyValue(val)
                {
                }
                virtual void Set(const T& val) { m_propertyValue = val; }
                virtual T Get() const { return m_propertyValue; }

                void operator=(const T& val) { Set(val);}
                operator T () const { return Get(); }

            private:
                T m_propertyValue;
            };

        template<typename ValueType>
        using PropertyConnectionDirect = std::shared_ptr<ValueType>;

    }// end Utils
}// end Spectre