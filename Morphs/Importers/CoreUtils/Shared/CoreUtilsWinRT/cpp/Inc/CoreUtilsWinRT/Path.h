/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

namespace Spectre
{

namespace UtilsWinRT
{

namespace P = Platform;
namespace WF = Windows::Foundation;

ref class Path sealed
{
public:
    Path(P::String^ path);
    Path(P::String^ basePath, P::String^ relativePath);

    Path^ ChangeExtension(P::String^ newExtension);
    Path^ CombinePath(P::String^ relativePath);

    bool Equals(Path^ other);

    property P::String^ RawPath {P::String^ get();}

    property Path^ Directory {Path^ get();}
    property P::String^ DirectoryString {P::String^ get();}
    property P::String^ Extension {P::String^ get();}
    property P::String^ Filename {P::String^ get();}
    property P::String^ FilenameWithoutExtension {P::String^ get();}
    property Path^ Root {Path^ get();}
    property P::String^ RootString {P::String^ get();}

    property bool HasExtension {bool get();}
    property bool IsAbsolute {bool get();}
    property bool IsDirectory {bool get();}
    property bool IsRooted {bool get();}

public: // constants
    static property wchar_t DirectorySeparatorChar {wchar_t get();}
    static property wchar_t AlternativeDirectorySeparatorChar {wchar_t get();}
    static property wchar_t ExtensionSeparatorChar {wchar_t get();}
    static property wchar_t VolumeSeparatorChar {wchar_t get();}

private:
    void Init(P::String^ path);

    P::String^ m_rawPath;
    P::String^ m_drive;
    P::String^ m_directory;
    P::String^ m_filename;
    P::String^ m_extension;
};

}

}
