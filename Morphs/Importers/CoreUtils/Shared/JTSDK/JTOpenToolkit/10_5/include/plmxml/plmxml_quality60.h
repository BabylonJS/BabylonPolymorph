/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 31/05/2019 07:27:49
// 
// Schema:	PLMXMLQualitySchema.xsd
// Data:	2019-06-20
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_QUALITY60_H__
#define __PLMXML_QUALITY60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_QUALITY60_EXPORTS
#define PLMXML_QUALITY60_API __declspec(dllexport)
#else
#define PLMXML_QUALITY60_API __declspec(dllimport)
#endif
#else
#define PLMXML_QUALITY60_API
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
//! eQualityActionEnum class
/*!
Allowed Values:
\verbatim
  eQualityActionEnumGeneral
	"general"
  eQualityActionEnumControlPlan
	"controlPlan"
  eQualityActionEnumFailureModeEffectsAnalysis
	"failureModeEffectsAnalysis"
  eQualityActionEnumProgram
	"program"
  eQualityActionEnumDimension8
	"dimension8"
  
\endverbatim
*/
class PLMXML_QUALITY60_API eQualityActionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eQualityActionEnum( const char* Type );
     
	//! Constructor
	eQualityActionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eQualityActionEnum( );
     
	//! Destructor 
	virtual ~eQualityActionEnum( );
     
	//! Assign from 'Type'
	const eQualityActionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eQualityActionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare QualityActionEnum
	friend plmxml_api::logical PLMXML_QUALITY60_API operator==( const eQualityActionEnum& e1, const eQualityActionEnum& e2 );
     
	//! Compare QualityActionEnum
	friend plmxml_api::logical PLMXML_QUALITY60_API operator!=( const eQualityActionEnum& e1, const eQualityActionEnum& e2 );
};
extern PLMXML_QUALITY60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumQualityActionEnum;
extern PLMXML_QUALITY60_API eQualityActionEnum eQualityActionEnumUnset;
extern PLMXML_QUALITY60_API eQualityActionEnum eQualityActionEnumGeneral;
extern PLMXML_QUALITY60_API eQualityActionEnum eQualityActionEnumControlPlan;
extern PLMXML_QUALITY60_API eQualityActionEnum eQualityActionEnumFailureModeEffectsAnalysis;
extern PLMXML_QUALITY60_API eQualityActionEnum eQualityActionEnumProgram;
extern PLMXML_QUALITY60_API eQualityActionEnum eQualityActionEnumDimension8;

////////////////////////////////////////////////////////////////////////////////////
//! eQualityActionStatusEnum class
/*!
Allowed Values:
\verbatim
  eQualityActionStatusEnumCompleted
	"completed"
  eQualityActionStatusEnumConfirmed
	"confirmed"
  eQualityActionStatusEnumActive
	"active"
  eQualityActionStatusEnumDraft
	"draft"
  eQualityActionStatusEnumCancelled
	"cancelled"
  eQualityActionStatusEnumTemplate
	"template"
  
\endverbatim
*/
class PLMXML_QUALITY60_API eQualityActionStatusEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eQualityActionStatusEnum( const char* Type );
     
	//! Constructor
	eQualityActionStatusEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eQualityActionStatusEnum( );
     
	//! Destructor 
	virtual ~eQualityActionStatusEnum( );
     
	//! Assign from 'Type'
	const eQualityActionStatusEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eQualityActionStatusEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare QualityActionStatusEnum
	friend plmxml_api::logical PLMXML_QUALITY60_API operator==( const eQualityActionStatusEnum& e1, const eQualityActionStatusEnum& e2 );
     
	//! Compare QualityActionStatusEnum
	friend plmxml_api::logical PLMXML_QUALITY60_API operator!=( const eQualityActionStatusEnum& e1, const eQualityActionStatusEnum& e2 );
};
extern PLMXML_QUALITY60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumQualityActionStatusEnum;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumUnset;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumCompleted;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumConfirmed;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumActive;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumDraft;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumCancelled;
extern PLMXML_QUALITY60_API eQualityActionStatusEnum eQualityActionStatusEnumTemplate;

////////////////////////////////////////////////////////////////////////////////////
//! eCharacteristicsEnum class
/*!
Allowed Values:
\verbatim
  eCharacteristicsEnumAttributive
	"attributive"
  eCharacteristicsEnumVisual
	"visual"
  eCharacteristicsEnumVariable
	"variable"
  
\endverbatim
*/
class PLMXML_QUALITY60_API eCharacteristicsEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCharacteristicsEnum( const char* Type );
     
	//! Constructor
	eCharacteristicsEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCharacteristicsEnum( );
     
	//! Destructor 
	virtual ~eCharacteristicsEnum( );
     
	//! Assign from 'Type'
	const eCharacteristicsEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCharacteristicsEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CharacteristicsEnum
	friend plmxml_api::logical PLMXML_QUALITY60_API operator==( const eCharacteristicsEnum& e1, const eCharacteristicsEnum& e2 );
     
	//! Compare CharacteristicsEnum
	friend plmxml_api::logical PLMXML_QUALITY60_API operator!=( const eCharacteristicsEnum& e1, const eCharacteristicsEnum& e2 );
};
extern PLMXML_QUALITY60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCharacteristicsEnum;
extern PLMXML_QUALITY60_API eCharacteristicsEnum eCharacteristicsEnumUnset;
extern PLMXML_QUALITY60_API eCharacteristicsEnum eCharacteristicsEnumAttributive;
extern PLMXML_QUALITY60_API eCharacteristicsEnum eCharacteristicsEnumVisual;
extern PLMXML_QUALITY60_API eCharacteristicsEnum eCharacteristicsEnumVariable;

