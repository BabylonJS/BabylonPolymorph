////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_ENTITY_HXX
#define JTK_ENTITY_HXX

#include <JtTk/JtkStandard.h>

// Helps define the typing mechanism for external objects
#define JTK_OBJECT_TYPE_HEADER( name ) \
public: \
   static JtkEntity::TypeID classTypeID( ); \
   virtual JtkEntity::TypeID typeID() const; \

// Helps define the typing mechanism for external objects
#define JTK_OBJECT_HEADER( name ) \
   JTK_OBJECT_TYPE_HEADER( name ) \
   name( const name & ); \
   name& operator=( const name& );

///////%{
//
// DEPRECATION    : These definitions support the legacy JtkEntity::TypeID values.
//                  They will be removed in a later release of the JtTk. It is
//                  recommended that these definitions not be relied upon and that
//                  the JtkEntity::TypeID enum values are used directly.
//
// Old API        :       JtkPMI_NONE
//                        JtkPMI_ENTITY
//                        JtkPMI_VISUAL_ENTITY
//                        JtkPMI_ANNOTATION
//                        JtkPMI_GLYPH
//                        JtkPMI_OUTLINE_GLYPH
//                        JtkPMI_POLYGON_GLYPH
//                        JtkPMI_DIMENSION
//                        JtkPMI_FASTENER
//                        JtkPMI_SURFACE_FINISH
//                        JtkPMI_FEATURE_CONTROL_FRAME
//                        JtkPMI_DATUM_FEATURE_SYMBOL
//                        JtkPMI_DATUM_TARGET
//                        JtkPMI_SPOT_WELD
//                        JtkPMI_LINE_WELD
//                        JtkPMI_MATERIAL_SPEC
//                        JtkPMI_PROCESS_SPEC
//                        JtkPMI_PART_SPEC
//                        JtkPMI_ORGANISATION
//                        JtkPMI_NOTE
//                        JtkPMI_BALLOON
//                        JtkPMI_MEASUREMENT_POINT
//                        JtkPMI_LOCATOR
//                        JtkPMI_USER_DEFINED_SYMBOL
//                        JtkPMI_CIRCLE_CENTRE
//                        JtkPMI_COORDINATE_NOTE
//                        JtkPMI_ATTRIBUTE_NOTE
//                        JtkPMI_BUNDLE_DRESSING_NOTE
//                        JtkPMI_CUTTING_PLANE_SYMBOL
//                        JtkPMI_CROSSHATCH
//                        JtkPMI_E_MARKING
//                        JtkPMI_MODEL_VIEW
//                        JtkPMI_DESIGN_GROUP
//                        JtkPMI_VIEW_SET
//                        JtkPMI_REF_GEOMETRY
//                        JtkPMI_REF_POINT
//                        JtkPMI_REF_AXIS
//                        JtkPMI_REF_PLANE
//                        JtkPMI_COORDINATE_SYSTEM
//                        JtkPMI_REGION
//                        JtkPMI_SECTION
//                        JtkPMI_SECTION_GROUP
//                        JtkPMI_CENTERLINE
//                        JtkPMI_FITDESIGNATION
//                        JtkPMI_COMPOSITEFCF
//
// New API        :       JtkPMINONE
//                        JtkPMIENTITY
//                        JtkPMIVISUALENTITY
//                        JtkPMIANNOTATION
//                        JtkPMIGLYPH
//                        JtkPMIOUTLINEGLYPH
//                        JtkPMIPOLYGONGLYPH
//                        JtkPMIDIMENSION
//                        JtkPMIFASTENER
//                        JtkPMISURFACEFINISH
//                        JtkPMIFEATURECONTROLFRAME
//                        JtkPMIDATUMFEATURESYMBOL
//                        JtkPMIDATUMTARGET
//                        JtkPMISPOTWELD
//                        JtkPMILINEWELD
//                        JtkPMIMATERIALSPEC
//                        JtkPMIPROCESSSPEC
//                        JtkPMIPARTSPEC
//                        JtkPMIORGANISATION
//                        JtkPMINOTE
//                        JtkPMIBALLOON
//                        JtkPMIMEASUREMENTPOINT
//                        JtkPMILOCATOR
//                        JtkPMIUSERDEFINEDSYMBOL
//                        JtkPMICIRCLECENTRE
//                        JtkPMICOORDINATENOTE
//                        JtkPMIATTRIBUTENOTE
//                        JtkPMIBUNDLEDRESSINGNOTE
//                        JtkPMICUTTINGPLANESYMBOL
//                        JtkPMICROSSHATCH
//                        JtkPMIEMARKING
//                        JtkPMIMODELVIEW
//                        JtkPMIDESIGNGROUP
//                        JtkPMIVIEWSET
//                        JtkPMIREFGEOMETRY
//                        JtkPMIREFPOINT
//                        JtkPMIREFAXIS
//                        JtkPMIREFPLANE
//                        JtkPMICOORDINATESYSTEM
//                        JtkPMIREGION
//                        JtkPMISECTION
//                        JtkPMISECTIONGROUP
//                        JtkPMICENTERLINE
//                        JtkPMIFITDESIGNATION
//                        JtkPMICOMPOSITEFCF
//
///////%}
#define JtkPMI_NONE                    JtkPMINONE
#define JtkPMI_ENTITY                  JtkPMIENTITY
#define JtkPMI_VISUAL_ENTITY           JtkPMIVISUALENTITY
#define JtkPMI_ANNOTATION              JtkPMIANNOTATION
#define JtkPMI_GLYPH                   JtkPMIGLYPH
#define JtkPMI_OUTLINE_GLYPH           JtkPMIOUTLINEGLYPH
#define JtkPMI_POLYGON_GLYPH           JtkPMIPOLYGONGLYPH
#define JtkPMI_DIMENSION               JtkPMIDIMENSION
#define JtkPMI_FASTENER                JtkPMIFASTENER
#define JtkPMI_SURFACE_FINISH          JtkPMISURFACEFINISH
#define JtkPMI_FEATURE_CONTROL_FRAME   JtkPMIFEATURECONTROLFRAME
#define JtkPMI_DATUM_FEATURE_SYMBOL    JtkPMIDATUMFEATURESYMBOL
#define JtkPMI_DATUM_TARGET            JtkPMIDATUMTARGET
#define JtkPMI_SPOT_WELD               JtkPMISPOTWELD
#define JtkPMI_LINE_WELD               JtkPMILINEWELD
#define JtkPMI_MATERIAL_SPEC           JtkPMIMATERIALSPEC
#define JtkPMI_PROCESS_SPEC            JtkPMIPROCESSSPEC
#define JtkPMI_PART_SPEC               JtkPMIPARTSPEC
#define JtkPMI_ORGANISATION            JtkPMIORGANISATION
#define JtkPMI_NOTE                    JtkPMINOTE
#define JtkPMI_BALLOON                 JtkPMIBALLOON
#define JtkPMI_MEASUREMENT_POINT       JtkPMIMEASUREMENTPOINT
#define JtkPMI_LOCATOR                 JtkPMILOCATOR
#define JtkPMI_USER_DEFINED_SYMBOL     JtkPMIUSERDEFINEDSYMBOL
#define JtkPMI_CIRCLE_CENTRE           JtkPMICIRCLECENTRE
#define JtkPMI_COORDINATE_NOTE         JtkPMICOORDINATENOTE
#define JtkPMI_ATTRIBUTE_NOTE          JtkPMIATTRIBUTENOTE
#define JtkPMI_BUNDLE_DRESSING_NOTE    JtkPMIBUNDLEDRESSINGNOTE
#define JtkPMI_CUTTING_PLANE_SYMBOL    JtkPMICUTTINGPLANESYMBOL
#define JtkPMI_CROSSHATCH              JtkPMICROSSHATCH
#define JtkPMI_E_MARKING               JtkPMIEMARKING
#define JtkPMI_MODEL_VIEW              JtkPMIMODELVIEW
#define JtkPMI_DESIGN_GROUP            JtkPMIDESIGNGROUP
#define JtkPMI_VIEW_SET                JtkPMIVIEWSET
#define JtkPMI_REF_GEOMETRY            JtkPMIREFERENCEGEOMETRY
#define JtkPMI_REF_POINT               JtkPMIREFERENCEPOINT
#define JtkPMI_REF_AXIS                JtkPMIREFERENCEAXIS
#define JtkPMI_REF_PLANE               JtkPMIREFERENCEPLANE
#define JtkPMI_COORDINATE_SYSTEM       JtkPMICOORDINATESYSTEM
#define JtkPMI_REGION                  JtkPMIREGION
#define JtkPMI_SECTION                 JtkPMISECTION
#define JtkPMI_SECTION_GROUP           JtkPMISECTIONGROUP
#define JtkPMI_CENTERLINE              JtkPMICENTERLINE
#define JtkPMI_FITDESIGNATION          JtkPMIFITDESIGNATION
#define JtkPMI_COMPOSITEFCF            JtkPMICOMPOSITEFCF

