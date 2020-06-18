////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_LOOP_HXX
#define JTK_XT_LOOP_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTFin;
class JtkXTVertex;

///////%{
//
// Class          : JtkXTLoop
//
// Description    : An object defining a loop within XT topology.
//
// Enums          :
//
// Includes       : JtkXTLoop.h
//
// Inheritance    : JtkXTTopology > JtkXTLoop
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTLoop : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTLoop )

public:
   // Brep hierarchy management methods
   virtual int    addChild( JtkXTFin* fin, int &error ) = 0;
   virtual int    insertChild( JtkXTFin* fin, int position, int &error ) = 0;
   virtual int    insertChild( JtkXTFin* fin, JtkXTFin* previous, int &error ) = 0;
   virtual int    getChild( JtkXTFin* &fin, int index, int &error ) = 0;
   virtual int    deleteChild( int index, int &error ) = 0;
   virtual int    numChildren( int &error ) = 0;

   virtual int    addChild( JtkXTVertex* vertex, int &error ) = 0;
   virtual int    getChild( JtkXTVertex* &vertex, int &error ) = 0;
   virtual int    deleteChild( int &error ) = 0;

   int            operator == ( const JtkXTLoop &rhs )const;

protected:
   JtkXTLoop();
   virtual ~JtkXTLoop();
};

#endif

