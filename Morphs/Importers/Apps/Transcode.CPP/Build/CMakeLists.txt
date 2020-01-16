cmake_minimum_required(VERSION 3.5)
project (Transcode.CPP)

include(CanvasPlatform)
GetCanvasPlatform(Platform)

file(GLOB source_cpp
    "${CMAKE_CURRENT_LIST_DIR}/../Source/*.cpp"
)

add_executable(Transcode.CPP ${source_cpp})

set_target_properties(Transcode.CPP PROPERTIES
    FOLDER "Apps"
)

target_include_directories(Transcode.CPP
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/../Source/"
)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # Enable Warnings as Errors 
    target_compile_options(Transcode.CPP
        PRIVATE "/WX"
    )
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(Transcode.CPP
        PRIVATE "-Wall"
        PRIVATE "-Werror"
        PRIVATE "-Wunguarded-availability"
    )
endif()

target_include_directories(Transcode.CPP
    PRIVATE "${CMAKE_SOURCE_DIR}/Built/Int" # For BabylonVersionInternal.h
)

target_link_libraries(Transcode.CPP
    Transcoders
    Asset3D
    CanvasTex
    ImagingComponent
    Framework
    CoreUtils
)

if (APPLE)
    target_link_libraries(Transcode.CPP
        "-framework Cocoa"
        "-framework AppKit"
        "-framework Security"
    )
endif()

if (WIN32)
    target_link_libraries(Transcode.CPP
        ole32
        advapi32
    )
endif()

if ((APPLE AND NOT IOS_PLATFORM) OR (Platform STREQUAL "windows_x64"))
    target_link_libraries(Transcode.CPP
        SKPSDK
    )
    if(Platform STREQUAL "windows_x64")
        add_custom_command(TARGET Transcode.CPP POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:SKPSDK> $<TARGET_FILE_DIR:Transcode.CPP>
        )
    elseif(APPLE AND NOT IOS_PLATFORM)
        add_custom_command(TARGET Transcode.CPP POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory ${SKPFRAMEWORK} $<TARGET_FILE_DIR:Transcode.CPP>/SketchUpAPI.framework
            COMMAND ${CMAKE_INSTALL_NAME_TOOL} -add_rpath "@executable_path/" $<TARGET_FILE:Transcode.CPP>
        )

        install(DIRECTORY "${PROJECT_BINARY_DIR}/$<CONFIG>/SketchUpAPI.framework/"
            DESTINATION ${CMAKE_SOURCE_DIR}/Built/Out/${Platform}/$<CONFIG>/${PROJECT_NAME}/SketchUpAPI.framework
        )
    endif()
endif()

CreateCanvasInstallTargets(Transcode.CPP ${Platform})
