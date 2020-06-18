////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PRIM_HXX
#define JTK_PRIM_HXX

#include <JtTk/JtkGeometry.h>
#include <JtTk/JtkAttrib.h>

///////%{
//
// Class          : JtkPrim
//
// Description    : The base class for all primitive-based geometry types.
//
// Enums          : Binding:
//                     JtkNONE -- No attribute mapping.
//                     JtkVERTEX -- The n-th attribute element is mapped to
//                        the n-th parameter of the primitive.
//
// Includes       : JtkPrim.h
//
// Inheritance    : JtkGeometry > JtkPrim
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPrim : public JtkGeometry
{
   JTK_OBJECT_HEADER( JtkPrim )

public:
   // Prim attribute bindings.  These binding types specify how color and
   // texture attribute data is mapped to the geometry prim's parameters.
   enum Binding
   {
      JtkNONE,
      JtkVERTEX
   };

   virtual int getBindings( Binding &Cbind,
                            Binding &Tbind ) = 0;

   virtual int addSet( float* Origins,
                       int    OriginCount,
                       float* Parameters,
                       int    ParameterCount,
                       float* Colors = NULL,
                       int    ColorCount = 0 ) = 0;

   virtual int getInternal( float* &Origins,
                            int    &OriginCount,
                            float* &Parameters,
                            int    &ParameterCount,
                            float* &Colors,
                            int    &ColorCount,
                            int    SetNum ) = 0;

   virtual int numOfSets() = 0;

   virtual int setMaterial( JtkMaterial* Material ) = 0;
   virtual int getMaterial( JtkMaterial* &Material ) = 0;

   virtual int tessellate( JtkTriStripSet* &TessResult ) = 0;

protected:
   JtkPrim();
   virtual~JtkPrim();
};
#endif

