/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#include "CoreUtilsWinRtPch.h"

#include <stdlib.h>

#include <CoreUtilsWinRT/Path.h>
#include <CoreUtilsWinRT/SmartThrow.h>

namespace Spectre
{

namespace UtilsWinRT
{

namespace
{

wchar_t CharAt(P::String^ string, int index)
{
    if (index >= 0)
    {
        SpectreAssert(static_cast<unsigned int>(index) < string->Length());
        return *(string->Begin() + index);
    }
    else
    {
        SpectreAssert(static_cast<unsigned int>(-index) <= string->Length());
        return *(string->End() + index);
    }
}

void CheckIsRelativePath(P::String^ relativePath)
{
    if ((CharAt(relativePath, 0) == Path::DirectorySeparatorChar) ||
        (CharAt(relativePath, 0) == Path::AlternativeDirectorySeparatorChar))
    {
        throw ref new Platform::Exception(E_INVALIDARG, L"Soho::ResourceResolver::Path '" + relativePath + L"' is not a relative path");
    }
}

P::String^ NormalizeDirectoryPath(P::String^ directory)
{
    // we make sure that directory ends in \ unless it is empty.
    // in that case we would be turning a relative path into an aboslute one
    // so we just ensure that directory is an empty string
    if (directory->IsEmpty())
    {
        // do nothing
    }
    else if (CharAt(directory, -1) != Path::DirectorySeparatorChar)
    {
        directory = directory + Path::DirectorySeparatorChar;
    }

    return directory;
}

P::String^ NormalizeExtension(P::String^ extension)
{
    // we make sure that extenstion begins with a . unless it is empty
    if (!extension)
    {
        extension = L"";
    }
    else if (extension->IsEmpty())
    {
        // do nothing
    }
    else if (CharAt(extension, 0) != Path::ExtensionSeparatorChar)
    {
        extension = Path::ExtensionSeparatorChar + extension;
    }

    return extension;
}

}

Path::Path(P::String^ path)
{
    Init(path);
}

Path::Path(P::String^ basePath, P::String^ relativePath)
{
    basePath = NormalizeDirectoryPath(basePath);
    CheckIsRelativePath(relativePath);

    Init(basePath + relativePath);
}

void Path::Init(P::String^ path)
{
    wchar_t drive[_MAX_DRIVE];
    wchar_t directory[_MAX_DIR];
    wchar_t filename[_MAX_FNAME];
    wchar_t extension[_MAX_EXT];

    //  _splitpath_s automatically handles multibyte-character string arguments as appropriate
    // See: http://msdn.microsoft.com/en-gb/library/8e46eyt7.aspx for more info
    DWORD result = _wsplitpath_s(path->Data(), drive, directory, filename, extension);
    if (result != ERROR_SUCCESS)
    {
        throw ref new Platform::Exception(E_INVALIDARG, L"Soho::ResourceResolver::Path failed to parse path '" + path + L"'");
    }

    m_rawPath = path;
    m_drive = ref new P::String(drive);
    m_directory = ref new P::String(directory);
    m_filename = ref new P::String(filename);
    m_extension = ref new P::String(extension);

    if (!RawPath->IsEmpty() && (RawPath == RootString))
    {
        // if the path is only a drive letter
        SpectreAssert(DirectoryString->IsEmpty());
        SpectreAssert(FilenameWithoutExtension->IsEmpty());
        SpectreAssert(Extension->IsEmpty());
        m_directory = L"" + DirectorySeparatorChar;
    }

    if (!RootString->IsEmpty() && DirectoryString->IsEmpty() && !FilenameWithoutExtension->IsEmpty())
    {
        // this will happen if someone forgot to escape the \ after the colon
        throw ::Spectre::Utils::SpectreWinRTException(E_INVALIDARG,
            L"Did you forget to escape the first slash in '" + RawPath + L"'", false);
    }

    if (!RootString->IsEmpty() && !DirectoryString->IsEmpty())
    {
        auto first = CharAt(DirectoryString, 0);
        auto isAbsolute = (first == DirectorySeparatorChar) || (first == AlternativeDirectorySeparatorChar);
        if (!isAbsolute)
        {
            // this will happen if someone forgot to escape the \ after the colon
            throw ref new Platform::Exception(E_INVALIDARG, L"Did you forget to escape the first slash in '" + RawPath + L"'");
        }
    }
}

Path^ Path::ChangeExtension(P::String^ newExtension)
{
    if (IsDirectory)
    {
        throw ref new Platform::Exception(E_INVALIDARG, L"Cannot set extension on directory path '" + RawPath + L"'");
    }

    auto filename = FilenameWithoutExtension + NormalizeExtension(newExtension);
    return Directory->CombinePath(filename);
}

Path^ Path::CombinePath(P::String^ relativePath)
{
    CheckIsRelativePath(relativePath);
    if (!IsDirectory)
    {
        throw ref new Platform::Exception(E_INVALIDARG, L"Cannot append path on non directory path '" + RawPath + L"'");
    }

    return ref new Path(RawPath, relativePath);
}

bool Path::Equals(Path^ other)
{
    return RawPath == other->RawPath;
}

P::String^ Path::RawPath::get()
{
    return m_rawPath;
}

Path^ Path::Directory::get()
{
    return ref new Path(DirectoryString);
}

P::String^ Path::DirectoryString::get()
{
    // the directory string is either empty or it always ends in a directory
    // separator char
    SpectreAssert(m_directory->IsEmpty()
        || (CharAt(m_directory, -1) == DirectorySeparatorChar)
        || (CharAt(m_directory, -1) == AlternativeDirectorySeparatorChar));
    // also the path is absolute if and only if it begins with a directory
    // separator char, so asserting on that is tautological
    return m_directory;
}

P::String^ Path::Extension::get()
{
    // if an extension is present it always begins with .
    SpectreAssert(m_extension->IsEmpty() || (CharAt(m_extension, 0) == ExtensionSeparatorChar));
    return m_extension;
}

P::String^ Path::Filename::get()
{
    return FilenameWithoutExtension + Extension;
}

P::String^ Path::FilenameWithoutExtension::get()
{
    return m_filename;
}

Path^ Path::Root::get()
{
    return ref new Path(RootString);
}

P::String^ Path::RootString::get()
{
    // the root string is either empty or it always ends in :
    SpectreAssert(m_drive->IsEmpty() || (CharAt(m_drive, -1) == VolumeSeparatorChar));
    return m_drive;
}

bool Path::HasExtension::get()
{
    return !Extension->IsEmpty();
}

bool Path::IsAbsolute::get()
{
    // relative path implies non rooted path
    if (DirectoryString->IsEmpty())
    {
        SpectreAssert(RootString->IsEmpty());
        return false;
    }

    auto first = CharAt(DirectoryString, 0);
    auto isAbsolute = (first == DirectorySeparatorChar) || (first == AlternativeDirectorySeparatorChar);
    SpectreAssert(isAbsolute || RootString->IsEmpty());
    return isAbsolute;
}

bool Path::IsDirectory::get()
{
    // being a directory implies no extension
    auto isDir = FilenameWithoutExtension->IsEmpty();
    SpectreAssert(!isDir || !HasExtension);
    return isDir;
}

bool Path::IsRooted::get()
{
    // rooted path implies absolute path
    auto isRoot = !RootString->IsEmpty();
    SpectreAssert(!isRoot || IsAbsolute);
    return isRoot;
}

wchar_t Path::DirectorySeparatorChar::get()
{
    return L'\\';
}

wchar_t Path::AlternativeDirectorySeparatorChar::get()
{
    return L'/';
}

wchar_t Path::ExtensionSeparatorChar::get()
{
    return L'.';
}

wchar_t Path::VolumeSeparatorChar::get()
{
    return L':';
}

}

}