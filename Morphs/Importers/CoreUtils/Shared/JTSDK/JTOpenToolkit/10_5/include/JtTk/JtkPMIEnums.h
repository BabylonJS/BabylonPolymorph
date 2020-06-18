////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PMI_ENUMS_H
#define JTK_PMI_ENUMS_H

enum JtkPMITriStateBoolean
{
   booleanTRUE,
   booleanFALSE,
   booleanUNKNOWN
};

enum JtkPMIDimensionCausality
{
   CausalityKEY,
   CausalityFUNCTIONAL,
   CausalityREFERENCE,
   CausalityASSOCIATED,
   CausalityPMI
};
enum JtkPMIDimensionOrigin
{
   OriginFIRST,
   OriginSECOND
};
enum JtkPMIDimensionType
{
   TypeCURVELENGTH,
   TypeLINEAR,
   TypeANGULAR,
   TypeRADIAL
};
enum JtkPMIDimensionStandard
{
   StandardASME_Y145M_1994,
   StandardJIS,
   StandardISO,
   StandardBS,
   StandardANSI_Y145M_1982,
   StandardASME_Y1441M_2003,
   StandardDIN,
   StandardGM_ADDENDUM_1994,
   StandardASME_Y145_2009
};
enum JtkPMIDimensionReferenceDisplay
{
   ReferenceDisplayPARENTHESIS,
   ReferenceDisplayREFERENCE,
   ReferenceDisplayMATCHED
};
enum JtkPMIDimensionZeroToleranceDisplay
{
   ZeroToleranceDisplayDISPLAYZERO,
   ZeroToleranceDisplayBLANK,
   ZeroToleranceDisplaySUPPRESSTRAILINGZERO,
   ZeroToleranceDisplayOMIT
};
enum JtkPMIDimensionStyle
{
   StyleLINEARDIAMETRAL,
   StyleRADIAL,
   StyleCONTROLLEDRADIAL,
   StyleDIAMETRAL,
   StyleLIMITS,
   StyleORDINATE,
   StyleSPHERICALRADIAL,
   StyleSPHERICALDIAMETRAL,
   StyleNARROW,
   StyleNONE
};
enum JtkPMIDimensionToleranceDisplay
{
   ToleranceDisplayUNSET = -1,
   ToleranceDisplayMINUSLIMIT1 = 0,
   ToleranceDisplayBILATERAL,
   ToleranceDisplayPLUSLIMIT1,
   ToleranceDisplayPLUSLIMIT2,
   ToleranceDisplayEQUALBILATERAL,
   ToleranceDisplayMINUSLIMIT2,
   ToleranceDisplayUPPERUNILATERAL,
   ToleranceDisplayLOWERUNILATERAL
};
enum JtkPMIDimensionPlacement
{
   PlacementUNSET = -1,
   PlacementBEFORE = 0,
   PlacementABOVE,
   PlacementBELOW,
   PlacementAFTER
};
enum JtkPMIDimensionDualType
{
   DualTypePOSITIONAL,
   DualTypeBRACKET,
   DualTypeLINESEPARATED
};

enum JtkPMILimitFitOrder
{
   OrderVALUELIMITFITTOLERANCE,
   OrderTOLERANCEVALUELIMITFIT,
   OrderVALUETOLERANCELIMITFIT
};

enum JtkPMILimitFitParentheses
{
   ParenthesesNONE,
   ParenthesesVALUELIMITFIT,
   ParenthesesLIMITFIT,
   ParenthesesTOLERANCE,
   ParenthesesVALUE,
   ParenthesesVALUETOLERANCE
};

enum JtkPMILimitDisplay
{
   LimitDisplayNONE,
   LimitDisplayLIMITFIT
};

enum JtkPMIFractionSize
{
   FractionSizeFULL,
   FractionSizeTWOTHIRDS,
   FractionSizeTHREEQUARTERS
};


enum JtkPMIAngleFormat
{
   AngleFormatUNSET = -1,
   AngleFormatDEGREES,
   AngleFormatSECONDS,
   AngleFormatMINUTES,
   AngleFormatWHOLEDEGREES
};

enum JtkPMILineStyle
{
   LineStyleUNSET,
   LineStyleLONGDASHED,
   LineStyleDOTTED,
   LineStyleDOTTEDDASHED,
   LineStylePHANTOM,
   LineStyleDASHED,
   LineStyleSOLID,
   LineStyleCENTRELINE
};

enum JtkPMIDisplayType
{
   DisplayTypeFLATTOSURFACE,
   DisplayTypeFLATTOSCREEN
};

enum JtkPMIInspectionDisplay
{
   InspectionDisplayUNSET,
   InspectionDisplayNONE,
   InspectionDisplayBEFORE,
   InspectionDisplayAFTER,
   InspectionDisplayBEFOREAFTER,
   InspectionDisplayALL
};

