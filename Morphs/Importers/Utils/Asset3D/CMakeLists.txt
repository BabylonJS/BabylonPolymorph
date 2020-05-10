# Asset3D
file(GLOB SOURCES CONFIGURE_DEPENDS
	"Include/Asset3D/*.h"
	"Source/*.h"
	"Source/*.cpp")
	
add_library(Asset3D ${SOURCES})

target_include_directories(Asset3D PUBLIC "Include")

set_property(TARGET Asset3D PROPERTY FOLDER Utils)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

target_link_libraries(Asset3D
    CoreUtils
	Framework
	ImagingComponent
)