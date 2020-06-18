////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_ENTITY_FACTORY_HXX
#define JTK_ENTITY_FACTORY_HXX

#include <JtTk/JtkString.h>
#include <JtTk/JtkPropertyFilter.h>
#include <JtTk/JtkParser.h>
#include <JtTk/JtkPrim.h>
#include <JtTk/JtkShape.h>
#include <JtTk/JtkTraverser.h>
#include <JtTk/JtkAnalyticCurve.h>
#include <JtTk/JtkVertexPool.h>
#include <JtTk/JtkFeature.h>

class JtkMaterial;
class JtkTransform;
class JtkPointLight;
class JtkInfiniteLight;
class JtkLight;
class JtkProperty;
class JtkBrep;
class JtkCoedge;
class JtkEdge;
class JtkFace;
class JtkLoop;
class JtkNURBSSurface;
class JtkRegion;
class JtkShell;
class JtkUVCurve;
class JtkXYZCurve;
class JtkShape;
class JtkTriStripSet;
class JtkPointSet;
class JtkPolygonSet;
class JtkLineStripSet;
class JtkPrim;
class JtkBoxSet;
class JtkCylinderSet;
class JtkPyramidSet;
class JtkSphereSet;
class JtkTriPrismSet;
class JtkPoint;
class JtkPartition;
class JtkAssembly;
class JtkPart;
class JtkInstance;
class JtkCADExporter;
class JtkCADImporter;
class JtkMotionExporter;
class JtkPartTable;
class JtkEntityTable;
class JtkEntityStack;
class JtkStack;
class JtkVertex;
class JtkWire;
class JtkWrep;
class JtkHarness;
class JtkWrepWire;
class JtkSegment;
class JtkBundle;
class JtkParser;
class JtkParserContext;
class JtkParserAction;
class JtkPropertyFilter;
class JtkTraverser;
class JtkConfig;
class JtkConfigData;
class JtkConfigBoolData;
class JtkConfigStringData;
class JtkConfigFPData;
class JtkConfigIntData;
class JtkConfigItem;
class JtkConfigGroup;
class JtkLineCurve;
class JtkCircleCurve;
class JtkEllipseCurve;
class JtkParabolaCurve;
class JtkHyperbolaCurve;
class JtkCae;
class JtkCaeLegend;
class JtkCaeColorbar;
class JtkTessParams;
class JtkTessAssociation;
class JtkTessGroup;
class JtkPMIGlyph;
class JtkPMIEntity;
class JtkReferenceMap;
class JtkLayerManager;
class JtkGuidManager;
class JtkCaeManager;
class JtkCrosshatchPattern;
class JtkReferenceSetManager;
class JtkMotionManager;
class JtkRefGeom;
class JtkRefPoint;
class JtkRefPlane;
class JtkRefAxis;
class JtkCoordSys;

