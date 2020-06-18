////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_EDGE_HXX
#define JTK_EDGE_HXX

#include <JtTk/JtkTopology.h>

// forward references
class JtkXYZCurve;
class JtkVertex;
class JtkTessParams;
class JtkLineStripSet;

///////%{
//
// Class          : JtkEdge
//
// Description    : An object defining an edge within a JtkBrep topology.
//
// Enums          :
//
// Includes       : JtkEdge.h
//
// Inheritance    : JtkTopology > JtkEdge
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkEdge : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkEdge )

public:
   // Model space curve accessor methods.
   virtual int                setCurve( JtkXYZCurve* ) = 0;
   virtual int                getCurve( JtkXYZCurve* & ) = 0;
   virtual int                deleteCurve() = 0;
   virtual int                getId( int & ) = 0;
   virtual const JtkXYZCurve* curve( void ) = 0;
   virtual int                setStartVertex( JtkVertex* ) = 0;
   virtual void               getStartVertex( JtkVertex* & ) = 0;
   virtual int                setEndVertex( JtkVertex* ) = 0;
   virtual void               getEndVertex( JtkVertex* & ) = 0;
   virtual const JtkVertex*   startVertex( void ) = 0;
   virtual const JtkVertex*   endVertex( void ) = 0;

   // User-driven tessellation API
   virtual int                tessellate( const JtkTessParams* Params, JtkLineStripSet* &TessResult ) = 0;

   int operator               ==( const JtkEdge &OtherEdge )const;

protected:
   JtkEdge();
   virtual  ~JtkEdge();
};
#endif

