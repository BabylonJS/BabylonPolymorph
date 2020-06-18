/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.23669 13/11/2017 14:35:22
// 
// Schema:	PLMXMLFDSchema.xsd
// Data:	13/11/2017 14:35:08
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_FD60_H__
#define __PLMXML_FD60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_FD60_EXPORTS
#define PLMXML_FD60_API __declspec(dllexport)
#else
#define PLMXML_FD60_API __declspec(dllimport)
#endif
#else
#define PLMXML_FD60_API
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
//! eHoleOrientationType class
/*!
Allowed Values:
\verbatim
  eHoleOrientationTypeCoaxial
	"coaxial"
  eHoleOrientationTypeNormalToEntrySurface
	"normalToEntrySurface"
  eHoleOrientationTypeNormalToPlacementPlane
	"normalToPlacementPlane"
  
\endverbatim
*/
class PLMXML_FD60_API eHoleOrientationType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eHoleOrientationType( const char* Type );
     
	//! Constructor
	eHoleOrientationType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eHoleOrientationType( );
     
	//! Destructor 
	virtual ~eHoleOrientationType( );
     
	//! Assign from 'Type'
	const eHoleOrientationType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eHoleOrientationType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare HoleOrientationType
	friend plmxml_api::logical PLMXML_FD60_API operator==( const eHoleOrientationType& e1, const eHoleOrientationType& e2 );
     
	//! Compare HoleOrientationType
	friend plmxml_api::logical PLMXML_FD60_API operator!=( const eHoleOrientationType& e1, const eHoleOrientationType& e2 );
};
extern PLMXML_FD60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumHoleOrientationType;
extern PLMXML_FD60_API eHoleOrientationType eHoleOrientationTypeUnset;
extern PLMXML_FD60_API eHoleOrientationType eHoleOrientationTypeCoaxial;
extern PLMXML_FD60_API eHoleOrientationType eHoleOrientationTypeNormalToEntrySurface;
extern PLMXML_FD60_API eHoleOrientationType eHoleOrientationTypeNormalToPlacementPlane;

////////////////////////////////////////////////////////////////////////////////////
//! eThreadEntrySettingType class
/*!
Allowed Values:
\verbatim
  eThreadEntrySettingTypeStandard
	"standard"
  eThreadEntrySettingTypeStraightPipe
	"straightPipe"
  eThreadEntrySettingTypeTaperedPipe
	"taperedPipe"
  
\endverbatim
*/
class PLMXML_FD60_API eThreadEntrySettingType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eThreadEntrySettingType( const char* Type );
     
	//! Constructor
	eThreadEntrySettingType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eThreadEntrySettingType( );
     
	//! Destructor 
	virtual ~eThreadEntrySettingType( );
     
	//! Assign from 'Type'
	const eThreadEntrySettingType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eThreadEntrySettingType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ThreadEntrySettingType
	friend plmxml_api::logical PLMXML_FD60_API operator==( const eThreadEntrySettingType& e1, const eThreadEntrySettingType& e2 );
     
	//! Compare ThreadEntrySettingType
	friend plmxml_api::logical PLMXML_FD60_API operator!=( const eThreadEntrySettingType& e1, const eThreadEntrySettingType& e2 );
};
extern PLMXML_FD60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumThreadEntrySettingType;
extern PLMXML_FD60_API eThreadEntrySettingType eThreadEntrySettingTypeUnset;
extern PLMXML_FD60_API eThreadEntrySettingType eThreadEntrySettingTypeStandard;
extern PLMXML_FD60_API eThreadEntrySettingType eThreadEntrySettingTypeStraightPipe;
extern PLMXML_FD60_API eThreadEntrySettingType eThreadEntrySettingTypeTaperedPipe;

////////////////////////////////////////////////////////////////////////////////////
//! eHoleExtentType class
/*!
Allowed Values:
\verbatim
  eHoleExtentTypeThroughNext
	"throughNext"
  eHoleExtentTypeThroughAll
	"throughAll"
  eHoleExtentTypeFinite
	"finite"
  eHoleExtentTypeFromTo
	"fromTo"
  
\endverbatim
*/
class PLMXML_FD60_API eHoleExtentType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eHoleExtentType( const char* Type );
     
	//! Constructor
	eHoleExtentType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eHoleExtentType( );
     
	//! Destructor 
	virtual ~eHoleExtentType( );
     
	//! Assign from 'Type'
	const eHoleExtentType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eHoleExtentType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare HoleExtentType
	friend plmxml_api::logical PLMXML_FD60_API operator==( const eHoleExtentType& e1, const eHoleExtentType& e2 );
     
	//! Compare HoleExtentType
	friend plmxml_api::logical PLMXML_FD60_API operator!=( const eHoleExtentType& e1, const eHoleExtentType& e2 );
};
extern PLMXML_FD60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumHoleExtentType;
extern PLMXML_FD60_API eHoleExtentType eHoleExtentTypeUnset;
extern PLMXML_FD60_API eHoleExtentType eHoleExtentTypeThroughNext;
extern PLMXML_FD60_API eHoleExtentType eHoleExtentTypeThroughAll;
extern PLMXML_FD60_API eHoleExtentType eHoleExtentTypeFinite;
extern PLMXML_FD60_API eHoleExtentType eHoleExtentTypeFromTo;

