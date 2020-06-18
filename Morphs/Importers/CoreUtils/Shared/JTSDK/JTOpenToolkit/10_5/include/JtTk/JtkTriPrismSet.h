////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_TRIPRISMSET_HXX
#define JTK_TRIPRISMSET_HXX

#include <JtTk/JtkPrim.h>

///////%{
//
// Class          : JtkTriPrismSet
//
// Description    : Represents a collection (set) of tri-prism objects.
//                  A tri-prism, which resembles half a cube, is the 3D 
//                  (extruded) equivalent of a 2D tristrip triangle.  
//                  Each tri-prism definition requires 9 float parameters:
//                  the x, y, and z components for 3 orthogonal vectors running
//                  along each axis of the volume encompassed by the tri-prism.
//                  The magnitude of each vector determines the extent of 
//                  the tri-prism in that direction.
//                  The origin for each tri-prism defines its lower left-hand, 
//                  front corner position.
//
// Enums          :
//
// Includes       : JtkTriPrismSet.h
//
// Inheritance    : JtkPrim > JtkTriPrismSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTriPrismSet : public JtkPrim
{
   JTK_OBJECT_HEADER( JtkTriPrismSet )

protected:
   JtkTriPrismSet();
   virtual  ~JtkTriPrismSet();
};
#endif

