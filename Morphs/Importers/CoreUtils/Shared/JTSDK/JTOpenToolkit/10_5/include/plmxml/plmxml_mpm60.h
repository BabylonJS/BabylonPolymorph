/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 08/06/2018 14:35:57
// 
// Schema:	PLMXMLMPMSchema.xsd
// Data:	08/06/2018 14:35:53
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_MPM60_H__
#define __PLMXML_MPM60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_MPM60_EXPORTS
#define PLMXML_MPM60_API __declspec(dllexport)
#else
#define PLMXML_MPM60_API __declspec(dllimport)
#endif
#else
#define PLMXML_MPM60_API
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
//! SetupInstance class
/*!
\verbatim

      This element is used to allow ProcessRevisionView elements to Instance elements
      in the Plant and Product Structures, or to reference Occurrences in those
      structures.
      
      Attributes:      
   
      predecessorRefs:     Used to indicate the process flow.
      
\endverbatim
*/
class PLMXML_MPM60_API SetupInstance : public CompositionInstance
{
public:
     
    //! Default constructor
    SetupInstance( );
     
    //! Constructs a SetupInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SetupInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SetupInstance();

private:

	//! Assignment operator
	SetupInstance& operator=( const SetupInstance& iSrc );

	//! Copy constructor
	SetupInstance( const SetupInstance& original );
     
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
 
// <PLMXML_UserCode type="functionHeaderSetupInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassSetupInstance;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessInstance class
/*!
\verbatim

      An Instance of a Process, ProcessRevision, ProcessRevisionView, or ProcessStructureView.
    
      Attributes:
    
      predecessorRefs:      Used to indicate the process flow.
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessInstance : public Instance
{
public:
     
    //! Default constructor
    ProcessInstance( );
     
    //! Constructs a ProcessInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessInstance();

private:

	//! Assignment operator
	ProcessInstance& operator=( const ProcessInstance& iSrc );

	//! Copy constructor
	ProcessInstance( const ProcessInstance& original );
     
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
 
// <PLMXML_UserCode type="functionHeaderProcessInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessInstance;


////////////////////////////////////////////////////////////////////////////////////
//! WorkAreaInstance class
/*!
\verbatim

      An Instance of a WorkArea, WorkAreaRevision, WorkAreaStructureView, or
      PlantRevisionView.
    
      Attributes:
    
      predecessorRefs:    Used to indicate the process flow.
      
\endverbatim
*/
class PLMXML_MPM60_API WorkAreaInstance : public Instance
{
public:
     
    //! Default constructor
    WorkAreaInstance( );
     
    //! Constructs a WorkAreaInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkAreaInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkAreaInstance();

private:

	//! Assignment operator
	WorkAreaInstance& operator=( const WorkAreaInstance& iSrc );

	//! Copy constructor
	WorkAreaInstance( const WorkAreaInstance& original );
     
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
 
// <PLMXML_UserCode type="functionHeaderWorkAreaInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassWorkAreaInstance;


////////////////////////////////////////////////////////////////////////////////////
//! Activity class
/*!
\verbatim

      An Activity is a component of an OperationRevision. An OperationRevision
      contains a tree of Activities.
    
      Attributes:
    
      type:              
      activityRefs       child activities
      predecessorRefs    prior activities in the flow
    
      Note that the values of the following attributes are in unspecified time units. They
      can be used for comparison, but do not indicate absolute time intervals.
    
      startTime          The start time of an activity 
      duration           The duration of the activity
      calcStartTime      Calculated time before starting current process/operation/activity 
                         due to existence of predecessors
      calcDuration       calculated total duration of all the activities under an operation
      calcMinStartTime   calculated minimum time required before starting current
                         process/operation/activity due to existence of predecessor(s)
      
\endverbatim
*/
class PLMXML_MPM60_API Activity : public Managed
{
public:
     
    //! Default constructor
    Activity( );
     
    //! Constructs a Activity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Activity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Activity();

private:

	//! Assignment operator
	Activity& operator=( const Activity& iSrc );

	//! Copy constructor
	Activity( const Activity& original );
     
public:

	//! Set StartTime
	plmxml_api::Result SetStartTime( double arg );

     //! Get StartTime
	double GetStartTime() const;

	//! Check if StartTime is set
	plmxml_api::logical HasStartTime() const;

	//! Unset StartTime
	plmxml_api::Result UnsetStartTime();

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

	//! Set CalcMinStartTime
	plmxml_api::Result SetCalcMinStartTime( double arg );

     //! Get CalcMinStartTime
	double GetCalcMinStartTime() const;

	//! Check if CalcMinStartTime is set
	plmxml_api::logical HasCalcMinStartTime() const;

	//! Unset CalcMinStartTime
	plmxml_api::Result UnsetCalcMinStartTime();

	//! Set CalcStartTime
	plmxml_api::Result SetCalcStartTime( double arg );

     //! Get CalcStartTime
	double GetCalcStartTime() const;

	//! Check if CalcStartTime is set
	plmxml_api::logical HasCalcStartTime() const;

	//! Unset CalcStartTime
	plmxml_api::Result UnsetCalcStartTime();

	//! Set Duration
	plmxml_api::Result SetDuration( double arg );

     //! Get Duration
	double GetDuration() const;

	//! Check if Duration is set
	plmxml_api::logical HasDuration() const;

	//! Unset Duration
	plmxml_api::Result UnsetDuration();

	//! Get Type of this Activity
	plmxml_api::String GetType() const;

	//! Set Type of this Activity
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Get number of URIs in Activity
	int NumberOfActivityURIs() const;

	//! Get i'th URI in Activity
	plmxml_api::String GetActivityURI( int i ) const;

	//! Add a URI to Activity array. Call ResolveActivityURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddActivityURI( const plmxml_api::String& u );

	//! Set i'th URI in Activity array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetActivityURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Activity URI. Does not resolve the URI.
	plmxml_api::Result GetActivityURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Activity array.
	plmxml_api::Result AddActivityURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Activity array to point to 'handle'.
	plmxml_api::Result SetActivityURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Activity points to.
	plmxml_api::Result ResolveActivityURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Activity array.
	plmxml_api::Result DeleteActivityURI( int i );

	//! Remove all URIs from Activity array.
	plmxml_api::Result DeleteActivityURIs( );
	
	//! Check if Activity is set
	plmxml_api::logical HasActivityURIs( ) const;

	//! Set CalcDuration
	plmxml_api::Result SetCalcDuration( double arg );

     //! Get CalcDuration
	double GetCalcDuration() const;

	//! Check if CalcDuration is set
	plmxml_api::logical HasCalcDuration() const;

	//! Unset CalcDuration
	plmxml_api::Result UnsetCalcDuration();
 
// <PLMXML_UserCode type="functionHeaderActivity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassActivity;


////////////////////////////////////////////////////////////////////////////////////
//! WorkArea class
/*!
\verbatim

      The WorkArea is used to represent plant structure.
      
\endverbatim
*/
class PLMXML_MPM60_API WorkArea : public Structure
{
public:
     
    //! Default constructor
    WorkArea( );
     
