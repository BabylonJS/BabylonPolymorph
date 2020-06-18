////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_VERTEX_HXX
#define JTK_VERTEX_HXX

#include <JtTk/JtkTopology.h>

// forward references
class JtkPoint;
class JtkEdge;

///////%{
//
// Class          : JtkVertex
//
// Description    : The vertex point object.
//
// Enums          :
//
// Includes       : JtkVertex.h
//
// Inheritance    : JtkTopology > JtkVertex
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkVertex : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkVertex )

public:
   // point accessor methods.
   virtual int             setPoint( JtkPoint * ) = 0;
   virtual int             getPoint( JtkPoint * & ) = 0;
   virtual int             deletePoint() = 0;

   // edge accessor method.
   virtual int             addEdgeToList( JtkEdge * ) = 0;
   virtual int             getEdgeInList( JtkEdge * &, int index ) = 0;
   virtual int             deleteEdgeInList( int index ) = 0;

   int operator            ==( const JtkVertex &OtherVertex )const;

protected:
   JtkVertex();
   virtual  ~JtkVertex();
};
#endif