////////////////////////////////////////////////////////////////////////////////////
//! eThreadExtentType class
/*!
Allowed Values:
\verbatim
  eThreadExtentTypeToExtent
	"toExtent"
  eThreadExtentTypeFinite
	"finite"
  
\endverbatim
*/
class PLMXML_FD60_API eThreadExtentType : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eThreadExtentType( const char* Type );
     
	//! Constructor
	eThreadExtentType( const plmxml_api::String& Type );
     
	//! Default Constructor
	eThreadExtentType( );
     
	//! Destructor 
	virtual ~eThreadExtentType( );
     
	//! Assign from 'Type'
	const eThreadExtentType& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eThreadExtentType& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ThreadExtentType
	friend plmxml_api::logical PLMXML_FD60_API operator==( const eThreadExtentType& e1, const eThreadExtentType& e2 );
     
	//! Compare ThreadExtentType
	friend plmxml_api::logical PLMXML_FD60_API operator!=( const eThreadExtentType& e1, const eThreadExtentType& e2 );
};
extern PLMXML_FD60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumThreadExtentType;
extern PLMXML_FD60_API eThreadExtentType eThreadExtentTypeUnset;
extern PLMXML_FD60_API eThreadExtentType eThreadExtentTypeToExtent;
extern PLMXML_FD60_API eThreadExtentType eThreadExtentTypeFinite;

////////////////////////////////////////////////////////////////////////////////////
//! Thread class
/*!
\verbatim

      This element describes a Thread.

      Note: The thread defaults to right-handed.

      Attributes:

      type:             The type (standard) of thread. Some possible values are:
                          ANSI threads:      UNC, UNF, UNEF
                          ANSI pipe threads: NPSM, NPT
                          ISO threads:       M
                          ISO pipe threads:  Rp, Rc
                        This attribute is a string to allow custom standards.
      extent:           The extent type of the thread.
      length:           The length of the thread, if extent = "finite".
      offset:           The offset distance, from the start of the owning
                          feature, before the thread starts.
      nominalDiameter:  Nominal diameter, i.e. diameter of cylinder to which the
                          thread applies. 
      internalDiameter: The inside diameter of the extrapolated thread form.
      externalDiameter: The outside diameter of the extrapolated thread form.
                        For these three diameters we have:
                            internalDiameter .LT. nominalDiameter .LT.
                              externalDiameter
      designateDiameter: Designated diameter. This is a string, e.g. "M8".
      effectiveLength:  This is the length of the thread which is cut at full
                          depth.
      height:           The distance from the inside of the extrapolated thread
                        form to the outside of the extrapolated thread form.
      taperAngle:       The angle of taper, in radians. This is positive and
                          less than pi/2. The taper is always towards the
                          centreline, in the direction of the thread.
      pitch:            The distance between adjacent threads, measured along
                          the length of the thread, in metres (SI units).
      leftHanded:       Whether the thread is left-handed.
      majorDiameter:    The outside diameter of the thread.
      minorDiameter:    The inside diameter of the thread.
      angle:            The angle between adjacent threads in radians.
      tapDrillDiameter: The tap drill diameter for internal threads before any
                        threading operations.
      shaftDiameter:    The shaft diameter for external threads before any
                        threading operations.
      method:           The manufacturing method for the thread.
      starts:           The number of thread starts.
      
\endverbatim
*/
class PLMXML_FD60_API Thread : public AttribOwner
{
public:
     
    //! Default constructor
    Thread( );
     
    //! Constructs a Thread with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Thread( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Thread();

private:

	//! Assignment operator
	Thread& operator=( const Thread& iSrc );

	//! Copy constructor
	Thread( const Thread& original );
     
public:

	//! Get Type of this Thread
	plmxml_api::String GetType() const;

	//! Set Type of this Thread
	plmxml_api::Result SetType( const plmxml_api::String &s );
	
	//! Check if Type is set
	plmxml_api::logical HasType( ) const;
	
	//! Unset Type
	plmxml_api::Result UnsetType( );

	//! Set MinorDiameter
	plmxml_api::Result SetMinorDiameter( double arg );

     //! Get MinorDiameter
	double GetMinorDiameter() const;

	//! Check if MinorDiameter is set
	plmxml_api::logical HasMinorDiameter() const;

	//! Unset MinorDiameter
	plmxml_api::Result UnsetMinorDiameter();

	//! Set Starts
	plmxml_api::Result SetStarts( int arg );
     
	//! Get Starts
	int GetStarts() const;
     
	//! Check if Starts is set
	plmxml_api::logical HasStarts() const;
     
	//! Unset Starts
	plmxml_api::Result UnsetStarts();

	//! Set Offset
	plmxml_api::Result SetOffset( double arg );

     //! Get Offset
	double GetOffset() const;

	//! Check if Offset is set
	plmxml_api::logical HasOffset() const;

	//! Unset Offset
	plmxml_api::Result UnsetOffset();

	//! Set NominalDiameter
	plmxml_api::Result SetNominalDiameter( double arg );

     //! Get NominalDiameter
	double GetNominalDiameter() const;

	//! Check if NominalDiameter is set
	plmxml_api::logical HasNominalDiameter() const;

	//! Unset NominalDiameter
	plmxml_api::Result UnsetNominalDiameter();

	//! Set TaperAngle
	plmxml_api::Result SetTaperAngle( double arg );

     //! Get TaperAngle
	double GetTaperAngle() const;

	//! Check if TaperAngle is set
	plmxml_api::logical HasTaperAngle() const;

	//! Unset TaperAngle
	plmxml_api::Result UnsetTaperAngle();

	//! Set LeftHanded
	plmxml_api::Result SetLeftHanded( plmxml_api::logical arg );

	//! Get LeftHanded
	plmxml_api::logical GetLeftHanded() const;

	//! Check if LeftHanded is set
	plmxml_api::logical HasLeftHanded() const;

	//! Unset LeftHanded
	plmxml_api::Result UnsetLeftHanded();

	//! Get Method of this Thread
	plmxml_api::String GetMethod() const;

	//! Set Method of this Thread
	plmxml_api::Result SetMethod( const plmxml_api::String &s );
	