///////%{
//
// Class          : JtkEntityFactory
//
// Description    : A static factory class used to create all toolkit objects.
//                  Client applications should use this class to create all
//                  JtkEntity-derived objects instead of C++'s new command.
//                  Object deletion should be accomplished via
//                  JtkEntity::unref() instead of C++'s delete command. Note,
//                  all objects have a ref count of zero when created.
//
// Enums          : parasolidOption:
//                   JtkPARASOLID_OFF -- do not turn on XT support (default)
//                   JtkPARASOLID_ON -- turn on support for XT
//
//                  environmentOption
//                   JtkENVIRONMENT_CURRENT -- Intialise the toolkit environment-controlled setting to the current version settings. (default)
//                   JtkENVIRONMENT_103 -- Initialize the toolkit environment-controlled setting to the v10.3 release settings.
//                   JtkENVIRONMENT_101 -- Initialize the toolkit environment-controlled setting to the v10.1 release settings.
//                   JtkENVIRONMENT_90 -- Initialize the toolkit environment-controlled setting to the v9.0 release settings.
//                   JtkENVIRONMENT_85 -- Initialize the toolkit environment-controlled setting to the v8.5 release settings.
//                   JtkENVIRONMENT_80 -- Initialize the toolkit environment-controlled setting to the v8.0 release settings.
//                   JtkENVIRONMENT_71 -- Initialize the toolkit environment-controlled setting to the v7.1 release settings.
//                   JtkENVIRONMENT_70 -- Initialize the toolkit environment-controlled setting to the v7.0 release settings.
//                   JtkENVIRONMENT_66 -- Initialize the toolkit environment-controlled setting to the v6.6 release settings.
//                   JtkENVIRONMENT_63 -- Initialize the toolkit environment-controlled setting to the v6.3 release settings.
//                   JtkENVIRONMENT_60 -- This option is deprecated.
//
//
// Includes       : JtkEntityFactory.h
//
// Inheritance    : JtkEntityFactory
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API   JtkEntityFactory
{

public:
   enum parasolidOption
   {
      JtkPARASOLID_OFF = 0,
      JtkPARASOLID_ON
   };

   enum environmentOption
   {
      JtkENVIRONMENT_CURRENT,
      JtkENVIRONMENT_103,
      JtkENVIRONMENT_101,
      JtkENVIRONMENT_90,
      JtkENVIRONMENT_85,
      JtkENVIRONMENT_80,
      JtkENVIRONMENT_71,
      JtkENVIRONMENT_70,
      JtkENVIRONMENT_66,
      JtkENVIRONMENT_63,
      JtkENVIRONMENT_60
   };

   // Required customer release licensing authentication
   static int registerCustomer( unsigned long );

   // Helper methods for deleting allocated arrays within JtTk.
   static int deleteMemory( void* memory );
   static int deleteMemory( JtkString* memory );

   // Required JT Open Toolkit start/finish functions.
   // Note, client apps *must* call these at the beginning and end,
   // respectively, of their main loop.
   static void init(parasolidOption xtOption = JtkPARASOLID_OFF,
                    environmentOption envOption = JtkENVIRONMENT_CURRENT,
                    const char* journalFile = NULL );
   static void fini();
   static int  initCount();

   // journal functionality
   static void journalComment( const JtkString& comment );

   // Product structure object creation
   static JtkAssembly* createAssembly( const JtkString&,
                                       int version = 0,
                                       int hiId = -1 );
   static JtkPart*     createPart( const JtkString&,
                                   int version = 0,
                                   int hiId = -1 );
   static JtkInstance* createInstance( JtkUnitHierarchy*,
                                       int instId = -1 );

   // Attribute object creation
   static JtkMaterial*      createMaterial( JtkAttrib::JtkFieldInheritanceType inheritanceType
                                             = JtkAttrib::JtkFIELD_INHERITANCE_UNSET );
   static JtkTransform*     createTransform( float* xform );
   static JtkTransform*     createTransform( double* xform );
   static JtkTransform*     createTransform();
   static JtkTexImage*      createTexImage( JtkTexImage::JtkTexType type
                                              = JtkTexImage::JtkTEXTYPE_2D );
   static JtkImageStamp*    createImageStamp( const JtkString& sFileName,
                                              JtkImageStamp::JtkScreenPosition nPos
                                              = JtkImageStamp::JtkSCREENPOSITION_MID_CENTER,
                                              int nXDPI = 300, int nYDPI =300 );
   static JtkTexImageDescription* createTexImageDescription();
   static JtkTexImageDescription* createTexImageDescription( const JtkString& FromFile );

   static JtkPointLight*    createPointLight();
   static JtkInfiniteLight* createInfiniteLight();
   static JtkShaderParam*   createShaderParam( JtkShaderParam::JtkShaderParamType,
                                               JtkShaderParam::JtkShaderValueClass,
                                               JtkShaderParam::JtkShaderValue );
   static JtkShaderParam*   createShaderParam();
   static JtkShader*        createShader( JtkShader::JtkShaderType Type );
   static JtkShaderEffects* createShaderEffects( int Enable = 1 );

   // Property object creation
   static JtkProperty*       createProperty( const JtkString& keyString,
                                             const JtkString& value,
                                             int         lateLoad = 1,
                                             int         isVisible = 1 );
   static JtkProperty*       createProperty( const JtkString& keyString,
                                             int         value,
                                             int         lateLoad = 1,
                                             int         isVisible = 1 );
   static JtkProperty*       createProperty( const JtkString& keyString,
                                             float       value,
                                             int         lateLoad = 1,
                                             int         isVisible = 1 );
   static JtkProperty*       createProperty( const JtkString& keyString,
                                             short       yyyy,
                                             short       mm,
                                             short       dd,
                                             short       hh,
                                             short       mm2,
                                             short       ss,
                                             int         lateLoad = 1,
                                             int         isVisible = 1,
                                             int         isUTC = 0 );
   static JtkPropertyFilter* createPropertyFilter();

   // Topological object creation
   static JtkBrep*     createBrep( int cadIdTag = -1 );
   static JtkRegion*   createRegion( int cadIdTag = -1 );
   static JtkShell*    createShell( int cadIdTag = -1 );
   static JtkFace*     createFace( int cadIdTag = -1 );
   static JtkLoop*     createLoop( int cadIdTag = -1 );
   static JtkCoedge*   createCoedge( int cadIdTag = -1 );
   static JtkEdge*     createEdge( int cadIdTag = -1 );
   static JtkWire*     createWire( int cadIdTag = -1 );
   static JtkWrep*     createWrep( int cadIdTag = -1 );
   static JtkHarness*  createHarness( int cadIdTag = -1 );
   static JtkWrepWire* createWrepWire( int cadIdTag = -1 );
   static JtkSegment*  createSegment( int cadIdTag = -1 );
   static JtkBundle*   createBundle( int cadIdTag = -1 );
   static JtkVertex*   createVertex( int cadIdTag = -1 );

   // Geometric object creation
   static JtkNURBSSurface* createNURBSSurface( int uDegree,
                                               int vDegree,
                                               int uNumPoints,
                                               int vNumPoints );
   static JtkUVCurve*      createUVCurve( int degree, int numCtlPoints );
   static JtkXYZCurve*     createXYZCurve( int degree, int numCtlPoints );
   static JtkPoint*        createPoint();
   static JtkPoint*        createPoint( double x, double y, double z );

   // File importer/exporter object creation
   static JtkCADExporter*    createCADExporter();
   static JtkCADImporter*    createCADImporter();
   static JtkMotionExporter* createMotionExporter();

   // Utility objects creation
   static JtkPartTable*   createPartTable();
   static JtkEntityTable* createEntityTable();
   static JtkEntityStack* createEntityStack();
   static JtkStack*       createStack();
   static JtkEntityList*  createEntityList( int initSize = 0 );
   static JtkEntityList*  createEntityList( const JtkEntityList &list );
   static JtkTraverser*   createTraverser();
   static JtkTraverser*   createTraverser( const JtkString& sLayerFilters );
   static JtkTessParams*  createTessParams( float AngularTol = 0.0f,
                                            float ChordalTol = 0.0f,
                                            float LengthTol  = 0.0f,
                                            float MinAngle   = 0.0f,
                                            float MaxAspect  = 0.0f,
                                            float HoleRemovalFraction = 0.0f,
                                            float MinEdgeLength = 0.0f,
                                            int TrimSuppress = 0,
                                            const JtkString& LODName = JtkString( ) );

   // Shape object creation
   static JtkTriStripSet*  createTriStripSet();
   static JtkTriStripSet*  createTriStripSet( JtkVertexPool* pool);
   static JtkTriStripSet*  createTriStripSet( JtkShape::Binding normBinding,
                                              JtkShape::Binding colBinding,
                                              JtkShape::Binding texBinding
                                                 = JtkShape::JtkNONE );
   static JtkTriStripSet*  createTriStripSet( JtkShape::Binding vertexFlagBinding,
                                              JtkShape::Binding normBinding,
                                              JtkShape::Binding colBinding,
                                              JtkShape::Binding texBinding );
   static JtkTriStripSet*  createTriStripSet( JtkShape::Binding normBinding,
                                              JtkShape::Binding colBinding,
                                              JtkShape::TextureChannelBindings TextureCoordinateDimensions[8] );
   static JtkTriStripSet*  createTriStripSet( JtkShape::Binding vertexFlagBinding,
                                              JtkShape::Binding normBinding,
                                              JtkShape::Binding colBinding,
                                              JtkShape::TextureChannelBindings TextureCoordinateDimensions[8] );
   static JtkTriStripSet*  createTriStripSet( JtkPolygonSet* ThePolySet );

   static JtkPointSet*     createPointSet();
   static JtkPointSet*     createPointSet( JtkVertexPool* pool );
   static JtkPointSet*     createPointSet( JtkShape::Binding normBinding,
                                           JtkShape::Binding colBinding );

   static JtkPolygonSet*   createPolygonSet();

   static JtkPolygonSet*   createPolygonSet( JtkVertexPool* pool );
   static JtkPolygonSet*   createPolygonSet( JtkShape::Binding normBinding,
                                             JtkShape::Binding colBinding,
                                             JtkShape::Binding texBinding
                                                = JtkShape::JtkNONE );
   static JtkPolygonSet*   createPolygonSet( JtkShape::Binding normBinding,
                                             JtkShape::Binding colBinding,
                                             JtkShape::TextureChannelBindings TextureCoordinateDimensions[8] );

   static JtkLineStripSet* createLineStripSet();
   static JtkLineStripSet* createLineStripSet( JtkVertexPool* pool );
   static JtkLineStripSet* createLineStripSet( JtkShape::Binding normBinding,
                                               JtkShape::Binding colBinding,
                                               JtkShape::Binding texBinding
                                                = JtkShape::JtkNONE );
   static JtkLineStripSet* createLineStripSet( JtkShape::Binding normBinding,
                                               JtkShape::Binding colBinding,
                                               JtkShape::TextureChannelBindings TextureCoordinateDimensions[8] );

   static JtkVertexPool*   createVertexPool( JtkVertexPool::Binding normBinding,
                                             JtkVertexPool::Binding colBinding,
                                             JtkVertexPool::TextureChannelBindings TextureCoordinateDimensions[8] );

   static JtkBoxSet*       createBoxSet();
   static JtkBoxSet*       createBoxSet( JtkPrim::Binding  colBinding,
                                         JtkPrim::Binding  texBinding );

   static JtkCylinderSet*  createCylinderSet();
   static JtkCylinderSet*  createCylinderSet( JtkPrim::Binding  colBinding,
                                              JtkPrim::Binding  texBinding );

   static JtkPyramidSet*   createPyramidSet();
   static JtkPyramidSet*   createPyramidSet( JtkPrim::Binding  colBinding,
                                             JtkPrim::Binding  texBinding );

   static JtkSphereSet*    createSphereSet();
   static JtkSphereSet*    createSphereSet( JtkPrim::Binding  colBinding,
                                            JtkPrim::Binding  texBinding );

   static JtkTriPrismSet*  createTriPrismSet();
   static JtkTriPrismSet*  createTriPrismSet( JtkPrim::Binding  colBinding,
                                              JtkPrim::Binding  texBinding );

   // Parser object creation
   static JtkParser*        createParser();
   static JtkParserContext* createParserContext( const JtkString& BeginRegExpr,
                                                 const JtkString& EndRegExpr,
                                                 JtkParser::JtkParserCB*
                                                    BeginContextCB,
                                                 JtkParser::JtkParserCB*
                                                    EndContextCB );
   static JtkParserAction*  createParserAction( const JtkString& RegExprMatch,
                                                JtkParser::JtkParserCB*
                     ActionCB );

   //JtkAnalytic related objects
   static JtkLineCurve* createLineCurve( JtkPoint* stPt, JtkPoint* endPt );
   static JtkCircleCurve* createCircleCurve( JtkPoint* stPt, JtkPoint* endPt,
                                             JtkPoint* cntPt, double* normal);
   static JtkEllipseCurve* createEllipseCurve( JtkPoint* stPt, JtkPoint* endPt,
                                               JtkPoint* cntPt, double majRadius,
                                               double minRadius, double* normal,
                                               double* majAxis );
   static JtkParabolaCurve* createParabolaCurve();
   static JtkHyperbolaCurve* createHyperbolaCurve();

   //JtkConfig related objects
   static JtkConfigItem*     createStringConfigItem( const JtkString& TheToken,
                                                     const JtkString& TheInitialValue,
                                                     int   WriteByDefault = Jtk_OK );
   static JtkConfigItem*     createBoolConfigItem( const JtkString& TheToken,
                                                   int   TheInitialValue,
                                                   int   WriteByDefault = Jtk_OK );
   static JtkConfigItem*     createFPConfigItem( const JtkString&  TheToken,
                                                 double TheInitialValue,
                                                 int    WriteByDefault = Jtk_OK );
   static JtkConfigItem*     createIntConfigItem( const JtkString& TheToken,
                                                  int   TheInitialValue,
                                                  int   WriteByDefault = Jtk_OK );
   static JtkConfigItem*     createConfigItem( const JtkString& TheToken,
                                               int   WriteByDefault = Jtk_OK );
   static JtkConfigGroup*    createConfigGroup( const JtkString& TheBeginToken,
                                                const JtkString& TheEndToken,
                                                int   WriteByDefault = Jtk_OK );
   static JtkConfig*         createConfig();

   //JtkCae related objects
   static JtkCae*            createCAE();
   static JtkCaeLegend*      createCAELegend();
   static JtkCaeColorbar*    createCAEColorbar();

   //JtkTessAssociation and JtkTessGroup related objects
   static JtkTessAssociation*    createTessAssociation();

   //JtkTessGroup object
   static JtkTessGroup*    createTessGroup();

   //JtkPMIGlyph objects
   static JtkPMIGlyph* createGlyph( JtkEntity::TypeID type , int dimension = 2 );

  // Function to create all types of PMI.
   static JtkPMIEntity*  createPMI( JtkEntity::TypeID type, JtkUnitHierarchy* owner );

   // Function to create JtkModelViewList.
   static JtkPMIModelViewList*  createModelViewList( JtkUnitHierarchy* owner );

   // Function to create a JtkReferenceMap
   static JtkReferenceMap* createReferenceMap( );

   // Function to create a JtkFeature derived object
   static JtkFeature* createFeature( JtkEntity::TypeID Type );
   static JtkFeature* createFeature( JtkFeature::SubType Type);

   // Function to get the global JtkLayerManager object
   static JtkLayerManager* getLayerManager();

   // Function to get the global JtkGuidManager object
   static JtkGuidManager* getGuidManager();

   // Function to get the global JtkCaeManager object
   static JtkCaeManager* getCaeManager();

   // Function to get the global JtkReferenceSetManager object
   static JtkReferenceSetManager* getReferenceSetManager( );

   //Function to get the global JtkMotionManager object
   static JtkMotionManager* getMotionManager( );

   // Function to create a JtkCrosshatchPattern
   static JtkCrosshatchPattern*   createCrosshatchPattern( const JtkString& Name );

   // Function to get the global XT option flags
   static parasolidOption getXTOption();

private:
   static int                 _refCount;

   // Global JtkLayerManager object
   // Note: not for user access
   static JtkLayerManager* _globalLayerManager;

   // Global JtkGuidManager object
   // Note: not for user access
   static JtkGuidManager*  _globalGUIDManager;

   // Global JtkCaeManager object
   // Note: not for user access
   static JtkCaeManager*  _globalCaeManager;

   // Global JtkPropertyFilter object
   // Note: not for user access
   static JtkPropertyFilter* _globalPropertyFilter;

   // Global XT option flags
   // Note: not for user access
   static parasolidOption   _xtOption;

};

#endif

