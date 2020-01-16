/********************************************************
 *                                                       *
 *   Copyright (C) Microsoft. All rights reserved.       *
 *                                                       *
 ********************************************************/

#pragma once

#include <memory>
#include <CoreUtils/Platform.h>

// Set this to 1 to enable the MacCll library and code for testing.
// It is currently not 100% functional and causes link errors in unit tests.
// Keep this disabled until it is ready to be released.
#if !CANVAS_PLATFORM_IS_IOS_SIMULATOR()
#   define ENABLE_MACCLL_LIBRARY 1
#endif

namespace Babylon
{
    namespace Utils
    {
        class CanvasCll
        {
        public:
            CanvasCll();
            ~CanvasCll();
            void IncrementCorrelationVector();
            void Log(std::string eventName, const char* eventData);
        private:
            class CllImpl;
            static int m_cllCount;
        };
    }
}
