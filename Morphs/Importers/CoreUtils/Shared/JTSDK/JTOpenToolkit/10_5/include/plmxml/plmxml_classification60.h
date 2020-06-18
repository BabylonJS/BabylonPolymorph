/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 14:17:09
// 
// Schema:	PLMXMLClassificationSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_CLASSIFICATION60_H__
#define __PLMXML_CLASSIFICATION60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_CLASSIFICATION60_EXPORTS
#define PLMXML_CLASSIFICATION60_API __declspec(dllexport)
#else
#define PLMXML_CLASSIFICATION60_API __declspec(dllimport)
#endif
#else
#define PLMXML_CLASSIFICATION60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


#include <plmxml_classification60.h>
#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
/*! \namespace plmxml_cl60
    \brief PLM XML SDK Classification schema specific API namespace.

    plmxml_cl60 namespace includes Classification schema specific auto-generated classes.
*/
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml_cl60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eCase class
/*!
Allowed Values:
\verbatim
  eCaseLower
	"lower"
  eCaseUpper
	"upper"
  eCaseMixed
	"mixed"
  
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API eCase : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCase( const char* Type );
     
	//! Constructor
	eCase( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCase( );
     
	//! Destructor 
	virtual ~eCase( );
     
	//! Assign from 'Type'
	const eCase& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCase& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Case
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator==( const eCase& e1, const eCase& e2 );
     
	//! Compare Case
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator!=( const eCase& e1, const eCase& e2 );
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCase;
extern PLMXML_CLASSIFICATION60_API eCase eCaseUnset;
extern PLMXML_CLASSIFICATION60_API eCase eCaseLower;
extern PLMXML_CLASSIFICATION60_API eCase eCaseUpper;
extern PLMXML_CLASSIFICATION60_API eCase eCaseMixed;

////////////////////////////////////////////////////////////////////////////////////
//! eAlign class
/*!
Allowed Values:
\verbatim
  eAlignLeft
	"left"
  eAlignRight
	"right"
  
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API eAlign : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAlign( const char* Type );
     
	//! Constructor
	eAlign( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAlign( );
     
	//! Destructor 
	virtual ~eAlign( );
     
	//! Assign from 'Type'
	const eAlign& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAlign& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Align
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator==( const eAlign& e1, const eAlign& e2 );
     
	//! Compare Align
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator!=( const eAlign& e1, const eAlign& e2 );
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAlign;
extern PLMXML_CLASSIFICATION60_API eAlign eAlignUnset;
extern PLMXML_CLASSIFICATION60_API eAlign eAlignLeft;
extern PLMXML_CLASSIFICATION60_API eAlign eAlignRight;

////////////////////////////////////////////////////////////////////////////////////
//! eUnitBaseType class
/*!
Allowed Values:
\verbatim
  eUnitBaseTypeMetric
	"metric"
  eUnitBaseTypeEnglish
	"english"
  eUnitBaseTypeInherited
	"inherited"
  eUnitBaseTypeBoth
	"both"
  
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API eUnitBaseType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eUnitBaseType( const char* Type );
     
	//! Constructor
	eUnitBaseType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eUnitBaseType( );
     
	//! Destructor 
	virtual ~eUnitBaseType( );
     
	//! Assign from 'Type'
	const eUnitBaseType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eUnitBaseType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare UnitBaseType
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator==( const eUnitBaseType& e1, const eUnitBaseType& e2 );
     
	//! Compare UnitBaseType
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator!=( const eUnitBaseType& e1, const eUnitBaseType& e2 );
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumUnitBaseType;
extern PLMXML_CLASSIFICATION60_API eUnitBaseType eUnitBaseTypeUnset;
extern PLMXML_CLASSIFICATION60_API eUnitBaseType eUnitBaseTypeMetric;
extern PLMXML_CLASSIFICATION60_API eUnitBaseType eUnitBaseTypeEnglish;
extern PLMXML_CLASSIFICATION60_API eUnitBaseType eUnitBaseTypeInherited;
extern PLMXML_CLASSIFICATION60_API eUnitBaseType eUnitBaseTypeBoth;

////////////////////////////////////////////////////////////////////////////////////
//! eType class
/*!
Allowed Values:
\verbatim
  eTypeDefault
	"default"
  eTypeUser
	"user"
  eTypeGroup
	"group"
  eTypeSubclass
	"subclass"
  
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API eType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eType( const char* Type );
     
	//! Constructor
	eType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eType( );
     
	//! Destructor 
	virtual ~eType( );
     
	//! Assign from 'Type'
	const eType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Type
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator==( const eType& e1, const eType& e2 );
     
	//! Compare Type
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator!=( const eType& e1, const eType& e2 );
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumType;
extern PLMXML_CLASSIFICATION60_API eType eTypeUnset;
extern PLMXML_CLASSIFICATION60_API eType eTypeDefault;
extern PLMXML_CLASSIFICATION60_API eType eTypeUser;
extern PLMXML_CLASSIFICATION60_API eType eTypeGroup;
extern PLMXML_CLASSIFICATION60_API eType eTypeSubclass;

////////////////////////////////////////////////////////////////////////////////////
//! eKeyLOVOptionsEnumType class
/*!
Allowed Values:
\verbatim
  eKeyLOVOptionsEnumTypeExclusive
	"Exclusive"
  eKeyLOVOptionsEnumTypeOptional
	"Optional"
  
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API eKeyLOVOptionsEnumType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eKeyLOVOptionsEnumType( const char* Type );
     
	//! Constructor
	eKeyLOVOptionsEnumType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eKeyLOVOptionsEnumType( );
     
	//! Destructor 
	virtual ~eKeyLOVOptionsEnumType( );
     
	//! Assign from 'Type'
	const eKeyLOVOptionsEnumType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eKeyLOVOptionsEnumType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare KeyLOVOptionsEnumType
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator==( const eKeyLOVOptionsEnumType& e1, const eKeyLOVOptionsEnumType& e2 );
     
	//! Compare KeyLOVOptionsEnumType
	friend plmxml_api::logical PLMXML_CLASSIFICATION60_API operator!=( const eKeyLOVOptionsEnumType& e1, const eKeyLOVOptionsEnumType& e2 );
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumKeyLOVOptionsEnumType;
extern PLMXML_CLASSIFICATION60_API eKeyLOVOptionsEnumType eKeyLOVOptionsEnumTypeUnset;
extern PLMXML_CLASSIFICATION60_API eKeyLOVOptionsEnumType eKeyLOVOptionsEnumTypeExclusive;
extern PLMXML_CLASSIFICATION60_API eKeyLOVOptionsEnumType eKeyLOVOptionsEnumTypeOptional;

////////////////////////////////////////////////////////////////////////////////////
//! LanguageString class
/*!
\verbatim

      This is the base type for all Types which are used for String values which
      might appear in different Languages.

      Attributes:

      isMaster:         Whether the language is the master language.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API LanguageString : public plmxml_api::Object
{
public:
     
    //! Default constructor
    LanguageString( );
     
    //! Constructs a LanguageString with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LanguageString( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LanguageString();

private:

	//! Assignment operator
	LanguageString& operator=( const LanguageString& iSrc );

	//! Copy constructor
	LanguageString( const LanguageString& original );
     
public:

	//! Get Language of this LanguageString
	plmxml_api::String GetLanguage() const;

	//! Set Language of this LanguageString
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Set IsMaster
	plmxml_api::Result SetIsMaster( plmxml_api::logical arg );

	//! Get IsMaster
	plmxml_api::logical GetIsMaster() const;

	//! Check if IsMaster is set
	plmxml_api::logical HasIsMaster() const;

	//! Unset IsMaster
	plmxml_api::Result UnsetIsMaster();
 
// <PLMXML_UserCode type="functionHeaderLanguageString" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassLanguageString;


////////////////////////////////////////////////////////////////////////////////////
//! Value class
/*!
\verbatim

      Represents the value of an AdminViewAttribute or an Attribute sub-element
      of an AdminClass or UserClass.

      Attributes:

      isFixed:          When ValueType is used to represent a default value,
                        isFixed indicates whether the value can be overridden.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Value : public LanguageString
{
public:
     
    //! Default constructor
    Value( );
     
    //! Constructs a Value with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Value( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Value();

private:

	//! Assignment operator
	Value& operator=( const Value& iSrc );

	//! Copy constructor
	Value( const Value& original );
     
public:

	//! Set IsFixed
	plmxml_api::Result SetIsFixed( plmxml_api::logical arg );

	//! Get IsFixed
	plmxml_api::logical GetIsFixed() const;

	//! Check if IsFixed is set
	plmxml_api::logical HasIsFixed() const;

	//! Unset IsFixed
	plmxml_api::Result UnsetIsFixed();
 
// <PLMXML_UserCode type="functionHeaderValue" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassValue;


////////////////////////////////////////////////////////////////////////////////////
//! Name class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Name : public LanguageString
{
public:
     
    //! Default constructor
    Name( );
     
    //! Constructs a Name with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Name( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Name();

private:

	//! Assignment operator
	Name& operator=( const Name& iSrc );

	//! Copy constructor
	Name( const Name& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderName" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassName;


////////////////////////////////////////////////////////////////////////////////////
//! ShortName class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API ShortName : public LanguageString
{
public:
     
    //! Default constructor
    ShortName( );
     
    //! Constructs a ShortName with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ShortName( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ShortName();

private:

	//! Assignment operator
	ShortName& operator=( const ShortName& iSrc );

	//! Copy constructor
	ShortName( const ShortName& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderShortName" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassShortName;


////////////////////////////////////////////////////////////////////////////////////
//! UserData class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API UserData : public LanguageString
{
public:
     
    //! Default constructor
    UserData( );
     
    //! Constructs a UserData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UserData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UserData();

private:

	//! Assignment operator
	UserData& operator=( const UserData& iSrc );

	//! Copy constructor
	UserData( const UserData& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderUserData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassUserData;


////////////////////////////////////////////////////////////////////////////////////
//! Description class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Description : public LanguageString
{
public:
     
    //! Default constructor
    Description( );
     
    //! Constructs a Description with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Description( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Description();

private:

	//! Assignment operator
	Description& operator=( const Description& iSrc );

	//! Copy constructor
	Description( const Description& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDescription" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassDescription;


////////////////////////////////////////////////////////////////////////////////////
//! Comment class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Comment : public LanguageString
{
public:
     
    //! Default constructor
    Comment( );
     
    //! Constructs a Comment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Comment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Comment();

private:

	//! Assignment operator
	Comment& operator=( const Comment& iSrc );

	//! Copy constructor
	Comment( const Comment& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderComment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassComment;


////////////////////////////////////////////////////////////////////////////////////
//! Annotation class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Annotation : public LanguageString
{
public:
     
    //! Default constructor
    Annotation( );
     
    //! Constructs a Annotation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Annotation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Annotation();

private:

	//! Assignment operator
	Annotation& operator=( const Annotation& iSrc );

	//! Copy constructor
	Annotation( const Annotation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderAnnotation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAnnotation;


////////////////////////////////////////////////////////////////////////////////////
//! GeneralOption class
/*!
\verbatim

      This type is intended to serve as a flexible extension mechanism to the existing explicit elements and attributes of any main type
      
      Attributes:
      
      optionType:   allows to define a type for the option like pre or post option
      name:         the name of the option
      language:     the language of the value
      value:        the value of the option
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API GeneralOption : public plmxml_api::Object
{
public:
     
    //! Default constructor
    GeneralOption( );
     
    //! Constructs a GeneralOption with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GeneralOption( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GeneralOption();

private:

	//! Assignment operator
	GeneralOption& operator=( const GeneralOption& iSrc );

	//! Copy constructor
	GeneralOption( const GeneralOption& original );
     
public:

	//! Get Value of this GeneralOption
	plmxml_api::String GetValue() const;

	//! Set Value of this GeneralOption
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Get Name of this GeneralOption
	plmxml_api::String GetName() const;

	//! Set Name of this GeneralOption
	plmxml_api::Result SetName( const plmxml_api::String &s );
	
	//! Check if Name is set
	plmxml_api::logical HasName( ) const;
	
	//! Unset Name
	plmxml_api::Result UnsetName( );

	//! Get Language of this GeneralOption
	plmxml_api::String GetLanguage() const;

	//! Set Language of this GeneralOption
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Get OptionType of this GeneralOption
	plmxml_api::String GetOptionType() const;

	//! Set OptionType of this GeneralOption
	plmxml_api::Result SetOptionType( const plmxml_api::String &s );
	
	//! Check if OptionType is set
	plmxml_api::logical HasOptionType( ) const;
	
	//! Unset OptionType
	plmxml_api::Result UnsetOptionType( );
 
// <PLMXML_UserCode type="functionHeaderGeneralOption" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassGeneralOption;


////////////////////////////////////////////////////////////////////////////////////
//! ReferenceSpecification class
/*!
\verbatim

      This element specifies how the value of an Attribute should be determined - from
      the classified element, a related element, or another ICO.
      
      Attributes:
      
      className:      The name of the class of the referenced element.
      attributeName:  The name of the referenced attribute.
      
      referenceType:  A string describing the type of reference. Defined values are
         classifiedObject - the reference is to an attribute of the classified object.
         relatedObject    - the reference is to an attribute of an object related to the 
                               classified object - the relation name is given by the "relationName"
                               attribute.
         ICOAttribute     - the reference is to another ICO, by icoId.
            
      relationName:   If referenceType is "relatedObject", this gives the name of the relation 
                      used to relate the classified object to the referenced object. 
                      
      useProduct:     If this is "true", and the classifiedObject is a ProductRevision, then the 
                      corresponding Product will be used instead. If, in addition, the referenceType 
                      is "relatedObject", then the relation will apply to the Product and the 
                      referenced element. 
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API ReferenceSpecification : public plmxml_api::Object
{
public:
     
    //! Default constructor
    ReferenceSpecification( );
     
    //! Constructs a ReferenceSpecification with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ReferenceSpecification( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ReferenceSpecification();

private:

	//! Assignment operator
	ReferenceSpecification& operator=( const ReferenceSpecification& iSrc );

	//! Copy constructor
	ReferenceSpecification( const ReferenceSpecification& original );
     
public:

	//! Get ReferenceType of this ReferenceSpecification
	plmxml_api::String GetReferenceType() const;

	//! Set ReferenceType of this ReferenceSpecification
	plmxml_api::Result SetReferenceType( const plmxml_api::String &s );
	
	//! Check if ReferenceType is set
	plmxml_api::logical HasReferenceType( ) const;
	
	//! Unset ReferenceType
	plmxml_api::Result UnsetReferenceType( );

	//! Set UseProduct
	plmxml_api::Result SetUseProduct( plmxml_api::logical arg );

	//! Get UseProduct
	plmxml_api::logical GetUseProduct() const;

	//! Check if UseProduct is set
	plmxml_api::logical HasUseProduct() const;

	//! Unset UseProduct
	plmxml_api::Result UnsetUseProduct();

	//! Get ClassName of this ReferenceSpecification
	plmxml_api::String GetClassName() const;

	//! Set ClassName of this ReferenceSpecification
	plmxml_api::Result SetClassName( const plmxml_api::String &s );
	
	//! Check if ClassName is set
	plmxml_api::logical HasClassName( ) const;
	
	//! Unset ClassName
	plmxml_api::Result UnsetClassName( );

	//! Get AttributeName of this ReferenceSpecification
	plmxml_api::String GetAttributeName() const;

	//! Set AttributeName of this ReferenceSpecification
	plmxml_api::Result SetAttributeName( const plmxml_api::String &s );
	
	//! Check if AttributeName is set
	plmxml_api::logical HasAttributeName( ) const;
	
	//! Unset AttributeName
	plmxml_api::Result UnsetAttributeName( );

	//! Get RelationName of this ReferenceSpecification
	plmxml_api::String GetRelationName() const;

	//! Set RelationName of this ReferenceSpecification
	plmxml_api::Result SetRelationName( const plmxml_api::String &s );
	
	//! Check if RelationName is set
	plmxml_api::logical HasRelationName( ) const;
	
	//! Unset RelationName
	plmxml_api::Result UnsetRelationName( );
 
// <PLMXML_UserCode type="functionHeaderReferenceSpecification" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassReferenceSpecification;


////////////////////////////////////////////////////////////////////////////////////
//! File class
/*!
\verbatim

      This extension of the ExternalFileType allows to define which role the document 
      will have like icon, image, etc.   
      
      Attributes:
      
      usage:             The attribute specified what the file is used for e.g. Icon, Image or 
                         PartFamilyTemplate. Which values are possible depends on the context 
                         where this type is used.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API File : public plmxml60::ExternalFile
{
public:
     
    //! Default constructor
    File( );
     
    //! Constructs a File with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    File( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~File();

private:

	//! Assignment operator
	File& operator=( const File& iSrc );

	//! Copy constructor
	File( const File& original );
     
public:

	//! Get Usage of this File
	plmxml_api::String GetUsage() const;

	//! Set Usage of this File
	plmxml_api::Result SetUsage( const plmxml_api::String &s );
	
	//! Check if Usage is set
	plmxml_api::logical HasUsage( ) const;
	
	//! Unset Usage
	plmxml_api::Result UnsetUsage( );

	//! Get Language of this File
	plmxml_api::String GetLanguage() const;

	//! Set Language of this File
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );
 
// <PLMXML_UserCode type="functionHeaderFile" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFile;


////////////////////////////////////////////////////////////////////////////////////
//! KeyLOVValue class
/*!
\verbatim

      Attributes:

      isDeprecated:   Whether the Value is deprecated.

      Elements:
      
      Key:               If a Key starts with a '#' it is used as configuration information 
                         ( e.g '#-' separator )
      Value:
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API KeyLOVValue : public plmxml_api::Object
{
public:
     
    //! Default constructor
    KeyLOVValue( );
     
    //! Constructs a KeyLOVValue with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    KeyLOVValue( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~KeyLOVValue();

private:

	//! Assignment operator
	KeyLOVValue& operator=( const KeyLOVValue& iSrc );

	//! Copy constructor
	KeyLOVValue( const KeyLOVValue& original );
     
public:

	//! Set IsDeprecated
	plmxml_api::Result SetIsDeprecated( plmxml_api::logical arg );

	//! Get IsDeprecated
	plmxml_api::logical GetIsDeprecated() const;

	//! Check if IsDeprecated is set
	plmxml_api::logical HasIsDeprecated() const;

	//! Unset IsDeprecated
	plmxml_api::Result UnsetIsDeprecated();

	//! Get Key of this KeyLOVValue
	plmxml_api::String GetKey() const;

	//! Set Key of this KeyLOVValue
	plmxml_api::Result SetKey( const plmxml_api::String &s );
	
	//! Check if Key is set
	plmxml_api::logical HasKey( ) const;
	
	//! Unset Key
	plmxml_api::Result UnsetKey( );

	//! Add Value child element to this KeyLOVValue. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddValue();
     
	//! Add 'arg' as Value child element to this KeyLOVValue.
	plmxml_api::Result AddValue( Value *arg );

	//! Detach and delete all Value child elements.
	void DeleteValues();
     
	//! Get number of Value child elements.
	int NumberOfValues() const;
     
	//! Get i'th Value child element.
	Value *GetValue( int i ) const;
     
	//! Get all Value child element as an array
	void GetValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th Value child element
	void DeleteValue( int i );
     
	//! Detach and delete 'arg' if it's one of the Value child elements
	void DeleteValue( Value *arg );
 
// <PLMXML_UserCode type="functionHeaderKeyLOVValue" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassKeyLOVValue;


////////////////////////////////////////////////////////////////////////////////////
//! KeyLOV class
/*!
\verbatim

      The KeyLOV type defines a list of key - value pairs that are used 
      to specify the list of possible values for Classification attributes 

      Elements:
      
      Name:       an optional display name for the KeyLOV definition.
      Comment:    a general comment intended for the maintainer of the object
      GeneralOption: general options.
      Values:     the key - values pairs
        
      Attribute:
      
      keyLOVId:   The unique id of the KeyLOV object
      options:    keyLOV specific options
      hideKeys:   if true it indicates the application to hide the keys while displaying keyLOV values
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API KeyLOV : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    KeyLOV( );
     
    //! Constructs a KeyLOV with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    KeyLOV( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~KeyLOV();

private:

	//! Assignment operator
	KeyLOV& operator=( const KeyLOV& iSrc );

	//! Copy constructor
	KeyLOV( const KeyLOV& original );
     
public:

	//! Get ModifiedUser of this KeyLOV
	plmxml_api::String GetModifiedUser() const;

	//! Set ModifiedUser of this KeyLOV
	plmxml_api::Result SetModifiedUser( const plmxml_api::String &s );
	
	//! Check if ModifiedUser is set
	plmxml_api::logical HasModifiedUser( ) const;
	
	//! Unset ModifiedUser
	plmxml_api::Result UnsetModifiedUser( );

	//! Get ModifiedDate of this KeyLOV
	plmxml_api::String GetModifiedDate() const;

	//! Set ModifiedDate of this KeyLOV
	plmxml_api::Result SetModifiedDate( const plmxml_api::String &s );
	
	//! Check if ModifiedDate is set
	plmxml_api::logical HasModifiedDate( ) const;
	
	//! Unset ModifiedDate
	plmxml_api::Result UnsetModifiedDate( );

	//! Get CreationUser of this KeyLOV
	plmxml_api::String GetCreationUser() const;

	//! Set CreationUser of this KeyLOV
	plmxml_api::Result SetCreationUser( const plmxml_api::String &s );
	
	//! Check if CreationUser is set
	plmxml_api::logical HasCreationUser( ) const;
	
	//! Unset CreationUser
	plmxml_api::Result UnsetCreationUser( );

	//! Set HideKeys
	plmxml_api::Result SetHideKeys( plmxml_api::logical arg );

	//! Get HideKeys
	plmxml_api::logical GetHideKeys() const;

	//! Check if HideKeys is set
	plmxml_api::logical HasHideKeys() const;

	//! Unset HideKeys
	plmxml_api::Result UnsetHideKeys();

	//! Get CreationDate of this KeyLOV
	plmxml_api::String GetCreationDate() const;

	//! Set CreationDate of this KeyLOV
	plmxml_api::Result SetCreationDate( const plmxml_api::String &s );
	
	//! Check if CreationDate is set
	plmxml_api::logical HasCreationDate( ) const;
	
	//! Unset CreationDate
	plmxml_api::Result UnsetCreationDate( );

	//! Set Options
	plmxml_api::Result SetOptions( const eKeyLOVOptionsEnumType& arg );

	//! Get Options
	eKeyLOVOptionsEnumType GetOptions() const;

	//! Get KeyLOVId of this KeyLOV
	plmxml_api::String GetKeyLOVId() const;

	//! Set KeyLOVId of this KeyLOV
	plmxml_api::Result SetKeyLOVId( const plmxml_api::String &s );
	
	//! Check if KeyLOVId is set
	plmxml_api::logical HasKeyLOVId( ) const;
	
	//! Unset KeyLOVId
	plmxml_api::Result UnsetKeyLOVId( );

	//! Add Name child element to this KeyLOV. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Name *AddName();
     
	//! Add 'arg' as Name child element to this KeyLOV.
	plmxml_api::Result AddName( Name *arg );

	//! Detach and delete all Name child elements.
	void DeleteNames();
     
	//! Get number of Name child elements.
	int NumberOfNames() const;
     
	//! Get i'th Name child element.
	Name *GetName( int i ) const;
     
	//! Get all Name child element as an array
	void GetNames( plmxml_api::Array<Name*> &array ) const;
	     
	//! Detach and delete i'th Name child element
	void DeleteName( int i );
     
	//! Detach and delete 'arg' if it's one of the Name child elements
	void DeleteName( Name *arg );

	//! Add Comment child element to this KeyLOV. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Comment *AddComment();
     
	//! Add 'arg' as Comment child element to this KeyLOV.
	plmxml_api::Result AddComment( Comment *arg );

	//! Detach and delete all Comment child elements.
	void DeleteComments();
     
	//! Get number of Comment child elements.
	int NumberOfComments() const;
     
	//! Get i'th Comment child element.
	Comment *GetComment( int i ) const;
     
	//! Get all Comment child element as an array
	void GetComments( plmxml_api::Array<Comment*> &array ) const;
	     
	//! Detach and delete i'th Comment child element
	void DeleteComment( int i );
     
	//! Detach and delete 'arg' if it's one of the Comment child elements
	void DeleteComment( Comment *arg );

	//! Add GeneralOption child element to this KeyLOV. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GeneralOption *AddGeneralOption();
     
	//! Add 'arg' as GeneralOption child element to this KeyLOV.
	plmxml_api::Result AddGeneralOption( GeneralOption *arg );

	//! Detach and delete all GeneralOption child elements.
	void DeleteGeneralOptions();
     
	//! Get number of GeneralOption child elements.
	int NumberOfGeneralOptions() const;
     
	//! Get i'th GeneralOption child element.
	GeneralOption *GetGeneralOption( int i ) const;
     
	//! Get all GeneralOption child element as an array
	void GetGeneralOptions( plmxml_api::Array<GeneralOption*> &array ) const;
	     
	//! Detach and delete i'th GeneralOption child element
	void DeleteGeneralOption( int i );
     
	//! Detach and delete 'arg' if it's one of the GeneralOption child elements
	void DeleteGeneralOption( GeneralOption *arg );

	//! Add Values child element to this KeyLOV. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	KeyLOVValue *AddValues();
     
	//! Add 'arg' as Values child element to this KeyLOV.
	plmxml_api::Result AddValues( KeyLOVValue *arg );

	//! Detach and delete all Values child elements.
	void DeleteValues();
     
	//! Get number of Values child elements.
	int NumberOfValues() const;
     
	//! Get i'th Values child element.
	KeyLOVValue *GetValues( int i ) const;
     
	//! Get all Values child element as an array
	void GetValues( plmxml_api::Array<KeyLOVValue*> &array ) const;
	     
	//! Detach and delete i'th Values child element
	void DeleteValues( int i );
     
	//! Detach and delete 'arg' if it's one of the Values child elements
	void DeleteValues( KeyLOVValue *arg );
 
// <PLMXML_UserCode type="functionHeaderKeyLOV" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassKeyLOV;


////////////////////////////////////////////////////////////////////////////////////
//! FormatString class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API FormatString : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FormatString( );
     
    //! Constructs a FormatString with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatString( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatString();

private:

	//! Assignment operator
	FormatString& operator=( const FormatString& iSrc );

	//! Copy constructor
	FormatString( const FormatString& original );
     
public:

	//! Set Align
	plmxml_api::Result SetAlign( const eAlign& arg );

	//! Get Align
	eAlign GetAlign() const;

	//! Set Scale
	plmxml_api::Result SetScale( int arg );
     
	//! Get Scale
	int GetScale() const;
     
	//! Check if Scale is set
	plmxml_api::logical HasScale() const;
     
	//! Unset Scale
	plmxml_api::Result UnsetScale();

	//! Set Case
	plmxml_api::Result SetCase( const eCase& arg );

	//! Get Case
	eCase GetCase() const;
 
// <PLMXML_UserCode type="functionHeaderFormatString" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFormatString;


////////////////////////////////////////////////////////////////////////////////////
//! FormatInteger class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API FormatInteger : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FormatInteger( );
     
    //! Constructs a FormatInteger with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatInteger( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatInteger();

private:

	//! Assignment operator
	FormatInteger& operator=( const FormatInteger& iSrc );

	//! Copy constructor
	FormatInteger( const FormatInteger& original );
     
public:

	//! Set Scale
	plmxml_api::Result SetScale( int arg );
     
	//! Get Scale
	int GetScale() const;
     
	//! Check if Scale is set
	plmxml_api::logical HasScale() const;
     
	//! Unset Scale
	plmxml_api::Result UnsetScale();

	//! Set Sign
	plmxml_api::Result SetSign( int arg );
     
	//! Get Sign
	int GetSign() const;
     
	//! Check if Sign is set
	plmxml_api::logical HasSign() const;
     
	//! Unset Sign
	plmxml_api::Result UnsetSign();
 
// <PLMXML_UserCode type="functionHeaderFormatInteger" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFormatInteger;


////////////////////////////////////////////////////////////////////////////////////
//! FormatFloat class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API FormatFloat : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FormatFloat( );
     
    //! Constructs a FormatFloat with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatFloat( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatFloat();

private:

	//! Assignment operator
	FormatFloat& operator=( const FormatFloat& iSrc );

	//! Copy constructor
	FormatFloat( const FormatFloat& original );
     
public:

	//! Set Scale
	plmxml_api::Result SetScale( int arg );
     
	//! Get Scale
	int GetScale() const;
     
	//! Check if Scale is set
	plmxml_api::logical HasScale() const;
     
	//! Unset Scale
	plmxml_api::Result UnsetScale();

	//! Set Sign
	plmxml_api::Result SetSign( int arg );
     
	//! Get Sign
	int GetSign() const;
     
	//! Check if Sign is set
	plmxml_api::logical HasSign() const;
     
	//! Unset Sign
	plmxml_api::Result UnsetSign();

	//! Set Precision
	plmxml_api::Result SetPrecision( int arg );
     
	//! Get Precision
	int GetPrecision() const;
     
	//! Check if Precision is set
	plmxml_api::logical HasPrecision() const;
     
	//! Unset Precision
	plmxml_api::Result UnsetPrecision();
 
// <PLMXML_UserCode type="functionHeaderFormatFloat" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFormatFloat;


////////////////////////////////////////////////////////////////////////////////////
//! FormatKeyLov class
/*!
\verbatim

      Attributes:
      
      keyLOVId:
      ref2keyLOVRef:      Reference to the keyLOV definition
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API FormatKeyLov : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FormatKeyLov( );
     
    //! Constructs a FormatKeyLov with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatKeyLov( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatKeyLov();

private:

	//! Assignment operator
	FormatKeyLov& operator=( const FormatKeyLov& iSrc );

	//! Copy constructor
	FormatKeyLov( const FormatKeyLov& original );
     
public:

	//! Set reference to Ref2keyLOV using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRef2keyLOVRef( plmxml60::IdObject *arg );

	//! Clear reference to Ref2keyLOV
	void RemoveRef2keyLOVRef( );

	//! Find a plmxml60::IdObject referenced by Ref2keyLOV
	plmxml60::IdObject *ResolveRef2keyLOVRef( plmxml_api::Configuration* config = NULL );

	//! Get Ref2keyLOV reference
	plmxml_api::String GetRef2keyLOVId() const;

	//! Set Ref2keyLOV reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRef2keyLOVId( const plmxml_api::String& u );
	
	//! Check if Ref2keyLOV is set
	plmxml_api::logical HasRef2keyLOVRef( ) const;

	//! Set KeyLOVId
	plmxml_api::Result SetKeyLOVId( int arg );
     
	//! Get KeyLOVId
	int GetKeyLOVId() const;
     
	//! Check if KeyLOVId is set
	plmxml_api::logical HasKeyLOVId() const;
     
	//! Unset KeyLOVId
	plmxml_api::Result UnsetKeyLOVId();
 
// <PLMXML_UserCode type="functionHeaderFormatKeyLov" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFormatKeyLov;


////////////////////////////////////////////////////////////////////////////////////
//! FormatAdmin class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API FormatAdmin : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FormatAdmin( );
     
    //! Constructs a FormatAdmin with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatAdmin( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatAdmin();

private:

	//! Assignment operator
	FormatAdmin& operator=( const FormatAdmin& iSrc );

	//! Copy constructor
	FormatAdmin( const FormatAdmin& original );
     
public:

	//! Add FormatString child element to this FormatAdmin. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatString *AddFormatString();
     
	//! Set FormatString child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatString( FormatString *arg );
     
	//! Get FormatString child element of this FormatAdmin.
	FormatString *GetFormatString() const;
     
	//! Detach and delete FormatString child element tree from this FormatAdmin.
	void DeleteFormatString();

	//! Add FormatInteger child element to this FormatAdmin. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatInteger *AddFormatInteger();
     
	//! Set FormatInteger child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatInteger( FormatInteger *arg );
     
	//! Get FormatInteger child element of this FormatAdmin.
	FormatInteger *GetFormatInteger() const;
     
	//! Detach and delete FormatInteger child element tree from this FormatAdmin.
	void DeleteFormatInteger();

	//! Add FormatFloat child element to this FormatAdmin. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatFloat *AddFormatFloat();
     
	//! Set FormatFloat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatFloat( FormatFloat *arg );
     
	//! Get FormatFloat child element of this FormatAdmin.
	FormatFloat *GetFormatFloat() const;
     
	//! Detach and delete FormatFloat child element tree from this FormatAdmin.
	void DeleteFormatFloat();

	//! Get FormatDate of this FormatAdmin
	plmxml_api::String GetFormatDate() const;

	//! Set FormatDate of this FormatAdmin
	plmxml_api::Result SetFormatDate( const plmxml_api::String &s );
	
	//! Check if FormatDate is set
	plmxml_api::logical HasFormatDate( ) const;
	
	//! Unset FormatDate
	plmxml_api::Result UnsetFormatDate( );

	//! Add FormatKeyLov child element to this FormatAdmin. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatKeyLov *AddFormatKeyLov();
     
	//! Set FormatKeyLov child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatKeyLov( FormatKeyLov *arg );
     
	//! Get FormatKeyLov child element of this FormatAdmin.
	FormatKeyLov *GetFormatKeyLov() const;
     
	//! Detach and delete FormatKeyLov child element tree from this FormatAdmin.
	void DeleteFormatKeyLov();

	//! Get Unit of this FormatAdmin
	plmxml_api::String GetUnit() const;

	//! Set Unit of this FormatAdmin
	plmxml_api::Result SetUnit( const plmxml_api::String &s );
	
	//! Check if Unit is set
	plmxml_api::logical HasUnit( ) const;
	
	//! Unset Unit
	plmxml_api::Result UnsetUnit( );
 
// <PLMXML_UserCode type="functionHeaderFormatAdmin" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFormatAdmin;


////////////////////////////////////////////////////////////////////////////////////
//! FormatUser class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API FormatUser : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FormatUser( );
     
    //! Constructs a FormatUser with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatUser( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatUser();

private:

	//! Assignment operator
	FormatUser& operator=( const FormatUser& iSrc );

	//! Copy constructor
	FormatUser( const FormatUser& original );
     
public:

	//! Add FormatString child element to this FormatUser. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatString *AddFormatString();
     
	//! Set FormatString child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatString( FormatString *arg );
     
	//! Get FormatString child element of this FormatUser.
	FormatString *GetFormatString() const;
     
	//! Detach and delete FormatString child element tree from this FormatUser.
	void DeleteFormatString();

	//! Add FormatInteger child element to this FormatUser. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatInteger *AddFormatInteger();
     
	//! Set FormatInteger child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatInteger( FormatInteger *arg );
     
	//! Get FormatInteger child element of this FormatUser.
	FormatInteger *GetFormatInteger() const;
     
	//! Detach and delete FormatInteger child element tree from this FormatUser.
	void DeleteFormatInteger();

	//! Add FormatFloat child element to this FormatUser. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatFloat *AddFormatFloat();
     
	//! Set FormatFloat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormatFloat( FormatFloat *arg );
     
	//! Get FormatFloat child element of this FormatUser.
	FormatFloat *GetFormatFloat() const;
     
	//! Detach and delete FormatFloat child element tree from this FormatUser.
	void DeleteFormatFloat();

	//! Get FormatDate of this FormatUser
	plmxml_api::String GetFormatDate() const;

	//! Set FormatDate of this FormatUser
	plmxml_api::Result SetFormatDate( const plmxml_api::String &s );
	
	//! Check if FormatDate is set
	plmxml_api::logical HasFormatDate( ) const;
	
	//! Unset FormatDate
	plmxml_api::Result UnsetFormatDate( );

	//! Add KeyLOV child element to this FormatUser. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	KeyLOV *AddKeyLOV();
     
	//! Set KeyLOV child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetKeyLOV( KeyLOV *arg );
     
	//! Get KeyLOV child element of this FormatUser.
	KeyLOV *GetKeyLOV() const;
     
	//! Detach and delete KeyLOV child element tree from this FormatUser.
	void DeleteKeyLOV();

	//! Get Unit of this FormatUser
	plmxml_api::String GetUnit() const;

	//! Set Unit of this FormatUser
	plmxml_api::Result SetUnit( const plmxml_api::String &s );
	
	//! Check if Unit is set
	plmxml_api::logical HasUnit( ) const;
	
	//! Unset Unit
	plmxml_api::Result UnsetUnit( );
 
// <PLMXML_UserCode type="functionHeaderFormatUser" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassFormatUser;


////////////////////////////////////////////////////////////////////////////////////
//! DictionaryAttribute class
/*!
\verbatim

      Represents the global attribute definition referenced from the class attribute definition
      
      Attributes:
      
      attributeId:  The unique id of the attribute
      reference:          
      
      Elements:
      
      Name:              Display name of the Attribute
      ShortName:         Short version of the display name
      Annotation:        The annotation is used as a reference in a graphical representation
                         of the class where this attribute is used
      Format:            Defines the type of values for this attribute if used in metric unit
                         base classes
      AltFormat:         Defines the type of values for this attribute if used in english unit
                         base classes
      MinValue:          Defines the minimum Value in metric units for this
                         attribute. This is only suitable for attributes of type
                         integer or float.
      MaxValue:          Defines the maximum Value in metric units for this
                         attribute. This is only suitable for attributes of type
                         integer or float.
      DefaultValue:      The default value for instances of metric unit classes using this attribute. 
                         This value can be overwritten in the class attribute definition
      AltDefaultValue:   The default value for instances of english unit classes using this attribute. 
                         This value can be overwritten in the class attribute definition
      UserData1:         User specific data
      UserData2:         User specific data
      Description:       Provides a display description for this Attribute
      Comment:           A field to maintain comments intended for maintainer of the definition
      ReferenceSpecification:  Specifies how the value for this attribute is acquired
                               if used as reference attribute
      GeneralOption:     General Options for the attribute definition.
      AltMinValue:       Defines the minimum Value in English units for this
                         attribute. This is only suitable for attributes of type
                         integer or float.
      AltMaxValue:       Defines the maximum Value in English units for this
                         attribute. This is only suitable for attributes of type
                         integer or float.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API DictionaryAttribute : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    DictionaryAttribute( );
     
    //! Constructs a DictionaryAttribute with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DictionaryAttribute( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DictionaryAttribute();

private:

	//! Assignment operator
	DictionaryAttribute& operator=( const DictionaryAttribute& iSrc );

	//! Copy constructor
	DictionaryAttribute( const DictionaryAttribute& original );
     
public:

	//! Get ModifiedUser of this DictionaryAttribute
	plmxml_api::String GetModifiedUser() const;

	//! Set ModifiedUser of this DictionaryAttribute
	plmxml_api::Result SetModifiedUser( const plmxml_api::String &s );
	
	//! Check if ModifiedUser is set
	plmxml_api::logical HasModifiedUser( ) const;
	
	//! Unset ModifiedUser
	plmxml_api::Result UnsetModifiedUser( );

	//! Set AttributeId
	plmxml_api::Result SetAttributeId( int arg );
     
	//! Get AttributeId
	int GetAttributeId() const;
     
	//! Check if AttributeId is set
	plmxml_api::logical HasAttributeId() const;
     
	//! Unset AttributeId
	plmxml_api::Result UnsetAttributeId();

	//! Get CreationDate of this DictionaryAttribute
	plmxml_api::String GetCreationDate() const;

	//! Set CreationDate of this DictionaryAttribute
	plmxml_api::Result SetCreationDate( const plmxml_api::String &s );
	
	//! Check if CreationDate is set
	plmxml_api::logical HasCreationDate( ) const;
	
	//! Unset CreationDate
	plmxml_api::Result UnsetCreationDate( );

	//! Get Reference of this DictionaryAttribute
	plmxml_api::String GetReference() const;

	//! Set Reference of this DictionaryAttribute
	plmxml_api::Result SetReference( const plmxml_api::String &s );
	
	//! Check if Reference is set
	plmxml_api::logical HasReference( ) const;
	
	//! Unset Reference
	plmxml_api::Result UnsetReference( );

	//! Get CreationUser of this DictionaryAttribute
	plmxml_api::String GetCreationUser() const;

	//! Set CreationUser of this DictionaryAttribute
	plmxml_api::Result SetCreationUser( const plmxml_api::String &s );
	
	//! Check if CreationUser is set
	plmxml_api::logical HasCreationUser( ) const;
	
	//! Unset CreationUser
	plmxml_api::Result UnsetCreationUser( );

	//! Get ModifiedDate of this DictionaryAttribute
	plmxml_api::String GetModifiedDate() const;

	//! Set ModifiedDate of this DictionaryAttribute
	plmxml_api::Result SetModifiedDate( const plmxml_api::String &s );
	
	//! Check if ModifiedDate is set
	plmxml_api::logical HasModifiedDate( ) const;
	
	//! Unset ModifiedDate
	plmxml_api::Result UnsetModifiedDate( );

	//! Add Name child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Name *AddName();
     
	//! Add 'arg' as Name child element to this DictionaryAttribute.
	plmxml_api::Result AddName( Name *arg );

	//! Detach and delete all Name child elements.
	void DeleteNames();
     
	//! Get number of Name child elements.
	int NumberOfNames() const;
     
	//! Get i'th Name child element.
	Name *GetName( int i ) const;
     
	//! Get all Name child element as an array
	void GetNames( plmxml_api::Array<Name*> &array ) const;
	     
	//! Detach and delete i'th Name child element
	void DeleteName( int i );
     
	//! Detach and delete 'arg' if it's one of the Name child elements
	void DeleteName( Name *arg );

	//! Add ShortName child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ShortName *AddShortName();
     
	//! Add 'arg' as ShortName child element to this DictionaryAttribute.
	plmxml_api::Result AddShortName( ShortName *arg );

	//! Detach and delete all ShortName child elements.
	void DeleteShortNames();
     
	//! Get number of ShortName child elements.
	int NumberOfShortNames() const;
     
	//! Get i'th ShortName child element.
	ShortName *GetShortName( int i ) const;
     
	//! Get all ShortName child element as an array
	void GetShortNames( plmxml_api::Array<ShortName*> &array ) const;
	     
	//! Detach and delete i'th ShortName child element
	void DeleteShortName( int i );
     
	//! Detach and delete 'arg' if it's one of the ShortName child elements
	void DeleteShortName( ShortName *arg );

	//! Add Annotation child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Annotation *AddAnnotation();
     
	//! Add 'arg' as Annotation child element to this DictionaryAttribute.
	plmxml_api::Result AddAnnotation( Annotation *arg );

	//! Detach and delete all Annotation child elements.
	void DeleteAnnotations();
     
	//! Get number of Annotation child elements.
	int NumberOfAnnotations() const;
     
	//! Get i'th Annotation child element.
	Annotation *GetAnnotation( int i ) const;
     
	//! Get all Annotation child element as an array
	void GetAnnotations( plmxml_api::Array<Annotation*> &array ) const;
	     
	//! Detach and delete i'th Annotation child element
	void DeleteAnnotation( int i );
     
	//! Detach and delete 'arg' if it's one of the Annotation child elements
	void DeleteAnnotation( Annotation *arg );

	//! Add Format child element to this DictionaryAttribute. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatAdmin *AddFormat();
     
	//! Set Format child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormat( FormatAdmin *arg );
     
	//! Get Format child element of this DictionaryAttribute.
	FormatAdmin *GetFormat() const;
     
	//! Detach and delete Format child element tree from this DictionaryAttribute.
	void DeleteFormat();

	//! Add AltFormat child element to this DictionaryAttribute. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatAdmin *AddAltFormat();
     
	//! Set AltFormat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetAltFormat( FormatAdmin *arg );
     
	//! Get AltFormat child element of this DictionaryAttribute.
	FormatAdmin *GetAltFormat() const;
     
	//! Detach and delete AltFormat child element tree from this DictionaryAttribute.
	void DeleteAltFormat();

	//! Add MinValue child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddMinValue();
     
	//! Add 'arg' as MinValue child element to this DictionaryAttribute.
	plmxml_api::Result AddMinValue( Value *arg );

	//! Detach and delete all MinValue child elements.
	void DeleteMinValues();
     
	//! Get number of MinValue child elements.
	int NumberOfMinValues() const;
     
	//! Get i'th MinValue child element.
	Value *GetMinValue( int i ) const;
     
	//! Get all MinValue child element as an array
	void GetMinValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th MinValue child element
	void DeleteMinValue( int i );
     
	//! Detach and delete 'arg' if it's one of the MinValue child elements
	void DeleteMinValue( Value *arg );

	//! Add MaxValue child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddMaxValue();
     
	//! Add 'arg' as MaxValue child element to this DictionaryAttribute.
	plmxml_api::Result AddMaxValue( Value *arg );

	//! Detach and delete all MaxValue child elements.
	void DeleteMaxValues();
     
	//! Get number of MaxValue child elements.
	int NumberOfMaxValues() const;
     
	//! Get i'th MaxValue child element.
	Value *GetMaxValue( int i ) const;
     
	//! Get all MaxValue child element as an array
	void GetMaxValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th MaxValue child element
	void DeleteMaxValue( int i );
     
	//! Detach and delete 'arg' if it's one of the MaxValue child elements
	void DeleteMaxValue( Value *arg );

	//! Add DefaultValue child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddDefaultValue();
     
	//! Add 'arg' as DefaultValue child element to this DictionaryAttribute.
	plmxml_api::Result AddDefaultValue( Value *arg );

	//! Detach and delete all DefaultValue child elements.
	void DeleteDefaultValues();
     
	//! Get number of DefaultValue child elements.
	int NumberOfDefaultValues() const;
     
	//! Get i'th DefaultValue child element.
	Value *GetDefaultValue( int i ) const;
     
	//! Get all DefaultValue child element as an array
	void GetDefaultValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th DefaultValue child element
	void DeleteDefaultValue( int i );
     
	//! Detach and delete 'arg' if it's one of the DefaultValue child elements
	void DeleteDefaultValue( Value *arg );

	//! Add AltDefaultValue child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltDefaultValue();
     
	//! Add 'arg' as AltDefaultValue child element to this DictionaryAttribute.
	plmxml_api::Result AddAltDefaultValue( Value *arg );

	//! Detach and delete all AltDefaultValue child elements.
	void DeleteAltDefaultValues();
     
	//! Get number of AltDefaultValue child elements.
	int NumberOfAltDefaultValues() const;
     
	//! Get i'th AltDefaultValue child element.
	Value *GetAltDefaultValue( int i ) const;
     
	//! Get all AltDefaultValue child element as an array
	void GetAltDefaultValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltDefaultValue child element
	void DeleteAltDefaultValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltDefaultValue child elements
	void DeleteAltDefaultValue( Value *arg );

	//! Add UserData1 child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData1();
     
	//! Add 'arg' as UserData1 child element to this DictionaryAttribute.
	plmxml_api::Result AddUserData1( UserData *arg );

	//! Detach and delete all UserData1 child elements.
	void DeleteUserData1s();
     
	//! Get number of UserData1 child elements.
	int NumberOfUserData1s() const;
     
	//! Get i'th UserData1 child element.
	UserData *GetUserData1( int i ) const;
     
	//! Get all UserData1 child element as an array
	void GetUserData1s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData1 child element
	void DeleteUserData1( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData1 child elements
	void DeleteUserData1( UserData *arg );

	//! Add UserData2 child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData2();
     
	//! Add 'arg' as UserData2 child element to this DictionaryAttribute.
	plmxml_api::Result AddUserData2( UserData *arg );

	//! Detach and delete all UserData2 child elements.
	void DeleteUserData2s();
     
	//! Get number of UserData2 child elements.
	int NumberOfUserData2s() const;
     
	//! Get i'th UserData2 child element.
	UserData *GetUserData2( int i ) const;
     
	//! Get all UserData2 child element as an array
	void GetUserData2s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData2 child element
	void DeleteUserData2( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData2 child elements
	void DeleteUserData2( UserData *arg );

	//! Add Description child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Description *AddDescription();
     
	//! Add 'arg' as Description child element to this DictionaryAttribute.
	plmxml_api::Result AddDescription( Description *arg );

	//! Detach and delete all Description child elements.
	void DeleteDescriptions();
     
	//! Get number of Description child elements.
	int NumberOfDescriptions() const;
     
	//! Get i'th Description child element.
	Description *GetDescription( int i ) const;
     
	//! Get all Description child element as an array
	void GetDescriptions( plmxml_api::Array<Description*> &array ) const;
	     
	//! Detach and delete i'th Description child element
	void DeleteDescription( int i );
     
	//! Detach and delete 'arg' if it's one of the Description child elements
	void DeleteDescription( Description *arg );

	//! Add Comment child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Comment *AddComment();
     
	//! Add 'arg' as Comment child element to this DictionaryAttribute.
	plmxml_api::Result AddComment( Comment *arg );

	//! Detach and delete all Comment child elements.
	void DeleteComments();
     
	//! Get number of Comment child elements.
	int NumberOfComments() const;
     
	//! Get i'th Comment child element.
	Comment *GetComment( int i ) const;
     
	//! Get all Comment child element as an array
	void GetComments( plmxml_api::Array<Comment*> &array ) const;
	     
	//! Detach and delete i'th Comment child element
	void DeleteComment( int i );
     
	//! Detach and delete 'arg' if it's one of the Comment child elements
	void DeleteComment( Comment *arg );

	//! Add ReferenceSpecification child element to this DictionaryAttribute. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ReferenceSpecification *AddReferenceSpecification();
     
	//! Set ReferenceSpecification child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetReferenceSpecification( ReferenceSpecification *arg );
     
	//! Get ReferenceSpecification child element of this DictionaryAttribute.
	ReferenceSpecification *GetReferenceSpecification() const;
     
	//! Detach and delete ReferenceSpecification child element tree from this DictionaryAttribute.
	void DeleteReferenceSpecification();

	//! Add GeneralOption child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GeneralOption *AddGeneralOption();
     
	//! Add 'arg' as GeneralOption child element to this DictionaryAttribute.
	plmxml_api::Result AddGeneralOption( GeneralOption *arg );

	//! Detach and delete all GeneralOption child elements.
	void DeleteGeneralOptions();
     
	//! Get number of GeneralOption child elements.
	int NumberOfGeneralOptions() const;
     
	//! Get i'th GeneralOption child element.
	GeneralOption *GetGeneralOption( int i ) const;
     
	//! Get all GeneralOption child element as an array
	void GetGeneralOptions( plmxml_api::Array<GeneralOption*> &array ) const;
	     
	//! Detach and delete i'th GeneralOption child element
	void DeleteGeneralOption( int i );
     
	//! Detach and delete 'arg' if it's one of the GeneralOption child elements
	void DeleteGeneralOption( GeneralOption *arg );

	//! Add AltMinValue child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltMinValue();
     
	//! Add 'arg' as AltMinValue child element to this DictionaryAttribute.
	plmxml_api::Result AddAltMinValue( Value *arg );

	//! Detach and delete all AltMinValue child elements.
	void DeleteAltMinValues();
     
	//! Get number of AltMinValue child elements.
	int NumberOfAltMinValues() const;
     
	//! Get i'th AltMinValue child element.
	Value *GetAltMinValue( int i ) const;
     
	//! Get all AltMinValue child element as an array
	void GetAltMinValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltMinValue child element
	void DeleteAltMinValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltMinValue child elements
	void DeleteAltMinValue( Value *arg );

	//! Add AltMaxValue child element to this DictionaryAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltMaxValue();
     
	//! Add 'arg' as AltMaxValue child element to this DictionaryAttribute.
	plmxml_api::Result AddAltMaxValue( Value *arg );

	//! Detach and delete all AltMaxValue child elements.
	void DeleteAltMaxValues();
     
	//! Get number of AltMaxValue child elements.
	int NumberOfAltMaxValues() const;
     
	//! Get i'th AltMaxValue child element.
	Value *GetAltMaxValue( int i ) const;
     
	//! Get all AltMaxValue child element as an array
	void GetAltMaxValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltMaxValue child element
	void DeleteAltMaxValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltMaxValue child elements
	void DeleteAltMaxValue( Value *arg );
 
// <PLMXML_UserCode type="functionHeaderDictionaryAttribute" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassDictionaryAttribute;


////////////////////////////////////////////////////////////////////////////////////
//! Parent class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Parent : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Parent( );
     
    //! Constructs a Parent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Parent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Parent();

private:

	//! Assignment operator
	Parent& operator=( const Parent& iSrc );

	//! Copy constructor
	Parent( const Parent& original );
     
public:

	//! Set reference to Parent using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetParentRef( plmxml60::IdObject *arg );

	//! Clear reference to Parent
	void RemoveParentRef( );

	//! Find a plmxml60::IdObject referenced by Parent
	plmxml60::IdObject *ResolveParentRef( plmxml_api::Configuration* config = NULL );

	//! Get Parent reference
	plmxml_api::String GetParentId() const;

	//! Set Parent reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetParentId( const plmxml_api::String& u );
	
	//! Check if Parent is set
	plmxml_api::logical HasParentRef( ) const;
 
// <PLMXML_UserCode type="functionHeaderParent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassParent;


////////////////////////////////////////////////////////////////////////////////////
//! ClassAttributeOption class
/*!
\verbatim

      This type is intended to serve as a flexible extension mechanism to the existing
      explicit elements and attributes of the class attributes.
      
      Attributes:
          
      optionType:   allows to define a type for the option like pre or post option
      name:         the name of the option
      language:     the language of the value
      value:        the value of the option
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API ClassAttributeOption : public plmxml_api::Object
{
public:
     
    //! Default constructor
    ClassAttributeOption( );
     
    //! Constructs a ClassAttributeOption with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClassAttributeOption( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClassAttributeOption();

private:

	//! Assignment operator
	ClassAttributeOption& operator=( const ClassAttributeOption& iSrc );

	//! Copy constructor
	ClassAttributeOption( const ClassAttributeOption& original );
     
public:

	//! Get Value of this ClassAttributeOption
	plmxml_api::String GetValue() const;

	//! Set Value of this ClassAttributeOption
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Get Name of this ClassAttributeOption
	plmxml_api::String GetName() const;

	//! Set Name of this ClassAttributeOption
	plmxml_api::Result SetName( const plmxml_api::String &s );
	
	//! Check if Name is set
	plmxml_api::logical HasName( ) const;
	
	//! Unset Name
	plmxml_api::Result UnsetName( );

	//! Get Language of this ClassAttributeOption
	plmxml_api::String GetLanguage() const;

	//! Set Language of this ClassAttributeOption
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Get OptionType of this ClassAttributeOption
	plmxml_api::String GetOptionType() const;

	//! Set OptionType of this ClassAttributeOption
	plmxml_api::Result SetOptionType( const plmxml_api::String &s );
	
	//! Check if OptionType is set
	plmxml_api::logical HasOptionType( ) const;
	
	//! Unset OptionType
	plmxml_api::Result UnsetOptionType( );
 
// <PLMXML_UserCode type="functionHeaderClassAttributeOption" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassClassAttributeOption;


////////////////////////////////////////////////////////////////////////////////////
//! AbstractClassAttribute class
/*!
\verbatim

      Attributes:
      
      CommonClassAttrAttributes:
      
      Elements:
      
      Annotation:         The Annotation is used to identify a attribute within one class and act 
                          as a reference into a related class image which visualises the attribute. 
                          If no value is given a default value is taken from the Annotation definition 
                          in the dictionary attribute definition
                          
      MinValue:           Defines the minimum allowed value for values of this
                          attribute in metric units. This definition overwrites
                          the definition in the dictionary attribute definition
                          and must be greater than or equal to the definition
                          there.
      MaxValue:           Defines the maximum allowed value for values of this
                          attribute in metric units. This definition overwrites
                          the definition in the dictionary attribute definition
                          and must be less than or equal to the definition
                          there.
                          
      DefaultValue:       Defines the metric unit default value for new instances of this class. This
                          definition overwrites the definition in the dictionary attribute definition.
      AltDefaultValue:    Defines the english unit default value for new instances of this class. This
                          definition overwrites the definition in the dictionary attribute definition.
                          
      Option:
      UserData1:          Allows the user to add his own information to the class
      UserData2:          Allows the user to add his own information to the class
      ReferenceSpecification:
      AltMinValue:        Defines the minimum allowed value for values of this
                          attribute in English units. This definition overwrites
                          the definition in the dictionary attribute definition
                          and must be greater than or equal to the definition
                          there.
      AltMaxValue:        Defines the maximum allowed value for values of this
                          attribute in English units. This definition overwrites
                          the definition in the dictionary attribute definition
                          and must be less than or equal to the definition
                          there.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AbstractClassAttribute : public plmxml_api::Object
{
public:
     
    //! Default constructor
    AbstractClassAttribute( );
     
    //! Constructs a AbstractClassAttribute with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AbstractClassAttribute( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AbstractClassAttribute();

private:

	//! Assignment operator
	AbstractClassAttribute& operator=( const AbstractClassAttribute& iSrc );

	//! Copy constructor
	AbstractClassAttribute( const AbstractClassAttribute& original );
     
public:

	//! Set HasFixedDefaultValue
	plmxml_api::Result SetHasFixedDefaultValue( plmxml_api::logical arg );

	//! Get HasFixedDefaultValue
	plmxml_api::logical GetHasFixedDefaultValue() const;

	//! Check if HasFixedDefaultValue is set
	plmxml_api::logical HasHasFixedDefaultValue() const;

	//! Unset HasFixedDefaultValue
	plmxml_api::Result UnsetHasFixedDefaultValue();

	//! Set AttributeId
	plmxml_api::Result SetAttributeId( int arg );
     
	//! Get AttributeId
	int GetAttributeId() const;
     
	//! Check if AttributeId is set
	plmxml_api::logical HasAttributeId() const;
     
	//! Unset AttributeId
	plmxml_api::Result UnsetAttributeId();

	//! Set IsPropagated
	plmxml_api::Result SetIsPropagated( plmxml_api::logical arg );

	//! Get IsPropagated
	plmxml_api::logical GetIsPropagated() const;

	//! Check if IsPropagated is set
	plmxml_api::logical HasIsPropagated() const;

	//! Unset IsPropagated
	plmxml_api::Result UnsetIsPropagated();

	//! Set IsLocalValue
	plmxml_api::Result SetIsLocalValue( plmxml_api::logical arg );

	//! Get IsLocalValue
	plmxml_api::logical GetIsLocalValue() const;

	//! Check if IsLocalValue is set
	plmxml_api::logical HasIsLocalValue() const;

	//! Unset IsLocalValue
	plmxml_api::Result UnsetIsLocalValue();

	//! Set IsMandatory
	plmxml_api::Result SetIsMandatory( plmxml_api::logical arg );

	//! Get IsMandatory
	plmxml_api::logical GetIsMandatory() const;

	//! Check if IsMandatory is set
	plmxml_api::logical HasIsMandatory() const;

	//! Unset IsMandatory
	plmxml_api::Result UnsetIsMandatory();

	//! Set IsExternalArray
	plmxml_api::Result SetIsExternalArray( plmxml_api::logical arg );

	//! Get IsExternalArray
	plmxml_api::logical GetIsExternalArray() const;

	//! Check if IsExternalArray is set
	plmxml_api::logical HasIsExternalArray() const;

	//! Unset IsExternalArray
	plmxml_api::Result UnsetIsExternalArray();

	//! Set IsAutoComputed
	plmxml_api::Result SetIsAutoComputed( plmxml_api::logical arg );

	//! Get IsAutoComputed
	plmxml_api::logical GetIsAutoComputed() const;

	//! Check if IsAutoComputed is set
	plmxml_api::logical HasIsAutoComputed() const;

	//! Unset IsAutoComputed
	plmxml_api::Result UnsetIsAutoComputed();

	//! Set IsProtected
	plmxml_api::Result SetIsProtected( plmxml_api::logical arg );

	//! Get IsProtected
	plmxml_api::logical GetIsProtected() const;

	//! Check if IsProtected is set
	plmxml_api::logical HasIsProtected() const;

	//! Unset IsProtected
	plmxml_api::Result UnsetIsProtected();

	//! Set ArraySize
	plmxml_api::Result SetArraySize( int arg );
     
	//! Get ArraySize
	int GetArraySize() const;
     
	//! Check if ArraySize is set
	plmxml_api::logical HasArraySize() const;
     
	//! Unset ArraySize
	plmxml_api::Result UnsetArraySize();

	//! Set IsReference
	plmxml_api::Result SetIsReference( plmxml_api::logical arg );

	//! Get IsReference
	plmxml_api::logical GetIsReference() const;

	//! Check if IsReference is set
	plmxml_api::logical HasIsReference() const;

	//! Unset IsReference
	plmxml_api::Result UnsetIsReference();

	//! Set IsUnique
	plmxml_api::Result SetIsUnique( plmxml_api::logical arg );

	//! Get IsUnique
	plmxml_api::logical GetIsUnique() const;

	//! Check if IsUnique is set
	plmxml_api::logical HasIsUnique() const;

	//! Unset IsUnique
	plmxml_api::Result UnsetIsUnique();

	//! Add Annotation child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Annotation *AddAnnotation();
     
	//! Add 'arg' as Annotation child element to this AbstractClassAttribute.
	plmxml_api::Result AddAnnotation( Annotation *arg );

	//! Detach and delete all Annotation child elements.
	void DeleteAnnotations();
     
	//! Get number of Annotation child elements.
	int NumberOfAnnotations() const;
     
	//! Get i'th Annotation child element.
	Annotation *GetAnnotation( int i ) const;
     
	//! Get all Annotation child element as an array
	void GetAnnotations( plmxml_api::Array<Annotation*> &array ) const;
	     
	//! Detach and delete i'th Annotation child element
	void DeleteAnnotation( int i );
     
	//! Detach and delete 'arg' if it's one of the Annotation child elements
	void DeleteAnnotation( Annotation *arg );

	//! Add MinValue child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddMinValue();
     
	//! Add 'arg' as MinValue child element to this AbstractClassAttribute.
	plmxml_api::Result AddMinValue( Value *arg );

	//! Detach and delete all MinValue child elements.
	void DeleteMinValues();
     
	//! Get number of MinValue child elements.
	int NumberOfMinValues() const;
     
	//! Get i'th MinValue child element.
	Value *GetMinValue( int i ) const;
     
	//! Get all MinValue child element as an array
	void GetMinValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th MinValue child element
	void DeleteMinValue( int i );
     
	//! Detach and delete 'arg' if it's one of the MinValue child elements
	void DeleteMinValue( Value *arg );

	//! Add MaxValue child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddMaxValue();
     
	//! Add 'arg' as MaxValue child element to this AbstractClassAttribute.
	plmxml_api::Result AddMaxValue( Value *arg );

	//! Detach and delete all MaxValue child elements.
	void DeleteMaxValues();
     
	//! Get number of MaxValue child elements.
	int NumberOfMaxValues() const;
     
	//! Get i'th MaxValue child element.
	Value *GetMaxValue( int i ) const;
     
	//! Get all MaxValue child element as an array
	void GetMaxValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th MaxValue child element
	void DeleteMaxValue( int i );
     
	//! Detach and delete 'arg' if it's one of the MaxValue child elements
	void DeleteMaxValue( Value *arg );

	//! Add DefaultValue child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddDefaultValue();
     
	//! Add 'arg' as DefaultValue child element to this AbstractClassAttribute.
	plmxml_api::Result AddDefaultValue( Value *arg );

	//! Detach and delete all DefaultValue child elements.
	void DeleteDefaultValues();
     
	//! Get number of DefaultValue child elements.
	int NumberOfDefaultValues() const;
     
	//! Get i'th DefaultValue child element.
	Value *GetDefaultValue( int i ) const;
     
	//! Get all DefaultValue child element as an array
	void GetDefaultValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th DefaultValue child element
	void DeleteDefaultValue( int i );
     
	//! Detach and delete 'arg' if it's one of the DefaultValue child elements
	void DeleteDefaultValue( Value *arg );

	//! Add AltDefaultValue child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltDefaultValue();
     
	//! Add 'arg' as AltDefaultValue child element to this AbstractClassAttribute.
	plmxml_api::Result AddAltDefaultValue( Value *arg );

	//! Detach and delete all AltDefaultValue child elements.
	void DeleteAltDefaultValues();
     
	//! Get number of AltDefaultValue child elements.
	int NumberOfAltDefaultValues() const;
     
	//! Get i'th AltDefaultValue child element.
	Value *GetAltDefaultValue( int i ) const;
     
	//! Get all AltDefaultValue child element as an array
	void GetAltDefaultValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltDefaultValue child element
	void DeleteAltDefaultValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltDefaultValue child elements
	void DeleteAltDefaultValue( Value *arg );

	//! Add Option child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ClassAttributeOption *AddOption();
     
	//! Add 'arg' as Option child element to this AbstractClassAttribute.
	plmxml_api::Result AddOption( ClassAttributeOption *arg );

	//! Detach and delete all Option child elements.
	void DeleteOptions();
     
	//! Get number of Option child elements.
	int NumberOfOptions() const;
     
	//! Get i'th Option child element.
	ClassAttributeOption *GetOption( int i ) const;
     
	//! Get all Option child element as an array
	void GetOptions( plmxml_api::Array<ClassAttributeOption*> &array ) const;
	     
	//! Detach and delete i'th Option child element
	void DeleteOption( int i );
     
	//! Detach and delete 'arg' if it's one of the Option child elements
	void DeleteOption( ClassAttributeOption *arg );

	//! Add UserData1 child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData1();
     
	//! Add 'arg' as UserData1 child element to this AbstractClassAttribute.
	plmxml_api::Result AddUserData1( UserData *arg );

	//! Detach and delete all UserData1 child elements.
	void DeleteUserData1s();
     
	//! Get number of UserData1 child elements.
	int NumberOfUserData1s() const;
     
	//! Get i'th UserData1 child element.
	UserData *GetUserData1( int i ) const;
     
	//! Get all UserData1 child element as an array
	void GetUserData1s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData1 child element
	void DeleteUserData1( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData1 child elements
	void DeleteUserData1( UserData *arg );

	//! Add UserData2 child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData2();
     
	//! Add 'arg' as UserData2 child element to this AbstractClassAttribute.
	plmxml_api::Result AddUserData2( UserData *arg );

	//! Detach and delete all UserData2 child elements.
	void DeleteUserData2s();
     
	//! Get number of UserData2 child elements.
	int NumberOfUserData2s() const;
     
	//! Get i'th UserData2 child element.
	UserData *GetUserData2( int i ) const;
     
	//! Get all UserData2 child element as an array
	void GetUserData2s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData2 child element
	void DeleteUserData2( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData2 child elements
	void DeleteUserData2( UserData *arg );

	//! Add ReferenceSpecification child element to this AbstractClassAttribute. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ReferenceSpecification *AddReferenceSpecification();
     
	//! Set ReferenceSpecification child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetReferenceSpecification( ReferenceSpecification *arg );
     
	//! Get ReferenceSpecification child element of this AbstractClassAttribute.
	ReferenceSpecification *GetReferenceSpecification() const;
     
	//! Detach and delete ReferenceSpecification child element tree from this AbstractClassAttribute.
	void DeleteReferenceSpecification();

	//! Add AltMinValue child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltMinValue();
     
	//! Add 'arg' as AltMinValue child element to this AbstractClassAttribute.
	plmxml_api::Result AddAltMinValue( Value *arg );

	//! Detach and delete all AltMinValue child elements.
	void DeleteAltMinValues();
     
	//! Get number of AltMinValue child elements.
	int NumberOfAltMinValues() const;
     
	//! Get i'th AltMinValue child element.
	Value *GetAltMinValue( int i ) const;
     
	//! Get all AltMinValue child element as an array
	void GetAltMinValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltMinValue child element
	void DeleteAltMinValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltMinValue child elements
	void DeleteAltMinValue( Value *arg );

	//! Add AltMaxValue child element to this AbstractClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltMaxValue();
     
	//! Add 'arg' as AltMaxValue child element to this AbstractClassAttribute.
	plmxml_api::Result AddAltMaxValue( Value *arg );

	//! Detach and delete all AltMaxValue child elements.
	void DeleteAltMaxValues();
     
	//! Get number of AltMaxValue child elements.
	int NumberOfAltMaxValues() const;
     
	//! Get i'th AltMaxValue child element.
	Value *GetAltMaxValue( int i ) const;
     
	//! Get all AltMaxValue child element as an array
	void GetAltMaxValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltMaxValue child element
	void DeleteAltMaxValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltMaxValue child elements
	void DeleteAltMaxValue( Value *arg );
 
// <PLMXML_UserCode type="functionHeaderAbstractClassAttribute" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAbstractClassAttribute;


////////////////////////////////////////////////////////////////////////////////////
//! AbstractClass class
/*!
\verbatim

      Attributes:

      CommonClassAttributes
      HistoryAttributes

      Elements:

      Name:            Display name for the class
      AliasName:       One or more alias names for the class
      ShortName:       Short version of the display name for the class
      UserData1:       User specific data
      UserData2:       User specific data
      Description:     A description of the class which might be displayed to the user
      Comment:         General comment intended for the maintainer of the class
      File:            Special supported values for format are Image, Icon and Template
      GeneralOption:   General Options for the class definition.
      LibraryType:      The types of library that the class represents.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AbstractClass : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    AbstractClass( );
     
    //! Constructs a AbstractClass with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AbstractClass( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AbstractClass();

private:

	//! Assignment operator
	AbstractClass& operator=( const AbstractClass& iSrc );

	//! Copy constructor
	AbstractClass( const AbstractClass& original );
     
public:

	//! Get ModifiedUser of this AbstractClass
	plmxml_api::String GetModifiedUser() const;

	//! Set ModifiedUser of this AbstractClass
	plmxml_api::Result SetModifiedUser( const plmxml_api::String &s );
	
	//! Check if ModifiedUser is set
	plmxml_api::logical HasModifiedUser( ) const;
	
	//! Unset ModifiedUser
	plmxml_api::Result UnsetModifiedUser( );

	//! Set IsAssembly
	plmxml_api::Result SetIsAssembly( plmxml_api::logical arg );

	//! Get IsAssembly
	plmxml_api::logical GetIsAssembly() const;

	//! Check if IsAssembly is set
	plmxml_api::logical HasIsAssembly() const;

	//! Unset IsAssembly
	plmxml_api::Result UnsetIsAssembly();

	//! Set IsAbstract
	plmxml_api::Result SetIsAbstract( plmxml_api::logical arg );

	//! Get IsAbstract
	plmxml_api::logical GetIsAbstract() const;

	//! Check if IsAbstract is set
	plmxml_api::logical HasIsAbstract() const;

	//! Unset IsAbstract
	plmxml_api::Result UnsetIsAbstract();

	//! Get ClassId of this AbstractClass
	plmxml_api::String GetClassId() const;

	//! Set ClassId of this AbstractClass
	plmxml_api::Result SetClassId( const plmxml_api::String &s );
	
	//! Check if ClassId is set
	plmxml_api::logical HasClassId( ) const;
	
	//! Unset ClassId
	plmxml_api::Result UnsetClassId( );

	//! Get CreationDate of this AbstractClass
	plmxml_api::String GetCreationDate() const;

	//! Set CreationDate of this AbstractClass
	plmxml_api::Result SetCreationDate( const plmxml_api::String &s );
	
	//! Check if CreationDate is set
	plmxml_api::logical HasCreationDate( ) const;
	
	//! Unset CreationDate
	plmxml_api::Result UnsetCreationDate( );

	//! Set AllowsMultiInst
	plmxml_api::Result SetAllowsMultiInst( plmxml_api::logical arg );

	//! Get AllowsMultiInst
	plmxml_api::logical GetAllowsMultiInst() const;

	//! Check if AllowsMultiInst is set
	plmxml_api::logical HasAllowsMultiInst() const;

	//! Unset AllowsMultiInst
	plmxml_api::Result UnsetAllowsMultiInst();

	//! Get Library of this AbstractClass
	plmxml_api::String GetLibrary() const;

	//! Set Library of this AbstractClass
	plmxml_api::Result SetLibrary( const plmxml_api::String &s );
	
	//! Check if Library is set
	plmxml_api::logical HasLibrary( ) const;
	
	//! Unset Library
	plmxml_api::Result UnsetLibrary( );

	//! Get CreationUser of this AbstractClass
	plmxml_api::String GetCreationUser() const;

	//! Set CreationUser of this AbstractClass
	plmxml_api::Result SetCreationUser( const plmxml_api::String &s );
	
	//! Check if CreationUser is set
	plmxml_api::logical HasCreationUser( ) const;
	
	//! Unset CreationUser
	plmxml_api::Result UnsetCreationUser( );

	//! Get ModifiedDate of this AbstractClass
	plmxml_api::String GetModifiedDate() const;

	//! Set ModifiedDate of this AbstractClass
	plmxml_api::Result SetModifiedDate( const plmxml_api::String &s );
	
	//! Check if ModifiedDate is set
	plmxml_api::logical HasModifiedDate( ) const;
	
	//! Unset ModifiedDate
	plmxml_api::Result UnsetModifiedDate( );

	//! Set ChildCount
	plmxml_api::Result SetChildCount( int arg );
     
	//! Get ChildCount
	int GetChildCount() const;
     
	//! Check if ChildCount is set
	plmxml_api::logical HasChildCount() const;
     
	//! Unset ChildCount
	plmxml_api::Result UnsetChildCount();

	//! Get number of references in Template array
	int NumberOfTemplateRefs() const;
     
	//! Add reference to 'arg' to Template array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddTemplateRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Template array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddTemplateId( const plmxml_api::String &u );
     
	//! Set i'th reference in Template array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetTemplateRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Template array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetTemplateId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Template array and return an object it points to.
	plmxml60::IdObject *ResolveTemplateRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Template array and return objects they point to.
	void ResolveTemplateRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Template array as plmxml_api::String
	plmxml_api::String GetTemplateId( int i ) const;
     
	//! Get all references in Template array as an array of plmxml_api::String
	void GetTemplateIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Template array.
	void RemoveTemplateRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Template array.
	void RemoveTemplateRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Template array.
	void RemoveTemplateRef( plmxml60::IdObject *arg );
     
	//! Remove all references Template array.
	void RemoveTemplateRefs();
	
	//! Check if Template is set
	plmxml_api::logical HasTemplateRefs( ) const;

	//! Set InstanceCount
	plmxml_api::Result SetInstanceCount( int arg );
     
	//! Get InstanceCount
	int GetInstanceCount() const;
     
	//! Check if InstanceCount is set
	plmxml_api::logical HasInstanceCount() const;
     
	//! Unset InstanceCount
	plmxml_api::Result UnsetInstanceCount();

	//! Add Name child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Name *AddName();
     
	//! Add 'arg' as Name child element to this AbstractClass.
	plmxml_api::Result AddName( Name *arg );

	//! Detach and delete all Name child elements.
	void DeleteNames();
     
	//! Get number of Name child elements.
	int NumberOfNames() const;
     
	//! Get i'th Name child element.
	Name *GetName( int i ) const;
     
	//! Get all Name child element as an array
	void GetNames( plmxml_api::Array<Name*> &array ) const;
	     
	//! Detach and delete i'th Name child element
	void DeleteName( int i );
     
	//! Detach and delete 'arg' if it's one of the Name child elements
	void DeleteName( Name *arg );

	//! Add AliasName child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Name *AddAliasName();
     
	//! Add 'arg' as AliasName child element to this AbstractClass.
	plmxml_api::Result AddAliasName( Name *arg );

	//! Detach and delete all AliasName child elements.
	void DeleteAliasNames();
     
	//! Get number of AliasName child elements.
	int NumberOfAliasNames() const;
     
	//! Get i'th AliasName child element.
	Name *GetAliasName( int i ) const;
     
	//! Get all AliasName child element as an array
	void GetAliasNames( plmxml_api::Array<Name*> &array ) const;
	     
	//! Detach and delete i'th AliasName child element
	void DeleteAliasName( int i );
     
	//! Detach and delete 'arg' if it's one of the AliasName child elements
	void DeleteAliasName( Name *arg );

	//! Add ShortName child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ShortName *AddShortName();
     
	//! Add 'arg' as ShortName child element to this AbstractClass.
	plmxml_api::Result AddShortName( ShortName *arg );

	//! Detach and delete all ShortName child elements.
	void DeleteShortNames();
     
	//! Get number of ShortName child elements.
	int NumberOfShortNames() const;
     
	//! Get i'th ShortName child element.
	ShortName *GetShortName( int i ) const;
     
	//! Get all ShortName child element as an array
	void GetShortNames( plmxml_api::Array<ShortName*> &array ) const;
	     
	//! Detach and delete i'th ShortName child element
	void DeleteShortName( int i );
     
	//! Detach and delete 'arg' if it's one of the ShortName child elements
	void DeleteShortName( ShortName *arg );

	//! Add UserData1 child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData1();
     
	//! Add 'arg' as UserData1 child element to this AbstractClass.
	plmxml_api::Result AddUserData1( UserData *arg );

	//! Detach and delete all UserData1 child elements.
	void DeleteUserData1s();
     
	//! Get number of UserData1 child elements.
	int NumberOfUserData1s() const;
     
	//! Get i'th UserData1 child element.
	UserData *GetUserData1( int i ) const;
     
	//! Get all UserData1 child element as an array
	void GetUserData1s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData1 child element
	void DeleteUserData1( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData1 child elements
	void DeleteUserData1( UserData *arg );

	//! Add UserData2 child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData2();
     
	//! Add 'arg' as UserData2 child element to this AbstractClass.
	plmxml_api::Result AddUserData2( UserData *arg );

	//! Detach and delete all UserData2 child elements.
	void DeleteUserData2s();
     
	//! Get number of UserData2 child elements.
	int NumberOfUserData2s() const;
     
	//! Get i'th UserData2 child element.
	UserData *GetUserData2( int i ) const;
     
	//! Get all UserData2 child element as an array
	void GetUserData2s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData2 child element
	void DeleteUserData2( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData2 child elements
	void DeleteUserData2( UserData *arg );

	//! Add Description child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Description *AddDescription();
     
	//! Add 'arg' as Description child element to this AbstractClass.
	plmxml_api::Result AddDescription( Description *arg );

	//! Detach and delete all Description child elements.
	void DeleteDescriptions();
     
	//! Get number of Description child elements.
	int NumberOfDescriptions() const;
     
	//! Get i'th Description child element.
	Description *GetDescription( int i ) const;
     
	//! Get all Description child element as an array
	void GetDescriptions( plmxml_api::Array<Description*> &array ) const;
	     
	//! Detach and delete i'th Description child element
	void DeleteDescription( int i );
     
	//! Detach and delete 'arg' if it's one of the Description child elements
	void DeleteDescription( Description *arg );

	//! Add Comment child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Comment *AddComment();
     
	//! Add 'arg' as Comment child element to this AbstractClass.
	plmxml_api::Result AddComment( Comment *arg );

	//! Detach and delete all Comment child elements.
	void DeleteComments();
     
	//! Get number of Comment child elements.
	int NumberOfComments() const;
     
	//! Get i'th Comment child element.
	Comment *GetComment( int i ) const;
     
	//! Get all Comment child element as an array
	void GetComments( plmxml_api::Array<Comment*> &array ) const;
	     
	//! Detach and delete i'th Comment child element
	void DeleteComment( int i );
     
	//! Detach and delete 'arg' if it's one of the Comment child elements
	void DeleteComment( Comment *arg );

	//! Add File child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	File *AddFile();
     
	//! Add 'arg' as File child element to this AbstractClass.
	plmxml_api::Result AddFile( File *arg );

	//! Detach and delete all File child elements.
	void DeleteFiles();
     
	//! Get number of File child elements.
	int NumberOfFiles() const;
     
	//! Get i'th File child element.
	File *GetFile( int i ) const;
     
	//! Get all File child element as an array
	void GetFiles( plmxml_api::Array<File*> &array ) const;
	     
	//! Detach and delete i'th File child element
	void DeleteFile( int i );
     
	//! Detach and delete 'arg' if it's one of the File child elements
	void DeleteFile( File *arg );

	//! Add GeneralOption child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GeneralOption *AddGeneralOption();
     
	//! Add 'arg' as GeneralOption child element to this AbstractClass.
	plmxml_api::Result AddGeneralOption( GeneralOption *arg );

	//! Detach and delete all GeneralOption child elements.
	void DeleteGeneralOptions();
     
	//! Get number of GeneralOption child elements.
	int NumberOfGeneralOptions() const;
     
	//! Get i'th GeneralOption child element.
	GeneralOption *GetGeneralOption( int i ) const;
     
	//! Get all GeneralOption child element as an array
	void GetGeneralOptions( plmxml_api::Array<GeneralOption*> &array ) const;
	     
	//! Detach and delete i'th GeneralOption child element
	void DeleteGeneralOption( int i );
     
	//! Detach and delete 'arg' if it's one of the GeneralOption child elements
	void DeleteGeneralOption( GeneralOption *arg );

	//! Add LibraryType child element to this AbstractClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	LanguageString *AddLibraryType();
     
	//! Add 'arg' as LibraryType child element to this AbstractClass.
	plmxml_api::Result AddLibraryType( LanguageString *arg );

	//! Detach and delete all LibraryType child elements.
	void DeleteLibraryTypes();
     
	//! Get number of LibraryType child elements.
	int NumberOfLibraryTypes() const;
     
	//! Get i'th LibraryType child element.
	LanguageString *GetLibraryType( int i ) const;
     
	//! Get all LibraryType child element as an array
	void GetLibraryTypes( plmxml_api::Array<LanguageString*> &array ) const;
	     
	//! Detach and delete i'th LibraryType child element
	void DeleteLibraryType( int i );
     
	//! Detach and delete 'arg' if it's one of the LibraryType child elements
	void DeleteLibraryType( LanguageString *arg );
 
// <PLMXML_UserCode type="functionHeaderAbstractClass" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAbstractClass;


////////////////////////////////////////////////////////////////////////////////////
//! AdminClassAttribute class
/*!
\verbatim

      This type holds the attributes of a Classification Class.
    
      Attributes:
    
      ref2AttributeRef:     Reference to the DictionaryAttribute Element containing
                            the global definition of the attribute.
      hasLocalDefaultValue: if true this class attribute overwrite the value from the dictionary.  
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AdminClassAttribute : public AbstractClassAttribute
{
public:
     
    //! Default constructor
    AdminClassAttribute( );
     
    //! Constructs a AdminClassAttribute with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AdminClassAttribute( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AdminClassAttribute();

private:

	//! Assignment operator
	AdminClassAttribute& operator=( const AdminClassAttribute& iSrc );

	//! Copy constructor
	AdminClassAttribute( const AdminClassAttribute& original );
     
public:

	//! Set HasLocalDefaultValue
	plmxml_api::Result SetHasLocalDefaultValue( plmxml_api::logical arg );

	//! Get HasLocalDefaultValue
	plmxml_api::logical GetHasLocalDefaultValue() const;

	//! Check if HasLocalDefaultValue is set
	plmxml_api::logical HasHasLocalDefaultValue() const;

	//! Unset HasLocalDefaultValue
	plmxml_api::Result UnsetHasLocalDefaultValue();

	//! Set reference to Ref2Attribute using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRef2AttributeRef( plmxml60::IdObject *arg );

	//! Clear reference to Ref2Attribute
	void RemoveRef2AttributeRef( );

	//! Find a plmxml60::IdObject referenced by Ref2Attribute
	plmxml60::IdObject *ResolveRef2AttributeRef( plmxml_api::Configuration* config = NULL );

	//! Get Ref2Attribute reference
	plmxml_api::String GetRef2AttributeId() const;

	//! Set Ref2Attribute reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRef2AttributeId( const plmxml_api::String& u );
	
	//! Check if Ref2Attribute is set
	plmxml_api::logical HasRef2AttributeRef( ) const;
 
// <PLMXML_UserCode type="functionHeaderAdminClassAttribute" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAdminClassAttribute;


////////////////////////////////////////////////////////////////////////////////////
//! AdminClass class
/*!
\verbatim

      The class definition is the core element which is ued to build the classification hierarchy 
      and used to store the instances (ICOs)  
      
      Attributes:
      
      isGroup:
      
      Elements:
      
      Parent:             Id of the parent class
      Attribute:
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AdminClass : public AbstractClass
{
public:
     
    //! Default constructor
    AdminClass( );
     
    //! Constructs a AdminClass with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AdminClass( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AdminClass();

private:

	//! Assignment operator
	AdminClass& operator=( const AdminClass& iSrc );

	//! Copy constructor
	AdminClass( const AdminClass& original );
     
public:

	//! Set IsGroup
	plmxml_api::Result SetIsGroup( plmxml_api::logical arg );

	//! Get IsGroup
	plmxml_api::logical GetIsGroup() const;

	//! Check if IsGroup is set
	plmxml_api::logical HasIsGroup() const;

	//! Unset IsGroup
	plmxml_api::Result UnsetIsGroup();

	//! Set UnitBase
	plmxml_api::Result SetUnitBase( const eUnitBaseType& arg );

	//! Get UnitBase
	eUnitBaseType GetUnitBase() const;

	//! Add Parent child element to this AdminClass. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Parent *AddParent();
     
	//! Set Parent child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetParent( Parent *arg );
     
	//! Get Parent child element of this AdminClass.
	Parent *GetParent() const;
     
	//! Detach and delete Parent child element tree from this AdminClass.
	void DeleteParent();

	//! Add Attribute child element to this AdminClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	AdminClassAttribute *AddAdminAttribute();
     
	//! Add 'arg' as Attribute child element to this AdminClass.
	plmxml_api::Result AddAdminAttribute( AdminClassAttribute *arg );

	//! Detach and delete all Attribute child elements.
	void DeleteAdminAttributes();
     
	//! Get number of Attribute child elements.
	int NumberOfAdminAttributes() const;
     
	//! Get i'th Attribute child element.
	AdminClassAttribute *GetAdminAttribute( int i ) const;
     
	//! Get all Attribute child element as an array
	void GetAdminAttributes( plmxml_api::Array<AdminClassAttribute*> &array ) const;
	     
	//! Detach and delete i'th Attribute child element
	void DeleteAdminAttribute( int i );
     
	//! Detach and delete 'arg' if it's one of the Attribute child elements
	void DeleteAdminAttribute( AdminClassAttribute *arg );
 
// <PLMXML_UserCode type="functionHeaderAdminClass" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAdminClass;


////////////////////////////////////////////////////////////////////////////////////
//! AdminViewAttributeOptions class
/*!
\verbatim

      This type is intended to serve as a flexible extension mechanism to the existing
      explicit elements and attributes of the class attributes.
      
      Attributes:
      
      optionType:   allows to define a type for the option like pre or post option
      name:         the name of the option
      language:     the language of the value
      value:        the value of the option
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AdminViewAttributeOptions : public plmxml_api::Object
{
public:
     
    //! Default constructor
    AdminViewAttributeOptions( );
     
    //! Constructs a AdminViewAttributeOptions with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AdminViewAttributeOptions( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AdminViewAttributeOptions();

private:

	//! Assignment operator
	AdminViewAttributeOptions& operator=( const AdminViewAttributeOptions& iSrc );

	//! Copy constructor
	AdminViewAttributeOptions( const AdminViewAttributeOptions& original );
     
public:

	//! Get Value of this AdminViewAttributeOptions
	plmxml_api::String GetValue() const;

	//! Set Value of this AdminViewAttributeOptions
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Get Name of this AdminViewAttributeOptions
	plmxml_api::String GetName() const;

	//! Set Name of this AdminViewAttributeOptions
	plmxml_api::Result SetName( const plmxml_api::String &s );
	
	//! Check if Name is set
	plmxml_api::logical HasName( ) const;
	
	//! Unset Name
	plmxml_api::Result UnsetName( );

	//! Get Language of this AdminViewAttributeOptions
	plmxml_api::String GetLanguage() const;

	//! Set Language of this AdminViewAttributeOptions
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Get OptionType of this AdminViewAttributeOptions
	plmxml_api::String GetOptionType() const;

	//! Set OptionType of this AdminViewAttributeOptions
	plmxml_api::Result SetOptionType( const plmxml_api::String &s );
	
	//! Check if OptionType is set
	plmxml_api::logical HasOptionType( ) const;
	
	//! Unset OptionType
	plmxml_api::Result UnsetOptionType( );
 
// <PLMXML_UserCode type="functionHeaderAdminViewAttributeOptions" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAdminViewAttributeOptions;


////////////////////////////////////////////////////////////////////////////////////
//! AdminViewAttribute class
/*!
\verbatim

      This type holds the attributes of Classification views.
          
      Attributes:
      
      attributeId:  unique id of the attribute that needs to exist in the class the view belongs to.
      isMandatory:  indicates that the value for this attribute is mandotory while
                    creating instances of a class the view belongs to.
      isProtected:  indicates that the values of this attribute are protected.
      hasLocalDefaultValue: if true this attribute overwrites the default value from 
                    the class attribute      
      isAutoComputed: Whether the values of the attribute are automatically
                      computed.

      Elements:
      
      PreOptions:   Options to configure the UI before the actual field for the attribute. 
                                  E.g. start grouping in a titled frame
      Options:      Options to configure the UI appearence af the attribute field
      PostOptions:  Options to configure the UI after the actual field for the attribute.  
                                  E.g. end grouping in a titled frame
      DefaultValue: Default value in metric units for the attribute.
      AltDefaultValue: Default value in english units for the attribute.
      MinValue:       Minimum value for the attribute in metric units.
      MaxValue:       Maximum value for the attribute in metric units.
      AltMinValue:    Minimum value for the attribute in English units.
      AltMaxValue:    Maximum value for the attribute in English units.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AdminViewAttribute : public plmxml_api::Object
{
public:
     
    //! Default constructor
    AdminViewAttribute( );
     
    //! Constructs a AdminViewAttribute with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AdminViewAttribute( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AdminViewAttribute();

private:

	//! Assignment operator
	AdminViewAttribute& operator=( const AdminViewAttribute& iSrc );

	//! Copy constructor
	AdminViewAttribute( const AdminViewAttribute& original );
     
public:

	//! Set IsProtected
	plmxml_api::Result SetIsProtected( plmxml_api::logical arg );

	//! Get IsProtected
	plmxml_api::logical GetIsProtected() const;

	//! Check if IsProtected is set
	plmxml_api::logical HasIsProtected() const;

	//! Unset IsProtected
	plmxml_api::Result UnsetIsProtected();

	//! Set IsAutoComputed
	plmxml_api::Result SetIsAutoComputed( plmxml_api::logical arg );

	//! Get IsAutoComputed
	plmxml_api::logical GetIsAutoComputed() const;

	//! Check if IsAutoComputed is set
	plmxml_api::logical HasIsAutoComputed() const;

	//! Unset IsAutoComputed
	plmxml_api::Result UnsetIsAutoComputed();

	//! Set IsMandatory
	plmxml_api::Result SetIsMandatory( plmxml_api::logical arg );

	//! Get IsMandatory
	plmxml_api::logical GetIsMandatory() const;

	//! Check if IsMandatory is set
	plmxml_api::logical HasIsMandatory() const;

	//! Unset IsMandatory
	plmxml_api::Result UnsetIsMandatory();

	//! Set HasLocalDefaultValue
	plmxml_api::Result SetHasLocalDefaultValue( plmxml_api::logical arg );

	//! Get HasLocalDefaultValue
	plmxml_api::logical GetHasLocalDefaultValue() const;

	//! Check if HasLocalDefaultValue is set
	plmxml_api::logical HasHasLocalDefaultValue() const;

	//! Unset HasLocalDefaultValue
	plmxml_api::Result UnsetHasLocalDefaultValue();

	//! Set AttributeId
	plmxml_api::Result SetAttributeId( int arg );
     
	//! Get AttributeId
	int GetAttributeId() const;
     
	//! Check if AttributeId is set
	plmxml_api::logical HasAttributeId() const;
     
	//! Unset AttributeId
	plmxml_api::Result UnsetAttributeId();

	//! Add PreOptions child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	AdminViewAttributeOptions *AddPreOptions();
     
	//! Add 'arg' as PreOptions child element to this AdminViewAttribute.
	plmxml_api::Result AddPreOptions( AdminViewAttributeOptions *arg );

	//! Detach and delete all PreOptions child elements.
	void DeletePreOptions();
     
	//! Get number of PreOptions child elements.
	int NumberOfPreOptions() const;
     
	//! Get i'th PreOptions child element.
	AdminViewAttributeOptions *GetPreOptions( int i ) const;
     
	//! Get all PreOptions child element as an array
	void GetPreOptions( plmxml_api::Array<AdminViewAttributeOptions*> &array ) const;
	     
	//! Detach and delete i'th PreOptions child element
	void DeletePreOptions( int i );
     
	//! Detach and delete 'arg' if it's one of the PreOptions child elements
	void DeletePreOptions( AdminViewAttributeOptions *arg );

	//! Add Options child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	AdminViewAttributeOptions *AddOptions();
     
	//! Add 'arg' as Options child element to this AdminViewAttribute.
	plmxml_api::Result AddOptions( AdminViewAttributeOptions *arg );

	//! Detach and delete all Options child elements.
	void DeleteOptions();
     
	//! Get number of Options child elements.
	int NumberOfOptions() const;
     
	//! Get i'th Options child element.
	AdminViewAttributeOptions *GetOptions( int i ) const;
     
	//! Get all Options child element as an array
	void GetOptions( plmxml_api::Array<AdminViewAttributeOptions*> &array ) const;
	     
	//! Detach and delete i'th Options child element
	void DeleteOptions( int i );
     
	//! Detach and delete 'arg' if it's one of the Options child elements
	void DeleteOptions( AdminViewAttributeOptions *arg );

	//! Add PostOptions child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	AdminViewAttributeOptions *AddPostOptions();
     
	//! Add 'arg' as PostOptions child element to this AdminViewAttribute.
	plmxml_api::Result AddPostOptions( AdminViewAttributeOptions *arg );

	//! Detach and delete all PostOptions child elements.
	void DeletePostOptions();
     
	//! Get number of PostOptions child elements.
	int NumberOfPostOptions() const;
     
	//! Get i'th PostOptions child element.
	AdminViewAttributeOptions *GetPostOptions( int i ) const;
     
	//! Get all PostOptions child element as an array
	void GetPostOptions( plmxml_api::Array<AdminViewAttributeOptions*> &array ) const;
	     
	//! Detach and delete i'th PostOptions child element
	void DeletePostOptions( int i );
     
	//! Detach and delete 'arg' if it's one of the PostOptions child elements
	void DeletePostOptions( AdminViewAttributeOptions *arg );

	//! Add DefaultValue child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddDefaultValue();
     
	//! Add 'arg' as DefaultValue child element to this AdminViewAttribute.
	plmxml_api::Result AddDefaultValue( Value *arg );

	//! Detach and delete all DefaultValue child elements.
	void DeleteDefaultValues();
     
	//! Get number of DefaultValue child elements.
	int NumberOfDefaultValues() const;
     
	//! Get i'th DefaultValue child element.
	Value *GetDefaultValue( int i ) const;
     
	//! Get all DefaultValue child element as an array
	void GetDefaultValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th DefaultValue child element
	void DeleteDefaultValue( int i );
     
	//! Detach and delete 'arg' if it's one of the DefaultValue child elements
	void DeleteDefaultValue( Value *arg );

	//! Add AltDefaultValue child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltDefaultValue();
     
	//! Add 'arg' as AltDefaultValue child element to this AdminViewAttribute.
	plmxml_api::Result AddAltDefaultValue( Value *arg );

	//! Detach and delete all AltDefaultValue child elements.
	void DeleteAltDefaultValues();
     
	//! Get number of AltDefaultValue child elements.
	int NumberOfAltDefaultValues() const;
     
	//! Get i'th AltDefaultValue child element.
	Value *GetAltDefaultValue( int i ) const;
     
	//! Get all AltDefaultValue child element as an array
	void GetAltDefaultValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltDefaultValue child element
	void DeleteAltDefaultValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltDefaultValue child elements
	void DeleteAltDefaultValue( Value *arg );

	//! Add MinValue child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddMinValue();
     
	//! Add 'arg' as MinValue child element to this AdminViewAttribute.
	plmxml_api::Result AddMinValue( Value *arg );

	//! Detach and delete all MinValue child elements.
	void DeleteMinValues();
     
	//! Get number of MinValue child elements.
	int NumberOfMinValues() const;
     
	//! Get i'th MinValue child element.
	Value *GetMinValue( int i ) const;
     
	//! Get all MinValue child element as an array
	void GetMinValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th MinValue child element
	void DeleteMinValue( int i );
     
	//! Detach and delete 'arg' if it's one of the MinValue child elements
	void DeleteMinValue( Value *arg );

	//! Add MaxValue child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddMaxValue();
     
	//! Add 'arg' as MaxValue child element to this AdminViewAttribute.
	plmxml_api::Result AddMaxValue( Value *arg );

	//! Detach and delete all MaxValue child elements.
	void DeleteMaxValues();
     
	//! Get number of MaxValue child elements.
	int NumberOfMaxValues() const;
     
	//! Get i'th MaxValue child element.
	Value *GetMaxValue( int i ) const;
     
	//! Get all MaxValue child element as an array
	void GetMaxValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th MaxValue child element
	void DeleteMaxValue( int i );
     
	//! Detach and delete 'arg' if it's one of the MaxValue child elements
	void DeleteMaxValue( Value *arg );

	//! Add AltMinValue child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltMinValue();
     
	//! Add 'arg' as AltMinValue child element to this AdminViewAttribute.
	plmxml_api::Result AddAltMinValue( Value *arg );

	//! Detach and delete all AltMinValue child elements.
	void DeleteAltMinValues();
     
	//! Get number of AltMinValue child elements.
	int NumberOfAltMinValues() const;
     
	//! Get i'th AltMinValue child element.
	Value *GetAltMinValue( int i ) const;
     
	//! Get all AltMinValue child element as an array
	void GetAltMinValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltMinValue child element
	void DeleteAltMinValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltMinValue child elements
	void DeleteAltMinValue( Value *arg );

	//! Add AltMaxValue child element to this AdminViewAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddAltMaxValue();
     
	//! Add 'arg' as AltMaxValue child element to this AdminViewAttribute.
	plmxml_api::Result AddAltMaxValue( Value *arg );

	//! Detach and delete all AltMaxValue child elements.
	void DeleteAltMaxValues();
     
	//! Get number of AltMaxValue child elements.
	int NumberOfAltMaxValues() const;
     
	//! Get i'th AltMaxValue child element.
	Value *GetAltMaxValue( int i ) const;
     
	//! Get all AltMaxValue child element as an array
	void GetAltMaxValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th AltMaxValue child element
	void DeleteAltMaxValue( int i );
     
	//! Detach and delete 'arg' if it's one of the AltMaxValue child elements
	void DeleteAltMaxValue( Value *arg );
 
// <PLMXML_UserCode type="functionHeaderAdminViewAttribute" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAdminViewAttribute;


////////////////////////////////////////////////////////////////////////////////////
//! AdminView class
/*!
\verbatim

      The view definition is related to a class. It allows configuration of the appearance
      of a class for certain users and/or groups.
      
      Attributes:
      
      classId:        the id of the class the blongs to
      viewId:         the id of the view (unique within the class)
      ref2classRef:   the reference to the class
      type:           the type of the view (e.g defaultView,user or group )
      HistoryAttributes
      
      Elements:
      
      Name:           Display name of the view
      ShortName:      A short display name
      UserData1:      User specific data
      UserData2:      User specific data
      Description:    A description of the view tat might be shown to the user
      Comment:        A comment field for the maintainer of the view.
      File:           Special values for format are Image, Icon and Template
      GeneralOption:  General Options for the view definition.
      AdminViewAttribute:  The attributes of the view        
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API AdminView : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    AdminView( );
     
    //! Constructs a AdminView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AdminView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AdminView();

private:

	//! Assignment operator
	AdminView& operator=( const AdminView& iSrc );

	//! Copy constructor
	AdminView( const AdminView& original );
     
public:

	//! Get ModifiedUser of this AdminView
	plmxml_api::String GetModifiedUser() const;

	//! Set ModifiedUser of this AdminView
	plmxml_api::Result SetModifiedUser( const plmxml_api::String &s );
	
	//! Check if ModifiedUser is set
	plmxml_api::logical HasModifiedUser( ) const;
	
	//! Unset ModifiedUser
	plmxml_api::Result UnsetModifiedUser( );

	//! Get ModifiedDate of this AdminView
	plmxml_api::String GetModifiedDate() const;

	//! Set ModifiedDate of this AdminView
	plmxml_api::Result SetModifiedDate( const plmxml_api::String &s );
	
	//! Check if ModifiedDate is set
	plmxml_api::logical HasModifiedDate( ) const;
	
	//! Unset ModifiedDate
	plmxml_api::Result UnsetModifiedDate( );

	//! Get ViewId of this AdminView
	plmxml_api::String GetViewId() const;

	//! Set ViewId of this AdminView
	plmxml_api::Result SetViewId( const plmxml_api::String &s );
	
	//! Check if ViewId is set
	plmxml_api::logical HasViewId( ) const;
	
	//! Unset ViewId
	plmxml_api::Result UnsetViewId( );

	//! Get ClassId of this AdminView
	plmxml_api::String GetClassId() const;

	//! Set ClassId of this AdminView
	plmxml_api::Result SetClassId( const plmxml_api::String &s );
	
	//! Check if ClassId is set
	plmxml_api::logical HasClassId( ) const;
	
	//! Unset ClassId
	plmxml_api::Result UnsetClassId( );

	//! Get CreationDate of this AdminView
	plmxml_api::String GetCreationDate() const;

	//! Set CreationDate of this AdminView
	plmxml_api::Result SetCreationDate( const plmxml_api::String &s );
	
	//! Check if CreationDate is set
	plmxml_api::logical HasCreationDate( ) const;
	
	//! Unset CreationDate
	plmxml_api::Result UnsetCreationDate( );

	//! Set reference to Ref2class using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRef2classRef( plmxml60::IdObject *arg );

	//! Clear reference to Ref2class
	void RemoveRef2classRef( );

	//! Find a plmxml60::IdObject referenced by Ref2class
	plmxml60::IdObject *ResolveRef2classRef( plmxml_api::Configuration* config = NULL );

	//! Get Ref2class reference
	plmxml_api::String GetRef2classId() const;

	//! Set Ref2class reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRef2classId( const plmxml_api::String& u );
	
	//! Check if Ref2class is set
	plmxml_api::logical HasRef2classRef( ) const;

	//! Get CreationUser of this AdminView
	plmxml_api::String GetCreationUser() const;

	//! Set CreationUser of this AdminView
	plmxml_api::Result SetCreationUser( const plmxml_api::String &s );
	
	//! Check if CreationUser is set
	plmxml_api::logical HasCreationUser( ) const;
	
	//! Unset CreationUser
	plmxml_api::Result UnsetCreationUser( );

	//! Set Type
	plmxml_api::Result SetType( const eType& arg );

	//! Get Type
	eType GetType() const;

	//! Add Name child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Name *AddName();
     
	//! Add 'arg' as Name child element to this AdminView.
	plmxml_api::Result AddName( Name *arg );

	//! Detach and delete all Name child elements.
	void DeleteNames();
     
	//! Get number of Name child elements.
	int NumberOfNames() const;
     
	//! Get i'th Name child element.
	Name *GetName( int i ) const;
     
	//! Get all Name child element as an array
	void GetNames( plmxml_api::Array<Name*> &array ) const;
	     
	//! Detach and delete i'th Name child element
	void DeleteName( int i );
     
	//! Detach and delete 'arg' if it's one of the Name child elements
	void DeleteName( Name *arg );

	//! Add ShortName child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ShortName *AddShortName();
     
	//! Add 'arg' as ShortName child element to this AdminView.
	plmxml_api::Result AddShortName( ShortName *arg );

	//! Detach and delete all ShortName child elements.
	void DeleteShortNames();
     
	//! Get number of ShortName child elements.
	int NumberOfShortNames() const;
     
	//! Get i'th ShortName child element.
	ShortName *GetShortName( int i ) const;
     
	//! Get all ShortName child element as an array
	void GetShortNames( plmxml_api::Array<ShortName*> &array ) const;
	     
	//! Detach and delete i'th ShortName child element
	void DeleteShortName( int i );
     
	//! Detach and delete 'arg' if it's one of the ShortName child elements
	void DeleteShortName( ShortName *arg );

	//! Add UserData1 child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData1();
     
	//! Add 'arg' as UserData1 child element to this AdminView.
	plmxml_api::Result AddUserData1( UserData *arg );

	//! Detach and delete all UserData1 child elements.
	void DeleteUserData1s();
     
	//! Get number of UserData1 child elements.
	int NumberOfUserData1s() const;
     
	//! Get i'th UserData1 child element.
	UserData *GetUserData1( int i ) const;
     
	//! Get all UserData1 child element as an array
	void GetUserData1s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData1 child element
	void DeleteUserData1( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData1 child elements
	void DeleteUserData1( UserData *arg );

	//! Add UserData2 child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserData *AddUserData2();
     
	//! Add 'arg' as UserData2 child element to this AdminView.
	plmxml_api::Result AddUserData2( UserData *arg );

	//! Detach and delete all UserData2 child elements.
	void DeleteUserData2s();
     
	//! Get number of UserData2 child elements.
	int NumberOfUserData2s() const;
     
	//! Get i'th UserData2 child element.
	UserData *GetUserData2( int i ) const;
     
	//! Get all UserData2 child element as an array
	void GetUserData2s( plmxml_api::Array<UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData2 child element
	void DeleteUserData2( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData2 child elements
	void DeleteUserData2( UserData *arg );

	//! Add Description child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Description *AddDescription();
     
	//! Add 'arg' as Description child element to this AdminView.
	plmxml_api::Result AddDescription( Description *arg );

	//! Detach and delete all Description child elements.
	void DeleteDescriptions();
     
	//! Get number of Description child elements.
	int NumberOfDescriptions() const;
     
	//! Get i'th Description child element.
	Description *GetDescription( int i ) const;
     
	//! Get all Description child element as an array
	void GetDescriptions( plmxml_api::Array<Description*> &array ) const;
	     
	//! Detach and delete i'th Description child element
	void DeleteDescription( int i );
     
	//! Detach and delete 'arg' if it's one of the Description child elements
	void DeleteDescription( Description *arg );

	//! Add Comment child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Comment *AddComment();
     
	//! Add 'arg' as Comment child element to this AdminView.
	plmxml_api::Result AddComment( Comment *arg );

	//! Detach and delete all Comment child elements.
	void DeleteComments();
     
	//! Get number of Comment child elements.
	int NumberOfComments() const;
     
	//! Get i'th Comment child element.
	Comment *GetComment( int i ) const;
     
	//! Get all Comment child element as an array
	void GetComments( plmxml_api::Array<Comment*> &array ) const;
	     
	//! Detach and delete i'th Comment child element
	void DeleteComment( int i );
     
	//! Detach and delete 'arg' if it's one of the Comment child elements
	void DeleteComment( Comment *arg );

	//! Add File child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	File *AddFile();
     
	//! Add 'arg' as File child element to this AdminView.
	plmxml_api::Result AddFile( File *arg );

	//! Detach and delete all File child elements.
	void DeleteFiles();
     
	//! Get number of File child elements.
	int NumberOfFiles() const;
     
	//! Get i'th File child element.
	File *GetFile( int i ) const;
     
	//! Get all File child element as an array
	void GetFiles( plmxml_api::Array<File*> &array ) const;
	     
	//! Detach and delete i'th File child element
	void DeleteFile( int i );
     
	//! Detach and delete 'arg' if it's one of the File child elements
	void DeleteFile( File *arg );

	//! Add GeneralOption child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GeneralOption *AddGeneralOption();
     
	//! Add 'arg' as GeneralOption child element to this AdminView.
	plmxml_api::Result AddGeneralOption( GeneralOption *arg );

	//! Detach and delete all GeneralOption child elements.
	void DeleteGeneralOptions();
     
	//! Get number of GeneralOption child elements.
	int NumberOfGeneralOptions() const;
     
	//! Get i'th GeneralOption child element.
	GeneralOption *GetGeneralOption( int i ) const;
     
	//! Get all GeneralOption child element as an array
	void GetGeneralOptions( plmxml_api::Array<GeneralOption*> &array ) const;
	     
	//! Detach and delete i'th GeneralOption child element
	void DeleteGeneralOption( int i );
     
	//! Detach and delete 'arg' if it's one of the GeneralOption child elements
	void DeleteGeneralOption( GeneralOption *arg );

	//! Add AdminViewAttribute child element to this AdminView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	AdminViewAttribute *AddAdminViewAttribute();
     
	//! Add 'arg' as AdminViewAttribute child element to this AdminView.
	plmxml_api::Result AddAdminViewAttribute( AdminViewAttribute *arg );

	//! Detach and delete all AdminViewAttribute child elements.
	void DeleteAdminViewAttributes();
     
	//! Get number of AdminViewAttribute child elements.
	int NumberOfAdminViewAttributes() const;
     
	//! Get i'th AdminViewAttribute child element.
	AdminViewAttribute *GetAdminViewAttribute( int i ) const;
     
	//! Get all AdminViewAttribute child element as an array
	void GetAdminViewAttributes( plmxml_api::Array<AdminViewAttribute*> &array ) const;
	     
	//! Detach and delete i'th AdminViewAttribute child element
	void DeleteAdminViewAttribute( int i );
     
	//! Detach and delete 'arg' if it's one of the AdminViewAttribute child elements
	void DeleteAdminViewAttribute( AdminViewAttribute *arg );
 
// <PLMXML_UserCode type="functionHeaderAdminView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassAdminView;


////////////////////////////////////////////////////////////////////////////////////
//! UserClassAttribute class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API UserClassAttribute : public AbstractClassAttribute
{
public:
     
    //! Default constructor
    UserClassAttribute( );
     
    //! Constructs a UserClassAttribute with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UserClassAttribute( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UserClassAttribute();

private:

	//! Assignment operator
	UserClassAttribute& operator=( const UserClassAttribute& iSrc );

	//! Copy constructor
	UserClassAttribute( const UserClassAttribute& original );
     
public:

	//! Get Classid of this UserClassAttribute
	plmxml_api::String GetClassid() const;

	//! Set Classid of this UserClassAttribute
	plmxml_api::Result SetClassid( const plmxml_api::String &s );
	
	//! Check if Classid is set
	plmxml_api::logical HasClassid( ) const;
	
	//! Unset Classid
	plmxml_api::Result UnsetClassid( );

	//! Add Name child element to this UserClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Name *AddName();
     
	//! Add 'arg' as Name child element to this UserClassAttribute.
	plmxml_api::Result AddName( Name *arg );

	//! Detach and delete all Name child elements.
	void DeleteNames();
     
	//! Get number of Name child elements.
	int NumberOfNames() const;
     
	//! Get i'th Name child element.
	Name *GetName( int i ) const;
     
	//! Get all Name child element as an array
	void GetNames( plmxml_api::Array<Name*> &array ) const;
	     
	//! Detach and delete i'th Name child element
	void DeleteName( int i );
     
	//! Detach and delete 'arg' if it's one of the Name child elements
	void DeleteName( Name *arg );

	//! Add ShortName child element to this UserClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ShortName *AddShortName();
     
	//! Add 'arg' as ShortName child element to this UserClassAttribute.
	plmxml_api::Result AddShortName( ShortName *arg );

	//! Detach and delete all ShortName child elements.
	void DeleteShortNames();
     
	//! Get number of ShortName child elements.
	int NumberOfShortNames() const;
     
	//! Get i'th ShortName child element.
	ShortName *GetShortName( int i ) const;
     
	//! Get all ShortName child element as an array
	void GetShortNames( plmxml_api::Array<ShortName*> &array ) const;
	     
	//! Detach and delete i'th ShortName child element
	void DeleteShortName( int i );
     
	//! Detach and delete 'arg' if it's one of the ShortName child elements
	void DeleteShortName( ShortName *arg );

	//! Add Format child element to this UserClassAttribute. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatUser *AddFormat();
     
	//! Set Format child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFormat( FormatUser *arg );
     
	//! Get Format child element of this UserClassAttribute.
	FormatUser *GetFormat() const;
     
	//! Detach and delete Format child element tree from this UserClassAttribute.
	void DeleteFormat();

	//! Get Unit of this UserClassAttribute
	plmxml_api::String GetUnit() const;

	//! Set Unit of this UserClassAttribute
	plmxml_api::Result SetUnit( const plmxml_api::String &s );
	
	//! Check if Unit is set
	plmxml_api::logical HasUnit( ) const;
	
	//! Unset Unit
	plmxml_api::Result UnsetUnit( );

	//! Add Description child element to this UserClassAttribute. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Description *AddDescription();
     
	//! Add 'arg' as Description child element to this UserClassAttribute.
	plmxml_api::Result AddDescription( Description *arg );

	//! Detach and delete all Description child elements.
	void DeleteDescriptions();
     
	//! Get number of Description child elements.
	int NumberOfDescriptions() const;
     
	//! Get i'th Description child element.
	Description *GetDescription( int i ) const;
     
	//! Get all Description child element as an array
	void GetDescriptions( plmxml_api::Array<Description*> &array ) const;
	     
	//! Detach and delete i'th Description child element
	void DeleteDescription( int i );
     
	//! Detach and delete 'arg' if it's one of the Description child elements
	void DeleteDescription( Description *arg );

	//! Add AltFormat child element to this UserClassAttribute. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FormatUser *AddAltFormat();
     
	//! Set AltFormat child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetAltFormat( FormatUser *arg );
     
	//! Get AltFormat child element of this UserClassAttribute.
	FormatUser *GetAltFormat() const;
     
	//! Detach and delete AltFormat child element tree from this UserClassAttribute.
	void DeleteAltFormat();
 
// <PLMXML_UserCode type="functionHeaderUserClassAttribute" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassUserClassAttribute;


////////////////////////////////////////////////////////////////////////////////////
//! UserClass class
/*!
\verbatim

      Class definition as used by the end user. It combines the class, view, dictionary and keylov 
      definition into one. This definition can only be used for readonly purposes.
      
      Elements:
      
      Parent:
      Attribute:
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API UserClass : public AbstractClass
{
public:
     
    //! Default constructor
    UserClass( );
     
    //! Constructs a UserClass with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UserClass( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UserClass();

private:

	//! Assignment operator
	UserClass& operator=( const UserClass& iSrc );

	//! Copy constructor
	UserClass( const UserClass& original );
     
public:

	//! Add Parent child element to this UserClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Parent *AddParent();
     
	//! Add 'arg' as Parent child element to this UserClass.
	plmxml_api::Result AddParent( Parent *arg );

	//! Detach and delete all Parent child elements.
	void DeleteParents();
     
	//! Get number of Parent child elements.
	int NumberOfParents() const;
     
	//! Get i'th Parent child element.
	Parent *GetParent( int i ) const;
     
	//! Get all Parent child element as an array
	void GetParents( plmxml_api::Array<Parent*> &array ) const;
	     
	//! Detach and delete i'th Parent child element
	void DeleteParent( int i );
     
	//! Detach and delete 'arg' if it's one of the Parent child elements
	void DeleteParent( Parent *arg );

	//! Add Attribute child element to this UserClass. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserClassAttribute *AddUserAttribute();
     
	//! Add 'arg' as Attribute child element to this UserClass.
	plmxml_api::Result AddUserAttribute( UserClassAttribute *arg );

	//! Detach and delete all Attribute child elements.
	void DeleteUserAttributes();
     
	//! Get number of Attribute child elements.
	int NumberOfUserAttributes() const;
     
	//! Get i'th Attribute child element.
	UserClassAttribute *GetUserAttribute( int i ) const;
     
	//! Get all Attribute child element as an array
	void GetUserAttributes( plmxml_api::Array<UserClassAttribute*> &array ) const;
	     
	//! Detach and delete i'th Attribute child element
	void DeleteUserAttribute( int i );
     
	//! Detach and delete 'arg' if it's one of the Attribute child elements
	void DeleteUserAttribute( UserClassAttribute *arg );
 
// <PLMXML_UserCode type="functionHeaderUserClass" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassUserClass;


////////////////////////////////////////////////////////////////////////////////////
//! ICOProperty class
/*!
\verbatim

      Attributes:
      
      attributeId:
      language:
      icoRef:             Holds the reference to another ICO if the the property is of type 
                          reference to ICO.
      
      Elements:

      Value:              A property might have single or multiple values
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API ICOProperty : public plmxml_api::Object
{
public:
     
    //! Default constructor
    ICOProperty( );
     
    //! Constructs a ICOProperty with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ICOProperty( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ICOProperty();

private:

	//! Assignment operator
	ICOProperty& operator=( const ICOProperty& iSrc );

	//! Copy constructor
	ICOProperty( const ICOProperty& original );
     
public:

	//! Set reference to Ico using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetIcoRef( plmxml60::IdObject *arg );

	//! Clear reference to Ico
	void RemoveIcoRef( );

	//! Find a plmxml60::IdObject referenced by Ico
	plmxml60::IdObject *ResolveIcoRef( plmxml_api::Configuration* config = NULL );

	//! Get Ico reference
	plmxml_api::String GetIcoId() const;

	//! Set Ico reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetIcoId( const plmxml_api::String& u );
	
	//! Check if Ico is set
	plmxml_api::logical HasIcoRef( ) const;

	//! Set AttributeId
	plmxml_api::Result SetAttributeId( int arg );
     
	//! Get AttributeId
	int GetAttributeId() const;
     
	//! Check if AttributeId is set
	plmxml_api::logical HasAttributeId() const;
     
	//! Unset AttributeId
	plmxml_api::Result UnsetAttributeId();

	//! Get Language of this ICOProperty
	plmxml_api::String GetLanguage() const;

	//! Set Language of this ICOProperty
	plmxml_api::Result SetLanguage( const plmxml_api::String &s );
	
	//! Check if Language is set
	plmxml_api::logical HasLanguage( ) const;
	
	//! Unset Language
	plmxml_api::Result UnsetLanguage( );

	//! Add Value child element to this ICOProperty. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Value *AddValue();
     
	//! Add 'arg' as Value child element to this ICOProperty.
	plmxml_api::Result AddValue( Value *arg );

	//! Detach and delete all Value child elements.
	void DeleteValues();
     
	//! Get number of Value child elements.
	int NumberOfValues() const;
     
	//! Get i'th Value child element.
	Value *GetValue( int i ) const;
     
	//! Get all Value child element as an array
	void GetValues( plmxml_api::Array<Value*> &array ) const;
	     
	//! Detach and delete i'th Value child element
	void DeleteValue( int i );
     
	//! Detach and delete 'arg' if it's one of the Value child elements
	void DeleteValue( Value *arg );
 
// <PLMXML_UserCode type="functionHeaderICOProperty" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassICOProperty;


////////////////////////////////////////////////////////////////////////////////////
//! ICOClassId class
/*!
\verbatim

\endverbatim
*/
class PLMXML_CLASSIFICATION60_API ICOClassId : public plmxml_api::Object
{
public:
     
