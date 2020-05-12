/* ++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    TraceLoggingCorrelationVector.hpp

Abstract:

    TraceLogging Correlation Vector logging helper classes and macros for C++.
    See http://osgwiki/wiki/CorrelationVector for more information about Correlation Vectors.

Environment:

    User mode.

--*/

#pragma once

#include <stdio.h>
#include <errno.h>
#include <new.h>

#include <combaseapi.h>

/*
Quick start:

#include <windows.h>
#include <TraceLoggingProvider.h>
#include <TraceLoggingCorrelationVector.hpp>

TRACELOGGING_DEFINE_PROVIDER(
    g_hProvider,
    "MyProvider",
    (0xb3864c38, 0x4273, 0x58c5, 0x54, 0x5b, 0x8b, 0x36, 0x08, 0x34, 0x34, 0x71));

int main(int argc, char* argv[])
{
    TraceLoggingRegister(g_hProvider);

    TraceLoggingCorrelationVector cv;

    // To write the current value of the CV:
    TraceLoggingWrite(
        g_hProvider,
        "Current CV Value",
        TraceLoggingCV(cv));
    
    // To increment the CV and write the incremented value:
    char szCv[CORRELATION_VECTOR_STRING_LENGTH];
    cv.Increment(szCv); // Increment and get the incremented value
    TraceLoggingWrite(
        g_hProvider,
        "Incremented CV Value",
        TraceLoggingCVString(szCv));

    TraceLoggingUnregister(g_hProvider);

    return 0;
}
*/

/*
Macro TraceLoggingCVString(szCv):
Invoke this macro within a TraceLoggingWrite(...) call to log a correlation
vector string obtained from cv.Increment(szCv).

Typical usage:

    char szCv[CORRELATION_VECTOR_STRING_LENGTH];
    cv.Increment(szCv); // Increment and get the new value.
    TraceLoggingWrite(
        g_hProvider,
        "EventName",
        TraceLoggingCVString(szCv),
        ...);

This macro does not accept a field name. It will use a fixed name "__TlgCV__" to
facilitate programmatic detection of the CV in an event payload.
*/
#define TraceLoggingCVString(szCv) TraceLoggingString(szCv, "__TlgCV__")

/*
Macro TraceLoggingCV(pCv):
Invoke this macro within a TraceLoggingWrite(...) call to log the current value
of a correlation vector.

Note that if you want to increment the CV and log the resulting value, you
should use TraceLoggingCVString instead of TraceLoggingCV. If you increment the
vector and then use TraceLoggingCV, you are subject to a potential race
condition (another thread might call Increment in the time between the first
Increment and the logging call).

This macro does not accept a field name. It will use a fixed name (__TlgCV__) to
facilitate programmatic detection of the CV in an event payload.
*/
#define TraceLoggingCV(pCv) TraceLoggingCVString(_TlgCVGetter(pCv).get())

/*
This macro defines the string to use when sending a CV through any transport
other than TraceLoggingCV(...), e.g. the HTTP header name.
*/
#define CorrelationVectorHeaderName "MS-CV"

/*
This macro defines the size of a correlation vector string, including the null terminator.
All calls to Increment and ToString must pass a buffer of at least this many characters to
hold the output.
*/
#define CORRELATION_VECTOR_STRING_LENGTH 129

