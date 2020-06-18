////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_REGION_HXX
#define JTK_REGION_HXX

#include <JtTk/JtkTopology.h>

// forward references
class JtkShell;

///////%{
//
// Class          : JtkRegion
//
// Description    : An object defining a region within a JtkBrep topology.
//
// Enums          :
//
// Includes       : JtkRegion.h
//
// Inheritance    : JtkTopology > JtkRegion
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkRegion : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkRegion )

public:
   virtual int          addChild( JtkShell * ) = 0;
   virtual int          getChild( JtkShell * &, int index ) = 0;
   virtual int          deleteChild( int index ) = 0;
   virtual int          numChildren() = 0;

   int operator         ==( const JtkRegion &OtherRegion )const;

protected:
   JtkRegion();
   virtual  ~JtkRegion();
};
#endif

