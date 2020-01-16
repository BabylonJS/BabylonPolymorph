/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/
#pragma once

#if !defined(COREUTILS_LEXICALCAST_H_INCLUDED)
#define COREUTILS_LEXICALCAST_H_INCLUDED

#if !defined(_STRING_)
#include <string>
#endif // _STRING_

#if !defined(_SSTREAM_)
#include <sstream>
#endif // _SSTREAM_

#if !defined(_TYPE_TRAITS_)
#include <type_traits>
#endif // _TYPE_TRAITS_

#if !defined(COREUTILS_ASSERT_H_INCLUDED)
#include "Assert.h"
#endif // COREUTILS_ASSERT_H_INCLUDED

#if !defined(COREUTILS_SMARTTHROW_H_INCLUDED)
#include "SmartThrow.h"
#endif // COREUTILS_SMARTTHROW_H_INCLUDED

#if !defined(COREUTILS_STRINGUTILS_H_INCLUDED)
#include "StringUtils.h"
#endif // COREUTILS_STRINGUTILS_H_INCLUDED

namespace Babylon {

namespace Utils {

// forward declare optional so we can disallow it in CoerceType
template<typename T>
class Optional;

struct LexicalCastFailed : Babylon::Utils::BabylonException
{
    LexicalCastFailed(std::string const& reason);
};

namespace Internal {

template<class STREAM>
void CheckStreamStatus(STREAM const& stream, bool checkEOF)
{
    BabylonAssert(!stream.bad());
    if (stream.fail())
    {
        // e.g. you tried converting "Foo" to an int...
        throw Babylon::Utils::LexicalCastFailed("Failed to convert value");
    }
    if (checkEOF && !stream.eof())
    {
        // E.g. you tried converting "62 61" or "61p" to an int...
        throw Babylon::Utils::LexicalCastFailed("Failed to convert value as too much data was supplied");
    }
}

typedef std::vector<unsigned char> ByteVector;

//------------------------------------------------------------------------------

template<typename T>
struct CoerceType
{
    typedef T type;
};

template<>
struct CoerceType<char>
{
    typedef std::string type;
};

template<>
struct CoerceType<unsigned char>
{
    typedef unsigned int type;
};

template<>
struct CoerceType<signed char>
{
    typedef int type;
};

template<>
struct CoerceType<wchar_t>
{
    typedef std::wstring type;
};

#ifdef __cplusplus_winrt
template<>
struct CoerceType<Platform::String^>
{
    typedef std::wstring type;
};
#endif

template<typename T>
struct CoerceType<T*>
{
    typedef typename std::remove_cv<T>::type CleanT;

    static_assert(
        std::is_same<char, CleanT>::value || std::is_same<wchar_t, CleanT>::value,
        "Lexical cast does not support casting from generic pointer or array types"
        );

    typedef typename CoerceType<CleanT>::type type;
};

template<typename T, size_t size>
struct CoerceType<T[size]>
{
    typedef typename std::remove_cv<T>::type CleanT;

    static_assert(
        std::is_same<char, CleanT>::value || std::is_same<wchar_t, CleanT>::value,
        "Lexical cast does not support casting from generic pointer or array types"
        );

    typedef typename CoerceType<CleanT>::type type;
};

template<typename T>
struct CoerceType<Optional<T>>
{
    typedef typename std::remove_cv<T>::type CleanT;

    // the std::is_same is to stop the assert from firing when the template is
    // parsed and to wait for actual instantiation
    static_assert(std::is_same<T, Optional<T>>::value, "Lexical cast does not support Utils::Optional parameters");