/*
In order to use correlation vectors (CV), you define an instance of the class below
and then use the TraceLogging macros above to log the CV as a field.

A TraceLogginCorrelationVector can be constructed from scratch, in which case it
will generate a new CV, or from an existing CV string.

    // This creates a new CV as a local variable.
    TraceLoggingCorrelationVector cv;

    // This creates a new dynamically-allocated CV.
    TraceLoggingCorrelationVector* pCv = new TraceLoggingCorrelationVector();

    // This extends an existing CV, yielding "tul4NUsfs9Cl7mOf.1.0".
    // The caller must free the returned pointer using delete.
    // Note that this will return nullptr on memory allocation failure.
    TraceLoggingCorrelationVector* pCv2 = TraceLoggingCorrelationVector::Extend("tul4NUsfs9Cl7mOf.1");

    // This validates an existing CV then extends it, yielding "tul4NUsfs9Cl7mOf.1.0"
    // The caller must free the returned pointer using delete.
    // Note that this will return nullptr on validation or memory allocation failure.
    TraceLoggingCorrelationVector* pCv2 = TraceLoggingCorrelationVector::Extend("tul4NUsfs9Cl7mOf.1", true);

    // This clones an existing CV, yielding "tul4NUsfs9Cl7mOf.1"
    // The caller must free the returned pointer using delete.
    // Note that this will return nullptr on memory allocation failure.
    TraceLoggingCorrelationVector* pCv3 = TraceLoggingCorrelationVector::Set("tul4NUsfs9Cl7mOf.1");

The Extend and Set functions both accept an optional boolean second parameter (default false) that,
if true, first validates the input CV according to the specification. If the input is invalid these
functions will return nullptr. If the second parameter is false some basic validation is still done,
and the functions may still return nullptr due to validation failure or memory allocation failure.

To increment a CV, use the Increment function. If the CV has reached its maximum value or size,
this function will silently do nothing.

To validate an existing CV without creating a new one, use TraceLoggingCorrelationVector::Validate(...).

To retrieve the string representation of a CV without logging, use the ToString function. This
function requires the caller to pass in an output buffer and its size in bytes, as well as an
output short that will receive the required number of bytes for the input, including the null terminator.
ToString returns true if the buffer was successfully written to, and false otherwise. If it returns
false make sure the input buffer at-least as big as the size returned in the output parameter.
To only retrieve the required buffer size, pass in NULL as the first parameter.

There is overloaded to accept a fixed-size character array that omits the second parameter. A
CV will not exceed 64 characters, per the spec.

    UINT16 requiredSize;
    pCv->ToString(nullptr, 0, &requiredSize);
    char* pBuffer = new char[requiredSize];
    pCv->ToString(pBuffer, requiredSize, &requiredSize);

    char buffer[CORRELATION_VECTOR_STRING_LENGTH];
    pCv->ToString(buffer);

TraceLoggingCorrelationVector is thread-safe. The order in which two concurrent
operations complete is non-deterministic.
*/
class TraceLoggingCorrelationVector;

inline namespace TLV
{
    extern __declspec(selectany) auto const nothrow = ::std::nothrow_t{};

    template<size_t _Size>
    void Base64Encode(const BYTE* pInput, const size_t cbInput, char(&output)[_Size])
    {
        static const char s_lookupTable[64] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                                '4', '5', '6', '7', '8', '9', '+', '/' };

        size_t nInputGroups = cbInput / 3;
        size_t nRemainder = cbInput % 3;
        size_t cchOutput = (nInputGroups * 4) + (nRemainder == 0 ? 0 : nRemainder == 1 ? 2: 3) + 1; // +1 for the null terminator

        if (cchOutput > _Size)
        {
            return;
        }

        size_t pos = 0;

        for (unsigned int i = 0; i < nInputGroups; i++)
        {
            BYTE one = (*pInput & 0xFC) >> 2;
            BYTE leftOverOne = (*pInput & 0x3) << 4;
            pInput++;
            BYTE two = leftOverOne | ((*pInput & 0xF0) >> 4);
            BYTE leftOverTwo = (*pInput & 0xF) << 2;
            pInput++;
            BYTE three = leftOverTwo | ((*pInput & 0xC0) >> 6);
            BYTE four = (*pInput & 0x3F);
            pInput++;

            output[pos++] = s_lookupTable[one];
            output[pos++] = s_lookupTable[two];
            output[pos++] = s_lookupTable[three];
            output[pos++] = s_lookupTable[four];
        }

        switch (nRemainder)
        {
        case 1:
        {
            BYTE one = (*pInput & 0xFC) >> 2;
            BYTE two = (*pInput & 0x3) << 4;

            output[pos++] = s_lookupTable[one];
            output[pos++] = s_lookupTable[two];
            output[pos++] = '=';
            output[pos++] = '=';
            break;
        }
        case 2:
        {
            BYTE one = (*pInput & 0xFC) >> 2;
            BYTE leftOverOne = (*pInput & 0x3) << 4;
            pInput++;
            BYTE two = leftOverOne | ((*pInput & 0xF0) >> 4);
            BYTE three = (*pInput & 0xF) << 2;

            output[pos++] = s_lookupTable[one];
            output[pos++] = s_lookupTable[two];
            output[pos++] = s_lookupTable[three];
            output[pos++] = '=';
            break;
        }
        }

        output[pos] = '\0';
    }
} // namespace anonymous

