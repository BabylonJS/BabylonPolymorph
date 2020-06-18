////////////////////////////////////////////////////////////////////////////////
// Copyright 2006 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_STANDARD_HXX
#define JTK_STANDARD_HXX

// Major and minor version for this library
#define JTTK_MAJOR_VERSION 10
#define JTTK_MINOR_VERSION 5

// Convenience #if macros for user code
#define SPLM_PROD_VER(maj,min,qrm) ((maj<<8) + (min<<4) + qrm)
#define JTTK_CURR_VER   SPLM_PROD_VER(JTTK_MAJOR_VERSION,JTTK_MINOR_VERSION,0)
#define JTTK_VER_EQ(maj,min)  ( JTTK_CURR_VER == SPLM_PROD_VER(maj,min,0) )
#define JTTK_VER_GE(maj,min)  ( JTTK_CURR_VER >= SPLM_PROD_VER(maj,min,0) )
#define JTTK_VER_GT(maj,min)  ( JTTK_CURR_VER >  SPLM_PROD_VER(maj,min,0) )
// Example usage:
//   #if JTTK_VER_EQ(8,5)
//      ...code relevant to JtTk v8.5...
//   #endif

// Major and minor ISO JT version (ISO 14306:2012)
#define JTTK_MAJOR_ISO_JT_VER 9
#define JTTK_MINOR_ISO_JT_VER 5

// Windows versus non-Windows API signature needs
#if !defined( _WIN32 ) || defined( STATIC_LIB )
#define JTK_TOOLKIT_API
#define JTK_TOOLKIT_TEMPLATE_API
#else
// JTK_DLL_EXPORTS should be defined for compiling toolkit,
// but not for toolkit client builds
#ifdef JTK_DLL_EXPORTS
// C4251: 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
// C4275: non – DLL-interface classkey 'identifier' used as base for DLL-interface classkey 'identifier'
// C4351: Elements of array will be default initialized
// C4996: Functions declared as deprecated
// C4091: '__declspec(dllimport)': ignored on left of 'value' when no variable is declared
#   pragma warning( disable : 4251 4275 4351 4996 4091 )
// C4100: Formal parameter not referenced in body of function
// C4101: Unreferenced local variable
// C4102: Unreferenced label
// C4189: Local variable initialized but not referenced
#   pragma warning( 3 : 4100 4101 4102 4189 )
// C4263: Func with same name a virtual but not same args
// C4264: No available override for virtual function
// C4266: Function is hidden for virtual member function
#   pragma warning( 3 : 4263 4264 4266)
#define JTK_TOOLKIT_API __declspec( dllexport )
#define JTK_TOOLKIT_TEMPLATE_API
#else
#define JTK_TOOLKIT_API __declspec( dllimport )
#define JTK_TOOLKIT_TEMPLATE_API
#endif
#endif
#ifdef _WIN32
#ifdef ERROR
#undef ERROR
#endif
#endif

// Parasolid data stubs
#ifndef PK_PART_t
typedef int PK_PART_t;
#endif
#ifndef PK_BODY_t
typedef int PK_BODY_t;
#endif
#ifndef PK_ENTITY_t
typedef int PK_ENTITY_t;
#endif
#ifndef PK_FACE_t
typedef int PK_FACE_t;
#endif
#ifndef PK_EDGE_t
typedef int PK_EDGE_t;
#endif
#ifndef PK_FIN_t
typedef int PK_FIN_t;
#endif

/*
Precedence of defines

1) classic iostreams headers
JTNOSTDIOS (user defined)
JTKNOSTDIOS (user defined)

2) std iostreams due to any of the following
_HP_NAMESPACE_STD (HP-UX aCC with -AA)
_MSC_VER >= 1300 (PC VC 7.x)
__sun
___linux
___APPLE_CC__
_AIX
__sgi && _COMPILER_VERSION >= 740 (sgi 7.4.x compiler)
JTNOSTDIOS (user defined)
JTKNOSTDIOS (user defined)
*/
# if (!defined (JTNOSTDIOS) && !defined (JTKNOSTDIOS))&& (defined(__sun) || defined(__linux) || defined(__APPLE_CC__) || defined(_AIX) || (defined(__sgi) && _COMPILER_VERSION >= 740) || defined (_HP_NAMESPACE_STD) || defined (JTSTDIOS) || _MSC_VER >= 1300)

#      ifndef JTKSTDIOS
#         define JTKSTDIOS
#      endif

#   else

#      ifndef JTKNOSTDIOS
#         define JTKNOSTDIOS
#      endif

#      ifndef JTNOSTDIOS
#         define JTNOSTDIOS
#      endif

#      ifdef JTKSTDIOS
#         undef JTKSTDIOS
#      endif

#   endif

#include <sys/types.h>

// Using ANSI C++ iostreams?
#ifdef JTKSTDIOS

#include <iostream>
#include <fstream>
#include <strstream>

using std::strstreambuf;
using std::istrstream;
using std::ostrstream;
using std::strstream;

using std::istream;
using std::cin;
using std::ws;
using std::filebuf;
using std::ifstream;
using std::ofstream;
using std::fstream;

using std::ostream;
using std::cout;
using std::cerr;
using std::clog;

using std::ios;
using std::iostream;
using std::streambuf;

using std::endl;
using std::ends;
using std::flush;
using std::streamsize;
using std::ios_base;
using std::streampos;
using std::unitbuf;
using std::nounitbuf;
using std::boolalpha;
using std::noboolalpha;
using std::showbase;
using std::noshowbase;
using std::showpoint;
using std::noshowpoint;
using std::showpos;
using std::noshowpos;
using std::skipws;
using std::noskipws;
using std::uppercase;
using std::nouppercase;
using std::internal;
using std::left;
using std::right;
using std::dec;
using std::hex;
using std::oct;
using std::fixed;
using std::scientific;

// Using "classic" C++ iostreams?
#else

#include <iostream.h>
#include <fstream.h>
#ifdef _WIN32
#include <strstrea.h>
#else
#include <strstream.h>
#endif

#endif

#include <stdlib.h>

