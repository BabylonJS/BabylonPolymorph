////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_LINE_HXX
#define JTK_XT_LINE_HXX

#include <JtTk/JtkXTCurve.h>

///////%{
//
// Class          : JtkXTLine
//
// Description    : An object defining an XT line curve.
//
// Enums          :
//
// Includes       : JtkXTLine.h
//
// Inheritance    : JtkXTCurve > JtkXTLine
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTLine : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTLine )

public:
   virtual int    getInternals( double* &location, 
                                double* &axis, 
                                int     &error ) = 0;

   virtual int    getInternals( JtkUnits units,
                                double* &location, 
                                double* &axis, 
                                int     &error ) = 0;

   int            operator == ( const JtkXTLine &OtherCurve )const;

protected:
   JtkXTLine();
   virtual ~JtkXTLine();
};

#endif

