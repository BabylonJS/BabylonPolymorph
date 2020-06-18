////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_BUNDLE_HXX
#define JTK_BUNDLE_HXX

#include <stdlib.h>
#include <JtTk/JtkTopology.h>
#ifdef _WIN32
#include <stddef.h>
#endif

// forward declarations
class JtkHarness;

///////%{
//
// Class          : JtkBundle
//
// Description    : An object for associating a JtkXYZCurve with
//                  a starting and ending point within a JtkWrep hierarchy.
//
// Enums          :
//
// Includes       : JtkBundle.h
//
// Inheritance    : JtkTopology > JtkBundle
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkBundle : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkBundle )

public:
   // get/set tag
   virtual int getTag( int &Tag ) = 0;
   virtual int setTag( int Tag ) = 0;
   virtual int tag() = 0;

   // set/get curve and start/end points in curve
   // note, points must be coincident with curve endpoints or an error will
   // occurr
   virtual int setCurve( JtkXYZCurve * ) = 0;
   virtual int getCurve( JtkXYZCurve * & ) = 0;
   virtual int setStartPoint( JtkPoint * ) = 0;
   virtual int getStartPoint( JtkPoint * & ) = 0;
   virtual int setEndPoint( JtkPoint * ) = 0;
   virtual int getEndPoint( JtkPoint * & ) = 0;

protected:
   JtkBundle();
   virtual     ~JtkBundle();
};
#endif

