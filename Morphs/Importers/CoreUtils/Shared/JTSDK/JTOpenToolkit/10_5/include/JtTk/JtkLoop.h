////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_LOOP_HXX
#define JTK_LOOP_HXX

#include <JtTk/JtkTopology.h>

// forward declarations
class JtkCoedge;

///////%{
//
// Class          : JtkLoop
//
// Description    : NURBS loop entity (composed of successive xyz, uv
//                  curve pairs).
//
// Enums          : JtkHoleType:
//                     Jtk_NOT_SET -- Unspecified loop traversal.
//                     Jtk_ANTIHOLE -- Counter-clockwise loop traversal.
//                     Jtk_HOLE -- Clockwise loop traversal.
//
// Includes       : JtkLoop.h
//
// Inheritance    : JtkTopology > JtkLoop
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLoop : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkLoop )

public:
   // Specification of loop type.  Based on this type, the loop is traversed
   // either in clockwise or counter-clockwise order.  In either case,
   // surface data "on the left" is kept and the rest is trimmed.
   enum JtkHoleType
   {
      Jtk_NOT_SET,
      Jtk_ANTIHOLE,  // CCW traversal.
      Jtk_HOLE       // CW traversal.
   };

   // Hole type accessor methods.
   virtual int setHoleType( JtkHoleType ) = 0;
   virtual int getHoleType( JtkHoleType & ) = 0;
   virtual JtkHoleType holeType( void ) = 0;

   // Add edges for construction of the loop.
   virtual int addChild( JtkCoedge * ) = 0;
   virtual int getChild( JtkCoedge * &c1, int index ) = 0;
   virtual int deleteChild( int index ) = 0;
   virtual int numChildren() = 0;

   int operator==( const JtkLoop &OtherLoop )const;

protected:
   JtkLoop();
   virtual~JtkLoop();
};
#endif

