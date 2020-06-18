/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.15175 03/04/2012 09:16:13
// 
// Schema:	PLMXMLMechatronicsSchema.xsd
// Data:	03/04/2012 09:16:12
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_MECHATRONICS60_H__
#define __PLMXML_MECHATRONICS60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_MECHATRONICS60_EXPORTS
#define PLMXML_MECHATRONICS60_API __declspec(dllexport)
#else
#define PLMXML_MECHATRONICS60_API __declspec(dllimport)
#endif
#else
#define PLMXML_MECHATRONICS60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>

#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
// TODO: Add extra include headers within this block
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
////////////////////////////////////////////////////////////////////////////////////
//! LocationAssigment class
/*!
	@deprecated Use the plmxml60::LocationAssignment class instead.
*/
class PLMXML_MECHATRONICS60_API LocationAssigment : public GeneralRelation
{
public:
     
    LocationAssigment( );     
    LocationAssigment( plmxml_api::Object* parent );
         
    virtual ~LocationAssigment();

private:

	LocationAssigment& operator=( const LocationAssigment& iSrc );
	LocationAssigment( const LocationAssigment& original );     
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassLocationAssigment;
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eWireProtectionTapingEnum class
/*!
Allowed Values:
\verbatim
  eWireProtectionTapingEnumRight
	"right"
  eWireProtectionTapingEnumLeft
	"left"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eWireProtectionTapingEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWireProtectionTapingEnum( const char* Type );
     
	//! Constructor
	eWireProtectionTapingEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWireProtectionTapingEnum( );
     
	//! Destructor 
	virtual ~eWireProtectionTapingEnum( );
     
	//! Assign from 'Type'
	const eWireProtectionTapingEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWireProtectionTapingEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WireProtectionTapingEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eWireProtectionTapingEnum& e1, const eWireProtectionTapingEnum& e2 );
     
	//! Compare WireProtectionTapingEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eWireProtectionTapingEnum& e1, const eWireProtectionTapingEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWireProtectionTapingEnum;
extern PLMXML_MECHATRONICS60_API eWireProtectionTapingEnum eWireProtectionTapingEnumUnset;
extern PLMXML_MECHATRONICS60_API eWireProtectionTapingEnum eWireProtectionTapingEnumRight;
extern PLMXML_MECHATRONICS60_API eWireProtectionTapingEnum eWireProtectionTapingEnumLeft;

////////////////////////////////////////////////////////////////////////////////////
//! eTemperatureEnum class
/*!
Allowed Values:
\verbatim
  eTemperatureEnumOperating
	"operating"
  eTemperatureEnumStorage
	"storage"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eTemperatureEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTemperatureEnum( const char* Type );
     
	//! Constructor
	eTemperatureEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTemperatureEnum( );
     
	//! Destructor 
	virtual ~eTemperatureEnum( );
     
	//! Assign from 'Type'
	const eTemperatureEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTemperatureEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TemperatureEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eTemperatureEnum& e1, const eTemperatureEnum& e2 );
     
	//! Compare TemperatureEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eTemperatureEnum& e1, const eTemperatureEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTemperatureEnum;
extern PLMXML_MECHATRONICS60_API eTemperatureEnum eTemperatureEnumUnset;
extern PLMXML_MECHATRONICS60_API eTemperatureEnum eTemperatureEnumOperating;
extern PLMXML_MECHATRONICS60_API eTemperatureEnum eTemperatureEnumStorage;

////////////////////////////////////////////////////////////////////////////////////
//! eSoftwareEnum class
/*!
Allowed Values:
\verbatim
  eSoftwareEnumCalibration
	"calibration"
  eSoftwareEnumApplication
	"application"
  eSoftwareEnumConfiguration
	"configuration"
  eSoftwareEnumBootLoader
	"bootLoader"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eSoftwareEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSoftwareEnum( const char* Type );
     
	//! Constructor
	eSoftwareEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSoftwareEnum( );
     
	//! Destructor 
	virtual ~eSoftwareEnum( );
     
	//! Assign from 'Type'
	const eSoftwareEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSoftwareEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SoftwareEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eSoftwareEnum& e1, const eSoftwareEnum& e2 );
     
	//! Compare SoftwareEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eSoftwareEnum& e1, const eSoftwareEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSoftwareEnum;
extern PLMXML_MECHATRONICS60_API eSoftwareEnum eSoftwareEnumUnset;
extern PLMXML_MECHATRONICS60_API eSoftwareEnum eSoftwareEnumCalibration;
extern PLMXML_MECHATRONICS60_API eSoftwareEnum eSoftwareEnumApplication;
extern PLMXML_MECHATRONICS60_API eSoftwareEnum eSoftwareEnumConfiguration;
extern PLMXML_MECHATRONICS60_API eSoftwareEnum eSoftwareEnumBootLoader;

////////////////////////////////////////////////////////////////////////////////////
//! eRatedVoltageEnum class
/*!
Allowed Values:
\verbatim
  eRatedVoltageEnumAc5Phase
	"ac5Phase"
  eRatedVoltageEnumAc3Phase
	"ac3Phase"
  eRatedVoltageEnumDc
	"dc"
  eRatedVoltageEnumAcSinglePhase
	"acSinglePhase"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eRatedVoltageEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRatedVoltageEnum( const char* Type );
     
	//! Constructor
	eRatedVoltageEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRatedVoltageEnum( );
     
	//! Destructor 
	virtual ~eRatedVoltageEnum( );
     
	//! Assign from 'Type'
	const eRatedVoltageEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRatedVoltageEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RatedVoltageEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eRatedVoltageEnum& e1, const eRatedVoltageEnum& e2 );
     
	//! Compare RatedVoltageEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eRatedVoltageEnum& e1, const eRatedVoltageEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRatedVoltageEnum;
extern PLMXML_MECHATRONICS60_API eRatedVoltageEnum eRatedVoltageEnumUnset;
extern PLMXML_MECHATRONICS60_API eRatedVoltageEnum eRatedVoltageEnumAc5Phase;
extern PLMXML_MECHATRONICS60_API eRatedVoltageEnum eRatedVoltageEnumAc3Phase;
extern PLMXML_MECHATRONICS60_API eRatedVoltageEnum eRatedVoltageEnumDc;
extern PLMXML_MECHATRONICS60_API eRatedVoltageEnum eRatedVoltageEnumAcSinglePhase;

////////////////////////////////////////////////////////////////////////////////////
//! eRatedCurrentEnum class
/*!
Allowed Values:
\verbatim
  eRatedCurrentEnumAc5Phase
	"ac5Phase"
  eRatedCurrentEnumAc3Phase
	"ac3Phase"
  eRatedCurrentEnumDc
	"dc"
  eRatedCurrentEnumAcSinglePhase
	"acSinglePhase"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eRatedCurrentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRatedCurrentEnum( const char* Type );
     
	//! Constructor
	eRatedCurrentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRatedCurrentEnum( );
     
	//! Destructor 
	virtual ~eRatedCurrentEnum( );
     
	//! Assign from 'Type'
	const eRatedCurrentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRatedCurrentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RatedCurrentEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eRatedCurrentEnum& e1, const eRatedCurrentEnum& e2 );
     
	//! Compare RatedCurrentEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eRatedCurrentEnum& e1, const eRatedCurrentEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRatedCurrentEnum;
extern PLMXML_MECHATRONICS60_API eRatedCurrentEnum eRatedCurrentEnumUnset;
extern PLMXML_MECHATRONICS60_API eRatedCurrentEnum eRatedCurrentEnumAc5Phase;
extern PLMXML_MECHATRONICS60_API eRatedCurrentEnum eRatedCurrentEnumAc3Phase;
extern PLMXML_MECHATRONICS60_API eRatedCurrentEnum eRatedCurrentEnumDc;
extern PLMXML_MECHATRONICS60_API eRatedCurrentEnum eRatedCurrentEnumAcSinglePhase;

////////////////////////////////////////////////////////////////////////////////////
//! eProcessorArchitectureEnum class
/*!
Allowed Values:
\verbatim
  eProcessorArchitectureEnumBits32
	"bits32"
  eProcessorArchitectureEnumBits64
	"bits64"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eProcessorArchitectureEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eProcessorArchitectureEnum( const char* Type );
     
	//! Constructor
	eProcessorArchitectureEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eProcessorArchitectureEnum( );
     
	//! Destructor 
	virtual ~eProcessorArchitectureEnum( );
     
	//! Assign from 'Type'
	const eProcessorArchitectureEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eProcessorArchitectureEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ProcessorArchitectureEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eProcessorArchitectureEnum& e1, const eProcessorArchitectureEnum& e2 );
     
	//! Compare ProcessorArchitectureEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eProcessorArchitectureEnum& e1, const eProcessorArchitectureEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumProcessorArchitectureEnum;
extern PLMXML_MECHATRONICS60_API eProcessorArchitectureEnum eProcessorArchitectureEnumUnset;
extern PLMXML_MECHATRONICS60_API eProcessorArchitectureEnum eProcessorArchitectureEnumBits32;
extern PLMXML_MECHATRONICS60_API eProcessorArchitectureEnum eProcessorArchitectureEnumBits64;

////////////////////////////////////////////////////////////////////////////////////
//! eCoordinateExtentEnum class
/*!
Allowed Values:
\verbatim
  eCoordinateExtentEnumZ
	"z"
  eCoordinateExtentEnumX
	"x"
  eCoordinateExtentEnumY
	"y"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eCoordinateExtentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCoordinateExtentEnum( const char* Type );
     
	//! Constructor
	eCoordinateExtentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCoordinateExtentEnum( );
     
	//! Destructor 
	virtual ~eCoordinateExtentEnum( );
     
	//! Assign from 'Type'
	const eCoordinateExtentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCoordinateExtentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CoordinateExtentEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eCoordinateExtentEnum& e1, const eCoordinateExtentEnum& e2 );
     
	//! Compare CoordinateExtentEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eCoordinateExtentEnum& e1, const eCoordinateExtentEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCoordinateExtentEnum;
extern PLMXML_MECHATRONICS60_API eCoordinateExtentEnum eCoordinateExtentEnumUnset;
extern PLMXML_MECHATRONICS60_API eCoordinateExtentEnum eCoordinateExtentEnumZ;
extern PLMXML_MECHATRONICS60_API eCoordinateExtentEnum eCoordinateExtentEnumX;
extern PLMXML_MECHATRONICS60_API eCoordinateExtentEnum eCoordinateExtentEnumY;

////////////////////////////////////////////////////////////////////////////////////
//! eProcessorByteOrderEnum class
/*!
Allowed Values:
\verbatim
  eProcessorByteOrderEnumLittleEndian
	"littleEndian"
  eProcessorByteOrderEnumBigEndian
	"bigEndian"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eProcessorByteOrderEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eProcessorByteOrderEnum( const char* Type );
     
	//! Constructor
	eProcessorByteOrderEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eProcessorByteOrderEnum( );
     
	//! Destructor 
	virtual ~eProcessorByteOrderEnum( );
     
	//! Assign from 'Type'
	const eProcessorByteOrderEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eProcessorByteOrderEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ProcessorByteOrderEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eProcessorByteOrderEnum& e1, const eProcessorByteOrderEnum& e2 );
     
	//! Compare ProcessorByteOrderEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eProcessorByteOrderEnum& e1, const eProcessorByteOrderEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumProcessorByteOrderEnum;
extern PLMXML_MECHATRONICS60_API eProcessorByteOrderEnum eProcessorByteOrderEnumUnset;
extern PLMXML_MECHATRONICS60_API eProcessorByteOrderEnum eProcessorByteOrderEnumLittleEndian;
extern PLMXML_MECHATRONICS60_API eProcessorByteOrderEnum eProcessorByteOrderEnumBigEndian;

////////////////////////////////////////////////////////////////////////////////////
//! eHarnessProductTypeEnum class
/*!
Allowed Values:
\verbatim
  eHarnessProductTypeEnumModule
	"module"
  eHarnessProductTypeEnumAccessory
	"accessory"
  eHarnessProductTypeEnumConnectorHousing
	"connectorHousing"
  eHarnessProductTypeEnumWireProtection
	"wireProtection"
  eHarnessProductTypeEnumTerminal
	"terminal"
  eHarnessProductTypeEnumComposite
	"composite"
  eHarnessProductTypeEnumConnectorCavitySeal
	"connectorCavitySeal"
  eHarnessProductTypeEnumConnectorCavityPlug
	"connectorCavityPlug"
  eHarnessProductTypeEnumHarness
	"harness"
  eHarnessProductTypeEnumGeneral
	"general"
  eHarnessProductTypeEnumFixing
	"fixing"
  eHarnessProductTypeEnumWire
	"wire"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eHarnessProductTypeEnum( const char* Type );
     
	//! Constructor
	eHarnessProductTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eHarnessProductTypeEnum( );
     
	//! Destructor 
	virtual ~eHarnessProductTypeEnum( );
     
	//! Assign from 'Type'
	const eHarnessProductTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eHarnessProductTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare HarnessProductTypeEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eHarnessProductTypeEnum& e1, const eHarnessProductTypeEnum& e2 );
     
	//! Compare HarnessProductTypeEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eHarnessProductTypeEnum& e1, const eHarnessProductTypeEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumHarnessProductTypeEnum;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumUnset;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumModule;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumAccessory;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumConnectorHousing;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumWireProtection;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumTerminal;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumComposite;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumConnectorCavitySeal;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumConnectorCavityPlug;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumHarness;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumGeneral;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumFixing;
extern PLMXML_MECHATRONICS60_API eHarnessProductTypeEnum eHarnessProductTypeEnumWire;

////////////////////////////////////////////////////////////////////////////////////
//! eRatedPowerEnum class
/*!
Allowed Values:
\verbatim
  eRatedPowerEnumTruePower
	"truePower"
  eRatedPowerEnumApparentPower
	"apparentPower"
  eRatedPowerEnumReactivePower
	"reactivePower"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eRatedPowerEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRatedPowerEnum( const char* Type );
     
	//! Constructor
	eRatedPowerEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRatedPowerEnum( );
     
	//! Destructor 
	virtual ~eRatedPowerEnum( );
     
	//! Assign from 'Type'
	const eRatedPowerEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRatedPowerEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RatedPowerEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eRatedPowerEnum& e1, const eRatedPowerEnum& e2 );
     
	//! Compare RatedPowerEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eRatedPowerEnum& e1, const eRatedPowerEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRatedPowerEnum;
extern PLMXML_MECHATRONICS60_API eRatedPowerEnum eRatedPowerEnumUnset;
extern PLMXML_MECHATRONICS60_API eRatedPowerEnum eRatedPowerEnumTruePower;
extern PLMXML_MECHATRONICS60_API eRatedPowerEnum eRatedPowerEnumApparentPower;
extern PLMXML_MECHATRONICS60_API eRatedPowerEnum eRatedPowerEnumReactivePower;

////////////////////////////////////////////////////////////////////////////////////
//! eRouteLineTypeEnum class
/*!
Allowed Values:
\verbatim
  eRouteLineTypeEnumDashed
	"dashed"
  eRouteLineTypeEnumSolid
	"solid"
  eRouteLineTypeEnumThin
	"thin"
  
\endverbatim
*/
class PLMXML_MECHATRONICS60_API eRouteLineTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRouteLineTypeEnum( const char* Type );
     
