/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 14:38:34
// 
// Schema:	PLMXMLSchedulingSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_SCHEDULING60_H__
#define __PLMXML_SCHEDULING60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_SCHEDULING60_EXPORTS
#define PLMXML_SCHEDULING60_API __declspec(dllexport)
#else
#define PLMXML_SCHEDULING60_API __declspec(dllimport)
#endif
#else
#define PLMXML_SCHEDULING60_API
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
//! eFixedCostAccrualEnum class
/*!
Allowed Values:
\verbatim
  eFixedCostAccrualEnumProrated
	"prorated"
  eFixedCostAccrualEnumStart
	"start"
  eFixedCostAccrualEnumEnd
	"end"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eFixedCostAccrualEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eFixedCostAccrualEnum( const char* Type );
     
	//! Constructor
	eFixedCostAccrualEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eFixedCostAccrualEnum( );
     
	//! Destructor 
	virtual ~eFixedCostAccrualEnum( );
     
	//! Assign from 'Type'
	const eFixedCostAccrualEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eFixedCostAccrualEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare FixedCostAccrualEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eFixedCostAccrualEnum& e1, const eFixedCostAccrualEnum& e2 );
     
	//! Compare FixedCostAccrualEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eFixedCostAccrualEnum& e1, const eFixedCostAccrualEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumFixedCostAccrualEnum;
extern PLMXML_SCHEDULING60_API eFixedCostAccrualEnum eFixedCostAccrualEnumUnset;
extern PLMXML_SCHEDULING60_API eFixedCostAccrualEnum eFixedCostAccrualEnumProrated;
extern PLMXML_SCHEDULING60_API eFixedCostAccrualEnum eFixedCostAccrualEnumStart;
extern PLMXML_SCHEDULING60_API eFixedCostAccrualEnum eFixedCostAccrualEnumEnd;

////////////////////////////////////////////////////////////////////////////////////
//! eWorkflowTriggerEnum class
/*!
Allowed Values:
\verbatim
  eWorkflowTriggerEnumBoth
	"both"
  eWorkflowTriggerEnumNone
	"none"
  eWorkflowTriggerEnumStart
	"start"
  eWorkflowTriggerEnumEither
	"either"
  eWorkflowTriggerEnumPredecessors
	"predecessors"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eWorkflowTriggerEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWorkflowTriggerEnum( const char* Type );
     
	//! Constructor
	eWorkflowTriggerEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWorkflowTriggerEnum( );
     
	//! Destructor 
	virtual ~eWorkflowTriggerEnum( );
     
	//! Assign from 'Type'
	const eWorkflowTriggerEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWorkflowTriggerEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WorkflowTriggerEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eWorkflowTriggerEnum& e1, const eWorkflowTriggerEnum& e2 );
     
	//! Compare WorkflowTriggerEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eWorkflowTriggerEnum& e1, const eWorkflowTriggerEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWorkflowTriggerEnum;
extern PLMXML_SCHEDULING60_API eWorkflowTriggerEnum eWorkflowTriggerEnumUnset;
extern PLMXML_SCHEDULING60_API eWorkflowTriggerEnum eWorkflowTriggerEnumBoth;
extern PLMXML_SCHEDULING60_API eWorkflowTriggerEnum eWorkflowTriggerEnumNone;
extern PLMXML_SCHEDULING60_API eWorkflowTriggerEnum eWorkflowTriggerEnumStart;
extern PLMXML_SCHEDULING60_API eWorkflowTriggerEnum eWorkflowTriggerEnumEither;
extern PLMXML_SCHEDULING60_API eWorkflowTriggerEnum eWorkflowTriggerEnumPredecessors;

////////////////////////////////////////////////////////////////////////////////////
//! eCalendarEnum class
/*!
Allowed Values:
\verbatim
  eCalendarEnumScheduleMember
	"scheduleMember"
  eCalendarEnumResource
	"resource"
  eCalendarEnumBase
	"base"
  eCalendarEnumSchedule
	"schedule"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eCalendarEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCalendarEnum( const char* Type );
     
	//! Constructor
	eCalendarEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCalendarEnum( );
     
	//! Destructor 
	virtual ~eCalendarEnum( );
     
	//! Assign from 'Type'
	const eCalendarEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCalendarEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CalendarEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eCalendarEnum& e1, const eCalendarEnum& e2 );
     
	//! Compare CalendarEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eCalendarEnum& e1, const eCalendarEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCalendarEnum;
extern PLMXML_SCHEDULING60_API eCalendarEnum eCalendarEnumUnset;
extern PLMXML_SCHEDULING60_API eCalendarEnum eCalendarEnumScheduleMember;
extern PLMXML_SCHEDULING60_API eCalendarEnum eCalendarEnumResource;
extern PLMXML_SCHEDULING60_API eCalendarEnum eCalendarEnumBase;
extern PLMXML_SCHEDULING60_API eCalendarEnum eCalendarEnumSchedule;

////////////////////////////////////////////////////////////////////////////////////
//! eTimeCategoryEnum class
/*!
Allowed Values:
\verbatim
  eTimeCategoryEnumHoliday
	"holiday"
  eTimeCategoryEnumVacation
	"vacation"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eTimeCategoryEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTimeCategoryEnum( const char* Type );
     
	//! Constructor
	eTimeCategoryEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTimeCategoryEnum( );
     
	//! Destructor 
	virtual ~eTimeCategoryEnum( );
     
	//! Assign from 'Type'
	const eTimeCategoryEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTimeCategoryEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TimeCategoryEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eTimeCategoryEnum& e1, const eTimeCategoryEnum& e2 );
     
	//! Compare TimeCategoryEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eTimeCategoryEnum& e1, const eTimeCategoryEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTimeCategoryEnum;
extern PLMXML_SCHEDULING60_API eTimeCategoryEnum eTimeCategoryEnumUnset;
extern PLMXML_SCHEDULING60_API eTimeCategoryEnum eTimeCategoryEnumHoliday;
extern PLMXML_SCHEDULING60_API eTimeCategoryEnum eTimeCategoryEnumVacation;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleTaskDeliverableSubmitEnum class
/*!
Allowed Values:
\verbatim
  eScheduleTaskDeliverableSubmitEnumReference
	"reference"
  eScheduleTaskDeliverableSubmitEnumTarget
	"target"
  eScheduleTaskDeliverableSubmitEnumNone
	"none"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleTaskDeliverableSubmitEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleTaskDeliverableSubmitEnum( const char* Type );
     
	//! Constructor
	eScheduleTaskDeliverableSubmitEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleTaskDeliverableSubmitEnum( );
     
	//! Destructor 
	virtual ~eScheduleTaskDeliverableSubmitEnum( );
     
	//! Assign from 'Type'
	const eScheduleTaskDeliverableSubmitEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleTaskDeliverableSubmitEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleTaskDeliverableSubmitEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleTaskDeliverableSubmitEnum& e1, const eScheduleTaskDeliverableSubmitEnum& e2 );
     
	//! Compare ScheduleTaskDeliverableSubmitEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleTaskDeliverableSubmitEnum& e1, const eScheduleTaskDeliverableSubmitEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleTaskDeliverableSubmitEnum;
extern PLMXML_SCHEDULING60_API eScheduleTaskDeliverableSubmitEnum eScheduleTaskDeliverableSubmitEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleTaskDeliverableSubmitEnum eScheduleTaskDeliverableSubmitEnumReference;
extern PLMXML_SCHEDULING60_API eScheduleTaskDeliverableSubmitEnum eScheduleTaskDeliverableSubmitEnumTarget;
extern PLMXML_SCHEDULING60_API eScheduleTaskDeliverableSubmitEnum eScheduleTaskDeliverableSubmitEnumNone;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleTaskFixedEnum class
/*!
Allowed Values:
\verbatim
  eScheduleTaskFixedEnumWork
	"work"
  eScheduleTaskFixedEnumDuration
	"duration"
  eScheduleTaskFixedEnumResources
	"resources"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleTaskFixedEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleTaskFixedEnum( const char* Type );
     
	//! Constructor
	eScheduleTaskFixedEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleTaskFixedEnum( );
     
	//! Destructor 
	virtual ~eScheduleTaskFixedEnum( );
     
	//! Assign from 'Type'
	const eScheduleTaskFixedEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleTaskFixedEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleTaskFixedEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleTaskFixedEnum& e1, const eScheduleTaskFixedEnum& e2 );
     
	//! Compare ScheduleTaskFixedEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleTaskFixedEnum& e1, const eScheduleTaskFixedEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleTaskFixedEnum;
extern PLMXML_SCHEDULING60_API eScheduleTaskFixedEnum eScheduleTaskFixedEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleTaskFixedEnum eScheduleTaskFixedEnumWork;
extern PLMXML_SCHEDULING60_API eScheduleTaskFixedEnum eScheduleTaskFixedEnumDuration;
extern PLMXML_SCHEDULING60_API eScheduleTaskFixedEnum eScheduleTaskFixedEnumResources;

////////////////////////////////////////////////////////////////////////////////////
//! eFixedCostBillingTypeEnum class
/*!
Allowed Values:
\verbatim
  eFixedCostBillingTypeEnumStandard
	"standard"
  eFixedCostBillingTypeEnumBillable
	"billable"
  eFixedCostBillingTypeEnumBilled
	"billed"
  eFixedCostBillingTypeEnumUnbillable
	"unbillable"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eFixedCostBillingTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eFixedCostBillingTypeEnum( const char* Type );
     
	//! Constructor
	eFixedCostBillingTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eFixedCostBillingTypeEnum( );
     
	//! Destructor 
	virtual ~eFixedCostBillingTypeEnum( );
     
	//! Assign from 'Type'
	const eFixedCostBillingTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eFixedCostBillingTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare FixedCostBillingTypeEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eFixedCostBillingTypeEnum& e1, const eFixedCostBillingTypeEnum& e2 );
     
	//! Compare FixedCostBillingTypeEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eFixedCostBillingTypeEnum& e1, const eFixedCostBillingTypeEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumFixedCostBillingTypeEnum;
extern PLMXML_SCHEDULING60_API eFixedCostBillingTypeEnum eFixedCostBillingTypeEnumUnset;
extern PLMXML_SCHEDULING60_API eFixedCostBillingTypeEnum eFixedCostBillingTypeEnumStandard;
extern PLMXML_SCHEDULING60_API eFixedCostBillingTypeEnum eFixedCostBillingTypeEnumBillable;
extern PLMXML_SCHEDULING60_API eFixedCostBillingTypeEnum eFixedCostBillingTypeEnumBilled;
extern PLMXML_SCHEDULING60_API eFixedCostBillingTypeEnum eFixedCostBillingTypeEnumUnbillable;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleProgressEnum class
/*!
Allowed Values:
\verbatim
  eScheduleProgressEnumAborted
	"aborted"
  eScheduleProgressEnumLate
	"late"
  eScheduleProgressEnumInProgress
	"inProgress"
  eScheduleProgressEnumNeedsAttention
	"needsAttention"
  eScheduleProgressEnumAbandoned
	"abandoned"
  eScheduleProgressEnumNotStarted
	"notStarted"
  eScheduleProgressEnumClosed
	"closed"
  eScheduleProgressEnumComplete
	"complete"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleProgressEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleProgressEnum( const char* Type );
     
	//! Constructor
	eScheduleProgressEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleProgressEnum( );
     
	//! Destructor 
	virtual ~eScheduleProgressEnum( );
     
	//! Assign from 'Type'
	const eScheduleProgressEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleProgressEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleProgressEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleProgressEnum& e1, const eScheduleProgressEnum& e2 );
     
	//! Compare ScheduleProgressEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleProgressEnum& e1, const eScheduleProgressEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleProgressEnum;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumAborted;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumLate;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumInProgress;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumNeedsAttention;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumAbandoned;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumNotStarted;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumClosed;
extern PLMXML_SCHEDULING60_API eScheduleProgressEnum eScheduleProgressEnumComplete;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleEnum class
/*!
Allowed Values:
\verbatim
  eScheduleEnumMaster
	"master"
  eScheduleEnumSub
	"sub"
  eScheduleEnumMasterSub
	"masterSub"
  eScheduleEnumNormal
	"normal"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleEnum( const char* Type );
     
	//! Constructor
	eScheduleEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleEnum( );
     
	//! Destructor 
	virtual ~eScheduleEnum( );
     
	//! Assign from 'Type'
	const eScheduleEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleEnum& e1, const eScheduleEnum& e2 );
     
	//! Compare ScheduleEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleEnum& e1, const eScheduleEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleEnum;
extern PLMXML_SCHEDULING60_API eScheduleEnum eScheduleEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleEnum eScheduleEnumMaster;
extern PLMXML_SCHEDULING60_API eScheduleEnum eScheduleEnumSub;
extern PLMXML_SCHEDULING60_API eScheduleEnum eScheduleEnumMasterSub;
extern PLMXML_SCHEDULING60_API eScheduleEnum eScheduleEnumNormal;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleTaskEnum class
/*!
Allowed Values:
\verbatim
  eScheduleTaskEnumOrphan
	"orphan"
  eScheduleTaskEnumScheduleSummary
	"scheduleSummary"
  eScheduleTaskEnumGate
	"gate"
  eScheduleTaskEnumPhase
	"phase"
  eScheduleTaskEnumSummary
	"summary"
  eScheduleTaskEnumStandard
	"standard"
  eScheduleTaskEnumMilestone
	"milestone"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleTaskEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleTaskEnum( const char* Type );
     
	//! Constructor
	eScheduleTaskEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleTaskEnum( );
     
	//! Destructor 
	virtual ~eScheduleTaskEnum( );
     
	//! Assign from 'Type'
	const eScheduleTaskEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleTaskEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleTaskEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleTaskEnum& e1, const eScheduleTaskEnum& e2 );
     
	//! Compare ScheduleTaskEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleTaskEnum& e1, const eScheduleTaskEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleTaskEnum;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumOrphan;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumScheduleSummary;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumGate;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumPhase;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumSummary;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumStandard;
extern PLMXML_SCHEDULING60_API eScheduleTaskEnum eScheduleTaskEnumMilestone;

////////////////////////////////////////////////////////////////////////////////////
//! eSchedulePriorityEnum class
/*!
Allowed Values:
\verbatim
  eSchedulePriorityEnumLow
	"low"
  eSchedulePriorityEnumMediumLow
	"mediumLow"
  eSchedulePriorityEnumMedium
	"medium"
  eSchedulePriorityEnumHigh
	"high"
  eSchedulePriorityEnumLowest
	"lowest"
  eSchedulePriorityEnumHighest
	"highest"
  eSchedulePriorityEnumVeryHigh
	"veryHigh"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eSchedulePriorityEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSchedulePriorityEnum( const char* Type );
     
	//! Constructor
	eSchedulePriorityEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSchedulePriorityEnum( );
     
	//! Destructor 
	virtual ~eSchedulePriorityEnum( );
     
	//! Assign from 'Type'
	const eSchedulePriorityEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSchedulePriorityEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SchedulePriorityEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eSchedulePriorityEnum& e1, const eSchedulePriorityEnum& e2 );
     
	//! Compare SchedulePriorityEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eSchedulePriorityEnum& e1, const eSchedulePriorityEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSchedulePriorityEnum;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumUnset;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumLow;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumMediumLow;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumMedium;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumHigh;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumLowest;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumHighest;
extern PLMXML_SCHEDULING60_API eSchedulePriorityEnum eSchedulePriorityEnumVeryHigh;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleTaskDependencyEnum class
/*!
Allowed Values:
\verbatim
  eScheduleTaskDependencyEnumEndToEnd
	"endToEnd"
  eScheduleTaskDependencyEnumStartToStart
	"startToStart"
  eScheduleTaskDependencyEnumEndToStart
	"endToStart"
  eScheduleTaskDependencyEnumPhaseGate
	"phaseGate"
  eScheduleTaskDependencyEnumStartToEnd
	"startToEnd"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleTaskDependencyEnum( const char* Type );
     
	//! Constructor
	eScheduleTaskDependencyEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleTaskDependencyEnum( );
     
	//! Destructor 
	virtual ~eScheduleTaskDependencyEnum( );
     
	//! Assign from 'Type'
	const eScheduleTaskDependencyEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleTaskDependencyEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleTaskDependencyEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleTaskDependencyEnum& e1, const eScheduleTaskDependencyEnum& e2 );
     
	//! Compare ScheduleTaskDependencyEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleTaskDependencyEnum& e1, const eScheduleTaskDependencyEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleTaskDependencyEnum;
extern PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum eScheduleTaskDependencyEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum eScheduleTaskDependencyEnumEndToEnd;
extern PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum eScheduleTaskDependencyEnumStartToStart;
extern PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum eScheduleTaskDependencyEnumEndToStart;
extern PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum eScheduleTaskDependencyEnumPhaseGate;
extern PLMXML_SCHEDULING60_API eScheduleTaskDependencyEnum eScheduleTaskDependencyEnumStartToEnd;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleTaskConstraintEnum class
/*!
Allowed Values:
\verbatim
  eScheduleTaskConstraintEnumFixed
	"fixed"
  eScheduleTaskConstraintEnumAsSoonAsPossible
	"asSoonAsPossible"
  eScheduleTaskConstraintEnumStartNoLaterThan
	"startNoLaterThan"
  eScheduleTaskConstraintEnumAsLateAsPossible
	"asLateAsPossible"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleTaskConstraintEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleTaskConstraintEnum( const char* Type );
     
	//! Constructor
	eScheduleTaskConstraintEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleTaskConstraintEnum( );
     
	//! Destructor 
	virtual ~eScheduleTaskConstraintEnum( );
     
	//! Assign from 'Type'
	const eScheduleTaskConstraintEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleTaskConstraintEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleTaskConstraintEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleTaskConstraintEnum& e1, const eScheduleTaskConstraintEnum& e2 );
     
	//! Compare ScheduleTaskConstraintEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleTaskConstraintEnum& e1, const eScheduleTaskConstraintEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleTaskConstraintEnum;
extern PLMXML_SCHEDULING60_API eScheduleTaskConstraintEnum eScheduleTaskConstraintEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleTaskConstraintEnum eScheduleTaskConstraintEnumFixed;
extern PLMXML_SCHEDULING60_API eScheduleTaskConstraintEnum eScheduleTaskConstraintEnumAsSoonAsPossible;
extern PLMXML_SCHEDULING60_API eScheduleTaskConstraintEnum eScheduleTaskConstraintEnumStartNoLaterThan;
extern PLMXML_SCHEDULING60_API eScheduleTaskConstraintEnum eScheduleTaskConstraintEnumAsLateAsPossible;

////////////////////////////////////////////////////////////////////////////////////
//! eCalendarEventEnum class
/*!
Allowed Values:
\verbatim
  eCalendarEventEnumYearly
	"yearly"
  eCalendarEventEnumWeekly
	"weekly"
  eCalendarEventEnumMonthly
	"monthly"
  eCalendarEventEnumDaily
	"daily"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eCalendarEventEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCalendarEventEnum( const char* Type );
     
	//! Constructor
	eCalendarEventEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCalendarEventEnum( );
     
	//! Destructor 
	virtual ~eCalendarEventEnum( );
     
	//! Assign from 'Type'
	const eCalendarEventEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCalendarEventEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CalendarEventEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eCalendarEventEnum& e1, const eCalendarEventEnum& e2 );
     
	//! Compare CalendarEventEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eCalendarEventEnum& e1, const eCalendarEventEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCalendarEventEnum;
extern PLMXML_SCHEDULING60_API eCalendarEventEnum eCalendarEventEnumUnset;
extern PLMXML_SCHEDULING60_API eCalendarEventEnum eCalendarEventEnumYearly;
extern PLMXML_SCHEDULING60_API eCalendarEventEnum eCalendarEventEnumWeekly;
extern PLMXML_SCHEDULING60_API eCalendarEventEnum eCalendarEventEnumMonthly;
extern PLMXML_SCHEDULING60_API eCalendarEventEnum eCalendarEventEnumDaily;

////////////////////////////////////////////////////////////////////////////////////
//! eScheduleMemberPrivilegeEnum class
/*!
Allowed Values:
\verbatim
  eScheduleMemberPrivilegeEnumParticipant
	"participant"
  eScheduleMemberPrivilegeEnumProxy
	"proxy"
  eScheduleMemberPrivilegeEnumObserver
	"observer"
  eScheduleMemberPrivilegeEnumCoordinator
	"coordinator"
  
\endverbatim
*/
class PLMXML_SCHEDULING60_API eScheduleMemberPrivilegeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eScheduleMemberPrivilegeEnum( const char* Type );
     
	//! Constructor
	eScheduleMemberPrivilegeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eScheduleMemberPrivilegeEnum( );
     
	//! Destructor 
	virtual ~eScheduleMemberPrivilegeEnum( );
     
	//! Assign from 'Type'
	const eScheduleMemberPrivilegeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eScheduleMemberPrivilegeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ScheduleMemberPrivilegeEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator==( const eScheduleMemberPrivilegeEnum& e1, const eScheduleMemberPrivilegeEnum& e2 );
     
	//! Compare ScheduleMemberPrivilegeEnum
	friend plmxml_api::logical PLMXML_SCHEDULING60_API operator!=( const eScheduleMemberPrivilegeEnum& e1, const eScheduleMemberPrivilegeEnum& e2 );
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumScheduleMemberPrivilegeEnum;
extern PLMXML_SCHEDULING60_API eScheduleMemberPrivilegeEnum eScheduleMemberPrivilegeEnumUnset;
extern PLMXML_SCHEDULING60_API eScheduleMemberPrivilegeEnum eScheduleMemberPrivilegeEnumParticipant;
extern PLMXML_SCHEDULING60_API eScheduleMemberPrivilegeEnum eScheduleMemberPrivilegeEnumProxy;
extern PLMXML_SCHEDULING60_API eScheduleMemberPrivilegeEnum eScheduleMemberPrivilegeEnumObserver;
extern PLMXML_SCHEDULING60_API eScheduleMemberPrivilegeEnum eScheduleMemberPrivilegeEnumCoordinator;

