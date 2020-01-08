// Copyright (c) Microsoft. All rights reserved.

#pragma once

#include "CanvasCll.h"
#if ENABLE_MACCLL_LIBRARY

#include "cll/ILogger.h"

using std::string;

namespace Spectre
{
    namespace Utils
    {
        class CanvasCllLogger : public cll::ILogger
        {
        public:

            CanvasCllLogger(LogLevel level);

            void setLogLevel(LogLevel level) override;
            void debug(const string& tag, const string& message) override;
            void warn(const string& tag, const string& message) override;
            void error(const string& tag, const string& message) override;

        protected:

            void logInternal(LogLevel messageLevel, const string& tag, const string& message);
        };
    }
}

#endif // ENABLE_MACCLL_LIBRARY
