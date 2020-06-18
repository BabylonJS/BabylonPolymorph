////////////////////////////////////////////////////////////////////////////////
// Copyright 2018 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_XT_POLYLINE_HXX
#define JTK_XT_POLYLINE_HXX

#include <JtTk/JtkXTCurve.h>

///////%{
//
// Class          : JtkXTPolyline
//
// Description    : An object defining a line consisting of a connected
//                  chain of linear segments.
//
// Enums          :
//
// Includes       : JtkXTPolyline.h
//
// Inheritance    : JtkXTCurve > JtkXTPolyline
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTPolyline : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTPolyline )

   int         operator==( const JtkXTPolyline &OtherPolyline ) const;

   // public interface
   virtual int getInternals( int& NumSegments, double*& Segments,
                             int& Closed, double& BaseParameter, int& Error ) const = 0;
   virtual int getInternals( JtkUnits units, int& NumSegments, double*& Segments,
                             int& Closed, double& BaseParameter, int& Error ) const = 0;

protected:

   JtkXTPolyline( );
   virtual ~JtkXTPolyline( );
};

#endif // !JTK_XT_POLYLINE_HXX
