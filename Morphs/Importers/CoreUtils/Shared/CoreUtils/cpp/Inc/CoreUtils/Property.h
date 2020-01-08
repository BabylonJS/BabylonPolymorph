/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(_FUNCTIONAL_)
#include <functional>
#endif // _FUNCTIONAL_

namespace Spectre
{
    namespace Utils
    {
        /// \brief Property class provides a generic interface for getting and setting value of type T
        template<class T>
        class IProperty
        {
        public:
            virtual void Set(const T& val) = 0;
            virtual T Get() const = 0;
        };

    }// end Utils
}// end Spectre