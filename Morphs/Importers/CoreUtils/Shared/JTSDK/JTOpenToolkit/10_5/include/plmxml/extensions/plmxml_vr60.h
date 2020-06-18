/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.18109 17/12/2010 10:06:01
// 
// Schema:	PLMXMLValidationRuleSchema.xsd
// Data:	2010-11-05
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_VR60_H__
#define __PLMXML_VR60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_VR60_EXPORTS
#define PLMXML_VR60_API __declspec(dllexport)
#else
#define PLMXML_VR60_API __declspec(dllimport)
#endif
#else
#define PLMXML_VR60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>

#include <plmxml60.h>

// <PLMXML_UserCode type="includeHeader" >
// TODO: Add extra include headers within this block
// </PLMXML_UserCode>


PLMXML_BEGIN_NAMESPACE( plmxml_rule60 )

/////////////////////////////////////////////////////////////////////////

// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>


//! Forward class declarations
using plmxml60::AttribOwner;

////////////////////////////////////////////////////////////////////////////////////
//! ValidationRuleSet class
/*!
\verbatim

      A rule set references multiple validation rules.

      Attributes:

      ruleRefs:         References multiple ValidationRule objects.
      
\endverbatim
*/
class PLMXML_VR60_API ValidationRuleSet : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    ValidationRuleSet( );
     
    //! Constructs a ValidationRuleSet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationRuleSet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationRuleSet();

private:

	//! Assignment operator
	ValidationRuleSet& operator=( const ValidationRuleSet& iSrc );

	//! Copy constructor
	ValidationRuleSet( const ValidationRuleSet& original );
     
public:

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

     // <PLMXML_UserCode type="functionHeaderValidationRuleSet" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_VR60_API plmxml_api::plmxmlClass plmxmlClassValidationRuleSet;


//! Forward class declarations
using plmxml60::AttribOwner;
class Target;

////////////////////////////////////////////////////////////////////////////////////
//! ValidationRule class
/*!
\verbatim

      A rule specifies:
        The types of validation checkers to choose and the results to expect,
        and
        When the rule needs to be applied, and
        The type of objects as the target of validation.

      A rule can be used to define the methods and moments how to find targets
      for validation, or find appropriate checkers, or control the validation
      results to be used, or control the relations between the targets, checkers
      and results.

      Attributes:

      name:             Inherited from AttribOwner. The name of this rule.
      checker:          The checker name. It supports wildcards.
      checkerVersion:   The checker version.
      mandated:         Indicates if the test result for this checker must be
                        pass or not.
                          True: Requires the checker to run and pass.
                          False: Requires the checker to run but the result is
                          ignored.
      eventRefs:        References an array of ValidationEvent objects as
                        conditions for this rule.
      parameterRefs:    References an array of CheckerParameter objects as
                        parameter name, value pairs for the checker defined by
                        this rule. Refer to the PLMXMLPDMSchema.xsd for the
                        details about the CheckerParameterType.

      Sub-elements:

      Target:           A Target type element, which defines the object types to
                        be checked by this rule.
      
\endverbatim
*/
class PLMXML_VR60_API ValidationRule : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    ValidationRule( );
     
    //! Constructs a ValidationRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationRule();

private:

	//! Assignment operator
	ValidationRule& operator=( const ValidationRule& iSrc );

	//! Copy constructor
	ValidationRule( const ValidationRule& original );
     
public:

	//! Get CheckerVersion of this ValidationRule
	plmxml_api::String GetCheckerVersion() const;

	//! Set CheckerVersion of this ValidationRule
	plmxml_api::Result SetCheckerVersion( const plmxml_api::String &s );
	
	//! Check if CheckerVersion is set
	plmxml_api::logical HasCheckerVersion( ) const;
	
	//! Unset CheckerVersion
	plmxml_api::Result UnsetCheckerVersion( );

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

	//! Get number of URIs in Event
	int NumberOfEventURIs() const;

	//! Get i'th URI in Event
	plmxml_api::String GetEventURI( int i ) const;

	//! Add a URI to Event array. Call ResolveEventURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddEventURI( const plmxml_api::String& u );

	//! Set i'th URI in Event array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetEventURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Event URI. Does not resolve the URI.
	plmxml_api::Result GetEventURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Event array.
	plmxml_api::Result AddEventURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Event array to point to 'handle'.
	plmxml_api::Result SetEventURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Event points to.
	plmxml_api::Result ResolveEventURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Event array.
	plmxml_api::Result DeleteEventURI( int i );

	//! Remove all URIs from Event array.
	plmxml_api::Result DeleteEventURIs( );
	
	//! Check if Event is set
	plmxml_api::logical HasEventURIs( ) const;

	//! Set Mandated
	plmxml_api::Result SetMandated( plmxml_api::logical arg );

	//! Get Mandated
	plmxml_api::logical GetMandated() const;

	//! Check if Mandated is set
	plmxml_api::logical HasMandated() const;

	//! Unset Mandated
	plmxml_api::Result UnsetMandated();

	//! Get Checker of this ValidationRule
	plmxml_api::String GetChecker() const;

	//! Set Checker of this ValidationRule
	plmxml_api::Result SetChecker( const plmxml_api::String &s );
	
	//! Check if Checker is set
	plmxml_api::logical HasChecker( ) const;
	
	//! Unset Checker
	plmxml_api::Result UnsetChecker( );

	//! Add Target child element to this ValidationRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Target *AddTarget();
     
	//! Set Target child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTarget( Target *arg );
     
	//! Get Target child element of this ValidationRule.
	Target *GetTarget() const;
     
	//! Detach and delete Target child element tree from this ValidationRule.
	void DeleteTarget();

     // <PLMXML_UserCode type="functionHeaderValidationRule" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_VR60_API plmxml_api::plmxmlClass plmxmlClassValidationRule;