// Specifies a series of features that are available in the JtTk
#define JTK_FEATURE_ENHANCED_ERROR_REPORTING    // The improved error reporting API is available.
#define JTK_FEATURE_REF_COUNTED_ENTITY          // Introducion of the JtkRefCounted type to the class hierarchy.
#define JTK_FEATURE_EXTENDED_LINE_WIDTH_SUPPORT // The extended line support for wires, pmi and reference geometry.
#define JTK_FEATURE_ENHANCED_ENTITY_TYPEINFO    // Introduction of the improved typing mechanism.
#define JTK_FEATURE_ENHANCED_LAYER_MANAGER      // Additional functionality provided for the JtkLayerManager.
#define JTK_FEATURE_INIT_ENVIRONMENTOPTION      // The JtkEntityFactory::init function allows specification of a JtTk version environment-setup to use.
#define JTK_MATERIAL_OVERRIDE                   // Improved Material Override support.
#define JTK_FEATURE_PMI_REFERENCE               // Introduction of the JtkPMIReference class.
#define JTK_FEATURE_ABSOLUTE_REFERENCE          // Allow specification of a absolute id.
#define JTK_FEATURE_XTGEOMETRY_SHARING          // Introduction of the JtkXTSharingManager class for XT geometry sharing.
#define JTK_FEATURE_ENVIRONMENT_STANDARDIZATION // Standardized API for accessing JtkEnvironment variables.
#define JTK_FEATURE_ALT_EXPORT                  // Occurence count based style of export cleanup to handle instances across file boundaries.
#define JTK_FEATURE_PMI_POLYLINE_INT_INDEX      // Newer polyline indices should be ints rather than shorts.
#define JTK_FEATURE_JOURNALLING                 // Support for journalling of a toolkit session.
#define JTK_FEATURE_PMIREFGEOM_MULTICAD_MAPPING // JtkPMIReferenceGeometry mapping to MULTICAD properties is supported.
#define JTK_FEATURE_PMI_MODELVIEWLISTS          // JtkPMIModelViewList support added.
#define JTK_FEATURE_V95_MULTITEXTURE_SUPPORT    // Support for multiple textures on JtkShapes.
#define JTK_FEATURE_XTBODY_FILTER               // Filtering of XT dependent on the body type.
#define JTK_FEATURE_PRIME_PMI                   // API support on JtkPMIAnnotationEntity to denote 'prime' status.
#define JTK_FEATURE_STRING                      // JtkString Unicode support
#define JTK_FEATURE_V100_JT_FORMAT              // v10.0 JT file format support
#define JTK_FEATURE_IS_COMPONENT_SUPPORT        // Support for JtkUnitHierarchy::isComponent/setIsComponent.
#define JTK_FEATURE_REFERENCESET_SUPPORT        // Support for JtkReferenceSet functionality
#define JTK_FEATURE_EXPORT_ERROR_REPORTING      // Improved error reporting API for JtkCADExporter::exportJt available.
#define JTK_FEATURE_V100_CAE_SUPPORT            // v10.0 CAE support.
#define JTK_FEATURE_VERTEXPOOL                  // Introduction of the JtkVertexPool class for vertex pool exposure
#define JTK_FEATURE_CONFIG_DATA_STANDARDIZATION // Standardized API for accessing JtkConfigData and derived classes member variables.
#define JTK_FEATURE_MOTION_MANAGER              // JtkMotionManager support
#define JTK_FEATURE_PMISTRING_SANITIZE          // Sanitize PMI strings that fail Unicode conversion
#define JTK_FEATURE_GLYPH_TO_OUTLINE            // Ability to obtain the outline from a JtkPMIPolygonGlyph in order to help users unable to use tessellated glyph data.
#define JTK_FEATURE_PER_SHAPE_MULTIATTR_SUPPORT // Support for multiple attributes on JtkShape.
#define JTK_FEATURE_EXPORT_OPTIONS_UPDATE       // Revamp of JtkCADExporter::Options to support larger range of values.
#define JTK_FEATURE_ENHANCED_CAD_PROPERTIES     // Additional cad properties API support.
#define JTK_FEATURE_XT_TESS_LENGTH_PARAM        // Support for 'length' tessellation parameter with XT Brep
#define JTK_FEATURE_LINESTYLE_STANDARDIZATION   // Standardization of the linestyles applicable to JtkWire and JtkLineStripSet
#define JTK_FEATURE_TESSPARAMS_TRIM_SUPPRESS    // JtkTessParams::JtkTESSELLATION_TRIM_SUPPRESS switched to be represented as a boolean
#define JTK_FEATURE_FEATURES                    // Support for JtkThreadedFeature and JtkHoleFeature added
#define JTK_FEATURE_SECTION_COLOR_FROM_BODY     // API to denote a JtkPMISection cap and curves color should come from the cut body
#define JTK_FEATURE_JTKXTMATERIAL_SUPPORT       // JtkXTMaterial represents the Parasolid color attribute and can be applied to JtkXTFace's.
#define JTK_FEATURE_PMI_CONTAINER               // JtkPMIContainer support
#define JTK_FEATURE_V101_JT_FORMAT              // v10.1 JT file format support
#define JTK_FEATURE_V102_JT_FORMAT              // v10.2 JT file format support
#define JTK_FEATURE_PMI_DISPLAY                 // Extensions to the ability to control the appearance of PMI.
#define JTK_FEATURE_SECTION_GROUP_COMPRESSION   // Support for compression of JtkPMISectionGroup during export
#define JTK_FEATURE_ISO_AUTO_JT_VERSION         // JtkCADExporter::JtkJT_VERSION_AUTO produces ISO file version at minimum
#define JTK_FEATURE_ANALYTIC_CURVE_CONVERSION   // JtkAnalyticCurve -> JtkXYZCurve support.
#define JTK_FEATURE_PMI_IMPORT                  // JtkPMIEntitites are always created on import
#define JTK_FEATURE_MODELVIEW_GENERAL_ATTRIBUTE // JtkPMIModelView API support for GeneralAttribute functionality
#define JTK_FEATURE_IMPORT_CALLBACKS            // Callbacks provided for the JtkCADImporter::import functionality.
#define JTK_FEATURE_ASSEMBLY_FEATURES           // JtkFeatures can now be added to JtkAssembly (in addition to JtkPart)
#define JTK_FEATURE_SEMANTIC_CAE_SUPPORT        // Semantic CAE support.
#define JTK_FEATURE_REFGEOM_END_ARROW           // JtkPMIReferenceAxis and JtkPMICoordinateSystem support an end arrow being added to them
#define JTK_FEATURE_OUTLINE_GLYPH_RETRISTRIP    // It is possible to optimise JtkPMIOutlineGlyph content via retristripping
#define JTK_FEATURE_SEMANTIC_CAE_READ_SUPPORT   // Support for reading Semantic CAE data.
#define JTK_FEATURE_SECTION_ASSEMBLY_HATCHING   // API to denote how a JtkPMISection crosshatching varies with adjacent components
#define JTK_FEATURE_EXTENDED_FEATURE_TYPES      // JtkFeature support has been extended to include weld and locator feature types
#define JTK_FEATURE_MODELVIEW_EDGE_COLOR        // JtkPMIModelview API support for coloring edges in styled views
#define JTK_FEATURE_PMI_UPDATES_86              // JtkPMIEntity derived classes updated inline with the PLM XML SDK schema definitions they are based on
#define JTK_FEATURE_PMI_TABLE                   // JtkPMITable support added
#define JTK_FEATURE_MATERIAL_FIELD_FLAGS        // JtkMaterial support for inhibit/final field flags
#define JTK_FEATURE_MATERIAL_BUMPINESS_FIELD    // JtkMaterial support for bumpiness field
#define JTK_FEATURE_RAW_XTFACE_ATTRIBUTES       // Support for adding JtkAttribs to Raw XT Faces so that, at tessellation, the appropriate attribs are placed on shape.
#define JTK_FEATURE_TESS_GROUP_ID               // JtkTriStripSet support for the tessGroupId
#define JTK_FEATURE_PMI_UPDATES_100             // JtkPMIEntity derived classes updated inline with the PLM XML SDK schema definitions they are based on
#define JTK_FEATURE_IMPORT_LATE_LOAD            // Late-loading functionality.
#define JTK_FEATURE_EXTENDED_LOD_LOAD           // Extended LOD loading functionality
#define JTK_FEATURE_XT_SHARING_PASSTHROUGH      // Passthrough support for XT geometry sharing and JtkXTSharingManager.
#define JTK_FEATURE_PMI_VALIDATION_1            // API for the authoring of PMI Validation properties have been added
#define JTK_FEATURE_PMI_UPDATES_101             // JtkPMIEntity derived classes updated inline with the PLM XML SDK schema definitions they are based on
#define JTK_FEATURE_V103_JT_FORMAT              // v10.3 JT file format support
#define JTK_FEATURE_ASSERTED_PROPERTIES         // Feature flag for asserted properties
#define JTK_FEATURE_DELETE_PMI_ASSOCIATION      // JtkUnitHierarchy has a DeletePMIAssociation API added.
#define JTK_FEATURE_XT_MESH_SUPPORT             // Support for XT Facet Mesh / Convergent modelling.
#define JTK_FEATURE_V104_JT_FORMAT              // v10.4 JT file format support
#define JTK_FEATURE_ULP2                        // Second generation ULP support
#define JTK_FEATURE_MODELVIEW_UPDATES_103       // ModelView support changes made in the JTTK103 timeframe
#define JTK_FEATURE_PMI_VALIDATION_2            // Additional API for the authoring of PMI Validation properties have been added
#define JTK_ISO_UNITS_DEFAULT                   // JtkEnvironment::JtkEXPORT_ISO_UNIT_LABELS now defaults to 1
#define JTK_IS_COMPONENT_API_DEFAULT            // JtkEnvironment::JtkIS_COMPONENT_ENABLED now defaults to 1
#define JTK_SECTION_GROUP_COMPRESSION_DEFAULT   // JtkEnvironment::JtkPMI_SECTION_GROUP_COMPRESSION_ENABLED now defaults to 1
#define JTK_FEATURE_PMI_UPDATES_1810            // JtkPMIEntity derived classes updated inline with the PLM XML SDK schema definitions they are based on
#define JTK_FEATURE_V105_JT_FORMAT              // v10.5 JT file format support
#define JTK_FEATURE_STT_SUPPORT                 // Support for STT
#define JTK_FEATURE_PMI_UPDATES_61956           // Added APIs for getting and setting visual colour and opacity
#define JTK_FEATURE_PMI_UPDATES_62005           // JTTK APIs provided for latest PLM XML schema updates.


