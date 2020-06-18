////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_ENTITY_STACK_
#define JTK_ENTITY_STACK_

#include <stdio.h>
#include <stdlib.h>

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkEntityStack
//
// Description    : A toolkit-specific stack object.  This object stores
//                  JtkEntity pointers, and it maintains responsibility for 
//                  memory management of the objects referenced by these 
//                  pointers.  A convenience method (combineEntities) may be 
//                  used to build toolkit object hierarchies.  This is useful 
//                  for recursive-descent-type parsing and processing of CAD 
//                  input data.
//
// Enums          : DBGLevel
//                     JtkNONE -- Print no debug or tracing messages.
//                     JtkSTACK_TRACE -- Print a trace message for each stack
//                        method called.
//                     JtkHIERARCHY_TRACE -- Print verbose tracing messages
//                        for the JtkEntity objects effected by the
//                        combineEnitities() method.  This is Useful for 
//                        debugging recursive-decent processing problems.
//                     JtkERRORS -- Print verbose error messages for the 
//                        JtkEntity objects effected by the combineEnitities() 
//                        method.  This is Useful for debugging 
//                        recursive-decent processing problems.
//
// Includes       : JtkEntityStack.h
//
// Inheritance    : JtkRefCounted > JtkEntityStack
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkEntityStack : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkEntityStack )

public:
   enum DBGLevel
   {
      JtkNONE,
      JtkSTACK_TRACE,
      JtkHIERARCHY_TRACE,
      JtkERRORS
   };
   virtual void setDebugLevel( JtkEntityStack::DBGLevel Debug ) = 0;
   virtual int combineEntities( void ) = 0;
   virtual int size( void ) = 0;
   virtual int push( JtkEntity* NewItem ) = 0;
   virtual JtkEntity* pop( void ) = 0;
   virtual JtkEntity* top( void ) = 0;
   virtual int isEmpty( void ) = 0;

protected:
   JtkEntityStack();
   virtual~JtkEntityStack();
};
#endif

