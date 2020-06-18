////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_POINT_HXX
#define JTK_POINT_HXX

#include <JtTk/JtkGeometry.h>

///////%{
//
// Class          : JtkPoint
//
// Description    : An object defining a 3 dimensional (xyz) coordinate.
//
// Enums          :
//
// Includes       : JtkPoint.h
//
// Inheritance    : JtkGeometry > JtkPoint
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPoint : public JtkGeometry
{
   JTK_OBJECT_HEADER( JtkPoint )

public:
   // get/set tag
   virtual int          getTag( int &Tag ) = 0;
   virtual int          setTag( int Tag ) = 0;
   virtual int          tag() = 0;

   // Set the values for the 3-d coordinate.  Returns Jtk_ERROR in cases of
   // illegal input.
   virtual int          set( const double* coords ) = 0;
   virtual int          get( double &x, double &y, double &z ) = 0;
   virtual int          get( double* xyz ) = 0;

   int operator         ==( const JtkPoint &OtherPoint )const;

protected:
   JtkPoint();
   virtual  ~JtkPoint();
};
#endif

