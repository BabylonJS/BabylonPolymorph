// Copyright (c) Microsoft. All rights reserved.

#include "CanvasCllLogger.h"

#if ENABLE_MACCLL_LIBRARY

#include <CoreUtils/Trace.h>

using std::string;

DEFINE_TRACE_AREA(CanvasCllLogger, 0);

namespace Babylon
{
    namespace Utils
    {
        CanvasCllLogger::CanvasCllLogger(LogLevel level)
        {
            logLevel = level;
        }

        void CanvasCllLogger::setLogLevel(LogLevel level)
        {
            logLevel = level;
        }

        void CanvasCllLogger::debug(const string& tag, const string& message)
        {
            logInternal(LevelDebug, tag, message);
        }

        void CanvasCllLogger::warn(const string& tag, const string& message)
        {
            logInternal(LevelWarn, tag, message);
        }

        void CanvasCllLogger::error(const string& tag, const string& message)
        {
            logInternal(LevelError, tag, message);
        }

        void CanvasCllLogger::logInternal(LogLevel messageLevel, const string& tag, const string& message)
        {
            if (logLevel >= messageLevel)
            {
                // The CLL telemetry logging is quite verbose, so only log it if the user has specified VERBOSE level logging.
                TRACE_VERBOSE(CanvasCllLogger, "%s: %s", tag.c_str(), message.c_str());
            }
        }
    }
}

#endif // ENABLE_MACCLL_LIBRARY