	//! Check if Method is set
	plmxml_api::logical HasMethod( ) const;
	
	//! Unset Method
	plmxml_api::Result UnsetMethod( );

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set MajorDiameter
	plmxml_api::Result SetMajorDiameter( double arg );

     //! Get MajorDiameter
	double GetMajorDiameter() const;

	//! Check if MajorDiameter is set
	plmxml_api::logical HasMajorDiameter() const;

	//! Unset MajorDiameter
	plmxml_api::Result UnsetMajorDiameter();

	//! Set InternalDiameter
	plmxml_api::Result SetInternalDiameter( double arg );

     //! Get InternalDiameter
	double GetInternalDiameter() const;

	//! Check if InternalDiameter is set
	plmxml_api::logical HasInternalDiameter() const;

	//! Unset InternalDiameter
	plmxml_api::Result UnsetInternalDiameter();

	//! Set ExternalDiameter
	plmxml_api::Result SetExternalDiameter( double arg );

     //! Get ExternalDiameter
	double GetExternalDiameter() const;

	//! Check if ExternalDiameter is set
	plmxml_api::logical HasExternalDiameter() const;

	//! Unset ExternalDiameter
	plmxml_api::Result UnsetExternalDiameter();

	//! Set Height
	plmxml_api::Result SetHeight( double arg );

     //! Get Height
	double GetHeight() const;

	//! Check if Height is set
	plmxml_api::logical HasHeight() const;

	//! Unset Height
	plmxml_api::Result UnsetHeight();

	//! Get DesignateDiameter of this Thread
	plmxml_api::String GetDesignateDiameter() const;

	//! Set DesignateDiameter of this Thread
	plmxml_api::Result SetDesignateDiameter( const plmxml_api::String &s );
	
	//! Check if DesignateDiameter is set
	plmxml_api::logical HasDesignateDiameter( ) const;
	
	//! Unset DesignateDiameter
	plmxml_api::Result UnsetDesignateDiameter( );

	//! Set EffectiveLength
	plmxml_api::Result SetEffectiveLength( double arg );

     //! Get EffectiveLength
	double GetEffectiveLength() const;

	//! Check if EffectiveLength is set
	plmxml_api::logical HasEffectiveLength() const;

	//! Unset EffectiveLength
	plmxml_api::Result UnsetEffectiveLength();

	//! Set ShaftDiameter
	plmxml_api::Result SetShaftDiameter( double arg );

     //! Get ShaftDiameter
	double GetShaftDiameter() const;

	//! Check if ShaftDiameter is set
	plmxml_api::logical HasShaftDiameter() const;

	//! Unset ShaftDiameter
	plmxml_api::Result UnsetShaftDiameter();

	//! Set TapDrillDiameter
	plmxml_api::Result SetTapDrillDiameter( double arg );

     //! Get TapDrillDiameter
	double GetTapDrillDiameter() const;

	//! Check if TapDrillDiameter is set
	plmxml_api::logical HasTapDrillDiameter() const;

	//! Unset TapDrillDiameter
	plmxml_api::Result UnsetTapDrillDiameter();

	//! Set Pitch
	plmxml_api::Result SetPitch( double arg );

     //! Get Pitch
	double GetPitch() const;

	//! Check if Pitch is set
	plmxml_api::logical HasPitch() const;

	//! Unset Pitch
	plmxml_api::Result UnsetPitch();

	//! Set Angle
	plmxml_api::Result SetAngle( double arg );

     //! Get Angle
	double GetAngle() const;

	//! Check if Angle is set
	plmxml_api::logical HasAngle() const;

	//! Unset Angle
	plmxml_api::Result UnsetAngle();

	//! Set Extent
	plmxml_api::Result SetExtent( const eThreadExtentType& arg );

	//! Get Extent
	eThreadExtentType GetExtent() const;
 
// <PLMXML_UserCode type="functionHeaderThread" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassThread;


////////////////////////////////////////////////////////////////////////////////////
//! CounterSink class
/*!
\verbatim

      This element specifies a CounterSink component of a HoleFeature. The CounterSink
      starts with a given diameter and tapers down.
      
      Attributes:
      
      diameter:     The diameter of the start of countersink.
      
      angle:        The angle of the countersink. This is the angle between a line
                       lying in the cone of the CounterSink, and a plane through the
                       start of the CounterSink. The range is 0 to pi/2. For example, 
                       just below pi/2 would be a nearly-cylindrical CounterSink.
                       
      length:       The length of the countersink along its axis.
                       
      Elements:
      
      EntityRef:    Reference to entities that are related to the CounterSink
      
\endverbatim
*/
class PLMXML_FD60_API CounterSink : public AttribOwner
{
public:
     
    //! Default constructor
    CounterSink( );
     
    //! Constructs a CounterSink with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CounterSink( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CounterSink();

private:

	//! Assignment operator
	CounterSink& operator=( const CounterSink& iSrc );

	//! Copy constructor
	CounterSink( const CounterSink& original );
     
public:

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set Angle
	plmxml_api::Result SetAngle( double arg );

     //! Get Angle
	double GetAngle() const;

	//! Check if Angle is set
	plmxml_api::logical HasAngle() const;

	//! Unset Angle
	plmxml_api::Result UnsetAngle();

	//! Add EntityRef child element to this CounterSink. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	EntityRef *AddEntityRef();
     
	//! Add 'arg' as EntityRef child element to this CounterSink.
	plmxml_api::Result AddEntityRef( EntityRef *arg );

	//! Detach and delete all EntityRef child elements.
	void DeleteEntityRefs();
     
	//! Get number of EntityRef child elements.
	int NumberOfEntityRefs() const;
     
	//! Get i'th EntityRef child element.
	EntityRef *GetEntityRef( int i ) const;
     
