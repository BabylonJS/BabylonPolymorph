# Common Windows C++ compiler options and settings that are always used regardless of the architecture or platform

# Setup target and minimum Windows SDK versions
set(CMAKE_SYSTEM_VERSION "10.0.17134.0")            # <WindowsTargetPlatformVersion>
set(SPECTRE_PLATFORM_MIN_VERSION "10.0.16299.0")    # <WindowsTargetPlatformMinVersion>

# The initial default compiler flags for Visual Studio C++ builds
# These were derived from the old Canvas3D project settings
# Options that were defined to be the same as the VS defaults have been excluded
# Some options have been excluded
# /FS (Serializes access to the pdb files, slower builds and probably isn't needed for the cmake build.  If we get a lot of pdb access errors we should re-enable this)
# /Zm200 (Increases the heap size for pre-compiled headers, which we don't enable globally.  If a project enables pre-compiled headers and runs out of memory it should set this option)

set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W4 /DUNICODE /D_UNICODE /DNOMINMAX /D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING /Gm- /EHsc /MP /guard:cf /sdl /Zi /Zc:inline /std:c++14 /errorReport:prompt /bigobj /d2Zi+")
set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Ob0 /Od /Oy- /RTC1 /DDEBUG /D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "/MD /O2 /Ob2 /Oy- /Oi /Gy /DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/MD /O2 /Ob1 /Oy- /Oi /Gy /DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "/MD /O1 /Ob1 /Oi /Gy /DNDEBUG")

# Ensure that we use WIN32 threading on Windows builds
option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)
