////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_SURFACE_HXX
#define JTK_SURFACE_HXX

#include <JtTk/JtkGeometry.h>

///////%{
//
// Class          : JtkSurface
//
// Description    : Toolkit surface class. Defines surface as extension of
//                  JtkGeometry.
//             
// Enums          : JtkSurfaceType:
//                     SCULPTURED -- Sculptured surface.
//                     PLANE -- Planar surface.
//                     CYLINDER -- Cylindrical surface.
//                     CONE -- Conic surface.
//                     SPHERE -- Spherical surface.
//                     TORUS -- Torus surface.
//                     SURFACE_OF_REVOLUTION -- Revolved surface.
//                     EXTRUDED_SURFACE -- Extruded surface.
//                     RULED_SURFACE -- Ruled surface.
//                     QUADRIC_SURFACE -- Quadric surface.
//                     PLANAR_CIRCULAR -- Planar circular surface.
//                     PLANAR_QUADRILATERAL -- Planar quadrilateral surface.
//                     UNKNOWN -- Unknown surface.
//
// Includes       : JtkSurface.h
//
// Inheritance    : JtkGeometry > JtkSurface
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkSurface : public JtkGeometry
{
   JTK_OBJECT_HEADER( JtkSurface )

public:
   enum JtkSurfaceType
   {
      SCULPTURED           = 0,
      PLANE,
      CYLINDER,
      CONE,
      SPHERE,
      TORUS,
      SURFACE_OF_REVOLUTION,
      EXTRUDED_SURFACE,
      RULED_SURFACE,
      QUADRIC_SURFACE,
      PLANAR_CIRCULAR,
      PLANAR_QUADRILATERAL,
      UNKNOWN
   };

   virtual JtkSurfaceType  type( void ) = 0;
   virtual void            setType( JtkSurfaceType type ) = 0;

   int operator            ==( const JtkSurface &OtherSurface )const;

protected:
   JtkSurface();
   virtual  ~JtkSurface();

private:
};
#endif