//forward declarations
class JtkString;

// Specifies features that are deprecated in the JtTk
#define JTK_DEPRECATION_XT_CONVERT_ALL_TO_NURBS // Deprecated environment option for converting XT to NURBS
#define JTK_DEPRECATION_PMIATTR_STRUCTURES      // PMIAttrGeneric structures are deprecated and semantic API's updated to match the functionality levels
#define JTK_LEGACY_PMI_API_REMOVED              // legacy PMI API's have been removed.
#define JTK_EXPORT_V64_JT_FORMAT_REMOVED        // v6.4 JT format export support has been removed
#define JTK_EXPORT_V70_JT_FORMAT_REMOVED        // v7.0 JT format export support has been removed
#define JTK_LEGACY_EXPORTER_API_REMOVED         // Legacy pre-5.2 toolkit functions / macros defined for JtkCADExporter have been removed.
#define JTK_LEGACY_LOD_PARAM_API_REMOVED        // Legacy LOD parameter APIs have been removed from JtkCADExporter and JtkFace
#define JTK_PMISTRUCTURES_REMOVED			      // All PMIAttr struture API's that where deprecated with JTTK 60 are now removed.
#define JTK_DEPRECATION_ENVIRONMENT_INIT        // All JtkEnvironment::init style functions are deprecated in favour of using JtkEntityFactory::environmentOption
#define JTK_ENVIRONMENT_INIT_REMOVED            // All JtkEnvironment::init style functions are removed.
#define JTK_DEPRECATION_ENVIRONMENT_OPTIONS     // A number of older JtkEnvironment::Options and JtkEntityFactory::environmentOption have been deprecated.
#define JTK_ENVIRONMENT_OPTIONS_REMOVED         // A number of older JtkEnvironment::Options and JtkEntityFactory::environmentOption have been removed

