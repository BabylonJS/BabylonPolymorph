////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_TRISTRIP_HXX
#define JTK_TRISTRIP_HXX

#include <JtTk/JtkShape.h>
#include <JtTk/JtkAttrib.h>

///////%{
//
// Class          : JtkTriStripSet
//
// Description    : A tri-strip set object.  Each triangle is defined by the
//                  window of 3 consecutive values spanned while moving
//                  left-to-right in the vertices list.
//
// Enums          :
//
// Includes       : JtkTriStripSet.h
//
// Inheritance    : JtkShape > JtkTriStripSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTriStripSet : public JtkShape
{
   JTK_OBJECT_HEADER( JtkTriStripSet )

public:

   // Must include 'use' of base class overloads for consistent access
   using JtkShape::addPrim;
   using JtkShape::getInternal;
   using JtkShape::getBindings;

   virtual void simplify( JtkTriStripSet* &outTSS,
                          float           epsilon = 1e-6,
                          float           creaseAngle = 40.0,
                          float           lodselectionratio = 1.0 ) = 0;

   virtual int  createVertexNormals() = 0;

   virtual int getBindings( JtkShape::Binding &VtxFlagBind,
                            JtkShape::Binding &Nbind,
                            JtkShape::Binding &Cbind,
                            JtkShape::Binding &Tbind ) = 0;

   virtual int getBindings( JtkShape::Binding &VtxFlagBind,
                            JtkShape::Binding &Nbind,
                            JtkShape::Binding &Cbind,
                            JtkShape::TextureChannelBindings TextureCoordinateDimensions[8] ) = 0;

   virtual int addPrim( float*       Coord3Vecs,
                        int          NumCoords,
                        int*         VertFlags,
                        int          NumVertexFlags,
                        float*       Normal3Vecs,
                        int          NumNorms,
                        float*       Color3Vecs,
                        int          NumColors,
                        float*       Texture2Vecs = NULL,
                        int          NumTextures = 0,
                        unsigned int TessGrpId = 0) = 0;

   virtual int addPrim( float*       Coord3Vecs,
                        int          NumCoords,
                        int*         VertFlags,
                        int          NumVertexFlags,
                        float*       Normal3Vecs,
                        int          NumNorms,
                        float*       Color3Vecs,
                        int          NumColors,
                        float*       TextureVecs[8],
                        int          NumTextures[8],
                        unsigned int TessGrpId = 0) = 0;

   virtual int getTessGrpId( int iPrim, int &TessGrpId ) = 0;

   virtual int getInternal( float* &Coord3Vecs,
                            int    &NumCoords,
                            int*   &VertFlags,
                            int    &NumVertexFlags,
                            float* &Normal3Vecs,
                            int    &NumNorms,
                            float* &Color3Vecs,
                            int    &NumColors,
                            float* &Texture2Vecs,
                            int    &NumTextures,
                            int    SetNum ) = 0;

    virtual int getInternal( float* &Coord3Vecs,
                             int    &NumCoords,
                             int*   &VertFlags,
                             int    &NumVertexFlags,
                             float* &Normal3Vecs,
                             int    &NumNorms,
                             float* &Color3Vecs,
                             int    &NumColors,
                             float* TextureVecs[8],
                             int    NumTextures[8],
                             int    SetNum ) = 0;

protected:
   JtkTriStripSet();
   virtual  ~JtkTriStripSet();
};
#endif

