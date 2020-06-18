////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_STACK_
#define JTK_STACK_

#include <stdio.h>
#include <stdlib.h>

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkStack
//
// Description    : A generic stack object.  This object holds void pointers 
//                  to user-defined items.  The user is responsible for
//                  memory management of the items referenced by these
//                  pointers.
//
// Enums          :
//             
// Includes       : JtkStack.h
//
// Inheritance    : JtkRefCounted > JtkStack
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkStack : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkStack )

public:
   //virtual int combineEntities(void)=0;
   virtual int size( void ) = 0;
   virtual int push( void *NewItem ) = 0;
   virtual void *pop( void ) = 0;
   virtual void *top( void ) = 0;
   virtual int isEmpty( void ) = 0;

protected:
   JtkStack();
   virtual~JtkStack();
};
#endif

