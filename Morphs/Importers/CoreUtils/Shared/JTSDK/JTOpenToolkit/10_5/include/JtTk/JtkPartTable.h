////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#include <JtTk/JtkEntity.h>
#include <JtTk/JtkStandard.h>
#include <JtTk/JtkHierarchy.h>

#ifndef JTK_PART_TABLE
#define JTK_PART_TABLE

///////%{
//
// Class          : JtkPartTable
//
// Description    : An object maintaining a product structure reference list.
//
// Enums          :
//
// Includes       : JtkPartTable.h
//
// Inheritance    : JtkRefCounted > JtkPartTable
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPartTable : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkPartTable )

public:
  //if node does not already exist, adds its name to table,
  //else increments the number of instances
  virtual int  add(JtkHierarchy* node) =0;
  virtual int  add(const JtkString&, JtkEntity*) =0;

   //returns pointer to first instance of part added to table
   //returns NULL if name is not in table.
   virtual JtkHierarchy *exists( const JtkString& name ) = 0;

   //returns number of times key has been added to the table
   virtual int          numInstances( const JtkString& key ) = 0;

   //clear all entries from table
   virtual int          clear() = 0;

   //set option to use the JtPtrVec for node storage
   //rather than the JtPropHashTable
   //biv
   virtual void         useJtPtrVec() = 0;

protected:
   JtkPartTable();
   virtual  ~JtkPartTable();
};
#endif //JTK_PART_TABLE