//! Forward class declarations
using plmxml60::AttribOwner;

////////////////////////////////////////////////////////////////////////////////////
//! ValidationEvent class
/*!
\verbatim

      An event defines a situation in which a rule should be selected or
      deselected when the rule is applied to a set of objects.

      Attributes:

      exclude:          Indicates whether the ValidationRule will be selected by
                        this event or not.
                          True: The rule will be selected if the event value is
                          evaluated as pass.
                          False: The rule will be deselected if the event value
                          is evaluated as pass.
      eventClass:       The event class clause for Teamcenter. Given the class
                        clause, it is able to get its values from the Teamcenter
                        database, then the values will be used to match with the
                        criterion. For example, ITEMREVISION:owning_group.
      applyTo:          The event clause for other applications. Given the
                        clause, it is able to get values from application
                        system, then the values will be used to match with the
                        criterion. For example, in NX, the clause could be
                        PARTATTRIBUTES:MQC_CHECK, which means to get the
                        "MQC_CHECK" attribute value from NX system.
      application:      Indicates the application this event will be used for.
                        For example, PLM means Teamcenter, NX means NX.

      Sub-Elements:

      ValueList:        Defines the criterion values for this event. It supports
                        wildcards.
      
\endverbatim
*/
class PLMXML_VR60_API ValidationEvent : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    ValidationEvent( );
     
    //! Constructs a ValidationEvent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ValidationEvent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ValidationEvent();

private:

	//! Assignment operator
	ValidationEvent& operator=( const ValidationEvent& iSrc );

	//! Copy constructor
	ValidationEvent( const ValidationEvent& original );
     
public:

	//! Get ApplyTo of this ValidationEvent
	plmxml_api::String GetApplyTo() const;

	//! Set ApplyTo of this ValidationEvent
	plmxml_api::Result SetApplyTo( const plmxml_api::String &s );
	
	//! Check if ApplyTo is set
	plmxml_api::logical HasApplyTo( ) const;
	
	//! Unset ApplyTo
	plmxml_api::Result UnsetApplyTo( );

	//! Get EventClass of this ValidationEvent
	plmxml_api::String GetEventClass() const;

	//! Set EventClass of this ValidationEvent
	plmxml_api::Result SetEventClass( const plmxml_api::String &s );
	
	//! Check if EventClass is set
	plmxml_api::logical HasEventClass( ) const;
	
	//! Unset EventClass
	plmxml_api::Result UnsetEventClass( );

	//! Get Application of this ValidationEvent
	plmxml_api::String GetApplication() const;

	//! Set Application of this ValidationEvent
	plmxml_api::Result SetApplication( const plmxml_api::String &s );
	
	//! Check if Application is set
	plmxml_api::logical HasApplication( ) const;
	
	//! Unset Application
	plmxml_api::Result UnsetApplication( );

	//! Set Exclude
	plmxml_api::Result SetExclude( plmxml_api::logical arg );

	//! Get Exclude
	plmxml_api::logical GetExclude() const;

	//! Check if Exclude is set
	plmxml_api::logical HasExclude() const;

	//! Unset Exclude
	plmxml_api::Result UnsetExclude();

	//! Add ValueList child element to this ValidationEvent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserList *AddValueList();
     
	//! Set ValueList child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueList( plmxml60::UserList *arg );
     
	//! Get ValueList child element of this ValidationEvent.
	plmxml60::UserList *GetValueList() const;
     
	//! Detach and delete ValueList child element tree from this ValidationEvent.
	void DeleteValueList();

     // <PLMXML_UserCode type="functionHeaderValidationEvent" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_VR60_API plmxml_api::plmxmlClass plmxmlClassValidationEvent;


//! Forward class declarations
using plmxml60::UserList;

////////////////////////////////////////////////////////////////////////////////////
//! Target class
/*!
\verbatim

      A target specifies the type of objects to be checked.

      Attributes:

      targetType:       The target type, for instance, Dataset.

      Sub-Elements:

      Item:             Inherited from UserListDataType. Represents the target
                        sub-types, like UGMaster, UGPart or Text et cetera. It
                        supports wildcards.
      
\endverbatim
*/
class PLMXML_VR60_API Target : public plmxml60::UserList
{
public:
     
    //! Default constructor
    Target( );
     
    //! Constructs a Target with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Target( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Target();

private:

	//! Assignment operator
	Target& operator=( const Target& iSrc );

	//! Copy constructor
	Target( const Target& original );
     
public:

	//! Get TargetType of this Target
	plmxml_api::String GetTargetType() const;

	//! Set TargetType of this Target
	plmxml_api::Result SetTargetType( const plmxml_api::String &s );
	
	//! Check if TargetType is set
	plmxml_api::logical HasTargetType( ) const;
	
	//! Unset TargetType
	plmxml_api::Result UnsetTargetType( );

     // <PLMXML_UserCode type="functionHeaderTarget" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_VR60_API plmxml_api::plmxmlClass plmxmlClassTarget;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