	//! Constructor
	eRouteLineTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRouteLineTypeEnum( );
     
	//! Destructor 
	virtual ~eRouteLineTypeEnum( );
     
	//! Assign from 'Type'
	const eRouteLineTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRouteLineTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RouteLineTypeEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator==( const eRouteLineTypeEnum& e1, const eRouteLineTypeEnum& e2 );
     
	//! Compare RouteLineTypeEnum
	friend plmxml_api::logical PLMXML_MECHATRONICS60_API operator!=( const eRouteLineTypeEnum& e1, const eRouteLineTypeEnum& e2 );
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRouteLineTypeEnum;
extern PLMXML_MECHATRONICS60_API eRouteLineTypeEnum eRouteLineTypeEnumUnset;
extern PLMXML_MECHATRONICS60_API eRouteLineTypeEnum eRouteLineTypeEnumDashed;
extern PLMXML_MECHATRONICS60_API eRouteLineTypeEnum eRouteLineTypeEnumSolid;
extern PLMXML_MECHATRONICS60_API eRouteLineTypeEnum eRouteLineTypeEnumThin;

////////////////////////////////////////////////////////////////////////////////////
//! Signal class
/*!
\verbatim

      A Signal is a message or flow of information within a system.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Signal : public Structure
{
public:
     
    //! Default constructor
    Signal( );
     
    //! Constructs a Signal with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Signal( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Signal();

private:

	//! Assignment operator
	Signal& operator=( const Signal& iSrc );

	//! Copy constructor
	Signal( const Signal& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderSignal" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSignal;


////////////////////////////////////////////////////////////////////////////////////
//! SignalRevision class
/*!
\verbatim

      This is a revision of a Signal.
      
      Attributes:
     
      valueRef:         Reference to a 'default' SignalValue
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API SignalRevision : public StructureRevision
{
public:
     
    //! Default constructor
    SignalRevision( );
     
    //! Constructs a SignalRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SignalRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SignalRevision();

private:

	//! Assignment operator
	SignalRevision& operator=( const SignalRevision& iSrc );

	//! Copy constructor
	SignalRevision( const SignalRevision& original );
     
public:

	//! Get Value URI as plmxml_api::String
	plmxml_api::String GetValueURI() const;

	//! Set Value URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetValueURI( const plmxml_api::String& );
	
	//! Get the handle of Value URI. Does not resolve the URI.
	plmxml_api::Result GetValueURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Value URI. URI string is unchanged.
	plmxml_api::Result SetValueURI( const plmxml_api::Handle& );
	
	//! Resolve Value URI and return an object (handle) it points to.
	plmxml_api::Result ResolveValueURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Value URI. Clears URI string and handle.
	plmxml_api::Result DeleteValueURI();
	
	//! Check if Value URI is set
	plmxml_api::logical HasValueURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderSignalRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSignalRevision;


////////////////////////////////////////////////////////////////////////////////////
//! SignalValue class
/*!
\verbatim

      This is a value of a Signal, e.g. "10.2 volts".
      
      Attributes:
      
      valueRef:         Reference to a ValueWithUnit or RangeWithUnit giving the signal value.
      characteristic:   Describes how the signal value depends on the value of 
                        the corresponding ProcessVariable. There is one predefined value,
                        namely "linear".
      characteristicRef: References a multiple language version of
                        characteristic. If multiple language support is
                        required, characteristicRef should be used in addition
                        to characteristic.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API SignalValue : public AttribOwner
{
public:
     
    //! Default constructor
    SignalValue( );
     
    //! Constructs a SignalValue with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SignalValue( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SignalValue();

private:

	//! Assignment operator
	SignalValue& operator=( const SignalValue& iSrc );

	//! Copy constructor
	SignalValue( const SignalValue& original );
     
public:

	//! Get Value URI as plmxml_api::String
	plmxml_api::String GetValueURI() const;

	//! Set Value URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetValueURI( const plmxml_api::String& );
	
	//! Get the handle of Value URI. Does not resolve the URI.
	plmxml_api::Result GetValueURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Value URI. URI string is unchanged.
	plmxml_api::Result SetValueURI( const plmxml_api::Handle& );
	
	//! Resolve Value URI and return an object (handle) it points to.
	plmxml_api::Result ResolveValueURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Value URI. Clears URI string and handle.
	plmxml_api::Result DeleteValueURI();
	
	//! Check if Value URI is set
	plmxml_api::logical HasValueURI( ) const;
	

	//! Get Characteristic of this SignalValue
	plmxml_api::String GetCharacteristic() const;

	//! Set Characteristic of this SignalValue
	plmxml_api::Result SetCharacteristic( const plmxml_api::String &s );
	
	//! Check if Characteristic is set
	plmxml_api::logical HasCharacteristic( ) const;
	
	//! Unset Characteristic
	plmxml_api::Result UnsetCharacteristic( );

	//! Get Characteristic URI as plmxml_api::String
	plmxml_api::String GetCharacteristicURI() const;

	//! Set Characteristic URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCharacteristicURI( const plmxml_api::String& );
	
	//! Get the handle of Characteristic URI. Does not resolve the URI.
	plmxml_api::Result GetCharacteristicURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Characteristic URI. URI string is unchanged.
	plmxml_api::Result SetCharacteristicURI( const plmxml_api::Handle& );
	
	//! Resolve Characteristic URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCharacteristicURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Characteristic URI. Clears URI string and handle.
	plmxml_api::Result DeleteCharacteristicURI();
	
	//! Check if Characteristic URI is set
	plmxml_api::logical HasCharacteristicURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderSignalValue" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSignalValue;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessVariable class
/*!
\verbatim

      The ProcessVariable is a sub-class of GDE. It corresponds to the ProcessVariable
      object in STEP AP212, where it is defined as 'a parameter used to control or monitor
      a process'.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API ProcessVariable : public GDE
{
public:
     
    //! Default constructor
    ProcessVariable( );
     
    //! Constructs a ProcessVariable with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessVariable( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessVariable();

private:

	//! Assignment operator
	ProcessVariable& operator=( const ProcessVariable& iSrc );

	//! Copy constructor
	ProcessVariable( const ProcessVariable& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcessVariable" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassProcessVariable;


////////////////////////////////////////////////////////////////////////////////////
//! GeneralRelationGroup class
/*!
\verbatim

      This element is a group of GeneralRelation elements.
        
      Attributes:
      
      groupId:          The identifier of the GeneralRelationGroup, unique in some context, e.g. an 
                        Organisation.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API GeneralRelationGroup : public Managed
{
public:
     
    //! Default constructor
    GeneralRelationGroup( );
     
    //! Constructs a GeneralRelationGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GeneralRelationGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GeneralRelationGroup();

private:

	//! Assignment operator
	GeneralRelationGroup& operator=( const GeneralRelationGroup& iSrc );

	//! Copy constructor
	GeneralRelationGroup( const GeneralRelationGroup& original );
     
public:

	//! Get GroupId of this GeneralRelationGroup
	plmxml_api::String GetGroupId() const;

	//! Set GroupId of this GeneralRelationGroup
	plmxml_api::Result SetGroupId( const plmxml_api::String &s );
	
	//! Check if GroupId is set
	plmxml_api::logical HasGroupId( ) const;
	
	//! Unset GroupId
	plmxml_api::Result UnsetGroupId( );
 
// <PLMXML_UserCode type="functionHeaderGeneralRelationGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassGeneralRelationGroup;


////////////////////////////////////////////////////////////////////////////////////
//! AllocationGroup class
/*!
\verbatim

      This element is a group of Allocation elements.
        
      Attributes:
      
      sourceRef:        The source ProductStructureView.
      targetRef:        The target ProductStructureView.
      structureRefs:    The referenced ProductStructureViews.
      
      Either sourceRef and targetRef should be set, or, structureRefs should be set. They
      should not be used together. 
      
      The Allocations in the AllocationGroup should all reference Occurrences which have
      one of the referenced ProductStructureViews as their root. An Allocation may reference
      more than one Occurrence with the same root.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API AllocationGroup : public GeneralRelationGroup
{
public:
     
    //! Default constructor
    AllocationGroup( );
     
    //! Constructs a AllocationGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AllocationGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AllocationGroup();

private:

	//! Assignment operator
	AllocationGroup& operator=( const AllocationGroup& iSrc );

	//! Copy constructor
	AllocationGroup( const AllocationGroup& original );
     
public:

	//! Get number of URIs in Structure
	int NumberOfStructureURIs() const;

	//! Get i'th URI in Structure
	plmxml_api::String GetStructureURI( int i ) const;

	//! Add a URI to Structure array. Call ResolveStructureURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddStructureURI( const plmxml_api::String& u );

	//! Set i'th URI in Structure array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetStructureURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Structure URI. Does not resolve the URI.
	plmxml_api::Result GetStructureURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Structure array.
	plmxml_api::Result AddStructureURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Structure array to point to 'handle'.
	plmxml_api::Result SetStructureURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Structure points to.
	plmxml_api::Result ResolveStructureURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Structure array.
	plmxml_api::Result DeleteStructureURI( int i );

	//! Remove all URIs from Structure array.
	plmxml_api::Result DeleteStructureURIs( );
	
	//! Check if Structure is set
	plmxml_api::logical HasStructureURIs( ) const;

	//! Get Target URI as plmxml_api::String
	plmxml_api::String GetTargetURI() const;

	//! Set Target URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTargetURI( const plmxml_api::String& );
	
	//! Get the handle of Target URI. Does not resolve the URI.
	plmxml_api::Result GetTargetURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Target URI. URI string is unchanged.
	plmxml_api::Result SetTargetURI( const plmxml_api::Handle& );
	
	//! Resolve Target URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTargetURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Target URI. Clears URI string and handle.
	plmxml_api::Result DeleteTargetURI();
	
	//! Check if Target URI is set
	plmxml_api::logical HasTargetURI( ) const;
	

	//! Get Source URI as plmxml_api::String
	plmxml_api::String GetSourceURI() const;

	//! Set Source URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSourceURI( const plmxml_api::String& );
	
	//! Get the handle of Source URI. Does not resolve the URI.
	plmxml_api::Result GetSourceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Source URI. URI string is unchanged.
	plmxml_api::Result SetSourceURI( const plmxml_api::Handle& );
	
	//! Resolve Source URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSourceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Source URI. Clears URI string and handle.
	plmxml_api::Result DeleteSourceURI();
	
	//! Check if Source URI is set
	plmxml_api::logical HasSourceURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderAllocationGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassAllocationGroup;


////////////////////////////////////////////////////////////////////////////////////
//! GeneralRelationGroupRevision class
/*!
\verbatim

      This is a revision of an GeneralRelationGroup.
      
      Attributes:
      
      revision:         The revision string, e.g. "A".
      masterRef:        The master GeneralRelationGroup
      memberRefs:       The GeneralRelation elements in the Group.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API GeneralRelationGroupRevision : public Managed
{
public:
     
    //! Default constructor
    GeneralRelationGroupRevision( );
     
    //! Constructs a GeneralRelationGroupRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GeneralRelationGroupRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GeneralRelationGroupRevision();

private:

	//! Assignment operator
	GeneralRelationGroupRevision& operator=( const GeneralRelationGroupRevision& iSrc );

	//! Copy constructor
	GeneralRelationGroupRevision( const GeneralRelationGroupRevision& original );
     
public:

	//! Get Master URI as plmxml_api::String
	plmxml_api::String GetMasterURI() const;

	//! Set Master URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMasterURI( const plmxml_api::String& );
	
	//! Get the handle of Master URI. Does not resolve the URI.
	plmxml_api::Result GetMasterURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Master URI. URI string is unchanged.
	plmxml_api::Result SetMasterURI( const plmxml_api::Handle& );
	
	//! Resolve Master URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMasterURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Master URI. Clears URI string and handle.
	plmxml_api::Result DeleteMasterURI();
	
	//! Check if Master URI is set
	plmxml_api::logical HasMasterURI( ) const;
	

	//! Get number of URIs in Member
	int NumberOfMemberURIs() const;

	//! Get i'th URI in Member
	plmxml_api::String GetMemberURI( int i ) const;

	//! Add a URI to Member array. Call ResolveMemberURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddMemberURI( const plmxml_api::String& u );

	//! Set i'th URI in Member array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetMemberURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Member URI. Does not resolve the URI.
	plmxml_api::Result GetMemberURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Member array.
	plmxml_api::Result AddMemberURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Member array to point to 'handle'.
	plmxml_api::Result SetMemberURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Member points to.
	plmxml_api::Result ResolveMemberURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Member array.
	plmxml_api::Result DeleteMemberURI( int i );

	//! Remove all URIs from Member array.
	plmxml_api::Result DeleteMemberURIs( );
	
	//! Check if Member is set
	plmxml_api::logical HasMemberURIs( ) const;

	//! Get Revision of this GeneralRelationGroupRevision
	plmxml_api::String GetRevision() const;

	//! Set Revision of this GeneralRelationGroupRevision
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );
 
// <PLMXML_UserCode type="functionHeaderGeneralRelationGroupRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassGeneralRelationGroupRevision;


////////////////////////////////////////////////////////////////////////////////////
//! AllocationGroupRevision class
/*!
\verbatim

      This element is a revision of an AllocationGroup.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API AllocationGroupRevision : public GeneralRelationGroupRevision
{
public:
     
    //! Default constructor
    AllocationGroupRevision( );
     
    //! Constructs a AllocationGroupRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AllocationGroupRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AllocationGroupRevision();

private:

	//! Assignment operator
	AllocationGroupRevision& operator=( const AllocationGroupRevision& iSrc );

	//! Copy constructor
	AllocationGroupRevision( const AllocationGroupRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAllocationGroupRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassAllocationGroupRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Allocation class
/*!
\verbatim

      An Allocation is a relation between a number of Occurrences, in different Views of the 
      same Product, or different Views of different Products. The 'relatedRefs' attribute of 
      the base GeneralRelation element will contain the referenced Occurrences.
      
      Elements:
      
      Reason            the reason for the Allocation. There is one predefined value
                        for this string, namely "functionalToPhysical", which may be
                        used if the Allocation represents the equivalent of the AP212
                        functional_unit_allocation.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Allocation : public GeneralRelation
{
public:
     
    //! Default constructor
    Allocation( );
     
    //! Constructs a Allocation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Allocation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Allocation();

private:

	//! Assignment operator
	Allocation& operator=( const Allocation& iSrc );

	//! Copy constructor
	Allocation( const Allocation& original );
     
public:

	//! Add Reason child element to this Allocation. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserEnum *AddReason();
     
	//! Set Reason child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetReason( UserEnum *arg );
     
	//! Get Reason child element of this Allocation.
	UserEnum *GetReason() const;
     
	//! Detach and delete Reason child element tree from this Allocation.
	void DeleteReason();
 
// <PLMXML_UserCode type="functionHeaderAllocation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassAllocation;


////////////////////////////////////////////////////////////////////////////////////
//! Terminal class
/*!
\verbatim

      The Terminal is a sub-class of GDE. It corresponds to the Interface_terminal
      object in STEP AP212, and represents 'an access point for a piece of equipment'.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Terminal : public GDE
{
public:
     
    //! Default constructor
    Terminal( );
     
    //! Constructs a Terminal with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Terminal( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Terminal();

private:

	//! Assignment operator
	Terminal& operator=( const Terminal& iSrc );

	//! Copy constructor
	Terminal( const Terminal& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTerminal" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassTerminal;


////////////////////////////////////////////////////////////////////////////////////
//! FlowConnection class
/*!
\verbatim

      This is a sub-class of Connection which corresponds to the AP212 Location,
      which "allows the flow of energy or information, for instance".
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API FlowConnection : public Connection
{
public:
     
    //! Default constructor
    FlowConnection( );
     
    //! Constructs a FlowConnection with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FlowConnection( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FlowConnection();

private:

	//! Assignment operator
	FlowConnection& operator=( const FlowConnection& iSrc );

	//! Copy constructor
	FlowConnection( const FlowConnection& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFlowConnection" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassFlowConnection;


////////////////////////////////////////////////////////////////////////////////////
//! FlowConnectionRevision class
/*!
\verbatim

\endverbatim
*/
class PLMXML_MECHATRONICS60_API FlowConnectionRevision : public ConnectionRevision
{
public:
     
