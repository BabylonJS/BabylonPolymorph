/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.23120 22/12/2016 12:54:06
// 
// Schema:	PLMXMLNGPSchema.xsd
// Data:	2016-05-24
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_NGP60_H__
#define __PLMXML_NGP60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_NGP60_EXPORTS
#define PLMXML_NGP60_API __declspec(dllexport)
#else
#define PLMXML_NGP60_API __declspec(dllimport)
#endif
#else
#define PLMXML_NGP60_API
#endif

//////////////////////////////////////////////////////////////////////

#include <plmxml.h>


#include <plmxml_classification60.h>
#include <plmxml60.h>
// <PLMXML_UserCode type="includeHeader" >
// TODO: Add extra include headers within this block
// </PLMXML_UserCode>

PLMXML_BEGIN_NAMESPACE( plmxml_ngp60 )

/////////////////////////////////////////////////////////////////////////
 
// <PLMXML_UserCode type="classHeader" >
// TODO: Add extra definitions required for the class in this block
// </PLMXML_UserCode>

////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingModel class
/*!
\verbatim

      A 4G Manufacturing Model.

      Attributes:

      modelId:          The identifier of the Manufacturing Model.
      productModelRefs: References Collaborative Designs.
      
\endverbatim
*/
class PLMXML_NGP60_API ManufacturingModel : public plmxml60::Structure
{
public:
     
    //! Default constructor
    ManufacturingModel( );
     
    //! Constructs a ManufacturingModel with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingModel( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingModel();

private:

	//! Assignment operator
	ManufacturingModel& operator=( const ManufacturingModel& iSrc );

	//! Copy constructor
	ManufacturingModel( const ManufacturingModel& original );
     
public:

	//! Get ModelId of this ManufacturingModel
	plmxml_api::String GetModelId() const;

	//! Set ModelId of this ManufacturingModel
	plmxml_api::Result SetModelId( const plmxml_api::String &s );
	
	//! Check if ModelId is set
	plmxml_api::logical HasModelId( ) const;
	
	//! Unset ModelId
	plmxml_api::Result UnsetModelId( );

	//! Get number of URIs in ProductModel
	int NumberOfProductModelURIs() const;

	//! Get i'th URI in ProductModel
	plmxml_api::String GetProductModelURI( int i ) const;

	//! Add a URI to ProductModel array. Call ResolveProductModelURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddProductModelURI( const plmxml_api::String& u );

	//! Set i'th URI in ProductModel array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetProductModelURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ProductModel URI. Does not resolve the URI.
	plmxml_api::Result GetProductModelURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ProductModel array.
	plmxml_api::Result AddProductModelURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ProductModel array to point to 'handle'.
	plmxml_api::Result SetProductModelURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ProductModel points to.
	plmxml_api::Result ResolveProductModelURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ProductModel array.
	plmxml_api::Result DeleteProductModelURI( int i );

	//! Remove all URIs from ProductModel array.
	plmxml_api::Result DeleteProductModelURIs( );
	
	//! Check if ProductModel is set
	plmxml_api::logical HasProductModelURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderManufacturingModel" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassManufacturingModel;


////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingModelStructureView class
/*!
\verbatim

      A view of a 4G Manufacturing Model.
      
\endverbatim
*/
class PLMXML_NGP60_API ManufacturingModelStructureView : public plmxml60::StructureView
{
public:
     
    //! Default constructor
    ManufacturingModelStructureView( );
     
    //! Constructs a ManufacturingModelStructureView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingModelStructureView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingModelStructureView();

private:

	//! Assignment operator
	ManufacturingModelStructureView& operator=( const ManufacturingModelStructureView& iSrc );

