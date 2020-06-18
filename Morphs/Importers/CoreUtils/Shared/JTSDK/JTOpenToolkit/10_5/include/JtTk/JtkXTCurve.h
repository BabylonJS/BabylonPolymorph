////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_CURVE_HXX
#define JTK_XT_CURVE_HXX

#include <JtTk/JtkXTGeometry.h>

///////%{
//
// Class          : JtkXTCurve
//
// Description    : Toolkit XT curve class.
//
// Enums          : JtkXTCurveType:
//                     BSPLINE -- B-spline curve.
//                     LINE -- Unbounded straight line curve.
//                     CIRCLE -- Complete circle curve.
//                     ELLIPSE -- Complete ellipse curve.
//                     SPCURVE -- Surface parameter curve.
//                     ICURVE -- Intersection curve.
//                     POLYLINE -- Polyline curve.
//
// Includes       : JtkXTCurve.h
//
// Inheritance    : JtkXTGeometry > JtkXTCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTCurve : public JtkXTGeometry
{
   JTK_OBJECT_HEADER( JtkXTCurve )

public:
   enum JtkXTCurveType
   {
      UNKNOWN = 0,
      BSPLINE,
      LINE,
      CIRCLE,
      ELLIPSE,
      SPCURVE,
      ICURVE,
      POLYLINE
   };

   virtual int getInterval( double &dStart, double &dEnd, int &nError ) = 0;

    struct NurbsConversionOptions
   {
      double dTolerance;
      bool bHaveInterval;
      bool bForceCubic;
      bool bForceNonRational;
      ContinuityType nRequiredCurveContinuity;
   };
   virtual int getNurbsRepresentation( double  pIntervalStart,
                                       double  pIntervalEnd,
                                       NurbsConversionOptions& NurbsOpts,
                                       int     &degree,
                                       int     &numCtlPts,
                                       int     &dimension,
                                       bool    &isRational,
                                       double* &ctlPts,
                                       int     &numKnots,
                                       int*    &knotMult,
                                       double* &knots,
                                       bool    &isPeriodic,
                                       bool    &isClosed,
                                       int     &nError ) = 0;

   virtual JtkXTCurveType  getType() = 0;
   virtual void            setType( JtkXTCurveType type ) = 0;

   int         operator == ( const JtkXTCurve &OtherCurve )const;

protected:
   JtkXTCurve();
   virtual ~JtkXTCurve();
};

#endif

