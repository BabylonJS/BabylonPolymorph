/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.0.28574 23/02/2009 15:56:41
// 
// Schema:	PLMXMLUGSSchema.xsd
// Data:	23/02/2009 15:56:40
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_UGS60_H__
#define __PLMXML_UGS60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_UGS60_EXPORTS
#define PLMXML_UGS60_API __declspec(dllexport)
#else
#define PLMXML_UGS60_API __declspec(dllimport)
#endif
#else
#define PLMXML_UGS60_API
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
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eMassConstraintsUnitType class
/*!
Allowed Values:
\verbatim
  eMassConstraintsUnitTypeMilligrams
	"milligrams"
  eMassConstraintsUnitTypeKilograms
	"kilograms"
  eMassConstraintsUnitTypePounds
	"pounds"
  eMassConstraintsUnitTypeGrams
	"grams"
  
\endverbatim
*/
class PLMXML_UGS60_API eMassConstraintsUnitType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eMassConstraintsUnitType( const char* Type );
     
	//! Constructor
	eMassConstraintsUnitType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eMassConstraintsUnitType( );
     
	//! Destructor 
	virtual ~eMassConstraintsUnitType( );
     
	//! Assign from 'Type'
	const eMassConstraintsUnitType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eMassConstraintsUnitType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare MassConstraintsUnitType
	friend plmxml_api::logical PLMXML_UGS60_API operator==( const eMassConstraintsUnitType& e1, const eMassConstraintsUnitType& e2 );
     
	//! Compare MassConstraintsUnitType
	friend plmxml_api::logical PLMXML_UGS60_API operator!=( const eMassConstraintsUnitType& e1, const eMassConstraintsUnitType& e2 );
};
extern PLMXML_UGS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumMassConstraintsUnitType;
extern PLMXML_UGS60_API eMassConstraintsUnitType eMassConstraintsUnitTypeUnset;
extern PLMXML_UGS60_API eMassConstraintsUnitType eMassConstraintsUnitTypeMilligrams;
extern PLMXML_UGS60_API eMassConstraintsUnitType eMassConstraintsUnitTypeKilograms;
extern PLMXML_UGS60_API eMassConstraintsUnitType eMassConstraintsUnitTypePounds;
extern PLMXML_UGS60_API eMassConstraintsUnitType eMassConstraintsUnitTypeGrams;

////////////////////////////////////////////////////////////////////////////////////
//! eRefEntityType class
/*!
Allowed Values:
\verbatim
  eRefEntityTypeVertex
	"vertex"
  eRefEntityTypeEdge
	"edge"
  eRefEntityTypeFace
	"face"
  eRefEntityTypeBody
	"body"
  
\endverbatim
*/
class PLMXML_UGS60_API eRefEntityType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRefEntityType( const char* Type );
     
	//! Constructor
	eRefEntityType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRefEntityType( );
     
	//! Destructor 
	virtual ~eRefEntityType( );
     
	//! Assign from 'Type'
	const eRefEntityType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRefEntityType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RefEntityType
	friend plmxml_api::logical PLMXML_UGS60_API operator==( const eRefEntityType& e1, const eRefEntityType& e2 );
     
	//! Compare RefEntityType
	friend plmxml_api::logical PLMXML_UGS60_API operator!=( const eRefEntityType& e1, const eRefEntityType& e2 );
};
extern PLMXML_UGS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRefEntityType;
extern PLMXML_UGS60_API eRefEntityType eRefEntityTypeUnset;
extern PLMXML_UGS60_API eRefEntityType eRefEntityTypeVertex;
extern PLMXML_UGS60_API eRefEntityType eRefEntityTypeEdge;
extern PLMXML_UGS60_API eRefEntityType eRefEntityTypeFace;
extern PLMXML_UGS60_API eRefEntityType eRefEntityTypeBody;

