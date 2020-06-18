/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 11/09/2018 15:13:09
// 
// Schema:	PLMXMLPDMSchema.xsd
// Data:	11/09/2018 15:13:03
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_PDM60_H__
#define __PLMXML_PDM60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_PDM60_EXPORTS
#define PLMXML_PDM60_API __declspec(dllexport)
#else
#define PLMXML_PDM60_API __declspec(dllimport)
#endif
#else
#define PLMXML_PDM60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


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
//! eStatusConfigType class
/*!
Allowed Values:
\verbatim
  eStatusConfigTypeReleasedDate
	"releasedDate"
  eStatusConfigTypeSerialNumber
	"serialNumber"
  eStatusConfigTypeEffectiveDate
	"effectiveDate"
  
\endverbatim
*/
class PLMXML_PDM60_API eStatusConfigType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eStatusConfigType( const char* Type );
     
	//! Constructor
	eStatusConfigType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eStatusConfigType( );
     
	//! Destructor 
	virtual ~eStatusConfigType( );
     
	//! Assign from 'Type'
	const eStatusConfigType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eStatusConfigType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare StatusConfigType
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eStatusConfigType& e1, const eStatusConfigType& e2 );
     
	//! Compare StatusConfigType
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eStatusConfigType& e1, const eStatusConfigType& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumStatusConfigType;
extern PLMXML_PDM60_API eStatusConfigType eStatusConfigTypeUnset;
extern PLMXML_PDM60_API eStatusConfigType eStatusConfigTypeReleasedDate;
extern PLMXML_PDM60_API eStatusConfigType eStatusConfigTypeSerialNumber;
extern PLMXML_PDM60_API eStatusConfigType eStatusConfigTypeEffectiveDate;

////////////////////////////////////////////////////////////////////////////////////
//! eIncChangeEnum class
/*!
Allowed Values:
\verbatim
  eIncChangeEnumDelete
	"delete"
  eIncChangeEnumAdd
	"add"
  
\endverbatim
*/
class PLMXML_PDM60_API eIncChangeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eIncChangeEnum( const char* Type );
     
	//! Constructor
	eIncChangeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eIncChangeEnum( );
     
	//! Destructor 
	virtual ~eIncChangeEnum( );
     
	//! Assign from 'Type'
	const eIncChangeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eIncChangeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare IncChangeEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eIncChangeEnum& e1, const eIncChangeEnum& e2 );
     
	//! Compare IncChangeEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eIncChangeEnum& e1, const eIncChangeEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumIncChangeEnum;
extern PLMXML_PDM60_API eIncChangeEnum eIncChangeEnumUnset;
extern PLMXML_PDM60_API eIncChangeEnum eIncChangeEnumDelete;
extern PLMXML_PDM60_API eIncChangeEnum eIncChangeEnumAdd;

////////////////////////////////////////////////////////////////////////////////////
//! eClosureRuleScopeType class
/*!
Allowed Values:
\verbatim
  eClosureRuleScopeTypeTCENG
	"TCENG"
  eClosureRuleScopeTypeApplication
	"application"
  eClosureRuleScopeTypePLMXML
	"PLMXML"
  
\endverbatim
*/
class PLMXML_PDM60_API eClosureRuleScopeType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eClosureRuleScopeType( const char* Type );
     
	//! Constructor
	eClosureRuleScopeType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eClosureRuleScopeType( );
     
	//! Destructor 
	virtual ~eClosureRuleScopeType( );
     
	//! Assign from 'Type'
	const eClosureRuleScopeType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eClosureRuleScopeType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ClosureRuleScopeType
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eClosureRuleScopeType& e1, const eClosureRuleScopeType& e2 );
     
	//! Compare ClosureRuleScopeType
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eClosureRuleScopeType& e1, const eClosureRuleScopeType& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumClosureRuleScopeType;
extern PLMXML_PDM60_API eClosureRuleScopeType eClosureRuleScopeTypeUnset;
extern PLMXML_PDM60_API eClosureRuleScopeType eClosureRuleScopeTypeTCENG;
extern PLMXML_PDM60_API eClosureRuleScopeType eClosureRuleScopeTypeApplication;
extern PLMXML_PDM60_API eClosureRuleScopeType eClosureRuleScopeTypePLMXML;

////////////////////////////////////////////////////////////////////////////////////
//! eMachineTypesType class
/*!
Allowed Values:
\verbatim
  eMachineTypesTypeWnt
	"wnt"
  eMachineTypesTypeUnix
	"unix"
  eMachineTypesTypeVms
	"vms"
  
\endverbatim
*/
class PLMXML_PDM60_API eMachineTypesType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eMachineTypesType( const char* Type );
     
	//! Constructor
	eMachineTypesType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eMachineTypesType( );
     
	//! Destructor 
	virtual ~eMachineTypesType( );
     
	//! Assign from 'Type'
	const eMachineTypesType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eMachineTypesType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare MachineTypesType
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eMachineTypesType& e1, const eMachineTypesType& e2 );
     
	//! Compare MachineTypesType
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eMachineTypesType& e1, const eMachineTypesType& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumMachineTypesType;
extern PLMXML_PDM60_API eMachineTypesType eMachineTypesTypeUnset;
extern PLMXML_PDM60_API eMachineTypesType eMachineTypesTypeWnt;
extern PLMXML_PDM60_API eMachineTypesType eMachineTypesTypeUnix;
extern PLMXML_PDM60_API eMachineTypesType eMachineTypesTypeVms;

////////////////////////////////////////////////////////////////////////////////////
//! eDiagramToolEnum class
/*!
Allowed Values:
\verbatim
  eDiagramToolEnumVisio
	"visio"
  
\endverbatim
*/
class PLMXML_PDM60_API eDiagramToolEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDiagramToolEnum( const char* Type );
     
	//! Constructor
	eDiagramToolEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDiagramToolEnum( );
     
	//! Destructor 
	virtual ~eDiagramToolEnum( );
     
	//! Assign from 'Type'
	const eDiagramToolEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDiagramToolEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DiagramToolEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eDiagramToolEnum& e1, const eDiagramToolEnum& e2 );
     
	//! Compare DiagramToolEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eDiagramToolEnum& e1, const eDiagramToolEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDiagramToolEnum;
extern PLMXML_PDM60_API eDiagramToolEnum eDiagramToolEnumUnset;
extern PLMXML_PDM60_API eDiagramToolEnum eDiagramToolEnumVisio;

////////////////////////////////////////////////////////////////////////////////////
//! eShapeMembershipEnum class
/*!
Allowed Values:
\verbatim
  eShapeMembershipEnumUserAdded
	"userAdded"
  eShapeMembershipEnumRule
	"rule"
  
\endverbatim
*/
class PLMXML_PDM60_API eShapeMembershipEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eShapeMembershipEnum( const char* Type );
     
	//! Constructor
	eShapeMembershipEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eShapeMembershipEnum( );
     
	//! Destructor 
	virtual ~eShapeMembershipEnum( );
     
	//! Assign from 'Type'
	const eShapeMembershipEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eShapeMembershipEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ShapeMembershipEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eShapeMembershipEnum& e1, const eShapeMembershipEnum& e2 );
     
	//! Compare ShapeMembershipEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eShapeMembershipEnum& e1, const eShapeMembershipEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumShapeMembershipEnum;
extern PLMXML_PDM60_API eShapeMembershipEnum eShapeMembershipEnumUnset;
extern PLMXML_PDM60_API eShapeMembershipEnum eShapeMembershipEnumUserAdded;
extern PLMXML_PDM60_API eShapeMembershipEnum eShapeMembershipEnumRule;

////////////////////////////////////////////////////////////////////////////////////
//! eSignoffRequiredEnum class
/*!
Allowed Values:
\verbatim
  eSignoffRequiredEnumRequiredUnmodifiable
	"requiredUnmodifiable"
  eSignoffRequiredEnumOptional
	"optional"
  eSignoffRequiredEnumRequiredModifiable
	"requiredModifiable"
  
\endverbatim
*/
class PLMXML_PDM60_API eSignoffRequiredEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSignoffRequiredEnum( const char* Type );
     
	//! Constructor
	eSignoffRequiredEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSignoffRequiredEnum( );
     
	//! Destructor 
	virtual ~eSignoffRequiredEnum( );
     
	//! Assign from 'Type'
	const eSignoffRequiredEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSignoffRequiredEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SignoffRequiredEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eSignoffRequiredEnum& e1, const eSignoffRequiredEnum& e2 );
     
	//! Compare SignoffRequiredEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eSignoffRequiredEnum& e1, const eSignoffRequiredEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSignoffRequiredEnum;
extern PLMXML_PDM60_API eSignoffRequiredEnum eSignoffRequiredEnumUnset;
extern PLMXML_PDM60_API eSignoffRequiredEnum eSignoffRequiredEnumRequiredUnmodifiable;
extern PLMXML_PDM60_API eSignoffRequiredEnum eSignoffRequiredEnumOptional;
extern PLMXML_PDM60_API eSignoffRequiredEnum eSignoffRequiredEnumRequiredModifiable;

////////////////////////////////////////////////////////////////////////////////////
//! eOverrideEnum class
/*!
Allowed Values:
\verbatim
  eOverrideEnumNoOverride
	"noOverride"
  eOverrideEnumTemporary
	"temporary"
  eOverrideEnumPermanent
	"permanent"
  
\endverbatim
*/
class PLMXML_PDM60_API eOverrideEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eOverrideEnum( const char* Type );
     
	//! Constructor
	eOverrideEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eOverrideEnum( );
     
	//! Destructor 
	virtual ~eOverrideEnum( );
     
	//! Assign from 'Type'
	const eOverrideEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eOverrideEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare OverrideEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eOverrideEnum& e1, const eOverrideEnum& e2 );
     
	//! Compare OverrideEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eOverrideEnum& e1, const eOverrideEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumOverrideEnum;
extern PLMXML_PDM60_API eOverrideEnum eOverrideEnumUnset;
extern PLMXML_PDM60_API eOverrideEnum eOverrideEnumNoOverride;
extern PLMXML_PDM60_API eOverrideEnum eOverrideEnumTemporary;
extern PLMXML_PDM60_API eOverrideEnum eOverrideEnumPermanent;

////////////////////////////////////////////////////////////////////////////////////
//! eWorkflowTemplateClassificationEnum class
/*!
Allowed Values:
\verbatim
  eWorkflowTemplateClassificationEnumProcess
	"process"
  eWorkflowTemplateClassificationEnumTask
	"task"
  
\endverbatim
*/
class PLMXML_PDM60_API eWorkflowTemplateClassificationEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWorkflowTemplateClassificationEnum( const char* Type );
     
	//! Constructor
	eWorkflowTemplateClassificationEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWorkflowTemplateClassificationEnum( );
     
	//! Destructor 
	virtual ~eWorkflowTemplateClassificationEnum( );
     
	//! Assign from 'Type'
	const eWorkflowTemplateClassificationEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWorkflowTemplateClassificationEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WorkflowTemplateClassificationEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eWorkflowTemplateClassificationEnum& e1, const eWorkflowTemplateClassificationEnum& e2 );
     
	//! Compare WorkflowTemplateClassificationEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eWorkflowTemplateClassificationEnum& e1, const eWorkflowTemplateClassificationEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWorkflowTemplateClassificationEnum;
extern PLMXML_PDM60_API eWorkflowTemplateClassificationEnum eWorkflowTemplateClassificationEnumUnset;
extern PLMXML_PDM60_API eWorkflowTemplateClassificationEnum eWorkflowTemplateClassificationEnumProcess;
extern PLMXML_PDM60_API eWorkflowTemplateClassificationEnum eWorkflowTemplateClassificationEnumTask;

////////////////////////////////////////////////////////////////////////////////////
//! eWorkflowTemplateStageEnum class
/*!
Allowed Values:
\verbatim
  eWorkflowTemplateStageEnumDeveloping
	"developing"
  eWorkflowTemplateStageEnumObsolete
	"obsolete"
  eWorkflowTemplateStageEnumAvailable
	"available"
  
\endverbatim
*/
class PLMXML_PDM60_API eWorkflowTemplateStageEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWorkflowTemplateStageEnum( const char* Type );
     
	//! Constructor
	eWorkflowTemplateStageEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWorkflowTemplateStageEnum( );
     
	//! Destructor 
	virtual ~eWorkflowTemplateStageEnum( );
     
	//! Assign from 'Type'
	const eWorkflowTemplateStageEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWorkflowTemplateStageEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WorkflowTemplateStageEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eWorkflowTemplateStageEnum& e1, const eWorkflowTemplateStageEnum& e2 );
     
	//! Compare WorkflowTemplateStageEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eWorkflowTemplateStageEnum& e1, const eWorkflowTemplateStageEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWorkflowTemplateStageEnum;
extern PLMXML_PDM60_API eWorkflowTemplateStageEnum eWorkflowTemplateStageEnumUnset;
extern PLMXML_PDM60_API eWorkflowTemplateStageEnum eWorkflowTemplateStageEnumDeveloping;
extern PLMXML_PDM60_API eWorkflowTemplateStageEnum eWorkflowTemplateStageEnumObsolete;
extern PLMXML_PDM60_API eWorkflowTemplateStageEnum eWorkflowTemplateStageEnumAvailable;

////////////////////////////////////////////////////////////////////////////////////
//! eResourceListActionEnum class
/*!
Allowed Values:
\verbatim
  eResourceListActionEnumReviewRequired
	"reviewRequired"
  eResourceListActionEnumAcknowledge
	"acknowledge"
  eResourceListActionEnumAcknowledgeRequired
	"acknowledgeRequired"
  eResourceListActionEnumReview
	"review"
  eResourceListActionEnumPerform
	"perform"
  eResourceListActionEnumNotify
	"notify"
  
\endverbatim
*/
class PLMXML_PDM60_API eResourceListActionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eResourceListActionEnum( const char* Type );
     
	//! Constructor
	eResourceListActionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eResourceListActionEnum( );
     
	//! Destructor 
	virtual ~eResourceListActionEnum( );
     
	//! Assign from 'Type'
	const eResourceListActionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eResourceListActionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ResourceListActionEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eResourceListActionEnum& e1, const eResourceListActionEnum& e2 );
     
	//! Compare ResourceListActionEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eResourceListActionEnum& e1, const eResourceListActionEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumResourceListActionEnum;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumUnset;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumReviewRequired;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumAcknowledge;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumAcknowledgeRequired;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumReview;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumPerform;
extern PLMXML_PDM60_API eResourceListActionEnum eResourceListActionEnumNotify;

////////////////////////////////////////////////////////////////////////////////////
//! eTaskStateType class
/*!
Allowed Values:
\verbatim
  eTaskStateTypePending
	"pending"
  eTaskStateTypeUnassigned
	"unassigned"
  eTaskStateTypeStarted
	"started"
  eTaskStateTypeSuspended
	"suspended"
  eTaskStateTypeSkipped
	"skipped"
  eTaskStateTypeAborted
	"aborted"
  eTaskStateTypeCompleted
	"completed"
  eTaskStateTypeFailed
	"failed"
  
\endverbatim
*/
class PLMXML_PDM60_API eTaskStateType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTaskStateType( const char* Type );
     
	//! Constructor
	eTaskStateType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTaskStateType( );
     
	//! Destructor 
	virtual ~eTaskStateType( );
     
	//! Assign from 'Type'
	const eTaskStateType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTaskStateType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TaskStateType
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eTaskStateType& e1, const eTaskStateType& e2 );
     
	//! Compare TaskStateType
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eTaskStateType& e1, const eTaskStateType& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTaskStateType;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeUnset;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypePending;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeUnassigned;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeStarted;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeSuspended;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeSkipped;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeAborted;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeCompleted;
extern PLMXML_PDM60_API eTaskStateType eTaskStateTypeFailed;

////////////////////////////////////////////////////////////////////////////////////
//! eGroupTypeEnum class
/*!
Allowed Values:
\verbatim
  eGroupTypeEnumStructure
	"structure"
  eGroupTypeEnumOccurrence
	"occurrence"
  
\endverbatim
*/
class PLMXML_PDM60_API eGroupTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eGroupTypeEnum( const char* Type );
     
	//! Constructor
	eGroupTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eGroupTypeEnum( );
     
	//! Destructor 
	virtual ~eGroupTypeEnum( );
     
	//! Assign from 'Type'
	const eGroupTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eGroupTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare GroupTypeEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eGroupTypeEnum& e1, const eGroupTypeEnum& e2 );
     
	//! Compare GroupTypeEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eGroupTypeEnum& e1, const eGroupTypeEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumGroupTypeEnum;
extern PLMXML_PDM60_API eGroupTypeEnum eGroupTypeEnumUnset;
extern PLMXML_PDM60_API eGroupTypeEnum eGroupTypeEnumStructure;
extern PLMXML_PDM60_API eGroupTypeEnum eGroupTypeEnumOccurrence;

////////////////////////////////////////////////////////////////////////////////////
//! eIssueReviewDecisionEnum class
/*!
Allowed Values:
\verbatim
  eIssueReviewDecisionEnumAssign
	"assign"
  eIssueReviewDecisionEnumApproveFix
	"approveFix"
  eIssueReviewDecisionEnumDefer
	"defer"
  eIssueReviewDecisionEnumReopen
	"reopen"
  eIssueReviewDecisionEnumApproveIssue
	"approveIssue"
  eIssueReviewDecisionEnumReject
	"reject"
  eIssueReviewDecisionEnumNoDecision
	"noDecision"
  eIssueReviewDecisionEnumClose
	"close"
  
\endverbatim
*/
class PLMXML_PDM60_API eIssueReviewDecisionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eIssueReviewDecisionEnum( const char* Type );
     
	//! Constructor
	eIssueReviewDecisionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eIssueReviewDecisionEnum( );
     
	//! Destructor 
	virtual ~eIssueReviewDecisionEnum( );
     
	//! Assign from 'Type'
	const eIssueReviewDecisionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eIssueReviewDecisionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare IssueReviewDecisionEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eIssueReviewDecisionEnum& e1, const eIssueReviewDecisionEnum& e2 );
     
	//! Compare IssueReviewDecisionEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eIssueReviewDecisionEnum& e1, const eIssueReviewDecisionEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumIssueReviewDecisionEnum;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumUnset;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumAssign;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumApproveFix;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumDefer;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumReopen;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumApproveIssue;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumReject;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumNoDecision;
extern PLMXML_PDM60_API eIssueReviewDecisionEnum eIssueReviewDecisionEnumClose;

////////////////////////////////////////////////////////////////////////////////////
//! eRevisionConfigType class
/*!
Allowed Values:
\verbatim
  eRevisionConfigTypeNumericRevID
	"numericRevID"
  eRevisionConfigTypeAlphaNumericRevID
	"alphaNumericRevID"
  eRevisionConfigTypeCreationDate
	"creationDate"
  
\endverbatim
*/
class PLMXML_PDM60_API eRevisionConfigType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRevisionConfigType( const char* Type );
     
	//! Constructor
	eRevisionConfigType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRevisionConfigType( );
     
	//! Destructor 
	virtual ~eRevisionConfigType( );
     
	//! Assign from 'Type'
	const eRevisionConfigType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRevisionConfigType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RevisionConfigType
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eRevisionConfigType& e1, const eRevisionConfigType& e2 );
     
	//! Compare RevisionConfigType
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eRevisionConfigType& e1, const eRevisionConfigType& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRevisionConfigType;
extern PLMXML_PDM60_API eRevisionConfigType eRevisionConfigTypeUnset;
extern PLMXML_PDM60_API eRevisionConfigType eRevisionConfigTypeNumericRevID;
extern PLMXML_PDM60_API eRevisionConfigType eRevisionConfigTypeAlphaNumericRevID;
extern PLMXML_PDM60_API eRevisionConfigType eRevisionConfigTypeCreationDate;

////////////////////////////////////////////////////////////////////////////////////
//! eParticipantEnum class
/*!
Allowed Values:
\verbatim
  eParticipantEnumChangeAdministrator3
	"changeAdministrator3"
  eParticipantEnumProposedReviewer
	"proposedReviewer"
  eParticipantEnumChangeImplementationBoard
	"changeImplementationBoard"
  eParticipantEnumChangeAdministrator2
	"changeAdministrator2"
  eParticipantEnumUserDefined
	"userDefined"
  eParticipantEnumChangeAdministrator1
	"changeAdministrator1"
  eParticipantEnumProposedResponsibleParty
	"proposedResponsibleParty"
  eParticipantEnumChangeAnalyst
	"changeAnalyst"
  eParticipantEnumChangeRequestor
	"changeRequestor"
  eParticipantEnumChangeReviewBoard
	"changeReviewBoard"
  
\endverbatim
*/
class PLMXML_PDM60_API eParticipantEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eParticipantEnum( const char* Type );
     
	//! Constructor
	eParticipantEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eParticipantEnum( );
     
	//! Destructor 
	virtual ~eParticipantEnum( );
     
	//! Assign from 'Type'
	const eParticipantEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eParticipantEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ParticipantEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eParticipantEnum& e1, const eParticipantEnum& e2 );
     
	//! Compare ParticipantEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eParticipantEnum& e1, const eParticipantEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumParticipantEnum;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumUnset;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeAdministrator3;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumProposedReviewer;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeImplementationBoard;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeAdministrator2;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumUserDefined;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeAdministrator1;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumProposedResponsibleParty;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeAnalyst;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeRequestor;
extern PLMXML_PDM60_API eParticipantEnum eParticipantEnumChangeReviewBoard;

////////////////////////////////////////////////////////////////////////////////////
//! eDecisionType class
/*!
Allowed Values:
\verbatim
  eDecisionTypeApprove
	"approve"
  eDecisionTypeNoDecision
	"noDecision"
  eDecisionTypeReject
	"reject"
  
\endverbatim
*/
class PLMXML_PDM60_API eDecisionType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDecisionType( const char* Type );
     
	//! Constructor
	eDecisionType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDecisionType( );
     
	//! Destructor 
	virtual ~eDecisionType( );
     
	//! Assign from 'Type'
	const eDecisionType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDecisionType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DecisionType
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eDecisionType& e1, const eDecisionType& e2 );
     
	//! Compare DecisionType
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eDecisionType& e1, const eDecisionType& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDecisionType;
extern PLMXML_PDM60_API eDecisionType eDecisionTypeUnset;
extern PLMXML_PDM60_API eDecisionType eDecisionTypeApprove;
extern PLMXML_PDM60_API eDecisionType eDecisionTypeNoDecision;
extern PLMXML_PDM60_API eDecisionType eDecisionTypeReject;

////////////////////////////////////////////////////////////////////////////////////
//! eWorkflowTemplateUndecidedReviewersEnum class
/*!
Allowed Values:
\verbatim
  eWorkflowTemplateUndecidedReviewersEnumFalse
	"false"
  eWorkflowTemplateUndecidedReviewersEnumTrue
	"true"
  
\endverbatim
*/
class PLMXML_PDM60_API eWorkflowTemplateUndecidedReviewersEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWorkflowTemplateUndecidedReviewersEnum( const char* Type );
     
	//! Constructor
	eWorkflowTemplateUndecidedReviewersEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWorkflowTemplateUndecidedReviewersEnum( );
     
	//! Destructor 
	virtual ~eWorkflowTemplateUndecidedReviewersEnum( );
     
	//! Assign from 'Type'
	const eWorkflowTemplateUndecidedReviewersEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWorkflowTemplateUndecidedReviewersEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WorkflowTemplateUndecidedReviewersEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eWorkflowTemplateUndecidedReviewersEnum& e1, const eWorkflowTemplateUndecidedReviewersEnum& e2 );
     
	//! Compare WorkflowTemplateUndecidedReviewersEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eWorkflowTemplateUndecidedReviewersEnum& e1, const eWorkflowTemplateUndecidedReviewersEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWorkflowTemplateUndecidedReviewersEnum;
extern PLMXML_PDM60_API eWorkflowTemplateUndecidedReviewersEnum eWorkflowTemplateUndecidedReviewersEnumUnset;
extern PLMXML_PDM60_API eWorkflowTemplateUndecidedReviewersEnum eWorkflowTemplateUndecidedReviewersEnumFalse;
extern PLMXML_PDM60_API eWorkflowTemplateUndecidedReviewersEnum eWorkflowTemplateUndecidedReviewersEnumTrue;

////////////////////////////////////////////////////////////////////////////////////
//! eOverrideStateEnum class
/*!
Allowed Values:
\verbatim
  eOverrideStateEnumFail
	"fail"
  eOverrideStateEnumPass
	"pass"
  
\endverbatim
*/
class PLMXML_PDM60_API eOverrideStateEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eOverrideStateEnum( const char* Type );
     
	//! Constructor
	eOverrideStateEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eOverrideStateEnum( );
     
	//! Destructor 
	virtual ~eOverrideStateEnum( );
     
	//! Assign from 'Type'
	const eOverrideStateEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eOverrideStateEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare OverrideStateEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator==( const eOverrideStateEnum& e1, const eOverrideStateEnum& e2 );
     
	//! Compare OverrideStateEnum
	friend plmxml_api::logical PLMXML_PDM60_API operator!=( const eOverrideStateEnum& e1, const eOverrideStateEnum& e2 );
};
extern PLMXML_PDM60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumOverrideStateEnum;
extern PLMXML_PDM60_API eOverrideStateEnum eOverrideStateEnumUnset;
extern PLMXML_PDM60_API eOverrideStateEnum eOverrideStateEnumFail;
extern PLMXML_PDM60_API eOverrideStateEnum eOverrideStateEnumPass;

////////////////////////////////////////////////////////////////////////////////////
//! Signoff class
/*!
\verbatim

      Attributes:

      organisationMemberRef: References an OrganisationMember if the workflow
                        task is assigned to an organisation member.
      resourcePoolRef:  References a ResourcePool if the workflow task is
                        assigned to a resource pool.
      decision:         approve, noDecision or reject.
      decisionDate:     The date and time the decision was made.
      userRef:          References the actual signing off User.
      signoffRequired:  Whether the Signoff is optional or required. If it is
                        required by a workflow process, the user might or might
                        not be allowed to modify it to optional.
      activeSurrogateRef: References an OrganisationMember who can deputise for
                        the assignee.
      assignerRef:      References the User who does the assigning.

      Sub-elements:

      Attribute:        Any element derived from AttributeBase.
      
\endverbatim
*/
class PLMXML_PDM60_API Signoff : public DescriptionObject
{
public:
     
    //! Default constructor
    Signoff( );
     
    //! Constructs a Signoff with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Signoff( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Signoff();

private:

	//! Assignment operator
	Signoff& operator=( const Signoff& iSrc );

	//! Copy constructor
	Signoff( const Signoff& original );
     
public:

	//! Get User URI as plmxml_api::String
	plmxml_api::String GetUserURI() const;

	//! Set User URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::String& );
	
	//! Get the handle of User URI. Does not resolve the URI.
	plmxml_api::Result GetUserURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of User URI. URI string is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::Handle& );
	
	//! Resolve User URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUserURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset User URI. Clears URI string and handle.
	plmxml_api::Result DeleteUserURI();
	
	//! Check if User URI is set
	plmxml_api::logical HasUserURI( ) const;
	

	//! Set SignoffRequired
	plmxml_api::Result SetSignoffRequired( const eSignoffRequiredEnum& arg );

	//! Get SignoffRequired
	eSignoffRequiredEnum GetSignoffRequired() const;

	//! Get ActiveSurrogate URI as plmxml_api::String
	plmxml_api::String GetActiveSurrogateURI() const;

	//! Set ActiveSurrogate URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActiveSurrogateURI( const plmxml_api::String& );
	
	//! Get the handle of ActiveSurrogate URI. Does not resolve the URI.
	plmxml_api::Result GetActiveSurrogateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActiveSurrogate URI. URI string is unchanged.
	plmxml_api::Result SetActiveSurrogateURI( const plmxml_api::Handle& );
	
	//! Resolve ActiveSurrogate URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActiveSurrogateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActiveSurrogate URI. Clears URI string and handle.
	plmxml_api::Result DeleteActiveSurrogateURI();
	
	//! Check if ActiveSurrogate URI is set
	plmxml_api::logical HasActiveSurrogateURI( ) const;
	

	//! Get DecisionDate of this Signoff
	plmxml_api::String GetDecisionDate() const;

	//! Set DecisionDate of this Signoff
	plmxml_api::Result SetDecisionDate( const plmxml_api::String &s );
	
	//! Check if DecisionDate is set
	plmxml_api::logical HasDecisionDate( ) const;
	
	//! Unset DecisionDate
	plmxml_api::Result UnsetDecisionDate( );

	//! Get Assigner URI as plmxml_api::String
	plmxml_api::String GetAssignerURI() const;

	//! Set Assigner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAssignerURI( const plmxml_api::String& );
	
	//! Get the handle of Assigner URI. Does not resolve the URI.
	plmxml_api::Result GetAssignerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Assigner URI. URI string is unchanged.
	plmxml_api::Result SetAssignerURI( const plmxml_api::Handle& );
	
	//! Resolve Assigner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAssignerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Assigner URI. Clears URI string and handle.
	plmxml_api::Result DeleteAssignerURI();
	
	//! Check if Assigner URI is set
	plmxml_api::logical HasAssignerURI( ) const;
	

	//! Get OrganisationMember URI as plmxml_api::String
	plmxml_api::String GetOrganisationMemberURI() const;

	//! Set OrganisationMember URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOrganisationMemberURI( const plmxml_api::String& );
	
	//! Get the handle of OrganisationMember URI. Does not resolve the URI.
	plmxml_api::Result GetOrganisationMemberURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of OrganisationMember URI. URI string is unchanged.
	plmxml_api::Result SetOrganisationMemberURI( const plmxml_api::Handle& );
	
	//! Resolve OrganisationMember URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOrganisationMemberURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset OrganisationMember URI. Clears URI string and handle.
	plmxml_api::Result DeleteOrganisationMemberURI();
	
	//! Check if OrganisationMember URI is set
	plmxml_api::logical HasOrganisationMemberURI( ) const;
	

	//! Get ResourcePool URI as plmxml_api::String
	plmxml_api::String GetResourcePoolURI() const;

	//! Set ResourcePool URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetResourcePoolURI( const plmxml_api::String& );
	
	//! Get the handle of ResourcePool URI. Does not resolve the URI.
	plmxml_api::Result GetResourcePoolURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ResourcePool URI. URI string is unchanged.
	plmxml_api::Result SetResourcePoolURI( const plmxml_api::Handle& );
	
	//! Resolve ResourcePool URI and return an object (handle) it points to.
	plmxml_api::Result ResolveResourcePoolURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ResourcePool URI. Clears URI string and handle.
	plmxml_api::Result DeleteResourcePoolURI();
	
	//! Check if ResourcePool URI is set
	plmxml_api::logical HasResourcePoolURI( ) const;
	

	//! Set Decision
	plmxml_api::Result SetDecision( const eDecisionType& arg );

	//! Get Decision
	eDecisionType GetDecision() const;

	//! Add Attribute child element to this Signoff. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Attribute *AddAttribute();
     
	//! Add 'arg' as Attribute child element to this Signoff.
	plmxml_api::Result AddAttribute( Attribute *arg );

	//! Detach and delete all Attribute child elements.
	void DeleteAttributes();
     
	//! Get number of Attribute child elements.
	int NumberOfAttributes() const;
     
	//! Get i'th Attribute child element.
	Attribute *GetAttribute( int i ) const;
     
	//! Get all Attribute child element as an array
	void GetAttributes( plmxml_api::Array<Attribute*> &array ) const;
	     
	//! Detach and delete i'th Attribute child element
	void DeleteAttribute( int i );
     
	//! Detach and delete 'arg' if it's one of the Attribute child elements
	void DeleteAttribute( Attribute *arg );
 
