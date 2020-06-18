////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_HARNESS_HXX
#define JTK_HARNESS_HXX

#include <JtTk/JtkTopology.h>
#include <JtTk/JtkWrepWire.h>
#include <JtTk/JtkBundle.h>

// forward references
class JtkWrepWire;
class JtkBundle;

///////%{
//
// Class          : JtkHarness
//
// Description    : An object defining a harness in a JtkWrep topology.
//
// Enums          :
//
// Includes       : JtkHarness.h
//
// Inheritance    : JtkTopology > JtkHarness
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHarness : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkHarness )

public:
   // get/set tag
   virtual int getTag( int &Tag ) = 0;
   virtual int setTag( int Tag ) = 0;
   virtual int tag() = 0;

   // Add a new bundle or wire to the harness
   virtual int addChild( JtkBundle * ) = 0;
   virtual int addChild( JtkWrepWire * ) = 0;
   virtual int getChild( JtkBundle * &, int Index ) = 0;
   virtual int getChild( JtkWrepWire * &, int Index ) = 0;
   virtual int deleteChild( JtkEntity::TypeID Type, int Index ) = 0;
   virtual int numChildren( JtkEntity::TypeID Type ) = 0;

protected:
   JtkHarness();
   virtual     ~JtkHarness();
};
#endif

