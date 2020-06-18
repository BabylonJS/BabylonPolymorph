/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 14:23:17
// 
// Schema:	PLMXMLDeltaSchema.xsd
// Data:	08/06/2018 14:23:13
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_DELTA60_H__
#define __PLMXML_DELTA60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_DELTA60_EXPORTS
#define PLMXML_DELTA60_API __declspec(dllexport)
#else
#define PLMXML_DELTA60_API __declspec(dllimport)
#endif
#else
#define PLMXML_DELTA60_API
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
//! eDeltaModifyOpType class
/*!
Allowed Values:
\verbatim
  eDeltaModifyOpTypeAdd
	"add"
  eDeltaModifyOpTypeModifyUserData
	"modifyUserData"
  eDeltaModifyOpTypeDelete
	"delete"
  eDeltaModifyOpTypeRemove
	"remove"
  eDeltaModifyOpTypeReplace
	"replace"
  eDeltaModifyOpTypeSetOwner
	"setOwner"
  
\endverbatim
*/
class PLMXML_DELTA60_API eDeltaModifyOpType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDeltaModifyOpType( const char* Type );
     
	//! Constructor
	eDeltaModifyOpType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDeltaModifyOpType( );
     
	//! Destructor 
	virtual ~eDeltaModifyOpType( );
     
	//! Assign from 'Type'
	const eDeltaModifyOpType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDeltaModifyOpType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DeltaModifyOpType
	friend plmxml_api::logical PLMXML_DELTA60_API operator==( const eDeltaModifyOpType& e1, const eDeltaModifyOpType& e2 );
     
	//! Compare DeltaModifyOpType
	friend plmxml_api::logical PLMXML_DELTA60_API operator!=( const eDeltaModifyOpType& e1, const eDeltaModifyOpType& e2 );
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDeltaModifyOpType;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeUnset;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeAdd;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeModifyUserData;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeDelete;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeRemove;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeReplace;
extern PLMXML_DELTA60_API eDeltaModifyOpType eDeltaModifyOpTypeSetOwner;

////////////////////////////////////////////////////////////////////////////////////
//! DeltaOperation class
/*!
\verbatim

      Base class for elements which define Delta operations, 
      i.e. DeltaAdd, DeltaDelete, DeltaModify, DeltaReplace
      
\endverbatim
*/
class PLMXML_DELTA60_API DeltaOperation : public plmxml_api::Object
{
public:
     
    //! Default constructor
    DeltaOperation( );
     
    //! Constructs a DeltaOperation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeltaOperation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeltaOperation();

private:

	//! Assignment operator
	DeltaOperation& operator=( const DeltaOperation& iSrc );