// <PLMXML_UserCode type="functionHeaderSignoff" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassSignoff;


////////////////////////////////////////////////////////////////////////////////////
//! Task class
/*!
\verbatim

      Attributes:

      state:            The state of the workflow task.
      subTaskRefs:      References any dependent sub-tasks.
      targetRefs:       References the WorkflowProcess and the items that are
                        the subject of the workflow process.
      referenceRefs:    References the WorkflowProcess and any reference items.
      responsiblePartyRef: References the OrganisationMember, User or
                        ResourcePool to whom the workflow task is assigned.
      activeSurrogateRef: References an OrganisationMember or User who can
                        deputise for the responsible party.
      assignerRef:      References the User who does the assigning.
      userRef:          References the actual signing off User.

      Sub-elements:

      Signoff:          The signoff of the workflow task.
      ReleaseStatus:    The release status of the workflow task.
      
\endverbatim
*/
class PLMXML_PDM60_API Task : public AttribOwner
{
public:
     
    //! Default constructor
    Task( );
     
    //! Constructs a Task with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Task( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Task();

private:

	//! Assignment operator
	Task& operator=( const Task& iSrc );

	//! Copy constructor
	Task( const Task& original );
     
public:

	//! Get number of URIs in Reference
	int NumberOfReferenceURIs() const;

	//! Get i'th URI in Reference
	plmxml_api::String GetReferenceURI( int i ) const;

	//! Add a URI to Reference array. Call ResolveReferenceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddReferenceURI( const plmxml_api::String& u );

	//! Set i'th URI in Reference array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetReferenceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Reference URI. Does not resolve the URI.
	plmxml_api::Result GetReferenceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Reference array.
	plmxml_api::Result AddReferenceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Reference array to point to 'handle'.
	plmxml_api::Result SetReferenceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Reference points to.
	plmxml_api::Result ResolveReferenceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Reference array.
	plmxml_api::Result DeleteReferenceURI( int i );

	//! Remove all URIs from Reference array.
	plmxml_api::Result DeleteReferenceURIs( );
	
	//! Check if Reference is set
	plmxml_api::logical HasReferenceURIs( ) const;

	//! Set State
	plmxml_api::Result SetState( const eTaskStateType& arg );

	//! Get State
	eTaskStateType GetState() const;

	//! Get User URI as plmxml_api::String
	plmxml_api::String GetUserURI() const;

	//! Set User URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::String& );
	
	//! Get the handle of User URI. Does not resolve the URI.
	plmxml_api::Result GetUserURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of User URI. URI string is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::Handle& );
	
	//! Resolve User URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUserURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset User URI. Clears URI string and handle.
	plmxml_api::Result DeleteUserURI();
	
	//! Check if User URI is set
	plmxml_api::logical HasUserURI( ) const;
	

	//! Get number of URIs in Target
	int NumberOfTargetURIs() const;

	//! Get i'th URI in Target
	plmxml_api::String GetTargetURI( int i ) const;

	//! Add a URI to Target array. Call ResolveTargetURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTargetURI( const plmxml_api::String& u );

	//! Set i'th URI in Target array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTargetURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Target URI. Does not resolve the URI.
	plmxml_api::Result GetTargetURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Target array.
	plmxml_api::Result AddTargetURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Target array to point to 'handle'.
	plmxml_api::Result SetTargetURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Target points to.
	plmxml_api::Result ResolveTargetURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Target array.
	plmxml_api::Result DeleteTargetURI( int i );

	//! Remove all URIs from Target array.
	plmxml_api::Result DeleteTargetURIs( );
	
	//! Check if Target is set
	plmxml_api::logical HasTargetURIs( ) const;

	//! Get number of URIs in SubTask
	int NumberOfSubTaskURIs() const;

	//! Get i'th URI in SubTask
	plmxml_api::String GetSubTaskURI( int i ) const;

	//! Add a URI to SubTask array. Call ResolveSubTaskURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSubTaskURI( const plmxml_api::String& u );

	//! Set i'th URI in SubTask array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSubTaskURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SubTask URI. Does not resolve the URI.
	plmxml_api::Result GetSubTaskURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SubTask array.
	plmxml_api::Result AddSubTaskURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SubTask array to point to 'handle'.
	plmxml_api::Result SetSubTaskURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SubTask points to.
	plmxml_api::Result ResolveSubTaskURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SubTask array.
	plmxml_api::Result DeleteSubTaskURI( int i );

	//! Remove all URIs from SubTask array.
	plmxml_api::Result DeleteSubTaskURIs( );
	
	//! Check if SubTask is set
	plmxml_api::logical HasSubTaskURIs( ) const;

	//! Get Assigner URI as plmxml_api::String
	plmxml_api::String GetAssignerURI() const;

	//! Set Assigner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAssignerURI( const plmxml_api::String& );
	
	//! Get the handle of Assigner URI. Does not resolve the URI.
	plmxml_api::Result GetAssignerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Assigner URI. URI string is unchanged.
	plmxml_api::Result SetAssignerURI( const plmxml_api::Handle& );
	
	//! Resolve Assigner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAssignerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Assigner URI. Clears URI string and handle.
	plmxml_api::Result DeleteAssignerURI();
	
	//! Check if Assigner URI is set
	plmxml_api::logical HasAssignerURI( ) const;
	

	//! Get ResponsibleParty URI as plmxml_api::String
	plmxml_api::String GetResponsiblePartyURI() const;

	//! Set ResponsibleParty URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetResponsiblePartyURI( const plmxml_api::String& );
	
	//! Get the handle of ResponsibleParty URI. Does not resolve the URI.
	plmxml_api::Result GetResponsiblePartyURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ResponsibleParty URI. URI string is unchanged.
	plmxml_api::Result SetResponsiblePartyURI( const plmxml_api::Handle& );
	
	//! Resolve ResponsibleParty URI and return an object (handle) it points to.
	plmxml_api::Result ResolveResponsiblePartyURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ResponsibleParty URI. Clears URI string and handle.
	plmxml_api::Result DeleteResponsiblePartyURI();
	
	//! Check if ResponsibleParty URI is set
	plmxml_api::logical HasResponsiblePartyURI( ) const;
	

	//! Get ActiveSurrogate URI as plmxml_api::String
	plmxml_api::String GetActiveSurrogateURI() const;

	//! Set ActiveSurrogate URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActiveSurrogateURI( const plmxml_api::String& );
	
	//! Get the handle of ActiveSurrogate URI. Does not resolve the URI.
	plmxml_api::Result GetActiveSurrogateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActiveSurrogate URI. URI string is unchanged.
	plmxml_api::Result SetActiveSurrogateURI( const plmxml_api::Handle& );
	
	//! Resolve ActiveSurrogate URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActiveSurrogateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActiveSurrogate URI. Clears URI string and handle.
	plmxml_api::Result DeleteActiveSurrogateURI();
	
	//! Check if ActiveSurrogate URI is set
	plmxml_api::logical HasActiveSurrogateURI( ) const;
	

	//! Add Signoff child element to this Task. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Signoff *AddSignoff();
     
	//! Add 'arg' as Signoff child element to this Task.
	plmxml_api::Result AddSignoff( Signoff *arg );

	//! Detach and delete all Signoff child elements.
	void DeleteSignoffs();
     
	//! Get number of Signoff child elements.
	int NumberOfSignoffs() const;
     
	//! Get i'th Signoff child element.
	Signoff *GetSignoff( int i ) const;
     
	//! Get all Signoff child element as an array
	void GetSignoffs( plmxml_api::Array<Signoff*> &array ) const;
	     
	//! Detach and delete i'th Signoff child element
	void DeleteSignoff( int i );
     
	//! Detach and delete 'arg' if it's one of the Signoff child elements
	void DeleteSignoff( Signoff *arg );

	//! Add ReleaseStatus child element to this Task. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ReleaseStatus *AddReleaseStatus();
     
	//! Set ReleaseStatus child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetReleaseStatus( ReleaseStatus *arg );
     
	//! Get ReleaseStatus child element of this Task.
	ReleaseStatus *GetReleaseStatus() const;
     
	//! Detach and delete ReleaseStatus child element tree from this Task.
	void DeleteReleaseStatus();
 
// <PLMXML_UserCode type="functionHeaderTask" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassTask;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowProcess class
/*!
\verbatim

      Attributes:

      templateNameRef:  References a multiple language version of templateName.
                        If multiple language support is required,
                        templateNameRef should be used in addition to
                        templateName.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowProcess : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowProcess( );
     
    //! Constructs a WorkflowProcess with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowProcess( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowProcess();

private:

	//! Assignment operator
	WorkflowProcess& operator=( const WorkflowProcess& iSrc );

	//! Copy constructor
	WorkflowProcess( const WorkflowProcess& original );
     
public:

	//! Get Owner URI as plmxml_api::String
	plmxml_api::String GetOwnerURI() const;

	//! Set Owner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::String& );
	
	//! Get the handle of Owner URI. Does not resolve the URI.
	plmxml_api::Result GetOwnerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Owner URI. URI string is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::Handle& );
	
	//! Resolve Owner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOwnerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Owner URI. Clears URI string and handle.
	plmxml_api::Result DeleteOwnerURI();
	
	//! Check if Owner URI is set
	plmxml_api::logical HasOwnerURI( ) const;
	

	//! Get TemplateName URI as plmxml_api::String
	plmxml_api::String GetTemplateNameURI() const;

	//! Set TemplateName URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTemplateNameURI( const plmxml_api::String& );
	
	//! Get the handle of TemplateName URI. Does not resolve the URI.
	plmxml_api::Result GetTemplateNameURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TemplateName URI. URI string is unchanged.
	plmxml_api::Result SetTemplateNameURI( const plmxml_api::Handle& );
	
	//! Resolve TemplateName URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTemplateNameURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TemplateName URI. Clears URI string and handle.
	plmxml_api::Result DeleteTemplateNameURI();
	
	//! Check if TemplateName URI is set
	plmxml_api::logical HasTemplateNameURI( ) const;
	

	//! Get TemplateName of this WorkflowProcess
	plmxml_api::String GetTemplateName() const;

	//! Set TemplateName of this WorkflowProcess
	plmxml_api::Result SetTemplateName( const plmxml_api::String &s );
	
	//! Check if TemplateName is set
	plmxml_api::logical HasTemplateName( ) const;
	
	//! Unset TemplateName
	plmxml_api::Result UnsetTemplateName( );

	//! Add Task child element to this WorkflowProcess. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Task *AddTask();
     
	//! Add 'arg' as Task child element to this WorkflowProcess.
	plmxml_api::Result AddTask( Task *arg );

	//! Detach and delete all Task child elements.
	void DeleteTasks();
     
	//! Get number of Task child elements.
	int NumberOfTasks() const;
     
	//! Get i'th Task child element.
	Task *GetTask( int i ) const;
     
	//! Get all Task child element as an array
	void GetTasks( plmxml_api::Array<Task*> &array ) const;
	     
	//! Detach and delete i'th Task child element
	void DeleteTask( int i );
     
	//! Detach and delete 'arg' if it's one of the Task child elements
	void DeleteTask( Task *arg );
 
// <PLMXML_UserCode type="functionHeaderWorkflowProcess" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowProcess;


////////////////////////////////////////////////////////////////////////////////////
//! RelatedItem class
/*!
\verbatim

      Attributes:

      typeRef:          References a multiple language version of type. If
                        multiple language support is required, typeRef should be
                        used in addition to type.
      
\endverbatim
*/
class PLMXML_PDM60_API RelatedItem : public plmxml_api::Object
{
public:
     
    //! Default constructor
    RelatedItem( );
     
    //! Constructs a RelatedItem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RelatedItem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RelatedItem();

private:

	//! Assignment operator
	RelatedItem& operator=( const RelatedItem& iSrc );

	//! Copy constructor
	RelatedItem( const RelatedItem& original );
     
public:

	//! Get Type of this RelatedItem
	plmxml_api::String GetType() const;

	//! Set Type of this RelatedItem
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get Item URI as plmxml_api::String
	plmxml_api::String GetItemURI() const;

	//! Set Item URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetItemURI( const plmxml_api::String& );
	
	//! Get the handle of Item URI. Does not resolve the URI.
	plmxml_api::Result GetItemURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Item URI. URI string is unchanged.
	plmxml_api::Result SetItemURI( const plmxml_api::Handle& );
	
	//! Resolve Item URI and return an object (handle) it points to.
	plmxml_api::Result ResolveItemURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Item URI. Clears URI string and handle.
	plmxml_api::Result DeleteItemURI();
	
	//! Check if Item URI is set
	plmxml_api::logical HasItemURI( ) const;
	

	//! Get Type URI as plmxml_api::String
	plmxml_api::String GetTypeURI() const;

	//! Set Type URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTypeURI( const plmxml_api::String& );
	
	//! Get the handle of Type URI. Does not resolve the URI.
	plmxml_api::Result GetTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Type URI. URI string is unchanged.
	plmxml_api::Result SetTypeURI( const plmxml_api::Handle& );
	
	//! Resolve Type URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Type URI. Clears URI string and handle.
	plmxml_api::Result DeleteTypeURI();
	
	//! Check if Type URI is set
	plmxml_api::logical HasTypeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderRelatedItem" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassRelatedItem;


//! Forward class declarations
class ChangeRecord;
class ChangeRecordGroup;

////////////////////////////////////////////////////////////////////////////////////
//! Change class
/*!
\verbatim

      This element represents an Engineering Change. Each Change has a number of
      related objects, with relation type such as Affected, Problem, or
      Reference.

      Attributes:

      type:
      changeId:         change id
      changeRevisionId: revision string, e.g. "B"
      ownerRef:
      typeRef:          References a multiple language version of type. If
                        multiple language support is required, typeRef should be
                        used in addition to type.

      Sub-elements:

      RelatedItem:      related elements
      ReleaseStatus:
      ChangeRecord:     records of adds, deletions and other changes
      ChangeRecordGroup:
      
\endverbatim
*/
class PLMXML_PDM60_API Change : public AttribOwner
{
public:
     
    //! Default constructor
    Change( );
     
    //! Constructs a Change with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Change( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Change();

private:

	//! Assignment operator
	Change& operator=( const Change& iSrc );

	//! Copy constructor
	Change( const Change& original );
     
public:

	//! Get Owner URI as plmxml_api::String
	plmxml_api::String GetOwnerURI() const;

	//! Set Owner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::String& );
	
	//! Get the handle of Owner URI. Does not resolve the URI.
	plmxml_api::Result GetOwnerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Owner URI. URI string is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::Handle& );
	
	//! Resolve Owner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOwnerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Owner URI. Clears URI string and handle.
	plmxml_api::Result DeleteOwnerURI();
	
	//! Check if Owner URI is set
	plmxml_api::logical HasOwnerURI( ) const;
	

	//! Get ChangeRevisionId of this Change
	plmxml_api::String GetChangeRevisionId() const;

	//! Set ChangeRevisionId of this Change
	plmxml_api::Result SetChangeRevisionId( const plmxml_api::String &s );
	
	//! Check if ChangeRevisionId is set
	plmxml_api::logical HasChangeRevisionId( ) const;
	
	//! Unset ChangeRevisionId
	plmxml_api::Result UnsetChangeRevisionId( );

	//! Get Type of this Change
	plmxml_api::String GetType() const;

	//! Set Type of this Change
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get Type URI as plmxml_api::String
	plmxml_api::String GetTypeURI() const;

	//! Set Type URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTypeURI( const plmxml_api::String& );
	
	//! Get the handle of Type URI. Does not resolve the URI.
	plmxml_api::Result GetTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Type URI. URI string is unchanged.
	plmxml_api::Result SetTypeURI( const plmxml_api::Handle& );
	
	//! Resolve Type URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Type URI. Clears URI string and handle.
	plmxml_api::Result DeleteTypeURI();
	
	//! Check if Type URI is set
	plmxml_api::logical HasTypeURI( ) const;
	

	//! Get ChangeId of this Change
	plmxml_api::String GetChangeId() const;

	//! Set ChangeId of this Change
	plmxml_api::Result SetChangeId( const plmxml_api::String &s );
	
	//! Check if ChangeId is set
	plmxml_api::logical HasChangeId( ) const;
	
	//! Unset ChangeId
	plmxml_api::Result UnsetChangeId( );

	//! Add RelatedItem child element to this Change. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RelatedItem *AddRelatedItem();
     
	//! Add 'arg' as RelatedItem child element to this Change.
	plmxml_api::Result AddRelatedItem( RelatedItem *arg );

	//! Detach and delete all RelatedItem child elements.
	void DeleteRelatedItems();
     
	//! Get number of RelatedItem child elements.
	int NumberOfRelatedItems() const;
     
	//! Get i'th RelatedItem child element.
	RelatedItem *GetRelatedItem( int i ) const;
     
	//! Get all RelatedItem child element as an array
	void GetRelatedItems( plmxml_api::Array<RelatedItem*> &array ) const;
	     
	//! Detach and delete i'th RelatedItem child element
	void DeleteRelatedItem( int i );
     
	//! Detach and delete 'arg' if it's one of the RelatedItem child elements
	void DeleteRelatedItem( RelatedItem *arg );

	//! Add ReleaseStatus child element to this Change. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ReleaseStatus *AddReleaseStatus();
     
	//! Add 'arg' as ReleaseStatus child element to this Change.
	plmxml_api::Result AddReleaseStatus( ReleaseStatus *arg );

	//! Detach and delete all ReleaseStatus child elements.
	void DeleteReleaseStatuses();
     
	//! Get number of ReleaseStatus child elements.
	int NumberOfReleaseStatuses() const;
     
	//! Get i'th ReleaseStatus child element.
	ReleaseStatus *GetReleaseStatus( int i ) const;
     
	//! Get all ReleaseStatus child element as an array
	void GetReleaseStatuses( plmxml_api::Array<ReleaseStatus*> &array ) const;
	     
	//! Detach and delete i'th ReleaseStatus child element
	void DeleteReleaseStatus( int i );
     
	//! Detach and delete 'arg' if it's one of the ReleaseStatus child elements
	void DeleteReleaseStatus( ReleaseStatus *arg );

	//! Add ChangeRecord child element to this Change. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ChangeRecord *AddChangeRecord();
     
	//! Add 'arg' as ChangeRecord child element to this Change.
	plmxml_api::Result AddChangeRecord( ChangeRecord *arg );

	//! Detach and delete all ChangeRecord child elements.
	void DeleteChangeRecords();
     
	//! Get number of ChangeRecord child elements.
	int NumberOfChangeRecords() const;
     
	//! Get i'th ChangeRecord child element.
	ChangeRecord *GetChangeRecord( int i ) const;
     
	//! Get all ChangeRecord child element as an array
	void GetChangeRecords( plmxml_api::Array<ChangeRecord*> &array ) const;
	     
	//! Detach and delete i'th ChangeRecord child element
	void DeleteChangeRecord( int i );
     
	//! Detach and delete 'arg' if it's one of the ChangeRecord child elements
	void DeleteChangeRecord( ChangeRecord *arg );

	//! Add ChangeRecordGroup child element to this Change. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ChangeRecordGroup *AddChangeRecordGroup();
     
	//! Add 'arg' as ChangeRecordGroup child element to this Change.
	plmxml_api::Result AddChangeRecordGroup( ChangeRecordGroup *arg );

	//! Detach and delete all ChangeRecordGroup child elements.
	void DeleteChangeRecordGroups();
     
	//! Get number of ChangeRecordGroup child elements.
	int NumberOfChangeRecordGroups() const;
     
	//! Get i'th ChangeRecordGroup child element.
	ChangeRecordGroup *GetChangeRecordGroup( int i ) const;
     
	//! Get all ChangeRecordGroup child element as an array
	void GetChangeRecordGroups( plmxml_api::Array<ChangeRecordGroup*> &array ) const;
	     
	//! Detach and delete i'th ChangeRecordGroup child element
	void DeleteChangeRecordGroup( int i );
     
