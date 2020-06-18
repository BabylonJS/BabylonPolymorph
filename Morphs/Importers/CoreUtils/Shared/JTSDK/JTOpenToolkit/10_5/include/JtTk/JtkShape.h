////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_SHAPE_HXX
#define JTK_SHAPE_HXX

#include <JtTk/JtkGeometry.h>
#include <JtTk/JtkAttrib.h>
#include <JtTk/JtkVertexPool.h>

///////%{
//
// Class          : JtkShape
//
// Description    : The base class for all facet-based geometry types.
//
// Enums          : Binding:
//                     JtkNONE -- No attribute mapping.
//                     JtkVERTEX -- The n-th attribute element is mapped to
//                        the n-th vertex of the shape.
//                     JtkFACET -- The n-th attribute element is mapped to the
//                        n-th facet of the shape. (Deprecated)
//                     JtkPRIM -- The n-th attribute element is mapped to the
//                        n-th primitive within the shape. (Deprecated)
//
//                : TextureChannelBindings:
//                     JtkNO_CHANNEL_BINDINGS -- No texture coordinates.
//                     Jtk1D_CHANNEL_BINDINGS -- 1 dimensional texture coordinates.
//                     Jtk2D_CHANNEL_BINDINGS -- 2 dimensional texture coordinates.
//                     Jtk3D_CHANNEL_BINDINGS -- 3 dimensional texture coordinates.
//                     Jtk4D_CHANNEL_BINDINGS -- 4 dimensional texture coordinates.
//
// Includes       : JtkShape.h
//
// Inheritance    : JtkGeometry > JtkShape
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkShape : public JtkGeometry
{
   JTK_OBJECT_HEADER( JtkShape )

public:
   // Shape attribute bindings.  These binding types specify how normal and
   // color attribute data is mapped to the vertex-based shape data.
   enum Binding
   {
      JtkNONE,
      JtkVERTEX,
      JtkFACET,
      JtkPRIM
   };

   enum TextureChannelBindings
   {
      JtkNO_CHANNEL_BINDINGS,
      Jtk1D_CHANNEL_BINDINGS,
      Jtk2D_CHANNEL_BINDINGS,
      Jtk3D_CHANNEL_BINDINGS,
      Jtk4D_CHANNEL_BINDINGS
    };

   virtual int getBindings( Binding &Nbind,
                            Binding &Cbind,
                            Binding &Tbind ) = 0;

   virtual int getBindings( Binding &Nbind,
                            Binding &Cbind,
                            TextureChannelBindings TextureCoordinateDimensions[8] ) = 0;

   virtual int addPrim( float*       coord3vecs,
                        int          numcoords,
                        float*       normal3vecs,
                        int          numnorms,
                        float*       color3vecs,
                        int          numcolors,
                        float*       texture2vecs = NULL,
                        int          numTextCoords = 0,
                        unsigned int TessGrpId = 0) = 0;

   virtual int addPrim( float*       coord3vecs,
                        int          numcoords,
                        float*       normal3vecs,
                        int          numnorms,
                        float*       color3vecs,
                        int          numcolors,
                        float*       textureCoords[8],
                        int          textureCoordsCount[8],
                        unsigned int TessGrpId = 0) = 0;
						
   virtual int addPrim( unsigned int indexCount, unsigned int* vertexPoolIndices, unsigned int TessGrpId = 0 ) = 0;

   virtual int addPrims( unsigned int nPrims,
                         unsigned int* primStartingIndices,
                         unsigned int* vertexPoolIndices,
                         unsigned int numIndices,
                         unsigned int TessGrpId = 0) = 0;

   virtual int getInternal( float* &vertex,
                            int    &vertexCount,
                            float* &normal,
                            int    &normCount,
                            float* &color,
                            int    &colorCount,
                            float* &texture,
                            int    &textCount,
                            int    setNum ) = 0;

    virtual int getVertexPool( JtkVertexPool* &Pool ) = 0;

    virtual int getInternal( float* &vertex,
                             int    &vertexCount,
                             float* &normal,
                             int    &normCount,
                             float* &color,
                             int    &colorCount,
                             float* textureCoords[8],
                             int    textureCoordsCount[8],
                             int    setNum ) = 0;

    virtual int getInternal( unsigned int iPrim,
                         unsigned int        &indexCount,
                         unsigned int*       &vertexPoolIndices) = 0;

    virtual int getInternals( unsigned int &nPrims,
                         unsigned int*       &primStartingIndices,
                         unsigned int*       &vertexPoolIndices,
                         unsigned int        &numIndices) = 0;

   virtual int numOfSets() = 0;

   // APIs for processing attributes to shape node
   virtual int addAttrib( JtkAttrib* attrib ) = 0;
   virtual int deleteAttrib( int index,
                             JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;
   virtual int deleteAttrib( JtkAttrib* attrib ) = 0;
   virtual int getAttrib( int index, JtkAttrib* & TheAttrib,
                          JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;
   virtual int numAttribs( JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;


   virtual int setMaterial( JtkMaterial* attribute ) = 0;
   virtual int getMaterial( JtkMaterial* &attribute ) = 0;
   virtual int setTexImage( JtkTexImage* TexImage ) = 0;
   virtual int getTexImage( JtkTexImage* &TexImage ) = 0;
   

   virtual int applyTransform( JtkTransform* transform ) = 0;

protected:
   JtkShape();
   virtual~JtkShape();
};
#endif

