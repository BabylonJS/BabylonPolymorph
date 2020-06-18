////////////////////////////////////////////////////////////////////////////////
// Copyright 2011 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_FAULT_HXX
#define JTK_FAULT_HXX

#include <JtTk/JtkClientData.h>
#include <JtTk/JtkString.h>
#include <JtTk/JtkEntityList.h>

class _JtkFault;

///////%{
//
// Class          : JtkFault
//
// Description    : Base class for the Fault reporting mechanism.
//
// Enums          : FaultCode
//                     JtkFILE_OPEN_FAULT -- A given JT file could not be opened.
//                           contextEntity -- Optionally the JtkHierarchy node for which the underlying JT
//                                         file that could not be opened.
//                           contextString -- The name of the JT file that could not be opened.
//                     JtkFILE_CREATE_FAULT -- Unable to create a specific output file.
//                           contextEntity -- Current root JtkHierarchy node that is being output to file.
//                           contextString -- The name of the root JtkHierarchy node.
//                     JtkFILE_PERMISSIONS_FAULT -- Invalid permissions for requested access to file.
//                           contextEntity --- Current root JtkHierarchy node that is being output to file.
//                           contextString -- The name of the root JtkHierarchy node.
//                     JtkFILE_WRITE_FAULT -- Unable to write date to file.
//                           contextEntity --- Current root JtkHierarchy node that is being output to file.
//                           contextString -- The name of the root JtkHierarchy node.
//                     JtkFILE_DISKFULL_FAULT -- Unable to write to file due to disk being full.
//                           contextEntity --- Current root JtkHierarchy node that is being output to file.
//                           contextString -- The name of the root JtkHierarchy node.
//                     JtkFILE_GENERAL_FAULT -- General file access problem.
//                           contextEntity --- Context root JtkHierarchy node.
//                           contextString -- Context filename.
//                     JtkBUFFER_WRITE_FAULT -- Unable to write data to memory buffer.
//                           contextEntity --- Current root JtkHierarchy node that is being output.
//                     JtkBUFFER_OPEN_FAULT -- A NULL, 0-length or invalid buffer has been 
//                        supplied to JtkCADImporter::import.
//                     JtkCREATE_ASSEMBLY_FAULT -- A JtkAssembly could not be created for the specified
//                        id. The assembly will be created without an id specification. This may lead to 
//                        persisted references to the node failing.
//                           contextEntity -- The JtkAssembly.
//                           contextString -- The original name of the assembly.
//                     JtkCREATE_INSTANCE_FAULT -- A JtkInstance could not be created for the specified
//                        id. The instance will be created without an id specification. This may lead to 
//                        persisted references to the node failing.
//                           contextEntity -- The JtkInstance.
//                           contextString -- The original name of the instance.
//                     JtkCREATE_PART_FAULT -- A JtkPart could not be created for the specified id.
//                        The part will be created without an id specification. This may lead to 
//                        persisted references to the node failing.
//                           contextEntity -- The JtkPart.
//                           contextString -- The original name of the part.
//                     JtkCREATE_SHAPE_FAULT -- Unable to create a specific shape.
//                           contextEntity -- The owning JtkPart.
//                     JtkWIREFRAME_FAULT -- Unable to get a wireframe edge CAD tag.
//                           contextEntity -- The owning JtkEntity.
//                           contextString -- The index of the edge in the wireframe.
//                     JtkCREATE_PRIM_FAULT -- Unable to create a specific geometry primitive.
//                           contextEntity -- The owning JtkEntity.
//                           contextString -- The LOD for which the geometry primitive was not built.
//                     JtkATTRIB_CREATE_FAULT -- Unable to create a specific attribute.
//                           contextEntity -- The JtkHierarchy node that is the owner of the attribute.
//                     JtkHIERARCHY_NAME_FAULT -- Unable to find a name property for a JtkHierarchy
//                        node.
//                           contextEntity -- The JtkHierarchy that a name could not be found for.
//                           contextString -- The new name that will be used for the JtkHierarchy node.
//                     JtkTEXTURE_IMAGE_FAULT -- Unable to read texture image bindings for a 
//                        tristrip set.
//                           contextEntity -- Owning parent JtkEntity.
//                     JtkOVERRIDE_MATERIAL_FAULT -- An override material definition could not
//                        be processed.
//                           contextEntity  -- Owning JtkHierarchy.
//                           contextEntity2 -- Optional JtkMaterial that contains the override.
//                           contextString  -- Optional NGID property value.
//                     JtkULP_TESSELLATE_FAULT -- An ULP representation failed to tessellate.
//                           contextEntity -- Owning JtkPart.
//                           contextString -- The LOD that the ULP is associated with.
//                     JtkULP_FAULT -- ULP specific fault
//                           contextEntity -- Owning JtkPart
//                           contextString -- Either the name of the part, or additional data specific
//                                         to the ULP fault.
//                     JtkLICENSE_FAULT -- Valid JT Open Toolkit license not found. Contact
//                        Siemens Product Lifecycle Management Software Inc. for purchase
//                        information.
//                     JtkXT_FAULT -- Problem with the generation of XT data. 
//                         Note: This is also the code used for all JtkXTFault instances.
//                            contextEntity -- The JtkPart for which the XT data could not be generated.
//                            contextEntity2 -- Optional JtkXTEntity derived object identifying the location 
//                                           of the problem.
//                            contextString -- Optional name of the problem JtkPart or identifier of the part.
//                     JtkXT_MONIKER_FAULT -- Problem with the moniker information associated with XT data.
//                            contextEntity -- The owning JtkPart for the XT for which the moniker could not 
//                                          be generated.
//                            contextEntity2 -- Optional JtkXTBody that is associated with the moniker data.
//                            contextString -- Name of JtkPart.
//                     JtkXT_GEOMSHARE_FAULT -- Problem with the XT geometry sharing functionality.
//                            contextEntity -- The root JtkHierarchy node of the associated model structure.
//                            contextEntity2 -- Optional JtkXTSharingGroup associated with the problem.
//                            contextString -- Optional index of the problem JtkXTSharingGroup in the 
//                                          JtkXTSharingManager.
//                     JtkXT_TESSELLATION_FAULT -- Problem with generating tessellation information for XT data
//                            contextEntity -- The owning JtkPart.
//                            contextString -- The name of the owning JtkPart.
//                     JtkJtBREP_FAULT -- Problem with a specific JtkBrep.
//                            contextEntity -- The owning JtkPart.
//                            contextEntity2 -- The problem JtkBrep.
//                            contextString -- The name of the owning JtkPart.
//                     JtkJtBREP_TESSELLATION_FAULT -- Problem with the tessellation of JtkBrep.
//                            contextEntity -- Either the owning JtkPart for the entity that is being tessellated 
//                                          or the entity itself.
//                            contextEntity2 -- Optional additional context entity, this can either be the entity 
//                                           being tessellated, a JtkLineStripSet or tessellation parameters.
//                            contextString -- Optional additional information identifying the source of the problem.
//                     JtkPMI_FAULT -- Unable to get / export a PMI property. 
//                            contextEntity  -- The JtkHierarchy node that owns the problem PMI.
//                            contextEntity2 -- Optional problem JtkPMIEntity object.
//                            contextString  -- Optional identifier of the JtkPMIEntity.
//                     JtkPMI_GLYPHSET_FAULT -- Problem converting from a global to a local GlyphSet
//                            contextEntity -- Owning JtkPart
//                            contextString -- Character/ Index causing the problem.
//                     JtkPMI_SORT_FAULT -- Problem applying PMI Sort information to node.
//                            contextEntity -- The JtkPart containing the sort information.
//                            contextString -- The problem sort information.
//                     JtkPMI_CONTAINER_FAULT -- Problem applying PMI Container information to node.
//                            contextEntity -- The JtkUnitHierarchy node that the PMI Container information would be 
//                                          applied to.
//                            contextString -- The id of the associated JtkPMIEntity.
//                     JtkLAYER_FAULT -- Problem with the definition of Layer data.
//                            contextEntity  -- The JtkHierarchy node associated with the problem Layer data.
//                            contextEntity2 -- Optional JtkLayerFilter, JtkLayer or JtkPMIEntity object 
//                                           associated with the fault.
//                            contextString  -- The problem Layer data.
//                     JtkUNITS_FAULT -- Problem with the units of measurement specified for a specific node.
//                            contextEntity -- The JtkUnitHierarchy node associated with the problem measurement units.
//                            contextString -- The problem measurement unit.
//                     JtkREFSET_FAULT --  Problem with a reference set property.
//                           contextEntity -- The JtkHierarchy which contains the problem property.
//                           contextString -- Additional context information to narrow the problem property.
//                     JtkIMAGE_STAMP_FAULT -- Problem with image stamping functionality.
//                            contextEntity  -- The owning JtkHierarchy node.
//                            contextEntity2 -- Optional problem JtkImageStamp.
//                     JtkEXPORT_PATH_FAULT -- The export path has not been set for the export.
//                            contextEntity -- The root JtkHierarchy that is to be exported.
//                     JtkNOT_IMPLEMENTED -- Functionality has not been implemented.
//                     JtkLOD_FAULT -- Problem with LOD information.
//                            contextEntity -- Owning JtkPart for the LOD
//                            contextString -- Optional index of the problem LOD.
//                     JtkMATERIAL_PATTERN_FAULT -- Problem with material pattern / crosshatch pattern.
//                            contextEntity -- Owning JtkHierarchy node.
//                            contextEntity2 -- Optional JtkMaterial associated with the fault.
//                            contextString -- Name of the pattern, otherwise name of the part.
//                     JtkINVALID_ROOT -- Invalid parameter root node.
//                            contextEntity -- Option entity for the fault.
//                            contextString -- Index of the problem parameter.
//                     JtkEXPORT_CUSTOM_FAULT -- Problem with the JtkCADExporter::JtkCustom
//                                            export option.
//                            contextEntity -- The JtkHierarchy node associated with the problem.
//                            contextString -- Optional string indicating either a problem entity 
//                                          type or the file that is currently being exported.
//                     JtkEXPORT_CB_FAULT -- An error has been detected based on the use of CallBack.
//                            contextEntity -- Possible JtkEntity triggering the error
//                            contextString -- Name of the callback invoked
//                     JtkDIRECTORY_FAULT -- Problem accessing (or changing to) a specific file 
//                                        system directory.
//                            contextString -- The directory.
//                     JtkJT2ASCII_FAULT -- Unable to access external Jt2Ascii tool.
//                            contextString -- Expected tool location.
//                     JtkPOST_TRANS_SCRIPT_FAULT -- Problem performing JTK_POST_TRANS_SCRIPT 
//                                                operation. 
//                            contextString -- Expected location of JTK_POST_TRANS_SCRIPT.
//                     JtkPROPERTY_FAULT -- Problem accessing / applying a given property.
//                            contextEntity -- Context JtkHierarchy or JtkAttrib node.
//                            contextEntity2 -- Optional problem JtkProperty.
//                            contextString -- Optional name of the problem property.
//                     JtkCAE_FAULT -- Problem with the CAE functionality.
//                            contextEntity -- JtkHierarchy node associated with the CAE data.
//                     JtkID_FAULT -- Problem with the persistent identifier of a node.
//                            contextEntity -- JtkHierarchy node associated with the fault.
//                            contextString -- Optional name of the JtkHierarchy node or the object
//                                          with the problem id.
//                     JtkCAD_PROPERTIES_FAULT -- Problem with access / output of CAD Properties.
//                            contextEntity -- The JtkHierarchy node associated with the properties.
//                     JtkEXPORT_DEGENERATE_FAULT -- A JtkHierarchy node is degenerate and due to
//                                                current export options a JT file will not be
//                                                generated during export.
//                            contextEntity -- The JtkUnitHierarchy node associated with the problem.
//                            contextString -- The name of the JT file that would have been output.
//                     JtkEXPORT_DEGENERATE_LOD_FAULT -- A JtkPart node has a degenerate LOD and due
//                                                    to current export options the LOD will be pruned 
//                                                    during export.
//                            contextEntity -- The JtkPart node associated with the problem.
//                            contextString -- The index of the LOD that has been pruned.
//                     JtkVERTEX_POOL_MERGE_FAULT -- A problem when merging the vertex pools of a user 
//                                                 defined list of shapes.
//                            contextEntity -- Optional JtkShape node associated with the problem.
//                            contextString -- Optional index of the shape associated with the problem
//                     JtkEXPORT_DUPLICATE_FILENAME -- Problem generating a unique output JT filename.
//                            contextEntity -- The JtkUnitHierarchy node for which the filename is being 
//                                          generated.
//                            contextString -- The non-unique output filename.
//                     JtkFEATURE_INVALID -- Problem with a JtkFeature node during import or export.
//                            contextEntity -- JtkFeature or JtkUnitHierarchy the problem is associated to
//                            contextEntity2 -- For export this second entity may hold the specific JtkFeature that the fault relates to.
//                                              For import this second entity may hold the child element of the contextEntity.
//                            contentString --  Description of the problem that triggered the fault and 
//                                              how the toolkit is handling this fault.
//                     JtkCAE_CREATE_ID_FAULT -- Problem creating a requested JtkCaeId
//                            contextString -- The element id and / or the node id of the requested JtkCaeId that could not be created. 
//                                          This will be of the form: "<element id>", "<node id>" or "<element id>:<node id>"
//                     JtkCAE_CREATE_ID_EXISTS_FAULT -- Unable to create a requested JtkCaeId as an existing JtkCaeId with matching
//                                                   element id and / or node id combination exists.
//                            contextEntity -- The existing JtkCaeId.
//                            contextString -- The element id and / or node id of the existing JtkCaeId. 
//                                          This will of the form: "<element id>", "<node id>" or "<element id>:<node id>"
//                     JtkCAE_INVALID_DATA -- Semantic CAE data is invalid. 
//                            contextEntity -- The JtkPart that contains the invalid data.
//                            contextString -- Additional information identifying the invalid data.
//                     JtkCAE_INVALID_LEGEND_DATA -- The data for a JtkCaeResultQuantityStepLegend is invalid.
//                            contextEntity -- Optional owning JtkCaeResultStep.
//                            contextEntity2 -- Optional owning JtkCaeResultQuantityArray.
//                            contextString -- Optional name of the problem data for the legend.
//                     JtkCAE_INVALID_RESULT_ARRAY_DATA -- The data for a JtkCaeResultQuantityArray is invalid.
//                            contextEntity -- Owning JtkPart.
//                            contextString -- Optional name of the problem data for the array.
//                     JtkINVALID_PARAM_FAULT -- A given parameter for the function is invalid.
//                            contextEntity -- Optional context entity.
//                            contextString -- Name of the invalid parameter.
//                     JtkLATE_LOAD_FAULT -- Unable to late-load a specific JtkUnitHierarchy node. Node will not be late-loaded.
//                            contextEntity -- JtkUnitHierarchy that could not be late-loaded.
//                            contextString -- Name of the node that could not be late-loaded.
//                     JtkLATE_LOAD_FILE_VERSION_FAULT -- Late loading has been requested for a JT file version earlier than JT v9.5.
//                                                     This is not supported, and the JT file will be loaded without late-loading.
//                            contextString -- The filename of the JT file being loaded.
//                     JtkLATE_LOAD_BUFFER_FAULT -- Late loading has been requested for import of JT data from a memory buffer.
//                                               This is not supported, and the JT data will be loaded without late-loading.
//                     JtkFLOATING_POINT_FAULT-- A fault occurred due to floating point operation
//                            contextEntity -- Optional owning class.
//                            contextString -- Variable/object name of owning floating point data
//                     JtkINDEXING_FAULT-- A fault occurred due invalid index
//                            contextEntity -- Optional owning class.
//                            contextString -- Variable/object name associated with indexing fault
//                     JtkXT_MESH_CONVERSION_FAULT -- A fault occurred converting mesh to XT
//                            contextEntity -- The problem JtkXTMesh.
//                            contextString -- Additional information as to why the conversion failed.
//                     JtkPFGA_CONVERSION_FAULT -- A fault occurred during PFGA conversion
//                            contextEntity -- Owning JtkPart with PFGA LODs.
//                            contextString -- Optional additional information.
//                     JtkSTT_FAULT -- A fault during STT generation
//                            contextEntity -- Optional owning class.
//                            contextString -- Optional additional information.
//                     JtkUNKNOWN_FAULT -- An unknown fault occurred
//                            contextEntity -- Optional owning class.
//                            contextString -- Any information.  
//                                                     
//                   FaultSeverity
//                     JtkERROR_SEVERITY -- The fault represents a catastrophic and/or 
//                        unrecoverable error.
//                     JtkWARNING_SEVERITY -- The fault represents a recoverable or 
//                        avoidable error. 
//                     JtkMESSAGE_SEVERITY -- The fault contains information only.
//                     JtkEXECEPTION_SEVERITY -- The fault represents a catastrophic and/or
//                        unrecoverable error caused by an exception. Continued execution may cause
//                        undefined behavior and/or subsequent crash. 
//                        NOTE: A fault with this severity will mean that the contextEntity
//                        of the fault will not necessarily be the owner of the issue,
//                        but rather the object that caught the exception. Similarly, the 
//                        contextString may describe the method that caught the exception rather
//                        than any contextual information.
//
//                   FaultCategory
//                      JtkIMPORT_CATEGORY -- The fault has been raised as the result of a 
//                         call to JtkCADImporter::import. 
//                      JtkEXPORT_CATEGORY -- The fault has been raised as the result of a
//                         call to JtkCADExporter::export.
//                      JtkPMI_CATEGORY -- The fault is related to the PMI functional area.
//                      JtkXT_CATEGORY -- The fault is related to the XT functional area.
//                      JtkVERTEXPOOL_CATEGORY -- The fault is related to the Vertex Pool functional area
//                      JtkCAE_CATEGORY -- The fault is related to the semantic CAE functional area.
//
// Includes       : JtkFault.h
//
// Inheritance    : JtkClientData > JtkFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkFault: public JtkClientData
{
   JTK_OBJECT_HEADER( JtkFault )

   friend class _JtkFault;

public:

   enum FaultCode
   {
      JtkUNSET_FAULT,
      JtkFILE_OPEN_FAULT,
      JtkBUFFER_OPEN_FAULT,
      JtkCREATE_ASSEMBLY_FAULT,
      JtkCREATE_INSTANCE_FAULT,
      JtkCREATE_PART_FAULT,
      JtkCREATE_SHAPE_FAULT,
      JtkCREATE_PRIM_FAULT,
      JtkWIREFRAME_FAULT,
      JtkATTRIB_CREATE_FAULT,      
      JtkHIERARCHY_NAME_FAULT,
      JtkTEXTURE_IMAGE_FAULT,
      JtkOVERRIDE_MATERIAL_FAULT,
      JtkULP_TESSELLATE_FAULT,
      JtkLICENSE_FAULT,
      JtkXT_FAULT,
      JtkPMI_FAULT,
      JtkLAYER_FAULT,
      JtkUNITS_FAULT,
      JtkIS_COMPONENT_FAULT,
      JtkXT_MONIKER_FAULT,
      JtkXT_TESSELLATION_FAULT,
      JtkXT_GEOMSHARE_FAULT,
      JtkJtBREP_FAULT,
      JtkJtBREP_TESSELLATION_FAULT,
      JtkULP_FAULT,
      JtkEXPORT_PATH_FAULT,
      JtkNOT_IMPLEMENTED,
      JtkLOD_FAULT,
      JtkMATERIAL_PATTERN_FAULT,
      JtkIMAGE_STAMP_FAULT,
      JtkINVALID_ROOT,
      JtkEXPORT_CUSTOM_FAULT,
      JtkEXPORT_CB_FAULT,
      JtkDIRECTORY_FAULT,
      JtkJT2ASCII_FAULT,
      JtkPOST_TRANS_SCRIPT_FAULT,
      JtkPROPERTY_FAULT,
      JtkCAE_FAULT,
      JtkID_FAULT,
      JtkCAD_PROPERTIES_FAULT,
      JtkPMI_GLYPHSET_FAULT,
      JtkPMI_SORT_FAULT,
      JtkPMI_CONTAINER_FAULT,
      JtkFILE_CREATE_FAULT,
      JtkFILE_PERMISSIONS_FAULT,
      JtkFILE_WRITE_FAULT,
      JtkFILE_DISKFULL_FAULT,
      JtkFILE_GENERAL_FAULT,
      JtkBUFFER_WRITE_FAULT,
      JtkREFSET_FAULT,
      JtkEXPORT_DEGENERATE_FAULT,
      JtkEXPORT_DEGENERATE_LOD_FAULT,
      JtkVERTEX_POOL_MERGE_FAULT,
      JtkEXPORT_DUPLICATE_FILENAME,
      JtkFEATURE_INVALID,
      JtkCAE_CREATE_ID_FAULT,
      JtkCAE_CREATE_ID_EXISTS_FAULT,
      JtkCAE_INVALID_DATA,
      JtkCAE_INVALID_LEGEND_DATA,
      JtkCAE_INVALID_RESULT_ARRAY_DATA,
      JtkINVALID_PARAM_FAULT,
      JtkLATE_LOAD_FAULT,
      JtkLATE_LOAD_FILE_VERSION_FAULT,
      JtkLATE_LOAD_BUFFER_FAULT,
      JtkINDEXING_FAULT,
      JtkFLOATING_POINT_FAULT,
      JtkXT_MESH_CONVERSION_FAULT,
      JtkPFGA_CONVERSION_FAULT,
      JtkSTT_FAULT,
      JtkUNKNOWN_FAULT
   };

   enum FaultSeverity
   {
      JtkUNSET_SEVERITY,
      JtkERROR_SEVERITY,
      JtkWARNING_SEVERITY,
      JtkMESSAGE_SEVERITY,
      JtkEXCEPTION_SEVERITY
   };

   enum FaultCategory
   {
      JtkUNSET_CATEGORY,
      JtkIMPORT_CATEGORY,
      JtkEXPORT_CATEGORY,
      JtkPMI_CATEGORY,
      JtkXT_CATEGORY,
      JtkVERTEXPOOL_CATEGORY,
      JtkCAE_CATEGORY
   };
   
   FaultCode getCode( ) const;

   FaultSeverity getSeverity( ) const;

   FaultCategory getCategory( ) const;

   JtkEntity* getContextEntity( ) const;
   JtkString getContextString( ) const;

   JtkString getMessage( ) const;

   int getContextEntities( JtkEntityList*& entities ) const;

private:

   // equality operator
   int operator ==( const JtkFault &OtherFault ) const;

protected:

   // internal constructor
   JtkFault( );

   // internal implementation
   _JtkFault*  _impl;

   // destruction
   virtual ~JtkFault();
};

////////////////////////////////////////////////////////////////////////////////

#endif // !JTK_FAULT_HXX
