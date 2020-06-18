////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SPHERE_HXX
#define JTK_XT_SPHERE_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTSphere
//
// Description    : An object defining an XT sphere surface.
//
// Enums          :
//
// Includes       : JtkXTSphere.h
//
// Inheritance    : JtkXTSurface > JtkXTSphere
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSphere : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTSphere )

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

   int            operator == ( const JtkXTSphere &OtherSurface )const;

protected:
   JtkXTSphere();
   virtual  ~JtkXTSphere();
};

#endif

