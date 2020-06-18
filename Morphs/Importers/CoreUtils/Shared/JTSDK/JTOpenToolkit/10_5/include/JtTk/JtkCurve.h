////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_CURVE_HXX
#define JTK_CURVE_HXX

#include <JtTk/JtkGeometry.h>

///////%{
//
// Class          : JtkCurve
//
// Description    : Toolkit base curve object.
//
// Enums          : JtkCurveType:
//                     SPLINE -- Spline curve.
//                     STRAIGHT -- Straight curve.
//                     CIRCULAR_ARC -- Circular curve.
//                     ELLIPTIC_ARC -- Elliptical curve.
//                     PARABOLIC_ARC -- Parabolic curve.
//                     HYPERBOLIC_ARC -- Hyperbolic curve.
//                     COMPOSITE -- Composite curve.
//                     RATIONAL_SPLINE -- Rational curve.
//                     DEGENERATE_CURVE -- Degenerate curve.
//                     UNKNOWN -- Unknown curve.
//
// Includes       : JtkCurve.h
//
// Inheritance    : JtkGeometry > JtkCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCurve : public JtkGeometry
{
   JTK_OBJECT_HEADER( JtkCurve )

public:
   enum JtkCurveType
   {
      SPLINE            = 0,
      STRAIGHT,
      CIRCULAR_ARC,
      ELLIPTIC_ARC,
      PARABOLIC_ARC,
      HYPERBOLIC_ARC,
      COMPOSITE,
      RATIONAL_SPLINE,
      DEGENERATE_CURVE,
      UNKNOWN
   };

   virtual JtkCurveType type( void ) = 0;
   virtual int         setType( JtkCurveType type ) = 0;

protected:
   JtkCurve();
   virtual  ~JtkCurve();
};
#endif