struct TraceLoggingCorrelationVectorV1_t
{
    static const unsigned char GuidBytesToUse = 12;
    static const unsigned char BaseLength = GuidBytesToUse / 3 * 4 + (GuidBytesToUse % 3 == 0 ? 0 : GuidBytesToUse % 3 == 1 ? 2: 3);
    static const unsigned char MaxCvLengthIncNull = 64; // The v1 spec limited CV length to 63 characters
};

struct TraceLoggingCorrelationVectorV2_t
{
    constexpr static unsigned char GuidBytesToUse = 16;
    constexpr static unsigned char BaseLength = GuidBytesToUse / 3 * 4 + (GuidBytesToUse % 3 == 0 ? 0 : GuidBytesToUse % 3 == 1 ? 2: 3);
    constexpr static unsigned char MaxCvLengthIncNull = 129;
};

constexpr TraceLoggingCorrelationVectorV1_t TraceLoggingCorrelationVectorV1 = {};
constexpr TraceLoggingCorrelationVectorV2_t TraceLoggingCorrelationVectorV2 = {};

class TraceLoggingCorrelationVector
{
private:
    char m_CvBaseValue[CORRELATION_VECTOR_STRING_LENGTH];
    SIZE_T m_cchCvBaseValue;
    volatile UINT64 m_CurrentIdAndSize;
    const SIZE_T m_MaxCvLength;

    enum CvVersion : unsigned char
    {
        Invalid = 0,
        Version1 = 1,
        Version2 = 2,
    };

public:
    TraceLoggingCorrelationVector() // The empty-constructor currently assumes a v1 CV. This will change to v2 in the future
        : m_MaxCvLength(TraceLoggingCorrelationVectorV1_t::MaxCvLengthIncNull)
    {
        GUID baseGuid = {0};
        (void)CoCreateGuid(&baseGuid);

        CreateCvFromGuid<TraceLoggingCorrelationVectorV1_t::GuidBytesToUse>(baseGuid);
    }

    explicit TraceLoggingCorrelationVector(GUID baseGuid)
        : m_MaxCvLength(TraceLoggingCorrelationVectorV2_t::MaxCvLengthIncNull - 2) // -2 as the last character is reserved for a ! to indicate overflow, plus the NULL
    {
        CreateCvFromGuid<TraceLoggingCorrelationVectorV2_t::GuidBytesToUse>(baseGuid);
    }

    explicit TraceLoggingCorrelationVector(TraceLoggingCorrelationVectorV1_t)
        : m_MaxCvLength(TraceLoggingCorrelationVectorV1_t::MaxCvLengthIncNull)
    {
        static_assert(CORRELATION_VECTOR_STRING_LENGTH >= TraceLoggingCorrelationVectorV1_t::MaxCvLengthIncNull, "CORRELATION_VECTOR_STRING_LENGTH is defined too small to hold a v1 CV");

        GUID baseGuid = {0};
        (void)CoCreateGuid(&baseGuid);

        CreateCvFromGuid<TraceLoggingCorrelationVectorV1_t::GuidBytesToUse>(baseGuid);
    }

    explicit TraceLoggingCorrelationVector(TraceLoggingCorrelationVectorV2_t)
        : m_MaxCvLength(TraceLoggingCorrelationVectorV2_t::MaxCvLengthIncNull - 2)
    {
        static_assert(CORRELATION_VECTOR_STRING_LENGTH >= TraceLoggingCorrelationVectorV2_t::MaxCvLengthIncNull, "CORRELATION_VECTOR_STRING_LENGTH is defined too small to hold a v2 CV");

        GUID baseGuid = {0};
        (void)CoCreateGuid(&baseGuid);

        CreateCvFromGuid<TraceLoggingCorrelationVectorV2_t::GuidBytesToUse>(baseGuid);
    }