enum JtkPMITextOrientationType
{
   TextOrientationTypeUNSET = -1,
   TextOrientationTypeHORIZONTAL = 0,
   TextOrientationTypeVERTICAL = 1
};
enum JtkPMITextOutlineType
{
   OutlineTypeUNSET = -1,
   OutlineTypeBOX = 0,
   OutlineTypeTRIANGLE,
   OutlineTypeCIRCLE,
   OutlineTypeELLIPSE,
   OutlineTypeUNDERLINE,
   OutlineTypeSQUARE,
   OutlineTypeSCOREDCIRCLE,
   OutlineTypeDIAMOND,
   OutlineTypeFLAGRIGHT,
   OutlineTypeFLAGLEFT,
   OutlineTypeFLAGBOTH,
   OutlineTypeOBLONG,
   OutlineTypeOBLONGRIGHT,
   OutlineTypeOBLONGLEFT,
   OutlineTypeSTICKING,
   OutlineTypeSET,
   OutlineTypeFIXEDSUPPORT,
   OutlineTypeNOTA,
   OutlineTypeSYMMETRICALPART,
   OutlineTypeSYMMETRICALSET,
   OutlineTypeSCOREDRECTANGLE,
   OutlineTypePARALLELOGRAM
};
enum JtkPMITextSymbol
{
   TextSymbolUNSET = -1,
   TextSymbolCENTRELINE = 0,
   TextSymbolPARTINGLINE,
   TextSymbolDEPTH,
   TextSymbolCOUNTERSINK,
   TextSymbolCONICALTAPER,
   TextSymbolSLOPE,
   TextSymbolCOUNTERBORE,
   TextSymbolSQUARE,
   TextSymbolPHI,
   TextSymbolPLUSMINUS,
   TextSymbolDEGREES,
   TextSymbolBETWEEN,
   TextSymbolARCLENGTH,
   TextSymbolLEFTPARENTHESIS,
   TextSymbolRIGHTPARENTHESIS,
   TextSymbolPROJECTEDTOLERANCE,
   TextSymbolMMC,
   TextSymbolLMC,
   TextSymbolFREESTATE,
   TextSymbolOHM,
   TextSymbolCIRCULARRUNOUT,
   TextSymbolTOTALRUNOUT,
   TextSymbolPROFILEOFASURFACE,
   TextSymbolPROFILEOFALINE,
   TextSymbolFLATNESS,
   TextSymbolSTRAIGHTNESS,
   TextSymbolSYMMETRY,
   TextSymbolPERPENDICULARITY,
   TextSymbolPARALLELISM,
   TextSymbolCYLINDRICITY,
   TextSymbolCONCENTRICITY,
   TextSymbolCIRCULARITY,
   TextSymbolANGULARITY,
   TextSymbolMICRO,
   TextSymbolPOSITION,
   TextSymbolENVELOPE,
   TextSymbolRFS,
   TextSymbolTANGENTPLANE,
   TextSymbolLESSTHANOREQUAL,
   TextSymbolGREATERTHANOREQUAL,
   TextSymbolTHREADPREFIX,
   TextSymbolTRIANGLE,
   TextSymbolSTATISTICAL,
   TextSymbolRADIUS,
   TextSymbolCIRCLEDU,
   TextSymbolFITFUNCTION,
   TextSymbolSAFETYCOMPLIANCE,
   TextSymbolQUANTITY,
   TextSymbolINDEPENDENCY,
   TextSymbolCONTINUOUSFEATURE,
   TextSymbolSPOTFACE,
   TextSymbolSPHI,
   TextSymbolSPHERE,
   TextSymbolLEFTTAPER,
   TextSymbolRIGHTTAPER,
   TextSymbolLEFTPITCH,
   TextSymbolRIGHTPITCH,
   TextSymbolAPPROXIMATEDIMENSION,
   TextSymbolAXISINTERSECTION,
   TextSymbolESKDPERPENDICULAR,
   TextSymbolESKDPARALLEL,
   TextSymbolESKDCROSS,
   TextSymbolORIENTATIONCONSTRAINT,
   TextSymbolDATUMTRANSLATION
};

enum JtkPMITextLeaderPosition
{
   TextLeaderPositionNONE,
   TextLeaderPositionABOVELEADER,
   TextLeaderPositionAFTERLEADER,
   TextLeaderPositionABOVESTUB,
   TextLeaderPositionAFTERSTUB
};

enum JtkPMITextOrientation
{
   TextOrientationHORIZONTAL,
   TextOrientationALIGNED,
   TextOrientationABOVE,
   TextOrientationPERPENDICULAR,
   TextOrientationUSERDEFINED
}; 

enum JtkPMIUserValueDataType
{
   UserValueDataTypeUNSET = -1,
   UserValueDataTypeINT = 0,
   UserValueDataTypeINTS,
   UserValueDataTypeREAL,
   UserValueDataTypeREALS,
   UserValueDataTypeBOOLEAN,
   UserValueDataTypeBOOLEANS,
   UserValueDataTypeSTRING,
   UserValueDataTypeREFERENCE,
   UserValueDataTypeENUM,
   UserValueDataTypeLIST,
   UserValueDataTypeDATETIME,
   UserValueDataTypeNONE
};
enum JtkPMIJustification
{
   JustificationUNSET = -1,
   JustificationRIGHT = 0,
   JustificationCENTRE,
   JustificationLEFT,
   JustificationTOPLEFT,
   JustificationTOPRIGHT,
   JustificationTOPCENTRE,
   JustificationBOTTOMLEFT,
   JustificationBOTTOMRIGHT,
   JustificationBOTTOMCENTRE
};
enum JtkPMIAttachmentType
{
   AttachmentTypeANGULARDIMENSION,
   AttachmentTypeONGEOMETRY,
   AttachmentTypeLINEARDIMENSION,
   AttachmentTypeLEADER,
   AttachmentTypeSTACKED,
   AttachmentTypeORDINATEDIMENSION,
   AttachmentTypeRADIALDIMENSION,
   AttachmentTypeDIAMETRALDIMENSION,
   AttachmentTypeNOLEADER,
   AttachmentTypeSTACKEDLEFT,
   AttachmentTypeSTACKEDRIGHT,
   AttachmentTypeSTACKEDABOVE
};
enum JtkPMIUnderline
{
   UnderlineUNSET = -1,
   UnderlineOVER = 0,
   UnderlineUNDER = 1
};
enum JtkPMIUnits
{
   UnitsMETRES,
   UnitsMILLIMETRES,
   UnitsINCHES
};
enum JtkPMITextLineThickness
{
   TextThicknessUNSET = -1,
   TextThicknessNORMAL = 0,
   TextThicknessTHICK,
   TextThicknessTHIN
};
enum JtkPMIDimensionStubDirection
{
   DimensionStubDirectionUNSET= -1,
   DimensionStubDirectionLEFT = 0,
   DimensionStubDirectionRIGHT,
   DimensionStubDirectionINFERRED
};

