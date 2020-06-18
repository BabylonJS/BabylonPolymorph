////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SPCURVE_HXX
#define JTK_XT_SPCURVE_HXX

#include <JtTk/JtkXTCurve.h>

class JtkXTSurface;

///////%{
//
// Class          : JtkXTSPCurve
//
// Description    : An object defining an XT surface parameter curve.
//
// Enums          :
//
// Includes       : JtkXTSPCurve.h
//
// Inheritance    : JtkXTCurve > JtkXTSPCurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSPCurve : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTSPCurve )

public:
   virtual int    getInternals( JtkXTSurface* &surface, 
                                JtkXTCurve*   &curve, 
                                int           &error ) = 0;

   int            operator == ( const JtkXTSPCurve &OtherCurve )const;

protected:
   JtkXTSPCurve();
   virtual ~JtkXTSPCurve();
};

#endif