	//! Detach and delete 'arg' if it's one of the ChangeRecordGroup child elements
	void DeleteChangeRecordGroup( ChangeRecordGroup *arg );
 
// <PLMXML_UserCode type="functionHeaderChange" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassChange;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowTemplate class
/*!
\verbatim

      The WorkflowTemplateType represents the type for the workflow templates.
      Typically workflow template is used to initialize workflow processes. A
      workflow template have actions associated with it to represent a list of
      workflow actions that will be triggered during a workflow process. The
      actions objects are WorkflowAction objects. A workflow template also might
      have a parent task template, one or more dependency task templates, and
      one or more child task templates associated with it. These are also
      WorkflowTemplate objects.

      Attributes:

      locationRef:      References a multiple language version of location. If
                        multiple language support is required, locationRef
                        should be used in addition to location.
      objectTypeRef:    References a multiple language version of objectType. If
                        multiple language support is required, objectTypeRef
                        should be used in addition to objectType.
      waitForUndecidedReviewers: Whether the workflow process should wait for
                        undecided reviewers.
      originalId:       An identifer for the original WorkflowTemplate to allow
                        traceability to the original WorkflowTemplate, even
                        after it has been deleted.
      asynchronous:     Whether the WorkflowTemplate may be processed
                        asynchronously.
      filterCondition:  The name of the filter condition.
      decisionSet:      The name of the decision set.
      storeParticipantsOnWorkflowProcess: Whether the assigned Participants are
                        stored on the workflow process or on the target
                        elements.
      requireCompleteConfirmation: Whether confirmation of completion is
                        required.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowTemplate : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowTemplate( );
     
    //! Constructs a WorkflowTemplate with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowTemplate( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowTemplate();

private:

	//! Assignment operator
	WorkflowTemplate& operator=( const WorkflowTemplate& iSrc );

	//! Copy constructor
	WorkflowTemplate( const WorkflowTemplate& original );
     
public:

	//! Set Asynchronous
	plmxml_api::Result SetAsynchronous( plmxml_api::logical arg );

	//! Get Asynchronous
	plmxml_api::logical GetAsynchronous() const;

	//! Check if Asynchronous is set
	plmxml_api::logical HasAsynchronous() const;

	//! Unset Asynchronous
	plmxml_api::Result UnsetAsynchronous();

	//! Get DecisionSet of this WorkflowTemplate
	plmxml_api::String GetDecisionSet() const;

	//! Set DecisionSet of this WorkflowTemplate
	plmxml_api::Result SetDecisionSet( const plmxml_api::String &s );
	
	//! Check if DecisionSet is set
	plmxml_api::logical HasDecisionSet( ) const;
	
	//! Unset DecisionSet
	plmxml_api::Result UnsetDecisionSet( );

	//! Get number of URIs in SubTemplate
	int NumberOfSubTemplateURIs() const;

	//! Get i'th URI in SubTemplate
	plmxml_api::String GetSubTemplateURI( int i ) const;

	//! Add a URI to SubTemplate array. Call ResolveSubTemplateURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSubTemplateURI( const plmxml_api::String& u );

	//! Set i'th URI in SubTemplate array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSubTemplateURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SubTemplate URI. Does not resolve the URI.
	plmxml_api::Result GetSubTemplateURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SubTemplate array.
	plmxml_api::Result AddSubTemplateURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SubTemplate array to point to 'handle'.
	plmxml_api::Result SetSubTemplateURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SubTemplate points to.
	plmxml_api::Result ResolveSubTemplateURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SubTemplate array.
	plmxml_api::Result DeleteSubTemplateURI( int i );

	//! Remove all URIs from SubTemplate array.
	plmxml_api::Result DeleteSubTemplateURIs( );
	
	//! Check if SubTemplate is set
	plmxml_api::logical HasSubTemplateURIs( ) const;

	//! Set Stage
	plmxml_api::Result SetStage( const eWorkflowTemplateStageEnum& arg );

	//! Get Stage
	eWorkflowTemplateStageEnum GetStage() const;

	//! Get OriginalId of this WorkflowTemplate
	plmxml_api::String GetOriginalId() const;

	//! Set OriginalId of this WorkflowTemplate
	plmxml_api::Result SetOriginalId( const plmxml_api::String &s );
	
	//! Check if OriginalId is set
	plmxml_api::logical HasOriginalId( ) const;
	
	//! Unset OriginalId
	plmxml_api::Result UnsetOriginalId( );

	//! Set StoreParticipantsOnWorkflowProcess
	plmxml_api::Result SetStoreParticipantsOnWorkflowProcess( plmxml_api::logical arg );

	//! Get StoreParticipantsOnWorkflowProcess
	plmxml_api::logical GetStoreParticipantsOnWorkflowProcess() const;

	//! Check if StoreParticipantsOnWorkflowProcess is set
	plmxml_api::logical HasStoreParticipantsOnWorkflowProcess() const;

	//! Unset StoreParticipantsOnWorkflowProcess
	plmxml_api::Result UnsetStoreParticipantsOnWorkflowProcess();

	//! Get FilterCondition of this WorkflowTemplate
	plmxml_api::String GetFilterCondition() const;

	//! Set FilterCondition of this WorkflowTemplate
	plmxml_api::Result SetFilterCondition( const plmxml_api::String &s );
	
	//! Check if FilterCondition is set
	plmxml_api::logical HasFilterCondition( ) const;
	
	//! Unset FilterCondition
	plmxml_api::Result UnsetFilterCondition( );

	//! Set SignoffQuorum
	plmxml_api::Result SetSignoffQuorum( int arg );
     
	//! Get SignoffQuorum
	int GetSignoffQuorum() const;
     
	//! Check if SignoffQuorum is set
	plmxml_api::logical HasSignoffQuorum() const;
     
	//! Unset SignoffQuorum
	plmxml_api::Result UnsetSignoffQuorum();

	//! Set WaitForUndecidedReviewers
	plmxml_api::Result SetWaitForUndecidedReviewers( const eWorkflowTemplateUndecidedReviewersEnum& arg );

	//! Get WaitForUndecidedReviewers
	eWorkflowTemplateUndecidedReviewersEnum GetWaitForUndecidedReviewers() const;

	//! Get ParentTaskTemplate URI as plmxml_api::String
	plmxml_api::String GetParentTaskTemplateURI() const;

	//! Set ParentTaskTemplate URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetParentTaskTemplateURI( const plmxml_api::String& );
	
	//! Get the handle of ParentTaskTemplate URI. Does not resolve the URI.
	plmxml_api::Result GetParentTaskTemplateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ParentTaskTemplate URI. URI string is unchanged.
	plmxml_api::Result SetParentTaskTemplateURI( const plmxml_api::Handle& );
	
	//! Resolve ParentTaskTemplate URI and return an object (handle) it points to.
	plmxml_api::Result ResolveParentTaskTemplateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ParentTaskTemplate URI. Clears URI string and handle.
	plmxml_api::Result DeleteParentTaskTemplateURI();
	
	//! Check if ParentTaskTemplate URI is set
	plmxml_api::logical HasParentTaskTemplateURI( ) const;
	

	//! Get ObjectType of this WorkflowTemplate
	plmxml_api::String GetObjectType() const;

	//! Set ObjectType of this WorkflowTemplate
	plmxml_api::Result SetObjectType( const plmxml_api::String &s );
	
	//! Check if ObjectType is set
	plmxml_api::logical HasObjectType( ) const;
	
	//! Unset ObjectType
	plmxml_api::Result UnsetObjectType( );

	//! Get IconKey of this WorkflowTemplate
	plmxml_api::String GetIconKey() const;

	//! Set IconKey of this WorkflowTemplate
	plmxml_api::Result SetIconKey( const plmxml_api::String &s );
	
	//! Check if IconKey is set
	plmxml_api::logical HasIconKey( ) const;
	
	//! Unset IconKey
	plmxml_api::Result UnsetIconKey( );

	//! Get number of URIs in DependencyTaskTemplate
	int NumberOfDependencyTaskTemplateURIs() const;

	//! Get i'th URI in DependencyTaskTemplate
	plmxml_api::String GetDependencyTaskTemplateURI( int i ) const;

	//! Add a URI to DependencyTaskTemplate array. Call ResolveDependencyTaskTemplateURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDependencyTaskTemplateURI( const plmxml_api::String& u );

	//! Set i'th URI in DependencyTaskTemplate array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDependencyTaskTemplateURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of DependencyTaskTemplate URI. Does not resolve the URI.
	plmxml_api::Result GetDependencyTaskTemplateURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to DependencyTaskTemplate array.
	plmxml_api::Result AddDependencyTaskTemplateURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in DependencyTaskTemplate array to point to 'handle'.
	plmxml_api::Result SetDependencyTaskTemplateURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in DependencyTaskTemplate points to.
	plmxml_api::Result ResolveDependencyTaskTemplateURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from DependencyTaskTemplate array.
	plmxml_api::Result DeleteDependencyTaskTemplateURI( int i );

	//! Remove all URIs from DependencyTaskTemplate array.
	plmxml_api::Result DeleteDependencyTaskTemplateURIs( );
	
	//! Check if DependencyTaskTemplate is set
	plmxml_api::logical HasDependencyTaskTemplateURIs( ) const;

	//! Set ShowInProcessStage
	plmxml_api::Result SetShowInProcessStage( plmxml_api::logical arg );

	//! Get ShowInProcessStage
	plmxml_api::logical GetShowInProcessStage() const;

	//! Check if ShowInProcessStage is set
	plmxml_api::logical HasShowInProcessStage() const;

	//! Unset ShowInProcessStage
	plmxml_api::Result UnsetShowInProcessStage();

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
	

	//! Get Location of this WorkflowTemplate
	plmxml_api::String GetLocation() const;

	//! Set Location of this WorkflowTemplate
	plmxml_api::Result SetLocation( const plmxml_api::String &s );
	
	//! Check if Location is set
	plmxml_api::logical HasLocation( ) const;
	
	//! Unset Location
	plmxml_api::Result UnsetLocation( );

	//! Set RequireCompleteConfirmation
	plmxml_api::Result SetRequireCompleteConfirmation( plmxml_api::logical arg );

	//! Get RequireCompleteConfirmation
	plmxml_api::logical GetRequireCompleteConfirmation() const;

	//! Check if RequireCompleteConfirmation is set
	plmxml_api::logical HasRequireCompleteConfirmation() const;

	//! Unset RequireCompleteConfirmation
	plmxml_api::Result UnsetRequireCompleteConfirmation();

	//! Get ObjectType URI as plmxml_api::String
	plmxml_api::String GetObjectTypeURI() const;

	//! Set ObjectType URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetObjectTypeURI( const plmxml_api::String& );
	
	//! Get the handle of ObjectType URI. Does not resolve the URI.
	plmxml_api::Result GetObjectTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ObjectType URI. URI string is unchanged.
	plmxml_api::Result SetObjectTypeURI( const plmxml_api::Handle& );
	
	//! Resolve ObjectType URI and return an object (handle) it points to.
	plmxml_api::Result ResolveObjectTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ObjectType URI. Clears URI string and handle.
	plmxml_api::Result DeleteObjectTypeURI();
	
	//! Check if ObjectType URI is set
	plmxml_api::logical HasObjectTypeURI( ) const;
	

	//! Set TemplateClassification
	plmxml_api::Result SetTemplateClassification( const eWorkflowTemplateClassificationEnum& arg );

	//! Get TemplateClassification
	eWorkflowTemplateClassificationEnum GetTemplateClassification() const;

	//! Get number of URIs in Actions
	int NumberOfActionsURIs() const;

	//! Get i'th URI in Actions
	plmxml_api::String GetActionsURI( int i ) const;

	//! Add a URI to Actions array. Call ResolveActionsURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActionsURI( const plmxml_api::String& u );

	//! Set i'th URI in Actions array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActionsURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Actions URI. Does not resolve the URI.
	plmxml_api::Result GetActionsURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Actions array.
	plmxml_api::Result AddActionsURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Actions array to point to 'handle'.
	plmxml_api::Result SetActionsURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Actions points to.
	plmxml_api::Result ResolveActionsURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Actions array.
	plmxml_api::Result DeleteActionsURI( int i );

	//! Remove all URIs from Actions array.
	plmxml_api::Result DeleteActionsURIs( );
	
	//! Check if Actions is set
	plmxml_api::logical HasActionsURIs( ) const;

	//! Add TaskDescription child element to this WorkflowTemplate. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserList *AddTaskDescription();
     
	//! Set TaskDescription child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTaskDescription( UserList *arg );
     
	//! Get TaskDescription child element of this WorkflowTemplate.
	UserList *GetTaskDescription() const;
     
	//! Detach and delete TaskDescription child element tree from this WorkflowTemplate.
	void DeleteTaskDescription();

	//! Get DependencyTaskActions of this WorkflowTemplate
	plmxml_api::String GetDependencyTaskActions() const;

	//! Set DependencyTaskActions of this WorkflowTemplate
	plmxml_api::Result SetDependencyTaskActions( const plmxml_api::String &s );
	
	//! Check if DependencyTaskActions is set
	plmxml_api::logical HasDependencyTaskActions( ) const;
	
	//! Unset DependencyTaskActions
	plmxml_api::Result UnsetDependencyTaskActions( );

	//! Get DependencyTaskTemplates of this WorkflowTemplate
	plmxml_api::String GetDependencyTaskTemplates() const;

	//! Set DependencyTaskTemplates of this WorkflowTemplate
	plmxml_api::Result SetDependencyTaskTemplates( const plmxml_api::String &s );
	
	//! Check if DependencyTaskTemplates is set
	plmxml_api::logical HasDependencyTaskTemplates( ) const;
	
	//! Unset DependencyTaskTemplates
	plmxml_api::Result UnsetDependencyTaskTemplates( );
 
// <PLMXML_UserCode type="functionHeaderWorkflowTemplate" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowTemplate;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowAction class
/*!
\verbatim

      Each WorkflowAction object has one or more action handlers and business rules associated
      with it. The action handlers are represented by a list WorkflowHandlers, while the business
      rules are represented WorkflowBusinessRules. The WorkflowAction object also has a back pointer
      to its parent task template.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowAction : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowAction( );
     
    //! Constructs a WorkflowAction with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowAction( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowAction();

private:

	//! Assignment operator
	WorkflowAction& operator=( const WorkflowAction& iSrc );

	//! Copy constructor
	WorkflowAction( const WorkflowAction& original );
     
public:

	//! Get number of URIs in ActionHandler
	int NumberOfActionHandlerURIs() const;

	//! Get i'th URI in ActionHandler
	plmxml_api::String GetActionHandlerURI( int i ) const;

	//! Add a URI to ActionHandler array. Call ResolveActionHandlerURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActionHandlerURI( const plmxml_api::String& u );

	//! Set i'th URI in ActionHandler array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActionHandlerURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ActionHandler URI. Does not resolve the URI.
	plmxml_api::Result GetActionHandlerURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ActionHandler array.
	plmxml_api::Result AddActionHandlerURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ActionHandler array to point to 'handle'.
	plmxml_api::Result SetActionHandlerURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ActionHandler points to.
	plmxml_api::Result ResolveActionHandlerURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ActionHandler array.
	plmxml_api::Result DeleteActionHandlerURI( int i );

	//! Remove all URIs from ActionHandler array.
	plmxml_api::Result DeleteActionHandlerURIs( );
	
	//! Check if ActionHandler is set
	plmxml_api::logical HasActionHandlerURIs( ) const;

	//! Get Parent URI as plmxml_api::String
	plmxml_api::String GetParentURI() const;

	//! Set Parent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::String& );
	
	//! Get the handle of Parent URI. Does not resolve the URI.
	plmxml_api::Result GetParentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Parent URI. URI string is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::Handle& );
	
	//! Resolve Parent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveParentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Parent URI. Clears URI string and handle.
	plmxml_api::Result DeleteParentURI();
	
	//! Check if Parent URI is set
	plmxml_api::logical HasParentURI( ) const;
	

	//! Get ActionType of this WorkflowAction
	plmxml_api::String GetActionType() const;

	//! Set ActionType of this WorkflowAction
	plmxml_api::Result SetActionType( const plmxml_api::String &s );
	
	//! Check if ActionType is set
	plmxml_api::logical HasActionType( ) const;
	
	//! Unset ActionType
	plmxml_api::Result UnsetActionType( );

	//! Get number of URIs in Rule
	int NumberOfRuleURIs() const;

	//! Get i'th URI in Rule
	plmxml_api::String GetRuleURI( int i ) const;

	//! Add a URI to Rule array. Call ResolveRuleURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRuleURI( const plmxml_api::String& u );

	//! Set i'th URI in Rule array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRuleURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Rule URI. Does not resolve the URI.
	plmxml_api::Result GetRuleURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Rule array.
	plmxml_api::Result AddRuleURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Rule array to point to 'handle'.
	plmxml_api::Result SetRuleURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Rule points to.
	plmxml_api::Result ResolveRuleURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Rule array.
	plmxml_api::Result DeleteRuleURI( int i );

	//! Remove all URIs from Rule array.
	plmxml_api::Result DeleteRuleURIs( );
	
	//! Check if Rule is set
	plmxml_api::logical HasRuleURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderWorkflowAction" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowAction;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowHandler class
/*!
\verbatim

      A WorkflowHandler is a small program or function. Handlers are used to 
      extend and customize workflow tasks. A WorkflowHandler object has one or more 
      arguments associated with it.  It also has a back pointer to its parent workflow
      action object.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowHandler : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowHandler( );
     
    //! Constructs a WorkflowHandler with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowHandler( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowHandler();

private:

	//! Assignment operator
	WorkflowHandler& operator=( const WorkflowHandler& iSrc );

	//! Copy constructor
	WorkflowHandler( const WorkflowHandler& original );
     
public:

	//! Get Parent URI as plmxml_api::String
	plmxml_api::String GetParentURI() const;

	//! Set Parent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::String& );
	
	//! Get the handle of Parent URI. Does not resolve the URI.
	plmxml_api::Result GetParentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Parent URI. URI string is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::Handle& );
	
	//! Resolve Parent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveParentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Parent URI. Clears URI string and handle.
	plmxml_api::Result DeleteParentURI();
	
	//! Check if Parent URI is set
	plmxml_api::logical HasParentURI( ) const;
	

	//! Add Arguments child element to this WorkflowHandler. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddArguments();
     
	//! Set Arguments child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetArguments( UserData *arg );
     
	//! Get Arguments child element of this WorkflowHandler.
	UserData *GetArguments() const;
     
	//! Detach and delete Arguments child element tree from this WorkflowHandler.
	void DeleteArguments();
 
// <PLMXML_UserCode type="functionHeaderWorkflowHandler" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowHandler;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowBusinessRuleHandler class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API WorkflowBusinessRuleHandler : public WorkflowHandler
{
public:
     
    //! Default constructor
    WorkflowBusinessRuleHandler( );
     
    //! Constructs a WorkflowBusinessRuleHandler with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowBusinessRuleHandler( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowBusinessRuleHandler();

private:

	//! Assignment operator
	WorkflowBusinessRuleHandler& operator=( const WorkflowBusinessRuleHandler& iSrc );

	//! Copy constructor
	WorkflowBusinessRuleHandler( const WorkflowBusinessRuleHandler& original );
     
public:

	//! Set Negated
	plmxml_api::Result SetNegated( plmxml_api::logical arg );

	//! Get Negated
	plmxml_api::logical GetNegated() const;

	//! Check if Negated is set
	plmxml_api::logical HasNegated() const;

	//! Unset Negated
	plmxml_api::Result UnsetNegated();

	//! Set Override
	plmxml_api::Result SetOverride( plmxml_api::logical arg );

	//! Get Override
	plmxml_api::logical GetOverride() const;

	//! Check if Override is set
	plmxml_api::logical HasOverride() const;

	//! Unset Override
	plmxml_api::Result UnsetOverride();
 
// <PLMXML_UserCode type="functionHeaderWorkflowBusinessRuleHandler" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowBusinessRuleHandler;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowBusinessRule class
/*!
\verbatim

      A WorkflowBusinessRule represents some conditions that must be met to perform a workflow
      action. It consists of one or more WorkflowBusinessRuleHandlers, and a rule quorum 
      specifying the number of rule handlers that must return go for the workflow action to 
      complete. It also has a back pointer to its parent workflow action object.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowBusinessRule : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowBusinessRule( );
     
    //! Constructs a WorkflowBusinessRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowBusinessRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowBusinessRule();

private:

	//! Assignment operator
	WorkflowBusinessRule& operator=( const WorkflowBusinessRule& iSrc );

	//! Copy constructor
	WorkflowBusinessRule( const WorkflowBusinessRule& original );
     
public:

	//! Set RuleQuorum
	plmxml_api::Result SetRuleQuorum( int arg );
     
	//! Get RuleQuorum
	int GetRuleQuorum() const;
     
	//! Check if RuleQuorum is set
	plmxml_api::logical HasRuleQuorum() const;
     
	//! Unset RuleQuorum
	plmxml_api::Result UnsetRuleQuorum();

	//! Get number of URIs in RuleHandler
	int NumberOfRuleHandlerURIs() const;

	//! Get i'th URI in RuleHandler
	plmxml_api::String GetRuleHandlerURI( int i ) const;

	//! Add a URI to RuleHandler array. Call ResolveRuleHandlerURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRuleHandlerURI( const plmxml_api::String& u );

	//! Set i'th URI in RuleHandler array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRuleHandlerURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of RuleHandler URI. Does not resolve the URI.
	plmxml_api::Result GetRuleHandlerURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to RuleHandler array.
	plmxml_api::Result AddRuleHandlerURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in RuleHandler array to point to 'handle'.
	plmxml_api::Result SetRuleHandlerURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in RuleHandler points to.
	plmxml_api::Result ResolveRuleHandlerURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from RuleHandler array.
	plmxml_api::Result DeleteRuleHandlerURI( int i );

	//! Remove all URIs from RuleHandler array.
	plmxml_api::Result DeleteRuleHandlerURIs( );
	
	//! Check if RuleHandler is set
	plmxml_api::logical HasRuleHandlerURIs( ) const;

	//! Get Parent URI as plmxml_api::String
	plmxml_api::String GetParentURI() const;

	//! Set Parent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::String& );
	
	//! Get the handle of Parent URI. Does not resolve the URI.
	plmxml_api::Result GetParentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Parent URI. URI string is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::Handle& );
	
	//! Resolve Parent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveParentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Parent URI. Clears URI string and handle.
	plmxml_api::Result DeleteParentURI();
	
	//! Check if Parent URI is set
	plmxml_api::logical HasParentURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderWorkflowBusinessRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowBusinessRule;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowSignoffProfile class
/*!
\verbatim

      A WorkflowSignoffProfile is used in a workflow review task template to define which a 
      user will comply with to assign review responsibilities to other Users. A signoff profile
      consists of a group and a role for a user, while the group object should be of type 
      plm:OrganisationType, and the role object should be of type plm:RoleType. The signoff profile
      object also has a back pointer to its related task template.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowSignoffProfile : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowSignoffProfile( );
     
    //! Constructs a WorkflowSignoffProfile with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowSignoffProfile( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowSignoffProfile();

private:

	//! Assignment operator
	WorkflowSignoffProfile& operator=( const WorkflowSignoffProfile& iSrc );

	//! Copy constructor
	WorkflowSignoffProfile( const WorkflowSignoffProfile& original );
     
public:

	//! Set AllowSubgroups
	plmxml_api::Result SetAllowSubgroups( plmxml_api::logical arg );

	//! Get AllowSubgroups
	plmxml_api::logical GetAllowSubgroups() const;

	//! Check if AllowSubgroups is set
	plmxml_api::logical HasAllowSubgroups() const;

	//! Unset AllowSubgroups
	plmxml_api::Result UnsetAllowSubgroups();

	//! Set SignoffQuorum
	plmxml_api::Result SetSignoffQuorum( int arg );
     
	//! Get SignoffQuorum
	int GetSignoffQuorum() const;
     
	//! Check if SignoffQuorum is set
	plmxml_api::logical HasSignoffQuorum() const;
     
	//! Unset SignoffQuorum
	plmxml_api::Result UnsetSignoffQuorum();

	//! Set SignoffRequired
	plmxml_api::Result SetSignoffRequired( plmxml_api::logical arg );

	//! Get SignoffRequired
	plmxml_api::logical GetSignoffRequired() const;

	//! Check if SignoffRequired is set
	plmxml_api::logical HasSignoffRequired() const;

	//! Unset SignoffRequired
	plmxml_api::Result UnsetSignoffRequired();

	//! Set NumberOfSignoffs
	plmxml_api::Result SetNumberOfSignoffs( int arg );
     
	//! Get NumberOfSignoffs
	int GetNumberOfSignoffs() const;
     
	//! Check if NumberOfSignoffs is set
	plmxml_api::logical HasNumberOfSignoffs() const;
     
	//! Unset NumberOfSignoffs
	plmxml_api::Result UnsetNumberOfSignoffs();

	//! Get Template URI as plmxml_api::String
	plmxml_api::String GetTemplateURI() const;

	//! Set Template URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTemplateURI( const plmxml_api::String& );
	
	//! Get the handle of Template URI. Does not resolve the URI.
	plmxml_api::Result GetTemplateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Template URI. URI string is unchanged.
	plmxml_api::Result SetTemplateURI( const plmxml_api::Handle& );
	
	//! Resolve Template URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTemplateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Template URI. Clears URI string and handle.
	plmxml_api::Result DeleteTemplateURI();
	
	//! Check if Template URI is set
	plmxml_api::logical HasTemplateURI( ) const;
	

	//! Get Role URI as plmxml_api::String
	plmxml_api::String GetRoleURI() const;

	//! Set Role URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRoleURI( const plmxml_api::String& );
	
	//! Get the handle of Role URI. Does not resolve the URI.
	plmxml_api::Result GetRoleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Role URI. URI string is unchanged.
	plmxml_api::Result SetRoleURI( const plmxml_api::Handle& );
	
	//! Resolve Role URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRoleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Role URI. Clears URI string and handle.
	plmxml_api::Result DeleteRoleURI();
	
	//! Check if Role URI is set
	plmxml_api::logical HasRoleURI( ) const;
	

	//! Get Group URI as plmxml_api::String
	plmxml_api::String GetGroupURI() const;

	//! Set Group URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetGroupURI( const plmxml_api::String& );
	
	//! Get the handle of Group URI. Does not resolve the URI.
	plmxml_api::Result GetGroupURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Group URI. URI string is unchanged.
	plmxml_api::Result SetGroupURI( const plmxml_api::Handle& );
	
	//! Resolve Group URI and return an object (handle) it points to.
	plmxml_api::Result ResolveGroupURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Group URI. Clears URI string and handle.
	plmxml_api::Result DeleteGroupURI();
	
	//! Check if Group URI is set
	plmxml_api::logical HasGroupURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderWorkflowSignoffProfile" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowSignoffProfile;


////////////////////////////////////////////////////////////////////////////////////
//! WorkflowProfileRelation class
/*!
\verbatim

      A base type for defining relations between workflow task template and signoff profile elements. 
      ownerRef is a reference to an owning object, such as a task template or a task. profileRefs is 
      a reference to one or many signoff profiles that this owner object is associated to.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkflowProfileRelation : public AttribOwner
{
public:
     
    //! Default constructor
    WorkflowProfileRelation( );
     
    //! Constructs a WorkflowProfileRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkflowProfileRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkflowProfileRelation();

private:

	//! Assignment operator
	WorkflowProfileRelation& operator=( const WorkflowProfileRelation& iSrc );

	//! Copy constructor
	WorkflowProfileRelation( const WorkflowProfileRelation& original );
     
public:

	//! Get Owner URI as plmxml_api::String
	plmxml_api::String GetOwnerURI() const;

	//! Set Owner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::String& );
	
	//! Get the handle of Owner URI. Does not resolve the URI.
	plmxml_api::Result GetOwnerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Owner URI. URI string is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::Handle& );
	
	//! Resolve Owner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOwnerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Owner URI. Clears URI string and handle.
	plmxml_api::Result DeleteOwnerURI();
	
	//! Check if Owner URI is set
	plmxml_api::logical HasOwnerURI( ) const;
	

	//! Get number of URIs in Profile
	int NumberOfProfileURIs() const;

	//! Get i'th URI in Profile
	plmxml_api::String GetProfileURI( int i ) const;

	//! Add a URI to Profile array. Call ResolveProfileURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddProfileURI( const plmxml_api::String& u );

	//! Set i'th URI in Profile array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetProfileURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Profile URI. Does not resolve the URI.
	plmxml_api::Result GetProfileURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Profile array.
	plmxml_api::Result AddProfileURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Profile array to point to 'handle'.
	plmxml_api::Result SetProfileURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Profile points to.
	plmxml_api::Result ResolveProfileURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Profile array.
	plmxml_api::Result DeleteProfileURI( int i );

	//! Remove all URIs from Profile array.
	plmxml_api::Result DeleteProfileURIs( );
	
	//! Check if Profile is set
	plmxml_api::logical HasProfileURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderWorkflowProfileRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkflowProfileRelation;


////////////////////////////////////////////////////////////////////////////////////
//! RuleEntry class
/*!
\verbatim

      Base type for Revision Rule Entries.
      
\endverbatim
*/
class PLMXML_PDM60_API RuleEntry : public DescriptionObject
{
public:
     
    //! Default constructor
    RuleEntry( );
     
    //! Constructs a RuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RuleEntry();

private:

	//! Assignment operator
	RuleEntry& operator=( const RuleEntry& iSrc );