////////////////////////////////////////////////////////////////////////////////////
//! ePartUnitsType class
/*!
Allowed Values:
\verbatim
  ePartUnitsTypeMillimetres
	"millimetres"
  ePartUnitsTypeInches
	"inches"
  
\endverbatim
*/
class PLMXML_UGS60_API ePartUnitsType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	ePartUnitsType( const char* Type );
     
	//! Constructor
	ePartUnitsType( const plmxml_api::String& Type );
     
	//! Default Constructor
	ePartUnitsType( );
     
	//! Destructor 
	virtual ~ePartUnitsType( );
     
	//! Assign from 'Type'
	const ePartUnitsType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const ePartUnitsType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare PartUnitsType
	friend plmxml_api::logical PLMXML_UGS60_API operator==( const ePartUnitsType& e1, const ePartUnitsType& e2 );
     
	//! Compare PartUnitsType
	friend plmxml_api::logical PLMXML_UGS60_API operator!=( const ePartUnitsType& e1, const ePartUnitsType& e2 );
};
extern PLMXML_UGS60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumPartUnitsType;
extern PLMXML_UGS60_API ePartUnitsType ePartUnitsTypeUnset;
extern PLMXML_UGS60_API ePartUnitsType ePartUnitsTypeMillimetres;
extern PLMXML_UGS60_API ePartUnitsType ePartUnitsTypeInches;

////////////////////////////////////////////////////////////////////////////////////
//! GUID class
/*!
\verbatim

\endverbatim
*/
class PLMXML_UGS60_API GUID : public DescriptionObject
{
public:
     
    //! Default constructor
    GUID( );
     
    //! Constructs a GUID with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GUID( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GUID();

private:

	//! Assignment operator
	GUID& operator=( const GUID& iSrc );

	//! Copy constructor
	GUID( const GUID& original );
     
public:

	//! Get Value of this GUID
	plmxml_api::String GetValue() const;

	//! Set Value of this GUID
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderGUID" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassGUID;


////////////////////////////////////////////////////////////////////////////////////
//! GUIDTable class
/*!
\verbatim

	  Datatype for defining a table of GUIDs for later
	  use by the entity reference elements. These values 
	  are the GUIDs used on the target body or entity and
	  provide a mechanism to 'shorthand' the moniker information
	  without having to repeat lengthy GUID strings. 
	  
\endverbatim
*/
class PLMXML_UGS60_API GUIDTable : public DescriptionObject
{
public:
     
    //! Default constructor
    GUIDTable( );
     
    //! Constructs a GUIDTable with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GUIDTable( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GUIDTable();

private:

	//! Assignment operator
	GUIDTable& operator=( const GUIDTable& iSrc );

	//! Copy constructor
	GUIDTable( const GUIDTable& original );
     
public:

	//! Add GUID child element to this GUIDTable. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GUID *AddGUID();
     
	//! Add 'arg' as GUID child element to this GUIDTable.
	plmxml_api::Result AddGUID( GUID *arg );

	//! Detach and delete all GUID child elements.
	void DeleteGUIDs();
     
	//! Get number of GUID child elements.
	int NumberOfGUIDs() const;
     
	//! Get i'th GUID child element.
	GUID *GetGUID( int i ) const;
     
	//! Get all GUID child element as an array
	void GetGUIDs( plmxml_api::Array<GUID*> &array ) const;
	     
	//! Detach and delete i'th GUID child element
	void DeleteGUID( int i );
     
	//! Detach and delete 'arg' if it's one of the GUID child elements
	void DeleteGUID( GUID *arg );
 
// <PLMXML_UserCode type="functionHeaderGUIDTable" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassGUIDTable;


////////////////////////////////////////////////////////////////////////////////////
//! MonikerDataRef class
/*!
\verbatim

	  This datatype describes a single item of moniker data (ie. a
	  moniker entity id and GUID index). The GUIDRef attribute 
	  contains the id of the GUID in the GUIDTable and the  
	  EntityId attribute is the value of the entity id held within
	  the moniker attribute on the target body. 
	  
\endverbatim
*/
class PLMXML_UGS60_API MonikerDataRef : public plmxml_api::Object
{
public:
     
    //! Default constructor
    MonikerDataRef( );
     
    //! Constructs a MonikerDataRef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MonikerDataRef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MonikerDataRef();

private:

	//! Assignment operator
	MonikerDataRef& operator=( const MonikerDataRef& iSrc );

	//! Copy constructor
	MonikerDataRef( const MonikerDataRef& original );
     
public:

	//! Set reference to Guid using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetGuidRef( plmxml60::IdObject *arg );

	//! Clear reference to Guid
	void RemoveGuidRef( );

	//! Find a plmxml60::IdObject referenced by Guid
	plmxml60::IdObject *ResolveGuidRef( plmxml_api::Configuration* config = NULL );

	//! Get Guid reference
	plmxml_api::String GetGuidId() const;

	//! Set Guid reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetGuidId( const plmxml_api::String& u );
	
