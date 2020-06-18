/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
//////////////////////////////////////////////////////////////////////
#ifndef __PLMXML_DEPRECATED_H__
#define __PLMXML_DEPRECATED_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64) || defined(PLMXML_DECLSPEC)

	#ifdef PLMXML_DEPRECATED_EXPORTS
	#define PLMXML_DEPRECATED_API __declspec(dllexport)
	#else
	#define PLMXML_DEPRECATED_API __declspec(dllimport)
	#endif

#else
	#define PLMXML_DEPRECATED_API
#endif

//////////////////////////////////////////////////////////////////////

// <PLMXML_UserCode type="includeHeader" >
#include <plmxml60.h>
PLMXML_USE_NAMESPACE( plmxml60 )
// </PLMXML_UserCode>

//////////////////////////////////////////////////////////////////////
// Enumeration definitions

PLMXML_BEGIN_NAMESPACE( plmxml_deprecated )

// <PLMXML_UserCode type="classHeader" >
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! eRepQueryType class
/*!
Allowed Values:
\verbatim
  eRepQueryTypeAll
	"All"
  eRepQueryTypeJXT
	"jXT"
  eRepQueryTypeJT
	"JT"
  eRepQueryTypeXT
	"XT"
  
\endverbatim
*/
class PLMXML_DEPRECATED_API eRepQueryType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRepQueryType( const char* Type );
     
	//! Constructor
	eRepQueryType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRepQueryType( );
     
	//! Destructor 
	virtual ~eRepQueryType( );
     
	//! Assign from 'Type'
	const eRepQueryType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRepQueryType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RepQueryType
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator==( const eRepQueryType& e1, const eRepQueryType& e2 );
     
	//! Compare RepQueryType
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator!=( const eRepQueryType& e1, const eRepQueryType& e2 );
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRepQueryType;

extern PLMXML_DEPRECATED_API eRepQueryType eRepQueryTypeUnset;

extern PLMXML_DEPRECATED_API eRepQueryType eRepQueryTypeAll;

extern PLMXML_DEPRECATED_API eRepQueryType eRepQueryTypeJXT;

extern PLMXML_DEPRECATED_API eRepQueryType eRepQueryTypeJT;

extern PLMXML_DEPRECATED_API eRepQueryType eRepQueryTypeXT;

