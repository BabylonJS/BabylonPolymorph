////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PROP_HXX
#define JTK_PROP_HXX

// This should really be made public in the VisMetaDataNode header
#define METADATA_PROP_FLAG 0x0001

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkProperty
//
// Description    : Toolkit class for defining date and time properties of a
//                  JtkEntity.
//
// Enums          : SubType
//                     JtkSTRING -- Designates a string property.
//                     JtkINT -- Designates an integer value property.
//                     JtkFLOAT -- Designates a floating point value property.
//                     JtkDATE -- Designates a date property.
//
//                  Visibility
//                     JtkPUBLIC_SHARED -- Designates a property that is
//                        visible among all instances of a JtkAssembly or 
//                        JtkPart.  This is the default for all properties.
//                     JtkHIDDEN_SHARED -- Designates a property that is
//                        associated with, but not visible from, all instances 
//                        of a JtkAssembly or JtkPart.
//                     JtkPUBLIC_INSTANCE -- Designates a property that is
//                        visible only from the JtkAssembly, JtkInstance, or
//                        JtkPart on which it is placed.
//                     JtkHIDDEN_INSTANCE -- Designates a property that is
//                        only associated with, but not visible from, the 
//                        JtkAssembly, JtkInstance, or JtkPart on which it is 
//                        placed.
//
// Includes       : JtkProperty.h
//
// Inheritance    : JtkRefCounted > JtkProperty
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkProperty : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkProperty )

public:
   enum SubType
   {
      JtkSTRING,
      JtkINT,
      JtkFLOAT,
      JtkDATE
   };

   // Bits: 00XX
   //         ||-shared/individual (0/1)
   //         |--public/hidden (0/1)
   enum Visibility
   {
      JtkPUBLIC_SHARED   = 0x00,
      JtkPUBLIC_INSTANCE = 0x01,
      JtkHIDDEN_SHARED   = 0x02,
      JtkHIDDEN_INSTANCE = 0x03
   };

   virtual int getInternal( JtkString& Key, JtkString& Value ) = 0;
   virtual int getInternal( JtkString& Key, int &Value ) = 0;
   virtual int getInternal( JtkString& Key, float &Value ) = 0;
   virtual int getInternal( JtkString& Key,
                            short &Year,
                            short &Month,
                            short &Day,
                            short &Hour,
                            short &Minutes,
                            short &Seconds ) = 0;
   virtual int getInternal( JtkString& Key,
                            short &Year,
                            short &Month,
                            short &Day,
                            short &Hour,
                            short &Minutes,
                            short &Seconds,
                            int   &isUTC ) = 0;

   virtual int getSubType(SubType &) = 0;
   virtual int getVisibility(Visibility &) = 0;
   virtual int setVisibility(Visibility) = 0;
   //virtual int isHidden() = 0;

   int operator==( const JtkProperty &OtherProperty )const;

protected:
   //Constructors
   JtkProperty();
   virtual~JtkProperty();
};
#endif //JTK_PROP_HXX