///////%{
//
// Class          : JtkEntity
//
// Description    : Base toolkit object.
//
// Enums          : TypeID
//                     JtkNONE -- Default unknown object type.
//                     JtkENTITY -- JtkEntity object type.
//                     JtkREFCOUNTED -- JtkRefCounted object type.
//                     JtkTOPOLOGY -- JtkTopology object type.
//                     JtkBREP -- JtkBrep object type.
//                     JtkREGION -- JtkRegion object type.
//                     JtkSHELL -- JtkShell object type.
//                     JtkFACE -- JtkFace object type.
//                     JtkLOOP -- JtkLoop object type.
//                     JtkCOEDGE -- JtkCoedge object type.
//                     JtkEDGE -- JtkEdge object type.
//                     JtkVERTEX -- JtkVertex object type.
//                     JtkVERTEXPOOL -- JtkVertexPool object type.
//                     JtkGEOMETRY -- JtkGeometry object type.
//                     JtkPRIM -- JtkPrim object type.
//                     JtkSHAPE -- JtkShape object type.
//                     JtkSURFACE -- JtkSurface object type.
//                     JtkNURBSSURFACE -- JtkNURBSSurface object type.
//                     JtkNURBSCURVE -- JtkNURBSCurve object type.
//                     JtkCURVE -- JtkCurve object type.
//                     JtkANALYTICCURVE -- JtkAnalyticCurve object type.
//                     JtkUVCURVE -- JtkUVCurve object type.
//                     JtkXYZCURVE -- JtkXYZCurve object type.
//                     JtkTRISTRIPSET -- JtkTriStripSet object type.
//                     JtkPOINTSET -- JtkPointSet object type.
//                     JtkLINESTRIPSET -- JtkLineStripSet object type.
//                     JtkPOLYGONSET -- JtkPolygonSet object type.
//                     JtkPOINT -- JtkPoint object type.
//                     JtkATTRIB -- JtkAttrib object type.
//                     JtkUNSUPPORTEDATTRIB --  JT attributes that do not have JtAttrib representations.
//                     JtkLIGHT -- JtkLightSet object type.
//                     JtkMATERIAL -- JtkMaterial object type.
//                     JtkTRANSFORM -- JtkTransform object type.
//                     JtkTEXIMAGE -- JtkTexImage object type.
//                     JtkTEXIMAGEDESCRIPTION -- JtkTexImageDescription object type.
//                     JtkIMAGESTAMP -- JtkImageStamp object type.
//                     JtkPOINTLIGHT -- JtkPointLight object type.
//                     JtkINFINITELIGHT -- JtkInfiniteLight object type.
//                     JtkSHADER -- JtkShader object type.
//                     JtkSHADEREFFECTS -- JtkShaderEffects object type.
//                     JtkSHADERPARAM -- JtkShaderParam object type.
//                     JtkPROPERTY -- JtkProperty object type.
//                     JtkHIERARCHY -- JtkHierarchy object type.
//                     JtkUNITHIERARCHY -- JtkUnitHierarchy object type.
//                     JtkASSEMBLY -- JtkAssembly object type.
//                     JtkPART -- JtkPart object type.
//                     JtkINSTANCE -- JtkInstance object type.
//                     JtkCLIENTDATA -- JtkClientData object type.
//                     JtkWIRE -- JtkWire object type.
//                     JtkCADEXPORTER -- JtkCADExporter object type.
//                     JtkCADIMPORTER -- JtkCADImporter object type.
//                     JtkENTITYSTACK -- JtkEntityStack object type.
//                     JtkSTACK -- JtkStack object type.
//                     JtkENTITYTABLE -- JtkEntityTable object type.
//                     JtkMOTIONEXPORTER -- JtkMotionExporter object type.
//                     JtkPARTTABLE -- JtkPartTable object type.
//                     JtkPROPERTYFILTER -- JtkPropertyFilter object type.
//                     JtkTRAVERSER -- JtkTraverser object type.
//                     JtkWREP -- JtkWrep object type.
//                     JtkHARNESS -- JtkHarness object type.
//                     JtkWREPWIRE -- JtkWrepWire object type.
//                     JtkBUNDLE -- JtkBundle object type.
//                     JtkSEGMENT -- JtkSegment object type.
//                     JtkBOXSET -- JtkBoxSet object type.
//                     JtkCYLINDERSET -- JtkCylinderSet object type.
//                     JtkPYRAMIDSET -- JtkPyramidSet object type.
//                     JtkSPHERESET -- JtkSphereSet object type.
//                     JtkTRIPRISMSET -- JtkTriPrismSet object type.
//                     JtkPARSER -- JtkParser object type.
//                     JtkPARSERACTION -- JtkParserAction object type.
//                     JtkPARSERCONTEXT -- JtkParserContext object type.
//                     JtkCONFIG -- JtkConfig object type.
//                     JtkCONFIGDATA -- JtkConfigData object type.
//                     JtkCONFIGBOOLDATA -- JtkConfigBoolData object type.
//                     JtkCONFIGFPDATA -- JtkConfigFPData object type.
//                     JtkCONFIGSTRINGDATA -- JtkConfigStringData object type.
//                     JtkCONFIGINTDATA -- JtkConfigIntData object type.
//                     JtkCONFIGITEM -- JtkConfigItem object type.
//                     JtkCONFIGGROUP -- JtkConfigGroup object type.
//                     JtkREFERENCEMAP -- JtkReferenceMap object type.
//                     JtkLINECURVE -- JtkLineCurve object type.
//                     JtkCIRCLECURVE -- JtkCircleCurve object type.
//                     JtkELLIPSECURVE -- JtkEllipseCurve object type.
//                     JtkPARABOLACURVE -- JtkParabolaCurve object type.
//                     JtkHYPERBOLACURVE -- JtkHyperbolaCurve object type.
//                     JtkCAE -- JtkCae object type.
//                     JtkCAEVISUAL -- JtkCaeVisual object type.
//                     JtkCAECOLORBAR -- JtkCaeColorbar object type.
//                     JtkCAELEGEND -- JtkCaeLegend obejct type.
//                     JtkNULLSHAPE -- JtkNullShape obejct type.
//                     JtkTESSASSOCIATION -- JtkTessAssociation object type.
//                     JtkTESSGROUP -- JtkTessGroup object type.
//                     JtkTESSPARAMS -- JtkTessParams object type.
//                     JtkPMINONE -- Default unknown PMI object type.
//                     JtkPMIENTITY -- JtkPMIEntity object type.
//                     JtkPMIGENERICENTITY -- JtkPMIGenericEntity object type.
//                     JtkPMIVISUALENTITY -- JtkPMIVisualEntity object type.
//                     JtkPMIANNOTATION -- JtkPMIAnnotation object type.
//                     JtkPMIGLYPH -- JtkPMIGlyph object type.
//                     JtkPMIOUTLINEGLYPH -- JtkPMIOutlineGlyph object type.
//                     JtkPMIPOLYGONGLYPH -- JtkPMIPolygonGlyph object type.
//                     JtkPMIDIMENSION -- JtkPMIDimention object type.
//                     JtkPMIFASTENER -- JtkPMIFastener object type.
//                     JtkPMISURFACEFINISH -- JtkPMISurfaceFinish object type.
//                     JtkPMIFEATURECONTROLFRAME -- JtkPMIFeatureControlFrame object type.
//                     JtkPMIDATUMFEATURESYMBOL -- JtkPMIDatumFeatureSymbol object type.
//                     JtkPMIDATUMTARGET -- JtkPMIDatumTarget object type.
//                     JtkPMISPOTWELD -- JtkPMISpotWeld object type.
//                     JtkPMILINEWELD -- JtkPMILineWeld object type.
//                     JtkPMIMATERIALSPEC -- JtkPMIMaterialSpec object type.
//                     JtkPMIPROCESSSPEC -- JtkPMIProcessSpec object type.
//                     JtkPMIPARTSPEC -- JtkPMIPartSpec object type.
//                     JtkPMIORGANISATION -- JtkPMIOrganisation object type.
//                     JtkPMINOTE -- JtkPMINote object type.
//                     JtkPMIBALLOON -- JtkPMIBalloon object type.
//                     JtkPMIMEASUREMENTPOINT -- JtkPMIMeasurementPoint object type.
//                     JtkPMILOCATOR -- JtkPMILocator object type.
//                     JtkPMIUSERDEFINEDSYMBOL -- JtkPMIUserDefinedSymbol object type.
//                     JtkPMICIRCLECENTRE -- JtkPMICircleCentre object type.
//                     JtkPMICOORDINATENOTE -- JtkPMICoordinateNote object type.
//                     JtkPMIATTRIBUTENOTE -- JtkPMIAttributeNote object type.
//                     JtkPMIBUNDLEDRESSINGNOTE -- JtkPMIBundleDressingNote
//                     JtkPMICUTTINGPLANESYMBOL -- JtkPMICuttingPlaneSymbol
//                     JtkPMICROSSHATCH -- JtkPMICrosshatch object type.
//                     JtkPMIEMARKING -- JtkPMIeMarking object type.
//                     JtkPMIMODELVIEW -- JtkPMIModelView object type.
//                     JtkPMIMODELVIEWLIST -- JtkPMIModelViewList object type.
//                     JtkPMIFOLDER -- JtkPMIFolder object type.
//                     JtkPMIDESIGNGROUP -- JtkPMIDesignGroup object type.
//                     JtkPMIVIEWSET -- JtkPMIViewSet object type.
//                     JtkPMIREFERENCEGEOMETRY -- JtkPMIReferenceGeometry object type.
//                     JtkPMIREFERENCEPOINT -- JtkPMIReferencePoint object type.
//                     JtkPMIREFERENCEAXIS -- JtkPMIReferenceAxis object type.
//                     JtkPMIREFERENCEPLANE -- JtkPMIReferencePlane object type.
//                     JtkPMICOORDINATESYSTEM -- JtkPMICoordinateSystem object type.
//                     JtkPMIREGION -- JtkPMIRegion object type.
//                     JtkPMISECTION -- JtkPMISection object type.
//                     JtkPMICENTERLINE -- JtkPMICenterLine object type.
//                     JtkPMIFITDESIGNATION -- JtkPMIFitDesignation object type.
//                     JtkPMICOMPOSITEFCF -- JtkPMICompositeFCF object type.
//                     JtkPMIREFERENCECIRCLE -- JtkPMIReferenceCircle object type.
//                     JtkPMIREFERENCECYLINDER -- JtkPMIReferenceCylinder object type.
//                     JtkPMICALLOUTDIMENSION -- JtkPMICalloutDimension object type.
//                     JtkPMIPARAMETERDIMENSION -- JtkPMIParameterDimension object type.
//                     JtkPMICHAMFER -- a JtkPMIChamfer object type.
//                     JtkXTENTITY -- JtkXTEntity object type.
//                     JtkXTATTRIB -- JtkXTAttrib object type.
//                     JtkXTMATERIAL -- JtkXTMaterial object type.
//                     JtkXTTOPOLOGY -- JtkXTTopology object type.
//                     JtkXTGEOMETRY -- JtkXTGeometry object type.
//                     JtkXTSURFACE -- JtkXTSurface object type.
//                     JtkXTBODY -- JtkXTBody object type.
//                     JtkXTREGION -- JtkXTRegion object type.
//                     JtkXTSHELL -- JtkXTShell object type.
//                     JtkXTFACADE -- JtkXTFacade object type.
//                     JtkXTFACE -- JtkXTFace object type.
//                     JtkXTLOOP -- JtkXTLoop object type.
//                     JtkXTFIN -- JtkXTFin object type.
//                     JtkXTEDGE -- JtkXTEdge object type.
//                     JtkXTSPOKE -- JtkXTSpoke object type.
//                     JtkXTVERTEX -- JtkXTVertex object type.
//                     JtkXTPOINT -- JtkXTPoint object type.
//                     JtkXTCURVE -- JtkXCurve object type.
//                     JtkXTBCURVE -- JtkXTBCurve object type.
//                     JtkXTCIRCLE -- JtkXTCircle object type.
//                     JtkXTELLIPSE -- JtkXTEllipse object type.
//                     JtkXTLINE -- JtkXTLine object type.
//                     JtkXTSPCURVE -- JtkXTSPCurve object type.
//                     JtkXTICURVE -- JtkXTICurve  object type.
//                     JtkXTBSURF -- JtkXTBSurf object type.
//                     JtkXTBLENDSURF -- JtkXTBlendSurf object type.
//                     JtkXTCONE -- JtkXTCone object type.
//                     JtkXTCYLINDER -- JtkXTCylinder object type.
//                     JtkXTOFFSET -- JtkXTOffset object type.
//                     JtkXTPLANE -- JtkXTPlane object type.
//                     JtkXTSPHERE -- JtkXTSphere object type.
//                     JtkXTSPUN -- JtkXTSpun object type.
//                     JtkXTSWEPT -- JtkXTSwept object type.
//                     JtkXTTORUS -- JtkXTTorus object type.
//                     JtkXTMESH -- JtkXTMesh object type.
//                     JtkXTPOLYLINE -- JtkXTPolyline object type.
//                     JtkPMISECTIONGROUP -- JtkPMISectionGroup object type.
//                     JtkXTENTITYMONIKER -- JtkXTEntityMoniker object type.
//                     JtkXTBODYMONIKER -- JtkXTBodyMoniker object type.
//                     JtkXTSHARINGMANAGER -- JtkXTSharingManager object type.
//                     JtkXTSHARINGGROUP -- JtkXTSharingGroup object type.
//                     JtkFAULT -- JtkFault object type.
//                     JtkXTFAULT -- JtkXTFault object type.
//                     JtkXTGEOMETRYFAULT -- JtkXTGeometryFault object type.
//                     JtkXTSINGLEPOINTGEOMETRYFAULT -- JtkXTSinglePointGometryFault object type.
//                     JtkXTENTITYFAULT -- JtkXTEntityFault object type.
//                     JtkXTSINGLEENTITYFAULT -- JtkXTSingleEntityFault object type.
//                     JtkXTMULTIPLEENTITYFAULT -- JtkXTMultipleEntityFault object type.
//                     JtkENTITYLIST -- JtkEntityList object type.
//                     JtkLAYERMANAGER -- JtkLayerManager object type.
//                     JtkLAYERFILTER -- JtkLayerFilter object type.
//                     JtkLAYER -- JtkLayer object type.
//                     JtkGUIDMANAGER -- JtkGuidManager object type.
//                     JtkGUID -- JtkGuid object type.
//                     JtkXTMONIKERGUID -- JtkXTMonikerGuid object type.
//                     JtkCROSSHATCHPATTERN -- JtkCrosshatchPattern object type.
//                     JtkCROSSHATCHGROUP -- JtkCrosshatchGroup object type.
//                     JtkREFERENCELINK -- JtkReferenceLink object type.
//                     JtkREFERENCE -- JtkReference object type.
//                     JtkPMIREFERENCE -- JtkPMIReference object type.
//                     JtkPMICROSSHATCHPATTERN -- JtkPMICrosshatchPattern object type.
//                     JtkPMITEXT -- JtkPMIText object type.
//                     JtkCAEID -- JtkCaeId object type.
//                     JtkCAERESULT -- JtkCaeResult object type.
//                     JtkCAERESULTSTEP -- JtkCaeResultStep object type.
//                     JtkCAERESULTQUANTITYARRAY -- JtkCaeResultQuantityArray object type.
//                     JtkCAERESULTQUANTITYSTEPLEGEND -- JtkCaeResultQuantityStepLegend object type.
//                     JtkCAEMANAGER -- JtkCaeManager object type.
//                     JtkREFERENCESET -- JtkReferenceSet object type.
//                     JtkREFERENCESETMANAGER -- JtkReferenceSetManager object type.
//                     JtkMOTION -- JtkMotion object type
//                     JtkMOTIONGROUP -- JtkMotionGroup object type
//                     JtkMOTIONMANAGER -- JtkMotionManager object type
//                     JtkTHREAD -- JtkThread object type
//                     JtkCOUNTERBORE -- JtkCounterBore object type
//                     JtkCOUNTERSINK -- JtkCounterSink object type
//                     JtkHOLECOMPONENT -- JtkHoleComponent object type
//                     JtkHOLEPOSITION -- JtkHolePosition object type
//                     JtkFEATURE -- JtkFeature object type
//                     JtkHOLEFEATURE -- JtkHoleFeature object type
//                     JtkTHREADEDFEATURE -- JtkThreadedFeature object type
//                     JtkPMICONTAINER -- JtkPMIContainer object type.
//                     JtkCONTINUOUSJOINFEATURE -- JtkContinuousJoinFeature object type
//                     JtkARCWELDFEATURE -- JtkArcWeldFeature object type
//                     JtkDATUMFEATURE -- JtkDatumFeature object type
//                     JtkDISCRETEJOINFEATURE -- JtkDiscreteJoinFeature object type
//                     JtkRESISTANCEWELDFEATURE -- JtkResistanceWeldFeature object type
//                     JtkSURFACEADDFEATURE -- JtkSurfaceAddFeature object type
//                     JtkADHESIVEFILLFEATURE -- JtkAdhesiveFillFeature object type
//                     JtkSURFACEWELDFEATURE -- JtkSurfaceWeldFeature object type
//                     JtkMEASUREMENTLOCATORFEATURE -- JtkMeasurementLocatorFeature object type
//                     JtkFEATUREGROUP -- JtkFeatureGroup object type
//                     JtkPMIMEMBER -- JtkPMIMember object type
//                     JtkPMITABLE -- JtkPMITable object type
//                     JtkPMITABLECOLUMN -- JtkPMITableColumn object type
//                     JtkPMITABLEROW -- JtkPMITableRow object type
//                     JtkPMITABLECELL -- JtkPMITableCell object type
//                     JtkPMITABLEMEMBER -- JtkPMITableMember object type
//                     JtkPMITABLEVALUE -- JtkPMITableValue object type
//                     JtkPMITABLELISTVALUE -- JtkPMITableListValue object type
//                     JtkPMIANNOTATIONOUTLINE -- JtkPMIAnnotationOutline object type
//                     JtkPMIANNOTATIONOUTLINESTYLE -- JtkPMIAnnotationOutlineStyle object type
//                     JtkPMIFEATURECONTROLFRAMEINDICATOR -- JtkPMIFeatureControlFrameIndicator object type
//                     JtkPMIFEATURECONTROLFRAMEDATUMGROUP -- JtkPMIFeatureControlFrameDatumGroup object type
//                     JtkPMIFEATURECONTROLFRAMEDATUMREFERENCE -- JtkPMIFeatureControlFrameDatumReference object type
//                     JtkPMITEXTITEM -- JtkPMITextItem object type
//                     JtkPMIDIMENSIONTEXT -- JtkPMIDimensionText object type
//                     JtkPMIDIMENSIONGENERALTOLERANCEISO -- JtkPMIDimensionGeneralToleranceISO object type
//
// Includes       : JtkEntity.h
//
// Inheritance    : JtkEntity
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkEntity
{
private:

   // copy constructor
   JtkEntity( const JtkEntity & );

   // assignment operator
   JtkEntity &operator=( const JtkEntity &OtherEntity );

public:

   // constructor
   JtkEntity();

   // enums for isOfType().
   enum TypeID
   {
      JtkNONE,
      JtkENTITY,
      JtkREFCOUNTED,
      JtkHIERARCHY,
      JtkUNITHIERARCHY,
      JtkBREP,
      JtkTOPOLOGY,
      JtkREGION,
      JtkSHELL,
      JtkFACE,
      JtkLOOP,
      JtkCOEDGE,
      JtkEDGE,
      JtkVERTEX,
      JtkVERTEXPOOL,
      JtkGEOMETRY,
      JtkSURFACE,
      JtkNURBSCURVE,
      JtkNURBSSURFACE,
      JtkUVCURVE,
      JtkXYZCURVE,
      JtkTRISTRIPSET,
      JtkPOINTSET,
      JtkLINESTRIPSET,
      JtkPOLYGONSET,
      JtkPOINT,
      JtkLIGHT,
      JtkATTRIB,
      JtkUNSUPPORTEDATTRIB,
      JtkMATERIAL,
      JtkTRANSFORM,
      JtkTEXIMAGE,
      JtkTEXIMAGEDESCRIPTION,
      JtkIMAGESTAMP,
      JtkPROPERTY,
      JtkASSEMBLY,
      JtkPART,
      JtkINSTANCE,
      JtkCLIENTDATA,
      JtkWIRE,
      JtkCADEXPORTER,
      JtkCADIMPORTER,
      JtkCADIMPORTER2,
      JtkENTITYSTACK,
      JtkSTACK,
      JtkENTITYTABLE,
      JtkMOTIONEXPORTER,
      JtkPARTTABLE,
      JtkPROPERTYFILTER,
      JtkTRAVERSER,
      JtkWREP,
      JtkHARNESS,
      JtkWREPWIRE,
      JtkBUNDLE,
      JtkSEGMENT,
      JtkPRIM,
      JtkBOXSET,
      JtkSHAPE,
      JtkCYLINDERSET,
      JtkPYRAMIDSET,
      JtkSPHERESET,
      JtkTRIPRISMSET,
      JtkPARSER,
      JtkPARSERACTION,
      JtkPARSERCONTEXT,
      JtkCONFIG,
      JtkCONFIGDATA,
      JtkCONFIGBOOLDATA,
      JtkCONFIGFPDATA,
      JtkCONFIGSTRINGDATA,
      JtkCONFIGINTDATA,
      JtkCONFIGITEM,
      JtkCONFIGGROUP,
      JtkPOINTLIGHT,
      JtkINFINITELIGHT,
      JtkSHADER,
      JtkSHADEREFFECTS,
      JtkSHADERPARAM,
      JtkREFERENCEMAP,
      JtkLINECURVE,
      JtkCIRCLECURVE,
      JtkELLIPSECURVE,
      JtkPARABOLACURVE,
      JtkHYPERBOLACURVE,
      JtkCAE,
      JtkCAEVISUAL,
      JtkCAECOLORBAR,
      JtkCAELEGEND,
      JtkNULLSHAPE,
      JtkTESSASSOCIATION,
      JtkTESSGROUP,
      JtkTESSPARAMS,
      JtkPMINONE,
      JtkPMIENTITY,
      JtkPMIGENERICENTITY,
      JtkPMIVISUALENTITY,
      JtkPMIANNOTATION,
      JtkPMIGLYPH,
      JtkPMIOUTLINEGLYPH,
      JtkPMIPOLYGONGLYPH,
      JtkPMIDIMENSION,
      JtkPMIFASTENER,
      JtkPMISURFACEFINISH,
      JtkPMIFEATURECONTROLFRAME,
      JtkPMIDATUMFEATURESYMBOL,
      JtkPMIDATUMTARGET,
      JtkPMISPOTWELD,
      JtkPMILINEWELD,
      JtkPMIMATERIALSPEC,
      JtkPMIPROCESSSPEC,
      JtkPMIPARTSPEC,
      JtkPMIORGANISATION,
      JtkPMINOTE,
      JtkPMIBALLOON,
      JtkPMIMEASUREMENTPOINT,
      JtkPMILOCATOR,
      JtkPMIUSERDEFINEDSYMBOL,
      JtkPMICIRCLECENTRE,
      JtkPMICOORDINATENOTE,
      JtkPMIATTRIBUTENOTE,
      JtkPMIBUNDLEDRESSINGNOTE,
      JtkPMICUTTINGPLANESYMBOL,
      JtkPMICROSSHATCH,
      JtkPMIEMARKING,
      JtkPMIMODELVIEW,
      JtkPMIMODELVIEWLIST,
      JtkPMIFOLDER,
      JtkPMIDESIGNGROUP,
      JtkPMIVIEWSET,
      JtkPMIREFERENCEGEOMETRY,
      JtkPMIREFERENCEPOINT,
      JtkPMIREFERENCEAXIS,
      JtkPMIREFERENCEPLANE,
      JtkPMICOORDINATESYSTEM,
      JtkPMIREGION,
      JtkPMISECTION,
      JtkPMICENTERLINE,
      JtkPMIFITDESIGNATION,
      JtkPMICOMPOSITEFCF,
      JtkPMIREFERENCECIRCLE,
      JtkPMIREFERENCECYLINDER,
      JtkPMICALLOUTDIMENSION,
      JtkPMIPARAMETERDIMENSION,
      JtkPMICHAMFER,
      JtkXTENTITY,
      JtkXTATTRIB,
      JtkXTMATERIAL,
      JtkXTTOPOLOGY,
      JtkXTGEOMETRY,
      JtkXTSURFACE,
      JtkXTBODY,
      JtkXTREGION,
      JtkXTSHELL,
      JtkXTFACADE,
      JtkXTFACE,
      JtkXTLOOP,
      JtkXTFIN,
      JtkXTEDGE,
      JtkXTSPOKE,
      JtkXTVERTEX,
      JtkXTPOINT,
      JtkXTCURVE,
      JtkXTBCURVE,
      JtkXTCIRCLE,
      JtkXTELLIPSE,
      JtkXTLINE,
      JtkXTSPCURVE,
      JtkXTICURVE,
      JtkXTBSURF,
      JtkXTBLENDSURF,
      JtkXTCONE,
      JtkXTCYLINDER,
      JtkXTOFFSET,
      JtkXTPLANE,
      JtkXTSPHERE,
      JtkXTSPUN,
      JtkXTSWEPT,
      JtkXTTORUS,
      JtkXTMESH,
      JtkXTPOLYLINE,
      JtkPMISECTIONGROUP,
      JtkXTENTITYMONIKER,
      JtkXTBODYMONIKER,
      JtkFAULT,
      JtkXTFAULT,
      JtkXTGEOMETRYFAULT,
      JtkXTSINGLEPOINTGEOMETRYFAULT,
      JtkXTSHARINGMANAGER,
      JtkXTSHARINGGROUP,
      JtkXTENTITYFAULT,
      JtkXTSINGLEENTITYFAULT,
      JtkXTMULTIPLEENTITYFAULT,
      JtkENTITYLIST,
      JtkLAYERMANAGER,
      JtkLAYERFILTER,
      JtkLAYER,
      JtkGUIDMANAGER,
      JtkGUID,
      JtkXTMONIKERGUID,
      JtkANALYTICCURVE,
      JtkCURVE,
      JtkCROSSHATCHPATTERN,
      JtkCROSSHATCHGROUP,
      JtkREFERENCELINK,
      JtkREFERENCE,
      JtkPMIREFERENCE,
      JtkPMICROSSHATCHPATTERN,
      JtkPMITEXT,
      JtkPMITEXTFORMAT,
      JtkCAEID,
      JtkCAERESULT,
      JtkCAERESULTSTEP,
      JtkCAERESULTQUANTITYARRAY,
      JtkCAERESULTQUANTITYSTEPLEGEND,
      JtkCAEMANAGER,
      JtkREFERENCESET,
      JtkREFERENCESETMANAGER,
      JtkMOTION,
      JtkMOTIONGROUP,
      JtkMOTIONMANAGER,
      JtkTHREAD,
      JtkHOLEELEMENT,
      JtkCOUNTERBORE,
      JtkCOUNTERSINK,
      JtkHOLECOMPONENT,
      JtkHOLEPOSITION,
      JtkFEATURE,
      JtkHOLEFEATURE,
      JtkTHREADEDFEATURE,
      JtkPMICONTAINER,
      JtkCONTINUOUSJOINFEATURE,
      JtkARCWELDFEATURE,
      JtkDATUMFEATURE,
      JtkDISCRETEJOINFEATURE,
      JtkRESISTANCEWELDFEATURE,
      JtkSURFACEADDFEATURE,
      JtkADHESIVEFILLFEATURE,
      JtkSURFACEWELDFEATURE,
      JtkMEASUREMENTLOCATORFEATURE,
      JtkFEATUREGROUP,
      JtkPMIMEMBER,
      JtkPMITABLE,
      JtkPMITABLEMEMBER,
      JtkPMITABLECOLUMN,
      JtkPMITABLEROW,
      JtkPMITABLECELL,
      JtkPMITABLEVALUE,
      JtkPMITABLELISTVALUE,
      JtkPMIANNOTATIONOUTLINE,
      JtkPMIANNOTATIONOUTLINESTYLE,
	   JtkPMIFEATURECONTROLFRAMEINDICATOR,
	   JtkPMIFEATURECONTROLFRAMEDATUMGROUP,
	   JtkPMIFEATURECONTROLFRAMEDATUMREFERENCE,
      JtkPMITEXTITEM,
      JtkPMIDIMENSIONTEXT,
      JtkPMIDIMENSIONGENERALTOLERANCEISO         
   };

   // Type identification methods.
   static TypeID classTypeID( );
   virtual TypeID typeID() const;
   JtkString typeIDName() const;
   int isOfType( TypeID id ) const;
   int isOfSubType( TypeID id ) const;
   TypeID parentTypeID( ) const;

   static inline JtkEntity* headAllocation() { return(_allocListHead); };
   inline        JtkEntity* prevAllocation() { return(_allocListPrev); };
   inline        long       allocIndex()     { return(_allocIndex); };
   inline        JtkEntity* nextAllocation() { return(_allocListNext); };
   static inline JtkEntity* tailAllocation() { return(_allocListTail); };

   // equality operator
   int operator==( const JtkEntity &OtherEntity )const;

protected:

   virtual ~JtkEntity();

   // Debug help.
   static JtkEntity* _allocListHead;
   JtkEntity*        _allocListPrev;
   long              _allocIndex;
   JtkEntity*        _allocListNext;
   static JtkEntity* _allocListTail;
   static long       _allocCount;
};