enum JtkPMIDimensionLineSplit
{
   DimensionLineSplitNONE,
   DimensionLineSplitLIMITFIT,
   DimensionLineSplitVALUELIMITFIT
};

enum JtkPMILeaderArrowType
{
   ArrowTypeCLOSED,
   ArrowTypeOPEN,
   ArrowTypeFILLED,
   ArrowTypeNONE,
   ArrowTypeORIGIN,
   ArrowTypeCROSS,
   ArrowTypeDOT,
   ArrowTypeFILLEDDOT,
   ArrowTypeWEDGE,
   ArrowTypePLUS,
   ArrowTypeX,
   ArrowTypeCLOSEDSOLID,
   ArrowTypeCLOSEDDOUBLE,
   ArrowTypeCLOSEDDOUBLESOLID,
   ArrowTypeOPENDDOUBLE,
   ArrowTypeFILLEDDOUBLE,
   ArrowTypeINTEGRAL,
   ArrowTypeBOX,
   ArrowTypeFILLEDBOX,
   ArrowTypeDATUM,
   ArrowTypeFILLEDDATUM,
   ArrowTypeSOLIDORIGIN,
   ArrowTypeFILLEDORIGIN,
   ArrowTypeXORIGIN,
   ArrowTypeSOLIDBOX,
   ArrowTypeROUNDBACKDART,
   ArrowTypeSOLIDROUNDBACKDART,
   ArrowTypeFILLEDROUNDBACKDART
};

enum JtkPMILeaderAttachment
{
   LeaderAttachmentTOP,
   LeaderAttachmentMIDDLE,
   LeaderAttachmentBOTTOM
};

enum JtkPMIExtensionJogging
{
   ExtensionJoggingON,
   ExtensionJoggingOFF,
   ExtensionJoggingAPPLICATION
};

enum JtkPMIExtensionJogDefinition
{
   ExtensionJogDefinitionSTARTEND,
   ExtensionJogDefinitionSTARTANGLE,
   ExtensionJogDefinitionENDANGLE
};

enum JtkPMIRefGeomType
{
   GeomTypePOINT = 1,
   GeomTypeAXIS,
   GeomTypePLANE
};

enum JtkPMISurfaceFinishLay
{
   LayPARALLEL,
   LayMULTIDIRECTIONAL,
   LayPERPENDICULAR,
   LayCIRCULAR,
   LayPARTICULATE,
   LayANGULARBOTH,
   LayRADIAL, 
   LayUSERDEFINED
};
enum JtkPMISurfaceFinishStandard
{
   SurfaceFinishStandardJIS,
   SurfaceFinishStandardANSI_Y1436_1993,
   SurfaceFinishStandardISO,
   SurfaceFinishStandardASME_Y1436M_1996,
   SurfaceFinishStandardDIN,
   SurfaceFinishStandardGB,
   SurfaceFinishStandardISO_1302_2002,
   SurfaceFinishStandardESKD,
   SurfaceFinishStandardDIN_EN_ISO_1302_2002
};
enum JtkPMISurfaceFinishType
{
   SurfaceFinishTypeBASIC,
   SurfaceFinishTypeMRR,
   SurfaceFinishTypeMRP
};

enum JtkPMIFCFCharacteristic
{
   CharacteristicPROFILEOFALINE,
   CharacteristicCIRCULARRUNOUT,
   CharacteristicPERPENDICULARITY,
   CharacteristicPOSITION,
   CharacteristicTOTALRUNOUT,
   CharacteristicPROFILEOFASURFACE,
   CharacteristicCYLINDRICITY,
   CharacteristicSYMMETRY,
   CharacteristicANGULARITY,
   CharacteristicPARALLELISM,
   CharacteristicCONCENTRICITY,
   CharacteristicFLATNESS,
   CharacteristicCIRCULARITY,
   CharacteristicSTRAIGHTNESS,
   CharacteristicAXISINTERSECTION
};
enum JtkPMIFCFProfileType
{
   ProfileTypeBILATERAL,
   ProfileTypeUNILATERALINSIDE,
   ProfileTypeUNILATERALOUTSIDE,
   ProfileTypeBILATERALUNEQUAL
};
enum JtkPMIFCFDatumGroup
{
   PRIMARY,
   SECONDARY,
   TERTIARY
};
enum JtkPMIFCFZoneShape
{
   FCFZoneShapeDIAMETER,
   FCFZoneShapeSPHERICALDIAMETER,
   FCFZoneShapeSQUARE
};
enum JtkPMIFCFModifier
{
   FCFModifierUNSET = -1,
   FCFModifierLMC = 0,
   FCFModifierMMC = 1,
   FCFModifierRFS = 2
};

enum JtkPMIFCFTextUnderline
{
   FCFTextUnderlineNONE,
   FCFTextUnderlineTOP,
   FCFTextUnderlineALL
};

enum JtkPMIDatumOnLeader
{
   DatumOnLeaderNONE,
   DatumOnLeaderSOLID,
   DatumOnLeaderFILLED
};

enum JtkPMIDatumTargetType
{
   TypeCYLINDRICAL,
   TypeLINE,
   TypeARBITRARY,
   TypeCIRCULAR,
   TypePOINT,
   TypeANNULAR,
   TypeAREA,
   TypeRECTANGULAR,
   TypeSPHERICAL
};

enum JtkPMIDatumTargetAreaShape
{
   AreaShapeDIAMETER,
   AreaShapeSPHERICALDIAMETER,
   AreaShapeSQUARE
};

enum JtkPMIDatumTerminator
{
   DatumTerminatorNONE,
   DatumTerminatorX,
   DatumTerminatorPLUS
};