    //! Constructs a WorkArea with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkArea( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkArea();

private:

	//! Assignment operator
	WorkArea& operator=( const WorkArea& iSrc );

	//! Copy constructor
	WorkArea( const WorkArea& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderWorkArea" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassWorkArea;


////////////////////////////////////////////////////////////////////////////////////
//! WorkAreaRevision class
/*!
\verbatim

      A Revision of a WorkArea.
      
\endverbatim
*/
class PLMXML_MPM60_API WorkAreaRevision : public StructureRevision
{
public:
     
    //! Default constructor
    WorkAreaRevision( );
     
    //! Constructs a WorkAreaRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkAreaRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkAreaRevision();

private:

	//! Assignment operator
	WorkAreaRevision& operator=( const WorkAreaRevision& iSrc );

	//! Copy constructor
	WorkAreaRevision( const WorkAreaRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderWorkAreaRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassWorkAreaRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Operation class
/*!
\verbatim

      An Operation is a leaf node in the Process Structure.
      
\endverbatim
*/
class PLMXML_MPM60_API Operation : public Structure
{
public:
     
    //! Default constructor
    Operation( );
     
    //! Constructs a Operation with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Operation( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Operation();

private:

	//! Assignment operator
	Operation& operator=( const Operation& iSrc );

	//! Copy constructor
	Operation( const Operation& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderOperation" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassOperation;


////////////////////////////////////////////////////////////////////////////////////
//! OperationRevision class
/*!
\verbatim

      A Revision of an Operation.
      
      Attributes:
      
      activityRef:   the root Activity under this Operation.
      
\endverbatim
*/
class PLMXML_MPM60_API OperationRevision : public StructureRevision
{
public:
     
    //! Default constructor
    OperationRevision( );
     
    //! Constructs a OperationRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OperationRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OperationRevision();

private:

	//! Assignment operator
	OperationRevision& operator=( const OperationRevision& iSrc );

	//! Copy constructor
	OperationRevision( const OperationRevision& original );
     
public:

	//! Get Activity URI as plmxml_api::String
	plmxml_api::String GetActivityURI() const;

	//! Set Activity URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetActivityURI( const plmxml_api::String& );
	
	//! Get the handle of Activity URI. Does not resolve the URI.
	plmxml_api::Result GetActivityURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Activity URI. URI string is unchanged.
	plmxml_api::Result SetActivityURI( const plmxml_api::Handle& );
	
	//! Resolve Activity URI and return an object (handle) it points to.
	plmxml_api::Result ResolveActivityURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Activity URI. Clears URI string and handle.
	plmxml_api::Result DeleteActivityURI();
	
	//! Check if Activity URI is set
	plmxml_api::logical HasActivityURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderOperationRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassOperationRevision;


////////////////////////////////////////////////////////////////////////////////////
//! Process class
/*!
\verbatim

      A Process is a subclass of Structure representing a Manufacturing Process.
      
\endverbatim
*/
class PLMXML_MPM60_API Process : public Structure
{
public:
     
    //! Default constructor
    Process( );
     
    //! Constructs a Process with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Process( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Process();

private:

	//! Assignment operator
	Process& operator=( const Process& iSrc );

	//! Copy constructor
	Process( const Process& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcess" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcess;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessRevision class
/*!
\verbatim

      A Revision of a Process
    
      Attributes
    
      productRefs:  
      plantRefs:
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessRevision : public StructureRevision
{
public:
     
    //! Default constructor
    ProcessRevision( );
     
    //! Constructs a ProcessRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessRevision();

private:

	//! Assignment operator
	ProcessRevision& operator=( const ProcessRevision& iSrc );

	//! Copy constructor
	ProcessRevision( const ProcessRevision& original );
     
public:

	//! Get number of URIs in Plant
	int NumberOfPlantURIs() const;

	//! Get i'th URI in Plant
	plmxml_api::String GetPlantURI( int i ) const;

	//! Add a URI to Plant array. Call ResolvePlantURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPlantURI( const plmxml_api::String& u );

	//! Set i'th URI in Plant array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPlantURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Plant URI. Does not resolve the URI.
	plmxml_api::Result GetPlantURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Plant array.
	plmxml_api::Result AddPlantURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Plant array to point to 'handle'.
	plmxml_api::Result SetPlantURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Plant points to.
	plmxml_api::Result ResolvePlantURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Plant array.
	plmxml_api::Result DeletePlantURI( int i );

	//! Remove all URIs from Plant array.
	plmxml_api::Result DeletePlantURIs( );
	
	//! Check if Plant is set
	plmxml_api::logical HasPlantURIs( ) const;

	//! Get number of URIs in Product
	int NumberOfProductURIs() const;

	//! Get i'th URI in Product
	plmxml_api::String GetProductURI( int i ) const;

	//! Add a URI to Product array. Call ResolveProductURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddProductURI( const plmxml_api::String& u );

	//! Set i'th URI in Product array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetProductURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Product URI. Does not resolve the URI.
	plmxml_api::Result GetProductURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Product array.
	plmxml_api::Result AddProductURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Product array to point to 'handle'.
	plmxml_api::Result SetProductURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Product points to.
	plmxml_api::Result ResolveProductURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Product array.
	plmxml_api::Result DeleteProductURI( int i );

	//! Remove all URIs from Product array.
	plmxml_api::Result DeleteProductURIs( );
	
	//! Check if Product is set
	plmxml_api::logical HasProductURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderProcessRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessRevision;


//! Forward class declarations
class ConfiguredActivity;
class LogicalAssignment;
class ManufacturingConstraint;

////////////////////////////////////////////////////////////////////////////////////
//! ProcessView class
/*!
\verbatim

      ProcessView. This is a collection of Occurrences.
	   
      Attributes:
                           
      definition:     how the ProcessView is defined. 

      usage:          This optional attribute specifies the intent of the ProcessView. 
                      
      rootRefs:       specifies the root Occurrences, i.e. those which are not children
                      of other Occurrences in this ProcessView.
                      
      primaryOccurrenceRef: (deprecated). Used when there is only one root Occurrence.                
       
      SubElements:
      
      Occurrence:           Occurrences in the ProcessView.
      ConfiguredOccurrenceGroup: ConfiguredOccurrenceGroups in the ProcessView
      Transform:            Transforms which may be referenced by the Occurrences.
      LogicalAssignment: ProductLogicalAssignments or ToolRequirements in the
                        ProcessView.
      ManufacturingConstraint: PrecedenceConstraints in the ProcessView.
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessView : public ConfigurationView
{
public:
     
    //! Default constructor
    ProcessView( );
     
    //! Constructs a ProcessView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessView();

private:

	//! Assignment operator
	ProcessView& operator=( const ProcessView& iSrc );

	//! Copy constructor
	ProcessView( const ProcessView& original );
     
public:

	//! Set Definition
	plmxml_api::Result SetDefinition( const plmxml60::eProductViewDefinitionType& arg );

	//! Get Definition
	plmxml60::eProductViewDefinitionType GetDefinition() const;

	//! Get number of references in Root array
	int NumberOfRootRefs() const;
     
	//! Add reference to 'arg' to Root array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddRootRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Root array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddRootId( const plmxml_api::String &u );
     
	//! Set i'th reference in Root array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRootRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Root array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRootId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Root array and return an object it points to.
	plmxml60::IdObject *ResolveRootRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Root array and return objects they point to.
	void ResolveRootRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Root array as plmxml_api::String
	plmxml_api::String GetRootId( int i ) const;
     
	//! Get all references in Root array as an array of plmxml_api::String
	void GetRootIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Root array.
	void RemoveRootRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Root array.
	void RemoveRootRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Root array.
	void RemoveRootRef( plmxml60::IdObject *arg );
     
	//! Remove all references Root array.
	void RemoveRootRefs();
	
	//! Check if Root is set
	plmxml_api::logical HasRootRefs( ) const;

	//! Set reference to PrimaryOccurrence using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetPrimaryOccurrenceRef( plmxml60::IdObject *arg );

	//! Clear reference to PrimaryOccurrence
	void RemovePrimaryOccurrenceRef( );

	//! Find a plmxml60::IdObject referenced by PrimaryOccurrence
	plmxml60::IdObject *ResolvePrimaryOccurrenceRef( plmxml_api::Configuration* config = NULL );

	//! Get PrimaryOccurrence reference
	plmxml_api::String GetPrimaryOccurrenceId() const;

	//! Set PrimaryOccurrence reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetPrimaryOccurrenceId( const plmxml_api::String& u );
	
	//! Check if PrimaryOccurrence is set
	plmxml_api::logical HasPrimaryOccurrenceRef( ) const;

	//! Set Usage
	plmxml_api::Result SetUsage( const plmxml60::eProductViewUsageType& arg );

	//! Get Usage
	plmxml60::eProductViewUsageType GetUsage() const;

	//! Add ConfiguredActivity child element to this ProcessView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConfiguredActivity *AddConfiguredActivity();
     
	//! Add 'arg' as ConfiguredActivity child element to this ProcessView.
	plmxml_api::Result AddConfiguredActivity( ConfiguredActivity *arg );

	//! Detach and delete all ConfiguredActivity child elements.
	void DeleteConfiguredActivities();
     
	//! Get number of ConfiguredActivity child elements.
	int NumberOfConfiguredActivities() const;
     
	//! Get i'th ConfiguredActivity child element.
	ConfiguredActivity *GetConfiguredActivity( int i ) const;
     
	//! Get all ConfiguredActivity child element as an array
	void GetConfiguredActivities( plmxml_api::Array<ConfiguredActivity*> &array ) const;
	     
	//! Detach and delete i'th ConfiguredActivity child element
	void DeleteConfiguredActivity( int i );
     
	//! Detach and delete 'arg' if it's one of the ConfiguredActivity child elements
	void DeleteConfiguredActivity( ConfiguredActivity *arg );

	//! Add Occurrence child element to this ProcessView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Occurrence *AddOccurrence();
     
	//! Add 'arg' as Occurrence child element to this ProcessView.
	plmxml_api::Result AddOccurrence( Occurrence *arg );

	//! Detach and delete all Occurrence child elements.
	void DeleteOccurrences();
     
	//! Get number of Occurrence child elements.
	int NumberOfOccurrences() const;
     
	//! Get i'th Occurrence child element.
	Occurrence *GetOccurrence( int i ) const;
     
	//! Get all Occurrence child element as an array
	void GetOccurrences( plmxml_api::Array<Occurrence*> &array ) const;
	     
	//! Detach and delete i'th Occurrence child element
	void DeleteOccurrence( int i );
     
	//! Detach and delete 'arg' if it's one of the Occurrence child elements
	void DeleteOccurrence( Occurrence *arg );

	//! Add ConfiguredOccurrenceGroup child element to this ProcessView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConfiguredOccurrenceGroup *AddConfiguredOccurrenceGroup();
     
	//! Add 'arg' as ConfiguredOccurrenceGroup child element to this ProcessView.
	plmxml_api::Result AddConfiguredOccurrenceGroup( ConfiguredOccurrenceGroup *arg );

	//! Detach and delete all ConfiguredOccurrenceGroup child elements.
	void DeleteConfiguredOccurrenceGroups();
     
	//! Get number of ConfiguredOccurrenceGroup child elements.
	int NumberOfConfiguredOccurrenceGroups() const;
     
	//! Get i'th ConfiguredOccurrenceGroup child element.
	ConfiguredOccurrenceGroup *GetConfiguredOccurrenceGroup( int i ) const;
     
	//! Get all ConfiguredOccurrenceGroup child element as an array
	void GetConfiguredOccurrenceGroups( plmxml_api::Array<ConfiguredOccurrenceGroup*> &array ) const;
	     
	//! Detach and delete i'th ConfiguredOccurrenceGroup child element
	void DeleteConfiguredOccurrenceGroup( int i );
     
	//! Detach and delete 'arg' if it's one of the ConfiguredOccurrenceGroup child elements
	void DeleteConfiguredOccurrenceGroup( ConfiguredOccurrenceGroup *arg );

	//! Add Transform child element to this ProcessView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Transform *AddTransform();
     
	//! Add 'arg' as Transform child element to this ProcessView.
	plmxml_api::Result AddTransform( Transform *arg );

	//! Detach and delete all Transform child elements.
	void DeleteTransforms();
     
	//! Get number of Transform child elements.
	int NumberOfTransforms() const;
     
	//! Get i'th Transform child element.
	Transform *GetTransform( int i ) const;
     
	//! Get all Transform child element as an array
	void GetTransforms( plmxml_api::Array<Transform*> &array ) const;
	     
	//! Detach and delete i'th Transform child element
	void DeleteTransform( int i );
     
	//! Detach and delete 'arg' if it's one of the Transform child elements
	void DeleteTransform( Transform *arg );

	//! Add LogicalAssignment child element to this ProcessView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	LogicalAssignment *AddLogicalAssignment();
     
	//! Add 'arg' as LogicalAssignment child element to this ProcessView.
	plmxml_api::Result AddLogicalAssignment( LogicalAssignment *arg );

	//! Detach and delete all LogicalAssignment child elements.
	void DeleteLogicalAssignments();
     
	//! Get number of LogicalAssignment child elements.
	int NumberOfLogicalAssignments() const;
     
	//! Get i'th LogicalAssignment child element.
	LogicalAssignment *GetLogicalAssignment( int i ) const;
     
	//! Get all LogicalAssignment child element as an array
	void GetLogicalAssignments( plmxml_api::Array<LogicalAssignment*> &array ) const;
	     
	//! Detach and delete i'th LogicalAssignment child element
	void DeleteLogicalAssignment( int i );
     
	//! Detach and delete 'arg' if it's one of the LogicalAssignment child elements
	void DeleteLogicalAssignment( LogicalAssignment *arg );

	//! Add ManufacturingConstraint child element to this ProcessView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ManufacturingConstraint *AddManufacturingConstraint();
     
	//! Add 'arg' as ManufacturingConstraint child element to this ProcessView.
	plmxml_api::Result AddManufacturingConstraint( ManufacturingConstraint *arg );

	//! Detach and delete all ManufacturingConstraint child elements.
	void DeleteManufacturingConstraints();
     
	//! Get number of ManufacturingConstraint child elements.
	int NumberOfManufacturingConstraints() const;
     
	//! Get i'th ManufacturingConstraint child element.
	ManufacturingConstraint *GetManufacturingConstraint( int i ) const;
     
	//! Get all ManufacturingConstraint child element as an array
	void GetManufacturingConstraints( plmxml_api::Array<ManufacturingConstraint*> &array ) const;
	     
	//! Detach and delete i'th ManufacturingConstraint child element
	void DeleteManufacturingConstraint( int i );
     
	//! Detach and delete 'arg' if it's one of the ManufacturingConstraint child elements
	void DeleteManufacturingConstraint( ManufacturingConstraint *arg );
 
// <PLMXML_UserCode type="functionHeaderProcessView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessView;


////////////////////////////////////////////////////////////////////////////////////
//! PlantView class
/*!
\verbatim

      PlantView. This is a collection of Occurrences of Parts within one
      Assembly, i.e. it selects certain Occurrences, for example in order to
      display them.

      All the root Occurrences (given by rootRefs) must
      have the same 'top Structure'. This is called the 'top Structure' of the 
      PlantView.
	   
      Attributes:
      
      definition:     how the PlantView is defined.
                           
      usage:          This optional attribute specifies the intent of the PlantView. 
                      
      rootRefs:       specifies the root Occurrences, i.e. those which are not children
                      of other Occurrences in this PlantView.
                     
      primaryOccurrenceRef: (deprecated). Used when there is only one root Occurrence.
       
      SubElements:
      
      Occurrence:           the Occurrences in the PlantView.
      ConfiguredOccurrenceGroup: ConfiguredOccurrenceGroups in the PlantView
      Transform:            Transforms which may be referenced by the Occurrences.
      
\endverbatim
*/
class PLMXML_MPM60_API PlantView : public ConfigurationView
{
public:
     
    //! Default constructor
    PlantView( );
     
    //! Constructs a PlantView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlantView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlantView();

private:

	//! Assignment operator
	PlantView& operator=( const PlantView& iSrc );

	//! Copy constructor
	PlantView( const PlantView& original );
     
public:

	//! Set Definition
	plmxml_api::Result SetDefinition( const plmxml60::eProductViewDefinitionType& arg );

	//! Get Definition
	plmxml60::eProductViewDefinitionType GetDefinition() const;

	//! Get number of references in Root array
	int NumberOfRootRefs() const;
     
	//! Add reference to 'arg' to Root array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddRootRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Root array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddRootId( const plmxml_api::String &u );
     
	//! Set i'th reference in Root array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRootRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Root array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRootId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Root array and return an object it points to.
	plmxml60::IdObject *ResolveRootRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Root array and return objects they point to.
	void ResolveRootRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Root array as plmxml_api::String
	plmxml_api::String GetRootId( int i ) const;
     
	//! Get all references in Root array as an array of plmxml_api::String
	void GetRootIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Root array.
	void RemoveRootRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Root array.
	void RemoveRootRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Root array.
	void RemoveRootRef( plmxml60::IdObject *arg );
     
	//! Remove all references Root array.
	void RemoveRootRefs();
	
	//! Check if Root is set
	plmxml_api::logical HasRootRefs( ) const;

	//! Set reference to PrimaryOccurrence using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetPrimaryOccurrenceRef( plmxml60::IdObject *arg );

	//! Clear reference to PrimaryOccurrence
	void RemovePrimaryOccurrenceRef( );

	//! Find a plmxml60::IdObject referenced by PrimaryOccurrence
	plmxml60::IdObject *ResolvePrimaryOccurrenceRef( plmxml_api::Configuration* config = NULL );

	//! Get PrimaryOccurrence reference
	plmxml_api::String GetPrimaryOccurrenceId() const;

	//! Set PrimaryOccurrence reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetPrimaryOccurrenceId( const plmxml_api::String& u );
	
	//! Check if PrimaryOccurrence is set
	plmxml_api::logical HasPrimaryOccurrenceRef( ) const;

	//! Set Usage
	plmxml_api::Result SetUsage( const plmxml60::eProductViewUsageType& arg );

	//! Get Usage
	plmxml60::eProductViewUsageType GetUsage() const;

	//! Add Occurrence child element to this PlantView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Occurrence *AddOccurrence();
     
	//! Add 'arg' as Occurrence child element to this PlantView.
	plmxml_api::Result AddOccurrence( Occurrence *arg );

	//! Detach and delete all Occurrence child elements.
	void DeleteOccurrences();
     
	//! Get number of Occurrence child elements.
	int NumberOfOccurrences() const;
     
	//! Get i'th Occurrence child element.
	Occurrence *GetOccurrence( int i ) const;
     
	//! Get all Occurrence child element as an array
	void GetOccurrences( plmxml_api::Array<Occurrence*> &array ) const;
	     
	//! Detach and delete i'th Occurrence child element
	void DeleteOccurrence( int i );
     
	//! Detach and delete 'arg' if it's one of the Occurrence child elements
	void DeleteOccurrence( Occurrence *arg );

	//! Add ConfiguredOccurrenceGroup child element to this PlantView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConfiguredOccurrenceGroup *AddConfiguredOccurrenceGroup();
     
	//! Add 'arg' as ConfiguredOccurrenceGroup child element to this PlantView.
	plmxml_api::Result AddConfiguredOccurrenceGroup( ConfiguredOccurrenceGroup *arg );

	//! Detach and delete all ConfiguredOccurrenceGroup child elements.
	void DeleteConfiguredOccurrenceGroups();
     
	//! Get number of ConfiguredOccurrenceGroup child elements.
	int NumberOfConfiguredOccurrenceGroups() const;
     
	//! Get i'th ConfiguredOccurrenceGroup child element.
	ConfiguredOccurrenceGroup *GetConfiguredOccurrenceGroup( int i ) const;
     
	//! Get all ConfiguredOccurrenceGroup child element as an array
	void GetConfiguredOccurrenceGroups( plmxml_api::Array<ConfiguredOccurrenceGroup*> &array ) const;
	     
	//! Detach and delete i'th ConfiguredOccurrenceGroup child element
	void DeleteConfiguredOccurrenceGroup( int i );
     
	//! Detach and delete 'arg' if it's one of the ConfiguredOccurrenceGroup child elements
	void DeleteConfiguredOccurrenceGroup( ConfiguredOccurrenceGroup *arg );

	//! Add Transform child element to this PlantView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Transform *AddTransform();
     
	//! Add 'arg' as Transform child element to this PlantView.
	plmxml_api::Result AddTransform( Transform *arg );

	//! Detach and delete all Transform child elements.
	void DeleteTransforms();
     
	//! Get number of Transform child elements.
	int NumberOfTransforms() const;
     
	//! Get i'th Transform child element.
	Transform *GetTransform( int i ) const;
     
	//! Get all Transform child element as an array
	void GetTransforms( plmxml_api::Array<Transform*> &array ) const;
	     
	//! Detach and delete i'th Transform child element
	void DeleteTransform( int i );
     
	//! Detach and delete 'arg' if it's one of the Transform child elements
	void DeleteTransform( Transform *arg );
 
// <PLMXML_UserCode type="functionHeaderPlantView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassPlantView;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessDef class
/*!
\verbatim

      ProcessDef is a container element for the Process Structure.
    
      Attributes:
    
      rootRefs:

      Sub-elements:
    
      ProcessInstance
      StructureRevision
      ProcessView
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessDef : public StructureDef
{
public:
     
    //! Default constructor
    ProcessDef( );
     
    //! Constructs a ProcessDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessDef();

private:

	//! Assignment operator
	ProcessDef& operator=( const ProcessDef& iSrc );

	//! Copy constructor
	ProcessDef( const ProcessDef& original );
     
public:

	//! Get number of references in Root array
	int NumberOfRootRefs() const;
     
	//! Add reference to 'arg' to Root array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddRootRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Root array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddRootId( const plmxml_api::String &u );
     
	//! Set i'th reference in Root array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetRootRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Root array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetRootId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Root array and return an object it points to.
	plmxml60::IdObject *ResolveRootRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Root array and return objects they point to.
	void ResolveRootRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Root array as plmxml_api::String
	plmxml_api::String GetRootId( int i ) const;
     
	//! Get all references in Root array as an array of plmxml_api::String
	void GetRootIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Root array.
	void RemoveRootRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Root array.
	void RemoveRootRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Root array.
	void RemoveRootRef( plmxml60::IdObject *arg );
     
	//! Remove all references Root array.
	void RemoveRootRefs();
	
	//! Check if Root is set
	plmxml_api::logical HasRootRefs( ) const;

	//! Add ProcessInstance child element to this ProcessDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ProcessInstance *AddProcessInstance();
     
	//! Add 'arg' as ProcessInstance child element to this ProcessDef.
	plmxml_api::Result AddProcessInstance( ProcessInstance *arg );

	//! Detach and delete all ProcessInstance child elements.
	void DeleteProcessInstances();
     
	//! Get number of ProcessInstance child elements.
	int NumberOfProcessInstances() const;
     
	//! Get i'th ProcessInstance child element.
	ProcessInstance *GetProcessInstance( int i ) const;
     
	//! Get all ProcessInstance child element as an array
	void GetProcessInstances( plmxml_api::Array<ProcessInstance*> &array ) const;
	     
	//! Detach and delete i'th ProcessInstance child element
	void DeleteProcessInstance( int i );
     
	//! Detach and delete 'arg' if it's one of the ProcessInstance child elements
	void DeleteProcessInstance( ProcessInstance *arg );

	//! Add StructureRevision child element to this ProcessDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StructureRevision *AddStructureRevision();
     
	//! Add 'arg' as StructureRevision child element to this ProcessDef.
	plmxml_api::Result AddStructureRevision( StructureRevision *arg );

	//! Detach and delete all StructureRevision child elements.
	void DeleteStructureRevisions();
     
	//! Get number of StructureRevision child elements.
	int NumberOfStructureRevisions() const;
     
	//! Get i'th StructureRevision child element.
	StructureRevision *GetStructureRevision( int i ) const;
     
	//! Get all StructureRevision child element as an array
	void GetStructureRevisions( plmxml_api::Array<StructureRevision*> &array ) const;
	     
	//! Detach and delete i'th StructureRevision child element
	void DeleteStructureRevision( int i );
     
	//! Detach and delete 'arg' if it's one of the StructureRevision child elements
	void DeleteStructureRevision( StructureRevision *arg );

	//! Add ProcessView child element to this ProcessDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ProcessView *AddProcessView();
     
	//! Add 'arg' as ProcessView child element to this ProcessDef.
	plmxml_api::Result AddProcessView( ProcessView *arg );

	//! Detach and delete all ProcessView child elements.
	void DeleteProcessViews();
     
	//! Get number of ProcessView child elements.
	int NumberOfProcessViews() const;
     
	//! Get i'th ProcessView child element.
	ProcessView *GetProcessView( int i ) const;
     
	//! Get all ProcessView child element as an array
	void GetProcessViews( plmxml_api::Array<ProcessView*> &array ) const;
	     
	//! Detach and delete i'th ProcessView child element
	void DeleteProcessView( int i );
     
	//! Detach and delete 'arg' if it's one of the ProcessView child elements
	void DeleteProcessView( ProcessView *arg );
 
// <PLMXML_UserCode type="functionHeaderProcessDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessDef;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessRevisionView class
/*!
\verbatim

      A 'View' of a ProcessRevision.
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessRevisionView : public StructureRevisionView
{
public:
     
    //! Default constructor
    ProcessRevisionView( );
     
    //! Constructs a ProcessRevisionView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessRevisionView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessRevisionView();

private:

	//! Assignment operator
	ProcessRevisionView& operator=( const ProcessRevisionView& iSrc );

	//! Copy constructor
	ProcessRevisionView( const ProcessRevisionView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcessRevisionView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessRevisionView;


////////////////////////////////////////////////////////////////////////////////////
//! PlantDef class
/*!
\verbatim

      PlantDef differs from ProductDef as it has the concept of stationFlow.
    
      Attributes:
    
      rootRefs:
    
      Sub-elements:
    
      PlantView:
      WorkAreaInstance:  
      WorkAreaRevision:  
      
\endverbatim
*/
class PLMXML_MPM60_API PlantDef : public StructureDef
{
public:
     
    //! Default constructor
    PlantDef( );
     
    //! Constructs a PlantDef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlantDef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlantDef();

private:

	//! Assignment operator
	PlantDef& operator=( const PlantDef& iSrc );

	//! Copy constructor
	PlantDef( const PlantDef& original );
     
public:

	//! Get number of URIs in Root
	int NumberOfRootURIs() const;

	//! Get i'th URI in Root
	plmxml_api::String GetRootURI( int i ) const;

	//! Add a URI to Root array. Call ResolveRootURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddRootURI( const plmxml_api::String& u );

	//! Set i'th URI in Root array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetRootURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Root URI. Does not resolve the URI.
	plmxml_api::Result GetRootURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Root array.
	plmxml_api::Result AddRootURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Root array to point to 'handle'.
	plmxml_api::Result SetRootURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Root points to.
	plmxml_api::Result ResolveRootURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Root array.
	plmxml_api::Result DeleteRootURI( int i );

	//! Remove all URIs from Root array.
	plmxml_api::Result DeleteRootURIs( );
	
	//! Check if Root is set
	plmxml_api::logical HasRootURIs( ) const;

	//! Add WorkAreaInstance child element to this PlantDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	WorkAreaInstance *AddWorkAreaInstance();
     
	//! Add 'arg' as WorkAreaInstance child element to this PlantDef.
	plmxml_api::Result AddWorkAreaInstance( WorkAreaInstance *arg );

	//! Detach and delete all WorkAreaInstance child elements.
	void DeleteWorkAreaInstances();
     
	//! Get number of WorkAreaInstance child elements.
	int NumberOfWorkAreaInstances() const;
     
	//! Get i'th WorkAreaInstance child element.
	WorkAreaInstance *GetWorkAreaInstance( int i ) const;
     
	//! Get all WorkAreaInstance child element as an array
	void GetWorkAreaInstances( plmxml_api::Array<WorkAreaInstance*> &array ) const;
	     
	//! Detach and delete i'th WorkAreaInstance child element
	void DeleteWorkAreaInstance( int i );
     
	//! Detach and delete 'arg' if it's one of the WorkAreaInstance child elements
	void DeleteWorkAreaInstance( WorkAreaInstance *arg );

	//! Add WorkAreaRevision child element to this PlantDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	WorkAreaRevision *AddWorkAreaRevision();
     
	//! Add 'arg' as WorkAreaRevision child element to this PlantDef.
	plmxml_api::Result AddWorkAreaRevision( WorkAreaRevision *arg );

	//! Detach and delete all WorkAreaRevision child elements.
	void DeleteWorkAreaRevisions();
     
	//! Get number of WorkAreaRevision child elements.
	int NumberOfWorkAreaRevisions() const;
     
	//! Get i'th WorkAreaRevision child element.
	WorkAreaRevision *GetWorkAreaRevision( int i ) const;
     
	//! Get all WorkAreaRevision child element as an array
	void GetWorkAreaRevisions( plmxml_api::Array<WorkAreaRevision*> &array ) const;
	     
	//! Detach and delete i'th WorkAreaRevision child element
	void DeleteWorkAreaRevision( int i );
     
	//! Detach and delete 'arg' if it's one of the WorkAreaRevision child elements
	void DeleteWorkAreaRevision( WorkAreaRevision *arg );

	//! Add PlantView child element to this PlantDef. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PlantView *AddPlantView();
     
	//! Add 'arg' as PlantView child element to this PlantDef.
	plmxml_api::Result AddPlantView( PlantView *arg );

	//! Detach and delete all PlantView child elements.
	void DeletePlantViews();
     
	//! Get number of PlantView child elements.
	int NumberOfPlantViews() const;
     
	//! Get i'th PlantView child element.
	PlantView *GetPlantView( int i ) const;
     
	//! Get all PlantView child element as an array
	void GetPlantViews( plmxml_api::Array<PlantView*> &array ) const;
	     
	//! Detach and delete i'th PlantView child element
	void DeletePlantView( int i );
     
	//! Detach and delete 'arg' if it's one of the PlantView child elements
	void DeletePlantView( PlantView *arg );
 
// <PLMXML_UserCode type="functionHeaderPlantDef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassPlantDef;


////////////////////////////////////////////////////////////////////////////////////
//! PlantRevisionView class
/*!
\verbatim

      A 'View' of a WorkAreaRevision. 
    
      For legacy reasons this is called a PlantRevisionView, not a WorkAreaRevisionView.
      
\endverbatim
*/
class PLMXML_MPM60_API PlantRevisionView : public StructureRevisionView
{
public:
     
    //! Default constructor
    PlantRevisionView( );
     
    //! Constructs a PlantRevisionView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlantRevisionView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlantRevisionView();

private:

	//! Assignment operator
	PlantRevisionView& operator=( const PlantRevisionView& iSrc );

	//! Copy constructor
	PlantRevisionView( const PlantRevisionView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderPlantRevisionView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassPlantRevisionView;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessStructureView class
/*!
\verbatim

      This element represents a View of a Process, e.g. 'design' View.
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessStructureView : public StructureView
{
public:
     
    //! Default constructor
    ProcessStructureView( );
     
    //! Constructs a ProcessStructureView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessStructureView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessStructureView();

private:

	//! Assignment operator
	ProcessStructureView& operator=( const ProcessStructureView& iSrc );

	//! Copy constructor
	ProcessStructureView( const ProcessStructureView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProcessStructureView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessStructureView;


////////////////////////////////////////////////////////////////////////////////////
//! WorkAreaStructureView class
/*!
\verbatim

      This element represents a View of a WorkArea, e.g. 'design' View.
      
\endverbatim
*/
class PLMXML_MPM60_API WorkAreaStructureView : public StructureView
{
public:
     
    //! Default constructor
    WorkAreaStructureView( );
     
    //! Constructs a WorkAreaStructureView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkAreaStructureView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkAreaStructureView();

private:

	//! Assignment operator
	WorkAreaStructureView& operator=( const WorkAreaStructureView& iSrc );

	//! Copy constructor
	WorkAreaStructureView( const WorkAreaStructureView& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderWorkAreaStructureView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassWorkAreaStructureView;


////////////////////////////////////////////////////////////////////////////////////
//! ProcessOccurrence class
/*!
\verbatim

      This is a derived class of Occurrence, specific to Process Structure.
      
      Attributes:
      
      predecessorRefs:            list of predecessor ProcessOccurrences
      configuredActivityRootRef:
      originRef:        References the origin ProcessOccurrence. When the
                        ProcessOccurrence represents a Context, originRef
                        references its origin Context.
      logicalAssignmentRefs: References one or more Logical Assignments.
      constraintRefs:   References one or more Manufacturing Constraints.
      
\endverbatim
*/
class PLMXML_MPM60_API ProcessOccurrence : public Occurrence
{
public:
     
    //! Default constructor
    ProcessOccurrence( );
     
    //! Constructs a ProcessOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProcessOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProcessOccurrence();

private:

	//! Assignment operator
	ProcessOccurrence& operator=( const ProcessOccurrence& iSrc );

	//! Copy constructor
	ProcessOccurrence( const ProcessOccurrence& original );
     
public:

	//! Get number of URIs in LogicalAssignment
	int NumberOfLogicalAssignmentURIs() const;

	//! Get i'th URI in LogicalAssignment
	plmxml_api::String GetLogicalAssignmentURI( int i ) const;

	//! Add a URI to LogicalAssignment array. Call ResolveLogicalAssignmentURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddLogicalAssignmentURI( const plmxml_api::String& u );

	//! Set i'th URI in LogicalAssignment array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetLogicalAssignmentURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of LogicalAssignment URI. Does not resolve the URI.
	plmxml_api::Result GetLogicalAssignmentURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to LogicalAssignment array.
	plmxml_api::Result AddLogicalAssignmentURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in LogicalAssignment array to point to 'handle'.
	plmxml_api::Result SetLogicalAssignmentURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in LogicalAssignment points to.
	plmxml_api::Result ResolveLogicalAssignmentURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from LogicalAssignment array.
	plmxml_api::Result DeleteLogicalAssignmentURI( int i );

	//! Remove all URIs from LogicalAssignment array.
	plmxml_api::Result DeleteLogicalAssignmentURIs( );
	
	//! Check if LogicalAssignment is set
	plmxml_api::logical HasLogicalAssignmentURIs( ) const;

	//! Get Origin URI as plmxml_api::String
	plmxml_api::String GetOriginURI() const;

	//! Set Origin URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOriginURI( const plmxml_api::String& );
	
	//! Get the handle of Origin URI. Does not resolve the URI.
	plmxml_api::Result GetOriginURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Origin URI. URI string is unchanged.
	plmxml_api::Result SetOriginURI( const plmxml_api::Handle& );
	
	//! Resolve Origin URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOriginURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Origin URI. Clears URI string and handle.
	plmxml_api::Result DeleteOriginURI();
	
	//! Check if Origin URI is set
	plmxml_api::logical HasOriginURI( ) const;
	

	//! Get ConfiguredActivityRoot URI as plmxml_api::String
	plmxml_api::String GetConfiguredActivityRootURI() const;

	//! Set ConfiguredActivityRoot URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetConfiguredActivityRootURI( const plmxml_api::String& );
	
	//! Get the handle of ConfiguredActivityRoot URI. Does not resolve the URI.
	plmxml_api::Result GetConfiguredActivityRootURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of ConfiguredActivityRoot URI. URI string is unchanged.
	plmxml_api::Result SetConfiguredActivityRootURI( const plmxml_api::Handle& );
	
	//! Resolve ConfiguredActivityRoot URI and return an object (handle) it points to.
	plmxml_api::Result ResolveConfiguredActivityRootURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset ConfiguredActivityRoot URI. Clears URI string and handle.
	plmxml_api::Result DeleteConfiguredActivityRootURI();
	
	//! Check if ConfiguredActivityRoot URI is set
	plmxml_api::logical HasConfiguredActivityRootURI( ) const;
	

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

	//! Get number of URIs in Constraint
	int NumberOfConstraintURIs() const;

	//! Get i'th URI in Constraint
	plmxml_api::String GetConstraintURI( int i ) const;

	//! Add a URI to Constraint array. Call ResolveConstraintURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddConstraintURI( const plmxml_api::String& u );

	//! Set i'th URI in Constraint array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetConstraintURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Constraint URI. Does not resolve the URI.
	plmxml_api::Result GetConstraintURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Constraint array.
	plmxml_api::Result AddConstraintURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Constraint array to point to 'handle'.
	plmxml_api::Result SetConstraintURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Constraint points to.
	plmxml_api::Result ResolveConstraintURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Constraint array.
	plmxml_api::Result DeleteConstraintURI( int i );

	//! Remove all URIs from Constraint array.
	plmxml_api::Result DeleteConstraintURIs( );
	
	//! Check if Constraint is set
	plmxml_api::logical HasConstraintURIs( ) const;
 
// <PLMXML_UserCode type="functionHeaderProcessOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProcessOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! WorkAreaOccurrence class
/*!
\verbatim

      This is a derived class of Occurrence, specific to WorkArea Structure.
      
      Attributes:
      
      predecessorRefs:            list of predecessor WorkAreaOccurrences
      
\endverbatim
*/
class PLMXML_MPM60_API WorkAreaOccurrence : public Occurrence
{
public:
     
    //! Default constructor
    WorkAreaOccurrence( );
     
    //! Constructs a WorkAreaOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    WorkAreaOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~WorkAreaOccurrence();

private:

	//! Assignment operator
	WorkAreaOccurrence& operator=( const WorkAreaOccurrence& iSrc );

	//! Copy constructor
	WorkAreaOccurrence( const WorkAreaOccurrence& original );
     
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
 
// <PLMXML_UserCode type="functionHeaderWorkAreaOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassWorkAreaOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! ConfiguredActivity class
/*!
\verbatim

      This is a derived class of AssociatedAttachment, and represents a Configured
      Activity.
      
      Attributes:
      
      predecessorRefs:            list of predecessor ConfiguredActivity elements
      
\endverbatim
*/
class PLMXML_MPM60_API ConfiguredActivity : public AssociatedAttachment
{
public:
     
    //! Default constructor
    ConfiguredActivity( );
     
    //! Constructs a ConfiguredActivity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConfiguredActivity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConfiguredActivity();

private:

	//! Assignment operator
	ConfiguredActivity& operator=( const ConfiguredActivity& iSrc );

	//! Copy constructor
	ConfiguredActivity( const ConfiguredActivity& original );
     
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
 
// <PLMXML_UserCode type="functionHeaderConfiguredActivity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassConfiguredActivity;


////////////////////////////////////////////////////////////////////////////////////
//! LogicalAssignment class
/*!
\verbatim

      Logical assignment (abstract).

      Attributes:

      subType:          Indicates the sub-type of a customized Logical
                        Assignment.
      subTypeRef:       References a multiple language version of subType. If
                        multiple language support is required, subTypeRef should
                        be used in addition to subType.
      assignmentType:   The type of relationship between the Process Structure
                        element and the Product Structure Occurrences.
      assignmentTypeRef: References a multiple language version of
                        assignmentType. If multiple language support is
                        required, assignmentTypeRef should be used in addition
                        to assignmentType.
      assignmentRefs:   References to the Occurrences representing the
                        assignments.
      criteriaRef:      References a SetFilter or a ClassFilter that represents
                        the search criteria.
      
\endverbatim
*/
class PLMXML_MPM60_API LogicalAssignment : public AttribOwner
{
public:
     
    //! Default constructor
    LogicalAssignment( );
     
    //! Constructs a LogicalAssignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LogicalAssignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LogicalAssignment();

private:

	//! Assignment operator
	LogicalAssignment& operator=( const LogicalAssignment& iSrc );

	//! Copy constructor
	LogicalAssignment( const LogicalAssignment& original );
     
public:

	//! Get AssignmentType URI as plmxml_api::String
	plmxml_api::String GetAssignmentTypeURI() const;

	//! Set AssignmentType URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAssignmentTypeURI( const plmxml_api::String& );
	
	//! Get the handle of AssignmentType URI. Does not resolve the URI.
	plmxml_api::Result GetAssignmentTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of AssignmentType URI. URI string is unchanged.
	plmxml_api::Result SetAssignmentTypeURI( const plmxml_api::Handle& );
	
	//! Resolve AssignmentType URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAssignmentTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset AssignmentType URI. Clears URI string and handle.
	plmxml_api::Result DeleteAssignmentTypeURI();
	
	//! Check if AssignmentType URI is set
	plmxml_api::logical HasAssignmentTypeURI( ) const;
	

	//! Get AssignmentType of this LogicalAssignment
	plmxml_api::String GetAssignmentType() const;

	//! Set AssignmentType of this LogicalAssignment
	plmxml_api::Result SetAssignmentType( const plmxml_api::String &s );
	
	//! Check if AssignmentType is set
	plmxml_api::logical HasAssignmentType( ) const;
	
	//! Unset AssignmentType
	plmxml_api::Result UnsetAssignmentType( );

	//! Get SubType of this LogicalAssignment
	plmxml_api::String GetSubType() const;

	//! Set SubType of this LogicalAssignment
	plmxml_api::Result SetSubType( const plmxml_api::String &s );
	
	//! Check if SubType is set
	plmxml_api::logical HasSubType( ) const;
	
	//! Unset SubType
	plmxml_api::Result UnsetSubType( );

	//! Get number of URIs in Assignment
	int NumberOfAssignmentURIs() const;

	//! Get i'th URI in Assignment
	plmxml_api::String GetAssignmentURI( int i ) const;

	//! Add a URI to Assignment array. Call ResolveAssignmentURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAssignmentURI( const plmxml_api::String& u );

	//! Set i'th URI in Assignment array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAssignmentURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Assignment URI. Does not resolve the URI.
	plmxml_api::Result GetAssignmentURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Assignment array.
	plmxml_api::Result AddAssignmentURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Assignment array to point to 'handle'.
	plmxml_api::Result SetAssignmentURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Assignment points to.
	plmxml_api::Result ResolveAssignmentURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Assignment array.
	plmxml_api::Result DeleteAssignmentURI( int i );

	//! Remove all URIs from Assignment array.
	plmxml_api::Result DeleteAssignmentURIs( );
	
	//! Check if Assignment is set
	plmxml_api::logical HasAssignmentURIs( ) const;

	//! Get Criteria URI as plmxml_api::String
	plmxml_api::String GetCriteriaURI() const;

	//! Set Criteria URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetCriteriaURI( const plmxml_api::String& );
	
	//! Get the handle of Criteria URI. Does not resolve the URI.
	plmxml_api::Result GetCriteriaURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Criteria URI. URI string is unchanged.
	plmxml_api::Result SetCriteriaURI( const plmxml_api::Handle& );
	
	//! Resolve Criteria URI and return an object (handle) it points to.
	plmxml_api::Result ResolveCriteriaURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Criteria URI. Clears URI string and handle.
	plmxml_api::Result DeleteCriteriaURI();
	
	//! Check if Criteria URI is set
	plmxml_api::logical HasCriteriaURI( ) const;
	

	//! Get SubType URI as plmxml_api::String
	plmxml_api::String GetSubTypeURI() const;

	//! Set SubType URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSubTypeURI( const plmxml_api::String& );
	
	//! Get the handle of SubType URI. Does not resolve the URI.
	plmxml_api::Result GetSubTypeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of SubType URI. URI string is unchanged.
	plmxml_api::Result SetSubTypeURI( const plmxml_api::Handle& );
	
	//! Resolve SubType URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSubTypeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset SubType URI. Clears URI string and handle.
	plmxml_api::Result DeleteSubTypeURI();
	
	//! Check if SubType URI is set
	plmxml_api::logical HasSubTypeURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderLogicalAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassLogicalAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! ProductLogicalAssignment class
/*!
\verbatim

      Product logical assignment.
      
\endverbatim
*/
class PLMXML_MPM60_API ProductLogicalAssignment : public LogicalAssignment
{
public:
     
    //! Default constructor
    ProductLogicalAssignment( );
     
    //! Constructs a ProductLogicalAssignment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProductLogicalAssignment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProductLogicalAssignment();

private:

	//! Assignment operator
	ProductLogicalAssignment& operator=( const ProductLogicalAssignment& iSrc );

	//! Copy constructor
	ProductLogicalAssignment( const ProductLogicalAssignment& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderProductLogicalAssignment" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassProductLogicalAssignment;


////////////////////////////////////////////////////////////////////////////////////
//! ToolRequirement class
/*!
\verbatim

      Tool requirement.
      
\endverbatim
*/
class PLMXML_MPM60_API ToolRequirement : public LogicalAssignment
{
public:
     
    //! Default constructor
    ToolRequirement( );
     
    //! Constructs a ToolRequirement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ToolRequirement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ToolRequirement();

private:

	//! Assignment operator
	ToolRequirement& operator=( const ToolRequirement& iSrc );

	//! Copy constructor
	ToolRequirement( const ToolRequirement& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderToolRequirement" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassToolRequirement;


////////////////////////////////////////////////////////////////////////////////////
//! ManufacturingConstraint class
/*!
\verbatim

      Manufacturing constraint (abstract).
      
\endverbatim
*/
class PLMXML_MPM60_API ManufacturingConstraint : public AttribOwner
{
public:
     
    //! Default constructor
    ManufacturingConstraint( );
     
    //! Constructs a ManufacturingConstraint with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ManufacturingConstraint( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ManufacturingConstraint();

private:

	//! Assignment operator
	ManufacturingConstraint& operator=( const ManufacturingConstraint& iSrc );

	//! Copy constructor
	ManufacturingConstraint( const ManufacturingConstraint& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderManufacturingConstraint" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassManufacturingConstraint;


////////////////////////////////////////////////////////////////////////////////////
//! PrecedenceConstraint class
/*!
\verbatim

      Precedence constraint.

      Attributes:

      implicit:         Whether the PrecedenceConstraint is real (false) or was
                        just calculated when exported (true).
      predecessorRef:   References the predecessor ProcessOccurrence.
      successorRef:     References the successor ProcessOccurrence.
      
\endverbatim
*/
class PLMXML_MPM60_API PrecedenceConstraint : public ManufacturingConstraint
{
public:
     
    //! Default constructor
    PrecedenceConstraint( );
     
    //! Constructs a PrecedenceConstraint with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PrecedenceConstraint( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PrecedenceConstraint();

private:

	//! Assignment operator
	PrecedenceConstraint& operator=( const PrecedenceConstraint& iSrc );

	//! Copy constructor
	PrecedenceConstraint( const PrecedenceConstraint& original );
     
public:

	//! Get Predecessor URI as plmxml_api::String
	plmxml_api::String GetPredecessorURI() const;

	//! Set Predecessor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPredecessorURI( const plmxml_api::String& );
	
	//! Get the handle of Predecessor URI. Does not resolve the URI.
	plmxml_api::Result GetPredecessorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Predecessor URI. URI string is unchanged.
	plmxml_api::Result SetPredecessorURI( const plmxml_api::Handle& );
	
	//! Resolve Predecessor URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePredecessorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Predecessor URI. Clears URI string and handle.
	plmxml_api::Result DeletePredecessorURI();
	
	//! Check if Predecessor URI is set
	plmxml_api::logical HasPredecessorURI( ) const;
	

	//! Set Implicit
	plmxml_api::Result SetImplicit( plmxml_api::logical arg );

	//! Get Implicit
	plmxml_api::logical GetImplicit() const;

	//! Check if Implicit is set
	plmxml_api::logical HasImplicit() const;

	//! Unset Implicit
	plmxml_api::Result UnsetImplicit();

	//! Get Successor URI as plmxml_api::String
	plmxml_api::String GetSuccessorURI() const;

	//! Set Successor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSuccessorURI( const plmxml_api::String& );
	
	//! Get the handle of Successor URI. Does not resolve the URI.
	plmxml_api::Result GetSuccessorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Successor URI. URI string is unchanged.
	plmxml_api::Result SetSuccessorURI( const plmxml_api::Handle& );
	
	//! Resolve Successor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSuccessorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Successor URI. Clears URI string and handle.
	plmxml_api::Result DeleteSuccessorURI();
	
	//! Check if Successor URI is set
	plmxml_api::logical HasSuccessorURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderPrecedenceConstraint" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_MPM60_API plmxml_api::plmxmlClass plmxmlClassPrecedenceConstraint;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
