/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.    *
*                                                       *
********************************************************/

#include "CoreUtilsPch.h"
#include <CoreUtils/Trace.h>

#if FEATURE_TRACEENABLED

#include <atomic>
#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <map>
#include <mutex>
#include <new>
#include <string>

#include <CoreUtils/IO.h>
#include <CoreUtils/LexicalCast.h>
#include <CoreUtils/SmartThrow.h>
#include <CoreUtils/BabylonSal.h>
#include <CoreUtils/StringUtils.h>
#include <CoreUtils/ThreadHelpers.h>
#include <locale>

#include "PlatformLogger.h"

DEFINE_TRACE_AREA(Trace, 0);

namespace
{
    std::atomic<int> g_TraceDisabledCount = { 0 };

    //--------------------------------------------------------------------------------

    // Gets the name of the configuration file
    std::string GetConfigFileName()
    {
    #if _DEBUG
        return Babylon::Utils::IO::GetTempDirectory() + "SavedHudSettings.txt";
    #else
        return "SavedHudSettings.txt";
    #endif // _DEBUG
    }

    //--------------------------------------------------------------------------------

    // Simple structure of all useful information about levels
    struct
    {
        Trace::Level    level;
        const char*     name;
        const char*     string;
    } allLevels[] = 
    {
        { Trace::Level::NotSet,    "NotSet",    "N" },
        { Trace::Level::Verbose,   "Verbose",   "V" },
        { Trace::Level::Info,      "Info",      "I" },
        { Trace::Level::Important, "Important", "P" },
        { Trace::Level::Warn,      "Warning",   "W" },
        { Trace::Level::Errored,   "Error",     "E" },
        { Trace::Level::Off,       "Off",       "O" },
    };
    static_assert(std::extent<decltype(allLevels)>::value == Trace::Level::MaxLevel, "allLevels array isn't up to date");

    //--------------------------------------------------------------------------------

    // Simple structure of all useful information about devices
    struct
    {
        Trace::Device device;
        const char* name;
        const char* friendlyName;
        Trace::Level defaultValue;
    } allDevices[] = 
    {
        { Trace::Device::Break,  "Break",  "Fire a debug break",    Trace::Level::Errored   },
        { Trace::Device::Handlers, "Handlers", "Handlers",          Trace::Level::Info   },
        { Trace::Device::Output, "Output", "Debug output",          Trace::Level::Important },
        { Trace::Device::File,   "File",   "To file - DEPRECATED",  Trace::Level::Off }, 
    };
    static_assert(std::extent<decltype(allDevices)>::value == Trace::Device::MaxDevice, "allDevices array isn't up to date");

    //--------------------------------------------------------------------------------

    // Converts from a severity level to its single char representation
    const char* GetSeverityString(Trace::Level level)
    {
        return allLevels[level].string;
    }

    //--------------------------------------------------------------------------------

    // Given a string, converts it to a value (effectively reverses GetLevelName());
    Trace::Level GetLevelValue(const std::string &value)
    {
        typedef decltype(allLevels[0]) LevelDesc;
        auto iter = std::find_if( std::begin(allLevels), std::end(allLevels), [&](LevelDesc &type)
        {
            return value == type.name;
        });
        if(iter == std::end(allLevels))
        {
            return Trace::Level::MaxLevel;
        }
        else
        {
            return iter->level;
        }
    }

    uint64_t GetMSCountSinceStartAccurate()
    {
        auto now = std::chrono::high_resolution_clock::now();
        static auto start = now;
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
    }

    // Gets the time string in [hhh:mm:ss.mls] format, epoch of the first time it is called
    std::string GetTimeString()
    {
        char buffer[256];

        auto ms = GetMSCountSinceStartAccurate();

        auto secs = ms / 1000;
        ms = ms % 1000;

        auto mins = secs / 60;
        secs = secs % 60;

        auto hours = mins / 60;
        mins = mins % 60;

        sprintf_s(buffer, "%.3d:%.2d:%.2d:%.3d", (int)hours, (int)mins, (int)secs, (int)ms);

        return buffer;
    }

    //--------------------------------------------------------------------------------

    // Gets the versions string of the config file
    const std::string& GetVersionString()
    {
        static const std::string versionString = "1.0";
        return versionString;
    }

    //--------------------------------------------------------------------------------

