/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#include <type_traits>
#include <CoreUtils/Assert.h>

namespace Babylon {

namespace Utils {

template <typename T>
class Optional
{
public:
    Optional() : m_isInitialized(false) {}
    Optional(T val) : m_isInitialized(false)
    {
        Set(std::move(val));
    }
    Optional(std::nullptr_t) : m_isInitialized(false) {}
    Optional(Optional const & rhs) : m_isInitialized(false)
    {
        if (rhs)
        {
            Set(*rhs);
        }
    }
    Optional(Optional && rhs) : m_isInitialized(false)
    {
        if (rhs)
        {
            Set(std::move(*rhs));
        }
        rhs.Clear();
    }
    ~Optional()
    {
        Clear();
    }

    void swap(Optional& rhs)
    {
        using std::swap;

        bool localValid = Valid();
        bool remoteValid = rhs.Valid();

        if (localValid)
        {
            if (remoteValid)
            {
                swap(**this, *rhs); // no need to update valid both are true
            }
            else
            {
                // set and clear update valid as needed
                rhs.Set(**this);
                Clear();
            }
        }
        else
        {
            if (remoteValid)
            {
                // set and clear update valid as needed
                Set(*rhs);
                rhs.Clear();
            }
            else
            {
                // nothing to do here, no need to update valid both are false
            }
        }
    }

    Optional& operator=(T val)
    {
        Set(std::move(val));
        return *this;
    }

    Optional& operator=(Optional rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    T const& operator*() const
    {
        BabylonAssert(Valid());
        return *GetPtr();
    }

    T& operator*()
    {
        BabylonAssert(Valid());
        return *GetPtr();
    }

    T const* operator->() const
    {
        BabylonAssert(Valid());
        return GetPtr();
    }

    T* operator->()
    {
        BabylonAssert(Valid());
        return GetPtr();
    }

    bool operator==(Optional const& rhs) const
    {
        bool localValid = Valid();
        bool remoteValid = rhs.Valid();
        if (localValid)
        {
            if (remoteValid)
            {
                return **this == *rhs;
            }
            return false;
        }
        else
        {
            return !remoteValid;
        }
    }

    bool operator!=(Optional const& rhs) const
    {
        return !(*this == rhs);
    }

    bool Valid() const
    {
        return m_isInitialized;
    }

    // Fake bool type for fake bool idiom
    typedef bool (Optional::*bool_type)() const;
    operator bool_type() const
    {
        return Valid() ? &Optional::Valid : nullptr;
    }

    void Clear()
    {
        if (m_isInitialized)
        {
            GetPtr()->~T();
            m_isInitialized = false;
        }
    }

    void Set(T val)
    {
        Clear();
        new(GetPtr())T(std::move(val));
        m_isInitialized = true;
    }

private:
    T* GetPtr() const // This is more than a little icky
    {
        return reinterpret_cast<T*>(const_cast<char*>(m_val));
    }

    union
    {
        typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type m_storage;
        char m_val[sizeof(T)];
    };
    bool m_isInitialized;
};

template <typename T>
class Optional<T&>
{
public:
    Optional() : m_ptr(nullptr) {}
    Optional(T& val) : m_ptr(&val) {}
    Optional(Optional const & rhs) : m_ptr(rhs.m_ptr) {}

    T const& operator*() const
    {
        BabylonAssert(m_ptr);
        return *m_ptr;
    }

    T& operator*()
    {
        BabylonAssert(m_ptr);
        return *m_ptr;
    }

    bool operator==(Optional const& rhs) const
    {
        bool localValid = Valid();
        bool remoteValid = rhs.Valid();
        if (localValid)
        {
            if (remoteValid)
            {
                return **this == *rhs;
            }
            return false;
        }
        else
        {
            return !remoteValid;
        }
    }

    bool Valid() const
    {
        return !!m_ptr;
    }

    typedef bool (Optional::*bool_type)() const;

    operator bool_type() const
    {
        return m_ptr ? &Optional::Valid : nullptr;
    }

private:
    Optional& operator=(Optional const&);

    T* m_ptr; // non owning
};

template<class T>
void swap(Optional<T>& lhs, Optional<T>& rhs)
{
    lhs.swap(rhs);
}

} // namespace Utils

} // namespace Babylon