    TraceLoggingCorrelationVector(const TraceLoggingCorrelationVector&) = delete;
    TraceLoggingCorrelationVector& operator=(const TraceLoggingCorrelationVector&) = delete;

    static void *operator new(size_t size)
    {
        auto ptr = _aligned_malloc(size, 8);
        if (ptr == nullptr)
        {
            throw std::bad_alloc();
        }
        return ptr;
    }

    static void operator delete(void *ptr)
    {
        _aligned_free(ptr);
    }

    static void* operator new(std::size_t count, const std::nothrow_t&)
    {
        return _aligned_malloc(count, 8);
    }

    static void operator delete(void* ptr, const std::nothrow_t&)
    {
        _aligned_free(ptr);
    }

public:
    ~TraceLoggingCorrelationVector()
    {
    }

    static bool Validate(
        _In_z_ LPCSTR szCorrelationVector
        ) throw()
    {
        return !!ValidateImpl(szCorrelationVector, false);
    }

    static TraceLoggingCorrelationVector* Extend(
        _In_z_ LPCSTR szCorrelationVector,
        bool fValidate = false
        )
    {
        CvVersion version = ValidateImpl(szCorrelationVector, !fValidate);
        if (version == Invalid)
        {
            return nullptr;
        }

        const size_t MaxCvLengthIncNull = (version == Version1 ? TraceLoggingCorrelationVectorV1_t::MaxCvLengthIncNull : TraceLoggingCorrelationVectorV2_t::MaxCvLengthIncNull);

        size_t len = strlen(szCorrelationVector);
        if ((len + 3) <= MaxCvLengthIncNull)
        {
            TraceLoggingCorrelationVector* pCV = nullptr;

            switch (version)
            {
            case Version1:
                pCV = new(::TLV::nothrow) TraceLoggingCorrelationVector(TraceLoggingCorrelationVectorV1);
                break;
            case Version2:
                pCV = new(::TLV::nothrow) TraceLoggingCorrelationVector(TraceLoggingCorrelationVectorV2);
                break;
            }

            if (pCV == nullptr)
            {
                return nullptr;
            }

            strncpy_s(pCV->m_CvBaseValue, szCorrelationVector, len);
            pCV->m_CvBaseValue[len] = '.';
            pCV->m_cchCvBaseValue = len + 1;
            pCV->m_CurrentIdAndSize = (0 | (static_cast<UINT64>(len + 3) << 32));

            pCV->m_CvBaseValue[pCV->m_cchCvBaseValue] = NULL;

            return pCV;
        }

        return nullptr;
    }

    static TraceLoggingCorrelationVector* Set(
        _In_z_ LPCSTR szCorrelationVector,
        bool fValidate = false
        )
    {
        CvVersion version = ValidateImpl(szCorrelationVector, !fValidate);
        if (version == Invalid)
        {
            return nullptr;
        }

        const size_t MaxCvLengthIncNull = (version == Version1 ? TraceLoggingCorrelationVectorV1_t::MaxCvLengthIncNull : TraceLoggingCorrelationVectorV2_t::MaxCvLengthIncNull);

        size_t len = strlen(szCorrelationVector);
        if (len < MaxCvLengthIncNull)
        {
            const char* pLastIndexof = strrchr(szCorrelationVector, '.');
            if (pLastIndexof != nullptr)
            {
                pLastIndexof++;

                _set_errno(0);
                UINT32 increment = strtol(pLastIndexof, nullptr, 10);
                if ((increment == 0 && pLastIndexof[0] != '0' && pLastIndexof[1] != '\0') ||
                    (errno == ERANGE))
                {
                    return nullptr;
                }

                TraceLoggingCorrelationVector* pCV = nullptr;

                switch (version)
                {
                case Version1:
                    pCV = new(::TLV::nothrow) TraceLoggingCorrelationVector(TraceLoggingCorrelationVectorV1);
                    break;
                case Version2:
                    pCV = new(::TLV::nothrow) TraceLoggingCorrelationVector(TraceLoggingCorrelationVectorV2);
                    break;
                }

				if (pCV == nullptr)
				{
					return nullptr;
				}

                size_t newLen = (pLastIndexof - szCorrelationVector);
                strncpy_s(pCV->m_CvBaseValue, szCorrelationVector, newLen);
                pCV->m_cchCvBaseValue = newLen;
                pCV->m_CurrentIdAndSize = (increment | (static_cast<UINT64>(newLen + 2) << 32));

                pCV->m_CvBaseValue[pCV->m_cchCvBaseValue] = NULL;

                return pCV;
            }
        }

        return nullptr;
    }

