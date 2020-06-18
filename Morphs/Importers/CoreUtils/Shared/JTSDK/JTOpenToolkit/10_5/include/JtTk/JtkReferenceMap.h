////////////////////////////////////////////////////////////////////////////////
// Copyright 2009 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_REFERENCEMAP_H
#define JTK_REFERENCEMAP_H

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkHierarchy.h>

///////%{
//
// Class          : JtkReferenceMap
//
// Description    :
//
// Enums          :
//
// Includes       : JtkReferenceMap.h
//
// Inheritance    : JtkRefCounted
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkReferenceMap : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkReferenceMap )

public:
   // Methods to add/find
   virtual int findInRefMap( const JtkString& str, JtkHierarchy*& Context ) = 0;
   virtual int addToMap( const JtkString& itemStr, JtkHierarchy* Context ) = 0;

protected:
   // constructor
   JtkReferenceMap();

   // destructor
   virtual ~JtkReferenceMap();
};

/////////////////////////////////////////////////

#endif //! JTK_REFERENCEMAP_H

