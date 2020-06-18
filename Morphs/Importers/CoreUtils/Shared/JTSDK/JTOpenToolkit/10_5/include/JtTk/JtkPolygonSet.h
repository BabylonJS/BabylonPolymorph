////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_POLYGONSET_HXX
#define JTK_POLYGONSET_HXX

#include <JtTk/JtkShape.h>
#include <JtTk/JtkAttrib.h>

///////%{
//
// Class          : JtkPolygonSet
//
// Description    : A polygon set object. Each polygon in the set is defined
//                  by a series of consecutive (x,y,z) values for each vertex
//                  in the polygon. JtkPolygonSet objects are triangulated into
//                  JtkTriStripSet objects during export to JT files because
//                  graphics processing operations, such as shading,
//                  are much faster with triangles.
//
// Enums          :
//
// Includes       : JtkPolygonSet.h
//
// Inheritance    : JtkShape > JtkPolygonSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPolygonSet : public JtkShape
{
   JTK_OBJECT_HEADER( JtkPolygonSet )

public:
   virtual int addHole( int nPolygonNum, float* pVertices, int nNumVertices,
                        float* pNormalCoords, int nNumNormals,
                        float* pColorValues, int nNumColors,
                        float* pTextureValues, int nNumTextures ) = 0;

   virtual int getHoleInternal( int nPolygonNum, int nHoleNum,
                                float* &pVertices, int &nNumVertices,
                                float* &pNormalCoords, int &nNumNormals,
                                float* &pColorValues, int &nNumColors,
                                float* &Textures, int &TextureCount ) = 0;

   virtual int numHoles ( int nPolygonNum, int &nNumHoles ) = 0;

protected:
   JtkPolygonSet();
   virtual  ~JtkPolygonSet();
};
#endif

