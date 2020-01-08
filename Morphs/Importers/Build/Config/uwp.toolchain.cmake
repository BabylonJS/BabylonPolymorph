set(CMAKE_SYSTEM_NAME "WindowsStore")

# TODO: Figure out of there is a better way to reference this path using environment variables or internal cmake paths
include_directories("C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Auxiliary/VS/UnitTest/include")
link_directories("C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Auxiliary/VS/UnitTest/lib")

include(${CMAKE_CURRENT_LIST_DIR}/windows.toolchain.cmake)

# Compile as C++/CX
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /ZW")

# Disable warning LNK4264: archiving object file compiled with /ZW into a static library.
SET(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} /IGNORE:4264")
