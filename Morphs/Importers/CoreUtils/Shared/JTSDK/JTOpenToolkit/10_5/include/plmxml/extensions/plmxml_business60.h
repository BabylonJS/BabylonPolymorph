/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/07/2018 10:43:26
// 
// Schema:	PLMXMLBusinessSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_BUSINESS60_H__
#define __PLMXML_BUSINESS60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_BUSINESS60_EXPORTS
#define PLMXML_BUSINESS60_API __declspec(dllexport)
#else
#define PLMXML_BUSINESS60_API __declspec(dllimport)
#endif
#else
#define PLMXML_BUSINESS60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


#include <plmxml_classification60.h>
#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
/*! \namespace plmxml_bus60
    \brief PLM XML SDK Business schema specific API namespace.

    plmxml_bus60 namespace includes Business schema specific auto-generated classes.
*/
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml_bus60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eSavedQueryResultsEnum class
/*!
Allowed Values:
\verbatim
  eSavedQueryResultsEnumHierarchical
	"hierarchical"
  eSavedQueryResultsEnumFlat
	"flat"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eSavedQueryResultsEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSavedQueryResultsEnum( const char* Type );
     
	//! Constructor
	eSavedQueryResultsEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSavedQueryResultsEnum( );
     
	//! Destructor 
	virtual ~eSavedQueryResultsEnum( );
     
	//! Assign from 'Type'
	const eSavedQueryResultsEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSavedQueryResultsEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SavedQueryResultsEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eSavedQueryResultsEnum& e1, const eSavedQueryResultsEnum& e2 );
     
	//! Compare SavedQueryResultsEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eSavedQueryResultsEnum& e1, const eSavedQueryResultsEnum& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSavedQueryResultsEnum;
extern PLMXML_BUSINESS60_API eSavedQueryResultsEnum eSavedQueryResultsEnumUnset;
extern PLMXML_BUSINESS60_API eSavedQueryResultsEnum eSavedQueryResultsEnumHierarchical;
extern PLMXML_BUSINESS60_API eSavedQueryResultsEnum eSavedQueryResultsEnumFlat;

////////////////////////////////////////////////////////////////////////////////////
//! eAPILanguageType class
/*!
Allowed Values:
\verbatim
  eAPILanguageTypeC
	"C"
  eAPILanguageTypeUnknown
	"unknown"
  eAPILanguageTypeDotNET
	"dotNET"
  eAPILanguageTypeScript
	"script"
  eAPILanguageTypeJava
	"java"
  eAPILanguageTypeCPlusPlus
	"CPlusPlus"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eAPILanguageType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAPILanguageType( const char* Type );
     
	//! Constructor
	eAPILanguageType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAPILanguageType( );
     
	//! Destructor 
	virtual ~eAPILanguageType( );
     
	//! Assign from 'Type'
	const eAPILanguageType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAPILanguageType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare APILanguageType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eAPILanguageType& e1, const eAPILanguageType& e2 );
     
	//! Compare APILanguageType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eAPILanguageType& e1, const eAPILanguageType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAPILanguageType;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeUnset;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeC;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeUnknown;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeDotNET;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeScript;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeJava;
extern PLMXML_BUSINESS60_API eAPILanguageType eAPILanguageTypeCPlusPlus;

////////////////////////////////////////////////////////////////////////////////////
//! eChangeIdDefFormatType class
/*!
Allowed Values:
\verbatim
  eChangeIdDefFormatTypeRunning
	"running"
  eChangeIdDefFormatTypeStatic
	"static"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eChangeIdDefFormatType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eChangeIdDefFormatType( const char* Type );
     
	//! Constructor
	eChangeIdDefFormatType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eChangeIdDefFormatType( );
     
	//! Destructor 
	virtual ~eChangeIdDefFormatType( );
     
	//! Assign from 'Type'
	const eChangeIdDefFormatType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eChangeIdDefFormatType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ChangeIdDefFormatType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eChangeIdDefFormatType& e1, const eChangeIdDefFormatType& e2 );
     
	//! Compare ChangeIdDefFormatType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eChangeIdDefFormatType& e1, const eChangeIdDefFormatType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumChangeIdDefFormatType;
extern PLMXML_BUSINESS60_API eChangeIdDefFormatType eChangeIdDefFormatTypeUnset;
extern PLMXML_BUSINESS60_API eChangeIdDefFormatType eChangeIdDefFormatTypeRunning;
extern PLMXML_BUSINESS60_API eChangeIdDefFormatType eChangeIdDefFormatTypeStatic;

////////////////////////////////////////////////////////////////////////////////////
//! eLOVType class
/*!
Allowed Values:
\verbatim
  eLOVTypeListOfValuesInteger
	"listOfValuesInteger"
  eLOVTypeListOfValuesTag
	"listOfValuesTag"
  eLOVTypeListOfValuesStringExtentWSOClass
	"listOfValuesStringExtentWSOClass"
  eLOVTypeListOfValuesExtentSite
	"listOfValuesExtentSite"
  eLOVTypeListOfValuesString
	"listOfValuesString"
  eLOVTypeListOfValuesStringExtentStatus
	"listOfValuesStringExtentStatus"
  eLOVTypeListOfValuesStringExtentGrName
	"listOfValuesStringExtentGrName"
  eLOVTypeListOfValuesStringExtent
	"listOfValuesStringExtent"
  eLOVTypeListOfValuesChar
	"listOfValuesChar"
  eLOVTypeListOfValuesStringExtentPubrType
	"listOfValuesStringExtentPubrType"
  eLOVTypeListOfValuesDouble
	"listOfValuesDouble"
  eLOVTypeListOfValuesDate
	"listOfValuesDate"
  eLOVTypeListOfValuesStringExtentUsName
	"listOfValuesStringExtentUsName"
  eLOVTypeListOfValuesStringExtentUserId
	"listOfValuesStringExtentUserId"
  eLOVTypeListOfValuesTagExtent
	"listOfValuesTagExtent"
  eLOVTypeListOfValuesFilter
	"listOfValuesFilter"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eLOVType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eLOVType( const char* Type );
     
	//! Constructor
	eLOVType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eLOVType( );
     
	//! Destructor 
	virtual ~eLOVType( );
     
	//! Assign from 'Type'
	const eLOVType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eLOVType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare LOVType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eLOVType& e1, const eLOVType& e2 );
     
	//! Compare LOVType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eLOVType& e1, const eLOVType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumLOVType;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeUnset;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesInteger;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesTag;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtentWSOClass;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesExtentSite;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesString;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtentStatus;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtentGrName;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtent;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesChar;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtentPubrType;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesDouble;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesDate;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtentUsName;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesStringExtentUserId;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesTagExtent;
extern PLMXML_BUSINESS60_API eLOVType eLOVTypeListOfValuesFilter;

////////////////////////////////////////////////////////////////////////////////////
//! eLOVUsageType class
/*!
Allowed Values:
\verbatim
  eLOVUsageTypeRange
	"range"
  eLOVUsageTypeExhaustive
	"exhaustive"
  eLOVUsageTypeSuggestive
	"suggestive"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eLOVUsageType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eLOVUsageType( const char* Type );
     
	//! Constructor
	eLOVUsageType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eLOVUsageType( );
     
	//! Destructor 
	virtual ~eLOVUsageType( );
     
	//! Assign from 'Type'
	const eLOVUsageType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eLOVUsageType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare LOVUsageType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eLOVUsageType& e1, const eLOVUsageType& e2 );
     
	//! Compare LOVUsageType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eLOVUsageType& e1, const eLOVUsageType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumLOVUsageType;
extern PLMXML_BUSINESS60_API eLOVUsageType eLOVUsageTypeUnset;
extern PLMXML_BUSINESS60_API eLOVUsageType eLOVUsageTypeRange;
extern PLMXML_BUSINESS60_API eLOVUsageType eLOVUsageTypeExhaustive;
extern PLMXML_BUSINESS60_API eLOVUsageType eLOVUsageTypeSuggestive;

////////////////////////////////////////////////////////////////////////////////////
//! eStorageMediaType class
/*!
Allowed Values:
\verbatim
  eStorageMediaTypeContentStorage
	"contentStorage"
  eStorageMediaTypeDisk
	"disk"
  eStorageMediaTypeTape
	"tape"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eStorageMediaType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eStorageMediaType( const char* Type );
     
	//! Constructor
	eStorageMediaType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eStorageMediaType( );
     
	//! Destructor 
	virtual ~eStorageMediaType( );
     
	//! Assign from 'Type'
	const eStorageMediaType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eStorageMediaType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare StorageMediaType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eStorageMediaType& e1, const eStorageMediaType& e2 );
     
	//! Compare StorageMediaType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eStorageMediaType& e1, const eStorageMediaType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumStorageMediaType;
extern PLMXML_BUSINESS60_API eStorageMediaType eStorageMediaTypeUnset;
extern PLMXML_BUSINESS60_API eStorageMediaType eStorageMediaTypeContentStorage;
extern PLMXML_BUSINESS60_API eStorageMediaType eStorageMediaTypeDisk;
extern PLMXML_BUSINESS60_API eStorageMediaType eStorageMediaTypeTape;

////////////////////////////////////////////////////////////////////////////////////
//! eDeepCopyType class
/*!
Allowed Values:
\verbatim
  eDeepCopyTypeNoCopy
	"noCopy"
  eDeepCopyTypeCopyAsReference
	"copyAsReference"
  eDeepCopyTypeCopyAsObject
	"copyAsObject"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eDeepCopyType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDeepCopyType( const char* Type );
     
	//! Constructor
	eDeepCopyType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDeepCopyType( );
     
	//! Destructor 
	virtual ~eDeepCopyType( );
     
	//! Assign from 'Type'
	const eDeepCopyType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDeepCopyType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DeepCopyType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eDeepCopyType& e1, const eDeepCopyType& e2 );
     
	//! Compare DeepCopyType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eDeepCopyType& e1, const eDeepCopyType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDeepCopyType;
extern PLMXML_BUSINESS60_API eDeepCopyType eDeepCopyTypeUnset;
extern PLMXML_BUSINESS60_API eDeepCopyType eDeepCopyTypeNoCopy;
extern PLMXML_BUSINESS60_API eDeepCopyType eDeepCopyTypeCopyAsReference;
extern PLMXML_BUSINESS60_API eDeepCopyType eDeepCopyTypeCopyAsObject;

////////////////////////////////////////////////////////////////////////////////////
//! eLOVValueType class
/*!
Allowed Values:
\verbatim
  eLOVValueTypeInteger
	"integer"
  eLOVValueTypeReference
	"reference"
  eLOVValueTypeChar
	"char"
  eLOVValueTypeDate
	"date"
  eLOVValueTypeDouble
	"double"
  eLOVValueTypeString
	"string"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eLOVValueType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eLOVValueType( const char* Type );
     
	//! Constructor
	eLOVValueType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eLOVValueType( );
     
	//! Destructor 
	virtual ~eLOVValueType( );
     
	//! Assign from 'Type'
	const eLOVValueType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eLOVValueType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare LOVValueType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eLOVValueType& e1, const eLOVValueType& e2 );
     
	//! Compare LOVValueType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eLOVValueType& e1, const eLOVValueType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumLOVValueType;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeUnset;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeInteger;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeReference;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeChar;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeDate;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeDouble;
extern PLMXML_BUSINESS60_API eLOVValueType eLOVValueTypeString;

////////////////////////////////////////////////////////////////////////////////////
//! eLOVAttachmentEnum class
/*!
Allowed Values:
\verbatim
  eLOVAttachmentEnumSimple
	"simple"
  eLOVAttachmentEnumInterdependent
	"interdependent"
  eLOVAttachmentEnumCascading
	"cascading"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eLOVAttachmentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eLOVAttachmentEnum( const char* Type );
     
	//! Constructor
	eLOVAttachmentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eLOVAttachmentEnum( );
     
	//! Destructor 
	virtual ~eLOVAttachmentEnum( );
     
	//! Assign from 'Type'
	const eLOVAttachmentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eLOVAttachmentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare LOVAttachmentEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eLOVAttachmentEnum& e1, const eLOVAttachmentEnum& e2 );
     
	//! Compare LOVAttachmentEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eLOVAttachmentEnum& e1, const eLOVAttachmentEnum& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumLOVAttachmentEnum;
extern PLMXML_BUSINESS60_API eLOVAttachmentEnum eLOVAttachmentEnumUnset;
extern PLMXML_BUSINESS60_API eLOVAttachmentEnum eLOVAttachmentEnumSimple;
extern PLMXML_BUSINESS60_API eLOVAttachmentEnum eLOVAttachmentEnumInterdependent;
extern PLMXML_BUSINESS60_API eLOVAttachmentEnum eLOVAttachmentEnumCascading;

////////////////////////////////////////////////////////////////////////////////////
//! eDeepCopyRuleOperationType class
/*!
Allowed Values:
\verbatim
  eDeepCopyRuleOperationTypeRevise
	"revise"
  eDeepCopyRuleOperationTypeSaveAs
	"saveAs"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eDeepCopyRuleOperationType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDeepCopyRuleOperationType( const char* Type );
     
	//! Constructor
	eDeepCopyRuleOperationType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDeepCopyRuleOperationType( );
     
	//! Destructor 
	virtual ~eDeepCopyRuleOperationType( );
     
	//! Assign from 'Type'
	const eDeepCopyRuleOperationType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDeepCopyRuleOperationType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DeepCopyRuleOperationType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eDeepCopyRuleOperationType& e1, const eDeepCopyRuleOperationType& e2 );
     
	//! Compare DeepCopyRuleOperationType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eDeepCopyRuleOperationType& e1, const eDeepCopyRuleOperationType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDeepCopyRuleOperationType;
extern PLMXML_BUSINESS60_API eDeepCopyRuleOperationType eDeepCopyRuleOperationTypeUnset;
extern PLMXML_BUSINESS60_API eDeepCopyRuleOperationType eDeepCopyRuleOperationTypeRevise;
extern PLMXML_BUSINESS60_API eDeepCopyRuleOperationType eDeepCopyRuleOperationTypeSaveAs;

////////////////////////////////////////////////////////////////////////////////////
//! ePropertyRuleIsModifiableType class
/*!
Allowed Values:
\verbatim
  ePropertyRuleIsModifiableTypeReadOnly
	"readOnly"
  ePropertyRuleIsModifiableTypeWritable
	"writable"
  ePropertyRuleIsModifiableTypeDefault
	"default"
  ePropertyRuleIsModifiableTypeWriteOnlyIfNull
	"writeOnlyIfNull"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API ePropertyRuleIsModifiableType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePropertyRuleIsModifiableType( const char* Type );
     
	//! Constructor
	ePropertyRuleIsModifiableType( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePropertyRuleIsModifiableType( );
     
	//! Destructor 
	virtual ~ePropertyRuleIsModifiableType( );
     
	//! Assign from 'Type'
	const ePropertyRuleIsModifiableType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePropertyRuleIsModifiableType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PropertyRuleIsModifiableType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const ePropertyRuleIsModifiableType& e1, const ePropertyRuleIsModifiableType& e2 );
     
	//! Compare PropertyRuleIsModifiableType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const ePropertyRuleIsModifiableType& e1, const ePropertyRuleIsModifiableType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPropertyRuleIsModifiableType;
extern PLMXML_BUSINESS60_API ePropertyRuleIsModifiableType ePropertyRuleIsModifiableTypeUnset;
extern PLMXML_BUSINESS60_API ePropertyRuleIsModifiableType ePropertyRuleIsModifiableTypeReadOnly;
extern PLMXML_BUSINESS60_API ePropertyRuleIsModifiableType ePropertyRuleIsModifiableTypeWritable;
extern PLMXML_BUSINESS60_API ePropertyRuleIsModifiableType ePropertyRuleIsModifiableTypeDefault;
extern PLMXML_BUSINESS60_API ePropertyRuleIsModifiableType ePropertyRuleIsModifiableTypeWriteOnlyIfNull;

////////////////////////////////////////////////////////////////////////////////////
//! eRuleScopeType class
/*!
Allowed Values:
\verbatim
  eRuleScopeTypeTceng
	"tceng"
  eRuleScopeTypeApplication
	"application"
  eRuleScopeTypePlmxml
	"plmxml"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eRuleScopeType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRuleScopeType( const char* Type );
     
	//! Constructor
	eRuleScopeType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRuleScopeType( );
     
	//! Destructor 
	virtual ~eRuleScopeType( );
     
	//! Assign from 'Type'
	const eRuleScopeType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRuleScopeType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RuleScopeType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eRuleScopeType& e1, const eRuleScopeType& e2 );
     
	//! Compare RuleScopeType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eRuleScopeType& e1, const eRuleScopeType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRuleScopeType;
extern PLMXML_BUSINESS60_API eRuleScopeType eRuleScopeTypeUnset;
extern PLMXML_BUSINESS60_API eRuleScopeType eRuleScopeTypeTceng;
extern PLMXML_BUSINESS60_API eRuleScopeType eRuleScopeTypeApplication;
extern PLMXML_BUSINESS60_API eRuleScopeType eRuleScopeTypePlmxml;

////////////////////////////////////////////////////////////////////////////////////
//! eTransferModeDirectionType class
/*!
Allowed Values:
\verbatim
  eTransferModeDirectionTypeFromPLMXML
	"fromPLMXML"
  eTransferModeDirectionTypeTceng2plmxml
	"tceng2plmxml"
  eTransferModeDirectionTypeToPLMXML
	"toPLMXML"
  eTransferModeDirectionTypePlmxml2tceng
	"plmxml2tceng"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eTransferModeDirectionType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTransferModeDirectionType( const char* Type );
     
	//! Constructor
	eTransferModeDirectionType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTransferModeDirectionType( );
     
	//! Destructor 
	virtual ~eTransferModeDirectionType( );
     
	//! Assign from 'Type'
	const eTransferModeDirectionType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTransferModeDirectionType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TransferModeDirectionType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eTransferModeDirectionType& e1, const eTransferModeDirectionType& e2 );
     
	//! Compare TransferModeDirectionType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eTransferModeDirectionType& e1, const eTransferModeDirectionType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTransferModeDirectionType;
extern PLMXML_BUSINESS60_API eTransferModeDirectionType eTransferModeDirectionTypeUnset;
extern PLMXML_BUSINESS60_API eTransferModeDirectionType eTransferModeDirectionTypeFromPLMXML;
extern PLMXML_BUSINESS60_API eTransferModeDirectionType eTransferModeDirectionTypeTceng2plmxml;
extern PLMXML_BUSINESS60_API eTransferModeDirectionType eTransferModeDirectionTypeToPLMXML;
extern PLMXML_BUSINESS60_API eTransferModeDirectionType eTransferModeDirectionTypePlmxml2tceng;

////////////////////////////////////////////////////////////////////////////////////
//! ePropertyRuleWriteOnceType class
/*!
Allowed Values:
\verbatim
  ePropertyRuleWriteOnceTypeNo
	"no"
  ePropertyRuleWriteOnceTypeOnlyIfNull
	"onlyIfNull"
  ePropertyRuleWriteOnceTypeAlways
	"always"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API ePropertyRuleWriteOnceType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePropertyRuleWriteOnceType( const char* Type );
     
	//! Constructor
	ePropertyRuleWriteOnceType( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePropertyRuleWriteOnceType( );
     
	//! Destructor 
	virtual ~ePropertyRuleWriteOnceType( );
     
	//! Assign from 'Type'
	const ePropertyRuleWriteOnceType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePropertyRuleWriteOnceType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PropertyRuleWriteOnceType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const ePropertyRuleWriteOnceType& e1, const ePropertyRuleWriteOnceType& e2 );
     
	//! Compare PropertyRuleWriteOnceType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const ePropertyRuleWriteOnceType& e1, const ePropertyRuleWriteOnceType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPropertyRuleWriteOnceType;
extern PLMXML_BUSINESS60_API ePropertyRuleWriteOnceType ePropertyRuleWriteOnceTypeUnset;
extern PLMXML_BUSINESS60_API ePropertyRuleWriteOnceType ePropertyRuleWriteOnceTypeNo;
extern PLMXML_BUSINESS60_API ePropertyRuleWriteOnceType ePropertyRuleWriteOnceTypeOnlyIfNull;
extern PLMXML_BUSINESS60_API ePropertyRuleWriteOnceType ePropertyRuleWriteOnceTypeAlways;

////////////////////////////////////////////////////////////////////////////////////
//! eMethodAttachmentPointEnum class
/*!
Allowed Values:
\verbatim
  eMethodAttachmentPointEnumBaseAction
	"baseAction"
  eMethodAttachmentPointEnumPostAction
	"postAction"
  eMethodAttachmentPointEnumPreAction
	"preAction"
  eMethodAttachmentPointEnumPreCondition
	"preCondition"
  eMethodAttachmentPointEnumUnknown
	"unknown"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eMethodAttachmentPointEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eMethodAttachmentPointEnum( const char* Type );
     
	//! Constructor
	eMethodAttachmentPointEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eMethodAttachmentPointEnum( );
     
	//! Destructor 
	virtual ~eMethodAttachmentPointEnum( );
     
	//! Assign from 'Type'
	const eMethodAttachmentPointEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eMethodAttachmentPointEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare MethodAttachmentPointEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eMethodAttachmentPointEnum& e1, const eMethodAttachmentPointEnum& e2 );
     
	//! Compare MethodAttachmentPointEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eMethodAttachmentPointEnum& e1, const eMethodAttachmentPointEnum& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumMethodAttachmentPointEnum;
extern PLMXML_BUSINESS60_API eMethodAttachmentPointEnum eMethodAttachmentPointEnumUnset;
extern PLMXML_BUSINESS60_API eMethodAttachmentPointEnum eMethodAttachmentPointEnumBaseAction;
extern PLMXML_BUSINESS60_API eMethodAttachmentPointEnum eMethodAttachmentPointEnumPostAction;
extern PLMXML_BUSINESS60_API eMethodAttachmentPointEnum eMethodAttachmentPointEnumPreAction;
extern PLMXML_BUSINESS60_API eMethodAttachmentPointEnum eMethodAttachmentPointEnumPreCondition;
extern PLMXML_BUSINESS60_API eMethodAttachmentPointEnum eMethodAttachmentPointEnumUnknown;

////////////////////////////////////////////////////////////////////////////////////
//! eAuthorisationRuleDomainEnum class
/*!
Allowed Values:
\verbatim
  eAuthorisationRuleDomainEnumUtility
	"utility"
  eAuthorisationRuleDomainEnumApplication
	"application"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eAuthorisationRuleDomainEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAuthorisationRuleDomainEnum( const char* Type );
     
	//! Constructor
	eAuthorisationRuleDomainEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAuthorisationRuleDomainEnum( );
     
	//! Destructor 
	virtual ~eAuthorisationRuleDomainEnum( );
     
	//! Assign from 'Type'
	const eAuthorisationRuleDomainEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAuthorisationRuleDomainEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare AuthorisationRuleDomainEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eAuthorisationRuleDomainEnum& e1, const eAuthorisationRuleDomainEnum& e2 );
     
	//! Compare AuthorisationRuleDomainEnum
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eAuthorisationRuleDomainEnum& e1, const eAuthorisationRuleDomainEnum& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAuthorisationRuleDomainEnum;
extern PLMXML_BUSINESS60_API eAuthorisationRuleDomainEnum eAuthorisationRuleDomainEnumUnset;
extern PLMXML_BUSINESS60_API eAuthorisationRuleDomainEnum eAuthorisationRuleDomainEnumUtility;
extern PLMXML_BUSINESS60_API eAuthorisationRuleDomainEnum eAuthorisationRuleDomainEnumApplication;

////////////////////////////////////////////////////////////////////////////////////
//! eNameFieldCaseType class
/*!
Allowed Values:
\verbatim
  eNameFieldCaseTypeLower
	"lower"
  eNameFieldCaseTypeUpper
	"upper"
  eNameFieldCaseTypeMixed
	"mixed"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eNameFieldCaseType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eNameFieldCaseType( const char* Type );
     
	//! Constructor
	eNameFieldCaseType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eNameFieldCaseType( );
     
	//! Destructor 
	virtual ~eNameFieldCaseType( );
     
	//! Assign from 'Type'
	const eNameFieldCaseType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eNameFieldCaseType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare NameFieldCaseType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eNameFieldCaseType& e1, const eNameFieldCaseType& e2 );
     
	//! Compare NameFieldCaseType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eNameFieldCaseType& e1, const eNameFieldCaseType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumNameFieldCaseType;
extern PLMXML_BUSINESS60_API eNameFieldCaseType eNameFieldCaseTypeUnset;
extern PLMXML_BUSINESS60_API eNameFieldCaseType eNameFieldCaseTypeLower;
extern PLMXML_BUSINESS60_API eNameFieldCaseType eNameFieldCaseTypeUpper;
extern PLMXML_BUSINESS60_API eNameFieldCaseType eNameFieldCaseTypeMixed;

////////////////////////////////////////////////////////////////////////////////////
//! eAttributeDefAttrType class
/*!
Allowed Values:
\verbatim
  eAttributeDefAttrTypeNote
	"note"
  eAttributeDefAttrTypeLogical
	"logical"
  eAttributeDefAttrTypeCharacter
	"character"
  eAttributeDefAttrTypeUntypedReference
	"untypedReference"
  eAttributeDefAttrTypeTypedReference
	"typedReference"
  eAttributeDefAttrTypeShort
	"short"
  eAttributeDefAttrTypeFloat
	"float"
  eAttributeDefAttrTypeInteger
	"integer"
  eAttributeDefAttrTypeExternalReference
	"externalReference"
  eAttributeDefAttrTypeDate
	"date"
  eAttributeDefAttrTypeDouble
	"double"
  eAttributeDefAttrTypeString
	"string"
  
\endverbatim
*/
class PLMXML_BUSINESS60_API eAttributeDefAttrType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAttributeDefAttrType( const char* Type );
     
	//! Constructor
	eAttributeDefAttrType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAttributeDefAttrType( );
     
	//! Destructor 
	virtual ~eAttributeDefAttrType( );
     
	//! Assign from 'Type'
	const eAttributeDefAttrType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAttributeDefAttrType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare AttributeDefAttrType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator==( const eAttributeDefAttrType& e1, const eAttributeDefAttrType& e2 );
     
	//! Compare AttributeDefAttrType
	friend plmxml_api::logical PLMXML_BUSINESS60_API operator!=( const eAttributeDefAttrType& e1, const eAttributeDefAttrType& e2 );
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAttributeDefAttrType;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeUnset;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeNote;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeLogical;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeCharacter;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeUntypedReference;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeTypedReference;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeShort;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeFloat;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeInteger;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeExternalReference;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeDate;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeDouble;
extern PLMXML_BUSINESS60_API eAttributeDefAttrType eAttributeDefAttrTypeString;

