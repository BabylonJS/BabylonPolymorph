////////////////////////////////////////////////////////////////////////////////
// Copyright 2012 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SHARING_MANAGER_HXX
#define JTK_XT_SHARING_MANAGER_HXX
#include <JtTk/JtkHierarchy.h>

///////%{
//
// Class          : JtkXTSharingGroup
//
// Description    : A collection class for defining groups of entities 
//                  within which XT B-rep geometry data should be shared
//
// Enums          :
//
// Includes       : JtkXTSharingGroup.h
//
// Inheritance    : JtkEntity > JtkXTSharingGroup
//
// Visibility     : public
//
// Theory         : A collection of JtkPart instances whose XT B-Rep should be considered for geometry sharing.
//
/////////%}
class JTK_TOOLKIT_API JtkXTSharingGroup : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkXTSharingGroup )
public:

   virtual int num( ) = 0; 
   virtual int get( int Index, JtkPart*& Part ) = 0; 
   virtual int get( JtkEntityList* &Parts ) = 0; 

   virtual int add( JtkPart* Part ) = 0; 
   virtual int add( JtkEntityList* Parts ) = 0; 

   virtual int remove( JtkPart* Part ) = 0; 
   virtual int remove( int StartAt, int Count = 1 ) = 0; 
   
   virtual int clear( ) = 0; 
   virtual int find( JtkPart* Part, int& Index, int StartAt = 0 ) = 0;


protected:

   JtkXTSharingGroup( );
   virtual ~JtkXTSharingGroup( );
};

///////%{
//
// Class          : JtkXTSharingManager
//
// Description    : A static object for managing groups of entities whose XT B-rep geometry should be shared.
//
// Enums          :
//
// Includes       : JtkXTSharingManager.h
//
// Inheritance    : JtkEntity > JtkXTSharingManager
//
// Visibility     : public
//
// Theory         : An XT share manager manages XT share groups for XT geometry sharing 
//
/////////%}
class JTK_TOOLKIT_API JtkXTSharingManager : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkXTSharingManager )
public:

   virtual JtkXTSharingGroup* createGroup( ) = 0;

   virtual int numGroups( ) = 0;

   virtual JtkXTSharingGroup* getGroup( int Index ) = 0;

   virtual int deleteGroup( int StartAt, int Count = 1 ) = 0;
   virtual int deleteGroup( JtkXTSharingGroup* Group ) = 0;

   virtual int findGroup( JtkPart* Entity, JtkXTSharingGroup*& Group ) = 0;

protected:
   JtkXTSharingManager( );
   virtual ~JtkXTSharingManager( );
};
#endif //JTK_XT_SHARING_MANAGER_HXX

