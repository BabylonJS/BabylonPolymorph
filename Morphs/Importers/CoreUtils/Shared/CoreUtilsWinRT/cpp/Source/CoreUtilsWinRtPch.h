/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <Windows.h>

#include <Windows.Storage.Streams.h>

#include <wrl.h>
#include <ppltasks.h>
#pragma warning(push)
#pragma warning(disable: 4467)
#include <robuffer.h>
#pragma warning(pop)

#include <vector>
#include <string>
#include <exception>
