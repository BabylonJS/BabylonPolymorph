/********************************************************
*                                                       *
*   Copyright (C) Microsoft. All rights reserved.       *
*                                                       *
********************************************************/
#pragma once

#define X_UP_NAME "X_UP"
#define Y_UP_NAME "Y_UP"
#define Z_UP_NAME "Z_UP"

/// options
#define _BASEPATH_OPTION_KEY "basepath"

/// default scene name for the root node
#define _DEFAULT_SCENE_NAME "SCENE"

/// this directives is to compile with import - usefull for debuging of files
#define _IMPORT_MATERIAL
#define _IMPORT_CAMERA

/// define post process operation for normal to avoid <0 or >1
#define _GEOM_NORMAL_POST_PROCESS
/// clear normals for the primitive when one of the normal is zero
#define _GEOM_NORMAL_CLEAR_ZERO
/// normalize all normals
#define _GEOM_NORMAL_NORMALIZE

/// used for geometry importer algorithm to aggregate vertices based or not upon values
#define _GEOM_TEST_POSITION_VALUE true
#define _GEOM_TEST_NORMAL_VALUE true
#define _GEOM_TEST_TANGENT_VALUE true
#define _GEOM_TEST_TEXTCOORD_VALUE true
#define _GEOM_TEST_COLOR_VALUE true

/// used to invert Y at ST to UV level using  U=S and V = 1-T 
enum InvertYMode {
	UVLevel,
	TextureLevel
};

#define _INVERT_Y_MODE InvertYMode::UVLevel
