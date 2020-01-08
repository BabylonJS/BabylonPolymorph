//
// Copyright (C) Microsoft.  All rights reserved.
//
#pragma once

#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/Assert.h>

// Force GLI_ASSERT to throw an exception if it occurs rather than the default behavour of calling "assert" which will terminate the app.
// The default behaviour in Release builds is to do nothing, which is possibly worse, so it will also throw an exception.
#include <gli/type.hpp>
#ifdef GLI_ASSERT
#   undef GLI_ASSERT
#endif
#define GLI_ASSERT(condition) if (!(condition)) {throw Spectre::Utils::SpectreException(#condition " is false in " __FILE__ " at line " _STRINGIZE(__LINE__) ); }

#include <gli/texture.hpp>
#include <gli/texture2d.hpp>
#include <gli/load_dds.hpp>