///////%{
//
// Class          : JtkRefCounted
//
// Description    : Base toolkit object for reference counted objects.
//
// Includes       : JtkEntity.h
//
// Inheritance    : JtkEntity > JtkRefCounted
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkRefCounted : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkRefCounted )

private:

   // Reference count.  This value is incremented/decremented with each call
   // to ref()/unref().  When the value is decremented to 0, the object is
   // deleted.
   mutable int referenceCount;

public:

   // constructor
   JtkRefCounted();

   // equality operator
   int operator==( const JtkRefCounted &OtherRefCountedEntity ) const;

   // Reference-counting methods.
   void ref() const;
   void unref() const;
   void unrefNoDelete() const;
   int  refCount() const;

   // Compile compatibility help
   void _ref()   { this->ref(); }
   void _unref() { this->unref(); }

protected:

   virtual ~JtkRefCounted();
};

///////%{
//
// Class          : JtkEntityPtr
//
// Description    : A smart pointer for use with JtkEntity-derived objects.
//                  This template class maintains a pointer to a
//                  JtkEntity-derived object and behaves as a smart pointer
//                  to that object.  Upon pointer assignment, the underlying
//                  JtkEntity object (if it is derived from JtkRefCounted)
//                  is implicitly (automatically) referenced. Upon destruction
//                  or reassignment, if the underlying object is derived from
//                  JtkRefCounted it is implicitly unreferenced.
//
// Includes       : JtkEntity.h
//
// Inheritance    : JtkEntityPtr
//
// Visibility     : public
//
// Theory         :
//
///////%}
template <class T>
class JTK_TOOLKIT_TEMPLATE_API JtkEntityPtr
{
public:
   JtkEntityPtr()     : _p(0)
            {}
   JtkEntityPtr(T *p) : _p(p)
            {
               if( ptr() )
               {
                  refInternal( ptr() );
               }
            }
   JtkEntityPtr(const JtkEntityPtr<T> &ap) : _p(ap._p)
            {
               if( ptr() )
               {
                  refInternal( ptr() );
               }
            }

