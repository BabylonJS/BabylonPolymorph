////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_TOPO_HXX
#define JTK_TOPO_HXX

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkTopology
//
// Description    : A base class for all topological geometry definition
//                  objects.
//
// Enums          :
//
// Includes       : JtkTopology.h
//
// Inheritance    : JtkRefCounted > JtkTopology
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTopology : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkTopology )

public:
   void                   setIndex( int i );
   int                    index();
   int                    alreadySaved();

   int operator            ==( const JtkTopology &OtherTopology )const;

protected:
   JtkTopology();
   virtual  ~JtkTopology();

   int      _index;
   int      _alreadySaved;
};

#include <JtTk/JtkBrep.h>
#include <JtTk/JtkRegion.h>
#include <JtTk/JtkShell.h>
#include <JtTk/JtkFace.h>
#include <JtTk/JtkLoop.h>
#include <JtTk/JtkCoedge.h>
#include <JtTk/JtkEdge.h>
#include <JtTk/JtkWire.h>
#include <JtTk/JtkVertex.h>
#endif

