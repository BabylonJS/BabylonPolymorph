////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_NURBS_SURFACE_HXX
#define JTK_NURBS_SURFACE_HXX

#include <JtTk/JtkSurface.h>

///////%{
//
// Class          : JtkNURBSSurface
//
// Description    : An object defining a NURBS surfaces.
//
// Enums          :
//
// Includes       : JtkNURBSSurface.h
//
// Inheritance    : JtkSurface > JtkNURBSSurface
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkNURBSSurface : public JtkSurface
{
   JTK_OBJECT_HEADER( JtkNURBSSurface )

public:
   virtual int                setKnots( double* uKnots, double* vKnots ) = 0;
   virtual int                setControlPoints( double   *ctlPts,
                                                int      nCoordsPerPoint ) = 0;
   virtual int                getInternals( int     &du,
                                            int     &dv,
                                            int     &nKnotsU,
                                            int     &nKnotsV,
                                            int     &nu,
                                            int     &nv,
                                            double* &knu,
                                            double* &knv,
                                            double* &ctlPoints,
                                            int     &dimension ) = 0;

   int operator               ==( const JtkNURBSSurface &OtherSurface )const;

protected:
   JtkNURBSSurface();
   virtual  ~JtkNURBSSurface();
};
#endif

