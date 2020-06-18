/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.27924 24/03/2016 10:22:51
// 
// Schema:	PLMXMLContentManagementSchema.xsd
// Data:	2010-08-31
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_CM60_H__
#define __PLMXML_CM60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_CM60_EXPORTS
#define PLMXML_CM60_API __declspec(dllexport)
#else
#define PLMXML_CM60_API __declspec(dllimport)
#endif
#else
#define PLMXML_CM60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


#include <plmxml_pdm60.h>

#include <plmxml_classification60.h>

#include <plmxml_business60.h>
#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
#include <plmxml_business60.h>
#include <plmxml_pdm60.h>
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! TopicTyp class
/*!
\verbatim

      Used for organization of all data necessary to process and edit topics in
      Content Management.

      Attributes:

      prefix:           XML prefix to the tag identifying the start of the topic
                        of this type.
      uri:              The namespace URI for the prefix.
      systemUsage:      Value to identify if the object can be used by users or
                        only by the system processes and hidden from users.
      tagName:          The XML tag that identifies start of the topic of this
                        type.
      condition:        A condition that can be evaluated in determining the
                        TopicTyp.
      typeName:         Name for the topic type.
      validateExample:  Flag to indicate that the system should run a validation
                        of the example XML content against the schema for topics
                        of this type whenever the content is being saved into an
                        application.
      validateIncoming: Flag to indicate that the system should run a validation
                        of the XML content against the schema for topics of this
                        type whenever the content is being saved into an
                        application.
      validateOutgoing: Flag to indicate that the system should run a validation
                        of the XML content against the schema for topics of this
                        type whenever the content is being pulled from an
                        application for use in tools or other systems.
      className:        Type name for the TopicTyp.
      transferModeRef:  References a TransferMode for importing to or exporting
                        from an application.
      fileExtension:    The extension of the import file name.
      nonTopicClasses:  A list of non-topic type names, separated by comma.
      
\endverbatim
*/
class PLMXML_CM60_API TopicTyp : public AttribOwner
{
public:
     
    //! Default constructor
    TopicTyp( );
     
    //! Constructs a TopicTyp with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTyp( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTyp();

private:

	//! Assignment operator
	TopicTyp& operator=( const TopicTyp& iSrc );

	//! Copy constructor
	TopicTyp( const TopicTyp& original );
     
public:

	//! Get TypeName of this TopicTyp
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this TopicTyp
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get TransferMode URI as plmxml_api::String
	plmxml_api::String GetTransferModeURI() const;

	//! Set TransferMode URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTransferModeURI( const plmxml_api::String& );
	
	//! Get the handle of TransferMode URI. Does not resolve the URI.
	plmxml_api::Result GetTransferModeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TransferMode URI. URI string is unchanged.
	plmxml_api::Result SetTransferModeURI( const plmxml_api::Handle& );
	
	//! Resolve TransferMode URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTransferModeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TransferMode URI. Clears URI string and handle.
	plmxml_api::Result DeleteTransferModeURI();
	
	//! Check if TransferMode URI is set
	plmxml_api::logical HasTransferModeURI( ) const;
	

	//! Get ClassName of this TopicTyp
	plmxml_api::String GetClassName() const;

	//! Set ClassName of this TopicTyp
	plmxml_api::Result SetClassName( const plmxml_api::String &s );
	
	//! Check if ClassName is set
	plmxml_api::logical HasClassName( ) const;
	
	//! Unset ClassName
	plmxml_api::Result UnsetClassName( );

	//! Set ValidateIncoming
	plmxml_api::Result SetValidateIncoming( plmxml_api::logical arg );

	//! Get ValidateIncoming
	plmxml_api::logical GetValidateIncoming() const;

	//! Check if ValidateIncoming is set
	plmxml_api::logical HasValidateIncoming() const;

	//! Unset ValidateIncoming
	plmxml_api::Result UnsetValidateIncoming();

	//! Set ValidateExample
	plmxml_api::Result SetValidateExample( plmxml_api::logical arg );

	//! Get ValidateExample
	plmxml_api::logical GetValidateExample() const;

	//! Check if ValidateExample is set
	plmxml_api::logical HasValidateExample() const;

	//! Unset ValidateExample
	plmxml_api::Result UnsetValidateExample();

	//! Get Prefix of this TopicTyp
	plmxml_api::String GetPrefix() const;

	//! Set Prefix of this TopicTyp
	plmxml_api::Result SetPrefix( const plmxml_api::String &s );
	
	//! Check if Prefix is set
	plmxml_api::logical HasPrefix( ) const;
	
	//! Unset Prefix
	plmxml_api::Result UnsetPrefix( );

	//! Get Uri of this TopicTyp
	plmxml_api::String GetUri() const;

	//! Set Uri of this TopicTyp
	plmxml_api::Result SetUri( const plmxml_api::String &s );
	
	//! Check if Uri is set
	plmxml_api::logical HasUri( ) const;
	
	//! Unset Uri
	plmxml_api::Result UnsetUri( );

	//! Get TagName of this TopicTyp
	plmxml_api::String GetTagName() const;

	//! Set TagName of this TopicTyp
	plmxml_api::Result SetTagName( const plmxml_api::String &s );
	
	//! Check if TagName is set
	plmxml_api::logical HasTagName( ) const;
	
	//! Unset TagName
	plmxml_api::Result UnsetTagName( );

	//! Get FileExtension of this TopicTyp
	plmxml_api::String GetFileExtension() const;

	//! Set FileExtension of this TopicTyp
	plmxml_api::Result SetFileExtension( const plmxml_api::String &s );
	
	//! Check if FileExtension is set
	plmxml_api::logical HasFileExtension( ) const;
	
	//! Unset FileExtension
	plmxml_api::Result UnsetFileExtension( );

	//! Set ValidateOutgoing
	plmxml_api::Result SetValidateOutgoing( plmxml_api::logical arg );

	//! Get ValidateOutgoing
	plmxml_api::logical GetValidateOutgoing() const;

	//! Check if ValidateOutgoing is set
	plmxml_api::logical HasValidateOutgoing() const;

	//! Unset ValidateOutgoing
	plmxml_api::Result UnsetValidateOutgoing();

	//! Get NonTopicClasses of this TopicTyp
	plmxml_api::String GetNonTopicClasses() const;

	//! Set NonTopicClasses of this TopicTyp
	plmxml_api::Result SetNonTopicClasses( const plmxml_api::String &s );
	
	//! Check if NonTopicClasses is set
	plmxml_api::logical HasNonTopicClasses( ) const;
	
	//! Unset NonTopicClasses
	plmxml_api::Result UnsetNonTopicClasses( );

	//! Get Condition of this TopicTyp
	plmxml_api::String GetCondition() const;

	//! Set Condition of this TopicTyp
	plmxml_api::Result SetCondition( const plmxml_api::String &s );
	
	//! Check if Condition is set
	plmxml_api::logical HasCondition( ) const;
	
	//! Unset Condition
	plmxml_api::Result UnsetCondition( );

	//! Get SystemUsage of this TopicTyp
	plmxml_api::String GetSystemUsage() const;

	//! Set SystemUsage of this TopicTyp
	plmxml_api::Result SetSystemUsage( const plmxml_api::String &s );
	
	//! Check if SystemUsage is set
	plmxml_api::logical HasSystemUsage( ) const;
	
	//! Unset SystemUsage
	plmxml_api::Result UnsetSystemUsage( );
 
// <PLMXML_UserCode type="functionHeaderTopicTyp" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTyp;


////////////////////////////////////////////////////////////////////////////////////
//! PublicationTyp class
/*!
\verbatim

      Special TopicTyp which can only be for a root of a structure of TopicTyps.
      
\endverbatim
*/
class PLMXML_CM60_API PublicationTyp : public TopicTyp
{
public:
     
    //! Default constructor
    PublicationTyp( );
     
    //! Constructs a PublicationTyp with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PublicationTyp( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PublicationTyp();

private:

	//! Assignment operator
	PublicationTyp& operator=( const PublicationTyp& iSrc );

