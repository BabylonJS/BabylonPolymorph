/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 14:37:15
// 
// Schema:	PLMXMLMROSchema.xsd
// Data:	08/06/2018 14:37:05
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_MRO60_H__
#define __PLMXML_MRO60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_MRO60_EXPORTS
#define PLMXML_MRO60_API __declspec(dllexport)
#else
#define PLMXML_MRO60_API __declspec(dllimport)
#endif
#else
#define PLMXML_MRO60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


#include <plmxml_mpm60.h>

#include <plmxml_classification60.h>
#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
#include <plmxml_mpm60.h>
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! ePricingModeEnum class
/*!
Allowed Values:
\verbatim
  ePricingModeEnumAverage
	"average"
  ePricingModeEnumActual
	"actual"
  
\endverbatim
*/
class PLMXML_MRO60_API ePricingModeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePricingModeEnum( const char* Type );
     
	//! Constructor
	ePricingModeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePricingModeEnum( );
     
	//! Destructor 
	virtual ~ePricingModeEnum( );
     
	//! Assign from 'Type'
	const ePricingModeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePricingModeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PricingModeEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const ePricingModeEnum& e1, const ePricingModeEnum& e2 );
     
	//! Compare PricingModeEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const ePricingModeEnum& e1, const ePricingModeEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPricingModeEnum;
extern PLMXML_MRO60_API ePricingModeEnum ePricingModeEnumUnset;
extern PLMXML_MRO60_API ePricingModeEnum ePricingModeEnumAverage;
extern PLMXML_MRO60_API ePricingModeEnum ePricingModeEnumActual;

////////////////////////////////////////////////////////////////////////////////////
//! eCategoryEnum class
/*!
Allowed Values:
\verbatim
  eCategoryEnumRepair
	"repair"
  eCategoryEnumOther
	"other"
  eCategoryEnumOverhaul
	"overhaul"
  eCategoryEnumInspection
	"inspection"
  
\endverbatim
*/
class PLMXML_MRO60_API eCategoryEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCategoryEnum( const char* Type );
     
	//! Constructor
	eCategoryEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCategoryEnum( );
     
	//! Destructor 
	virtual ~eCategoryEnum( );
     
	//! Assign from 'Type'
	const eCategoryEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCategoryEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CategoryEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eCategoryEnum& e1, const eCategoryEnum& e2 );
     
	//! Compare CategoryEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eCategoryEnum& e1, const eCategoryEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCategoryEnum;
extern PLMXML_MRO60_API eCategoryEnum eCategoryEnumUnset;
extern PLMXML_MRO60_API eCategoryEnum eCategoryEnumRepair;
extern PLMXML_MRO60_API eCategoryEnum eCategoryEnumOther;
extern PLMXML_MRO60_API eCategoryEnum eCategoryEnumOverhaul;
extern PLMXML_MRO60_API eCategoryEnum eCategoryEnumInspection;

////////////////////////////////////////////////////////////////////////////////////
//! eRequestStatusEnum class
/*!
Allowed Values:
\verbatim
  eRequestStatusEnumTurnedIn
	"turnedIn"
  eRequestStatusEnumCancelled
	"cancelled"
  eRequestStatusEnumOpen
	"open"
  eRequestStatusEnumClosed
	"closed"
  
\endverbatim
*/
class PLMXML_MRO60_API eRequestStatusEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRequestStatusEnum( const char* Type );
     
	//! Constructor
	eRequestStatusEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRequestStatusEnum( );
     
	//! Destructor 
	virtual ~eRequestStatusEnum( );
     
	//! Assign from 'Type'
	const eRequestStatusEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRequestStatusEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RequestStatusEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eRequestStatusEnum& e1, const eRequestStatusEnum& e2 );
     
	//! Compare RequestStatusEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eRequestStatusEnum& e1, const eRequestStatusEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRequestStatusEnum;
extern PLMXML_MRO60_API eRequestStatusEnum eRequestStatusEnumUnset;
extern PLMXML_MRO60_API eRequestStatusEnum eRequestStatusEnumTurnedIn;
extern PLMXML_MRO60_API eRequestStatusEnum eRequestStatusEnumCancelled;
extern PLMXML_MRO60_API eRequestStatusEnum eRequestStatusEnumOpen;
extern PLMXML_MRO60_API eRequestStatusEnum eRequestStatusEnumClosed;

////////////////////////////////////////////////////////////////////////////////////
//! eRealisedProductTraceableType class
/*!
Allowed Values:
\verbatim
  eRealisedProductTraceableTypeNonRepairable
	"nonRepairable"
  eRealisedProductTraceableTypeRepairable
	"repairable"
  
\endverbatim
*/
class PLMXML_MRO60_API eRealisedProductTraceableType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRealisedProductTraceableType( const char* Type );
     
	//! Constructor
	eRealisedProductTraceableType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRealisedProductTraceableType( );
     
	//! Destructor 
	virtual ~eRealisedProductTraceableType( );
     
	//! Assign from 'Type'
	const eRealisedProductTraceableType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRealisedProductTraceableType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RealisedProductTraceableType
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eRealisedProductTraceableType& e1, const eRealisedProductTraceableType& e2 );
     
	//! Compare RealisedProductTraceableType
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eRealisedProductTraceableType& e1, const eRealisedProductTraceableType& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRealisedProductTraceableType;
extern PLMXML_MRO60_API eRealisedProductTraceableType eRealisedProductTraceableTypeUnset;
extern PLMXML_MRO60_API eRealisedProductTraceableType eRealisedProductTraceableTypeNonRepairable;
extern PLMXML_MRO60_API eRealisedProductTraceableType eRealisedProductTraceableTypeRepairable;

////////////////////////////////////////////////////////////////////////////////////
//! eDispositionCodeEnum class
/*!
Allowed Values:
\verbatim
  eDispositionCodeEnumUseAsIs
	"useAsIs"
  eDispositionCodeEnumRework
	"rework"
  eDispositionCodeEnumNone
	"none"
  eDispositionCodeEnumReturn
	"return"
  eDispositionCodeEnumAccept
	"accept"
  eDispositionCodeEnumRepair
	"repair"
  eDispositionCodeEnumScrap
	"scrap"
  
\endverbatim
*/
class PLMXML_MRO60_API eDispositionCodeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDispositionCodeEnum( const char* Type );
     
	//! Constructor
	eDispositionCodeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDispositionCodeEnum( );
     
	//! Destructor 
	virtual ~eDispositionCodeEnum( );
     
	//! Assign from 'Type'
	const eDispositionCodeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDispositionCodeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DispositionCodeEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eDispositionCodeEnum& e1, const eDispositionCodeEnum& e2 );
     
	//! Compare DispositionCodeEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eDispositionCodeEnum& e1, const eDispositionCodeEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDispositionCodeEnum;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumUnset;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumUseAsIs;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumRework;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumNone;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumReturn;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumAccept;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumRepair;
extern PLMXML_MRO60_API eDispositionCodeEnum eDispositionCodeEnumScrap;

////////////////////////////////////////////////////////////////////////////////////
//! eSkillEnum class
/*!
Allowed Values:
\verbatim
  eSkillEnumPerson
	"person"
  eSkillEnumCrew
	"crew"
  
\endverbatim
*/
class PLMXML_MRO60_API eSkillEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSkillEnum( const char* Type );
     
	//! Constructor
	eSkillEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSkillEnum( );
     
	//! Destructor 
	virtual ~eSkillEnum( );
     
	//! Assign from 'Type'
	const eSkillEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSkillEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SkillEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eSkillEnum& e1, const eSkillEnum& e2 );
     
	//! Compare SkillEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eSkillEnum& e1, const eSkillEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSkillEnum;
extern PLMXML_MRO60_API eSkillEnum eSkillEnumUnset;
extern PLMXML_MRO60_API eSkillEnum eSkillEnumPerson;
extern PLMXML_MRO60_API eSkillEnum eSkillEnumCrew;

////////////////////////////////////////////////////////////////////////////////////
//! eExecutionEnum class
/*!
Allowed Values:
\verbatim
  eExecutionEnumOther
	"other"
  eExecutionEnumPerform
	"perform"
  eExecutionEnumSignOff
	"signOff"
  
\endverbatim
*/
class PLMXML_MRO60_API eExecutionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eExecutionEnum( const char* Type );
     
	//! Constructor
	eExecutionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eExecutionEnum( );
     
	//! Destructor 
	virtual ~eExecutionEnum( );
     
	//! Assign from 'Type'
	const eExecutionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eExecutionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ExecutionEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eExecutionEnum& e1, const eExecutionEnum& e2 );
     
	//! Compare ExecutionEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eExecutionEnum& e1, const eExecutionEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumExecutionEnum;
extern PLMXML_MRO60_API eExecutionEnum eExecutionEnumUnset;
extern PLMXML_MRO60_API eExecutionEnum eExecutionEnumOther;
extern PLMXML_MRO60_API eExecutionEnum eExecutionEnumPerform;
extern PLMXML_MRO60_API eExecutionEnum eExecutionEnumSignOff;

////////////////////////////////////////////////////////////////////////////////////
//! eRealisedProductConditionEnum class
/*!
Allowed Values:
\verbatim
  eRealisedProductConditionEnumUnServiceable
	"unServiceable"
  eRealisedProductConditionEnumServiceable
	"serviceable"
  
\endverbatim
*/
class PLMXML_MRO60_API eRealisedProductConditionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRealisedProductConditionEnum( const char* Type );
     
	//! Constructor
	eRealisedProductConditionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRealisedProductConditionEnum( );
     
	//! Destructor 
	virtual ~eRealisedProductConditionEnum( );
     
	//! Assign from 'Type'
	const eRealisedProductConditionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRealisedProductConditionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RealisedProductConditionEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eRealisedProductConditionEnum& e1, const eRealisedProductConditionEnum& e2 );
     
	//! Compare RealisedProductConditionEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eRealisedProductConditionEnum& e1, const eRealisedProductConditionEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRealisedProductConditionEnum;
extern PLMXML_MRO60_API eRealisedProductConditionEnum eRealisedProductConditionEnumUnset;
extern PLMXML_MRO60_API eRealisedProductConditionEnum eRealisedProductConditionEnumUnServiceable;
extern PLMXML_MRO60_API eRealisedProductConditionEnum eRealisedProductConditionEnumServiceable;

////////////////////////////////////////////////////////////////////////////////////
//! eWarningEnum class
/*!
Allowed Values:
\verbatim
  eWarningEnumOther
	"other"
  eWarningEnumSafety
	"safety"
  eWarningEnumHazardousMaterial
	"hazardousMaterial"
  
\endverbatim
*/
class PLMXML_MRO60_API eWarningEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWarningEnum( const char* Type );
     
	//! Constructor
	eWarningEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWarningEnum( );
     
	//! Destructor 
	virtual ~eWarningEnum( );
     
	//! Assign from 'Type'
	const eWarningEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWarningEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WarningEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eWarningEnum& e1, const eWarningEnum& e2 );
     
	//! Compare WarningEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eWarningEnum& e1, const eWarningEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWarningEnum;
extern PLMXML_MRO60_API eWarningEnum eWarningEnumUnset;
extern PLMXML_MRO60_API eWarningEnum eWarningEnumOther;
extern PLMXML_MRO60_API eWarningEnum eWarningEnumSafety;
extern PLMXML_MRO60_API eWarningEnum eWarningEnumHazardousMaterial;

////////////////////////////////////////////////////////////////////////////////////
//! eRemoveInstallProductActionEnum class
/*!
Allowed Values:
\verbatim
  eRemoveInstallProductActionEnumRemove
	"remove"
  eRemoveInstallProductActionEnumInstall
	"install"
  eRemoveInstallProductActionEnumChange
	"change"
  
\endverbatim
*/
class PLMXML_MRO60_API eRemoveInstallProductActionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRemoveInstallProductActionEnum( const char* Type );
     
	//! Constructor
	eRemoveInstallProductActionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRemoveInstallProductActionEnum( );
     
	//! Destructor 
	virtual ~eRemoveInstallProductActionEnum( );
     
	//! Assign from 'Type'
	const eRemoveInstallProductActionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRemoveInstallProductActionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RemoveInstallProductActionEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eRemoveInstallProductActionEnum& e1, const eRemoveInstallProductActionEnum& e2 );
     
	//! Compare RemoveInstallProductActionEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eRemoveInstallProductActionEnum& e1, const eRemoveInstallProductActionEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRemoveInstallProductActionEnum;
extern PLMXML_MRO60_API eRemoveInstallProductActionEnum eRemoveInstallProductActionEnumUnset;
extern PLMXML_MRO60_API eRemoveInstallProductActionEnum eRemoveInstallProductActionEnumRemove;
extern PLMXML_MRO60_API eRemoveInstallProductActionEnum eRemoveInstallProductActionEnumInstall;
extern PLMXML_MRO60_API eRemoveInstallProductActionEnum eRemoveInstallProductActionEnumChange;

////////////////////////////////////////////////////////////////////////////////////
//! ePartMovementEnum class
/*!
Allowed Values:
\verbatim
  ePartMovementEnumRemove
	"remove"
  ePartMovementEnumInstall
	"install"
  ePartMovementEnumChange
	"change"
  
\endverbatim
*/
class PLMXML_MRO60_API ePartMovementEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePartMovementEnum( const char* Type );
     
	//! Constructor
	ePartMovementEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePartMovementEnum( );
     
	//! Destructor 
	virtual ~ePartMovementEnum( );
     
	//! Assign from 'Type'
	const ePartMovementEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePartMovementEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PartMovementEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const ePartMovementEnum& e1, const ePartMovementEnum& e2 );
     
	//! Compare PartMovementEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const ePartMovementEnum& e1, const ePartMovementEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPartMovementEnum;
extern PLMXML_MRO60_API ePartMovementEnum ePartMovementEnumUnset;
extern PLMXML_MRO60_API ePartMovementEnum ePartMovementEnumRemove;
extern PLMXML_MRO60_API ePartMovementEnum ePartMovementEnumInstall;
extern PLMXML_MRO60_API ePartMovementEnum ePartMovementEnumChange;

////////////////////////////////////////////////////////////////////////////////////
//! ePeriodEnum class
/*!
Allowed Values:
\verbatim
  ePeriodEnumMonths
	"months"
  ePeriodEnumDays
	"days"
  ePeriodEnumYears
	"years"
  ePeriodEnumCycles
	"cycles"
  ePeriodEnumHours
	"hours"
  ePeriodEnumWeeks
	"weeks"
  ePeriodEnumQuarters
	"quarters"
  ePeriodEnumOther
	"other"
  
\endverbatim
*/
class PLMXML_MRO60_API ePeriodEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePeriodEnum( const char* Type );
     
	//! Constructor
	ePeriodEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePeriodEnum( );
     
	//! Destructor 
	virtual ~ePeriodEnum( );
     
	//! Assign from 'Type'
	const ePeriodEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePeriodEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PeriodEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const ePeriodEnum& e1, const ePeriodEnum& e2 );
     
	//! Compare PeriodEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const ePeriodEnum& e1, const ePeriodEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPeriodEnum;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumUnset;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumMonths;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumDays;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumYears;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumCycles;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumHours;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumWeeks;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumQuarters;
extern PLMXML_MRO60_API ePeriodEnum ePeriodEnumOther;

////////////////////////////////////////////////////////////////////////////////////
//! eLocationEnum class
/*!
Allowed Values:
\verbatim
  eLocationEnumInService
	"inService"
  eLocationEnumEnterprise
	"enterprise"
  
\endverbatim
*/
class PLMXML_MRO60_API eLocationEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eLocationEnum( const char* Type );
     
	//! Constructor
	eLocationEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eLocationEnum( );
     
	//! Destructor 
	virtual ~eLocationEnum( );
     
	//! Assign from 'Type'
	const eLocationEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eLocationEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare LocationEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eLocationEnum& e1, const eLocationEnum& e2 );
     
	//! Compare LocationEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eLocationEnum& e1, const eLocationEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumLocationEnum;
extern PLMXML_MRO60_API eLocationEnum eLocationEnumUnset;
extern PLMXML_MRO60_API eLocationEnum eLocationEnumInService;
extern PLMXML_MRO60_API eLocationEnum eLocationEnumEnterprise;

////////////////////////////////////////////////////////////////////////////////////
//! ePartUsedIsEnum class
/*!
Allowed Values:
\verbatim
  ePartUsedIsEnumAlternate
	"alternate"
  ePartUsedIsEnumDeviated
	"deviated"
  ePartUsedIsEnumSubstitute
	"substitute"
  ePartUsedIsEnumPreferred
	"preferred"
  
\endverbatim
*/
class PLMXML_MRO60_API ePartUsedIsEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePartUsedIsEnum( const char* Type );
     
	//! Constructor
	ePartUsedIsEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePartUsedIsEnum( );
     
	//! Destructor 
	virtual ~ePartUsedIsEnum( );
     
	//! Assign from 'Type'
	const ePartUsedIsEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePartUsedIsEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PartUsedIsEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const ePartUsedIsEnum& e1, const ePartUsedIsEnum& e2 );
     
	//! Compare PartUsedIsEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const ePartUsedIsEnum& e1, const ePartUsedIsEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPartUsedIsEnum;
extern PLMXML_MRO60_API ePartUsedIsEnum ePartUsedIsEnumUnset;
extern PLMXML_MRO60_API ePartUsedIsEnum ePartUsedIsEnumAlternate;
extern PLMXML_MRO60_API ePartUsedIsEnum ePartUsedIsEnumDeviated;
extern PLMXML_MRO60_API ePartUsedIsEnum ePartUsedIsEnumSubstitute;
extern PLMXML_MRO60_API ePartUsedIsEnum ePartUsedIsEnumPreferred;

////////////////////////////////////////////////////////////////////////////////////
//! eRequestStageEnum class
/*!
Allowed Values:
\verbatim
  eRequestStageEnumReserved
	"reserved"
  eRequestStageEnumTurnedIn
	"turnedIn"
  eRequestStageEnumIssued
	"issued"
  
\endverbatim
*/
class PLMXML_MRO60_API eRequestStageEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRequestStageEnum( const char* Type );
     
	//! Constructor
	eRequestStageEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRequestStageEnum( );
     
	//! Destructor 
	virtual ~eRequestStageEnum( );
     
	//! Assign from 'Type'
	const eRequestStageEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRequestStageEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RequestStageEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator==( const eRequestStageEnum& e1, const eRequestStageEnum& e2 );
     
	//! Compare RequestStageEnum
	friend plmxml_api::logical PLMXML_MRO60_API operator!=( const eRequestStageEnum& e1, const eRequestStageEnum& e2 );
};
extern PLMXML_MRO60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRequestStageEnum;
extern PLMXML_MRO60_API eRequestStageEnum eRequestStageEnumUnset;
extern PLMXML_MRO60_API eRequestStageEnum eRequestStageEnumReserved;
extern PLMXML_MRO60_API eRequestStageEnum eRequestStageEnumTurnedIn;
extern PLMXML_MRO60_API eRequestStageEnum eRequestStageEnumIssued;

////////////////////////////////////////////////////////////////////////////////////
//! RealisedProduct class
/*!
\verbatim

      This represents a physical product, throughout its as-built/as-maintained
      lifecycle.

      Attributes:

      unitRef:          Inherited from Product. References a Unit that
                        represents the default unit of measure.
      manufacturerId:   Id (part number) assigned by Manufacturer.
      mrbId:            Id (part number) assigned by Material Review Board.
      manufactureDate:  Date (and time) of manufacture.
      manufacturerRef:  Ref to manufacturing Organisation.
      designRef:        Reference to Product Revision from which this product
                        was realised.
      standardLife:     Standard Life specified in given environment and
                        operation conditions.
      actualLife:       Actual Hours recorded by physical part.
      standardLifeValueRef: Reference to a ValueWithUnit giving the standard
                        life.
      actualLifeValueRef: Reference to a ValueWithUnit giving the actual life.
      lifeLimitedPart:  Whether the life of a part is limited.
      orderDate:        Physical Part Order Date.
      serialNumber:     Serial Number if a serialised product.
      lot:              Lot number if product is lot.
      traceablePartType: Whether the part is repairable or non-repairable.
      orderId:          Physical Part order id.
      defaultQuantity:  Default quantity.
      lotRef:           Reference to MRO lot.
      
\endverbatim
*/
class PLMXML_MRO60_API RealisedProduct : public Product
{
public:
     
    //! Default constructor
    RealisedProduct( );
     
    //! Constructs a RealisedProduct with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RealisedProduct( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RealisedProduct();

private:

	//! Assignment operator
	RealisedProduct& operator=( const RealisedProduct& iSrc );

	//! Copy constructor
	RealisedProduct( const RealisedProduct& original );
     
public:

	//! Set TraceablePartType
	plmxml_api::Result SetTraceablePartType( const eRealisedProductTraceableType& arg );

	//! Get TraceablePartType
	eRealisedProductTraceableType GetTraceablePartType() const;

	//! Get Design URI as plmxml_api::String
	plmxml_api::String GetDesignURI() const;

	//! Set Design URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDesignURI( const plmxml_api::String& );
	
	//! Get the handle of Design URI. Does not resolve the URI.
	plmxml_api::Result GetDesignURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Design URI. URI string is unchanged.
	plmxml_api::Result SetDesignURI( const plmxml_api::Handle& );
	
	//! Resolve Design URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDesignURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Design URI. Clears URI string and handle.
	plmxml_api::Result DeleteDesignURI();
	
	//! Check if Design URI is set
	plmxml_api::logical HasDesignURI( ) const;
	

	//! Set LifeLimitedPart
	plmxml_api::Result SetLifeLimitedPart( plmxml_api::logical arg );

	//! Get LifeLimitedPart
	plmxml_api::logical GetLifeLimitedPart() const;

	//! Check if LifeLimitedPart is set
	plmxml_api::logical HasLifeLimitedPart() const;

	//! Unset LifeLimitedPart
	plmxml_api::Result UnsetLifeLimitedPart();

	//! Get Lot of this RealisedProduct
	plmxml_api::String GetLot() const;

	//! Set Lot of this RealisedProduct
	plmxml_api::Result SetLot( const plmxml_api::String &s );
	
	//! Check if Lot is set
	plmxml_api::logical HasLot( ) const;
	
	//! Unset Lot
	plmxml_api::Result UnsetLot( );

	//! Get SerialNumber of this RealisedProduct
	plmxml_api::String GetSerialNumber() const;

	//! Set SerialNumber of this RealisedProduct
	plmxml_api::Result SetSerialNumber( const plmxml_api::String &s );
	
	//! Check if SerialNumber is set
	plmxml_api::logical HasSerialNumber( ) const;
	
	//! Unset SerialNumber
	plmxml_api::Result UnsetSerialNumber( );

	//! Get StandardLifeValue URI as plmxml_api::String
	plmxml_api::String GetStandardLifeValueURI() const;

	//! Set StandardLifeValue URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStandardLifeValueURI( const plmxml_api::String& );
	
	//! Get the handle of StandardLifeValue URI. Does not resolve the URI.
	plmxml_api::Result GetStandardLifeValueURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of StandardLifeValue URI. URI string is unchanged.
	plmxml_api::Result SetStandardLifeValueURI( const plmxml_api::Handle& );
	
	//! Resolve StandardLifeValue URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStandardLifeValueURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset StandardLifeValue URI. Clears URI string and handle.
	plmxml_api::Result DeleteStandardLifeValueURI();
	
	//! Check if StandardLifeValue URI is set
	plmxml_api::logical HasStandardLifeValueURI( ) const;
	

	//! Get ManufacturerId of this RealisedProduct
	plmxml_api::String GetManufacturerId() const;

	//! Set ManufacturerId of this RealisedProduct
	plmxml_api::Result SetManufacturerId( const plmxml_api::String &s );
	
	//! Check if ManufacturerId is set
	plmxml_api::logical HasManufacturerId( ) const;
	
	//! Unset ManufacturerId
	plmxml_api::Result UnsetManufacturerId( );

	//! Get ActualLifeValue URI as plmxml_api::String
	plmxml_api::String GetActualLifeValueURI() const;

	//! Set ActualLifeValue URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActualLifeValueURI( const plmxml_api::String& );
	
	//! Get the handle of ActualLifeValue URI. Does not resolve the URI.
	plmxml_api::Result GetActualLifeValueURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActualLifeValue URI. URI string is unchanged.
	plmxml_api::Result SetActualLifeValueURI( const plmxml_api::Handle& );
	
	//! Resolve ActualLifeValue URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActualLifeValueURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActualLifeValue URI. Clears URI string and handle.
	plmxml_api::Result DeleteActualLifeValueURI();
	
	//! Check if ActualLifeValue URI is set
	plmxml_api::logical HasActualLifeValueURI( ) const;
	

	//! Get ActualLife of this RealisedProduct
	plmxml_api::String GetActualLife() const;

	//! Set ActualLife of this RealisedProduct
	plmxml_api::Result SetActualLife( const plmxml_api::String &s );
	
	//! Check if ActualLife is set
	plmxml_api::logical HasActualLife( ) const;
	
	//! Unset ActualLife
	plmxml_api::Result UnsetActualLife( );

	//! Get ManufactureDate of this RealisedProduct
	plmxml_api::String GetManufactureDate() const;

	//! Set ManufactureDate of this RealisedProduct
	plmxml_api::Result SetManufactureDate( const plmxml_api::String &s );
	
	//! Check if ManufactureDate is set
	plmxml_api::logical HasManufactureDate( ) const;
	
	//! Unset ManufactureDate
	plmxml_api::Result UnsetManufactureDate( );

	//! Set DefaultQuantity
	plmxml_api::Result SetDefaultQuantity( double arg );

     //! Get DefaultQuantity
	double GetDefaultQuantity() const;

	//! Check if DefaultQuantity is set
	plmxml_api::logical HasDefaultQuantity() const;

	//! Unset DefaultQuantity
	plmxml_api::Result UnsetDefaultQuantity();

	//! Get OrderDate of this RealisedProduct
	plmxml_api::String GetOrderDate() const;

	//! Set OrderDate of this RealisedProduct
	plmxml_api::Result SetOrderDate( const plmxml_api::String &s );
	
	//! Check if OrderDate is set
	plmxml_api::logical HasOrderDate( ) const;
	
	//! Unset OrderDate
	plmxml_api::Result UnsetOrderDate( );

	//! Get MrbId of this RealisedProduct
	plmxml_api::String GetMrbId() const;

	//! Set MrbId of this RealisedProduct
	plmxml_api::Result SetMrbId( const plmxml_api::String &s );
	
	//! Check if MrbId is set
	plmxml_api::logical HasMrbId( ) const;
	
	//! Unset MrbId
	plmxml_api::Result UnsetMrbId( );

	//! Get Manufacturer URI as plmxml_api::String
	plmxml_api::String GetManufacturerURI() const;

	//! Set Manufacturer URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::String& );
	
	//! Get the handle of Manufacturer URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Manufacturer URI. URI string is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::Handle& );
	
	//! Resolve Manufacturer URI and return an object (handle) it points to.
	plmxml_api::Result ResolveManufacturerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Manufacturer URI. Clears URI string and handle.
	plmxml_api::Result DeleteManufacturerURI();
	
	//! Check if Manufacturer URI is set
	plmxml_api::logical HasManufacturerURI( ) const;
	

	//! Get Lot URI as plmxml_api::String
	plmxml_api::String GetLotURI() const;

	//! Set Lot URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetLotURI( const plmxml_api::String& );
	
	//! Get the handle of Lot URI. Does not resolve the URI.
	plmxml_api::Result GetLotURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Lot URI. URI string is unchanged.
	plmxml_api::Result SetLotURI( const plmxml_api::Handle& );
	
	//! Resolve Lot URI and return an object (handle) it points to.
	plmxml_api::Result ResolveLotURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Lot URI. Clears URI string and handle.
	plmxml_api::Result DeleteLotURI();
	
	//! Check if Lot URI is set
	plmxml_api::logical HasLotURI( ) const;
	

	//! Get StandardLife of this RealisedProduct
	plmxml_api::String GetStandardLife() const;

	//! Set StandardLife of this RealisedProduct
	plmxml_api::Result SetStandardLife( const plmxml_api::String &s );
	
	//! Check if StandardLife is set
	plmxml_api::logical HasStandardLife( ) const;
	
	//! Unset StandardLife
	plmxml_api::Result UnsetStandardLife( );

	//! Get OrderId of this RealisedProduct
	plmxml_api::String GetOrderId() const;

	//! Set OrderId of this RealisedProduct
	plmxml_api::Result SetOrderId( const plmxml_api::String &s );
	
	//! Check if OrderId is set
	plmxml_api::logical HasOrderId( ) const;
	
	//! Unset OrderId
	plmxml_api::Result UnsetOrderId( );
 
// <PLMXML_UserCode type="functionHeaderRealisedProduct" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRealisedProduct;


////////////////////////////////////////////////////////////////////////////////////
//! RealisedProductRevision class
/*!
\verbatim

      This represents a physical product, at a particular stage of maintenance.
      It corresponds to STEP AP239 "product_as_realized".

      Attributes:

      effectivityRefs:  Inherited from ProductRevision. References a
                        DateEffectivity, which is used to specify the effective
                        from and effective to dates.
      condition:        If part is serviceable or unserviceable.
      enrolmentDate:    Enrolment date.
      expirationDate:   Expiration date.
      isConsumable:     Is consumable.
      isEquipment:      Is equipment.
      isObsoletePart:   Is part obsolete.
      isLot:            Is lot.
      isMeter:          Is meter.
      isPanel:          Is panel.
      isRental:         Is rental.
      isRotable:        Is rotable.
      isSerialised:     Is serialised.
      isTool:           Is tool.
      keyword:          Keyword value.
      manufacturedDate: Manufactured date.
      manufacturerPartNumber: Part number referred by manufacturer.
      stockNumber:      Its national stock number which will be assigned to an
                        item.
      nomenclature:     Part nomenclature.
      orderDate:        Physical part order date.
      orderId:          Physical part order id.
      category:         Part category.
      partNumber:       Part number.
      physicalPartUID:  Unique identification for physical part.
      serialNumber:     Serial number if a serialised product.
      warrantyDate:     Warranty date.
      enterpriseRef:    If the part is owned by an Enterprise.
      manufacturerRef:  Refers to manufacturer name and cage code.
      overhaulDate:     Overhaul date and time of physical product.
      repairDate:       Repair date and time of physical product.
      
\endverbatim
*/
class PLMXML_MRO60_API RealisedProductRevision : public ProductRevision
{
public:
     
    //! Default constructor
    RealisedProductRevision( );
     
    //! Constructs a RealisedProductRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RealisedProductRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RealisedProductRevision();

private:

	//! Assignment operator
	RealisedProductRevision& operator=( const RealisedProductRevision& iSrc );

	//! Copy constructor
	RealisedProductRevision( const RealisedProductRevision& original );
     
public:

	//! Set IsLot
	plmxml_api::Result SetIsLot( plmxml_api::logical arg );

	//! Get IsLot
	plmxml_api::logical GetIsLot() const;

	//! Check if IsLot is set
	plmxml_api::logical HasIsLot() const;

	//! Unset IsLot
	plmxml_api::Result UnsetIsLot();

	//! Set IsSerialised
	plmxml_api::Result SetIsSerialised( plmxml_api::logical arg );

	//! Get IsSerialised
	plmxml_api::logical GetIsSerialised() const;

	//! Check if IsSerialised is set
	plmxml_api::logical HasIsSerialised() const;

	//! Unset IsSerialised
	plmxml_api::Result UnsetIsSerialised();

	//! Get SerialNumber of this RealisedProductRevision
	plmxml_api::String GetSerialNumber() const;

	//! Set SerialNumber of this RealisedProductRevision
	plmxml_api::Result SetSerialNumber( const plmxml_api::String &s );
	
	//! Check if SerialNumber is set
	plmxml_api::logical HasSerialNumber( ) const;
	
	//! Unset SerialNumber
	plmxml_api::Result UnsetSerialNumber( );