///////%{
//
// Class          : Globals
//
// Description    : These defines are defined with global scope and used
//                  throughout the toolkit.
//
//                  <B>Jtk_ERROR</B> - Return value indicating API failure.
//                                Interpret as a Boolean FALSE.
//                                Equates to an integer value of '0'.
//
//                  <B>Jtk_OK</B> - Return value indicating API success.
//                             Interpret as a Boolean TRUE.
//                             Equates to an integer value of '1'.
//
//                  <B>JtkError</B> - Use like <i>cout</i> or <i>cerr</i>.
//                               Directs output to the stream assigned
//                               to JtkInfo::JtkERROR.
//
//                  <B>JtkWarn</B> - Use like <i>cout</i> or <i>cerr</i>.
//                              Directs output to the stream assigned
//                              to JtkInfo::JtkWARN.
//
//                  <B>JtkDebug</B> - Use like <i>cout</i> or <i>cerr</i>.
//                               Directs output to the stream assigned
//                               to JtkInfo::JtkDEBUG.
//
//                  <B>JtkMessage</B> - Use like <i>cout</i> or <i>cerr</i>.
//                                 Directs output to the stream assigned
//                                 to JtkInfo::JtkMESSAGE.
//
// Enums          : JtkUnits
//                     JtkUNKNOWN -- Unknown units (default except JtkXTEntityFactory)
//                     JtkMICROMETERS -- Micrometer units
//                     JtkMILLIMETERS -- Millimeter units
//                     JtkCENTIMETERS -- Centimeter units
//                     JtkDECIMETERS -- Decimeter units
//                     JtkMETERS -- Meter units (default JtkXTEntityFactory)
//                     JtkKILOMETERS -- Kilometer units
//                     JtkINCHES -- Inch units
//                     JtkFEET -- Feet units
//                     JtkYARDS -- Yard units
//                     JtkMILES -- Mile units
//                     JtkMILS -- Mil (milli-inch) units
//
//                  JtkMeasureEnum :
//                   MeasureEnumLENGTH --
//                   MeasureEnumAREA --
//                   MeasureEnumVOLUME --
//                   MeasureEnumMASS --
//                   MeasureEnumMASSDENSITY --
//                   MeasureEnumFATIGUESTRENGTHCOEFFICIENT --
//                   MeasureEnumTIME --
//                   MeasureEnumANGLE --
//                   MeasureEnumVELOCITY --
//                   MeasureEnumACCELERATION --
//                   MeasureEnumFORCE --
//                   MeasureEnumFORCEPERUNITLENGTH --
//                   MeasureEnumPRESSURE --
//                   MeasureEnumMOMENT --
//                   MeasureEnumSTRESS --
//                   MeasureEnumSTRAIN --
//                   MeasureEnumSTRAINENERGY --
//                   MeasureEnumSTRAINENERGYDENSITY --
//                   MeasureEnumTEMPERATURE --
//                   MeasureEnumHEATFLUX --
//                   MeasureEnumCONVECTIONCOEFFICIENT --
//                   MeasureEnumTHERMALCONDUCTIVITY --
//                   MeasureEnumTHERMALEXPANSIONCOEFFICIENT --
//                   MeasureEnumSPECIFICHEAT --
//                   MeasureEnumANGULARVELOCITY --
//                   MeasureEnumANGULARACCELERATION --
//                   MeasureEnumFATIGUELIFE --
//                   MeasureEnumHEATFLOWRATE --
//                   MeasureEnumTHERMALENERGY --
//                   MeasureEnumMASSMOMENTOFINERTIA --
//                   MeasureEnumDYNAMICVISCOSITY --
//                   MeasureEnumHEATGENERATION --
//                   MeasureEnumTHERMALCONDUCTANCE --
//                   MeasureEnumCONDUCTANCEPERUNITLENGTH --
//                   MeasureEnumTHERMALRESISTANCE --
//                   MeasureEnumMASSFLOWRATE --
//                   MeasureEnumVOLUMEFLOWRATE --
//                   MeasureEnumTEMPERATUREDIFFERENCE --
//                   MeasureEnumFREQUENCY --
//                   MeasureEnumCOEFFICIENTPERUNITLENGTH --
//                   MeasureEnumMOMENTOFINERTIAAREA --
//                   MeasureEnumVISCOUSDAMPING --
//                   MeasureEnumENERGY --
//                   MeasureEnumPOWER --
//                   MeasureEnumMOMENTUM --
//                   MeasureEnumTEMPERATUREGRADIENT --
//                   MeasureEnumENERGYPERUNITMASS --
//                   MeasureEnumDISSIPATIONRATEOFENERGYPERUNITMASS --
//                   MeasureEnumMASSFLUX --
//                   MeasureEnumMASSPERUNITLENGTH --
//                   MeasureEnumMASSPERUNITAREA --
//                   MeasureEnumELECTRICCURRENT --
//                   MeasureEnumELECTRICALRESISTANCE --
//                   MeasureEnumELECTRICALRESISTIVITY --
//                   MeasureEnumELECTRICALCONDUCTANCE --
//                   MeasureEnumVOLTAGE --
//                   MeasureEnumVOLTAGEPERTEMPERATURE --
//                   MeasureEnumDIFFUSIVITY --
//                   MeasureEnumLATENTHEATPERMASS --
//                   MeasureEnumTHERMALENERGYPERAREA --
//                   MeasureEnumTHERMALPIDGAIN --
//                   MeasureEnumTHERMALPIDINTEGRALTERMCONSTANT --
//                   MeasureEnumTHERMALPIDDERIVATIVETERMCONSTANT --
//                   MeasureEnumHEADLOSSCOEFFICIENT --
//                   MeasureEnumTSAIWUCOEFFICIENT --
//                   MeasureEnumMASSLENGTH --
//                   MeasureEnumPERVOLUME --
//                   MeasureEnumWARPINGCONSTANT --
//                   MeasureEnumSTRESSCOMPLIANCE --
//                   MeasureEnumLENGTHPERUNITPRESSURE --
//                   MeasureEnumPRESSUREPERUNITLENGTH --
//                   MeasureEnumPRESSUREPERUNITVELOCITY --
//                   MeasureEnumMOMENTPERANGLE --
//                   MeasureEnumCOEFFICIENTPERUNITTIME --
//                   MeasureEnumANGULARMOMENTUMPERUNITANGLE --
//                   MeasureEnumTHERMALCAPACITANCE --
//                   MeasureEnumINDUCTANCE --
//                   MeasureEnumVOLTAGEPERANGULARVELOCITY --
//                   MeasureEnumPERAREA --
//                   MeasureEnumTEMPERATURECHANGERATE --
//                   MeasureEnumJERK --
//                   MeasureEnumANGULARJERK --
//                   MeasureEnumMAGNETICFIELDSTRENGTH --
//                   MeasureEnumMAGNETICFLUXDENSITY --
//
//                  JtkDataType :
//                   DataTypeINT --
//                   DataTypeINTS --
//                   DataTypeREAL --
//                   DataTypeREALS --
//                   DataTypeBOOLEAN --
//                   DataTypeBOOLEANS --
//                   DataTypeSTRING --
//                   DataTypeREFERENCE --
//                   DataTypeENUM --
//                   DataTypeLIST --
//                   DataTypeDATETIME --
//                   DataTypeNONE --
//
// Includes       : JtkStandard.h
//
// Inheritance    : Globals
//
// Visibility     : public
//
// Theory         :
//
/////////%}
enum
{
   Jtk_ERROR= 0,
   Jtk_OK   = 1
};

enum JtkUnits
{
   JtkUNKNOWN     = 0,
   JtkMICROMETERS,
   JtkMILLIMETERS,
   JtkCENTIMETERS,
   JtkDECIMETERS,
   JtkMETERS,
   JtkKILOMETERS,
   JtkINCHES,
   JtkFEET,
   JtkYARDS,
   JtkMILES,
   JtkMILS
};

