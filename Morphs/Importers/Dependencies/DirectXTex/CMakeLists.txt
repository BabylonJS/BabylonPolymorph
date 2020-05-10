# Download and unpack DirectXTex at configure time
configure_file(CMakeDirectXTexDownload.txt.in ${CMAKE_BINARY_DIR}/DirectXTex-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/DirectXTex-download )
if(result)
  message(FATAL_ERROR "CMake step for DirectXTex failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/DirectXTex-download )
if(result)
  message(FATAL_ERROR "Build step for DirectXTex failed: ${result}")
endif()

# DirectXTex doesn't use CMake for its build.
# We have two options here.  Use msbuild to build the solution files that are in the git repo
# or use CMake to add the source files to the build
# Using msbuild means that we would have to build all the configurations here in the "Configure" step.
# It also makes it less configurable (switch between /MD and /MT compile options, for example)

# We are going to try just building the source files

# Copy a CMakeLists.txt into the source folder that will be used by the build.
configure_file(CMakeDirectXTexBuild.txt ${CMAKE_BINARY_DIR}/DirectXTex-src/CMakeLists.txt COPYONLY)

# Add the CMakeLists.txt copied above into our build.
add_subdirectory(${CMAKE_BINARY_DIR}/DirectXTex-src
                 ${CMAKE_BINARY_DIR}/DirectXTex-build)

# Force DirectXTex targets in sub-folder in solution
set_target_properties(DirectXTex PROPERTIES
    FOLDER "Dependencies"
)
