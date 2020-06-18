/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 11:02:02
// 
// Schema:	PLMXMLClassLibrarySchema.xsd
// Data:	2013-09-04
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_CL60_H__
#define __PLMXML_CL60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_CL60_EXPORTS
#define PLMXML_CL60_API __declspec(dllexport)
#else
#define PLMXML_CL60_API __declspec(dllimport)
#endif
#else
#define PLMXML_CL60_API
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
//! eSpecRuleEnum class
/*!
Allowed Values:
\verbatim
  eSpecRuleEnumInterfaceConstraint
	"interfaceConstraint"
  eSpecRuleEnumSpecification
	"specification"
  eSpecRuleEnumAction
	"action"
  
\endverbatim
*/
class PLMXML_CL60_API eSpecRuleEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSpecRuleEnum( const char* Type );
     
	//! Constructor
	eSpecRuleEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSpecRuleEnum( );
     
	//! Destructor 
	virtual ~eSpecRuleEnum( );
     
	//! Assign from 'Type'
	const eSpecRuleEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSpecRuleEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SpecRuleEnum
	friend plmxml_api::logical PLMXML_CL60_API operator==( const eSpecRuleEnum& e1, const eSpecRuleEnum& e2 );
     
	//! Compare SpecRuleEnum
	friend plmxml_api::logical PLMXML_CL60_API operator!=( const eSpecRuleEnum& e1, const eSpecRuleEnum& e2 );
};
extern PLMXML_CL60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSpecRuleEnum;
extern PLMXML_CL60_API eSpecRuleEnum eSpecRuleEnumUnset;
extern PLMXML_CL60_API eSpecRuleEnum eSpecRuleEnumInterfaceConstraint;
extern PLMXML_CL60_API eSpecRuleEnum eSpecRuleEnumSpecification;
extern PLMXML_CL60_API eSpecRuleEnum eSpecRuleEnumAction;

////////////////////////////////////////////////////////////////////////////////////
//! eSpecActionEnum class
/*!
Allowed Values:
\verbatim
  eSpecActionEnumAdd
	"add"
  
\endverbatim
*/
class PLMXML_CL60_API eSpecActionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSpecActionEnum( const char* Type );
     
	//! Constructor
	eSpecActionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSpecActionEnum( );
     
	//! Destructor 
	virtual ~eSpecActionEnum( );
     
	//! Assign from 'Type'
	const eSpecActionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSpecActionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SpecActionEnum
	friend plmxml_api::logical PLMXML_CL60_API operator==( const eSpecActionEnum& e1, const eSpecActionEnum& e2 );
     
	//! Compare SpecActionEnum
	friend plmxml_api::logical PLMXML_CL60_API operator!=( const eSpecActionEnum& e1, const eSpecActionEnum& e2 );
};
extern PLMXML_CL60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSpecActionEnum;
extern PLMXML_CL60_API eSpecActionEnum eSpecActionEnumUnset;
extern PLMXML_CL60_API eSpecActionEnum eSpecActionEnumAdd;

////////////////////////////////////////////////////////////////////////////////////
//! eSpecActionSetEnum class
/*!
Allowed Values:
\verbatim
  eSpecActionSetEnumConnectionCompatibility
	"connectionCompatibility"
  eSpecActionSetEnumPostPlacement
	"postPlacement"
  
\endverbatim
*/
class PLMXML_CL60_API eSpecActionSetEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSpecActionSetEnum( const char* Type );
     
	//! Constructor
	eSpecActionSetEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSpecActionSetEnum( );
     
	//! Destructor 
	virtual ~eSpecActionSetEnum( );
     
	//! Assign from 'Type'
	const eSpecActionSetEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSpecActionSetEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SpecActionSetEnum
	friend plmxml_api::logical PLMXML_CL60_API operator==( const eSpecActionSetEnum& e1, const eSpecActionSetEnum& e2 );
     
	//! Compare SpecActionSetEnum
	friend plmxml_api::logical PLMXML_CL60_API operator!=( const eSpecActionSetEnum& e1, const eSpecActionSetEnum& e2 );
};
extern PLMXML_CL60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSpecActionSetEnum;
extern PLMXML_CL60_API eSpecActionSetEnum eSpecActionSetEnumUnset;
extern PLMXML_CL60_API eSpecActionSetEnum eSpecActionSetEnumConnectionCompatibility;
extern PLMXML_CL60_API eSpecActionSetEnum eSpecActionSetEnumPostPlacement;

////////////////////////////////////////////////////////////////////////////////////
//! ClassificationHeader class
/*!
\verbatim

      Classification Header.

      Attributes:

      name:             Inherited from AttribOwner.
      nameRef:          Inherited from AttribOwner. References a multiple
                        language version of name.
      descriptionTextRef: Inherited from AttribOwner. References a multiple
                        language version of description.
      objectId:         The identifier of the derived object.
      subType:          Type of derived element.
      siteRef:          References a Site.

      Sub-elements:

      Description:      Inherited from AttribOwner.
      Property:         Custom node properties.
      
\endverbatim
*/
class PLMXML_CL60_API ClassificationHeader : public AttribOwner
{
public:
     
    //! Default constructor
    ClassificationHeader( );
     
    //! Constructs a ClassificationHeader with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClassificationHeader( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClassificationHeader();

private:

	//! Assignment operator
	ClassificationHeader& operator=( const ClassificationHeader& iSrc );

	//! Copy constructor
	ClassificationHeader( const ClassificationHeader& original );
     
public:

	//! Get Site URI as plmxml_api::String
	plmxml_api::String GetSiteURI() const;

	//! Set Site URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSiteURI( const plmxml_api::String& );
	
	//! Get the handle of Site URI. Does not resolve the URI.
	plmxml_api::Result GetSiteURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Site URI. URI string is unchanged.
	plmxml_api::Result SetSiteURI( const plmxml_api::Handle& );
	