    //! Default constructor
    FlowConnectionRevision( );
     
    //! Constructs a FlowConnectionRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FlowConnectionRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FlowConnectionRevision();

private:

	//! Assignment operator
	FlowConnectionRevision& operator=( const FlowConnectionRevision& iSrc );

	//! Copy constructor
	FlowConnectionRevision( const FlowConnectionRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFlowConnectionRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassFlowConnectionRevision;


////////////////////////////////////////////////////////////////////////////////////
//! FlowConnectionRevisionView class
/*!
\verbatim

\endverbatim
*/
class PLMXML_MECHATRONICS60_API FlowConnectionRevisionView : public ConnectionRevisionView
{
public:
     
    //! Default constructor
    FlowConnectionRevisionView( );
     
    //! Constructs a FlowConnectionRevisionView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FlowConnectionRevisionView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FlowConnectionRevisionView();

private:

	//! Assignment operator
	FlowConnectionRevisionView& operator=( const FlowConnectionRevisionView& iSrc );

	//! Copy constructor
	FlowConnectionRevisionView( const FlowConnectionRevisionView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFlowConnectionRevisionView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassFlowConnectionRevisionView;


//! Forward class declarations
class RouteDataSegment;

////////////////////////////////////////////////////////////////////////////////////
//! RouteData class
/*!
\verbatim

      A RouteData element is used to assign routing information to an Instance or Occurrence.
      
      Elements:
      
      RouteDataSegment:  the RouteDataSegments which define the routes of the various segments 
                         of the object, in sequence.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RouteData : public AttribOwner
{
public:
     
    //! Default constructor
    RouteData( );
     
    //! Constructs a RouteData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteData();

private:

	//! Assignment operator
	RouteData& operator=( const RouteData& iSrc );

	//! Copy constructor
	RouteData( const RouteData& original );
     
public:

	//! Add RouteDataSegment child element to this RouteData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RouteDataSegment *AddRouteDataSegment();
     
	//! Add 'arg' as RouteDataSegment child element to this RouteData.
	plmxml_api::Result AddRouteDataSegment( RouteDataSegment *arg );

	//! Detach and delete all RouteDataSegment child elements.
	void DeleteRouteDataSegments();
     
	//! Get number of RouteDataSegment child elements.
	int NumberOfRouteDataSegments() const;
     
	//! Get i'th RouteDataSegment child element.
	RouteDataSegment *GetRouteDataSegment( int i ) const;
     
	//! Get all RouteDataSegment child element as an array
	void GetRouteDataSegments( plmxml_api::Array<RouteDataSegment*> &array ) const;
	     
	//! Detach and delete i'th RouteDataSegment child element
	void DeleteRouteDataSegment( int i );
     
	//! Detach and delete 'arg' if it's one of the RouteDataSegment child elements
	void DeleteRouteDataSegment( RouteDataSegment *arg );
 
// <PLMXML_UserCode type="functionHeaderRouteData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRouteData;


////////////////////////////////////////////////////////////////////////////////////
//! RouteDataSegment class
/*!
\verbatim

      A RouteDataSegment is used to assign routing information to a segment of an
      Instance or Occurrence.
      
      Attributes:
      
      courseRefs:   the RouteNodes, RouteSections and Routes which define the route of this segment
                    of the  object, in sequence.
      free:         false if the segment has a fixed route in space - true if it is free, such as a
                    freely hanging wire.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RouteDataSegment : public DescriptionObject
{
public:
     
    //! Default constructor
    RouteDataSegment( );
     
    //! Constructs a RouteDataSegment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteDataSegment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteDataSegment();

private:

	//! Assignment operator
	RouteDataSegment& operator=( const RouteDataSegment& iSrc );

	//! Copy constructor
	RouteDataSegment( const RouteDataSegment& original );
     
public:

	//! Get number of URIs in Course
	int NumberOfCourseURIs() const;

	//! Get i'th URI in Course
	plmxml_api::String GetCourseURI( int i ) const;

	//! Add a URI to Course array. Call ResolveCourseURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCourseURI( const plmxml_api::String& u );

	//! Set i'th URI in Course array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCourseURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Course URI. Does not resolve the URI.
	plmxml_api::Result GetCourseURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Course array.
	plmxml_api::Result AddCourseURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Course array to point to 'handle'.
	plmxml_api::Result SetCourseURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Course points to.
	plmxml_api::Result ResolveCourseURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Course array.
	plmxml_api::Result DeleteCourseURI( int i );

	//! Remove all URIs from Course array.
	plmxml_api::Result DeleteCourseURIs( );
	
	//! Check if Course is set
	plmxml_api::logical HasCourseURIs( ) const;

	//! Set Free
	plmxml_api::Result SetFree( plmxml_api::logical arg );

	//! Get Free
	plmxml_api::logical GetFree() const;

	//! Check if Free is set
	plmxml_api::logical HasFree() const;

	//! Unset Free
	plmxml_api::Result UnsetFree();
 
// <PLMXML_UserCode type="functionHeaderRouteDataSegment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRouteDataSegment;


////////////////////////////////////////////////////////////////////////////////////
//! Route class
/*!
\verbatim

      A Route represents a course or track through space.
      
      Attributes:
      
      courseRefs:    the RouteSections and/or RouteNodes that make up the Route, in order.
      revision:      a revision string.
      colour:        display colour
      lineType:      display line type
      lineThicknessRef: display line thickness (ValueWithUnit).
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Route : public Managed
{
public:
     
    //! Default constructor
    Route( );
     
    //! Constructs a Route with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Route( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Route();

private:

	//! Assignment operator
	Route& operator=( const Route& iSrc );

	//! Copy constructor
	Route( const Route& original );
     
public:

	//! Set LineType
	plmxml_api::Result SetLineType( const eRouteLineTypeEnum& arg );

	//! Get LineType
	eRouteLineTypeEnum GetLineType() const;

	//! Get number of URIs in Course
	int NumberOfCourseURIs() const;

	//! Get i'th URI in Course
	plmxml_api::String GetCourseURI( int i ) const;

	//! Add a URI to Course array. Call ResolveCourseURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCourseURI( const plmxml_api::String& u );

	//! Set i'th URI in Course array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCourseURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Course URI. Does not resolve the URI.
	plmxml_api::Result GetCourseURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Course array.
	plmxml_api::Result AddCourseURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Course array to point to 'handle'.
	plmxml_api::Result SetCourseURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Course points to.
	plmxml_api::Result ResolveCourseURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Course array.
	plmxml_api::Result DeleteCourseURI( int i );

	//! Remove all URIs from Course array.
	plmxml_api::Result DeleteCourseURIs( );
	
	//! Check if Course is set
	plmxml_api::logical HasCourseURIs( ) const;

	//! Set Colour array
	plmxml_api::Result SetColour( const double *arg );

	//! Get Colour array
	plmxml_api::Result GetColour( double *arg ) const;

	//! Check if Colour array is set
	plmxml_api::logical HasColour() const;

	//! Unset Colour array
	plmxml_api::Result UnsetColour();

	//! Get Revision of this Route
	plmxml_api::String GetRevision() const;

	//! Set Revision of this Route
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

	//! Get LineThickness URI as plmxml_api::String
	plmxml_api::String GetLineThicknessURI() const;

	//! Set LineThickness URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetLineThicknessURI( const plmxml_api::String& );
	
	//! Get the handle of LineThickness URI. Does not resolve the URI.
	plmxml_api::Result GetLineThicknessURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of LineThickness URI. URI string is unchanged.
	plmxml_api::Result SetLineThicknessURI( const plmxml_api::Handle& );
	
	//! Resolve LineThickness URI and return an object (handle) it points to.
	plmxml_api::Result ResolveLineThicknessURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset LineThickness URI. Clears URI string and handle.
	plmxml_api::Result DeleteLineThicknessURI();
	
	//! Check if LineThickness URI is set
	plmxml_api::logical HasLineThicknessURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderRoute" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRoute;


////////////////////////////////////////////////////////////////////////////////////
//! RouteSection class
/*!
\verbatim

      A RouteSection represents a section of a Route, from one Node to the next.
      
      Attributes:
      
      startNodeRef:  the Node at the start.
      endNodeRef:    the Node at the end. Note that this can be the same as the Node at 
                     the start.
      startKind:     the shape of the Section at the start. Can be one of "flat oval",
                     "round", "u shape", or some other string.
      endKind:       the shape of the Section at the end. Values as for startKind.
      revision:      a revision string.
      
      curveRef:     reference to a Curve element (or entity in a Representation file)
                    giving the geometric course of the RouteSection.
                    
      crossSectionalAreaRefs: references to ValueWithUnit or RangeWithUnit elements describing 
                     cross-sectional area(s) of the Section.
      lengthRefs:    references to ValueWithUnit or RangeWithUnit elements describing the length(s)
                     of the Section.

      bendingRadiusRefs: references to ValueWithUnit or RangeWithUnit elements describing the bending
                     radius or radii of the Section.
      spaceFactors:  These are double values which represent the ratio(s) of the usable cross-
                     section to the geometrical cross-section along the Section.
      implementationRefs: Occurrences or Instances of ProductRevisionView(s) which implement
                     the RouteSection.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RouteSection : public Managed
{
public:
     
    //! Default constructor
    RouteSection( );
     
    //! Constructs a RouteSection with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteSection( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteSection();

private:

	//! Assignment operator
	RouteSection& operator=( const RouteSection& iSrc );

	//! Copy constructor
	RouteSection( const RouteSection& original );
     
public:

	//! Set SpaceFactors
	plmxml_api::Result SetSpaceFactors( const plmxml_api::Array<double>& arg );

	//! Get SpaceFactors
	plmxml_api::Result GetSpaceFactors( plmxml_api::Array<double>& arg ) const;

	//! Check if SpaceFactors is set
	plmxml_api::logical HasSpaceFactors() const;

	//! Unset SpaceFactors
	plmxml_api::Result UnsetSpaceFactors();

	//! Get EndNode URI as plmxml_api::String
	plmxml_api::String GetEndNodeURI() const;

	//! Set EndNode URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEndNodeURI( const plmxml_api::String& );
	
	//! Get the handle of EndNode URI. Does not resolve the URI.
	plmxml_api::Result GetEndNodeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of EndNode URI. URI string is unchanged.
	plmxml_api::Result SetEndNodeURI( const plmxml_api::Handle& );
	
	//! Resolve EndNode URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEndNodeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset EndNode URI. Clears URI string and handle.
	plmxml_api::Result DeleteEndNodeURI();
	
	//! Check if EndNode URI is set
	plmxml_api::logical HasEndNodeURI( ) const;
	

	//! Get number of URIs in CrossSectionalArea
	int NumberOfCrossSectionalAreaURIs() const;

	//! Get i'th URI in CrossSectionalArea
	plmxml_api::String GetCrossSectionalAreaURI( int i ) const;

	//! Add a URI to CrossSectionalArea array. Call ResolveCrossSectionalAreaURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCrossSectionalAreaURI( const plmxml_api::String& u );

	//! Set i'th URI in CrossSectionalArea array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCrossSectionalAreaURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of CrossSectionalArea URI. Does not resolve the URI.
	plmxml_api::Result GetCrossSectionalAreaURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to CrossSectionalArea array.
	plmxml_api::Result AddCrossSectionalAreaURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in CrossSectionalArea array to point to 'handle'.
	plmxml_api::Result SetCrossSectionalAreaURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in CrossSectionalArea points to.
	plmxml_api::Result ResolveCrossSectionalAreaURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from CrossSectionalArea array.
	plmxml_api::Result DeleteCrossSectionalAreaURI( int i );

	//! Remove all URIs from CrossSectionalArea array.
	plmxml_api::Result DeleteCrossSectionalAreaURIs( );
	
	//! Check if CrossSectionalArea is set
	plmxml_api::logical HasCrossSectionalAreaURIs( ) const;

	//! Get EndKind of this RouteSection
	plmxml_api::String GetEndKind() const;

	//! Set EndKind of this RouteSection
	plmxml_api::Result SetEndKind( const plmxml_api::String &s );
	
	//! Check if EndKind is set
	plmxml_api::logical HasEndKind( ) const;
	
	//! Unset EndKind
	plmxml_api::Result UnsetEndKind( );

	//! Get number of URIs in Length
	int NumberOfLengthURIs() const;

	//! Get i'th URI in Length
	plmxml_api::String GetLengthURI( int i ) const;

	//! Add a URI to Length array. Call ResolveLengthURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddLengthURI( const plmxml_api::String& u );

	//! Set i'th URI in Length array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetLengthURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Length URI. Does not resolve the URI.
	plmxml_api::Result GetLengthURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Length array.
	plmxml_api::Result AddLengthURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Length array to point to 'handle'.
	plmxml_api::Result SetLengthURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Length points to.
	plmxml_api::Result ResolveLengthURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Length array.
	plmxml_api::Result DeleteLengthURI( int i );

	//! Remove all URIs from Length array.
	plmxml_api::Result DeleteLengthURIs( );
	
	//! Check if Length is set
	plmxml_api::logical HasLengthURIs( ) const;

	//! Get StartNode URI as plmxml_api::String
	plmxml_api::String GetStartNodeURI() const;

	//! Set StartNode URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStartNodeURI( const plmxml_api::String& );
	
	//! Get the handle of StartNode URI. Does not resolve the URI.
	plmxml_api::Result GetStartNodeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of StartNode URI. URI string is unchanged.
	plmxml_api::Result SetStartNodeURI( const plmxml_api::Handle& );
	
	//! Resolve StartNode URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStartNodeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset StartNode URI. Clears URI string and handle.
	plmxml_api::Result DeleteStartNodeURI();
	
	//! Check if StartNode URI is set
	plmxml_api::logical HasStartNodeURI( ) const;
	

	//! Get StartKind of this RouteSection
	plmxml_api::String GetStartKind() const;

	//! Set StartKind of this RouteSection
	plmxml_api::Result SetStartKind( const plmxml_api::String &s );
	
	//! Check if StartKind is set
	plmxml_api::logical HasStartKind( ) const;
	
	//! Unset StartKind
	plmxml_api::Result UnsetStartKind( );

	//! Get number of URIs in BendingRadius
	int NumberOfBendingRadiusURIs() const;

	//! Get i'th URI in BendingRadius
	plmxml_api::String GetBendingRadiusURI( int i ) const;

	//! Add a URI to BendingRadius array. Call ResolveBendingRadiusURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddBendingRadiusURI( const plmxml_api::String& u );

	//! Set i'th URI in BendingRadius array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetBendingRadiusURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of BendingRadius URI. Does not resolve the URI.
	plmxml_api::Result GetBendingRadiusURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to BendingRadius array.
	plmxml_api::Result AddBendingRadiusURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in BendingRadius array to point to 'handle'.
	plmxml_api::Result SetBendingRadiusURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in BendingRadius points to.
	plmxml_api::Result ResolveBendingRadiusURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from BendingRadius array.
	plmxml_api::Result DeleteBendingRadiusURI( int i );

	//! Remove all URIs from BendingRadius array.
	plmxml_api::Result DeleteBendingRadiusURIs( );
	
	//! Check if BendingRadius is set
	plmxml_api::logical HasBendingRadiusURIs( ) const;

	//! Get Revision of this RouteSection
	plmxml_api::String GetRevision() const;

	//! Set Revision of this RouteSection
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

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
	

	//! Get number of URIs in Implementation
	int NumberOfImplementationURIs() const;

	//! Get i'th URI in Implementation
	plmxml_api::String GetImplementationURI( int i ) const;

	//! Add a URI to Implementation array. Call ResolveImplementationURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddImplementationURI( const plmxml_api::String& u );

	//! Set i'th URI in Implementation array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetImplementationURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Implementation URI. Does not resolve the URI.
	plmxml_api::Result GetImplementationURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Implementation array.
	plmxml_api::Result AddImplementationURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Implementation array to point to 'handle'.
	plmxml_api::Result SetImplementationURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Implementation points to.
	plmxml_api::Result ResolveImplementationURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Implementation array.
	plmxml_api::Result DeleteImplementationURI( int i );

	//! Remove all URIs from Implementation array.
	plmxml_api::Result DeleteImplementationURIs( );
	
	//! Check if Implementation is set
	plmxml_api::logical HasImplementationURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderRouteSection" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRouteSection;


////////////////////////////////////////////////////////////////////////////////////
//! RouteNode class
/*!
\verbatim

      A RouteNode represents a position along a Route, normally at the end of one
      or more RouteSections.
      
      Attributes:
      
      position:      the x,y,z coordinates of the Node.
      implementationRefs: Occurrences or Instances of ProductRevisionView(s) which implement
                     the RouteNode.

      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RouteNode : public Managed
{
public:
     
    //! Default constructor
    RouteNode( );
     
    //! Constructs a RouteNode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteNode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteNode();

private:

	//! Assignment operator
	RouteNode& operator=( const RouteNode& iSrc );

	//! Copy constructor
	RouteNode( const RouteNode& original );
     
public:

	//! Get number of URIs in Implementation
	int NumberOfImplementationURIs() const;

	//! Get i'th URI in Implementation
	plmxml_api::String GetImplementationURI( int i ) const;

	//! Add a URI to Implementation array. Call ResolveImplementationURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddImplementationURI( const plmxml_api::String& u );

	//! Set i'th URI in Implementation array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetImplementationURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Implementation URI. Does not resolve the URI.
	plmxml_api::Result GetImplementationURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Implementation array.
	plmxml_api::Result AddImplementationURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Implementation array to point to 'handle'.
	plmxml_api::Result SetImplementationURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Implementation points to.
	plmxml_api::Result ResolveImplementationURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Implementation array.
	plmxml_api::Result DeleteImplementationURI( int i );

	//! Remove all URIs from Implementation array.
	plmxml_api::Result DeleteImplementationURIs( );
	
	//! Check if Implementation is set
	plmxml_api::logical HasImplementationURIs( ) const;

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();
 
// <PLMXML_UserCode type="functionHeaderRouteNode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRouteNode;


////////////////////////////////////////////////////////////////////////////////////
//! Location class
/*!
\verbatim

      A Location represents a region of space.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Location : public Structure
{
public:
     
    //! Default constructor
    Location( );
     
    //! Constructs a Location with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Location( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Location();

private:

	//! Assignment operator
	Location& operator=( const Location& iSrc );

	//! Copy constructor
	Location( const Location& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderLocation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassLocation;


////////////////////////////////////////////////////////////////////////////////////
//! LocationRevision class
/*!
\verbatim

      This is a revision of a Location.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API LocationRevision : public StructureRevision
{
public:
     
    //! Default constructor
    LocationRevision( );
     
    //! Constructs a LocationRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LocationRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LocationRevision();

private:

	//! Assignment operator
	LocationRevision& operator=( const LocationRevision& iSrc );

	//! Copy constructor
	LocationRevision( const LocationRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderLocationRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassLocationRevision;


////////////////////////////////////////////////////////////////////////////////////
//! LocationInstance class
/*!
\verbatim

      An Instance of a LocationRevision.
      
      definitionRef:      reference to a ProductRevisionView, or an Instance or Occurrence of
                          a ProductRevisionView, which defines the region of space of this
                          LocationInstance.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API LocationInstance : public Instance
{
public:
     
    //! Default constructor
    LocationInstance( );
     
    //! Constructs a LocationInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LocationInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LocationInstance();

private:

	//! Assignment operator
	LocationInstance& operator=( const LocationInstance& iSrc );

	//! Copy constructor
	LocationInstance( const LocationInstance& original );
     
public:

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
	
 
// <PLMXML_UserCode type="functionHeaderLocationInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassLocationInstance;


////////////////////////////////////////////////////////////////////////////////////
//! LocationAssignment class
/*!
\verbatim

      This relation relates an element to an Instance or Occurrence of a Location.
      The Location specifies the region of space in which the element lies.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API LocationAssignment : public GeneralRelation
{
public:
     
    //! Default constructor
    LocationAssignment( );
     
    //! Constructs a LocationAssignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LocationAssignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LocationAssignment();

private:

	//! Assignment operator
	LocationAssignment& operator=( const LocationAssignment& iSrc );

	//! Copy constructor
	LocationAssignment( const LocationAssignment& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderLocationAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassLocationAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! CrossSectionalArea class
/*!
\verbatim

      This is a Property giving the Cross Sectional Area of an object.
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the cross-sectional area.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API CrossSectionalArea : public Property
{
public:
     
    //! Default constructor
    CrossSectionalArea( );
     
    //! Constructs a CrossSectionalArea with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CrossSectionalArea( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CrossSectionalArea();

private:

	//! Assignment operator
	CrossSectionalArea& operator=( const CrossSectionalArea& iSrc );

	//! Copy constructor
	CrossSectionalArea( const CrossSectionalArea& original );
     
public:

	//! Add ValueWithUnit child element to this CrossSectionalArea. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this CrossSectionalArea.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this CrossSectionalArea.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this CrossSectionalArea. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this CrossSectionalArea.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this CrossSectionalArea.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderCrossSectionalArea" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassCrossSectionalArea;


////////////////////////////////////////////////////////////////////////////////////
//! CoordinateExtent class
/*!
\verbatim

      This Property gives the Coordinate Extent of an element, i.e. the 'length' in a 
      particular coordinate direction.      
      Attributes:
      
      type:           "x", "y" or "z"
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit   one of these sub-elements should be used to indicate the value
                      or range of the CoordinateExtent.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API CoordinateExtent : public Property
{
public:
     
    //! Default constructor
    CoordinateExtent( );
     
    //! Constructs a CoordinateExtent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CoordinateExtent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CoordinateExtent();

private:

	//! Assignment operator
	CoordinateExtent& operator=( const CoordinateExtent& iSrc );

	//! Copy constructor
	CoordinateExtent( const CoordinateExtent& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eCoordinateExtentEnum& arg );

	//! Get Type
	eCoordinateExtentEnum GetType() const;

	//! Add ValueWithUnit child element to this CoordinateExtent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this CoordinateExtent.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this CoordinateExtent.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this CoordinateExtent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this CoordinateExtent.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this CoordinateExtent.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderCoordinateExtent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassCoordinateExtent;


////////////////////////////////////////////////////////////////////////////////////
//! Temperature class
/*!
\verbatim

      This Property gives the Temperature (operating or storage) of an element.
     
      Attributes:
      
      type:          "operating" or "storage"
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the temperature.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Temperature : public Property
{
public:
     
    //! Default constructor
    Temperature( );
     
    //! Constructs a Temperature with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Temperature( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Temperature();

private:

	//! Assignment operator
	Temperature& operator=( const Temperature& iSrc );

	//! Copy constructor
	Temperature( const Temperature& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eTemperatureEnum& arg );

	//! Get Type
	eTemperatureEnum GetType() const;

	//! Add ValueWithUnit child element to this Temperature. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this Temperature.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this Temperature.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this Temperature. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this Temperature.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this Temperature.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderTemperature" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassTemperature;


////////////////////////////////////////////////////////////////////////////////////
//! OutsideDiameter class
/*!
\verbatim

      This Property gives the Outside Diameter of an element.
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the Outside Diameter
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API OutsideDiameter : public Property
{
public:
     
    //! Default constructor
    OutsideDiameter( );
     
    //! Constructs a OutsideDiameter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OutsideDiameter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OutsideDiameter();

private:

	//! Assignment operator
	OutsideDiameter& operator=( const OutsideDiameter& iSrc );

	//! Copy constructor
	OutsideDiameter( const OutsideDiameter& original );
     
public:

	//! Add ValueWithUnit child element to this OutsideDiameter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this OutsideDiameter.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this OutsideDiameter.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this OutsideDiameter. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this OutsideDiameter.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this OutsideDiameter.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderOutsideDiameter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassOutsideDiameter;


////////////////////////////////////////////////////////////////////////////////////
//! RatedCurrent class
/*!
\verbatim

      This Property gives the Rated Current of an element.
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the Rated Current.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RatedCurrent : public Property
{
public:
     
    //! Default constructor
    RatedCurrent( );
     
    //! Constructs a RatedCurrent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RatedCurrent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RatedCurrent();

private:

	//! Assignment operator
	RatedCurrent& operator=( const RatedCurrent& iSrc );

	//! Copy constructor
	RatedCurrent( const RatedCurrent& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eRatedCurrentEnum& arg );

	//! Get Type
	eRatedCurrentEnum GetType() const;

	//! Add ValueWithUnit child element to this RatedCurrent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this RatedCurrent.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this RatedCurrent.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this RatedCurrent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this RatedCurrent.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this RatedCurrent.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderRatedCurrent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRatedCurrent;


////////////////////////////////////////////////////////////////////////////////////
//! RatedVoltage class
/*!
\verbatim

      This Property gives the Rated Voltage of an element.
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the Rated Voltage.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RatedVoltage : public Property
{
public:
     
    //! Default constructor
    RatedVoltage( );
     
    //! Constructs a RatedVoltage with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RatedVoltage( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RatedVoltage();

private:

	//! Assignment operator
	RatedVoltage& operator=( const RatedVoltage& iSrc );

	//! Copy constructor
	RatedVoltage( const RatedVoltage& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eRatedVoltageEnum& arg );

	//! Get Type
	eRatedVoltageEnum GetType() const;

	//! Add ValueWithUnit child element to this RatedVoltage. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this RatedVoltage.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this RatedVoltage.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this RatedVoltage. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this RatedVoltage.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this RatedVoltage.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderRatedVoltage" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRatedVoltage;


////////////////////////////////////////////////////////////////////////////////////
//! RatedPower class
/*!
\verbatim

      This Property gives the Rated Power of an element.
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the Rated Power.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RatedPower : public Property
{
public:
     
    //! Default constructor
    RatedPower( );
     
    //! Constructs a RatedPower with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RatedPower( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RatedPower();

private:

	//! Assignment operator
	RatedPower& operator=( const RatedPower& iSrc );

	//! Copy constructor
	RatedPower( const RatedPower& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eRatedPowerEnum& arg );

	//! Get Type
	eRatedPowerEnum GetType() const;

	//! Add ValueWithUnit child element to this RatedPower. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this RatedPower.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this RatedPower.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this RatedPower. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this RatedPower.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this RatedPower.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderRatedPower" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRatedPower;


////////////////////////////////////////////////////////////////////////////////////
//! MaterialSpecification class
/*!
\verbatim

      This element specifies the physical material from which an object is made. More than one
      MaterialSpecification can be associated with an object.
      
      Attributes:
      
      materialId:      Id of the material in some materials database.
      referenceSystem: name of the reference system or database in which the material
                       is defined
      usage:           string indicating how the material is used in the object, e.g.
                       "plating".
      patternRef:       References a CrosshatchPatternDefinition, which defines
                        a custom pattern for the crosshatching.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API MaterialSpecification : public Property
{
public:
     
    //! Default constructor
    MaterialSpecification( );
     
    //! Constructs a MaterialSpecification with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MaterialSpecification( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MaterialSpecification();

private:

	//! Assignment operator
	MaterialSpecification& operator=( const MaterialSpecification& iSrc );

	//! Copy constructor
	MaterialSpecification( const MaterialSpecification& original );
     
public:

	//! Get ReferenceSystem of this MaterialSpecification
	plmxml_api::String GetReferenceSystem() const;

	//! Set ReferenceSystem of this MaterialSpecification
	plmxml_api::Result SetReferenceSystem( const plmxml_api::String &s );
	
	//! Check if ReferenceSystem is set
	plmxml_api::logical HasReferenceSystem( ) const;
	
	//! Unset ReferenceSystem
	plmxml_api::Result UnsetReferenceSystem( );

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
	

	//! Get MaterialId of this MaterialSpecification
	plmxml_api::String GetMaterialId() const;

	//! Set MaterialId of this MaterialSpecification
	plmxml_api::Result SetMaterialId( const plmxml_api::String &s );
	
	//! Check if MaterialId is set
	plmxml_api::logical HasMaterialId( ) const;
	
	//! Unset MaterialId
	plmxml_api::Result UnsetMaterialId( );

	//! Get Usage of this MaterialSpecification
	plmxml_api::String GetUsage() const;

	//! Set Usage of this MaterialSpecification
	plmxml_api::Result SetUsage( const plmxml_api::String &s );
	
	//! Check if Usage is set
	plmxml_api::logical HasUsage( ) const;
	
	//! Unset Usage
	plmxml_api::Result UnsetUsage( );
 
// <PLMXML_UserCode type="functionHeaderMaterialSpecification" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassMaterialSpecification;


////////////////////////////////////////////////////////////////////////////////////
//! WireGauge class
/*!
\verbatim

      This element specifies the gauge of a Wire.
      
      Attributes:
      
      value:           the gauge value.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API WireGauge : public Property
{
public:
     
    //! Default constructor
    WireGauge( );
     
    //! Constructs a WireGauge with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WireGauge( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WireGauge();

private:

	//! Assignment operator
	WireGauge& operator=( const WireGauge& iSrc );

	//! Copy constructor
	WireGauge( const WireGauge& original );
     
public:

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();
 
// <PLMXML_UserCode type="functionHeaderWireGauge" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassWireGauge;


////////////////////////////////////////////////////////////////////////////////////
//! HarnessProduct class
/*!
\verbatim

      This is a subclass of Product which corresponds to a Product related to electrical
      Harness definition, as for example defined in the KBL standard.
      
      Attributes:
      
      type:               An enum specifying the type of Product.
      harnessProductType: A further string describing the type of product, e.g.
                          "flat band" or "corrugated pipe".
      code:               a code for the Product. Only relevant where type="connectorHousing"
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API HarnessProduct : public Product
{
public:
     
    //! Default constructor
    HarnessProduct( );
     
    //! Constructs a HarnessProduct with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HarnessProduct( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HarnessProduct();

private:

	//! Assignment operator
	HarnessProduct& operator=( const HarnessProduct& iSrc );

	//! Copy constructor
	HarnessProduct( const HarnessProduct& original );
     
public:

	//! Get Code of this HarnessProduct
	plmxml_api::String GetCode() const;

	//! Set Code of this HarnessProduct
	plmxml_api::Result SetCode( const plmxml_api::String &s );
	
	//! Check if Code is set
	plmxml_api::logical HasCode( ) const;
	
	//! Unset Code
	plmxml_api::Result UnsetCode( );

	//! Get HarnessProductType of this HarnessProduct
	plmxml_api::String GetHarnessProductType() const;

	//! Set HarnessProductType of this HarnessProduct
	plmxml_api::Result SetHarnessProductType( const plmxml_api::String &s );
	
	//! Check if HarnessProductType is set
	plmxml_api::logical HasHarnessProductType( ) const;
	
	//! Unset HarnessProductType
	plmxml_api::Result UnsetHarnessProductType( );

	//! Set Type
	plmxml_api::Result SetType( const eHarnessProductTypeEnum& arg );

	//! Get Type
	eHarnessProductTypeEnum GetType() const;
 
// <PLMXML_UserCode type="functionHeaderHarnessProduct" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassHarnessProduct;


////////////////////////////////////////////////////////////////////////////////////
//! BendRadius class
/*!
\verbatim

      This is a Property giving the minumum Bend Radius of an object.
      
      Attributes:
      
      value:         the value of the Bend Radius in metres.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API BendRadius : public Property
{
public:
     
    //! Default constructor
    BendRadius( );
     
    //! Constructs a BendRadius with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BendRadius( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BendRadius();

private:

	//! Assignment operator
	BendRadius& operator=( const BendRadius& iSrc );

	//! Copy constructor
	BendRadius( const BendRadius& original );
     
public:

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();
 
// <PLMXML_UserCode type="functionHeaderBendRadius" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassBendRadius;


////////////////////////////////////////////////////////////////////////////////////
//! CompatibleWireSize class
/*!
\verbatim

      This is a Property giving the size (diameter) of Wire which is compatible with 
      this Product.
      
      Elements:
      
      ValueWithUnit
      RangeWithUnit  one of these sub-elements should be used to indicate the value
                     or range of the compatible wire size.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API CompatibleWireSize : public Property
{
public:
     
    //! Default constructor
    CompatibleWireSize( );
     
    //! Constructs a CompatibleWireSize with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CompatibleWireSize( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CompatibleWireSize();

private:

	//! Assignment operator
	CompatibleWireSize& operator=( const CompatibleWireSize& iSrc );

	//! Copy constructor
	CompatibleWireSize( const CompatibleWireSize& original );
     
public:

	//! Add ValueWithUnit child element to this CompatibleWireSize. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this CompatibleWireSize.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this CompatibleWireSize.
	void DeleteValueWithUnit();

	//! Add RangeWithUnit child element to this CompatibleWireSize. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this CompatibleWireSize.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this CompatibleWireSize.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderCompatibleWireSize" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassCompatibleWireSize;


////////////////////////////////////////////////////////////////////////////////////
//! Copyright class
/*!
\verbatim

      This is a Property giving a Copyright string for an object.
      
      Attributes:
      
      value:         the value of the Copyright string.
      valueRef:      References a multiple language version of value. If
                     multiple language support is required, valueRef should be
                     used in addition to value.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Copyright : public Property
{
public:
     
    //! Default constructor
    Copyright( );
     
    //! Constructs a Copyright with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Copyright( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Copyright();

private:

	//! Assignment operator
	Copyright& operator=( const Copyright& iSrc );

	//! Copy constructor
	Copyright( const Copyright& original );
     
public:

	//! Get Value URI as plmxml_api::String
	plmxml_api::String GetValueURI() const;

	//! Set Value URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetValueURI( const plmxml_api::String& );
	
	//! Get the handle of Value URI. Does not resolve the URI.
	plmxml_api::Result GetValueURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Value URI. URI string is unchanged.
	plmxml_api::Result SetValueURI( const plmxml_api::Handle& );
	
	//! Resolve Value URI and return an object (handle) it points to.
	plmxml_api::Result ResolveValueURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Value URI. Clears URI string and handle.
	plmxml_api::Result DeleteValueURI();
	
	//! Check if Value URI is set
	plmxml_api::logical HasValueURI( ) const;
	

	//! Get Value of this Copyright
	plmxml_api::String GetValue() const;

	//! Set Value of this Copyright
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderCopyright" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassCopyright;


////////////////////////////////////////////////////////////////////////////////////
//! WireCore class
/*!
\verbatim

      This represents a single wire in a multi-core cable.
      
      Attributes:
      
      wireCoreType:  A string describing the type of Wire Core, e.g.
                     "flat band" or "protected wire".
      wireCoreTypeRef: References a multiple language version of wireCoreType.
                     If multiple language support is required, wireCoreTypeRef
                     should be used in addition to wireCoreType.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API WireCore : public GDE
{
public:
     
    //! Default constructor
    WireCore( );
     
    //! Constructs a WireCore with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WireCore( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WireCore();

private:

	//! Assignment operator
	WireCore& operator=( const WireCore& iSrc );

	//! Copy constructor
	WireCore( const WireCore& original );
     
public:

	//! Get WireCoreType URI as plmxml_api::String
	plmxml_api::String GetWireCoreTypeURI() const;

	//! Set WireCoreType URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWireCoreTypeURI( const plmxml_api::String& );
	
	//! Get the handle of WireCoreType URI. Does not resolve the URI.
	plmxml_api::Result GetWireCoreTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of WireCoreType URI. URI string is unchanged.
	plmxml_api::Result SetWireCoreTypeURI( const plmxml_api::Handle& );
	
	//! Resolve WireCoreType URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWireCoreTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset WireCoreType URI. Clears URI string and handle.
	plmxml_api::Result DeleteWireCoreTypeURI();
	
	//! Check if WireCoreType URI is set
	plmxml_api::logical HasWireCoreTypeURI( ) const;
	

	//! Get WireCoreType of this WireCore
	plmxml_api::String GetWireCoreType() const;

	//! Set WireCoreType of this WireCore
	plmxml_api::Result SetWireCoreType( const plmxml_api::String &s );
	
	//! Check if WireCoreType is set
	plmxml_api::logical HasWireCoreType( ) const;
	
	//! Unset WireCoreType
	plmxml_api::Result UnsetWireCoreType( );
 
// <PLMXML_UserCode type="functionHeaderWireCore" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassWireCore;


////////////////////////////////////////////////////////////////////////////////////
//! ConnectorCavityGroup class
/*!
\verbatim

      This represents a group of ConnectorCavities.
      
      Attributes:
      
      connectorCavityGroupType:  A string describing the type of ConnectorCavityGroup
      connectorCavityGroupTypeRef: References a multiple language version of
                      connectorCavityGroupType. If multiple language support is
                      required, connectorCavityGroupTypeRef should be used in
                      addition to connectorCavityGroupType.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API ConnectorCavityGroup : public GDE
{
public:
     
    //! Default constructor
    ConnectorCavityGroup( );
     
    //! Constructs a ConnectorCavityGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConnectorCavityGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConnectorCavityGroup();

private:

	//! Assignment operator
	ConnectorCavityGroup& operator=( const ConnectorCavityGroup& iSrc );

	//! Copy constructor
	ConnectorCavityGroup( const ConnectorCavityGroup& original );
     
public:

	//! Get ConnectorCavityGroupType of this ConnectorCavityGroup
	plmxml_api::String GetConnectorCavityGroupType() const;

	//! Set ConnectorCavityGroupType of this ConnectorCavityGroup
	plmxml_api::Result SetConnectorCavityGroupType( const plmxml_api::String &s );
	
	//! Check if ConnectorCavityGroupType is set
	plmxml_api::logical HasConnectorCavityGroupType( ) const;
	
	//! Unset ConnectorCavityGroupType
	plmxml_api::Result UnsetConnectorCavityGroupType( );

	//! Get ConnectorCavityGroupType URI as plmxml_api::String
	plmxml_api::String GetConnectorCavityGroupTypeURI() const;

	//! Set ConnectorCavityGroupType URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetConnectorCavityGroupTypeURI( const plmxml_api::String& );
	
	//! Get the handle of ConnectorCavityGroupType URI. Does not resolve the URI.
	plmxml_api::Result GetConnectorCavityGroupTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ConnectorCavityGroupType URI. URI string is unchanged.
	plmxml_api::Result SetConnectorCavityGroupTypeURI( const plmxml_api::Handle& );
	
	//! Resolve ConnectorCavityGroupType URI and return an object (handle) it points to.
	plmxml_api::Result ResolveConnectorCavityGroupTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ConnectorCavityGroupType URI. Clears URI string and handle.
	plmxml_api::Result DeleteConnectorCavityGroupTypeURI();
	
	//! Check if ConnectorCavityGroupType URI is set
	plmxml_api::logical HasConnectorCavityGroupTypeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderConnectorCavityGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassConnectorCavityGroup;


////////////////////////////////////////////////////////////////////////////////////
//! ConnectorCavity class
/*!
\verbatim

      This represents a cavity in a connector, into which a wire can be fixed.
      
      Attributes:
      
      connectorCavityType:  A string describing the type of ConnectorCavity
      connectorCavityTypeRef: References a multiple language version of
                      connectorCavityType. If multiple language support is
                      required, connectorCavityTypeRef should be used in
                      addition to connectorCavityType.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API ConnectorCavity : public GDE
{
public:
     
    //! Default constructor
    ConnectorCavity( );
     
    //! Constructs a ConnectorCavity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConnectorCavity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConnectorCavity();

private:

	//! Assignment operator
	ConnectorCavity& operator=( const ConnectorCavity& iSrc );

	//! Copy constructor
	ConnectorCavity( const ConnectorCavity& original );
     
public:

	//! Get ConnectorCavityType of this ConnectorCavity
	plmxml_api::String GetConnectorCavityType() const;

	//! Set ConnectorCavityType of this ConnectorCavity
	plmxml_api::Result SetConnectorCavityType( const plmxml_api::String &s );
	
	//! Check if ConnectorCavityType is set
	plmxml_api::logical HasConnectorCavityType( ) const;
	
	//! Unset ConnectorCavityType
	plmxml_api::Result UnsetConnectorCavityType( );

	//! Get ConnectorCavityType URI as plmxml_api::String
	plmxml_api::String GetConnectorCavityTypeURI() const;

	//! Set ConnectorCavityType URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetConnectorCavityTypeURI( const plmxml_api::String& );
	
	//! Get the handle of ConnectorCavityType URI. Does not resolve the URI.
	plmxml_api::Result GetConnectorCavityTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ConnectorCavityType URI. URI string is unchanged.
	plmxml_api::Result SetConnectorCavityTypeURI( const plmxml_api::Handle& );
	
	//! Resolve ConnectorCavityType URI and return an object (handle) it points to.
	plmxml_api::Result ResolveConnectorCavityTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ConnectorCavityType URI. Clears URI string and handle.
	plmxml_api::Result DeleteConnectorCavityTypeURI();
	
	//! Check if ConnectorCavityType URI is set
	plmxml_api::logical HasConnectorCavityTypeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderConnectorCavity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassConnectorCavity;


////////////////////////////////////////////////////////////////////////////////////
//! WireProtectionAreaRelation class
/*!
\verbatim

      This relation relates an Occurrence of a WireProtection to one or more
      RouteSection elements, which specify where the protection applies.

      Attributes:

      relatedRefs:      Inherited from GeneralRelation. The first item in the
                        list references the Occurrence. Subsequent items
                        reference the RouteSections from the first to the last
                        in order.
      startT:           Start parameter on the first associated RouteSection.
      endT:             End parameter on the last associated RouteSection.
      gradient:         The pitch of the taping in metres.
      tapingDirection:  Whether the tape winds clockwise or counter-clockwise.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API WireProtectionAreaRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    WireProtectionAreaRelation( );
     
    //! Constructs a WireProtectionAreaRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WireProtectionAreaRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WireProtectionAreaRelation();

private:

	//! Assignment operator
	WireProtectionAreaRelation& operator=( const WireProtectionAreaRelation& iSrc );

	//! Copy constructor
	WireProtectionAreaRelation( const WireProtectionAreaRelation& original );
     
public:

	//! Set Gradient
	plmxml_api::Result SetGradient( double arg );

     //! Get Gradient
	double GetGradient() const;

	//! Check if Gradient is set
	plmxml_api::logical HasGradient() const;

	//! Unset Gradient
	plmxml_api::Result UnsetGradient();

	//! Set EndT
	plmxml_api::Result SetEndT( double arg );

     //! Get EndT
	double GetEndT() const;

	//! Check if EndT is set
	plmxml_api::logical HasEndT() const;

	//! Unset EndT
	plmxml_api::Result UnsetEndT();

	//! Set StartT
	plmxml_api::Result SetStartT( double arg );

     //! Get StartT
	double GetStartT() const;

	//! Check if StartT is set
	plmxml_api::logical HasStartT() const;

	//! Unset StartT
	plmxml_api::Result UnsetStartT();

	//! Set TapingDirection
	plmxml_api::Result SetTapingDirection( const eWireProtectionTapingEnum& arg );

	//! Get TapingDirection
	eWireProtectionTapingEnum GetTapingDirection() const;
 
// <PLMXML_UserCode type="functionHeaderWireProtectionAreaRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassWireProtectionAreaRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RouteNodeAssignment class
/*!
\verbatim

      This relation relates an Occurrence to a RouteNode, on which it lies.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RouteNodeAssignment : public GeneralRelation
{
public:
     
    //! Default constructor
    RouteNodeAssignment( );
     
    //! Constructs a RouteNodeAssignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteNodeAssignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteNodeAssignment();

private:

	//! Assignment operator
	RouteNodeAssignment& operator=( const RouteNodeAssignment& iSrc );

	//! Copy constructor
	RouteNodeAssignment( const RouteNodeAssignment& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRouteNodeAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRouteNodeAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! RouteSectionAssignment class
/*!
\verbatim

      This relation relates an Occurrence to a RouteSection, on which it lies.
      For example, the Occurrence might be of a Fixing on a wire.
      
      Attributes:
      
      t:             parameter on the RouteSection at which the Occurrence occurs.
      zAxis:         direction of the 'Z axis' of the Occurrence.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API RouteSectionAssignment : public GeneralRelation
{
public:
     
    //! Default constructor
    RouteSectionAssignment( );
     
    //! Constructs a RouteSectionAssignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteSectionAssignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteSectionAssignment();

private:

	//! Assignment operator
	RouteSectionAssignment& operator=( const RouteSectionAssignment& iSrc );

	//! Copy constructor
	RouteSectionAssignment( const RouteSectionAssignment& original );
     
public:

	//! Set ZAxis using plmxml_api::Vector components
	plmxml_api::Result SetZAxis( const plmxml_api::Vector& arg );

	//! Get ZAxis as plmxml_api::Vector
	plmxml_api::Result GetZAxis( plmxml_api::Vector& arg ) const;

	//! Check if ZAxis is set
	plmxml_api::logical HasZAxis() const;

	//! Unset ZAxis
	plmxml_api::Result UnsetZAxis();

	//! Set T
	plmxml_api::Result SetT( double arg );

     //! Get T
	double GetT() const;

	//! Check if T is set
	plmxml_api::logical HasT() const;

	//! Unset T
	plmxml_api::Result UnsetT();
 
// <PLMXML_UserCode type="functionHeaderRouteSectionAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassRouteSectionAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! DerivedFromRelation class
/*!
\verbatim

      This relation indicates that one element is derived from (based on) another. 
      For example, a ProductRevision might be based on an earlier revision of the 
      Product (or a different Product).
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API DerivedFromRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    DerivedFromRelation( );
     
    //! Constructs a DerivedFromRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DerivedFromRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DerivedFromRelation();

private:

	//! Assignment operator
	DerivedFromRelation& operator=( const DerivedFromRelation& iSrc );

	//! Copy constructor
	DerivedFromRelation( const DerivedFromRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDerivedFromRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassDerivedFromRelation;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessorProduct class
/*!
\verbatim

      The ProcessorProduct element is a type of Product which is used to represent a processor
      which can run embedded software.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API ProcessorProduct : public Product
{
public:
     
    //! Default constructor
    ProcessorProduct( );
     
    //! Constructs a ProcessorProduct with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessorProduct( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessorProduct();

private:

	//! Assignment operator
	ProcessorProduct& operator=( const ProcessorProduct& iSrc );

	//! Copy constructor
	ProcessorProduct( const ProcessorProduct& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcessorProduct" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassProcessorProduct;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessorProductRevision class
/*!
\verbatim

      The ProcessorProductRevision element is a revision of a ProcessorProduct.
      
      Attributes:
      
      linked:                "true" if this Processor is connected to a network.
      programmableInService: "true" if this Processor can be reprogrammed in service.
      memoryType:            type of memory, e.g. "EEPROM"
      byteOrder:             littleEndian or bigEndian
      architecture:          32-bit or 64-bit
      gateway:               true if this is a Gateway Processor, i.e. acts as
                             a Gateway for accessing other Processors.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API ProcessorProductRevision : public ProductRevision
{
public:
     
    //! Default constructor
    ProcessorProductRevision( );
     
    //! Constructs a ProcessorProductRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessorProductRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessorProductRevision();

private:

	//! Assignment operator
	ProcessorProductRevision& operator=( const ProcessorProductRevision& iSrc );

	//! Copy constructor
	ProcessorProductRevision( const ProcessorProductRevision& original );
     
public:

	//! Set ProgrammableInService
	plmxml_api::Result SetProgrammableInService( plmxml_api::logical arg );

	//! Get ProgrammableInService
	plmxml_api::logical GetProgrammableInService() const;

	//! Check if ProgrammableInService is set
	plmxml_api::logical HasProgrammableInService() const;

	//! Unset ProgrammableInService
	plmxml_api::Result UnsetProgrammableInService();

	//! Set Linked
	plmxml_api::Result SetLinked( plmxml_api::logical arg );

	//! Get Linked
	plmxml_api::logical GetLinked() const;

	//! Check if Linked is set
	plmxml_api::logical HasLinked() const;

	//! Unset Linked
	plmxml_api::Result UnsetLinked();

	//! Set ByteOrder
	plmxml_api::Result SetByteOrder( const eProcessorByteOrderEnum& arg );

	//! Get ByteOrder
	eProcessorByteOrderEnum GetByteOrder() const;

	//! Set Architecture
	plmxml_api::Result SetArchitecture( const eProcessorArchitectureEnum& arg );

	//! Get Architecture
	eProcessorArchitectureEnum GetArchitecture() const;

	//! Get MemoryType of this ProcessorProductRevision
	plmxml_api::String GetMemoryType() const;

	//! Set MemoryType of this ProcessorProductRevision
	plmxml_api::Result SetMemoryType( const plmxml_api::String &s );
	
	//! Check if MemoryType is set
	plmxml_api::logical HasMemoryType( ) const;
	
	//! Unset MemoryType
	plmxml_api::Result UnsetMemoryType( );

	//! Set Gateway
	plmxml_api::Result SetGateway( plmxml_api::logical arg );

	//! Get Gateway
	plmxml_api::logical GetGateway() const;

	//! Check if Gateway is set
	plmxml_api::logical HasGateway() const;

	//! Unset Gateway
	plmxml_api::Result UnsetGateway();
 
// <PLMXML_UserCode type="functionHeaderProcessorProductRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassProcessorProductRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Processor class
/*!
\verbatim

      The Processor element is a type of GDE which is used to represent a processor
      which can run embedded software.
      
      Attributes:
      
      linked:                "true" if this Processor is connected to a network.
      programmableInService: "true" if this Processor can be reprogrammed in service.
      networkProtocol:       e.g. "CAN", "MOST"
      memoryType:            type of memory, e.g. "EEPROM"
      byteOrder:             littleEndian or bigEndian
      architecture:          32-bit or 64-bit
      gateway:               true if this is a Gateway Processor, i.e. acts as
                             a Gateway for accessing other Processors.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Processor : public GDE
{
public:
     
    //! Default constructor
    Processor( );
     
    //! Constructs a Processor with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Processor( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Processor();

private:

	//! Assignment operator
	Processor& operator=( const Processor& iSrc );

	//! Copy constructor
	Processor( const Processor& original );
     
public:

	//! Set ProgrammableInService
	plmxml_api::Result SetProgrammableInService( plmxml_api::logical arg );

	//! Get ProgrammableInService
	plmxml_api::logical GetProgrammableInService() const;

	//! Check if ProgrammableInService is set
	plmxml_api::logical HasProgrammableInService() const;

	//! Unset ProgrammableInService
	plmxml_api::Result UnsetProgrammableInService();

	//! Set Linked
	plmxml_api::Result SetLinked( plmxml_api::logical arg );

	//! Get Linked
	plmxml_api::logical GetLinked() const;

	//! Check if Linked is set
	plmxml_api::logical HasLinked() const;

	//! Unset Linked
	plmxml_api::Result UnsetLinked();

	//! Set ByteOrder
	plmxml_api::Result SetByteOrder( const eProcessorByteOrderEnum& arg );

	//! Get ByteOrder
	eProcessorByteOrderEnum GetByteOrder() const;

	//! Get NetworkProtocol of this Processor
	plmxml_api::String GetNetworkProtocol() const;

	//! Set NetworkProtocol of this Processor
	plmxml_api::Result SetNetworkProtocol( const plmxml_api::String &s );
	
	//! Check if NetworkProtocol is set
	plmxml_api::logical HasNetworkProtocol( ) const;
	
	//! Unset NetworkProtocol
	plmxml_api::Result UnsetNetworkProtocol( );

	//! Set Architecture
	plmxml_api::Result SetArchitecture( const eProcessorArchitectureEnum& arg );

	//! Get Architecture
	eProcessorArchitectureEnum GetArchitecture() const;

	//! Get MemoryType of this Processor
	plmxml_api::String GetMemoryType() const;

	//! Set MemoryType of this Processor
	plmxml_api::Result SetMemoryType( const plmxml_api::String &s );
	
	//! Check if MemoryType is set
	plmxml_api::logical HasMemoryType( ) const;
	
	//! Unset MemoryType
	plmxml_api::Result UnsetMemoryType( );

	//! Set Gateway
	plmxml_api::Result SetGateway( plmxml_api::logical arg );

	//! Get Gateway
	plmxml_api::logical GetGateway() const;

	//! Check if Gateway is set
	plmxml_api::logical HasGateway() const;

	//! Unset Gateway
	plmxml_api::Result UnsetGateway();
 
// <PLMXML_UserCode type="functionHeaderProcessor" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassProcessor;


////////////////////////////////////////////////////////////////////////////////////
//! Software class
/*!
\verbatim

      Software is a subclass of Structure representing a piece of embedded Software, 
      e.g. in an ECU.
      
      Attributes:
      
      softwareType:  the type of the software - "application", "calibration",
                     "bootLoader" or "configuration".
                     
      alternateForRef:  An 'alternate' Software is one which is substitutable, in all 
                     contexts, for a particular Software. If this is an 'alternate'
                     Software, then this attribute references the Software for which
                     this is an alternate.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API Software : public Structure
{
public:
     
    //! Default constructor
    Software( );
     
    //! Constructs a Software with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Software( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Software();

private:

	//! Assignment operator
	Software& operator=( const Software& iSrc );

	//! Copy constructor
	Software( const Software& original );
     
public:

	//! Set SoftwareType
	plmxml_api::Result SetSoftwareType( const eSoftwareEnum& arg );

	//! Get SoftwareType
	eSoftwareEnum GetSoftwareType() const;

	//! Get AlternateFor URI as plmxml_api::String
	plmxml_api::String GetAlternateForURI() const;

	//! Set AlternateFor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAlternateForURI( const plmxml_api::String& );
	
	//! Get the handle of AlternateFor URI. Does not resolve the URI.
	plmxml_api::Result GetAlternateForURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of AlternateFor URI. URI string is unchanged.
	plmxml_api::Result SetAlternateForURI( const plmxml_api::Handle& );
	
	//! Resolve AlternateFor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAlternateForURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset AlternateFor URI. Clears URI string and handle.
	plmxml_api::Result DeleteAlternateForURI();
	
	//! Check if AlternateFor URI is set
	plmxml_api::logical HasAlternateForURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderSoftware" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSoftware;


////////////////////////////////////////////////////////////////////////////////////
//! SoftwareRevision class
/*!
\verbatim

      This is a revision of Software. 
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API SoftwareRevision : public StructureRevision
{
public:
     
    //! Default constructor
    SoftwareRevision( );
     
    //! Constructs a SoftwareRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SoftwareRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SoftwareRevision();

private:

	//! Assignment operator
	SoftwareRevision& operator=( const SoftwareRevision& iSrc );

	//! Copy constructor
	SoftwareRevision( const SoftwareRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderSoftwareRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSoftwareRevision;


////////////////////////////////////////////////////////////////////////////////////
//! SoftwareRevisionView class
/*!
\verbatim

      This is a 'view' (e.g. 'design', 'manufacturing', 'maintenance') of a 
      revision of a Software.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API SoftwareRevisionView : public StructureRevisionView
{
public:
     
    //! Default constructor
    SoftwareRevisionView( );
     
    //! Constructs a SoftwareRevisionView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SoftwareRevisionView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SoftwareRevisionView();

private:

	//! Assignment operator
	SoftwareRevisionView& operator=( const SoftwareRevisionView& iSrc );

	//! Copy constructor
	SoftwareRevisionView( const SoftwareRevisionView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderSoftwareRevisionView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSoftwareRevisionView;


////////////////////////////////////////////////////////////////////////////////////
//! SoftwareInstance class
/*!
\verbatim

      An Instance of a SoftwareRevisionView, SoftwareRevision, or Software.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API SoftwareInstance : public Instance
{
public:
     
    //! Default constructor
    SoftwareInstance( );
     
    //! Constructs a SoftwareInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SoftwareInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SoftwareInstance();

private:

	//! Assignment operator
	SoftwareInstance& operator=( const SoftwareInstance& iSrc );

	//! Copy constructor
	SoftwareInstance( const SoftwareInstance& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderSoftwareInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassSoftwareInstance;


////////////////////////////////////////////////////////////////////////////////////
//! FrameSignal class
/*!
\verbatim

      A FrameSignal is a type of Signal that carries multiple embedded signals
      between devices.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API FrameSignal : public Signal
{
public:
     
    //! Default constructor
    FrameSignal( );
     
    //! Constructs a FrameSignal with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FrameSignal( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FrameSignal();

private:

	//! Assignment operator
	FrameSignal& operator=( const FrameSignal& iSrc );

	//! Copy constructor
	FrameSignal( const FrameSignal& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFrameSignal" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassFrameSignal;


////////////////////////////////////////////////////////////////////////////////////
//! FrameSignalRevision class
/*!
\verbatim

      This is a revision of a FrameSignal.
      
\endverbatim
*/
class PLMXML_MECHATRONICS60_API FrameSignalRevision : public SignalRevision
{
public:
     
    //! Default constructor
    FrameSignalRevision( );
     
    //! Constructs a FrameSignalRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FrameSignalRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FrameSignalRevision();

private:

	//! Assignment operator
	FrameSignalRevision& operator=( const FrameSignalRevision& iSrc );

	//! Copy constructor
	FrameSignalRevision( const FrameSignalRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFrameSignalRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MECHATRONICS60_API plmxml_api::plmxmlClass plmxmlClassFrameSignalRevision;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