	//! Get all EntityRef child element as an array
	void GetEntityRefs( plmxml_api::Array<EntityRef*> &array ) const;
	     
	//! Detach and delete i'th EntityRef child element
	void DeleteEntityRef( int i );
     
	//! Detach and delete 'arg' if it's one of the EntityRef child elements
	void DeleteEntityRef( EntityRef *arg );
 
// <PLMXML_UserCode type="functionHeaderCounterSink" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassCounterSink;


////////////////////////////////////////////////////////////////////////////////////
//! CounterBore class
/*!
\verbatim

      This element specifies a CounterBore component of a HoleFeature. 

      Attributes:
       
      diameter:        The diameter of the CounterBore.
      length:          The length of the CounterBore.

      Elements:
       
      EntityRef:       Reference to entities that are related to the CounterBore
      Thread:          Definition of thread for CounterBore (at most one)
      
\endverbatim
*/
class PLMXML_FD60_API CounterBore : public AttribOwner
{
public:
     
    //! Default constructor
    CounterBore( );
     
    //! Constructs a CounterBore with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CounterBore( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CounterBore();

private:

	//! Assignment operator
	CounterBore& operator=( const CounterBore& iSrc );

	//! Copy constructor
	CounterBore( const CounterBore& original );
     
public:

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Add EntityRef child element to this CounterBore. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	EntityRef *AddEntityRef();
     
	//! Add 'arg' as EntityRef child element to this CounterBore.
	plmxml_api::Result AddEntityRef( EntityRef *arg );

	//! Detach and delete all EntityRef child elements.
	void DeleteEntityRefs();
     
	//! Get number of EntityRef child elements.
	int NumberOfEntityRefs() const;
     
	//! Get i'th EntityRef child element.
	EntityRef *GetEntityRef( int i ) const;
     
	//! Get all EntityRef child element as an array
	void GetEntityRefs( plmxml_api::Array<EntityRef*> &array ) const;
	     
	//! Detach and delete i'th EntityRef child element
	void DeleteEntityRef( int i );
     
	//! Detach and delete 'arg' if it's one of the EntityRef child elements
	void DeleteEntityRef( EntityRef *arg );

	//! Add Thread child element to this CounterBore. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Thread *AddThread();
     
	//! Set Thread child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetThread( Thread *arg );
     
	//! Get Thread child element of this CounterBore.
	Thread *GetThread() const;
     
	//! Detach and delete Thread child element tree from this CounterBore.
	void DeleteThread();
 
// <PLMXML_UserCode type="functionHeaderCounterBore" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassCounterBore;


////////////////////////////////////////////////////////////////////////////////////
//! HoleComponent class
/*!
\verbatim

      A component of a HoleFeature.
      
      Attributes:
       
      diameter:       The diameter of the hole.
      length:         The length of the hole.
      extent:         The way the hole length was determined. 
                         
      blindHoleAngle: The angle of the termination of the a blind hole. This is the
                         total angle at the tip, in radians, so pi would be a flat tip.
                         If omitted, the termination is flat.
      taperAngle:     The angle of taper, in radians. This is positive
                         and less than pi/2.

      Elements:
      
      Thread:         Definition of Thread(s) for hole component
    
\endverbatim
*/
class PLMXML_FD60_API HoleComponent : public AttribOwner
{
public:
     
    //! Default constructor
    HoleComponent( );
     
    //! Constructs a HoleComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HoleComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HoleComponent();

private:

	//! Assignment operator
	HoleComponent& operator=( const HoleComponent& iSrc );

	//! Copy constructor
	HoleComponent( const HoleComponent& original );
     
public:

	//! Set BlindHoleAngle
	plmxml_api::Result SetBlindHoleAngle( double arg );

     //! Get BlindHoleAngle
	double GetBlindHoleAngle() const;

	//! Check if BlindHoleAngle is set
	plmxml_api::logical HasBlindHoleAngle() const;

	//! Unset BlindHoleAngle
	plmxml_api::Result UnsetBlindHoleAngle();

	//! Set TaperAngle
	plmxml_api::Result SetTaperAngle( double arg );

     //! Get TaperAngle
	double GetTaperAngle() const;

	//! Check if TaperAngle is set
	plmxml_api::logical HasTaperAngle() const;

	//! Unset TaperAngle
	plmxml_api::Result UnsetTaperAngle();

	//! Set Diameter
	plmxml_api::Result SetDiameter( double arg );

     //! Get Diameter
	double GetDiameter() const;

	//! Check if Diameter is set
	plmxml_api::logical HasDiameter() const;

	//! Unset Diameter
	plmxml_api::Result UnsetDiameter();

	//! Set Length
	plmxml_api::Result SetLength( double arg );

     //! Get Length
	double GetLength() const;

	//! Check if Length is set
	plmxml_api::logical HasLength() const;

	//! Unset Length
	plmxml_api::Result UnsetLength();

	//! Set Extent
	plmxml_api::Result SetExtent( const eHoleExtentType& arg );

	//! Get Extent
	eHoleExtentType GetExtent() const;

	//! Add EntityRef child element to this HoleComponent. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	EntityRef *AddEntityRef();
     
	//! Add 'arg' as EntityRef child element to this HoleComponent.
	plmxml_api::Result AddEntityRef( EntityRef *arg );

	//! Detach and delete all EntityRef child elements.
	void DeleteEntityRefs();
     
	//! Get number of EntityRef child elements.
	int NumberOfEntityRefs() const;
     
	//! Get i'th EntityRef child element.
	EntityRef *GetEntityRef( int i ) const;
     
	//! Get all EntityRef child element as an array
	void GetEntityRefs( plmxml_api::Array<EntityRef*> &array ) const;
	     
