////////////////////////////////////////////////////////////////////////////////
// Copyright 2014 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_VERTEX_POOL_HXX
#define JTK_VERTEX_POOL_HXX
#include <JtTk/JtkHierarchy.h>

///////%{
//
// Class          : JtkVertexPool
//
// Description    : A JtkVertexPool object for managing vertex pools
//
// Enums          : Binding
//                   JtkNONE -- No bindings 
//                   JtkVERTEX -- Vertex bindings
//
//                  TextureChannelBindings
//                   JtkNO_CHANNEL_BINDINGS -- No texture bindings
//                   Jtk1D_CHANNEL_BINDINGS -- 1D texture bindings
//                   Jtk2D_CHANNEL_BINDINGS -- 2D texture bindings
//                   Jtk3D_CHANNEL_BINDINGS -- 3D texture bindings
//                   Jtk4D_CHANNEL_BINDINGS -- 4D texture bindings
//
// Includes       : JtkVertexPool.h
//
// Inheritance    : JtkRefCounted > JtkVertexPool
//
// Visibility     : public
//
// Theory         : A vertex pool contains a list of vertices, normals, colors and textures for all geometry sets. 
//
/////////%}

class JTK_TOOLKIT_API JtkVertexPool : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkVertexPool )

public:

   enum Binding
   {
      JtkNONE = 0,
      JtkVERTEX = 1
   };

   enum TextureChannelBindings
   {
      JtkNO_CHANNEL_BINDINGS = 0,
      Jtk1D_CHANNEL_BINDINGS = 1,
      Jtk2D_CHANNEL_BINDINGS = 2,
      Jtk3D_CHANNEL_BINDINGS = 3,
      Jtk4D_CHANNEL_BINDINGS = 4
    };

   virtual int addVertices( float* Verts, int VertCount, float* Norms, int NormCount, float* Colors, 
                                  int ColorCount, float* Textures[8], int TexCount[8], int &StartIndex, int &FinalIndex ) = 0;
   virtual int addVertices( JtkVertexPool* Pool, int &StartIndex, int &FinalIndex ) = 0;
   virtual int getInternals( float* &Verts, int &VertCount, float* &Norms, int &NormCount, float* &Colors, 
                                  int &ColorCount, float* Textures[8], int TexCount[8] ) = 0;
   virtual int getInternals( int* vertexPoolIndices, int IndexCount, float* &Verts, int &VertCount, float* &Norms, int &NormCount, float* &Colors, 
                                  int &ColorCount, float* Textures[8], int TexCount[8] ) = 0;
   virtual int getBindings( Binding &NBind, Binding &CBind, TextureChannelBindings TextureCoordinateDimensions[8] ) = 0;

   static JtkVertexPool* mergeShapeVertexPools( JtkEntityList* Shapes, JtkEntityList* &FaultsList );

protected:
   JtkVertexPool( );
   virtual ~JtkVertexPool(  );                                        // Hidden dtor
};
#endif // JTK_VERTEX_POOL_HXX

