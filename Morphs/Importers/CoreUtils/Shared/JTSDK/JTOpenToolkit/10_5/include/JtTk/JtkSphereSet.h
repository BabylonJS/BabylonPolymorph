////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_SPHERESET_HXX
#define JTK_SPHERESET_HXX

#include <JtTk/JtkPrim.h>

///////%{
//
// Class          : JtkSphereSet
//
// Description    : Represents a collection (set) of spheres.
//                  Each sphere definition requires 1 float parameter:  the
//                  radius of the sphere.
//                  The origin for each sphere defines its center position.
//
// Enums          :
//
// Includes       : JtkSphereSet.h
//
// Inheritance    : JtkPrim > JtkSphereSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkSphereSet : public JtkPrim
{
   JTK_OBJECT_HEADER( JtkSphereSet )

protected:
   JtkSphereSet();
   virtual  ~JtkSphereSet();
};
#endif

