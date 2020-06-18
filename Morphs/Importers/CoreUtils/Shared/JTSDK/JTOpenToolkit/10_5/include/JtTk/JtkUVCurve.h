////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_UV_CURVE_HXX
#define JTK_UV_CURVE_HXX

#include <JtTk/JtkNURBSCurve.h>

///////%{
//
// Class          : JtkUVCurve
//
// Description    : The parametric (UV) curve object.
//
// Enums          :
//
// Includes       : JtkUVCurve.h
//
// Inheritance    : JtkNURBSCurve > JtkUVCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkUVCurve : public JtkNURBSCurve
{
   JTK_OBJECT_HEADER( JtkUVCurve )

public:
   // Set the NURBS knot vector.  The length of this vector is implied by
   // the degree and # of control points specified by the construction
   // arguments.  The method returns Jtk_ERROR in cases of illegal input.
   virtual int          setKnots( double* knots ) = 0;

   // Set the control point vector.  The length of the given vector is
   // implied by the # of control points specified by the construction
   // arguments and _nCoordsPerPoint_ argument.  The method returns
   // Jtk_ERROR in cases of illegal input.
   //
   // Packing order:
   //     Non-Rational: (xy,xy,xy,...),    nCoordsPerPoint = 2
   //     Rational:     (xyw,xyw,xyw,...), nCoordsPerPoint = 3
   virtual int          setControlPoints( double* ctlPts,
                                          int      nCoordsPerPoint ) = 0;

   // Retrieve the NURBS info. This method allocates
   // memory for the knot vector and control point array.
   // It is the users responsibility to delete the arrays.
   virtual int          getInternals( int     &du,
                                      int     &numKnots,
                                      int     &numCtlPoints,
                                      double* &knots,
                                      double* &ctlPoints,
                                      int     &nCoordsPerPoint ) = 0;

   int operator         ==( const JtkUVCurve &OtherCurve )const;

protected:
   JtkUVCurve();
   virtual  ~JtkUVCurve();
};
#endif