	//! Resolve Site URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSiteURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Site URI. Clears URI string and handle.
	plmxml_api::Result DeleteSiteURI();
	
	//! Check if Site URI is set
	plmxml_api::logical HasSiteURI( ) const;
	

	//! Get SubType of this ClassificationHeader
	plmxml_api::String GetSubType() const;

	//! Set SubType of this ClassificationHeader
	plmxml_api::Result SetSubType( const plmxml_api::String &s );
	
	//! Check if SubType is set
	plmxml_api::logical HasSubType( ) const;
	
	//! Unset SubType
	plmxml_api::Result UnsetSubType( );

	//! Get ObjectId of this ClassificationHeader
	plmxml_api::String GetObjectId() const;

	//! Set ObjectId of this ClassificationHeader
	plmxml_api::Result SetObjectId( const plmxml_api::String &s );
	
	//! Check if ObjectId is set
	plmxml_api::logical HasObjectId( ) const;
	
	//! Unset ObjectId
	plmxml_api::Result UnsetObjectId( );

	//! Add Property child element to this ClassificationHeader. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddProperty();
     
	//! Add 'arg' as Property child element to this ClassificationHeader.
	plmxml_api::Result AddProperty( UserValue *arg );

	//! Detach and delete all Property child elements.
	void DeleteProperties();
     
	//! Get number of Property child elements.
	int NumberOfProperties() const;
     
	//! Get i'th Property child element.
	UserValue *GetProperty( int i ) const;
     
