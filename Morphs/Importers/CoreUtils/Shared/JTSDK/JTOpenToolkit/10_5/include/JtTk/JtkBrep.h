////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_BREP_HXX
#define JTK_BREP_HXX

#include <stdlib.h>
#include <JtTk/JtkTopology.h>
#ifdef _WIN32
#include <stddef.h>
#endif

#include <JtTk/JtkString.h>

// forward declarations
class JtkRegion;
class JtkWire;
class JtkPoint;
class JtkEdge;
class VisPartNode;
class JtkTessParams;
class JtkEntityList;

///////%{
//
// Class          : JtkBrep
//
// Description    : The class for the root object of the toolkit's NURBS 
//                  geometry topology.  Each child of the brep representation 
//                  is of type JtkRegion.
//
// Enums          :
//
// Includes       : JtkBrep.h
//
// Inheritance    : JtkTopology > JtkBrep
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkBrep : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkBrep )

public:
   // Add a new region to the current boundary-representation.
   virtual int       addChild( JtkRegion * ) = 0;
   virtual int       addChild( JtkWire * ) = 0;
   virtual int       addChild( JtkEdge * ) = 0;
   virtual int       getChild( JtkRegion * &, int index ) = 0;
   virtual int       getChild( JtkWire * &, int index ) = 0;
   virtual int       getChild( JtkEdge * &, int index ) = 0;
   virtual int       deleteChild( JtkEntity::TypeID type, int index ) = 0;
   virtual int       numChildren( JtkEntity::TypeID type ) = 0;

   // Allow user to generate texture coordinates when tessellating
   // Off by default.
   virtual void      texCoordGenerationON() = 0;
   virtual void      texCoordGenerationOFF() = 0;

   // Set the axis-aligned bounding box for the topology.  Used in
   // calculating tessellation constraints.
   virtual int       setBBox( JtkPoint *lowerCorner,
                                 JtkPoint *upperCorner ) = 0;

   virtual int       getBBox( JtkPoint * &lowerCorner,
                                 JtkPoint * &upperCorner ) = 0;

   virtual void      calcBBox() = 0;

   // Debug print-out mechanism.
   // prints to "outputFile" if given, otherwise "JtkBrepInfo.out".
   virtual int       print( const JtkString& outputFile = JtkString( ) ) = 0;

   int operator      ==( const JtkBrep &OtherBrep )const;

   // Allows user to manually perform tessellation of the Brep
   virtual int       tessellate( const JtkTessParams* Params,
                                 JtkEntityList* &TessResult ) = 0;

protected:
   JtkBrep();
   virtual           ~JtkBrep();
};
#endif

