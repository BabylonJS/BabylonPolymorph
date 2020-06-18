////////////////////////////////////////////////////////////////////////////////
// Copyright 2014 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_REFERENCESETS_HXX
#define JTK_REFERENCESETS_HXX

#include <JtTk/JtkHierarchy.h>


///////%{
//
// Class          : JtkReferenceSet
//
// Description    : The object for defining refence set groupings for filtering
//                  use by JT consumers
//
// Enums          : DataHint :
//                     JtkNOHINT -- no hint about what you want to view
//                     JtkPOINTSET -- the part has pointsets we want to include
//                     JtkWIREFRAME -- the part has wireframe we want to include
//                     JtkLIGHTWEIGHT -- the part has facet data we want to include 
//                                     the reference set at the exclusion of brep.
//
// Includes       : JtkReferenceSets.h
//
// Inheritance    : JtkEntity > JtkReferenceSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkReferenceSet : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkReferenceSet )

public:

   enum DataHint 
   {
      JtkNOHINT = -1,
      JtkPOINTSET= 0,
      JtkWIREFRAME = 1,
      JtkLIGHTWEIGHT = 2
   };

   virtual JtkAssembly* node( ) const = 0;
   virtual JtkString name( ) const = 0;

   virtual int setIsModelSet( int trueFalse ) = 0;
   virtual int isModelSet( ) const = 0;

   virtual int numMembers( ) const = 0;
   virtual JtkEntity* member( int index ) const = 0;
   virtual int member( int index, JtkPart*& part, DataHint& dataset ) const = 0;
   virtual int add( JtkEntity* ) = 0;
   virtual int add( JtkPart*, DataHint dataset ) = 0;
   virtual int remove( JtkEntity* ) = 0;
   virtual int remove( int index, int number = 1 ) = 0;
   virtual int find( JtkEntity* ) const = 0;

protected:
   virtual ~JtkReferenceSet();
   JtkReferenceSet();
};


///////%{
//
// Class          : JtkReferenceSetManager
//
// Description    : A static object for creating and managing
//                  JtkReferenceSet objects.
//
// Enums          :
//
// Includes       : JtkReferenceSets.h
//
// Inheritance    : JtkEntity > JtkReferenceSetManager
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkReferenceSetManager : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkReferenceSetManager )
public:
   virtual JtkReferenceSet* createReferenceSet( JtkAssembly* context, 
				                          const JtkString& name ) = 0;

   virtual int destroy( JtkReferenceSet* ) = 0;

   virtual int numReferenceSets( JtkAssembly* context = NULL ) = 0;
   virtual JtkReferenceSet* getReferenceSet( int index, JtkAssembly* context = NULL ) = 0;
   virtual int findReferenceSet( JtkReferenceSet*, int& index, JtkAssembly* context = NULL ) = 0;
   virtual int findReferenceSets( const JtkString& name, JtkEntityList*& locatedSets, JtkAssembly* context = NULL ) = 0;
   virtual int findModelSets( JtkEntityList*& modelSets, JtkAssembly* context = NULL ) = 0;

   virtual int findMember( JtkEntity* entity, JtkEntityList*& inSets ) const = 0;

protected:
    virtual ~JtkReferenceSetManager();
    JtkReferenceSetManager();
};

#endif //JTK_REFERENCESETS_HXX

