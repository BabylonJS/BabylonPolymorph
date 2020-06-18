////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_GEOM_HXX
#define JTK_GEOM_HXX

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkGeometry
//
// Description    : The base class for all renderable geometry.
//
// Enums          :
//
// Includes       : JtkGeometry.h
//
// Inheritance    : JtkRefCounted > JtkGeometry
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkGeometry : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkGeometry )

public:
   void                   setIndex( int i );
   int                    index();
   int                    alreadySaved();
   int operator           ==( const JtkGeometry &OtherGeometry )const;

protected:
   JtkGeometry();
   virtual  ~JtkGeometry();
   int      _index;
   int      _alreadySaved;
};
#endif

