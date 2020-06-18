////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_CYLINDER_HXX
#define JTK_XT_CYLINDER_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTCylinder
//
// Description    : An object defining an XT cylinder surface.
//
// Enums          :
//
// Includes       : JtkXTCylinder.h
//
// Inheritance    : JtkXTSurface > JtkXTCylinder
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTCylinder : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTCylinder )

public:
   virtual int    getInternals( double* &location, 
                                double* &reference,
                                double* &axis, 
                                double  &radius,
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                double* &location, 
                                double* &reference,
                                double* &axis, 
                                double  &radius,
                                int     &error ) = 0;

   int            operator == ( const JtkXTCylinder &OtherSurface )const;

protected:
   JtkXTCylinder();
   virtual  ~JtkXTCylinder();
};

#endif

