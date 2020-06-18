////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_POINT_HXX
#define JTK_XT_POINT_HXX

#include <JtTk/JtkXTGeometry.h>

///////%{
//
// Class          : JtkXTPoint
//
// Description    : An object defining an XT point.
//
// Enums          :
//
// Includes       : JtkXTPoint.h
//
// Inheritance    : JtkXTGeometry > JtkXTPoint
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTPoint : public JtkXTGeometry
{
   JTK_OBJECT_HEADER( JtkXTPoint )

public:
   virtual int    getInternals( double* &xyz, int &error ) = 0;
   virtual int    getInternals( JtkUnits units, double* &xyz, int &error ) = 0;

   int            operator == ( const JtkXTPoint &OtherPoint )const;

protected:
   JtkXTPoint();
   virtual  ~JtkXTPoint();
};

#endif

