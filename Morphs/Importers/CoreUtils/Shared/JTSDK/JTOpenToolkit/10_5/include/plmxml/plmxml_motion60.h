/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 14:26:27
// 
// Schema:	PLMXMLMotionSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_MOTION60_H__
#define __PLMXML_MOTION60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_MOTION60_EXPORTS
#define PLMXML_MOTION60_API __declspec(dllexport)
#else
#define PLMXML_MOTION60_API __declspec(dllimport)
#endif
#else
#define PLMXML_MOTION60_API
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
//! eFrameTypeEnum class
/*!
Allowed Values:
\verbatim
  eFrameTypeEnumSimple
	"simple"
  eFrameTypeEnumKey
	"key"
  
\endverbatim
*/
class PLMXML_MOTION60_API eFrameTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eFrameTypeEnum( const char* Type );
     
	//! Constructor
	eFrameTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eFrameTypeEnum( );
     
	//! Destructor 
	virtual ~eFrameTypeEnum( );
     
	//! Assign from 'Type'
	const eFrameTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eFrameTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare FrameTypeEnum
	friend plmxml_api::logical PLMXML_MOTION60_API operator==( const eFrameTypeEnum& e1, const eFrameTypeEnum& e2 );
     
	//! Compare FrameTypeEnum
	friend plmxml_api::logical PLMXML_MOTION60_API operator!=( const eFrameTypeEnum& e1, const eFrameTypeEnum& e2 );
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumFrameTypeEnum;
extern PLMXML_MOTION60_API eFrameTypeEnum eFrameTypeEnumUnset;
extern PLMXML_MOTION60_API eFrameTypeEnum eFrameTypeEnumSimple;
extern PLMXML_MOTION60_API eFrameTypeEnum eFrameTypeEnumKey;

////////////////////////////////////////////////////////////////////////////////////
//! eMotionTransformEnum class
/*!
Allowed Values:
\verbatim
  eMotionTransformEnumRelative
	"relative"
  eMotionTransformEnumAbsolute
	"absolute"
  
\endverbatim
*/
class PLMXML_MOTION60_API eMotionTransformEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eMotionTransformEnum( const char* Type );
     
	//! Constructor
	eMotionTransformEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eMotionTransformEnum( );
     
	//! Destructor 
	virtual ~eMotionTransformEnum( );
     
	//! Assign from 'Type'
	const eMotionTransformEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eMotionTransformEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare MotionTransformEnum
	friend plmxml_api::logical PLMXML_MOTION60_API operator==( const eMotionTransformEnum& e1, const eMotionTransformEnum& e2 );
     
	//! Compare MotionTransformEnum
	friend plmxml_api::logical PLMXML_MOTION60_API operator!=( const eMotionTransformEnum& e1, const eMotionTransformEnum& e2 );
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumMotionTransformEnum;
extern PLMXML_MOTION60_API eMotionTransformEnum eMotionTransformEnumUnset;
extern PLMXML_MOTION60_API eMotionTransformEnum eMotionTransformEnumRelative;
extern PLMXML_MOTION60_API eMotionTransformEnum eMotionTransformEnumAbsolute;

//! Forward class declarations
class FrameSequenceInstance;

////////////////////////////////////////////////////////////////////////////////////
//! MotionAssembly class
/*!
\verbatim

            The container element for a sequence of FrameSequenceInstance
            elements.
            
            Sub-elements:
            
            FrameSequenceInstance: The instances of the FrameSequences in the
                            sequence.

          
\endverbatim
*/
class PLMXML_MOTION60_API MotionAssembly : public AttribOwner
{
public:
     
    //! Default constructor
    MotionAssembly( );
     
    //! Constructs a MotionAssembly with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MotionAssembly( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MotionAssembly();

private:

	//! Assignment operator
	MotionAssembly& operator=( const MotionAssembly& iSrc );

	//! Copy constructor
	MotionAssembly( const MotionAssembly& original );
     
public:

	//! Add FrameSequenceInstance child element to this MotionAssembly. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FrameSequenceInstance *AddFrameSequenceInstance();
     
	//! Add 'arg' as FrameSequenceInstance child element to this MotionAssembly.
	plmxml_api::Result AddFrameSequenceInstance( FrameSequenceInstance *arg );

	//! Detach and delete all FrameSequenceInstance child elements.
	void DeleteFrameSequenceInstances();
     
	//! Get number of FrameSequenceInstance child elements.
	int NumberOfFrameSequenceInstances() const;
     
	//! Get i'th FrameSequenceInstance child element.
	FrameSequenceInstance *GetFrameSequenceInstance( int i ) const;
     