////////////////////////////////////////////////////////////////////////////////////
//! eTristripControl class
/*!
Allowed Values:
\verbatim
  eTristripControlTristrips
	"tristrips"
  eTristripControlFacetsAndTristrips
	"facetsAndTristrips"
  eTristripControlFacets
	"facets"
  
\endverbatim
*/
class PLMXML_DEPRECATED_API eTristripControl : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTristripControl( const char* Type );
     
	//! Constructor
	eTristripControl( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTristripControl( );
     
	//! Destructor 
	virtual ~eTristripControl( );
     
	//! Assign from 'Type'
	const eTristripControl& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTristripControl& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TristripControl
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator==( const eTristripControl& e1, const eTristripControl& e2 );
     
	//! Compare TristripControl
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator!=( const eTristripControl& e1, const eTristripControl& e2 );
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTristripControl;

extern PLMXML_DEPRECATED_API eTristripControl eTristripControlUnset;

extern PLMXML_DEPRECATED_API eTristripControl eTristripControlTristrips;

extern PLMXML_DEPRECATED_API eTristripControl eTristripControlFacetsAndTristrips;

extern PLMXML_DEPRECATED_API eTristripControl eTristripControlFacets;

////////////////////////////////////////////////////////////////////////////////////
//! eFacetsetControl class
/*!
Allowed Values:
\verbatim
  eFacetsetControlUnspecified
	"unspecified"
  eFacetsetControlPerFace
	"perFace"
  eFacetsetControlPerMaterial
	"perMaterial"
  
\endverbatim
*/
class PLMXML_DEPRECATED_API eFacetsetControl : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eFacetsetControl( const char* Type );
     
	//! Constructor
	eFacetsetControl( const plmxml_api::String& Type );
     
	//! Default Constructor
	eFacetsetControl( );
     
	//! Destructor 
	virtual ~eFacetsetControl( );
     
	//! Assign from 'Type'
	const eFacetsetControl& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eFacetsetControl& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare FacetsetControl
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator==( const eFacetsetControl& e1, const eFacetsetControl& e2 );
     
	//! Compare FacetsetControl
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator!=( const eFacetsetControl& e1, const eFacetsetControl& e2 );
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlFieldType plmxmlFieldEnumFacetsetControl;

extern PLMXML_DEPRECATED_API eFacetsetControl eFacetsetControlUnset;

extern PLMXML_DEPRECATED_API eFacetsetControl eFacetsetControlUnspecified;

extern PLMXML_DEPRECATED_API eFacetsetControl eFacetsetControlPerFace;

extern PLMXML_DEPRECATED_API eFacetsetControl eFacetsetControlPerMaterial;

////////////////////////////////////////////////////////////////////////////////////
//! eRequestResultType class
/*!
Allowed Values:
\verbatim
  eRequestResultTypeSuccess
	"Success"
  eRequestResultTypeInvalidRequest
	"InvalidRequest"
  eRequestResultTypeContextNotIdentified
	"ContextNotIdentified"
  
\endverbatim
*/
class PLMXML_DEPRECATED_API eRequestResultType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRequestResultType( const char* Type );
     
	//! Constructor
	eRequestResultType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRequestResultType( );
     
	//! Destructor 
	virtual ~eRequestResultType( );
     
	//! Assign from 'Type'
	const eRequestResultType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRequestResultType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RequestResultType
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator==( const eRequestResultType& e1, const eRequestResultType& e2 );
     
	//! Compare RequestResultType
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator!=( const eRequestResultType& e1, const eRequestResultType& e2 );
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRequestResultType;

extern PLMXML_DEPRECATED_API eRequestResultType eRequestResultTypeUnset;

extern PLMXML_DEPRECATED_API eRequestResultType eRequestResultTypeSuccess;

extern PLMXML_DEPRECATED_API eRequestResultType eRequestResultTypeInvalidRequest;

extern PLMXML_DEPRECATED_API eRequestResultType eRequestResultTypeContextNotIdentified;

////////////////////////////////////////////////////////////////////////////////////
//! eRequestSeverityType class
/*!
Allowed Values:
\verbatim
  eRequestSeverityTypeSevere
	"severe"
  eRequestSeverityTypeAborted
	"aborted"
  eRequestSeverityTypeNone
	"none"
  eRequestSeverityTypeMild
	"mild"
  
\endverbatim
*/
class PLMXML_DEPRECATED_API eRequestSeverityType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eRequestSeverityType( const char* Type );
     
	//! Constructor
	eRequestSeverityType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eRequestSeverityType( );
     
	//! Destructor 
	virtual ~eRequestSeverityType( );
     
	//! Assign from 'Type'
	const eRequestSeverityType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eRequestSeverityType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare RequestSeverityType
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator==( const eRequestSeverityType& e1, const eRequestSeverityType& e2 );
     
	//! Compare RequestSeverityType
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator!=( const eRequestSeverityType& e1, const eRequestSeverityType& e2 );
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlFieldType plmxmlFieldEnumRequestSeverityType;

extern PLMXML_DEPRECATED_API eRequestSeverityType eRequestSeverityTypeUnset;

extern PLMXML_DEPRECATED_API eRequestSeverityType eRequestSeverityTypeSevere;

extern PLMXML_DEPRECATED_API eRequestSeverityType eRequestSeverityTypeAborted;

extern PLMXML_DEPRECATED_API eRequestSeverityType eRequestSeverityTypeNone;

extern PLMXML_DEPRECATED_API eRequestSeverityType eRequestSeverityTypeMild;

////////////////////////////////////////////////////////////////////////////////////
//! eType class
/*!
Allowed Values:
\verbatim
  eTypeGeneral
	"general"
  eTypeMinimal
	"minimal"
  eTypeSheet
	"sheet"
  eTypeSolid
	"solid"
  eTypeWire
	"wire"
  
\endverbatim
*/
class PLMXML_DEPRECATED_API eType : public plmxml_api::EnumBase
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
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator==( const eType& e1, const eType& e2 );
     
	//! Compare Type
	friend plmxml_api::logical PLMXML_DEPRECATED_API operator!=( const eType& e1, const eType& e2 );
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlFieldType plmxmlFieldEnumType;

extern PLMXML_DEPRECATED_API eType eTypeUnset;

extern PLMXML_DEPRECATED_API eType eTypeGeneral;

extern PLMXML_DEPRECATED_API eType eTypeMinimal;

extern PLMXML_DEPRECATED_API eType eTypeSheet;

extern PLMXML_DEPRECATED_API eType eTypeSolid;

extern PLMXML_DEPRECATED_API eType eTypeWire;

//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//! Vertex class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Vertex : public EntityObject
{
public:
     
    //! Default constructor
    Vertex( );
     
    //! Constructs a Vertex with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Vertex( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Vertex();

private:

	//! Assignment operator
	Vertex& operator=( const Vertex& iSrc );

	//! Copy constructor
	Vertex( const Vertex& original );
     
public:

	//! Set reference to Fin using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetFinRef( plmxml60::IdObject *arg );

	//! Clear reference to Fin
	void RemoveFinRef( );

	//! Find a plmxml60::IdObject referenced by Fin
	plmxml60::IdObject *ResolveFinRef( plmxml_api::Configuration* config = NULL );

	//! Get Fin reference
	plmxml_api::String GetFinId() const;

	//! Set Fin reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetFinId( const plmxml_api::String& u );
	
	//! Check if Fin is set
	plmxml_api::logical HasFinRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderVertex" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassVertex;


////////////////////////////////////////////////////////////////////////////////////
//! Edge class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Edge : public EntityObject
{
public:
     
    //! Default constructor
    Edge( );
     
    //! Constructs a Edge with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Edge( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Edge();

private:

	//! Assignment operator
	Edge& operator=( const Edge& iSrc );

	//! Copy constructor
	Edge( const Edge& original );
     
public:

	//! Set reference to Fin using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetFinRef( plmxml60::IdObject *arg );

	//! Clear reference to Fin
	void RemoveFinRef( );

	//! Find a plmxml60::IdObject referenced by Fin
	plmxml60::IdObject *ResolveFinRef( plmxml_api::Configuration* config = NULL );

	//! Get Fin reference
	plmxml_api::String GetFinId() const;

	//! Set Fin reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetFinId( const plmxml_api::String& u );
	
	//! Check if Fin is set
	plmxml_api::logical HasFinRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderEdge" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassEdge;


////////////////////////////////////////////////////////////////////////////////////
//! Fin class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Fin : public EntityObject
{
public:
     
    //! Default constructor
    Fin( );
     
    //! Constructs a Fin with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Fin( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Fin();

private:

	//! Assignment operator
	Fin& operator=( const Fin& iSrc );

	//! Copy constructor
	Fin( const Fin& original );
     
public:

	//! Set reference to Vertex using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetVertexRef( plmxml60::IdObject *arg );

	//! Clear reference to Vertex
	void RemoveVertexRef( );

	//! Find a plmxml60::IdObject referenced by Vertex
	plmxml60::IdObject *ResolveVertexRef( plmxml_api::Configuration* config = NULL );

	//! Get Vertex reference
	plmxml_api::String GetVertexId() const;

	//! Set Vertex reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetVertexId( const plmxml_api::String& u );
	
	//! Check if Vertex is set
	plmxml_api::logical HasVertexRef( ) const;

	//! Set reference to NextOfVertex using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetNextOfVertexRef( plmxml60::IdObject *arg );

	//! Clear reference to NextOfVertex
	void RemoveNextOfVertexRef( );

	//! Find a plmxml60::IdObject referenced by NextOfVertex
	plmxml60::IdObject *ResolveNextOfVertexRef( plmxml_api::Configuration* config = NULL );

	//! Get NextOfVertex reference
	plmxml_api::String GetNextOfVertexId() const;

	//! Set NextOfVertex reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetNextOfVertexId( const plmxml_api::String& u );
	
	//! Check if NextOfVertex is set
	plmxml_api::logical HasNextOfVertexRef( ) const;

	//! Set reference to Edge using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetEdgeRef( plmxml60::IdObject *arg );

	//! Clear reference to Edge
	void RemoveEdgeRef( );

	//! Find a plmxml60::IdObject referenced by Edge
	plmxml60::IdObject *ResolveEdgeRef( plmxml_api::Configuration* config = NULL );

	//! Get Edge reference
	plmxml_api::String GetEdgeId() const;

	//! Set Edge reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetEdgeId( const plmxml_api::String& u );
	
	//! Check if Edge is set
	plmxml_api::logical HasEdgeRef( ) const;

	//! Set reference to Forward using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetForwardRef( plmxml60::IdObject *arg );

	//! Clear reference to Forward
	void RemoveForwardRef( );

	//! Find a plmxml60::IdObject referenced by Forward
	plmxml60::IdObject *ResolveForwardRef( plmxml_api::Configuration* config = NULL );

	//! Get Forward reference
	plmxml_api::String GetForwardId() const;

	//! Set Forward reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetForwardId( const plmxml_api::String& u );
	
	//! Check if Forward is set
	plmxml_api::logical HasForwardRef( ) const;

	//! Set reference to NextOfEdge using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetNextOfEdgeRef( plmxml60::IdObject *arg );

	//! Clear reference to NextOfEdge
	void RemoveNextOfEdgeRef( );

	//! Find a plmxml60::IdObject referenced by NextOfEdge
	plmxml60::IdObject *ResolveNextOfEdgeRef( plmxml_api::Configuration* config = NULL );

	//! Get NextOfEdge reference
	plmxml_api::String GetNextOfEdgeId() const;

	//! Set NextOfEdge reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetNextOfEdgeId( const plmxml_api::String& u );
	
	//! Check if NextOfEdge is set
	plmxml_api::logical HasNextOfEdgeRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderFin" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFin;


////////////////////////////////////////////////////////////////////////////////////
//! Loop class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Loop : public EntityObject
{
public:
     
    //! Default constructor
    Loop( );
     
    //! Constructs a Loop with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Loop( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Loop();

private:

	//! Assignment operator
	Loop& operator=( const Loop& iSrc );

	//! Copy constructor
	Loop( const Loop& original );
     
public:
public:
	//! Add Fin child element to this Loop. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Fin *AddFin();
     
	//! Add 'arg' as Fin child element to this Loop.
	plmxml_api::Result AddFin( Fin *arg );

	//! Detach and delete all Fin child elements.
	void DeleteFins();
     
	//! Get number of Fin child elements.
	int NumberOfFins() const;
     
	//! Get i'th Fin child element.
	Fin *GetFin( int i ) const;
     
	//! Get all Fin child element as an array
	void GetFins( plmxml_api::Array<Fin*> &array ) const;
	     
	//! Detach and delete i'th Fin child element
	void DeleteFin( int i );
     
	//! Detach and delete 'arg' if it's one of the Fin child elements
	void DeleteFin( Fin *arg );
public:
	//! Add Vertex child element to this Loop. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Vertex *AddVertex();
     
	//! Set Vertex child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetVertex( Vertex *arg );
     
	//! Get Vertex child element of this Loop.
	Vertex *GetVertex() const;
     
	//! Detach and delete Vertex child element tree from this Loop.
	void DeleteVertex();
public:

     // <PLMXML_UserCode type="functionHeaderLoop" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassLoop;


////////////////////////////////////////////////////////////////////////////////////
//! Face class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Face : public EntityObject
{
public:
     
    //! Default constructor
    Face( );
     
    //! Constructs a Face with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Face( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Face();

private:

	//! Assignment operator
	Face& operator=( const Face& iSrc );

	//! Copy constructor
	Face( const Face& original );
     
public:
public:
	//! Add Loop child element to this Face. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Loop *AddLoop();
     
	//! Add 'arg' as Loop child element to this Face.
	plmxml_api::Result AddLoop( Loop *arg );

	//! Detach and delete all Loop child elements.
	void DeleteLoops();
     
	//! Get number of Loop child elements.
	int NumberOfLoops() const;
     
	//! Get i'th Loop child element.
	Loop *GetLoop( int i ) const;
     
	//! Get all Loop child element as an array
	void GetLoops( plmxml_api::Array<Loop*> &array ) const;
	     
	//! Detach and delete i'th Loop child element
	void DeleteLoop( int i );
     
	//! Detach and delete 'arg' if it's one of the Loop child elements
	void DeleteLoop( Loop *arg );
public:

     // <PLMXML_UserCode type="functionHeaderFace" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFace;


////////////////////////////////////////////////////////////////////////////////////
//! Shell class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Shell : public EntityObject
{
public:
     
    //! Default constructor
    Shell( );
     
    //! Constructs a Shell with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Shell( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Shell();

private:

	//! Assignment operator
	Shell& operator=( const Shell& iSrc );

	//! Copy constructor
	Shell( const Shell& original );
     
public:

	//! Get number of references in FrontFace array
	int NumberOfFrontFaceRefs() const;
     
	//! Add reference to 'arg' to FrontFace array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddFrontFaceRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to FrontFace array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddFrontFaceId( const plmxml_api::String &u );
     
	//! Set i'th reference in FrontFace array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetFrontFaceRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in FrontFace array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetFrontFaceId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in FrontFace array and return an object it points to.
	plmxml60::IdObject *ResolveFrontFaceRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in FrontFace array and return objects they point to.
	void ResolveFrontFaceRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in FrontFace array as plmxml_api::String
	plmxml_api::String GetFrontFaceId( int i ) const;
     
	//! Get all references in FrontFace array as an array of plmxml_api::String
	void GetFrontFaceIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the FrontFace array.
	void RemoveFrontFaceRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the FrontFace array.
	void RemoveFrontFaceRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the FrontFace array.
	void RemoveFrontFaceRef( plmxml60::IdObject *arg );
     
	//! Remove all references FrontFace array.
	void RemoveFrontFaceRefs();
	
	//! Check if FrontFace is set
	plmxml_api::logical HasFrontFaceRefs( ) const;

	//! Set reference to AcornVertex using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetAcornVertexRef( plmxml60::IdObject *arg );

	//! Clear reference to AcornVertex
	void RemoveAcornVertexRef( );

	//! Find a plmxml60::IdObject referenced by AcornVertex
	plmxml60::IdObject *ResolveAcornVertexRef( plmxml_api::Configuration* config = NULL );

	//! Get AcornVertex reference
	plmxml_api::String GetAcornVertexId() const;

	//! Set AcornVertex reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetAcornVertexId( const plmxml_api::String& u );
	
	//! Check if AcornVertex is set
	plmxml_api::logical HasAcornVertexRef( ) const;

	//! Get number of references in BackFace array
	int NumberOfBackFaceRefs() const;
     
	//! Add reference to 'arg' to BackFace array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddBackFaceRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to BackFace array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddBackFaceId( const plmxml_api::String &u );
     
	//! Set i'th reference in BackFace array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetBackFaceRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in BackFace array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetBackFaceId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in BackFace array and return an object it points to.
	plmxml60::IdObject *ResolveBackFaceRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in BackFace array and return objects they point to.
	void ResolveBackFaceRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in BackFace array as plmxml_api::String
	plmxml_api::String GetBackFaceId( int i ) const;
     
	//! Get all references in BackFace array as an array of plmxml_api::String
	void GetBackFaceIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the BackFace array.
	void RemoveBackFaceRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the BackFace array.
	void RemoveBackFaceRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the BackFace array.
	void RemoveBackFaceRef( plmxml60::IdObject *arg );
     
	//! Remove all references BackFace array.
	void RemoveBackFaceRefs();
	
	//! Check if BackFace is set
	plmxml_api::logical HasBackFaceRefs( ) const;

	//! Get number of references in WireEdge array
	int NumberOfWireEdgeRefs() const;
     
	//! Add reference to 'arg' to WireEdge array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddWireEdgeRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to WireEdge array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddWireEdgeId( const plmxml_api::String &u );
     
	//! Set i'th reference in WireEdge array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetWireEdgeRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in WireEdge array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetWireEdgeId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in WireEdge array and return an object it points to.
	plmxml60::IdObject *ResolveWireEdgeRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in WireEdge array and return objects they point to.
	void ResolveWireEdgeRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in WireEdge array as plmxml_api::String
	plmxml_api::String GetWireEdgeId( int i ) const;
     
	//! Get all references in WireEdge array as an array of plmxml_api::String
	void GetWireEdgeIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the WireEdge array.
	void RemoveWireEdgeRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the WireEdge array.
	void RemoveWireEdgeRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the WireEdge array.
	void RemoveWireEdgeRef( plmxml60::IdObject *arg );
     
	//! Remove all references WireEdge array.
	void RemoveWireEdgeRefs();
	
	//! Check if WireEdge is set
	plmxml_api::logical HasWireEdgeRefs( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderShell" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassShell;


////////////////////////////////////////////////////////////////////////////////////
//! Region class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Region : public EntityObject
{
public:
     
    //! Default constructor
    Region( );
     
    //! Constructs a Region with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Region( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Region();

private:

	//! Assignment operator
	Region& operator=( const Region& iSrc );

	//! Copy constructor
	Region( const Region& original );
     
public:

	//! Set RegionIsSolid
	plmxml_api::Result SetRegionIsSolid( plmxml_api::logical arg );

	//! Get RegionIsSolid
	plmxml_api::logical GetRegionIsSolid() const;

	//! Check if RegionIsSolid is set
	plmxml_api::logical HasRegionIsSolid() const;

	//! Unset RegionIsSolid
	plmxml_api::Result UnsetRegionIsSolid();
public:
	//! Add Shell child element to this Region. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Shell *AddShell();
     
	//! Add 'arg' as Shell child element to this Region.
	plmxml_api::Result AddShell( Shell *arg );

	//! Detach and delete all Shell child elements.
	void DeleteShells();
     
	//! Get number of Shell child elements.
	int NumberOfShells() const;
     
	//! Get i'th Shell child element.
	Shell *GetShell( int i ) const;
     
	//! Get all Shell child element as an array
	void GetShells( plmxml_api::Array<Shell*> &array ) const;
	     
	//! Detach and delete i'th Shell child element
	void DeleteShell( int i );
     
	//! Detach and delete 'arg' if it's one of the Shell child elements
	void DeleteShell( Shell *arg );
public:

     // <PLMXML_UserCode type="functionHeaderRegion" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassRegion;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! ShapeTopology class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API ShapeTopology : public InternalRep
{
public:
     
    //! Default constructor
    ShapeTopology( );
     
    //! Constructs a ShapeTopology with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ShapeTopology( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ShapeTopology();

private:

	//! Assignment operator
	ShapeTopology& operator=( const ShapeTopology& iSrc );

	//! Copy constructor
	ShapeTopology( const ShapeTopology& original );
     
public:

	//! Get Entity URI as plmxml_api::String
	plmxml_api::String GetEntityURI() const;

	//! Set Entity URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetEntityURI( const plmxml_api::String& );
	
	//! Get the handle of Entity URI. Does not resolve the URI.
	plmxml_api::Result GetEntityURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Entity URI. URI string is unchanged.
	plmxml_api::Result SetEntityURI( const plmxml_api::Handle& );
	
	//! Resolve Entity URI and return an object (handle) it points to.
	plmxml_api::Result ResolveEntityURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Entity URI. Clears URI string and handle.
	plmxml_api::Result DeleteEntityURI();
	
	//! Check if Entity URI is set
	plmxml_api::logical HasEntityURI( ) const;
	
public:
	//! Add Region child element to this ShapeTopology. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Region *AddRegion();
     
	//! Add 'arg' as Region child element to this ShapeTopology.
	plmxml_api::Result AddRegion( Region *arg );

	//! Detach and delete all Region child elements.
	void DeleteRegions();
     
	//! Get number of Region child elements.
	int NumberOfRegions() const;
     
	//! Get i'th Region child element.
	Region *GetRegion( int i ) const;
     
	//! Get all Region child element as an array
	void GetRegions( plmxml_api::Array<Region*> &array ) const;
	     
	//! Detach and delete i'th Region child element
	void DeleteRegion( int i );
     
	//! Detach and delete 'arg' if it's one of the Region child elements
	void DeleteRegion( Region *arg );
public:
	//! Add Face child element to this ShapeTopology. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Face *AddFace();
     
	//! Add 'arg' as Face child element to this ShapeTopology.
	plmxml_api::Result AddFace( Face *arg );

	//! Detach and delete all Face child elements.
	void DeleteFaces();
     
	//! Get number of Face child elements.
	int NumberOfFaces() const;
     
	//! Get i'th Face child element.
	Face *GetFace( int i ) const;
     
	//! Get all Face child element as an array
	void GetFaces( plmxml_api::Array<Face*> &array ) const;
	     
	//! Detach and delete i'th Face child element
	void DeleteFace( int i );
     
	//! Detach and delete 'arg' if it's one of the Face child elements
	void DeleteFace( Face *arg );
public:
	//! Add Edge child element to this ShapeTopology. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Edge *AddEdge();
     
	//! Add 'arg' as Edge child element to this ShapeTopology.
	plmxml_api::Result AddEdge( Edge *arg );

	//! Detach and delete all Edge child elements.
	void DeleteEdges();
     
	//! Get number of Edge child elements.
	int NumberOfEdges() const;
     
	//! Get i'th Edge child element.
	Edge *GetEdge( int i ) const;
     
	//! Get all Edge child element as an array
	void GetEdges( plmxml_api::Array<Edge*> &array ) const;
	     
	//! Detach and delete i'th Edge child element
	void DeleteEdge( int i );
     
	//! Detach and delete 'arg' if it's one of the Edge child elements
	void DeleteEdge( Edge *arg );
public:
	//! Add Vertex child element to this ShapeTopology. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Vertex *AddVertex();
     
	//! Add 'arg' as Vertex child element to this ShapeTopology.
	plmxml_api::Result AddVertex( Vertex *arg );

	//! Detach and delete all Vertex child elements.
	void DeleteVertices();
     
	//! Get number of Vertex child elements.
	int NumberOfVertices() const;
     
	//! Get i'th Vertex child element.
	Vertex *GetVertex( int i ) const;
     
	//! Get all Vertex child element as an array
	void GetVertices( plmxml_api::Array<Vertex*> &array ) const;
	     
	//! Detach and delete i'th Vertex child element
	void DeleteVertex( int i );
     
	//! Detach and delete 'arg' if it's one of the Vertex child elements
	void DeleteVertex( Vertex *arg );
public:

     // <PLMXML_UserCode type="functionHeaderShapeTopology" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassShapeTopology;


////////////////////////////////////////////////////////////////////////////////////
//! BRepVertex class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API BRepVertex : public Vertex
{
public:
     
    //! Default constructor
    BRepVertex( );
     
    //! Constructs a BRepVertex with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BRepVertex( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BRepVertex();

private:

	//! Assignment operator
	BRepVertex& operator=( const BRepVertex& iSrc );

	//! Copy constructor
	BRepVertex( const BRepVertex& original );
     
public:

	//! Set Tolerance
	plmxml_api::Result SetTolerance( double arg );

     //! Get Tolerance
	double GetTolerance() const;

	//! Check if Tolerance is set
	plmxml_api::logical HasTolerance() const;

	//! Unset Tolerance
	plmxml_api::Result UnsetTolerance();

	//! Set reference to Point using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetPointRef( plmxml60::IdObject *arg );

	//! Clear reference to Point
	void RemovePointRef( );

	//! Find a plmxml60::IdObject referenced by Point
	plmxml60::IdObject *ResolvePointRef( plmxml_api::Configuration* config = NULL );

	//! Get Point reference
	plmxml_api::String GetPointId() const;

	//! Set Point reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetPointId( const plmxml_api::String& u );
	
	//! Check if Point is set
	plmxml_api::logical HasPointRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderBRepVertex" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassBRepVertex;


////////////////////////////////////////////////////////////////////////////////////
//! BRepEdge class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API BRepEdge : public Edge
{
public:
     
    //! Default constructor
    BRepEdge( );
     
    //! Constructs a BRepEdge with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BRepEdge( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BRepEdge();

private:

	//! Assignment operator
	BRepEdge& operator=( const BRepEdge& iSrc );

	//! Copy constructor
	BRepEdge( const BRepEdge& original );
     
public:

	//! Set Tolerance
	plmxml_api::Result SetTolerance( double arg );

     //! Get Tolerance
	double GetTolerance() const;

	//! Check if Tolerance is set
	plmxml_api::logical HasTolerance() const;

	//! Unset Tolerance
	plmxml_api::Result UnsetTolerance();

	//! Set reference to Curve using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetCurveRef( plmxml60::IdObject *arg );

	//! Clear reference to Curve
	void RemoveCurveRef( );

	//! Find a plmxml60::IdObject referenced by Curve
	plmxml60::IdObject *ResolveCurveRef( plmxml_api::Configuration* config = NULL );

	//! Get Curve reference
	plmxml_api::String GetCurveId() const;

	//! Set Curve reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetCurveId( const plmxml_api::String& u );
	
	//! Check if Curve is set
	plmxml_api::logical HasCurveRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderBRepEdge" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassBRepEdge;


////////////////////////////////////////////////////////////////////////////////////
//! BRepFin class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API BRepFin : public Fin
{
public:
     
    //! Default constructor
    BRepFin( );
     
    //! Constructs a BRepFin with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BRepFin( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BRepFin();

private:

	//! Assignment operator
	BRepFin& operator=( const BRepFin& iSrc );

	//! Copy constructor
	BRepFin( const BRepFin& original );
     
public:

	//! Set reference to Curve using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetCurveRef( plmxml60::IdObject *arg );

	//! Clear reference to Curve
	void RemoveCurveRef( );

	//! Find a plmxml60::IdObject referenced by Curve
	plmxml60::IdObject *ResolveCurveRef( plmxml_api::Configuration* config = NULL );

	//! Get Curve reference
	plmxml_api::String GetCurveId() const;

	//! Set Curve reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetCurveId( const plmxml_api::String& u );
	
	//! Check if Curve is set
	plmxml_api::logical HasCurveRef( ) const;

	//! Set IsPositive
	plmxml_api::Result SetIsPositive( plmxml_api::logical arg );

	//! Get IsPositive
	plmxml_api::logical GetIsPositive() const;

	//! Check if IsPositive is set
	plmxml_api::logical HasIsPositive() const;

	//! Unset IsPositive
	plmxml_api::Result UnsetIsPositive();
public:

     // <PLMXML_UserCode type="functionHeaderBRepFin" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassBRepFin;


////////////////////////////////////////////////////////////////////////////////////
//! BRepFace class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API BRepFace : public Face
{
public:
     
    //! Default constructor
    BRepFace( );
     
    //! Constructs a BRepFace with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BRepFace( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BRepFace();

private:

	//! Assignment operator
	BRepFace& operator=( const BRepFace& iSrc );

	//! Copy constructor
	BRepFace( const BRepFace& original );
     
public:

	//! Set IsPositive
	plmxml_api::Result SetIsPositive( plmxml_api::logical arg );

	//! Get IsPositive
	plmxml_api::logical GetIsPositive() const;

	//! Check if IsPositive is set
	plmxml_api::logical HasIsPositive() const;

	//! Unset IsPositive
	plmxml_api::Result UnsetIsPositive();

	//! Set reference to Surface using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetSurfaceRef( plmxml60::IdObject *arg );

	//! Clear reference to Surface
	void RemoveSurfaceRef( );

	//! Find a plmxml60::IdObject referenced by Surface
	plmxml60::IdObject *ResolveSurfaceRef( plmxml_api::Configuration* config = NULL );

	//! Get Surface reference
	plmxml_api::String GetSurfaceId() const;

	//! Set Surface reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetSurfaceId( const plmxml_api::String& u );
	
	//! Check if Surface is set
	plmxml_api::logical HasSurfaceRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderBRepFace" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassBRepFace;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! BRepBody class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API BRepBody : public ShapeTopology
{
public:
     
    //! Default constructor
    BRepBody( );
     
    //! Constructs a BRepBody with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BRepBody( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BRepBody();

private:

	//! Assignment operator
	BRepBody& operator=( const BRepBody& iSrc );

	//! Copy constructor
	BRepBody( const BRepBody& original );
     
public:

	//! Set ResSize
	plmxml_api::Result SetResSize( double arg );

     //! Get ResSize
	double GetResSize() const;

	//! Check if ResSize is set
	plmxml_api::logical HasResSize() const;

	//! Unset ResSize
	plmxml_api::Result UnsetResSize();

	//! Set Type
	plmxml_api::Result SetType( const eType& arg );

	//! Get Type
	eType GetType() const;

	//! Set ResLinear
	plmxml_api::Result SetResLinear( double arg );

     //! Get ResLinear
	double GetResLinear() const;

	//! Check if ResLinear is set
	plmxml_api::logical HasResLinear() const;

	//! Unset ResLinear
	plmxml_api::Result UnsetResLinear();
public:
	//! Add Surface child element to this BRepBody. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Surface *AddSurface();
     
	//! Add 'arg' as Surface child element to this BRepBody.
	plmxml_api::Result AddSurface( Surface *arg );

	//! Detach and delete all Surface child elements.
	void DeleteSurfaces();
     
	//! Get number of Surface child elements.
	int NumberOfSurfaces() const;
     
	//! Get i'th Surface child element.
	Surface *GetSurface( int i ) const;
     
	//! Get all Surface child element as an array
	void GetSurfaces( plmxml_api::Array<Surface*> &array ) const;
	     
	//! Detach and delete i'th Surface child element
	void DeleteSurface( int i );
     
	//! Detach and delete 'arg' if it's one of the Surface child elements
	void DeleteSurface( Surface *arg );
public:
	//! Add Curve child element to this BRepBody. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Curve *AddCurve();
     
	//! Add 'arg' as Curve child element to this BRepBody.
	plmxml_api::Result AddCurve( Curve *arg );

	//! Detach and delete all Curve child elements.
	void DeleteCurves();
     
	//! Get number of Curve child elements.
	int NumberOfCurves() const;
     
	//! Get i'th Curve child element.
	Curve *GetCurve( int i ) const;
     
	//! Get all Curve child element as an array
	void GetCurves( plmxml_api::Array<Curve*> &array ) const;
	     
	//! Detach and delete i'th Curve child element
	void DeleteCurve( int i );
     
	//! Detach and delete 'arg' if it's one of the Curve child elements
	void DeleteCurve( Curve *arg );
public:
	//! Add Point child element to this BRepBody. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Point *AddPoint();
     
	//! Add 'arg' as Point child element to this BRepBody.
	plmxml_api::Result AddPoint( Point *arg );

	//! Detach and delete all Point child elements.
	void DeletePoints();
     
	//! Get number of Point child elements.
	int NumberOfPoints() const;
     
	//! Get i'th Point child element.
	Point *GetPoint( int i ) const;
     
	//! Get all Point child element as an array
	void GetPoints( plmxml_api::Array<Point*> &array ) const;
	     
	//! Detach and delete i'th Point child element
	void DeletePoint( int i );
     
	//! Detach and delete 'arg' if it's one of the Point child elements
	void DeletePoint( Point *arg );
public:

     // <PLMXML_UserCode type="functionHeaderBRepBody" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassBRepBody;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! FacetVertex class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API FacetVertex : public IdObject
{
public:
     
    //! Default constructor
    FacetVertex( );
     
    //! Constructs a FacetVertex with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetVertex( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetVertex();

private:

	//! Assignment operator
	FacetVertex& operator=( const FacetVertex& iSrc );

	//! Copy constructor
	FacetVertex( const FacetVertex& original );
     
public:

	//! Set reference to Point using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetPointRef( plmxml60::IdObject *arg );

	//! Clear reference to Point
	void RemovePointRef( );

	//! Find a plmxml60::IdObject referenced by Point
	plmxml60::IdObject *ResolvePointRef( plmxml_api::Configuration* config = NULL );

	//! Get Point reference
	plmxml_api::String GetPointId() const;

	//! Set Point reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetPointId( const plmxml_api::String& u );
	
	//! Check if Point is set
	plmxml_api::logical HasPointRef( ) const;

	//! Set reference to Normal using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetNormalRef( plmxml60::IdObject *arg );

	//! Clear reference to Normal
	void RemoveNormalRef( );

	//! Find a plmxml60::IdObject referenced by Normal
	plmxml60::IdObject *ResolveNormalRef( plmxml_api::Configuration* config = NULL );

	//! Get Normal reference
	plmxml_api::String GetNormalId() const;

	//! Set Normal reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetNormalId( const plmxml_api::String& u );
	
	//! Check if Normal is set
	plmxml_api::logical HasNormalRef( ) const;

	//! Set reference to Coord using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetCoordRef( plmxml60::IdObject *arg );

	//! Clear reference to Coord
	void RemoveCoordRef( );

	//! Find a plmxml60::IdObject referenced by Coord
	plmxml60::IdObject *ResolveCoordRef( plmxml_api::Configuration* config = NULL );

	//! Get Coord reference
	plmxml_api::String GetCoordId() const;

	//! Set Coord reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetCoordId( const plmxml_api::String& u );
	
	//! Check if Coord is set
	plmxml_api::logical HasCoordRef( ) const;
public:

     // <PLMXML_UserCode type="functionHeaderFacetVertex" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetVertex;


////////////////////////////////////////////////////////////////////////////////////
//! Facet class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Facet : public IdObject
{
public:
     
    //! Default constructor
    Facet( );
     
    //! Constructs a Facet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Facet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Facet();

private:

	//! Assignment operator
	Facet& operator=( const Facet& iSrc );

	//! Copy constructor
	Facet( const Facet& original );
     
public:
public:
	//! Add FacetVertex child element to this Facet. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FacetVertex *AddFacetVertex();
     
	//! Add 'arg' as FacetVertex child element to this Facet.
	plmxml_api::Result AddFacetVertex( FacetVertex *arg );

	//! Detach and delete all FacetVertex child elements.
	void DeleteFacetVertices();
     
	//! Get number of FacetVertex child elements.
	int NumberOfFacetVertices() const;
     
	//! Get i'th FacetVertex child element.
	FacetVertex *GetFacetVertex( int i ) const;
     
	//! Get all FacetVertex child element as an array
	void GetFacetVertices( plmxml_api::Array<FacetVertex*> &array ) const;
	     
	//! Detach and delete i'th FacetVertex child element
	void DeleteFacetVertex( int i );
     
	//! Detach and delete 'arg' if it's one of the FacetVertex child elements
	void DeleteFacetVertex( FacetVertex *arg );
public:

     // <PLMXML_UserCode type="functionHeaderFacet" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacet;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! FacetData class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API FacetData : public Entity3D
{
public:
     
    //! Default constructor
    FacetData( );
     
    //! Constructs a FacetData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetData();

private:

	//! Assignment operator
	FacetData& operator=( const FacetData& iSrc );

	//! Copy constructor
	FacetData( const FacetData& original );
     
public:

	//! Set NumberOfPoints
	plmxml_api::Result SetNumberOfPoints( int arg );
     
	//! Get NumberOfPoints
	int GetNumberOfPoints() const;
     
	//! Check if NumberOfPoints is set
	plmxml_api::logical HasNumberOfPoints() const;
     
	//! Unset NumberOfPoints
	plmxml_api::Result UnsetNumberOfPoints();

	//! Set CurveChordTol
	plmxml_api::Result SetCurveChordTol( double arg );

     //! Get CurveChordTol
	double GetCurveChordTol() const;

	//! Check if CurveChordTol is set
	plmxml_api::logical HasCurveChordTol() const;

	//! Unset CurveChordTol
	plmxml_api::Result UnsetCurveChordTol();

	//! Set DoubleSided
	plmxml_api::Result SetDoubleSided( plmxml_api::logical arg );

	//! Get DoubleSided
	plmxml_api::logical GetDoubleSided() const;

	//! Check if DoubleSided is set
	plmxml_api::logical HasDoubleSided() const;

	//! Unset DoubleSided
	plmxml_api::Result UnsetDoubleSided();

	//! Set reference to Texture using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetTextureRef( plmxml60::IdObject *arg );

	//! Clear reference to Texture
	void RemoveTextureRef( );

	//! Find a plmxml60::IdObject referenced by Texture
	plmxml60::IdObject *ResolveTextureRef( plmxml_api::Configuration* config = NULL );

	//! Get Texture reference
	plmxml_api::String GetTextureId() const;

	//! Set Texture reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetTextureId( const plmxml_api::String& u );
	
	//! Check if Texture is set
	plmxml_api::logical HasTextureRef( ) const;

	//! Set NumberOfNormals
	plmxml_api::Result SetNumberOfNormals( int arg );
     
	//! Get NumberOfNormals
	int GetNumberOfNormals() const;
     
	//! Check if NumberOfNormals is set
	plmxml_api::logical HasNumberOfNormals() const;
     
	//! Unset NumberOfNormals
	plmxml_api::Result UnsetNumberOfNormals();

	//! Set SurfacePlaneTol
	plmxml_api::Result SetSurfacePlaneTol( double arg );

     //! Get SurfacePlaneTol
	double GetSurfacePlaneTol() const;

	//! Check if SurfacePlaneTol is set
	plmxml_api::logical HasSurfacePlaneTol() const;

	//! Unset SurfacePlaneTol
	plmxml_api::Result UnsetSurfacePlaneTol();

	//! Set NumberOfFacets
	plmxml_api::Result SetNumberOfFacets( int arg );
     
	//! Get NumberOfFacets
	int GetNumberOfFacets() const;
     
	//! Check if NumberOfFacets is set
	plmxml_api::logical HasNumberOfFacets() const;
     
	//! Unset NumberOfFacets
	plmxml_api::Result UnsetNumberOfFacets();

	//! Set reference to Material using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetMaterialRef( plmxml60::IdObject *arg );

	//! Clear reference to Material
	void RemoveMaterialRef( );

	//! Find a plmxml60::IdObject referenced by Material
	plmxml60::IdObject *ResolveMaterialRef( plmxml_api::Configuration* config = NULL );

	//! Get Material reference
	plmxml_api::String GetMaterialId() const;

	//! Set Material reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetMaterialId( const plmxml_api::String& u );
	
	//! Check if Material is set
	plmxml_api::logical HasMaterialRef( ) const;
public:
	//! Add Point child element to this FacetData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Position *AddPoint();
     
	//! Add 'arg' as Point child element to this FacetData.
	plmxml_api::Result AddPoint( Position *arg );

	//! Detach and delete all Point child elements.
	void DeletePoints();
     
	//! Get number of Point child elements.
	int NumberOfPoints() const;
     
	//! Get i'th Point child element.
	Position *GetPoint( int i ) const;
     
	//! Get all Point child element as an array
	void GetPoints( plmxml_api::Array<Position*> &array ) const;
	     
	//! Detach and delete i'th Point child element
	void DeletePoint( int i );
     
	//! Detach and delete 'arg' if it's one of the Point child elements
	void DeletePoint( Position *arg );
public:
	//! Add Normal child element to this FacetData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Normal *AddNormal();
     
	//! Add 'arg' as Normal child element to this FacetData.
	plmxml_api::Result AddNormal( Normal *arg );

	//! Detach and delete all Normal child elements.
	void DeleteNormals();
     
	//! Get number of Normal child elements.
	int NumberOfNormals() const;
     
	//! Get i'th Normal child element.
	Normal *GetNormal( int i ) const;
     
	//! Get all Normal child element as an array
	void GetNormals( plmxml_api::Array<Normal*> &array ) const;
	     
	//! Detach and delete i'th Normal child element
	void DeleteNormal( int i );
     
	//! Detach and delete 'arg' if it's one of the Normal child elements
	void DeleteNormal( Normal *arg );
public:
	//! Add TextureCoord child element to this FacetData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	TextureCoord *AddTextureCoord();
     
	//! Add 'arg' as TextureCoord child element to this FacetData.
	plmxml_api::Result AddTextureCoord( TextureCoord *arg );

	//! Detach and delete all TextureCoord child elements.
	void DeleteTextureCoords();
     
	//! Get number of TextureCoord child elements.
	int NumberOfTextureCoords() const;
     
	//! Get i'th TextureCoord child element.
	TextureCoord *GetTextureCoord( int i ) const;
     
	//! Get all TextureCoord child element as an array
	void GetTextureCoords( plmxml_api::Array<TextureCoord*> &array ) const;
	     
	//! Detach and delete i'th TextureCoord child element
	void DeleteTextureCoord( int i );
     
	//! Detach and delete 'arg' if it's one of the TextureCoord child elements
	void DeleteTextureCoord( TextureCoord *arg );
public:

     // <PLMXML_UserCode type="functionHeaderFacetData" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetData;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! Patch class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Patch : public FacetData
{
public:
     
    //! Default constructor
    Patch( );
     
    //! Constructs a Patch with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Patch( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Patch();

private:

	//! Assignment operator
	Patch& operator=( const Patch& iSrc );

	//! Copy constructor
	Patch( const Patch& original );
     
public:

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
	

	//! Set Load
	plmxml_api::Result SetLoad( plmxml_api::logical arg );

	//! Get Load
	plmxml_api::logical GetLoad() const;

	//! Check if Load is set
	plmxml_api::logical HasLoad() const;

	//! Unset Load
	plmxml_api::Result UnsetLoad();
public:
	//! Add Facet child element to this Patch. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Facet *AddFacet();
     
	//! Add 'arg' as Facet child element to this Patch.
	plmxml_api::Result AddFacet( Facet *arg );

	//! Detach and delete all Facet child elements.
	void DeleteFacets();
     
	//! Get number of Facet child elements.
	int NumberOfFacets() const;
     
	//! Get i'th Facet child element.
	Facet *GetFacet( int i ) const;
     
	//! Get all Facet child element as an array
	void GetFacets( plmxml_api::Array<Facet*> &array ) const;
	     
	//! Detach and delete i'th Facet child element
	void DeleteFacet( int i );
     
	//! Detach and delete 'arg' if it's one of the Facet child elements
	void DeleteFacet( Facet *arg );
public:
	//! Add EntityRef child element to this Patch. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	EntityRef *AddEntityRef();
     
	//! Set EntityRef child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetEntityRef( EntityRef *arg );
     
	//! Get EntityRef child element of this Patch.
	EntityRef *GetEntityRef() const;
     
	//! Detach and delete EntityRef child element tree from this Patch.
	void DeleteEntityRef();
public:

     // <PLMXML_UserCode type="functionHeaderPatch" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassPatch;


////////////////////////////////////////////////////////////////////////////////////
//! Mesh class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API Mesh : public FacetData
{
public:
     
    //! Default constructor
    Mesh( );
     
    //! Constructs a Mesh with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Mesh( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Mesh();

private:

	//! Assignment operator
	Mesh& operator=( const Mesh& iSrc );

	//! Copy constructor
	Mesh( const Mesh& original );
     
public:

	//! Get Topology URI as plmxml_api::String
	plmxml_api::String GetTopologyURI() const;

	//! Set Topology URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTopologyURI( const plmxml_api::String& );
	
	//! Get the handle of Topology URI. Does not resolve the URI.
	plmxml_api::Result GetTopologyURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Topology URI. URI string is unchanged.
	plmxml_api::Result SetTopologyURI( const plmxml_api::Handle& );
	
	//! Resolve Topology URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTopologyURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Topology URI. Clears URI string and handle.
	plmxml_api::Result DeleteTopologyURI();
	
	//! Check if Topology URI is set
	plmxml_api::logical HasTopologyURI( ) const;
	
public:
	//! Add Patch child element to this Mesh. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Patch *AddPatch();
     
	//! Add 'arg' as Patch child element to this Mesh.
	plmxml_api::Result AddPatch( Patch *arg );

	//! Detach and delete all Patch child elements.
	void DeletePatches();
     
	//! Get number of Patch child elements.
	int NumberOfPatches() const;
     
	//! Get i'th Patch child element.
	Patch *GetPatch( int i ) const;
     
	//! Get all Patch child element as an array
	void GetPatches( plmxml_api::Array<Patch*> &array ) const;
	     
	//! Detach and delete i'th Patch child element
	void DeletePatch( int i );
     
	//! Detach and delete 'arg' if it's one of the Patch child elements
	void DeletePatch( Patch *arg );
public:

     // <PLMXML_UserCode type="functionHeaderMesh" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassMesh;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! FacetRep class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API FacetRep : public InternalRep
{
public:
     
    //! Default constructor
    FacetRep( );
     
    //! Constructs a FacetRep with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetRep( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetRep();

private:

	//! Assignment operator
	FacetRep& operator=( const FacetRep& iSrc );

	//! Copy constructor
	FacetRep( const FacetRep& original );
     
public:
public:
	//! Add Material child element to this FacetRep. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Material *AddMaterial();
     
	//! Add 'arg' as Material child element to this FacetRep.
	plmxml_api::Result AddMaterial( Material *arg );

	//! Detach and delete all Material child elements.
	void DeleteMaterials();
     
	//! Get number of Material child elements.
	int NumberOfMaterials() const;
     
	//! Get i'th Material child element.
	Material *GetMaterial( int i ) const;
     
	//! Get all Material child element as an array
	void GetMaterials( plmxml_api::Array<Material*> &array ) const;
	     
	//! Detach and delete i'th Material child element
	void DeleteMaterial( int i );
     
	//! Detach and delete 'arg' if it's one of the Material child elements
	void DeleteMaterial( Material *arg );
public:
	//! Add TextureData child element to this FacetRep. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	TextureData *AddTextureData();
     
	//! Add 'arg' as TextureData child element to this FacetRep.
	plmxml_api::Result AddTextureData( TextureData *arg );

	//! Detach and delete all TextureData child elements.
	void DeleteTextureDatas();
     
	//! Get number of TextureData child elements.
	int NumberOfTextureDatas() const;
     
	//! Get i'th TextureData child element.
	TextureData *GetTextureData( int i ) const;
     
	//! Get all TextureData child element as an array
	void GetTextureDatas( plmxml_api::Array<TextureData*> &array ) const;
	     
	//! Detach and delete i'th TextureData child element
	void DeleteTextureData( int i );
     
	//! Detach and delete 'arg' if it's one of the TextureData child elements
	void DeleteTextureData( TextureData *arg );
public:
	//! Add Texture child element to this FacetRep. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Texture *AddTexture();
     
	//! Add 'arg' as Texture child element to this FacetRep.
	plmxml_api::Result AddTexture( Texture *arg );

	//! Detach and delete all Texture child elements.
	void DeleteTextures();
     
	//! Get number of Texture child elements.
	int NumberOfTextures() const;
     
	//! Get i'th Texture child element.
	Texture *GetTexture( int i ) const;
     
	//! Get all Texture child element as an array
	void GetTextures( plmxml_api::Array<Texture*> &array ) const;
	     
	//! Detach and delete i'th Texture child element
	void DeleteTexture( int i );
     
	//! Detach and delete 'arg' if it's one of the Texture child elements
	void DeleteTexture( Texture *arg );
public:
	//! Add Mesh child element to this FacetRep. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Mesh *AddMesh();
     
	//! Set Mesh child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetMesh( Mesh *arg );
     
	//! Get Mesh child element of this FacetRep.
	Mesh *GetMesh() const;
     
	//! Detach and delete Mesh child element tree from this FacetRep.
	void DeleteMesh();
public:

     // <PLMXML_UserCode type="functionHeaderFacetRep" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetRep;


////////////////////////////////////////////////////////////////////////////////////
//! FacetFin class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API FacetFin : public Fin
{
public:
     
    //! Default constructor
    FacetFin( );
     
    //! Constructs a FacetFin with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetFin( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetFin();

private:

	//! Assignment operator
	FacetFin& operator=( const FacetFin& iSrc );

	//! Copy constructor
	FacetFin( const FacetFin& original );
     
public:

	//! Get FacetVertex URI as plmxml_api::String
	plmxml_api::String GetFacetVertexURI() const;

	//! Set FacetVertex URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFacetVertexURI( const plmxml_api::String& );
	
	//! Get the handle of FacetVertex URI. Does not resolve the URI.
	plmxml_api::Result GetFacetVertexURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of FacetVertex URI. URI string is unchanged.
	plmxml_api::Result SetFacetVertexURI( const plmxml_api::Handle& );
	
	//! Resolve FacetVertex URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFacetVertexURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset FacetVertex URI. Clears URI string and handle.
	plmxml_api::Result DeleteFacetVertexURI();
	
	//! Check if FacetVertex URI is set
	plmxml_api::logical HasFacetVertexURI( ) const;
	

	//! Get Facet URI as plmxml_api::String
	plmxml_api::String GetFacetURI() const;

	//! Set Facet URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFacetURI( const plmxml_api::String& );
	
	//! Get the handle of Facet URI. Does not resolve the URI.
	plmxml_api::Result GetFacetURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Facet URI. URI string is unchanged.
	plmxml_api::Result SetFacetURI( const plmxml_api::Handle& );
	
	//! Resolve Facet URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFacetURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Facet URI. Clears URI string and handle.
	plmxml_api::Result DeleteFacetURI();
	
	//! Check if Facet URI is set
	plmxml_api::logical HasFacetURI( ) const;
	

	//! Set Type
	plmxml_api::Result SetType( const eType& arg );

	//! Get Type
	eType GetType() const;
public:

     // <PLMXML_UserCode type="functionHeaderFacetFin" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetFin;


////////////////////////////////////////////////////////////////////////////////////
//! FacetFace class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API FacetFace : public Face
{
public:
     
    //! Default constructor
    FacetFace( );
     
    //! Constructs a FacetFace with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetFace( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetFace();

private:

	//! Assignment operator
	FacetFace& operator=( const FacetFace& iSrc );

	//! Copy constructor
	FacetFace( const FacetFace& original );
     
public:

	//! Get number of URIs in Patch
	int NumberOfPatchURIs() const;

	//! Get i'th URI in Patch
	plmxml_api::String GetPatchURI( int i ) const;

	//! Add a URI to Patch array. Call ResolvePatchURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPatchURI( const plmxml_api::String& u );

	//! Set i'th URI in Patch array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPatchURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Patch URI. Does not resolve the URI.
	plmxml_api::Result GetPatchURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Patch array.
	plmxml_api::Result AddPatchURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Patch array to point to 'handle'.
	plmxml_api::Result SetPatchURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Patch points to.
	plmxml_api::Result ResolvePatchURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Patch array.
	plmxml_api::Result DeletePatchURI( int i );

	//! Remove all URIs from Patch array.
	plmxml_api::Result DeletePatchURIs( );
	
	//! Check if Patch is set
	plmxml_api::logical HasPatchURIs( ) const;
public:
	//! Add FacetFin child element to this FacetFace. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FacetFin *AddFacetFin();
     
	//! Add 'arg' as FacetFin child element to this FacetFace.
	plmxml_api::Result AddFacetFin( FacetFin *arg );

	//! Detach and delete all FacetFin child elements.
	void DeleteFacetFins();
     
	//! Get number of FacetFin child elements.
	int NumberOfFacetFins() const;
     
	//! Get i'th FacetFin child element.
	FacetFin *GetFacetFin( int i ) const;
     
	//! Get all FacetFin child element as an array
	void GetFacetFins( plmxml_api::Array<FacetFin*> &array ) const;
	     
	//! Detach and delete i'th FacetFin child element
	void DeleteFacetFin( int i );
     
	//! Detach and delete 'arg' if it's one of the FacetFin child elements
	void DeleteFacetFin( FacetFin *arg );
public:
	//! Add EntityRef child element to this FacetFace. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	EntityRef *AddEntityRef();
     
	//! Set EntityRef child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetEntityRef( EntityRef *arg );
     
	//! Get EntityRef child element of this FacetFace.
	EntityRef *GetEntityRef() const;
     
	//! Detach and delete EntityRef child element tree from this FacetFace.
	void DeleteEntityRef();
public:

     // <PLMXML_UserCode type="functionHeaderFacetFace" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetFace;


////////////////////////////////////////////////////////////////////////////////////
//! FacetTopology class
/*!
\verbatim

\endverbatim
*/
class PLMXML_DEPRECATED_API FacetTopology : public ShapeTopology
{
public:
     
    //! Default constructor
    FacetTopology( );
     
    //! Constructs a FacetTopology with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetTopology( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetTopology();

private:

	//! Assignment operator
	FacetTopology& operator=( const FacetTopology& iSrc );

	//! Copy constructor
	FacetTopology( const FacetTopology& original );
     
public:
public:

     // <PLMXML_UserCode type="functionHeaderFacetTopology" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetTopology;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! Query class
/*!
\verbatim

			The abstract datatype and element for Query elements.
			
\endverbatim
*/
class PLMXML_DEPRECATED_API Query : public AttribOwner
{
public:
     
    //! Default constructor
    Query( );
     
    //! Constructs a Query with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Query( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Query();

private:

	//! Assignment operator
	Query& operator=( const Query& iSrc );

	//! Copy constructor
	Query( const Query& original );
     
public:
public:

     // <PLMXML_UserCode type="functionHeaderQuery" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassQuery;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! Request class
/*!
\verbatim

      The element describing the data context for PLMXML request.
      This effectively identifies the part or application
      context for the request.

      Attributes:
      name:          (optional) name of the data context or part.
      format:        (required) the format of the context.
      context:       (required) the location or identifier of the 
                     data context. NB the name is 'context', not
                     'contextRef'.

      SubElements:
      
      Query          (required) the query itself. Note that this
                     is an abstract element, so a substitution
                     element must be used.
      
\endverbatim
*/
class PLMXML_DEPRECATED_API Request : public plmxml_api::Object
{
public:
     
    //! Default constructor
    Request( );
     
    //! Constructs a Request with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Request( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Request();

private:

	//! Assignment operator
	Request& operator=( const Request& iSrc );

	//! Copy constructor
	Request( const Request& original );
     
public:

	//! Get Name of this Request
	plmxml_api::String GetName() const;

	//! Set Name of this Request
	plmxml_api::Result SetName( const plmxml_api::String &s );
	
	//! Check if Name is set
	plmxml_api::logical HasName( ) const;
	
	//! Unset Name
	plmxml_api::Result UnsetName( );

	//! Get Context of this Request
	plmxml_api::String GetContext() const;

	//! Set Context of this Request
	plmxml_api::Result SetContext( const plmxml_api::String &s );
	
	//! Check if Context is set
	plmxml_api::logical HasContext( ) const;
	
	//! Unset Context
	plmxml_api::Result UnsetContext( );

	//! Set Format
	plmxml_api::Result SetFormat( const eRepresentationFormatType& arg );

	//! Get Format
	eRepresentationFormatType GetFormat() const;
public:
	//! Add Query child element to this Request. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Query *AddQuery();
     
	//! Add 'arg' as Query child element to this Request.
	plmxml_api::Result AddQuery( Query *arg );

	//! Detach and delete all Query child elements.
	void DeleteQueries();
     
	//! Get number of Query child elements.
	int NumberOfQueries() const;
     
	//! Get i'th Query child element.
	Query *GetQuery( int i ) const;
     
	//! Get all Query child element as an array
	void GetQueries( plmxml_api::Array<Query*> &array ) const;
	     
	//! Detach and delete i'th Query child element
	void DeleteQuery( int i );
     
	//! Detach and delete 'arg' if it's one of the Query child elements
	void DeleteQuery( Query *arg );
public:

     // <PLMXML_UserCode type="functionHeaderRequest" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassRequest;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! RequestDocument class
/*!
\verbatim

      The main PLMXML data request element. This element must appear within it's own document.
      The element contains a number of fields for describing the context of the request 
      (e.g. the part name, etc) and the type of data to be returned. The application making the 
      request provides it's own context within the data request element via the 'requestId' 
      attribute. This attribute value must be returned in the resultant PLMXML document. 
      This enables the application to match PLMXML documents with the data request.
     
      Attributes:
    
      application:    (mandatory) Name of the application making the request.
      requestId:      (mandatory) Application supplied identifier for the 
                      request. This value will be returned in the resulting
                      PLMXML document.

      Elements:
    
      Request:        (optional) The application part context and request. 
    
\endverbatim
*/
class PLMXML_DEPRECATED_API RequestDocument : public DocumentBase
{
public:
     
    //! Default constructor
    RequestDocument( );
     
    //! Constructs a RequestDocument with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RequestDocument( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RequestDocument();

private:

	//! Assignment operator
	RequestDocument& operator=( const RequestDocument& iSrc );

	//! Copy constructor
	RequestDocument( const RequestDocument& original );
     
public:

	//! Get Application of this RequestDocument
	plmxml_api::String GetApplication() const;

	//! Set Application of this RequestDocument
	plmxml_api::Result SetApplication( const plmxml_api::String &s );
	
	//! Check if Application is set
	plmxml_api::logical HasApplication( ) const;
	
	//! Unset Application
	plmxml_api::Result UnsetApplication( );

	//! Get RequestId of this RequestDocument
	plmxml_api::String GetRequestId() const;

	//! Set RequestId of this RequestDocument
	plmxml_api::Result SetRequestId( const plmxml_api::String &s );
	
	//! Check if RequestId is set
	plmxml_api::logical HasRequestId( ) const;
	
	//! Unset RequestId
	plmxml_api::Result UnsetRequestId( );
public:
	//! Add Request child element to this RequestDocument. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Request *AddRequest();
     
	//! Set Request child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRequest( Request *arg );
     
	//! Get Request child element of this RequestDocument.
	Request *GetRequest() const;
     
	//! Detach and delete Request child element tree from this RequestDocument.
	void DeleteRequest();
public:

     // <PLMXML_UserCode type="functionHeaderRequestDocument" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassRequestDocument;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! FacetControls class
/*!
\verbatim

      This type gives the parameters which control a facet generation
      operation.
    
      Attributes:
    
      curveAngularTol:     max angular change between chords along edge
      curveDistanceTol:    max edge/chord distance
      surfaceAngularTol:   max angular change between facets
      surfaceDistanceTol:  max face/facet distance
      tristripControl :    whether tristrips allowed
      facetsetControl:     whether facetsets are created per face, per material, or
                           unspecified
    
      
\endverbatim
*/
class PLMXML_DEPRECATED_API FacetControls : public plmxml_api::Object
{
public:
     
    //! Default constructor
    FacetControls( );
     
    //! Constructs a FacetControls with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FacetControls( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FacetControls();

private:

	//! Assignment operator
	FacetControls& operator=( const FacetControls& iSrc );

	//! Copy constructor
	FacetControls( const FacetControls& original );
     
public:

	//! Set SurfaceDistanceTol
	plmxml_api::Result SetSurfaceDistanceTol( double arg );

     //! Get SurfaceDistanceTol
	double GetSurfaceDistanceTol() const;

	//! Check if SurfaceDistanceTol is set
	plmxml_api::logical HasSurfaceDistanceTol() const;

	//! Unset SurfaceDistanceTol
	plmxml_api::Result UnsetSurfaceDistanceTol();

	//! Set FacetsetControl
	plmxml_api::Result SetFacetsetControl( const eFacetsetControl& arg );

	//! Get FacetsetControl
	eFacetsetControl GetFacetsetControl() const;

	//! Set CurveDistanceTol
	plmxml_api::Result SetCurveDistanceTol( double arg );

     //! Get CurveDistanceTol
	double GetCurveDistanceTol() const;

	//! Check if CurveDistanceTol is set
	plmxml_api::logical HasCurveDistanceTol() const;

	//! Unset CurveDistanceTol
	plmxml_api::Result UnsetCurveDistanceTol();

	//! Set SurfaceAngularTol
	plmxml_api::Result SetSurfaceAngularTol( double arg );

     //! Get SurfaceAngularTol
	double GetSurfaceAngularTol() const;

	//! Check if SurfaceAngularTol is set
	plmxml_api::logical HasSurfaceAngularTol() const;

	//! Unset SurfaceAngularTol
	plmxml_api::Result UnsetSurfaceAngularTol();

	//! Set CurveAngularTol
	plmxml_api::Result SetCurveAngularTol( double arg );

     //! Get CurveAngularTol
	double GetCurveAngularTol() const;

	//! Check if CurveAngularTol is set
	plmxml_api::logical HasCurveAngularTol() const;

	//! Unset CurveAngularTol
	plmxml_api::Result UnsetCurveAngularTol();

	//! Set TristripControl
	plmxml_api::Result SetTristripControl( const eTristripControl& arg );

	//! Get TristripControl
	eTristripControl GetTristripControl() const;
public:

     // <PLMXML_UserCode type="functionHeaderFacetControls" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFacetControls;


////////////////////////////////////////////////////////////////////////////////////
//! RepresentationQuery class
/*!
\verbatim

      This datatype is used to describe a representation query. The
      element is defined as a substitution element for the abstract
      Query element.
      
      Attributes:
      
      type:       (required) The type of representation requested.
                  Currently, this is : XT, JT, jXT or All
      label:      (optional) If a suitable application label is specified
                  the request must return the representation matching the
                  specified label.
                  If no label is specified, then the request must return
                  a PLMXML document that identifies all the appropriate 
                  representations in the specified context.
    
\endverbatim
*/
class PLMXML_DEPRECATED_API RepresentationQuery : public Query
{
public:
     
    //! Default constructor
    RepresentationQuery( );
     
    //! Constructs a RepresentationQuery with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RepresentationQuery( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RepresentationQuery();

private:

	//! Assignment operator
	RepresentationQuery& operator=( const RepresentationQuery& iSrc );

	//! Copy constructor
	RepresentationQuery( const RepresentationQuery& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eRepQueryType& arg );

	//! Get Type
	eRepQueryType GetType() const;

	//! Get Label of this RepresentationQuery
	plmxml_api::String GetLabel() const;

	//! Set Label of this RepresentationQuery
	plmxml_api::Result SetLabel( const plmxml_api::String &s );
	
	//! Check if Label is set
	plmxml_api::logical HasLabel( ) const;
	
	//! Unset Label
	plmxml_api::Result UnsetLabel( );
public:
	//! Add FacetControls child element to this RepresentationQuery. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	FacetControls *AddFacetControls();
     
	//! Set FacetControls child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetFacetControls( FacetControls *arg );
     
	//! Get FacetControls child element of this RepresentationQuery.
	FacetControls *GetFacetControls() const;
     
	//! Detach and delete FacetControls child element tree from this RepresentationQuery.
	void DeleteFacetControls();
public:

     // <PLMXML_UserCode type="functionHeaderRepresentationQuery" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassRepresentationQuery;


////////////////////////////////////////////////////////////////////////////////////
//! ProductDefQuery class
/*!
\verbatim

      This datatype is used to describe a product structure query. The
      element is defined as a substitution element for the abstract
      Query element.
      
\endverbatim
*/
class PLMXML_DEPRECATED_API ProductDefQuery : public Query
{
public:
     
    //! Default constructor
    ProductDefQuery( );
     
    //! Constructs a ProductDefQuery with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProductDefQuery( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProductDefQuery();

private:

	//! Assignment operator
	ProductDefQuery& operator=( const ProductDefQuery& iSrc );

	//! Copy constructor
	ProductDefQuery( const ProductDefQuery& original );
     
public:
public:

     // <PLMXML_UserCode type="functionHeaderProductDefQuery" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassProductDefQuery;


////////////////////////////////////////////////////////////////////////////////////
//! FeatureQuery class
/*!
\verbatim

      This datatype is used to describe a Feature/FeatureTree query. The
      element is defined as a substitution element for the abstract
      Query element.
    
      Attributes:
    
      label:    (optional) If a suitable application label is specified
                the request must return the feature matching the
                specified label.
                If no label is specified, then the request must return
                an PLMXML document that specifies the whole feature tree 
                within the specified context.
      
\endverbatim
*/
class PLMXML_DEPRECATED_API FeatureQuery : public Query
{
public:
     
    //! Default constructor
    FeatureQuery( );
     
    //! Constructs a FeatureQuery with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FeatureQuery( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FeatureQuery();

private:

	//! Assignment operator
	FeatureQuery& operator=( const FeatureQuery& iSrc );

	//! Copy constructor
	FeatureQuery( const FeatureQuery& original );
     
public:

	//! Get Label of this FeatureQuery
	plmxml_api::String GetLabel() const;

	//! Set Label of this FeatureQuery
	plmxml_api::Result SetLabel( const plmxml_api::String &s );
	
	//! Check if Label is set
	plmxml_api::logical HasLabel( ) const;
	
	//! Unset Label
	plmxml_api::Result UnsetLabel( );
public:

     // <PLMXML_UserCode type="functionHeaderFeatureQuery" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassFeatureQuery;


////////////////////////////////////////////////////////////////////////////////////
//! AnnotationQuery class
/*!
\verbatim

      This datatype is used to describe an Annotation query. The
      element is defined as a substitution element for the abstract
      Query element.
    
      Attributes:
   
      label:    (optional) If a suitable application label is specified
                the request must return the annotation matching the
                specified label.
                If no label is specified, then the request must return
                an PLMXML document that specifies all the annotations 
                within the specified context.
      
\endverbatim
*/
class PLMXML_DEPRECATED_API AnnotationQuery : public Query
{
public:
     
    //! Default constructor
    AnnotationQuery( );
     
    //! Constructs a AnnotationQuery with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AnnotationQuery( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AnnotationQuery();

private:

	//! Assignment operator
	AnnotationQuery& operator=( const AnnotationQuery& iSrc );

	//! Copy constructor
	AnnotationQuery( const AnnotationQuery& original );
     
public:

	//! Get Label of this AnnotationQuery
	plmxml_api::String GetLabel() const;

	//! Set Label of this AnnotationQuery
	plmxml_api::Result SetLabel( const plmxml_api::String &s );
	
	//! Check if Label is set
	plmxml_api::logical HasLabel( ) const;
	
	//! Unset Label
	plmxml_api::Result UnsetLabel( );
public:

     // <PLMXML_UserCode type="functionHeaderAnnotationQuery" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassAnnotationQuery;


//! Forward class declarations

////////////////////////////////////////////////////////////////////////////////////
//! RequestInformation class
/*!
\verbatim

      This datatype is used to return status information to the user
      within the resultant PLMXML document. The element is in the form
      of a PLMXML attribute. This implies that an PLMXML docuemnt could 
      just be returned with one RequestInformation element in it - 
      useful for returning errors and no data.
    
      Attributes:
    
      requestId:     (required) The application request identifier.
      result:        (default=Success) Indicates success or failure with a code.
      description:   (optional) textual description of failure, etc. 
    
\endverbatim
*/
class PLMXML_DEPRECATED_API RequestInformation : public Attribute
{
public:
     
    //! Default constructor
    RequestInformation( );
     
    //! Constructs a RequestInformation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RequestInformation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RequestInformation();

private:

	//! Assignment operator
	RequestInformation& operator=( const RequestInformation& iSrc );

	//! Copy constructor
	RequestInformation( const RequestInformation& original );
     
public:

	//! Get Description of this RequestInformation
	plmxml_api::String GetDescription() const;

	//! Set Description of this RequestInformation
	plmxml_api::Result SetDescription( const plmxml_api::String &s );
	
	//! Check if Description is set
	plmxml_api::logical HasDescription( ) const;
	
	//! Unset Description
	plmxml_api::Result UnsetDescription( );

	//! Set Result
	plmxml_api::Result SetResult( const eRequestResultType& arg );

	//! Get Result
	eRequestResultType GetResult() const;

	//! Get RequestId of this RequestInformation
	plmxml_api::String GetRequestId() const;

	//! Set RequestId of this RequestInformation
	plmxml_api::Result SetRequestId( const plmxml_api::String &s );
	
	//! Check if RequestId is set
	plmxml_api::logical HasRequestId( ) const;
	
	//! Unset RequestId
	plmxml_api::Result UnsetRequestId( );
public:

     // <PLMXML_UserCode type="functionHeaderRequestInformation" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_DEPRECATED_API plmxml_api::plmxmlClass plmxmlClassRequestInformation;

//////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

/*! \namespace plmxml_deprecated
    \brief PLMXML_DEPRECATED extensions namespace.

    Namespace includes PLMXML_DEPRECATED extensions.
*/
PLMXML_BEGIN_NAMESPACE( plmxml_deprecated )

PLMXML_END_NAMESPACE

#endif