	//! Get WarrantyDate of this RealisedProductRevision
	plmxml_api::String GetWarrantyDate() const;

	//! Set WarrantyDate of this RealisedProductRevision
	plmxml_api::Result SetWarrantyDate( const plmxml_api::String &s );
	
	//! Check if WarrantyDate is set
	plmxml_api::logical HasWarrantyDate( ) const;
	
	//! Unset WarrantyDate
	plmxml_api::Result UnsetWarrantyDate( );

	//! Set IsConsumable
	plmxml_api::Result SetIsConsumable( plmxml_api::logical arg );

	//! Get IsConsumable
	plmxml_api::logical GetIsConsumable() const;

	//! Check if IsConsumable is set
	plmxml_api::logical HasIsConsumable() const;

	//! Unset IsConsumable
	plmxml_api::Result UnsetIsConsumable();

	//! Get ExpirationDate of this RealisedProductRevision
	plmxml_api::String GetExpirationDate() const;

	//! Set ExpirationDate of this RealisedProductRevision
	plmxml_api::Result SetExpirationDate( const plmxml_api::String &s );
	
	//! Check if ExpirationDate is set
	plmxml_api::logical HasExpirationDate( ) const;
	
	//! Unset ExpirationDate
	plmxml_api::Result UnsetExpirationDate( );

	//! Get OverhaulDate of this RealisedProductRevision
	plmxml_api::String GetOverhaulDate() const;

	//! Set OverhaulDate of this RealisedProductRevision
	plmxml_api::Result SetOverhaulDate( const plmxml_api::String &s );
	
	//! Check if OverhaulDate is set
	plmxml_api::logical HasOverhaulDate( ) const;
	
	//! Unset OverhaulDate
	plmxml_api::Result UnsetOverhaulDate( );

	//! Get OrderId of this RealisedProductRevision
	plmxml_api::String GetOrderId() const;

	//! Set OrderId of this RealisedProductRevision
	plmxml_api::Result SetOrderId( const plmxml_api::String &s );
	
	//! Check if OrderId is set
	plmxml_api::logical HasOrderId( ) const;
	
	//! Unset OrderId
	plmxml_api::Result UnsetOrderId( );

	//! Set IsRental
	plmxml_api::Result SetIsRental( plmxml_api::logical arg );

	//! Get IsRental
	plmxml_api::logical GetIsRental() const;

	//! Check if IsRental is set
	plmxml_api::logical HasIsRental() const;

	//! Unset IsRental
	plmxml_api::Result UnsetIsRental();

	//! Get ManufacturedDate of this RealisedProductRevision
	plmxml_api::String GetManufacturedDate() const;

	//! Set ManufacturedDate of this RealisedProductRevision
	plmxml_api::Result SetManufacturedDate( const plmxml_api::String &s );
	
	//! Check if ManufacturedDate is set
	plmxml_api::logical HasManufacturedDate( ) const;
	
	//! Unset ManufacturedDate
	plmxml_api::Result UnsetManufacturedDate( );

	//! Get Category of this RealisedProductRevision
	plmxml_api::String GetCategory() const;

	//! Set Category of this RealisedProductRevision
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );

	//! Get StockNumber of this RealisedProductRevision
	plmxml_api::String GetStockNumber() const;

	//! Set StockNumber of this RealisedProductRevision
	plmxml_api::Result SetStockNumber( const plmxml_api::String &s );
	
	//! Check if StockNumber is set
	plmxml_api::logical HasStockNumber( ) const;
	
	//! Unset StockNumber
	plmxml_api::Result UnsetStockNumber( );

	//! Get RepairDate of this RealisedProductRevision
	plmxml_api::String GetRepairDate() const;

	//! Set RepairDate of this RealisedProductRevision
	plmxml_api::Result SetRepairDate( const plmxml_api::String &s );
	
	//! Check if RepairDate is set
	plmxml_api::logical HasRepairDate( ) const;
	
	//! Unset RepairDate
	plmxml_api::Result UnsetRepairDate( );

	//! Set IsObsoletePart
	plmxml_api::Result SetIsObsoletePart( plmxml_api::logical arg );

	//! Get IsObsoletePart
	plmxml_api::logical GetIsObsoletePart() const;

	//! Check if IsObsoletePart is set
	plmxml_api::logical HasIsObsoletePart() const;

	//! Unset IsObsoletePart
	plmxml_api::Result UnsetIsObsoletePart();

	//! Get Nomenclature of this RealisedProductRevision
	plmxml_api::String GetNomenclature() const;

	//! Set Nomenclature of this RealisedProductRevision
	plmxml_api::Result SetNomenclature( const plmxml_api::String &s );
	
	//! Check if Nomenclature is set
	plmxml_api::logical HasNomenclature( ) const;
	
	//! Unset Nomenclature
	plmxml_api::Result UnsetNomenclature( );

	//! Set IsTool
	plmxml_api::Result SetIsTool( plmxml_api::logical arg );

	//! Get IsTool
	plmxml_api::logical GetIsTool() const;

	//! Check if IsTool is set
	plmxml_api::logical HasIsTool() const;

	//! Unset IsTool
	plmxml_api::Result UnsetIsTool();

	//! Get PartNumber of this RealisedProductRevision
	plmxml_api::String GetPartNumber() const;

	//! Set PartNumber of this RealisedProductRevision
	plmxml_api::Result SetPartNumber( const plmxml_api::String &s );
	
	//! Check if PartNumber is set
	plmxml_api::logical HasPartNumber( ) const;
	
	//! Unset PartNumber
	plmxml_api::Result UnsetPartNumber( );

	//! Set IsEquipment
	plmxml_api::Result SetIsEquipment( plmxml_api::logical arg );

	//! Get IsEquipment
	plmxml_api::logical GetIsEquipment() const;

	//! Check if IsEquipment is set
	plmxml_api::logical HasIsEquipment() const;

	//! Unset IsEquipment
	plmxml_api::Result UnsetIsEquipment();

	//! Set Condition
	plmxml_api::Result SetCondition( const eRealisedProductConditionEnum& arg );

	//! Get Condition
	eRealisedProductConditionEnum GetCondition() const;

	//! Get OrderDate of this RealisedProductRevision
	plmxml_api::String GetOrderDate() const;

	//! Set OrderDate of this RealisedProductRevision
	plmxml_api::Result SetOrderDate( const plmxml_api::String &s );
	
	//! Check if OrderDate is set
	plmxml_api::logical HasOrderDate( ) const;
	
	//! Unset OrderDate
	plmxml_api::Result UnsetOrderDate( );

	//! Get Manufacturer URI as plmxml_api::String
	plmxml_api::String GetManufacturerURI() const;

	//! Set Manufacturer URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::String& );
	
	//! Get the handle of Manufacturer URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Manufacturer URI. URI string is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::Handle& );
	
	//! Resolve Manufacturer URI and return an object (handle) it points to.
	plmxml_api::Result ResolveManufacturerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Manufacturer URI. Clears URI string and handle.
	plmxml_api::Result DeleteManufacturerURI();
	
	//! Check if Manufacturer URI is set
	plmxml_api::logical HasManufacturerURI( ) const;
	

	//! Set IsMeter
	plmxml_api::Result SetIsMeter( plmxml_api::logical arg );

	//! Get IsMeter
	plmxml_api::logical GetIsMeter() const;

	//! Check if IsMeter is set
	plmxml_api::logical HasIsMeter() const;

	//! Unset IsMeter
	plmxml_api::Result UnsetIsMeter();

	//! Get PhysicalPartUID of this RealisedProductRevision
	plmxml_api::String GetPhysicalPartUID() const;

	//! Set PhysicalPartUID of this RealisedProductRevision
	plmxml_api::Result SetPhysicalPartUID( const plmxml_api::String &s );
	
	//! Check if PhysicalPartUID is set
	plmxml_api::logical HasPhysicalPartUID( ) const;
	
	//! Unset PhysicalPartUID
	plmxml_api::Result UnsetPhysicalPartUID( );

	//! Set IsRotable
	plmxml_api::Result SetIsRotable( plmxml_api::logical arg );

	//! Get IsRotable
	plmxml_api::logical GetIsRotable() const;

	//! Check if IsRotable is set
	plmxml_api::logical HasIsRotable() const;

	//! Unset IsRotable
	plmxml_api::Result UnsetIsRotable();

	//! Get Enterprise URI as plmxml_api::String
	plmxml_api::String GetEnterpriseURI() const;

	//! Set Enterprise URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEnterpriseURI( const plmxml_api::String& );
	
	//! Get the handle of Enterprise URI. Does not resolve the URI.
	plmxml_api::Result GetEnterpriseURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Enterprise URI. URI string is unchanged.
	plmxml_api::Result SetEnterpriseURI( const plmxml_api::Handle& );
	
	//! Resolve Enterprise URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEnterpriseURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Enterprise URI. Clears URI string and handle.
	plmxml_api::Result DeleteEnterpriseURI();
	
	//! Check if Enterprise URI is set
	plmxml_api::logical HasEnterpriseURI( ) const;
	

	//! Set IsPanel
	plmxml_api::Result SetIsPanel( plmxml_api::logical arg );

	//! Get IsPanel
	plmxml_api::logical GetIsPanel() const;

	//! Check if IsPanel is set
	plmxml_api::logical HasIsPanel() const;

	//! Unset IsPanel
	plmxml_api::Result UnsetIsPanel();

	//! Get Keyword of this RealisedProductRevision
	plmxml_api::String GetKeyword() const;

	//! Set Keyword of this RealisedProductRevision
	plmxml_api::Result SetKeyword( const plmxml_api::String &s );
	
	//! Check if Keyword is set
	plmxml_api::logical HasKeyword( ) const;
	
	//! Unset Keyword
	plmxml_api::Result UnsetKeyword( );

	//! Get EnrolmentDate of this RealisedProductRevision
	plmxml_api::String GetEnrolmentDate() const;

	//! Set EnrolmentDate of this RealisedProductRevision
	plmxml_api::Result SetEnrolmentDate( const plmxml_api::String &s );
	
	//! Check if EnrolmentDate is set
	plmxml_api::logical HasEnrolmentDate( ) const;
	
	//! Unset EnrolmentDate
	plmxml_api::Result UnsetEnrolmentDate( );
 
// <PLMXML_UserCode type="functionHeaderRealisedProductRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRealisedProductRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Facility class
/*!
\verbatim

      Facility classes are defined to identify usage of physical parts in
      various facilities like Inventory, Repair Shop etc.
      
\endverbatim
*/
class PLMXML_MRO60_API Facility : public Structure
{
public:
     
    //! Default constructor
    Facility( );
     
    //! Constructs a Facility with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Facility( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Facility();

private:

	//! Assignment operator
	Facility& operator=( const Facility& iSrc );