    typedef typename CoerceType<CleanT>::type type;
};

//------------------------------------------------------------------------------

template<typename CleanType, typename Type>
struct
    AdapterIn
{
    static
        CleanType
        Apply(
        const Type& val
        )
    {
        return val;
    }
};

template<typename CleanType, typename Type>
struct
    AdapterOut
{
    static
        Type
        Apply(
        const CleanType& val
        )
    {
        return static_cast<Type>(val); // allow narrowing conversions on the way out
    }
};

template<typename Type>
struct
    AdapterIn<Type, Type> // if there is no conversion skip the copy
{
    static
        const Type&
        Apply(
        const Type& val
        )
    {
        return val;
    }
};

template<typename Type>
struct
    AdapterOut<Type, Type> // if there is no conversion skip the copy
{
    static
        const Type&
        Apply(
        const Type& val
        )
    {
        return val;
    }
};

template<>
struct
    AdapterIn<std::string, char>
{
    static
        std::string
        Apply(
        char val
        )
    {
        return std::string(1, val);
    }
};

template<>
struct
    AdapterOut<std::string, char>
{
    static
        char
        Apply(
        const std::string& val
        )
    {
        BabylonAssert(val.size() == 1);

        if (!val.empty())
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
};

template<>
struct
    AdapterIn<std::wstring, wchar_t>
{
    static
        std::wstring
        Apply(
        wchar_t val
        )
    {
        return std::wstring(1, val);
    }
};

template<>
struct
    AdapterOut<std::wstring, wchar_t>
{
    static
        wchar_t
        Apply(
        const std::wstring& val
        )
    {
        BabylonAssert(val.size() == 1);

        if (!val.empty())
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
};

#ifdef __cplusplus_winrt
template<>
struct
    AdapterIn<std::wstring, Platform::String^>
{
    static
        std::wstring
        Apply(
        Platform::String^ val
        )
    {
        return std::wstring(val->Data());
    }
};

template<>
struct
    AdapterOut<std::wstring, Platform::String^>
{
    static
        Platform::String^
        Apply(
        const std::wstring& val
        )
    {
        return ref new Platform::String(val.c_str());
    }
};
#endif

//------------------------------------------------------------------------------

template<typename ToType, typename FromType>
struct PassThroughCaster
{
    static
        ToType
        Cast(
        const FromType & val
        )
    {
        return val;
    }
};

//------------------------------------------------------------------------------

template<typename ToType, typename FromType>
struct StreamCaster;

template<typename ToType>
struct StreamCaster<ToType, std::string>
{
    static_assert(!std::is_same<std::string, ToType>::value,
        "StreamCaster<ToType, std::string> cannot cast to std::string");
    static_assert(!std::is_same<std::wstring, ToType>::value,
        "StreamCaster<ToType, std::string> cannot cast to std::wstring");

    static
        ToType
        Cast(
        const std::string& val
        )
    {
        ToType res = ToType();
        std::istringstream ws;
        ws.str(val);
        ws >> res;
        CheckStreamStatus(ws, true);
        return res;
    }
};

template<typename ToType>
struct StreamCaster<ToType, std::wstring>
{
    static_assert(!std::is_same<std::string, ToType>::value,
        "StreamCaster<ToType, std::wstring> cannot cast to std::string");
    static_assert(!std::is_same<std::wstring, ToType>::value,
        "StreamCaster<ToType, std::wstring> cannot cast to std::wstring");

    static
        ToType
        Cast(
        const std::wstring& val
        )
    {
        ToType res = ToType();
        std::wistringstream ws;
        ws.str(val);
        ws >> res;
        CheckStreamStatus(ws, true);
        return res;
    }
};

//------------------------------------------------------------------------------

template<typename FromType>
struct ToStringCaster
{
    static_assert(!std::is_same<std::string, FromType>::value,
        "ToStringCaster cannot cast from std::string");

    static
        std::string
        Cast(
        const FromType& val
        )
    {
        std::ostringstream os;
        os << val;
        CheckStreamStatus(os, false);
        return os.str();
    }
};

template<>
struct ToStringCaster<std::wstring>
{
    static
        std::string
        Cast(
        const std::wstring& val
        )
    {
        return WStringToString(val);
    }
};

template<>
struct ToStringCaster<ByteVector>
{
    static
        std::string
        Cast(
        const ByteVector& val
        )
    {
        return std::string(begin(val), end(val));
    }
};

template<typename FromType>
struct ToWStringCaster
{
    static_assert(!std::is_same<std::wstring, FromType>::value,
        "ToWStringCaster cannot cast from std::wstring");
    static_assert(!std::is_same<ByteVector, FromType>::value,
        "ToWStringCaster does not support byte vectors");

    static
        std::wstring
        Cast(
        const FromType& val
        )
    {
        std::wostringstream os;
        os << val;
        CheckStreamStatus(os, false);
        return os.str();
    }
};

template<>
struct ToWStringCaster<std::string>
{
    static
        std::wstring
        Cast(
        const std::string& val
        )
    {
        return StringToWString(val);
    }
};

template<typename FromType>
struct ToByteVectorCaster
{
    static_assert(std::is_same<std::string, FromType>::value,
        "ToByteVectorCaster only supports std::string sources");

    static
        ByteVector
        Cast(
        const FromType& val
        );
};

template<>
struct ToByteVectorCaster<std::string>
{
    static
        ByteVector
        Cast(
        const std::string& val
        )
    {
        return std::vector<unsigned char>(begin(val), end(val));
    }
};

//------------------------------------------------------------------------------

template<typename ToType, typename FromType>
struct Caster :
    std::conditional<// we need to use conditionals instead of specializations because they would overlap
    std::is_same<ToType, FromType>::value,
    PassThroughCaster<ToType, FromType>,
    typename std::conditional<
    std::is_same<std::string, ToType>::value,
    ToStringCaster<FromType>,
    typename std::conditional<
    std::is_same<std::wstring, ToType>::value,
    ToWStringCaster<FromType>,
    typename std::conditional<
    std::is_same<ByteVector, ToType>::value,
    ToByteVectorCaster<FromType>,
    StreamCaster<ToType, FromType>
    >::type
    >::type
    >::type
    >::type
{};

} // namespace Internal

//------------------------------------------------------------------------------

template<typename ToType, typename FromType>
ToType
LexicalCast(
const FromType & val
)
{
    static_assert(!std::is_reference<ToType>::value, "Cannot return references from a lexical_cast");
    static_assert(!std::is_pointer<ToType>::value, "Cannot return pointers from a lexical_cast");

    typedef typename std::remove_cv<ToType>::type NoCvToType;
    typedef typename std::remove_cv<FromType>::type NoCvFromType;

    typedef typename Internal::CoerceType<NoCvToType>::type CleanToType;
    typedef typename Internal::CoerceType<NoCvFromType>::type CleanFromType;

    return Internal::AdapterOut<CleanToType, NoCvToType>::Apply(
        Internal::Caster<CleanToType, CleanFromType>::Cast(
        Internal::AdapterIn<CleanFromType, NoCvFromType>::Apply(val)
        )
        );
}

} // namespace Utils

} // namespace Babylon

#endif // COREUTILS_LEXICALCAST_H_INCLUDED
