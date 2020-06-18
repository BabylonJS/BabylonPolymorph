////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PROP_FILTER_HXX
#define JTK_PROP_FILTER_HXX

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkPropertyFilter
//
// Description    : Toolkit class for filtering out properties based on 
//                  their key before export.
//
// Enums          :
//
// Includes       : JtkPropertyFilter.h
//
// Inheritance    : JtkRefCounted > JtkPropertyFilter
//
// Visibility     : public
//
// Theory         : Class to allow filtering out properties (based on their
//                  key) before export.  Only one can exist at a given time,
//                  and filtering happens at the time of the ->addProp() call
//                  on an JtkHierarchy node.
//
/////////%}
class JTK_TOOLKIT_API JtkPropertyFilter : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkPropertyFilter )

public:
   virtual int                   addFilter( const JtkString& Key ) = 0;
   virtual int                   removeFilter( int Index ) = 0;
   virtual int                   findKey( const JtkString& Key ) = 0;
   virtual int                   isFiltered( const JtkString& Key ) = 0;
   virtual int                   setFilterDirection( int Exclude ) = 0;
   virtual int                   getFilterDirection( int &Exclude ) = 0;
   virtual int                   numFilters() = 0;
   virtual JtkString      filterKey( int Index ) = 0;

   int operator                  ==( const JtkPropertyFilter &OtherFilter )const;

protected:
   JtkPropertyFilter();
   virtual  ~JtkPropertyFilter();
};
#endif //JTK_PROP_HXX