////////////////////////////////////////////////////////////////////////////////////
//! BusinessRule class
/*!
\verbatim

      This element defines abstract type for Business Rules.

      Attributes:

      isExportable:           Is this rule exportable? 
      isReplaceable:          Used for import. If the object exists and and this flag is set to true,  
                              then only this element can be replaced.
      version:                String that represents the version of a BusinessRule. This will help 
                              in tracking changes to rules.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API BusinessRule : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    BusinessRule( );
     
    //! Constructs a BusinessRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BusinessRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BusinessRule();

private:

	//! Assignment operator
	BusinessRule& operator=( const BusinessRule& iSrc );

	//! Copy constructor
	BusinessRule( const BusinessRule& original );
     
public:

	//! Set IsReplaceable
	plmxml_api::Result SetIsReplaceable( plmxml_api::logical arg );

	//! Get IsReplaceable
	plmxml_api::logical GetIsReplaceable() const;

	//! Check if IsReplaceable is set
	plmxml_api::logical HasIsReplaceable() const;

	//! Unset IsReplaceable
	plmxml_api::Result UnsetIsReplaceable();

	//! Get Version of this BusinessRule
	plmxml_api::String GetVersion() const;

	//! Set Version of this BusinessRule
	plmxml_api::Result SetVersion( const plmxml_api::String &s );
	
	//! Check if Version is set
	plmxml_api::logical HasVersion( ) const;
	
	//! Unset Version
	plmxml_api::Result UnsetVersion( );

	//! Set IsExportable
	plmxml_api::Result SetIsExportable( plmxml_api::logical arg );

	//! Get IsExportable
	plmxml_api::logical GetIsExportable() const;

	//! Check if IsExportable is set
	plmxml_api::logical HasIsExportable() const;

	//! Unset IsExportable
	plmxml_api::Result UnsetIsExportable();
 
// <PLMXML_UserCode type="functionHeaderBusinessRule" >
    //! @deprecated Use plmxml_bus60::BusinessRule::SetIsReplaceable( plmxml_api::logical arg ) instead.
	plmxml_api::Result SetIsReplicable( plmxml_api::logical arg );

	//! @deprecated Use plmxml_bus60::BusinessRule::GetIsReplaceable( ) const instead.
	plmxml_api::logical GetIsReplicable() const;

	//! @deprecated Use plmxml_bus60::BusinessRule::HasIsReplaceable( ) const instead.
	plmxml_api::logical HasIsReplicable() const;

	//! @deprecated Use plmxml_bus60::BusinessRule::UnsetIsReplaceable( ) instead.
	plmxml_api::Result UnsetIsReplicable();
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassBusinessRule;


////////////////////////////////////////////////////////////////////////////////////
//! HideTypeRule class
/*!
\verbatim

      This element contains a Hide Type Business Rule. This rule is used for suppressing 
      display of types in the creation dialogs.

      Attributes:
      
      hiddenTypeClassName:    Name of the class in which this type exists
      hiddenTypeName:         Name of the type on which this rule is applicable
      accessorType:           Type of accessor, i.e. user, group, role in group. 
      accessor:               reference to an URI of above type of accessor. If not specified, 
                              this would be assumed as a site wide rule
      isSystemRule:           Is this a system defined rule. If not specified this is assumed 
                              as false.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API HideTypeRule : public BusinessRule
{
public:
     
    //! Default constructor
    HideTypeRule( );
     
    //! Constructs a HideTypeRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HideTypeRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HideTypeRule();

private:

	//! Assignment operator
	HideTypeRule& operator=( const HideTypeRule& iSrc );

	//! Copy constructor
	HideTypeRule( const HideTypeRule& original );
     
public:

	//! Get number of URIs in Accessor
	int NumberOfAccessorURIs() const;

	//! Get i'th URI in Accessor
	plmxml_api::String GetAccessorURI( int i ) const;

	//! Add a URI to Accessor array. Call ResolveAccessorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAccessorURI( const plmxml_api::String& u );

	//! Set i'th URI in Accessor array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAccessorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Accessor URI. Does not resolve the URI.
	plmxml_api::Result GetAccessorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Accessor array.
	plmxml_api::Result AddAccessorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Accessor array to point to 'handle'.
	plmxml_api::Result SetAccessorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Accessor points to.
	plmxml_api::Result ResolveAccessorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Accessor array.
	plmxml_api::Result DeleteAccessorURI( int i );

	//! Remove all URIs from Accessor array.
	plmxml_api::Result DeleteAccessorURIs( );
	
	//! Check if Accessor is set
	plmxml_api::logical HasAccessorURIs( ) const;

	//! Get HiddenTypeName of this HideTypeRule
	plmxml_api::String GetHiddenTypeName() const;

	//! Set HiddenTypeName of this HideTypeRule
	plmxml_api::Result SetHiddenTypeName( const plmxml_api::String &s );
	
	//! Check if HiddenTypeName is set
	plmxml_api::logical HasHiddenTypeName( ) const;
	
	//! Unset HiddenTypeName
	plmxml_api::Result UnsetHiddenTypeName( );

	//! Get AccessorType of this HideTypeRule
	plmxml_api::String GetAccessorType() const;

	//! Set AccessorType of this HideTypeRule
	plmxml_api::Result SetAccessorType( const plmxml_api::String &s );
	
	//! Check if AccessorType is set
	plmxml_api::logical HasAccessorType( ) const;
	
	//! Unset AccessorType
	plmxml_api::Result UnsetAccessorType( );

	//! Get HiddenTypeClassName of this HideTypeRule
	plmxml_api::String GetHiddenTypeClassName() const;

	//! Set HiddenTypeClassName of this HideTypeRule
	plmxml_api::Result SetHiddenTypeClassName( const plmxml_api::String &s );
	
	//! Check if HiddenTypeClassName is set
	plmxml_api::logical HasHiddenTypeClassName( ) const;
	
	//! Unset HiddenTypeClassName
	plmxml_api::Result UnsetHiddenTypeClassName( );

	//! Set IsSystemRule
	plmxml_api::Result SetIsSystemRule( plmxml_api::logical arg );

	//! Get IsSystemRule
	plmxml_api::logical GetIsSystemRule() const;

	//! Check if IsSystemRule is set
	plmxml_api::logical HasIsSystemRule() const;

	//! Unset IsSystemRule
	plmxml_api::Result UnsetIsSystemRule();
 
// <PLMXML_UserCode type="functionHeaderHideTypeRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassHideTypeRule;


////////////////////////////////////////////////////////////////////////////////////
//! RelationRule class
/*!
\verbatim

      This element contains a Business rule of GRM Rule Type. It defines the constraints 
      for a relation.

      Attributes:
      
      primaryObjectType:      Primary object type for the relation
      secondaryObjectType:    Secondary object type for the relation
      relationType:           Relation type
      primaryCardinality:     Cardinality on primary object
      secondaryCardinality:   Cardinality on secondary object
      bitwiseConstraints:     Bitwise constraints, to represent attachability, detachability.
      secured:                Is this a system rule? Default is false.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API RelationRule : public BusinessRule
{
public:
     
    //! Default constructor
    RelationRule( );
     
    //! Constructs a RelationRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RelationRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RelationRule();

private:

	//! Assignment operator
	RelationRule& operator=( const RelationRule& iSrc );

	//! Copy constructor
	RelationRule( const RelationRule& original );
     
public:

	//! Set SecondaryCardinality
	plmxml_api::Result SetSecondaryCardinality( int arg );
     
	//! Get SecondaryCardinality
	int GetSecondaryCardinality() const;
     
	//! Check if SecondaryCardinality is set
	plmxml_api::logical HasSecondaryCardinality() const;
     
	//! Unset SecondaryCardinality
	plmxml_api::Result UnsetSecondaryCardinality();

	//! Get SecondaryObjectType of this RelationRule
	plmxml_api::String GetSecondaryObjectType() const;

	//! Set SecondaryObjectType of this RelationRule
	plmxml_api::Result SetSecondaryObjectType( const plmxml_api::String &s );
	
	//! Check if SecondaryObjectType is set
	plmxml_api::logical HasSecondaryObjectType( ) const;
	
	//! Unset SecondaryObjectType
	plmxml_api::Result UnsetSecondaryObjectType( );

	//! Get RelationType of this RelationRule
	plmxml_api::String GetRelationType() const;

	//! Set RelationType of this RelationRule
	plmxml_api::Result SetRelationType( const plmxml_api::String &s );
	
	//! Check if RelationType is set
	plmxml_api::logical HasRelationType( ) const;
	
	//! Unset RelationType
	plmxml_api::Result UnsetRelationType( );

	//! Set Secured
	plmxml_api::Result SetSecured( plmxml_api::logical arg );

	//! Get Secured
	plmxml_api::logical GetSecured() const;

	//! Check if Secured is set
	plmxml_api::logical HasSecured() const;

	//! Unset Secured
	plmxml_api::Result UnsetSecured();

	//! Set BitwiseConstraints
	plmxml_api::Result SetBitwiseConstraints( int arg );
     
	//! Get BitwiseConstraints
	int GetBitwiseConstraints() const;
     
	//! Check if BitwiseConstraints is set
	plmxml_api::logical HasBitwiseConstraints() const;
     
	//! Unset BitwiseConstraints
	plmxml_api::Result UnsetBitwiseConstraints();

	//! Get PrimaryObjectType of this RelationRule
	plmxml_api::String GetPrimaryObjectType() const;

	//! Set PrimaryObjectType of this RelationRule
	plmxml_api::Result SetPrimaryObjectType( const plmxml_api::String &s );
	
	//! Check if PrimaryObjectType is set
	plmxml_api::logical HasPrimaryObjectType( ) const;
	
	//! Unset PrimaryObjectType
	plmxml_api::Result UnsetPrimaryObjectType( );

	//! Set PrimaryCardinality
	plmxml_api::Result SetPrimaryCardinality( int arg );
     
	//! Get PrimaryCardinality
	int GetPrimaryCardinality() const;
     
	//! Check if PrimaryCardinality is set
	plmxml_api::logical HasPrimaryCardinality() const;
     
	//! Unset PrimaryCardinality
	plmxml_api::Result UnsetPrimaryCardinality();
 
// <PLMXML_UserCode type="functionHeaderRelationRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassRelationRule;


////////////////////////////////////////////////////////////////////////////////////
//! CompoundPropDef class
/*!
\verbatim

      This element contains a Business rule of Type Compound Property.

      Attributes:
      
      compoundPropName:       Name of compound property
      displayTypeName:        Display Object Type on which this compound property is defined
      sourceTypeName:         Source object Type
      sourcePropName:         Property name on the source object
      objectHierarchy:        String that represents how this property can queried on the displayed
      isReadOnly:             Is  this compound property be read only. Default is false.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API CompoundPropDef : public BusinessRule
{
public:
     
    //! Default constructor
    CompoundPropDef( );
     
    //! Constructs a CompoundPropDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CompoundPropDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CompoundPropDef();

private:

	//! Assignment operator
	CompoundPropDef& operator=( const CompoundPropDef& iSrc );

	//! Copy constructor
	CompoundPropDef( const CompoundPropDef& original );
     
public:

	//! Get SourcePropName of this CompoundPropDef
	plmxml_api::String GetSourcePropName() const;

	//! Set SourcePropName of this CompoundPropDef
	plmxml_api::Result SetSourcePropName( const plmxml_api::String &s );
	
	//! Check if SourcePropName is set
	plmxml_api::logical HasSourcePropName( ) const;
	
	//! Unset SourcePropName
	plmxml_api::Result UnsetSourcePropName( );

	//! Get DisplayTypeName of this CompoundPropDef
	plmxml_api::String GetDisplayTypeName() const;

	//! Set DisplayTypeName of this CompoundPropDef
	plmxml_api::Result SetDisplayTypeName( const plmxml_api::String &s );
	
	//! Check if DisplayTypeName is set
	plmxml_api::logical HasDisplayTypeName( ) const;
	
	//! Unset DisplayTypeName
	plmxml_api::Result UnsetDisplayTypeName( );

	//! Get ObjectHierarchy of this CompoundPropDef
	plmxml_api::String GetObjectHierarchy() const;

	//! Set ObjectHierarchy of this CompoundPropDef
	plmxml_api::Result SetObjectHierarchy( const plmxml_api::String &s );
	
	//! Check if ObjectHierarchy is set
	plmxml_api::logical HasObjectHierarchy( ) const;
	
	//! Unset ObjectHierarchy
	plmxml_api::Result UnsetObjectHierarchy( );

	//! Get SourceTypeName of this CompoundPropDef
	plmxml_api::String GetSourceTypeName() const;

	//! Set SourceTypeName of this CompoundPropDef
	plmxml_api::Result SetSourceTypeName( const plmxml_api::String &s );
	
	//! Check if SourceTypeName is set
	plmxml_api::logical HasSourceTypeName( ) const;
	
	//! Unset SourceTypeName
	plmxml_api::Result UnsetSourceTypeName( );

	//! Get CompoundPropName of this CompoundPropDef
	plmxml_api::String GetCompoundPropName() const;

	//! Set CompoundPropName of this CompoundPropDef
	plmxml_api::Result SetCompoundPropName( const plmxml_api::String &s );
	
	//! Check if CompoundPropName is set
	plmxml_api::logical HasCompoundPropName( ) const;
	
	//! Unset CompoundPropName
	plmxml_api::Result UnsetCompoundPropName( );

	//! Set IsReadOnly
	plmxml_api::Result SetIsReadOnly( plmxml_api::logical arg );

	//! Get IsReadOnly
	plmxml_api::logical GetIsReadOnly() const;

	//! Check if IsReadOnly is set
	plmxml_api::logical HasIsReadOnly() const;

	//! Unset IsReadOnly
	plmxml_api::Result UnsetIsReadOnly();
 
// <PLMXML_UserCode type="functionHeaderCompoundPropDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassCompoundPropDef;


//! Forward class declarations
class Autogen;
class ValueDetails;

////////////////////////////////////////////////////////////////////////////////////
//! NameRule class
/*!
\verbatim

      This element contains a Business rule of Type Naming Rule. This would contain 
      patterns that are valid for a Naming Rule.
      
      SubElements:
      
      Autogen:            Specifies if counters need to be generated for the Naming Rule 
                          using the first pattern
      StringPattern:      A Naming Rule Pattern or regular expression
      
\endverbatim
*/
class PLMXML_BUSINESS60_API NameRule : public BusinessRule
{
public:
     
