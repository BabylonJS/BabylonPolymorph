////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_NURBS_CURVE_HXX
#define JTK_NURBS_CURVE_HXX

#include <JtTk/JtkCurve.h>

///////%{
//
// Class          : JtkNURBSCurve
//
// Description    : A base object class for defining NURBS curves.
//
// Enums          :
//
// Includes       : JtkNURBSCurve.h
//
// Inheritance    : JtkCurve > JtkNURBSCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkNURBSCurve : public JtkCurve
{
   JTK_OBJECT_HEADER( JtkNURBSCurve )

protected:
   JtkNURBSCurve();
   virtual  ~JtkNURBSCurve();
};
#endif

