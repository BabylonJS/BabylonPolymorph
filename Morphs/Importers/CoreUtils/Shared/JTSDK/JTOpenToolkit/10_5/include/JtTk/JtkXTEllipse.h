////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_ELLIPSE_HXX
#define JTK_XT_ELLIPSE_HXX

#include <JtTk/JtkXTCurve.h>

///////%{
//
// Class          : JtkXTEllipse
//
// Description    : An object defining an XT ellipse curve.
//
// Enums          :
//
// Includes       : JtkXTEllipse.h
//
// Inheritance    : JtkXTCurve > JtkXTEllipse
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTEllipse : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTEllipse )

public:
   virtual int    getInternals( double* &location, 
                                double* &reference, 
                                double* &axis, 
                                double  &radius1, 
                                double  &radius2, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units, 
                                double* &location, 
                                double* &reference, 
                                double* &axis, 
                                double  &radius1, 
                                double  &radius2, 
                                int     &error ) = 0;

   int            operator == ( const JtkXTEllipse &OtherCurve )const;

protected:
   JtkXTEllipse();
   virtual ~JtkXTEllipse();
};

#endif

