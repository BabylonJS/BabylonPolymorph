/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.   *
*                                                       *
********************************************************/

#pragma once

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <array>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <locale.h>
#include <map>
#include <memory>
#include <mutex>
#include <random>
#include <sstream>
#include <stdio.h>
#include <string>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <utility>
#include <vector>
#include <CoreUtils/BabylonSal.h>
#include <CoreUtils/Memory.h>
#include <Framework/Memory.h>

#ifdef _WIN32
# include <Windows.h>
# include <wincodec.h>
#endif
