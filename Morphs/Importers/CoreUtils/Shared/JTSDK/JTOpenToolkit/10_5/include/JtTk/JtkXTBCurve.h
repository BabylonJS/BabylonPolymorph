////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_BCURVE_HXX
#define JTK_XT_BCURVE_HXX

#include <JtTk/JtkXTCurve.h>

///////%{
//
// Class          : JtkXTBCurve
//
// Description    : An object defining an XT b-spline curve.
//
// Enums          :
//
// Includes       : JtkXTBCurve.h
//
// Inheritance    : JtkXTCurve > JtkXTBCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTBCurve : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTBCurve )

public:
   virtual int    getInternals( int     &degree, 
                                int     &numCtlPts, 
                                int     &dimension, 
                                bool    &isRational, 
                                double* &ctlPts, 
                                int     &numKnots, 
                                int*    &knotMult, 
                                double* &knots, 
                                bool    &isPeriodic, 
                                bool    &isClosed, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
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
                                int     &error ) = 0;

   int            operator == ( const JtkXTBCurve &OtherCurve )const;

protected:
   JtkXTBCurve();
   virtual ~JtkXTBCurve();
};

#endif

