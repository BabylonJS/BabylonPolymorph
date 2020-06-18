////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_CYLINDERSET_HXX
#define JTK_CYLINDERSET_HXX

#include <JtTk/JtkPrim.h>

///////%{
//
// Class          : JtkCylinderSet
//
// Description    : Represents a collection (set) of cylinders.
//                  Each cylinder definition requires 5 float parameters: x,
//                  y, and z components for the orthogonal vector defining the
//                  orientation and length of the cylinder, and the radius
//                  definitions for both the top and bottom ends of the 
//                  cylinder.  The origin for each cylinder defines the center 
//                  position of its first radius.  
//                  
//                  Note, cones and truncated cones can be creating using this 
//                  primitive by specifying different radii.
//
// Enums          :
//
// Includes       : JtkCylinderSet.h
//
// Inheritance    : JtkPrim > JtkCylinderSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCylinderSet : public JtkPrim
{
   JTK_OBJECT_HEADER( JtkCylinderSet )

protected:
   JtkCylinderSet();
   virtual  ~JtkCylinderSet();
};
#endif