	//! Copy constructor
	RuleEntry( const RuleEntry& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! DateRuleEntry class
/*!
\verbatim

      Specifies a date to be used by other Rule Entries.
      
      Attributes:
      
      refDate:      the dateTime
      isToday:      if 'true', the dateTime is today (at 00.00 hours).
      
\endverbatim
*/
class PLMXML_PDM60_API DateRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    DateRuleEntry( );
     
    //! Constructs a DateRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DateRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DateRuleEntry();

private:

	//! Assignment operator
	DateRuleEntry& operator=( const DateRuleEntry& iSrc );

	//! Copy constructor
	DateRuleEntry( const DateRuleEntry& original );
     
public:

	//! Set IsToday
	plmxml_api::Result SetIsToday( plmxml_api::logical arg );

	//! Get IsToday
	plmxml_api::logical GetIsToday() const;

	//! Check if IsToday is set
	plmxml_api::logical HasIsToday() const;

	//! Unset IsToday
	plmxml_api::Result UnsetIsToday();

	//! Get RefDate of this DateRuleEntry
	plmxml_api::String GetRefDate() const;

	//! Set RefDate of this DateRuleEntry
	plmxml_api::Result SetRefDate( const plmxml_api::String &s );
	
	//! Check if RefDate is set
	plmxml_api::logical HasRefDate( ) const;
	
	//! Unset RefDate
	plmxml_api::Result UnsetRefDate( );
 
// <PLMXML_UserCode type="functionHeaderDateRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDateRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! StatusRuleEntry class
/*!
\verbatim

      A RevisionRule Entry for selecting a Revision by its Release Status. 

      Attributes:

      status:           This specifies the required release status of the
                        Revision. It corresponds to the 'name' attribute of the
                        corresponding ReleaseStatus element. If 'status' has the
                        value "any", then any status is acceptable.
      type:             specifies whether the rule is to use the release date,
                        the effectivity dates, or the serial number range, in
                        the ReleaseStatus, when choosing an element. May use the
                        date or serial number from a DateRuleEntry or a
                        SerialNumberRuleEntry.
      statusRef:        References a multiple language version of status. If
                        multiple language support is required, statusRef should
                        be used in addition to status.
      
\endverbatim
*/
class PLMXML_PDM60_API StatusRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    StatusRuleEntry( );
     
    //! Constructs a StatusRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StatusRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StatusRuleEntry();

private:

	//! Assignment operator
	StatusRuleEntry& operator=( const StatusRuleEntry& iSrc );

	//! Copy constructor
	StatusRuleEntry( const StatusRuleEntry& original );
     
public:

	//! Get Status of this StatusRuleEntry
	plmxml_api::String GetStatus() const;

	//! Set Status of this StatusRuleEntry
	plmxml_api::Result SetStatus( const plmxml_api::String &s );
	
	//! Check if Status is set
	plmxml_api::logical HasStatus( ) const;
	
	//! Unset Status
	plmxml_api::Result UnsetStatus( );

	//! Set Type
	plmxml_api::Result SetType( const eStatusConfigType& arg );

	//! Get Type
	eStatusConfigType GetType() const;

	//! Get Status URI as plmxml_api::String
	plmxml_api::String GetStatusURI() const;

	//! Set Status URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStatusURI( const plmxml_api::String& );
	
	//! Get the handle of Status URI. Does not resolve the URI.
	plmxml_api::Result GetStatusURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Status URI. URI string is unchanged.
	plmxml_api::Result SetStatusURI( const plmxml_api::Handle& );
	
	//! Resolve Status URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStatusURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Status URI. Clears URI string and handle.
	plmxml_api::Result DeleteStatusURI();
	
	//! Check if Status URI is set
	plmxml_api::logical HasStatusURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderStatusRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassStatusRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! LatestWorkingRuleEntry class
/*!
\verbatim

      Latest Working Rule - select the most recent element with status Working
      (i.e. no ReleaseStatus).
      
\endverbatim
*/
class PLMXML_PDM60_API LatestWorkingRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    LatestWorkingRuleEntry( );
     
    //! Constructs a LatestWorkingRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LatestWorkingRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LatestWorkingRuleEntry();

private:

	//! Assignment operator
	LatestWorkingRuleEntry& operator=( const LatestWorkingRuleEntry& iSrc );

	//! Copy constructor
	LatestWorkingRuleEntry( const LatestWorkingRuleEntry& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderLatestWorkingRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassLatestWorkingRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! WorkingRuleEntry class
/*!
\verbatim

      Working Rule Entry - i.e. no Release Status, selecting by user or group.
      
      Attributes:
      
      userRef:         reference to User
      groupRef:        
      
      isCurrentUser:   if 'true', then select by the current user
      isCurrentGroup:  if 'true', then select by the current group.
      
\endverbatim
*/
class PLMXML_PDM60_API WorkingRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    WorkingRuleEntry( );
     
    //! Constructs a WorkingRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkingRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkingRuleEntry();

private:

	//! Assignment operator
	WorkingRuleEntry& operator=( const WorkingRuleEntry& iSrc );

	//! Copy constructor
	WorkingRuleEntry( const WorkingRuleEntry& original );
     
public:

	//! Get User URI as plmxml_api::String
	plmxml_api::String GetUserURI() const;

	//! Set User URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::String& );
	
	//! Get the handle of User URI. Does not resolve the URI.
	plmxml_api::Result GetUserURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of User URI. URI string is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::Handle& );
	
	//! Resolve User URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUserURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset User URI. Clears URI string and handle.
	plmxml_api::Result DeleteUserURI();
	
	//! Check if User URI is set
	plmxml_api::logical HasUserURI( ) const;
	

	//! Set IsCurrentUser
	plmxml_api::Result SetIsCurrentUser( plmxml_api::logical arg );

	//! Get IsCurrentUser
	plmxml_api::logical GetIsCurrentUser() const;

	//! Check if IsCurrentUser is set
	plmxml_api::logical HasIsCurrentUser() const;

	//! Unset IsCurrentUser
	plmxml_api::Result UnsetIsCurrentUser();

	//! Set IsCurrentGroup
	plmxml_api::Result SetIsCurrentGroup( plmxml_api::logical arg );

	//! Get IsCurrentGroup
	plmxml_api::logical GetIsCurrentGroup() const;

	//! Check if IsCurrentGroup is set
	plmxml_api::logical HasIsCurrentGroup() const;

	//! Unset IsCurrentGroup
	plmxml_api::Result UnsetIsCurrentGroup();

	//! Get Group URI as plmxml_api::String
	plmxml_api::String GetGroupURI() const;

	//! Set Group URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetGroupURI( const plmxml_api::String& );
	
	//! Get the handle of Group URI. Does not resolve the URI.
	plmxml_api::Result GetGroupURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Group URI. URI string is unchanged.
	plmxml_api::Result SetGroupURI( const plmxml_api::Handle& );
	
	//! Resolve Group URI and return an object (handle) it points to.
	plmxml_api::Result ResolveGroupURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Group URI. Clears URI string and handle.
	plmxml_api::Result DeleteGroupURI();
	
	//! Check if Group URI is set
	plmxml_api::logical HasGroupURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderWorkingRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassWorkingRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! LatestRuleEntry class
/*!
\verbatim

      Latest Rule Entry - i.e. most recent by creation date, numeric productId, 
      or alphanumeric productId.
      
\endverbatim
*/
class PLMXML_PDM60_API LatestRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    LatestRuleEntry( );
     
    //! Constructs a LatestRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LatestRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LatestRuleEntry();

private:

	//! Assignment operator
	LatestRuleEntry& operator=( const LatestRuleEntry& iSrc );

	//! Copy constructor
	LatestRuleEntry( const LatestRuleEntry& original );
     
public:

	//! Set ConfigType
	plmxml_api::Result SetConfigType( const eRevisionConfigType& arg );

	//! Get ConfigType
	eRevisionConfigType GetConfigType() const;
 
// <PLMXML_UserCode type="functionHeaderLatestRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassLatestRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! OverrideRuleEntry class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API OverrideRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    OverrideRuleEntry( );
     
    //! Constructs a OverrideRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OverrideRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OverrideRuleEntry();

private:

	//! Assignment operator
	OverrideRuleEntry& operator=( const OverrideRuleEntry& iSrc );

	//! Copy constructor
	OverrideRuleEntry( const OverrideRuleEntry& original );
     
public:

	//! Get OverrideFolder URI as plmxml_api::String
	plmxml_api::String GetOverrideFolderURI() const;

	//! Set OverrideFolder URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOverrideFolderURI( const plmxml_api::String& );
	
	//! Get the handle of OverrideFolder URI. Does not resolve the URI.
	plmxml_api::Result GetOverrideFolderURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of OverrideFolder URI. URI string is unchanged.
	plmxml_api::Result SetOverrideFolderURI( const plmxml_api::Handle& );
	
	//! Resolve OverrideFolder URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOverrideFolderURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset OverrideFolder URI. Clears URI string and handle.
	plmxml_api::Result DeleteOverrideFolderURI();
	
	//! Check if OverrideFolder URI is set
	plmxml_api::logical HasOverrideFolderURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderOverrideRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassOverrideRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! PreciseRuleEntry class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API PreciseRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    PreciseRuleEntry( );
     
    //! Constructs a PreciseRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PreciseRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PreciseRuleEntry();

private:

	//! Assignment operator
	PreciseRuleEntry& operator=( const PreciseRuleEntry& iSrc );

	//! Copy constructor
	PreciseRuleEntry( const PreciseRuleEntry& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPreciseRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassPreciseRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! SerialNumberRuleEntry class
/*!
\verbatim

      Specifies a Serial Number to be used by other Rule Entries.
      
\endverbatim
*/
class PLMXML_PDM60_API SerialNumberRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    SerialNumberRuleEntry( );
     
    //! Constructs a SerialNumberRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SerialNumberRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SerialNumberRuleEntry();

private:

	//! Assignment operator
	SerialNumberRuleEntry& operator=( const SerialNumberRuleEntry& iSrc );

	//! Copy constructor
	SerialNumberRuleEntry( const SerialNumberRuleEntry& original );
     
public:

	//! Get SerialNumber of this SerialNumberRuleEntry
	plmxml_api::String GetSerialNumber() const;

	//! Set SerialNumber of this SerialNumberRuleEntry
	plmxml_api::Result SetSerialNumber( const plmxml_api::String &s );
	
	//! Check if SerialNumber is set
	plmxml_api::logical HasSerialNumber( ) const;
	
	//! Unset SerialNumber
	plmxml_api::Result UnsetSerialNumber( );
 
// <PLMXML_UserCode type="functionHeaderSerialNumberRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassSerialNumberRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! ContextRuleEntry class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API ContextRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    ContextRuleEntry( );
     
    //! Constructs a ContextRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ContextRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ContextRuleEntry();

private:

	//! Assignment operator
	ContextRuleEntry& operator=( const ContextRuleEntry& iSrc );

	//! Copy constructor
	ContextRuleEntry( const ContextRuleEntry& original );
     
public:

	//! Get Context URI as plmxml_api::String
	plmxml_api::String GetContextURI() const;

	//! Set Context URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetContextURI( const plmxml_api::String& );
	
	//! Get the handle of Context URI. Does not resolve the URI.
	plmxml_api::Result GetContextURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Context URI. URI string is unchanged.
	plmxml_api::Result SetContextURI( const plmxml_api::Handle& );
	
	//! Resolve Context URI and return an object (handle) it points to.
	plmxml_api::Result ResolveContextURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Context URI. Clears URI string and handle.
	plmxml_api::Result DeleteContextURI();
	
	//! Check if Context URI is set
	plmxml_api::logical HasContextURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderContextRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassContextRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! GroupRuleEntry class
/*!
\verbatim

      This RuleEntry contains subordinate RuleEntries, which are of equal precedence.
      They are all processed; if there is at least one match, then the revision with the
      most recent creation date is configured.
      
      SubElements:
      
      RuleEntry:        Each sub-element is a subordinate RuleEntry. 
      
\endverbatim
*/
class PLMXML_PDM60_API GroupRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    GroupRuleEntry( );
     
    //! Constructs a GroupRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GroupRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GroupRuleEntry();

private:

	//! Assignment operator
	GroupRuleEntry& operator=( const GroupRuleEntry& iSrc );

	//! Copy constructor
	GroupRuleEntry( const GroupRuleEntry& original );
     
public:

	//! Add RuleEntry child element to this GroupRuleEntry. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RuleEntry *AddRuleEntry();
     
	//! Add 'arg' as RuleEntry child element to this GroupRuleEntry.
	plmxml_api::Result AddRuleEntry( RuleEntry *arg );

	//! Detach and delete all RuleEntry child elements.
	void DeleteRuleEntries();
     
	//! Get number of RuleEntry child elements.
	int NumberOfRuleEntries() const;
     
	//! Get i'th RuleEntry child element.
	RuleEntry *GetRuleEntry( int i ) const;
     
	//! Get all RuleEntry child element as an array
	void GetRuleEntries( plmxml_api::Array<RuleEntry*> &array ) const;
	     
	//! Detach and delete i'th RuleEntry child element
	void DeleteRuleEntry( int i );
     
	//! Detach and delete 'arg' if it's one of the RuleEntry child elements
	void DeleteRuleEntry( RuleEntry *arg );
 
// <PLMXML_UserCode type="functionHeaderGroupRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassGroupRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! GroupByTypeRuleEntry class
/*!
\verbatim

      This RuleEntry contains subordinate RuleEntries, and only applies to
      Structures or Occurrences with 'subType' attribute corresponding to one of
      a specified set of allowed types. The RuleEntry sub-elements are processed
      sequentially.

      Attributes:

      groupType:        The type of elements to which the GroupByTypeRuleEntry
                        applies.

      SubElements:

      AllowedType:      Each sub-element specifies an allowed 'subType'
      RuleEntry:        Each sub-element is a subordinate RuleEntry. Note that these
                        subordinate RuleEntries cannot be of type GroupByTypeRuleEntry.
      
\endverbatim
*/
class PLMXML_PDM60_API GroupByTypeRuleEntry : public RuleEntry
{
public:
     
    //! Default constructor
    GroupByTypeRuleEntry( );
     
    //! Constructs a GroupByTypeRuleEntry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GroupByTypeRuleEntry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GroupByTypeRuleEntry();

private:

	//! Assignment operator
	GroupByTypeRuleEntry& operator=( const GroupByTypeRuleEntry& iSrc );

	//! Copy constructor
	GroupByTypeRuleEntry( const GroupByTypeRuleEntry& original );
     
public:

	//! Set GroupType
	plmxml_api::Result SetGroupType( const eGroupTypeEnum& arg );

	//! Get GroupType
	eGroupTypeEnum GetGroupType() const;

	//! Add AllowedType child element to this GroupByTypeRuleEntry. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StringField *AddAllowedType();
     
	//! Add 'arg' as AllowedType child element to this GroupByTypeRuleEntry.
	plmxml_api::Result AddAllowedType( StringField *arg );

	//! Detach and delete all AllowedType child elements.
	void DeleteAllowedTypes();
     
	//! Get number of AllowedType child elements.
	int NumberOfAllowedTypes() const;
     
	//! Get i'th AllowedType child element.
	StringField *GetAllowedType( int i ) const;
     
	//! Get all AllowedType child element as an array
	void GetAllowedTypes( plmxml_api::Array<StringField*> &array ) const;
	     
	//! Detach and delete i'th AllowedType child element
	void DeleteAllowedType( int i );
     
	//! Detach and delete 'arg' if it's one of the AllowedType child elements
	void DeleteAllowedType( StringField *arg );

	//! Add RuleEntry child element to this GroupByTypeRuleEntry. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RuleEntry *AddRuleEntry();
     
	//! Add 'arg' as RuleEntry child element to this GroupByTypeRuleEntry.
	plmxml_api::Result AddRuleEntry( RuleEntry *arg );

	//! Detach and delete all RuleEntry child elements.
	void DeleteRuleEntries();
     
	//! Get number of RuleEntry child elements.
	int NumberOfRuleEntries() const;
     
	//! Get i'th RuleEntry child element.
	RuleEntry *GetRuleEntry( int i ) const;
     
	//! Get all RuleEntry child element as an array
	void GetRuleEntries( plmxml_api::Array<RuleEntry*> &array ) const;
	     
	//! Detach and delete i'th RuleEntry child element
	void DeleteRuleEntry( int i );
     
	//! Detach and delete 'arg' if it's one of the RuleEntry child elements
	void DeleteRuleEntry( RuleEntry *arg );
 
// <PLMXML_UserCode type="functionHeaderGroupByTypeRuleEntry" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassGroupByTypeRuleEntry;


////////////////////////////////////////////////////////////////////////////////////
//! RevisionRule class
/*!
\verbatim

      A Revision Rule is a rule specifying which Revisions of Structures should be
      configured.
      
      Sub-elements:
      
      RuleEntry:    the clauses (entries) in the Rule. They are applied sequentially.
      
\endverbatim
*/
class PLMXML_PDM60_API RevisionRule : public ConfigRule
{
public:
     
    //! Default constructor
    RevisionRule( );
     
    //! Constructs a RevisionRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RevisionRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RevisionRule();

private:

	//! Assignment operator
	RevisionRule& operator=( const RevisionRule& iSrc );

	//! Copy constructor
	RevisionRule( const RevisionRule& original );
     
public:

	//! Add RuleEntry child element to this RevisionRule. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RuleEntry *AddRuleEntry();
     
	//! Add 'arg' as RuleEntry child element to this RevisionRule.
	plmxml_api::Result AddRuleEntry( RuleEntry *arg );

	//! Detach and delete all RuleEntry child elements.
	void DeleteRuleEntries();
     
	//! Get number of RuleEntry child elements.
	int NumberOfRuleEntries() const;
     
	//! Get i'th RuleEntry child element.
	RuleEntry *GetRuleEntry( int i ) const;
     
	//! Get all RuleEntry child element as an array
	void GetRuleEntries( plmxml_api::Array<RuleEntry*> &array ) const;
	     
	//! Detach and delete i'th RuleEntry child element
	void DeleteRuleEntry( int i );
     
	//! Detach and delete 'arg' if it's one of the RuleEntry child elements
	void DeleteRuleEntry( RuleEntry *arg );
 
// <PLMXML_UserCode type="functionHeaderRevisionRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassRevisionRule;


////////////////////////////////////////////////////////////////////////////////////
//! Form class
/*!
\verbatim

      A Form is a way of associating additional freeform attributes with an element,
      effectively defining a subclass of element. (The subclass can be specified by
      means of the "subType" attribute on the element).
      
      The attributes are attached to the Form by using UserData. The Form is attached 
      to the element by means of an AssociatedForm element.
   
      Attributes:
      
      mainClass:          
      subClass:          
      
\endverbatim
*/
class PLMXML_PDM60_API Form : public Managed
{
public:
     
    //! Default constructor
    Form( );
     
    //! Constructs a Form with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Form( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Form();

private:

	//! Assignment operator
	Form& operator=( const Form& iSrc );

	//! Copy constructor
	Form( const Form& original );
     
public:

	//! Get SubClass of this Form
	plmxml_api::String GetSubClass() const;

	//! Set SubClass of this Form
	plmxml_api::Result SetSubClass( const plmxml_api::String &s );
	
	//! Check if SubClass is set
	plmxml_api::logical HasSubClass( ) const;
	
	//! Unset SubClass
	plmxml_api::Result UnsetSubClass( );

	//! Get MainClass of this Form
	plmxml_api::String GetMainClass() const;

	//! Set MainClass of this Form
	plmxml_api::Result SetMainClass( const plmxml_api::String &s );
	
	//! Check if MainClass is set
	plmxml_api::logical HasMainClass( ) const;
	
	//! Unset MainClass
	plmxml_api::Result UnsetMainClass( );
 
// <PLMXML_UserCode type="functionHeaderForm" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassForm;


////////////////////////////////////////////////////////////////////////////////////
//! Folder class
/*!
\verbatim

        A Folder is a general-purpose collection of other elements.
      
        Attributes:
      
        subType:        Inherited from ManagedBase. A string representing the sub-type of the Folder. The
                        string, "viewSet", is reserved for a set of Model Views in NX.
        folderContentRefs: The contents of the Folder. When the subType attribute is set to "viewSet",
                        folderContentsRefs references a list of ProductViews with their usage attributes
                        set to "modelView". The first reference in the list references the Base View.
      
\endverbatim
*/
class PLMXML_PDM60_API Folder : public Managed
{
public:
     
    //! Default constructor
    Folder( );
     
    //! Constructs a Folder with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Folder( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Folder();

private:

	//! Assignment operator
	Folder& operator=( const Folder& iSrc );

	//! Copy constructor
	Folder( const Folder& original );
     
public:

	//! Get number of URIs in FolderContent
	int NumberOfFolderContentURIs() const;

	//! Get i'th URI in FolderContent
	plmxml_api::String GetFolderContentURI( int i ) const;

	//! Add a URI to FolderContent array. Call ResolveFolderContentURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFolderContentURI( const plmxml_api::String& u );

	//! Set i'th URI in FolderContent array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFolderContentURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of FolderContent URI. Does not resolve the URI.
	plmxml_api::Result GetFolderContentURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to FolderContent array.
	plmxml_api::Result AddFolderContentURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in FolderContent array to point to 'handle'.
	plmxml_api::Result SetFolderContentURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in FolderContent points to.
	plmxml_api::Result ResolveFolderContentURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from FolderContent array.
	plmxml_api::Result DeleteFolderContentURI( int i );

	//! Remove all URIs from FolderContent array.
	plmxml_api::Result DeleteFolderContentURIs( );
	
	//! Check if FolderContent is set
	plmxml_api::logical HasFolderContentURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderFolder" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassFolder;


////////////////////////////////////////////////////////////////////////////////////
//! AssociatedFolder class
/*!
\verbatim

      plm:Attribute used to associate a Folder with a PLM XML element.

      Attributes:

      folderRef     reference to the Folder
      role          role/purpose of Folder.

      Sub-elements:

      UserData:         Represents user-definable properties on the
                        relationship.
      
\endverbatim
*/
class PLMXML_PDM60_API AssociatedFolder : public Attribute
{
public:
     
    //! Default constructor
    AssociatedFolder( );
     
    //! Constructs a AssociatedFolder with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AssociatedFolder( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AssociatedFolder();

private:

	//! Assignment operator
	AssociatedFolder& operator=( const AssociatedFolder& iSrc );

	//! Copy constructor
	AssociatedFolder( const AssociatedFolder& original );
     
public:

	//! Get Role of this AssociatedFolder
	plmxml_api::String GetRole() const;

	//! Set Role of this AssociatedFolder
	plmxml_api::Result SetRole( const plmxml_api::String &s );
	
	//! Check if Role is set
	plmxml_api::logical HasRole( ) const;
	
	//! Unset Role
	plmxml_api::Result UnsetRole( );

	//! Get Folder URI as plmxml_api::String
	plmxml_api::String GetFolderURI() const;

	//! Set Folder URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFolderURI( const plmxml_api::String& );
	
	//! Get the handle of Folder URI. Does not resolve the URI.
	plmxml_api::Result GetFolderURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Folder URI. URI string is unchanged.
	plmxml_api::Result SetFolderURI( const plmxml_api::Handle& );
	
	//! Resolve Folder URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFolderURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Folder URI. Clears URI string and handle.
	plmxml_api::Result DeleteFolderURI();
	
	//! Check if Folder URI is set
	plmxml_api::logical HasFolderURI( ) const;
	

	//! Add UserData child element to this AssociatedFolder. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData();
     
	//! Add 'arg' as UserData child element to this AssociatedFolder.
	plmxml_api::Result AddUserData( UserData *arg );

	//! Detach and delete all UserData child elements.
	void DeleteUserDatas();
     
	//! Get number of UserData child elements.
	int NumberOfUserDatas() const;
     
	//! Get i'th UserData child element.
	UserData *GetUserData( int i ) const;
     
	//! Get all UserData child element as an array
	void GetUserDatas( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData child element
	void DeleteUserData( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData child elements
	void DeleteUserData( UserData *arg );
 
// <PLMXML_UserCode type="functionHeaderAssociatedFolder" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassAssociatedFolder;


////////////////////////////////////////////////////////////////////////////////////
//! AssociatedForm class
/*!
\verbatim

      plm:Attribute used to associate a Form with a PLM XML element.

      Attributes:

      formRef      reference to the Form
      role         role/purpose of Form.    

      Sub-elements:

      UserData:         Represents user-definable properties on the
                        relationship.
      
\endverbatim
*/
class PLMXML_PDM60_API AssociatedForm : public Attribute
{
public:
     
    //! Default constructor
    AssociatedForm( );
     
    //! Constructs a AssociatedForm with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AssociatedForm( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AssociatedForm();

private:

	//! Assignment operator
	AssociatedForm& operator=( const AssociatedForm& iSrc );

	//! Copy constructor
	AssociatedForm( const AssociatedForm& original );
     
public:

	//! Get Role of this AssociatedForm
	plmxml_api::String GetRole() const;

	//! Set Role of this AssociatedForm
	plmxml_api::Result SetRole( const plmxml_api::String &s );
	
	//! Check if Role is set
	plmxml_api::logical HasRole( ) const;
	
	//! Unset Role
	plmxml_api::Result UnsetRole( );

	//! Get Form URI as plmxml_api::String
	plmxml_api::String GetFormURI() const;

	//! Set Form URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFormURI( const plmxml_api::String& );
	
	//! Get the handle of Form URI. Does not resolve the URI.
	plmxml_api::Result GetFormURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Form URI. URI string is unchanged.
	plmxml_api::Result SetFormURI( const plmxml_api::Handle& );
	
	//! Resolve Form URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFormURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Form URI. Clears URI string and handle.
	plmxml_api::Result DeleteFormURI();
	
	//! Check if Form URI is set
	plmxml_api::logical HasFormURI( ) const;
	

	//! Add UserData child element to this AssociatedForm. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData();
     
	//! Add 'arg' as UserData child element to this AssociatedForm.
	plmxml_api::Result AddUserData( UserData *arg );

	//! Detach and delete all UserData child elements.
	void DeleteUserDatas();
     
	//! Get number of UserData child elements.
	int NumberOfUserDatas() const;
     
	//! Get i'th UserData child element.
	UserData *GetUserData( int i ) const;
     
	//! Get all UserData child element as an array
	void GetUserDatas( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData child element
	void DeleteUserData( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData child elements
	void DeleteUserData( UserData *arg );
 
// <PLMXML_UserCode type="functionHeaderAssociatedForm" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassAssociatedForm;


////////////////////////////////////////////////////////////////////////////////////
//! IdContext class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API IdContext : public Managed
{
public:
     
    //! Default constructor
    IdContext( );
     
    //! Constructs a IdContext with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IdContext( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IdContext();

private:

	//! Assignment operator
	IdContext& operator=( const IdContext& iSrc );

	//! Copy constructor
	IdContext( const IdContext& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderIdContext" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassIdContext;


////////////////////////////////////////////////////////////////////////////////////
//! Identifier class
/*!
\verbatim

      This defines an alternative id for an element, in some context.

      Attributes:

      identifierId:     the alternative id.
      idContext:        a context string
      supplementalContext: a list of context elements, such as Organisations
      alternativeIdOf:  a list of elements that this is an id of
      isDispDefault:    true if this is the id to display by default when
                        displaying the identified element.
      idContextRef:     References a multiple language version of idContext. If
                        multiple language support is required, idContextRef
                        should be used in addition to idContext.
      
\endverbatim
*/
class PLMXML_PDM60_API Identifier : public Managed
{
public:
     
    //! Default constructor
    Identifier( );
     
    //! Constructs a Identifier with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Identifier( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Identifier();

private:

	//! Assignment operator
	Identifier& operator=( const Identifier& iSrc );

	//! Copy constructor
	Identifier( const Identifier& original );
     
public:

	//! Get IdContext of this Identifier
	plmxml_api::String GetIdContext() const;

	//! Set IdContext of this Identifier
	plmxml_api::Result SetIdContext( const plmxml_api::String &s );
	
	//! Check if IdContext is set
	plmxml_api::logical HasIdContext( ) const;
	
	//! Unset IdContext
	plmxml_api::Result UnsetIdContext( );

	//! Get number of URIs in SupplementalContext
	int NumberOfSupplementalContextURIs() const;

	//! Get i'th URI in SupplementalContext
	plmxml_api::String GetSupplementalContextURI( int i ) const;

	//! Add a URI to SupplementalContext array. Call ResolveSupplementalContextURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSupplementalContextURI( const plmxml_api::String& u );

	//! Set i'th URI in SupplementalContext array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSupplementalContextURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SupplementalContext URI. Does not resolve the URI.
	plmxml_api::Result GetSupplementalContextURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SupplementalContext array.
	plmxml_api::Result AddSupplementalContextURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SupplementalContext array to point to 'handle'.
	plmxml_api::Result SetSupplementalContextURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SupplementalContext points to.
	plmxml_api::Result ResolveSupplementalContextURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SupplementalContext array.
	plmxml_api::Result DeleteSupplementalContextURI( int i );

	//! Remove all URIs from SupplementalContext array.
	plmxml_api::Result DeleteSupplementalContextURIs( );
	
	//! Check if SupplementalContext is set
	plmxml_api::logical HasSupplementalContextURIs( ) const;

	//! Get number of URIs in AlternateIdOf
	int NumberOfAlternateIdOfURIs() const;

	//! Get i'th URI in AlternateIdOf
	plmxml_api::String GetAlternateIdOfURI( int i ) const;

	//! Add a URI to AlternateIdOf array. Call ResolveAlternateIdOfURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAlternateIdOfURI( const plmxml_api::String& u );

	//! Set i'th URI in AlternateIdOf array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAlternateIdOfURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of AlternateIdOf URI. Does not resolve the URI.
	plmxml_api::Result GetAlternateIdOfURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to AlternateIdOf array.
	plmxml_api::Result AddAlternateIdOfURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in AlternateIdOf array to point to 'handle'.
	plmxml_api::Result SetAlternateIdOfURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in AlternateIdOf points to.
	plmxml_api::Result ResolveAlternateIdOfURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from AlternateIdOf array.
	plmxml_api::Result DeleteAlternateIdOfURI( int i );

	//! Remove all URIs from AlternateIdOf array.
	plmxml_api::Result DeleteAlternateIdOfURIs( );
	
	//! Check if AlternateIdOf is set
	plmxml_api::logical HasAlternateIdOfURIs( ) const;

	//! Get IdentifierId of this Identifier
	plmxml_api::String GetIdentifierId() const;

	//! Set IdentifierId of this Identifier
	plmxml_api::Result SetIdentifierId( const plmxml_api::String &s );
	
	//! Check if IdentifierId is set
	plmxml_api::logical HasIdentifierId( ) const;
	
	//! Unset IdentifierId
	plmxml_api::Result UnsetIdentifierId( );

	//! Get IdContext URI as plmxml_api::String
	plmxml_api::String GetIdContextURI() const;

	//! Set IdContext URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetIdContextURI( const plmxml_api::String& );
	
	//! Get the handle of IdContext URI. Does not resolve the URI.
	plmxml_api::Result GetIdContextURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of IdContext URI. URI string is unchanged.
	plmxml_api::Result SetIdContextURI( const plmxml_api::Handle& );
	
	//! Resolve IdContext URI and return an object (handle) it points to.
	plmxml_api::Result ResolveIdContextURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset IdContext URI. Clears URI string and handle.
	plmxml_api::Result DeleteIdContextURI();
	
	//! Check if IdContext URI is set
	plmxml_api::logical HasIdContextURI( ) const;
	

	//! Set IsDispDefault
	plmxml_api::Result SetIsDispDefault( plmxml_api::logical arg );

	//! Get IsDispDefault
	plmxml_api::logical GetIsDispDefault() const;

	//! Check if IsDispDefault is set
	plmxml_api::logical HasIsDispDefault() const;

	//! Unset IsDispDefault
	plmxml_api::Result UnsetIsDispDefault();
 
// <PLMXML_UserCode type="functionHeaderIdentifier" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassIdentifier;


////////////////////////////////////////////////////////////////////////////////////
//! Project class
/*!
\verbatim

      Identifies a group of people or organizations, such as project teams,
      development teams, suppliers or customers, for a particular piece of work.

      Attributes:

      projectId:        The identifier for the project.
      team:             A list of references to the OrganisationMember or
                        Organisation elements that constitute the project team.
      active:           Whether the Project is active.
      visible:          When active is false, visible determines whether the
                        Project remains visible.
      useProjectSecurity: Whether an OrganisationMember or Organisation can gain
                        access to an element by virtue of its membership of the
                        Project.
      
\endverbatim
*/
class PLMXML_PDM60_API Project : public Managed
{
public:
     
    //! Default constructor
    Project( );
     
    //! Constructs a Project with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Project( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Project();

private:

	//! Assignment operator
	Project& operator=( const Project& iSrc );

	//! Copy constructor
	Project( const Project& original );
     
public:

	//! Set Visible
	plmxml_api::Result SetVisible( plmxml_api::logical arg );

	//! Get Visible
	plmxml_api::logical GetVisible() const;

	//! Check if Visible is set
	plmxml_api::logical HasVisible() const;

	//! Unset Visible
	plmxml_api::Result UnsetVisible();

	//! Set Active
	plmxml_api::Result SetActive( plmxml_api::logical arg );

	//! Get Active
	plmxml_api::logical GetActive() const;

	//! Check if Active is set
	plmxml_api::logical HasActive() const;

	//! Unset Active
	plmxml_api::Result UnsetActive();

	//! Set UseProjectSecurity
	plmxml_api::Result SetUseProjectSecurity( plmxml_api::logical arg );

	//! Get UseProjectSecurity
	plmxml_api::logical GetUseProjectSecurity() const;

	//! Check if UseProjectSecurity is set
	plmxml_api::logical HasUseProjectSecurity() const;

	//! Unset UseProjectSecurity
	plmxml_api::Result UnsetUseProjectSecurity();

	//! Get ProjectId of this Project
	plmxml_api::String GetProjectId() const;

	//! Set ProjectId of this Project
	plmxml_api::Result SetProjectId( const plmxml_api::String &s );
	
	//! Check if ProjectId is set
	plmxml_api::logical HasProjectId( ) const;
	
	//! Unset ProjectId
	plmxml_api::Result UnsetProjectId( );

	//! Get number of URIs in Team
	int NumberOfTeamURIs() const;

	//! Get i'th URI in Team
	plmxml_api::String GetTeamURI( int i ) const;

	//! Add a URI to Team array. Call ResolveTeamURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTeamURI( const plmxml_api::String& u );

	//! Set i'th URI in Team array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTeamURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Team URI. Does not resolve the URI.
	plmxml_api::Result GetTeamURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Team array.
	plmxml_api::Result AddTeamURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Team array to point to 'handle'.
	plmxml_api::Result SetTeamURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Team points to.
	plmxml_api::Result ResolveTeamURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Team array.
	plmxml_api::Result DeleteTeamURI( int i );

	//! Remove all URIs from Team array.
	plmxml_api::Result DeleteTeamURIs( );
	
	//! Check if Team is set
	plmxml_api::logical HasTeamURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderProject" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassProject;


////////////////////////////////////////////////////////////////////////////////////
//! Vault class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API Vault : public AttribOwner
{
public:
     
    //! Default constructor
    Vault( );
     
    //! Constructs a Vault with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Vault( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Vault();

private:

	//! Assignment operator
	Vault& operator=( const Vault& iSrc );

	//! Copy constructor
	Vault( const Vault& original );
     
public:

	//! Get ShadowPath of this Vault
	plmxml_api::String GetShadowPath() const;

	//! Set ShadowPath of this Vault
	plmxml_api::Result SetShadowPath( const plmxml_api::String &s );
	
	//! Check if ShadowPath is set
	plmxml_api::logical HasShadowPath( ) const;
	
	//! Unset ShadowPath
	plmxml_api::Result UnsetShadowPath( );

	//! Get Path of this Vault
	plmxml_api::String GetPath() const;

	//! Set Path of this Vault
	plmxml_api::Result SetPath( const plmxml_api::String &s );
	
	//! Check if Path is set
	plmxml_api::logical HasPath( ) const;
	
	//! Unset Path
	plmxml_api::Result UnsetPath( );

	//! Get ShadowNodeName of this Vault
	plmxml_api::String GetShadowNodeName() const;

	//! Set ShadowNodeName of this Vault
	plmxml_api::Result SetShadowNodeName( const plmxml_api::String &s );
	
	//! Check if ShadowNodeName is set
	plmxml_api::logical HasShadowNodeName( ) const;
	
	//! Unset ShadowNodeName
	plmxml_api::Result UnsetShadowNodeName( );

	//! Set ShadowMachineType
	plmxml_api::Result SetShadowMachineType( const eMachineTypesType& arg );

	//! Get ShadowMachineType
	eMachineTypesType GetShadowMachineType() const;

	//! Set MachineType
	plmxml_api::Result SetMachineType( const eMachineTypesType& arg );

	//! Get MachineType
	eMachineTypesType GetMachineType() const;

	//! Get NodeName of this Vault
	plmxml_api::String GetNodeName() const;

	//! Set NodeName of this Vault
	plmxml_api::Result SetNodeName( const plmxml_api::String &s );
	
	//! Check if NodeName is set
	plmxml_api::logical HasNodeName( ) const;
	
	//! Unset NodeName
	plmxml_api::Result UnsetNodeName( );
 
// <PLMXML_UserCode type="functionHeaderVault" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassVault;


////////////////////////////////////////////////////////////////////////////////////
//! ClosureRuleClause class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API ClosureRuleClause : public plmxml_api::Object
{
public:
     
    //! Default constructor
    ClosureRuleClause( );
     
    //! Constructs a ClosureRuleClause with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClosureRuleClause( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClosureRuleClause();

private:

	//! Assignment operator
	ClosureRuleClause& operator=( const ClosureRuleClause& iSrc );

	//! Copy constructor
	ClosureRuleClause( const ClosureRuleClause& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderClosureRuleClause" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassClosureRuleClause;


////////////////////////////////////////////////////////////////////////////////////
//! ClosureRule class
/*!
\verbatim

      ClosureRule is used to define what type of associated data gets exported. It consists
      of a sequence of clauses, each one defining a primary class, a secondary class,
      a relation, and an action. It is used to drive a traversal process.

      Attributes:

      scope:       PLMXML or application
      searchCriteriaRef: References a 4GD Search Criteria.

      Sub-Elements:

      Clause:      Closure rule clause in string form, e.g.
                   "CLASS.*:CLASS.*:ATTRIBUTE.*:TRAVERSE_AND_PROCESS"
      
\endverbatim
*/
class PLMXML_PDM60_API ClosureRule : public ConfigRule
{
public:
     
    //! Default constructor
    ClosureRule( );
     
    //! Constructs a ClosureRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClosureRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClosureRule();

private:

	//! Assignment operator
	ClosureRule& operator=( const ClosureRule& iSrc );

	//! Copy constructor
	ClosureRule( const ClosureRule& original );
     
public:

	//! Get SearchCriteria URI as plmxml_api::String
	plmxml_api::String GetSearchCriteriaURI() const;

	//! Set SearchCriteria URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSearchCriteriaURI( const plmxml_api::String& );
	
	//! Get the handle of SearchCriteria URI. Does not resolve the URI.
	plmxml_api::Result GetSearchCriteriaURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of SearchCriteria URI. URI string is unchanged.
	plmxml_api::Result SetSearchCriteriaURI( const plmxml_api::Handle& );
	
	//! Resolve SearchCriteria URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSearchCriteriaURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset SearchCriteria URI. Clears URI string and handle.
	plmxml_api::Result DeleteSearchCriteriaURI();
	
	//! Check if SearchCriteria URI is set
	plmxml_api::logical HasSearchCriteriaURI( ) const;
	

	//! Set Scope
	plmxml_api::Result SetScope( const eClosureRuleScopeType& arg );

	//! Get Scope
	eClosureRuleScopeType GetScope() const;

	//! Add Clause child element to this ClosureRule. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ClosureRuleClause *AddClause();
     
	//! Add 'arg' as Clause child element to this ClosureRule.
	plmxml_api::Result AddClause( ClosureRuleClause *arg );

	//! Detach and delete all Clause child elements.
	void DeleteClauses();
     
	//! Get number of Clause child elements.
	int NumberOfClauses() const;
     
	//! Get i'th Clause child element.
	ClosureRuleClause *GetClause( int i ) const;
     
	//! Get all Clause child element as an array
	void GetClauses( plmxml_api::Array<ClosureRuleClause*> &array ) const;
	     
	//! Detach and delete i'th Clause child element
	void DeleteClause( int i );
     
	//! Detach and delete 'arg' if it's one of the Clause child elements
	void DeleteClause( ClosureRuleClause *arg );
 
// <PLMXML_UserCode type="functionHeaderClosureRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassClosureRule;


////////////////////////////////////////////////////////////////////////////////////
//! ConfigurationRule class
/*!
\verbatim

      This element defines a configuration rule by referencing closure rule, 
      variant rule and revision rule.
      
      Attributes:
      
      closureRuleRef:    reference to a ClosureRule
      variantRuleRef:    reference to a VariantRule
      revisionRuleRef:   reference to a RevisionRule
      
\endverbatim
*/
class PLMXML_PDM60_API ConfigurationRule : public AttribOwner
{
public:
     
    //! Default constructor
    ConfigurationRule( );
     
    //! Constructs a ConfigurationRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConfigurationRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConfigurationRule();

private:

	//! Assignment operator
	ConfigurationRule& operator=( const ConfigurationRule& iSrc );

	//! Copy constructor
	ConfigurationRule( const ConfigurationRule& original );
     
public:

	//! Get RevisionRule URI as plmxml_api::String
	plmxml_api::String GetRevisionRuleURI() const;

	//! Set RevisionRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRevisionRuleURI( const plmxml_api::String& );
	
	//! Get the handle of RevisionRule URI. Does not resolve the URI.
	plmxml_api::Result GetRevisionRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of RevisionRule URI. URI string is unchanged.
	plmxml_api::Result SetRevisionRuleURI( const plmxml_api::Handle& );
	
	//! Resolve RevisionRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRevisionRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset RevisionRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteRevisionRuleURI();
	
	//! Check if RevisionRule URI is set
	plmxml_api::logical HasRevisionRuleURI( ) const;
	

	//! Get ClosureRule URI as plmxml_api::String
	plmxml_api::String GetClosureRuleURI() const;

	//! Set ClosureRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetClosureRuleURI( const plmxml_api::String& );
	
	//! Get the handle of ClosureRule URI. Does not resolve the URI.
	plmxml_api::Result GetClosureRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ClosureRule URI. URI string is unchanged.
	plmxml_api::Result SetClosureRuleURI( const plmxml_api::Handle& );
	
	//! Resolve ClosureRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveClosureRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ClosureRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteClosureRuleURI();
	
	//! Check if ClosureRule URI is set
	plmxml_api::logical HasClosureRuleURI( ) const;
	

	//! Get VariantRule URI as plmxml_api::String
	plmxml_api::String GetVariantRuleURI() const;

	//! Set VariantRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetVariantRuleURI( const plmxml_api::String& );
	
	//! Get the handle of VariantRule URI. Does not resolve the URI.
	plmxml_api::Result GetVariantRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of VariantRule URI. URI string is unchanged.
	plmxml_api::Result SetVariantRuleURI( const plmxml_api::Handle& );
	
	//! Resolve VariantRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveVariantRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset VariantRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteVariantRuleURI();
	
	//! Check if VariantRule URI is set
	plmxml_api::logical HasVariantRuleURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderConfigurationRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassConfigurationRule;


////////////////////////////////////////////////////////////////////////////////////
//! StructureContext class
/*!
\verbatim

      StructureContext is used to group together all the objects that the user 
      would like to treat as a project for analysis.
      
      Attributes:
      
      configurationRuleRef: configurationRule for this element.
      
      structureRefs:             
      structureRevisionRefs:           
      occurrenceRefs:             
      managedRefs:            
      
\endverbatim
*/
class PLMXML_PDM60_API StructureContext : public Managed
{
public:
     
    //! Default constructor
    StructureContext( );
     
    //! Constructs a StructureContext with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StructureContext( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StructureContext();

private:

	//! Assignment operator
	StructureContext& operator=( const StructureContext& iSrc );

	//! Copy constructor
	StructureContext( const StructureContext& original );
     
public:

	//! Get number of URIs in Managed
	int NumberOfManagedURIs() const;

	//! Get i'th URI in Managed
	plmxml_api::String GetManagedURI( int i ) const;

	//! Add a URI to Managed array. Call ResolveManagedURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddManagedURI( const plmxml_api::String& u );

	//! Set i'th URI in Managed array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetManagedURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Managed URI. Does not resolve the URI.
	plmxml_api::Result GetManagedURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Managed array.
	plmxml_api::Result AddManagedURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Managed array to point to 'handle'.
	plmxml_api::Result SetManagedURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Managed points to.
	plmxml_api::Result ResolveManagedURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Managed array.
	plmxml_api::Result DeleteManagedURI( int i );

	//! Remove all URIs from Managed array.
	plmxml_api::Result DeleteManagedURIs( );
	
	//! Check if Managed is set
	plmxml_api::logical HasManagedURIs( ) const;

	//! Get ConfigurationRule URI as plmxml_api::String
	plmxml_api::String GetConfigurationRuleURI() const;

	//! Set ConfigurationRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetConfigurationRuleURI( const plmxml_api::String& );
	
	//! Get the handle of ConfigurationRule URI. Does not resolve the URI.
	plmxml_api::Result GetConfigurationRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ConfigurationRule URI. URI string is unchanged.
	plmxml_api::Result SetConfigurationRuleURI( const plmxml_api::Handle& );
	
	//! Resolve ConfigurationRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveConfigurationRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ConfigurationRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteConfigurationRuleURI();
	
	//! Check if ConfigurationRule URI is set
	plmxml_api::logical HasConfigurationRuleURI( ) const;
	

	//! Get number of URIs in StructureRevision
	int NumberOfStructureRevisionURIs() const;

	//! Get i'th URI in StructureRevision
	plmxml_api::String GetStructureRevisionURI( int i ) const;

	//! Add a URI to StructureRevision array. Call ResolveStructureRevisionURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddStructureRevisionURI( const plmxml_api::String& u );

	//! Set i'th URI in StructureRevision array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetStructureRevisionURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of StructureRevision URI. Does not resolve the URI.
	plmxml_api::Result GetStructureRevisionURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to StructureRevision array.
	plmxml_api::Result AddStructureRevisionURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in StructureRevision array to point to 'handle'.
	plmxml_api::Result SetStructureRevisionURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in StructureRevision points to.
	plmxml_api::Result ResolveStructureRevisionURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from StructureRevision array.
	plmxml_api::Result DeleteStructureRevisionURI( int i );

	//! Remove all URIs from StructureRevision array.
	plmxml_api::Result DeleteStructureRevisionURIs( );
	
	//! Check if StructureRevision is set
	plmxml_api::logical HasStructureRevisionURIs( ) const;

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

	//! Get number of URIs in Occurrence
	int NumberOfOccurrenceURIs() const;

	//! Get i'th URI in Occurrence
	plmxml_api::String GetOccurrenceURI( int i ) const;

	//! Add a URI to Occurrence array. Call ResolveOccurrenceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddOccurrenceURI( const plmxml_api::String& u );

	//! Set i'th URI in Occurrence array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetOccurrenceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Occurrence URI. Does not resolve the URI.
	plmxml_api::Result GetOccurrenceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Occurrence array.
	plmxml_api::Result AddOccurrenceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Occurrence array to point to 'handle'.
	plmxml_api::Result SetOccurrenceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Occurrence points to.
	plmxml_api::Result ResolveOccurrenceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Occurrence array.
	plmxml_api::Result DeleteOccurrenceURI( int i );

	//! Remove all URIs from Occurrence array.
	plmxml_api::Result DeleteOccurrenceURIs( );
	
	//! Check if Occurrence is set
	plmxml_api::logical HasOccurrenceURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderStructureContext" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassStructureContext;


////////////////////////////////////////////////////////////////////////////////////
//! CollaborationContext class
/*!
\verbatim

      CollaborationContext is used to group together several StructureContext elements,
      and a default configuration rule.
        
      Attributes:
    
      currentContextRef:    The current StructureContext.
      configurationRuleRef: configuration rule for this element.
      structureContextRefs: References to StructureContextRefs.
      managedRefs:          references to attachments.
      
\endverbatim
*/
class PLMXML_PDM60_API CollaborationContext : public Managed
{
public:
     
    //! Default constructor
    CollaborationContext( );
     
    //! Constructs a CollaborationContext with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CollaborationContext( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CollaborationContext();

private:

	//! Assignment operator
	CollaborationContext& operator=( const CollaborationContext& iSrc );

	//! Copy constructor
	CollaborationContext( const CollaborationContext& original );
     
public:

	//! Get number of URIs in Managed
	int NumberOfManagedURIs() const;

	//! Get i'th URI in Managed
	plmxml_api::String GetManagedURI( int i ) const;

	//! Add a URI to Managed array. Call ResolveManagedURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddManagedURI( const plmxml_api::String& u );

	//! Set i'th URI in Managed array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetManagedURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Managed URI. Does not resolve the URI.
	plmxml_api::Result GetManagedURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Managed array.
	plmxml_api::Result AddManagedURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Managed array to point to 'handle'.
	plmxml_api::Result SetManagedURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Managed points to.
	plmxml_api::Result ResolveManagedURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Managed array.
	plmxml_api::Result DeleteManagedURI( int i );

	//! Remove all URIs from Managed array.
	plmxml_api::Result DeleteManagedURIs( );
	
	//! Check if Managed is set
	plmxml_api::logical HasManagedURIs( ) const;

	//! Get ConfigurationRule URI as plmxml_api::String
	plmxml_api::String GetConfigurationRuleURI() const;

	//! Set ConfigurationRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetConfigurationRuleURI( const plmxml_api::String& );
	
	//! Get the handle of ConfigurationRule URI. Does not resolve the URI.
	plmxml_api::Result GetConfigurationRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ConfigurationRule URI. URI string is unchanged.
	plmxml_api::Result SetConfigurationRuleURI( const plmxml_api::Handle& );
	
	//! Resolve ConfigurationRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveConfigurationRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ConfigurationRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteConfigurationRuleURI();
	
	//! Check if ConfigurationRule URI is set
	plmxml_api::logical HasConfigurationRuleURI( ) const;
	

	//! Get number of URIs in StructureContext
	int NumberOfStructureContextURIs() const;

	//! Get i'th URI in StructureContext
	plmxml_api::String GetStructureContextURI( int i ) const;

	//! Add a URI to StructureContext array. Call ResolveStructureContextURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddStructureContextURI( const plmxml_api::String& u );

	//! Set i'th URI in StructureContext array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetStructureContextURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of StructureContext URI. Does not resolve the URI.
	plmxml_api::Result GetStructureContextURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to StructureContext array.
	plmxml_api::Result AddStructureContextURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in StructureContext array to point to 'handle'.
	plmxml_api::Result SetStructureContextURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in StructureContext points to.
	plmxml_api::Result ResolveStructureContextURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from StructureContext array.
	plmxml_api::Result DeleteStructureContextURI( int i );

	//! Remove all URIs from StructureContext array.
	plmxml_api::Result DeleteStructureContextURIs( );
	
	//! Check if StructureContext is set
	plmxml_api::logical HasStructureContextURIs( ) const;

	//! Get CurrentContext URI as plmxml_api::String
	plmxml_api::String GetCurrentContextURI() const;

	//! Set CurrentContext URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCurrentContextURI( const plmxml_api::String& );
	
	//! Get the handle of CurrentContext URI. Does not resolve the URI.
	plmxml_api::Result GetCurrentContextURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of CurrentContext URI. URI string is unchanged.
	plmxml_api::Result SetCurrentContextURI( const plmxml_api::Handle& );
	
	//! Resolve CurrentContext URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCurrentContextURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset CurrentContext URI. Clears URI string and handle.
	plmxml_api::Result DeleteCurrentContextURI();
	
	//! Check if CurrentContext URI is set
	plmxml_api::logical HasCurrentContextURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderCollaborationContext" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassCollaborationContext;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationChecker class
/*!
\verbatim

      This element gives the result of a Validation Check performed on an
      object.

      Attributes:

      name:             name of the check
      result:           true if check passed, false if failed
      status:           an integer return code from the check
      comments:         a comment string
      adHoc:            true if the validation is ad-hoc.
      reportRef:        URI of the validation report file.
      nameRef:          References a multiple language version of name. If
                        multiple language support is required, nameRef should be
                        used in addition to name.
      commentsRef:      References a multiple language version of comments. If
                        multiple language support is required, commentsRef
                        should be used in addition to comments.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationChecker : public plmxml_api::Object
{
public:
     
    //! Default constructor
    ValidationChecker( );
     
    //! Constructs a ValidationChecker with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationChecker( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationChecker();

private:

	//! Assignment operator
	ValidationChecker& operator=( const ValidationChecker& iSrc );

	//! Copy constructor
	ValidationChecker( const ValidationChecker& original );
     
public:

	//! Set AdHoc
	plmxml_api::Result SetAdHoc( plmxml_api::logical arg );

	//! Get AdHoc
	plmxml_api::logical GetAdHoc() const;

	//! Check if AdHoc is set
	plmxml_api::logical HasAdHoc() const;

	//! Unset AdHoc
	plmxml_api::Result UnsetAdHoc();

	//! Get Report URI as plmxml_api::String
	plmxml_api::String GetReportURI() const;

	//! Set Report URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReportURI( const plmxml_api::String& );
	
	//! Get the handle of Report URI. Does not resolve the URI.
	plmxml_api::Result GetReportURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Report URI. URI string is unchanged.
	plmxml_api::Result SetReportURI( const plmxml_api::Handle& );
	
	//! Resolve Report URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReportURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Report URI. Clears URI string and handle.
	plmxml_api::Result DeleteReportURI();
	
	//! Check if Report URI is set
	plmxml_api::logical HasReportURI( ) const;
	

	//! Get Name URI as plmxml_api::String
	plmxml_api::String GetNameURI() const;

	//! Set Name URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetNameURI( const plmxml_api::String& );
	
	//! Get the handle of Name URI. Does not resolve the URI.
	plmxml_api::Result GetNameURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Name URI. URI string is unchanged.
	plmxml_api::Result SetNameURI( const plmxml_api::Handle& );
	
	//! Resolve Name URI and return an object (handle) it points to.
	plmxml_api::Result ResolveNameURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Name URI. Clears URI string and handle.
	plmxml_api::Result DeleteNameURI();
	
	//! Check if Name URI is set
	plmxml_api::logical HasNameURI( ) const;
	

	//! Get Comments URI as plmxml_api::String
	plmxml_api::String GetCommentsURI() const;

	//! Set Comments URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCommentsURI( const plmxml_api::String& );
	
	//! Get the handle of Comments URI. Does not resolve the URI.
	plmxml_api::Result GetCommentsURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Comments URI. URI string is unchanged.
	plmxml_api::Result SetCommentsURI( const plmxml_api::Handle& );
	
	//! Resolve Comments URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCommentsURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Comments URI. Clears URI string and handle.
	plmxml_api::Result DeleteCommentsURI();
	
	//! Check if Comments URI is set
	plmxml_api::logical HasCommentsURI( ) const;
	

	//! Get Name of this ValidationChecker
	plmxml_api::String GetName() const;

	//! Set Name of this ValidationChecker
	plmxml_api::Result SetName( const plmxml_api::String &s );
	
	//! Check if Name is set
	plmxml_api::logical HasName( ) const;
	
	//! Unset Name
	plmxml_api::Result UnsetName( );

	//! Get Comments of this ValidationChecker
	plmxml_api::String GetComments() const;

	//! Set Comments of this ValidationChecker
	plmxml_api::Result SetComments( const plmxml_api::String &s );
	
	//! Check if Comments is set
	plmxml_api::logical HasComments( ) const;
	
	//! Unset Comments
	plmxml_api::Result UnsetComments( );

	//! Set Status
	plmxml_api::Result SetStatus( int arg );
     
	//! Get Status
	int GetStatus() const;
     
	//! Check if Status is set
	plmxml_api::logical HasStatus() const;
     
	//! Unset Status
	plmxml_api::Result UnsetStatus();

	//! Set Result
	plmxml_api::Result SetResult( plmxml_api::logical arg );

	//! Get Result
	plmxml_api::logical GetResult() const;

	//! Check if Result is set
	plmxml_api::logical HasResult() const;

	//! Unset Result
	plmxml_api::Result UnsetResult();
 
// <PLMXML_UserCode type="functionHeaderValidationChecker" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationChecker;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationResults class
/*!
\verbatim

      This element, derived from plm:Attribute, is used to give the results of applying
      a validation check to its parent element.

      Attributes:

      application:      the validating application

      Sub-elements:

      Checker:          the name and result of each check performed
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationResults : public Attribute
{
public:
     
    //! Default constructor
    ValidationResults( );
     
    //! Constructs a ValidationResults with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationResults( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationResults();

private:

	//! Assignment operator
	ValidationResults& operator=( const ValidationResults& iSrc );

	//! Copy constructor
	ValidationResults( const ValidationResults& original );
     
public:

	//! Get Application of this ValidationResults
	plmxml_api::String GetApplication() const;

	//! Set Application of this ValidationResults
	plmxml_api::Result SetApplication( const plmxml_api::String &s );
	
	//! Check if Application is set
	plmxml_api::logical HasApplication( ) const;
	
	//! Unset Application
	plmxml_api::Result UnsetApplication( );

	//! Add Checker child element to this ValidationResults. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValidationChecker *AddChecker();
     
	//! Add 'arg' as Checker child element to this ValidationResults.
	plmxml_api::Result AddChecker( ValidationChecker *arg );

	//! Detach and delete all Checker child elements.
	void DeleteCheckers();
     
	//! Get number of Checker child elements.
	int NumberOfCheckers() const;
     
	//! Get i'th Checker child element.
	ValidationChecker *GetChecker( int i ) const;
     
	//! Get all Checker child element as an array
	void GetCheckers( plmxml_api::Array<ValidationChecker*> &array ) const;
	     
	//! Detach and delete i'th Checker child element
	void DeleteChecker( int i );
     
	//! Detach and delete 'arg' if it's one of the Checker child elements
	void DeleteChecker( ValidationChecker *arg );
 
// <PLMXML_UserCode type="functionHeaderValidationResults" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationResults;


////////////////////////////////////////////////////////////////////////////////////
//! ChangeRecord class
/*!
\verbatim

      This element describes a change in terms of one or two Instances.
        
      Attributes:
      
      originalRef:      the original Instance, if any.
      modifiedRef:      the modified Instance, if any.
      
      select:           If both Instances are present, the 'select' attribute can be used to 
                        specify what attribute or sub-element of the Instance has changed, by
                        using an XPATH syntax (for example, "@quantity", or "Transform").

      derived:          true if the ChangeRecord exists as a result of an addition of a
                        higher-level structure.
      
      parentRef:        The parent StructureRevisionView of the 'Modified' Instance,
                        unless 'derived' is true, in which case it is the 
                        higher-level StructureRevisionView from which this ChangeRecord
                        is derived.
      
\endverbatim
*/
class PLMXML_PDM60_API ChangeRecord : public AttribOwner
{
public:
     
    //! Default constructor
    ChangeRecord( );
     
    //! Constructs a ChangeRecord with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChangeRecord( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChangeRecord();

private:

	//! Assignment operator
	ChangeRecord& operator=( const ChangeRecord& iSrc );

	//! Copy constructor
	ChangeRecord( const ChangeRecord& original );
     
public:

	//! Get Select of this ChangeRecord
	plmxml_api::String GetSelect() const;

	//! Set Select of this ChangeRecord
	plmxml_api::Result SetSelect( const plmxml_api::String &s );
	
	//! Check if Select is set
	plmxml_api::logical HasSelect( ) const;
	
	//! Unset Select
	plmxml_api::Result UnsetSelect( );

	//! Get Original URI as plmxml_api::String
	plmxml_api::String GetOriginalURI() const;

	//! Set Original URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOriginalURI( const plmxml_api::String& );
	
	//! Get the handle of Original URI. Does not resolve the URI.
	plmxml_api::Result GetOriginalURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Original URI. URI string is unchanged.
	plmxml_api::Result SetOriginalURI( const plmxml_api::Handle& );
	
	//! Resolve Original URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOriginalURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Original URI. Clears URI string and handle.
	plmxml_api::Result DeleteOriginalURI();
	
	//! Check if Original URI is set
	plmxml_api::logical HasOriginalURI( ) const;
	

	//! Get Parent URI as plmxml_api::String
	plmxml_api::String GetParentURI() const;

	//! Set Parent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::String& );
	
	//! Get the handle of Parent URI. Does not resolve the URI.
	plmxml_api::Result GetParentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Parent URI. URI string is unchanged.
	plmxml_api::Result SetParentURI( const plmxml_api::Handle& );
	
	//! Resolve Parent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveParentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Parent URI. Clears URI string and handle.
	plmxml_api::Result DeleteParentURI();
	
	//! Check if Parent URI is set
	plmxml_api::logical HasParentURI( ) const;
	

	//! Set Derived
	plmxml_api::Result SetDerived( plmxml_api::logical arg );

	//! Get Derived
	plmxml_api::logical GetDerived() const;

	//! Check if Derived is set
	plmxml_api::logical HasDerived() const;

	//! Unset Derived
	plmxml_api::Result UnsetDerived();

	//! Get Modified URI as plmxml_api::String
	plmxml_api::String GetModifiedURI() const;

	//! Set Modified URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetModifiedURI( const plmxml_api::String& );
	
	//! Get the handle of Modified URI. Does not resolve the URI.
	plmxml_api::Result GetModifiedURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Modified URI. URI string is unchanged.
	plmxml_api::Result SetModifiedURI( const plmxml_api::Handle& );
	
	//! Resolve Modified URI and return an object (handle) it points to.
	plmxml_api::Result ResolveModifiedURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Modified URI. Clears URI string and handle.
	plmxml_api::Result DeleteModifiedURI();
	
	//! Check if Modified URI is set
	plmxml_api::logical HasModifiedURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderChangeRecord" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassChangeRecord;


////////////////////////////////////////////////////////////////////////////////////
//! ChangeRecordGroup class
/*!
\verbatim

      This element defines a group of ChangeRecords which together define a logical or
      functional replacement.
        
      Attributes:
      
      transfer:           true if the ChangeRecordGroup is the result of transferring the same 
                          component from one assembly to another.
      modifiedRootRef:    The StructureRevisionView which is at the root of the Modified
                          assembly.
      memberRefs:         The ChangeRecord elements in the group.
      
\endverbatim
*/
class PLMXML_PDM60_API ChangeRecordGroup : public AttribOwner
{
public:
     
    //! Default constructor
    ChangeRecordGroup( );
     
    //! Constructs a ChangeRecordGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChangeRecordGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChangeRecordGroup();

private:

	//! Assignment operator
	ChangeRecordGroup& operator=( const ChangeRecordGroup& iSrc );

	//! Copy constructor
	ChangeRecordGroup( const ChangeRecordGroup& original );
     
public:

	//! Get ModifiedRoot URI as plmxml_api::String
	plmxml_api::String GetModifiedRootURI() const;

	//! Set ModifiedRoot URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetModifiedRootURI( const plmxml_api::String& );
	
	//! Get the handle of ModifiedRoot URI. Does not resolve the URI.
	plmxml_api::Result GetModifiedRootURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ModifiedRoot URI. URI string is unchanged.
	plmxml_api::Result SetModifiedRootURI( const plmxml_api::Handle& );
	
	//! Resolve ModifiedRoot URI and return an object (handle) it points to.
	plmxml_api::Result ResolveModifiedRootURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ModifiedRoot URI. Clears URI string and handle.
	plmxml_api::Result DeleteModifiedRootURI();
	
	//! Check if ModifiedRoot URI is set
	plmxml_api::logical HasModifiedRootURI( ) const;
	

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

	//! Set Transfer
	plmxml_api::Result SetTransfer( plmxml_api::logical arg );

	//! Get Transfer
	plmxml_api::logical GetTransfer() const;

	//! Check if Transfer is set
	plmxml_api::logical HasTransfer() const;

	//! Unset Transfer
	plmxml_api::Result UnsetTransfer();
 
// <PLMXML_UserCode type="functionHeaderChangeRecordGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassChangeRecordGroup;


////////////////////////////////////////////////////////////////////////////////////
//! IncrementalChange class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API IncrementalChange : public DescriptionObject
{
public:
     
    //! Default constructor
    IncrementalChange( );
     
    //! Constructs a IncrementalChange with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IncrementalChange( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IncrementalChange();

private:

	//! Assignment operator
	IncrementalChange& operator=( const IncrementalChange& iSrc );

	//! Copy constructor
	IncrementalChange( const IncrementalChange& original );
     
public:

	//! Get number of URIs in Instance
	int NumberOfInstanceURIs() const;

	//! Get i'th URI in Instance
	plmxml_api::String GetInstanceURI( int i ) const;

	//! Add a URI to Instance array. Call ResolveInstanceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddInstanceURI( const plmxml_api::String& u );

	//! Set i'th URI in Instance array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetInstanceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Instance URI. Does not resolve the URI.
	plmxml_api::Result GetInstanceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Instance array.
	plmxml_api::Result AddInstanceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Instance array to point to 'handle'.
	plmxml_api::Result SetInstanceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Instance points to.
	plmxml_api::Result ResolveInstanceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Instance array.
	plmxml_api::Result DeleteInstanceURI( int i );

	//! Remove all URIs from Instance array.
	plmxml_api::Result DeleteInstanceURIs( );
	
	//! Check if Instance is set
	plmxml_api::logical HasInstanceURIs( ) const;

	//! Get number of URIs in Folder
	int NumberOfFolderURIs() const;

	//! Get i'th URI in Folder
	plmxml_api::String GetFolderURI( int i ) const;

	//! Add a URI to Folder array. Call ResolveFolderURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFolderURI( const plmxml_api::String& u );

	//! Set i'th URI in Folder array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFolderURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Folder URI. Does not resolve the URI.
	plmxml_api::Result GetFolderURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Folder array.
	plmxml_api::Result AddFolderURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Folder array to point to 'handle'.
	plmxml_api::Result SetFolderURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Folder points to.
	plmxml_api::Result ResolveFolderURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Folder array.
	plmxml_api::Result DeleteFolderURI( int i );

	//! Remove all URIs from Folder array.
	plmxml_api::Result DeleteFolderURIs( );
	
	//! Check if Folder is set
	plmxml_api::logical HasFolderURIs( ) const;

	//! Get number of URIs in Form
	int NumberOfFormURIs() const;

	//! Get i'th URI in Form
	plmxml_api::String GetFormURI( int i ) const;

	//! Add a URI to Form array. Call ResolveFormURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFormURI( const plmxml_api::String& u );

	//! Set i'th URI in Form array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFormURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Form URI. Does not resolve the URI.
	plmxml_api::Result GetFormURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Form array.
	plmxml_api::Result AddFormURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Form array to point to 'handle'.
	plmxml_api::Result SetFormURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Form points to.
	plmxml_api::Result ResolveFormURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Form array.
	plmxml_api::Result DeleteFormURI( int i );

	//! Remove all URIs from Form array.
	plmxml_api::Result DeleteFormURIs( );
	
	//! Check if Form is set
	plmxml_api::logical HasFormURIs( ) const;

	//! Get number of URIs in Activity
	int NumberOfActivityURIs() const;

	//! Get i'th URI in Activity
	plmxml_api::String GetActivityURI( int i ) const;

	//! Add a URI to Activity array. Call ResolveActivityURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActivityURI( const plmxml_api::String& u );

	//! Set i'th URI in Activity array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActivityURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Activity URI. Does not resolve the URI.
	plmxml_api::Result GetActivityURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Activity array.
	plmxml_api::Result AddActivityURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Activity array to point to 'handle'.
	plmxml_api::Result SetActivityURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Activity points to.
	plmxml_api::Result ResolveActivityURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Activity array.
	plmxml_api::Result DeleteActivityURI( int i );

	//! Remove all URIs from Activity array.
	plmxml_api::Result DeleteActivityURIs( );
	
	//! Check if Activity is set
	plmxml_api::logical HasActivityURIs( ) const;

	//! Get number of URIs in Association
	int NumberOfAssociationURIs() const;

	//! Get i'th URI in Association
	plmxml_api::String GetAssociationURI( int i ) const;

	//! Add a URI to Association array. Call ResolveAssociationURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAssociationURI( const plmxml_api::String& u );

	//! Set i'th URI in Association array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAssociationURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Association URI. Does not resolve the URI.
	plmxml_api::Result GetAssociationURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Association array.
	plmxml_api::Result AddAssociationURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Association array to point to 'handle'.
	plmxml_api::Result SetAssociationURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Association points to.
	plmxml_api::Result ResolveAssociationURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Association array.
	plmxml_api::Result DeleteAssociationURI( int i );

	//! Remove all URIs from Association array.
	plmxml_api::Result DeleteAssociationURIs( );
	
	//! Check if Association is set
	plmxml_api::logical HasAssociationURIs( ) const;

	//! Get number of URIs in Dataset
	int NumberOfDatasetURIs() const;

	//! Get i'th URI in Dataset
	plmxml_api::String GetDatasetURI( int i ) const;

	//! Add a URI to Dataset array. Call ResolveDatasetURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDatasetURI( const plmxml_api::String& u );

	//! Set i'th URI in Dataset array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDatasetURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Dataset URI. Does not resolve the URI.
	plmxml_api::Result GetDatasetURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Dataset array.
	plmxml_api::Result AddDatasetURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Dataset array to point to 'handle'.
	plmxml_api::Result SetDatasetURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Dataset points to.
	plmxml_api::Result ResolveDatasetURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Dataset array.
	plmxml_api::Result DeleteDatasetURI( int i );

	//! Remove all URIs from Dataset array.
	plmxml_api::Result DeleteDatasetURIs( );
	
	//! Check if Dataset is set
	plmxml_api::logical HasDatasetURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderIncrementalChange" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassIncrementalChange;


////////////////////////////////////////////////////////////////////////////////////
//! ChangeOrder class
/*!
\verbatim

\endverbatim
*/
class PLMXML_PDM60_API ChangeOrder : public Structure
{
public:
     
    //! Default constructor
    ChangeOrder( );
     
    //! Constructs a ChangeOrder with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChangeOrder( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChangeOrder();

private:

	//! Assignment operator
	ChangeOrder& operator=( const ChangeOrder& iSrc );

	//! Copy constructor
	ChangeOrder( const ChangeOrder& original );
     
public:

	//! Add IncrementalChangeAdd child element to this ChangeOrder. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	IncrementalChange *AddIncrementalChangeAdd();
     
	//! Add 'arg' as IncrementalChangeAdd child element to this ChangeOrder.
	plmxml_api::Result AddIncrementalChangeAdd( IncrementalChange *arg );

	//! Detach and delete all IncrementalChangeAdd child elements.
	void DeleteIncrementalChangeAdds();
     
	//! Get number of IncrementalChangeAdd child elements.
	int NumberOfIncrementalChangeAdds() const;
     
	//! Get i'th IncrementalChangeAdd child element.
	IncrementalChange *GetIncrementalChangeAdd( int i ) const;
     
	//! Get all IncrementalChangeAdd child element as an array
	void GetIncrementalChangeAdds( plmxml_api::Array<IncrementalChange*> &array ) const;
	     
	//! Detach and delete i'th IncrementalChangeAdd child element
	void DeleteIncrementalChangeAdd( int i );
     
	//! Detach and delete 'arg' if it's one of the IncrementalChangeAdd child elements
	void DeleteIncrementalChangeAdd( IncrementalChange *arg );

	//! Add IncrementalChangeDelete child element to this ChangeOrder. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	IncrementalChange *AddIncrementalChangeDelete();
     
	//! Add 'arg' as IncrementalChangeDelete child element to this ChangeOrder.
	plmxml_api::Result AddIncrementalChangeDelete( IncrementalChange *arg );

	//! Detach and delete all IncrementalChangeDelete child elements.
	void DeleteIncrementalChangeDeletes();
     
	//! Get number of IncrementalChangeDelete child elements.
	int NumberOfIncrementalChangeDeletes() const;
     
	//! Get i'th IncrementalChangeDelete child element.
	IncrementalChange *GetIncrementalChangeDelete( int i ) const;
     
	//! Get all IncrementalChangeDelete child element as an array
	void GetIncrementalChangeDeletes( plmxml_api::Array<IncrementalChange*> &array ) const;
	     
	//! Detach and delete i'th IncrementalChangeDelete child element
	void DeleteIncrementalChangeDelete( int i );
     
	//! Detach and delete 'arg' if it's one of the IncrementalChangeDelete child elements
	void DeleteIncrementalChangeDelete( IncrementalChange *arg );
 
// <PLMXML_UserCode type="functionHeaderChangeOrder" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassChangeOrder;


////////////////////////////////////////////////////////////////////////////////////
//! Vendor class
/*!
\verbatim

      Represents a vendor.

      Attributes:

      addressRef:       References the Address that holds the address of the
                        vendor's premises and the vendor's web site address,
                        phone number and email address.
      contactRef:       References the Person that holds the name of the contact
                        at the vendor.
      
\endverbatim
*/
class PLMXML_PDM60_API Vendor : public Structure
{
public:
     
    //! Default constructor
    Vendor( );
     
    //! Constructs a Vendor with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Vendor( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Vendor();

private:

	//! Assignment operator
	Vendor& operator=( const Vendor& iSrc );

	//! Copy constructor
	Vendor( const Vendor& original );
     
public:

	//! Get Contact URI as plmxml_api::String
	plmxml_api::String GetContactURI() const;

	//! Set Contact URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetContactURI( const plmxml_api::String& );
	
	//! Get the handle of Contact URI. Does not resolve the URI.
	plmxml_api::Result GetContactURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Contact URI. URI string is unchanged.
	plmxml_api::Result SetContactURI( const plmxml_api::Handle& );
	
	//! Resolve Contact URI and return an object (handle) it points to.
	plmxml_api::Result ResolveContactURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Contact URI. Clears URI string and handle.
	plmxml_api::Result DeleteContactURI();
	
	//! Check if Contact URI is set
	plmxml_api::logical HasContactURI( ) const;
	

	//! Get Address URI as plmxml_api::String
	plmxml_api::String GetAddressURI() const;

	//! Set Address URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAddressURI( const plmxml_api::String& );
	
	//! Get the handle of Address URI. Does not resolve the URI.
	plmxml_api::Result GetAddressURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Address URI. URI string is unchanged.
	plmxml_api::Result SetAddressURI( const plmxml_api::Handle& );
	
	//! Resolve Address URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAddressURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Address URI. Clears URI string and handle.
	plmxml_api::Result DeleteAddressURI();
	
	//! Check if Address URI is set
	plmxml_api::logical HasAddressURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderVendor" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassVendor;


////////////////////////////////////////////////////////////////////////////////////
//! VendorRevision class
/*!
\verbatim

      Represents a revision of a vendor.

      Attributes:

      vendorRoleRefs:   References a list of VendorRole elements that represent
                        the roles and associated information about the vendor
                        revision.
      comments:         General comments about the vendor revision.
      
\endverbatim
*/
class PLMXML_PDM60_API VendorRevision : public StructureRevision
{
public:
     
    //! Default constructor
    VendorRevision( );
     
    //! Constructs a VendorRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    VendorRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~VendorRevision();

private:

	//! Assignment operator
	VendorRevision& operator=( const VendorRevision& iSrc );

	//! Copy constructor
	VendorRevision( const VendorRevision& original );
     
public:

	//! Get Comments of this VendorRevision
	plmxml_api::String GetComments() const;

	//! Set Comments of this VendorRevision
	plmxml_api::Result SetComments( const plmxml_api::String &s );
	
	//! Check if Comments is set
	plmxml_api::logical HasComments( ) const;
	
	//! Unset Comments
	plmxml_api::Result UnsetComments( );

	//! Get number of URIs in VendorRole
	int NumberOfVendorRoleURIs() const;

	//! Get i'th URI in VendorRole
	plmxml_api::String GetVendorRoleURI( int i ) const;

	//! Add a URI to VendorRole array. Call ResolveVendorRoleURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddVendorRoleURI( const plmxml_api::String& u );

	//! Set i'th URI in VendorRole array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetVendorRoleURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of VendorRole URI. Does not resolve the URI.
	plmxml_api::Result GetVendorRoleURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to VendorRole array.
	plmxml_api::Result AddVendorRoleURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in VendorRole array to point to 'handle'.
	plmxml_api::Result SetVendorRoleURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in VendorRole points to.
	plmxml_api::Result ResolveVendorRoleURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from VendorRole array.
	plmxml_api::Result DeleteVendorRoleURI( int i );

	//! Remove all URIs from VendorRole array.
	plmxml_api::Result DeleteVendorRoleURIs( );
	
	//! Check if VendorRole is set
	plmxml_api::logical HasVendorRoleURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderVendorRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassVendorRevision;


////////////////////////////////////////////////////////////////////////////////////
//! VendorRole class
/*!
\verbatim

      Represents a role and associated information about a vendor revision.

      Attributes:

      type:             The type or role of the vendor revision.
      
\endverbatim
*/
class PLMXML_PDM60_API VendorRole : public AttribOwner
{
public:
     
    //! Default constructor
    VendorRole( );
     
    //! Constructs a VendorRole with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    VendorRole( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~VendorRole();

private:

	//! Assignment operator
	VendorRole& operator=( const VendorRole& iSrc );

	//! Copy constructor
	VendorRole( const VendorRole& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const plmxml60::eOrganisationRoleEnum& arg );

	//! Get Type
	plmxml60::eOrganisationRoleEnum GetType() const;
 
// <PLMXML_UserCode type="functionHeaderVendorRole" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassVendorRole;


////////////////////////////////////////////////////////////////////////////////////
//! VendorPartRelation class
/*!
\verbatim

      Relates a commercial part to a vendor part.

      Attributes:

      preferredStatus:  Whether the Product representing the vendor part
                        referenced by the second reference in the inherited
                        relatedRefs attribute is the preferred solution for the
                        commercial part referenced by the first reference in
                        relatedRefs. preferredStatus can take values like
                        "preferred" or "backup". The preferred status of the
                        Vendor is indicated by the vendorRef attribute on the
                        Product representing the vendor part.
      
\endverbatim
*/
class PLMXML_PDM60_API VendorPartRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    VendorPartRelation( );
     
    //! Constructs a VendorPartRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    VendorPartRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~VendorPartRelation();

private:

	//! Assignment operator
	VendorPartRelation& operator=( const VendorPartRelation& iSrc );

	//! Copy constructor
	VendorPartRelation( const VendorPartRelation& original );
     
public:

	//! Get PreferredStatus of this VendorPartRelation
	plmxml_api::String GetPreferredStatus() const;

	//! Set PreferredStatus of this VendorPartRelation
	plmxml_api::Result SetPreferredStatus( const plmxml_api::String &s );
	
	//! Check if PreferredStatus is set
	plmxml_api::logical HasPreferredStatus( ) const;
	
	//! Unset PreferredStatus
	plmxml_api::Result UnsetPreferredStatus( );
 
// <PLMXML_UserCode type="functionHeaderVendorPartRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassVendorPartRelation;


////////////////////////////////////////////////////////////////////////////////////
//! BidPackage class
/*!
\verbatim

      Represents a bid package.
      
\endverbatim
*/
class PLMXML_PDM60_API BidPackage : public Structure
{
public:
     
    //! Default constructor
    BidPackage( );
     
    //! Constructs a BidPackage with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BidPackage( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BidPackage();

private:

	//! Assignment operator
	BidPackage& operator=( const BidPackage& iSrc );

	//! Copy constructor
	BidPackage( const BidPackage& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderBidPackage" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassBidPackage;


////////////////////////////////////////////////////////////////////////////////////
//! LineItemConfigurationContext class
/*!
\verbatim

      Represents configuration context for a line item.

      Attributes:

      viewRef:          References the View used to configure the line item.
      
\endverbatim
*/
class PLMXML_PDM60_API LineItemConfigurationContext : public ConfigurationContext
{
public:
     
    //! Default constructor
    LineItemConfigurationContext( );
     
    //! Constructs a LineItemConfigurationContext with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LineItemConfigurationContext( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LineItemConfigurationContext();

private:

	//! Assignment operator
	LineItemConfigurationContext& operator=( const LineItemConfigurationContext& iSrc );

	//! Copy constructor
	LineItemConfigurationContext( const LineItemConfigurationContext& original );
     
public:

	//! Get View URI as plmxml_api::String
	plmxml_api::String GetViewURI() const;

	//! Set View URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetViewURI( const plmxml_api::String& );
	
	//! Get the handle of View URI. Does not resolve the URI.
	plmxml_api::Result GetViewURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of View URI. URI string is unchanged.
	plmxml_api::Result SetViewURI( const plmxml_api::Handle& );
	
	//! Resolve View URI and return an object (handle) it points to.
	plmxml_api::Result ResolveViewURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset View URI. Clears URI string and handle.
	plmxml_api::Result DeleteViewURI();
	
	//! Check if View URI is set
	plmxml_api::logical HasViewURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLineItemConfigurationContext" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassLineItemConfigurationContext;


////////////////////////////////////////////////////////////////////////////////////
//! LineItem class
/*!
\verbatim

      Represents an individual line item in a bid package revision.

      Attributes:

      productRef:       References the Product that represents the commercial
                        part for the line item.
      quantityRef:      References the ValueWithUnit that represents the
                        quantity of the line item.
      quoteRefs:        A list of references to the Quote elements for the line
                        item.
      
\endverbatim
*/
class PLMXML_PDM60_API LineItem : public Managed
{
public:
     
    //! Default constructor
    LineItem( );
     
    //! Constructs a LineItem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LineItem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LineItem();

private:

	//! Assignment operator
	LineItem& operator=( const LineItem& iSrc );

	//! Copy constructor
	LineItem( const LineItem& original );
     
public:

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
	

	//! Get Quantity URI as plmxml_api::String
	plmxml_api::String GetQuantityURI() const;

	//! Set Quantity URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetQuantityURI( const plmxml_api::String& );
	
	//! Get the handle of Quantity URI. Does not resolve the URI.
	plmxml_api::Result GetQuantityURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Quantity URI. URI string is unchanged.
	plmxml_api::Result SetQuantityURI( const plmxml_api::Handle& );
	
	//! Resolve Quantity URI and return an object (handle) it points to.
	plmxml_api::Result ResolveQuantityURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Quantity URI. Clears URI string and handle.
	plmxml_api::Result DeleteQuantityURI();
	
	//! Check if Quantity URI is set
	plmxml_api::logical HasQuantityURI( ) const;
	

	//! Get number of URIs in Quote
	int NumberOfQuoteURIs() const;

	//! Get i'th URI in Quote
	plmxml_api::String GetQuoteURI( int i ) const;

	//! Add a URI to Quote array. Call ResolveQuoteURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddQuoteURI( const plmxml_api::String& u );

	//! Set i'th URI in Quote array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetQuoteURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Quote URI. Does not resolve the URI.
	plmxml_api::Result GetQuoteURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Quote array.
	plmxml_api::Result AddQuoteURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Quote array to point to 'handle'.
	plmxml_api::Result SetQuoteURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Quote points to.
	plmxml_api::Result ResolveQuoteURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Quote array.
	plmxml_api::Result DeleteQuoteURI( int i );

	//! Remove all URIs from Quote array.
	plmxml_api::Result DeleteQuoteURIs( );
	
	//! Check if Quote is set
	plmxml_api::logical HasQuoteURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderLineItem" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassLineItem;


////////////////////////////////////////////////////////////////////////////////////
//! BidPackageRevision class
/*!
\verbatim

      Represents a revision of a bid package.

      Attributes:

      requiredDate:     The required date of the bid package revision.
      purpose:          The purpose of the bid package revision.

      Sub-elements:

      LineItem:         The individual line items in the bid package revision.
      
\endverbatim
*/
class PLMXML_PDM60_API BidPackageRevision : public StructureRevision
{
public:
     
    //! Default constructor
    BidPackageRevision( );
     
    //! Constructs a BidPackageRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BidPackageRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BidPackageRevision();

private:

	//! Assignment operator
	BidPackageRevision& operator=( const BidPackageRevision& iSrc );

	//! Copy constructor
	BidPackageRevision( const BidPackageRevision& original );
     
public:

	//! Get Purpose of this BidPackageRevision
	plmxml_api::String GetPurpose() const;

	//! Set Purpose of this BidPackageRevision
	plmxml_api::Result SetPurpose( const plmxml_api::String &s );
	
	//! Check if Purpose is set
	plmxml_api::logical HasPurpose( ) const;
	
	//! Unset Purpose
	plmxml_api::Result UnsetPurpose( );

	//! Get RequiredDate of this BidPackageRevision
	plmxml_api::String GetRequiredDate() const;

	//! Set RequiredDate of this BidPackageRevision
	plmxml_api::Result SetRequiredDate( const plmxml_api::String &s );
	
	//! Check if RequiredDate is set
	plmxml_api::logical HasRequiredDate( ) const;
	
	//! Unset RequiredDate
	plmxml_api::Result UnsetRequiredDate( );

	//! Add LineItem child element to this BidPackageRevision. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	LineItem *AddLineItem();
     
	//! Add 'arg' as LineItem child element to this BidPackageRevision.
	plmxml_api::Result AddLineItem( LineItem *arg );

	//! Detach and delete all LineItem child elements.
	void DeleteLineItems();
     
	//! Get number of LineItem child elements.
	int NumberOfLineItems() const;
     
	//! Get i'th LineItem child element.
	LineItem *GetLineItem( int i ) const;
     
	//! Get all LineItem child element as an array
	void GetLineItems( plmxml_api::Array<LineItem*> &array ) const;
	     
	//! Detach and delete i'th LineItem child element
	void DeleteLineItem( int i );
     
	//! Detach and delete 'arg' if it's one of the LineItem child elements
	void DeleteLineItem( LineItem *arg );
 
// <PLMXML_UserCode type="functionHeaderBidPackageRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassBidPackageRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Quote class
/*!
\verbatim

      Represents an individual line item in a bid package revision.

      Attributes:

      vendorRef:        References the Vendor for the Quote.
      
\endverbatim
*/
class PLMXML_PDM60_API Quote : public Managed
{
public:
     
    //! Default constructor
    Quote( );
     
    //! Constructs a Quote with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Quote( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Quote();

private:

	//! Assignment operator
	Quote& operator=( const Quote& iSrc );

	//! Copy constructor
	Quote( const Quote& original );
     
public:

	//! Get Vendor URI as plmxml_api::String
	plmxml_api::String GetVendorURI() const;

	//! Set Vendor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetVendorURI( const plmxml_api::String& );
	
	//! Get the handle of Vendor URI. Does not resolve the URI.
	plmxml_api::Result GetVendorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Vendor URI. URI string is unchanged.
	plmxml_api::Result SetVendorURI( const plmxml_api::Handle& );
	
	//! Resolve Vendor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveVendorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Vendor URI. Clears URI string and handle.
	plmxml_api::Result DeleteVendorURI();
	
	//! Check if Vendor URI is set
	plmxml_api::logical HasVendorURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderQuote" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassQuote;


////////////////////////////////////////////////////////////////////////////////////
//! CheckerParameter class
/*!
\verbatim

      This element gives the parameter of a Validation Checker performed on an
      object.

      Attributes:

      name:            Inherited from AttribOwner. The name of this parameter.
      value:           The value of the parameter.
      operator:        The operator to connect name and value.
      
\endverbatim
*/
class PLMXML_PDM60_API CheckerParameter : public AttribOwner
{
public:
     
    //! Default constructor
    CheckerParameter( );
     
    //! Constructs a CheckerParameter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CheckerParameter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CheckerParameter();

private:

	//! Assignment operator
	CheckerParameter& operator=( const CheckerParameter& iSrc );

	//! Copy constructor
	CheckerParameter( const CheckerParameter& original );
     
public:

	//! Get Value of this CheckerParameter
	plmxml_api::String GetValue() const;

	//! Set Value of this CheckerParameter
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Set Operator
	plmxml_api::Result SetOperator( const plmxml60::ePropertyFilterOperationEnum& arg );

	//! Get Operator
	plmxml60::ePropertyFilterOperationEnum GetOperator() const;
 
// <PLMXML_UserCode type="functionHeaderCheckerParameter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassCheckerParameter;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationResult class
/*!
\verbatim

      This element gives the result of a Validation Check performed on an
      object.

      Attributes:

      name:             Inherited from AttribOwner. The name of this result.
      checker:          The name of the checker.
      application:      The application to execute validation.
      category:         The category of this checker
      utilityCommand:   The command of validation utility.
      arguments:        A group of arguments used to run the validation
                        application.
      resultID:         The ID of one ValidationResult object.
      result:           The result of a checker.
      upToDate:         True if result is up_to_date, false if out_of_date.
      adHoc:            Indicates if the checker is adhoc.
      executorRef:      A reference to the Person or User that ran the
                        ValidationResult.
      date:             The date validation performed.
      comments:         The comments of one ValidationResult object.
      userRef:          A reference to the Person or User that created the
                        ValidationResult.
      reportRefs:       An array of URIs of Dataset.
      targetRef:        URI of the target dataset or other element to which the
                        validation applies.
      parameterRefs:    A list of references to the CheckerParameters for the
                        checker.
      requirementRef:   A reference to the RequirementRevision that this
                        ValidationResult validates.
      commentsRef:      References a multiple language version of comments. If
                        multiple language support is required, commentsRef
                        should be used in addition to comments.
      overrideApprovalRef: References an OverrideApproval.
      checkRef:         References the ValidationCheckRevision used to generate
                        the ValidationResult.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationResult : public AttribOwner
{
public:
     
    //! Default constructor
    ValidationResult( );
     
    //! Constructs a ValidationResult with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationResult( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationResult();

private:

	//! Assignment operator
	ValidationResult& operator=( const ValidationResult& iSrc );

	//! Copy constructor
	ValidationResult( const ValidationResult& original );
     
public:

	//! Get number of URIs in Parameter
	int NumberOfParameterURIs() const;

	//! Get i'th URI in Parameter
	plmxml_api::String GetParameterURI( int i ) const;

	//! Add a URI to Parameter array. Call ResolveParameterURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddParameterURI( const plmxml_api::String& u );

	//! Set i'th URI in Parameter array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetParameterURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Parameter URI. Does not resolve the URI.
	plmxml_api::Result GetParameterURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Parameter array.
	plmxml_api::Result AddParameterURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Parameter array to point to 'handle'.
	plmxml_api::Result SetParameterURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Parameter points to.
	plmxml_api::Result ResolveParameterURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Parameter array.
	plmxml_api::Result DeleteParameterURI( int i );

	//! Remove all URIs from Parameter array.
	plmxml_api::Result DeleteParameterURIs( );
	
	//! Check if Parameter is set
	plmxml_api::logical HasParameterURIs( ) const;

	//! Get number of URIs in Report
	int NumberOfReportURIs() const;

	//! Get i'th URI in Report
	plmxml_api::String GetReportURI( int i ) const;

	//! Add a URI to Report array. Call ResolveReportURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddReportURI( const plmxml_api::String& u );

	//! Set i'th URI in Report array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetReportURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Report URI. Does not resolve the URI.
	plmxml_api::Result GetReportURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Report array.
	plmxml_api::Result AddReportURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Report array to point to 'handle'.
	plmxml_api::Result SetReportURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Report points to.
	plmxml_api::Result ResolveReportURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Report array.
	plmxml_api::Result DeleteReportURI( int i );

	//! Remove all URIs from Report array.
	plmxml_api::Result DeleteReportURIs( );
	
	//! Check if Report is set
	plmxml_api::logical HasReportURIs( ) const;

	//! Get Application of this ValidationResult
	plmxml_api::String GetApplication() const;

	//! Set Application of this ValidationResult
	plmxml_api::Result SetApplication( const plmxml_api::String &s );
	
	//! Check if Application is set
	plmxml_api::logical HasApplication( ) const;
	
	//! Unset Application
	plmxml_api::Result UnsetApplication( );

	//! Get Arguments of this ValidationResult
	plmxml_api::String GetArguments() const;

	//! Set Arguments of this ValidationResult
	plmxml_api::Result SetArguments( const plmxml_api::String &s );
	
	//! Check if Arguments is set
	plmxml_api::logical HasArguments( ) const;
	
	//! Unset Arguments
	plmxml_api::Result UnsetArguments( );

	//! Get User URI as plmxml_api::String
	plmxml_api::String GetUserURI() const;

	//! Set User URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::String& );
	
	//! Get the handle of User URI. Does not resolve the URI.
	plmxml_api::Result GetUserURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of User URI. URI string is unchanged.
	plmxml_api::Result SetUserURI( const plmxml_api::Handle& );
	
	//! Resolve User URI and return an object (handle) it points to.
	plmxml_api::Result ResolveUserURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset User URI. Clears URI string and handle.
	plmxml_api::Result DeleteUserURI();
	
	//! Check if User URI is set
	plmxml_api::logical HasUserURI( ) const;
	

	//! Get Check URI as plmxml_api::String
	plmxml_api::String GetCheckURI() const;

	//! Set Check URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCheckURI( const plmxml_api::String& );
	
	//! Get the handle of Check URI. Does not resolve the URI.
	plmxml_api::Result GetCheckURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Check URI. URI string is unchanged.
	plmxml_api::Result SetCheckURI( const plmxml_api::Handle& );
	
	//! Resolve Check URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCheckURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Check URI. Clears URI string and handle.
	plmxml_api::Result DeleteCheckURI();
	
	//! Check if Check URI is set
	plmxml_api::logical HasCheckURI( ) const;
	

	//! Get Comments of this ValidationResult
	plmxml_api::String GetComments() const;

	//! Set Comments of this ValidationResult
	plmxml_api::Result SetComments( const plmxml_api::String &s );
	
	//! Check if Comments is set
	plmxml_api::logical HasComments( ) const;
	
	//! Unset Comments
	plmxml_api::Result UnsetComments( );

	//! Get UtilityCommand of this ValidationResult
	plmxml_api::String GetUtilityCommand() const;

	//! Set UtilityCommand of this ValidationResult
	plmxml_api::Result SetUtilityCommand( const plmxml_api::String &s );
	
	//! Check if UtilityCommand is set
	plmxml_api::logical HasUtilityCommand( ) const;
	
	//! Unset UtilityCommand
	plmxml_api::Result UnsetUtilityCommand( );

	//! Set Result
	plmxml_api::Result SetResult( plmxml_api::logical arg );

	//! Get Result
	plmxml_api::logical GetResult() const;

	//! Check if Result is set
	plmxml_api::logical HasResult() const;

	//! Unset Result
	plmxml_api::Result UnsetResult();

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
	

	//! Get Comments URI as plmxml_api::String
	plmxml_api::String GetCommentsURI() const;

	//! Set Comments URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCommentsURI( const plmxml_api::String& );
	
	//! Get the handle of Comments URI. Does not resolve the URI.
	plmxml_api::Result GetCommentsURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Comments URI. URI string is unchanged.
	plmxml_api::Result SetCommentsURI( const plmxml_api::Handle& );
	
	//! Resolve Comments URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCommentsURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Comments URI. Clears URI string and handle.
	plmxml_api::Result DeleteCommentsURI();
	
	//! Check if Comments URI is set
	plmxml_api::logical HasCommentsURI( ) const;
	

	//! Get ResultID of this ValidationResult
	plmxml_api::String GetResultID() const;

	//! Set ResultID of this ValidationResult
	plmxml_api::Result SetResultID( const plmxml_api::String &s );
	
	//! Check if ResultID is set
	plmxml_api::logical HasResultID( ) const;
	
	//! Unset ResultID
	plmxml_api::Result UnsetResultID( );

	//! Set UpToDate
	plmxml_api::Result SetUpToDate( plmxml_api::logical arg );

	//! Get UpToDate
	plmxml_api::logical GetUpToDate() const;

	//! Check if UpToDate is set
	plmxml_api::logical HasUpToDate() const;

	//! Unset UpToDate
	plmxml_api::Result UnsetUpToDate();

	//! Get Date of this ValidationResult
	plmxml_api::String GetDate() const;

	//! Set Date of this ValidationResult
	plmxml_api::Result SetDate( const plmxml_api::String &s );
	
	//! Check if Date is set
	plmxml_api::logical HasDate( ) const;
	
	//! Unset Date
	plmxml_api::Result UnsetDate( );

	//! Get OverrideApproval URI as plmxml_api::String
	plmxml_api::String GetOverrideApprovalURI() const;

	//! Set OverrideApproval URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOverrideApprovalURI( const plmxml_api::String& );
	
	//! Get the handle of OverrideApproval URI. Does not resolve the URI.
	plmxml_api::Result GetOverrideApprovalURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of OverrideApproval URI. URI string is unchanged.
	plmxml_api::Result SetOverrideApprovalURI( const plmxml_api::Handle& );
	
	//! Resolve OverrideApproval URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOverrideApprovalURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset OverrideApproval URI. Clears URI string and handle.
	plmxml_api::Result DeleteOverrideApprovalURI();
	
	//! Check if OverrideApproval URI is set
	plmxml_api::logical HasOverrideApprovalURI( ) const;
	

	//! Get Executor URI as plmxml_api::String
	plmxml_api::String GetExecutorURI() const;

	//! Set Executor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetExecutorURI( const plmxml_api::String& );
	
	//! Get the handle of Executor URI. Does not resolve the URI.
	plmxml_api::Result GetExecutorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Executor URI. URI string is unchanged.
	plmxml_api::Result SetExecutorURI( const plmxml_api::Handle& );
	
	//! Resolve Executor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveExecutorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Executor URI. Clears URI string and handle.
	plmxml_api::Result DeleteExecutorURI();
	
	//! Check if Executor URI is set
	plmxml_api::logical HasExecutorURI( ) const;
	

	//! Set AdHoc
	plmxml_api::Result SetAdHoc( plmxml_api::logical arg );

	//! Get AdHoc
	plmxml_api::logical GetAdHoc() const;

	//! Check if AdHoc is set
	plmxml_api::logical HasAdHoc() const;

	//! Unset AdHoc
	plmxml_api::Result UnsetAdHoc();

	//! Get Checker of this ValidationResult
	plmxml_api::String GetChecker() const;

	//! Set Checker of this ValidationResult
	plmxml_api::Result SetChecker( const plmxml_api::String &s );
	
	//! Check if Checker is set
	plmxml_api::logical HasChecker( ) const;
	
	//! Unset Checker
	plmxml_api::Result UnsetChecker( );

	//! Get Category of this ValidationResult
	plmxml_api::String GetCategory() const;

	//! Set Category of this ValidationResult
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );

	//! Get Requirement URI as plmxml_api::String
	plmxml_api::String GetRequirementURI() const;

	//! Set Requirement URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRequirementURI( const plmxml_api::String& );
	
	//! Get the handle of Requirement URI. Does not resolve the URI.
	plmxml_api::Result GetRequirementURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Requirement URI. URI string is unchanged.
	plmxml_api::Result SetRequirementURI( const plmxml_api::Handle& );
	
	//! Resolve Requirement URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRequirementURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Requirement URI. Clears URI string and handle.
	plmxml_api::Result DeleteRequirementURI();
	
	//! Check if Requirement URI is set
	plmxml_api::logical HasRequirementURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderValidationResult" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationResult;


////////////////////////////////////////////////////////////////////////////////////
//! DesignRequirement class
/*!
\verbatim

      A requirement for design.
      
\endverbatim
*/
class PLMXML_PDM60_API DesignRequirement : public Requirement
{
public:
     
    //! Default constructor
    DesignRequirement( );
     
    //! Constructs a DesignRequirement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DesignRequirement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DesignRequirement();

private:

	//! Assignment operator
	DesignRequirement& operator=( const DesignRequirement& iSrc );

	//! Copy constructor
	DesignRequirement( const DesignRequirement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDesignRequirement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDesignRequirement;


////////////////////////////////////////////////////////////////////////////////////
//! DesignRequirementRevision class
/*!
\verbatim

      A revision of a requirement for design.
      
      Attributes:
      
      parameterRefs:    A list of to the ValidationParameters for the
                        validation.
      
\endverbatim
*/
class PLMXML_PDM60_API DesignRequirementRevision : public RequirementRevision
{
public:
     
    //! Default constructor
    DesignRequirementRevision( );
     
    //! Constructs a DesignRequirementRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DesignRequirementRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DesignRequirementRevision();

private:

	//! Assignment operator
	DesignRequirementRevision& operator=( const DesignRequirementRevision& iSrc );

	//! Copy constructor
	DesignRequirementRevision( const DesignRequirementRevision& original );
     
public:

	//! Get number of URIs in Parameter
	int NumberOfParameterURIs() const;

	//! Get i'th URI in Parameter
	plmxml_api::String GetParameterURI( int i ) const;

	//! Add a URI to Parameter array. Call ResolveParameterURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddParameterURI( const plmxml_api::String& u );

	//! Set i'th URI in Parameter array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetParameterURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Parameter URI. Does not resolve the URI.
	plmxml_api::Result GetParameterURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Parameter array.
	plmxml_api::Result AddParameterURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Parameter array to point to 'handle'.
	plmxml_api::Result SetParameterURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Parameter points to.
	plmxml_api::Result ResolveParameterURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Parameter array.
	plmxml_api::Result DeleteParameterURI( int i );

	//! Remove all URIs from Parameter array.
	plmxml_api::Result DeleteParameterURIs( );
	
	//! Check if Parameter is set
	plmxml_api::logical HasParameterURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderDesignRequirementRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDesignRequirementRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationRequirement class
/*!
\verbatim

      A requirement for validation.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationRequirement : public DesignRequirement
{
public:
     
    //! Default constructor
    ValidationRequirement( );
     
    //! Constructs a ValidationRequirement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationRequirement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationRequirement();

private:

	//! Assignment operator
	ValidationRequirement& operator=( const ValidationRequirement& iSrc );

	//! Copy constructor
	ValidationRequirement( const ValidationRequirement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderValidationRequirement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationRequirement;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationRequirementRevision class
/*!
\verbatim

      A revision of a requirement for validation.
      
      Attributes:
      
      expressionRef:    References the ValidationExpression for the requirement.
      
      Sub-elements:
      
      Message:          The status of the validation. An InformMessage indicates
                        pass. An ErrorMessage indicates failure. A WarnMessage
                        indicates a warning. A CheckMessage indicates no
                        specific semantics.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationRequirementRevision : public DesignRequirementRevision
{
public:
     
    //! Default constructor
    ValidationRequirementRevision( );
     
    //! Constructs a ValidationRequirementRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationRequirementRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationRequirementRevision();

private:

	//! Assignment operator
	ValidationRequirementRevision& operator=( const ValidationRequirementRevision& iSrc );

	//! Copy constructor
	ValidationRequirementRevision( const ValidationRequirementRevision& original );
     
public:

	//! Get Expression URI as plmxml_api::String
	plmxml_api::String GetExpressionURI() const;

	//! Set Expression URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetExpressionURI( const plmxml_api::String& );
	
	//! Get the handle of Expression URI. Does not resolve the URI.
	plmxml_api::Result GetExpressionURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Expression URI. URI string is unchanged.
	plmxml_api::Result SetExpressionURI( const plmxml_api::Handle& );
	
	//! Resolve Expression URI and return an object (handle) it points to.
	plmxml_api::Result ResolveExpressionURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Expression URI. Clears URI string and handle.
	plmxml_api::Result DeleteExpressionURI();
	
	//! Check if Expression URI is set
	plmxml_api::logical HasExpressionURI( ) const;
	

	//! Add Message child element to this ValidationRequirementRevision. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Message *AddMessage();
     
	//! Set Message child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetMessage( Message *arg );
     
	//! Get Message child element of this ValidationRequirementRevision.
	Message *GetMessage() const;
     
	//! Detach and delete Message child element tree from this ValidationRequirementRevision.
	void DeleteMessage();
 
// <PLMXML_UserCode type="functionHeaderValidationRequirementRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationRequirementRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationParameter class
/*!
\verbatim

      A parameter for design or validation.

      Attributes:

      type:             The data type of the parameter.
      value:            The value of the parameter if appropriate.
      measure:          The physical quantity that the parameter represents if
                        appropriate.
      unitRef:          References the units of the physical quantity if
                        appropriate.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationParameter : public AttribOwner
{
public:
     
    //! Default constructor
    ValidationParameter( );
     
    //! Constructs a ValidationParameter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationParameter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationParameter();

private:

	//! Assignment operator
	ValidationParameter& operator=( const ValidationParameter& iSrc );

	//! Copy constructor
	ValidationParameter( const ValidationParameter& original );
     
public:

	//! Set Measure
	plmxml_api::Result SetMeasure( const plmxml60::eMeasureEnum& arg );

	//! Get Measure
	plmxml60::eMeasureEnum GetMeasure() const;

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
	

	//! Set Type
	plmxml_api::Result SetType( const plmxml60::eUserValueDataType& arg );

	//! Get Type
	plmxml60::eUserValueDataType GetType() const;

	//! Get Value of this ValidationParameter
	plmxml_api::String GetValue() const;

	//! Set Value of this ValidationParameter
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderValidationParameter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationParameter;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationExpression class
/*!
\verbatim

      An expression for validation.

      Attributes:

      measure:          The physical quantity that the expression represents if
                        appropriate.
      unitRef:          References the units of the physical quantity if
                        appropriate.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationExpression : public GeneralExpression
{
public:
     
    //! Default constructor
    ValidationExpression( );
     
    //! Constructs a ValidationExpression with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationExpression( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationExpression();

private:

	//! Assignment operator
	ValidationExpression& operator=( const ValidationExpression& iSrc );

	//! Copy constructor
	ValidationExpression( const ValidationExpression& original );
     
public:

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
	

	//! Set Measure
	plmxml_api::Result SetMeasure( const plmxml60::eMeasureEnum& arg );

	//! Get Measure
	plmxml60::eMeasureEnum GetMeasure() const;
 
// <PLMXML_UserCode type="functionHeaderValidationExpression" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationExpression;


////////////////////////////////////////////////////////////////////////////////////
//! Participant class
/*!
\verbatim

      A workflow dynamic participant in the CMII process from the Institute of
      Configuration Management. It is used in workflow and change management.
      Other elements can be related to Participants via GeneralRelations with
      their subType attributes set to HasParticipant. WorkflowHandlers in
      WorkflowTemplates can be configured so that when a WorkflowProcess is
      initiated on the element, the related Participants are used.

      Attributes:

      type:             The type or role of the workflow dynamic participant.
                        When type is userDefined, the type or role is obtained
                        from userDefinedType.
      assigneeRef:      References an OrganisationMember or a ResourcePool.
      userDefinedType:  The type or role of a custom participant.
                        userDefinedType is ignored when type is not
                        userDefined.
      
\endverbatim
*/
class PLMXML_PDM60_API Participant : public AttribOwner
{
public:
     
    //! Default constructor
    Participant( );
     
    //! Constructs a Participant with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Participant( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Participant();

private:

	//! Assignment operator
	Participant& operator=( const Participant& iSrc );

	//! Copy constructor
	Participant( const Participant& original );
     
public:

	//! Get UserDefinedType of this Participant
	plmxml_api::String GetUserDefinedType() const;

	//! Set UserDefinedType of this Participant
	plmxml_api::Result SetUserDefinedType( const plmxml_api::String &s );
	
	//! Check if UserDefinedType is set
	plmxml_api::logical HasUserDefinedType( ) const;
	
	//! Unset UserDefinedType
	plmxml_api::Result UnsetUserDefinedType( );

	//! Set Type
	plmxml_api::Result SetType( const eParticipantEnum& arg );

	//! Get Type
	eParticipantEnum GetType() const;

	//! Get Assignee URI as plmxml_api::String
	plmxml_api::String GetAssigneeURI() const;

	//! Set Assignee URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAssigneeURI( const plmxml_api::String& );
	
	//! Get the handle of Assignee URI. Does not resolve the URI.
	plmxml_api::Result GetAssigneeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Assignee URI. URI string is unchanged.
	plmxml_api::Result SetAssigneeURI( const plmxml_api::Handle& );
	
	//! Resolve Assignee URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAssigneeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Assignee URI. Clears URI string and handle.
	plmxml_api::Result DeleteAssigneeURI();
	
	//! Check if Assignee URI is set
	plmxml_api::logical HasAssigneeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderParticipant" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassParticipant;


////////////////////////////////////////////////////////////////////////////////////
//! OverrideApproval class
/*!
\verbatim

      Represents the approval override of a ValidationResult.

      Attributes:

      type:             The override type.
      state:            The state that the override should apply to.
      requestState:     The request state.
      category:         The override category.
      categoryRef:      References a multiple language version of category. If
                        multiple language support is required, categoryRef
                        should be used in addition to category.
      reason:           The brief override reason.
      reasonRef         References a multiple language version of reason. If
                        multiple language support is required, reasonRef should
                        be used in addition to reason.
      requestDate:      The override request date.
      requestUserRef:   References the override request user.
      decisionDate:     The decision date for the override request.
      decisionUserRef:  References the decision user for the override request.
      comment:          The decision comment for the override request.
      commentRef:       References a multiple language version of the decision
                        comment. If multiple language support is required,
                        commentRef should be used in addition to comment.
      descriptionTextRef: Inherited from AttribOwner. If multiple language
                        support is required, descriptionTextRef should be used
                        in addition to the Description sub-element.

      Sub-elements:

      Description:      Inherited from AttribOwner. The detailed description of
                        the override reason.
      
\endverbatim
*/
class PLMXML_PDM60_API OverrideApproval : public AttribOwner
{
public:
     
    //! Default constructor
    OverrideApproval( );
     
    //! Constructs a OverrideApproval with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OverrideApproval( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OverrideApproval();

private:

	//! Assignment operator
	OverrideApproval& operator=( const OverrideApproval& iSrc );

	//! Copy constructor
	OverrideApproval( const OverrideApproval& original );
     
public:

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
	

	//! Get RequestDate of this OverrideApproval
	plmxml_api::String GetRequestDate() const;

	//! Set RequestDate of this OverrideApproval
	plmxml_api::Result SetRequestDate( const plmxml_api::String &s );
	
	//! Check if RequestDate is set
	plmxml_api::logical HasRequestDate( ) const;
	
	//! Unset RequestDate
	plmxml_api::Result UnsetRequestDate( );

	//! Get DecisionDate of this OverrideApproval
	plmxml_api::String GetDecisionDate() const;

	//! Set DecisionDate of this OverrideApproval
	plmxml_api::Result SetDecisionDate( const plmxml_api::String &s );
	
	//! Check if DecisionDate is set
	plmxml_api::logical HasDecisionDate( ) const;
	
	//! Unset DecisionDate
	plmxml_api::Result UnsetDecisionDate( );

	//! Get Reason URI as plmxml_api::String
	plmxml_api::String GetReasonURI() const;

	//! Set Reason URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReasonURI( const plmxml_api::String& );
	
	//! Get the handle of Reason URI. Does not resolve the URI.
	plmxml_api::Result GetReasonURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Reason URI. URI string is unchanged.
	plmxml_api::Result SetReasonURI( const plmxml_api::Handle& );
	
	//! Resolve Reason URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReasonURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Reason URI. Clears URI string and handle.
	plmxml_api::Result DeleteReasonURI();
	
	//! Check if Reason URI is set
	plmxml_api::logical HasReasonURI( ) const;
	

	//! Set Type
	plmxml_api::Result SetType( const eOverrideEnum& arg );

	//! Get Type
	eOverrideEnum GetType() const;

	//! Set State
	plmxml_api::Result SetState( const eOverrideStateEnum& arg );

	//! Get State
	eOverrideStateEnum GetState() const;

	//! Set RequestState
	plmxml_api::Result SetRequestState( const eDecisionType& arg );

	//! Get RequestState
	eDecisionType GetRequestState() const;

	//! Get RequestUser URI as plmxml_api::String
	plmxml_api::String GetRequestUserURI() const;

	//! Set RequestUser URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRequestUserURI( const plmxml_api::String& );
	
	//! Get the handle of RequestUser URI. Does not resolve the URI.
	plmxml_api::Result GetRequestUserURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of RequestUser URI. URI string is unchanged.
	plmxml_api::Result SetRequestUserURI( const plmxml_api::Handle& );
	
	//! Resolve RequestUser URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRequestUserURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset RequestUser URI. Clears URI string and handle.
	plmxml_api::Result DeleteRequestUserURI();
	
	//! Check if RequestUser URI is set
	plmxml_api::logical HasRequestUserURI( ) const;
	

	//! Get Reason of this OverrideApproval
	plmxml_api::String GetReason() const;

	//! Set Reason of this OverrideApproval
	plmxml_api::Result SetReason( const plmxml_api::String &s );
	
	//! Check if Reason is set
	plmxml_api::logical HasReason( ) const;
	
	//! Unset Reason
	plmxml_api::Result UnsetReason( );

	//! Get DecisionUser URI as plmxml_api::String
	plmxml_api::String GetDecisionUserURI() const;

	//! Set DecisionUser URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDecisionUserURI( const plmxml_api::String& );
	
	//! Get the handle of DecisionUser URI. Does not resolve the URI.
	plmxml_api::Result GetDecisionUserURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of DecisionUser URI. URI string is unchanged.
	plmxml_api::Result SetDecisionUserURI( const plmxml_api::Handle& );
	
	//! Resolve DecisionUser URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDecisionUserURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset DecisionUser URI. Clears URI string and handle.
	plmxml_api::Result DeleteDecisionUserURI();
	
	//! Check if DecisionUser URI is set
	plmxml_api::logical HasDecisionUserURI( ) const;
	

	//! Get Comment of this OverrideApproval
	plmxml_api::String GetComment() const;

	//! Set Comment of this OverrideApproval
	plmxml_api::Result SetComment( const plmxml_api::String &s );
	
	//! Check if Comment is set
	plmxml_api::logical HasComment( ) const;
	
	//! Unset Comment
	plmxml_api::Result UnsetComment( );

	//! Get Comment URI as plmxml_api::String
	plmxml_api::String GetCommentURI() const;

	//! Set Comment URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCommentURI( const plmxml_api::String& );
	
	//! Get the handle of Comment URI. Does not resolve the URI.
	plmxml_api::Result GetCommentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Comment URI. URI string is unchanged.
	plmxml_api::Result SetCommentURI( const plmxml_api::Handle& );
	
	//! Resolve Comment URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCommentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Comment URI. Clears URI string and handle.
	plmxml_api::Result DeleteCommentURI();
	
	//! Check if Comment URI is set
	plmxml_api::logical HasCommentURI( ) const;
	

	//! Get Category of this OverrideApproval
	plmxml_api::String GetCategory() const;

	//! Set Category of this OverrideApproval
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );
 
// <PLMXML_UserCode type="functionHeaderOverrideApproval" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassOverrideApproval;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationCheck class
/*!
\verbatim

      Represents the definition of a validation check.

      Attributes:

      name:             Inherited from Structure.
      checkClass:       The class of the validation check.

      Sub-elements:

      Description:      Inherited from Structure.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationCheck : public Structure
{
public:
     
    //! Default constructor
    ValidationCheck( );
     
    //! Constructs a ValidationCheck with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationCheck( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationCheck();

private:

	//! Assignment operator
	ValidationCheck& operator=( const ValidationCheck& iSrc );

	//! Copy constructor
	ValidationCheck( const ValidationCheck& original );
     
public:

	//! Get CheckClass of this ValidationCheck
	plmxml_api::String GetCheckClass() const;

	//! Set CheckClass of this ValidationCheck
	plmxml_api::Result SetCheckClass( const plmxml_api::String &s );
	
	//! Check if CheckClass is set
	plmxml_api::logical HasCheckClass( ) const;
	
	//! Unset CheckClass
	plmxml_api::Result UnsetCheckClass( );
 
// <PLMXML_UserCode type="functionHeaderValidationCheck" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationCheck;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationCheckRevision class
/*!
\verbatim

      Represents a revision of a ValidationCheck.

      Attributes:

      name:             Inherited from StructureRevision.
      parameterRefs:    A list of references to the CheckerParameters for the
                        validation check.
      isMandatory:      Whether the validation check is mandatory.
      canGroup:         Whether the validation check can group.
      category:         The category of the validation check.
      categoryRef:      References a multiple language version of category. If
                        multiple language support is required, categoryRef
                        should be used in addition to category.

      Sub-elements:

      Description:      Inherited from StructureRevision.
      AssociatedDataSet: Inherited from StructureRevision. The value of the role
                        attribute should be extensionRule.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationCheckRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ValidationCheckRevision( );
     
    //! Constructs a ValidationCheckRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationCheckRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationCheckRevision();

private:

	//! Assignment operator
	ValidationCheckRevision& operator=( const ValidationCheckRevision& iSrc );

	//! Copy constructor
	ValidationCheckRevision( const ValidationCheckRevision& original );
     
public:

	//! Get number of URIs in Parameter
	int NumberOfParameterURIs() const;

	//! Get i'th URI in Parameter
	plmxml_api::String GetParameterURI( int i ) const;

	//! Add a URI to Parameter array. Call ResolveParameterURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddParameterURI( const plmxml_api::String& u );

	//! Set i'th URI in Parameter array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetParameterURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Parameter URI. Does not resolve the URI.
	plmxml_api::Result GetParameterURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Parameter array.
	plmxml_api::Result AddParameterURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Parameter array to point to 'handle'.
	plmxml_api::Result SetParameterURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Parameter points to.
	plmxml_api::Result ResolveParameterURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Parameter array.
	plmxml_api::Result DeleteParameterURI( int i );

	//! Remove all URIs from Parameter array.
	plmxml_api::Result DeleteParameterURIs( );
	
	//! Check if Parameter is set
	plmxml_api::logical HasParameterURIs( ) const;

	//! Get Category of this ValidationCheckRevision
	plmxml_api::String GetCategory() const;

	//! Set Category of this ValidationCheckRevision
	plmxml_api::Result SetCategory( const plmxml_api::String &s );
	
	//! Check if Category is set
	plmxml_api::logical HasCategory( ) const;
	
	//! Unset Category
	plmxml_api::Result UnsetCategory( );

	//! Set IsMandatory
	plmxml_api::Result SetIsMandatory( plmxml_api::logical arg );

	//! Get IsMandatory
	plmxml_api::logical GetIsMandatory() const;

	//! Check if IsMandatory is set
	plmxml_api::logical HasIsMandatory() const;

	//! Unset IsMandatory
	plmxml_api::Result UnsetIsMandatory();

	//! Set CanGroup
	plmxml_api::Result SetCanGroup( plmxml_api::logical arg );

	//! Get CanGroup
	plmxml_api::logical GetCanGroup() const;

	//! Check if CanGroup is set
	plmxml_api::logical HasCanGroup() const;

	//! Unset CanGroup
	plmxml_api::Result UnsetCanGroup();

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
	
 
// <PLMXML_UserCode type="functionHeaderValidationCheckRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationCheckRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationAgent class
/*!
\verbatim

      Represents an agent that performs validation checks.

      Attributes:

      name:             Inherited from Structure.
      isClientUtility:  Whether the validation agent is a client utility.

      Sub-elements:

      Description:      Inherited from Structure.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationAgent : public Structure
{
public:
     
    //! Default constructor
    ValidationAgent( );
     
    //! Constructs a ValidationAgent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationAgent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationAgent();

private:

	//! Assignment operator
	ValidationAgent& operator=( const ValidationAgent& iSrc );

	//! Copy constructor
	ValidationAgent( const ValidationAgent& original );
     
public:

	//! Set IsClientUtility
	plmxml_api::Result SetIsClientUtility( plmxml_api::logical arg );

	//! Get IsClientUtility
	plmxml_api::logical GetIsClientUtility() const;

	//! Check if IsClientUtility is set
	plmxml_api::logical HasIsClientUtility() const;

	//! Unset IsClientUtility
	plmxml_api::Result UnsetIsClientUtility();
 
// <PLMXML_UserCode type="functionHeaderValidationAgent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationAgent;


////////////////////////////////////////////////////////////////////////////////////
//! ValidationAgentRevision class
/*!
\verbatim

      Represents a revision of a ValidationAgent.

      Attributes:

      keepOverriddenResult: Whether the overridden results of the validation
                        checks of an agent are kept when the checks are run. If
                        false, the results are updated when the checks are run.
      overrideReasonMandatory: Whether a user is required to enter a reason when
                        a result override is being requested.
      checkRefs:        A list of references to the validation checks that the
                        agent performs.
      arguments:        A group of arguments used to run the validation agent.
      closureRuleRef:   References the ClosureRule on which the validation agent
                        performs its checks.
      toolRef:          References the tool the validation agent uses to perform
                        its checks.
      
\endverbatim
*/
class PLMXML_PDM60_API ValidationAgentRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ValidationAgentRevision( );
     
    //! Constructs a ValidationAgentRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationAgentRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationAgentRevision();

private:

	//! Assignment operator
	ValidationAgentRevision& operator=( const ValidationAgentRevision& iSrc );

	//! Copy constructor
	ValidationAgentRevision( const ValidationAgentRevision& original );
     
public:

	//! Get number of URIs in Check
	int NumberOfCheckURIs() const;

	//! Get i'th URI in Check
	plmxml_api::String GetCheckURI( int i ) const;

	//! Add a URI to Check array. Call ResolveCheckURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCheckURI( const plmxml_api::String& u );

	//! Set i'th URI in Check array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCheckURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Check URI. Does not resolve the URI.
	plmxml_api::Result GetCheckURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Check array.
	plmxml_api::Result AddCheckURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Check array to point to 'handle'.
	plmxml_api::Result SetCheckURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Check points to.
	plmxml_api::Result ResolveCheckURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Check array.
	plmxml_api::Result DeleteCheckURI( int i );

	//! Remove all URIs from Check array.
	plmxml_api::Result DeleteCheckURIs( );
	
	//! Check if Check is set
	plmxml_api::logical HasCheckURIs( ) const;

	//! Set KeepOverriddenResult
	plmxml_api::Result SetKeepOverriddenResult( plmxml_api::logical arg );

	//! Get KeepOverriddenResult
	plmxml_api::logical GetKeepOverriddenResult() const;

	//! Check if KeepOverriddenResult is set
	plmxml_api::logical HasKeepOverriddenResult() const;

	//! Unset KeepOverriddenResult
	plmxml_api::Result UnsetKeepOverriddenResult();

	//! Get ClosureRule URI as plmxml_api::String
	plmxml_api::String GetClosureRuleURI() const;

	//! Set ClosureRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetClosureRuleURI( const plmxml_api::String& );
	
	//! Get the handle of ClosureRule URI. Does not resolve the URI.
	plmxml_api::Result GetClosureRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ClosureRule URI. URI string is unchanged.
	plmxml_api::Result SetClosureRuleURI( const plmxml_api::Handle& );
	
	//! Resolve ClosureRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveClosureRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ClosureRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteClosureRuleURI();
	
	//! Check if ClosureRule URI is set
	plmxml_api::logical HasClosureRuleURI( ) const;
	

	//! Get Tool URI as plmxml_api::String
	plmxml_api::String GetToolURI() const;

	//! Set Tool URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetToolURI( const plmxml_api::String& );
	
	//! Get the handle of Tool URI. Does not resolve the URI.
	plmxml_api::Result GetToolURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Tool URI. URI string is unchanged.
	plmxml_api::Result SetToolURI( const plmxml_api::Handle& );
	
	//! Resolve Tool URI and return an object (handle) it points to.
	plmxml_api::Result ResolveToolURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Tool URI. Clears URI string and handle.
	plmxml_api::Result DeleteToolURI();
	
	//! Check if Tool URI is set
	plmxml_api::logical HasToolURI( ) const;
	

	//! Get Arguments of this ValidationAgentRevision
	plmxml_api::String GetArguments() const;

	//! Set Arguments of this ValidationAgentRevision
	plmxml_api::Result SetArguments( const plmxml_api::String &s );
	
	//! Check if Arguments is set
	plmxml_api::logical HasArguments( ) const;
	
	//! Unset Arguments
	plmxml_api::Result UnsetArguments( );

	//! Set OverrideReasonMandatory
	plmxml_api::Result SetOverrideReasonMandatory( plmxml_api::logical arg );

	//! Get OverrideReasonMandatory
	plmxml_api::logical GetOverrideReasonMandatory() const;

	//! Check if OverrideReasonMandatory is set
	plmxml_api::logical HasOverrideReasonMandatory() const;

	//! Unset OverrideReasonMandatory
	plmxml_api::Result UnsetOverrideReasonMandatory();
 
// <PLMXML_UserCode type="functionHeaderValidationAgentRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassValidationAgentRevision;


////////////////////////////////////////////////////////////////////////////////////
//! IssueReview class
/*!
\verbatim

      Represents the review of an issue.

      Attributes:

      decision:         The decision of review.
      reviewerRef:      References the Person or User that reviewed the issue.
      comments:         The review comments.
      commentsRef:      References a multiple language version of comments. If
                        multiple language support is required, commentsRef
                        should be used in addition to comments.
      
\endverbatim
*/
class PLMXML_PDM60_API IssueReview : public AttribOwner
{
public:
     
    //! Default constructor
    IssueReview( );
     
    //! Constructs a IssueReview with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IssueReview( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IssueReview();

private:

	//! Assignment operator
	IssueReview& operator=( const IssueReview& iSrc );

	//! Copy constructor
	IssueReview( const IssueReview& original );
     
public:

	//! Set Decision
	plmxml_api::Result SetDecision( const eIssueReviewDecisionEnum& arg );

	//! Get Decision
	eIssueReviewDecisionEnum GetDecision() const;

	//! Get Comments of this IssueReview
	plmxml_api::String GetComments() const;

	//! Set Comments of this IssueReview
	plmxml_api::Result SetComments( const plmxml_api::String &s );
	
	//! Check if Comments is set
	plmxml_api::logical HasComments( ) const;
	
	//! Unset Comments
	plmxml_api::Result UnsetComments( );

	//! Get Comments URI as plmxml_api::String
	plmxml_api::String GetCommentsURI() const;

	//! Set Comments URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCommentsURI( const plmxml_api::String& );
	
	//! Get the handle of Comments URI. Does not resolve the URI.
	plmxml_api::Result GetCommentsURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Comments URI. URI string is unchanged.
	plmxml_api::Result SetCommentsURI( const plmxml_api::Handle& );
	
	//! Resolve Comments URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCommentsURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Comments URI. Clears URI string and handle.
	plmxml_api::Result DeleteCommentsURI();
	
	//! Check if Comments URI is set
	plmxml_api::logical HasCommentsURI( ) const;
	

	//! Get Reviewer URI as plmxml_api::String
	plmxml_api::String GetReviewerURI() const;

	//! Set Reviewer URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReviewerURI( const plmxml_api::String& );
	
	//! Get the handle of Reviewer URI. Does not resolve the URI.
	plmxml_api::Result GetReviewerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Reviewer URI. URI string is unchanged.
	plmxml_api::Result SetReviewerURI( const plmxml_api::Handle& );
	
	//! Resolve Reviewer URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReviewerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Reviewer URI. Clears URI string and handle.
	plmxml_api::Result DeleteReviewerURI();
	
	//! Check if Reviewer URI is set
	plmxml_api::logical HasReviewerURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderIssueReview" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassIssueReview;


////////////////////////////////////////////////////////////////////////////////////
//! AssignmentList class
/*!
\verbatim

      Process assignment list is used to assign all tasks in a workflow process.
      Process assignment list is associated to a WorkflowTemplate and can be
      used to apply to processes created using that template. It can also be
      used to apply to any other template. If it is used to apply to processes
      that are created using different templates than it is defined for, it will
      try to assign the resources to the matching task templates and ignore the
      remaining.

      Attributes:

      name:             Inherited from AttribOwner. The name of the process
                        assignment list.
      taskTemplateRefs: A list of references to the task templates in a process
                        template.
      resourcesListRefs: A list of references to the resources assigned to the
                        task templates.
      shared:           Whether the process assignment list is shared.

      Sub-elements:

      Description:      Inherited from AttribOwner. The description of the
                        process assignment list.
      
\endverbatim
*/
class PLMXML_PDM60_API AssignmentList : public AttribOwner
{
public:
     
    //! Default constructor
    AssignmentList( );
     
    //! Constructs a AssignmentList with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AssignmentList( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AssignmentList();

private:

	//! Assignment operator
	AssignmentList& operator=( const AssignmentList& iSrc );

	//! Copy constructor
	AssignmentList( const AssignmentList& original );
     
public:

	//! Set Shared
	plmxml_api::Result SetShared( plmxml_api::logical arg );

	//! Get Shared
	plmxml_api::logical GetShared() const;

	//! Check if Shared is set
	plmxml_api::logical HasShared() const;

	//! Unset Shared
	plmxml_api::Result UnsetShared();

	//! Get number of URIs in TaskTemplate
	int NumberOfTaskTemplateURIs() const;

	//! Get i'th URI in TaskTemplate
	plmxml_api::String GetTaskTemplateURI( int i ) const;

	//! Add a URI to TaskTemplate array. Call ResolveTaskTemplateURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTaskTemplateURI( const plmxml_api::String& u );

	//! Set i'th URI in TaskTemplate array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTaskTemplateURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of TaskTemplate URI. Does not resolve the URI.
	plmxml_api::Result GetTaskTemplateURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to TaskTemplate array.
	plmxml_api::Result AddTaskTemplateURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in TaskTemplate array to point to 'handle'.
	plmxml_api::Result SetTaskTemplateURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in TaskTemplate points to.
	plmxml_api::Result ResolveTaskTemplateURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from TaskTemplate array.
	plmxml_api::Result DeleteTaskTemplateURI( int i );

	//! Remove all URIs from TaskTemplate array.
	plmxml_api::Result DeleteTaskTemplateURIs( );
	
	//! Check if TaskTemplate is set
	plmxml_api::logical HasTaskTemplateURIs( ) const;

	//! Get number of URIs in ResourcesList
	int NumberOfResourcesListURIs() const;

	//! Get i'th URI in ResourcesList
	plmxml_api::String GetResourcesListURI( int i ) const;

	//! Add a URI to ResourcesList array. Call ResolveResourcesListURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddResourcesListURI( const plmxml_api::String& u );

	//! Set i'th URI in ResourcesList array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetResourcesListURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ResourcesList URI. Does not resolve the URI.
	plmxml_api::Result GetResourcesListURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ResourcesList array.
	plmxml_api::Result AddResourcesListURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ResourcesList array to point to 'handle'.
	plmxml_api::Result SetResourcesListURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ResourcesList points to.
	plmxml_api::Result ResolveResourcesListURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ResourcesList array.
	plmxml_api::Result DeleteResourcesListURI( int i );

	//! Remove all URIs from ResourcesList array.
	plmxml_api::Result DeleteResourcesListURIs( );
	
	//! Check if ResourcesList is set
	plmxml_api::logical HasResourcesListURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderAssignmentList" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassAssignmentList;


////////////////////////////////////////////////////////////////////////////////////
//! ResourceListItem class
/*!
\verbatim

      Attributes:

      action:           The action to be performed, like Review, Acknowledge,
                        Perform, Notify.                                                
      resourceRef:      References the user / group member / resource pool
                        element.
      profileRef:       Signoff profile, required for the task template.
      
\endverbatim
*/
class PLMXML_PDM60_API ResourceListItem : public Attribute
{
public:
     
    //! Default constructor
    ResourceListItem( );
     
    //! Constructs a ResourceListItem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ResourceListItem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ResourceListItem();

private:

	//! Assignment operator
	ResourceListItem& operator=( const ResourceListItem& iSrc );

	//! Copy constructor
	ResourceListItem( const ResourceListItem& original );
     
public:

	//! Set Action
	plmxml_api::Result SetAction( const eResourceListActionEnum& arg );

	//! Get Action
	eResourceListActionEnum GetAction() const;

	//! Get Resource URI as plmxml_api::String
	plmxml_api::String GetResourceURI() const;

	//! Set Resource URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetResourceURI( const plmxml_api::String& );
	
	//! Get the handle of Resource URI. Does not resolve the URI.
	plmxml_api::Result GetResourceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Resource URI. URI string is unchanged.
	plmxml_api::Result SetResourceURI( const plmxml_api::Handle& );
	
	//! Resolve Resource URI and return an object (handle) it points to.
	plmxml_api::Result ResolveResourceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Resource URI. Clears URI string and handle.
	plmxml_api::Result DeleteResourceURI();
	
	//! Check if Resource URI is set
	plmxml_api::logical HasResourceURI( ) const;
	

	//! Get Profile URI as plmxml_api::String
	plmxml_api::String GetProfileURI() const;

	//! Set Profile URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProfileURI( const plmxml_api::String& );
	
	//! Get the handle of Profile URI. Does not resolve the URI.
	plmxml_api::Result GetProfileURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Profile URI. URI string is unchanged.
	plmxml_api::Result SetProfileURI( const plmxml_api::Handle& );
	
	//! Resolve Profile URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProfileURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Profile URI. Clears URI string and handle.
	plmxml_api::Result DeleteProfileURI();
	
	//! Check if Profile URI is set
	plmxml_api::logical HasProfileURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderResourceListItem" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassResourceListItem;


////////////////////////////////////////////////////////////////////////////////////
//! ResourceList class
/*!
\verbatim

      A ResourceList element is used to store the users / group members /
      resource pools assigned to a task template. It also stores the actions
      that the users / group members / resource pools are responsible for. If
      the task template has a defined profile, the profile information is also
      stored. If the task template is a review task template, we store the
      review quorum and if it is an acknowledge task template, we store the
      acknowledge quorum.

      Attributes:

      reviewQuorum:     The quorum value for a review task.
      acknowledgeQuorum: The quorum value for an acknowledge task.
      waitForUndecidedReviewers: Whether the workflow process should wait for
                        undecided reviewers.

      Sub-elements:

      ResourceListItem: An entry in the ResourceList.
      
\endverbatim
*/
class PLMXML_PDM60_API ResourceList : public AttribOwner
{
public:
     
    //! Default constructor
    ResourceList( );
     
    //! Constructs a ResourceList with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ResourceList( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ResourceList();

private:

	//! Assignment operator
	ResourceList& operator=( const ResourceList& iSrc );

	//! Copy constructor
	ResourceList( const ResourceList& original );
     
public:

	//! Set WaitForUndecidedReviewers
	plmxml_api::Result SetWaitForUndecidedReviewers( const eWorkflowTemplateUndecidedReviewersEnum& arg );

	//! Get WaitForUndecidedReviewers
	eWorkflowTemplateUndecidedReviewersEnum GetWaitForUndecidedReviewers() const;

	//! Set ReviewQuorum
	plmxml_api::Result SetReviewQuorum( int arg );
     
	//! Get ReviewQuorum
	int GetReviewQuorum() const;
     
	//! Check if ReviewQuorum is set
	plmxml_api::logical HasReviewQuorum() const;
     
	//! Unset ReviewQuorum
	plmxml_api::Result UnsetReviewQuorum();

	//! Set AcknowledgeQuorum
	plmxml_api::Result SetAcknowledgeQuorum( int arg );
     
	//! Get AcknowledgeQuorum
	int GetAcknowledgeQuorum() const;
     
	//! Check if AcknowledgeQuorum is set
	plmxml_api::logical HasAcknowledgeQuorum() const;
     
	//! Unset AcknowledgeQuorum
	plmxml_api::Result UnsetAcknowledgeQuorum();

	//! Add ResourceListItem child element to this ResourceList. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ResourceListItem *AddResourceListItem();
     
	//! Add 'arg' as ResourceListItem child element to this ResourceList.
	plmxml_api::Result AddResourceListItem( ResourceListItem *arg );

	//! Detach and delete all ResourceListItem child elements.
	void DeleteResourceListItems();
     
	//! Get number of ResourceListItem child elements.
	int NumberOfResourceListItems() const;
     
	//! Get i'th ResourceListItem child element.
	ResourceListItem *GetResourceListItem( int i ) const;
     
	//! Get all ResourceListItem child element as an array
	void GetResourceListItems( plmxml_api::Array<ResourceListItem*> &array ) const;
	     
	//! Detach and delete i'th ResourceListItem child element
	void DeleteResourceListItem( int i );
     
	//! Detach and delete 'arg' if it's one of the ResourceListItem child elements
	void DeleteResourceListItem( ResourceListItem *arg );
 
// <PLMXML_UserCode type="functionHeaderResourceList" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassResourceList;


////////////////////////////////////////////////////////////////////////////////////
//! ChangeRevision class
/*!
\verbatim

      A revision of a ChangeOrder.
      
\endverbatim
*/
class PLMXML_PDM60_API ChangeRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ChangeRevision( );
     
    //! Constructs a ChangeRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChangeRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChangeRevision();

private:

	//! Assignment operator
	ChangeRevision& operator=( const ChangeRevision& iSrc );

	//! Copy constructor
	ChangeRevision( const ChangeRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderChangeRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassChangeRevision;


////////////////////////////////////////////////////////////////////////////////////
//! IncChange class
/*!
\verbatim

      An incremental change to an element.

      Attributes:

      type:             The type or operation of the incremental change.
      engChangeRef:     References the ChangeRevision that represents the
                        engineering change.
      affectedRef:      References the affected element.

      Sub-elements:

      UserData:         Inherited from AttribOwner. If type is modify, UserData
                        elements detail the changes to the properties.
      
\endverbatim
*/
class PLMXML_PDM60_API IncChange : public AttribOwner
{
public:
     
    //! Default constructor
    IncChange( );
     
    //! Constructs a IncChange with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IncChange( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IncChange();

private:

	//! Assignment operator
	IncChange& operator=( const IncChange& iSrc );

	//! Copy constructor
	IncChange( const IncChange& original );
     
public:

	//! Get Affected URI as plmxml_api::String
	plmxml_api::String GetAffectedURI() const;

	//! Set Affected URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAffectedURI( const plmxml_api::String& );
	
	//! Get the handle of Affected URI. Does not resolve the URI.
	plmxml_api::Result GetAffectedURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Affected URI. URI string is unchanged.
	plmxml_api::Result SetAffectedURI( const plmxml_api::Handle& );
	
	//! Resolve Affected URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAffectedURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Affected URI. Clears URI string and handle.
	plmxml_api::Result DeleteAffectedURI();
	
	//! Check if Affected URI is set
	plmxml_api::logical HasAffectedURI( ) const;
	

	//! Set Type
	plmxml_api::Result SetType( const eIncChangeEnum& arg );

	//! Get Type
	eIncChangeEnum GetType() const;

	//! Get EngChange URI as plmxml_api::String
	plmxml_api::String GetEngChangeURI() const;

	//! Set EngChange URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEngChangeURI( const plmxml_api::String& );
	
	//! Get the handle of EngChange URI. Does not resolve the URI.
	plmxml_api::Result GetEngChangeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of EngChange URI. URI string is unchanged.
	plmxml_api::Result SetEngChangeURI( const plmxml_api::Handle& );
	
	//! Resolve EngChange URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEngChangeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset EngChange URI. Clears URI string and handle.
	plmxml_api::Result DeleteEngChangeURI();
	
	//! Check if EngChange URI is set
	plmxml_api::logical HasEngChangeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderIncChange" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassIncChange;


////////////////////////////////////////////////////////////////////////////////////
//! DiagramTemplate class
/*!
\verbatim

      Template for a Diagram.

      Attributes:

      tool:             The tool used to create the DiagramTemplate.
      appDomain:        The application domain of the DiagramTemplate such as
                        functional, logical or electrical.
      hidePorts:        Whether to hide the ports on the associated Diagram.
      
\endverbatim
*/
class PLMXML_PDM60_API DiagramTemplate : public Structure
{
public:
     
    //! Default constructor
    DiagramTemplate( );
     
    //! Constructs a DiagramTemplate with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DiagramTemplate( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DiagramTemplate();

private:

	//! Assignment operator
	DiagramTemplate& operator=( const DiagramTemplate& iSrc );

	//! Copy constructor
	DiagramTemplate( const DiagramTemplate& original );
     
public:

	//! Set Tool
	plmxml_api::Result SetTool( const eDiagramToolEnum& arg );

	//! Get Tool
	eDiagramToolEnum GetTool() const;

	//! Set HidePorts
	plmxml_api::Result SetHidePorts( plmxml_api::logical arg );

	//! Get HidePorts
	plmxml_api::logical GetHidePorts() const;

	//! Check if HidePorts is set
	plmxml_api::logical HasHidePorts() const;

	//! Unset HidePorts
	plmxml_api::Result UnsetHidePorts();

	//! Get AppDomain of this DiagramTemplate
	plmxml_api::String GetAppDomain() const;

	//! Set AppDomain of this DiagramTemplate
	plmxml_api::Result SetAppDomain( const plmxml_api::String &s );
	
	//! Check if AppDomain is set
	plmxml_api::logical HasAppDomain( ) const;
	
	//! Unset AppDomain
	plmxml_api::Result UnsetAppDomain( );
 
// <PLMXML_UserCode type="functionHeaderDiagramTemplate" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDiagramTemplate;


////////////////////////////////////////////////////////////////////////////////////
//! DiagramTemplateRevision class
/*!
\verbatim

      Revision of a DiagramTemplate.
      
\endverbatim
*/
class PLMXML_PDM60_API DiagramTemplateRevision : public StructureRevision
{
public:
     
    //! Default constructor
    DiagramTemplateRevision( );
     
    //! Constructs a DiagramTemplateRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DiagramTemplateRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DiagramTemplateRevision();

private:

	//! Assignment operator
	DiagramTemplateRevision& operator=( const DiagramTemplateRevision& iSrc );

	//! Copy constructor
	DiagramTemplateRevision( const DiagramTemplateRevision& original );
     
public:

	//! Get MembershipRule URI as plmxml_api::String
	plmxml_api::String GetMembershipRuleURI() const;

	//! Set MembershipRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMembershipRuleURI( const plmxml_api::String& );
	
	//! Get the handle of MembershipRule URI. Does not resolve the URI.
	plmxml_api::Result GetMembershipRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of MembershipRule URI. URI string is unchanged.
	plmxml_api::Result SetMembershipRuleURI( const plmxml_api::Handle& );
	
	//! Resolve MembershipRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMembershipRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset MembershipRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteMembershipRuleURI();
	
	//! Check if MembershipRule URI is set
	plmxml_api::logical HasMembershipRuleURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderDiagramTemplateRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDiagramTemplateRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Diagram class
/*!
\verbatim

      Graphical representation of a product structure.
      
\endverbatim
*/
class PLMXML_PDM60_API Diagram : public Structure
{
public:
     
    //! Default constructor
    Diagram( );
     
    //! Constructs a Diagram with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Diagram( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Diagram();

private:

	//! Assignment operator
	Diagram& operator=( const Diagram& iSrc );

	//! Copy constructor
	Diagram( const Diagram& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDiagram" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDiagram;


////////////////////////////////////////////////////////////////////////////////////
//! DiagramRevision class
/*!
\verbatim

      Revision of a Diagram.

      Sub-elements:

      Representation:   Representation of the DiagramRevision.

      Attributes:

      representationRefs: Used in preference to Representation sub-elements.
      diagramTemplateRevisionRef: References the DiagramTemplateRevision.
      
\endverbatim
*/
class PLMXML_PDM60_API DiagramRevision : public StructureRevision
{
public:
     
    //! Default constructor
    DiagramRevision( );
     
    //! Constructs a DiagramRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DiagramRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DiagramRevision();

private:

	//! Assignment operator
	DiagramRevision& operator=( const DiagramRevision& iSrc );

	//! Copy constructor
	DiagramRevision( const DiagramRevision& original );
     
public:

	//! Get number of URIs in Representation
	int NumberOfRepresentationURIs() const;

	//! Get i'th URI in Representation
	plmxml_api::String GetRepresentationURI( int i ) const;

	//! Add a URI to Representation array. Call ResolveRepresentationURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRepresentationURI( const plmxml_api::String& u );

	//! Set i'th URI in Representation array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRepresentationURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Representation URI. Does not resolve the URI.
	plmxml_api::Result GetRepresentationURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Representation array.
	plmxml_api::Result AddRepresentationURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Representation array to point to 'handle'.
	plmxml_api::Result SetRepresentationURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Representation points to.
	plmxml_api::Result ResolveRepresentationURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Representation array.
	plmxml_api::Result DeleteRepresentationURI( int i );

	//! Remove all URIs from Representation array.
	plmxml_api::Result DeleteRepresentationURIs( );
	
	//! Check if Representation is set
	plmxml_api::logical HasRepresentationURIs( ) const;

	//! Get DiagramTemplateRevision URI as plmxml_api::String
	plmxml_api::String GetDiagramTemplateRevisionURI() const;

	//! Set DiagramTemplateRevision URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDiagramTemplateRevisionURI( const plmxml_api::String& );
	
	//! Get the handle of DiagramTemplateRevision URI. Does not resolve the URI.
	plmxml_api::Result GetDiagramTemplateRevisionURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of DiagramTemplateRevision URI. URI string is unchanged.
	plmxml_api::Result SetDiagramTemplateRevisionURI( const plmxml_api::Handle& );
	
	//! Resolve DiagramTemplateRevision URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDiagramTemplateRevisionURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset DiagramTemplateRevision URI. Clears URI string and handle.
	plmxml_api::Result DeleteDiagramTemplateRevisionURI();
	
	//! Check if DiagramTemplateRevision URI is set
	plmxml_api::logical HasDiagramTemplateRevisionURI( ) const;
	

	//! Add Representation child element to this DiagramRevision. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Representation *AddRepresentation();
     
	//! Add 'arg' as Representation child element to this DiagramRevision.
	plmxml_api::Result AddRepresentation( Representation *arg );

	//! Detach and delete all Representation child elements.
	void DeleteRepresentations();
     
	//! Get number of Representation child elements.
	int NumberOfRepresentations() const;
     
	//! Get i'th Representation child element.
	Representation *GetRepresentation( int i ) const;
     
	//! Get all Representation child element as an array
	void GetRepresentations( plmxml_api::Array<Representation*> &array ) const;
	     
	//! Detach and delete i'th Representation child element
	void DeleteRepresentation( int i );
     
	//! Detach and delete 'arg' if it's one of the Representation child elements
	void DeleteRepresentation( Representation *arg );
 
// <PLMXML_UserCode type="functionHeaderDiagramRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDiagramRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ShapeRelation class
/*!
\verbatim

      Relates a Diagram shape to a product structure element.

      Attributes:

      shapeGraphics:    The tool specific string to render the shape.
      membershipType:   The membership type which brought the shape onto the
                        Diagram.
      userOmitted:      Whether the shape is deliberately omitted from the
                        Diagram by the user. 
      
\endverbatim
*/
class PLMXML_PDM60_API ShapeRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    ShapeRelation( );
     
    //! Constructs a ShapeRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ShapeRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ShapeRelation();

private:

	//! Assignment operator
	ShapeRelation& operator=( const ShapeRelation& iSrc );

	//! Copy constructor
	ShapeRelation( const ShapeRelation& original );
     
public:

	//! Get ShapeGraphics of this ShapeRelation
	plmxml_api::String GetShapeGraphics() const;

	//! Set ShapeGraphics of this ShapeRelation
	plmxml_api::Result SetShapeGraphics( const plmxml_api::String &s );
	
	//! Check if ShapeGraphics is set
	plmxml_api::logical HasShapeGraphics( ) const;
	
	//! Unset ShapeGraphics
	plmxml_api::Result UnsetShapeGraphics( );

	//! Set UserOmitted
	plmxml_api::Result SetUserOmitted( plmxml_api::logical arg );

	//! Get UserOmitted
	plmxml_api::logical GetUserOmitted() const;

	//! Check if UserOmitted is set
	plmxml_api::logical HasUserOmitted() const;

	//! Unset UserOmitted
	plmxml_api::Result UnsetUserOmitted();

	//! Set MembershipType
	plmxml_api::Result SetMembershipType( const eShapeMembershipEnum& arg );

	//! Get MembershipType
	eShapeMembershipEnum GetMembershipType() const;
 
// <PLMXML_UserCode type="functionHeaderShapeRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassShapeRelation;


////////////////////////////////////////////////////////////////////////////////////
//! DiagramRule class
/*!
\verbatim

      A list of Relation names for a DiagramTemplate.

      Sub-elements:

      DiagramRelations: The individual Relation names.
      
\endverbatim
*/
class PLMXML_PDM60_API DiagramRule : public AttribOwner
{
public:
     
    //! Default constructor
    DiagramRule( );
     
    //! Constructs a DiagramRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DiagramRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DiagramRule();

private:

	//! Assignment operator
	DiagramRule& operator=( const DiagramRule& iSrc );

	//! Copy constructor
	DiagramRule( const DiagramRule& original );
     
public:

	//! Add DiagramRelations child element to this DiagramRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	UserList *AddDiagramRelations();
     
	//! Set DiagramRelations child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDiagramRelations( UserList *arg );
     
	//! Get DiagramRelations child element of this DiagramRule.
	UserList *GetDiagramRelations() const;
     
	//! Detach and delete DiagramRelations child element tree from this DiagramRule.
	void DeleteDiagramRelations();
 
// <PLMXML_UserCode type="functionHeaderDiagramRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassDiagramRule;


////////////////////////////////////////////////////////////////////////////////////
//! AttributeGroup class
/*!
\verbatim

      A 4GD Attribute Group.

      Attributes:

      subType:          Inherited from Form. The value, "managed", indicates the
                        Attribute Group is managed. Otherwise, it is unmanaged.
      revision:         The revision of the Attribute Group.
      applicationModelRef: References the Application Model. For product
                        structure, this is a Collaborative Design.
      elementThreadRef: References the InstanceThread to which this Attribute
                        Group attaches.
      elementThread:    The identifier of the element thread of the Attribute
                        Group.

      Sub-elements:

      Parameter:        The name/value pairs of the attributes.
      VariantCondition: Switches the Attribute Group on.
      
\endverbatim
*/
class PLMXML_PDM60_API AttributeGroup : public Form
{
public:
     
    //! Default constructor
    AttributeGroup( );
     
    //! Constructs a AttributeGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AttributeGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AttributeGroup();

private:

	//! Assignment operator
	AttributeGroup& operator=( const AttributeGroup& iSrc );

	//! Copy constructor
	AttributeGroup( const AttributeGroup& original );
     
public:

	//! Get ApplicationModel URI as plmxml_api::String
	plmxml_api::String GetApplicationModelURI() const;

	//! Set ApplicationModel URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetApplicationModelURI( const plmxml_api::String& );
	
	//! Get the handle of ApplicationModel URI. Does not resolve the URI.
	plmxml_api::Result GetApplicationModelURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ApplicationModel URI. URI string is unchanged.
	plmxml_api::Result SetApplicationModelURI( const plmxml_api::Handle& );
	
	//! Resolve ApplicationModel URI and return an object (handle) it points to.
	plmxml_api::Result ResolveApplicationModelURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ApplicationModel URI. Clears URI string and handle.
	plmxml_api::Result DeleteApplicationModelURI();
	
	//! Check if ApplicationModel URI is set
	plmxml_api::logical HasApplicationModelURI( ) const;
	

	//! Get Revision of this AttributeGroup
	plmxml_api::String GetRevision() const;

	//! Set Revision of this AttributeGroup
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

	//! Get ElementThread of this AttributeGroup
	plmxml_api::String GetElementThread() const;

	//! Set ElementThread of this AttributeGroup
	plmxml_api::Result SetElementThread( const plmxml_api::String &s );
	
	//! Check if ElementThread is set
	plmxml_api::logical HasElementThread( ) const;
	
	//! Unset ElementThread
	plmxml_api::Result UnsetElementThread( );

	//! Get ElementThread URI as plmxml_api::String
	plmxml_api::String GetElementThreadURI() const;

	//! Set ElementThread URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetElementThreadURI( const plmxml_api::String& );
	
	//! Get the handle of ElementThread URI. Does not resolve the URI.
	plmxml_api::Result GetElementThreadURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ElementThread URI. URI string is unchanged.
	plmxml_api::Result SetElementThreadURI( const plmxml_api::Handle& );
	
	//! Resolve ElementThread URI and return an object (handle) it points to.
	plmxml_api::Result ResolveElementThreadURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ElementThread URI. Clears URI string and handle.
	plmxml_api::Result DeleteElementThreadURI();
	
	//! Check if ElementThread URI is set
	plmxml_api::logical HasElementThreadURI( ) const;
	

	//! Add Parameter child element to this AttributeGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddParameter();
     
	//! Add 'arg' as Parameter child element to this AttributeGroup.
	plmxml_api::Result AddParameter( UserValue *arg );

	//! Detach and delete all Parameter child elements.
	void DeleteParameters();
     
	//! Get number of Parameter child elements.
	int NumberOfParameters() const;
     
	//! Get i'th Parameter child element.
	UserValue *GetParameter( int i ) const;
     
	//! Get all Parameter child element as an array
	void GetParameters( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th Parameter child element
	void DeleteParameter( int i );
     
	//! Detach and delete 'arg' if it's one of the Parameter child elements
	void DeleteParameter( UserValue *arg );

	//! Add VariantCondition child element to this AttributeGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	VariantCondition *AddVariantCondition();
     
	//! Add 'arg' as VariantCondition child element to this AttributeGroup.
	plmxml_api::Result AddVariantCondition( VariantCondition *arg );

	//! Detach and delete all VariantCondition child elements.
	void DeleteVariantConditions();
     
	//! Get number of VariantCondition child elements.
	int NumberOfVariantConditions() const;
     
	//! Get i'th VariantCondition child element.
	VariantCondition *GetVariantCondition( int i ) const;
     
	//! Get all VariantCondition child element as an array
	void GetVariantConditions( plmxml_api::Array<VariantCondition*> &array ) const;
	     
	//! Detach and delete i'th VariantCondition child element
	void DeleteVariantCondition( int i );
     
	//! Detach and delete 'arg' if it's one of the VariantCondition child elements
	void DeleteVariantCondition( VariantCondition *arg );
 
// <PLMXML_UserCode type="functionHeaderAttributeGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassAttributeGroup;


////////////////////////////////////////////////////////////////////////////////////
//! Palette class
/*!
\verbatim

      A set of Model View Lists for a Disclosure.
      
\endverbatim
*/
class PLMXML_PDM60_API Palette : public Folder
{
public:
     
    //! Default constructor
    Palette( );
     
    //! Constructs a Palette with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Palette( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Palette();

private:

	//! Assignment operator
	Palette& operator=( const Palette& iSrc );

	//! Copy constructor
	Palette( const Palette& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPalette" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_PDM60_API plmxml_api::plmxmlClass plmxmlClassPalette;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