    std::mutex& GetAreaMapMutex()
    {
        static std::mutex mut;
        return mut;
    }

    //--------------------------------------------------------------------------------

    std::map<std::string, Trace::LevelSettings*>& GetAreaMap()
    {
        static std::map<std::string, Trace::LevelSettings*> list;
        return list;
    }
} // anonymous namespace

//--------------------------------------------------------------------------------

namespace Trace
{

//--------------------------------------------------------------------------------

void BABYLON_SDK_CALL EnableTrace()
{
    BabylonAssert(g_TraceDisabledCount > 0);
    --g_TraceDisabledCount;
}

void BABYLON_SDK_CALL DisableTrace()
{
    ++g_TraceDisabledCount;
}

//--------------------------------------------------------------------------------

// Gets the name of a trace level
std::string GetLevelName(Level level)
{
    BabylonAssert(allLevels[level].level == level);
    return allLevels[level].name;
}

//--------------------------------------------------------------------------------

void SetAreaLevels(Device device, Level level)
{
    std::lock_guard<std::mutex> stackLock(GetAreaMapMutex());
    for (auto& area : GetAreaMap())
    {
        area.second->SetLevel(device, level);
    }
}

//--------------------------------------------------------------------------------

void SetAreaLevel(const std::string& area, Device device, Level level)
{
    std::lock_guard<std::mutex> stackLock(GetAreaMapMutex());
    auto& areaMap = GetAreaMap();

    auto areaIt = areaMap.find(area);
    if (areaIt != areaMap.end())
    {
        areaIt->second->SetLevel(device, level);
    }
}

//--------------------------------------------------------------------------------

void SaveCurrentTraceSettings()
{
    std::string configFileName = GetConfigFileName();

    std::lock_guard<std::mutex> stackLock(GetAreaMapMutex());
    auto& list = GetAreaMap();

    std::string contents = "version=" + GetVersionString() + "\n";
    for (auto iter = list.begin(); iter != list.end(); ++iter)
    {
        LevelSettings *settings = iter->second;
        std::string name = iter->first;
        contents += name + "=" + settings->Serialise() + "\n";
    }

    try
    {
        Babylon::Utils::IO::DebugOnlyWriteWholeFile(configFileName, contents);
    }
    catch (std::bad_alloc&)
    {
        throw;
    }
    catch (std::exception&)
    {
        // We dont care if this fails
    }
}

//--------------------------------------------------------------------------------

void LoadCurrentTraceSettings()
{
    std::string configFileName = GetConfigFileName();

    std::string currentVersionString = GetVersionString();
    try
    {
        std::string contents = Babylon::Utils::IO::DebugOnlyReadWholeBlockingFileAsString(configFileName);
        std::vector<std::string> allLines = Babylon::Utils::Split(contents, "\n");

        if (allLines.size() == 0)
        {
            TRACE_WARN(Trace, "Found an empty config file");
            return;
        }

        std::lock_guard<std::mutex> stackLock(GetAreaMapMutex());
        auto& list = GetAreaMap();

        bool firstTime = true;
        for (auto& line : allLines)
        {
            auto pair = Babylon::Utils::Split(line, "=");
            if (pair.size() != 2)
            {
                TRACE_WARN(Trace, "Found config file with wrong line format expected 2 args delimeted by '=', found '%s'", line.c_str());
                return;
            }

            std::string name = pair[0];
            std::string value = pair[1];

            if (firstTime)
            {
                firstTime = false;
                if (name != "version" || value != currentVersionString)
                {
                    TRACE_WARN(Trace, "Found config file with wrong version - expected 'version=%s', found '%s'", currentVersionString.c_str(), line.c_str());
                    return;
                }
            }
            else
            {
                auto iter = list.find(name);
                if (iter == list.end())
                {
                    // Ignore, this Trace doesn't exist anymore
                }
                else
                {
                    iter->second->Deserialise(value);
                }
            }
        }
    }
    catch (std::bad_alloc&)
    {
        throw;
    }
    catch (std::exception&)
    {
        // We don't really care if this fails
    }
}

//--------------------------------------------------------------------------------

std::string GetDeviceName(Device device)
{
    BabylonAssert((device >= 0) && (device < Device::MaxDevice));
    return allDevices[device].name;
}

//--------------------------------------------------------------------------------

std::string GetFriendlyDeviceName(Device device)
{
    BabylonAssert((device >= 0) && (device < Device::MaxDevice));
    return allDevices[device].friendlyName;
}

//--------------------------------------------------------------------------------

void LevelSettingsWrapper::InitIfNecessary()
{
    std::call_once(initOnce, [this]() {

        BabylonAssert(this->ptr == nullptr);
        this->ptr = ::new Trace::LevelSettings(this->areaName, this->flags);
    });

    BabylonAssert(this->ptr);
}

//--------------------------------------------------------------------------------

void LevelSettings::ResetLevels()
{
    m_to[Device::Break] = allDevices[Device::Break].defaultValue;
    m_to[Device::Handlers] = allDevices[Device::Handlers].defaultValue;
    m_to[Device::Output] = allDevices[Device::Output].defaultValue;
    m_to[Device::File] = allDevices[Device::File].defaultValue;
}

//--------------------------------------------------------------------------------

LevelSettings::LevelSettings(
    const char* areaName,
    uint32_t flags
    ) : m_areaName(areaName)
{
    // Extract from the flags the levels we should send to file, output, screen and break on.
    // If any of the lower importance output methods has a higher Level than an important
    // one then drag down the lower device to the more spammy version.
    // For example, if screen is set to verbose and file to warning, then file will
    // also be set to verbose

    ResetLevels();

    uint32_t breakOn = (flags & BreakOn::Mask) >> BreakOn::Shift;
    if (breakOn == 0) breakOn = (uint32_t)m_to[Device::Break];
    m_to[Device::Break] = static_cast<Level>(breakOn);

    uint32_t toHandlers = (flags & ToHandlers::Mask) >> ToHandlers::Shift;
    if (toHandlers == 0) toHandlers = (uint32_t)m_to[Device::Handlers];
    if (toHandlers > breakOn) toHandlers = breakOn;
    m_to[Device::Handlers] = static_cast<Level>(toHandlers);

    uint32_t toOutput = (flags & ToOutput::Mask) >> ToOutput::Shift;
    if (toOutput == 0) toOutput = (uint32_t)m_to[Device::Output];
    m_to[Device::Output] = static_cast<Level>(toOutput);

    // disable tracing to file, it's not going to work with dlls
    //uint32_t toFile = (flags & ToFile::Mask) >> ToFile::Shift;
    //if(toFile == 0) toFile = (uint32_t)m_to[Device::File];
    //if(toFile > toOutput) toFile = toOutput;
    //m_to[Device::File] = static_cast<Level>(toFile);
    m_to[Device::File] = Level::Off;

    std::lock_guard<std::mutex> stackLock(GetAreaMapMutex());
    GetAreaMap()[areaName] = this;
}

//--------------------------------------------------------------------------------

void LevelSettings::SetLevel(Device d, Level level)
{
    m_to[d] = level;
}

//--------------------------------------------------------------------------------

Level LevelSettings::GetLevel(Device d) const
{
    return m_to[d];
}

//--------------------------------------------------------------------------------

std::string LevelSettings::GetAreaName() const
{
    return this->m_areaName;
}

//--------------------------------------------------------------------------------

void LevelSettingsWrapper::Output(_In_ Level level, _In_z_ _Printf_format_string_ const char *formatString, ...)
{
    InitIfNecessary();
    va_list varArgs;
    va_start(varArgs, formatString);
    this->ptr->Output(level, formatString, varArgs);
    va_end(varArgs);
}

//--------------------------------------------------------------------------------

void LevelSettings::Output(Level level, const char *formatString, va_list varArgs)
{
    if (g_TraceDisabledCount > 0)
    {
        return;
    }

    // Removed file support as the code was not cross-platform
    //bool toFile = (level >= m_to[Device::File]); 

    bool toOutput = (level >= m_to[Device::Output]);
    bool toHandlers = (level >= m_to[Device::Handlers]);
    bool breakOn = (level >= m_to[Device::Break]);
    // Create the string the code passed in
    char formattedBuffer[kMaxLineLength];
    vsnprintf_s(formattedBuffer, kMaxLineLength, _TRUNCATE, formatString, varArgs);

    // Create the line to log - something like "[HHH::MM:SS.ms][E][AreaName][0xThreadId] Failed to contobulate the bozzle\n"
    char wholeLine[kMaxLineLength + 64];
    sprintf_s(wholeLine, "[%s][%s][%s][0x%.8x] %s\n", GetTimeString().c_str(), GetSeverityString(level), this->GetAreaName().c_str(), (unsigned int)::GetCurrentThreadId(), formattedBuffer);

    //if (toFile)
    //{
    //    TODO: Re-add file support with a cross-platform implementation that can also work on WinRT.
    //}

    if (toHandlers)
    {
        NotifyHandlers(m_areaName, level, wholeLine);
    }

    if (toOutput)
    {
#if _DEBUG && !FORCE_TRACE_ON
        ::OutputDebugStringA(wholeLine);
#else
        PrintLogMessage(wholeLine);
#endif // _DEBUG
    }

#if FORCE_TRACE_ON && defined(_WIN32)
    // Force output to the debugger
    ::OutputDebugStringA(wholeLine);
#endif

    if (breakOn)
    {
        // If you hit this debug break, that means the code hit a TRACE_ERROR - see up the callstack to find it
        Babylon_DEBUG_BREAK();
    }
}

//--------------------------------------------------------------------------------

std::string LevelSettings::Serialise() const
{
    std::string line = "break:" + GetLevelName(m_to[Device::Break]);
    line += ";file:" + GetLevelName(m_to[Device::File]);
    line += ";output:" + GetLevelName(m_to[Device::Output]);
    line += ";handlers:" + GetLevelName(m_to[Device::Handlers]);
    return line;
}

//--------------------------------------------------------------------------------

void LevelSettings::Deserialise(const std::string &line)
{
    this->ResetLevels();
    auto items = Babylon::Utils::Split(line, ";");
    for (auto& item : items)
    {
        auto pair = Babylon::Utils::Split(item, ":");
        if (pair.size() != 2)
        {
            throw Babylon::Utils::BabylonException("Wrong line format of " + line);
        }
        auto& key = pair[0];
        auto& val = pair[1];
        Level l = GetLevelValue(val);
        if (key == "break")
        {
            m_to[Device::Break] = l;
        }
        else if (key == "file")
        {
            m_to[Device::File] = l;
        }
        else if (key == "output")
        {
            m_to[Device::Output] = l;
        }
        else if (key == "handlers")
        {
            m_to[Device::Handlers] = l;
        }
        else
        {
            throw Babylon::Utils::BabylonException("Bad line description '" + key + "'");
        }
    }
}

//--------------------------------------------------------------------------------

std::mutex& GetHandlerMapCriticalLock()
{
    static std::mutex mutex;
    return mutex;
}

//--------------------------------------------------------------------------------

std::map<RegistrationToken, TraceHandler>& GetHandlerMap()
{
    static std::map<RegistrationToken, TraceHandler> map;
    return map;
}

//--------------------------------------------------------------------------------

RegistrationToken GetNewRegistrationToken()
{
    static RegistrationToken token = 0;
    return ++token;
}

//--------------------------------------------------------------------------------

void NotifyHandlers(std::string const& area, Level level, std::string const& message)
{
    std::map<RegistrationToken, TraceHandler> handlers;
    {
        std::lock_guard<std::mutex> lock(GetHandlerMapCriticalLock());
        auto handlerMap = GetHandlerMap();
        handlers = handlerMap;
    }
    for (auto handler : handlers)
    {
        handler.second(area, level, message);
    }
}

//--------------------------------------------------------------------------------

RegistrationToken AttachTraceHandler(TraceHandler handler)
{
    std::lock_guard<std::mutex> lock(GetHandlerMapCriticalLock());

    auto& map = GetHandlerMap();
    auto token = GetNewRegistrationToken();
    map.insert(std::make_pair(token, handler));

    return token;
}

//--------------------------------------------------------------------------------

void RemoveTraceHandler(RegistrationToken token)
{
    std::lock_guard<std::mutex> lock(GetHandlerMapCriticalLock());

    auto& map = GetHandlerMap();
    auto it = map.find(token);
    if (it != map.end())
    {
        map.erase(token);
    }
}

//--------------------------------------------------------------------------------

} // namespace Trace

//--------------------------------------------------------------------------------

#endif // FEATURE_TRACEENABLED
