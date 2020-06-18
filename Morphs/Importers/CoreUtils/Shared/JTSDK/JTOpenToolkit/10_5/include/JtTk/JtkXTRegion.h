////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_REGION_HXX
#define JTK_XT_REGION_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTShell;

///////%{
//
// Class          : JtkXTRegion
//
// Description    : An object defining a region within XT topology.
//
// Enums          :
//
// Includes       : JtkXTRegion.h
//
// Inheritance    : JtkXTTopology > JtkXTRegion
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTRegion : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTRegion )

public:
   // Brep hierarchy management methods
   virtual int    addChild( JtkXTShell* shell, int &error ) = 0;
   virtual int    insertChild( JtkXTShell* shell, int position, int &error ) = 0;
   virtual int    insertChild( JtkXTShell* shell, JtkXTShell* previous, int &error ) = 0;
   virtual int    getChild( JtkXTShell* &shell, int index, int &error ) = 0;
   virtual int    deleteChild( int index, int &error ) = 0;
   virtual int    numChildren( int &error ) = 0;

   virtual int    setSolid( bool trueOrFalse, int &error ) = 0;
   virtual int    getSolid( bool &trueOrFalse, int &error ) = 0;

   int            operator == ( const JtkXTRegion &rhs )const;

protected:
   JtkXTRegion();
   virtual ~JtkXTRegion();
};

#endif