enum JtkPMISpotWeldType
{
   TypeUNSET,
   TypeRESISTANCE,
   TypePROJECTION
};
enum JtkPMILineWeldSymbol
{
   LineWeldSymbolUNSET,
   LineWeldSymbolJISSEAM,
   LineWeldSymbolSINGLEBEVELGROOVE,
   LineWeldSymbolSINGLEUGROOVE,
   LineWeldSymbolEDGEFLANGE,
   LineWeldSymbolSURFACE,
   LineWeldSymbolSTEEPFLANKEDSINGLEBEVEL,
   LineWeldSymbolFLARESINGLEVGROOVE,
   LineWeldSymbolSURFACEJOINT,
   LineWeldSymbolSINGLEVGROOVE,
   LineWeldSymbolINCLINEDJOINT,
   LineWeldSymbolPLUG,
   LineWeldSymbolFILLET,
   LineWeldSymbolSQUAREGROOVE,
   LineWeldSymbolSPOT,
   LineWeldSymbolSINGLEJ,
   LineWeldSymbolSQUARE,
   LineWeldSymbolOVERLAY,
   LineWeldSymbolSINGLEU,
   LineWeldSymbolSINGLEJGROOVE,
   LineWeldSymbolDOUBLEFLANGE,
   LineWeldSymbolSINGLEFLANGE,
   LineWeldSymbolSPOTPROJECTED,
   LineWeldSymbolPLUGANDSLOT,
   LineWeldSymbolSINGLEBEVELBROADROOTFACE,
   LineWeldSymbolEDGE,
   LineWeldSymbolJISSTAGGEREDFILLET1,
   LineWeldSymbolSINGLEV,
   LineWeldSymbolFLARESINGLEBEVELGROOVE,
   LineWeldSymbolSINGLEVBROADROOTFACE,
   LineWeldSymbolSTEEPFLANKEDSINGLEV,
   LineWeldSymbolREMOVABLEBACKINGSTRIP,
   LineWeldSymbolPERMANENTBACKINGSTRIP,
   LineWeldSymbolJISFILLET,
   LineWeldSymbolSINGLEBEVEL,
   LineWeldSymbolBACKING,
   LineWeldSymbolFOLDJOINT,
   LineWeldSymbolJISSTAGGEREDFILLET2,
   LineWeldSymbolSEAM,
   LineWeldSymbolBEAD,
   LineWeldSymbolSTUD,
   LineWeldSymbolINTERMITTENT,
   LineWeldSymbolBACKINGPLATE,
   LineWeldSymbolMELTTHROUGH,
   LineWeldSymbolSOLDER,
   LineWeldSymbolKGROOVE,
   LineWeldSymbolSTAKE,
   LineWeldSymbolKEYHOLE,
   LineWeldSymbolJISPOT,
   LineWeldSymbolJISSPOTFLATELECTRODE,
   LineWeldSymbolESKDHEAT,
   LineWeldSymbolESKDSMOOTH,
   LineWeldSymbolESKDSTAGGERCHAIN,
   LineWeldSymbolESKDSTAGGERCHECK,
   LineWeldSymbolESKDNOTALLAROUND,
   LineWeldSymbolESKDDIAMETER,
   LineWeldSymbolESKDNUMBER,
   LineWeldSymbolISOEDGE
};
enum JtkPMILineWeldFinishSymbol
{
   LineWeldFinishSymbolUNSET,
   LineWeldFinishSymbolUNSPECIFIED,
   LineWeldFinishSymbolMACHINING,
   LineWeldFinishSymbolGRINDING,
   LineWeldFinishSymbolCHIPPING,
   LineWeldFinishSymbolNONE,
   LineWeldFinishSymbolHAMMERING,
   LineWeldFinishSymbolPEENING,
   LineWeldFinishSymbolROLLING,
   LineWeldFinishSymbolFINISHING
};
enum JtkPMILineWeldSupplementalSymbol
{
   LineWeldSupplementalSymbolUNSET,
   LineWeldSupplementalSymbolCONVEX,
   LineWeldSupplementalSymbolTOESBLENDED,
   LineWeldSupplementalSymbolCONCAVE,
   LineWeldSupplementalSymbolFLUSH,
   LineWeldSupplementalSymbolPERMANENTBACKINGSTRIP,
   LineWeldSupplementalSymbolREMOVABLEBACKINGSTRIP,
   LineWeldSupplementalSymbolSTUD,
   LineWeldSupplementalSymbolINTERMITTENT,
   LineWeldSupplementalSymbolBACKING,
   LineWeldSupplementalSymbolBACKINGREMOVEAFTERWELD,
   LineWeldSupplementalSymbolSPACER,
   LineWeldSupplementalSymbolCONSUMABLEINSERT,
   LineWeldSupplementalSymbolFLUSHESKD,
   LineWeldSupplementalSymbolMACHININGGRADEDJUNCTION,
   LineWeldSupplementalSymbolSURFACEFINISHBASIC,
   LineWeldSupplementalSymbolSURFACEFINISHBASICCOMPLETE,
   LineWeldSupplementalSymbolSURFACEFINISHMRR,
   LineWeldSupplementalSymbolSURFACEFINISHMRRCOMPLETE,
   LineWeldSupplementalSymbolSURFACEFINISHMRP,
   LineWeldSupplementalSymbolSURFACEFINISHMRPCOMPLETE,
   LineWeldSupplementalSymbolMELTTHROUGH
};

enum JtkPMILineWeldStandard
{
   StandardANSIAWS_A24MINUS98,
   StandardISO_2556,
   StandardJIS_Z_3021,
   LineWeldStandardDIN,
   LineWeldStandardESKD,
   LineWeldStandardGB
};

enum JtkPMILineWeldReferenceSign
{
   LineWeldReferenceSignFORK,
   LineWeldREferenceSignBOX
};

enum JtkPMILineWeldFieldWeld
{
   LineWeldFieldWeldCOMMON,
   LineWeldFieldWeldESKD
};

enum JtkPMILineWeldContour
{
   LineWeldContourUNSET,
   LineWeldContourCLOSED,
   LineWeldContourOPEN,
   LineWeldContourTRILATERAL,
   LineWeldContourALLAROUND
};