	//! Get all FrameSequenceInstance child element as an array
	void GetFrameSequenceInstances( plmxml_api::Array<FrameSequenceInstance*> &array ) const;
	     
	//! Detach and delete i'th FrameSequenceInstance child element
	void DeleteFrameSequenceInstance( int i );
     
	//! Detach and delete 'arg' if it's one of the FrameSequenceInstance child elements
	void DeleteFrameSequenceInstance( FrameSequenceInstance *arg );
 
// <PLMXML_UserCode type="functionHeaderMotionAssembly" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlClass plmxmlClassMotionAssembly;


////////////////////////////////////////////////////////////////////////////////////
//! FrameSequenceInstance class
/*!
\verbatim

            An instance of a FrameSequence.
            
            Attributes:
            
            frameSequenceRef: References a FrameSequence.
            timeStamp:      The time in seconds (SI units) of the start of the
                            FrameSequence with respect to some external datum.
                            This overrides the timeStamp attribute on the
                            FrameSequence.
          
\endverbatim
*/
class PLMXML_MOTION60_API FrameSequenceInstance : public AttribOwner
{
public:
     
    //! Default constructor
    FrameSequenceInstance( );
     
    //! Constructs a FrameSequenceInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FrameSequenceInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FrameSequenceInstance();

private:

	//! Assignment operator
	FrameSequenceInstance& operator=( const FrameSequenceInstance& iSrc );

	//! Copy constructor
	FrameSequenceInstance( const FrameSequenceInstance& original );
     
public:

	//! Set TimeStamp
	plmxml_api::Result SetTimeStamp( double arg );

     //! Get TimeStamp
	double GetTimeStamp() const;

	//! Check if TimeStamp is set
	plmxml_api::logical HasTimeStamp() const;

	//! Unset TimeStamp
	plmxml_api::Result UnsetTimeStamp();

	//! Get FrameSequence URI as plmxml_api::String
	plmxml_api::String GetFrameSequenceURI() const;

	//! Set FrameSequence URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFrameSequenceURI( const plmxml_api::String& );
	
	//! Get the handle of FrameSequence URI. Does not resolve the URI.
	plmxml_api::Result GetFrameSequenceURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of FrameSequence URI. URI string is unchanged.
	plmxml_api::Result SetFrameSequenceURI( const plmxml_api::Handle& );
	
	//! Resolve FrameSequence URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFrameSequenceURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset FrameSequence URI. Clears URI string and handle.
	plmxml_api::Result DeleteFrameSequenceURI();
	
	//! Check if FrameSequence URI is set
	plmxml_api::logical HasFrameSequenceURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderFrameSequenceInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlClass plmxmlClassFrameSequenceInstance;


//! Forward class declarations
class Frame;

////////////////////////////////////////////////////////////////////////////////////
//! FrameSequence class
/*!
\verbatim

            A sequence of Frames that defines Motion results definition.
            FrameSequences are independent.
            
            Attributes:
            
            frameRate:      The frame rate in frames per second (SI units).
            timeStamp:      The time in seconds (SI units) of the first Frame in
                            the sequence with respect to some external datum.
              
            Sub-elements:
            
            Frame:          The Frames in the sequence.
          
\endverbatim
*/
class PLMXML_MOTION60_API FrameSequence : public AttribOwner
{
public:
     
    //! Default constructor
    FrameSequence( );
     
    //! Constructs a FrameSequence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FrameSequence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FrameSequence();

private:

	//! Assignment operator
	FrameSequence& operator=( const FrameSequence& iSrc );

	//! Copy constructor
	FrameSequence( const FrameSequence& original );
     
public:

	//! Set TimeStamp
	plmxml_api::Result SetTimeStamp( double arg );

     //! Get TimeStamp
	double GetTimeStamp() const;

	//! Check if TimeStamp is set
	plmxml_api::logical HasTimeStamp() const;

	//! Unset TimeStamp
	plmxml_api::Result UnsetTimeStamp();

	//! Set FrameRate
	plmxml_api::Result SetFrameRate( double arg );

     //! Get FrameRate
	double GetFrameRate() const;

	//! Check if FrameRate is set
	plmxml_api::logical HasFrameRate() const;

	//! Unset FrameRate
	plmxml_api::Result UnsetFrameRate();

	//! Add Frame child element to this FrameSequence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Frame *AddFrame();
     
	//! Add 'arg' as Frame child element to this FrameSequence.
	plmxml_api::Result AddFrame( Frame *arg );

	//! Detach and delete all Frame child elements.
	void DeleteFrames();
     
	//! Get number of Frame child elements.
	int NumberOfFrames() const;
     
