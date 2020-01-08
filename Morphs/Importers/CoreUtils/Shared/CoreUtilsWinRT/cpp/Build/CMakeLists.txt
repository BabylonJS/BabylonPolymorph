cmake_minimum_required(VERSION 3.5)

project (CoreUtilsWinRt)

###############################################################################
## This project only builds for WindowsStore/UWP/UAP/WinRt
###############################################################################

if (${CMAKE_SYSTEM_NAME} STREQUAL "WindowsStore")

    include(CanvasPlatform)
    GetCanvasPlatform(Platform)

    ###############################################################################
    ## Library Source
    ###############################################################################

    file(GLOB INC_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Inc/CoreUtilsWinRt/*.h"
    )

    file(GLOB COMMON_SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
    )

    source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/../Inc/CoreUtilsWinRt" PREFIX "Headers\\CoreUtilsWinRt" FILES ${INC_FILES})
    source_group(TREE "${CMAKE_CURRENT_LIST_DIR}/../Source" PREFIX "Sources" FILES ${COMMON_SOURCE_FILES})

    add_library(CoreUtilsWinRt ${COMMON_SOURCE_FILES} ${INC_FILES})

    ###############################################################################
    ## Include Path
    ###############################################################################

    target_include_directories(CoreUtilsWinRt
        PUBLIC "${CMAKE_CURRENT_LIST_DIR}/../Inc"
        PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int"
    )

    ###############################################################################
    ## Library depedencies
    ###############################################################################

    target_link_libraries(CoreUtilsWinRt
        CoreUtils
    )

    ###############################################################################
    ## Compiler Options
    ###############################################################################
    
    set_target_properties(CoreUtilsWinRt PROPERTIES VS_WINRT_COMPONENT TRUE)
    if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        # Enable Warnings as Errors 
        target_compile_options(CoreUtilsWinRt
            PRIVATE "/WX"
    )
    endif()

    
    ###############################################################################
    ## Install
    ###############################################################################

    CreateCanvasInstallTargets(CoreUtilsWinRt ${Platform})

else()

    # Add an empty interface library for unsupported platforms so that it can be added as a dependency
    # without conditions.
    add_library(CoreUtilsWinRt INTERFACE)

endif()