    bool Increment(
        _Out_writes_z_(CORRELATION_VECTOR_STRING_LENGTH) LPSTR szCV
        ) throw()
    {
        UINT64 currentIdAndSize = IncrementImpl();
        return ToStringImpl(currentIdAndSize, szCV);
    }

    bool ToString(
        _Out_writes_z_(CORRELATION_VECTOR_STRING_LENGTH) LPSTR szCV
        ) throw()
    {
        UINT64 currentIdAndSize = static_cast<UINT64>(InterlockedAdd64((LONG64*) &m_CurrentIdAndSize, 0));
        return ToStringImpl(currentIdAndSize, szCV);
    }

private:
    template<size_t cbGuidToUse>
    void CreateCvFromGuid(GUID baseGuid) throw()
    {
        constexpr size_t cchBaseValue = cbGuidToUse / 3 * 4 + (cbGuidToUse % 3 == 0 ? 0 : cbGuidToUse % 3 == 1 ? 2: 3);

        m_cchCvBaseValue = cchBaseValue + 1; // +1 for the period
        m_CurrentIdAndSize = (0 | (static_cast<UINT64>(m_cchCvBaseValue + 2) << 32)); // +2 for the ID value, and null terminator

        ZeroMemory(&m_CvBaseValue, ARRAYSIZE(m_CvBaseValue));

        TLV::Base64Encode((const BYTE*) &baseGuid, cbGuidToUse, m_CvBaseValue);

        m_CvBaseValue[cchBaseValue] = '.';
        m_CvBaseValue[cchBaseValue + 1] = '\0';
    }

    UINT64 IncrementImpl() throw()
    {
        for (;;)
        {
            UINT64 currentIdAndSize = static_cast<UINT64>(InterlockedAdd64((LONG64*) &m_CurrentIdAndSize, 0));
            UINT64 currentId = (currentIdAndSize & 0xFFFFFFFF);
            UINT64 currentSize = (currentIdAndSize & 0xFFFFFFFF00000000) >> 32;
            if (currentId == MAXINT32)
            {
                return currentIdAndSize;
            }

            UINT64 newId = currentId + 1;
            UINT64 newOutputSize = currentSize;
            if (newId == 10 ||
                newId == 100 ||
                newId == 1000 ||
                newId == 10000 ||
                newId == 100000 ||
                newId == 1000000 ||
                newId == 10000000 ||
                newId == 100000000 ||
                newId == 1000000000)
            {
                newOutputSize++;
            }

            if (newOutputSize > m_MaxCvLength)
            {
                return currentIdAndSize;
            }

            UINT64 newIdAndSize = (newId | (newOutputSize << 32));

            UINT64 oldValue = InterlockedCompareExchange(&m_CurrentIdAndSize, newIdAndSize, currentIdAndSize);
            if (oldValue == currentIdAndSize)
            {
                return newIdAndSize;
            }
        }
    }

    bool ToStringImpl(
        _In_ UINT64 currentIdAndSize,
        _Out_writes_opt_z_(CORRELATION_VECTOR_STRING_LENGTH) LPSTR szCV
        ) throw()
    {
        UINT32 currentId = static_cast<UINT32>(currentIdAndSize & 0xFFFFFFFF);
        UINT16 currentSize = static_cast<UINT16>((currentIdAndSize & 0xFFFFFFFF00000000) >> 32);

        if (szCV == nullptr)
        {
            return false;
        }

        szCV[0] = '\0';

        __analysis_assume(m_MaxCvLength <= CORRELATION_VECTOR_STRING_LENGTH);
        __analysis_assume(m_cchCvBaseValue < CORRELATION_VECTOR_STRING_LENGTH);

        if (memcpy_s(szCV, m_MaxCvLength, m_CvBaseValue, static_cast<SIZE_T>(currentSize)))
        {
            return false;
        }

        if (sprintf_s(szCV + m_cchCvBaseValue, m_MaxCvLength - m_cchCvBaseValue, "%u", currentId) == -1)
        {
            return false;
        }

        return true;
    }