    //! Default constructor
    ICOClassId( );
     
    //! Constructs a ICOClassId with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ICOClassId( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ICOClassId();

private:

	//! Assignment operator
	ICOClassId& operator=( const ICOClassId& iSrc );

	//! Copy constructor
	ICOClassId( const ICOClassId& original );
     
public:

	//! Set reference to Ref2class using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRef2classRef( plmxml60::IdObject *arg );

	//! Clear reference to Ref2class
	void RemoveRef2classRef( );

	//! Find a plmxml60::IdObject referenced by Ref2class
	plmxml60::IdObject *ResolveRef2classRef( plmxml_api::Configuration* config = NULL );

	//! Get Ref2class reference
	plmxml_api::String GetRef2classId() const;

	//! Set Ref2class reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRef2classId( const plmxml_api::String& u );
	
	//! Check if Ref2class is set
	plmxml_api::logical HasRef2classRef( ) const;

	//! Get SubclassId of this ICOClassId
	plmxml_api::String GetSubclassId() const;

	//! Set SubclassId of this ICOClassId
	plmxml_api::Result SetSubclassId( const plmxml_api::String &s );
	
	//! Check if SubclassId is set
	plmxml_api::logical HasSubclassId( ) const;
	
	//! Unset SubclassId
	plmxml_api::Result UnsetSubclassId( );
 
// <PLMXML_UserCode type="functionHeaderICOClassId" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassICOClassId;


////////////////////////////////////////////////////////////////////////////////////
//! ICO class
/*!
\verbatim

      The view definition is related to a class. It allows configuration of the appearance
      of a class for certain users and/or groups.
      
      Attributes:
      
      icoId:              The id of the ICO. In case there is no wsoRef specified the icoId is treated 
                          to be unique unless a corresponding workspace object exists in the target database
      relatedRefs:        References to other ICOs classifying the same WSO
      wsoRef:             Reference to the classified object if defined in the XML document
      unitBase:           Indicates the unit base. english and metric mean english and metric unit bases
                          respectively. inherited means that the unit base is inherited from the containing
                          AdminClass.

      HistoryAttributes:
      
      Elements:

      ClassId:            The ClassId defines to which class this ICO belongs. The ref2Class attribute 
                          is set if that class is defined within the same plmxml document. On import that 
                          class definition has to be successfully imported to allow the ICO to be imported.
      Parent:             This element lists ALL parents of the class the ICO is stored in. The primary 
                          use is to support a mapping into a different class hierarchy without the transfer 
                          of the class definition to get the isMemberOf information. On import this 
                          information will be ignored.
      Property:           The actual format of  property value is defined by the attribute definition 
                          referenced by attributeId
      File: 
      GeneralOption:      General Options for the ICO definition.
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API ICO : public plmxml60::AttribOwner
{
public:
     
    //! Default constructor
    ICO( );
     
    //! Constructs a ICO with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ICO( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ICO();

private:

	//! Assignment operator
	ICO& operator=( const ICO& iSrc );

	//! Copy constructor
	ICO( const ICO& original );
     
public:

	//! Set UnitBase
	plmxml_api::Result SetUnitBase( const eUnitBaseType& arg );

	//! Get UnitBase
	eUnitBaseType GetUnitBase() const;

	//! Get ModifiedDate of this ICO
	plmxml_api::String GetModifiedDate() const;

	//! Set ModifiedDate of this ICO
	plmxml_api::Result SetModifiedDate( const plmxml_api::String &s );
	
	//! Check if ModifiedDate is set
	plmxml_api::logical HasModifiedDate( ) const;
	
	//! Unset ModifiedDate
	plmxml_api::Result UnsetModifiedDate( );

	//! Get CreationUser of this ICO
	plmxml_api::String GetCreationUser() const;

	//! Set CreationUser of this ICO
	plmxml_api::Result SetCreationUser( const plmxml_api::String &s );
	
	//! Check if CreationUser is set
	plmxml_api::logical HasCreationUser( ) const;
	
	//! Unset CreationUser
	plmxml_api::Result UnsetCreationUser( );

	//! Set reference to Wso using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetWsoRef( plmxml60::IdObject *arg );

	//! Clear reference to Wso
	void RemoveWsoRef( );

	//! Find a plmxml60::IdObject referenced by Wso
	plmxml60::IdObject *ResolveWsoRef( plmxml_api::Configuration* config = NULL );

	//! Get Wso reference
	plmxml_api::String GetWsoId() const;

	//! Set Wso reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetWsoId( const plmxml_api::String& u );
	
	//! Check if Wso is set
	plmxml_api::logical HasWsoRef( ) const;

	//! Get CreationDate of this ICO
	plmxml_api::String GetCreationDate() const;

	//! Set CreationDate of this ICO
	plmxml_api::Result SetCreationDate( const plmxml_api::String &s );
	
	//! Check if CreationDate is set
	plmxml_api::logical HasCreationDate( ) const;
	
	//! Unset CreationDate
	plmxml_api::Result UnsetCreationDate( );

	//! Get ModifiedUser of this ICO
	plmxml_api::String GetModifiedUser() const;

	//! Set ModifiedUser of this ICO
	plmxml_api::Result SetModifiedUser( const plmxml_api::String &s );
	
	//! Check if ModifiedUser is set
	plmxml_api::logical HasModifiedUser( ) const;
	
	//! Unset ModifiedUser
	plmxml_api::Result UnsetModifiedUser( );

	//! Get IcoId of this ICO
	plmxml_api::String GetIcoId() const;

	//! Set IcoId of this ICO
	plmxml_api::Result SetIcoId( const plmxml_api::String &s );
	
	//! Check if IcoId is set
	plmxml_api::logical HasIcoId( ) const;
	
	//! Unset IcoId
	plmxml_api::Result UnsetIcoId( );

	//! Get number of references in Related array
	int NumberOfRelatedRefs() const;
     
	//! Add reference to 'arg' to Related array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddRelatedRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Related array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddRelatedId( const plmxml_api::String &u );
     
	//! Set i'th reference in Related array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRelatedRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Related array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRelatedId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Related array and return an object it points to.
	plmxml60::IdObject *ResolveRelatedRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Related array and return objects they point to.
	void ResolveRelatedRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Related array as plmxml_api::String
	plmxml_api::String GetRelatedId( int i ) const;
     
	//! Get all references in Related array as an array of plmxml_api::String
	void GetRelatedIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Related array.
	void RemoveRelatedRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Related array.
	void RemoveRelatedRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Related array.
	void RemoveRelatedRef( plmxml60::IdObject *arg );
     
	//! Remove all references Related array.
	void RemoveRelatedRefs();
	
	//! Check if Related is set
	plmxml_api::logical HasRelatedRefs( ) const;

	//! Add ClassId child element to this ICO. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ICOClassId *AddClassId();
     
	//! Set ClassId child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClassId( ICOClassId *arg );
     
	//! Get ClassId child element of this ICO.
	ICOClassId *GetClassId() const;
     
	//! Detach and delete ClassId child element tree from this ICO.
	void DeleteClassId();

	//! Add Parent child element to this ICO. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Parent *AddParent();
     
	//! Add 'arg' as Parent child element to this ICO.
	plmxml_api::Result AddParent( Parent *arg );

	//! Detach and delete all Parent child elements.
	void DeleteParents();
     
	//! Get number of Parent child elements.
	int NumberOfParents() const;
     
	//! Get i'th Parent child element.
	Parent *GetParent( int i ) const;
     
	//! Get all Parent child element as an array
	void GetParents( plmxml_api::Array<Parent*> &array ) const;
	     
	//! Detach and delete i'th Parent child element
	void DeleteParent( int i );
     
	//! Detach and delete 'arg' if it's one of the Parent child elements
	void DeleteParent( Parent *arg );

	//! Add Property child element to this ICO. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ICOProperty *AddProperty();
     
	//! Add 'arg' as Property child element to this ICO.
	plmxml_api::Result AddProperty( ICOProperty *arg );

	//! Detach and delete all Property child elements.
	void DeleteProperties();
     
	//! Get number of Property child elements.
	int NumberOfProperties() const;
     
	//! Get i'th Property child element.
	ICOProperty *GetProperty( int i ) const;
     
	//! Get all Property child element as an array
	void GetProperties( plmxml_api::Array<ICOProperty*> &array ) const;
	     
	//! Detach and delete i'th Property child element
	void DeleteProperty( int i );
     
	//! Detach and delete 'arg' if it's one of the Property child elements
	void DeleteProperty( ICOProperty *arg );

	//! Add File child element to this ICO. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	File *AddFile();
     
	//! Add 'arg' as File child element to this ICO.
	plmxml_api::Result AddFile( File *arg );

	//! Detach and delete all File child elements.
	void DeleteFiles();
     
	//! Get number of File child elements.
	int NumberOfFiles() const;
     
	//! Get i'th File child element.
	File *GetFile( int i ) const;
     
	//! Get all File child element as an array
	void GetFiles( plmxml_api::Array<File*> &array ) const;
	     
	//! Detach and delete i'th File child element
	void DeleteFile( int i );
     
	//! Detach and delete 'arg' if it's one of the File child elements
	void DeleteFile( File *arg );

	//! Add GeneralOption child element to this ICO. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GeneralOption *AddGeneralOption();
     
	//! Add 'arg' as GeneralOption child element to this ICO.
	plmxml_api::Result AddGeneralOption( GeneralOption *arg );

	//! Detach and delete all GeneralOption child elements.
	void DeleteGeneralOptions();
     
	//! Get number of GeneralOption child elements.
	int NumberOfGeneralOptions() const;
     
	//! Get i'th GeneralOption child element.
	GeneralOption *GetGeneralOption( int i ) const;
     
	//! Get all GeneralOption child element as an array
	void GetGeneralOptions( plmxml_api::Array<GeneralOption*> &array ) const;
	     
	//! Detach and delete i'th GeneralOption child element
	void DeleteGeneralOption( int i );
     
	//! Detach and delete 'arg' if it's one of the GeneralOption child elements
	void DeleteGeneralOption( GeneralOption *arg );
 
// <PLMXML_UserCode type="functionHeaderICO" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassICO;


////////////////////////////////////////////////////////////////////////////////////
//! Classification class
/*!
\verbatim

      Elements of this type relate their parent element to its classification 
      information (ICO).
      
      Attributes:
      
      icoRefs:          Reference to ICO elements. 
      
\endverbatim
*/
class PLMXML_CLASSIFICATION60_API Classification : public plmxml60::Attribute
{
public:
     
    //! Default constructor
    Classification( );
     
    //! Constructs a Classification with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Classification( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Classification();

private:

	//! Assignment operator
	Classification& operator=( const Classification& iSrc );

	//! Copy constructor
	Classification( const Classification& original );
     
public:

	//! Get number of URIs in Ico
	int NumberOfIcoURIs() const;

	//! Get i'th URI in Ico
	plmxml_api::String GetIcoURI( int i ) const;

	//! Add a URI to Ico array. Call ResolveIcoURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddIcoURI( const plmxml_api::String& u );

	//! Set i'th URI in Ico array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetIcoURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Ico URI. Does not resolve the URI.
	plmxml_api::Result GetIcoURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Ico array.
	plmxml_api::Result AddIcoURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Ico array to point to 'handle'.
	plmxml_api::Result SetIcoURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Ico points to.
	plmxml_api::Result ResolveIcoURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Ico array.
	plmxml_api::Result DeleteIcoURI( int i );

	//! Remove all URIs from Ico array.
	plmxml_api::Result DeleteIcoURIs( );
	
	//! Check if Ico is set
	plmxml_api::logical HasIcoURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderClassification" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CLASSIFICATION60_API plmxml_api::plmxmlClass plmxmlClassClassification;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