	//! Detach and delete i'th EntityRef child element
	void DeleteEntityRef( int i );
     
	//! Detach and delete 'arg' if it's one of the EntityRef child elements
	void DeleteEntityRef( EntityRef *arg );

	//! Add Thread child element to this HoleComponent. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Thread *AddThread();
     
	//! Add 'arg' as Thread child element to this HoleComponent.
	plmxml_api::Result AddThread( Thread *arg );

	//! Detach and delete all Thread child elements.
	void DeleteThreads();
     
	//! Get number of Thread child elements.
	int NumberOfThreads() const;
     
	//! Get i'th Thread child element.
	Thread *GetThread( int i ) const;
     
	//! Get all Thread child element as an array
	void GetThreads( plmxml_api::Array<Thread*> &array ) const;
	     
	//! Detach and delete i'th Thread child element
	void DeleteThread( int i );
     
	//! Detach and delete 'arg' if it's one of the Thread child elements
	void DeleteThread( Thread *arg );
 
// <PLMXML_UserCode type="functionHeaderHoleComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassHoleComponent;


////////////////////////////////////////////////////////////////////////////////////
//! HolePosition class
/*!
\verbatim

      This specifies the position, and optionally the direction, of a Hole.
      
      Attributes:
      
      position:       Position of the start of the hole in global 3-space coords.
      direction:      Direction of of the hole. This direction defines the reference
                         direction when evaluating the sequence of HoleComponent, 
                         CounterSink and CounterBore elements; and the extent/offsets 
                         values within those items. If absent, the direction attribute 
                         on the HoleFeature is used.
    
\endverbatim
*/
class PLMXML_FD60_API HolePosition : public IdObject
{
public:
     
    //! Default constructor
    HolePosition( );
     
    //! Constructs a HolePosition with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HolePosition( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HolePosition();

private:

	//! Assignment operator
	HolePosition& operator=( const HolePosition& iSrc );

	//! Copy constructor
	HolePosition( const HolePosition& original );
     
public:

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();
 
// <PLMXML_UserCode type="functionHeaderHolePosition" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassHolePosition;


////////////////////////////////////////////////////////////////////////////////////
//! HoleFeature class
/*!
\verbatim

      This is a Hole Feature. It may consist of a number of actual holes, each of which
      has the same sequence of Components (HoleComponent, CounterSink, CounterBore), but
      which may have differing positions and directions.
      
      Attributes:
      
      direction:      Direction of of the hole. This direction defines the reference
                         direction when evaluating the sequence of hole, countersink and
                         counterbore elements; and the extent/offsets values within those
                         elements. Individual HolePosition elements may override this 
                         direction. 

      sequenceRefs:   The sequence of HoleComponent, CounterSink and CounterBore elements 
                         that make up the complete hole description, in order along the
                         Hole axis. These elements must be sub-elements of this HoleFeature.
                        
      orientation:    The orientation of the hole with respect to the starting geometry. 
                         This is for information/presentation purposes. 
                        
      Elements:
      
      HolePosition:   One HolePosition element per actual hole. At least one.
       
      HoleComponent:  Definition of a HoleComponent
      CounterBore:    Definition of a CounterBore component
      CounterSink:    Definition of a CounterSink component
      
\endverbatim
*/
class PLMXML_FD60_API HoleFeature : public Feature
{
public:
     
    //! Default constructor
    HoleFeature( );
     
    //! Constructs a HoleFeature with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HoleFeature( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HoleFeature();

private:

	//! Assignment operator
	HoleFeature& operator=( const HoleFeature& iSrc );

	//! Copy constructor
	HoleFeature( const HoleFeature& original );
     
public:

	//! Get number of references in Sequence array
	int NumberOfSequenceRefs() const;
     
	//! Add reference to 'arg' to Sequence array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddSequenceRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Sequence array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddSequenceId( const plmxml_api::String &u );
     
	//! Set i'th reference in Sequence array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetSequenceRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Sequence array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetSequenceId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Sequence array and return an object it points to.
	plmxml60::IdObject *ResolveSequenceRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Sequence array and return objects they point to.
	void ResolveSequenceRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Sequence array as plmxml_api::String
	plmxml_api::String GetSequenceId( int i ) const;
     
	//! Get all references in Sequence array as an array of plmxml_api::String
	void GetSequenceIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Sequence array.
	void RemoveSequenceRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Sequence array.
	void RemoveSequenceRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Sequence array.
	void RemoveSequenceRef( plmxml60::IdObject *arg );
     
	//! Remove all references Sequence array.
	void RemoveSequenceRefs();
	
	//! Check if Sequence is set
	plmxml_api::logical HasSequenceRefs( ) const;

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set Orientation
	plmxml_api::Result SetOrientation( const eHoleOrientationType& arg );

	//! Get Orientation
	eHoleOrientationType GetOrientation() const;

	//! Add HolePosition child element to this HoleFeature. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	HolePosition *AddHolePosition();
     
	//! Add 'arg' as HolePosition child element to this HoleFeature.
	plmxml_api::Result AddHolePosition( HolePosition *arg );

	//! Detach and delete all HolePosition child elements.
	void DeleteHolePositions();
     
	//! Get number of HolePosition child elements.
	int NumberOfHolePositions() const;
     
	//! Get i'th HolePosition child element.
	HolePosition *GetHolePosition( int i ) const;
     
	//! Get all HolePosition child element as an array
	void GetHolePositions( plmxml_api::Array<HolePosition*> &array ) const;
	     
	//! Detach and delete i'th HolePosition child element
	void DeleteHolePosition( int i );
     
	//! Detach and delete 'arg' if it's one of the HolePosition child elements
	void DeleteHolePosition( HolePosition *arg );

