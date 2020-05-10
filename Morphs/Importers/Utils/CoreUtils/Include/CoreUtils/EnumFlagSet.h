/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#pragma once

#include <type_traits>

namespace Babylon
{

namespace Utils
{

template < typename enumType >
class EnumFlagSet
{
    static_assert(std::is_enum<enumType>::value, "enumType must be an enum type");

    typedef typename std::underlying_type<enumType>::type base_type;

public:
    EnumFlagSet()
        : m_values(0)
    { }
    EnumFlagSet(enumType flag)
        : m_values(static_cast<base_type>(flag))
    { }
    EnumFlagSet(EnumFlagSet const & other)
        : m_values(other.m_values)
    { }
    EnumFlagSet(enumType f0, enumType f1, enumType f2 = enumType(0), enumType f3 = enumType(0))
        : m_values(static_cast<base_type>(f0 | f1 | f2 | f3))
    { }
    EnumFlagSet(std::nullptr_t)
        : m_values(0)
    { }

    base_type ToRawFlags() const { return m_values; }
    static EnumFlagSet FromRawFlags(base_type flags) { return EnumFlagSet(flags); }

    EnumFlagSet& operator=(EnumFlagSet other)
    {
        m_values = other.m_values;
        return *this;
    }

    // Composition
    EnumFlagSet& operator&=(EnumFlagSet other)
    {
        m_values &= other.m_values;
        return *this;
    }
    EnumFlagSet& operator|=(EnumFlagSet other)
    {
        m_values |= other.m_values;
        return *this;
    }
    EnumFlagSet& operator^=(EnumFlagSet other)
    {
        m_values ^= other.m_values;
        return *this;
    }

    EnumFlagSet operator&(EnumFlagSet other) const { return (other &= *this); }
    EnumFlagSet operator|(EnumFlagSet other) const { return (other |= *this); }
    EnumFlagSet operator^(EnumFlagSet other) const { return (other ^= *this); }

    EnumFlagSet operator~() const { return EnumFlagSet(~m_values); }

    // Comparison
    bool operator==(EnumFlagSet other) const { return m_values == other.m_values; }
    bool operator!=(EnumFlagSet other) const { return !(*this == other); }

    // Ordering
    bool operator<(EnumFlagSet other) const { return m_values < other.m_values; }

    // Testing
    bool HasAnyBits() const { return m_values != 0; }
    bool CountSetBits() const
    {
        auto values = m_values;
        auto count = 0;
        while (values)
        {
            ++count;
            values &= (values - 1);
        }
        return count;
    }
    bool Test(EnumFlagSet testFlags) const { return (*this & testFlags) == testFlags; }
    bool Test(enumType testFlag) const { return (*this & testFlag) == testFlag; }

    // Setting an clearing
    void Set(EnumFlagSet flags) { m_values |= flags.m_values; }
    void Set(enumType flag) { m_values |= static_cast<base_type>(flag); }
    void Clear(EnumFlagSet flags) { m_values &= ~flags.m_values; }
    void Clear(enumType flag) { m_values &= ~static_cast<base_type>(flag); }

    // In the absence of explicit conversion operators, using safe bool idiom
    typedef void (EnumFlagSet::*bool_type)() const;
    operator bool_type() const { return m_values != 0 ? &EnumFlagSet::bool_func : nullptr; }

private:
    // Private constructor - not typesafe, for internal use, which is why it is private.
    explicit EnumFlagSet(base_type values)
        : m_values(values)
    { }

    base_type m_values;

    void bool_func() const { }
};

}

}
