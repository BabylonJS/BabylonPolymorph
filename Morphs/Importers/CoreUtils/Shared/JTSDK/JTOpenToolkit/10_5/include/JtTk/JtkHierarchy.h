////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_HIERARCHY_HXX
#define JTK_HIERARCHY_HXX

#include <JtTk/JtkString.h>
#include <JtTk/JtkEntity.h>
#include <JtTk/JtkEntityList.h>

//forward declarations
class JtkProperty;
class JtkTransform;
class JtkMaterial;
class JtkTexImage;
class JtkLight;
class JtkAttrib;
class JtkShape;
class JtkPrim;
class JtkBrep;
class JtkWrep;
class JtkClientData;
class JtkPoint;
class JtkXTBody;
class JtkCae;
class JtkTriStripSet;
class JtkTessParams;
class JtkPMIReference;
class JtkReferenceMap;
class JtkPMIEntity;
class JtkTraverser;
class JtkPMIModelViewList;
class JtkFeature;

///////%{
//
// Class          : JtkHierarchy
//
// Description    : The base class for all product structure objects
//                  (JtkAssembly, JtkPart, and JtkInstance).
//
// Enums          : JtkRefIdType
//                    JtkREFID_UNKNOWN -- Unknown identifier
//                    JtkITEM_REFID_PDM -- PDM item identifier
//                    JtkITEM_REFID_CAD -- CAD item identifier
//                    JtkINST_REFID_PDM -- PDM instance identifier
//                    JtkINST_REFID_CAD -- CAD instance identifier
//                    JtkITEM_REFID_NAME -- Name item identifier, also known as CADID
//                    JtkINST_CLONE_PDM -- PDM Clone instance identifier
//                    JtkINST_CSID_SUBSET -- CSID Subset instance identifier
//                    JtkINST_CSID_MEMBER -- CSID Member instance identifier
//
// Includes       : JtkHierarchy.h
//
// Inheritance    : JtkRefCounted > JtkHierarchy
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHierarchy : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkHierarchy )

