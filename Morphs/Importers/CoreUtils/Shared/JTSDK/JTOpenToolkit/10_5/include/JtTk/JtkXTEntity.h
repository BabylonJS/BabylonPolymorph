////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_ENTITY_HXX
#define JTK_XT_ENTITY_HXX

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkXTEntity
//
// Description    : Base XT object.
//
// Includes       : JtkXTEntity.h
//
// Inheritance    : JtkRefCounted > JtkXTEntity
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTEntity : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkXTEntity )

public:
   virtual void           setIndex( int index ) = 0;
   virtual int            getIndex( ) = 0;
   virtual int            alreadySaved( ) = 0;

   int          operator == ( const JtkXTEntity &OtherEntity )const;

protected:
   JtkXTEntity();
   virtual ~JtkXTEntity();
};

#endif
