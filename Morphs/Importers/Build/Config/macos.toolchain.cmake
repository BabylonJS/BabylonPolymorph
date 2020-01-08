function(CopyConfigurationVariables parentSuffix buildSuffix)
    get_directory_property(allVariables VARIABLES)
    foreach(currentVariable IN LISTS allVariables)
        if (currentVariable MATCHES "_${parentSuffix}$")
            string(REPLACE "_${parentSuffix}" "_${buildSuffix}" newVariable "${currentVariable}")
            set(${newVariable} "${${currentVariable}}" PARENT_SCOPE)
        endif()
    endforeach()
endfunction(CopyConfigurationVariables)

# Available build types are:
# - Debug - default CMake debug build type.
# - Release - default CMake release build type.
# - RelWithDebInfo - default CMake release with debug info build type.
# - MinSizeRel - default CMake minimal size relase build type.
# - DebugWithAddressSanitizer - custome buuld type. Same as Debug but with Address sanitizer and UB sanitizer enabled.
# - DebugWithThreadSanitizer - custome buuld type. Same as Debug but with Thread sanitizer and UB sanitizer enabled.
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo;MinSizeRel;DebugWithAddressSanitizer;DebugWithThreadSanitizer" CACHE STRING "Available build-types: Debug, Release, RelWithDebInfo, MinSizeRel, DebugWithAddressSanitizer and DebugWithThreadSanitizer" FORCE)

CopyConfigurationVariables("DEBUG" "DEBUGWITHADDRESSSANITIZER")
CopyConfigurationVariables("DEBUG" "DEBUGWITHTHREADSANITIZER")

set(CMAKE_CXX_FLAGS_DEBUGWITHADDRESSSANITIZER "${CMAKE_CXX_FLAGS_DEBUGWITHADDRESSSANITIZER} -fsanitize=undefined,address -fno-sanitize=float-divide-by-zero -fno-sanitize-recover=all -fno-omit-frame-pointer -D_LIBCPP_HAS_NO_ASAN")
set(CMAKE_C_FLAGS_DEBUGWITHADDRESSSANITIZER "${CMAKE_C_FLAGS_DEBUGWITHADDRESSSANITIZER} -fsanitize=undefined,address -fno-sanitize=float-divide-by-zero -fno-sanitize-recover=all -fno-omit-frame-pointer -D_LIBCPP_HAS_NO_ASAN")
set(CMAKE_EXE_LINKER_FLAGS_DEBUGWITHADDRESSSANITIZER "${CMAKE_EXE_LINKER_FLAGS_DEBUGWITHADDRESSSANITIZER} -fsanitize=undefined,address -fno-omit-frame-pointer")

set(CMAKE_CXX_FLAGS_DEBUGWITHTHREADSANITIZER "${CMAKE_CXX_FLAGS_DEBUGWITHTHREADSANITIZER} -fsanitize=undefined,thread -fno-sanitize=float-divide-by-zero -fno-sanitize-recover=all")
set(CMAKE_C_FLAGS_DEBUGWITHTHREADSANITIZER "${CMAKE_C_FLAGS_DEBUGWITHTHREADSANITIZER} -fsanitize=undefined,thread -fno-sanitize=float-divide-by-zero -fno-sanitize-recover=all")
set(CMAKE_EXE_LINKER_FLAGS_DEBUGWITHTHREADSANITIZER "${CMAKE_EXE_LINKER_FLAGS_DEBUGWITHTHREADSANITIZER} -fsanitize=undefined,thread")

execute_process(COMMAND xcode-select -print-path
   OUTPUT_VARIABLE SELECTED_XCODE_ROOT
   ERROR_QUIET
   OUTPUT_STRIP_TRAILING_WHITESPACE)

file(GLOB_RECURSE TSAN_RUNTIME "${SELECTED_XCODE_ROOT}/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/**/libclang_rt.tsan_osx_dynamic.dylib")
file(GLOB_RECURSE ASAN_RUNTIME "${SELECTED_XCODE_ROOT}/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/**/libclang_rt.asan_osx_dynamic.dylib")
file(GLOB_RECURSE UBSAN_RUNTIME "${SELECTED_XCODE_ROOT}/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/**/libclang_rt.ubsan_osx_dynamic.dylib")

# When redefining a function an exisiting one gets renamed to _<name>. So in order to make sure we do this only once we first check if _add_executable
# is not already defined. Since this runs ahead of everything else we don't expect add_executable to be redefined.
# Look here for further explaination: https://cmake.org/pipermail/cmake/2015-October/061751.html
if (NOT _CANVAS_TOOLCHAIN_SOURCED)
  set(_CANVAS_TOOLCHAIN_SOURCED ON)

  if (COMMAND _add_executable)
    message(FATAL_ERROR "A different cmake file has already redefined add_executable")
  endif()

  function(add_executable target)
    _add_executable(${target} ${ARGN})

    install(FILES ${ASAN_RUNTIME}
            DESTINATION ${CMAKE_SOURCE_DIR}/Built/Out/macOS/$<CONFIG>/${target}
            CONFIGURATIONS DebugWithAddressSanitizer
    )

    install(FILES ${TSAN_RUNTIME}
            DESTINATION ${CMAKE_SOURCE_DIR}/Built/Out/macOS/$<CONFIG>/${target}
            CONFIGURATIONS DebugWithThreadSanitizer
    )

    install(FILES ${UBSAN_RUNTIME}
            DESTINATION ${CMAKE_SOURCE_DIR}/Built/Out/macOS/$<CONFIG>/${target}
            CONFIGURATIONS DebugWithAddressSanitizer DebugWithThreadSanitizer
    )
  endfunction()
endif()