enum JtkMeasureEnum
{
   MeasureEnumNONE = -1,
   MeasureEnumLENGTH,
   MeasureEnumAREA,
   MeasureEnumVOLUME,
   MeasureEnumMASS,
   MeasureEnumMASSDENSITY,
   MeasureEnumFATIGUESTRENGTHCOEFFICIENT,
   MeasureEnumTIME,
   MeasureEnumANGLE,
   MeasureEnumVELOCITY,
   MeasureEnumACCELERATION,
   MeasureEnumFORCE,
   MeasureEnumFORCEPERUNITLENGTH,
   MeasureEnumPRESSURE,
   MeasureEnumMOMENT,
   MeasureEnumSTRESS,
   MeasureEnumSTRAIN,
   MeasureEnumSTRAINENERGY,
   MeasureEnumSTRAINENERGYDENSITY,
   MeasureEnumTEMPERATURE,
   MeasureEnumHEATFLUX,
   MeasureEnumCONVECTIONCOEFFICIENT,
   MeasureEnumTHERMALCONDUCTIVITY,
   MeasureEnumTHERMALEXPANSIONCOEFFICIENT,
   MeasureEnumSPECIFICHEAT,
   MeasureEnumANGULARVELOCITY,
   MeasureEnumANGULARACCELERATION,
   MeasureEnumFATIGUELIFE,
   MeasureEnumHEATFLOWRATE,
   MeasureEnumTHERMALENERGY,
   MeasureEnumMASSMOMENTOFINERTIA,
   MeasureEnumDYNAMICVISCOSITY,
   MeasureEnumHEATGENERATION,
   MeasureEnumTHERMALCONDUCTANCE,
   MeasureEnumCONDUCTANCEPERUNITLENGTH,
   MeasureEnumTHERMALRESISTANCE,
   MeasureEnumMASSFLOWRATE,
   MeasureEnumVOLUMEFLOWRATE,
   MeasureEnumTEMPERATUREDIFFERENCE,
   MeasureEnumFREQUENCY,
   MeasureEnumCOEFFICIENTPERUNITLENGTH,
   MeasureEnumMOMENTOFINERTIAAREA,
   MeasureEnumVISCOUSDAMPING,
   MeasureEnumENERGY,
   MeasureEnumPOWER,
   MeasureEnumMOMENTUM,
   MeasureEnumTEMPERATUREGRADIENT,
   MeasureEnumENERGYPERUNITMASS,
   MeasureEnumDISSIPATIONRATEOFENERGYPERUNITMASS,
   MeasureEnumMASSFLUX,
   MeasureEnumMASSPERUNITLENGTH,
   MeasureEnumMASSPERUNITAREA,
   MeasureEnumELECTRICCURRENT,
   MeasureEnumELECTRICALRESISTANCE,
   MeasureEnumELECTRICALRESISTIVITY,
   MeasureEnumELECTRICALCONDUCTANCE,
   MeasureEnumVOLTAGE,
   MeasureEnumVOLTAGEPERTEMPERATURE,
   MeasureEnumDIFFUSIVITY,
   MeasureEnumLATENTHEATPERMASS,
   MeasureEnumTHERMALENERGYPERAREA,
   MeasureEnumTHERMALPIDGAIN,
   MeasureEnumTHERMALPIDINTEGRALTERMCONSTANT,
   MeasureEnumTHERMALPIDDERIVATIVETERMCONSTANT,
   MeasureEnumHEADLOSSCOEFFICIENT,
   MeasureEnumTSAIWUCOEFFICIENT,
   MeasureEnumMASSLENGTH,
   MeasureEnumPERVOLUME,
   MeasureEnumWARPINGCONSTANT,
   MeasureEnumSTRESSCOMPLIANCE,
   MeasureEnumLENGTHPERUNITPRESSURE,
   MeasureEnumPRESSUREPERUNITLENGTH,
   MeasureEnumPRESSUREPERUNITVELOCITY,
   MeasureEnumMOMENTPERANGLE,
   MeasureEnumCOEFFICIENTPERUNITTIME,
   MeasureEnumANGULARMOMENTUMPERUNITANGLE,
   MeasureEnumTHERMALCAPACITANCE,
   MeasureEnumINDUCTANCE,
   MeasureEnumVOLTAGEPERANGULARVELOCITY,
   MeasureEnumPERAREA,
   MeasureEnumTEMPERATURECHANGERATE,
   MeasureEnumJERK,
   MeasureEnumANGULARJERK,
   MeasureEnumMAGNETICFIELDSTRENGTH,
   MeasureEnumMAGNETICFLUXDENSITY
};

enum JtkDataType
{
   DataTypeUNSET = -1,
   DataTypeINT,
   DataTypeINTS,
   DataTypeREAL,
   DataTypeREALS,
   DataTypeBOOLEAN,
   DataTypeBOOLEANS,
   DataTypeSTRING,
   DataTypeREFERENCE,
   DataTypeENUM,
   DataTypeLIST,
   DataTypeDATETIME,
   DataTypeNONE
};

//backwards compatiblity defines to map new name back to old
#define JtkPMIMeasureEnum JtkMeasureEnum
#define JtkPMIDataType JtkDataType

#undef ERROR
#define JtkError     JtkInfo::post( JtkInfo::JtkERROR )
#define JtkWarn      JtkInfo::post( JtkInfo::JtkWARN )
#define JtkDebug     JtkInfo::post( JtkInfo::JtkDEBUG )
#define JtkMessage   JtkInfo::post( JtkInfo::JtkMESSAGE )

///////%{
//
// Class          : JtkInfo
//
// Description    : A static class defining four configurable and filterable
//                  standard toolkit output streams.  All toolkit errors and
//                  warnings are sent through these streams.
//
//                  The four streams include:
//
//                  <B>JtkERROR</B> - Intended for catastrophic and/or
//                  unrecoverable errors.  Output defaults to the C++
//                  <i>cerr</i> stream.
//
//                  <B>JtkWARN</B> - Intended for recoverable or avoidable
//                  errors.  Output defaults to the C++ <i>cout</i> stream.
//
//                  <B>JtkMESSAGE</B> - Intended for informal messages.
//                  Output defaults to the C++ <i>cout</i> stream.
//
//                  <B>JtkDEBUG</B> - Intended for application debug
//                  information.  Output defaults to the C++ <i>cout</i> stream.
//
//                  The user may filter any or all of these streams via the
//                  setFilter() method, as well as redirect these streams via
//                  the setStream() method.
//
//                  Note, for convenience, four global macros --
//                  <i>JtkError</i>, <i>JtkWarn</i>, <i>JtkMessage</i>, and
//                  <i>JtkDebug</i> -- exist for usage which mimics that
//                  associated with normal C++ streams (<i>cout</i>,
//                  <i>cerr</i>, etc.).
//
// Includes       : JtkStandard.h
//
// Inheritance    : JtkInfo
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API   JtkInfo
{
   friend class JtkEntityFactory;

public:
   enum Streams
   {
      JtkNONE     = 0x0000,   // Invalid severity.  No message posted.
      JtkERROR    = 0x0001,   // Catastrophic or unrecoverable error.
      JtkWARN     = 0x0010,   // Recoverable or avoidable error.
      JtkMESSAGE  = 0x0100,   // Informational message.  Not an error.
      JtkDEBUG    = 0x1000    // Debug message.
   };

   static ostream       &post( Streams StreamToUse );

   static int           setStream( Streams StreamToSet, ostream *TheStream );
   static int           getStream( Streams StreamToGet, ostream * &TheStream );

   static int           setFilter( Streams StreamsToFilter );
   static int           removeFilter( Streams StreamsToRemove );
   static int           isFiltered( Streams StreamsToCheck );

private:
   static unsigned long _toFilter;

   static ostream       *_JtkError;
   static ostream       *_JtkWarn;
   static ostream       *_JtkMessage;
   static ostream       *_JtkDebug;
   static ostream       *_JtkNone;
};

///////%{
//
// Class          : JtkVersion
//
// Description    : A static class providing access to toolkit version and
//                  build information.
//
// Includes       : JtkStandard.h
//
// Inheritance    : JtkVersion
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API   JtkVersion
{
public:
   static const char* version();
   static const char* build();
   static char  status();
};