   ~JtkEntityPtr()
            {
               release();
            }

   JtkEntityPtr<T>& operator =(const JtkEntityPtr<T> &ap)
            {
                if( _p != ap._p )
                {
                    if( ap.ptr() )
                    {
                       refInternal( ap.ptr() );
                    }
                    release_and_set(ap.ptr());
                }
                return *this;
            }
   JtkEntityPtr<T>& operator =(T* p)
            {
                if( _p != p )
                {
                    if( p )
                    {
                       refInternal( p );
                    }
                    release_and_set(p);
                }
                return *this;
            }
   T& operator *() const
            {
               return *ptr();
            }
   T* operator ->()
            {
               return ptr();
            }
   const T* operator ->() const
            {
               return ptr();
            }
   operator T* () const
            {
               return ptr();
            }
   bool operator !() const
            {
               return(ptr()==NULL);
            }

   // Release and return the raw object pointer, unref'ing it WITHOUT deleting
   T* detach()
            {
               T* p(_p);
               set(NULL);
               if( p )
               {
                  if ( p->isOfSubType( JtkEntity::JtkREFCOUNTED ) )
                  {
                     ((JtkRefCounted*)p)->unrefNoDelete();
                  }
               }
               return p;
            }

   // Return the raw pointer value
   T* ptr() const
            {
               return _p;
            }

private:

   // Ref supplied pointer *if* derived from JtkRefCounted
   void refInternal(T* p)
            {
               if ( p->isOfSubType( JtkEntity::JtkREFCOUNTED ) )
               {
                  ((JtkRefCounted*)p)->ref( );
               }
            }

   // Unref and set to NULL
   void release()
            {
               release_and_set(NULL);
            }

   // Unref and set to p
   void release_and_set(T* p)
            {
               T* pPrev = ptr();
               set(p);
               if( pPrev )
               {
                  if ( pPrev->isOfSubType( JtkEntity::JtkREFCOUNTED ) )
                  {
                     ((JtkRefCounted*)pPrev)->unref();
                  }
               }
            }

   // Set internal pointer to p
   void set(T* p)
            {
               _p = p;
            }

   T* _p;
};

#endif