////////////////////////////////////////////////////////////////////////////////////
//! CharacteristicsGroup class
/*!
\verbatim

      CharacteristicsGroup.

      Attributes:

      characteristicsType: The type of the collection of similar characteristics
                        specifications under this CharacteristicsGroup.
      actionRefs:       References the QualityActions to mitigate the potential
                        failures related to this CharacteristicsGroup.
      failureRefs:      References the potential failures associated with this
                        CharacteristicsGroup.
      specificationRefs: References a list of all the characteristics
                        specifications related to this CharacteristicsGroup.
      
\endverbatim
*/
class PLMXML_QUALITY60_API CharacteristicsGroup : public Managed
{
public:
     
    //! Default constructor
    CharacteristicsGroup( );
     
    //! Constructs a CharacteristicsGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CharacteristicsGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CharacteristicsGroup();

private:

	//! Assignment operator
	CharacteristicsGroup& operator=( const CharacteristicsGroup& iSrc );

	//! Copy constructor
	CharacteristicsGroup( const CharacteristicsGroup& original );
     
public:

	//! Get number of URIs in Action
	int NumberOfActionURIs() const;

	//! Get i'th URI in Action
	plmxml_api::String GetActionURI( int i ) const;

	//! Add a URI to Action array. Call ResolveActionURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActionURI( const plmxml_api::String& u );

	//! Set i'th URI in Action array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActionURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Action URI. Does not resolve the URI.
	plmxml_api::Result GetActionURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Action array.
	plmxml_api::Result AddActionURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Action array to point to 'handle'.
	plmxml_api::Result SetActionURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Action points to.
	plmxml_api::Result ResolveActionURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Action array.
	plmxml_api::Result DeleteActionURI( int i );

	//! Remove all URIs from Action array.
	plmxml_api::Result DeleteActionURIs( );
	
	//! Check if Action is set
	plmxml_api::logical HasActionURIs( ) const;

	//! Set CharacteristicsType
	plmxml_api::Result SetCharacteristicsType( const eCharacteristicsEnum& arg );

	//! Get CharacteristicsType
	eCharacteristicsEnum GetCharacteristicsType() const;

	//! Get number of URIs in Specification
	int NumberOfSpecificationURIs() const;

	//! Get i'th URI in Specification
	plmxml_api::String GetSpecificationURI( int i ) const;

	//! Add a URI to Specification array. Call ResolveSpecificationURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSpecificationURI( const plmxml_api::String& u );

	//! Set i'th URI in Specification array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSpecificationURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Specification URI. Does not resolve the URI.
	plmxml_api::Result GetSpecificationURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Specification array.
	plmxml_api::Result AddSpecificationURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Specification array to point to 'handle'.
	plmxml_api::Result SetSpecificationURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Specification points to.
	plmxml_api::Result ResolveSpecificationURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Specification array.
	plmxml_api::Result DeleteSpecificationURI( int i );

	//! Remove all URIs from Specification array.
	plmxml_api::Result DeleteSpecificationURIs( );
	
	//! Check if Specification is set
	plmxml_api::logical HasSpecificationURIs( ) const;

	//! Get number of URIs in Failure
	int NumberOfFailureURIs() const;

	//! Get i'th URI in Failure
	plmxml_api::String GetFailureURI( int i ) const;

	//! Add a URI to Failure array. Call ResolveFailureURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddFailureURI( const plmxml_api::String& u );

	//! Set i'th URI in Failure array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetFailureURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Failure URI. Does not resolve the URI.
	plmxml_api::Result GetFailureURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Failure array.
	plmxml_api::Result AddFailureURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Failure array to point to 'handle'.
	plmxml_api::Result SetFailureURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Failure points to.
	plmxml_api::Result ResolveFailureURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Failure array.
	plmxml_api::Result DeleteFailureURI( int i );

	//! Remove all URIs from Failure array.
	plmxml_api::Result DeleteFailureURIs( );
	
	//! Check if Failure is set
	plmxml_api::logical HasFailureURIs( ) const;

     // <PLMXML_UserCode type="functionHeaderCharacteristicsGroup" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_QUALITY60_API plmxml_api::plmxmlClass plmxmlClassCharacteristicsGroup;


////////////////////////////////////////////////////////////////////////////////////
//! MasterQualityObject class
/*!
\verbatim

      MasterQualityObject.

      Attributes:

      basedOnId:        Version information for the based-on objects.
      latest:           Whether the the given specification or failure object is
                        the latest.
      active:           Whether this MasterQualityObject is active.
      basedOnSpecificationRefs: References a list of all the versioned
                        characteristics specifications based on the given
                        specification.
      
\endverbatim
*/
class PLMXML_QUALITY60_API MasterQualityObject : public Managed
{
public:
     
