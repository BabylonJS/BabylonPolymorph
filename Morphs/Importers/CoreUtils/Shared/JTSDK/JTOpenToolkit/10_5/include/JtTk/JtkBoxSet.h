////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_BOXSET_HXX
#define JTK_BOXSET_HXX

#include <JtTk/JtkPrim.h>

///////%{
//
// Class          : JtkBoxSet
//
// Description    : Represents a collection (set) of boxes. 
//                  Each box definition requires 9 float parameters: 
//                  the x, y, and z components for 3 orthogonal vectors running
//                  along each axis of the volume encompassed by the box.
//                  The magnitude of each vector determines the extent of 
//                  the box in that direction. The origin for each box defines 
//                  its lower left-hand, front corner position.
//
// Enums          :
//
// Includes       : JtkBoxSet.h
//
// Inheritance    : JtkPrim > JtkBoxSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkBoxSet : public JtkPrim
{
   JTK_OBJECT_HEADER( JtkBoxSet )

protected:
   JtkBoxSet();
   virtual  ~JtkBoxSet();
};
#endif