    //! Default constructor
    NameRule( );
     
    //! Constructs a NameRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NameRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NameRule();

private:

	//! Assignment operator
	NameRule& operator=( const NameRule& iSrc );

	//! Copy constructor
	NameRule( const NameRule& original );
     
public:

	//! Add Autogen child element to this NameRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Autogen *AddAutogen();
     
	//! Set Autogen child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetAutogen( Autogen *arg );
     
	//! Get Autogen child element of this NameRule.
	Autogen *GetAutogen() const;
     
	//! Detach and delete Autogen child element tree from this NameRule.
	void DeleteAutogen();

	//! Add StringPattern child element to this NameRule. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueDetails *AddStringPattern();
     
	//! Add 'arg' as StringPattern child element to this NameRule.
	plmxml_api::Result AddStringPattern( ValueDetails *arg );

	//! Detach and delete all StringPattern child elements.
	void DeleteStringPatterns();
     
	//! Get number of StringPattern child elements.
	int NumberOfStringPatterns() const;
     
	//! Get i'th StringPattern child element.
	ValueDetails *GetStringPattern( int i ) const;
     
	//! Get all StringPattern child element as an array
	void GetStringPatterns( plmxml_api::Array<ValueDetails*> &array ) const;
	     
	//! Detach and delete i'th StringPattern child element
	void DeleteStringPattern( int i );
     
	//! Detach and delete 'arg' if it's one of the StringPattern child elements
	void DeleteStringPattern( ValueDetails *arg );
 
// <PLMXML_UserCode type="functionHeaderNameRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassNameRule;


////////////////////////////////////////////////////////////////////////////////////
//! NameField class
/*!
\verbatim

      This element contains a Business rule of Type Name Field. Determines which property 
      will have a Name Rule associated with it.

      Attributes:
      
      typeName:             Name of Object Type to which a Naming Rule is attached
      propertyName:         Property on the Object to which a Naming Rule is attached
      ruleNameRef:          Name of the Naming Rule as defined by NameRuleType
      case:                 Case to which the value will get converted
      
\endverbatim
*/
class PLMXML_BUSINESS60_API NameField : public BusinessRule
{
public:
     
    //! Default constructor
    NameField( );
     
    //! Constructs a NameField with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NameField( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NameField();

private:

	//! Assignment operator
	NameField& operator=( const NameField& iSrc );

	//! Copy constructor
	NameField( const NameField& original );
     
public:

	//! Get TypeName of this NameField
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this NameField
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get RuleName URI as plmxml_api::String
	plmxml_api::String GetRuleNameURI() const;

	//! Set RuleName URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRuleNameURI( const plmxml_api::String& );
	
	//! Get the handle of RuleName URI. Does not resolve the URI.
	plmxml_api::Result GetRuleNameURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of RuleName URI. URI string is unchanged.
	plmxml_api::Result SetRuleNameURI( const plmxml_api::Handle& );
	
	//! Resolve RuleName URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRuleNameURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset RuleName URI. Clears URI string and handle.
	plmxml_api::Result DeleteRuleNameURI();
	
	//! Check if RuleName URI is set
	plmxml_api::logical HasRuleNameURI( ) const;
	

	//! Get PropertyName of this NameField
	plmxml_api::String GetPropertyName() const;

	//! Set PropertyName of this NameField
	plmxml_api::Result SetPropertyName( const plmxml_api::String &s );
	
	//! Check if PropertyName is set
	plmxml_api::logical HasPropertyName( ) const;
	
	//! Unset PropertyName
	plmxml_api::Result UnsetPropertyName( );

	//! Set Case
	plmxml_api::Result SetCase( const eNameFieldCaseType& arg );

	//! Get Case
	eNameFieldCaseType GetCase() const;
 
// <PLMXML_UserCode type="functionHeaderNameField" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassNameField;


////////////////////////////////////////////////////////////////////////////////////
//! Autogen class
/*!
\verbatim

      This element holds the details of Autogen of ids for Naming Rule.

      Attributes:
      
      init:              Initial Value
      max:               Maximum Value
      
\endverbatim
*/
class PLMXML_BUSINESS60_API Autogen : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    Autogen( );
     
    //! Constructs a Autogen with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Autogen( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Autogen();

private:

	//! Assignment operator
	Autogen& operator=( const Autogen& iSrc );

	//! Copy constructor
	Autogen( const Autogen& original );
     
public:

	//! Get Max of this Autogen
	plmxml_api::String GetMax() const;

	//! Set Max of this Autogen
	plmxml_api::Result SetMax( const plmxml_api::String &s );
	
	//! Check if Max is set
	plmxml_api::logical HasMax( ) const;
	
	//! Unset Max
	plmxml_api::Result UnsetMax( );

	//! Get Init of this Autogen
	plmxml_api::String GetInit() const;

	//! Set Init of this Autogen
	plmxml_api::Result SetInit( const plmxml_api::String &s );
	
	//! Check if Init is set
	plmxml_api::logical HasInit( ) const;
	
	//! Unset Init
	plmxml_api::Result UnsetInit( );
 
// <PLMXML_UserCode type="functionHeaderAutogen" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassAutogen;


//! Forward class declarations
class MethodOpts;

////////////////////////////////////////////////////////////////////////////////////
//! TypeCannedMethod class
/*!
\verbatim

      This element contains a Business rule of Type Action Rules. These are methods to be 
      executed on Types on some events.

      SubElements:
      
      MethodOpts:          References a construct of parameters, that are required for this method. 
                           Multiple sets of parameters are allowed.
      
      Attributes:
      
      typeName:            Object Type on which this rule is applied
      msgName:             Name of the message, which is the event at which this rule gets applied
      actionType:          Holds the action as Precondition, PreAction or Post Action
      methodName:          Name of the Method which gets executed at this event
      execSeq:             Specifies the Order sequence in which this method gets executed
      
\endverbatim
*/
class PLMXML_BUSINESS60_API TypeCannedMethod : public BusinessRule
{
public:
     
    //! Default constructor
    TypeCannedMethod( );
     
    //! Constructs a TypeCannedMethod with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TypeCannedMethod( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TypeCannedMethod();

private:

	//! Assignment operator
	TypeCannedMethod& operator=( const TypeCannedMethod& iSrc );

	//! Copy constructor
	TypeCannedMethod( const TypeCannedMethod& original );
     
public:

	//! Get TypeName of this TypeCannedMethod
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this TypeCannedMethod
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get MsgName of this TypeCannedMethod
	plmxml_api::String GetMsgName() const;

	//! Set MsgName of this TypeCannedMethod
	plmxml_api::Result SetMsgName( const plmxml_api::String &s );
	
	//! Check if MsgName is set
	plmxml_api::logical HasMsgName( ) const;
	
	//! Unset MsgName
	plmxml_api::Result UnsetMsgName( );

	//! Get ActionType of this TypeCannedMethod
	plmxml_api::String GetActionType() const;

	//! Set ActionType of this TypeCannedMethod
	plmxml_api::Result SetActionType( const plmxml_api::String &s );
	
	//! Check if ActionType is set
	plmxml_api::logical HasActionType( ) const;
	
	//! Unset ActionType
	plmxml_api::Result UnsetActionType( );

	//! Get ExecSeq of this TypeCannedMethod
	plmxml_api::String GetExecSeq() const;

	//! Set ExecSeq of this TypeCannedMethod
	plmxml_api::Result SetExecSeq( const plmxml_api::String &s );
	
	//! Check if ExecSeq is set
	plmxml_api::logical HasExecSeq( ) const;
	
	//! Unset ExecSeq
	plmxml_api::Result UnsetExecSeq( );

	//! Get MethodName of this TypeCannedMethod
	plmxml_api::String GetMethodName() const;

	//! Set MethodName of this TypeCannedMethod
	plmxml_api::Result SetMethodName( const plmxml_api::String &s );
	
	//! Check if MethodName is set
	plmxml_api::logical HasMethodName( ) const;
	
	//! Unset MethodName
	plmxml_api::Result UnsetMethodName( );

	//! Add MethodOpts child element to this TypeCannedMethod. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MethodOpts *AddMethodOpts();
     
	//! Add 'arg' as MethodOpts child element to this TypeCannedMethod.
	plmxml_api::Result AddMethodOpts( MethodOpts *arg );

	//! Detach and delete all MethodOpts child elements.
	void DeleteMethodOpts();
     
	//! Get number of MethodOpts child elements.
	int NumberOfMethodOpts() const;
     
	//! Get i'th MethodOpts child element.
	MethodOpts *GetMethodOpts( int i ) const;
     
	//! Get all MethodOpts child element as an array
	void GetMethodOpts( plmxml_api::Array<MethodOpts*> &array ) const;
	     
	//! Detach and delete i'th MethodOpts child element
	void DeleteMethodOpts( int i );
     
	//! Detach and delete 'arg' if it's one of the MethodOpts child elements
	void DeleteMethodOpts( MethodOpts *arg );
 
// <PLMXML_UserCode type="functionHeaderTypeCannedMethod" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassTypeCannedMethod;


//! Forward class declarations
class Parameter;

////////////////////////////////////////////////////////////////////////////////////
//! MethodOpts class
/*!
\verbatim

      Holds a construct of parameters that are passed to Action Rule.

      SubElements:
      
      Parameters:             A set of parameters that are defined for an Action Rule.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodOpts : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    MethodOpts( );
     
    //! Constructs a MethodOpts with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodOpts( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodOpts();

private:

	//! Assignment operator
	MethodOpts& operator=( const MethodOpts& iSrc );

	//! Copy constructor
	MethodOpts( const MethodOpts& original );
     
public:

	//! Add Parameter child element to this MethodOpts. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Parameter *AddParameter();
     
	//! Add 'arg' as Parameter child element to this MethodOpts.
	plmxml_api::Result AddParameter( Parameter *arg );

	//! Detach and delete all Parameter child elements.
	void DeleteParameters();
     
	//! Get number of Parameter child elements.
	int NumberOfParameters() const;
     
	//! Get i'th Parameter child element.
	Parameter *GetParameter( int i ) const;
     
	//! Get all Parameter child element as an array
	void GetParameters( plmxml_api::Array<Parameter*> &array ) const;
	     
	//! Detach and delete i'th Parameter child element
	void DeleteParameter( int i );
     
	//! Detach and delete 'arg' if it's one of the Parameter child elements
	void DeleteParameter( Parameter *arg );
 
// <PLMXML_UserCode type="functionHeaderMethodOpts" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodOpts;


////////////////////////////////////////////////////////////////////////////////////
//! Parameter class
/*!
\verbatim

      Holds a set of parameter strings.

      SubElements:
      Parameter:          A string that is passed as a parameter
      
\endverbatim
*/
class PLMXML_BUSINESS60_API Parameter : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    Parameter( );
     
    //! Constructs a Parameter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Parameter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Parameter();

private:

	//! Assignment operator
	Parameter& operator=( const Parameter& iSrc );

	//! Copy constructor
	Parameter( const Parameter& original );
     
public:

	//! Get Value of this Parameter
	plmxml_api::String GetValue() const;

	//! Set Value of this Parameter
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderParameter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassParameter;


////////////////////////////////////////////////////////////////////////////////////
//! PropertyRule class
/*!
\verbatim

      This element contains a Business rule of Type Property Rule. 

      Attributes:
      
      typeName:                Object Type on which this rule applies
      propertyName:            Property on the object on which this rule applies
      initialValue:            Initial Value for the property
      isModifiable:            Is this property modifiable?
      writeOnce:               Is this property value written once only?
      isRequired:                             
      isEnabled:
      alternateDisplayName:
      isVisible:
      attachedLOVName:
      
\endverbatim
*/
class PLMXML_BUSINESS60_API PropertyRule : public BusinessRule
{
public:
     
    //! Default constructor
    PropertyRule( );
     
    //! Constructs a PropertyRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PropertyRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PropertyRule();

private:

	//! Assignment operator
	PropertyRule& operator=( const PropertyRule& iSrc );

	//! Copy constructor
	PropertyRule( const PropertyRule& original );
     
public:

	//! Set IsVisible
	plmxml_api::Result SetIsVisible( plmxml_api::logical arg );

	//! Get IsVisible
	plmxml_api::logical GetIsVisible() const;

	//! Check if IsVisible is set
	plmxml_api::logical HasIsVisible() const;

	//! Unset IsVisible
	plmxml_api::Result UnsetIsVisible();

	//! Get AlternateDisplayName of this PropertyRule
	plmxml_api::String GetAlternateDisplayName() const;

	//! Set AlternateDisplayName of this PropertyRule
	plmxml_api::Result SetAlternateDisplayName( const plmxml_api::String &s );
	
	//! Check if AlternateDisplayName is set
	plmxml_api::logical HasAlternateDisplayName( ) const;
	
	//! Unset AlternateDisplayName
	plmxml_api::Result UnsetAlternateDisplayName( );

	//! Set IsModifiable
	plmxml_api::Result SetIsModifiable( const ePropertyRuleIsModifiableType& arg );

	//! Get IsModifiable
	ePropertyRuleIsModifiableType GetIsModifiable() const;

	//! Set IsRequired
	plmxml_api::Result SetIsRequired( plmxml_api::logical arg );

	//! Get IsRequired
	plmxml_api::logical GetIsRequired() const;

	//! Check if IsRequired is set
	plmxml_api::logical HasIsRequired() const;

	//! Unset IsRequired
	plmxml_api::Result UnsetIsRequired();

	//! Get TypeName of this PropertyRule
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this PropertyRule
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get AttachedLOVName of this PropertyRule
	plmxml_api::String GetAttachedLOVName() const;

	//! Set AttachedLOVName of this PropertyRule
	plmxml_api::Result SetAttachedLOVName( const plmxml_api::String &s );
	
	//! Check if AttachedLOVName is set
	plmxml_api::logical HasAttachedLOVName( ) const;
	
	//! Unset AttachedLOVName
	plmxml_api::Result UnsetAttachedLOVName( );

	//! Get CombinationProperty of this PropertyRule
	plmxml_api::String GetCombinationProperty() const;

	//! Set CombinationProperty of this PropertyRule
	plmxml_api::Result SetCombinationProperty( const plmxml_api::String &s );
	
	//! Check if CombinationProperty is set
	plmxml_api::logical HasCombinationProperty( ) const;
	
	//! Unset CombinationProperty
	plmxml_api::Result UnsetCombinationProperty( );

	//! Set IsEnabled
	plmxml_api::Result SetIsEnabled( plmxml_api::logical arg );

	//! Get IsEnabled
	plmxml_api::logical GetIsEnabled() const;

	//! Check if IsEnabled is set
	plmxml_api::logical HasIsEnabled() const;

	//! Unset IsEnabled
	plmxml_api::Result UnsetIsEnabled();

	//! Get InitialValue of this PropertyRule
	plmxml_api::String GetInitialValue() const;

	//! Set InitialValue of this PropertyRule
	plmxml_api::Result SetInitialValue( const plmxml_api::String &s );
	
	//! Check if InitialValue is set
	plmxml_api::logical HasInitialValue( ) const;
	
	//! Unset InitialValue
	plmxml_api::Result UnsetInitialValue( );

	//! Set WriteOnce
	plmxml_api::Result SetWriteOnce( const ePropertyRuleWriteOnceType& arg );

	//! Get WriteOnce
	ePropertyRuleWriteOnceType GetWriteOnce() const;
 
// <PLMXML_UserCode type="functionHeaderPropertyRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassPropertyRule;


////////////////////////////////////////////////////////////////////////////////////
//! IdContextRule class
/*!
\verbatim

      This element contains a Business rule for IdContext used for Alternate Id. 

      Attributes:
      typeName:              Object Type on which this rule applies
      idContextName:                             
      identifierType:
      validationRule:
      
\endverbatim
*/
class PLMXML_BUSINESS60_API IdContextRule : public BusinessRule
{
public:
     
    //! Default constructor
    IdContextRule( );
     
    //! Constructs a IdContextRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IdContextRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IdContextRule();

private:

	//! Assignment operator
	IdContextRule& operator=( const IdContextRule& iSrc );

	//! Copy constructor
	IdContextRule( const IdContextRule& original );
     
public:

	//! Get TypeName of this IdContextRule
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this IdContextRule
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get IdContextName of this IdContextRule
	plmxml_api::String GetIdContextName() const;

	//! Set IdContextName of this IdContextRule
	plmxml_api::Result SetIdContextName( const plmxml_api::String &s );
	
	//! Check if IdContextName is set
	plmxml_api::logical HasIdContextName( ) const;
	
	//! Unset IdContextName
	plmxml_api::Result UnsetIdContextName( );

	//! Get ValidationRule of this IdContextRule
	plmxml_api::String GetValidationRule() const;

	//! Set ValidationRule of this IdContextRule
	plmxml_api::Result SetValidationRule( const plmxml_api::String &s );
	
	//! Check if ValidationRule is set
	plmxml_api::logical HasValidationRule( ) const;
	
	//! Unset ValidationRule
	plmxml_api::Result UnsetValidationRule( );

	//! Get IdentifierType of this IdContextRule
	plmxml_api::String GetIdentifierType() const;

	//! Set IdentifierType of this IdContextRule
	plmxml_api::Result SetIdentifierType( const plmxml_api::String &s );
	
	//! Check if IdentifierType is set
	plmxml_api::logical HasIdentifierType( ) const;
	
	//! Unset IdentifierType
	plmxml_api::Result UnsetIdentifierType( );
 
// <PLMXML_UserCode type="functionHeaderIdContextRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassIdContextRule;


////////////////////////////////////////////////////////////////////////////////////
//! DeepCopyRule class
/*!
\verbatim

      This element contains a Business rule of Type Deep Copy Rule. When doing a Save As 
      or Revise, specifies what should be copied forward as a physical copy or reference 
      or not copied forward at all.

      Attributes:
      
      typeName:              Object Type on which this rule applies
      operation:             Whether it is SaveAs or Revise
      copyType:
      relationType:
      attachmentType:
      isRequired:
      
\endverbatim
*/
class PLMXML_BUSINESS60_API DeepCopyRule : public BusinessRule
{
public:
     