	//! Copy constructor
	DeltaOperation( const DeltaOperation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderDeltaOperation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassDeltaOperation;


////////////////////////////////////////////////////////////////////////////////////
//! DeltaAdd class
/*!
\verbatim

      This element represents adding a fragment of PLMXML, i.e. a tree of elements, to
      a master document.
      
      The sub-elements of this element are all added.
      
      Attributes:
      
      parentRef:       A URI reference to a placeholder element which represents the
                       element in the master document which will become the parent of the
                       added elements. Exactly one of parentRef or siblingRef should be present.
                       
      siblingRef:      A URI reference to a placeholder element which represents the
                       element in the master document which will become a sibling
                       of the added elements. There is no implication that the added element
                       will be adjacent to the sibling element in the sub-element ordering -
                       only that it will have the same parent.
      
      Elements:
      
      Any PLMXML elements may be included as sub-elements.
      
\endverbatim
*/
class PLMXML_DELTA60_API DeltaAdd : public DeltaOperation
{
public:
     
    //! Default constructor
    DeltaAdd( );
     
    //! Constructs a DeltaAdd with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeltaAdd( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeltaAdd();

private:

	//! Assignment operator
	DeltaAdd& operator=( const DeltaAdd& iSrc );

	//! Copy constructor
	DeltaAdd( const DeltaAdd& original );
     
public:

	//! Get Sibling URI as plmxml_api::String
	plmxml_api::String GetSiblingURI() const;

	//! Set Sibling URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSiblingURI( const plmxml_api::String& );
	
	//! Get the handle of Sibling URI. Does not resolve the URI.
	plmxml_api::Result GetSiblingURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Sibling URI. URI string is unchanged.
	plmxml_api::Result SetSiblingURI( const plmxml_api::Handle& );
	
	//! Resolve Sibling URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSiblingURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Sibling URI. Clears URI string and handle.
	plmxml_api::Result DeleteSiblingURI();
	
	//! Check if Sibling URI is set
	plmxml_api::logical HasSiblingURI( ) const;
	

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
	
 
// <PLMXML_UserCode type="functionHeaderDeltaAdd" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassDeltaAdd;


////////////////////////////////////////////////////////////////////////////////////
//! DeltaReplace class
/*!
\verbatim

      This element represents replacing a fragment of PLMXML, i.e. a tree of elements, with
      another tree.
      
      The sub-element of this element is used to replace the target element and all its
      descendents.
      
      Attributes:
      
      targetRef:       A URI reference to a placeholder element which represents the
                       element in the master document which will be replaced.
      
      Elements:
      
      Any PLMXML element may be included as sub-element. There must be exactly one.
      
\endverbatim
*/
class PLMXML_DELTA60_API DeltaReplace : public DeltaOperation
{
public:
     
    //! Default constructor
    DeltaReplace( );
     
    //! Constructs a DeltaReplace with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeltaReplace( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeltaReplace();

private:

	//! Assignment operator
	DeltaReplace& operator=( const DeltaReplace& iSrc );

	//! Copy constructor
	DeltaReplace( const DeltaReplace& original );
     
public:

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
	
 
// <PLMXML_UserCode type="functionHeaderDeltaReplace" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassDeltaReplace;


////////////////////////////////////////////////////////////////////////////////////
//! DeltaDelete class
/*!
\verbatim

      This element represents deleting a fragment of PLMXML, i.e. a tree of elements, from
      a master document.
      
      NOTE that it also removes any IDREF or local URI references to those elements, since 
      normally you would not want 'dangling' references left. For example, deleting an Instance 
      will automatically remove that Instance from any 'instanceRefs' attributes which reference
      it. 
      
      Attributes:
      
      targetRefs:       A multiple URI reference to placeholder element(s) which represent the
                        elements in the master document which will be deleted, along with
                        their sub-elements.
      
\endverbatim
*/
class PLMXML_DELTA60_API DeltaDelete : public DeltaOperation
{
public:
     
    //! Default constructor
    DeltaDelete( );
     
    //! Constructs a DeltaDelete with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeltaDelete( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeltaDelete();

private:

	//! Assignment operator
	DeltaDelete& operator=( const DeltaDelete& iSrc );

	//! Copy constructor
	DeltaDelete( const DeltaDelete& original );
     
public:

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
 
// <PLMXML_UserCode type="functionHeaderDeltaDelete" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassDeltaDelete;


////////////////////////////////////////////////////////////////////////////////////
//! DeltaModify class
/*!
\verbatim

      This element represents modifying an element in a master document in some way, 
      depending on the 'op' attribute.
            
      Attributes:
      
      targetRef:        A URI reference to a placeholder element which represents the
                        element in the master document which will be modified.
                        
      attributeName:    The name of the attribute being modified, if any.
      
      values:           The value or values to be used when modifying the attribute. The way in 
                          which this is used to make the modification is determined by the 
                          'op' attribute. 
                          
      valueRefs:        URI reference to placeholder element(s) which represent
                          elements in the master document; or to elements in Add or Replace
                          blocks in this delta. The attribute being modified is
                          altered to reference these elements, according to the value of the
                          'op' attribute.
                          
      op:               This determines the operation used to make the modification. One of
      
                        'replace'        completely replaces an existing attribute value, with 
                                         the value in 'values' or 'valueRefs'.
                        'add'            adds the values in 'values' or 'valueRefs' to an existing
                                         attribute, for example an integer array, IDREFS or multiple
                                         URI attribute.
                        'remove'         removes the values in 'values' or 'valueRefs' from an
                                         existing attribute.
                        'delete'         deletes an existing attribute entirely.
                        
                        'modifyUserData' merges the UserData of this Modify element into the 
                                         UserData of the target element. 'attributeName' is
                                         not set in this case.
      
\endverbatim
*/
class PLMXML_DELTA60_API DeltaModify : public DeltaOperation
{
public:
     
    //! Default constructor
    DeltaModify( );
     
    //! Constructs a DeltaModify with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeltaModify( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeltaModify();

private:

	//! Assignment operator
	DeltaModify& operator=( const DeltaModify& iSrc );

	//! Copy constructor
	DeltaModify( const DeltaModify& original );
     
public:

	//! Set Op
	plmxml_api::Result SetOp( const eDeltaModifyOpType& arg );

	//! Get Op
	eDeltaModifyOpType GetOp() const;

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
	

	//! Get AttributeName of this DeltaModify
	plmxml_api::String GetAttributeName() const;

	//! Set AttributeName of this DeltaModify
	plmxml_api::Result SetAttributeName( const plmxml_api::String &s );
	
	//! Check if AttributeName is set
	plmxml_api::logical HasAttributeName( ) const;
	
	//! Unset AttributeName
	plmxml_api::Result UnsetAttributeName( );

	//! Get number of URIs in Value
	int NumberOfValueURIs() const;

	//! Get i'th URI in Value
	plmxml_api::String GetValueURI( int i ) const;

	//! Add a URI to Value array. Call ResolveValueURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddValueURI( const plmxml_api::String& u );

	//! Set i'th URI in Value array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetValueURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Value URI. Does not resolve the URI.
	plmxml_api::Result GetValueURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Value array.
	plmxml_api::Result AddValueURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Value array to point to 'handle'.
	plmxml_api::Result SetValueURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Value points to.
	plmxml_api::Result ResolveValueURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Value array.
	plmxml_api::Result DeleteValueURI( int i );

	//! Remove all URIs from Value array.
	plmxml_api::Result DeleteValueURIs( );
	
	//! Check if Value is set
	plmxml_api::logical HasValueURIs( ) const;

	//! Get Values of this DeltaModify
	plmxml_api::String GetValues() const;

	//! Set Values of this DeltaModify
	plmxml_api::Result SetValues( const plmxml_api::String &s );
	
	//! Check if Values is set
	plmxml_api::logical HasValues( ) const;
	
	//! Unset Values
	plmxml_api::Result UnsetValues( );
 
// <PLMXML_UserCode type="functionHeaderDeltaModify" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassDeltaModify;


////////////////////////////////////////////////////////////////////////////////////
//! ExternalReference class
/*!
\verbatim

      This element is a reference to an object in an Application data model. At present it 
      identifies the object by containing one or more ApplicationRef or NGID sub-elements.
      
      Attributes:
      
      type:           Optional PLMXML type of the external object, e.g. "ProductRevision"
      
      select:         If this attribute is present, it will be an XPATH string, which 
                      identifies the referenced object relative to a parent object, which 
                      is identified by the ApplcationRef sub-elements. The XPATH string will
                      be in terms of the PLMXML schema, but it will be interpreted as 
                      applying to the Application data model.
      SubElements:
      
      NGID:           Contains an identifier in NGID format.
      
\endverbatim
*/
class PLMXML_DELTA60_API ExternalReference : public AttribOwner
{
public:
     
    //! Default constructor
    ExternalReference( );
     
    //! Constructs a ExternalReference with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExternalReference( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExternalReference();

private:

	//! Assignment operator
	ExternalReference& operator=( const ExternalReference& iSrc );

	//! Copy constructor
	ExternalReference( const ExternalReference& original );
     
public:

	//! Get Type of this ExternalReference
	plmxml_api::String GetType() const;

	//! Set Type of this ExternalReference
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get Select of this ExternalReference
	plmxml_api::String GetSelect() const;

	//! Set Select of this ExternalReference
	plmxml_api::Result SetSelect( const plmxml_api::String &s );
	
	//! Check if Select is set
	plmxml_api::logical HasSelect( ) const;
	
	//! Unset Select
	plmxml_api::Result UnsetSelect( );

	//! Get NGID of this ExternalReference
	plmxml_api::String GetNGID() const;

	//! Set NGID of this ExternalReference
	plmxml_api::Result SetNGID( const plmxml_api::String &s );
	
	//! Check if NGID is set
	plmxml_api::logical HasNGID( ) const;
	
	//! Unset NGID
	plmxml_api::Result UnsetNGID( );
 
// <PLMXML_UserCode type="functionHeaderExternalReference" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassExternalReference;


////////////////////////////////////////////////////////////////////////////////////
//! DeltaOperationGroup class
/*!
\verbatim

      NB This is an extension to the DELTA schema included here to avoid
      the need for a separate schema.
      
      A group of Delta Operations. A context can be provided by adding an
      ApplicationRef sub-element of this element.
      
      SubElements:
      
      Add:            Add elements, representing the addition of a tree of elements
      Replace:        Replace elements, representing the replacement of a tree of elements
      Delete:         Delete elements, representing the deletion of trees of elements
      Modify:         Modify elements, representing an alteration to an attribute of
                        an element.
      
\endverbatim
*/
class PLMXML_DELTA60_API DeltaOperationGroup : public DescriptionObject
{
public:
     
    //! Default constructor
    DeltaOperationGroup( );
     
    //! Constructs a DeltaOperationGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DeltaOperationGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DeltaOperationGroup();

private:

	//! Assignment operator
	DeltaOperationGroup& operator=( const DeltaOperationGroup& iSrc );

	//! Copy constructor
	DeltaOperationGroup( const DeltaOperationGroup& original );
     
public:

	//! Add Add child element to this DeltaOperationGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaAdd *AddAdd();
     
	//! Add 'arg' as Add child element to this DeltaOperationGroup.
	plmxml_api::Result AddAdd( DeltaAdd *arg );

	//! Detach and delete all Add child elements.
	void DeleteAdds();
     
	//! Get number of Add child elements.
	int NumberOfAdds() const;
     
	//! Get i'th Add child element.
	DeltaAdd *GetAdd( int i ) const;
     
	//! Get all Add child element as an array
	void GetAdds( plmxml_api::Array<DeltaAdd*> &array ) const;
	     
	//! Detach and delete i'th Add child element
	void DeleteAdd( int i );
     
	//! Detach and delete 'arg' if it's one of the Add child elements
	void DeleteAdd( DeltaAdd *arg );

	//! Add Replace child element to this DeltaOperationGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaReplace *AddReplace();
     
	//! Add 'arg' as Replace child element to this DeltaOperationGroup.
	plmxml_api::Result AddReplace( DeltaReplace *arg );

	//! Detach and delete all Replace child elements.
	void DeleteReplaces();
     
	//! Get number of Replace child elements.
	int NumberOfReplaces() const;
     
	//! Get i'th Replace child element.
	DeltaReplace *GetReplace( int i ) const;
     
	//! Get all Replace child element as an array
	void GetReplaces( plmxml_api::Array<DeltaReplace*> &array ) const;
	     
	//! Detach and delete i'th Replace child element
	void DeleteReplace( int i );
     
	//! Detach and delete 'arg' if it's one of the Replace child elements
	void DeleteReplace( DeltaReplace *arg );

	//! Add Delete child element to this DeltaOperationGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaDelete *AddDelete();
     
	//! Add 'arg' as Delete child element to this DeltaOperationGroup.
	plmxml_api::Result AddDelete( DeltaDelete *arg );

	//! Detach and delete all Delete child elements.
	void DeleteDeletes();
     
	//! Get number of Delete child elements.
	int NumberOfDeletes() const;
     
	//! Get i'th Delete child element.
	DeltaDelete *GetDelete( int i ) const;
     
	//! Get all Delete child element as an array
	void GetDeletes( plmxml_api::Array<DeltaDelete*> &array ) const;
	     
	//! Detach and delete i'th Delete child element
	void DeleteDelete( int i );
     
	//! Detach and delete 'arg' if it's one of the Delete child elements
	void DeleteDelete( DeltaDelete *arg );

	//! Add Modify child element to this DeltaOperationGroup. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaModify *AddModify();
     
	//! Add 'arg' as Modify child element to this DeltaOperationGroup.
	plmxml_api::Result AddModify( DeltaModify *arg );

	//! Detach and delete all Modify child elements.
	void DeleteModifies();
     
	//! Get number of Modify child elements.
	int NumberOfModifies() const;
     
	//! Get i'th Modify child element.
	DeltaModify *GetModify( int i ) const;
     
	//! Get all Modify child element as an array
	void GetModifies( plmxml_api::Array<DeltaModify*> &array ) const;
	     
	//! Detach and delete i'th Modify child element
	void DeleteModify( int i );
     
	//! Detach and delete 'arg' if it's one of the Modify child elements
	void DeleteModify( DeltaModify *arg );
 
// <PLMXML_UserCode type="functionHeaderDeltaOperationGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassDeltaOperationGroup;


////////////////////////////////////////////////////////////////////////////////////
//! PLMXMLDelta class
/*!
\verbatim

      The top-level element in a PLMXML Delta file. This represents a delta, or change,
      to be applied to a PLMXML file or equivalent Application model (the 'master' file/model).
      
      Attributes:
      
      context:        A URI or other indication of the master Document or model to which 
                      this delta is to be applied.
      
      SubElements:
      
      Add:            Add elements, representing the addition of a tree of elements
      Replace:        Replace elements, representing the replacement of a tree of elements
      Delete:         Delete elements, representing the deletion of trees of elements
      Modify:         Modify elements, representing an alteration to an attribute of
                        an element.
                        
      ExternalReference:    References to Application objects. 
      
\endverbatim
*/
class PLMXML_DELTA60_API PLMXMLDelta : public DocumentBase
{
public:
     
    //! Default constructor
    PLMXMLDelta( );
     
    //! Constructs a PLMXMLDelta with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PLMXMLDelta( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PLMXMLDelta();

private:

	//! Assignment operator
	PLMXMLDelta& operator=( const PLMXMLDelta& iSrc );

	//! Copy constructor
	PLMXMLDelta( const PLMXMLDelta& original );
     
public:

	//! Get Context of this PLMXMLDelta
	plmxml_api::String GetContext() const;

	//! Set Context of this PLMXMLDelta
	plmxml_api::Result SetContext( const plmxml_api::String &s );
	
	//! Check if Context is set
	plmxml_api::logical HasContext( ) const;
	
	//! Unset Context
	plmxml_api::Result UnsetContext( );

	//! Add Add child element to this PLMXMLDelta. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaAdd *AddAdd();
     
	//! Add 'arg' as Add child element to this PLMXMLDelta.
	plmxml_api::Result AddAdd( DeltaAdd *arg );

	//! Detach and delete all Add child elements.
	void DeleteAdds();
     
	//! Get number of Add child elements.
	int NumberOfAdds() const;
     
	//! Get i'th Add child element.
	DeltaAdd *GetAdd( int i ) const;
     
	//! Get all Add child element as an array
	void GetAdds( plmxml_api::Array<DeltaAdd*> &array ) const;
	     
	//! Detach and delete i'th Add child element
	void DeleteAdd( int i );
     
	//! Detach and delete 'arg' if it's one of the Add child elements
	void DeleteAdd( DeltaAdd *arg );

	//! Add Replace child element to this PLMXMLDelta. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaReplace *AddReplace();
     
	//! Add 'arg' as Replace child element to this PLMXMLDelta.
	plmxml_api::Result AddReplace( DeltaReplace *arg );

	//! Detach and delete all Replace child elements.
	void DeleteReplaces();
     
	//! Get number of Replace child elements.
	int NumberOfReplaces() const;
     
	//! Get i'th Replace child element.
	DeltaReplace *GetReplace( int i ) const;
     
	//! Get all Replace child element as an array
	void GetReplaces( plmxml_api::Array<DeltaReplace*> &array ) const;
	     
	//! Detach and delete i'th Replace child element
	void DeleteReplace( int i );
     
	//! Detach and delete 'arg' if it's one of the Replace child elements
	void DeleteReplace( DeltaReplace *arg );

	//! Add Delete child element to this PLMXMLDelta. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaDelete *AddDelete();
     
	//! Add 'arg' as Delete child element to this PLMXMLDelta.
	plmxml_api::Result AddDelete( DeltaDelete *arg );

	//! Detach and delete all Delete child elements.
	void DeleteDeletes();
     
	//! Get number of Delete child elements.
	int NumberOfDeletes() const;
     
	//! Get i'th Delete child element.
	DeltaDelete *GetDelete( int i ) const;
     
	//! Get all Delete child element as an array
	void GetDeletes( plmxml_api::Array<DeltaDelete*> &array ) const;
	     
	//! Detach and delete i'th Delete child element
	void DeleteDelete( int i );
     
	//! Detach and delete 'arg' if it's one of the Delete child elements
	void DeleteDelete( DeltaDelete *arg );

	//! Add Modify child element to this PLMXMLDelta. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaModify *AddModify();
     
	//! Add 'arg' as Modify child element to this PLMXMLDelta.
	plmxml_api::Result AddModify( DeltaModify *arg );

	//! Detach and delete all Modify child elements.
	void DeleteModifies();
     
	//! Get number of Modify child elements.
	int NumberOfModifies() const;
     
	//! Get i'th Modify child element.
	DeltaModify *GetModify( int i ) const;
     
	//! Get all Modify child element as an array
	void GetModifies( plmxml_api::Array<DeltaModify*> &array ) const;
	     
	//! Detach and delete i'th Modify child element
	void DeleteModify( int i );
     
	//! Detach and delete 'arg' if it's one of the Modify child elements
	void DeleteModify( DeltaModify *arg );

	//! Add ExternalReference child element to this PLMXMLDelta. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ExternalReference *AddExternalReference();
     
	//! Add 'arg' as ExternalReference child element to this PLMXMLDelta.
	plmxml_api::Result AddExternalReference( ExternalReference *arg );

	//! Detach and delete all ExternalReference child elements.
	void DeleteExternalReferences();
     
	//! Get number of ExternalReference child elements.
	int NumberOfExternalReferences() const;
     
	//! Get i'th ExternalReference child element.
	ExternalReference *GetExternalReference( int i ) const;
     
	//! Get all ExternalReference child element as an array
	void GetExternalReferences( plmxml_api::Array<ExternalReference*> &array ) const;
	     
	//! Detach and delete i'th ExternalReference child element
	void DeleteExternalReference( int i );
     
	//! Detach and delete 'arg' if it's one of the ExternalReference child elements
	void DeleteExternalReference( ExternalReference *arg );

	//! Add DeltaOperationGroup child element to this PLMXMLDelta. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DeltaOperationGroup *AddDeltaOperationGroup();
     
	//! Add 'arg' as DeltaOperationGroup child element to this PLMXMLDelta.
	plmxml_api::Result AddDeltaOperationGroup( DeltaOperationGroup *arg );

	//! Detach and delete all DeltaOperationGroup child elements.
	void DeleteDeltaOperationGroups();
     
	//! Get number of DeltaOperationGroup child elements.
	int NumberOfDeltaOperationGroups() const;
     
	//! Get i'th DeltaOperationGroup child element.
	DeltaOperationGroup *GetDeltaOperationGroup( int i ) const;
     
	//! Get all DeltaOperationGroup child element as an array
	void GetDeltaOperationGroups( plmxml_api::Array<DeltaOperationGroup*> &array ) const;
	     
	//! Detach and delete i'th DeltaOperationGroup child element
	void DeleteDeltaOperationGroup( int i );
     
	//! Detach and delete 'arg' if it's one of the DeltaOperationGroup child elements
	void DeleteDeltaOperationGroup( DeltaOperationGroup *arg );
 
// <PLMXML_UserCode type="functionHeaderPLMXMLDelta" >
    //! Apply this delta document to the given Master document
	/*!
	The Master document is modified according to the contents of the
	Delta document. Fragments of the Delta contained in Add and Replace
	blocks are transferred to the Master. The rest of the Delta is then
	deleted.
	*/
	plmxml_api::Result Apply( plmxml_api::Object *pMaster, plmxml_api::Configuration* pConf=NULL );
     
	//! Create Delta document representing difference between two subtrees.
	/*!
	Analyse difference between two nodes and their subtrees and
	create Delta document.
	*/
	static plmxml_api::Result Create( plmxml_api::Object *pNode1, plmxml_api::Object *pNode2, PLMXMLDelta*& delta, plmxml_api::Configuration* pConf=NULL );
// </PLMXML_UserCode>
};
extern PLMXML_DELTA60_API plmxml_api::plmxmlClass plmxmlClassPLMXMLDelta;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
