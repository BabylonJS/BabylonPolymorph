////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_SEGMENT_HXX
#define JTK_SEGMENT_HXX

#include <stdlib.h>
#include <JtTk/JtkTopology.h>
#include <JtTk/JtkBundle.h>
#ifdef _WIN32
#include <stddef.h>
#endif

///////%{
//
// Class          : JtkSegment
//
// Description    : An object defining a segment within a JtkWrep topology.
//
// Enums          :
//
// Includes       : JtkSegment.h
//
// Inheritance    : JtkTopology > JtkSegment
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkSegment : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkSegment )

public:
   // get/set tag
   virtual int getTag( int &Tag ) = 0;
   virtual int setTag( int Tag ) = 0;
   virtual int tag() = 0;

   // set/get the bundle association for this segment
   virtual int setBundle( JtkBundle * ) = 0;
   virtual int getBundle( JtkBundle * & ) = 0;

protected:
   JtkSegment();
   virtual     ~JtkSegment();
};
#endif

