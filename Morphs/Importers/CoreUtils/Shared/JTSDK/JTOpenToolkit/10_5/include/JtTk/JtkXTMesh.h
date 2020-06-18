////////////////////////////////////////////////////////////////////////////////
// Copyright 2018 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_XT_MESH_HXX
#define JTK_XT_MESH_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTMesh
//
// Description    : An object defining an XT mesh (facet based) surface.
//
// Enums          :
//
// Includes       : JtkXTMesh.h
//
// Inheritance    : JtkXTSurface > JtkXTMesh
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTMesh : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTMesh )

   int         operator==( const JtkXTMesh &OtherMesh ) const;

   // Populate
   virtual int addFacets( int NumFacets, double* Positions, double* Normals, int& Error ) = 0;
   virtual int addFacets( JtkUnits Units, int NumFacets, double* Positions, double* Normals, int& Error ) = 0;

   // Get number of facets
   virtual int getNumberOfFacets( int& NumFacets, int& Error ) const = 0;

   // Get all facets at once
   virtual int getInternals( int& NumFacets, int*& FacetIds, int*& VertexIds, double*& Positions, double** Normals, int& Error ) const = 0;
   virtual int getInternals( JtkUnits Units, int& NumFacets, int*& FacetIds, int*& VertexIds, double*& Positions, double** Normals, int& Error ) const = 0;

   // Incremental access to facets
   virtual int getInternals( int StartFacetId, int MaxNumFacets, int& NumFacets, int*& FacetIds, int*& VertexIds, double*& Positions, double** Normals, int& Error ) const = 0;
   virtual int getInternals( JtkUnits Units, int StartFacetId, int MaxNumFacets, int& NumFacets, int*& FacetIds, int*& VertexIds, double*& Positions, double** Normals, int& Error ) const = 0;

protected:

   JtkXTMesh( );
   virtual ~JtkXTMesh( );
};

#endif // !JTK_XT_MESH_HXX