	//! Copy constructor
	PublicationTyp( const PublicationTyp& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPublicationTyp" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassPublicationTyp;


////////////////////////////////////////////////////////////////////////////////////
//! RefTopicTyp class
/*!
\verbatim

      Special TopicTyp with extra data used for building links and references to
      Topics.

      Attributes:

      fragmentTagNames: The XML tag in the content used to identify the
                        reference, string containing one or more types,
                        separated by comma.
      referenceType:    Type of reference.
      variant:          Variant to be applied when expanding the reference.
      
\endverbatim
*/
class PLMXML_CM60_API RefTopicTyp : public TopicTyp
{
public:
     
    //! Default constructor
    RefTopicTyp( );
     
    //! Constructs a RefTopicTyp with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    RefTopicTyp( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~RefTopicTyp();

private:

	//! Assignment operator
	RefTopicTyp& operator=( const RefTopicTyp& iSrc );

	//! Copy constructor
	RefTopicTyp( const RefTopicTyp& original );
     
public:

	//! Get Variant of this RefTopicTyp
	plmxml_api::String GetVariant() const;

	//! Set Variant of this RefTopicTyp
	plmxml_api::Result SetVariant( const plmxml_api::String &s );
	
	//! Check if Variant is set
	plmxml_api::logical HasVariant( ) const;
	
	//! Unset Variant
	plmxml_api::Result UnsetVariant( );

	//! Get ReferenceType of this RefTopicTyp
	plmxml_api::String GetReferenceType() const;

	//! Set ReferenceType of this RefTopicTyp
	plmxml_api::Result SetReferenceType( const plmxml_api::String &s );
	
	//! Check if ReferenceType is set
	plmxml_api::logical HasReferenceType( ) const;
	
	//! Unset ReferenceType
	plmxml_api::Result UnsetReferenceType( );

	//! Get FragmentTagNames of this RefTopicTyp
	plmxml_api::String GetFragmentTagNames() const;

	//! Set FragmentTagNames of this RefTopicTyp
	plmxml_api::Result SetFragmentTagNames( const plmxml_api::String &s );
	
	//! Check if FragmentTagNames is set
	plmxml_api::logical HasFragmentTagNames( ) const;
	
	//! Unset FragmentTagNames
	plmxml_api::Result UnsetFragmentTagNames( );
 
// <PLMXML_UserCode type="functionHeaderRefTopicTyp" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassRefTopicTyp;


////////////////////////////////////////////////////////////////////////////////////
//! TransformPolicy class
/*!
\verbatim

      Stores a table that can be used to attach content transformations or
      scripts to certain actions.

      Attributes:

      comment:          Administrator notes about the object.
      policyName:       Name for the Policy object.
      tableRefs:        References to rows in the transformation policy table.
      
\endverbatim
*/
class PLMXML_CM60_API TransformPolicy : public AttribOwner
{
public:
     
    //! Default constructor
    TransformPolicy( );
     
    //! Constructs a TransformPolicy with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TransformPolicy( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TransformPolicy();

private:

	//! Assignment operator
	TransformPolicy& operator=( const TransformPolicy& iSrc );

	//! Copy constructor
	TransformPolicy( const TransformPolicy& original );
     
public:

	//! Get Comment of this TransformPolicy
	plmxml_api::String GetComment() const;

	//! Set Comment of this TransformPolicy
	plmxml_api::Result SetComment( const plmxml_api::String &s );
	
	//! Check if Comment is set
	plmxml_api::logical HasComment( ) const;
	
	//! Unset Comment
	plmxml_api::Result UnsetComment( );

	//! Get number of URIs in Table
	int NumberOfTableURIs() const;

	//! Get i'th URI in Table
	plmxml_api::String GetTableURI( int i ) const;

	//! Add a URI to Table array. Call ResolveTableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTableURI( const plmxml_api::String& u );

	//! Set i'th URI in Table array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Table URI. Does not resolve the URI.
	plmxml_api::Result GetTableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Table array.
	plmxml_api::Result AddTableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Table array to point to 'handle'.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Table points to.
	plmxml_api::Result ResolveTableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Table array.
	plmxml_api::Result DeleteTableURI( int i );

	//! Remove all URIs from Table array.
	plmxml_api::Result DeleteTableURIs( );
	
	//! Check if Table is set
	plmxml_api::logical HasTableURIs( ) const;

	//! Get PolicyName of this TransformPolicy
	plmxml_api::String GetPolicyName() const;

	//! Set PolicyName of this TransformPolicy
	plmxml_api::Result SetPolicyName( const plmxml_api::String &s );
	
	//! Check if PolicyName is set
	plmxml_api::logical HasPolicyName( ) const;
	
	//! Unset PolicyName
	plmxml_api::Result UnsetPolicyName( );
 
// <PLMXML_UserCode type="functionHeaderTransformPolicy" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTransformPolicy;


////////////////////////////////////////////////////////////////////////////////////
//! StyleTyp class
/*!
\verbatim

      Used to organize style sheets for different tools which represent the same
      style or branding.

      Attributes:

      typeName:         Name of the style type.
      systemUsage:      Value to identify if the object can be used by users or
                        only by the system processes and hidden from users.
      
\endverbatim
*/
class PLMXML_CM60_API StyleTyp : public AttribOwner
{
public:
     
    //! Default constructor
    StyleTyp( );
     
    //! Constructs a StyleTyp with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StyleTyp( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StyleTyp();

private:

	//! Assignment operator
	StyleTyp& operator=( const StyleTyp& iSrc );

	//! Copy constructor
	StyleTyp( const StyleTyp& original );
     
public:

	//! Get TypeName of this StyleTyp
	plmxml_api::String GetTypeName() const;

	//! Set TypeName of this StyleTyp
	plmxml_api::Result SetTypeName( const plmxml_api::String &s );
	
	//! Check if TypeName is set
	plmxml_api::logical HasTypeName( ) const;
	
	//! Unset TypeName
	plmxml_api::Result UnsetTypeName( );

	//! Get SystemUsage of this StyleTyp
	plmxml_api::String GetSystemUsage() const;

	//! Set SystemUsage of this StyleTyp
	plmxml_api::Result SetSystemUsage( const plmxml_api::String &s );
	
	//! Check if SystemUsage is set
	plmxml_api::logical HasSystemUsage( ) const;
	
	//! Unset SystemUsage
	plmxml_api::Result UnsetSystemUsage( );
 
// <PLMXML_UserCode type="functionHeaderStyleTyp" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassStyleTyp;


////////////////////////////////////////////////////////////////////////////////////
//! CMTool class
/*!
\verbatim

      The abstract class bundles all classes used for accessing tools from the
      Content Management client or server.

      Attributes:

      command:          The command string for running external executables,
                        with substitutions for the content file, the schema if
                        needed, the style sheet if needed and other command
                        options depending on the tool.
      systemUsage:      Value to identify if the object can be used by users or
                        only by the system processes and hidden from users.
      path:             The default install path for the tool.
      graphicPriorityRef: Reference to the GraphicPriorityList object to resolve
                        usage of graphics for the tool.
      downloadGraphics: Specifies if graphics should be downloaded for use by
                        the tool.
      downloadSchema:   Specifies if schema files should be downloaded for use
                        by the tool.
      downloadStyleSheet: Specifies if style sheets should be downloaded for use
                        by the tool.
      processInstruction: Used to pass something to the publish process that is
                        used but is not part of the input content.
      activation:       The client java class used to invoke to launch the tool.
      
\endverbatim
*/
class PLMXML_CM60_API CMTool : public AttribOwner
{
public:
     
    //! Default constructor
    CMTool( );
     
    //! Constructs a CMTool with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CMTool( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CMTool();

private:

	//! Assignment operator
	CMTool& operator=( const CMTool& iSrc );

	//! Copy constructor
	CMTool( const CMTool& original );
     
public:

	//! Set DownloadStyleSheet
	plmxml_api::Result SetDownloadStyleSheet( plmxml_api::logical arg );

	//! Get DownloadStyleSheet
	plmxml_api::logical GetDownloadStyleSheet() const;

	//! Check if DownloadStyleSheet is set
	plmxml_api::logical HasDownloadStyleSheet() const;

	//! Unset DownloadStyleSheet
	plmxml_api::Result UnsetDownloadStyleSheet();

	//! Get Path of this CMTool
	plmxml_api::String GetPath() const;

	//! Set Path of this CMTool
	plmxml_api::Result SetPath( const plmxml_api::String &s );
	
	//! Check if Path is set
	plmxml_api::logical HasPath( ) const;
	
	//! Unset Path
	plmxml_api::Result UnsetPath( );

	//! Set DownloadGraphics
	plmxml_api::Result SetDownloadGraphics( plmxml_api::logical arg );

	//! Get DownloadGraphics
	plmxml_api::logical GetDownloadGraphics() const;

	//! Check if DownloadGraphics is set
	plmxml_api::logical HasDownloadGraphics() const;

	//! Unset DownloadGraphics
	plmxml_api::Result UnsetDownloadGraphics();

	//! Get SystemUsage of this CMTool
	plmxml_api::String GetSystemUsage() const;

	//! Set SystemUsage of this CMTool
	plmxml_api::Result SetSystemUsage( const plmxml_api::String &s );
	
	//! Check if SystemUsage is set
	plmxml_api::logical HasSystemUsage( ) const;
	
	//! Unset SystemUsage
	plmxml_api::Result UnsetSystemUsage( );

	//! Get ProcessInstruction of this CMTool
	plmxml_api::String GetProcessInstruction() const;

	//! Set ProcessInstruction of this CMTool
	plmxml_api::Result SetProcessInstruction( const plmxml_api::String &s );
	
	//! Check if ProcessInstruction is set
	plmxml_api::logical HasProcessInstruction( ) const;
	
	//! Unset ProcessInstruction
	plmxml_api::Result UnsetProcessInstruction( );

	//! Get Command of this CMTool
	plmxml_api::String GetCommand() const;

	//! Set Command of this CMTool
	plmxml_api::Result SetCommand( const plmxml_api::String &s );
	
	//! Check if Command is set
	plmxml_api::logical HasCommand( ) const;
	
	//! Unset Command
	plmxml_api::Result UnsetCommand( );

	//! Set DownloadSchema
	plmxml_api::Result SetDownloadSchema( plmxml_api::logical arg );

	//! Get DownloadSchema
	plmxml_api::logical GetDownloadSchema() const;

	//! Check if DownloadSchema is set
	plmxml_api::logical HasDownloadSchema() const;

	//! Unset DownloadSchema
	plmxml_api::Result UnsetDownloadSchema();

	//! Get GraphicPriority URI as plmxml_api::String
	plmxml_api::String GetGraphicPriorityURI() const;

	//! Set GraphicPriority URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetGraphicPriorityURI( const plmxml_api::String& );
	
	//! Get the handle of GraphicPriority URI. Does not resolve the URI.
	plmxml_api::Result GetGraphicPriorityURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of GraphicPriority URI. URI string is unchanged.
	plmxml_api::Result SetGraphicPriorityURI( const plmxml_api::Handle& );
	
	//! Resolve GraphicPriority URI and return an object (handle) it points to.
	plmxml_api::Result ResolveGraphicPriorityURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset GraphicPriority URI. Clears URI string and handle.
	plmxml_api::Result DeleteGraphicPriorityURI();
	
	//! Check if GraphicPriority URI is set
	plmxml_api::logical HasGraphicPriorityURI( ) const;
	

	//! Get Activation of this CMTool
	plmxml_api::String GetActivation() const;

	//! Set Activation of this CMTool
	plmxml_api::Result SetActivation( const plmxml_api::String &s );
	
	//! Check if Activation is set
	plmxml_api::logical HasActivation( ) const;
	
	//! Unset Activation
	plmxml_api::Result UnsetActivation( );
 
// <PLMXML_UserCode type="functionHeaderCMTool" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassCMTool;


////////////////////////////////////////////////////////////////////////////////////
//! CompareTool class
/*!
\verbatim

      Stores information necessary to launch a compare application.

      Attributes:

      outputState:      The Compare tool output usage.
      
\endverbatim
*/
class PLMXML_CM60_API CompareTool : public CMTool
{
public:
     
    //! Default constructor
    CompareTool( );
     
    //! Constructs a CompareTool with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CompareTool( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CompareTool();

private:

	//! Assignment operator
	CompareTool& operator=( const CompareTool& iSrc );

	//! Copy constructor
	CompareTool( const CompareTool& original );
     
public:

	//! Get OutputState of this CompareTool
	plmxml_api::String GetOutputState() const;

	//! Set OutputState of this CompareTool
	plmxml_api::Result SetOutputState( const plmxml_api::String &s );
	
	//! Check if OutputState is set
	plmxml_api::logical HasOutputState( ) const;
	
	//! Unset OutputState
	plmxml_api::Result UnsetOutputState( );
 
// <PLMXML_UserCode type="functionHeaderCompareTool" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassCompareTool;


////////////////////////////////////////////////////////////////////////////////////
//! EditTool class
/*!
\verbatim

      Stores information necessary to launch an editing application.
      
\endverbatim
*/
class PLMXML_CM60_API EditTool : public CMTool
{
public:
     
    //! Default constructor
    EditTool( );
     
    //! Constructs a EditTool with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    EditTool( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~EditTool();

private:

	//! Assignment operator
	EditTool& operator=( const EditTool& iSrc );

	//! Copy constructor
	EditTool( const EditTool& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderEditTool" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassEditTool;


////////////////////////////////////////////////////////////////////////////////////
//! PublishTool class
/*!
\verbatim

      Stores information necessary to launch internal or external publishing
      engines.

      Attributes:

      local:            Flag to indicate the tool is a client side tool rather
                        than a server tool.
      numberOfInstances: Record the number of licenses for a specific tool.
      
\endverbatim
*/
class PLMXML_CM60_API PublishTool : public CMTool
{
public:
     
    //! Default constructor
    PublishTool( );
     
    //! Constructs a PublishTool with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PublishTool( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PublishTool();

private:

	//! Assignment operator
	PublishTool& operator=( const PublishTool& iSrc );

	//! Copy constructor
	PublishTool( const PublishTool& original );
     
public:

	//! Set NumberOfInstances
	plmxml_api::Result SetNumberOfInstances( int arg );
     
	//! Get NumberOfInstances
	int GetNumberOfInstances() const;
     
	//! Check if NumberOfInstances is set
	plmxml_api::logical HasNumberOfInstances() const;
     
	//! Unset NumberOfInstances
	plmxml_api::Result UnsetNumberOfInstances();

	//! Set Local
	plmxml_api::Result SetLocal( plmxml_api::logical arg );

	//! Get Local
	plmxml_api::logical GetLocal() const;

	//! Check if Local is set
	plmxml_api::logical HasLocal() const;

	//! Unset Local
	plmxml_api::Result UnsetLocal();
 
// <PLMXML_UserCode type="functionHeaderPublishTool" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassPublishTool;


////////////////////////////////////////////////////////////////////////////////////
//! TransformTool class
/*!
\verbatim

      Stores information necessary for supporting the Word document import
      implementation, which needs to run a transformation before importing.

      Attributes:

      outputState:      Describes the file to use from the results of the
                        transformation tool run.
      
\endverbatim
*/
class PLMXML_CM60_API TransformTool : public CMTool
{
public:
     
    //! Default constructor
    TransformTool( );
     
    //! Constructs a TransformTool with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TransformTool( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TransformTool();

private:

	//! Assignment operator
	TransformTool& operator=( const TransformTool& iSrc );

	//! Copy constructor
	TransformTool( const TransformTool& original );
     
public:

	//! Get OutputState of this TransformTool
	plmxml_api::String GetOutputState() const;

	//! Set OutputState of this TransformTool
	plmxml_api::Result SetOutputState( const plmxml_api::String &s );
	
	//! Check if OutputState is set
	plmxml_api::logical HasOutputState( ) const;
	
	//! Unset OutputState
	plmxml_api::Result UnsetOutputState( );
 
// <PLMXML_UserCode type="functionHeaderTransformTool" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTransformTool;


////////////////////////////////////////////////////////////////////////////////////
//! ViewTool class
/*!
\verbatim

      Stores information necessary to launch a viewing application.

      Attributes:

      contentType:      The type of content that can be viewed by the view
                        tool.
      
\endverbatim
*/
class PLMXML_CM60_API ViewTool : public CMTool
{
public:
     
    //! Default constructor
    ViewTool( );
     
    //! Constructs a ViewTool with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ViewTool( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ViewTool();

private:

	//! Assignment operator
	ViewTool& operator=( const ViewTool& iSrc );

	//! Copy constructor
	ViewTool( const ViewTool& original );
     
public:

	//! Get ContentType of this ViewTool
	plmxml_api::String GetContentType() const;

	//! Set ContentType of this ViewTool
	plmxml_api::Result SetContentType( const plmxml_api::String &s );
	
	//! Check if ContentType is set
	plmxml_api::logical HasContentType( ) const;
	
	//! Unset ContentType
	plmxml_api::Result UnsetContentType( );
 
// <PLMXML_UserCode type="functionHeaderViewTool" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassViewTool;


////////////////////////////////////////////////////////////////////////////////////
//! XMLAttributeMap class
/*!
\verbatim

      Is used to control the moving of meta data from contents to objects and
      vice versa.

      Attributes:

      comment:          Administrator notes about the object.
      namespaceTableRefs: Reference to the rows of the Namespaces table.
      mapName:          Name for the Attribute Map.
      tableRefs:        References to the rows of the XML Attribute Map table.
      
\endverbatim
*/
class PLMXML_CM60_API XMLAttributeMap : public AttribOwner
{
public:
     
    //! Default constructor
    XMLAttributeMap( );
     
    //! Constructs a XMLAttributeMap with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    XMLAttributeMap( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~XMLAttributeMap();

private:

	//! Assignment operator
	XMLAttributeMap& operator=( const XMLAttributeMap& iSrc );

	//! Copy constructor
	XMLAttributeMap( const XMLAttributeMap& original );
     
public:

	//! Get Comment of this XMLAttributeMap
	plmxml_api::String GetComment() const;

	//! Set Comment of this XMLAttributeMap
	plmxml_api::Result SetComment( const plmxml_api::String &s );
	
	//! Check if Comment is set
	plmxml_api::logical HasComment( ) const;
	
	//! Unset Comment
	plmxml_api::Result UnsetComment( );

	//! Get MapName of this XMLAttributeMap
	plmxml_api::String GetMapName() const;

	//! Set MapName of this XMLAttributeMap
	plmxml_api::Result SetMapName( const plmxml_api::String &s );
	
	//! Check if MapName is set
	plmxml_api::logical HasMapName( ) const;
	
	//! Unset MapName
	plmxml_api::Result UnsetMapName( );

	//! Get number of URIs in NamespaceTable
	int NumberOfNamespaceTableURIs() const;

	//! Get i'th URI in NamespaceTable
	plmxml_api::String GetNamespaceTableURI( int i ) const;

	//! Add a URI to NamespaceTable array. Call ResolveNamespaceTableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddNamespaceTableURI( const plmxml_api::String& u );

	//! Set i'th URI in NamespaceTable array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetNamespaceTableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of NamespaceTable URI. Does not resolve the URI.
	plmxml_api::Result GetNamespaceTableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to NamespaceTable array.
	plmxml_api::Result AddNamespaceTableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in NamespaceTable array to point to 'handle'.
	plmxml_api::Result SetNamespaceTableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in NamespaceTable points to.
	plmxml_api::Result ResolveNamespaceTableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from NamespaceTable array.
	plmxml_api::Result DeleteNamespaceTableURI( int i );

	//! Remove all URIs from NamespaceTable array.
	plmxml_api::Result DeleteNamespaceTableURIs( );
	
	//! Check if NamespaceTable is set
	plmxml_api::logical HasNamespaceTableURIs( ) const;

	//! Get number of URIs in Table
	int NumberOfTableURIs() const;

	//! Get i'th URI in Table
	plmxml_api::String GetTableURI( int i ) const;

	//! Add a URI to Table array. Call ResolveTableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTableURI( const plmxml_api::String& u );

	//! Set i'th URI in Table array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Table URI. Does not resolve the URI.
	plmxml_api::Result GetTableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Table array.
	plmxml_api::Result AddTableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Table array to point to 'handle'.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Table points to.
	plmxml_api::Result ResolveTableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Table array.
	plmxml_api::Result DeleteTableURI( int i );

	//! Remove all URIs from Table array.
	plmxml_api::Result DeleteTableURIs( );
	
	//! Check if Table is set
	plmxml_api::logical HasTableURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderXMLAttributeMap" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassXMLAttributeMap;


////////////////////////////////////////////////////////////////////////////////////
//! GraphicAttributeMap class
/*!
\verbatim

      Is used for graphic properties generation during the import of graphics
      into a Content Management system.

      Attributes:

      comment:          Administrator notes about the object.
      tableRefs:        References to the rows in the graphic attribute mapping
                        table.
      
\endverbatim
*/
class PLMXML_CM60_API GraphicAttributeMap : public AttribOwner
{
public:
     
    //! Default constructor
    GraphicAttributeMap( );
     
    //! Constructs a GraphicAttributeMap with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GraphicAttributeMap( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GraphicAttributeMap();

private:

	//! Assignment operator
	GraphicAttributeMap& operator=( const GraphicAttributeMap& iSrc );

	//! Copy constructor
	GraphicAttributeMap( const GraphicAttributeMap& original );
     
public:

	//! Get Comment of this GraphicAttributeMap
	plmxml_api::String GetComment() const;

	//! Set Comment of this GraphicAttributeMap
	plmxml_api::Result SetComment( const plmxml_api::String &s );
	
	//! Check if Comment is set
	plmxml_api::logical HasComment( ) const;
	
	//! Unset Comment
	plmxml_api::Result UnsetComment( );

	//! Get number of URIs in Table
	int NumberOfTableURIs() const;

	//! Get i'th URI in Table
	plmxml_api::String GetTableURI( int i ) const;

	//! Add a URI to Table array. Call ResolveTableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTableURI( const plmxml_api::String& u );

	//! Set i'th URI in Table array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Table URI. Does not resolve the URI.
	plmxml_api::Result GetTableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Table array.
	plmxml_api::Result AddTableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Table array to point to 'handle'.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Table points to.
	plmxml_api::Result ResolveTableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Table array.
	plmxml_api::Result DeleteTableURI( int i );

	//! Remove all URIs from Table array.
	plmxml_api::Result DeleteTableURIs( );
	
	//! Check if Table is set
	plmxml_api::logical HasTableURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderGraphicAttributeMap" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassGraphicAttributeMap;


////////////////////////////////////////////////////////////////////////////////////
//! GraphicPriorityList class
/*!
\verbatim

      Stores a list used to control the order in which graphic properties are
      selected for a Graphic during content processing.

      Attributes:

      comment:          Administrator notes about the object.
      usages:           Priority list of usages for a graphic, string containing
                        one or more usage, separated by comma.
      maxOptions:       For publishing to media where more than one graphic file
                        should be made available.
      priorityName:     Name for the Graphic Priority List.
      
\endverbatim
*/
class PLMXML_CM60_API GraphicPriorityList : public AttribOwner
{
public:
     
    //! Default constructor
    GraphicPriorityList( );
     
    //! Constructs a GraphicPriorityList with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GraphicPriorityList( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GraphicPriorityList();

private:

	//! Assignment operator
	GraphicPriorityList& operator=( const GraphicPriorityList& iSrc );

	//! Copy constructor
	GraphicPriorityList( const GraphicPriorityList& original );
     
public:

	//! Get Usages of this GraphicPriorityList
	plmxml_api::String GetUsages() const;

	//! Set Usages of this GraphicPriorityList
	plmxml_api::Result SetUsages( const plmxml_api::String &s );
	
	//! Check if Usages is set
	plmxml_api::logical HasUsages( ) const;
	
	//! Unset Usages
	plmxml_api::Result UnsetUsages( );

	//! Set MaxOptions
	plmxml_api::Result SetMaxOptions( int arg );
     
	//! Get MaxOptions
	int GetMaxOptions() const;
     
	//! Check if MaxOptions is set
	plmxml_api::logical HasMaxOptions() const;
     
	//! Unset MaxOptions
	plmxml_api::Result UnsetMaxOptions();

	//! Get Comment of this GraphicPriorityList
	plmxml_api::String GetComment() const;

	//! Set Comment of this GraphicPriorityList
	plmxml_api::Result SetComment( const plmxml_api::String &s );
	
	//! Check if Comment is set
	plmxml_api::logical HasComment( ) const;
	
	//! Unset Comment
	plmxml_api::Result UnsetComment( );

	//! Get PriorityName of this GraphicPriorityList
	plmxml_api::String GetPriorityName() const;

	//! Set PriorityName of this GraphicPriorityList
	plmxml_api::Result SetPriorityName( const plmxml_api::String &s );
	
	//! Check if PriorityName is set
	plmxml_api::logical HasPriorityName( ) const;
	
	//! Unset PriorityName
	plmxml_api::Result UnsetPriorityName( );
 
// <PLMXML_UserCode type="functionHeaderGraphicPriorityList" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassGraphicPriorityList;


////////////////////////////////////////////////////////////////////////////////////
//! Language class
/*!
\verbatim

      Stores data for a language available for translation of document or topic
      content.

      Attributes:

      comment:          Administrator notes about the object.
      publishFont:      For any publish language, there are different fonts used
                        for the output, default for publishing.
      countryCode:      The ISO 639-1 standard country code for the language.
      languageCode:     The ISO 639-1 standard code for the language.
      languageDescription: Any description of the language.
      fileInitials:     The initials for filenames where the language is
                        embedded into the filename.
      languageName:     Name of the language.
      fallbackRef:      References a fallback language to use if a translation
                        to this language does not exist.
      
\endverbatim
*/
class PLMXML_CM60_API Language : public AttribOwner
{
public:
     
    //! Default constructor
    Language( );
     
    //! Constructs a Language with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Language( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Language();

private:

	//! Assignment operator
	Language& operator=( const Language& iSrc );

	//! Copy constructor
	Language( const Language& original );
     
public:

	//! Get FileInitials of this Language
	plmxml_api::String GetFileInitials() const;

	//! Set FileInitials of this Language
	plmxml_api::Result SetFileInitials( const plmxml_api::String &s );
	
	//! Check if FileInitials is set
	plmxml_api::logical HasFileInitials( ) const;
	
	//! Unset FileInitials
	plmxml_api::Result UnsetFileInitials( );

	//! Get LanguageDescription of this Language
	plmxml_api::String GetLanguageDescription() const;

	//! Set LanguageDescription of this Language
	plmxml_api::Result SetLanguageDescription( const plmxml_api::String &s );
	
	//! Check if LanguageDescription is set
	plmxml_api::logical HasLanguageDescription( ) const;
	
	//! Unset LanguageDescription
	plmxml_api::Result UnsetLanguageDescription( );

	//! Get LanguageName of this Language
	plmxml_api::String GetLanguageName() const;

	//! Set LanguageName of this Language
	plmxml_api::Result SetLanguageName( const plmxml_api::String &s );
	
	//! Check if LanguageName is set
	plmxml_api::logical HasLanguageName( ) const;
	
	//! Unset LanguageName
	plmxml_api::Result UnsetLanguageName( );

	//! Get Comment of this Language
	plmxml_api::String GetComment() const;

	//! Set Comment of this Language
	plmxml_api::Result SetComment( const plmxml_api::String &s );
	
	//! Check if Comment is set
	plmxml_api::logical HasComment( ) const;
	
	//! Unset Comment
	plmxml_api::Result UnsetComment( );

	//! Get LanguageCode of this Language
	plmxml_api::String GetLanguageCode() const;

	//! Set LanguageCode of this Language
	plmxml_api::Result SetLanguageCode( const plmxml_api::String &s );
	
	//! Check if LanguageCode is set
	plmxml_api::logical HasLanguageCode( ) const;
	
	//! Unset LanguageCode
	plmxml_api::Result UnsetLanguageCode( );

	//! Get CountryCode of this Language
	plmxml_api::String GetCountryCode() const;

	//! Set CountryCode of this Language
	plmxml_api::Result SetCountryCode( const plmxml_api::String &s );
	
	//! Check if CountryCode is set
	plmxml_api::logical HasCountryCode( ) const;
	
	//! Unset CountryCode
	plmxml_api::Result UnsetCountryCode( );

	//! Get PublishFont of this Language
	plmxml_api::String GetPublishFont() const;

	//! Set PublishFont of this Language
	plmxml_api::Result SetPublishFont( const plmxml_api::String &s );
	
	//! Check if PublishFont is set
	plmxml_api::logical HasPublishFont( ) const;
	
	//! Unset PublishFont
	plmxml_api::Result UnsetPublishFont( );

	//! Get Fallback URI as plmxml_api::String
	plmxml_api::String GetFallbackURI() const;

	//! Set Fallback URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetFallbackURI( const plmxml_api::String& );
	
	//! Get the handle of Fallback URI. Does not resolve the URI.
	plmxml_api::Result GetFallbackURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Fallback URI. URI string is unchanged.
	plmxml_api::Result SetFallbackURI( const plmxml_api::Handle& );
	
	//! Resolve Fallback URI and return an object (handle) it points to.
	plmxml_api::Result ResolveFallbackURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Fallback URI. Clears URI string and handle.
	plmxml_api::Result DeleteFallbackURI();
	
	//! Check if Fallback URI is set
	plmxml_api::logical HasFallbackURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLanguage" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassLanguage;


////////////////////////////////////////////////////////////////////////////////////
//! DITAValueFilter class
/*!
\verbatim

      The DITA value filter is selected at the time of publish.

      Attributes:

      filterName:       Name of the filter.
      tableRefs:        References to the rows of the filter table for this
                        filter.
      
\endverbatim
*/
class PLMXML_CM60_API DITAValueFilter : public AttribOwner
{
public:
     
    //! Default constructor
    DITAValueFilter( );
     
    //! Constructs a DITAValueFilter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DITAValueFilter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DITAValueFilter();

private:

	//! Assignment operator
	DITAValueFilter& operator=( const DITAValueFilter& iSrc );

	//! Copy constructor
	DITAValueFilter( const DITAValueFilter& original );
     
public:

	//! Get FilterName of this DITAValueFilter
	plmxml_api::String GetFilterName() const;

	//! Set FilterName of this DITAValueFilter
	plmxml_api::Result SetFilterName( const plmxml_api::String &s );
	
	//! Check if FilterName is set
	plmxml_api::logical HasFilterName( ) const;
	
	//! Unset FilterName
	plmxml_api::Result UnsetFilterName( );

	//! Get number of URIs in Table
	int NumberOfTableURIs() const;

	//! Get i'th URI in Table
	plmxml_api::String GetTableURI( int i ) const;

	//! Add a URI to Table array. Call ResolveTableURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddTableURI( const plmxml_api::String& u );

	//! Set i'th URI in Table array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Table URI. Does not resolve the URI.
	plmxml_api::Result GetTableURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Table array.
	plmxml_api::Result AddTableURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Table array to point to 'handle'.
	plmxml_api::Result SetTableURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Table points to.
	plmxml_api::Result ResolveTableURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Table array.
	plmxml_api::Result DeleteTableURI( int i );

	//! Remove all URIs from Table array.
	plmxml_api::Result DeleteTableURIs( );
	
	//! Check if Table is set
	plmxml_api::logical HasTableURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderDITAValueFilter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassDITAValueFilter;


////////////////////////////////////////////////////////////////////////////////////
//! ExtEntAdmin class
/*!
\verbatim

      External entity administration class bundles all the supporting data
      classes, which are primarily identified by a public ID attribute.
      
\endverbatim
*/
class PLMXML_CM60_API ExtEntAdmin : public Structure
{
public:
     
    //! Default constructor
    ExtEntAdmin( );
     
    //! Constructs a ExtEntAdmin with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExtEntAdmin( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExtEntAdmin();

private:

	//! Assignment operator
	ExtEntAdmin& operator=( const ExtEntAdmin& iSrc );

	//! Copy constructor
	ExtEntAdmin( const ExtEntAdmin& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderExtEntAdmin" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassExtEntAdmin;


////////////////////////////////////////////////////////////////////////////////////
//! CMSchema class
/*!
\verbatim

      Is used to store the contents of supporting data necessary to process XML
      or SGML.
      
\endverbatim
*/
class PLMXML_CM60_API CMSchema : public ExtEntAdmin
{
public:
     
    //! Default constructor
    CMSchema( );
     
    //! Constructs a CMSchema with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CMSchema( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CMSchema();

private:

	//! Assignment operator
	CMSchema& operator=( const CMSchema& iSrc );

	//! Copy constructor
	CMSchema( const CMSchema& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderCMSchema" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassCMSchema;


////////////////////////////////////////////////////////////////////////////////////
//! XMLSchema class
/*!
\verbatim

      Stores some additional data necessary to work with Schemas that use the
      XML Schema standard.
      
\endverbatim
*/
class PLMXML_CM60_API XMLSchema : public CMSchema
{
public:
     
    //! Default constructor
    XMLSchema( );
     
    //! Constructs a XMLSchema with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    XMLSchema( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~XMLSchema();

private:

	//! Assignment operator
	XMLSchema& operator=( const XMLSchema& iSrc );

	//! Copy constructor
	XMLSchema( const XMLSchema& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderXMLSchema" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassXMLSchema;


////////////////////////////////////////////////////////////////////////////////////
//! StyleSheet class
/*!
\verbatim

      Stores data used for transformation of content.
      
\endverbatim
*/
class PLMXML_CM60_API StyleSheet : public ExtEntAdmin
{
public:
     
    //! Default constructor
    StyleSheet( );
     
    //! Constructs a StyleSheet with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StyleSheet( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StyleSheet();

private:

	//! Assignment operator
	StyleSheet& operator=( const StyleSheet& iSrc );

	//! Copy constructor
	StyleSheet( const StyleSheet& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderStyleSheet" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassStyleSheet;


////////////////////////////////////////////////////////////////////////////////////
//! Procedure class
/*!
\verbatim

      Stores scripts in a scripting language that are used for content
      transformations or to dynamically extend business functions in Content
      Management.
      
\endverbatim
*/
class PLMXML_CM60_API Procedure : public Structure
{
public:
     
    //! Default constructor
    Procedure( );
     
    //! Constructs a Procedure with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Procedure( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Procedure();

private:

	//! Assignment operator
	Procedure& operator=( const Procedure& iSrc );

	//! Copy constructor
	Procedure( const Procedure& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcedure" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassProcedure;


////////////////////////////////////////////////////////////////////////////////////
//! TopicTypGroup class
/*!
\verbatim

      Topic Type Group.

      Attributes:

      groupName:        Name for the Topic Type Group, used for users setting
                        client preference for group of topics that they want to
                        use.
      
\endverbatim
*/
class PLMXML_CM60_API TopicTypGroup : public Folder
{
public:
     
    //! Default constructor
    TopicTypGroup( );
     
    //! Constructs a TopicTypGroup with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTypGroup( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTypGroup();

private:

	//! Assignment operator
	TopicTypGroup& operator=( const TopicTypGroup& iSrc );

	//! Copy constructor
	TopicTypGroup( const TopicTypGroup& original );
     
public:

	//! Get GroupName of this TopicTypGroup
	plmxml_api::String GetGroupName() const;

	//! Set GroupName of this TopicTypGroup
	plmxml_api::Result SetGroupName( const plmxml_api::String &s );
	
	//! Check if GroupName is set
	plmxml_api::logical HasGroupName( ) const;
	
	//! Unset GroupName
	plmxml_api::Result UnsetGroupName( );
 
// <PLMXML_UserCode type="functionHeaderTopicTypGroup" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTypGroup;


////////////////////////////////////////////////////////////////////////////////////
//! ExtEntAdminRevision class
/*!
\verbatim

      This class is the Revision of the external entity administration class.

      Attributes:

      publicId:         The XML string used inside the file to identify the
                        content for tools.
      systemId:         The filename for the content.
      
\endverbatim
*/
class PLMXML_CM60_API ExtEntAdminRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ExtEntAdminRevision( );
     
    //! Constructs a ExtEntAdminRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ExtEntAdminRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ExtEntAdminRevision();

private:

	//! Assignment operator
	ExtEntAdminRevision& operator=( const ExtEntAdminRevision& iSrc );

	//! Copy constructor
	ExtEntAdminRevision( const ExtEntAdminRevision& original );
     
public:

	//! Get PublicId of this ExtEntAdminRevision
	plmxml_api::String GetPublicId() const;

	//! Set PublicId of this ExtEntAdminRevision
	plmxml_api::Result SetPublicId( const plmxml_api::String &s );
	
	//! Check if PublicId is set
	plmxml_api::logical HasPublicId( ) const;
	
	//! Unset PublicId
	plmxml_api::Result UnsetPublicId( );

	//! Get SystemId of this ExtEntAdminRevision
	plmxml_api::String GetSystemId() const;

	//! Set SystemId of this ExtEntAdminRevision
	plmxml_api::Result SetSystemId( const plmxml_api::String &s );
	
	//! Check if SystemId is set
	plmxml_api::logical HasSystemId( ) const;
	
	//! Unset SystemId
	plmxml_api::Result UnsetSystemId( );
 
// <PLMXML_UserCode type="functionHeaderExtEntAdminRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassExtEntAdminRevision;


////////////////////////////////////////////////////////////////////////////////////
//! CMSchemaRevision class
/*!
\verbatim

      This is the Revision Schema.

      Attributes:

      contentSize:      Disk size needed for the content.
      schemaType:       Type of schema.
      
\endverbatim
*/
class PLMXML_CM60_API CMSchemaRevision : public ExtEntAdminRevision
{
public:
     
    //! Default constructor
    CMSchemaRevision( );
     
    //! Constructs a CMSchemaRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CMSchemaRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CMSchemaRevision();

private:

	//! Assignment operator
	CMSchemaRevision& operator=( const CMSchemaRevision& iSrc );

	//! Copy constructor
	CMSchemaRevision( const CMSchemaRevision& original );
     
public:

	//! Get SchemaType of this CMSchemaRevision
	plmxml_api::String GetSchemaType() const;

	//! Set SchemaType of this CMSchemaRevision
	plmxml_api::Result SetSchemaType( const plmxml_api::String &s );
	
	//! Check if SchemaType is set
	plmxml_api::logical HasSchemaType( ) const;
	
	//! Unset SchemaType
	plmxml_api::Result UnsetSchemaType( );

	//! Set ContentSize
	plmxml_api::Result SetContentSize( int arg );
     
	//! Get ContentSize
	int GetContentSize() const;
     
	//! Check if ContentSize is set
	plmxml_api::logical HasContentSize() const;
     
	//! Unset ContentSize
	plmxml_api::Result UnsetContentSize();
 
// <PLMXML_UserCode type="functionHeaderCMSchemaRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassCMSchemaRevision;


////////////////////////////////////////////////////////////////////////////////////
//! XMLSchemaRevision class
/*!
\verbatim

      This is the Revision for XMLSchema.

      Attributes:

      prefix:           Default XML prefix to the tags identified in the schema.
      location:         Similar to the namespace URI, for the schema public ID
                        that corresponds to the prefix.
      
\endverbatim
*/
class PLMXML_CM60_API XMLSchemaRevision : public CMSchemaRevision
{
public:
     
    //! Default constructor
    XMLSchemaRevision( );
     
    //! Constructs a XMLSchemaRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    XMLSchemaRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~XMLSchemaRevision();

private:

	//! Assignment operator
	XMLSchemaRevision& operator=( const XMLSchemaRevision& iSrc );

	//! Copy constructor
	XMLSchemaRevision( const XMLSchemaRevision& original );
     
public:

	//! Get Location of this XMLSchemaRevision
	plmxml_api::String GetLocation() const;

	//! Set Location of this XMLSchemaRevision
	plmxml_api::Result SetLocation( const plmxml_api::String &s );
	
	//! Check if Location is set
	plmxml_api::logical HasLocation( ) const;
	
	//! Unset Location
	plmxml_api::Result UnsetLocation( );

	//! Get Prefix of this XMLSchemaRevision
	plmxml_api::String GetPrefix() const;

	//! Set Prefix of this XMLSchemaRevision
	plmxml_api::Result SetPrefix( const plmxml_api::String &s );
	
	//! Check if Prefix is set
	plmxml_api::logical HasPrefix( ) const;
	
	//! Unset Prefix
	plmxml_api::Result UnsetPrefix( );
 
// <PLMXML_UserCode type="functionHeaderXMLSchemaRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassXMLSchemaRevision;


////////////////////////////////////////////////////////////////////////////////////
//! StyleSheetRevision class
/*!
\verbatim

      Revision of StyleSheet.

      Attributes:

      contentSize:      Disk size needed for the content.
      mainFile:         The name of the file in the zip to start with.
      contentType:      Content type that the style sheet is intended for.
      styleSheetType:   Style sheet type.
      target:           The ANT target parameter for publishing tools driven by
                        ANT processing.
      
\endverbatim
*/
class PLMXML_CM60_API StyleSheetRevision : public ExtEntAdminRevision
{
public:
     
    //! Default constructor
    StyleSheetRevision( );
     
    //! Constructs a StyleSheetRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StyleSheetRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StyleSheetRevision();

private:

	//! Assignment operator
	StyleSheetRevision& operator=( const StyleSheetRevision& iSrc );

	//! Copy constructor
	StyleSheetRevision( const StyleSheetRevision& original );
     
public:

	//! Get StyleSheetType of this StyleSheetRevision
	plmxml_api::String GetStyleSheetType() const;

	//! Set StyleSheetType of this StyleSheetRevision
	plmxml_api::Result SetStyleSheetType( const plmxml_api::String &s );
	
	//! Check if StyleSheetType is set
	plmxml_api::logical HasStyleSheetType( ) const;
	
	//! Unset StyleSheetType
	plmxml_api::Result UnsetStyleSheetType( );

	//! Set ContentSize
	plmxml_api::Result SetContentSize( int arg );
     
	//! Get ContentSize
	int GetContentSize() const;
     
	//! Check if ContentSize is set
	plmxml_api::logical HasContentSize() const;
     
	//! Unset ContentSize
	plmxml_api::Result UnsetContentSize();

	//! Get MainFile of this StyleSheetRevision
	plmxml_api::String GetMainFile() const;

	//! Set MainFile of this StyleSheetRevision
	plmxml_api::Result SetMainFile( const plmxml_api::String &s );
	
	//! Check if MainFile is set
	plmxml_api::logical HasMainFile( ) const;
	
	//! Unset MainFile
	plmxml_api::Result UnsetMainFile( );

	//! Get ContentType of this StyleSheetRevision
	plmxml_api::String GetContentType() const;

	//! Set ContentType of this StyleSheetRevision
	plmxml_api::Result SetContentType( const plmxml_api::String &s );
	
	//! Check if ContentType is set
	plmxml_api::logical HasContentType( ) const;
	
	//! Unset ContentType
	plmxml_api::Result UnsetContentType( );

	//! Get Target of this StyleSheetRevision
	plmxml_api::String GetTarget() const;

	//! Set Target of this StyleSheetRevision
	plmxml_api::Result SetTarget( const plmxml_api::String &s );
	
	//! Check if Target is set
	plmxml_api::logical HasTarget( ) const;
	
	//! Unset Target
	plmxml_api::Result UnsetTarget( );
 
// <PLMXML_UserCode type="functionHeaderStyleSheetRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassStyleSheetRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ProcedureRevision class
/*!
\verbatim

      Revision of the Procedure.

      Attributes:

      contentSize:      Disk size needed for the content.
      procedureName:    Name of the procedure object.
      usage:            The procedure usage describes when the procedure is
                        designed to be used.
      
\endverbatim
*/
class PLMXML_CM60_API ProcedureRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ProcedureRevision( );
     
    //! Constructs a ProcedureRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcedureRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcedureRevision();

private:

	//! Assignment operator
	ProcedureRevision& operator=( const ProcedureRevision& iSrc );

	//! Copy constructor
	ProcedureRevision( const ProcedureRevision& original );
     
public:

	//! Get ProcedureName of this ProcedureRevision
	plmxml_api::String GetProcedureName() const;

	//! Set ProcedureName of this ProcedureRevision
	plmxml_api::Result SetProcedureName( const plmxml_api::String &s );
	
	//! Check if ProcedureName is set
	plmxml_api::logical HasProcedureName( ) const;
	
	//! Unset ProcedureName
	plmxml_api::Result UnsetProcedureName( );

	//! Set ContentSize
	plmxml_api::Result SetContentSize( int arg );
     
	//! Get ContentSize
	int GetContentSize() const;
     
	//! Check if ContentSize is set
	plmxml_api::logical HasContentSize() const;
     
	//! Unset ContentSize
	plmxml_api::Result UnsetContentSize();

	//! Get Usage of this ProcedureRevision
	plmxml_api::String GetUsage() const;

	//! Set Usage of this ProcedureRevision
	plmxml_api::Result SetUsage( const plmxml_api::String &s );
	
	//! Check if Usage is set
	plmxml_api::logical HasUsage( ) const;
	
	//! Unset Usage
	plmxml_api::Result UnsetUsage( );
 
// <PLMXML_UserCode type="functionHeaderProcedureRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassProcedureRevision;


////////////////////////////////////////////////////////////////////////////////////
//! GraphicAttributeRow class
/*!
\verbatim

      Represents the rows used to load and export graphic files, to provide the
      capability to extract information from filenames being imported or to
      prepare the correct filename when writing the file.

      Attributes:

      attributeName:    The property name.
      capitalizationBehavior: Control for setting lowercase or uppercase on
                        field values.
      value:            An optional literal string.
      fieldName:        An internal name for the portion of the filename being
                        addressed or the XML tag value which applies.
      fieldSeparator:   The divider character used when separating the filename
                        into the specified field.
      fieldLength:      The field length if it is a fixed length field.
      function:         The function being invoked to which the attribute
                        exchange row applies.
      
\endverbatim
*/
class PLMXML_CM60_API GraphicAttributeRow : public Attribute
{
public:
     
    //! Default constructor
    GraphicAttributeRow( );
     
    //! Constructs a GraphicAttributeRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GraphicAttributeRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GraphicAttributeRow();

private:

	//! Assignment operator
	GraphicAttributeRow& operator=( const GraphicAttributeRow& iSrc );

	//! Copy constructor
	GraphicAttributeRow( const GraphicAttributeRow& original );
     
public:

	//! Get FieldSeparator of this GraphicAttributeRow
	plmxml_api::String GetFieldSeparator() const;

	//! Set FieldSeparator of this GraphicAttributeRow
	plmxml_api::Result SetFieldSeparator( const plmxml_api::String &s );
	
	//! Check if FieldSeparator is set
	plmxml_api::logical HasFieldSeparator( ) const;
	
	//! Unset FieldSeparator
	plmxml_api::Result UnsetFieldSeparator( );

	//! Set FieldLength
	plmxml_api::Result SetFieldLength( int arg );
     
	//! Get FieldLength
	int GetFieldLength() const;
     
	//! Check if FieldLength is set
	plmxml_api::logical HasFieldLength() const;
     
	//! Unset FieldLength
	plmxml_api::Result UnsetFieldLength();

	//! Get Function of this GraphicAttributeRow
	plmxml_api::String GetFunction() const;

	//! Set Function of this GraphicAttributeRow
	plmxml_api::Result SetFunction( const plmxml_api::String &s );
	
	//! Check if Function is set
	plmxml_api::logical HasFunction( ) const;
	
	//! Unset Function
	plmxml_api::Result UnsetFunction( );

	//! Get FieldName of this GraphicAttributeRow
	plmxml_api::String GetFieldName() const;

	//! Set FieldName of this GraphicAttributeRow
	plmxml_api::Result SetFieldName( const plmxml_api::String &s );
	
	//! Check if FieldName is set
	plmxml_api::logical HasFieldName( ) const;
	
	//! Unset FieldName
	plmxml_api::Result UnsetFieldName( );

	//! Get Value of this GraphicAttributeRow
	plmxml_api::String GetValue() const;

	//! Set Value of this GraphicAttributeRow
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Get CapitalizationBehavior of this GraphicAttributeRow
	plmxml_api::String GetCapitalizationBehavior() const;

	//! Set CapitalizationBehavior of this GraphicAttributeRow
	plmxml_api::Result SetCapitalizationBehavior( const plmxml_api::String &s );
	
	//! Check if CapitalizationBehavior is set
	plmxml_api::logical HasCapitalizationBehavior( ) const;
	
	//! Unset CapitalizationBehavior
	plmxml_api::Result UnsetCapitalizationBehavior( );

	//! Get AttributeName of this GraphicAttributeRow
	plmxml_api::String GetAttributeName() const;

	//! Set AttributeName of this GraphicAttributeRow
	plmxml_api::Result SetAttributeName( const plmxml_api::String &s );
	
	//! Check if AttributeName is set
	plmxml_api::logical HasAttributeName( ) const;
	
	//! Unset AttributeName
	plmxml_api::Result UnsetAttributeName( );
 
// <PLMXML_UserCode type="functionHeaderGraphicAttributeRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassGraphicAttributeRow;


////////////////////////////////////////////////////////////////////////////////////
//! XMLAttributeRow class
/*!
\verbatim

      Represents the rows of specified interchange of metadata with topic
      content.

      Attributes:

      procedureRef:     Reference to the ProcedureRevision to be used for
                        transformation, if any.
      attributeName:    The property name.
      value:            An optional literal string.
      fieldSeparator:   The divider character used when separating a value into
                        the specified field.
      fieldLength:      The field length if it is a fixed length field.
      function:         The function being invoked to which the attribute
                        exchange row applies.
      omitEmpty:        Flag to skip exchange if value is empty, or to pass an
                        empty string.
      path:             The XML content path to where the value is to be fetched
                        or put.
      callback:         An optional callback function.
      
\endverbatim
*/
class PLMXML_CM60_API XMLAttributeRow : public Attribute
{
public:
     
    //! Default constructor
    XMLAttributeRow( );
     
    //! Constructs a XMLAttributeRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    XMLAttributeRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~XMLAttributeRow();

private:

	//! Assignment operator
	XMLAttributeRow& operator=( const XMLAttributeRow& iSrc );

	//! Copy constructor
	XMLAttributeRow( const XMLAttributeRow& original );
     
public:

	//! Set FieldLength
	plmxml_api::Result SetFieldLength( int arg );
     
	//! Get FieldLength
	int GetFieldLength() const;
     
	//! Check if FieldLength is set
	plmxml_api::logical HasFieldLength() const;
     
	//! Unset FieldLength
	plmxml_api::Result UnsetFieldLength();

	//! Get Path of this XMLAttributeRow
	plmxml_api::String GetPath() const;

	//! Set Path of this XMLAttributeRow
	plmxml_api::Result SetPath( const plmxml_api::String &s );
	
	//! Check if Path is set
	plmxml_api::logical HasPath( ) const;
	
	//! Unset Path
	plmxml_api::Result UnsetPath( );

	//! Get Value of this XMLAttributeRow
	plmxml_api::String GetValue() const;

	//! Set Value of this XMLAttributeRow
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );

	//! Get Function of this XMLAttributeRow
	plmxml_api::String GetFunction() const;

	//! Set Function of this XMLAttributeRow
	plmxml_api::Result SetFunction( const plmxml_api::String &s );
	
	//! Check if Function is set
	plmxml_api::logical HasFunction( ) const;
	
	//! Unset Function
	plmxml_api::Result UnsetFunction( );

	//! Set OmitEmpty
	plmxml_api::Result SetOmitEmpty( plmxml_api::logical arg );

	//! Get OmitEmpty
	plmxml_api::logical GetOmitEmpty() const;

	//! Check if OmitEmpty is set
	plmxml_api::logical HasOmitEmpty() const;

	//! Unset OmitEmpty
	plmxml_api::Result UnsetOmitEmpty();

	//! Get FieldSeparator of this XMLAttributeRow
	plmxml_api::String GetFieldSeparator() const;

	//! Set FieldSeparator of this XMLAttributeRow
	plmxml_api::Result SetFieldSeparator( const plmxml_api::String &s );
	
	//! Check if FieldSeparator is set
	plmxml_api::logical HasFieldSeparator( ) const;
	
	//! Unset FieldSeparator
	plmxml_api::Result UnsetFieldSeparator( );

	//! Get Callback of this XMLAttributeRow
	plmxml_api::String GetCallback() const;

	//! Set Callback of this XMLAttributeRow
	plmxml_api::Result SetCallback( const plmxml_api::String &s );
	
	//! Check if Callback is set
	plmxml_api::logical HasCallback( ) const;
	
	//! Unset Callback
	plmxml_api::Result UnsetCallback( );

	//! Get Procedure URI as plmxml_api::String
	plmxml_api::String GetProcedureURI() const;

	//! Set Procedure URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProcedureURI( const plmxml_api::String& );
	
	//! Get the handle of Procedure URI. Does not resolve the URI.
	plmxml_api::Result GetProcedureURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Procedure URI. URI string is unchanged.
	plmxml_api::Result SetProcedureURI( const plmxml_api::Handle& );
	
	//! Resolve Procedure URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProcedureURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Procedure URI. Clears URI string and handle.
	plmxml_api::Result DeleteProcedureURI();
	
	//! Check if Procedure URI is set
	plmxml_api::logical HasProcedureURI( ) const;
	

	//! Get AttributeName of this XMLAttributeRow
	plmxml_api::String GetAttributeName() const;

	//! Set AttributeName of this XMLAttributeRow
	plmxml_api::Result SetAttributeName( const plmxml_api::String &s );
	
	//! Check if AttributeName is set
	plmxml_api::logical HasAttributeName( ) const;
	
	//! Unset AttributeName
	plmxml_api::Result UnsetAttributeName( );
 
// <PLMXML_UserCode type="functionHeaderXMLAttributeRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassXMLAttributeRow;


////////////////////////////////////////////////////////////////////////////////////
//! LanguageRow class
/*!
\verbatim

      Language table.

      Attributes:

      languageRef:      Reference to the language for this row of the languages
                        table.
      reviewOrdered:    Flag to indicate if a review is needed on the content
                        returned.
      
\endverbatim
*/
class PLMXML_CM60_API LanguageRow : public Attribute
{
public:
     
    //! Default constructor
    LanguageRow( );
     
    //! Constructs a LanguageRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LanguageRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LanguageRow();

private:

	//! Assignment operator
	LanguageRow& operator=( const LanguageRow& iSrc );

	//! Copy constructor
	LanguageRow( const LanguageRow& original );
     
public:

	//! Set ReviewOrdered
	plmxml_api::Result SetReviewOrdered( plmxml_api::logical arg );

	//! Get ReviewOrdered
	plmxml_api::logical GetReviewOrdered() const;

	//! Check if ReviewOrdered is set
	plmxml_api::logical HasReviewOrdered() const;

	//! Unset ReviewOrdered
	plmxml_api::Result UnsetReviewOrdered();

	//! Get Language URI as plmxml_api::String
	plmxml_api::String GetLanguageURI() const;

	//! Set Language URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetLanguageURI( const plmxml_api::String& );
	
	//! Get the handle of Language URI. Does not resolve the URI.
	plmxml_api::Result GetLanguageURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Language URI. URI string is unchanged.
	plmxml_api::Result SetLanguageURI( const plmxml_api::Handle& );
	
	//! Resolve Language URI and return an object (handle) it points to.
	plmxml_api::Result ResolveLanguageURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Language URI. Clears URI string and handle.
	plmxml_api::Result DeleteLanguageURI();
	
	//! Check if Language URI is set
	plmxml_api::logical HasLanguageURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLanguageRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassLanguageRow;


////////////////////////////////////////////////////////////////////////////////////
//! NamespaceRow class
/*!
\verbatim

      Represents the rows of XML prefix values used with their full URI, used in
      the attribute mapping when finding values to replace.

      Attributes:

      uri:              The namespace URI corresponding to the prefix used.
      prefix:           XML prefix used for the namespace.
      
\endverbatim
*/
class PLMXML_CM60_API NamespaceRow : public Attribute
{
public:
     
    //! Default constructor
    NamespaceRow( );
     
    //! Constructs a NamespaceRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    NamespaceRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~NamespaceRow();

private:

	//! Assignment operator
	NamespaceRow& operator=( const NamespaceRow& iSrc );

	//! Copy constructor
	NamespaceRow( const NamespaceRow& original );
     
public:

	//! Get Prefix of this NamespaceRow
	plmxml_api::String GetPrefix() const;

	//! Set Prefix of this NamespaceRow
	plmxml_api::Result SetPrefix( const plmxml_api::String &s );
	
	//! Check if Prefix is set
	plmxml_api::logical HasPrefix( ) const;
	
	//! Unset Prefix
	plmxml_api::Result UnsetPrefix( );

	//! Get Uri of this NamespaceRow
	plmxml_api::String GetUri() const;

	//! Set Uri of this NamespaceRow
	plmxml_api::Result SetUri( const plmxml_api::String &s );
	
	//! Check if Uri is set
	plmxml_api::logical HasUri( ) const;
	
	//! Unset Uri
	plmxml_api::Result UnsetUri( );
 
// <PLMXML_UserCode type="functionHeaderNamespaceRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassNamespaceRow;


////////////////////////////////////////////////////////////////////////////////////
//! TransformPolicyRow class
/*!
\verbatim

      Represents the table of procedures to be run based upon the Tool,
      StyleSheet, and user action.

      Attributes:

      procedureRef:     Reference to the procedure revision to be used for
                        transformation, if any.
      toolRef:          Reference to the transformation tool which implements
                        the transformation.
      userAction:       User action which requires a transformation policy to be
                        run.
      styleSheetRef:    Reference to StyleSheet.
      
\endverbatim
*/
class PLMXML_CM60_API TransformPolicyRow : public Attribute
{
public:
     
    //! Default constructor
    TransformPolicyRow( );
     
    //! Constructs a TransformPolicyRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TransformPolicyRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TransformPolicyRow();

private:

	//! Assignment operator
	TransformPolicyRow& operator=( const TransformPolicyRow& iSrc );

	//! Copy constructor
	TransformPolicyRow( const TransformPolicyRow& original );
     
public:

	//! Get StyleSheet URI as plmxml_api::String
	plmxml_api::String GetStyleSheetURI() const;

	//! Set StyleSheet URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStyleSheetURI( const plmxml_api::String& );
	
	//! Get the handle of StyleSheet URI. Does not resolve the URI.
	plmxml_api::Result GetStyleSheetURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of StyleSheet URI. URI string is unchanged.
	plmxml_api::Result SetStyleSheetURI( const plmxml_api::Handle& );
	
	//! Resolve StyleSheet URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStyleSheetURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset StyleSheet URI. Clears URI string and handle.
	plmxml_api::Result DeleteStyleSheetURI();
	
	//! Check if StyleSheet URI is set
	plmxml_api::logical HasStyleSheetURI( ) const;
	

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
	

	//! Get UserAction of this TransformPolicyRow
	plmxml_api::String GetUserAction() const;

	//! Set UserAction of this TransformPolicyRow
	plmxml_api::Result SetUserAction( const plmxml_api::String &s );
	
	//! Check if UserAction is set
	plmxml_api::logical HasUserAction( ) const;
	
	//! Unset UserAction
	plmxml_api::Result UnsetUserAction( );

	//! Get Procedure URI as plmxml_api::String
	plmxml_api::String GetProcedureURI() const;

	//! Set Procedure URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetProcedureURI( const plmxml_api::String& );
	
	//! Get the handle of Procedure URI. Does not resolve the URI.
	plmxml_api::Result GetProcedureURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Procedure URI. URI string is unchanged.
	plmxml_api::Result SetProcedureURI( const plmxml_api::Handle& );
	
	//! Resolve Procedure URI and return an object (handle) it points to.
	plmxml_api::Result ResolveProcedureURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Procedure URI. Clears URI string and handle.
	plmxml_api::Result DeleteProcedureURI();
	
	//! Check if Procedure URI is set
	plmxml_api::logical HasProcedureURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderTransformPolicyRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTransformPolicyRow;


////////////////////////////////////////////////////////////////////////////////////
//! DITAValueFilterRow class
/*!
\verbatim

      The DITA Value filter table lists the rows that control the selection of
      content during publish.

      Attributes:

      action:           The action to be taken.
      attributeName:    The attribute name on the topic to be compared to the
                        value.
      value:            The value to match the value of the property in the
                        topic, when making the selection for what content to
                        publish using the DITA value filter.
      
\endverbatim
*/
class PLMXML_CM60_API DITAValueFilterRow : public Attribute
{
public:
     
    //! Default constructor
    DITAValueFilterRow( );
     
    //! Constructs a DITAValueFilterRow with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DITAValueFilterRow( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DITAValueFilterRow();

private:

	//! Assignment operator
	DITAValueFilterRow& operator=( const DITAValueFilterRow& iSrc );

	//! Copy constructor
	DITAValueFilterRow( const DITAValueFilterRow& original );
     
public:

	//! Get Action of this DITAValueFilterRow
	plmxml_api::String GetAction() const;

	//! Set Action of this DITAValueFilterRow
	plmxml_api::Result SetAction( const plmxml_api::String &s );
	
	//! Check if Action is set
	plmxml_api::logical HasAction( ) const;
	
	//! Unset Action
	plmxml_api::Result UnsetAction( );

	//! Get AttributeName of this DITAValueFilterRow
	plmxml_api::String GetAttributeName() const;

	//! Set AttributeName of this DITAValueFilterRow
	plmxml_api::Result SetAttributeName( const plmxml_api::String &s );
	
	//! Check if AttributeName is set
	plmxml_api::logical HasAttributeName( ) const;
	
	//! Unset AttributeName
	plmxml_api::Result UnsetAttributeName( );

	//! Get Value of this DITAValueFilterRow
	plmxml_api::String GetValue() const;

	//! Set Value of this DITAValueFilterRow
	plmxml_api::Result SetValue( const plmxml_api::String &s );
	
	//! Check if Value is set
	plmxml_api::logical HasValue( ) const;
	
	//! Unset Value
	plmxml_api::Result UnsetValue( );
 
// <PLMXML_UserCode type="functionHeaderDITAValueFilterRow" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassDITAValueFilterRow;


////////////////////////////////////////////////////////////////////////////////////
//! TopicTypXMLAttributeMapRelation class
/*!
\verbatim
This relation relates a TopicTyp to a XML Attribute Map.
\endverbatim
*/
class PLMXML_CM60_API TopicTypXMLAttributeMapRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    TopicTypXMLAttributeMapRelation( );
     
    //! Constructs a TopicTypXMLAttributeMapRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTypXMLAttributeMapRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTypXMLAttributeMapRelation();

private:

	//! Assignment operator
	TopicTypXMLAttributeMapRelation& operator=( const TopicTypXMLAttributeMapRelation& iSrc );

	//! Copy constructor
	TopicTypXMLAttributeMapRelation( const TopicTypXMLAttributeMapRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTopicTypXMLAttributeMapRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTypXMLAttributeMapRelation;


////////////////////////////////////////////////////////////////////////////////////
//! TopicTypTransformPolicyRelation class
/*!
\verbatim
This relation relates a TopicTyp to a Transformation Policy.
\endverbatim
*/
class PLMXML_CM60_API TopicTypTransformPolicyRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    TopicTypTransformPolicyRelation( );
     
    //! Constructs a TopicTypTransformPolicyRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTypTransformPolicyRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTypTransformPolicyRelation();

private:

	//! Assignment operator
	TopicTypTransformPolicyRelation& operator=( const TopicTypTransformPolicyRelation& iSrc );

	//! Copy constructor
	TopicTypTransformPolicyRelation( const TopicTypTransformPolicyRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTopicTypTransformPolicyRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTypTransformPolicyRelation;


////////////////////////////////////////////////////////////////////////////////////
//! TopicTypStyleSheetRelation class
/*!
\verbatim
This relation relates a TopicTyp to a StyleSheet.
\endverbatim
*/
class PLMXML_CM60_API TopicTypStyleSheetRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    TopicTypStyleSheetRelation( );
     
    //! Constructs a TopicTypStyleSheetRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTypStyleSheetRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTypStyleSheetRelation();

private:

	//! Assignment operator
	TopicTypStyleSheetRelation& operator=( const TopicTypStyleSheetRelation& iSrc );

	//! Copy constructor
	TopicTypStyleSheetRelation( const TopicTypStyleSheetRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTopicTypStyleSheetRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTypStyleSheetRelation;


////////////////////////////////////////////////////////////////////////////////////
//! TopicTypSchemaRelation class
/*!
\verbatim
This relation relates a TopicTyp to a CMSchema.
\endverbatim
*/
class PLMXML_CM60_API TopicTypSchemaRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    TopicTypSchemaRelation( );
     
    //! Constructs a TopicTypSchemaRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTypSchemaRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTypSchemaRelation();

private:

	//! Assignment operator
	TopicTypSchemaRelation& operator=( const TopicTypSchemaRelation& iSrc );

	//! Copy constructor
	TopicTypSchemaRelation( const TopicTypSchemaRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTopicTypSchemaRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTypSchemaRelation;


////////////////////////////////////////////////////////////////////////////////////
//! StyleSheetToolRelation class
/*!
\verbatim
This relation relates a StyleSheet to a Tool.
\endverbatim
*/
class PLMXML_CM60_API StyleSheetToolRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    StyleSheetToolRelation( );
     
    //! Constructs a StyleSheetToolRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StyleSheetToolRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StyleSheetToolRelation();

private:

	//! Assignment operator
	StyleSheetToolRelation& operator=( const StyleSheetToolRelation& iSrc );

	//! Copy constructor
	StyleSheetToolRelation( const StyleSheetToolRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderStyleSheetToolRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassStyleSheetToolRelation;


////////////////////////////////////////////////////////////////////////////////////
//! StyleTypeStyleSheetRelation class
/*!
\verbatim
This relation relates a StyleType to a StyleSheet.
\endverbatim
*/
class PLMXML_CM60_API StyleTypeStyleSheetRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    StyleTypeStyleSheetRelation( );
     
    //! Constructs a StyleTypeStyleSheetRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StyleTypeStyleSheetRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StyleTypeStyleSheetRelation();

private:

	//! Assignment operator
	StyleTypeStyleSheetRelation& operator=( const StyleTypeStyleSheetRelation& iSrc );

	//! Copy constructor
	StyleTypeStyleSheetRelation( const StyleTypeStyleSheetRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderStyleTypeStyleSheetRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassStyleTypeStyleSheetRelation;


////////////////////////////////////////////////////////////////////////////////////
//! TopicTypTopicTypRelation class
/*!
\verbatim
This relation relates a TopicTyp to another TopicTyp.
\endverbatim
*/
class PLMXML_CM60_API TopicTypTopicTypRelation : public GeneralRelation
{
public:
     
    //! Default constructor
    TopicTypTopicTypRelation( );
     
    //! Constructs a TopicTypTopicTypRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TopicTypTopicTypRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TopicTypTopicTypRelation();

private:

	//! Assignment operator
	TopicTypTopicTypRelation& operator=( const TopicTypTopicTypRelation& iSrc );

	//! Copy constructor
	TopicTypTopicTypRelation( const TopicTypTopicTypRelation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderTopicTypTopicTypRelation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CM60_API plmxml_api::plmxmlClass plmxmlClassTopicTypTopicTypRelation;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
