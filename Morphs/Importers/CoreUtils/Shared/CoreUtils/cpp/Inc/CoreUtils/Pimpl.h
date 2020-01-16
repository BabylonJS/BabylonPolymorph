/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <memory>

// Note: include this file in the header and PimplImpl.h in the .cpp

// Usage:
//
// #include <Pimpl.h>
//
// class SomeType
// {
//     class Impl;
//     Pimpl<Impl> m_impl;
// };

namespace Babylon
{
namespace Utils
{
    enum class PimplCreationMode
    {
        Default = 0,
        Lazy
    };

    namespace Detail
    {
        template<PimplCreationMode>
        struct Tag {};
    }

    constexpr Detail::Tag<PimplCreationMode::Lazy>    PimplLazyTag = {};
    constexpr Detail::Tag<PimplCreationMode::Default> PimplDefaultTag = {};

    template<typename T>
    class Pimpl final
    {
    public:
        template<PimplCreationMode Mode>
        Pimpl(Detail::Tag<Mode> tag = PimplDefaultTag);

        template<typename ...TArgs>
        Pimpl(TArgs&& ...);
        Pimpl(Pimpl&& pimpl);

        ~Pimpl();

        template<typename ...TArgs>
        void Create(TArgs&& ...);
        void Create(Pimpl&& pimpl);

        void Delete();

        Pimpl& operator=(Pimpl&&);
        Pimpl& operator=(const Pimpl&) = delete;

        explicit operator bool() const;

        T* operator->();
        const T* operator->() const;

        T& operator*();
        const T& operator*() const;

    private:
        std::unique_ptr<T> m_ptr;
    };
}
}
