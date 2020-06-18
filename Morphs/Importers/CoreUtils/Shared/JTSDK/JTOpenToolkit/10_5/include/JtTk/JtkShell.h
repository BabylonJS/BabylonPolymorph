////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_SHELL_HXX
#define JTK_SHELL_HXX

#include <JtTk/JtkTopology.h>

// forward references
class JtkFace;

///////%{
//
// Class          : JtkShell
//
// Description    : An object defining a shell within a JtkBrep topology.
//
// Enums          :
//
// Includes       : JtkShell.h
//
// Inheritance    : JtkTopology > JtkShell
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkShell : public JtkTopology
{
   JTK_OBJECT_HEADER( JtkShell )

public:
   //  Add a new face to the shell representation.
   virtual int          addChild( JtkFace * ) = 0;
   virtual int          getChild( JtkFace * &f, int index ) = 0;
   virtual int          deleteChild( int index ) = 0;
   virtual int          numChildren() = 0;

   int operator         ==( const JtkShell &OtherShell )const;

protected:
   JtkShell();
   virtual  ~JtkShell();
};
#endif