public:
   // Basic ID APIs
   virtual JtkString name() = 0;
   virtual int   setName( const JtkString& ) = 0;
   virtual int   version() = 0;
   virtual int   setId( int InstId ) = 0;
   virtual int   getId( int &InstId ) = 0;

   //alternate ID APIs
   enum JtkRefIdType
   {
      JtkREFID_UNKNOWN = 0,
      JtkITEM_REFID_PDM = 1,
      JtkITEM_REFID_CAD,
      JtkINST_REFID_PDM,
      JtkINST_REFID_CAD,
      JtkITEM_REFID_NAME,
      JtkINST_CLONE_PDM,
      JtkINST_CSID_SUBSET,
      JtkINST_CSID_MEMBER
   };

   virtual int   setReferenceId( JtkRefIdType       IdType,
                                 const JtkString&   Id ) = 0;
   virtual int   getReferenceId( JtkRefIdType       IdTypeValue,
                                 JtkString&         Id ) = 0;

   // graph-related APIs
   virtual JtkHierarchy* parent( ) = 0;

   // Custom data structure APIs
   virtual void           setClientData( JtkClientData* cd ) = 0;
   virtual JtkClientData* clientData() const = 0;

   // Add properties to this hierarchy node
   virtual int addProp( JtkProperty* prop ) = 0;
   virtual int getProp( const JtkString&  Key,
                        JtkProperty* &p1 ) = 0;
   virtual int getProp( int          Index,
                        JtkString&        Key,
                        JtkProperty* &p1 ) = 0;
   virtual int numProps( int &numOfProps ) = 0;
   virtual int numProps( JtkProperty::Visibility VisType,
                         int                     &NumProps ) = 0;
   virtual int deleteProp( const JtkString& Key ) = 0;
   virtual int deleteProp( int Index ) = 0;

   // APIs for processing attributes to hierarchy node
   virtual int addAttrib( JtkAttrib* attrib ) = 0;
   virtual int deleteAttrib( int index,
                             JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;
   virtual int deleteAttrib( JtkAttrib* attrib ) = 0;
   virtual int getAttrib( int index, JtkAttrib* & TheAttrib,
                          JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;
   virtual int numAttribs( JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;

   // *LEGACY* APIs for processing attributes
   virtual int setTransform( JtkTransform* TheXform ) = 0;
   virtual int getTransform( JtkTransform* &TheXform ) = 0;
   virtual int setMaterial( JtkMaterial* TheMaterial ) = 0;
   virtual int getMaterial( JtkMaterial* &TheMaterial ) = 0;
   virtual int setTexImage( JtkTexImage* TheTexture ) = 0;
   virtual int getTexImage( JtkTexImage* &TheTexture ) = 0;
   virtual int setLight( JtkLight* TheLight ) = 0;
   virtual int getLight( JtkLight* &TheLight ) = 0;

   // Add BBox information to the hierarchy node
   virtual int setBBox( JtkPoint* bboxMin,
                        JtkPoint* bboxMax ) = 0;
   virtual int getBBox( JtkPoint* &bboxMin,
                        JtkPoint* &bboxMax ) = 0;

   // Motion APIs
   virtual int addFrames( JtkTransform** sequence,
                          int            numFrames ) = 0;
   virtual int numFrames() = 0;
   virtual int getFrame( int index,
                         JtkTransform* &aFrame ) = 0;
   virtual int setNumFrames( int nf ) = 0;
   virtual int resetMotionList() = 0;

   // JT file structure ("shattering") APIs
   virtual int setJtFilename( const JtkString& JtFileName ) = 0;
   virtual int getJtFilename( JtkString& JtFileName ) = 0;
   virtual int getJtFilename( JtkString& JtFileName, int &Major, int &Minor ) = 0;
   virtual int getJtFileVersion( int &Major, int &Minor ) = 0;

protected:

   // constructor
   JtkHierarchy( );
   
   // destructor
   virtual ~JtkHierarchy( );
};

///////%{
//
// Class          : JtkUnitHierarchy
//
// Description    : The intermediate class implementing units and PMI for
//                  JtkAssembly and JtkPart.
//
// Enums          : JtkMassUnits
//                    JtkUNKNOWN -- unknown units of mass
//                    JtkMICROGRAMS -- micrograms are the unit of mass
//                    JtkMILLIGRAMS -- milligrams are the unit of mass
//                    JtkGRAMS -- grams are the unit of mass
//                    JtkKILOGRAMS -- kilograms are the unit of mass
//                    JtkOUNCES -- ounces are the unit of mass
//                    JtkPOUNDS -- pounds are the unit of mass
//
//                 : JtkForceUnits
//                    JtkFORCE_UNIT_UNKNOWN -- unknown units of force
//                    JtkFORCE_UNIT_MILLINEWTONS -- milliNewtons are the unit of force
//                    JtkFORCE_UNIT_NEWTONS -- newtons are the unit of force
//                    JtkFORCE_UNIT_POUNDS -- pounds are the unit of force
//
//				   : JtkDeterminationMethod
//					   JtkDETERMINATION_CAD -- property value was calculated by the CAD system
//					   JtkDETERMINATION_ASSERTED -- property value was user asserted in the CAD system
//
//                : JtkPMISortDirection
//                    JtkPMI_SORT_NONE -- no sort order specified.
//                    JtkPMI_SORT_ASCENDING -- arrange PMI in a ascending order.
//                    JtkPMI_SORT_DESCENDING -- arrange PMI in a descending order.
//
//                : JtkPMISortMethod
//                    JtkPMI_SORT_UNKNOWN -- no sort method specified.
//                    JtkPMI_SORT_ALPHABETIC -- arrange PMI by alphabetic method.
//                    JtkPMI_SORT_ALPHANUMERIC -- arrange PMI by alphanumeric method.
//
//                : JtkPMISortNum
//                    JtkPMI_SORT_FIRST -- first sort group.
//                    JtkPMI_SORT_SECOND -- second sort group.
//                    JtkPMI_SORT_THIRD -- third sort group.
//
//                : JtkPMISortGrouping
//                    JtkPMI_SORT_UNSET -- no sort grouping.
//                    JtkPMI_SORT_ASSEMBLY_STRUCTURE -- group PMI as per assembly structure.
//                    JtkPMI_SORT_PART_NAME -- group PMI as per part name.
//                    JtkPMI_SORT_PMI_TYPE -- group PMI as per PMI type.
//                    JtkPMI_SORT_CUSTOM -- group PMI as per customer specified grouping.
//
//                  JtkValidationCountType
//                      Annotation -- total number of annotation for the node.
//                      AttributeNote -- total number of attribute notes for the node.
//                      Balloon -- total number of balloon for the node.
//                      BundleDressingNote -- total number of bundle dressing notes for the node.
//                      CalloutDimension -- total number of callout dimension for the node.
//                      Centerline -- total number of centerline for the node.
//                      Chamfer -- total number of chamfer for the node.
//                      CircleCentre -- total number of circle centre for the node.
//                      CoordinateNote -- total number of coordinate note for the node.
//                      Crosshatch -- total number of crosshatch for the node.
//                      CuttingPlaneSymbol -- total number of cutting plane symbols for the node.
//                      DatumFeatureSymbol -- total number of datumm feature symbols for the node.
//                      DatumTarget -- total number of datum target for the node.
//                      Dimension -- total number of dimension for the node.
//                      eMarking -- total number of eMarking for the node.
//                      Fastener -- total number of fastener for the node.
//                      FeatureControlFrame -- total number of feature control frame for the node.
//                      FitDesignation -- total number of fit designation for the node.
//                      LineWeld -- total number of line weld for the node.
//                      Locator -- total number of locator for the node.
//                      MaterialSpecification -- total number of material specification for the node.
//                      MeasurementPoint -- total number of measurement point for the node.
//                      ModelView -- total number of model views for the node
//                      Note -- total number of note for the node.
//                      Organisation -- total number of organisationfor the node.
//                      PartSpecification -- total number of part specification for the node.
//                      ProcessSpecification -- total number of process specification for the node.
//                      Region -- total number of region for the node.
//                      SpotWeld -- total number of spotweld for the node.
//                      SurfaceFinish -- total number of surface finish for the node.
//                      UserDefinedSymbol -- total number of user defined symbol for the node.
//                      Table -- total number of table pmi for the node.
//
// Includes       : JtkHierarchy.h
//
// Inheritance    : JtkHierarchy > JtkUnitHierarchy
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkUnitHierarchy : public JtkHierarchy
{
   JTK_OBJECT_HEADER( JtkUnitHierarchy )

public:
   // Measurement units APIs
   virtual int setUnits( JtkUnits units ) = 0;
   virtual int getUnits( JtkUnits &units ) = 0;

   // CAD Property API's
   enum JtkMassUnits
   {
      JtkUNKNOWN = 0,
      JtkMICROGRAMS,
      JtkMILLIGRAMS,
      JtkGRAMS,
      JtkKILOGRAMS,
      JtkOUNCES,
      JtkPOUNDS
   };

   enum JtkDeterminationMethod
   {
	   JtkDETERMINATION_CAD = 0,
	   JtkDETERMINATION_ASSERTED
   };

   enum JtkForceUnits
   {
      JtkFORCE_UNIT_UNKNOWN = 0,
      JtkFORCE_UNIT_MILLINEWTONS,
      JtkFORCE_UNIT_NEWTONS,
      JtkFORCE_UNIT_POUNDS
   };

   // PMI Sort Direction and Method Enums
   enum JtkPMISortDirection
   {
      JtkPMI_SORT_NONE,
      JtkPMI_SORT_ASCENDING,
      JtkPMI_SORT_DESCENDING 
   };

   enum JtkPMISortMethod
   {
      JtkPMI_SORT_UNKNOWN,
      JtkPMI_SORT_ALPHABETIC,
      JtkPMI_SORT_ALPHANUMERIC 
   };

   // PMI Sort Grouping number and type 
   enum JtkPMISortNum 
   {
      JtkPMI_SORT_FIRST, 
      JtkPMI_SORT_SECOND, 
      JtkPMI_SORT_THIRD
   };

   enum JtkPMISortGrouping
   {
      JtkPMI_SORT_UNSET,
      JtkPMI_SORT_ASSEMBLY_STRUCTURE,
      JtkPMI_SORT_PART_NAME,
      JtkPMI_SORT_PMI_TYPE,
      JtkPMI_SORT_CUSTOM
   };

   virtual int setMassUnits( JtkMassUnits massUnit ) = 0;
   virtual int getMassUnits( JtkMassUnits& massUnit ) = 0;

   virtual int setForceUnits( JtkForceUnits forceUnit ) = 0;
   virtual int getForceUnits( JtkForceUnits& forceUnit ) = 0;

   virtual int setSurfaceArea( double area, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;
   virtual int getSurfaceArea( double& area, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;

   virtual int setVolume( double volume, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;
   virtual int getVolume( double& volume, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;

   virtual int setDensity( double density, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;
   virtual int getDensity( double& density, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;

   virtual int setMass( double mass, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;
   virtual int getMass( double& mass, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;

   virtual int setCenterOfGravity( double x, double y, double z, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;
   virtual int getCenterOfGravity( double& x, double& y, double& z, JtkDeterminationMethod method = JtkDETERMINATION_CAD) = 0;

   virtual int setMaterialThickness( double thickness ) = 0;
   virtual int getMaterialThickness( double& thickness ) = 0;

   virtual int setCADPartName( const JtkString& name ) = 0;
   virtual int getCADPartName( JtkString& name ) = 0;

   virtual int setCADSource( const JtkString& source ) = 0;
   virtual int getCADSource( JtkString& source ) = 0;

   virtual int setYoungsModulus( double YoungsModulus ) = 0;
   virtual int getYoungsModulus( double& YoungsModulus ) = 0;

   virtual int setMomentOfInertia( double XX, double YY, double ZZ, double XY, double XZ, double YZ ) = 0;
   virtual int getMomentOfInertia( double& XX, double& YY, double& ZZ, double& XY, double& XZ, double& YZ ) = 0;

   virtual int getTranslationDate( int wantUTC, short& year, short& month, short& day, short& hour, short& minutes, short& seconds, int& isUTC ) = 0;
   
   // Instance APIs
   virtual int numInstances() = 0;

   // PMI APIs
   // Functions to add, delete and provide access to PMI objects associated
   // with the product structure entity.
   virtual int numPMI( JtkEntity::TypeID classTypeId = JtkEntity::JtkPMIENTITY ) = 0;
   virtual int addPMI( JtkPMIEntity* ) = 0;
   virtual int getPMI( int index, JtkPMIEntity*&, JtkEntity::TypeID classTypeId = JtkEntity::JtkPMIENTITY  ) = 0;
   virtual int deletePMI( int index, JtkEntity::TypeID classTypeId = JtkEntity::JtkPMIENTITY  ) = 0;
   virtual int deletePMI( JtkPMIEntity* ) = 0;
   virtual int findPMI( int id, JtkEntity::TypeID classTypeId, JtkPMIEntity*& ) = 0;
   
   //Associations
   virtual int AddPMIAssociation( int                 Reason,
                                  const JtkPMIReference& SrcReference,
                                  const JtkPMIReference& DstReference ) = 0;

   virtual int numPMIAssociation( ) = 0;
   virtual int GetPMIAssociation( int          Index,
                                  int          &Reason,
                                  JtkPMIReference &SrcReference,
                                  JtkPMIReference &DstReference,
                                  JtkReferenceMap *ReferenceMap = NULL ) = 0;
   virtual int DeletePMIAssociation( int Index, int Number = 1 ) = 0;
   
   //Model View Lists
   virtual int numPMIModelViewLists() = 0;
   virtual int GetPMIModelViewList( int index, JtkPMIModelViewList* &pMVList ) = 0;

   //PMI Sorting related
   virtual int setPMISortMethod(JtkPMISortMethod sortMethod, JtkPMISortDirection = JtkPMI_SORT_ASCENDING ) = 0;
   virtual int getPMISortMethod(JtkPMISortMethod& sortmethod, JtkPMISortDirection&  sortDirection) = 0;
   virtual int setPMISortExcludes(int nTypes, int* types) = 0;
   virtual int getPMISortExcludes(int& nTypes, int*& types) = 0;
   virtual int addPMISortGrouping(JtkPMISortNum sortNum, JtkPMISortGrouping  grouping, const JtkString& custom = JtkString( ) ) = 0;
   virtual int getPMISortGrouping(JtkPMISortNum& sortNum, JtkPMISortGrouping&  grouping, JtkString& custom ) = 0; 

   //Default model view
   virtual int setDefaultModelView( const JtkPMIReference&  ) = 0;
   virtual int getDefaultModelView( JtkPMIReference&  ) const = 0;
   
   //User Attribute Data
   virtual int AddPMITextData( const JtkString& key,
                               const JtkString& value ) = 0;
   virtual int numPMITextData() = 0;
   virtual int GetPMITextData(int index, JtkString& Key, JtkString& Value) = 0;

   //CAE Data
   virtual int setCAE( JtkCae* cae ) = 0;
   virtual int getCAE( JtkCae* &cae ) = 0;
   virtual int hasCAE() = 0;

   // Component API
   virtual int setIsComponent( int isComponent ) = 0;
   virtual int isComponent( ) = 0;

   // Feature API
   virtual int numFeatures() const = 0;
   virtual int addFeature(JtkFeature*) = 0;
   virtual int getFeature(int Index, JtkFeature*&) const = 0;

   //PMI Validation APIs
   virtual int setValidationVersion( int ) = 0;
   virtual int getValidationVersion( int& ) const = 0;

   enum JtkValidationCountType
   {
      Annotation,
      AttributeNote,
      Balloon,
      BundleDressingNote,
      CalloutDimension,
      Centerline,
      Chamfer,
      CircleCentre,
      CoordinateNote,
      Crosshatch,
      CuttingPlaneSymbol,
      DatumFeatureSymbol,
      DatumTarget,
      Dimension,
      eMarking,
      Fastener,
      FeatureControlFrame,
      FitDesignation,
      LineWeld,
      Locator,      
      MaterialSpecification,
      MeasurementPoint,
      ModelView,
      Note,
      Organisation,
      PartSpecification,
      ProcessSpecification,
      Region,
      SpotWeld,
      SurfaceFinish,
      UserDefinedSymbol,
      Table
   };

   virtual int addValidationCount( JtkValidationCountType, int ) = 0;
   virtual int getValidationCount( JtkValidationCountType, int& ) const = 0;

protected:

   // constructor
   JtkUnitHierarchy( );
   
   // destructor
   virtual ~JtkUnitHierarchy( );
};

///////%{
//
// Class          : JtkAssembly
//
// Description    : The object for defining non-leaf nodes in a product
//                  structure hierarchy.  Any hierarchy object may be a child
//                  of this object.  Note: all hierarchies must be acyclical
//                  (i.e. an assembly object cannot be a descendent of itself).
//                  Cycle detection is NOT performed, and cyclic graphs will
//                  likely lead to undefined results.
//
// Enums          :
//
// Includes       : JtkHierarchy.h
//
// Inheritance    : JtkUnitHierarchy > JtkAssembly
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkAssembly : public JtkUnitHierarchy
{
   JTK_OBJECT_HEADER( JtkAssembly )

public:
   // graph-related APIs
   virtual int           addChild( JtkHierarchy* child ) = 0;
   virtual int           removeChild( int index ) = 0;
   virtual int           removeChild( JtkHierarchy* child ) = 0;
   virtual int           replaceChild( JtkHierarchy* oldChild,
                                       JtkHierarchy* newChild ) = 0;
   virtual int           numChildren() = 0;
   virtual JtkHierarchy* child( int index ) = 0;

   // deprecated
   virtual int loadAssembly( const JtkString& fileName ) = 0;

protected:
   JtkAssembly();
   virtual ~JtkAssembly();
};

///////%{
//
// Class          : JtkPart
//
// Description    : The object for defining leaf nodes in a product
//                  structure hierarchy.  These objects are the only ones that
//                  can hold geometry.
//
// Enums          :
//
// Includes       : JtkHierarchy.h
//
// Inheritance    : JtkUnitHierarchy > JtkPart
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPart : public JtkUnitHierarchy
{
   JTK_OBJECT_HEADER( JtkPart )

public:

   // Interface for JtkBrep on the part
   virtual int setBrep( JtkBrep* ) = 0;
   virtual int getBrep( JtkBrep* & ) = 0;
   virtual int convertBrep() = 0;
   virtual int tessellateJtkBrep( const JtkTessParams* TessParams, JtkEntityList* &TessResult ) = 0;

   // Interfaces for Parasolid/XT Toolkit bodies on the part
   virtual int numXtBodies( int & ) = 0;
   virtual int generateXTBodiesForEditing() = 0;

   // Interfaces for XT Toolkit bodies on the part
   virtual int setBody( JtkXTBody*, int & ) = 0;
   virtual int setBody( JtkXTBody*, JtkEntityList* &pFaultsList, int & ) = 0;

   virtual int addBody( JtkXTBody*, int & ) = 0;
   virtual int addBody( JtkXTBody*, JtkEntityList* &pFaultsList,  int & ) = 0;

   virtual int getBody( int, JtkXTBody* &, int & ) = 0;
   virtual int getBodies( JtkEntityList* & ) = 0;
   virtual int tessellateXTBodies( const JtkTessParams* TessParams, JtkEntityList* &TessResult ) = 0;
   virtual int tessellateXTBodies( const JtkTessParams* TessParams, JtkEntityList* &TessResult, JtkEntityList* &pFaultsList ) = 0;

   // Interfaces for Parasolid bodies on the part
   virtual int setBrep( PK_BODY_t ) = 0;
   virtual int addBrep( PK_BODY_t ) = 0;
   virtual int getBrep( int, PK_BODY_t & ) = 0;
   virtual int getBreps( PK_BODY_t* &, int & ) = 0;
   virtual int tessellateXTBrep( const JtkTessParams* TessParams, JtkEntityList* &TessResult ) = 0;
   virtual int tessellateXTBrep( const JtkTessParams* TessParams, JtkEntityList* &TessResult, JtkEntityList* &pFaultsList ) = 0;

   // Interfaces for JtkWrep on the part
   virtual int setWrep( JtkWrep* ) = 0;
   virtual int getWrep( JtkWrep* & ) = 0;

   // Part has one LOD from which JtkShapes hang.
   // Shapes should be added in order of decreasing complexity -
   // add highest LOD first
   virtual int addPolyShape( JtkShape* Shape,
                             int       LodIndex = 0 ) = 0;
   virtual int numPolyLODs() = 0;
   virtual int numPolyShapes( int LodIndex ) = 0;
   virtual int getPolyShape( JtkShape* &Shape,
                             int       LodIndex,
                             int       Index ) = 0;
   virtual int deletePolyShape( int LodIndex,
                                int Index ) = 0;

   // Interface for JtkPrim-derived classes
   virtual int addPrimShape( JtkPrim* Prim,
                             int      LodIndex = 0 ) = 0;
   virtual int numPrimLODs() = 0;
   virtual int numPrimShapes( int LodIndex ) = 0;
   virtual int getPrimShape( JtkPrim* &Prim,
                             int      LodIndex,
                             int      Index ) = 0;
   virtual int deletePrimShape( int LodIndex,
                                int Index ) = 0;

   virtual int autoNormalsON() = 0;
   virtual int autoNormalsOFF() = 0;

   // deprecated
   virtual int loadPart( const JtkString& fileName ) = 0;

   // ULP support
   virtual int generateULP( float Precision = 0.001f ) = 0;
   virtual int hasULP( ) const = 0;
   virtual int tessellateULP( const JtkTessParams*  TessParams,
                                    JtkEntityList* &TessResult ) = 0;

   // Saved tessellation parameters support
   virtual int getTessParams( int LodIndex, JtkTessParams* &TessParams ) = 0;
   virtual int numTessParams( int &NumParams ) = 0;

   // STT support
   virtual int hasSTT() const = 0;

protected:
   JtkPart();
   virtual ~JtkPart();
};

///////%{
//
// Class          : JtkInstance
//
// Description    : Reference object pointing to an either a JtkAssembly or
//                  JtkPart object.  Used to avoid physical duplication of
//                  replicated assembly objects.
//
// Enums          :
//
// Includes       :  JtkHierarchy.h
//
// Inheritance    : JtkHierarchy > JtkInstance
//
// Visibility     : public
//
// Theory         : NOTE:  The behavior of JtkInstance nodes is slightly
//                  different than that of the JtkAssembly/JtkPart objects.
//
//                  JtkProperties (added via the addProp() virtual method) are
//                  not maintained separately for each JtkInstance of a given
//                  JtkHierarchy node -- each JtkProperty applied via an
//                  JtkInstance is redirected to the original node and is
//                  maintained there (thereby, possibly overriding a
//                  pre-existing property possessing a matching key).
//                  Likewise, the _name_ assigned to the original is also the
//                  _name_ of all of the instances (i.e. it can viewed as a
//                  special type of property).
//
//                  Contrarily, pre-existing JtkAttribs (JtkMaterial and
//                  JtkTransform) on the original node are instanced in each
//                  of the JtkInstance nodes referring to the original node.
//                  These "default" attributes can be overridden for each
//                  individual JtkInstance by applying the new JtkAttrib via
//                  the JtkInstance virtual methods (setMaterial() and
//                  setTransform()).  Overriding these instanced attributes
//                  does not alter the existing attributes of the original
//                  node.
//
/////////%}
class JTK_TOOLKIT_API JtkInstance : public JtkHierarchy
{
   JTK_OBJECT_HEADER( JtkInstance )

public:
   // Retrieve a reference to the original node this object is instancing.
   virtual JtkHierarchy* original() = 0;

protected:
   JtkInstance();
   virtual ~JtkInstance();
};
#endif //JTK_HIERARCHY_HXX