    //! Default constructor
    DeepCopyRule( );
     
    //! Constructs a DeepCopyRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeepCopyRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeepCopyRule();

private:

	//! Assignment operator
	DeepCopyRule& operator=( const DeepCopyRule& iSrc );

	//! Copy constructor
	DeepCopyRule( const DeepCopyRule& original );
     
public:

	//! Get RelationType of this DeepCopyRule
	plmxml_api::String GetRelationType() const;

	//! Set RelationType of this DeepCopyRule
	plmxml_api::Result SetRelationType( const plmxml_api::String &s );
	
	//! Check if RelationType is set
	plmxml_api::logical HasRelationType( ) const;
	
	//! Unset RelationType
	plmxml_api::Result UnsetRelationType( );

	//! Get TypeName of this DeepCopyRule
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this DeepCopyRule
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Set IsRequired
	plmxml_api::Result SetIsRequired( plmxml_api::logical arg );

	//! Get IsRequired
	plmxml_api::logical GetIsRequired() const;

	//! Check if IsRequired is set
	plmxml_api::logical HasIsRequired() const;

	//! Unset IsRequired
	plmxml_api::Result UnsetIsRequired();

	//! Get AttachmentType of this DeepCopyRule
	plmxml_api::String GetAttachmentType() const;

	//! Set AttachmentType of this DeepCopyRule
	plmxml_api::Result SetAttachmentType( const plmxml_api::String &s );
	
	//! Check if AttachmentType is set
	plmxml_api::logical HasAttachmentType( ) const;
	
	//! Unset AttachmentType
	plmxml_api::Result UnsetAttachmentType( );

	//! Set Operation
	plmxml_api::Result SetOperation( const eDeepCopyRuleOperationType& arg );

	//! Get Operation
	eDeepCopyRuleOperationType GetOperation() const;

	//! Set CopyType
	plmxml_api::Result SetCopyType( const eDeepCopyType& arg );

	//! Get CopyType
	eDeepCopyType GetCopyType() const;
 
// <PLMXML_UserCode type="functionHeaderDeepCopyRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassDeepCopyRule;


////////////////////////////////////////////////////////////////////////////////////
//! BusinessDataDef class
/*!
\verbatim

      This element defines abstract type for Business Data Definition.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API BusinessDataDef : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    BusinessDataDef( );
     
    //! Constructs a BusinessDataDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BusinessDataDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BusinessDataDef();

private:

	//! Assignment operator
	BusinessDataDef& operator=( const BusinessDataDef& iSrc );

	//! Copy constructor
	BusinessDataDef( const BusinessDataDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderBusinessDataDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassBusinessDataDef;


////////////////////////////////////////////////////////////////////////////////////
//! ValueDetails class
/*!
\verbatim

      This is a value in a LOV (the type is also used for other purposes).
      
      Attributes:
      
      stringValue:      value, if a string
      intValue:         value, if an integer
      doubleValue:      value, if a double
      dateValue:        value, if a date
    
      indexValue:       associates an index with a LOV value
      listOfValuesRef:  used if a LOV value has a reference to another LOV.
      classification:   associates a classification string with a LOV value. The classification
                        specifies the 'meaning' of the value.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API ValueDetails : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    ValueDetails( );
     
    //! Constructs a ValueDetails with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValueDetails( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValueDetails();

private:

	//! Assignment operator
	ValueDetails& operator=( const ValueDetails& iSrc );

	//! Copy constructor
	ValueDetails( const ValueDetails& original );
     
public:

	//! Get Classification of this ValueDetails
	plmxml_api::String GetClassification() const;

	//! Set Classification of this ValueDetails
	plmxml_api::Result SetClassification( const plmxml_api::String &s );
	
	//! Check if Classification is set
	plmxml_api::logical HasClassification( ) const;
	
	//! Unset Classification
	plmxml_api::Result UnsetClassification( );

	//! Get DateValue of this ValueDetails
	plmxml_api::String GetDateValue() const;

	//! Set DateValue of this ValueDetails
	plmxml_api::Result SetDateValue( const plmxml_api::String &s );
	
	//! Check if DateValue is set
	plmxml_api::logical HasDateValue( ) const;
	
	//! Unset DateValue
	plmxml_api::Result UnsetDateValue( );

	//! Set DoubleValue
	plmxml_api::Result SetDoubleValue( double arg );

     //! Get DoubleValue
	double GetDoubleValue() const;

	//! Check if DoubleValue is set
	plmxml_api::logical HasDoubleValue() const;

	//! Unset DoubleValue
	plmxml_api::Result UnsetDoubleValue();

	//! Get ListOfValues URI as plmxml_api::String
	plmxml_api::String GetListOfValuesURI() const;

	//! Set ListOfValues URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetListOfValuesURI( const plmxml_api::String& );
	
	//! Get the handle of ListOfValues URI. Does not resolve the URI.
	plmxml_api::Result GetListOfValuesURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ListOfValues URI. URI string is unchanged.
	plmxml_api::Result SetListOfValuesURI( const plmxml_api::Handle& );
	
	//! Resolve ListOfValues URI and return an object (handle) it points to.
	plmxml_api::Result ResolveListOfValuesURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ListOfValues URI. Clears URI string and handle.
	plmxml_api::Result DeleteListOfValuesURI();
	
	//! Check if ListOfValues URI is set
	plmxml_api::logical HasListOfValuesURI( ) const;
	

	//! Get StringValue of this ValueDetails
	plmxml_api::String GetStringValue() const;

	//! Set StringValue of this ValueDetails
	plmxml_api::Result SetStringValue( const plmxml_api::String &s );
	
	//! Check if StringValue is set
	plmxml_api::logical HasStringValue( ) const;
	
	//! Unset StringValue
	plmxml_api::Result UnsetStringValue( );

	//! Set IntValue
	plmxml_api::Result SetIntValue( int arg );
     
	//! Get IntValue
	int GetIntValue() const;
     
	//! Check if IntValue is set
	plmxml_api::logical HasIntValue() const;
     
	//! Unset IntValue
	plmxml_api::Result UnsetIntValue();

	//! Set IndexValue
	plmxml_api::Result SetIndexValue( int arg );
     
	//! Get IndexValue
	int GetIndexValue() const;
     
	//! Check if IndexValue is set
	plmxml_api::logical HasIndexValue() const;
     
	//! Unset IndexValue
	plmxml_api::Result UnsetIndexValue();
 
// <PLMXML_UserCode type="functionHeaderValueDetails" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassValueDetails;


////////////////////////////////////////////////////////////////////////////////////
//! LOVAttachment class
/*!
\verbatim

      These attributes specify where the LOV is attached to,i.e. to which type and what property. 
      
      Attributes:
		 
	  typeName:        name of object type (i.e. class)
	  propertyName:    name of property
	  attachType:      type of attachment
	  level:           in an interdependent LOV, this gives the hierarchical level at which the property
	                   is attached (level 1 means the parent LOV of the LOVAttachment element).
	  classification:  in an interdependent LOV, this specifies that only values with this classification
	                   are to be used as property values. 'level' and 'classification' should not be 
	                   used together.
	  isDescription:   if true, the property values are taken from the LOV value Descriptions rather than
	                   the actual LOV values.
	  parentDepth:     in a cascading LOV, this integer specifies the number of levels above the base
	                   level which are used to construct the property value. The LOV values from the
	                   various levels are combined (top first), with a system-defined separating
	                   character. So for example parentDepth=1 means two levels are combined. Only 
	                   meaningful for string-valued LOVs.
	  
\endverbatim
*/
class PLMXML_BUSINESS60_API LOVAttachment : public plmxml_api::Object
{
public:
     
    //! Default constructor
    LOVAttachment( );
     
    //! Constructs a LOVAttachment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LOVAttachment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LOVAttachment();

private:

	//! Assignment operator
	LOVAttachment& operator=( const LOVAttachment& iSrc );

	//! Copy constructor
	LOVAttachment( const LOVAttachment& original );
     
public:

	//! Get Classification of this LOVAttachment
	plmxml_api::String GetClassification() const;

	//! Set Classification of this LOVAttachment
	plmxml_api::Result SetClassification( const plmxml_api::String &s );
	
	//! Check if Classification is set
	plmxml_api::logical HasClassification( ) const;
	
	//! Unset Classification
	plmxml_api::Result UnsetClassification( );

	//! Get PropertyName of this LOVAttachment
	plmxml_api::String GetPropertyName() const;

	//! Set PropertyName of this LOVAttachment
	plmxml_api::Result SetPropertyName( const plmxml_api::String &s );
	
	//! Check if PropertyName is set
	plmxml_api::logical HasPropertyName( ) const;
	
	//! Unset PropertyName
	plmxml_api::Result UnsetPropertyName( );

	//! Set Level
	plmxml_api::Result SetLevel( int arg );
     
	//! Get Level
	int GetLevel() const;
     
	//! Check if Level is set
	plmxml_api::logical HasLevel() const;
     
	//! Unset Level
	plmxml_api::Result UnsetLevel();

	//! Set IsDescription
	plmxml_api::Result SetIsDescription( plmxml_api::logical arg );

	//! Get IsDescription
	plmxml_api::logical GetIsDescription() const;

	//! Check if IsDescription is set
	plmxml_api::logical HasIsDescription() const;

	//! Unset IsDescription
	plmxml_api::Result UnsetIsDescription();

	//! Set AttachType
	plmxml_api::Result SetAttachType( const eLOVAttachmentEnum& arg );

	//! Get AttachType
	eLOVAttachmentEnum GetAttachType() const;

	//! Get TypeName of this LOVAttachment
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this LOVAttachment
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Set ParentDepth
	plmxml_api::Result SetParentDepth( int arg );
     
	//! Get ParentDepth
	int GetParentDepth() const;
     
	//! Check if ParentDepth is set
	plmxml_api::logical HasParentDepth() const;
     
	//! Unset ParentDepth
	plmxml_api::Result UnsetParentDepth();
 
// <PLMXML_UserCode type="functionHeaderLOVAttachment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassLOVAttachment;


////////////////////////////////////////////////////////////////////////////////////
//! ListOfValues class
/*!
\verbatim

      A List-of-Values.
      
      Sub-elements:
      
      LovValueDetails:     The values in the LOV.
      LovAttachTypes:      deprecated
      LovAttachProperties: deprecated
      LOVAttachment:       Specifies the property, type and level to which the LOV is attached.
		 
\endverbatim
*/
class PLMXML_BUSINESS60_API ListOfValues : public BusinessDataDef
{
public:
     
    //! Default constructor
    ListOfValues( );
     
    //! Constructs a ListOfValues with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ListOfValues( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ListOfValues();

private:

	//! Assignment operator
	ListOfValues& operator=( const ListOfValues& iSrc );

	//! Copy constructor
	ListOfValues( const ListOfValues& original );
     
public:

	//! Set LovType
	plmxml_api::Result SetLovType( const eLOVType& arg );

	//! Get LovType
	eLOVType GetLovType() const;

	//! Set LovUsage
	plmxml_api::Result SetLovUsage( const eLOVUsageType& arg );

	//! Get LovUsage
	eLOVUsageType GetLovUsage() const;

	//! Get ReferenceAttribute of this ListOfValues
	plmxml_api::String GetReferenceAttribute() const;

	//! Set ReferenceAttribute of this ListOfValues
	plmxml_api::Result SetReferenceAttribute( const plmxml_api::String &s );
	
	//! Check if ReferenceAttribute is set
	plmxml_api::logical HasReferenceAttribute( ) const;
	
	//! Unset ReferenceAttribute
	plmxml_api::Result UnsetReferenceAttribute( );

	//! Get RangeMaxValue of this ListOfValues
	plmxml_api::String GetRangeMaxValue() const;

	//! Set RangeMaxValue of this ListOfValues
	plmxml_api::Result SetRangeMaxValue( const plmxml_api::String &s );
	
	//! Check if RangeMaxValue is set
	plmxml_api::logical HasRangeMaxValue( ) const;
	
	//! Unset RangeMaxValue
	plmxml_api::Result UnsetRangeMaxValue( );

	//! Get ReferenceClass of this ListOfValues
	plmxml_api::String GetReferenceClass() const;

	//! Set ReferenceClass of this ListOfValues
	plmxml_api::Result SetReferenceClass( const plmxml_api::String &s );
	
	//! Check if ReferenceClass is set
	plmxml_api::logical HasReferenceClass( ) const;
	
	//! Unset ReferenceClass
	plmxml_api::Result UnsetReferenceClass( );

	//! Set ValueType
	plmxml_api::Result SetValueType( const eLOVValueType& arg );

	//! Get ValueType
	eLOVValueType GetValueType() const;

	//! Get RangeMinValue of this ListOfValues
	plmxml_api::String GetRangeMinValue() const;

	//! Set RangeMinValue of this ListOfValues
	plmxml_api::Result SetRangeMinValue( const plmxml_api::String &s );
	
	//! Check if RangeMinValue is set
	plmxml_api::logical HasRangeMinValue( ) const;
	
	//! Unset RangeMinValue
	plmxml_api::Result UnsetRangeMinValue( );

	//! Add LovValueDetails child element to this ListOfValues. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueDetails *AddLovValueDetails();
     
	//! Add 'arg' as LovValueDetails child element to this ListOfValues.
	plmxml_api::Result AddLovValueDetails( ValueDetails *arg );

	//! Detach and delete all LovValueDetails child elements.
	void DeleteLovValueDetails();
     
	//! Get number of LovValueDetails child elements.
	int NumberOfLovValueDetails() const;
     
	//! Get i'th LovValueDetails child element.
	ValueDetails *GetLovValueDetails( int i ) const;
     
	//! Get all LovValueDetails child element as an array
	void GetLovValueDetails( plmxml_api::Array<ValueDetails*> &array ) const;
	     
	//! Detach and delete i'th LovValueDetails child element
	void DeleteLovValueDetails( int i );
     
	//! Detach and delete 'arg' if it's one of the LovValueDetails child elements
	void DeleteLovValueDetails( ValueDetails *arg );

	//! Add LovAttachTypes child element to this ListOfValues. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueDetails *AddLovAttachTypes();
     
	//! Add 'arg' as LovAttachTypes child element to this ListOfValues.
	plmxml_api::Result AddLovAttachTypes( ValueDetails *arg );

	//! Detach and delete all LovAttachTypes child elements.
	void DeleteLovAttachTypes();
     
	//! Get number of LovAttachTypes child elements.
	int NumberOfLovAttachTypes() const;
     
	//! Get i'th LovAttachTypes child element.
	ValueDetails *GetLovAttachTypes( int i ) const;
     
	//! Get all LovAttachTypes child element as an array
	void GetLovAttachTypes( plmxml_api::Array<ValueDetails*> &array ) const;
	     
	//! Detach and delete i'th LovAttachTypes child element
	void DeleteLovAttachTypes( int i );
     
	//! Detach and delete 'arg' if it's one of the LovAttachTypes child elements
	void DeleteLovAttachTypes( ValueDetails *arg );

	//! Add LovAttachProperties child element to this ListOfValues. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueDetails *AddLovAttachProperties();
     
	//! Add 'arg' as LovAttachProperties child element to this ListOfValues.
	plmxml_api::Result AddLovAttachProperties( ValueDetails *arg );

	//! Detach and delete all LovAttachProperties child elements.
	void DeleteLovAttachProperties();
     
	//! Get number of LovAttachProperties child elements.
	int NumberOfLovAttachProperties() const;
     
	//! Get i'th LovAttachProperties child element.
	ValueDetails *GetLovAttachProperties( int i ) const;
     
	//! Get all LovAttachProperties child element as an array
	void GetLovAttachProperties( plmxml_api::Array<ValueDetails*> &array ) const;
	     
	//! Detach and delete i'th LovAttachProperties child element
	void DeleteLovAttachProperties( int i );
     
	//! Detach and delete 'arg' if it's one of the LovAttachProperties child elements
	void DeleteLovAttachProperties( ValueDetails *arg );

	//! Add LOVAttachment child element to this ListOfValues. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	LOVAttachment *AddLOVAttachment();
     
	//! Add 'arg' as LOVAttachment child element to this ListOfValues.
	plmxml_api::Result AddLOVAttachment( LOVAttachment *arg );

	//! Detach and delete all LOVAttachment child elements.
	void DeleteLOVAttachments();
     
	//! Get number of LOVAttachment child elements.
	int NumberOfLOVAttachments() const;
     
	//! Get i'th LOVAttachment child element.
	LOVAttachment *GetLOVAttachment( int i ) const;
     
	//! Get all LOVAttachment child element as an array
	void GetLOVAttachments( plmxml_api::Array<LOVAttachment*> &array ) const;
	     
	//! Detach and delete i'th LOVAttachment child element
	void DeleteLOVAttachment( int i );
     
	//! Detach and delete 'arg' if it's one of the LOVAttachment child elements
	void DeleteLOVAttachment( LOVAttachment *arg );
 
// <PLMXML_UserCode type="functionHeaderListOfValues" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassListOfValues;


////////////////////////////////////////////////////////////////////////////////////
//! ListOfValuesFilter class
/*!
\verbatim

      A List-of-Values defined as a filter.
      
      attributes:
            
      basedOnLOVRef:         reference to based on LOV
      filterIndices:         indices into the referenced LOV.
		 
\endverbatim
*/
class PLMXML_BUSINESS60_API ListOfValuesFilter : public ListOfValues
{
public:
     
    //! Default constructor
    ListOfValuesFilter( );
     
    //! Constructs a ListOfValuesFilter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ListOfValuesFilter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ListOfValuesFilter();

private:

	//! Assignment operator
	ListOfValuesFilter& operator=( const ListOfValuesFilter& iSrc );

	//! Copy constructor
	ListOfValuesFilter( const ListOfValuesFilter& original );
     
public:

	//! Get BasedOnLOV URI as plmxml_api::String
	plmxml_api::String GetBasedOnLOVURI() const;

	//! Set BasedOnLOV URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetBasedOnLOVURI( const plmxml_api::String& );
	
	//! Get the handle of BasedOnLOV URI. Does not resolve the URI.
	plmxml_api::Result GetBasedOnLOVURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of BasedOnLOV URI. URI string is unchanged.
	plmxml_api::Result SetBasedOnLOVURI( const plmxml_api::Handle& );
	
	//! Resolve BasedOnLOV URI and return an object (handle) it points to.
	plmxml_api::Result ResolveBasedOnLOVURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset BasedOnLOV URI. Clears URI string and handle.
	plmxml_api::Result DeleteBasedOnLOVURI();
	
	//! Check if BasedOnLOV URI is set
	plmxml_api::logical HasBasedOnLOVURI( ) const;
	

     //! Set FilterIndices array
     plmxml_api::Result SetFilterIndices( const plmxml_api::Array<int>& arg );
     
     //! Get FilterIndices array
     plmxml_api::Result GetFilterIndices( plmxml_api::Array<int>& arg ) const;
     
     //! Check if FilterIndices array is set
     plmxml_api::logical HasFilterIndices() const;
     
