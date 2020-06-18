////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_FACE_HXX
#define JTK_FACE_HXX

#include <JtTk/JtkTopology.h>

// forward references
class JtkSurface;
class JtkLoop;
class JtkMaterial;
class JtkTexImage;
class JtkLight;
class JtkTriStripSet;
class JtkTessParams;

///////%{
//
// Class          : JtkFace
//
// Description    : An object defining a face within a JtkBrep topology.
//
// Enums          :
//
// Includes       : JtkFace.h
//
// Inheritance    : JtkTopology > JtkFace
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkFace : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkFace )

public:
   // Brep hierarchy management methods
   virtual int          addChild( JtkLoop* ) = 0;
   virtual int          getChild( JtkLoop* &, int ) = 0;
   virtual int          deleteChild( int ) = 0;
   virtual int          numChildren() = 0;

   // Face attribute methods
   virtual int          setMaterial( JtkMaterial* ) = 0;
   virtual int          getMaterial( JtkMaterial* & ) = 0;
   virtual int          setTexImage( JtkTexImage* ) = 0;
   virtual int          getTexImage( JtkTexImage* & ) = 0;
   virtual int          setLight( JtkLight* ) = 0;
   virtual int          getLight( JtkLight* & ) = 0;
   virtual int          setReverseNormals( int ) = 0;
   virtual int          getReverseNormals( int & ) = 0;
   virtual int          getId( int &) = 0;
   virtual int          reverseNormals() = 0; // to be deprecated in near future

   // Trimmed surface accessor methods.
   virtual int          setSurface( JtkSurface* ) = 0;
   virtual int          getSurface( JtkSurface* & ) = 0;
   virtual JtkSurface*  surface( void ) const = 0;

   virtual int          tessellate( const JtkTessParams* TessParams,
                                    JtkTriStripSet* &TessResult ) = 0;

   int operator         ==( const JtkFace & )const;

protected:
   JtkFace();
   virtual  ~JtkFace();
};
#endif

