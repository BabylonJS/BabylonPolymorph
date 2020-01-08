/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#if defined(RAPIDJSON_NAMESPACE)
#error Another file has likely already included rapidjson.h before this.  This could result in compiling or linking with a different version of rapidjson than we expect. \
This is known to cause runtime errors if different versions of rapidjson are included in the same namespace. \
Spectre Canvas code should only include rapidjson using this header. \
If this is being included from another library then it is important to separate the code in that library from our own use of rapidjson. \
Please do not include their headers and this header in the same cpp file.
#endif

#define RAPIDJSON_NAMESPACE Spectre::rapidjson
#define RAPIDJSON_NAMESPACE_BEGIN namespace Spectre { namespace rapidjson {
#define RAPIDJSON_NAMESPACE_END   } }

// rapidjson
#include <rapidjson/document.h>
#include <rapidjson/reader.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/error/en.h>

#pragma warning(push)
// Bitwise and with zero. This is due to preprocessor definitions controlling rapidjson behavior that in the default case result in such an operation.
// The logic is still correct, but technically could be optimized away with a little more work, but we don't want to modify rapidjson for this yet.
#pragma warning(disable: 6313)
#include <rapidjson/writer.h>
#pragma warning(pop)
