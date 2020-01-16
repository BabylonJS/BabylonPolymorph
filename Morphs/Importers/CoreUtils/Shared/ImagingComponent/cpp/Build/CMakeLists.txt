cmake_minimum_required(VERSION 3.5)
project (ImagingComponent)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

###############################################################################
## Library Source
###############################################################################

file(GLOB COMMON_SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
)

if(WIN32)
    file (GLOB PLATFORM_SOURCE_FILES
      "${CMAKE_CURRENT_LIST_DIR}/../Source/Win/*"
    )
endif()

add_library(ImagingComponent ${COMMON_SOURCE_FILES} ${PLATFORM_SOURCE_FILES})

set_target_properties(ImagingComponent PROPERTIES
    FOLDER "CoreUtils"
)

###############################################################################
## Compiler Options
###############################################################################

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(ImagingComponent
      PRIVATE "-Wunguarded-availability"
      PRIVATE "-Wall"
      PRIVATE "-Werror")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(ImagingComponent PRIVATE "/WX")
endif()

###############################################################################
## Include Path
###############################################################################

target_include_directories(ImagingComponent
    PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
    PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
)

###############################################################################
## Dependencies
###############################################################################

target_link_libraries(ImagingComponent CanvasTex Framework CoreUtils)

###############################################################################
## Install
###############################################################################

CreateCanvasInstallTargets(ImagingComponent ${Platform})