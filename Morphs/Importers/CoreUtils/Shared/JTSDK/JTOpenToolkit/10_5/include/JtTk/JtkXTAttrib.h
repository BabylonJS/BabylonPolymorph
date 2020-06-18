////////////////////////////////////////////////////////////////////////////////
// Copyright 2015 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XTATTRIB_HXX
#define JTK_XTATTRIB_HXX

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkAttrib.h>

///////%{
//
// Class          : JtkXTAttrib
//
// Description    : An attribute object that abstracts the representation of 
//                  XT attribute information.
//
// Enums          :
//
// Includes       : JtkXTAttrib.h
//
// Inheritance    : JtkAttrib > JtkXTAttrib
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTAttrib : public JtkAttrib
{
   JTK_OBJECT_HEADER(JtkXTAttrib)
   int operator         ==( const JtkXTAttrib &OtherAttrib )const;

protected:
   //Constructors and Destructors
   JtkXTAttrib ();
   virtual  ~ JtkXTAttrib ();
};


///////%{
//
// Class          : JtkXTMaterial
//
// Description    : An attribute object that abstracts the representation of 
//                  XT material information that can be associated with an
//                  XT B-Rep face.
//
// Enums          :
//
// Includes       : JtkXTAttrib.h
//
// Inheritance    : JtkXTAttrib > JtkXTMaterial
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTMaterial : public JtkXTAttrib
{
   JTK_OBJECT_HEADER(JtkXTMaterial)

public:
   // Material primitives accessor methods.
   virtual int             setColor( float* fColor ) = 0;
   virtual int             getColor( float* &fColor ) = 0;
   int operator            ==( const JtkXTMaterial &OtherMaterial )const;

protected:
   //Constructors and Destructors
   JtkXTMaterial();
   virtual  ~JtkXTMaterial();
};

#endif //JTK_ATTRIB_HXX

