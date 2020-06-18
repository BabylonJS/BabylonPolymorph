////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SWEPT_SURFACE_HXX
#define JTK_XT_SWEPT_SURFACE_HXX

#include <JtTk/JtkXTSurface.h>

class JtkXTCurve;

///////%{
//
// Class          : JtkXTSwept
//
// Description    : An object defining an XT swept surface.
//
// Enums          :
//
// Includes       : JtkXTSwept.h
//
// Inheritance    : JtkXTSurface > JtkXTSwept
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSwept : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTSwept )

public:
   virtual int    getInternals( JtkXTCurve* &curve,
                                double*     &direction, 
                                int         &error ) = 0;

   int            operator == ( const JtkXTSwept &OtherSurface )const;

protected:
   JtkXTSwept();
   virtual  ~JtkXTSwept();
};

#endif

