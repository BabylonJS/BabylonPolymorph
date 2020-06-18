/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.0.30330 23/02/2009 16:57:12
// 
// Schema:	PLMXMLRouteListSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_ROUTELIST60_H__
#define __PLMXML_ROUTELIST60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_ROUTELIST60_EXPORTS
#define PLMXML_ROUTELIST60_API __declspec(dllexport)
#else
#define PLMXML_ROUTELIST60_API __declspec(dllimport)
#endif
#else
#define PLMXML_ROUTELIST60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>

#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
/*! \namespace plmxml_rl60
    \brief PLM XML SDK RouteList schema specific API namespace.

    plmxml_rl60 namespace includes RouteList schema specific auto-generated classes.
*/
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml_rl60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eRouted class
/*!
Allowed Values:
\verbatim
  eRoutedManual
	"manual"
  eRoutedNotRouted
	"notRouted"
  eRoutedAuto
	"auto"
  
\endverbatim
*/
class PLMXML_ROUTELIST60_API eRouted : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRouted( const char* Type );
     
	//! Constructor
	eRouted( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRouted( );
     
	//! Destructor 
	virtual ~eRouted( );
     
	//! Assign from 'Type'
	const eRouted& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRouted& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Routed
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator==( const eRouted& e1, const eRouted& e2 );
     
	//! Compare Routed
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator!=( const eRouted& e1, const eRouted& e2 );
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRouted;
extern PLMXML_ROUTELIST60_API eRouted eRoutedUnset;
extern PLMXML_ROUTELIST60_API eRouted eRoutedManual;
extern PLMXML_ROUTELIST60_API eRouted eRoutedNotRouted;
extern PLMXML_ROUTELIST60_API eRouted eRoutedAuto;

////////////////////////////////////////////////////////////////////////////////////
//! eType class
/*!
Allowed Values:
\verbatim
  eTypeOther
	"other"
  eTypeConnector
	"connector"
  eTypeSplice
	"splice"
  
\endverbatim
*/
class PLMXML_ROUTELIST60_API eType : public plmxml_api::EnumBase
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
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator==( const eType& e1, const eType& e2 );
     
	//! Compare Type
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator!=( const eType& e1, const eType& e2 );
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumType;
extern PLMXML_ROUTELIST60_API eType eTypeUnset;
extern PLMXML_ROUTELIST60_API eType eTypeOther;
extern PLMXML_ROUTELIST60_API eType eTypeConnector;
extern PLMXML_ROUTELIST60_API eType eTypeSplice;

////////////////////////////////////////////////////////////////////////////////////
//! eCrossSectionType class
/*!
Allowed Values:
\verbatim
  eCrossSectionTypeCircular
	"circular"
  eCrossSectionTypeFlat
	"flat"
  
\endverbatim
*/
class PLMXML_ROUTELIST60_API eCrossSectionType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCrossSectionType( const char* Type );
     
	//! Constructor
	eCrossSectionType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCrossSectionType( );
     
	//! Destructor 
	virtual ~eCrossSectionType( );
     
	//! Assign from 'Type'
	const eCrossSectionType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCrossSectionType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CrossSectionType
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator==( const eCrossSectionType& e1, const eCrossSectionType& e2 );
     
	//! Compare CrossSectionType
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator!=( const eCrossSectionType& e1, const eCrossSectionType& e2 );
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCrossSectionType;
extern PLMXML_ROUTELIST60_API eCrossSectionType eCrossSectionTypeUnset;
extern PLMXML_ROUTELIST60_API eCrossSectionType eCrossSectionTypeCircular;
extern PLMXML_ROUTELIST60_API eCrossSectionType eCrossSectionTypeFlat;

////////////////////////////////////////////////////////////////////////////////////
//! eWireClass class
/*!
Allowed Values:
\verbatim
  eWireClassTwisted
	"twisted"
  eWireClassRegular
	"regular"
  eWireClassStowed
	"stowed"
  
\endverbatim
*/
class PLMXML_ROUTELIST60_API eWireClass : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eWireClass( const char* Type );
     
	//! Constructor
	eWireClass( const plmxml_api::String& Type );
     
	//! Default Constructor
	eWireClass( );
     
	//! Destructor 
	virtual ~eWireClass( );
     
	//! Assign from 'Type'
	const eWireClass& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eWireClass& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare WireClass
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator==( const eWireClass& e1, const eWireClass& e2 );
     
	//! Compare WireClass
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator!=( const eWireClass& e1, const eWireClass& e2 );
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumWireClass;
extern PLMXML_ROUTELIST60_API eWireClass eWireClassUnset;
extern PLMXML_ROUTELIST60_API eWireClass eWireClassTwisted;
extern PLMXML_ROUTELIST60_API eWireClass eWireClassRegular;
extern PLMXML_ROUTELIST60_API eWireClass eWireClassStowed;

////////////////////////////////////////////////////////////////////////////////////
//! eAssigned class
/*!
Allowed Values:
\verbatim
  eAssignedManual
	"manual"
  eAssignedNotAssigned
	"notAssigned"
  eAssignedAuto
	"auto"
  
\endverbatim
*/
class PLMXML_ROUTELIST60_API eAssigned : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eAssigned( const char* Type );
     
	//! Constructor
	eAssigned( const plmxml_api::String& Type );
     
	//! Default Constructor
	eAssigned( );
     
	//! Destructor 
	virtual ~eAssigned( );
     
	//! Assign from 'Type'
	const eAssigned& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eAssigned& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare Assigned
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator==( const eAssigned& e1, const eAssigned& e2 );
     
	//! Compare Assigned
	friend plmxml_api::logical PLMXML_ROUTELIST60_API operator!=( const eAssigned& e1, const eAssigned& e2 );
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumAssigned;
extern PLMXML_ROUTELIST60_API eAssigned eAssignedUnset;
extern PLMXML_ROUTELIST60_API eAssigned eAssignedManual;
extern PLMXML_ROUTELIST60_API eAssigned eAssignedNotAssigned;
extern PLMXML_ROUTELIST60_API eAssigned eAssignedAuto;

//! Forward class declarations
using plmxml60::DescriptionObject;

////////////////////////////////////////////////////////////////////////////////////
//! RouteListElement class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ROUTELIST60_API RouteListElement : public plmxml60::DescriptionObject
{
public:
     
    //! Default constructor
    RouteListElement( );
     
    //! Constructs a RouteListElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteListElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteListElement();

private:

	//! Assignment operator
	RouteListElement& operator=( const RouteListElement& iSrc );

	//! Copy constructor
	RouteListElement( const RouteListElement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderRouteListElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassRouteListElement;


////////////////////////////////////////////////////////////////////////////////////
//! IdentifiedRouteListElement class
/*!
\verbatim

\endverbatim
*/
class PLMXML_ROUTELIST60_API IdentifiedRouteListElement : public RouteListElement
{
public:
     
    //! Default constructor
    IdentifiedRouteListElement( );
     
    //! Constructs a IdentifiedRouteListElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IdentifiedRouteListElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IdentifiedRouteListElement();

private:

	//! Assignment operator
	IdentifiedRouteListElement& operator=( const IdentifiedRouteListElement& iSrc );

	//! Copy constructor
	IdentifiedRouteListElement( const IdentifiedRouteListElement& original );
     
public:

	//! Get UniqueId of this IdentifiedRouteListElement
	plmxml_api::String GetUniqueId() const;

	//! Set UniqueId of this IdentifiedRouteListElement
	plmxml_api::Result SetUniqueId( const plmxml_api::String &s );
	
	//! Check if UniqueId is set
	plmxml_api::logical HasUniqueId( ) const;
	
	//! Unset UniqueId
	plmxml_api::Result UnsetUniqueId( );

	//! Add UserData child element to this IdentifiedRouteListElement. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserData *AddUserData();
     
	//! Add 'arg' as UserData child element to this IdentifiedRouteListElement.
	plmxml_api::Result AddUserData( plmxml60::UserData *arg );

	//! Detach and delete all UserData child elements.
	void DeleteUserDatas();
     
	//! Get number of UserData child elements.
	int NumberOfUserDatas() const;
     
	//! Get i'th UserData child element.
	plmxml60::UserData *GetUserData( int i ) const;
     
	//! Get all UserData child element as an array
	void GetUserDatas( plmxml_api::Array<plmxml60::UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData child element
	void DeleteUserData( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData child elements
	void DeleteUserData( plmxml60::UserData *arg );
 
// <PLMXML_UserCode type="functionHeaderIdentifiedRouteListElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassIdentifiedRouteListElement;


////////////////////////////////////////////////////////////////////////////////////
//! ElectricalComponentDefinition class
/*!
\verbatim
 Contains properties of electrical component
\endverbatim
*/
class PLMXML_ROUTELIST60_API ElectricalComponentDefinition : public IdentifiedRouteListElement
{
public:
     
    //! Default constructor
    ElectricalComponentDefinition( );
     
    //! Constructs a ElectricalComponentDefinition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ElectricalComponentDefinition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ElectricalComponentDefinition();

private:

	//! Assignment operator
	ElectricalComponentDefinition& operator=( const ElectricalComponentDefinition& iSrc );

	//! Copy constructor
	ElectricalComponentDefinition( const ElectricalComponentDefinition& original );
     
public:

	//! Get ProductId of this ElectricalComponentDefinition
	plmxml_api::String GetProductId() const;

	//! Set ProductId of this ElectricalComponentDefinition
	plmxml_api::Result SetProductId( const plmxml_api::String &s );
	
	//! Check if ProductId is set
	plmxml_api::logical HasProductId( ) const;
	
	//! Unset ProductId
	plmxml_api::Result UnsetProductId( );
 
// <PLMXML_UserCode type="functionHeaderElectricalComponentDefinition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassElectricalComponentDefinition;


////////////////////////////////////////////////////////////////////////////////////
//! ElectricalComponentUsage class
/*!
\verbatim
 Contains properties of electrical component
\endverbatim
*/
class PLMXML_ROUTELIST60_API ElectricalComponentUsage : public IdentifiedRouteListElement
{
public:
     
    //! Default constructor
    ElectricalComponentUsage( );
     
    //! Constructs a ElectricalComponentUsage with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ElectricalComponentUsage( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ElectricalComponentUsage();

private:

	//! Assignment operator
	ElectricalComponentUsage& operator=( const ElectricalComponentUsage& iSrc );

	//! Copy constructor
	ElectricalComponentUsage( const ElectricalComponentUsage& original );
     
public:

	//! Get InstanceName of this ElectricalComponentUsage
	plmxml_api::String GetInstanceName() const;

	//! Set InstanceName of this ElectricalComponentUsage
	plmxml_api::Result SetInstanceName( const plmxml_api::String &s );
	
	//! Check if InstanceName is set
	plmxml_api::logical HasInstanceName( ) const;
	
	//! Unset InstanceName
	plmxml_api::Result UnsetInstanceName( );

	//! Set Assigned
	plmxml_api::Result SetAssigned( const eAssigned& arg );

	//! Get Assigned
	eAssigned GetAssigned() const;

	//! Set IsRouted
	plmxml_api::Result SetIsRouted( plmxml_api::logical arg );

	//! Get IsRouted
	plmxml_api::logical GetIsRouted() const;

	//! Check if IsRouted is set
	plmxml_api::logical HasIsRouted() const;

	//! Unset IsRouted
	plmxml_api::Result UnsetIsRouted();

	//! Get Component URI as plmxml_api::String
	plmxml_api::String GetComponentURI() const;

	//! Set Component URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetComponentURI( const plmxml_api::String& );
	
	//! Get the handle of Component URI. Does not resolve the URI.
	plmxml_api::Result GetComponentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Component URI. URI string is unchanged.
	plmxml_api::Result SetComponentURI( const plmxml_api::Handle& );
	
	//! Resolve Component URI and return an object (handle) it points to.
	plmxml_api::Result ResolveComponentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Component URI. Clears URI string and handle.
	plmxml_api::Result DeleteComponentURI();
	
	//! Check if Component URI is set
	plmxml_api::logical HasComponentURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderElectricalComponentUsage" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassElectricalComponentUsage;


////////////////////////////////////////////////////////////////////////////////////
//! Wire class
/*!
\verbatim
Contains physical Wire Properties
\endverbatim
*/
class PLMXML_ROUTELIST60_API Wire : public RouteListElement
{
public:
     
    //! Default constructor
    Wire( );
     
    //! Constructs a Wire with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Wire( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Wire();

private:

	//! Assignment operator
	Wire& operator=( const Wire& iSrc );

	//! Copy constructor
	Wire( const Wire& original );
     
public:

	//! Get Type of this Wire
	plmxml_api::String GetType() const;

	//! Set Type of this Wire
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Set MaxLengthAllowed
	plmxml_api::Result SetMaxLengthAllowed( double arg );

     //! Get MaxLengthAllowed
	double GetMaxLengthAllowed() const;

	//! Check if MaxLengthAllowed is set
	plmxml_api::logical HasMaxLengthAllowed() const;

	//! Unset MaxLengthAllowed
	plmxml_api::Result UnsetMaxLengthAllowed();

	//! Set Gauge
	plmxml_api::Result SetGauge( int arg );
     
	//! Get Gauge
	int GetGauge() const;
     
	//! Check if Gauge is set
	plmxml_api::logical HasGauge() const;
     
	//! Unset Gauge
	plmxml_api::Result UnsetGauge();

	//! Set OuterDiameter
	plmxml_api::Result SetOuterDiameter( double arg );

     //! Get OuterDiameter
	double GetOuterDiameter() const;

	//! Check if OuterDiameter is set
	plmxml_api::logical HasOuterDiameter() const;

	//! Unset OuterDiameter
	plmxml_api::Result UnsetOuterDiameter();

	//! Get MaterialName of this Wire
	plmxml_api::String GetMaterialName() const;

	//! Set MaterialName of this Wire
	plmxml_api::Result SetMaterialName( const plmxml_api::String &s );
	
	//! Check if MaterialName is set
	plmxml_api::logical HasMaterialName( ) const;
	
	//! Unset MaterialName
	plmxml_api::Result UnsetMaterialName( );

	//! Get ProductId of this Wire
	plmxml_api::String GetProductId() const;

	//! Set ProductId of this Wire
	plmxml_api::Result SetProductId( const plmxml_api::String &s );
	
	//! Check if ProductId is set
	plmxml_api::logical HasProductId( ) const;
	
	//! Unset ProductId
	plmxml_api::Result UnsetProductId( );

	//! Set MinBendRadius
	plmxml_api::Result SetMinBendRadius( double arg );

     //! Get MinBendRadius
	double GetMinBendRadius() const;

	//! Check if MinBendRadius is set
	plmxml_api::logical HasMinBendRadius() const;

	//! Unset MinBendRadius
	plmxml_api::Result UnsetMinBendRadius();

	//! Set LinearDensity
	plmxml_api::Result SetLinearDensity( double arg );

     //! Get LinearDensity
	double GetLinearDensity() const;

	//! Check if LinearDensity is set
	plmxml_api::logical HasLinearDensity() const;

	//! Unset LinearDensity
	plmxml_api::Result UnsetLinearDensity();

	//! Set MinLengthAllowed
	plmxml_api::Result SetMinLengthAllowed( double arg );

     //! Get MinLengthAllowed
	double GetMinLengthAllowed() const;

	//! Check if MinLengthAllowed is set
	plmxml_api::logical HasMinLengthAllowed() const;

	//! Unset MinLengthAllowed
	plmxml_api::Result UnsetMinLengthAllowed();

	//! Get ColourName of this Wire
	plmxml_api::String GetColourName() const;

	//! Set ColourName of this Wire
	plmxml_api::Result SetColourName( const plmxml_api::String &s );
	
	//! Check if ColourName is set
	plmxml_api::logical HasColourName( ) const;
	
	//! Unset ColourName
	plmxml_api::Result UnsetColourName( );

	//! Set Colour array
	plmxml_api::Result SetColour( const double *arg );

	//! Get Colour array
	plmxml_api::Result GetColour( double *arg ) const;

	//! Check if Colour array is set
	plmxml_api::logical HasColour() const;

	//! Unset Colour array
	plmxml_api::Result UnsetColour();

	//! Get MaterialType of this Wire
	plmxml_api::String GetMaterialType() const;

	//! Set MaterialType of this Wire
	plmxml_api::Result SetMaterialType( const plmxml_api::String &s );
	
	//! Check if MaterialType is set
	plmxml_api::logical HasMaterialType( ) const;
	
	//! Unset MaterialType
	plmxml_api::Result UnsetMaterialType( );

	//! Add UserData child element to this Wire. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserData *AddUserData();
     
	//! Add 'arg' as UserData child element to this Wire.
	plmxml_api::Result AddUserData( plmxml60::UserData *arg );

	//! Detach and delete all UserData child elements.
	void DeleteUserDatas();
     
	//! Get number of UserData child elements.
	int NumberOfUserDatas() const;
     
	//! Get i'th UserData child element.
	plmxml60::UserData *GetUserData( int i ) const;
     
	//! Get all UserData child element as an array
	void GetUserDatas( plmxml_api::Array<plmxml60::UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData child element
	void DeleteUserData( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData child elements
	void DeleteUserData( plmxml60::UserData *arg );
 
// <PLMXML_UserCode type="functionHeaderWire" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassWire;


////////////////////////////////////////////////////////////////////////////////////
//! Cable class
/*!
\verbatim
Contains physical Cable Properties
\endverbatim
*/
class PLMXML_ROUTELIST60_API Cable : public RouteListElement
{
public:
     
    //! Default constructor
    Cable( );
     
    //! Constructs a Cable with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Cable( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Cable();

private:

	//! Assignment operator
	Cable& operator=( const Cable& iSrc );

	//! Copy constructor
	Cable( const Cable& original );
     
public:

	//! Set Shielding
	plmxml_api::Result SetShielding( plmxml_api::logical arg );

	//! Get Shielding
	plmxml_api::logical GetShielding() const;

	//! Check if Shielding is set
	plmxml_api::logical HasShielding() const;

	//! Unset Shielding
	plmxml_api::Result UnsetShielding();

	//! Get number of URIs in Cable
	int NumberOfCableURIs() const;

	//! Get i'th URI in Cable
	plmxml_api::String GetCableURI( int i ) const;

	//! Add a URI to Cable array. Call ResolveCableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddCableURI( const plmxml_api::String& u );

	//! Set i'th URI in Cable array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetCableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Cable URI. Does not resolve the URI.
	plmxml_api::Result GetCableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Cable array.
	plmxml_api::Result AddCableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Cable array to point to 'handle'.
	plmxml_api::Result SetCableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Cable points to.
	plmxml_api::Result ResolveCableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Cable array.
	plmxml_api::Result DeleteCableURI( int i );

	//! Remove all URIs from Cable array.
	plmxml_api::Result DeleteCableURIs( );
	
	//! Check if Cable is set
	plmxml_api::logical HasCableURIs( ) const;

	//! Set CoverThickness
	plmxml_api::Result SetCoverThickness( double arg );

     //! Get CoverThickness
	double GetCoverThickness() const;

	//! Check if CoverThickness is set
	plmxml_api::logical HasCoverThickness() const;

	//! Unset CoverThickness
	plmxml_api::Result UnsetCoverThickness();

	//! Set CrossSectionType
	plmxml_api::Result SetCrossSectionType( const eCrossSectionType& arg );

	//! Get CrossSectionType
	eCrossSectionType GetCrossSectionType() const;

	//! Set OuterDiameter
	plmxml_api::Result SetOuterDiameter( double arg );

     //! Get OuterDiameter
	double GetOuterDiameter() const;

	//! Check if OuterDiameter is set
	plmxml_api::logical HasOuterDiameter() const;

	//! Unset OuterDiameter
	plmxml_api::Result UnsetOuterDiameter();

	//! Set Width
	plmxml_api::Result SetWidth( double arg );

     //! Get Width
	double GetWidth() const;

	//! Check if Width is set
	plmxml_api::logical HasWidth() const;

	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Set Spacing
	plmxml_api::Result SetSpacing( double arg );

     //! Get Spacing
	double GetSpacing() const;

	//! Check if Spacing is set
	plmxml_api::logical HasSpacing() const;

	//! Unset Spacing
	plmxml_api::Result UnsetSpacing();

	//! Get ColourName of this Cable
	plmxml_api::String GetColourName() const;

	//! Set ColourName of this Cable
	plmxml_api::Result SetColourName( const plmxml_api::String &s );
	
	//! Check if ColourName is set
	plmxml_api::logical HasColourName( ) const;
	
	//! Unset ColourName
	plmxml_api::Result UnsetColourName( );

	//! Get MaterialName of this Cable
	plmxml_api::String GetMaterialName() const;

	//! Set MaterialName of this Cable
	plmxml_api::Result SetMaterialName( const plmxml_api::String &s );
	
	//! Check if MaterialName is set
	plmxml_api::logical HasMaterialName( ) const;
	
	//! Unset MaterialName
	plmxml_api::Result UnsetMaterialName( );

	//! Get ProductId of this Cable
	plmxml_api::String GetProductId() const;

	//! Set ProductId of this Cable
	plmxml_api::Result SetProductId( const plmxml_api::String &s );
	
	//! Check if ProductId is set
	plmxml_api::logical HasProductId( ) const;
	
	//! Unset ProductId
	plmxml_api::Result UnsetProductId( );

	//! Set Height
	plmxml_api::Result SetHeight( double arg );

     //! Get Height
	double GetHeight() const;

	//! Check if Height is set
	plmxml_api::logical HasHeight() const;

	//! Unset Height
	plmxml_api::Result UnsetHeight();

	//! Get number of URIs in Wire
	int NumberOfWireURIs() const;

	//! Get i'th URI in Wire
	plmxml_api::String GetWireURI( int i ) const;

	//! Add a URI to Wire array. Call ResolveWireURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddWireURI( const plmxml_api::String& u );

	//! Set i'th URI in Wire array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetWireURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Wire URI. Does not resolve the URI.
	plmxml_api::Result GetWireURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Wire array.
	plmxml_api::Result AddWireURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Wire array to point to 'handle'.
	plmxml_api::Result SetWireURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Wire points to.
	plmxml_api::Result ResolveWireURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Wire array.
	plmxml_api::Result DeleteWireURI( int i );

	//! Remove all URIs from Wire array.
	plmxml_api::Result DeleteWireURIs( );
	
	//! Check if Wire is set
	plmxml_api::logical HasWireURIs( ) const;

	//! Set LinearDensity
	plmxml_api::Result SetLinearDensity( double arg );

     //! Get LinearDensity
	double GetLinearDensity() const;

	//! Check if LinearDensity is set
	plmxml_api::logical HasLinearDensity() const;

	//! Unset LinearDensity
	plmxml_api::Result UnsetLinearDensity();

	//! Get MaterialType of this Cable
	plmxml_api::String GetMaterialType() const;

	//! Set MaterialType of this Cable
	plmxml_api::Result SetMaterialType( const plmxml_api::String &s );
	
	//! Check if MaterialType is set
	plmxml_api::logical HasMaterialType( ) const;
	
	//! Unset MaterialType
	plmxml_api::Result UnsetMaterialType( );

	//! Set Colour array
	plmxml_api::Result SetColour( const double *arg );

	//! Get Colour array
	plmxml_api::Result GetColour( double *arg ) const;

	//! Check if Colour array is set
	plmxml_api::logical HasColour() const;

	//! Unset Colour array
	plmxml_api::Result UnsetColour();

	//! Add UserData child element to this Cable. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserData *AddUserData();
     
	//! Add 'arg' as UserData child element to this Cable.
	plmxml_api::Result AddUserData( plmxml60::UserData *arg );

	//! Detach and delete all UserData child elements.
	void DeleteUserDatas();
     
	//! Get number of UserData child elements.
	int NumberOfUserDatas() const;
     
	//! Get i'th UserData child element.
	plmxml60::UserData *GetUserData( int i ) const;
     
	//! Get all UserData child element as an array
	void GetUserDatas( plmxml_api::Array<plmxml60::UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData child element
	void DeleteUserData( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData child elements
	void DeleteUserData( plmxml60::UserData *arg );
 
// <PLMXML_UserCode type="functionHeaderCable" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassCable;


////////////////////////////////////////////////////////////////////////////////////
//! SpaceReservation class
/*!
\verbatim
 Contains space-reservation properties
\endverbatim
*/
class PLMXML_ROUTELIST60_API SpaceReservation : public RouteListElement
{
public:
     
    //! Default constructor
    SpaceReservation( );
     
    //! Constructs a SpaceReservation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpaceReservation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpaceReservation();

private:

	//! Assignment operator
	SpaceReservation& operator=( const SpaceReservation& iSrc );

	//! Copy constructor
	SpaceReservation( const SpaceReservation& original );
     
public:

	//! Set CrossSectionType
	plmxml_api::Result SetCrossSectionType( const eCrossSectionType& arg );

	//! Get CrossSectionType
	eCrossSectionType GetCrossSectionType() const;

	//! Set Offset
	plmxml_api::Result SetOffset( double arg );

     //! Get Offset
	double GetOffset() const;

	//! Check if Offset is set
	plmxml_api::logical HasOffset() const;

	//! Unset Offset
	plmxml_api::Result UnsetOffset();

	//! Set OuterDiameter
	plmxml_api::Result SetOuterDiameter( double arg );

     //! Get OuterDiameter
	double GetOuterDiameter() const;

	//! Check if OuterDiameter is set
	plmxml_api::logical HasOuterDiameter() const;

	//! Unset OuterDiameter
	plmxml_api::Result UnsetOuterDiameter();

	//! Set Width
	plmxml_api::Result SetWidth( double arg );

     //! Get Width
	double GetWidth() const;

	//! Check if Width is set
	plmxml_api::logical HasWidth() const;

	//! Unset Width
	plmxml_api::Result UnsetWidth();

	//! Set Height
	plmxml_api::Result SetHeight( double arg );

     //! Get Height
	double GetHeight() const;

	//! Check if Height is set
	plmxml_api::logical HasHeight() const;

	//! Unset Height
	plmxml_api::Result UnsetHeight();

	//! Set Multiplier
	plmxml_api::Result SetMultiplier( double arg );

     //! Get Multiplier
	double GetMultiplier() const;

	//! Check if Multiplier is set
	plmxml_api::logical HasMultiplier() const;

	//! Unset Multiplier
	plmxml_api::Result UnsetMultiplier();
 
// <PLMXML_UserCode type="functionHeaderSpaceReservation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassSpaceReservation;


////////////////////////////////////////////////////////////////////////////////////
//! Harness class
/*!
\verbatim
 Contains Harness properties. (Fabrication etc.)    
\endverbatim
*/
class PLMXML_ROUTELIST60_API Harness : public RouteListElement
{
public:
     
    //! Default constructor
    Harness( );
     
    //! Constructs a Harness with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Harness( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Harness();

private:

	//! Assignment operator
	Harness& operator=( const Harness& iSrc );

	//! Copy constructor
	Harness( const Harness& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderHarness" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassHarness;


////////////////////////////////////////////////////////////////////////////////////
//! NonHarnessComponent class
/*!
\verbatim
 Electrical components but not part of harnesses (Ex: Device)
\endverbatim
*/
class PLMXML_ROUTELIST60_API NonHarnessComponent : public ElectricalComponentUsage
{
public:
     
    //! Default constructor
    NonHarnessComponent( );
     
    //! Constructs a NonHarnessComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NonHarnessComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NonHarnessComponent();

private:

	//! Assignment operator
	NonHarnessComponent& operator=( const NonHarnessComponent& iSrc );

	//! Copy constructor
	NonHarnessComponent( const NonHarnessComponent& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderNonHarnessComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassNonHarnessComponent;


////////////////////////////////////////////////////////////////////////////////////
//! HarnessComponent class
/*!
\verbatim
 Harness electrical components (Connector, splice etc.)
\endverbatim
*/
class PLMXML_ROUTELIST60_API HarnessComponent : public ElectricalComponentUsage
{
public:
     
    //! Default constructor
    HarnessComponent( );
     
    //! Constructs a HarnessComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HarnessComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HarnessComponent();

private:

	//! Assignment operator
	HarnessComponent& operator=( const HarnessComponent& iSrc );

	//! Copy constructor
	HarnessComponent( const HarnessComponent& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eType& arg );

	//! Get Type
	eType GetType() const;

	//! Get NonHarnessComponent URI as plmxml_api::String
	plmxml_api::String GetNonHarnessComponentURI() const;

	//! Set NonHarnessComponent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetNonHarnessComponentURI( const plmxml_api::String& );
	
	//! Get the handle of NonHarnessComponent URI. Does not resolve the URI.
	plmxml_api::Result GetNonHarnessComponentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of NonHarnessComponent URI. URI string is unchanged.
	plmxml_api::Result SetNonHarnessComponentURI( const plmxml_api::Handle& );
	
	//! Resolve NonHarnessComponent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveNonHarnessComponentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset NonHarnessComponent URI. Clears URI string and handle.
	plmxml_api::Result DeleteNonHarnessComponentURI();
	
	//! Check if NonHarnessComponent URI is set
	plmxml_api::logical HasNonHarnessComponentURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderHarnessComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassHarnessComponent;


////////////////////////////////////////////////////////////////////////////////////
//! ConductorOccurrence class
/*!
\verbatim
 Contains properties of conductor (Wire/Cable/SpaceReservation) i.e assigned to a connection
\endverbatim
*/
class PLMXML_ROUTELIST60_API ConductorOccurrence : public IdentifiedRouteListElement
{
public:
     
    //! Default constructor
    ConductorOccurrence( );
     
    //! Constructs a ConductorOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConductorOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConductorOccurrence();

private:

	//! Assignment operator
	ConductorOccurrence& operator=( const ConductorOccurrence& iSrc );

	//! Copy constructor
	ConductorOccurrence( const ConductorOccurrence& original );
     
public:

	//! Set WireClass
	plmxml_api::Result SetWireClass( const eWireClass& arg );

	//! Get WireClass
	eWireClass GetWireClass() const;

	//! Get Conductor URI as plmxml_api::String
	plmxml_api::String GetConductorURI() const;

	//! Set Conductor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetConductorURI( const plmxml_api::String& );
	
	//! Get the handle of Conductor URI. Does not resolve the URI.
	plmxml_api::Result GetConductorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Conductor URI. URI string is unchanged.
	plmxml_api::Result SetConductorURI( const plmxml_api::Handle& );
	
	//! Resolve Conductor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveConductorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Conductor URI. Clears URI string and handle.
	plmxml_api::Result DeleteConductorURI();
	
	//! Check if Conductor URI is set
	plmxml_api::logical HasConductorURI( ) const;
	

	//! Set Routed
	plmxml_api::Result SetRouted( const eRouted& arg );

	//! Get Routed
	eRouted GetRouted() const;

	//! Set CutLength
	plmxml_api::Result SetCutLength( double arg );

     //! Get CutLength
	double GetCutLength() const;

	//! Check if CutLength is set
	plmxml_api::logical HasCutLength() const;

	//! Unset CutLength
	plmxml_api::Result UnsetCutLength();

	//! Get WireSignal of this ConductorOccurrence
	plmxml_api::String GetWireSignal() const;

	//! Set WireSignal of this ConductorOccurrence
	plmxml_api::Result SetWireSignal( const plmxml_api::String &s );
	
	//! Check if WireSignal is set
	plmxml_api::logical HasWireSignal( ) const;
	
	//! Unset WireSignal
	plmxml_api::Result UnsetWireSignal( );

	//! Set Location
	plmxml_api::Result SetLocation( int arg );
     
	//! Get Location
	int GetLocation() const;
     
	//! Check if Location is set
	plmxml_api::logical HasLocation() const;
     
	//! Unset Location
	plmxml_api::Result UnsetLocation();

	//! Get Harness URI as plmxml_api::String
	plmxml_api::String GetHarnessURI() const;

	//! Set Harness URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetHarnessURI( const plmxml_api::String& );
	
	//! Get the handle of Harness URI. Does not resolve the URI.
	plmxml_api::Result GetHarnessURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Harness URI. URI string is unchanged.
	plmxml_api::Result SetHarnessURI( const plmxml_api::Handle& );
	
	//! Resolve Harness URI and return an object (handle) it points to.
	plmxml_api::Result ResolveHarnessURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Harness URI. Clears URI string and handle.
	plmxml_api::Result DeleteHarnessURI();
	
	//! Check if Harness URI is set
	plmxml_api::logical HasHarnessURI( ) const;
	

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Get WireSeparationCode of this ConductorOccurrence
	plmxml_api::String GetWireSeparationCode() const;

	//! Set WireSeparationCode of this ConductorOccurrence
	plmxml_api::Result SetWireSeparationCode( const plmxml_api::String &s );
	
	//! Check if WireSeparationCode is set
	plmxml_api::logical HasWireSeparationCode( ) const;
	
	//! Unset WireSeparationCode
	plmxml_api::Result UnsetWireSeparationCode( );
 
// <PLMXML_UserCode type="functionHeaderConductorOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassConductorOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! IntermediateComponent class
/*!
\verbatim
 Intermediate splice and pin information for connections
\endverbatim
*/
class PLMXML_ROUTELIST60_API IntermediateComponent : public ElectricalComponentUsage
{
public:
     
    //! Default constructor
    IntermediateComponent( );
     
    //! Constructs a IntermediateComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    IntermediateComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~IntermediateComponent();

private:

	//! Assignment operator
	IntermediateComponent& operator=( const IntermediateComponent& iSrc );

	//! Copy constructor
	IntermediateComponent( const IntermediateComponent& original );
     
public:

	//! Get Pin of this IntermediateComponent
	plmxml_api::String GetPin() const;

	//! Set Pin of this IntermediateComponent
	plmxml_api::Result SetPin( const plmxml_api::String &s );
	
	//! Check if Pin is set
	plmxml_api::logical HasPin( ) const;
	
	//! Unset Pin
	plmxml_api::Result UnsetPin( );
 
// <PLMXML_UserCode type="functionHeaderIntermediateComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassIntermediateComponent;


////////////////////////////////////////////////////////////////////////////////////
//! Connection class
/*!
\verbatim
Connection usage Properties
\endverbatim
*/
class PLMXML_ROUTELIST60_API Connection : public RouteListElement
{
public:
     
    //! Default constructor
    Connection( );
     
    //! Constructs a Connection with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Connection( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Connection();

private:

	//! Assignment operator
	Connection& operator=( const Connection& iSrc );

	//! Copy constructor
	Connection( const Connection& original );
     
public:

	//! Get FromPin of this Connection
	plmxml_api::String GetFromPin() const;

	//! Set FromPin of this Connection
	plmxml_api::Result SetFromPin( const plmxml_api::String &s );
	
	//! Check if FromPin is set
	plmxml_api::logical HasFromPin( ) const;
	
	//! Unset FromPin
	plmxml_api::Result UnsetFromPin( );

	//! Set Offset
	plmxml_api::Result SetOffset( double arg );

     //! Get Offset
	double GetOffset() const;

	//! Check if Offset is set
	plmxml_api::logical HasOffset() const;

	//! Unset Offset
	plmxml_api::Result UnsetOffset();

	//! Get FromComponent URI as plmxml_api::String
	plmxml_api::String GetFromComponentURI() const;

	//! Set FromComponent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFromComponentURI( const plmxml_api::String& );
	
	//! Get the handle of FromComponent URI. Does not resolve the URI.
	plmxml_api::Result GetFromComponentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of FromComponent URI. URI string is unchanged.
	plmxml_api::Result SetFromComponentURI( const plmxml_api::Handle& );
	
	//! Resolve FromComponent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFromComponentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset FromComponent URI. Clears URI string and handle.
	plmxml_api::Result DeleteFromComponentURI();
	
	//! Check if FromComponent URI is set
	plmxml_api::logical HasFromComponentURI( ) const;
	

	//! Get ToComponent URI as plmxml_api::String
	plmxml_api::String GetToComponentURI() const;

	//! Set ToComponent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetToComponentURI( const plmxml_api::String& );
	
	//! Get the handle of ToComponent URI. Does not resolve the URI.
	plmxml_api::Result GetToComponentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ToComponent URI. URI string is unchanged.
	plmxml_api::Result SetToComponentURI( const plmxml_api::Handle& );
	
	//! Resolve ToComponent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveToComponentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ToComponent URI. Clears URI string and handle.
	plmxml_api::Result DeleteToComponentURI();
	
	//! Check if ToComponent URI is set
	plmxml_api::logical HasToComponentURI( ) const;
	

	//! Set Multiplier
	plmxml_api::Result SetMultiplier( double arg );

     //! Get Multiplier
	double GetMultiplier() const;

	//! Check if Multiplier is set
	plmxml_api::logical HasMultiplier() const;

	//! Unset Multiplier
	plmxml_api::Result UnsetMultiplier();

	//! Get ToPin of this Connection
	plmxml_api::String GetToPin() const;

	//! Set ToPin of this Connection
	plmxml_api::Result SetToPin( const plmxml_api::String &s );
	
	//! Check if ToPin is set
	plmxml_api::logical HasToPin( ) const;
	
	//! Unset ToPin
	plmxml_api::Result UnsetToPin( );

	//! Add UserData child element to this Connection. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::UserData *AddUserData();
     
	//! Add 'arg' as UserData child element to this Connection.
	plmxml_api::Result AddUserData( plmxml60::UserData *arg );

	//! Detach and delete all UserData child elements.
	void DeleteUserDatas();
     
	//! Get number of UserData child elements.
	int NumberOfUserDatas() const;
     
	//! Get i'th UserData child element.
	plmxml60::UserData *GetUserData( int i ) const;
     
	//! Get all UserData child element as an array
	void GetUserDatas( plmxml_api::Array<plmxml60::UserData*> &array ) const;
	     
	//! Detach and delete i'th UserData child element
	void DeleteUserData( int i );
     
	//! Detach and delete 'arg' if it's one of the UserData child elements
	void DeleteUserData( plmxml60::UserData *arg );

	//! Add IntermediateComponent child element to this Connection. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	IntermediateComponent *AddIntermediateComponent();
     
	//! Add 'arg' as IntermediateComponent child element to this Connection.
	plmxml_api::Result AddIntermediateComponent( IntermediateComponent *arg );

	//! Detach and delete all IntermediateComponent child elements.
	void DeleteIntermediateComponents();
     
	//! Get number of IntermediateComponent child elements.
	int NumberOfIntermediateComponents() const;
     
	//! Get i'th IntermediateComponent child element.
	IntermediateComponent *GetIntermediateComponent( int i ) const;
     
	//! Get all IntermediateComponent child element as an array
	void GetIntermediateComponents( plmxml_api::Array<IntermediateComponent*> &array ) const;
	     
	//! Detach and delete i'th IntermediateComponent child element
	void DeleteIntermediateComponent( int i );
     
	//! Detach and delete 'arg' if it's one of the IntermediateComponent child elements
	void DeleteIntermediateComponent( IntermediateComponent *arg );

	//! Add ConductorOccurrence child element to this Connection. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConductorOccurrence *AddConductorOccurrence();
     
	//! Add 'arg' as ConductorOccurrence child element to this Connection.
	plmxml_api::Result AddConductorOccurrence( ConductorOccurrence *arg );

	//! Detach and delete all ConductorOccurrence child elements.
	void DeleteConductorOccurrences();
     
	//! Get number of ConductorOccurrence child elements.
	int NumberOfConductorOccurrences() const;
     
	//! Get i'th ConductorOccurrence child element.
	ConductorOccurrence *GetConductorOccurrence( int i ) const;
     
	//! Get all ConductorOccurrence child element as an array
	void GetConductorOccurrences( plmxml_api::Array<ConductorOccurrence*> &array ) const;
	     
	//! Detach and delete i'th ConductorOccurrence child element
	void DeleteConductorOccurrence( int i );
     
	//! Detach and delete 'arg' if it's one of the ConductorOccurrence child elements
	void DeleteConductorOccurrence( ConductorOccurrence *arg );
 
// <PLMXML_UserCode type="functionHeaderConnection" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassConnection;


////////////////////////////////////////////////////////////////////////////////////
//! DisplayFilter class
/*!
\verbatim
Display filters
\endverbatim
*/
class PLMXML_ROUTELIST60_API DisplayFilter : public RouteListElement
{
public:
     
    //! Default constructor
    DisplayFilter( );
     
    //! Constructs a DisplayFilter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DisplayFilter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DisplayFilter();

private:

	//! Assignment operator
	DisplayFilter& operator=( const DisplayFilter& iSrc );

	//! Copy constructor
	DisplayFilter( const DisplayFilter& original );
     
public:

	//! Get FilterClause of this DisplayFilter
	plmxml_api::String GetFilterClause() const;

	//! Set FilterClause of this DisplayFilter
	plmxml_api::Result SetFilterClause( const plmxml_api::String &s );
	
	//! Check if FilterClause is set
	plmxml_api::logical HasFilterClause( ) const;
	
	//! Unset FilterClause
	plmxml_api::Result UnsetFilterClause( );

	//! Get FilterName of this DisplayFilter
	plmxml_api::String GetFilterName() const;

	//! Set FilterName of this DisplayFilter
	plmxml_api::Result SetFilterName( const plmxml_api::String &s );
	
	//! Check if FilterName is set
	plmxml_api::logical HasFilterName( ) const;
	
	//! Unset FilterName
	plmxml_api::Result UnsetFilterName( );
 
// <PLMXML_UserCode type="functionHeaderDisplayFilter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassDisplayFilter;


////////////////////////////////////////////////////////////////////////////////////
//! FormatField class
/*!
\verbatim
Display format fields.  Each display format has associated fields.
\endverbatim
*/
class PLMXML_ROUTELIST60_API FormatField : public RouteListElement
{
public:
     
    //! Default constructor
    FormatField( );
     
    //! Constructs a FormatField with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FormatField( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FormatField();

private:

	//! Assignment operator
	FormatField& operator=( const FormatField& iSrc );

	//! Copy constructor
	FormatField( const FormatField& original );
     
public:

	//! Get FormatFieldName of this FormatField
	plmxml_api::String GetFormatFieldName() const;

	//! Set FormatFieldName of this FormatField
	plmxml_api::Result SetFormatFieldName( const plmxml_api::String &s );
	
	//! Check if FormatFieldName is set
	plmxml_api::logical HasFormatFieldName( ) const;
	
	//! Unset FormatFieldName
	plmxml_api::Result UnsetFormatFieldName( );

	//! Get FormatColumnName of this FormatField
	plmxml_api::String GetFormatColumnName() const;

	//! Set FormatColumnName of this FormatField
	plmxml_api::Result SetFormatColumnName( const plmxml_api::String &s );
	
	//! Check if FormatColumnName is set
	plmxml_api::logical HasFormatColumnName( ) const;
	
	//! Unset FormatColumnName
	plmxml_api::Result UnsetFormatColumnName( );

	//! Set FormatSortOrder
	plmxml_api::Result SetFormatSortOrder( int arg );
     
	//! Get FormatSortOrder
	int GetFormatSortOrder() const;
     
	//! Check if FormatSortOrder is set
	plmxml_api::logical HasFormatSortOrder() const;
     
	//! Unset FormatSortOrder
	plmxml_api::Result UnsetFormatSortOrder();

	//! Set FormatColumnOrder
	plmxml_api::Result SetFormatColumnOrder( int arg );
     
	//! Get FormatColumnOrder
	int GetFormatColumnOrder() const;
     
	//! Check if FormatColumnOrder is set
	plmxml_api::logical HasFormatColumnOrder() const;
     
	//! Unset FormatColumnOrder
	plmxml_api::Result UnsetFormatColumnOrder();

	//! Set FormatColumnWidth
	plmxml_api::Result SetFormatColumnWidth( int arg );
     
	//! Get FormatColumnWidth
	int GetFormatColumnWidth() const;
     
	//! Check if FormatColumnWidth is set
	plmxml_api::logical HasFormatColumnWidth() const;
     
	//! Unset FormatColumnWidth
	plmxml_api::Result UnsetFormatColumnWidth();
 
// <PLMXML_UserCode type="functionHeaderFormatField" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassFormatField;


////////////////////////////////////////////////////////////////////////////////////
//! DisplayFormat class
/*!
\verbatim
Display formats
\endverbatim
*/
class PLMXML_ROUTELIST60_API DisplayFormat : public RouteListElement
{
public:
     
    //! Default constructor
    DisplayFormat( );
     
    //! Constructs a DisplayFormat with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DisplayFormat( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DisplayFormat();

private:

	//! Assignment operator
	DisplayFormat& operator=( const DisplayFormat& iSrc );

	//! Copy constructor
	DisplayFormat( const DisplayFormat& original );
     
public:

	//! Get FormatName of this DisplayFormat
	plmxml_api::String GetFormatName() const;

	//! Set FormatName of this DisplayFormat
	plmxml_api::Result SetFormatName( const plmxml_api::String &s );
	
	//! Check if FormatName is set
	plmxml_api::logical HasFormatName( ) const;
	
	//! Unset FormatName
	plmxml_api::Result UnsetFormatName( );

	//! Get FormatType of this DisplayFormat
	plmxml_api::String GetFormatType() const;

	//! Set FormatType of this DisplayFormat
	plmxml_api::Result SetFormatType( const plmxml_api::String &s );
	
	//! Check if FormatType is set
	plmxml_api::logical HasFormatType( ) const;
	
	//! Unset FormatType
	plmxml_api::Result UnsetFormatType( );

	//! Add FormatField child element to this DisplayFormat. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FormatField *AddFormatField();
     
	//! Add 'arg' as FormatField child element to this DisplayFormat.
	plmxml_api::Result AddFormatField( FormatField *arg );

	//! Detach and delete all FormatField child elements.
	void DeleteFormatFields();
     
	//! Get number of FormatField child elements.
	int NumberOfFormatFields() const;
     
	//! Get i'th FormatField child element.
	FormatField *GetFormatField( int i ) const;
     
	//! Get all FormatField child element as an array
	void GetFormatFields( plmxml_api::Array<FormatField*> &array ) const;
	     
	//! Detach and delete i'th FormatField child element
	void DeleteFormatField( int i );
     
	//! Detach and delete 'arg' if it's one of the FormatField child elements
	void DeleteFormatField( FormatField *arg );
 
// <PLMXML_UserCode type="functionHeaderDisplayFormat" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassDisplayFormat;


//! Forward class declarations
using plmxml60::DocumentBase;

////////////////////////////////////////////////////////////////////////////////////
//! RouteList class
/*!
\verbatim
 Contains Wires, Cables, Components and Connection details
\endverbatim
*/
class PLMXML_ROUTELIST60_API RouteList : public plmxml60::DocumentBase
{
public:
     
    //! Default constructor
    RouteList( );
     
    //! Constructs a RouteList with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RouteList( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RouteList();

private:

	//! Assignment operator
	RouteList& operator=( const RouteList& iSrc );

	//! Copy constructor
	RouteList( const RouteList& original );
     
public:

	//! Add Unit child element to this RouteList. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::Unit *AddUnit();
     
	//! Set Unit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetUnit( plmxml60::Unit *arg );
     
	//! Get Unit child element of this RouteList.
	plmxml60::Unit *GetUnit() const;
     
	//! Detach and delete Unit child element tree from this RouteList.
	void DeleteUnit();

	//! Add RouteListElement child element to this RouteList. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RouteListElement *AddRouteListElement();
     
	//! Add 'arg' as RouteListElement child element to this RouteList.
	plmxml_api::Result AddRouteListElement( RouteListElement *arg );

	//! Detach and delete all RouteListElement child elements.
	void DeleteRouteListElements();
     
	//! Get number of RouteListElement child elements.
	int NumberOfRouteListElements() const;
     
	//! Get i'th RouteListElement child element.
	RouteListElement *GetRouteListElement( int i ) const;
     
	//! Get all RouteListElement child element as an array
	void GetRouteListElements( plmxml_api::Array<RouteListElement*> &array ) const;
	     
	//! Detach and delete i'th RouteListElement child element
	void DeleteRouteListElement( int i );
     
	//! Detach and delete 'arg' if it's one of the RouteListElement child elements
	void DeleteRouteListElement( RouteListElement *arg );
 
// <PLMXML_UserCode type="functionHeaderRouteList" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_ROUTELIST60_API plmxml_api::plmxmlClass plmxmlClassRouteList;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
