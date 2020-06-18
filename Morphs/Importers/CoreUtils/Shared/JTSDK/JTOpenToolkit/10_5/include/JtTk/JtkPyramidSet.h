////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PYRAMIDSET_HXX
#define JTK_PYRAMIDSET_HXX

#include <JtTk/JtkPrim.h>

///////%{
//
// Class          : JtkPyramidSet
//
// Description    : Represents a collection (set) of pyramids.
//                  Each pyramid definition requires 9 float parameters:  the
//                  x, y, and z components for 3 orthogonal vectors
//                  running along each axis of the volume encompassed by the
//                  pyramid. The magnitude of each vector determines the extent of 
//                  the pyramid in that direction.
//                  The origin for each pyramid defines the center of its base.
//
// Enums          :
//
// Includes       : JtkPyramidSet.h
//
// Inheritance    : JtkPrim > JtkPyramidSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPyramidSet : public JtkPrim
{
   JTK_OBJECT_HEADER( JtkPyramidSet )

protected:
   JtkPyramidSet();
   virtual  ~JtkPyramidSet();
};
#endif

