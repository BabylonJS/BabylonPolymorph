function(CopyConfigurationVariables parentSuffix buildSuffix)
    get_directory_property(allVariables VARIABLES)
    foreach(currentVariable IN LISTS allVariables)
        if (currentVariable MATCHES "_${parentSuffix}$")
            string(REPLACE "_${parentSuffix}" "_${buildSuffix}" newVariable "${currentVariable}")
            set(${newVariable} "${${currentVariable}}" PARENT_SCOPE)
        endif()
    endforeach()
endfunction(CopyConfigurationVariables)

set(CMAKE_SYSTEM_NAME "Windows")

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;DebugWithDrMemory" CACHE STRING "Available build-types: Debug, Release, and DebugWithDrMemory" FORCE)

# Setup DebugWithDrMemory configuration
CopyConfigurationVariables("DEBUG" "DEBUGWITHDRMEMORY")
set(CMAKE_CXX_FLAGS_DEBUGWITHDRMEMORY "${CMAKE_CXX_FLAGS_DEBUGWITHDRMEMORY} /MTd /Zi /Ob0 /Oy-")
set(CMAKE_EXE_LINKER_FLAGS_DEBUGWITHDRMEMORY "${CMAKE_EXE_LINKER_FLAGS_DEBUGWITHDRMEMORY} /DEBUG")

include(${CMAKE_CURRENT_LIST_DIR}/windows.toolchain.cmake)

# Target Windows 7 (Copied from Spectre.Cpp.props)
add_definitions(-DWINVER=0x0601 -DWIN32_WINNT=0x0601)
