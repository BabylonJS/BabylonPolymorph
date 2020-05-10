/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if !defined(COREUTILS_STRINGUTILS_H_INCLUDED)
#define COREUTILS_STRINGUTILS_H_INCLUDED

#include <CoreUtils/BabylonSDK.h>
#include <string>
#include <vector>

#ifndef _MSC_VER
#include <cstdarg>
#endif

namespace Babylon
{
    namespace Utils
    {
        /**
         * Converts an UTF-8 string to a wide character string.
         */
        std::wstring BABYLON_SDK_CALL StringToWString(const char* s, size_t size);

        /**
         * Converts an UTF-8 string to a wide character string.
         */
        std::wstring BABYLON_SDK_CALL StringToWString(const std::string& s);

        /**
         * Converts a wide character string to an UTF-8 string.
         */
        std::string BABYLON_SDK_CALL WStringToString(const wchar_t* w, size_t size);

        /**
         * Converts a wide character string to an UTF-8 string.
         */
        std::string BABYLON_SDK_CALL WStringToString(const std::wstring& w);

        /**
         * Trims leading whitespace from a string.
         */
        std::string BABYLON_SDK_CALL LTrim(std::string str);

        /**
         * Trims leading whitespace from a string.
         */
        std::wstring BABYLON_SDK_CALL LTrim(std::wstring str);

        /**
         * Trims trailing from a string.
         */
        std::string BABYLON_SDK_CALL RTrim(std::string str);

        /**
         * Trims trailing from a string.
         */
        std::wstring BABYLON_SDK_CALL RTrim(std::wstring str);

        /**
         * Trims leading and trailing whitespace from a string.
         */
        std::string BABYLON_SDK_CALL Trim(std::string str);

        /**
         * Trims leading and trailing whitespace from a string.
         */
        std::wstring BABYLON_SDK_CALL Trim(std::wstring str);

        /**
         * Splits up a string given a delimeter.
         */
        std::vector<std::string> BABYLON_SDK_CALL Split(const std::string& string, const std::string& delimiter);

        /**
         * Splits up a string given a delimeter.
         */
        std::vector<std::wstring> BABYLON_SDK_CALL Split(const std::wstring& string, const std::wstring& delimiter);

        /**
         * Splits up a string given a regex.
         */
        std::vector<std::string> BABYLON_SDK_CALL SplitRegex(const std::string& string, const std::string& regex);

        /**
         * Splits up a string given a regex.
         */
        std::vector<std::wstring> BABYLON_SDK_CALL SplitRegex(const std::wstring& string, const std::wstring& regex);

        /**
         * Replaces all instances of a substring with another in a string.
         */
        std::string BABYLON_SDK_CALL StringReplace(std::string const& string, std::string const& what, std::string const& with);

        /**
         * Replaces all instances of a substring with another in a string.
         */
        std::wstring BABYLON_SDK_CALL StringReplace(std::wstring const& string, std::wstring const& what, std::wstring const& with);

        bool BABYLON_SDK_CALL IsPathAbsolute(const std::string& path);
        bool BABYLON_SDK_CALL IsPathAbsolute(const std::wstring& path);

        bool BABYLON_SDK_CALL IsPathRelative(const std::string& path);
        bool BABYLON_SDK_CALL IsPathRelative(const std::wstring& path);

        std::string BABYLON_SDK_CALL GetPathConsistentSlashes(std::string const& path);
        std::wstring BABYLON_SDK_CALL GetPathConsistentSlashes(std::wstring const& path);

        std::string BABYLON_SDK_CALL GetPathConcatenation(std::string const& first, std::string const& second);
        std::wstring BABYLON_SDK_CALL GetPathConcatenation(std::wstring const& first, std::wstring const& second);

        std::string BABYLON_SDK_CALL GetPathDirectory(std::string const& path);
        std::wstring BABYLON_SDK_CALL GetPathDirectory(std::wstring const& path);

        std::string BABYLON_SDK_CALL GetPathFileName(std::string const& path);
        std::wstring BABYLON_SDK_CALL GetPathFileName(std::wstring const& path);

        std::string BABYLON_SDK_CALL GetPathFileExtension(std::string const& path);
        std::wstring BABYLON_SDK_CALL GetPathFileExtension(std::wstring const& path);

        std::string BABYLON_SDK_CALL GetPathFileExtensionLower(std::string const& path);
        std::wstring BABYLON_SDK_CALL GetPathFileExtensionLower(std::wstring const& path);

        bool BABYLON_SDK_CALL BeginsWith(std::string const &a, char b);
        bool BABYLON_SDK_CALL BeginsWith(std::string const &a, std::string const &b);
        bool BABYLON_SDK_CALL BeginsWith(std::wstring const &a, wchar_t b);
        bool BABYLON_SDK_CALL BeginsWith(std::wstring const &a, std::wstring const &b);

        bool BABYLON_SDK_CALL EndsWith(std::string const &a, char b);
        bool BABYLON_SDK_CALL EndsWith(std::string const &a, std::string const &b);
        bool BABYLON_SDK_CALL EndsWith(std::wstring const &a, wchar_t b);
        bool BABYLON_SDK_CALL EndsWith(std::wstring const &a, std::wstring const &b);

        void BABYLON_SDK_CALL TransformToLower(std::string &str);
        void BABYLON_SDK_CALL TransformToLower(std::wstring &str);

        std::string BABYLON_SDK_CALL ToLower(const std::string& str);
        std::wstring BABYLON_SDK_CALL ToLower(const std::wstring& str);

#ifndef _MSC_VER
        int BabylonSDK_CALL BabylonVSNPrintf_s(char* const _Buffer, size_t const _BufferCount, size_t const _MaxCount, char const* const _Format, va_list _ArgList);

        inline int BabylonSPrintf_s(char* const _Buffer, size_t const _BufferCount, char const* const _Format, ...)
        {
            va_list args;
            va_start(args, _Format);
            int result = BabylonVSNPrintf_s(_Buffer, _BufferCount, _BufferCount - 1, _Format, args);
            va_end(args);
            return result;
        }

        template <size_t _Size> inline int BabylonSPrintf_s(char(&_Buffer)[_Size], char const* const _Format, ...)
        {
            va_list args;
            va_start(args, _Format);
            int result = BabylonVSNPrintf_s(_Buffer, _Size, _Size - 1, _Format, args);
            va_end(args);
            return result;
        }

        static const size_t Babylon_TRUNCATE = static_cast<size_t>(-1);
#endif // #ifndef _MSC_VER
    } // namespace Utils
} // namespace Babylon

#ifndef _MSC_VER
#define _TRUNCATE Babylon::Utils::Babylon_TRUNCATE
#define sprintf_s Babylon::Utils::BabylonSPrintf_s
#define vsnprintf_s Babylon::Utils::BabylonVSNPrintf_s
#define strtok_s strtok_r
#endif

#endif // COREUTILS_STRINGUTILS_H_INCLUDED