    static CvVersion ValidateImpl(
        _In_z_ LPCSTR szCorrelationVector,
        bool fOnlyCheckVersion
        ) throw()
    {
        CvVersion detectedVersion = Version2;

        // A valid v1 CV matches ^[A-Za-z0-9+/]{16}(.[0-9]+)+$
        // and a valid v2 CV matches ^[A-Za-z0-9+/]{22}(.[0-9]+)+$
        // where each extension number is <= MAXINT32.

        size_t len = strlen(szCorrelationVector);

        if (len < TraceLoggingCorrelationVectorV1_t::BaseLength + 2) // +2 for the period and ID
        {
            return Invalid;
        }

        // If the input CV is less than the minimum size for a v2 CV, it must be a v1 CV or invalid
        if (len < TraceLoggingCorrelationVectorV2_t::BaseLength + 2) // +2 for the period and ID
        {
            detectedVersion = Version1;
        }

        size_t pos = 0;
        size_t baseLength = TraceLoggingCorrelationVectorV1_t::BaseLength;

        if (fOnlyCheckVersion)
        {
            pos = TraceLoggingCorrelationVectorV1_t::BaseLength;

            do
            {
                if (szCorrelationVector[pos] == '.')
                {
                    break;
                }

                pos = TraceLoggingCorrelationVectorV2_t::BaseLength;

                detectedVersion = (CvVersion)(detectedVersion - 1);
            } while (detectedVersion != Invalid);

            return detectedVersion;
        }
        else
        {
            do
            {
                for (; pos < baseLength; pos++)
                {
                    char ch = szCorrelationVector[pos];
                    if ((ch < '0' || ch > '9') &&
                        (ch < 'A' || ch > 'Z') &&
                        (ch < 'a' || ch > 'z') &&
                        (ch != '+') &&
                        (ch != '/'))
                    {
                        return Invalid;
                    }
                }

                if (szCorrelationVector[pos] != '.')
                {
                    baseLength = TraceLoggingCorrelationVectorV2_t::BaseLength;
                }

                detectedVersion = (CvVersion)(detectedVersion - 1);
            } while (detectedVersion != Invalid);
        }

        detectedVersion = baseLength == TraceLoggingCorrelationVectorV2_t::BaseLength ? Version2 : Version1;

        do
        {
            if (szCorrelationVector[pos] != '.')
            {
                return Invalid;
            }

            pos++;

            if (pos >= len)
            {
                return Invalid;
            }

            char buffer[11] = { 0 };
            const char* tmp = strchr(&szCorrelationVector[pos], '.');

            size_t cch = (tmp == NULL) ? len - pos : tmp - &szCorrelationVector[pos];
            if (cch > ARRAYSIZE(buffer))
            {
                return Invalid;
            }

            strncpy_s(buffer, &szCorrelationVector[pos], cch);
            _set_errno(0);
            UINT32 value = strtol(buffer, nullptr, 10);
            if ((value == 0 && buffer[0] != '0' && buffer[1] != '\0') ||
                (errno == ERANGE))
            {
                return Invalid;
            }

            pos += cch;
        } while (pos < len);

        return detectedVersion;
    }
};

/*
For internal use only. Temporarily stores the result of calling
cv.ToString().
*/
class _TlgCVGetter
{
    char m_szCV[CORRELATION_VECTOR_STRING_LENGTH];

public:

    _TlgCVGetter(_TlgCVGetter const&) = delete;
    void operator=(_TlgCVGetter const&) = delete;

    explicit _TlgCVGetter(_In_opt_ TraceLoggingCorrelationVector* pCV)
    {
        if (pCV)
        {
            pCV->ToString(m_szCV);
        }
        else
        {
            m_szCV[0] = 0;
        }
    }

    _Ret_z_ char const* get() const
    {
        return m_szCV;
    }
};