///////%{
//
// Class          : JtkSanitizeString
//
// Description    : A static class providing access to sanitized character string
//                  and the ability to set characters to be sanitized.
//
// Includes       : JtkStandard.h
//
// Inheritance    : JtkSanitizeString
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API   JtkSanitizeString
{
public:
   static const void InitSanitizeCharacterString();
   static const int GetSanitizedFileName(JtkString&);
   static void SetCharactersToBeSanitized(const JtkString&);
   static const int GetCharactersToBeSanitized(JtkString&);
   static const void FiniSanitizeCharacterString();
};

///////%{
//
// Class          : JtkEnvironment
//
// Description    : A static class to hold environment variables.
//
// Enums          : Options
//                     JtkPMI_SEMANTIC_MAPPING_FEATURES -- Controls how the
//                        semantic PMI API maps into JT. Supported versions are:<br />
//                        1 - Hidden values. The mappings will hide the properties 
//                            for values determined to be purely semantic information.<br />
//                        2 - In addition to being hidden (i.e. 1) the JtkPMIReferenceGeometry APIs are also mapped into
//                            MULTICAD properties for authoring. Additional validation
//                            may be done to ensure the values given to the JtkPMIReferenceGeometry
//                            meet the expected ranges for multicad properties. This is default.<br />
//                        The equivalent environment variable is
//                        JTK_SEMANTIC_PMI_FEATURE.
//                     JtkPMI_SECTION_GROUP_COMPRESSION_ENABLED -- If 1 then the toolkit will make use of PMI
//                        Container objects to reduce the number of associations required to represent PMI
//                        Section Groups in JT.
//                        Note: This is only supported in JT version 10.2 or greater files, if export options
//                        have been explicitly set to output an earlier JT version then no compression will
//                        occur.
//                        If 0 then no compression of PMI Section Groups will occur.
//                        The equivalent environment variable is:
//                           JTK_PMI_SECTION_GROUP_COMPRESSION_ENABLED.
//                        The allowed values of this environment variable are:<br />
//                           1 - PMI Section Group compression is enabled. (default)<br />
//                           0 - PMI Section Group compression is disabled .<br />
//                        Any value other than the supported values will result in the default behaviour.
//                     JtkXT_BREP_CLEAN_ENABLED -- Whether geometry "healing" is
//                        performed on XT parts before they are finalized for output
//                        to JT files where 0 means false and 1 (the default) means
//                        true.<br />
//                        The equivalent environment variable is
//                        JTK_XTBREP_CLEANING_OFF.
//                     JtkXT_BREP_AUTO_CONVERT_OPTION -- Specifies the bit vector of
//                        control options for JT B-rep-to-XT B-rep conversion. The
//                        default value is 0x11C75.<br />
//                        The equivalent environment variable is
//                        JTK_AUTO_XT_CONVERT_OPTION.
//                     JtkXT_BREP_AUTO_CONV_SEW_LEGACY_ENABLED -- Whether the
//                        JtkXTSurface::getNurbsRepresentation and
//                        JtkXTCurve::getNurbsRepresentation methods split periodic
//                        faces and ring edges.<br />
//                        The equivalent environment variable is
//                        JTKXT_SPLIT_PERIODIC_FACES_AND_EDGES.
//                     JtkXT_SPLIT_PERIODICS -- Whether the JtkXTSurface::getNurbsRepresentation
//                        and JtkXTCurve::getNurbsRepresentation methods split periodic faces
//                        and ring edges. Where 0 (the default) means false and 1 means true.<br />
//                        The equivalent environment variable is
//                        JTKXT_SPLIT_PERIODIC_FACES_AND_EDGES.
//                     JtkXT_IGNORE_UNSUPPORTED_GEOM -- Whether the JT Open
//                        Toolkit ignores unexpected geometry where 0 (the default)
//                        means false and 1 means true.<br />
//                        The equivalent environment variable is
//                        JTK_IGNORE_UNSUPPORTED_XT_GEOM.
//                     JtkXT_FILTER_ATTRIBUTES -- If 0, no attribute filtering is applied.
//                        If 1, attribute filtering is applied during both import and
//                        export. If 2, attribute filtering is applied during export
//                        only. If 3, attribute filtering is applied during import only.<br />
//                        The equivalent environment variable is
//                        JTK_IGNORE_XT_ENTITY_ID_ATTRIB which has the following allowed
//                        values:<br />
//                           JTK_IGNORE_XT_ENTITY_ID_ATTRIB -        1.<br />
//                           JTK_IGNORE_XT_ENTITY_ID_ATTRIB=EXPORT - 2.<br />
//                           JTK_IGNORE_XT_ENTITY_ID_ATTRIB=IMPORT - 3.<br />
//                     JtkXT_MAKE_MANIFOLD -- Whether to make an XT body manifold if it is
//                        non-manifold. Where 0 (the default) means false and 1 means true.<br />
//                        The equivalent environment variable is
//                        JTKXT_MAKE_MANIFOLD.
//
//                        Note: This option is not supported for facet based XT bodies, and if
//                        enabled it will be ignored.
//                     JtkXT_ATTEMPT_REPAIR -- Whether to use a larger tolerance for repairing
//                        XT edges than the global cleaning tolerance. Where 0 (the default)
//                        means false and 1 means true.<br />
//                        The equivalent environment variable is
//                        JTKXT_ATTEMPT_REPAIR
//                     JtkXT_AGGRESSIVE_MEMORY_CLEANUP -- If 1 the JtTk will tidy up
//                        the underlying storage used with JtkXTEntities when the number of them
//                        in memory is reduced to 0. Default for this option is 0.<br />
//                        The equivalent environment variable is
//                        JTK_XT_AGGRESSIVE_MEMORY_CLEANUP.
//                     JtkXT_AUTO_POPULATE_FACE_COLOR -- If 1, any JtkMaterial
//                        set on a JtkXTFace will result in corresponding XT color
//                        information being added to the resultant "raw" XT
//                        B-rep in the JT file. The default is 0 (false).<br />
//                        The equivalent environment variable is
//                        JTK_XT_AUTO_POPULATE_FACE_COLOR.
//                     JtkXT_BREP_BODY_FILTER -- This XT filter-in switch will block any XT body
//                        type which is not specified in this option. The option consists of a list
//                        of body types which the user wants to use and blocking occurs when trying
//                        to add/set XTbodies (JtkXTBodies or XT pass through body) to a JtkPart. The
//                        option is represented by the logical combination of the allowed types which
//                        are represented through the
//                        following enum values:<br />
//                          JtkXT_BODY_FILTER_ACORN<br />
//                          JtkXT_BODY_FILTER_GENERAL<br />
//                          JtkXT_BODY_FILTER_MINIMUM<br />
//                          JtkXT_BODY_FILTER_SHEET<br />
//                          JtkXT_BODY_FILTER_SOLID<br />
//                          JtkXT_BODY_FILTER_WIRE<br />
//                        The default value is solid and sheet, meaning that only solid
//                        and sheet XT body types can be added to a JtkPart.<br />
//                        The equivalent environment variable is
//                        JTK_XTBREP_BODY_FILTER which is specified as a string separated
//                        by commas, the recognised values are: Solid,Sheet,Acorn,Minimum,General,Wire.
//                     JtkXT_BREP_PREPARE_BEHAVIOR -- Provides control over the behavior of the
//                        toolkit when finalizing XT parts for output to JT files. It has the
//                        following allowed values:<br />
//                               1 - Version 1 (original) XT finalize behavior will be used.
//                                 Any general bodies will be prepared in such a way as to create
//                                 individual sheet bodies for each face of the body.<br />
//                               2 - Version 2 XT finalize behavior will be used. General bodies will be
//                                 prepared in such a way as to create as many manifold bodies as possible.<br />
//                               3 - Version 3 XT finalize behavior will be used (default). The behavior for this
//                                 option is cumulative to that for version 2. In cases where multiple XT bodies are
//                                 generated from a single JtkXTBody the bodies will be ordered as sets of disjoint
//                                 bodies dependent on the body type (solid, sheet or any other type).<br />
//                        The equivalent environment variable is JTK_XTBREP_PREPARE_BEHAVIOR.
//                        The allowed values of this environment variable are:<br />
//                            1 - JTK_XTBREP_PREPARE_BEHAVIOR is set to version 1 behavior.<br />
//                            2 - JTK_XTBREP_PREPARE_BEHAVIOR is set to version 2 behavior.<br />
//                            3 - JTK_XTBREP_PREPARE_BEHAVIOR is set to version 3 behavior (default).<br />
//                        Any value other than the supported values will result in the default behavior.
//
//                        Note: This option is not supported for facet based XT bodies, and if 
//                        enabled it will be ignored.
//                     JtkXT_BREP_TESS_LENGTH_BEHAVIOR -- Whether XT tessellation
//                        takes the "Length" tessellation parameter into account.
//                        0 (the default) means the legacy XT tessellation behavior,
//                        which ignores "Length".  1 means the new XT
//                        tessellation behavior, which applies "Length".<br />
//                        The equivalent environment variable is
//                        JTK_XTBREP_TESS_LENGTH_BEHAVIOR.
//                     JtkLAYER_FILTERS -- Controls whether specific layer
//                        filters should be applied during the import operation. By
//                        default this is NULL and no layer filters will be applied.
//                        If this is non-NULL then it contains a list of layer filters
//                        to be applied. The format is as follows:<br />
//                           &lt;LayerFilter1&gt;,&lt;LayerFilter2&gt;,&lt;LayerFilter...&gt;,&lt;LayerFilterN&gt;<br />
//                        For example:<br />
//                           "DMU,MYF" (where "DMU" and "MYF" are Layer Filters)<br />
//                        A special value of "DEFAULT" can be used to indicate that the
//                        default layer filter defined in the JT file should be used.<br />
//                        The equivalent environment variable is
//                        JTK_LAYER_FILTERS
//                     JtkREFSET_MANAGER_ENABLE -- If 1 (the default),
//                        JtkReferenceSetManager is operational and will be used by
//                        the toolkit for all reference set related functionality. Otherwise,
//                        reference set information is not abstracted by the toolkit, and the user
//                        is left to deal with reference sets as a semantic guideline that utilizes
//                        JtkProperty.</br>
//                        The equivalent environment variable is
//                        JTK_REFSET_MANAGER_DISABLE.
//                     JtkMEMORY_PROFILE_ENABLED -- Whether memory usage will be
//                        printed at key locations within the toolkit's processing
//                        where 0 (the default) means false and 1 means true.<br />
//                        The equivalent environment variable is
//                        JTK_MEMORY_PROFILE_ENABLED.
//                     JtkENTITY_LEAK_REPORT_ENABLED -- Whether a report of
//                        undeleted JtkEntity objects will be printed by
//                        JtkEntityFactory::fini where 0 (the default) means false
//                        and 1 means true.<br />
//                        The equivalent environment variable is
//                        JTK_ENTITY_LEAK_INFO.
//                     JtkPOST_EXPORT_EXE -- Specifies a command to run on every
//                        written (root) JT file.<br />
//                        The equivalent environment variable is
//                        JTK_POST_TRANS_SCRIPT.
//                     JtkTRANSLATION_DATE_BEHAVIOR -- If 1 (the default), JtkUnitHierarchy::getTranslationDate
//                         is active and any imported TRANSLATION_DATE property will only be accessible through
//                         that interface. Otherwise, access to TRANSLATION_DATE will be available through
//                         the JtkProperty interface per the legacy behavior. getTranslationDate usage is
//                         recommended for increased compatability with UTC date functionality.<br />
//                         The equivalent enviornment varaible is
//                         JTK_TRANSLATION_DATE_BEHAVIOR.
//                     JtkCAE_MANAGER_ENABLE -- If 1 (the default),
//                        JtkCaeManager is operational and will be used by the
//                        toolkit for all JT v10.0 CAE-related functionality.<br/>
//                     JtkBREP_BBOX_DIAG_EXACT -- If 1 (the default), the bounding
//                        box diagonal of JT B-rep geometry will be calculated using
//                        the Pythagorean theorem. Otherwise, a legacy weighted
//                        average heuristic will be used.<br />
//                        The equivalent environment variable is
//                        JTK_BREP_BBOX_DIAG_LEGACY.
//                     JtkBREP_BBOX_EXACT -- Control to recalculate the bounding
//                        box for a B-rep using its control points. The default is 1
//                        (true).<br />
//                        The equivalent environment variable is
//                        JTK_BREP_BBOX_LEGACY.
//                     JtkBREP_FORCE_ENSURE -- Control to force JtBrep regions to
//                        be converted to JtkBrep regions. The default is 0 (false).<br />
//                        The equivalent environment variable is
//                        JTK_BREP_FORCE_ENSURE.
//                     JtkBREP_BBOX_WIRE_EXACT -- If 1 (the default), the bounding
//                        box of wireframe curve geometry will be calculated using all
//                        control points.  Otherwise, a legacy heuristic using a subset
//                        of control points will be used.<br />
//                        The equivalent environment variable is
//                        JTK_BREP_BBOX_WIRE_LEGACY.
//                     JtkULP_TESS_N_THREADS -- Specifies the maximum number of
//                        threads allowed for multi-threaded ULP tessellation. A
//                        value of 0 implies that the CPU supported default number
//                        of threads will be allowed.<br />
//                        The equivalent environment variable is
//                        JTK_ULP_TESS_N_THREADS.
//                     JtkMAX_TASK_THREADS -- Specifies the maximum number of
//                        threads allowed for multi-threading within the current
//                        toolkit process. This number can be set using the
//                        JtkEnvironment:setMaxTaskThreads API, or via the
//                        JTK_NUM_MAX_THREADS environment variable.
//                     JtkCAD_PROPERTIES_ENABLED-- this option is deprecated and will be removed from the toolkit.
//                     JtkUSE_ALT_EXPORT -- If 1, the CADExporter will clean up nodes based on node occurence
//                        counts. These counts are populated by a traverser that steps completely into instances.
//                        The default value is false(0).<br />
//                        The equivalent environment variable is
//                        JTK_USE_ALT_EXPORT.
//                     JtkEXPORT_ISO_UNIT_LABELS -- If true(1), the CADExporter
//                        will create unit labels within JT per the ISO standard
//                        (ISO 14306:2012). Note, prior toolkit versions did not
//                        produce ISO-compliant unit labels, so legacy JT
//                        consumers may need update to recognize them properly.
//                        The default value is true(1).<br />
//                        The equivalent environment variable is
//                        JTK_EXPORT_ISO_UNIT_LABELS.
//                     JtkEXPORT_ISO_AUTO_JT_VERSION -- If true(1), using the
//                        JtkCADExporter's JtkJT_VERSION_AUTO option or "AUTO"
//                        for JtFileFormat in a config file will minimally
//                        produce v9.5 JT files. This is the JT version
//                        described by the ISO standard (ISO 14306:2012).
//                        Prior toolkit versions would minimally create
//                        v8.0 JT files.  The default value is true(1).<br />
//                        The equivalent environment variable is
//                        JTK_EXPORT_ISO_AUTO_JT_VERSION.
//                     JtkIS_COMPONENT_ENABLED -- If 1 then the JtkUnitHierarchy::isComponent API
//                        is active and all SUBNODE properties will *only* be accessible through this interface.
//                        Otherwise SUBNODE properties will not be abstracted by the toolkit and will continue
//                        to be available through the JtkProperty interface.
//                        The equivalent environment variable is:
//                           JTK_IS_COMPONENT_ENABLED.
//                        The allowed values of this environment variable are:<br />
//                           1 - isComponent API is enabled (default).<br />
//                           0 - isComponent API disabled .<br />
//                        Any value other than the supported values will result in the default behaviour.
//                     JtkNAME_PROPERTY_ENABLED -- If 1 the creation of JtkPart and JtkAssembly objects
//                           will result in a "Name" property being created.
//                        The equivalent environment variable is:
//                           JTK_NAME_PROPERTY_ENABLED.
//                        The allowed values of this environment variable are:<br />
//                           1 - Name property creation is enabled.<br />
//                           0 - Name property creation is disabled. (default)<br />
//                        Any value other than the supported values will result in the default behaviour.
//                     JtkXT_BREP_TESS_PREFER_XT_COLOR  -- If 1, then XT Brep tessellation
//                        will apply XT-defined color to shapes wherever both XT color and
//                        JtkMaterial exist.  Otherwise, JtkMaterial will be applied in this scenario.
//                        The equivalent environment variable is:
//                           JTK_XTBREP_TESS_PREFER_XT_COLOR.
//                        The allowed values of this environment variable are:<br />
//                           1 - Where both XT color and JtkMaterial exist, XT tessellation will apply XT color to generated shapes. (default)<br />
//                           0 - Where both XT color and JtkMaterial exist, XT tessellation will apply JtkMaterial to generated shapes.<br /
//                        Any value other than the supported values will result in the default behaviour.
//
// Includes       : JtkStandard.h
//
// Inheritance    : JtkEnvironment
//
// Visibility     : public
//
/////////%}
class JTK_TOOLKIT_API JtkEnvironment
{
public:

