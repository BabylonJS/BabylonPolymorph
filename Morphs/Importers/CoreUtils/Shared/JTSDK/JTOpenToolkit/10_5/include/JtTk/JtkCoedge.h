////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_COEDGE_HXX
#define JTK_COEDGE_HXX

#include <JtTk/JtkTopology.h>

// forward references
class JtkEdge;
class JtkUVCurve;

///////%{
//
// Class          : JtkCoedge
//
// Description    : An object for defining an association between a JtkEdge
//                  and a JtkUVCurve within a JtkBrep topology.
//
// Enums          :
//
// Includes       : JtkCoedge.h
//
// Inheritance    : JtkTopology > JtkCoedge
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCoedge : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkCoedge )

public:
   // the JtkEdge this coedge maps to.
   virtual int               setEdge( JtkEdge* ) = 0;
   virtual int               getEdge( JtkEdge* & ) = 0;
   virtual int               deleteEdge() = 0;
   virtual const JtkEdge*    edge( void ) = 0;

   // edgeDirection = 1 (default value) or -1,
   // depending on whether the edge is in the same or
   // opposite direction relative to the coedge.
   virtual int               setEdgeDirection( int ) = 0;
   virtual int               getEdgeDirection( int & ) = 0;

   // the parameter space curve representation for this edge.
   virtual int               setCurve( JtkUVCurve* ) = 0;
   virtual int               getCurve( JtkUVCurve* & ) = 0;
   virtual int               deleteCurve() = 0;

   virtual const JtkUVCurve* curve( void ) = 0;

   int operator              ==( const JtkCoedge & )const;

protected:
   JtkCoedge();
   virtual  ~JtkCoedge();
};
#endif