	//! Add HoleComponent child element to this HoleFeature. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	HoleComponent *AddHoleComponent();
     
	//! Add 'arg' as HoleComponent child element to this HoleFeature.
	plmxml_api::Result AddHoleComponent( HoleComponent *arg );

	//! Detach and delete all HoleComponent child elements.
	void DeleteHoleComponents();
     
	//! Get number of HoleComponent child elements.
	int NumberOfHoleComponents() const;
     
	//! Get i'th HoleComponent child element.
	HoleComponent *GetHoleComponent( int i ) const;
     
	//! Get all HoleComponent child element as an array
	void GetHoleComponents( plmxml_api::Array<HoleComponent*> &array ) const;
	     
	//! Detach and delete i'th HoleComponent child element
	void DeleteHoleComponent( int i );
     
	//! Detach and delete 'arg' if it's one of the HoleComponent child elements
	void DeleteHoleComponent( HoleComponent *arg );

	//! Add CounterBore child element to this HoleFeature. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	CounterBore *AddCounterBore();
     
	//! Add 'arg' as CounterBore child element to this HoleFeature.
	plmxml_api::Result AddCounterBore( CounterBore *arg );

	//! Detach and delete all CounterBore child elements.
	void DeleteCounterBores();
     
	//! Get number of CounterBore child elements.
	int NumberOfCounterBores() const;
     
	//! Get i'th CounterBore child element.
	CounterBore *GetCounterBore( int i ) const;
     
	//! Get all CounterBore child element as an array
	void GetCounterBores( plmxml_api::Array<CounterBore*> &array ) const;
	     
	//! Detach and delete i'th CounterBore child element
	void DeleteCounterBore( int i );
     
	//! Detach and delete 'arg' if it's one of the CounterBore child elements
	void DeleteCounterBore( CounterBore *arg );

	//! Add CounterSink child element to this HoleFeature. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	CounterSink *AddCounterSink();
     
	//! Add 'arg' as CounterSink child element to this HoleFeature.
	plmxml_api::Result AddCounterSink( CounterSink *arg );

	//! Detach and delete all CounterSink child elements.
	void DeleteCounterSinks();
     
	//! Get number of CounterSink child elements.
	int NumberOfCounterSinks() const;
     
	//! Get i'th CounterSink child element.
	CounterSink *GetCounterSink( int i ) const;
     
	//! Get all CounterSink child element as an array
	void GetCounterSinks( plmxml_api::Array<CounterSink*> &array ) const;
	     
	//! Detach and delete i'th CounterSink child element
	void DeleteCounterSink( int i );
     
	//! Detach and delete 'arg' if it's one of the CounterSink child elements
	void DeleteCounterSink( CounterSink *arg );
 
// <PLMXML_UserCode type="functionHeaderHoleFeature" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassHoleFeature;


////////////////////////////////////////////////////////////////////////////////////
//! ThreadedFeature class
/*!
\verbatim

      This is a Thread Feature, not associated with a Hole. Only a single position
      and direction can be specified.
      
      Attributes:
      
      position:       Position of the start of the thread in global 3-space coords
      direction:      Direction of the thread. This direction defines the reference
                         direction when evaluating the sequence of thread elements; 
                         and the extent/offsets values within those items.
      sequenceRefs:   The sequence of thread elements that make up the complete 
                         thread description. These elements must be defined as elements 
                         within this thread description.
      inside:         'true' if a thread feature on the inside of a hole, 'false' if
                         a thread feature on a boss.
      setting         The thread entry setting.
                       
      Elements:
      
      Thread:         Definition of a thread component. More than one is allowed.
      
\endverbatim
*/
class PLMXML_FD60_API ThreadedFeature : public Feature
{
public:
     
    //! Default constructor
    ThreadedFeature( );
     
    //! Constructs a ThreadedFeature with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ThreadedFeature( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ThreadedFeature();

private:

	//! Assignment operator
	ThreadedFeature& operator=( const ThreadedFeature& iSrc );

	//! Copy constructor
	ThreadedFeature( const ThreadedFeature& original );
     
public:

	//! Set Inside
	plmxml_api::Result SetInside( plmxml_api::logical arg );

	//! Get Inside
	plmxml_api::logical GetInside() const;

	//! Check if Inside is set
	plmxml_api::logical HasInside() const;

	//! Unset Inside
	plmxml_api::Result UnsetInside();

	//! Get number of references in Sequence array
	int NumberOfSequenceRefs() const;
     
	//! Add reference to 'arg' to Sequence array
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical AddSequenceRef( plmxml60::IdObject *arg );
     
	//! Add reference to an object pointed to by 'u' to Sequence array
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical AddSequenceId( const plmxml_api::String &u );
     
	//! Set i'th reference in Sequence array to 'arg'
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetSequenceRef( int i, plmxml60::IdObject *arg );
     
	//! Set i'th reference in Sequence array to an object pointed to by 'u'
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetSequenceId( int i, const plmxml_api::String &u );
     
	//! Resolve i'th reference in Sequence array and return an object it points to.
	plmxml60::IdObject *ResolveSequenceRef( int i, plmxml_api::Configuration* config = NULL );
     
	//! Resolve all references in Sequence array and return objects they point to.
	void ResolveSequenceRefs( plmxml_api::Array<plmxml60::IdObject *> & array, plmxml_api::Configuration* config = NULL );
     
	//! Get i'th reference in Sequence array as plmxml_api::String
	plmxml_api::String GetSequenceId( int i ) const;
     
	//! Get all references in Sequence array as an array of plmxml_api::String
	void GetSequenceIds( plmxml_api::Array<plmxml_api::String> &array ) const;
     
	//! Remove i'th reference from the Sequence array.
	void RemoveSequenceRef( int i );
     
