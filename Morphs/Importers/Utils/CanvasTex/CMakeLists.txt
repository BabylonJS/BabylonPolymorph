# CanvasTex
file(GLOB SOURCES CONFIGURE_DEPENDS
	"Include/CanvasTex/*.h"
	"Source/*.h"
	"Source/Win/*.h"
	"Source/Win/*.cpp")
	
add_library(CanvasTex ${SOURCES})

target_include_directories(CanvasTex PUBLIC "Include")

target_compile_definitions(CanvasTex
    PRIVATE NOMINMAX)

set_property(TARGET CanvasTex PROPERTY FOLDER Utils)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(CanvasTex
    CoreUtils
	Framework
)

if(WIN32)
    target_link_libraries(CanvasTex 
		DirectXTex 
		d3d11.lib 
		dxgi.lib 
		windowscodecs.lib)
endif()
