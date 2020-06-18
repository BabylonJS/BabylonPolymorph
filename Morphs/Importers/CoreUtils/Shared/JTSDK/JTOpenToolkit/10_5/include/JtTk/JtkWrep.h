////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_WREP_HXX
#define JTK_WREP_HXX

#include <stdlib.h>
#include <JtTk/JtkString.h>
#include <JtTk/JtkTopology.h>
#ifdef _WIN32
#include <stddef.h>
#endif

// forward declarations
class JtkHarness;

///////%{
//
// Class          : JtkWrep
//
// Description    : The main topology object for representing wire harness.
//
// Enums          :
//
// Includes       : JtkWrep.h
//
// Inheritance    : JtkTopology > JtkWrep
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkWrep : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkWrep )

public:
   // get/set tag
   virtual int getTag( int &Tag ) = 0;
   virtual int setTag( int Tag ) = 0;
   virtual int tag() = 0;

   // Add a new harness to the current wrep
   virtual int addChild( JtkHarness * ) = 0;
   virtual int getChild( JtkHarness * &, int index ) = 0;
   virtual int deleteChild( int index ) = 0;
   virtual int numChildren() = 0;

   virtual int print( const JtkString& OutFile = JtkString( ) ) = 0;

protected:
   JtkWrep();
   virtual     ~JtkWrep();
};
#endif

