////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_XT_BODY_HXX
#define JTK_XT_BODY_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTRegion;
class JtkEntityList;
class JtkTessParams;
class JtkXTBodyMoniker;

///////%{
//
// Class          : JtkXTBody
//
// Description    : An object defining a body within XT topology.
//
// Enums          : JtkXTBodyType
//                      JtkBODY_TYPE_UNKNOWN -- The body type is either unknown or
//                         cannot be determined from the given topology.
//                      JtkBODY_TYPE_MINIMUM -- A topologically zero-dimensional 
//                         manifold body containing a single isolated vertex.
//                      JtkBODY_TYPE_ACORN -- A topologically zero-dimensional 
//                         manifold body containing two or more isolated vertices.
//                      JtkBODY_TYPE_WIRE -- A topologically one-dimensional manifold 
//                         body containing one or more connected sets of edges, where
//                         any vertex is at the junction of no more than two edges.
//                      JtkBODY_TYPE_SHEET -- A topologically two-dimensional manifold
//                         body containing one or more connected sets of faces, where
//                         any edge is at the junction of no more than two faces.
//                      JtkBODY_TYPE_SOLID -- A topologically three-dimensional 
//                         manifold body containing one or more disjoint and separate 
//                         solid regions. All faces form a boundary between a solid
//                         and a void region.
//                      JtkBODY_TYPE_GENERAL -- A body which is non-manifold or of
//                         mixed topological dimensionality (or both).
//                      JtkBODY_TYPE_COMPOUND -- A body which has shared XT Geometry in it
//
//                  JtkXTFacetGeometryType
//                      JtkFACET_GEOMETRY_TYPE_UNKNOWN -- The facet geometry type is either unknown or
//                         cannot be determined from the given geometry.
//                      JtkFACET_GEOMETRY_TYPE_NONE -- The body contains no facet geometry.
//                      JtkFACET_GEOMETRY_TYPE_ALL -- All the geometry of the body is facet based.
//                      JtkFACET_GEOMETRY_TYPE_MIXED -- The body contains both facet and non-facet based geometry.
//
// Includes       : JtkXTBody.h
//
// Inheritance    : JtkXTTopology > JtkXTBody
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTBody : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTBody )

public:
   enum JtkXTBodyType
   {
      JtkBODY_TYPE_UNKNOWN = 0,
      JtkBODY_TYPE_MINIMUM,
      JtkBODY_TYPE_ACORN,
      JtkBODY_TYPE_WIRE,
      JtkBODY_TYPE_SHEET,
      JtkBODY_TYPE_SOLID,
      JtkBODY_TYPE_GENERAL,
      JtkBODY_TYPE_COMPOUND
   };

   enum JtkXTFacetGeometryType
   {
      JtkFACET_GEOMETRY_TYPE_UNKNOWN = 0,
      JtkFACET_GEOMETRY_TYPE_NONE,
      JtkFACET_GEOMETRY_TYPE_ALL,
      JtkFACET_GEOMETRY_TYPE_MIXED
   };

   // Brep hierarchy management methods
   virtual int    addChild( JtkXTRegion* region, int &error ) = 0;
   virtual int    insertChild( JtkXTRegion* region, int position, int &error ) = 0;
   virtual int    insertChild( JtkXTRegion* region, JtkXTRegion* previous, int &error ) = 0;
   virtual int    getChild( JtkXTRegion* &region, int index, int &error ) = 0;
   virtual int    deleteChild( int index, int &error ) = 0;
   virtual int    numChildren( int &error ) = 0;

   // Allow user to generate texture coordinates when tessellating.
   // Off by default.
   virtual int    texCoordGenerationON( int &error ) = 0;
   virtual int    texCoordGenerationOFF( int &error ) = 0;

   // Allow user to write nominal geometry when using tolerant models.
   // Off by default.
   virtual int    setWriteNominalGeom( bool writeNominalGeom, int &error ) = 0;
   virtual int    getWriteNominalGeom( bool &writeNominalGeom, int &error ) = 0;

   virtual int    setBodyId( int BodyId, int& Error ) = 0;
   virtual int    getBodyId( int& BodyId, int& Error ) = 0;
   static int     setBodyId( PK_BODY_t XTBody, int BodyId,  int& Error );
   static int     getBodyId( PK_BODY_t XTBody, int& BodyId, int& Error );

   // Allow user to set the cleaning tolerance.
   virtual int    setCleaningTolerance( double tolerance, int &error ) = 0;
   virtual int    setCleaningTolerance( JtkUnits units, double tolerance, int &error ) = 0;
   virtual int    getCleaningTolerance( double &tolerance, int &error ) = 0;
   virtual int    getCleaningTolerance( JtkUnits units, double &tolerance, int &error ) = 0;
   
   // Allow user to check the validity of the body.
   virtual int    checkValidity( int &numFaults, JtkEntityList* &pFaultsList, int &error ) = 0;

   // Allow user to check the XT body type
   virtual int    findType( JtkXTBodyType &type, int &error ) = 0;

   // and the facet Geometry type
   virtual int    findFacetGeometryType(JtkXTFacetGeometryType& Type, int& Error) const = 0;

   // Allow user to check xt data structure is correct
   virtual int    checkXTBody( int &numFaults, JtkEntityList* &pFaultsList, int &error ) = 0;
   // Debug print-out mechanism.
   // prints to "outputFile" if given, otherwise "JtkXTBodyInfo.out".
   virtual int    print( const JtkString& outputFile, int &error ) = 0;
   virtual int    print( JtkUnits units, const JtkString& outputFile, int &error ) = 0;

   // Debug XML print-out mechanism.
   // prints to "outputFile" if given, otherwise "JtkXTBodyInfo.xml".
   virtual int    printXML( const JtkString& outputFile, int &error ) = 0;
   virtual int    printXML( JtkUnits units, const JtkString& outputFile, int &error ) = 0;

   // User-driven Tessellation methods
   virtual int    tessellate( const JtkTessParams* Params, JtkEntityList* &TessResult ) = 0;
   virtual int    tessellate( JtkUnits Units, const JtkTessParams* Params, JtkEntityList* &TessResult ) = 0;
   virtual int    tessellate( const JtkTessParams* Params, JtkEntityList* &TessResult, JtkEntityList* &pFaults ) = 0;
   virtual int    tessellate( JtkUnits Units, const JtkTessParams* Params, JtkEntityList* &TessResult, JtkEntityList* &pFaults ) = 0;
   static int     tessellate( PK_BODY_t body, const JtkTessParams* Params, JtkEntityList* &TessResult );
   static int     tessellate( JtkUnits Units, PK_BODY_t body, const JtkTessParams* Params, JtkEntityList* &TessResult );
   static int     tessellate( PK_BODY_t body, const JtkTessParams* Params, JtkEntityList* &TessResult, JtkEntityList* &pFaults );
   static int     tessellate( JtkUnits Units, PK_BODY_t body, const JtkTessParams* Params, JtkEntityList* &TessResult, JtkEntityList* &pFaults );

   // Monikers related APIs
   virtual int    addBodyMoniker( JtkXTBodyMoniker* BodyMoniker ) = 0;
   virtual int    numBodyMonikers( ) = 0;
   virtual int    getBodyMoniker( JtkXTBodyMoniker*& BodyMoniker, int Index ) = 0;
   virtual int    deleteBodyMoniker( int Index ) = 0;

   int            operator == ( const JtkXTBody &rhs )const;

protected:
   JtkXTBody();
   virtual ~JtkXTBody();
};

#endif

