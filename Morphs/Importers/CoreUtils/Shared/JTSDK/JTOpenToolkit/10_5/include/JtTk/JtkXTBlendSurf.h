////////////////////////////////////////////////////////////////////////////////
// Copyright 2009 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_BLENDSURF_HXX
#define JTK_XT_BLENDSURF_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTBlendSurf
//
// Description    : Represents a Parasolid XT Blend Surface. This geometry type
//                  is procedural and can be created only as a result of a
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
// Includes       : JtkXTBlendSurf.h
//
// Inheritance    : JtkXTSurface > JtkXTBlendSurf
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTBlendSurf : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTBlendSurf )

public:

   int            operator == ( const JtkXTBlendSurf &OtherSurface )const;

protected:
   JtkXTBlendSurf();
   virtual  ~JtkXTBlendSurf();
};

#endif