   // Valid JtkXT_BREP_BODY_FILTER values
   enum XTBodyFilterType
   {
      // These are the XT body types options for the new filter in switch.
      // The JtTk will only allow XT body types specified in this filter to
      // be attached to JtkParts
      JtkXT_BODY_NULL_OPTION = 0x00000000,      // 00000000
      JtkXT_BODY_FILTER_ACORN  = 0x00000001,    // 00000001
      JtkXT_BODY_FILTER_GENERAL = 0x00000002,   // 00000010
      JtkXT_BODY_FILTER_MINIMUM = 0x00000004,   // 00000100
      JtkXT_BODY_FILTER_SHEET = 0x00000008,     // 00001000
      JtkXT_BODY_FILTER_SOLID = 0x00000010,     // 00010000
      JtkXT_BODY_FILTER_WIRE = 0x00000020       // 00100000
   };

   enum Options
   {
      // PMI Controls
      JtkPMI_SEMANTIC_MAPPING_FEATURES,
      JtkPMI_SECTION_GROUP_COMPRESSION_ENABLED,

      // XT Brep controls
      JtkXT_BREP_CLEAN_ENABLED,
      JtkXT_BREP_AUTO_CONVERT_OPTION,
      JtkXT_BREP_AUTO_CONV_SEW_LEGACY_ENABLED,
      JtkXT_SPLIT_PERIODICS,
      JtkXT_IGNORE_UNSUPPORTED_GEOM,
      JtkXT_FILTER_ATTRIBUTES,
      JtkXT_MAKE_MANIFOLD,
      JtkXT_ATTEMPT_REPAIR,
      JtkXT_AGGRESSIVE_MEMORY_CLEANUP,
      JtkXT_AUTO_POPULATE_FACE_COLOR,
      JtkXT_BREP_BODY_FILTER,
      JtkXT_BREP_PREPARE_BEHAVIOR,
      JtkXT_BREP_TESS_LENGTH_BEHAVIOR,
      JtkXT_BREP_TESS_PREFER_XT_COLOR,