    //! Default constructor
    MasterQualityObject( );
     
    //! Constructs a MasterQualityObject with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MasterQualityObject( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MasterQualityObject();

private:

	//! Assignment operator
	MasterQualityObject& operator=( const MasterQualityObject& iSrc );

	//! Copy constructor
	MasterQualityObject( const MasterQualityObject& original );
     
public:

	//! Set Latest
	plmxml_api::Result SetLatest( plmxml_api::logical arg );

	//! Get Latest
	plmxml_api::logical GetLatest() const;

	//! Check if Latest is set
	plmxml_api::logical HasLatest() const;

	//! Unset Latest
	plmxml_api::Result UnsetLatest();

	//! Set Active
	plmxml_api::Result SetActive( plmxml_api::logical arg );

	//! Get Active
	plmxml_api::logical GetActive() const;

	//! Check if Active is set
	plmxml_api::logical HasActive() const;

	//! Unset Active
	plmxml_api::Result UnsetActive();

	//! Set BasedOnId
	plmxml_api::Result SetBasedOnId( int arg );
     
	//! Get BasedOnId
	int GetBasedOnId() const;
     
	//! Check if BasedOnId is set
	plmxml_api::logical HasBasedOnId() const;
     
	//! Unset BasedOnId
	plmxml_api::Result UnsetBasedOnId();

	//! Get number of URIs in BasedOnSpecification
	int NumberOfBasedOnSpecificationURIs() const;

	//! Get i'th URI in BasedOnSpecification
	plmxml_api::String GetBasedOnSpecificationURI( int i ) const;

	//! Add a URI to BasedOnSpecification array. Call ResolveBasedOnSpecificationURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddBasedOnSpecificationURI( const plmxml_api::String& u );

	//! Set i'th URI in BasedOnSpecification array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetBasedOnSpecificationURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of BasedOnSpecification URI. Does not resolve the URI.
	plmxml_api::Result GetBasedOnSpecificationURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to BasedOnSpecification array.
	plmxml_api::Result AddBasedOnSpecificationURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in BasedOnSpecification array to point to 'handle'.
	plmxml_api::Result SetBasedOnSpecificationURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in BasedOnSpecification points to.
	plmxml_api::Result ResolveBasedOnSpecificationURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from BasedOnSpecification array.
	plmxml_api::Result DeleteBasedOnSpecificationURI( int i );

	//! Remove all URIs from BasedOnSpecification array.
	plmxml_api::Result DeleteBasedOnSpecificationURIs( );
	
	//! Check if BasedOnSpecification is set
	plmxml_api::logical HasBasedOnSpecificationURIs( ) const;

     // <PLMXML_UserCode type="functionHeaderMasterQualityObject" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_QUALITY60_API plmxml_api::plmxmlClass plmxmlClassMasterQualityObject;


////////////////////////////////////////////////////////////////////////////////////
//! QualityAction class
/*!
\verbatim

      QualityAction.

      Attributes:

      actionItemId:     Object identifier.
      qualityActionStatus: The qualitative, rather than chronological, status of
                        this QualityAction.
      qualityActionType: The type of this QualityAction to categorize and
                        differentiate between different QualityAction types.
      qualityActionSubType: The sub-type of this QualityAction to categorize and
                        differentiate between different QualityAction sub-types.
      
\endverbatim
*/
class PLMXML_QUALITY60_API QualityAction : public Managed
{
public:
     
    //! Default constructor
    QualityAction( );
     
    //! Constructs a QualityAction with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    QualityAction( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~QualityAction();

private:

	//! Assignment operator
	QualityAction& operator=( const QualityAction& iSrc );

	//! Copy constructor
	QualityAction( const QualityAction& original );
     
public:

	//! Set QualityActionSubType
	plmxml_api::Result SetQualityActionSubType( const eQualityActionEnum& arg );

	//! Get QualityActionSubType
	eQualityActionEnum GetQualityActionSubType() const;

	//! Get ActionItemId of this QualityAction
	plmxml_api::String GetActionItemId() const;

	//! Set ActionItemId of this QualityAction
	plmxml_api::Result SetActionItemId( const plmxml_api::String &s );
	
	//! Check if ActionItemId is set
	plmxml_api::logical HasActionItemId( ) const;
	
	//! Unset ActionItemId
	plmxml_api::Result UnsetActionItemId( );

	//! Set QualityActionStatus
	plmxml_api::Result SetQualityActionStatus( const eQualityActionStatusEnum& arg );

	//! Get QualityActionStatus
	eQualityActionStatusEnum GetQualityActionStatus() const;

	//! Set QualityActionType
	plmxml_api::Result SetQualityActionType( const eQualityActionEnum& arg );

	//! Get QualityActionType
	eQualityActionEnum GetQualityActionType() const;

     // <PLMXML_UserCode type="functionHeaderQualityAction" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_QUALITY60_API plmxml_api::plmxmlClass plmxmlClassQualityAction;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
