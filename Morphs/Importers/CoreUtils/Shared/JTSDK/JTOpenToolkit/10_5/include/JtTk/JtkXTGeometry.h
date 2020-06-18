////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_GEOMETRY_HXX
#define JTK_XT_GEOMETRY_HXX

#include <JtTk/JtkXTEntity.h>

///////%{
//
// Class          : JtkXTGeometry
//
// Description    : The base class for all renderable XT geometry.
//
// Enums          : ContinuityType
//                     C1 -- The parametrization is continuous.
//                     C2 -- The first derivatives are continuous.
//                     C3 -- The second derivatives are continuous.
//                     G1 -- The surface or curve has continuous position, i.e.
//                           it is a single piece with no gaps.
//                     G2 -- The surface has continuous normals (tangent
//                           planes), i.e. it has no sharp creases or the curve
//                           has continuous tangents, i.e. it has no sharp
//                           corners.
//                     G3 -- The surface or curve has continuous curvature.
//
// Includes       : JtkXTGeometry.h
//
// Inheritance    : JtkXTEntity > JtkXTGeometry
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTGeometry : public JtkXTEntity
{
   JTK_OBJECT_HEADER( JtkXTGeometry )

public:

   int            operator == ( const JtkXTGeometry &OtherGeometry )const;
   enum ContinuityType{
                        C1=23150,
                        C2=23151,
                        C3=23152,
                        G1=23153,
                        G2=23154,
                        G3=23155
                      };
protected:
   JtkXTGeometry();
   virtual ~JtkXTGeometry();
};

#endif
