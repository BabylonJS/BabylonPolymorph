////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_CONE_HXX
#define JTK_XT_CONE_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTCone
//
// Description    : An object defining an XT cone surface.
//
// Enums          :
//
// Includes       : JtkXTCone.h
//
// Inheritance    : JtkXTSurface > JtkXTCone
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTCone : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTCone )

public:
   virtual int    getInternals( double* &location, 
                                double* &reference,
                                double* &axis, 
                                double  &radius,
                                double  &halfAngle, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                double* &location, 
                                double* &reference,
                                double* &axis, 
                                double  &radius,
                                double  &halfAngle,
                                int     &error ) = 0;

   int            operator == ( const JtkXTCone &OtherSurface )const;

protected:
   JtkXTCone();
   virtual  ~JtkXTCone();
};

#endif