	//! Check if Guid is set
	plmxml_api::logical HasGuidRef( ) const;

	//! Set EntityId
	plmxml_api::Result SetEntityId( int arg );
     
	//! Get EntityId
	int GetEntityId() const;
     
	//! Check if EntityId is set
	plmxml_api::logical HasEntityId() const;
     
	//! Unset EntityId
	plmxml_api::Result UnsetEntityId();
 
// <PLMXML_UserCode type="functionHeaderMonikerDataRef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMonikerDataRef;


////////////////////////////////////////////////////////////////////////////////////
//! MonikerGUIDRef class
/*!
\verbatim

	  This datatype just contains the id of the GUID which describes
	  all the entities of interest. The GUIDRef attribute contains
	  the id of the GUID in the GUIDTable. 
	  By specifying just a GUID for a moniker means the reference
	  is specifiying all the entities that are associated with that
	  GUID.
	  
\endverbatim
*/
class PLMXML_UGS60_API MonikerGUIDRef : public plmxml_api::Object
{
public:
     
    //! Default constructor
    MonikerGUIDRef( );
     
    //! Constructs a MonikerGUIDRef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MonikerGUIDRef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MonikerGUIDRef();

private:

	//! Assignment operator
	MonikerGUIDRef& operator=( const MonikerGUIDRef& iSrc );

	//! Copy constructor
	MonikerGUIDRef( const MonikerGUIDRef& original );
     
public:

	//! Set reference to Guid using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetGuidRef( plmxml60::IdObject *arg );

	//! Clear reference to Guid
	void RemoveGuidRef( );

	//! Find a plmxml60::IdObject referenced by Guid
	plmxml60::IdObject *ResolveGuidRef( plmxml_api::Configuration* config = NULL );

	//! Get Guid reference
	plmxml_api::String GetGuidId() const;

	//! Set Guid reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetGuidId( const plmxml_api::String& u );
	
	//! Check if Guid is set
	plmxml_api::logical HasGuidRef( ) const;
 
// <PLMXML_UserCode type="functionHeaderMonikerGUIDRef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMonikerGUIDRef;


////////////////////////////////////////////////////////////////////////////////////
//! MonikerPath class
/*!
\verbatim

	  This datatype just contains a string which represents the 
	  moniker path of the entity/entities. This equivalent to the 
	  string used within the context of the SE public API.
	  This functionality should eventually be used by all EDS PLM 
	  applications.
	  
\endverbatim
*/
class PLMXML_UGS60_API MonikerPath : public plmxml_api::Object
{
public:
     
    //! Default constructor
    MonikerPath( );
     
    //! Constructs a MonikerPath with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MonikerPath( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MonikerPath();

private:

	//! Assignment operator
	MonikerPath& operator=( const MonikerPath& iSrc );

	//! Copy constructor
	MonikerPath( const MonikerPath& original );
     
public:

	//! Get Path of this MonikerPath
	plmxml_api::String GetPath() const;

	//! Set Path of this MonikerPath
	plmxml_api::Result SetPath( const plmxml_api::String &s );
	
	//! Check if Path is set
	plmxml_api::logical HasPath( ) const;
	
	//! Unset Path
	plmxml_api::Result UnsetPath( );
 
// <PLMXML_UserCode type="functionHeaderMonikerPath" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMonikerPath;


////////////////////////////////////////////////////////////////////////////////////
//! MonikerRefSet class
/*!
\verbatim

	  A datatype which describes a reference to a single entity 
	  or set of entities. The element of this datatype consists
	  of :
		  - Moniker -(at least one) Element describing a single set of
				  moniker attribute values. Note that there may be
				  an entity that has multiple moniker attributes
				  (hence the 'unbounded' facet in the schema).\
		  OR
		  - MonikerGUID -(only one) Element containing the GUID of all the
				  entities of interest.
		  OR
		  - MonikerPath -(only one) Element containing the moniker path of
				  all the entities of interest.
	  
\endverbatim
*/
class PLMXML_UGS60_API MonikerRefSet : public plmxml_api::Object
{
public:
     
    //! Default constructor
    MonikerRefSet( );
     
    //! Constructs a MonikerRefSet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MonikerRefSet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MonikerRefSet();

private:

	//! Assignment operator
	MonikerRefSet& operator=( const MonikerRefSet& iSrc );

	//! Copy constructor
	MonikerRefSet( const MonikerRefSet& original );
     
public:

	//! Add Moniker child element to this MonikerRefSet. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MonikerDataRef *AddMoniker();
     
	//! Add 'arg' as Moniker child element to this MonikerRefSet.
	plmxml_api::Result AddMoniker( MonikerDataRef *arg );

	//! Detach and delete all Moniker child elements.
	void DeleteMonikers();
     
	//! Get number of Moniker child elements.
	int NumberOfMonikers() const;
     
	//! Get i'th Moniker child element.
	MonikerDataRef *GetMoniker( int i ) const;
     
	//! Get all Moniker child element as an array
	void GetMonikers( plmxml_api::Array<MonikerDataRef*> &array ) const;
	     
	//! Detach and delete i'th Moniker child element
	void DeleteMoniker( int i );
     
	//! Detach and delete 'arg' if it's one of the Moniker child elements
	void DeleteMoniker( MonikerDataRef *arg );

	//! Add MonikerGUID child element to this MonikerRefSet. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MonikerGUIDRef *AddMonikerGUID();
     
	//! Set MonikerGUID child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetMonikerGUID( MonikerGUIDRef *arg );
     
	//! Get MonikerGUID child element of this MonikerRefSet.
	MonikerGUIDRef *GetMonikerGUID() const;
     
	//! Detach and delete MonikerGUID child element tree from this MonikerRefSet.
	void DeleteMonikerGUID();

	//! Add MonikerPath child element to this MonikerRefSet. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MonikerPath *AddMonikerPath();
     
	//! Set MonikerPath child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetMonikerPath( MonikerPath *arg );
     
	//! Get MonikerPath child element of this MonikerRefSet.
	MonikerPath *GetMonikerPath() const;
     
	//! Detach and delete MonikerPath child element tree from this MonikerRefSet.
	void DeleteMonikerPath();
 
// <PLMXML_UserCode type="functionHeaderMonikerRefSet" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMonikerRefSet;


////////////////////////////////////////////////////////////////////////////////////
//! MonikerRef class
/*!
\verbatim

	  The main datatype for defining a moniker based entity reference. The
	  type consists of :
		  - GUIDTable -(optional) in which to place a the GUIDs that may be 
					  referenced by the moniker references themselves.
					  The GUIDs referenced by the individual entries could be
					  in a 'global' document table - not every reference needs 
					  to define its own GUID table. 
		  - Target    -(mandatory) The element which contains the moniker data of
					  the target entity or entities. 
		  - Adjacent  -(optional) The elements which contain moniker references to 
					  entities adjacent to the target entity. These references
					  will assist with the unique identification of target entities
					  when there is ambiguous (ie. duplicate) moniker data.
					  (not implemeneted in first release or prototype).

	  Attribute:
		  - type   -(mandatory) Type of the reference - body, face, edge or vertex. 
	  
\endverbatim
*/
class PLMXML_UGS60_API MonikerRef : public EntityRef
{
public:
     
    //! Default constructor
    MonikerRef( );
     
    //! Constructs a MonikerRef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MonikerRef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MonikerRef();

private:

	//! Assignment operator
	MonikerRef& operator=( const MonikerRef& iSrc );

	//! Copy constructor
	MonikerRef( const MonikerRef& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eRefEntityType& arg );

	//! Get Type
	eRefEntityType GetType() const;

	//! Add GUIDTable child element to this MonikerRef. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	GUIDTable *AddGUIDTable();
     
	//! Set GUIDTable child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetGUIDTable( GUIDTable *arg );
     
	//! Get GUIDTable child element of this MonikerRef.
	GUIDTable *GetGUIDTable() const;
     
	//! Detach and delete GUIDTable child element tree from this MonikerRef.
	void DeleteGUIDTable();

	//! Add Target child element to this MonikerRef. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MonikerRefSet *AddTarget();
     
	//! Set Target child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTarget( MonikerRefSet *arg );
     
	//! Get Target child element of this MonikerRef.
	MonikerRefSet *GetTarget() const;
     
	//! Detach and delete Target child element tree from this MonikerRef.
	void DeleteTarget();

	//! Add Adjacent child element to this MonikerRef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MonikerRefSet *AddAdjacent();
     
	//! Add 'arg' as Adjacent child element to this MonikerRef.
	plmxml_api::Result AddAdjacent( MonikerRefSet *arg );

	//! Detach and delete all Adjacent child elements.
	void DeleteAdjacents();
     
	//! Get number of Adjacent child elements.
	int NumberOfAdjacents() const;
     
