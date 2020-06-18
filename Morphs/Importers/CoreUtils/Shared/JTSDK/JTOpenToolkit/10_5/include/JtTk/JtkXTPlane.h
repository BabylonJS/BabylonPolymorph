////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_PLANE_HXX
#define JTK_XT_PLANE_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTPlane
//
// Description    : An object defining an XT plane surface.
//
// Enums          :
//
// Includes       : JtkXTPlane.h
//
// Inheritance    : JtkXTSurface > JtkXTPlane
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTPlane : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTPlane )

public:
   virtual int    getInternals( double* &location, 
                                double* &reference, 
                                double* &axis, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                double* &location, 
                                double* &reference, 
                                double* &axis, 
                                int     &error ) = 0;

   int            operator == ( const JtkXTPlane &OtherSurface )const;

protected:
   JtkXTPlane();
   virtual  ~JtkXTPlane();
};

#endif

