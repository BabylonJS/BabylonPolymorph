////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SHELL_HXX
#define JTK_XT_SHELL_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTFacade;
class JtkXTEdge;
class JtkXTVertex;

///////%{
//
// Class          : JtkXTShell
//
// Description    : An object defining a shell within XT topology.
//
// Enums          :
//
// Includes       : JtkXTShell.h
//
// Inheritance    : JtkXTTopology > JtkXTShell
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTShell : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTShell )

public:
   // Brep hierarchy management methods
   virtual int    addChild( JtkXTFacade* facade, int &error ) = 0;
   virtual int    insertChild( JtkXTFacade* facade, int position, int &error ) = 0;
   virtual int    insertChild( JtkXTFacade* facade, JtkXTFacade* previous, int &error ) = 0;
   virtual int    getChild( JtkXTFacade* &facade, int index, int &error ) = 0;
   virtual int    deleteFacade( int index, int &error ) = 0;
   virtual int    numFacades( int &error ) = 0;

   virtual int    addChild( JtkXTEdge* edge, int &error ) = 0;
   virtual int    insertChild( JtkXTEdge* edge, int position, int &error ) = 0;
   virtual int    insertChild( JtkXTEdge* edge, JtkXTEdge* previous, int &error ) = 0;
   virtual int    getChild( JtkXTEdge* &edge, int index, int &error ) = 0;
   virtual int    deleteEdge( int index, int &error ) = 0;
   virtual int    numEdges( int &error ) = 0;

   virtual int    addChild( JtkXTVertex* vertex, int &error ) = 0;
   virtual int    getChild( JtkXTVertex* &vertex, int &error ) = 0;
   virtual int    deleteVertex( int &error ) = 0;

   int            operator == ( const JtkXTShell &rhs )const;

protected:
   JtkXTShell();
   virtual ~JtkXTShell();
};

#endif

