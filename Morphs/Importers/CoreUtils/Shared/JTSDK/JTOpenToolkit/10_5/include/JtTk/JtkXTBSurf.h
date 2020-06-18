////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_BSURF_HXX
#define JTK_XT_BSURF_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTBSurf
//
// Description    : An object defining an XT b-spline surface.
//
// Enums          :
//
// Includes       : JtkXTBSurf.h
//
// Inheritance    : JtkXTSurface > JtkXTBSurf
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTBSurf : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTBSurf )

public:
   virtual int    getInternals( int     &uDegree, 
                                int     &vDegree, 
                                int     &uNumCtlPts, 
                                int     &vNumCtlPts, 
                                int     &dimension, 
                                bool    &isRational, 
                                double* &uvCtlPts, 
                                int     &uNumKnots, 
                                int     &vNumKnots, 
                                int*    &uKnotMult, 
                                int*    &vKnotMult, 
                                double* &uKnots, 
                                double* &vKnots, 
                                bool    &uIsPeriodic, 
                                bool    &vIsPeriodic, 
                                bool    &uIsClosed, 
                                bool    &vIsClosed, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                int     &uDegree, 
                                int     &vDegree, 
                                int     &uNumCtlPts, 
                                int     &vNumCtlPts, 
                                int     &dimension, 
                                bool    &isRational, 
                                double* &uvCtlPts, 
                                int     &uNumKnots, 
                                int     &vNumKnots, 
                                int*    &uKnotMult, 
                                int*    &vKnotMult, 
                                double* &uKnots, 
                                double* &vKnots, 
                                bool    &uIsPeriodic, 
                                bool    &vIsPeriodic, 
                                bool    &uIsClosed, 
                                bool    &vIsClosed,
                                int     &error ) = 0;

   int            operator == ( const JtkXTBSurf &OtherSurface )const;

protected:
   JtkXTBSurf();
   virtual  ~JtkXTBSurf();
};

#endif