	//! Get i'th Frame child element.
	Frame *GetFrame( int i ) const;
     
	//! Get all Frame child element as an array
	void GetFrames( plmxml_api::Array<Frame*> &array ) const;
	     
	//! Detach and delete i'th Frame child element
	void DeleteFrame( int i );
     
	//! Detach and delete 'arg' if it's one of the Frame child elements
	void DeleteFrame( Frame *arg );
 
// <PLMXML_UserCode type="functionHeaderFrameSequence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlClass plmxmlClassFrameSequence;


//! Forward class declarations
class MotionEntityRef;

////////////////////////////////////////////////////////////////////////////////////
//! Frame class
/*!
\verbatim

            A Frame of type simple represents a single Frame at the time of the
            previous frame plus the reciprocal of the frame rate in seconds (SI
            units). A Frame of type key represents a key Frame that is linearly
            interpolated at the frame rate up to the time of the previous frame
            plus the duration in seconds (SI units).
            
            Attributes:
            
            type:           The type of a Frame, either simple (the default) or
                            key.
            duration:       The time in seconds (SI units) of a Frame relative
                            to the previous frame.
            
            Sub-elements:
            
            MotionEntityRef: The references to the MotionEntity elements, which
                            represent the conceptual motion entities or bodies.
          
\endverbatim
*/
class PLMXML_MOTION60_API Frame : public AttribOwner
{
public:
     
    //! Default constructor
    Frame( );
     
    //! Constructs a Frame with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Frame( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Frame();

private:

	//! Assignment operator
	Frame& operator=( const Frame& iSrc );

	//! Copy constructor
	Frame( const Frame& original );
     
public:

	//! Set Duration
	plmxml_api::Result SetDuration( double arg );

     //! Get Duration
	double GetDuration() const;

	//! Check if Duration is set
	plmxml_api::logical HasDuration() const;

	//! Unset Duration
	plmxml_api::Result UnsetDuration();

	//! Set Type
	plmxml_api::Result SetType( const eFrameTypeEnum& arg );

	//! Get Type
	eFrameTypeEnum GetType() const;

	//! Add MotionEntityRef child element to this Frame. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MotionEntityRef *AddMotionEntityRef();
     
	//! Add 'arg' as MotionEntityRef child element to this Frame.
	plmxml_api::Result AddMotionEntityRef( MotionEntityRef *arg );

	//! Detach and delete all MotionEntityRef child elements.
	void DeleteMotionEntityRefs();
     
	//! Get number of MotionEntityRef child elements.
	int NumberOfMotionEntityRefs() const;
     
	//! Get i'th MotionEntityRef child element.
	MotionEntityRef *GetMotionEntityRef( int i ) const;
     
	//! Get all MotionEntityRef child element as an array
	void GetMotionEntityRefs( plmxml_api::Array<MotionEntityRef*> &array ) const;
	     
	//! Detach and delete i'th MotionEntityRef child element
	void DeleteMotionEntityRef( int i );
     
	//! Detach and delete 'arg' if it's one of the MotionEntityRef child elements
	void DeleteMotionEntityRef( MotionEntityRef *arg );
 
// <PLMXML_UserCode type="functionHeaderFrame" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlClass plmxmlClassFrame;


////////////////////////////////////////////////////////////////////////////////////
//! MotionEntityRef class
/*!
\verbatim

            Applies a Transform sub-element to one or more conceptual motion
            entities or bodies. A MotionEntityRef may have an absolute or
            relative Transform.

            Attributes:

            transformType:  Specifies whether the Transform sub-element is
                            applied to the MotionEntity elements referenced by
                            the motionEntityRefs attribute absolutely or
                            relatively (the default). An absolute
                            MotionEntityRef applies its Transform to the
                            MotionEntity elements in the absolute coordinate
                            system. A relative MotionEntityRef applies its
                            Transform relative to the positions and orientations
                            of the MotionEntity elements in a previous Frame.
                            Those positions and orientations are usually defined
                            by the Transform sub-element of a MotionEntityRef in
                            a previous Frame. However, if no previous Frame has
                            a MotionEntityRef that applies to the MotionEntity
                            elements and that has a Transform sub-element, the
                            positions and orientations are defined by the
                            playback application.
            motionEntityRefs: References MotionEntity elements, which represent
                            the conceptual motion entities or bodies.

            Sub-elements:

            Transform:      The Transform that is applied to the MotionEntity
                            elements referenced by the motionEntityRefs
                            attribute.
          
\endverbatim
*/
class PLMXML_MOTION60_API MotionEntityRef : public AttribOwner
{
public:
     
    //! Default constructor
    MotionEntityRef( );
     