enum JtkPMILocatorCoordinatePlane
{
   CoordinatePlaneY,
   CoordinatePlaneXZ,
   CoordinatePlaneXY,
   CoordinatePlaneYZ,
   CoordinatePlaneZ,
   CoordinatePlaneXYZ,
   CoordinatePlaneX
};
enum JtkPMILocatorMainRectSlotFreeformType
{
   MainRectSlotFreeformTypeDL,
   MainRectSlotFreeformTypeH,
   MainRectSlotFreeformTypehk,
   MainRectSlotFreeformTypeBL,
   MainRectSlotFreeformTypeHK,
   MainRectSlotFreeformTypeAC,
   MainRectSlotFreeformTypeh,
   MainRectSlotFreeformTypeCH
};
enum JtkPMILocatorMainSurfaceType
{
   MainSurfaceTypeSK,
   MainSurfaceTypeCO,
   MainSurfaceTypeJ,
   MainSurfaceTypes,
   MainSurfaceTypeSL,
   MainSurfaceTypesk,
   MainSurfaceTypeCS,
   MainSurfaceTypeS,
   MainSurfaceTypeCK
};
enum JtkPMILocatorMainEdgeType
{
   MainEdgeTypeCE,
   MainEdgeTypee,
   MainEdgeTypeE,
   MainEdgeTypeEK,
   MainEdgeTypeCO
};
enum JtkPMILocatorChangeLevel
{
   ChangeLevelSOFT,
   ChangeLevelMEDIUM,
   ChangeLevelHARD
};
enum JtkPMILocatorSubtype
{
   SubtypeUNSET = -1,
   SubtypeMECHANICALLYFASTENED = 0,
   SubtypeMANUFACTURINGANDASSEMBLY,
   SubtypeDIESMOLDS,
   SubtypeFIXING,
   SubtypeTEMPORARYTRANSFERRED,
   SubtypePERMANENTLYTRANSFERRED,
   SubtypeCOORDINATION,
   SubtypeCORRECTABLE,
   SubtypeAUXILIARYREST,
   SubtypeSCRIBEDCOORDINATIONLINE,
   SubtypeACCESSCLEARANCEHOLE,
   SubtypeDETACHED,
   SubtypeBLANK,
   SubtypeJCLAMPS
};
enum JtkPMILocatorMainHoleType
{
   MainHoleTypeDL,
   MainHoleTypeH,
   MainHoleTypehk,
   MainHoleTypech,
   MainHoleTypeHK,
   MainHoleTypeAC,
   MainHoleTypeh,
   MainHoleTypeBL,
   MainHoleTypeCH
};
enum JtkPMILocatorSymbol
{
   SymbolRECTANGLE,
   SymbolEDGE,
   SymbolHOLE,
   SymbolFREEFORM,
   SymbolSLOT,
   SymbolSURFACE
};
enum JtkPMIBundleDressingType
{
   TypeBUNDLENOTE,
   TypeDRESSINGNOTE
};
enum JtkPMICuttingPlaneSymbolType
{
   CutterTypePLANE,
   CutterTypeOPEN,
   CutterTypeCLOSED
};
enum JtkPMICuttingPlaneStandard
{
   CuttingPlaneStandardUNSET,
   CuttingPlaneStandardISO,
   CuttingPlaneStandardASME_Y1441M
};
enum JtkPMITextPlaneOrientation
{
   TextPlaneOrientationUNSET,
   TextPlaneOrientationPARALLEL,
   TextPlaneOrientationPERPENDICULAR
};
enum JtkPMIPlaneArrowPlacement
{
   ArrowPlacementUNSET,
   ArrowPlacementORIGIN,
   ArrowPlacementTOP,
   ArrowPlacementBOTTOMRIGHT,
   ArrowPlacementTOPRIGHT
};
enum JtkPMICrossHatchPattern
{
   PatternUNSET,
   PatternRUBBER,
   PatternLEAD,
   PatternUSER,
   PatternSTEEL,
   PatternBRASS,
   PatternSOLID,
   PatternIRON,
   PatternALUMINUM,
   PatternGLASS,
   PatternELECTRICALWINDING,
   PatternREFRACTORY,
   PatternTHERMALINSULATION
};
enum JtkPMIEMarkingType
{
   TypeEXPORTCONTROL,
   TypePRODUCTPROPRIETARYINFO,
   TypeGOVERNMENTSECURITYINFO
};

enum JtkPMIRegionArea
{
   AreaRECTANGULAR,
   AreaCIRCULAR,
   AreaANNULAR,
   AreaCYLINDRICAL,
   AreaGENERAL
};
enum JtkPMIOriginAnchor
{
   OriginAnchorTOPLEFT,
   OriginAnchorTOPCENTRE,
   OriginAnchorTOPRIGHT,
   OriginAnchorMIDDLELEFT,
   OriginAnchorMIDDLECENTRE,
   OriginAnchorMIDDLERIGHT,
   OriginAnchorBOTTOMLEFT,
   OriginAnchorBOTTOMCENTRE,
   OriginAnchorBOTTOMRIGHT
};
#define JtkPMIRegionOriginAnchor JtkPMIOriginAnchor //backwards compatibility

