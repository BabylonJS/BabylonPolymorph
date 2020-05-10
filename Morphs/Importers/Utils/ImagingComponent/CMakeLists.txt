# ImagingComponent
file(GLOB SOURCES CONFIGURE_DEPENDS
	"Include/ImagingComponent/*.h"
	"Source/*.h"
	"Source/*.cpp"
	"Source/Win/*.h"
	"Source/Win/*.cpp")
	
add_library(ImagingComponent ${SOURCES})

target_include_directories(ImagingComponent PUBLIC "Include")

set_property(TARGET ImagingComponent PROPERTY FOLDER Utils)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(ImagingComponent
    CoreUtils
	Framework
	CanvasTex
)