////////////////////////////////////////////////////////////////////////////////////
//! BillingRate class
/*!
\verbatim

      Override the billing rates for the ScheduleMember elements assigned to a
      ScheduleTaskRevision.

      Attributes:

      isMultiplier:   Whether the BillingRate multiplies the billing rates for
                      the ScheduleMember elements assigned to the
                      ScheduleTaskRevision.
      multiplier:     The factor by which the billing rates for the
                      ScheduleMember elements assigned to the
                      ScheduleTaskRevision is multiplied.
      moneyRef:       A reference to the Money that overrides the billing
                      rates for the ScheduleMember elements assigned to the
                      ScheduleTaskRevision.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API BillingRate : public AttribOwner
{
public:
     
    //! Default constructor
    BillingRate( );
     
    //! Constructs a BillingRate with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BillingRate( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BillingRate();

private:

	//! Assignment operator
	BillingRate& operator=( const BillingRate& iSrc );

	//! Copy constructor
	BillingRate( const BillingRate& original );
     
public:

	//! Set IsMultiplier
	plmxml_api::Result SetIsMultiplier( plmxml_api::logical arg );

	//! Get IsMultiplier
	plmxml_api::logical GetIsMultiplier() const;

	//! Check if IsMultiplier is set
	plmxml_api::logical HasIsMultiplier() const;

	//! Unset IsMultiplier
	plmxml_api::Result UnsetIsMultiplier();

	//! Set Multiplier
	plmxml_api::Result SetMultiplier( double arg );

     //! Get Multiplier
	double GetMultiplier() const;

	//! Check if Multiplier is set
	plmxml_api::logical HasMultiplier() const;

	//! Unset Multiplier
	plmxml_api::Result UnsetMultiplier();

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
	
 
// <PLMXML_UserCode type="functionHeaderBillingRate" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassBillingRate;


////////////////////////////////////////////////////////////////////////////////////
//! DailyTime class
/*!
\verbatim

      Represents a range of time during a day.

      Attributes:

      start:          The time of day at which the range of time starts.
      end:            The time of day at which the range of time ends.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API DailyTime : public AttribOwner
{
public:
     
    //! Default constructor
    DailyTime( );
     
    //! Constructs a DailyTime with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DailyTime( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DailyTime();

private:

	//! Assignment operator
	DailyTime& operator=( const DailyTime& iSrc );

	//! Copy constructor
	DailyTime( const DailyTime& original );
     
public:

	//! Get End of this DailyTime
	plmxml_api::String GetEnd() const;

	//! Set End of this DailyTime
	plmxml_api::Result SetEnd( const plmxml_api::String &s );
	
	//! Check if End is set
	plmxml_api::logical HasEnd( ) const;
	
	//! Unset End
	plmxml_api::Result UnsetEnd( );

	//! Get Start of this DailyTime
	plmxml_api::String GetStart() const;

	//! Set Start of this DailyTime
	plmxml_api::Result SetStart( const plmxml_api::String &s );
	
	//! Check if Start is set
	plmxml_api::logical HasStart( ) const;
	
	//! Unset Start
	plmxml_api::Result UnsetStart( );
 
// <PLMXML_UserCode type="functionHeaderDailyTime" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassDailyTime;


////////////////////////////////////////////////////////////////////////////////////
//! Calendar class
/*!
\verbatim

      Represents the range(s) of working time during a week.

      Attributes:

      baseCalendarType: A reference to any base Calendar.
      name:           Inherited from AttribOwnerBase.
      type:           The type of the calendar.
      timeZone:       The time zone code of the calendar according to
                      http://www.twinsun.com/tz/tz-link.htm. For example,
                      "Europe/Berlin".
      sundayRefs:     A list of references to the DailyTime elements for
                      Sunday. The working time is the union of the times of
                      the DailyTime elements.
      mondayRefs:     A list of references to the DailyTime elements for
                      Monday. The working time is the union of the times of
                      the DailyTime elements.
      tuesdayRefs:    A list of references to the DailyTime elements for
                      Tuesday. The working time is the union of the times of
                      the DailyTime elements.
      wednesdayRefs:  A list of references to the DailyTime elements for
                      Wednesday. The working time is the union of the times of
                      the DailyTime elements.
      thursdayRefs:   A list of references to the DailyTime elements for
                      Thursday. The working time is the union of the times of
                      the DailyTime elements.
      fridayRefs:     A list of references to the DailyTime elements for
                      Friday. The working time is the union of the times of
                      the DailyTime elements.
      saturdayRefs:   A list of references to the DailyTime elements for
                      Saturday. The working time is the union of the times of
                      the DailyTime elements.

      Sub-elements:

      Description:    Inherited from AttribOwnerBase.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API Calendar : public AttribOwner
{
public:
     
    //! Default constructor
    Calendar( );
     
    //! Constructs a Calendar with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Calendar( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Calendar();

private:

	//! Assignment operator
	Calendar& operator=( const Calendar& iSrc );

	//! Copy constructor
	Calendar( const Calendar& original );
     
public:

	//! Get number of URIs in Sunday
	int NumberOfSundayURIs() const;

	//! Get i'th URI in Sunday
	plmxml_api::String GetSundayURI( int i ) const;

	//! Add a URI to Sunday array. Call ResolveSundayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSundayURI( const plmxml_api::String& u );

	//! Set i'th URI in Sunday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSundayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Sunday URI. Does not resolve the URI.
	plmxml_api::Result GetSundayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Sunday array.
	plmxml_api::Result AddSundayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Sunday array to point to 'handle'.
	plmxml_api::Result SetSundayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Sunday points to.
	plmxml_api::Result ResolveSundayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Sunday array.
	plmxml_api::Result DeleteSundayURI( int i );

	//! Remove all URIs from Sunday array.
	plmxml_api::Result DeleteSundayURIs( );
	
	//! Check if Sunday is set
	plmxml_api::logical HasSundayURIs( ) const;

	//! Get number of URIs in Saturday
	int NumberOfSaturdayURIs() const;

	//! Get i'th URI in Saturday
	plmxml_api::String GetSaturdayURI( int i ) const;

	//! Add a URI to Saturday array. Call ResolveSaturdayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSaturdayURI( const plmxml_api::String& u );

	//! Set i'th URI in Saturday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSaturdayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Saturday URI. Does not resolve the URI.
	plmxml_api::Result GetSaturdayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Saturday array.
	plmxml_api::Result AddSaturdayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Saturday array to point to 'handle'.
	plmxml_api::Result SetSaturdayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Saturday points to.
	plmxml_api::Result ResolveSaturdayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Saturday array.
	plmxml_api::Result DeleteSaturdayURI( int i );

	//! Remove all URIs from Saturday array.
	plmxml_api::Result DeleteSaturdayURIs( );
	
	//! Check if Saturday is set
	plmxml_api::logical HasSaturdayURIs( ) const;

	//! Get number of URIs in Tuesday
	int NumberOfTuesdayURIs() const;

	//! Get i'th URI in Tuesday
	plmxml_api::String GetTuesdayURI( int i ) const;

	//! Add a URI to Tuesday array. Call ResolveTuesdayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTuesdayURI( const plmxml_api::String& u );

	//! Set i'th URI in Tuesday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTuesdayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Tuesday URI. Does not resolve the URI.
	plmxml_api::Result GetTuesdayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Tuesday array.
	plmxml_api::Result AddTuesdayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Tuesday array to point to 'handle'.
	plmxml_api::Result SetTuesdayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Tuesday points to.
	plmxml_api::Result ResolveTuesdayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Tuesday array.
	plmxml_api::Result DeleteTuesdayURI( int i );

	//! Remove all URIs from Tuesday array.
	plmxml_api::Result DeleteTuesdayURIs( );
	
	//! Check if Tuesday is set
	plmxml_api::logical HasTuesdayURIs( ) const;

	//! Get number of URIs in Friday
	int NumberOfFridayURIs() const;

	//! Get i'th URI in Friday
	plmxml_api::String GetFridayURI( int i ) const;

	//! Add a URI to Friday array. Call ResolveFridayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFridayURI( const plmxml_api::String& u );

	//! Set i'th URI in Friday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFridayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Friday URI. Does not resolve the URI.
	plmxml_api::Result GetFridayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Friday array.
	plmxml_api::Result AddFridayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Friday array to point to 'handle'.
	plmxml_api::Result SetFridayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Friday points to.
	plmxml_api::Result ResolveFridayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Friday array.
	plmxml_api::Result DeleteFridayURI( int i );

	//! Remove all URIs from Friday array.
	plmxml_api::Result DeleteFridayURIs( );
	
	//! Check if Friday is set
	plmxml_api::logical HasFridayURIs( ) const;

	//! Get number of URIs in Thursday
	int NumberOfThursdayURIs() const;

	//! Get i'th URI in Thursday
	plmxml_api::String GetThursdayURI( int i ) const;

	//! Add a URI to Thursday array. Call ResolveThursdayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddThursdayURI( const plmxml_api::String& u );

	//! Set i'th URI in Thursday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetThursdayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Thursday URI. Does not resolve the URI.
	plmxml_api::Result GetThursdayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Thursday array.
	plmxml_api::Result AddThursdayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Thursday array to point to 'handle'.
	plmxml_api::Result SetThursdayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Thursday points to.
	plmxml_api::Result ResolveThursdayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Thursday array.
	plmxml_api::Result DeleteThursdayURI( int i );

	//! Remove all URIs from Thursday array.
	plmxml_api::Result DeleteThursdayURIs( );
	
	//! Check if Thursday is set
	plmxml_api::logical HasThursdayURIs( ) const;

	//! Get BaseCalendar URI as plmxml_api::String
	plmxml_api::String GetBaseCalendarURI() const;

	//! Set BaseCalendar URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetBaseCalendarURI( const plmxml_api::String& );
	
	//! Get the handle of BaseCalendar URI. Does not resolve the URI.
	plmxml_api::Result GetBaseCalendarURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of BaseCalendar URI. URI string is unchanged.
	plmxml_api::Result SetBaseCalendarURI( const plmxml_api::Handle& );
	
	//! Resolve BaseCalendar URI and return an object (handle) it points to.
	plmxml_api::Result ResolveBaseCalendarURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset BaseCalendar URI. Clears URI string and handle.
	plmxml_api::Result DeleteBaseCalendarURI();
	
	//! Check if BaseCalendar URI is set
	plmxml_api::logical HasBaseCalendarURI( ) const;
	

	//! Set Type
	plmxml_api::Result SetType( const eCalendarEnum& arg );

	//! Get Type
	eCalendarEnum GetType() const;

	//! Get TimeZone of this Calendar
	plmxml_api::String GetTimeZone() const;

	//! Set TimeZone of this Calendar
	plmxml_api::Result SetTimeZone( const plmxml_api::String &s );
	
	//! Check if TimeZone is set
	plmxml_api::logical HasTimeZone( ) const;
	
	//! Unset TimeZone
	plmxml_api::Result UnsetTimeZone( );

	//! Get number of URIs in Wednesday
	int NumberOfWednesdayURIs() const;

	//! Get i'th URI in Wednesday
	plmxml_api::String GetWednesdayURI( int i ) const;

	//! Add a URI to Wednesday array. Call ResolveWednesdayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddWednesdayURI( const plmxml_api::String& u );

	//! Set i'th URI in Wednesday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetWednesdayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Wednesday URI. Does not resolve the URI.
	plmxml_api::Result GetWednesdayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Wednesday array.
	plmxml_api::Result AddWednesdayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Wednesday array to point to 'handle'.
	plmxml_api::Result SetWednesdayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Wednesday points to.
	plmxml_api::Result ResolveWednesdayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Wednesday array.
	plmxml_api::Result DeleteWednesdayURI( int i );

	//! Remove all URIs from Wednesday array.
	plmxml_api::Result DeleteWednesdayURIs( );
	
	//! Check if Wednesday is set
	plmxml_api::logical HasWednesdayURIs( ) const;

	//! Get number of URIs in Monday
	int NumberOfMondayURIs() const;

	//! Get i'th URI in Monday
	plmxml_api::String GetMondayURI( int i ) const;

	//! Add a URI to Monday array. Call ResolveMondayURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddMondayURI( const plmxml_api::String& u );

	//! Set i'th URI in Monday array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetMondayURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Monday URI. Does not resolve the URI.
	plmxml_api::Result GetMondayURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Monday array.
	plmxml_api::Result AddMondayURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Monday array to point to 'handle'.
	plmxml_api::Result SetMondayURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Monday points to.
	plmxml_api::Result ResolveMondayURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Monday array.
	plmxml_api::Result DeleteMondayURI( int i );

	//! Remove all URIs from Monday array.
	plmxml_api::Result DeleteMondayURIs( );
	
	//! Check if Monday is set
	plmxml_api::logical HasMondayURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderCalendar" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassCalendar;


////////////////////////////////////////////////////////////////////////////////////
//! CalendarEvent class
/*!
\verbatim

      Overrides the range(s) of working time during a day in a Calendar on a
      possibly recurring basis.

      Attributes:

      calendarRef:    A reference to the Calendar to which the override
                      applies.
      start:          For single day overrides, the date of the first
                      recurrence of the override. For multiple day overrides,
                      the date of the first day of the first recurrence of the
                      override.
      end:            For single day overrides, end is the same as start. For
                      multiple day overrides, the date of the last day of the
                      first recurrence of the override.
      expiry:         The date on which the override expires.
      dailyTimeRefs:  A list of references to the DailyTime elements for the
                      override. The working time is the union of the times of
                      the DailyTime elements.
      type:           The type of the override.
      recurrences:    The number of recurrences of the override.
      interval:       The number of days between recurrences of the override.
      days:           The days of the week on which recurrences of the
                      override occur.
      weeks:          The weeks of the month on which recurrences of the
                      override occur.
      months:         The months of the year on which recurrences of the
                      override occur.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API CalendarEvent : public AttribOwner
{
public:
     
    //! Default constructor
    CalendarEvent( );
     
    //! Constructs a CalendarEvent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CalendarEvent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CalendarEvent();

private:

	//! Assignment operator
	CalendarEvent& operator=( const CalendarEvent& iSrc );

	//! Copy constructor
	CalendarEvent( const CalendarEvent& original );
     
public:

	//! Set Interval
	plmxml_api::Result SetInterval( int arg );
     
	//! Get Interval
	int GetInterval() const;
     
	//! Check if Interval is set
	plmxml_api::logical HasInterval() const;
     
	//! Unset Interval
	plmxml_api::Result UnsetInterval();

     //! Set Months array
     plmxml_api::Result SetMonths( const plmxml_api::Array<int>& arg );
     
     //! Get Months array
     plmxml_api::Result GetMonths( plmxml_api::Array<int>& arg ) const;
     
     //! Check if Months array is set
     plmxml_api::logical HasMonths() const;
     
     //! Empty Months array
     plmxml_api::Result UnsetMonths();

     //! Set Days array
     plmxml_api::Result SetDays( const plmxml_api::Array<int>& arg );
     
     //! Get Days array
     plmxml_api::Result GetDays( plmxml_api::Array<int>& arg ) const;
     
     //! Check if Days array is set
     plmxml_api::logical HasDays() const;
     
     //! Empty Days array
     plmxml_api::Result UnsetDays();

	//! Get number of URIs in DailyTime
	int NumberOfDailyTimeURIs() const;

	//! Get i'th URI in DailyTime
	plmxml_api::String GetDailyTimeURI( int i ) const;

	//! Add a URI to DailyTime array. Call ResolveDailyTimeURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDailyTimeURI( const plmxml_api::String& u );

	//! Set i'th URI in DailyTime array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDailyTimeURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of DailyTime URI. Does not resolve the URI.
	plmxml_api::Result GetDailyTimeURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to DailyTime array.
	plmxml_api::Result AddDailyTimeURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in DailyTime array to point to 'handle'.
	plmxml_api::Result SetDailyTimeURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in DailyTime points to.
	plmxml_api::Result ResolveDailyTimeURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from DailyTime array.
	plmxml_api::Result DeleteDailyTimeURI( int i );

	//! Remove all URIs from DailyTime array.
	plmxml_api::Result DeleteDailyTimeURIs( );
	
	//! Check if DailyTime is set
	plmxml_api::logical HasDailyTimeURIs( ) const;

	//! Get Start of this CalendarEvent
	plmxml_api::String GetStart() const;

	//! Set Start of this CalendarEvent
	plmxml_api::Result SetStart( const plmxml_api::String &s );
	
	//! Check if Start is set
	plmxml_api::logical HasStart( ) const;
	
	//! Unset Start
	plmxml_api::Result UnsetStart( );

	//! Get End of this CalendarEvent
	plmxml_api::String GetEnd() const;

	//! Set End of this CalendarEvent
	plmxml_api::Result SetEnd( const plmxml_api::String &s );
	
	//! Check if End is set
	plmxml_api::logical HasEnd( ) const;
	
	//! Unset End
	plmxml_api::Result UnsetEnd( );

	//! Set Type
	plmxml_api::Result SetType( const eCalendarEventEnum& arg );

	//! Get Type
	eCalendarEventEnum GetType() const;

     //! Set Weeks array
     plmxml_api::Result SetWeeks( const plmxml_api::Array<int>& arg );
     
     //! Get Weeks array
     plmxml_api::Result GetWeeks( plmxml_api::Array<int>& arg ) const;
     
     //! Check if Weeks array is set
     plmxml_api::logical HasWeeks() const;
     
     //! Empty Weeks array
     plmxml_api::Result UnsetWeeks();

	//! Get Calendar URI as plmxml_api::String
	plmxml_api::String GetCalendarURI() const;

	//! Set Calendar URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCalendarURI( const plmxml_api::String& );
	
	//! Get the handle of Calendar URI. Does not resolve the URI.
	plmxml_api::Result GetCalendarURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Calendar URI. URI string is unchanged.
	plmxml_api::Result SetCalendarURI( const plmxml_api::Handle& );
	
	//! Resolve Calendar URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCalendarURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Calendar URI. Clears URI string and handle.
	plmxml_api::Result DeleteCalendarURI();
	
	//! Check if Calendar URI is set
	plmxml_api::logical HasCalendarURI( ) const;
	

	//! Get Expiry of this CalendarEvent
	plmxml_api::String GetExpiry() const;

	//! Set Expiry of this CalendarEvent
	plmxml_api::Result SetExpiry( const plmxml_api::String &s );
	
	//! Check if Expiry is set
	plmxml_api::logical HasExpiry( ) const;
	
	//! Unset Expiry
	plmxml_api::Result UnsetExpiry( );

	//! Set Recurrences
	plmxml_api::Result SetRecurrences( int arg );
     
	//! Get Recurrences
	int GetRecurrences() const;
     
	//! Check if Recurrences is set
	plmxml_api::logical HasRecurrences() const;
     
	//! Unset Recurrences
	plmxml_api::Result UnsetRecurrences();
 
// <PLMXML_UserCode type="functionHeaderCalendarEvent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassCalendarEvent;


////////////////////////////////////////////////////////////////////////////////////
//! FixedCost class
/*!
\verbatim

      Represents information about a single fixed cost.

      Attributes:

      accrual:        The type of accrual for the fixed cost.
      useActualCost:  Whether to use the actual cost, referenced by
                      actualCostRef. The default value of false means that the
                      estimated cost, referenced by estimatedCostRef, should
                      be used.
      billingCode:    The code for the billing of the fixed cost.
      billingSubCode: The sub code for the billing of the fixed cost.
      billingType:    Deprecated in favour of customBillingType.
      actualCostRef:  A reference to the Money element that represents the
                      actual fixed cost.
      estimatedCostRef: A reference to the Money element that represents the
                      estimated fixed cost.
      customBillingType: The type of billing for the fixed cost.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API FixedCost : public AttribOwner
{
public:
     
    //! Default constructor
    FixedCost( );
     
    //! Constructs a FixedCost with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FixedCost( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FixedCost();

private:

	//! Assignment operator
	FixedCost& operator=( const FixedCost& iSrc );

	//! Copy constructor
	FixedCost( const FixedCost& original );
     
public:

	//! Get EstimatedCost URI as plmxml_api::String
	plmxml_api::String GetEstimatedCostURI() const;

	//! Set EstimatedCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEstimatedCostURI( const plmxml_api::String& );
	
	//! Get the handle of EstimatedCost URI. Does not resolve the URI.
	plmxml_api::Result GetEstimatedCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of EstimatedCost URI. URI string is unchanged.
	plmxml_api::Result SetEstimatedCostURI( const plmxml_api::Handle& );
	
	//! Resolve EstimatedCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEstimatedCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset EstimatedCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteEstimatedCostURI();
	
	//! Check if EstimatedCost URI is set
	plmxml_api::logical HasEstimatedCostURI( ) const;
	

	//! Set BillingType
	plmxml_api::Result SetBillingType( const eFixedCostBillingTypeEnum& arg );

	//! Get BillingType
	eFixedCostBillingTypeEnum GetBillingType() const;

	//! Get ActualCost URI as plmxml_api::String
	plmxml_api::String GetActualCostURI() const;

	//! Set ActualCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActualCostURI( const plmxml_api::String& );
	
	//! Get the handle of ActualCost URI. Does not resolve the URI.
	plmxml_api::Result GetActualCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActualCost URI. URI string is unchanged.
	plmxml_api::Result SetActualCostURI( const plmxml_api::Handle& );
	
	//! Resolve ActualCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActualCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActualCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteActualCostURI();
	
	//! Check if ActualCost URI is set
	plmxml_api::logical HasActualCostURI( ) const;
	

	//! Get BillingSubCode of this FixedCost
	plmxml_api::String GetBillingSubCode() const;

	//! Set BillingSubCode of this FixedCost
	plmxml_api::Result SetBillingSubCode( const plmxml_api::String &s );
	
	//! Check if BillingSubCode is set
	plmxml_api::logical HasBillingSubCode( ) const;
	
	//! Unset BillingSubCode
	plmxml_api::Result UnsetBillingSubCode( );

	//! Get CustomBillingType of this FixedCost
	plmxml_api::String GetCustomBillingType() const;

	//! Set CustomBillingType of this FixedCost
	plmxml_api::Result SetCustomBillingType( const plmxml_api::String &s );
	
	//! Check if CustomBillingType is set
	plmxml_api::logical HasCustomBillingType( ) const;
	
	//! Unset CustomBillingType
	plmxml_api::Result UnsetCustomBillingType( );

	//! Set Accrual
	plmxml_api::Result SetAccrual( const eFixedCostAccrualEnum& arg );

	//! Get Accrual
	eFixedCostAccrualEnum GetAccrual() const;

	//! Set UseActualCost
	plmxml_api::Result SetUseActualCost( plmxml_api::logical arg );

	//! Get UseActualCost
	plmxml_api::logical GetUseActualCost() const;

	//! Check if UseActualCost is set
	plmxml_api::logical HasUseActualCost() const;

	//! Unset UseActualCost
	plmxml_api::Result UnsetUseActualCost();

	//! Get BillingCode of this FixedCost
	plmxml_api::String GetBillingCode() const;

	//! Set BillingCode of this FixedCost
	plmxml_api::Result SetBillingCode( const plmxml_api::String &s );
	
	//! Check if BillingCode is set
	plmxml_api::logical HasBillingCode( ) const;
	
	//! Unset BillingCode
	plmxml_api::Result UnsetBillingCode( );
 
// <PLMXML_UserCode type="functionHeaderFixedCost" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassFixedCost;


////////////////////////////////////////////////////////////////////////////////////
//! FixedCostInfo class
/*!
\verbatim

      Represents information about the fixed costs associated with a
      ScheduleRevision or ScheduleTaskRevision.

      Attributes:

      fixedCostRefs:  A list of references to the FixedCost elements that
                      represent the individual fixed costs.
      billingRateRef: A reference to the default BillingRate.
      billingCode:    The default code for the billing of the fixed costs.
      billingSubCode: The default sub code for the billing of the fixed costs.
      billingType:    Deprecated in favour of customBillingType.
      customBillingType: The default type of billing for the fixed costs.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API FixedCostInfo : public Attribute
{
public:
     
    //! Default constructor
    FixedCostInfo( );
     
    //! Constructs a FixedCostInfo with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FixedCostInfo( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FixedCostInfo();

private:

	//! Assignment operator
	FixedCostInfo& operator=( const FixedCostInfo& iSrc );

	//! Copy constructor
	FixedCostInfo( const FixedCostInfo& original );
     
public:

	//! Get BillingRate URI as plmxml_api::String
	plmxml_api::String GetBillingRateURI() const;

	//! Set BillingRate URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetBillingRateURI( const plmxml_api::String& );
	
	//! Get the handle of BillingRate URI. Does not resolve the URI.
	plmxml_api::Result GetBillingRateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of BillingRate URI. URI string is unchanged.
	plmxml_api::Result SetBillingRateURI( const plmxml_api::Handle& );
	
	//! Resolve BillingRate URI and return an object (handle) it points to.
	plmxml_api::Result ResolveBillingRateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset BillingRate URI. Clears URI string and handle.
	plmxml_api::Result DeleteBillingRateURI();
	
	//! Check if BillingRate URI is set
	plmxml_api::logical HasBillingRateURI( ) const;
	

	//! Set BillingType
	plmxml_api::Result SetBillingType( const eFixedCostBillingTypeEnum& arg );

	//! Get BillingType
	eFixedCostBillingTypeEnum GetBillingType() const;

	//! Get CustomBillingType of this FixedCostInfo
	plmxml_api::String GetCustomBillingType() const;

	//! Set CustomBillingType of this FixedCostInfo
	plmxml_api::Result SetCustomBillingType( const plmxml_api::String &s );
	
	//! Check if CustomBillingType is set
	plmxml_api::logical HasCustomBillingType( ) const;
	
	//! Unset CustomBillingType
	plmxml_api::Result UnsetCustomBillingType( );

	//! Get BillingSubCode of this FixedCostInfo
	plmxml_api::String GetBillingSubCode() const;

	//! Set BillingSubCode of this FixedCostInfo
	plmxml_api::Result SetBillingSubCode( const plmxml_api::String &s );
	
	//! Check if BillingSubCode is set
	plmxml_api::logical HasBillingSubCode( ) const;
	
	//! Unset BillingSubCode
	plmxml_api::Result UnsetBillingSubCode( );

	//! Get number of URIs in FixedCost
	int NumberOfFixedCostURIs() const;

	//! Get i'th URI in FixedCost
	plmxml_api::String GetFixedCostURI( int i ) const;

	//! Add a URI to FixedCost array. Call ResolveFixedCostURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFixedCostURI( const plmxml_api::String& u );

	//! Set i'th URI in FixedCost array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFixedCostURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of FixedCost URI. Does not resolve the URI.
	plmxml_api::Result GetFixedCostURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to FixedCost array.
	plmxml_api::Result AddFixedCostURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in FixedCost array to point to 'handle'.
	plmxml_api::Result SetFixedCostURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in FixedCost points to.
	plmxml_api::Result ResolveFixedCostURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from FixedCost array.
	plmxml_api::Result DeleteFixedCostURI( int i );

	//! Remove all URIs from FixedCost array.
	plmxml_api::Result DeleteFixedCostURIs( );
	
	//! Check if FixedCost is set
	plmxml_api::logical HasFixedCostURIs( ) const;

	//! Get BillingCode of this FixedCostInfo
	plmxml_api::String GetBillingCode() const;

	//! Set BillingCode of this FixedCostInfo
	plmxml_api::Result SetBillingCode( const plmxml_api::String &s );
	
	//! Check if BillingCode is set
	plmxml_api::logical HasBillingCode( ) const;
	
	//! Unset BillingCode
	plmxml_api::Result UnsetBillingCode( );
 
// <PLMXML_UserCode type="functionHeaderFixedCostInfo" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassFixedCostInfo;


////////////////////////////////////////////////////////////////////////////////////
//! Schedule class
/*!
\verbatim

      Represents a schedule.

      Attributes:

      name:           Inherited from StructureBase.
      customerName:   The name of the customer.
      customerNumber: The number of the customer.
      customerNameRef: References a multiple language version of customerName.
                      If multiple language support is required, customerNameRef
                      should be used in addition to customerName.
      customerNumberRef: References a multiple language version of
                      customerNumber. If multiple language support is required,
                      customerNumberRef should be used in addition to
                      customerNumber.
      activeBaselineRef: References the active baseline schedule.
      baselineRefs:   References the related baseline schedules.

      Sub-elements:

      Description:    Inherited from StructureBase.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API Schedule : public Structure
{
public:
     
    //! Default constructor
    Schedule( );
     
    //! Constructs a Schedule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Schedule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Schedule();

private:

	//! Assignment operator
	Schedule& operator=( const Schedule& iSrc );

	//! Copy constructor
	Schedule( const Schedule& original );
     
public:

	//! Get number of URIs in Baseline
	int NumberOfBaselineURIs() const;

	//! Get i'th URI in Baseline
	plmxml_api::String GetBaselineURI( int i ) const;

	//! Add a URI to Baseline array. Call ResolveBaselineURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddBaselineURI( const plmxml_api::String& u );

	//! Set i'th URI in Baseline array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetBaselineURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Baseline URI. Does not resolve the URI.
	plmxml_api::Result GetBaselineURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Baseline array.
	plmxml_api::Result AddBaselineURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Baseline array to point to 'handle'.
	plmxml_api::Result SetBaselineURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Baseline points to.
	plmxml_api::Result ResolveBaselineURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Baseline array.
	plmxml_api::Result DeleteBaselineURI( int i );

	//! Remove all URIs from Baseline array.
	plmxml_api::Result DeleteBaselineURIs( );
	
	//! Check if Baseline is set
	plmxml_api::logical HasBaselineURIs( ) const;

	//! Get CustomerName of this Schedule
	plmxml_api::String GetCustomerName() const;

	//! Set CustomerName of this Schedule
	plmxml_api::Result SetCustomerName( const plmxml_api::String &s );
	
	//! Check if CustomerName is set
	plmxml_api::logical HasCustomerName( ) const;
	
	//! Unset CustomerName
	plmxml_api::Result UnsetCustomerName( );

	//! Get CustomerName URI as plmxml_api::String
	plmxml_api::String GetCustomerNameURI() const;

	//! Set CustomerName URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCustomerNameURI( const plmxml_api::String& );
	
	//! Get the handle of CustomerName URI. Does not resolve the URI.
	plmxml_api::Result GetCustomerNameURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of CustomerName URI. URI string is unchanged.
	plmxml_api::Result SetCustomerNameURI( const plmxml_api::Handle& );
	
	//! Resolve CustomerName URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCustomerNameURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset CustomerName URI. Clears URI string and handle.
	plmxml_api::Result DeleteCustomerNameURI();
	
	//! Check if CustomerName URI is set
	plmxml_api::logical HasCustomerNameURI( ) const;
	

	//! Get ActiveBaseline URI as plmxml_api::String
	plmxml_api::String GetActiveBaselineURI() const;

	//! Set ActiveBaseline URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActiveBaselineURI( const plmxml_api::String& );
	
	//! Get the handle of ActiveBaseline URI. Does not resolve the URI.
	plmxml_api::Result GetActiveBaselineURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActiveBaseline URI. URI string is unchanged.
	plmxml_api::Result SetActiveBaselineURI( const plmxml_api::Handle& );
	
	//! Resolve ActiveBaseline URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActiveBaselineURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActiveBaseline URI. Clears URI string and handle.
	plmxml_api::Result DeleteActiveBaselineURI();
	
	//! Check if ActiveBaseline URI is set
	plmxml_api::logical HasActiveBaselineURI( ) const;
	

	//! Get CustomerNumber URI as plmxml_api::String
	plmxml_api::String GetCustomerNumberURI() const;

	//! Set CustomerNumber URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCustomerNumberURI( const plmxml_api::String& );
	
	//! Get the handle of CustomerNumber URI. Does not resolve the URI.
	plmxml_api::Result GetCustomerNumberURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of CustomerNumber URI. URI string is unchanged.
	plmxml_api::Result SetCustomerNumberURI( const plmxml_api::Handle& );
	
	//! Resolve CustomerNumber URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCustomerNumberURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset CustomerNumber URI. Clears URI string and handle.
	plmxml_api::Result DeleteCustomerNumberURI();
	
	//! Check if CustomerNumber URI is set
	plmxml_api::logical HasCustomerNumberURI( ) const;
	

	//! Get CustomerNumber of this Schedule
	plmxml_api::String GetCustomerNumber() const;

	//! Set CustomerNumber of this Schedule
	plmxml_api::Result SetCustomerNumber( const plmxml_api::String &s );
	
	//! Check if CustomerNumber is set
	plmxml_api::logical HasCustomerNumber( ) const;
	
	//! Unset CustomerNumber
	plmxml_api::Result UnsetCustomerNumber( );
 
// <PLMXML_UserCode type="functionHeaderSchedule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassSchedule;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleRevision class
/*!
\verbatim

      Represents a revision of a schedule.

      Attributes:

      isBaseline:     Whether the ScheduleRevision is a baseline.
      baselineCostRef: If the ScheduleRevision is a baseline, baselineCostRef
                      references a Money representing the baseline cost of the
                      ScheduleRevision. Deprecated.
      summaryTaskRef: A reference to the ScheduleTaskRevision that represents
                      a revision of the top-level summary task for this
                      ScheduleRevision.
      isTemplate:     Whether the ScheduleRevision is a template. Template
                      ScheduleRevision elements cannot be published or
                      executed.
      progress:       The progress of the ScheduleRevision.
      priority:       The priority of the ScheduleRevision.
      isPublished:    Whether the ScheduleMember elements assigned to the
                      ScheduleRevision have access to it.
      isPublic:       Whether ScheduleMember elements that are not assigned to
                      the ScheduleRevision have read access to it. The default
                      value is the value of the isPublished attribute.
      linksAllowed:   Whether the ScheduleTaskRevision elements of another
                      ScheduleRevision can be dependent on the
                      ScheduleTaskRevision elements of this ScheduleRevision.
      progressLinked: Whether the fraction complete is linked to the actual
                      work.
      schedulingInfoRequiresRecalc: Whether the scheduling information of the
                      ScheduleRevision requires recalculation.
      executionInfoRequiresRecalc: Whether the execution information of the
                      ScheduleRevision requires recalculation.
      masterSubInfoRequiresRecalc: Whether the master and sub information of
                      the ScheduleRevision requires recalculation.
      rightsMask:     Whether the ScheduleMember elements referenced by
                      scheduleMemberRefs can modify the ScheduleTaskRevision
                      referenced by the summaryTaskRef attribute.
      scheduledEndDate: When a ScheduleTaskRevision is completed, its end
                      attribute is set to its scheduled end date if
                      scheduledEndDate is true and to the system date if
                      scheduledEndDate is false.
      start:          The date and time of the start of the ScheduleRevision.
      end:            The date and time of the end of the ScheduleRevision.
      deliverableRefs: A list of references to the Deliverable elements for
                      this ScheduleRevision.
      scheduleMemberRefs: A list of references to the ScheduleMember elements
                      for this ScheduleRevision.
      notificationsEnabled: Whether notifications on the ScheduleRevision are
                      enabled.
      archiveNotifications: Whether the notifications are archived when the
                      ScheduleRevision is completed.
      latestStart:    The date and time of the latest allowable start of the
                      ScheduleRevision. The start date and time is not allowed
                      to be later even if a sub-schedule starts later.
      earliestEnd:    The date and time of the earliest allowable end of the
                      ScheduleRevision. The end date and time is not allowed
                      to be earlier even if a sub-schedule ends earlier.
      wBSFormat:      The format of the work breakdown structure identifier as
                      a string.
      wBSValue:       The value of the work breakdown structure identifier as
                      a string.
      useEnd:         Whether to use the date and time of the end of the
                      ScheduleRevision, given in the end attribute, for
                      scheduling. The default value is false, which means that
                      the date and time of the start of the ScheduleRevision,
                      given in the start attribute, should be used for
                      scheduling.
      type:           The type of the schedule.
      masterScheduleRef: Reference a Schedule, which represents the master
                      schedule when this Schedule/ScheduleRevision set
                      represents a sub-schedule.
      finalStatus:    The customizable status of the schedule.
      proxyTaskRefs:  References the proxy tasks.
      calendarRef:    References the related calendar.
      allowExecUpdate: Whether execution information of tasks in the schedule
                       may be updated after they have been closed, completed or
                       aborted.
      datesLinked:    Whether scheduled dates are updated to reflect reality
                      when actual dates are updated.

      Sub-elements:

      FixedCostInfo:  Any number of FixedCostInfo sub-elements hold additional
                      information about the fixed costs associated with the
                      ScheduleRevision. Deprecated.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ScheduleRevision( );
     
    //! Constructs a ScheduleRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleRevision();

private:

	//! Assignment operator
	ScheduleRevision& operator=( const ScheduleRevision& iSrc );

	//! Copy constructor
	ScheduleRevision( const ScheduleRevision& original );
     
public:

	//! Set NotificationsEnabled
	plmxml_api::Result SetNotificationsEnabled( plmxml_api::logical arg );

	//! Get NotificationsEnabled
	plmxml_api::logical GetNotificationsEnabled() const;

	//! Check if NotificationsEnabled is set
	plmxml_api::logical HasNotificationsEnabled() const;

	//! Unset NotificationsEnabled
	plmxml_api::Result UnsetNotificationsEnabled();

	//! Get number of URIs in ProxyTask
	int NumberOfProxyTaskURIs() const;

	//! Get i'th URI in ProxyTask
	plmxml_api::String GetProxyTaskURI( int i ) const;

	//! Add a URI to ProxyTask array. Call ResolveProxyTaskURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddProxyTaskURI( const plmxml_api::String& u );

	//! Set i'th URI in ProxyTask array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetProxyTaskURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ProxyTask URI. Does not resolve the URI.
	plmxml_api::Result GetProxyTaskURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ProxyTask array.
	plmxml_api::Result AddProxyTaskURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ProxyTask array to point to 'handle'.
	plmxml_api::Result SetProxyTaskURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ProxyTask points to.
	plmxml_api::Result ResolveProxyTaskURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ProxyTask array.
	plmxml_api::Result DeleteProxyTaskURI( int i );

	//! Remove all URIs from ProxyTask array.
	plmxml_api::Result DeleteProxyTaskURIs( );
	
	//! Check if ProxyTask is set
	plmxml_api::logical HasProxyTaskURIs( ) const;

	//! Get FinalStatus of this ScheduleRevision
	plmxml_api::String GetFinalStatus() const;

	//! Set FinalStatus of this ScheduleRevision
	plmxml_api::Result SetFinalStatus( const plmxml_api::String &s );
	
	//! Check if FinalStatus is set
	plmxml_api::logical HasFinalStatus( ) const;
	
	//! Unset FinalStatus
	plmxml_api::Result UnsetFinalStatus( );

	//! Get WBSFormat of this ScheduleRevision
	plmxml_api::String GetWBSFormat() const;

	//! Set WBSFormat of this ScheduleRevision
	plmxml_api::Result SetWBSFormat( const plmxml_api::String &s );
	
	//! Check if WBSFormat is set
	plmxml_api::logical HasWBSFormat( ) const;
	
	//! Unset WBSFormat
	plmxml_api::Result UnsetWBSFormat( );

	//! Set ScheduledEndDate
	plmxml_api::Result SetScheduledEndDate( plmxml_api::logical arg );

	//! Get ScheduledEndDate
	plmxml_api::logical GetScheduledEndDate() const;

	//! Check if ScheduledEndDate is set
	plmxml_api::logical HasScheduledEndDate() const;

	//! Unset ScheduledEndDate
	plmxml_api::Result UnsetScheduledEndDate();

	//! Get number of URIs in ScheduleMember
	int NumberOfScheduleMemberURIs() const;

	//! Get i'th URI in ScheduleMember
	plmxml_api::String GetScheduleMemberURI( int i ) const;

	//! Add a URI to ScheduleMember array. Call ResolveScheduleMemberURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddScheduleMemberURI( const plmxml_api::String& u );

	//! Set i'th URI in ScheduleMember array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetScheduleMemberURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ScheduleMember URI. Does not resolve the URI.
	plmxml_api::Result GetScheduleMemberURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ScheduleMember array.
	plmxml_api::Result AddScheduleMemberURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ScheduleMember array to point to 'handle'.
	plmxml_api::Result SetScheduleMemberURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ScheduleMember points to.
	plmxml_api::Result ResolveScheduleMemberURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ScheduleMember array.
	plmxml_api::Result DeleteScheduleMemberURI( int i );

	//! Remove all URIs from ScheduleMember array.
	plmxml_api::Result DeleteScheduleMemberURIs( );
	
	//! Check if ScheduleMember is set
	plmxml_api::logical HasScheduleMemberURIs( ) const;

	//! Set DatesLinked
	plmxml_api::Result SetDatesLinked( plmxml_api::logical arg );

	//! Get DatesLinked
	plmxml_api::logical GetDatesLinked() const;

	//! Check if DatesLinked is set
	plmxml_api::logical HasDatesLinked() const;

	//! Unset DatesLinked
	plmxml_api::Result UnsetDatesLinked();

	//! Set LinksAllowed
	plmxml_api::Result SetLinksAllowed( plmxml_api::logical arg );

	//! Get LinksAllowed
	plmxml_api::logical GetLinksAllowed() const;

	//! Check if LinksAllowed is set
	plmxml_api::logical HasLinksAllowed() const;

	//! Unset LinksAllowed
	plmxml_api::Result UnsetLinksAllowed();

	//! Get LatestStart of this ScheduleRevision
	plmxml_api::String GetLatestStart() const;

	//! Set LatestStart of this ScheduleRevision
	plmxml_api::Result SetLatestStart( const plmxml_api::String &s );
	
	//! Check if LatestStart is set
	plmxml_api::logical HasLatestStart( ) const;
	
	//! Unset LatestStart
	plmxml_api::Result UnsetLatestStart( );

	//! Set IsPublished
	plmxml_api::Result SetIsPublished( plmxml_api::logical arg );

	//! Get IsPublished
	plmxml_api::logical GetIsPublished() const;

	//! Check if IsPublished is set
	plmxml_api::logical HasIsPublished() const;

	//! Unset IsPublished
	plmxml_api::Result UnsetIsPublished();

	//! Set Progress
	plmxml_api::Result SetProgress( const eScheduleProgressEnum& arg );

	//! Get Progress
	eScheduleProgressEnum GetProgress() const;

	//! Set UseEnd
	plmxml_api::Result SetUseEnd( plmxml_api::logical arg );

	//! Get UseEnd
	plmxml_api::logical GetUseEnd() const;

	//! Check if UseEnd is set
	plmxml_api::logical HasUseEnd() const;

	//! Unset UseEnd
	plmxml_api::Result UnsetUseEnd();

	//! Get SummaryTask URI as plmxml_api::String
	plmxml_api::String GetSummaryTaskURI() const;

	//! Set SummaryTask URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSummaryTaskURI( const plmxml_api::String& );
	
	//! Get the handle of SummaryTask URI. Does not resolve the URI.
	plmxml_api::Result GetSummaryTaskURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of SummaryTask URI. URI string is unchanged.
	plmxml_api::Result SetSummaryTaskURI( const plmxml_api::Handle& );
	
	//! Resolve SummaryTask URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSummaryTaskURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset SummaryTask URI. Clears URI string and handle.
	plmxml_api::Result DeleteSummaryTaskURI();
	
	//! Check if SummaryTask URI is set
	plmxml_api::logical HasSummaryTaskURI( ) const;
	

	//! Get WBSValue of this ScheduleRevision
	plmxml_api::String GetWBSValue() const;

	//! Set WBSValue of this ScheduleRevision
	plmxml_api::Result SetWBSValue( const plmxml_api::String &s );
	
	//! Check if WBSValue is set
	plmxml_api::logical HasWBSValue( ) const;
	
	//! Unset WBSValue
	plmxml_api::Result UnsetWBSValue( );

	//! Set ProgressLinked
	plmxml_api::Result SetProgressLinked( plmxml_api::logical arg );

	//! Get ProgressLinked
	plmxml_api::logical GetProgressLinked() const;

	//! Check if ProgressLinked is set
	plmxml_api::logical HasProgressLinked() const;

	//! Unset ProgressLinked
	plmxml_api::Result UnsetProgressLinked();

	//! Set MasterSubInfoRequiresRecalc
	plmxml_api::Result SetMasterSubInfoRequiresRecalc( plmxml_api::logical arg );

	//! Get MasterSubInfoRequiresRecalc
	plmxml_api::logical GetMasterSubInfoRequiresRecalc() const;

	//! Check if MasterSubInfoRequiresRecalc is set
	plmxml_api::logical HasMasterSubInfoRequiresRecalc() const;

	//! Unset MasterSubInfoRequiresRecalc
	plmxml_api::Result UnsetMasterSubInfoRequiresRecalc();

	//! Get BaselineCost URI as plmxml_api::String
	plmxml_api::String GetBaselineCostURI() const;

	//! Set BaselineCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetBaselineCostURI( const plmxml_api::String& );
	
	//! Get the handle of BaselineCost URI. Does not resolve the URI.
	plmxml_api::Result GetBaselineCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of BaselineCost URI. URI string is unchanged.
	plmxml_api::Result SetBaselineCostURI( const plmxml_api::Handle& );
	
	//! Resolve BaselineCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveBaselineCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset BaselineCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteBaselineCostURI();
	
	//! Check if BaselineCost URI is set
	plmxml_api::logical HasBaselineCostURI( ) const;
	

	//! Set ArchiveNotifications
	plmxml_api::Result SetArchiveNotifications( plmxml_api::logical arg );

	//! Get ArchiveNotifications
	plmxml_api::logical GetArchiveNotifications() const;

	//! Check if ArchiveNotifications is set
	plmxml_api::logical HasArchiveNotifications() const;

	//! Unset ArchiveNotifications
	plmxml_api::Result UnsetArchiveNotifications();

	//! Set IsTemplate
	plmxml_api::Result SetIsTemplate( plmxml_api::logical arg );

	//! Get IsTemplate
	plmxml_api::logical GetIsTemplate() const;

	//! Check if IsTemplate is set
	plmxml_api::logical HasIsTemplate() const;

	//! Unset IsTemplate
	plmxml_api::Result UnsetIsTemplate();

	//! Set AllowExecUpdate
	plmxml_api::Result SetAllowExecUpdate( plmxml_api::logical arg );

	//! Get AllowExecUpdate
	plmxml_api::logical GetAllowExecUpdate() const;

	//! Check if AllowExecUpdate is set
	plmxml_api::logical HasAllowExecUpdate() const;

	//! Unset AllowExecUpdate
	plmxml_api::Result UnsetAllowExecUpdate();

	//! Get number of URIs in Deliverable
	int NumberOfDeliverableURIs() const;

	//! Get i'th URI in Deliverable
	plmxml_api::String GetDeliverableURI( int i ) const;

	//! Add a URI to Deliverable array. Call ResolveDeliverableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDeliverableURI( const plmxml_api::String& u );

	//! Set i'th URI in Deliverable array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDeliverableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Deliverable URI. Does not resolve the URI.
	plmxml_api::Result GetDeliverableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Deliverable array.
	plmxml_api::Result AddDeliverableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Deliverable array to point to 'handle'.
	plmxml_api::Result SetDeliverableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Deliverable points to.
	plmxml_api::Result ResolveDeliverableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Deliverable array.
	plmxml_api::Result DeleteDeliverableURI( int i );

	//! Remove all URIs from Deliverable array.
	plmxml_api::Result DeleteDeliverableURIs( );
	
	//! Check if Deliverable is set
	plmxml_api::logical HasDeliverableURIs( ) const;

	//! Get Calendar URI as plmxml_api::String
	plmxml_api::String GetCalendarURI() const;

	//! Set Calendar URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCalendarURI( const plmxml_api::String& );
	
	//! Get the handle of Calendar URI. Does not resolve the URI.
	plmxml_api::Result GetCalendarURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Calendar URI. URI string is unchanged.
	plmxml_api::Result SetCalendarURI( const plmxml_api::Handle& );
	
	//! Resolve Calendar URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCalendarURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Calendar URI. Clears URI string and handle.
	plmxml_api::Result DeleteCalendarURI();
	
	//! Check if Calendar URI is set
	plmxml_api::logical HasCalendarURI( ) const;
	

	//! Set IsBaseline
	plmxml_api::Result SetIsBaseline( plmxml_api::logical arg );

	//! Get IsBaseline
	plmxml_api::logical GetIsBaseline() const;

	//! Check if IsBaseline is set
	plmxml_api::logical HasIsBaseline() const;

	//! Unset IsBaseline
	plmxml_api::Result UnsetIsBaseline();

	//! Set RightsMask
	plmxml_api::Result SetRightsMask( plmxml_api::logical arg );

	//! Get RightsMask
	plmxml_api::logical GetRightsMask() const;

	//! Check if RightsMask is set
	plmxml_api::logical HasRightsMask() const;

	//! Unset RightsMask
	plmxml_api::Result UnsetRightsMask();

	//! Get End of this ScheduleRevision
	plmxml_api::String GetEnd() const;

	//! Set End of this ScheduleRevision
	plmxml_api::Result SetEnd( const plmxml_api::String &s );
	
	//! Check if End is set
	plmxml_api::logical HasEnd( ) const;
	
	//! Unset End
	plmxml_api::Result UnsetEnd( );

	//! Set IsPublic
	plmxml_api::Result SetIsPublic( plmxml_api::logical arg );

	//! Get IsPublic
	plmxml_api::logical GetIsPublic() const;

	//! Check if IsPublic is set
	plmxml_api::logical HasIsPublic() const;

	//! Unset IsPublic
	plmxml_api::Result UnsetIsPublic();

	//! Get Start of this ScheduleRevision
	plmxml_api::String GetStart() const;

	//! Set Start of this ScheduleRevision
	plmxml_api::Result SetStart( const plmxml_api::String &s );
	
	//! Check if Start is set
	plmxml_api::logical HasStart( ) const;
	
	//! Unset Start
	plmxml_api::Result UnsetStart( );

	//! Set SchedulingInfoRequiresRecalc
	plmxml_api::Result SetSchedulingInfoRequiresRecalc( plmxml_api::logical arg );

	//! Get SchedulingInfoRequiresRecalc
	plmxml_api::logical GetSchedulingInfoRequiresRecalc() const;

	//! Check if SchedulingInfoRequiresRecalc is set
	plmxml_api::logical HasSchedulingInfoRequiresRecalc() const;

	//! Unset SchedulingInfoRequiresRecalc
	plmxml_api::Result UnsetSchedulingInfoRequiresRecalc();

	//! Set Priority
	plmxml_api::Result SetPriority( const eSchedulePriorityEnum& arg );

	//! Get Priority
	eSchedulePriorityEnum GetPriority() const;

	//! Set Type
	plmxml_api::Result SetType( const eScheduleEnum& arg );

	//! Get Type
	eScheduleEnum GetType() const;

	//! Get MasterSchedule URI as plmxml_api::String
	plmxml_api::String GetMasterScheduleURI() const;

	//! Set MasterSchedule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMasterScheduleURI( const plmxml_api::String& );
	
	//! Get the handle of MasterSchedule URI. Does not resolve the URI.
	plmxml_api::Result GetMasterScheduleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of MasterSchedule URI. URI string is unchanged.
	plmxml_api::Result SetMasterScheduleURI( const plmxml_api::Handle& );
	
	//! Resolve MasterSchedule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMasterScheduleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset MasterSchedule URI. Clears URI string and handle.
	plmxml_api::Result DeleteMasterScheduleURI();
	
	//! Check if MasterSchedule URI is set
	plmxml_api::logical HasMasterScheduleURI( ) const;
	

	//! Get EarliestEnd of this ScheduleRevision
	plmxml_api::String GetEarliestEnd() const;

	//! Set EarliestEnd of this ScheduleRevision
	plmxml_api::Result SetEarliestEnd( const plmxml_api::String &s );
	
	//! Check if EarliestEnd is set
	plmxml_api::logical HasEarliestEnd( ) const;
	
	//! Unset EarliestEnd
	plmxml_api::Result UnsetEarliestEnd( );

	//! Set ExecutionInfoRequiresRecalc
	plmxml_api::Result SetExecutionInfoRequiresRecalc( plmxml_api::logical arg );

	//! Get ExecutionInfoRequiresRecalc
	plmxml_api::logical GetExecutionInfoRequiresRecalc() const;

	//! Check if ExecutionInfoRequiresRecalc is set
	plmxml_api::logical HasExecutionInfoRequiresRecalc() const;

	//! Unset ExecutionInfoRequiresRecalc
	plmxml_api::Result UnsetExecutionInfoRequiresRecalc();

	//! Add FixedCostInfo child element to this ScheduleRevision. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FixedCostInfo *AddFixedCostInfo();
     
	//! Add 'arg' as FixedCostInfo child element to this ScheduleRevision.
	plmxml_api::Result AddFixedCostInfo( FixedCostInfo *arg );

	//! Detach and delete all FixedCostInfo child elements.
	void DeleteFixedCostInfos();
     
	//! Get number of FixedCostInfo child elements.
	int NumberOfFixedCostInfos() const;
     
	//! Get i'th FixedCostInfo child element.
	FixedCostInfo *GetFixedCostInfo( int i ) const;
     
	//! Get all FixedCostInfo child element as an array
	void GetFixedCostInfos( plmxml_api::Array<FixedCostInfo*> &array ) const;
	     
	//! Detach and delete i'th FixedCostInfo child element
	void DeleteFixedCostInfo( int i );
     
	//! Detach and delete 'arg' if it's one of the FixedCostInfo child elements
	void DeleteFixedCostInfo( FixedCostInfo *arg );
 
// <PLMXML_UserCode type="functionHeaderScheduleRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleDeliverable class
/*!
\verbatim

      Represents a deliverable of a ScheduleRevision.

      Attributes:

      type:           The type of the deliverable.
      name:           Inherited from AttribOwnerBase.
      deliverableRef: A reference to the deliverable object.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleDeliverable : public AttribOwner
{
public:
     
    //! Default constructor
    ScheduleDeliverable( );
     
    //! Constructs a ScheduleDeliverable with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleDeliverable( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleDeliverable();

private:

	//! Assignment operator
	ScheduleDeliverable& operator=( const ScheduleDeliverable& iSrc );

	//! Copy constructor
	ScheduleDeliverable( const ScheduleDeliverable& original );
     
public:

	//! Get Type of this ScheduleDeliverable
	plmxml_api::String GetType() const;

	//! Set Type of this ScheduleDeliverable
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get Deliverable URI as plmxml_api::String
	plmxml_api::String GetDeliverableURI() const;

	//! Set Deliverable URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDeliverableURI( const plmxml_api::String& );
	
	//! Get the handle of Deliverable URI. Does not resolve the URI.
	plmxml_api::Result GetDeliverableURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Deliverable URI. URI string is unchanged.
	plmxml_api::Result SetDeliverableURI( const plmxml_api::Handle& );
	
	//! Resolve Deliverable URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDeliverableURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Deliverable URI. Clears URI string and handle.
	plmxml_api::Result DeleteDeliverableURI();
	
	//! Check if Deliverable URI is set
	plmxml_api::logical HasDeliverableURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderScheduleDeliverable" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleDeliverable;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleTask class
/*!
\verbatim

      Represents a task of a schedule.

      Attributes:

      name:           Inherited from StructureBase.
      originalRef:    References the original task when this task represents a
                      baseline task.

      Sub-elements:

      Description:    Inherited from StructureBase.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleTask : public Structure
{
public:
     
    //! Default constructor
    ScheduleTask( );
     
    //! Constructs a ScheduleTask with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleTask( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleTask();

private:

	//! Assignment operator
	ScheduleTask& operator=( const ScheduleTask& iSrc );

	//! Copy constructor
	ScheduleTask( const ScheduleTask& original );
     
public:

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
	
 
// <PLMXML_UserCode type="functionHeaderScheduleTask" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleTask;


////////////////////////////////////////////////////////////////////////////////////
//! TaskSchedulingInfo class
/*!
\verbatim

      Represents additional information about planning a ScheduleTaskRevision.

      Attributes:

      start:          The planned date and time of the start of the
                      ScheduleTaskRevision.
      end:            The planned date and time of the end of the
                      ScheduleTaskRevision.
      duration:       The duration of the task.
      work:           An estimate of the amount of person-time involved in the
                      ScheduleTaskRevision.
      deliverableRefs: A list of references to the ScheduleTaskDeliverable
                      elements for the ScheduleTaskRevision.
      workflowTemplateRef: A reference to the WorkflowTemplate associated with
                      the ScheduleTaskRevision.
      workflowTrigger: The trigger criteria for the workflow associated with
                      the ScheduleTaskRevision.
      wBSValue:       The value of the work breakdown structure identifier as
                      a string.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API TaskSchedulingInfo : public Attribute
{
public:
     
    //! Default constructor
    TaskSchedulingInfo( );
     
    //! Constructs a TaskSchedulingInfo with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TaskSchedulingInfo( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TaskSchedulingInfo();

private:

	//! Assignment operator
	TaskSchedulingInfo& operator=( const TaskSchedulingInfo& iSrc );

	//! Copy constructor
	TaskSchedulingInfo( const TaskSchedulingInfo& original );
     
public:

	//! Get number of URIs in Deliverable
	int NumberOfDeliverableURIs() const;

	//! Get i'th URI in Deliverable
	plmxml_api::String GetDeliverableURI( int i ) const;

	//! Add a URI to Deliverable array. Call ResolveDeliverableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDeliverableURI( const plmxml_api::String& u );

	//! Set i'th URI in Deliverable array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDeliverableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Deliverable URI. Does not resolve the URI.
	plmxml_api::Result GetDeliverableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Deliverable array.
	plmxml_api::Result AddDeliverableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Deliverable array to point to 'handle'.
	plmxml_api::Result SetDeliverableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Deliverable points to.
	plmxml_api::Result ResolveDeliverableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Deliverable array.
	plmxml_api::Result DeleteDeliverableURI( int i );

	//! Remove all URIs from Deliverable array.
	plmxml_api::Result DeleteDeliverableURIs( );
	
	//! Check if Deliverable is set
	plmxml_api::logical HasDeliverableURIs( ) const;

	//! Get Work of this TaskSchedulingInfo
	plmxml_api::String GetWork() const;

	//! Set Work of this TaskSchedulingInfo
	plmxml_api::Result SetWork( const plmxml_api::String &s );
	
	//! Check if Work is set
	plmxml_api::logical HasWork( ) const;
	
	//! Unset Work
	plmxml_api::Result UnsetWork( );

	//! Get Start of this TaskSchedulingInfo
	plmxml_api::String GetStart() const;

	//! Set Start of this TaskSchedulingInfo
	plmxml_api::Result SetStart( const plmxml_api::String &s );
	
	//! Check if Start is set
	plmxml_api::logical HasStart( ) const;
	
	//! Unset Start
	plmxml_api::Result UnsetStart( );

	//! Get End of this TaskSchedulingInfo
	plmxml_api::String GetEnd() const;

	//! Set End of this TaskSchedulingInfo
	plmxml_api::Result SetEnd( const plmxml_api::String &s );
	
	//! Check if End is set
	plmxml_api::logical HasEnd( ) const;
	
	//! Unset End
	plmxml_api::Result UnsetEnd( );

	//! Get Duration of this TaskSchedulingInfo
	plmxml_api::String GetDuration() const;

	//! Set Duration of this TaskSchedulingInfo
	plmxml_api::Result SetDuration( const plmxml_api::String &s );
	
	//! Check if Duration is set
	plmxml_api::logical HasDuration( ) const;
	
	//! Unset Duration
	plmxml_api::Result UnsetDuration( );

	//! Get WorkflowTemplate URI as plmxml_api::String
	plmxml_api::String GetWorkflowTemplateURI() const;

	//! Set WorkflowTemplate URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWorkflowTemplateURI( const plmxml_api::String& );
	
	//! Get the handle of WorkflowTemplate URI. Does not resolve the URI.
	plmxml_api::Result GetWorkflowTemplateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of WorkflowTemplate URI. URI string is unchanged.
	plmxml_api::Result SetWorkflowTemplateURI( const plmxml_api::Handle& );
	
	//! Resolve WorkflowTemplate URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWorkflowTemplateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset WorkflowTemplate URI. Clears URI string and handle.
	plmxml_api::Result DeleteWorkflowTemplateURI();
	
	//! Check if WorkflowTemplate URI is set
	plmxml_api::logical HasWorkflowTemplateURI( ) const;
	

	//! Set WorkflowTrigger
	plmxml_api::Result SetWorkflowTrigger( const eWorkflowTriggerEnum& arg );

	//! Get WorkflowTrigger
	eWorkflowTriggerEnum GetWorkflowTrigger() const;

	//! Get WBSValue of this TaskSchedulingInfo
	plmxml_api::String GetWBSValue() const;

	//! Set WBSValue of this TaskSchedulingInfo
	plmxml_api::Result SetWBSValue( const plmxml_api::String &s );
	
	//! Check if WBSValue is set
	plmxml_api::logical HasWBSValue( ) const;
	
	//! Unset WBSValue
	plmxml_api::Result UnsetWBSValue( );
 
// <PLMXML_UserCode type="functionHeaderTaskSchedulingInfo" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassTaskSchedulingInfo;


////////////////////////////////////////////////////////////////////////////////////
//! TaskExecutionInfo class
/*!
\verbatim

      Represents additional information about the actual execution of a
      ScheduleTaskRevision.

      Attributes:

      progress:       The progress of the ScheduleTaskRevision.
      start:          The actual date and time of the start of the
                      ScheduleTaskRevision.
      end:            The actual date and time of the end of the
                      ScheduleTaskRevision.
      fraction:       The fraction of work completed in the
                      ScheduleTaskRevision.
      completedWork:  The amount of person-time completed in the
                      ScheduleTaskRevision.
      workflowRef:    A reference to the workflow or task associated with the
                      ScheduleTaskRevision.
      approvedWork:   The amount of person-time approved for the
                      ScheduleTaskRevision.
      remainingWork:  The amount of person-time remaining in the task.
      finalStatus:    The customizable status of the task.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API TaskExecutionInfo : public Attribute
{
public:
     
    //! Default constructor
    TaskExecutionInfo( );
     
    //! Constructs a TaskExecutionInfo with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TaskExecutionInfo( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TaskExecutionInfo();

private:

	//! Assignment operator
	TaskExecutionInfo& operator=( const TaskExecutionInfo& iSrc );

	//! Copy constructor
	TaskExecutionInfo( const TaskExecutionInfo& original );
     
public:

	//! Get CompletedWork of this TaskExecutionInfo
	plmxml_api::String GetCompletedWork() const;

	//! Set CompletedWork of this TaskExecutionInfo
	plmxml_api::Result SetCompletedWork( const plmxml_api::String &s );
	
	//! Check if CompletedWork is set
	plmxml_api::logical HasCompletedWork( ) const;
	
	//! Unset CompletedWork
	plmxml_api::Result UnsetCompletedWork( );

	//! Get Workflow URI as plmxml_api::String
	plmxml_api::String GetWorkflowURI() const;

	//! Set Workflow URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWorkflowURI( const plmxml_api::String& );
	
	//! Get the handle of Workflow URI. Does not resolve the URI.
	plmxml_api::Result GetWorkflowURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Workflow URI. URI string is unchanged.
	plmxml_api::Result SetWorkflowURI( const plmxml_api::Handle& );
	
	//! Resolve Workflow URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWorkflowURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Workflow URI. Clears URI string and handle.
	plmxml_api::Result DeleteWorkflowURI();
	
	//! Check if Workflow URI is set
	plmxml_api::logical HasWorkflowURI( ) const;
	

	//! Get RemainingWork of this TaskExecutionInfo
	plmxml_api::String GetRemainingWork() const;

	//! Set RemainingWork of this TaskExecutionInfo
	plmxml_api::Result SetRemainingWork( const plmxml_api::String &s );
	
	//! Check if RemainingWork is set
	plmxml_api::logical HasRemainingWork( ) const;
	
	//! Unset RemainingWork
	plmxml_api::Result UnsetRemainingWork( );

	//! Set Fraction
	plmxml_api::Result SetFraction( double arg );

     //! Get Fraction
	double GetFraction() const;

	//! Check if Fraction is set
	plmxml_api::logical HasFraction() const;

	//! Unset Fraction
	plmxml_api::Result UnsetFraction();

	//! Get Start of this TaskExecutionInfo
	plmxml_api::String GetStart() const;

	//! Set Start of this TaskExecutionInfo
	plmxml_api::Result SetStart( const plmxml_api::String &s );
	
	//! Check if Start is set
	plmxml_api::logical HasStart( ) const;
	
	//! Unset Start
	plmxml_api::Result UnsetStart( );

	//! Get End of this TaskExecutionInfo
	plmxml_api::String GetEnd() const;

	//! Set End of this TaskExecutionInfo
	plmxml_api::Result SetEnd( const plmxml_api::String &s );
	
	//! Check if End is set
	plmxml_api::logical HasEnd( ) const;
	
	//! Unset End
	plmxml_api::Result UnsetEnd( );

	//! Get ApprovedWork of this TaskExecutionInfo
	plmxml_api::String GetApprovedWork() const;

	//! Set ApprovedWork of this TaskExecutionInfo
	plmxml_api::Result SetApprovedWork( const plmxml_api::String &s );
	
	//! Check if ApprovedWork is set
	plmxml_api::logical HasApprovedWork( ) const;
	
	//! Unset ApprovedWork
	plmxml_api::Result UnsetApprovedWork( );

	//! Get FinalStatus of this TaskExecutionInfo
	plmxml_api::String GetFinalStatus() const;

	//! Set FinalStatus of this TaskExecutionInfo
	plmxml_api::Result SetFinalStatus( const plmxml_api::String &s );
	
	//! Check if FinalStatus is set
	plmxml_api::logical HasFinalStatus( ) const;
	
	//! Unset FinalStatus
	plmxml_api::Result UnsetFinalStatus( );

	//! Set Progress
	plmxml_api::Result SetProgress( const eScheduleProgressEnum& arg );

	//! Get Progress
	eScheduleProgressEnum GetProgress() const;
 
// <PLMXML_UserCode type="functionHeaderTaskExecutionInfo" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassTaskExecutionInfo;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleTaskRevision class
/*!
\verbatim

      Represents a revision of a task of a schedule.

      Attributes:

      isBaseline:     Whether the ScheduleTaskRevision is a baseline.
      scheduleRef:    A reference to the ScheduleRevision that contains this
                      ScheduleTaskRevision.
      baselineCostRef: If the ScheduleTaskRevision is a baseline,
                      baselineCostRef references a Money element representing
                      the baseline cost of the ScheduleTaskRevision and its
                      sub-tasks. Deprecated.
      childRefs:      A list of references to the child ScheduleTaskRevision
                      elements of this ScheduleTaskRevision.
      type:           The type of the ScheduleTaskRevision.
      constraint:     The constraint on the ScheduleTaskRevision.
      fixed:          Whether the work, duration or resources of the
                      ScheduleTaskRevision are fixed.
      priority:       The priority of the ScheduleTaskRevision.
      autoComplete:   If the type attribute is milestone, autoComplete
                      represents whether the ScheduleTaskRevision becomes
                      complete when all predecessor ScheduleTaskRevision
                      elements become complete.
      workflowResourceAssignmentRef: A reference to the ResourceAssignment
                      that receives workflow notifications for the
                      ScheduleTaskRevision.
      workflowOwnerRef: References the workflow process owner.

      Sub-elements:

      FixedCostInfo:  Any number of FixedCostInfo sub-elements hold additional
                      information about the fixed costs associated with the
                      ScheduleTaskRevision.
      TaskSchedulingInfo: A ScheduleTaskRevision may have a TaskSchedulingInfo
                      sub-element to hold additional information about
                      planning the ScheduleTaskRevision.
      TaskExecutionInfo: A ScheduleTaskRevision may have a TaskExecutionInfo
                      sub-element to hold additional information about the
                      actual execution of the ScheduleTaskRevision.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleTaskRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ScheduleTaskRevision( );
     
    //! Constructs a ScheduleTaskRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleTaskRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleTaskRevision();

private:

	//! Assignment operator
	ScheduleTaskRevision& operator=( const ScheduleTaskRevision& iSrc );

	//! Copy constructor
	ScheduleTaskRevision( const ScheduleTaskRevision& original );
     
public:

	//! Set Priority
	plmxml_api::Result SetPriority( const eSchedulePriorityEnum& arg );

	//! Get Priority
	eSchedulePriorityEnum GetPriority() const;

	//! Set Fixed
	plmxml_api::Result SetFixed( const eScheduleTaskFixedEnum& arg );

	//! Get Fixed
	eScheduleTaskFixedEnum GetFixed() const;

	//! Set Constraint
	plmxml_api::Result SetConstraint( const eScheduleTaskConstraintEnum& arg );

	//! Get Constraint
	eScheduleTaskConstraintEnum GetConstraint() const;

	//! Get WorkflowResourceAssignment URI as plmxml_api::String
	plmxml_api::String GetWorkflowResourceAssignmentURI() const;

	//! Set WorkflowResourceAssignment URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWorkflowResourceAssignmentURI( const plmxml_api::String& );
	
	//! Get the handle of WorkflowResourceAssignment URI. Does not resolve the URI.
	plmxml_api::Result GetWorkflowResourceAssignmentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of WorkflowResourceAssignment URI. URI string is unchanged.
	plmxml_api::Result SetWorkflowResourceAssignmentURI( const plmxml_api::Handle& );
	
	//! Resolve WorkflowResourceAssignment URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWorkflowResourceAssignmentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset WorkflowResourceAssignment URI. Clears URI string and handle.
	plmxml_api::Result DeleteWorkflowResourceAssignmentURI();
	
	//! Check if WorkflowResourceAssignment URI is set
	plmxml_api::logical HasWorkflowResourceAssignmentURI( ) const;
	

	//! Get Schedule URI as plmxml_api::String
	plmxml_api::String GetScheduleURI() const;

	//! Set Schedule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetScheduleURI( const plmxml_api::String& );
	
	//! Get the handle of Schedule URI. Does not resolve the URI.
	plmxml_api::Result GetScheduleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Schedule URI. URI string is unchanged.
	plmxml_api::Result SetScheduleURI( const plmxml_api::Handle& );
	
	//! Resolve Schedule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveScheduleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Schedule URI. Clears URI string and handle.
	plmxml_api::Result DeleteScheduleURI();
	
	//! Check if Schedule URI is set
	plmxml_api::logical HasScheduleURI( ) const;
	

	//! Set AutoComplete
	plmxml_api::Result SetAutoComplete( plmxml_api::logical arg );

	//! Get AutoComplete
	plmxml_api::logical GetAutoComplete() const;

	//! Check if AutoComplete is set
	plmxml_api::logical HasAutoComplete() const;

	//! Unset AutoComplete
	plmxml_api::Result UnsetAutoComplete();

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

	//! Set Type
	plmxml_api::Result SetType( const eScheduleTaskEnum& arg );

	//! Get Type
	eScheduleTaskEnum GetType() const;

	//! Get WorkflowOwner URI as plmxml_api::String
	plmxml_api::String GetWorkflowOwnerURI() const;

	//! Set WorkflowOwner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetWorkflowOwnerURI( const plmxml_api::String& );
	
	//! Get the handle of WorkflowOwner URI. Does not resolve the URI.
	plmxml_api::Result GetWorkflowOwnerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of WorkflowOwner URI. URI string is unchanged.
	plmxml_api::Result SetWorkflowOwnerURI( const plmxml_api::Handle& );
	
	//! Resolve WorkflowOwner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveWorkflowOwnerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset WorkflowOwner URI. Clears URI string and handle.
	plmxml_api::Result DeleteWorkflowOwnerURI();
	
	//! Check if WorkflowOwner URI is set
	plmxml_api::logical HasWorkflowOwnerURI( ) const;
	

	//! Get BaselineCost URI as plmxml_api::String
	plmxml_api::String GetBaselineCostURI() const;

	//! Set BaselineCost URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetBaselineCostURI( const plmxml_api::String& );
	
	//! Get the handle of BaselineCost URI. Does not resolve the URI.
	plmxml_api::Result GetBaselineCostURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of BaselineCost URI. URI string is unchanged.
	plmxml_api::Result SetBaselineCostURI( const plmxml_api::Handle& );
	
	//! Resolve BaselineCost URI and return an object (handle) it points to.
	plmxml_api::Result ResolveBaselineCostURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset BaselineCost URI. Clears URI string and handle.
	plmxml_api::Result DeleteBaselineCostURI();
	
	//! Check if BaselineCost URI is set
	plmxml_api::logical HasBaselineCostURI( ) const;
	

	//! Set IsBaseline
	plmxml_api::Result SetIsBaseline( plmxml_api::logical arg );

	//! Get IsBaseline
	plmxml_api::logical GetIsBaseline() const;

	//! Check if IsBaseline is set
	plmxml_api::logical HasIsBaseline() const;

	//! Unset IsBaseline
	plmxml_api::Result UnsetIsBaseline();

	//! Add FixedCostInfo child element to this ScheduleTaskRevision. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FixedCostInfo *AddFixedCostInfo();
     
	//! Add 'arg' as FixedCostInfo child element to this ScheduleTaskRevision.
	plmxml_api::Result AddFixedCostInfo( FixedCostInfo *arg );

	//! Detach and delete all FixedCostInfo child elements.
	void DeleteFixedCostInfos();
     
	//! Get number of FixedCostInfo child elements.
	int NumberOfFixedCostInfos() const;
     
	//! Get i'th FixedCostInfo child element.
	FixedCostInfo *GetFixedCostInfo( int i ) const;
     
	//! Get all FixedCostInfo child element as an array
	void GetFixedCostInfos( plmxml_api::Array<FixedCostInfo*> &array ) const;
	     
	//! Detach and delete i'th FixedCostInfo child element
	void DeleteFixedCostInfo( int i );
     
	//! Detach and delete 'arg' if it's one of the FixedCostInfo child elements
	void DeleteFixedCostInfo( FixedCostInfo *arg );

	//! Add TaskSchedulingInfo child element to this ScheduleTaskRevision. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	TaskSchedulingInfo *AddTaskSchedulingInfo();
     
	//! Set TaskSchedulingInfo child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTaskSchedulingInfo( TaskSchedulingInfo *arg );
     
	//! Get TaskSchedulingInfo child element of this ScheduleTaskRevision.
	TaskSchedulingInfo *GetTaskSchedulingInfo() const;
     
	//! Detach and delete TaskSchedulingInfo child element tree from this ScheduleTaskRevision.
	void DeleteTaskSchedulingInfo();

	//! Add TaskExecutionInfo child element to this ScheduleTaskRevision. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	TaskExecutionInfo *AddTaskExecutionInfo();
     
	//! Set TaskExecutionInfo child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTaskExecutionInfo( TaskExecutionInfo *arg );
     
	//! Get TaskExecutionInfo child element of this ScheduleTaskRevision.
	TaskExecutionInfo *GetTaskExecutionInfo() const;
     
	//! Detach and delete TaskExecutionInfo child element tree from this ScheduleTaskRevision.
	void DeleteTaskExecutionInfo();
 
// <PLMXML_UserCode type="functionHeaderScheduleTaskRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleTaskRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleTaskDeliverable class
/*!
\verbatim

      Represents a deliverable of a ScheduleTaskRevision.

      Attributes:

      submit:         The type of the deliverable.
      deliverableRef: A reference to the parent ScheduleDeliverable.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleTaskDeliverable : public AttribOwner
{
public:
     
    //! Default constructor
    ScheduleTaskDeliverable( );
     
    //! Constructs a ScheduleTaskDeliverable with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleTaskDeliverable( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleTaskDeliverable();

private:

	//! Assignment operator
	ScheduleTaskDeliverable& operator=( const ScheduleTaskDeliverable& iSrc );

	//! Copy constructor
	ScheduleTaskDeliverable( const ScheduleTaskDeliverable& original );
     
public:

	//! Set Submit
	plmxml_api::Result SetSubmit( const eScheduleTaskDeliverableSubmitEnum& arg );

	//! Get Submit
	eScheduleTaskDeliverableSubmitEnum GetSubmit() const;

	//! Get Deliverable URI as plmxml_api::String
	plmxml_api::String GetDeliverableURI() const;

	//! Set Deliverable URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDeliverableURI( const plmxml_api::String& );
	
	//! Get the handle of Deliverable URI. Does not resolve the URI.
	plmxml_api::Result GetDeliverableURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Deliverable URI. URI string is unchanged.
	plmxml_api::Result SetDeliverableURI( const plmxml_api::Handle& );
	
	//! Resolve Deliverable URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDeliverableURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Deliverable URI. Clears URI string and handle.
	plmxml_api::Result DeleteDeliverableURI();
	
	//! Check if Deliverable URI is set
	plmxml_api::logical HasDeliverableURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderScheduleTaskDeliverable" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleTaskDeliverable;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleTaskDependency class
/*!
\verbatim

      Represents the dependency between two ScheduleTaskRevision elements.

      Attributes:

      dependency:     The dependency between the two ScheduleTaskRevision
                      elements.
      lag:            The amount of time between the start or end of one
                      ScheduleTaskRevision and the start or end of the other.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleTaskDependency : public GeneralRelation
{
public:
     
    //! Default constructor
    ScheduleTaskDependency( );
     
    //! Constructs a ScheduleTaskDependency with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleTaskDependency( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleTaskDependency();

private:

	//! Assignment operator
	ScheduleTaskDependency& operator=( const ScheduleTaskDependency& iSrc );

	//! Copy constructor
	ScheduleTaskDependency( const ScheduleTaskDependency& original );
     
public:

	//! Set Dependency
	plmxml_api::Result SetDependency( const eScheduleTaskDependencyEnum& arg );

	//! Get Dependency
	eScheduleTaskDependencyEnum GetDependency() const;

	//! Get Lag of this ScheduleTaskDependency
	plmxml_api::String GetLag() const;

	//! Set Lag of this ScheduleTaskDependency
	plmxml_api::Result SetLag( const plmxml_api::String &s );
	
	//! Check if Lag is set
	plmxml_api::logical HasLag( ) const;
	
	//! Unset Lag
	plmxml_api::Result UnsetLag( );
 
// <PLMXML_UserCode type="functionHeaderScheduleTaskDependency" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleTaskDependency;


////////////////////////////////////////////////////////////////////////////////////
//! ResourceAssignment class
/*!
\verbatim

      Represents the assignment of a User, Organisation or Discipline to a
      ScheduleTaskRevision.

      Attributes:

      workingTimeFraction: The fraction of the working time according to its
                      Calendar that the ScheduleMember commits to the
                      ScheduleTaskRevision.
      disciplineRef:  A reference to the Discipline that the
                      ScheduleTaskRevision is assigned to.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ResourceAssignment : public GeneralRelation
{
public:
     
    //! Default constructor
    ResourceAssignment( );
     
    //! Constructs a ResourceAssignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ResourceAssignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ResourceAssignment();

private:

	//! Assignment operator
	ResourceAssignment& operator=( const ResourceAssignment& iSrc );

	//! Copy constructor
	ResourceAssignment( const ResourceAssignment& original );
     
public:

	//! Set WorkingTimeFraction
	plmxml_api::Result SetWorkingTimeFraction( double arg );

     //! Get WorkingTimeFraction
	double GetWorkingTimeFraction() const;

	//! Check if WorkingTimeFraction is set
	plmxml_api::logical HasWorkingTimeFraction() const;

	//! Unset WorkingTimeFraction
	plmxml_api::Result UnsetWorkingTimeFraction();

	//! Get Discipline URI as plmxml_api::String
	plmxml_api::String GetDisciplineURI() const;

	//! Set Discipline URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisciplineURI( const plmxml_api::String& );
	
	//! Get the handle of Discipline URI. Does not resolve the URI.
	plmxml_api::Result GetDisciplineURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Discipline URI. URI string is unchanged.
	plmxml_api::Result SetDisciplineURI( const plmxml_api::Handle& );
	
	//! Resolve Discipline URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisciplineURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Discipline URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisciplineURI();
	
	//! Check if Discipline URI is set
	plmxml_api::logical HasDisciplineURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderResourceAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassResourceAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! ScheduleMember class
/*!
\verbatim

      Represents a User, Organisation or Discipline that is assigned to a
      ScheduleTaskRevision.

      Attributes:

      calendarRef:    A reference to the Calendar of the ScheduleMember.
      resourceRef:    A reference to the User, Organisation, Discipline, Role or
                      ResourcePool that constitutes the ScheduleMember.
      privilege:      The privilege of the ScheduleMember.
      moneyRef:       A reference to the Money element that represents the
                      rate of pay of the ScheduleMember per day.
      scheduleRef:    If the ScheduleMember is a member of a schedule by proxy,
                      scheduleRef references the master schedule.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ScheduleMember : public AttribOwner
{
public:
     
    //! Default constructor
    ScheduleMember( );
     
    //! Constructs a ScheduleMember with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ScheduleMember( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ScheduleMember();

private:

	//! Assignment operator
	ScheduleMember& operator=( const ScheduleMember& iSrc );

	//! Copy constructor
	ScheduleMember( const ScheduleMember& original );
     
public:

	//! Get Calendar URI as plmxml_api::String
	plmxml_api::String GetCalendarURI() const;

	//! Set Calendar URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCalendarURI( const plmxml_api::String& );
	
	//! Get the handle of Calendar URI. Does not resolve the URI.
	plmxml_api::Result GetCalendarURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Calendar URI. URI string is unchanged.
	plmxml_api::Result SetCalendarURI( const plmxml_api::Handle& );
	
	//! Resolve Calendar URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCalendarURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Calendar URI. Clears URI string and handle.
	plmxml_api::Result DeleteCalendarURI();
	
	//! Check if Calendar URI is set
	plmxml_api::logical HasCalendarURI( ) const;
	

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
	

	//! Get Schedule URI as plmxml_api::String
	plmxml_api::String GetScheduleURI() const;

	//! Set Schedule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetScheduleURI( const plmxml_api::String& );
	
	//! Get the handle of Schedule URI. Does not resolve the URI.
	plmxml_api::Result GetScheduleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Schedule URI. URI string is unchanged.
	plmxml_api::Result SetScheduleURI( const plmxml_api::Handle& );
	
	//! Resolve Schedule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveScheduleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Schedule URI. Clears URI string and handle.
	plmxml_api::Result DeleteScheduleURI();
	
	//! Check if Schedule URI is set
	plmxml_api::logical HasScheduleURI( ) const;
	

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
	

	//! Set Privilege
	plmxml_api::Result SetPrivilege( const eScheduleMemberPrivilegeEnum& arg );

	//! Get Privilege
	eScheduleMemberPrivilegeEnum GetPrivilege() const;
 
// <PLMXML_UserCode type="functionHeaderScheduleMember" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassScheduleMember;


////////////////////////////////////////////////////////////////////////////////////
//! TimeSheetRecord class
/*!
\verbatim

      Represents the actual work completed by a User.

      Attributes:

      date:           The date of the TimeSheetRecord.
      work:           The amount of person-time completed in this
                      TimeSheetRecord.
      billingRateRef: A reference to the BillingRate for the TimeSheetRecord.
      billingCode:    The billing code for the TimeSheetRecord.
      billingSubCode: The billing sub code for the TimeSheetRecord.
      billingType:    Deprecated in favour of customBillingType.
      taskRef:        A reference to the ScheduleTask for the TimeSheetRecord.
      userRef:        A reference to the User.
      timeCategory:   The category of time in this TimeSheetRecord.
      customBillingType: The billing type for the TimeSheetRecord.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API TimeSheetRecord : public AttribOwner
{
public:
     
    //! Default constructor
    TimeSheetRecord( );
     
    //! Constructs a TimeSheetRecord with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TimeSheetRecord( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TimeSheetRecord();

private:

	//! Assignment operator
	TimeSheetRecord& operator=( const TimeSheetRecord& iSrc );

	//! Copy constructor
	TimeSheetRecord( const TimeSheetRecord& original );
     
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
	

	//! Get BillingRate URI as plmxml_api::String
	plmxml_api::String GetBillingRateURI() const;

	//! Set BillingRate URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetBillingRateURI( const plmxml_api::String& );
	
	//! Get the handle of BillingRate URI. Does not resolve the URI.
	plmxml_api::Result GetBillingRateURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of BillingRate URI. URI string is unchanged.
	plmxml_api::Result SetBillingRateURI( const plmxml_api::Handle& );
	
	//! Resolve BillingRate URI and return an object (handle) it points to.
	plmxml_api::Result ResolveBillingRateURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset BillingRate URI. Clears URI string and handle.
	plmxml_api::Result DeleteBillingRateURI();
	
	//! Check if BillingRate URI is set
	plmxml_api::logical HasBillingRateURI( ) const;
	

	//! Set BillingType
	plmxml_api::Result SetBillingType( const eFixedCostBillingTypeEnum& arg );

	//! Get BillingType
	eFixedCostBillingTypeEnum GetBillingType() const;

	//! Get Work of this TimeSheetRecord
	plmxml_api::String GetWork() const;

	//! Set Work of this TimeSheetRecord
	plmxml_api::Result SetWork( const plmxml_api::String &s );
	
	//! Check if Work is set
	plmxml_api::logical HasWork( ) const;
	
	//! Unset Work
	plmxml_api::Result UnsetWork( );

	//! Get Task URI as plmxml_api::String
	plmxml_api::String GetTaskURI() const;

	//! Set Task URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTaskURI( const plmxml_api::String& );
	
	//! Get the handle of Task URI. Does not resolve the URI.
	plmxml_api::Result GetTaskURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Task URI. URI string is unchanged.
	plmxml_api::Result SetTaskURI( const plmxml_api::Handle& );
	
	//! Resolve Task URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTaskURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Task URI. Clears URI string and handle.
	plmxml_api::Result DeleteTaskURI();
	
	//! Check if Task URI is set
	plmxml_api::logical HasTaskURI( ) const;
	

	//! Get BillingSubCode of this TimeSheetRecord
	plmxml_api::String GetBillingSubCode() const;

	//! Set BillingSubCode of this TimeSheetRecord
	plmxml_api::Result SetBillingSubCode( const plmxml_api::String &s );
	
	//! Check if BillingSubCode is set
	plmxml_api::logical HasBillingSubCode( ) const;
	
	//! Unset BillingSubCode
	plmxml_api::Result UnsetBillingSubCode( );

	//! Get CustomBillingType of this TimeSheetRecord
	plmxml_api::String GetCustomBillingType() const;

	//! Set CustomBillingType of this TimeSheetRecord
	plmxml_api::Result SetCustomBillingType( const plmxml_api::String &s );
	
	//! Check if CustomBillingType is set
	plmxml_api::logical HasCustomBillingType( ) const;
	
	//! Unset CustomBillingType
	plmxml_api::Result UnsetCustomBillingType( );

	//! Get Date of this TimeSheetRecord
	plmxml_api::String GetDate() const;

	//! Set Date of this TimeSheetRecord
	plmxml_api::Result SetDate( const plmxml_api::String &s );
	
	//! Check if Date is set
	plmxml_api::logical HasDate( ) const;
	
	//! Unset Date
	plmxml_api::Result UnsetDate( );

	//! Get BillingCode of this TimeSheetRecord
	plmxml_api::String GetBillingCode() const;

	//! Set BillingCode of this TimeSheetRecord
	plmxml_api::Result SetBillingCode( const plmxml_api::String &s );
	
	//! Check if BillingCode is set
	plmxml_api::logical HasBillingCode( ) const;
	
	//! Unset BillingCode
	plmxml_api::Result UnsetBillingCode( );

	//! Set TimeCategory
	plmxml_api::Result SetTimeCategory( const eTimeCategoryEnum& arg );

	//! Get TimeCategory
	eTimeCategoryEnum GetTimeCategory() const;
 
// <PLMXML_UserCode type="functionHeaderTimeSheetRecord" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassTimeSheetRecord;


////////////////////////////////////////////////////////////////////////////////////
//! ProxyTask class
/*!
\verbatim

      Represents a proxy task in a schedule. The real task is in a different
      schedule.

      Attributes:

      constraint:     The constraint on the proxy task.
      end:            The date and time of the end of the proxy task.
      fraction:       The actual fraction of work completed in the proxy task.
      completedWorkFraction: The calculated fraction of work completed in the
                      proxy task.
      displayTaskRef: References the task under which the proxy task is
                      displayed.
      scheduleName:   The name of the schedule for the real task.
      start:          The date and time of the start of the proxy task.
      finalStatus:    The customizable status of the proxy task.
      scheduleTaskRef: References the real task.
      type:           The type of the proxy task.
      scheduleRef:    References the schedule for the proxy task.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API ProxyTask : public Managed
{
public:
     
    //! Default constructor
    ProxyTask( );
     
    //! Constructs a ProxyTask with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProxyTask( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProxyTask();

private:

	//! Assignment operator
	ProxyTask& operator=( const ProxyTask& iSrc );

	//! Copy constructor
	ProxyTask( const ProxyTask& original );
     
public:

	//! Get ScheduleName of this ProxyTask
	plmxml_api::String GetScheduleName() const;

	//! Set ScheduleName of this ProxyTask
	plmxml_api::Result SetScheduleName( const plmxml_api::String &s );
	
	//! Check if ScheduleName is set
	plmxml_api::logical HasScheduleName( ) const;
	
	//! Unset ScheduleName
	plmxml_api::Result UnsetScheduleName( );

	//! Get Schedule URI as plmxml_api::String
	plmxml_api::String GetScheduleURI() const;

	//! Set Schedule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetScheduleURI( const plmxml_api::String& );
	
	//! Get the handle of Schedule URI. Does not resolve the URI.
	plmxml_api::Result GetScheduleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Schedule URI. URI string is unchanged.
	plmxml_api::Result SetScheduleURI( const plmxml_api::Handle& );
	
	//! Resolve Schedule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveScheduleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Schedule URI. Clears URI string and handle.
	plmxml_api::Result DeleteScheduleURI();
	
	//! Check if Schedule URI is set
	plmxml_api::logical HasScheduleURI( ) const;
	

	//! Set Constraint
	plmxml_api::Result SetConstraint( const eScheduleTaskConstraintEnum& arg );

	//! Get Constraint
	eScheduleTaskConstraintEnum GetConstraint() const;

	//! Set Type
	plmxml_api::Result SetType( const eScheduleTaskEnum& arg );

	//! Get Type
	eScheduleTaskEnum GetType() const;

	//! Set Fraction
	plmxml_api::Result SetFraction( double arg );

     //! Get Fraction
	double GetFraction() const;

	//! Check if Fraction is set
	plmxml_api::logical HasFraction() const;

	//! Unset Fraction
	plmxml_api::Result UnsetFraction();

	//! Get Start of this ProxyTask
	plmxml_api::String GetStart() const;

	//! Set Start of this ProxyTask
	plmxml_api::Result SetStart( const plmxml_api::String &s );
	
	//! Check if Start is set
	plmxml_api::logical HasStart( ) const;
	
	//! Unset Start
	plmxml_api::Result UnsetStart( );

	//! Get End of this ProxyTask
	plmxml_api::String GetEnd() const;

	//! Set End of this ProxyTask
	plmxml_api::Result SetEnd( const plmxml_api::String &s );
	
	//! Check if End is set
	plmxml_api::logical HasEnd( ) const;
	
	//! Unset End
	plmxml_api::Result UnsetEnd( );

	//! Get ScheduleTask URI as plmxml_api::String
	plmxml_api::String GetScheduleTaskURI() const;

	//! Set ScheduleTask URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetScheduleTaskURI( const plmxml_api::String& );
	
	//! Get the handle of ScheduleTask URI. Does not resolve the URI.
	plmxml_api::Result GetScheduleTaskURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ScheduleTask URI. URI string is unchanged.
	plmxml_api::Result SetScheduleTaskURI( const plmxml_api::Handle& );
	
	//! Resolve ScheduleTask URI and return an object (handle) it points to.
	plmxml_api::Result ResolveScheduleTaskURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ScheduleTask URI. Clears URI string and handle.
	plmxml_api::Result DeleteScheduleTaskURI();
	
	//! Check if ScheduleTask URI is set
	plmxml_api::logical HasScheduleTaskURI( ) const;
	

	//! Get FinalStatus of this ProxyTask
	plmxml_api::String GetFinalStatus() const;

	//! Set FinalStatus of this ProxyTask
	plmxml_api::Result SetFinalStatus( const plmxml_api::String &s );
	
	//! Check if FinalStatus is set
	plmxml_api::logical HasFinalStatus( ) const;
	
	//! Unset FinalStatus
	plmxml_api::Result UnsetFinalStatus( );

	//! Get DisplayTask URI as plmxml_api::String
	plmxml_api::String GetDisplayTaskURI() const;

	//! Set DisplayTask URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDisplayTaskURI( const plmxml_api::String& );
	
	//! Get the handle of DisplayTask URI. Does not resolve the URI.
	plmxml_api::Result GetDisplayTaskURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of DisplayTask URI. URI string is unchanged.
	plmxml_api::Result SetDisplayTaskURI( const plmxml_api::Handle& );
	
	//! Resolve DisplayTask URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDisplayTaskURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset DisplayTask URI. Clears URI string and handle.
	plmxml_api::Result DeleteDisplayTaskURI();
	
	//! Check if DisplayTask URI is set
	plmxml_api::logical HasDisplayTaskURI( ) const;
	

	//! Set CompletedWorkFraction
	plmxml_api::Result SetCompletedWorkFraction( double arg );

     //! Get CompletedWorkFraction
	double GetCompletedWorkFraction() const;

	//! Check if CompletedWorkFraction is set
	plmxml_api::logical HasCompletedWorkFraction() const;

	//! Unset CompletedWorkFraction
	plmxml_api::Result UnsetCompletedWorkFraction();
 
// <PLMXML_UserCode type="functionHeaderProxyTask" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassProxyTask;


////////////////////////////////////////////////////////////////////////////////////
//! UnversionedSchedule class
/*!
\verbatim

      Represents an unversioned schedule.

      Attributes:

      catalogueId:      The identifier of the schedule, unique in some context,
                        such as an Organisation.
      customerName:     The name of the customer.
      customerNumber:   The number of the customer.
      customerNameRef:  References a multiple language version of customerName.
                        If multiple language support is required,
                        customerNameRef should be used in addition to
                        customerName.
      customerNumberRef: References a multiple language version of
                        customerNumber. If multiple language support is
                        required, customerNumberRef should be used in addition
                        to customerNumber.
      activeBaselineRef: References the active baseline schedule.
      baselineRefs:     References the related baseline schedules.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API UnversionedSchedule : public ScheduleRevision
{
public:
     
    //! Default constructor
    UnversionedSchedule( );
     
    //! Constructs a UnversionedSchedule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UnversionedSchedule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UnversionedSchedule();

private:

	//! Assignment operator
	UnversionedSchedule& operator=( const UnversionedSchedule& iSrc );

	//! Copy constructor
	UnversionedSchedule( const UnversionedSchedule& original );
     
public:

	//! Get CatalogueId of this UnversionedSchedule
	plmxml_api::String GetCatalogueId() const;

	//! Set CatalogueId of this UnversionedSchedule
	plmxml_api::Result SetCatalogueId( const plmxml_api::String &s );
	
	//! Check if CatalogueId is set
	plmxml_api::logical HasCatalogueId( ) const;
	
	//! Unset CatalogueId
	plmxml_api::Result UnsetCatalogueId( );

	//! Get CustomerName of this UnversionedSchedule
	plmxml_api::String GetCustomerName() const;

	//! Set CustomerName of this UnversionedSchedule
	plmxml_api::Result SetCustomerName( const plmxml_api::String &s );
	
	//! Check if CustomerName is set
	plmxml_api::logical HasCustomerName( ) const;
	
	//! Unset CustomerName
	plmxml_api::Result UnsetCustomerName( );

	//! Get CustomerName URI as plmxml_api::String
	plmxml_api::String GetCustomerNameURI() const;

	//! Set CustomerName URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCustomerNameURI( const plmxml_api::String& );
	
	//! Get the handle of CustomerName URI. Does not resolve the URI.
	plmxml_api::Result GetCustomerNameURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of CustomerName URI. URI string is unchanged.
	plmxml_api::Result SetCustomerNameURI( const plmxml_api::Handle& );
	
	//! Resolve CustomerName URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCustomerNameURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset CustomerName URI. Clears URI string and handle.
	plmxml_api::Result DeleteCustomerNameURI();
	
	//! Check if CustomerName URI is set
	plmxml_api::logical HasCustomerNameURI( ) const;
	

	//! Get ActiveBaseline URI as plmxml_api::String
	plmxml_api::String GetActiveBaselineURI() const;

	//! Set ActiveBaseline URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActiveBaselineURI( const plmxml_api::String& );
	
	//! Get the handle of ActiveBaseline URI. Does not resolve the URI.
	plmxml_api::Result GetActiveBaselineURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ActiveBaseline URI. URI string is unchanged.
	plmxml_api::Result SetActiveBaselineURI( const plmxml_api::Handle& );
	
	//! Resolve ActiveBaseline URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActiveBaselineURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ActiveBaseline URI. Clears URI string and handle.
	plmxml_api::Result DeleteActiveBaselineURI();
	
	//! Check if ActiveBaseline URI is set
	plmxml_api::logical HasActiveBaselineURI( ) const;
	

	//! Get CustomerNumber URI as plmxml_api::String
	plmxml_api::String GetCustomerNumberURI() const;

	//! Set CustomerNumber URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCustomerNumberURI( const plmxml_api::String& );
	
	//! Get the handle of CustomerNumber URI. Does not resolve the URI.
	plmxml_api::Result GetCustomerNumberURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of CustomerNumber URI. URI string is unchanged.
	plmxml_api::Result SetCustomerNumberURI( const plmxml_api::Handle& );
	
	//! Resolve CustomerNumber URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCustomerNumberURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset CustomerNumber URI. Clears URI string and handle.
	plmxml_api::Result DeleteCustomerNumberURI();
	
	//! Check if CustomerNumber URI is set
	plmxml_api::logical HasCustomerNumberURI( ) const;
	

	//! Get CustomerNumber of this UnversionedSchedule
	plmxml_api::String GetCustomerNumber() const;

	//! Set CustomerNumber of this UnversionedSchedule
	plmxml_api::Result SetCustomerNumber( const plmxml_api::String &s );
	
	//! Check if CustomerNumber is set
	plmxml_api::logical HasCustomerNumber( ) const;
	
	//! Unset CustomerNumber
	plmxml_api::Result UnsetCustomerNumber( );
 
// <PLMXML_UserCode type="functionHeaderUnversionedSchedule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassUnversionedSchedule;


////////////////////////////////////////////////////////////////////////////////////
//! UnversionedScheduleTask class
/*!
\verbatim

      Represents an unversioned task of a schedule.

      Attributes:

      catalogueId:      The identifier of the task, unique in some context, such
                        as an Organisation.
      originalRef:      References the original task when this task represents a
                        baseline task.
      
\endverbatim
*/
class PLMXML_SCHEDULING60_API UnversionedScheduleTask : public ScheduleTaskRevision
{
public:
     
    //! Default constructor
    UnversionedScheduleTask( );
     
    //! Constructs a UnversionedScheduleTask with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UnversionedScheduleTask( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UnversionedScheduleTask();

private:

	//! Assignment operator
	UnversionedScheduleTask& operator=( const UnversionedScheduleTask& iSrc );

	//! Copy constructor
	UnversionedScheduleTask( const UnversionedScheduleTask& original );
     
public:

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
	

	//! Get CatalogueId of this UnversionedScheduleTask
	plmxml_api::String GetCatalogueId() const;

	//! Set CatalogueId of this UnversionedScheduleTask
	plmxml_api::Result SetCatalogueId( const plmxml_api::String &s );
	
	//! Check if CatalogueId is set
	plmxml_api::logical HasCatalogueId( ) const;
	
	//! Unset CatalogueId
	plmxml_api::Result UnsetCatalogueId( );
 
// <PLMXML_UserCode type="functionHeaderUnversionedScheduleTask" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_SCHEDULING60_API plmxml_api::plmxmlClass plmxmlClassUnversionedScheduleTask;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