enum JtkPMIRefGeomDrawType
{
   JtkPMI_LINE_UNSET = -1,
   JtkPMI_LINE_SOLID = 0,
   JtkPMI_LINE_DASHED,
   JtkPMI_LINE_DOTTED,
   JtkPMI_LINE_DASHED_DOTTED,
   JtkPMI_LINE_PHANTOM,
   JtkPMI_LINE_LONG_DASHED,
   JtkPMI_LINE_CENTERLINE,
   JtkPMI_LINE_INVISIBLE,
   JtkPMI_POINT_NO_MARKER,
   JtkPMI_POINT_POINT_MARKER,
   JtkPMI_POINT_DOT_MARKER,
   JtkPMI_POINT_ASTERISK_MARKER,
   JtkPMI_POINT_CIRCLE_MARKER,
   JtkPMI_POINT_POUNDSIGN_MARKER,
   JtkPMI_POINT_X_MARKER,
   JtkPMI_POINT_GRIDPOINT_MARKER,
   JtkPMI_POINT_SQUARE_MARKER,
   JtkPMI_POINT_TRIANGLE_MARKER,
   JtkPMI_POINT_DIAMOND_MARKER,
   JtkPMI_POINT_CENTERLINE_MARKER,
   JtkPMI_POINT_ANCHOR_MARKER,
   JtkPMI_POINT_FILLED_CIRCLE_MARKER,
   JtkPMI_POINT_FILLED_SQUARE_MARKER,
   JtkPMI_POINT_LARGE_FILLED_SQUARE_MARKER,
   JtkPMI_POINT_CIRCLE_IN_CIRCLE_MARKER,
   JtkPMI_POINT_CIRCLE_IN_SQUARE_MARKER,
   JtkPMI_POINT_SQUARE_IN_SQUARE_MARKER,
   JtkPMI_POINT_FILLED_LEFT_TRIANGLE_MARKER,
   JtkPMI_POINT_FILLED_RIGHT_TRIANGLE_MARKER,
   JtkPMI_POINT_FILLED_UP_TRIANGLE_MARKER,
   JtkPMI_POINT_FILLED_DOWN_TRIANGLE_MARKER,
   JtkPMI_POINT_FILLED_LEFT_TRIANGLE_IN_CIRCLE_MARKER,
   JtkPMI_POINT_FILLED_RIGHT_TRIANGLE_IN_CIRCLE_MARKER,
   JtkPMI_POINT_FILLED_UP_TRIANGLE_IN_CIRCLE_MARKER,
   JtkPMI_POINT_FILLED_DOWN_TRIANGLE_IN_CIRCLE_MARKER,
   JtkPMI_POINT_FILLED_LEFT_TRIANGLE_IN_SQUARE_MARKER,
   JtkPMI_POINT_FILLED_RIGHT_TRIANGLE_IN_SQUARE_MARKER,
   JtkPMI_POINT_FILLED_UP_TRIANGLE_IN_SQUARE_MARKER,
   JtkPMI_POINT_FILLED_DOWN_TRIANGLEIN_SQUARE_MARKER,
   JtkPMI_POINT_ROUNDED_CROSS_MARKER,
   JtkPMI_POINT_FILLED_DIAMOND_MARKER,
   JtkPMI_POINT_UP_DOWN_TRIANGLES_MARKER,
   JtkPMI_POINT_LEFT_RIGHT_TRIANGLES_MARKER,
   JtkPMI_POINT_SMALL_WHEEL_MARKER,
   JtkPMI_POINT_LARGE_WHEEL_MARKER,
   JtkPMI_POINT_HOLLOW_CIRCLE_MARKER,
   JtkPMI_POINT_ARC_END_POINT_MARKER,
   JtkPMI_POINT_BIG_ASTERISK_MARKER,
   JtkPMI_POINT_LINE_IN_CIRCLE_MARKER,
   JtkPMI_POINT_PLUS_IN_CIRCLE_MARKER,
   JtkPMI_POINT_CENTER_OF_ROTATION_MARKER,
   JtkPMI_POINT_INVALID_MARKER
};
enum JtkPMIArrowPlacement
{
   ArrowPlacementOUT,
   ArrowPlacementIN
};
enum JtkPMISectionDisplay
{
   SectionDisplaySLICE,
   SectionDisplaySECTION,
   SectionDisplayFAR,
   SectionDisplayNONE
};
enum JtkPMISectionStyle
{
   SectionStyleSHADED,
   SectionStyleWIREFRAME
};
enum JtkPMISectionComponentState
{
   SectionComponentStateINCLUSIVE,
   SectionComponentStateEXCLUSIVE
};
enum JtkSectionCrosshatchMethod
{
   SectionCrosshatchMethodNONE,
   SectionCrosshatchMethodBYPATTERN,
   SectionCrosshatchMethodBYMATERIAL
};
enum JtkPMICenterlineType
{
   Centerline2D,
   Centerline3D,
   CenterMark,
   CircularCenterline,
   BoltCircleCenterline,
   SymmetricCenterline,
   OffsetCenterline
};
enum JtkPMICenterlineDisplay
{
   CenterlineNone,
   Centerline,
   CenterlineWithExtension,
   Centerpoint
};
enum JtkPMIParenthesis
{
   ParenthesisNONE,
   ParenthesisLEFT,
   ParenthesisRIGHT,
   ParenthesisBOTH
};

enum JtkPMISectionGroupGeometryType
{
   SectionGroupGeometryPARALLELPLANES,
   SectionGroupGeometryBOX
};

enum JtkWidthMeasurementType
{
   WidthMeasurementMETERS,
   WidthMeasurementPIXELS
};

enum JtkPMIStrikethrough
{
   StrikethroughNONE,
   StrikethroughSINGLE,
   StrikethroughDOUBLE
};

enum JtkPMISubscript
{
   SubscriptUNSET = -1,
   SubscriptSUB = 0,
   SubscriptSUPER
};

enum JtkPMIFitDesignationAlignment
{
   FitDesignationAlignmentUNSET = -1,
   FitDesignationAlignmentMIDDLE = 0,
   FitDesignationAlignmentBOTTOM
};

enum JtkPMICameraType
{
   CameraTypePERSPECTIVE = 0,
   CameraTypeORTHOGRAPHIC = 1
};

