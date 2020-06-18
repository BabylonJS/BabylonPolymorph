////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_OFFSET_SURFACE_HXX
#define JTK_XT_OFFSET_SURFACE_HXX

#include <JtTk/JtkXTSurface.h>

///////%{
//
// Class          : JtkXTOffset
//
// Description    : An object defining an XT offset surface.
//
// Enums          :
//
// Includes       : JtkXTOffset.h
//
// Inheritance    : JtkXTSurface > JtkXTOffset
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTOffset : public JtkXTSurface
{
   JTK_OBJECT_HEADER( JtkXTOffset )

public:
   virtual int    getInternals( JtkXTSurface* &underlyingSurface,
                                double        &offsetDistance, 
                                int           &error ) = 0;

   virtual int    getInternals( JtkUnits      units,
                                JtkXTSurface* &underlyingSurface,
                                double        &offsetDistance,
                                int           &error ) = 0;

   int            operator == ( const JtkXTOffset &OtherSurface )const;

protected:
   JtkXTOffset();
   virtual  ~JtkXTOffset();
};

#endif

