////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_WREPWIRE_HXX
#define JTK_WREPWIRE_HXX

#include <stdlib.h>
#include <JtTk/JtkTopology.h>
#include <JtTk/JtkHarness.h>
#include <JtTk/JtkSegment.h>
#ifdef _WIN32
#include <stddef.h>
#endif

///////%{
//
// Class          : JtkWrepWire
//
// Description    : The object defining a wrep wire within a JtkWrep topology.
//
// Enums          :
//
// Includes       : JtkWrepWire.h
//
// Inheritance    : JtkTopology > JtkWrepWire
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkWrepWire : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkWrepWire )

public:
   // get/set tag
   virtual int getTag( int &Tag ) = 0;
   virtual int setTag( int Tag ) = 0;
   virtual int tag() = 0;

   // set wrep wire attributes
   virtual int setRadius( double Radius ) = 0;
   virtual int getRadius( double &Radius ) = 0;
   virtual int setMultiplicity( int Mult ) = 0;
   virtual int getMultiplicity( int &Mult ) = 0;
   virtual int setColor( float RGBA[4] ) = 0;
   virtual int setColor( JtkMaterial *material ) = 0; // for convenience only, the RGB values are *copied* from the material.
   virtual int getColor( float * &RGBA ) = 0;

   // Add a new segment to the current wrep wire
   virtual int addChild( JtkSegment * ) = 0;
   virtual int getChild( JtkSegment * &, int index ) = 0;
   virtual int deleteChild( int index ) = 0;
   virtual int numChildren() = 0;

protected:
   JtkWrepWire();
   virtual     ~JtkWrepWire();
};
#endif