	//! Get all Property child element as an array
	void GetProperties( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th Property child element
	void DeleteProperty( int i );
     
	//! Detach and delete 'arg' if it's one of the Property child elements
	void DeleteProperty( UserValue *arg );
 
// <PLMXML_UserCode type="functionHeaderClassificationHeader" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassClassificationHeader;


////////////////////////////////////////////////////////////////////////////////////
//! ClassLibraryIdentifier class
/*!
\verbatim

      Class Library Identifier.

      Attributes:

      identifier:       String identifier.
      referenceRef:     References the parent Classification Node, if there is
                        one.
      
\endverbatim
*/
class PLMXML_CL60_API ClassLibraryIdentifier : public Attribute
{
public:
     
    //! Default constructor
    ClassLibraryIdentifier( );
     
    //! Constructs a ClassLibraryIdentifier with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClassLibraryIdentifier( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClassLibraryIdentifier();

private:

	//! Assignment operator
	ClassLibraryIdentifier& operator=( const ClassLibraryIdentifier& iSrc );

	//! Copy constructor
	ClassLibraryIdentifier( const ClassLibraryIdentifier& original );
     
public:

	//! Get Reference URI as plmxml_api::String
	plmxml_api::String GetReferenceURI() const;

	//! Set Reference URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReferenceURI( const plmxml_api::String& );
	
	//! Get the handle of Reference URI. Does not resolve the URI.
	plmxml_api::Result GetReferenceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Reference URI. URI string is unchanged.
	plmxml_api::Result SetReferenceURI( const plmxml_api::Handle& );
	
	//! Resolve Reference URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReferenceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Reference URI. Clears URI string and handle.
	plmxml_api::Result DeleteReferenceURI();
	
	//! Check if Reference URI is set
	plmxml_api::logical HasReferenceURI( ) const;
	

	//! Get Identifier of this ClassLibraryIdentifier
	plmxml_api::String GetIdentifier() const;

	//! Set Identifier of this ClassLibraryIdentifier
	plmxml_api::Result SetIdentifier( const plmxml_api::String &s );
	
	//! Check if Identifier is set
	plmxml_api::logical HasIdentifier( ) const;
	
	//! Unset Identifier
	plmxml_api::Result UnsetIdentifier( );
 
// <PLMXML_UserCode type="functionHeaderClassLibraryIdentifier" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassClassLibraryIdentifier;


////////////////////////////////////////////////////////////////////////////////////
//! ClassificationNode class
/*!
\verbatim

      Classification Hierarchy Node.

      Attributes:

      objectId:         Inherited from ClassificationHeader. The identifier of
      sortIndex:        Sort index.
                        the Classification Node.
      leaf:             Whether the Master Node is a leaf node.

      Sub-elements:

      Parent:           Identifies the parent Classification Node, if there is
                        one.
      
\endverbatim
*/
class PLMXML_CL60_API ClassificationNode : public ClassificationHeader
{
public:
     
    //! Default constructor
    ClassificationNode( );
     
    //! Constructs a ClassificationNode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClassificationNode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClassificationNode();

private:

	//! Assignment operator
	ClassificationNode& operator=( const ClassificationNode& iSrc );

	//! Copy constructor
	ClassificationNode( const ClassificationNode& original );
     
public:

	//! Set SortIndex
	plmxml_api::Result SetSortIndex( int arg );
     
	//! Get SortIndex
	int GetSortIndex() const;
     
	//! Check if SortIndex is set
	plmxml_api::logical HasSortIndex() const;
     
	//! Unset SortIndex
	plmxml_api::Result UnsetSortIndex();

	//! Set Leaf
	plmxml_api::Result SetLeaf( plmxml_api::logical arg );

	//! Get Leaf
	plmxml_api::logical GetLeaf() const;

	//! Check if Leaf is set
	plmxml_api::logical HasLeaf() const;

	//! Unset Leaf
	plmxml_api::Result UnsetLeaf();

	//! Add Parent child element to this ClassificationNode. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddParent();
     
	//! Set Parent child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetParent( ClassLibraryIdentifier *arg );
     
	//! Get Parent child element of this ClassificationNode.
	ClassLibraryIdentifier *GetParent() const;
     
	//! Detach and delete Parent child element tree from this ClassificationNode.
	void DeleteParent();
 
// <PLMXML_UserCode type="functionHeaderClassificationNode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassClassificationNode;


////////////////////////////////////////////////////////////////////////////////////
//! GroupNode class
/*!
\verbatim

      Group Node.
      
\endverbatim
*/
class PLMXML_CL60_API GroupNode : public ClassificationNode
{
public:
     
    //! Default constructor
    GroupNode( );
     
    //! Constructs a GroupNode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GroupNode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GroupNode();

private:

	//! Assignment operator
	GroupNode& operator=( const GroupNode& iSrc );

	//! Copy constructor
	GroupNode( const GroupNode& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderGroupNode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassGroupNode;


////////////////////////////////////////////////////////////////////////////////////
//! MasterNode class
/*!
\verbatim

      Master Node.

      Attributes:

      storageClass:     Storage class.
      
\endverbatim
*/
class PLMXML_CL60_API MasterNode : public ClassificationNode
{
public:
     
    //! Default constructor
    MasterNode( );
     
    //! Constructs a MasterNode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MasterNode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MasterNode();

private:

	//! Assignment operator
	MasterNode& operator=( const MasterNode& iSrc );

	//! Copy constructor
	MasterNode( const MasterNode& original );
     
public:

	//! Get StorageClass of this MasterNode
	plmxml_api::String GetStorageClass() const;

	//! Set StorageClass of this MasterNode
	plmxml_api::Result SetStorageClass( const plmxml_api::String &s );
	
	//! Check if StorageClass is set
	plmxml_api::logical HasStorageClass( ) const;
	
	//! Unset StorageClass
	plmxml_api::Result UnsetStorageClass( );
 
// <PLMXML_UserCode type="functionHeaderMasterNode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassMasterNode;


////////////////////////////////////////////////////////////////////////////////////
//! ClassificationMember class
/*!
\verbatim

      Classification Member.

      Attributes:

      objectId:         Inherited from ClassificationHeader. The identifier of
                        the Classification Member.
      objectRef:        References the object in the product structure.
      local:            Whether the classification is local to a Library.

      Sub-elements:

      OwningNode:       Identifies the owning Classification Node in the
                        Classification Hierarchy.
      
\endverbatim
*/
class PLMXML_CL60_API ClassificationMember : public ClassificationHeader
{
public:
     
    //! Default constructor
    ClassificationMember( );
     
    //! Constructs a ClassificationMember with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClassificationMember( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClassificationMember();

private:

	//! Assignment operator
	ClassificationMember& operator=( const ClassificationMember& iSrc );

	//! Copy constructor
	ClassificationMember( const ClassificationMember& original );
     
public:

	//! Set Local
	plmxml_api::Result SetLocal( plmxml_api::logical arg );

	//! Get Local
	plmxml_api::logical GetLocal() const;

	//! Check if Local is set
	plmxml_api::logical HasLocal() const;

	//! Unset Local
	plmxml_api::Result UnsetLocal();

	//! Get Object URI as plmxml_api::String
	plmxml_api::String GetObjectURI() const;

	//! Set Object URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetObjectURI( const plmxml_api::String& );
	
	//! Get the handle of Object URI. Does not resolve the URI.
	plmxml_api::Result GetObjectURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Object URI. URI string is unchanged.
	plmxml_api::Result SetObjectURI( const plmxml_api::Handle& );
	
	//! Resolve Object URI and return an object (handle) it points to.
	plmxml_api::Result ResolveObjectURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Object URI. Clears URI string and handle.
	plmxml_api::Result DeleteObjectURI();
	
	//! Check if Object URI is set
	plmxml_api::logical HasObjectURI( ) const;
	

	//! Add OwningNode child element to this ClassificationMember. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningNode();
     
	//! Set OwningNode child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningNode( ClassLibraryIdentifier *arg );
     
	//! Get OwningNode child element of this ClassificationMember.
	ClassLibraryIdentifier *GetOwningNode() const;
     
	//! Detach and delete OwningNode child element tree from this ClassificationMember.
	void DeleteOwningNode();
 
// <PLMXML_UserCode type="functionHeaderClassificationMember" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassClassificationMember;


////////////////////////////////////////////////////////////////////////////////////
//! Library class
/*!
\verbatim

      Classification Library.

      Attributes:

      objectId:         Inherited from ClassificationHeader. The identifier of
                        the Classification Library.
      libraryType:      The type of the Library.
      disciplineRefs:   A list of references to Disciplines.
      version:          The version of the Classification Library.
      administratorRefs: A list of references to administrative Users.

      Sub-elements:

      Specification:    Identifies a Specification in the Classification
                        Library.
      
\endverbatim
*/
class PLMXML_CL60_API Library : public ClassificationHeader
{
public:
     
    //! Default constructor
    Library( );
     
    //! Constructs a Library with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Library( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Library();

private:

	//! Assignment operator
	Library& operator=( const Library& iSrc );

	//! Copy constructor
	Library( const Library& original );
     
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

	//! Get LibraryType of this Library
	plmxml_api::String GetLibraryType() const;

	//! Set LibraryType of this Library
	plmxml_api::Result SetLibraryType( const plmxml_api::String &s );
	
	//! Check if LibraryType is set
	plmxml_api::logical HasLibraryType( ) const;
	
	//! Unset LibraryType
	plmxml_api::Result UnsetLibraryType( );

	//! Get number of URIs in Administrator
	int NumberOfAdministratorURIs() const;

	//! Get i'th URI in Administrator
	plmxml_api::String GetAdministratorURI( int i ) const;

	//! Add a URI to Administrator array. Call ResolveAdministratorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAdministratorURI( const plmxml_api::String& u );

	//! Set i'th URI in Administrator array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAdministratorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Administrator URI. Does not resolve the URI.
	plmxml_api::Result GetAdministratorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Administrator array.
	plmxml_api::Result AddAdministratorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Administrator array to point to 'handle'.
	plmxml_api::Result SetAdministratorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Administrator points to.
	plmxml_api::Result ResolveAdministratorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Administrator array.
	plmxml_api::Result DeleteAdministratorURI( int i );

	//! Remove all URIs from Administrator array.
	plmxml_api::Result DeleteAdministratorURIs( );
	
	//! Check if Administrator is set
	plmxml_api::logical HasAdministratorURIs( ) const;

	//! Get Version of this Library
	plmxml_api::String GetVersion() const;

	//! Set Version of this Library
	plmxml_api::Result SetVersion( const plmxml_api::String &s );
	
	//! Check if Version is set
	plmxml_api::logical HasVersion( ) const;
	
	//! Unset Version
	plmxml_api::Result UnsetVersion( );

	//! Add Specification child element to this Library. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddSpecification();
     
	//! Add 'arg' as Specification child element to this Library.
	plmxml_api::Result AddSpecification( ClassLibraryIdentifier *arg );

	//! Detach and delete all Specification child elements.
	void DeleteSpecifications();
     
	//! Get number of Specification child elements.
	int NumberOfSpecifications() const;
     
	//! Get i'th Specification child element.
	ClassLibraryIdentifier *GetSpecification( int i ) const;
     
	//! Get all Specification child element as an array
	void GetSpecifications( plmxml_api::Array<ClassLibraryIdentifier*> &array ) const;
	     
	//! Detach and delete i'th Specification child element
	void DeleteSpecification( int i );
     
	//! Detach and delete 'arg' if it's one of the Specification child elements
	void DeleteSpecification( ClassLibraryIdentifier *arg );
 
// <PLMXML_UserCode type="functionHeaderLibrary" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassLibrary;


////////////////////////////////////////////////////////////////////////////////////
//! LibraryNode class
/*!
\verbatim

      Library Hierarchy Node.

      Attributes:

      classificationNodeRef: References a Classification Hierarchy Node.
      virtual:          Whether the Library Node is virtual.

      Sub-elements:

      OwningHierarchy:  Identifies the owning LibraryHierarchy.
      OwningLibrary:    Identifies the owning Library.
      
\endverbatim
*/
class PLMXML_CL60_API LibraryNode : public ClassificationNode
{
public:
     
    //! Default constructor
    LibraryNode( );
     
    //! Constructs a LibraryNode with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LibraryNode( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LibraryNode();

private:

	//! Assignment operator
	LibraryNode& operator=( const LibraryNode& iSrc );

	//! Copy constructor
	LibraryNode( const LibraryNode& original );
     
public:

	//! Get ClassificationNode URI as plmxml_api::String
	plmxml_api::String GetClassificationNodeURI() const;

	//! Set ClassificationNode URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetClassificationNodeURI( const plmxml_api::String& );
	
	//! Get the handle of ClassificationNode URI. Does not resolve the URI.
	plmxml_api::Result GetClassificationNodeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ClassificationNode URI. URI string is unchanged.
	plmxml_api::Result SetClassificationNodeURI( const plmxml_api::Handle& );
	
	//! Resolve ClassificationNode URI and return an object (handle) it points to.
	plmxml_api::Result ResolveClassificationNodeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ClassificationNode URI. Clears URI string and handle.
	plmxml_api::Result DeleteClassificationNodeURI();
	
	//! Check if ClassificationNode URI is set
	plmxml_api::logical HasClassificationNodeURI( ) const;
	

	//! Set Virtual
	plmxml_api::Result SetVirtual( plmxml_api::logical arg );

	//! Get Virtual
	plmxml_api::logical GetVirtual() const;

	//! Check if Virtual is set
	plmxml_api::logical HasVirtual() const;

	//! Unset Virtual
	plmxml_api::Result UnsetVirtual();

	//! Add OwningHierarchy child element to this LibraryNode. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningHierarchy();
     
	//! Set OwningHierarchy child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningHierarchy( ClassLibraryIdentifier *arg );
     
	//! Get OwningHierarchy child element of this LibraryNode.
	ClassLibraryIdentifier *GetOwningHierarchy() const;
     
	//! Detach and delete OwningHierarchy child element tree from this LibraryNode.
	void DeleteOwningHierarchy();

	//! Add OwningLibrary child element to this LibraryNode. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningLibrary();
     
	//! Set OwningLibrary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningLibrary( ClassLibraryIdentifier *arg );
     
	//! Get OwningLibrary child element of this LibraryNode.
	ClassLibraryIdentifier *GetOwningLibrary() const;
     
	//! Detach and delete OwningLibrary child element tree from this LibraryNode.
	void DeleteOwningLibrary();
 
// <PLMXML_UserCode type="functionHeaderLibraryNode" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassLibraryNode;


////////////////////////////////////////////////////////////////////////////////////
//! LibraryHierarchy class
/*!
\verbatim

      Library Hierarchy.

      Attributes:

      objectId:         Inherited from ClassificationHeader. The identifier of
                        the Library Hierarchy.
      disciplineRefs:   A list of references to Disciplines.

      Sub-elements:

      OwningLibrary:    Identifies the owning Library.
      
\endverbatim
*/
class PLMXML_CL60_API LibraryHierarchy : public ClassificationHeader
{
public:
     
    //! Default constructor
    LibraryHierarchy( );
     
    //! Constructs a LibraryHierarchy with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LibraryHierarchy( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LibraryHierarchy();

private:

	//! Assignment operator
	LibraryHierarchy& operator=( const LibraryHierarchy& iSrc );

	//! Copy constructor
	LibraryHierarchy( const LibraryHierarchy& original );
     
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

	//! Add OwningLibrary child element to this LibraryHierarchy. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningLibrary();
     
	//! Set OwningLibrary child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningLibrary( ClassLibraryIdentifier *arg );
     
	//! Get OwningLibrary child element of this LibraryHierarchy.
	ClassLibraryIdentifier *GetOwningLibrary() const;
     
	//! Detach and delete OwningLibrary child element tree from this LibraryHierarchy.
	void DeleteOwningLibrary();
 
// <PLMXML_UserCode type="functionHeaderLibraryHierarchy" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassLibraryHierarchy;


////////////////////////////////////////////////////////////////////////////////////
//! LibraryMember class
/*!
\verbatim

      Library Member.

      Attributes:

      objectId:         The identifier of the Library Member.
      objectRef:        References the object in the product structure.
      classificationMemberRef: References the Classification Member.
      published:        Whether the Library Member is published.
      replacedByRef:    References the Library Member that replaces this
                        Library Member.

      Sub-elements:

      OwningNode:       Identifies the owning Library Node in the Library
                        Hierarchy.
      
\endverbatim
*/
class PLMXML_CL60_API LibraryMember : public Managed
{
public:
     
    //! Default constructor
    LibraryMember( );
     
    //! Constructs a LibraryMember with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LibraryMember( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LibraryMember();

private:

	//! Assignment operator
	LibraryMember& operator=( const LibraryMember& iSrc );

	//! Copy constructor
	LibraryMember( const LibraryMember& original );
     
public:

	//! Get ClassificationMember URI as plmxml_api::String
	plmxml_api::String GetClassificationMemberURI() const;

	//! Set ClassificationMember URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetClassificationMemberURI( const plmxml_api::String& );
	
	//! Get the handle of ClassificationMember URI. Does not resolve the URI.
	plmxml_api::Result GetClassificationMemberURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ClassificationMember URI. URI string is unchanged.
	plmxml_api::Result SetClassificationMemberURI( const plmxml_api::Handle& );
	
	//! Resolve ClassificationMember URI and return an object (handle) it points to.
	plmxml_api::Result ResolveClassificationMemberURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ClassificationMember URI. Clears URI string and handle.
	plmxml_api::Result DeleteClassificationMemberURI();
	
	//! Check if ClassificationMember URI is set
	plmxml_api::logical HasClassificationMemberURI( ) const;
	

	//! Get ReplacedBy URI as plmxml_api::String
	plmxml_api::String GetReplacedByURI() const;

	//! Set ReplacedBy URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReplacedByURI( const plmxml_api::String& );
	
	//! Get the handle of ReplacedBy URI. Does not resolve the URI.
	plmxml_api::Result GetReplacedByURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ReplacedBy URI. URI string is unchanged.
	plmxml_api::Result SetReplacedByURI( const plmxml_api::Handle& );
	
	//! Resolve ReplacedBy URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReplacedByURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ReplacedBy URI. Clears URI string and handle.
	plmxml_api::Result DeleteReplacedByURI();
	
	//! Check if ReplacedBy URI is set
	plmxml_api::logical HasReplacedByURI( ) const;
	

	//! Set Published
	plmxml_api::Result SetPublished( plmxml_api::logical arg );

	//! Get Published
	plmxml_api::logical GetPublished() const;

	//! Check if Published is set
	plmxml_api::logical HasPublished() const;

	//! Unset Published
	plmxml_api::Result UnsetPublished();

	//! Get ObjectId of this LibraryMember
	plmxml_api::String GetObjectId() const;

	//! Set ObjectId of this LibraryMember
	plmxml_api::Result SetObjectId( const plmxml_api::String &s );
	
	//! Check if ObjectId is set
	plmxml_api::logical HasObjectId( ) const;
	
	//! Unset ObjectId
	plmxml_api::Result UnsetObjectId( );

	//! Get Object URI as plmxml_api::String
	plmxml_api::String GetObjectURI() const;

	//! Set Object URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetObjectURI( const plmxml_api::String& );
	
	//! Get the handle of Object URI. Does not resolve the URI.
	plmxml_api::Result GetObjectURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Object URI. URI string is unchanged.
	plmxml_api::Result SetObjectURI( const plmxml_api::Handle& );
	
	//! Resolve Object URI and return an object (handle) it points to.
	plmxml_api::Result ResolveObjectURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Object URI. Clears URI string and handle.
	plmxml_api::Result DeleteObjectURI();
	
	//! Check if Object URI is set
	plmxml_api::logical HasObjectURI( ) const;
	

	//! Add OwningNode child element to this LibraryMember. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningNode();
     
	//! Set OwningNode child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningNode( ClassLibraryIdentifier *arg );
     
	//! Get OwningNode child element of this LibraryMember.
	ClassLibraryIdentifier *GetOwningNode() const;
     
	//! Detach and delete OwningNode child element tree from this LibraryMember.
	void DeleteOwningNode();
 
// <PLMXML_UserCode type="functionHeaderLibraryMember" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassLibraryMember;


////////////////////////////////////////////////////////////////////////////////////
//! Specification class
/*!
\verbatim

      Library Specification.

      Attributes:

      objectId:         Inherited from ClassificationHeader. The identifier of
                        the Library Specification.
      disciplineRef:    References the Discipline.
      version:          The version of the Library Specification.
      administratorRefs: A list of references to administrative Users.
      childRulesOverride: Whether child rules referencing this Library
                        Specification override or extend parent rules.
      
\endverbatim
*/
class PLMXML_CL60_API Specification : public ClassificationHeader
{
public:
     
    //! Default constructor
    Specification( );
     
    //! Constructs a Specification with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Specification( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Specification();

private:

	//! Assignment operator
	Specification& operator=( const Specification& iSrc );

	//! Copy constructor
	Specification( const Specification& original );
     
public:

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
	

	//! Get number of URIs in Administrator
	int NumberOfAdministratorURIs() const;

	//! Get i'th URI in Administrator
	plmxml_api::String GetAdministratorURI( int i ) const;

	//! Add a URI to Administrator array. Call ResolveAdministratorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAdministratorURI( const plmxml_api::String& u );

	//! Set i'th URI in Administrator array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAdministratorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Administrator URI. Does not resolve the URI.
	plmxml_api::Result GetAdministratorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Administrator array.
	plmxml_api::Result AddAdministratorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Administrator array to point to 'handle'.
	plmxml_api::Result SetAdministratorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Administrator points to.
	plmxml_api::Result ResolveAdministratorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Administrator array.
	plmxml_api::Result DeleteAdministratorURI( int i );

	//! Remove all URIs from Administrator array.
	plmxml_api::Result DeleteAdministratorURIs( );
	
	//! Check if Administrator is set
	plmxml_api::logical HasAdministratorURIs( ) const;

	//! Set ChildRulesOverride
	plmxml_api::Result SetChildRulesOverride( plmxml_api::logical arg );

	//! Get ChildRulesOverride
	plmxml_api::logical GetChildRulesOverride() const;

	//! Check if ChildRulesOverride is set
	plmxml_api::logical HasChildRulesOverride() const;

	//! Unset ChildRulesOverride
	plmxml_api::Result UnsetChildRulesOverride();

	//! Get Version of this Specification
	plmxml_api::String GetVersion() const;

	//! Set Version of this Specification
	plmxml_api::Result SetVersion( const plmxml_api::String &s );
	
	//! Check if Version is set
	plmxml_api::logical HasVersion( ) const;
	
	//! Unset Version
	plmxml_api::Result UnsetVersion( );
 
// <PLMXML_UserCode type="functionHeaderSpecification" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecification;


////////////////////////////////////////////////////////////////////////////////////
//! SpecificationHeader class
/*!
\verbatim

      Specification Header.

      Attributes:

      name:             Inherited from AttribOwner.
      nameRef:          Inherited from AttribOwner. References a multiple
                        language version of name.
      descriptionTextRef: Inherited from AttribOwner. References a multiple
                        language version of description.
      objectId:         The identifier of the derived object.
      active:           Whether the Specification Header is active in the
                        Specification.

      Sub-elements:

      Description:      Inherited from AttribOwner.
      OwningSpecification: Identifies the owning Specification.
      
\endverbatim
*/
class PLMXML_CL60_API SpecificationHeader : public AttribOwner
{
public:
     
    //! Default constructor
    SpecificationHeader( );
     
    //! Constructs a SpecificationHeader with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecificationHeader( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecificationHeader();

private:

	//! Assignment operator
	SpecificationHeader& operator=( const SpecificationHeader& iSrc );

	//! Copy constructor
	SpecificationHeader( const SpecificationHeader& original );
     
public:

	//! Set Active
	plmxml_api::Result SetActive( plmxml_api::logical arg );

	//! Get Active
	plmxml_api::logical GetActive() const;

	//! Check if Active is set
	plmxml_api::logical HasActive() const;

	//! Unset Active
	plmxml_api::Result UnsetActive();

	//! Get ObjectId of this SpecificationHeader
	plmxml_api::String GetObjectId() const;

	//! Set ObjectId of this SpecificationHeader
	plmxml_api::Result SetObjectId( const plmxml_api::String &s );
	
	//! Check if ObjectId is set
	plmxml_api::logical HasObjectId( ) const;
	
	//! Unset ObjectId
	plmxml_api::Result UnsetObjectId( );

	//! Add OwningSpecification child element to this SpecificationHeader. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningSpecification();
     
	//! Set OwningSpecification child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningSpecification( ClassLibraryIdentifier *arg );
     
	//! Get OwningSpecification child element of this SpecificationHeader.
	ClassLibraryIdentifier *GetOwningSpecification() const;
     
	//! Detach and delete OwningSpecification child element tree from this SpecificationHeader.
	void DeleteOwningSpecification();
 
// <PLMXML_UserCode type="functionHeaderSpecificationHeader" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecificationHeader;


////////////////////////////////////////////////////////////////////////////////////
//! SpecificationRuleSet class
/*!
\verbatim

      Specification Rule Set.

      Attributes:

      objectId:         Inherited from SpecificationHeader. The identifier of
                        the Specification Rule Set.
      
\endverbatim
*/
class PLMXML_CL60_API SpecificationRuleSet : public SpecificationHeader
{
public:
     
    //! Default constructor
    SpecificationRuleSet( );
     
    //! Constructs a SpecificationRuleSet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecificationRuleSet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecificationRuleSet();

private:

	//! Assignment operator
	SpecificationRuleSet& operator=( const SpecificationRuleSet& iSrc );

	//! Copy constructor
	SpecificationRuleSet( const SpecificationRuleSet& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderSpecificationRuleSet" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecificationRuleSet;


////////////////////////////////////////////////////////////////////////////////////
//! SpecConditionIs class
/*!
\verbatim

      SpecConditionIs returns the truth of the operation attribute operating on
      the name attribute on the containing SpecCondition and the value
      attribute.

      Attributes:

      operation:        The type of operation.
      value:            The second operand.
      inputValue:       Whether the input value for the target condition is
                        obtained from the input value to the source condition.
      
\endverbatim
*/
class PLMXML_CL60_API SpecConditionIs : public LogicalExpression
{
public:
     
    //! Default constructor
    SpecConditionIs( );
     
    //! Constructs a SpecConditionIs with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecConditionIs( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecConditionIs();

private:

	//! Assignment operator
	SpecConditionIs& operator=( const SpecConditionIs& iSrc );

	//! Copy constructor
	SpecConditionIs( const SpecConditionIs& original );
     
public:

	//! Set InputValue
	plmxml_api::Result SetInputValue( plmxml_api::logical arg );

	//! Get InputValue
	plmxml_api::logical GetInputValue() const;

	//! Check if InputValue is set
	plmxml_api::logical HasInputValue() const;

	//! Unset InputValue
	plmxml_api::Result UnsetInputValue();

	//! Set Operation
	plmxml_api::Result SetOperation( const plmxml60::eLogicalOperationType& arg );

	//! Get Operation
	plmxml60::eLogicalOperationType GetOperation() const;

	//! Get Value of this SpecConditionIs
	plmxml_api::String GetValue() const;

	//! Set Value of this SpecConditionIs
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderSpecConditionIs" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecConditionIs;


////////////////////////////////////////////////////////////////////////////////////
//! SpecCondition class
/*!
\verbatim

      Specification Condition.

      Sub-elements:

      LogicalExpression: The expression specifying the truth of the condition.
      
\endverbatim
*/
class PLMXML_CL60_API SpecCondition : public AttribOwner
{
public:
     
    //! Default constructor
    SpecCondition( );
     
    //! Constructs a SpecCondition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecCondition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecCondition();

private:

	//! Assignment operator
	SpecCondition& operator=( const SpecCondition& iSrc );

	//! Copy constructor
	SpecCondition( const SpecCondition& original );
     
public:

	//! Add LogicalExpression child element to this SpecCondition. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	LogicalExpression *AddLogicalExpression();
     
	//! Set LogicalExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLogicalExpression( LogicalExpression *arg );
     
	//! Get LogicalExpression child element of this SpecCondition.
	LogicalExpression *GetLogicalExpression() const;
     
	//! Detach and delete LogicalExpression child element tree from this SpecCondition.
	void DeleteLogicalExpression();
 
// <PLMXML_UserCode type="functionHeaderSpecCondition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecCondition;


////////////////////////////////////////////////////////////////////////////////////
//! SpecificationRule class
/*!
\verbatim

      Specification Rule.

      Attributes:

      objectId:         Inherited from SpecificationHeader. The identifier of
                        the Specification Rule.
      ruleType:         The type of Specification Rule.

      Sub-elements:

      OwningSet:        Identifies the Set in which the Specification Rule lies.
      AssignedNode:     Identifies the assigned Library Node.
      SourceCondition:  The condition under which the Specification Rule
                        applies.
      TargetCondition:  The condition imposed by the Specification Rule.
      
\endverbatim
*/
class PLMXML_CL60_API SpecificationRule : public SpecificationHeader
{
public:
     
    //! Default constructor
    SpecificationRule( );
     
    //! Constructs a SpecificationRule with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecificationRule( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecificationRule();

private:

	//! Assignment operator
	SpecificationRule& operator=( const SpecificationRule& iSrc );

	//! Copy constructor
	SpecificationRule( const SpecificationRule& original );
     
public:

	//! Set RuleType
	plmxml_api::Result SetRuleType( const eSpecRuleEnum& arg );

	//! Get RuleType
	eSpecRuleEnum GetRuleType() const;

	//! Add OwningSet child element to this SpecificationRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddOwningSet();
     
	//! Set OwningSet child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningSet( ClassLibraryIdentifier *arg );
     
	//! Get OwningSet child element of this SpecificationRule.
	ClassLibraryIdentifier *GetOwningSet() const;
     
	//! Detach and delete OwningSet child element tree from this SpecificationRule.
	void DeleteOwningSet();

	//! Add AssignedNode child element to this SpecificationRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddAssignedNode();
     
	//! Set AssignedNode child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetAssignedNode( ClassLibraryIdentifier *arg );
     
	//! Get AssignedNode child element of this SpecificationRule.
	ClassLibraryIdentifier *GetAssignedNode() const;
     
	//! Detach and delete AssignedNode child element tree from this SpecificationRule.
	void DeleteAssignedNode();

	//! Add SourceCondition child element to this SpecificationRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SpecCondition *AddSourceCondition();
     
	//! Set SourceCondition child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSourceCondition( SpecCondition *arg );
     
	//! Get SourceCondition child element of this SpecificationRule.
	SpecCondition *GetSourceCondition() const;
     
	//! Detach and delete SourceCondition child element tree from this SpecificationRule.
	void DeleteSourceCondition();

	//! Add TargetCondition child element to this SpecificationRule. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SpecCondition *AddTargetCondition();
     
	//! Set TargetCondition child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTargetCondition( SpecCondition *arg );
     
	//! Get TargetCondition child element of this SpecificationRule.
	SpecCondition *GetTargetCondition() const;
     
	//! Detach and delete TargetCondition child element tree from this SpecificationRule.
	void DeleteTargetCondition();
 
// <PLMXML_UserCode type="functionHeaderSpecificationRule" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecificationRule;


////////////////////////////////////////////////////////////////////////////////////
//! SpecificationActionSet class
/*!
\verbatim

      Specification Action Set.

      Attributes:

      objectId:         Inherited from SpecificationHeader. The identifier of
                        the Specification Action Set.
      setType:          The type of Specification Action Set.
      actionRefs:       A list of references to the Specification Actions in the
                        Set.
      dataRefs:         A list of references to Specification Application Data
                        elements.

      Sub-elements:

      Source:           Identifies the Library Node that invokes the
                        Specification Action Set.
      Target:           When setType is connectionCompatibility, Target
                        identifies the other Library Node involved.
      
\endverbatim
*/
class PLMXML_CL60_API SpecificationActionSet : public SpecificationHeader
{
public:
     
    //! Default constructor
    SpecificationActionSet( );
     
    //! Constructs a SpecificationActionSet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecificationActionSet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecificationActionSet();

private:

	//! Assignment operator
	SpecificationActionSet& operator=( const SpecificationActionSet& iSrc );

	//! Copy constructor
	SpecificationActionSet( const SpecificationActionSet& original );
     
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

	//! Get number of URIs in Data
	int NumberOfDataURIs() const;

	//! Get i'th URI in Data
	plmxml_api::String GetDataURI( int i ) const;

	//! Add a URI to Data array. Call ResolveDataURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddDataURI( const plmxml_api::String& u );

	//! Set i'th URI in Data array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetDataURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Data URI. Does not resolve the URI.
	plmxml_api::Result GetDataURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Data array.
	plmxml_api::Result AddDataURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Data array to point to 'handle'.
	plmxml_api::Result SetDataURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Data points to.
	plmxml_api::Result ResolveDataURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Data array.
	plmxml_api::Result DeleteDataURI( int i );

	//! Remove all URIs from Data array.
	plmxml_api::Result DeleteDataURIs( );
	
	//! Check if Data is set
	plmxml_api::logical HasDataURIs( ) const;

	//! Set SetType
	plmxml_api::Result SetSetType( const eSpecActionSetEnum& arg );

	//! Get SetType
	eSpecActionSetEnum GetSetType() const;

	//! Add Source child element to this SpecificationActionSet. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddSource();
     
	//! Set Source child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSource( ClassLibraryIdentifier *arg );
     
	//! Get Source child element of this SpecificationActionSet.
	ClassLibraryIdentifier *GetSource() const;
     
	//! Detach and delete Source child element tree from this SpecificationActionSet.
	void DeleteSource();

	//! Add Target child element to this SpecificationActionSet. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassLibraryIdentifier *AddTarget();
     
	//! Set Target child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTarget( ClassLibraryIdentifier *arg );
     
	//! Get Target child element of this SpecificationActionSet.
	ClassLibraryIdentifier *GetTarget() const;
     
	//! Detach and delete Target child element tree from this SpecificationActionSet.
	void DeleteTarget();
 
// <PLMXML_UserCode type="functionHeaderSpecificationActionSet" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecificationActionSet;


////////////////////////////////////////////////////////////////////////////////////
//! SpecificationAction class
/*!
\verbatim

      Specification Action.

      Attributes:

      objectId:         Inherited from SpecificationHeader. The identifier of
                        the Specification Action.
      actionType:       The action performed by the Specification Action.
      quantity:         The number of components involved in the Specification
                        Action.
      ruleRefs:         A list of references to Specification Rules that select
                        suitable components. 
      
\endverbatim
*/
class PLMXML_CL60_API SpecificationAction : public SpecificationHeader
{
public:
     
    //! Default constructor
    SpecificationAction( );
     
    //! Constructs a SpecificationAction with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecificationAction( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecificationAction();

private:

	//! Assignment operator
	SpecificationAction& operator=( const SpecificationAction& iSrc );

	//! Copy constructor
	SpecificationAction( const SpecificationAction& original );
     
public:

	//! Set Quantity
	plmxml_api::Result SetQuantity( int arg );
     
	//! Get Quantity
	int GetQuantity() const;
     
	//! Check if Quantity is set
	plmxml_api::logical HasQuantity() const;
     
	//! Unset Quantity
	plmxml_api::Result UnsetQuantity();

	//! Set ActionType
	plmxml_api::Result SetActionType( const eSpecActionEnum& arg );

	//! Get ActionType
	eSpecActionEnum GetActionType() const;

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
 
// <PLMXML_UserCode type="functionHeaderSpecificationAction" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecificationAction;


////////////////////////////////////////////////////////////////////////////////////
//! SpecAppData class
/*!
\verbatim

      Specification Application Data.

      Attributes:

      objectId:         Inherited from SpecificationHeader. The identifier of
                        the Specification Application Data.
      global:           Whether the Specification Application Data element is
                        global.
      usage:            What the Specification Application Data element is used
                        for.

      Sub-elements:

      DataItem:         Name / value pairs that constitute the Specification
                        Application Data element.
      
\endverbatim
*/
class PLMXML_CL60_API SpecAppData : public SpecificationHeader
{
public:
     
    //! Default constructor
    SpecAppData( );
     
    //! Constructs a SpecAppData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpecAppData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpecAppData();

private:

	//! Assignment operator
	SpecAppData& operator=( const SpecAppData& iSrc );

	//! Copy constructor
	SpecAppData( const SpecAppData& original );
     
public:

	//! Get Usage of this SpecAppData
	plmxml_api::String GetUsage() const;

	//! Set Usage of this SpecAppData
	plmxml_api::Result SetUsage( const plmxml_api::String &s );
	
	//! Check if Usage is set
	plmxml_api::logical HasUsage( ) const;
	
	//! Unset Usage
	plmxml_api::Result UnsetUsage( );

	//! Set Global
	plmxml_api::Result SetGlobal( plmxml_api::logical arg );

	//! Get Global
	plmxml_api::logical GetGlobal() const;

	//! Check if Global is set
	plmxml_api::logical HasGlobal() const;

	//! Unset Global
	plmxml_api::Result UnsetGlobal();

	//! Add DataItem child element to this SpecAppData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddDataItem();
     
	//! Add 'arg' as DataItem child element to this SpecAppData.
	plmxml_api::Result AddDataItem( UserValue *arg );

	//! Detach and delete all DataItem child elements.
	void DeleteDataItems();
     
	//! Get number of DataItem child elements.
	int NumberOfDataItems() const;
     
	//! Get i'th DataItem child element.
	UserValue *GetDataItem( int i ) const;
     
	//! Get all DataItem child element as an array
	void GetDataItems( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th DataItem child element
	void DeleteDataItem( int i );
     
	//! Detach and delete 'arg' if it's one of the DataItem child elements
	void DeleteDataItem( UserValue *arg );
 
// <PLMXML_UserCode type="functionHeaderSpecAppData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CL60_API plmxml_api::plmxmlClass plmxmlClassSpecAppData;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
