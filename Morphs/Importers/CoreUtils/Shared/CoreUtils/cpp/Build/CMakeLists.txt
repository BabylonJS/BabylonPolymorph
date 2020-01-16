cmake_minimum_required(VERSION 3.5)
project (CoreUtils)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

###############################################################################
## Library Source
###############################################################################

file(GLOB INC_FILES
    "${CMAKE_CURRENT_LIST_DIR}/../Inc/CoreUtils/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/../Inc/CoreUtils/Math/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/../Inc/CoreUtils/Tweening/*.h"
)

file(GLOB DIRECTXMATH_INC_FILES
    "${CMAKE_CURRENT_LIST_DIR}/../Inc/DirectXMath/*.h"
)

file(GLOB COMMON_SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.h"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/../Source/Tweening/*.cpp"
)

if(ANDROID_OS_PLATFORM)
    file (GLOB PLATFORM_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Android/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Android-Mac/*.cpp"
    )
elseif(APPLE)
    file (GLOB PLATFORM_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Mac/*.mm"
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Android-Mac/*.cpp"
    )
elseif(WIN32)
    file (GLOB PLATFORM_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/Win/*.cpp"
    )
else()
    message(FATAL_ERROR "Unknown platform")
endif()

source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/../Inc/CoreUtils" PREFIX "Headers\\CoreUtils" FILES ${INC_FILES})
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/../Inc/DirectXMath" PREFIX "Headers\\DirectXMath" FILES ${DIRECTXMATH_INC_FILES})
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/../Source" PREFIX "Sources" FILES ${PLATFORM_SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/../Source" PREFIX "Sources" FILES ${COMMON_SOURCE_FILES})

add_library(CoreUtils ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES} ${INC_FILES} ${DIRECTXMATH_INC_FILES} ${PLATFORM_INC_FILES})

set_target_properties(CoreUtils PROPERTIES
    FOLDER "CoreUtils"
)

###############################################################################
## Include Path
###############################################################################

target_include_directories(CoreUtils
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
    PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
)

if(WIN32)
    # Add Source to the include path because that is where CoreUtilsPch.h exists, but it is included in Source/Win
    target_include_directories(CoreUtils
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Source"
    )
endif()

###############################################################################
## Compiler Options
###############################################################################

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(CoreUtils
        PRIVATE "-Wunguarded-availability"
        PRIVATE "-Wall"
        PRIVATE "-Werror"
        PUBLIC "-Wno-unknown-pragmas")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(CoreUtils PRIVATE "/WX")
endif()

###############################################################################
## Library depedencies
###############################################################################

target_link_libraries(CoreUtils
    GLTFSDK
    RapidJSON
)

###############################################################################
## Install
###############################################################################

CreateCanvasInstallTargets(CoreUtils ${Platform})
