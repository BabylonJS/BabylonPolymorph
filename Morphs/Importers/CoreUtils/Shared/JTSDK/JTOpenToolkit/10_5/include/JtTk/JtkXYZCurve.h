////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XYZ_CURVE_HXX
#define JTK_XYZ_CURVE_HXX

#include <JtTk/JtkNURBSCurve.h>

///////%{
//
// Class          : JtkXYZCurve
//
// Description    : The model-space (XYZ) curve object.
//
// Enums          :
//
// Includes       : JtkXYZCurve.h
//
// Inheritance    : JtkNURBSCurve > JtkXYZCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXYZCurve : public JtkNURBSCurve
{
   JTK_OBJECT_HEADER( JtkXYZCurve )

public:
   virtual int             setKnots( double* knots ) = 0;
   virtual int             setControlPoints( double* ctlPts,
                                             int     nCoordsPerPoint ) = 0;
   virtual int             getInternals( int     &du,
                                         int     &numKnots,
                                         int     &numCtlPoints,
                                         double* &knots,
                                         double* &ctlPoints,
                                         int     &dimension ) = 0;
   virtual int             reverseDirection() = 0;

   int operator            ==( const JtkXYZCurve &OtherCurve )const;

protected:
   JtkXYZCurve();
   virtual  ~JtkXYZCurve();
};
#endif

