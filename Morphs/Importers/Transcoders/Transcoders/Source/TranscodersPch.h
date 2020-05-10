/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/

#pragma once

#define BABYLON_SDK_API

#define WIN32_LEAN_AND_MEAN
#define _ATL_NO_WIN_SUPPORT

#include <algorithm>
#include <future>
#include <string>
#include <iostream>
#include <fstream>
#include <numeric>
#include <memory>
#include <math.h>
#include <float.h>

#include <Framework/Types.h>
#include <Framework/GeometryWriter.h>
#include <Framework/GeometryUtils.h>
#include <Framework/TextureWriter.h>
#include <Framework/MaterialWriter.h>

#include <CoreUtils/Math/SimpleMath.h>
#include <CoreUtils/Assert.h>
#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/Hash.h>
#include <CoreUtils/Trace.h>

#include <ImagingComponent/ImagingComponent.h>

#include <PluginSDK/FractionalProgressCallback.h>

#ifdef _WIN32
#include <Windows.h>
#endif