    //! Constructs a MotionEntityRef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MotionEntityRef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MotionEntityRef();

private:

	//! Assignment operator
	MotionEntityRef& operator=( const MotionEntityRef& iSrc );

	//! Copy constructor
	MotionEntityRef( const MotionEntityRef& original );
     
public:

	//! Set TransformType
	plmxml_api::Result SetTransformType( const eMotionTransformEnum& arg );

	//! Get TransformType
	eMotionTransformEnum GetTransformType() const;

	//! Get number of URIs in MotionEntity
	int NumberOfMotionEntityURIs() const;

	//! Get i'th URI in MotionEntity
	plmxml_api::String GetMotionEntityURI( int i ) const;

	//! Add a URI to MotionEntity array. Call ResolveMotionEntityURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddMotionEntityURI( const plmxml_api::String& u );

	//! Set i'th URI in MotionEntity array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetMotionEntityURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of MotionEntity URI. Does not resolve the URI.
	plmxml_api::Result GetMotionEntityURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to MotionEntity array.
	plmxml_api::Result AddMotionEntityURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in MotionEntity array to point to 'handle'.
	plmxml_api::Result SetMotionEntityURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in MotionEntity points to.
	plmxml_api::Result ResolveMotionEntityURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from MotionEntity array.
	plmxml_api::Result DeleteMotionEntityURI( int i );

	//! Remove all URIs from MotionEntity array.
	plmxml_api::Result DeleteMotionEntityURIs( );
	
	//! Check if MotionEntity is set
	plmxml_api::logical HasMotionEntityURIs( ) const;

	//! Add Transform child element to this MotionEntityRef. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Transform *AddTransform();
     
	//! Set Transform child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTransform( Transform *arg );
     
	//! Get Transform child element of this MotionEntityRef.
	Transform *GetTransform() const;
     
	//! Detach and delete Transform child element tree from this MotionEntityRef.
	void DeleteTransform();
 
// <PLMXML_UserCode type="functionHeaderMotionEntityRef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlClass plmxmlClassMotionEntityRef;


////////////////////////////////////////////////////////////////////////////////////
//! MotionEntity class
/*!
\verbatim

            A conceptual motion entity or body.
            
            Attribute:
            
            entityRefs:     References Occurrences in the Product Structure or
                            external references.
            
            Sub-elements:
            
            Reference:      Any references to entities within Occurrences.
          
\endverbatim
*/
class PLMXML_MOTION60_API MotionEntity : public AttribOwner
{
public:
     
    //! Default constructor
    MotionEntity( );
     
    //! Constructs a MotionEntity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MotionEntity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MotionEntity();

private:

	//! Assignment operator
	MotionEntity& operator=( const MotionEntity& iSrc );

	//! Copy constructor
	MotionEntity( const MotionEntity& original );
     
public:

	//! Get number of URIs in Entity
	int NumberOfEntityURIs() const;

	//! Get i'th URI in Entity
	plmxml_api::String GetEntityURI( int i ) const;

	//! Add a URI to Entity array. Call ResolveEntityURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddEntityURI( const plmxml_api::String& u );

	//! Set i'th URI in Entity array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetEntityURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Entity URI. Does not resolve the URI.
	plmxml_api::Result GetEntityURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Entity array.
	plmxml_api::Result AddEntityURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Entity array to point to 'handle'.
	plmxml_api::Result SetEntityURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Entity points to.
	plmxml_api::Result ResolveEntityURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Entity array.
	plmxml_api::Result DeleteEntityURI( int i );

	//! Remove all URIs from Entity array.
	plmxml_api::Result DeleteEntityURIs( );
	
	//! Check if Entity is set
	plmxml_api::logical HasEntityURIs( ) const;

	//! Add Reference child element to this MotionEntity. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddReference();
     
	//! Add 'arg' as Reference child element to this MotionEntity.
	plmxml_api::Result AddReference( GDEReference *arg );

	//! Detach and delete all Reference child elements.
	void DeleteReferences();
     
	//! Get number of Reference child elements.
	int NumberOfReferences() const;
     
	//! Get i'th Reference child element.
	GDEReference *GetReference( int i ) const;
     
	//! Get all Reference child element as an array
	void GetReferences( plmxml_api::Array<GDEReference*> &array ) const;
	     
	//! Detach and delete i'th Reference child element
	void DeleteReference( int i );
     
	//! Detach and delete 'arg' if it's one of the Reference child elements
	void DeleteReference( GDEReference *arg );
 
// <PLMXML_UserCode type="functionHeaderMotionEntity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MOTION60_API plmxml_api::plmxmlClass plmxmlClassMotionEntity;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