enum JtkPMIParameterType
{
   ParameterTypeUNSET = -1,
   ParameterTypeDIAMETER = 0,
   ParameterTypeDEPTH,
   ParameterTypeCOUNTERBOREDIAMETER,
   ParameterTypeCOUNTERBOREDEPTH,
   ParameterTypeCOUNTERSINKDIAMETER,
   ParameterTypeCOUNTERSINKANGLE,
   ParameterTypeTAPERANGLE,
   ParameterTypeFIT,
   ParameterTypeSCREWTYPE,
   ParameterTypeSCREWSIZE,
   ParameterTypeTHREADSIZE,
   ParameterTypeTHREADDEPTH,
   ParameterTypeSTARTCHAMFERDIAMETER,
   ParameterTypeSTARTCHAMFERANGLE,
   ParameterTypeENDCHAMFERDIAMETER,
   ParameterTypeENDCHAMFERANGLE,
   ParameterTypePITCH,
   ParameterTypeANGLE,
   ParameterTypeMINORDIAMETER,
   ParameterTypeMAJORDIAMETER,
   ParameterTypeTAPDRILLDIAMETER,
   ParameterTypeLENGTH,
   ParameterTypeTAPDRILLSIZE,
   ParameterTypeSYMBOLICTHREADCALLOUT,
   ParameterTypeSHAFTSIZE,
   ParameterTypeTHREADPITCH,
   ParameterTypeFORM,
   ParameterTypeINTERNALEXTERNALSYMBOL
};

enum JtkPMIChamferDisplay
{
   ChamferDisplaySYMBOL,
   ChamferDisplaySIZE,
   ChamferDisplaySIZEANGLE,
   ChamferDisplayANGLESIZE
};

enum JtkPMIChamferLeader
{
   ChamferLeaderPERPENDICULAR,
   ChamferLeaderPARALLEL,
   ChamferLeaderLINEAR
};

enum JtkPMIChamferSymbol
{
   ChamferSymbolNONE,
   ChamferSymbolPREFIX,
   ChamferSymbolSUFFIX
};

enum JtkPMIModelViewStyle
{
   ModelViewStyleUNSET = -1,
   ModelViewStyleSHADED,
   ModelViewStyleSHADEDWITHEDGES,
   ModelViewStyleHIDDEN,
   ModelViewStyleHIDDENMARKED,
   ModelViewStyleWIREFRAME,
   ModelViewStyleTRANSPARENT
};

enum JtkPMIPolylineStyle
{
   SolidStyle = 0,
   DashedStyle = 1,
   DottedStyle = 2,
   DashedDotted = 3,
   DashedDottedDotted = 4,
   LongDashed = 5,
   CenterDashed = 6,
   CenterDashedDashed = 7,
   Invisible = 8
};

enum JtkPMIReferenceGeometryArrowType
{
   RefGeomArrowTypeUnsupported = -1,
   RefGeomArrowTypeNone = 0,
   RefGeomArrowTypeCone = 1
};

enum JtkAssemblyCrosshatch
{
   AssemblyCrosshatchUNSET = -1,
   AssemblyCrosshatchNONE = 0,
   AssemblyCrosshatchDIAGONAL = 1,
   AssemblyCrosshatchVARIABLE = 2
};

enum JtkPMIFCFIndicator
{
   FCFIndicatorUNSET = -1,
   FCFIndicatorINTERSECTIONPLANE = 0,
   FCFIndicatorORIENTATIONPLANE = 1,
   FCFIndicatorCOLLECTIONPLANE = 2,
   FCFIndicatorDIRECTIONFEATURE = 3
};

enum JtkPMIFCFIndicatorSymbol
{
   FCFIndicatorSymbolUNSET = -1,
   FCFIndicatorSymbolPARALLEL = 0,
   FCFIndicatorSymbolPERPENDICULAR = 1,
   FCFIndicatorSymbolANGULAR = 2,
   FCFIndicatorSymbolINCLUDING = 3
};

enum JtkPMICircularCenterlineMethod
{
	CircularCenterlineMethodUNSET = -1,
	CircularCenterlineMethodCENTER = 0,
	CircularCenterlineMethodPOINTS = 1
};

enum JtkPMIFieldWeldDirection
{
   FieldWeldDirectionUNSET =-1,
   FieldWeldDirectionUP = 0,
   FieldWeldDirectionDOWN = 1
};

enum JtkPMIGrooveGapTextStyle
{
   GrooveGapTextStyleUNSET = -1,
   GrooveGapTextStyleINSIDE = 0,
   GrooveGapTextStyleOUTSIDE = 1,
   GrooveGapTextStyleARROW = 2
};

enum JtkPMIHalfArrow
{
   HalfArrowUNSET = -1,
   HalfArrowLEFT = 0,
   HalfArrowRIGHT = 1,
   HalfArrowFULL = 2
};

enum JtkPMIFCFUnequalDisplay
{
	UnequalDisplayUNSET = -1,
	UnequalDisplayCIRCLEU = 0,
	UnequalDisplayUZ = 1
};

enum JtkPMIReferenceContent
{
	ReferenceContentUNSET = -1,
	ReferenceContentVALUE = 0,
	ReferenceContentPREFIX = 1,
	ReferenceContentTOLERANCE = 2 
};

enum JtkPMIDimensionToleranceClassISO
{
   ISOToleranceClassUNSET = -1,
   ISOToleranceClassFINE = 0,
   ISOToleranceClassMEDIUM,
   ISOToleranceClassCOARSE,
   ISOToleranceClassVERYCOARSE,
};

enum JtkPMIShadingStyle
{
   ShadingStyleUNSET = -1,
   ShadingStyleFLAT = 0,
   ShadingStyleSMOOTH = 1
};

enum JtkPMIStubAttachment
{
   StubAttachmentUNSET = -1,
   StubAttachmentSIDE = 0, 
   StubAttachmentUNDERLINE
};

enum JtkPMIZeroToleranceSign
{
   ZeroToleranceSignUNSET = -1,
   ZeroToleranceSignNONE = 0,
   ZeroToleranceSignPLUS = 1,
   ZeroToleranceSignMINUS = 2
};

