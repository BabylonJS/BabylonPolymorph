# Transcode.CPP
set(SOURCES
	"Source/main.cpp"
	"Source/Transcode.cpp"
	"Source/Transcode.h")
	
add_executable(Transcode.CPP ${SOURCES})

set_target_properties(Transcode.CPP PROPERTIES
    FOLDER "Apps"
)

target_include_directories(Transcode.CPP
    PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Source/"
)

target_compile_definitions(Transcode.CPP
    PRIVATE NOMINMAX)

target_link_libraries(Transcode.CPP
	CoreUtils
	Framework
	CanvasTex
	ImagingComponent
	Asset3D
	Transcoders
)

if(WIN32)
	target_link_libraries(Transcode.CPP
		ole32
		advapi32
		secur32
	)
	
	if(SKPSDK_FOUND)
		target_link_libraries(Transcode.CPP
		SKPSDK
		)

		if(SKPSDK_MULTI_FILES)
			add_custom_command(TARGET Transcode.CPP POST_BUILD
				COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:SKPSDK> $<TARGET_FILE_DIR:Transcode.CPP>
				COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE_DIR:SKPSDK>/SketchUpCommonPreferences.dll $<TARGET_FILE_DIR:Transcode.CPP>
			)
		endif()
	endif()
endif()
