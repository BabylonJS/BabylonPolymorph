////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SPUN_SURFACE_HXX
#define JTK_XT_SPUN_SURFACE_HXX

#include <JtTk/JtkXTSurface.h>

class JtkXTCurve;

///////%{
//
// Class          : JtkXTSpun
//
// Description    : An object defining an XT spun surface.
//
// Enums          :
//
// Includes       : JtkXTSpun.h
//
// Inheritance    : JtkXTSurface > JtkXTSpun
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSpun : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTSpun )

public:
   virtual int    getInternals( JtkXTCurve* &curve, 
                                double*     &location, 
                                double*     &axis, 
                                int         &error ) = 0;

   virtual int    getInternals( JtkUnits    units,
                                JtkXTCurve* &curve, 
                                double*     &location, 
                                double*     &axis, 
                                int         &error ) = 0;

   int            operator == ( const JtkXTSpun &OtherSurface )const;

protected:
   JtkXTSpun();
   virtual  ~JtkXTSpun();
};

#endif

