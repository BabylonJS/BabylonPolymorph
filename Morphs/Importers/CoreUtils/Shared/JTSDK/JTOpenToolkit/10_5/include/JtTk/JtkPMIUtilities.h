////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTKPMIUTILITIES_H
#define JTKPMIUTILITIES_H

#include <JtTk/JtkStandard.h>

//*****************************************************************************
// functions to initial and destruct the PMI structs
//*****************************************************************************

JTK_TOOLKIT_API int        PMICreatePolylineForSymbol( int      sIndex,
                                                       int      font,
                                                       float   &charWidth,
                                                       short*  &indices,
                                                       int     &indicesLen,
                                                       float*  &verts );                                                   
#endif