	//! Remove reference to an object pointed to by 'u' from the Sequence array.
	void RemoveSequenceRef( const plmxml_api::String &u );
     
	//! Remove reference to 'arg' from the Sequence array.
	void RemoveSequenceRef( plmxml60::IdObject *arg );
     
	//! Remove all references Sequence array.
	void RemoveSequenceRefs();
	
	//! Check if Sequence is set
	plmxml_api::logical HasSequenceRefs( ) const;

	//! Set Direction using plmxml_api::Vector components
	plmxml_api::Result SetDirection( const plmxml_api::Vector& arg );

	//! Get Direction as plmxml_api::Vector
	plmxml_api::Result GetDirection( plmxml_api::Vector& arg ) const;

	//! Check if Direction is set
	plmxml_api::logical HasDirection() const;

	//! Unset Direction
	plmxml_api::Result UnsetDirection();

	//! Set Setting
	plmxml_api::Result SetSetting( const eThreadEntrySettingType& arg );

	//! Get Setting
	eThreadEntrySettingType GetSetting() const;

	//! Set Position using plmxml_api::Vector components
	plmxml_api::Result SetPosition( const plmxml_api::Vector& arg );

	//! Get Position as plmxml_api::Vector
	plmxml_api::Result GetPosition( plmxml_api::Vector& arg ) const;

	//! Check if Position is set
	plmxml_api::logical HasPosition() const;

	//! Unset Position
	plmxml_api::Result UnsetPosition();

	//! Add Thread child element to this ThreadedFeature. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Thread *AddThread();
     
	//! Add 'arg' as Thread child element to this ThreadedFeature.
	plmxml_api::Result AddThread( Thread *arg );

	//! Detach and delete all Thread child elements.
	void DeleteThreads();
     
	//! Get number of Thread child elements.
	int NumberOfThreads() const;
     
	//! Get i'th Thread child element.
	Thread *GetThread( int i ) const;
     
	//! Get all Thread child element as an array
	void GetThreads( plmxml_api::Array<Thread*> &array ) const;
	     
	//! Detach and delete i'th Thread child element
	void DeleteThread( int i );
     
	//! Detach and delete 'arg' if it's one of the Thread child elements
	void DeleteThread( Thread *arg );
 
// <PLMXML_UserCode type="functionHeaderThreadedFeature" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassThreadedFeature;


////////////////////////////////////////////////////////////////////////////////////
//! FeatureDescriptions class
/*!
\verbatim

      This is a collection (sequence) of Features.

      Attributes:

      firstFeature:     The first feature in the sequence.
      ownerRef:         Reference to owning ProductRevisionView or
                        Representation.

      Elements:

      Feature:          A HoleFeature or any other elements derived from
                        Feature.
      ContinuousJoinDesignFeature: Elements derived from
                        ContinuousJoinDesignFeature such as
                        ArcWeldDesignFeature.
      DatumDesignFeature:
      DiscreteJoinDesignFeature: Elements derived from
                        DiscreteJoinDesignFeature such as
                        ResistanceWeldDesignFeature.
      SurfaceAddDesignFeature: Elements derived from
                        SurfaceAddDesignFeature such as
                        AdhesiveFillDesignFeature.
      
\endverbatim
*/
class PLMXML_FD60_API FeatureDescriptions : public AttribOwner
{
public:
     
    //! Default constructor
    FeatureDescriptions( );
     
    //! Constructs a FeatureDescriptions with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FeatureDescriptions( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FeatureDescriptions();

private:

	//! Assignment operator
	FeatureDescriptions& operator=( const FeatureDescriptions& iSrc );

	//! Copy constructor
	FeatureDescriptions( const FeatureDescriptions& original );
     
public:

	//! Set reference to FirstFeature using 'arg's plmxml_api::Id.
	/*! 
		Returns FALSE if 'arg's Id is unset otherwise TRUE.
	*/
	plmxml_api::logical SetFirstFeatureRef( plmxml60::IdObject *arg );

	//! Clear reference to FirstFeature
	void RemoveFirstFeatureRef( );

	//! Find a plmxml60::IdObject referenced by FirstFeature
	plmxml60::IdObject *ResolveFirstFeatureRef( plmxml_api::Configuration* config = NULL );

	//! Get FirstFeature reference
	plmxml_api::String GetFirstFeatureId() const;

	//! Set FirstFeature reference.
	/*! 
		Returns FALSE if input String is empty otherwise TRUE.
	*/
	plmxml_api::logical SetFirstFeatureId( const plmxml_api::String& u );
	
	//! Check if FirstFeature is set
	plmxml_api::logical HasFirstFeatureRef( ) const;

	//! Get Owner URI as plmxml_api::String
	plmxml_api::String GetOwnerURI() const;

	//! Set Owner URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::String& );
	
	//! Get the handle of Owner URI. Does not resolve the URI.
	plmxml_api::Result GetOwnerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Owner URI. URI string is unchanged.
	plmxml_api::Result SetOwnerURI( const plmxml_api::Handle& );
	
	//! Resolve Owner URI and return an object (handle) it points to.
	plmxml_api::Result ResolveOwnerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Owner URI. Clears URI string and handle.
	plmxml_api::Result DeleteOwnerURI();
	
	//! Check if Owner URI is set
	plmxml_api::logical HasOwnerURI( ) const;
	

	//! Add Feature child element to this FeatureDescriptions. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Feature *AddFeature();
     
	//! Add 'arg' as Feature child element to this FeatureDescriptions.
	plmxml_api::Result AddFeature( Feature *arg );

	//! Detach and delete all Feature child elements.
	void DeleteFeatures();
     
	//! Get number of Feature child elements.
	int NumberOfFeatures() const;
     