	//! Copy constructor
	ManufacturingModelStructureView( const ManufacturingModelStructureView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderManufacturingModelStructureView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassManufacturingModelStructureView;


////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingModelRevision class
/*!
\verbatim

      A revision of a 4G Manufacturing Model.
      
\endverbatim
*/
class PLMXML_NGP60_API ManufacturingModelRevision : public plmxml60::StructureRevision
{
public:
     
    //! Default constructor
    ManufacturingModelRevision( );
     
    //! Constructs a ManufacturingModelRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingModelRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingModelRevision();

private:

	//! Assignment operator
	ManufacturingModelRevision& operator=( const ManufacturingModelRevision& iSrc );

	//! Copy constructor
	ManufacturingModelRevision( const ManufacturingModelRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderManufacturingModelRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassManufacturingModelRevision;


////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingModelRevisionView class
/*!
\verbatim

      A view of a revision of a 4G Manufacturing Model.

      Sub-elements:

      ModelElement:     4G Model Elements.
      
\endverbatim
*/
class PLMXML_NGP60_API ManufacturingModelRevisionView : public plmxml60::StructureRevisionView
{
public:
     
    //! Default constructor
    ManufacturingModelRevisionView( );
     
    //! Constructs a ManufacturingModelRevisionView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingModelRevisionView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingModelRevisionView();

private:

	//! Assignment operator
	ManufacturingModelRevisionView& operator=( const ManufacturingModelRevisionView& iSrc );

	//! Copy constructor
	ManufacturingModelRevisionView( const ManufacturingModelRevisionView& original );
     
public:

	//! Add ModelElement child element to this ManufacturingModelRevisionView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	plmxml60::ModelElement *AddModelElement();
     
	//! Add 'arg' as ModelElement child element to this ManufacturingModelRevisionView.
	plmxml_api::Result AddModelElement( plmxml60::ModelElement *arg );

	//! Detach and delete all ModelElement child elements.
	void DeleteModelElements();
     
	//! Get number of ModelElement child elements.
	int NumberOfModelElements() const;
     
	//! Get i'th ModelElement child element.
	plmxml60::ModelElement *GetModelElement( int i ) const;
     
	//! Get all ModelElement child element as an array
	void GetModelElements( plmxml_api::Array<plmxml60::ModelElement*> &array ) const;
	     
	//! Detach and delete i'th ModelElement child element
	void DeleteModelElement( int i );
     
	//! Detach and delete 'arg' if it's one of the ModelElement child elements
	void DeleteModelElement( plmxml60::ModelElement *arg );
 
// <PLMXML_UserCode type="functionHeaderManufacturingModelRevisionView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassManufacturingModelRevisionView;


////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingModelElement class
/*!
\verbatim

      A 4G Manufacturing Model Element.

      Attributes:

      objectId:         The identifier of the Manufacturing Model Element.

      Sub-elements:

      AssociatedDataSet: Inherited from ModelElement.
      
\endverbatim
*/
class PLMXML_NGP60_API ManufacturingModelElement : public plmxml60::ModelElement
{
public:
     
    //! Default constructor
    ManufacturingModelElement( );
     
    //! Constructs a ManufacturingModelElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingModelElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingModelElement();

private:

	//! Assignment operator
	ManufacturingModelElement& operator=( const ManufacturingModelElement& iSrc );

	//! Copy constructor
	ManufacturingModelElement( const ManufacturingModelElement& original );
     
public:

	//! Get ObjectId of this ManufacturingModelElement
	plmxml_api::String GetObjectId() const;

	//! Set ObjectId of this ManufacturingModelElement
	plmxml_api::Result SetObjectId( const plmxml_api::String &s );
	
	//! Check if ObjectId is set
	plmxml_api::logical HasObjectId( ) const;
	
	//! Unset ObjectId
	plmxml_api::Result UnsetObjectId( );
 
// <PLMXML_UserCode type="functionHeaderManufacturingModelElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassManufacturingModelElement;


////////////////////////////////////////////////////////////////////////////////////
//! BuildElement class
/*!
\verbatim

      A 4G Build Element.

      Attributes:

      objectId:         Inherited from ManufacturingModelElement. The identifier
                        of the Build Element.
      activityElementRefs: References Activity Elements.
      subBuildElementRefs: References subordinate Build Elements.
      
\endverbatim
*/
class PLMXML_NGP60_API BuildElement : public ManufacturingModelElement
{
public:
     
    //! Default constructor
    BuildElement( );
     
    //! Constructs a BuildElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BuildElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BuildElement();

private:

	//! Assignment operator
	BuildElement& operator=( const BuildElement& iSrc );

	//! Copy constructor
	BuildElement( const BuildElement& original );
     
public:

	//! Get number of URIs in ActivityElement
	int NumberOfActivityElementURIs() const;

	//! Get i'th URI in ActivityElement
	plmxml_api::String GetActivityElementURI( int i ) const;

	//! Add a URI to ActivityElement array. Call ResolveActivityElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActivityElementURI( const plmxml_api::String& u );

	//! Set i'th URI in ActivityElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActivityElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ActivityElement URI. Does not resolve the URI.
	plmxml_api::Result GetActivityElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ActivityElement array.
	plmxml_api::Result AddActivityElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ActivityElement array to point to 'handle'.
	plmxml_api::Result SetActivityElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ActivityElement points to.
	plmxml_api::Result ResolveActivityElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ActivityElement array.
	plmxml_api::Result DeleteActivityElementURI( int i );

	//! Remove all URIs from ActivityElement array.
	plmxml_api::Result DeleteActivityElementURIs( );
	
	//! Check if ActivityElement is set
	plmxml_api::logical HasActivityElementURIs( ) const;

	//! Get number of URIs in SubBuildElement
	int NumberOfSubBuildElementURIs() const;

	//! Get i'th URI in SubBuildElement
	plmxml_api::String GetSubBuildElementURI( int i ) const;

	//! Add a URI to SubBuildElement array. Call ResolveSubBuildElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSubBuildElementURI( const plmxml_api::String& u );

	//! Set i'th URI in SubBuildElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSubBuildElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SubBuildElement URI. Does not resolve the URI.
	plmxml_api::Result GetSubBuildElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SubBuildElement array.
	plmxml_api::Result AddSubBuildElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SubBuildElement array to point to 'handle'.
	plmxml_api::Result SetSubBuildElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SubBuildElement points to.
	plmxml_api::Result ResolveSubBuildElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SubBuildElement array.
	plmxml_api::Result DeleteSubBuildElementURI( int i );

	//! Remove all URIs from SubBuildElement array.
	plmxml_api::Result DeleteSubBuildElementURIs( );
	
	//! Check if SubBuildElement is set
	plmxml_api::logical HasSubBuildElementURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderBuildElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassBuildElement;


////////////////////////////////////////////////////////////////////////////////////
//! ActivityElement class
/*!
\verbatim

      A 4G Activity Element.

      Attributes:

      objectId:         Inherited from ManufacturingModelElement. The identifier
                        of the Activity Element.
      processElementRefs: References the Process Elements to which this Activity
                        Element relates.
      manufacturingElementRefs: References the Manufacturing Elements to which
                        this Activity Element relates.
      subsetInstanceRefs: References the SubsetInstances to which this Activity
                        Element relates.
      
\endverbatim
*/
class PLMXML_NGP60_API ActivityElement : public ManufacturingModelElement
{
public:
     
    //! Default constructor
    ActivityElement( );
     
    //! Constructs a ActivityElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ActivityElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ActivityElement();

private:

	//! Assignment operator
	ActivityElement& operator=( const ActivityElement& iSrc );

	//! Copy constructor
	ActivityElement( const ActivityElement& original );
     
public:

	//! Get number of URIs in ProcessElement
	int NumberOfProcessElementURIs() const;

	//! Get i'th URI in ProcessElement
	plmxml_api::String GetProcessElementURI( int i ) const;

	//! Add a URI to ProcessElement array. Call ResolveProcessElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddProcessElementURI( const plmxml_api::String& u );

	//! Set i'th URI in ProcessElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetProcessElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ProcessElement URI. Does not resolve the URI.
	plmxml_api::Result GetProcessElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ProcessElement array.
	plmxml_api::Result AddProcessElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ProcessElement array to point to 'handle'.
	plmxml_api::Result SetProcessElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ProcessElement points to.
	plmxml_api::Result ResolveProcessElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ProcessElement array.
	plmxml_api::Result DeleteProcessElementURI( int i );

	//! Remove all URIs from ProcessElement array.
	plmxml_api::Result DeleteProcessElementURIs( );
	
	//! Check if ProcessElement is set
	plmxml_api::logical HasProcessElementURIs( ) const;

	//! Get number of URIs in ManufacturingElement
	int NumberOfManufacturingElementURIs() const;

	//! Get i'th URI in ManufacturingElement
	plmxml_api::String GetManufacturingElementURI( int i ) const;

	//! Add a URI to ManufacturingElement array. Call ResolveManufacturingElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddManufacturingElementURI( const plmxml_api::String& u );

	//! Set i'th URI in ManufacturingElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetManufacturingElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ManufacturingElement URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturingElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ManufacturingElement array.
	plmxml_api::Result AddManufacturingElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ManufacturingElement array to point to 'handle'.
	plmxml_api::Result SetManufacturingElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ManufacturingElement points to.
	plmxml_api::Result ResolveManufacturingElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ManufacturingElement array.
	plmxml_api::Result DeleteManufacturingElementURI( int i );

	//! Remove all URIs from ManufacturingElement array.
	plmxml_api::Result DeleteManufacturingElementURIs( );
	
	//! Check if ManufacturingElement is set
	plmxml_api::logical HasManufacturingElementURIs( ) const;

	//! Get number of URIs in SubsetInstance
	int NumberOfSubsetInstanceURIs() const;

	//! Get i'th URI in SubsetInstance
	plmxml_api::String GetSubsetInstanceURI( int i ) const;

	//! Add a URI to SubsetInstance array. Call ResolveSubsetInstanceURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSubsetInstanceURI( const plmxml_api::String& u );

	//! Set i'th URI in SubsetInstance array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSubsetInstanceURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SubsetInstance URI. Does not resolve the URI.
	plmxml_api::Result GetSubsetInstanceURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SubsetInstance array.
	plmxml_api::Result AddSubsetInstanceURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SubsetInstance array to point to 'handle'.
	plmxml_api::Result SetSubsetInstanceURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SubsetInstance points to.
	plmxml_api::Result ResolveSubsetInstanceURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SubsetInstance array.
	plmxml_api::Result DeleteSubsetInstanceURI( int i );

	//! Remove all URIs from SubsetInstance array.
	plmxml_api::Result DeleteSubsetInstanceURIs( );
	
	//! Check if SubsetInstance is set
	plmxml_api::logical HasSubsetInstanceURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderActivityElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassActivityElement;


////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingElement class
/*!
\verbatim

      A 4G Manufacturing Element.

      Attributes:

      objectId:         Inherited from ManufacturingModelElement. The identifier
                        of the Manufacturing Element.
      subManufacturingElementRefs: References subordinate Manufacturing
                        Elements.
      
\endverbatim
*/
class PLMXML_NGP60_API ManufacturingElement : public ManufacturingModelElement
{
public:
     
    //! Default constructor
    ManufacturingElement( );
     
    //! Constructs a ManufacturingElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingElement();

private:

	//! Assignment operator
	ManufacturingElement& operator=( const ManufacturingElement& iSrc );

	//! Copy constructor
	ManufacturingElement( const ManufacturingElement& original );
     
public:

	//! Get number of URIs in SubManufacturingElement
	int NumberOfSubManufacturingElementURIs() const;

	//! Get i'th URI in SubManufacturingElement
	plmxml_api::String GetSubManufacturingElementURI( int i ) const;

	//! Add a URI to SubManufacturingElement array. Call ResolveSubManufacturingElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddSubManufacturingElementURI( const plmxml_api::String& u );

	//! Set i'th URI in SubManufacturingElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetSubManufacturingElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of SubManufacturingElement URI. Does not resolve the URI.
	plmxml_api::Result GetSubManufacturingElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to SubManufacturingElement array.
	plmxml_api::Result AddSubManufacturingElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in SubManufacturingElement array to point to 'handle'.
	plmxml_api::Result SetSubManufacturingElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in SubManufacturingElement points to.
	plmxml_api::Result ResolveSubManufacturingElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from SubManufacturingElement array.
	plmxml_api::Result DeleteSubManufacturingElementURI( int i );

	//! Remove all URIs from SubManufacturingElement array.
	plmxml_api::Result DeleteSubManufacturingElementURIs( );
	
	//! Check if SubManufacturingElement is set
	plmxml_api::logical HasSubManufacturingElementURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderManufacturingElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassManufacturingElement;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessElement class
/*!
\verbatim

      A 4G Process Element.

      Attributes:

      objectId:         Inherited from ManufacturingModelElement. The identifier
                        of the Process Element.
      operationElementRefs: References the subordinate Operation Elements.
      manufacturingElementRefs: References the Manufacturing Elements to which
                        this Process Element relates.
      predecessorRefs:  References predecessor Process Elements.
      
\endverbatim
*/
class PLMXML_NGP60_API ProcessElement : public ManufacturingModelElement
{
public:
     
    //! Default constructor
    ProcessElement( );
     
    //! Constructs a ProcessElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessElement();

private:

	//! Assignment operator
	ProcessElement& operator=( const ProcessElement& iSrc );

	//! Copy constructor
	ProcessElement( const ProcessElement& original );
     
public:

	//! Get number of URIs in ManufacturingElement
	int NumberOfManufacturingElementURIs() const;

	//! Get i'th URI in ManufacturingElement
	plmxml_api::String GetManufacturingElementURI( int i ) const;

	//! Add a URI to ManufacturingElement array. Call ResolveManufacturingElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddManufacturingElementURI( const plmxml_api::String& u );

	//! Set i'th URI in ManufacturingElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetManufacturingElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of ManufacturingElement URI. Does not resolve the URI.
	plmxml_api::Result GetManufacturingElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to ManufacturingElement array.
	plmxml_api::Result AddManufacturingElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in ManufacturingElement array to point to 'handle'.
	plmxml_api::Result SetManufacturingElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in ManufacturingElement points to.
	plmxml_api::Result ResolveManufacturingElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from ManufacturingElement array.
	plmxml_api::Result DeleteManufacturingElementURI( int i );

	//! Remove all URIs from ManufacturingElement array.
	plmxml_api::Result DeleteManufacturingElementURIs( );
	
	//! Check if ManufacturingElement is set
	plmxml_api::logical HasManufacturingElementURIs( ) const;

	//! Get number of URIs in Predecessor
	int NumberOfPredecessorURIs() const;

	//! Get i'th URI in Predecessor
	plmxml_api::String GetPredecessorURI( int i ) const;

	//! Add a URI to Predecessor array. Call ResolvePredecessorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPredecessorURI( const plmxml_api::String& u );

	//! Set i'th URI in Predecessor array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPredecessorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Predecessor URI. Does not resolve the URI.
	plmxml_api::Result GetPredecessorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Predecessor array.
	plmxml_api::Result AddPredecessorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Predecessor array to point to 'handle'.
	plmxml_api::Result SetPredecessorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Predecessor points to.
	plmxml_api::Result ResolvePredecessorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Predecessor array.
	plmxml_api::Result DeletePredecessorURI( int i );

	//! Remove all URIs from Predecessor array.
	plmxml_api::Result DeletePredecessorURIs( );
	
	//! Check if Predecessor is set
	plmxml_api::logical HasPredecessorURIs( ) const;

	//! Get number of URIs in OperationElement
	int NumberOfOperationElementURIs() const;

	//! Get i'th URI in OperationElement
	plmxml_api::String GetOperationElementURI( int i ) const;

	//! Add a URI to OperationElement array. Call ResolveOperationElementURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddOperationElementURI( const plmxml_api::String& u );

	//! Set i'th URI in OperationElement array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetOperationElementURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of OperationElement URI. Does not resolve the URI.
	plmxml_api::Result GetOperationElementURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to OperationElement array.
	plmxml_api::Result AddOperationElementURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in OperationElement array to point to 'handle'.
	plmxml_api::Result SetOperationElementURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in OperationElement points to.
	plmxml_api::Result ResolveOperationElementURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from OperationElement array.
	plmxml_api::Result DeleteOperationElementURI( int i );

	//! Remove all URIs from OperationElement array.
	plmxml_api::Result DeleteOperationElementURIs( );
	
	//! Check if OperationElement is set
	plmxml_api::logical HasOperationElementURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderProcessElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassProcessElement;


////////////////////////////////////////////////////////////////////////////////////
//! OperationElement class
/*!
\verbatim

      A 4G Operation Element.

      Attributes:

      objectId:         Inherited from ManufacturingModelElement. The identifier
                        of the Operation Element.
      predecessorRefs:  References predecessor Operation Elements.
      
\endverbatim
*/
class PLMXML_NGP60_API OperationElement : public ManufacturingModelElement
{
public:
     
    //! Default constructor
    OperationElement( );
     
    //! Constructs a OperationElement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OperationElement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OperationElement();

private:

	//! Assignment operator
	OperationElement& operator=( const OperationElement& iSrc );

	//! Copy constructor
	OperationElement( const OperationElement& original );
     
public:

	//! Get number of URIs in Predecessor
	int NumberOfPredecessorURIs() const;

	//! Get i'th URI in Predecessor
	plmxml_api::String GetPredecessorURI( int i ) const;

	//! Add a URI to Predecessor array. Call ResolvePredecessorURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPredecessorURI( const plmxml_api::String& u );

	//! Set i'th URI in Predecessor array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPredecessorURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Predecessor URI. Does not resolve the URI.
	plmxml_api::Result GetPredecessorURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Predecessor array.
	plmxml_api::Result AddPredecessorURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Predecessor array to point to 'handle'.
	plmxml_api::Result SetPredecessorURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Predecessor points to.
	plmxml_api::Result ResolvePredecessorURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Predecessor array.
	plmxml_api::Result DeletePredecessorURI( int i );

	//! Remove all URIs from Predecessor array.
	plmxml_api::Result DeletePredecessorURIs( );
	
	//! Check if Predecessor is set
	plmxml_api::logical HasPredecessorURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderOperationElement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassOperationElement;


////////////////////////////////////////////////////////////////////////////////////
//! Assignment class
/*!
\verbatim

      A 4G Assignment.

      Attributes:

      subType:          Inherited from GeneralRelation.
      derived:          Whether the Assignment is derived.
      
\endverbatim
*/
class PLMXML_NGP60_API Assignment : public plmxml60::GeneralRelation
{
public:
     
    //! Default constructor
    Assignment( );
     
    //! Constructs a Assignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Assignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Assignment();

private:

	//! Assignment operator
	Assignment& operator=( const Assignment& iSrc );

	//! Copy constructor
	Assignment( const Assignment& original );
     
public:

	//! Set Derived
	plmxml_api::Result SetDerived( plmxml_api::logical arg );

	//! Get Derived
	plmxml_api::logical GetDerived() const;

	//! Check if Derived is set
	plmxml_api::logical HasDerived() const;

	//! Unset Derived
	plmxml_api::Result UnsetDerived();
 
// <PLMXML_UserCode type="functionHeaderAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! ProductModelRelation class
/*!
\verbatim

      Relates a ManufacturingModel to a CollaborativeDesign. The references in
      the inherited relatedRefs attribute must be in that order.

      Attributes:

      subType:          Inherited from GeneralRelation.
      relatedRefs:      Inherited from GeneralRelation. Relates a
                        ManufacturingModel to a CollaborativeDesign in that
                        order.
      
\endverbatim
*/
class PLMXML_NGP60_API ProductModelRelation : public plmxml60::GeneralRelation
{
public:
     
    //! Default constructor
    ProductModelRelation( );
     
    //! Constructs a ProductModelRelation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProductModelRelation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProductModelRelation();

private:

	//! Assignment operator
	ProductModelRelation& operator=( const ProductModelRelation& iSrc );

	//! Copy constructor
	ProductModelRelation( const ProductModelRelation& original );
     
public:

     // <PLMXML_UserCode type="functionHeaderProductModelRelation" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_NGP60_API plmxml_api::plmxmlClass plmxmlClassProductModelRelation;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