enum PMIPolygonPrimType
{
   PMI_PRIMTYPE_TRIANGLES,
   PMI_PRIMTYPE_TRIANGLES_STRIP,
   PMI_PRIMTYPE_TRIANGLES_FAN,
   PMI_PRIMTYPE_POLYGON
};

// Note: The following pre-defined types can be/are used for types values of PMI.
//       The JtkPMIGenericEntity derived classes have assigned types which can be 
//       accessed via JtkPMIGenericEntity::getPMIType.
//       Some classes such as JtkPMISpotWeld also have a setPMIType function which enable the user
//       to change the type to a specific set of defined child types documented with the function.
//       JtkPMIUserDefinedSymbol also has a setPMIType which can be freely set to any value.
//       Supplying a predefined value to this may result on read of the JT file the PMI being read
//       as a different JtkPMIGenericEntity type. The JtkPMIUserDefinedSymbol entity also allows for the 
//       setting of the parent type.
const unsigned short PMI_TYPE = 0x0001;
const unsigned short PMI_WELD_TYPE = 0x0002;
const unsigned short PMI_SPOT_WELD_TYPE = 0x0004;
const unsigned short PMI_LINE_WELD_TYPE = 0x0008;

const unsigned short PMI_GROOVE_WELD_TYPE = 0x0010;
const unsigned short PMI_FILLET_WELD_TYPE = 0x0011;
const unsigned short PMI_SLOT_WELD_TYPE = 0x0012;
const unsigned short PMI_EDGE_WELD_TYPE = 0x0014;
const unsigned short PMI_ARC_SPOT_WELD_TYPE = 0x0018;
const unsigned short PMI_RES_SPOT_WELD_TYPE = 0x0020;
const unsigned short PMI_RES_SEAM_WELD_TYPE = 0x0021;
const unsigned short PMI_BEAD_TYPE = 0x0022;
const unsigned short PMI_TAPE_TYPE = 0x0024;
const unsigned short PMI_DOLLOP_TYPE = 0x0028;
const unsigned short PMI_CLINCH_TYPE = 0x0040;

const unsigned short PMI_SURF_FINISH_TYPE = 0x0041;
const unsigned short PMI_MEAS_PT_TYPE = 0x0042;
const unsigned short PMI_DATUM_LOC_TYPE = 0x0044;

const unsigned short PMI_CERT_PT_TYPE = 0x0048;

const unsigned short PMI_GDT_TYPE = 0x0080;
const unsigned short PMI_FCF_TYPE = 0x0081;
const unsigned short PMI_DIM_TYPE = 0x0082;
const unsigned short PMI_DFS_TYPE = 0x0084;
const unsigned short PMI_DTARGET_TYPE = 0x0088;
const unsigned short PMI_NOTE_TYPE = 0x0100;
const unsigned short PMI_FACE_ATTR_TYPE = 0x0101;
const unsigned short PMI_MV_LABEL_TYPE = 0x0102;
const unsigned short PMI_CSYSTEM_TYPE = 0x0104;
const unsigned short PMI_REF_GEOM_TYPE = 0x0108;
const unsigned short PMI_REF_PT_TYPE = 0x0110;
const unsigned short PMI_REF_AXIS_TYPE = 0x0111;
const unsigned short PMI_REF_PLANE_TYPE = 0x0112;
const unsigned short PMI_USER_DEFINED = 0x0114;

const unsigned short PMI_MEAS_LOC_TYPE = 0x0118;

const unsigned short PMI_DATUM_PT_TYPE = 0x0120;

const unsigned short PMI_SURF_VEC_TYPE = 0x0121;
const unsigned short PMI_HOLE_VEC_TYPE = 0x0122;
const unsigned short PMI_TRIM_VEC_TYPE = 0x0124;
const unsigned short PMI_HEM_VEC_TYPE = 0x0128;

const unsigned short PMI_FASTENER_TYPE = 0x0230;
const unsigned short PMI_MATERIAL_SPEC_TYPE = 0x0231;
const unsigned short PMI_PROCESS_SPEC_TYPE = 0x0232;
const unsigned short PMI_PART_SPEC_TYPE = 0x0233;
const unsigned short PMI_BALLOON_TYPE = 0x0235;
const unsigned short PMI_CIRCLE_CENTRE_TYPE = 0x0238;
const unsigned short PMI_COORDINATE_NOTE_TYPE = 0x0239;
const unsigned short PMI_ATTRIBUTE_NOTE_TYPE = 0x0240;
const unsigned short PMI_BUNDLE_DRESSING_NOTE_TYPE = 0x0241;
const unsigned short PMI_CUTTING_PLANE_SYMBOL_TYPE = 0x0242;
const unsigned short PMI_CROSSHATCH_TYPE = 0x0243;
const unsigned short PMI_E_MARKING_TYPE = 0x0244;
const unsigned short PMI_ORGANISATION_TYPE = 0x0245;
const unsigned short PMI_REGION_TYPE = 0x0246;
const unsigned short PMI_SECTION_TYPE = 0x0305;
const unsigned short PMI_CENTERLINE_TYPE = 0x0306;
const unsigned short PMI_FIT_DESIGNATION_TYPE = 0x0307;
const unsigned short PMI_COMPOSITE_FCF_TYPE = 0x0308;
const unsigned short PMI_WELD_NOTE_TYPE = 0x0309;
const unsigned short PMI_REF_CIRCLE = 0x030A;
const unsigned short PMI_REF_CYLINDER = 0x030B;
const unsigned short PMI_PART_TRANSFORM_TYPE = 0X030C;
const unsigned short PMI_CALLOUT_DIM_TYPE = 0X030D;
const unsigned short PMI_PARAMETER_DIM_TYPE = 0X030E;
const unsigned short PMI_CHAMFER_TYPE = 0x030F;
const unsigned short PMI_MVSTYLE_TYPE = 0x0310;
const unsigned short PMI_TABLE_TYPE = 0x0311;

#endif // JTK_PMI_ENUMS_H

