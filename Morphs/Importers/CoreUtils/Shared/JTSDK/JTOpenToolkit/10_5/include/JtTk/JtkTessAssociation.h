////////////////////////////////////////////////////////////////////////////////
// Copyright 2007 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_TESS_ASSOCIATION_HXX
#define JTK_TESS_ASSOCIATION_HXX

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkHierarchy.h>
#include <JtTk/JtkStandard.h>

class JtkTessAssociation;
class JtkTessGroup;

class JtkBrep;
class JtkFace;
class JtkEdge;
class JtkXTBody;
class JtkXTFace;
class JtkXTEdge;
class JtkLineStripSet;
class JtkTriStripSet;
class JtkEntityList;
class JtkPart;

///////%{
//
// Class          : JtkTessGroup
//
// Description    : A tessellation group is an object that groups tri-strips
//                  contained within a tri-strip set together with a precise
//                  geometry face.
//
// Enums          : FaceType
//                  tFaceNone -- The tessellation group has no brep face.
//                  tFaceJtkFace -- The tessellation group has a JtkBrep face.
//                  tFaceJtkXTFace -- The tessellation group has a JtkXT face.
//                  tFacePKFace -- The tessellation group has a Parasolid face.
//
// Includes       : JtkTessAssociation.h
//
// Inheritance    : JtkRefCounted > JtkTessGroup
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTessGroup : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkTessGroup )

public:
   enum FaceType {
      tFaceNone = 0,
      tFaceJtkFace,
      tFaceJtkXTFace,
      tFacePKFace
   };

   // Hierarchy
   virtual JtkTessAssociation* parent() = 0;

   // Facet data access
   virtual int getTriStripSet( JtkTriStripSet* &OutTSSet ) = 0;
   virtual int setTriStripSet( JtkTriStripSet* TSSet ) = 0;
   virtual int getNumSets( int &NumSets ) = 0;
   virtual int getSetNum( int i, int &OutSetNum ) = 0;
   virtual int addSetNum( int SetNum ) = 0;

   // Face data access
   virtual int hasFace() = 0;
   virtual int getFaceType( FaceType &OutType ) = 0;
   virtual int getFace( JtkFace* &OutFace ) = 0;
   virtual int setFace( JtkFace* Face ) = 0;
   virtual int getFace( JtkXTFace* &OutFace ) = 0;
   virtual int setFace( JtkXTFace* Face ) = 0;
   virtual int getFace( PK_FACE_t &OutFace ) = 0;
   virtual int setFace( PK_FACE_t Face ) = 0;

   // Method to extract the tessellation group border edges (face boundary edges)
   virtual int getBoundaryEdges( JtkLineStripSet* &OutEdges ) = 0;
   
   // Method for constructing the boundary edges of this JtkTessGroup with matching precise edges
   virtual int getBoundaryEdges( JtkEntityList* &OutPreciseEdges, JtkLineStripSet* &OutEdges, const JtkUnits unit = JtkUNKNOWN ) = 0;
   virtual int getBoundaryEdges( PK_FIN_t* &OutPreciseEdges, JtkLineStripSet* &OutEdges, const JtkUnits unit = JtkUNKNOWN ) = 0;
   
   // Data Verification (checks all vertices to see if they are on the face)
   // Positive values from [0.0,1.0] indicate relative epsilon to the face bounding box, ideally
   // the best epsilon to use here is the absolute chordal value that was used during tessellation.
   // By default we assume within 10% good enough balance for verification (don't want to try to be too tight).
   virtual int verify( const JtkUnits unit = JtkUNKNOWN, const float eps = 0.1f ) = 0;

   // Standard operators
   bool operator==( const JtkTessGroup& grp ) const;

   // For grouping facets by TopoMesh face group without precise geometry
   static int buildGroupList( JtkEntityList* tsSetList, JtkEntityList* &OutGrpList );

protected:
   JtkTessGroup();
   virtual ~JtkTessGroup();
};

///////%{
//
// Class          : JtkTessAssociation
//
// Description    : Constructs and manages JtkTessGroup instances
//                  while providing multiple indexes to access the tessellation groups.
//
// Enums          :
//
// Includes       : JtkTessAssociation.h
//
// Inheritance    : JtkRefCounted > JtkTessAssociation
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTessAssociation : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkTessAssociation )

public:
   // Methods for initializing the association tables for query.
   virtual int buildAssociations( JtkBrep* brep, JtkEntityList* tsSetList ) = 0;
   virtual int buildAssociations( JtkEntityList* jtkXtBodyList, JtkEntityList* tsSetList ) = 0;
   virtual int buildAssociations( PK_BODY_t* xtBodyList, int numBodies, JtkEntityList* tsSetList ) = 0;
   virtual int buildAssociations( JtkEntityList* tsSetList ) = 0;

   // Method to apply association tables to part.
   // Note, this will update underlying JtkShape geometry on the part.
   virtual int applyAssociations(JtkPart* part) = 0;
   
   // Access to tessellation groups by index
   virtual int numTessGroups( int &c ) = 0;
   virtual int getTessGroup( int i, JtkTessGroup* &OutGrp ) = 0;
   virtual int findTessGroup( JtkTessGroup* grp, int &i ) = 0;
   virtual int removeTessGroups( int i, int c = 1 ) = 0;

   // Access to tessellation groups by pointer
   virtual int addTessGroup( JtkTessGroup* grp ) = 0;
   virtual int hasTessGroup( JtkTessGroup* grp ) = 0;
   virtual int removeTessGroup( JtkTessGroup* grp ) = 0;

   // Methods for cleaning up
   virtual int clear() = 0;
   virtual int shrink() = 0;

   // Methods for face-to-group lookups
   virtual int getGroupByFace( JtkFace* face, JtkTessGroup* &OutGrp ) = 0;
   virtual int getGroupByFace( JtkXTFace* face, JtkTessGroup* &OutGrp ) = 0;
   virtual int getGroupByFace( PK_FACE_t face, JtkTessGroup* &OutGrp ) = 0;

   // Methods for facets-to-group lookups
   virtual int getGroupByFacets( JtkTriStripSet* tsSet, int SetNum, JtkTessGroup* &OutGrp ) = 0;

protected:
   JtkTessAssociation();
   virtual ~JtkTessAssociation();
};

#endif
