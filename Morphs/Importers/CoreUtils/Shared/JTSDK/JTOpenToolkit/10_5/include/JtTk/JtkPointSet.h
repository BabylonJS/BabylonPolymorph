////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_POINTSET_HXX
#define JTK_POINTSET_HXX

#include <JtTk/JtkShape.h>
#include <JtTk/JtkAttrib.h>

///////%{
//
// Class          : JtkPointSet
//
// Description    : A point set object.  Each point in the set is defined by
//                  consecutive (x,y,z) values.
//
// Enums          : pointType:
//                   JtkSQUARE --
//                   JtkCIRCLE --
//
//                  pointWidth:
//                   JtkNORMAL --
//                   JtkTHICK --
//                   JtkTHIN --
//
// Includes       : JtkPointSet.h
//
// Inheritance    : JtkShape > JtkPointSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPointSet : public JtkShape
{
   JTK_OBJECT_HEADER( JtkPointSet )

public:
   // point style
   enum pointType
   {
      JtkSQUARE,            
      JtkCIRCLE
      // TBD - more point types
   };

   enum pointWidth
   {
      JtkNORMAL,
      JtkTHICK,
      JtkTHIN
   };

   virtual int setDrawStyle( pointType type = JtkSQUARE,
                             pointWidth width = JtkNORMAL ) = 0;
   virtual void getDrawStyle( pointType& type, pointWidth& width ) = 0;

protected:
   JtkPointSet();
   virtual  ~JtkPointSet();
};
#endif

