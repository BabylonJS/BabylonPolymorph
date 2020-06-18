/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 11/06/2019 09:51:05
// 
// Schema:	PLMXMLAnnotationSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_ANNOTATION60_H__
#define __PLMXML_ANNOTATION60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_ANNOTATION60_EXPORTS
#define PLMXML_ANNOTATION60_API __declspec(dllexport)
#else
#define PLMXML_ANNOTATION60_API __declspec(dllimport)
#endif
#else
#define PLMXML_ANNOTATION60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


#include <plmxml_pdm60.h>

#include <plmxml_classification60.h>
#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
// TODO: Add extra include headers within this block
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFUnequalDisplayEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFUnequalDisplayEnumCircleU
	"circleU"
  eAnn3DFCFUnequalDisplayEnumUZ
	"UZ"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFUnequalDisplayEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFUnequalDisplayEnum( const char* Type );
     
	//! Constructor
	eAnn3DFCFUnequalDisplayEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFUnequalDisplayEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFCFUnequalDisplayEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFCFUnequalDisplayEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFUnequalDisplayEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFUnequalDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFUnequalDisplayEnum& e1, const eAnn3DFCFUnequalDisplayEnum& e2 );
     
	//! Compare Ann3DFCFUnequalDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFUnequalDisplayEnum& e1, const eAnn3DFCFUnequalDisplayEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFUnequalDisplayEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFCFUnequalDisplayEnum eAnn3DFCFUnequalDisplayEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFUnequalDisplayEnum eAnn3DFCFUnequalDisplayEnumCircleU;
extern PLMXML_ANNOTATION60_API eAnn3DFCFUnequalDisplayEnum eAnn3DFCFUnequalDisplayEnumUZ;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextOrientationEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DTextOrientationEnumAligned
	"aligned"
  eAnn3DTextOrientationEnumAbove
	"above"
  eAnn3DTextOrientationEnumUserDefined
	"userDefined"
  eAnn3DTextOrientationEnumPerpendicular
	"perpendicular"
  eAnn3DTextOrientationEnumHorizontal
	"horizontal"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextOrientationEnum( const char* Type );
     
	//! Constructor
	eAnn3DTextOrientationEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextOrientationEnum( );
     
	//! Destructor 
	virtual ~eAnn3DTextOrientationEnum( );
     
	//! Assign from 'Type'
	const eAnn3DTextOrientationEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextOrientationEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextOrientationEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextOrientationEnum& e1, const eAnn3DTextOrientationEnum& e2 );
     
	//! Compare Ann3DTextOrientationEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextOrientationEnum& e1, const eAnn3DTextOrientationEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextOrientationEnum;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum eAnn3DTextOrientationEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum eAnn3DTextOrientationEnumAligned;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum eAnn3DTextOrientationEnumAbove;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum eAnn3DTextOrientationEnumUserDefined;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum eAnn3DTextOrientationEnumPerpendicular;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationEnum eAnn3DTextOrientationEnumHorizontal;

////////////////////////////////////////////////////////////////////////////////////
//! eTextJustificationType class
/*!
Allowed Values:
\verbatim
  eTextJustificationTypeLeft
	"left"
  eTextJustificationTypeBottomLeft
	"bottomLeft"
  eTextJustificationTypeTopLeft
	"topLeft"
  eTextJustificationTypeTopRight
	"topRight"
  eTextJustificationTypeTopCentre
	"topCentre"
  eTextJustificationTypeCentre
	"centre"
  eTextJustificationTypeBottomCentre
	"bottomCentre"
  eTextJustificationTypeRight
	"right"
  eTextJustificationTypeBottomRight
	"bottomRight"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eTextJustificationType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTextJustificationType( const char* Type );
     
	//! Constructor
	eTextJustificationType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTextJustificationType( );
     
	//! Destructor 
	virtual ~eTextJustificationType( );
     
	//! Assign from 'Type'
	const eTextJustificationType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTextJustificationType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TextJustificationType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eTextJustificationType& e1, const eTextJustificationType& e2 );
     
	//! Compare TextJustificationType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eTextJustificationType& e1, const eTextJustificationType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTextJustificationType;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeUnset;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeLeft;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeBottomLeft;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeTopLeft;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeTopRight;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeTopCentre;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeCentre;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeBottomCentre;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeRight;
extern PLMXML_ANNOTATION60_API eTextJustificationType eTextJustificationTypeBottomRight;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorChangeLevel class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorChangeLevelMedium
	"medium"
  eAnn3DLocatorChangeLevelSoft
	"soft"
  eAnn3DLocatorChangeLevelHard
	"hard"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorChangeLevel : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorChangeLevel( const char* Type );
     
	//! Constructor
	eAnn3DLocatorChangeLevel( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorChangeLevel( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorChangeLevel( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorChangeLevel& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorChangeLevel& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorChangeLevel
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorChangeLevel& e1, const eAnn3DLocatorChangeLevel& e2 );
     
	//! Compare Ann3DLocatorChangeLevel
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorChangeLevel& e1, const eAnn3DLocatorChangeLevel& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorChangeLevel;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorChangeLevel eAnn3DLocatorChangeLevelUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorChangeLevel eAnn3DLocatorChangeLevelMedium;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorChangeLevel eAnn3DLocatorChangeLevelSoft;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorChangeLevel eAnn3DLocatorChangeLevelHard;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorCoordinatePlane class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorCoordinatePlaneXZ
	"XZ"
  eAnn3DLocatorCoordinatePlaneYZ
	"YZ"
  eAnn3DLocatorCoordinatePlaneXYZ
	"XYZ"
  eAnn3DLocatorCoordinatePlaneZ
	"Z"
  eAnn3DLocatorCoordinatePlaneXY
	"XY"
  eAnn3DLocatorCoordinatePlaneX
	"X"
  eAnn3DLocatorCoordinatePlaneY
	"Y"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorCoordinatePlane( const char* Type );
     
	//! Constructor
	eAnn3DLocatorCoordinatePlane( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorCoordinatePlane( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorCoordinatePlane( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorCoordinatePlane& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorCoordinatePlane& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorCoordinatePlane
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorCoordinatePlane& e1, const eAnn3DLocatorCoordinatePlane& e2 );
     
	//! Compare Ann3DLocatorCoordinatePlane
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorCoordinatePlane& e1, const eAnn3DLocatorCoordinatePlane& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorCoordinatePlane;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneXZ;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneYZ;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneXYZ;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneZ;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneXY;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneX;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorCoordinatePlane eAnn3DLocatorCoordinatePlaneY;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFieldWeldDirectionEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFieldWeldDirectionEnumUp
	"up"
  eAnn3DFieldWeldDirectionEnumDown
	"down"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFieldWeldDirectionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFieldWeldDirectionEnum( const char* Type );
     
	//! Constructor
	eAnn3DFieldWeldDirectionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFieldWeldDirectionEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFieldWeldDirectionEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFieldWeldDirectionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFieldWeldDirectionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFieldWeldDirectionEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFieldWeldDirectionEnum& e1, const eAnn3DFieldWeldDirectionEnum& e2 );
     
	//! Compare Ann3DFieldWeldDirectionEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFieldWeldDirectionEnum& e1, const eAnn3DFieldWeldDirectionEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFieldWeldDirectionEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFieldWeldDirectionEnum eAnn3DFieldWeldDirectionEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFieldWeldDirectionEnum eAnn3DFieldWeldDirectionEnumUp;
extern PLMXML_ANNOTATION60_API eAnn3DFieldWeldDirectionEnum eAnn3DFieldWeldDirectionEnumDown;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DSurfaceFinishLay class
/*!
Allowed Values:
\verbatim
  eAnn3DSurfaceFinishLayPerpendicular
	"perpendicular"
  eAnn3DSurfaceFinishLayUserDefined
	"userDefined"
  eAnn3DSurfaceFinishLayAngularBoth
	"angularBoth"
  eAnn3DSurfaceFinishLayParticulate
	"particulate"
  eAnn3DSurfaceFinishLayMultidirectional
	"multidirectional"
  eAnn3DSurfaceFinishLayParallel
	"parallel"
  eAnn3DSurfaceFinishLayRadial
	"radial"
  eAnn3DSurfaceFinishLayCircular
	"circular"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DSurfaceFinishLay( const char* Type );
     
	//! Constructor
	eAnn3DSurfaceFinishLay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DSurfaceFinishLay( );
     
	//! Destructor 
	virtual ~eAnn3DSurfaceFinishLay( );
     
	//! Assign from 'Type'
	const eAnn3DSurfaceFinishLay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DSurfaceFinishLay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DSurfaceFinishLay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DSurfaceFinishLay& e1, const eAnn3DSurfaceFinishLay& e2 );
     
	//! Compare Ann3DSurfaceFinishLay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DSurfaceFinishLay& e1, const eAnn3DSurfaceFinishLay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DSurfaceFinishLay;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayPerpendicular;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayUserDefined;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayAngularBoth;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayParticulate;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayMultidirectional;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayParallel;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayRadial;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishLay eAnn3DSurfaceFinishLayCircular;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFModifier class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFModifierLMC
	"LMC"
  eAnn3DFCFModifierRFS
	"RFS"
  eAnn3DFCFModifierMMC
	"MMC"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFModifier : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFModifier( const char* Type );
     
	//! Constructor
	eAnn3DFCFModifier( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFModifier( );
     
	//! Destructor 
	virtual ~eAnn3DFCFModifier( );
     
	//! Assign from 'Type'
	const eAnn3DFCFModifier& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFModifier& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFModifier
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFModifier& e1, const eAnn3DFCFModifier& e2 );
     
	//! Compare Ann3DFCFModifier
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFModifier& e1, const eAnn3DFCFModifier& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFModifier;
extern PLMXML_ANNOTATION60_API eAnn3DFCFModifier eAnn3DFCFModifierUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFModifier eAnn3DFCFModifierLMC;
extern PLMXML_ANNOTATION60_API eAnn3DFCFModifier eAnn3DFCFModifierRFS;
extern PLMXML_ANNOTATION60_API eAnn3DFCFModifier eAnn3DFCFModifierMMC;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DCircleCentreDisplay class
/*!
Allowed Values:
\verbatim
  eAnn3DCircleCentreDisplayFlatToScreen
	"flatToScreen"
  eAnn3DCircleCentreDisplayFlatToSurface
	"flatToSurface"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DCircleCentreDisplay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DCircleCentreDisplay( const char* Type );
     
	//! Constructor
	eAnn3DCircleCentreDisplay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DCircleCentreDisplay( );
     
	//! Destructor 
	virtual ~eAnn3DCircleCentreDisplay( );
     
	//! Assign from 'Type'
	const eAnn3DCircleCentreDisplay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DCircleCentreDisplay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DCircleCentreDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DCircleCentreDisplay& e1, const eAnn3DCircleCentreDisplay& e2 );
     
	//! Compare Ann3DCircleCentreDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DCircleCentreDisplay& e1, const eAnn3DCircleCentreDisplay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DCircleCentreDisplay;
extern PLMXML_ANNOTATION60_API eAnn3DCircleCentreDisplay eAnn3DCircleCentreDisplayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DCircleCentreDisplay eAnn3DCircleCentreDisplayFlatToScreen;
extern PLMXML_ANNOTATION60_API eAnn3DCircleCentreDisplay eAnn3DCircleCentreDisplayFlatToSurface;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorSymbol class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorSymbolFreeform
	"freeform"
  eAnn3DLocatorSymbolSurface
	"surface"
  eAnn3DLocatorSymbolRectangle
	"rectangle"
  eAnn3DLocatorSymbolSlot
	"slot"
  eAnn3DLocatorSymbolHole
	"hole"
  eAnn3DLocatorSymbolEdge
	"edge"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorSymbol( const char* Type );
     
	//! Constructor
	eAnn3DLocatorSymbol( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorSymbol( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorSymbol( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorSymbol& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorSymbol& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorSymbol& e1, const eAnn3DLocatorSymbol& e2 );
     
	//! Compare Ann3DLocatorSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorSymbol& e1, const eAnn3DLocatorSymbol& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolFreeform;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolSurface;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolRectangle;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolSlot;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolHole;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSymbol eAnn3DLocatorSymbolEdge;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionCausality class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionCausalityAssociated
	"associated"
  eAnn3DDimensionCausalityReference
	"reference"
  eAnn3DDimensionCausalityPmi
	"pmi"
  eAnn3DDimensionCausalityKey
	"key"
  eAnn3DDimensionCausalityFunctional
	"functional"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionCausality : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionCausality( const char* Type );
     
	//! Constructor
	eAnn3DDimensionCausality( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionCausality( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionCausality( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionCausality& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionCausality& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionCausality
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionCausality& e1, const eAnn3DDimensionCausality& e2 );
     
	//! Compare Ann3DDimensionCausality
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionCausality& e1, const eAnn3DDimensionCausality& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionCausality;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionCausality eAnn3DDimensionCausalityUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionCausality eAnn3DDimensionCausalityAssociated;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionCausality eAnn3DDimensionCausalityReference;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionCausality eAnn3DDimensionCausalityPmi;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionCausality eAnn3DDimensionCausalityKey;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionCausality eAnn3DDimensionCausalityFunctional;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DAttachment class
/*!
Allowed Values:
\verbatim
  eAnn3DAttachmentRadialDimension
	"radialDimension"
  eAnn3DAttachmentStackedLeft
	"stackedLeft"
  eAnn3DAttachmentNoLeader
	"noLeader"
  eAnn3DAttachmentStackedAbove
	"stackedAbove"
  eAnn3DAttachmentStackedRight
	"stackedRight"
  eAnn3DAttachmentOrdinateDimension
	"ordinateDimension"
  eAnn3DAttachmentLinearDimension
	"linearDimension"
  eAnn3DAttachmentOnGeometry
	"onGeometry"
  eAnn3DAttachmentStacked
	"stacked"
  eAnn3DAttachmentAngularDimension
	"angularDimension"
  eAnn3DAttachmentLeader
	"leader"
  eAnn3DAttachmentDiametralDimension
	"diametralDimension"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DAttachment : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DAttachment( const char* Type );
     
	//! Constructor
	eAnn3DAttachment( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DAttachment( );
     
	//! Destructor 
	virtual ~eAnn3DAttachment( );
     
	//! Assign from 'Type'
	const eAnn3DAttachment& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DAttachment& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DAttachment
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DAttachment& e1, const eAnn3DAttachment& e2 );
     
	//! Compare Ann3DAttachment
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DAttachment& e1, const eAnn3DAttachment& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DAttachment;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentUnset;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentRadialDimension;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentStackedLeft;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentNoLeader;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentStackedAbove;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentStackedRight;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentOrdinateDimension;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentLinearDimension;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentOnGeometry;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentStacked;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentAngularDimension;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentLeader;
extern PLMXML_ANNOTATION60_API eAnn3DAttachment eAnn3DAttachmentDiametralDimension;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldSupplementalSymbol class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldSupplementalSymbolBackingRemoveAfterWeld
	"backingRemoveAfterWeld"
  eAnn3DLineWeldSupplementalSymbolRemovableBackingStrip
	"removableBackingStrip"
  eAnn3DLineWeldSupplementalSymbolConcave
	"concave"
  eAnn3DLineWeldSupplementalSymbolMachiningGradedJunction
	"machiningGradedJunction"
  eAnn3DLineWeldSupplementalSymbolFlush
	"flush"
  eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRRComplete
	"surfaceFinishMRRComplete"
  eAnn3DLineWeldSupplementalSymbolConvex
	"convex"
  eAnn3DLineWeldSupplementalSymbolPermanentBackingStrip
	"permanentBackingStrip"
  eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRP
	"surfaceFinishMRP"
  eAnn3DLineWeldSupplementalSymbolSurfaceFinishBasicComplete
	"surfaceFinishBasicComplete"
  eAnn3DLineWeldSupplementalSymbolMeltThrough
	"meltThrough"
  eAnn3DLineWeldSupplementalSymbolFlushEskd
	"flushEskd"
  eAnn3DLineWeldSupplementalSymbolToesBlended
	"toesBlended"
  eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRPComplete
	"surfaceFinishMRPComplete"
  eAnn3DLineWeldSupplementalSymbolSpacer
	"spacer"
  eAnn3DLineWeldSupplementalSymbolConsumableInsert
	"consumableInsert"
  eAnn3DLineWeldSupplementalSymbolSurfaceFinishBasic
	"surfaceFinishBasic"
  eAnn3DLineWeldSupplementalSymbolIntermittent
	"intermittent"
  eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRR
	"surfaceFinishMRR"
  eAnn3DLineWeldSupplementalSymbolStud
	"stud"
  eAnn3DLineWeldSupplementalSymbolBacking
	"backing"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldSupplementalSymbol( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldSupplementalSymbol( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldSupplementalSymbol( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldSupplementalSymbol( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldSupplementalSymbol& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldSupplementalSymbol& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldSupplementalSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldSupplementalSymbol& e1, const eAnn3DLineWeldSupplementalSymbol& e2 );
     
	//! Compare Ann3DLineWeldSupplementalSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldSupplementalSymbol& e1, const eAnn3DLineWeldSupplementalSymbol& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldSupplementalSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolBackingRemoveAfterWeld;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolRemovableBackingStrip;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolConcave;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolMachiningGradedJunction;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolFlush;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRRComplete;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolConvex;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolPermanentBackingStrip;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRP;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSurfaceFinishBasicComplete;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolMeltThrough;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolFlushEskd;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolToesBlended;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRPComplete;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSpacer;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolConsumableInsert;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSurfaceFinishBasic;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolIntermittent;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolSurfaceFinishMRR;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolStud;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSupplementalSymbol eAnn3DLineWeldSupplementalSymbolBacking;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DOutlineEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DOutlineEnumTriangleRight
	"triangleRight"
  eAnn3DOutlineEnumFlagRight
	"flagRight"
  eAnn3DOutlineEnumOblongLeft
	"oblongLeft"
  eAnn3DOutlineEnumUnderline
	"underline"
  eAnn3DOutlineEnumFlagLeft
	"flagLeft"
  eAnn3DOutlineEnumSymmetricalSet
	"symmetricalSet"
  eAnn3DOutlineEnumNota
	"nota"
  eAnn3DOutlineEnumSymmetricalPart
	"symmetricalPart"
  eAnn3DOutlineEnumScoredCircle
	"scoredCircle"
  eAnn3DOutlineEnumFixedSupport
	"fixedSupport"
  eAnn3DOutlineEnumSet
	"set"
  eAnn3DOutlineEnumTriangle
	"triangle"
  eAnn3DOutlineEnumSquaredCircle
	"squaredCircle"
  eAnn3DOutlineEnumBox
	"box"
  eAnn3DOutlineEnumFlagBoth
	"flagBoth"
  eAnn3DOutlineEnumSticking
	"sticking"
  eAnn3DOutlineEnumDiamond
	"diamond"
  eAnn3DOutlineEnumParallelogram
	"parallelogram"
  eAnn3DOutlineEnumScoredRectangle
	"scoredRectangle"
  eAnn3DOutlineEnumOblong
	"oblong"
  eAnn3DOutlineEnumCircle
	"circle"
  eAnn3DOutlineEnumEllipse
	"ellipse"
  eAnn3DOutlineEnumTriangleLeft
	"triangleLeft"
  eAnn3DOutlineEnumSquare
	"square"
  eAnn3DOutlineEnumOblongRight
	"oblongRight"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DOutlineEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DOutlineEnum( const char* Type );
     
	//! Constructor
	eAnn3DOutlineEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DOutlineEnum( );
     
	//! Destructor 
	virtual ~eAnn3DOutlineEnum( );
     
	//! Assign from 'Type'
	const eAnn3DOutlineEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DOutlineEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DOutlineEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DOutlineEnum& e1, const eAnn3DOutlineEnum& e2 );
     
	//! Compare Ann3DOutlineEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DOutlineEnum& e1, const eAnn3DOutlineEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DOutlineEnum;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumTriangleRight;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumFlagRight;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumOblongLeft;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumUnderline;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumFlagLeft;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumSymmetricalSet;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumNota;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumSymmetricalPart;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumScoredCircle;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumFixedSupport;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumSet;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumTriangle;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumSquaredCircle;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumBox;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumFlagBoth;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumSticking;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumDiamond;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumParallelogram;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumScoredRectangle;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumOblong;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumCircle;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumEllipse;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumTriangleLeft;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumSquare;
extern PLMXML_ANNOTATION60_API eAnn3DOutlineEnum eAnn3DOutlineEnumOblongRight;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DParenthesisEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DParenthesisEnumRight
	"right"
  eAnn3DParenthesisEnumNone
	"none"
  eAnn3DParenthesisEnumLeft
	"left"
  eAnn3DParenthesisEnumBoth
	"both"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DParenthesisEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DParenthesisEnum( const char* Type );
     
	//! Constructor
	eAnn3DParenthesisEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DParenthesisEnum( );
     
	//! Destructor 
	virtual ~eAnn3DParenthesisEnum( );
     
	//! Assign from 'Type'
	const eAnn3DParenthesisEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DParenthesisEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DParenthesisEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DParenthesisEnum& e1, const eAnn3DParenthesisEnum& e2 );
     
	//! Compare Ann3DParenthesisEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DParenthesisEnum& e1, const eAnn3DParenthesisEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DParenthesisEnum;
extern PLMXML_ANNOTATION60_API eAnn3DParenthesisEnum eAnn3DParenthesisEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DParenthesisEnum eAnn3DParenthesisEnumRight;
extern PLMXML_ANNOTATION60_API eAnn3DParenthesisEnum eAnn3DParenthesisEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DParenthesisEnum eAnn3DParenthesisEnumLeft;
extern PLMXML_ANNOTATION60_API eAnn3DParenthesisEnum eAnn3DParenthesisEnumBoth;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldSymbol class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldSymbolSteepFlankedSingleBevel
	"steepFlankedSingleBevel"
  eAnn3DLineWeldSymbolEdge
	"edge"
  eAnn3DLineWeldSymbolJisFillet
	"jisFillet"
  eAnn3DLineWeldSymbolEskdSmooth
	"eskdSmooth"
  eAnn3DLineWeldSymbolSingleJGroove
	"singleJGroove"
  eAnn3DLineWeldSymbolJisSpotFlatElectrode
	"jisSpotFlatElectrode"
  eAnn3DLineWeldSymbolPlug
	"plug"
  eAnn3DLineWeldSymbolSeam
	"seam"
  eAnn3DLineWeldSymbolFillet
	"fillet"
  eAnn3DLineWeldSymbolSingleBevelGroove
	"singleBevelGroove"
  eAnn3DLineWeldSymbolStud
	"stud"
  eAnn3DLineWeldSymbolJisStaggeredFillet2
	"jisStaggeredFillet2"
  eAnn3DLineWeldSymbolSteepFlankedSingleV
	"steepFlankedSingleV"
  eAnn3DLineWeldSymbolSquareGroove
	"squareGroove"
  eAnn3DLineWeldSymbolKGroove
	"kGroove"
  eAnn3DLineWeldSymbolSingleV
	"singleV"
  eAnn3DLineWeldSymbolSingleU
	"singleU"
  eAnn3DLineWeldSymbolPermanentBackingStrip
	"permanentBackingStrip"
  eAnn3DLineWeldSymbolBacking
	"backing"
  eAnn3DLineWeldSymbolDoubleFlange
	"doubleFlange"
  eAnn3DLineWeldSymbolSquare
	"square"
  eAnn3DLineWeldSymbolSingleBevelBroadRootFace
	"singleBevelBroadRootFace"
  eAnn3DLineWeldSymbolEskdStaggerCheck
	"eskdStaggerCheck"
  eAnn3DLineWeldSymbolFoldJoint
	"foldJoint"
  eAnn3DLineWeldSymbolIntermittent
	"intermittent"
  eAnn3DLineWeldSymbolSpotProjected
	"spotProjected"
  eAnn3DLineWeldSymbolBackingPlate
	"backingPlate"
  eAnn3DLineWeldSymbolBead
	"bead"
  eAnn3DLineWeldSymbolPlugAndSlot
	"plugAndSlot"
  eAnn3DLineWeldSymbolRemovableBackingStrip
	"removableBackingStrip"
  eAnn3DLineWeldSymbolFlareSingleBevelGroove
	"flareSingleBevelGroove"
  eAnn3DLineWeldSymbolJisStaggeredFillet1
	"jisStaggeredFillet1"
  eAnn3DLineWeldSymbolEskdNumber
	"eskdNumber"
  eAnn3DLineWeldSymbolEskdNotAllAround
	"eskdNotAllAround"
  eAnn3DLineWeldSymbolKeyHole
	"keyHole"
  eAnn3DLineWeldSymbolSurface
	"surface"
  eAnn3DLineWeldSymbolJisSpot
	"jisSpot"
  eAnn3DLineWeldSymbolMeltThrough
	"meltThrough"
  eAnn3DLineWeldSymbolEdgeFlange
	"edgeFlange"
  eAnn3DLineWeldSymbolStake
	"stake"
  eAnn3DLineWeldSymbolSpot
	"spot"
  eAnn3DLineWeldSymbolIsoEdge
	"isoEdge"
  eAnn3DLineWeldSymbolSurfaceJoint
	"surfaceJoint"
  eAnn3DLineWeldSymbolSingleVGroove
	"singleVGroove"
  eAnn3DLineWeldSymbolEskdHeat
	"eskdHeat"
  eAnn3DLineWeldSymbolInclinedJoint
	"inclinedJoint"
  eAnn3DLineWeldSymbolSolder
	"solder"
  eAnn3DLineWeldSymbolEskdDiameter
	"eskdDiameter"
  eAnn3DLineWeldSymbolSingleFlange
	"singleFlange"
  eAnn3DLineWeldSymbolEskdStaggerChain
	"eskdStaggerChain"
  eAnn3DLineWeldSymbolOverlay
	"overlay"
  eAnn3DLineWeldSymbolJisSeam
	"jisSeam"
  eAnn3DLineWeldSymbolFlareSingleVGroove
	"flareSingleVGroove"
  eAnn3DLineWeldSymbolSingleUGroove
	"singleUGroove"
  eAnn3DLineWeldSymbolSingleBevel
	"singleBevel"
  eAnn3DLineWeldSymbolSingleVBroadRootFace
	"singleVBroadRootFace"
  eAnn3DLineWeldSymbolSingleJ
	"singleJ"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldSymbol( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldSymbol( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldSymbol( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldSymbol( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldSymbol& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldSymbol& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldSymbol& e1, const eAnn3DLineWeldSymbol& e2 );
     
	//! Compare Ann3DLineWeldSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldSymbol& e1, const eAnn3DLineWeldSymbol& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSteepFlankedSingleBevel;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEdge;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolJisFillet;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdSmooth;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleJGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolJisSpotFlatElectrode;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolPlug;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSeam;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolFillet;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleBevelGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolStud;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolJisStaggeredFillet2;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSteepFlankedSingleV;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSquareGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolKGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleV;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleU;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolPermanentBackingStrip;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolBacking;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolDoubleFlange;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSquare;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleBevelBroadRootFace;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdStaggerCheck;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolFoldJoint;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolIntermittent;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSpotProjected;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolBackingPlate;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolBead;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolPlugAndSlot;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolRemovableBackingStrip;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolFlareSingleBevelGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolJisStaggeredFillet1;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdNumber;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdNotAllAround;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolKeyHole;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSurface;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolJisSpot;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolMeltThrough;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEdgeFlange;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolStake;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSpot;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolIsoEdge;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSurfaceJoint;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleVGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdHeat;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolInclinedJoint;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSolder;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleFlange;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolEskdStaggerChain;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolOverlay;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolJisSeam;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolFlareSingleVGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleUGroove;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleBevel;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleVBroadRootFace;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldSymbol eAnn3DLineWeldSymbolSingleJ;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DSpotWeld class
/*!
Allowed Values:
\verbatim
  eAnn3DSpotWeldResistance
	"resistance"
  eAnn3DSpotWeldProjection
	"projection"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DSpotWeld : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DSpotWeld( const char* Type );
     
	//! Constructor
	eAnn3DSpotWeld( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DSpotWeld( );
     
	//! Destructor 
	virtual ~eAnn3DSpotWeld( );
     
	//! Assign from 'Type'
	const eAnn3DSpotWeld& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DSpotWeld& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DSpotWeld
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DSpotWeld& e1, const eAnn3DSpotWeld& e2 );
     
	//! Compare Ann3DSpotWeld
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DSpotWeld& e1, const eAnn3DSpotWeld& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DSpotWeld;
extern PLMXML_ANNOTATION60_API eAnn3DSpotWeld eAnn3DSpotWeldUnset;
extern PLMXML_ANNOTATION60_API eAnn3DSpotWeld eAnn3DSpotWeldResistance;
extern PLMXML_ANNOTATION60_API eAnn3DSpotWeld eAnn3DSpotWeldProjection;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLimitFitParenthesesEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLimitFitParenthesesEnumTolerance
	"tolerance"
  eAnn3DLimitFitParenthesesEnumNone
	"none"
  eAnn3DLimitFitParenthesesEnumValue
	"value"
  eAnn3DLimitFitParenthesesEnumValueLimitFit
	"valueLimitFit"
  eAnn3DLimitFitParenthesesEnumValueTolerance
	"valueTolerance"
  eAnn3DLimitFitParenthesesEnumLimitFit
	"limitFit"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLimitFitParenthesesEnum( const char* Type );
     
	//! Constructor
	eAnn3DLimitFitParenthesesEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLimitFitParenthesesEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLimitFitParenthesesEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLimitFitParenthesesEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLimitFitParenthesesEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLimitFitParenthesesEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLimitFitParenthesesEnum& e1, const eAnn3DLimitFitParenthesesEnum& e2 );
     
	//! Compare Ann3DLimitFitParenthesesEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLimitFitParenthesesEnum& e1, const eAnn3DLimitFitParenthesesEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLimitFitParenthesesEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumTolerance;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumValue;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumValueLimitFit;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumValueTolerance;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitParenthesesEnum eAnn3DLimitFitParenthesesEnumLimitFit;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFIndicatorSymbolEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFIndicatorSymbolEnumIncluding
	"including"
  eAnn3DFCFIndicatorSymbolEnumAngular
	"angular"
  eAnn3DFCFIndicatorSymbolEnumPerpendicular
	"perpendicular"
  eAnn3DFCFIndicatorSymbolEnumParallel
	"parallel"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorSymbolEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFIndicatorSymbolEnum( const char* Type );
     
	//! Constructor
	eAnn3DFCFIndicatorSymbolEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFIndicatorSymbolEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFCFIndicatorSymbolEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFCFIndicatorSymbolEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFIndicatorSymbolEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFIndicatorSymbolEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFIndicatorSymbolEnum& e1, const eAnn3DFCFIndicatorSymbolEnum& e2 );
     
	//! Compare Ann3DFCFIndicatorSymbolEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFIndicatorSymbolEnum& e1, const eAnn3DFCFIndicatorSymbolEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFIndicatorSymbolEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorSymbolEnum eAnn3DFCFIndicatorSymbolEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorSymbolEnum eAnn3DFCFIndicatorSymbolEnumIncluding;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorSymbolEnum eAnn3DFCFIndicatorSymbolEnumAngular;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorSymbolEnum eAnn3DFCFIndicatorSymbolEnumPerpendicular;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorSymbolEnum eAnn3DFCFIndicatorSymbolEnumParallel;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionStyle class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionStyleNarrow
	"narrow"
  eAnn3DDimensionStyleRadial
	"radial"
  eAnn3DDimensionStyleOrdinate
	"ordinate"
  eAnn3DDimensionStyleControlledRadial
	"controlledRadial"
  eAnn3DDimensionStyleSphericalDiametral
	"sphericalDiametral"
  eAnn3DDimensionStyleDiametral
	"diametral"
  eAnn3DDimensionStyleNone
	"none"
  eAnn3DDimensionStyleSphericalRadial
	"sphericalRadial"
  eAnn3DDimensionStyleLimits
	"limits"
  eAnn3DDimensionStyleLinearDiametral
	"linearDiametral"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionStyle : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionStyle( const char* Type );
     
	//! Constructor
	eAnn3DDimensionStyle( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionStyle( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionStyle( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionStyle& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionStyle& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionStyle
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionStyle& e1, const eAnn3DDimensionStyle& e2 );
     
	//! Compare Ann3DDimensionStyle
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionStyle& e1, const eAnn3DDimensionStyle& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionStyle;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleNarrow;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleRadial;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleOrdinate;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleControlledRadial;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleSphericalDiametral;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleDiametral;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleNone;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleSphericalRadial;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleLimits;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStyle eAnn3DDimensionStyleLinearDiametral;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DExtensionJoggingEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DExtensionJoggingEnumOn
	"on"
  eAnn3DExtensionJoggingEnumOff
	"off"
  eAnn3DExtensionJoggingEnumApplication
	"application"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DExtensionJoggingEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DExtensionJoggingEnum( const char* Type );
     
	//! Constructor
	eAnn3DExtensionJoggingEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DExtensionJoggingEnum( );
     
	//! Destructor 
	virtual ~eAnn3DExtensionJoggingEnum( );
     
	//! Assign from 'Type'
	const eAnn3DExtensionJoggingEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DExtensionJoggingEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DExtensionJoggingEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DExtensionJoggingEnum& e1, const eAnn3DExtensionJoggingEnum& e2 );
     
	//! Compare Ann3DExtensionJoggingEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DExtensionJoggingEnum& e1, const eAnn3DExtensionJoggingEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DExtensionJoggingEnum;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJoggingEnum eAnn3DExtensionJoggingEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJoggingEnum eAnn3DExtensionJoggingEnumOn;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJoggingEnum eAnn3DExtensionJoggingEnumOff;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJoggingEnum eAnn3DExtensionJoggingEnumApplication;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorHoleType class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorHoleTypeDL
	"DL"
  eAnn3DLocatorHoleTypeBL
	"BL"
  eAnn3DLocatorHoleTypeCh
	"ch"
  eAnn3DLocatorHoleTypeCH
	"CH"
  eAnn3DLocatorHoleTypeHK
	"HK"
  eAnn3DLocatorHoleTypeHLower
	"h"
  eAnn3DLocatorHoleTypeHUpper
	"H"
  eAnn3DLocatorHoleTypeHk
	"hk"
  eAnn3DLocatorHoleTypeAC
	"AC"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorHoleType( const char* Type );
     
	//! Constructor
	eAnn3DLocatorHoleType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorHoleType( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorHoleType( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorHoleType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorHoleType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorHoleType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorHoleType& e1, const eAnn3DLocatorHoleType& e2 );
     
	//! Compare Ann3DLocatorHoleType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorHoleType& e1, const eAnn3DLocatorHoleType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorHoleType;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeDL;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeBL;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeCh;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeCH;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeHK;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeHLower;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeHUpper;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeHk;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorHoleType eAnn3DLocatorHoleTypeAC;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionZeroToleranceDisplay class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionZeroToleranceDisplaySuppressTrailingZero
	"suppressTrailingZero"
  eAnn3DDimensionZeroToleranceDisplayOmit
	"omit"
  eAnn3DDimensionZeroToleranceDisplayBlank
	"blank"
  eAnn3DDimensionZeroToleranceDisplayDisplayZero
	"displayZero"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionZeroToleranceDisplay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionZeroToleranceDisplay( const char* Type );
     
	//! Constructor
	eAnn3DDimensionZeroToleranceDisplay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionZeroToleranceDisplay( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionZeroToleranceDisplay( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionZeroToleranceDisplay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionZeroToleranceDisplay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionZeroToleranceDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionZeroToleranceDisplay& e1, const eAnn3DDimensionZeroToleranceDisplay& e2 );
     
	//! Compare Ann3DDimensionZeroToleranceDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionZeroToleranceDisplay& e1, const eAnn3DDimensionZeroToleranceDisplay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionZeroToleranceDisplay;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionZeroToleranceDisplay eAnn3DDimensionZeroToleranceDisplayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionZeroToleranceDisplay eAnn3DDimensionZeroToleranceDisplaySuppressTrailingZero;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionZeroToleranceDisplay eAnn3DDimensionZeroToleranceDisplayOmit;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionZeroToleranceDisplay eAnn3DDimensionZeroToleranceDisplayBlank;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionZeroToleranceDisplay eAnn3DDimensionZeroToleranceDisplayDisplayZero;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionParameterEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionParameterEnumAngle
	"angle"
  eAnn3DDimensionParameterEnumCounterboreDiameter
	"counterboreDiameter"
  eAnn3DDimensionParameterEnumInternalExternalSymbol
	"internalExternalSymbol"
  eAnn3DDimensionParameterEnumShaftSize
	"shaftSize"
  eAnn3DDimensionParameterEnumMinorDiameter
	"minorDiameter"
  eAnn3DDimensionParameterEnumPitch
	"pitch"
  eAnn3DDimensionParameterEnumEndChamferAngle
	"endChamferAngle"
  eAnn3DDimensionParameterEnumSymbolicThreadCallout
	"symbolicThreadCallout"
  eAnn3DDimensionParameterEnumCountersinkDiameter
	"countersinkDiameter"
  eAnn3DDimensionParameterEnumScrewSize
	"screwSize"
  eAnn3DDimensionParameterEnumScrewType
	"screwType"
  eAnn3DDimensionParameterEnumDiameter
	"diameter"
  eAnn3DDimensionParameterEnumEndChamferDiameter
	"endChamferDiameter"
  eAnn3DDimensionParameterEnumTapDrillDiameter
	"tapDrillDiameter"
  eAnn3DDimensionParameterEnumThreadSize
	"threadSize"
  eAnn3DDimensionParameterEnumStartChamferDiameter
	"startChamferDiameter"
  eAnn3DDimensionParameterEnumThreadPitch
	"threadPitch"
  eAnn3DDimensionParameterEnumMajorDiameter
	"majorDiameter"
  eAnn3DDimensionParameterEnumCountersinkAngle
	"countersinkAngle"
  eAnn3DDimensionParameterEnumForm
	"form"
  eAnn3DDimensionParameterEnumCounterboreDepth
	"counterboreDepth"
  eAnn3DDimensionParameterEnumThreadDepth
	"threadDepth"
  eAnn3DDimensionParameterEnumFit
	"fit"
  eAnn3DDimensionParameterEnumTaperAngle
	"taperAngle"
  eAnn3DDimensionParameterEnumStartChamferAngle
	"startChamferAngle"
  eAnn3DDimensionParameterEnumTapDrillSize
	"tapDrillSize"
  eAnn3DDimensionParameterEnumDepth
	"depth"
  eAnn3DDimensionParameterEnumLength
	"length"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionParameterEnum( const char* Type );
     
	//! Constructor
	eAnn3DDimensionParameterEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionParameterEnum( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionParameterEnum( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionParameterEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionParameterEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionParameterEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionParameterEnum& e1, const eAnn3DDimensionParameterEnum& e2 );
     
	//! Compare Ann3DDimensionParameterEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionParameterEnum& e1, const eAnn3DDimensionParameterEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionParameterEnum;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumAngle;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumCounterboreDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumInternalExternalSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumShaftSize;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumMinorDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumPitch;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumEndChamferAngle;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumSymbolicThreadCallout;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumCountersinkDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumScrewSize;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumScrewType;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumEndChamferDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumTapDrillDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumThreadSize;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumStartChamferDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumThreadPitch;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumMajorDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumCountersinkAngle;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumForm;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumCounterboreDepth;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumThreadDepth;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumFit;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumTaperAngle;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumStartChamferAngle;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumTapDrillSize;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumDepth;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionParameterEnum eAnn3DDimensionParameterEnumLength;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFIndicatorEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFIndicatorEnumCollectionPlane
	"collectionPlane"
  eAnn3DFCFIndicatorEnumOrientationPlane
	"orientationPlane"
  eAnn3DFCFIndicatorEnumDirectionFeature
	"directionFeature"
  eAnn3DFCFIndicatorEnumIntersectionPlane
	"intersectionPlane"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFIndicatorEnum( const char* Type );
     
	//! Constructor
	eAnn3DFCFIndicatorEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFIndicatorEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFCFIndicatorEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFCFIndicatorEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFIndicatorEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFIndicatorEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFIndicatorEnum& e1, const eAnn3DFCFIndicatorEnum& e2 );
     
	//! Compare Ann3DFCFIndicatorEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFIndicatorEnum& e1, const eAnn3DFCFIndicatorEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFIndicatorEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorEnum eAnn3DFCFIndicatorEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorEnum eAnn3DFCFIndicatorEnumCollectionPlane;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorEnum eAnn3DFCFIndicatorEnumOrientationPlane;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorEnum eAnn3DFCFIndicatorEnumDirectionFeature;
extern PLMXML_ANNOTATION60_API eAnn3DFCFIndicatorEnum eAnn3DFCFIndicatorEnumIntersectionPlane;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorSubtype class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorSubtypeAccessClearanceHole
	"accessClearanceHole"
  eAnn3DLocatorSubtypeAuxiliaryRest
	"auxiliaryRest"
  eAnn3DLocatorSubtypeManufacturingAndAssembly
	"manufacturingAndAssembly"
  eAnn3DLocatorSubtypePermanentlyTransferred
	"permanentlyTransferred"
  eAnn3DLocatorSubtypeDiesMolds
	"diesMolds"
  eAnn3DLocatorSubtypeCoordination
	"coordination"
  eAnn3DLocatorSubtypeTemporaryTransferred
	"temporaryTransferred"
  eAnn3DLocatorSubtypeDetached
	"detached"
  eAnn3DLocatorSubtypeJClamps
	"jClamps"
  eAnn3DLocatorSubtypeFixing
	"fixing"
  eAnn3DLocatorSubtypeCorrectable
	"correctable"
  eAnn3DLocatorSubtypeMechanicallyFastened
	"mechanicallyFastened"
  eAnn3DLocatorSubtypeScribedCoordinationLine
	"scribedCoordinationLine"
  eAnn3DLocatorSubtypeBlank
	"blank"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorSubtype( const char* Type );
     
	//! Constructor
	eAnn3DLocatorSubtype( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorSubtype( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorSubtype( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorSubtype& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorSubtype& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorSubtype
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorSubtype& e1, const eAnn3DLocatorSubtype& e2 );
     
	//! Compare Ann3DLocatorSubtype
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorSubtype& e1, const eAnn3DLocatorSubtype& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorSubtype;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeAccessClearanceHole;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeAuxiliaryRest;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeManufacturingAndAssembly;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypePermanentlyTransferred;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeDiesMolds;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeCoordination;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeTemporaryTransferred;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeDetached;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeJClamps;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeFixing;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeCorrectable;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeMechanicallyFastened;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeScribedCoordinationLine;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSubtype eAnn3DLocatorSubtypeBlank;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorSurfaceType class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorSurfaceTypeCK
	"CK"
  eAnn3DLocatorSurfaceTypeSK
	"SK"
  eAnn3DLocatorSurfaceTypeSLower
	"s"
  eAnn3DLocatorSurfaceTypeSUpper
	"S"
  eAnn3DLocatorSurfaceTypeSL
	"SL"
  eAnn3DLocatorSurfaceTypeSk
	"sk"
  eAnn3DLocatorSurfaceTypeJ
	"J"
  eAnn3DLocatorSurfaceTypeCS
	"CS"
  eAnn3DLocatorSurfaceTypeCO
	"CO"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorSurfaceType( const char* Type );
     
	//! Constructor
	eAnn3DLocatorSurfaceType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorSurfaceType( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorSurfaceType( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorSurfaceType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorSurfaceType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorSurfaceType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorSurfaceType& e1, const eAnn3DLocatorSurfaceType& e2 );
     
	//! Compare Ann3DLocatorSurfaceType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorSurfaceType& e1, const eAnn3DLocatorSurfaceType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorSurfaceType;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeCK;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeSK;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeSLower;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeSUpper;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeSL;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeSk;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeJ;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeCS;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorSurfaceType eAnn3DLocatorSurfaceTypeCO;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DReferenceContentEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DReferenceContentEnumTolerance
	"tolerance"
  eAnn3DReferenceContentEnumPrefix
	"prefix"
  eAnn3DReferenceContentEnumValue
	"value"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DReferenceContentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DReferenceContentEnum( const char* Type );
     
	//! Constructor
	eAnn3DReferenceContentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DReferenceContentEnum( );
     
	//! Destructor 
	virtual ~eAnn3DReferenceContentEnum( );
     
	//! Assign from 'Type'
	const eAnn3DReferenceContentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DReferenceContentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DReferenceContentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DReferenceContentEnum& e1, const eAnn3DReferenceContentEnum& e2 );
     
	//! Compare Ann3DReferenceContentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DReferenceContentEnum& e1, const eAnn3DReferenceContentEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DReferenceContentEnum;
extern PLMXML_ANNOTATION60_API eAnn3DReferenceContentEnum eAnn3DReferenceContentEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DReferenceContentEnum eAnn3DReferenceContentEnumTolerance;
extern PLMXML_ANNOTATION60_API eAnn3DReferenceContentEnum eAnn3DReferenceContentEnumPrefix;
extern PLMXML_ANNOTATION60_API eAnn3DReferenceContentEnum eAnn3DReferenceContentEnumValue;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DGrooveGapTextStyleEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DGrooveGapTextStyleEnumInside
	"inside"
  eAnn3DGrooveGapTextStyleEnumArrow
	"arrow"
  eAnn3DGrooveGapTextStyleEnumOutside
	"outside"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DGrooveGapTextStyleEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DGrooveGapTextStyleEnum( const char* Type );
     
	//! Constructor
	eAnn3DGrooveGapTextStyleEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DGrooveGapTextStyleEnum( );
     
	//! Destructor 
	virtual ~eAnn3DGrooveGapTextStyleEnum( );
     
	//! Assign from 'Type'
	const eAnn3DGrooveGapTextStyleEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DGrooveGapTextStyleEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DGrooveGapTextStyleEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DGrooveGapTextStyleEnum& e1, const eAnn3DGrooveGapTextStyleEnum& e2 );
     
	//! Compare Ann3DGrooveGapTextStyleEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DGrooveGapTextStyleEnum& e1, const eAnn3DGrooveGapTextStyleEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DGrooveGapTextStyleEnum;
extern PLMXML_ANNOTATION60_API eAnn3DGrooveGapTextStyleEnum eAnn3DGrooveGapTextStyleEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DGrooveGapTextStyleEnum eAnn3DGrooveGapTextStyleEnumInside;
extern PLMXML_ANNOTATION60_API eAnn3DGrooveGapTextStyleEnum eAnn3DGrooveGapTextStyleEnumArrow;
extern PLMXML_ANNOTATION60_API eAnn3DGrooveGapTextStyleEnum eAnn3DGrooveGapTextStyleEnumOutside;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DCuttingPlaneSymbolStandardEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DCuttingPlaneSymbolStandardEnumISO
	"ISO"
  eAnn3DCuttingPlaneSymbolStandardEnumASME
	"ASME Y14.41M"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DCuttingPlaneSymbolStandardEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DCuttingPlaneSymbolStandardEnum( const char* Type );
     
	//! Constructor
	eAnn3DCuttingPlaneSymbolStandardEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DCuttingPlaneSymbolStandardEnum( );
     
	//! Destructor 
	virtual ~eAnn3DCuttingPlaneSymbolStandardEnum( );
     
	//! Assign from 'Type'
	const eAnn3DCuttingPlaneSymbolStandardEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DCuttingPlaneSymbolStandardEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DCuttingPlaneSymbolStandardEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DCuttingPlaneSymbolStandardEnum& e1, const eAnn3DCuttingPlaneSymbolStandardEnum& e2 );
     
	//! Compare Ann3DCuttingPlaneSymbolStandardEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DCuttingPlaneSymbolStandardEnum& e1, const eAnn3DCuttingPlaneSymbolStandardEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DCuttingPlaneSymbolStandardEnum;
extern PLMXML_ANNOTATION60_API eAnn3DCuttingPlaneSymbolStandardEnum eAnn3DCuttingPlaneSymbolStandardEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DCuttingPlaneSymbolStandardEnum eAnn3DCuttingPlaneSymbolStandardEnumISO;
extern PLMXML_ANNOTATION60_API eAnn3DCuttingPlaneSymbolStandardEnum eAnn3DCuttingPlaneSymbolStandardEnumASME;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDatumTarget class
/*!
Allowed Values:
\verbatim
  eAnn3DDatumTargetAnnular
	"annular"
  eAnn3DDatumTargetSpherical
	"spherical"
  eAnn3DDatumTargetArea
	"area"
  eAnn3DDatumTargetLine
	"line"
  eAnn3DDatumTargetRectangular
	"rectangular"
  eAnn3DDatumTargetPoint
	"point"
  eAnn3DDatumTargetCylindrical
	"cylindrical"
  eAnn3DDatumTargetArbitrary
	"arbitrary"
  eAnn3DDatumTargetCircular
	"circular"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDatumTarget : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDatumTarget( const char* Type );
     
	//! Constructor
	eAnn3DDatumTarget( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDatumTarget( );
     
	//! Destructor 
	virtual ~eAnn3DDatumTarget( );
     
	//! Assign from 'Type'
	const eAnn3DDatumTarget& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDatumTarget& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDatumTarget
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDatumTarget& e1, const eAnn3DDatumTarget& e2 );
     
	//! Compare Ann3DDatumTarget
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDatumTarget& e1, const eAnn3DDatumTarget& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDatumTarget;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetAnnular;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetSpherical;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetArea;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetLine;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetRectangular;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetPoint;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetCylindrical;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetArbitrary;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTarget eAnn3DDatumTargetCircular;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLimitFitOrderEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLimitFitOrderEnumToleranceValueLimitFit
	"toleranceValueLimitFit"
  eAnn3DLimitFitOrderEnumValueToleranceLimitFit
	"valueToleranceLimitFit"
  eAnn3DLimitFitOrderEnumValueLimitFitTolerance
	"valueLimitFitTolerance"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLimitFitOrderEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLimitFitOrderEnum( const char* Type );
     
	//! Constructor
	eAnn3DLimitFitOrderEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLimitFitOrderEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLimitFitOrderEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLimitFitOrderEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLimitFitOrderEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLimitFitOrderEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLimitFitOrderEnum& e1, const eAnn3DLimitFitOrderEnum& e2 );
     
	//! Compare Ann3DLimitFitOrderEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLimitFitOrderEnum& e1, const eAnn3DLimitFitOrderEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLimitFitOrderEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitOrderEnum eAnn3DLimitFitOrderEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitOrderEnum eAnn3DLimitFitOrderEnumToleranceValueLimitFit;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitOrderEnum eAnn3DLimitFitOrderEnumValueToleranceLimitFit;
extern PLMXML_ANNOTATION60_API eAnn3DLimitFitOrderEnum eAnn3DLimitFitOrderEnumValueLimitFitTolerance;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionTextPosition class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionTextPositionAfter
	"after"
  eAnn3DDimensionTextPositionAbove
	"above"
  eAnn3DDimensionTextPositionBelow
	"below"
  eAnn3DDimensionTextPositionBefore
	"before"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionTextPosition : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionTextPosition( const char* Type );
     
	//! Constructor
	eAnn3DDimensionTextPosition( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionTextPosition( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionTextPosition( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionTextPosition& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionTextPosition& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionTextPosition
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionTextPosition& e1, const eAnn3DDimensionTextPosition& e2 );
     
	//! Compare Ann3DDimensionTextPosition
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionTextPosition& e1, const eAnn3DDimensionTextPosition& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionTextPosition;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTextPosition eAnn3DDimensionTextPositionUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTextPosition eAnn3DDimensionTextPositionAfter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTextPosition eAnn3DDimensionTextPositionAbove;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTextPosition eAnn3DDimensionTextPositionBelow;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTextPosition eAnn3DDimensionTextPositionBefore;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextSymbol class
/*!
Allowed Values:
\verbatim
  eAnn3DTextSymbolIndependency
	"independency"
  eAnn3DTextSymbolFlatness
	"flatness"
  eAnn3DTextSymbolFitFunction
	"fitFunction"
  eAnn3DTextSymbolEnvelope
	"envelope"
  eAnn3DTextSymbolDatumTranslation
	"datumTranslation"
  eAnn3DTextSymbolBetween
	"between"
  eAnn3DTextSymbolSPhi
	"sPhi"
  eAnn3DTextSymbolSlope
	"slope"
  eAnn3DTextSymbolApproximateDimension
	"approximateDimension"
  eAnn3DTextSymbolMicro
	"micro"
  eAnn3DTextSymbolContinuousFeature
	"continuousFeature"
  eAnn3DTextSymbolOrientationConstraint
	"orientationConstraint"
  eAnn3DTextSymbolLessThanOrEqual
	"lessThanOrEqual"
  eAnn3DTextSymbolSpotFace
	"spotFace"
  eAnn3DTextSymbolEskdCross
	"eskdCross"
  eAnn3DTextSymbolConcentricity
	"concentricity"
  eAnn3DTextSymbolDegrees
	"degrees"
  eAnn3DTextSymbolThreadPrefix
	"threadPrefix"
  eAnn3DTextSymbolRadius
	"radius"
  eAnn3DTextSymbolSquare
	"square"
  eAnn3DTextSymbolRightPitch
	"rightPitch"
  eAnn3DTextSymbolProjectedTolerance
	"projectedTolerance"
  eAnn3DTextSymbolRightTaper
	"rightTaper"
  eAnn3DTextSymbolCountersink
	"countersink"
  eAnn3DTextSymbolLeftPitch
	"leftPitch"
  eAnn3DTextSymbolCircularRunout
	"circularRunout"
  eAnn3DTextSymbolPosition
	"position"
  eAnn3DTextSymbolPartingline
	"partingline"
  eAnn3DTextSymbolTotalRunout
	"totalRunout"
  eAnn3DTextSymbolQuantity
	"quantity"
  eAnn3DTextSymbolPhi
	"phi"
  eAnn3DTextSymbolEskdPerpendicular
	"eskdPerpendicular"
  eAnn3DTextSymbolSafetyCompliance
	"safetyCompliance"
  eAnn3DTextSymbolTangentPlane
	"tangentPlane"
  eAnn3DTextSymbolTriangle
	"triangle"
  eAnn3DTextSymbolAxisIntersection
	"axisIntersection"
  eAnn3DTextSymbolSymmetry
	"symmetry"
  eAnn3DTextSymbolCircularity
	"circularity"
  eAnn3DTextSymbolPerpendicularity
	"perpendicularity"
  eAnn3DTextSymbolCircleU
	"circleU"
  eAnn3DTextSymbolEskdParallel
	"eskdParallel"
  eAnn3DTextSymbolConicalTaper
	"conicalTaper"
  eAnn3DTextSymbolMmc
	"mmc"
  eAnn3DTextSymbolSphere
	"sphere"
  eAnn3DTextSymbolRfs
	"rfs"
  eAnn3DTextSymbolLeftParenthesis
	"leftParenthesis"
  eAnn3DTextSymbolLeftTaper
	"leftTaper"
  eAnn3DTextSymbolCounterbore
	"counterbore"
  eAnn3DTextSymbolCentreline
	"centreline"
  eAnn3DTextSymbolCylindricity
	"cylindricity"
  eAnn3DTextSymbolAngularity
	"angularity"
  eAnn3DTextSymbolParallelism
	"parallelism"
  eAnn3DTextSymbolProfileOfALine
	"profileOfALine"
  eAnn3DTextSymbolStatistical
	"statistical"
  eAnn3DTextSymbolStraightness
	"straightness"
  eAnn3DTextSymbolRightParenthesis
	"rightParenthesis"
  eAnn3DTextSymbolGreaterThanOrEqual
	"greaterThanOrEqual"
  eAnn3DTextSymbolLmc
	"lmc"
  eAnn3DTextSymbolFreeState
	"freeState"
  eAnn3DTextSymbolDepth
	"depth"
  eAnn3DTextSymbolOhm
	"ohm"
  eAnn3DTextSymbolPlusMinus
	"plus-minus"
  eAnn3DTextSymbolProfileOfASurface
	"profileOfASurface"
  eAnn3DTextSymbolArcLength
	"arcLength"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextSymbol : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextSymbol( const char* Type );
     
	//! Constructor
	eAnn3DTextSymbol( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextSymbol( );
     
	//! Destructor 
	virtual ~eAnn3DTextSymbol( );
     
	//! Assign from 'Type'
	const eAnn3DTextSymbol& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextSymbol& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextSymbol& e1, const eAnn3DTextSymbol& e2 );
     
	//! Compare Ann3DTextSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextSymbol& e1, const eAnn3DTextSymbol& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolIndependency;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolFlatness;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolFitFunction;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolEnvelope;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolDatumTranslation;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolBetween;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSPhi;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSlope;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolApproximateDimension;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolMicro;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolContinuousFeature;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolOrientationConstraint;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolLessThanOrEqual;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSpotFace;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolEskdCross;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolConcentricity;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolDegrees;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolThreadPrefix;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolRadius;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSquare;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolRightPitch;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolProjectedTolerance;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolRightTaper;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCountersink;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolLeftPitch;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCircularRunout;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolPosition;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolPartingline;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolTotalRunout;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolQuantity;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolPhi;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolEskdPerpendicular;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSafetyCompliance;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolTangentPlane;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolTriangle;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolAxisIntersection;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSymmetry;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCircularity;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolPerpendicularity;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCircleU;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolEskdParallel;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolConicalTaper;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolMmc;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolSphere;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolRfs;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolLeftParenthesis;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolLeftTaper;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCounterbore;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCentreline;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolCylindricity;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolAngularity;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolParallelism;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolProfileOfALine;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolStatistical;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolStraightness;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolRightParenthesis;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolGreaterThanOrEqual;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolLmc;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolFreeState;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolDepth;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolOhm;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolPlusMinus;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolProfileOfASurface;
extern PLMXML_ANNOTATION60_API eAnn3DTextSymbol eAnn3DTextSymbolArcLength;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DCrosshatchPattern class
/*!
Allowed Values:
\verbatim
  eAnn3DCrosshatchPatternRefractory
	"refractory"
  eAnn3DCrosshatchPatternSolid
	"solid"
  eAnn3DCrosshatchPatternRubber
	"rubber"
  eAnn3DCrosshatchPatternBrass
	"brass"
  eAnn3DCrosshatchPatternLead
	"lead"
  eAnn3DCrosshatchPatternElectricalWinding
	"electricalWinding"
  eAnn3DCrosshatchPatternIron
	"iron"
  eAnn3DCrosshatchPatternSteel
	"steel"
  eAnn3DCrosshatchPatternUser
	"user"
  eAnn3DCrosshatchPatternThermalInsulation
	"thermalInsulation"
  eAnn3DCrosshatchPatternGlass
	"glass"
  eAnn3DCrosshatchPatternAluminum
	"aluminum"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DCrosshatchPattern( const char* Type );
     
	//! Constructor
	eAnn3DCrosshatchPattern( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DCrosshatchPattern( );
     
	//! Destructor 
	virtual ~eAnn3DCrosshatchPattern( );
     
	//! Assign from 'Type'
	const eAnn3DCrosshatchPattern& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DCrosshatchPattern& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DCrosshatchPattern
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DCrosshatchPattern& e1, const eAnn3DCrosshatchPattern& e2 );
     
	//! Compare Ann3DCrosshatchPattern
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DCrosshatchPattern& e1, const eAnn3DCrosshatchPattern& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DCrosshatchPattern;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternUnset;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternRefractory;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternSolid;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternRubber;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternBrass;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternLead;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternElectricalWinding;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternIron;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternSteel;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternUser;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternThermalInsulation;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternGlass;
extern PLMXML_ANNOTATION60_API eAnn3DCrosshatchPattern eAnn3DCrosshatchPatternAluminum;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionToleranceClassISOEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionToleranceClassISOEnumMedium
	"medium"
  eAnn3DDimensionToleranceClassISOEnumFine
	"fine"
  eAnn3DDimensionToleranceClassISOEnumCoarse
	"coarse"
  eAnn3DDimensionToleranceClassISOEnumVeryCoarse
	"veryCoarse"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionToleranceClassISOEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionToleranceClassISOEnum( const char* Type );
     
	//! Constructor
	eAnn3DDimensionToleranceClassISOEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionToleranceClassISOEnum( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionToleranceClassISOEnum( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionToleranceClassISOEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionToleranceClassISOEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionToleranceClassISOEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionToleranceClassISOEnum& e1, const eAnn3DDimensionToleranceClassISOEnum& e2 );
     
	//! Compare Ann3DDimensionToleranceClassISOEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionToleranceClassISOEnum& e1, const eAnn3DDimensionToleranceClassISOEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionToleranceClassISOEnum;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionToleranceClassISOEnum eAnn3DDimensionToleranceClassISOEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionToleranceClassISOEnum eAnn3DDimensionToleranceClassISOEnumMedium;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionToleranceClassISOEnum eAnn3DDimensionToleranceClassISOEnumFine;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionToleranceClassISOEnum eAnn3DDimensionToleranceClassISOEnumCoarse;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionToleranceClassISOEnum eAnn3DDimensionToleranceClassISOEnumVeryCoarse;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFractionSizeEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFractionSizeEnumTwoThirds
	"twoThirds"
  eAnn3DFractionSizeEnumThreeQuarters
	"threeQuarters"
  eAnn3DFractionSizeEnumFull
	"full"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFractionSizeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFractionSizeEnum( const char* Type );
     
	//! Constructor
	eAnn3DFractionSizeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFractionSizeEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFractionSizeEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFractionSizeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFractionSizeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFractionSizeEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFractionSizeEnum& e1, const eAnn3DFractionSizeEnum& e2 );
     
	//! Compare Ann3DFractionSizeEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFractionSizeEnum& e1, const eAnn3DFractionSizeEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFractionSizeEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFractionSizeEnum eAnn3DFractionSizeEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFractionSizeEnum eAnn3DFractionSizeEnumTwoThirds;
extern PLMXML_ANNOTATION60_API eAnn3DFractionSizeEnum eAnn3DFractionSizeEnumThreeQuarters;
extern PLMXML_ANNOTATION60_API eAnn3DFractionSizeEnum eAnn3DFractionSizeEnumFull;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldReferenceSignEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldReferenceSignEnumBox
	"box"
  eAnn3DLineWeldReferenceSignEnumFork
	"fork"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldReferenceSignEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldReferenceSignEnum( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldReferenceSignEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldReferenceSignEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldReferenceSignEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldReferenceSignEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldReferenceSignEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldReferenceSignEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldReferenceSignEnum& e1, const eAnn3DLineWeldReferenceSignEnum& e2 );
     
	//! Compare Ann3DLineWeldReferenceSignEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldReferenceSignEnum& e1, const eAnn3DLineWeldReferenceSignEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldReferenceSignEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldReferenceSignEnum eAnn3DLineWeldReferenceSignEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldReferenceSignEnum eAnn3DLineWeldReferenceSignEnumBox;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldReferenceSignEnum eAnn3DLineWeldReferenceSignEnumFork;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DMeasurementPointDisplay class
/*!
Allowed Values:
\verbatim
  eAnn3DMeasurementPointDisplayFlatToScreen
	"flatToScreen"
  eAnn3DMeasurementPointDisplayFlatToSurface
	"flatToSurface"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DMeasurementPointDisplay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DMeasurementPointDisplay( const char* Type );
     
	//! Constructor
	eAnn3DMeasurementPointDisplay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DMeasurementPointDisplay( );
     
	//! Destructor 
	virtual ~eAnn3DMeasurementPointDisplay( );
     
	//! Assign from 'Type'
	const eAnn3DMeasurementPointDisplay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DMeasurementPointDisplay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DMeasurementPointDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DMeasurementPointDisplay& e1, const eAnn3DMeasurementPointDisplay& e2 );
     
	//! Compare Ann3DMeasurementPointDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DMeasurementPointDisplay& e1, const eAnn3DMeasurementPointDisplay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DMeasurementPointDisplay;
extern PLMXML_ANNOTATION60_API eAnn3DMeasurementPointDisplay eAnn3DMeasurementPointDisplayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DMeasurementPointDisplay eAnn3DMeasurementPointDisplayFlatToScreen;
extern PLMXML_ANNOTATION60_API eAnn3DMeasurementPointDisplay eAnn3DMeasurementPointDisplayFlatToSurface;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DInspectionDisplayEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DInspectionDisplayEnumAfter
	"after"
  eAnn3DInspectionDisplayEnumAll
	"all"
  eAnn3DInspectionDisplayEnumNone
	"none"
  eAnn3DInspectionDisplayEnumBeforeAfter
	"beforeAfter"
  eAnn3DInspectionDisplayEnumBefore
	"before"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DInspectionDisplayEnum( const char* Type );
     
	//! Constructor
	eAnn3DInspectionDisplayEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DInspectionDisplayEnum( );
     
	//! Destructor 
	virtual ~eAnn3DInspectionDisplayEnum( );
     
	//! Assign from 'Type'
	const eAnn3DInspectionDisplayEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DInspectionDisplayEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DInspectionDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DInspectionDisplayEnum& e1, const eAnn3DInspectionDisplayEnum& e2 );
     
	//! Compare Ann3DInspectionDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DInspectionDisplayEnum& e1, const eAnn3DInspectionDisplayEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DInspectionDisplayEnum;
extern PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum eAnn3DInspectionDisplayEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum eAnn3DInspectionDisplayEnumAfter;
extern PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum eAnn3DInspectionDisplayEnumAll;
extern PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum eAnn3DInspectionDisplayEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum eAnn3DInspectionDisplayEnumBeforeAfter;
extern PLMXML_ANNOTATION60_API eAnn3DInspectionDisplayEnum eAnn3DInspectionDisplayEnumBefore;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimReferenceDisplay class
/*!
Allowed Values:
\verbatim
  eAnn3DDimReferenceDisplayReference
	"reference"
  eAnn3DDimReferenceDisplayMatched
	"matched"
  eAnn3DDimReferenceDisplayParenthesis
	"parenthesis"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimReferenceDisplay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimReferenceDisplay( const char* Type );
     
	//! Constructor
	eAnn3DDimReferenceDisplay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimReferenceDisplay( );
     
	//! Destructor 
	virtual ~eAnn3DDimReferenceDisplay( );
     
	//! Assign from 'Type'
	const eAnn3DDimReferenceDisplay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimReferenceDisplay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimReferenceDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimReferenceDisplay& e1, const eAnn3DDimReferenceDisplay& e2 );
     
	//! Compare Ann3DDimReferenceDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimReferenceDisplay& e1, const eAnn3DDimReferenceDisplay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimReferenceDisplay;
extern PLMXML_ANNOTATION60_API eAnn3DDimReferenceDisplay eAnn3DDimReferenceDisplayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimReferenceDisplay eAnn3DDimReferenceDisplayReference;
extern PLMXML_ANNOTATION60_API eAnn3DDimReferenceDisplay eAnn3DDimReferenceDisplayMatched;
extern PLMXML_ANNOTATION60_API eAnn3DDimReferenceDisplay eAnn3DDimReferenceDisplayParenthesis;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFastenerDisplay class
/*!
Allowed Values:
\verbatim
  eAnn3DFastenerDisplayFlatToScreen
	"flatToScreen"
  eAnn3DFastenerDisplayFlatToSurface
	"flatToSurface"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFastenerDisplay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFastenerDisplay( const char* Type );
     
	//! Constructor
	eAnn3DFastenerDisplay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFastenerDisplay( );
     
	//! Destructor 
	virtual ~eAnn3DFastenerDisplay( );
     
	//! Assign from 'Type'
	const eAnn3DFastenerDisplay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFastenerDisplay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFastenerDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFastenerDisplay& e1, const eAnn3DFastenerDisplay& e2 );
     
	//! Compare Ann3DFastenerDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFastenerDisplay& e1, const eAnn3DFastenerDisplay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFastenerDisplay;
extern PLMXML_ANNOTATION60_API eAnn3DFastenerDisplay eAnn3DFastenerDisplayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFastenerDisplay eAnn3DFastenerDisplayFlatToScreen;
extern PLMXML_ANNOTATION60_API eAnn3DFastenerDisplay eAnn3DFastenerDisplayFlatToSurface;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DCenterlineEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DCenterlineEnumCenterline3D
	"centerline3D"
  eAnn3DCenterlineEnumSymmetricCenterline
	"symmetricCenterline"
  eAnn3DCenterlineEnumBoltCircleCenterline
	"boltCircleCenterline"
  eAnn3DCenterlineEnumCircularCenterline
	"circularCenterline"
  eAnn3DCenterlineEnumCentermark
	"centermark"
  eAnn3DCenterlineEnumOffsetCenterpoint
	"offsetCenterpoint"
  eAnn3DCenterlineEnumCenterline2D
	"centerline2D"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DCenterlineEnum( const char* Type );
     
	//! Constructor
	eAnn3DCenterlineEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DCenterlineEnum( );
     
	//! Destructor 
	virtual ~eAnn3DCenterlineEnum( );
     
	//! Assign from 'Type'
	const eAnn3DCenterlineEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DCenterlineEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DCenterlineEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DCenterlineEnum& e1, const eAnn3DCenterlineEnum& e2 );
     
	//! Compare Ann3DCenterlineEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DCenterlineEnum& e1, const eAnn3DCenterlineEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DCenterlineEnum;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumCenterline3D;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumSymmetricCenterline;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumBoltCircleCenterline;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumCircularCenterline;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumCentermark;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumOffsetCenterpoint;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineEnum eAnn3DCenterlineEnumCenterline2D;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DAngleFormat class
/*!
Allowed Values:
\verbatim
  eAnn3DAngleFormatDegrees
	"degrees"
  eAnn3DAngleFormatMinutes
	"minutes"
  eAnn3DAngleFormatSeconds
	"seconds"
  eAnn3DAngleFormatWholeDegrees
	"wholeDegrees"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DAngleFormat : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DAngleFormat( const char* Type );
     
	//! Constructor
	eAnn3DAngleFormat( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DAngleFormat( );
     
	//! Destructor 
	virtual ~eAnn3DAngleFormat( );
     
	//! Assign from 'Type'
	const eAnn3DAngleFormat& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DAngleFormat& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DAngleFormat
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DAngleFormat& e1, const eAnn3DAngleFormat& e2 );
     
	//! Compare Ann3DAngleFormat
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DAngleFormat& e1, const eAnn3DAngleFormat& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DAngleFormat;
extern PLMXML_ANNOTATION60_API eAnn3DAngleFormat eAnn3DAngleFormatUnset;
extern PLMXML_ANNOTATION60_API eAnn3DAngleFormat eAnn3DAngleFormatDegrees;
extern PLMXML_ANNOTATION60_API eAnn3DAngleFormat eAnn3DAngleFormatMinutes;
extern PLMXML_ANNOTATION60_API eAnn3DAngleFormat eAnn3DAngleFormatSeconds;
extern PLMXML_ANNOTATION60_API eAnn3DAngleFormat eAnn3DAngleFormatWholeDegrees;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionStandardType class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionStandardTypeBS
	"BS"
  eAnn3DDimensionStandardTypeANSI
	"ANSI Y14.5M 1982"
  eAnn3DDimensionStandardTypeJIS
	"JIS"
  eAnn3DDimensionStandardTypeASME
	"ASME Y14.5M 1994"
  eAnn3DDimensionStandardTypeASME2003
	"ASME Y14.41M 2003"
  eAnn3DDimensionStandardTypeISO
	"ISO"
  eAnn3DDimensionStandardTypeGMAddendum
	"GM Addendum 1994"
  eAnn3DDimensionStandardTypeASME2009
	"ASME Y14.5 2009"
  eAnn3DDimensionStandardTypeDIN
	"DIN"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionStandardType( const char* Type );
     
	//! Constructor
	eAnn3DDimensionStandardType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionStandardType( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionStandardType( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionStandardType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionStandardType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionStandardType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionStandardType& e1, const eAnn3DDimensionStandardType& e2 );
     
	//! Compare Ann3DDimensionStandardType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionStandardType& e1, const eAnn3DDimensionStandardType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionStandardType;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeBS;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeANSI;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeJIS;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeASME;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeASME2003;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeISO;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeGMAddendum;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeASME2009;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStandardType eAnn3DDimensionStandardTypeDIN;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldStandardType class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldStandardTypeDIN
	"DIN"
  eAnn3DLineWeldStandardTypeGB
	"GB"
  eAnn3DLineWeldStandardTypeJIS
	"JIS Z 3021"
  eAnn3DLineWeldStandardTypeESKD
	"ESKD"
  eAnn3DLineWeldStandardTypeANSI
	"ANSI/AWS A2.4-98"
  eAnn3DLineWeldStandardTypeISO
	"ISO 2556"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldStandardType( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldStandardType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldStandardType( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldStandardType( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldStandardType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldStandardType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldStandardType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldStandardType& e1, const eAnn3DLineWeldStandardType& e2 );
     
	//! Compare Ann3DLineWeldStandardType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldStandardType& e1, const eAnn3DLineWeldStandardType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldStandardType;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeDIN;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeGB;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeJIS;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeESKD;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeANSI;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldStandardType eAnn3DLineWeldStandardTypeISO;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DStubAttachmentEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DStubAttachmentEnumUnderline
	"underline"
  eAnn3DStubAttachmentEnumSide
	"side"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DStubAttachmentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DStubAttachmentEnum( const char* Type );
     
	//! Constructor
	eAnn3DStubAttachmentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DStubAttachmentEnum( );
     
	//! Destructor 
	virtual ~eAnn3DStubAttachmentEnum( );
     
	//! Assign from 'Type'
	const eAnn3DStubAttachmentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DStubAttachmentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DStubAttachmentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DStubAttachmentEnum& e1, const eAnn3DStubAttachmentEnum& e2 );
     
	//! Compare Ann3DStubAttachmentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DStubAttachmentEnum& e1, const eAnn3DStubAttachmentEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DStubAttachmentEnum;
extern PLMXML_ANNOTATION60_API eAnn3DStubAttachmentEnum eAnn3DStubAttachmentEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DStubAttachmentEnum eAnn3DStubAttachmentEnumUnderline;
extern PLMXML_ANNOTATION60_API eAnn3DStubAttachmentEnum eAnn3DStubAttachmentEnumSide;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DSurfaceFinishStandardType class
/*!
Allowed Values:
\verbatim
  eAnn3DSurfaceFinishStandardTypeANSI
	"ANSI Y14.36 1993"
  eAnn3DSurfaceFinishStandardTypeESKD
	"ESKD"
  eAnn3DSurfaceFinishStandardTypeJIS
	"JIS"
  eAnn3DSurfaceFinishStandardTypeGB
	"GB/T 131-93"
  eAnn3DSurfaceFinishStandardTypeISO
	"ISO"
  eAnn3DSurfaceFinishStandardTypeISO_1302_2002
	"ISO 1302:2002"
  eAnn3DSurfaceFinishStandardTypeASME
	"ASME Y14.36M 1996"
  eAnn3DSurfaceFinishStandardTypeDIN_EN_ISO_1302_2002
	"DIN EN ISO 1302:2002"
  eAnn3DSurfaceFinishStandardTypeDIN
	"DIN"
  eAnn3DSurfaceFinishStandardTypeJIS_1982
	"JIS_1982"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DSurfaceFinishStandardType( const char* Type );
     
	//! Constructor
	eAnn3DSurfaceFinishStandardType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DSurfaceFinishStandardType( );
     
	//! Destructor 
	virtual ~eAnn3DSurfaceFinishStandardType( );
     
	//! Assign from 'Type'
	const eAnn3DSurfaceFinishStandardType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DSurfaceFinishStandardType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DSurfaceFinishStandardType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DSurfaceFinishStandardType& e1, const eAnn3DSurfaceFinishStandardType& e2 );
     
	//! Compare Ann3DSurfaceFinishStandardType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DSurfaceFinishStandardType& e1, const eAnn3DSurfaceFinishStandardType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DSurfaceFinishStandardType;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeANSI;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeESKD;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeJIS;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeGB;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeISO;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeISO_1302_2002;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeASME;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeDIN_EN_ISO_1302_2002;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeDIN;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinishStandardType eAnn3DSurfaceFinishStandardTypeJIS_1982;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionDualPlacement class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionDualPlacementAfter
	"after"
  eAnn3DDimensionDualPlacementAbove
	"above"
  eAnn3DDimensionDualPlacementBelow
	"below"
  eAnn3DDimensionDualPlacementBefore
	"before"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionDualPlacement : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionDualPlacement( const char* Type );
     
	//! Constructor
	eAnn3DDimensionDualPlacement( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionDualPlacement( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionDualPlacement( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionDualPlacement& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionDualPlacement& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionDualPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionDualPlacement& e1, const eAnn3DDimensionDualPlacement& e2 );
     
	//! Compare Ann3DDimensionDualPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionDualPlacement& e1, const eAnn3DDimensionDualPlacement& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionDualPlacement;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDualPlacement eAnn3DDimensionDualPlacementUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDualPlacement eAnn3DDimensionDualPlacementAfter;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDualPlacement eAnn3DDimensionDualPlacementAbove;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDualPlacement eAnn3DDimensionDualPlacementBelow;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDualPlacement eAnn3DDimensionDualPlacementBefore;

////////////////////////////////////////////////////////////////////////////////////
//! eTextUnderlineType class
/*!
Allowed Values:
\verbatim
  eTextUnderlineTypeUnder
	"under"
  eTextUnderlineTypeOver
	"over"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eTextUnderlineType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTextUnderlineType( const char* Type );
     
	//! Constructor
	eTextUnderlineType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTextUnderlineType( );
     
	//! Destructor 
	virtual ~eTextUnderlineType( );
     
	//! Assign from 'Type'
	const eTextUnderlineType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTextUnderlineType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TextUnderlineType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eTextUnderlineType& e1, const eTextUnderlineType& e2 );
     
	//! Compare TextUnderlineType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eTextUnderlineType& e1, const eTextUnderlineType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTextUnderlineType;
extern PLMXML_ANNOTATION60_API eTextUnderlineType eTextUnderlineTypeUnset;
extern PLMXML_ANNOTATION60_API eTextUnderlineType eTextUnderlineTypeUnder;
extern PLMXML_ANNOTATION60_API eTextUnderlineType eTextUnderlineTypeOver;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionTolerance class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionToleranceLowerLimit1
	"-limit1"
  eAnn3DDimensionToleranceUpperLimit2
	"+limit2"
  eAnn3DDimensionToleranceLowerUnilateral
	"lowerUnilateral"
  eAnn3DDimensionToleranceUpperUnilateral
	"upperUnilateral"
  eAnn3DDimensionToleranceUpperLimit1
	"+limit1"
  eAnn3DDimensionToleranceLowerLimit2
	"-limit2"
  eAnn3DDimensionToleranceEqualBilateral
	"equalBilateral"
  eAnn3DDimensionToleranceBilateral
	"bilateral"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionTolerance( const char* Type );
     
	//! Constructor
	eAnn3DDimensionTolerance( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionTolerance( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionTolerance( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionTolerance& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionTolerance& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionTolerance
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionTolerance& e1, const eAnn3DDimensionTolerance& e2 );
     
	//! Compare Ann3DDimensionTolerance
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionTolerance& e1, const eAnn3DDimensionTolerance& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionTolerance;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceLowerLimit1;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceUpperLimit2;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceLowerUnilateral;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceUpperUnilateral;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceUpperLimit1;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceLowerLimit2;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceEqualBilateral;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionTolerance eAnn3DDimensionToleranceBilateral;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorEdgeType class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorEdgeTypeELower
	"e"
  eAnn3DLocatorEdgeTypeCE
	"CE"
  eAnn3DLocatorEdgeTypeEUpper
	"E"
  eAnn3DLocatorEdgeTypeEK
	"EK"
  eAnn3DLocatorEdgeTypeCO
	"CO"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorEdgeType( const char* Type );
     
	//! Constructor
	eAnn3DLocatorEdgeType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorEdgeType( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorEdgeType( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorEdgeType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorEdgeType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorEdgeType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorEdgeType& e1, const eAnn3DLocatorEdgeType& e2 );
     
	//! Compare Ann3DLocatorEdgeType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorEdgeType& e1, const eAnn3DLocatorEdgeType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorEdgeType;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType eAnn3DLocatorEdgeTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType eAnn3DLocatorEdgeTypeELower;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType eAnn3DLocatorEdgeTypeCE;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType eAnn3DLocatorEdgeTypeEUpper;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType eAnn3DLocatorEdgeTypeEK;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorEdgeType eAnn3DLocatorEdgeTypeCO;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFZoneShape class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFZoneShapeSquare
	"square"
  eAnn3DFCFZoneShapeSphericalDiameter
	"sphericalDiameter"
  eAnn3DFCFZoneShapeDiameter
	"diameter"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFZoneShape : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFZoneShape( const char* Type );
     
	//! Constructor
	eAnn3DFCFZoneShape( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFZoneShape( );
     
	//! Destructor 
	virtual ~eAnn3DFCFZoneShape( );
     
	//! Assign from 'Type'
	const eAnn3DFCFZoneShape& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFZoneShape& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFZoneShape
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFZoneShape& e1, const eAnn3DFCFZoneShape& e2 );
     
	//! Compare Ann3DFCFZoneShape
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFZoneShape& e1, const eAnn3DFCFZoneShape& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFZoneShape;
extern PLMXML_ANNOTATION60_API eAnn3DFCFZoneShape eAnn3DFCFZoneShapeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFZoneShape eAnn3DFCFZoneShapeSquare;
extern PLMXML_ANNOTATION60_API eAnn3DFCFZoneShape eAnn3DFCFZoneShapeSphericalDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DFCFZoneShape eAnn3DFCFZoneShapeDiameter;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineType class
/*!
Allowed Values:
\verbatim
  eAnn3DLineTypeLongDashed
	"longDashed"
  eAnn3DLineTypePhantom
	"phantom"
  eAnn3DLineTypeSolid
	"solid"
  eAnn3DLineTypeCentreline
	"centreline"
  eAnn3DLineTypeDashed
	"dashed"
  eAnn3DLineTypeDottedDashed
	"dottedDashed"
  eAnn3DLineTypeDotted
	"dotted"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineType( const char* Type );
     
	//! Constructor
	eAnn3DLineType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineType( );
     
	//! Destructor 
	virtual ~eAnn3DLineType( );
     
	//! Assign from 'Type'
	const eAnn3DLineType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineType& e1, const eAnn3DLineType& e2 );
     
	//! Compare Ann3DLineType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineType& e1, const eAnn3DLineType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineType;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeLongDashed;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypePhantom;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeSolid;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeCentreline;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeDashed;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeDottedDashed;
extern PLMXML_ANNOTATION60_API eAnn3DLineType eAnn3DLineTypeDotted;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DZeroToleranceSignEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DZeroToleranceSignEnumMinus
	"minus"
  eAnn3DZeroToleranceSignEnumPlus
	"plus"
  eAnn3DZeroToleranceSignEnumNone
	"none"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DZeroToleranceSignEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DZeroToleranceSignEnum( const char* Type );
     
	//! Constructor
	eAnn3DZeroToleranceSignEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DZeroToleranceSignEnum( );
     
	//! Destructor 
	virtual ~eAnn3DZeroToleranceSignEnum( );
     
	//! Assign from 'Type'
	const eAnn3DZeroToleranceSignEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DZeroToleranceSignEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DZeroToleranceSignEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DZeroToleranceSignEnum& e1, const eAnn3DZeroToleranceSignEnum& e2 );
     
	//! Compare Ann3DZeroToleranceSignEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DZeroToleranceSignEnum& e1, const eAnn3DZeroToleranceSignEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DZeroToleranceSignEnum;
extern PLMXML_ANNOTATION60_API eAnn3DZeroToleranceSignEnum eAnn3DZeroToleranceSignEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DZeroToleranceSignEnum eAnn3DZeroToleranceSignEnumMinus;
extern PLMXML_ANNOTATION60_API eAnn3DZeroToleranceSignEnum eAnn3DZeroToleranceSignEnumPlus;
extern PLMXML_ANNOTATION60_API eAnn3DZeroToleranceSignEnum eAnn3DZeroToleranceSignEnumNone;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLeaderAttachmentEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLeaderAttachmentEnumBottom
	"bottom"
  eAnn3DLeaderAttachmentEnumMiddle
	"middle"
  eAnn3DLeaderAttachmentEnumTop
	"top"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLeaderAttachmentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLeaderAttachmentEnum( const char* Type );
     
	//! Constructor
	eAnn3DLeaderAttachmentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLeaderAttachmentEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLeaderAttachmentEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLeaderAttachmentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLeaderAttachmentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLeaderAttachmentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLeaderAttachmentEnum& e1, const eAnn3DLeaderAttachmentEnum& e2 );
     
	//! Compare Ann3DLeaderAttachmentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLeaderAttachmentEnum& e1, const eAnn3DLeaderAttachmentEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLeaderAttachmentEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLeaderAttachmentEnum eAnn3DLeaderAttachmentEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLeaderAttachmentEnum eAnn3DLeaderAttachmentEnumBottom;
extern PLMXML_ANNOTATION60_API eAnn3DLeaderAttachmentEnum eAnn3DLeaderAttachmentEnumMiddle;
extern PLMXML_ANNOTATION60_API eAnn3DLeaderAttachmentEnum eAnn3DLeaderAttachmentEnumTop;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimStatisticalPlacement class
/*!
Allowed Values:
\verbatim
  eAnn3DDimStatisticalPlacementAfter
	"after"
  eAnn3DDimStatisticalPlacementAbove
	"above"
  eAnn3DDimStatisticalPlacementBelow
	"below"
  eAnn3DDimStatisticalPlacementBefore
	"before"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimStatisticalPlacement : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimStatisticalPlacement( const char* Type );
     
	//! Constructor
	eAnn3DDimStatisticalPlacement( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimStatisticalPlacement( );
     
	//! Destructor 
	virtual ~eAnn3DDimStatisticalPlacement( );
     
	//! Assign from 'Type'
	const eAnn3DDimStatisticalPlacement& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimStatisticalPlacement& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimStatisticalPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimStatisticalPlacement& e1, const eAnn3DDimStatisticalPlacement& e2 );
     
	//! Compare Ann3DDimStatisticalPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimStatisticalPlacement& e1, const eAnn3DDimStatisticalPlacement& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimStatisticalPlacement;
extern PLMXML_ANNOTATION60_API eAnn3DDimStatisticalPlacement eAnn3DDimStatisticalPlacementUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimStatisticalPlacement eAnn3DDimStatisticalPlacementAfter;
extern PLMXML_ANNOTATION60_API eAnn3DDimStatisticalPlacement eAnn3DDimStatisticalPlacementAbove;
extern PLMXML_ANNOTATION60_API eAnn3DDimStatisticalPlacement eAnn3DDimStatisticalPlacementBelow;
extern PLMXML_ANNOTATION60_API eAnn3DDimStatisticalPlacement eAnn3DDimStatisticalPlacementBefore;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCF class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFTotalRunout
	"totalRunout"
  eAnn3DFCFConcentricity
	"concentricity"
  eAnn3DFCFCircularRunout
	"circularRunout"
  eAnn3DFCFPosition
	"position"
  eAnn3DFCFProfileOfASurface
	"profileOfASurface"
  eAnn3DFCFFlatness
	"flatness"
  eAnn3DFCFProfileOfALine
	"profileOfALine"
  eAnn3DFCFCircularity
	"circularity"
  eAnn3DFCFCylindricity
	"cylindricity"
  eAnn3DFCFAxisIntersection
	"axisIntersection"
  eAnn3DFCFSymmetry
	"symmetry"
  eAnn3DFCFAngularity
	"angularity"
  eAnn3DFCFPerpendicularity
	"perpendicularity"
  eAnn3DFCFStraightness
	"straightness"
  eAnn3DFCFParallelism
	"parallelism"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCF : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCF( const char* Type );
     
	//! Constructor
	eAnn3DFCF( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCF( );
     
	//! Destructor 
	virtual ~eAnn3DFCF( );
     
	//! Assign from 'Type'
	const eAnn3DFCF& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCF& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCF
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCF& e1, const eAnn3DFCF& e2 );
     
	//! Compare Ann3DFCF
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCF& e1, const eAnn3DFCF& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCF;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFTotalRunout;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFConcentricity;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFCircularRunout;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFPosition;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFProfileOfASurface;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFFlatness;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFProfileOfALine;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFCircularity;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFCylindricity;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFAxisIntersection;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFSymmetry;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFAngularity;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFPerpendicularity;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFStraightness;
extern PLMXML_ANNOTATION60_API eAnn3DFCF eAnn3DFCFParallelism;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLocatorRectSlotFreeformType class
/*!
Allowed Values:
\verbatim
  eAnn3DLocatorRectSlotFreeformTypeDL
	"DL"
  eAnn3DLocatorRectSlotFreeformTypeBL
	"BL"
  eAnn3DLocatorRectSlotFreeformTypeCH
	"CH"
  eAnn3DLocatorRectSlotFreeformTypeHK
	"HK"
  eAnn3DLocatorRectSlotFreeformTypeHLower
	"h"
  eAnn3DLocatorRectSlotFreeformTypeHUpper
	"H"
  eAnn3DLocatorRectSlotFreeformTypeHk
	"hk"
  eAnn3DLocatorRectSlotFreeformTypeAC
	"AC"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLocatorRectSlotFreeformType( const char* Type );
     
	//! Constructor
	eAnn3DLocatorRectSlotFreeformType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLocatorRectSlotFreeformType( );
     
	//! Destructor 
	virtual ~eAnn3DLocatorRectSlotFreeformType( );
     
	//! Assign from 'Type'
	const eAnn3DLocatorRectSlotFreeformType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLocatorRectSlotFreeformType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLocatorRectSlotFreeformType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLocatorRectSlotFreeformType& e1, const eAnn3DLocatorRectSlotFreeformType& e2 );
     
	//! Compare Ann3DLocatorRectSlotFreeformType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLocatorRectSlotFreeformType& e1, const eAnn3DLocatorRectSlotFreeformType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLocatorRectSlotFreeformType;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeDL;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeBL;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeCH;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeHK;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeHLower;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeHUpper;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeHk;
extern PLMXML_ANNOTATION60_API eAnn3DLocatorRectSlotFreeformType eAnn3DLocatorRectSlotFreeformTypeAC;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldFieldWeldEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldFieldWeldEnumCommon
	"common"
  eAnn3DLineWeldFieldWeldEnumEskd
	"eskd"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldFieldWeldEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldFieldWeldEnum( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldFieldWeldEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldFieldWeldEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldFieldWeldEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldFieldWeldEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldFieldWeldEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldFieldWeldEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldFieldWeldEnum& e1, const eAnn3DLineWeldFieldWeldEnum& e2 );
     
	//! Compare Ann3DLineWeldFieldWeldEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldFieldWeldEnum& e1, const eAnn3DLineWeldFieldWeldEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldFieldWeldEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFieldWeldEnum eAnn3DLineWeldFieldWeldEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFieldWeldEnum eAnn3DLineWeldFieldWeldEnumCommon;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFieldWeldEnum eAnn3DLineWeldFieldWeldEnumEskd;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimension class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionLinear
	"linear"
  eAnn3DDimensionRadial
	"radial"
  eAnn3DDimensionAngular
	"angular"
  eAnn3DDimensionCurveLength
	"curveLength"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimension : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimension( const char* Type );
     
	//! Constructor
	eAnn3DDimension( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimension( );
     
	//! Destructor 
	virtual ~eAnn3DDimension( );
     
	//! Assign from 'Type'
	const eAnn3DDimension& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimension& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimension
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimension& e1, const eAnn3DDimension& e2 );
     
	//! Compare Ann3DDimension
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimension& e1, const eAnn3DDimension& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimension;
extern PLMXML_ANNOTATION60_API eAnn3DDimension eAnn3DDimensionUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimension eAnn3DDimensionLinear;
extern PLMXML_ANNOTATION60_API eAnn3DDimension eAnn3DDimensionRadial;
extern PLMXML_ANNOTATION60_API eAnn3DDimension eAnn3DDimensionAngular;
extern PLMXML_ANNOTATION60_API eAnn3DDimension eAnn3DDimensionCurveLength;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextStrikethroughEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DTextStrikethroughEnumSingle
	"single"
  eAnn3DTextStrikethroughEnumNone
	"none"
  eAnn3DTextStrikethroughEnumDouble
	"double"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextStrikethroughEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextStrikethroughEnum( const char* Type );
     
	//! Constructor
	eAnn3DTextStrikethroughEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextStrikethroughEnum( );
     
	//! Destructor 
	virtual ~eAnn3DTextStrikethroughEnum( );
     
	//! Assign from 'Type'
	const eAnn3DTextStrikethroughEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextStrikethroughEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextStrikethroughEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextStrikethroughEnum& e1, const eAnn3DTextStrikethroughEnum& e2 );
     
	//! Compare Ann3DTextStrikethroughEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextStrikethroughEnum& e1, const eAnn3DTextStrikethroughEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextStrikethroughEnum;
extern PLMXML_ANNOTATION60_API eAnn3DTextStrikethroughEnum eAnn3DTextStrikethroughEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextStrikethroughEnum eAnn3DTextStrikethroughEnumSingle;
extern PLMXML_ANNOTATION60_API eAnn3DTextStrikethroughEnum eAnn3DTextStrikethroughEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DTextStrikethroughEnum eAnn3DTextStrikethroughEnumDouble;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DExtensionJogDefinitionEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DExtensionJogDefinitionEnumStartAngle
	"startAngle"
  eAnn3DExtensionJogDefinitionEnumEndAngle
	"endAngle"
  eAnn3DExtensionJogDefinitionEnumStartEnd
	"startEnd"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DExtensionJogDefinitionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DExtensionJogDefinitionEnum( const char* Type );
     
	//! Constructor
	eAnn3DExtensionJogDefinitionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DExtensionJogDefinitionEnum( );
     
	//! Destructor 
	virtual ~eAnn3DExtensionJogDefinitionEnum( );
     
	//! Assign from 'Type'
	const eAnn3DExtensionJogDefinitionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DExtensionJogDefinitionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DExtensionJogDefinitionEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DExtensionJogDefinitionEnum& e1, const eAnn3DExtensionJogDefinitionEnum& e2 );
     
	//! Compare Ann3DExtensionJogDefinitionEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DExtensionJogDefinitionEnum& e1, const eAnn3DExtensionJogDefinitionEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DExtensionJogDefinitionEnum;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJogDefinitionEnum eAnn3DExtensionJogDefinitionEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJogDefinitionEnum eAnn3DExtensionJogDefinitionEnumStartAngle;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJogDefinitionEnum eAnn3DExtensionJogDefinitionEnumEndAngle;
extern PLMXML_ANNOTATION60_API eAnn3DExtensionJogDefinitionEnum eAnn3DExtensionJogDefinitionEnumStartEnd;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFitDesignationAlignmentEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFitDesignationAlignmentEnumMiddle
	"middle"
  eAnn3DFitDesignationAlignmentEnumBottom
	"bottom"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFitDesignationAlignmentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFitDesignationAlignmentEnum( const char* Type );
     
	//! Constructor
	eAnn3DFitDesignationAlignmentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFitDesignationAlignmentEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFitDesignationAlignmentEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFitDesignationAlignmentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFitDesignationAlignmentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFitDesignationAlignmentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFitDesignationAlignmentEnum& e1, const eAnn3DFitDesignationAlignmentEnum& e2 );
     
	//! Compare Ann3DFitDesignationAlignmentEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFitDesignationAlignmentEnum& e1, const eAnn3DFitDesignationAlignmentEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFitDesignationAlignmentEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFitDesignationAlignmentEnum eAnn3DFitDesignationAlignmentEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFitDesignationAlignmentEnum eAnn3DFitDesignationAlignmentEnumMiddle;
extern PLMXML_ANNOTATION60_API eAnn3DFitDesignationAlignmentEnum eAnn3DFitDesignationAlignmentEnumBottom;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimDiameterPlacement class
/*!
Allowed Values:
\verbatim
  eAnn3DDimDiameterPlacementAfter
	"after"
  eAnn3DDimDiameterPlacementAbove
	"above"
  eAnn3DDimDiameterPlacementBelow
	"below"
  eAnn3DDimDiameterPlacementBefore
	"before"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimDiameterPlacement : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimDiameterPlacement( const char* Type );
     
	//! Constructor
	eAnn3DDimDiameterPlacement( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimDiameterPlacement( );
     
	//! Destructor 
	virtual ~eAnn3DDimDiameterPlacement( );
     
	//! Assign from 'Type'
	const eAnn3DDimDiameterPlacement& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimDiameterPlacement& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimDiameterPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimDiameterPlacement& e1, const eAnn3DDimDiameterPlacement& e2 );
     
	//! Compare Ann3DDimDiameterPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimDiameterPlacement& e1, const eAnn3DDimDiameterPlacement& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimDiameterPlacement;
extern PLMXML_ANNOTATION60_API eAnn3DDimDiameterPlacement eAnn3DDimDiameterPlacementUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimDiameterPlacement eAnn3DDimDiameterPlacementAfter;
extern PLMXML_ANNOTATION60_API eAnn3DDimDiameterPlacement eAnn3DDimDiameterPlacementAbove;
extern PLMXML_ANNOTATION60_API eAnn3DDimDiameterPlacement eAnn3DDimDiameterPlacementBelow;
extern PLMXML_ANNOTATION60_API eAnn3DDimDiameterPlacement eAnn3DDimDiameterPlacementBefore;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionArrowPlacement class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionArrowPlacementIn
	"in"
  eAnn3DDimensionArrowPlacementOut
	"out"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionArrowPlacement : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionArrowPlacement( const char* Type );
     
	//! Constructor
	eAnn3DDimensionArrowPlacement( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionArrowPlacement( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionArrowPlacement( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionArrowPlacement& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionArrowPlacement& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionArrowPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionArrowPlacement& e1, const eAnn3DDimensionArrowPlacement& e2 );
     
	//! Compare Ann3DDimensionArrowPlacement
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionArrowPlacement& e1, const eAnn3DDimensionArrowPlacement& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionArrowPlacement;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionArrowPlacement eAnn3DDimensionArrowPlacementUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionArrowPlacement eAnn3DDimensionArrowPlacementIn;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionArrowPlacement eAnn3DDimensionArrowPlacementOut;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DChamferLeaderEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DChamferLeaderEnumLinear
	"linear"
  eAnn3DChamferLeaderEnumPerpendicular
	"perpendicular"
  eAnn3DChamferLeaderEnumParallel
	"parallel"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DChamferLeaderEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DChamferLeaderEnum( const char* Type );
     
	//! Constructor
	eAnn3DChamferLeaderEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DChamferLeaderEnum( );
     
	//! Destructor 
	virtual ~eAnn3DChamferLeaderEnum( );
     
	//! Assign from 'Type'
	const eAnn3DChamferLeaderEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DChamferLeaderEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DChamferLeaderEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DChamferLeaderEnum& e1, const eAnn3DChamferLeaderEnum& e2 );
     
	//! Compare Ann3DChamferLeaderEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DChamferLeaderEnum& e1, const eAnn3DChamferLeaderEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DChamferLeaderEnum;
extern PLMXML_ANNOTATION60_API eAnn3DChamferLeaderEnum eAnn3DChamferLeaderEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DChamferLeaderEnum eAnn3DChamferLeaderEnumLinear;
extern PLMXML_ANNOTATION60_API eAnn3DChamferLeaderEnum eAnn3DChamferLeaderEnumPerpendicular;
extern PLMXML_ANNOTATION60_API eAnn3DChamferLeaderEnum eAnn3DChamferLeaderEnumParallel;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DSpotWeldDisplay class
/*!
Allowed Values:
\verbatim
  eAnn3DSpotWeldDisplayFlatToScreen
	"flatToScreen"
  eAnn3DSpotWeldDisplayFlatToSurface
	"flatToSurface"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DSpotWeldDisplay : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DSpotWeldDisplay( const char* Type );
     
	//! Constructor
	eAnn3DSpotWeldDisplay( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DSpotWeldDisplay( );
     
	//! Destructor 
	virtual ~eAnn3DSpotWeldDisplay( );
     
	//! Assign from 'Type'
	const eAnn3DSpotWeldDisplay& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DSpotWeldDisplay& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DSpotWeldDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DSpotWeldDisplay& e1, const eAnn3DSpotWeldDisplay& e2 );
     
	//! Compare Ann3DSpotWeldDisplay
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DSpotWeldDisplay& e1, const eAnn3DSpotWeldDisplay& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DSpotWeldDisplay;
extern PLMXML_ANNOTATION60_API eAnn3DSpotWeldDisplay eAnn3DSpotWeldDisplayUnset;
extern PLMXML_ANNOTATION60_API eAnn3DSpotWeldDisplay eAnn3DSpotWeldDisplayFlatToScreen;
extern PLMXML_ANNOTATION60_API eAnn3DSpotWeldDisplay eAnn3DSpotWeldDisplayFlatToSurface;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionDual class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionDualLineSeparated
	"lineSeparated"
  eAnn3DDimensionDualBracket
	"bracket"
  eAnn3DDimensionDualPositional
	"positional"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionDual : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionDual( const char* Type );
     
	//! Constructor
	eAnn3DDimensionDual( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionDual( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionDual( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionDual& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionDual& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionDual
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionDual& e1, const eAnn3DDimensionDual& e2 );
     
	//! Compare Ann3DDimensionDual
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionDual& e1, const eAnn3DDimensionDual& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionDual;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDual eAnn3DDimensionDualUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDual eAnn3DDimensionDualLineSeparated;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDual eAnn3DDimensionDualBracket;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionDual eAnn3DDimensionDualPositional;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextOrientationType class
/*!
Allowed Values:
\verbatim
  eAnn3DTextOrientationTypeVertical
	"vertical"
  eAnn3DTextOrientationTypeHorizontal
	"horizontal"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextOrientationType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextOrientationType( const char* Type );
     
	//! Constructor
	eAnn3DTextOrientationType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextOrientationType( );
     
	//! Destructor 
	virtual ~eAnn3DTextOrientationType( );
     
	//! Assign from 'Type'
	const eAnn3DTextOrientationType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextOrientationType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextOrientationType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextOrientationType& e1, const eAnn3DTextOrientationType& e2 );
     
	//! Compare Ann3DTextOrientationType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextOrientationType& e1, const eAnn3DTextOrientationType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextOrientationType;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationType eAnn3DTextOrientationTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationType eAnn3DTextOrientationTypeVertical;
extern PLMXML_ANNOTATION60_API eAnn3DTextOrientationType eAnn3DTextOrientationTypeHorizontal;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DOriginAnchorEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DOriginAnchorEnumMiddleCentre
	"middleCentre"
  eAnn3DOriginAnchorEnumTopLeft
	"topLeft"
  eAnn3DOriginAnchorEnumTopRight
	"topRight"
  eAnn3DOriginAnchorEnumBottomLeft
	"bottomLeft"
  eAnn3DOriginAnchorEnumBottomRight
	"bottomRight"
  eAnn3DOriginAnchorEnumMiddleLeft
	"middleLeft"
  eAnn3DOriginAnchorEnumTopCentre
	"topCentre"
  eAnn3DOriginAnchorEnumMiddleRight
	"middleRight"
  eAnn3DOriginAnchorEnumBottomCentre
	"bottomCentre"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DOriginAnchorEnum( const char* Type );
     
	//! Constructor
	eAnn3DOriginAnchorEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DOriginAnchorEnum( );
     
	//! Destructor 
	virtual ~eAnn3DOriginAnchorEnum( );
     
	//! Assign from 'Type'
	const eAnn3DOriginAnchorEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DOriginAnchorEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DOriginAnchorEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DOriginAnchorEnum& e1, const eAnn3DOriginAnchorEnum& e2 );
     
	//! Compare Ann3DOriginAnchorEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DOriginAnchorEnum& e1, const eAnn3DOriginAnchorEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DOriginAnchorEnum;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumMiddleCentre;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumTopLeft;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumTopRight;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumBottomLeft;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumBottomRight;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumMiddleLeft;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumTopCentre;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumMiddleRight;
extern PLMXML_ANNOTATION60_API eAnn3DOriginAnchorEnum eAnn3DOriginAnchorEnumBottomCentre;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DBundleOrDressingNote class
/*!
Allowed Values:
\verbatim
  eAnn3DBundleOrDressingNoteDressingNote
	"dressingNote"
  eAnn3DBundleOrDressingNoteBundleNote
	"bundleNote"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DBundleOrDressingNote : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DBundleOrDressingNote( const char* Type );
     
	//! Constructor
	eAnn3DBundleOrDressingNote( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DBundleOrDressingNote( );
     
	//! Destructor 
	virtual ~eAnn3DBundleOrDressingNote( );
     
	//! Assign from 'Type'
	const eAnn3DBundleOrDressingNote& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DBundleOrDressingNote& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DBundleOrDressingNote
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DBundleOrDressingNote& e1, const eAnn3DBundleOrDressingNote& e2 );
     
	//! Compare Ann3DBundleOrDressingNote
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DBundleOrDressingNote& e1, const eAnn3DBundleOrDressingNote& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DBundleOrDressingNote;
extern PLMXML_ANNOTATION60_API eAnn3DBundleOrDressingNote eAnn3DBundleOrDressingNoteUnset;
extern PLMXML_ANNOTATION60_API eAnn3DBundleOrDressingNote eAnn3DBundleOrDressingNoteDressingNote;
extern PLMXML_ANNOTATION60_API eAnn3DBundleOrDressingNote eAnn3DBundleOrDressingNoteBundleNote;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextLeaderPositionEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DTextLeaderPositionEnumAfterLeader
	"afterLeader"
  eAnn3DTextLeaderPositionEnumNone
	"none"
  eAnn3DTextLeaderPositionEnumAboveLeader
	"aboveLeader"
  eAnn3DTextLeaderPositionEnumAfterStub
	"afterStub"
  eAnn3DTextLeaderPositionEnumAboveStub
	"aboveStub"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextLeaderPositionEnum( const char* Type );
     
	//! Constructor
	eAnn3DTextLeaderPositionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextLeaderPositionEnum( );
     
	//! Destructor 
	virtual ~eAnn3DTextLeaderPositionEnum( );
     
	//! Assign from 'Type'
	const eAnn3DTextLeaderPositionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextLeaderPositionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextLeaderPositionEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextLeaderPositionEnum& e1, const eAnn3DTextLeaderPositionEnum& e2 );
     
	//! Compare Ann3DTextLeaderPositionEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextLeaderPositionEnum& e1, const eAnn3DTextLeaderPositionEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextLeaderPositionEnum;
extern PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum eAnn3DTextLeaderPositionEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum eAnn3DTextLeaderPositionEnumAfterLeader;
extern PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum eAnn3DTextLeaderPositionEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum eAnn3DTextLeaderPositionEnumAboveLeader;
extern PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum eAnn3DTextLeaderPositionEnumAfterStub;
extern PLMXML_ANNOTATION60_API eAnn3DTextLeaderPositionEnum eAnn3DTextLeaderPositionEnumAboveStub;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DCenterlineDisplayEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DCenterlineDisplayEnumCenterlineWithExtension
	"centerlineWithExtension"
  eAnn3DCenterlineDisplayEnumNone
	"none"
  eAnn3DCenterlineDisplayEnumCenterline
	"centerline"
  eAnn3DCenterlineDisplayEnumCenterpoint
	"centerpoint"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DCenterlineDisplayEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DCenterlineDisplayEnum( const char* Type );
     
	//! Constructor
	eAnn3DCenterlineDisplayEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DCenterlineDisplayEnum( );
     
	//! Destructor 
	virtual ~eAnn3DCenterlineDisplayEnum( );
     
	//! Assign from 'Type'
	const eAnn3DCenterlineDisplayEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DCenterlineDisplayEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DCenterlineDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DCenterlineDisplayEnum& e1, const eAnn3DCenterlineDisplayEnum& e2 );
     
	//! Compare Ann3DCenterlineDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DCenterlineDisplayEnum& e1, const eAnn3DCenterlineDisplayEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DCenterlineDisplayEnum;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineDisplayEnum eAnn3DCenterlineDisplayEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineDisplayEnum eAnn3DCenterlineDisplayEnumCenterlineWithExtension;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineDisplayEnum eAnn3DCenterlineDisplayEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineDisplayEnum eAnn3DCenterlineDisplayEnumCenterline;
extern PLMXML_ANNOTATION60_API eAnn3DCenterlineDisplayEnum eAnn3DCenterlineDisplayEnumCenterpoint;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DAreaEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DAreaEnumRectangular
	"rectangular"
  eAnn3DAreaEnumAnnular
	"annular"
  eAnn3DAreaEnumGeneral
	"general"
  eAnn3DAreaEnumCylindrical
	"cylindrical"
  eAnn3DAreaEnumCircular
	"circular"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DAreaEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DAreaEnum( const char* Type );
     
	//! Constructor
	eAnn3DAreaEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DAreaEnum( );
     
	//! Destructor 
	virtual ~eAnn3DAreaEnum( );
     
	//! Assign from 'Type'
	const eAnn3DAreaEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DAreaEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DAreaEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DAreaEnum& e1, const eAnn3DAreaEnum& e2 );
     
	//! Compare Ann3DAreaEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DAreaEnum& e1, const eAnn3DAreaEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DAreaEnum;
extern PLMXML_ANNOTATION60_API eAnn3DAreaEnum eAnn3DAreaEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DAreaEnum eAnn3DAreaEnumRectangular;
extern PLMXML_ANNOTATION60_API eAnn3DAreaEnum eAnn3DAreaEnumAnnular;
extern PLMXML_ANNOTATION60_API eAnn3DAreaEnum eAnn3DAreaEnumGeneral;
extern PLMXML_ANNOTATION60_API eAnn3DAreaEnum eAnn3DAreaEnumCylindrical;
extern PLMXML_ANNOTATION60_API eAnn3DAreaEnum eAnn3DAreaEnumCircular;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DHalfArrowEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DHalfArrowEnumFull
	"full"
  eAnn3DHalfArrowEnumRight
	"right"
  eAnn3DHalfArrowEnumLeft
	"left"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DHalfArrowEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DHalfArrowEnum( const char* Type );
     
	//! Constructor
	eAnn3DHalfArrowEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DHalfArrowEnum( );
     
	//! Destructor 
	virtual ~eAnn3DHalfArrowEnum( );
     
	//! Assign from 'Type'
	const eAnn3DHalfArrowEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DHalfArrowEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DHalfArrowEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DHalfArrowEnum& e1, const eAnn3DHalfArrowEnum& e2 );
     
	//! Compare Ann3DHalfArrowEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DHalfArrowEnum& e1, const eAnn3DHalfArrowEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DHalfArrowEnum;
extern PLMXML_ANNOTATION60_API eAnn3DHalfArrowEnum eAnn3DHalfArrowEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DHalfArrowEnum eAnn3DHalfArrowEnumFull;
extern PLMXML_ANNOTATION60_API eAnn3DHalfArrowEnum eAnn3DHalfArrowEnumRight;
extern PLMXML_ANNOTATION60_API eAnn3DHalfArrowEnum eAnn3DHalfArrowEnumLeft;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDatumOnLeaderEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DDatumOnLeaderEnumFilled
	"filled"
  eAnn3DDatumOnLeaderEnumSolid
	"solid"
  eAnn3DDatumOnLeaderEnumNone
	"none"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDatumOnLeaderEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDatumOnLeaderEnum( const char* Type );
     
	//! Constructor
	eAnn3DDatumOnLeaderEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDatumOnLeaderEnum( );
     
	//! Destructor 
	virtual ~eAnn3DDatumOnLeaderEnum( );
     
	//! Assign from 'Type'
	const eAnn3DDatumOnLeaderEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDatumOnLeaderEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDatumOnLeaderEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDatumOnLeaderEnum& e1, const eAnn3DDatumOnLeaderEnum& e2 );
     
	//! Compare Ann3DDatumOnLeaderEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDatumOnLeaderEnum& e1, const eAnn3DDatumOnLeaderEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDatumOnLeaderEnum;
extern PLMXML_ANNOTATION60_API eAnn3DDatumOnLeaderEnum eAnn3DDatumOnLeaderEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDatumOnLeaderEnum eAnn3DDatumOnLeaderEnumFilled;
extern PLMXML_ANNOTATION60_API eAnn3DDatumOnLeaderEnum eAnn3DDatumOnLeaderEnumSolid;
extern PLMXML_ANNOTATION60_API eAnn3DDatumOnLeaderEnum eAnn3DDatumOnLeaderEnumNone;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFTextUnderlineEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFTextUnderlineEnumAll
	"all"
  eAnn3DFCFTextUnderlineEnumNone
	"none"
  eAnn3DFCFTextUnderlineEnumTop
	"top"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFTextUnderlineEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFTextUnderlineEnum( const char* Type );
     
	//! Constructor
	eAnn3DFCFTextUnderlineEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFTextUnderlineEnum( );
     
	//! Destructor 
	virtual ~eAnn3DFCFTextUnderlineEnum( );
     
	//! Assign from 'Type'
	const eAnn3DFCFTextUnderlineEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFTextUnderlineEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFTextUnderlineEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFTextUnderlineEnum& e1, const eAnn3DFCFTextUnderlineEnum& e2 );
     
	//! Compare Ann3DFCFTextUnderlineEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFTextUnderlineEnum& e1, const eAnn3DFCFTextUnderlineEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFTextUnderlineEnum;
extern PLMXML_ANNOTATION60_API eAnn3DFCFTextUnderlineEnum eAnn3DFCFTextUnderlineEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFTextUnderlineEnum eAnn3DFCFTextUnderlineEnumAll;
extern PLMXML_ANNOTATION60_API eAnn3DFCFTextUnderlineEnum eAnn3DFCFTextUnderlineEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DFCFTextUnderlineEnum eAnn3DFCFTextUnderlineEnumTop;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DCircularCenterlineMethodEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DCircularCenterlineMethodEnumPoints
	"points"
  eAnn3DCircularCenterlineMethodEnumCenter
	"center"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DCircularCenterlineMethodEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DCircularCenterlineMethodEnum( const char* Type );
     
	//! Constructor
	eAnn3DCircularCenterlineMethodEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DCircularCenterlineMethodEnum( );
     
	//! Destructor 
	virtual ~eAnn3DCircularCenterlineMethodEnum( );
     
	//! Assign from 'Type'
	const eAnn3DCircularCenterlineMethodEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DCircularCenterlineMethodEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DCircularCenterlineMethodEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DCircularCenterlineMethodEnum& e1, const eAnn3DCircularCenterlineMethodEnum& e2 );
     
	//! Compare Ann3DCircularCenterlineMethodEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DCircularCenterlineMethodEnum& e1, const eAnn3DCircularCenterlineMethodEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DCircularCenterlineMethodEnum;
extern PLMXML_ANNOTATION60_API eAnn3DCircularCenterlineMethodEnum eAnn3DCircularCenterlineMethodEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DCircularCenterlineMethodEnum eAnn3DCircularCenterlineMethodEnumPoints;
extern PLMXML_ANNOTATION60_API eAnn3DCircularCenterlineMethodEnum eAnn3DCircularCenterlineMethodEnumCenter;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DArrow class
/*!
Allowed Values:
\verbatim
  eAnn3DArrowOrigin
	"origin"
  eAnn3DArrowClosed
	"closed"
  eAnn3DArrowDatum
	"datum"
  eAnn3DArrowXOrigin
	"xOrigin"
  eAnn3DArrowFilledDot
	"filledDot"
  eAnn3DArrowNone
	"none"
  eAnn3DArrowFilledDouble
	"filledDouble"
  eAnn3DArrowOpen
	"open"
  eAnn3DArrowBox
	"box"
  eAnn3DArrowClosedSolid
	"closedSolid"
  eAnn3DArrowCross
	"cross"
  eAnn3DArrowSolidOrigin
	"solidOrigin"
  eAnn3DArrowX
	"x"
  eAnn3DArrowClosedDoubleSolid
	"closedDoubleSolid"
  eAnn3DArrowSolidRoundBackDart
	"solidRoundBackDart"
  eAnn3DArrowFilled
	"filled"
  eAnn3DArrowOpenDouble
	"openDouble"
  eAnn3DArrowFilledOrigin
	"filledOrigin"
  eAnn3DArrowPlus
	"plus"
  eAnn3DArrowIntegral
	"integral"
  eAnn3DArrowWedge
	"wedge"
  eAnn3DArrowFilledDatum
	"filledDatum"
  eAnn3DArrowFilledRoundBackDart
	"filledRoundBackDart"
  eAnn3DArrowClosedDouble
	"closedDouble"
  eAnn3DArrowSolidBox
	"solidBox"
  eAnn3DArrowFilledBox
	"filledBox"
  eAnn3DArrowRoundBackDart
	"roundBackDart"
  eAnn3DArrowDot
	"dot"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DArrow : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DArrow( const char* Type );
     
	//! Constructor
	eAnn3DArrow( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DArrow( );
     
	//! Destructor 
	virtual ~eAnn3DArrow( );
     
	//! Assign from 'Type'
	const eAnn3DArrow& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DArrow& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DArrow
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DArrow& e1, const eAnn3DArrow& e2 );
     
	//! Compare Ann3DArrow
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DArrow& e1, const eAnn3DArrow& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DArrow;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowUnset;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowOrigin;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowClosed;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowDatum;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowXOrigin;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilledDot;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowNone;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilledDouble;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowOpen;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowBox;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowClosedSolid;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowCross;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowSolidOrigin;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowX;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowClosedDoubleSolid;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowSolidRoundBackDart;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilled;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowOpenDouble;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilledOrigin;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowPlus;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowIntegral;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowWedge;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilledDatum;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilledRoundBackDart;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowClosedDouble;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowSolidBox;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowFilledBox;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowRoundBackDart;
extern PLMXML_ANNOTATION60_API eAnn3DArrow eAnn3DArrowDot;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextSubscriptEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DTextSubscriptEnumSuper
	"super"
  eAnn3DTextSubscriptEnumSub
	"sub"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextSubscriptEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextSubscriptEnum( const char* Type );
     
	//! Constructor
	eAnn3DTextSubscriptEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextSubscriptEnum( );
     
	//! Destructor 
	virtual ~eAnn3DTextSubscriptEnum( );
     
	//! Assign from 'Type'
	const eAnn3DTextSubscriptEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextSubscriptEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextSubscriptEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextSubscriptEnum& e1, const eAnn3DTextSubscriptEnum& e2 );
     
	//! Compare Ann3DTextSubscriptEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextSubscriptEnum& e1, const eAnn3DTextSubscriptEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextSubscriptEnum;
extern PLMXML_ANNOTATION60_API eAnn3DTextSubscriptEnum eAnn3DTextSubscriptEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextSubscriptEnum eAnn3DTextSubscriptEnumSuper;
extern PLMXML_ANNOTATION60_API eAnn3DTextSubscriptEnum eAnn3DTextSubscriptEnumSub;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DChamferSymbolEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DChamferSymbolEnumSuffix
	"suffix"
  eAnn3DChamferSymbolEnumPrefix
	"prefix"
  eAnn3DChamferSymbolEnumNone
	"none"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DChamferSymbolEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DChamferSymbolEnum( const char* Type );
     
	//! Constructor
	eAnn3DChamferSymbolEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DChamferSymbolEnum( );
     
	//! Destructor 
	virtual ~eAnn3DChamferSymbolEnum( );
     
	//! Assign from 'Type'
	const eAnn3DChamferSymbolEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DChamferSymbolEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DChamferSymbolEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DChamferSymbolEnum& e1, const eAnn3DChamferSymbolEnum& e2 );
     
	//! Compare Ann3DChamferSymbolEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DChamferSymbolEnum& e1, const eAnn3DChamferSymbolEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DChamferSymbolEnum;
extern PLMXML_ANNOTATION60_API eAnn3DChamferSymbolEnum eAnn3DChamferSymbolEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DChamferSymbolEnum eAnn3DChamferSymbolEnumSuffix;
extern PLMXML_ANNOTATION60_API eAnn3DChamferSymbolEnum eAnn3DChamferSymbolEnumPrefix;
extern PLMXML_ANNOTATION60_API eAnn3DChamferSymbolEnum eAnn3DChamferSymbolEnumNone;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionLineSplitEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionLineSplitEnumLimitFit
	"limitFit"
  eAnn3DDimensionLineSplitEnumNone
	"none"
  eAnn3DDimensionLineSplitEnumValueLimitFit
	"valueLimitFit"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionLineSplitEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionLineSplitEnum( const char* Type );
     
	//! Constructor
	eAnn3DDimensionLineSplitEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionLineSplitEnum( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionLineSplitEnum( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionLineSplitEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionLineSplitEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionLineSplitEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionLineSplitEnum& e1, const eAnn3DDimensionLineSplitEnum& e2 );
     
	//! Compare Ann3DDimensionLineSplitEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionLineSplitEnum& e1, const eAnn3DDimensionLineSplitEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionLineSplitEnum;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionLineSplitEnum eAnn3DDimensionLineSplitEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionLineSplitEnum eAnn3DDimensionLineSplitEnumLimitFit;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionLineSplitEnum eAnn3DDimensionLineSplitEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionLineSplitEnum eAnn3DDimensionLineSplitEnumValueLimitFit;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DNoteDisplayEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DNoteDisplayEnumFlatToScreen
	"flatToScreen"
  eAnn3DNoteDisplayEnumFlatToSurface
	"flatToSurface"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DNoteDisplayEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DNoteDisplayEnum( const char* Type );
     
	//! Constructor
	eAnn3DNoteDisplayEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DNoteDisplayEnum( );
     
	//! Destructor 
	virtual ~eAnn3DNoteDisplayEnum( );
     
	//! Assign from 'Type'
	const eAnn3DNoteDisplayEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DNoteDisplayEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DNoteDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DNoteDisplayEnum& e1, const eAnn3DNoteDisplayEnum& e2 );
     
	//! Compare Ann3DNoteDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DNoteDisplayEnum& e1, const eAnn3DNoteDisplayEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DNoteDisplayEnum;
extern PLMXML_ANNOTATION60_API eAnn3DNoteDisplayEnum eAnn3DNoteDisplayEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DNoteDisplayEnum eAnn3DNoteDisplayEnumFlatToScreen;
extern PLMXML_ANNOTATION60_API eAnn3DNoteDisplayEnum eAnn3DNoteDisplayEnumFlatToSurface;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDatumTerminatorEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DDatumTerminatorEnumX
	"x"
  eAnn3DDatumTerminatorEnumPlus
	"plus"
  eAnn3DDatumTerminatorEnumNone
	"none"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDatumTerminatorEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDatumTerminatorEnum( const char* Type );
     
	//! Constructor
	eAnn3DDatumTerminatorEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDatumTerminatorEnum( );
     
	//! Destructor 
	virtual ~eAnn3DDatumTerminatorEnum( );
     
	//! Assign from 'Type'
	const eAnn3DDatumTerminatorEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDatumTerminatorEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDatumTerminatorEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDatumTerminatorEnum& e1, const eAnn3DDatumTerminatorEnum& e2 );
     
	//! Compare Ann3DDatumTerminatorEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDatumTerminatorEnum& e1, const eAnn3DDatumTerminatorEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDatumTerminatorEnum;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTerminatorEnum eAnn3DDatumTerminatorEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTerminatorEnum eAnn3DDatumTerminatorEnumX;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTerminatorEnum eAnn3DDatumTerminatorEnumPlus;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTerminatorEnum eAnn3DDatumTerminatorEnumNone;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DeMarkingEnumType class
/*!
Allowed Values:
\verbatim
  eAnn3DeMarkingEnumTypeExportControl
	"exportControl"
  eAnn3DeMarkingEnumTypeProductProprietaryInfo
	"productProprietaryInfo"
  eAnn3DeMarkingEnumTypeGovernmentSecurityInfo
	"governmentSecurityInfo"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DeMarkingEnumType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DeMarkingEnumType( const char* Type );
     
	//! Constructor
	eAnn3DeMarkingEnumType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DeMarkingEnumType( );
     
	//! Destructor 
	virtual ~eAnn3DeMarkingEnumType( );
     
	//! Assign from 'Type'
	const eAnn3DeMarkingEnumType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DeMarkingEnumType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DeMarkingEnumType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DeMarkingEnumType& e1, const eAnn3DeMarkingEnumType& e2 );
     
	//! Compare Ann3DeMarkingEnumType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DeMarkingEnumType& e1, const eAnn3DeMarkingEnumType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DeMarkingEnumType;
extern PLMXML_ANNOTATION60_API eAnn3DeMarkingEnumType eAnn3DeMarkingEnumTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DeMarkingEnumType eAnn3DeMarkingEnumTypeExportControl;
extern PLMXML_ANNOTATION60_API eAnn3DeMarkingEnumType eAnn3DeMarkingEnumTypeProductProprietaryInfo;
extern PLMXML_ANNOTATION60_API eAnn3DeMarkingEnumType eAnn3DeMarkingEnumTypeGovernmentSecurityInfo;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DChamferDisplayEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DChamferDisplayEnumSymbol
	"symbol"
  eAnn3DChamferDisplayEnumSize
	"size"
  eAnn3DChamferDisplayEnumAngleSize
	"angleSize"
  eAnn3DChamferDisplayEnumSizeAngle
	"sizeAngle"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DChamferDisplayEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DChamferDisplayEnum( const char* Type );
     
	//! Constructor
	eAnn3DChamferDisplayEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DChamferDisplayEnum( );
     
	//! Destructor 
	virtual ~eAnn3DChamferDisplayEnum( );
     
	//! Assign from 'Type'
	const eAnn3DChamferDisplayEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DChamferDisplayEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DChamferDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DChamferDisplayEnum& e1, const eAnn3DChamferDisplayEnum& e2 );
     
	//! Compare Ann3DChamferDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DChamferDisplayEnum& e1, const eAnn3DChamferDisplayEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DChamferDisplayEnum;
extern PLMXML_ANNOTATION60_API eAnn3DChamferDisplayEnum eAnn3DChamferDisplayEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DChamferDisplayEnum eAnn3DChamferDisplayEnumSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DChamferDisplayEnum eAnn3DChamferDisplayEnumSize;
extern PLMXML_ANNOTATION60_API eAnn3DChamferDisplayEnum eAnn3DChamferDisplayEnumAngleSize;
extern PLMXML_ANNOTATION60_API eAnn3DChamferDisplayEnum eAnn3DChamferDisplayEnumSizeAngle;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionStubDirection class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionStubDirectionInferred
	"inferred"
  eAnn3DDimensionStubDirectionRight
	"right"
  eAnn3DDimensionStubDirectionLeft
	"left"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionStubDirection : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionStubDirection( const char* Type );
     
	//! Constructor
	eAnn3DDimensionStubDirection( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionStubDirection( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionStubDirection( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionStubDirection& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionStubDirection& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionStubDirection
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionStubDirection& e1, const eAnn3DDimensionStubDirection& e2 );
     
	//! Compare Ann3DDimensionStubDirection
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionStubDirection& e1, const eAnn3DDimensionStubDirection& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionStubDirection;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStubDirection eAnn3DDimensionStubDirectionUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStubDirection eAnn3DDimensionStubDirectionInferred;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStubDirection eAnn3DDimensionStubDirectionRight;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionStubDirection eAnn3DDimensionStubDirectionLeft;

////////////////////////////////////////////////////////////////////////////////////
//! eTextLineThicknessType class
/*!
Allowed Values:
\verbatim
  eTextLineThicknessTypeThick
	"thick"
  eTextLineThicknessTypeThin
	"thin"
  eTextLineThicknessTypeNormal
	"normal"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eTextLineThicknessType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTextLineThicknessType( const char* Type );
     
	//! Constructor
	eTextLineThicknessType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTextLineThicknessType( );
     
	//! Destructor 
	virtual ~eTextLineThicknessType( );
     
	//! Assign from 'Type'
	const eTextLineThicknessType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTextLineThicknessType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TextLineThicknessType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eTextLineThicknessType& e1, const eTextLineThicknessType& e2 );
     
	//! Compare TextLineThicknessType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eTextLineThicknessType& e1, const eTextLineThicknessType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTextLineThicknessType;
extern PLMXML_ANNOTATION60_API eTextLineThicknessType eTextLineThicknessTypeUnset;
extern PLMXML_ANNOTATION60_API eTextLineThicknessType eTextLineThicknessTypeThick;
extern PLMXML_ANNOTATION60_API eTextLineThicknessType eTextLineThicknessTypeThin;
extern PLMXML_ANNOTATION60_API eTextLineThicknessType eTextLineThicknessTypeNormal;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLimitDisplayEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLimitDisplayEnumNone
	"none"
  eAnn3DLimitDisplayEnumLimitFit
	"limitFit"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLimitDisplayEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLimitDisplayEnum( const char* Type );
     
	//! Constructor
	eAnn3DLimitDisplayEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLimitDisplayEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLimitDisplayEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLimitDisplayEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLimitDisplayEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLimitDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLimitDisplayEnum& e1, const eAnn3DLimitDisplayEnum& e2 );
     
	//! Compare Ann3DLimitDisplayEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLimitDisplayEnum& e1, const eAnn3DLimitDisplayEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLimitDisplayEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLimitDisplayEnum eAnn3DLimitDisplayEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLimitDisplayEnum eAnn3DLimitDisplayEnumNone;
extern PLMXML_ANNOTATION60_API eAnn3DLimitDisplayEnum eAnn3DLimitDisplayEnumLimitFit;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldFinishSymbol class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldFinishSymbolFinishing
	"finishing"
  eAnn3DLineWeldFinishSymbolPeening
	"peening"
  eAnn3DLineWeldFinishSymbolRolling
	"rolling"
  eAnn3DLineWeldFinishSymbolMachining
	"machining"
  eAnn3DLineWeldFinishSymbolHammering
	"hammering"
  eAnn3DLineWeldFinishSymbolNone
	"none"
  eAnn3DLineWeldFinishSymbolGrinding
	"grinding"
  eAnn3DLineWeldFinishSymbolChipping
	"chipping"
  eAnn3DLineWeldFinishSymbolUnspecified
	"unspecified"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldFinishSymbol( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldFinishSymbol( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldFinishSymbol( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldFinishSymbol( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldFinishSymbol& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldFinishSymbol& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldFinishSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldFinishSymbol& e1, const eAnn3DLineWeldFinishSymbol& e2 );
     
	//! Compare Ann3DLineWeldFinishSymbol
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldFinishSymbol& e1, const eAnn3DLineWeldFinishSymbol& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldFinishSymbol;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolFinishing;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolPeening;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolRolling;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolMachining;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolHammering;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolNone;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolGrinding;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolChipping;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldFinishSymbol eAnn3DLineWeldFinishSymbolUnspecified;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DArrowPlacementEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DArrowPlacementEnumBottomRight
	"bottomRight"
  eAnn3DArrowPlacementEnumOrigin
	"origin"
  eAnn3DArrowPlacementEnumTopRight
	"topRight"
  eAnn3DArrowPlacementEnumTop
	"top"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DArrowPlacementEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DArrowPlacementEnum( const char* Type );
     
	//! Constructor
	eAnn3DArrowPlacementEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DArrowPlacementEnum( );
     
	//! Destructor 
	virtual ~eAnn3DArrowPlacementEnum( );
     
	//! Assign from 'Type'
	const eAnn3DArrowPlacementEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DArrowPlacementEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DArrowPlacementEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DArrowPlacementEnum& e1, const eAnn3DArrowPlacementEnum& e2 );
     
	//! Compare Ann3DArrowPlacementEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DArrowPlacementEnum& e1, const eAnn3DArrowPlacementEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DArrowPlacementEnum;
extern PLMXML_ANNOTATION60_API eAnn3DArrowPlacementEnum eAnn3DArrowPlacementEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DArrowPlacementEnum eAnn3DArrowPlacementEnumBottomRight;
extern PLMXML_ANNOTATION60_API eAnn3DArrowPlacementEnum eAnn3DArrowPlacementEnumOrigin;
extern PLMXML_ANNOTATION60_API eAnn3DArrowPlacementEnum eAnn3DArrowPlacementEnumTopRight;
extern PLMXML_ANNOTATION60_API eAnn3DArrowPlacementEnum eAnn3DArrowPlacementEnumTop;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDimensionOrigin class
/*!
Allowed Values:
\verbatim
  eAnn3DDimensionOriginSecond
	"second"
  eAnn3DDimensionOriginFirst
	"first"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDimensionOrigin : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDimensionOrigin( const char* Type );
     
	//! Constructor
	eAnn3DDimensionOrigin( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDimensionOrigin( );
     
	//! Destructor 
	virtual ~eAnn3DDimensionOrigin( );
     
	//! Assign from 'Type'
	const eAnn3DDimensionOrigin& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDimensionOrigin& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDimensionOrigin
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDimensionOrigin& e1, const eAnn3DDimensionOrigin& e2 );
     
	//! Compare Ann3DDimensionOrigin
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDimensionOrigin& e1, const eAnn3DDimensionOrigin& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDimensionOrigin;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionOrigin eAnn3DDimensionOriginUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionOrigin eAnn3DDimensionOriginSecond;
extern PLMXML_ANNOTATION60_API eAnn3DDimensionOrigin eAnn3DDimensionOriginFirst;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DFCFProfileType class
/*!
Allowed Values:
\verbatim
  eAnn3DFCFProfileTypeBilateral
	"bilateral"
  eAnn3DFCFProfileTypeUnilateralInside
	"unilateralInside"
  eAnn3DFCFProfileTypeUnilateralOutside
	"unilateralOutside"
  eAnn3DFCFProfileTypeBilateralUnequal
	"bilateralUnequal"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DFCFProfileType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DFCFProfileType( const char* Type );
     
	//! Constructor
	eAnn3DFCFProfileType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DFCFProfileType( );
     
	//! Destructor 
	virtual ~eAnn3DFCFProfileType( );
     
	//! Assign from 'Type'
	const eAnn3DFCFProfileType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DFCFProfileType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DFCFProfileType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DFCFProfileType& e1, const eAnn3DFCFProfileType& e2 );
     
	//! Compare Ann3DFCFProfileType
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DFCFProfileType& e1, const eAnn3DFCFProfileType& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DFCFProfileType;
extern PLMXML_ANNOTATION60_API eAnn3DFCFProfileType eAnn3DFCFProfileTypeUnset;
extern PLMXML_ANNOTATION60_API eAnn3DFCFProfileType eAnn3DFCFProfileTypeBilateral;
extern PLMXML_ANNOTATION60_API eAnn3DFCFProfileType eAnn3DFCFProfileTypeUnilateralInside;
extern PLMXML_ANNOTATION60_API eAnn3DFCFProfileType eAnn3DFCFProfileTypeUnilateralOutside;
extern PLMXML_ANNOTATION60_API eAnn3DFCFProfileType eAnn3DFCFProfileTypeBilateralUnequal;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DTextPlaneOrientationEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DTextPlaneOrientationEnumPerpendicular
	"perpendicular"
  eAnn3DTextPlaneOrientationEnumParallel
	"parallel"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DTextPlaneOrientationEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DTextPlaneOrientationEnum( const char* Type );
     
	//! Constructor
	eAnn3DTextPlaneOrientationEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DTextPlaneOrientationEnum( );
     
	//! Destructor 
	virtual ~eAnn3DTextPlaneOrientationEnum( );
     
	//! Assign from 'Type'
	const eAnn3DTextPlaneOrientationEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DTextPlaneOrientationEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DTextPlaneOrientationEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DTextPlaneOrientationEnum& e1, const eAnn3DTextPlaneOrientationEnum& e2 );
     
	//! Compare Ann3DTextPlaneOrientationEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DTextPlaneOrientationEnum& e1, const eAnn3DTextPlaneOrientationEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DTextPlaneOrientationEnum;
extern PLMXML_ANNOTATION60_API eAnn3DTextPlaneOrientationEnum eAnn3DTextPlaneOrientationEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DTextPlaneOrientationEnum eAnn3DTextPlaneOrientationEnumPerpendicular;
extern PLMXML_ANNOTATION60_API eAnn3DTextPlaneOrientationEnum eAnn3DTextPlaneOrientationEnumParallel;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DDatumTargetAreaShapeEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DDatumTargetAreaShapeEnumSquare
	"square"
  eAnn3DDatumTargetAreaShapeEnumSphericalDiameter
	"sphericalDiameter"
  eAnn3DDatumTargetAreaShapeEnumDiameter
	"diameter"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DDatumTargetAreaShapeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DDatumTargetAreaShapeEnum( const char* Type );
     
	//! Constructor
	eAnn3DDatumTargetAreaShapeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DDatumTargetAreaShapeEnum( );
     
	//! Destructor 
	virtual ~eAnn3DDatumTargetAreaShapeEnum( );
     
	//! Assign from 'Type'
	const eAnn3DDatumTargetAreaShapeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DDatumTargetAreaShapeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DDatumTargetAreaShapeEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DDatumTargetAreaShapeEnum& e1, const eAnn3DDatumTargetAreaShapeEnum& e2 );
     
	//! Compare Ann3DDatumTargetAreaShapeEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DDatumTargetAreaShapeEnum& e1, const eAnn3DDatumTargetAreaShapeEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DDatumTargetAreaShapeEnum;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTargetAreaShapeEnum eAnn3DDatumTargetAreaShapeEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTargetAreaShapeEnum eAnn3DDatumTargetAreaShapeEnumSquare;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTargetAreaShapeEnum eAnn3DDatumTargetAreaShapeEnumSphericalDiameter;
extern PLMXML_ANNOTATION60_API eAnn3DDatumTargetAreaShapeEnum eAnn3DDatumTargetAreaShapeEnumDiameter;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DSurfaceFinish class
/*!
Allowed Values:
\verbatim
  eAnn3DSurfaceFinishBasic
	"basic"
  eAnn3DSurfaceFinishMRR
	"MRR"
  eAnn3DSurfaceFinishMRP
	"MRP"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DSurfaceFinish : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DSurfaceFinish( const char* Type );
     
	//! Constructor
	eAnn3DSurfaceFinish( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DSurfaceFinish( );
     
	//! Destructor 
	virtual ~eAnn3DSurfaceFinish( );
     
	//! Assign from 'Type'
	const eAnn3DSurfaceFinish& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DSurfaceFinish& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DSurfaceFinish
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DSurfaceFinish& e1, const eAnn3DSurfaceFinish& e2 );
     
	//! Compare Ann3DSurfaceFinish
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DSurfaceFinish& e1, const eAnn3DSurfaceFinish& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DSurfaceFinish;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinish eAnn3DSurfaceFinishUnset;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinish eAnn3DSurfaceFinishBasic;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinish eAnn3DSurfaceFinishMRR;
extern PLMXML_ANNOTATION60_API eAnn3DSurfaceFinish eAnn3DSurfaceFinishMRP;

////////////////////////////////////////////////////////////////////////////////////
//! eAnn3DLineWeldContourEnum class
/*!
Allowed Values:
\verbatim
  eAnn3DLineWeldContourEnumOpen
	"open"
  eAnn3DLineWeldContourEnumClosed
	"closed"
  eAnn3DLineWeldContourEnumTrilateral
	"trilateral"
  eAnn3DLineWeldContourEnumAllAround
	"allAround"
  
\endverbatim
*/
class PLMXML_ANNOTATION60_API eAnn3DLineWeldContourEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAnn3DLineWeldContourEnum( const char* Type );
     
	//! Constructor
	eAnn3DLineWeldContourEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAnn3DLineWeldContourEnum( );
     
	//! Destructor 
	virtual ~eAnn3DLineWeldContourEnum( );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldContourEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAnn3DLineWeldContourEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Ann3DLineWeldContourEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator==( const eAnn3DLineWeldContourEnum& e1, const eAnn3DLineWeldContourEnum& e2 );
     
	//! Compare Ann3DLineWeldContourEnum
	friend plmxml_api::logical PLMXML_ANNOTATION60_API operator!=( const eAnn3DLineWeldContourEnum& e1, const eAnn3DLineWeldContourEnum& e2 );
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAnn3DLineWeldContourEnum;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldContourEnum eAnn3DLineWeldContourEnumUnset;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldContourEnum eAnn3DLineWeldContourEnumOpen;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldContourEnum eAnn3DLineWeldContourEnumClosed;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldContourEnum eAnn3DLineWeldContourEnumTrilateral;
extern PLMXML_ANNOTATION60_API eAnn3DLineWeldContourEnum eAnn3DLineWeldContourEnumAllAround;

//! Forward class declarations
class Ann3DLeader;
class Ann3DTextFormat;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DDisplay class
/*!
\verbatim

      The base type for types describing how to display an
      Annotation3D element.

      Attributes:

      blanked:         true if this Display is marked as not to
                       be displayed at the moment.
      units:           specifies which units lengths will be displayed in. This
                       attribute is deprecated in favour of unitRef.
      symbolColour:    colour of the lines in the symbol.
      layer:           layer on which to display (deprecated - use the Layer Property instead)
      textOrigin:      3D vector describing the location of the top
                       left corner of the text window, in model
                       space, in metres.
      textDirection:   3D direction of the text, in the display
                       plane.
      textBox:         whether a box is drawn around the symbol. (Deprecated.
                       Use an AnnotationOutline referenced by outlineRef
                       instead.)
      outlineRef:      reference to an AnnotationOutline element which specifies the
                       outline of the Annotation.

      attachmentType:  method of display (leader, stacked, as a radial dimension, etc )
      symbolicDisplayRef: reference to a Representation which can be
                       considered as a symbolic representation of
                       the Annotation.

      annotation3DRef: the Annotation3D being displayed (deprecated)
      commaAsDecimal:  Whether the decimal separator is represented by a
                       full-stop or a comma.
      flag:            Whether any Leader sub-elements attach to the Annotation
                       as flags.
      unitRef:         References a Unit, which specifies the units lengths will
                       be displayed in. If absent, the units in the referencing
                       ProductRevision or ProductRevisionView (if any) will be
                       used. If still absent, millimetres will be assumed. Note
                       this does not affect lengths in the PLMXML file - these
                       are always in metres.
      prime:           Whether the Annotation is displayed by virtue of it
                       referencing "prime" or "reference" geometry.
      originAnchor:    The point that the origin attribute on the DisplayPlane
                       sub-element defines.
      parallelToScreen: Whether the Annotation is always displayed parallel to
                       the screen.
      panZoom:         If parallelToScreen is true, panZoom indicates whether
                       the Annotation participates in pan and zoom operations.
      textRotationPoint: Specifies the location of the text rotation point in
                       model space in metres. As the user rotates the Annotation
                       in a view, a viewing application may rotate its text
                       about one or two axes to ensure it remains readable.
                       Those axes pass through the text rotation point and lie
                       parallel with the X axis or the Y axis of the display
                       plane.
      stackFactor:     The gap to the target annotation in the direction of the
                       stack as a factor of textHeight. Relevant only if
                       attachmentType is stacked (below), stackedLeft,
                       stackedRight or stackedAbove.

      Elements:

      DisplayPlane:    The plane on which the Annotation is
                       displayed. If no plane is provided then it is
                       up to the application to choose a plane.

      Leader:          Zero or more leader-line specifications

      Geometry:        Zero or more ConstructionGeometry sub-elements. These
                       are alternative visual representations of the Annotation. These
                       can contain Points or Curves. If these are 2D, then they
                       lie in the DisplayPlane.
      TextFormat:      Formatting attributes for special characters and symbols.
                       Applies generally to all text fields.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DDisplay : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DDisplay( );
     
    //! Constructs a Ann3DDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DDisplay();

private:

	//! Assignment operator
	Ann3DDisplay& operator=( const Ann3DDisplay& iSrc );

	//! Copy constructor
	Ann3DDisplay( const Ann3DDisplay& original );
     
public:

	//! Get Outline URI as plmxml_api::String
	plmxml_api::String GetOutlineURI() const;

	//! Set Outline URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOutlineURI( const plmxml_api::String& );
	
	//! Get the handle of Outline URI. Does not resolve the URI.
	plmxml_api::Result GetOutlineURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Outline URI. URI string is unchanged.
	plmxml_api::Result SetOutlineURI( const plmxml_api::Handle& );
	
	//! Resolve Outline URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOutlineURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Outline URI. Clears URI string and handle.
	plmxml_api::Result DeleteOutlineURI();
	
	//! Check if Outline URI is set
	plmxml_api::logical HasOutlineURI( ) const;
	

	//! Get Unit URI as plmxml_api::String
	plmxml_api::String GetUnitURI() const;

	//! Set Unit URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUnitURI( const plmxml_api::String& );
	
	//! Get the handle of Unit URI. Does not resolve the URI.
	plmxml_api::Result GetUnitURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Unit URI. URI string is unchanged.
	plmxml_api::Result SetUnitURI( const plmxml_api::Handle& );
	
	//! Resolve Unit URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUnitURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Unit URI. Clears URI string and handle.
	plmxml_api::Result DeleteUnitURI();
	
	//! Check if Unit URI is set
	plmxml_api::logical HasUnitURI( ) const;
	

	//! Set Strikethrough
	plmxml_api::Result SetStrikethrough( const eAnn3DTextStrikethroughEnum& arg );

	//! Get Strikethrough
	eAnn3DTextStrikethroughEnum GetStrikethrough() const;

	//! Set Units
	plmxml_api::Result SetUnits( const plmxml60::ePreferredPartUnitsType& arg );

	//! Get Units
	plmxml60::ePreferredPartUnitsType GetUnits() const;

	//! Set Flag
	plmxml_api::Result SetFlag( plmxml_api::logical arg );

	//! Get Flag
	plmxml_api::logical GetFlag() const;

	//! Check if Flag is set
	plmxml_api::logical HasFlag() const;

	//! Unset Flag
	plmxml_api::Result UnsetFlag();

	//! Set TextColour array
	plmxml_api::Result SetTextColour( const double *arg );

	//! Get TextColour array
	plmxml_api::Result GetTextColour( double *arg ) const;

	//! Check if TextColour array is set
	plmxml_api::logical HasTextColour() const;

	//! Unset TextColour array
	plmxml_api::Result UnsetTextColour();

	//! Set Italic
	plmxml_api::Result SetItalic( plmxml_api::logical arg );

	//! Get Italic
	plmxml_api::logical GetItalic() const;

	//! Check if Italic is set
	plmxml_api::logical HasItalic() const;

	//! Unset Italic
	plmxml_api::Result UnsetItalic();

	//! Get SymbolicDisplay URI as plmxml_api::String
	plmxml_api::String GetSymbolicDisplayURI() const;

	//! Set SymbolicDisplay URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSymbolicDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of SymbolicDisplay URI. Does not resolve the URI.
	plmxml_api::Result GetSymbolicDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of SymbolicDisplay URI. URI string is unchanged.
	plmxml_api::Result SetSymbolicDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve SymbolicDisplay URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSymbolicDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset SymbolicDisplay URI. Clears URI string and handle.
	plmxml_api::Result DeleteSymbolicDisplayURI();
	
	//! Check if SymbolicDisplay URI is set
	plmxml_api::logical HasSymbolicDisplayURI( ) const;
	

	//! Set PanZoom
	plmxml_api::Result SetPanZoom( plmxml_api::logical arg );

	//! Get PanZoom
	plmxml_api::logical GetPanZoom() const;

	//! Check if PanZoom is set
	plmxml_api::logical HasPanZoom() const;

	//! Unset PanZoom
	plmxml_api::Result UnsetPanZoom();

	//! Set Justification
	plmxml_api::Result SetJustification( const eTextJustificationType& arg );

	//! Get Justification
	eTextJustificationType GetJustification() const;

	//! Set Prime
	plmxml_api::Result SetPrime( plmxml_api::logical arg );

	//! Get Prime
	plmxml_api::logical GetPrime() const;

	//! Check if Prime is set
	plmxml_api::logical HasPrime() const;

	//! Unset Prime
	plmxml_api::Result UnsetPrime();

	//! Set TextOrigin using plmxml_api::Vector components
	plmxml_api::Result SetTextOrigin( const plmxml_api::Vector& arg );

	//! Get TextOrigin as plmxml_api::Vector
	plmxml_api::Result GetTextOrigin( plmxml_api::Vector& arg ) const;

	//! Check if TextOrigin is set
	plmxml_api::logical HasTextOrigin() const;

	//! Unset TextOrigin
	plmxml_api::Result UnsetTextOrigin();

	//! Set LineFactor
	plmxml_api::Result SetLineFactor( double arg );

     //! Get LineFactor
	double GetLineFactor() const;

	//! Check if LineFactor is set
	plmxml_api::logical HasLineFactor() const;

	//! Unset LineFactor
	plmxml_api::Result UnsetLineFactor();

	//! Set TextHeight
	plmxml_api::Result SetTextHeight( double arg );

     //! Get TextHeight
	double GetTextHeight() const;

	//! Check if TextHeight is set
	plmxml_api::logical HasTextHeight() const;

	//! Unset TextHeight
	plmxml_api::Result UnsetTextHeight();

	//! Set ParallelToScreen
	plmxml_api::Result SetParallelToScreen( plmxml_api::logical arg );

	//! Get ParallelToScreen
	plmxml_api::logical GetParallelToScreen() const;

	//! Check if ParallelToScreen is set
	plmxml_api::logical HasParallelToScreen() const;

	//! Unset ParallelToScreen
	plmxml_api::Result UnsetParallelToScreen();

	//! Set TextDirection using plmxml_api::Vector components
	plmxml_api::Result SetTextDirection( const plmxml_api::Vector& arg );

	//! Get TextDirection as plmxml_api::Vector
	plmxml_api::Result GetTextDirection( plmxml_api::Vector& arg ) const;

	//! Check if TextDirection is set
	plmxml_api::logical HasTextDirection() const;

	//! Unset TextDirection
	plmxml_api::Result UnsetTextDirection();

	//! Set TextBox
	plmxml_api::Result SetTextBox( plmxml_api::logical arg );

	//! Get TextBox
	plmxml_api::logical GetTextBox() const;

	//! Check if TextBox is set
	plmxml_api::logical HasTextBox() const;

	//! Unset TextBox
	plmxml_api::Result UnsetTextBox();

	//! Get TextLineWidth URI as plmxml_api::String
	plmxml_api::String GetTextLineWidthURI() const;

	//! Set TextLineWidth URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::String& );
	
	//! Get the handle of TextLineWidth URI. Does not resolve the URI.
	plmxml_api::Result GetTextLineWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TextLineWidth URI. URI string is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::Handle& );
	
	//! Resolve TextLineWidth URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTextLineWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TextLineWidth URI. Clears URI string and handle.
	plmxml_api::Result DeleteTextLineWidthURI();
	
	//! Check if TextLineWidth URI is set
	plmxml_api::logical HasTextLineWidthURI( ) const;
	

	//! Get Language of this Ann3DDisplay
	plmxml_api::String GetLanguage() const;

	//! Set Language of this Ann3DDisplay
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Set Layer
	plmxml_api::Result SetLayer( int arg );
     
	//! Get Layer
	int GetLayer() const;
     
	//! Check if Layer is set
	plmxml_api::logical HasLayer() const;
     
	//! Unset Layer
	plmxml_api::Result UnsetLayer();

	//! Get Font of this Ann3DDisplay
	plmxml_api::String GetFont() const;

	//! Set Font of this Ann3DDisplay
	plmxml_api::Result SetFont( const plmxml_api::String &s );
	
	//! Check if Font is set
	plmxml_api::logical HasFont( ) const;
	
	//! Unset Font
	plmxml_api::Result UnsetFont( );

	//! Set TextRotationPoint using plmxml_api::Vector components
	plmxml_api::Result SetTextRotationPoint( const plmxml_api::Vector& arg );

	//! Get TextRotationPoint as plmxml_api::Vector
	plmxml_api::Result GetTextRotationPoint( plmxml_api::Vector& arg ) const;

	//! Check if TextRotationPoint is set
	plmxml_api::logical HasTextRotationPoint() const;

	//! Unset TextRotationPoint
	plmxml_api::Result UnsetTextRotationPoint();

	//! Set OriginAnchor
	plmxml_api::Result SetOriginAnchor( const eAnn3DOriginAnchorEnum& arg );

	//! Get OriginAnchor
	eAnn3DOriginAnchorEnum GetOriginAnchor() const;

	//! Set reference to Annotation3D using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetAnnotation3DRef( plmxml60::IdObject *arg );

	//! Clear reference to Annotation3D
	void RemoveAnnotation3DRef( );

	//! Find a plmxml60::IdObject referenced by Annotation3D
	plmxml60::IdObject *ResolveAnnotation3DRef( plmxml_api::Configuration* config = NULL );

	//! Get Annotation3D reference
	plmxml_api::String GetAnnotation3DId() const;

	//! Set Annotation3D reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetAnnotation3DId( const plmxml_api::String& u );
	
	//! Check if Annotation3D is set
	plmxml_api::logical HasAnnotation3DRef( ) const;

	//! Set Underline
	plmxml_api::Result SetUnderline( const eTextUnderlineType& arg );

	//! Get Underline
	eTextUnderlineType GetUnderline() const;

	//! Set Bold
	plmxml_api::Result SetBold( plmxml_api::logical arg );

	//! Get Bold
	plmxml_api::logical GetBold() const;

	//! Check if Bold is set
	plmxml_api::logical HasBold() const;

	//! Unset Bold
	plmxml_api::Result UnsetBold();

	//! Set Blanked
	plmxml_api::Result SetBlanked( plmxml_api::logical arg );

	//! Get Blanked
	plmxml_api::logical GetBlanked() const;

	//! Check if Blanked is set
	plmxml_api::logical HasBlanked() const;

	//! Unset Blanked
	plmxml_api::Result UnsetBlanked();

	//! Set Subscript
	plmxml_api::Result SetSubscript( const eAnn3DTextSubscriptEnum& arg );

	//! Get Subscript
	eAnn3DTextSubscriptEnum GetSubscript() const;

	//! Set TextThickness
	plmxml_api::Result SetTextThickness( const eTextLineThicknessType& arg );

	//! Get TextThickness
	eTextLineThicknessType GetTextThickness() const;

	//! Set AttachmentType
	plmxml_api::Result SetAttachmentType( const eAnn3DAttachment& arg );

	//! Get AttachmentType
	eAnn3DAttachment GetAttachmentType() const;

	//! Set TextAspect
	plmxml_api::Result SetTextAspect( double arg );

     //! Get TextAspect
	double GetTextAspect() const;

	//! Check if TextAspect is set
	plmxml_api::logical HasTextAspect() const;

	//! Unset TextAspect
	plmxml_api::Result UnsetTextAspect();

	//! Set CommaAsDecimal
	plmxml_api::Result SetCommaAsDecimal( plmxml_api::logical arg );

	//! Get CommaAsDecimal
	plmxml_api::logical GetCommaAsDecimal() const;

	//! Check if CommaAsDecimal is set
	plmxml_api::logical HasCommaAsDecimal() const;

	//! Unset CommaAsDecimal
	plmxml_api::Result UnsetCommaAsDecimal();

	//! Set TextLineWidth
	plmxml_api::Result SetTextLineWidth( double arg );

     //! Get TextLineWidth
	double GetTextLineWidth() const;

	//! Check if TextLineWidth is set
	plmxml_api::logical HasTextLineWidth() const;

	//! Unset TextLineWidth
	plmxml_api::Result UnsetTextLineWidth();

	//! Set StackFactor
	plmxml_api::Result SetStackFactor( double arg );

     //! Get StackFactor
	double GetStackFactor() const;

	//! Check if StackFactor is set
	plmxml_api::logical HasStackFactor() const;

	//! Unset StackFactor
	plmxml_api::Result UnsetStackFactor();

	//! Set SymbolColour array
	plmxml_api::Result SetSymbolColour( const double *arg );

	//! Get SymbolColour array
	plmxml_api::Result GetSymbolColour( double *arg ) const;

	//! Check if SymbolColour array is set
	plmxml_api::logical HasSymbolColour() const;

	//! Unset SymbolColour array
	plmxml_api::Result UnsetSymbolColour();

	//! Set ItalicAngle
	plmxml_api::Result SetItalicAngle( double arg );

     //! Get ItalicAngle
	double GetItalicAngle() const;

	//! Check if ItalicAngle is set
	plmxml_api::logical HasItalicAngle() const;

	//! Unset ItalicAngle
	plmxml_api::Result UnsetItalicAngle();

	//! Set SpaceFactor
	plmxml_api::Result SetSpaceFactor( double arg );

     //! Get SpaceFactor
	double GetSpaceFactor() const;

	//! Check if SpaceFactor is set
	plmxml_api::logical HasSpaceFactor() const;

	//! Unset SpaceFactor
	plmxml_api::Result UnsetSpaceFactor();

	//! Add DisplayPlane child element to this Ann3DDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddDisplayPlane();
     
	//! Set DisplayPlane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDisplayPlane( Plane *arg );
     
	//! Get DisplayPlane child element of this Ann3DDisplay.
	Plane *GetDisplayPlane() const;
     
	//! Detach and delete DisplayPlane child element tree from this Ann3DDisplay.
	void DeleteDisplayPlane();

	//! Add Leader child element to this Ann3DDisplay. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DLeader *AddLeader();
     
	//! Add 'arg' as Leader child element to this Ann3DDisplay.
	plmxml_api::Result AddLeader( Ann3DLeader *arg );

	//! Detach and delete all Leader child elements.
	void DeleteLeaders();
     
	//! Get number of Leader child elements.
	int NumberOfLeaders() const;
     
	//! Get i'th Leader child element.
	Ann3DLeader *GetLeader( int i ) const;
     
	//! Get all Leader child element as an array
	void GetLeaders( plmxml_api::Array<Ann3DLeader*> &array ) const;
	     
	//! Detach and delete i'th Leader child element
	void DeleteLeader( int i );
     
	//! Detach and delete 'arg' if it's one of the Leader child elements
	void DeleteLeader( Ann3DLeader *arg );

	//! Add Geometry child element to this Ann3DDisplay. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstructionGeometry *AddGeometry();
     
	//! Add 'arg' as Geometry child element to this Ann3DDisplay.
	plmxml_api::Result AddGeometry( ConstructionGeometry *arg );

	//! Detach and delete all Geometry child elements.
	void DeleteGeometries();
     
	//! Get number of Geometry child elements.
	int NumberOfGeometries() const;
     
	//! Get i'th Geometry child element.
	ConstructionGeometry *GetGeometry( int i ) const;
     
	//! Get all Geometry child element as an array
	void GetGeometries( plmxml_api::Array<ConstructionGeometry*> &array ) const;
	     
	//! Detach and delete i'th Geometry child element
	void DeleteGeometry( int i );
     
	//! Detach and delete 'arg' if it's one of the Geometry child elements
	void DeleteGeometry( ConstructionGeometry *arg );

	//! Add TextFormat child element to this Ann3DDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTextFormat *AddTextFormat();
     
	//! Set TextFormat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTextFormat( Ann3DTextFormat *arg );
     
	//! Get TextFormat child element of this Ann3DDisplay.
	Ann3DTextFormat *GetTextFormat() const;
     
	//! Detach and delete TextFormat child element tree from this Ann3DDisplay.
	void DeleteTextFormat();
 
// <PLMXML_UserCode type="functionHeaderAnn3DDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Annotation3D class
/*!
\verbatim

      Annotation3D: the abstract base type for all 3D Annotations

      Attributes:

      accountabilityId:
      group:            This is an application specific type used as part of a
                        classification scheme for the annotations.
      usage:            used to indicate a usage other than that expected.
      uriRefs:          associated URI references
      stringRep:        A simplified string representation of the annotation,
                        often used for validation.

      Elements:

      Reference:        Deprecated. This is for legacy import only, and
                        specifies the entities the Annotation3D refers to.
      SafetyClassification: This is an application specific type used to
                        indicate the importance of an annotation, e.g. minor,
                        major, critical.
      ValueToCustomer:  This is an application specific type used to indicate
                        the value of an annotation to a customer, e.g. "critical
                        to quality".
      Keyword:          a keyword string (may contain spaces).
      FeatureIdentification: An application specific identifier for a relevant
                        feature.
      RevisionModifier: Application-specific meta-data relating to the revision.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Annotation3D : public GDE
{
public:
     
    //! Default constructor
    Annotation3D( );
     
    //! Constructs a Annotation3D with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Annotation3D( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Annotation3D();

private:

	//! Assignment operator
	Annotation3D& operator=( const Annotation3D& iSrc );

	//! Copy constructor
	Annotation3D( const Annotation3D& original );
     
public:

	//! Get number of URIs in Uri
	int NumberOfUriURIs() const;

	//! Get i'th URI in Uri
	plmxml_api::String GetUriURI( int i ) const;

	//! Add a URI to Uri array. Call ResolveUriURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddUriURI( const plmxml_api::String& u );

	//! Set i'th URI in Uri array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetUriURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Uri URI. Does not resolve the URI.
	plmxml_api::Result GetUriURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Uri array.
	plmxml_api::Result AddUriURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Uri array to point to 'handle'.
	plmxml_api::Result SetUriURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Uri points to.
	plmxml_api::Result ResolveUriURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Uri array.
	plmxml_api::Result DeleteUriURI( int i );

	//! Remove all URIs from Uri array.
	plmxml_api::Result DeleteUriURIs( );
	
	//! Check if Uri is set
	plmxml_api::logical HasUriURIs( ) const;

	//! Get Usage of this Annotation3D
	plmxml_api::String GetUsage() const;

	//! Set Usage of this Annotation3D
	plmxml_api::Result SetUsage( const plmxml_api::String &s );
	
	//! Check if Usage is set
	plmxml_api::logical HasUsage( ) const;
	
	//! Unset Usage
	plmxml_api::Result UnsetUsage( );

	//! Get Group of this Annotation3D
	plmxml_api::String GetGroup() const;

	//! Set Group of this Annotation3D
	plmxml_api::Result SetGroup( const plmxml_api::String &s );
	
	//! Check if Group is set
	plmxml_api::logical HasGroup( ) const;
	
	//! Unset Group
	plmxml_api::Result UnsetGroup( );

	//! Get StringRep of this Annotation3D
	plmxml_api::String GetStringRep() const;

	//! Set StringRep of this Annotation3D
	plmxml_api::Result SetStringRep( const plmxml_api::String &s );
	
	//! Check if StringRep is set
	plmxml_api::logical HasStringRep( ) const;
	
	//! Unset StringRep
	plmxml_api::Result UnsetStringRep( );

	//! Set AccountabilityId
	plmxml_api::Result SetAccountabilityId( int arg );
     
	//! Get AccountabilityId
	int GetAccountabilityId() const;
     
	//! Check if AccountabilityId is set
	plmxml_api::logical HasAccountabilityId() const;
     
	//! Unset AccountabilityId
	plmxml_api::Result UnsetAccountabilityId();

	//! Add Keyword child element to this Annotation3D. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StringField *AddKeyword();
     
	//! Add 'arg' as Keyword child element to this Annotation3D.
	plmxml_api::Result AddKeyword( StringField *arg );

	//! Detach and delete all Keyword child elements.
	void DeleteKeywords();
     
	//! Get number of Keyword child elements.
	int NumberOfKeywords() const;
     
	//! Get i'th Keyword child element.
	StringField *GetKeyword( int i ) const;
     
	//! Get all Keyword child element as an array
	void GetKeywords( plmxml_api::Array<StringField*> &array ) const;
	     
	//! Detach and delete i'th Keyword child element
	void DeleteKeyword( int i );
     
	//! Detach and delete 'arg' if it's one of the Keyword child elements
	void DeleteKeyword( StringField *arg );

	//! Add SafetyClassification child element to this Annotation3D. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserEnum *AddSafetyClassification();
     
	//! Set SafetyClassification child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSafetyClassification( UserEnum *arg );
     
	//! Get SafetyClassification child element of this Annotation3D.
	UserEnum *GetSafetyClassification() const;
     
	//! Detach and delete SafetyClassification child element tree from this Annotation3D.
	void DeleteSafetyClassification();

	//! Add ValueToCustomer child element to this Annotation3D. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserEnum *AddValueToCustomer();
     
	//! Set ValueToCustomer child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueToCustomer( UserEnum *arg );
     
	//! Get ValueToCustomer child element of this Annotation3D.
	UserEnum *GetValueToCustomer() const;
     
	//! Detach and delete ValueToCustomer child element tree from this Annotation3D.
	void DeleteValueToCustomer();

	//! Add Reference child element to this Annotation3D. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddReference();
     
	//! Add 'arg' as Reference child element to this Annotation3D.
	plmxml_api::Result AddReference( GDEReference *arg );

	//! Detach and delete all Reference child elements.
	void DeleteReferences();
     
	//! Get number of Reference child elements.
	int NumberOfReferences() const;
     
	//! Get i'th Reference child element.
	GDEReference *GetReference( int i ) const;
     
	//! Get all Reference child element as an array
	void GetReferences( plmxml_api::Array<GDEReference*> &array ) const;
	     
	//! Detach and delete i'th Reference child element
	void DeleteReference( int i );
     
	//! Detach and delete 'arg' if it's one of the Reference child elements
	void DeleteReference( GDEReference *arg );

	//! Add FeatureIdentification child element to this Annotation3D. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserEnum *AddFeatureIdentification();
     
	//! Set FeatureIdentification child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFeatureIdentification( UserEnum *arg );
     
	//! Get FeatureIdentification child element of this Annotation3D.
	UserEnum *GetFeatureIdentification() const;
     
	//! Detach and delete FeatureIdentification child element tree from this Annotation3D.
	void DeleteFeatureIdentification();

	//! Get RevisionModifier of this Annotation3D
	plmxml_api::String GetRevisionModifier() const;

	//! Set RevisionModifier of this Annotation3D
	plmxml_api::Result SetRevisionModifier( const plmxml_api::String &s );
	
	//! Check if RevisionModifier is set
	plmxml_api::logical HasRevisionModifier( ) const;
	
	//! Unset RevisionModifier
	plmxml_api::Result UnsetRevisionModifier( );
 
// <PLMXML_UserCode type="functionHeaderAnnotation3D" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnnotation3D;


//! Forward class declarations
class Ann3DRegionAreaReference;
class Ann3DIntersectionReference;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DInstance class
/*!
\verbatim

      An Instance of an Annotation3D.

      Attributes:

      dimensionStandard:      standard to use for dimensions (and
                              other annotations which use the same
                              standards enum)
      surfaceFinishStandard:  standard to use for surface finishes
      lineWeldStandard:       standard to use for line welds
      displayRef:             a reference to an element, derived from Ann3DDisplayType,
                              which specifies how this instance is to be displayed.
      valid:                  Whether the PMI is valid, invalid or unknown at
                              the time of export.
      associatedFeatureGroup: The collective name for the targets of the
                              Reference sub-elements.
      stringRep:              A simplified string representation of the
                              annotation, often used for validation.

      These attributes are used to over-ride default values set for
      a containing Ann3DInstanceGroup.

      Sub-elements:

      RegionAreaReference:    References a face that defines an Area and the
                              Area that it defines when the Ann3DInstance
                              instances an Ann3DRegion.
      Ann3DIntersectionReference: References an intersection of 2 entities.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DInstance : public GDEInstance
{
public:
     
    //! Default constructor
    Ann3DInstance( );
     
    //! Constructs a Ann3DInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DInstance();

private:

	//! Assignment operator
	Ann3DInstance& operator=( const Ann3DInstance& iSrc );

	//! Copy constructor
	Ann3DInstance( const Ann3DInstance& original );
     
public:

	//! Set Valid
	plmxml_api::Result SetValid( const plmxml60::eTriStateBooleanEnum& arg );

	//! Get Valid
	plmxml60::eTriStateBooleanEnum GetValid() const;

	//! Set DimensionStandard
	plmxml_api::Result SetDimensionStandard( const eAnn3DDimensionStandardType& arg );

	//! Get DimensionStandard
	eAnn3DDimensionStandardType GetDimensionStandard() const;

	//! Get StringRep of this Ann3DInstance
	plmxml_api::String GetStringRep() const;

	//! Set StringRep of this Ann3DInstance
	plmxml_api::Result SetStringRep( const plmxml_api::String &s );
	
	//! Check if StringRep is set
	plmxml_api::logical HasStringRep( ) const;
	
	//! Unset StringRep
	plmxml_api::Result UnsetStringRep( );

	//! Get AssociatedFeatureGroup of this Ann3DInstance
	plmxml_api::String GetAssociatedFeatureGroup() const;

	//! Set AssociatedFeatureGroup of this Ann3DInstance
	plmxml_api::Result SetAssociatedFeatureGroup( const plmxml_api::String &s );
	
	//! Check if AssociatedFeatureGroup is set
	plmxml_api::logical HasAssociatedFeatureGroup( ) const;
	
	//! Unset AssociatedFeatureGroup
	plmxml_api::Result UnsetAssociatedFeatureGroup( );

	//! Set SurfaceFinishStandard
	plmxml_api::Result SetSurfaceFinishStandard( const eAnn3DSurfaceFinishStandardType& arg );

	//! Get SurfaceFinishStandard
	eAnn3DSurfaceFinishStandardType GetSurfaceFinishStandard() const;

	//! Set LineWeldStandard
	plmxml_api::Result SetLineWeldStandard( const eAnn3DLineWeldStandardType& arg );

	//! Get LineWeldStandard
	eAnn3DLineWeldStandardType GetLineWeldStandard() const;

	//! Get Display URI as plmxml_api::String
	plmxml_api::String GetDisplayURI() const;

	//! Set Display URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of Display URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Display URI. URI string is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve Display URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Display URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayURI();
	
	//! Check if Display URI is set
	plmxml_api::logical HasDisplayURI( ) const;
	

	//! Add RegionAreaReference child element to this Ann3DInstance. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DRegionAreaReference *AddRegionAreaReference();
     
	//! Add 'arg' as RegionAreaReference child element to this Ann3DInstance.
	plmxml_api::Result AddRegionAreaReference( Ann3DRegionAreaReference *arg );

	//! Detach and delete all RegionAreaReference child elements.
	void DeleteRegionAreaReferences();
     
	//! Get number of RegionAreaReference child elements.
	int NumberOfRegionAreaReferences() const;
     
	//! Get i'th RegionAreaReference child element.
	Ann3DRegionAreaReference *GetRegionAreaReference( int i ) const;
     
	//! Get all RegionAreaReference child element as an array
	void GetRegionAreaReferences( plmxml_api::Array<Ann3DRegionAreaReference*> &array ) const;
	     
	//! Detach and delete i'th RegionAreaReference child element
	void DeleteRegionAreaReference( int i );
     
	//! Detach and delete 'arg' if it's one of the RegionAreaReference child elements
	void DeleteRegionAreaReference( Ann3DRegionAreaReference *arg );

	//! Add Ann3DIntersectionReference child element to this Ann3DInstance. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DIntersectionReference *AddAnn3DIntersectionReference();
     
	//! Add 'arg' as Ann3DIntersectionReference child element to this Ann3DInstance.
	plmxml_api::Result AddAnn3DIntersectionReference( Ann3DIntersectionReference *arg );

	//! Detach and delete all Ann3DIntersectionReference child elements.
	void DeleteAnn3DIntersectionReferences();
     
	//! Get number of Ann3DIntersectionReference child elements.
	int NumberOfAnn3DIntersectionReferences() const;
     
	//! Get i'th Ann3DIntersectionReference child element.
	Ann3DIntersectionReference *GetAnn3DIntersectionReference( int i ) const;
     
	//! Get all Ann3DIntersectionReference child element as an array
	void GetAnn3DIntersectionReferences( plmxml_api::Array<Ann3DIntersectionReference*> &array ) const;
	     
	//! Detach and delete i'th Ann3DIntersectionReference child element
	void DeleteAnn3DIntersectionReference( int i );
     
	//! Detach and delete 'arg' if it's one of the Ann3DIntersectionReference child elements
	void DeleteAnn3DIntersectionReference( Ann3DIntersectionReference *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DInstance;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DVirtualInstance class
/*!
\verbatim

      An Ann3DInstance that can appear only as part of another Annotation3D.
      They are never displayed in their own right.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DVirtualInstance : public Ann3DInstance
{
public:
     
    //! Default constructor
    Ann3DVirtualInstance( );
     
    //! Constructs a Ann3DVirtualInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DVirtualInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DVirtualInstance();

private:

	//! Assignment operator
	Ann3DVirtualInstance& operator=( const Ann3DVirtualInstance& iSrc );

	//! Copy constructor
	Ann3DVirtualInstance( const Ann3DVirtualInstance& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DVirtualInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DVirtualInstance;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DInstanceGroup class
/*!
\verbatim

      Ann3DInstanceGroup.

      This element is used to collect together a number of
      Ann3DInstance elements to simplify referencing and allow the
      specification of default values for appropriate standards

      Attributes:
      
      dimensionStandard:      standard to use for dimensions (and
                              other annotations which use the same
                              standards enum)
      surfaceFinishStandard:  standard to use for surface finishes
      lineWeldStandard:       standard to use for line welds
      
      displayRef:             a reference to an element, derived from Ann3DDisplayType,
                              which specifies how the instances in this group are
                              to be displayed.
                              
      The above attributes may be overridden by attributes of the same name on the
      Ann3DInstance sub-elements.

      Elements:
      
      This element inherits 'GDEInstance' sub-elements from its parent type, 
      GDEInstanceGroupType. These sub-elements should all be of type
      Ann3DInstanceType.      
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DInstanceGroup : public GDEInstanceGroup
{
public:
     
    //! Default constructor
    Ann3DInstanceGroup( );
     
    //! Constructs a Ann3DInstanceGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DInstanceGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DInstanceGroup();

private:

	//! Assignment operator
	Ann3DInstanceGroup& operator=( const Ann3DInstanceGroup& iSrc );

	//! Copy constructor
	Ann3DInstanceGroup( const Ann3DInstanceGroup& original );
     
public:

	//! Get Display URI as plmxml_api::String
	plmxml_api::String GetDisplayURI() const;

	//! Set Display URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of Display URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Display URI. URI string is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve Display URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Display URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayURI();
	
	//! Check if Display URI is set
	plmxml_api::logical HasDisplayURI( ) const;
	

	//! Set SurfaceFinishStandard
	plmxml_api::Result SetSurfaceFinishStandard( const eAnn3DSurfaceFinishStandardType& arg );

	//! Get SurfaceFinishStandard
	eAnn3DSurfaceFinishStandardType GetSurfaceFinishStandard() const;

	//! Set DimensionStandard
	plmxml_api::Result SetDimensionStandard( const eAnn3DDimensionStandardType& arg );

	//! Get DimensionStandard
	eAnn3DDimensionStandardType GetDimensionStandard() const;

	//! Set LineWeldStandard
	plmxml_api::Result SetLineWeldStandard( const eAnn3DLineWeldStandardType& arg );

	//! Get LineWeldStandard
	eAnn3DLineWeldStandardType GetLineWeldStandard() const;
 
// <PLMXML_UserCode type="functionHeaderAnn3DInstanceGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DInstanceGroup;


//! Forward class declarations
class Ann3DRegionAreaReference;
class Ann3DIntersectionReference;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DOccurrence class
/*!
\verbatim

      An Occurrence of an Annotation3D.

      Attributes:

      displayRef:             a reference to an element, derived from Ann3DDisplayType,
                              which specifies how this occurrence is to be displayed.
      valid:                  Whether the PMI is valid, invalid or unknown at
                              the time of export.

      These attributes are used to over-ride default values set for Ann3DInstance(Group).

      Sub-elements:

      RegionAreaReference:    References a face that defines an Area and the
                              Area that it defines when the Ann3DOccurrence is
                              an occurrence of an Ann3DRegion.
      Ann3DIntersectionReference: References an intersection of 2 entities.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DOccurrence : public Occurrence
{
public:
     
    //! Default constructor
    Ann3DOccurrence( );
     
    //! Constructs a Ann3DOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DOccurrence();

private:

	//! Assignment operator
	Ann3DOccurrence& operator=( const Ann3DOccurrence& iSrc );

	//! Copy constructor
	Ann3DOccurrence( const Ann3DOccurrence& original );
     
public:

	//! Set Valid
	plmxml_api::Result SetValid( const plmxml60::eTriStateBooleanEnum& arg );

	//! Get Valid
	plmxml60::eTriStateBooleanEnum GetValid() const;

	//! Get Display URI as plmxml_api::String
	plmxml_api::String GetDisplayURI() const;

	//! Set Display URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of Display URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Display URI. URI string is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve Display URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Display URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayURI();
	
	//! Check if Display URI is set
	plmxml_api::logical HasDisplayURI( ) const;
	

	//! Add RegionAreaReference child element to this Ann3DOccurrence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DRegionAreaReference *AddRegionAreaReference();
     
	//! Add 'arg' as RegionAreaReference child element to this Ann3DOccurrence.
	plmxml_api::Result AddRegionAreaReference( Ann3DRegionAreaReference *arg );

	//! Detach and delete all RegionAreaReference child elements.
	void DeleteRegionAreaReferences();
     
	//! Get number of RegionAreaReference child elements.
	int NumberOfRegionAreaReferences() const;
     
	//! Get i'th RegionAreaReference child element.
	Ann3DRegionAreaReference *GetRegionAreaReference( int i ) const;
     
	//! Get all RegionAreaReference child element as an array
	void GetRegionAreaReferences( plmxml_api::Array<Ann3DRegionAreaReference*> &array ) const;
	     
	//! Detach and delete i'th RegionAreaReference child element
	void DeleteRegionAreaReference( int i );
     
	//! Detach and delete 'arg' if it's one of the RegionAreaReference child elements
	void DeleteRegionAreaReference( Ann3DRegionAreaReference *arg );

	//! Add Ann3DIntersectionReference child element to this Ann3DOccurrence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DIntersectionReference *AddAnn3DIntersectionReference();
     
	//! Add 'arg' as Ann3DIntersectionReference child element to this Ann3DOccurrence.
	plmxml_api::Result AddAnn3DIntersectionReference( Ann3DIntersectionReference *arg );

	//! Detach and delete all Ann3DIntersectionReference child elements.
	void DeleteAnn3DIntersectionReferences();
     
	//! Get number of Ann3DIntersectionReference child elements.
	int NumberOfAnn3DIntersectionReferences() const;
     
	//! Get i'th Ann3DIntersectionReference child element.
	Ann3DIntersectionReference *GetAnn3DIntersectionReference( int i ) const;
     
	//! Get all Ann3DIntersectionReference child element as an array
	void GetAnn3DIntersectionReferences( plmxml_api::Array<Ann3DIntersectionReference*> &array ) const;
	     
	//! Detach and delete i'th Ann3DIntersectionReference child element
	void DeleteAnn3DIntersectionReference( int i );
     
	//! Detach and delete 'arg' if it's one of the Ann3DIntersectionReference child elements
	void DeleteAnn3DIntersectionReference( Ann3DIntersectionReference *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DOutlineStyle class
/*!
\verbatim

      Specifies the style of an individual line of an Annotation or Text Outline.

      Attributes:

      colour:           The colour of the line.
      style:            The line style of the line.
      thickness:        The thickness of the line.
      widthRef:         References a LineWidth, which specifies the thickness of
                        the line quantitatively.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DOutlineStyle : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DOutlineStyle( );
     
    //! Constructs a Ann3DOutlineStyle with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DOutlineStyle( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DOutlineStyle();

private:

	//! Assignment operator
	Ann3DOutlineStyle& operator=( const Ann3DOutlineStyle& iSrc );

	//! Copy constructor
	Ann3DOutlineStyle( const Ann3DOutlineStyle& original );
     
public:

	//! Set Colour array
	plmxml_api::Result SetColour( const double *arg );

	//! Get Colour array
	plmxml_api::Result GetColour( double *arg ) const;

	//! Check if Colour array is set
	plmxml_api::logical HasColour() const;

	//! Unset Colour array
	plmxml_api::Result UnsetColour();

	//! Set Style
	plmxml_api::Result SetStyle( const eAnn3DLineType& arg );

	//! Get Style
	eAnn3DLineType GetStyle() const;

	//! Set Thickness
	plmxml_api::Result SetThickness( const eTextLineThicknessType& arg );

	//! Get Thickness
	eTextLineThicknessType GetThickness() const;

	//! Get Width URI as plmxml_api::String
	plmxml_api::String GetWidthURI() const;

	//! Set Width URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::String& );
	
	//! Get the handle of Width URI. Does not resolve the URI.
	plmxml_api::Result GetWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Width URI. URI string is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::Handle& );
	
	//! Resolve Width URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Width URI. Clears URI string and handle.
	plmxml_api::Result DeleteWidthURI();
	
	//! Check if Width URI is set
	plmxml_api::logical HasWidthURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderAnn3DOutlineStyle" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DOutlineStyle;


////////////////////////////////////////////////////////////////////////////////////
//! AnnotationOutline class
/*!
\verbatim

      Specifies the shape of an Annotation or Text Outline.

      Attributes:

      type:             One of "box", "triangle", "circle", "ellipse",
                        "underline", etc.
                        Note that "underline" refers to the place where the
                        bottom edge of a "box" outline would be placed. It is
                        not the same as underlining the text by means of
                        underline="true".
      colour:           The colour of the outline. Overridden by Top, Bottom,
                        Left or Right sub-elements.
      style:            The line style of the outline. Overridden by Top,
                        Bottom, Left or Right sub-elements.
      thickness:        The line thickness of the outline. Overridden by Top,
                        Bottom, Left or Right sub-elements.
      widthRef:         References a LineWidth, which specifies the thickness of
                        the outline quantitatively. Overridden by Top, Bottom,
                        Left or Right sub-elements.
      doubleOffset:     The offset of any double outline in metres.
      visible:          Whether the line of the outline is visible. Often false
                        if the outline is filled.
      filled:           Whether the outline is filled.
      fillColour:       The fill colour, if the outline is filled. Otherwise
                        transparent.

      Sub-elements:

      Top:              The style of the top of a "box" outline. Overrides
                        colour, style, thickness and widthRef attributes.
      Bottom:           The style of the bottom of a "box" outline. Overrides
                        colour, style, thickness and widthRef attributes.
      Left:             The style of the left of a "box" outline. Overrides
                        colour, style, thickness and widthRef attributes.
      Right:            The style of the right of a "box" outline. Overrides
                        colour, style, thickness and widthRef attributes.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API AnnotationOutline : public AttribOwner
{
public:
     
    //! Default constructor
    AnnotationOutline( );
     
    //! Constructs a AnnotationOutline with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AnnotationOutline( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AnnotationOutline();

private:

	//! Assignment operator
	AnnotationOutline& operator=( const AnnotationOutline& iSrc );

	//! Copy constructor
	AnnotationOutline( const AnnotationOutline& original );
     
public:

	//! Set Colour array
	plmxml_api::Result SetColour( const double *arg );

	//! Get Colour array
	plmxml_api::Result GetColour( double *arg ) const;

	//! Check if Colour array is set
	plmxml_api::logical HasColour() const;

	//! Unset Colour array
	plmxml_api::Result UnsetColour();

	//! Set DoubleOffset
	plmxml_api::Result SetDoubleOffset( double arg );

     //! Get DoubleOffset
	double GetDoubleOffset() const;

	//! Check if DoubleOffset is set
	plmxml_api::logical HasDoubleOffset() const;

	//! Unset DoubleOffset
	plmxml_api::Result UnsetDoubleOffset();

	//! Set Style
	plmxml_api::Result SetStyle( const eAnn3DLineType& arg );

	//! Get Style
	eAnn3DLineType GetStyle() const;

	//! Set Thickness
	plmxml_api::Result SetThickness( const eTextLineThicknessType& arg );

	//! Get Thickness
	eTextLineThicknessType GetThickness() const;

	//! Set Visible
	plmxml_api::Result SetVisible( plmxml_api::logical arg );

	//! Get Visible
	plmxml_api::logical GetVisible() const;

	//! Check if Visible is set
	plmxml_api::logical HasVisible() const;

	//! Unset Visible
	plmxml_api::Result UnsetVisible();

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DOutlineEnum& arg );

	//! Get Type
	eAnn3DOutlineEnum GetType() const;

	//! Set Filled
	plmxml_api::Result SetFilled( plmxml_api::logical arg );

	//! Get Filled
	plmxml_api::logical GetFilled() const;

	//! Check if Filled is set
	plmxml_api::logical HasFilled() const;

	//! Unset Filled
	plmxml_api::Result UnsetFilled();

	//! Get Width URI as plmxml_api::String
	plmxml_api::String GetWidthURI() const;

	//! Set Width URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::String& );
	
	//! Get the handle of Width URI. Does not resolve the URI.
	plmxml_api::Result GetWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Width URI. URI string is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::Handle& );
	
	//! Resolve Width URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Width URI. Clears URI string and handle.
	plmxml_api::Result DeleteWidthURI();
	
	//! Check if Width URI is set
	plmxml_api::logical HasWidthURI( ) const;
	

	//! Set FillColour array
	plmxml_api::Result SetFillColour( const double *arg );

	//! Get FillColour array
	plmxml_api::Result GetFillColour( double *arg ) const;

	//! Check if FillColour array is set
	plmxml_api::logical HasFillColour() const;

	//! Unset FillColour array
	plmxml_api::Result UnsetFillColour();

	//! Add Top child element to this AnnotationOutline. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DOutlineStyle *AddTop();
     
	//! Set Top child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTop( Ann3DOutlineStyle *arg );
     
	//! Get Top child element of this AnnotationOutline.
	Ann3DOutlineStyle *GetTop() const;
     
	//! Detach and delete Top child element tree from this AnnotationOutline.
	void DeleteTop();

	//! Add Bottom child element to this AnnotationOutline. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DOutlineStyle *AddBottom();
     
	//! Set Bottom child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetBottom( Ann3DOutlineStyle *arg );
     
	//! Get Bottom child element of this AnnotationOutline.
	Ann3DOutlineStyle *GetBottom() const;
     
	//! Detach and delete Bottom child element tree from this AnnotationOutline.
	void DeleteBottom();

	//! Add Left child element to this AnnotationOutline. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DOutlineStyle *AddLeft();
     
	//! Set Left child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLeft( Ann3DOutlineStyle *arg );
     
	//! Get Left child element of this AnnotationOutline.
	Ann3DOutlineStyle *GetLeft() const;
     
	//! Detach and delete Left child element tree from this AnnotationOutline.
	void DeleteLeft();

	//! Add Right child element to this AnnotationOutline. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DOutlineStyle *AddRight();
     
	//! Set Right child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRight( Ann3DOutlineStyle *arg );
     
	//! Get Right child element of this AnnotationOutline.
	Ann3DOutlineStyle *GetRight() const;
     
	//! Detach and delete Right child element tree from this AnnotationOutline.
	void DeleteRight();
 
// <PLMXML_UserCode type="functionHeaderAnnotationOutline" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnnotationOutline;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTextItem class
/*!
\verbatim

      This element can represent a formatted text string, a string with a type
      (e.g. a real number), or a symbol.

      This is derived from xsd:string, so it has string element content

      Attributes:

      symbol:           if this attribute is present, its value specifies the
                        symbol which this text item represents (e.g.
                        "centreline"). In this case, the element content is
                        ignored. If "symbol" is used, "lineWeldSymbol" and
                        "lineWeldSupplementalSymbol" should not be used.
      lineWeldSymbol:   A symbol from the "Ann3DLineWeldSymbol" set. If
                        "lineWeldSymbol" is used, "symbol" and
                        "lineWeldSupplementalSymbol" should not be used.
      lineWeldSupplementalSymbol: A symbol from the
                        "Ann3DLineWeldSupplementalSymbol" set. If
                        "lineWeldSupplementalSymbol" is used, "symbol" and
                        "lineWeldSymbol" should not be used.

      format:           if present, this attribute specifies the format (type)
                        of the text, e.g. "int", "real", "boolean".

      outlineRef:       reference to an AnnotationOutline element which
                        specifies the outline of the Text Item.

      The TextGroup attributes override any attributes of the same name in the
      enclosing Ann3DTextType element.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTextItem : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DTextItem( );
     
    //! Constructs a Ann3DTextItem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTextItem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTextItem();

private:

	//! Assignment operator
	Ann3DTextItem& operator=( const Ann3DTextItem& iSrc );

	//! Copy constructor
	Ann3DTextItem( const Ann3DTextItem& original );
     
public:

	//! Set ItalicAngle
	plmxml_api::Result SetItalicAngle( double arg );

     //! Get ItalicAngle
	double GetItalicAngle() const;

	//! Check if ItalicAngle is set
	plmxml_api::logical HasItalicAngle() const;

	//! Unset ItalicAngle
	plmxml_api::Result UnsetItalicAngle();

	//! Set SpaceFactor
	plmxml_api::Result SetSpaceFactor( double arg );

     //! Get SpaceFactor
	double GetSpaceFactor() const;

	//! Check if SpaceFactor is set
	plmxml_api::logical HasSpaceFactor() const;

	//! Unset SpaceFactor
	plmxml_api::Result UnsetSpaceFactor();

	//! Set Italic
	plmxml_api::Result SetItalic( plmxml_api::logical arg );

	//! Get Italic
	plmxml_api::logical GetItalic() const;

	//! Check if Italic is set
	plmxml_api::logical HasItalic() const;

	//! Unset Italic
	plmxml_api::Result UnsetItalic();

	//! Set Bold
	plmxml_api::Result SetBold( plmxml_api::logical arg );

	//! Get Bold
	plmxml_api::logical GetBold() const;

	//! Check if Bold is set
	plmxml_api::logical HasBold() const;

	//! Unset Bold
	plmxml_api::Result UnsetBold();

	//! Set Underline
	plmxml_api::Result SetUnderline( const eTextUnderlineType& arg );

	//! Get Underline
	eTextUnderlineType GetUnderline() const;

	//! Set LineFactor
	plmxml_api::Result SetLineFactor( double arg );

     //! Get LineFactor
	double GetLineFactor() const;

	//! Check if LineFactor is set
	plmxml_api::logical HasLineFactor() const;

	//! Unset LineFactor
	plmxml_api::Result UnsetLineFactor();

	//! Set LineWeldSymbol
	plmxml_api::Result SetLineWeldSymbol( const eAnn3DLineWeldSymbol& arg );

	//! Get LineWeldSymbol
	eAnn3DLineWeldSymbol GetLineWeldSymbol() const;

	//! Get TextLineWidth URI as plmxml_api::String
	plmxml_api::String GetTextLineWidthURI() const;

	//! Set TextLineWidth URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::String& );
	
	//! Get the handle of TextLineWidth URI. Does not resolve the URI.
	plmxml_api::Result GetTextLineWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TextLineWidth URI. URI string is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::Handle& );
	
	//! Resolve TextLineWidth URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTextLineWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TextLineWidth URI. Clears URI string and handle.
	plmxml_api::Result DeleteTextLineWidthURI();
	
	//! Check if TextLineWidth URI is set
	plmxml_api::logical HasTextLineWidthURI( ) const;
	

	//! Set TextThickness
	plmxml_api::Result SetTextThickness( const eTextLineThicknessType& arg );

	//! Get TextThickness
	eTextLineThicknessType GetTextThickness() const;

	//! Set Symbol
	plmxml_api::Result SetSymbol( const eAnn3DTextSymbol& arg );

	//! Get Symbol
	eAnn3DTextSymbol GetSymbol() const;

	//! Get Outline URI as plmxml_api::String
	plmxml_api::String GetOutlineURI() const;

	//! Set Outline URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOutlineURI( const plmxml_api::String& );
	
	//! Get the handle of Outline URI. Does not resolve the URI.
	plmxml_api::Result GetOutlineURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Outline URI. URI string is unchanged.
	plmxml_api::Result SetOutlineURI( const plmxml_api::Handle& );
	
	//! Resolve Outline URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOutlineURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Outline URI. Clears URI string and handle.
	plmxml_api::Result DeleteOutlineURI();
	
	//! Check if Outline URI is set
	plmxml_api::logical HasOutlineURI( ) const;
	

	//! Set Strikethrough
	plmxml_api::Result SetStrikethrough( const eAnn3DTextStrikethroughEnum& arg );

	//! Get Strikethrough
	eAnn3DTextStrikethroughEnum GetStrikethrough() const;

	//! Set TextColour array
	plmxml_api::Result SetTextColour( const double *arg );

	//! Get TextColour array
	plmxml_api::Result GetTextColour( double *arg ) const;

	//! Check if TextColour array is set
	plmxml_api::logical HasTextColour() const;

	//! Unset TextColour array
	plmxml_api::Result UnsetTextColour();

	//! Set Subscript
	plmxml_api::Result SetSubscript( const eAnn3DTextSubscriptEnum& arg );

	//! Get Subscript
	eAnn3DTextSubscriptEnum GetSubscript() const;

	//! Set Justification
	plmxml_api::Result SetJustification( const eTextJustificationType& arg );

	//! Get Justification
	eTextJustificationType GetJustification() const;

	//! Set Format
	plmxml_api::Result SetFormat( const plmxml60::eUserValueDataType& arg );

	//! Get Format
	plmxml60::eUserValueDataType GetFormat() const;

	//! Get Font of this Ann3DTextItem
	plmxml_api::String GetFont() const;

	//! Set Font of this Ann3DTextItem
	plmxml_api::Result SetFont( const plmxml_api::String &s );
	
	//! Check if Font is set
	plmxml_api::logical HasFont( ) const;
	
	//! Unset Font
	plmxml_api::Result UnsetFont( );

	//! Set LineWeldSupplementalSymbol
	plmxml_api::Result SetLineWeldSupplementalSymbol( const eAnn3DLineWeldSupplementalSymbol& arg );

	//! Get LineWeldSupplementalSymbol
	eAnn3DLineWeldSupplementalSymbol GetLineWeldSupplementalSymbol() const;

	//! Set TextHeight
	plmxml_api::Result SetTextHeight( double arg );

     //! Get TextHeight
	double GetTextHeight() const;

	//! Check if TextHeight is set
	plmxml_api::logical HasTextHeight() const;

	//! Unset TextHeight
	plmxml_api::Result UnsetTextHeight();

	//! Set TextLineWidth
	plmxml_api::Result SetTextLineWidth( double arg );

     //! Get TextLineWidth
	double GetTextLineWidth() const;

	//! Check if TextLineWidth is set
	plmxml_api::logical HasTextLineWidth() const;

	//! Unset TextLineWidth
	plmxml_api::Result UnsetTextLineWidth();

	//! Get Language of this Ann3DTextItem
	plmxml_api::String GetLanguage() const;

	//! Set Language of this Ann3DTextItem
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Set TextAspect
	plmxml_api::Result SetTextAspect( double arg );

     //! Get TextAspect
	double GetTextAspect() const;

	//! Check if TextAspect is set
	plmxml_api::logical HasTextAspect() const;

	//! Unset TextAspect
	plmxml_api::Result UnsetTextAspect();
 
// <PLMXML_UserCode type="functionHeaderAnn3DTextItem" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTextItem;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DText class
/*!
\verbatim

      A Text block, i.e. a sequence of text items. Each item may be
      simple text, text with a type (e.g. a real number), or a symbol.

      Attributes:

      textOrientation:  orientation of the characters with respect to each other.
      name:             the name of the Text block. This can be used to indicate some
                        particular significance of the text.
      outlineRef:       reference to an AnnotationOutline element which specifies the outline
                        of the Text block.
      textGroup attributes:
                        The TextGroup attributes act as defaults which are overridden
                        by attributes of the same name in the text items (and override
                        any attributes of the same name in a referencing
                        Annotation3DDisplay element).
      maxExtend:        Whether any underlining extends to the full length of
                        the longest item of text of an Annotation.

      Elements:

      Item:             at least one Ann3DTextItemType sub-element
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DText : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DText( );
     
    //! Constructs a Ann3DText with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DText( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DText();

private:

	//! Assignment operator
	Ann3DText& operator=( const Ann3DText& iSrc );

	//! Copy constructor
	Ann3DText( const Ann3DText& original );
     
public:

	//! Set ItalicAngle
	plmxml_api::Result SetItalicAngle( double arg );

     //! Get ItalicAngle
	double GetItalicAngle() const;

	//! Check if ItalicAngle is set
	plmxml_api::logical HasItalicAngle() const;

	//! Unset ItalicAngle
	plmxml_api::Result UnsetItalicAngle();

	//! Set SpaceFactor
	plmxml_api::Result SetSpaceFactor( double arg );

     //! Get SpaceFactor
	double GetSpaceFactor() const;

	//! Check if SpaceFactor is set
	plmxml_api::logical HasSpaceFactor() const;

	//! Unset SpaceFactor
	plmxml_api::Result UnsetSpaceFactor();

	//! Set Bold
	plmxml_api::Result SetBold( plmxml_api::logical arg );

	//! Get Bold
	plmxml_api::logical GetBold() const;

	//! Check if Bold is set
	plmxml_api::logical HasBold() const;

	//! Unset Bold
	plmxml_api::Result UnsetBold();

	//! Set Underline
	plmxml_api::Result SetUnderline( const eTextUnderlineType& arg );

	//! Get Underline
	eTextUnderlineType GetUnderline() const;

	//! Set LineFactor
	plmxml_api::Result SetLineFactor( double arg );

     //! Get LineFactor
	double GetLineFactor() const;

	//! Check if LineFactor is set
	plmxml_api::logical HasLineFactor() const;

	//! Unset LineFactor
	plmxml_api::Result UnsetLineFactor();

	//! Get Language of this Ann3DText
	plmxml_api::String GetLanguage() const;

	//! Set Language of this Ann3DText
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Set TextThickness
	plmxml_api::Result SetTextThickness( const eTextLineThicknessType& arg );

	//! Get TextThickness
	eTextLineThicknessType GetTextThickness() const;

	//! Set MaxExtend
	plmxml_api::Result SetMaxExtend( plmxml_api::logical arg );

	//! Get MaxExtend
	plmxml_api::logical GetMaxExtend() const;

	//! Check if MaxExtend is set
	plmxml_api::logical HasMaxExtend() const;

	//! Unset MaxExtend
	plmxml_api::Result UnsetMaxExtend();

	//! Get TextLineWidth URI as plmxml_api::String
	plmxml_api::String GetTextLineWidthURI() const;

	//! Set TextLineWidth URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::String& );
	
	//! Get the handle of TextLineWidth URI. Does not resolve the URI.
	plmxml_api::Result GetTextLineWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TextLineWidth URI. URI string is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::Handle& );
	
	//! Resolve TextLineWidth URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTextLineWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TextLineWidth URI. Clears URI string and handle.
	plmxml_api::Result DeleteTextLineWidthURI();
	
	//! Check if TextLineWidth URI is set
	plmxml_api::logical HasTextLineWidthURI( ) const;
	

	//! Set Italic
	plmxml_api::Result SetItalic( plmxml_api::logical arg );

	//! Get Italic
	plmxml_api::logical GetItalic() const;

	//! Check if Italic is set
	plmxml_api::logical HasItalic() const;

	//! Unset Italic
	plmxml_api::Result UnsetItalic();

	//! Get Outline URI as plmxml_api::String
	plmxml_api::String GetOutlineURI() const;

	//! Set Outline URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOutlineURI( const plmxml_api::String& );
	
	//! Get the handle of Outline URI. Does not resolve the URI.
	plmxml_api::Result GetOutlineURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Outline URI. URI string is unchanged.
	plmxml_api::Result SetOutlineURI( const plmxml_api::Handle& );
	
	//! Resolve Outline URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOutlineURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Outline URI. Clears URI string and handle.
	plmxml_api::Result DeleteOutlineURI();
	
	//! Check if Outline URI is set
	plmxml_api::logical HasOutlineURI( ) const;
	

	//! Set Strikethrough
	plmxml_api::Result SetStrikethrough( const eAnn3DTextStrikethroughEnum& arg );

	//! Get Strikethrough
	eAnn3DTextStrikethroughEnum GetStrikethrough() const;

	//! Set TextColour array
	plmxml_api::Result SetTextColour( const double *arg );

	//! Get TextColour array
	plmxml_api::Result GetTextColour( double *arg ) const;

	//! Check if TextColour array is set
	plmxml_api::logical HasTextColour() const;

	//! Unset TextColour array
	plmxml_api::Result UnsetTextColour();

	//! Set Subscript
	plmxml_api::Result SetSubscript( const eAnn3DTextSubscriptEnum& arg );

	//! Get Subscript
	eAnn3DTextSubscriptEnum GetSubscript() const;

	//! Set Justification
	plmxml_api::Result SetJustification( const eTextJustificationType& arg );

	//! Get Justification
	eTextJustificationType GetJustification() const;

	//! Set TextOrientation
	plmxml_api::Result SetTextOrientation( const eAnn3DTextOrientationType& arg );

	//! Get TextOrientation
	eAnn3DTextOrientationType GetTextOrientation() const;

	//! Get Font of this Ann3DText
	plmxml_api::String GetFont() const;

	//! Set Font of this Ann3DText
	plmxml_api::Result SetFont( const plmxml_api::String &s );
	
	//! Check if Font is set
	plmxml_api::logical HasFont( ) const;
	
	//! Unset Font
	plmxml_api::Result UnsetFont( );

	//! Set TextHeight
	plmxml_api::Result SetTextHeight( double arg );

     //! Get TextHeight
	double GetTextHeight() const;

	//! Check if TextHeight is set
	plmxml_api::logical HasTextHeight() const;

	//! Unset TextHeight
	plmxml_api::Result UnsetTextHeight();

	//! Set TextLineWidth
	plmxml_api::Result SetTextLineWidth( double arg );

     //! Get TextLineWidth
	double GetTextLineWidth() const;

	//! Check if TextLineWidth is set
	plmxml_api::logical HasTextLineWidth() const;

	//! Unset TextLineWidth
	plmxml_api::Result UnsetTextLineWidth();

	//! Get Name of this Ann3DText
	plmxml_api::String GetName() const;

	//! Set Name of this Ann3DText
	plmxml_api::Result SetName( const plmxml_api::String &s );
	
	//! Check if Name is set
	plmxml_api::logical HasName( ) const;
	
	//! Unset Name
	plmxml_api::Result UnsetName( );

	//! Set TextAspect
	plmxml_api::Result SetTextAspect( double arg );

     //! Get TextAspect
	double GetTextAspect() const;

	//! Check if TextAspect is set
	plmxml_api::logical HasTextAspect() const;

	//! Unset TextAspect
	plmxml_api::Result UnsetTextAspect();

	//! Add Item child element to this Ann3DText. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTextItem *AddItem();
     
	//! Add 'arg' as Item child element to this Ann3DText.
	plmxml_api::Result AddItem( Ann3DTextItem *arg );

	//! Detach and delete all Item child elements.
	void DeleteItems();
     
	//! Get number of Item child elements.
	int NumberOfItems() const;
     
	//! Get i'th Item child element.
	Ann3DTextItem *GetItem( int i ) const;
     
	//! Get all Item child element as an array
	void GetItems( plmxml_api::Array<Ann3DTextItem*> &array ) const;
	     
	//! Detach and delete i'th Item child element
	void DeleteItem( int i );
     
	//! Detach and delete 'arg' if it's one of the Item child elements
	void DeleteItem( Ann3DTextItem *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DText" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DText;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DLeader class
/*!
\verbatim

      Ann3DLeaderType: data describing the position, colour, etc, of a leader line

      Attributes:

      referenceRef:    references the Reference element which references the entity
                         being annotated
      tParm:           t-parameter on the referenced edge or curve, if applicable
      uvParms:         u,v-parameters on the referenced face or surface, if applicable
      terminator:      3D position of the end of the leader. This, and the next two
                       attributes, are not relevant if explicit leader geometry is given as a
                       sub-element.
      stubDirection:   left or right, initial direction of leader. Overridden
                       by direction.
      stubLength:      length of first segment of leader (metres)
      colour:          leader colour
      lineType:        solid, dashed, dotted, etc
      thickness:       thin, normal or thick
      arrowType:       shape of arrowhead
      arrowColour:     colour of arrowhead
      arrowLineType:   solid, dashed, dotted etc
      arrowThickness:  thin, normal or thick
      arrowAngle:      total angle, in radians, at tip of arrow (0 to pi)
      arrowLength:     length of the arrow
      dotDiameter:        diameter of dot, in metres, if applicable
      arrowPlacement:     in, or out. Refers to arrows inside or outside extension lines
      arrowOutsideLength: length of segment of leader on outside arrows
      lineTextGap:        gap (metres) between text and start of leader
      extensionLineGap:   gap (metres) between extension line and model geometry
      extensionLineExtension:  length of the portion of the extension line which extends beyond
                               the dimension line
      extensionColour     extension line colour
      extensionLineType:  solid, etc
      extensionThickness: thin, normal or thick
      radiusToCentre:   Whether the Leader sub-element under a DimensionDisplay
                        of a Dimension of type radial is drawn to the centre of
                        the measured geometry.
      widthRef:         References a LineWidth, which specifies the thickness of
                        the leader quantitatively.
      arrowWidthRef:    References a LineWidth, which specifies the thickness of
                        the arrow quantitatively.
      extensionWidthRef: References a LineWidth, which specifies the thickness
                        of the extension quantitatively.
      perpendicularToStub: Whether the Leader is maintained perpendicular to its
                        stub.
      perpendicularToTerminator: Whether the rest of the Leader is maintained
                        perpendicular to its termination geometry (which is
                        given by referenceRef).
      leaderAttachment: The vertical position where the Leader attaches to the
                        Annotation.
      extensionJogging: Whether the extension line is jogged.
      extensionJogDefinition: How the jogged extension line is defined.
      extensionJogOut:  Whether the jogged extension line is jogged inwards or
                        outwards.
      extensionJogStart: The start of the jogged extension line.
      extensionJogEnd:  The end of the jogged extension line.
      extensionJogAngle: The angle of the jogged extension line.
      suppressed:       Whether the leader is suppressed. For example, a
                        Dimension may have one leader present and the other
                        suppressed.
      offsetCentre:     Whether referenceRef and terminator relate to the offset
                        centre of a folded radius Dimension.
      allAroundSymbolSize: The diameter of any allAround symbol.
      halfArrow:        Whether only the left or the right side of the
                        arrowhead, looking in the direction of the arrow, is
                        displayed. By default, both sides are displayed.
      direction:        The direction of the leader from terminator. Overrides
                        stubDirection.
      textOverStubFactor: The location of any text over the stub of the Leader
                        relative to the text height.
      textOverLeaderFactor: The location of any text over the Leader itself
                        relative to the text height.
      stubAttachment:   The vertical position where the stub of the Leader
                        attaches to a text item of an Annotation.

      Elements:

      Curve:              Leader line geometry represented via a
                          polyline. The schema allows other curve types for expansion.
      Jog:                The position of a jog in the leader.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DLeader : public IdObject
{
public:
     
    //! Default constructor
    Ann3DLeader( );
     
    //! Constructs a Ann3DLeader with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DLeader( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DLeader();

private:

	//! Assignment operator
	Ann3DLeader& operator=( const Ann3DLeader& iSrc );

	//! Copy constructor
	Ann3DLeader( const Ann3DLeader& original );
     
public:

	//! Set TextOverStubFactor
	plmxml_api::Result SetTextOverStubFactor( double arg );

     //! Get TextOverStubFactor
	double GetTextOverStubFactor() const;

	//! Check if TextOverStubFactor is set
	plmxml_api::logical HasTextOverStubFactor() const;

	//! Unset TextOverStubFactor
	plmxml_api::Result UnsetTextOverStubFactor();

	//! Set LineType
	plmxml_api::Result SetLineType( const eAnn3DLineType& arg );

	//! Get LineType
	eAnn3DLineType GetLineType() const;

	//! Get Width URI as plmxml_api::String
	plmxml_api::String GetWidthURI() const;

	//! Set Width URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::String& );
	
	//! Get the handle of Width URI. Does not resolve the URI.
	plmxml_api::Result GetWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Width URI. URI string is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::Handle& );
	
	//! Resolve Width URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Width URI. Clears URI string and handle.
	plmxml_api::Result DeleteWidthURI();
	
	//! Check if Width URI is set
	plmxml_api::logical HasWidthURI( ) const;
	

	//! Set RadiusToCentre
	plmxml_api::Result SetRadiusToCentre( plmxml_api::logical arg );

	//! Get RadiusToCentre
	plmxml_api::logical GetRadiusToCentre() const;

	//! Check if RadiusToCentre is set
	plmxml_api::logical HasRadiusToCentre() const;

	//! Unset RadiusToCentre
	plmxml_api::Result UnsetRadiusToCentre();

	//! Set DotDiameter
	plmxml_api::Result SetDotDiameter( double arg );

     //! Get DotDiameter
	double GetDotDiameter() const;

	//! Check if DotDiameter is set
	plmxml_api::logical HasDotDiameter() const;

	//! Unset DotDiameter
	plmxml_api::Result UnsetDotDiameter();

	//! Set ArrowLineType
	plmxml_api::Result SetArrowLineType( const eAnn3DLineType& arg );

	//! Get ArrowLineType
	eAnn3DLineType GetArrowLineType() const;

	//! Set UvParms array
	plmxml_api::Result SetUvParms( const double *arg );

	//! Get UvParms array
	plmxml_api::Result GetUvParms( double *arg ) const;

	//! Check if UvParms array is set
	plmxml_api::logical HasUvParms() const;

	//! Unset UvParms array
	plmxml_api::Result UnsetUvParms();

	//! Get ExtensionWidth URI as plmxml_api::String
	plmxml_api::String GetExtensionWidthURI() const;

	//! Set ExtensionWidth URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetExtensionWidthURI( const plmxml_api::String& );
	
	//! Get the handle of ExtensionWidth URI. Does not resolve the URI.
	plmxml_api::Result GetExtensionWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ExtensionWidth URI. URI string is unchanged.
	plmxml_api::Result SetExtensionWidthURI( const plmxml_api::Handle& );
	
	//! Resolve ExtensionWidth URI and return an object (handle) it points to.
	plmxml_api::Result ResolveExtensionWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ExtensionWidth URI. Clears URI string and handle.
	plmxml_api::Result DeleteExtensionWidthURI();
	
	//! Check if ExtensionWidth URI is set
	plmxml_api::logical HasExtensionWidthURI( ) const;
	

	//! Set ExtensionThickness
	plmxml_api::Result SetExtensionThickness( const eTextLineThicknessType& arg );

	//! Get ExtensionThickness
	eTextLineThicknessType GetExtensionThickness() const;

	//! Set ArrowWidth
	plmxml_api::Result SetArrowWidth( double arg );

     //! Get ArrowWidth
	double GetArrowWidth() const;

	//! Check if ArrowWidth is set
	plmxml_api::logical HasArrowWidth() const;

	//! Unset ArrowWidth
	plmxml_api::Result UnsetArrowWidth();

	//! Set ExtensionJogDefinition
	plmxml_api::Result SetExtensionJogDefinition( const eAnn3DExtensionJogDefinitionEnum& arg );

	//! Get ExtensionJogDefinition
	eAnn3DExtensionJogDefinitionEnum GetExtensionJogDefinition() const;

	//! Set reference to Reference using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetReferenceRef( plmxml60::IdObject *arg );

	//! Clear reference to Reference
	void RemoveReferenceRef( );

	//! Find a plmxml60::IdObject referenced by Reference
	plmxml60::IdObject *ResolveReferenceRef( plmxml_api::Configuration* config = NULL );

	//! Get Reference reference
	plmxml_api::String GetReferenceId() const;

	//! Set Reference reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetReferenceId( const plmxml_api::String& u );
	
	//! Check if Reference is set
	plmxml_api::logical HasReferenceRef( ) const;

	//! Get ArrowWidth URI as plmxml_api::String
	plmxml_api::String GetArrowWidthURI() const;

	//! Set ArrowWidth URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetArrowWidthURI( const plmxml_api::String& );
	
	//! Get the handle of ArrowWidth URI. Does not resolve the URI.
	plmxml_api::Result GetArrowWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ArrowWidth URI. URI string is unchanged.
	plmxml_api::Result SetArrowWidthURI( const plmxml_api::Handle& );
	
	//! Resolve ArrowWidth URI and return an object (handle) it points to.
	plmxml_api::Result ResolveArrowWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ArrowWidth URI. Clears URI string and handle.
	plmxml_api::Result DeleteArrowWidthURI();
	
	//! Check if ArrowWidth URI is set
	plmxml_api::logical HasArrowWidthURI( ) const;
	

	//! Set ArrowType
	plmxml_api::Result SetArrowType( const eAnn3DArrow& arg );

	//! Get ArrowType
	eAnn3DArrow GetArrowType() const;

	//! Set Colour array
	plmxml_api::Result SetColour( const double *arg );

	//! Get Colour array
	plmxml_api::Result GetColour( double *arg ) const;

	//! Check if Colour array is set
	plmxml_api::logical HasColour() const;

	//! Unset Colour array
	plmxml_api::Result UnsetColour();

	//! Set StubLength
	plmxml_api::Result SetStubLength( double arg );

     //! Get StubLength
	double GetStubLength() const;

	//! Check if StubLength is set
	plmxml_api::logical HasStubLength() const;

	//! Unset StubLength
	plmxml_api::Result UnsetStubLength();

	//! Set Suppressed
	plmxml_api::Result SetSuppressed( plmxml_api::logical arg );

	//! Get Suppressed
	plmxml_api::logical GetSuppressed() const;

	//! Check if Suppressed is set
	plmxml_api::logical HasSuppressed() const;

	//! Unset Suppressed
	plmxml_api::Result UnsetSuppressed();

	//! Set ExtensionLineExtension
	plmxml_api::Result SetExtensionLineExtension( double arg );

     //! Get ExtensionLineExtension
	double GetExtensionLineExtension() const;

	//! Check if ExtensionLineExtension is set
	plmxml_api::logical HasExtensionLineExtension() const;

	//! Unset ExtensionLineExtension
	plmxml_api::Result UnsetExtensionLineExtension();

	//! Set Width
	plmxml_api::Result SetWidth( double arg );

     //! Get Width
	double GetWidth() const;

	//! Check if Width is set
	plmxml_api::logical HasWidth() const;

	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Set LeaderAttachment
	plmxml_api::Result SetLeaderAttachment( const eAnn3DLeaderAttachmentEnum& arg );

	//! Get LeaderAttachment
	eAnn3DLeaderAttachmentEnum GetLeaderAttachment() const;

	//! Set PerpendicularToTerminator
	plmxml_api::Result SetPerpendicularToTerminator( plmxml_api::logical arg );

	//! Get PerpendicularToTerminator
	plmxml_api::logical GetPerpendicularToTerminator() const;

	//! Check if PerpendicularToTerminator is set
	plmxml_api::logical HasPerpendicularToTerminator() const;

	//! Unset PerpendicularToTerminator
	plmxml_api::Result UnsetPerpendicularToTerminator();

	//! Set ExtensionJogEnd
	plmxml_api::Result SetExtensionJogEnd( double arg );

     //! Get ExtensionJogEnd
	double GetExtensionJogEnd() const;

	//! Check if ExtensionJogEnd is set
	plmxml_api::logical HasExtensionJogEnd() const;

	//! Unset ExtensionJogEnd
	plmxml_api::Result UnsetExtensionJogEnd();

	//! Set Thickness
	plmxml_api::Result SetThickness( const eTextLineThicknessType& arg );

	//! Get Thickness
	eTextLineThicknessType GetThickness() const;

	//! Set ArrowThickness
	plmxml_api::Result SetArrowThickness( const eTextLineThicknessType& arg );

	//! Get ArrowThickness
	eTextLineThicknessType GetArrowThickness() const;

	//! Set StubDirection
	plmxml_api::Result SetStubDirection( const eAnn3DDimensionStubDirection& arg );

	//! Get StubDirection
	eAnn3DDimensionStubDirection GetStubDirection() const;

	//! Set Terminator using plmxml_api::Vector components
	plmxml_api::Result SetTerminator( const plmxml_api::Vector& arg );

	//! Get Terminator as plmxml_api::Vector
	plmxml_api::Result GetTerminator( plmxml_api::Vector& arg ) const;

	//! Check if Terminator is set
	plmxml_api::logical HasTerminator() const;

	//! Unset Terminator
	plmxml_api::Result UnsetTerminator();

	//! Set ArrowLength
	plmxml_api::Result SetArrowLength( double arg );

     //! Get ArrowLength
	double GetArrowLength() const;

	//! Check if ArrowLength is set
	plmxml_api::logical HasArrowLength() const;

	//! Unset ArrowLength
	plmxml_api::Result UnsetArrowLength();

	//! Set ArrowOutsideLength
	plmxml_api::Result SetArrowOutsideLength( double arg );

     //! Get ArrowOutsideLength
	double GetArrowOutsideLength() const;

	//! Check if ArrowOutsideLength is set
	plmxml_api::logical HasArrowOutsideLength() const;

	//! Unset ArrowOutsideLength
	plmxml_api::Result UnsetArrowOutsideLength();

	//! Set ArrowColour array
	plmxml_api::Result SetArrowColour( const double *arg );

	//! Get ArrowColour array
	plmxml_api::Result GetArrowColour( double *arg ) const;

	//! Check if ArrowColour array is set
	plmxml_api::logical HasArrowColour() const;

	//! Unset ArrowColour array
	plmxml_api::Result UnsetArrowColour();

	//! Set ExtensionWidth
	plmxml_api::Result SetExtensionWidth( double arg );

     //! Get ExtensionWidth
	double GetExtensionWidth() const;

	//! Check if ExtensionWidth is set
	plmxml_api::logical HasExtensionWidth() const;

	//! Unset ExtensionWidth
	plmxml_api::Result UnsetExtensionWidth();

	//! Set OffsetCentre
	plmxml_api::Result SetOffsetCentre( plmxml_api::logical arg );

	//! Get OffsetCentre
	plmxml_api::logical GetOffsetCentre() const;

	//! Check if OffsetCentre is set
	plmxml_api::logical HasOffsetCentre() const;

	//! Unset OffsetCentre
	plmxml_api::Result UnsetOffsetCentre();

	//! Set TParm
	plmxml_api::Result SetTParm( double arg );

     //! Get TParm
	double GetTParm() const;

	//! Check if TParm is set
	plmxml_api::logical HasTParm() const;

	//! Unset TParm
	plmxml_api::Result UnsetTParm();

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set ExtensionJogStart
	plmxml_api::Result SetExtensionJogStart( double arg );

     //! Get ExtensionJogStart
	double GetExtensionJogStart() const;

	//! Check if ExtensionJogStart is set
	plmxml_api::logical HasExtensionJogStart() const;

	//! Unset ExtensionJogStart
	plmxml_api::Result UnsetExtensionJogStart();

	//! Set ExtensionLineGap
	plmxml_api::Result SetExtensionLineGap( double arg );

     //! Get ExtensionLineGap
	double GetExtensionLineGap() const;

	//! Check if ExtensionLineGap is set
	plmxml_api::logical HasExtensionLineGap() const;

	//! Unset ExtensionLineGap
	plmxml_api::Result UnsetExtensionLineGap();

	//! Set AllAroundSymbolSize
	plmxml_api::Result SetAllAroundSymbolSize( double arg );

     //! Get AllAroundSymbolSize
	double GetAllAroundSymbolSize() const;

	//! Check if AllAroundSymbolSize is set
	plmxml_api::logical HasAllAroundSymbolSize() const;

	//! Unset AllAroundSymbolSize
	plmxml_api::Result UnsetAllAroundSymbolSize();

	//! Set LineTextGap
	plmxml_api::Result SetLineTextGap( double arg );

     //! Get LineTextGap
	double GetLineTextGap() const;

	//! Check if LineTextGap is set
	plmxml_api::logical HasLineTextGap() const;

	//! Unset LineTextGap
	plmxml_api::Result UnsetLineTextGap();

	//! Set ExtensionJogAngle
	plmxml_api::Result SetExtensionJogAngle( double arg );

     //! Get ExtensionJogAngle
	double GetExtensionJogAngle() const;

	//! Check if ExtensionJogAngle is set
	plmxml_api::logical HasExtensionJogAngle() const;

	//! Unset ExtensionJogAngle
	plmxml_api::Result UnsetExtensionJogAngle();

	//! Set StubAttachment
	plmxml_api::Result SetStubAttachment( const eAnn3DStubAttachmentEnum& arg );

	//! Get StubAttachment
	eAnn3DStubAttachmentEnum GetStubAttachment() const;

	//! Set ArrowPlacement
	plmxml_api::Result SetArrowPlacement( const eAnn3DDimensionArrowPlacement& arg );

	//! Get ArrowPlacement
	eAnn3DDimensionArrowPlacement GetArrowPlacement() const;

	//! Set ExtensionLineType
	plmxml_api::Result SetExtensionLineType( const eAnn3DLineType& arg );

	//! Get ExtensionLineType
	eAnn3DLineType GetExtensionLineType() const;

	//! Set HalfArrow
	plmxml_api::Result SetHalfArrow( const eAnn3DHalfArrowEnum& arg );

	//! Get HalfArrow
	eAnn3DHalfArrowEnum GetHalfArrow() const;

	//! Set ArrowAngle
	plmxml_api::Result SetArrowAngle( double arg );

     //! Get ArrowAngle
	double GetArrowAngle() const;

	//! Check if ArrowAngle is set
	plmxml_api::logical HasArrowAngle() const;

	//! Unset ArrowAngle
	plmxml_api::Result UnsetArrowAngle();

	//! Set ExtensionJogging
	plmxml_api::Result SetExtensionJogging( const eAnn3DExtensionJoggingEnum& arg );

	//! Get ExtensionJogging
	eAnn3DExtensionJoggingEnum GetExtensionJogging() const;

	//! Set ExtensionColour array
	plmxml_api::Result SetExtensionColour( const double *arg );

	//! Get ExtensionColour array
	plmxml_api::Result GetExtensionColour( double *arg ) const;

	//! Check if ExtensionColour array is set
	plmxml_api::logical HasExtensionColour() const;

	//! Unset ExtensionColour array
	plmxml_api::Result UnsetExtensionColour();

	//! Set PerpendicularToStub
	plmxml_api::Result SetPerpendicularToStub( plmxml_api::logical arg );

	//! Get PerpendicularToStub
	plmxml_api::logical GetPerpendicularToStub() const;

	//! Check if PerpendicularToStub is set
	plmxml_api::logical HasPerpendicularToStub() const;

	//! Unset PerpendicularToStub
	plmxml_api::Result UnsetPerpendicularToStub();

	//! Set TextOverLeaderFactor
	plmxml_api::Result SetTextOverLeaderFactor( double arg );

     //! Get TextOverLeaderFactor
	double GetTextOverLeaderFactor() const;

	//! Check if TextOverLeaderFactor is set
	plmxml_api::logical HasTextOverLeaderFactor() const;

	//! Unset TextOverLeaderFactor
	plmxml_api::Result UnsetTextOverLeaderFactor();

	//! Set ExtensionJogOut
	plmxml_api::Result SetExtensionJogOut( plmxml_api::logical arg );

	//! Get ExtensionJogOut
	plmxml_api::logical GetExtensionJogOut() const;

	//! Check if ExtensionJogOut is set
	plmxml_api::logical HasExtensionJogOut() const;

	//! Unset ExtensionJogOut
	plmxml_api::Result UnsetExtensionJogOut();

	//! Add Curve child element to this Ann3DLeader. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Curve *AddCurve();
     
	//! Set Curve child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCurve( Curve *arg );
     
	//! Get Curve child element of this Ann3DLeader.
	Curve *GetCurve() const;
     
	//! Detach and delete Curve child element tree from this Ann3DLeader.
	void DeleteCurve();

	//! Add Jog child element to this Ann3DLeader. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	VectorField *AddJog();
     
	//! Add 'arg' as Jog child element to this Ann3DLeader.
	plmxml_api::Result AddJog( VectorField *arg );

	//! Detach and delete all Jog child elements.
	void DeleteJogs();
     
	//! Get number of Jog child elements.
	int NumberOfJogs() const;
     
	//! Get i'th Jog child element.
	VectorField *GetJog( int i ) const;
     
	//! Get all Jog child element as an array
	void GetJogs( plmxml_api::Array<VectorField*> &array ) const;
	     
	//! Detach and delete i'th Jog child element
	void DeleteJog( int i );
     
	//! Detach and delete 'arg' if it's one of the Jog child elements
	void DeleteJog( VectorField *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DLeader" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DLeader;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DDimensionText class
/*!
\verbatim

      Ann3DDimensionTextType:  text to be added to a Dimension, in a specified position

      Attributes:
        
      position:    position of text relative to the Dimension

      Elements:

      Text:        a single Ann3DTextType element
    
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DDimensionText : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DDimensionText( );
     
    //! Constructs a Ann3DDimensionText with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DDimensionText( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DDimensionText();

private:

	//! Assignment operator
	Ann3DDimensionText& operator=( const Ann3DDimensionText& iSrc );

	//! Copy constructor
	Ann3DDimensionText( const Ann3DDimensionText& original );
     
public:

	//! Set Position
	plmxml_api::Result SetPosition( const eAnn3DDimensionTextPosition& arg );

	//! Get Position
	eAnn3DDimensionTextPosition GetPosition() const;

	//! Add Text child element to this Ann3DDimensionText. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddText();
     
	//! Set Text child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetText( Ann3DText *arg );
     
	//! Get Text child element of this Ann3DDimensionText.
	Ann3DText *GetText() const;
     
	//! Detach and delete Text child element tree from this Ann3DDimensionText.
	void DeleteText();
 
// <PLMXML_UserCode type="functionHeaderAnn3DDimensionText" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DDimensionText;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DStatisticalRefinement class
/*!
\verbatim

      Ann3DStatisticalRefinementType:  statistical refinement
      This type will be expanded to contain further information in the future.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DStatisticalRefinement : public IdObject
{
public:
     
    //! Default constructor
    Ann3DStatisticalRefinement( );
     
    //! Constructs a Ann3DStatisticalRefinement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DStatisticalRefinement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DStatisticalRefinement();

private:

	//! Assignment operator
	Ann3DStatisticalRefinement& operator=( const Ann3DStatisticalRefinement& iSrc );

	//! Copy constructor
	Ann3DStatisticalRefinement( const Ann3DStatisticalRefinement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DStatisticalRefinement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DStatisticalRefinement;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DFreeStateRefinement class
/*!
\verbatim

      Ann3DFreeStateRefinementType:  Free State refinement
      This type will be expanded to contain further information in the future.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DFreeStateRefinement : public IdObject
{
public:
     
    //! Default constructor
    Ann3DFreeStateRefinement( );
     
    //! Constructs a Ann3DFreeStateRefinement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DFreeStateRefinement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DFreeStateRefinement();

private:

	//! Assignment operator
	Ann3DFreeStateRefinement& operator=( const Ann3DFreeStateRefinement& iSrc );

	//! Copy constructor
	Ann3DFreeStateRefinement( const Ann3DFreeStateRefinement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DFreeStateRefinement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DFreeStateRefinement;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DDimensionGeneralToleranceISO class
/*!
\verbatim

      Represents a general tolerance according to ISO 2768. If present,
      tolerances are determined from type and value on the corresponding
      Dimension. upperDelta and lowerDelta are ignored.

      Attributes:

      toleranceClass:   The general tolerance class.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DDimensionGeneralToleranceISO : public Attribute
{
public:
     
    //! Default constructor
    Ann3DDimensionGeneralToleranceISO( );
     
    //! Constructs a Ann3DDimensionGeneralToleranceISO with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DDimensionGeneralToleranceISO( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DDimensionGeneralToleranceISO();

private:

	//! Assignment operator
	Ann3DDimensionGeneralToleranceISO& operator=( const Ann3DDimensionGeneralToleranceISO& iSrc );

	//! Copy constructor
	Ann3DDimensionGeneralToleranceISO( const Ann3DDimensionGeneralToleranceISO& original );
     
public:

	//! Set ToleranceClass
	plmxml_api::Result SetToleranceClass( const eAnn3DDimensionToleranceClassISOEnum& arg );

	//! Get ToleranceClass
	eAnn3DDimensionToleranceClassISOEnum GetToleranceClass() const;
 
// <PLMXML_UserCode type="functionHeaderAnn3DDimensionGeneralToleranceISO" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DDimensionGeneralToleranceISO;


////////////////////////////////////////////////////////////////////////////////////
//! Dimension class
/*!
\verbatim

      Dimension: 3D Dimension Annotation

      Attributes:

      standard:           e.g. "ANSI Y..."
      type:               linear, radial, angular or curveLength
      direction:          direction of measurement
      basic:              whether a 'basic' dimension.
      reference:          whether a 'reference' dimension.
      origin:             whether first or second entity is the origin (for
                          directed Dimensions). This attribute is deprecated in
                          favour of origin on the Reference element.
      value:              value of dimension, in metres or radians
      upperDelta:         max value minus nominal value, in metres or radians
      lowerDelta:         nominal value minus min value, in metres or radians
      causality:          key, functional, associated, reference or pmi
      grade:            
      deviation:        
      pitchDiaGrade:    
      pitchDiaDeviation:
      fitGrade:         
      threadClass:  
      projected:          true if the Dimension is a projected Dimension, rather than
                          a true value Dimension.
      documentation:    Whether a non-PMI Dimension is treated as a PMI
                        Dimension for documenting a Part, for example, on
                        manufacturing drawings.
      notToScale:       Whether a dimension is not-to-scale.
      angleNumerator:   The angle (in radians) of the arc for fractional angular
                        dimensions.
      manual:           Whether value has been entered manually. If it has, it
                        cannot be assumed to be synchronised with the referenced
                        geometry.
      patternCount:     The number of repetitions in a compound feature to which
                        the Dimension applies.
      featureOfSize:    Whether the Dimension specifies the size of a feature.
      majorAngle:       If type is angular, majorAngle indicates whether value
                        represents the major angle or the minor angle.
      allAround:        Whether the All Around symbol is added.
      allOver:          Whether the tolerance applies all over the 3-dimensional
                        profile of the part.

      Elements:

      DimensionText:    Text elements.
      DualDimensionText: Text elements for a dual dimension, if displayed.
      ValueText:        When manual is true, ValueText overrides value.
      DualValueText:    When manual is true and dualUnits on the corresponding
                        DimensionDisplay is set, DualValueText overrides any
                        calculated dual value.
      ReferenceText:    Text elements inside the parentheses of a reference
                        Dimension. Only before and after are allowed.
      GeneralToleranceISO: A general tolerance according to ISO 2768. If
                        present, tolerances are determined from type and value.
                        upperDelta and lowerDelta are ignored.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Dimension : public Annotation3D
{
public:
     
    //! Default constructor
    Dimension( );
     
    //! Constructs a Dimension with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Dimension( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Dimension();

private:

	//! Assignment operator
	Dimension& operator=( const Dimension& iSrc );

	//! Copy constructor
	Dimension( const Dimension& original );
     
public:

	//! Set FeatureOfSize
	plmxml_api::Result SetFeatureOfSize( plmxml_api::logical arg );

	//! Get FeatureOfSize
	plmxml_api::logical GetFeatureOfSize() const;

	//! Check if FeatureOfSize is set
	plmxml_api::logical HasFeatureOfSize() const;

	//! Unset FeatureOfSize
	plmxml_api::Result UnsetFeatureOfSize();

	//! Set Documentation
	plmxml_api::Result SetDocumentation( plmxml_api::logical arg );

	//! Get Documentation
	plmxml_api::logical GetDocumentation() const;

	//! Check if Documentation is set
	plmxml_api::logical HasDocumentation() const;

	//! Unset Documentation
	plmxml_api::Result UnsetDocumentation();

	//! Set Manual
	plmxml_api::Result SetManual( plmxml_api::logical arg );

	//! Get Manual
	plmxml_api::logical GetManual() const;

	//! Check if Manual is set
	plmxml_api::logical HasManual() const;

	//! Unset Manual
	plmxml_api::Result UnsetManual();

	//! Set LowerDelta
	plmxml_api::Result SetLowerDelta( double arg );

     //! Get LowerDelta
	double GetLowerDelta() const;

	//! Check if LowerDelta is set
	plmxml_api::logical HasLowerDelta() const;

	//! Unset LowerDelta
	plmxml_api::Result UnsetLowerDelta();

	//! Set NotToScale
	plmxml_api::Result SetNotToScale( plmxml_api::logical arg );

	//! Get NotToScale
	plmxml_api::logical GetNotToScale() const;

	//! Check if NotToScale is set
	plmxml_api::logical HasNotToScale() const;

	//! Unset NotToScale
	plmxml_api::Result UnsetNotToScale();

	//! Set ThreadClass
	plmxml_api::Result SetThreadClass( int arg );
     
	//! Get ThreadClass
	int GetThreadClass() const;
     
	//! Check if ThreadClass is set
	plmxml_api::logical HasThreadClass() const;
     
	//! Unset ThreadClass
	plmxml_api::Result UnsetThreadClass();

	//! Set Causality
	plmxml_api::Result SetCausality( const eAnn3DDimensionCausality& arg );

	//! Get Causality
	eAnn3DDimensionCausality GetCausality() const;

	//! Set PatternCount
	plmxml_api::Result SetPatternCount( int arg );
     
	//! Get PatternCount
	int GetPatternCount() const;
     
	//! Check if PatternCount is set
	plmxml_api::logical HasPatternCount() const;
     
	//! Unset PatternCount
	plmxml_api::Result UnsetPatternCount();

	//! Set AngleNumerator
	plmxml_api::Result SetAngleNumerator( double arg );

     //! Get AngleNumerator
	double GetAngleNumerator() const;

	//! Check if AngleNumerator is set
	plmxml_api::logical HasAngleNumerator() const;

	//! Unset AngleNumerator
	plmxml_api::Result UnsetAngleNumerator();

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DDimension& arg );

	//! Get Type
	eAnn3DDimension GetType() const;

	//! Set Projected
	plmxml_api::Result SetProjected( plmxml_api::logical arg );

	//! Get Projected
	plmxml_api::logical GetProjected() const;

	//! Check if Projected is set
	plmxml_api::logical HasProjected() const;

	//! Unset Projected
	plmxml_api::Result UnsetProjected();

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Set UpperDelta
	plmxml_api::Result SetUpperDelta( double arg );

     //! Get UpperDelta
	double GetUpperDelta() const;

	//! Check if UpperDelta is set
	plmxml_api::logical HasUpperDelta() const;

	//! Unset UpperDelta
	plmxml_api::Result UnsetUpperDelta();

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set FitGrade
	plmxml_api::Result SetFitGrade( int arg );
     
	//! Get FitGrade
	int GetFitGrade() const;
     
	//! Check if FitGrade is set
	plmxml_api::logical HasFitGrade() const;
     
	//! Unset FitGrade
	plmxml_api::Result UnsetFitGrade();

	//! Set AllOver
	plmxml_api::Result SetAllOver( plmxml_api::logical arg );

	//! Get AllOver
	plmxml_api::logical GetAllOver() const;

	//! Check if AllOver is set
	plmxml_api::logical HasAllOver() const;

	//! Unset AllOver
	plmxml_api::Result UnsetAllOver();

	//! Set MajorAngle
	plmxml_api::Result SetMajorAngle( plmxml_api::logical arg );

	//! Get MajorAngle
	plmxml_api::logical GetMajorAngle() const;

	//! Check if MajorAngle is set
	plmxml_api::logical HasMajorAngle() const;

	//! Unset MajorAngle
	plmxml_api::Result UnsetMajorAngle();

	//! Set PitchDiaGrade
	plmxml_api::Result SetPitchDiaGrade( int arg );
     
	//! Get PitchDiaGrade
	int GetPitchDiaGrade() const;
     
	//! Check if PitchDiaGrade is set
	plmxml_api::logical HasPitchDiaGrade() const;
     
	//! Unset PitchDiaGrade
	plmxml_api::Result UnsetPitchDiaGrade();

	//! Set Origin
	plmxml_api::Result SetOrigin( const eAnn3DDimensionOrigin& arg );

	//! Get Origin
	eAnn3DDimensionOrigin GetOrigin() const;

	//! Set Grade
	plmxml_api::Result SetGrade( int arg );
     
	//! Get Grade
	int GetGrade() const;
     
	//! Check if Grade is set
	plmxml_api::logical HasGrade() const;
     
	//! Unset Grade
	plmxml_api::Result UnsetGrade();

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();

	//! Set Basic
	plmxml_api::Result SetBasic( plmxml_api::logical arg );

	//! Get Basic
	plmxml_api::logical GetBasic() const;

	//! Check if Basic is set
	plmxml_api::logical HasBasic() const;

	//! Unset Basic
	plmxml_api::Result UnsetBasic();

	//! Get PitchDiaDeviation of this Dimension
	plmxml_api::String GetPitchDiaDeviation() const;

	//! Set PitchDiaDeviation of this Dimension
	plmxml_api::Result SetPitchDiaDeviation( const plmxml_api::String &s );
	
	//! Check if PitchDiaDeviation is set
	plmxml_api::logical HasPitchDiaDeviation( ) const;
	
	//! Unset PitchDiaDeviation
	plmxml_api::Result UnsetPitchDiaDeviation( );

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set Reference
	plmxml_api::Result SetReference( plmxml_api::logical arg );

	//! Get Reference
	plmxml_api::logical GetReference() const;

	//! Check if Reference is set
	plmxml_api::logical HasReference() const;

	//! Unset Reference
	plmxml_api::Result UnsetReference();

	//! Get Deviation of this Dimension
	plmxml_api::String GetDeviation() const;

	//! Set Deviation of this Dimension
	plmxml_api::Result SetDeviation( const plmxml_api::String &s );
	
	//! Check if Deviation is set
	plmxml_api::logical HasDeviation( ) const;
	
	//! Unset Deviation
	plmxml_api::Result UnsetDeviation( );

	//! Add DimensionText child element to this Dimension. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddDimensionText();
     
	//! Add 'arg' as DimensionText child element to this Dimension.
	plmxml_api::Result AddDimensionText( Ann3DDimensionText *arg );

	//! Detach and delete all DimensionText child elements.
	void DeleteDimensionTexts();
     
	//! Get number of DimensionText child elements.
	int NumberOfDimensionTexts() const;
     
	//! Get i'th DimensionText child element.
	Ann3DDimensionText *GetDimensionText( int i ) const;
     
	//! Get all DimensionText child element as an array
	void GetDimensionTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th DimensionText child element
	void DeleteDimensionText( int i );
     
	//! Detach and delete 'arg' if it's one of the DimensionText child elements
	void DeleteDimensionText( Ann3DDimensionText *arg );

	//! Add DualDimensionText child element to this Dimension. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddDualDimensionText();
     
	//! Add 'arg' as DualDimensionText child element to this Dimension.
	plmxml_api::Result AddDualDimensionText( Ann3DDimensionText *arg );

	//! Detach and delete all DualDimensionText child elements.
	void DeleteDualDimensionTexts();
     
	//! Get number of DualDimensionText child elements.
	int NumberOfDualDimensionTexts() const;
     
	//! Get i'th DualDimensionText child element.
	Ann3DDimensionText *GetDualDimensionText( int i ) const;
     
	//! Get all DualDimensionText child element as an array
	void GetDualDimensionTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th DualDimensionText child element
	void DeleteDualDimensionText( int i );
     
	//! Detach and delete 'arg' if it's one of the DualDimensionText child elements
	void DeleteDualDimensionText( Ann3DDimensionText *arg );

	//! Add Statistical child element to this Dimension. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DStatisticalRefinement *AddStatistical();
     
	//! Set Statistical child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStatistical( Ann3DStatisticalRefinement *arg );
     
	//! Get Statistical child element of this Dimension.
	Ann3DStatisticalRefinement *GetStatistical() const;
     
	//! Detach and delete Statistical child element tree from this Dimension.
	void DeleteStatistical();

	//! Add FreeState child element to this Dimension. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFreeStateRefinement *AddFreeState();
     
	//! Set FreeState child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFreeState( Ann3DFreeStateRefinement *arg );
     
	//! Get FreeState child element of this Dimension.
	Ann3DFreeStateRefinement *GetFreeState() const;
     
	//! Detach and delete FreeState child element tree from this Dimension.
	void DeleteFreeState();

	//! Add ValueText child element to this Dimension. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddValueText();
     
	//! Set ValueText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueText( Ann3DText *arg );
     
	//! Get ValueText child element of this Dimension.
	Ann3DText *GetValueText() const;
     
	//! Detach and delete ValueText child element tree from this Dimension.
	void DeleteValueText();

	//! Add DualValueText child element to this Dimension. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddDualValueText();
     
	//! Set DualValueText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDualValueText( Ann3DText *arg );
     
	//! Get DualValueText child element of this Dimension.
	Ann3DText *GetDualValueText() const;
     
	//! Detach and delete DualValueText child element tree from this Dimension.
	void DeleteDualValueText();

	//! Add ReferenceText child element to this Dimension. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddReferenceText();
     
	//! Add 'arg' as ReferenceText child element to this Dimension.
	plmxml_api::Result AddReferenceText( Ann3DDimensionText *arg );

	//! Detach and delete all ReferenceText child elements.
	void DeleteReferenceTexts();
     
	//! Get number of ReferenceText child elements.
	int NumberOfReferenceTexts() const;
     
	//! Get i'th ReferenceText child element.
	Ann3DDimensionText *GetReferenceText( int i ) const;
     
	//! Get all ReferenceText child element as an array
	void GetReferenceTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th ReferenceText child element
	void DeleteReferenceText( int i );
     
	//! Detach and delete 'arg' if it's one of the ReferenceText child elements
	void DeleteReferenceText( Ann3DDimensionText *arg );

	//! Add GeneralToleranceISO child element to this Dimension. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionGeneralToleranceISO *AddGeneralToleranceISO();
     
	//! Set GeneralToleranceISO child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetGeneralToleranceISO( Ann3DDimensionGeneralToleranceISO *arg );
     
	//! Get GeneralToleranceISO child element of this Dimension.
	Ann3DDimensionGeneralToleranceISO *GetGeneralToleranceISO() const;
     
	//! Detach and delete GeneralToleranceISO child element tree from this Dimension.
	void DeleteGeneralToleranceISO();
 
// <PLMXML_UserCode type="functionHeaderDimension" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassDimension;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTextFormat class
/*!
\verbatim

      Text formatting override.

      Attributes:

      TextGroup:       Text formatting attributes.

      Sub-elements:

      Item:            The characters and symbols to which the override applies.
                       If none, the override applies to all characters and
                       symbols. If more than one element, the order is
                       insignificant.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTextFormat : public Attribute
{
public:
     
    //! Default constructor
    Ann3DTextFormat( );
     
    //! Constructs a Ann3DTextFormat with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTextFormat( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTextFormat();

private:

	//! Assignment operator
	Ann3DTextFormat& operator=( const Ann3DTextFormat& iSrc );

	//! Copy constructor
	Ann3DTextFormat( const Ann3DTextFormat& original );
     
public:

	//! Set ItalicAngle
	plmxml_api::Result SetItalicAngle( double arg );

     //! Get ItalicAngle
	double GetItalicAngle() const;

	//! Check if ItalicAngle is set
	plmxml_api::logical HasItalicAngle() const;

	//! Unset ItalicAngle
	plmxml_api::Result UnsetItalicAngle();

	//! Set SpaceFactor
	plmxml_api::Result SetSpaceFactor( double arg );

     //! Get SpaceFactor
	double GetSpaceFactor() const;

	//! Check if SpaceFactor is set
	plmxml_api::logical HasSpaceFactor() const;

	//! Unset SpaceFactor
	plmxml_api::Result UnsetSpaceFactor();

	//! Set Bold
	plmxml_api::Result SetBold( plmxml_api::logical arg );

	//! Get Bold
	plmxml_api::logical GetBold() const;

	//! Check if Bold is set
	plmxml_api::logical HasBold() const;

	//! Unset Bold
	plmxml_api::Result UnsetBold();

	//! Set Underline
	plmxml_api::Result SetUnderline( const eTextUnderlineType& arg );

	//! Get Underline
	eTextUnderlineType GetUnderline() const;

	//! Set TextThickness
	plmxml_api::Result SetTextThickness( const eTextLineThicknessType& arg );

	//! Get TextThickness
	eTextLineThicknessType GetTextThickness() const;

	//! Get TextLineWidth URI as plmxml_api::String
	plmxml_api::String GetTextLineWidthURI() const;

	//! Set TextLineWidth URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::String& );
	
	//! Get the handle of TextLineWidth URI. Does not resolve the URI.
	plmxml_api::Result GetTextLineWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TextLineWidth URI. URI string is unchanged.
	plmxml_api::Result SetTextLineWidthURI( const plmxml_api::Handle& );
	
	//! Resolve TextLineWidth URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTextLineWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TextLineWidth URI. Clears URI string and handle.
	plmxml_api::Result DeleteTextLineWidthURI();
	
	//! Check if TextLineWidth URI is set
	plmxml_api::logical HasTextLineWidthURI( ) const;
	

	//! Set Italic
	plmxml_api::Result SetItalic( plmxml_api::logical arg );

	//! Get Italic
	plmxml_api::logical GetItalic() const;

	//! Check if Italic is set
	plmxml_api::logical HasItalic() const;

	//! Unset Italic
	plmxml_api::Result UnsetItalic();

	//! Set LineFactor
	plmxml_api::Result SetLineFactor( double arg );

     //! Get LineFactor
	double GetLineFactor() const;

	//! Check if LineFactor is set
	plmxml_api::logical HasLineFactor() const;

	//! Unset LineFactor
	plmxml_api::Result UnsetLineFactor();

	//! Set Strikethrough
	plmxml_api::Result SetStrikethrough( const eAnn3DTextStrikethroughEnum& arg );

	//! Get Strikethrough
	eAnn3DTextStrikethroughEnum GetStrikethrough() const;

	//! Set TextColour array
	plmxml_api::Result SetTextColour( const double *arg );

	//! Get TextColour array
	plmxml_api::Result GetTextColour( double *arg ) const;

	//! Check if TextColour array is set
	plmxml_api::logical HasTextColour() const;

	//! Unset TextColour array
	plmxml_api::Result UnsetTextColour();

	//! Set Subscript
	plmxml_api::Result SetSubscript( const eAnn3DTextSubscriptEnum& arg );

	//! Get Subscript
	eAnn3DTextSubscriptEnum GetSubscript() const;

	//! Set Justification
	plmxml_api::Result SetJustification( const eTextJustificationType& arg );

	//! Get Justification
	eTextJustificationType GetJustification() const;

	//! Get Font of this Ann3DTextFormat
	plmxml_api::String GetFont() const;

	//! Set Font of this Ann3DTextFormat
	plmxml_api::Result SetFont( const plmxml_api::String &s );
	
	//! Check if Font is set
	plmxml_api::logical HasFont( ) const;
	
	//! Unset Font
	plmxml_api::Result UnsetFont( );

	//! Set TextHeight
	plmxml_api::Result SetTextHeight( double arg );

     //! Get TextHeight
	double GetTextHeight() const;

	//! Check if TextHeight is set
	plmxml_api::logical HasTextHeight() const;

	//! Unset TextHeight
	plmxml_api::Result UnsetTextHeight();

	//! Set TextLineWidth
	plmxml_api::Result SetTextLineWidth( double arg );

     //! Get TextLineWidth
	double GetTextLineWidth() const;

	//! Check if TextLineWidth is set
	plmxml_api::logical HasTextLineWidth() const;

	//! Unset TextLineWidth
	plmxml_api::Result UnsetTextLineWidth();

	//! Get Language of this Ann3DTextFormat
	plmxml_api::String GetLanguage() const;

	//! Set Language of this Ann3DTextFormat
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Set TextAspect
	plmxml_api::Result SetTextAspect( double arg );

     //! Get TextAspect
	double GetTextAspect() const;

	//! Check if TextAspect is set
	plmxml_api::logical HasTextAspect() const;

	//! Unset TextAspect
	plmxml_api::Result UnsetTextAspect();

	//! Add Item child element to this Ann3DTextFormat. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTextItem *AddItem();
     
	//! Add 'arg' as Item child element to this Ann3DTextFormat.
	plmxml_api::Result AddItem( Ann3DTextItem *arg );

	//! Detach and delete all Item child elements.
	void DeleteItems();
     
	//! Get number of Item child elements.
	int NumberOfItems() const;
     
	//! Get i'th Item child element.
	Ann3DTextItem *GetItem( int i ) const;
     
	//! Get all Item child element as an array
	void GetItems( plmxml_api::Array<Ann3DTextItem*> &array ) const;
	     
	//! Detach and delete i'th Item child element
	void DeleteItem( int i );
     
	//! Detach and delete 'arg' if it's one of the Item child elements
	void DeleteItem( Ann3DTextItem *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DTextFormat" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTextFormat;


////////////////////////////////////////////////////////////////////////////////////
//! DimensionDisplay class
/*!
\verbatim

      DimensionDisplay: 3D Dimension display, derived from Annotation3DDisplay

      Attributes:

        toleranceDisplay:   method of display for tolerance
        style:              style of display - radial, diametral, sphericalRadial,
                            controlledRadial, sphericalDiameter, ordinate or
                            linearDiametral. The value, limits, is deprecated in
                            favour of the limitDisplay attribute.
        precision:          The precision of the displayed value in number of
                            decimal places. This is the number of decimal places
                            that can be relied on, whether or not that number of
                            decimal places is actually displayed. Normally they
                            would be displayed but trailing zeros can be
                            suppressed by setting dimensionTrailingZero to
                            false.
        angleFormat:        controls the format of angular values
        tolerancePrecision: number of decimal places shown in the tolerance
        toleranceAngleFormat: controls the format of angular tolerances
        unitText:           whether to display the unit text (e.g. "inches")
        dualUnits:          units to use for the dual dimension. This attribute
                            is deprecated in favour of dualUnitRef.
        dualType:           bracket, positional or line separated display of the
                            dual dimension
        dualPlacement:      Placement of the dual dimension: before, after, above or below the
                            main dimension
        dualTolerancePrecision: number of decimal places shown in the dual tolerance
        dualUnitText:       ditto for the dual dimension
        diameterPlacement:  before, after, above or below
        statisticalPlacement: ditto
        radialPlacement:    ditto
        linearPlacement:    ditto
        referenceDisplay:   how to display reference dimensions - reference, parenthesis, or matched
        zeroToleranceDisplay: controls the display of a zero valued tolerance
        dimensionLeadingZero: whether to display leading zeroes in the dimension value
        toleranceLeadingZero: whether to display leading zeroes in the tolerance value
        dimensionTrailingZero: Whether trailing zeros on dimension values are
                            displayed. This does not affect the precision of the
                            displayed value. See precision attribute.
        toleranceTrailingZero: Whether trailing zeros on tolerance values are
                            displayed.
        fraction:           For linear dimensions, display each of value,
                            upperDelta and lowerDelta on Dimension as an integer
                            (if value is greater than or equal to one) and a
                            fraction (unless value is exactly an integer). For
                            angular dimensions, display them as fractions of the
                            arc given by the angleNumerator attribute on the
                            corresponding Dimension.
        valueDenominator:   The largest denominator allowable for value on
                            Dimension.
        upperDeltaDenominator: The largest denominator allowable for upperDelta
                            on Dimension.
        lowerDeltaDenominator: The largest denominator allowable for lowerDelta
                            on Dimension.
        fractionSize:       The size of the numerals in any fractions compared
                            to the size of those in the integers.
        limitFitOrder:      For a limits and fits dimension, the order in which
                            the value attribute, the deviation and the grade
                            attributes, and the tolerance information on the
                            corresponding Dimension are displayed.
        limitFitParentheses: For a limits and fits dimension, whether the value
                            attribute, the deviation and the grade attributes or
                            the tolerance information on the corresponding
                            Dimension are displayed in parentheses.
        dualValueDenominator: The largest denominator allowable for value
                            converted to a dual dimension.
        dualUpperDeltaDenominator: The largest denominator allowable for
                            upperDelta converted to a dual Dimension.
        dualLowerDeltaDenominator: The largest denominator allowable for
                            lowerDelta converted to a dual Dimension.
        dualUnitRef:        References a Unit, which specifies the units to use
                            for the dual dimension. NB: if this is present, a
                            dual dimension is displayed - otherwise not.
        limitDisplay:       How the deviation and the grade attributes on the
                            corresponding Dimension are displayed.
        singleSided:        Whether the Dimension is displayed single sided.
        singleSideFirst:    Whether a single sided Dimension points towards the
                            first or the second Reference sub-element.
        singleSideLength:   The length (or the arc length for an angular
                            Dimension) that the non arrow side of a single sided
                            Dimension protrudes from the text.
        alignment:          The position of the value relative to the limit and
                            fit (if there is one) and the tolerance information,
                            which follow.
        textOrientationType: How the dimension text is orientated.
        dimensionLineTrim:  When textOrientationType is aboveDimensionLine and
                            the dimension line is displayed between the
                            extension lines, dimensionLineTrim specifies whether
                            the dimension line is trimmed if the dimension text
                            crosses both extension lines.
        dimensionLineBetweenArrows: Whether the dimension line is displayed
                            between the dimension arrowheads.
        textLeaderPosition: The position and the orientation of the text at the
                            end of a Leader.
        narrowOffset:       For a narrow Dimension, the perpendicular distance
                            from the dimension line to the end of the Leader (if
                            there is one) or the text (if there is no Leader) in
                            metres.
        narrowLeaderAngle:  For a narrow Dimension, the angle between the
                            dimension line and the Leader in radians.
        foldLocation:       The location of the fold of a folded radius
                            Dimension.
        inspection:         Whether the Dimension is used for inspection.
        inspectionDisplay:  If inspection is true, inspectionDisplay specifies
                            how any appended text is displayed inside the
                            dimension inspection symbol.
        ordinateBaselineZero: Whether to display a zero at the baseline for
                            ordinate dimensions.
        dualDimensionLineCenter: Whether to center the dimension line between
                            the dimension and the dual dimension.
        referenceContent:   The type of information to display inside the
                            parentheses of a reference Dimension.
        appendedTextSpaceFactor: The spacing of any appended text fields
                            relative to the font size.
        toleranceTextSpaceFactor: The spacing of the tolerance fields relative
                            to the font size.
        zeroToleranceSign:  The sign (if any) before zero tolerance values for
                            both upper and lower bounds.

      Sub-elements:

        ToleranceTextFormat: Formatting attributes for the text of the tolerance
                            values. Overrides any formatting attributes applying
                            generally to all text fields.
        StyleText:           Custom style indicator text, such as the diameter
                             symbol. Overrides any style indicator inferred from
                             style.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API DimensionDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    DimensionDisplay( );
     
    //! Constructs a DimensionDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DimensionDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DimensionDisplay();

private:

	//! Assignment operator
	DimensionDisplay& operator=( const DimensionDisplay& iSrc );

	//! Copy constructor
	DimensionDisplay( const DimensionDisplay& original );
     
public:

	//! Set DualUnitText
	plmxml_api::Result SetDualUnitText( plmxml_api::logical arg );

	//! Get DualUnitText
	plmxml_api::logical GetDualUnitText() const;

	//! Check if DualUnitText is set
	plmxml_api::logical HasDualUnitText() const;

	//! Unset DualUnitText
	plmxml_api::Result UnsetDualUnitText();

	//! Set ToleranceTextSpaceFactor
	plmxml_api::Result SetToleranceTextSpaceFactor( double arg );

     //! Get ToleranceTextSpaceFactor
	double GetToleranceTextSpaceFactor() const;

	//! Check if ToleranceTextSpaceFactor is set
	plmxml_api::logical HasToleranceTextSpaceFactor() const;

	//! Unset ToleranceTextSpaceFactor
	plmxml_api::Result UnsetToleranceTextSpaceFactor();

	//! Set ToleranceDisplay
	plmxml_api::Result SetToleranceDisplay( const eAnn3DDimensionTolerance& arg );

	//! Get ToleranceDisplay
	eAnn3DDimensionTolerance GetToleranceDisplay() const;

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set LinearPlacement
	plmxml_api::Result SetLinearPlacement( const eAnn3DDimDiameterPlacement& arg );

	//! Get LinearPlacement
	eAnn3DDimDiameterPlacement GetLinearPlacement() const;

	//! Set ZeroToleranceSign
	plmxml_api::Result SetZeroToleranceSign( const eAnn3DZeroToleranceSignEnum& arg );

	//! Get ZeroToleranceSign
	eAnn3DZeroToleranceSignEnum GetZeroToleranceSign() const;

	//! Set SingleSideLength
	plmxml_api::Result SetSingleSideLength( double arg );

     //! Get SingleSideLength
	double GetSingleSideLength() const;

	//! Check if SingleSideLength is set
	plmxml_api::logical HasSingleSideLength() const;

	//! Unset SingleSideLength
	plmxml_api::Result UnsetSingleSideLength();

	//! Set LimitFitOrder
	plmxml_api::Result SetLimitFitOrder( const eAnn3DLimitFitOrderEnum& arg );

	//! Get LimitFitOrder
	eAnn3DLimitFitOrderEnum GetLimitFitOrder() const;

	//! Set SingleSided
	plmxml_api::Result SetSingleSided( plmxml_api::logical arg );

	//! Get SingleSided
	plmxml_api::logical GetSingleSided() const;

	//! Check if SingleSided is set
	plmxml_api::logical HasSingleSided() const;

	//! Unset SingleSided
	plmxml_api::Result UnsetSingleSided();

	//! Set DimensionLineBetweenArrows
	plmxml_api::Result SetDimensionLineBetweenArrows( plmxml_api::logical arg );

	//! Get DimensionLineBetweenArrows
	plmxml_api::logical GetDimensionLineBetweenArrows() const;

	//! Check if DimensionLineBetweenArrows is set
	plmxml_api::logical HasDimensionLineBetweenArrows() const;

	//! Unset DimensionLineBetweenArrows
	plmxml_api::Result UnsetDimensionLineBetweenArrows();

	//! Set ZeroToleranceDisplay
	plmxml_api::Result SetZeroToleranceDisplay( const eAnn3DDimensionZeroToleranceDisplay& arg );

	//! Get ZeroToleranceDisplay
	eAnn3DDimensionZeroToleranceDisplay GetZeroToleranceDisplay() const;

	//! Set TolerancePrecision
	plmxml_api::Result SetTolerancePrecision( int arg );
     
	//! Get TolerancePrecision
	int GetTolerancePrecision() const;
     
	//! Check if TolerancePrecision is set
	plmxml_api::logical HasTolerancePrecision() const;
     
	//! Unset TolerancePrecision
	plmxml_api::Result UnsetTolerancePrecision();

	//! Set NarrowLeaderAngle
	plmxml_api::Result SetNarrowLeaderAngle( double arg );

     //! Get NarrowLeaderAngle
	double GetNarrowLeaderAngle() const;

	//! Check if NarrowLeaderAngle is set
	plmxml_api::logical HasNarrowLeaderAngle() const;

	//! Unset NarrowLeaderAngle
	plmxml_api::Result UnsetNarrowLeaderAngle();

	//! Set DimensionLeadingZero
	plmxml_api::Result SetDimensionLeadingZero( plmxml_api::logical arg );

	//! Get DimensionLeadingZero
	plmxml_api::logical GetDimensionLeadingZero() const;

	//! Check if DimensionLeadingZero is set
	plmxml_api::logical HasDimensionLeadingZero() const;

	//! Unset DimensionLeadingZero
	plmxml_api::Result UnsetDimensionLeadingZero();

	//! Set TextOrientationType
	plmxml_api::Result SetTextOrientationType( const eAnn3DTextOrientationEnum& arg );

	//! Get TextOrientationType
	eAnn3DTextOrientationEnum GetTextOrientationType() const;

	//! Set DualValueDenominator
	plmxml_api::Result SetDualValueDenominator( int arg );
     
	//! Get DualValueDenominator
	int GetDualValueDenominator() const;
     
	//! Check if DualValueDenominator is set
	plmxml_api::logical HasDualValueDenominator() const;
     
	//! Unset DualValueDenominator
	plmxml_api::Result UnsetDualValueDenominator();

	//! Set DiameterPlacement
	plmxml_api::Result SetDiameterPlacement( const eAnn3DDimDiameterPlacement& arg );

	//! Get DiameterPlacement
	eAnn3DDimDiameterPlacement GetDiameterPlacement() const;

	//! Set DualTolerancePrecision
	plmxml_api::Result SetDualTolerancePrecision( int arg );
     
	//! Get DualTolerancePrecision
	int GetDualTolerancePrecision() const;
     
	//! Check if DualTolerancePrecision is set
	plmxml_api::logical HasDualTolerancePrecision() const;
     
	//! Unset DualTolerancePrecision
	plmxml_api::Result UnsetDualTolerancePrecision();

	//! Set RadialPlacement
	plmxml_api::Result SetRadialPlacement( const eAnn3DDimDiameterPlacement& arg );

	//! Get RadialPlacement
	eAnn3DDimDiameterPlacement GetRadialPlacement() const;

	//! Set NarrowOffset
	plmxml_api::Result SetNarrowOffset( double arg );

     //! Get NarrowOffset
	double GetNarrowOffset() const;

	//! Check if NarrowOffset is set
	plmxml_api::logical HasNarrowOffset() const;

	//! Unset NarrowOffset
	plmxml_api::Result UnsetNarrowOffset();

	//! Set FoldLocation using plmxml_api::Vector components
	plmxml_api::Result SetFoldLocation( const plmxml_api::Vector& arg );

	//! Get FoldLocation as plmxml_api::Vector
	plmxml_api::Result GetFoldLocation( plmxml_api::Vector& arg ) const;

	//! Check if FoldLocation is set
	plmxml_api::logical HasFoldLocation() const;

	//! Unset FoldLocation
	plmxml_api::Result UnsetFoldLocation();

	//! Set SingleSideFirst
	plmxml_api::Result SetSingleSideFirst( plmxml_api::logical arg );

	//! Get SingleSideFirst
	plmxml_api::logical GetSingleSideFirst() const;

	//! Check if SingleSideFirst is set
	plmxml_api::logical HasSingleSideFirst() const;

	//! Unset SingleSideFirst
	plmxml_api::Result UnsetSingleSideFirst();

	//! Set Inspection
	plmxml_api::Result SetInspection( plmxml_api::logical arg );

	//! Get Inspection
	plmxml_api::logical GetInspection() const;

	//! Check if Inspection is set
	plmxml_api::logical HasInspection() const;

	//! Unset Inspection
	plmxml_api::Result UnsetInspection();

	//! Set UnitText
	plmxml_api::Result SetUnitText( plmxml_api::logical arg );

	//! Get UnitText
	plmxml_api::logical GetUnitText() const;

	//! Check if UnitText is set
	plmxml_api::logical HasUnitText() const;

	//! Unset UnitText
	plmxml_api::Result UnsetUnitText();

	//! Set AngleFormat
	plmxml_api::Result SetAngleFormat( const eAnn3DAngleFormat& arg );

	//! Get AngleFormat
	eAnn3DAngleFormat GetAngleFormat() const;

	//! Set ValueDenominator
	plmxml_api::Result SetValueDenominator( int arg );
     
	//! Get ValueDenominator
	int GetValueDenominator() const;
     
	//! Check if ValueDenominator is set
	plmxml_api::logical HasValueDenominator() const;
     
	//! Unset ValueDenominator
	plmxml_api::Result UnsetValueDenominator();

	//! Set StatisticalPlacement
	plmxml_api::Result SetStatisticalPlacement( const eAnn3DDimStatisticalPlacement& arg );

	//! Get StatisticalPlacement
	eAnn3DDimStatisticalPlacement GetStatisticalPlacement() const;

	//! Set UpperDeltaDenominator
	plmxml_api::Result SetUpperDeltaDenominator( int arg );
     
	//! Get UpperDeltaDenominator
	int GetUpperDeltaDenominator() const;
     
	//! Check if UpperDeltaDenominator is set
	plmxml_api::logical HasUpperDeltaDenominator() const;
     
	//! Unset UpperDeltaDenominator
	plmxml_api::Result UnsetUpperDeltaDenominator();

	//! Set DualType
	plmxml_api::Result SetDualType( const eAnn3DDimensionDual& arg );

	//! Get DualType
	eAnn3DDimensionDual GetDualType() const;

	//! Set ToleranceTrailingZero
	plmxml_api::Result SetToleranceTrailingZero( plmxml_api::logical arg );

	//! Get ToleranceTrailingZero
	plmxml_api::logical GetToleranceTrailingZero() const;

	//! Check if ToleranceTrailingZero is set
	plmxml_api::logical HasToleranceTrailingZero() const;

	//! Unset ToleranceTrailingZero
	plmxml_api::Result UnsetToleranceTrailingZero();

	//! Get DualUnits of this DimensionDisplay
	plmxml_api::String GetDualUnits() const;

	//! Set DualUnits of this DimensionDisplay
	plmxml_api::Result SetDualUnits( const plmxml_api::String &s );
	
	//! Check if DualUnits is set
	plmxml_api::logical HasDualUnits( ) const;
	
	//! Unset DualUnits
	plmxml_api::Result UnsetDualUnits( );

	//! Set OrdinateBaselineZero
	plmxml_api::Result SetOrdinateBaselineZero( plmxml_api::logical arg );

	//! Get OrdinateBaselineZero
	plmxml_api::logical GetOrdinateBaselineZero() const;

	//! Check if OrdinateBaselineZero is set
	plmxml_api::logical HasOrdinateBaselineZero() const;

	//! Unset OrdinateBaselineZero
	plmxml_api::Result UnsetOrdinateBaselineZero();

	//! Set LowerDeltaDenominator
	plmxml_api::Result SetLowerDeltaDenominator( int arg );
     
	//! Get LowerDeltaDenominator
	int GetLowerDeltaDenominator() const;
     
	//! Check if LowerDeltaDenominator is set
	plmxml_api::logical HasLowerDeltaDenominator() const;
     
	//! Unset LowerDeltaDenominator
	plmxml_api::Result UnsetLowerDeltaDenominator();

	//! Set InspectionDisplay
	plmxml_api::Result SetInspectionDisplay( const eAnn3DInspectionDisplayEnum& arg );

	//! Get InspectionDisplay
	eAnn3DInspectionDisplayEnum GetInspectionDisplay() const;

	//! Get DualUnit URI as plmxml_api::String
	plmxml_api::String GetDualUnitURI() const;

	//! Set DualUnit URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDualUnitURI( const plmxml_api::String& );
	
	//! Get the handle of DualUnit URI. Does not resolve the URI.
	plmxml_api::Result GetDualUnitURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of DualUnit URI. URI string is unchanged.
	plmxml_api::Result SetDualUnitURI( const plmxml_api::Handle& );
	
	//! Resolve DualUnit URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDualUnitURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset DualUnit URI. Clears URI string and handle.
	plmxml_api::Result DeleteDualUnitURI();
	
	//! Check if DualUnit URI is set
	plmxml_api::logical HasDualUnitURI( ) const;
	

	//! Set DualPrecision
	plmxml_api::Result SetDualPrecision( int arg );
     
	//! Get DualPrecision
	int GetDualPrecision() const;
     
	//! Check if DualPrecision is set
	plmxml_api::logical HasDualPrecision() const;
     
	//! Unset DualPrecision
	plmxml_api::Result UnsetDualPrecision();

	//! Set DualDimensionLineCenter
	plmxml_api::Result SetDualDimensionLineCenter( plmxml_api::logical arg );

	//! Get DualDimensionLineCenter
	plmxml_api::logical GetDualDimensionLineCenter() const;

	//! Check if DualDimensionLineCenter is set
	plmxml_api::logical HasDualDimensionLineCenter() const;

	//! Unset DualDimensionLineCenter
	plmxml_api::Result UnsetDualDimensionLineCenter();

	//! Set DualLowerDeltaDenominator
	plmxml_api::Result SetDualLowerDeltaDenominator( int arg );
     
	//! Get DualLowerDeltaDenominator
	int GetDualLowerDeltaDenominator() const;
     
	//! Check if DualLowerDeltaDenominator is set
	plmxml_api::logical HasDualLowerDeltaDenominator() const;
     
	//! Unset DualLowerDeltaDenominator
	plmxml_api::Result UnsetDualLowerDeltaDenominator();

	//! Set ToleranceLeadingZero
	plmxml_api::Result SetToleranceLeadingZero( plmxml_api::logical arg );

	//! Get ToleranceLeadingZero
	plmxml_api::logical GetToleranceLeadingZero() const;

	//! Check if ToleranceLeadingZero is set
	plmxml_api::logical HasToleranceLeadingZero() const;

	//! Unset ToleranceLeadingZero
	plmxml_api::Result UnsetToleranceLeadingZero();

	//! Set TextLeaderPosition
	plmxml_api::Result SetTextLeaderPosition( const eAnn3DTextLeaderPositionEnum& arg );

	//! Get TextLeaderPosition
	eAnn3DTextLeaderPositionEnum GetTextLeaderPosition() const;

	//! Set DualPlacement
	plmxml_api::Result SetDualPlacement( const eAnn3DDimensionDualPlacement& arg );

	//! Get DualPlacement
	eAnn3DDimensionDualPlacement GetDualPlacement() const;

	//! Set ReferenceContent
	plmxml_api::Result SetReferenceContent( const eAnn3DReferenceContentEnum& arg );

	//! Get ReferenceContent
	eAnn3DReferenceContentEnum GetReferenceContent() const;

	//! Set Style
	plmxml_api::Result SetStyle( const eAnn3DDimensionStyle& arg );

	//! Get Style
	eAnn3DDimensionStyle GetStyle() const;

	//! Set DimensionTrailingZero
	plmxml_api::Result SetDimensionTrailingZero( plmxml_api::logical arg );

	//! Get DimensionTrailingZero
	plmxml_api::logical GetDimensionTrailingZero() const;

	//! Check if DimensionTrailingZero is set
	plmxml_api::logical HasDimensionTrailingZero() const;

	//! Unset DimensionTrailingZero
	plmxml_api::Result UnsetDimensionTrailingZero();

	//! Set ToleranceAngleFormat
	plmxml_api::Result SetToleranceAngleFormat( const eAnn3DAngleFormat& arg );

	//! Get ToleranceAngleFormat
	eAnn3DAngleFormat GetToleranceAngleFormat() const;

	//! Set DimensionLineTrim
	plmxml_api::Result SetDimensionLineTrim( plmxml_api::logical arg );

	//! Get DimensionLineTrim
	plmxml_api::logical GetDimensionLineTrim() const;

	//! Check if DimensionLineTrim is set
	plmxml_api::logical HasDimensionLineTrim() const;

	//! Unset DimensionLineTrim
	plmxml_api::Result UnsetDimensionLineTrim();

	//! Set AppendedTextSpaceFactor
	plmxml_api::Result SetAppendedTextSpaceFactor( double arg );

     //! Get AppendedTextSpaceFactor
	double GetAppendedTextSpaceFactor() const;

	//! Check if AppendedTextSpaceFactor is set
	plmxml_api::logical HasAppendedTextSpaceFactor() const;

	//! Unset AppendedTextSpaceFactor
	plmxml_api::Result UnsetAppendedTextSpaceFactor();

	//! Set DualUpperDeltaDenominator
	plmxml_api::Result SetDualUpperDeltaDenominator( int arg );
     
	//! Get DualUpperDeltaDenominator
	int GetDualUpperDeltaDenominator() const;
     
	//! Check if DualUpperDeltaDenominator is set
	plmxml_api::logical HasDualUpperDeltaDenominator() const;
     
	//! Unset DualUpperDeltaDenominator
	plmxml_api::Result UnsetDualUpperDeltaDenominator();

	//! Set FractionSize
	plmxml_api::Result SetFractionSize( const eAnn3DFractionSizeEnum& arg );

	//! Get FractionSize
	eAnn3DFractionSizeEnum GetFractionSize() const;

	//! Set ReferenceDisplay
	plmxml_api::Result SetReferenceDisplay( const eAnn3DDimReferenceDisplay& arg );

	//! Get ReferenceDisplay
	eAnn3DDimReferenceDisplay GetReferenceDisplay() const;

	//! Set Fraction
	plmxml_api::Result SetFraction( plmxml_api::logical arg );

	//! Get Fraction
	plmxml_api::logical GetFraction() const;

	//! Check if Fraction is set
	plmxml_api::logical HasFraction() const;

	//! Unset Fraction
	plmxml_api::Result UnsetFraction();

	//! Set Alignment
	plmxml_api::Result SetAlignment( const eAnn3DFitDesignationAlignmentEnum& arg );

	//! Get Alignment
	eAnn3DFitDesignationAlignmentEnum GetAlignment() const;

	//! Set LimitDisplay
	plmxml_api::Result SetLimitDisplay( const eAnn3DLimitDisplayEnum& arg );

	//! Get LimitDisplay
	eAnn3DLimitDisplayEnum GetLimitDisplay() const;

	//! Set LimitFitParentheses
	plmxml_api::Result SetLimitFitParentheses( const eAnn3DLimitFitParenthesesEnum& arg );

	//! Get LimitFitParentheses
	eAnn3DLimitFitParenthesesEnum GetLimitFitParentheses() const;

	//! Add ToleranceTextFormat child element to this DimensionDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTextFormat *AddToleranceTextFormat();
     
	//! Set ToleranceTextFormat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetToleranceTextFormat( Ann3DTextFormat *arg );
     
	//! Get ToleranceTextFormat child element of this DimensionDisplay.
	Ann3DTextFormat *GetToleranceTextFormat() const;
     
	//! Detach and delete ToleranceTextFormat child element tree from this DimensionDisplay.
	void DeleteToleranceTextFormat();

	//! Add StyleText child element to this DimensionDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddStyleText();
     
	//! Set StyleText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStyleText( Ann3DText *arg );
     
	//! Get StyleText child element of this DimensionDisplay.
	Ann3DText *GetStyleText() const;
     
	//! Detach and delete StyleText child element tree from this DimensionDisplay.
	void DeleteStyleText();
 
// <PLMXML_UserCode type="functionHeaderDimensionDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassDimensionDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Fastener class
/*!
\verbatim

      Fastener Annotation

      Attributes:

      symbolType:          e.g. capScrew, hole, dowel, or other user-defined type
      threaded:            whether threaded or not
      counterbored:        whether counterbored or not
      diameter[]:          array of diameters
      depth[]:             array of depths
      axisDirection[3]:    axis direction of hole etc
      indexDirection[3]:   index direction - user-defined
      optDirection[3]:     optional direction - user-defined
      type:                user-defined type string to define the type of the Fastener
      fastenerSubType:     optional user-defined string to further clarify the type
                           of the Fastener
      position:            position of the Fastener in global space
        
      Elements:
      
      GeneralText:         general text
      CoordinatedEntity:   a text string specifying a related entity in some undefined way
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Fastener : public Annotation3D
{
public:
     
    //! Default constructor
    Fastener( );
     
    //! Constructs a Fastener with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Fastener( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Fastener();

private:

	//! Assignment operator
	Fastener& operator=( const Fastener& iSrc );

	//! Copy constructor
	Fastener( const Fastener& original );
     
public:

	//! Set Depth
	plmxml_api::Result SetDepth( const plmxml_api::Array<double>& arg );

	//! Get Depth
	plmxml_api::Result GetDepth( plmxml_api::Array<double>& arg ) const;

	//! Check if Depth is set
	plmxml_api::logical HasDepth() const;

	//! Unset Depth
	plmxml_api::Result UnsetDepth();

	//! Set Counterbored
	plmxml_api::Result SetCounterbored( plmxml_api::logical arg );

	//! Get Counterbored
	plmxml_api::logical GetCounterbored() const;

	//! Check if Counterbored is set
	plmxml_api::logical HasCounterbored() const;

	//! Unset Counterbored
	plmxml_api::Result UnsetCounterbored();

	//! Set IndexDirection using plmxml_api::Vector components
	plmxml_api::Result SetIndexDirection( const plmxml_api::Vector& arg );

	//! Get IndexDirection as plmxml_api::Vector
	plmxml_api::Result GetIndexDirection( plmxml_api::Vector& arg ) const;

	//! Check if IndexDirection is set
	plmxml_api::logical HasIndexDirection() const;

	//! Unset IndexDirection
	plmxml_api::Result UnsetIndexDirection();

	//! Set OptDirection using plmxml_api::Vector components
	plmxml_api::Result SetOptDirection( const plmxml_api::Vector& arg );

	//! Get OptDirection as plmxml_api::Vector
	plmxml_api::Result GetOptDirection( plmxml_api::Vector& arg ) const;

	//! Check if OptDirection is set
	plmxml_api::logical HasOptDirection() const;

	//! Unset OptDirection
	plmxml_api::Result UnsetOptDirection();

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();

	//! Get Type of this Fastener
	plmxml_api::String GetType() const;

	//! Set Type of this Fastener
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Set Diameter
	plmxml_api::Result SetDiameter( const plmxml_api::Array<double>& arg );

	//! Get Diameter
	plmxml_api::Result GetDiameter( plmxml_api::Array<double>& arg ) const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Get FastenerSubType of this Fastener
	plmxml_api::String GetFastenerSubType() const;

	//! Set FastenerSubType of this Fastener
	plmxml_api::Result SetFastenerSubType( const plmxml_api::String &s );
	
	//! Check if FastenerSubType is set
	plmxml_api::logical HasFastenerSubType( ) const;
	
	//! Unset FastenerSubType
	plmxml_api::Result UnsetFastenerSubType( );

	//! Get SymbolType of this Fastener
	plmxml_api::String GetSymbolType() const;

	//! Set SymbolType of this Fastener
	plmxml_api::Result SetSymbolType( const plmxml_api::String &s );
	
	//! Check if SymbolType is set
	plmxml_api::logical HasSymbolType( ) const;
	
	//! Unset SymbolType
	plmxml_api::Result UnsetSymbolType( );

	//! Set Threaded
	plmxml_api::Result SetThreaded( plmxml_api::logical arg );

	//! Get Threaded
	plmxml_api::logical GetThreaded() const;

	//! Check if Threaded is set
	plmxml_api::logical HasThreaded() const;

	//! Unset Threaded
	plmxml_api::Result UnsetThreaded();

	//! Set AxisDirection using plmxml_api::Vector components
	plmxml_api::Result SetAxisDirection( const plmxml_api::Vector& arg );

	//! Get AxisDirection as plmxml_api::Vector
	plmxml_api::Result GetAxisDirection( plmxml_api::Vector& arg ) const;

	//! Check if AxisDirection is set
	plmxml_api::logical HasAxisDirection() const;

	//! Unset AxisDirection
	plmxml_api::Result UnsetAxisDirection();

	//! Add GeneralText child element to this Fastener. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddGeneralText();
     
	//! Set GeneralText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetGeneralText( Ann3DText *arg );
     
	//! Get GeneralText child element of this Fastener.
	Ann3DText *GetGeneralText() const;
     
	//! Detach and delete GeneralText child element tree from this Fastener.
	void DeleteGeneralText();

	//! Add CoordinatedEntity child element to this Fastener. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCoordinatedEntity();
     
	//! Add 'arg' as CoordinatedEntity child element to this Fastener.
	plmxml_api::Result AddCoordinatedEntity( Ann3DText *arg );

	//! Detach and delete all CoordinatedEntity child elements.
	void DeleteCoordinatedEntities();
     
	//! Get number of CoordinatedEntity child elements.
	int NumberOfCoordinatedEntities() const;
     
	//! Get i'th CoordinatedEntity child element.
	Ann3DText *GetCoordinatedEntity( int i ) const;
     
	//! Get all CoordinatedEntity child element as an array
	void GetCoordinatedEntities( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th CoordinatedEntity child element
	void DeleteCoordinatedEntity( int i );
     
	//! Detach and delete 'arg' if it's one of the CoordinatedEntity child elements
	void DeleteCoordinatedEntity( Ann3DText *arg );
 
// <PLMXML_UserCode type="functionHeaderFastener" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassFastener;


////////////////////////////////////////////////////////////////////////////////////
//! FastenerDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API FastenerDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    FastenerDisplay( );
     
    //! Constructs a FastenerDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FastenerDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FastenerDisplay();

private:

	//! Assignment operator
	FastenerDisplay& operator=( const FastenerDisplay& iSrc );

	//! Copy constructor
	FastenerDisplay( const FastenerDisplay& original );
     
public:

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set DisplayType
	plmxml_api::Result SetDisplayType( const eAnn3DFastenerDisplay& arg );

	//! Get DisplayType
	eAnn3DFastenerDisplay GetDisplayType() const;
 
// <PLMXML_UserCode type="functionHeaderFastenerDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassFastenerDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! SurfaceFinish class
/*!
\verbatim

      SurfaceFinish:    derived from Annotation3D

      Attributes:

      standard:         surface finish standard
      type:             The type of SurfaceFinish symbol: basic, MRR or MRP.
      modifier:         whether modifier added to symbol
      allAround:        whether All Around added to symbol
      allAroundLeader:  Whether the All Around symbol is added to the Leader of
                        the SurfaceFinish.
      lay:              parallel, perpendicular, etc
      machiningAllowance: also known as materialRemoval
      upperDelta:       upper and
      lowerDelta:       lower tolerance values for the machiningAllowance
      direction[3]:
      roughness:
      maxRoughness:
      minRoughness:
      roughnessSpacing:
      roughnessCutoff:  See the relevant Standard for details of these.
      wavinessHeight:   Although these are essentially numeric values,
      wavinessSpacing:  the Standards require them to be strings.
      roughness2:
      roughness3:       ESKD standard tertiary roughness.
      maxRoughness2:
      minRoughness2:
      jisSurfaceTexture: When standard is JIS_1982, jisSurfaceTexture is the
                        number of repeats of the JIS_1982 basic symbol.

      Elements:

      ProcessText:      Process Text element
      LayText:          Lay Text element.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API SurfaceFinish : public Annotation3D
{
public:
     
    //! Default constructor
    SurfaceFinish( );
     
    //! Constructs a SurfaceFinish with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SurfaceFinish( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SurfaceFinish();

private:

	//! Assignment operator
	SurfaceFinish& operator=( const SurfaceFinish& iSrc );

	//! Copy constructor
	SurfaceFinish( const SurfaceFinish& original );
     
public:

	//! Get RoughnessSpacing of this SurfaceFinish
	plmxml_api::String GetRoughnessSpacing() const;

	//! Set RoughnessSpacing of this SurfaceFinish
	plmxml_api::Result SetRoughnessSpacing( const plmxml_api::String &s );
	
	//! Check if RoughnessSpacing is set
	plmxml_api::logical HasRoughnessSpacing( ) const;
	
	//! Unset RoughnessSpacing
	plmxml_api::Result UnsetRoughnessSpacing( );

	//! Get MinRoughness2 of this SurfaceFinish
	plmxml_api::String GetMinRoughness2() const;

	//! Set MinRoughness2 of this SurfaceFinish
	plmxml_api::Result SetMinRoughness2( const plmxml_api::String &s );
	
	//! Check if MinRoughness2 is set
	plmxml_api::logical HasMinRoughness2( ) const;
	
	//! Unset MinRoughness2
	plmxml_api::Result UnsetMinRoughness2( );

	//! Get WavinessSpacing of this SurfaceFinish
	plmxml_api::String GetWavinessSpacing() const;

	//! Set WavinessSpacing of this SurfaceFinish
	plmxml_api::Result SetWavinessSpacing( const plmxml_api::String &s );
	
	//! Check if WavinessSpacing is set
	plmxml_api::logical HasWavinessSpacing( ) const;
	
	//! Unset WavinessSpacing
	plmxml_api::Result UnsetWavinessSpacing( );

	//! Get Roughness2 of this SurfaceFinish
	plmxml_api::String GetRoughness2() const;

	//! Set Roughness2 of this SurfaceFinish
	plmxml_api::Result SetRoughness2( const plmxml_api::String &s );
	
	//! Check if Roughness2 is set
	plmxml_api::logical HasRoughness2( ) const;
	
	//! Unset Roughness2
	plmxml_api::Result UnsetRoughness2( );

	//! Get Roughness of this SurfaceFinish
	plmxml_api::String GetRoughness() const;

	//! Set Roughness of this SurfaceFinish
	plmxml_api::Result SetRoughness( const plmxml_api::String &s );
	
	//! Check if Roughness is set
	plmxml_api::logical HasRoughness( ) const;
	
	//! Unset Roughness
	plmxml_api::Result UnsetRoughness( );

	//! Get MaxRoughness of this SurfaceFinish
	plmxml_api::String GetMaxRoughness() const;

	//! Set MaxRoughness of this SurfaceFinish
	plmxml_api::Result SetMaxRoughness( const plmxml_api::String &s );
	
	//! Check if MaxRoughness is set
	plmxml_api::logical HasMaxRoughness( ) const;
	
	//! Unset MaxRoughness
	plmxml_api::Result UnsetMaxRoughness( );

	//! Set Lay
	plmxml_api::Result SetLay( const eAnn3DSurfaceFinishLay& arg );

	//! Get Lay
	eAnn3DSurfaceFinishLay GetLay() const;

	//! Get MaxRoughness2 of this SurfaceFinish
	plmxml_api::String GetMaxRoughness2() const;

	//! Set MaxRoughness2 of this SurfaceFinish
	plmxml_api::Result SetMaxRoughness2( const plmxml_api::String &s );
	
	//! Check if MaxRoughness2 is set
	plmxml_api::logical HasMaxRoughness2( ) const;
	
	//! Unset MaxRoughness2
	plmxml_api::Result UnsetMaxRoughness2( );

	//! Get Roughness3 of this SurfaceFinish
	plmxml_api::String GetRoughness3() const;

	//! Set Roughness3 of this SurfaceFinish
	plmxml_api::Result SetRoughness3( const plmxml_api::String &s );
	
	//! Check if Roughness3 is set
	plmxml_api::logical HasRoughness3( ) const;
	
	//! Unset Roughness3
	plmxml_api::Result UnsetRoughness3( );

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DSurfaceFinish& arg );

	//! Get Type
	eAnn3DSurfaceFinish GetType() const;

	//! Get MachiningAllowance of this SurfaceFinish
	plmxml_api::String GetMachiningAllowance() const;

	//! Set MachiningAllowance of this SurfaceFinish
	plmxml_api::Result SetMachiningAllowance( const plmxml_api::String &s );
	
	//! Check if MachiningAllowance is set
	plmxml_api::logical HasMachiningAllowance( ) const;
	
	//! Unset MachiningAllowance
	plmxml_api::Result UnsetMachiningAllowance( );

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DSurfaceFinishStandardType& arg );

	//! Get Standard
	eAnn3DSurfaceFinishStandardType GetStandard() const;

	//! Set UpperDelta
	plmxml_api::Result SetUpperDelta( double arg );

     //! Get UpperDelta
	double GetUpperDelta() const;

	//! Check if UpperDelta is set
	plmxml_api::logical HasUpperDelta() const;

	//! Unset UpperDelta
	plmxml_api::Result UnsetUpperDelta();

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Get WavinessHeight of this SurfaceFinish
	plmxml_api::String GetWavinessHeight() const;

	//! Set WavinessHeight of this SurfaceFinish
	plmxml_api::Result SetWavinessHeight( const plmxml_api::String &s );
	
	//! Check if WavinessHeight is set
	plmxml_api::logical HasWavinessHeight( ) const;
	
	//! Unset WavinessHeight
	plmxml_api::Result UnsetWavinessHeight( );

	//! Set Modifier
	plmxml_api::Result SetModifier( plmxml_api::logical arg );

	//! Get Modifier
	plmxml_api::logical GetModifier() const;

	//! Check if Modifier is set
	plmxml_api::logical HasModifier() const;

	//! Unset Modifier
	plmxml_api::Result UnsetModifier();

	//! Set JisSurfaceTexture
	plmxml_api::Result SetJisSurfaceTexture( int arg );
     
	//! Get JisSurfaceTexture
	int GetJisSurfaceTexture() const;
     
	//! Check if JisSurfaceTexture is set
	plmxml_api::logical HasJisSurfaceTexture() const;
     
	//! Unset JisSurfaceTexture
	plmxml_api::Result UnsetJisSurfaceTexture();

	//! Get MinRoughness of this SurfaceFinish
	plmxml_api::String GetMinRoughness() const;

	//! Set MinRoughness of this SurfaceFinish
	plmxml_api::Result SetMinRoughness( const plmxml_api::String &s );
	
	//! Check if MinRoughness is set
	plmxml_api::logical HasMinRoughness( ) const;
	
	//! Unset MinRoughness
	plmxml_api::Result UnsetMinRoughness( );

	//! Set AllAroundLeader
	plmxml_api::Result SetAllAroundLeader( plmxml_api::logical arg );

	//! Get AllAroundLeader
	plmxml_api::logical GetAllAroundLeader() const;

	//! Check if AllAroundLeader is set
	plmxml_api::logical HasAllAroundLeader() const;

	//! Unset AllAroundLeader
	plmxml_api::Result UnsetAllAroundLeader();

	//! Get RoughnessCutoff of this SurfaceFinish
	plmxml_api::String GetRoughnessCutoff() const;

	//! Set RoughnessCutoff of this SurfaceFinish
	plmxml_api::Result SetRoughnessCutoff( const plmxml_api::String &s );
	
	//! Check if RoughnessCutoff is set
	plmxml_api::logical HasRoughnessCutoff( ) const;
	
	//! Unset RoughnessCutoff
	plmxml_api::Result UnsetRoughnessCutoff( );

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set LowerDelta
	plmxml_api::Result SetLowerDelta( double arg );

     //! Get LowerDelta
	double GetLowerDelta() const;

	//! Check if LowerDelta is set
	plmxml_api::logical HasLowerDelta() const;

	//! Unset LowerDelta
	plmxml_api::Result UnsetLowerDelta();

	//! Add ProcessText child element to this SurfaceFinish. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddProcessText();
     
	//! Set ProcessText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetProcessText( Ann3DText *arg );
     
	//! Get ProcessText child element of this SurfaceFinish.
	Ann3DText *GetProcessText() const;
     
	//! Detach and delete ProcessText child element tree from this SurfaceFinish.
	void DeleteProcessText();

	//! Add LayText child element to this SurfaceFinish. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddLayText();
     
	//! Set LayText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLayText( Ann3DText *arg );
     
	//! Get LayText child element of this SurfaceFinish.
	Ann3DText *GetLayText() const;
     
	//! Detach and delete LayText child element tree from this SurfaceFinish.
	void DeleteLayText();
 
// <PLMXML_UserCode type="functionHeaderSurfaceFinish" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassSurfaceFinish;


////////////////////////////////////////////////////////////////////////////////////
//! SurfaceFinishDisplay class
/*!
\verbatim

      Attributes:

      bottomExtensionLine:
      precision:
      toleranceDisplay:
      zeroToleranceDisplay:     Controls the display of a zero valued tolerance.
      toleranceLeadingZero:     Whether to display leading zeros in the
                                tolerance value.
      invertText:               Whether the text of the surface finish symbol is
                                inverted.
      toleranceTrailingZero:    Whether trailing zeros on tolerance values are
                                displayed.
      parenthesis:              The type of parenthesis(es) displayed if any.
      singleLine:               Whether the lay and roughness values are displayed
                                on a single line. singleLine is applicable only
                                when standard on the corresponding SurfaceFinish
                                is ESKD.
      invertSymbol:             Whether the surface finish symbol is inverted.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API SurfaceFinishDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    SurfaceFinishDisplay( );
     
    //! Constructs a SurfaceFinishDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SurfaceFinishDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SurfaceFinishDisplay();

private:

	//! Assignment operator
	SurfaceFinishDisplay& operator=( const SurfaceFinishDisplay& iSrc );

	//! Copy constructor
	SurfaceFinishDisplay( const SurfaceFinishDisplay& original );
     
public:

	//! Set ToleranceTrailingZero
	plmxml_api::Result SetToleranceTrailingZero( plmxml_api::logical arg );

	//! Get ToleranceTrailingZero
	plmxml_api::logical GetToleranceTrailingZero() const;

	//! Check if ToleranceTrailingZero is set
	plmxml_api::logical HasToleranceTrailingZero() const;

	//! Unset ToleranceTrailingZero
	plmxml_api::Result UnsetToleranceTrailingZero();

	//! Set ToleranceLeadingZero
	plmxml_api::Result SetToleranceLeadingZero( plmxml_api::logical arg );

	//! Get ToleranceLeadingZero
	plmxml_api::logical GetToleranceLeadingZero() const;

	//! Check if ToleranceLeadingZero is set
	plmxml_api::logical HasToleranceLeadingZero() const;

	//! Unset ToleranceLeadingZero
	plmxml_api::Result UnsetToleranceLeadingZero();

	//! Set ToleranceDisplay
	plmxml_api::Result SetToleranceDisplay( const eAnn3DDimensionTolerance& arg );

	//! Get ToleranceDisplay
	eAnn3DDimensionTolerance GetToleranceDisplay() const;

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set InvertText
	plmxml_api::Result SetInvertText( plmxml_api::logical arg );

	//! Get InvertText
	plmxml_api::logical GetInvertText() const;

	//! Check if InvertText is set
	plmxml_api::logical HasInvertText() const;

	//! Unset InvertText
	plmxml_api::Result UnsetInvertText();

	//! Set InvertSymbol
	plmxml_api::Result SetInvertSymbol( plmxml_api::logical arg );

	//! Get InvertSymbol
	plmxml_api::logical GetInvertSymbol() const;

	//! Check if InvertSymbol is set
	plmxml_api::logical HasInvertSymbol() const;

	//! Unset InvertSymbol
	plmxml_api::Result UnsetInvertSymbol();

	//! Set ZeroToleranceDisplay
	plmxml_api::Result SetZeroToleranceDisplay( const eAnn3DDimensionZeroToleranceDisplay& arg );

	//! Get ZeroToleranceDisplay
	eAnn3DDimensionZeroToleranceDisplay GetZeroToleranceDisplay() const;

	//! Set SingleLine
	plmxml_api::Result SetSingleLine( plmxml_api::logical arg );

	//! Get SingleLine
	plmxml_api::logical GetSingleLine() const;

	//! Check if SingleLine is set
	plmxml_api::logical HasSingleLine() const;

	//! Unset SingleLine
	plmxml_api::Result UnsetSingleLine();

	//! Set BottomExtensionLine
	plmxml_api::Result SetBottomExtensionLine( plmxml_api::logical arg );

	//! Get BottomExtensionLine
	plmxml_api::logical GetBottomExtensionLine() const;

	//! Check if BottomExtensionLine is set
	plmxml_api::logical HasBottomExtensionLine() const;

	//! Unset BottomExtensionLine
	plmxml_api::Result UnsetBottomExtensionLine();

	//! Set Parenthesis
	plmxml_api::Result SetParenthesis( const eAnn3DParenthesisEnum& arg );

	//! Get Parenthesis
	eAnn3DParenthesisEnum GetParenthesis() const;
 
// <PLMXML_UserCode type="functionHeaderSurfaceFinishDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassSurfaceFinishDisplay;


//! Forward class declarations
class Ann3DFCFToleranceCompartment;
class Ann3DFCFDatumGroup;

////////////////////////////////////////////////////////////////////////////////////
//! FeatureControlFrame class
/*!
\verbatim

      FeatureControlFrame Annotation
      
      Attributes:
      
      standard:         as for Dimensions
      characteristic:   position, straightness, etc
      direction:        direction of tolerance application
      allAround:        all around symbol
      maxBonus:         true if a max bonus tolerance is used
      maxBonusValue:    max bonus tolerance
      profileType:      profile type
      profileValue:     profile tolerance value
      profileValue2:    profile tolerance value2 
                        (used when there are two compartments)
      allOver:          indicates the tolerance applies all over the 3
                        dimensional profile of the part

      Elements:
      
      Text:            general Text element
      ToleranceCompartment: one or more of these sub-elements. If there are two or more,
                            the FCF is composite.
      FCFText:          Text added to a FeatureControlFrame in a specified
                        position.
      Primary           first common DatumGroup of a composite FCF.
      Secondary         2nd common DatumGroup of a composite FCF.
      Tertiary          3rd common DatumGroup of a composite FCF.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API FeatureControlFrame : public Annotation3D
{
public:
     
    //! Default constructor
    FeatureControlFrame( );
     
    //! Constructs a FeatureControlFrame with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FeatureControlFrame( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FeatureControlFrame();

private:

	//! Assignment operator
	FeatureControlFrame& operator=( const FeatureControlFrame& iSrc );

	//! Copy constructor
	FeatureControlFrame( const FeatureControlFrame& original );
     
public:

	//! Set AllOver
	plmxml_api::Result SetAllOver( plmxml_api::logical arg );

	//! Get AllOver
	plmxml_api::logical GetAllOver() const;

	//! Check if AllOver is set
	plmxml_api::logical HasAllOver() const;

	//! Unset AllOver
	plmxml_api::Result UnsetAllOver();

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set ProfileValue2
	plmxml_api::Result SetProfileValue2( double arg );

     //! Get ProfileValue2
	double GetProfileValue2() const;

	//! Check if ProfileValue2 is set
	plmxml_api::logical HasProfileValue2() const;

	//! Unset ProfileValue2
	plmxml_api::Result UnsetProfileValue2();

	//! Set MaxBonus
	plmxml_api::Result SetMaxBonus( plmxml_api::logical arg );

	//! Get MaxBonus
	plmxml_api::logical GetMaxBonus() const;

	//! Check if MaxBonus is set
	plmxml_api::logical HasMaxBonus() const;

	//! Unset MaxBonus
	plmxml_api::Result UnsetMaxBonus();

	//! Set Characteristic
	plmxml_api::Result SetCharacteristic( const eAnn3DFCF& arg );

	//! Get Characteristic
	eAnn3DFCF GetCharacteristic() const;

	//! Set MaxBonusValue
	plmxml_api::Result SetMaxBonusValue( double arg );

     //! Get MaxBonusValue
	double GetMaxBonusValue() const;

	//! Check if MaxBonusValue is set
	plmxml_api::logical HasMaxBonusValue() const;

	//! Unset MaxBonusValue
	plmxml_api::Result UnsetMaxBonusValue();

	//! Set ProfileType
	plmxml_api::Result SetProfileType( const eAnn3DFCFProfileType& arg );

	//! Get ProfileType
	eAnn3DFCFProfileType GetProfileType() const;

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Set ProfileValue
	plmxml_api::Result SetProfileValue( double arg );

     //! Get ProfileValue
	double GetProfileValue() const;

	//! Check if ProfileValue is set
	plmxml_api::logical HasProfileValue() const;

	//! Unset ProfileValue
	plmxml_api::Result UnsetProfileValue();

	//! Add Text child element to this FeatureControlFrame. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddText();
     
	//! Set Text child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetText( Ann3DText *arg );
     
	//! Get Text child element of this FeatureControlFrame.
	Ann3DText *GetText() const;
     
	//! Detach and delete Text child element tree from this FeatureControlFrame.
	void DeleteText();

	//! Add ToleranceCompartment child element to this FeatureControlFrame. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFToleranceCompartment *AddToleranceCompartment();
     
	//! Add 'arg' as ToleranceCompartment child element to this FeatureControlFrame.
	plmxml_api::Result AddToleranceCompartment( Ann3DFCFToleranceCompartment *arg );

	//! Detach and delete all ToleranceCompartment child elements.
	void DeleteToleranceCompartments();
     
	//! Get number of ToleranceCompartment child elements.
	int NumberOfToleranceCompartments() const;
     
	//! Get i'th ToleranceCompartment child element.
	Ann3DFCFToleranceCompartment *GetToleranceCompartment( int i ) const;
     
	//! Get all ToleranceCompartment child element as an array
	void GetToleranceCompartments( plmxml_api::Array<Ann3DFCFToleranceCompartment*> &array ) const;
	     
	//! Detach and delete i'th ToleranceCompartment child element
	void DeleteToleranceCompartment( int i );
     
	//! Detach and delete 'arg' if it's one of the ToleranceCompartment child elements
	void DeleteToleranceCompartment( Ann3DFCFToleranceCompartment *arg );

	//! Add FCFText child element to this FeatureControlFrame. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddFCFText();
     
	//! Add 'arg' as FCFText child element to this FeatureControlFrame.
	plmxml_api::Result AddFCFText( Ann3DDimensionText *arg );

	//! Detach and delete all FCFText child elements.
	void DeleteFCFTexts();
     
	//! Get number of FCFText child elements.
	int NumberOfFCFTexts() const;
     
	//! Get i'th FCFText child element.
	Ann3DDimensionText *GetFCFText( int i ) const;
     
	//! Get all FCFText child element as an array
	void GetFCFTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th FCFText child element
	void DeleteFCFText( int i );
     
	//! Detach and delete 'arg' if it's one of the FCFText child elements
	void DeleteFCFText( Ann3DDimensionText *arg );

	//! Add Primary child element to this FeatureControlFrame. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddPrimary();
     
	//! Set Primary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPrimary( Ann3DFCFDatumGroup *arg );
     
	//! Get Primary child element of this FeatureControlFrame.
	Ann3DFCFDatumGroup *GetPrimary() const;
     
	//! Detach and delete Primary child element tree from this FeatureControlFrame.
	void DeletePrimary();

	//! Add Secondary child element to this FeatureControlFrame. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddSecondary();
     
	//! Set Secondary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSecondary( Ann3DFCFDatumGroup *arg );
     
	//! Get Secondary child element of this FeatureControlFrame.
	Ann3DFCFDatumGroup *GetSecondary() const;
     
	//! Detach and delete Secondary child element tree from this FeatureControlFrame.
	void DeleteSecondary();

	//! Add Tertiary child element to this FeatureControlFrame. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddTertiary();
     
	//! Set Tertiary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTertiary( Ann3DFCFDatumGroup *arg );
     
	//! Get Tertiary child element of this FeatureControlFrame.
	Ann3DFCFDatumGroup *GetTertiary() const;
     
	//! Detach and delete Tertiary child element tree from this FeatureControlFrame.
	void DeleteTertiary();
 
// <PLMXML_UserCode type="functionHeaderFeatureControlFrame" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassFeatureControlFrame;


//! Forward class declarations
class Ann3DFCFDatumGroup;
class Ann3DFCFIndicator;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DFCFToleranceCompartment class
/*!
\verbatim

      Ann3DFCFToleranceCompartmentType: derived from IdBase

      Attributes:

      value             tolerance value
      precision         number of decimal places
      modifier          lmc, mmc, or rfs
      zoneShape         diametral or spherical
      projected         flag indicating a projected tolerance
      projectedValue    value for projection
      projectionVector  direction of projection
      tangentPlane      ditto, tangent plane
      freeState         ditto, free state
      maxBonus          true if a max bonus tolerance is used
      maxBonusValue     max bonus tolerance
      unitBasis         true if a unit basis zone refinement is used
      unitBasisValue    unit basis zone refinement
      commonZone        whether the common zone refinement is present
      prefix            general prefix text, which appears before processing
                        other attributes
      suffix            general suffix text, which appears only after processing
                        the other attributes
      unequal           indicates a profile tolerance zone is unequally
                        disposed
      unequalValue      the outward portion of an unequally disposed profile
                        tolerance zone
      unequalDisplay:   How any unequal symbols in tolerance compartments are
                        displayed.
      maxBonusValueString: Non-numerical maximum bonus tolerance. Overrides
                        maxBonusValue.
      minimaxFeature:   Flag indicating a minimax (Chebyshev) feature.
      leastSquaresFeature: Flag indicating a least squares feature.
      minimumCircumscribedFeature: Flag indicating a minimum circumscribed
                        feature.
      maximumInscribedFeature: Flag indicating a maximum inscribed feature.
      derivedFeature:   Flag indicating a derived feature.
      dynamicProfile:   Flag indicating a dynamic profile.

      Elements:

      Primary           first DatumGroup
      Secondary         2nd DatumGroup
      Tertiary          3rd DatumGroup
      Statistical       statistical refinement
      FreeState         free state refinement
      TextUnitBasisValue this sub-element allows for the case where the
                        unitBasisValue is not simple text, but, for example,
                        contains symbols. The unitBasisValue attribute and the
                        TextUnitBasisValue sub-element should not be used
                        together.
      TextPrefix:       This sub-element allows for the case where the prefix is
                        not simple text, but, for example, contains symbols. The
                        prefix attribute and the TextPrefix sub-element should
                        not be used together.
      TextSuffix:       This sub-element allows for the case where the suffix is
                        not simple text, but, for example, contains symbols. The
                        suffix attribute and the TextSuffix sub-element should
                        not be used together.
      BeforeIndicator:  Any number of indicators to the left of the FCF, ordered
                        left to right.
      AfterIndicator:   Any number of indicators to the right of the FCF,
                        ordered left to right.
      TextMaxBasisValue: This sub-element allows for the case where the
                        maxBonusValue is not simple text, but, for example,
                        contains symbols. The maxBonusValue attribute and the
                        TextMaxBonusValue sub-element should not be used
                        together.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DFCFToleranceCompartment : public IdObject
{
public:
     
    //! Default constructor
    Ann3DFCFToleranceCompartment( );
     
    //! Constructs a Ann3DFCFToleranceCompartment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DFCFToleranceCompartment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DFCFToleranceCompartment();

private:

	//! Assignment operator
	Ann3DFCFToleranceCompartment& operator=( const Ann3DFCFToleranceCompartment& iSrc );

	//! Copy constructor
	Ann3DFCFToleranceCompartment( const Ann3DFCFToleranceCompartment& original );
     
public:

	//! Set ZoneShape
	plmxml_api::Result SetZoneShape( const eAnn3DFCFZoneShape& arg );

	//! Get ZoneShape
	eAnn3DFCFZoneShape GetZoneShape() const;

	//! Set Unequal
	plmxml_api::Result SetUnequal( plmxml_api::logical arg );

	//! Get Unequal
	plmxml_api::logical GetUnequal() const;

	//! Check if Unequal is set
	plmxml_api::logical HasUnequal() const;

	//! Unset Unequal
	plmxml_api::Result UnsetUnequal();

	//! Set Modifier
	plmxml_api::Result SetModifier( const eAnn3DFCFModifier& arg );

	//! Get Modifier
	eAnn3DFCFModifier GetModifier() const;

	//! Set ProjectionVector using plmxml_api::Vector components
	plmxml_api::Result SetProjectionVector( const plmxml_api::Vector& arg );

	//! Get ProjectionVector as plmxml_api::Vector
	plmxml_api::Result GetProjectionVector( plmxml_api::Vector& arg ) const;

	//! Check if ProjectionVector is set
	plmxml_api::logical HasProjectionVector() const;

	//! Unset ProjectionVector
	plmxml_api::Result UnsetProjectionVector();

	//! Set DerivedFeature
	plmxml_api::Result SetDerivedFeature( plmxml_api::logical arg );

	//! Get DerivedFeature
	plmxml_api::logical GetDerivedFeature() const;

	//! Check if DerivedFeature is set
	plmxml_api::logical HasDerivedFeature() const;

	//! Unset DerivedFeature
	plmxml_api::Result UnsetDerivedFeature();

	//! Get UnequalValue of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetUnequalValue() const;

	//! Set UnequalValue of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetUnequalValue( const plmxml_api::String &s );
	
	//! Check if UnequalValue is set
	plmxml_api::logical HasUnequalValue( ) const;
	
	//! Unset UnequalValue
	plmxml_api::Result UnsetUnequalValue( );

	//! Set UnitBasis
	plmxml_api::Result SetUnitBasis( plmxml_api::logical arg );

	//! Get UnitBasis
	plmxml_api::logical GetUnitBasis() const;

	//! Check if UnitBasis is set
	plmxml_api::logical HasUnitBasis() const;

	//! Unset UnitBasis
	plmxml_api::Result UnsetUnitBasis();

	//! Get Prefix of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetPrefix() const;

	//! Set Prefix of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetPrefix( const plmxml_api::String &s );
	
	//! Check if Prefix is set
	plmxml_api::logical HasPrefix( ) const;
	
	//! Unset Prefix
	plmxml_api::Result UnsetPrefix( );

	//! Set MinimaxFeature
	plmxml_api::Result SetMinimaxFeature( plmxml_api::logical arg );

	//! Get MinimaxFeature
	plmxml_api::logical GetMinimaxFeature() const;

	//! Check if MinimaxFeature is set
	plmxml_api::logical HasMinimaxFeature() const;

	//! Unset MinimaxFeature
	plmxml_api::Result UnsetMinimaxFeature();

	//! Set Projected
	plmxml_api::Result SetProjected( plmxml_api::logical arg );

	//! Get Projected
	plmxml_api::logical GetProjected() const;

	//! Check if Projected is set
	plmxml_api::logical HasProjected() const;

	//! Unset Projected
	plmxml_api::Result UnsetProjected();

	//! Set UnequalDisplay
	plmxml_api::Result SetUnequalDisplay( const eAnn3DFCFUnequalDisplayEnum& arg );

	//! Get UnequalDisplay
	eAnn3DFCFUnequalDisplayEnum GetUnequalDisplay() const;

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Get Suffix of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetSuffix() const;

	//! Set Suffix of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetSuffix( const plmxml_api::String &s );
	
	//! Check if Suffix is set
	plmxml_api::logical HasSuffix( ) const;
	
	//! Unset Suffix
	plmxml_api::Result UnsetSuffix( );

	//! Get MaxBonusValueString of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetMaxBonusValueString() const;

	//! Set MaxBonusValueString of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetMaxBonusValueString( const plmxml_api::String &s );
	
	//! Check if MaxBonusValueString is set
	plmxml_api::logical HasMaxBonusValueString( ) const;
	
	//! Unset MaxBonusValueString
	plmxml_api::Result UnsetMaxBonusValueString( );

	//! Set MaxBonusValue
	plmxml_api::Result SetMaxBonusValue( double arg );

     //! Get MaxBonusValue
	double GetMaxBonusValue() const;

	//! Check if MaxBonusValue is set
	plmxml_api::logical HasMaxBonusValue() const;

	//! Unset MaxBonusValue
	plmxml_api::Result UnsetMaxBonusValue();

	//! Get ProjectedValue of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetProjectedValue() const;

	//! Set ProjectedValue of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetProjectedValue( const plmxml_api::String &s );
	
	//! Check if ProjectedValue is set
	plmxml_api::logical HasProjectedValue( ) const;
	
	//! Unset ProjectedValue
	plmxml_api::Result UnsetProjectedValue( );

	//! Set DynamicProfile
	plmxml_api::Result SetDynamicProfile( plmxml_api::logical arg );

	//! Get DynamicProfile
	plmxml_api::logical GetDynamicProfile() const;

	//! Check if DynamicProfile is set
	plmxml_api::logical HasDynamicProfile() const;

	//! Unset DynamicProfile
	plmxml_api::Result UnsetDynamicProfile();

	//! Set MaxBonus
	plmxml_api::Result SetMaxBonus( plmxml_api::logical arg );

	//! Get MaxBonus
	plmxml_api::logical GetMaxBonus() const;

	//! Check if MaxBonus is set
	plmxml_api::logical HasMaxBonus() const;

	//! Unset MaxBonus
	plmxml_api::Result UnsetMaxBonus();

	//! Get UnitBasisValue of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetUnitBasisValue() const;

	//! Set UnitBasisValue of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetUnitBasisValue( const plmxml_api::String &s );
	
	//! Check if UnitBasisValue is set
	plmxml_api::logical HasUnitBasisValue( ) const;
	
	//! Unset UnitBasisValue
	plmxml_api::Result UnsetUnitBasisValue( );

	//! Set LeastSquaresFeature
	plmxml_api::Result SetLeastSquaresFeature( plmxml_api::logical arg );

	//! Get LeastSquaresFeature
	plmxml_api::logical GetLeastSquaresFeature() const;

	//! Check if LeastSquaresFeature is set
	plmxml_api::logical HasLeastSquaresFeature() const;

	//! Unset LeastSquaresFeature
	plmxml_api::Result UnsetLeastSquaresFeature();

	//! Set MinimumCircumscribedFeature
	plmxml_api::Result SetMinimumCircumscribedFeature( plmxml_api::logical arg );

	//! Get MinimumCircumscribedFeature
	plmxml_api::logical GetMinimumCircumscribedFeature() const;

	//! Check if MinimumCircumscribedFeature is set
	plmxml_api::logical HasMinimumCircumscribedFeature() const;

	//! Unset MinimumCircumscribedFeature
	plmxml_api::Result UnsetMinimumCircumscribedFeature();

	//! Get Value of this Ann3DFCFToleranceCompartment
	plmxml_api::String GetValue() const;

	//! Set Value of this Ann3DFCFToleranceCompartment
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Set TangentPlane
	plmxml_api::Result SetTangentPlane( plmxml_api::logical arg );

	//! Get TangentPlane
	plmxml_api::logical GetTangentPlane() const;

	//! Check if TangentPlane is set
	plmxml_api::logical HasTangentPlane() const;

	//! Unset TangentPlane
	plmxml_api::Result UnsetTangentPlane();

	//! Set MaximumInscribedFeature
	plmxml_api::Result SetMaximumInscribedFeature( plmxml_api::logical arg );

	//! Get MaximumInscribedFeature
	plmxml_api::logical GetMaximumInscribedFeature() const;

	//! Check if MaximumInscribedFeature is set
	plmxml_api::logical HasMaximumInscribedFeature() const;

	//! Unset MaximumInscribedFeature
	plmxml_api::Result UnsetMaximumInscribedFeature();

	//! Set CommonZone
	plmxml_api::Result SetCommonZone( plmxml_api::logical arg );

	//! Get CommonZone
	plmxml_api::logical GetCommonZone() const;

	//! Check if CommonZone is set
	plmxml_api::logical HasCommonZone() const;

	//! Unset CommonZone
	plmxml_api::Result UnsetCommonZone();

	//! Add Primary child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddPrimary();
     
	//! Set Primary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPrimary( Ann3DFCFDatumGroup *arg );
     
	//! Get Primary child element of this Ann3DFCFToleranceCompartment.
	Ann3DFCFDatumGroup *GetPrimary() const;
     
	//! Detach and delete Primary child element tree from this Ann3DFCFToleranceCompartment.
	void DeletePrimary();

	//! Add Secondary child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddSecondary();
     
	//! Set Secondary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSecondary( Ann3DFCFDatumGroup *arg );
     
	//! Get Secondary child element of this Ann3DFCFToleranceCompartment.
	Ann3DFCFDatumGroup *GetSecondary() const;
     
	//! Detach and delete Secondary child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteSecondary();

	//! Add Tertiary child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddTertiary();
     
	//! Set Tertiary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTertiary( Ann3DFCFDatumGroup *arg );
     
	//! Get Tertiary child element of this Ann3DFCFToleranceCompartment.
	Ann3DFCFDatumGroup *GetTertiary() const;
     
	//! Detach and delete Tertiary child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteTertiary();

	//! Add Statistical child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DStatisticalRefinement *AddStatistical();
     
	//! Set Statistical child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStatistical( Ann3DStatisticalRefinement *arg );
     
	//! Get Statistical child element of this Ann3DFCFToleranceCompartment.
	Ann3DStatisticalRefinement *GetStatistical() const;
     
	//! Detach and delete Statistical child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteStatistical();

	//! Add FreeState child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFreeStateRefinement *AddFreeState();
     
	//! Set FreeState child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFreeState( Ann3DFreeStateRefinement *arg );
     
	//! Get FreeState child element of this Ann3DFCFToleranceCompartment.
	Ann3DFreeStateRefinement *GetFreeState() const;
     
	//! Detach and delete FreeState child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteFreeState();

	//! Add TextUnitBasisValue child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddTextUnitBasisValue();
     
	//! Set TextUnitBasisValue child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTextUnitBasisValue( Ann3DText *arg );
     
	//! Get TextUnitBasisValue child element of this Ann3DFCFToleranceCompartment.
	Ann3DText *GetTextUnitBasisValue() const;
     
	//! Detach and delete TextUnitBasisValue child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteTextUnitBasisValue();

	//! Add TextPrefix child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddTextPrefix();
     
	//! Set TextPrefix child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTextPrefix( Ann3DText *arg );
     
	//! Get TextPrefix child element of this Ann3DFCFToleranceCompartment.
	Ann3DText *GetTextPrefix() const;
     
	//! Detach and delete TextPrefix child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteTextPrefix();

	//! Add TextSuffix child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddTextSuffix();
     
	//! Set TextSuffix child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTextSuffix( Ann3DText *arg );
     
	//! Get TextSuffix child element of this Ann3DFCFToleranceCompartment.
	Ann3DText *GetTextSuffix() const;
     
	//! Detach and delete TextSuffix child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteTextSuffix();

	//! Add BeforeIndicator child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFIndicator *AddBeforeIndicator();
     
	//! Add 'arg' as BeforeIndicator child element to this Ann3DFCFToleranceCompartment.
	plmxml_api::Result AddBeforeIndicator( Ann3DFCFIndicator *arg );

	//! Detach and delete all BeforeIndicator child elements.
	void DeleteBeforeIndicators();
     
	//! Get number of BeforeIndicator child elements.
	int NumberOfBeforeIndicators() const;
     
	//! Get i'th BeforeIndicator child element.
	Ann3DFCFIndicator *GetBeforeIndicator( int i ) const;
     
	//! Get all BeforeIndicator child element as an array
	void GetBeforeIndicators( plmxml_api::Array<Ann3DFCFIndicator*> &array ) const;
	     
	//! Detach and delete i'th BeforeIndicator child element
	void DeleteBeforeIndicator( int i );
     
	//! Detach and delete 'arg' if it's one of the BeforeIndicator child elements
	void DeleteBeforeIndicator( Ann3DFCFIndicator *arg );

	//! Add AfterIndicator child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFIndicator *AddAfterIndicator();
     
	//! Add 'arg' as AfterIndicator child element to this Ann3DFCFToleranceCompartment.
	plmxml_api::Result AddAfterIndicator( Ann3DFCFIndicator *arg );

	//! Detach and delete all AfterIndicator child elements.
	void DeleteAfterIndicators();
     
	//! Get number of AfterIndicator child elements.
	int NumberOfAfterIndicators() const;
     
	//! Get i'th AfterIndicator child element.
	Ann3DFCFIndicator *GetAfterIndicator( int i ) const;
     
	//! Get all AfterIndicator child element as an array
	void GetAfterIndicators( plmxml_api::Array<Ann3DFCFIndicator*> &array ) const;
	     
	//! Detach and delete i'th AfterIndicator child element
	void DeleteAfterIndicator( int i );
     
	//! Detach and delete 'arg' if it's one of the AfterIndicator child elements
	void DeleteAfterIndicator( Ann3DFCFIndicator *arg );

	//! Add TextMaxBonusValue child element to this Ann3DFCFToleranceCompartment. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddTextMaxBonusValue();
     
	//! Set TextMaxBonusValue child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTextMaxBonusValue( Ann3DText *arg );
     
	//! Get TextMaxBonusValue child element of this Ann3DFCFToleranceCompartment.
	Ann3DText *GetTextMaxBonusValue() const;
     
	//! Detach and delete TextMaxBonusValue child element tree from this Ann3DFCFToleranceCompartment.
	void DeleteTextMaxBonusValue();
 
// <PLMXML_UserCode type="functionHeaderAnn3DFCFToleranceCompartment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DFCFToleranceCompartment;


//! Forward class declarations
class Ann3DFCFDatumReference;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DFCFDatumGroup class
/*!
\verbatim

      Ann3DFCFDatumGroupType: derived from IdBase

      Elements:

      Datum:         one or more DatumReference elements
      ExtendedText:  Text after the DatumReference(s) to clarify or customize
                     the datum feature boundary.
    
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DFCFDatumGroup : public IdObject
{
public:
     
    //! Default constructor
    Ann3DFCFDatumGroup( );
     
    //! Constructs a Ann3DFCFDatumGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DFCFDatumGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DFCFDatumGroup();

private:

	//! Assignment operator
	Ann3DFCFDatumGroup& operator=( const Ann3DFCFDatumGroup& iSrc );

	//! Copy constructor
	Ann3DFCFDatumGroup( const Ann3DFCFDatumGroup& original );
     
public:

	//! Add Datum child element to this Ann3DFCFDatumGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumReference *AddDatum();
     
	//! Add 'arg' as Datum child element to this Ann3DFCFDatumGroup.
	plmxml_api::Result AddDatum( Ann3DFCFDatumReference *arg );

	//! Detach and delete all Datum child elements.
	void DeleteDatums();
     
	//! Get number of Datum child elements.
	int NumberOfDatums() const;
     
	//! Get i'th Datum child element.
	Ann3DFCFDatumReference *GetDatum( int i ) const;
     
	//! Get all Datum child element as an array
	void GetDatums( plmxml_api::Array<Ann3DFCFDatumReference*> &array ) const;
	     
	//! Detach and delete i'th Datum child element
	void DeleteDatum( int i );
     
	//! Detach and delete 'arg' if it's one of the Datum child elements
	void DeleteDatum( Ann3DFCFDatumReference *arg );

	//! Add ExtendedText child element to this Ann3DFCFDatumGroup. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddExtendedText();
     
	//! Set ExtendedText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetExtendedText( Ann3DText *arg );
     
	//! Get ExtendedText child element of this Ann3DFCFDatumGroup.
	Ann3DText *GetExtendedText() const;
     
	//! Detach and delete ExtendedText child element tree from this Ann3DFCFDatumGroup.
	void DeleteExtendedText();
 
// <PLMXML_UserCode type="functionHeaderAnn3DFCFDatumGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DFCFDatumGroup;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DFCFDatumReference class
/*!
\verbatim

      Ann3DFCFDatumReference: derived from IdBase

      Attributes:

      modifier        lmc, mmc, or rfs
      datumRef        reference to the DatumFeatureSymbol element, if it exists
      label           the label (e.g. "A") of the DatumFeatureSymbol.
      projected       Whether the DatumFeatureSymbol is a projected feature.

      Elements:

      TextLabel       this sub-element allows for the case where the label is 
                      not simple text, but, for example, contains symbols. The label
                      attribute and the TextLabel sub-element should not be used together.
      FreeState       free state refinement
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DFCFDatumReference : public IdObject
{
public:
     
    //! Default constructor
    Ann3DFCFDatumReference( );
     
    //! Constructs a Ann3DFCFDatumReference with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DFCFDatumReference( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DFCFDatumReference();

private:

	//! Assignment operator
	Ann3DFCFDatumReference& operator=( const Ann3DFCFDatumReference& iSrc );

	//! Copy constructor
	Ann3DFCFDatumReference( const Ann3DFCFDatumReference& original );
     
public:

	//! Set reference to Datum using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetDatumRef( plmxml60::IdObject *arg );

	//! Clear reference to Datum
	void RemoveDatumRef( );

	//! Find a plmxml60::IdObject referenced by Datum
	plmxml60::IdObject *ResolveDatumRef( plmxml_api::Configuration* config = NULL );

	//! Get Datum reference
	plmxml_api::String GetDatumId() const;

	//! Set Datum reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetDatumId( const plmxml_api::String& u );
	
	//! Check if Datum is set
	plmxml_api::logical HasDatumRef( ) const;

	//! Set Modifier
	plmxml_api::Result SetModifier( const eAnn3DFCFModifier& arg );

	//! Get Modifier
	eAnn3DFCFModifier GetModifier() const;

	//! Set Projected
	plmxml_api::Result SetProjected( plmxml_api::logical arg );

	//! Get Projected
	plmxml_api::logical GetProjected() const;

	//! Check if Projected is set
	plmxml_api::logical HasProjected() const;

	//! Unset Projected
	plmxml_api::Result UnsetProjected();

	//! Get Label of this Ann3DFCFDatumReference
	plmxml_api::String GetLabel() const;

	//! Set Label of this Ann3DFCFDatumReference
	plmxml_api::Result SetLabel( const plmxml_api::String &s );
	
	//! Check if Label is set
	plmxml_api::logical HasLabel( ) const;
	
	//! Unset Label
	plmxml_api::Result UnsetLabel( );

	//! Add TextLabel child element to this Ann3DFCFDatumReference. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddTextLabel();
     
	//! Set TextLabel child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTextLabel( Ann3DText *arg );
     
	//! Get TextLabel child element of this Ann3DFCFDatumReference.
	Ann3DText *GetTextLabel() const;
     
	//! Detach and delete TextLabel child element tree from this Ann3DFCFDatumReference.
	void DeleteTextLabel();

	//! Add FreeState child element to this Ann3DFCFDatumReference. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFreeStateRefinement *AddFreeState();
     
	//! Set FreeState child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFreeState( Ann3DFreeStateRefinement *arg );
     
	//! Get FreeState child element of this Ann3DFCFDatumReference.
	Ann3DFreeStateRefinement *GetFreeState() const;
     
	//! Detach and delete FreeState child element tree from this Ann3DFCFDatumReference.
	void DeleteFreeState();
 
// <PLMXML_UserCode type="functionHeaderAnn3DFCFDatumReference" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DFCFDatumReference;


////////////////////////////////////////////////////////////////////////////////////
//! FeatureControlFrameDisplay class
/*!
\verbatim

      FeatureControlFrame Display.

      Attributes:

      maxBonusPrecision:
      angleFormat:
      projectedPrecision:
      leadingZero:      Whether leading zeros on the ToleranceCompartment value
                        are displayed.
      trailingZero:     Whether trailing zeros on the ToleranceCompartment value
                        are displayed.
      datumOnLeader:    Whether the Leader has an intermediate datum symbol
                        rather than going directly to the target geometry and,
                        if it has, whether the symbol is solid or filled.
      projectedBelow:   Whether any projected tolerance zone is displayed below
                        the tolerance compartment. By default, it is
                        incorporated into the tolerance compartment.
      fcfTextUnderline: How the FCFText elements on the FeatureControlFrame are
                        underlined.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API FeatureControlFrameDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    FeatureControlFrameDisplay( );
     
    //! Constructs a FeatureControlFrameDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FeatureControlFrameDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FeatureControlFrameDisplay();

private:

	//! Assignment operator
	FeatureControlFrameDisplay& operator=( const FeatureControlFrameDisplay& iSrc );

	//! Copy constructor
	FeatureControlFrameDisplay( const FeatureControlFrameDisplay& original );
     
public:

	//! Set ProjectedBelow
	plmxml_api::Result SetProjectedBelow( plmxml_api::logical arg );

	//! Get ProjectedBelow
	plmxml_api::logical GetProjectedBelow() const;

	//! Check if ProjectedBelow is set
	plmxml_api::logical HasProjectedBelow() const;

	//! Unset ProjectedBelow
	plmxml_api::Result UnsetProjectedBelow();

	//! Set ProjectedPrecision
	plmxml_api::Result SetProjectedPrecision( int arg );
     
	//! Get ProjectedPrecision
	int GetProjectedPrecision() const;
     
	//! Check if ProjectedPrecision is set
	plmxml_api::logical HasProjectedPrecision() const;
     
	//! Unset ProjectedPrecision
	plmxml_api::Result UnsetProjectedPrecision();

	//! Set MaxBonusPrecision
	plmxml_api::Result SetMaxBonusPrecision( int arg );
     
	//! Get MaxBonusPrecision
	int GetMaxBonusPrecision() const;
     
	//! Check if MaxBonusPrecision is set
	plmxml_api::logical HasMaxBonusPrecision() const;
     
	//! Unset MaxBonusPrecision
	plmxml_api::Result UnsetMaxBonusPrecision();

	//! Set TrailingZero
	plmxml_api::Result SetTrailingZero( plmxml_api::logical arg );

	//! Get TrailingZero
	plmxml_api::logical GetTrailingZero() const;

	//! Check if TrailingZero is set
	plmxml_api::logical HasTrailingZero() const;

	//! Unset TrailingZero
	plmxml_api::Result UnsetTrailingZero();

	//! Set FcfTextUnderline
	plmxml_api::Result SetFcfTextUnderline( const eAnn3DFCFTextUnderlineEnum& arg );

	//! Get FcfTextUnderline
	eAnn3DFCFTextUnderlineEnum GetFcfTextUnderline() const;

	//! Set LeadingZero
	plmxml_api::Result SetLeadingZero( plmxml_api::logical arg );

	//! Get LeadingZero
	plmxml_api::logical GetLeadingZero() const;

	//! Check if LeadingZero is set
	plmxml_api::logical HasLeadingZero() const;

	//! Unset LeadingZero
	plmxml_api::Result UnsetLeadingZero();

	//! Set DatumOnLeader
	plmxml_api::Result SetDatumOnLeader( const eAnn3DDatumOnLeaderEnum& arg );

	//! Get DatumOnLeader
	eAnn3DDatumOnLeaderEnum GetDatumOnLeader() const;

	//! Set AngleFormat
	plmxml_api::Result SetAngleFormat( const eAnn3DAngleFormat& arg );

	//! Get AngleFormat
	eAnn3DAngleFormat GetAngleFormat() const;
 
// <PLMXML_UserCode type="functionHeaderFeatureControlFrameDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassFeatureControlFrameDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DFCFIndicator class
/*!
\verbatim

      Attributes:

      type:             The type of indicator.
      symbol:           The symbol for the controlled geometric characteristic.

      Sub-elements:

      DatumGroup        The DatumGroup.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DFCFIndicator : public IdObject
{
public:
     
    //! Default constructor
    Ann3DFCFIndicator( );
     
    //! Constructs a Ann3DFCFIndicator with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DFCFIndicator( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DFCFIndicator();

private:

	//! Assignment operator
	Ann3DFCFIndicator& operator=( const Ann3DFCFIndicator& iSrc );

	//! Copy constructor
	Ann3DFCFIndicator( const Ann3DFCFIndicator& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DFCFIndicatorEnum& arg );

	//! Get Type
	eAnn3DFCFIndicatorEnum GetType() const;

	//! Set Symbol
	plmxml_api::Result SetSymbol( const eAnn3DFCFIndicatorSymbolEnum& arg );

	//! Get Symbol
	eAnn3DFCFIndicatorSymbolEnum GetSymbol() const;

	//! Add DatumGroup child element to this Ann3DFCFIndicator. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFCFDatumGroup *AddDatumGroup();
     
	//! Set DatumGroup child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDatumGroup( Ann3DFCFDatumGroup *arg );
     
	//! Get DatumGroup child element of this Ann3DFCFIndicator.
	Ann3DFCFDatumGroup *GetDatumGroup() const;
     
	//! Detach and delete DatumGroup child element tree from this Ann3DFCFIndicator.
	void DeleteDatumGroup();
 
// <PLMXML_UserCode type="functionHeaderAnn3DFCFIndicator" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DFCFIndicator;


////////////////////////////////////////////////////////////////////////////////////
//! DatumFeatureSymbol class
/*!
\verbatim

      DatumFeatureSymbol Annotation

      Attributes:

      standard:         As for Dimensions.
      label:            e.g. "A"
      datumTargetRefs:  Datum Targets associated with this DFS.
      individuallyApplied:
      allAround:        Whether the All Around symbol is added.

      Sub-elements:

      DatumFeatureSymbolText: Text elements other than the label.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API DatumFeatureSymbol : public Annotation3D
{
public:
     
    //! Default constructor
    DatumFeatureSymbol( );
     
    //! Constructs a DatumFeatureSymbol with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DatumFeatureSymbol( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DatumFeatureSymbol();

private:

	//! Assignment operator
	DatumFeatureSymbol& operator=( const DatumFeatureSymbol& iSrc );

	//! Copy constructor
	DatumFeatureSymbol( const DatumFeatureSymbol& original );
     
public:

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Get number of references in DatumTarget array
	int NumberOfDatumTargetRefs() const;
     
	//! Add reference to 'arg' to DatumTarget array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddDatumTargetRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to DatumTarget array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddDatumTargetId( const plmxml_api::String &u );
     
	//! Set i'th reference in DatumTarget array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetDatumTargetRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in DatumTarget array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetDatumTargetId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in DatumTarget array and return an object it points to.
	plmxml60::IdObject *ResolveDatumTargetRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in DatumTarget array and return objects they point to.
	void ResolveDatumTargetRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in DatumTarget array as plmxml_api::String
	plmxml_api::String GetDatumTargetId( int i ) const;
     
	//! Get all references in DatumTarget array as an array of plmxml_api::String
	void GetDatumTargetIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the DatumTarget array.
	void RemoveDatumTargetRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the DatumTarget array.
	void RemoveDatumTargetRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the DatumTarget array.
	void RemoveDatumTargetRef( plmxml60::IdObject *arg );
     
	//! Remove all references DatumTarget array.
	void RemoveDatumTargetRefs();
	
	//! Check if DatumTarget is set
	plmxml_api::logical HasDatumTargetRefs( ) const;

	//! Get Label of this DatumFeatureSymbol
	plmxml_api::String GetLabel() const;

	//! Set Label of this DatumFeatureSymbol
	plmxml_api::Result SetLabel( const plmxml_api::String &s );
	
	//! Check if Label is set
	plmxml_api::logical HasLabel( ) const;
	
	//! Unset Label
	plmxml_api::Result UnsetLabel( );

	//! Set IndividuallyApplied
	plmxml_api::Result SetIndividuallyApplied( plmxml_api::logical arg );

	//! Get IndividuallyApplied
	plmxml_api::logical GetIndividuallyApplied() const;

	//! Check if IndividuallyApplied is set
	plmxml_api::logical HasIndividuallyApplied() const;

	//! Unset IndividuallyApplied
	plmxml_api::Result UnsetIndividuallyApplied();

	//! Add DatumFeatureSymbolText child element to this DatumFeatureSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddDatumFeatureSymbolText();
     
	//! Add 'arg' as DatumFeatureSymbolText child element to this DatumFeatureSymbol.
	plmxml_api::Result AddDatumFeatureSymbolText( Ann3DDimensionText *arg );

	//! Detach and delete all DatumFeatureSymbolText child elements.
	void DeleteDatumFeatureSymbolTexts();
     
	//! Get number of DatumFeatureSymbolText child elements.
	int NumberOfDatumFeatureSymbolTexts() const;
     
	//! Get i'th DatumFeatureSymbolText child element.
	Ann3DDimensionText *GetDatumFeatureSymbolText( int i ) const;
     
	//! Get all DatumFeatureSymbolText child element as an array
	void GetDatumFeatureSymbolTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th DatumFeatureSymbolText child element
	void DeleteDatumFeatureSymbolText( int i );
     
	//! Detach and delete 'arg' if it's one of the DatumFeatureSymbolText child elements
	void DeleteDatumFeatureSymbolText( Ann3DDimensionText *arg );
 
// <PLMXML_UserCode type="functionHeaderDatumFeatureSymbol" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassDatumFeatureSymbol;


////////////////////////////////////////////////////////////////////////////////////
//! DatumFeatureSymbolDisplay class
/*!
\verbatim

      Attributes:

      datumOnLeader:    Whether the datum symbol appears on the Leader rather
                        than the target geometry and, if it does, whether it is
                        solid or filled.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API DatumFeatureSymbolDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    DatumFeatureSymbolDisplay( );
     
    //! Constructs a DatumFeatureSymbolDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DatumFeatureSymbolDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DatumFeatureSymbolDisplay();

private:

	//! Assignment operator
	DatumFeatureSymbolDisplay& operator=( const DatumFeatureSymbolDisplay& iSrc );

	//! Copy constructor
	DatumFeatureSymbolDisplay( const DatumFeatureSymbolDisplay& original );
     
public:

	//! Set DatumOnLeader
	plmxml_api::Result SetDatumOnLeader( const eAnn3DDatumOnLeaderEnum& arg );

	//! Get DatumOnLeader
	eAnn3DDatumOnLeaderEnum GetDatumOnLeader() const;
 
// <PLMXML_UserCode type="functionHeaderDatumFeatureSymbolDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassDatumFeatureSymbolDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! DatumTarget class
/*!
\verbatim

      DatumTarget Annotation

      Attributes:

      standard:        as for Dimensions
      label:           label of parent Datum, e.g. "A". Note the Datum Target can exist
                        without a DFS.
      index:           index of the Datum Target in its DFS, if it exists
      type:            point, line, circular, rectangular, cylindrical or arbitrary
      planar:          whether planar or not
      diameter:        diameter, for circular targets
      innerDiameter:   inner diameter, for circular targets
      length:          if rectangular 
      width:           if rectangular
      point1:          first point
      point2:          second point - only for cylindrical and line targets
      movable:         true if the DatumTarget is movable (shown as a 'bird-beak' symbol)
      movableTargetStubDirection: the left/right direction of the bird-beak.
                       movableTargetStubDirection should not be used with
                       movableModifierAngle.
      movableTargetStubLength: the length of the first segment of the leader (in metres)
      textStubDirection: if the text of the DatumTarget is outside the DatumTargetSymbol,
                       then this specifies whether the text is to the right or left of
                       the symbol.
      textStubLength:  if the text of the DatumTarget is outside the DatumTargetSymbol,
                       then this specifies the length (in metres) of the stub line 
                       joining the text to the symbol.
      areaShape:       The shape of the target area according to the area
                       specification segment of the DatumTarget symbol.
      shapeTextOutsideSymbol: Whether the text that describes the shape of the
                       target area lies outside the DatumTarget symbol. The text
                       usually lies inside the area specification segment of the
                       DatumTarget symbol.
      size:            The size of the DatumTarget if the type is arbitrary.
      movableModifierAngle: The direction in which a movable DatumTarget may
                       move relative to the line across the DatumTarget in
                       radians. The bird-beak symbol points in this direction.
                       movableModifierAngle should not be used with
                       movableTargetStubDirection.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API DatumTarget : public Annotation3D
{
public:
     
    //! Default constructor
    DatumTarget( );
     
    //! Constructs a DatumTarget with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DatumTarget( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DatumTarget();

private:

	//! Assignment operator
	DatumTarget& operator=( const DatumTarget& iSrc );

	//! Copy constructor
	DatumTarget( const DatumTarget& original );
     
public:

	//! Set MovableTargetStubLength
	plmxml_api::Result SetMovableTargetStubLength( double arg );

     //! Get MovableTargetStubLength
	double GetMovableTargetStubLength() const;

	//! Check if MovableTargetStubLength is set
	plmxml_api::logical HasMovableTargetStubLength() const;

	//! Unset MovableTargetStubLength
	plmxml_api::Result UnsetMovableTargetStubLength();

	//! Set AreaShape
	plmxml_api::Result SetAreaShape( const eAnn3DDatumTargetAreaShapeEnum& arg );

	//! Get AreaShape
	eAnn3DDatumTargetAreaShapeEnum GetAreaShape() const;

	//! Get Label of this DatumTarget
	plmxml_api::String GetLabel() const;

	//! Set Label of this DatumTarget
	plmxml_api::Result SetLabel( const plmxml_api::String &s );
	
	//! Check if Label is set
	plmxml_api::logical HasLabel( ) const;
	
	//! Unset Label
	plmxml_api::Result UnsetLabel( );

	//! Set Point1 using plmxml_api::Vector components
	plmxml_api::Result SetPoint1( const plmxml_api::Vector& arg );

	//! Get Point1 as plmxml_api::Vector
	plmxml_api::Result GetPoint1( plmxml_api::Vector& arg ) const;

	//! Check if Point1 is set
	plmxml_api::logical HasPoint1() const;

	//! Unset Point1
	plmxml_api::Result UnsetPoint1();

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Set InnerDiameter
	plmxml_api::Result SetInnerDiameter( double arg );

     //! Get InnerDiameter
	double GetInnerDiameter() const;

	//! Check if InnerDiameter is set
	plmxml_api::logical HasInnerDiameter() const;

	//! Unset InnerDiameter
	plmxml_api::Result UnsetInnerDiameter();

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set ShapeTextOutsideSymbol
	plmxml_api::Result SetShapeTextOutsideSymbol( plmxml_api::logical arg );

	//! Get ShapeTextOutsideSymbol
	plmxml_api::logical GetShapeTextOutsideSymbol() const;

	//! Check if ShapeTextOutsideSymbol is set
	plmxml_api::logical HasShapeTextOutsideSymbol() const;

	//! Unset ShapeTextOutsideSymbol
	plmxml_api::Result UnsetShapeTextOutsideSymbol();

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DDatumTarget& arg );

	//! Get Type
	eAnn3DDatumTarget GetType() const;

	//! Set MovableModifierAngle
	plmxml_api::Result SetMovableModifierAngle( double arg );

     //! Get MovableModifierAngle
	double GetMovableModifierAngle() const;

	//! Check if MovableModifierAngle is set
	plmxml_api::logical HasMovableModifierAngle() const;

	//! Unset MovableModifierAngle
	plmxml_api::Result UnsetMovableModifierAngle();

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Set Index
	plmxml_api::Result SetIndex( int arg );
     
	//! Get Index
	int GetIndex() const;
     
	//! Check if Index is set
	plmxml_api::logical HasIndex() const;
     
	//! Unset Index
	plmxml_api::Result UnsetIndex();

	//! Set TextStubDirection
	plmxml_api::Result SetTextStubDirection( const eAnn3DDimensionStubDirection& arg );

	//! Get TextStubDirection
	eAnn3DDimensionStubDirection GetTextStubDirection() const;

	//! Set TextStubLength
	plmxml_api::Result SetTextStubLength( double arg );

     //! Get TextStubLength
	double GetTextStubLength() const;

	//! Check if TextStubLength is set
	plmxml_api::logical HasTextStubLength() const;

	//! Unset TextStubLength
	plmxml_api::Result UnsetTextStubLength();

	//! Get Size of this DatumTarget
	plmxml_api::String GetSize() const;

	//! Set Size of this DatumTarget
	plmxml_api::Result SetSize( const plmxml_api::String &s );
	
	//! Check if Size is set
	plmxml_api::logical HasSize( ) const;
	
	//! Unset Size
	plmxml_api::Result UnsetSize( );

	//! Set Movable
	plmxml_api::Result SetMovable( plmxml_api::logical arg );

	//! Get Movable
	plmxml_api::logical GetMovable() const;

	//! Check if Movable is set
	plmxml_api::logical HasMovable() const;

	//! Unset Movable
	plmxml_api::Result UnsetMovable();

	//! Set Point2 using plmxml_api::Vector components
	plmxml_api::Result SetPoint2( const plmxml_api::Vector& arg );

	//! Get Point2 as plmxml_api::Vector
	plmxml_api::Result GetPoint2( plmxml_api::Vector& arg ) const;

	//! Check if Point2 is set
	plmxml_api::logical HasPoint2() const;

	//! Unset Point2
	plmxml_api::Result UnsetPoint2();

	//! Set MovableTargetStubDirection
	plmxml_api::Result SetMovableTargetStubDirection( const eAnn3DDimensionStubDirection& arg );

	//! Get MovableTargetStubDirection
	eAnn3DDimensionStubDirection GetMovableTargetStubDirection() const;

	//! Set Width
	plmxml_api::Result SetWidth( double arg );

     //! Get Width
	double GetWidth() const;

	//! Check if Width is set
	plmxml_api::logical HasWidth() const;

	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Set Planar
	plmxml_api::Result SetPlanar( plmxml_api::logical arg );

	//! Get Planar
	plmxml_api::logical GetPlanar() const;

	//! Check if Planar is set
	plmxml_api::logical HasPlanar() const;

	//! Unset Planar
	plmxml_api::Result UnsetPlanar();
 
// <PLMXML_UserCode type="functionHeaderDatumTarget" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassDatumTarget;


////////////////////////////////////////////////////////////////////////////////////
//! DatumTargetDisplay class
/*!
\verbatim

      DatumTarget Display

      Attributes:

      precision:        The number of decimal places.
      terminator:       The symbol for the DatumTarget terminator.
      radius:           The radius of the symbol.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API DatumTargetDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    DatumTargetDisplay( );
     
    //! Constructs a DatumTargetDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DatumTargetDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DatumTargetDisplay();

private:

	//! Assignment operator
	DatumTargetDisplay& operator=( const DatumTargetDisplay& iSrc );

	//! Copy constructor
	DatumTargetDisplay( const DatumTargetDisplay& original );
     
public:

	//! Set Radius
	plmxml_api::Result SetRadius( double arg );

     //! Get Radius
	double GetRadius() const;

	//! Check if Radius is set
	plmxml_api::logical HasRadius() const;

	//! Unset Radius
	plmxml_api::Result UnsetRadius();

	//! Set Terminator
	plmxml_api::Result SetTerminator( const eAnn3DDatumTerminatorEnum& arg );

	//! Get Terminator
	eAnn3DDatumTerminatorEnum GetTerminator() const;

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();
 
// <PLMXML_UserCode type="functionHeaderDatumTargetDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassDatumTargetDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! SpotWeld class
/*!
\verbatim

      SpotWeld Annotation
      
      Attributes:
      
      diameter:            diameter
      thickness:           thickness of the weld bead
      thicknesses:         number of thicknesses of material being welded
      type:                type of weld, resistance or projection
      position:            location of the spot weld
      approachDirection:   direction weld gun approaches weld
      clampingDirection:   direction in which material is clamped
      normalDirection:     normal vector at point of weld
      jointId:             user specified id for joint weld participates in
      groupId:             user specified id for group weld is in
      delta:               flag indicating weld is "critical" (more important)

      Elements:
      
      ProcessText         process text
      CoordinatedEntity   a text string specifying a related entity in some undefined way
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API SpotWeld : public Annotation3D
{
public:
     
    //! Default constructor
    SpotWeld( );
     
    //! Constructs a SpotWeld with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpotWeld( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpotWeld();

private:

	//! Assignment operator
	SpotWeld& operator=( const SpotWeld& iSrc );

	//! Copy constructor
	SpotWeld( const SpotWeld& original );
     
public:

	//! Get GroupId of this SpotWeld
	plmxml_api::String GetGroupId() const;

	//! Set GroupId of this SpotWeld
	plmxml_api::Result SetGroupId( const plmxml_api::String &s );
	
	//! Check if GroupId is set
	plmxml_api::logical HasGroupId( ) const;
	
	//! Unset GroupId
	plmxml_api::Result UnsetGroupId( );

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DSpotWeld& arg );

	//! Get Type
	eAnn3DSpotWeld GetType() const;

	//! Set Delta
	plmxml_api::Result SetDelta( plmxml_api::logical arg );

	//! Get Delta
	plmxml_api::logical GetDelta() const;

	//! Check if Delta is set
	plmxml_api::logical HasDelta() const;

	//! Unset Delta
	plmxml_api::Result UnsetDelta();

	//! Set Thickness
	plmxml_api::Result SetThickness( double arg );

     //! Get Thickness
	double GetThickness() const;

	//! Check if Thickness is set
	plmxml_api::logical HasThickness() const;

	//! Unset Thickness
	plmxml_api::Result UnsetThickness();

	//! Set ClampingDirection using plmxml_api::Vector components
	plmxml_api::Result SetClampingDirection( const plmxml_api::Vector& arg );

	//! Get ClampingDirection as plmxml_api::Vector
	plmxml_api::Result GetClampingDirection( plmxml_api::Vector& arg ) const;

	//! Check if ClampingDirection is set
	plmxml_api::logical HasClampingDirection() const;

	//! Unset ClampingDirection
	plmxml_api::Result UnsetClampingDirection();

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();

	//! Set Thicknesses
	plmxml_api::Result SetThicknesses( int arg );
     
	//! Get Thicknesses
	int GetThicknesses() const;
     
	//! Check if Thicknesses is set
	plmxml_api::logical HasThicknesses() const;
     
	//! Unset Thicknesses
	plmxml_api::Result UnsetThicknesses();

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Set ApproachDirection using plmxml_api::Vector components
	plmxml_api::Result SetApproachDirection( const plmxml_api::Vector& arg );

	//! Get ApproachDirection as plmxml_api::Vector
	plmxml_api::Result GetApproachDirection( plmxml_api::Vector& arg ) const;

	//! Check if ApproachDirection is set
	plmxml_api::logical HasApproachDirection() const;

	//! Unset ApproachDirection
	plmxml_api::Result UnsetApproachDirection();

	//! Set NormalDirection using plmxml_api::Vector components
	plmxml_api::Result SetNormalDirection( const plmxml_api::Vector& arg );

	//! Get NormalDirection as plmxml_api::Vector
	plmxml_api::Result GetNormalDirection( plmxml_api::Vector& arg ) const;

	//! Check if NormalDirection is set
	plmxml_api::logical HasNormalDirection() const;

	//! Unset NormalDirection
	plmxml_api::Result UnsetNormalDirection();

	//! Get JointId of this SpotWeld
	plmxml_api::String GetJointId() const;

	//! Set JointId of this SpotWeld
	plmxml_api::Result SetJointId( const plmxml_api::String &s );
	
	//! Check if JointId is set
	plmxml_api::logical HasJointId( ) const;
	
	//! Unset JointId
	plmxml_api::Result UnsetJointId( );

	//! Add CoordinatedEntity child element to this SpotWeld. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCoordinatedEntity();
     
	//! Add 'arg' as CoordinatedEntity child element to this SpotWeld.
	plmxml_api::Result AddCoordinatedEntity( Ann3DText *arg );

	//! Detach and delete all CoordinatedEntity child elements.
	void DeleteCoordinatedEntities();
     
	//! Get number of CoordinatedEntity child elements.
	int NumberOfCoordinatedEntities() const;
     
	//! Get i'th CoordinatedEntity child element.
	Ann3DText *GetCoordinatedEntity( int i ) const;
     
	//! Get all CoordinatedEntity child element as an array
	void GetCoordinatedEntities( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th CoordinatedEntity child element
	void DeleteCoordinatedEntity( int i );
     
	//! Detach and delete 'arg' if it's one of the CoordinatedEntity child elements
	void DeleteCoordinatedEntity( Ann3DText *arg );

	//! Add ProcessText child element to this SpotWeld. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddProcessText();
     
	//! Set ProcessText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetProcessText( Ann3DText *arg );
     
	//! Get ProcessText child element of this SpotWeld.
	Ann3DText *GetProcessText() const;
     
	//! Detach and delete ProcessText child element tree from this SpotWeld.
	void DeleteProcessText();
 
// <PLMXML_UserCode type="functionHeaderSpotWeld" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassSpotWeld;


////////////////////////////////////////////////////////////////////////////////////
//! SpotWeldDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API SpotWeldDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    SpotWeldDisplay( );
     
    //! Constructs a SpotWeldDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpotWeldDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpotWeldDisplay();

private:

	//! Assignment operator
	SpotWeldDisplay& operator=( const SpotWeldDisplay& iSrc );

	//! Copy constructor
	SpotWeldDisplay( const SpotWeldDisplay& original );
     
public:

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set DisplayType
	plmxml_api::Result SetDisplayType( const eAnn3DSpotWeldDisplay& arg );

	//! Get DisplayType
	eAnn3DSpotWeldDisplay GetDisplayType() const;
 
// <PLMXML_UserCode type="functionHeaderSpotWeldDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassSpotWeldDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! LineWeld class
/*!
\verbatim

      LineWeld Annotation

      Attributes:

      standard:                     ISO 2556 or ANSI/AWS A2.4-98
      arrowSideSymbol:              symbol on arrow side of weld
      otherSideSymbol:              symbol shown on other side of the weld
      arrowSideMainSize:            main size of the weld on the arrow side
      otherSideMainSize:            main size of the weld on the other side
      arrowSideLongitudinalSize:    longitudinal size of the weld on the arrow side
      otherSideLongitudinalSize:    longitudinal size of the weld on the other side
      arrowSideStaggeredSize:       staggered size of the weld on the arrow side
      otherSideStaggeredSize:       staggered size of the weld on the other side
      arrowSideSupplementalSymbol:  supplemental symbol on arrow side
      otherSideSupplementalSymbol:  supplemental symbol on other side
      allAround:                    flag indicating an all around weld
      delta:                        flag indicating weld is "critical" (more important)
      fieldWeld:                    indicates weld is applied in the field
      referenceSign:                reference sign is to be included in symbol
      arrowSideFinishSymbol:        Indicates the type of process used to apply a finish 
                                    to the Arrow side of a Weld
      otherSideFinishSymbol:        ditto, Other side
      jisArrowSidePartialPenetrationGrooveWeld: Flag indicating the Arrow side of a weld 
                                    represents a partial penetration groove weld
      jisOtherSidePartialPenetrationGrooveWeld: ditto, Other side
      jisStaggeredFilletWeld:       Flag indicating that the JIS fillet weld is to be staggered
      arrowSideGrooveGap:           Gap applied to the Arrow side of a groove weld
      otherSideGrooveGap:           ditto, Other side
      arrowSideGrooveAngle:         Angle applied to the Arrow side of a groove weld
      otherSideGrooveAngle:         ditto, Other side
      staggeredWeld:                Whether the weld is staggered
      arrowSideCompoundWeld:        Whether the arrow side of the weld is a compound weld.
      otherSideCompoundWeld:        Whether the other side of the weld is a compound weld.
      arrowSideCompoundMainSize:    The main size of the compound weld on the arrow side.
      otherSideCompoundMainSize:    The main size of the compound weld on the other side.
      contour:                      Contour symbol.
      symmetric:                    Whether the weld is symmetrical by design.
      solder:                       Flag indicating a soldered joint.
      glue:                         Flag indicating a glued joint.
      surfaceFinishInstanceRef:     References the Ann3DVirtualInstance of any
                                    incorporated SurfaceFinish.
      arrowSideSupplementalSymbol2: Second supplemental symbol on arrow side.
      otherSideSupplementalSymbol2: Second supplemental symbol on other side.
      arrowSideCompoundLongitudinalSize: Longitudinal size of the compound weld on the arrow side.
      otherSideCompoundLongitudinalSize: Longitudinal size of the compound weld on the other side.
      arrowSideCompoundStaggeredSize: Staggered size of the compound weld on the arrow side.
      otherSideCompoundStaggeredSize: Staggered size of the compound weld on the other side.

      Elements:

      ProcessText:                  process text
      CoordinatedEntity:            text string specifying a related entity in an undefined way
      LeaderText:                   Text elements on the Leader of an ESKD LineWeld.
                                    Only above and below are allowed.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API LineWeld : public Annotation3D
{
public:
     
    //! Default constructor
    LineWeld( );
     
    //! Constructs a LineWeld with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LineWeld( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LineWeld();

private:

	//! Assignment operator
	LineWeld& operator=( const LineWeld& iSrc );

	//! Copy constructor
	LineWeld( const LineWeld& original );
     
public:

	//! Get OtherSideStaggeredSize of this LineWeld
	plmxml_api::String GetOtherSideStaggeredSize() const;

	//! Set OtherSideStaggeredSize of this LineWeld
	plmxml_api::Result SetOtherSideStaggeredSize( const plmxml_api::String &s );
	
	//! Check if OtherSideStaggeredSize is set
	plmxml_api::logical HasOtherSideStaggeredSize( ) const;
	
	//! Unset OtherSideStaggeredSize
	plmxml_api::Result UnsetOtherSideStaggeredSize( );

	//! Get OtherSideGrooveAngle of this LineWeld
	plmxml_api::String GetOtherSideGrooveAngle() const;

	//! Set OtherSideGrooveAngle of this LineWeld
	plmxml_api::Result SetOtherSideGrooveAngle( const plmxml_api::String &s );
	
	//! Check if OtherSideGrooveAngle is set
	plmxml_api::logical HasOtherSideGrooveAngle( ) const;
	
	//! Unset OtherSideGrooveAngle
	plmxml_api::Result UnsetOtherSideGrooveAngle( );

	//! Get OtherSideCompoundLongitudinalSize of this LineWeld
	plmxml_api::String GetOtherSideCompoundLongitudinalSize() const;

	//! Set OtherSideCompoundLongitudinalSize of this LineWeld
	plmxml_api::Result SetOtherSideCompoundLongitudinalSize( const plmxml_api::String &s );
	
	//! Check if OtherSideCompoundLongitudinalSize is set
	plmxml_api::logical HasOtherSideCompoundLongitudinalSize( ) const;
	
	//! Unset OtherSideCompoundLongitudinalSize
	plmxml_api::Result UnsetOtherSideCompoundLongitudinalSize( );

	//! Set OtherSideCompoundWeld
	plmxml_api::Result SetOtherSideCompoundWeld( plmxml_api::logical arg );

	//! Get OtherSideCompoundWeld
	plmxml_api::logical GetOtherSideCompoundWeld() const;

	//! Check if OtherSideCompoundWeld is set
	plmxml_api::logical HasOtherSideCompoundWeld() const;

	//! Unset OtherSideCompoundWeld
	plmxml_api::Result UnsetOtherSideCompoundWeld();

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DLineWeldStandardType& arg );

	//! Get Standard
	eAnn3DLineWeldStandardType GetStandard() const;

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set OtherSideSupplementalSymbol2
	plmxml_api::Result SetOtherSideSupplementalSymbol2( const eAnn3DLineWeldSupplementalSymbol& arg );

	//! Get OtherSideSupplementalSymbol2
	eAnn3DLineWeldSupplementalSymbol GetOtherSideSupplementalSymbol2() const;

	//! Get ArrowSideMainSize of this LineWeld
	plmxml_api::String GetArrowSideMainSize() const;

	//! Set ArrowSideMainSize of this LineWeld
	plmxml_api::Result SetArrowSideMainSize( const plmxml_api::String &s );
	
	//! Check if ArrowSideMainSize is set
	plmxml_api::logical HasArrowSideMainSize( ) const;
	
	//! Unset ArrowSideMainSize
	plmxml_api::Result UnsetArrowSideMainSize( );

	//! Set ArrowSideSupplementalSymbol
	plmxml_api::Result SetArrowSideSupplementalSymbol( const eAnn3DLineWeldSupplementalSymbol& arg );

	//! Get ArrowSideSupplementalSymbol
	eAnn3DLineWeldSupplementalSymbol GetArrowSideSupplementalSymbol() const;

	//! Get OtherSideMainSize of this LineWeld
	plmxml_api::String GetOtherSideMainSize() const;

	//! Set OtherSideMainSize of this LineWeld
	plmxml_api::Result SetOtherSideMainSize( const plmxml_api::String &s );
	
	//! Check if OtherSideMainSize is set
	plmxml_api::logical HasOtherSideMainSize( ) const;
	
	//! Unset OtherSideMainSize
	plmxml_api::Result UnsetOtherSideMainSize( );

	//! Set Glue
	plmxml_api::Result SetGlue( plmxml_api::logical arg );

	//! Get Glue
	plmxml_api::logical GetGlue() const;

	//! Check if Glue is set
	plmxml_api::logical HasGlue() const;

	//! Unset Glue
	plmxml_api::Result UnsetGlue();

	//! Set JisOtherSidePartialPenetrationGrooveWeld
	plmxml_api::Result SetJisOtherSidePartialPenetrationGrooveWeld( plmxml_api::logical arg );

	//! Get JisOtherSidePartialPenetrationGrooveWeld
	plmxml_api::logical GetJisOtherSidePartialPenetrationGrooveWeld() const;

	//! Check if JisOtherSidePartialPenetrationGrooveWeld is set
	plmxml_api::logical HasJisOtherSidePartialPenetrationGrooveWeld() const;

	//! Unset JisOtherSidePartialPenetrationGrooveWeld
	plmxml_api::Result UnsetJisOtherSidePartialPenetrationGrooveWeld();

	//! Set StaggeredWeld
	plmxml_api::Result SetStaggeredWeld( plmxml_api::logical arg );

	//! Get StaggeredWeld
	plmxml_api::logical GetStaggeredWeld() const;

	//! Check if StaggeredWeld is set
	plmxml_api::logical HasStaggeredWeld() const;

	//! Unset StaggeredWeld
	plmxml_api::Result UnsetStaggeredWeld();

	//! Get ArrowSideGrooveAngle of this LineWeld
	plmxml_api::String GetArrowSideGrooveAngle() const;

	//! Set ArrowSideGrooveAngle of this LineWeld
	plmxml_api::Result SetArrowSideGrooveAngle( const plmxml_api::String &s );
	
	//! Check if ArrowSideGrooveAngle is set
	plmxml_api::logical HasArrowSideGrooveAngle( ) const;
	
	//! Unset ArrowSideGrooveAngle
	plmxml_api::Result UnsetArrowSideGrooveAngle( );

	//! Set Contour
	plmxml_api::Result SetContour( const eAnn3DLineWeldContourEnum& arg );

	//! Get Contour
	eAnn3DLineWeldContourEnum GetContour() const;

	//! Set OtherSideFinishSymbol
	plmxml_api::Result SetOtherSideFinishSymbol( const eAnn3DLineWeldFinishSymbol& arg );

	//! Get OtherSideFinishSymbol
	eAnn3DLineWeldFinishSymbol GetOtherSideFinishSymbol() const;

	//! Set JisStaggeredFilletWeld
	plmxml_api::Result SetJisStaggeredFilletWeld( plmxml_api::logical arg );

	//! Get JisStaggeredFilletWeld
	plmxml_api::logical GetJisStaggeredFilletWeld() const;

	//! Check if JisStaggeredFilletWeld is set
	plmxml_api::logical HasJisStaggeredFilletWeld() const;

	//! Unset JisStaggeredFilletWeld
	plmxml_api::Result UnsetJisStaggeredFilletWeld();

	//! Get ArrowSideCompoundMainSize of this LineWeld
	plmxml_api::String GetArrowSideCompoundMainSize() const;

	//! Set ArrowSideCompoundMainSize of this LineWeld
	plmxml_api::Result SetArrowSideCompoundMainSize( const plmxml_api::String &s );
	
	//! Check if ArrowSideCompoundMainSize is set
	plmxml_api::logical HasArrowSideCompoundMainSize( ) const;
	
	//! Unset ArrowSideCompoundMainSize
	plmxml_api::Result UnsetArrowSideCompoundMainSize( );

	//! Get ArrowSideStaggeredSize of this LineWeld
	plmxml_api::String GetArrowSideStaggeredSize() const;

	//! Set ArrowSideStaggeredSize of this LineWeld
	plmxml_api::Result SetArrowSideStaggeredSize( const plmxml_api::String &s );
	
	//! Check if ArrowSideStaggeredSize is set
	plmxml_api::logical HasArrowSideStaggeredSize( ) const;
	
	//! Unset ArrowSideStaggeredSize
	plmxml_api::Result UnsetArrowSideStaggeredSize( );

	//! Set Delta
	plmxml_api::Result SetDelta( plmxml_api::logical arg );

	//! Get Delta
	plmxml_api::logical GetDelta() const;

	//! Check if Delta is set
	plmxml_api::logical HasDelta() const;

	//! Unset Delta
	plmxml_api::Result UnsetDelta();

	//! Get ArrowSideCompoundStaggeredSize of this LineWeld
	plmxml_api::String GetArrowSideCompoundStaggeredSize() const;

	//! Set ArrowSideCompoundStaggeredSize of this LineWeld
	plmxml_api::Result SetArrowSideCompoundStaggeredSize( const plmxml_api::String &s );
	
	//! Check if ArrowSideCompoundStaggeredSize is set
	plmxml_api::logical HasArrowSideCompoundStaggeredSize( ) const;
	
	//! Unset ArrowSideCompoundStaggeredSize
	plmxml_api::Result UnsetArrowSideCompoundStaggeredSize( );

	//! Set JisArrowSidePartialPenetrationGrooveWeld
	plmxml_api::Result SetJisArrowSidePartialPenetrationGrooveWeld( plmxml_api::logical arg );

	//! Get JisArrowSidePartialPenetrationGrooveWeld
	plmxml_api::logical GetJisArrowSidePartialPenetrationGrooveWeld() const;

	//! Check if JisArrowSidePartialPenetrationGrooveWeld is set
	plmxml_api::logical HasJisArrowSidePartialPenetrationGrooveWeld() const;

	//! Unset JisArrowSidePartialPenetrationGrooveWeld
	plmxml_api::Result UnsetJisArrowSidePartialPenetrationGrooveWeld();

	//! Get ArrowSideLongitudinalSize of this LineWeld
	plmxml_api::String GetArrowSideLongitudinalSize() const;

	//! Set ArrowSideLongitudinalSize of this LineWeld
	plmxml_api::Result SetArrowSideLongitudinalSize( const plmxml_api::String &s );
	
	//! Check if ArrowSideLongitudinalSize is set
	plmxml_api::logical HasArrowSideLongitudinalSize( ) const;
	
	//! Unset ArrowSideLongitudinalSize
	plmxml_api::Result UnsetArrowSideLongitudinalSize( );

	//! Set ReferenceSign
	plmxml_api::Result SetReferenceSign( plmxml_api::logical arg );

	//! Get ReferenceSign
	plmxml_api::logical GetReferenceSign() const;

	//! Check if ReferenceSign is set
	plmxml_api::logical HasReferenceSign() const;

	//! Unset ReferenceSign
	plmxml_api::Result UnsetReferenceSign();

	//! Set ArrowSideSupplementalSymbol2
	plmxml_api::Result SetArrowSideSupplementalSymbol2( const eAnn3DLineWeldSupplementalSymbol& arg );

	//! Get ArrowSideSupplementalSymbol2
	eAnn3DLineWeldSupplementalSymbol GetArrowSideSupplementalSymbol2() const;

	//! Set OtherSideSupplementalSymbol
	plmxml_api::Result SetOtherSideSupplementalSymbol( const eAnn3DLineWeldSupplementalSymbol& arg );

	//! Get OtherSideSupplementalSymbol
	eAnn3DLineWeldSupplementalSymbol GetOtherSideSupplementalSymbol() const;

	//! Get ArrowSideCompoundLongitudinalSize of this LineWeld
	plmxml_api::String GetArrowSideCompoundLongitudinalSize() const;

	//! Set ArrowSideCompoundLongitudinalSize of this LineWeld
	plmxml_api::Result SetArrowSideCompoundLongitudinalSize( const plmxml_api::String &s );
	
	//! Check if ArrowSideCompoundLongitudinalSize is set
	plmxml_api::logical HasArrowSideCompoundLongitudinalSize( ) const;
	
	//! Unset ArrowSideCompoundLongitudinalSize
	plmxml_api::Result UnsetArrowSideCompoundLongitudinalSize( );

	//! Set ArrowSideCompoundWeld
	plmxml_api::Result SetArrowSideCompoundWeld( plmxml_api::logical arg );

	//! Get ArrowSideCompoundWeld
	plmxml_api::logical GetArrowSideCompoundWeld() const;

	//! Check if ArrowSideCompoundWeld is set
	plmxml_api::logical HasArrowSideCompoundWeld() const;

	//! Unset ArrowSideCompoundWeld
	plmxml_api::Result UnsetArrowSideCompoundWeld();

	//! Set ArrowSideSymbol
	plmxml_api::Result SetArrowSideSymbol( const eAnn3DLineWeldSymbol& arg );

	//! Get ArrowSideSymbol
	eAnn3DLineWeldSymbol GetArrowSideSymbol() const;

	//! Get OtherSideGrooveGap of this LineWeld
	plmxml_api::String GetOtherSideGrooveGap() const;

	//! Set OtherSideGrooveGap of this LineWeld
	plmxml_api::Result SetOtherSideGrooveGap( const plmxml_api::String &s );
	
	//! Check if OtherSideGrooveGap is set
	plmxml_api::logical HasOtherSideGrooveGap( ) const;
	
	//! Unset OtherSideGrooveGap
	plmxml_api::Result UnsetOtherSideGrooveGap( );

	//! Get SurfaceFinishInstance URI as plmxml_api::String
	plmxml_api::String GetSurfaceFinishInstanceURI() const;

	//! Set SurfaceFinishInstance URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSurfaceFinishInstanceURI( const plmxml_api::String& );
	
	//! Get the handle of SurfaceFinishInstance URI. Does not resolve the URI.
	plmxml_api::Result GetSurfaceFinishInstanceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of SurfaceFinishInstance URI. URI string is unchanged.
	plmxml_api::Result SetSurfaceFinishInstanceURI( const plmxml_api::Handle& );
	
	//! Resolve SurfaceFinishInstance URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSurfaceFinishInstanceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset SurfaceFinishInstance URI. Clears URI string and handle.
	plmxml_api::Result DeleteSurfaceFinishInstanceURI();
	
	//! Check if SurfaceFinishInstance URI is set
	plmxml_api::logical HasSurfaceFinishInstanceURI( ) const;
	

	//! Get OtherSideCompoundMainSize of this LineWeld
	plmxml_api::String GetOtherSideCompoundMainSize() const;

	//! Set OtherSideCompoundMainSize of this LineWeld
	plmxml_api::Result SetOtherSideCompoundMainSize( const plmxml_api::String &s );
	
	//! Check if OtherSideCompoundMainSize is set
	plmxml_api::logical HasOtherSideCompoundMainSize( ) const;
	
	//! Unset OtherSideCompoundMainSize
	plmxml_api::Result UnsetOtherSideCompoundMainSize( );

	//! Get OtherSideCompoundStaggeredSize of this LineWeld
	plmxml_api::String GetOtherSideCompoundStaggeredSize() const;

	//! Set OtherSideCompoundStaggeredSize of this LineWeld
	plmxml_api::Result SetOtherSideCompoundStaggeredSize( const plmxml_api::String &s );
	
	//! Check if OtherSideCompoundStaggeredSize is set
	plmxml_api::logical HasOtherSideCompoundStaggeredSize( ) const;
	
	//! Unset OtherSideCompoundStaggeredSize
	plmxml_api::Result UnsetOtherSideCompoundStaggeredSize( );

	//! Get OtherSideLongitudinalSize of this LineWeld
	plmxml_api::String GetOtherSideLongitudinalSize() const;

	//! Set OtherSideLongitudinalSize of this LineWeld
	plmxml_api::Result SetOtherSideLongitudinalSize( const plmxml_api::String &s );
	
	//! Check if OtherSideLongitudinalSize is set
	plmxml_api::logical HasOtherSideLongitudinalSize( ) const;
	
	//! Unset OtherSideLongitudinalSize
	plmxml_api::Result UnsetOtherSideLongitudinalSize( );

	//! Set ArrowSideFinishSymbol
	plmxml_api::Result SetArrowSideFinishSymbol( const eAnn3DLineWeldFinishSymbol& arg );

	//! Get ArrowSideFinishSymbol
	eAnn3DLineWeldFinishSymbol GetArrowSideFinishSymbol() const;

	//! Set OtherSideSymbol
	plmxml_api::Result SetOtherSideSymbol( const eAnn3DLineWeldSymbol& arg );

	//! Get OtherSideSymbol
	eAnn3DLineWeldSymbol GetOtherSideSymbol() const;

	//! Set Solder
	plmxml_api::Result SetSolder( plmxml_api::logical arg );

	//! Get Solder
	plmxml_api::logical GetSolder() const;

	//! Check if Solder is set
	plmxml_api::logical HasSolder() const;

	//! Unset Solder
	plmxml_api::Result UnsetSolder();

	//! Get ArrowSideGrooveGap of this LineWeld
	plmxml_api::String GetArrowSideGrooveGap() const;

	//! Set ArrowSideGrooveGap of this LineWeld
	plmxml_api::Result SetArrowSideGrooveGap( const plmxml_api::String &s );
	
	//! Check if ArrowSideGrooveGap is set
	plmxml_api::logical HasArrowSideGrooveGap( ) const;
	
	//! Unset ArrowSideGrooveGap
	plmxml_api::Result UnsetArrowSideGrooveGap( );

	//! Set Symmetric
	plmxml_api::Result SetSymmetric( plmxml_api::logical arg );

	//! Get Symmetric
	plmxml_api::logical GetSymmetric() const;

	//! Check if Symmetric is set
	plmxml_api::logical HasSymmetric() const;

	//! Unset Symmetric
	plmxml_api::Result UnsetSymmetric();

	//! Set FieldWeld
	plmxml_api::Result SetFieldWeld( plmxml_api::logical arg );

	//! Get FieldWeld
	plmxml_api::logical GetFieldWeld() const;

	//! Check if FieldWeld is set
	plmxml_api::logical HasFieldWeld() const;

	//! Unset FieldWeld
	plmxml_api::Result UnsetFieldWeld();

	//! Add ProcessText child element to this LineWeld. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddProcessText();
     
	//! Set ProcessText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetProcessText( Ann3DText *arg );
     
	//! Get ProcessText child element of this LineWeld.
	Ann3DText *GetProcessText() const;
     
	//! Detach and delete ProcessText child element tree from this LineWeld.
	void DeleteProcessText();

	//! Add CoordinatedEntity child element to this LineWeld. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCoordinatedEntity();
     
	//! Add 'arg' as CoordinatedEntity child element to this LineWeld.
	plmxml_api::Result AddCoordinatedEntity( Ann3DText *arg );

	//! Detach and delete all CoordinatedEntity child elements.
	void DeleteCoordinatedEntities();
     
	//! Get number of CoordinatedEntity child elements.
	int NumberOfCoordinatedEntities() const;
     
	//! Get i'th CoordinatedEntity child element.
	Ann3DText *GetCoordinatedEntity( int i ) const;
     
	//! Get all CoordinatedEntity child element as an array
	void GetCoordinatedEntities( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th CoordinatedEntity child element
	void DeleteCoordinatedEntity( int i );
     
	//! Detach and delete 'arg' if it's one of the CoordinatedEntity child elements
	void DeleteCoordinatedEntity( Ann3DText *arg );

	//! Add LeaderText child element to this LineWeld. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddLeaderText();
     
	//! Add 'arg' as LeaderText child element to this LineWeld.
	plmxml_api::Result AddLeaderText( Ann3DDimensionText *arg );

	//! Detach and delete all LeaderText child elements.
	void DeleteLeaderTexts();
     
	//! Get number of LeaderText child elements.
	int NumberOfLeaderTexts() const;
     
	//! Get i'th LeaderText child element.
	Ann3DDimensionText *GetLeaderText( int i ) const;
     
	//! Get all LeaderText child element as an array
	void GetLeaderTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th LeaderText child element
	void DeleteLeaderText( int i );
     
	//! Detach and delete 'arg' if it's one of the LeaderText child elements
	void DeleteLeaderText( Ann3DDimensionText *arg );
 
// <PLMXML_UserCode type="functionHeaderLineWeld" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassLineWeld;


////////////////////////////////////////////////////////////////////////////////////
//! LineWeldDisplay class
/*!
\verbatim

      LineWeld Display

      Attributes:

      precision:        The number of decimal places to display.
      referenceSignType: The type of any reference sign.
      fieldWeldType:    The type of any field weld indicator.
      arrowSideAboveLine: Whether to show the arrow side information above the
                        reference line. By default, the arrow side information
                        is shown below the reference line. In order to comply
                        with standards, if arrowSideAboveLine is true, a dashed
                        identification line should also be shown below the solid
                        reference line to indicate the other side.
      identificationLine: Whether to show a dashed identification line to
                        indicate the other side.
      identificationBelowReference: Whether to show the dashed identification
                        line below the solid reference line. By default, the
                        dashed identification line is shown above the solid
                        reference line. In order to comply with standards, if
                        identificationBelowReference is true, identificationLine
                        should also be true.
      fieldSpaceFactor: The relative spacing of the fields of the weld
                        information.
      lineGap:          The gap between the reference line and the weld
                        information.
      fieldWeldDirection: The direction of any field weld indicator.
      grooveGapTextStyle: How any groove gap text relates to its symbol.
      symbolSizeFactor: The size of basic and supplemental weld symbols relative
                        to the text height.

      Sub-elements:

      GrooveGapTextFormat: Overriding format attributes for any groove gap text.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API LineWeldDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    LineWeldDisplay( );
     
    //! Constructs a LineWeldDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LineWeldDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LineWeldDisplay();

private:

	//! Assignment operator
	LineWeldDisplay& operator=( const LineWeldDisplay& iSrc );

	//! Copy constructor
	LineWeldDisplay( const LineWeldDisplay& original );
     
public:

	//! Set FieldWeldType
	plmxml_api::Result SetFieldWeldType( const eAnn3DLineWeldFieldWeldEnum& arg );

	//! Get FieldWeldType
	eAnn3DLineWeldFieldWeldEnum GetFieldWeldType() const;

	//! Set ReferenceSignType
	plmxml_api::Result SetReferenceSignType( const eAnn3DLineWeldReferenceSignEnum& arg );

	//! Get ReferenceSignType
	eAnn3DLineWeldReferenceSignEnum GetReferenceSignType() const;

	//! Set IdentificationLine
	plmxml_api::Result SetIdentificationLine( plmxml_api::logical arg );

	//! Get IdentificationLine
	plmxml_api::logical GetIdentificationLine() const;

	//! Check if IdentificationLine is set
	plmxml_api::logical HasIdentificationLine() const;

	//! Unset IdentificationLine
	plmxml_api::Result UnsetIdentificationLine();

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set SymbolSizeFactor
	plmxml_api::Result SetSymbolSizeFactor( double arg );

     //! Get SymbolSizeFactor
	double GetSymbolSizeFactor() const;

	//! Check if SymbolSizeFactor is set
	plmxml_api::logical HasSymbolSizeFactor() const;

	//! Unset SymbolSizeFactor
	plmxml_api::Result UnsetSymbolSizeFactor();

	//! Set ArrowSideAboveLine
	plmxml_api::Result SetArrowSideAboveLine( plmxml_api::logical arg );

	//! Get ArrowSideAboveLine
	plmxml_api::logical GetArrowSideAboveLine() const;

	//! Check if ArrowSideAboveLine is set
	plmxml_api::logical HasArrowSideAboveLine() const;

	//! Unset ArrowSideAboveLine
	plmxml_api::Result UnsetArrowSideAboveLine();

	//! Set LineGap
	plmxml_api::Result SetLineGap( double arg );

     //! Get LineGap
	double GetLineGap() const;

	//! Check if LineGap is set
	plmxml_api::logical HasLineGap() const;

	//! Unset LineGap
	plmxml_api::Result UnsetLineGap();

	//! Set FieldWeldDirection
	plmxml_api::Result SetFieldWeldDirection( const eAnn3DFieldWeldDirectionEnum& arg );

	//! Get FieldWeldDirection
	eAnn3DFieldWeldDirectionEnum GetFieldWeldDirection() const;

	//! Set GrooveGapTextStyle
	plmxml_api::Result SetGrooveGapTextStyle( const eAnn3DGrooveGapTextStyleEnum& arg );

	//! Get GrooveGapTextStyle
	eAnn3DGrooveGapTextStyleEnum GetGrooveGapTextStyle() const;

	//! Set IdentificationBelowReference
	plmxml_api::Result SetIdentificationBelowReference( plmxml_api::logical arg );

	//! Get IdentificationBelowReference
	plmxml_api::logical GetIdentificationBelowReference() const;

	//! Check if IdentificationBelowReference is set
	plmxml_api::logical HasIdentificationBelowReference() const;

	//! Unset IdentificationBelowReference
	plmxml_api::Result UnsetIdentificationBelowReference();

	//! Set FieldSpaceFactor
	plmxml_api::Result SetFieldSpaceFactor( double arg );

     //! Get FieldSpaceFactor
	double GetFieldSpaceFactor() const;

	//! Check if FieldSpaceFactor is set
	plmxml_api::logical HasFieldSpaceFactor() const;

	//! Unset FieldSpaceFactor
	plmxml_api::Result UnsetFieldSpaceFactor();

	//! Add GrooveGapTextFormat child element to this LineWeldDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTextFormat *AddGrooveGapTextFormat();
     
	//! Set GrooveGapTextFormat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetGrooveGapTextFormat( Ann3DTextFormat *arg );
     
	//! Get GrooveGapTextFormat child element of this LineWeldDisplay.
	Ann3DTextFormat *GetGrooveGapTextFormat() const;
     
	//! Detach and delete GrooveGapTextFormat child element tree from this LineWeldDisplay.
	void DeleteGrooveGapTextFormat();
 
// <PLMXML_UserCode type="functionHeaderLineWeldDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassLineWeldDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DSpec class
/*!
\verbatim

      Ann3DSpec: base type for Specification annotations

      Attributes:

      identifier:       unique identifier for the specification
      revision:         revision of the specification
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DSpec : public Annotation3D
{
public:
     
    //! Default constructor
    Ann3DSpec( );
     
    //! Constructs a Ann3DSpec with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DSpec( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DSpec();

private:

	//! Assignment operator
	Ann3DSpec& operator=( const Ann3DSpec& iSrc );

	//! Copy constructor
	Ann3DSpec( const Ann3DSpec& original );
     
public:

	//! Get Identifier of this Ann3DSpec
	plmxml_api::String GetIdentifier() const;

	//! Set Identifier of this Ann3DSpec
	plmxml_api::Result SetIdentifier( const plmxml_api::String &s );
	
	//! Check if Identifier is set
	plmxml_api::logical HasIdentifier( ) const;
	
	//! Unset Identifier
	plmxml_api::Result UnsetIdentifier( );

	//! Get Revision of this Ann3DSpec
	plmxml_api::String GetRevision() const;

	//! Set Revision of this Ann3DSpec
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );
 
// <PLMXML_UserCode type="functionHeaderAnn3DSpec" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DSpec;


////////////////////////////////////////////////////////////////////////////////////
//! MaterialSpec class
/*!
\verbatim

      MaterialSpec: used to specify the material used in manufacture

      Elements:
          
      Nomenclature:     Textual information about the material
      OpenField:        Additional information
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API MaterialSpec : public Ann3DSpec
{
public:
     
    //! Default constructor
    MaterialSpec( );
     
    //! Constructs a MaterialSpec with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MaterialSpec( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MaterialSpec();

private:

	//! Assignment operator
	MaterialSpec& operator=( const MaterialSpec& iSrc );

	//! Copy constructor
	MaterialSpec( const MaterialSpec& original );
     
public:

	//! Add Nomenclature child element to this MaterialSpec. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddNomenclature();
     
	//! Set Nomenclature child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetNomenclature( Ann3DText *arg );
     
	//! Get Nomenclature child element of this MaterialSpec.
	Ann3DText *GetNomenclature() const;
     
	//! Detach and delete Nomenclature child element tree from this MaterialSpec.
	void DeleteNomenclature();

	//! Add OpenField child element to this MaterialSpec. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddOpenField();
     
	//! Set OpenField child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOpenField( Ann3DText *arg );
     
	//! Get OpenField child element of this MaterialSpec.
	Ann3DText *GetOpenField() const;
     
	//! Detach and delete OpenField child element tree from this MaterialSpec.
	void DeleteOpenField();
 
// <PLMXML_UserCode type="functionHeaderMaterialSpec" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassMaterialSpec;


////////////////////////////////////////////////////////////////////////////////////
//! MaterialSpecDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API MaterialSpecDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    MaterialSpecDisplay( );
     
    //! Constructs a MaterialSpecDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MaterialSpecDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MaterialSpecDisplay();

private:

	//! Assignment operator
	MaterialSpecDisplay& operator=( const MaterialSpecDisplay& iSrc );

	//! Copy constructor
	MaterialSpecDisplay( const MaterialSpecDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMaterialSpecDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassMaterialSpecDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessSpec class
/*!
\verbatim

      ProcessSpec: used to specify the process used in manufacture

      Elements:
      
      Nomenclature:     Textual information about the process
      OpenField:        Additional information
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API ProcessSpec : public Ann3DSpec
{
public:
     
    //! Default constructor
    ProcessSpec( );
     
    //! Constructs a ProcessSpec with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessSpec( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessSpec();

private:

	//! Assignment operator
	ProcessSpec& operator=( const ProcessSpec& iSrc );

	//! Copy constructor
	ProcessSpec( const ProcessSpec& original );
     
public:

	//! Add Nomenclature child element to this ProcessSpec. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddNomenclature();
     
	//! Set Nomenclature child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetNomenclature( Ann3DText *arg );
     
	//! Get Nomenclature child element of this ProcessSpec.
	Ann3DText *GetNomenclature() const;
     
	//! Detach and delete Nomenclature child element tree from this ProcessSpec.
	void DeleteNomenclature();

	//! Add OpenField child element to this ProcessSpec. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddOpenField();
     
	//! Set OpenField child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOpenField( Ann3DText *arg );
     
	//! Get OpenField child element of this ProcessSpec.
	Ann3DText *GetOpenField() const;
     
	//! Detach and delete OpenField child element tree from this ProcessSpec.
	void DeleteOpenField();
 
// <PLMXML_UserCode type="functionHeaderProcessSpec" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassProcessSpec;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessSpecDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API ProcessSpecDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    ProcessSpecDisplay( );
     
    //! Constructs a ProcessSpecDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessSpecDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessSpecDisplay();

private:

	//! Assignment operator
	ProcessSpecDisplay& operator=( const ProcessSpecDisplay& iSrc );

	//! Copy constructor
	ProcessSpecDisplay( const ProcessSpecDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcessSpecDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassProcessSpecDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! PartSpec class
/*!
\verbatim

      PartSpec: derived from Ann3DSpec
                Part identification based on MIL-STD-100

      Attributes:
          
      itemName:              
      nameModifier:
      descriptiveModifier: 
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API PartSpec : public Ann3DSpec
{
public:
     
    //! Default constructor
    PartSpec( );
     
    //! Constructs a PartSpec with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PartSpec( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PartSpec();

private:

	//! Assignment operator
	PartSpec& operator=( const PartSpec& iSrc );

	//! Copy constructor
	PartSpec( const PartSpec& original );
     
public:

	//! Get ItemName of this PartSpec
	plmxml_api::String GetItemName() const;

	//! Set ItemName of this PartSpec
	plmxml_api::Result SetItemName( const plmxml_api::String &s );
	
	//! Check if ItemName is set
	plmxml_api::logical HasItemName( ) const;
	
	//! Unset ItemName
	plmxml_api::Result UnsetItemName( );

	//! Get NameModifier of this PartSpec
	plmxml_api::String GetNameModifier() const;

	//! Set NameModifier of this PartSpec
	plmxml_api::Result SetNameModifier( const plmxml_api::String &s );
	
	//! Check if NameModifier is set
	plmxml_api::logical HasNameModifier( ) const;
	
	//! Unset NameModifier
	plmxml_api::Result UnsetNameModifier( );

	//! Get DescriptiveModifier of this PartSpec
	plmxml_api::String GetDescriptiveModifier() const;

	//! Set DescriptiveModifier of this PartSpec
	plmxml_api::Result SetDescriptiveModifier( const plmxml_api::String &s );
	
	//! Check if DescriptiveModifier is set
	plmxml_api::logical HasDescriptiveModifier( ) const;
	
	//! Unset DescriptiveModifier
	plmxml_api::Result UnsetDescriptiveModifier( );
 
// <PLMXML_UserCode type="functionHeaderPartSpec" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassPartSpec;


////////////////////////////////////////////////////////////////////////////////////
//! PartSpecDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API PartSpecDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    PartSpecDisplay( );
     
    //! Constructs a PartSpecDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PartSpecDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PartSpecDisplay();

private:

	//! Assignment operator
	PartSpecDisplay& operator=( const PartSpecDisplay& iSrc );

	//! Copy constructor
	PartSpecDisplay( const PartSpecDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPartSpecDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassPartSpecDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DOrganisation class
/*!
\verbatim

      An Annotation which specifies an associated organisation. The Ann3DInstance which
      references this Annotation should also reference an Organisation and/or Site 
      element.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DOrganisation : public Annotation3D
{
public:
     
    //! Default constructor
    Ann3DOrganisation( );
     
    //! Constructs a Ann3DOrganisation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DOrganisation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DOrganisation();

private:

	//! Assignment operator
	Ann3DOrganisation& operator=( const Ann3DOrganisation& iSrc );

	//! Copy constructor
	Ann3DOrganisation( const Ann3DOrganisation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DOrganisation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DOrganisation;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DOrganisationDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DOrganisationDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    Ann3DOrganisationDisplay( );
     
    //! Constructs a Ann3DOrganisationDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DOrganisationDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DOrganisationDisplay();

private:

	//! Assignment operator
	Ann3DOrganisationDisplay& operator=( const Ann3DOrganisationDisplay& iSrc );

	//! Copy constructor
	Ann3DOrganisationDisplay( const Ann3DOrganisationDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DOrganisationDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DOrganisationDisplay;


//! Forward class declarations
class Ann3DUserDefinedSymbolText;

////////////////////////////////////////////////////////////////////////////////////
//! Note class
/*!
\verbatim

      Note Annotation

      Attributes:

      standard:         standard applicable to the Note
      identifier:       identifier of the Note
      category:         category of the Note
      revision:         revision of the Note
      allAround:        Whether the All Around symbol is added.

      Elements:

      Text:             Zero or more blocks of text.
      AltText:          Any number of blocks of alternative text. It is up to
                        the consuming application how to display alternative
                        text.
      NoteText:         Similar to Text but allows the origin and the direction
                        of each block to be specified individually.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Note : public Annotation3D
{
public:
     
    //! Default constructor
    Note( );
     
    //! Constructs a Note with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Note( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Note();

private:

	//! Assignment operator
	Note& operator=( const Note& iSrc );

	//! Copy constructor
	Note( const Note& original );
     
public:

	//! Get Identifier of this Note
	plmxml_api::String GetIdentifier() const;

	//! Set Identifier of this Note
	plmxml_api::Result SetIdentifier( const plmxml_api::String &s );
	
	//! Check if Identifier is set
	plmxml_api::logical HasIdentifier( ) const;
	
	//! Unset Identifier
	plmxml_api::Result UnsetIdentifier( );

	//! Get Category of this Note
	plmxml_api::String GetCategory() const;

	//! Set Category of this Note
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Get Revision of this Note
	plmxml_api::String GetRevision() const;

	//! Set Revision of this Note
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Add Text child element to this Note. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddText();
     
	//! Add 'arg' as Text child element to this Note.
	plmxml_api::Result AddText( Ann3DText *arg );

	//! Detach and delete all Text child elements.
	void DeleteTexts();
     
	//! Get number of Text child elements.
	int NumberOfTexts() const;
     
	//! Get i'th Text child element.
	Ann3DText *GetText( int i ) const;
     
	//! Get all Text child element as an array
	void GetTexts( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th Text child element
	void DeleteText( int i );
     
	//! Detach and delete 'arg' if it's one of the Text child elements
	void DeleteText( Ann3DText *arg );

	//! Add AltText child element to this Note. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddAltText();
     
	//! Add 'arg' as AltText child element to this Note.
	plmxml_api::Result AddAltText( Ann3DText *arg );

	//! Detach and delete all AltText child elements.
	void DeleteAltTexts();
     
	//! Get number of AltText child elements.
	int NumberOfAltTexts() const;
     
	//! Get i'th AltText child element.
	Ann3DText *GetAltText( int i ) const;
     
	//! Get all AltText child element as an array
	void GetAltTexts( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th AltText child element
	void DeleteAltText( int i );
     
	//! Detach and delete 'arg' if it's one of the AltText child elements
	void DeleteAltText( Ann3DText *arg );

	//! Add NoteText child element to this Note. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DUserDefinedSymbolText *AddNoteText();
     
	//! Add 'arg' as NoteText child element to this Note.
	plmxml_api::Result AddNoteText( Ann3DUserDefinedSymbolText *arg );

	//! Detach and delete all NoteText child elements.
	void DeleteNoteTexts();
     
	//! Get number of NoteText child elements.
	int NumberOfNoteTexts() const;
     
	//! Get i'th NoteText child element.
	Ann3DUserDefinedSymbolText *GetNoteText( int i ) const;
     
	//! Get all NoteText child element as an array
	void GetNoteTexts( plmxml_api::Array<Ann3DUserDefinedSymbolText*> &array ) const;
	     
	//! Detach and delete i'th NoteText child element
	void DeleteNoteText( int i );
     
	//! Detach and delete 'arg' if it's one of the NoteText child elements
	void DeleteNoteText( Ann3DUserDefinedSymbolText *arg );
 
// <PLMXML_UserCode type="functionHeaderNote" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassNote;


////////////////////////////////////////////////////////////////////////////////////
//! NoteDisplay class
/*!
\verbatim

      Note display.

      Attributes:

      displayType:      Whether the Note is displayed flat to the screen or flat
                        to the surface.
      datumOnLeader:    Whether the Leader has an intermediate datum symbol
                        rather than going directly to the target geometry and,
                        if it has, whether the symbol is solid or filled.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API NoteDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    NoteDisplay( );
     
    //! Constructs a NoteDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NoteDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NoteDisplay();

private:

	//! Assignment operator
	NoteDisplay& operator=( const NoteDisplay& iSrc );

	//! Copy constructor
	NoteDisplay( const NoteDisplay& original );
     
public:

	//! Set DatumOnLeader
	plmxml_api::Result SetDatumOnLeader( const eAnn3DDatumOnLeaderEnum& arg );

	//! Get DatumOnLeader
	eAnn3DDatumOnLeaderEnum GetDatumOnLeader() const;

	//! Set DisplayType
	plmxml_api::Result SetDisplayType( const eAnn3DNoteDisplayEnum& arg );

	//! Get DisplayType
	eAnn3DNoteDisplayEnum GetDisplayType() const;
 
// <PLMXML_UserCode type="functionHeaderNoteDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassNoteDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Balloon class
/*!
\verbatim

      Balloon Annotation (derived from Note).
      
      Attributes:
      
      balloonId:       String giving the letter(s) displayed inside the Balloon circle.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Balloon : public Note
{
public:
     
    //! Default constructor
    Balloon( );
     
    //! Constructs a Balloon with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Balloon( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Balloon();

private:

	//! Assignment operator
	Balloon& operator=( const Balloon& iSrc );

	//! Copy constructor
	Balloon( const Balloon& original );
     
public:

	//! Get BalloonId of this Balloon
	plmxml_api::String GetBalloonId() const;

	//! Set BalloonId of this Balloon
	plmxml_api::Result SetBalloonId( const plmxml_api::String &s );
	
	//! Check if BalloonId is set
	plmxml_api::logical HasBalloonId( ) const;
	
	//! Unset BalloonId
	plmxml_api::Result UnsetBalloonId( );
 
// <PLMXML_UserCode type="functionHeaderBalloon" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassBalloon;


////////////////////////////////////////////////////////////////////////////////////
//! BalloonDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API BalloonDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    BalloonDisplay( );
     
    //! Constructs a BalloonDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BalloonDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BalloonDisplay();

private:

	//! Assignment operator
	BalloonDisplay& operator=( const BalloonDisplay& iSrc );

	//! Copy constructor
	BalloonDisplay( const BalloonDisplay& original );
     
public:

	//! Set Radius
	plmxml_api::Result SetRadius( double arg );

     //! Get Radius
	double GetRadius() const;

	//! Check if Radius is set
	plmxml_api::logical HasRadius() const;

	//! Unset Radius
	plmxml_api::Result UnsetRadius();
 
// <PLMXML_UserCode type="functionHeaderBalloonDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassBalloonDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! MeasurementPoint class
/*!
\verbatim

      MeasurementPoint: derived from Annotation3D

      Attributes:
      
      level:                  level of measurement point use in process
      measurementDirection:   direction CMM approaches measurement point
      coordinationDirection:  direction for coordinating with another part
      normalDirection:        normal vector at point of measurement point
      position:               location of the measurement point
        
      Elements:
        
      CoordinatedEntity:      text string specifying a related entity in an undefined way
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API MeasurementPoint : public Annotation3D
{
public:
     
    //! Default constructor
    MeasurementPoint( );
     
    //! Constructs a MeasurementPoint with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MeasurementPoint( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MeasurementPoint();

private:

	//! Assignment operator
	MeasurementPoint& operator=( const MeasurementPoint& iSrc );

	//! Copy constructor
	MeasurementPoint( const MeasurementPoint& original );
     
public:

	//! Set MeasurementDirection using plmxml_api::Vector components
	plmxml_api::Result SetMeasurementDirection( const plmxml_api::Vector& arg );

	//! Get MeasurementDirection as plmxml_api::Vector
	plmxml_api::Result GetMeasurementDirection( plmxml_api::Vector& arg ) const;

	//! Check if MeasurementDirection is set
	plmxml_api::logical HasMeasurementDirection() const;

	//! Unset MeasurementDirection
	plmxml_api::Result UnsetMeasurementDirection();

	//! Set NormalDirection using plmxml_api::Vector components
	plmxml_api::Result SetNormalDirection( const plmxml_api::Vector& arg );

	//! Get NormalDirection as plmxml_api::Vector
	plmxml_api::Result GetNormalDirection( plmxml_api::Vector& arg ) const;

	//! Check if NormalDirection is set
	plmxml_api::logical HasNormalDirection() const;

	//! Unset NormalDirection
	plmxml_api::Result UnsetNormalDirection();

	//! Set CoordinationDirection using plmxml_api::Vector components
	plmxml_api::Result SetCoordinationDirection( const plmxml_api::Vector& arg );

	//! Get CoordinationDirection as plmxml_api::Vector
	plmxml_api::Result GetCoordinationDirection( plmxml_api::Vector& arg ) const;

	//! Check if CoordinationDirection is set
	plmxml_api::logical HasCoordinationDirection() const;

	//! Unset CoordinationDirection
	plmxml_api::Result UnsetCoordinationDirection();

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();

	//! Get Level of this MeasurementPoint
	plmxml_api::String GetLevel() const;

	//! Set Level of this MeasurementPoint
	plmxml_api::Result SetLevel( const plmxml_api::String &s );
	
	//! Check if Level is set
	plmxml_api::logical HasLevel( ) const;
	
	//! Unset Level
	plmxml_api::Result UnsetLevel( );

	//! Add CoordinatedEntity child element to this MeasurementPoint. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCoordinatedEntity();
     
	//! Add 'arg' as CoordinatedEntity child element to this MeasurementPoint.
	plmxml_api::Result AddCoordinatedEntity( Ann3DText *arg );

	//! Detach and delete all CoordinatedEntity child elements.
	void DeleteCoordinatedEntities();
     
	//! Get number of CoordinatedEntity child elements.
	int NumberOfCoordinatedEntities() const;
     
	//! Get i'th CoordinatedEntity child element.
	Ann3DText *GetCoordinatedEntity( int i ) const;
     
	//! Get all CoordinatedEntity child element as an array
	void GetCoordinatedEntities( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th CoordinatedEntity child element
	void DeleteCoordinatedEntity( int i );
     
	//! Detach and delete 'arg' if it's one of the CoordinatedEntity child elements
	void DeleteCoordinatedEntity( Ann3DText *arg );
 
// <PLMXML_UserCode type="functionHeaderMeasurementPoint" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassMeasurementPoint;


////////////////////////////////////////////////////////////////////////////////////
//! MeasurementPointDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API MeasurementPointDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    MeasurementPointDisplay( );
     
    //! Constructs a MeasurementPointDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MeasurementPointDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MeasurementPointDisplay();

private:

	//! Assignment operator
	MeasurementPointDisplay& operator=( const MeasurementPointDisplay& iSrc );

	//! Copy constructor
	MeasurementPointDisplay( const MeasurementPointDisplay& original );
     
public:

	//! Set DisplayType
	plmxml_api::Result SetDisplayType( const eAnn3DMeasurementPointDisplay& arg );

	//! Get DisplayType
	eAnn3DMeasurementPointDisplay GetDisplayType() const;
 
// <PLMXML_UserCode type="functionHeaderMeasurementPointDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassMeasurementPointDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Locator class
/*!
\verbatim

      Locator Annotation.

      Attributes:
      
      symbol:                  Main type of the Locator Symbol. e.g. hole, edge, surface, etc.

                               One of the following is required, depending on the value of symbol
      mainEdgeType:            If symbol is edge, indicates thge type of the Edge Locator
      mainHoleType:            If symbol is hole, indicates the type of the Hole Locator
      mainSurfaceType:         If symbol is surface, indicates the type of the Surface Locator
      mainRectSlotFreeformType:If symbol is recangular, slot or freeform
                                  indicates the type of the Rectangular, Slot or Freeform
                                  Locator
      subtype:                 Indicates the subtype of the Locator
      coordinatePlane:         Indicates the coordinate plane for which the Locator limits
                                  the degrees of freedom of the Part
      functionalSubscript:     Indicates which functional subscripts are applicable.
                                  These are (may include more than one):
                                   O - Dies, molds, checking fixtures for individual parts
                                   S - Sub-assembly prior to framing
                                   K - Sub-assembly locators in checking fixtures
                                   C - Assembly fixtures for framing prior to paint
                                   F - Trim and final assembly after paint
      changeLevel:             Indicates how easy it is (for the overall process) to allow 
                                  change to this Locator.
      punchDirection[3]:       punch direction - direction in which punch approaches part
      pinDirection[3]:         pin direction - direction in which part is pinned
      normalDirection[3]:      normal direction - normal vector at this locator
      hotSpotPosition:         position of the Hot Spot for the Locator in global space
       
      Elements:
        
      PartNumber:              a user entered string indicating the part number
      Note:                    a user entered string, free text
      CoordinatedEntity:       a text string specifying a related entity in an undefined way
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Locator : public Annotation3D
{
public:
     
    //! Default constructor
    Locator( );
     
    //! Constructs a Locator with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Locator( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Locator();

private:

	//! Assignment operator
	Locator& operator=( const Locator& iSrc );

	//! Copy constructor
	Locator( const Locator& original );
     
public:

	//! Set HotSpotPosition using plmxml_api::Vector components
	plmxml_api::Result SetHotSpotPosition( const plmxml_api::Vector& arg );

	//! Get HotSpotPosition as plmxml_api::Vector
	plmxml_api::Result GetHotSpotPosition( plmxml_api::Vector& arg ) const;

	//! Check if HotSpotPosition is set
	plmxml_api::logical HasHotSpotPosition() const;

	//! Unset HotSpotPosition
	plmxml_api::Result UnsetHotSpotPosition();

	//! Set PinDirection using plmxml_api::Vector components
	plmxml_api::Result SetPinDirection( const plmxml_api::Vector& arg );

	//! Get PinDirection as plmxml_api::Vector
	plmxml_api::Result GetPinDirection( plmxml_api::Vector& arg ) const;

	//! Check if PinDirection is set
	plmxml_api::logical HasPinDirection() const;

	//! Unset PinDirection
	plmxml_api::Result UnsetPinDirection();

	//! Set CoordinatePlane
	plmxml_api::Result SetCoordinatePlane( const eAnn3DLocatorCoordinatePlane& arg );

	//! Get CoordinatePlane
	eAnn3DLocatorCoordinatePlane GetCoordinatePlane() const;

	//! Set MainEdgeType
	plmxml_api::Result SetMainEdgeType( const eAnn3DLocatorEdgeType& arg );

	//! Get MainEdgeType
	eAnn3DLocatorEdgeType GetMainEdgeType() const;

	//! Get FunctionalSubscript of this Locator
	plmxml_api::String GetFunctionalSubscript() const;

	//! Set FunctionalSubscript of this Locator
	plmxml_api::Result SetFunctionalSubscript( const plmxml_api::String &s );
	
	//! Check if FunctionalSubscript is set
	plmxml_api::logical HasFunctionalSubscript( ) const;
	
	//! Unset FunctionalSubscript
	plmxml_api::Result UnsetFunctionalSubscript( );

	//! Set ChangeLevel
	plmxml_api::Result SetChangeLevel( const eAnn3DLocatorChangeLevel& arg );

	//! Get ChangeLevel
	eAnn3DLocatorChangeLevel GetChangeLevel() const;

	//! Set NormalDirection using plmxml_api::Vector components
	plmxml_api::Result SetNormalDirection( const plmxml_api::Vector& arg );

	//! Get NormalDirection as plmxml_api::Vector
	plmxml_api::Result GetNormalDirection( plmxml_api::Vector& arg ) const;

	//! Check if NormalDirection is set
	plmxml_api::logical HasNormalDirection() const;

	//! Unset NormalDirection
	plmxml_api::Result UnsetNormalDirection();

	//! Set MainSurfaceType
	plmxml_api::Result SetMainSurfaceType( const eAnn3DLocatorSurfaceType& arg );

	//! Get MainSurfaceType
	eAnn3DLocatorSurfaceType GetMainSurfaceType() const;

	//! Set PunchDirection using plmxml_api::Vector components
	plmxml_api::Result SetPunchDirection( const plmxml_api::Vector& arg );

	//! Get PunchDirection as plmxml_api::Vector
	plmxml_api::Result GetPunchDirection( plmxml_api::Vector& arg ) const;

	//! Check if PunchDirection is set
	plmxml_api::logical HasPunchDirection() const;

	//! Unset PunchDirection
	plmxml_api::Result UnsetPunchDirection();

	//! Set Symbol
	plmxml_api::Result SetSymbol( const eAnn3DLocatorSymbol& arg );

	//! Get Symbol
	eAnn3DLocatorSymbol GetSymbol() const;

	//! Set MainHoleType
	plmxml_api::Result SetMainHoleType( const eAnn3DLocatorHoleType& arg );

	//! Get MainHoleType
	eAnn3DLocatorHoleType GetMainHoleType() const;

	//! Set Subtype
	plmxml_api::Result SetSubtype( const eAnn3DLocatorSubtype& arg );

	//! Get Subtype
	eAnn3DLocatorSubtype GetSubtype() const;

	//! Set MainRectSlotFreeformType
	plmxml_api::Result SetMainRectSlotFreeformType( const eAnn3DLocatorRectSlotFreeformType& arg );

	//! Get MainRectSlotFreeformType
	eAnn3DLocatorRectSlotFreeformType GetMainRectSlotFreeformType() const;

	//! Add PartNumber child element to this Locator. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddPartNumber();
     
	//! Set PartNumber child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPartNumber( Ann3DText *arg );
     
	//! Get PartNumber child element of this Locator.
	Ann3DText *GetPartNumber() const;
     
	//! Detach and delete PartNumber child element tree from this Locator.
	void DeletePartNumber();

	//! Add Note child element to this Locator. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddNote();
     
	//! Set Note child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetNote( Ann3DText *arg );
     
	//! Get Note child element of this Locator.
	Ann3DText *GetNote() const;
     
	//! Detach and delete Note child element tree from this Locator.
	void DeleteNote();

	//! Add CoordinatedEntity child element to this Locator. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCoordinatedEntity();
     
	//! Add 'arg' as CoordinatedEntity child element to this Locator.
	plmxml_api::Result AddCoordinatedEntity( Ann3DText *arg );

	//! Detach and delete all CoordinatedEntity child elements.
	void DeleteCoordinatedEntities();
     
	//! Get number of CoordinatedEntity child elements.
	int NumberOfCoordinatedEntities() const;
     
	//! Get i'th CoordinatedEntity child element.
	Ann3DText *GetCoordinatedEntity( int i ) const;
     
	//! Get all CoordinatedEntity child element as an array
	void GetCoordinatedEntities( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th CoordinatedEntity child element
	void DeleteCoordinatedEntity( int i );
     
	//! Detach and delete 'arg' if it's one of the CoordinatedEntity child elements
	void DeleteCoordinatedEntity( Ann3DText *arg );
 
// <PLMXML_UserCode type="functionHeaderLocator" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassLocator;


////////////////////////////////////////////////////////////////////////////////////
//! LocatorDisplay class
/*!
\verbatim

      Attributes:

      precision:        number of decimal places
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API LocatorDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    LocatorDisplay( );
     
    //! Constructs a LocatorDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LocatorDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LocatorDisplay();

private:

	//! Assignment operator
	LocatorDisplay& operator=( const LocatorDisplay& iSrc );

	//! Copy constructor
	LocatorDisplay( const LocatorDisplay& original );
     
public:

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();
 
// <PLMXML_UserCode type="functionHeaderLocatorDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassLocatorDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DUserDefinedSymbolText class
/*!
\verbatim

      Text to be added to a User Defined Symbol in a specified position and orientation
      
      Attributes: 
      
      origin:      position of start of text, in the display plane
      direction:   direction of text
      
      Elements:
      
      Text:           a single Ann3DTextType element (required)
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DUserDefinedSymbolText : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DUserDefinedSymbolText( );
     
    //! Constructs a Ann3DUserDefinedSymbolText with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DUserDefinedSymbolText( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DUserDefinedSymbolText();

private:

	//! Assignment operator
	Ann3DUserDefinedSymbolText& operator=( const Ann3DUserDefinedSymbolText& iSrc );

	//! Copy constructor
	Ann3DUserDefinedSymbolText( const Ann3DUserDefinedSymbolText& original );
     
public:

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set Origin using plmxml_api::Vector components
	plmxml_api::Result SetOrigin( const plmxml_api::Vector& arg );

	//! Get Origin as plmxml_api::Vector
	plmxml_api::Result GetOrigin( plmxml_api::Vector& arg ) const;

	//! Check if Origin is set
	plmxml_api::logical HasOrigin() const;

	//! Unset Origin
	plmxml_api::Result UnsetOrigin();

	//! Add Text child element to this Ann3DUserDefinedSymbolText. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddText();
     
	//! Set Text child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetText( Ann3DText *arg );
     
	//! Get Text child element of this Ann3DUserDefinedSymbolText.
	Ann3DText *GetText() const;
     
	//! Detach and delete Text child element tree from this Ann3DUserDefinedSymbolText.
	void DeleteText();
 
// <PLMXML_UserCode type="functionHeaderAnn3DUserDefinedSymbolText" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DUserDefinedSymbolText;


////////////////////////////////////////////////////////////////////////////////////
//! UserDefinedSymbol class
/*!
\verbatim

      UserDefinedSymbol Annotation.
      
      Note that the textOrigin and textDirection attributes on Ann3DisplayType
      do not apply to this Annotation.

      Attributes:
        
      lineStyle:         The style applied to the lines in the User Defined Symbol
      scale:             Scale factor applied to the symbol
      filename:          name of the file used to define the symbol
       
      Elements:
      
      Line:              One element for each line in the symbol
      Arc:               One element for each arc in the symbol
      Circle:            One element for each circle in the symbol
      Ellipse:           One element for each ellipse in the symbol
      Spline:            One element for each spline in the symbol
      PolyLine:          One element for each polyline in the symbol
      UserDefinedSymbolText: Positioned and oriented Text blocks
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API UserDefinedSymbol : public Annotation3D
{
public:
     
    //! Default constructor
    UserDefinedSymbol( );
     
    //! Constructs a UserDefinedSymbol with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UserDefinedSymbol( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UserDefinedSymbol();

private:

	//! Assignment operator
	UserDefinedSymbol& operator=( const UserDefinedSymbol& iSrc );

	//! Copy constructor
	UserDefinedSymbol( const UserDefinedSymbol& original );
     
public:

	//! Set Scale
	plmxml_api::Result SetScale( double arg );

     //! Get Scale
	double GetScale() const;

	//! Check if Scale is set
	plmxml_api::logical HasScale() const;

	//! Unset Scale
	plmxml_api::Result UnsetScale();

	//! Get Filename URI as plmxml_api::String
	plmxml_api::String GetFilenameURI() const;

	//! Set Filename URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFilenameURI( const plmxml_api::String& );
	
	//! Get the handle of Filename URI. Does not resolve the URI.
	plmxml_api::Result GetFilenameURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Filename URI. URI string is unchanged.
	plmxml_api::Result SetFilenameURI( const plmxml_api::Handle& );
	
	//! Resolve Filename URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFilenameURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Filename URI. Clears URI string and handle.
	plmxml_api::Result DeleteFilenameURI();
	
	//! Check if Filename URI is set
	plmxml_api::logical HasFilenameURI( ) const;
	

	//! Set LineStyle
	plmxml_api::Result SetLineStyle( const eAnn3DLineType& arg );

	//! Get LineStyle
	eAnn3DLineType GetLineStyle() const;

	//! Add Line child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Line *AddLine();
     
	//! Add 'arg' as Line child element to this UserDefinedSymbol.
	plmxml_api::Result AddLine( Line *arg );

	//! Detach and delete all Line child elements.
	void DeleteLines();
     
	//! Get number of Line child elements.
	int NumberOfLines() const;
     
	//! Get i'th Line child element.
	Line *GetLine( int i ) const;
     
	//! Get all Line child element as an array
	void GetLines( plmxml_api::Array<Line*> &array ) const;
	     
	//! Detach and delete i'th Line child element
	void DeleteLine( int i );
     
	//! Detach and delete 'arg' if it's one of the Line child elements
	void DeleteLine( Line *arg );

	//! Add Arc child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Circle *AddArc();
     
	//! Add 'arg' as Arc child element to this UserDefinedSymbol.
	plmxml_api::Result AddArc( Circle *arg );

	//! Detach and delete all Arc child elements.
	void DeleteArcs();
     
	//! Get number of Arc child elements.
	int NumberOfArcs() const;
     
	//! Get i'th Arc child element.
	Circle *GetArc( int i ) const;
     
	//! Get all Arc child element as an array
	void GetArcs( plmxml_api::Array<Circle*> &array ) const;
	     
	//! Detach and delete i'th Arc child element
	void DeleteArc( int i );
     
	//! Detach and delete 'arg' if it's one of the Arc child elements
	void DeleteArc( Circle *arg );

	//! Add Circle child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Circle *AddCircle();
     
	//! Add 'arg' as Circle child element to this UserDefinedSymbol.
	plmxml_api::Result AddCircle( Circle *arg );

	//! Detach and delete all Circle child elements.
	void DeleteCircles();
     
	//! Get number of Circle child elements.
	int NumberOfCircles() const;
     
	//! Get i'th Circle child element.
	Circle *GetCircle( int i ) const;
     
	//! Get all Circle child element as an array
	void GetCircles( plmxml_api::Array<Circle*> &array ) const;
	     
	//! Detach and delete i'th Circle child element
	void DeleteCircle( int i );
     
	//! Detach and delete 'arg' if it's one of the Circle child elements
	void DeleteCircle( Circle *arg );

	//! Add Ellipse child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ellipse *AddEllipse();
     
	//! Add 'arg' as Ellipse child element to this UserDefinedSymbol.
	plmxml_api::Result AddEllipse( Ellipse *arg );

	//! Detach and delete all Ellipse child elements.
	void DeleteEllipses();
     
	//! Get number of Ellipse child elements.
	int NumberOfEllipses() const;
     
	//! Get i'th Ellipse child element.
	Ellipse *GetEllipse( int i ) const;
     
	//! Get all Ellipse child element as an array
	void GetEllipses( plmxml_api::Array<Ellipse*> &array ) const;
	     
	//! Detach and delete i'th Ellipse child element
	void DeleteEllipse( int i );
     
	//! Detach and delete 'arg' if it's one of the Ellipse child elements
	void DeleteEllipse( Ellipse *arg );

	//! Add Spline child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	BSplineCurve *AddSpline();
     
	//! Add 'arg' as Spline child element to this UserDefinedSymbol.
	plmxml_api::Result AddSpline( BSplineCurve *arg );

	//! Detach and delete all Spline child elements.
	void DeleteSplines();
     
	//! Get number of Spline child elements.
	int NumberOfSplines() const;
     
	//! Get i'th Spline child element.
	BSplineCurve *GetSpline( int i ) const;
     
	//! Get all Spline child element as an array
	void GetSplines( plmxml_api::Array<BSplineCurve*> &array ) const;
	     
	//! Detach and delete i'th Spline child element
	void DeleteSpline( int i );
     
	//! Detach and delete 'arg' if it's one of the Spline child elements
	void DeleteSpline( BSplineCurve *arg );

	//! Add PolyLine child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PolyLine *AddPolyLine();
     
	//! Add 'arg' as PolyLine child element to this UserDefinedSymbol.
	plmxml_api::Result AddPolyLine( PolyLine *arg );

	//! Detach and delete all PolyLine child elements.
	void DeletePolyLines();
     
	//! Get number of PolyLine child elements.
	int NumberOfPolyLines() const;
     
	//! Get i'th PolyLine child element.
	PolyLine *GetPolyLine( int i ) const;
     
	//! Get all PolyLine child element as an array
	void GetPolyLines( plmxml_api::Array<PolyLine*> &array ) const;
	     
	//! Detach and delete i'th PolyLine child element
	void DeletePolyLine( int i );
     
	//! Detach and delete 'arg' if it's one of the PolyLine child elements
	void DeletePolyLine( PolyLine *arg );

	//! Add UserDefinedSymbolText child element to this UserDefinedSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DUserDefinedSymbolText *AddUserDefinedSymbolText();
     
	//! Add 'arg' as UserDefinedSymbolText child element to this UserDefinedSymbol.
	plmxml_api::Result AddUserDefinedSymbolText( Ann3DUserDefinedSymbolText *arg );

	//! Detach and delete all UserDefinedSymbolText child elements.
	void DeleteUserDefinedSymbolTexts();
     
	//! Get number of UserDefinedSymbolText child elements.
	int NumberOfUserDefinedSymbolTexts() const;
     
	//! Get i'th UserDefinedSymbolText child element.
	Ann3DUserDefinedSymbolText *GetUserDefinedSymbolText( int i ) const;
     
	//! Get all UserDefinedSymbolText child element as an array
	void GetUserDefinedSymbolTexts( plmxml_api::Array<Ann3DUserDefinedSymbolText*> &array ) const;
	     
	//! Detach and delete i'th UserDefinedSymbolText child element
	void DeleteUserDefinedSymbolText( int i );
     
	//! Detach and delete 'arg' if it's one of the UserDefinedSymbolText child elements
	void DeleteUserDefinedSymbolText( Ann3DUserDefinedSymbolText *arg );
 
// <PLMXML_UserCode type="functionHeaderUserDefinedSymbol" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassUserDefinedSymbol;


////////////////////////////////////////////////////////////////////////////////////
//! UserDefinedSymbolDisplay class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ANNOTATION60_API UserDefinedSymbolDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    UserDefinedSymbolDisplay( );
     
    //! Constructs a UserDefinedSymbolDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UserDefinedSymbolDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UserDefinedSymbolDisplay();

private:

	//! Assignment operator
	UserDefinedSymbolDisplay& operator=( const UserDefinedSymbolDisplay& iSrc );

	//! Copy constructor
	UserDefinedSymbolDisplay( const UserDefinedSymbolDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderUserDefinedSymbolDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassUserDefinedSymbolDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! CircleCentre class
/*!
\verbatim

      CircleCentre Annotation.

      Attributes:
      
      diameter:            specifies the diameter of the circle if not derived
                             from the tracked geometry
      diameterOverride:    indicates whether the diameter of any tracked geometry is
                             overridden by the value specified in diameter.
      axisDirection[3]:    axis direction of hole etc.
      normalDirection[3]:  normal direction
      position:            position of the Circle Centre in model space
        
      Elements:
      
      CoordinatedEntity:   a text string specifying a related entity in some unspecified way
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CircleCentre : public Annotation3D
{
public:
     
    //! Default constructor
    CircleCentre( );
     
    //! Constructs a CircleCentre with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CircleCentre( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CircleCentre();

private:

	//! Assignment operator
	CircleCentre& operator=( const CircleCentre& iSrc );

	//! Copy constructor
	CircleCentre( const CircleCentre& original );
     
public:

	//! Set NormalDirection using plmxml_api::Vector components
	plmxml_api::Result SetNormalDirection( const plmxml_api::Vector& arg );

	//! Get NormalDirection as plmxml_api::Vector
	plmxml_api::Result GetNormalDirection( plmxml_api::Vector& arg ) const;

	//! Check if NormalDirection is set
	plmxml_api::logical HasNormalDirection() const;

	//! Unset NormalDirection
	plmxml_api::Result UnsetNormalDirection();

	//! Set AxisDirection using plmxml_api::Vector components
	plmxml_api::Result SetAxisDirection( const plmxml_api::Vector& arg );

	//! Get AxisDirection as plmxml_api::Vector
	plmxml_api::Result GetAxisDirection( plmxml_api::Vector& arg ) const;

	//! Check if AxisDirection is set
	plmxml_api::logical HasAxisDirection() const;

	//! Unset AxisDirection
	plmxml_api::Result UnsetAxisDirection();

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Set DiameterOverride
	plmxml_api::Result SetDiameterOverride( plmxml_api::logical arg );

	//! Get DiameterOverride
	plmxml_api::logical GetDiameterOverride() const;

	//! Check if DiameterOverride is set
	plmxml_api::logical HasDiameterOverride() const;

	//! Unset DiameterOverride
	plmxml_api::Result UnsetDiameterOverride();

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();

	//! Add CoordinatedEntity child element to this CircleCentre. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCoordinatedEntity();
     
	//! Add 'arg' as CoordinatedEntity child element to this CircleCentre.
	plmxml_api::Result AddCoordinatedEntity( Ann3DText *arg );

	//! Detach and delete all CoordinatedEntity child elements.
	void DeleteCoordinatedEntities();
     
	//! Get number of CoordinatedEntity child elements.
	int NumberOfCoordinatedEntities() const;
     
	//! Get i'th CoordinatedEntity child element.
	Ann3DText *GetCoordinatedEntity( int i ) const;
     
	//! Get all CoordinatedEntity child element as an array
	void GetCoordinatedEntities( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th CoordinatedEntity child element
	void DeleteCoordinatedEntity( int i );
     
	//! Detach and delete 'arg' if it's one of the CoordinatedEntity child elements
	void DeleteCoordinatedEntity( Ann3DText *arg );
 
// <PLMXML_UserCode type="functionHeaderCircleCentre" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCircleCentre;


////////////////////////////////////////////////////////////////////////////////////
//! CircleCentreDisplay class
/*!
\verbatim

      CircleCentre Display.

      Attributes:
      
      precision:           number of decimal places used in the display
      displayType:         flatToScreen or flatToSurface
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CircleCentreDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    CircleCentreDisplay( );
     
    //! Constructs a CircleCentreDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CircleCentreDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CircleCentreDisplay();

private:

	//! Assignment operator
	CircleCentreDisplay& operator=( const CircleCentreDisplay& iSrc );

	//! Copy constructor
	CircleCentreDisplay( const CircleCentreDisplay& original );
     
public:

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set DisplayType
	plmxml_api::Result SetDisplayType( const eAnn3DCircleCentreDisplay& arg );

	//! Get DisplayType
	eAnn3DCircleCentreDisplay GetDisplayType() const;
 
// <PLMXML_UserCode type="functionHeaderCircleCentreDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCircleCentreDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! CoordinateNote class
/*!
\verbatim

      CoordinateNote Annotation

      Attributes:

      standard:       standard used in for the Coordinate Note
      textBox:        Indicates whether or not the note has a box around it

      includeX:       Indicates whether or not to include the X coordinate of the tracked entity
      xPrefix:        User specified prefix for X coordinate
      xSuffix:        User specified suffix for X coordinate
      xOverride:      If present, overrides the computed X coordinate value.

      includeY:       Indicates whether or not to include the Y coordinate of the tracked entity
      yPrefix:        User specified prefix for Y coordinate
      ySuffix:        User specified suffix for Y coordinate
      yOverride:      If present, overrides the computed Y coordinate value.

      includeZ:       Indicates whether or not to include the Z coordinate of the tracked entity
      zPrefix:        User specified prefix for Z coordinate
      zSuffix:        User specified suffix for Z coordinate
      zOverride:      If present, overrides the computed Z coordinate value.

      includeI:       Indicates whether or not to include the I component of the tracked entity
                       Only meaningful if the tracked entity has a normal vector
      iPrefix:        User specified prefix for I coordinate
      iSuffix:        User specified suffix for I coordinate
      iOverride:      If present, overrides the computed I coordinate value.

      includeJ:       Indicates whether or not to include the J component of the tracked entity
                       Only meaningful if the tracked entity has a normal vector
      jPrefix:        User specified prefix for J coordinate
      jSuffix:        User specified suffix for J coordinate
      jOverride:      If present, overrides the computed J coordinate value.

      includeK:       Indicates whether or not to include the K component of the tracked entity
                       Only meaningful if the tracked entity has a normal vector
      kPrefix:        User specified prefix for K coordinate
      kSuffix:        User specified suffix for K coordinate
      kOverride:      If present, overrides the computed K coordinate value.

      includeLabel:   Indicates whether or not to include the Label of the tracked entity
      labelPrefix:    User specified prefix for Label
      labelSuffix:    User specified suffix for Label

      includeLevel:   Indicates whether or not to include the Level of the tracked entity
                       Only meaningful if the tracked entity is a measurement point
      levelPrefix:    User specified prefix for Level
      levelSuffix:    User specified suffix for Level
      coordinateSystemRef: References the CoordinateSystem to which the Coordinate Note relates.
      identifier:       The identifier of the Coordinate Note.
      category:         The category of the Coordinate Note.
      revision:         The revision of the Coordinate Note.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CoordinateNote : public Annotation3D
{
public:
     
    //! Default constructor
    CoordinateNote( );
     
    //! Constructs a CoordinateNote with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CoordinateNote( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CoordinateNote();

private:

	//! Assignment operator
	CoordinateNote& operator=( const CoordinateNote& iSrc );

	//! Copy constructor
	CoordinateNote( const CoordinateNote& original );
     
public:

	//! Get ZSuffix of this CoordinateNote
	plmxml_api::String GetZSuffix() const;

	//! Set ZSuffix of this CoordinateNote
	plmxml_api::Result SetZSuffix( const plmxml_api::String &s );
	
	//! Check if ZSuffix is set
	plmxml_api::logical HasZSuffix( ) const;
	
	//! Unset ZSuffix
	plmxml_api::Result UnsetZSuffix( );

	//! Get YPrefix of this CoordinateNote
	plmxml_api::String GetYPrefix() const;

	//! Set YPrefix of this CoordinateNote
	plmxml_api::Result SetYPrefix( const plmxml_api::String &s );
	
	//! Check if YPrefix is set
	plmxml_api::logical HasYPrefix( ) const;
	
	//! Unset YPrefix
	plmxml_api::Result UnsetYPrefix( );

	//! Get LevelSuffix of this CoordinateNote
	plmxml_api::String GetLevelSuffix() const;

	//! Set LevelSuffix of this CoordinateNote
	plmxml_api::Result SetLevelSuffix( const plmxml_api::String &s );
	
	//! Check if LevelSuffix is set
	plmxml_api::logical HasLevelSuffix( ) const;
	
	//! Unset LevelSuffix
	plmxml_api::Result UnsetLevelSuffix( );

	//! Set IncludeY
	plmxml_api::Result SetIncludeY( plmxml_api::logical arg );

	//! Get IncludeY
	plmxml_api::logical GetIncludeY() const;

	//! Check if IncludeY is set
	plmxml_api::logical HasIncludeY() const;

	//! Unset IncludeY
	plmxml_api::Result UnsetIncludeY();

	//! Get XPrefix of this CoordinateNote
	plmxml_api::String GetXPrefix() const;

	//! Set XPrefix of this CoordinateNote
	plmxml_api::Result SetXPrefix( const plmxml_api::String &s );
	
	//! Check if XPrefix is set
	plmxml_api::logical HasXPrefix( ) const;
	
	//! Unset XPrefix
	plmxml_api::Result UnsetXPrefix( );

	//! Set IncludeZ
	plmxml_api::Result SetIncludeZ( plmxml_api::logical arg );

	//! Get IncludeZ
	plmxml_api::logical GetIncludeZ() const;

	//! Check if IncludeZ is set
	plmxml_api::logical HasIncludeZ() const;

	//! Unset IncludeZ
	plmxml_api::Result UnsetIncludeZ();

	//! Set YOverride
	plmxml_api::Result SetYOverride( double arg );

     //! Get YOverride
	double GetYOverride() const;

	//! Check if YOverride is set
	plmxml_api::logical HasYOverride() const;

	//! Unset YOverride
	plmxml_api::Result UnsetYOverride();

	//! Set JOverride
	plmxml_api::Result SetJOverride( double arg );

     //! Get JOverride
	double GetJOverride() const;

	//! Check if JOverride is set
	plmxml_api::logical HasJOverride() const;

	//! Unset JOverride
	plmxml_api::Result UnsetJOverride();

	//! Set IncludeI
	plmxml_api::Result SetIncludeI( plmxml_api::logical arg );

	//! Get IncludeI
	plmxml_api::logical GetIncludeI() const;

	//! Check if IncludeI is set
	plmxml_api::logical HasIncludeI() const;

	//! Unset IncludeI
	plmxml_api::Result UnsetIncludeI();

	//! Get ZPrefix of this CoordinateNote
	plmxml_api::String GetZPrefix() const;

	//! Set ZPrefix of this CoordinateNote
	plmxml_api::Result SetZPrefix( const plmxml_api::String &s );
	
	//! Check if ZPrefix is set
	plmxml_api::logical HasZPrefix( ) const;
	
	//! Unset ZPrefix
	plmxml_api::Result UnsetZPrefix( );

	//! Set IncludeJ
	plmxml_api::Result SetIncludeJ( plmxml_api::logical arg );

	//! Get IncludeJ
	plmxml_api::logical GetIncludeJ() const;

	//! Check if IncludeJ is set
	plmxml_api::logical HasIncludeJ() const;

	//! Unset IncludeJ
	plmxml_api::Result UnsetIncludeJ();

	//! Get ISuffix of this CoordinateNote
	plmxml_api::String GetISuffix() const;

	//! Set ISuffix of this CoordinateNote
	plmxml_api::Result SetISuffix( const plmxml_api::String &s );
	
	//! Check if ISuffix is set
	plmxml_api::logical HasISuffix( ) const;
	
	//! Unset ISuffix
	plmxml_api::Result UnsetISuffix( );

	//! Get LabelSuffix of this CoordinateNote
	plmxml_api::String GetLabelSuffix() const;

	//! Set LabelSuffix of this CoordinateNote
	plmxml_api::Result SetLabelSuffix( const plmxml_api::String &s );
	
	//! Check if LabelSuffix is set
	plmxml_api::logical HasLabelSuffix( ) const;
	
	//! Unset LabelSuffix
	plmxml_api::Result UnsetLabelSuffix( );

	//! Set IncludeLabel
	plmxml_api::Result SetIncludeLabel( plmxml_api::logical arg );

	//! Get IncludeLabel
	plmxml_api::logical GetIncludeLabel() const;

	//! Check if IncludeLabel is set
	plmxml_api::logical HasIncludeLabel() const;

	//! Unset IncludeLabel
	plmxml_api::Result UnsetIncludeLabel();

	//! Set IncludeX
	plmxml_api::Result SetIncludeX( plmxml_api::logical arg );

	//! Get IncludeX
	plmxml_api::logical GetIncludeX() const;

	//! Check if IncludeX is set
	plmxml_api::logical HasIncludeX() const;

	//! Unset IncludeX
	plmxml_api::Result UnsetIncludeX();

	//! Get Category of this CoordinateNote
	plmxml_api::String GetCategory() const;

	//! Set Category of this CoordinateNote
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );

	//! Set XOverride
	plmxml_api::Result SetXOverride( double arg );

     //! Get XOverride
	double GetXOverride() const;

	//! Check if XOverride is set
	plmxml_api::logical HasXOverride() const;

	//! Unset XOverride
	plmxml_api::Result UnsetXOverride();

	//! Get JSuffix of this CoordinateNote
	plmxml_api::String GetJSuffix() const;

	//! Set JSuffix of this CoordinateNote
	plmxml_api::Result SetJSuffix( const plmxml_api::String &s );
	
	//! Check if JSuffix is set
	plmxml_api::logical HasJSuffix( ) const;
	
	//! Unset JSuffix
	plmxml_api::Result UnsetJSuffix( );

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Get KSuffix of this CoordinateNote
	plmxml_api::String GetKSuffix() const;

	//! Set KSuffix of this CoordinateNote
	plmxml_api::Result SetKSuffix( const plmxml_api::String &s );
	
	//! Check if KSuffix is set
	plmxml_api::logical HasKSuffix( ) const;
	
	//! Unset KSuffix
	plmxml_api::Result UnsetKSuffix( );

	//! Set ZOverride
	plmxml_api::Result SetZOverride( double arg );

     //! Get ZOverride
	double GetZOverride() const;

	//! Check if ZOverride is set
	plmxml_api::logical HasZOverride() const;

	//! Unset ZOverride
	plmxml_api::Result UnsetZOverride();

	//! Set TextBox
	plmxml_api::Result SetTextBox( plmxml_api::logical arg );

	//! Get TextBox
	plmxml_api::logical GetTextBox() const;

	//! Check if TextBox is set
	plmxml_api::logical HasTextBox() const;

	//! Unset TextBox
	plmxml_api::Result UnsetTextBox();

	//! Get LevelPrefix of this CoordinateNote
	plmxml_api::String GetLevelPrefix() const;

	//! Set LevelPrefix of this CoordinateNote
	plmxml_api::Result SetLevelPrefix( const plmxml_api::String &s );
	
	//! Check if LevelPrefix is set
	plmxml_api::logical HasLevelPrefix( ) const;
	
	//! Unset LevelPrefix
	plmxml_api::Result UnsetLevelPrefix( );

	//! Get LabelPrefix of this CoordinateNote
	plmxml_api::String GetLabelPrefix() const;

	//! Set LabelPrefix of this CoordinateNote
	plmxml_api::Result SetLabelPrefix( const plmxml_api::String &s );
	
	//! Check if LabelPrefix is set
	plmxml_api::logical HasLabelPrefix( ) const;
	
	//! Unset LabelPrefix
	plmxml_api::Result UnsetLabelPrefix( );

	//! Set IncludeLevel
	plmxml_api::Result SetIncludeLevel( plmxml_api::logical arg );

	//! Get IncludeLevel
	plmxml_api::logical GetIncludeLevel() const;

	//! Check if IncludeLevel is set
	plmxml_api::logical HasIncludeLevel() const;

	//! Unset IncludeLevel
	plmxml_api::Result UnsetIncludeLevel();

	//! Get CoordinateSystem URI as plmxml_api::String
	plmxml_api::String GetCoordinateSystemURI() const;

	//! Set CoordinateSystem URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCoordinateSystemURI( const plmxml_api::String& );
	
	//! Get the handle of CoordinateSystem URI. Does not resolve the URI.
	plmxml_api::Result GetCoordinateSystemURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of CoordinateSystem URI. URI string is unchanged.
	plmxml_api::Result SetCoordinateSystemURI( const plmxml_api::Handle& );
	
	//! Resolve CoordinateSystem URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCoordinateSystemURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset CoordinateSystem URI. Clears URI string and handle.
	plmxml_api::Result DeleteCoordinateSystemURI();
	
	//! Check if CoordinateSystem URI is set
	plmxml_api::logical HasCoordinateSystemURI( ) const;
	

	//! Get KPrefix of this CoordinateNote
	plmxml_api::String GetKPrefix() const;

	//! Set KPrefix of this CoordinateNote
	plmxml_api::Result SetKPrefix( const plmxml_api::String &s );
	
	//! Check if KPrefix is set
	plmxml_api::logical HasKPrefix( ) const;
	
	//! Unset KPrefix
	plmxml_api::Result UnsetKPrefix( );

	//! Get JPrefix of this CoordinateNote
	plmxml_api::String GetJPrefix() const;

	//! Set JPrefix of this CoordinateNote
	plmxml_api::Result SetJPrefix( const plmxml_api::String &s );
	
	//! Check if JPrefix is set
	plmxml_api::logical HasJPrefix( ) const;
	
	//! Unset JPrefix
	plmxml_api::Result UnsetJPrefix( );

	//! Get IPrefix of this CoordinateNote
	plmxml_api::String GetIPrefix() const;

	//! Set IPrefix of this CoordinateNote
	plmxml_api::Result SetIPrefix( const plmxml_api::String &s );
	
	//! Check if IPrefix is set
	plmxml_api::logical HasIPrefix( ) const;
	
	//! Unset IPrefix
	plmxml_api::Result UnsetIPrefix( );

	//! Set IOverride
	plmxml_api::Result SetIOverride( double arg );

     //! Get IOverride
	double GetIOverride() const;

	//! Check if IOverride is set
	plmxml_api::logical HasIOverride() const;

	//! Unset IOverride
	plmxml_api::Result UnsetIOverride();

	//! Get YSuffix of this CoordinateNote
	plmxml_api::String GetYSuffix() const;

	//! Set YSuffix of this CoordinateNote
	plmxml_api::Result SetYSuffix( const plmxml_api::String &s );
	
	//! Check if YSuffix is set
	plmxml_api::logical HasYSuffix( ) const;
	
	//! Unset YSuffix
	plmxml_api::Result UnsetYSuffix( );

	//! Set KOverride
	plmxml_api::Result SetKOverride( double arg );

     //! Get KOverride
	double GetKOverride() const;

	//! Check if KOverride is set
	plmxml_api::logical HasKOverride() const;

	//! Unset KOverride
	plmxml_api::Result UnsetKOverride();

	//! Set IncludeK
	plmxml_api::Result SetIncludeK( plmxml_api::logical arg );

	//! Get IncludeK
	plmxml_api::logical GetIncludeK() const;

	//! Check if IncludeK is set
	plmxml_api::logical HasIncludeK() const;

	//! Unset IncludeK
	plmxml_api::Result UnsetIncludeK();

	//! Get XSuffix of this CoordinateNote
	plmxml_api::String GetXSuffix() const;

	//! Set XSuffix of this CoordinateNote
	plmxml_api::Result SetXSuffix( const plmxml_api::String &s );
	
	//! Check if XSuffix is set
	plmxml_api::logical HasXSuffix( ) const;
	
	//! Unset XSuffix
	plmxml_api::Result UnsetXSuffix( );

	//! Get Revision of this CoordinateNote
	plmxml_api::String GetRevision() const;

	//! Set Revision of this CoordinateNote
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

	//! Get Identifier of this CoordinateNote
	plmxml_api::String GetIdentifier() const;

	//! Set Identifier of this CoordinateNote
	plmxml_api::Result SetIdentifier( const plmxml_api::String &s );
	
	//! Check if Identifier is set
	plmxml_api::logical HasIdentifier( ) const;
	
	//! Unset Identifier
	plmxml_api::Result UnsetIdentifier( );
 
// <PLMXML_UserCode type="functionHeaderCoordinateNote" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCoordinateNote;


////////////////////////////////////////////////////////////////////////////////////
//! CoordinateNoteDisplay class
/*!
\verbatim

      CoordinateNote Display
      
      Attributes:
      
      precision:        number of decimal places
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CoordinateNoteDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    CoordinateNoteDisplay( );
     
    //! Constructs a CoordinateNoteDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CoordinateNoteDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CoordinateNoteDisplay();

private:

	//! Assignment operator
	CoordinateNoteDisplay& operator=( const CoordinateNoteDisplay& iSrc );

	//! Copy constructor
	CoordinateNoteDisplay( const CoordinateNoteDisplay& original );
     
public:

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();
 
// <PLMXML_UserCode type="functionHeaderCoordinateNoteDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCoordinateNoteDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DAttributeReference class
/*!
\verbatim

      This element gives the name of an Attribute and optionally a URI
      reference to it. The name is the element content.
      
      Attributes:
      
      attributeRef:     reference to the attribute.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DAttributeReference : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DAttributeReference( );
     
    //! Constructs a Ann3DAttributeReference with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DAttributeReference( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DAttributeReference();

private:

	//! Assignment operator
	Ann3DAttributeReference& operator=( const Ann3DAttributeReference& iSrc );

	//! Copy constructor
	Ann3DAttributeReference( const Ann3DAttributeReference& original );
     
public:

	//! Get Attribute URI as plmxml_api::String
	plmxml_api::String GetAttributeURI() const;

	//! Set Attribute URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAttributeURI( const plmxml_api::String& );
	
	//! Get the handle of Attribute URI. Does not resolve the URI.
	plmxml_api::Result GetAttributeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Attribute URI. URI string is unchanged.
	plmxml_api::Result SetAttributeURI( const plmxml_api::Handle& );
	
	//! Resolve Attribute URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAttributeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Attribute URI. Clears URI string and handle.
	plmxml_api::Result DeleteAttributeURI();
	
	//! Check if Attribute URI is set
	plmxml_api::logical HasAttributeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderAnn3DAttributeReference" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DAttributeReference;


////////////////////////////////////////////////////////////////////////////////////
//! AttributeNote class
/*!
\verbatim

      AttributeNote Annotation.

      Attributes:
      
      standard:       standard used for the AttributeNote
      
      Elements:
        
      AttributeName:  Attribute name. The values of the named attributes 
                      are used to construct the AttributeNote text.
      AttributeReference: Attribute name and reference. This is similar to
                      AttributeName above, but allows a URI reference to the
                      actual attribute. Do not use AttributeName elements and
                      AttributeReference elements at the same time.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API AttributeNote : public Annotation3D
{
public:
     
    //! Default constructor
    AttributeNote( );
     
    //! Constructs a AttributeNote with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AttributeNote( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AttributeNote();

private:

	//! Assignment operator
	AttributeNote& operator=( const AttributeNote& iSrc );

	//! Copy constructor
	AttributeNote( const AttributeNote& original );
     
public:

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Add AttributeName child element to this AttributeNote. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StringField *AddAttributeName();
     
	//! Add 'arg' as AttributeName child element to this AttributeNote.
	plmxml_api::Result AddAttributeName( StringField *arg );

	//! Detach and delete all AttributeName child elements.
	void DeleteAttributeNames();
     
	//! Get number of AttributeName child elements.
	int NumberOfAttributeNames() const;
     
	//! Get i'th AttributeName child element.
	StringField *GetAttributeName( int i ) const;
     
	//! Get all AttributeName child element as an array
	void GetAttributeNames( plmxml_api::Array<StringField*> &array ) const;
	     
	//! Detach and delete i'th AttributeName child element
	void DeleteAttributeName( int i );
     
	//! Detach and delete 'arg' if it's one of the AttributeName child elements
	void DeleteAttributeName( StringField *arg );

	//! Add AttributeReference child element to this AttributeNote. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DAttributeReference *AddAttributeReference();
     
	//! Add 'arg' as AttributeReference child element to this AttributeNote.
	plmxml_api::Result AddAttributeReference( Ann3DAttributeReference *arg );

	//! Detach and delete all AttributeReference child elements.
	void DeleteAttributeReferences();
     
	//! Get number of AttributeReference child elements.
	int NumberOfAttributeReferences() const;
     
	//! Get i'th AttributeReference child element.
	Ann3DAttributeReference *GetAttributeReference( int i ) const;
     
	//! Get all AttributeReference child element as an array
	void GetAttributeReferences( plmxml_api::Array<Ann3DAttributeReference*> &array ) const;
	     
	//! Detach and delete i'th AttributeReference child element
	void DeleteAttributeReference( int i );
     
	//! Detach and delete 'arg' if it's one of the AttributeReference child elements
	void DeleteAttributeReference( Ann3DAttributeReference *arg );
 
// <PLMXML_UserCode type="functionHeaderAttributeNote" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAttributeNote;


////////////////////////////////////////////////////////////////////////////////////
//! AttributeNoteDisplay class
/*!
\verbatim

      AttributeNote Display
      
      Attributes:

      includeLabels:  Indicates whether or not the labels for the attributes are 
                      included in the note text
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API AttributeNoteDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    AttributeNoteDisplay( );
     
    //! Constructs a AttributeNoteDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AttributeNoteDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AttributeNoteDisplay();

private:

	//! Assignment operator
	AttributeNoteDisplay& operator=( const AttributeNoteDisplay& iSrc );

	//! Copy constructor
	AttributeNoteDisplay( const AttributeNoteDisplay& original );
     
public:

	//! Set IncludeLabels
	plmxml_api::Result SetIncludeLabels( plmxml_api::logical arg );

	//! Get IncludeLabels
	plmxml_api::logical GetIncludeLabels() const;

	//! Check if IncludeLabels is set
	plmxml_api::logical HasIncludeLabels() const;

	//! Unset IncludeLabels
	plmxml_api::Result UnsetIncludeLabels();
 
// <PLMXML_UserCode type="functionHeaderAttributeNoteDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAttributeNoteDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! BundleDressingNote class
/*!
\verbatim

      BundleDressingNote Annotation.

      Attributes:
      
      standard:        Standard used in for the Bundle/Dressing Note
      type:            Indicates whether the Bundle/Dressing Note is for a Bundle or a Dressing
      locationOnCurve: The location (parameter) along the wirepath where the leader attaches
                       for leader directed Bundle/Dressing Notes
      
      Elements:
        
      AttributeName:   A list of bundle or dressing attribute names. The values of the named
                       attributes are used to construct the BundleDressingNote text.
      AttributeReference: Attribute name and reference. This is similar to
                      AttributeName above, but allows a URI reference to the
                      actual attribute. Do not use AttributeName elements and
                      AttributeReference elements at the same time.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API BundleDressingNote : public Annotation3D
{
public:
     
    //! Default constructor
    BundleDressingNote( );
     
    //! Constructs a BundleDressingNote with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BundleDressingNote( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BundleDressingNote();

private:

	//! Assignment operator
	BundleDressingNote& operator=( const BundleDressingNote& iSrc );

	//! Copy constructor
	BundleDressingNote( const BundleDressingNote& original );
     
public:

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DBundleOrDressingNote& arg );

	//! Get Type
	eAnn3DBundleOrDressingNote GetType() const;

	//! Set LocationOnCurve
	plmxml_api::Result SetLocationOnCurve( double arg );

     //! Get LocationOnCurve
	double GetLocationOnCurve() const;

	//! Check if LocationOnCurve is set
	plmxml_api::logical HasLocationOnCurve() const;

	//! Unset LocationOnCurve
	plmxml_api::Result UnsetLocationOnCurve();

	//! Add AttributeName child element to this BundleDressingNote. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StringField *AddAttributeName();
     
	//! Add 'arg' as AttributeName child element to this BundleDressingNote.
	plmxml_api::Result AddAttributeName( StringField *arg );

	//! Detach and delete all AttributeName child elements.
	void DeleteAttributeNames();
     
	//! Get number of AttributeName child elements.
	int NumberOfAttributeNames() const;
     
	//! Get i'th AttributeName child element.
	StringField *GetAttributeName( int i ) const;
     
	//! Get all AttributeName child element as an array
	void GetAttributeNames( plmxml_api::Array<StringField*> &array ) const;
	     
	//! Detach and delete i'th AttributeName child element
	void DeleteAttributeName( int i );
     
	//! Detach and delete 'arg' if it's one of the AttributeName child elements
	void DeleteAttributeName( StringField *arg );

	//! Add AttributeReference child element to this BundleDressingNote. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DAttributeReference *AddAttributeReference();
     
	//! Add 'arg' as AttributeReference child element to this BundleDressingNote.
	plmxml_api::Result AddAttributeReference( Ann3DAttributeReference *arg );

	//! Detach and delete all AttributeReference child elements.
	void DeleteAttributeReferences();
     
	//! Get number of AttributeReference child elements.
	int NumberOfAttributeReferences() const;
     
	//! Get i'th AttributeReference child element.
	Ann3DAttributeReference *GetAttributeReference( int i ) const;
     
	//! Get all AttributeReference child element as an array
	void GetAttributeReferences( plmxml_api::Array<Ann3DAttributeReference*> &array ) const;
	     
	//! Detach and delete i'th AttributeReference child element
	void DeleteAttributeReference( int i );
     
	//! Detach and delete 'arg' if it's one of the AttributeReference child elements
	void DeleteAttributeReference( Ann3DAttributeReference *arg );
 
// <PLMXML_UserCode type="functionHeaderBundleDressingNote" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassBundleDressingNote;


////////////////////////////////////////////////////////////////////////////////////
//! BundleDressingNoteDisplay class
/*!
\verbatim

      BundleDressingNoteDisplay.
      
      Attributes:

      precision:        number of decimal places
      includeLabels:    Indicates whether or not the labels for the attributes are
                        included in the note text
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API BundleDressingNoteDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    BundleDressingNoteDisplay( );
     
    //! Constructs a BundleDressingNoteDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BundleDressingNoteDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BundleDressingNoteDisplay();

private:

	//! Assignment operator
	BundleDressingNoteDisplay& operator=( const BundleDressingNoteDisplay& iSrc );

	//! Copy constructor
	BundleDressingNoteDisplay( const BundleDressingNoteDisplay& original );
     
public:

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set IncludeLabels
	plmxml_api::Result SetIncludeLabels( plmxml_api::logical arg );

	//! Get IncludeLabels
	plmxml_api::logical GetIncludeLabels() const;

	//! Check if IncludeLabels is set
	plmxml_api::logical HasIncludeLabels() const;

	//! Unset IncludeLabels
	plmxml_api::Result UnsetIncludeLabels();
 
// <PLMXML_UserCode type="functionHeaderBundleDressingNoteDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassBundleDressingNoteDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCPSPlaneCutter class
/*!
\verbatim

      PlaneCutter.

      Attributes:
        
      materialSide:    Defines whether or not the normal for the cutting plane indicates
                       the side from which to remove the material. True means the normal
                       for the plane indicates the side from which to remove material,
                       false means the opposite of the plane normal is the side from
                       which to remove material. 
                       
      Elements:
        
      Plane:           The cutting plane.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCPSPlaneCutter : public IdObject
{
public:
     
    //! Default constructor
    Ann3DCPSPlaneCutter( );
     
    //! Constructs a Ann3DCPSPlaneCutter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCPSPlaneCutter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCPSPlaneCutter();

private:

	//! Assignment operator
	Ann3DCPSPlaneCutter& operator=( const Ann3DCPSPlaneCutter& iSrc );

	//! Copy constructor
	Ann3DCPSPlaneCutter( const Ann3DCPSPlaneCutter& original );
     
public:

	//! Set MaterialSide
	plmxml_api::Result SetMaterialSide( plmxml_api::logical arg );

	//! Get MaterialSide
	plmxml_api::logical GetMaterialSide() const;

	//! Check if MaterialSide is set
	plmxml_api::logical HasMaterialSide() const;

	//! Unset MaterialSide
	plmxml_api::Result UnsetMaterialSide();

	//! Add Plane child element to this Ann3DCPSPlaneCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddPlane();
     
	//! Set Plane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPlane( Plane *arg );
     
	//! Get Plane child element of this Ann3DCPSPlaneCutter.
	Plane *GetPlane() const;
     
	//! Detach and delete Plane child element tree from this Ann3DCPSPlaneCutter.
	void DeletePlane();
 
// <PLMXML_UserCode type="functionHeaderAnn3DCPSPlaneCutter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCPSPlaneCutter;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCPSOpenPolylineCutter class
/*!
\verbatim

      OpenPolylineCutter.
      
      This element is deprecated - use Ann3DCPSOpenCutterType in preference.

      Attributes:
       
      materialSide:    Indicates which side of the cut contains material:
                       First, take the vector cross product of the constraint plane
                       and the vector formed from the first line segment of the polyline.
                       materialSide of true indicates this cross product shows the side
                       from which material is removed. materialSide of false indicates
                       the opposite side has the material removed. 

      Elements:
        
      ConstraintPlane: Equation defining the constraint plane
      Polyline:        Data for the points selected to define the polyline cutter
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCPSOpenPolylineCutter : public IdObject
{
public:
     
    //! Default constructor
    Ann3DCPSOpenPolylineCutter( );
     
    //! Constructs a Ann3DCPSOpenPolylineCutter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCPSOpenPolylineCutter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCPSOpenPolylineCutter();

private:

	//! Assignment operator
	Ann3DCPSOpenPolylineCutter& operator=( const Ann3DCPSOpenPolylineCutter& iSrc );

	//! Copy constructor
	Ann3DCPSOpenPolylineCutter( const Ann3DCPSOpenPolylineCutter& original );
     
public:

	//! Set MaterialSide
	plmxml_api::Result SetMaterialSide( plmxml_api::logical arg );

	//! Get MaterialSide
	plmxml_api::logical GetMaterialSide() const;

	//! Check if MaterialSide is set
	plmxml_api::logical HasMaterialSide() const;

	//! Unset MaterialSide
	plmxml_api::Result UnsetMaterialSide();

	//! Add ConstraintPlane child element to this Ann3DCPSOpenPolylineCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddConstraintPlane();
     
	//! Set ConstraintPlane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintPlane( Plane *arg );
     
	//! Get ConstraintPlane child element of this Ann3DCPSOpenPolylineCutter.
	Plane *GetConstraintPlane() const;
     
	//! Detach and delete ConstraintPlane child element tree from this Ann3DCPSOpenPolylineCutter.
	void DeleteConstraintPlane();

	//! Add Polyline child element to this Ann3DCPSOpenPolylineCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	PolyLine *AddPolyline();
     
	//! Set Polyline child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPolyline( PolyLine *arg );
     
	//! Get Polyline child element of this Ann3DCPSOpenPolylineCutter.
	PolyLine *GetPolyline() const;
     
	//! Detach and delete Polyline child element tree from this Ann3DCPSOpenPolylineCutter.
	void DeletePolyline();
 
// <PLMXML_UserCode type="functionHeaderAnn3DCPSOpenPolylineCutter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCPSOpenPolylineCutter;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCPSClosedPolylineCutter class
/*!
\verbatim

      ClosedPolylineCutter.
      
      This element is deprecated - use Ann3DCPSClosedCutterType in preference.

      Attributes:
      
      materialSide:    Indicates which side of the cut contains material -
                       materialSide of true indicates this is a "Cut" (where the shape
                       represented by the closed polyline curve is removed from the
                       original Part) and a value of false indicates this is an
                       "Intersect" (where only the material from the original Part that
                       intersects with the volume defined by the cutting plane symbol is
                       retained). 
                       
      aftThroughAll:   Indicates whether or not the extrusion in the Aft direction is
                         "Through All"
      aftDistance:     The distance the extrude is performed in the Aft distance
      foreThroughAll:  Indicates whether or not the extrusion in the Fore direction is
                         "Through All"
      foreDistance:    The distance the extrude is performed in the Fore distance
      
      Elements:
        
      ConstraintPlane: Equation defining the constraint plane
      Polyline:        Data for the points selected to define the polyline cutter
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCPSClosedPolylineCutter : public IdObject
{
public:
     
    //! Default constructor
    Ann3DCPSClosedPolylineCutter( );
     
    //! Constructs a Ann3DCPSClosedPolylineCutter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCPSClosedPolylineCutter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCPSClosedPolylineCutter();

private:

	//! Assignment operator
	Ann3DCPSClosedPolylineCutter& operator=( const Ann3DCPSClosedPolylineCutter& iSrc );

	//! Copy constructor
	Ann3DCPSClosedPolylineCutter( const Ann3DCPSClosedPolylineCutter& original );
     
public:

	//! Set MaterialSide
	plmxml_api::Result SetMaterialSide( plmxml_api::logical arg );

	//! Get MaterialSide
	plmxml_api::logical GetMaterialSide() const;

	//! Check if MaterialSide is set
	plmxml_api::logical HasMaterialSide() const;

	//! Unset MaterialSide
	plmxml_api::Result UnsetMaterialSide();

	//! Set AftDistance
	plmxml_api::Result SetAftDistance( double arg );

     //! Get AftDistance
	double GetAftDistance() const;

	//! Check if AftDistance is set
	plmxml_api::logical HasAftDistance() const;

	//! Unset AftDistance
	plmxml_api::Result UnsetAftDistance();

	//! Set ForeDistance
	plmxml_api::Result SetForeDistance( double arg );

     //! Get ForeDistance
	double GetForeDistance() const;

	//! Check if ForeDistance is set
	plmxml_api::logical HasForeDistance() const;

	//! Unset ForeDistance
	plmxml_api::Result UnsetForeDistance();

	//! Set AftThroughAll
	plmxml_api::Result SetAftThroughAll( plmxml_api::logical arg );

	//! Get AftThroughAll
	plmxml_api::logical GetAftThroughAll() const;

	//! Check if AftThroughAll is set
	plmxml_api::logical HasAftThroughAll() const;

	//! Unset AftThroughAll
	plmxml_api::Result UnsetAftThroughAll();

	//! Set ForeThroughAll
	plmxml_api::Result SetForeThroughAll( plmxml_api::logical arg );

	//! Get ForeThroughAll
	plmxml_api::logical GetForeThroughAll() const;

	//! Check if ForeThroughAll is set
	plmxml_api::logical HasForeThroughAll() const;

	//! Unset ForeThroughAll
	plmxml_api::Result UnsetForeThroughAll();

	//! Add ConstraintPlane child element to this Ann3DCPSClosedPolylineCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddConstraintPlane();
     
	//! Set ConstraintPlane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintPlane( Plane *arg );
     
	//! Get ConstraintPlane child element of this Ann3DCPSClosedPolylineCutter.
	Plane *GetConstraintPlane() const;
     
	//! Detach and delete ConstraintPlane child element tree from this Ann3DCPSClosedPolylineCutter.
	void DeleteConstraintPlane();

	//! Add Polyline child element to this Ann3DCPSClosedPolylineCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	PolyLine *AddPolyline();
     
	//! Set Polyline child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPolyline( PolyLine *arg );
     
	//! Get Polyline child element of this Ann3DCPSClosedPolylineCutter.
	PolyLine *GetPolyline() const;
     
	//! Detach and delete Polyline child element tree from this Ann3DCPSClosedPolylineCutter.
	void DeletePolyline();
 
// <PLMXML_UserCode type="functionHeaderAnn3DCPSClosedPolylineCutter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCPSClosedPolylineCutter;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCPSOpenCutter class
/*!
\verbatim

      Open Cutter.

      Attributes:
       
      materialSide:    Indicates which side of the cut contains material:
                       First, take the vector cross product of the constraint plane normal
                       and the tangent at the start of the curve. materialSide of true 
                       indicates this cross product shows the side from which material is 
                       removed. materialSide of false indicates the opposite side has 
                       the material removed.
                       
      curveRef:        reference to the curve which defines the cut. This may be a 
                       CompositeCurve.

      Elements:
        
      ConstraintPlane: Plane in which the curve lies.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCPSOpenCutter : public IdObject
{
public:
     
    //! Default constructor
    Ann3DCPSOpenCutter( );
     
    //! Constructs a Ann3DCPSOpenCutter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCPSOpenCutter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCPSOpenCutter();

private:

	//! Assignment operator
	Ann3DCPSOpenCutter& operator=( const Ann3DCPSOpenCutter& iSrc );

	//! Copy constructor
	Ann3DCPSOpenCutter( const Ann3DCPSOpenCutter& original );
     
public:

	//! Get Curve URI as plmxml_api::String
	plmxml_api::String GetCurveURI() const;

	//! Set Curve URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCurveURI( const plmxml_api::String& );
	
	//! Get the handle of Curve URI. Does not resolve the URI.
	plmxml_api::Result GetCurveURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Curve URI. URI string is unchanged.
	plmxml_api::Result SetCurveURI( const plmxml_api::Handle& );
	
	//! Resolve Curve URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCurveURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Curve URI. Clears URI string and handle.
	plmxml_api::Result DeleteCurveURI();
	
	//! Check if Curve URI is set
	plmxml_api::logical HasCurveURI( ) const;
	

	//! Set MaterialSide
	plmxml_api::Result SetMaterialSide( plmxml_api::logical arg );

	//! Get MaterialSide
	plmxml_api::logical GetMaterialSide() const;

	//! Check if MaterialSide is set
	plmxml_api::logical HasMaterialSide() const;

	//! Unset MaterialSide
	plmxml_api::Result UnsetMaterialSide();

	//! Add ConstraintPlane child element to this Ann3DCPSOpenCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddConstraintPlane();
     
	//! Set ConstraintPlane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintPlane( Plane *arg );
     
	//! Get ConstraintPlane child element of this Ann3DCPSOpenCutter.
	Plane *GetConstraintPlane() const;
     
	//! Detach and delete ConstraintPlane child element tree from this Ann3DCPSOpenCutter.
	void DeleteConstraintPlane();
 
// <PLMXML_UserCode type="functionHeaderAnn3DCPSOpenCutter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCPSOpenCutter;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCPSClosedCutter class
/*!
\verbatim

      Closed Cutter.

      Attributes:
      
      materialSide:    Indicates which side of the cut contains material -
                       materialSide of true indicates this is a "Cut" (where the shape
                       represented by the closed curve is removed from the
                       original Part) and a value of false indicates this is an
                       "Intersect" (where only the material from the original Part that
                       intersects with the volume defined by the cutting plane symbol is
                       retained). 
                       
                       The constraint plane normal defines the "fore" direction; the 
                       opposite is the "aft" direction:
                       
      aftThroughAll:   Indicates whether or not the extrusion in the Aft direction is
                         "Through All"
      aftDistance:     The distance the extrude is performed in the Aft distance, in metres.
      foreThroughAll:  Indicates whether or not the extrusion in the Fore direction is
                         "Through All"
      foreDistance:    The distance the extrude is performed in the Fore distance, in metres.
      
      curveRef:        reference to the closed curve which defines the cut. This may be a 
                       CompositeCurve.
      
      Elements:
        
      ConstraintPlane: Plane in which the curve lies.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCPSClosedCutter : public IdObject
{
public:
     
    //! Default constructor
    Ann3DCPSClosedCutter( );
     
    //! Constructs a Ann3DCPSClosedCutter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCPSClosedCutter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCPSClosedCutter();

private:

	//! Assignment operator
	Ann3DCPSClosedCutter& operator=( const Ann3DCPSClosedCutter& iSrc );

	//! Copy constructor
	Ann3DCPSClosedCutter( const Ann3DCPSClosedCutter& original );
     
public:

	//! Set ForeDistance
	plmxml_api::Result SetForeDistance( double arg );

     //! Get ForeDistance
	double GetForeDistance() const;

	//! Check if ForeDistance is set
	plmxml_api::logical HasForeDistance() const;

	//! Unset ForeDistance
	plmxml_api::Result UnsetForeDistance();

	//! Set AftDistance
	plmxml_api::Result SetAftDistance( double arg );

     //! Get AftDistance
	double GetAftDistance() const;

	//! Check if AftDistance is set
	plmxml_api::logical HasAftDistance() const;

	//! Unset AftDistance
	plmxml_api::Result UnsetAftDistance();

	//! Set MaterialSide
	plmxml_api::Result SetMaterialSide( plmxml_api::logical arg );

	//! Get MaterialSide
	plmxml_api::logical GetMaterialSide() const;

	//! Check if MaterialSide is set
	plmxml_api::logical HasMaterialSide() const;

	//! Unset MaterialSide
	plmxml_api::Result UnsetMaterialSide();

	//! Set ForeThroughAll
	plmxml_api::Result SetForeThroughAll( plmxml_api::logical arg );

	//! Get ForeThroughAll
	plmxml_api::logical GetForeThroughAll() const;

	//! Check if ForeThroughAll is set
	plmxml_api::logical HasForeThroughAll() const;

	//! Unset ForeThroughAll
	plmxml_api::Result UnsetForeThroughAll();

	//! Set AftThroughAll
	plmxml_api::Result SetAftThroughAll( plmxml_api::logical arg );

	//! Get AftThroughAll
	plmxml_api::logical GetAftThroughAll() const;

	//! Check if AftThroughAll is set
	plmxml_api::logical HasAftThroughAll() const;

	//! Unset AftThroughAll
	plmxml_api::Result UnsetAftThroughAll();

	//! Get Curve URI as plmxml_api::String
	plmxml_api::String GetCurveURI() const;

	//! Set Curve URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCurveURI( const plmxml_api::String& );
	
	//! Get the handle of Curve URI. Does not resolve the URI.
	plmxml_api::Result GetCurveURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Curve URI. URI string is unchanged.
	plmxml_api::Result SetCurveURI( const plmxml_api::Handle& );
	
	//! Resolve Curve URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCurveURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Curve URI. Clears URI string and handle.
	plmxml_api::Result DeleteCurveURI();
	
	//! Check if Curve URI is set
	plmxml_api::logical HasCurveURI( ) const;
	

	//! Add ConstraintPlane child element to this Ann3DCPSClosedCutter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddConstraintPlane();
     
	//! Set ConstraintPlane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintPlane( Plane *arg );
     
	//! Get ConstraintPlane child element of this Ann3DCPSClosedCutter.
	Plane *GetConstraintPlane() const;
     
	//! Detach and delete ConstraintPlane child element tree from this Ann3DCPSClosedCutter.
	void DeleteConstraintPlane();
 
// <PLMXML_UserCode type="functionHeaderAnn3DCPSClosedCutter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCPSClosedCutter;


////////////////////////////////////////////////////////////////////////////////////
//! CuttingPlaneSymbol class
/*!
\verbatim

      CuttingPlaneSymbol Annotation.

      Attributes:

      standard:         The standard used for the Cutting Plane Symbol.

      Elements:

      CpsLetters:       The name displayed with the Cutting Plane Symbol in the
                        graphics region. This is not the system ID for the
                        symbol.

      One (usually only one) of the following:

      PlaneCutter:      Data for a Plane cutter. A CuttingPlaneSymbol for a
                        parallel planes lightweight Section has 2 PlaneCutters.
                        One for a box lightweight Section has 6.
      OpenPolylineCutter: Data for an open polyline cutter
      ClosedPolylineCutter: Data for a closed polyline cutter
      OpenCutter:       Data for an open polyline cutter
      ClosedCutter:     Data for a closed polyline cutter
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CuttingPlaneSymbol : public Annotation3D
{
public:
     
    //! Default constructor
    CuttingPlaneSymbol( );
     
    //! Constructs a CuttingPlaneSymbol with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CuttingPlaneSymbol( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CuttingPlaneSymbol();

private:

	//! Assignment operator
	CuttingPlaneSymbol& operator=( const CuttingPlaneSymbol& iSrc );

	//! Copy constructor
	CuttingPlaneSymbol( const CuttingPlaneSymbol& original );
     
public:

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DCuttingPlaneSymbolStandardEnum& arg );

	//! Get Standard
	eAnn3DCuttingPlaneSymbolStandardEnum GetStandard() const;

	//! Add CpsLetters child element to this CuttingPlaneSymbol. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddCpsLetters();
     
	//! Set CpsLetters child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCpsLetters( Ann3DText *arg );
     
	//! Get CpsLetters child element of this CuttingPlaneSymbol.
	Ann3DText *GetCpsLetters() const;
     
	//! Detach and delete CpsLetters child element tree from this CuttingPlaneSymbol.
	void DeleteCpsLetters();

	//! Add PlaneCutter child element to this CuttingPlaneSymbol. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCPSPlaneCutter *AddPlaneCutter();
     
	//! Add 'arg' as PlaneCutter child element to this CuttingPlaneSymbol.
	plmxml_api::Result AddPlaneCutter( Ann3DCPSPlaneCutter *arg );

	//! Detach and delete all PlaneCutter child elements.
	void DeletePlaneCutters();
     
	//! Get number of PlaneCutter child elements.
	int NumberOfPlaneCutters() const;
     
	//! Get i'th PlaneCutter child element.
	Ann3DCPSPlaneCutter *GetPlaneCutter( int i ) const;
     
	//! Get all PlaneCutter child element as an array
	void GetPlaneCutters( plmxml_api::Array<Ann3DCPSPlaneCutter*> &array ) const;
	     
	//! Detach and delete i'th PlaneCutter child element
	void DeletePlaneCutter( int i );
     
	//! Detach and delete 'arg' if it's one of the PlaneCutter child elements
	void DeletePlaneCutter( Ann3DCPSPlaneCutter *arg );

	//! Add OpenPolylineCutter child element to this CuttingPlaneSymbol. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCPSOpenPolylineCutter *AddOpenPolylineCutter();
     
	//! Set OpenPolylineCutter child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOpenPolylineCutter( Ann3DCPSOpenPolylineCutter *arg );
     
	//! Get OpenPolylineCutter child element of this CuttingPlaneSymbol.
	Ann3DCPSOpenPolylineCutter *GetOpenPolylineCutter() const;
     
	//! Detach and delete OpenPolylineCutter child element tree from this CuttingPlaneSymbol.
	void DeleteOpenPolylineCutter();

	//! Add ClosedPolylineCutter child element to this CuttingPlaneSymbol. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCPSClosedPolylineCutter *AddClosedPolylineCutter();
     
	//! Set ClosedPolylineCutter child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClosedPolylineCutter( Ann3DCPSClosedPolylineCutter *arg );
     
	//! Get ClosedPolylineCutter child element of this CuttingPlaneSymbol.
	Ann3DCPSClosedPolylineCutter *GetClosedPolylineCutter() const;
     
	//! Detach and delete ClosedPolylineCutter child element tree from this CuttingPlaneSymbol.
	void DeleteClosedPolylineCutter();

	//! Add OpenCutter child element to this CuttingPlaneSymbol. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCPSOpenCutter *AddOpenCutter();
     
	//! Set OpenCutter child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOpenCutter( Ann3DCPSOpenCutter *arg );
     
	//! Get OpenCutter child element of this CuttingPlaneSymbol.
	Ann3DCPSOpenCutter *GetOpenCutter() const;
     
	//! Detach and delete OpenCutter child element tree from this CuttingPlaneSymbol.
	void DeleteOpenCutter();

	//! Add ClosedCutter child element to this CuttingPlaneSymbol. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCPSClosedCutter *AddClosedCutter();
     
	//! Set ClosedCutter child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClosedCutter( Ann3DCPSClosedCutter *arg );
     
	//! Get ClosedCutter child element of this CuttingPlaneSymbol.
	Ann3DCPSClosedCutter *GetClosedCutter() const;
     
	//! Detach and delete ClosedCutter child element tree from this CuttingPlaneSymbol.
	void DeleteClosedCutter();
 
// <PLMXML_UserCode type="functionHeaderCuttingPlaneSymbol" >
     // TODO: Add extra function headers within this block
	//! Set PlaneCutter child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPlaneCutter( Ann3DCPSPlaneCutter *arg );
	//! Get PlaneCutter child element of this CuttingPlaneSymbol.
	Ann3DCPSPlaneCutter *GetPlaneCutter( ) const;
	//! Detach and delete PlaneCutter child element tree from this CuttingPlaneSymbol.
	void DeletePlaneCutter( );
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCuttingPlaneSymbol;


////////////////////////////////////////////////////////////////////////////////////
//! CuttingPlaneSymbolDisplay class
/*!
\verbatim

      CuttingPlaneSymbolDisplay

      Attributes:

      twoArrows:        Indicates whether one or two arrows are used in the
                        cutting plane symbol.
      shadedPlane:      Whether the interior of the outline of a plane cutter is
                        shaded.
      planeColour:      The colour of the plane cutters.
      textPlaneOrientation: Whether the text is parallel or perpendicular to the
                        plane of the arrow. This overrides the orientation
                        dictated by the standard attribute on the corresponding
                        CuttingPlaneSymbol.
      lineStyle:        The style of the lines in the CuttingPlaneSymbol.
      arrowPlacement1:  The position of the first arrow on the outline of a
                        plane cutter.
      arrowPlacement2:  The position of the second arrow, if there is one, on
                        the outline of a plane cutter.
      arrowTowardsCutter: Whether the arrow is directed towards or away from the
                        cutting surface. If unspecified, the direction is
                        determined by the standard.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CuttingPlaneSymbolDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    CuttingPlaneSymbolDisplay( );
     
    //! Constructs a CuttingPlaneSymbolDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CuttingPlaneSymbolDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CuttingPlaneSymbolDisplay();

private:

	//! Assignment operator
	CuttingPlaneSymbolDisplay& operator=( const CuttingPlaneSymbolDisplay& iSrc );

	//! Copy constructor
	CuttingPlaneSymbolDisplay( const CuttingPlaneSymbolDisplay& original );
     
public:

	//! Set PlaneColour array
	plmxml_api::Result SetPlaneColour( const double *arg );

	//! Get PlaneColour array
	plmxml_api::Result GetPlaneColour( double *arg ) const;

	//! Check if PlaneColour array is set
	plmxml_api::logical HasPlaneColour() const;

	//! Unset PlaneColour array
	plmxml_api::Result UnsetPlaneColour();

	//! Set TwoArrows
	plmxml_api::Result SetTwoArrows( plmxml_api::logical arg );

	//! Get TwoArrows
	plmxml_api::logical GetTwoArrows() const;

	//! Check if TwoArrows is set
	plmxml_api::logical HasTwoArrows() const;

	//! Unset TwoArrows
	plmxml_api::Result UnsetTwoArrows();

	//! Set ShadedPlane
	plmxml_api::Result SetShadedPlane( plmxml_api::logical arg );

	//! Get ShadedPlane
	plmxml_api::logical GetShadedPlane() const;

	//! Check if ShadedPlane is set
	plmxml_api::logical HasShadedPlane() const;

	//! Unset ShadedPlane
	plmxml_api::Result UnsetShadedPlane();

	//! Set LineStyle
	plmxml_api::Result SetLineStyle( const eAnn3DLineType& arg );

	//! Get LineStyle
	eAnn3DLineType GetLineStyle() const;

	//! Set ArrowTowardsCutter
	plmxml_api::Result SetArrowTowardsCutter( plmxml_api::logical arg );

	//! Get ArrowTowardsCutter
	plmxml_api::logical GetArrowTowardsCutter() const;

	//! Check if ArrowTowardsCutter is set
	plmxml_api::logical HasArrowTowardsCutter() const;

	//! Unset ArrowTowardsCutter
	plmxml_api::Result UnsetArrowTowardsCutter();

	//! Set TextPlaneOrientation
	plmxml_api::Result SetTextPlaneOrientation( const eAnn3DTextPlaneOrientationEnum& arg );

	//! Get TextPlaneOrientation
	eAnn3DTextPlaneOrientationEnum GetTextPlaneOrientation() const;

	//! Set ArrowPlacement2
	plmxml_api::Result SetArrowPlacement2( const eAnn3DArrowPlacementEnum& arg );

	//! Get ArrowPlacement2
	eAnn3DArrowPlacementEnum GetArrowPlacement2() const;

	//! Set ArrowPlacement1
	plmxml_api::Result SetArrowPlacement1( const eAnn3DArrowPlacementEnum& arg );

	//! Get ArrowPlacement1
	eAnn3DArrowPlacementEnum GetArrowPlacement1() const;
 
// <PLMXML_UserCode type="functionHeaderCuttingPlaneSymbolDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCuttingPlaneSymbolDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Crosshatch class
/*!
\verbatim

      Crosshatch Annotation

      Attributes:

      rotate:           Indicates whether or not the crosshatch pattern is
                        rotated.
      pattern:          The pattern used for the Crosshatch. pattern is
                        overriden by definitionRef.
      spacing:          The spacing between the lines in the Crosshatch, in
                        metres.
      angle:            The angle (in radians) of the lines in the crosshatch
                        from the X direction for the symbol.
      definitionRef:    References a CrosshatchPatternDefinition. The entire
                        crosshatch pattern may then be modified by the rotate,
                        spacing and angle attributes. If definitionRef is
                        absent, the crosshatch pattern is defined by the pattern
                        attribute.
         
\endverbatim
*/
class PLMXML_ANNOTATION60_API Crosshatch : public Annotation3D
{
public:
     
    //! Default constructor
    Crosshatch( );
     
    //! Constructs a Crosshatch with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Crosshatch( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Crosshatch();

private:

	//! Assignment operator
	Crosshatch& operator=( const Crosshatch& iSrc );

	//! Copy constructor
	Crosshatch( const Crosshatch& original );
     
public:

	//! Set Rotate
	plmxml_api::Result SetRotate( plmxml_api::logical arg );

	//! Get Rotate
	plmxml_api::logical GetRotate() const;

	//! Check if Rotate is set
	plmxml_api::logical HasRotate() const;

	//! Unset Rotate
	plmxml_api::Result UnsetRotate();

	//! Set Pattern
	plmxml_api::Result SetPattern( const eAnn3DCrosshatchPattern& arg );

	//! Get Pattern
	eAnn3DCrosshatchPattern GetPattern() const;

	//! Set Spacing
	plmxml_api::Result SetSpacing( double arg );

     //! Get Spacing
	double GetSpacing() const;

	//! Check if Spacing is set
	plmxml_api::logical HasSpacing() const;

	//! Unset Spacing
	plmxml_api::Result UnsetSpacing();

	//! Set Angle
	plmxml_api::Result SetAngle( double arg );

     //! Get Angle
	double GetAngle() const;

	//! Check if Angle is set
	plmxml_api::logical HasAngle() const;

	//! Unset Angle
	plmxml_api::Result UnsetAngle();

	//! Get Definition URI as plmxml_api::String
	plmxml_api::String GetDefinitionURI() const;

	//! Set Definition URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDefinitionURI( const plmxml_api::String& );
	
	//! Get the handle of Definition URI. Does not resolve the URI.
	plmxml_api::Result GetDefinitionURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Definition URI. URI string is unchanged.
	plmxml_api::Result SetDefinitionURI( const plmxml_api::Handle& );
	
	//! Resolve Definition URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDefinitionURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Definition URI. Clears URI string and handle.
	plmxml_api::Result DeleteDefinitionURI();
	
	//! Check if Definition URI is set
	plmxml_api::logical HasDefinitionURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderCrosshatch" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCrosshatch;


////////////////////////////////////////////////////////////////////////////////////
//! CrosshatchDisplay class
/*!
\verbatim

      Crosshatch Display.

      Attributes:

      symbolColour:     Inherited from Ann3DDisplay. The colour of the lines in
                        the Crosshatch.
      widthRef:         References a LineWidth, which specifies the thickness of
                        the lines in the Crosshatch.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CrosshatchDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    CrosshatchDisplay( );
     
    //! Constructs a CrosshatchDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CrosshatchDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CrosshatchDisplay();

private:

	//! Assignment operator
	CrosshatchDisplay& operator=( const CrosshatchDisplay& iSrc );

	//! Copy constructor
	CrosshatchDisplay( const CrosshatchDisplay& original );
     
public:

	//! Get Width URI as plmxml_api::String
	plmxml_api::String GetWidthURI() const;

	//! Set Width URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::String& );
	
	//! Get the handle of Width URI. Does not resolve the URI.
	plmxml_api::Result GetWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Width URI. URI string is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::Handle& );
	
	//! Resolve Width URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Width URI. Clears URI string and handle.
	plmxml_api::Result DeleteWidthURI();
	
	//! Check if Width URI is set
	plmxml_api::logical HasWidthURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderCrosshatchDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCrosshatchDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DeMarking class
/*!
\verbatim

      eMarking Annotation (derived from Note).

      The eMarking annotation indicates governmental, legal, and proprietary controls
      over products.
      
      Attributes:
      
      type:             type of information
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DeMarking : public Note
{
public:
     
    //! Default constructor
    Ann3DeMarking( );
     
    //! Constructs a Ann3DeMarking with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DeMarking( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DeMarking();

private:

	//! Assignment operator
	Ann3DeMarking& operator=( const Ann3DeMarking& iSrc );

	//! Copy constructor
	Ann3DeMarking( const Ann3DeMarking& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DeMarkingEnumType& arg );

	//! Get Type
	eAnn3DeMarkingEnumType GetType() const;
 
// <PLMXML_UserCode type="functionHeaderAnn3DeMarking" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DeMarking;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DeMarkingDisplay class
/*!
\verbatim

      Ann3DeMarkingDisplay
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DeMarkingDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    Ann3DeMarkingDisplay( );
     
    //! Constructs a Ann3DeMarkingDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DeMarkingDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DeMarkingDisplay();

private:

	//! Assignment operator
	Ann3DeMarkingDisplay& operator=( const Ann3DeMarkingDisplay& iSrc );

	//! Copy constructor
	Ann3DeMarkingDisplay( const Ann3DeMarkingDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DeMarkingDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DeMarkingDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DGroup class
/*!
\verbatim

      Ann3DGroup (derived from GDE).
      
      This element represents a collection of 3D Annotations.
      
      It instances its Annotations via the gdeInstanceRefs attribute, in other words the
      Annotations are regarded as sub-structure.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DGroup : public GDE
{
public:
     
    //! Default constructor
    Ann3DGroup( );
     
    //! Constructs a Ann3DGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DGroup();

private:

	//! Assignment operator
	Ann3DGroup& operator=( const Ann3DGroup& iSrc );

	//! Copy constructor
	Ann3DGroup( const Ann3DGroup& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DGroup;


////////////////////////////////////////////////////////////////////////////////////
//! Annotation3DGroup class
/*!
\verbatim

      Annotation3DGroup: This element is deprecated.

      Attributes:
      
      dimensionStandard:      standard to use for dimensions (and other annotations which 
                                use the same standards enum)
      surfaceFinishStandard:  standard to use for surface finishes
      lineWeldStandard:       standard to use for line welds

      Elements:
      
      any number of Dimensions, Fasteners, etc etc, and corresponding Display elements.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Annotation3DGroup : public Attribute
{
public:
     
    //! Default constructor
    Annotation3DGroup( );
     
    //! Constructs a Annotation3DGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Annotation3DGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Annotation3DGroup();

private:

	//! Assignment operator
	Annotation3DGroup& operator=( const Annotation3DGroup& iSrc );

	//! Copy constructor
	Annotation3DGroup( const Annotation3DGroup& original );
     
public:

	//! Set SurfaceFinishStandard
	plmxml_api::Result SetSurfaceFinishStandard( const eAnn3DSurfaceFinishStandardType& arg );

	//! Get SurfaceFinishStandard
	eAnn3DSurfaceFinishStandardType GetSurfaceFinishStandard() const;

	//! Set DimensionStandard
	plmxml_api::Result SetDimensionStandard( const eAnn3DDimensionStandardType& arg );

	//! Get DimensionStandard
	eAnn3DDimensionStandardType GetDimensionStandard() const;

	//! Set LineWeldStandard
	plmxml_api::Result SetLineWeldStandard( const eAnn3DLineWeldStandardType& arg );

	//! Get LineWeldStandard
	eAnn3DLineWeldStandardType GetLineWeldStandard() const;

	//! Add Annotation3D child element to this Annotation3DGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Annotation3D *AddAnnotation3D();
     
	//! Add 'arg' as Annotation3D child element to this Annotation3DGroup.
	plmxml_api::Result AddAnnotation3D( Annotation3D *arg );

	//! Detach and delete all Annotation3D child elements.
	void DeleteAnnotation3Ds();
     
	//! Get number of Annotation3D child elements.
	int NumberOfAnnotation3Ds() const;
     
	//! Get i'th Annotation3D child element.
	Annotation3D *GetAnnotation3D( int i ) const;
     
	//! Get all Annotation3D child element as an array
	void GetAnnotation3Ds( plmxml_api::Array<Annotation3D*> &array ) const;
	     
	//! Detach and delete i'th Annotation3D child element
	void DeleteAnnotation3D( int i );
     
	//! Detach and delete 'arg' if it's one of the Annotation3D child elements
	void DeleteAnnotation3D( Annotation3D *arg );

	//! Add Ann3DDisplay child element to this Annotation3DGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDisplay *AddAnn3DDisplay();
     
	//! Add 'arg' as Ann3DDisplay child element to this Annotation3DGroup.
	plmxml_api::Result AddAnn3DDisplay( Ann3DDisplay *arg );

	//! Detach and delete all Ann3DDisplay child elements.
	void DeleteAnn3DDisplays();
     
	//! Get number of Ann3DDisplay child elements.
	int NumberOfAnn3DDisplays() const;
     
	//! Get i'th Ann3DDisplay child element.
	Ann3DDisplay *GetAnn3DDisplay( int i ) const;
     
	//! Get all Ann3DDisplay child element as an array
	void GetAnn3DDisplays( plmxml_api::Array<Ann3DDisplay*> &array ) const;
	     
	//! Detach and delete i'th Ann3DDisplay child element
	void DeleteAnn3DDisplay( int i );
     
	//! Detach and delete 'arg' if it's one of the Ann3DDisplay child elements
	void DeleteAnn3DDisplay( Ann3DDisplay *arg );
 
// <PLMXML_UserCode type="functionHeaderAnnotation3DGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnnotation3DGroup;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DArea class
/*!
\verbatim

      A constituent area of an Ann3DRegion.

      Attributes:

      type:             The shape of the Area as an Ann3DAreaEnum.
      length:           Refers to the side of a rectangular Area that lies along
                        the 'x' axis of the Plane sub-element.
      width:            Refers to the side of a rectangular Area that lies along
                        the 'y' axis of the Plane sub-element.
      diameter:         The diameter of a circular Area. The outer diameter of
                        an annular Area.
      innerDiameter:    The inner diameter of an annular Area.
      height:           The height along the axis of a cylindrical Area in the
                        direction of the 'z' axis of the Plane sub-element.
      insidePoint:      If type is general and the Area has a set of Curve
                        sub-elements, insidePoint is any point that indicates
                        the inside of the set.
      originAnchor:     If type is circular, rectangular or annular,
                        originAnchor is the point on the Area that the origin
                        attribute of the Plane sub-element defines.

      Sub-elements:

      Plane:            The plane in which the Area lies. The origin of the
                        plane defines the origin of a circular, rectangular,
                        cylindrical or annular Area. The xAxis of the plane
                        defines the direction of a rectangular area. (Also
                        circular and annular but these are invariant under
                        change of direction.) The zAxis of the plane defines the
                        axis of a cylindrical Area.
      Curve:            The curves that constitute a general Area.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DArea : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DArea( );
     
    //! Constructs a Ann3DArea with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DArea( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DArea();

private:

	//! Assignment operator
	Ann3DArea& operator=( const Ann3DArea& iSrc );

	//! Copy constructor
	Ann3DArea( const Ann3DArea& original );
     
public:

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set InsidePoint using plmxml_api::Vector components
	plmxml_api::Result SetInsidePoint( const plmxml_api::Vector& arg );

	//! Get InsidePoint as plmxml_api::Vector
	plmxml_api::Result GetInsidePoint( plmxml_api::Vector& arg ) const;

	//! Check if InsidePoint is set
	plmxml_api::logical HasInsidePoint() const;

	//! Unset InsidePoint
	plmxml_api::Result UnsetInsidePoint();

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DAreaEnum& arg );

	//! Get Type
	eAnn3DAreaEnum GetType() const;

	//! Set InnerDiameter
	plmxml_api::Result SetInnerDiameter( double arg );

     //! Get InnerDiameter
	double GetInnerDiameter() const;

	//! Check if InnerDiameter is set
	plmxml_api::logical HasInnerDiameter() const;

	//! Unset InnerDiameter
	plmxml_api::Result UnsetInnerDiameter();

	//! Set OriginAnchor
	plmxml_api::Result SetOriginAnchor( const eAnn3DOriginAnchorEnum& arg );

	//! Get OriginAnchor
	eAnn3DOriginAnchorEnum GetOriginAnchor() const;

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Set Width
	plmxml_api::Result SetWidth( double arg );

     //! Get Width
	double GetWidth() const;

	//! Check if Width is set
	plmxml_api::logical HasWidth() const;

	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Set Height
	plmxml_api::Result SetHeight( double arg );

     //! Get Height
	double GetHeight() const;

	//! Check if Height is set
	plmxml_api::logical HasHeight() const;

	//! Unset Height
	plmxml_api::Result UnsetHeight();

	//! Add Plane child element to this Ann3DArea. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddPlane();
     
	//! Set Plane child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPlane( Plane *arg );
     
	//! Get Plane child element of this Ann3DArea.
	Plane *GetPlane() const;
     
	//! Detach and delete Plane child element tree from this Ann3DArea.
	void DeletePlane();

	//! Add Curve child element to this Ann3DArea. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Curve *AddCurve();
     
	//! Add 'arg' as Curve child element to this Ann3DArea.
	plmxml_api::Result AddCurve( Curve *arg );

	//! Detach and delete all Curve child elements.
	void DeleteCurves();
     
	//! Get number of Curve child elements.
	int NumberOfCurves() const;
     
	//! Get i'th Curve child element.
	Curve *GetCurve( int i ) const;
     
	//! Get all Curve child element as an array
	void GetCurves( plmxml_api::Array<Curve*> &array ) const;
	     
	//! Detach and delete i'th Curve child element
	void DeleteCurve( int i );
     
	//! Detach and delete 'arg' if it's one of the Curve child elements
	void DeleteCurve( Curve *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DArea" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DArea;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DRegion class
/*!
\verbatim

      Region Annotation.

      Attributes:

      conformsToFaces:  Whether the Ann3DRegion conforms to the target faces of
                        the RegionAreaReference sub-elements under its
                        Ann3DInstance or Ann3DOccurrence.
      patternRef:       References a Crosshatch element that holds the
                        crosshatch parameters of the Ann3DRegion. If this
                        attribute is absent, the Ann3DRegion is not
                        crosshatched.

      Sub-elements:

      Area:             The Areas that constitute the Ann3DRegion.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DRegion : public Annotation3D
{
public:
     
    //! Default constructor
    Ann3DRegion( );
     
    //! Constructs a Ann3DRegion with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DRegion( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DRegion();

private:

	//! Assignment operator
	Ann3DRegion& operator=( const Ann3DRegion& iSrc );

	//! Copy constructor
	Ann3DRegion( const Ann3DRegion& original );
     
public:

	//! Set ConformsToFaces
	plmxml_api::Result SetConformsToFaces( plmxml_api::logical arg );

	//! Get ConformsToFaces
	plmxml_api::logical GetConformsToFaces() const;

	//! Check if ConformsToFaces is set
	plmxml_api::logical HasConformsToFaces() const;

	//! Unset ConformsToFaces
	plmxml_api::Result UnsetConformsToFaces();

	//! Get Pattern URI as plmxml_api::String
	plmxml_api::String GetPatternURI() const;

	//! Set Pattern URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPatternURI( const plmxml_api::String& );
	
	//! Get the handle of Pattern URI. Does not resolve the URI.
	plmxml_api::Result GetPatternURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Pattern URI. URI string is unchanged.
	plmxml_api::Result SetPatternURI( const plmxml_api::Handle& );
	
	//! Resolve Pattern URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePatternURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Pattern URI. Clears URI string and handle.
	plmxml_api::Result DeletePatternURI();
	
	//! Check if Pattern URI is set
	plmxml_api::logical HasPatternURI( ) const;
	

	//! Add Area child element to this Ann3DRegion. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DArea *AddArea();
     
	//! Add 'arg' as Area child element to this Ann3DRegion.
	plmxml_api::Result AddArea( Ann3DArea *arg );

	//! Detach and delete all Area child elements.
	void DeleteAreas();
     
	//! Get number of Area child elements.
	int NumberOfAreas() const;
     
	//! Get i'th Area child element.
	Ann3DArea *GetArea( int i ) const;
     
	//! Get all Area child element as an array
	void GetAreas( plmxml_api::Array<Ann3DArea*> &array ) const;
	     
	//! Detach and delete i'th Area child element
	void DeleteArea( int i );
     
	//! Detach and delete 'arg' if it's one of the Area child elements
	void DeleteArea( Ann3DArea *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DRegion" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DRegion;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DRegionAreaReference class
/*!
\verbatim

      A specialisation of Reference for defining the Areas that constitute an
      Ann3DInstance or Ann3DOccurrence of an Ann3DRegion.

      Attributes:

      targetRef:        Inherited from GDEReferenceType. References the face
                        that defines the Area.
      areaRef:          References the Area that the face defines.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DRegionAreaReference : public GDEReference
{
public:
     
    //! Default constructor
    Ann3DRegionAreaReference( );
     
    //! Constructs a Ann3DRegionAreaReference with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DRegionAreaReference( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DRegionAreaReference();

private:

	//! Assignment operator
	Ann3DRegionAreaReference& operator=( const Ann3DRegionAreaReference& iSrc );

	//! Copy constructor
	Ann3DRegionAreaReference( const Ann3DRegionAreaReference& original );
     
public:

	//! Get Area URI as plmxml_api::String
	plmxml_api::String GetAreaURI() const;

	//! Set Area URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAreaURI( const plmxml_api::String& );
	
	//! Get the handle of Area URI. Does not resolve the URI.
	plmxml_api::Result GetAreaURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Area URI. URI string is unchanged.
	plmxml_api::Result SetAreaURI( const plmxml_api::Handle& );
	
	//! Resolve Area URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAreaURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Area URI. Clears URI string and handle.
	plmxml_api::Result DeleteAreaURI();
	
	//! Check if Area URI is set
	plmxml_api::logical HasAreaURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderAnn3DRegionAreaReference" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DRegionAreaReference;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DRegionDisplay class
/*!
\verbatim

      Region Display.

      Attributes:

      symbolColour:     Inherited from Ann3DDisplay. The colour of the boundary
                        lines of the Region.
      lineStyle:        The style of the boundary lines of the Region.
      widthRef:         References a LineWidth, which specifies the thickness of
                        the boundary lines.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DRegionDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    Ann3DRegionDisplay( );
     
    //! Constructs a Ann3DRegionDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DRegionDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DRegionDisplay();

private:

	//! Assignment operator
	Ann3DRegionDisplay& operator=( const Ann3DRegionDisplay& iSrc );

	//! Copy constructor
	Ann3DRegionDisplay( const Ann3DRegionDisplay& original );
     
public:

	//! Set LineStyle
	plmxml_api::Result SetLineStyle( const eAnn3DLineType& arg );

	//! Get LineStyle
	eAnn3DLineType GetLineStyle() const;

	//! Get Width URI as plmxml_api::String
	plmxml_api::String GetWidthURI() const;

	//! Set Width URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::String& );
	
	//! Get the handle of Width URI. Does not resolve the URI.
	plmxml_api::Result GetWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Width URI. URI string is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::Handle& );
	
	//! Resolve Width URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Width URI. Clears URI string and handle.
	plmxml_api::Result DeleteWidthURI();
	
	//! Check if Width URI is set
	plmxml_api::logical HasWidthURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderAnn3DRegionDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DRegionDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Centerline class
/*!
\verbatim

      Centerline Annotation.

      Attributes:

      centerlineType:   The type of the Centerline.
      individualExtensions: Whether each extension is defined individually.
      fullCircle:       Whether a circular Centerline contains a full circle.
      centercrossSize:  For transverse Centerlines, the size of the center
                        cross.
      overrun:          For longitudinal Centerlines, the overrun past the model
                        geometry.
      shortDash:        For 2DCenterline Centerlines, the length of the short
                        dash.
      angle:            The angle (in radians) of the center cross from the X
                        direction of the display plane.
      center:           The centre of a circular Centerline.
      circularCenterlineMethod: The method for defining circular centerlines.

      Sub-elements:

      Position:         Positions of the Centerlines in model space.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Centerline : public Annotation3D
{
public:
     
    //! Default constructor
    Centerline( );
     
    //! Constructs a Centerline with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Centerline( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Centerline();

private:

	//! Assignment operator
	Centerline& operator=( const Centerline& iSrc );

	//! Copy constructor
	Centerline( const Centerline& original );
     
public:

	//! Set FullCircle
	plmxml_api::Result SetFullCircle( plmxml_api::logical arg );

	//! Get FullCircle
	plmxml_api::logical GetFullCircle() const;

	//! Check if FullCircle is set
	plmxml_api::logical HasFullCircle() const;

	//! Unset FullCircle
	plmxml_api::Result UnsetFullCircle();

	//! Set CircularCenterlineMethod
	plmxml_api::Result SetCircularCenterlineMethod( const eAnn3DCircularCenterlineMethodEnum& arg );

	//! Get CircularCenterlineMethod
	eAnn3DCircularCenterlineMethodEnum GetCircularCenterlineMethod() const;

	//! Set IndividualExtensions
	plmxml_api::Result SetIndividualExtensions( plmxml_api::logical arg );

	//! Get IndividualExtensions
	plmxml_api::logical GetIndividualExtensions() const;

	//! Check if IndividualExtensions is set
	plmxml_api::logical HasIndividualExtensions() const;

	//! Unset IndividualExtensions
	plmxml_api::Result UnsetIndividualExtensions();

	//! Set CentercrossSize
	plmxml_api::Result SetCentercrossSize( double arg );

     //! Get CentercrossSize
	double GetCentercrossSize() const;

	//! Check if CentercrossSize is set
	plmxml_api::logical HasCentercrossSize() const;

	//! Unset CentercrossSize
	plmxml_api::Result UnsetCentercrossSize();

	//! Set Angle
	plmxml_api::Result SetAngle( double arg );

     //! Get Angle
	double GetAngle() const;

	//! Check if Angle is set
	plmxml_api::logical HasAngle() const;

	//! Unset Angle
	plmxml_api::Result UnsetAngle();

	//! Set Center using plmxml_api::Vector components
	plmxml_api::Result SetCenter( const plmxml_api::Vector& arg );

	//! Get Center as plmxml_api::Vector
	plmxml_api::Result GetCenter( plmxml_api::Vector& arg ) const;

	//! Check if Center is set
	plmxml_api::logical HasCenter() const;

	//! Unset Center
	plmxml_api::Result UnsetCenter();

	//! Set ShortDash
	plmxml_api::Result SetShortDash( double arg );

     //! Get ShortDash
	double GetShortDash() const;

	//! Check if ShortDash is set
	plmxml_api::logical HasShortDash() const;

	//! Unset ShortDash
	plmxml_api::Result UnsetShortDash();

	//! Set Overrun
	plmxml_api::Result SetOverrun( double arg );

     //! Get Overrun
	double GetOverrun() const;

	//! Check if Overrun is set
	plmxml_api::logical HasOverrun() const;

	//! Unset Overrun
	plmxml_api::Result UnsetOverrun();

	//! Set CenterlineType
	plmxml_api::Result SetCenterlineType( const eAnn3DCenterlineEnum& arg );

	//! Get CenterlineType
	eAnn3DCenterlineEnum GetCenterlineType() const;

	//! Add Position child element to this Centerline. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	VectorField *AddPosition();
     
	//! Add 'arg' as Position child element to this Centerline.
	plmxml_api::Result AddPosition( VectorField *arg );

	//! Detach and delete all Position child elements.
	void DeletePositions();
     
	//! Get number of Position child elements.
	int NumberOfPositions() const;
     
	//! Get i'th Position child element.
	VectorField *GetPosition( int i ) const;
     
	//! Get all Position child element as an array
	void GetPositions( plmxml_api::Array<VectorField*> &array ) const;
	     
	//! Detach and delete i'th Position child element
	void DeletePosition( int i );
     
	//! Detach and delete 'arg' if it's one of the Position child elements
	void DeletePosition( VectorField *arg );
 
// <PLMXML_UserCode type="functionHeaderCenterline" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCenterline;


////////////////////////////////////////////////////////////////////////////////////
//! CenterlineDisplay class
/*!
\verbatim

      Centerline Display.

      Attributes:

      displayOption:    The type of the Centerline display.
      widthRef:         References a LineWidth, which specifies the thickness of
                        the Centerline.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CenterlineDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    CenterlineDisplay( );
     
    //! Constructs a CenterlineDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CenterlineDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CenterlineDisplay();

private:

	//! Assignment operator
	CenterlineDisplay& operator=( const CenterlineDisplay& iSrc );

	//! Copy constructor
	CenterlineDisplay( const CenterlineDisplay& original );
     
public:

	//! Set DisplayOption
	plmxml_api::Result SetDisplayOption( const eAnn3DCenterlineDisplayEnum& arg );

	//! Get DisplayOption
	eAnn3DCenterlineDisplayEnum GetDisplayOption() const;

	//! Get Width URI as plmxml_api::String
	plmxml_api::String GetWidthURI() const;

	//! Set Width URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::String& );
	
	//! Get the handle of Width URI. Does not resolve the URI.
	plmxml_api::Result GetWidthURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Width URI. URI string is unchanged.
	plmxml_api::Result SetWidthURI( const plmxml_api::Handle& );
	
	//! Resolve Width URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWidthURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Width URI. Clears URI string and handle.
	plmxml_api::Result DeleteWidthURI();
	
	//! Check if Width URI is set
	plmxml_api::logical HasWidthURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderCenterlineDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCenterlineDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! FitDesignation class
/*!
\verbatim

      FitDesignation: 3D Fit Designation Annotation.

      Attributes:

      standard:         For example, ANSI.
      type:             linear, radial, angular or curveLength.
      direction:        Direction of measurement.
      reference:        Whether a reference Fit Designation.
      origin:           Whether the first or the second entity is the origin
                        for directed Fit Designations.
      value:            The basic size of the fit designation in metres.
      holeUpperDelta:   The maximum size of the hole minus the basic size in
                        metres.
      holeLowerDelta:   The minimum size of the hole minus the basic size in
                        metres.
      shaftUpperDelta:  The maximum size of the shaft minus the basic size in
                        metres.
      shaftLowerDelta:  The minimum size of the shaft minus the basic size in
                        metres.
      pitchDiameterUpperDelta: For threaded shafts, the maximum pitch diameter
                        minus the basic size in metres.
      pitchDiameterLowerDelta: For threaded shafts, the minimum pitch diameter
                        minus the basic size in metres.
      holeDeviation:    The deviation letter(s) of the hole.
      holeGrade:        The grade integer of the hole.
      shaftDeviation:   The deviation letter(s) of the shaft. For threaded
                        shafts, the deviation letter(s) of the major diameter.
      shaftGrade:       The grade integer of the shaft. For threaded shafts, the
                        grade integer of the major diameter.
      pitchDiameterDeviation: For threaded shafts, the deviation letter(s) of
                        the pitch diameter.
      pitchDiameterGrade: For threaded shafts, the grade integer of the pitch
                        diameter.
      manual:           Whether value has been entered manually. If it has, it
                        cannot be assumed to be synchronised with the referenced
                        geometry.
      patternCount:     The number of repetitions in a compound feature to which
                        the Fit Designation applies.
      notToScale:       Whether the Fit Designation is not-to-scale.
      allAround:        Whether the All Around symbol is added.
      allOver:          Whether the tolerance applies all over the 3-dimensional
                        profile of the part.
      featureOfSize:    Whether the Fit Designation specifies the size of a
                        feature.

      Sub-elements:

      FitDesignationText: Text elements.
      Statistical:      Statistical refinement.
      FreeState:        Free State refinement.
      ValueText:        When manual is true, ValueText overrides value.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API FitDesignation : public Annotation3D
{
public:
     
    //! Default constructor
    FitDesignation( );
     
    //! Constructs a FitDesignation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FitDesignation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FitDesignation();

private:

	//! Assignment operator
	FitDesignation& operator=( const FitDesignation& iSrc );

	//! Copy constructor
	FitDesignation( const FitDesignation& original );
     
public:

	//! Set PitchDiameterGrade
	plmxml_api::Result SetPitchDiameterGrade( int arg );
     
	//! Get PitchDiameterGrade
	int GetPitchDiameterGrade() const;
     
	//! Check if PitchDiameterGrade is set
	plmxml_api::logical HasPitchDiameterGrade() const;
     
	//! Unset PitchDiameterGrade
	plmxml_api::Result UnsetPitchDiameterGrade();

	//! Set FeatureOfSize
	plmxml_api::Result SetFeatureOfSize( plmxml_api::logical arg );

	//! Get FeatureOfSize
	plmxml_api::logical GetFeatureOfSize() const;

	//! Check if FeatureOfSize is set
	plmxml_api::logical HasFeatureOfSize() const;

	//! Unset FeatureOfSize
	plmxml_api::Result UnsetFeatureOfSize();

	//! Set Manual
	plmxml_api::Result SetManual( plmxml_api::logical arg );

	//! Get Manual
	plmxml_api::logical GetManual() const;

	//! Check if Manual is set
	plmxml_api::logical HasManual() const;

	//! Unset Manual
	plmxml_api::Result UnsetManual();

	//! Set PitchDiameterUpperDelta
	plmxml_api::Result SetPitchDiameterUpperDelta( double arg );

     //! Get PitchDiameterUpperDelta
	double GetPitchDiameterUpperDelta() const;

	//! Check if PitchDiameterUpperDelta is set
	plmxml_api::logical HasPitchDiameterUpperDelta() const;

	//! Unset PitchDiameterUpperDelta
	plmxml_api::Result UnsetPitchDiameterUpperDelta();

	//! Set ShaftUpperDelta
	plmxml_api::Result SetShaftUpperDelta( double arg );

     //! Get ShaftUpperDelta
	double GetShaftUpperDelta() const;

	//! Check if ShaftUpperDelta is set
	plmxml_api::logical HasShaftUpperDelta() const;

	//! Unset ShaftUpperDelta
	plmxml_api::Result UnsetShaftUpperDelta();

	//! Set NotToScale
	plmxml_api::Result SetNotToScale( plmxml_api::logical arg );

	//! Get NotToScale
	plmxml_api::logical GetNotToScale() const;

	//! Check if NotToScale is set
	plmxml_api::logical HasNotToScale() const;

	//! Unset NotToScale
	plmxml_api::Result UnsetNotToScale();

	//! Set HoleUpperDelta
	plmxml_api::Result SetHoleUpperDelta( double arg );

     //! Get HoleUpperDelta
	double GetHoleUpperDelta() const;

	//! Check if HoleUpperDelta is set
	plmxml_api::logical HasHoleUpperDelta() const;

	//! Unset HoleUpperDelta
	plmxml_api::Result UnsetHoleUpperDelta();

	//! Set PatternCount
	plmxml_api::Result SetPatternCount( int arg );
     
	//! Get PatternCount
	int GetPatternCount() const;
     
	//! Check if PatternCount is set
	plmxml_api::logical HasPatternCount() const;
     
	//! Unset PatternCount
	plmxml_api::Result UnsetPatternCount();

	//! Get HoleDeviation of this FitDesignation
	plmxml_api::String GetHoleDeviation() const;

	//! Set HoleDeviation of this FitDesignation
	plmxml_api::Result SetHoleDeviation( const plmxml_api::String &s );
	
	//! Check if HoleDeviation is set
	plmxml_api::logical HasHoleDeviation( ) const;
	
	//! Unset HoleDeviation
	plmxml_api::Result UnsetHoleDeviation( );

	//! Set AllOver
	plmxml_api::Result SetAllOver( plmxml_api::logical arg );

	//! Get AllOver
	plmxml_api::logical GetAllOver() const;

	//! Check if AllOver is set
	plmxml_api::logical HasAllOver() const;

	//! Unset AllOver
	plmxml_api::Result UnsetAllOver();

	//! Set Type
	plmxml_api::Result SetType( const eAnn3DDimension& arg );

	//! Get Type
	eAnn3DDimension GetType() const;

	//! Set Standard
	plmxml_api::Result SetStandard( const eAnn3DDimensionStandardType& arg );

	//! Get Standard
	eAnn3DDimensionStandardType GetStandard() const;

	//! Set HoleGrade
	plmxml_api::Result SetHoleGrade( int arg );
     
	//! Get HoleGrade
	int GetHoleGrade() const;
     
	//! Check if HoleGrade is set
	plmxml_api::logical HasHoleGrade() const;
     
	//! Unset HoleGrade
	plmxml_api::Result UnsetHoleGrade();

	//! Set ShaftLowerDelta
	plmxml_api::Result SetShaftLowerDelta( double arg );

     //! Get ShaftLowerDelta
	double GetShaftLowerDelta() const;

	//! Check if ShaftLowerDelta is set
	plmxml_api::logical HasShaftLowerDelta() const;

	//! Unset ShaftLowerDelta
	plmxml_api::Result UnsetShaftLowerDelta();

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set HoleLowerDelta
	plmxml_api::Result SetHoleLowerDelta( double arg );

     //! Get HoleLowerDelta
	double GetHoleLowerDelta() const;

	//! Check if HoleLowerDelta is set
	plmxml_api::logical HasHoleLowerDelta() const;

	//! Unset HoleLowerDelta
	plmxml_api::Result UnsetHoleLowerDelta();

	//! Set PitchDiameterLowerDelta
	plmxml_api::Result SetPitchDiameterLowerDelta( double arg );

     //! Get PitchDiameterLowerDelta
	double GetPitchDiameterLowerDelta() const;

	//! Check if PitchDiameterLowerDelta is set
	plmxml_api::logical HasPitchDiameterLowerDelta() const;

	//! Unset PitchDiameterLowerDelta
	plmxml_api::Result UnsetPitchDiameterLowerDelta();

	//! Set ShaftGrade
	plmxml_api::Result SetShaftGrade( int arg );
     
	//! Get ShaftGrade
	int GetShaftGrade() const;
     
	//! Check if ShaftGrade is set
	plmxml_api::logical HasShaftGrade() const;
     
	//! Unset ShaftGrade
	plmxml_api::Result UnsetShaftGrade();

	//! Set Origin
	plmxml_api::Result SetOrigin( const eAnn3DDimensionOrigin& arg );

	//! Get Origin
	eAnn3DDimensionOrigin GetOrigin() const;

	//! Get ShaftDeviation of this FitDesignation
	plmxml_api::String GetShaftDeviation() const;

	//! Set ShaftDeviation of this FitDesignation
	plmxml_api::Result SetShaftDeviation( const plmxml_api::String &s );
	
	//! Check if ShaftDeviation is set
	plmxml_api::logical HasShaftDeviation( ) const;
	
	//! Unset ShaftDeviation
	plmxml_api::Result UnsetShaftDeviation( );

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();

	//! Get PitchDiameterDeviation of this FitDesignation
	plmxml_api::String GetPitchDiameterDeviation() const;

	//! Set PitchDiameterDeviation of this FitDesignation
	plmxml_api::Result SetPitchDiameterDeviation( const plmxml_api::String &s );
	
	//! Check if PitchDiameterDeviation is set
	plmxml_api::logical HasPitchDiameterDeviation( ) const;
	
	//! Unset PitchDiameterDeviation
	plmxml_api::Result UnsetPitchDiameterDeviation( );

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set Reference
	plmxml_api::Result SetReference( plmxml_api::logical arg );

	//! Get Reference
	plmxml_api::logical GetReference() const;

	//! Check if Reference is set
	plmxml_api::logical HasReference() const;

	//! Unset Reference
	plmxml_api::Result UnsetReference();

	//! Add FitDesignationText child element to this FitDesignation. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DDimensionText *AddFitDesignationText();
     
	//! Add 'arg' as FitDesignationText child element to this FitDesignation.
	plmxml_api::Result AddFitDesignationText( Ann3DDimensionText *arg );

	//! Detach and delete all FitDesignationText child elements.
	void DeleteFitDesignationTexts();
     
	//! Get number of FitDesignationText child elements.
	int NumberOfFitDesignationTexts() const;
     
	//! Get i'th FitDesignationText child element.
	Ann3DDimensionText *GetFitDesignationText( int i ) const;
     
	//! Get all FitDesignationText child element as an array
	void GetFitDesignationTexts( plmxml_api::Array<Ann3DDimensionText*> &array ) const;
	     
	//! Detach and delete i'th FitDesignationText child element
	void DeleteFitDesignationText( int i );
     
	//! Detach and delete 'arg' if it's one of the FitDesignationText child elements
	void DeleteFitDesignationText( Ann3DDimensionText *arg );

	//! Add Statistical child element to this FitDesignation. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DStatisticalRefinement *AddStatistical();
     
	//! Set Statistical child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStatistical( Ann3DStatisticalRefinement *arg );
     
	//! Get Statistical child element of this FitDesignation.
	Ann3DStatisticalRefinement *GetStatistical() const;
     
	//! Detach and delete Statistical child element tree from this FitDesignation.
	void DeleteStatistical();

	//! Add FreeState child element to this FitDesignation. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DFreeStateRefinement *AddFreeState();
     
	//! Set FreeState child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFreeState( Ann3DFreeStateRefinement *arg );
     
	//! Get FreeState child element of this FitDesignation.
	Ann3DFreeStateRefinement *GetFreeState() const;
     
	//! Detach and delete FreeState child element tree from this FitDesignation.
	void DeleteFreeState();

	//! Add ValueText child element to this FitDesignation. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddValueText();
     
	//! Set ValueText child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueText( Ann3DText *arg );
     
	//! Get ValueText child element of this FitDesignation.
	Ann3DText *GetValueText() const;
     
	//! Detach and delete ValueText child element tree from this FitDesignation.
	void DeleteValueText();
 
// <PLMXML_UserCode type="functionHeaderFitDesignation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassFitDesignation;


////////////////////////////////////////////////////////////////////////////////////
//! FitDesignationDisplay class
/*!
\verbatim

      FitDesignationDisplay: 3D Fit Designation Display.

      Attributes:

      toleranceDisplay: The method of display for any tolerances.
      style:            Style of display: radial, diametral, sphericalRadial,
                        controlledRadial, sphericalDiameter, ordinate or
                        linearDiametral. The value, limits, is deprecated in
                        favour of the limitDisplay attribute.
      unitText:         Whether to display the unit text.
      precision:        The precision of the displayed value in number of
                        decimal places. This is the number of decimal places
                        that can be relied on, whether or not that number of
                        decimal places is actually displayed. Normally they
                        would be displayed but trailing zeros can be suppressed
                        by setting valueTrailingZero to false.
      tolerancePrecision: The number of decimal places displayed in any
                        tolerances.
      zeroToleranceDisplay: Controls the display of any zero valued tolerances.
      valueLeadingZero: Whether to display leading zeros in the value attribute.
      toleranceLeadingZero: Whether to display leading zeros in any tolerances.
      valueTrailingZero: Whether trailing zeros on the value attribute are
                        displayed. This does not affect the precision of the
                        displayed value. See precision attribute.
      toleranceTrailingZero: Whether trailing zeros on any tolerances are
                        displayed.
      displayTolerance: Whether tolerance information is displayed.
      displayClearance: Whether clearance information is displayed.
      limitFitSingleLine: Whether the FitDesignation is displayed on a single
                        line with a slash character or like a fraction.
      limitFitOrder:    The order in which the value attribute, the deviation
                        and grade information, and the tolerance information on
                        the corresponding FitDesignation are displayed.
      limitFitParentheses: Whether the value attribute, the deviation and grade
                        information or the tolerance information on the
                        corresponding FitDesignation are displayed in
                        parentheses.
      horizontalLine:   If limitFitSingleLine is false, horizontalLine
                        determines whether a line is drawn between the numerator
                        and the denominator of the FitDesignation.
      alignment:        If limitFitSingleLine is false, alignment determines
                        the vertical alignment of the hole/shaft deviation/grade
                        and the value.
      limitFitAlignment: The position of the limit and fit (if there is one)
                        relative to the tolerance information, which follows.
      dimensionLineSplit: Where the dimension line is split.
      referenceDisplay: How to display reference Fit Designations - reference,
                        parenthesis, or matched.
      diameterPlacement: Before, after, above or below.
      radialPlacement:  Ditto.
      linearPlacement:  Ditto.
      limitDisplay:     How the deviation and the grade attributes on the
                        corresponding Fit Designation are displayed.
      singleSided:      Whether the Fit Designation is displayed single sided.
      singleSideFirst:  Whether a single sided Fit Designation points towards
                        the first or the second Reference sub-element.
      singleSideLength: The length (or the arc length for an angular
                        Fit Designation) that the non arrow side of a single
                        sided Fit Designation protrudes from the text.
      textOrientationType: How the dimension text is orientated.
      dimensionLineTrim: When textOrientationType is aboveDimensionLine and the
                        dimension line is displayed between the extension lines,
                        dimensionLineTrim specifies whether the dimension line
                        is trimmed if the dimension text crosses both extension
                        lines.
      dimensionLineBetweenArrows: Whether the dimension line is displayed
                        between the dimension arrowheads.
      textLeaderPosition: The position and the orientation of the text at the
                        end of a Leader.
      narrowOffset:     For a narrow Fit Designation, the perpendicular distance
                        from the dimension line to the end of the Leader (if
                        there is one) or the text (if there is no Leader) in
                        metres.
      narrowLeaderAngle: For a narrow Fit Designation, the angle between the
                        dimension line and the Leader in radians.
      foldLocation:     The location of the fold of a folded radius Fit
                        Designation.
      inspection:       Whether the Fit Designation is used for inspection.
      inspectionDisplay:  If inspection is true, inspectionDisplay specifies how
                        any appended text is displayed inside the dimension
                        inspection symbol.

      Sub-elements:

      ToleranceTextFormat: Formatting attributes for the text of the tolerance
                        values. Overrides any formatting attributes applying
                        generally to all text fields.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API FitDesignationDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    FitDesignationDisplay( );
     
    //! Constructs a FitDesignationDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FitDesignationDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FitDesignationDisplay();

private:

	//! Assignment operator
	FitDesignationDisplay& operator=( const FitDesignationDisplay& iSrc );

	//! Copy constructor
	FitDesignationDisplay( const FitDesignationDisplay& original );
     
public:

	//! Set DimensionLineSplit
	plmxml_api::Result SetDimensionLineSplit( const eAnn3DDimensionLineSplitEnum& arg );

	//! Get DimensionLineSplit
	eAnn3DDimensionLineSplitEnum GetDimensionLineSplit() const;

	//! Set ToleranceDisplay
	plmxml_api::Result SetToleranceDisplay( const eAnn3DDimensionTolerance& arg );

	//! Get ToleranceDisplay
	eAnn3DDimensionTolerance GetToleranceDisplay() const;

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set LinearPlacement
	plmxml_api::Result SetLinearPlacement( const eAnn3DDimDiameterPlacement& arg );

	//! Get LinearPlacement
	eAnn3DDimDiameterPlacement GetLinearPlacement() const;

	//! Set LimitFitOrder
	plmxml_api::Result SetLimitFitOrder( const eAnn3DLimitFitOrderEnum& arg );

	//! Get LimitFitOrder
	eAnn3DLimitFitOrderEnum GetLimitFitOrder() const;

	//! Set SingleSided
	plmxml_api::Result SetSingleSided( plmxml_api::logical arg );

	//! Get SingleSided
	plmxml_api::logical GetSingleSided() const;

	//! Check if SingleSided is set
	plmxml_api::logical HasSingleSided() const;

	//! Unset SingleSided
	plmxml_api::Result UnsetSingleSided();

	//! Set DimensionLineBetweenArrows
	plmxml_api::Result SetDimensionLineBetweenArrows( plmxml_api::logical arg );

	//! Get DimensionLineBetweenArrows
	plmxml_api::logical GetDimensionLineBetweenArrows() const;

	//! Check if DimensionLineBetweenArrows is set
	plmxml_api::logical HasDimensionLineBetweenArrows() const;

	//! Unset DimensionLineBetweenArrows
	plmxml_api::Result UnsetDimensionLineBetweenArrows();

	//! Set ZeroToleranceDisplay
	plmxml_api::Result SetZeroToleranceDisplay( const eAnn3DDimensionZeroToleranceDisplay& arg );

	//! Get ZeroToleranceDisplay
	eAnn3DDimensionZeroToleranceDisplay GetZeroToleranceDisplay() const;

	//! Set NarrowOffset
	plmxml_api::Result SetNarrowOffset( double arg );

     //! Get NarrowOffset
	double GetNarrowOffset() const;

	//! Check if NarrowOffset is set
	plmxml_api::logical HasNarrowOffset() const;

	//! Unset NarrowOffset
	plmxml_api::Result UnsetNarrowOffset();

	//! Set NarrowLeaderAngle
	plmxml_api::Result SetNarrowLeaderAngle( double arg );

     //! Get NarrowLeaderAngle
	double GetNarrowLeaderAngle() const;

	//! Check if NarrowLeaderAngle is set
	plmxml_api::logical HasNarrowLeaderAngle() const;

	//! Unset NarrowLeaderAngle
	plmxml_api::Result UnsetNarrowLeaderAngle();

	//! Set SingleSideFirst
	plmxml_api::Result SetSingleSideFirst( plmxml_api::logical arg );

	//! Get SingleSideFirst
	plmxml_api::logical GetSingleSideFirst() const;

	//! Check if SingleSideFirst is set
	plmxml_api::logical HasSingleSideFirst() const;

	//! Unset SingleSideFirst
	plmxml_api::Result UnsetSingleSideFirst();

	//! Set TextOrientationType
	plmxml_api::Result SetTextOrientationType( const eAnn3DTextOrientationEnum& arg );

	//! Get TextOrientationType
	eAnn3DTextOrientationEnum GetTextOrientationType() const;

	//! Set DisplayTolerance
	plmxml_api::Result SetDisplayTolerance( plmxml_api::logical arg );

	//! Get DisplayTolerance
	plmxml_api::logical GetDisplayTolerance() const;

	//! Check if DisplayTolerance is set
	plmxml_api::logical HasDisplayTolerance() const;

	//! Unset DisplayTolerance
	plmxml_api::Result UnsetDisplayTolerance();

	//! Set DiameterPlacement
	plmxml_api::Result SetDiameterPlacement( const eAnn3DDimDiameterPlacement& arg );

	//! Get DiameterPlacement
	eAnn3DDimDiameterPlacement GetDiameterPlacement() const;

	//! Set RadialPlacement
	plmxml_api::Result SetRadialPlacement( const eAnn3DDimDiameterPlacement& arg );

	//! Get RadialPlacement
	eAnn3DDimDiameterPlacement GetRadialPlacement() const;

	//! Set FoldLocation using plmxml_api::Vector components
	plmxml_api::Result SetFoldLocation( const plmxml_api::Vector& arg );

	//! Get FoldLocation as plmxml_api::Vector
	plmxml_api::Result GetFoldLocation( plmxml_api::Vector& arg ) const;

	//! Check if FoldLocation is set
	plmxml_api::logical HasFoldLocation() const;

	//! Unset FoldLocation
	plmxml_api::Result UnsetFoldLocation();

	//! Set Inspection
	plmxml_api::Result SetInspection( plmxml_api::logical arg );

	//! Get Inspection
	plmxml_api::logical GetInspection() const;

	//! Check if Inspection is set
	plmxml_api::logical HasInspection() const;

	//! Unset Inspection
	plmxml_api::Result UnsetInspection();

	//! Set UnitText
	plmxml_api::Result SetUnitText( plmxml_api::logical arg );

	//! Get UnitText
	plmxml_api::logical GetUnitText() const;

	//! Check if UnitText is set
	plmxml_api::logical HasUnitText() const;

	//! Unset UnitText
	plmxml_api::Result UnsetUnitText();

	//! Set SingleSideLength
	plmxml_api::Result SetSingleSideLength( double arg );

     //! Get SingleSideLength
	double GetSingleSideLength() const;

	//! Check if SingleSideLength is set
	plmxml_api::logical HasSingleSideLength() const;

	//! Unset SingleSideLength
	plmxml_api::Result UnsetSingleSideLength();

	//! Set ValueTrailingZero
	plmxml_api::Result SetValueTrailingZero( plmxml_api::logical arg );

	//! Get ValueTrailingZero
	plmxml_api::logical GetValueTrailingZero() const;

	//! Check if ValueTrailingZero is set
	plmxml_api::logical HasValueTrailingZero() const;

	//! Unset ValueTrailingZero
	plmxml_api::Result UnsetValueTrailingZero();

	//! Set ToleranceTrailingZero
	plmxml_api::Result SetToleranceTrailingZero( plmxml_api::logical arg );

	//! Get ToleranceTrailingZero
	plmxml_api::logical GetToleranceTrailingZero() const;

	//! Check if ToleranceTrailingZero is set
	plmxml_api::logical HasToleranceTrailingZero() const;

	//! Unset ToleranceTrailingZero
	plmxml_api::Result UnsetToleranceTrailingZero();

	//! Set InspectionDisplay
	plmxml_api::Result SetInspectionDisplay( const eAnn3DInspectionDisplayEnum& arg );

	//! Get InspectionDisplay
	eAnn3DInspectionDisplayEnum GetInspectionDisplay() const;

	//! Set LimitFitSingleLine
	plmxml_api::Result SetLimitFitSingleLine( plmxml_api::logical arg );

	//! Get LimitFitSingleLine
	plmxml_api::logical GetLimitFitSingleLine() const;

	//! Check if LimitFitSingleLine is set
	plmxml_api::logical HasLimitFitSingleLine() const;

	//! Unset LimitFitSingleLine
	plmxml_api::Result UnsetLimitFitSingleLine();

	//! Set ToleranceLeadingZero
	plmxml_api::Result SetToleranceLeadingZero( plmxml_api::logical arg );

	//! Get ToleranceLeadingZero
	plmxml_api::logical GetToleranceLeadingZero() const;

	//! Check if ToleranceLeadingZero is set
	plmxml_api::logical HasToleranceLeadingZero() const;

	//! Unset ToleranceLeadingZero
	plmxml_api::Result UnsetToleranceLeadingZero();

	//! Set TextLeaderPosition
	plmxml_api::Result SetTextLeaderPosition( const eAnn3DTextLeaderPositionEnum& arg );

	//! Get TextLeaderPosition
	eAnn3DTextLeaderPositionEnum GetTextLeaderPosition() const;

	//! Set Style
	plmxml_api::Result SetStyle( const eAnn3DDimensionStyle& arg );

	//! Get Style
	eAnn3DDimensionStyle GetStyle() const;

	//! Set TolerancePrecision
	plmxml_api::Result SetTolerancePrecision( int arg );
     
	//! Get TolerancePrecision
	int GetTolerancePrecision() const;
     
	//! Check if TolerancePrecision is set
	plmxml_api::logical HasTolerancePrecision() const;
     
	//! Unset TolerancePrecision
	plmxml_api::Result UnsetTolerancePrecision();

	//! Set DimensionLineTrim
	plmxml_api::Result SetDimensionLineTrim( plmxml_api::logical arg );

	//! Get DimensionLineTrim
	plmxml_api::logical GetDimensionLineTrim() const;

	//! Check if DimensionLineTrim is set
	plmxml_api::logical HasDimensionLineTrim() const;

	//! Unset DimensionLineTrim
	plmxml_api::Result UnsetDimensionLineTrim();

	//! Set LimitFitAlignment
	plmxml_api::Result SetLimitFitAlignment( const eAnn3DFitDesignationAlignmentEnum& arg );

	//! Get LimitFitAlignment
	eAnn3DFitDesignationAlignmentEnum GetLimitFitAlignment() const;

	//! Set ValueLeadingZero
	plmxml_api::Result SetValueLeadingZero( plmxml_api::logical arg );

	//! Get ValueLeadingZero
	plmxml_api::logical GetValueLeadingZero() const;

	//! Check if ValueLeadingZero is set
	plmxml_api::logical HasValueLeadingZero() const;

	//! Unset ValueLeadingZero
	plmxml_api::Result UnsetValueLeadingZero();

	//! Set DisplayClearance
	plmxml_api::Result SetDisplayClearance( plmxml_api::logical arg );

	//! Get DisplayClearance
	plmxml_api::logical GetDisplayClearance() const;

	//! Check if DisplayClearance is set
	plmxml_api::logical HasDisplayClearance() const;

	//! Unset DisplayClearance
	plmxml_api::Result UnsetDisplayClearance();

	//! Set HorizontalLine
	plmxml_api::Result SetHorizontalLine( plmxml_api::logical arg );

	//! Get HorizontalLine
	plmxml_api::logical GetHorizontalLine() const;

	//! Check if HorizontalLine is set
	plmxml_api::logical HasHorizontalLine() const;

	//! Unset HorizontalLine
	plmxml_api::Result UnsetHorizontalLine();

	//! Set ReferenceDisplay
	plmxml_api::Result SetReferenceDisplay( const eAnn3DDimReferenceDisplay& arg );

	//! Get ReferenceDisplay
	eAnn3DDimReferenceDisplay GetReferenceDisplay() const;

	//! Set Alignment
	plmxml_api::Result SetAlignment( const eAnn3DFitDesignationAlignmentEnum& arg );

	//! Get Alignment
	eAnn3DFitDesignationAlignmentEnum GetAlignment() const;

	//! Set LimitDisplay
	plmxml_api::Result SetLimitDisplay( const eAnn3DLimitDisplayEnum& arg );

	//! Get LimitDisplay
	eAnn3DLimitDisplayEnum GetLimitDisplay() const;

	//! Set LimitFitParentheses
	plmxml_api::Result SetLimitFitParentheses( const eAnn3DLimitFitParenthesesEnum& arg );

	//! Get LimitFitParentheses
	eAnn3DLimitFitParenthesesEnum GetLimitFitParentheses() const;

	//! Add ToleranceTextFormat child element to this FitDesignationDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTextFormat *AddToleranceTextFormat();
     
	//! Set ToleranceTextFormat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetToleranceTextFormat( Ann3DTextFormat *arg );
     
	//! Get ToleranceTextFormat child element of this FitDesignationDisplay.
	Ann3DTextFormat *GetToleranceTextFormat() const;
     
	//! Detach and delete ToleranceTextFormat child element tree from this FitDesignationDisplay.
	void DeleteToleranceTextFormat();
 
// <PLMXML_UserCode type="functionHeaderFitDesignationDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassFitDesignationDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! ModelViewList class
/*!
\verbatim

      An ordered list of Model View PMIs.

      Attributes:

      current:        Whether the Model View list was the current one when the
                      definitions were saved.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API ModelViewList : public Folder
{
public:
     
    //! Default constructor
    ModelViewList( );
     
    //! Constructs a ModelViewList with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ModelViewList( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ModelViewList();

private:

	//! Assignment operator
	ModelViewList& operator=( const ModelViewList& iSrc );

	//! Copy constructor
	ModelViewList( const ModelViewList& original );
     
public:

	//! Set Current
	plmxml_api::Result SetCurrent( plmxml_api::logical arg );

	//! Get Current
	plmxml_api::logical GetCurrent() const;

	//! Check if Current is set
	plmxml_api::logical HasCurrent() const;

	//! Unset Current
	plmxml_api::Result UnsetCurrent();
 
// <PLMXML_UserCode type="functionHeaderModelViewList" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassModelViewList;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCrosshatchSegment class
/*!
\verbatim

      A definition of a Crosshatch line segment.

      Attributes:

      phantom:                  Whether the line segment is solid or phantom.
      length:                   The length of the segment in Crosshatch line
                                spacing units.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCrosshatchSegment : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DCrosshatchSegment( );
     
    //! Constructs a Ann3DCrosshatchSegment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCrosshatchSegment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCrosshatchSegment();

private:

	//! Assignment operator
	Ann3DCrosshatchSegment& operator=( const Ann3DCrosshatchSegment& iSrc );

	//! Copy constructor
	Ann3DCrosshatchSegment( const Ann3DCrosshatchSegment& original );
     
public:

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set Phantom
	plmxml_api::Result SetPhantom( plmxml_api::logical arg );

	//! Get Phantom
	plmxml_api::logical GetPhantom() const;

	//! Check if Phantom is set
	plmxml_api::logical HasPhantom() const;

	//! Unset Phantom
	plmxml_api::Result UnsetPhantom();
 
// <PLMXML_UserCode type="functionHeaderAnn3DCrosshatchSegment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCrosshatchSegment;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCrosshatchLine class
/*!
\verbatim

      A definition of a Crosshatch line.

      Attributes:

      offset:                   The offset of the line in Crosshatch line
                                spacing units.
      dash:                     Whether the Crosshatch line is solid, phantom or
                                dashed.

      Sub-elements:

      Segment:                  Any number of Crosshatch line segments.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCrosshatchLine : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DCrosshatchLine( );
     
    //! Constructs a Ann3DCrosshatchLine with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCrosshatchLine( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCrosshatchLine();

private:

	//! Assignment operator
	Ann3DCrosshatchLine& operator=( const Ann3DCrosshatchLine& iSrc );

	//! Copy constructor
	Ann3DCrosshatchLine( const Ann3DCrosshatchLine& original );
     
public:

	//! Set Dash
	plmxml_api::Result SetDash( const eAnn3DLineType& arg );

	//! Get Dash
	eAnn3DLineType GetDash() const;

	//! Set Offset
	plmxml_api::Result SetOffset( double arg );

     //! Get Offset
	double GetOffset() const;

	//! Check if Offset is set
	plmxml_api::logical HasOffset() const;

	//! Unset Offset
	plmxml_api::Result UnsetOffset();

	//! Add Segment child element to this Ann3DCrosshatchLine. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCrosshatchSegment *AddSegment();
     
	//! Add 'arg' as Segment child element to this Ann3DCrosshatchLine.
	plmxml_api::Result AddSegment( Ann3DCrosshatchSegment *arg );

	//! Detach and delete all Segment child elements.
	void DeleteSegments();
     
	//! Get number of Segment child elements.
	int NumberOfSegments() const;
     
	//! Get i'th Segment child element.
	Ann3DCrosshatchSegment *GetSegment( int i ) const;
     
	//! Get all Segment child element as an array
	void GetSegments( plmxml_api::Array<Ann3DCrosshatchSegment*> &array ) const;
	     
	//! Detach and delete i'th Segment child element
	void DeleteSegment( int i );
     
	//! Detach and delete 'arg' if it's one of the Segment child elements
	void DeleteSegment( Ann3DCrosshatchSegment *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DCrosshatchLine" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCrosshatchLine;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DCrosshatchGroup class
/*!
\verbatim

      A definition of a Crosshatch line group.

      Attributes:

      angle:                    The angle of the Crosshatch line group in
                                radians.
      scale:                    The scale of the spacing relative to the default
                                Crosshatch line spacing.

      Sub-elements:

      Line:                     One or more Crosshatch lines.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DCrosshatchGroup : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Ann3DCrosshatchGroup( );
     
    //! Constructs a Ann3DCrosshatchGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DCrosshatchGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DCrosshatchGroup();

private:

	//! Assignment operator
	Ann3DCrosshatchGroup& operator=( const Ann3DCrosshatchGroup& iSrc );

	//! Copy constructor
	Ann3DCrosshatchGroup( const Ann3DCrosshatchGroup& original );
     
public:

	//! Set Angle
	plmxml_api::Result SetAngle( double arg );

     //! Get Angle
	double GetAngle() const;

	//! Check if Angle is set
	plmxml_api::logical HasAngle() const;

	//! Unset Angle
	plmxml_api::Result UnsetAngle();

	//! Set Scale
	plmxml_api::Result SetScale( double arg );

     //! Get Scale
	double GetScale() const;

	//! Check if Scale is set
	plmxml_api::logical HasScale() const;

	//! Unset Scale
	plmxml_api::Result UnsetScale();

	//! Add Line child element to this Ann3DCrosshatchGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCrosshatchLine *AddLine();
     
	//! Add 'arg' as Line child element to this Ann3DCrosshatchGroup.
	plmxml_api::Result AddLine( Ann3DCrosshatchLine *arg );

	//! Detach and delete all Line child elements.
	void DeleteLines();
     
	//! Get number of Line child elements.
	int NumberOfLines() const;
     
	//! Get i'th Line child element.
	Ann3DCrosshatchLine *GetLine( int i ) const;
     
	//! Get all Line child element as an array
	void GetLines( plmxml_api::Array<Ann3DCrosshatchLine*> &array ) const;
	     
	//! Detach and delete i'th Line child element
	void DeleteLine( int i );
     
	//! Detach and delete 'arg' if it's one of the Line child elements
	void DeleteLine( Ann3DCrosshatchLine *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DCrosshatchGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DCrosshatchGroup;


////////////////////////////////////////////////////////////////////////////////////
//! CrosshatchPatternDefinition class
/*!
\verbatim

      A Crosshatch pattern definition.

      Attributes:

      name:                     Inherited from AttribOwner.

      Sub-elements:

      Group:                    One or more Crosshatch line groups.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CrosshatchPatternDefinition : public AttribOwner
{
public:
     
    //! Default constructor
    CrosshatchPatternDefinition( );
     
    //! Constructs a CrosshatchPatternDefinition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CrosshatchPatternDefinition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CrosshatchPatternDefinition();

private:

	//! Assignment operator
	CrosshatchPatternDefinition& operator=( const CrosshatchPatternDefinition& iSrc );

	//! Copy constructor
	CrosshatchPatternDefinition( const CrosshatchPatternDefinition& original );
     
public:

	//! Add Group child element to this CrosshatchPatternDefinition. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DCrosshatchGroup *AddGroup();
     
	//! Add 'arg' as Group child element to this CrosshatchPatternDefinition.
	plmxml_api::Result AddGroup( Ann3DCrosshatchGroup *arg );

	//! Detach and delete all Group child elements.
	void DeleteGroups();
     
	//! Get number of Group child elements.
	int NumberOfGroups() const;
     
	//! Get i'th Group child element.
	Ann3DCrosshatchGroup *GetGroup( int i ) const;
     
	//! Get all Group child element as an array
	void GetGroups( plmxml_api::Array<Ann3DCrosshatchGroup*> &array ) const;
	     
	//! Detach and delete i'th Group child element
	void DeleteGroup( int i );
     
	//! Detach and delete 'arg' if it's one of the Group child elements
	void DeleteGroup( Ann3DCrosshatchGroup *arg );
 
// <PLMXML_UserCode type="functionHeaderCrosshatchPatternDefinition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCrosshatchPatternDefinition;


////////////////////////////////////////////////////////////////////////////////////
//! ParameterDimension class
/*!
\verbatim

      A Parameter Dimension.

      Attributes:

      parameter:        The parameter that the Parameter Dimension represents.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API ParameterDimension : public Dimension
{
public:
     
    //! Default constructor
    ParameterDimension( );
     
    //! Constructs a ParameterDimension with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ParameterDimension( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ParameterDimension();

private:

	//! Assignment operator
	ParameterDimension& operator=( const ParameterDimension& iSrc );

	//! Copy constructor
	ParameterDimension( const ParameterDimension& original );
     
public:

	//! Set Parameter
	plmxml_api::Result SetParameter( const eAnn3DDimensionParameterEnum& arg );

	//! Get Parameter
	eAnn3DDimensionParameterEnum GetParameter() const;
 
// <PLMXML_UserCode type="functionHeaderParameterDimension" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassParameterDimension;


////////////////////////////////////////////////////////////////////////////////////
//! ParameterDimensionInstance class
/*!
\verbatim

      An Instance of a Parameter Dimension.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API ParameterDimensionInstance : public Ann3DInstance
{
public:
     
    //! Default constructor
    ParameterDimensionInstance( );
     
    //! Constructs a ParameterDimensionInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ParameterDimensionInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ParameterDimensionInstance();

private:

	//! Assignment operator
	ParameterDimensionInstance& operator=( const ParameterDimensionInstance& iSrc );

	//! Copy constructor
	ParameterDimensionInstance( const ParameterDimensionInstance& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderParameterDimensionInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassParameterDimensionInstance;


////////////////////////////////////////////////////////////////////////////////////
//! CalloutDimension class
/*!
\verbatim

      A Callout Dimension.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CalloutDimension : public Dimension
{
public:
     
    //! Default constructor
    CalloutDimension( );
     
    //! Constructs a CalloutDimension with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CalloutDimension( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CalloutDimension();

private:

	//! Assignment operator
	CalloutDimension& operator=( const CalloutDimension& iSrc );

	//! Copy constructor
	CalloutDimension( const CalloutDimension& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderCalloutDimension" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCalloutDimension;


////////////////////////////////////////////////////////////////////////////////////
//! CalloutDimensionDisplay class
/*!
\verbatim

      A Callout Dimension Display.

      Attributes:

      parameterSpaceFactor: The space between the parameters of a callout
                        dimension.
      parameterLineFactor: The space between the lines of the parameters of a
                        callout dimension.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CalloutDimensionDisplay : public DimensionDisplay
{
public:
     
    //! Default constructor
    CalloutDimensionDisplay( );
     
    //! Constructs a CalloutDimensionDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CalloutDimensionDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CalloutDimensionDisplay();

private:

	//! Assignment operator
	CalloutDimensionDisplay& operator=( const CalloutDimensionDisplay& iSrc );

	//! Copy constructor
	CalloutDimensionDisplay( const CalloutDimensionDisplay& original );
     
public:

	//! Set ParameterLineFactor
	plmxml_api::Result SetParameterLineFactor( double arg );

     //! Get ParameterLineFactor
	double GetParameterLineFactor() const;

	//! Check if ParameterLineFactor is set
	plmxml_api::logical HasParameterLineFactor() const;

	//! Unset ParameterLineFactor
	plmxml_api::Result UnsetParameterLineFactor();

	//! Set ParameterSpaceFactor
	plmxml_api::Result SetParameterSpaceFactor( double arg );

     //! Get ParameterSpaceFactor
	double GetParameterSpaceFactor() const;

	//! Check if ParameterSpaceFactor is set
	plmxml_api::logical HasParameterSpaceFactor() const;

	//! Unset ParameterSpaceFactor
	plmxml_api::Result UnsetParameterSpaceFactor();
 
// <PLMXML_UserCode type="functionHeaderCalloutDimensionDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCalloutDimensionDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! CalloutDimensionInstance class
/*!
\verbatim

      An Instance of a Callout Dimension.

      Attributes:

      parameterDimensionInstanceRefs: References the defining
                        ParameterDimensionInstance elements.
     
\endverbatim
*/
class PLMXML_ANNOTATION60_API CalloutDimensionInstance : public Ann3DInstance
{
public:
     
    //! Default constructor
    CalloutDimensionInstance( );
     
    //! Constructs a CalloutDimensionInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CalloutDimensionInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CalloutDimensionInstance();

private:

	//! Assignment operator
	CalloutDimensionInstance& operator=( const CalloutDimensionInstance& iSrc );

	//! Copy constructor
	CalloutDimensionInstance( const CalloutDimensionInstance& original );
     
public:

	//! Get number of URIs in ParameterDimensionInstance
	int NumberOfParameterDimensionInstanceURIs() const;

	//! Get i'th URI in ParameterDimensionInstance
	plmxml_api::String GetParameterDimensionInstanceURI( int i ) const;

	//! Add a URI to ParameterDimensionInstance array. Call ResolveParameterDimensionInstanceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddParameterDimensionInstanceURI( const plmxml_api::String& u );

	//! Set i'th URI in ParameterDimensionInstance array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetParameterDimensionInstanceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ParameterDimensionInstance URI. Does not resolve the URI.
	plmxml_api::Result GetParameterDimensionInstanceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ParameterDimensionInstance array.
	plmxml_api::Result AddParameterDimensionInstanceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ParameterDimensionInstance array to point to 'handle'.
	plmxml_api::Result SetParameterDimensionInstanceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ParameterDimensionInstance points to.
	plmxml_api::Result ResolveParameterDimensionInstanceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ParameterDimensionInstance array.
	plmxml_api::Result DeleteParameterDimensionInstanceURI( int i );

	//! Remove all URIs from ParameterDimensionInstance array.
	plmxml_api::Result DeleteParameterDimensionInstanceURIs( );
	
	//! Check if ParameterDimensionInstance is set
	plmxml_api::logical HasParameterDimensionInstanceURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderCalloutDimensionInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCalloutDimensionInstance;


////////////////////////////////////////////////////////////////////////////////////
//! Chamfer class
/*!
\verbatim

      A Chamfer Dimension.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Chamfer : public Dimension
{
public:
     
    //! Default constructor
    Chamfer( );
     
    //! Constructs a Chamfer with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Chamfer( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Chamfer();

private:

	//! Assignment operator
	Chamfer& operator=( const Chamfer& iSrc );

	//! Copy constructor
	Chamfer( const Chamfer& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderChamfer" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassChamfer;


////////////////////////////////////////////////////////////////////////////////////
//! ChamferDisplay class
/*!
\verbatim

      A Chamfer Dimension Display.

      Attributes:

      chamferDisplayType: How a Chamfer Dimension is displayed.
      chamferLeaderType: How the Leader of a Chamfer Dimension is displayed.
      chamferSymbolType: How any Chamfer Dimension symbol is displayed.
      chamferSeparatorCapital: When chamferDisplayType is sizeAngle or
                        angleSize, chamferSeparatorCapital specifies whether the
                        separator is displayed in upper or lower case.
      chamferSpacing:   Specifies the spacing between the characters or symbols
                        and the chamfer dimension as a multiple of the character
                        size.

      Sub-elements:

      ChamferSymbol:    Specifies the prefix or suffix characters when
                        chamferSymbolType is set to prefix or suffix.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API ChamferDisplay : public DimensionDisplay
{
public:
     
    //! Default constructor
    ChamferDisplay( );
     
    //! Constructs a ChamferDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChamferDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChamferDisplay();

private:

	//! Assignment operator
	ChamferDisplay& operator=( const ChamferDisplay& iSrc );

	//! Copy constructor
	ChamferDisplay( const ChamferDisplay& original );
     
public:

	//! Set ChamferDisplayType
	plmxml_api::Result SetChamferDisplayType( const eAnn3DChamferDisplayEnum& arg );

	//! Get ChamferDisplayType
	eAnn3DChamferDisplayEnum GetChamferDisplayType() const;

	//! Set ChamferSymbolType
	plmxml_api::Result SetChamferSymbolType( const eAnn3DChamferSymbolEnum& arg );

	//! Get ChamferSymbolType
	eAnn3DChamferSymbolEnum GetChamferSymbolType() const;

	//! Set ChamferSpacing
	plmxml_api::Result SetChamferSpacing( double arg );

     //! Get ChamferSpacing
	double GetChamferSpacing() const;

	//! Check if ChamferSpacing is set
	plmxml_api::logical HasChamferSpacing() const;

	//! Unset ChamferSpacing
	plmxml_api::Result UnsetChamferSpacing();

	//! Set ChamferLeaderType
	plmxml_api::Result SetChamferLeaderType( const eAnn3DChamferLeaderEnum& arg );

	//! Get ChamferLeaderType
	eAnn3DChamferLeaderEnum GetChamferLeaderType() const;

	//! Set ChamferSeparatorCapital
	plmxml_api::Result SetChamferSeparatorCapital( plmxml_api::logical arg );

	//! Get ChamferSeparatorCapital
	plmxml_api::logical GetChamferSeparatorCapital() const;

	//! Check if ChamferSeparatorCapital is set
	plmxml_api::logical HasChamferSeparatorCapital() const;

	//! Unset ChamferSeparatorCapital
	plmxml_api::Result UnsetChamferSeparatorCapital();

	//! Add ChamferSymbol child element to this ChamferDisplay. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddChamferSymbol();
     
	//! Set ChamferSymbol child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetChamferSymbol( Ann3DText *arg );
     
	//! Get ChamferSymbol child element of this ChamferDisplay.
	Ann3DText *GetChamferSymbol() const;
     
	//! Detach and delete ChamferSymbol child element tree from this ChamferDisplay.
	void DeleteChamferSymbol();
 
// <PLMXML_UserCode type="functionHeaderChamferDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassChamferDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DIntersectionReference class
/*!
\verbatim

      References the intersection of 2 entities by referencing the 2 entities.

      Sub-elements:

      Reference:                The 2 References to the 2 entities.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DIntersectionReference : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DIntersectionReference( );
     
    //! Constructs a Ann3DIntersectionReference with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DIntersectionReference( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DIntersectionReference();

private:

	//! Assignment operator
	Ann3DIntersectionReference& operator=( const Ann3DIntersectionReference& iSrc );

	//! Copy constructor
	Ann3DIntersectionReference( const Ann3DIntersectionReference& original );
     
public:

	//! Add Reference child element to this Ann3DIntersectionReference. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddReference();
     
	//! Add 'arg' as Reference child element to this Ann3DIntersectionReference.
	plmxml_api::Result AddReference( GDEReference *arg );

	//! Detach and delete all Reference child elements.
	void DeleteReferences();
     
	//! Get number of Reference child elements.
	int NumberOfReferences() const;
     
	//! Get i'th Reference child element.
	GDEReference *GetReference( int i ) const;
     
	//! Get all Reference child element as an array
	void GetReferences( plmxml_api::Array<GDEReference*> &array ) const;
	     
	//! Detach and delete i'th Reference child element
	void DeleteReference( int i );
     
	//! Detach and delete 'arg' if it's one of the Reference child elements
	void DeleteReference( GDEReference *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DIntersectionReference" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DIntersectionReference;


//! Forward class declarations
class Ann3DTableColumn;
class Ann3DTableRow;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTable class
/*!
\verbatim

      A Table Annotation.

      Attributes:

      columnCount:      The number of columns in the table.
      rowCount:         The number of rows in the table.
      allAround:        Whether the All Around symbol is added.

      Sub-elements:

      Column:           The default formatting and content for the columns of
                        the table.
      Row:              The default formatting and content for the rows of the
                        table. The formatting and content for the individual
                        cells of the table.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTable : public Annotation3D
{
public:
     
    //! Default constructor
    Ann3DTable( );
     
    //! Constructs a Ann3DTable with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTable( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTable();

private:

	//! Assignment operator
	Ann3DTable& operator=( const Ann3DTable& iSrc );

	//! Copy constructor
	Ann3DTable( const Ann3DTable& original );
     
public:

	//! Set ColumnCount
	plmxml_api::Result SetColumnCount( int arg );
     
	//! Get ColumnCount
	int GetColumnCount() const;
     
	//! Check if ColumnCount is set
	plmxml_api::logical HasColumnCount() const;
     
	//! Unset ColumnCount
	plmxml_api::Result UnsetColumnCount();

	//! Set AllAround
	plmxml_api::Result SetAllAround( plmxml_api::logical arg );

	//! Get AllAround
	plmxml_api::logical GetAllAround() const;

	//! Check if AllAround is set
	plmxml_api::logical HasAllAround() const;

	//! Unset AllAround
	plmxml_api::Result UnsetAllAround();

	//! Set RowCount
	plmxml_api::Result SetRowCount( int arg );
     
	//! Get RowCount
	int GetRowCount() const;
     
	//! Check if RowCount is set
	plmxml_api::logical HasRowCount() const;
     
	//! Unset RowCount
	plmxml_api::Result UnsetRowCount();

	//! Add Column child element to this Ann3DTable. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTableColumn *AddColumn();
     
	//! Add 'arg' as Column child element to this Ann3DTable.
	plmxml_api::Result AddColumn( Ann3DTableColumn *arg );

	//! Detach and delete all Column child elements.
	void DeleteColumns();
     
	//! Get number of Column child elements.
	int NumberOfColumns() const;
     
	//! Get i'th Column child element.
	Ann3DTableColumn *GetColumn( int i ) const;
     
	//! Get all Column child element as an array
	void GetColumns( plmxml_api::Array<Ann3DTableColumn*> &array ) const;
	     
	//! Detach and delete i'th Column child element
	void DeleteColumn( int i );
     
	//! Detach and delete 'arg' if it's one of the Column child elements
	void DeleteColumn( Ann3DTableColumn *arg );

	//! Add Row child element to this Ann3DTable. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTableRow *AddRow();
     
	//! Add 'arg' as Row child element to this Ann3DTable.
	plmxml_api::Result AddRow( Ann3DTableRow *arg );

	//! Detach and delete all Row child elements.
	void DeleteRows();
     
	//! Get number of Row child elements.
	int NumberOfRows() const;
     
	//! Get i'th Row child element.
	Ann3DTableRow *GetRow( int i ) const;
     
	//! Get all Row child element as an array
	void GetRows( plmxml_api::Array<Ann3DTableRow*> &array ) const;
	     
	//! Detach and delete i'th Row child element
	void DeleteRow( int i );
     
	//! Detach and delete 'arg' if it's one of the Row child elements
	void DeleteRow( Ann3DTableRow *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DTable" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTable;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTableDisplay class
/*!
\verbatim

      A Table Annotation Display.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTableDisplay : public Ann3DDisplay
{
public:
     
    //! Default constructor
    Ann3DTableDisplay( );
     
    //! Constructs a Ann3DTableDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTableDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTableDisplay();

private:

	//! Assignment operator
	Ann3DTableDisplay& operator=( const Ann3DTableDisplay& iSrc );

	//! Copy constructor
	Ann3DTableDisplay( const Ann3DTableDisplay& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnn3DTableDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTableDisplay;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTableColumn class
/*!
\verbatim

      Defines the default formatting and content for a Table Annotation column.

      Attributes:

      displayRef:       References a TableDisplay, which holds the default
                        display properties common to the column.
      index:            The index number of the column.
      width:            The default width of the column in metres.

      Sub-elements:

      ColumnValue:      The default value and references common to the column.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTableColumn : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DTableColumn( );
     
    //! Constructs a Ann3DTableColumn with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTableColumn( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTableColumn();

private:

	//! Assignment operator
	Ann3DTableColumn& operator=( const Ann3DTableColumn& iSrc );

	//! Copy constructor
	Ann3DTableColumn( const Ann3DTableColumn& original );
     
public:

	//! Set Index
	plmxml_api::Result SetIndex( int arg );
     
	//! Get Index
	int GetIndex() const;
     
	//! Check if Index is set
	plmxml_api::logical HasIndex() const;
     
	//! Unset Index
	plmxml_api::Result UnsetIndex();

	//! Set Width
	plmxml_api::Result SetWidth( double arg );

     //! Get Width
	double GetWidth() const;

	//! Check if Width is set
	plmxml_api::logical HasWidth() const;

	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Get Display URI as plmxml_api::String
	plmxml_api::String GetDisplayURI() const;

	//! Set Display URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of Display URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Display URI. URI string is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve Display URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Display URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayURI();
	
	//! Check if Display URI is set
	plmxml_api::logical HasDisplayURI( ) const;
	

	//! Add ColumnValue child element to this Ann3DTableColumn. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddColumnValue();
     
	//! Add 'arg' as ColumnValue child element to this Ann3DTableColumn.
	plmxml_api::Result AddColumnValue( UserValue *arg );

	//! Detach and delete all ColumnValue child elements.
	void DeleteColumnValues();
     
	//! Get number of ColumnValue child elements.
	int NumberOfColumnValues() const;
     
	//! Get i'th ColumnValue child element.
	UserValue *GetColumnValue( int i ) const;
     
	//! Get all ColumnValue child element as an array
	void GetColumnValues( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th ColumnValue child element
	void DeleteColumnValue( int i );
     
	//! Detach and delete 'arg' if it's one of the ColumnValue child elements
	void DeleteColumnValue( UserValue *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DTableColumn" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTableColumn;


//! Forward class declarations
class Ann3DTableCell;

////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTableRow class
/*!
\verbatim

      Defines the default formatting and content for a Table Annotation row.
      Contains the formatting and content for the individual Table Annotation
      cells.

      Attributes:

      header:           Whether the row is a header row.
      displayRef:       References a TableDisplay, which holds the default
                        display properties common to the row.
      index:            The index number of the row.
      height:           The default height of the row in metres.

      Sub-elements:

      RowValue:         The default value and references common to the row.
      Cell:             The formatting and content for the individual cells of
                        the table.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTableRow : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DTableRow( );
     
    //! Constructs a Ann3DTableRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTableRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTableRow();

private:

	//! Assignment operator
	Ann3DTableRow& operator=( const Ann3DTableRow& iSrc );

	//! Copy constructor
	Ann3DTableRow( const Ann3DTableRow& original );
     
public:

	//! Set Height
	plmxml_api::Result SetHeight( double arg );

     //! Get Height
	double GetHeight() const;

	//! Check if Height is set
	plmxml_api::logical HasHeight() const;

	//! Unset Height
	plmxml_api::Result UnsetHeight();

	//! Set Header
	plmxml_api::Result SetHeader( plmxml_api::logical arg );

	//! Get Header
	plmxml_api::logical GetHeader() const;

	//! Check if Header is set
	plmxml_api::logical HasHeader() const;

	//! Unset Header
	plmxml_api::Result UnsetHeader();

	//! Get Display URI as plmxml_api::String
	plmxml_api::String GetDisplayURI() const;

	//! Set Display URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of Display URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Display URI. URI string is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve Display URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Display URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayURI();
	
	//! Check if Display URI is set
	plmxml_api::logical HasDisplayURI( ) const;
	

	//! Set Index
	plmxml_api::Result SetIndex( int arg );
     
	//! Get Index
	int GetIndex() const;
     
	//! Check if Index is set
	plmxml_api::logical HasIndex() const;
     
	//! Unset Index
	plmxml_api::Result UnsetIndex();

	//! Add RowValue child element to this Ann3DTableRow. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddRowValue();
     
	//! Add 'arg' as RowValue child element to this Ann3DTableRow.
	plmxml_api::Result AddRowValue( UserValue *arg );

	//! Detach and delete all RowValue child elements.
	void DeleteRowValues();
     
	//! Get number of RowValue child elements.
	int NumberOfRowValues() const;
     
	//! Get i'th RowValue child element.
	UserValue *GetRowValue( int i ) const;
     
	//! Get all RowValue child element as an array
	void GetRowValues( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th RowValue child element
	void DeleteRowValue( int i );
     
	//! Detach and delete 'arg' if it's one of the RowValue child elements
	void DeleteRowValue( UserValue *arg );

	//! Add Cell child element to this Ann3DTableRow. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DTableCell *AddCell();
     
	//! Add 'arg' as Cell child element to this Ann3DTableRow.
	plmxml_api::Result AddCell( Ann3DTableCell *arg );

	//! Detach and delete all Cell child elements.
	void DeleteCells();
     
	//! Get number of Cell child elements.
	int NumberOfCells() const;
     
	//! Get i'th Cell child element.
	Ann3DTableCell *GetCell( int i ) const;
     
	//! Get all Cell child element as an array
	void GetCells( plmxml_api::Array<Ann3DTableCell*> &array ) const;
	     
	//! Detach and delete i'th Cell child element
	void DeleteCell( int i );
     
	//! Detach and delete 'arg' if it's one of the Cell child elements
	void DeleteCell( Ann3DTableCell *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DTableRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTableRow;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DTableCell class
/*!
\verbatim

      A Table Annotation Cell.

      Attributes:

      displayRef:       References a TableDisplay, which holds the display
                        properties of the cell.
      index:            The column index of the cell within the containing row.
      mergeAcross:      The number of adjacent cells across from the cell to
                        merge.
      mergeDown:        The number of adjacent cells below the cell to merge.

      Sub-elements:

      CellValue:        The value and any references of the cell.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DTableCell : public AttribOwner
{
public:
     
    //! Default constructor
    Ann3DTableCell( );
     
    //! Constructs a Ann3DTableCell with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DTableCell( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DTableCell();

private:

	//! Assignment operator
	Ann3DTableCell& operator=( const Ann3DTableCell& iSrc );

	//! Copy constructor
	Ann3DTableCell( const Ann3DTableCell& original );
     
public:

	//! Set Index
	plmxml_api::Result SetIndex( int arg );
     
	//! Get Index
	int GetIndex() const;
     
	//! Check if Index is set
	plmxml_api::logical HasIndex() const;
     
	//! Unset Index
	plmxml_api::Result UnsetIndex();

	//! Get Display URI as plmxml_api::String
	plmxml_api::String GetDisplayURI() const;

	//! Set Display URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::String& );
	
	//! Get the handle of Display URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Display URI. URI string is unchanged.
	plmxml_api::Result SetDisplayURI( const plmxml_api::Handle& );
	
	//! Resolve Display URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Display URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayURI();
	
	//! Check if Display URI is set
	plmxml_api::logical HasDisplayURI( ) const;
	

	//! Set MergeDown
	plmxml_api::Result SetMergeDown( int arg );
     
	//! Get MergeDown
	int GetMergeDown() const;
     
	//! Check if MergeDown is set
	plmxml_api::logical HasMergeDown() const;
     
	//! Unset MergeDown
	plmxml_api::Result UnsetMergeDown();

	//! Set MergeAcross
	plmxml_api::Result SetMergeAcross( int arg );
     
	//! Get MergeAcross
	int GetMergeAcross() const;
     
	//! Check if MergeAcross is set
	plmxml_api::logical HasMergeAcross() const;
     
	//! Unset MergeAcross
	plmxml_api::Result UnsetMergeAcross();

	//! Add CellValue child element to this Ann3DTableCell. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddCellValue();
     
	//! Add 'arg' as CellValue child element to this Ann3DTableCell.
	plmxml_api::Result AddCellValue( UserValue *arg );

	//! Detach and delete all CellValue child elements.
	void DeleteCellValues();
     
	//! Get number of CellValue child elements.
	int NumberOfCellValues() const;
     
	//! Get i'th CellValue child element.
	UserValue *GetCellValue( int i ) const;
     
	//! Get all CellValue child element as an array
	void GetCellValues( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th CellValue child element
	void DeleteCellValue( int i );
     
	//! Detach and delete 'arg' if it's one of the CellValue child elements
	void DeleteCellValue( UserValue *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DTableCell" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DTableCell;


////////////////////////////////////////////////////////////////////////////////////
//! Ann3DUnit class
/*!
\verbatim

      Unit with a textual representation of the unit symbol.

      Sub-elements:

      Symbol:           The symbol for the unit. For compound units (like
                        degrees, minutes and seconds) more than one is
                        permitted.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API Ann3DUnit : public Unit
{
public:
     
    //! Default constructor
    Ann3DUnit( );
     
    //! Constructs a Ann3DUnit with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ann3DUnit( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ann3DUnit();

private:

	//! Assignment operator
	Ann3DUnit& operator=( const Ann3DUnit& iSrc );

	//! Copy constructor
	Ann3DUnit( const Ann3DUnit& original );
     
public:

	//! Add Symbol child element to this Ann3DUnit. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Ann3DText *AddSymbol();
     
	//! Add 'arg' as Symbol child element to this Ann3DUnit.
	plmxml_api::Result AddSymbol( Ann3DText *arg );

	//! Detach and delete all Symbol child elements.
	void DeleteSymbols();
     
	//! Get number of Symbol child elements.
	int NumberOfSymbols() const;
     
	//! Get i'th Symbol child element.
	Ann3DText *GetSymbol( int i ) const;
     
	//! Get all Symbol child element as an array
	void GetSymbols( plmxml_api::Array<Ann3DText*> &array ) const;
	     
	//! Detach and delete i'th Symbol child element
	void DeleteSymbol( int i );
     
	//! Detach and delete 'arg' if it's one of the Symbol child elements
	void DeleteSymbol( Ann3DText *arg );
 
// <PLMXML_UserCode type="functionHeaderAnn3DUnit" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassAnn3DUnit;


////////////////////////////////////////////////////////////////////////////////////
//! ParameterFitDesignation class
/*!
\verbatim

      A Parameter FitDesignation.

      Attributes:

      parameter:        The parameter that the Parameter FitDesignation
                        represents.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API ParameterFitDesignation : public FitDesignation
{
public:
     
    //! Default constructor
    ParameterFitDesignation( );
     
    //! Constructs a ParameterFitDesignation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ParameterFitDesignation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ParameterFitDesignation();

private:

	//! Assignment operator
	ParameterFitDesignation& operator=( const ParameterFitDesignation& iSrc );

	//! Copy constructor
	ParameterFitDesignation( const ParameterFitDesignation& original );
     
public:

	//! Set Parameter
	plmxml_api::Result SetParameter( const eAnn3DDimensionParameterEnum& arg );

	//! Get Parameter
	eAnn3DDimensionParameterEnum GetParameter() const;
 
// <PLMXML_UserCode type="functionHeaderParameterFitDesignation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassParameterFitDesignation;


////////////////////////////////////////////////////////////////////////////////////
//! CalloutFitDesignation class
/*!
\verbatim

      A Callout FitDesignation.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CalloutFitDesignation : public FitDesignation
{
public:
     
    //! Default constructor
    CalloutFitDesignation( );
     
    //! Constructs a CalloutFitDesignation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CalloutFitDesignation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CalloutFitDesignation();

private:

	//! Assignment operator
	CalloutFitDesignation& operator=( const CalloutFitDesignation& iSrc );

	//! Copy constructor
	CalloutFitDesignation( const CalloutFitDesignation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderCalloutFitDesignation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCalloutFitDesignation;


////////////////////////////////////////////////////////////////////////////////////
//! CalloutFitDesignationDisplay class
/*!
\verbatim

      A Callout FitDesignation Display.

      Attributes:

      parameterSpaceFactor: The space between the parameters of a callout
                        fit designation.
      parameterLineFactor: The space between the lines of the parameters of a
                        callout fit designation.
      
\endverbatim
*/
class PLMXML_ANNOTATION60_API CalloutFitDesignationDisplay : public FitDesignationDisplay
{
public:
     
    //! Default constructor
    CalloutFitDesignationDisplay( );
     
    //! Constructs a CalloutFitDesignationDisplay with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CalloutFitDesignationDisplay( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CalloutFitDesignationDisplay();

private:

	//! Assignment operator
	CalloutFitDesignationDisplay& operator=( const CalloutFitDesignationDisplay& iSrc );

	//! Copy constructor
	CalloutFitDesignationDisplay( const CalloutFitDesignationDisplay& original );
     
public:

	//! Set ParameterLineFactor
	plmxml_api::Result SetParameterLineFactor( double arg );

     //! Get ParameterLineFactor
	double GetParameterLineFactor() const;

	//! Check if ParameterLineFactor is set
	plmxml_api::logical HasParameterLineFactor() const;

	//! Unset ParameterLineFactor
	plmxml_api::Result UnsetParameterLineFactor();

	//! Set ParameterSpaceFactor
	plmxml_api::Result SetParameterSpaceFactor( double arg );

     //! Get ParameterSpaceFactor
	double GetParameterSpaceFactor() const;

	//! Check if ParameterSpaceFactor is set
	plmxml_api::logical HasParameterSpaceFactor() const;

	//! Unset ParameterSpaceFactor
	plmxml_api::Result UnsetParameterSpaceFactor();
 
// <PLMXML_UserCode type="functionHeaderCalloutFitDesignationDisplay" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ANNOTATION60_API plmxml_api::plmxmlClass plmxmlClassCalloutFitDesignationDisplay;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
