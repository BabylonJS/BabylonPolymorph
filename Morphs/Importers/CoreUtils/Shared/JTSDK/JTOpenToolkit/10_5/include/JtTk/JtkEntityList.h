////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_ENTITY_LIST_HXX
#define JTK_ENTITY_LIST_HXX

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkProperty.h>

class JtkEntity;

///////%{
//
// Class          : JtkEntityList
//
// Description    : A toolkit-specific list object with array access.  This
//                  object stores JtkEntity pointers, and it maintains
//                  responsibility for memory management of the objects
//                  referenced by these pointers.
//
// Enums          :
//
// Includes       : JtkEntityList.h
//
// Inheritance    : JtkRefCounted > JtkEntityList
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkEntityList : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkEntityList )

public:
   virtual int             length() const = 0;

   virtual void            print( ostream & ) const = 0;

   int operator            ==( const JtkEntityList &OtherList )const;
   JtkEntity * operator [] (int index);

   virtual int          append( JtkEntity *entity ) = 0;
   virtual int          append( const JtkEntityList &list ) = 0;
   virtual int          insert( int index, JtkEntity *entity ) = 0;
   virtual int          remove( int startAt, int num = 1 ) = 0;
   virtual int          replace( int index, JtkEntity *entity ) = 0;
   virtual int          clear() = 0;
   virtual int          find(    JtkEntity   *entity,
                                 int         &index,
                                 int         startAt = 0 ) const = 0;

   virtual JtkEntity    *searchByKey( const JtkString&        Key,
                                      JtkEntity::TypeID entityType = JtkEntity::JtkPROPERTY ) = 0;

   virtual int          getByIndex( int               index,
                                    JtkString&               Key,
                                    JtkProperty       * &Value,
                                    JtkEntity::TypeID entityType = JtkEntity::JtkPROPERTY ) = 0;

   virtual void         shrink() = 0;

protected:
   JtkEntityList();
   virtual  ~JtkEntityList();
};
#endif

