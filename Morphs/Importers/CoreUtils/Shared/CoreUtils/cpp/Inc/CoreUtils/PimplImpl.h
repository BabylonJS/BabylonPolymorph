/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#include <stdexcept>

// Note: include this file in the .cpp and Pimpl.h in the header

// Usage:
//
// #include <PimplImpl.h>
//
// class SomeType::Impl
// {
// };


namespace Spectre
{
namespace Utils
{
    namespace Detail
    {
        template<typename T>
        T* Create(Tag<PimplCreationMode::Default>)
        {
            return new T;
        }

        template<typename T>
        T* Create(Tag<PimplCreationMode::Lazy>)
        {
            return nullptr;
        }
    }

    template<typename T>
    template<PimplCreationMode Mode>
    Pimpl<T>::Pimpl(Detail::Tag<Mode> tag) : m_ptr(Detail::Create<T>(tag)) {}

    template<typename T>
    template<typename ...TArgs>
    Pimpl<T>::Pimpl(TArgs&& ...args) : m_ptr(new T(std::forward<TArgs>(args)...)) {}

    template<typename T>
    Pimpl<T>::Pimpl(Pimpl&& pimpl) : m_ptr(std::move(pimpl.m_ptr)) {}

    template<typename T>
    Pimpl<T>::~Pimpl() = default;

    template<typename T>
    template<typename ...TArgs>
    void Pimpl<T>::Create(TArgs&& ...args)
    {
        if (m_ptr)
        {
            throw std::runtime_error("Pimpl has already been created");
        }
        else
        {
            m_ptr.reset(new T(std::forward<TArgs>(args)...));
        }
    }

    template<typename T>
    void Pimpl<T>::Create(Pimpl&& pimpl)
    {
        if (m_ptr)
        {
            throw std::runtime_error("Pimpl has already been created");
        }
        else
        {
            m_ptr = std::move(pimpl.m_ptr);
        }
    }

    template<typename T>
    void Pimpl<T>::Delete()
    {
        if (m_ptr)
        {
            m_ptr.reset();
        }
        else
        {
            throw std::runtime_error("Pimpl has not yet been created");
        }
    }

    template<typename T>
    Pimpl<T>& Pimpl<T>::operator=(Pimpl&&) = default;

    template<typename T>
    Pimpl<T>::operator bool() const
    {
        return m_ptr.operator bool();
    }

    template<typename T>
    T* Pimpl<T>::operator->() { return m_ptr.get(); }

    template<typename T>
    const T* Pimpl<T>::operator->() const { return m_ptr.get(); }

    template<typename T>
    T& Pimpl<T>::operator*() { return *m_ptr.get(); }

    template<typename T>
    const T& Pimpl<T>::operator*() const { return *m_ptr.get(); }
}
}
