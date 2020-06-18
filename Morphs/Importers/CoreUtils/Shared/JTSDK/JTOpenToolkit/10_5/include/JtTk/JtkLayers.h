////////////////////////////////////////////////////////////////////////////////
// Copyright 2010 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_LAYERS_HXX
#define JTK_LAYERS_HXX

#include <JtTk/JtkHierarchy.h>

//forward declarations
class JtkPMIModelView;

///////%{
//
// Class          : JtkLayer
//
// Description    : The object for designating a group of product structure
//                  and PMI entities as a "layer".
//
// Enums          :
//
// Includes       : JtkLayers.h
//
// Inheritance    : JtkEntity > JtkLayer
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLayer : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkLayer )
public:
   virtual int getId( int& nId ) = 0;
   virtual int numMembers( ) = 0;
   virtual JtkEntity* member( int nIndex ) = 0;
   virtual int add(JtkEntity*) = 0;
   virtual int remove( JtkEntity* ) = 0;
   virtual int remove( int nIndex, int nNumEntities = 1 ) = 0;
   virtual int find( JtkEntity* pEntity,
                     int        &index,
                     int        startAt = 0 ) = 0;

protected:
   virtual ~JtkLayer();
   JtkLayer();
 };

///////%{
//
// Class          : JtkLayerFilter
//
// Description    : The object for defining groups of layers for filtering
//                  use by JT consumers.
//
// Enums          :
//
// Includes       : JtkLayers.h
//
// Inheritance    : JtkEntity > JtkLayerFilter
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLayerFilter : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkLayerFilter )
public:
   virtual JtkHierarchy* node()  = 0;
   virtual JtkString name() = 0;
   virtual int isDefault() = 0;

   virtual int numLayers( ) = 0;
   virtual JtkLayer* layer( int nIndex ) = 0;
   virtual int add( JtkLayer* pLayer ) = 0;
   virtual int setDefault( int nDefault ) = 0;
   virtual int remove( JtkLayer* pLayer ) = 0;
   virtual int remove( int nIndex, int nNumLayers = 1 ) = 0;
   virtual int find( JtkLayer*       pLayer,
                     int             &index,
                     int             startAt = 0 ) = 0;
   virtual int find( int layerId, JtkLayer*& pLayer ) = 0;

protected:
   virtual ~JtkLayerFilter();
   JtkLayerFilter();
};

///////%{
//
// Class          : JtkLayerManager
//
// Description    : A static object for creating and managing
//                  JtkLayerBase-derived objects.
//
// Enums          :
//
// Includes       : JtkLayers.h
//
// Inheritance    : JtkEntity > JtkLayerManager
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLayerManager : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkLayerManager )
public:
   // APIs for manipulation of JtkLayerFilters
   virtual JtkLayerFilter* createLayerFilter( JtkHierarchy* pNode,
                                              const JtkString&         sName ) = 0;
   virtual int destroy( JtkLayerFilter* ) = 0;

   virtual int numLayerFilters( ) = 0;
   virtual JtkLayerFilter* layerFilter( int nIndex ) = 0;
   virtual int findLayerFilter( JtkLayerFilter* pFilter,
                                int&            nIndex,
                                int             startAt = 0 ) = 0;
   virtual int findLayerFilters( const JtkString& sName, JtkEntityList*& pLayerFilters ) = 0;
   virtual int resolveDefaultLayerFilter( JtkEntityList* pOccurrencePath, 
                                          JtkLayerFilter*& pDefaultLayerFilter ) = 0;
   virtual int resolveLayerFilters( JtkEntityList* pOccurrencePath, 
                                    JtkEntityList*& pLayerFilters ) = 0;
   virtual int matchLayerFilters( const JtkString& sLayerFilters, 
                                  JtkEntityList* pOccurrencePath,
                                  int& matched ) = 0;

   // APIs for manipulation of JtkLayers
   virtual JtkLayer* createLayer( int nId ) = 0;
   virtual int destroy( JtkLayer* ) = 0;

   virtual int numLayers( ) = 0;
   virtual JtkLayer* layer( int nIndex ) = 0;
   virtual int findLayer( JtkLayer* pLayer,
                          int&      nIndex,
                          int       startAt = 0 ) = 0;
   virtual int findLayer( int layerId, JtkLayer*& pLayer ) = 0;
   virtual int resolveLayers( JtkEntityList* pOccurrencePath, JtkEntityList*& pLayers ) = 0;

   // APIs for enabling a Model View to activate a Layer
   virtual int addLayers( JtkPMIModelView*, JtkEntityList* ) = 0;
   virtual int getLayers( JtkPMIModelView*, JtkEntityList*& ) const = 0;
   virtual int removeLayers( JtkPMIModelView* ) = 0;

protected:
    virtual ~JtkLayerManager();
    JtkLayerManager();
};
#endif //JTK_LAYERS_HXX
