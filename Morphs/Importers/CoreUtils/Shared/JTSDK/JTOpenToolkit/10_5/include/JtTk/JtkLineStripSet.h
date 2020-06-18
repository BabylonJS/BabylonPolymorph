////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_LINESTRIP_HXX
#define JTK_LINESTRIP_HXX

#include <JtTk/JtkShape.h>
#include <JtTk/JtkAttrib.h>

///////%{
//
// Class          : JtkLineStripSet
//
// Description    : A line strip set object.  Each line strip is defined by a
//                  series of consecutive (x,y,z) values for each vertex in
//                  the line.
//
// Enums          : lineType:
//                   JtkSOLID -- Solid line
//                   JtkDASHED -- Dashed line
//                   JtkDOTTED -- Dotted line
//                   JtkDASHED_DOTTED -- Dashed and dotted line
//                   JtkDASHED_DOTTED_DOTTED -- Dash followed by 2 dots
//                   JtkLONG_DASHED -- Long dashed line
//                   JtkCENTER_DASHED_DASHED -- Center line with 2 dashes
//                   JtkINVISIBLE -- Invisible line
//                   JtkCENTER_DASHED-- Center line with singular
//
// Includes       : JtkLineStripSet.h
//
// Inheritance    : JtkShape > JtkLineStripSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLineStripSet : public JtkShape
{
   JTK_OBJECT_HEADER( JtkLineStripSet )

public:

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

   virtual int setDrawStyle( lineType type = JtkSOLID,
                           float customWidth = 1.0f ) = 0;
   virtual void getDrawStyle( lineType &, float& ) = 0;

protected:
   JtkLineStripSet();
   virtual  ~JtkLineStripSet();
};
#endif

