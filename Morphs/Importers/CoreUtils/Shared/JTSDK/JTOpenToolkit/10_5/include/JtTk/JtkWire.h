////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_WIRE_HXX
#define JTK_WIRE_HXX

#include <JtTk/JtkTopology.h>
#include <JtTk/JtkAttrib.h>

// forward references
class JtkXYZCurve;
class JtkCurve;

///////%{
//
// Class          : JtkWire
//
// Description    : The precise wireframe object.
//
//                  It has the following possible attributes:
//                      JtkMaterial
//                      JtkTexImage
//
//                  It also has the following 'multiCAD' properties:
//                      Name
//                      Visibility
//                      DrawStyle
//                      Layer
//                      RefGeom 
//                      other user defined JtkProperty based values
//                  For the 'multiCAD' properties to persist correctly to jt.
//                  The wire requires an Id to be supplied when it is created.
//
// Enums          : lineType:
//                   JtkSOLID -- Solid line
//                   JtkDASHED -- Dashed line
//                   JtkDOTTED -- Dotted line
//                   JtkDASHED_DOTTED -- Dashed and dotted line
//                   JtkDASHED_DOTTED_DOTTED -- Dashed line with 2 dots between dashed
//                   JtkLONG_DASHED -- Long dashed line
//                   JtkCENTER_DASHED_DASHED -- Center line with 2 dashes
//                   JtkINVISIBLE -- Invisible line
//                   JtkCENTER_DASHED -- Center line with single dash
//
//                  lineWidth:
//                   JtkNORMAL -- Normal line - width is 2.0
//                   JtkTHICK -- Thick line - width is 3.0
//                   JtkTHIN -- Thin line - width is 1.0
//                   JtkORIGINAL -- Same as normal - width is 2.0
//                   JtkCUSTOM -- Line width is a custom width supplied additionally in pixels.
//
// Includes       : JtkWire.h
//
// Inheritance    : JtkTopology > JtkWire
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkWire : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkWire )

public:
   // line style
   enum lineType
   {
      JtkSOLID,
      JtkDASHED,
      JtkDOTTED,
      JtkDASHED_DOTTED,
      JtkDASHED_DOTTED_DOTTED,
      JtkLONG_DASHED,
      JtkCENTER_DASHED_DASHED,
      JtkINVISIBLE,
      JtkCENTER_DASHED,
      JtkPHANTOM = JtkDASHED_DOTTED_DOTTED, //deprecated 
      JtkCENTERLINE = JtkCENTER_DASHED_DASHED //deprecated 
   };

   enum lineWidth
   {
      JtkNORMAL,
      JtkTHICK,
      JtkTHIN,
      JtkORIGINAL,
      JtkCUSTOM
   };

   // Model space curve accessor methods.
   virtual int setCurve( JtkXYZCurve* ) = 0;
   virtual int getCurve( JtkXYZCurve* & ) = 0;
   virtual int setCurve( JtkCurve* ) = 0;
   virtual int getCurve( JtkCurve* & ) = 0;
   virtual int getId( int & ) = 0;

   virtual int setMaterial( JtkMaterial* ) = 0;
   virtual int getMaterial( JtkMaterial* & ) = 0;

   virtual int setTexImage( JtkTexImage* TexImage ) = 0;
   virtual int getTexImage( JtkTexImage* &TexImage ) = 0;

   // Functions for multiCAD
   virtual int addProp( JtkProperty* ) = 0;
   virtual int numProps( int & ) = 0;
   virtual int numMultiCADProps() = 0;
   virtual int getProp( int, JtkString& , JtkProperty* & ) = 0;
   virtual int deleteProp( const JtkString& ) = 0;
   virtual int deleteProp( int ) = 0;
   virtual int setName( const JtkString& ) = 0;
   virtual int getName( JtkString&  ) const = 0;
   virtual int setVisibility( int visibility = 1 ) = 0;
   virtual int setReferenceGeom( int refGeom = 0 ) = 0;
   virtual void getVisibility( int & ) = 0;
   virtual void getReferenceGeom( int & ) = 0;
   virtual int setDrawStyle( lineType type = JtkSOLID,
                             lineWidth width = JtkNORMAL,
                             float customWidth = -1.0f ) = 0;
   virtual void getDrawStyle( lineType &, lineWidth & ) = 0;
   virtual void getDrawStyle( lineType &, lineWidth &, float&  ) = 0;
   virtual int setLayer( int ) = 0;
   virtual void getLayer( int & ) = 0;

   int operator      ==( const JtkWire & )const;

protected:
   JtkWire();
   virtual ~JtkWire();
};
#endif