      // Layers control
      JtkLAYER_FILTERS,

      // Refset control
      JtkREFSET_MANAGER_ENABLE,

      // Memory debug controls
      JtkMEMORY_PROFILE_ENABLED,
      JtkENTITY_LEAK_REPORT_ENABLED,

      // Misc. controls
      JtkPOST_EXPORT_EXE,
      JtkTRANSLATION_DATE_BEHAVIOR,

      //JT v10.0 CAE functionality control
      JtkCAE_MANAGER_ENABLE,

      // Brep controls
      JtkBREP_BBOX_DIAG_EXACT,
      JtkBREP_BBOX_EXACT,
      JtkBREP_FORCE_ENSURE,
      JtkBREP_BBOX_WIRE_EXACT,

      // ULP controls
      JtkULP_TESS_N_THREADS,

      // Max threads controls
      JtkMAX_TASK_THREADS,

      // CAD property support
      JtkCAD_PROPERTIES_ENABLED,

      // Alternate node cleanup on export based on occurence counts
      JtkUSE_ALT_EXPORT,

      // ISO compliance behavior changes
      JtkEXPORT_ISO_UNIT_LABELS,
      JtkEXPORT_ISO_AUTO_JT_VERSION,

     // Auto Export Preference
     // NOTE: This is provided to support legacy applications only where necessary while they transition
     // to the new behaviour, and will be removed in a later version of the toolkit
     JtkEXPORT_AUTO_BEHAVIOR,

      // isComponent support
      JtkIS_COMPONENT_ENABLED,

      // Name Property
      JtkNAME_PROPERTY_ENABLED
   };

   // access functions
   static int getOption( Options option, int& val );
   static int setOption( Options option, int val );
   static int testOption( Options option, int val );

   static int getOption( Options option, JtkString& val );
   static int setOption( Options option, const JtkString& val );
   static int testOption( Options option, const JtkString& val );

   // print environment function
   static void print( ostream &os );
};

#endif

