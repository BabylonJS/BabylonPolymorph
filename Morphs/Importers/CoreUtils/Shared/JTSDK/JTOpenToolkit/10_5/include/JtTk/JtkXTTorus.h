////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_TORUS_HXX
#define JTK_XT_TORUS_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTTorus
//
// Description    : An object defining an XT torus surface.
//
// Enums          :
//
// Includes       : JtkXTTorus.h
//
// Inheritance    : JtkXTSurface > JtkXTTorus
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTTorus : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTTorus )

public:
   virtual int    getInternals( double* &location, 
                                double* &reference,
                                double* &axis, 
                                double  &majorRadius,
                                double  &minorRadius, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                double* &location, 
                                double* &reference,
                                double* &axis, 
                                double  &majorRadius,
                                double  &minorRadius, 
                                int     &error ) = 0;

   int            operator == ( const JtkXTTorus &OtherSurface )const;

protected:
   JtkXTTorus();
   virtual  ~JtkXTTorus();
};

#endif

