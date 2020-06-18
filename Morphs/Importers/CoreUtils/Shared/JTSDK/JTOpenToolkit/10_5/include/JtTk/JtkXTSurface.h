////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SURFACE_HXX
#define JTK_XT_SURFACE_HXX

#include <JtTk/JtkXTGeometry.h>

///////%{
//
// Class          : JtkXTSurface
//
// Description    : Toolkit XT surface class.
//
// Enums          : JtkXTSurfaceType:
//                     BSPLINE -- Sculptured surface.
//                     PLANE -- Planar surface.
//                     CYLINDER -- Cylindrical surface.
//                     CONE -- Conic surface.
//                     SPHERE -- Spherical surface.
//                     TORUS -- Torus surface.
//                     OFFSET -- Offset surface.
//                     SWEPT -- Swept surface.
//                     SPUN -- Spun surface.
//                     BLEND -- Blend surface.
//                     MESH -- Facet Mesh surface.
//
// Includes       : JtkXTSurface.h
//
// Inheritance    : JtkXTGeometry > JtkXTSurface
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSurface : public JtkXTGeometry
{
   JTK_OBJECT_HEADER( JtkXTSurface )

public:
   enum JtkXTSurfaceType
   {
      UNKNOWN = 0,
      BSPLINE,
      PLANE,
      CYLINDER,
      CONE,
      SPHERE,
      TORUS,
      OFFSET,
      SWEPT,
      SPUN,
      BLEND,
      MESH
   };

   virtual int getUVBox( double &dU1, double &dV1, double &dU2, double &dV2,
                         int& nError ) = 0;

   struct NurbsConversionOptions
   {
      double dTolerance;
      bool bHaveUVBox;
      bool bForceCubic;
      bool bForceNonRational;
      ContinuityType nRequiredSurfContinuity;
   };
   virtual int getNurbsRepresentation( double  dU1,
                                       double  dV1,
                                       double  dU2,
                                       double  dV2,
                                       NurbsConversionOptions& NurbsOpts,
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
                                       int     &nError ) = 0;
   virtual JtkXTSurfaceType   getType() = 0;
   virtual void               setType( JtkXTSurfaceType type ) = 0;

   int           operator == ( const JtkXTSurface &OtherSurface )const;

protected:
   JtkXTSurface();
   virtual ~JtkXTSurface();

private:
};

#endif

