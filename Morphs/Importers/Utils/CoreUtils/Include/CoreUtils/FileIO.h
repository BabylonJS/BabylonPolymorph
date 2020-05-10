/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#if !defined __cplusplus_winrt

#if !defined(_STRING_)
#include <string>
#endif // _STRING_

#if !defined(_VECTOR_)
#include <vector>
#endif // _VECTOR_

namespace Babylon
{

namespace Utils
{

namespace IO
{

bool FileExists(const std::string &fileName);
bool FileExists(const std::wstring &fileName);

std::vector<std::wstring> GetFilesInDirectory(std::wstring const& path, std::wstring const& filter = L"");

} // namespace IO

} // namespace Utils

} // namespace Babylon

#endif