	//! Get i'th Adjacent child element.
	MonikerRefSet *GetAdjacent( int i ) const;
     
	//! Get all Adjacent child element as an array
	void GetAdjacents( plmxml_api::Array<MonikerRefSet*> &array ) const;
	     
	//! Detach and delete i'th Adjacent child element
	void DeleteAdjacent( int i );
     
	//! Detach and delete 'arg' if it's one of the Adjacent child elements
	void DeleteAdjacent( MonikerRefSet *arg );
 
// <PLMXML_UserCode type="functionHeaderMonikerRef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMonikerRef;


////////////////////////////////////////////////////////////////////////////////////
//! MonikerContext class
/*!
\verbatim

\endverbatim
*/
class PLMXML_UGS60_API MonikerContext : public Attribute
{
public:
     
    //! Default constructor
    MonikerContext( );
     
    //! Constructs a MonikerContext with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MonikerContext( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MonikerContext();

private:

	//! Assignment operator
	MonikerContext& operator=( const MonikerContext& iSrc );

	//! Copy constructor
	MonikerContext( const MonikerContext& original );
     
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
	

	//! Add GUID child element to this MonikerContext. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GUID *AddGUID();
     
	//! Add 'arg' as GUID child element to this MonikerContext.
	plmxml_api::Result AddGUID( GUID *arg );

	//! Detach and delete all GUID child elements.
	void DeleteGUIDs();
     
	//! Get number of GUID child elements.
	int NumberOfGUIDs() const;
     
	//! Get i'th GUID child element.
	GUID *GetGUID( int i ) const;
     
	//! Get all GUID child element as an array
	void GetGUIDs( plmxml_api::Array<GUID*> &array ) const;
	     
	//! Detach and delete i'th GUID child element
	void DeleteGUID( int i );
     
	//! Detach and delete 'arg' if it's one of the GUID child elements
	void DeleteGUID( GUID *arg );
 
// <PLMXML_UserCode type="functionHeaderMonikerContext" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMonikerContext;


////////////////////////////////////////////////////////////////////////////////////
//! RepresentationData class
/*!
\verbatim

	  PLMXML attributes for UG specific representation.
	  
\endverbatim
*/
class PLMXML_UGS60_API RepresentationData : public Attribute
{
public:
     
    //! Default constructor
    RepresentationData( );
     
    //! Constructs a RepresentationData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RepresentationData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RepresentationData();

private:

	//! Assignment operator
	RepresentationData& operator=( const RepresentationData& iSrc );

	//! Copy constructor
	RepresentationData( const RepresentationData& original );
     
public:

	//! Get Units of this RepresentationData
	plmxml_api::String GetUnits() const;

	//! Set Units of this RepresentationData
	plmxml_api::Result SetUnits( const plmxml_api::String &s );
	
	//! Check if Units is set
	plmxml_api::logical HasUnits( ) const;
	
	//! Unset Units
	plmxml_api::Result UnsetUnits( );

	//! Get Type of this RepresentationData
	plmxml_api::String GetType() const;

	//! Set Type of this RepresentationData
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Set Format
	plmxml_api::Result SetFormat( const plmxml60::eRepresentationFormatType& arg );

	//! Get Format
	plmxml60::eRepresentationFormatType GetFormat() const;

	//! Get PartNumber of this RepresentationData
	plmxml_api::String GetPartNumber() const;

	//! Set PartNumber of this RepresentationData
	plmxml_api::Result SetPartNumber( const plmxml_api::String &s );
	
	//! Check if PartNumber is set
	plmxml_api::logical HasPartNumber( ) const;
	
	//! Unset PartNumber
	plmxml_api::Result UnsetPartNumber( );

	//! Get Revision of this RepresentationData
	plmxml_api::String GetRevision() const;

	//! Set Revision of this RepresentationData
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );
 
// <PLMXML_UserCode type="functionHeaderRepresentationData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassRepresentationData;


////////////////////////////////////////////////////////////////////////////////////
//! MassConstraints class
/*!
\verbatim

\endverbatim
*/
class PLMXML_UGS60_API MassConstraints : public plmxml_api::Object
{
public:
     
    //! Default constructor
    MassConstraints( );
     
    //! Constructs a MassConstraints with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MassConstraints( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MassConstraints();

private:

	//! Assignment operator
	MassConstraints& operator=( const MassConstraints& iSrc );

	//! Copy constructor
	MassConstraints( const MassConstraints& original );
     
public:

