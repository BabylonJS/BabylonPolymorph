////////////////////////////////////////////////////////////////////////////////
// Copyright 2011 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_GUID_H
#define JTK_GUID_H

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkString.h>

class _JtkGuidImpl;
class _JtkGuidManagerImpl;
class _JtkXTMonikerGuidImpl;

#ifndef JTK_GUID_ENTITY_ACCESS
#define JTK_GUID_ENTITY_ACCESS
#endif

///////%{
//
// Class          : JtkGuid
//
// Description    : The base class for a globally unique identifier (GUID)
//                  object in the toolkit. All objects of this class type or
//                  a derived type are created and managed by the
//                  JtkGuidManager.
//
// Enums          :
//
// Includes       : JtkGuid.h
//
// Inheritance    : JtkEntity > JtkGuid
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkGuid : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkGuid )
   JTK_GUID_ENTITY_ACCESS

public:
   int getUidString( JtkString& UidString ) ;

   _JtkGuidImpl* impl( );

protected:
   JtkGuid( );
   virtual ~JtkGuid( );

   _JtkGuidImpl* _impl;
};

///////%{
//
// Class          : JtkXTMonikerGuid
//
// Description    : The class for defining a GUID as required by the
//                  JtkXTFaceMoniker class. Note, objects of this class
//                  type are created and managed by the JtkGuidManager.
//
// Enums          :
//
// Includes       : JtkGuid.h
//
// Inheritance    : JtkGuid > JtkXTMonikerGuid
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTMonikerGuid : public JtkGuid
{
   JTK_OBJECT_HEADER( JtkXTMonikerGuid )
   JTK_GUID_ENTITY_ACCESS

public:
   int getAppName( JtkString& AppName );
   int setAppName( const JtkString& AppName );

protected:
   JtkXTMonikerGuid( );
   virtual ~JtkXTMonikerGuid( );
};

///////%{
//
// Class          : JtkGuidManager
//
// Description    : The static object for creating and managing
//                  JtkGuid-derived objects.
//
// Enums          :
//
// Includes       : JtkGuid.h
//
// Inheritance    : JtkEntity > JtkGuidManager
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkGuidManager : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkGuidManager )
   JTK_GUID_ENTITY_ACCESS

public:
   JtkGuid* createGuid( JtkEntity::TypeID GuidType, const JtkString& UidString );
   int numGuids( JtkEntity::TypeID GuidType = JtkEntity::JtkGUID );
   JtkGuid* guid( int Index,
                  JtkEntity::TypeID GuidType = JtkEntity::JtkGUID );
   int findGuid( const JtkString& UidString, JtkGuid*& Guid );

   _JtkGuidManagerImpl* impl( );

protected:
   JtkGuidManager( );
   virtual ~JtkGuidManager( );

   _JtkGuidManagerImpl* _impl;
};
#endif

