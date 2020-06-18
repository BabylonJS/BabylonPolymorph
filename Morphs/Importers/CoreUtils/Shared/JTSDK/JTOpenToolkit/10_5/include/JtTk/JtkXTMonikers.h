////////////////////////////////////////////////////////////////////////////////
// Copyright 2011 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XTMONIKERS_H
#define JTK_XTMONIKERS_H

#include <JtTk/JtkXTEntity.h>

class JtkXTMonikerGuid;

///////%{
//
// Class          : JtkXTEntityMoniker
//
// Description    : The object for defining a Moniker for a XT Face.
//                  These are used for identifying and grouping XT faces
//                  authored in separate sessions.
//
// Enums          :
//
// Includes       : JtkXTMonikers.h
//
// Inheritance    : JtkXTEntity > JtkXTEntityMoniker
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTEntityMoniker : public JtkXTEntity
{
   JTK_OBJECT_HEADER( JtkXTEntityMoniker )

public:
   virtual int getInternals( int& EntityId,
                             JtkXTMonikerGuid*& Guid ) = 0;
protected:
   JtkXTEntityMoniker( );
   virtual ~JtkXTEntityMoniker( );
};

///////%{
//
// Class          : JtkXTBodyMoniker
//
// Description    : The object for defining Moniker infomation intended
//                  for a XT Body. These are used for identifying merged
//                  or split XT bodies.
//
// Enums          :
//
// Includes       : JtkXTMonikers.h
//
// Inheritance    : JtkXTEntity > JtkXTBodyMoniker
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTBodyMoniker : public JtkXTEntity
{
   JTK_OBJECT_HEADER( JtkXTBodyMoniker )

public:
   virtual int getInternals( int& BodyId, JtkString& AppName ) = 0;

protected:
   JtkXTBodyMoniker( );
   virtual ~JtkXTBodyMoniker();
};
#endif