     //! Empty FilterIndices array
     plmxml_api::Result UnsetFilterIndices();
 
// <PLMXML_UserCode type="functionHeaderListOfValuesFilter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassListOfValuesFilter;


////////////////////////////////////////////////////////////////////////////////////
//! SavedQueryDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API SavedQueryDef : public BusinessDataDef
{
public:
     
    //! Default constructor
    SavedQueryDef( );
     
    //! Constructs a SavedQueryDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SavedQueryDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SavedQueryDef();

private:

	//! Assignment operator
	SavedQueryDef& operator=( const SavedQueryDef& iSrc );

	//! Copy constructor
	SavedQueryDef( const SavedQueryDef& original );
     
public:

	//! Set QueryFlag
	plmxml_api::Result SetQueryFlag( int arg );
     
	//! Get QueryFlag
	int GetQueryFlag() const;
     
	//! Check if QueryFlag is set
	plmxml_api::logical HasQueryFlag() const;
     
	//! Unset QueryFlag
	plmxml_api::Result UnsetQueryFlag();

	//! Get QueryClass of this SavedQueryDef
	plmxml_api::String GetQueryClass() const;

	//! Set QueryClass of this SavedQueryDef
	plmxml_api::Result SetQueryClass( const plmxml_api::String &s );
	
	//! Check if QueryClass is set
	plmxml_api::logical HasQueryClass( ) const;
	
	//! Unset QueryClass
	plmxml_api::Result UnsetQueryClass( );

	//! Set ResultsType
	plmxml_api::Result SetResultsType( const eSavedQueryResultsEnum& arg );

	//! Get ResultsType
	eSavedQueryResultsEnum GetResultsType() const;

	//! Add QueryClause child element to this SavedQueryDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueDetails *AddQueryClause();
     
	//! Add 'arg' as QueryClause child element to this SavedQueryDef.
	plmxml_api::Result AddQueryClause( ValueDetails *arg );

	//! Detach and delete all QueryClause child elements.
	void DeleteQueryClauses();
     
	//! Get number of QueryClause child elements.
	int NumberOfQueryClauses() const;
     
	//! Get i'th QueryClause child element.
	ValueDetails *GetQueryClause( int i ) const;
     
	//! Get all QueryClause child element as an array
	void GetQueryClauses( plmxml_api::Array<ValueDetails*> &array ) const;
	     
	//! Detach and delete i'th QueryClause child element
	void DeleteQueryClause( int i );
     
	//! Detach and delete 'arg' if it's one of the QueryClause child elements
	void DeleteQueryClause( ValueDetails *arg );
 
// <PLMXML_UserCode type="functionHeaderSavedQueryDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassSavedQueryDef;


////////////////////////////////////////////////////////////////////////////////////
//! DataTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API DataTypeDef : public BusinessDataDef
{
public:
     
    //! Default constructor
    DataTypeDef( );
     
    //! Constructs a DataTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DataTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DataTypeDef();

private:

	//! Assignment operator
	DataTypeDef& operator=( const DataTypeDef& iSrc );

	//! Copy constructor
	DataTypeDef( const DataTypeDef& original );
     
public:

	//! Get CName of this DataTypeDef
	plmxml_api::String GetCName() const;

	//! Set CName of this DataTypeDef
	plmxml_api::Result SetCName( const plmxml_api::String &s );
	
	//! Check if CName is set
	plmxml_api::logical HasCName( ) const;
	
	//! Unset CName
	plmxml_api::Result UnsetCName( );
 
// <PLMXML_UserCode type="functionHeaderDataTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassDataTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! GenericTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API GenericTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    GenericTypeDef( );
     
    //! Constructs a GenericTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GenericTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GenericTypeDef();

private:

	//! Assignment operator
	GenericTypeDef& operator=( const GenericTypeDef& iSrc );

	//! Copy constructor
	GenericTypeDef( const GenericTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderGenericTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassGenericTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! ItemTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API ItemTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    ItemTypeDef( );
     
    //! Constructs a ItemTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ItemTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ItemTypeDef();

private:

	//! Assignment operator
	ItemTypeDef& operator=( const ItemTypeDef& iSrc );

	//! Copy constructor
	ItemTypeDef( const ItemTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderItemTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassItemTypeDef;


//! Forward class declarations
class AttributeDef;

////////////////////////////////////////////////////////////////////////////////////
//! StorageClassDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API StorageClassDef : public BusinessDataDef
{
public:
     
    //! Default constructor
    StorageClassDef( );
     
    //! Constructs a StorageClassDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StorageClassDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StorageClassDef();

private:

	//! Assignment operator
	StorageClassDef& operator=( const StorageClassDef& iSrc );

	//! Copy constructor
	StorageClassDef( const StorageClassDef& original );
     
public:

	//! Get ParentClass of this StorageClassDef
	plmxml_api::String GetParentClass() const;

	//! Set ParentClass of this StorageClassDef
	plmxml_api::Result SetParentClass( const plmxml_api::String &s );
	
	//! Check if ParentClass is set
	plmxml_api::logical HasParentClass( ) const;
	
	//! Unset ParentClass
	plmxml_api::Result UnsetParentClass( );

	//! Add AttributeDef child element to this StorageClassDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	AttributeDef *AddAttributeDef();
     
	//! Add 'arg' as AttributeDef child element to this StorageClassDef.
	plmxml_api::Result AddAttributeDef( AttributeDef *arg );

	//! Detach and delete all AttributeDef child elements.
	void DeleteAttributeDefs();
     
	//! Get number of AttributeDef child elements.
	int NumberOfAttributeDefs() const;
     
	//! Get i'th AttributeDef child element.
	AttributeDef *GetAttributeDef( int i ) const;
     
	//! Get all AttributeDef child element as an array
	void GetAttributeDefs( plmxml_api::Array<AttributeDef*> &array ) const;
	     
	//! Detach and delete i'th AttributeDef child element
	void DeleteAttributeDef( int i );
     
	//! Detach and delete 'arg' if it's one of the AttributeDef child elements
	void DeleteAttributeDef( AttributeDef *arg );
 
// <PLMXML_UserCode type="functionHeaderStorageClassDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassStorageClassDef;


////////////////////////////////////////////////////////////////////////////////////
//! AttributeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API AttributeDef : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    AttributeDef( );
     
    //! Constructs a AttributeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AttributeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AttributeDef();

private:

	//! Assignment operator
	AttributeDef& operator=( const AttributeDef& iSrc );

	//! Copy constructor
	AttributeDef( const AttributeDef& original );
     
public:

	//! Set IsUnique
	plmxml_api::Result SetIsUnique( plmxml_api::logical arg );

	//! Get IsUnique
	plmxml_api::logical GetIsUnique() const;

	//! Check if IsUnique is set
	plmxml_api::logical HasIsUnique() const;

	//! Unset IsUnique
	plmxml_api::Result UnsetIsUnique();

	//! Set IsCandidateKey
	plmxml_api::Result SetIsCandidateKey( plmxml_api::logical arg );

	//! Get IsCandidateKey
	plmxml_api::logical GetIsCandidateKey() const;

	//! Check if IsCandidateKey is set
	plmxml_api::logical HasIsCandidateKey() const;

	//! Unset IsCandidateKey
	plmxml_api::Result UnsetIsCandidateKey();

	//! Set StringSize
	plmxml_api::Result SetStringSize( int arg );
     
	//! Get StringSize
	int GetStringSize() const;
     
	//! Check if StringSize is set
	plmxml_api::logical HasStringSize() const;
     
	//! Unset StringSize
	plmxml_api::Result UnsetStringSize();

	//! Set IsPublicRead
	plmxml_api::Result SetIsPublicRead( plmxml_api::logical arg );

	//! Get IsPublicRead
	plmxml_api::logical GetIsPublicRead() const;

	//! Check if IsPublicRead is set
	plmxml_api::logical HasIsPublicRead() const;

	//! Unset IsPublicRead
	plmxml_api::Result UnsetIsPublicRead();

	//! Get InitialValue of this AttributeDef
	plmxml_api::String GetInitialValue() const;

	//! Set InitialValue of this AttributeDef
	plmxml_api::Result SetInitialValue( const plmxml_api::String &s );
	
	//! Check if InitialValue is set
	plmxml_api::logical HasInitialValue( ) const;
	
	//! Unset InitialValue
	plmxml_api::Result UnsetInitialValue( );

	//! Set IsNullsAllowed
	plmxml_api::Result SetIsNullsAllowed( plmxml_api::logical arg );

	//! Get IsNullsAllowed
	plmxml_api::logical GetIsNullsAllowed() const;

	//! Check if IsNullsAllowed is set
	plmxml_api::logical HasIsNullsAllowed() const;

	//! Unset IsNullsAllowed
	plmxml_api::Result UnsetIsNullsAllowed();

	//! Set IsArray
	plmxml_api::Result SetIsArray( plmxml_api::logical arg );

	//! Get IsArray
	plmxml_api::logical GetIsArray() const;

	//! Check if IsArray is set
	plmxml_api::logical HasIsArray() const;

	//! Unset IsArray
	plmxml_api::Result UnsetIsArray();

	//! Set AttrType
	plmxml_api::Result SetAttrType( const eAttributeDefAttrType& arg );

	//! Get AttrType
	eAttributeDefAttrType GetAttrType() const;

	//! Set IsIgnoreErrors
	plmxml_api::Result SetIsIgnoreErrors( plmxml_api::logical arg );

	//! Get IsIgnoreErrors
	plmxml_api::logical GetIsIgnoreErrors() const;

	//! Check if IsIgnoreErrors is set
	plmxml_api::logical HasIsIgnoreErrors() const;

	//! Unset IsIgnoreErrors
	plmxml_api::Result UnsetIsIgnoreErrors();

	//! Get ReferenceClass of this AttributeDef
	plmxml_api::String GetReferenceClass() const;

	//! Set ReferenceClass of this AttributeDef
	plmxml_api::Result SetReferenceClass( const plmxml_api::String &s );
	
	//! Check if ReferenceClass is set
	plmxml_api::logical HasReferenceClass( ) const;
	
	//! Unset ReferenceClass
	plmxml_api::Result UnsetReferenceClass( );

	//! Get UpperBound of this AttributeDef
	plmxml_api::String GetUpperBound() const;

	//! Set UpperBound of this AttributeDef
	plmxml_api::Result SetUpperBound( const plmxml_api::String &s );
	
	//! Check if UpperBound is set
	plmxml_api::logical HasUpperBound( ) const;
	
	//! Unset UpperBound
	plmxml_api::Result UnsetUpperBound( );

	//! Set IsPublicWrite
	plmxml_api::Result SetIsPublicWrite( plmxml_api::logical arg );

	//! Get IsPublicWrite
	plmxml_api::logical GetIsPublicWrite() const;

	//! Check if IsPublicWrite is set
	plmxml_api::logical HasIsPublicWrite() const;

	//! Unset IsPublicWrite
	plmxml_api::Result UnsetIsPublicWrite();

	//! Get LowerBound of this AttributeDef
	plmxml_api::String GetLowerBound() const;

	//! Set LowerBound of this AttributeDef
	plmxml_api::Result SetLowerBound( const plmxml_api::String &s );
	
	//! Check if LowerBound is set
	plmxml_api::logical HasLowerBound( ) const;
	
	//! Unset LowerBound
	plmxml_api::Result UnsetLowerBound( );
 
// <PLMXML_UserCode type="functionHeaderAttributeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassAttributeDef;


////////////////////////////////////////////////////////////////////////////////////
//! FormTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API FormTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    FormTypeDef( );
     
    //! Constructs a FormTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormTypeDef();

private:

	//! Assignment operator
	FormTypeDef& operator=( const FormTypeDef& iSrc );

	//! Copy constructor
	FormTypeDef( const FormTypeDef& original );
     
public:

	//! Get DisplayFileName of this FormTypeDef
	plmxml_api::String GetDisplayFileName() const;

	//! Set DisplayFileName of this FormTypeDef
	plmxml_api::Result SetDisplayFileName( const plmxml_api::String &s );
	
	//! Check if DisplayFileName is set
	plmxml_api::logical HasDisplayFileName( ) const;
	
	//! Unset DisplayFileName
	plmxml_api::Result UnsetDisplayFileName( );

	//! Get StorageClass URI as plmxml_api::String
	plmxml_api::String GetStorageClassURI() const;

	//! Set StorageClass URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStorageClassURI( const plmxml_api::String& );
	
	//! Get the handle of StorageClass URI. Does not resolve the URI.
	plmxml_api::Result GetStorageClassURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of StorageClass URI. URI string is unchanged.
	plmxml_api::Result SetStorageClassURI( const plmxml_api::Handle& );
	
	//! Resolve StorageClass URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStorageClassURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset StorageClass URI. Clears URI string and handle.
	plmxml_api::Result DeleteStorageClassURI();
	
	//! Check if StorageClass URI is set
	plmxml_api::logical HasStorageClassURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderFormTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassFormTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! DatasetTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API DatasetTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    DatasetTypeDef( );
     
    //! Constructs a DatasetTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DatasetTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DatasetTypeDef();

private:

	//! Assignment operator
	DatasetTypeDef& operator=( const DatasetTypeDef& iSrc );

	//! Copy constructor
	DatasetTypeDef( const DatasetTypeDef& original );
     
public:

	//! Get number of URIs in ReferenceTool
	int NumberOfReferenceToolURIs() const;

	//! Get i'th URI in ReferenceTool
	plmxml_api::String GetReferenceToolURI( int i ) const;

	//! Add a URI to ReferenceTool array. Call ResolveReferenceToolURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddReferenceToolURI( const plmxml_api::String& u );

	//! Set i'th URI in ReferenceTool array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetReferenceToolURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ReferenceTool URI. Does not resolve the URI.
	plmxml_api::Result GetReferenceToolURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ReferenceTool array.
	plmxml_api::Result AddReferenceToolURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ReferenceTool array to point to 'handle'.
	plmxml_api::Result SetReferenceToolURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ReferenceTool points to.
	plmxml_api::Result ResolveReferenceToolURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ReferenceTool array.
	plmxml_api::Result DeleteReferenceToolURI( int i );

	//! Remove all URIs from ReferenceTool array.
	plmxml_api::Result DeleteReferenceToolURIs( );
	
	//! Check if ReferenceTool is set
	plmxml_api::logical HasReferenceToolURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderDatasetTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassDatasetTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! ApplicationToolDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API ApplicationToolDef : public DataTypeDef
{
public:
     
    //! Default constructor
    ApplicationToolDef( );
     
    //! Constructs a ApplicationToolDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ApplicationToolDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ApplicationToolDef();

private:

	//! Assignment operator
	ApplicationToolDef& operator=( const ApplicationToolDef& iSrc );

	//! Copy constructor
	ApplicationToolDef( const ApplicationToolDef& original );
     
public:

	//! Get VendorName of this ApplicationToolDef
	plmxml_api::String GetVendorName() const;

	//! Set VendorName of this ApplicationToolDef
	plmxml_api::Result SetVendorName( const plmxml_api::String &s );
	
	//! Check if VendorName is set
	plmxml_api::logical HasVendorName( ) const;
	
	//! Unset VendorName
	plmxml_api::Result UnsetVendorName( );

	//! Get MimeType of this ApplicationToolDef
	plmxml_api::String GetMimeType() const;

	//! Set MimeType of this ApplicationToolDef
	plmxml_api::Result SetMimeType( const plmxml_api::String &s );
	
	//! Check if MimeType is set
	plmxml_api::logical HasMimeType( ) const;
	
	//! Unset MimeType
	plmxml_api::Result UnsetMimeType( );

	//! Get ReleaseDate of this ApplicationToolDef
	plmxml_api::String GetReleaseDate() const;

	//! Set ReleaseDate of this ApplicationToolDef
	plmxml_api::Result SetReleaseDate( const plmxml_api::String &s );
	
	//! Check if ReleaseDate is set
	plmxml_api::logical HasReleaseDate( ) const;
	
	//! Unset ReleaseDate
	plmxml_api::Result UnsetReleaseDate( );

	//! Get OutputFormat of this ApplicationToolDef
	plmxml_api::String GetOutputFormat() const;

	//! Set OutputFormat of this ApplicationToolDef
	plmxml_api::Result SetOutputFormat( const plmxml_api::String &s );
	
	//! Check if OutputFormat is set
	plmxml_api::logical HasOutputFormat( ) const;
	
	//! Unset OutputFormat
	plmxml_api::Result UnsetOutputFormat( );

	//! Get Revision of this ApplicationToolDef
	plmxml_api::String GetRevision() const;

	//! Set Revision of this ApplicationToolDef
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

	//! Get ShellOrSymbolName of this ApplicationToolDef
	plmxml_api::String GetShellOrSymbolName() const;

	//! Set ShellOrSymbolName of this ApplicationToolDef
	plmxml_api::Result SetShellOrSymbolName( const plmxml_api::String &s );
	
	//! Check if ShellOrSymbolName is set
	plmxml_api::logical HasShellOrSymbolName( ) const;
	
	//! Unset ShellOrSymbolName
	plmxml_api::Result UnsetShellOrSymbolName( );

	//! Get InputFormat of this ApplicationToolDef
	plmxml_api::String GetInputFormat() const;

	//! Set InputFormat of this ApplicationToolDef
	plmxml_api::Result SetInputFormat( const plmxml_api::String &s );
	
	//! Check if InputFormat is set
	plmxml_api::logical HasInputFormat( ) const;
	
	//! Unset InputFormat
	plmxml_api::Result UnsetInputFormat( );
 
// <PLMXML_UserCode type="functionHeaderApplicationToolDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassApplicationToolDef;


////////////////////////////////////////////////////////////////////////////////////
//! AliasTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API AliasTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    AliasTypeDef( );
     
    //! Constructs a AliasTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AliasTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AliasTypeDef();

private:

	//! Assignment operator
	AliasTypeDef& operator=( const AliasTypeDef& iSrc );

	//! Copy constructor
	AliasTypeDef( const AliasTypeDef& original );
     
public:

	//! Get AliasClassName of this AliasTypeDef
	plmxml_api::String GetAliasClassName() const;

	//! Set AliasClassName of this AliasTypeDef
	plmxml_api::Result SetAliasClassName( const plmxml_api::String &s );
	
	//! Check if AliasClassName is set
	plmxml_api::logical HasAliasClassName( ) const;
	
	//! Unset AliasClassName
	plmxml_api::Result UnsetAliasClassName( );
 
// <PLMXML_UserCode type="functionHeaderAliasTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassAliasTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! IdentifierTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API IdentifierTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    IdentifierTypeDef( );
     
    //! Constructs a IdentifierTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IdentifierTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IdentifierTypeDef();

private:

	//! Assignment operator
	IdentifierTypeDef& operator=( const IdentifierTypeDef& iSrc );

	//! Copy constructor
	IdentifierTypeDef( const IdentifierTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderIdentifierTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassIdentifierTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! FolderTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API FolderTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    FolderTypeDef( );
     
    //! Constructs a FolderTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FolderTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FolderTypeDef();

private:

	//! Assignment operator
	FolderTypeDef& operator=( const FolderTypeDef& iSrc );

	//! Copy constructor
	FolderTypeDef( const FolderTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderFolderTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassFolderTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! StatusTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API StatusTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    StatusTypeDef( );
     
    //! Constructs a StatusTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StatusTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StatusTypeDef();

private:

	//! Assignment operator
	StatusTypeDef& operator=( const StatusTypeDef& iSrc );

	//! Copy constructor
	StatusTypeDef( const StatusTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderStatusTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassStatusTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! ViewTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API ViewTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    ViewTypeDef( );
     
    //! Constructs a ViewTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ViewTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ViewTypeDef();

private:

	//! Assignment operator
	ViewTypeDef& operator=( const ViewTypeDef& iSrc );

	//! Copy constructor
	ViewTypeDef( const ViewTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderViewTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassViewTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! NoteTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API NoteTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    NoteTypeDef( );
     
    //! Constructs a NoteTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NoteTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NoteTypeDef();

private:

	//! Assignment operator
	NoteTypeDef& operator=( const NoteTypeDef& iSrc );

	//! Copy constructor
	NoteTypeDef( const NoteTypeDef& original );
     
public:

	//! Get DefaultValue of this NoteTypeDef
	plmxml_api::String GetDefaultValue() const;

	//! Set DefaultValue of this NoteTypeDef
	plmxml_api::Result SetDefaultValue( const plmxml_api::String &s );
	
	//! Check if DefaultValue is set
	plmxml_api::logical HasDefaultValue( ) const;
	
	//! Unset DefaultValue
	plmxml_api::Result UnsetDefaultValue( );

	//! Set AttachValueList
	plmxml_api::Result SetAttachValueList( plmxml_api::logical arg );

	//! Get AttachValueList
	plmxml_api::logical GetAttachValueList() const;

	//! Check if AttachValueList is set
	plmxml_api::logical HasAttachValueList() const;

	//! Unset AttachValueList
	plmxml_api::Result UnsetAttachValueList();

	//! Add NoteValue child element to this NoteTypeDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueDetails *AddNoteValue();
     
	//! Add 'arg' as NoteValue child element to this NoteTypeDef.
	plmxml_api::Result AddNoteValue( ValueDetails *arg );

	//! Detach and delete all NoteValue child elements.
	void DeleteNoteValues();
     
	//! Get number of NoteValue child elements.
	int NumberOfNoteValues() const;
     
	//! Get i'th NoteValue child element.
	ValueDetails *GetNoteValue( int i ) const;
     
	//! Get all NoteValue child element as an array
	void GetNoteValues( plmxml_api::Array<ValueDetails*> &array ) const;
	     
	//! Detach and delete i'th NoteValue child element
	void DeleteNoteValue( int i );
     
	//! Detach and delete 'arg' if it's one of the NoteValue child elements
	void DeleteNoteValue( ValueDetails *arg );
 
// <PLMXML_UserCode type="functionHeaderNoteTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassNoteTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! UnitOfMeasureDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API UnitOfMeasureDef : public DataTypeDef
{
public:
     
    //! Default constructor
    UnitOfMeasureDef( );
     
    //! Constructs a UnitOfMeasureDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UnitOfMeasureDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UnitOfMeasureDef();

private:

	//! Assignment operator
	UnitOfMeasureDef& operator=( const UnitOfMeasureDef& iSrc );

	//! Copy constructor
	UnitOfMeasureDef( const UnitOfMeasureDef& original );
     
public:

	//! Get Symbol of this UnitOfMeasureDef
	plmxml_api::String GetSymbol() const;

	//! Set Symbol of this UnitOfMeasureDef
	plmxml_api::Result SetSymbol( const plmxml_api::String &s );
	
	//! Check if Symbol is set
	plmxml_api::logical HasSymbol( ) const;
	
	//! Unset Symbol
	plmxml_api::Result UnsetSymbol( );
 
// <PLMXML_UserCode type="functionHeaderUnitOfMeasureDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassUnitOfMeasureDef;


////////////////////////////////////////////////////////////////////////////////////
//! RelationTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API RelationTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    RelationTypeDef( );
     
    //! Constructs a RelationTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RelationTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RelationTypeDef();

private:

	//! Assignment operator
	RelationTypeDef& operator=( const RelationTypeDef& iSrc );

	//! Copy constructor
	RelationTypeDef( const RelationTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRelationTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassRelationTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! StorageMediaDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API StorageMediaDef : public DataTypeDef
{
public:
     
    //! Default constructor
    StorageMediaDef( );
     
    //! Constructs a StorageMediaDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StorageMediaDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StorageMediaDef();

private:

	//! Assignment operator
	StorageMediaDef& operator=( const StorageMediaDef& iSrc );

	//! Copy constructor
	StorageMediaDef( const StorageMediaDef& original );
     
public:

	//! Set MediaType
	plmxml_api::Result SetMediaType( const eStorageMediaType& arg );

	//! Get MediaType
	eStorageMediaType GetMediaType() const;

	//! Get LogicalDevice of this StorageMediaDef
	plmxml_api::String GetLogicalDevice() const;

	//! Set LogicalDevice of this StorageMediaDef
	plmxml_api::Result SetLogicalDevice( const plmxml_api::String &s );
	
	//! Check if LogicalDevice is set
	plmxml_api::logical HasLogicalDevice( ) const;
	
	//! Unset LogicalDevice
	plmxml_api::Result UnsetLogicalDevice( );
 
// <PLMXML_UserCode type="functionHeaderStorageMediaDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassStorageMediaDef;


////////////////////////////////////////////////////////////////////////////////////
//! MEProcessTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API MEProcessTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    MEProcessTypeDef( );
     
    //! Constructs a MEProcessTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MEProcessTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MEProcessTypeDef();

private:

	//! Assignment operator
	MEProcessTypeDef& operator=( const MEProcessTypeDef& iSrc );

	//! Copy constructor
	MEProcessTypeDef( const MEProcessTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMEProcessTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMEProcessTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! ProductInstanceTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API ProductInstanceTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    ProductInstanceTypeDef( );
     
    //! Constructs a ProductInstanceTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProductInstanceTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProductInstanceTypeDef();

private:

	//! Assignment operator
	ProductInstanceTypeDef& operator=( const ProductInstanceTypeDef& iSrc );

	//! Copy constructor
	ProductInstanceTypeDef( const ProductInstanceTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProductInstanceTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassProductInstanceTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! WorkAreaTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API WorkAreaTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    WorkAreaTypeDef( );
     
    //! Constructs a WorkAreaTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkAreaTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkAreaTypeDef();

private:

	//! Assignment operator
	WorkAreaTypeDef& operator=( const WorkAreaTypeDef& iSrc );

	//! Copy constructor
	WorkAreaTypeDef( const WorkAreaTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderWorkAreaTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassWorkAreaTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! ActivityTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API ActivityTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    ActivityTypeDef( );
     
    //! Constructs a ActivityTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ActivityTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ActivityTypeDef();

private:

	//! Assignment operator
	ActivityTypeDef& operator=( const ActivityTypeDef& iSrc );

	//! Copy constructor
	ActivityTypeDef( const ActivityTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderActivityTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassActivityTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! MEOperationTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API MEOperationTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    MEOperationTypeDef( );
     
    //! Constructs a MEOperationTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MEOperationTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MEOperationTypeDef();

private:

	//! Assignment operator
	MEOperationTypeDef& operator=( const MEOperationTypeDef& iSrc );

	//! Copy constructor
	MEOperationTypeDef( const MEOperationTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMEOperationTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMEOperationTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! OccurrenceGroupTypeDef class
/*!
\verbatim

\endverbatim
*/
class PLMXML_BUSINESS60_API OccurrenceGroupTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    OccurrenceGroupTypeDef( );
     
    //! Constructs a OccurrenceGroupTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OccurrenceGroupTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OccurrenceGroupTypeDef();

private:

	//! Assignment operator
	OccurrenceGroupTypeDef& operator=( const OccurrenceGroupTypeDef& iSrc );

	//! Copy constructor
	OccurrenceGroupTypeDef( const OccurrenceGroupTypeDef& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderOccurrenceGroupTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassOccurrenceGroupTypeDef;


//! Forward class declarations
class ChangeIdDef;

////////////////////////////////////////////////////////////////////////////////////
//! ChangeTypeDef class
/*!
\verbatim

      attributes:
      
      formTypeDefRefs:   references the Form Types related to this Change type.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API ChangeTypeDef : public DataTypeDef
{
public:
     
    //! Default constructor
    ChangeTypeDef( );
     
    //! Constructs a ChangeTypeDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChangeTypeDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChangeTypeDef();

private:

	//! Assignment operator
	ChangeTypeDef& operator=( const ChangeTypeDef& iSrc );

	//! Copy constructor
	ChangeTypeDef( const ChangeTypeDef& original );
     
public:

	//! Set IsEffectivityShared
	plmxml_api::Result SetIsEffectivityShared( plmxml_api::logical arg );

	//! Get IsEffectivityShared
	plmxml_api::logical GetIsEffectivityShared() const;

	//! Check if IsEffectivityShared is set
	plmxml_api::logical HasIsEffectivityShared() const;

	//! Unset IsEffectivityShared
	plmxml_api::Result UnsetIsEffectivityShared();

	//! Get number of URIs in FormTypeDef
	int NumberOfFormTypeDefURIs() const;

	//! Get i'th URI in FormTypeDef
	plmxml_api::String GetFormTypeDefURI( int i ) const;

	//! Add a URI to FormTypeDef array. Call ResolveFormTypeDefURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFormTypeDefURI( const plmxml_api::String& u );

	//! Set i'th URI in FormTypeDef array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFormTypeDefURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of FormTypeDef URI. Does not resolve the URI.
	plmxml_api::Result GetFormTypeDefURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to FormTypeDef array.
	plmxml_api::Result AddFormTypeDefURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in FormTypeDef array to point to 'handle'.
	plmxml_api::Result SetFormTypeDefURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in FormTypeDef points to.
	plmxml_api::Result ResolveFormTypeDefURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from FormTypeDef array.
	plmxml_api::Result DeleteFormTypeDefURI( int i );

	//! Remove all URIs from FormTypeDef array.
	plmxml_api::Result DeleteFormTypeDefURIs( );
	
	//! Check if FormTypeDef is set
	plmxml_api::logical HasFormTypeDefURIs( ) const;

	//! Add FormType child element to this ChangeTypeDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FormTypeDef *AddFormType();
     
	//! Add 'arg' as FormType child element to this ChangeTypeDef.
	plmxml_api::Result AddFormType( FormTypeDef *arg );

	//! Detach and delete all FormType child elements.
	void DeleteFormTypes();
     
	//! Get number of FormType child elements.
	int NumberOfFormTypes() const;
     
	//! Get i'th FormType child element.
	FormTypeDef *GetFormType( int i ) const;
     
	//! Get all FormType child element as an array
	void GetFormTypes( plmxml_api::Array<FormTypeDef*> &array ) const;
	     
	//! Detach and delete i'th FormType child element
	void DeleteFormType( int i );
     
	//! Detach and delete 'arg' if it's one of the FormType child elements
	void DeleteFormType( FormTypeDef *arg );

	//! Add ChangeId child element to this ChangeTypeDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ChangeIdDef *AddChangeId();
     
	//! Add 'arg' as ChangeId child element to this ChangeTypeDef.
	plmxml_api::Result AddChangeId( ChangeIdDef *arg );

	//! Detach and delete all ChangeId child elements.
	void DeleteChangeIds();
     
	//! Get number of ChangeId child elements.
	int NumberOfChangeIds() const;
     
	//! Get i'th ChangeId child element.
	ChangeIdDef *GetChangeId( int i ) const;
     
	//! Get all ChangeId child element as an array
	void GetChangeIds( plmxml_api::Array<ChangeIdDef*> &array ) const;
	     
	//! Detach and delete i'th ChangeId child element
	void DeleteChangeId( int i );
     
	//! Detach and delete 'arg' if it's one of the ChangeId child elements
	void DeleteChangeId( ChangeIdDef *arg );

	//! Add RevId child element to this ChangeTypeDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ChangeIdDef *AddRevId();
     
	//! Add 'arg' as RevId child element to this ChangeTypeDef.
	plmxml_api::Result AddRevId( ChangeIdDef *arg );

	//! Detach and delete all RevId child elements.
	void DeleteRevIds();
     
	//! Get number of RevId child elements.
	int NumberOfRevIds() const;
     
	//! Get i'th RevId child element.
	ChangeIdDef *GetRevId( int i ) const;
     
	//! Get all RevId child element as an array
	void GetRevIds( plmxml_api::Array<ChangeIdDef*> &array ) const;
	     
	//! Detach and delete i'th RevId child element
	void DeleteRevId( int i );
     
	//! Detach and delete 'arg' if it's one of the RevId child elements
	void DeleteRevId( ChangeIdDef *arg );

	//! Add Process child element to this ChangeTypeDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::StringField *AddProcess();
     
	//! Add 'arg' as Process child element to this ChangeTypeDef.
	plmxml_api::Result AddProcess( plmxml60::StringField *arg );

	//! Detach and delete all Process child elements.
	void DeleteProcesses();
     
	//! Get number of Process child elements.
	int NumberOfProcesses() const;
     
	//! Get i'th Process child element.
	plmxml60::StringField *GetProcess( int i ) const;
     
	//! Get all Process child element as an array
	void GetProcesses( plmxml_api::Array<plmxml60::StringField*> &array ) const;
	     
	//! Detach and delete i'th Process child element
	void DeleteProcess( int i );
     
	//! Detach and delete 'arg' if it's one of the Process child elements
	void DeleteProcess( plmxml60::StringField *arg );
 
// <PLMXML_UserCode type="functionHeaderChangeTypeDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassChangeTypeDef;


////////////////////////////////////////////////////////////////////////////////////
//! ChangeIdDef class
/*!
\verbatim

      attributes:
      
      length:         number of characters or digits in the ID
      
\endverbatim
*/
class PLMXML_BUSINESS60_API ChangeIdDef : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    ChangeIdDef( );
     
    //! Constructs a ChangeIdDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ChangeIdDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ChangeIdDef();

private:

	//! Assignment operator
	ChangeIdDef& operator=( const ChangeIdDef& iSrc );

	//! Copy constructor
	ChangeIdDef( const ChangeIdDef& original );
     
public:

	//! Get Range of this ChangeIdDef
	plmxml_api::String GetRange() const;

	//! Set Range of this ChangeIdDef
	plmxml_api::Result SetRange( const plmxml_api::String &s );
	
	//! Check if Range is set
	plmxml_api::logical HasRange( ) const;
	
	//! Unset Range
	plmxml_api::Result UnsetRange( );

	//! Set ChangeFormat
	plmxml_api::Result SetChangeFormat( const eChangeIdDefFormatType& arg );

	//! Get ChangeFormat
	eChangeIdDefFormatType GetChangeFormat() const;

	//! Set Length
	plmxml_api::Result SetLength( int arg );
     
	//! Get Length
	int GetLength() const;
     
	//! Check if Length is set
	plmxml_api::logical HasLength() const;
     
	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Get Value of this ChangeIdDef
	plmxml_api::String GetValue() const;

	//! Set Value of this ChangeIdDef
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderChangeIdDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassChangeIdDef;


////////////////////////////////////////////////////////////////////////////////////
//! TransferMode class
/*!
\verbatim

      Represents the TransferMode information for PLM XML based Import/Export from TC.
                             
      Attributes:
                              
      contextString       User Specified String that the TransferMode carries.
      direction           Import or Export Mode.
      incremental         Specified whether the mode defines full transfer or incremental transfer
      closureRule         Reference to a Closure Rule Element
      filter              Reference to a Filter Element
      propertySet         Reference to a PropertySet Element

      configObjects       Reference to either Context Objects or individual configuration 
                          objects i.e. Saved Variant Rule and/or Revision Rule.
      xsltFiles           Reference to ExternalFile elements that contain XSLT Transform file links.
      actionList          Reference to ApplicationToolDef
      diagramRuleRef:     References a DiagramRule.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API TransferMode : public BusinessDataDef
{
public:
     
    //! Default constructor
    TransferMode( );
     
    //! Constructs a TransferMode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TransferMode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TransferMode();

private:

	//! Assignment operator
	TransferMode& operator=( const TransferMode& iSrc );

	//! Copy constructor
	TransferMode( const TransferMode& original );
     
public:

	//! Get Filter URI as plmxml_api::String
	plmxml_api::String GetFilterURI() const;

	//! Set Filter URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFilterURI( const plmxml_api::String& );
	
	//! Get the handle of Filter URI. Does not resolve the URI.
	plmxml_api::Result GetFilterURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Filter URI. URI string is unchanged.
	plmxml_api::Result SetFilterURI( const plmxml_api::Handle& );
	
	//! Resolve Filter URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFilterURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Filter URI. Clears URI string and handle.
	plmxml_api::Result DeleteFilterURI();
	
	//! Check if Filter URI is set
	plmxml_api::logical HasFilterURI( ) const;
	

	//! Get number of URIs in ActionList
	int NumberOfActionListURIs() const;

	//! Get i'th URI in ActionList
	plmxml_api::String GetActionListURI( int i ) const;

	//! Add a URI to ActionList array. Call ResolveActionListURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActionListURI( const plmxml_api::String& u );

	//! Set i'th URI in ActionList array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActionListURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ActionList URI. Does not resolve the URI.
	plmxml_api::Result GetActionListURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ActionList array.
	plmxml_api::Result AddActionListURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ActionList array to point to 'handle'.
	plmxml_api::Result SetActionListURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ActionList points to.
	plmxml_api::Result ResolveActionListURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ActionList array.
	plmxml_api::Result DeleteActionListURI( int i );

	//! Remove all URIs from ActionList array.
	plmxml_api::Result DeleteActionListURIs( );
	
	//! Check if ActionList is set
	plmxml_api::logical HasActionListURIs( ) const;

	//! Get number of URIs in ConfigObjects
	int NumberOfConfigObjectsURIs() const;

	//! Get i'th URI in ConfigObjects
	plmxml_api::String GetConfigObjectsURI( int i ) const;

	//! Add a URI to ConfigObjects array. Call ResolveConfigObjectsURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddConfigObjectsURI( const plmxml_api::String& u );

	//! Set i'th URI in ConfigObjects array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetConfigObjectsURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ConfigObjects URI. Does not resolve the URI.
	plmxml_api::Result GetConfigObjectsURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ConfigObjects array.
	plmxml_api::Result AddConfigObjectsURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ConfigObjects array to point to 'handle'.
	plmxml_api::Result SetConfigObjectsURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ConfigObjects points to.
	plmxml_api::Result ResolveConfigObjectsURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ConfigObjects array.
	plmxml_api::Result DeleteConfigObjectsURI( int i );

	//! Remove all URIs from ConfigObjects array.
	plmxml_api::Result DeleteConfigObjectsURIs( );
	
	//! Check if ConfigObjects is set
	plmxml_api::logical HasConfigObjectsURIs( ) const;

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
	

	//! Get number of URIs in XsltFiles
	int NumberOfXsltFilesURIs() const;

	//! Get i'th URI in XsltFiles
	plmxml_api::String GetXsltFilesURI( int i ) const;

	//! Add a URI to XsltFiles array. Call ResolveXsltFilesURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddXsltFilesURI( const plmxml_api::String& u );

	//! Set i'th URI in XsltFiles array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetXsltFilesURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of XsltFiles URI. Does not resolve the URI.
	plmxml_api::Result GetXsltFilesURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to XsltFiles array.
	plmxml_api::Result AddXsltFilesURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in XsltFiles array to point to 'handle'.
	plmxml_api::Result SetXsltFilesURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in XsltFiles points to.
	plmxml_api::Result ResolveXsltFilesURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from XsltFiles array.
	plmxml_api::Result DeleteXsltFilesURI( int i );

	//! Remove all URIs from XsltFiles array.
	plmxml_api::Result DeleteXsltFilesURIs( );
	
	//! Check if XsltFiles is set
	plmxml_api::logical HasXsltFilesURIs( ) const;

	//! Set Incremental
	plmxml_api::Result SetIncremental( plmxml_api::logical arg );

	//! Get Incremental
	plmxml_api::logical GetIncremental() const;

	//! Check if Incremental is set
	plmxml_api::logical HasIncremental() const;

	//! Unset Incremental
	plmxml_api::Result UnsetIncremental();

	//! Get ContextString of this TransferMode
	plmxml_api::String GetContextString() const;

	//! Set ContextString of this TransferMode
	plmxml_api::Result SetContextString( const plmxml_api::String &s );
	
	//! Check if ContextString is set
	plmxml_api::logical HasContextString( ) const;
	
	//! Unset ContextString
	plmxml_api::Result UnsetContextString( );

	//! Set Direction
	plmxml_api::Result SetDirection( const eTransferModeDirectionType& arg );

	//! Get Direction
	eTransferModeDirectionType GetDirection() const;

	//! Get PropertySet URI as plmxml_api::String
	plmxml_api::String GetPropertySetURI() const;

	//! Set PropertySet URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPropertySetURI( const plmxml_api::String& );
	
	//! Get the handle of PropertySet URI. Does not resolve the URI.
	plmxml_api::Result GetPropertySetURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of PropertySet URI. URI string is unchanged.
	plmxml_api::Result SetPropertySetURI( const plmxml_api::Handle& );
	
	//! Resolve PropertySet URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePropertySetURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset PropertySet URI. Clears URI string and handle.
	plmxml_api::Result DeletePropertySetURI();
	
	//! Check if PropertySet URI is set
	plmxml_api::logical HasPropertySetURI( ) const;
	

	//! Get DiagramRule URI as plmxml_api::String
	plmxml_api::String GetDiagramRuleURI() const;

	//! Set DiagramRule URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetDiagramRuleURI( const plmxml_api::String& );
	
	//! Get the handle of DiagramRule URI. Does not resolve the URI.
	plmxml_api::Result GetDiagramRuleURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of DiagramRule URI. URI string is unchanged.
	plmxml_api::Result SetDiagramRuleURI( const plmxml_api::Handle& );
	
	//! Resolve DiagramRule URI and return an object (handle) it points to.
	plmxml_api::Result ResolveDiagramRuleURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset DiagramRule URI. Clears URI string and handle.
	plmxml_api::Result DeleteDiagramRuleURI();
	
	//! Check if DiagramRule URI is set
	plmxml_api::logical HasDiagramRuleURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderTransferMode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassTransferMode;


////////////////////////////////////////////////////////////////////////////////////
//! ClosureRule class
/*!
\verbatim

      Represents the Closure Rule Set for any Transfer Mode.
                             
      Attributes:
                                                      
      SubElements:
      
      Clauses        A UserList element that contains the list of Rule Strings in a CLosure Rule Set.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API ClosureRule : public BusinessDataDef
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

	//! Set Scope
	plmxml_api::Result SetScope( const eRuleScopeType& arg );

	//! Get Scope
	eRuleScopeType GetScope() const;

	//! Add Clauses child element to this ClosureRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserList *AddClauses();
     
	//! Set Clauses child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClauses( plmxml60::UserList *arg );
     
	//! Get Clauses child element of this ClosureRule.
	plmxml60::UserList *GetClauses() const;
     
	//! Detach and delete Clauses child element tree from this ClosureRule.
	void DeleteClauses();
 
// <PLMXML_UserCode type="functionHeaderClosureRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassClosureRule;


////////////////////////////////////////////////////////////////////////////////////
//! FilterRule class
/*!
\verbatim

      Represents the Filter Rule Set for any Transfer Mode.
                             
      Attributes:
                             
                              
      SubElements:
                              
      Clauses        A UserList element that contains the list of filters for various object 
                     types in the filter rule set.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API FilterRule : public BusinessDataDef
{
public:
     
    //! Default constructor
    FilterRule( );
     
    //! Constructs a FilterRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FilterRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FilterRule();

private:

	//! Assignment operator
	FilterRule& operator=( const FilterRule& iSrc );

	//! Copy constructor
	FilterRule( const FilterRule& original );
     
public:

	//! Set Scope
	plmxml_api::Result SetScope( const eRuleScopeType& arg );

	//! Get Scope
	eRuleScopeType GetScope() const;

	//! Add Clauses child element to this FilterRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserList *AddClauses();
     
	//! Set Clauses child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClauses( plmxml60::UserList *arg );
     
	//! Get Clauses child element of this FilterRule.
	plmxml60::UserList *GetClauses() const;
     
	//! Detach and delete Clauses child element tree from this FilterRule.
	void DeleteClauses();
 
// <PLMXML_UserCode type="functionHeaderFilterRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassFilterRule;


////////////////////////////////////////////////////////////////////////////////////
//! PropertySet class
/*!
\verbatim

      Represents the Property Set for any Transfer Mode.
                        
      Attributes:
                                           
      SubElements:
                         
      Clauses:        A UserList element that contains the list of property strings for 
                      various object types in the property set.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API PropertySet : public BusinessDataDef
{
public:
     
    //! Default constructor
    PropertySet( );
     
    //! Constructs a PropertySet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PropertySet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PropertySet();

private:

	//! Assignment operator
	PropertySet& operator=( const PropertySet& iSrc );

	//! Copy constructor
	PropertySet( const PropertySet& original );
     
public:

	//! Set Scope
	plmxml_api::Result SetScope( const eRuleScopeType& arg );

	//! Get Scope
	eRuleScopeType GetScope() const;

	//! Add Clauses child element to this PropertySet. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserList *AddClauses();
     
	//! Set Clauses child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClauses( plmxml60::UserList *arg );
     
	//! Get Clauses child element of this PropertySet.
	plmxml60::UserList *GetClauses() const;
     
	//! Detach and delete Clauses child element tree from this PropertySet.
	void DeleteClauses();
 
// <PLMXML_UserCode type="functionHeaderPropertySet" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassPropertySet;


////////////////////////////////////////////////////////////////////////////////////
//! MethodValidity class
/*!
\verbatim

      Represents a condition which determines whether a particular Method can
      be used with a particular Business Operation and/or MethodAttachmentPoint.
      
      Attributes:
      
      typeName:                   The allowed 'typeName' of the Operation
      propertyName:               The allowed 'propertyName' of the Operation
      operationName:              The allowed 'name' of the Operation
      methodAttachmentPointType:  The allowed type of the MethodAttachmentPoint.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodValidity : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    MethodValidity( );
     
    //! Constructs a MethodValidity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodValidity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodValidity();

private:

	//! Assignment operator
	MethodValidity& operator=( const MethodValidity& iSrc );

	//! Copy constructor
	MethodValidity( const MethodValidity& original );
     
public:

	//! Get TypeName of this MethodValidity
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this MethodValidity
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get OperationName of this MethodValidity
	plmxml_api::String GetOperationName() const;

	//! Set OperationName of this MethodValidity
	plmxml_api::Result SetOperationName( const plmxml_api::String &s );
	
	//! Check if OperationName is set
	plmxml_api::logical HasOperationName( ) const;
	
	//! Unset OperationName
	plmxml_api::Result UnsetOperationName( );

	//! Get PropertyName of this MethodValidity
	plmxml_api::String GetPropertyName() const;

	//! Set PropertyName of this MethodValidity
	plmxml_api::Result SetPropertyName( const plmxml_api::String &s );
	
	//! Check if PropertyName is set
	plmxml_api::logical HasPropertyName( ) const;
	
	//! Unset PropertyName
	plmxml_api::Result UnsetPropertyName( );

	//! Set MethodAttachmentPointType
	plmxml_api::Result SetMethodAttachmentPointType( const eMethodAttachmentPointEnum& arg );

	//! Get MethodAttachmentPointType
	eMethodAttachmentPointEnum GetMethodAttachmentPointType() const;
 
// <PLMXML_UserCode type="functionHeaderMethodValidity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodValidity;


////////////////////////////////////////////////////////////////////////////////////
//! MethodArgumentDefinition class
/*!
\verbatim

      Represents a Method Argument Definition.
      
      Attributes:
      
      name (derived):   Name of the argument.
      type:             Type of the argument ("string", "int", etc)
      required:         Whether the argument is required or not.
      queryRef:         An optional reference to a SavedQueryDef element, which when
                        invoked, returns a list of possible values of the Argument,
                        to be chosen for example by a user.    
      listOfValuesRef:  An optional reference to a ListOfValues element, which defines
                        a list of possible values. 'queryRef' and 'listOfValuesRef' should not 
                        be used together.      
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodArgumentDefinition : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    MethodArgumentDefinition( );
     
    //! Constructs a MethodArgumentDefinition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodArgumentDefinition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodArgumentDefinition();

private:

	//! Assignment operator
	MethodArgumentDefinition& operator=( const MethodArgumentDefinition& iSrc );

	//! Copy constructor
	MethodArgumentDefinition( const MethodArgumentDefinition& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const plmxml60::eUserValueDataType& arg );

	//! Get Type
	plmxml60::eUserValueDataType GetType() const;

	//! Set Required
	plmxml_api::Result SetRequired( plmxml_api::logical arg );

	//! Get Required
	plmxml_api::logical GetRequired() const;

	//! Check if Required is set
	plmxml_api::logical HasRequired() const;

	//! Unset Required
	plmxml_api::Result UnsetRequired();

	//! Get ListOfValues URI as plmxml_api::String
	plmxml_api::String GetListOfValuesURI() const;

	//! Set ListOfValues URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetListOfValuesURI( const plmxml_api::String& );
	
	//! Get the handle of ListOfValues URI. Does not resolve the URI.
	plmxml_api::Result GetListOfValuesURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ListOfValues URI. URI string is unchanged.
	plmxml_api::Result SetListOfValuesURI( const plmxml_api::Handle& );
	
	//! Resolve ListOfValues URI and return an object (handle) it points to.
	plmxml_api::Result ResolveListOfValuesURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ListOfValues URI. Clears URI string and handle.
	plmxml_api::Result DeleteListOfValuesURI();
	
	//! Check if ListOfValues URI is set
	plmxml_api::logical HasListOfValuesURI( ) const;
	

	//! Get Query URI as plmxml_api::String
	plmxml_api::String GetQueryURI() const;

	//! Set Query URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetQueryURI( const plmxml_api::String& );
	
	//! Get the handle of Query URI. Does not resolve the URI.
	plmxml_api::Result GetQueryURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Query URI. URI string is unchanged.
	plmxml_api::Result SetQueryURI( const plmxml_api::Handle& );
	
	//! Resolve Query URI and return an object (handle) it points to.
	plmxml_api::Result ResolveQueryURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Query URI. Clears URI string and handle.
	plmxml_api::Result DeleteQueryURI();
	
	//! Check if Query URI is set
	plmxml_api::logical HasQueryURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderMethodArgumentDefinition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodArgumentDefinition;


////////////////////////////////////////////////////////////////////////////////////
//! Method class
/*!
\verbatim

      Represents a Method that could be used for extending the behaviour of an operation.
                        
      attributes:
                         
      library:        Library or Jar file name that contains this method.
      language:       Language of implementation of this method.
      
      Sub-elements:
      
      ArgumentDefinition: Definitions of arguments that can be passed to the Method.                                    
      Validity:           Specifies the MethodAttachmentPoints which this Method can be 
                          connected to.   
      
\endverbatim
*/
class PLMXML_BUSINESS60_API Method : public BusinessRule
{
public:
     
    //! Default constructor
    Method( );
     
    //! Constructs a Method with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Method( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Method();

private:

	//! Assignment operator
	Method& operator=( const Method& iSrc );

	//! Copy constructor
	Method( const Method& original );
     
public:

	//! Get Library of this Method
	plmxml_api::String GetLibrary() const;

	//! Set Library of this Method
	plmxml_api::Result SetLibrary( const plmxml_api::String &s );
	
	//! Check if Library is set
	plmxml_api::logical HasLibrary( ) const;
	
	//! Unset Library
	plmxml_api::Result UnsetLibrary( );

	//! Set Language
	plmxml_api::Result SetLanguage( const eAPILanguageType& arg );

	//! Get Language
	eAPILanguageType GetLanguage() const;

	//! Add ArgumentDefinition child element to this Method. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MethodArgumentDefinition *AddArgumentDefinition();
     
	//! Add 'arg' as ArgumentDefinition child element to this Method.
	plmxml_api::Result AddArgumentDefinition( MethodArgumentDefinition *arg );

	//! Detach and delete all ArgumentDefinition child elements.
	void DeleteArgumentDefinitions();
     
	//! Get number of ArgumentDefinition child elements.
	int NumberOfArgumentDefinitions() const;
     
	//! Get i'th ArgumentDefinition child element.
	MethodArgumentDefinition *GetArgumentDefinition( int i ) const;
     
	//! Get all ArgumentDefinition child element as an array
	void GetArgumentDefinitions( plmxml_api::Array<MethodArgumentDefinition*> &array ) const;
	     
	//! Detach and delete i'th ArgumentDefinition child element
	void DeleteArgumentDefinition( int i );
     
	//! Detach and delete 'arg' if it's one of the ArgumentDefinition child elements
	void DeleteArgumentDefinition( MethodArgumentDefinition *arg );

	//! Add Validity child element to this Method. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MethodValidity *AddValidity();
     
	//! Add 'arg' as Validity child element to this Method.
	plmxml_api::Result AddValidity( MethodValidity *arg );

	//! Detach and delete all Validity child elements.
	void DeleteValidities();
     
	//! Get number of Validity child elements.
	int NumberOfValidities() const;
     
	//! Get i'th Validity child element.
	MethodValidity *GetValidity( int i ) const;
     
	//! Get all Validity child element as an array
	void GetValidities( plmxml_api::Array<MethodValidity*> &array ) const;
	     
	//! Detach and delete i'th Validity child element
	void DeleteValidity( int i );
     
	//! Detach and delete 'arg' if it's one of the Validity child elements
	void DeleteValidity( MethodValidity *arg );
 
// <PLMXML_UserCode type="functionHeaderMethod" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethod;


////////////////////////////////////////////////////////////////////////////////////
//! MethodCondition class
/*!
\verbatim

      Represents a Method Condition, which is used to determine whether
      or not to execute a Method.
      
      Attributes:
      
      methodRef:        Reference to another Method which is to be executed
                        to evaluate the Condition.
      value:            A boolean value which, if present, gives the evaluation
                        of the Condition as true or false.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodCondition : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    MethodCondition( );
     
    //! Constructs a MethodCondition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodCondition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodCondition();

private:

	//! Assignment operator
	MethodCondition& operator=( const MethodCondition& iSrc );

	//! Copy constructor
	MethodCondition( const MethodCondition& original );
     
public:

	//! Get Method URI as plmxml_api::String
	plmxml_api::String GetMethodURI() const;

	//! Set Method URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMethodURI( const plmxml_api::String& );
	
	//! Get the handle of Method URI. Does not resolve the URI.
	plmxml_api::Result GetMethodURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Method URI. URI string is unchanged.
	plmxml_api::Result SetMethodURI( const plmxml_api::Handle& );
	
	//! Resolve Method URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMethodURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Method URI. Clears URI string and handle.
	plmxml_api::Result DeleteMethodURI();
	
	//! Check if Method URI is set
	plmxml_api::logical HasMethodURI( ) const;
	

	//! Set Value
	plmxml_api::Result SetValue( plmxml_api::logical arg );

	//! Get Value
	plmxml_api::logical GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();
 
// <PLMXML_UserCode type="functionHeaderMethodCondition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodCondition;


////////////////////////////////////////////////////////////////////////////////////
//! MethodArgument class
/*!
\verbatim

      Represents a Method Argument.
      
      Attributes:
      
      name (derived):   Name of the argument.
      value:            Value of the argument.  
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodArgument : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    MethodArgument( );
     
    //! Constructs a MethodArgument with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodArgument( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodArgument();

private:

	//! Assignment operator
	MethodArgument& operator=( const MethodArgument& iSrc );

	//! Copy constructor
	MethodArgument( const MethodArgument& original );
     
public:

	//! Get Value of this MethodArgument
	plmxml_api::String GetValue() const;

	//! Set Value of this MethodArgument
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderMethodArgument" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodArgument;


////////////////////////////////////////////////////////////////////////////////////
//! MethodArgumentGroup class
/*!
\verbatim

      Represents a group of Method Arguments.
      
      Sub-elements:
      
      Argument:       An element of type MethodArgument.       
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodArgumentGroup : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    MethodArgumentGroup( );
     
    //! Constructs a MethodArgumentGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodArgumentGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodArgumentGroup();

private:

	//! Assignment operator
	MethodArgumentGroup& operator=( const MethodArgumentGroup& iSrc );

	//! Copy constructor
	MethodArgumentGroup( const MethodArgumentGroup& original );
     
public:

	//! Add Argument child element to this MethodArgumentGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MethodArgument *AddArgument();
     
	//! Add 'arg' as Argument child element to this MethodArgumentGroup.
	plmxml_api::Result AddArgument( MethodArgument *arg );

	//! Detach and delete all Argument child elements.
	void DeleteArguments();
     
	//! Get number of Argument child elements.
	int NumberOfArguments() const;
     
	//! Get i'th Argument child element.
	MethodArgument *GetArgument( int i ) const;
     
	//! Get all Argument child element as an array
	void GetArguments( plmxml_api::Array<MethodArgument*> &array ) const;
	     
	//! Detach and delete i'th Argument child element
	void DeleteArgument( int i );
     
	//! Detach and delete 'arg' if it's one of the Argument child elements
	void DeleteArgument( MethodArgument *arg );
 
// <PLMXML_UserCode type="functionHeaderMethodArgumentGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodArgumentGroup;


////////////////////////////////////////////////////////////////////////////////////
//! MethodDescriptor class
/*!
\verbatim

      Contains all the information required to execute a Method. The name of the MethodDescriptor 
      will be name of Method itself. For internally implemented Method in the system there will not be any
      methodRef.
      
      Attributes:                  
                                                                
      methodRef:      Reference to Method. Only used for non-core Methods.
      priority:       Priority of executing the specified method. Lower number has higher priority.
      
      Sub-elements:
      
      Condition:      A element of type MethodCondition. This evaluates to a boolean which
                      determines whether or not the Method method is invoked.

      ArgumentGroup:  A group of arguments to be passed to the Method. If there is more than one
                      ArgumentGroup sub-element, the Method is invoked once with each
                      group of arguments.                
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodDescriptor : public BusinessRule
{
public:
     
    //! Default constructor
    MethodDescriptor( );
     
    //! Constructs a MethodDescriptor with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodDescriptor( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodDescriptor();

private:

	//! Assignment operator
	MethodDescriptor& operator=( const MethodDescriptor& iSrc );

	//! Copy constructor
	MethodDescriptor( const MethodDescriptor& original );
     
public:

	//! Get Method URI as plmxml_api::String
	plmxml_api::String GetMethodURI() const;

	//! Set Method URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMethodURI( const plmxml_api::String& );
	
	//! Get the handle of Method URI. Does not resolve the URI.
	plmxml_api::Result GetMethodURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Method URI. URI string is unchanged.
	plmxml_api::Result SetMethodURI( const plmxml_api::Handle& );
	
	//! Resolve Method URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMethodURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Method URI. Clears URI string and handle.
	plmxml_api::Result DeleteMethodURI();
	
	//! Check if Method URI is set
	plmxml_api::logical HasMethodURI( ) const;
	

	//! Set Priority
	plmxml_api::Result SetPriority( int arg );
     
	//! Get Priority
	int GetPriority() const;
     
	//! Check if Priority is set
	plmxml_api::logical HasPriority() const;
     
	//! Unset Priority
	plmxml_api::Result UnsetPriority();

	//! Add Condition child element to this MethodDescriptor. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MethodCondition *AddCondition();
     
	//! Set Condition child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCondition( MethodCondition *arg );
     
	//! Get Condition child element of this MethodDescriptor.
	MethodCondition *GetCondition() const;
     
	//! Detach and delete Condition child element tree from this MethodDescriptor.
	void DeleteCondition();

	//! Add ArgumentGroup child element to this MethodDescriptor. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MethodArgumentGroup *AddArgumentGroup();
     
	//! Add 'arg' as ArgumentGroup child element to this MethodDescriptor.
	plmxml_api::Result AddArgumentGroup( MethodArgumentGroup *arg );

	//! Detach and delete all ArgumentGroup child elements.
	void DeleteArgumentGroups();
     
	//! Get number of ArgumentGroup child elements.
	int NumberOfArgumentGroups() const;
     
	//! Get i'th ArgumentGroup child element.
	MethodArgumentGroup *GetArgumentGroup( int i ) const;
     
	//! Get all ArgumentGroup child element as an array
	void GetArgumentGroups( plmxml_api::Array<MethodArgumentGroup*> &array ) const;
	     
	//! Detach and delete i'th ArgumentGroup child element
	void DeleteArgumentGroup( int i );
     
	//! Detach and delete 'arg' if it's one of the ArgumentGroup child elements
	void DeleteArgumentGroup( MethodArgumentGroup *arg );
 
// <PLMXML_UserCode type="functionHeaderMethodDescriptor" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodDescriptor;


////////////////////////////////////////////////////////////////////////////////////
//! MethodAttachmentPoint class
/*!
\verbatim

      This describes a Method Attachment Point in an operation.
                        
      isOverridable:             Specifies if this Attachment Point is overridable            
      isSingleMethod:            If true, this element can have only one Descriptor.
      methodAttachmentPointType: Type of the MethodAttachmentPoint. This determines when
                                 the method is executed.
      methodDescriptorRefs:      Reference to Method Descriptors that contain the methods to be 
                                 executed within this Attachment Point.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API MethodAttachmentPoint : public BusinessRule
{
public:
     
    //! Default constructor
    MethodAttachmentPoint( );
     
    //! Constructs a MethodAttachmentPoint with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MethodAttachmentPoint( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MethodAttachmentPoint();

private:

	//! Assignment operator
	MethodAttachmentPoint& operator=( const MethodAttachmentPoint& iSrc );

	//! Copy constructor
	MethodAttachmentPoint( const MethodAttachmentPoint& original );
     
public:

	//! Get number of URIs in MethodDescriptor
	int NumberOfMethodDescriptorURIs() const;

	//! Get i'th URI in MethodDescriptor
	plmxml_api::String GetMethodDescriptorURI( int i ) const;

	//! Add a URI to MethodDescriptor array. Call ResolveMethodDescriptorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddMethodDescriptorURI( const plmxml_api::String& u );

	//! Set i'th URI in MethodDescriptor array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetMethodDescriptorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of MethodDescriptor URI. Does not resolve the URI.
	plmxml_api::Result GetMethodDescriptorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to MethodDescriptor array.
	plmxml_api::Result AddMethodDescriptorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in MethodDescriptor array to point to 'handle'.
	plmxml_api::Result SetMethodDescriptorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in MethodDescriptor points to.
	plmxml_api::Result ResolveMethodDescriptorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from MethodDescriptor array.
	plmxml_api::Result DeleteMethodDescriptorURI( int i );

	//! Remove all URIs from MethodDescriptor array.
	plmxml_api::Result DeleteMethodDescriptorURIs( );
	
	//! Check if MethodDescriptor is set
	plmxml_api::logical HasMethodDescriptorURIs( ) const;

	//! Set MethodAttachmentPointType
	plmxml_api::Result SetMethodAttachmentPointType( const eMethodAttachmentPointEnum& arg );

	//! Get MethodAttachmentPointType
	eMethodAttachmentPointEnum GetMethodAttachmentPointType() const;

	//! Set IsSingleMethod
	plmxml_api::Result SetIsSingleMethod( plmxml_api::logical arg );

	//! Get IsSingleMethod
	plmxml_api::logical GetIsSingleMethod() const;

	//! Check if IsSingleMethod is set
	plmxml_api::logical HasIsSingleMethod() const;

	//! Unset IsSingleMethod
	plmxml_api::Result UnsetIsSingleMethod();

	//! Set IsOverridable
	plmxml_api::Result SetIsOverridable( plmxml_api::logical arg );

	//! Get IsOverridable
	plmxml_api::logical GetIsOverridable() const;

	//! Check if IsOverridable is set
	plmxml_api::logical HasIsOverridable() const;

	//! Unset IsOverridable
	plmxml_api::Result UnsetIsOverridable();
 
// <PLMXML_UserCode type="functionHeaderMethodAttachmentPoint" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassMethodAttachmentPoint;


////////////////////////////////////////////////////////////////////////////////////
//! BusinessOperation class
/*!
\verbatim

      This describes a Business Operation.
           
      Attributes:     
                      
      typeName:                  Object Type name on which this operation is defined
      methodAttachmentPointRefs: Reference to MethodAttachmentPoints related to this Operation.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API BusinessOperation : public BusinessRule
{
public:
     
    //! Default constructor
    BusinessOperation( );
     
    //! Constructs a BusinessOperation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BusinessOperation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BusinessOperation();

private:

	//! Assignment operator
	BusinessOperation& operator=( const BusinessOperation& iSrc );

	//! Copy constructor
	BusinessOperation( const BusinessOperation& original );
     
public:

	//! Get TypeName of this BusinessOperation
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this BusinessOperation
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get number of URIs in MethodAttachmentPoint
	int NumberOfMethodAttachmentPointURIs() const;

	//! Get i'th URI in MethodAttachmentPoint
	plmxml_api::String GetMethodAttachmentPointURI( int i ) const;

	//! Add a URI to MethodAttachmentPoint array. Call ResolveMethodAttachmentPointURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddMethodAttachmentPointURI( const plmxml_api::String& u );

	//! Set i'th URI in MethodAttachmentPoint array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetMethodAttachmentPointURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of MethodAttachmentPoint URI. Does not resolve the URI.
	plmxml_api::Result GetMethodAttachmentPointURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to MethodAttachmentPoint array.
	plmxml_api::Result AddMethodAttachmentPointURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in MethodAttachmentPoint array to point to 'handle'.
	plmxml_api::Result SetMethodAttachmentPointURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in MethodAttachmentPoint points to.
	plmxml_api::Result ResolveMethodAttachmentPointURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from MethodAttachmentPoint array.
	plmxml_api::Result DeleteMethodAttachmentPointURI( int i );

	//! Remove all URIs from MethodAttachmentPoint array.
	plmxml_api::Result DeleteMethodAttachmentPointURIs( );
	
	//! Check if MethodAttachmentPoint is set
	plmxml_api::logical HasMethodAttachmentPointURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderBusinessOperation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassBusinessOperation;


////////////////////////////////////////////////////////////////////////////////////
//! TypeBusinessOperation class
/*!
\verbatim

      This describes a Business Operation which operates on a particular type of object.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API TypeBusinessOperation : public BusinessOperation
{
public:
     
    //! Default constructor
    TypeBusinessOperation( );
     
    //! Constructs a TypeBusinessOperation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TypeBusinessOperation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TypeBusinessOperation();

private:

	//! Assignment operator
	TypeBusinessOperation& operator=( const TypeBusinessOperation& iSrc );

	//! Copy constructor
	TypeBusinessOperation( const TypeBusinessOperation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTypeBusinessOperation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassTypeBusinessOperation;


////////////////////////////////////////////////////////////////////////////////////
//! PropertyBusinessOperation class
/*!
\verbatim

      This describes a Business Operation which operates on a particular property of
      a particular Type.
           
      Attributes:     
                      
      propertyName:      Property of object where this operation is defined.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API PropertyBusinessOperation : public BusinessOperation
{
public:
     
    //! Default constructor
    PropertyBusinessOperation( );
     
    //! Constructs a PropertyBusinessOperation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PropertyBusinessOperation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PropertyBusinessOperation();

private:

	//! Assignment operator
	PropertyBusinessOperation& operator=( const PropertyBusinessOperation& iSrc );

	//! Copy constructor
	PropertyBusinessOperation( const PropertyBusinessOperation& original );
     
public:

	//! Get PropertyName of this PropertyBusinessOperation
	plmxml_api::String GetPropertyName() const;

	//! Set PropertyName of this PropertyBusinessOperation
	plmxml_api::Result SetPropertyName( const plmxml_api::String &s );
	
	//! Check if PropertyName is set
	plmxml_api::logical HasPropertyName( ) const;
	
	//! Unset PropertyName
	plmxml_api::Result UnsetPropertyName( );
 
// <PLMXML_UserCode type="functionHeaderPropertyBusinessOperation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassPropertyBusinessOperation;


////////////////////////////////////////////////////////////////////////////////////
//! ApplicationInterface class
/*!
\verbatim

      This element describes the integration between the main application and an 
      external application.
      
      Attributes:     
                      
      incrementalChangeRequired: If "true", this means that when the external application 
                           makes changes to data sent from the main app, these changes 
                           must be recorded in the main database under an Incremental Change.
      
      objectTypes:         This is an array of types, which defines the object types understood 
                           by the external application.
      viewRefs:            This is an array of View elements giving the Views which the application 
                           is allowed to access/process.
      exportTransferModeRef: This is the TransferMode used to export PLM XML to the external application.
      importTransferModeRef: This is the TransferMode used to import PLM XML from the external application.
      toolRef:             This specifies the ApplicationToolDef element which corresponds to 
                           the external application.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API ApplicationInterface : public BusinessDataDef
{
public:
     
    //! Default constructor
    ApplicationInterface( );
     
    //! Constructs a ApplicationInterface with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ApplicationInterface( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ApplicationInterface();

private:

	//! Assignment operator
	ApplicationInterface& operator=( const ApplicationInterface& iSrc );

	//! Copy constructor
	ApplicationInterface( const ApplicationInterface& original );
     
public:

	//! Get ExportTransferMode URI as plmxml_api::String
	plmxml_api::String GetExportTransferModeURI() const;

	//! Set ExportTransferMode URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetExportTransferModeURI( const plmxml_api::String& );
	
	//! Get the handle of ExportTransferMode URI. Does not resolve the URI.
	plmxml_api::Result GetExportTransferModeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ExportTransferMode URI. URI string is unchanged.
	plmxml_api::Result SetExportTransferModeURI( const plmxml_api::Handle& );
	
	//! Resolve ExportTransferMode URI and return an object (handle) it points to.
	plmxml_api::Result ResolveExportTransferModeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ExportTransferMode URI. Clears URI string and handle.
	plmxml_api::Result DeleteExportTransferModeURI();
	
	//! Check if ExportTransferMode URI is set
	plmxml_api::logical HasExportTransferModeURI( ) const;
	

	//! Get ObjectTypes of this ApplicationInterface
	plmxml_api::String GetObjectTypes() const;

	//! Set ObjectTypes of this ApplicationInterface
	plmxml_api::Result SetObjectTypes( const plmxml_api::String &s );
	
	//! Check if ObjectTypes is set
	plmxml_api::logical HasObjectTypes( ) const;
	
	//! Unset ObjectTypes
	plmxml_api::Result UnsetObjectTypes( );

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
	

	//! Set IncrementalChangeRequired
	plmxml_api::Result SetIncrementalChangeRequired( plmxml_api::logical arg );

	//! Get IncrementalChangeRequired
	plmxml_api::logical GetIncrementalChangeRequired() const;

	//! Check if IncrementalChangeRequired is set
	plmxml_api::logical HasIncrementalChangeRequired() const;

	//! Unset IncrementalChangeRequired
	plmxml_api::Result UnsetIncrementalChangeRequired();

	//! Get number of URIs in View
	int NumberOfViewURIs() const;

	//! Get i'th URI in View
	plmxml_api::String GetViewURI( int i ) const;

	//! Add a URI to View array. Call ResolveViewURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddViewURI( const plmxml_api::String& u );

	//! Set i'th URI in View array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetViewURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of View URI. Does not resolve the URI.
	plmxml_api::Result GetViewURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to View array.
	plmxml_api::Result AddViewURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in View array to point to 'handle'.
	plmxml_api::Result SetViewURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in View points to.
	plmxml_api::Result ResolveViewURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from View array.
	plmxml_api::Result DeleteViewURI( int i );

	//! Remove all URIs from View array.
	plmxml_api::Result DeleteViewURIs( );
	
	//! Check if View is set
	plmxml_api::logical HasViewURIs( ) const;

	//! Get ImportTransferMode URI as plmxml_api::String
	plmxml_api::String GetImportTransferModeURI() const;

	//! Set ImportTransferMode URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetImportTransferModeURI( const plmxml_api::String& );
	
	//! Get the handle of ImportTransferMode URI. Does not resolve the URI.
	plmxml_api::Result GetImportTransferModeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ImportTransferMode URI. URI string is unchanged.
	plmxml_api::Result SetImportTransferModeURI( const plmxml_api::Handle& );
	
	//! Resolve ImportTransferMode URI and return an object (handle) it points to.
	plmxml_api::Result ResolveImportTransferModeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ImportTransferMode URI. Clears URI string and handle.
	plmxml_api::Result DeleteImportTransferModeURI();
	
	//! Check if ImportTransferMode URI is set
	plmxml_api::logical HasImportTransferModeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderApplicationInterface" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassApplicationInterface;


////////////////////////////////////////////////////////////////////////////////////
//! AuthorisationRule class
/*!
\verbatim

      A rule authorising certain users or groups to use a specified resource.
           
      Attributes:     
                      
      targetName:         the name of the resource, e.g. an application program
      ruleDomain:         the type of resource
      accessorRefs:       the Users, Persons, OrganisationMembers, Organisations, or
                          ResourcePools which are permitted to use the resource.
      
\endverbatim
*/
class PLMXML_BUSINESS60_API AuthorisationRule : public BusinessRule
{
public:
     
    //! Default constructor
    AuthorisationRule( );
     
    //! Constructs a AuthorisationRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AuthorisationRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AuthorisationRule();

private:

	//! Assignment operator
	AuthorisationRule& operator=( const AuthorisationRule& iSrc );

	//! Copy constructor
	AuthorisationRule( const AuthorisationRule& original );
     
public:

	//! Set RuleDomain
	plmxml_api::Result SetRuleDomain( const eAuthorisationRuleDomainEnum& arg );

	//! Get RuleDomain
	eAuthorisationRuleDomainEnum GetRuleDomain() const;

	//! Get number of URIs in Accessor
	int NumberOfAccessorURIs() const;

	//! Get i'th URI in Accessor
	plmxml_api::String GetAccessorURI( int i ) const;

	//! Add a URI to Accessor array. Call ResolveAccessorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAccessorURI( const plmxml_api::String& u );

	//! Set i'th URI in Accessor array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAccessorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Accessor URI. Does not resolve the URI.
	plmxml_api::Result GetAccessorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Accessor array.
	plmxml_api::Result AddAccessorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Accessor array to point to 'handle'.
	plmxml_api::Result SetAccessorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Accessor points to.
	plmxml_api::Result ResolveAccessorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Accessor array.
	plmxml_api::Result DeleteAccessorURI( int i );

	//! Remove all URIs from Accessor array.
	plmxml_api::Result DeleteAccessorURIs( );
	
	//! Check if Accessor is set
	plmxml_api::logical HasAccessorURIs( ) const;

	//! Get TargetName of this AuthorisationRule
	plmxml_api::String GetTargetName() const;

	//! Set TargetName of this AuthorisationRule
	plmxml_api::Result SetTargetName( const plmxml_api::String &s );
	
	//! Check if TargetName is set
	plmxml_api::logical HasTargetName( ) const;
	
	//! Unset TargetName
	plmxml_api::Result UnsetTargetName( );
 
// <PLMXML_UserCode type="functionHeaderAuthorisationRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassAuthorisationRule;


////////////////////////////////////////////////////////////////////////////////////
//! PLMXMLBusinessTypes class
/*!
\verbatim

      This element is the root element for transferring Business Data Types and Rules
      
\endverbatim
*/
class PLMXML_BUSINESS60_API PLMXMLBusinessTypes : public plmxml60::DocumentBase
{
public:
     
    //! Default constructor
    PLMXMLBusinessTypes( );
     
    //! Constructs a PLMXMLBusinessTypes with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PLMXMLBusinessTypes( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PLMXMLBusinessTypes();

private:

	//! Assignment operator
	PLMXMLBusinessTypes& operator=( const PLMXMLBusinessTypes& iSrc );

	//! Copy constructor
	PLMXMLBusinessTypes( const PLMXMLBusinessTypes& original );
     
public:

	//! Add BusinessRule child element to this PLMXMLBusinessTypes. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	BusinessRule *AddBusinessRule();
     
	//! Add 'arg' as BusinessRule child element to this PLMXMLBusinessTypes.
	plmxml_api::Result AddBusinessRule( BusinessRule *arg );

	//! Detach and delete all BusinessRule child elements.
	void DeleteBusinessRules();
     
	//! Get number of BusinessRule child elements.
	int NumberOfBusinessRules() const;
     
	//! Get i'th BusinessRule child element.
	BusinessRule *GetBusinessRule( int i ) const;
     
	//! Get all BusinessRule child element as an array
	void GetBusinessRules( plmxml_api::Array<BusinessRule*> &array ) const;
	     
	//! Detach and delete i'th BusinessRule child element
	void DeleteBusinessRule( int i );
     
	//! Detach and delete 'arg' if it's one of the BusinessRule child elements
	void DeleteBusinessRule( BusinessRule *arg );

	//! Add BusinessDataDef child element to this PLMXMLBusinessTypes. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	BusinessDataDef *AddBusinessDataDef();
     
	//! Add 'arg' as BusinessDataDef child element to this PLMXMLBusinessTypes.
	plmxml_api::Result AddBusinessDataDef( BusinessDataDef *arg );

	//! Detach and delete all BusinessDataDef child elements.
	void DeleteBusinessDataDefs();
     
	//! Get number of BusinessDataDef child elements.
	int NumberOfBusinessDataDefs() const;
     
	//! Get i'th BusinessDataDef child element.
	BusinessDataDef *GetBusinessDataDef( int i ) const;
     
	//! Get all BusinessDataDef child element as an array
	void GetBusinessDataDefs( plmxml_api::Array<BusinessDataDef*> &array ) const;
	     
	//! Detach and delete i'th BusinessDataDef child element
	void DeleteBusinessDataDef( int i );
     
	//! Detach and delete 'arg' if it's one of the BusinessDataDef child elements
	void DeleteBusinessDataDef( BusinessDataDef *arg );

	//! Add AttribOwner child element to this PLMXMLBusinessTypes. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::AttribOwner *AddAttribOwner();
     
	//! Add 'arg' as AttribOwner child element to this PLMXMLBusinessTypes.
	plmxml_api::Result AddAttribOwner( plmxml60::AttribOwner *arg );

	//! Detach and delete all AttribOwner child elements.
	void DeleteAttribOwners();
     
	//! Get number of AttribOwner child elements.
	int NumberOfAttribOwners() const;
     
	//! Get i'th AttribOwner child element.
	plmxml60::AttribOwner *GetAttribOwner( int i ) const;
     
	//! Get all AttribOwner child element as an array
	void GetAttribOwners( plmxml_api::Array<plmxml60::AttribOwner*> &array ) const;
	     
	//! Detach and delete i'th AttribOwner child element
	void DeleteAttribOwner( int i );
     
	//! Detach and delete 'arg' if it's one of the AttribOwner child elements
	void DeleteAttribOwner( plmxml60::AttribOwner *arg );

	//! Add Text child element to this PLMXMLBusinessTypes. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::MultipleLanguageText *AddText();
     
	//! Add 'arg' as Text child element to this PLMXMLBusinessTypes.
	plmxml_api::Result AddText( plmxml60::MultipleLanguageText *arg );

	//! Detach and delete all Text child elements.
	void DeleteTexts();
     
	//! Get number of Text child elements.
	int NumberOfTexts() const;
     
	//! Get i'th Text child element.
	plmxml60::MultipleLanguageText *GetText( int i ) const;
     
	//! Get all Text child element as an array
	void GetTexts( plmxml_api::Array<plmxml60::MultipleLanguageText*> &array ) const;
	     
	//! Detach and delete i'th Text child element
	void DeleteText( int i );
     
	//! Detach and delete 'arg' if it's one of the Text child elements
	void DeleteText( plmxml60::MultipleLanguageText *arg );
 
// <PLMXML_UserCode type="functionHeaderPLMXMLBusinessTypes" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_BUSINESS60_API plmxml_api::plmxmlClass plmxmlClassPLMXMLBusinessTypes;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
