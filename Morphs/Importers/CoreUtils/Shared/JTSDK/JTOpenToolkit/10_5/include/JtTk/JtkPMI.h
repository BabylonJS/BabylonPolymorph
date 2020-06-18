////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PMI_H
#define JTK_PMI_H

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkString.h>
#include <JtTk/JtkPMIEnums.h>

#ifndef JTK_PMI_ENTITY_ACCESS
#define JTK_PMI_ENTITY_ACCESS
#endif

#ifndef JTK_PMI_CROSSHATCH_PATTERN_ACCESS
#define JTK_PMI_CROSSHATCH_PATTERN_ACCESS
#endif
//forward decs
class _JtkPMIEntityImpl;
class _JtkPMIMemberImpl;
class _JtkPMICrosshatchPatternImpl;
class _JtkPMIGenericImpl;
class _JtkPMIFolderImpl;
class _JtkPMIModelViewImpl;
class JtkPMIAnnotation;
class JtkPMICoordinateSystem;


///////%{
//
// Class          : JtkPMICrosshatchPattern
//
// Description    : A Class which contains the methods of a Crosshatch. A Crosshatch has the following properties:
//      <br/><b>rotate:</b>     Indicates whether or not the crosshatch pattern is rotated
//      <br/><b>pattern:</b>    The pattern used for the Crosshatch
//      <br/><b>spacing:</b>    The spacing between the lines in the Crosshatch, in metres
//      <br/><b>angle:</b>      The angle (in radians) of the lines in the crosshatch from the X direction for the symbol
//
//                     This is used by the JtkPMICrosshatch and JtkPMIRegions.
//
// Enums          : JtkPMICrossHatchPattern:
//                        PatternUNSET --
//                        PatternRUBBER --
//                        PatternLEAD --
//                        PatternUSER --
//                        PatternSTEEL --
//                        PatternBRASS --
//                        PatternSOLID --
//                        PatternIRON --
//                        PatternALUMINUM --
//                        PatternGLASS --
//                        PatternELECTRICALWINDING --
//                        PatternREFRACTORY --
//                        PatternTHERMALINSULATION --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkEntity > JtkPMICrosshatchPattern
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICrosshatchPattern : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkPMICrosshatchPattern )
   JTK_PMI_CROSSHATCH_PATTERN_ACCESS

private:
   _JtkPMICrosshatchPatternImpl*      _patternImpl;
   JtkPMICrosshatchPattern( JtkPMIAnnotation* PMIOwner );
   virtual ~JtkPMICrosshatchPattern( );

public:

   int getRotate( int& ) const;
   int setRotate( int );
   int unsetRotate( void );

   int getPattern( JtkPMICrossHatchPattern& ) const;
   int setPattern( JtkPMICrossHatchPattern );
   int unsetPattern( void );

   int getAngle( double& ) const;
   int setAngle( double );
   int unsetAngle( void );

   int getSpacing( double& ) const;
   int setSpacing( double );
   int unsetSpacing( void );
};

//////////////////////////////////////////////////////////////////
// JtkPMISubClasses
//////////////////////////////////////////////////////////////////

///////%{
//
// Class          : JtkPMIMember
//
// Description    : Base class for JtkPMI classes which are created
//                  as members/sub classes of the main JtkPMIEntity derived objects
//                  that do not exist independently
//
// Enums          : 
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkEntity > JtkPMIMember
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIMember : public JtkEntity
{
private:
   JTK_OBJECT_HEADER( JtkPMIMember )

   friend class JtkPMIAnnotationOutline;
   _JtkPMIMemberImpl*         _subImpl;

   JtkPMIMember( );
   virtual ~JtkPMIMember( );

   _JtkPMIMemberImpl* getImpl( ) const;
};

///////%{
//
// Class          : JtkPMIAnnotationOutlineStyle
//
// Description    : Specifies the style of an individual line of a box type outline
//                  It has the following properties:
//   <br/><b>colour:</b>     The colour of the line.
//   <br/><b>style:</b>      The line style of the line.
//   <br/><b>thickness:</b>  The thickness of the line.
//   <br/><b>width:</b>      The width of the line.
//
// Enums          :  JtkPMILineStyle:
//                     LineStyleUNSET --
//                     LineStyleLONGDASHED --
//                     LineStyleDOTTED --
//                     LineStyleDOTTEDDASHED --
//                     LineStylePHANTOM --
//                     LineStyleDASHED --
//                     LineStyleSOLID --
//                     LineStyleCENTRELINE --
//
//                   JtkPMITextLineThickness:
//                     TextThicknessNORMAL --
//                     TextThicknessTHICK --
//                     TextThicknessTHIN --
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIAnnotationOutlineStyle
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIAnnotationOutlineStyle : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIAnnotationOutlineStyle )

   JtkPMIAnnotationOutlineStyle( );
   virtual ~JtkPMIAnnotationOutlineStyle( );

public:

   int setColour( const JtkString& );
   int getColour( JtkString& ) const;
   int unsetColour( void );

   int setStyle( JtkPMILineStyle );
   int getStyle( JtkPMILineStyle& ) const;
   int unsetStyle( void );

   int setThickness( JtkPMITextLineThickness );
   int getThickness( JtkPMITextLineThickness& ) const;
   int unsetThickness( void );

   int setWidth( JtkWidthMeasurementType measurementType, double width );
   int setWidth( const JtkString& namedWidth );
   int getWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getWidth( JtkString& namedWidth ) const;
   int unsetWidth( );
};


///////%{
//
// Class          : JtkPMIAnnotationOutline
//
// Description    : Specifies the shape and style of an Annotation or Text Outline.
//                  It has the following properties:
//   <br/><b>type:</b>           One of "box", "triangle", "circle", "ellipse",
//                               "underline", etc. Note that "underline" refers to the place where the
//                               bottom edge of a "box" outline would be placed. It is not the same
//                               as underlining the text by means of underline = "true".
//   <br/><b>colour:</b>         The colour of the outline. Overridden by Top, Bottom,
//                               Left or Right.
//   <br/><b>style:</b>          The line style of the outline. Overridden by Top,
//                               Bottom, Left or Right.
//   <br/><b>thickness:</b>      The line thickness of the outline. Overridden by Top,
//                               Bottom, Left or Right.
//   <br/><b>width:</b>          The width of the outline. Overridden by Top,
//                               Bottom, Left or Right.
//   <br/><b>doubleOffset:</b>   The offset of any double outline in metres.
//   <br/><b>visible:</b>        Whether the line of the outline is visible. Often false
//                               if the outline is filled.
//   <br/>filled:</b>            Whether the outline is filled.
//   <br/>fillColour:</b>        The fill colour, if the outline is filled. Otherwise
//                               transparent.
//
//                  It has the following child content:
//   <br/><b>Top:</b>            The style of the top of a "box" outline. Overrides
//                               colour, style, thickness and width attributes.
//   <br/><b>Bottom:</b>         The style of the bottom of a "box" outline. Overrides
//                               colour, style, thickness and width attributes.
//   <br/><b>Left:</b>           The style of the left of a "box" outline. Overrides
//                               colour, style, thickness and width attributes.
//   <br/><b>Right:</b>          The style of the right of a "box" outline. Overrides
//                               colour, style, thickness and width attributes.
//
// Enums          :  JtkPMITextOutlineType:
//                        OutlineTypeBOX --
//                        OutlineTypeTRIANGLE --
//                        OutlineTypeCIRCLE --
//                        OutlineTypeELLIPSE --
//                        OutlineTypeUNDERLINE --
//                        OutlineTypeSQUARE --
//                        OutlineTypeSCOREDCIRCLE --
//                        OutlineTypeDIAMOND --
//                        OutlineTypeFLAGRIGHT --
//                        OutlineTypeFLAGLEFT --
//                        OutlineTypeFLAGBOTH --
//                        OutlineTypeOBLONG --
//                        OutlineTypeOBLONGRIGHT --
//                        OutlineTypeOBLONGLEFT --
//                        OutlineTypeSTICKING --
//                        OutlineTypeSET --
//                        OutlineTypeFIXEDSUPPORT --
//                        OutlineTypeNOTA --
//                        OutlineTypeSYMMETRICALPART --
//                        OutlineTypeSYMMETRICALSET --
//                        OutlineTypeSCOREDRECTANGLE --
//                        OutlineTypePARALLELOGRAM --
//
//                     JtkPMILineStyle:
//                     LineStyleUNSET --
//                     LineStyleLONGDASHED --
//                     LineStyleDOTTED --
//                     LineStyleDOTTEDDASHED --
//                     LineStylePHANTOM --
//                     LineStyleDASHED --
//                     LineStyleSOLID --
//                     LineStyleCENTRELINE --
//
//                   JtkPMITextLineThickness:
//                     TextThicknessNORMAL --
//                     TextThicknessTHICK --
//                     TextThicknessTHIN --
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIAnnotationOutline
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIAnnotationOutline : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIAnnotationOutline )
   friend class _JtkPMIGenericImpl;
   friend class JtkPMIText;

   JtkPMIAnnotationOutline( );
   virtual ~JtkPMIAnnotationOutline( );

public:
   int setType( JtkPMITextOutlineType outline );
   int getType( JtkPMITextOutlineType& outline ) const;
   int unsetType( );

   int setColour( const JtkString& );
   int getColour( JtkString& ) const;
   int unsetColour( void );

   int setStyle( JtkPMILineStyle );
   int getStyle( JtkPMILineStyle& ) const;
   int unsetStyle( void );

   int setThickness( JtkPMITextLineThickness );
   int getThickness( JtkPMITextLineThickness& ) const;
   int unsetThickness( void );

   int setWidth( JtkWidthMeasurementType measurementType, double width );
   int setWidth( const JtkString& namedWidth );
   int getWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getWidth( JtkString& namedWidth ) const;
   int unsetWidth( );

   int setDoubleOffset( double );
   int getDoubleOffset( double& ) const;
   int unsetDoubleOffset( );

   int setVisible( int );
   int getVisible( int& ) const;
   int unsetVisible( );

   int setFilled( int );
   int getFilled( int& ) const;
   int unsetFilled( );

   int setFillColour( const JtkString& );
   int getFillColour( JtkString& ) const;
   int unsetFillColour( );

   int addTop( JtkPMIAnnotationOutlineStyle*& );
   int getTop( JtkPMIAnnotationOutlineStyle*& ) const;
   int unsetTop( );

   int addBottom( JtkPMIAnnotationOutlineStyle*& );
   int getBottom( JtkPMIAnnotationOutlineStyle*& ) const;
   int unsetBottom( );

   int addLeft( JtkPMIAnnotationOutlineStyle*& );
   int getLeft( JtkPMIAnnotationOutlineStyle*& ) const;
   int unsetLeft( );

   int addRight( JtkPMIAnnotationOutlineStyle*& );
   int getRight( JtkPMIAnnotationOutlineStyle*& ) const;
   int unsetRight( );
};

///////%{
//
// Class          : JtkPMITextItem
//
// Description    : Class for the representation of a text item
//   <br/><b>string:</b>                     The content of the item.
//   <br/><b>symbol:</b>                     The symbol for the item.
//   <br/><b>lineweldSymbol:</b>             The lineweld for the item.
//   <br/><b>lineweldSupplementalSymbol:</b> The lineweldSupplementSymbol for the item.
//   <br/><b>format:</b>            The format of the item.
//   <br/><b>language:</b>          The language of the text item.
//   <br/><b>font:</b>              The font of the text item.
//   <br/><b>textHeight:</b>        The height of the text item.
//   <br/><b>textThickness:</b>     The thickness of lines representing the text item.
//   <br/><b>textLineWidth:</b>     The width of lines representing the text the text item.
//   <br/><b>textAspect:</b>        The ratio of textHeight to textWidth item.
//   <br/><b>textColour:</b>        The colour of the text item.
//   <br/><b>bold:</b>              Whether the text item is bold.
//   <br/><b>italic:</b>            Whether the text item is italic.
//   <br/><b>italicAngle:</b>       The angle of the italic on the text item.
//   <br/><b>strikethrough:</b>     Whether the text item is struck through.
//   <br/><b>subscript:</b>         Whether the text item is subscript.
//   <br/><b>underline:</b>         The underline of the text item.
//   <br/><b>justification:</b>     The justification of the text item.
//   <br/><b>spaceFactor:</b>       The space between letters of the text item.
//   <br/><b>lineFactor:</b>        The space between lines of the text item.
//   <br/><b>Outline:</b>           An JtkPMIAnnotationOutline specifying the outlining of the Item.
//
//   Each Item should have only 1 of string, symbol, lineweldSymbol or lineweldSuppliementSymbol. 
//
// Enums          :   JtkPMITextLineThickness:
//                        TextThicknessNORMAL --
//                        TextThicknessTHICK --
//                        TextThicknessTHIN --
//
//                     JtkPMIUnderline:
//                        UnderlineOVER --
//                        UnderlineUNDER --
//
//                     JtkPMIJustification:
//                        JustificationRIGHT --
//                        JustificationCENTRE --
//                        JustificationLEFT --
//                        JustificationTOPLEFT --
//                        JustificationTOPRIGHT --
//                        JustificationTOPCENTRE --
//                        JustificationBOTTOMLEFT --
//                        JustificationBOTTOMRIGHT --
//                        JustificationBOTTOMCENTRE --
//
//                     JtkPMITextSymbol:
//                        TextSymbolCENTRELINE --
//                        TextSymbolPARTINGLINE --
//                        TextSymbolDEPTH --
//                        TextSymbolCOUNTERSINK --
//                        TextSymbolCONICALTAPER --
//                        TextSymbolSLOPE --
//                        TextSymbolCOUNTERBORE --
//                        TextSymbolSQUARE --
//                        TextSymbolPHI --
//                        TextSymbolPLUSMINUS --
//                        TextSymbolDEGREES --
//                        TextSymbolBETWEEN --
//                        TextSymbolARCLENGTH --
//                        TextSymbolLEFTPARENTHESIS --
//                        TextSymbolRIGHTPARENTHESIS --
//                        TextSymbolPROJECTEDTOLERANCE --
//                        TextSymbolMMC --
//                        TextSymbolLMC --
//                        TextSymbolFREESTATE --
//                        TextSymbolOHM --
//                        TextSymbolCIRCULARRUNOUT --
//                        TextSymbolTOTALRUNOUT --
//                        TextSymbolPROFILEOFASURFACE --
//                        TextSymbolPROFILEOFALINE --
//                        TextSymbolFLATNESS --
//                        TextSymbolSTRAIGHTNESS --
//                        TextSymbolSYMMETRY --
//                        TextSymbolPERPENDICULARITY --
//                        TextSymbolPARALLELISM --
//                        TextSymbolCYLINDRICITY --
//                        TextSymbolCONCENTRICITY --
//                        TextSymbolCIRCULARITY --
//                        TextSymbolANGULARITY --
//                        TextSymbolMICRO --
//                        TextSymbolPOSITION --
//                        TextSymbolENVELOPE --
//                        TextSymbolRFS --
//                        TextSymbolTANGENTPLANE --
//                        TextSymbolLESSTHANOREQUAL --
//                        TextSymbolGREATERTHANOREQUAL --
//                        TextSymbolTHREADPREFIX --
//                        TextSymbolTRIANGLE --
//                        TextSymbolSTATISTICAL --
//                        TextSymbolRADIUS --
//                        TextSymbolCIRCLEDU --
//                        TextSymbolFITFUNCTION --
//                        TextSymbolSAFETYCOMPLIANCE --
//                        TextSymbolQUANTITY --
//                        TextSymbolINDEPENDENCY --
//                        TextSymbolCONTINUOUSFEATURE --
//                        TextSymbolSPOTFACE --
//                        TextSymbolSPHI -- 
//                        TextSymbolSPHERE -- 
//                        TextSymbolLEFTTAPER -- 
//                        TextSymbolRIGHTTAPER -- 
//                        TextSymbolLEFTPITCH -- 
//                        TextSymbolRIGHTPITCH -- 
//                        TextSymbolAPPROXIMATEDIMENSION -- 
//                        TextSymbolAXISINTERSECTION -- 
//                        TextSymbolESKDPERPENDICULAR -- 
//                        TextSymbolESKDPARALLEL --
//                        TextSymbolESKDCROSS --
//                        TextSymbolORIENTATIONCONSTRAINT --
//                        TextSymbolDATUMTRANSLATION --
//
//                      JtkPMILineWeldSymbol:
//                        LineWeldSymbolUNSET --
//                        LineWeldSymbolJISSEAM --
//                        LineWeldSymbolSINGLEBEVELGROOVE --
//                        LineWeldSymbolSINGLEUGROOVE --
//                        LineWeldSymbolEDGEFLANGE --
//                        LineWeldSymbolSURFACE --
//                        LineWeldSymbolSTEEPFLANKEDSINGLEBEVEL --
//                        LineWeldSymbolFLARESINGLEVGROOVE --
//                        LineWeldSymbolSURFACEJOINT --
//                        LineWeldSymbolSINGLEVGROOVE --
//                        LineWeldSymbolINCLINEDJOINT --
//                        LineWeldSymbolPLUG --
//                        LineWeldSymbolFILLET --
//                        LineWeldSymbolSQUAREGROOVE --
//                        LineWeldSymbolSPOT --
//                        LineWeldSymbolSINGLEJ --
//                        LineWeldSymbolSQUARE --
//                        LineWeldSymbolOVERLAY --
//                        LineWeldSymbolSINGLEU --
//                        LineWeldSymbolSINGLEJGROOVE --
//                        LineWeldSymbolDOUBLEFLANGE --
//                        LineWeldSymbolSINGLEFLANGE --
//                        LineWeldSymbolSPOTPROJECTED --
//                        LineWeldSymbolPLUGANDSLOT --
//                        LineWeldSymbolSINGLEBEVELBROADROOTFACE --
//                        LineWeldSymbolEDGE --
//                        LineWeldSymbolJISSTAGGEREDFILLET1 --
//                        LineWeldSymbolSINGLEV --
//                        LineWeldSymbolFLARESINGLEBEVELGROOVE --
//                        LineWeldSymbolSINGLEVBROADROOTFACE --
//                        LineWeldSymbolSTEEPFLANKEDSINGLEV --
//                        LineWeldSymbolREMOVABLEBACKINGSTRIP --
//                        LineWeldSymbolPERMANENTBACKINGSTRIP --
//                        LineWeldSymbolJISFILLET --
//                        LineWeldSymbolSINGLEBEVEL --
//                        LineWeldSymbolBACKING --
//                        LineWeldSymbolFOLDJOINT --
//                        LineWeldSymbolJISSTAGGEREDFILLET2 --
//                        LineWeldSymbolSEAM --
//                        LineWeldSymbolBEAD --
//                        LineWeldSymbolSTUD --
//                        LineWeldSymbolINTERMITTENT --
//                        LineWeldSymbolBACKINGPLATE --
//                        LineWeldSymbolMELTTHROUGH -- deprecated in favour of LineWeldSupplementalSymbolMELTTHROUGH
//                        LineWeldSymbolSOLDER --
//                        LineWeldSymbolKGROOVE --
//                        LineWeldSymbolSTAKE --
//                        LineWeldSymbolKEYHOLE --
//                        LineWeldSymbolJISPOT --
//                        LineWeldSymbolJISSPOTFLATELECTRODE --
//                        LineWeldSymbolESKDHEAT --
//                        LineWeldSymbolESKDSMOOTH --
//                        LineWeldSymbolESKDSTAGGERCHAIN --
//                        LineWeldSymbolESKDSTAGGERCHECK --
//                        LineWeldSymbolESKDNOTALLAROUND --
//                        LineWeldSymbolESKDDIAMETER --
//                        LineWeldSymbolESKDNUMBER --
//                        LineWeldSymbolISOEDGE --
//
//                     JtkPMILineWeldSupplementalSymbol:
//                        LineWeldSupplementalSymbolUNSET --
//                        LineWeldSupplementalSymbolCONVEX --
//                        LineWeldSupplementalSymbolTOESBLENDED --
//                        LineWeldSupplementalSymbolCONCAVE --
//                        LineWeldSupplementalSymbolFLUSH --
//                        LineWeldSupplementalSymbolPERMANENTBACKINGSTRIP --
//                        LineWeldSupplementalSymbolREMOVABLEBACKINGSTRIP --
//                        LineWeldSupplementalSymbolSTUD --
//                        LineWeldSupplementalSymbolINTERMITTENT --
//                        LineWeldSupplementalSymbolBACKING --
//                        LineWeldSupplementalSymbolBACKINGREMOVEAFTERWELD --
//                        LineWeldSupplementalSymbolSPACER --
//                        LineWeldSupplementalSymbolCONSUMABLEINSERT --
//                        LineWeldSupplementalSymbolFLUSHESKD --
//                        LineWeldSupplementalSymbolMACHININGGRADEDJUNCTION --
//                        LineWeldSupplementalSymbolSURFACEFINISHBASIC --
//                        LineWeldSupplementalSymbolSURFACEFINISHBASICCOMPLETE --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRR --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRRCOMPLETE --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRP --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRPCOMPLETE --
//                        LineWeldSupplementalSymbolMELTTHROUGH --
//
//                     JtkPMIUserValueDataType:
//                        UserValueDataTypeINT --
//                        UserValueDataTypeINTS --
//                        UserValueDataTypeREAL --
//                        UserValueDataTypeREALS --
//                        UserValueDataTypeBOOLEAN --
//                        UserValueDataTypeBOOLEANS --
//                        UserValueDataTypeSTRING --
//                        UserValueDataTypeREFERENCE --
//                        UserValueDataTypeENUM --
//                        UserValueDataTypeLIST --
//                        UserValueDataTypeDATETIME -- 
//                        UserValueDataTypeNONE -- 
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMITextItem
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITextItem : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITextItem )

   JtkPMITextItem( );
   virtual ~JtkPMITextItem( );

public:

   int setString( const JtkString& string );
   int getString( JtkString& string ) const;
   int unsetString( );

   int setSymbol( JtkPMITextSymbol symbol );
   int getSymbol( JtkPMITextSymbol& symbol ) const;
   int unsetSymbol( );

   int setLineWeldSymbol( JtkPMILineWeldSymbol symbol );
   int getLineWeldSymbol( JtkPMILineWeldSymbol& symbol ) const;
   int unsetLineWeldSymbol( );

   int setLineWeldSupplementalSymbol( JtkPMILineWeldSupplementalSymbol symbol );
   int getLineWeldSupplementalSymbol( JtkPMILineWeldSupplementalSymbol& symbol ) const;
   int unsetLineWeldSupplementalSymbol( );

   int setFormat( JtkPMIUserValueDataType format );
   int getFormat( JtkPMIUserValueDataType& format ) const;
   int unsetFormat( );

   int addOutline( JtkPMIAnnotationOutline*& );
   int getOutline( JtkPMIAnnotationOutline*& ) const;
   int unsetOutline( );

   int setLanguage( const JtkString& language );
   int getLanguage( JtkString& language ) const;
   int unsetLanguage( );

   int setFont( const JtkString& font );
   int getFont( JtkString& font ) const;
   int unsetFont( );

   int setTextHeight( double height );
   int getTextHeight( double& height ) const;
   int unsetTextHeight( );

   int setTextThickness( JtkPMITextLineThickness thickness );
   int getTextThickness( JtkPMITextLineThickness& thickness ) const;
   int unsetTextThickness( );

   int setTextLineWidth( JtkWidthMeasurementType measurementType, double width );
   int setTextLineWidth( const JtkString& namedWidth );
   int getTextLineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getTextLineWidth( JtkString& namedWidth ) const;
   int unsetTextLineWidth( );

   int setTextAspect( double aspect );
   int getTextAspect( double& aspect ) const;
   int unsetTextAspect( );

   int setTextColour( const JtkString& colour );
   int getTextColour( JtkString& colour ) const;
   int unsetTextColour( );

   int setBold( int isBold );
   int getBold( int& isBold ) const;
   int unsetBold( );

   int setItalic( int isItalic );
   int getItalic( int& isItalic ) const;
   int unsetItalic( );

   int setItalicAngle( double angle );
   int getItalicAngle( double& angle ) const;
   int unsetItalicAngle( );

   int setStrikethrough( JtkPMIStrikethrough );
   int getStrikethrough( JtkPMIStrikethrough& ) const;
   int unsetStrikethrough( );

   int setSubscript( JtkPMISubscript );
   int getSubscript( JtkPMISubscript& ) const;
   int unsetSubscript( );

   int setUnderline( JtkPMIUnderline underline );
   int getUnderline( JtkPMIUnderline& underline ) const;
   int unsetUnderline( );

   int setJustification( JtkPMIJustification justification );
   int getJustification( JtkPMIJustification& justification ) const;
   int unsetJustification( );

   int setSpaceFactor( double spaceFactor );
   int getSpaceFactor( double& spaceFactor ) const;
   int unsetSpaceFactor( );

   int setLineFactor( double lineFactor );
   int getLineFactor( double& lineFactor ) const;
   int unsetLineFactor( );
};

///////%{
//
// Class          : JtkPMIText
//
// Description    : Class for the representation of text on PMI.
//   <br/><b>name:</b>              The name for the text.
//   <br/><b>outlineType:</b>       The outline around the text. (deprecated)
//   <br/><b>outlineColour:</b>     The colour of the outline around the text. (deprecated)
//   <br/><b>outlineStyle:</b>      The style of the outline around the text. (deprecated)
//   <br/><b>outlineThickness:</b>  The thickness of the outline around the text. (deprecated)
//   <br/><b>outlineWidth:</b>      The width of the outline around the text. (deprecated)
//   <br/><b>orientation:</b>       The orientation of the text.
//   <br/><b>language:</b>          The language of the text.
//   <br/><b>font:</b>              The font of the text.
//   <br/><b>textHeight:</b>        The height of the text.
//   <br/><b>textThickness:</b>     The thickness of lines representing the text.
//   <br/><b>textLineWidth:</b>     The width of lines representing the text.
//   <br/><b>textAspect:</b>        The ratio of textHeight to textWidth.
//   <br/><b>textColour:</b>        The colour of the text.
//   <br/><b>bold:</b>              Whether the text is bold.
//   <br/><b>italic:</b>            Whether the text is italic.
//   <br/><b>italicAngle:</b>       The angle of the italic on the text.
//   <br/><b>strikethrough:</b>     Whether the text is struck through.
//   <br/><b>subscript:</b>         Whether the text is subscript.
//   <br/><b>underline:</b>         The underline of the text.
//   <br/><b>justification:</b>     The text justification.
//   <br/><b>spaceFactor:</b>       The space between letters.
//   <br/><b>lineFactor:</b>        The space between lines.
//   <br/><b>maxExtend:</b>         Whether any underlining extends to the full length of
//                                  the longest item of text of an Annotation.
//   <br/><b>Outline:</b>           An JtkPMIAnnotationOutline specifying the outlining of the text.
//   <br/><b>Item:</b>              One or more JtkPMITextItems.
//
// Enums          :   JtkPMITextOutlineType:
//                        OutlineTypeBOX --
//                        OutlineTypeTRIANGLE --
//                        OutlineTypeCIRCLE --
//                        OutlineTypeELLIPSE --
//                        OutlineTypeUNDERLINE --
//                        OutlineTypeSQUARE --
//                        OutlineTypeSCOREDCIRCLE --
//                        OutlineTypeDIAMOND --
//                        OutlineTypeFLAGRIGHT --
//                        OutlineTypeFLAGLEFT --
//                        OutlineTypeFLAGBOTH --
//                        OutlineTypeOBLONG --
//                        OutlineTypeOBLONGRIGHT --
//                        OutlineTypeOBLONGLEFT --
//                        OutlineTypeSTICKING --
//                        OutlineTypeSET --
//                        OutlineTypeFIXEDSUPPORT --
//                        OutlineTypeNOTA --
//                        OutlineTypeSYMMETRICALPART --
//                        OutlineTypeSYMMETRICALSET --
//                        OutlineTypeSCOREDRECTANGLE --
//                        OutlineTypePARALLELOGRAM --
//
//                     JtkPMITextLineThickness:
//                        TextThicknessNORMAL --
//                        TextThicknessTHICK --
//                        TextThicknessTHIN --
//
//                     JtkPMIUnderline:
//                        UnderlineOVER --
//                        UnderlineUNDER --
//
//                     JtkPMIJustification:
//                        JustificationRIGHT --
//                        JustificationCENTRE --
//                        JustificationLEFT --
//                        JustificationTOPLEFT --
//                        JustificationTOPRIGHT --
//                        JustificationTOPCENTRE --
//                        JustificationBOTTOMLEFT --
//                        JustificationBOTTOMRIGHT --
//                        JustificationBOTTOMCENTRE --
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIText
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIText : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIText )

   JtkPMIText( );
   virtual ~JtkPMIText( );

public:
   int setName( const JtkString& name );
   int getName( JtkString& name ) const;
   int unsetName( );

   int setOutlineType( JtkPMITextOutlineType outline );
   int getOutlineType( JtkPMITextOutlineType& outline ) const;
   int unsetOutlineType( );

   int setOutlineColour( const JtkString& );
   int getOutlineColour( JtkString& ) const;
   int unsetOutlineColour( void );

   int setOutlineStyle( JtkPMILineStyle );
   int getOutlineStyle( JtkPMILineStyle& ) const;
   int unsetOutlineStyle( void );

   int setOutlineThickness( JtkPMITextLineThickness );
   int getOutlineThickness( JtkPMITextLineThickness& ) const;
   int unsetOutlineThickness( void );

   int setOutlineWidth( JtkWidthMeasurementType measurementType, double width );
   int setOutlineWidth( const JtkString& namedWidth );
   int getOutlineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getOutlineWidth( JtkString& namedWidth ) const;
   int unsetOutlineWidth( );

   int addOutline( JtkPMIAnnotationOutline*& );
   int getOutline( JtkPMIAnnotationOutline*& ) const;
   int unsetOutline( );

   int setOrientation( JtkPMITextOrientationType orientation );
   int getOrientation( JtkPMITextOrientationType& orientation ) const;
   int unsetOrientation( );

   int setLanguage( const JtkString& language );
   int getLanguage( JtkString& language ) const;
   int unsetLanguage( );

   //The setFont function should input the name of the font, this name should correspond to iFont in the VisualTextData
   int setFont( const JtkString& font );
   int getFont( JtkString& font ) const;
   int unsetFont( );

   int setTextHeight( double height );
   int getTextHeight( double& height ) const;
   int unsetTextHeight( );

   int setTextThickness( JtkPMITextLineThickness thickness );
   int getTextThickness( JtkPMITextLineThickness& thickness ) const;
   int unsetTextThickness( );

   int setTextLineWidth( JtkWidthMeasurementType measurementType, double width );
   int setTextLineWidth( const JtkString& namedWidth );
   int getTextLineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getTextLineWidth( JtkString& namedWidth ) const;
   int unsetTextLineWidth( );

   int setTextAspect( double aspect );
   int getTextAspect( double& aspect ) const;
   int unsetTextAspect( );

   int setTextColour( const JtkString& colour );
   int getTextColour( JtkString& colour ) const;
   int unsetTextColour( );

   int setBold( int isBold );
   int getBold( int& isBold ) const;
   int unsetBold( );

   int setItalic( int isItalic );
   int getItalic( int& isItalic ) const;
   int unsetItalic( );

   int setItalicAngle( double angle );
   int getItalicAngle( double& angle ) const;
   int unsetItalicAngle( );

   int setStrikethrough( JtkPMIStrikethrough );
   int getStrikethrough( JtkPMIStrikethrough& ) const;
   int unsetStrikethrough( void );

   int setSubscript( JtkPMISubscript );
   int getSubscript( JtkPMISubscript& ) const;
   int unsetSubscript( void );

   int setUnderline( JtkPMIUnderline underline );
   int getUnderline( JtkPMIUnderline& underline ) const;
   int unsetUnderline( );

   int setJustification( JtkPMIJustification justification );
   int getJustification( JtkPMIJustification& justification ) const;
   int unsetJustification( );

   int setSpaceFactor( double spaceFactor );
   int getSpaceFactor( double& spaceFactor ) const;
   int unsetSpaceFactor( );

   int setLineFactor( double lineFactor );
   int getLineFactor( double& lineFactor ) const;
   int unsetLineFactor( );

   int setMaxExtend( int maxExtend );
   int getMaxExtend( int& maxExtend ) const;
   int unsetMaxExtend( );

   //The addItem( const JtkString& string ) when a string is supplied sets the same string as the setItemString method.
   int addItem( JtkPMITextItem*&, const JtkString& string = JtkString( ) );
   int addItem( const JtkString& string = JtkString( ) );
   int numItem( int& number ) const;
   int getItem( int index, JtkPMITextItem*& ) const;
   int unsetItem( int index );

   //below is deprecated in favour of accessing via JtkPMITextItem
   int setItemString( int index, const JtkString& string );
   int getItemString( int index, JtkString& string ) const;
   int unsetItemString( int index );

   int setItemFormat( int index, JtkPMIUserValueDataType format );
   int getItemFormat( int index, JtkPMIUserValueDataType& format ) const;
   int unsetItemFormat( int index );

   int setItemSymbol( int index, JtkPMITextSymbol symbol );
   int getItemSymbol( int index, JtkPMITextSymbol& symbol ) const;
   int unsetItemSymbol( int index );

   int setItemOutlineType( int index, JtkPMITextOutlineType outline );
   int getItemOutlineType( int index, JtkPMITextOutlineType& outline ) const;
   int unsetItemOutlineType( int index );

   int setItemOutlineColour( int index, const JtkString& );
   int getItemOutlineColour( int index, JtkString& ) const;
   int unsetItemOutlineColour( int index );

   int setItemOutlineStyle( int index, JtkPMILineStyle );
   int getItemOutlineStyle( int index, JtkPMILineStyle& ) const;
   int unsetItemOutlineStyle( int index );

   int setItemOutlineThickness( int index, JtkPMITextLineThickness );
   int getItemOutlineThickness( int index, JtkPMITextLineThickness& ) const;
   int unsetItemOutlineThickness( int index );

   int setItemOutlineWidth( int index, JtkWidthMeasurementType measurementType, double width );
   int setItemOutlineWidth( int index, const JtkString& namedWidth );
   int getItemOutlineWidth( int index, JtkWidthMeasurementType measurementType, double& width ) const;
   int getItemOutlineWidth( int index, JtkString& namedWidth ) const;
   int unsetItemOutlineWidth( int index );

   int addItemOutline( int index, JtkPMIAnnotationOutline*& );
   int getItemOutline( int index, JtkPMIAnnotationOutline*& ) const;
   int unsetItemOutline( int index );

   int setItemLanguage( int index, const JtkString& language );
   int getItemLanguage( int index, JtkString& language ) const;
   int unsetItemLanguage( int index );

   int setItemFont( int index, const JtkString& font );
   int getItemFont( int index, JtkString& font ) const;
   int unsetItemFont( int index );

   int setItemTextHeight( int index, double height );
   int getItemTextHeight( int index, double& height ) const;
   int unsetItemTextHeight( int index );

   int setItemTextThickness( int index, JtkPMITextLineThickness thickness );
   int getItemTextThickness( int index, JtkPMITextLineThickness& thickness ) const;
   int unsetItemTextThickness( int index );

   int setItemTextLineWidth( int index, JtkWidthMeasurementType measurementType, double width );
   int setItemTextLineWidth( int index, const JtkString& namedWidth );
   int getItemTextLineWidth( int index, JtkWidthMeasurementType measurementType, double& width ) const;
   int getItemTextLineWidth( int index, JtkString& namedWidth ) const;
   int unsetItemTextLineWidth( int index );

   int setItemTextAspect( int index, double aspect );
   int getItemTextAspect( int index, double& aspect ) const;
   int unsetItemTextAspect( int index );

   int setItemTextColour( int index, const JtkString& colour );
   int getItemTextColour( int index, JtkString& colour ) const;
   int unsetItemTextColour( int index );

   int setItemBold( int index, int isBold );
   int getItemBold( int index, int& isBold ) const;
   int unsetItemBold( int index );

   int setItemItalic( int index, int isItalic );
   int getItemItalic( int index, int& isItalic ) const;
   int unsetItemItalic( int index );

   int setItemItalicAngle( int index, double angle );
   int getItemItalicAngle( int index, double& angle ) const;
   int unsetItemItalicAngle( int index );

   int setItemStrikethrough( int index, JtkPMIStrikethrough );
   int getItemStrikethrough( int index, JtkPMIStrikethrough& ) const;
   int unsetItemStrikethrough( int index );

   int setItemSubscript( int index, JtkPMISubscript );
   int getItemSubscript( int index, JtkPMISubscript& ) const;
   int unsetItemSubscript( int index );

   int setItemUnderline( int index, JtkPMIUnderline underline );
   int getItemUnderline( int index, JtkPMIUnderline& underline ) const;
   int unsetItemUnderline( int index );

   int setItemJustification( int index, JtkPMIJustification justification );
   int getItemJustification( int index, JtkPMIJustification& justification ) const;
   int unsetItemJustification( int index );

   int setItemSpaceFactor( int index, double spaceFactor );
   int getItemSpaceFactor( int index, double& spaceFactor ) const;
   int unsetItemSpaceFactor( int index );

   int setItemLineFactor( int index, double lineFactor );
   int getItemLineFactor( int index, double& lineFactor ) const;
   int unsetItemLineFactor( int index );
};

///////%{
//
// Class          : JtkPMITextFormat
//
// Description    : Class for the representation of text on PMI.
//   <br/><b>language:</b>          The language of the text.
//   <br/><b>font:</b>              The font of the text.
//   <br/><b>textHeight:</b>        The height of the text.
//   <br/><b>textThickness:</b>     The thickness of lines representing the text.
//   <br/><b>textLineWidth:</b>     The width of lines representing the text.
//   <br/><b>textAspect:</b>        The ratio of textHeight to textWidth.
//   <br/><b>textColour:</b>        The colour of the text.
//   <br/><b>bold:</b>              Whether the text is bold.
//   <br/><b>italic:</b>            Whether the text is italic.
//   <br/><b>italicAngle:</b>       The angle of the italic on the text.
//   <br/><b>strikethrough:</b>     Whether the text is struck through.
//   <br/><b>subscript:</b>         Whether the text is subscript.
//   <br/><b>underline:</b>         The underline of the text.
//   <br/><b>justification:</b>     The text justification.
//   <br/><b>spaceFactor:</b>       The space between letters.
//   <br/><b>lineFactor:</b>        The space between lines.
//   <br/><b>Item:</b>              If supplied these items identify the specific 
//                                  characters and symbols the formatting override applies.
//                                  If none then the override applies to all the characters and symbols
//                                  in scope for the format.
//
// Enums          :    JtkPMITextLineThickness:
//                        TextThicknessNORMAL --
//                        TextThicknessTHICK --
//                        TextThicknessTHIN --
//
//                     JtkPMIUnderline:
//                        UnderlineOVER --
//                        UnderlineUNDER --
//
//                     JtkPMIJustification:
//                        JustificationRIGHT --
//                        JustificationCENTRE --
//                        JustificationLEFT --
//                        JustificationTOPLEFT --
//                        JustificationTOPRIGHT --
//                        JustificationTOPCENTRE --
//                        JustificationBOTTOMLEFT --
//                        JustificationBOTTOMRIGHT --
//                        JustificationBOTTOMCENTRE --
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMITextFormat
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITextFormat : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITextFormat )

   JtkPMITextFormat( );
   virtual ~JtkPMITextFormat( );

public:
   int setLanguage( const JtkString& language );
   int getLanguage( JtkString& language ) const;
   int unsetLanguage( );

   int setFont( const JtkString& font );
   int getFont( JtkString& font ) const;
   int unsetFont( );

   int setTextHeight( double height );
   int getTextHeight( double& height ) const;
   int unsetTextHeight( );

   int setTextThickness( JtkPMITextLineThickness thickness );
   int getTextThickness( JtkPMITextLineThickness& thickness ) const;
   int unsetTextThickness( );

   int setTextLineWidth( JtkWidthMeasurementType measurementType, double width );
   int setTextLineWidth( const JtkString& namedWidth );
   int getTextLineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getTextLineWidth( JtkString& namedWidth ) const;
   int unsetTextLineWidth( );

   int setTextAspect( double aspect );
   int getTextAspect( double& aspect ) const;
   int unsetTextAspect( );

   int setTextColour( const JtkString& colour );
   int getTextColour( JtkString& colour ) const;
   int unsetTextColour( );

   int setBold( int isBold );
   int getBold( int& isBold ) const;
   int unsetBold( );

   int setItalic( int isItalic );
   int getItalic( int& isItalic ) const;
   int unsetItalic( );

   int setItalicAngle( double angle );
   int getItalicAngle( double& angle ) const;
   int unsetItalicAngle( );

   int setStrikethrough( JtkPMIStrikethrough );
   int getStrikethrough( JtkPMIStrikethrough& ) const;
   int unsetStrikethrough( void );

   int setSubscript( JtkPMISubscript );
   int getSubscript( JtkPMISubscript& ) const;
   int unsetSubscript( void );

   int setUnderline( JtkPMIUnderline underline );
   int getUnderline( JtkPMIUnderline& underline ) const;
   int unsetUnderline( );

   int setJustification( JtkPMIJustification justification );
   int getJustification( JtkPMIJustification& justification ) const;
   int unsetJustification( );

   int setSpaceFactor( double spaceFactor );
   int getSpaceFactor( double& spaceFactor ) const;
   int unsetSpaceFactor( );

   int setLineFactor( double lineFactor );
   int getLineFactor( double& lineFactor ) const;
   int unsetLineFactor( );

   int addItem( JtkPMITextItem*&, const JtkString& string = JtkString( ) );
   int numItem( int& number ) const;
   int getItem( int index, JtkPMITextItem*& ) const;
   int unsetItem( int index );
};

///////%{
//
// Class          : JtkPMIDimensionText
//
// Description    : Class for the representation of a text positioned around a PMI.
//   <br/><b>position:</b>          The position around the main PMI content
//   <br/><b>Text:</b>              The text at that position.
//
// Enums          :    JtkPMIDimensionPlacement:
//                        PlacementBEFORE --
//                        PlacementABOVE --
//                        PlacementBELOW --
//                        PlacementAFTER --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIDimensionText
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIDimensionText : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIDimensionText )

   JtkPMIDimensionText( );
   virtual ~JtkPMIDimensionText( );

public:
   int getPosition( JtkPMIDimensionPlacement& ) const;
   int setPosition( JtkPMIDimensionPlacement );
   int unsetPosition( );

   int getText( JtkPMIText*& ) const;
   int addText( JtkPMIText*& );
   int unsetText( );

};

///////%{
//
// Class          : JtkPMIEntity
//
// Description    :   Base class for the creation of JtkPMIEntities.
//                     It has the following properties:
//                        <br/><b>name:</b>               descriptive or display name
//
//                     Additional functionality :
//                        <br/><b>validate:</b>          method which checks that the PMI has all the expected required fields
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkRefCounted > JtkPMIEntity
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIEntity : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkPMIEntity )
   JTK_PMI_ENTITY_ACCESS
protected:
   _JtkPMIEntityImpl* _impl;

   JtkPMIEntity( );
   virtual ~JtkPMIEntity( );

public:
   int getName( JtkString& ) const;
   int setName( const JtkString& );

   int getId( ) const;
   int setId( const int id );

   int getCadType( ) const;

   int validate( ) const;

   int numProperties( ) const;
};

///////%{
//
// Class          : JtkPMIGenericEntity
//
// Description    : JtkPMIGenericEntity is the base class for general PMI.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIEntity > JtkPMIGenericEntity
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIGenericEntity : public JtkPMIEntity
{
   JTK_OBJECT_HEADER( JtkPMIGenericEntity )
   _JtkPMIGenericImpl* getImpl( ) const;
   void setImpl( _JtkPMIGenericImpl* );

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIGenericEntity( JtkUnitHierarchy* owner );
   virtual ~JtkPMIGenericEntity( );

public:
   int setVisualValidity( int nValid );
   int getVisualValidity( int& nValid )const;

   int getPMIType( int& nPmiType, JtkString& sPmiTypeName )const;
   int getParentPMIType( int& nPmiType, JtkString& sPmiTypeName )const;

   int getAttrProperty( int index, JtkString& key, JtkString& value, int& hidden ) const;
   int addAttrProperty( const JtkString& key, const JtkString& value, int hidden = 0 );
};

///////%{
//
// Class          : JtkPMIFolder
//
// Description    : JtkPMIFolder is the base class for design group and viewset pmi.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIEntity > JtkPMIFolder
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFolder : public JtkPMIEntity
{
   JTK_OBJECT_HEADER( JtkPMIFolder )
   _JtkPMIFolderImpl* getImpl( ) const;
   void setImpl( _JtkPMIFolderImpl* );
protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIFolder( JtkUnitHierarchy* owner );
   virtual ~JtkPMIFolder( );

public:
   int getDGProperty( int index, JtkString& key, JtkString& value, JtkString& description ) const;
   int addDGProperty( const JtkString& key, const JtkString& value, const JtkString& description = JtkString( ) );
};

///////%{
//
// Class          : JtkPMIVisualEntity
//
// Description    : JtkPMIVisualEntity is the base class for PMI with a visual component.
//                  It has the following properties:
//      <br/><b>VisualTextData:</b>                   Allows for the addition of Prim2dTextData to the PMI.
//      <br/><b>VisualTextPolyLineData:</b>           Allows for the addition of PolylineData to the Prim2dText data on the PMI.
//      <br/><b>VisualPolyLineData:</b>               Allows for the addition of PolylineData to the PMI.
//      <br/><b>VisualPolygonData:</b>                Allows for the addition of PolygonData to the PMI.
//      <br/><b>VisualFrame:</b>                      Allows the addition of PMIBasicAttr.ar2dFrame data to the PMI to represent a display plane.
//                                                    The default values for the origin, the bottom right corner, and the top left corner are
//                                                    (0,0,0), (1,0,0), and (0,0,1) respectively.
//      <br/><b>VisualTextHeight:</b>                 Set the text height for displaying flat to screen.
//      <br/><b>VisualValidity:</b>                   Sets the validity for the PMI.
//      <br/><b>Reference:</b>                        Specifies the entities the PMI refers to.
//                  In order for any PMI derived from this to have a visual component one
//                  of the following functions needs to be called addVisualTextData, setVisualPolylineData
//                  or setVisualPolygonData the functions that set properties on the PMI do not create a display.
//
// Enums          : JtkPMIPolylineStyle : line style to apply to polyline segments
//                   SolidStyle -- solid style
//                   DashedStyle -- dashed style
//                   DottedStyle -- dotted style
//                   DashedDotted -- dashed dotted style
//                   DashedDottedDotted -- dashed dotted dotted style
//                   LongDashed -- long dashed style
//                   CenterDashed -- center dashed style
//                   CenterDashedDashed -- center dashed dashed style
//                   Invisible -- invisible style
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIGenericEntity > JtkPMIVisualEntity
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIVisualEntity : public JtkPMIGenericEntity
{
   JTK_OBJECT_HEADER( JtkPMIVisualEntity )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIVisualEntity( JtkUnitHierarchy* owner );
   virtual ~JtkPMIVisualEntity( );

public:
   int setVisualPolylineData( int polyDim, int primIndexLength, int polyTypesLength, const int* primIndices, const int* polyTypes, const double* polylines, int polyWidthsLength = 0, const int* polyWidths = NULL );
   int getVisualPolylineData( int& polyDim, int& primIndexLength, int& polyTypesLength, int*& primIndices, int*& polyTypes, double*& polylines ) const;
   int getVisualPolylineData( int& polyDim, int& primIndexLength, int& polyTypesLength, int& polyWidthsLength,
                              int*& primIndices, int*& polyTypes, int*& polyWidths, double*& polylines ) const;
   int unsetVisualPolylineData( );

   int setVisualPolylines( int dimension, int indicesLength, int typesLength,
                           int* indices, int* types, double* vertices,
                           int* widths = NULL, JtkPMIPolylineStyle* styles = NULL, int numColourComponent = 3, double* colours = NULL );

   int getVisualPolylines( int &dimension, int &indicesLength, int& typesLength,
                           int*& indices, int*& types, double*& vertices,
                           int*& widths, JtkPMIPolylineStyle*& styles, int& numColourComponent, double*& colours ) const;
   int unsetVisualPolylines( );

   int addVisualTextData( const JtkString& scString, double arTxtBox[6], int iFont, double rSlant, int iOrient );
   int addVisualTextData( const JtkString& scString, double arTxtBox[6], int iFont, double rSlant, int iOrient, double colour[4] );
   int getVisualTextData( int index, JtkString& scString, double arTxtBox[6], int& iFont, double& rSlant, int& iOrient ) const;
   int getVisualTextData( int index, JtkString& scString, double arTxtBox[6], int& iFont, double& rSlant, int& iOrient, double colour[4] ) const;
   int numVisualTextData( int& number ) const;
   int unsetVisualTextData( int index );

   int setVisualTextDataPolyline( int index, int polyDim, int primIndexLength, int polyTypesLength, const int* primIndices, const int* polyTypes, const double* polylines );
   int getVisualTextDataPolyline( int index, int& polyDim, int& primIndexLength, int& polyTypesLength, int*& primIndices, int*& polyTypes, double*& polylines ) const;
   int unsetVisualTextDataPolyline( int index );

   int setVisualPolygonData( int dim, int primIndexLength, int primTypeLength, int iNumVertices,
                             int* primTypes, int* primIndices, int* vertIndices,
                             bool normalBinding, bool colorBinding, bool texcoordBinding,
                             float* pgVertices, float* pgNormals, float* pgColors, float* pgTexcoords );
   int getVisualPolygonData( int& dim, int& primIndexLength, int& primTypeLength, int& iNumVertices,
                             int*& primTypes, int*& primIndices, int*& vertIndices,
                             bool& normalBinding, bool& colorBinding, bool& texcoordBinding,
                             float*& pgVertices, float*& pgNormals, float*& pgColors, float*& pgTexcoords ) const;
   int getVisualPolygonDataOutline( int& polyDim,
                                    int& nLines,
                                    int*& indices,
                                    float*& vertices ) const;
   int unsetVisualPolygonData( );

   int setVisualFrame( double origin[3], double bottomRight[3], double topLeft[3] );
   int getVisualFrame( double origin[3], double bottomRight[3], double topLeft[3] ) const;
   int unsetVisualFrame( void );

   int setVisualTextHeight( float dTextHeight );
   int getVisualTextHeight( float& dTextHeight )const;

   int numReference( int& ) const;
   int addReference( int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int addReference( const JtkPMIReference&, int reason = -1, int origin = 0 );
   int getReference( int, int& dstId, int& dstType, JtkString& path ) const;
   int getReference( int, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int getReference( int, JtkPMIReference& des, int& reason, int& origin ) const;
   int unsetReference( int );

   int setShowFlatToScreenOnly( int flatToScreenOnly );
   int getShowFlatToScreenOnly( int& flatToScreenOnly ) const;

   int setUseNameAsAnnotation( int useName );
   int getUseNameAsAnnotation( int& useName ) const;

   int getVisualColour(JtkString& textBackgroundColour, JtkString& textForegroundColour, JtkString& geometryColour) const;
   int setVisualColour(const JtkString& textBackgroundColour, const JtkString& textForegroundColour, const JtkString& geometryColour);

   int getVisualOpacity(unsigned int& inPlaneOpacity, unsigned int& flatToScreenOpacity) const;
   int setVisualOpacity(const unsigned int& inPlaneOpacity = 0, const unsigned int& flatToScreenOpacity = 100);
};

///////%{
//
// Class          : JtkPMIAnnotation
//
// Description    :   JtkPMIAnnotation is the base class for Annotation PMI.
//                     It has the following properties:
//      <br/><b>Description:</b>                      Readable textual description of the element.
//      <br/><b>accountabilityId:</b>
//      <br/><b>group:</b>                            This is an application specific type used as part of a
//                                                    classification scheme for the annotations.
//      <br/><b>usage:</b>                            used to indicate a usage other than that expected.
//      <br/><b>uriRefs:</b>                          associated URI references
//      <br/><b>SafetyClassification:</b>             This is an application specific type used to indicate the
//                                                    importance of an annotation, e.g. minor, major, critical.
//      <br/><b>ValueToCustomer:</b>                  This is an application specific type used to indicate the
//                                                    value of an annotation to a customer, e.g. "critical to
//                                                    quality".
//      <br/><b>Keyword:</b>                          a keyword string (may contain spaces).
//      <br/><b>blanked:</b>                          true if the PMI's Display is marked as not to be displayed at the moment.
//      <br/><b>units:</b>                            specifies which units lengths will be displayed in. (DEPRECATED in favour of <b>unit</b>)
//      <br/><b>symbolColour:</b>                     colour of the lines in the symbol.
//      <br/><b>textOrigin:</b>                       3D vector describing the location of the top left corner of the text window
//                                                    in model space, in metres.
//      <br/><b>textDirection:</b>                    3D direction of the text, in the display plane.
//      <br/><b>attachmentType:</b>                   method of display (leader, stacked, as a radial dimension, etc )
//      <br/><b>valid:</b>                            Whether the PMI is valid, invalid or unknown at
//                                                    the time of export.
//      <br/><b>commaAsDecimal:</b>                   Whether the decimal separator is represented by a
//                                                    full-stop or a comma.
//      <br/><b>flag:</b>                             Whether any Leader sub-elements attach to the Annotation
//                                                    as flags.
//      <br/><b>unit:</b>                             Specifies the measurement unit of the PMI.
//      <br/><b>outlineType:</b>                      The outline around the annotation. (deprecated)
//      <br/><b>outlineColour:</b>                    The colour of the outline around the annotation. (deprecated)
//      <br/><b>outlineStyle:</b>                     The style of the outline around the annotation. (deprecated)
//      <br/><b>outlineThickness:</b>                 The thickness of the outline around the annotation. (deprecated)
//      <br/><b>outlineWidth:</b>                     The width of the outline around the annotation. (deprecated)
//      <br/><b>language:</b>                         The language of the text.
//      <br/><b>font:</b>                             The font of the text.
//      <br/><b>textHeight:</b>                       The height of the text.
//      <br/><b>textThickness:</b>                    The thickness of lines representing the text.
//      <br/><b>textLineWidth:</b>                    The width of lines representing the text the text.
//      <br/><b>textAspect:</b>                       The ratio of textHeight to textWidth.
//      <br/><b>textColour:</b>                       The colour of the text.
//      <br/><b>bold:</b>                             Whether the text is bold.
//      <br/><b>italic:</b>                           Whether the text is italic.
//      <br/><b>italicAngle:</b>                      The angle of the italic on the text.
//      <br/><b>strikethrough:</b>                    Whether the text is struck through.
//      <br/><b>subscript:</b>                        Whether the text is subscript.
//      <br/><b>underline:</b>                        The underline of the text.
//      <br/><b>justification:</b>                    The text justification.
//      <br/><b>spaceFactor:</b>                      The space between letters.
//      <br/><b>lineFactor:</b>                       The space between lines.
//      <br/><b>prime:</b>                            Whether the Annotation is displayed by virtue of it
//                                                    referencing "prime" or "reference" geometry (default true).
//      <br/><b>originAnchor:</b>                     The point that the origin attribute on the DisplayPlane
//                                                    sub-element defines.
//      <br/><b>panZoom:</b>                          If flat to screen, panZoom indicates whether the annotation participates in pan + zoom operations.
//      <br/><b>textRotationPoint:</b>                Specifies the location of the text rotation point in model space in metres.
//                                                    As the user rotates the Annotation in a view, a viewing application may rotate
//                                                    its text about one or two axes to ensure it remains readable. Those axes pass through the 
//                                                    text rotation point and lie parallel with the X axis or the Y axis of the display plane.
//      <br/><b>Leader:</b>                           Zero or more leader-line specifications.
//      <br/><b>FeatureIdentification:</b>            Information about the feature identified by the PMI.
//      <br/><b>GeneralAttribute:</b>                 Nonspecific user attributes.
//      <br/><b>RevisionModifier:</b>                 Application-specific meta-data relating to the revision.
//      <br/><b>Outline:</b>                          An JtkPMIAnnotationOutline specifying the outlining of the component.
//      <br/><b>TextFormat:</b>                       Formatting attributes for special characters and symbols. Applies generally to all text fields.
//      <br/><b>stackFactor:</b>                      The gap to the target annotation in the direction of the stack as a factor of textHeight.
//                                                    Relevant only if attachmentType is stacked(below), stackedLeft, stackedRight or stackedAbove.
//
//      Each leader can have the following properties:
//         <br/><b>Reference:</b>                     Contains the details of the Reference that the Leader links with. Should correspond to a reference added via the addReference method.
//         <br/><b>tParm:</b>                         t-parameter on the referenced edge or curve, if applicable
//         <br/><b>uvParms:</b>                       u,v-parameters on the referenced face or surface, if applicable
//         <br/><b>terminator:</b>                    3D position of the end of the leader.
//         <br/><b>stubLength:</b>                    length of first segment of leader (metres)
//         <br/><b>colour:</b>                        leader colour
//         <br/><b>lineType:</b>                      solid, dashed, dotted, etc
//         <br/><b>thickness:</b>                     thin, normal or thick
//         <br/><b>arrowType:</b>                     shape of arrowhead
//         <br/><b>arrowColour:</b>                   colour of arrowhead
//         <br/><b>arrowLineType:</b>                 solid, dashed, dotted etc
//         <br/><b>arrowThickness:</b>                thin, normal or thick
//         <br/><b>arrowAngle:</b>                    total angle, in radians, at tip of arrow (0 to pi)
//         <br/><b>arrowLength:</b>                   length of the arrow
//         <br/><b>dotDiameter:</b>                   diameter of dot, in metres, if applicable
//         <br/><b>arrowPlacement:</b>                in, or out. Refers to arrows inside or outside extension lines
//         <br/><b>arrowOutsideLength:</b>            length of segment of leader on outside arrows
//         <br/><b>lineTextGap:</b>                   gap (metres) between text and start of leader
//         <br/><b>extensionLineGap:</b>              gap (metres) between extension line and model geometry
//         <br/><b>extensionLineExtension:</b>        length of the portion of the extension line which extends beyond the dimension line
//         <br/><b>extensionColour:</b>               extension line colour
//         <br/><b>extensionLineType:</b>             solid, etc
//         <br/><b>extensionThickness:</b>            think, normal or thick
//         <br/><b>radiusToCentre:</b>                Whether the Leader sub-element under a JtkPMIDimension
//                                                    of type radial is drawn to the centre of the measured geometry.
//         <br/><b>suppressed:</b>                    Whether the leader is suppressed. For example, a
//                                                    Dimension may have one leader present and the other
//                                                    suppressed.
//         <br/><b>perpendicularToStub:</b>           Whether the Leader is maintained perpendicular to its
//                                                    stub.
//         <br/><b>perpendicularToTerminator:</b>     Whether the rest of the Leader is maintained
//                                                    perpendicular to its termination geometry (which is
//                                                    given by LeaderReference).
//         <br/><b>leaderAttachment:</b>              The vertical position where the Leader attaches to the
//                                                    Annotation.
//         <br/><b>extensionJogging:</b>              Whether the extension line is jogged.
//         <br/><b>extensionJogDefinition:</b>        How the jogged extension line is defined.
//         <br/><b>extensionJogOut:</b>               Whether the jogged extension line is jogged inwards or
//                                                    outwards.
//         <br/><b>extensionJogStart:</b>             The start of the jogged extension line.
//         <br/><b>extensionJogEnd:</b>               The end of the jogged extension line.
//         <br/><b>extensionJogAngle:</b>             The angle of the jogged extension line.
//         <br/><b>offsetCentre:</b>                  Whether Reference and terminator relate to the offset
//                                                    centre of a folded radius Dimension.
//         <br/><b>allAroundSymbolSize</b>            The diameter of any allAround symbol.
//         <br/><b>halfArrow:</b>                     Whether only the left or right side of the arrowhead, looking in the direction of the arrow, is displayed.
//                                                    By default, both sides are displayed.
//         <br/><b>direction:</b>                     The direction of the leader from terminator. Overrides stubDirection.
//         <br/><b>textOverStubFactor:</b>            The location of any text over the stub of the Leader relative to the text height.
//         <br/><b>textOverLeaderFactor:</b>          The location of any text over the Leader itself relative to the text height.
//         <br/><b>stubAttachment:</b>                The vertical position where the stub of the Leader attaches to a text item of an Annotation
//         <br/><b>Jog</b>                            The position of a jog in the leader.
//         <br/><b>unitSymbol:</b>                    The symbol for the unit. For compound units (like degrees, minutes and seconds) more
//                                                    than one is permitted.
//
//      The Geometry property and Leader CurveRef property of the PLMXML Annotations schema are not represented in this API as the Visual functions replace them.
//
// Enums          :  JtkPMIJustification:
//                        JustificationRIGHT --
//                        JustificationCENTRE --
//                        JustificationLEFT --
//                        JustificationTOPLEFT --
//                        JustificationTOPRIGHT --
//                        JustificationTOPCENTRE --
//                        JustificationBOTTOMLEFT --
//                        JustificationBOTTOMRIGHT --
//                        JustificationBOTTOMCENTRE --
//
//                     JtkPMIAttachmentType:
//                        AttachmentTypeANGULARDIMENSION --
//                        AttachmentTypeONGEOMETRY --
//                        AttachmentTypeLINEARDIMENSION --
//                        AttachmentTypeLEADER --
//                        AttachmentTypeSTACKED --
//                        AttachmentTypeORDINATEDIMENSION --
//                        AttachmentTypeRADIALDIMENSION --
//                        AttachmentTypeDIAMETRALDIMENSION --
//                        AttachmentTypeNOLEADER --
//                        AttachmentTypeSTACKEDLEFT --
//                        AttachmentTypeSTACKEDRIGHT -- 
//                        AttachmentTypeSTACKEDABOVE --
//
//                     JtkPMIUnderline:
//                        UnderlineOVER --
//                        UnderlineUNDER --
//
//                     JtkPMIUnits:
//                        UnitsMETRES --
//                        UnitsMILLIMETRES --
//                        UnitsINCHES --
//
//                     JtkPMITextLineThickness:
//                        TextThicknessNORMAL --
//                        TextThicknessTHICK --
//                        TextThicknessTHIN --
//
//                     JtkPMIDimensionStubDirection:
//                        DimensionStubDirectionLEFT --
//                        DimensionStubDirectionRIGHT --
//                        DimensionStubDirectionINFERRED --
//
//                     JtkPMILeaderArrowType:
//                        ArrowTypeCLOSED --
//                        ArrowTypeOPEN --
//                        ArrowTypeFILLED --
//                        ArrowTypeNONE --
//                        ArrowTypeORIGIN --
//                        ArrowTypeCROSS --
//                        ArrowTypeDOT --
//                        ArrowTypeFILLEDDOT --
//                        ArrowTypeWEDGE --
//                        ArrowTypePLUS --
//                        ArrowTypeX --
//                        ArrowTypeCLOSEDSOLID --
//                        ArrowTypeCLOSEDDOUBLE --
//                        ArrowTypeCLOSEDDOUBLESOLID --
//                        ArrowTypeOPENDDOUBLE --
//                        ArrowTypeFILLEDDOUBLE --
//                        ArrowTypeINTEGRAL --
//                        ArrowTypeBOX --
//                        ArrowTypeFILLEDBOX --
//                        ArrowTypeDATUM --
//                        ArrowTypeFILLEDDATUM --
//                        ArrowTypeSOLIDORIGIN --
//                        ArrowTypeFILLEDORIGIN --
//                        ArrowTypeXORIGIN --
//                        ArrowTypeSOLIDBOX --
//                        ArrowTypeROUNDBACKDART --
//                        ArrowTypeSOLIDROUNDBACKDART --
//                        ArrowTypeFILLEDROUNDBACKDART --
//
//                     JtkPMILineStyle:
//                        LineStyleUNSET --
//                        LineStyleLONGDASHED --
//                        LineStyleDOTTED --
//                        LineStyleDOTTEDDASHED --
//                        LineStylePHANTOM --
//                        LineStyleDASHED --
//                        LineStyleSOLID --
//                        LineStyleCENTRELINE --
//
//                     JtkPMITextOutlineType:
//                        OutlineTypeBOX --
//                        OutlineTypeTRIANGLE --
//                        OutlineTypeCIRCLE --
//                        OutlineTypeELLIPSE --
//                        OutlineTypeUNDERLINE --
//                        OutlineTypeSQUARE --
//                        OutlineTypeSCOREDCIRCLE --
//                        OutlineTypeDIAMOND --
//                        OutlineTypeFLAGRIGHT --
//                        OutlineTypeFLAGLEFT --
//                        OutlineTypeFLAGBOTH --
//                        OutlineTypeOBLONG --
//                        OutlineTypeOBLONGRIGHT --
//                        OutlineTypeOBLONGLEFT --
//                        OutlineTypeSTICKING --
//                        OutlineTypeSET --
//                        OutlineTypeFIXEDSUPPORT --
//                        OutlineTypeNOTA --
//                        OutlineTypeSYMMETRICALPART --
//                        OutlineTypeSYMMETRICALSET --
//                        OutlineTypeSCOREDRECTANGLE --
//                        OutlineTypePARALLELOGRAM --
//
//                   JtkPMIOriginAnchor:
//                        OriginAnchorTOPLEFT --
//                        OriginAnchorTOPCENTRE --
//                        OriginAnchorTOPRIGHT --
//                        OriginAnchorMIDDLELEFT --
//                        OriginAnchorMIDDLECENTRE --
//                        OriginAnchorMIDDLERIGHT --
//                        OriginAnchorBOTTOMLEFT --
//                        OriginAnchorBOTTOMCENTRE --
//                        OriginAnchorBOTTOMRIGHT --
//
//                   JtkPMILeaderAttachment:
//                        LeaderAttachmentTOP --
//                        LeaderAttachmentMIDDLE --
//                        LeaderAttachmentBOTTOM --
//
//                   JtkPMIStubAttachment:
//                        StubAttachmentSIDE --
//                        StubAttachmentUNDERLINE --
//
//                    JtkPMIExtensionJogging:
//                        ExtensionJoggingOFF -- the extension line is not jogged
//                        ExtensionJoggingON -- the extension line is jogged
//                        ExtensionJoggingAPPLICATION -- application determines if extension line is jogged
//
//                     JtkPMIExtensionJogDefinition:
//                        ExtensionJogDefinitionSTARTEND -- the start and end of the Jog
//                        ExtensionJogDefinitionSTARTANGLE -- the start of the Jog and its angle.
//                        ExtensionJogDefinitionENDANGLE -- the end of the Jog and its angle
//
//                     JtkPMIHalfArrow:
//                        HalfArrowLEFT -- Looking in the direction of the arrow only the left side of the arrow head is displayed
//                        HalfArrowRIGHT -- Looking in the direction of the arrow only the right side of the arrow head is displayed
//                        HalfArrowFULL -- Both sides of an arrow head are displayed
//
//                     JtkValidationLengthType:
//                        PolylineLength -- total length of all polyline content that makes up the PMI.
//                        AttachedLength -- total curve length of wires and edge content attached to the PMI.
//                        AssociatedLength -- total curve length of wires and edge content associated to the PMI.
//
//                     JtkValidationAreaType:
//                        AttachedArea -- total surface area of content attached to the PMI.
//                        AssociatedArea -- total surface area of content associated to the PMI.
//
//                     JtkValidationCentroidType:
//                        PolylineCentroid -- mathematical centroid of the polyline content that makes up the PMI.
//
//                     JtkValidationOriginType
//                        AttachedOrigin -- origin of PMI content attached to the PMI.
//                        AssociatedOrigin -- origin of PMI content associated to the PMI.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIVisualEntity > JtkPMIAnnotation
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIAnnotation : public JtkPMIVisualEntity
{
   JTK_OBJECT_HEADER( JtkPMIAnnotation )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIAnnotation( JtkUnitHierarchy* owner );
   virtual ~JtkPMIAnnotation( );

public:
   int getDescription( JtkString& ) const;
   int setDescription( const JtkString& );
   int unsetDescription( void );

   int getGroup( JtkString& ) const;
   int setGroup( const JtkString& );
   int unsetGroup( void );

   int numUriRefs( int& ) const;
   int addUriRefs( const JtkString& );
   int getUriRefs( int, JtkString& ) const;
   int setUriRefs( int, const JtkString& );
   int unsetUriRefs( int );

   int getAccountabilityId( int& ) const;
   int setAccountabilityId( int );
   int unsetAccountabilityId( void );

   int getUsage( JtkString& ) const;
   int setUsage( const JtkString& );
   int unsetUsage( void );

   int numKeyword( int& ) const;
   int addKeyword( const JtkString& );
   int getKeyword( int, JtkString& ) const;
   int setKeyword( int, const JtkString& );
   int unsetKeyword( int );

   int getSafetyClassification( JtkString& ) const;
   int setSafetyClassification( const JtkString& );
   int unsetSafetyClassification( void );

   int getValueToCustomer( JtkString& ) const;
   int setValueToCustomer( const JtkString& );
   int unsetValueToCustomer( void );

   int getSymbolColour( JtkString& ) const;
   int setSymbolColour( const JtkString& );
   int unsetSymbolColour( void );

   int getOutlineType( JtkPMITextOutlineType& ) const;
   int setOutlineType( JtkPMITextOutlineType );
   int unsetOutlineType( void );

   int getOutlineColour( JtkString& ) const;
   int setOutlineColour( const JtkString& );
   int unsetOutlineColour( void );

   int getOutlineStyle( JtkPMILineStyle& ) const;
   int setOutlineStyle( JtkPMILineStyle );
   int unsetOutlineStyle( void );

   int getOutlineThickness( JtkPMITextLineThickness& ) const;
   int setOutlineThickness( JtkPMITextLineThickness );
   int unsetOutlineThickness( void );

   int getOutlineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getOutlineWidth( JtkString& namedWidth ) const;
   int setOutlineWidth( JtkWidthMeasurementType measurementType, double width );
   int setOutlineWidth( const JtkString& namedWidth );
   int unsetOutlineWidth( );

   int addOutline( JtkPMIAnnotationOutline*& );
   int getOutline( JtkPMIAnnotationOutline*& ) const;
   int unsetOutline( );

   int getFont( JtkString& ) const;
   int setFont( const JtkString& );
   int unsetFont( void );

   int getTextColour( JtkString& colour ) const;
   int setTextColour( const JtkString& colour );
   int unsetTextColour( void );

   int getLanguage( JtkString& ) const;
   int setLanguage( const JtkString& );
   int unsetLanguage( void );

   int getTextHeight( double& ) const;
   int setTextHeight( double );
   int unsetTextHeight( void );

   int getJustification( JtkPMIJustification& ) const;
   int setJustification( JtkPMIJustification );
   int unsetJustification( void );

   int getAttachmentType( JtkPMIAttachmentType& ) const;
   int setAttachmentType( JtkPMIAttachmentType );
   int unsetAttachmentType( void );

   int getTextOrigin( double&, double&, double& ) const;
   int setTextOrigin( double, double, double );
   int unsetTextOrigin( void );

   int getUnderline( JtkPMIUnderline& ) const;
   int setUnderline( JtkPMIUnderline );
   int unsetUnderline( void );

   int getUnits( JtkPMIUnits& ) const;
   int setUnits( JtkPMIUnits );
   int unsetUnits( void );

   int getUnit( JtkString& ) const;
   int setUnit( const JtkString& );
   int unsetUnit( void );

   int getTextThickness( JtkPMITextLineThickness& ) const;
   int setTextThickness( JtkPMITextLineThickness );
   int unsetTextThickness( void );

   int getTextLineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getTextLineWidth( JtkString& namedWidth ) const;
   int setTextLineWidth( JtkWidthMeasurementType measurementType, double width );
   int setTextLineWidth( const JtkString& namedWidth );
   int unsetTextLineWidth( void );

   int getTextAspect( double& ) const;
   int setTextAspect( double );
   int unsetTextAspect( void );

   int getBold( int& ) const;
   int setBold( int );
   int unsetBold( void );

   int getTextDirection( double&, double&, double& ) const;
   int setTextDirection( double, double, double );
   int unsetTextDirection( void );

   int getSpaceFactor( double& ) const;
   int setSpaceFactor( double );
   int unsetSpaceFactor( void );

   int getLineFactor( double& ) const;
   int setLineFactor( double );
   int unsetLineFactor( void );

   int getItalic( int& ) const;
   int setItalic( int );
   int unsetItalic( void );

   int getBlanked( int& ) const;
   int setBlanked( int );
   int unsetBlanked( void );

   int getItalicAngle( double& ) const;
   int setItalicAngle( double );
   int unsetItalicAngle( void );

   int getStrikethrough( JtkPMIStrikethrough& ) const;
   int setStrikethrough( JtkPMIStrikethrough );
   int unsetStrikethrough( void );

   int getSubscript( JtkPMISubscript& ) const;
   int setSubscript( JtkPMISubscript );
   int unsetSubscript( void );

   int getValid( JtkPMITriStateBoolean& ) const;
   int setValid( JtkPMITriStateBoolean );
   int unsetValid( );

   int getLayer( int& ) const;
   int setLayer( int );
   int unsetLayer( );

   int getCommaAsDecimal( int& ) const;
   int setCommaAsDecimal( int );
   int unsetCommaAsDecimal( void );

   int getFlag( int& ) const;
   int setFlag( int );
   int unsetFlag( void );

   int numLeaders( int& count ) const;
   int addLeader( );
   int unsetLeader( int index );

   //store the id, type and path of the reference for this leader.
   int getLeaderReference( int index, int& dstId, int& dstType, JtkString& path ) const;
   int setLeaderReference( int index, int dstId, int dstType, const JtkString& path = JtkString( ) );

   int getLeaderReference( int index, JtkPMIReference& reference ) const;
   int setLeaderReference( int index, const JtkPMIReference& reference );

   int getLeaderReference( int index, JtkPMIReference& reference1, JtkPMIReference& reference2 ) const;
   int setLeaderReference( int index, const JtkPMIReference& reference1, const JtkPMIReference& reference2 );
   int unsetLeaderReference( int index );

   int getLeadertParm( int index, double& ) const;
   int setLeadertParm( int index, double );
   int unsetLeadertParm( int index );

   int getLeaderuvParm( int index, double&, double& ) const;
   int setLeaderuvParm( int index, double, double );
   int unsetLeaderuvParm( int index );

   int getLeaderTerminator( int index, double&, double&, double& ) const;
   int setLeaderTerminator( int index, double, double, double );
   int unsetLeaderTerminator( int index );

   int getLeaderStubDirection( int index, JtkPMIDimensionStubDirection& ) const;
   int setLeaderStubDirection( int index, JtkPMIDimensionStubDirection );
   int unsetLeaderStubDirection( int index );

   int getLeaderStubLength( int index, double& ) const;
   int setLeaderStubLength( int index, double );
   int unsetLeaderStubLength( int index );

   int getLeaderColour( int index, JtkString& ) const;
   int setLeaderColour( int index, const JtkString& );
   int unsetLeaderColour( int index );

   int getLeaderLineType( int index, JtkPMILineStyle& ) const;
   int setLeaderLineType( int index, JtkPMILineStyle );
   int unsetLeaderLineType( int index );

   int getLeaderLineThickness( int index, JtkPMITextLineThickness& ) const;
   int setLeaderLineThickness( int index, JtkPMITextLineThickness );
   int unsetLeaderLineThickness( int index );

   int getLeaderWidth( int index, JtkWidthMeasurementType measurementType, double& width ) const;
   int getLeaderWidth( int index, JtkString& namedWidth ) const;
   int setLeaderWidth( int index, JtkWidthMeasurementType measurementType, double width );
   int setLeaderWidth( int index, const JtkString& namedWidth );
   int unsetLeaderWidth( int index );

   int getLeaderArrowType( int index, JtkPMILeaderArrowType& ) const;
   int setLeaderArrowType( int index, JtkPMILeaderArrowType );
   int unsetLeaderArrowType( int index );

   int getLeaderArrowColour( int index, JtkString& ) const;
   int setLeaderArrowColour( int index, const JtkString& );
   int unsetLeaderArrowColour( int index );

   int getLeaderArrowLineType( int index, JtkPMILineStyle& ) const;
   int setLeaderArrowLineType( int index, JtkPMILineStyle );
   int unsetLeaderArrowLineType( int index );

   int getLeaderArrowLineThickness( int index, JtkPMITextLineThickness& ) const;
   int setLeaderArrowLineThickness( int index, JtkPMITextLineThickness );
   int unsetLeaderArrowLineThickness( int index );

   int getLeaderArrowWidth( int index, JtkWidthMeasurementType measurementType, double& width ) const;
   int getLeaderArrowWidth( int index, JtkString& namedWidth ) const;
   int setLeaderArrowWidth( int index, JtkWidthMeasurementType measurementType, double width );
   int setLeaderArrowWidth( int index, const JtkString& namedWidth );
   int unsetLeaderArrowWidth( int index );

   int getLeaderArrowAngle( int index, double& ) const;
   int setLeaderArrowAngle( int index, double );
   int unsetLeaderArrowAngle( int index );

   int getLeaderArrowLength( int index, double& ) const;
   int setLeaderArrowLength( int index, double );
   int unsetLeaderArrowLength( int index );

   int getLeaderDotDiameter( int index, double& ) const;
   int setLeaderDotDiameter( int index, double );
   int unsetLeaderDotDiameter( int index );

   int getLeaderArrowPlacement( int index, JtkPMIArrowPlacement& ) const;
   int setLeaderArrowPlacement( int index, JtkPMIArrowPlacement );
   int unsetLeaderArrowPlacement( int index );

   int getLeaderArrowOutsideLength( int index, double& ) const;
   int setLeaderArrowOutsideLength( int index, double );
   int unsetLeaderArrowOutsideLength( int index );

   int getLeaderLineTextGap( int index, double& ) const;
   int setLeaderLineTextGap( int index, double );
   int unsetLeaderLineTextGap( int index );

   int getLeaderExtensionLineGap( int index, double& ) const;
   int setLeaderExtensionLineGap( int index, double );
   int unsetLeaderExtensionLineGap( int index );

   int getLeaderExtensionLineColour( int index, JtkString& ) const;
   int setLeaderExtensionLineColour( int index, const JtkString& );
   int unsetLeaderExtensionLineColour( int index );

   int getLeaderExtensionLineType( int index, JtkPMILineStyle& ) const;
   int setLeaderExtensionLineType( int index, JtkPMILineStyle );
   int unsetLeaderExtensionLineType( int index );

   int getLeaderExtensionLineThickness( int index, JtkPMITextLineThickness& ) const;
   int setLeaderExtensionLineThickness( int index, JtkPMITextLineThickness );
   int unsetLeaderExtensionLineThickness( int index );

   int getLeaderExtensionWidth( int index, JtkWidthMeasurementType measurementType, double& width ) const;
   int getLeaderExtensionWidth( int index, JtkString& namedWidth ) const;
   int setLeaderExtensionWidth( int index, JtkWidthMeasurementType measurementType, double width );
   int setLeaderExtensionWidth( int index, const JtkString& namedWidth );
   int unsetLeaderExtensionWidth( int index );

   int getLeaderExtensionLineExtension( int index, double& ) const;
   int setLeaderExtensionLineExtension( int index, double );
   int unsetLeaderExtensionLineExtension( int index );

   int getLeaderRadiusToCentre( int index, int& ) const;
   int setLeaderRadiusToCentre( int index, int );
   int unsetLeaderRadiusToCentre( int index );

   int numLeaderJogs( int leaderIndex, int& ) const;
   int addLeaderJog( int leaderIndex, double, double, double );
   int getLeaderJog( int leaderIndex, int jogIndex, double&, double&, double& ) const;
   int unsetLeaderJog( int leaderIndex, int jogIndex );

   int getLeaderSuppressed( int index, int& ) const;
   int setLeaderSuppressed( int index, int );
   int unsetLeaderSuppressed( int index );

   int getLeaderPerpendicularToStub( int index, int& ) const;
   int setLeaderPerpendicularToStub( int index, int );
   int unsetLeaderPerpendicularToStub( int index );

   int getLeaderPerpendicularToTerminator( int index, int& ) const;
   int setLeaderPerpendicularToTerminator( int index, int );
   int unsetLeaderPerpendicularToTerminator( int index );

   int getLeaderLeaderAttachment( int index, JtkPMILeaderAttachment& ) const;
   int setLeaderLeaderAttachment( int index, JtkPMILeaderAttachment );
   int unsetLeaderLeaderAttachment( int index );

   int getLeaderExtensionJogging( int index, JtkPMIExtensionJogging& ) const;
   int setLeaderExtensionJogging( int index, JtkPMIExtensionJogging );
   int unsetLeaderExtensionJogging( int index );

   int getLeaderExtensionJogDefinition( int index, JtkPMIExtensionJogDefinition& ) const;
   int setLeaderExtensionJogDefinition( int index, JtkPMIExtensionJogDefinition );
   int unsetLeaderExtensionJogDefinition( int index );

   int getLeaderExtensionJogOut( int index, int& ) const;
   int setLeaderExtensionJogOut( int index, int );
   int unsetLeaderExtensionJogOut( int index );

   int getLeaderExtensionJogStart( int index, double& ) const;
   int setLeaderExtensionJogStart( int index, double );
   int unsetLeaderExtensionJogStart( int index );

   int getLeaderExtensionJogEnd( int index, double& ) const;
   int setLeaderExtensionJogEnd( int index, double );
   int unsetLeaderExtensionJogEnd( int index );

   int getLeaderExtensionJogAngle( int index, double& ) const;
   int setLeaderExtensionJogAngle( int index, double );
   int unsetLeaderExtensionJogAngle( int index );

   int getLeaderOffsetCentre( int index, int& ) const;
   int setLeaderOffsetCentre( int index, int );
   int unsetLeaderOffsetCentre( int index );

   int getLeaderAllAroundSymbolSize( int index, double& ) const;
   int setLeaderAllAroundSymbolSize( int index, double );
   int unsetLeaderAllAroundSymbolSize( int index );

   int getLeaderHalfArrow( int index, JtkPMIHalfArrow& ) const;
   int setLeaderHalfArrow( int index, JtkPMIHalfArrow );
   int unsetLeaderHalfArrow( int index );

   int getLeaderDirection( int index, double&, double&, double& ) const;
   int setLeaderDirection( int index, double, double, double );
   int unsetLeaderDirection( int index );

   int getLeaderTextOverStubFactor( int index, double& ) const;
   int setLeaderTextOverStubFactor( int index, double );
   int unsetLeaderTextOverStubFactor( int index );

   int getLeaderTextOverLeaderFactor( int index, double& ) const;
   int setLeaderTextOverLeaderFactor( int index, double );
   int unsetLeaderTextOverLeaderFactor( int index );

   int getLeaderStubAttachment( int index, JtkPMIStubAttachment& ) const;
   int setLeaderStubAttachment( int index, JtkPMIStubAttachment );
   int unsetLeaderStubAttachment( int index );

   int setNameComponents( const JtkString& pmiName, const JtkString& pmiDisplayName );
   int getNameComponents( JtkString& pmiName, JtkString& pmiDisplayName ) const;
   int unsetNameComponents( );

   int setPrime( int );
   int getPrime( int& ) const;
   int unsetPrime( );

   int setOriginAnchor( JtkPMIOriginAnchor );
   int getOriginAnchor( JtkPMIOriginAnchor& ) const;
   int unsetOriginAnchor( );

   int setFeatureIdentification( const JtkString& value );
   int getFeatureIdentification( JtkString& value ) const;
   int unsetFeatureIdentification( );

   int setRevisionModifier( const JtkString& value );
   int getRevisionModifier( JtkString& value ) const;
   int unsetRevisionModifier( );

   int numGeneralAttributes( int& Number ) const;
   int addGeneralAttribute( const JtkString& Name, const JtkString& Value,
                            const JtkString& Unit = JtkString( ), const JtkString& Category = JtkString( ),
                            JtkMeasureEnum Dimensionality = MeasureEnumNONE,
                            JtkDataType Type = DataTypeSTRING, int Editable = 0 );
   int getGeneralAttribute( int Index, JtkString& Name, JtkString& Value,
                            JtkString& Unit, JtkString& Category,
                            JtkMeasureEnum& Dimensionality,
                            JtkDataType& Type, int& Editable ) const;
   int unsetGeneralAttribute( int Index );

   int numGeneralAttributeListValues( int Index, int& Number ) const;
   int addGeneralAttributeListValue( int Index, const JtkString& ListValue );
   int getGeneralAttributeListValue( int Index, int ListIndex, JtkString& ListValue ) const;
   int unsetGeneralAttributeListValue( int Index, int ListIndex );
   int unsetGeneralAttrbuteListValue( int Index, int ListIndex );

   int getDisplayPlane( double origin[3], double xAxis[3], double zAxis[3] ) const;
   int setDisplayPlane( double origin[3], double xAxis[3], double zAxis[3] );
   int unsetDisplayPlane( );

   int numIntersectionReferences( int& ) const;
   int addIntersectionReference( const JtkPMIReference& dst1, const JtkPMIReference& dst2, int reason = -1, int origin = 0 );
   int getIntersectionReference( int index, JtkPMIReference& dst1, JtkPMIReference& dst2, int& reason, int& origin ) const;
   int unsetIntersectionReference( int index );

   int getPanZoom( int& trueFalse ) const;
   int setPanZoom( int trueFalse );
   int unsetPanZoom( );

   int getTextRotationPoint( double& X, double& Y, double& Z ) const;
   int setTextRotationPoint( double X, double Y, double Z );
   int unsetTextRotationPoint( );

   int addTextFormat( JtkPMITextFormat*& );
   int getTextFormat( JtkPMITextFormat*& ) const;
   int unsetTextFormat( );

   int getStackFactor( double& StackFactor ) const;
   int setStackFactor( double StackFactor );
   int unsetStackFactor( void );

   int addUnitSymbol( JtkPMIText*& UnitSymbol );
   int getUnitSymbol( int Index, JtkPMIText*& UnitSymbol ) const;
   int numUnitSymbol( int& Count ) const;
   int unsetUnitSymbol( int Index );

   //PMI Validation APIs
   enum JtkValidationLengthType
   {
      PolylineLength,
      AttachedLength,
      AssociatedLength
   };

   int addValidationLength( JtkValidationLengthType, double, JtkUnits );
   int getValidationLength( JtkValidationLengthType, double&, JtkUnits& ) const;

   enum JtkValidationAreaType
   {
      AttachedArea,
      AssociatedArea
   };

   int addValidationArea( JtkValidationAreaType, double, JtkUnits );
   int getValidationArea( JtkValidationAreaType, double&, JtkUnits& ) const;

   enum JtkValidationCentroidType
   {
      PolylineCentroid
   };

   int addValidationCentroid( JtkValidationCentroidType, double, double, double );
   int getValidationCentroid( JtkValidationCentroidType, double&, double&, double& ) const;

   int addValidationString( const JtkString& );
   int getValidationString( JtkString& ) const;

   enum JtkValidationOriginType
   {
      AssociatedOrigin,
      AttachedOrigin
   };

   int numValidationOrigins( JtkValidationOriginType, int& ) const;
   int addValidationOrigin( JtkValidationOriginType, double, double, double );
   int getValidationOrigin( JtkValidationOriginType, int index, double&, double&, double& ) const;
};

///////%{
//
// Class          : JtkPMIDimensionGeneralToleranceISO
//
// Description    : Class for the representating a general tolerance according to ISO 2768.
//                  If present, tolerances are determined from type and value on the corresponding
//                  Dimension. upperDelta and lowerDelta are ignored
//                  <br/><b>toleranceClass:</b>          The general tolerance class.
//
// Enums          :    JtkPMIDimensionToleranceClassISO:
//                        ISOToleranceClassFINE --
//                        ISOToleranceClassMEDIUM --
//                        ISOToleranceClassCOARSE --
//                        ISOToleranceClassVERYCOARSE --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIDimensionGeneralToleranceISO
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIDimensionGeneralToleranceISO : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIDimensionGeneralToleranceISO )

   JtkPMIDimensionGeneralToleranceISO( );
   virtual ~JtkPMIDimensionGeneralToleranceISO( );

public:
   int getToleranceClass( JtkPMIDimensionToleranceClassISO& ) const;
   int setToleranceClass( JtkPMIDimensionToleranceClassISO );
   int unsetToleranceClass( );
};

///////%{
//
// Class          : JtkPMIDimension
//
// Description    : JtkPMI class for the representation of Dimensions. It has the following properties:
//      <br/><b>standard:</b>               e.g. "ANSI Y..."
//      <br/><b>type:</b>                   linear, radial, angular or curveLength
//      <br/><b>direction:</b>              direction of measurement
//      <br/><b>basic:</b>                  whether a 'basic' dimension.
//      <br/><b>reference:</b>              whether a 'reference' dimension.
//      <br/><b>origin:</b>                 whether first or second entity is the origin (for directed Dimensions)
//                                          Deprecated in favour of identifying this on the LeaderReference.
//      <br/><b>value:</b>                  value of dimension, in metres or radians
//      <br/><b>upperDelta:</b>             max value minus nominal value, in metres or radians
//      <br/><b>lowerDelta:</b>             nominal value minus min value, in metres or radians
//      <br/><b>causality:</b>              key, functional, associated or reference
//      <br/><b>grade:</b>
//      <br/><b>deviation:</b>
//      <br/><b>pitchDiaGrade:</b>
//      <br/><b>pitchDiaDeviation:</b>
//      <br/><b>fitGrade:</b>
//      <br/><b>threadClass:</b>
//      <br/><b>projected:</b>              true if the Dimension is a projected Dimension, rather than
//                                          a true value Dimension.
//      <br/><b>documentation:</b>          Whether a non-PMI Dimension is treated as a PMI
//                                          Dimension for documenting a Part, for example, on
//                                          manufacturing drawings.
//      <br/><b>notToScale:</b>             Whether a dimension is not-to-scale.
//      <br/><b>toleranceDisplay:</b>       method of display for tolerance
//      <br/><b>style:</b>                  style of display - radial, diametral, sphericalRadial,
//                                          controlledRadial, sphericalDiameter, or ordinate.
//                                          The limits value has been deprecated in favor of the <b>limitDisplay</b> property.
//      <br/><b>precision:</b>              number of decimal places in the value display
//      <br/><b>angleFormat:</b>            controls the format of angular values
//      <br/><b>tolerancePrecision:</b>     number of decimal places shown in the tolerance
//      <br/><b>unitText:</b>               whether to display the unit text (e.g. "inches")
//      <br/><b>dualUnits:                  units to use for the dual dimension. (DEPRECATED: use dualUnit)
//      <br/><b>dualUnit:                   units to use for the dual dimension. NB:</b>    if this is present, a
//                                          dual dimension is displayed - otherwise not.
//      <br/><b>dualType:</b>               bracket, positional or line separated display of the dual dimension
//      <br/><b>dualPlacement:              Placment of the dual dimension:</b>    before, after, above or below the
//                                          main dimension
//      <br/><b>dualTolerancePrecision:</b> number of decimal places shown in the dual tolerance
//      <br/><b>dualUnitText:</b>           ditto for the dual dimension
//      <br/><b>diameterPlacement:</b>      before, after, above or below
//      <br/><b>statisticalPlacement:</b>   before, after, above or below
//      <br/><b>radialPlacement:</b>        before, after, above or below
//      <br/><b>linearPlacement:</b>        before, after, above or below
//      <br/><b>referenceDisplay:</b>       how to display reference dimensions - reference, parenthesis, or matched
//      <br/><b>zeroToleranceDisplay:</b>   controls the display of a zero valued tolerance
//      <br/><b>dimensionLeadingZero:</b>   whether to display leading zeroes in the dimension value
//      <br/><b>dimensionTrailingZero:</b>  whether to display trailing zeroes in the dimension value
//      <br/><b>toleranceLeadingZero:</b>   whether to display leading zeroes in the tolerance value
//      <br/><b>toleranceTrailingZero:</b>  whether trailing zeros on tolerance values are
//                                          displayed.
//      <br/><b>limitFitOrder:</b>          For a limits and fits dimension, the order in which
//                                          the value attribute, the deviation and the grade
//                                          attributes, and the tolerance information on the
//                                          corresponding Dimension are displayed.
//      <br/><b>limitFitParentheses:</b>    For a limits and fits dimension, whether the value
//                                          attribute, the deviation and the grade attributes or
//                                          the tolerance information on the corresponding
//                                          Dimension are displayed in parentheses.
//      <br/><b>limitDisplay:</b>           Wether limit information is displayed.
//      <br/><b>fraction:</b>               Display each of value, upperDelta and lowerDelta on
//                                          Dimension as an integer (if value is greater than or
//                                          equal to one) and a fraction (unless value is
//                                          exactly an integer). For angular dimensions, display
//                                          them as fractions of the arc given by angleNumerator.
//      <br/><b>fractionSize:</b>           The size of the numerals in any fractions compared
//                                          to the size of those in the integers.
//      <br/><b>valueDenominator:</b>       The largest denominator allowable for value on
//                                          Dimension.
//      <br/><b>upperDeltaDenominator:</b>  The largest denominator allowable for upperDelta
//                                          on Dimension.
//      <br/><b>lowerDeltaDenominator:</b>  The largest denominator allowable for lowerDelta
//                                          on Dimension.
//      <br/><b>valueDenominator:</b>       The largest denominator allowable for value
//                                          converted to a dual dimension..
//      <br/><b>upperDeltaDenominator:</b>  The largest denominator allowable for upperDelta
//                                          converted to a dual dimension..
//      <br/><b>lowerDeltaDenominator:</b>  The largest denominator allowable for lowerDelta
//                                          converted to a dual dimension..
//      <br/><b>angleNumerator:</b>         The angle (in radians) of the arc for fractional
//                                          angular dimensions.
//      <br/><b>manual:</b>                 Whether the dimension is a manual dimension.
//      <br/><b>patternCount:</b>           The number of repetitions in a compound feature to which
//                                          the Dimension applies.
//      <br/><b>majorAngle:</b>             If type is angular, majorAngle indicates whether value
//                                          represents the major angle or the minor angle.
//      <br/><b>featureOfSize:</b>          Whether the Dimension specifies the size of a feature.
//      <br/><b>textOrientationType:</b>    How the dimension text is orientated.
//      <br/><b>dimensionLineTrim:</b>      When textOrientationType is aboveDimensionLine and
//                                          the dimension line is displayed between the
//                                          extension lines, dimensionLineTrim specifies whether
//                                          the dimension line is trimmed if the dimension text
//                                          crosses both extension lines.
//      <br/><b>dimensionLineBetweenArrows:</b> Whether the dimension line is displayed
//                                          between the dimension arrowheads.
//      <br/><b>textLeaderPosition:</b>     The position and the orientation of the text at the
//                                          end of a Leader.
//      <br/><b>narrowOffset:</b>           For a narrow Dimension, the perpendicular distance
//                                          from the dimension line to the end of the Leader (if
//                                          there is one) or the text (if there is no Leader) in
//                                          metres.
//      <br/><b>narrowLeaderAngle:</b>      For a narrow Dimension, the angle between the
//                                          dimension line and the Leader in radians.
//      <br/><b>singleSided:</b>            Whether the Dimension is displayed single sided.
//      <br/><b>singleSideFirst:</b>        Whether a single sided Dimension points towards the
//                                          first or the second Reference sub-element.
//      <br/><b>singleSideLength:</b>       The length (or the arc length for an angular
//                                          Dimension) that the non arrow side of a single sided
//                                          Dimension protrudes from the text.
//      <br/><b>alignment:</b>              The position of the value relative to the limit and
//                                          fit (if there is one) and the tolerance information,
//                                          which follow.
//      <br/><b>toleranceAngleFormat:</b>   controls the format of angular tolerances
//      <br/><b>foldLocation:</b>           The location of the fold of a folded radius Dimension.
//      <br/><b>inspection:</b>             Whether the Dimension is used for inspection.
//      <br/><b>allAround:</b>              Whether the All Around symbol is added
//      <br/><b>allOver:</b>                Whether the tolerance applies all over the 3-dimensional profile of the part
//      <br/><b>inspectionDisplay:</b>       If inspection is true, inspectionDisplay specifies how any appended
//                                           text is displayed inside the dimension inspection symbol
//      <br/><b>ordinateBaselineZero:</b>    Whether to display a zero at the baseline for ordinate dimensions.
//      <br/><b>dualDimensionLineCenter:</b> Whether to center the dimension line between the dimension and the dual dimension
//      <br/><b>referenceContent:            The type of information to display inside the
//                                           parentheses of a reference Dimension.
//      <br/><b>appendedTextSpaceFactor:</b> The spacing of any appended text fields relative to the font size.
//      <br/><b>toleranceTextSpaceFactor:</b>The spacing of the tolerance fields relative to the font size
//      <br/><b>ToleranceTextFormat:</b>     Formatting attributes for the text of the tolerance values.
//      <br/><b>ValueText:</b>               When manual the text for the value.
//      <br/><b>DualValueText:</b>           When manual the text for the dual value.
//      <br/><b>StyleText:</b>               Custom style indicator text, such as the diameter
//                                           symbol.Overrides any style indicator inferred from
//                                           style.
//
//      <br/><b>DimensionText:</b>          Up to four positioned text's on the pmi.
//      <br/><b>DualDimensionText:</b>      Up to four positioned text's for dual dimension, if displayed.
//      <br/><b>ReferenceText:</b>          Up to 2 positioned text elements inside the parentheses of a reference
//                                          Dimension. Only before and after are allowed.
//      <br/><b>GeneralToleranceISO:</b>    A general tolerance according to ISO 2768. If present, tolerances are 
//                                          determined from type and value. upperDelta and lowerDelta are ignored.
//      <br/><b>zeroToleranceSign:</b>      The sign (if any) before zero tolerance values for both upper and lower bounds.
//      <br/><b>dualUnitSymbol:</b>         The symbol for the dualUnit. For compound units (like degrees, minutes and seconds) more
//                                          than one is permitted.
//
//      Each Dimension or DualDimension Text can have the following properties:
//         <br/><b>position:</b>             Before, After, Above or Below
//         <br/><b>Text:</b>                 A single JtkPMIText for this DimensionText or DualDimensionText.
//
//
// Enums          : JtkPMIDimensionCausality:
//                        CausalityKEY --
//                        CausalityFUNCTIONAL --
//                        CausalityREFERENCE --
//                        CausalityASSOCIATED --
//                        CausalityPMI ---
//
//                     JtkPMIDimensionOrigin:
//                        OriginFIRST --
//                        OriginSECOND --
//
//                     JtkPMIDimensionType:
//                        TypeCURVELENGTH --
//                        TypeLINEAR --
//                        TypeANGULAR --
//                        TypeRADIAL --
//
//                     JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
//                     JtkPMIDimensionReferenceDisplay:
//                        ReferenceDisplayPARENTHESIS --
//                        ReferenceDisplayREFERENCE --
//                        ReferenceDisplayMATCHED --
//
//                     JtkPMIDimensionZeroToleranceDisplay:
//                        ZeroToleranceDisplayDISPLAYZERO --
//                        ZeroToleranceDisplayBLANK --
//                        ZeroToleranceDisplaySUPPRESSTRAILINGZERO --
//                        ZeroToleranceDisplayOMIT --
//
//                     JtkPMIDimensionStyle:
//                        StyleLINEARDIAMETRAL --
//                        StyleRADIAL --
//                        StyleCONTROLLEDRADIAL --
//                        StyleDIAMETRAL --
//                        StyleLIMITS -- Deprecated in favor of the limitDisplay property
//                        StyleORDINATE --
//                        StyleSPHERICALRADIAL --
//                        StyleSPHERICALDIAMETRAL --
//                        StyleNARROW -- 
//                        StyleNONE --
//
//                     JtkPMIDimensionToleranceDisplay:
//                        ToleranceDisplayMINUSLIMIT1 --
//                        ToleranceDisplayBILATERAL --
//                        ToleranceDisplayPLUSLIMIT1 --
//                        ToleranceDisplayPLUSLIMIT2 --
//                        ToleranceDisplayEQUALBILATERAL --
//                        ToleranceDisplayMINUSLIMIT2 --
//                        ToleranceDisplayUPPERUNILATERAL --
//                        ToleranceDisplayLOWERUNILATERAL --
//
//                     JtkPMIDimensionPlacement:
//                        PlacementBEFORE --
//                        PlacementABOVE --
//                        PlacementBELOW --
//                        PlacementAFTER --
//
//                     JtkPMIDimensionDualType:
//                        DualTypePOSITIONAL --
//                        DualTypeBRACKET --
//                        DualTypeLINESEPARATED -- 
//
//                     JtkPMIAngleFormat:
//                        AngleFormatDEGREES --
//                        AngleFormatSECONDS --
//                        AngleFormatMINUTES --
//                        AngleFormatWHOLEDEGREES --
//
//                     JtkPMILimitFitOrder:
//                        OrderVALUELIMITFITTOLERANCE --
//                        OrderTOLERANCEVALUELIMITFIT --
//                        OrderVALUETOLERANCELIMITFIT --
//
//                     JtkPMILimitFitParentheses:
//                        ParenthesesNONE --
//                        ParenthesesVALUELIMITFIT --
//                        ParenthesesLIMITFIT --
//                        ParenthesesTOLERANCE --
//
//                     JtkPMIFractionSize:
//                        FractionSizeFULL --
//                        FractionSizeTWOTHIRDS --
//                        FractionSizeTHREEQUARTERS --
//                
//                     JtkPMITextLeaderPosition:
//                        TextLeaderPositionNONE --
//                        TextLeaderPositionABOVELEADER --
//                        TextLeaderPositionAFTERLEADER --
//                        TextLeaderPositionABOVESTUB --
//                        TextLeaderPositionAFTERSTUB --
//
//                     JtkPMITextOrientation:
//                        TextOrientationHORIZONTAL --
//                        TextOrientationALIGNED --
//                        TextOrientationABOVE --
//                        TextOrientationPERPENDICULAR --
//                        TextOrientationUSERDEFINED --
//
//                     JtkPMILimitDisplay: 
//                        LimitDisplayNONE -- 
//                        LimitDisplayLIMITFIT --
// 
//                     JtkPMIInspectionDisplay:
//                        InspectionDisplayNONE -- No appended text is display inside the inspection symbol
//                        InspectionDisplayBEFORE -- Any before appended text is displayed inside the inspection symbol
//                        InspectionDisplayAFTER -- Any after appended text is displayed inside the inspection symbol
//                        InspectionDisplayBEFOREAFTER -- Any before and after appended text is displayed inside the inspection symbol
//                        InspectionDisplayALL -- All appended text is displayed inside the inspection symbol
//
//                     JtkPMIReferenceContent: 
//                        ReferenceContentVALUE -- Only the value is displayed inside the parentheses of a reference Dimension
//                        ReferenceContentPREFIX -- The prefix and the value are displayed inside the parentheses of a reference Dimension
//                        ReferenceContentTOLERANCE -- The prefix, the value and the tolerance are displayed inside the parentheses of a reference Dimension
//
//                     JtkPMIZeroToleranceSign:
//                        ZeroToleranceSignNONE --
//                        ZeroToleranceSignPLUS --
//                        ZeroToleranceSignMINUS --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIDimension
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIDimension : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIDimension )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIDimension( JtkUnitHierarchy* owner );
   virtual ~JtkPMIDimension( );

public:
   int getCausality( JtkPMIDimensionCausality& ) const;
   int setCausality( JtkPMIDimensionCausality );
   int unsetCausality( void );

   int getUpperDelta( double& ) const;
   int setUpperDelta( double );
   int unsetUpperDelta( void );

   int getLowerDelta( double& ) const;
   int setLowerDelta( double );
   int unsetLowerDelta( void );

   int getPitchDiaDeviation( JtkString& ) const;
   int setPitchDiaDeviation( const JtkString& );
   int unsetPitchDiaDeviation( void );

   int getDirection( double&, double&, double& ) const;
   int setDirection( double, double, double );
   int unsetDirection( void );

   int getOrigin( JtkPMIDimensionOrigin& ) const;
   int setOrigin( JtkPMIDimensionOrigin );
   int unsetOrigin( void );

   int getValue( double& ) const;
   int setValue( double );
   int unsetValue( void );

   int getType( JtkPMIDimensionType& ) const;
   int setType( JtkPMIDimensionType );
   int unsetType( void );

   int getIsReference( int& ) const;
   int setIsReference( int );
   int unsetIsReference( void );

   int getFitGrade( int& ) const;
   int setFitGrade( int );
   int unsetFitGrade( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getBasic( int& ) const;
   int setBasic( int );
   int unsetBasic( void );

   int getProjected( int& ) const;
   int setProjected( int );
   int unsetProjected( void );

   int getDocumentation( int& ) const;
   int setDocumentation( int );
   int unsetDocumentation( void );

   int getNotToScale( int& ) const;
   int setNotToScale( int );
   int unsetNotToScale( void );

   int getThreadClass( int& ) const;
   int setThreadClass( int );
   int unsetThreadClass( void );

   int getDeviation( JtkString& ) const;
   int setDeviation( const JtkString& );
   int unsetDeviation( void );

   int getPitchDiaGrade( int& ) const;
   int setPitchDiaGrade( int );
   int unsetPitchDiaGrade( void );

   int getGrade( int& ) const;
   int setGrade( int );
   int unsetGrade( void );

   int addDimensionText( );
   int numDimensionText( int& number ) const;
   int unsetDimensionText( int index );

   int addDimensionTextText( int dIndex, JtkPMIText*& );
   int getDimensionTextText( int dIndex, JtkPMIText*& ) const;
   int unsetDimensionTextText( int dIndex );

   int setDimensionTextPosition( int dIndex, JtkPMIDimensionPlacement pos );
   int getDimensionTextPosition( int dIndex, JtkPMIDimensionPlacement& pos ) const;
   int unsetDimensionTextPosition( int dIndex );

   int addDualDimensionText( );
   int numDualDimensionText( int& number ) const;
   int unsetDualDimensionText( int index );

   int addDualDimensionTextText( int dIndex, JtkPMIText*& );
   int getDualDimensionTextText( int dIndex, JtkPMIText*& ) const;
   int unsetDualDimensionTextText( int dIndex );

   int setDualDimensionTextPosition( int dIndex, JtkPMIDimensionPlacement pos );
   int getDualDimensionTextPosition( int dIndex, JtkPMIDimensionPlacement& pos ) const;
   int unsetDualDimensionTextPosition( int dIndex );

   int addReferenceText( );
   int numReferenceText( int& number ) const;
   int unsetReferenceText( int index );

   int addReferenceTextText( int dIndex, JtkPMIText*& );
   int getReferenceTextText( int dIndex, JtkPMIText*& ) const;
   int unsetReferenceTextText( int dIndex );

   int setReferenceTextPosition( int dIndex, JtkPMIDimensionPlacement pos );
   int getReferenceTextPosition( int dIndex, JtkPMIDimensionPlacement& pos ) const;
   int unsetReferenceTextPosition( int dIndex );

   int addFreeState( void );
   int getFreeState( void ) const;
   int unsetFreeState( void );

   int addStatistical( void );
   int getStatistical( void ) const;
   int unsetStatistical( void );

   int setManual( int );
   int getManual( int& ) const;
   int unsetManual( void );

   int addValueText( JtkPMIText*& );
   int getValueText( JtkPMIText*& ) const;
   int unsetValueText( );

   int addDualValueText( JtkPMIText*& );
   int getDualValueText( JtkPMIText*& ) const;
   int unsetDualValueText( );

   int getPatternCount( int& ) const;
   int setPatternCount( int );
   int unsetPatternCount( );

   int getMajorAngle( int& ) const;
   int setMajorAngle( int );
   int unsetMajorAngle( );

   int getFeatureOfSize( int& ) const;
   int setFeatureOfSize( int );
   int unsetFeatureOfSize( );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getLinearPlacement( JtkPMIDimensionPlacement& ) const;
   int setLinearPlacement( JtkPMIDimensionPlacement );
   int unsetLinearPlacement( void );

   int getDualPlacement( JtkPMIDimensionPlacement& ) const;
   int setDualPlacement( JtkPMIDimensionPlacement );
   int unsetDualPlacement( void );

   int getReferenceDisplay( JtkPMIDimensionReferenceDisplay& ) const;
   int setReferenceDisplay( JtkPMIDimensionReferenceDisplay );
   int unsetReferenceDisplay( void );

   int getDualUnits( JtkString& ) const;
   int setDualUnits( const JtkString& );
   int unsetDualUnits( void );

   int getDualUnit( JtkString& ) const;
   int setDualUnit( const JtkString& );
   int unsetDualUnit( void );

   int getDiameterPlacement( JtkPMIDimensionPlacement& ) const;
   int setDiameterPlacement( JtkPMIDimensionPlacement );
   int unsetDiameterPlacement( void );

   int getUnitText( int& ) const;
   int setUnitText( int );
   int unsetUnitText( void );

   int getToleranceLeadingZero( int& ) const;
   int setToleranceLeadingZero( int );
   int unsetToleranceLeadingZero( void );

   int getTolerancePrecision( int& ) const;
   int setTolerancePrecision( int );
   int unsetTolerancePrecision( void );

   int getDualPrecision( int& ) const;
   int setDualPrecision( int );
   int unsetDualPrecision( void );

   int getZeroToleranceDisplay( JtkPMIDimensionZeroToleranceDisplay& ) const;
   int setZeroToleranceDisplay( JtkPMIDimensionZeroToleranceDisplay );
   int unsetZeroToleranceDisplay( void );

   int getStatisticalPlacement( JtkPMIDimensionPlacement& ) const;
   int setStatisticalPlacement( JtkPMIDimensionPlacement );
   int unsetStatisticalPlacement( void );

   int getDimensionLeadingZero( int& ) const;
   int setDimensionLeadingZero( int );
   int unsetDimensionLeadingZero( void );

   int getDimensionTrailingZero( int& ) const;
   int setDimensionTrailingZero( int );
   int unsetDimensionTrailingZero( void );

   int getAngleFormat( JtkPMIAngleFormat& ) const;
   int setAngleFormat( JtkPMIAngleFormat );
   int unsetAngleFormat( void );

   int getStyle( JtkPMIDimensionStyle& ) const;
   int setStyle( JtkPMIDimensionStyle );
   int unsetStyle( void );

   int getDualTolerancePrecision( int& ) const;
   int setDualTolerancePrecision( int );
   int unsetDualTolerancePrecision( void );

   int getToleranceDisplay( JtkPMIDimensionToleranceDisplay& ) const;
   int setToleranceDisplay( JtkPMIDimensionToleranceDisplay );
   int unsetToleranceDisplay( void );

   int getRadialPlacement( JtkPMIDimensionPlacement& ) const;
   int setRadialPlacement( JtkPMIDimensionPlacement );
   int unsetRadialPlacement( void );

   int getDualType( JtkPMIDimensionDualType& ) const;
   int setDualType( JtkPMIDimensionDualType );
   int unsetDualType( void );

   int getDualUnitText( int& ) const;
   int setDualUnitText( int );
   int unsetDualUnitText( void );

   int getToleranceTrailingZero( int& ) const;
   int setToleranceTrailingZero( int );
   int unsetToleranceTrailingZero( void );

   int getLimitFitOrder( JtkPMILimitFitOrder& );
   int setLimitFitOrder( JtkPMILimitFitOrder );
   int unsetLimitFitOrder( void );

   int getLimitFitParentheses( JtkPMILimitFitParentheses& );
   int setLimitFitParentheses( JtkPMILimitFitParentheses );
   int unsetLimitFitParentheses( void );

   int getLimitDisplay( JtkPMILimitDisplay& ) const;
   int setLimitDisplay( JtkPMILimitDisplay );
   int unsetLimitDisplay( void );

   int getFraction( int& ) const;
   int setFraction( int );
   int unsetFraction( void );

   int getFractionSize( JtkPMIFractionSize& ) const;
   int setFractionSize( JtkPMIFractionSize );
   int unsetFractionSize( void );

   int getValueDenominator( int& ) const;
   int setValueDenominator( int );
   int unsetValueDenominator( void );

   int getUpperDeltaDenominator( int& ) const;
   int setUpperDeltaDenominator( int );
   int unsetUpperDeltaDenominator( void );

   int getLowerDeltaDenominator( int& ) const;
   int setLowerDeltaDenominator( int );
   int unsetLowerDeltaDenominator( void );

   int getDualValueDenominator( int& ) const;
   int setDualValueDenominator( int );
   int unsetDualValueDenominator( void );

   int getDualUpperDeltaDenominator( int& ) const;
   int setDualUpperDeltaDenominator( int );
   int unsetDualUpperDeltaDenominator( void );

   int getDualLowerDeltaDenominator( int& ) const;
   int setDualLowerDeltaDenominator( int );
   int unsetDualLowerDeltaDenominator( void );

   int getAngleNumerator( double& ) const;
   int setAngleNumerator( double );
   int unsetAngleNumerator( void );

   int getTextOrientationType( JtkPMITextOrientation& ) const;
   int setTextOrientationType( JtkPMITextOrientation );
   int unsetTextOrientationType( );

   int getDimensionLineTrim( int& ) const;
   int setDimensionLineTrim( int );
   int unsetDimensionLineTrim( );

   int getDimensionLineBetweenArrows( int& ) const;
   int setDimensionLineBetweenArrows( int );
   int unsetDimensionLineBetweenArrows( );

   int getTextLeaderPosition( JtkPMITextLeaderPosition& ) const;
   int setTextLeaderPosition( JtkPMITextLeaderPosition );
   int unsetTextLeaderPosition( );

   int getNarrowOffset( double& ) const;
   int setNarrowOffset( double );
   int unsetNarrowOffset( );

   int getNarrowLeaderAngle( double& ) const;
   int setNarrowLeaderAngle( double );
   int unsetNarrowLeaderAngle( );

   int getSingleSided( int& ) const;
   int setSingleSided( int );
   int unsetSingleSided( );

   int getSingleSideFirst( int& ) const;
   int setSingleSideFirst( int );
   int unsetSingleSideFirst( );

   int getSingleSideLength( double& ) const;
   int setSingleSideLength( double );
   int unsetSingleSideLength( );

   int getAlignment( JtkPMIFitDesignationAlignment& ) const;
   int setAlignment( JtkPMIFitDesignationAlignment );
   int unsetAlignment( );

   int getToleranceAngleFormat( JtkPMIAngleFormat& ) const;
   int setToleranceAngleFormat( JtkPMIAngleFormat );
   int unsetToleranceAngleFormat( );

   int getFoldLocation( double&, double&, double& ) const;
   int setFoldLocation( double, double, double );
   int unsetFoldLocation( );

   int getInspection( int& ) const;
   int setInspection( int );
   int unsetInspection( );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( );

   int getAllOver( int& ) const;
   int setAllOver( int );
   int unsetAllOver( );

   int getInspectionDisplay( JtkPMIInspectionDisplay& ) const;
   int setInspectionDisplay( JtkPMIInspectionDisplay );
   int unsetInspectionDisplay( );

   int getOrdinateBaselineZero( int& ) const;
   int setOrdinateBaselineZero( int );
   int unsetOrdinateBaselineZero( );

   int getDualDimensionLineCenter( int& ) const;
   int setDualDimensionLineCenter( int );
   int unsetDualDimensionLineCenter( );

   int addToleranceTextFormat( JtkPMITextFormat*& );
   int getToleranceTextFormat( JtkPMITextFormat*& ) const;
   int unsetToleranceTextFormat( );

   int getReferenceContent( JtkPMIReferenceContent& ) const;
   int setReferenceContent( JtkPMIReferenceContent );
   int unsetReferenceContent( );

   int addStyleText( JtkPMIText*& );
   int getStyleText( JtkPMIText*& ) const;
   int unsetStyleText( );

   int getAppendedTextSpaceFactor( double& ) const;
   int setAppendedTextSpaceFactor( double );
   int unsetAppendedTextSpaceFactor( );

   int getToleranceTextSpaceFactor( double& ) const;
   int setToleranceTextSpaceFactor( double );
   int unsetToleranceTextSpaceFactor( );

   int addGeneralToleranceISO( JtkPMIDimensionGeneralToleranceISO*& );
   int getGeneralToleranceISO( JtkPMIDimensionGeneralToleranceISO*& ) const;
   int unsetGeneralToleranceISO( );

   int getZeroToleranceSign( JtkPMIZeroToleranceSign& ZeroToleranceSign ) const;
   int setZeroToleranceSign( JtkPMIZeroToleranceSign ZeroToleranceSign );
   int unsetZeroToleranceSign( void );

   int addDualUnitSymbol( JtkPMIText*& DualUnitSymbol );
   int getDualUnitSymbol( int Index, JtkPMIText*& DualUnitSymbol ) const;
   int numDualUnitSymbol( int& Count ) const;
   int unsetDualUnitSymbol( int Index );

};
///////%{
//
// Class          : JtkPMIFastener
//
// Description    : JtkPMI class for the representation of Fasteners. It has the following properties:
//      <br/><b>symbolType:</b>               e.g. capScrew, hole, dowel, or other user-defined type
//      <br/><b>threaded:</b>               whether threaded or not
//      <br/><b>counterbored:</b>            whether counterbored or not
//      <br/><b>diameter[]:</b>               array of diameters
//      <br/><b>depth[]:</b>                  array of depths
//      <br/><b>axisDirection[3]:</b>         axis direction of hole etc
//      <br/><b>indexDirection[3]:</b>      index direction - user-defined
//      <br/><b>optDirection[3]:</b>         optional direction - user-defined
//      <br/><b>type:</b>                     user-defined type string to define the type of the Fastener
//      <br/><b>fastenerSubType:</b>         optional user-defined string to further clarify the type
//                                          of the Fastener
//      <br/><b>position:</b>               position of the Fastener in global space
//      <br/><b>GeneralText:</b>            A JtkPMIText* representing some general text
//      <br/><b>CoordinatedEntity:</b>      Multiple JtkPMIText* that specify a related entity in some undefined way
//      <br/><b>precision:</b>               The number of decimal places to display.
//      <br/><b>displayType:</b>            Whether to display the PMI Text flat to the screen or the surface.
//
// Enums          :   JtkPMIDisplayType:
//                        DisplayTypeFLATTOSURFACE -- display the text flat to the surface
//                        DisplayTypeFLATTOSCREEN -- display the text flat to the screen
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIFastener
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFastener : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIFastener )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIFastener( JtkUnitHierarchy* owner );
   virtual ~JtkPMIFastener( );

public:
   int getType( JtkString& ) const;
   int setType( const JtkString& );
   int unsetType( void );

   int getFastenerSubType( JtkString& ) const;
   int setFastenerSubType( const JtkString& );
   int unsetFastenerSubType( void );

   int getPosition( double&, double&, double& ) const;
   int setPosition( double, double, double );
   int unsetPosition( void );

   int getCounterbored( int& ) const;
   int setCounterbored( int );
   int unsetCounterbored( void );

   int getIndexDirection( double&, double&, double& ) const;
   int setIndexDirection( double, double, double );
   int unsetIndexDirection( void );

   int getAxisDirection( double&, double&, double& ) const;
   int setAxisDirection( double, double, double );
   int unsetAxisDirection( void );

   int getThreaded( int& ) const;
   int setThreaded( int );
   int unsetThreaded( void );

   int getSymbolType( JtkString& ) const;
   int setSymbolType( const JtkString& );
   int unsetSymbolType( void );

   int addDiameter( double );
   int numDiameters( int& count ) const;
   int getDiameter( int index, double& ) const;
   int setDiameter( int index, double );
   int unsetDiameter( int index );

   int addDepth( double );
   int numDepths( int& count ) const;
   int getDepth( int index, double& ) const;
   int setDepth( int index, double );
   int unsetDepth( int index );

   int getOptDirection( double&, double&, double& ) const;
   int setOptDirection( double, double, double );
   int unsetOptDirection( void );

   int addGeneralText( JtkPMIText*& );
   int getGeneralText( JtkPMIText*& ) const;
   int unsetGeneralText( );

   int addCoordinatedEntity( JtkPMIText*& );
   int getCoordinatedEntity( int index, JtkPMIText*& ) const;
   int numCoordinatedEntity( int& count ) const;
   int unsetCoordinatedEntity( int index );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getDisplayType( JtkPMIDisplayType& ) const;
   int setDisplayType( JtkPMIDisplayType );
   int unsetDisplayType( void );
};
///////%{
//
// Class          : JtkPMISurfaceFinish
//
// Description    : JtkPMI class for a Surface Finish. It has the following properties:
//      <br/><b>standard:</b>               surface finish standard
//      <br/><b>type:</b>                   basic, MRR, or MRP
//      <br/><b>modifier:</b>               whether modifier added to symbol
//      <br/><b>allAround:</b>              whether All Around added to symbol
//      <br/><b>allAroundLeader:</b>        Whether the All Around symbol is added to the Leader of the SurfaceFinish.
//      <br/><b>lay:</b>                    parallel, perpendicular, etc
//      <br/><b>machiningAllowance:</b>     also known as materialRemoval
//      <br/><b>upperDelta:</b>             upper and
//      <br/><b>lowerDelta:</b>             lower tolerance values for the machiningAllowance
//      <br/><b>direction[3]:</b>
//      <br/><b>roughness:</b>
//      <br/><b>maxRoughness:</b>
//      <br/><b>minRoughness:</b>
//      <br/><b>roughnessSpacing:</b>
//      <br/><b>roughnessCutoff:</b>        See the relevant Standard for details of these.
//      <br/><b>wavinessHeight:</b>         Although these are essentially numeric values,
//      <br/><b>wavinessSpacing:</b>        the Standards require them to be strings.
//      <br/><b>roughness2:</b>
//      <br/><b>maxRoughness2:</b>
//      <br/><b>minRoughness2:</b>
//      <br/><b>roughness3:</b>
//      <br/><b>ProcessText:</b>            Process Text element
//      <br/><b>LayText:</b>                Lay Text element
//      <br/><b>bottomExtensionLine:</b>    Default value = false.
//      <br/><b>precision:</b>              The number of decimal places to display.
//      <br/><b>zeroToleranceDisplay:</b>   controls the display of a zero valued tolerance.
//      <br/><b>toleranceLeadingZero:</b>   whether to display leading zeros in the
//                                          tolerance value.
//      <br/><b>invertText:</b>             whether the text of the surface finish symbol is
//                                          inverted.
//      <br/><b>toleranceTrailingZero:</b>  whether trailing zeros on tolerance values are
//                                          displayed.
//      <br/><b>toleranceDisplay:</b>
//      <br/><b>parenthesis:</b>            The type of parenthesis(es) displayed if any.
//      <br/><b>singleLine:</b>             Whether the lay and roughness values are displayed
//                                          on a single line. singleLine is applicable only
//                                          when standard on the corresponding SurfaceFinish
//                                          is ESKD.
//      <br/><b>invertSymbol:</b>           Whether the surface finish symbol is inverted.
//      <br/><b>jisSurfaceTexture:</b>      When standard is JIS, jisSurfaceTexture is the number of repeats of the JIS basic symbol
//
// Enums          :  JtkPMISurfaceFinishLay:
//                        LayPARALLEL --
//                        LayMULTIDIRECTIONAL --
//                        LayPERPENDICULAR --
//                        LayCIRCULAR --
//                        LayPARTICULATE --
//                        LayANGULARBOTH --
//                        LayRADIAL --
//                        LayUSERDEFINED -- see LayText.
//
//                     JtkPMISurfaceFinishStandard:
//                        SurfaceFinishStandardJIS --
//                        SurfaceFinishStandardANSI_Y1436_1993 --
//                        SurfaceFinishStandardISO --
//                        SurfaceFinishStandardASME_Y1436M_1996 --
//                        SurfaceFinishStandardDIN --
//                        SurfaceFinishStandardGB --
//                        SurfaceFinishStandardISO_1302_2002 --
//                        SurfaceFinishStandardESKD --
//                        SurfaceFinishStandardDIN_EN_ISO_1302_2002 --
//
//                     JtkPMISurfaceFinishType:
//                        SurfaceFinishTypeBASIC --
//                        SurfaceFinishTypeMRR --
//                        SurfaceFinishTypeMRP --
//
//                     JtkPMIDimensionToleranceDisplay:
//                        ToleranceDisplayMINUSLIMIT1 --
//                        ToleranceDisplayBILATERAL --
//                        ToleranceDisplayPLUSLIMIT1 --
//                        ToleranceDisplayPLUSLIMIT2 --
//                        ToleranceDisplayEQUALBILATERAL --
//                        ToleranceDisplayMINUSLIMIT2 --
//                        ToleranceDisplayUPPERUNILATERAL --
//                        ToleranceDisplayLOWERUNILATERAL --
//
//                     JtkPMIDimensionZeroToleranceDisplay:
//                        ZeroToleranceDisplayDISPLAYZERO --
//                        ZeroToleranceDisplayBLANK --
//                        ZeroToleranceDisplaySUPPRESSTRAILINGZERO --
//                        ZeroToleranceDisplayOMIT --
//
//                     JtkPMIParenthesis:
//                        ParenthesisNone --
//                        ParenthesisLeft --
//                        ParenthesisRight --
//                        ParenthesisBoth --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMISurfaceFinish
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMISurfaceFinish : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMISurfaceFinish )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMISurfaceFinish( JtkUnitHierarchy* owner );
   virtual ~JtkPMISurfaceFinish( );

public:
   int getDirection( double&, double&, double& ) const;
   int setDirection( double, double, double );
   int unsetDirection( void );

   int getUpperDelta( double& ) const;
   int setUpperDelta( double );
   int unsetUpperDelta( void );

   int getLowerDelta( double& ) const;
   int setLowerDelta( double );
   int unsetLowerDelta( void );

   int getWavinessHeight( JtkString& ) const;
   int setWavinessHeight( const JtkString& );
   int unsetWavinessHeight( void );

   int getRoughness2( JtkString& ) const;
   int setRoughness2( const JtkString& );
   int unsetRoughness2( void );

   int getRoughness( JtkString& ) const;
   int setRoughness( const JtkString& );
   int unsetRoughness( void );

   int getModifier( int& ) const;
   int setModifier( int );
   int unsetModifier( void );

   int getMaxRoughness2( JtkString& ) const;
   int setMaxRoughness2( const JtkString& );
   int unsetMaxRoughness2( void );

   int getRoughness3( JtkString& ) const;
   int setRoughness3( const JtkString& );
   int unsetRoughness3( void );

   int getLay( JtkPMISurfaceFinishLay& ) const;
   int setLay( JtkPMISurfaceFinishLay );
   int unsetLay( void );

   int getStandard( JtkPMISurfaceFinishStandard& ) const;
   int setStandard( JtkPMISurfaceFinishStandard );
   int unsetStandard( void );

   int getType( JtkPMISurfaceFinishType& ) const;
   int setType( JtkPMISurfaceFinishType );
   int unsetType( void );

   int getMaxRoughness( JtkString& ) const;
   int setMaxRoughness( const JtkString& );
   int unsetMaxRoughness( void );

   int getMachiningAllowance( JtkString& ) const;
   int setMachiningAllowance( const JtkString& );
   int unsetMachiningAllowance( void );

   int getMinRoughness( JtkString& ) const;
   int setMinRoughness( const JtkString& );
   int unsetMinRoughness( void );

   int getMinRoughness2( JtkString& ) const;
   int setMinRoughness2( const JtkString& );
   int unsetMinRoughness2( void );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( void );

   int getAllAroundLeader( int& ) const;
   int setAllAroundLeader( int );
   int unsetAllAroundLeader( void );

   int getWavinessSpacing( JtkString& ) const;
   int setWavinessSpacing( const JtkString& );
   int unsetWavinessSpacing( void );

   int getRoughnessSpacing( JtkString& ) const;
   int setRoughnessSpacing( const JtkString& );
   int unsetRoughnessSpacing( void );

   int getRoughnessCutoff( JtkString& ) const;
   int setRoughnessCutoff( const JtkString& );
   int unsetRoughnessCutoff( void );

   int addProcessText( JtkPMIText*& );
   int getProcessText( JtkPMIText*& ) const;
   int unsetProcessText( );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getToleranceDisplay( JtkPMIDimensionToleranceDisplay& ) const;
   int setToleranceDisplay( JtkPMIDimensionToleranceDisplay );
   int unsetToleranceDisplay( void );

   int getBottomExtensionLine( int& ) const;
   int setBottomExtensionLine( int );
   int unsetBottomExtensionLine( void );

   int getZeroToleranceDisplay( JtkPMIDimensionZeroToleranceDisplay& ) const;
   int setZeroToleranceDisplay( JtkPMIDimensionZeroToleranceDisplay );
   int unsetZeroToleranceDisplay( void );

   int getToleranceLeadingZero( int& ) const;
   int setToleranceLeadingZero( int );
   int unsetToleranceLeadingZero( void );

   int getInvertText( int& ) const;
   int setInvertText( int );
   int unsetInvertText( void );

   int getToleranceTrailingZero( int& ) const;
   int setToleranceTrailingZero( int );
   int unsetToleranceTrailingZero( void );

   int getParenthesis( JtkPMIParenthesis& ) const;
   int setParenthesis( JtkPMIParenthesis );
   int unsetParenthesis( void );

   int getSingleLine( int& ) const;
   int setSingleLine( int );
   int unsetSingleLine( void );

   int getInvertSymbol( int& ) const;
   int setInvertSymbol( int );
   int unsetInvertSymbol( void );

   int getJisSurfaceTexture( unsigned int& ) const;
   int setJisSurfaceTexture( unsigned int );
   int unsetJisSurfaceTexture( void );

   int getLayText( JtkPMIText*& ) const;
   int addLayText( JtkPMIText*& );
   int unsetLayText( void );
};

//forward declaration
class JtkPMIDatumFeatureSymbol;

///////%{
//
// Class          : JtkPMIFeatureControlFrameDatumReference
//
// Description    : Jtk PMI Member class containing information referencing a datum.
//         <br/><b>modifier:</b>               lmc, mmc, or rfs
//         <br/><b>datumRef:</b>               reference to the DatumFeatureSymbol element, if it exists
//         <br/><b>label:</b>                  the label (e.g. "A") of the DatumFeaureSymbol.
//         <br/><b>projected:</b>              Whether the referenced DatumFeatureSymbol is a projected feature.
//         <br/><b>TextLabel:</b>              A single JtkPMIText* that allows for the case where the label is
//                                             not simple text, but, for example, contains symbols. The label
//                                             attribute and the TextLabel <b>should not</b> be used together.
//         <br/><b>FreeState:</b>              free state refinement
//
//
// Enums          :   JtkPMIFCFModifier:
//                        FCFModifierLMC --
//                        FCFModifierMMC --
//                        FCFModifierRFS --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIFeatureControlFrameDatumReference
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFeatureControlFrameDatumReference : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIFeatureControlFrameDatumReference )

   JtkPMIFeatureControlFrameDatumReference( );
   virtual ~JtkPMIFeatureControlFrameDatumReference( );

public:
   int setModifier( JtkPMIFCFModifier );
   int getModifier( JtkPMIFCFModifier& ) const;
   int unsetModifier( );

   int setLabel( const JtkString& );
   int getLabel( JtkString& ) const;
   int unsetLabel( );

   int setReference( int, int, const JtkString& = JtkString( ), int = -1 );
   int getReference( int&, int&, JtkString&, int& ) const;
   int unsetReference( );

   int setProjected( int );
   int getProjected( int& ) const;
   int unsetProjected( );

   int addTextLabel( JtkPMIText*& );
   int getTextLabel( JtkPMIText*& ) const;
   int unsetTextLabel( );

   int addFreeState( );
   int getFreeState( ) const;
   int unsetFreeState( );
};

///////%{
//
// Class          : JtkPMIFeatureControlFrameDatumGroup
//
// Description    : JtkPMIMember class representing a DatumGroup
//         <br/><b>Datum:</b>               One or more JtkPMIFeatureControlFrameDatumReference
//         <br/><b>ExtendedText:</b>           Text after the DatumReference(s) to clarify or customize
//                                             the datum feature boundary.
//
//
// Enums          :   
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIFeatureControlFrameDatumGroup
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFeatureControlFrameDatumGroup : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIFeatureControlFrameDatumGroup )

   JtkPMIFeatureControlFrameDatumGroup( );
   virtual ~JtkPMIFeatureControlFrameDatumGroup( );

public:
   int numDatum( int& ) const;
   int addDatum( JtkPMIFeatureControlFrameDatumReference*& );
   int getDatum( int Index, JtkPMIFeatureControlFrameDatumReference*& ) const;
   int unsetDatum( int Index );

   int addExtendedText( JtkPMIText*& );
   int getExtendedText( JtkPMIText*& ) const;
   int unsetExtendedText( );

};

///////%{
//
// Class          : JtkPMIFeatureControlFrameIndicator
//
// Description    : JtkPMIMember class representing a Feature control frame indicator
//         <br/><b>type:</b>                   The type of indicator (required)
//         <br/><b>symbol:</b>                 The symbol for the controlled geometric characteristic (required)
//         <br/><b>DatumGroup:</b>             A DatumGroup (optional)
//
//
// Enums          : JtkPMIFCFIndicator:
//                        FCFIndicatorINTERSECTIONPLANE --
//                        FCFIndicatorORIENTATIONPLANE --
//                        FCFIndicatorCOLLECTIONPLANE --
//                        FCFIndicatorDIRECTIONFEATURE --
//
//                  JtkPMIFCFIndicatorSymbol:
//                        FCFIndicatorSymbolPARALLEL --
//                        FCFIndicatorSymbolPERPENDICULAR -- 
//                        FCFIndicatorSymbolANGULAR -- 
//                        FCFIndicatorSymbolINCLUDING --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMIFeatureControlFrameIndicator
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFeatureControlFrameIndicator : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMIFeatureControlFrameIndicator )

   JtkPMIFeatureControlFrameIndicator( );
   virtual ~JtkPMIFeatureControlFrameIndicator( );

public:
   int setType( JtkPMIFCFIndicator type );
   int getType( JtkPMIFCFIndicator& type ) const;
   int unsetType( );

   int setSymbol( JtkPMIFCFIndicatorSymbol symbol );
   int getSymbol( JtkPMIFCFIndicatorSymbol& symbol ) const;
   int unsetSymbol( );

   int addDatumGroup( JtkPMIFeatureControlFrameDatumGroup*& );
   int getDatumGroup( JtkPMIFeatureControlFrameDatumGroup*& ) const;
   int unsetDatumGroup( );

};

///////%{
//
// Class          : JtkPMIFeatureControlFrame
//
// Description    : JtkPMI class for Feature Control Frames. It has the following properties:
//      <br/><b>standard:</b>                  as for Dimensions
//      <br/><b>characteristic:</b>            position, straightness, etc
//      <br/><b>direction:</b>                 direction of tolerance application
//      <br/><b>allAround:</b>                 all around symbol
//      <br/><b>maxBonus:</b>                  true if a max bonus tolerance is used
//      <br/><b>maxBonusValue:</b>             max bonus tolerance
//      <br/><b>profileType:</b>               profile type
//      <br/><b>profileValue:</b>              profile tolerance value
//      <br/><b>profileValue2:</b>             profile tolerance value2 (used when there are two compartments)
//      <br/><b>allOver:</b>                   indicates the tolerance applies all over the 3
//                                             dimensional profile of the part
//      <br/><b>maxBonusPrecision:</b>
//      <br/><b>angleFormat:</b>
//      <br/><b>projectedPrecision:</b>
//      <br/><b>leadingZero:</b>               Whether leading zeros on the ToleranceCompartment value
//                                             are displayed.
//      <br/><b>trailingZero:</b>              Whether trailing zeros on the ToleranceCompartment value
//                                             are displayed
//      <br/><b>datumOnLeader:</b>             Whether the Leader has an intermediate datum symbol
//                                             rather than going directly to the target geometry and,
//                                             if it has, whether the symbol is solid or filled.
//      <br/><b>projectedBelow:</b>            Whether any projected tolerance zone is displayed
//                                             below the tolerance compartment. By default it is
//                                             incorperated into the tolerance compartment.
//      <br/><b>fcfTextUnderline:</b>          How the FCFText elements on the FeatureControlFrame are
//                                             underlined.
//      <br/><b>Text:</b>                      A JtkPMIText for a general Text element.
//      <br/><b>FCFText:</b>                   Up to four positioned text on the pmi.
//      <br/><b>ToleranceCompartment:</b>      one or more of these sub-elements. If there are two or more, the
//                                             FCF is composite.
//
//      Each FCFText can have the following properties:
//         <br/><b>position:</b>             Before, After, Above or Below
//         <br/><b>Text:</b>                 A single JtkPMIText for this FCFText
//
//      Each tolerance compartment can have the following:
//         <br/><b>value:</b>                   tolerance value
//         <br/><b>precision:</b>               number of decimal places
//         <br/><b>modifier:</b>                lmc, mmc, or rfs
//         <br/><b>zoneShape:</b>               diametral or spherical
//         <br/><b>projected:</b>               flag indicating a projected tolerance
//         <br/><b>projectedValue:</b>          value for projection
//         <br/><b>projectionVector:</b>        direction of projection
//         <br/><b>tangentPlane:</b>            ditto, tangent plane
//         <br/><b>maxBonus:</b>                true if a max bonus tolerance is used
//         <br/><b>maxBonusValue:</b>           max bonus tolerance
//         <br/><b>unitBasis:</b>               true if a unit basis zone refinement is used
//         <br/><b>unitBasisValue:</b>          unit basis zone refinement
//         <br/><b>commonZone:</b>              whether the common zone refinement is present
//         <br/><b>prefix:</b>                  general prefix text, which appears before processing
//                                              other attributes
//         <br/><b>suffix:</b>                  general suffix text, which appears only after processing
//                                              the other attributes
//         <br/><b>unequal:</b>                 indicates a profile tolerance zone is unequally disposed
//         <br/><b>unequalValue:</b>            the outward portion of an unequally disposed profile
//                                              tolerance zone
//         <br/><b>unequalDisplay:</b>          How any unequal symbols in this tolerance compartment should be displayed.
//         <br/><b>maxBonusValueString:</b>     Non-numerical maximum bonus tolerance. Overrides maxBonusValue.
//         <br/><b>Statistical:</b>             statistical refinement
//         <br/><b>FreeState:</b>               free state refinement
//         <br/><b>Primary:</b>                 first DatumGroup
//         <br/><b>Secondary:</b>               2nd DatumGroup
//         <br/><b>Tertiary</b>:                3rd DatumGroup
//         <br/><b>TextUnitBasisValue:</b>      JtkPMIText based value for the unit basis zone refinement
//                                              The unitBasisValue attribute and the TextUnitBasisValue
//                                              should not be used together.
//         <br/><b>TextPrefix:</b>              JtkPMIText based value for the prefix. prefix and TextPrefix
//                                              should not be used together.
//         <br/><b>TextSuffix:</b>              JtkPMIText based value for the suffix. prefix and TextSuffix
//                                              should not be used together.
//         <br/><b>BeforeIndicator:</b>         Any number of indicators to the left of the FCF, ordered left to right
//         <br/><b>AfterIndicator:</b>          Any number of indicators to the right of the FCF, ordered left to right
//
//      Each DatumGroup can have mulitple DatumReferences belonging to it expressed via the following properties:
//         <br/><b>modifier:</b>               lmc, mmc, or rfs
//         <br/><b>datumRef:</b>               reference to the DatumFeatureSymbol element, if it exists
//         <br/><b>label:</b>                  the label (e.g. "A") of the DatumFeaureSymbol.
//         <br/><b>projected:</b>              Whether the DatumFeatureSymbol is a projected feature.
//         <br/><b>TextLabel:</b>              this single JtkPMIText* that allows for the case where the label is
//                                             not simple text, but, for example, contains symbols. The label
//                                             attribute and the TextLabel sub-element <b>should not</b> be used together.
//         <br/><b>FreeState:</b>              free state refinement
//      Additionally it can also have:
//         <br/><b>ExtendedText:</b>           Text after the DatumReference(s) to clarify or customize
//                                             the datum feature boundary.
//
//
// Enums          :   JtkPMIFCFCharacteristic:
//                        CharacteristicPROFILEOFALINE --
//                        CharacteristicCIRCULARRUNOUT --
//                        CharacteristicPERPENDICULARITY --
//                        CharacteristicPOSITION --
//                        CharacteristicTOTALRUNOUT --
//                        CharacteristicPROFILEOFASURFACE --
//                        CharacteristicCYLINDRICITY --
//                        CharacteristicSYMMETRY --
//                        CharacteristicANGULARITY --
//                        CharacteristicPARALLELISM --
//                        CharacteristicCONCENTRICITY --
//                        CharacteristicFLATNESS --
//                        CharacteristicCIRCULARITY --
//                        CharacteristicSTRAIGHTNESS --
//                        CharacteristicAXISINTERSECTION --
//
//                     JtkPMIFCFProfileType:
//                        ProfileTypeBILATERAL --
//                        ProfileTypeUNILATERALINSIDE --
//                        ProfileTypeUNILATERALOUTSIDE --
//                        ProfileTypeBILATERALUNEQUAL --
//
//                     JtkPMIFCFDatumGroup:
//                        PRIMARY --
//                        SECONDARY --
//                        TERTIARY --
//
//                     JtkPMIFCFZoneShape:
//                        FCFZoneShapeDIAMETER --
//                        FCFZoneShapeSPHERICALDIAMETER --
//                        FCFZoneShapeSQUARE --
//
//                     JtkPMIFCFModifier:
//                        FCFModifierLMC --
//                        FCFModifierMMC --
//                        FCFModifierRFS --
//
//                     JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
//                     JtkPMIAngleFormat:
//                        AngleFormatDEGREES --
//                        AngleFormatSECONDS --
//                        AngleFormatMINUTES --
//                        AngleFormatWHOLEDEGREES -- 
//
//                     JtkPMIDatumOnLeader:
//                        DatumOnLeaderNONE --
//                        DatumOnLeaderSOLID --
//                        DatumOnLeaderFILLED --
//
//                     JtkPMIFCFUnequalDisplay:
//                        UnequalDisplayCIRCLEU -- display as a circled U 
//                        UnequalDisplayUZ -- display as UZ
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIFeatureControlFrame
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFeatureControlFrame : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIFeatureControlFrame )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIFeatureControlFrame( JtkUnitHierarchy* owner );
   virtual ~JtkPMIFeatureControlFrame( );

public:
   int getDirection( double&, double&, double& ) const;
   int setDirection( double, double, double );
   int unsetDirection( void );

   int getCharacteristic( JtkPMIFCFCharacteristic& ) const;
   int setCharacteristic( JtkPMIFCFCharacteristic );
   int unsetCharacteristic( void );

   int getProfileValue2( double& ) const;
   int setProfileValue2( double );
   int unsetProfileValue2( void );

   int getProfileValue( double& ) const;
   int setProfileValue( double );
   int unsetProfileValue( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( void );

   int getAllOver( int& ) const;
   int setAllOver( int );
   int unsetAllOver( void );

   int getMaxBonus( int& ) const;
   int setMaxBonus( int );
   int unsetMaxBonus( void );

   int getProfileType( JtkPMIFCFProfileType& ) const;
   int setProfileType( JtkPMIFCFProfileType );
   int unsetProfileType( void );

   int getMaxBonusValue( double& ) const;
   int setMaxBonusValue( double );
   int unsetMaxBonusValue( void );

   int addText( JtkPMIText*& );
   int getText( JtkPMIText*& ) const;
   int unsetText( );

   int addFCFText( );
   int numFCFText( int& number ) const;
   int unsetFCFText( int index );

   int addFCFTextText( int index, JtkPMIText*& );
   int getFCFTextText( int index, JtkPMIText*& ) const;
   int unsetFCFTextText( int index );

   int setFCFTextPosition( int index, JtkPMIDimensionPlacement pos );
   int getFCFTextPosition( int index, JtkPMIDimensionPlacement& pos ) const;
   int unsetFCFTextPosition( int index );

   int addToleranceCompartment( );
   int numToleranceCompartment( int& number ) const;
   int unsetToleranceCompartment( int tc );

   int setToleranceCompartmentValue( int tc, const JtkString& );
   int getToleranceCompartmentValue( int tc, JtkString& ) const;
   int unsetToleranceCompartmentValue( int tc );

   int setToleranceCompartmentProjectedValue( int tc, const JtkString& );
   int getToleranceCompartmentProjectedValue( int tc, JtkString& ) const;
   int unsetToleranceCompartmentProjectedValue( int tc );

   int setToleranceCompartmentPrecision( int tc, int );
   int getToleranceCompartmentPrecision( int tc, int& ) const;
   int unsetToleranceCompartmentPrecision( int tc );

   int setToleranceCompartmentModifier( int tc, JtkPMIFCFModifier );
   int getToleranceCompartmentModifier( int tc, JtkPMIFCFModifier& ) const;
   int unsetToleranceCompartmentModifier( int tc );

   int setToleranceCompartmentZoneShape( int tc, JtkPMIFCFZoneShape );
   int getToleranceCompartmentZoneShape( int tc, JtkPMIFCFZoneShape& ) const;
   int unsetToleranceCompartmentZoneShape( int tc );

   int setToleranceCompartmentProjected( int tc, int );
   int getToleranceCompartmentProjected( int tc, int& ) const;
   int unsetToleranceCompartmentProjected( int tc );

   int setToleranceCompartmentProjectionVector( int tc, double v1, double v2, double v3 );
   int getToleranceCompartmentProjectionVector( int tc, double& v1, double& v2, double& v3 ) const;
   int unsetToleranceCompartmentProjectionVector( int tc );

   int setToleranceCompartmentTangentPlane( int tc, int );
   int getToleranceCompartmentTangentPlane( int tc, int& ) const;
   int unsetToleranceCompartmentTangentPlane( int tc );

   int setToleranceCompartmentMaxBonus( int tc, int );
   int getToleranceCompartmentMaxBonus( int tc, int& ) const;
   int unsetToleranceCompartmentMaxBonus( int tc );

   int setToleranceCompartmentMaxBonusValue( int tc, double );
   int getToleranceCompartmentMaxBonusValue( int tc, double& ) const;
   int unsetToleranceCompartmentMaxBonusValue( int tc );

   int setToleranceCompartmentUnitBasis( int tc, int );
   int getToleranceCompartmentUnitBasis( int tc, int& ) const;
   int unsetToleranceCompartmentUnitBasis( int tc );

   int setToleranceCompartmentUnitBasisValue( int tc, const JtkString& );
   int getToleranceCompartmentUnitBasisValue( int tc, JtkString& ) const;
   int unsetToleranceCompartmentUnitBasisValue( int tc );

   int addToleranceCompartmentTextUnitBasisValue( int tc, JtkPMIText*& );
   int getToleranceCompartmentTextUnitBasisValue( int tc, JtkPMIText*& ) const;
   int unsetToleranceCompartmentTextUnitBasisValue( int tc );

   int setToleranceCompartmentCommonZone( int tc, int );
   int getToleranceCompartmentCommonZone( int tc, int& ) const;
   int unsetToleranceCompartmentCommonZone( int tc );

   int addToleranceCompartmentFreeState( int tc );
   int getToleranceCompartmentFreeState( int tc ) const;
   int unsetToleranceCompartmentFreeState( int tc );

   int addToleranceCompartmentStatistical( int tc );
   int getToleranceCompartmentStatistical( int tc ) const;
   int unsetToleranceCompartmentStatistical( int tc );

   int setToleranceCompartmentPrefix( int tc, const JtkString& );
   int getToleranceCompartmentPrefix( int tc, JtkString& ) const;
   int unsetToleranceCompartmentPrefix( int tc );

   int addToleranceCompartmentTextPrefix( int tc, JtkPMIText*& );
   int getToleranceCompartmentTextPrefix( int tc, JtkPMIText*& ) const;
   int unsetToleranceCompartmentTextPrefix( int tc );

   int setToleranceCompartmentSuffix( int tc, const JtkString& );
   int getToleranceCompartmentSuffix( int tc, JtkString& ) const;
   int unsetToleranceCompartmentSuffix( int tc );

   int addToleranceCompartmentTextSuffix( int tc, JtkPMIText*& );
   int getToleranceCompartmentTextSuffix( int tc, JtkPMIText*& ) const;
   int unsetToleranceCompartmentTextSuffix( int tc );

   int setToleranceCompartmentUnequal( int tc, int );
   int getToleranceCompartmentUnequal( int tc, int& ) const;
   int unsetToleranceCompartmentUnequal( int tc );

   int setToleranceCompartmentUnequalValue( int tc, const JtkString& );
   int getToleranceCompartmentUnequalValue( int tc, JtkString& ) const;
   int unsetToleranceCompartmentUnequalValue( int tc );

   int setToleranceCompartmentUnequalDisplay( int tc, JtkPMIFCFUnequalDisplay );
   int getToleranceCompartmentUnequalDisplay( int tc, JtkPMIFCFUnequalDisplay& ) const;
   int unsetToleranceCompartmentUnequalDisplay( int tc );

   int setToleranceCompartmentMaxBonusValueString( int tc, const JtkString& );
   int getToleranceCompartmentMaxBonusValueString( int tc, JtkString& ) const;
   int unsetToleranceCompartmentMaxBonusValueString( int tc );

   int addToleranceCompartmentDatum( int tc, JtkPMIFCFDatumGroup dg );
   int numToleranceCompartmentDatum( int tc, JtkPMIFCFDatumGroup dg, int& number ) const;
   int unsetToleranceCompartmentDatum( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int setToleranceCompartmentDatumModifier( int tc, JtkPMIFCFDatumGroup dg, int datumItem, JtkPMIFCFModifier );
   int getToleranceCompartmentDatumModifier( int tc, JtkPMIFCFDatumGroup dg, int datumItem, JtkPMIFCFModifier& ) const;
   int unsetToleranceCompartmentDatumModifier( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int setToleranceCompartmentDatumLabel( int tc, JtkPMIFCFDatumGroup dg, int datumItem, const JtkString& );
   int getToleranceCompartmentDatumLabel( int tc, JtkPMIFCFDatumGroup dg, int datumItem, JtkString& ) const;
   int unsetToleranceCompartmentDatumLabel( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int setToleranceCompartmentDatumReference( int tc, JtkPMIFCFDatumGroup dg, int datumItem, int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int getToleranceCompartmentDatumReference( int tc, JtkPMIFCFDatumGroup dg, int datumItem, int& dstId, int& dstType, JtkString& path ) const;
   int getToleranceCompartmentDatumReference( int tc, JtkPMIFCFDatumGroup dg, int datumItem, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int unsetToleranceCompartmentDatumReference( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int setToleranceCompartmentDatumProjected( int tc, JtkPMIFCFDatumGroup dg, int datumItem, int );
   int getToleranceCompartmentDatumProjected( int tc, JtkPMIFCFDatumGroup dg, int datumItem, int& ) const;
   int unsetToleranceCompartmentDatumProjected( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int addToleranceCompartmentDatumTextLabel( int tc, JtkPMIFCFDatumGroup dg, int datumItem, JtkPMIText*& );
   int getToleranceCompartmentDatumTextLabel( int tc, JtkPMIFCFDatumGroup dg, int datumItem, JtkPMIText*& ) const;
   int unsetToleranceCompartmentDatumTextLabel( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int addToleranceCompartmentDatumFreeState( int tc, JtkPMIFCFDatumGroup dg, int datumItem );
   int getToleranceCompartmentDatumFreeState( int tc, JtkPMIFCFDatumGroup dg, int datumItem ) const;
   int unsetToleranceCompartmentDatumFreeState( int tc, JtkPMIFCFDatumGroup dg, int datumItem );

   int addToleranceCompartmentExtendedText( int tc, JtkPMIFCFDatumGroup dg, JtkPMIText*& );
   int getToleranceCompartmentExtendedText( int tc, JtkPMIFCFDatumGroup dg, JtkPMIText*& ) const;
   int unsetToleranceCompartmentExtendedText( int tc, JtkPMIFCFDatumGroup dg );

   int addToleranceCompartmentBeforeIndicator( int tc, JtkPMIFeatureControlFrameIndicator*& );
   int numToleranceCompartmentBeforeIndicator( int tc, int& num ) const;
   int getToleranceCompartmentBeforeIndicator( int tc, int bi, JtkPMIFeatureControlFrameIndicator*& ) const;
   int unsetToleranceCompartmentBeforeIndicator( int tc, int bi );

   int addToleranceCompartmentAfterIndicator( int tc, JtkPMIFeatureControlFrameIndicator*& );
   int numToleranceCompartmentAfterIndicator( int tc, int& num ) const;
   int getToleranceCompartmentAfterIndicator( int tc, int ai, JtkPMIFeatureControlFrameIndicator*& ) const;
   int unsetToleranceCompartmentAfterIndicator( int tc, int ai );

   int addPrimary( JtkPMIFeatureControlFrameDatumGroup*& );
   int getPrimary( JtkPMIFeatureControlFrameDatumGroup*& ) const;
   int unsetPrimary( );

   int addSecondary( JtkPMIFeatureControlFrameDatumGroup*& );
   int getSecondary( JtkPMIFeatureControlFrameDatumGroup*& ) const;
   int unsetSecondary( );

   int addTertiary( JtkPMIFeatureControlFrameDatumGroup*& );
   int getTertiary( JtkPMIFeatureControlFrameDatumGroup*& ) const;
   int unsetTertiary( );

   int getProjectedPrecision( int& ) const;
   int setProjectedPrecision( int );
   int unsetProjectedPrecision( void );

   int getAngleFormat( JtkPMIAngleFormat& ) const;
   int setAngleFormat( JtkPMIAngleFormat );
   int unsetAngleFormat( void );

   int getMaxBonusPrecision( int& ) const;
   int setMaxBonusPrecision( int );
   int unsetMaxBonusPrecision( void );

   int getLeadingZero( int& ) const;
   int setLeadingZero( int );
   int unsetLeadingZero( void );

   int getTrailingZero( int& ) const;
   int setTrailingZero( int );
   int unsetTrailingZero( void );

   int getDatumOnLeader( JtkPMIDatumOnLeader& ) const;
   int setDatumOnLeader( JtkPMIDatumOnLeader );
   int unsetDatumOnLeader( void );

   int getProjectedBelow( int& ) const;
   int setProjectedBelow( int );
   int unsetProjectedBelow( );

   int getFCFTextUnderline( JtkPMIFCFTextUnderline& ) const;
   int setFCFTextUnderline( JtkPMIFCFTextUnderline );
   int unsetFCFTextUnderline( );
};


//forward declaration
class JtkPMIDatumTarget;
///////%{
//
// Class          : JtkPMIDatumFeatureSymbol
//
// Description    : JtkPMI class for Datum Feature Symbols. It can have the following properties:
//      <br/><b>standard:</b>                  As for Dimensions.
//      <br/><b>label:</b>                     e.g. "A"
//      <br/><b>DatumTargetReferences:</b>     Datum Targets associated with this DFS.
//      <br/><b>individuallyApplied:</b>
//      <br/><b>datumOnLeader:</b>             Whether the datum symbol appears on the Leader rather
//                                             than the target geometry and, if it does, whether it is
//                                             solid or filled.
//      <br/><b>allAround:</b>                 Whether the All Around symbol is added
//      <br/><b>DatumFeatureSymbolText:</b>    Text elements other than the label
//
// Enums          : JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
//                   JtkPMIDatumOnLeader:
//                        DatumOnLeaderNONE --
//                        DatumOnLeaderSOLID --
//                        DatumOnLeaderFILLED --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIDatumFeatureSymbol
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIDatumFeatureSymbol : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIDatumFeatureSymbol )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIDatumFeatureSymbol( JtkUnitHierarchy* owner );
   virtual ~JtkPMIDatumFeatureSymbol( );

public:
   int numDatumTargetReferences( int& ) const;
   int addDatumTargetReference( int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int getDatumTargetReference( int, int& dstId, int& dstType, JtkString& path ) const;
   int getDatumTargetReference( int, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int unsetDatumTargetReference( int );

   int getIndividuallyApplied( int& ) const;
   int setIndividuallyApplied( int );
   int unsetIndividuallyApplied( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getLabel( JtkString& ) const;
   int setLabel( const JtkString& );
   int unsetLabel( void );

   int getDatumOnLeader( JtkPMIDatumOnLeader& ) const;
   int setDatumOnLeader( JtkPMIDatumOnLeader );
   int unsetDatumOnLeader( void );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( void );

   int addDatumFeatureSymbolText( JtkPMIDimensionText*& );
   int getDatumFeatureSymbolText( int index, JtkPMIDimensionText*& ) const;
   int numDatumFeatureSymbolText( int& number ) const;
   int unsetDatumFeatureSymbolText( int index );
};
///////%{
//
// Class          : JtkPMIDatumTarget
//
// Description    : JtkPMI class for Datum Targets. It has the following properties:
//      <br/><b>standard:</b>                     as for Dimensions
//      <br/><b>label:</b>                        label of parent Datum, e.g. "A". Note the Datum Target can exist without a DFS.
//      <br/><b>index:</b>                        index of the Datum Target in its DFS, if it exists
//      <br/><b>type:</b>                         point, line, circular, rectangular, cylindrical or arbitrary
//      <br/><b>planar:</b>                       whether planar or not
//      <br/><b>diameter:</b>                     diameter, for circular targets
//      <br/><b>innerDiameter:</b>                inner diameter, for circular targets
//      <br/><b>length:</b>                       if rectangular
//      <br/><b>width:</b>                        if rectangular
//      <br/><b>point1:</b>                       first point
//      <br/><b>point2:</b>                       second point - only for cylindrical and line targets
//      <br/><b>movable:</b>                      true if the DatumTarget is movable
//      <br/><b>movableTargetStubDirection:</b>   the left/right direction of the bird-beak.
//                                                movableTargetStubDirection should not be used with
//                                                movableModifierAngle.
//      <br/><b>movableTargetStubLength:</b>      the length of the first segment of the leader (in metres)
//      <br/><b>textStubDirection:</b>            if the text of the DatumTarget is outside the DatumTargetSymbol,
//                                                then this specifies whether the text is to the right or left of
//                                                the symbol.
//      <br/><b>textStubLength:</b>               if the text of the DatumTarget is outside the DatumTargetSymbol,
//                                                then this specifies the length (in metres) of the stub line
//                                                joining the text to the symbol.
//      <br/><b>areaShape:</b>                    The shape of the target area according to the area
//                                                specification segment of the DatumTarget symbol.
//      <br/><b>shapeTextOutsideSymbol:</b>       Whether the text that describes the shape of the
//                                                target area lies outside the DatumTarget symbol. The text
//                                                usually lies inside the area specification segment of the
//                                                DatumTarget symbol.
//      <br/><b>size:</b>                         The size of the DatumTarget if the type is arbitrary.
//      <br/><b>movableModifierAngle:</b>         The direction in which a movable DatumTarget may
//                                                move relative to the line across the DatumTarget in
//                                                radians. The bird-beak symbol points in this direction.
//                                                movableModifierAngle should not be used with
//                                                movableTargetStubDirection.
//      <br/><b>precision:</b>                    The number of decimal places to display.
//      <br/><b>terminator:</b>                   The symbol for the DatumTarget terminator.
//      <br/><b>radius:</b>                       The radius of the symbol.
//
// Enums          : JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
//                     JtkPMIDatumTargetType:
//                        TypeCYLINDRICAL --
//                        TypeLINE --
//                        TypeARBITRARY --
//                        TypeCIRCULAR --
//                        TypePOINT --
//                        TypeANNULAR --
//                        TypeAREA --
//                        TypeRECTANGULAR --
//                        TypeSPHERICAL --
//
//                     JtkPMIDimensionStubDirection:
//                        DimensionStubDirectionLEFT --
//                        DimensionStubDirectionRIGHT --
//                        DimensionStubDirectionINFERRED --
//
//                     JtkPMIDatumTargetAreaShape:
//                        AreaShapeDIAMETER --
//                        AreaShapeSPHERICALDIAMETER --
//                        AreaShapeSQUARE --
//
//                     JtkPMIDatumTerminator:
//                        DatumTerminatorNONE -- 
//                        DatumTerminatorX -- 
//                        DatumTerminatorPLUS --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIDatumTarget
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIDatumTarget : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIDatumTarget )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIDatumTarget( JtkUnitHierarchy* owner );
   virtual ~JtkPMIDatumTarget( );

public:
   int getPlanar( int& ) const;
   int setPlanar( int );
   int unsetPlanar( void );

   int getTextStubLength( double& ) const;
   int setTextStubLength( double );
   int unsetTextStubLength( void );

   int getLabel( JtkString& ) const;
   int setLabel( const JtkString& );
   int unsetLabel( void );

   int getTextStubDirection( JtkPMIDimensionStubDirection& ) const;
   int setTextStubDirection( JtkPMIDimensionStubDirection );
   int unsetTextStubDirection( void );

   int getPoint1( double&, double&, double& ) const;
   int setPoint1( double, double, double );
   int unsetPoint1( void );

   int getType( JtkPMIDatumTargetType& ) const;
   int setType( JtkPMIDatumTargetType );
   int unsetType( void );

   int getWidth( double& ) const;
   int setWidth( double );
   int unsetWidth( void );

   int getMovableTargetStubLength( double& ) const;
   int setMovableTargetStubLength( double );
   int unsetMovableTargetStubLength( void );

   int getMovable( int& ) const;
   int setMovable( int );
   int unsetMovable( void );

   int getPoint2( double&, double&, double& ) const;
   int setPoint2( double, double, double );
   int unsetPoint2( void );

   int getDiameter( double& ) const;
   int setDiameter( double );
   int unsetDiameter( void );

   int getMovableTargetStubDirection( JtkPMIDimensionStubDirection& ) const;
   int setMovableTargetStubDirection( JtkPMIDimensionStubDirection );
   int unsetMovableTargetStubDirection( void );

   int getInnerDiameter( double& ) const;
   int setInnerDiameter( double );
   int unsetInnerDiameter( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getLength( double& ) const;
   int setLength( double );
   int unsetLength( void );

   int getIndex( int& ) const;
   int setIndex( int );
   int unsetIndex( void );

   int getAreaShape( JtkPMIDatumTargetAreaShape& ) const;
   int setAreaShape( JtkPMIDatumTargetAreaShape );
   int unsetAreaShape( void );

   int getShapeTextOutsideSymbol( int& ) const;
   int setShapeTextOutsideSymbol( int );
   int unsetShapeTextOutsideSymbol( void );

   int getSize( JtkString& ) const;
   int setSize( const JtkString& );
   int unsetSize( void );

   int getMovableModifierAngle( double& ) const;
   int setMovableModifierAngle( double );
   int unsetMovableModifierAngle( );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getTerminator( JtkPMIDatumTerminator& ) const;
   int setTerminator( JtkPMIDatumTerminator );
   int unsetTerminator( );

   int getRadius( double& ) const;
   int setRadius( double );
   int unsetRadius( );
};
///////%{
//
// Class          : JtkPMISpotWeld
//
// Description    : JtkPMI class for Spot Welds. Each spot weld can have the following properties:
//      <br/><b>diameter:</b>               diameter
//      <br/><b>thickness:</b>              thickness of the weld bead
//      <br/><b>thicknesses:</b>            number of thicknesses of material being welded
//      <br/><b>type:</b>                   type of weld, resistance or projection
//      <br/><b>position:</b>               location of the spot weld
//      <br/><b>approachDirection:</b>      direction weld gun approaches weld
//      <br/><b>clampingDirection:</b>      direction in which material is clamped
//      <br/><b>normalDirection:</b>        normal vector at point of weld
//      <br/><b>jointId:</b>                user specified id for joint weld participates in
//      <br/><b>groupId:</b>                user specified id for group weld is in
//      <br/><b>delta:</b>                  flag indicating weld is "critical" (more important)
//      <br/><b>ProcessText:</b>            A single JtkPMIText representing the process text
//      <br/><b>CoordinatedEntity:</b>      Multiple JtkPMIText specifying a related entity in some undefined way
//      <br/><b>precision:</b>              The number of decimal places to display.
//      <br/><b>displayType:</b>            Whether to display text flat to the surface or the screen.
//
// Enums          :   JtkPMISpotWeldType:
//                        TypeUNSET --
//                        TypeRESISTANCE --
//                        TypePROJECTION --
//
//                     JtkPMIDisplayType:
//                        DisplayTypeFLATTOSURFACE -- display the text flat to the surface
//                        DisplayTypeFLATTOSCREEN -- display the text flat to the screen
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMISpotWeld
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMISpotWeld : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMISpotWeld )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMISpotWeld( JtkUnitHierarchy* owner );
   virtual ~JtkPMISpotWeld( );

public:

   int getType( JtkPMISpotWeldType& ) const;
   int setType( JtkPMISpotWeldType );
   int unsetType( void );

   int getJointId( JtkString& ) const;
   int setJointId( const JtkString& );
   int unsetJointId( void );

   int getApproachDirection( double&, double&, double& ) const;
   int setApproachDirection( double, double, double );
   int unsetApproachDirection( void );

   int getPosition( double&, double&, double& ) const;
   int setPosition( double, double, double );
   int unsetPosition( void );

   int getDiameter( double& ) const;
   int setDiameter( double );
   int unsetDiameter( void );

   int getThickness( double& ) const;
   int setThickness( double );
   int unsetThickness( void );

   int getGroupId( JtkString& ) const;
   int setGroupId( const JtkString& );
   int unsetGroupId( void );

   int getClampingDirection( double&, double&, double& ) const;
   int setClampingDirection( double, double, double );
   int unsetClampingDirection( void );

   int getNormalDirection( double&, double&, double& ) const;
   int setNormalDirection( double, double, double );
   int unsetNormalDirection( void );

   int getThicknesses( int& ) const;
   int setThicknesses( int );
   int unsetThicknesses( void );

   int getDelta( int& ) const;
   int setDelta( int );
   int unsetDelta( void );

   int addCoordinatedEntity( JtkPMIText*& );
   int getCoordinatedEntity( int index, JtkPMIText*& ) const;
   int numCoordinatedEntity( int& count ) const;
   int unsetCoordinatedEntity( int index );

   int addProcessText( JtkPMIText*& );
   int getProcessText( JtkPMIText*& ) const;
   int unsetProcessText( );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getDisplayType( JtkPMIDisplayType& ) const;
   int setDisplayType( JtkPMIDisplayType );
   int unsetDisplayType( void );

   int setPMIType( int nPmiType, const JtkString& sPmiTypeName );
};
///////%{
//
// Class          : JtkPMILineWeld
//
// Description    : JtkPMI class for Line Welds. Each line weld can have the following properties:
//      <br/><b>standard:</b>                                    ISO 2556 or ANSI/AWS A2.4-98
//      <br/><b>arrowSideSymbol:</b>                             symbol on arrow side of weld
//      <br/><b>otherSideSymbol:</b>                             symbol shown on other side of the weld
//      <br/><b>arrowSideMainSize:</b>                           main size of the weld on the arrow side
//      <br/><b>otherSideMainSize:</b>                           main size of the weld on the other side
//      <br/><b>arrowSideLongitudinalSize:</b>                   longitudinal size of the weld on the arrow side
//      <br/><b>otherSideLongitudinalSize:</b>                   longitudinal size of the weld on the other side
//      <br/><b>arrowSideStaggeredSize:</b>                      staggered size of the weld on the arrow side
//      <br/><b>otherSideStaggeredSize:</b>                      staggered size of the weld on the other side
//      <br/><b>arrowSideSupplementalSymbol:</b>                 supplemental symbol on arrow side
//      <br/><b>otherSideSupplementalSymbol:</b>                 supplemental symbol on other side
//      <br/><b>arrowSideSupplementalSymbol2:</b>                Second supplemental symbol on arrow side
//      <br/><b>otherSideSupplementalSymbol2:</b>                Second supplemental symbol on other side
//      <br/><b>allAround:</b>                                   flag indicating an all around weld
//      <br/><b>delta:</b>                                       flag indicating weld is "critical" (more important)
//      <br/><b>fieldWeld:</b>                                   indicates weld is applied in the field
//      <br/><b>referenceSign:</b>                               reference sign is to be included in symbol
//      <br/><b>arrowSideFinishSymbol:</b>                       Indicates the type of process used to apply a finish
//                                                               to the Arrow side of a Weld
//      <br/><b>otherSideFinishSymbol:</b>                       ditto, Other side
//      <br/><b>jisArrowSidePartialPenetrationGrooveWeld:</b>    Flag indicating the Arrow side of a weld
//                                                               represents a partial penetration groove weld
//      <br/><b>jisOtherSidePartialPenetrationGrooveWeld:</b>    ditto, Other side
//      <br/><b>jisStaggeredFilletWeld:</b>                      Flag indicating that the JIS fillet weld is to be staggered
//      <br/><b>arrowSideGrooveGap:</b>                          Gap applied to the Arrow side of a groove weld
//      <br/><b>otherSideGrooveGap:</b>                          ditto, Other side
//      <br/><b>arrowSideGrooveAngle:</b>                        Angle applied to the Arrow side of a groove weld
//      <br/><b>otherSideGrooveAngle:</b>                        ditto, Other side
//      <br/><b>staggeredWeld:</b>                               Whether the weld is staggered
//      <br/><b>arrowSideCompoundWeld:</b>                       Whether the arrow side of the weld is a compound weld.
//      <br/><b>otherSideCompoundWeld:</b>                       Whether the other side of the weld is a compound weld.
//      <br/><b>arrowSideCompoundMainSize:</b>                   The main size of the weld on the arrow side.
//      <br/><b>otherSideCompoundMainSize:</b>                   The main size of the weld on the other side.
//      <br/><b>arrowSideCompoundLongitudinalSize:</b>           Longitudinal size of the compound weld on the arrow side.
//      <br/><b>otherSideCompoundLongitudinalSize:</b>           Longitudinal size of the compound weld on the other side.
//      <br/><b>arrowSideCompoundStaggeredSize:</b>              Staggered size of the compound weld on the arrow side.
//      <br/><b>otherSideCompoundStaggeredSize:</b>              Staggered size of the compound weld on the other side.
//      <br/><b>contour:</b>                                     Contour symbol.
//      <br/><b>ProcessText:</b>                                 A JtkPMIText* representing the process text
//      <br/><b>CoordinatedEntity:</b>                           Multiple JtkPMIText's specifying a related entity in an undefined way
//      <br/><b>precision:</b>                                   The number of decimal places to display.
//      <br/><b>referenceSignType:</b>                           The type of any reference sign.
//      <br/><b>fieldWeldType:</b>                               The type of any field weld indicator.
//      <br/><b>arrowSideAboveLine:</b>                          Whether to show the arrow side information above the
//                                                               reference line. By default, the arrow side information
//                                                               is shown below the reference line. In order to comply
//                                                               with standards, if arrowSideAboveLine is true, a dashed
//                                                               identification line should also be shown below the solid
//                                                               reference line to indicate the other side.
//      <br/><b>identificationLine:</b>                          Whether to show a dashed identification line to
//                                                               indicate the other side.
//      <br/><b>identificationBelowReference:</b>                Whether to show the dashed identification
//                                                               line below the solid reference line. By default, the
//                                                               dashed identification line is shown above the solid
//                                                               reference line. In order to comply with standards, if
//                                                               identificationBelowReference is true, identificationLine
//                                                               should also be true.
//      <br/><b>fieldSpaceFactor:</b>                            The relative spacing of the fields of the weld
//                                                               information.
//      <br/><b>symmetric:</b>                                   Whether the weld is symmetrical by design.
//      <br/><b>lineGap:</b>                                     The gap between the reference line and the weld information.
//      <br/><b>solder:</b>                                      Flag indicating a soldered joint.
//      <br/><b>glue:</b>                                        Flag indicating a glued joint.
//      <br/><b>fieldWeldDirection:</b>                          The direction of any field weld indicator.
//      <br/><b>grooveGapTextStyle:</b>                          How any groove gap text relates to its symbol.
//      <br/><b>GrooveGapTextFormat:</b>                         Overriding format attributes for any groove gap text.
//      <br/><b>SurfaceFinish:</b>                               Incorporated SurfaceFinish.
//      <br/><b>LeaderText:</b>                                  Text elements on the Leader of an ESKD LineWeld. Only above and below are allowed.
//       
//
// Enums          : JtkPMILineWeldSymbol:
//                        LineWeldSymbolUNSET --
//                        LineWeldSymbolJISSEAM --
//                        LineWeldSymbolSINGLEBEVELGROOVE --
//                        LineWeldSymbolSINGLEUGROOVE --
//                        LineWeldSymbolEDGEFLANGE --
//                        LineWeldSymbolSURFACE --
//                        LineWeldSymbolSTEEPFLANKEDSINGLEBEVEL --
//                        LineWeldSymbolFLARESINGLEVGROOVE --
//                        LineWeldSymbolSURFACEJOINT --
//                        LineWeldSymbolSINGLEVGROOVE --
//                        LineWeldSymbolINCLINEDJOINT --
//                        LineWeldSymbolPLUG --
//                        LineWeldSymbolFILLET --
//                        LineWeldSymbolSQUAREGROOVE --
//                        LineWeldSymbolSPOT --
//                        LineWeldSymbolSINGLEJ --
//                        LineWeldSymbolSQUARE --
//                        LineWeldSymbolOVERLAY --
//                        LineWeldSymbolSINGLEU --
//                        LineWeldSymbolSINGLEJGROOVE --
//                        LineWeldSymbolDOUBLEFLANGE --
//                        LineWeldSymbolSINGLEFLANGE --
//                        LineWeldSymbolSPOTPROJECTED --
//                        LineWeldSymbolPLUGANDSLOT --
//                        LineWeldSymbolSINGLEBEVELBROADROOTFACE --
//                        LineWeldSymbolEDGE --
//                        LineWeldSymbolJISSTAGGEREDFILLET1 --
//                        LineWeldSymbolSINGLEV --
//                        LineWeldSymbolFLARESINGLEBEVELGROOVE --
//                        LineWeldSymbolSINGLEVBROADROOTFACE --
//                        LineWeldSymbolSTEEPFLANKEDSINGLEV --
//                        LineWeldSymbolREMOVABLEBACKINGSTRIP --
//                        LineWeldSymbolPERMANENTBACKINGSTRIP --
//                        LineWeldSymbolJISFILLET --
//                        LineWeldSymbolSINGLEBEVEL --
//                        LineWeldSymbolBACKING --
//                        LineWeldSymbolFOLDJOINT --
//                        LineWeldSymbolJISSTAGGEREDFILLET2 --
//                        LineWeldSymbolSEAM --
//                        LineWeldSymbolBEAD --
//                        LineWeldSymbolSTUD --
//                        LineWeldSymbolINTERMITTENT --
//                        LineWeldSymbolBACKINGPLATE --
//                        LineWeldSymbolMELTTHROUGH -- deprecated in favour of LineWeldSupplementalSymbolMELTTHROUGH
//                        LineWeldSymbolSOLDER --
//                        LineWeldSymbolKGROOVE --
//                        LineWeldSymbolSTAKE --
//                        LineWeldSymbolKEYHOLE --
//                        LineWeldSymbolJISPOT --
//                        LineWeldSymbolJISSPOTFLATELECTRODE --
//                        LineWeldSymbolESKDHEAT --
//                        LineWeldSymbolESKDSMOOTH --
//                        LineWeldSymbolESKDSTAGGERCHAIN --
//                        LineWeldSymbolESKDSTAGGERCHECK --
//                        LineWeldSymbolESKDNOTALLAROUND --
//                        LineWeldSymbolESKDDIAMETER --
//                        LineWeldSymbolESKDNUMBER --
//                        LineWeldSymbolISOEDGE --
//
//                     JtkPMILineWeldFinishSymbol:
//                        LineWeldFinishSymbolUNSET --
//                        LineWeldFinishSymbolUNSPECIFIED --
//                        LineWeldFinishSymbolMACHINING --
//                        LineWeldFinishSymbolGRINDING --
//                        LineWeldFinishSymbolCHIPPING --
//                        LineWeldFinishSymbolNONE --
//                        LineWeldFinishSymbolHAMMERING --
//                        LineWeldFinishSymbolPEENING --
//                        LineWeldFinishSymbolROLLING --
//                        LineWeldFinishSymbolFINISHING --
//
//                     JtkPMILineWeldSupplementalSymbol:
//                        LineWeldSupplementalSymbolUNSET --
//                        LineWeldSupplementalSymbolCONVEX --
//                        LineWeldSupplementalSymbolTOESBLENDED --
//                        LineWeldSupplementalSymbolCONCAVE --
//                        LineWeldSupplementalSymbolFLUSH --
//                        LineWeldSupplementalSymbolPERMANENTBACKINGSTRIP --
//                        LineWeldSupplementalSymbolREMOVABLEBACKINGSTRIP --
//                        LineWeldSupplementalSymbolSTUD --
//                        LineWeldSupplementalSymbolINTERMITTENT --
//                        LineWeldSupplementalSymbolBACKING --
//                        LineWeldSupplementalSymbolBACKINGREMOVEAFTERWELD --
//                        LineWeldSupplementalSymbolSPACER --
//                        LineWeldSupplementalSymbolCONSUMABLEINSERT --
//                        LineWeldSupplementalSymbolFLUSHESKD --
//                        LineWeldSupplementalSymbolMACHININGGRADEDJUNCTION --
//                        LineWeldSupplementalSymbolSURFACEFINISHBASIC --
//                        LineWeldSupplementalSymbolSURFACEFINISHBASICCOMPLETE --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRR --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRRCOMPLETE --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRP --
//                        LineWeldSupplementalSymbolSURFACEFINISHMRPCOMPLETE --
//                        LineWeldSupplementalSymbolMELTTHROUGH --
//
//                     JtkPMILineWeldStandard:
//                        LineWeldStandardANSIAWS_A24MINUS98 --
//                        LineWeldStandardISO_2556 --
//                        LineWeldStandardJIS_Z_3021 --
//                        LineWeldStandardDIN --
//                        LineWeldStandardESKD --
//                        LineWeldStandardBG --
//
//                     JtkPMILineWeldReferenceSign:
//                        LineWeldReferenceSignFORK --
//                        LineWeldREferenceSignBOX -- 
//
//                     JtkPMILineWeldFieldWeld:
//                        LineWeldFieldWeldCOMMON --
//                        LineWeldFieldWeldESKD --
//
//                     JtkPMILineWeldContour:
//                        LineWeldContourCLOSED --
//                        LineWeldContourOPEN --
//                        LineWeldContourTRILATERAL --
//                        LineWeldContourALLAROUND --
//
//                     JtkPMIFieldWeldDirection:
//                        FieldWeldDirectionUP -- Any field weld indicator points up
//                        FieldWeldDirectionDOWN -- Any field weld indicator points down
//
//                     JtkPMIGrooveGapTextStyle:
//                        GrooveGapTextStyleINSIDE -- Any groove gap text lines inside the symbol
//                        GrooveGapTextStyleOUTSIDE -- Any groove gap text lines outside the symbol
//                        GrooveGapTextStyleARROW -- Any groove gap text is atached to the symbol with an arrow.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMILineWeld
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMILineWeld : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMILineWeld )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMILineWeld( JtkUnitHierarchy* owner );
   virtual ~JtkPMILineWeld( );

public:
   int getOtherSideLongitudinalSize( JtkString& ) const;
   int setOtherSideLongitudinalSize( const JtkString& );
   int unsetOtherSideLongitudinalSize( void );

   int getArrowSideSymbol( JtkPMILineWeldSymbol& ) const;
   int setArrowSideSymbol( JtkPMILineWeldSymbol );
   int unsetArrowSideSymbol( void );

   int getOtherSideStaggeredSize( JtkString& ) const;
   int setOtherSideStaggeredSize( const JtkString& );
   int unsetOtherSideStaggeredSize( void );

   int getArrowSideMainSize( JtkString& ) const;
   int setArrowSideMainSize( const JtkString& );
   int unsetArrowSideMainSize( void );

   int getOtherSideMainSize( JtkString& ) const;
   int setOtherSideMainSize( const JtkString& );
   int unsetOtherSideMainSize( void );

   int getOtherSideGrooveGap( JtkString& ) const;
   int setOtherSideGrooveGap( const JtkString& );
   int unsetOtherSideGrooveGap( void );

   int getArrowSideFinishSymbol( JtkPMILineWeldFinishSymbol& ) const;
   int setArrowSideFinishSymbol( JtkPMILineWeldFinishSymbol );
   int unsetArrowSideFinishSymbol( void );

   int getFieldWeld( int& ) const;
   int setFieldWeld( int );
   int unsetFieldWeld( void );

   int getOtherSideSupplementalSymbol( JtkPMILineWeldSupplementalSymbol& ) const;
   int setOtherSideSupplementalSymbol( JtkPMILineWeldSupplementalSymbol );
   int unsetOtherSideSupplementalSymbol( void );

   int getOtherSideGrooveAngle( JtkString& ) const;
   int setOtherSideGrooveAngle( const JtkString& );
   int unsetOtherSideGrooveAngle( void );

   int getArrowSideLongitudinalSize( JtkString& ) const;
   int setArrowSideLongitudinalSize( const JtkString& );
   int unsetArrowSideLongitudinalSize( void );

   int getJisStaggeredFilletWeld( int& ) const;
   int setJisStaggeredFilletWeld( int );
   int unsetJisStaggeredFilletWeld( void );

   int getArrowSideStaggeredSize( JtkString& ) const;
   int setArrowSideStaggeredSize( const JtkString& );
   int unsetArrowSideStaggeredSize( void );

   int getStandard( JtkPMILineWeldStandard& ) const;
   int setStandard( JtkPMILineWeldStandard );
   int unsetStandard( void );

   int getJisArrowSidePartialPenetrationGrooveWeld( int& ) const;
   int setJisArrowSidePartialPenetrationGrooveWeld( int );
   int unsetJisArrowSidePartialPenetrationGrooveWeld( void );

   int getArrowSideGrooveAngle( JtkString& ) const;
   int setArrowSideGrooveAngle( const JtkString& );
   int unsetArrowSideGrooveAngle( void );

   int getArrowSideSupplementalSymbol( JtkPMILineWeldSupplementalSymbol& ) const;
   int setArrowSideSupplementalSymbol( JtkPMILineWeldSupplementalSymbol );
   int unsetArrowSideSupplementalSymbol( void );

   int getArrowSideGrooveGap( JtkString& ) const;
   int setArrowSideGrooveGap( const JtkString& );
   int unsetArrowSideGrooveGap( void );

   int getDelta( int& ) const;
   int setDelta( int );
   int unsetDelta( void );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( void );

   int getReferenceSign( int& ) const;
   int setReferenceSign( int );
   int unsetReferenceSign( void );

   int getJisOtherSidePartialPenetrationGrooveWeld( int& ) const;
   int setJisOtherSidePartialPenetrationGrooveWeld( int );
   int unsetJisOtherSidePartialPenetrationGrooveWeld( void );

   int getOtherSideFinishSymbol( JtkPMILineWeldFinishSymbol& ) const;
   int setOtherSideFinishSymbol( JtkPMILineWeldFinishSymbol );
   int unsetOtherSideFinishSymbol( void );

   int getOtherSideSymbol( JtkPMILineWeldSymbol& ) const;
   int setOtherSideSymbol( JtkPMILineWeldSymbol );
   int unsetOtherSideSymbol( void );

   int getStaggeredWeld( int& ) const;
   int setStaggeredWeld( int );
   int unsetStaggeredWeld( );

   int getArrowSideCompoundWeld( int& ) const;
   int setArrowSideCompoundWeld( int );
   int unsetArrowSideCompoundWeld( );

   int getOtherSideCompoundWeld( int& ) const;
   int setOtherSideCompoundWeld( int );
   int unsetOtherSideCompoundWeld( );

   int getArrowSideCompoundMainSize( JtkString& ) const;
   int setArrowSideCompoundMainSize( const JtkString& );
   int unsetArrowSideCompoundMainSize( );

   int getOtherSideCompoundMainSize( JtkString& ) const;
   int setOtherSideCompoundMainSize( const JtkString& );
   int unsetOtherSideCompoundMainSize( );

   int getContour( JtkPMILineWeldContour& symbol ) const;
   int setContour( JtkPMILineWeldContour symbol );
   int unsetContour( );

   int addProcessText( JtkPMIText*& );
   int getProcessText( JtkPMIText*& ) const;
   int unsetProcessText( );

   int addCoordinatedEntity( JtkPMIText*& );
   int getCoordinatedEntity( int index, JtkPMIText*& ) const;
   int numCoordinatedEntity( int& count ) const;
   int unsetCoordinatedEntity( int index );

   int getArrowSideSupplementalSymbol2( JtkPMILineWeldSupplementalSymbol& ) const;
   int setArrowSideSupplementalSymbol2( JtkPMILineWeldSupplementalSymbol );
   int unsetArrowSideSupplementalSymbol2( void );

   int getOtherSideSupplementalSymbol2( JtkPMILineWeldSupplementalSymbol& ) const;
   int setOtherSideSupplementalSymbol2( JtkPMILineWeldSupplementalSymbol );
   int unsetOtherSideSupplementalSymbol2( void );

   int getArrowSideCompoundLongitudinalSize( JtkString& ) const;
   int setArrowSideCompoundLongitudinalSize( const JtkString& );
   int unsetArrowSideCompoundLongitudinalSize( void );

   int getOtherSideCompoundLongitudinalSize( JtkString& ) const;
   int setOtherSideCompoundLongitudinalSize( const JtkString& );
   int unsetOtherSideCompoundLongitudinalSize( void );

   int getArrowSideCompoundStaggeredSize( JtkString& ) const;
   int setArrowSideCompoundStaggeredSize( const JtkString& );
   int unsetArrowSideCompoundStaggeredSize( void );

   int getOtherSideCompoundStaggeredSize( JtkString& ) const;
   int setOtherSideCompoundStaggeredSize( const JtkString& );
   int unsetOtherSideCompoundStaggeredSize( void );

   int getLeaderText( int, JtkPMIDimensionText*& ) const;
   int addLeaderText( JtkPMIDimensionText*& );
   int numLeaderText( int& ) const;
   int unsetLeaderText( int );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getReferenceSignType( JtkPMILineWeldReferenceSign& ) const;
   int setReferenceSignType( JtkPMILineWeldReferenceSign );
   int unsetReferenceSignType( void );

   int getFieldWeldType( JtkPMILineWeldFieldWeld& ) const;
   int setFieldWeldType( JtkPMILineWeldFieldWeld );
   int unsetFieldWeldType( void );

   int getArrowSideAboveLine( int& ) const;
   int setArrowSideAboveLine( int );
   int unsetArrowSideAboveLine( void );

   int getIdentificationLine( int& ) const;
   int setIdentificationLine( int );
   int unsetIdentificationLine( void );

   int getIdentificationBelowReference( int& ) const;
   int setIdentificationBelowReference( int );
   int unsetIdentificationBelowReference( void );

   int getFieldSpaceFactor( double& ) const;
   int setFieldSpaceFactor( double );
   int unsetFieldSpaceFactor( void );

   int getSymmetric( int& ) const;
   int setSymmetric( int );
   int unsetSymmetric( );

   int getLineGap( double& ) const;
   int setLineGap( double );
   int unsetLineGap( void );

   int getSolder( int& ) const;
   int setSolder( int );
   int unsetSolder( );

   int getGlue( int& ) const;
   int setGlue( int );
   int unsetGlue( );

   int getSurfaceFinish( JtkPMISurfaceFinish*& ) const;
   int addSurfaceFinish( JtkPMISurfaceFinish*& );
   int unsetSurfaceFinish( );

   int getFieldWeldDirection( JtkPMIFieldWeldDirection& ) const;
   int setFieldWeldDirection( JtkPMIFieldWeldDirection );
   int unsetFieldWeldDirection( );

   int getGrooveGapTextStyle( JtkPMIGrooveGapTextStyle& ) const;
   int setGrooveGapTextStyle( JtkPMIGrooveGapTextStyle );
   int unsetGrooveGapTextStyle( );

   int getGrooveGapTextFormat( JtkPMITextFormat*& ) const;
   int addGrooveGapTextFormat( JtkPMITextFormat*& );
   int unsetGrooveGapTextFormat( );

   int setPMIType( int nPmiType, const JtkString& sPmiTypeName );
};
///////%{
//
// Class          : JtkPMIMaterialSpec
//
// Description    : JtkPMI class for Material Specifications. It can have the following properties
//      <br/><b>identifier:</b>            unique identifier for the specification
//      <br/><b>revision:</b>            revision of the specification
//      <br/><b>Nomenclature:</b>         information about the material
//      <br/><b>OpenField:</b>            Additional information
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIMaterialSpec
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIMaterialSpec : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIMaterialSpec )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIMaterialSpec( JtkUnitHierarchy* owner );
   virtual ~JtkPMIMaterialSpec( );

public:
   int addNomenclature( JtkPMIText*& );
   int getNomenclature( JtkPMIText*& ) const;
   int unsetNomenclature( );

   int addOpenField( JtkPMIText*& );
   int getOpenField( JtkPMIText*& ) const;
   int unsetOpenField( );

   int getIdentifier( JtkString& ) const;
   int setIdentifier( const JtkString& );
   int unsetIdentifier( void );

   int getRevision( JtkString& ) const;
   int setRevision( const JtkString& );
   int unsetRevision( void );

};
///////%{
//
// Class          : JtkPMIProcessSpec
//
// Description    : JtkPMI class for Process Specifications. It can have the following properties
//      <br/><b>identifier:</b>            unique identifier for the specification
//      <br/><b>revision:</b>            revision of the specification
//      <br/><b>Nomenclature:</b>         information about the process
//      <br/><b>OpenField:</b>            Additional information
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIProcessSpec
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIProcessSpec : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIProcessSpec )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIProcessSpec( JtkUnitHierarchy* owner );
   virtual ~JtkPMIProcessSpec( );

public:
   int addNomenclature( JtkPMIText*& );
   int getNomenclature( JtkPMIText*& ) const;
   int unsetNomenclature( );

   int addOpenField( JtkPMIText*& );
   int getOpenField( JtkPMIText*& ) const;
   int unsetOpenField( );

   int getIdentifier( JtkString& ) const;
   int setIdentifier( const JtkString& );
   int unsetIdentifier( void );

   int getRevision( JtkString& ) const;
   int setRevision( const JtkString& );
   int unsetRevision( void );

};
///////%{
//
// Class          : JtkPMIPartSpec
//
// Description    : JtkPMI class for Part Specs. It can have the following properties
//      <br/><b>itemName:</b>
//      <br/><b>nameModifier:</b>
//      <br/><b>descriptiveModifier:</b>
//      <br/><b>identifier:</b>            unique identifier for the specification
//      <br/><b>revision:</b>              revision of the specification
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIPartSpec
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIPartSpec : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIPartSpec )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIPartSpec( JtkUnitHierarchy* owner );
   virtual ~JtkPMIPartSpec( );

public:
   int getDescriptiveModifier( JtkString& ) const;
   int setDescriptiveModifier( const JtkString& );
   int unsetDescriptiveModifier( void );

   int getNameModifier( JtkString& ) const;
   int setNameModifier( const JtkString& );
   int unsetNameModifier( void );

   int getItemName( JtkString& ) const;
   int setItemName( const JtkString& );
   int unsetItemName( void );

   int getIdentifier( JtkString& ) const;
   int setIdentifier( const JtkString& );
   int unsetIdentifier( void );

   int getRevision( JtkString& ) const;
   int setRevision( const JtkString& );
   int unsetRevision( void );

};

///////%{
//
// Class          : JtkPMIOrganisation
//
// Description    : JtkPMI class for Organisations.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIOrganisation
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIOrganisation : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIOrganisation )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIOrganisation( JtkUnitHierarchy* owner );
   virtual ~JtkPMIOrganisation( );

   //no additional methods
};

///////%{
//
// Class          : JtkPMINote
//
// Description    : JtkPMI class for Notes. A note can have the following properties
//      <br/><b>standard:</b>         standard applicable to the Note
//      <br/><b>identifier:</b>       identifier of the Note
//      <br/><b>category:</b>         category of the Note
//      <br/><b>revision:</b>         revision of the Note
//      <br/><b>Text:</b>             Zero or more blocks of text.
//      <br/><b>AltText:</b>          Zero or more blocks of alternate text.
//      <br/><b>NoteText:</b>         Zero or more blocks of positioned and orientated text.
//      <br/><b>displayType:</b>      Whether to display the PMI Text flat to the screen or the surface.
//      <br/><b>datumOnLeader:</b>    Whether the Leader has an intermediate datum symbol
//                                    rather than going directly to the target geometry and,
//                                    if it has, whether the symbol is solid or filled.
//      <br/><b>allAround:</b>        Whether the All Around symbol is added. 
//
//    Each <b>NoteText</b> can have the following:
//      <br/><b>origin:</b>            position of start of text, in the display plane
//      <br/><b>direction:</b>         direction of text
//      <br/><b>Text:</b>              a single JtkPMIText
//
// Enums          : JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
//                  JtkPMIDisplayType:
//                        DisplayTypeFLATTOSURFACE -- display the text flat to the surface
//                        DisplayTypeFLATTOSCREEN -- display the text flat to the screen
//
//                  JtkPMIDatumOnLeader:
//                        DatumOnLeaderNONE --
//                        DatumOnLeaderSOLID --
//                        DatumOnLeaderFILLED --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMINote
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMINote : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMINote )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMINote( JtkUnitHierarchy* owner );
   virtual ~JtkPMINote( );

public:
   int getCategory( JtkString& ) const;
   int setCategory( const JtkString& );
   int unsetCategory( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getIdentifier( JtkString& ) const;
   int setIdentifier( const JtkString& );
   int unsetIdentifier( void );

   int getRevision( JtkString& ) const;
   int setRevision( const JtkString& );
   int unsetRevision( void );

   int addText( JtkPMIText*& );
   int getText( int index, JtkPMIText*& ) const;
   int numText( int& count ) const;
   int unsetText( int index );

   int addAltText( JtkPMIText*& );
   int getAltText( int index, JtkPMIText*& ) const;
   int numAltText( int& count ) const;
   int unsetAltText( int index );

   int addNoteText( );
   int numNoteText( int& number ) const;
   int unsetNoteText( int index );

   int addNoteTextText( int index, JtkPMIText*& text );
   int getNoteTextText( int index, JtkPMIText*& text ) const;
   int unsetNoteTextText( int index );

   int setNoteTextOrigin( int index, double d1, double d2, double d3 );
   int getNoteTextOrigin( int index, double& d1, double& d2, double& d3 ) const;
   int unsetNoteTextOrigin( int index );

   int setNoteTextDirection( int index, double d1, double d2, double d3 );
   int getNoteTextDirection( int index, double& d1, double& d2, double& d3 ) const;
   int unsetNoteTextDirection( int index );

   int getDisplayType( JtkPMIDisplayType& ) const;
   int setDisplayType( JtkPMIDisplayType );
   int unsetDisplayType( void );

   int getDatumOnLeader( JtkPMIDatumOnLeader& ) const;
   int setDatumOnLeader( JtkPMIDatumOnLeader );
   int unsetDatumOnLeader( void );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( );

   int setPMIType( int nPmiType, const JtkString& sPmiTypeName );
};
///////%{
//
// Class          : JtkPMIBalloon
//
// Description    : JtkPMI class Balloon Note PMI. In addition to those inherited from Note a Balloon can have the following Properties
//      <br/><b>balloonId:</b>      String giving the letter(s) displayed inside the Balloon circle.
//      <br/><b>radius:</b>         The radius of the balloon circle
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMINote > JtkPMIBalloon
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIBalloon : public JtkPMINote
{
   JTK_OBJECT_HEADER( JtkPMIBalloon )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIBalloon( JtkUnitHierarchy* owner );
   virtual ~JtkPMIBalloon( );

public:
   int getBalloonId( JtkString& ) const;
   int setBalloonId( const JtkString& );
   int unsetBalloonId( void );

   int getRadius( double& ) const;
   int setRadius( double );
   int unsetRadius( void );
};
///////%{
//
// Class          : JtkPMIMeasurementPoint
//
// Description    : JtkPMI class for MeasurementPoints. A measurement point can have the following properties:
//      <br/><b>level:</b>                  level of measurement point use in process
//      <br/><b>measurementDirection:</b>   direction CMM approaches measurement point
//      <br/><b>coordinationDirection:</b>   direction for coordinating with another part
//      <br/><b>normalDirection:</b>         normal vector at point of measurement point
//      <br/><b>position:</b>               location of the measurement point. This is a required field.
//      <br/><b>CoordinatedEntity:</b>      text string specifying a related entity in an undefined way
//      <br/><b>displayType:</b>            Whether to display the PMI Text flat to the screen or the surface.
//
// Enums          : JtkPMIDisplayType:
//                        DisplayTypeFLATTOSURFACE -- display the text flat to the surface
//                        DisplayTypeFLATTOSCREEN -- display the text flat to the screen
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIMeasurementPoint
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIMeasurementPoint : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIMeasurementPoint )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIMeasurementPoint( JtkUnitHierarchy* owner );
   virtual ~JtkPMIMeasurementPoint( );

public:
   int getMeasurementDirection( double&, double&, double& ) const;
   int setMeasurementDirection( double, double, double );
   int unsetMeasurementDirection( void );

   int getCoordinationDirection( double&, double&, double& ) const;
   int setCoordinationDirection( double, double, double );
   int unsetCoordinationDirection( void );

   int getNormalDirection( double&, double&, double& ) const;
   int setNormalDirection( double, double, double );
   int unsetNormalDirection( void );

   int getPosition( double&, double&, double& ) const;
   int setPosition( double, double, double );
   int unsetPosition( void );

   int getLevel( JtkString& ) const;
   int setLevel( const JtkString& );
   int unsetLevel( void );

   int addCoordinatedEntity( JtkPMIText*& );
   int getCoordinatedEntity( int index, JtkPMIText*& ) const;
   int numCoordinatedEntity( int& count ) const;
   int unsetCoordinatedEntity( int index );

   int getDisplayType( JtkPMIDisplayType& ) const;
   int setDisplayType( JtkPMIDisplayType );
   int unsetDisplayType( void );

   int setPMIType( int nPmiType, const JtkString& sPmiTypeName );
};
///////%{
//
// Class          : JtkPMILocator
//
// Description    : JtkPMI class for Locators. A locator can have the following properties:
//      <br/><b>symbol:</b>                  Main type of the Locator Symbol. e.g. hole, edge, surface, etc.
//      <br/><b>subtype:</b>                  Indicates the subtype of the Locator
//      <br/><b>coordinatePlane:</b>         Indicates the coordinate plane for which the Locator limits
//                                          the degrees of freedom of the Part
//      <br/><b>functionalSubscript:</b>      Indicates which functional subscripts are applicable.
//                                          These are (may include more than one):
//                                          O - Dies, moulds, checking fixtures for individual parts
//                                          S - Sub-assembly prior to framing
//                                          K - Sub-assembly locators in checking fixtures
//                                          C - Assembly fixtures for framing prior to paint
//                                          F - Trim and final assembly after paint
//      <br/><b>changeLevel:</b>            Indicates how easy it is (for the overall process) to allow
//                                          change to this Locator.
//      <br/><b>punchDirection[3]:</b>      punch direction - direction in which punch approaches part
//      <br/><b>pinDirection[3]:</b>         pin direction - direction in which part is pinned
//      <br/><b>normalDirection[3]:</b>      normal direction - normal vector at this locator
//      <br/><b>hotSpotPosition:</b>         position of the Hot Spot for the Locator in global space
//      <br/><b>PartNumber:</b>               a user entered string indicating the part number
//      <br/><b>Note:</b>                     a user entered string, free text
//      <br/><b>CoordinatedEntity:</b>      a text string specifying a related entity in an undefined way
//      <br/><b>precision:</b>               number of decimal places
//
//      One of the following is required, depending on the value of symbol
//         <br/><b>mainEdgeType:</b>                  If symbol is edge, indicates the type of the Edge Locator
//         <br/><b>mainHoleType:</b>                  If symbol is hole, indicates the type of the Hole Locator
//         <br/><b>mainSurfaceType:</b>               If symbol is surface, indicates the type of the Surface Locator
//         <br/><b>mainRectSlotFreeformType:</b>      If symbol is rectangular, slot or freeform
//                                                   indicates the type of the Rectangular, Slot or FreeformLocator
//
// Enums          : JtkPMILocatorCoordinatePlane:
//                        CoordinatePlaneY --
//                        CoordinatePlaneXZ --
//                        CoordinatePlaneXY --
//                        CoordinatePlaneYZ --
//                        CoordinatePlaneZ --
//                        CoordinatePlaneXYZ --
//                        CoordinatePlaneX --
//
//                     JtkPMILocatorMainRectSlotFreeformType:
//                        MainRectSlotFreeformTypeDL --
//                        MainRectSlotFreeformTypeH --
//                        MainRectSlotFreeformTypehk --
//                        MainRectSlotFreeformTypeBL --
//                        MainRectSlotFreeformTypeHK --
//                        MainRectSlotFreeformTypeAC --
//                        MainRectSlotFreeformTypeh --
//                        MainRectSlotFreeformTypeCH --
//
//                     JtkPMILocatorMainSurfaceType:
//                        MainSurfaceTypeSK --
//                        MainSurfaceTypeCO --
//                        MainSurfaceTypeJ --
//                        MainSurfaceTypes --
//                        MainSurfaceTypeSL --
//                        MainSurfaceTypesk --
//                        MainSurfaceTypeCS --
//                        MainSurfaceTypeS --
//                        MainSurfaceTypeCK --
//
//                     JtkPMILocatorMainEdgeType:
//                        MainEdgeTypeCE --
//                        MainEdgeTypee --
//                        MainEdgeTypeE --
//                        MainEdgeTypeEK --
//                        MainEdgeTypeCO --
//
//                     JtkPMILocatorChangeLevel:
//                        ChangeLevelSOFT --
//                        ChangeLevelMEDIUM --
//                        ChangeLevelHARD --
//
//                     JtkPMILocatorSubtype:
//                        SubtypeMECHANICALLYFASTENED --
//                        SubtypeMANUFACTURINGANDASSEMBLY --
//                        SubtypeDIESMOLDS --
//                        SubtypeFIXING --
//                        SubtypeTEMPORARYTRANSFERRED --
//                        SubtypePERMANENTLYTRANSFERRED --
//                        SubtypeCOORDINATION --
//                        SubtypeCORRECTABLE -- 
//                        SubtypeAUXILIARYREST --
//                        SubtypeSCRIBEDCOORDINATIONLINE --
//                        SubtypeACCESSCLEARANCEHOLE --
//                        SubtypeDETACHED -- 
//                        SubtypeBLANK --
//                        SubtypeJCLAMPS --
//
//                     JtkPMILocatorMainHoleType:
//                        MainHoleTypeDL --
//                        MainHoleTypeH --
//                        MainHoleTypehk --
//                        MainHoleTypech --
//                        MainHoleTypeHK --
//                        MainHoleTypeAC --
//                        MainHoleTypeh --
//                        MainHoleTypeBL --
//                        MainHoleTypeCH --
//
//                     JtkPMILocatorSymbol:
//                        SymbolRECTANGLE --
//                        SymbolEDGE --
//                        SymbolHOLE --
//                        SymbolFREEFORM --
//                        SymbolSLOT --
//                        SymbolSURFACE --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMILocator
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMILocator : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMILocator )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMILocator( JtkUnitHierarchy* owner );
   virtual ~JtkPMILocator( );

public:
   int getHotSpotPosition( double&, double&, double& ) const;
   int setHotSpotPosition( double, double, double );
   int unsetHotSpotPosition( void );

   int getCoordinatePlane( JtkPMILocatorCoordinatePlane& ) const;
   int setCoordinatePlane( JtkPMILocatorCoordinatePlane );
   int unsetCoordinatePlane( void );

   int getMainRectSlotFreeformType( JtkPMILocatorMainRectSlotFreeformType& ) const;
   int setMainRectSlotFreeformType( JtkPMILocatorMainRectSlotFreeformType );
   int unsetMainRectSlotFreeformType( void );

   int getMainSurfaceType( JtkPMILocatorMainSurfaceType& ) const;
   int setMainSurfaceType( JtkPMILocatorMainSurfaceType );
   int unsetMainSurfaceType( void );

   int getPinDirection( double&, double&, double& ) const;
   int setPinDirection( double, double, double );
   int unsetPinDirection( void );

   int getMainEdgeType( JtkPMILocatorMainEdgeType& ) const;
   int setMainEdgeType( JtkPMILocatorMainEdgeType );
   int unsetMainEdgeType( void );

   int getChangeLevel( JtkPMILocatorChangeLevel& ) const;
   int setChangeLevel( JtkPMILocatorChangeLevel );
   int unsetChangeLevel( void );

   int getSubType( JtkPMILocatorSubtype& ) const;
   int setSubType( JtkPMILocatorSubtype );
   int unsetSubType( void );

   int getMainHoleType( JtkPMILocatorMainHoleType& ) const;
   int setMainHoleType( JtkPMILocatorMainHoleType );
   int unsetMainHoleType( void );

   int getFunctionalSubscript( JtkString& ) const;
   int setFunctionalSubscript( const JtkString& );
   int unsetFunctionalSubscript( void );

   int getPunchDirection( double&, double&, double& ) const;
   int setPunchDirection( double, double, double );
   int unsetPunchDirection( void );

   int getSymbol( JtkPMILocatorSymbol& ) const;
   int setSymbol( JtkPMILocatorSymbol );
   int unsetSymbol( void );

   int getNormalDirection( double&, double&, double& ) const;
   int setNormalDirection( double, double, double );
   int unsetNormalDirection( void );

   int addPartNumber( JtkPMIText*& );
   int getPartNumber( JtkPMIText*& ) const;
   int unsetPartNumber( );

   int addNote( JtkPMIText*& );
   int getNote( JtkPMIText*& ) const;
   int unsetNote( );

   int addCoordinatedEntity( JtkPMIText*& );
   int getCoordinatedEntity( int index, JtkPMIText*& ) const;
   int numCoordinatedEntity( int& count ) const;
   int unsetCoordinatedEntity( int index );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int setPMIType( int nPmiType, const JtkString& sPmiTypeName );
};

///////%{
//
// Class          : JtkPMIUserDefinedSymbol
//
// Description    : JtkPMI class for User Defined Symbols. A user defined symbol can have the following properties:
//      <br/><b>lineStyle:</b>                  The style applied to the lines in the User Defined Symbol
//      <br/><b>scale:</b>                     Scale factor applied to the symbol
//      <br/><b>filename:</b>                  name of the file used to define the symbol
//      <br/><b>UserDefinedSymbolText:</b>      Positioned and oriented Text blocks
//
//      Each <b>UserDefinedSymbolText:</b> can have the following:
//         <br/><b>origin:</b>         position of start of text, in the display plane
//         <br/><b>direction:</b>      direction of text
//         <br/><b>Text:</b>            a single JtkPMIText
//
//      The Line, Arc,Circle, Ellipse and Spline properties from the PLM XML Schema are not represented here as it is expected they would be part of the visual data.
//
//      The PMIType and Parent PMI Types can also be set for this class. 
//      Note: Changing the values of these types can affect how the PMI will be exported and subsequently re-imported. 
//      For example if the PMIType were changed to match the type of an existing JtkPMIEntity derived class then on 
//      re-import an instance of that class would be created rather than a JtkPMIUserDefinedSymbol.
//
// Enums          : JtkPMILineStyle:
//                        LineStyleUNSET --
//                        LineStyleLONGDASHED --
//                        LineStyleDOTTED --
//                        LineStyleDOTTEDDASHED --
//                        LineStylePHANTOM --
//                        LineStyleDASHED --
//                        LineStyleSOLID --
//                        LineStyleCENTRELINE --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIUserDefinedSymbol
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIUserDefinedSymbol : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIUserDefinedSymbol )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIUserDefinedSymbol( JtkUnitHierarchy* owner );
   virtual ~JtkPMIUserDefinedSymbol( );

public:
   int getScale( double& ) const;
   int setScale( double );
   int unsetScale( void );

   int getFilename( JtkString& ) const;
   int setFilename( const JtkString& );
   int unsetFilename( void );

   int getLineStyle( JtkPMILineStyle& ) const;
   int setLineStyle( JtkPMILineStyle );
   int unsetLineStyle( void );

   int addUserDefinedSymbolText( );
   int numUserDefinedSymbolText( int& number ) const;
   int unsetUserDefinedSymbolText( int index );

   int addUserDefinedSymbolTextText( int index, JtkPMIText*& text );
   int getUserDefinedSymbolTextText( int index, JtkPMIText*& text );
   int unsetUserDefinedSymbolTextText( int index );

   int setUserDefinedSymbolTextOrigin( int index, double d1, double d2, double d3 );
   int getUserDefinedSymbolTextOrigin( int index, double& d1, double& d2, double& d3 ) const;
   int unsetUserDefinedSymbolTextOrigin( int index );

   int setUserDefinedSymbolTextDirection( int index, double d1, double d2, double d3 );
   int getUserDefinedSymbolTextDirection( int index, double& d1, double& d2, double& d3 ) const;
   int unsetUserDefinedSymbolTextDirection( int index );

   int setPMIType( int pmiType, const JtkString& pmiTypeName );
   int setParentPMIType( int parentPMIType, const JtkString& parentPMITypeName );
};
///////%{
//
// Class          : JtkPMICircleCentre
//
// Description    : JtkPMI class for a CircleCentre. A CircleCentre can have the following attributes.
//      <br/><b>diameter:</b>            specifies the diameter of the circle if not derived from the tracked geometry
//      <br/><b>diameterOverride:</b>      indicates whether the diameter of any tracked geometry is overridden by the value specified in diameter.
//      <br/><b>axisDirection[3]:</b>      axis direction of hole etc.
//      <br/><b>normalDirection[3]:</b>   normal direction
//      <br/><b>position:</b>            position of the Circle Centre in model space
//      <br/><b>CoordinatedEntity:</b>   a text string specifying a related entity in some unspecified way
//      <br/><b>precision:</b>            number of decimal places used in the display
//      <br/><b>displayType:</b>         flatToScreen or flatToSurface
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMICircleCentre
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICircleCentre : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMICircleCentre )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICircleCentre( JtkUnitHierarchy* owner );
   virtual ~JtkPMICircleCentre( );

public:

   int getDiameter( double& ) const;
   int setDiameter( double );
   int unsetDiameter( void );

   int getNormalDirection( double&, double&, double& ) const;
   int setNormalDirection( double, double, double );
   int unsetNormalDirection( void );

   int getDiameterOverride( int& ) const;
   int setDiameterOverride( int );
   int unsetDiameterOverride( void );

   int getPosition( double&, double&, double& ) const;
   int setPosition( double, double, double );
   int unsetPosition( void );

   int getAxisDirection( double&, double&, double& ) const;
   int setAxisDirection( double, double, double );
   int unsetAxisDirection( void );

   int addCoordinatedEntity( JtkPMIText*& );
   int getCoordinatedEntity( int index, JtkPMIText*& ) const;
   int numCoordinatedEntity( int& count ) const;
   int unsetCoordinatedEntity( int index );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getDisplayType( JtkPMIDisplayType& ) const;
   int setDisplayType( JtkPMIDisplayType );
   int unsetDisplayType( void );
};
///////%{
//
// Class          : JtkPMICoordinateNote
//
// Description    : A JtkPMI class for Coordinate Notes. A coordinate note can have the following properties:
//      <br/><b>standard:</b>           standard used in for the Coordinate Note
//      <br/><b>textBox:</b>            Indicates whether or not the note has a box around it
//      <br/><b>includeX:</b>           Indicates whether or not to include the X coordinate of the tracked entity
//      <br/><b>xPrefix:</b>            User specified prefix for X coordinate
//      <br/><b>xSuffix:</b>            User specified suffix for X coordinate
//      <br/><b>includeY:</b>           Indicates whether or not to include the Y coordinate of the tracked entity
//      <br/><b>yPrefix:</b>            User specified prefix for Y coordinate
//      <br/><b>ySuffix:</b>            User specified suffix for Y coordinate
//      <br/><b>includeZ:</b>           Indicates whether or not to include the Z coordinate of the tracked entity
//      <br/><b>zPrefix:</b>            User specified prefix for Z coordinate
//      <br/><b>zSuffix:</b>            User specified suffix for Z coordinate
//      <br/><b>includeI:</b>           Indicates whether or not to include the I component of the tracked entity
//                                      Only meaningful if the tracked entity has a normal vector
//      <br/><b>iPrefix:</b>            User specified prefix for I coordinate
//      <br/><b>iSuffix:</b>            User specified suffix for I coordinate
//      <br/><b>includeJ:</b>           Indicates whether or not to include the J component of the tracked entity
//                                      Only meaningful if the tracked entity has a normal vector
//      <br/><b>jPrefix:</b>            User specified prefix for J coordinate
//      <br/><b>jSuffix:</b>            User specified suffix for J coordinate
//      <br/><b>includeK:</b>           Indicates whether or not to include the K component of the tracked entity
//                                      Only meaningful if the tracked entity has a normal vector
//      <br/><b>kPrefix:</b>            User specified prefix for K coordinate
//      <br/><b>kSuffix:</b>            User specified suffix for K coordinate
//      <br/><b>includeLabel:</b>       Indicates whether or not to include the Label of the tracked entity
//      <br/><b>labelPrefix:</b>        User specified prefix for Label
//      <br/><b>labelSuffix:</b>        User specified suffix for Label
//      <br/><b>includeLevel:</b>       Indicates whether or not to include the Level of the tracked entity
//                                      Only meaningful if the tracked entity is a measurement point
//      <br/><b>levelPrefix:</b>        User specified prefix for Level
//      <br/><b>levelSuffix:</b>        User specified suffix for Level
//      <br/><b>coordinateSystemRef:</b>References the CoordinateSystem to which the Coordinate Note relates.        
//      <br/><b>identifier:</b>         The identifier of the Coordinate Note.
//      <br/><b>category:</b>           The category of the Coordinate Note.
//      <br/><b>revision:</b>           The revision of the Coordinate Note.
//      <br/><b>precision:</b>          number of decimal places
//      <br/><b>xOverride:</b>          overrides the computed X coordinate value of the Coordinate Note.
//      <br/><b>yOverride:</b>          overrides the computed Y coordinate value of the Coordinate Note.
//      <br/><b>zOverride:</b>          overrides the computed Z coordinate value of the Coordinate Note.
//      <br/><b>iOverride:</b>          overrides the computed I coordinate value of the Coordinate Note.
//      <br/><b>jOverride:</b>          overrides the computed J coordinate value of the Coordinate Note.
//      <br/><b>kOverride:</b>          overrides the computed K coordinate value of the Coordinate Note.
//
// Enums          : JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMICoordinateNote
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICoordinateNote : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMICoordinateNote )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICoordinateNote( JtkUnitHierarchy* owner );
   virtual ~JtkPMICoordinateNote( );

public:
   int getLabelSuffix( JtkString& ) const;
   int setLabelSuffix( const JtkString& );
   int unsetLabelSuffix( void );

   int getKPrefix( JtkString& ) const;
   int setKPrefix( const JtkString& );
   int unsetKPrefix( void );

   int getZSuffix( JtkString& ) const;
   int setZSuffix( const JtkString& );
   int unsetZSuffix( void );

   int getIncludeLabel( int& ) const;
   int setIncludeLabel( int );
   int unsetIncludeLabel( void );

   int getIncludeZ( int& ) const;
   int setIncludeZ( int );
   int unsetIncludeZ( void );

   int getLabelPrefix( JtkString& ) const;
   int setLabelPrefix( const JtkString& );
   int unsetLabelPrefix( void );

   int getIncludeX( int& ) const;
   int setIncludeX( int );
   int unsetIncludeX( void );

   int getIncludeY( int& ) const;
   int setIncludeY( int );
   int unsetIncludeY( void );

   int getJSuffix( JtkString& ) const;
   int setJSuffix( const JtkString& );
   int unsetJSuffix( void );

   int getLevelSuffix( JtkString& ) const;
   int setLevelSuffix( const JtkString& );
   int unsetLevelSuffix( void );

   int getIPrefix( JtkString& ) const;
   int setIPrefix( const JtkString& );
   int unsetIPrefix( void );

   int getZPrefix( JtkString& ) const;
   int setZPrefix( const JtkString& );
   int unsetZPrefix( void );

   int getLevelPrefix( JtkString& ) const;
   int setLevelPrefix( const JtkString& );
   int unsetLevelPrefix( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getISuffix( JtkString& ) const;
   int setISuffix( const JtkString& );
   int unsetISuffix( void );

   int getKSuffix( JtkString& ) const;
   int setKSuffix( const JtkString& );
   int unsetKSuffix( void );

   int getIncludeLevel( int& ) const;
   int setIncludeLevel( int );
   int unsetIncludeLevel( void );

   int getXSuffix( JtkString& ) const;
   int setXSuffix( const JtkString& );
   int unsetXSuffix( void );

   int getYSuffix( JtkString& ) const;
   int setYSuffix( const JtkString& );
   int unsetYSuffix( void );

   int getJPrefix( JtkString& ) const;
   int setJPrefix( const JtkString& );
   int unsetJPrefix( void );

   int getIncludeJ( int& ) const;
   int setIncludeJ( int );
   int unsetIncludeJ( void );

   int getIncludeK( int& ) const;
   int setIncludeK( int );
   int unsetIncludeK( void );

   int getTextBox( int& ) const;
   int setTextBox( int );
   int unsetTextBox( void );

   int getIncludeI( int& ) const;
   int setIncludeI( int );
   int unsetIncludeI( void );

   int getXPrefix( JtkString& ) const;
   int setXPrefix( const JtkString& );
   int unsetXPrefix( void );

   int getYPrefix( JtkString& ) const;
   int setYPrefix( const JtkString& );
   int unsetYPrefix( void );

   int getCoordinateSystemRef( int& id ) const;
   int setCoordinateSystemRef( int id );
   int unsetCoordinateSystemRef( );

   int getCoordinateSystem( double origin[3], double xaxis[3], double zaxis[3] ) const;
   int setCoordinateSystem( double origin[3], double xaxis[3], double zaxis[3] );
   int unsetCoordinateSystem( void );

   int getIdentifier( JtkString& ) const;
   int setIdentifier( const JtkString& );
   int unsetIdentifier( );

   int getCategory( JtkString& ) const;
   int setCategory( const JtkString& );
   int unsetCategory( );

   int getRevision( JtkString& ) const;
   int setRevision( const JtkString& );
   int unsetRevision( );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getXOverride( double& XOverride ) const;
   int setXOverride( double XOverride );
   int unsetXOverride( void );

   int getYOverride( double& YOverride ) const;
   int setYOverride( double YOverride );
   int unsetYOverride( void );

   int getZOverride( double& ZOverride ) const;
   int setZOverride( double ZOverride );
   int unsetZOverride( void );

   int getIOverride( double& IOverride ) const;
   int setIOverride( double IOverride );
   int unsetIOverride( void );

   int getJOverride( double& JOverride ) const;
   int setJOverride( double JOverride );
   int unsetJOverride( void );

   int getKOverride( double& KOverride ) const;
   int setKOverride( double KOverride );
   int unsetKOverride( void );

};
///////%{
//
// Class          : JtkPMIAttributeNote
//
// Description    : JtkPMI class for Attribute Notes. An attribute note can have the following properties:
//      <br/><b>standard:</b>         standard used for the AttributeNote
//      <br/><b>AttributeName:</b>      The values of the named attributes are used to construct the AttributeNote text.
//      <br/><b>includeLabels:</b>      Indicates whether or not the labels for the attributes are included in the note text
//
// Enums          : JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIAttributeNote
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIAttributeNote : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIAttributeNote )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIAttributeNote( JtkUnitHierarchy* owner );
   virtual ~JtkPMIAttributeNote( );

public:
   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int addAttributeName( const JtkString& );
   int numAttributeName( int& ) const;
   int setAttributeName( int index, const JtkString& );
   int getAttributeName( int index, JtkString& ) const;
   int unsetAttributeName( int index );

   int getIncludeLabels( int& ) const;
   int setIncludeLabels( int );
   int unsetIncludeLabels( void );
};
///////%{
//
// Class          : JtkPMIBundleDressingNote
//
// Description    : A JtkPMI class for Bundle or Dressing Note PMI. A bundle or dressing note can have the following properties:
//      <br/><b>standard:</b>         standard used for the BundleDressingNote
//      <br/><b>type:</b>               Indicates whether the Bundle/Dressing Note is a Bundle Note or a Dressing Note
//      <br/><b>locationOnCurve:</b>   The location (parameter) along the wirepath where the leader attaches for leader directed Bundle/Dressing Notes
//      <br/><b>AttributeName:</b>      Attribute name. The values of the named attributes are used to construct the BundleDressingNote text.
//      <br/><b>includeLabels:</b>      Indicates whether or not the labels for the attributes are included in the note text
//      <br/><b>precision:</b>         number of decimal places
//
// Enums          :   JtkPMIBundleDressingType:
//                        TypeBUNDLENOTE --
//                        TypeDRESSINGNOTE --
//
//                     JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIBundleDressingNote
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIBundleDressingNote : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIBundleDressingNote )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIBundleDressingNote( JtkUnitHierarchy* owner );
   virtual ~JtkPMIBundleDressingNote( );

public:
   int getType( JtkPMIBundleDressingType& ) const;
   int setType( JtkPMIBundleDressingType );
   int unsetType( void );

   int getStandard( JtkPMIDimensionStandard& ) const;
   int setStandard( JtkPMIDimensionStandard );
   int unsetStandard( void );

   int getLocationOnCurve( double& ) const;
   int setLocationOnCurve( double );
   int unsetLocationOnCurve( void );

   int addAttributeName( const JtkString& );
   int numAttributeName( int& ) const;
   int setAttributeName( int index, const JtkString& );
   int getAttributeName( int index, JtkString& ) const;
   int unsetAttributeName( int index );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getIncludeLabels( int& ) const;
   int setIncludeLabels( int );
   int unsetIncludeLabels( void );

};

///////%{
//
// Class          : JtkPMICuttingPlaneSymbol
//
// Description    : A JtkPMI class for Cutting Plane Symbols. The properties that a Cutting Plane Symbol can have depend on the type property.
//      The type is set by the setCuttingPlaneSymbol method and can be Plane, Open or Closed. This value can only be set once.
//
//      When the type is Plane then you can have multiple planes:
//      <br/><b>Plane:</b>                sepcification of origin, normal and reference axis of the plane as well as the mateiral side cut.
//
//      When the type is Closed or Open you can only specifiy a single <b>ConstraintPlane</b> that the curves lie within via:
//      <br/><b>materialSide:</b>         Indicates which side of the cut contains material.
//      <br/><b>planeOrigin:</b>          The origin of the constraint plane.
//      <br/><b>planeZAxis:</b>           The normal of the constraint plane.
//      <br/><b>planeYAxis:</b>           The axis of the constraint plane.
//
//      Properties for all types of Cutting Plane Symbols:                              
//      <br/><b>CpsLetters:</b>           The name displayed with the Cutting Plane Symbol in the
//                                        graphics region.
//      <br/><b>standard:</b>             The standard used for the cutting plane symbol.
//      <br/><b>twoArrows:</b>            Indicates whether one or two arrows are used in the cutting plane symbol
//      <br/><b>shadedPlane:</b>          Whether the plane cutters are shaded.
//      <br/><b>planeColour:</b>          The colour of the plane cutters.
//      <br/><b>textPlaneOrientation:</b> Whether the text is parallel or perpendicular to the
//                                        plane of the arrow. This overrides the orientation
//                                        dictated by the standard attribute on the corresponding
//                                        CuttingPlaneSymbol.
//      <br/><b>lineStyle:</b>            The style of the lines in the CuttingPlaneSymbol.
//      <br/><b>arrowPlacement1:</b>      The position of the first arrow on the outline of the CuttingPlaneSymbol.
//      <br/><b>arrowPlacement2:</b>      The position of the second arrow, if there is one, on the outline of the CuttingPlaneSymbol.
//      <br/><b>arrowTowardsCutter:>/b>   Whether the arrow is directed towards or away from the
//                                        cutting surface. If unspecified, the direction is determined by the standard.
//
//      Properties for closed and open types of Cutting Plane Symbols:
//      <br/><b>curveRef:</b>         reference to the closed curve which defines the cut. This may be a CompositeCurve.
//
//      Properties for closed Cutting Plane Symbols:
//      <br/><b>aftThroughAll:</b>    Indicates whether or not the extrusion in the Aft direction is "Through All"
//      <br/><b>aftDistance:</b>      The distance the extrude is performed in the Aft distance, in metres.
//      <br/><b>foreThroughAll:</b>   Indicates whether or not the extrusion in the Fore direction is "Through All"
//      <br/><b>foreDistance:</b>     The distance the extrude is performed in the Fore distance, in metres.
//      <br/><b>Planes:</b>           The sequence of cutting planes for plane type cutting plane symbols. 
//                                    At most 6 planes can be specified. Each plane is defined by an origin, 
//                                    z and x axes and an indication of which side of the plane contains material.
//
// Enums          : JtkPMICuttingPlaneSymbolType:
//                      CutterTypePLANE -- Cutting plane symbol is plane based.
//                      CutterTypeOPEN -- Cutting plane symbol is based on an open cutter.
//                      CutterTypeCLOSED -- Cutting plane symbol is based on a closed cutter.
//
//                  JtkPMICuttingPlaneStandard:                    
//                      CuttingPlaneStandardISO -- ISO standard
//                      CuttingPlaneStandardASME_Y1441M -- ASME Y14.41M standard
//
//                  JtkPMITextPlaneOrientation:
//                      TextPlaneOrientationPARALLEL -- CPS text is parallel to the plane of the arrow.
//                      TextPlaneOrientationPERPENDICULAR -- CPS text is perpendicular to the plane of the arrow.
//
//                  JtkPMIPlaneArrowPlacement:
//                      ArrowPlacementORIGIN -- arrow is positioned at the bottom left of the planes outline.
//                      ArrowPlacementTOP -- arrow is positioned at the top left of the planes outline.
//                      ArrowPlacementBOTTOMRIGHT -- arrow is positioned at bottom right of the planes outline.
//                      ArrowPlacementTOPRIGHT -- arrow is positioned at the top right of the planes outline.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMICuttingPlaneSymbol
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICuttingPlaneSymbol : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMICuttingPlaneSymbol )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICuttingPlaneSymbol( JtkUnitHierarchy* owner );
   virtual ~JtkPMICuttingPlaneSymbol( );

public:
   //Below methods apply for all types of CuttingPlaneSymbols
   int addCpsLetters( JtkPMIText*& cpsLetters );
   int getCpsLetters( JtkPMIText*& cpsLetters ) const;
   int unsetCpsLetters( );

   int setCuttingPlaneSymbol( JtkPMICuttingPlaneSymbolType type );
   int getCuttingPlaneSymbol( JtkPMICuttingPlaneSymbolType& type ) const;
   int unsetCuttingPlaneSymbol( void );

   int getStandard( JtkPMICuttingPlaneStandard& ) const;
   int setStandard( JtkPMICuttingPlaneStandard );
   int unsetStandard( );

   int getTwoArrows( int& var ) const;
   int setTwoArrows( int var );
   int unsetTwoArrows( );

   int getShadedPlane( int& var ) const;
   int setShadedPlane( int var );
   int unsetShadedPlane( );

   int getPlaneColour( JtkString& colour ) const;
   int setPlaneColour( const JtkString& colour );
   int unsetPlaneColour( );

   int getTextPlaneOrientation( JtkPMITextPlaneOrientation& ) const;
   int setTextPlaneOrientation( JtkPMITextPlaneOrientation );
   int unsetTextPlaneOrientation( );

   int getLineStyle( JtkPMILineStyle& ) const;
   int setLineStyle( JtkPMILineStyle );
   int unsetLineStyle( );

   int getArrowPlacement1( JtkPMIPlaneArrowPlacement& ) const;
   int setArrowPlacement1( JtkPMIPlaneArrowPlacement );
   int unsetArrowPlacement1( );

   int getArrowPlacement2( JtkPMIPlaneArrowPlacement& ) const;
   int setArrowPlacement2( JtkPMIPlaneArrowPlacement );
   int unsetArrowPlacement2( );

   //Below methods apply to both Open and Closed CuttingPlaneSymbols
   int setCurveRef( int dstId, int dstType, const JtkString& path = JtkString( ) );
   int getCurveRef( int& dstId, int& dstType, JtkString& path ) const;
   int unsetCurveRef( void );

   //Below methods only apply only to Closed CuttingPlaneSymbols
   int setClosedCutterAftThroughAll( int );
   int getClosedCutterAftThroughAll( int& );
   int unsetClosedCutterAftThroughAll( void );

   int setClosedCutterAftDistance( double );
   int getClosedCutterAftDistance( double& ) const;
   int unsetClosedCutterAftDistance( void );

   int setClosedCutterForeThroughAll( int );
   int getClosedCutterForeThroughAll( int& );
   int unsetClosedCutterForeThroughAll( void );

   int setClosedCutterForeDistance( double );
   int getClosedCutterForeDistance( double& ) const;
   int unsetClosedCutterForeDistance( void );

   //constraint plane specification
   int setPlaneOrigin( double, double, double );
   int getPlaneOrigin( double&, double&, double& ) const;
   int unsetPlaneOrigin( void );

   int setPlaneXAxis( double, double, double );
   int getPlaneXAxis( double&, double&, double& ) const;
   int unsetPlaneXAxis( void );

   int setPlaneZAxis( double, double, double );
   int getPlaneZAxis( double&, double&, double& ) const;
   int unsetPlaneZAxis( void );

   int setMaterialSide( int );
   int getMaterialSide( int& ) const;
   int unsetMaterialSide( );

   //multiple plane support
   int addPlane( double origin[3], double xaxis[3], double zaxis[3], int materialSide );
   int getPlane( int index, double origin[3], double xaxis[3], double zaxis[3], int &materialSide ) const;
   int unsetPlane( int index );
   int numPlanes( int& number ) const;

   int setArrowTowardsCutter( int );
   int getArrowTowardsCutter( int& ) const;
   int unsetArrowTowardsCutter( );
};
///////%{
//
// Class          : JtkPMICrosshatch
//
// Description    : JtkPMI class for the creation of a JtkPMICrosshatchPattern as a piece of PMI.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMICrosshatch
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICrosshatch : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMICrosshatch )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICrosshatch( JtkUnitHierarchy* owner );
   virtual ~JtkPMICrosshatch( );

public:
   int addPattern( JtkPMICrosshatchPattern*& createdPattern );
   int getPattern( JtkPMICrosshatchPattern*& existingPattern ) const;
   int unsetPattern( );
};

///////%{
//
// Class          : JtkPMIeMarking
//
// Description    : JtkPMI class for eMarkings. An eMarking has the following property:
//      <br/><b>type:</b>          type of information
//
// Enums          :   JtkPMIEMarkingType:
//                        TypeEXPORTCONTROL --
//                        TypePRODUCTPROPRIETARYINFO --
//                        TypeGOVERNMENTSECURITYINFO --
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMINote > JtkPMIeMarking
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIeMarking : public JtkPMINote
{
   JTK_OBJECT_HEADER( JtkPMIeMarking )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIeMarking( JtkUnitHierarchy* owner );
   virtual ~JtkPMIeMarking( );

public:
   int getType( JtkPMIEMarkingType& ) const;
   int setType( JtkPMIEMarkingType );
   int unsetType( void );
};
///////%{
//
// Class          : JtkPMIModelView
//
// Description    : A JtkPMI class for creating ModelViews. It can have the following properties:
//      <br/><b>viewId:</b>                  The unique viewId.
//      <br/><b>eyeDir:</b>                  The eye (view) direction.
//      <br/><b>eyePos:</b>                  The eye position.
//      <br/><b>targetPt:</b>                The target point.
//      <br/><b>viewAngle:</b>
//      <br/><b>viewportDiameter:</b>
//      <br/><b>clipThickness:</b>
//      <br/><b>bClip:</b>
//      <br/><b>bActive:</b>
//      <br/><b>name:</b>                     View name.
//      <br/><b>cameraType:</b>               The camera type of the view. Default perspective.
//      <br/><b>style:</b>                    Style.
//      <br/><b>shadingStyle:</b>             The shading style if the drawing style is shaded.
//      <br/><b>Members:</b>                  JtkEntitys that are associated with the ModelView
//      <br/><b>GeneralAttribute:</b>         Non specific user attributes.
//      <br/><b>edgeColour:</b>               How to colour the edges of a body. 
//
// Enums          : JtkPMICameraType:
//                      CameraTypePERSPECTIVE  -- perspective camera type
//                      CameraTypeORTHOGRAPHIC -- orthographic camera type
//
//                  JtkPMIModelViewStyle:
//                      ModelViewStyleUNSET           -- no style
//                      ModelViewStyleSHADED          -- solidly shaded
//                      ModelViewStyleSHADEDWITHEDGES -- solidly shaded with edges shown
//                      ModelViewStyleHIDDEN          -- wireframe with hidden lines not shown
//                      ModelViewStyleHIDDENMARKED    -- wireframe with hidden lines faintly shown
//                      ModelViewStyleWIREFRAME       -- all edges shown
//                      ModelViewStyleTRANSPARENT     -- all transparently shown
//
//                  JtkPMIShadingStyle:
//                      ShadingStyleFLAT           -- 
//                      ShadingStyleSMOOTH          -- 
//
//                  ViewBehavior
//                      ApplyCamera -- Apply the model view’s camera position when applying the model view.  Otherwise, camera state is not changed.
//                      ApplyPartVisibility -- Apply the model view’s part visibility.  Otherwise, part state is not changed.
//                      ApplyPMIVisibility -- Apply the model view’s PMI visibility.  Otherwise, PMI state is not changed.
//                      HideOtherParts -- Hide parts in the model view’s scope that are not specifically mentioned in the model view.  Otherwise, the visibility of parts not specifically mentioned is not changed.
//                      ShowOtherParts -- Shows parts in the model view’s scope that are not specifically mentioned in the model view.
//                      HideOtherPMI -- Hides PMI in the model view’s scope that are not specifically mentioned in the model view.  Otherwise, the visibility of PMI not specifically mentioned is not changed.
//
//                  JtkValidationCountType
//                      Annotation -- total number of annotation displayed within the view.
//                      AttributeNote -- total number of attribute notes displayed within the view.
//                      Balloon -- total number of balloon displayed within the view.
//                      BundleDressingNote -- total number of bundle dressing notes displayed within the view.
//                      CalloutDimension -- total number of callout dimension displayed within the view.
//                      Centerline -- total number of centerline displayed within the view.
//                      Chamfer -- total number of chamfer displayed within the view.
//                      CircleCentre -- total number of circle centre displayed within the view.
//                      CoordinateNote -- total number of coordinate note displayed within the view.
//                      Crosshatch -- total number of crosshatch displayed within the view.
//                      CuttingPlaneSymbol -- total number of cutting plane symbols displayed within the view.
//                      DatumFeatureSymbol -- total number of datumm feature symbols displayed within the view.
//                      DatumTarget -- total number of datum target displayed within the view.
//                      Dimension -- total number of dimension displayed within the view.
//                      eMarking -- total number of eMarking displayed within the view.
//                      Fastener -- total number of fastener displayed within the view.
//                      FeatureControlFrame -- total number of feature control frame displayed within the view.
//                      FitDesignation -- total number of fit designation displayed within the view.
//                      LineWeld -- total number of line weld displayed within the view.
//                      Locator -- total number of locator displayed within the view.
//                      MaterialSpecification -- total number of material specification displayed within the view.
//                      MeasurementPoint -- total number of measurement point displayed within the view.
//                      Note -- total number of note displayed within the view.
//                      Organisation -- total number of organisationdisplayed within the view.
//                      PartSpecification -- total number of part specification displayed within the view.
//                      ProcessSpecification -- total number of process specification displayed within the view.
//                      Region -- total number of region displayed within the view.
//                      SpotWeld -- total number of spotweld displayed within the view.
//                      SurfaceFinish -- total number of surface finish displayed within the view.
//                      UserDefinedSymbol -- total number of user defined symbol displayed within the view.
//                      Table -- total number of table PMI displayed within the view.
//
//                    JtkValidationLengthType
//                      PolylineLength -- total length of all polyline content displayed in the model view.
//                      AssociatedLength -- total curve length of wires and edge content displayed in the model view.
//
//                     JtkValidationAreaType:
//                        TessellatedArea -- total surface area of PMI displayed in the model view.
//                        AssociatedArea -- total surface area of B-rep content displayed in the model view.
//
//                     JtkValidationCentroidType:
//                        PolylineCentroid -- centroid of all the PMI polyline content displayed in the view.
//                        SurfaceCentroid -- centroid of all the PMI surface content displayed in the view.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIEntity > JtkPMIModelView
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIModelView : public JtkPMIEntity
{
   JTK_OBJECT_HEADER( JtkPMIModelView )
   _JtkPMIModelViewImpl* getImpl( ) const;
   void setImpl( _JtkPMIModelViewImpl* );
protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIModelView( JtkUnitHierarchy* owner );
   virtual ~JtkPMIModelView( );

public:
   int setViewId( int viewId );
   int getViewId( int& viewId ) const;

   int setEyeDirection( double d1, double d2, double d3, double d4 );
   int getEyeDirection( double& d1, double& d2, double& d3, double& d4 ) const;
   int unsetEyeDirection( );

   int setEyePosition( double d1, double d2, double d3 );
   int getEyePosition( double& d1, double& d2, double& d3 ) const;
   int unsetEyePosition( );

   int setTargetPoint( double x, double y, double z );
   int getTargetPoint( double& x, double& y, double& z ) const;
   int unsetTargetPoint( void );

   int setViewAngle( double d1, double d2, double d3 );
   int getViewAngle( double& d1, double& d2, double& d3 ) const;
   int unsetViewAngle( );

   int setViewportDiameter( double dia );
   int getViewportDiameter( double& dia ) const;
   int unsetViewportDiameter( );

   int setClipThickness( double ct );
   int getClipThickness( double& ct ) const;
   int unsetClipThickness( );

   int setBClip( int );
   int getBClip( int& ) const;
   int unsetBClip( );

   int setBActive( int );
   int getBActive( int& ) const;
   int unsetBActive( );

   int setCameraType( JtkPMICameraType );
   int getCameraType( JtkPMICameraType& ) const;
   int unsetCameraType( );

   int setStyle( JtkPMIModelViewStyle );
   int getStyle( JtkPMIModelViewStyle& ) const;
   int unsetStyle( );

   int setShadingStyle( JtkPMIShadingStyle );
   int getShadingStyle( JtkPMIShadingStyle& ) const;
   int unsetShadingStyle( );

   int setBackgroundColour( const JtkString& bottomLeft, const JtkString& bottomRight,
                            const JtkString& topLeft, const JtkString& topRight );
   int getBackgroundColour( JtkString& bottomLeft, JtkString& bottomRight,
                            JtkString& topLeft, JtkString& topRight ) const;
   int unsetBackgroundColour( );

   int setEdgeColour( const JtkString& Colour, int FromBody = 0 );
   int getEdgeColour( JtkString& Colour, int& FromBody ) const;
   int unsetEdgeColour( );

   int addMember( int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int numMembers( int& count ) const;
   int getMember( int index, int& dstId, int& dstType, JtkString& path ) const;
   int getMember( int index, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int unsetMember( int index );

   int getAttrProperty( int index, JtkString& key, JtkString& value, int& hidden ) const;
   int addAttrProperty( const JtkString& key, const JtkString& value, int hidden = 0 );

   int numGeneralAttributes( int& Number ) const;
   int addGeneralAttribute( const JtkString& Name, const JtkString& Value,
                            const JtkString& Unit = JtkString( ), const JtkString& Category = JtkString( ),
                            JtkMeasureEnum Dimensionality = MeasureEnumNONE,
                            JtkDataType Type = DataTypeSTRING, int Editable = 0 );
   int getGeneralAttribute( int Index, JtkString& Name, JtkString& Value,
                            JtkString& Unit, JtkString& Category,
                            JtkMeasureEnum& Dimensionality,
                            JtkDataType& Type, int& Editable ) const;
   int unsetGeneralAttribute( int Index );

   int numGeneralAttributeListValues( int Index, int& Number ) const;
   int addGeneralAttributeListValue( int Index, const JtkString& ListValue );
   int getGeneralAttributeListValue( int Index, int ListIndex, JtkString& ListValue ) const;
   int unsetGeneralAttributeListValue( int Index, int ListIndex );

   int setExploded( int );
   int getExploded( int& ) const;
   int unsetExploded( );

   enum ViewBehavior
   {
      ApplyCamera = 0x0001,
      ApplyPartVisibility = 0x0002,
      ApplyPMIVisibility = 0x0004,
      HideOtherParts = 0x0008,
      ShowOtherParts = 0x0010,
      HideOtherPMI = 0x0200
   };

   int setViewBehavior( unsigned short Behaviours );
   int getViewBehavior( unsigned short& Behaviours ) const;
   int unsetViewBehavior( );

   //PMI Validation APIs
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

   virtual int addValidationCount( JtkValidationCountType, int );
   virtual int getValidationCount( JtkValidationCountType, int& ) const;

   int addValidationString( const JtkString& );
   int getValidationString( JtkString& ) const;

   enum JtkValidationOriginType
   {
      AssociatedOrigin
   };

   int numValidationOrigins( JtkValidationOriginType, int& ) const;
   int addValidationOrigin( JtkValidationOriginType, double, double, double );
   int getValidationOrigin( JtkValidationOriginType, int index, double&, double&, double& ) const;

   int numValidationPoints( int& ) const;
   int addValidationPoint( double fromX, double fromY, double fromZ,
                           double toX, double toY, double toZ );
   int getValidationPoint( int, double& fromX, double& fromY, double& fromZ,
                           double& toX, double& toY, double& toZ ) const;
};

///////%{
//
// Class          : JtkPMIDesignGroup
//
// Description    : A JtkPMI class for creating Design Groups. It can have the following properties:
//      <br/><b>Entitys:</b>         JtkEntitys that are associated with the DesignGroup. An Entity cannot be a Model View PMI.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIFolder > JtkPMIDesignGroup
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIDesignGroup : public JtkPMIFolder
{
   JTK_OBJECT_HEADER( JtkPMIDesignGroup )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIDesignGroup( JtkUnitHierarchy* owner );
   virtual ~JtkPMIDesignGroup( );

public:
   int addEntity( int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int numEntities( int& count ) const;
   int getEntity( int index, int& dstId, int& dstType, JtkString& path ) const;
   int getEntity( int index, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int unsetEntity( int index );
};

///////%{
//
// Class          : JtkPMIContainer
//
// Description    : Represents a virtual collection of PMI and B-Rep entities.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIDesignGroup > JtkPMIContainer
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIContainer : public JtkPMIDesignGroup
{
   JTK_OBJECT_HEADER( JtkPMIContainer )

private:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIContainer( JtkUnitHierarchy* owner );
   virtual ~JtkPMIContainer( );

public:
};

///////%{
//
// Class          : JtkPMIViewSet
//
// Description    : A JtkPMI class for creating Design Group's which contain Model View. It can have the following properties:
//      <br/><b>ModelViews:</b>         ModelViews that are associated with the ViewSet. It will only accept references to ModelViews
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIFolder > JtkPMIViewSet
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIViewSet : public JtkPMIFolder
{
   JTK_OBJECT_HEADER( JtkPMIViewSet )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIViewSet( JtkUnitHierarchy* owner );
   virtual ~JtkPMIViewSet( );

public:
   int addModelView( int dstId, int dstType, int reason = -1 );
   int numModelViews( int& count ) const;
   int getModelView( int index, int& dstId, int& dstType ) const;
   int getModelView( int index, int& dstId, int& dstType, int& reason ) const;
   int unsetModelView( int index );

};

///////%{
//
// Class          : JtkPMIReferenceGeometry
//
// Description    : JTkPMI base class for reference geometry objects. It can have the following properties:
//      <br/><b>MaterialAmbient:</b>       The ambient value of the Material for the reference geometry
//      <br/><b>MaterialDiffuse:</b>       The diffuse value of the Material for the reference geometry
//      <br/><b>MaterialEmission:</b>      The emission value of the Material for the reference geometry
//      <br/><b>MaterialSpecular:</b>      The specular value of the Material for the reference geometry
//      <br/><b>MaterialShininess:</b>     The shininess value of the Material for the reference geometry
//      <br/><b>DrawStyleType:</b>         The draw style to be applied to the reference geometry
//      <br/><b>DrawStyleWidth:</b>        The width the reference geometry display
//      <br/><b>Visibility:</b>            Whether it is visible
//      <br/><b>Layer:</b>
//
// Enums          : JtkPMIRefGeomDrawType:
//                        JtkPMI_LINE_SOLID --
//                        JtkPMI_LINE_DASHED --
//                        JtkPMI_LINE_DOTTED --
//                        JtkPMI_LINE_DASHED_DOTTED --
//                        JtkPMI_LINE_PHANTOM --
//                        JtkPMI_LINE_LONG_DASHED --
//                        JtkPMI_LINE_CENTERLINE --
//                        JtkPMI_LINE_INVISIBLE --
//                        JtkPMI_POINT_NO_MARKER --
//                        JtkPMI_POINT_POINT_MARKER --
//                        JtkPMI_POINT_DOT_MARKER --
//                        JtkPMI_POINT_ASTERISK_MARKER --
//                        JtkPMI_POINT_CIRCLE_MARKER --
//                        JtkPMI_POINT_POUNDSIGN_MARKER --
//                        JtkPMI_POINT_X_MARKER --
//                        JtkPMI_POINT_GRIDPOINT_MARKER --
//                        JtkPMI_POINT_SQUARE_MARKER --
//                        JtkPMI_POINT_TRIANGLE_MARKER --
//                        JtkPMI_POINT_DIAMOND_MARKER --
//                        JtkPMI_POINT_CENTERLINE_MARKER --
//                        JtkPMI_POINT_ANCHOR_MARKER --
//                        JtkPMI_POINT_FILLED_CIRCLE_MARKER --
//                        JtkPMI_POINT_FILLED_SQUARE_MARKER --
//                        JtkPMI_POINT_LARGE_FILLED_SQUARE_MARKER --
//                        JtkPMI_POINT_CIRCLE_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_CIRCLE_IN_SQUARE_MARKER --
//                        JtkPMI_POINT_SQUARE_IN_SQUARE_MARKER --
//                        JtkPMI_POINT_FILLED_LEFT_TRIANGLE_MARKER --
//                        JtkPMI_POINT_FILLED_RIGHT_TRIANGLE_MARKER --
//                        JtkPMI_POINT_FILLED_UP_TRIANGLE_MARKER --
//                        JtkPMI_POINT_FILLED_DOWN_TRIANGLE_MARKER --
//                        JtkPMI_POINT_FILLED_LEFT_TRIANGLE_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_FILLED_RIGHT_TRIANGLE_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_FILLED_UP_TRIANGLE_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_FILLED_DOWN_TRIANGLE_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_FILLED_LEFT_TRIANGLE_IN_SQUARE_MARKER --
//                        JtkPMI_POINT_FILLED_RIGHT_TRIANGLE_IN_SQUARE_MARKER --
//                        JtkPMI_POINT_FILLED_UP_TRIANGLE_IN_SQUARE_MARKER --
//                        JtkPMI_POINT_FILLED_DOWN_TRIANGLEIN_SQUARE_MARKER --
//                        JtkPMI_POINT_ROUNDED_CROSS_MARKER --
//                        JtkPMI_POINT_FILLED_DIAMOND_MARKER --
//                        JtkPMI_POINT_UP_DOWN_TRIANGLES_MARKER --
//                        JtkPMI_POINT_LEFT_RIGHT_TRIANGLES_MARKER --
//                        JtkPMI_POINT_SMALL_WHEEL_MARKER --
//                        JtkPMI_POINT_LARGE_WHEEL_MARKER --
//                        JtkPMI_POINT_HOLLOW_CIRCLE_MARKER --
//                        JtkPMI_POINT_ARC_END_POINT_MARKER --
//                        JtkPMI_POINT_BIG_ASTERISK_MARKER --
//                        JtkPMI_POINT_LINE_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_PLUS_IN_CIRCLE_MARKER --
//                        JtkPMI_POINT_CENTER_OF_ROTATION_MARKER --
//                        JtkPMI_POINT_INVALID_MARKER --
//
//                     JtkPMITextLineThickness:
//                        TextThicknessNORMAL --
//                        TextThicknessTHICK --
//                        TextThicknessTHIN --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIGenericEntity > JtkPMIReferenceGeometry
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReferenceGeometry : public JtkPMIGenericEntity
{
   JTK_OBJECT_HEADER( JtkPMIReferenceGeometry )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIReferenceGeometry( JtkUnitHierarchy* owner );
   virtual ~JtkPMIReferenceGeometry( );
public:
   int setMaterialAmbientColour( double, double, double, double );
   int getMaterialAmbientColour( double&, double&, double&, double& ) const;
   int unsetMaterialAmbientColour( );

   int setMaterialSpecularColour( double, double, double, double );
   int getMaterialSpecularColour( double&, double&, double&, double& ) const;
   int unsetMaterialSpecularColour( );

   int setMaterialDiffuseColour( double, double, double, double );
   int getMaterialDiffuseColour( double&, double&, double&, double& ) const;
   int unsetMaterialDiffuseColour( );

   int setMaterialEmissionColour( double, double, double, double );
   int getMaterialEmissionColour( double&, double&, double&, double& ) const;
   int unsetMaterialEmissionColour( );

   int setMaterialShininess( double );
   int getMaterialShininess( double& ) const;
   int unsetMaterialShininess( );

   int setDrawStyleType( JtkPMIRefGeomDrawType );
   int getDrawStyleType( JtkPMIRefGeomDrawType& ) const;
   int unsetDrawStyleType( );

   int setDrawStyleWidth( JtkPMITextLineThickness );
   int getDrawStyleWidth( JtkPMITextLineThickness& );
   int unsetDrawStyleWidth( );

   int setWidth( JtkWidthMeasurementType measurementType, double width );
   int setWidth( const JtkString& namedWidth );
   int getWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getWidth( JtkString& namedWidth ) const;
   int unsetWidth( );

   int setVisibility( int );
   int getVisibility( int& ) const;
   int unsetVisibility( );

   int setLayer( int );
   int getLayer( int& ) const;
   int unsetLayer( );

   int numGeneralAttributes( int& Number ) const;
   int addGeneralAttribute( const JtkString& Name, const JtkString& Value,
                            const JtkString& Unit = JtkString( ), const JtkString& Category = JtkString( ),
                            JtkMeasureEnum Dimensionality = MeasureEnumNONE,
                            JtkDataType Type = DataTypeSTRING, int Editable = 0 );
   int getGeneralAttribute( int Index, JtkString& Name, JtkString& Value,
                            JtkString& Unit, JtkString& Category,
                            JtkMeasureEnum& Dimensionality,
                            JtkDataType& Type, int& Editable ) const;
   int unsetGeneralAttribute( int Index );

   int numGeneralAttributeListValues( int Index, int& Number ) const;
   int addGeneralAttributeListValue( int Index, const JtkString& ListValue );
   int getGeneralAttributeListValue( int Index, int ListIndex, JtkString& ListValue ) const;
   int unsetGeneralAttributeListValue( int Index, int ListIndex );
   int unsetGeneralAttrbuteListValue( int Index, int ListIndex );
};



///////%{
//
// Class          : JtkPMICoordinateSystem
//
// Description    : A JtkPMI class for coordinate systems. It is intended to supersede JtkCoordSys. It can have the following properties:
//      <br/><b>CoordinateFrame:</b>                      Allows the addition of PMIBasicAttr.ar2dFrame data to the PMI to represent a coordinate system.
//                                                      The default values for the origin, the bottom right corner, and the top left corner are
//                                                      (0,0,0), (1,0,0), and (0,0,1) respectively.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIReferenceGeometry > JtkPMICoordinateSystem
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICoordinateSystem : public JtkPMIReferenceGeometry
{
   JTK_OBJECT_HEADER( JtkPMICoordinateSystem )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICoordinateSystem( JtkUnitHierarchy* owner );
   virtual ~JtkPMICoordinateSystem( );
public:
   int setCoordinateFrame( double origin[3], double bottomRight[3], double topLeft[3] );
   int getCoordinateFrame( double origin[3], double bottomRight[3], double topLeft[3] ) const;
   int unsetCoordinateFrame( void );

   int setEndArrows( JtkPMIReferenceGeometryArrowType ArrowType );
   int getEndArrows( JtkPMIReferenceGeometryArrowType& ArrowType ) const;
   int unsetEndArrows( );
};
///////%{
//
// Class          : JtkPMIReferencePoint
//
// Description    : A JtkPMI class for reference points. It is intended to supersede JtkRefPoint. It can have the following properties:
//      <br/><b>Point</b>:      The point.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIReferenceGeometry > JtkPMIReferencePoint
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReferencePoint : public JtkPMIReferenceGeometry
{
   JTK_OBJECT_HEADER( JtkPMIReferencePoint )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIReferencePoint( JtkUnitHierarchy* owner );
   virtual ~JtkPMIReferencePoint( );
public:
   int setPoint( double x, double y, double z );
   int getPoint( double& x, double& y, double& z );
   int unsetPoint( void );
};
///////%{
//
// Class          : JtkPMIReferenceAxis
//
// Description    : A JtkPMI class for reference axes. It is intended to supersede JtkRefAxis. It can have the following properties:
//      <br/><b>Axis:</b>      Two points denoting the start and end points of an axis.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIReferenceGeometry > JtkPMIReferenceAxis
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReferenceAxis : public JtkPMIReferenceGeometry
{
   JTK_OBJECT_HEADER( JtkPMIReferenceAxis )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIReferenceAxis( JtkUnitHierarchy* owner );
   virtual ~JtkPMIReferenceAxis( );
public:
   int setAxis( double axisPoints[6] );
   int getAxis( double*& axisPoints ) const;
   int unsetAxis( void );

   int setEndArrow( JtkPMIReferenceGeometryArrowType Type );
   int getEndArrow( JtkPMIReferenceGeometryArrowType& Type ) const;
   int unsetEndArrow( );
};
///////%{
//
// Class          : JtkPMIReferencePlane
//
// Description    : A JtkPMI class for reference planes. It is intended to supersede JtkRefPlane. It can have the following properties:
//      <br/><b>Plane:</b>      Four points denoting a rectangle which represents a plane.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIReferenceGeometry > JtkPMIReferencePlane
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReferencePlane : public JtkPMIReferenceGeometry
{
   JTK_OBJECT_HEADER( JtkPMIReferencePlane )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIReferencePlane( JtkUnitHierarchy* owner );
   virtual ~JtkPMIReferencePlane( );
public:
   int setPlane( double planePoints[12] );
   int getPlane( double*& planePoints );
   int unsetPlane( void );
};
///////%{
//
// Class          : JtkPMIRegion
//
// Description    : A JtkPMI class for Region PMI. A region can have the following properties:
//      <br/><b>conformsToFaces:</b>      Whether the Region conforms to the target faces.
//      <br/><b>pattern:</b>              References a CrosshatchPattern that holds the crosshatch parameters of the Region. If this
//                                        attribute is absent, the Region is not   crosshatched.
//      <br/><b>Face:</b>                 A face that the region conforms to.
//      <br/><b>Area:</b>                 The Areas that constitute the Region.
//
//      Each Area can have the following properties
//         <br/><b>type:</b>              The shape of the Area as an JtkPMIRegionArea enum.
//         <br/><b>length:</b>            Refers to the side of a rectangular Area that lies along the 'x' axis of
//                                        the Plane sub-element.
//         <br/><b>width:</b>             Refers to the side of a rectangular Area that lies along the 'y' axis of
//                                        the Plane sub-element.
//         <br/><b>diameter:</b>          The diameter of a circular Area. The outer diameter of an annular Area.
//         <br/><b>innerDiameter:</b>     The inner diameter of an annular Area.
//         <br/><b>height:</b>            The height along the axis of a cylindrical Area in the direction of the 'z'
//                                        axis of the Plane sub-element.
//         <br/><b>insidePoint:</b>       If type is general and the Area has a set of Curve sub-elements, insidePoint
//                                        is any point that indicates the inside of the set.
//         <br/><b>originAnchor:</b>      If type is circular, rectangular or annular, originAnchor is the point on the
//                                        Area that the origin   attribute of the Plane sub-element defines.
//         <br/><b>Plane:</b>             The plane in which the Area lies. The origin of the
//                                        plane defines the origin of a circular, rectangular,
//                                        cylindrical or annular Area. The xAxis of the plane
//                                        defines the direction of a rectangular area. (Also
//                                        circular and annular but these are invariant under
//                                        change of direction.) The zAxis of the plane defines the
//                                        axis of a cylindrical Area.
//         <br/><b>Curve:</b>             The curves that constitute a general Area.
//
// Enums          :   JtkPMIOriginAnchor{
//                        OriginAnchorTOPLEFT --
//                        OriginAnchorTOPCENTRE --
//                        OriginAnchorTOPRIGHT --
//                        OriginAnchorMIDDLELEFT --
//                        OriginAnchorMIDDLECENTRE --
//                        OriginAnchorMIDDLERIGHT --
//                        OriginAnchorBOTTOMLEFT --
//                        OriginAnchorBOTTOMCENTRE --
//                        OriginAnchorBOTTOMRIGHT --
//
//                     JtkPMIRegionArea:
//                        AreaRECTANGULAR --
//                        AreaCIRCULAR --
//                        AreaANNULAR --
//                        AreaCYLINDRICAL --
//                        AreaGENERAL --
//
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIRegion
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIRegion : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIRegion )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIRegion( JtkUnitHierarchy* owner );
   virtual ~JtkPMIRegion( );

public:
   int addArea( );
   int numAreas( int& number ) const;
   int unsetArea( int index );

   int setAreaPlaneOrigin( int index, double v1, double v2, double v3 );
   int getAreaPlaneOrigin( int index, double& v1, double& v2, double& v3 ) const;
   int unsetAreaPlaneOrigin( int index );

   int setAreaPlaneXAxis( int index, double v1, double v2, double v3 );
   int getAreaPlaneXAxis( int index, double& v1, double& v2, double& v3 ) const;
   int unsetAreaPlaneXAxis( int index );

   int setAreaPlaneZAxis( int index, double v1, double v2, double v3 );
   int getAreaPlaneZAxis( int index, double& v1, double& v2, double& v3 ) const;
   int unsetAreaPlaneZAxis( int index );

   int addAreaCurveReference( int areaIndex, int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int numAreaCurveReferences( int areaIndex, int& number ) const;
   int getAreaCurveReference( int areaIndex, int refIndex, int& dstId, int& dstType, JtkString& path ) const;
   int getAreaCurveReference( int areaIndex, int refIndex, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int unsetAreaCurveReference( int areaIndex, int refIndex );

   int setAreaType( int index, JtkPMIRegionArea type );
   int getAreaType( int index, JtkPMIRegionArea& type ) const;
   int unsetAreaType( int index );

   int setAreaLength( int index, double length );
   int getAreaLength( int index, double& length ) const;
   int unsetAreaLength( int index );

   int setAreaWidth( int index, double width );
   int getAreaWidth( int index, double& width ) const;
   int unsetAreaWidth( int index );

   int setAreaDiameter( int index, double diameter );
   int getAreaDiameter( int index, double& diameter ) const;
   int unsetAreaDiameter( int index );

   int setAreaInnerDiameter( int index, double innerDiameter );
   int getAreaInnerDiameter( int index, double& innerDiameter ) const;
   int unsetAreaInnerDiameter( int index );

   int setAreaHeight( int index, double height );
   int getAreaHeight( int index, double& height ) const;
   int unsetAreaHeight( int index );

   int setAreaInsidePoint( int index, double v1, double v2, double v3 );
   int getAreaInsidePoint( int index, double& v1, double& v2, double& v3 ) const;
   int unsetAreaInsidePoint( int index );

   int setAreaOriginAnchor( int index, JtkPMIOriginAnchor originAnchor );
   int getAreaOriginAnchor( int index, JtkPMIOriginAnchor& originAnchor ) const;
   int unsetAreaOriginAnchor( int index );

   int setConformsToFaces( int conforms );
   int getConformsToFaces( int& conforms ) const;
   int unsetConformsToFaces( void );

   int addFace( int dstId, int dstType, const JtkString& path = JtkString( ), int reason = -1 );
   int numFaces( int& count ) const;
   int getFace( int index, int& dstId, int& dstType, JtkString& path ) const;
   int getFace( int index, int& dstId, int& dstType, JtkString& path, int& reason ) const;
   int unsetFace( int index );

   int addPattern( JtkPMICrosshatchPattern*& createdPattern );
   int getPattern( JtkPMICrosshatchPattern*& existingPattern ) const;
   int unsetPattern( void );
};

///////%{
//
// Class          : JtkPMISection
//
// Description    : A JtkPMI class for lightweight Section PMI
//      <br/><b>position:</b>                            The position of the section.
//      <br/><b>normal:</b>                              The normal direction of the plane creating the Section.
//                                                       This should point toward the area to be clipped away.
//      <br/><b>curveReference:</b>                      References the curves that result from the clip.
//      <br/><b>display:</b>                             The display type of the section.
//      <br/><b>render:</b>                              The render mode of the section.
//      <br/><b>capDisplay:</b>                          Whether the face resulting from the clip is displayed.
//      <br/><b>capColour:</b>                           The colour of the face resulting from the clip.
//      <br/><b>curveDisplay:</b>                        Whether the curves resulting from the clip are displayed.
//      <br/><b>curveColour:</b>                         The colour of the curves.
//      <br/><b>componentReferenceState</b>              Attribute identifying if componentReferences are being used
//                                                       to specify specific parts to clip, or parts to excluded from clip.
//                                                       Default is specifying specific parts to clip. This state can only
//                                                       be changed when no componentReferenceEntities exist.
//      <br/><b>componentReference:</b>                  This References parts from within the assembly to either be
//                                                       the only components clip, or to be the exponents excluded from clip.
//                                                       Whether we are excluding or specifying to clip is determined by the
//                                                       value of componentReferenceState. When no componentReferences are supplied
//                                                       the section will clip everything.
//      <br/><b>crosshatchMethod:</b>                    How to crosshatch the section (by pattern or by material) and a pattern
//                                                       to use in relation to that method.
//      <br/><b>crosshatchDefaultMaterialPattern:</b>    When crosshatching based on material this is the JtkCrosshatchPattern to use
//                                                       when the material of the component doesn't have a mapped to pattern.
//      <br/><b>crosshatchColour:</b>                    The colour to disply the crosshatch lines in.
//      <br/><b>crosshatchParameters:</b>                The spacing (in meters) and the angle (in degrees) at which to display the crosshatching.
//      <br/><b>crosshatchRotate:</b>                    Whether or not the crosshatch pattern is rotated. Default false.
//      <br/><b>referenceAxis:</b>                       Axis which is perpendicular to the normal residing in the plane.
//                                                       The crosshatch angle is measured from this axis.
//      <br/><b>derivesFromCuttingPlaneSymbol:</b>       The JtkPMICuttingPlaneSymbol the section derives from. Note that
//                                                       if the section derives from a cutting plane symbol the display and plane information
//      <br/><b>namedFromCuttingPlaneSymbol:</b>         When the section is deriving from a cutting plane symbol it is possible for the 
//                                                       name of the section to be derived from the name of the cutting plane symbol.
//                                                       cannot be altered. For section groups additionally the geometry type cannot be changed.
//      <br/><b>removeCoincidentEntities:</b>            Whether entities coincident with the section geometry are removed.
//      <br/><b>capColourFromBody:</b>                   Whether the colour of the face resulting from the cut is determined from the body (default false).
//                                                       If true, capColour should be ignored.
//      <br/><b>curveColourFromBody:</b>                 Whether the colour of the curves resulting from the cut is determined from the body (default false).
//                                                       If true, curvesColour should be ignored.
//      <br/><b>clipWireframeEntities:</b>               Whether wireframe entities lying within the section planes were removed from the view
//      <br/><b>assemblyCrosshatchMethod:</b>            How the consuming application should vary the
//                                                       crosshatch angle between adjacent components of an
//                                                       assembly to provide better visualization.
//      <br/><b>assemblyCrosshatchAdjacency:</b>         The separation below which components of an assembly are considered adjacent.
//
// Enums          :  JtkPMISectionComponentState:
//                      SectionComponentStateINCLUSIVE -- section clips only the supplied componentReferences
//                      SectionComponentStateEXCLUSIVE -- section doesn't clip the supplied componentReferences
//
//                   JtkPMISectionDisplay:
//                      SectionDisplaySLICE --
//                      SectionDisplaySECTION --
//                      SectionDisplayFAR --
//                      SectionDisplayNONE --
//
//                   JtkPMISectionStyle:
//                      SectionStyleSHADED --
//                      SectionStyleWIREFRAME --
//
//                   JtkSectionCrosshatchMethod :
//                      SectionCrosshatchMethodNONE -- crosshatch not specified (default should not be used with setCrosshatchMethod)
//                      SectionCrosshatchMethodBYPATTERN -- crosshatch all components with a set pattern
//                      SectionCrosshatchMethodBYMATERIAL -- crosshatch based on the pattern of any material associated with the components.
//
//                   JtkAssemblyCrosshatch : How the Section crosshatch angle should be varied between adjacent components of an assembly
//                      AssemblyCrosshatchNONE -- No crosshatch angle variation is allowed
//                      AssemblyCrosshatchDIAGONAL -- Restricted to pi/2 radians to the horizontal and the vertical.
//                      AssemblyCrosshatchVARIABLE -- Continuously variable.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIGenericEntity > JtkPMISection
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMISection : public JtkPMIGenericEntity
{
   JTK_OBJECT_HEADER( JtkPMISection )

private:
   int _state;

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMISection( JtkUnitHierarchy* owner );
   virtual ~JtkPMISection( );

public:
   int setPosition( double x, double y, double z );
   int getPosition( double& x, double& y, double& z ) const;
   int unsetPosition( );

   int setNormal( double x, double y, double z );
   int getNormal( double& x, double& y, double& z ) const;
   int unsetNormal( );

   int addCurveReference( int dstId, int dstType, const JtkString& path = JtkString( ) );
   int numCurveReferences( int& number ) const;
   int getCurveReference( int index, int& dstId, int& dstType, JtkString& path ) const;
   int unsetCurveReference( int index );

   int setDisplay( JtkPMISectionDisplay );
   int getDisplay( JtkPMISectionDisplay& ) const;
   int unsetDisplay( );

   int setRender( JtkPMISectionStyle );
   int getRender( JtkPMISectionStyle& ) const;
   int unsetRender( );

   int setCapDisplay( int );
   int getCapDisplay( int& ) const;
   int unsetCapDisplay( );

   int setCapColour( const JtkString& );
   int getCapColour( JtkString& ) const;
   int unsetCapColour( );

   int setCurveDisplay( int );
   int getCurveDisplay( int& ) const;
   int unsetCurveDisplay( );

   int setCurveColour( const JtkString& );
   int getCurveColour( JtkString& ) const;
   int unsetCurveColour( );

   int setComponentReferenceState( JtkPMISectionComponentState );
   int getComponentReferenceState( JtkPMISectionComponentState& );
   int unsetComponentReferenceState( );

   int addComponentReference( int dstId, const JtkString& path = JtkString( ) );
   int numComponentReferences( int& number ) const;
   int getComponentReference( int index, int& dstId, JtkString& path );
   int unsetComponentReference( int index );

   //section crosshatching
   int setCrosshatchMethod( JtkSectionCrosshatchMethod method, JtkCrosshatchPattern* pattern );
   int getCrosshatchMethod( JtkSectionCrosshatchMethod& method, JtkCrosshatchPattern*& pattern ) const;
   int unsetCrosshatchMethod( );

   int setCrosshatchDefaultMaterialPattern( JtkCrosshatchPattern* pattern );
   int getCrosshatchDefaultMaterialPattern( JtkCrosshatchPattern*& pattern ) const;
   int unsetCrosshatchDefaultMaterialPattern( );

   int setCrosshatchColour( const JtkString& );
   int getCrosshatchColour( JtkString& ) const;
   int unsetCrosshatchColour( );

   int setCrosshatchParameters( double spacing, double angle );
   int getCrosshatchParameters( double& spacing, double& angle ) const;
   int unsetCrosshatchParameters( );

   int setCrosshatchRotate( int );
   int getCrosshatchRotate( int& ) const;
   int unsetCrosshatchRotate( );

   int setReferenceAxis( double x, double y, double z );
   int getReferenceAxis( double& x, double& y, double& z ) const;
   int unsetReferenceAxis( );

   //derivation from JtkPMICuttingPlaneSymbol
   int setDerivesFromCuttingPlaneSymbol( JtkPMICuttingPlaneSymbol* derivesFrom );
   int getDerivesFromCuttingPlaneSymbol( JtkPMICuttingPlaneSymbol*& derivesFrom ) const;
   int unsetDerivesFromCuttingPlaneSymbol( );

   int setNamedFromCuttingPlaneSymbol( int );
   int getNamedFromCuttingPlaneSymbol( int& ) const;
   int unsetNamedFromCuttingPlaneSymbol( );

   int setRemoveCoincidentEntities( int );
   int getRemoveCoincidentEntities( int& ) const;
   int unsetRemoveCoincidentEntities( );

   int setCapColourFromBody( int );
   int getCapColourFromBody( int& ) const;
   int unsetCapColourFromBody( );

   int setCurveColourFromBody( int );
   int getCurveColourFromBody( int& ) const;
   int unsetCurveColourFromBody( );

   int setClipWireframeEntities( int );
   int getClipWireframeEntities( int& ) const;
   int unsetClipWireframeEntities( );

   int setAssemblyCrosshatchMethod( JtkAssemblyCrosshatch );
   int getAssemblyCrosshatchMethod( JtkAssemblyCrosshatch& )const;
   int unsetAssemblyCrosshatchMethod( );

   int setAssemblyCrosshatchAdjacency( double );
   int getAssemblyCrosshatchAdjacency( double& ) const;
   int unsetAssemblyCrosshatchAdjacency( );
};

///////%{
//
// Class          : JtkPMISectionGroup
//
// Description    : A JtkPMI class for Section Group PMI.
//      <br/><b>geometryType:</b>            The type of clipping that this Section group represents.
//
//      <br/><b>plane:</b>                   The collecton of planes that represent the Section Group. The normal for each plane should
//                                           point towards the area to be clipped away.
//      <br/><b>planeReferenceAxis:</b>      Axis which is perpendicular to the normal residing in the plane.
//                                           The crosshatch angle is measured from this axis.
//
// Enums          :  JtkPMISectionGroupGeometryType:
//                      SectionGroupGeometryPARALLELPLANES  -- section group consists of 2 parallel clipping planes.
//                      SectionGroupGeometryBOX             -- section group consists of 6 clipping planes that form a box.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMISection > JtkPMISectionGroup
//
// Visibility     : public
//
// Theory         : The position / normal functionality provided by the base JtkPMISection class is blocked for the JtkPMISectionGroup
//                  class. The addPlane, numPlanes, getPlane, unsetPlane should be used instead.
//
/////////%}
class JTK_TOOLKIT_API JtkPMISectionGroup : public JtkPMISection
{
   JTK_OBJECT_HEADER( JtkPMISectionGroup )

protected:

   JTK_PMI_ENTITY_ACCESS

   JtkPMISectionGroup( JtkUnitHierarchy* owner );
   virtual ~JtkPMISectionGroup( );

public:

   int setGeometryType( JtkPMISectionGroupGeometryType );
   int getGeometryType( JtkPMISectionGroupGeometryType& ) const;
   int unsetGeometryType( );

   int addPlane( double position[3], double normal[3] );
   int numPlanes( int& number ) const;
   int getPlane( int index, double position[3], double normal[3] ) const;
   int unsetPlane( int index );

   int setPlaneReferenceAxis( int index, double axis[3] );
   int getPlaneReferenceAxis( int index, double axis[3] ) const;
   int unsetPlaneReferenceAxis( int index );
};

///////%{
//
// Class          : JtkPMICenterline
//
// Description    : A JtkPMI class for centerline and centermark support
//      <br/><b>centerlineType:</b>          The type of the Centerline.
//      <br/><b>individualExtensions:</b>    Whether each extension is defined individually.
//      <br/><b>fullCircle:</b>              Whether a circular Centerline contains a full circle.
//      <br/><b>centercrossSize:</b>         For transverse Centerlines, the size of the center cross.
//      <br/><b>overrun:</b>                 For longitudinal Centerlines, the overrun past the model geometry.
//      <br/><b>shortDash:</b>               For 2DCenterline Centerlines, the length of the short dash.
//      <br/><b>angle:</b>                   The angle (in radians) of the center cross from the X
//                                           direction of the display plane.
//      <br/><b>circularCenterlineMethod</b> The method for defining circular centerlines.
//      <br/><b>Position:</b>                Positions of the Centerlines in model space.
//      <br/>displayOption:</b>              The type of the Centerline display.
//      <br/>width:</b>                      The width of the Centerline display.
//
// Enums          : JtkPMICenterlineType:
//                      Centerline2D --
//                      Centerline3D --
//                      CenterMark --
//                      CircularCenterline --
//                      BoltCircleCenterline --
//                      SymmetricCenterline --
//                      OffsetCenterline --
//
//                  JtkPMICenterlineDisplay:
//                      CenterlineNone --
//                      Centerline --
//                      CenterlineWithExtension --
//                      Centerpoint --
//
//                  JtkPMICircularCenterlineMethod:
//                      CircularCenterlineMethodCENTER -- The first Position is the center, subsequent points lie on the circle.
//                      CircularCenterlineMethodPOINTS -- All Position values are on the circle, 3 or more required.
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMICenterline
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICenterline : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMICenterline )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICenterline( JtkUnitHierarchy* owner );
   virtual ~JtkPMICenterline( );
public:
   int numPosition( int &number ) const;
   int addPosition( double x, double y, double z );
   int setPosition( int index, double x, double y, double z );
   int getPosition( int index, double&x, double& y, double& z ) const;
   int unsetPosition( int index );

   int setCenterlineType( JtkPMICenterlineType type );
   int getCenterlineType( JtkPMICenterlineType& type ) const;
   int unsetCenterlineType( void );

   int setIndividualExtensions( int trueFalse );
   int getIndividualExtensions( int& trueFalse ) const;
   int unsetIndividualExtensions( void );

   int setFullCircle( int trueFalse );
   int getFullCircle( int& trueFalse ) const;
   int unsetFullCircle( void );

   int setCentercrossSize( double size );
   int getCentercrossSize( double& size ) const;
   int unsetCentercrossSize( void );

   int setOverrun( double overrun );
   int getOverrun( double& overrun ) const;
   int unsetOverrun( void );

   int setShortDash( double shortDash );
   int getShortDash( double& shortDash ) const;
   int unsetShortDash( void );

   int setAngle( double angle );
   int getAngle( double& angle ) const;
   int unsetAngle( void );

   int setCenter( double x, double y, double z );
   int getCenter( double& x, double& y, double& z ) const;
   int unsetCenter( );

   int setCircularCenterlineMethod( JtkPMICircularCenterlineMethod method );
   int getCircularCenterlineMethod( JtkPMICircularCenterlineMethod& method ) const;
   int unsetCircularCenterlineMethod( );

   int setDisplayOption( JtkPMICenterlineDisplay display );
   int getDisplayOption( JtkPMICenterlineDisplay& display ) const;
   int unsetDisplayOption( void );

   int setWidth( JtkWidthMeasurementType MeasurementType, double Width );
   int setWidth( const JtkString& NamedWidth );
   int getWidth( JtkWidthMeasurementType MeasurementType, double& Width ) const;
   int getWidth( JtkString& NamedWidth ) const;
   int unsetWidth( void );

};
///////%{
//
// Class          : JtkPMIFitDesignation
//
// Description    : A JtkPMI class for fit designation annotation
//      <br/><b>value:</b>                   The basic size of the fit designation in metres.
//      <br/><b>holeUpperDelta:</b>          The maximum size of the hole minus the basic size in metres.
//      <br/><b>holeLowerDelta:</b>          The basic size minus the minimum size of the hole in metres.
//      <br/><b>shaftUpperDelta:</b>         The maximum size of the shaft minus the basic size in metres.
//      <br/><b>shaftLowerDelta:</b>         The basic size minus the minimum size of the shaft in metres.
//      <br/><b>pitchDiameterUpperDelta:</b> For threaded shafts, the maximum pitch diameter
//                                           minus the basic size in metres.
//      <br/><b>pitchDiameterLowerDelta:</b> For threaded shafts, the minimum pitch diameter
//                                           minus the basic size in metres.
//      <br/><b>holeDeviation:</b>           The deviation letter(s) of the hole.
//      <br/><b>holeGrade:</b>               The grade integer of the hole.
//      <br/><b>shaftDeviation:</b>          The deviation letter(s) of the shaft. For threaded
//                                           shafts, the deviation letter(s) of the major diameter.
//      <br/><b>shaftGrade:</b>              The grade integer of the shaft. For threaded shafts, the
//                                           grade integer of the major diameter.
//      <br/><b>pitchDiameterDeviation:</b>  For threaded shafts, the deviation letter(s) of
//                                           the pitch diameter.
//      <br/><b>pitchDiameterGrade:</b>      For threaded shafts, the grade integer of the pitch diameter.
//      <br/><b>FitDesignationText:</b>      Up to 4 positioned text elements.
//      <br/><b>manual:</b>                  Whether value has been entered manually. If it has, it
//                                           cannot be assumed to be synchronised with the referenced
//                                           geometry.
//      <br/><b>standard</b>                 For example, ANSI.
//      <br/><b>type</b>                     linear, radial, angular or curveLength
//      <br/><b>direction</b>                Direction of measurement.
//      <br/><b>reference</b>                Whether a reference Fit Designation.
//      <br/><b>origin</b>                   Whether the first or second entity is the origin 
//                                           for the fit designation.
//      <br/><b>patternCount</b>             The number of repetitions in a compound feature to which
//                                           the fit designation applies.
//      <br/><b>notToScale:</b>              Whether the FitDesignation is not-to-scale.
//      <br/><b>ValueText</b>                When manual is true, ValueText overrides value.
//      <br/><b>Statistical:</b>             statistical refinement
//      <br/><b>FreeState:</b>               free state refinement
//      <br/><b>toleranceDisplay:</b>        The method of display for any tolerances.
//      <br/><b>precision:</b>               The precision of the displayed value in number of
//                                           decimal places. This is the number of decimal places
//                                           that can be relied on, whether or not that number of
//                                           decimal places is actually displayed. Normally they
//                                           would be displayed but trailing zeros can be suppressed
//                                           by setting valueTrailingZero to false.
//      <br/><b>tolerancePrecision:</b>      The number of decimal places displayed in any tolerances.
//      <br/><b>zeroToleranceDisplay:</b>    Controls the display of any zero valued tolerances.
//      <br/><b>valueLeadingZero:</b>        Whether to display leading zeros in the value attribute.
//      <br/><b>toleranceLeadingZero:</b>    Whether to display leading zeros in any tolerances.
//      <br/><b>valueTrailingZero:</b>       Whether trailing zeros on the value attribute are
//                                           displayed. This does not affect the precision of the
//                                           displayed value. See precision attribute.
//      <br/><b>toleranceTrailingZero:</b>   Whether trailing zeros on any tolerances are displayed.
//      <br/><b>displayTolerance:</b>        Whether tolerance information is displayed.
//      <br/><b>displayClearance:</b>        Whether clearance information is displayed.
//      <br/><b>limitFitSingleLine:</b>      Whether the FitDesignation is displayed on a single
//                                           line with a slash character or like a fraction.
//      <br/><b>limitFitOrder:</b>           The order in which the value attribute, the deviation
//                                           and grade information, and the tolerance information on
//                                           the corresponding FitDesignation are displayed.
//      <br/><b>limitFitParentheses:</b>     Whether the value attribute, the deviation and grade
//                                           information or the tolerance information on the
//                                           corresponding FitDesignation are displayed in
//                                           parentheses.
//      <br/><b>horizontalLine:</b>          If limitFitSingleLine is false, horizontalLine
//                                           determines whether a line is drawn between the numerator
//                                           and the denominator of the FitDesignation.
//      <br/><b>alignment:</b>               If limitFitSingleLine is false, alignment determines
//                                           the vertical alignment of the hole/shaft deviation/grade
//                                           and the value.
//      <br/><b>style:</b>                   Style of display: radial, diamteral, sphericalRadial,
//                                           controlledRadial, spehericalDiamter, oridinate or
//                                           linearDiametral.
//      <br/><b>unitText:</b>                Whether to display the unitText.
//      <br/><b>limitFitAlignment:</b>       The position of the limit and fit (if there is one)
//                                           relative to the tolerance information, which follows.
//      <br/><b>dimensionLineSplit:</b>      Where the dimension line is split.
//      <br/><b>referenceDisplay:</b>        how to display reference Fit Designations - reference, parenthesis, or matched
//      <br/><b>diameterPlacement:</b>       before, after, above or below
//      <br/><b>radialPlacement:</b>         before, after, above or below
//      <br/><b>linearPlacement:</b>         before, after, above or below
//      <br/><b>limitDisplay:</b>            Wether limit information is displayed.
//      <br/><b>singleSided:</b>             Whether the Fit Designations is displayed single sided.
//      <br/><b>singleSideFirst:</b>         Whether a single sided Fit Designations points towards the
//                                           first or the second Reference sub-element.
//      <br/><b>singleSideLength:</b>        The length (or the arc length for an angular
//                                           Fit Designations) that the non arrow side of a single sided
//                                           Fit Designations protrudes from the text.
//      <br/><b>textOrientationType:</b>     How the Fit Designations text is orientated.
//      <br/><b>dimensionLineTrim:</b>       When textOrientationType is aboveDimensionLine and
//                                           the dimension line is displayed between the
//                                           extension lines, dimensionLineTrim specifies whether
//                                           the dimension line is trimmed if the dimension text
//                                           crosses both extension lines.
//      <br/><b>dimensionLineBetweenArrows:</b> Whether the dimension line is displayed
//                                           between the dimension arrowheads.
//      <br/><b>textLeaderPosition:</b>      The position and the orientation of the text at the
//                                           end of a Leader.
//      <br/><b>narrowOffset:</b>            For a narrow Fit Designations, the perpendicular distance
//                                           from the dimension line to the end of the Leader (if
//                                           there is one) or the text (if there is no Leader) in
//                                           metres.
//      <br/><b>narrowLeaderAngle:</b>       For a narrow Fit Designations, the angle between the
//                                           dimension line and the Leader in radians.
//      <br/><b>foldLocation:</b>            The location of the fold of a folded radius Fit Designations.
//      <br/><b>inspection:</b>              Whether the Fit Designations is used for inspection.
//      <br/><b>allAround:</b>               Whether the All Around symbol is added
//      <br/><b>allOver:</b>                 Whether the tolerance applies all over the 3-dimensional profile of the part
//      <br/><b>inspectionDisplay:</b>       If inspection is true, inspectionDisplay specifies how any appended
//                                           text is displayed inside the dimension inspection symbol
//      <br/><b>featureOfSize:</b>           Whether the Fit Designation specifies the size of a feature.
//      <br/><b>ToleranceTextFormat:</b>     Formatting attributes for the text of the tolerance values.
//
//      Each FitDesignationText can have the following properties:
//         <br/><b>position:</b>             Before, After, Above or Below
//         <br/><b>Text:</b>                 A single JtkPMIText for this positioned FitDesignationText.
//
// Enums          :   JtkPMIDimensionToleranceDisplay:
//                        ToleranceDisplayMINUSLIMIT1 --
//                        ToleranceDisplayBILATERAL --
//                        ToleranceDisplayPLUSLIMIT1 --
//                        ToleranceDisplayPLUSLIMIT2 --
//                        ToleranceDisplayEQUALBILATERAL --
//                        ToleranceDisplayMINUSLIMIT2 -
//                        ToleranceDisplayUPPERUNILATERAL --
//                        ToleranceDisplayLOWERUNILATERAL --
//
//                     JtkPMIDimensionZeroToleranceDisplay:
//                        ZeroToleranceDisplayDISPLAYZERO --
//                        ZeroToleranceDisplayBLANK --
//                        ZeroToleranceDisplaySUPPRESSTRAILINGZERO --
//                        ZeroToleranceDisplayOMIT --
//
//                     JtkPMILimitFitOrder:
//                        OrderVALUELIMITFITTOLERANCE --
//                        OrderTOLERANCEVALUELIMITFIT --
//                        OrderVALUETOLERANCELIMITFIT --
//
//                     JtkPMILimitFitParentheses:
//                        ParenthesesNONE --
//                        ParenthesesVALUELIMITFIT --
//                        ParenthesesLIMITFIT --
//                        ParenthesesTOLERANCE -
//
//                      JtkPMIFitDesignationAlignment:
//                        FitDesignationAlignmentMIDDLE -- 
//                        FitDesignationAlignmentBOTTOM --  
//
//                     JtkPMIDimensionOrigin:
//                        OriginFIRST --
//                        OriginSECOND --
//
//                     JtkPMIDimensionType:
//                        TypeCURVELENGTH --
//                        TypeLINEAR --
//                        TypeANGULAR --
//                        TypeRADIAL --
//
//                     JtkPMIDimensionStandard:
//                        StandardASME_Y145M_1994 --
//                        StandardJIS --
//                        StandardISO --
//                        StandardBS --
//                        StandardANSI_Y145M_1982 --
//                        StandardASME_Y1441M_2003 --
//                        StandardDIN --
//                        StandardGM_ADDENDUM_1994 --
//                        StandardASME_Y145_2009 --
//
//                     JtkPMIDimensionStyle:
//                        StyleLINEARDIAMETRAL --
//                        StyleRADIAL --
//                        StyleCONTROLLEDRADIAL --
//                        StyleDIAMETRAL --
//                        StyleLIMITS -- Deprecated in favor of the limitDisplay property
//                        StyleORDINATE --
//                        StyleSPHERICALRADIAL --
//                        StyleSPHERICALDIAMETRAL --
//                        StyleNARROW --
//                        StyleNONE --
//
//                     JtkPMIDimensionLineSplit:
//                        DimensionLineSplitNONE
//                        DimensionLineSplitLIMITFIT
//                        DimensionLineSplitVALUELIMITFIT
//
//                     JtkPMIDimensionReferenceDisplay:
//                        ReferenceDisplayPARENTHESIS --
//                        ReferenceDisplayREFERENCE --
//                        ReferenceDisplayMATCHED --
//
//                     JtkPMIDimensionPlacement:
//                        PlacementBEFORE --
//                        PlacementABOVE --
//                        PlacementBELOW --
//                        PlacementAFTER --
//
//                     JtkPMITextLeaderPosition:
//                        TextLeaderPositionNONE --
//                        TextLeaderPositionABOVELEADER --
//                        TextLeaderPositionAFTERLEADER --
//                        TextLeaderPositionABOVESTUB --
//                        TextLeaderPositionAFTERSTUB --
//
//                     JtkPMITextOrientation:
//                        TextOrientationHORIZONTAL --
//                        TextOrientationALIGNED --
//                        TextOrientationABOVE --
//                        TextOrientationPERPENDICULAR --
//                        TextOrientationUSERDEFINED --
//
//                     JtkPMILimitDisplay: 
//                        LimitDisplayNONE -- 
//                        LimitDisplayLIMITFIT --
// 
//                     JtkPMIInspectionDisplay:
//                        InspectionDisplayNONE -- No appended text is display inside the inspection symbol
//                        InspectionDisplayBEFORE -- Any before appended text is displayed inside the inspection symbol
//                        InspectionDisplayAFTER -- Any after appended text is displayed inside the inspection symbol
//                        InspectionDisplayBEFOREAFTER -- Any before and after appended text is displayed inside the inspection symbol
//                        InspectionDisplayALL -- All appended text is displayed inside the inspection symbol
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMIFitDesignation
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIFitDesignation : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMIFitDesignation )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIFitDesignation( JtkUnitHierarchy* owner );
   virtual ~JtkPMIFitDesignation( );
public:

   int getValue( double& ) const;
   int setValue( double );
   int unsetValue( void );

   int getHoleUpperDelta( double& ) const;
   int setHoleUpperDelta( double );
   int unsetHoleUpperDelta( void );

   int getHoleLowerDelta( double& ) const;
   int setHoleLowerDelta( double );
   int unsetHoleLowerDelta( void );

   int getShaftUpperDelta( double& ) const;
   int setShaftUpperDelta( double );
   int unsetShaftUpperDelta( void );

   int getShaftLowerDelta( double& ) const;
   int setShaftLowerDelta( double );
   int unsetShaftLowerDelta( void );

   int getPitchDiameterUpperDelta( double& ) const;
   int setPitchDiameterUpperDelta( double );
   int unsetPitchDiameterUpperDelta( void );

   int getPitchDiameterLowerDelta( double& ) const;
   int setPitchDiameterLowerDelta( double );
   int unsetPitchDiameterLowerDelta( void );

   int getHoleDeviation( JtkString& ) const;
   int setHoleDeviation( const JtkString& );
   int unsetHoleDeviation( void );

   int getHoleGrade( int& ) const;
   int setHoleGrade( int );
   int unsetHoleGrade( void );

   int getShaftDeviation( JtkString& ) const;
   int setShaftDeviation( const JtkString& );
   int unsetShaftDeviation( void );

   int getShaftGrade( int& ) const;
   int setShaftGrade( int );
   int unsetShaftGrade( void );

   int getPitchDiameterDeviation( JtkString& ) const;
   int setPitchDiameterDeviation( const JtkString& );
   int unsetPitchDiameterDeviation( void );

   int getPitchDiameterGrade( int& ) const;
   int setPitchDiameterGrade( int );
   int unsetPitchDiameterGrade( void );

   int addFitDesignationText( );
   int numFitDesignationText( int& number ) const;
   int unsetFitDesignationText( int index );

   int addFitDesignationTextText( int dIndex, JtkPMIText*& );
   int getFitDesignationTextText( int dIndex, JtkPMIText*& ) const;
   int unsetFitDesignationTextText( int dIndex );

   int setFitDesignationTextPosition( int dIndex, JtkPMIDimensionPlacement pos );
   int getFitDesignationTextPosition( int dIndex, JtkPMIDimensionPlacement& pos ) const;
   int unsetFitDesignationTextPosition( int dIndex );

   int setManual( int );
   int getManual( int& ) const;
   int unsetManual( void );

   int addValueText( JtkPMIText*& );
   int getValueText( JtkPMIText*& ) const;
   int unsetValueText( );

   int addFreeState( void );
   int getFreeState( void ) const;
   int unsetFreeState( void );

   int addStatistical( void );
   int getStatistical( void ) const;
   int unsetStatistical( void );

   int setStandard( JtkPMIDimensionStandard standard );
   int getStandard( JtkPMIDimensionStandard& standard ) const;
   int unsetStandard( );

   int setType( JtkPMIDimensionType type );
   int getType( JtkPMIDimensionType& type ) const;
   int unsetType( );

   int setDirection( double x, double y, double z );
   int getDirection( double& x, double& y, double& z ) const;
   int unsetDirection( );

   int setIsReference( int isReference );
   int getIsReference( int& isReference ) const;
   int unsetIsReference( );

   int setOrigin( JtkPMIDimensionOrigin origin );
   int getOrigin( JtkPMIDimensionOrigin& origin ) const;
   int unsetOrigin( );

   int setPatternCount( int patternCount );
   int getPatternCount( int& patternCount ) const;
   int unsetPatternCount( );

   int getNotToScale( int& ) const;
   int setNotToScale( int );
   int unsetNotToScale( void );

   int getToleranceDisplay( JtkPMIDimensionToleranceDisplay& ) const;
   int setToleranceDisplay( JtkPMIDimensionToleranceDisplay );
   int unsetToleranceDisplay( void );

   int getPrecision( int& ) const;
   int setPrecision( int );
   int unsetPrecision( void );

   int getTolerancePrecision( int& ) const;
   int setTolerancePrecision( int );
   int unsetTolerancePrecision( void );

   int getZeroToleranceDisplay( JtkPMIDimensionZeroToleranceDisplay& ) const;
   int setZeroToleranceDisplay( JtkPMIDimensionZeroToleranceDisplay );
   int unsetZeroToleranceDisplay( void );

   int getValueLeadingZero( int& ) const;
   int setValueLeadingZero( int );
   int unsetValueLeadingZero( void );

   int getToleranceLeadingZero( int& ) const;
   int setToleranceLeadingZero( int );
   int unsetToleranceLeadingZero( void );

   int getValueTrailingZero( int& ) const;
   int setValueTrailingZero( int );
   int unsetValueTrailingZero( void );

   int getToleranceTrailingZero( int& ) const;
   int setToleranceTrailingZero( int );
   int unsetToleranceTrailingZero( void );

   int getDisplayTolerance( int& ) const;
   int setDisplayTolerance( int );
   int unsetDisplayTolerance( void );

   int getDisplayClearance( int& ) const;
   int setDisplayClearance( int );
   int unsetDisplayClearance( void );

   int getLimitFitSingleLine( int& ) const;
   int setLimitFitSingleLine( int );
   int unsetLimitFitSingleLine( void );

   int getLimitFitOrder( JtkPMILimitFitOrder& );
   int setLimitFitOrder( JtkPMILimitFitOrder );
   int unsetLimitFitOrder( void );

   int getLimitFitParentheses( JtkPMILimitFitParentheses& );
   int setLimitFitParentheses( JtkPMILimitFitParentheses );
   int unsetLimitFitParentheses( void );

   int getHorizontalLine( int& ) const;
   int setHorizontalLine( int );
   int unsetHorizontalLine( );

   int getAlignment( JtkPMIFitDesignationAlignment& ) const;
   int setAlignment( JtkPMIFitDesignationAlignment );
   int unsetAlignment( );

   int setStyle( JtkPMIDimensionStyle style );
   int getStyle( JtkPMIDimensionStyle& style ) const;
   int unsetStyle( );

   int setUnitText( int display );
   int getUnitText( int& display ) const;
   int unsetUnitText( );

   int setLimitFitAlignment( JtkPMIFitDesignationAlignment );
   int getLimitFitAlignment( JtkPMIFitDesignationAlignment& ) const;
   int unsetLimitFitAlignment( );

   int setDimensionLineSplit( JtkPMIDimensionLineSplit );
   int getDimensionLineSplit( JtkPMIDimensionLineSplit& ) const;
   int unsetDimensionLineSplit( );

   int getReferenceDisplay( JtkPMIDimensionReferenceDisplay& ) const;
   int setReferenceDisplay( JtkPMIDimensionReferenceDisplay );
   int unsetReferenceDisplay( void );

   int getDiameterPlacement( JtkPMIDimensionPlacement& ) const;
   int setDiameterPlacement( JtkPMIDimensionPlacement );
   int unsetDiameterPlacement( void );

   int getRadialPlacement( JtkPMIDimensionPlacement& ) const;
   int setRadialPlacement( JtkPMIDimensionPlacement );
   int unsetRadialPlacement( void );

   int getLinearPlacement( JtkPMIDimensionPlacement& ) const;
   int setLinearPlacement( JtkPMIDimensionPlacement );
   int unsetLinearPlacement( void );

   int getLimitDisplay( JtkPMILimitDisplay& ) const;
   int setLimitDisplay( JtkPMILimitDisplay );
   int unsetLimitDisplay( void );

   int getSingleSided( int& ) const;
   int setSingleSided( int );
   int unsetSingleSided( );

   int getSingleSideFirst( int& ) const;
   int setSingleSideFirst( int );
   int unsetSingleSideFirst( );

   int getSingleSideLength( double& ) const;
   int setSingleSideLength( double );
   int unsetSingleSideLength( );

   int getTextOrientationType( JtkPMITextOrientation& ) const;
   int setTextOrientationType( JtkPMITextOrientation );
   int unsetTextOrientationType( );

   int getDimensionLineTrim( int& ) const;
   int setDimensionLineTrim( int );
   int unsetDimensionLineTrim( );

   int getDimensionLineBetweenArrows( int& ) const;
   int setDimensionLineBetweenArrows( int );
   int unsetDimensionLineBetweenArrows( );

   int getTextLeaderPosition( JtkPMITextLeaderPosition& ) const;
   int setTextLeaderPosition( JtkPMITextLeaderPosition );
   int unsetTextLeaderPosition( );

   int getNarrowOffset( double& ) const;
   int setNarrowOffset( double );
   int unsetNarrowOffset( );

   int getNarrowLeaderAngle( double& ) const;
   int setNarrowLeaderAngle( double );
   int unsetNarrowLeaderAngle( );

   int getFoldLocation( double&, double&, double& ) const;
   int setFoldLocation( double, double, double );
   int unsetFoldLocation( );

   int getInspection( int& ) const;
   int setInspection( int );
   int unsetInspection( );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( );

   int getAllOver( int& ) const;
   int setAllOver( int );
   int unsetAllOver( );

   int getInspectionDisplay( JtkPMIInspectionDisplay& ) const;
   int setInspectionDisplay( JtkPMIInspectionDisplay );
   int unsetInspectionDisplay( );

   int addToleranceTextFormat( JtkPMITextFormat*& );
   int getToleranceTextFormat( JtkPMITextFormat*& ) const;
   int unsetToleranceTextFormat( );

   int getFeatureOfSize( int& ) const;
   int setFeatureOfSize( int );
   int unsetFeatureOfSize( );
};
///////%{
//
// Class          : JtkPMICompositeFeatureControlFrame
//
// Description    : A JtkPMI class for creation of a composite feature control frame.
//                  This allows for mulitple feature control frames to be
//                  connected together to form a single PMI.
//
//                  With the exception of setName (which is supported for the member
//                  FeatureControlFrames) it is expected that any shared functionality will
//                  be applied to the owning JtkPMICompositeFeatureControlFrame. As such
//                  it is expected that all display (i.e. display created through the
//                  setVisualPolylineData, setVisualValidty etc.) will be applied directly to the
//                  composite frame and not to one of the member FeatureControlFrames.
//                  Similarly setId is not expected to be called against the member FeatureControlFrames.
//                  As such use of this functionality on the member FeatureControlFrame is not supported.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIVisualEntity > JtkPMICompositeFeatureControlFrame
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICompositeFeatureControlFrame : public JtkPMIVisualEntity
{
   JTK_OBJECT_HEADER( JtkPMICompositeFeatureControlFrame )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICompositeFeatureControlFrame( JtkUnitHierarchy* owner );
   virtual ~JtkPMICompositeFeatureControlFrame( );
public:
   int addFeatureControlFrame( JtkPMIFeatureControlFrame*& );
   int numFeatureControlFrames( int& ) const;
   int getFeatureControlFrame( int, JtkPMIFeatureControlFrame*& );
   int unsetFeatureControlFrame( int );
};

///////%{
//
// Class          : JtkPMIModelViewList
//
// Description    : A PMI class for the creation of lists of JtkPMIModelView 
//                  and JtkPMIViewSet entities.
//
//                  A JtkPMIModelViewList can contain both JtkPMIModelView and 
//                  JtkPMIViewSet entities and provides a mechanism for ordering 
//                  them for a given JtkUnitHierarchy. Multiple JtkPMIModelViewList 
//                  entities can exist for a given node but only one of these can be
//                  considered current. After the first current list is located
//                  subsequent JtkPMIModelViewList entities will be persisted to JT 
//                  as additional available orders.
//
//                  Note:  If a JtkPMIModelViewList exists then it must contain all 
//                  the JtkPMIModelViews of the owning JtkUnitHierarchy node. This 
//                  can either be directly or indirectly via the use of a JtkPMIViewSet container.
//
//                  Note: A JtkPMIViewSet can only be added to a JtkPMIModelViewList when
//                  the JtkEnvironment::JtkPMI_PERSISTED_ID_ENABLED option is enabled (i.e set to 1)
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkRefCounted > JtkPMIModelViewList
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class _JtkPMIModelViewListImpl;
class JTK_TOOLKIT_API JtkPMIModelViewList : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkPMIModelViewList )
   JTK_PMI_ENTITY_ACCESS
protected:
   _JtkPMIModelViewListImpl* _impl;
   JtkPMIModelViewList( JtkUnitHierarchy* owner );
   virtual ~JtkPMIModelViewList( );

public:
   int setName( const JtkString& sOrderListName );
   int getName( JtkString& sOrderListName )const;

   int setCurrent( int isCurrent );
   int getCurrent( int& isCurrent )const;

   int addMember( JtkPMIModelView* pModelView );
   int addMember( JtkPMIViewSet* pViewSet );
   int getMember( int nIndex, JtkPMIEntity*& entity ) const;
   int numMembers( int& nEntities ) const;
};

///////%{
//
// Class          : JtkPMIReferenceCircle
//
// Description    : Creates a circular reference geometry in the jt.
//      <br/><b>radius</b>:      The radius of the circle.
//      <br/><b>parameter</b>:   The start and end parameter of the circle
//      <br/><b>origin</b>:      The origin of the circle.
//      <br/><b>normal</b>:      The normal to the plane containing the circle.
//      <br/><b>axis</b>:        The x-axis of the plane containing the circle.
//      <br/><b>CirclePoints</b>:A number of sampled points to depict the appearance of the circle.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIReferenceGeometry > JtkPMIReferenceCircle
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReferenceCircle : public JtkPMIReferenceGeometry
{
   JTK_OBJECT_HEADER( JtkPMIReferenceCircle )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIReferenceCircle( JtkUnitHierarchy* owner );
   virtual ~JtkPMIReferenceCircle( );

public:
   int setRadius( double radius );
   int getRadius( double& radius ) const;
   int unsetRadius( );

   int setParameters( double startT, double endT );
   int getParameters( double &startT, double &endT ) const;
   int unsetParameters( );

   int setOrigin( double x, double y, double z );
   int getOrigin( double& x, double& y, double& z ) const;
   int unsetOrigin( );

   int setNormal( double nx, double ny, double nz );
   int getNormal( double& nx, double& ny, double& nz ) const;
   int unsetNormal( );

   int setAxis( double nx, double ny, double nz );
   int getAxis( double& nx, double& ny, double& nz ) const;
   int unsetAxis( );

   int setCirclePoints( int nPoints, double* points );
   int getCirclePoints( int& nPoints, double*& points ) const;
   int unsetCirclePoints( );
};

///////%{
//
// Class          : JtkPMIReferenceCylinder
//
// Description    : Creates a cylindrical reference geometry in the jt.
//      <br/><b>radius</b>:         The radius of the cylinder.
//      <br/><b>parameter</b>:      The start and end u v parameters of the cylinder
//      <br/><b>origin</b>:         The origin of the cylinder.
//      <br/><b>normal</b>:         The normal axis of the cylinder.
//      <br/><b>axis</b>:           The x-axis of the cylinder.
//      <br/><b>CylinderPoints</b>: A number of sampled points forming a tristrip
//                                  to depict the appearance of the cylinder.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIReferenceGeometry > JtkPMIReferenceCylinder
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReferenceCylinder : public JtkPMIReferenceGeometry
{
   JTK_OBJECT_HEADER( JtkPMIReferenceCylinder )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIReferenceCylinder( JtkUnitHierarchy* owner );
   virtual ~JtkPMIReferenceCylinder( );

public:
   int setRadius( double radius );
   int getRadius( double& radius ) const;
   int unsetRadius( );

   int setParameters( double startU, double endU, double startV, double endV );
   int getParameters( double &startU, double &endU, double &startV, double &endV ) const;
   int unsetParameters( );

   int setOrigin( double x, double y, double z );
   int getOrigin( double& x, double& y, double& z ) const;
   int unsetOrigin( );

   int setNormal( double nx, double ny, double nz );
   int getNormal( double& nx, double& ny, double& nz ) const;
   int unsetNormal( );

   int setAxis( double nx, double ny, double nz );
   int getAxis( double& nx, double& ny, double& nz ) const;
   int unsetAxis( );

   int setCylinderPoints( int nPoints, double* points );
   int getCylinderPoints( int& nPoints, double*& points ) const;
   int unsetCylinderPoints( );
};

///////%{
//
// Class          : JtkPMIParameterDimension
//
// Description    : A parameter dimension. A parameter dimension can only exist as part of a 
//                  callout dimension, it is not possible to have a parameter dimension by itself.
//      <br/><b>parameter</b>:         The parameter this parameter dimension represents.
//
// Enums          : JtkPMIParameterType:
//                      ParameterTypeDIAMETER --
//                      ParameterTypeDEPTH --
//                      ParameterTypeCOUNTERBOREDIAMETER --
//                      ParameterTypeCOUNTERBOREDEPTH --
//                      ParameterTypeCOUNTERSINKDIAMETER --
//                      ParameterTypeCOUNTERSINKANGLE --
//                      ParameterTypeTAPERANGLE --
//                      ParameterTypeFIT --
//                      ParameterTypeSCREWTYPE --
//                      ParameterTypeSCREWSIZE --
//                      ParameterTypeTHREADSIZE --
//                      ParameterTypeTHREADDEPTH --
//                      ParameterTypeSTARTCHAMFERDIAMETER --
//                      ParameterTypeSTARTCHAMFERANGLE --
//                      ParameterTypeENDCHAMFERDIAMETER --
//                      ParameterTypeENDCHAMFERANGLE --
//                      ParameterTypePITCH --
//                      ParameterTypeANGLE --
//                      ParameterTypeMINORDIAMETER --
//                      ParameterTypeMAJORDIAMETER --
//                      ParameterTypeTAPDRILLDIAMETER --
//                      ParameterTypeLENGTH --
//                      ParameterTypeTAPDRILLSIZE --
//                      ParameterTypeSYMBOLICTHREADCALLOUT --
//                      ParameterTypeSHAFTSIZE --
//                      ParameterTypeTHREADPITCH --
//                      ParameterTypeFORM --
//                      ParameterTypeINTERNALEXTERNALSYMBOL -- 
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIDimension > JtkPMIParameterDimension
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIParameterDimension : public JtkPMIDimension
{
   JTK_OBJECT_HEADER( JtkPMIParameterDimension )

protected:
   JTK_PMI_ENTITY_ACCESS
   friend class JtkPMICalloutDimension;

   JtkPMIParameterDimension( );
   virtual ~JtkPMIParameterDimension( );

public:
   int setParameter( JtkPMIParameterType  Parameter );
   int getParameter( JtkPMIParameterType& Parameter ) const;
   int unsetParameter( );
};

///////%{
//
// Class          : JtkPMICalloutDimension
//
// Description    : A callout dimension.
//      <br/><b>parameterSpaceFactor</b>:     The space factor between the parameters in the callout dimension
//      <br/><b>parameterLineFactor</b>:      The line factor between lines in multi-line callout dimensions.
//
//      <br/><b>ParameterDimension</b>:        A number of JtkPMIParameterDimensions contained by the callout dimension.
//
// Enums          :
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIDimension > JtkPMICalloutDimension
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMICalloutDimension : public JtkPMIDimension
{
   JTK_OBJECT_HEADER( JtkPMICalloutDimension )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMICalloutDimension( JtkUnitHierarchy* Owner );
   virtual ~JtkPMICalloutDimension( );

public:
   int numParameterDimensions( int& Number ) const;
   int addParameterDimension( JtkPMIParameterDimension*& ParameterDimension );
   int getParameterDimension( int Index, JtkPMIParameterDimension*& ParameterDimension ) const;
   int unsetParameterDimension( int Index );

   int setParameterSpaceFactor( double SpaceFactor );
   int getParameterSpaceFactor( double& SpaceFactor ) const;
   int unsetParameterSpaceFactor( );

   int setParameterLineFactor( double LineFactor );
   int getParameterLineFactor( double& LineFactor ) const;
   int unsetParameterLineFactor( );
};

///////%{
//
// Class          : JtkPMIChamfer
//
// Description    : A chamfer dimension.
//      <br/><b>chamferDisplayType</b>:        How a Chamfer Dimension is displayed.
//      <br/><b>chamferLeaderType</b>:         How the Leader of a Chamfer Dimension is displayed.
//      <br/><b>chamferSymbolType</b>:         How any Chamfer Dimension symbol is displayed.
//      <br/><b>chamferSeparatorCapital</b>:   When chamferDisplayType is sizeAngle orangleSize,
//                                             chamferSeparatorCapital specifies whether the
//                                             separator is displayed in upper or lower case.
//      <br/><b>chamferSpacing</b>:            Specifies the spacing between the characters or 
//                                             symbols and the chamfer dimension as a multiple of the
//                                             character size.
//
//      <br/><b>ChamferSymbol</b>:             pecifies the prefix or suffix characters when chamferSymbolType
//                                             is set to prefix or suffix.
//
// Enums          :  JtkPMIChamferDisplay:
//                      ChamferDisplaySYMBOL --
//                      ChamferDisplaySIZE --
//                      ChamferDisplaySIZEANGLE --
//                      ChamferDisplayANGLESIZE --
//
//                   JtkPMIChamferLeader:
//                      ChamferLeaderPERPENDICULAR --
//                      ChamferLeaderPARALLEL --
//                      ChamferLeaderLINEAR --
//
//                   JtkPMIChamferSymbol:
//                      ChamferSymbolNONE --
//                      ChamferSymbolPREFIX --
//                      ChamferSymbolSUFFIX --
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIDimension > JtkPMIChamfer
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIChamfer : public JtkPMIDimension
{
   JTK_OBJECT_HEADER( JtkPMIChamfer )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMIChamfer( JtkUnitHierarchy* Owner );
   virtual ~JtkPMIChamfer( );

public:
   int getChamferDisplayType( JtkPMIChamferDisplay& ) const;
   int setChamferDisplayType( JtkPMIChamferDisplay );
   int unsetChamferDisplayType( );

   int getChamferLeaderType( JtkPMIChamferLeader& ) const;
   int setChamferLeaderType( JtkPMIChamferLeader );
   int unsetChamferLeaderType( );

   int getChamferSymbolType( JtkPMIChamferSymbol& ) const;
   int setChamferSymbolType( JtkPMIChamferSymbol );
   int unsetChamferSymbolType( );

   int getChamferSeparatorCapital( int& ) const;
   int setChamferSeparatorCapital( int );
   int unsetChamferSeparatorCapital( );

   int getChamferSpacing( double& ) const;
   int setChamferSpacing( double );
   int unsetChamferSpacing( );

   int addChamferSymbol( JtkPMIText*& );
   int getChamferSymbol( JtkPMIText*& )const;
   int unsetChamferSymbol( );
};

class JtkPMITableColumn;
class JtkPMITableRow;
class JtkPMITableCell;
class JtkPMITableValue;

///////%{
//
// Class          : JtkPMITable
//
// Description    : A PMI table
//      <br/><b>columnCount</b>:          The number of columns in the table.
//      <br/><b>rowCount</b>:             The number of rows in the table.
//      <br/><b>allAround</b>:            Whether the All Around symbol is added.
//      <br/><b>Column</b>:               The default formatting and content for the columns of the table.
//                                        The number of Columns cannot exceed the columnCount but
//                                        maybe be less than it if some Columns are empty or blank.
//      <br/><b>Row</b>:                  The default formatting and content for the rows of the
//                                        table. The number of Rows cannot exceed the rowCount but
//                                        maybe be less than it if some rows are empty or blank.
//
// Enums          :  
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIAnnotation > JtkPMITable
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITable : public JtkPMIAnnotation
{
   JTK_OBJECT_HEADER( JtkPMITable )

protected:
   JTK_PMI_ENTITY_ACCESS
   JtkPMITable( JtkUnitHierarchy* Owner );
   virtual ~JtkPMITable( );

public:

   int getColumnCount( unsigned int& ) const;
   int setColumnCount( unsigned int );
   int unsetColumnCount( );

   int getRowCount( unsigned int& ) const;
   int setRowCount( unsigned int );
   int unsetRowCount( );

   int numColumn( unsigned int& Number ) const;
   int addColumn( JtkPMITableColumn*& );
   int getColumn( unsigned int Index, JtkPMITableColumn*& ) const;
   int unsetColumn( unsigned int Index );

   int numRow( unsigned int& Number ) const;
   int addRow( JtkPMITableRow*& );
   int getRow( unsigned int Index, JtkPMITableRow*& ) const;
   int unsetRow( unsigned int Index );

   int getAllAround( int& ) const;
   int setAllAround( int );
   int unsetAllAround( void );
};

///////%{
//
// Class          : JtkPMITableMember
//
// Description    : Base class for sub-components of the JtkPMITable. With display formatting properties
//      As the JtkPMITable, JtkPMITableColumn, JtkPMITableRow and JtkPMITableCell as support this information
//      the formatting should be used based on the formatting closest to the cell so:
//      <br/><b>blanked:</b>                          true if the components's display is marked as not to be displayed at the moment.
//      <br/><b>symbolColour:</b>                     colour of the lines in the components.
//      <br/><b>textOrigin:</b>                       3D vector describing the location of the top left corner of the text window
//                                                    in model space, in metres.
//      <br/><b>textDirection:</b>                    3D direction of the text in the display plane of the JtkPMITable
//      <br/><b>commaAsDecimal:</b>                   Whether the decimal separator is represented by a
//                                                    full-stop or a comma.
//      <br/><b>language:</b>                         The language of the text.
//      <br/><b>font:</b>                             The font of the text.
//      <br/><b>textHeight:</b>                       The height of the text.
//      <br/><b>textThickness:</b>                    The thickness of lines representing the text.
//      <br/><b>textLineWidth:</b>                    The width of lines representing the text the text.
//      <br/><b>textAspect:</b>                       The ratio of textHeight to textWdith.
//      <br/><b>textColour:</b>                       The colour of the text.
//      <br/><b>bold:</b>                             Whether the text is bold.
//      <br/><b>italic:</b>                           Whether the text is italic.
//      <br/><b>italicAngle:</b>                      The angle of the italic on the text.
//      <br/><b>strikethrough:</b>                    Whether the text is struck through.
//      <br/><b>subscript:</b>                        Whether the text is subscript.
//      <br/><b>underline:</b>                        The underline of the text.
//      <br/><b>justification:</b>                    The text justification.
//      <br/><b>spaceFactor:</b>                      The space between letters.
//      <br/><b>lineFactor:</b>                       The space between lines.
//    It also has
//      <br/><b>Outline:</b>                          An JtkPMIAnnotationOutline specifying the outlining of the component.
//
// Enums          :  
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMITableMember
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITableMember : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITableMember )

   JtkPMITableMember( );
   virtual ~JtkPMITableMember( );
public:
   int getNumber( unsigned int& ) const;
   int setNumber( unsigned int );
   int unsetNumber( );

   int getBlanked( int& ) const;
   int setBlanked( int );
   int unsetBlanked( void );

   int getSymbolColour( JtkString& ) const;
   int setSymbolColour( const JtkString& );
   int unsetSymbolColour( void );

   int getTextOrigin( double&, double&, double& ) const;
   int setTextOrigin( double, double, double );
   int unsetTextOrigin( void );

   int getTextDirection( double&, double&, double& ) const;
   int setTextDirection( double, double, double );
   int unsetTextDirection( void );

   int getCommaAsDecimal( int& ) const;
   int setCommaAsDecimal( int );
   int unsetCommaAsDecimal( void );

   int getLanguage( JtkString& ) const;
   int setLanguage( const JtkString& );
   int unsetLanguage( void );

   int getFont( JtkString& ) const;
   int setFont( const JtkString& );
   int unsetFont( void );

   int getTextHeight( double& ) const;
   int setTextHeight( double );
   int unsetTextHeight( void );

   int getTextThickness( JtkPMITextLineThickness& ) const;
   int setTextThickness( JtkPMITextLineThickness );
   int unsetTextThickness( void );

   int getTextLineWidth( JtkWidthMeasurementType measurementType, double& width ) const;
   int getTextLineWidth( JtkString& namedWidth ) const;
   int setTextLineWidth( JtkWidthMeasurementType measurementType, double width );
   int setTextLineWidth( const JtkString& namedWidth );
   int unsetTextLineWidth( void );

   int getTextAspect( double& ) const;
   int setTextAspect( double );
   int unsetTextAspect( void );

   int getTextColour( JtkString& colour ) const;
   int setTextColour( const JtkString& colour );
   int unsetTextColour( void );

   int getBold( int& ) const;
   int setBold( int );
   int unsetBold( void );

   int getItalic( int& ) const;
   int setItalic( int );
   int unsetItalic( void );

   int getItalicAngle( double& ) const;
   int setItalicAngle( double );
   int unsetItalicAngle( void );

   int getStrikethrough( JtkPMIStrikethrough& ) const;
   int setStrikethrough( JtkPMIStrikethrough );
   int unsetStrikethrough( void );

   int getSubscript( JtkPMISubscript& ) const;
   int setSubscript( JtkPMISubscript );
   int unsetSubscript( void );

   int getUnderline( JtkPMIUnderline& ) const;
   int setUnderline( JtkPMIUnderline );
   int unsetUnderline( void );

   int getJustification( JtkPMIJustification& ) const;
   int setJustification( JtkPMIJustification );
   int unsetJustification( void );

   int getSpaceFactor( double& ) const;
   int setSpaceFactor( double );
   int unsetSpaceFactor( void );

   int getLineFactor( double& ) const;
   int setLineFactor( double );
   int unsetLineFactor( void );

   int addOutline( JtkPMIAnnotationOutline*& );
   int getOutline( JtkPMIAnnotationOutline*& ) const;
   int unsetOutline( );
};

///////%{
//
// Class          : JtkPMITableColumn
//
// Description    : A Column in a JtkPMITable
//      <br/><b>number</b>:       The identifier for the column in the table.
//      <br/><b>width</b>:        The default width of the column in meters.
//      <br/><b>ColumnValue</b>:  The default value and references common to the column.
//
// Enums          : 
//
// Includes       : JtkPMI.h
//
// Inheritance    :  JtkPMITableMember > JtkPMITableColumn
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITableColumn : public JtkPMITableMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITableColumn )

   JtkPMITableColumn( );
   virtual ~JtkPMITableColumn( );
public:

   int setWidth( double );
   int getWidth( double& ) const;
   int unsetWidth( );

   int numColumnValue( unsigned int& Number )  const;
   int addColumnValue( JtkPMITableValue*& );
   int getColumnValue( unsigned int Index, JtkPMITableValue*& ) const;
   int unsetColumnValue( unsigned int Index );
};

///////%{
//
// Class          : JtkPMITableRow
//
// Description    : A Row in a JtkPMITable
//      <br/><b>number</b>:       The number for the row in the table.
//      <br/><b>header</b>:       Whether the row is a header row.
//      <br/><b>height</b>:       The default height of the row in meters.
//      <br/><b>RowValue</b>:     The default value and references common to the row.
//      <br/><b>Cell</b>:         The formatting and content for the individual cells of the table.
//                          This overrides any defaults supplied via the JtkPMITableRow or JtkPMIColumn this Cell aligns to.
//                                The number of Cells cannot exceed the columnCount of the JtkPMITable,
//                                this Row belongs too but may be less than it if some cells are ommited/blank or merged over.
//
// Enums          : 
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMITableMember > JtkPMITableRow
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITableRow : public JtkPMITableMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITableRow )

   JtkPMITableRow( );
   virtual ~JtkPMITableRow( );

public:

   int setHeader( int );
   int getHeader( int& )const;
   int unsetHeader( );

   int setHeight( double );
   int getHeight( double& ) const;
   int unsetHeight( );

   int numRowValue( unsigned int& Number )  const;
   int addRowValue( JtkPMITableValue*& );
   int getRowValue( unsigned int Index, JtkPMITableValue*& ) const;
   int unsetRowValue( unsigned int Index );

   int numCell( unsigned int& Number ) const;
   int addCell( JtkPMITableCell*& );
   int getCell( unsigned int Index, JtkPMITableCell*& ) const;
   int unsetCell( unsigned int Index );
};

///////%{
//
// Class          : JtkPMITableCell
//
// Description    : A Cell in a JtkPMITable
//      <br/><b>number</b>:        The column number of the cell within the containing row
//      <br/><b>mergeAcross</b>:  The number of adjacent cells across from the cell to merge.
//      <br/><b>mergeDown</b>:    The number of adjacent cells below the cell to merge.
//      <br/><b>CellValue</b>:    The value and any references of the cell.
//
// Enums          : 
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMITableMember > JtkPMITableCell
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITableCell : public JtkPMITableMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITableCell )

   JtkPMITableCell( );
   virtual ~JtkPMITableCell( );

public:
   int setMergeAcross( unsigned int );
   int getMergeAcross( unsigned int& ) const;
   int unsetMergeAcross( );

   int setMergeDown( unsigned int );
   int getMergeDown( unsigned int& ) const;
   int unsetMergeDown( );

   int numCellValue( unsigned int& Number ) const;
   int addCellValue( JtkPMITableValue*& );
   int getCellValue( unsigned int Index, JtkPMITableValue*& ) const;
   int unsetCellValue( unsigned int Index );
};

///////%{
//
// Class          : JtkPMITableListValue
//
// Description    : An item in a JtkPMITableList comprising of 
//                   <br/><b>value</b>:         the value of the item
//                   <br/><b>description</b>:   optional description for the item

//
// Enums          :  
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMITableListValue
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITableListValue : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITableListValue )
   friend class _JtkPMIMemberImpl;

   JtkPMITableListValue( );
   virtual ~JtkPMITableListValue( );

public:
   int setValue( const JtkString& );
   int getValue( JtkString& ) const;
   int unsetValue( );

   int setDescription( const JtkString& );
   int getDescription( JtkString& ) const;
   int unsetDescription( );
};

///////%{
//
// Class          : JtkPMITableValue
//
// Description    : Class for specialised User defined typed data values
//                  <br/><b>title</b>:          the name of this piece of data
//                  <br/><b>value</b>:          the value of this data (unless type is UserValueDataTypeLIST )
//                  <br/><b>type</b>:           the data type of the value
//                  <br/><b>format</b>:         the format string used for printf type operations
//                  <br/><b>reference</b>:      if type == UserValueDataTypeREFERENCE the referenced content
//                  <br/><b>editable</b>:       false if the receiving application should modify the value
//                  <br/><b>minInclusive</b>:   minimum value allowed (inclusive)
//                  <br/><b>minExclusive</b>:   minimum value allowed (exclusive)
//                  <br/><b>maxInclusive</b>:   maximum value allowed (inclusive)
//                  <br/><b>maxExclusive</b>:   maximum value allowed (exclusive)
//                  <br/><b>stepValue</b>:      allowed values go from minimum to maximum according to step value.
//                  <br/><b>minLength</b>:      minimum length of list allowed
//                  <br/><b>maxLength</b>:      maximum lenght of list allowed.
//                  <br/><b>List</b>:           JtkPMITableList containing a list of values if type == UserValueDataTypeLIST.
//                                              Alternatively if type == UserValueDataTypeENUM the list of all possible
//                                              enumeration values with value being a value from this list.
//
// Enums          : JtkPMIUserValueDataType:
//                        UserValueDataTypeINT --
//                        UserValueDataTypeINTS --
//                        UserValueDataTypeREAL --
//                        UserValueDataTypeREALS --
//                        UserValueDataTypeBOOLEAN --
//                        UserValueDataTypeBOOLEANS --
//                        UserValueDataTypeSTRING --
//                        UserValueDataTypeREFERENCE --
//                        UserValueDataTypeENUM --
//                        UserValueDataTypeLIST --
//                        UserValueDataTypeDATETIME -- 
//                        UserValueDataTypeNONE -- 
//
// Includes       : JtkPMI.h
//
// Inheritance    : JtkPMIMember > JtkPMITableValue
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMITableValue : public JtkPMIMember
{
private:
   JTK_OBJECT_HEADER( JtkPMITableValue )

   JtkPMITableValue( );
   virtual ~JtkPMITableValue( );

public:
   int setTitle( const JtkString& );
   int getTitle( JtkString& ) const;
   int unsetTitle( );

   int setValue( const JtkString& );
   int getValue( JtkString& ) const;
   int unsetValue( );

   int setType( JtkPMIUserValueDataType );
   int getType( JtkPMIUserValueDataType& ) const;
   int unsetType( );

   int setFormat( const JtkString& );
   int getFormat( JtkString& ) const;
   int unsetFormat( );

   int setReference( int TargetId, int TargetType, const JtkString& TargetPath );
   int getReference( int& TargetId, int& TargetType, JtkString& TargetPath ) const;
   int unsetReference( );

   int setEditable( int );
   int getEditable( int& ) const;
   int unsetEditable( );

   int setMinInclusive( double );
   int getMinInclusive( double& ) const;
   int unsetMinInclusive( );

   int setMinExclusive( double );
   int getMinExclusive( double& ) const;
   int unsetMinExclusive( );

   int setMaxInclusive( double );
   int getMaxInclusive( double& ) const;
   int unsetMaxInclusive( );

   int setMaxExclusive( double );
   int getMaxExclusive( double& ) const;
   int unsetMaxExclusive( );

   int setStepValue( double );
   int getStepValue( double& ) const;
   int unsetStepValue( );

   int setMaxLength( unsigned int );
   int getMaxLength( unsigned int& ) const;
   int unsetMaxLength( );

   int setMinLength( unsigned int );
   int getMinLength( unsigned int& ) const;
   int unsetMinLength( );

   int setListType( JtkPMIUserValueDataType );
   int getListType( JtkPMIUserValueDataType& ) const;
   int unsetListType( );

   int numListValue( unsigned int& Number ) const;
   int addListValue( JtkPMITableListValue*& );
   int getListValue( unsigned int Index, JtkPMITableListValue*& ) const;
   int unsetListValue( unsigned int Index );
};


#endif // JTK_PMI_H

