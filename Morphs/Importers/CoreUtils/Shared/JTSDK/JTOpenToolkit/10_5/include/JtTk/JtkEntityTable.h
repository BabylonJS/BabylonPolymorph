////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_ENTITY_TABLE
#define JTK_ENTITY_TABLE
#include <JtTk/JtkEntity.h>
#include <JtTk/JtkStandard.h>

///////%{
//
// Class          : JtkEntityTable
//
// Description    : A toolkit-specific reference table object.  This object
//                  stores JtkEntity pointers, and it maintains responsibility
//                  for memory management of the objects referenced by these
//                  pointers.
//
// Enums          :
//
// Includes       : JtkEntityTable.h
//
// Inheritance    : JtkRefCounted > JtkEntityTable
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkEntityTable : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkEntityTable )

public:
   virtual int        add( int UID, JtkEntity* edge ) = 0;

   virtual JtkEntity* remove( int UID ) = 0;

   //returns pointer to instance of Entity added to table
   //returns NULL if UID is not in table.
   virtual JtkEntity* exists( int UID ) = 0;

   //clear all entries from table
   virtual int        clear() = 0;

protected:
   JtkEntityTable();
   virtual           ~JtkEntityTable();
};
#endif //JTK_ENTITY_TABLE

