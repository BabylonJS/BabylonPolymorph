////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_ICurve_HXX
#define JTK_XT_ICurve_HXX

#include <JtTk/JtkXTCurve.h>

///////%{
//
// Class          : JtkXTICurve
//
// Description    : Represents a Parasolid XT Intersection Curve. This geometry
//                  type is procedural and can be created only as a result of a
//                  Parasolid modeling operation. You cannot create it directly
//                  through the JT Open Toolkit API but it may get created as a
//                  result of an internal operation or you may encounter it in
//                  existing data. It is supported by this API only to the
//                  extent that it can be passed on to some other API functions.
//                  For example, you can pass it into the appropriate
//                  getNURBSRepresentation method to obtain a NURBS
//                  approximation of it.
//
// Enums          :
//
// Includes       : JtkXTICurve.h
//
// Inheritance    : JtkXTCurve > JtkXTICurve
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTICurve : public JtkXTCurve
{
   JTK_OBJECT_HEADER( JtkXTICurve )

public:
   int            operator == ( const JtkXTICurve &OtherCurve )const;

protected:
   JtkXTICurve();
   virtual ~JtkXTICurve();
};

#endif