	//! Copy constructor
	Facility( const Facility& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFacility" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFacility;


////////////////////////////////////////////////////////////////////////////////////
//! Inventory class
/*!
\verbatim

      Inventory class is defined to identify usage of physical parts in an
      Inventory.
      
\endverbatim
*/
class PLMXML_MRO60_API Inventory : public Facility
{
public:
     
    //! Default constructor
    Inventory( );
     
    //! Constructs a Inventory with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Inventory( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Inventory();

private:

	//! Assignment operator
	Inventory& operator=( const Inventory& iSrc );

	//! Copy constructor
	Inventory( const Inventory& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderInventory" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassInventory;


////////////////////////////////////////////////////////////////////////////////////
//! RepairShop class
/*!
\verbatim

      RepairShop class is defined to identify usage of physical parts in a
      Repair Shop.
      
\endverbatim
*/
class PLMXML_MRO60_API RepairShop : public Facility
{
public:
     
    //! Default constructor
    RepairShop( );
     
    //! Constructs a RepairShop with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RepairShop( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RepairShop();

private:

	//! Assignment operator
	RepairShop& operator=( const RepairShop& iSrc );

	//! Copy constructor
	RepairShop( const RepairShop& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRepairShop" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRepairShop;


////////////////////////////////////////////////////////////////////////////////////
//! RealisedFromRelation class
/*!
\verbatim

      This relation relates a ProductRevision to a RealisedProductRevision. The
      references in the inherited relatedRefs attribute must be in that order.

      Attributes:

      effectiveUnit:    Effective unit.
      relationIsActive: Is relation active.
      
\endverbatim
*/
class PLMXML_MRO60_API RealisedFromRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    RealisedFromRelation( );
     
    //! Constructs a RealisedFromRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RealisedFromRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RealisedFromRelation();

private:

	//! Assignment operator
	RealisedFromRelation& operator=( const RealisedFromRelation& iSrc );

	//! Copy constructor
	RealisedFromRelation( const RealisedFromRelation& original );
     
public:

	//! Get EffectiveUnit of this RealisedFromRelation
	plmxml_api::String GetEffectiveUnit() const;

	//! Set EffectiveUnit of this RealisedFromRelation
	plmxml_api::Result SetEffectiveUnit( const plmxml_api::String &s );
	
	//! Check if EffectiveUnit is set
	plmxml_api::logical HasEffectiveUnit( ) const;
	
	//! Unset EffectiveUnit
	plmxml_api::Result UnsetEffectiveUnit( );

	//! Set RelationIsActive
	plmxml_api::Result SetRelationIsActive( plmxml_api::logical arg );

	//! Get RelationIsActive
	plmxml_api::logical GetRelationIsActive() const;

	//! Check if RelationIsActive is set
	plmxml_api::logical HasRelationIsActive() const;

	//! Unset RelationIsActive
	plmxml_api::Result UnsetRelationIsActive();
 
// <PLMXML_UserCode type="functionHeaderRealisedFromRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRealisedFromRelation;


////////////////////////////////////////////////////////////////////////////////////
//! CharacteristicValueForRealisedProductRelation class
/*!
\verbatim

      This relation relates a RealisedProduct to a CharacteristicValue. The
      references in the inherited relatedRefs attribute must be in that order.
      If the rateIsEstimated on CharacteristicValue is set to true, the relation
      attributes are ignored.

      Attributes:

      isPropagated:     Life propagated to child physical part.
      
\endverbatim
*/
class PLMXML_MRO60_API CharacteristicValueForRealisedProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    CharacteristicValueForRealisedProductRelation( );
     
    //! Constructs a CharacteristicValueForRealisedProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CharacteristicValueForRealisedProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CharacteristicValueForRealisedProductRelation();

private:

	//! Assignment operator
	CharacteristicValueForRealisedProductRelation& operator=( const CharacteristicValueForRealisedProductRelation& iSrc );

	//! Copy constructor
	CharacteristicValueForRealisedProductRelation( const CharacteristicValueForRealisedProductRelation& original );
     
public:

	//! Set IsPropagated
	plmxml_api::Result SetIsPropagated( plmxml_api::logical arg );

	//! Get IsPropagated
	plmxml_api::logical GetIsPropagated() const;

	//! Check if IsPropagated is set
	plmxml_api::logical HasIsPropagated() const;

	//! Unset IsPropagated
	plmxml_api::Result UnsetIsPropagated();
 
// <PLMXML_UserCode type="functionHeaderCharacteristicValueForRealisedProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCharacteristicValueForRealisedProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! AllowedDeviationRelation class
/*!
\verbatim

      This relation is created if the RealisedProduct relates to a
      RealisedProduct that deviates from the design. The references in the
      inherited relatedRefs attribute must be in that order. The deviation
      requires some MROSpecification, referenced by deviationRef, for acceptance
      of the deviated RealisedProduct.

      Attributes:

      deviationRef:     Material review board document reference.
      
\endverbatim
*/
class PLMXML_MRO60_API AllowedDeviationRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    AllowedDeviationRelation( );
     
    //! Constructs a AllowedDeviationRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AllowedDeviationRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AllowedDeviationRelation();

private:

	//! Assignment operator
	AllowedDeviationRelation& operator=( const AllowedDeviationRelation& iSrc );

	//! Copy constructor
	AllowedDeviationRelation( const AllowedDeviationRelation& original );
     
public:

	//! Get Deviation URI as plmxml_api::String
	plmxml_api::String GetDeviationURI() const;

	//! Set Deviation URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDeviationURI( const plmxml_api::String& );
	
	//! Get the handle of Deviation URI. Does not resolve the URI.
	plmxml_api::Result GetDeviationURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Deviation URI. URI string is unchanged.
	plmxml_api::Result SetDeviationURI( const plmxml_api::Handle& );
	
	//! Resolve Deviation URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDeviationURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Deviation URI. Clears URI string and handle.
	plmxml_api::Result DeleteDeviationURI();
	
	//! Check if Deviation URI is set
	plmxml_api::logical HasDeviationURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderAllowedDeviationRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassAllowedDeviationRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RealisedProductInstance class
/*!
\verbatim

      This relation relates a parent RealisedProductRevision to a child
      RealisedProductRevision. The references in the inherited relatedRefs
      attribute must be in that order.

      Attributes:

      installationTimestamp: Installation timestamp.
      isInstalled:      To indicate if part is installed.
      partUsedIs:       Part used as is either "Preferred", "Substitute",
                        "Alternate" or "Deviated".
      unInstallationTimestamp: Uninstallation timestamp.
      occurrenceRef:    Occurrence reference.
      
\endverbatim
*/
class PLMXML_MRO60_API RealisedProductInstance : public ProductInstance
{
public:
     
    //! Default constructor
    RealisedProductInstance( );
     
    //! Constructs a RealisedProductInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RealisedProductInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RealisedProductInstance();

private:

	//! Assignment operator
	RealisedProductInstance& operator=( const RealisedProductInstance& iSrc );

	//! Copy constructor
	RealisedProductInstance( const RealisedProductInstance& original );
     
public:

	//! Set IsInstalled
	plmxml_api::Result SetIsInstalled( plmxml_api::logical arg );

	//! Get IsInstalled
	plmxml_api::logical GetIsInstalled() const;

	//! Check if IsInstalled is set
	plmxml_api::logical HasIsInstalled() const;

	//! Unset IsInstalled
	plmxml_api::Result UnsetIsInstalled();

	//! Get Occurrence URI as plmxml_api::String
	plmxml_api::String GetOccurrenceURI() const;

	//! Set Occurrence URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOccurrenceURI( const plmxml_api::String& );
	
	//! Get the handle of Occurrence URI. Does not resolve the URI.
	plmxml_api::Result GetOccurrenceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Occurrence URI. URI string is unchanged.
	plmxml_api::Result SetOccurrenceURI( const plmxml_api::Handle& );
	
	//! Resolve Occurrence URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOccurrenceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Occurrence URI. Clears URI string and handle.
	plmxml_api::Result DeleteOccurrenceURI();
	
	//! Check if Occurrence URI is set
	plmxml_api::logical HasOccurrenceURI( ) const;
	

	//! Get InstallationTimestamp of this RealisedProductInstance
	plmxml_api::String GetInstallationTimestamp() const;

	//! Set InstallationTimestamp of this RealisedProductInstance
	plmxml_api::Result SetInstallationTimestamp( const plmxml_api::String &s );
	
	//! Check if InstallationTimestamp is set
	plmxml_api::logical HasInstallationTimestamp( ) const;
	
	//! Unset InstallationTimestamp
	plmxml_api::Result UnsetInstallationTimestamp( );

	//! Set PartUsedIs
	plmxml_api::Result SetPartUsedIs( const ePartUsedIsEnum& arg );

	//! Get PartUsedIs
	ePartUsedIsEnum GetPartUsedIs() const;

	//! Get UnInstallationTimestamp of this RealisedProductInstance
	plmxml_api::String GetUnInstallationTimestamp() const;

	//! Set UnInstallationTimestamp of this RealisedProductInstance
	plmxml_api::Result SetUnInstallationTimestamp( const plmxml_api::String &s );
	
	//! Check if UnInstallationTimestamp is set
	plmxml_api::logical HasUnInstallationTimestamp( ) const;
	
	//! Unset UnInstallationTimestamp
	plmxml_api::Result UnsetUnInstallationTimestamp( );
 
// <PLMXML_UserCode type="functionHeaderRealisedProductInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRealisedProductInstance;


////////////////////////////////////////////////////////////////////////////////////
//! MROLocationRelation class
/*!
\verbatim

      This relation relates a RealisedProduct to a MROLocation. The references
      in the inherited relatedRefs attribute must be in that order.

      Attributes:

      isStored:         Is stored.
      timeIn:           Time in value. The time at which RealisedProduct was
                        placed in MROLocation.
      timeOut:          Time out value. The time at which RealisedProduct was
                        out of MROLocation.
      
\endverbatim
*/
class PLMXML_MRO60_API MROLocationRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    MROLocationRelation( );
     
    //! Constructs a MROLocationRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROLocationRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROLocationRelation();

private:

	//! Assignment operator
	MROLocationRelation& operator=( const MROLocationRelation& iSrc );

	//! Copy constructor
	MROLocationRelation( const MROLocationRelation& original );
     
public:

	//! Set IsStored
	plmxml_api::Result SetIsStored( plmxml_api::logical arg );

	//! Get IsStored
	plmxml_api::logical GetIsStored() const;

	//! Check if IsStored is set
	plmxml_api::logical HasIsStored() const;

	//! Unset IsStored
	plmxml_api::Result UnsetIsStored();

	//! Get TimeOut of this MROLocationRelation
	plmxml_api::String GetTimeOut() const;

	//! Set TimeOut of this MROLocationRelation
	plmxml_api::Result SetTimeOut( const plmxml_api::String &s );
	
	//! Check if TimeOut is set
	plmxml_api::logical HasTimeOut( ) const;
	
	//! Unset TimeOut
	plmxml_api::Result UnsetTimeOut( );

	//! Get TimeIn of this MROLocationRelation
	plmxml_api::String GetTimeIn() const;

	//! Set TimeIn of this MROLocationRelation
	plmxml_api::Result SetTimeIn( const plmxml_api::String &s );
	
	//! Check if TimeIn is set
	plmxml_api::logical HasTimeIn( ) const;
	
	//! Unset TimeIn
	plmxml_api::Result UnsetTimeIn( );
 
// <PLMXML_UserCode type="functionHeaderMROLocationRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROLocationRelation;


////////////////////////////////////////////////////////////////////////////////////
//! MROLocation class
/*!
\verbatim

      It represents the location.

      Attributes:

      name:             Inherited from Structure. The name of the location.
                        Required in this context.
      type:             MRO location type. Deprecated. You should use the Type
                        sub-element instead.

      Sub-elements:

      LocationType:     MRO location type. You should use this instead of the
                        type attribute.
      
\endverbatim
*/
class PLMXML_MRO60_API MROLocation : public Structure
{
public:
     
    //! Default constructor
    MROLocation( );
     
    //! Constructs a MROLocation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROLocation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROLocation();

private:

	//! Assignment operator
	MROLocation& operator=( const MROLocation& iSrc );

	//! Copy constructor
	MROLocation( const MROLocation& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eLocationEnum& arg );

	//! Get Type
	eLocationEnum GetType() const;

	//! Add LocationType child element to this MROLocation. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserEnum *AddLocationType();
     
	//! Set LocationType child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLocationType( UserEnum *arg );
     
	//! Get LocationType child element of this MROLocation.
	UserEnum *GetLocationType() const;
     
	//! Detach and delete LocationType child element tree from this MROLocation.
	void DeleteLocationType();
 
// <PLMXML_UserCode type="functionHeaderMROLocation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROLocation;


////////////////////////////////////////////////////////////////////////////////////
//! MROLocationRevision class
/*!
\verbatim

      It represents the Location revision.

      Attributes:

      name:             Inherited from StructureRevision. The name of the
                        location.
      code:             Location code.
      childRefs:        A list of MRO location references. Represents locations
                        contained by this location.
      
\endverbatim
*/
class PLMXML_MRO60_API MROLocationRevision : public StructureRevision
{
public:
     
    //! Default constructor
    MROLocationRevision( );
     
    //! Constructs a MROLocationRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROLocationRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROLocationRevision();

private:

	//! Assignment operator
	MROLocationRevision& operator=( const MROLocationRevision& iSrc );

	//! Copy constructor
	MROLocationRevision( const MROLocationRevision& original );
     
public:

	//! Get number of URIs in Child
	int NumberOfChildURIs() const;

	//! Get i'th URI in Child
	plmxml_api::String GetChildURI( int i ) const;

	//! Add a URI to Child array. Call ResolveChildURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddChildURI( const plmxml_api::String& u );

	//! Set i'th URI in Child array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetChildURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Child URI. Does not resolve the URI.
	plmxml_api::Result GetChildURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Child array.
	plmxml_api::Result AddChildURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Child array to point to 'handle'.
	plmxml_api::Result SetChildURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Child points to.
	plmxml_api::Result ResolveChildURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Child array.
	plmxml_api::Result DeleteChildURI( int i );

	//! Remove all URIs from Child array.
	plmxml_api::Result DeleteChildURIs( );
	
	//! Check if Child is set
	plmxml_api::logical HasChildURIs( ) const;

	//! Get Code of this MROLocationRevision
	plmxml_api::String GetCode() const;

	//! Set Code of this MROLocationRevision
	plmxml_api::Result SetCode( const plmxml_api::String &s );
	
	//! Check if Code is set
	plmxml_api::logical HasCode( ) const;
	
	//! Unset Code
	plmxml_api::Result UnsetCode( );
 
// <PLMXML_UserCode type="functionHeaderMROLocationRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROLocationRevision;


////////////////////////////////////////////////////////////////////////////////////
//! CharacteristicDefinition class
/*!
\verbatim

      Characteristic Definition type information.

      Attributes:

      name:             Inherited from Structure. The name of the
                        CharacteristicDefinition. Required in this context.
      subType:          Inherited from Structure. It can take one of the values
                        Life, Observation or Date in this context. If subType is
                        specified then the value for isCondition on
                        CharacteristicDefinitionRevision is ignored.
      derivedFromRefs:  Related characteristic definitions.
      
\endverbatim
*/
class PLMXML_MRO60_API CharacteristicDefinition : public Structure
{
public:
     
    //! Default constructor
    CharacteristicDefinition( );
     
    //! Constructs a CharacteristicDefinition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CharacteristicDefinition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CharacteristicDefinition();

private:

	//! Assignment operator
	CharacteristicDefinition& operator=( const CharacteristicDefinition& iSrc );

	//! Copy constructor
	CharacteristicDefinition( const CharacteristicDefinition& original );
     
public:

	//! Get number of URIs in DerivedFrom
	int NumberOfDerivedFromURIs() const;

	//! Get i'th URI in DerivedFrom
	plmxml_api::String GetDerivedFromURI( int i ) const;

	//! Add a URI to DerivedFrom array. Call ResolveDerivedFromURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDerivedFromURI( const plmxml_api::String& u );

	//! Set i'th URI in DerivedFrom array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDerivedFromURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of DerivedFrom URI. Does not resolve the URI.
	plmxml_api::Result GetDerivedFromURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to DerivedFrom array.
	plmxml_api::Result AddDerivedFromURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in DerivedFrom array to point to 'handle'.
	plmxml_api::Result SetDerivedFromURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in DerivedFrom points to.
	plmxml_api::Result ResolveDerivedFromURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from DerivedFrom array.
	plmxml_api::Result DeleteDerivedFromURI( int i );

	//! Remove all URIs from DerivedFrom array.
	plmxml_api::Result DeleteDerivedFromURIs( );
	
	//! Check if DerivedFrom is set
	plmxml_api::logical HasDerivedFromURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderCharacteristicDefinition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCharacteristicDefinition;


////////////////////////////////////////////////////////////////////////////////////
//! CharacteristicDefinitionRevision class
/*!
\verbatim

      Characteristic definition revision type information. The characteristic
      definition can be conditional derived.

      Attributes:

      derivedExpressionRef: References the derived characteristic definition
                        expression.
      isCondition:      If the characteristic definition is condition based
                        characteristic definition.
      isDerived:        If characteristic definition is derived characteristic
                        definition.
      isDefault:        Boolean to determine if this characteristic definition
                        is attached to all Neutral Structure Elements (NSE) by
                        default.
      isMetered:        Boolean to determine if this characteristic definition
                        is based on a meter which will require the storage of
                        the last meter.
      precision:        Decimal precision for this characteristic definition.
      unit:             Unit for the characteristic definition.
      unitRef:          References a Unit when unit is other.
      
\endverbatim
*/
class PLMXML_MRO60_API CharacteristicDefinitionRevision : public StructureRevision
{
public:
     
    //! Default constructor
    CharacteristicDefinitionRevision( );
     
    //! Constructs a CharacteristicDefinitionRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CharacteristicDefinitionRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CharacteristicDefinitionRevision();

private:

	//! Assignment operator
	CharacteristicDefinitionRevision& operator=( const CharacteristicDefinitionRevision& iSrc );

	//! Copy constructor
	CharacteristicDefinitionRevision( const CharacteristicDefinitionRevision& original );
     
public:

	//! Set IsMetered
	plmxml_api::Result SetIsMetered( plmxml_api::logical arg );

	//! Get IsMetered
	plmxml_api::logical GetIsMetered() const;

	//! Check if IsMetered is set
	plmxml_api::logical HasIsMetered() const;

	//! Unset IsMetered
	plmxml_api::Result UnsetIsMetered();

	//! Get DerivedExpression URI as plmxml_api::String
	plmxml_api::String GetDerivedExpressionURI() const;

	//! Set DerivedExpression URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDerivedExpressionURI( const plmxml_api::String& );
	
	//! Get the handle of DerivedExpression URI. Does not resolve the URI.
	plmxml_api::Result GetDerivedExpressionURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of DerivedExpression URI. URI string is unchanged.
	plmxml_api::Result SetDerivedExpressionURI( const plmxml_api::Handle& );
	
	//! Resolve DerivedExpression URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDerivedExpressionURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset DerivedExpression URI. Clears URI string and handle.
	plmxml_api::Result DeleteDerivedExpressionURI();
	
	//! Check if DerivedExpression URI is set
	plmxml_api::logical HasDerivedExpressionURI( ) const;
	

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();

	//! Set IsDefault
	plmxml_api::Result SetIsDefault( plmxml_api::logical arg );

	//! Get IsDefault
	plmxml_api::logical GetIsDefault() const;

	//! Check if IsDefault is set
	plmxml_api::logical HasIsDefault() const;

	//! Unset IsDefault
	plmxml_api::Result UnsetIsDefault();

	//! Set IsDerived
	plmxml_api::Result SetIsDerived( plmxml_api::logical arg );

	//! Get IsDerived
	plmxml_api::logical GetIsDerived() const;

	//! Check if IsDerived is set
	plmxml_api::logical HasIsDerived() const;

	//! Unset IsDerived
	plmxml_api::Result UnsetIsDerived();

	//! Set Unit
	plmxml_api::Result SetUnit( const ePeriodEnum& arg );

	//! Get Unit
	ePeriodEnum GetUnit() const;

	//! Set IsCondition
	plmxml_api::Result SetIsCondition( plmxml_api::logical arg );

	//! Get IsCondition
	plmxml_api::logical GetIsCondition() const;

	//! Check if IsCondition is set
	plmxml_api::logical HasIsCondition() const;

	//! Unset IsCondition
	plmxml_api::Result UnsetIsCondition();

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
	
 
// <PLMXML_UserCode type="functionHeaderCharacteristicDefinitionRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCharacteristicDefinitionRevision;


////////////////////////////////////////////////////////////////////////////////////
//! CharacteristicValue class
/*!
\verbatim

      Characteristic value information.

      Attributes:

      estimationPeriod: Holds estimated values for characteristic definition.
                        cycles and other values are not applicable here.
      rateIsEstimated:  Whether the characteristic value rate is estimated. If
                        this is set to true, the attributes on any referencing
                        CharacteristicValueForRealisedProductRelation are
                        ignored.
      value:            The value of this characteristic value. When the
                        characteristic value is a date and/or a time, dateValue
                        is used instead. Only one of value and dateValue should
                        be present.
      time:             Date and time at which this characteristic value was
                        accrued.
      definitionRef:    References the Characteristic definition for which this
                        value is defined.
      dateValue:        The value of this characteristic value when it is a date
                        and/or a time. Only one of dateValue and value should be
                        present.
      
\endverbatim
*/
class PLMXML_MRO60_API CharacteristicValue : public Managed
{
public:
     
    //! Default constructor
    CharacteristicValue( );
     
    //! Constructs a CharacteristicValue with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CharacteristicValue( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CharacteristicValue();

private:

	//! Assignment operator
	CharacteristicValue& operator=( const CharacteristicValue& iSrc );

	//! Copy constructor
	CharacteristicValue( const CharacteristicValue& original );
     
public:

	//! Get Time of this CharacteristicValue
	plmxml_api::String GetTime() const;

	//! Set Time of this CharacteristicValue
	plmxml_api::Result SetTime( const plmxml_api::String &s );
	
	//! Check if Time is set
	plmxml_api::logical HasTime( ) const;
	
	//! Unset Time
	plmxml_api::Result UnsetTime( );

	//! Set EstimationPeriod
	plmxml_api::Result SetEstimationPeriod( const ePeriodEnum& arg );

	//! Get EstimationPeriod
	ePeriodEnum GetEstimationPeriod() const;

	//! Get DateValue of this CharacteristicValue
	plmxml_api::String GetDateValue() const;

	//! Set DateValue of this CharacteristicValue
	plmxml_api::Result SetDateValue( const plmxml_api::String &s );
	
	//! Check if DateValue is set
	plmxml_api::logical HasDateValue( ) const;
	
	//! Unset DateValue
	plmxml_api::Result UnsetDateValue( );

	//! Set RateIsEstimated
	plmxml_api::Result SetRateIsEstimated( plmxml_api::logical arg );

	//! Get RateIsEstimated
	plmxml_api::logical GetRateIsEstimated() const;

	//! Check if RateIsEstimated is set
	plmxml_api::logical HasRateIsEstimated() const;

	//! Unset RateIsEstimated
	plmxml_api::Result UnsetRateIsEstimated();

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
	

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();
 
// <PLMXML_UserCode type="functionHeaderCharacteristicValue" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCharacteristicValue;


////////////////////////////////////////////////////////////////////////////////////
//! Lot class
/*!
\verbatim

      Lot information.

      Attributes:

      lotNumber:        Lot number.
      manufacturerRef:  Refers to manufacturing organisation.
      productRef:       Product reference. productId is required to identify
                        which product it belongs to.
      
\endverbatim
*/
class PLMXML_MRO60_API Lot : public Structure
{
public:
     
    //! Default constructor
    Lot( );
     
    //! Constructs a Lot with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Lot( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Lot();

private:

	//! Assignment operator
	Lot& operator=( const Lot& iSrc );

	//! Copy constructor
	Lot( const Lot& original );
     
public:

	//! Get LotNumber of this Lot
	plmxml_api::String GetLotNumber() const;

	//! Set LotNumber of this Lot
	plmxml_api::Result SetLotNumber( const plmxml_api::String &s );
	
	//! Check if LotNumber is set
	plmxml_api::logical HasLotNumber( ) const;
	
	//! Unset LotNumber
	plmxml_api::Result UnsetLotNumber( );

	//! Get Product URI as plmxml_api::String
	plmxml_api::String GetProductURI() const;

	//! Set Product URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::String& );
	
	//! Get the handle of Product URI. Does not resolve the URI.
	plmxml_api::Result GetProductURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Product URI. URI string is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::Handle& );
	
	//! Resolve Product URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProductURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Product URI. Clears URI string and handle.
	plmxml_api::Result DeleteProductURI();
	
	//! Check if Product URI is set
	plmxml_api::logical HasProductURI( ) const;
	

	//! Get Manufacturer URI as plmxml_api::String
	plmxml_api::String GetManufacturerURI() const;

	//! Set Manufacturer URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::String& );
	
	//! Get the handle of Manufacturer URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Manufacturer URI. URI string is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::Handle& );
	
	//! Resolve Manufacturer URI and return an object (handle) it points to.
	plmxml_api::Result ResolveManufacturerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Manufacturer URI. Clears URI string and handle.
	plmxml_api::Result DeleteManufacturerURI();
	
	//! Check if Manufacturer URI is set
	plmxml_api::logical HasManufacturerURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLot" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLot;


////////////////////////////////////////////////////////////////////////////////////
//! LotRevision class
/*!
\verbatim

      Lot revision type information.

      Attributes:

      expirationDate:   Expiration date.
      size:             Lot size.
      
\endverbatim
*/
class PLMXML_MRO60_API LotRevision : public StructureRevision
{
public:
     
    //! Default constructor
    LotRevision( );
     
    //! Constructs a LotRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LotRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LotRevision();

private:

	//! Assignment operator
	LotRevision& operator=( const LotRevision& iSrc );

	//! Copy constructor
	LotRevision( const LotRevision& original );
     
public:

	//! Set Size
	plmxml_api::Result SetSize( int arg );
     
	//! Get Size
	int GetSize() const;
     
	//! Check if Size is set
	plmxml_api::logical HasSize() const;
     
	//! Unset Size
	plmxml_api::Result UnsetSize();

	//! Get ExpirationDate of this LotRevision
	plmxml_api::String GetExpirationDate() const;

	//! Set ExpirationDate of this LotRevision
	plmxml_api::Result SetExpirationDate( const plmxml_api::String &s );
	
	//! Check if ExpirationDate is set
	plmxml_api::logical HasExpirationDate( ) const;
	
	//! Unset ExpirationDate
	plmxml_api::Result UnsetExpirationDate( );
 
// <PLMXML_UserCode type="functionHeaderLotRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLotRevision;


////////////////////////////////////////////////////////////////////////////////////
//! MROProduct class
/*!
\verbatim

      MROProduct common information. productId is required to identify this
      product.

      Attributes:

      type:             Type of part.
      
\endverbatim
*/
class PLMXML_MRO60_API MROProduct : public Product
{
public:
     
    //! Default constructor
    MROProduct( );
     
    //! Constructs a MROProduct with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROProduct( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROProduct();

private:

	//! Assignment operator
	MROProduct& operator=( const MROProduct& iSrc );

	//! Copy constructor
	MROProduct( const MROProduct& original );
     
public:

	//! Get Type of this MROProduct
	plmxml_api::String GetType() const;

	//! Set Type of this MROProduct
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );
 
// <PLMXML_UserCode type="functionHeaderMROProduct" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROProduct;


////////////////////////////////////////////////////////////////////////////////////
//! MROProductRevision class
/*!
\verbatim

      MROProduct revision type information.

      Attributes:

      harmonyCode:      Harmony code.
      isConsumable:     Is consumable.
      isEquipment:      Is equipment.
      isLot:            Is lot.
      isMeter:          Is meter.
      isPanel:          Is panel.
      isRotable:        Is rotable.
      isSerialised:     Is serialised.
      isTool:           Is tool.
      keyword:          Keyword value.
      lruContext:       Line replaceable unit context.
      maintenanceProgram: The maintenance program is the identification of the
                        regulatory program by which the MROProduct is
                        maintained.
      modelNumber:      Model number.
      partCategory:     Part category.
      pricingMode:      Pricing mode.
      shelfLifeDuration: The shelf life duration.
      shelfLifeUnit:    Unit for shelf life. cycles and other values are not
                        applicable here.
      stockNumber:      Its stock number which will be assigned to an item.
      
\endverbatim
*/
class PLMXML_MRO60_API MROProductRevision : public ProductRevision
{
public:
     
    //! Default constructor
    MROProductRevision( );
     
    //! Constructs a MROProductRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROProductRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROProductRevision();

private:

	//! Assignment operator
	MROProductRevision& operator=( const MROProductRevision& iSrc );

	//! Copy constructor
	MROProductRevision( const MROProductRevision& original );
     
public:

	//! Get ModelNumber of this MROProductRevision
	plmxml_api::String GetModelNumber() const;

	//! Set ModelNumber of this MROProductRevision
	plmxml_api::Result SetModelNumber( const plmxml_api::String &s );
	
	//! Check if ModelNumber is set
	plmxml_api::logical HasModelNumber( ) const;
	
	//! Unset ModelNumber
	plmxml_api::Result UnsetModelNumber( );

	//! Set PricingMode
	plmxml_api::Result SetPricingMode( const ePricingModeEnum& arg );

	//! Get PricingMode
	ePricingModeEnum GetPricingMode() const;

	//! Get PartCategory of this MROProductRevision
	plmxml_api::String GetPartCategory() const;

	//! Set PartCategory of this MROProductRevision
	plmxml_api::Result SetPartCategory( const plmxml_api::String &s );
	
	//! Check if PartCategory is set
	plmxml_api::logical HasPartCategory( ) const;
	
	//! Unset PartCategory
	plmxml_api::Result UnsetPartCategory( );

	//! Get StockNumber of this MROProductRevision
	plmxml_api::String GetStockNumber() const;

	//! Set StockNumber of this MROProductRevision
	plmxml_api::Result SetStockNumber( const plmxml_api::String &s );
	
	//! Check if StockNumber is set
	plmxml_api::logical HasStockNumber( ) const;
	
	//! Unset StockNumber
	plmxml_api::Result UnsetStockNumber( );

	//! Set IsPanel
	plmxml_api::Result SetIsPanel( plmxml_api::logical arg );

	//! Get IsPanel
	plmxml_api::logical GetIsPanel() const;

	//! Check if IsPanel is set
	plmxml_api::logical HasIsPanel() const;

	//! Unset IsPanel
	plmxml_api::Result UnsetIsPanel();

	//! Set IsMeter
	plmxml_api::Result SetIsMeter( plmxml_api::logical arg );

	//! Get IsMeter
	plmxml_api::logical GetIsMeter() const;

	//! Check if IsMeter is set
	plmxml_api::logical HasIsMeter() const;

	//! Unset IsMeter
	plmxml_api::Result UnsetIsMeter();

	//! Set ShelfLifeDuration
	plmxml_api::Result SetShelfLifeDuration( int arg );
     
	//! Get ShelfLifeDuration
	int GetShelfLifeDuration() const;
     
	//! Check if ShelfLifeDuration is set
	plmxml_api::logical HasShelfLifeDuration() const;
     
	//! Unset ShelfLifeDuration
	plmxml_api::Result UnsetShelfLifeDuration();

	//! Get Keyword of this MROProductRevision
	plmxml_api::String GetKeyword() const;

	//! Set Keyword of this MROProductRevision
	plmxml_api::Result SetKeyword( const plmxml_api::String &s );
	
	//! Check if Keyword is set
	plmxml_api::logical HasKeyword( ) const;
	
	//! Unset Keyword
	plmxml_api::Result UnsetKeyword( );

	//! Set ShelfLifeUnit
	plmxml_api::Result SetShelfLifeUnit( const ePeriodEnum& arg );

	//! Get ShelfLifeUnit
	ePeriodEnum GetShelfLifeUnit() const;

	//! Set IsRotable
	plmxml_api::Result SetIsRotable( plmxml_api::logical arg );

	//! Get IsRotable
	plmxml_api::logical GetIsRotable() const;

	//! Check if IsRotable is set
	plmxml_api::logical HasIsRotable() const;

	//! Unset IsRotable
	plmxml_api::Result UnsetIsRotable();

	//! Set IsLot
	plmxml_api::Result SetIsLot( plmxml_api::logical arg );

	//! Get IsLot
	plmxml_api::logical GetIsLot() const;

	//! Check if IsLot is set
	plmxml_api::logical HasIsLot() const;

	//! Unset IsLot
	plmxml_api::Result UnsetIsLot();

	//! Get HarmonyCode of this MROProductRevision
	plmxml_api::String GetHarmonyCode() const;

	//! Set HarmonyCode of this MROProductRevision
	plmxml_api::Result SetHarmonyCode( const plmxml_api::String &s );
	
	//! Check if HarmonyCode is set
	plmxml_api::logical HasHarmonyCode( ) const;
	
	//! Unset HarmonyCode
	plmxml_api::Result UnsetHarmonyCode( );

	//! Set IsSerialised
	plmxml_api::Result SetIsSerialised( plmxml_api::logical arg );

	//! Get IsSerialised
	plmxml_api::logical GetIsSerialised() const;

	//! Check if IsSerialised is set
	plmxml_api::logical HasIsSerialised() const;

	//! Unset IsSerialised
	plmxml_api::Result UnsetIsSerialised();

	//! Set IsEquipment
	plmxml_api::Result SetIsEquipment( plmxml_api::logical arg );

	//! Get IsEquipment
	plmxml_api::logical GetIsEquipment() const;

	//! Check if IsEquipment is set
	plmxml_api::logical HasIsEquipment() const;

	//! Unset IsEquipment
	plmxml_api::Result UnsetIsEquipment();

	//! Set IsConsumable
	plmxml_api::Result SetIsConsumable( plmxml_api::logical arg );

	//! Get IsConsumable
	plmxml_api::logical GetIsConsumable() const;

	//! Check if IsConsumable is set
	plmxml_api::logical HasIsConsumable() const;

	//! Unset IsConsumable
	plmxml_api::Result UnsetIsConsumable();

	//! Set IsTool
	plmxml_api::Result SetIsTool( plmxml_api::logical arg );

	//! Get IsTool
	plmxml_api::logical GetIsTool() const;

	//! Check if IsTool is set
	plmxml_api::logical HasIsTool() const;

	//! Unset IsTool
	plmxml_api::Result UnsetIsTool();

	//! Get MaintenanceProgram of this MROProductRevision
	plmxml_api::String GetMaintenanceProgram() const;

	//! Set MaintenanceProgram of this MROProductRevision
	plmxml_api::Result SetMaintenanceProgram( const plmxml_api::String &s );
	
	//! Check if MaintenanceProgram is set
	plmxml_api::logical HasMaintenanceProgram( ) const;
	
	//! Unset MaintenanceProgram
	plmxml_api::Result UnsetMaintenanceProgram( );

	//! Get LruContext of this MROProductRevision
	plmxml_api::String GetLruContext() const;

	//! Set LruContext of this MROProductRevision
	plmxml_api::Result SetLruContext( const plmxml_api::String &s );
	
	//! Check if LruContext is set
	plmxml_api::logical HasLruContext( ) const;
	
	//! Unset LruContext
	plmxml_api::Result UnsetLruContext( );
 
// <PLMXML_UserCode type="functionHeaderMROProductRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROProductRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Aircraft class
/*!
\verbatim

      Aircraft Information.
      
\endverbatim
*/
class PLMXML_MRO60_API Aircraft : public MROProduct
{
public:
     
    //! Default constructor
    Aircraft( );
     
    //! Constructs a Aircraft with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Aircraft( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Aircraft();

private:

	//! Assignment operator
	Aircraft& operator=( const Aircraft& iSrc );

	//! Copy constructor
	Aircraft( const Aircraft& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAircraft" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassAircraft;


////////////////////////////////////////////////////////////////////////////////////
//! AircraftRevision class
/*!
\verbatim

      Aircraft revision type information.
      
\endverbatim
*/
class PLMXML_MRO60_API AircraftRevision : public MROProductRevision
{
public:
     
    //! Default constructor
    AircraftRevision( );
     
    //! Constructs a AircraftRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AircraftRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AircraftRevision();

private:

	//! Assignment operator
	AircraftRevision& operator=( const AircraftRevision& iSrc );

	//! Copy constructor
	AircraftRevision( const AircraftRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAircraftRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassAircraftRevision;


////////////////////////////////////////////////////////////////////////////////////
//! PhysicalAircraft class
/*!
\verbatim

      Physical Aircraft type information.
      
\endverbatim
*/
class PLMXML_MRO60_API PhysicalAircraft : public RealisedProduct
{
public:
     
    //! Default constructor
    PhysicalAircraft( );
     
    //! Constructs a PhysicalAircraft with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PhysicalAircraft( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PhysicalAircraft();

private:

	//! Assignment operator
	PhysicalAircraft& operator=( const PhysicalAircraft& iSrc );

	//! Copy constructor
	PhysicalAircraft( const PhysicalAircraft& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPhysicalAircraft" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPhysicalAircraft;


////////////////////////////////////////////////////////////////////////////////////
//! PhysicalAircraftRevision class
/*!
\verbatim

      Physical aircraft revision type information.

      Attributes:

      registrationNumber: Registration number of aircraft.
      tailNumber:       Tail number of aircraft.
      
\endverbatim
*/
class PLMXML_MRO60_API PhysicalAircraftRevision : public RealisedProductRevision
{
public:
     
    //! Default constructor
    PhysicalAircraftRevision( );
     
    //! Constructs a PhysicalAircraftRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PhysicalAircraftRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PhysicalAircraftRevision();

private:

	//! Assignment operator
	PhysicalAircraftRevision& operator=( const PhysicalAircraftRevision& iSrc );

	//! Copy constructor
	PhysicalAircraftRevision( const PhysicalAircraftRevision& original );
     
public:

	//! Get TailNumber of this PhysicalAircraftRevision
	plmxml_api::String GetTailNumber() const;

	//! Set TailNumber of this PhysicalAircraftRevision
	plmxml_api::Result SetTailNumber( const plmxml_api::String &s );
	
	//! Check if TailNumber is set
	plmxml_api::logical HasTailNumber( ) const;
	
	//! Unset TailNumber
	plmxml_api::Result UnsetTailNumber( );

	//! Get RegistrationNumber of this PhysicalAircraftRevision
	plmxml_api::String GetRegistrationNumber() const;

	//! Set RegistrationNumber of this PhysicalAircraftRevision
	plmxml_api::Result SetRegistrationNumber( const plmxml_api::String &s );
	
	//! Check if RegistrationNumber is set
	plmxml_api::logical HasRegistrationNumber( ) const;
	
	//! Unset RegistrationNumber
	plmxml_api::Result UnsetRegistrationNumber( );
 
// <PLMXML_UserCode type="functionHeaderPhysicalAircraftRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPhysicalAircraftRevision;


////////////////////////////////////////////////////////////////////////////////////
//! MRODocument class
/*!
\verbatim

      Document type information.

      Attributes:

      name:             Inherited from Structure. The name of the document.
                        Required in this context.
      
\endverbatim
*/
class PLMXML_MRO60_API MRODocument : public Structure
{
public:
     
    //! Default constructor
    MRODocument( );
     
    //! Constructs a MRODocument with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MRODocument( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MRODocument();

private:

	//! Assignment operator
	MRODocument& operator=( const MRODocument& iSrc );

	//! Copy constructor
	MRODocument( const MRODocument& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMRODocument" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMRODocument;


////////////////////////////////////////////////////////////////////////////////////
//! MRODocumentRevision class
/*!
\verbatim

      Document revision type information.

      Attributes:

      title:            Document title.
      type:             Type describes the kind of document that this  document
                        represents. It could be an illustrated parts catalogue,
                        a maintenance manual, an airworthiness directive, or a
                        service bulletin or any other type defined by the user.
                        The user should be able to do searches based on the type
                        of document.
      
\endverbatim
*/
class PLMXML_MRO60_API MRODocumentRevision : public StructureRevision
{
public:
     
    //! Default constructor
    MRODocumentRevision( );
     
    //! Constructs a MRODocumentRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MRODocumentRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MRODocumentRevision();

private:

	//! Assignment operator
	MRODocumentRevision& operator=( const MRODocumentRevision& iSrc );

	//! Copy constructor
	MRODocumentRevision( const MRODocumentRevision& original );
     
public:

	//! Get Type of this MRODocumentRevision
	plmxml_api::String GetType() const;

	//! Set Type of this MRODocumentRevision
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get Title of this MRODocumentRevision
	plmxml_api::String GetTitle() const;

	//! Set Title of this MRODocumentRevision
	plmxml_api::Result SetTitle( const plmxml_api::String &s );
	
	//! Check if Title is set
	plmxml_api::logical HasTitle( ) const;
	
	//! Unset Title
	plmxml_api::Result UnsetTitle( );
 
// <PLMXML_UserCode type="functionHeaderMRODocumentRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMRODocumentRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Deviation class
/*!
\verbatim

      Material review board document type information.
      
\endverbatim
*/
class PLMXML_MRO60_API Deviation : public MRODocument
{
public:
     
    //! Default constructor
    Deviation( );
     
    //! Constructs a Deviation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Deviation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Deviation();

private:

	//! Assignment operator
	Deviation& operator=( const Deviation& iSrc );

	//! Copy constructor
	Deviation( const Deviation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDeviation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassDeviation;


////////////////////////////////////////////////////////////////////////////////////
//! DeviationRevision class
/*!
\verbatim

      Material review board document revision information.

      Attributes:

      defectDescription: Defect description.
      dispositionCode:  Material review board disposition code.
      repairDescription: Repair description.
      
\endverbatim
*/
class PLMXML_MRO60_API DeviationRevision : public MRODocumentRevision
{
public:
     
    //! Default constructor
    DeviationRevision( );
     
    //! Constructs a DeviationRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeviationRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeviationRevision();

private:

	//! Assignment operator
	DeviationRevision& operator=( const DeviationRevision& iSrc );

	//! Copy constructor
	DeviationRevision( const DeviationRevision& original );
     
public:

	//! Get DefectDescription of this DeviationRevision
	plmxml_api::String GetDefectDescription() const;

	//! Set DefectDescription of this DeviationRevision
	plmxml_api::Result SetDefectDescription( const plmxml_api::String &s );
	
	//! Check if DefectDescription is set
	plmxml_api::logical HasDefectDescription( ) const;
	
	//! Unset DefectDescription
	plmxml_api::Result UnsetDefectDescription( );

	//! Get RepairDescription of this DeviationRevision
	plmxml_api::String GetRepairDescription() const;

	//! Set RepairDescription of this DeviationRevision
	plmxml_api::Result SetRepairDescription( const plmxml_api::String &s );
	
	//! Check if RepairDescription is set
	plmxml_api::logical HasRepairDescription( ) const;
	
	//! Unset RepairDescription
	plmxml_api::Result UnsetRepairDescription( );

	//! Set DispositionCode
	plmxml_api::Result SetDispositionCode( const eDispositionCodeEnum& arg );

	//! Get DispositionCode
	eDispositionCodeEnum GetDispositionCode() const;
 
// <PLMXML_UserCode type="functionHeaderDeviationRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassDeviationRevision;


////////////////////////////////////////////////////////////////////////////////////
//! MROResource class
/*!
\verbatim

      MROResource type information.

      Attributes:

      resourceId:       MRO Resource Id.
      
\endverbatim
*/
class PLMXML_MRO60_API MROResource : public Structure
{
public:
     
    //! Default constructor
    MROResource( );
     
    //! Constructs a MROResource with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROResource( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROResource();

private:

	//! Assignment operator
	MROResource& operator=( const MROResource& iSrc );

	//! Copy constructor
	MROResource( const MROResource& original );
     
public:

	//! Get ResourceId of this MROResource
	plmxml_api::String GetResourceId() const;

	//! Set ResourceId of this MROResource
	plmxml_api::Result SetResourceId( const plmxml_api::String &s );
	
	//! Check if ResourceId is set
	plmxml_api::logical HasResourceId( ) const;
	
	//! Unset ResourceId
	plmxml_api::Result UnsetResourceId( );
 
// <PLMXML_UserCode type="functionHeaderMROResource" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROResource;


////////////////////////////////////////////////////////////////////////////////////
//! MROResourceRevision class
/*!
\verbatim

\endverbatim
*/
class PLMXML_MRO60_API MROResourceRevision : public StructureRevision
{
public:
     
    //! Default constructor
    MROResourceRevision( );
     
    //! Constructs a MROResourceRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROResourceRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROResourceRevision();

private:

	//! Assignment operator
	MROResourceRevision& operator=( const MROResourceRevision& iSrc );

	//! Copy constructor
	MROResourceRevision( const MROResourceRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMROResourceRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROResourceRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Crew class
/*!
\verbatim

      Crew type information.
      
\endverbatim
*/
class PLMXML_MRO60_API Crew : public MROResource
{
public:
     
    //! Default constructor
    Crew( );
     
    //! Constructs a Crew with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Crew( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Crew();

private:

	//! Assignment operator
	Crew& operator=( const Crew& iSrc );

	//! Copy constructor
	Crew( const Crew& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderCrew" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCrew;


////////////////////////////////////////////////////////////////////////////////////
//! CrewRevision class
/*!
\verbatim

      Crew revision information.

      Attributes:

      name:             Inherited from MROResourceRevision. The name of the
                        crew. Required in this context.
      subResourceRefs:  A list of MROResource references.
      locationRef:      The location for the crew.
      
\endverbatim
*/
class PLMXML_MRO60_API CrewRevision : public MROResourceRevision
{
public:
     
    //! Default constructor
    CrewRevision( );
     
    //! Constructs a CrewRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CrewRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CrewRevision();

private:

	//! Assignment operator
	CrewRevision& operator=( const CrewRevision& iSrc );

	//! Copy constructor
	CrewRevision( const CrewRevision& original );
     
public:

	//! Get number of URIs in SubResource
	int NumberOfSubResourceURIs() const;

	//! Get i'th URI in SubResource
	plmxml_api::String GetSubResourceURI( int i ) const;

	//! Add a URI to SubResource array. Call ResolveSubResourceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSubResourceURI( const plmxml_api::String& u );

	//! Set i'th URI in SubResource array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSubResourceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SubResource URI. Does not resolve the URI.
	plmxml_api::Result GetSubResourceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SubResource array.
	plmxml_api::Result AddSubResourceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SubResource array to point to 'handle'.
	plmxml_api::Result SetSubResourceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SubResource points to.
	plmxml_api::Result ResolveSubResourceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SubResource array.
	plmxml_api::Result DeleteSubResourceURI( int i );

	//! Remove all URIs from SubResource array.
	plmxml_api::Result DeleteSubResourceURIs( );
	
	//! Check if SubResource is set
	plmxml_api::logical HasSubResourceURIs( ) const;

	//! Get Location URI as plmxml_api::String
	plmxml_api::String GetLocationURI() const;

	//! Set Location URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetLocationURI( const plmxml_api::String& );
	
	//! Get the handle of Location URI. Does not resolve the URI.
	plmxml_api::Result GetLocationURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Location URI. URI string is unchanged.
	plmxml_api::Result SetLocationURI( const plmxml_api::Handle& );
	
	//! Resolve Location URI and return an object (handle) it points to.
	plmxml_api::Result ResolveLocationURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Location URI. Clears URI string and handle.
	plmxml_api::Result DeleteLocationURI();
	
	//! Check if Location URI is set
	plmxml_api::logical HasLocationURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderCrewRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCrewRevision;


////////////////////////////////////////////////////////////////////////////////////
//! MROPerson class
/*!
\verbatim

      Person information.
      
\endverbatim
*/
class PLMXML_MRO60_API MROPerson : public MROResource
{
public:
     
    //! Default constructor
    MROPerson( );
     
    //! Constructs a MROPerson with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROPerson( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROPerson();

private:

	//! Assignment operator
	MROPerson& operator=( const MROPerson& iSrc );

	//! Copy constructor
	MROPerson( const MROPerson& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMROPerson" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROPerson;


////////////////////////////////////////////////////////////////////////////////////
//! MROPersonRevision class
/*!
\verbatim

      Person revision information.

      Attributes:

      personRef:        Reference to participating user in the system and the
                        person information.
      
\endverbatim
*/
class PLMXML_MRO60_API MROPersonRevision : public MROResourceRevision
{
public:
     
    //! Default constructor
    MROPersonRevision( );
     
    //! Constructs a MROPersonRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROPersonRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROPersonRevision();

private:

	//! Assignment operator
	MROPersonRevision& operator=( const MROPersonRevision& iSrc );

	//! Copy constructor
	MROPersonRevision( const MROPersonRevision& original );
     
public:

	//! Get Person URI as plmxml_api::String
	plmxml_api::String GetPersonURI() const;

	//! Set Person URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPersonURI( const plmxml_api::String& );
	
	//! Get the handle of Person URI. Does not resolve the URI.
	plmxml_api::Result GetPersonURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Person URI. URI string is unchanged.
	plmxml_api::Result SetPersonURI( const plmxml_api::Handle& );
	
	//! Resolve Person URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePersonURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Person URI. Clears URI string and handle.
	plmxml_api::Result DeletePersonURI();
	
	//! Check if Person URI is set
	plmxml_api::logical HasPersonURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderMROPersonRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROPersonRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Skill class
/*!
\verbatim

      Skill information.

      Attributes:

      name:             Inherited from Structure. The name of the skill.
                        Required in this context.
      type:             Skill type. person or crew.
      disciplineRefs:   A list of references to Discipline elements.
      
\endverbatim
*/
class PLMXML_MRO60_API Skill : public Structure
{
public:
     
    //! Default constructor
    Skill( );
     
    //! Constructs a Skill with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Skill( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Skill();

private:

	//! Assignment operator
	Skill& operator=( const Skill& iSrc );

	//! Copy constructor
	Skill( const Skill& original );
     
public:

	//! Get number of URIs in Discipline
	int NumberOfDisciplineURIs() const;

	//! Get i'th URI in Discipline
	plmxml_api::String GetDisciplineURI( int i ) const;

	//! Add a URI to Discipline array. Call ResolveDisciplineURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDisciplineURI( const plmxml_api::String& u );

	//! Set i'th URI in Discipline array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDisciplineURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Discipline URI. Does not resolve the URI.
	plmxml_api::Result GetDisciplineURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Discipline array.
	plmxml_api::Result AddDisciplineURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Discipline array to point to 'handle'.
	plmxml_api::Result SetDisciplineURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Discipline points to.
	plmxml_api::Result ResolveDisciplineURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Discipline array.
	plmxml_api::Result DeleteDisciplineURI( int i );

	//! Remove all URIs from Discipline array.
	plmxml_api::Result DeleteDisciplineURIs( );
	
	//! Check if Discipline is set
	plmxml_api::logical HasDisciplineURIs( ) const;

	//! Set Type
	plmxml_api::Result SetType( const eSkillEnum& arg );

	//! Get Type
	eSkillEnum GetType() const;
 
// <PLMXML_UserCode type="functionHeaderSkill" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassSkill;


////////////////////////////////////////////////////////////////////////////////////
//! SkillRevision class
/*!
\verbatim

      Skill revision type.

      Attributes:

      role:             Role for the skill.
      code:             Skill code.
      specialityCode:   The skill specialty code of each person required to
                        complete the task.
      resourceRefs:     A list of MRO Resource references.
      skillRefs:        A list of Skill references.
      
\endverbatim
*/
class PLMXML_MRO60_API SkillRevision : public StructureRevision
{
public:
     
    //! Default constructor
    SkillRevision( );
     
    //! Constructs a SkillRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SkillRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SkillRevision();

private:

	//! Assignment operator
	SkillRevision& operator=( const SkillRevision& iSrc );

	//! Copy constructor
	SkillRevision( const SkillRevision& original );
     
public:

	//! Get SpecialityCode of this SkillRevision
	plmxml_api::String GetSpecialityCode() const;

	//! Set SpecialityCode of this SkillRevision
	plmxml_api::Result SetSpecialityCode( const plmxml_api::String &s );
	
	//! Check if SpecialityCode is set
	plmxml_api::logical HasSpecialityCode( ) const;
	
	//! Unset SpecialityCode
	plmxml_api::Result UnsetSpecialityCode( );

	//! Get Role of this SkillRevision
	plmxml_api::String GetRole() const;

	//! Set Role of this SkillRevision
	plmxml_api::Result SetRole( const plmxml_api::String &s );
	
	//! Check if Role is set
	plmxml_api::logical HasRole( ) const;
	
	//! Unset Role
	plmxml_api::Result UnsetRole( );

	//! Get Code of this SkillRevision
	plmxml_api::String GetCode() const;

	//! Set Code of this SkillRevision
	plmxml_api::Result SetCode( const plmxml_api::String &s );
	
	//! Check if Code is set
	plmxml_api::logical HasCode( ) const;
	
	//! Unset Code
	plmxml_api::Result UnsetCode( );

	//! Get number of URIs in Skill
	int NumberOfSkillURIs() const;

	//! Get i'th URI in Skill
	plmxml_api::String GetSkillURI( int i ) const;

	//! Add a URI to Skill array. Call ResolveSkillURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSkillURI( const plmxml_api::String& u );

	//! Set i'th URI in Skill array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSkillURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Skill URI. Does not resolve the URI.
	plmxml_api::Result GetSkillURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Skill array.
	plmxml_api::Result AddSkillURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Skill array to point to 'handle'.
	plmxml_api::Result SetSkillURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Skill points to.
	plmxml_api::Result ResolveSkillURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Skill array.
	plmxml_api::Result DeleteSkillURI( int i );

	//! Remove all URIs from Skill array.
	plmxml_api::Result DeleteSkillURIs( );
	
	//! Check if Skill is set
	plmxml_api::logical HasSkillURIs( ) const;

	//! Get number of URIs in Resource
	int NumberOfResourceURIs() const;

	//! Get i'th URI in Resource
	plmxml_api::String GetResourceURI( int i ) const;

	//! Add a URI to Resource array. Call ResolveResourceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddResourceURI( const plmxml_api::String& u );

	//! Set i'th URI in Resource array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetResourceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Resource URI. Does not resolve the URI.
	plmxml_api::Result GetResourceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Resource array.
	plmxml_api::Result AddResourceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Resource array to point to 'handle'.
	plmxml_api::Result SetResourceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Resource points to.
	plmxml_api::Result ResolveResourceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Resource array.
	plmxml_api::Result DeleteResourceURI( int i );

	//! Remove all URIs from Resource array.
	plmxml_api::Result DeleteResourceURIs( );
	
	//! Check if Resource is set
	plmxml_api::logical HasResourceURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderSkillRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassSkillRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Fleet class
/*!
\verbatim

      Fleet type information.

      Attributes:

      name:             Inherited from Managed. The name of the fleet. Required
                        in this context.
      title:            Fleet title.
      type:             Type of the fleet.
      memberRefs:       A list of RealisedProduct references.
      relatedRefs:      A list of related fleet references.
      
\endverbatim
*/
class PLMXML_MRO60_API Fleet : public Managed
{
public:
     
    //! Default constructor
    Fleet( );
     
    //! Constructs a Fleet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Fleet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Fleet();

private:

	//! Assignment operator
	Fleet& operator=( const Fleet& iSrc );

	//! Copy constructor
	Fleet( const Fleet& original );
     
public:

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

	//! Get Title of this Fleet
	plmxml_api::String GetTitle() const;

	//! Set Title of this Fleet
	plmxml_api::Result SetTitle( const plmxml_api::String &s );
	
	//! Check if Title is set
	plmxml_api::logical HasTitle( ) const;
	
	//! Unset Title
	plmxml_api::Result UnsetTitle( );

	//! Get Type of this Fleet
	plmxml_api::String GetType() const;

	//! Set Type of this Fleet
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get number of URIs in Related
	int NumberOfRelatedURIs() const;

	//! Get i'th URI in Related
	plmxml_api::String GetRelatedURI( int i ) const;

	//! Add a URI to Related array. Call ResolveRelatedURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRelatedURI( const plmxml_api::String& u );

	//! Set i'th URI in Related array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRelatedURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Related URI. Does not resolve the URI.
	plmxml_api::Result GetRelatedURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Related array.
	plmxml_api::Result AddRelatedURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Related array to point to 'handle'.
	plmxml_api::Result SetRelatedURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Related points to.
	plmxml_api::Result ResolveRelatedURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Related array.
	plmxml_api::Result DeleteRelatedURI( int i );

	//! Remove all URIs from Related array.
	plmxml_api::Result DeleteRelatedURIs( );
	
	//! Check if Related is set
	plmxml_api::logical HasRelatedURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderFleet" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFleet;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceBulletin class
/*!
\verbatim

      Service bulletin type information.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceBulletin : public MRODocument
{
public:
     
    //! Default constructor
    ServiceBulletin( );
     
    //! Constructs a ServiceBulletin with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceBulletin( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceBulletin();

private:

	//! Assignment operator
	ServiceBulletin& operator=( const ServiceBulletin& iSrc );

	//! Copy constructor
	ServiceBulletin( const ServiceBulletin& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderServiceBulletin" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceBulletin;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceBulletinRevision class
/*!
\verbatim

      Service bulletin revision type information.

      Attributes:

      compliance:       Service bulletin compliance.
      purpose:          Service bulletin purpose.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceBulletinRevision : public MRODocumentRevision
{
public:
     
    //! Default constructor
    ServiceBulletinRevision( );
     
    //! Constructs a ServiceBulletinRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceBulletinRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceBulletinRevision();

private:

	//! Assignment operator
	ServiceBulletinRevision& operator=( const ServiceBulletinRevision& iSrc );

	//! Copy constructor
	ServiceBulletinRevision( const ServiceBulletinRevision& original );
     
public:

	//! Get Purpose of this ServiceBulletinRevision
	plmxml_api::String GetPurpose() const;

	//! Set Purpose of this ServiceBulletinRevision
	plmxml_api::Result SetPurpose( const plmxml_api::String &s );
	
	//! Check if Purpose is set
	plmxml_api::logical HasPurpose( ) const;
	
	//! Unset Purpose
	plmxml_api::Result UnsetPurpose( );

	//! Get Compliance of this ServiceBulletinRevision
	plmxml_api::String GetCompliance() const;

	//! Set Compliance of this ServiceBulletinRevision
	plmxml_api::Result SetCompliance( const plmxml_api::String &s );
	
	//! Check if Compliance is set
	plmxml_api::logical HasCompliance( ) const;
	
	//! Unset Compliance
	plmxml_api::Result UnsetCompliance( );
 
// <PLMXML_UserCode type="functionHeaderServiceBulletinRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceBulletinRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Kit class
/*!
\verbatim

\endverbatim
*/
class PLMXML_MRO60_API Kit : public MROProduct
{
public:
     
    //! Default constructor
    Kit( );
     
    //! Constructs a Kit with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Kit( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Kit();

private:

	//! Assignment operator
	Kit& operator=( const Kit& iSrc );

	//! Copy constructor
	Kit( const Kit& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderKit" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassKit;


////////////////////////////////////////////////////////////////////////////////////
//! KitRevision class
/*!
\verbatim

      Kit revision type information.
      
\endverbatim
*/
class PLMXML_MRO60_API KitRevision : public MROProductRevision
{
public:
     
    //! Default constructor
    KitRevision( );
     
    //! Constructs a KitRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    KitRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~KitRevision();

private:

	//! Assignment operator
	KitRevision& operator=( const KitRevision& iSrc );

	//! Copy constructor
	KitRevision( const KitRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderKitRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassKitRevision;


////////////////////////////////////////////////////////////////////////////////////
//! LaborGroup class
/*!
\verbatim

      Labor group information.

      Attributes:

      name:             Inherited from Structure. The name of the labor group.
                        Required in this context.
      
\endverbatim
*/
class PLMXML_MRO60_API LaborGroup : public Structure
{
public:
     
    //! Default constructor
    LaborGroup( );
     
    //! Constructs a LaborGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LaborGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LaborGroup();

private:

	//! Assignment operator
	LaborGroup& operator=( const LaborGroup& iSrc );

	//! Copy constructor
	LaborGroup( const LaborGroup& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderLaborGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLaborGroup;


////////////////////////////////////////////////////////////////////////////////////
//! LaborGroupRevision class
/*!
\verbatim

      Labor group revision type information.

      Attributes:

      moneyRef:         Money reference to specify rate and currency.
      skillRefs:        A list of Skill references.
      
\endverbatim
*/
class PLMXML_MRO60_API LaborGroupRevision : public StructureRevision
{
public:
     
    //! Default constructor
    LaborGroupRevision( );
     
    //! Constructs a LaborGroupRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LaborGroupRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LaborGroupRevision();

private:

	//! Assignment operator
	LaborGroupRevision& operator=( const LaborGroupRevision& iSrc );

	//! Copy constructor
	LaborGroupRevision( const LaborGroupRevision& original );
     
public:

	//! Get number of URIs in Skill
	int NumberOfSkillURIs() const;

	//! Get i'th URI in Skill
	plmxml_api::String GetSkillURI( int i ) const;

	//! Add a URI to Skill array. Call ResolveSkillURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSkillURI( const plmxml_api::String& u );

	//! Set i'th URI in Skill array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSkillURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Skill URI. Does not resolve the URI.
	plmxml_api::Result GetSkillURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Skill array.
	plmxml_api::Result AddSkillURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Skill array to point to 'handle'.
	plmxml_api::Result SetSkillURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Skill points to.
	plmxml_api::Result ResolveSkillURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Skill array.
	plmxml_api::Result DeleteSkillURI( int i );

	//! Remove all URIs from Skill array.
	plmxml_api::Result DeleteSkillURIs( );
	
	//! Check if Skill is set
	plmxml_api::logical HasSkillURIs( ) const;

	//! Get Money URI as plmxml_api::String
	plmxml_api::String GetMoneyURI() const;

	//! Set Money URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMoneyURI( const plmxml_api::String& );
	
	//! Get the handle of Money URI. Does not resolve the URI.
	plmxml_api::Result GetMoneyURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Money URI. URI string is unchanged.
	plmxml_api::Result SetMoneyURI( const plmxml_api::Handle& );
	
	//! Resolve Money URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMoneyURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Money URI. Clears URI string and handle.
	plmxml_api::Result DeleteMoneyURI();
	
	//! Check if Money URI is set
	plmxml_api::logical HasMoneyURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLaborGroupRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLaborGroupRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Enterprise class
/*!
\verbatim

      Enterprise information.

      Attributes:

      name:             Inherited from Structure. The name of the enterprise.
                        Required in this context.
      
\endverbatim
*/
class PLMXML_MRO60_API Enterprise : public Structure
{
public:
     
    //! Default constructor
    Enterprise( );
     
    //! Constructs a Enterprise with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Enterprise( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Enterprise();

private:

	//! Assignment operator
	Enterprise& operator=( const Enterprise& iSrc );

	//! Copy constructor
	Enterprise( const Enterprise& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderEnterprise" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassEnterprise;


////////////////////////////////////////////////////////////////////////////////////
//! EnterpriseRevision class
/*!
\verbatim

      Enterprise revision information.

      Attributes:

      discountPercent:  This attribute holds the percent by which a charge would
                        be marked up or marked down for this customer based on
                        the straight rate that is found in the labor group. It
                        is used for calculating the charge on a work order.
      type:             Enterprise type.
      isInternal:       A boolean value, set to true if the enterprise is part
                        of the user’s internal enterprise and false if not.
      isIssuing:        A boolean value, set to true if the enterprise issues
                        documentation and false if not.
      roleRefs:         A list of Enterprise role references.
      
\endverbatim
*/
class PLMXML_MRO60_API EnterpriseRevision : public StructureRevision
{
public:
     
    //! Default constructor
    EnterpriseRevision( );
     
    //! Constructs a EnterpriseRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    EnterpriseRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~EnterpriseRevision();

private:

	//! Assignment operator
	EnterpriseRevision& operator=( const EnterpriseRevision& iSrc );

	//! Copy constructor
	EnterpriseRevision( const EnterpriseRevision& original );
     
public:

	//! Set IsIssuing
	plmxml_api::Result SetIsIssuing( plmxml_api::logical arg );

	//! Get IsIssuing
	plmxml_api::logical GetIsIssuing() const;

	//! Check if IsIssuing is set
	plmxml_api::logical HasIsIssuing() const;

	//! Unset IsIssuing
	plmxml_api::Result UnsetIsIssuing();

	//! Set DiscountPercent
	plmxml_api::Result SetDiscountPercent( double arg );

     //! Get DiscountPercent
	double GetDiscountPercent() const;

	//! Check if DiscountPercent is set
	plmxml_api::logical HasDiscountPercent() const;

	//! Unset DiscountPercent
	plmxml_api::Result UnsetDiscountPercent();

	//! Get Type of this EnterpriseRevision
	plmxml_api::String GetType() const;

	//! Set Type of this EnterpriseRevision
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get number of URIs in Role
	int NumberOfRoleURIs() const;

	//! Get i'th URI in Role
	plmxml_api::String GetRoleURI( int i ) const;

	//! Add a URI to Role array. Call ResolveRoleURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRoleURI( const plmxml_api::String& u );

	//! Set i'th URI in Role array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRoleURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Role URI. Does not resolve the URI.
	plmxml_api::Result GetRoleURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Role array.
	plmxml_api::Result AddRoleURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Role array to point to 'handle'.
	plmxml_api::Result SetRoleURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Role points to.
	plmxml_api::Result ResolveRoleURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Role array.
	plmxml_api::Result DeleteRoleURI( int i );

	//! Remove all URIs from Role array.
	plmxml_api::Result DeleteRoleURIs( );
	
	//! Check if Role is set
	plmxml_api::logical HasRoleURIs( ) const;

	//! Set IsInternal
	plmxml_api::Result SetIsInternal( plmxml_api::logical arg );

	//! Get IsInternal
	plmxml_api::logical GetIsInternal() const;

	//! Check if IsInternal is set
	plmxml_api::logical HasIsInternal() const;

	//! Unset IsInternal
	plmxml_api::Result UnsetIsInternal();
 
// <PLMXML_UserCode type="functionHeaderEnterpriseRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassEnterpriseRevision;


////////////////////////////////////////////////////////////////////////////////////
//! EnterpriseRole class
/*!
\verbatim

      Enterprise role information.

      Attributes:

      role:             Enterprise role.
      
\endverbatim
*/
class PLMXML_MRO60_API EnterpriseRole : public Managed
{
public:
     
    //! Default constructor
    EnterpriseRole( );
     
    //! Constructs a EnterpriseRole with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    EnterpriseRole( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~EnterpriseRole();

private:

	//! Assignment operator
	EnterpriseRole& operator=( const EnterpriseRole& iSrc );

	//! Copy constructor
	EnterpriseRole( const EnterpriseRole& original );
     
public:

	//! Set Role
	plmxml_api::Result SetRole( const plmxml60::eOrganisationRoleEnum& arg );

	//! Get Role
	plmxml60::eOrganisationRoleEnum GetRole() const;
 
// <PLMXML_UserCode type="functionHeaderEnterpriseRole" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassEnterpriseRole;


////////////////////////////////////////////////////////////////////////////////////
//! ProductRequest class
/*!
\verbatim

      Part request information.

      Attributes:

      creditAccount:    Credit account.
      debitAccount:     Debit account.
      requestOwner:     Request owner.
      quantity:         Quantity to be turned-in.
      reasonForRequest: Reason for request.
      remarks:          Remarks if any.
      requestID:        Request Id.
      status:           Request status.
      turnInDate:       Date of turn-in.
      workOrderNumber:  Work order number.
      productRef:       Product reference.
      inventoryLocationRef: Inventory reference.
      
\endverbatim
*/
class PLMXML_MRO60_API ProductRequest : public Managed
{
public:
     
    //! Default constructor
    ProductRequest( );
     
    //! Constructs a ProductRequest with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProductRequest( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProductRequest();

private:

	//! Assignment operator
	ProductRequest& operator=( const ProductRequest& iSrc );

	//! Copy constructor
	ProductRequest( const ProductRequest& original );
     
public:

	//! Get WorkOrderNumber of this ProductRequest
	plmxml_api::String GetWorkOrderNumber() const;

	//! Set WorkOrderNumber of this ProductRequest
	plmxml_api::Result SetWorkOrderNumber( const plmxml_api::String &s );
	
	//! Check if WorkOrderNumber is set
	plmxml_api::logical HasWorkOrderNumber( ) const;
	
	//! Unset WorkOrderNumber
	plmxml_api::Result UnsetWorkOrderNumber( );

	//! Get RequestOwner of this ProductRequest
	plmxml_api::String GetRequestOwner() const;

	//! Set RequestOwner of this ProductRequest
	plmxml_api::Result SetRequestOwner( const plmxml_api::String &s );
	
	//! Check if RequestOwner is set
	plmxml_api::logical HasRequestOwner( ) const;
	
	//! Unset RequestOwner
	plmxml_api::Result UnsetRequestOwner( );

	//! Get Product URI as plmxml_api::String
	plmxml_api::String GetProductURI() const;

	//! Set Product URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::String& );
	
	//! Get the handle of Product URI. Does not resolve the URI.
	plmxml_api::Result GetProductURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Product URI. URI string is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::Handle& );
	
	//! Resolve Product URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProductURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Product URI. Clears URI string and handle.
	plmxml_api::Result DeleteProductURI();
	
	//! Check if Product URI is set
	plmxml_api::logical HasProductURI( ) const;
	

	//! Get ReasonForRequest of this ProductRequest
	plmxml_api::String GetReasonForRequest() const;

	//! Set ReasonForRequest of this ProductRequest
	plmxml_api::Result SetReasonForRequest( const plmxml_api::String &s );
	
	//! Check if ReasonForRequest is set
	plmxml_api::logical HasReasonForRequest( ) const;
	
	//! Unset ReasonForRequest
	plmxml_api::Result UnsetReasonForRequest( );

	//! Set Status
	plmxml_api::Result SetStatus( const eRequestStatusEnum& arg );

	//! Get Status
	eRequestStatusEnum GetStatus() const;

	//! Get CreditAccount of this ProductRequest
	plmxml_api::String GetCreditAccount() const;

	//! Set CreditAccount of this ProductRequest
	plmxml_api::Result SetCreditAccount( const plmxml_api::String &s );
	
	//! Check if CreditAccount is set
	plmxml_api::logical HasCreditAccount( ) const;
	
	//! Unset CreditAccount
	plmxml_api::Result UnsetCreditAccount( );

	//! Get RequestID of this ProductRequest
	plmxml_api::String GetRequestID() const;

	//! Set RequestID of this ProductRequest
	plmxml_api::Result SetRequestID( const plmxml_api::String &s );
	
	//! Check if RequestID is set
	plmxml_api::logical HasRequestID( ) const;
	
	//! Unset RequestID
	plmxml_api::Result UnsetRequestID( );

	//! Get InventoryLocation URI as plmxml_api::String
	plmxml_api::String GetInventoryLocationURI() const;

	//! Set InventoryLocation URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetInventoryLocationURI( const plmxml_api::String& );
	
	//! Get the handle of InventoryLocation URI. Does not resolve the URI.
	plmxml_api::Result GetInventoryLocationURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of InventoryLocation URI. URI string is unchanged.
	plmxml_api::Result SetInventoryLocationURI( const plmxml_api::Handle& );
	
	//! Resolve InventoryLocation URI and return an object (handle) it points to.
	plmxml_api::Result ResolveInventoryLocationURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset InventoryLocation URI. Clears URI string and handle.
	plmxml_api::Result DeleteInventoryLocationURI();
	
	//! Check if InventoryLocation URI is set
	plmxml_api::logical HasInventoryLocationURI( ) const;
	

	//! Get TurnInDate of this ProductRequest
	plmxml_api::String GetTurnInDate() const;

	//! Set TurnInDate of this ProductRequest
	plmxml_api::Result SetTurnInDate( const plmxml_api::String &s );
	
	//! Check if TurnInDate is set
	plmxml_api::logical HasTurnInDate( ) const;
	
	//! Unset TurnInDate
	plmxml_api::Result UnsetTurnInDate( );

	//! Get Remarks of this ProductRequest
	plmxml_api::String GetRemarks() const;

	//! Set Remarks of this ProductRequest
	plmxml_api::Result SetRemarks( const plmxml_api::String &s );
	
	//! Check if Remarks is set
	plmxml_api::logical HasRemarks( ) const;
	
	//! Unset Remarks
	plmxml_api::Result UnsetRemarks( );

	//! Get DebitAccount of this ProductRequest
	plmxml_api::String GetDebitAccount() const;

	//! Set DebitAccount of this ProductRequest
	plmxml_api::Result SetDebitAccount( const plmxml_api::String &s );
	
	//! Check if DebitAccount is set
	plmxml_api::logical HasDebitAccount( ) const;
	
	//! Unset DebitAccount
	plmxml_api::Result UnsetDebitAccount( );

	//! Set Quantity
	plmxml_api::Result SetQuantity( double arg );

     //! Get Quantity
	double GetQuantity() const;

	//! Check if Quantity is set
	plmxml_api::logical HasQuantity() const;

	//! Unset Quantity
	plmxml_api::Result UnsetQuantity();
 
// <PLMXML_UserCode type="functionHeaderProductRequest" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassProductRequest;


////////////////////////////////////////////////////////////////////////////////////
//! RequestedRealisedProductRelation class
/*!
\verbatim

      This relation relates a ProductRequest to a RealisedProduct. The
      references in the inherited relatedRefs attribute must be in that order.

      Attributes:

      requestStage:     The stage of the RealisedProduct with respect to
                        ProductRequest.
      
\endverbatim
*/
class PLMXML_MRO60_API RequestedRealisedProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    RequestedRealisedProductRelation( );
     
    //! Constructs a RequestedRealisedProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RequestedRealisedProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RequestedRealisedProductRelation();

private:

	//! Assignment operator
	RequestedRealisedProductRelation& operator=( const RequestedRealisedProductRelation& iSrc );

	//! Copy constructor
	RequestedRealisedProductRelation( const RequestedRealisedProductRelation& original );
     
public:

	//! Set RequestStage
	plmxml_api::Result SetRequestStage( const eRequestStageEnum& arg );

	//! Get RequestStage
	eRequestStageEnum GetRequestStage() const;
 
// <PLMXML_UserCode type="functionHeaderRequestedRealisedProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRequestedRealisedProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RequestedLotRelation class
/*!
\verbatim

      This relation relates a ProductRequest to a Lot. The references in the
      inherited relatedRefs attribute must be in that order.

      Attributes:

      issuedQuantity:   The issued quantity from lot.
      reservedQuantity: The reserved quantity from lot.
      turnInQuantity:   The turned-in quantity from lot.
      
\endverbatim
*/
class PLMXML_MRO60_API RequestedLotRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    RequestedLotRelation( );
     
    //! Constructs a RequestedLotRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RequestedLotRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RequestedLotRelation();

private:

	//! Assignment operator
	RequestedLotRelation& operator=( const RequestedLotRelation& iSrc );

	//! Copy constructor
	RequestedLotRelation( const RequestedLotRelation& original );
     
public:

	//! Set TurnInQuantity
	plmxml_api::Result SetTurnInQuantity( double arg );

     //! Get TurnInQuantity
	double GetTurnInQuantity() const;

	//! Check if TurnInQuantity is set
	plmxml_api::logical HasTurnInQuantity() const;

	//! Unset TurnInQuantity
	plmxml_api::Result UnsetTurnInQuantity();

	//! Set IssuedQuantity
	plmxml_api::Result SetIssuedQuantity( double arg );

     //! Get IssuedQuantity
	double GetIssuedQuantity() const;

	//! Check if IssuedQuantity is set
	plmxml_api::logical HasIssuedQuantity() const;

	//! Unset IssuedQuantity
	plmxml_api::Result UnsetIssuedQuantity();

	//! Set ReservedQuantity
	plmxml_api::Result SetReservedQuantity( double arg );

     //! Get ReservedQuantity
	double GetReservedQuantity() const;

	//! Check if ReservedQuantity is set
	plmxml_api::logical HasReservedQuantity() const;

	//! Unset ReservedQuantity
	plmxml_api::Result UnsetReservedQuantity();
 
// <PLMXML_UserCode type="functionHeaderRequestedLotRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRequestedLotRelation;


////////////////////////////////////////////////////////////////////////////////////
//! MROSpecification class
/*!
\verbatim

      MRO Specification type information.
      
\endverbatim
*/
class PLMXML_MRO60_API MROSpecification : public MRODocument
{
public:
     
    //! Default constructor
    MROSpecification( );
     
    //! Constructs a MROSpecification with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROSpecification( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROSpecification();

private:

	//! Assignment operator
	MROSpecification& operator=( const MROSpecification& iSrc );

	//! Copy constructor
	MROSpecification( const MROSpecification& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMROSpecification" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROSpecification;


////////////////////////////////////////////////////////////////////////////////////
//! MROSpecificationRevision class
/*!
\verbatim

      MRO specification revision type information.

      Attributes:

      type:             Inherited from MRODocumentRevision. Required in this
                        context.
      effectiveDate:    Specifies the date the item is effective and available
                        for use.
      expirationDate:   Specifies the date on which the document expires for
                        maintenance.
      documentNumber:   MRO specification number. This attribute holds the
                        number assigned by the manufacturer to the document.
      receivedDate:     Specifies the date on which the document was received.
      revisionDate:     This attribute holds the date assigned by the
                        manufacturer to this revision.
      industryCode:     MRO specification industry code.
      isStatusTracking: Specifies if the document is marked for tracking.
      issueDate:        This attribute holds the date of issue for the document.
      keyword:          The keyword for MRO document.
      libraryControlNumber: MRO specification library control number.
      mrbApproved:      Materials review board approved.
      mrbNumber:        Materials review board number.
      mrbReferenceNumbers: Materials review board reference numbers.
      necessity:        This attribute defines the compliance type for
                        implementing this MRO document.
      originatorRevision: This attribute holds the number that identifies the
                        revision of the document specified by the manufacturer.
      standardBookNumber: International standard book number (ISBN).
      standardSerialNumber: International standard serial number (ISSN).
      enterpriseRef:    Enterprise reference. Specifies the relationship
                        indicating the enterprise that published the MRO
                        specification.
      
\endverbatim
*/
class PLMXML_MRO60_API MROSpecificationRevision : public MRODocumentRevision
{
public:
     
    //! Default constructor
    MROSpecificationRevision( );
     
    //! Constructs a MROSpecificationRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROSpecificationRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROSpecificationRevision();

private:

	//! Assignment operator
	MROSpecificationRevision& operator=( const MROSpecificationRevision& iSrc );

	//! Copy constructor
	MROSpecificationRevision( const MROSpecificationRevision& original );
     
public:

	//! Get MrbNumber of this MROSpecificationRevision
	plmxml_api::String GetMrbNumber() const;

	//! Set MrbNumber of this MROSpecificationRevision
	plmxml_api::Result SetMrbNumber( const plmxml_api::String &s );
	
	//! Check if MrbNumber is set
	plmxml_api::logical HasMrbNumber( ) const;
	
	//! Unset MrbNumber
	plmxml_api::Result UnsetMrbNumber( );

	//! Get Necessity of this MROSpecificationRevision
	plmxml_api::String GetNecessity() const;

	//! Set Necessity of this MROSpecificationRevision
	plmxml_api::Result SetNecessity( const plmxml_api::String &s );
	
	//! Check if Necessity is set
	plmxml_api::logical HasNecessity( ) const;
	
	//! Unset Necessity
	plmxml_api::Result UnsetNecessity( );

	//! Get ExpirationDate of this MROSpecificationRevision
	plmxml_api::String GetExpirationDate() const;

	//! Set ExpirationDate of this MROSpecificationRevision
	plmxml_api::Result SetExpirationDate( const plmxml_api::String &s );
	
	//! Check if ExpirationDate is set
	plmxml_api::logical HasExpirationDate( ) const;
	
	//! Unset ExpirationDate
	plmxml_api::Result UnsetExpirationDate( );

	//! Get EffectiveDate of this MROSpecificationRevision
	plmxml_api::String GetEffectiveDate() const;

	//! Set EffectiveDate of this MROSpecificationRevision
	plmxml_api::Result SetEffectiveDate( const plmxml_api::String &s );
	
	//! Check if EffectiveDate is set
	plmxml_api::logical HasEffectiveDate( ) const;
	
	//! Unset EffectiveDate
	plmxml_api::Result UnsetEffectiveDate( );

	//! Get IssueDate of this MROSpecificationRevision
	plmxml_api::String GetIssueDate() const;

	//! Set IssueDate of this MROSpecificationRevision
	plmxml_api::Result SetIssueDate( const plmxml_api::String &s );
	
	//! Check if IssueDate is set
	plmxml_api::logical HasIssueDate( ) const;
	
	//! Unset IssueDate
	plmxml_api::Result UnsetIssueDate( );

	//! Get MrbReferenceNumbers of this MROSpecificationRevision
	plmxml_api::String GetMrbReferenceNumbers() const;

	//! Set MrbReferenceNumbers of this MROSpecificationRevision
	plmxml_api::Result SetMrbReferenceNumbers( const plmxml_api::String &s );
	
	//! Check if MrbReferenceNumbers is set
	plmxml_api::logical HasMrbReferenceNumbers( ) const;
	
	//! Unset MrbReferenceNumbers
	plmxml_api::Result UnsetMrbReferenceNumbers( );

	//! Get DocumentNumber of this MROSpecificationRevision
	plmxml_api::String GetDocumentNumber() const;

	//! Set DocumentNumber of this MROSpecificationRevision
	plmxml_api::Result SetDocumentNumber( const plmxml_api::String &s );
	
	//! Check if DocumentNumber is set
	plmxml_api::logical HasDocumentNumber( ) const;
	
	//! Unset DocumentNumber
	plmxml_api::Result UnsetDocumentNumber( );

	//! Get Keyword of this MROSpecificationRevision
	plmxml_api::String GetKeyword() const;

	//! Set Keyword of this MROSpecificationRevision
	plmxml_api::Result SetKeyword( const plmxml_api::String &s );
	
	//! Check if Keyword is set
	plmxml_api::logical HasKeyword( ) const;
	
	//! Unset Keyword
	plmxml_api::Result UnsetKeyword( );

	//! Set IsStatusTracking
	plmxml_api::Result SetIsStatusTracking( plmxml_api::logical arg );

	//! Get IsStatusTracking
	plmxml_api::logical GetIsStatusTracking() const;

	//! Check if IsStatusTracking is set
	plmxml_api::logical HasIsStatusTracking() const;

	//! Unset IsStatusTracking
	plmxml_api::Result UnsetIsStatusTracking();

	//! Get MrbApproved of this MROSpecificationRevision
	plmxml_api::String GetMrbApproved() const;

	//! Set MrbApproved of this MROSpecificationRevision
	plmxml_api::Result SetMrbApproved( const plmxml_api::String &s );
	
	//! Check if MrbApproved is set
	plmxml_api::logical HasMrbApproved( ) const;
	
	//! Unset MrbApproved
	plmxml_api::Result UnsetMrbApproved( );

	//! Get Enterprise URI as plmxml_api::String
	plmxml_api::String GetEnterpriseURI() const;

	//! Set Enterprise URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEnterpriseURI( const plmxml_api::String& );
	
	//! Get the handle of Enterprise URI. Does not resolve the URI.
	plmxml_api::Result GetEnterpriseURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Enterprise URI. URI string is unchanged.
	plmxml_api::Result SetEnterpriseURI( const plmxml_api::Handle& );
	
	//! Resolve Enterprise URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEnterpriseURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Enterprise URI. Clears URI string and handle.
	plmxml_api::Result DeleteEnterpriseURI();
	
	//! Check if Enterprise URI is set
	plmxml_api::logical HasEnterpriseURI( ) const;
	

	//! Get OriginatorRevision of this MROSpecificationRevision
	plmxml_api::String GetOriginatorRevision() const;

	//! Set OriginatorRevision of this MROSpecificationRevision
	plmxml_api::Result SetOriginatorRevision( const plmxml_api::String &s );
	
	//! Check if OriginatorRevision is set
	plmxml_api::logical HasOriginatorRevision( ) const;
	
	//! Unset OriginatorRevision
	plmxml_api::Result UnsetOriginatorRevision( );

	//! Get LibraryControlNumber of this MROSpecificationRevision
	plmxml_api::String GetLibraryControlNumber() const;

	//! Set LibraryControlNumber of this MROSpecificationRevision
	plmxml_api::Result SetLibraryControlNumber( const plmxml_api::String &s );
	
	//! Check if LibraryControlNumber is set
	plmxml_api::logical HasLibraryControlNumber( ) const;
	
	//! Unset LibraryControlNumber
	plmxml_api::Result UnsetLibraryControlNumber( );

	//! Get IndustryCode of this MROSpecificationRevision
	plmxml_api::String GetIndustryCode() const;

	//! Set IndustryCode of this MROSpecificationRevision
	plmxml_api::Result SetIndustryCode( const plmxml_api::String &s );
	
	//! Check if IndustryCode is set
	plmxml_api::logical HasIndustryCode( ) const;
	
	//! Unset IndustryCode
	plmxml_api::Result UnsetIndustryCode( );

	//! Get RevisionDate of this MROSpecificationRevision
	plmxml_api::String GetRevisionDate() const;

	//! Set RevisionDate of this MROSpecificationRevision
	plmxml_api::Result SetRevisionDate( const plmxml_api::String &s );
	
	//! Check if RevisionDate is set
	plmxml_api::logical HasRevisionDate( ) const;
	
	//! Unset RevisionDate
	plmxml_api::Result UnsetRevisionDate( );

	//! Get ReceivedDate of this MROSpecificationRevision
	plmxml_api::String GetReceivedDate() const;

	//! Set ReceivedDate of this MROSpecificationRevision
	plmxml_api::Result SetReceivedDate( const plmxml_api::String &s );
	
	//! Check if ReceivedDate is set
	plmxml_api::logical HasReceivedDate( ) const;
	
	//! Unset ReceivedDate
	plmxml_api::Result UnsetReceivedDate( );

	//! Get StandardSerialNumber of this MROSpecificationRevision
	plmxml_api::String GetStandardSerialNumber() const;

	//! Set StandardSerialNumber of this MROSpecificationRevision
	plmxml_api::Result SetStandardSerialNumber( const plmxml_api::String &s );
	
	//! Check if StandardSerialNumber is set
	plmxml_api::logical HasStandardSerialNumber( ) const;
	
	//! Unset StandardSerialNumber
	plmxml_api::Result UnsetStandardSerialNumber( );

	//! Get StandardBookNumber of this MROSpecificationRevision
	plmxml_api::String GetStandardBookNumber() const;

	//! Set StandardBookNumber of this MROSpecificationRevision
	plmxml_api::Result SetStandardBookNumber( const plmxml_api::String &s );
	
	//! Check if StandardBookNumber is set
	plmxml_api::logical HasStandardBookNumber( ) const;
	
	//! Unset StandardBookNumber
	plmxml_api::Result UnsetStandardBookNumber( );
 
// <PLMXML_UserCode type="functionHeaderMROSpecificationRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROSpecificationRevision;


////////////////////////////////////////////////////////////////////////////////////
//! MROSpecificationRelation class
/*!
\verbatim

      This relation relates a MROSpecificationRevision to a MROSpecification.
      The references in the inherited relatedRefs attribute must be in that
      order.

      Attributes:

      type:             The type of relation. It could be Superseded, Related.
      
\endverbatim
*/
class PLMXML_MRO60_API MROSpecificationRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    MROSpecificationRelation( );
     
    //! Constructs a MROSpecificationRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROSpecificationRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROSpecificationRelation();

private:

	//! Assignment operator
	MROSpecificationRelation& operator=( const MROSpecificationRelation& iSrc );

	//! Copy constructor
	MROSpecificationRelation( const MROSpecificationRelation& original );
     
public:

	//! Get Type of this MROSpecificationRelation
	plmxml_api::String GetType() const;

	//! Set Type of this MROSpecificationRelation
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );
 
// <PLMXML_UserCode type="functionHeaderMROSpecificationRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROSpecificationRelation;


////////////////////////////////////////////////////////////////////////////////////
//! FinancialCodeFormat class
/*!
\verbatim

      Financial code type information.

      Attributes:

      delimiter:        Delimiter for chart of account (COA).
      segment:          Number of segments in chart of account (COA).
      sequence:         The sequence in which the chart of account (COA)
                        segments must appear.
      type:             The type of the chart of account (COA) segments.
      width:            The width of the chart of account (COA) segment.
      
\endverbatim
*/
class PLMXML_MRO60_API FinancialCodeFormat : public Managed
{
public:
     
    //! Default constructor
    FinancialCodeFormat( );
     
    //! Constructs a FinancialCodeFormat with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FinancialCodeFormat( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FinancialCodeFormat();

private:

	//! Assignment operator
	FinancialCodeFormat& operator=( const FinancialCodeFormat& iSrc );

	//! Copy constructor
	FinancialCodeFormat( const FinancialCodeFormat& original );
     
public:

	//! Get Type of this FinancialCodeFormat
	plmxml_api::String GetType() const;

	//! Set Type of this FinancialCodeFormat
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Set Width
	plmxml_api::Result SetWidth( int arg );
     
	//! Get Width
	int GetWidth() const;
     
	//! Check if Width is set
	plmxml_api::logical HasWidth() const;
     
	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Get Delimiter of this FinancialCodeFormat
	plmxml_api::String GetDelimiter() const;

	//! Set Delimiter of this FinancialCodeFormat
	plmxml_api::Result SetDelimiter( const plmxml_api::String &s );
	
	//! Check if Delimiter is set
	plmxml_api::logical HasDelimiter( ) const;
	
	//! Unset Delimiter
	plmxml_api::Result UnsetDelimiter( );

	//! Set Segment
	plmxml_api::Result SetSegment( int arg );
     
	//! Get Segment
	int GetSegment() const;
     
	//! Check if Segment is set
	plmxml_api::logical HasSegment() const;
     
	//! Unset Segment
	plmxml_api::Result UnsetSegment();

	//! Set Sequence
	plmxml_api::Result SetSequence( int arg );
     
	//! Get Sequence
	int GetSequence() const;
     
	//! Check if Sequence is set
	plmxml_api::logical HasSequence() const;
     
	//! Unset Sequence
	plmxml_api::Result UnsetSequence();
 
// <PLMXML_UserCode type="functionHeaderFinancialCodeFormat" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFinancialCodeFormat;


////////////////////////////////////////////////////////////////////////////////////
//! FinancialCode class
/*!
\verbatim

      Financial code type information.

      Attributes:

      value:            The value of the financial code type.
      formatRef:        Financial code type reference.
      
\endverbatim
*/
class PLMXML_MRO60_API FinancialCode : public Managed
{
public:
     
    //! Default constructor
    FinancialCode( );
     
    //! Constructs a FinancialCode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FinancialCode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FinancialCode();

private:

	//! Assignment operator
	FinancialCode& operator=( const FinancialCode& iSrc );

	//! Copy constructor
	FinancialCode( const FinancialCode& original );
     
public:

	//! Get Value of this FinancialCode
	plmxml_api::String GetValue() const;

	//! Set Value of this FinancialCode
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Get Format URI as plmxml_api::String
	plmxml_api::String GetFormatURI() const;

	//! Set Format URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFormatURI( const plmxml_api::String& );
	
	//! Get the handle of Format URI. Does not resolve the URI.
	plmxml_api::Result GetFormatURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Format URI. URI string is unchanged.
	plmxml_api::Result SetFormatURI( const plmxml_api::Handle& );
	
	//! Resolve Format URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFormatURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Format URI. Clears URI string and handle.
	plmxml_api::Result DeleteFormatURI();
	
	//! Check if Format URI is set
	plmxml_api::logical HasFormatURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderFinancialCode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFinancialCode;


////////////////////////////////////////////////////////////////////////////////////
//! MROPosition class
/*!
\verbatim

      Position information.

      Attributes:

      isMeter:          If position is a meter position.
      isPanel:          If position is a panel position.
      occurrenceRef:    Occurrence reference. An Occurrence without its
                        instanceRefs attribute set indicates self position.
      
\endverbatim
*/
class PLMXML_MRO60_API MROPosition : public Structure
{
public:
     
    //! Default constructor
    MROPosition( );
     
    //! Constructs a MROPosition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROPosition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROPosition();

private:

	//! Assignment operator
	MROPosition& operator=( const MROPosition& iSrc );

	//! Copy constructor
	MROPosition( const MROPosition& original );
     
public:

	//! Get Occurrence URI as plmxml_api::String
	plmxml_api::String GetOccurrenceURI() const;

	//! Set Occurrence URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOccurrenceURI( const plmxml_api::String& );
	
	//! Get the handle of Occurrence URI. Does not resolve the URI.
	plmxml_api::Result GetOccurrenceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Occurrence URI. URI string is unchanged.
	plmxml_api::Result SetOccurrenceURI( const plmxml_api::Handle& );
	
	//! Resolve Occurrence URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOccurrenceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Occurrence URI. Clears URI string and handle.
	plmxml_api::Result DeleteOccurrenceURI();
	
	//! Check if Occurrence URI is set
	plmxml_api::logical HasOccurrenceURI( ) const;
	

	//! Set IsPanel
	plmxml_api::Result SetIsPanel( plmxml_api::logical arg );

	//! Get IsPanel
	plmxml_api::logical GetIsPanel() const;

	//! Check if IsPanel is set
	plmxml_api::logical HasIsPanel() const;

	//! Unset IsPanel
	plmxml_api::Result UnsetIsPanel();

	//! Set IsMeter
	plmxml_api::Result SetIsMeter( plmxml_api::logical arg );

	//! Get IsMeter
	plmxml_api::logical GetIsMeter() const;

	//! Check if IsMeter is set
	plmxml_api::logical HasIsMeter() const;

	//! Unset IsMeter
	plmxml_api::Result UnsetIsMeter();
 
// <PLMXML_UserCode type="functionHeaderMROPosition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROPosition;


////////////////////////////////////////////////////////////////////////////////////
//! MROPositionRevision class
/*!
\verbatim

      Position revision information.

      Attributes:

      panelNumber:      Unique identifier to identify the panel number of the
                        given position.
      code:             Unique identifier to identify the position code of the
                        given position.
      childRefs:        A list of references to child positions.
      meterRefs:        A list of references to meter positions.
      panelRefs:        A list of references to panel positions.
      
\endverbatim
*/
class PLMXML_MRO60_API MROPositionRevision : public StructureRevision
{
public:
     
    //! Default constructor
    MROPositionRevision( );
     
    //! Constructs a MROPositionRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROPositionRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROPositionRevision();

private:

	//! Assignment operator
	MROPositionRevision& operator=( const MROPositionRevision& iSrc );

	//! Copy constructor
	MROPositionRevision( const MROPositionRevision& original );
     
public:

	//! Get number of URIs in Meter
	int NumberOfMeterURIs() const;

	//! Get i'th URI in Meter
	plmxml_api::String GetMeterURI( int i ) const;

	//! Add a URI to Meter array. Call ResolveMeterURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddMeterURI( const plmxml_api::String& u );

	//! Set i'th URI in Meter array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetMeterURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Meter URI. Does not resolve the URI.
	plmxml_api::Result GetMeterURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Meter array.
	plmxml_api::Result AddMeterURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Meter array to point to 'handle'.
	plmxml_api::Result SetMeterURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Meter points to.
	plmxml_api::Result ResolveMeterURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Meter array.
	plmxml_api::Result DeleteMeterURI( int i );

	//! Remove all URIs from Meter array.
	plmxml_api::Result DeleteMeterURIs( );
	
	//! Check if Meter is set
	plmxml_api::logical HasMeterURIs( ) const;

	//! Get number of URIs in Child
	int NumberOfChildURIs() const;

	//! Get i'th URI in Child
	plmxml_api::String GetChildURI( int i ) const;

	//! Add a URI to Child array. Call ResolveChildURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddChildURI( const plmxml_api::String& u );

	//! Set i'th URI in Child array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetChildURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Child URI. Does not resolve the URI.
	plmxml_api::Result GetChildURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Child array.
	plmxml_api::Result AddChildURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Child array to point to 'handle'.
	plmxml_api::Result SetChildURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Child points to.
	plmxml_api::Result ResolveChildURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Child array.
	plmxml_api::Result DeleteChildURI( int i );

	//! Remove all URIs from Child array.
	plmxml_api::Result DeleteChildURIs( );
	
	//! Check if Child is set
	plmxml_api::logical HasChildURIs( ) const;

	//! Get Code of this MROPositionRevision
	plmxml_api::String GetCode() const;

	//! Set Code of this MROPositionRevision
	plmxml_api::Result SetCode( const plmxml_api::String &s );
	
	//! Check if Code is set
	plmxml_api::logical HasCode( ) const;
	
	//! Unset Code
	plmxml_api::Result UnsetCode( );

	//! Get PanelNumber of this MROPositionRevision
	plmxml_api::String GetPanelNumber() const;

	//! Set PanelNumber of this MROPositionRevision
	plmxml_api::Result SetPanelNumber( const plmxml_api::String &s );
	
	//! Check if PanelNumber is set
	plmxml_api::logical HasPanelNumber( ) const;
	
	//! Unset PanelNumber
	plmxml_api::Result UnsetPanelNumber( );

	//! Get number of URIs in Panel
	int NumberOfPanelURIs() const;

	//! Get i'th URI in Panel
	plmxml_api::String GetPanelURI( int i ) const;

	//! Add a URI to Panel array. Call ResolvePanelURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPanelURI( const plmxml_api::String& u );

	//! Set i'th URI in Panel array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPanelURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Panel URI. Does not resolve the URI.
	plmxml_api::Result GetPanelURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Panel array.
	plmxml_api::Result AddPanelURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Panel array to point to 'handle'.
	plmxml_api::Result SetPanelURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Panel points to.
	plmxml_api::Result ResolvePanelURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Panel array.
	plmxml_api::Result DeletePanelURI( int i );

	//! Remove all URIs from Panel array.
	plmxml_api::Result DeletePanelURIs( );
	
	//! Check if Panel is set
	plmxml_api::logical HasPanelURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderMROPositionRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROPositionRevision;


////////////////////////////////////////////////////////////////////////////////////
//! PartLogistics class
/*!
\verbatim

      Neutral element information.

      Attributes:

      isConsumable:     Is consumable.
      isLot:            Is lot.
      isPreserveQuantity: Specifies if the quantities are preserved while
                        generating the RealisedProduct.
      isRotable:        Is rotable.
      isSerialised:     Is serialised.
      isTraceable:      Is traceable.
      productRef:       Reference to product.
      
\endverbatim
*/
class PLMXML_MRO60_API PartLogistics : public Managed
{
public:
     
    //! Default constructor
    PartLogistics( );
     
    //! Constructs a PartLogistics with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PartLogistics( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PartLogistics();

private:

	//! Assignment operator
	PartLogistics& operator=( const PartLogistics& iSrc );

	//! Copy constructor
	PartLogistics( const PartLogistics& original );
     
public:

	//! Set IsConsumable
	plmxml_api::Result SetIsConsumable( plmxml_api::logical arg );

	//! Get IsConsumable
	plmxml_api::logical GetIsConsumable() const;

	//! Check if IsConsumable is set
	plmxml_api::logical HasIsConsumable() const;

	//! Unset IsConsumable
	plmxml_api::Result UnsetIsConsumable();

	//! Set IsRotable
	plmxml_api::Result SetIsRotable( plmxml_api::logical arg );

	//! Get IsRotable
	plmxml_api::logical GetIsRotable() const;

	//! Check if IsRotable is set
	plmxml_api::logical HasIsRotable() const;

	//! Unset IsRotable
	plmxml_api::Result UnsetIsRotable();

	//! Get Product URI as plmxml_api::String
	plmxml_api::String GetProductURI() const;

	//! Set Product URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::String& );
	
	//! Get the handle of Product URI. Does not resolve the URI.
	plmxml_api::Result GetProductURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Product URI. URI string is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::Handle& );
	
	//! Resolve Product URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProductURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Product URI. Clears URI string and handle.
	plmxml_api::Result DeleteProductURI();
	
	//! Check if Product URI is set
	plmxml_api::logical HasProductURI( ) const;
	

	//! Set IsTraceable
	plmxml_api::Result SetIsTraceable( plmxml_api::logical arg );

	//! Get IsTraceable
	plmxml_api::logical GetIsTraceable() const;

	//! Check if IsTraceable is set
	plmxml_api::logical HasIsTraceable() const;

	//! Unset IsTraceable
	plmxml_api::Result UnsetIsTraceable();

	//! Set IsSerialised
	plmxml_api::Result SetIsSerialised( plmxml_api::logical arg );

	//! Get IsSerialised
	plmxml_api::logical GetIsSerialised() const;

	//! Check if IsSerialised is set
	plmxml_api::logical HasIsSerialised() const;

	//! Unset IsSerialised
	plmxml_api::Result UnsetIsSerialised();

	//! Set IsPreserveQuantity
	plmxml_api::Result SetIsPreserveQuantity( plmxml_api::logical arg );

	//! Get IsPreserveQuantity
	plmxml_api::logical GetIsPreserveQuantity() const;

	//! Check if IsPreserveQuantity is set
	plmxml_api::logical HasIsPreserveQuantity() const;

	//! Unset IsPreserveQuantity
	plmxml_api::Result UnsetIsPreserveQuantity();

	//! Set IsLot
	plmxml_api::Result SetIsLot( plmxml_api::logical arg );

	//! Get IsLot
	plmxml_api::logical GetIsLot() const;

	//! Check if IsLot is set
	plmxml_api::logical HasIsLot() const;

	//! Unset IsLot
	plmxml_api::Result UnsetIsLot();
 
// <PLMXML_UserCode type="functionHeaderPartLogistics" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPartLogistics;


////////////////////////////////////////////////////////////////////////////////////
//! CharacteristicDefinitionExpression class
/*!
\verbatim

      An expression for the definition of a characteristic.
      
\endverbatim
*/
class PLMXML_MRO60_API CharacteristicDefinitionExpression : public GeneralExpression
{
public:
     
    //! Default constructor
    CharacteristicDefinitionExpression( );
     
    //! Constructs a CharacteristicDefinitionExpression with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CharacteristicDefinitionExpression( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CharacteristicDefinitionExpression();

private:

	//! Assignment operator
	CharacteristicDefinitionExpression& operator=( const CharacteristicDefinitionExpression& iSrc );

	//! Copy constructor
	CharacteristicDefinitionExpression( const CharacteristicDefinitionExpression& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderCharacteristicDefinitionExpression" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassCharacteristicDefinitionExpression;


////////////////////////////////////////////////////////////////////////////////////
//! RemoveInstallProduct class
/*!
\verbatim

      Remove-Install Product information. This element has been deprecated and
      should not be used.

      Attributes:

      deviationAuthority: The identity whose authorized the installation.
      isNew:            Is New Part?
      manufacturerRef:  Manufacturer's ID.
      isTraced:         Is true if part is traced.
      productRef:       References a serialized or a non-serialized part.
      reason:           Reason for the part removal/installation.
      pathRef:          References a Part Position Path - Contains a position
                        path of any remove or install events.
      quantity:         Quantity of the parts being removed/installed.
      serialNumber:     Serial Number.
      actionType:       Type of action - Install, Remove or Change.
      
\endverbatim
*/
class PLMXML_MRO60_API RemoveInstallProduct : public Managed
{
public:
     
    //! Default constructor
    RemoveInstallProduct( );
     
    //! Constructs a RemoveInstallProduct with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RemoveInstallProduct( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RemoveInstallProduct();

private:

	//! Assignment operator
	RemoveInstallProduct& operator=( const RemoveInstallProduct& iSrc );

	//! Copy constructor
	RemoveInstallProduct( const RemoveInstallProduct& original );
     
public:

	//! Get Manufacturer URI as plmxml_api::String
	plmxml_api::String GetManufacturerURI() const;

	//! Set Manufacturer URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::String& );
	
	//! Get the handle of Manufacturer URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Manufacturer URI. URI string is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::Handle& );
	
	//! Resolve Manufacturer URI and return an object (handle) it points to.
	plmxml_api::Result ResolveManufacturerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Manufacturer URI. Clears URI string and handle.
	plmxml_api::Result DeleteManufacturerURI();
	
	//! Check if Manufacturer URI is set
	plmxml_api::logical HasManufacturerURI( ) const;
	

	//! Get DeviationAuthority of this RemoveInstallProduct
	plmxml_api::String GetDeviationAuthority() const;

	//! Set DeviationAuthority of this RemoveInstallProduct
	plmxml_api::Result SetDeviationAuthority( const plmxml_api::String &s );
	
	//! Check if DeviationAuthority is set
	plmxml_api::logical HasDeviationAuthority( ) const;
	
	//! Unset DeviationAuthority
	plmxml_api::Result UnsetDeviationAuthority( );

	//! Set ActionType
	plmxml_api::Result SetActionType( const eRemoveInstallProductActionEnum& arg );

	//! Get ActionType
	eRemoveInstallProductActionEnum GetActionType() const;

	//! Set IsTraced
	plmxml_api::Result SetIsTraced( plmxml_api::logical arg );

	//! Get IsTraced
	plmxml_api::logical GetIsTraced() const;

	//! Check if IsTraced is set
	plmxml_api::logical HasIsTraced() const;

	//! Unset IsTraced
	plmxml_api::Result UnsetIsTraced();

	//! Get SerialNumber of this RemoveInstallProduct
	plmxml_api::String GetSerialNumber() const;

	//! Set SerialNumber of this RemoveInstallProduct
	plmxml_api::Result SetSerialNumber( const plmxml_api::String &s );
	
	//! Check if SerialNumber is set
	plmxml_api::logical HasSerialNumber( ) const;
	
	//! Unset SerialNumber
	plmxml_api::Result UnsetSerialNumber( );

	//! Get Product URI as plmxml_api::String
	plmxml_api::String GetProductURI() const;

	//! Set Product URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::String& );
	
	//! Get the handle of Product URI. Does not resolve the URI.
	plmxml_api::Result GetProductURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Product URI. URI string is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::Handle& );
	
	//! Resolve Product URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProductURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Product URI. Clears URI string and handle.
	plmxml_api::Result DeleteProductURI();
	
	//! Check if Product URI is set
	plmxml_api::logical HasProductURI( ) const;
	

	//! Get Reason of this RemoveInstallProduct
	plmxml_api::String GetReason() const;

	//! Set Reason of this RemoveInstallProduct
	plmxml_api::Result SetReason( const plmxml_api::String &s );
	
	//! Check if Reason is set
	plmxml_api::logical HasReason( ) const;
	
	//! Unset Reason
	plmxml_api::Result UnsetReason( );

	//! Get Path URI as plmxml_api::String
	plmxml_api::String GetPathURI() const;

	//! Set Path URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPathURI( const plmxml_api::String& );
	
	//! Get the handle of Path URI. Does not resolve the URI.
	plmxml_api::Result GetPathURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Path URI. URI string is unchanged.
	plmxml_api::Result SetPathURI( const plmxml_api::Handle& );
	
	//! Resolve Path URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePathURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Path URI. Clears URI string and handle.
	plmxml_api::Result DeletePathURI();
	
	//! Check if Path URI is set
	plmxml_api::logical HasPathURI( ) const;
	

	//! Set IsNew
	plmxml_api::Result SetIsNew( plmxml_api::logical arg );

	//! Get IsNew
	plmxml_api::logical GetIsNew() const;

	//! Check if IsNew is set
	plmxml_api::logical HasIsNew() const;

	//! Unset IsNew
	plmxml_api::Result UnsetIsNew();

	//! Set Quantity
	plmxml_api::Result SetQuantity( double arg );

     //! Get Quantity
	double GetQuantity() const;

	//! Check if Quantity is set
	plmxml_api::logical HasQuantity() const;

	//! Unset Quantity
	plmxml_api::Result UnsetQuantity();
 
// <PLMXML_UserCode type="functionHeaderRemoveInstallProduct" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRemoveInstallProduct;


////////////////////////////////////////////////////////////////////////////////////
//! PhysicalProductMovement class
/*!
\verbatim

      Physical Product Movement information. This element has been deprecated
      and should not be used.

      Attributes:

      deviationAuthority: The identity whose authorized the installation.
      isNew:            Is New Part?
      manufacturerRef:  Manufacturer's ID.
      isTraced:         Is true if part is traced.
      productRef:       Inherited from RemoveInstallProduct. References a
                        serialized or a non-serialized part.
      reason:           Reason for the part removal/installation.
      pathRef:          Inherited from RemoveInstallProduct. References a Part
                        Position Path - Contains a position path of any remove
                        or install events.
      quantity:         Quantity of the parts being removed/installed.
      serialNumber:     Serial Number.
      actionType:       Type of action - Install or Remove.
      
\endverbatim
*/
class PLMXML_MRO60_API PhysicalProductMovement : public RemoveInstallProduct
{
public:
     
    //! Default constructor
    PhysicalProductMovement( );
     
    //! Constructs a PhysicalProductMovement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PhysicalProductMovement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PhysicalProductMovement();

private:

	//! Assignment operator
	PhysicalProductMovement& operator=( const PhysicalProductMovement& iSrc );

	//! Copy constructor
	PhysicalProductMovement( const PhysicalProductMovement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPhysicalProductMovement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPhysicalProductMovement;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceEvent class
/*!
\verbatim

      Service Event information. This element has been deprecated and should not
      be used.

      Attributes:

      sENumber:         Service Event Number.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceEvent : public Structure
{
public:
     
    //! Default constructor
    ServiceEvent( );
     
    //! Constructs a ServiceEvent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceEvent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceEvent();

private:

	//! Assignment operator
	ServiceEvent& operator=( const ServiceEvent& iSrc );

	//! Copy constructor
	ServiceEvent( const ServiceEvent& original );
     
public:

	//! Get SENumber of this ServiceEvent
	plmxml_api::String GetSENumber() const;

	//! Set SENumber of this ServiceEvent
	plmxml_api::Result SetSENumber( const plmxml_api::String &s );
	
	//! Check if SENumber is set
	plmxml_api::logical HasSENumber( ) const;
	
	//! Unset SENumber
	plmxml_api::Result UnsetSENumber( );
 
// <PLMXML_UserCode type="functionHeaderServiceEvent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceEvent;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceEventRevision class
/*!
\verbatim

      Service Event Revision type information. This element has been deprecated
      and should not be used.

      Attributes:

      manufacturerRef:  Manufacturer's ID.
      productRef:       References a serialized or a non-serialized part.
      pathRef:          References a Part Position Path - Contains a position
                        path of any remove or install events.
      sENote:           User defined notes.
      sENumber:         Service Event Number.
      sETitle:          Short description of an External Service.
      serialNumber:     Serial Number.

      Sub-elements:

      Description:      Inherited from StructureRevision.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceEventRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ServiceEventRevision( );
     
    //! Constructs a ServiceEventRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceEventRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceEventRevision();

private:

	//! Assignment operator
	ServiceEventRevision& operator=( const ServiceEventRevision& iSrc );

	//! Copy constructor
	ServiceEventRevision( const ServiceEventRevision& original );
     
public:

	//! Get SENumber of this ServiceEventRevision
	plmxml_api::String GetSENumber() const;

	//! Set SENumber of this ServiceEventRevision
	plmxml_api::Result SetSENumber( const plmxml_api::String &s );
	
	//! Check if SENumber is set
	plmxml_api::logical HasSENumber( ) const;
	
	//! Unset SENumber
	plmxml_api::Result UnsetSENumber( );

	//! Get Manufacturer URI as plmxml_api::String
	plmxml_api::String GetManufacturerURI() const;

	//! Set Manufacturer URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::String& );
	
	//! Get the handle of Manufacturer URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Manufacturer URI. URI string is unchanged.
	plmxml_api::Result SetManufacturerURI( const plmxml_api::Handle& );
	
	//! Resolve Manufacturer URI and return an object (handle) it points to.
	plmxml_api::Result ResolveManufacturerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Manufacturer URI. Clears URI string and handle.
	plmxml_api::Result DeleteManufacturerURI();
	
	//! Check if Manufacturer URI is set
	plmxml_api::logical HasManufacturerURI( ) const;
	

	//! Get Product URI as plmxml_api::String
	plmxml_api::String GetProductURI() const;

	//! Set Product URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::String& );
	
	//! Get the handle of Product URI. Does not resolve the URI.
	plmxml_api::Result GetProductURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Product URI. URI string is unchanged.
	plmxml_api::Result SetProductURI( const plmxml_api::Handle& );
	
	//! Resolve Product URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProductURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Product URI. Clears URI string and handle.
	plmxml_api::Result DeleteProductURI();
	
	//! Check if Product URI is set
	plmxml_api::logical HasProductURI( ) const;
	

	//! Get SerialNumber of this ServiceEventRevision
	plmxml_api::String GetSerialNumber() const;

	//! Set SerialNumber of this ServiceEventRevision
	plmxml_api::Result SetSerialNumber( const plmxml_api::String &s );
	
	//! Check if SerialNumber is set
	plmxml_api::logical HasSerialNumber( ) const;
	
	//! Unset SerialNumber
	plmxml_api::Result UnsetSerialNumber( );

	//! Get SETitle of this ServiceEventRevision
	plmxml_api::String GetSETitle() const;

	//! Set SETitle of this ServiceEventRevision
	plmxml_api::Result SetSETitle( const plmxml_api::String &s );
	
	//! Check if SETitle is set
	plmxml_api::logical HasSETitle( ) const;
	
	//! Unset SETitle
	plmxml_api::Result UnsetSETitle( );

	//! Get Path URI as plmxml_api::String
	plmxml_api::String GetPathURI() const;

	//! Set Path URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPathURI( const plmxml_api::String& );
	
	//! Get the handle of Path URI. Does not resolve the URI.
	plmxml_api::Result GetPathURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Path URI. URI string is unchanged.
	plmxml_api::Result SetPathURI( const plmxml_api::Handle& );
	
	//! Resolve Path URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePathURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Path URI. Clears URI string and handle.
	plmxml_api::Result DeletePathURI();
	
	//! Check if Path URI is set
	plmxml_api::logical HasPathURI( ) const;
	

	//! Get SENote of this ServiceEventRevision
	plmxml_api::String GetSENote() const;

	//! Set SENote of this ServiceEventRevision
	plmxml_api::Result SetSENote( const plmxml_api::String &s );
	
	//! Check if SENote is set
	plmxml_api::logical HasSENote( ) const;
	
	//! Unset SENote
	plmxml_api::Result UnsetSENote( );
 
// <PLMXML_UserCode type="functionHeaderServiceEventRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceEventRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ExternalServiceEventDiscrepancy class
/*!
\verbatim

      External Service Event Discrepancy information. This element has been
      deprecated and should not be used.

      Attributes:

      sENumber:         Service Event Number.
      
\endverbatim
*/
class PLMXML_MRO60_API ExternalServiceEventDiscrepancy : public ServiceEvent
{
public:
     
    //! Default constructor
    ExternalServiceEventDiscrepancy( );
     
    //! Constructs a ExternalServiceEventDiscrepancy with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExternalServiceEventDiscrepancy( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExternalServiceEventDiscrepancy();

private:

	//! Assignment operator
	ExternalServiceEventDiscrepancy& operator=( const ExternalServiceEventDiscrepancy& iSrc );

	//! Copy constructor
	ExternalServiceEventDiscrepancy( const ExternalServiceEventDiscrepancy& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderExternalServiceEventDiscrepancy" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassExternalServiceEventDiscrepancy;


////////////////////////////////////////////////////////////////////////////////////
//! ExternalServiceEventDiscrepancyRevision class
/*!
\verbatim

      External Service Event Discrepancy Revision information. This element has
      been deprecated and should not be used.

      Attributes:

      manufacturerRef:  Manufacturer's ID.
      productRef:       Inherited from ServiceEventRevision. References a
                        serialized or a non-serialized part.
      pathRef:          Inherited from ServiceEventRevision. References a Part
                        Position Path - Contains a position path of any remove
                        or install part.
      sENote:           User defined notes.
      sENumber:         Service Event Number.
      sETitle:          Short description of an External Service.
      serialNumber:     Serial Number.
      discoveryDate:    Discovery Date.
      discoveredBy:     Discovered By.
      sEClass:          User defined class.
      isFailure:        Discrepancy was the result of a failure?
      faultCode:        Fault code in the event of a failure.
      isMEL:            Minimum equipment list?

      Sub-elements:

      Description:      Inherited from StructureRevision.
      
\endverbatim
*/
class PLMXML_MRO60_API ExternalServiceEventDiscrepancyRevision : public ServiceEventRevision
{
public:
     
    //! Default constructor
    ExternalServiceEventDiscrepancyRevision( );
     
    //! Constructs a ExternalServiceEventDiscrepancyRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExternalServiceEventDiscrepancyRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExternalServiceEventDiscrepancyRevision();

private:

	//! Assignment operator
	ExternalServiceEventDiscrepancyRevision& operator=( const ExternalServiceEventDiscrepancyRevision& iSrc );

	//! Copy constructor
	ExternalServiceEventDiscrepancyRevision( const ExternalServiceEventDiscrepancyRevision& original );
     
public:

	//! Set IsMEL
	plmxml_api::Result SetIsMEL( plmxml_api::logical arg );

	//! Get IsMEL
	plmxml_api::logical GetIsMEL() const;

	//! Check if IsMEL is set
	plmxml_api::logical HasIsMEL() const;

	//! Unset IsMEL
	plmxml_api::Result UnsetIsMEL();

	//! Get SEClass of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::String GetSEClass() const;

	//! Set SEClass of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::Result SetSEClass( const plmxml_api::String &s );
	
	//! Check if SEClass is set
	plmxml_api::logical HasSEClass( ) const;
	
	//! Unset SEClass
	plmxml_api::Result UnsetSEClass( );

	//! Get DiscoveryDate of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::String GetDiscoveryDate() const;

	//! Set DiscoveryDate of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::Result SetDiscoveryDate( const plmxml_api::String &s );
	
	//! Check if DiscoveryDate is set
	plmxml_api::logical HasDiscoveryDate( ) const;
	
	//! Unset DiscoveryDate
	plmxml_api::Result UnsetDiscoveryDate( );

	//! Get FaultCode of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::String GetFaultCode() const;

	//! Set FaultCode of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::Result SetFaultCode( const plmxml_api::String &s );
	
	//! Check if FaultCode is set
	plmxml_api::logical HasFaultCode( ) const;
	
	//! Unset FaultCode
	plmxml_api::Result UnsetFaultCode( );

	//! Set IsFailure
	plmxml_api::Result SetIsFailure( plmxml_api::logical arg );

	//! Get IsFailure
	plmxml_api::logical GetIsFailure() const;

	//! Check if IsFailure is set
	plmxml_api::logical HasIsFailure() const;

	//! Unset IsFailure
	plmxml_api::Result UnsetIsFailure();

	//! Get DiscoveredBy of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::String GetDiscoveredBy() const;

	//! Set DiscoveredBy of this ExternalServiceEventDiscrepancyRevision
	plmxml_api::Result SetDiscoveredBy( const plmxml_api::String &s );
	
	//! Check if DiscoveredBy is set
	plmxml_api::logical HasDiscoveredBy( ) const;
	
	//! Unset DiscoveredBy
	plmxml_api::Result UnsetDiscoveredBy( );
 
// <PLMXML_UserCode type="functionHeaderExternalServiceEventDiscrepancyRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassExternalServiceEventDiscrepancyRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ExternalServiceActivity class
/*!
\verbatim

      External Service Activity information. This element has been deprecated
      and should not be used.

      Attributes:

      sENumber:         Service Event Number.
      
\endverbatim
*/
class PLMXML_MRO60_API ExternalServiceActivity : public ServiceEvent
{
public:
     
    //! Default constructor
    ExternalServiceActivity( );
     
    //! Constructs a ExternalServiceActivity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExternalServiceActivity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExternalServiceActivity();

private:

	//! Assignment operator
	ExternalServiceActivity& operator=( const ExternalServiceActivity& iSrc );

	//! Copy constructor
	ExternalServiceActivity( const ExternalServiceActivity& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderExternalServiceActivity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassExternalServiceActivity;


////////////////////////////////////////////////////////////////////////////////////
//! ExternalServiceActivityRevision class
/*!
\verbatim

      External Service Activity Revision information. This element has been
      deprecated and should not be used.

      Attributes:

      manufacturerRef:  Manufacturer's ID.
      productRef:       Inherited from ServiceEventRevision. References a 
                        serialized or a non-serialized part.
      pathRef:          Inherited from ServiceEventRevision. References a Part
                        Position Path - Contains a position path of any remove
                        or install part.
      sENote:           User defined notes.
      sENumber:         Service Event Number.
      sETitle:          Short description of an External Service.
      serialNumber:     Serial Number.
      authorizedBy:     Authorized By.
      category:         Category.
      completedBy:      Completed By.
      completedDate:    Completed Date.
      cost:             Cost.
      endTime:          Elapsed Completion End Time.
      startTime:        Elapsed Completion Start Time.
      eventType:        Event Type.
      otherSignOffs:    Other Sign Offs.
      removeInstalls:   Remove Installs.
      workCards:        Job cards/work cards used.
      workLocation:     Location where the service was performed.
      zone:             Zones where the service was performed.

      Sub-elements:

      Description:      Inherited from StructureRevision.
      
\endverbatim
*/
class PLMXML_MRO60_API ExternalServiceActivityRevision : public ServiceEventRevision
{
public:
     
    //! Default constructor
    ExternalServiceActivityRevision( );
     
    //! Constructs a ExternalServiceActivityRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExternalServiceActivityRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExternalServiceActivityRevision();

private:

	//! Assignment operator
	ExternalServiceActivityRevision& operator=( const ExternalServiceActivityRevision& iSrc );

	//! Copy constructor
	ExternalServiceActivityRevision( const ExternalServiceActivityRevision& original );
     
public:

	//! Get EventType of this ExternalServiceActivityRevision
	plmxml_api::String GetEventType() const;

	//! Set EventType of this ExternalServiceActivityRevision
	plmxml_api::Result SetEventType( const plmxml_api::String &s );
	
	//! Check if EventType is set
	plmxml_api::logical HasEventType( ) const;
	
	//! Unset EventType
	plmxml_api::Result UnsetEventType( );

	//! Get StartTime of this ExternalServiceActivityRevision
	plmxml_api::String GetStartTime() const;

	//! Set StartTime of this ExternalServiceActivityRevision
	plmxml_api::Result SetStartTime( const plmxml_api::String &s );
	
	//! Check if StartTime is set
	plmxml_api::logical HasStartTime( ) const;
	
	//! Unset StartTime
	plmxml_api::Result UnsetStartTime( );

	//! Get CompletedDate of this ExternalServiceActivityRevision
	plmxml_api::String GetCompletedDate() const;

	//! Set CompletedDate of this ExternalServiceActivityRevision
	plmxml_api::Result SetCompletedDate( const plmxml_api::String &s );
	
	//! Check if CompletedDate is set
	plmxml_api::logical HasCompletedDate( ) const;
	
	//! Unset CompletedDate
	plmxml_api::Result UnsetCompletedDate( );

	//! Get OtherSignOffs of this ExternalServiceActivityRevision
	plmxml_api::String GetOtherSignOffs() const;

	//! Set OtherSignOffs of this ExternalServiceActivityRevision
	plmxml_api::Result SetOtherSignOffs( const plmxml_api::String &s );
	
	//! Check if OtherSignOffs is set
	plmxml_api::logical HasOtherSignOffs( ) const;
	
	//! Unset OtherSignOffs
	plmxml_api::Result UnsetOtherSignOffs( );

	//! Set Cost
	plmxml_api::Result SetCost( double arg );

     //! Get Cost
	double GetCost() const;

	//! Check if Cost is set
	plmxml_api::logical HasCost() const;

	//! Unset Cost
	plmxml_api::Result UnsetCost();

	//! Get Category of this ExternalServiceActivityRevision
	plmxml_api::String GetCategory() const;

	//! Set Category of this ExternalServiceActivityRevision
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );

	//! Get CompletedBy of this ExternalServiceActivityRevision
	plmxml_api::String GetCompletedBy() const;

	//! Set CompletedBy of this ExternalServiceActivityRevision
	plmxml_api::Result SetCompletedBy( const plmxml_api::String &s );
	
	//! Check if CompletedBy is set
	plmxml_api::logical HasCompletedBy( ) const;
	
	//! Unset CompletedBy
	plmxml_api::Result UnsetCompletedBy( );

	//! Get AuthorizedBy of this ExternalServiceActivityRevision
	plmxml_api::String GetAuthorizedBy() const;

	//! Set AuthorizedBy of this ExternalServiceActivityRevision
	plmxml_api::Result SetAuthorizedBy( const plmxml_api::String &s );
	
	//! Check if AuthorizedBy is set
	plmxml_api::logical HasAuthorizedBy( ) const;
	
	//! Unset AuthorizedBy
	plmxml_api::Result UnsetAuthorizedBy( );

	//! Get WorkLocation URI as plmxml_api::String
	plmxml_api::String GetWorkLocationURI() const;

	//! Set WorkLocation URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWorkLocationURI( const plmxml_api::String& );
	
	//! Get the handle of WorkLocation URI. Does not resolve the URI.
	plmxml_api::Result GetWorkLocationURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of WorkLocation URI. URI string is unchanged.
	plmxml_api::Result SetWorkLocationURI( const plmxml_api::Handle& );
	
	//! Resolve WorkLocation URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWorkLocationURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset WorkLocation URI. Clears URI string and handle.
	plmxml_api::Result DeleteWorkLocationURI();
	
	//! Check if WorkLocation URI is set
	plmxml_api::logical HasWorkLocationURI( ) const;
	

	//! Get RemoveInstalls of this ExternalServiceActivityRevision
	plmxml_api::String GetRemoveInstalls() const;

	//! Set RemoveInstalls of this ExternalServiceActivityRevision
	plmxml_api::Result SetRemoveInstalls( const plmxml_api::String &s );
	
	//! Check if RemoveInstalls is set
	plmxml_api::logical HasRemoveInstalls( ) const;
	
	//! Unset RemoveInstalls
	plmxml_api::Result UnsetRemoveInstalls( );

	//! Get EndTime of this ExternalServiceActivityRevision
	plmxml_api::String GetEndTime() const;

	//! Set EndTime of this ExternalServiceActivityRevision
	plmxml_api::Result SetEndTime( const plmxml_api::String &s );
	
	//! Check if EndTime is set
	plmxml_api::logical HasEndTime( ) const;
	
	//! Unset EndTime
	plmxml_api::Result UnsetEndTime( );

	//! Get Zone of this ExternalServiceActivityRevision
	plmxml_api::String GetZone() const;

	//! Set Zone of this ExternalServiceActivityRevision
	plmxml_api::Result SetZone( const plmxml_api::String &s );
	
	//! Check if Zone is set
	plmxml_api::logical HasZone( ) const;
	
	//! Unset Zone
	plmxml_api::Result UnsetZone( );

	//! Get WorkCards of this ExternalServiceActivityRevision
	plmxml_api::String GetWorkCards() const;

	//! Set WorkCards of this ExternalServiceActivityRevision
	plmxml_api::Result SetWorkCards( const plmxml_api::String &s );
	
	//! Check if WorkCards is set
	plmxml_api::logical HasWorkCards( ) const;
	
	//! Unset WorkCards
	plmxml_api::Result UnsetWorkCards( );
 
// <PLMXML_UserCode type="functionHeaderExternalServiceActivityRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassExternalServiceActivityRevision;


////////////////////////////////////////////////////////////////////////////////////
//! PendingEventRelation class
/*!
\verbatim

      Pending Event Relation relates a Physical Part and an External Service
      Activity. The references in the inherited relatedRefs attribute must be in
      that order. This element has been deprecated and should not be used.
      
\endverbatim
*/
class PLMXML_MRO60_API PendingEventRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    PendingEventRelation( );
     
    //! Constructs a PendingEventRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PendingEventRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PendingEventRelation();

private:

	//! Assignment operator
	PendingEventRelation& operator=( const PendingEventRelation& iSrc );

	//! Copy constructor
	PendingEventRelation( const PendingEventRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPendingEventRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPendingEventRelation;


////////////////////////////////////////////////////////////////////////////////////
//! ElementEventRelation class
/*!
\verbatim

      Element Event Relation relates a Physical Part Revision and an External
      Service Activity. The references in the inherited relatedRefs attribute
      must be in that order. This element has been deprecated and should not be
      used.
      
\endverbatim
*/
class PLMXML_MRO60_API ElementEventRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    ElementEventRelation( );
     
    //! Constructs a ElementEventRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ElementEventRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ElementEventRelation();

private:

	//! Assignment operator
	ElementEventRelation& operator=( const ElementEventRelation& iSrc );

	//! Copy constructor
	ElementEventRelation( const ElementEventRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderElementEventRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassElementEventRelation;


////////////////////////////////////////////////////////////////////////////////////
//! DiscrepancyPhysicalProductRelation class
/*!
\verbatim

      Discrepancy Physical Product Relation relates an External Service Event
      Discrepancy Revision and a Physical Part. The references in the inherited
      relatedRefs attribute must be in that order. This element has been
      deprecated and should not be used.
      
\endverbatim
*/
class PLMXML_MRO60_API DiscrepancyPhysicalProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    DiscrepancyPhysicalProductRelation( );
     
    //! Constructs a DiscrepancyPhysicalProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DiscrepancyPhysicalProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DiscrepancyPhysicalProductRelation();

private:

	//! Assignment operator
	DiscrepancyPhysicalProductRelation& operator=( const DiscrepancyPhysicalProductRelation& iSrc );

	//! Copy constructor
	DiscrepancyPhysicalProductRelation( const DiscrepancyPhysicalProductRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDiscrepancyPhysicalProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassDiscrepancyPhysicalProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! DiscrepancyProductRelation class
/*!
\verbatim

      Discrepancy Product Relation relates an External Service Event Discrepancy
      Revision and a Neutral Structure Element. The references in the inherited
      relatedRefs attribute must be in that order. This element has been
      deprecated and should not be used.
      
\endverbatim
*/
class PLMXML_MRO60_API DiscrepancyProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    DiscrepancyProductRelation( );
     
    //! Constructs a DiscrepancyProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DiscrepancyProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DiscrepancyProductRelation();

private:

	//! Assignment operator
	DiscrepancyProductRelation& operator=( const DiscrepancyProductRelation& iSrc );

	//! Copy constructor
	DiscrepancyProductRelation( const DiscrepancyProductRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDiscrepancyProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassDiscrepancyProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RemovedInstalledDesignProductRelation class
/*!
\verbatim

      Removed-Installed Design Product Relation relates a Neutral Structure
      Element and a Remove Install Part. The references in the inherited
      relatedRefs attribute must be in that order. This element has been
      deprecated and should not be used.
      
\endverbatim
*/
class PLMXML_MRO60_API RemovedInstalledDesignProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    RemovedInstalledDesignProductRelation( );
     
    //! Constructs a RemovedInstalledDesignProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RemovedInstalledDesignProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RemovedInstalledDesignProductRelation();

private:

	//! Assignment operator
	RemovedInstalledDesignProductRelation& operator=( const RemovedInstalledDesignProductRelation& iSrc );

	//! Copy constructor
	RemovedInstalledDesignProductRelation( const RemovedInstalledDesignProductRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRemovedInstalledDesignProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRemovedInstalledDesignProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RemovedInstalledPhysicalProductRelation class
/*!
\verbatim

      Removed-Installed Physical Product Relation relates a Physical Part and a
      Remove Install Part. The references in the inherited relatedRefs attribute
      must be in that order. This element has been deprecated and should not be
      used.
      
\endverbatim
*/
class PLMXML_MRO60_API RemovedInstalledPhysicalProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    RemovedInstalledPhysicalProductRelation( );
     
    //! Constructs a RemovedInstalledPhysicalProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RemovedInstalledPhysicalProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RemovedInstalledPhysicalProductRelation();

private:

	//! Assignment operator
	RemovedInstalledPhysicalProductRelation& operator=( const RemovedInstalledPhysicalProductRelation& iSrc );

	//! Copy constructor
	RemovedInstalledPhysicalProductRelation( const RemovedInstalledPhysicalProductRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRemovedInstalledPhysicalProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRemovedInstalledPhysicalProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RemovedInstalledProductRelation class
/*!
\verbatim

      Removed-Installed Physical Product Relation relates an External Service
      Activity Revision and a Remove Install Part. The references in the
      inherited relatedRefs attribute must be in that order. This element has
      been deprecated and should not be used.
      
\endverbatim
*/
class PLMXML_MRO60_API RemovedInstalledProductRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    RemovedInstalledProductRelation( );
     
    //! Constructs a RemovedInstalledProductRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RemovedInstalledProductRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RemovedInstalledProductRelation();

private:

	//! Assignment operator
	RemovedInstalledProductRelation& operator=( const RemovedInstalledProductRelation& iSrc );

	//! Copy constructor
	RemovedInstalledProductRelation( const RemovedInstalledProductRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRemovedInstalledProductRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassRemovedInstalledProductRelation;


////////////////////////////////////////////////////////////////////////////////////
//! PathElementRelation class
/*!
\verbatim

      Path Element Relation relates an External Service Activity Revision and a
      Physical Part. The references in the inherited relatedRefs attribute must
      be in that order. This element has been deprecated and should not be used.

      Attributes:

      pESequence:       Path sequence number.
      
\endverbatim
*/
class PLMXML_MRO60_API PathElementRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    PathElementRelation( );
     
    //! Constructs a PathElementRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PathElementRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PathElementRelation();

private:

	//! Assignment operator
	PathElementRelation& operator=( const PathElementRelation& iSrc );

	//! Copy constructor
	PathElementRelation( const PathElementRelation& original );
     
public:

	//! Set PESequence
	plmxml_api::Result SetPESequence( int arg );
     
	//! Get PESequence
	int GetPESequence() const;
     
	//! Check if PESequence is set
	plmxml_api::logical HasPESequence() const;
     
	//! Unset PESequence
	plmxml_api::Result UnsetPESequence();
 
// <PLMXML_UserCode type="functionHeaderPathElementRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPathElementRelation;


////////////////////////////////////////////////////////////////////////////////////
//! HasSubActivitiesRelation class
/*!
\verbatim

      Has Sub-Activities Relation relates a Service Event Revision and a Service
      Event. The references in the inherited relatedRefs attribute must be in
      that order. This element has been deprecated and should not be used.
      
\endverbatim
*/
class PLMXML_MRO60_API HasSubActivitiesRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    HasSubActivitiesRelation( );
     
    //! Constructs a HasSubActivitiesRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HasSubActivitiesRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HasSubActivitiesRelation();

private:

	//! Assignment operator
	HasSubActivitiesRelation& operator=( const HasSubActivitiesRelation& iSrc );

	//! Copy constructor
	HasSubActivitiesRelation( const HasSubActivitiesRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderHasSubActivitiesRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassHasSubActivitiesRelation;


////////////////////////////////////////////////////////////////////////////////////
//! LogBook class
/*!
\verbatim

      Log Book information.

      Attributes:

      name:             Inherited from Managed. It is required in this context.
      realisedProductRef: References the Realised Product.

      Sub-elements:

      Description:      Inherited from Managed.
      
\endverbatim
*/
class PLMXML_MRO60_API LogBook : public Managed
{
public:
     
    //! Default constructor
    LogBook( );
     
    //! Constructs a LogBook with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LogBook( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LogBook();

private:

	//! Assignment operator
	LogBook& operator=( const LogBook& iSrc );

	//! Copy constructor
	LogBook( const LogBook& original );
     
public:

	//! Get RealisedProduct URI as plmxml_api::String
	plmxml_api::String GetRealisedProductURI() const;

	//! Set RealisedProduct URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRealisedProductURI( const plmxml_api::String& );
	
	//! Get the handle of RealisedProduct URI. Does not resolve the URI.
	plmxml_api::Result GetRealisedProductURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of RealisedProduct URI. URI string is unchanged.
	plmxml_api::Result SetRealisedProductURI( const plmxml_api::Handle& );
	
	//! Resolve RealisedProduct URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRealisedProductURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset RealisedProduct URI. Clears URI string and handle.
	plmxml_api::Result DeleteRealisedProductURI();
	
	//! Check if RealisedProduct URI is set
	plmxml_api::logical HasRealisedProductURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLogBook" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLogBook;


////////////////////////////////////////////////////////////////////////////////////
//! LogEntry class
/*!
\verbatim

      Log Entry information.

      Attributes:

      name:             Inherited from Managed. It is required in this context.
      time:             The time at which the values for the Log Entry are
                        recorded.
      capturedBy:       The name of the person who recorded the values.
      logBookRef:       References the Log Book.

      Sub-elements:

      Description:      Inherited from Managed.
      
\endverbatim
*/
class PLMXML_MRO60_API LogEntry : public Managed
{
public:
     
    //! Default constructor
    LogEntry( );
     
    //! Constructs a LogEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LogEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LogEntry();

private:

	//! Assignment operator
	LogEntry& operator=( const LogEntry& iSrc );

	//! Copy constructor
	LogEntry( const LogEntry& original );
     
public:

	//! Get CapturedBy of this LogEntry
	plmxml_api::String GetCapturedBy() const;

	//! Set CapturedBy of this LogEntry
	plmxml_api::Result SetCapturedBy( const plmxml_api::String &s );
	
	//! Check if CapturedBy is set
	plmxml_api::logical HasCapturedBy( ) const;
	
	//! Unset CapturedBy
	plmxml_api::Result UnsetCapturedBy( );

	//! Get Time of this LogEntry
	plmxml_api::String GetTime() const;

	//! Set Time of this LogEntry
	plmxml_api::Result SetTime( const plmxml_api::String &s );
	
	//! Check if Time is set
	plmxml_api::logical HasTime( ) const;
	
	//! Unset Time
	plmxml_api::Result UnsetTime( );

	//! Get LogBook URI as plmxml_api::String
	plmxml_api::String GetLogBookURI() const;

	//! Set LogBook URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetLogBookURI( const plmxml_api::String& );
	
	//! Get the handle of LogBook URI. Does not resolve the URI.
	plmxml_api::Result GetLogBookURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of LogBook URI. URI string is unchanged.
	plmxml_api::Result SetLogBookURI( const plmxml_api::Handle& );
	
	//! Resolve LogBook URI and return an object (handle) it points to.
	plmxml_api::Result ResolveLogBookURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset LogBook URI. Clears URI string and handle.
	plmxml_api::Result DeleteLogBookURI();
	
	//! Check if LogBook URI is set
	plmxml_api::logical HasLogBookURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLogEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLogEntry;


////////////////////////////////////////////////////////////////////////////////////
//! Disposition class
/*!
\verbatim

      Represents the disposition state of a RealisedProduct.

      Attributes:

      name:             Inherited from Managed.
      isServiceable:    Whether the related RealisedProduct is serviceable.
      
\endverbatim
*/
class PLMXML_MRO60_API Disposition : public Managed
{
public:
     
    //! Default constructor
    Disposition( );
     
    //! Constructs a Disposition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Disposition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Disposition();

private:

	//! Assignment operator
	Disposition& operator=( const Disposition& iSrc );

	//! Copy constructor
	Disposition( const Disposition& original );
     
public:

	//! Set IsServiceable
	plmxml_api::Result SetIsServiceable( plmxml_api::logical arg );

	//! Get IsServiceable
	plmxml_api::logical GetIsServiceable() const;

	//! Check if IsServiceable is set
	plmxml_api::logical HasIsServiceable() const;

	//! Unset IsServiceable
	plmxml_api::Result UnsetIsServiceable();
 
// <PLMXML_UserCode type="functionHeaderDisposition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassDisposition;


////////////////////////////////////////////////////////////////////////////////////
//! PhysicalLogEntriesRelation class
/*!
\verbatim

      This Relation relates a RealisedProduct to a Log Entry. The references in
      the inherited relatedRefs attribute must be in that order.
      
\endverbatim
*/
class PLMXML_MRO60_API PhysicalLogEntriesRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    PhysicalLogEntriesRelation( );
     
    //! Constructs a PhysicalLogEntriesRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PhysicalLogEntriesRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PhysicalLogEntriesRelation();

private:

	//! Assignment operator
	PhysicalLogEntriesRelation& operator=( const PhysicalLogEntriesRelation& iSrc );

	//! Copy constructor
	PhysicalLogEntriesRelation( const PhysicalLogEntriesRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPhysicalLogEntriesRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPhysicalLogEntriesRelation;


////////////////////////////////////////////////////////////////////////////////////
//! LogEntryValuesRelation class
/*!
\verbatim

      This relation relates a Log Entry to a Characteristic Value. The
      references in the inherited relatedRefs attribute must be in that order.
      
\endverbatim
*/
class PLMXML_MRO60_API LogEntryValuesRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    LogEntryValuesRelation( );
     
    //! Constructs a LogEntryValuesRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LogEntryValuesRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LogEntryValuesRelation();

private:

	//! Assignment operator
	LogEntryValuesRelation& operator=( const LogEntryValuesRelation& iSrc );

	//! Copy constructor
	LogEntryValuesRelation( const LogEntryValuesRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderLogEntryValuesRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassLogEntryValuesRelation;


////////////////////////////////////////////////////////////////////////////////////
//! DispositionApplicabilityRelation class
/*!
\verbatim

      This relation relates a RealisedProduct to a Disposition. The references
      in the inherited relatedRefs attribute must be in that order.

      Attributes:

      startTime:        The time when the RealisedProduct enters the Disposition
                        state.
      endTime:          The time when the RealisedProduct leaves the Disposition
                        state.
      
\endverbatim
*/
class PLMXML_MRO60_API DispositionApplicabilityRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    DispositionApplicabilityRelation( );
     
    //! Constructs a DispositionApplicabilityRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DispositionApplicabilityRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DispositionApplicabilityRelation();

private:

	//! Assignment operator
	DispositionApplicabilityRelation& operator=( const DispositionApplicabilityRelation& iSrc );

	//! Copy constructor
	DispositionApplicabilityRelation( const DispositionApplicabilityRelation& original );
     
public:

	//! Get EndTime of this DispositionApplicabilityRelation
	plmxml_api::String GetEndTime() const;

	//! Set EndTime of this DispositionApplicabilityRelation
	plmxml_api::Result SetEndTime( const plmxml_api::String &s );
	
	//! Check if EndTime is set
	plmxml_api::logical HasEndTime( ) const;
	
	//! Unset EndTime
	plmxml_api::Result UnsetEndTime( );

	//! Get StartTime of this DispositionApplicabilityRelation
	plmxml_api::String GetStartTime() const;

	//! Set StartTime of this DispositionApplicabilityRelation
	plmxml_api::Result SetStartTime( const plmxml_api::String &s );
	
	//! Check if StartTime is set
	plmxml_api::logical HasStartTime( ) const;
	
	//! Unset StartTime
	plmxml_api::Result UnsetStartTime( );
 
// <PLMXML_UserCode type="functionHeaderDispositionApplicabilityRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassDispositionApplicabilityRelation;


////////////////////////////////////////////////////////////////////////////////////
//! NeutralCharacteristicRelation class
/*!
\verbatim

      This relation relates a Product to a Characteristic Definition. The
      references in the inherited relatedRefs attribute must be in that order.
      
\endverbatim
*/
class PLMXML_MRO60_API NeutralCharacteristicRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    NeutralCharacteristicRelation( );
     
    //! Constructs a NeutralCharacteristicRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NeutralCharacteristicRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NeutralCharacteristicRelation();

private:

	//! Assignment operator
	NeutralCharacteristicRelation& operator=( const NeutralCharacteristicRelation& iSrc );

	//! Copy constructor
	NeutralCharacteristicRelation( const NeutralCharacteristicRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderNeutralCharacteristicRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassNeutralCharacteristicRelation;


////////////////////////////////////////////////////////////////////////////////////
//! TransactionElement class
/*!
\verbatim

      Abstract sub-class.

      Attributes:

      name:             Inherited from AttribOwner. Workspace object name.
      description:      Inherited from AttribOwner. Workspace description.
      transactionId:    Transaction Id.
      initiationDate:   Initiation date.
      dueDate:          Due date.
      approval:         Status of approval.
      disposition:      Disposition.
      purpose:          Purpose of service.
      dispositionDate:  Completed date.
      dispositionedBy:  Completed by.
      transactionElementType: Transaction Element type.
      activityCostRef:  References the activity cost.
      physicalPartRevisionRefs: References one or more Physical Part Revisions.
      containsRefs:     References one or more contains Physical Parts.
      
\endverbatim
*/
class PLMXML_MRO60_API TransactionElement : public AttribOwner
{
public:
     
    //! Default constructor
    TransactionElement( );
     
    //! Constructs a TransactionElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TransactionElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TransactionElement();

private:

	//! Assignment operator
	TransactionElement& operator=( const TransactionElement& iSrc );

	//! Copy constructor
	TransactionElement( const TransactionElement& original );
     
public:

	//! Get DispositionDate of this TransactionElement
	plmxml_api::String GetDispositionDate() const;

	//! Set DispositionDate of this TransactionElement
	plmxml_api::Result SetDispositionDate( const plmxml_api::String &s );
	
	//! Check if DispositionDate is set
	plmxml_api::logical HasDispositionDate( ) const;
	
	//! Unset DispositionDate
	plmxml_api::Result UnsetDispositionDate( );

	//! Get TransactionId of this TransactionElement
	plmxml_api::String GetTransactionId() const;

	//! Set TransactionId of this TransactionElement
	plmxml_api::Result SetTransactionId( const plmxml_api::String &s );
	
	//! Check if TransactionId is set
	plmxml_api::logical HasTransactionId( ) const;
	
	//! Unset TransactionId
	plmxml_api::Result UnsetTransactionId( );

	//! Get DueDate of this TransactionElement
	plmxml_api::String GetDueDate() const;

	//! Set DueDate of this TransactionElement
	plmxml_api::Result SetDueDate( const plmxml_api::String &s );
	
	//! Check if DueDate is set
	plmxml_api::logical HasDueDate( ) const;
	
	//! Unset DueDate
	plmxml_api::Result UnsetDueDate( );

	//! Get Purpose of this TransactionElement
	plmxml_api::String GetPurpose() const;

	//! Set Purpose of this TransactionElement
	plmxml_api::Result SetPurpose( const plmxml_api::String &s );
	
	//! Check if Purpose is set
	plmxml_api::logical HasPurpose( ) const;
	
	//! Unset Purpose
	plmxml_api::Result UnsetPurpose( );

	//! Get TransactionElementType of this TransactionElement
	plmxml_api::String GetTransactionElementType() const;

	//! Set TransactionElementType of this TransactionElement
	plmxml_api::Result SetTransactionElementType( const plmxml_api::String &s );
	
	//! Check if TransactionElementType is set
	plmxml_api::logical HasTransactionElementType( ) const;
	
	//! Unset TransactionElementType
	plmxml_api::Result UnsetTransactionElementType( );

	//! Get Disposition of this TransactionElement
	plmxml_api::String GetDisposition() const;

	//! Set Disposition of this TransactionElement
	plmxml_api::Result SetDisposition( const plmxml_api::String &s );
	
	//! Check if Disposition is set
	plmxml_api::logical HasDisposition( ) const;
	
	//! Unset Disposition
	plmxml_api::Result UnsetDisposition( );

	//! Get number of URIs in Contains
	int NumberOfContainsURIs() const;

	//! Get i'th URI in Contains
	plmxml_api::String GetContainsURI( int i ) const;

	//! Add a URI to Contains array. Call ResolveContainsURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddContainsURI( const plmxml_api::String& u );

	//! Set i'th URI in Contains array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetContainsURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Contains URI. Does not resolve the URI.
	plmxml_api::Result GetContainsURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Contains array.
	plmxml_api::Result AddContainsURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Contains array to point to 'handle'.
	plmxml_api::Result SetContainsURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Contains points to.
	plmxml_api::Result ResolveContainsURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Contains array.
	plmxml_api::Result DeleteContainsURI( int i );

	//! Remove all URIs from Contains array.
	plmxml_api::Result DeleteContainsURIs( );
	
	//! Check if Contains is set
	plmxml_api::logical HasContainsURIs( ) const;

	//! Get Approval of this TransactionElement
	plmxml_api::String GetApproval() const;

	//! Set Approval of this TransactionElement
	plmxml_api::Result SetApproval( const plmxml_api::String &s );
	
	//! Check if Approval is set
	plmxml_api::logical HasApproval( ) const;
	
	//! Unset Approval
	plmxml_api::Result UnsetApproval( );

	//! Get InitiationDate of this TransactionElement
	plmxml_api::String GetInitiationDate() const;

	//! Set InitiationDate of this TransactionElement
	plmxml_api::Result SetInitiationDate( const plmxml_api::String &s );
	
	//! Check if InitiationDate is set
	plmxml_api::logical HasInitiationDate( ) const;
	
	//! Unset InitiationDate
	plmxml_api::Result UnsetInitiationDate( );

	//! Get ActivityCost URI as plmxml_api::String
	plmxml_api::String GetActivityCostURI() const;

	//! Set ActivityCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActivityCostURI( const plmxml_api::String& );
	
	//! Get the handle of ActivityCost URI. Does not resolve the URI.
	plmxml_api::Result GetActivityCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActivityCost URI. URI string is unchanged.
	plmxml_api::Result SetActivityCostURI( const plmxml_api::Handle& );
	
	//! Resolve ActivityCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActivityCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActivityCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteActivityCostURI();
	
	//! Check if ActivityCost URI is set
	plmxml_api::logical HasActivityCostURI( ) const;
	

	//! Get number of URIs in PhysicalPartRevision
	int NumberOfPhysicalPartRevisionURIs() const;

	//! Get i'th URI in PhysicalPartRevision
	plmxml_api::String GetPhysicalPartRevisionURI( int i ) const;

	//! Add a URI to PhysicalPartRevision array. Call ResolvePhysicalPartRevisionURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPhysicalPartRevisionURI( const plmxml_api::String& u );

	//! Set i'th URI in PhysicalPartRevision array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPhysicalPartRevisionURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of PhysicalPartRevision URI. Does not resolve the URI.
	plmxml_api::Result GetPhysicalPartRevisionURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to PhysicalPartRevision array.
	plmxml_api::Result AddPhysicalPartRevisionURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in PhysicalPartRevision array to point to 'handle'.
	plmxml_api::Result SetPhysicalPartRevisionURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in PhysicalPartRevision points to.
	plmxml_api::Result ResolvePhysicalPartRevisionURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from PhysicalPartRevision array.
	plmxml_api::Result DeletePhysicalPartRevisionURI( int i );

	//! Remove all URIs from PhysicalPartRevision array.
	plmxml_api::Result DeletePhysicalPartRevisionURIs( );
	
	//! Check if PhysicalPartRevision is set
	plmxml_api::logical HasPhysicalPartRevisionURIs( ) const;

	//! Get DispositionedBy of this TransactionElement
	plmxml_api::String GetDispositionedBy() const;

	//! Set DispositionedBy of this TransactionElement
	plmxml_api::Result SetDispositionedBy( const plmxml_api::String &s );
	
	//! Check if DispositionedBy is set
	plmxml_api::logical HasDispositionedBy( ) const;
	
	//! Unset DispositionedBy
	plmxml_api::Result UnsetDispositionedBy( );
 
// <PLMXML_UserCode type="functionHeaderTransactionElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassTransactionElement;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceGroup class
/*!
\verbatim

      Container for Service Group, Service Event and Service Discrepancy.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceGroup : public TransactionElement
{
public:
     
    //! Default constructor
    ServiceGroup( );
     
    //! Constructs a ServiceGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceGroup();

private:

	//! Assignment operator
	ServiceGroup& operator=( const ServiceGroup& iSrc );

	//! Copy constructor
	ServiceGroup( const ServiceGroup& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderServiceGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceGroup;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceActivity class
/*!
\verbatim

      Generic service information.

      Attributes:

      transactionNote:  User defined notes.
      needByDate:       Need by date.
      activityNumber:   Identification.
      authorizedBy:     Authorized by.
      isPreventativeMaintenance: Is preventative maintenance?
      usagePathRef:     References a Part Position Path - Contains a position
                        path of any remove or install events.
      category:         Category.
      activityEntryValueRefs: References one or more entry values.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceActivity : public TransactionElement
{
public:
     
    //! Default constructor
    ServiceActivity( );
     
    //! Constructs a ServiceActivity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceActivity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceActivity();

private:

	//! Assignment operator
	ServiceActivity& operator=( const ServiceActivity& iSrc );

	//! Copy constructor
	ServiceActivity( const ServiceActivity& original );
     
public:

	//! Get AuthorizedBy of this ServiceActivity
	plmxml_api::String GetAuthorizedBy() const;

	//! Set AuthorizedBy of this ServiceActivity
	plmxml_api::Result SetAuthorizedBy( const plmxml_api::String &s );
	
	//! Check if AuthorizedBy is set
	plmxml_api::logical HasAuthorizedBy( ) const;
	
	//! Unset AuthorizedBy
	plmxml_api::Result UnsetAuthorizedBy( );

	//! Set Category
	plmxml_api::Result SetCategory( const eCategoryEnum& arg );

	//! Get Category
	eCategoryEnum GetCategory() const;

	//! Set IsPreventativeMaintenance
	plmxml_api::Result SetIsPreventativeMaintenance( plmxml_api::logical arg );

	//! Get IsPreventativeMaintenance
	plmxml_api::logical GetIsPreventativeMaintenance() const;

	//! Check if IsPreventativeMaintenance is set
	plmxml_api::logical HasIsPreventativeMaintenance() const;

	//! Unset IsPreventativeMaintenance
	plmxml_api::Result UnsetIsPreventativeMaintenance();

	//! Get number of URIs in ActivityEntryValue
	int NumberOfActivityEntryValueURIs() const;

	//! Get i'th URI in ActivityEntryValue
	plmxml_api::String GetActivityEntryValueURI( int i ) const;

	//! Add a URI to ActivityEntryValue array. Call ResolveActivityEntryValueURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActivityEntryValueURI( const plmxml_api::String& u );

	//! Set i'th URI in ActivityEntryValue array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActivityEntryValueURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ActivityEntryValue URI. Does not resolve the URI.
	plmxml_api::Result GetActivityEntryValueURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ActivityEntryValue array.
	plmxml_api::Result AddActivityEntryValueURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ActivityEntryValue array to point to 'handle'.
	plmxml_api::Result SetActivityEntryValueURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ActivityEntryValue points to.
	plmxml_api::Result ResolveActivityEntryValueURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ActivityEntryValue array.
	plmxml_api::Result DeleteActivityEntryValueURI( int i );

	//! Remove all URIs from ActivityEntryValue array.
	plmxml_api::Result DeleteActivityEntryValueURIs( );
	
	//! Check if ActivityEntryValue is set
	plmxml_api::logical HasActivityEntryValueURIs( ) const;

	//! Get TransactionNote of this ServiceActivity
	plmxml_api::String GetTransactionNote() const;

	//! Set TransactionNote of this ServiceActivity
	plmxml_api::Result SetTransactionNote( const plmxml_api::String &s );
	
	//! Check if TransactionNote is set
	plmxml_api::logical HasTransactionNote( ) const;
	
	//! Unset TransactionNote
	plmxml_api::Result UnsetTransactionNote( );

	//! Get UsagePath URI as plmxml_api::String
	plmxml_api::String GetUsagePathURI() const;

	//! Set UsagePath URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUsagePathURI( const plmxml_api::String& );
	
	//! Get the handle of UsagePath URI. Does not resolve the URI.
	plmxml_api::Result GetUsagePathURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of UsagePath URI. URI string is unchanged.
	plmxml_api::Result SetUsagePathURI( const plmxml_api::Handle& );
	
	//! Resolve UsagePath URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUsagePathURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset UsagePath URI. Clears URI string and handle.
	plmxml_api::Result DeleteUsagePathURI();
	
	//! Check if UsagePath URI is set
	plmxml_api::logical HasUsagePathURI( ) const;
	

	//! Get ActivityNumber of this ServiceActivity
	plmxml_api::String GetActivityNumber() const;

	//! Set ActivityNumber of this ServiceActivity
	plmxml_api::Result SetActivityNumber( const plmxml_api::String &s );
	
	//! Check if ActivityNumber is set
	plmxml_api::logical HasActivityNumber( ) const;
	
	//! Unset ActivityNumber
	plmxml_api::Result UnsetActivityNumber( );

	//! Get NeedByDate of this ServiceActivity
	plmxml_api::String GetNeedByDate() const;

	//! Set NeedByDate of this ServiceActivity
	plmxml_api::Result SetNeedByDate( const plmxml_api::String &s );
	
	//! Check if NeedByDate is set
	plmxml_api::logical HasNeedByDate( ) const;
	
	//! Unset NeedByDate
	plmxml_api::Result UnsetNeedByDate( );
 
// <PLMXML_UserCode type="functionHeaderServiceActivity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceActivity;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceDiscrepancy class
/*!
\verbatim

      Service Discrepancy information.

      Attributes:

      severity:         Severity.
      isFailure:        Discrepancy was the result of a failure?
      discoveredBy:     Discovered by.
      discoveryDate:    Discovery date.
      faultCodeRefs:    References one or more fault codes in the event of a
                        failure.
      isMEL:            Minimum equipment list?
      correctiveActionRefs:	References one or more Service Events as a
                        corrective action.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceDiscrepancy : public ServiceActivity
{
public:
     
    //! Default constructor
    ServiceDiscrepancy( );
     
    //! Constructs a ServiceDiscrepancy with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceDiscrepancy( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceDiscrepancy();

private:

	//! Assignment operator
	ServiceDiscrepancy& operator=( const ServiceDiscrepancy& iSrc );

	//! Copy constructor
	ServiceDiscrepancy( const ServiceDiscrepancy& original );
     
public:

	//! Get Severity of this ServiceDiscrepancy
	plmxml_api::String GetSeverity() const;

	//! Set Severity of this ServiceDiscrepancy
	plmxml_api::Result SetSeverity( const plmxml_api::String &s );
	
	//! Check if Severity is set
	plmxml_api::logical HasSeverity( ) const;
	
	//! Unset Severity
	plmxml_api::Result UnsetSeverity( );

	//! Set IsMEL
	plmxml_api::Result SetIsMEL( plmxml_api::logical arg );

	//! Get IsMEL
	plmxml_api::logical GetIsMEL() const;

	//! Check if IsMEL is set
	plmxml_api::logical HasIsMEL() const;

	//! Unset IsMEL
	plmxml_api::Result UnsetIsMEL();

	//! Get number of URIs in CorrectiveAction
	int NumberOfCorrectiveActionURIs() const;

	//! Get i'th URI in CorrectiveAction
	plmxml_api::String GetCorrectiveActionURI( int i ) const;

	//! Add a URI to CorrectiveAction array. Call ResolveCorrectiveActionURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCorrectiveActionURI( const plmxml_api::String& u );

	//! Set i'th URI in CorrectiveAction array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCorrectiveActionURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of CorrectiveAction URI. Does not resolve the URI.
	plmxml_api::Result GetCorrectiveActionURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to CorrectiveAction array.
	plmxml_api::Result AddCorrectiveActionURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in CorrectiveAction array to point to 'handle'.
	plmxml_api::Result SetCorrectiveActionURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in CorrectiveAction points to.
	plmxml_api::Result ResolveCorrectiveActionURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from CorrectiveAction array.
	plmxml_api::Result DeleteCorrectiveActionURI( int i );

	//! Remove all URIs from CorrectiveAction array.
	plmxml_api::Result DeleteCorrectiveActionURIs( );
	
	//! Check if CorrectiveAction is set
	plmxml_api::logical HasCorrectiveActionURIs( ) const;

	//! Get DiscoveryDate of this ServiceDiscrepancy
	plmxml_api::String GetDiscoveryDate() const;

	//! Set DiscoveryDate of this ServiceDiscrepancy
	plmxml_api::Result SetDiscoveryDate( const plmxml_api::String &s );
	
	//! Check if DiscoveryDate is set
	plmxml_api::logical HasDiscoveryDate( ) const;
	
	//! Unset DiscoveryDate
	plmxml_api::Result UnsetDiscoveryDate( );

	//! Get number of URIs in FaultCode
	int NumberOfFaultCodeURIs() const;

	//! Get i'th URI in FaultCode
	plmxml_api::String GetFaultCodeURI( int i ) const;

	//! Add a URI to FaultCode array. Call ResolveFaultCodeURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFaultCodeURI( const plmxml_api::String& u );

	//! Set i'th URI in FaultCode array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFaultCodeURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of FaultCode URI. Does not resolve the URI.
	plmxml_api::Result GetFaultCodeURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to FaultCode array.
	plmxml_api::Result AddFaultCodeURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in FaultCode array to point to 'handle'.
	plmxml_api::Result SetFaultCodeURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in FaultCode points to.
	plmxml_api::Result ResolveFaultCodeURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from FaultCode array.
	plmxml_api::Result DeleteFaultCodeURI( int i );

	//! Remove all URIs from FaultCode array.
	plmxml_api::Result DeleteFaultCodeURIs( );
	
	//! Check if FaultCode is set
	plmxml_api::logical HasFaultCodeURIs( ) const;

	//! Set IsFailure
	plmxml_api::Result SetIsFailure( plmxml_api::logical arg );

	//! Get IsFailure
	plmxml_api::logical GetIsFailure() const;

	//! Check if IsFailure is set
	plmxml_api::logical HasIsFailure() const;

	//! Unset IsFailure
	plmxml_api::Result UnsetIsFailure();

	//! Get DiscoveredBy of this ServiceDiscrepancy
	plmxml_api::String GetDiscoveredBy() const;

	//! Set DiscoveredBy of this ServiceDiscrepancy
	plmxml_api::Result SetDiscoveredBy( const plmxml_api::String &s );
	
	//! Check if DiscoveredBy is set
	plmxml_api::logical HasDiscoveredBy( ) const;
	
	//! Unset DiscoveredBy
	plmxml_api::Result UnsetDiscoveredBy( );
 
// <PLMXML_UserCode type="functionHeaderServiceDiscrepancy" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceDiscrepancy;


////////////////////////////////////////////////////////////////////////////////////
//! ServicePerformed class
/*!
\verbatim

      Service Performed information.

      Attributes:

      workStartDate:    Work start date.
      partMovementRefs:  References one or more Part Movements.
      
\endverbatim
*/
class PLMXML_MRO60_API ServicePerformed : public ServiceActivity
{
public:
     
    //! Default constructor
    ServicePerformed( );
     
    //! Constructs a ServicePerformed with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServicePerformed( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServicePerformed();

private:

	//! Assignment operator
	ServicePerformed& operator=( const ServicePerformed& iSrc );

	//! Copy constructor
	ServicePerformed( const ServicePerformed& original );
     
public:

	//! Get WorkStartDate of this ServicePerformed
	plmxml_api::String GetWorkStartDate() const;

	//! Set WorkStartDate of this ServicePerformed
	plmxml_api::Result SetWorkStartDate( const plmxml_api::String &s );
	
	//! Check if WorkStartDate is set
	plmxml_api::logical HasWorkStartDate( ) const;
	
	//! Unset WorkStartDate
	plmxml_api::Result UnsetWorkStartDate( );

	//! Get number of URIs in PartMovement
	int NumberOfPartMovementURIs() const;

	//! Get i'th URI in PartMovement
	plmxml_api::String GetPartMovementURI( int i ) const;

	//! Add a URI to PartMovement array. Call ResolvePartMovementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPartMovementURI( const plmxml_api::String& u );

	//! Set i'th URI in PartMovement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPartMovementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of PartMovement URI. Does not resolve the URI.
	plmxml_api::Result GetPartMovementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to PartMovement array.
	plmxml_api::Result AddPartMovementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in PartMovement array to point to 'handle'.
	plmxml_api::Result SetPartMovementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in PartMovement points to.
	plmxml_api::Result ResolvePartMovementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from PartMovement array.
	plmxml_api::Result DeletePartMovementURI( int i );

	//! Remove all URIs from PartMovement array.
	plmxml_api::Result DeletePartMovementURIs( );
	
	//! Check if PartMovement is set
	plmxml_api::logical HasPartMovementURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderServicePerformed" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServicePerformed;


////////////////////////////////////////////////////////////////////////////////////
//! TCServiceEvent class
/*!
\verbatim

      Service Event information.

      Attributes:

      workLocation:     Location where the service was performed.
      jobCards:         Job cards/work cards used.
      zones:            Zones where the service was performed.
      signedOffBy:      Other sign offs.
      
\endverbatim
*/
class PLMXML_MRO60_API TCServiceEvent : public ServicePerformed
{
public:
     
    //! Default constructor
    TCServiceEvent( );
     
    //! Constructs a TCServiceEvent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TCServiceEvent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TCServiceEvent();

private:

	//! Assignment operator
	TCServiceEvent& operator=( const TCServiceEvent& iSrc );

	//! Copy constructor
	TCServiceEvent( const TCServiceEvent& original );
     
public:

	//! Get WorkLocation of this TCServiceEvent
	plmxml_api::String GetWorkLocation() const;

	//! Set WorkLocation of this TCServiceEvent
	plmxml_api::Result SetWorkLocation( const plmxml_api::String &s );
	
	//! Check if WorkLocation is set
	plmxml_api::logical HasWorkLocation( ) const;
	
	//! Unset WorkLocation
	plmxml_api::Result UnsetWorkLocation( );

	//! Get JobCards of this TCServiceEvent
	plmxml_api::String GetJobCards() const;

	//! Set JobCards of this TCServiceEvent
	plmxml_api::Result SetJobCards( const plmxml_api::String &s );
	
	//! Check if JobCards is set
	plmxml_api::logical HasJobCards( ) const;
	
	//! Unset JobCards
	plmxml_api::Result UnsetJobCards( );

	//! Get Zones of this TCServiceEvent
	plmxml_api::String GetZones() const;

	//! Set Zones of this TCServiceEvent
	plmxml_api::Result SetZones( const plmxml_api::String &s );
	
	//! Check if Zones is set
	plmxml_api::logical HasZones( ) const;
	
	//! Unset Zones
	plmxml_api::Result UnsetZones( );

	//! Get SignedOffBy of this TCServiceEvent
	plmxml_api::String GetSignedOffBy() const;

	//! Set SignedOffBy of this TCServiceEvent
	plmxml_api::Result SetSignedOffBy( const plmxml_api::String &s );
	
	//! Check if SignedOffBy is set
	plmxml_api::logical HasSignedOffBy( ) const;
	
	//! Unset SignedOffBy
	plmxml_api::Result UnsetSignedOffBy( );
 
// <PLMXML_UserCode type="functionHeaderTCServiceEvent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassTCServiceEvent;


////////////////////////////////////////////////////////////////////////////////////
//! PartMovement class
/*!
\verbatim

      Part Movement information.

      Attributes:

      name:             Inherited from AttribOwner. Workspace object name.
      description:      Inherited from AttribOwner. Workspace description.
      manufacturerId:   Manufacturer's Id.
      partNumber:       Part number.
      serialNumber:     Serial number.
      lotNumber:        Lot number.
      usageName:        Usage name.
      isTraceable:      Is true if part is traced.
      partMovementType: Type of action - Install, Remove or Change.
      isNew:            Is new part?
      isApprovedDeviation: Is approved deviation?
      actionDate:       Action date.
      newPartClass:     New part class. Deprecated.
      newPartName:      Part name. Deprecated.
      parentPhysicalElementRef: References a parent element.
      physicalPartRef:  References the installed, uninstalled or replacement
                        physical part.
      isExtraToDesign:  Is extra to design?
      movedPartRef:     Part that will be utilized to generate the new Part.
      movedOccurrenceRef: Occurrence reference.
      replacedPartRef:  References the replaced physical part.
      
\endverbatim
*/
class PLMXML_MRO60_API PartMovement : public AttribOwner
{
public:
     
    //! Default constructor
    PartMovement( );
     
    //! Constructs a PartMovement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PartMovement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PartMovement();

private:

	//! Assignment operator
	PartMovement& operator=( const PartMovement& iSrc );

	//! Copy constructor
	PartMovement( const PartMovement& original );
     
public:

	//! Get MovedOccurrence URI as plmxml_api::String
	plmxml_api::String GetMovedOccurrenceURI() const;

	//! Set MovedOccurrence URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMovedOccurrenceURI( const plmxml_api::String& );
	
	//! Get the handle of MovedOccurrence URI. Does not resolve the URI.
	plmxml_api::Result GetMovedOccurrenceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of MovedOccurrence URI. URI string is unchanged.
	plmxml_api::Result SetMovedOccurrenceURI( const plmxml_api::Handle& );
	
	//! Resolve MovedOccurrence URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMovedOccurrenceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset MovedOccurrence URI. Clears URI string and handle.
	plmxml_api::Result DeleteMovedOccurrenceURI();
	
	//! Check if MovedOccurrence URI is set
	plmxml_api::logical HasMovedOccurrenceURI( ) const;
	

	//! Get UsageName of this PartMovement
	plmxml_api::String GetUsageName() const;

	//! Set UsageName of this PartMovement
	plmxml_api::Result SetUsageName( const plmxml_api::String &s );
	
	//! Check if UsageName is set
	plmxml_api::logical HasUsageName( ) const;
	
	//! Unset UsageName
	plmxml_api::Result UnsetUsageName( );

	//! Get PhysicalPart URI as plmxml_api::String
	plmxml_api::String GetPhysicalPartURI() const;

	//! Set PhysicalPart URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPhysicalPartURI( const plmxml_api::String& );
	
	//! Get the handle of PhysicalPart URI. Does not resolve the URI.
	plmxml_api::Result GetPhysicalPartURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of PhysicalPart URI. URI string is unchanged.
	plmxml_api::Result SetPhysicalPartURI( const plmxml_api::Handle& );
	
	//! Resolve PhysicalPart URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePhysicalPartURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset PhysicalPart URI. Clears URI string and handle.
	plmxml_api::Result DeletePhysicalPartURI();
	
	//! Check if PhysicalPart URI is set
	plmxml_api::logical HasPhysicalPartURI( ) const;
	

	//! Set IsTraceable
	plmxml_api::Result SetIsTraceable( plmxml_api::logical arg );

	//! Get IsTraceable
	plmxml_api::logical GetIsTraceable() const;

	//! Check if IsTraceable is set
	plmxml_api::logical HasIsTraceable() const;

	//! Unset IsTraceable
	plmxml_api::Result UnsetIsTraceable();

	//! Get NewPartName of this PartMovement
	plmxml_api::String GetNewPartName() const;

	//! Set NewPartName of this PartMovement
	plmxml_api::Result SetNewPartName( const plmxml_api::String &s );
	
	//! Check if NewPartName is set
	plmxml_api::logical HasNewPartName( ) const;
	
	//! Unset NewPartName
	plmxml_api::Result UnsetNewPartName( );

	//! Get ReplacedPart URI as plmxml_api::String
	plmxml_api::String GetReplacedPartURI() const;

	//! Set ReplacedPart URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReplacedPartURI( const plmxml_api::String& );
	
	//! Get the handle of ReplacedPart URI. Does not resolve the URI.
	plmxml_api::Result GetReplacedPartURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ReplacedPart URI. URI string is unchanged.
	plmxml_api::Result SetReplacedPartURI( const plmxml_api::Handle& );
	
	//! Resolve ReplacedPart URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReplacedPartURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ReplacedPart URI. Clears URI string and handle.
	plmxml_api::Result DeleteReplacedPartURI();
	
	//! Check if ReplacedPart URI is set
	plmxml_api::logical HasReplacedPartURI( ) const;
	

	//! Get PartNumber of this PartMovement
	plmxml_api::String GetPartNumber() const;

	//! Set PartNumber of this PartMovement
	plmxml_api::Result SetPartNumber( const plmxml_api::String &s );
	
	//! Check if PartNumber is set
	plmxml_api::logical HasPartNumber( ) const;
	
	//! Unset PartNumber
	plmxml_api::Result UnsetPartNumber( );

	//! Set IsNew
	plmxml_api::Result SetIsNew( plmxml_api::logical arg );

	//! Get IsNew
	plmxml_api::logical GetIsNew() const;

	//! Check if IsNew is set
	plmxml_api::logical HasIsNew() const;

	//! Unset IsNew
	plmxml_api::Result UnsetIsNew();

	//! Get SerialNumber of this PartMovement
	plmxml_api::String GetSerialNumber() const;

	//! Set SerialNumber of this PartMovement
	plmxml_api::Result SetSerialNumber( const plmxml_api::String &s );
	
	//! Check if SerialNumber is set
	plmxml_api::logical HasSerialNumber( ) const;
	
	//! Unset SerialNumber
	plmxml_api::Result UnsetSerialNumber( );

	//! Get LotNumber of this PartMovement
	plmxml_api::String GetLotNumber() const;

	//! Set LotNumber of this PartMovement
	plmxml_api::Result SetLotNumber( const plmxml_api::String &s );
	
	//! Check if LotNumber is set
	plmxml_api::logical HasLotNumber( ) const;
	
	//! Unset LotNumber
	plmxml_api::Result UnsetLotNumber( );

	//! Get ManufacturerId of this PartMovement
	plmxml_api::String GetManufacturerId() const;

	//! Set ManufacturerId of this PartMovement
	plmxml_api::Result SetManufacturerId( const plmxml_api::String &s );
	
	//! Check if ManufacturerId is set
	plmxml_api::logical HasManufacturerId( ) const;
	
	//! Unset ManufacturerId
	plmxml_api::Result UnsetManufacturerId( );

	//! Get ParentPhysicalElement URI as plmxml_api::String
	plmxml_api::String GetParentPhysicalElementURI() const;

	//! Set ParentPhysicalElement URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetParentPhysicalElementURI( const plmxml_api::String& );
	
	//! Get the handle of ParentPhysicalElement URI. Does not resolve the URI.
	plmxml_api::Result GetParentPhysicalElementURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ParentPhysicalElement URI. URI string is unchanged.
	plmxml_api::Result SetParentPhysicalElementURI( const plmxml_api::Handle& );
	
	//! Resolve ParentPhysicalElement URI and return an object (handle) it points to.
	plmxml_api::Result ResolveParentPhysicalElementURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ParentPhysicalElement URI. Clears URI string and handle.
	plmxml_api::Result DeleteParentPhysicalElementURI();
	
	//! Check if ParentPhysicalElement URI is set
	plmxml_api::logical HasParentPhysicalElementURI( ) const;
	

	//! Set IsExtraToDesign
	plmxml_api::Result SetIsExtraToDesign( plmxml_api::logical arg );

	//! Get IsExtraToDesign
	plmxml_api::logical GetIsExtraToDesign() const;

	//! Check if IsExtraToDesign is set
	plmxml_api::logical HasIsExtraToDesign() const;

	//! Unset IsExtraToDesign
	plmxml_api::Result UnsetIsExtraToDesign();

	//! Get ActionDate of this PartMovement
	plmxml_api::String GetActionDate() const;

	//! Set ActionDate of this PartMovement
	plmxml_api::Result SetActionDate( const plmxml_api::String &s );
	
	//! Check if ActionDate is set
	plmxml_api::logical HasActionDate( ) const;
	
	//! Unset ActionDate
	plmxml_api::Result UnsetActionDate( );

	//! Set IsApprovedDeviation
	plmxml_api::Result SetIsApprovedDeviation( plmxml_api::logical arg );

	//! Get IsApprovedDeviation
	plmxml_api::logical GetIsApprovedDeviation() const;

	//! Check if IsApprovedDeviation is set
	plmxml_api::logical HasIsApprovedDeviation() const;

	//! Unset IsApprovedDeviation
	plmxml_api::Result UnsetIsApprovedDeviation();

	//! Set PartMovementType
	plmxml_api::Result SetPartMovementType( const ePartMovementEnum& arg );

	//! Get PartMovementType
	ePartMovementEnum GetPartMovementType() const;

	//! Get NewPartClass of this PartMovement
	plmxml_api::String GetNewPartClass() const;

	//! Set NewPartClass of this PartMovement
	plmxml_api::Result SetNewPartClass( const plmxml_api::String &s );
	
	//! Check if NewPartClass is set
	plmxml_api::logical HasNewPartClass( ) const;
	
	//! Unset NewPartClass
	plmxml_api::Result UnsetNewPartClass( );

	//! Get MovedPart URI as plmxml_api::String
	plmxml_api::String GetMovedPartURI() const;

	//! Set MovedPart URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMovedPartURI( const plmxml_api::String& );
	
	//! Get the handle of MovedPart URI. Does not resolve the URI.
	plmxml_api::Result GetMovedPartURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of MovedPart URI. URI string is unchanged.
	plmxml_api::Result SetMovedPartURI( const plmxml_api::Handle& );
	
	//! Resolve MovedPart URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMovedPartURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset MovedPart URI. Clears URI string and handle.
	plmxml_api::Result DeleteMovedPartURI();
	
	//! Check if MovedPart URI is set
	plmxml_api::logical HasMovedPartURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderPartMovement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPartMovement;


////////////////////////////////////////////////////////////////////////////////////
//! FaultCode class
/*!
\verbatim

      Fault identification information.

      Attributes:

      name:             Inherited from AttribOwner. Workspace object name.
      description:      Inherited from AttribOwner. Workspace description.
      partRef:          References the part associated with the FaultCode.
      
\endverbatim
*/
class PLMXML_MRO60_API FaultCode : public AttribOwner
{
public:
     
    //! Default constructor
    FaultCode( );
     
    //! Constructs a FaultCode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FaultCode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FaultCode();

private:

	//! Assignment operator
	FaultCode& operator=( const FaultCode& iSrc );

	//! Copy constructor
	FaultCode( const FaultCode& original );
     
public:

	//! Get Part URI as plmxml_api::String
	plmxml_api::String GetPartURI() const;

	//! Set Part URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPartURI( const plmxml_api::String& );
	
	//! Get the handle of Part URI. Does not resolve the URI.
	plmxml_api::Result GetPartURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Part URI. URI string is unchanged.
	plmxml_api::Result SetPartURI( const plmxml_api::Handle& );
	
	//! Resolve Part URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePartURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Part URI. Clears URI string and handle.
	plmxml_api::Result DeletePartURI();
	
	//! Check if Part URI is set
	plmxml_api::logical HasPartURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderFaultCode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFaultCode;


////////////////////////////////////////////////////////////////////////////////////
//! ActivityCost class
/*!
\verbatim

      Service cost information.

      Attributes:

      name:             Inherited from AttribOwner. Workspace object name.
      description:      Inherited from AttribOwner. Workspace description.
      estimatedTotalCostRef: References a Money representing the estimated total
                        cost.
      actualTotalCostRef: References a Money representing the actual total cost.
      estimatedLaborHours: Estimated work hours.
      actualLaborHours: Actual work hours.
      estimatedLaborCostRef: References a Money representing the estimated work
                        cost.
      actualLaborCostRef: References a Money representing the actual work cost.
      estimatedMaterialCostRef: References a Money representing the estimated
                        supply cost.
      actualMaterialCostRef: References a Money representing the actual supply
                        cost.
      
\endverbatim
*/
class PLMXML_MRO60_API ActivityCost : public AttribOwner
{
public:
     
    //! Default constructor
    ActivityCost( );
     
    //! Constructs a ActivityCost with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ActivityCost( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ActivityCost();

private:

	//! Assignment operator
	ActivityCost& operator=( const ActivityCost& iSrc );

	//! Copy constructor
	ActivityCost( const ActivityCost& original );
     
public:

	//! Get ActualTotalCost URI as plmxml_api::String
	plmxml_api::String GetActualTotalCostURI() const;

	//! Set ActualTotalCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActualTotalCostURI( const plmxml_api::String& );
	
	//! Get the handle of ActualTotalCost URI. Does not resolve the URI.
	plmxml_api::Result GetActualTotalCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActualTotalCost URI. URI string is unchanged.
	plmxml_api::Result SetActualTotalCostURI( const plmxml_api::Handle& );
	
	//! Resolve ActualTotalCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActualTotalCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActualTotalCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteActualTotalCostURI();
	
	//! Check if ActualTotalCost URI is set
	plmxml_api::logical HasActualTotalCostURI( ) const;
	

	//! Get ActualMaterialCost URI as plmxml_api::String
	plmxml_api::String GetActualMaterialCostURI() const;

	//! Set ActualMaterialCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActualMaterialCostURI( const plmxml_api::String& );
	
	//! Get the handle of ActualMaterialCost URI. Does not resolve the URI.
	plmxml_api::Result GetActualMaterialCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActualMaterialCost URI. URI string is unchanged.
	plmxml_api::Result SetActualMaterialCostURI( const plmxml_api::Handle& );
	
	//! Resolve ActualMaterialCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActualMaterialCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActualMaterialCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteActualMaterialCostURI();
	
	//! Check if ActualMaterialCost URI is set
	plmxml_api::logical HasActualMaterialCostURI( ) const;
	

	//! Get EstimatedLaborCost URI as plmxml_api::String
	plmxml_api::String GetEstimatedLaborCostURI() const;

	//! Set EstimatedLaborCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEstimatedLaborCostURI( const plmxml_api::String& );
	
	//! Get the handle of EstimatedLaborCost URI. Does not resolve the URI.
	plmxml_api::Result GetEstimatedLaborCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of EstimatedLaborCost URI. URI string is unchanged.
	plmxml_api::Result SetEstimatedLaborCostURI( const plmxml_api::Handle& );
	
	//! Resolve EstimatedLaborCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEstimatedLaborCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset EstimatedLaborCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteEstimatedLaborCostURI();
	
	//! Check if EstimatedLaborCost URI is set
	plmxml_api::logical HasEstimatedLaborCostURI( ) const;
	

	//! Get EstimatedTotalCost URI as plmxml_api::String
	plmxml_api::String GetEstimatedTotalCostURI() const;

	//! Set EstimatedTotalCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEstimatedTotalCostURI( const plmxml_api::String& );
	
	//! Get the handle of EstimatedTotalCost URI. Does not resolve the URI.
	plmxml_api::Result GetEstimatedTotalCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of EstimatedTotalCost URI. URI string is unchanged.
	plmxml_api::Result SetEstimatedTotalCostURI( const plmxml_api::Handle& );
	
	//! Resolve EstimatedTotalCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEstimatedTotalCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset EstimatedTotalCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteEstimatedTotalCostURI();
	
	//! Check if EstimatedTotalCost URI is set
	plmxml_api::logical HasEstimatedTotalCostURI( ) const;
	

	//! Set EstimatedLaborHours
	plmxml_api::Result SetEstimatedLaborHours( double arg );

     //! Get EstimatedLaborHours
	double GetEstimatedLaborHours() const;

	//! Check if EstimatedLaborHours is set
	plmxml_api::logical HasEstimatedLaborHours() const;

	//! Unset EstimatedLaborHours
	plmxml_api::Result UnsetEstimatedLaborHours();

	//! Set ActualLaborHours
	plmxml_api::Result SetActualLaborHours( double arg );

     //! Get ActualLaborHours
	double GetActualLaborHours() const;

	//! Check if ActualLaborHours is set
	plmxml_api::logical HasActualLaborHours() const;

	//! Unset ActualLaborHours
	plmxml_api::Result UnsetActualLaborHours();

	//! Get EstimatedMaterialCost URI as plmxml_api::String
	plmxml_api::String GetEstimatedMaterialCostURI() const;

	//! Set EstimatedMaterialCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEstimatedMaterialCostURI( const plmxml_api::String& );
	
	//! Get the handle of EstimatedMaterialCost URI. Does not resolve the URI.
	plmxml_api::Result GetEstimatedMaterialCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of EstimatedMaterialCost URI. URI string is unchanged.
	plmxml_api::Result SetEstimatedMaterialCostURI( const plmxml_api::Handle& );
	
	//! Resolve EstimatedMaterialCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEstimatedMaterialCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset EstimatedMaterialCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteEstimatedMaterialCostURI();
	
	//! Check if EstimatedMaterialCost URI is set
	plmxml_api::logical HasEstimatedMaterialCostURI( ) const;
	

	//! Get ActualLaborCost URI as plmxml_api::String
	plmxml_api::String GetActualLaborCostURI() const;

	//! Set ActualLaborCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActualLaborCostURI( const plmxml_api::String& );
	
	//! Get the handle of ActualLaborCost URI. Does not resolve the URI.
	plmxml_api::Result GetActualLaborCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActualLaborCost URI. URI string is unchanged.
	plmxml_api::Result SetActualLaborCostURI( const plmxml_api::Handle& );
	
	//! Resolve ActualLaborCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActualLaborCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActualLaborCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteActualLaborCostURI();
	
	//! Check if ActualLaborCost URI is set
	plmxml_api::logical HasActualLaborCostURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderActivityCost" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassActivityCost;


////////////////////////////////////////////////////////////////////////////////////
//! ActivityEntryValue class
/*!
\verbatim

      Service data collection information.

      Attributes:

      name:             Inherited from AttribOwner. Workspace object name.
      description:      Inherited from AttribOwner. Workspace description.
      entryValueChar:   Characteristic value.
      entryValueDate:   Characteristic date. 
      isPropagate:      Is propagate on Activity Entry Value.
      
\endverbatim
*/
class PLMXML_MRO60_API ActivityEntryValue : public AttribOwner
{
public:
     
    //! Default constructor
    ActivityEntryValue( );
     
    //! Constructs a ActivityEntryValue with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ActivityEntryValue( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ActivityEntryValue();

private:

	//! Assignment operator
	ActivityEntryValue& operator=( const ActivityEntryValue& iSrc );

	//! Copy constructor
	ActivityEntryValue( const ActivityEntryValue& original );
     
public:

	//! Get EntryValueDate of this ActivityEntryValue
	plmxml_api::String GetEntryValueDate() const;

	//! Set EntryValueDate of this ActivityEntryValue
	plmxml_api::Result SetEntryValueDate( const plmxml_api::String &s );
	
	//! Check if EntryValueDate is set
	plmxml_api::logical HasEntryValueDate( ) const;
	
	//! Unset EntryValueDate
	plmxml_api::Result UnsetEntryValueDate( );

	//! Set EntryValueChar
	plmxml_api::Result SetEntryValueChar( double arg );

     //! Get EntryValueChar
	double GetEntryValueChar() const;

	//! Check if EntryValueChar is set
	plmxml_api::logical HasEntryValueChar() const;

	//! Unset EntryValueChar
	plmxml_api::Result UnsetEntryValueChar();

	//! Set IsPropagate
	plmxml_api::Result SetIsPropagate( plmxml_api::logical arg );

	//! Get IsPropagate
	plmxml_api::logical GetIsPropagate() const;

	//! Check if IsPropagate is set
	plmxml_api::logical HasIsPropagate() const;

	//! Unset IsPropagate
	plmxml_api::Result UnsetIsPropagate();
 
// <PLMXML_UserCode type="functionHeaderActivityEntryValue" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassActivityEntryValue;


////////////////////////////////////////////////////////////////////////////////////
//! WorkCard class
/*!
\verbatim

      A WorkCard defines how to accomplish a ServiceRequirement, holds
      information about the tasks, effort estimates and cost estimates,
      resources required to perform the tasks.

      Attributes:

      catalogueId:      Inherited from OperationType. Unique identifier of the
                        Work Card.
      rebase:           This is TRUE if the WorkCard represents the process of
                        upgrading a physical product to a new neutral
                        configuration standard.
      
\endverbatim
*/
class PLMXML_MRO60_API WorkCard : public Operation
{
public:
     
    //! Default constructor
    WorkCard( );
     
    //! Constructs a WorkCard with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkCard( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkCard();

private:

	//! Assignment operator
	WorkCard& operator=( const WorkCard& iSrc );

	//! Copy constructor
	WorkCard( const WorkCard& original );
     
public:

	//! Set Rebase
	plmxml_api::Result SetRebase( plmxml_api::logical arg );

	//! Get Rebase
	plmxml_api::logical GetRebase() const;

	//! Check if Rebase is set
	plmxml_api::logical HasRebase() const;

	//! Unset Rebase
	plmxml_api::Result UnsetRebase();
 
// <PLMXML_UserCode type="functionHeaderWorkCard" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassWorkCard;


////////////////////////////////////////////////////////////////////////////////////
//! WorkCardRevision class
/*!
\verbatim

      WorkCard Revision.

      Attributes:

      executionType:    Represents the type of assignment. It can take one of
                        these values: perform, signOff, other.
      upgradedConfigurationRef: References the StructureContext.
      characteristicDefinitionRefs: A list of references to the related
                        CharacteristicDefinitions.
      warningRefs:      A list of references to the warnings associated with the
                        WorkCardRevision.
      narrative:        Represents information about how to perform/carry out
                        the work.
      laborCostRef:     References Money to represent labor cost associated with
                        the Work Card.
      materialCostRef:  References Money to represent material cost associated
                        with Materials of the Work Card.
      
\endverbatim
*/
class PLMXML_MRO60_API WorkCardRevision : public OperationRevision
{
public:
     
    //! Default constructor
    WorkCardRevision( );
     
    //! Constructs a WorkCardRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkCardRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkCardRevision();

private:

	//! Assignment operator
	WorkCardRevision& operator=( const WorkCardRevision& iSrc );

	//! Copy constructor
	WorkCardRevision( const WorkCardRevision& original );
     
public:

	//! Get LaborCost URI as plmxml_api::String
	plmxml_api::String GetLaborCostURI() const;

	//! Set LaborCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetLaborCostURI( const plmxml_api::String& );
	
	//! Get the handle of LaborCost URI. Does not resolve the URI.
	plmxml_api::Result GetLaborCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of LaborCost URI. URI string is unchanged.
	plmxml_api::Result SetLaborCostURI( const plmxml_api::Handle& );
	
	//! Resolve LaborCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveLaborCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset LaborCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteLaborCostURI();
	
	//! Check if LaborCost URI is set
	plmxml_api::logical HasLaborCostURI( ) const;
	

	//! Get number of URIs in Warning
	int NumberOfWarningURIs() const;

	//! Get i'th URI in Warning
	plmxml_api::String GetWarningURI( int i ) const;

	//! Add a URI to Warning array. Call ResolveWarningURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddWarningURI( const plmxml_api::String& u );

	//! Set i'th URI in Warning array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetWarningURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Warning URI. Does not resolve the URI.
	plmxml_api::Result GetWarningURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Warning array.
	plmxml_api::Result AddWarningURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Warning array to point to 'handle'.
	plmxml_api::Result SetWarningURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Warning points to.
	plmxml_api::Result ResolveWarningURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Warning array.
	plmxml_api::Result DeleteWarningURI( int i );

	//! Remove all URIs from Warning array.
	plmxml_api::Result DeleteWarningURIs( );
	
	//! Check if Warning is set
	plmxml_api::logical HasWarningURIs( ) const;

	//! Get MaterialCost URI as plmxml_api::String
	plmxml_api::String GetMaterialCostURI() const;

	//! Set MaterialCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMaterialCostURI( const plmxml_api::String& );
	
	//! Get the handle of MaterialCost URI. Does not resolve the URI.
	plmxml_api::Result GetMaterialCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of MaterialCost URI. URI string is unchanged.
	plmxml_api::Result SetMaterialCostURI( const plmxml_api::Handle& );
	
	//! Resolve MaterialCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMaterialCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset MaterialCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteMaterialCostURI();
	
	//! Check if MaterialCost URI is set
	plmxml_api::logical HasMaterialCostURI( ) const;
	

	//! Get UpgradedConfiguration URI as plmxml_api::String
	plmxml_api::String GetUpgradedConfigurationURI() const;

	//! Set UpgradedConfiguration URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUpgradedConfigurationURI( const plmxml_api::String& );
	
	//! Get the handle of UpgradedConfiguration URI. Does not resolve the URI.
	plmxml_api::Result GetUpgradedConfigurationURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of UpgradedConfiguration URI. URI string is unchanged.
	plmxml_api::Result SetUpgradedConfigurationURI( const plmxml_api::Handle& );
	
	//! Resolve UpgradedConfiguration URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUpgradedConfigurationURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset UpgradedConfiguration URI. Clears URI string and handle.
	plmxml_api::Result DeleteUpgradedConfigurationURI();
	
	//! Check if UpgradedConfiguration URI is set
	plmxml_api::logical HasUpgradedConfigurationURI( ) const;
	

	//! Get Narrative of this WorkCardRevision
	plmxml_api::String GetNarrative() const;

	//! Set Narrative of this WorkCardRevision
	plmxml_api::Result SetNarrative( const plmxml_api::String &s );
	
	//! Check if Narrative is set
	plmxml_api::logical HasNarrative( ) const;
	
	//! Unset Narrative
	plmxml_api::Result UnsetNarrative( );

	//! Set ExecutionType
	plmxml_api::Result SetExecutionType( const eExecutionEnum& arg );

	//! Get ExecutionType
	eExecutionEnum GetExecutionType() const;

	//! Get number of URIs in CharacteristicDefinition
	int NumberOfCharacteristicDefinitionURIs() const;

	//! Get i'th URI in CharacteristicDefinition
	plmxml_api::String GetCharacteristicDefinitionURI( int i ) const;

	//! Add a URI to CharacteristicDefinition array. Call ResolveCharacteristicDefinitionURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCharacteristicDefinitionURI( const plmxml_api::String& u );

	//! Set i'th URI in CharacteristicDefinition array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCharacteristicDefinitionURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of CharacteristicDefinition URI. Does not resolve the URI.
	plmxml_api::Result GetCharacteristicDefinitionURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to CharacteristicDefinition array.
	plmxml_api::Result AddCharacteristicDefinitionURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in CharacteristicDefinition array to point to 'handle'.
	plmxml_api::Result SetCharacteristicDefinitionURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in CharacteristicDefinition points to.
	plmxml_api::Result ResolveCharacteristicDefinitionURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from CharacteristicDefinition array.
	plmxml_api::Result DeleteCharacteristicDefinitionURI( int i );

	//! Remove all URIs from CharacteristicDefinition array.
	plmxml_api::Result DeleteCharacteristicDefinitionURIs( );
	
	//! Check if CharacteristicDefinition is set
	plmxml_api::logical HasCharacteristicDefinitionURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderWorkCardRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassWorkCardRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceRequirementCategory class
/*!
\verbatim

      Specifies the category and sub category of the ServiceRequirement.

      Attributes:

      name:             Inherited from AttribOwner. Used to specify the
                        ServiceRequirement sub category. It is required in this
                        context.
      type:             The ServiceRequirement category. It can take one of
                        these values: overhaul, repair, inspection, other.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceRequirementCategory : public AttribOwner
{
public:
     
    //! Default constructor
    ServiceRequirementCategory( );
     
    //! Constructs a ServiceRequirementCategory with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceRequirementCategory( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceRequirementCategory();

private:

	//! Assignment operator
	ServiceRequirementCategory& operator=( const ServiceRequirementCategory& iSrc );

	//! Copy constructor
	ServiceRequirementCategory( const ServiceRequirementCategory& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eCategoryEnum& arg );

	//! Get Type
	eCategoryEnum GetType() const;
 
// <PLMXML_UserCode type="functionHeaderServiceRequirementCategory" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceRequirementCategory;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceRequirement class
/*!
\verbatim

      ServiceRequirement is a maintenance process.

      Attributes:

      catalogueId:      Inherited from ProcessType. Identifies the requirement.
      categoryRef:      References a service requirement category. Indicates the
                        type of the service requirement.
      upgradeRequirement: This is TRUE if the purpose of the WorkCard is to
                        upgrade a physical part from one configuration to
                        another. 
      satisfiesRefs:    A list of references to the satisfied service requirements.
      requiresRefs:     A list of references to the required service
                        requirements. It indicates that the required
                        ServiceRequirements must be done along with the one
                        under consideration.
      faultCodeRefs:    A list of references to the FaultCodes resolved by the
                        service requirement.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceRequirement : public Process
{
public:
     
    //! Default constructor
    ServiceRequirement( );
     
    //! Constructs a ServiceRequirement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceRequirement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceRequirement();

private:

	//! Assignment operator
	ServiceRequirement& operator=( const ServiceRequirement& iSrc );

	//! Copy constructor
	ServiceRequirement( const ServiceRequirement& original );
     
public:

	//! Set UpgradeRequirement
	plmxml_api::Result SetUpgradeRequirement( plmxml_api::logical arg );

	//! Get UpgradeRequirement
	plmxml_api::logical GetUpgradeRequirement() const;

	//! Check if UpgradeRequirement is set
	plmxml_api::logical HasUpgradeRequirement() const;

	//! Unset UpgradeRequirement
	plmxml_api::Result UnsetUpgradeRequirement();

	//! Get number of URIs in FaultCode
	int NumberOfFaultCodeURIs() const;

	//! Get i'th URI in FaultCode
	plmxml_api::String GetFaultCodeURI( int i ) const;

	//! Add a URI to FaultCode array. Call ResolveFaultCodeURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFaultCodeURI( const plmxml_api::String& u );

	//! Set i'th URI in FaultCode array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFaultCodeURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of FaultCode URI. Does not resolve the URI.
	plmxml_api::Result GetFaultCodeURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to FaultCode array.
	plmxml_api::Result AddFaultCodeURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in FaultCode array to point to 'handle'.
	plmxml_api::Result SetFaultCodeURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in FaultCode points to.
	plmxml_api::Result ResolveFaultCodeURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from FaultCode array.
	plmxml_api::Result DeleteFaultCodeURI( int i );

	//! Remove all URIs from FaultCode array.
	plmxml_api::Result DeleteFaultCodeURIs( );
	
	//! Check if FaultCode is set
	plmxml_api::logical HasFaultCodeURIs( ) const;

	//! Get Category URI as plmxml_api::String
	plmxml_api::String GetCategoryURI() const;

	//! Set Category URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCategoryURI( const plmxml_api::String& );
	
	//! Get the handle of Category URI. Does not resolve the URI.
	plmxml_api::Result GetCategoryURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Category URI. URI string is unchanged.
	plmxml_api::Result SetCategoryURI( const plmxml_api::Handle& );
	
	//! Resolve Category URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCategoryURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Category URI. Clears URI string and handle.
	plmxml_api::Result DeleteCategoryURI();
	
	//! Check if Category URI is set
	plmxml_api::logical HasCategoryURI( ) const;
	

	//! Get number of URIs in Satisfies
	int NumberOfSatisfiesURIs() const;

	//! Get i'th URI in Satisfies
	plmxml_api::String GetSatisfiesURI( int i ) const;

	//! Add a URI to Satisfies array. Call ResolveSatisfiesURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSatisfiesURI( const plmxml_api::String& u );

	//! Set i'th URI in Satisfies array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSatisfiesURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Satisfies URI. Does not resolve the URI.
	plmxml_api::Result GetSatisfiesURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Satisfies array.
	plmxml_api::Result AddSatisfiesURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Satisfies array to point to 'handle'.
	plmxml_api::Result SetSatisfiesURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Satisfies points to.
	plmxml_api::Result ResolveSatisfiesURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Satisfies array.
	plmxml_api::Result DeleteSatisfiesURI( int i );

	//! Remove all URIs from Satisfies array.
	plmxml_api::Result DeleteSatisfiesURIs( );
	
	//! Check if Satisfies is set
	plmxml_api::logical HasSatisfiesURIs( ) const;

	//! Get number of URIs in Requires
	int NumberOfRequiresURIs() const;

	//! Get i'th URI in Requires
	plmxml_api::String GetRequiresURI( int i ) const;

	//! Add a URI to Requires array. Call ResolveRequiresURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRequiresURI( const plmxml_api::String& u );

	//! Set i'th URI in Requires array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRequiresURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Requires URI. Does not resolve the URI.
	plmxml_api::Result GetRequiresURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Requires array.
	plmxml_api::Result AddRequiresURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Requires array to point to 'handle'.
	plmxml_api::Result SetRequiresURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Requires points to.
	plmxml_api::Result ResolveRequiresURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Requires array.
	plmxml_api::Result DeleteRequiresURI( int i );

	//! Remove all URIs from Requires array.
	plmxml_api::Result DeleteRequiresURIs( );
	
	//! Check if Requires is set
	plmxml_api::logical HasRequiresURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderServiceRequirement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceRequirement;


////////////////////////////////////////////////////////////////////////////////////
//! ServiceRequirementRevision class
/*!
\verbatim

      Service Requirement Revision.

      Attributes:

      scheduled:        This is TRUE if the service requirement is for preventative maintenance.
      
\endverbatim
*/
class PLMXML_MRO60_API ServiceRequirementRevision : public ProcessRevision
{
public:
     
    //! Default constructor
    ServiceRequirementRevision( );
     
    //! Constructs a ServiceRequirementRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServiceRequirementRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServiceRequirementRevision();

private:

	//! Assignment operator
	ServiceRequirementRevision& operator=( const ServiceRequirementRevision& iSrc );

	//! Copy constructor
	ServiceRequirementRevision( const ServiceRequirementRevision& original );
     
public:

	//! Set Scheduled
	plmxml_api::Result SetScheduled( plmxml_api::logical arg );

	//! Get Scheduled
	plmxml_api::logical GetScheduled() const;

	//! Check if Scheduled is set
	plmxml_api::logical HasScheduled() const;

	//! Unset Scheduled
	plmxml_api::Result UnsetScheduled();
 
// <PLMXML_UserCode type="functionHeaderServiceRequirementRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServiceRequirementRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ServicePlan class
/*!
\verbatim

      Service Plan is a container for service requirements.

      Attributes:

      partRef: References the part for the service plan.
      
\endverbatim
*/
class PLMXML_MRO60_API ServicePlan : public Structure
{
public:
     
    //! Default constructor
    ServicePlan( );
     
    //! Constructs a ServicePlan with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServicePlan( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServicePlan();

private:

	//! Assignment operator
	ServicePlan& operator=( const ServicePlan& iSrc );

	//! Copy constructor
	ServicePlan( const ServicePlan& original );
     
public:

	//! Get Part URI as plmxml_api::String
	plmxml_api::String GetPartURI() const;

	//! Set Part URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPartURI( const plmxml_api::String& );
	
	//! Get the handle of Part URI. Does not resolve the URI.
	plmxml_api::Result GetPartURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Part URI. URI string is unchanged.
	plmxml_api::Result SetPartURI( const plmxml_api::Handle& );
	
	//! Resolve Part URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePartURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Part URI. Clears URI string and handle.
	plmxml_api::Result DeletePartURI();
	
	//! Check if Part URI is set
	plmxml_api::logical HasPartURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderServicePlan" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServicePlan;


////////////////////////////////////////////////////////////////////////////////////
//! ServicePlanRevision class
/*!
\verbatim

      Service Plan Revision.

      Attributes:

      scheduledServiceRequirements: This is TRUE if the ServicePlan contains scheduled service requirements.
      
\endverbatim
*/
class PLMXML_MRO60_API ServicePlanRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ServicePlanRevision( );
     
    //! Constructs a ServicePlanRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ServicePlanRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ServicePlanRevision();

private:

	//! Assignment operator
	ServicePlanRevision& operator=( const ServicePlanRevision& iSrc );

	//! Copy constructor
	ServicePlanRevision( const ServicePlanRevision& original );
     
public:

	//! Set ScheduledServiceRequirements
	plmxml_api::Result SetScheduledServiceRequirements( plmxml_api::logical arg );

	//! Get ScheduledServiceRequirements
	plmxml_api::logical GetScheduledServiceRequirements() const;

	//! Check if ScheduledServiceRequirements is set
	plmxml_api::logical HasScheduledServiceRequirements() const;

	//! Unset ScheduledServiceRequirements
	plmxml_api::Result UnsetScheduledServiceRequirements();
 
// <PLMXML_UserCode type="functionHeaderServicePlanRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassServicePlanRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Frequency class
/*!
\verbatim

      A Frequency is an interval or period for executing maintenance. 
      
\endverbatim
*/
class PLMXML_MRO60_API Frequency : public Structure
{
public:
     
    //! Default constructor
    Frequency( );
     
    //! Constructs a Frequency with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Frequency( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Frequency();

private:

	//! Assignment operator
	Frequency& operator=( const Frequency& iSrc );

	//! Copy constructor
	Frequency( const Frequency& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFrequency" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFrequency;


////////////////////////////////////////////////////////////////////////////////////
//! FrequencyRevision class
/*!
\verbatim

      Frequency Revision.

      Attributes:

      frequency:        An expression for the definition of frequency.
      
\endverbatim
*/
class PLMXML_MRO60_API FrequencyRevision : public StructureRevision
{
public:
     
    //! Default constructor
    FrequencyRevision( );
     
    //! Constructs a FrequencyRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FrequencyRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FrequencyRevision();

private:

	//! Assignment operator
	FrequencyRevision& operator=( const FrequencyRevision& iSrc );

	//! Copy constructor
	FrequencyRevision( const FrequencyRevision& original );
     
public:

	//! Get Frequency of this FrequencyRevision
	plmxml_api::String GetFrequency() const;

	//! Set Frequency of this FrequencyRevision
	plmxml_api::Result SetFrequency( const plmxml_api::String &s );
	
	//! Check if Frequency is set
	plmxml_api::logical HasFrequency( ) const;
	
	//! Unset Frequency
	plmxml_api::Result UnsetFrequency( );
 
// <PLMXML_UserCode type="functionHeaderFrequencyRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassFrequencyRevision;


////////////////////////////////////////////////////////////////////////////////////
//! PartApplicabilityRelation class
/*!
\verbatim

      This relation is between a ServiceRequirementRevision and a Product. The
      references in the inherited relatedRefs attribute must be in that order.

      Attributes:

      startSerialNumber: The beginning of the applicable serial number range.
      endSerialNumber:  The end of the applicable serial number range.
      
\endverbatim
*/
class PLMXML_MRO60_API PartApplicabilityRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    PartApplicabilityRelation( );
     
    //! Constructs a PartApplicabilityRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PartApplicabilityRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PartApplicabilityRelation();

private:

	//! Assignment operator
	PartApplicabilityRelation& operator=( const PartApplicabilityRelation& iSrc );

	//! Copy constructor
	PartApplicabilityRelation( const PartApplicabilityRelation& original );
     
public:

	//! Get StartSerialNumber of this PartApplicabilityRelation
	plmxml_api::String GetStartSerialNumber() const;

	//! Set StartSerialNumber of this PartApplicabilityRelation
	plmxml_api::Result SetStartSerialNumber( const plmxml_api::String &s );
	
	//! Check if StartSerialNumber is set
	plmxml_api::logical HasStartSerialNumber( ) const;
	
	//! Unset StartSerialNumber
	plmxml_api::Result UnsetStartSerialNumber( );

	//! Get EndSerialNumber of this PartApplicabilityRelation
	plmxml_api::String GetEndSerialNumber() const;

	//! Set EndSerialNumber of this PartApplicabilityRelation
	plmxml_api::Result SetEndSerialNumber( const plmxml_api::String &s );
	
	//! Check if EndSerialNumber is set
	plmxml_api::logical HasEndSerialNumber( ) const;
	
	//! Unset EndSerialNumber
	plmxml_api::Result UnsetEndSerialNumber( );
 
// <PLMXML_UserCode type="functionHeaderPartApplicabilityRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassPartApplicabilityRelation;


////////////////////////////////////////////////////////////////////////////////////
//! Warning class
/*!
\verbatim

      Warning type information.

      Attributes:

      type:           Type of warning. It can take one of these values:
                      safety, hazardousMaterial, other.
      
\endverbatim
*/
class PLMXML_MRO60_API Warning : public AttribOwner
{
public:
     
    //! Default constructor
    Warning( );
     
    //! Constructs a Warning with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Warning( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Warning();

private:

	//! Assignment operator
	Warning& operator=( const Warning& iSrc );

	//! Copy constructor
	Warning( const Warning& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eWarningEnum& arg );

	//! Get Type
	eWarningEnum GetType() const;
 
// <PLMXML_UserCode type="functionHeaderWarning" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassWarning;


////////////////////////////////////////////////////////////////////////////////////
//! MROActivity class
/*!
\verbatim

      An Activity is a component of an OperationRevision. An OperationRevision
      contains a tree of Activities.

      Attributes:

      executionType:    Represents the type of assignment. It can take one of
                        these values: perform, signOff, other.
      warningRefs:      A list of references to the warnings associated with the
                        Activity.
      characteristicDefinitionRefs: A list of references to the related
                        CharacteristicDefinitions.
      
\endverbatim
*/
class PLMXML_MRO60_API MROActivity : public Activity
{
public:
     
    //! Default constructor
    MROActivity( );
     
    //! Constructs a MROActivity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MROActivity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MROActivity();

private:

	//! Assignment operator
	MROActivity& operator=( const MROActivity& iSrc );

	//! Copy constructor
	MROActivity( const MROActivity& original );
     
public:

	//! Set ExecutionType
	plmxml_api::Result SetExecutionType( const eExecutionEnum& arg );

	//! Get ExecutionType
	eExecutionEnum GetExecutionType() const;

	//! Get number of URIs in Warning
	int NumberOfWarningURIs() const;

	//! Get i'th URI in Warning
	plmxml_api::String GetWarningURI( int i ) const;

	//! Add a URI to Warning array. Call ResolveWarningURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddWarningURI( const plmxml_api::String& u );

	//! Set i'th URI in Warning array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetWarningURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Warning URI. Does not resolve the URI.
	plmxml_api::Result GetWarningURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Warning array.
	plmxml_api::Result AddWarningURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Warning array to point to 'handle'.
	plmxml_api::Result SetWarningURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Warning points to.
	plmxml_api::Result ResolveWarningURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Warning array.
	plmxml_api::Result DeleteWarningURI( int i );

	//! Remove all URIs from Warning array.
	plmxml_api::Result DeleteWarningURIs( );
	
	//! Check if Warning is set
	plmxml_api::logical HasWarningURIs( ) const;

	//! Get number of URIs in CharacteristicDefinition
	int NumberOfCharacteristicDefinitionURIs() const;

	//! Get i'th URI in CharacteristicDefinition
	plmxml_api::String GetCharacteristicDefinitionURI( int i ) const;

	//! Add a URI to CharacteristicDefinition array. Call ResolveCharacteristicDefinitionURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCharacteristicDefinitionURI( const plmxml_api::String& u );

	//! Set i'th URI in CharacteristicDefinition array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCharacteristicDefinitionURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of CharacteristicDefinition URI. Does not resolve the URI.
	plmxml_api::Result GetCharacteristicDefinitionURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to CharacteristicDefinition array.
	plmxml_api::Result AddCharacteristicDefinitionURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in CharacteristicDefinition array to point to 'handle'.
	plmxml_api::Result SetCharacteristicDefinitionURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in CharacteristicDefinition points to.
	plmxml_api::Result ResolveCharacteristicDefinitionURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from CharacteristicDefinition array.
	plmxml_api::Result DeleteCharacteristicDefinitionURI( int i );

	//! Remove all URIs from CharacteristicDefinition array.
	plmxml_api::Result DeleteCharacteristicDefinitionURIs( );
	
	//! Check if CharacteristicDefinition is set
	plmxml_api::logical HasCharacteristicDefinitionURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderMROActivity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MRO60_API plmxml_api::plmxmlClass plmxmlClassMROActivity;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
