////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_EXPORTER_H
#define JTK_EXPORTER_H

#include <JtTk/JtkStandard.h>
#include <JtTk/JtkEntity.h>

class JtkAssembly;
class JtkEntityList;
class JtkHierarchy;
class JtkPart;
class JtkProperty;
class JtkString;
class JtkTessParams;

///////%{
//
// Class          : JtkCADExporter
//
// Description    : Class for exporting in JT files
//
// Enums          : Response
//                     JtkABORT -- Callback response indicating that the
//                        current exportJT() invocation is to be aborted.
//                     JtkSKIP -- Callback response indicating that the
//                        current part is to be skipped.
//                     JtkCONTINUE -- Callback response indicating "OK".
//
//                  Options
//                     JtkNULL_OPTION -- Unknown or NULL specification.
//                     JtkASSEMBLY_ONLY -- JtkEXPORT_TARGET_TYPE option
//                        limiting JT file output to those JT files containing
//                        solely JtkAssembly product structure nodes.
//                     JtkPARTS_ONLY -- JtkEXPORT_TARGET_TYPE option
//                        limiting JT file output to those JT files containing
//                        solely JtkPart product structure nodes.
//                     JtkASSEMBLY_AND_PARTS -- JtkEXPORT_TARGET_TYPE option
//                        allowing JT file output of all product structure.
//                     JtkPER_PART -- JtkEXPORT_FILE_FORMAT option specifying
//                        output of one JT file containing all JtkAssembly
//                        hierarchy and a directory containing one JT file per
//                        JtkPart.
//                     JtkFULL_SHATTER -- JtkEXPORT_FILE_FORMAT option
//                        specifying output of each product structure node in
//                        individual JT files.
//                     JtkMONOLITHIC -- JtkEXPORT_FILE_FORMAT option specifying
//                        output of the entire model in one JT file.
//                     JtkCUSTOM -- JtkEXPORT_FILE_FORMAT option specifying JT
//                        output based on use of JtkHierarchy::setJtFilename().
//                        Setting JtkCUSTOM causes the export to use the path
//                        set by JtkHierarchy::setJtFilename verbatim, bypassing
//                        any mapping of characters, like the directory
//                        separators '/' and '\', between operating systems.
//                     JtkTESS_ONLY -- JtkEXPORT_GEOMETRY_TYPE option limiting
//                        saved geometry to non-precise data.
//                     JtkBREP_ONLY -- JtkEXPORT_GEOMETRY_TYPE option limiting
//                        saved geometry to precise data where available.
//                        I.e., no tessellation is performed.
//                     JtkTESS_AND_BREP -- JtkEXPORT_GEOMETRY_TYPE option
//                        specifying all geometry is to be saved.
//                     JtkJT_VERSION_64 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 6.4 JT file format,
//                        which is uncompressed.
//                        Note: Support for authoring 6.4 files has been removed,
//                        this API will remain in place for compile compatiblity (for a limited time)
//                        but will result in a 8.0 format JT file instead.
//                     JtkJT_VERSION_70 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 7.0 JT file format,
//                        which is compressed using dictionary (zlib-like)
//                        lossless compression techniques.
//                        Note: Support for authoring 7.0 files has been removed,
//                        this API will remain in place for compile compatiblity (for a limited time)
//                        but will result in a 8.0 format JT file instead.
//                     JtkJT_VERSION_80 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 8.0 JT file format,
//                        which is compressed using lossless or lossy
//                        domain-specific compression techniques.
//                     JtkJT_VERSION_81 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 8.1 JT file format.
//                     JtkJT_VERSION_82 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 8.2 JT file format.
//                     JtkJT_VERSION_90 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 9.0 JT file format.
//                     JtkJT_VERSION_91 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 9.1 JT file format.
//                     JtkJT_VERSION_92 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 9.2 JT file format.
//                     JtkJT_VERSION_93 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 9.3 JT file format.
//                     JtkJT_VERSION_94 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 9.4 JT file format.
//                     JtkJT_VERSION_95 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 9.5 JT file format.
//                     JtkJT_VERSION_100 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 10.0 JT file format.
//                     JtkJT_VERSION_101 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 10.1 JT file format.
//                     JtkJT_VERSION_102 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 10.2 JT file format.
//                     JtkJT_VERSION_103 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 10.3 JT file format.
//                     JtkJT_VERSION_104 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 10.4 JT file format.
//                     JtkJT_VERSION_105 -- JtkEXPORT_COMPRESSION option
//                        selecting output in version 10.5 JT file format.
//                     JtkJT_VERSION_AUTO -- JtkEXPORT_COMPRESSION option
//                        automaticlly decide the most compatible JT file format,
//                        the default will be version 80.
//                     JtkSINGLE -- JtkEXPORT_PRECISION option selecting
//                        geometry storage in 32-bit floating point format.
//                     JtkDOUBLE -- JtkEXPORT_PRECISION option selecting
//                        geometry storage in 64-bit floating point format.
//                     JtkALL -- JtkEXPORT_JT_OVERWRITE option selecting
//                        overwrite of any existing JT files.
//                     JtkUPDATE -- JtkEXPORT_JT_OVERWRITE option selecting
//                        update only of any existing JT files.
//                     JtkRELATIVE -- JtkEXPORT_CHORDAL_TYPE option selecting
//                        chordal interpretation as a fraction of each
//                        JtkPart's bounding box diagonal.
//                     JtkABSOLUTE -- JtkEXPORT_CHORDAL_TYPE option Chordal
//                        specified is global
//                     JtkPER_LOD -- JtkEXPORT_CHORDAL_TYPE option.
//                          ChordalType is specified per lod via the 
//                          JtkTessParams::JtkTESSELLATION_RELATIVE_CHORDAL setting
//                     JtkSEAM_SEWING_OFF -- JtkEXPORT_SEAM_SEWING option
//                     JtkSEAM_SEWING_ON -- JtkEXPORT_SEAM_SEWING option
//                     JtkRETRISTRIP_OFF -- JtkEXPORT_RETRISTRIPPING option
//                     JtkRETRISTRIP_ON -- JtkEXPORT_RETRISTRIPPING option
//                     JtkAUTO_REDUCE_OFF -- JtkEXPORT_AUTO_REDUCE option
//                     JtkAUTO_REDUCE_ON -- JtkEXPORT_AUTO_REDUCE option
//                     JtkAJT_WRITE_OFF -- JtkEXPORT_AJT_WRITE option
//                     JtkAJT_WRITE_ON -- JtkEXPORT_AJT_WRITE option
//                     JtkCLEANSE_FILENAMES_OFF -- JtkEXPORT_CLEANSE_FILENAMES
//                        option
//                     JtkCLEANSE_FILENAMES_ON -- JtkEXPORT_CLEANSE_FILENAMES
//                        option
//                     JtkPART_SIMPLIFY_OFF -- JtkEXPORT_PART_SIMPLIFY option
//                     JtkPART_SIMPLIFY_ON -- JtkEXPORT_PART_SIMPLIFY option
//                     JtkSMART_LODS_OFF -- JtkEXPORT_SMART_LODS option
//                     JtkSMART_LODS_ON -- JtkEXPORT_SMART_LODS option
//                     JtkAUTO_LOW_LODS_OFF -- JtkEXPORT_AUTO_LOW_LODS option
//                     JtkAUTO_LOW_LODS_ON -- JtkEXPORT_AUTO_LOW_LODS option
//                     JtkDEGEN_OUTPUT_SKIP_OFF -- JtkEXPORT_DEGEN_OUTPUT_SKIP
//                        option
//                     JtkDEGEN_OUTPUT_SKIP_ON -- JtkEXPORT_DEGEN_OUTPUT_SKIP
//                        option
//                     JtkDELETE_OFF -- JtkEXPORT_DELETE option
//                     JtkDELETE_ON -- JtkEXPORT_DELETE option
//                     JtkPART_MONITOR_OFF -- JtkEXPORT_PART_MONITOR option
//                     JtkPART_MONITOR_ON -- JtkEXPORT_PART_MONITOR option
//                     JtkTESS_PER_REGION_OFF -- JtkEXPORT_TESS_PER_REGION option
//                     JtkTESS_PER_REGION_ON -- JtkEXPORT_TESS_PER_REGION option
//                     JtkAUTO_XTBREP_OFF -- JtkEXPORT_XTBREP option
//                     JtkAUTO_XTBREP_ON -- JtkEXPORT_XTBREP option
//                     JtkINCLUDE_ULP_ON -- JtkINCLUDE_ULP option
//                     JtkINCLUDE_ULP_OFF -- JtkINCLUDE_ULP option
//                     JtkINCLUDE_ULP_PASSTHROUGH -- JtkINCLUDE_ULP option
//                     JtkGEOM_SHARING_OFF -- JtkEXPORT_XT_GEOM_SHARING option
//                        specifying that no geometry sharing should be done.
//                     JtkGEOM_SHARING_ALL -- JtkEXPORT_XT_GEOM_SHARING option
//                        specifying that geometry sharing should be done for all parts.
//                     JtkGEOM_SHARING_CUSTOM -- JtkEXPORT_XT_GEOM_SHARING option
//                        specifying that geometry sharing should be done as indicated by the 
//                        groups within the JtkXTSharingManager.
//                     JtkGEOM_SHARING_PASSTHROUGH-- JtkEXPORT_XT_GEOM_SHARING option
//                        specifying that geometry sharing should be passed through.
//                     JtkDEGEN_LOD_OUTPUT_SKIP_OFF -- JtkEXPORT_DEGEN_LOD_OUTPUT_SKIP
//                        option. Specifies that degenerate LODs (those that contain no
//                        shapes) should be output.
//                     JtkDEGEN_LOD_OUTPUT_SKIP_ON -- JtkEXPORT_DEGEN_LOD_OUTPUT_SKIP
//                        option. Specifies that degenerate LODs (those that contain no
//                        shapes) should be not be output.
//                     JtkGENERATE_STT_ON -- JtkEXPORT_GENERATE_STT option. Specifies that STT
//                        generation should be enabled.
//                     JtkGENERATE_STT_OFF -- JtkEXPORT_GENERATE_STT option. Specifies that STT
//                        generation *is not* enabled.
//                     JtkGENERATE_STT_REGENERATE -- JtkEXPORT_GENERATE_STT option. Specifies that
//                        any existing STT data should be regenerated on export.
//
//                  OptionsMask
//                     JtkEXPORT_NULL -- Unknown or NULL option type.
//                     JtkEXPORT_TARGET_TYPE -- Option type related to output
//                        file filtering by product structure contents.
//                     JtkEXPORT_FILE_FORMAT -- Option type related to the
//                        mapping of product structure to JT file structure.
//                     JtkEXPORT_GEOMETRY_TYPE -- Option type related to choice
//                        of geometry to persist in output files.
//                     JtkEXPORT_COMPRESSION -- Option type related to choice
//                        of JT file version to output.
//                     JtkEXPORT_PRECISION -- Option type related to choice of
//                        floating point precision to use for persisted
//                        geometry.
//                     JtkEXPORT_JT_OVERWRITE -- Option type related to choice
//                        of update versus full overwrite of output files.
//                     JtkEXPORT_CHORDAL_TYPE -- Option type related to chordal
//                        tessellation parameter interpretation.
//                     JtkEXPORT_SEAM_SEWING -- Option type for on/off of seam
//                        sewing feature.
//                     JtkEXPORT_RETRISTRIPPING -- Option type for on/off of
//                        retristripping feature.
//                     JtkEXPORT_AUTO_REDUCE -- Option type for on/off of
//                        auto-reduce feature.
//                     JtkEXPORT_AJT_WRITE -- Option type for on/off of
//                        AJT assembly output feature.
//                     JtkEXPORT_CLEANSE_FILENAMES -- Option type for on/off
//                        of filename auto-cleansing feature.
//                     JtkEXPORT_PART_SIMPLIFY -- Option type for on/off of
//                        LOD simplification feature.
//                     JtkEXPORT_SMART_LODS -- Option type for on/off of
//                        automatic LOD generation feature.
//                     JtkEXPORT_AUTO_LOW_LODS -- Option type for on/off of
//                        automatic simple LOD generation feature.
//                     JtkEXPORT_DEGEN_OUTPUT_SKIP -- Option type for on/off
//                        of degenerate output pruning feature.
//                     JtkEXPORT_DELETE -- Option type for on/off of delete
//                        unused part feature.  (Deprecated)
//                     JtkEXPORT_PART_MONITOR -- Option type for on/off of
//                        part monitor feature.  (Deprecated)
//                     JtkEXPORT_TESS_PER_REGION -- Option type for on/off of
//                        tessellation per brep region feature.
//                     JtkEXPORT_AUTO_XTBREP -- Option type for on/off of
//                        automatic convertion of JT brep to XT brep.
//                     JtkEXPORT_INCLUDE_ULP --- Option type for
//                        inclusion of ULP data for trimmed B-rep.
//                     JtkEXPORT_XT_GEOM_SHARING --- Option type for
//                        XT geometry sharing
//                     JtkEXPORT_DEGEN_LOD_OUTPUT_SKIP -- Option type for on/off
//                        of degenerate LOD output pruning feature.
//                     JtkEXPORT_GENERATE_STT -- Option type for STT generation.
//
//                  statusType
//                     JtkPART_STATUS --
//                     JtkLOD_STATUS --
//                     JtkFACE_STATUS --
//                     JtkTEXT_STATUS --
//
//                  LODParamOption
//                     JtkADV_COMPRESS_LEVEL --
//                     JtkTESSELLATION_CHORDAL --
//                     JtkTESSELLATION_ANGULAR --
//                     JtkTESSELLATION_LENGTH --
//                     JtkTESSELLATION_MAX_ASPECT --
//                     JtkTESSELLATION_MIN_ANGLE --
//                     JtkSIMPLIFIER_FRACTION --
//                     JtkBREP_HOLE_REMOVAL_FRACTION --
//                     JtkTESSELLATION_LODLABEL --
//                     JtkULP --
//
// Includes       : JtkCADExporter.h
//
// Inheritance    : JtkRefCounted > JtkCADExporter
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCADExporter : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkCADExporter )

public:
   // Export callback prototype.
   enum Response
   {
      JtkABORT    = 0, // Abort the export process completely.
      JtkSKIP,         // Don't export current part and go to next.
      JtkCONTINUE
   };

   // JT write options that can be set using setExportOption( ).
   enum Options
   {
      // JtkEXPORT_NULL
      JtkNULL_OPTION,

      // JtkEXPORT_TARGET_TYPE
      JtkASSEMBLY_ONLY,
      JtkPARTS_ONLY,
      JtkASSEMBLY_AND_PARTS,

      // JtkEXPORT_FILE_FORMAT
      JtkPER_PART,      // asm JT file + parts dir w/ JT files
      JtkUG_SHATTER,    // each asm node == JT file
      JtkFULL_SHATTER,  // each node == JT file
      JtkMONOLITHIC,    // Entire assembly in one file.
      JtkCUSTOM,        // client PS -> JT file mapping

      // JtkEXPORT_GEOMETRY_TYPE
      JtkTESS_ONLY,     // Save tessellated data only
      JtkBREP_ONLY,     // Save brep data only
      JtkTESS_AND_BREP, // Save both tessellated & brep data

      // JtkEXPORT_COMPRESSION
      JtkJT_VERSION_64,          // Uncompressed JT (deprecated/removed)
      JtkJT_VERSION_70,          // Standard compressed JT (deprecated/removed)
      JtkJT_VERSION_80,          // Advanced compressed JT
      JtkJT_VERSION_AUTO,        // Auto version control
      JtkJT_VERSION_81,          // Jt 81 format
      JtkJT_VERSION_82,          // Jt 82 format
      JtkJT_VERSION_83,          // Jt 83 format (deprecated/removed)
      JtkJT_VERSION_90,          // Jt 90 format
      JtkJT_VERSION_91,          // Jt 91 format
      JtkJT_VERSION_92,          // Jt 92 format
      JtkJT_VERSION_93,          // Jt 93 format
      JtkJT_VERSION_94,          // Jt 94 format
      JtkJT_VERSION_95,          // Jt 95 format
      JtkJT_VERSION_100,         // Jt 10 format
      JtkJT_VERSION_101,         // Jt 101 format
      JtkJT_VERSION_102,         // Jt 102 format
      JtkJT_VERSION_103,         // Jt 103 format
      JtkJT_VERSION_104,         // Jt 104 format
      JtkJT_VERSION_105,         // Jt 105 format
		
      // JtkEXPORT_PRECISION
      JtkSINGLE, // Store "floats"
      JtkDOUBLE, // Store "doubles"

      // JtkEXPORT_JT_OVERWRITE
      JtkALL,     // Rewrite all existing JT files
      JtkUPDATE,  // Rewrite only changed JT files

      // JtkEXPORT_CHORDAL_TYPE
      JtkRELATIVE, // Chordal specified is dynamic and equals fraction of part's bbox diag
      JtkABSOLUTE, // Chordal specified is global
      JtkPER_LOD,  // ChordalType is specified per lod via the JtkTessParams::JtkTESSELLATION_RELATIVE_CHORDAL setting

      // JtkEXPORT_SEAM_SEWING
      JtkSEAM_SEWING_OFF,
      JtkSEAM_SEWING_ON,

      // JtkEXPORT_RETRISTRIPPING
      JtkRETRISTRIP_OFF,
      JtkRETRISTRIP_ON,

      // JtkEXPORT_AUTO_REDUCE
      JtkAUTO_REDUCE_OFF,
      JtkAUTO_REDUCE_ON,

      // JtkEXPORT_AJT_WRITE
      JtkAJT_WRITE_OFF,
      JtkAJT_WRITE_ON,

      // JtkEXPORT_CLEANSE_FILENAMES
      JtkCLEANSE_FILENAMES_OFF,
      JtkCLEANSE_FILENAMES_ON,

      // JtkEXPORT_PART_SIMPLIFY
      JtkPART_SIMPLIFY_OFF,
      JtkPART_SIMPLIFY_ON,

      // JtkEXPORT_SMART_LODS
      JtkSMART_LODS_OFF,
      JtkSMART_LODS_ON,

      // JtkEXPORT_AUTO_LOW_LODS
      JtkAUTO_LOW_LODS_OFF,
      JtkAUTO_LOW_LODS_ON,

      // JtkEXPORT_DEGEN_OUTPUT_SKIP
      JtkDEGEN_OUTPUT_SKIP_OFF,
      JtkDEGEN_OUTPUT_SKIP_ON,
      
      // JtkEXPORT_DELETE
      JtkDELETE_OFF,
      JtkDELETE_ON,

      // JtkEXPORT_PART_MONITOR
      JtkPART_MONITOR_OFF,
      JtkPART_MONITOR_ON,

      // JtkEXPORT_TESS_PER_REGION
      JtkTESS_PER_REGION_OFF,
      JtkTESS_PER_REGION_ON,

      // JtkEXPORT_AUTO_XTBREP
      JtkAUTO_XTBREP_OFF,
      JtkAUTO_XTBREP_ON,

      // JtkEXPORT_INCLUDE_ULP
      JtkINCLUDE_ULP_OFF,
      JtkINCLUDE_ULP_ON,
      JtkINCLUDE_ULP_PASSTHROUGH,

      // JtkEXPORT_XT_GEOM_SHARING
      JtkGEOM_SHARING_OFF,
      JtkGEOM_SHARING_ALL,
      JtkGEOM_SHARING_CUSTOM,
      JtkGEOM_SHARING_PASSTHROUGH,

      // JtkEXPORT_DEGEN_LOD_OUTPUT_SKIP
      JtkDEGEN_LOD_OUTPUT_SKIP_OFF,
      JtkDEGEN_LOD_OUTPUT_SKIP_ON,

      // JtkEXPORT_GENERATE_STT
      JtkGENERATE_STT_ON,
      JtkGENERATE_STT_OFF,
      JtkGENERATE_STT_REGENERATE,
   };

   // These are the group names for the above options used to specify which
   // option getExportOption( ) should focus on.
   enum OptionsMask
   {
      JtkEXPORT_NULL,
      JtkEXPORT_TARGET_TYPE,
      JtkEXPORT_FILE_FORMAT,
      JtkEXPORT_GEOMETRY_TYPE,
      JtkEXPORT_COMPRESSION,   // needs to encompass all of the different versions
      JtkEXPORT_PRECISION,
      JtkEXPORT_JT_OVERWRITE,
      JtkEXPORT_CHORDAL_TYPE,
      JtkEXPORT_SEAM_SEWING,
      JtkEXPORT_RETRISTRIPPING,
      JtkEXPORT_AUTO_REDUCE,
      JtkEXPORT_AJT_WRITE,
      JtkEXPORT_CLEANSE_FILENAMES,
      JtkEXPORT_PART_SIMPLIFY,
      JtkEXPORT_SMART_LODS,
      JtkEXPORT_AUTO_LOW_LODS,
      JtkEXPORT_DEGEN_OUTPUT_SKIP,
      JtkEXPORT_DELETE,
      JtkEXPORT_PART_MONITOR,
      JtkEXPORT_TESS_PER_REGION,
      JtkEXPORT_AUTO_XTBREP,
      JtkEXPORT_INCLUDE_ULP,
      JtkEXPORT_XT_GEOM_SHARING,
      JtkEXPORT_DEGEN_LOD_OUTPUT_SKIP,
      JtkEXPORT_GENERATE_STT
   };

   // Set/get options for export
   virtual int setExportOption( Options Option ) = 0;
   virtual int getExportOption( OptionsMask Mask, Options &Option ) = 0;
   virtual int testOption( Options Option ) = 0;

   // XTBrep write callbacks
   typedef unsigned int XTPreWriteCB();
   typedef unsigned int XTPostWriteCB();

   //only export parts that have a later version
   //than in the current assembly file of the same name
   // The prototype for the client-specified part export callback.  The
   // arguments to the callback are:
   //
   //    exporter:  A reference to the calling JtkCADExporter instance.
   //    part:      The current part being exported.
   //    partIndex: The index of this part in the list of all unique parts.
   //    numParts:  The total number of unique parts found in this assembly.
   typedef Response  PartExportCB( JtkCADExporter *exporter,
                                   JtkPart        *part,
                                   int            partIndex,
                                   int            numParts );

   // The prototype for the client-specified misc. export callbacks.  The
   // arguments to the callback are:
   //
   //    exporter:   A reference to the calling JtkCADExporter instance.
   //    entityList: A list of entities of interest to the callback.
   //
   // Misc. export callbacks should return Jtk_ERROR or Jtk_OK as appropriate.
   typedef int       MiscExportCB( JtkCADExporter *exporter,
                                   JtkEntityList  *entityList );


   enum statusType
   {
      JtkPART_STATUS,
      JtkLOD_STATUS,
      JtkFACE_STATUS,
      JtkTEXT_STATUS
   };
   typedef Response StatusCB( void  *clientData,
                              statusType,
                              int itemIndex,
                              int numItems,
                              const JtkString& msg );

   virtual int    setNumLOD( int numLODs ) = 0;
   virtual int    getNumLOD( ) = 0;
   virtual int    getLODParams( int LodIndex, JtkTessParams* &TessParams ) = 0;
   virtual int    getLODParams( JtkEntityPtr<JtkEntityList>& TessParamList ) = 0;
   virtual int    setLODParams( int LodIndex, JtkTessParams* TessParams ) = 0;
   virtual int    setLODParams( JtkEntityList* TessParamList ) = 0;

   // Attempt to sew brep faces together using provided tolerance
   // Default is ON with tolerance = 0.001 (0.1% of bbox diagonal).
   virtual int    setSeamSewingTol( float Tol ) = 0;

   // Turn on/off writing of agressive compression (version 8.0) JT files
   // Default is OFF.
   virtual void   setAdvancedCompressionLevel( float level ) = 0;
   virtual void   getAdvancedCompressionLevel( float &level ) = 0;

   virtual void   addCleanseMacro( const JtkString& Find, const JtkString& Replace ) = 0;

   // set up XTBrep write callbacks
   static void    setXTPreWriteCallback( XTPreWriteCB *cb );
   static void    setXTPostWriteCallback( XTPostWriteCB *cb );

   // Turn on/off part simplification

   // Set a callback method to be called on each unique part found in the
   // assembly hierarchy during the export process.  The callback allows the
   // client to generate geometric/topological information relating to each
   // part in a "just-in-time" manner.  This potentially decreases memory
   // usage considerably during the export process.
   void           setPartExportPreCallback( PartExportCB *cb );
   void           setPartExportPostCallback( PartExportCB *cb );
   void           setJtFileRootNodeCallback( MiscExportCB *cb );
   void           setJtFileWriteCallback( MiscExportCB *cb );
   void           setJtFileSkipCallback( MiscExportCB *cb );
   void           setStatusCallback( StatusCB *cb, void *clientData );

   // Set the directory path for the exported assembly. _path_ specifies an
   // absolute path to an existing directory where the assembly database is
   // to be written.
   virtual int    setExportPath( const JtkString& path ) = 0;

   // Methods to assign and read the setting for the common parts path.
   // The common parts path is a '*' seperated list of directories.
   // Note, this path is only used for the "UPDATE CHANGED" functionality.
   virtual int    setCommonPartsPath( const JtkString& Path ) = 0;
   virtual int    getCommonPartsPath( JtkString&  Path ) = 0;

   // Keeps a persistent record of parts that have crashed us in the past &
   // avoids processing these parts in successive translations.  A record of
   // each failed part is saved in a "failures" directory under the exportPath.
   // If this flag is "on", any parts found in this directory will not be
   // processed during translation. This flag is off by default, and is only
   // meant to work in conjunction with the part export callback.

   // Export the assembly and/or parts
   virtual int    exportJt( JtkHierarchy *RootNode ) = 0;
   virtual int    exportJt( JtkHierarchy *RootNode, JtkEntityList* &Faults ) = 0;
   
   // Export to a memory buffer
   virtual int    exportJt( JtkHierarchy *RootNode, unsigned char*& buff, int& buffLen ) = 0;
   virtual int    exportJt( JtkHierarchy *RootNode, unsigned char*& buff, int& buffLen, JtkEntityList* &Faults ) = 0;

   // ULP options

   // ULP precision to be used during export for automatic ULP generation.
   // Default: 0.001
   virtual int setULPPrecision( float Precision ) = 0;
   virtual int getULPPrecision( float& Precision ) = 0;

   // Adds info segment property for all JT files that are exported
   // Fails if there is an existing key
   // Adds the following info segment properties:
   //   JT_PROP_TRANSLATOR_NAME
   //   JT_PROP_TRANSLATOR_VERSION
   virtual int addInfoSegmentPropTranslator( const JtkString& Name, const JtkString& Version ) = 0;

   // Adds info segment property for all JT files that are exported
   // Fails if there is an existing key
   // Prohibits adding reserved info segment properties with key prefix:
   //   JT_PROP
   virtual int addInfoSegmentProp( JtkProperty* Prop ) = 0;

protected:
   JtkCADExporter();
   virtual        ~JtkCADExporter();

   static XTPreWriteCB   *_xtPreWriteCB;
   static XTPostWriteCB  *_xtPostWriteCB;
   // Client specified part export callback.
   PartExportCB   *_partPreCB;
   PartExportCB   *_partPostCB;
   MiscExportCB   *_jtFileRootNodeCB;
   MiscExportCB   *_jtFileWriteCB;
   MiscExportCB   *_jtFileSkipCB;
   StatusCB       *_statusCB;
   void           *_statusClientData;

private:
};

#endif