	//! Get i'th Feature child element.
	Feature *GetFeature( int i ) const;
     
	//! Get all Feature child element as an array
	void GetFeatures( plmxml_api::Array<Feature*> &array ) const;
	     
	//! Detach and delete i'th Feature child element
	void DeleteFeature( int i );
     
	//! Detach and delete 'arg' if it's one of the Feature child elements
	void DeleteFeature( Feature *arg );

	//! Add ContinuousJoinDesignFeature child element to this FeatureDescriptions. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ContinuousJoinDesignFeature *AddContinuousJoinDesignFeature();
     
	//! Add 'arg' as ContinuousJoinDesignFeature child element to this FeatureDescriptions.
	plmxml_api::Result AddContinuousJoinDesignFeature( ContinuousJoinDesignFeature *arg );

	//! Detach and delete all ContinuousJoinDesignFeature child elements.
	void DeleteContinuousJoinDesignFeatures();
     
	//! Get number of ContinuousJoinDesignFeature child elements.
	int NumberOfContinuousJoinDesignFeatures() const;
     
	//! Get i'th ContinuousJoinDesignFeature child element.
	ContinuousJoinDesignFeature *GetContinuousJoinDesignFeature( int i ) const;
     
	//! Get all ContinuousJoinDesignFeature child element as an array
	void GetContinuousJoinDesignFeatures( plmxml_api::Array<ContinuousJoinDesignFeature*> &array ) const;
	     
	//! Detach and delete i'th ContinuousJoinDesignFeature child element
	void DeleteContinuousJoinDesignFeature( int i );
     
	//! Detach and delete 'arg' if it's one of the ContinuousJoinDesignFeature child elements
	void DeleteContinuousJoinDesignFeature( ContinuousJoinDesignFeature *arg );

	//! Add DatumDesignFeature child element to this FeatureDescriptions. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DatumDesignFeature *AddDatumDesignFeature();
     
	//! Add 'arg' as DatumDesignFeature child element to this FeatureDescriptions.
	plmxml_api::Result AddDatumDesignFeature( DatumDesignFeature *arg );

	//! Detach and delete all DatumDesignFeature child elements.
	void DeleteDatumDesignFeatures();
     
	//! Get number of DatumDesignFeature child elements.
	int NumberOfDatumDesignFeatures() const;
     
	//! Get i'th DatumDesignFeature child element.
	DatumDesignFeature *GetDatumDesignFeature( int i ) const;
     
	//! Get all DatumDesignFeature child element as an array
	void GetDatumDesignFeatures( plmxml_api::Array<DatumDesignFeature*> &array ) const;
	     
	//! Detach and delete i'th DatumDesignFeature child element
	void DeleteDatumDesignFeature( int i );
     
	//! Detach and delete 'arg' if it's one of the DatumDesignFeature child elements
	void DeleteDatumDesignFeature( DatumDesignFeature *arg );

	//! Add DiscreteJoinDesignFeature child element to this FeatureDescriptions. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DiscreteJoinDesignFeature *AddDiscreteJoinDesignFeature();
     
	//! Add 'arg' as DiscreteJoinDesignFeature child element to this FeatureDescriptions.
	plmxml_api::Result AddDiscreteJoinDesignFeature( DiscreteJoinDesignFeature *arg );

	//! Detach and delete all DiscreteJoinDesignFeature child elements.
	void DeleteDiscreteJoinDesignFeatures();
     
	//! Get number of DiscreteJoinDesignFeature child elements.
	int NumberOfDiscreteJoinDesignFeatures() const;
     
	//! Get i'th DiscreteJoinDesignFeature child element.
	DiscreteJoinDesignFeature *GetDiscreteJoinDesignFeature( int i ) const;
     
	//! Get all DiscreteJoinDesignFeature child element as an array
	void GetDiscreteJoinDesignFeatures( plmxml_api::Array<DiscreteJoinDesignFeature*> &array ) const;
	     
	//! Detach and delete i'th DiscreteJoinDesignFeature child element
	void DeleteDiscreteJoinDesignFeature( int i );
     
	//! Detach and delete 'arg' if it's one of the DiscreteJoinDesignFeature child elements
	void DeleteDiscreteJoinDesignFeature( DiscreteJoinDesignFeature *arg );

	//! Add SurfaceAddDesignFeature child element to this FeatureDescriptions. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	SurfaceAddDesignFeature *AddSurfaceAddDesignFeature();
     
	//! Add 'arg' as SurfaceAddDesignFeature child element to this FeatureDescriptions.
	plmxml_api::Result AddSurfaceAddDesignFeature( SurfaceAddDesignFeature *arg );

	//! Detach and delete all SurfaceAddDesignFeature child elements.
	void DeleteSurfaceAddDesignFeatures();
     
	//! Get number of SurfaceAddDesignFeature child elements.
	int NumberOfSurfaceAddDesignFeatures() const;
     
	//! Get i'th SurfaceAddDesignFeature child element.
	SurfaceAddDesignFeature *GetSurfaceAddDesignFeature( int i ) const;
     
	//! Get all SurfaceAddDesignFeature child element as an array
	void GetSurfaceAddDesignFeatures( plmxml_api::Array<SurfaceAddDesignFeature*> &array ) const;
	     
	//! Detach and delete i'th SurfaceAddDesignFeature child element
	void DeleteSurfaceAddDesignFeature( int i );
     
	//! Detach and delete 'arg' if it's one of the SurfaceAddDesignFeature child elements
	void DeleteSurfaceAddDesignFeature( SurfaceAddDesignFeature *arg );
 
// <PLMXML_UserCode type="functionHeaderFeatureDescriptions" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_FD60_API plmxml_api::plmxmlClass plmxmlClassFeatureDescriptions;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
