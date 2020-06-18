////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_CIRCLE_HXX
#define JTK_XT_CIRCLE_HXX

#include <JtTk/JtkXTCurve.h>

///////%{
//
// Class          : JtkXTCircle
//
// Description    : An object defining an XT circle curve.
//
// Enums          :
//
// Includes       : JtkXTCircle.h
//
// Inheritance    : JtkXTCurve > JtkXTCircle
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTCircle : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTCircle )
public:
   virtual int    getInternals( double* &location, 
                                double* &reference, 
                                double* &axis, 
                                double  &radius, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                double* &location, 
                                double* &reference, 
                                double* &axis, 
                                double  &radius, 
                                int     &error ) = 0;

   int            operator == ( const JtkXTCircle &OtherCurve )const;

protected:
   JtkXTCircle();
   virtual ~JtkXTCircle();
};

#endif

