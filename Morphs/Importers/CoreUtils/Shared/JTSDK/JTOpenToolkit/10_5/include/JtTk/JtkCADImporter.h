////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_IMPORTER_H
#define JTK_IMPORTER_H

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkHierarchy.h>

class JtkString;

typedef int propertiesCB( JtkProperty *pProp, JtkHierarchy *pNode );

// XTBrep write callbacks
typedef unsigned int XTPreReadCB();
typedef unsigned int XTPostReadCB();

///////%[
//
// Method         : int JtkImportActionCB( JtkHierarchy* CurrNode, int level, JtkClientData* Info )
//
// Class          : Globals
//
// Description    : A typedef for the callback functions passed to
//                  JtkCADImporter::setupImportPreActionCallback and
//                  JtkCADImporter::setupImportPostActionCallback.
//
// Inputs         : CurrNode -- The current product structure hierarchy node.
//                  level -- The level of the current node in the product structure hierarchy.
//                  Info -- The JtkClientData-derived object passed to JtkCADImporter::import.
//
// Outputs        :
//
// Returns        : The value returned from this callback is currently ignored - recursion will always occur to lower
//                  levels.
//
// Visibility     : public
//
/////////%]
typedef int JtkImportActionCB( JtkHierarchy* CurrNode,
                               int level,
                               JtkClientData* Info );

///////%{
//
// Class          : JtkCADImporter
//
// Description    : Class for reading JT files.
//
// Enums          : Response
//                     JtkABORT -- The JtkCADImporter part or status callback
//                        response indicating that the current exportJT()
//                        invocation is to be aborted.
//                     JtkSKIP -- The JtkCADImporter part or status callback
//                        response indicating that the current part is to be
//                        skipped.
//                     JtkCONTINUE -- The JtkCADImporter part or status
//                        callback response indicating an expected ("Ok")
//                        result.
//
//                  ShapeLoadOption
//                     JtkALL_LODS -- Import all LODs of facet geometry data
//                        when reading a JT file.
//                     JtkHIGH_LOD -- Import only the high LOD of facet
//                        geometry data when reading a JT file.
//                     JtkLOW_LOD -- Import only the lowest LOD of facet
//                        geometry data when reading a JT file.
//                     JtkCUSTOM_LOD -- Import only a specific LOD of facet
//                        geometry data when reading a JT file. The index of the
//                        LOD to load will be provided in a call to setShapeLoadOption.
//
//                  BrepLoadOption
//                     JtkTESS_ONLY -- Import only facet (tessellated) geometry
//                        data for JtkParts when reading a JT file.
//                     JtkBREP_ONLY -- Import only the topological geometry
//                        for JtkParts containing NURBS when reading a JT file.
//                     JtkTESS_XOR_BREP -- Import either the topological or
//                        facet geometry for JtkParts, with a preference for
//                        the topological when reading a JT file.
//                     JtkTESS_AND_BREP -- Import both the topological and
//                        facet geometry for JtkParts when reading a JT file.
//                     JtkNO_GEOM -- Import only product structure.
//
//                  PmiLoadOption
//                     JtkNONE -- Do not import any PMI data when reading a JT
//                        file.
//                     JtkPART_ONLY -- Import only part PMI data when reading a
//                        JT file.
//                     JtkASM_ONLY -- Import only assembly PMI data when reading
//                        a JT file.
//                     JtkPART_AND_ASM -- Import assembly and part PMI data when
//                        reading a JT file.
//
//                  PmiRetristripOption
//                     JtkPMI_RETRISTRIP_OFF -- Default option - data loaded as is from the JT file.
//                     JtkPMI_RETRISTRIP_ON -- when reading the JT file the toolkit will attempt 
//                                        retristrip the filled PMI content. This is the content returned via
//                                        JtkPMIVisualEntity::getVisualPolygonData and JtkPMIPolgyonGlyph::getInternals
//
//                  XTBrepEditOption
//                     JtkXTBREP_FOR_EDIT_OFF -- Default option - not to create
//                        XT bodies from the PS tag
//                     JtkXTBREP_FOR_EDIT_ON -- option to create XT bodies from
//                        the PS tag
//
//                  AssemblyOption
//                     JtkINSTANCE_ASSEMBLY -- Create JtkInstance nodes for
//                        each JtkAssembly instances in a JT file being read.
//                     JtkEXPLODE_ASSEMBLY -- Create a new JtkAssembly for
//                        each instanced JtkAssembly in a JT file being read.
//
//                  PartStorageOption
//                     JtkUSE_PTR_VEC -- Memory option.  Internally use arrays
//                        instead of hash tables within the JtkCADImporter
//                        during a JT read.
//                     JtkUSE_HASH_TABLE -- Memory option.  Internally use hash
//                        tables instead of arrays within the JtkCADImporter
//                        during a JT read.
//
//                  FileImportOption
//                     JtkLOAD_ALL -- Load the file and all referenced
//                        sub-assembly and part files.
//                     JtkLOAD_FIRST -- Load just the first file, which is
//                        typically just the assembly file.
//
//                  UlpLoadOption
//                     JtkULP_LOAD_OFF -- Do not read ULP data.
//                     JtkULP_LOAD_ON -- Read ULP data.
//                     JtkULP_LOAD_TESSELLATE -- Read ULP data and tessellate if
//                        necessary.
//
//                  FeatureLoadOption
//                     JtkFEATURE_OFF -- Do not import feature information
//                     JtkFEATURE_ON -- Do import feature information (default)
//
//                  LateLoadOption
//                     JtkLATE_LOAD_OFF -- Late loading of JT data is not enabled (default).
//                     JtkLATE_LOAD_ON -- Late loading of JT data is enabled.
//
// Includes       : JtkCADImporter.h
//
// Inheritance    : JtkRefCounted > JtkCADImporter
//
// Visibility     : public
//
// Theory         : Read an existing JT file and create an JtkHierarchy for it.
//
/////////%}
class JTK_TOOLKIT_API JtkCADImporter : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkCADImporter )

public:
   // Export callback prototype.
   enum Response
   {
      JtkABORT    = 0, // Abort the import process completely.
      JtkSKIP,         // Don't import current part and go to next.
      JtkCONTINUE
   };

   // Continue the export process normally.
   // Option to load tristrip/linestrip/polygon/point set data from the .jt file
   enum ShapeLoadOption
   {
      JtkALL_LODS = 0, // Retain all LODs from the input
      JtkHIGH_LOD,
      JtkLOW_LOD,
      JtkCUSTOM_LOD
   };

   // Retain only high LOD from the input
   // Option to load BRep/NURBS data from the .jt file
   enum BrepLoadOption
   {
      JtkTESS_ONLY      = 0, // Read only tessellated data
      JtkBREP_ONLY,          // Read only brep data
      JtkTESS_AND_BREP,      // Read both brep and tess data if available
      JtkTESS_XOR_BREP,      // Read brep if available, else read tess data
      JtkNO_GEOM            // Do not read in any tessellated or brep data
   };

   // - Set option to create/not create XT bodies from the PS tag
   // - Client apps set this option if XT bodies are needed for editing
   // - Option not set if only the PS tag from pass-thru API is needed.
   enum XTBrepEditOption
   {
      JtkXTBREP_FOR_EDIT_OFF = 0,
      JtkXTBREP_FOR_EDIT_ON
   };

   // option to instance/explode assemblies
   enum AssemblyOption
   {
      JtkINSTANCE_ASSEMBLY = 0,
      JtkEXPLODE_ASSEMBLY
   };

   // option to load a single/all JT files
   enum FileImportOption
   {
      JtkLOAD_ALL = 0,
      JtkLOAD_FIRST
   };

   // Option that specifies which if any PMI data to load form the .jt file
   enum PmiLoadOption
   {
      JtkNONE          =0, // Do not read any PMI data
      JtkPART_ONLY,        // Read only Part PMI data
      JtkASM_ONLY,         // Read only Asm PMI data
      JtkPART_AND_ASM      // Read Part and Asm PMI data
   };

   // NOTE: this was implemented to fix DE 15455
   // which was causing problems in the hash table
   // used by JtkPartTable.
   enum PartStorageOption
   {
      JtkUSE_PTR_VEC       = 0,
      JtkUSE_HASH_TABLE
   };

   // Controls the loading of ULP data from .jt file
   enum UlpLoadOption
   {
     JtkULP_LOAD_OFF      = 0, // Do not read ULP data
     JtkULP_LOAD_ON,           // Read ULP data
     JtkULP_LOAD_TESSELLATE    // Read ULP data and tessellate if necessary
   };

   // Controls the loading of Feature data for parts from the .jt file
   enum FeatureLoadOption
   {
      JtkFEATURE_OFF  = 0,   // Do not import feature information
      JtkFEATURE_ON          // Do import feature information
   };

   // Controls the late loading of JT data
   enum LateLoadOption
   {
      JtkLATE_LOAD_OFF = 0,  // Late loading is not enabled
      JtkLATE_LOAD_ON
   };

   enum PmiRetristripOption
   {
      JtkPMI_RETRISTRIP_OFF = 0, 
      JtkPMI_RETRISTRIP_ON
   };

   JtkCADImporter();
   virtual ~JtkCADImporter();

   // Set/get options for import
   virtual void               setDeleteDegenAssem( int del ) = 0;
   virtual int                getDeleteDegenAssem() = 0;
   virtual void               setShapeLoadOption( ShapeLoadOption Option, int LOD = 0 ) = 0;
   virtual ShapeLoadOption    shapeLoadOption() = 0;
   virtual ShapeLoadOption    shapeLoadOption( int& LOD ) = 0;
   virtual void               setBrepLoadOption( BrepLoadOption Option ) = 0;
   virtual BrepLoadOption     brepLoadOption() = 0;
   virtual void               setAssemblyOption( AssemblyOption Option ) = 0;
   virtual AssemblyOption     assemblyOption() = 0;
   virtual void               setPMILoadOption( PmiLoadOption Option ) = 0;
   virtual PmiLoadOption      pmiLoadOption() = 0;
   virtual void               setXTBrepEditOption( XTBrepEditOption Option ) = 0;
   virtual XTBrepEditOption   getXTBrepEditOption() = 0;
   virtual void               setULPLoadOption( UlpLoadOption Option ) = 0;
   virtual UlpLoadOption      ulpLoadOption() = 0;
   virtual void               setPartStorageOption( PartStorageOption Option ) = 0;
   virtual PartStorageOption  partStorageOption() = 0;
   virtual void               setPropertiesCB( propertiesCB *pPropCB ) = 0;
   virtual void               setFileImportOption( FileImportOption Option ) = 0;
   virtual FileImportOption   fileImportOption( ) = 0;
   virtual void               setFeatureLoadOption(FeatureLoadOption Option) = 0;
   virtual FeatureLoadOption  featureLoadOption() = 0;
   virtual void               setLateLoadOption( LateLoadOption Option ) = 0;
   virtual LateLoadOption     lateLoadOption( ) = 0;
   virtual void               setPMIRetristripOption( PmiRetristripOption Option ) = 0;
   virtual PmiRetristripOption pmiRetristripOption( ) = 0;

   virtual JtkHierarchy*      import( const JtkString& Filename ) = 0;
   virtual JtkHierarchy*      import( const JtkString& Filename, JtkEntityList* &Faults ) = 0;
   virtual JtkHierarchy*      import( const JtkString& Filename, JtkEntityList* &Faults, JtkClientData* Info ) = 0;
   virtual JtkHierarchy*      import( unsigned char* Buffer, const int BuffLen ) = 0;
   virtual JtkHierarchy*      import( unsigned char* Buffer, const int BuffLen, JtkEntityList* &Faults ) = 0;
   virtual JtkHierarchy*      import( unsigned char* Buffer, const int BuffLen, JtkEntityList* &Faults, JtkClientData* Info ) = 0;

   virtual int                getJtFileVersion( const JtkString& Filename,
                                                int &Major,
                                                int &Minor ) = 0;

   virtual int                getInfoSegmentProps( const JtkString& Filename,
                                                   JtkEntityList*& Props ) const = 0;
   virtual int                getInfoSegmentProps( const unsigned char* Buffer, int BuffLen,
                                                   JtkEntityList*& Props ) const = 0;

   virtual int                setLayerFilterOption( const JtkString& Option ) = 0;
   virtual JtkString          layerFilterOption( ) = 0;

   // vfm read API
   virtual int                loadMotion( const JtkString&         MotionFileName,
                                          const JtkHierarchy* MotionRoot ) = 0;
   virtual int                loadMotion( const JtkString&         MotionFileName,
                                          const JtkHierarchy* MotionRoot,
                                          JtkUnits            &Units ) = 0;

   // set up XTBrep read callbacks
   static void                setXTPreReadCallback( XTPreReadCB *cb );
   static void                setXTPostReadCallback( XTPostReadCB *cb );

   // import callbacks
   virtual int                setPreActionImportCallback( JtkImportActionCB* cb ) = 0;
   virtual int                setPostActionImportCallback( JtkImportActionCB* cb ) = 0;

protected:
   static XTPreReadCB   *_xtPreReadCB;
   static XTPostReadCB  *_xtPostReadCB;

private:
};
#endif