	//! Set Maximum
	plmxml_api::Result SetMaximum( double arg );

     //! Get Maximum
	double GetMaximum() const;

	//! Check if Maximum is set
	plmxml_api::logical HasMaximum() const;

	//! Unset Maximum
	plmxml_api::Result UnsetMaximum();

	//! Set Minimum
	plmxml_api::Result SetMinimum( double arg );

     //! Get Minimum
	double GetMinimum() const;

	//! Check if Minimum is set
	plmxml_api::logical HasMinimum() const;

	//! Unset Minimum
	plmxml_api::Result UnsetMinimum();

	//! Set Units
	plmxml_api::Result SetUnits( const eMassConstraintsUnitType& arg );

	//! Get Units
	eMassConstraintsUnitType GetUnits() const;
 
// <PLMXML_UserCode type="functionHeaderMassConstraints" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassMassConstraints;


////////////////////////////////////////////////////////////////////////////////////
//! PartConstraints class
/*!
\verbatim

\endverbatim
*/
class PLMXML_UGS60_API PartConstraints : public Attribute
{
public:
     
    //! Default constructor
    PartConstraints( );
     
    //! Constructs a PartConstraints with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PartConstraints( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PartConstraints();

private:

	//! Assignment operator
	PartConstraints& operator=( const PartConstraints& iSrc );

	//! Copy constructor
	PartConstraints( const PartConstraints& original );
     
public:

	//! Add Mass child element to this PartConstraints. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MassConstraints *AddMass();
     
	//! Add 'arg' as Mass child element to this PartConstraints.
	plmxml_api::Result AddMass( MassConstraints *arg );

	//! Detach and delete all Mass child elements.
	void DeleteMasses();
     
	//! Get number of Mass child elements.
	int NumberOfMasses() const;
     
	//! Get i'th Mass child element.
	MassConstraints *GetMass( int i ) const;
     
	//! Get all Mass child element as an array
	void GetMasses( plmxml_api::Array<MassConstraints*> &array ) const;
	     
	//! Detach and delete i'th Mass child element
	void DeleteMass( int i );
     
	//! Detach and delete 'arg' if it's one of the Mass child elements
	void DeleteMass( MassConstraints *arg );
 
// <PLMXML_UserCode type="functionHeaderPartConstraints" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassPartConstraints;


////////////////////////////////////////////////////////////////////////////////////
//! UGRep class
/*!
\verbatim

	  UG Representation component of the PLMXML Schema
	  
\endverbatim
*/
class PLMXML_UGS60_API UGRep : public InternalRep
{
public:
     
    //! Default constructor
    UGRep( );
     
    //! Constructs a UGRep with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    UGRep( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~UGRep();

private:

	//! Assignment operator
	UGRep& operator=( const UGRep& iSrc );

	//! Copy constructor
	UGRep( const UGRep& original );
     
public:

	//! Set Units
	plmxml_api::Result SetUnits( const ePartUnitsType& arg );

	//! Get Units
	ePartUnitsType GetUnits() const;

	//! Get Type of this UGRep
	plmxml_api::String GetType() const;

	//! Set Type of this UGRep
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Set Format
	plmxml_api::Result SetFormat( const plmxml60::eRepresentationFormatType& arg );

	//! Get Format
	plmxml60::eRepresentationFormatType GetFormat() const;

	//! Get PartNumber of this UGRep
	plmxml_api::String GetPartNumber() const;

	//! Set PartNumber of this UGRep
	plmxml_api::Result SetPartNumber( const plmxml_api::String &s );
	
	//! Check if PartNumber is set
	plmxml_api::logical HasPartNumber( ) const;
	
	//! Unset PartNumber
	plmxml_api::Result UnsetPartNumber( );

	//! Get Revision of this UGRep
	plmxml_api::String GetRevision() const;

	//! Set Revision of this UGRep
	plmxml_api::Result SetRevision( const plmxml_api::String &s );
	
	//! Check if Revision is set
	plmxml_api::logical HasRevision( ) const;
	
	//! Unset Revision
	plmxml_api::Result UnsetRevision( );

	//! Add Representation child element to this UGRep. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Representation *AddRepresentation();
     
	//! Add 'arg' as Representation child element to this UGRep.
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
 
// <PLMXML_UserCode type="functionHeaderUGRep" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_UGS60_API plmxml_api::plmxmlClass plmxmlClassUGRep;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
