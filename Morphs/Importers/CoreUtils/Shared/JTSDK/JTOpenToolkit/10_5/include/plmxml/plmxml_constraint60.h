/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.26482 14/06/2017 09:43:26
// 
// Schema:	PLMXMLConstraintSchema.xsd
// Data:	2008-05-02
// Version:	6.0
// Status:	release
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_CONSTRAINT60_H__
#define __PLMXML_CONSTRAINT60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_CONSTRAINT60_EXPORTS
#define PLMXML_CONSTRAINT60_API __declspec(dllexport)
#else
#define PLMXML_CONSTRAINT60_API __declspec(dllimport)
#endif
#else
#define PLMXML_CONSTRAINT60_API
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
//! eDriverEnum class
/*!
Allowed Values:
\verbatim
  eDriverEnumGeneral
	"general"
  eDriverEnumConstant
	"constant"
  eDriverEnumMotor
	"motor"
  eDriverEnumHarmonic
	"harmonic"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eDriverEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDriverEnum( const char* Type );
     
	//! Constructor
	eDriverEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDriverEnum( );
     
	//! Destructor 
	virtual ~eDriverEnum( );
     
	//! Assign from 'Type'
	const eDriverEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDriverEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DriverEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eDriverEnum& e1, const eDriverEnum& e2 );
     
	//! Compare DriverEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eDriverEnum& e1, const eDriverEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDriverEnum;
extern PLMXML_CONSTRAINT60_API eDriverEnum eDriverEnumUnset;
extern PLMXML_CONSTRAINT60_API eDriverEnum eDriverEnumGeneral;
extern PLMXML_CONSTRAINT60_API eDriverEnum eDriverEnumConstant;
extern PLMXML_CONSTRAINT60_API eDriverEnum eDriverEnumMotor;
extern PLMXML_CONSTRAINT60_API eDriverEnum eDriverEnumHarmonic;

////////////////////////////////////////////////////////////////////////////////////
//! eSensorEnum class
/*!
Allowed Values:
\verbatim
  eSensorEnumDisplacement
	"displacement"
  eSensorEnumVelocity
	"velocity"
  eSensorEnumAcceleration
	"acceleration"
  eSensorEnumForce
	"force"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eSensorEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSensorEnum( const char* Type );
     
	//! Constructor
	eSensorEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSensorEnum( );
     
	//! Destructor 
	virtual ~eSensorEnum( );
     
	//! Assign from 'Type'
	const eSensorEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSensorEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SensorEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eSensorEnum& e1, const eSensorEnum& e2 );
     
	//! Compare SensorEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eSensorEnum& e1, const eSensorEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSensorEnum;
extern PLMXML_CONSTRAINT60_API eSensorEnum eSensorEnumUnset;
extern PLMXML_CONSTRAINT60_API eSensorEnum eSensorEnumDisplacement;
extern PLMXML_CONSTRAINT60_API eSensorEnum eSensorEnumVelocity;
extern PLMXML_CONSTRAINT60_API eSensorEnum eSensorEnumAcceleration;
extern PLMXML_CONSTRAINT60_API eSensorEnum eSensorEnumForce;

////////////////////////////////////////////////////////////////////////////////////
//! eJointOverlapDeltaEnum class
/*!
Allowed Values:
\verbatim
  eJointOverlapDeltaEnumConstant
	"constant"
  eJointOverlapDeltaEnumDecrease
	"decrease"
  eJointOverlapDeltaEnumIncrease
	"increase"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eJointOverlapDeltaEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eJointOverlapDeltaEnum( const char* Type );
     
	//! Constructor
	eJointOverlapDeltaEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eJointOverlapDeltaEnum( );
     
	//! Destructor 
	virtual ~eJointOverlapDeltaEnum( );
     
	//! Assign from 'Type'
	const eJointOverlapDeltaEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eJointOverlapDeltaEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare JointOverlapDeltaEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eJointOverlapDeltaEnum& e1, const eJointOverlapDeltaEnum& e2 );
     
	//! Compare JointOverlapDeltaEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eJointOverlapDeltaEnum& e1, const eJointOverlapDeltaEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumJointOverlapDeltaEnum;
extern PLMXML_CONSTRAINT60_API eJointOverlapDeltaEnum eJointOverlapDeltaEnumUnset;
extern PLMXML_CONSTRAINT60_API eJointOverlapDeltaEnum eJointOverlapDeltaEnumConstant;
extern PLMXML_CONSTRAINT60_API eJointOverlapDeltaEnum eJointOverlapDeltaEnumDecrease;
extern PLMXML_CONSTRAINT60_API eJointOverlapDeltaEnum eJointOverlapDeltaEnumIncrease;

////////////////////////////////////////////////////////////////////////////////////
//! eConstraintAlignmentEnum class
/*!
Allowed Values:
\verbatim
  eConstraintAlignmentEnumAntiAlign
	"antiAlign"
  eConstraintAlignmentEnumAlign
	"align"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConstraintAlignmentEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConstraintAlignmentEnum( const char* Type );
     
	//! Constructor
	eConstraintAlignmentEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConstraintAlignmentEnum( );
     
	//! Destructor 
	virtual ~eConstraintAlignmentEnum( );
     
	//! Assign from 'Type'
	const eConstraintAlignmentEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConstraintAlignmentEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConstraintAlignmentEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConstraintAlignmentEnum& e1, const eConstraintAlignmentEnum& e2 );
     
	//! Compare ConstraintAlignmentEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConstraintAlignmentEnum& e1, const eConstraintAlignmentEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConstraintAlignmentEnum;
extern PLMXML_CONSTRAINT60_API eConstraintAlignmentEnum eConstraintAlignmentEnumUnset;
extern PLMXML_CONSTRAINT60_API eConstraintAlignmentEnum eConstraintAlignmentEnumAntiAlign;
extern PLMXML_CONSTRAINT60_API eConstraintAlignmentEnum eConstraintAlignmentEnumAlign;

////////////////////////////////////////////////////////////////////////////////////
//! eDegreeOfFreedomEnum class
/*!
Allowed Values:
\verbatim
  eDegreeOfFreedomEnumRz
	"rz"
  eDegreeOfFreedomEnumY
	"y"
  eDegreeOfFreedomEnumRx
	"rx"
  eDegreeOfFreedomEnumZ
	"z"
  eDegreeOfFreedomEnumX
	"x"
  eDegreeOfFreedomEnumRy
	"ry"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eDegreeOfFreedomEnum( const char* Type );
     
	//! Constructor
	eDegreeOfFreedomEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eDegreeOfFreedomEnum( );
     
	//! Destructor 
	virtual ~eDegreeOfFreedomEnum( );
     
	//! Assign from 'Type'
	const eDegreeOfFreedomEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eDegreeOfFreedomEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare DegreeOfFreedomEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eDegreeOfFreedomEnum& e1, const eDegreeOfFreedomEnum& e2 );
     
	//! Compare DegreeOfFreedomEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eDegreeOfFreedomEnum& e1, const eDegreeOfFreedomEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumDegreeOfFreedomEnum;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumUnset;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumRz;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumY;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumRx;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumZ;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumX;
extern PLMXML_CONSTRAINT60_API eDegreeOfFreedomEnum eDegreeOfFreedomEnumRy;

////////////////////////////////////////////////////////////////////////////////////
//! eConstraintEnum class
/*!
Allowed Values:
\verbatim
  eConstraintEnumRadius
	"radius"
  eConstraintEnumTangent
	"tangent"
  eConstraintEnumEqualCurvature
	"equalCurvature"
  eConstraintEnumConcentric
	"concentric"
  eConstraintEnumMidpoint
	"midpoint"
  eConstraintEnumAngle3D
	"angle3D"
  eConstraintEnumEqualDistance
	"equalDistance"
  eConstraintEnumFixedParameter
	"fixedParameter"
  eConstraintEnumSymmetric
	"symmetric"
  eConstraintEnumEqualSecondDerivative
	"equalSecondDerivative"
  eConstraintEnumDiameter
	"diameter"
  eConstraintEnumCoupler
	"coupler"
  eConstraintEnumContact
	"contact"
  eConstraintEnumSpring
	"spring"
  eConstraintEnumAngle2D
	"angle2D"
  eConstraintEnumCoincident
	"coincident"
  eConstraintEnumParallel
	"parallel"
  eConstraintEnumPerpendicular
	"perpendicular"
  eConstraintEnumEqualParameter
	"equalParameter"
  eConstraintEnumEqualRadius
	"equalRadius"
  eConstraintEnumForce
	"force"
  eConstraintEnumMajorRadius
	"majorRadius"
  eConstraintEnumJoint
	"joint"
  eConstraintEnumMinorRadius
	"minorRadius"
  eConstraintEnumTouchAlign
	"touchAlign"
  eConstraintEnumFixed
	"fixed"
  eConstraintEnumHalfAngle
	"halfAngle"
  eConstraintEnumBushing
	"bushing"
  eConstraintEnumEqualLength
	"equalLength"
  eConstraintEnumDistance
	"distance"
  eConstraintEnumSignedDistance
	"signedDistance"
  eConstraintEnumDriver
	"driver"
  eConstraintEnumDamper
	"damper"
  eConstraintEnumLimitsDependency
	"limitsDependency"
  eConstraintEnumLength
	"length"
  eConstraintEnumEqualFirstDerivative
	"equalFirstDerivative"
  eConstraintEnumRigid
	"rigid"
  eConstraintEnumEqualDirection
	"equalDirection"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConstraintEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConstraintEnum( const char* Type );
     
	//! Constructor
	eConstraintEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConstraintEnum( );
     
	//! Destructor 
	virtual ~eConstraintEnum( );
     
	//! Assign from 'Type'
	const eConstraintEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConstraintEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConstraintEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConstraintEnum& e1, const eConstraintEnum& e2 );
     
	//! Compare ConstraintEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConstraintEnum& e1, const eConstraintEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConstraintEnum;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumUnset;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumRadius;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumTangent;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualCurvature;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumConcentric;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumMidpoint;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumAngle3D;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualDistance;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumFixedParameter;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumSymmetric;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualSecondDerivative;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumDiameter;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumCoupler;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumContact;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumSpring;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumAngle2D;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumCoincident;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumParallel;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumPerpendicular;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualParameter;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualRadius;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumForce;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumMajorRadius;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumJoint;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumMinorRadius;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumTouchAlign;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumFixed;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumHalfAngle;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumBushing;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualLength;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumDistance;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumSignedDistance;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumDriver;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumDamper;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumLimitsDependency;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumLength;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualFirstDerivative;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumRigid;
extern PLMXML_CONSTRAINT60_API eConstraintEnum eConstraintEnumEqualDirection;

////////////////////////////////////////////////////////////////////////////////////
//! eGeometrySubTypeEnum class
/*!
Allowed Values:
\verbatim
  eGeometrySubTypeEnumInterpolation
	"interpolation"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eGeometrySubTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eGeometrySubTypeEnum( const char* Type );
     
	//! Constructor
	eGeometrySubTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eGeometrySubTypeEnum( );
     
	//! Destructor 
	virtual ~eGeometrySubTypeEnum( );
     
	//! Assign from 'Type'
	const eGeometrySubTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eGeometrySubTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare GeometrySubTypeEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eGeometrySubTypeEnum& e1, const eGeometrySubTypeEnum& e2 );
     
	//! Compare GeometrySubTypeEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eGeometrySubTypeEnum& e1, const eGeometrySubTypeEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumGeometrySubTypeEnum;
extern PLMXML_CONSTRAINT60_API eGeometrySubTypeEnum eGeometrySubTypeEnumUnset;
extern PLMXML_CONSTRAINT60_API eGeometrySubTypeEnum eGeometrySubTypeEnumInterpolation;

////////////////////////////////////////////////////////////////////////////////////
//! eGeometryTypeEnum class
/*!
Allowed Values:
\verbatim
  eGeometryTypeEnumGeneralParametricCurve
	"generalParametricCurve"
  eGeometryTypeEnumBSplineSurface
	"bSplineSurface"
  eGeometryTypeEnumTorus
	"torus"
  eGeometryTypeEnumSpCurve
	"spCurve"
  eGeometryTypeEnumSweptSurface
	"sweptSurface"
  eGeometryTypeEnumLine
	"line"
  eGeometryTypeEnumGeneralParametricSurface
	"generalParametricSurface"
  eGeometryTypeEnumPlane
	"plane"
  eGeometryTypeEnumPoint
	"point"
  eGeometryTypeEnumSpunSurface
	"spunSurface"
  eGeometryTypeEnumSurface
	"surface"
  eGeometryTypeEnumBSplineCurve
	"bSplineCurve"
  eGeometryTypeEnumCompositeCurve
	"compositeCurve"
  eGeometryTypeEnumCurve
	"curve"
  eGeometryTypeEnumCircle
	"circle"
  eGeometryTypeEnumEllipse
	"ellipse"
  eGeometryTypeEnumSphere
	"sphere"
  eGeometryTypeEnumCylinder
	"cylinder"
  eGeometryTypeEnumCone
	"cone"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eGeometryTypeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eGeometryTypeEnum( const char* Type );
     
	//! Constructor
	eGeometryTypeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eGeometryTypeEnum( );
     
	//! Destructor 
	virtual ~eGeometryTypeEnum( );
     
	//! Assign from 'Type'
	const eGeometryTypeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eGeometryTypeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare GeometryTypeEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eGeometryTypeEnum& e1, const eGeometryTypeEnum& e2 );
     
	//! Compare GeometryTypeEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eGeometryTypeEnum& e1, const eGeometryTypeEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumGeometryTypeEnum;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumUnset;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumGeneralParametricCurve;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumBSplineSurface;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumTorus;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumSpCurve;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumSweptSurface;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumLine;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumGeneralParametricSurface;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumPlane;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumPoint;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumSpunSurface;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumSurface;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumBSplineCurve;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumCompositeCurve;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumCurve;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumCircle;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumEllipse;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumSphere;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumCylinder;
extern PLMXML_CONSTRAINT60_API eGeometryTypeEnum eGeometryTypeEnumCone;

////////////////////////////////////////////////////////////////////////////////////
//! eSolverEnum class
/*!
Allowed Values:
\verbatim
  eSolverEnumTecnomatix
	"tecnomatix"
  eSolverEnumAdams
	"adams"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eSolverEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSolverEnum( const char* Type );
     
	//! Constructor
	eSolverEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSolverEnum( );
     
	//! Destructor 
	virtual ~eSolverEnum( );
     
	//! Assign from 'Type'
	const eSolverEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSolverEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SolverEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eSolverEnum& e1, const eSolverEnum& e2 );
     
	//! Compare SolverEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eSolverEnum& e1, const eSolverEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSolverEnum;
extern PLMXML_CONSTRAINT60_API eSolverEnum eSolverEnumUnset;
extern PLMXML_CONSTRAINT60_API eSolverEnum eSolverEnumTecnomatix;
extern PLMXML_CONSTRAINT60_API eSolverEnum eSolverEnumAdams;

////////////////////////////////////////////////////////////////////////////////////
//! eCouplerEnum class
/*!
Allowed Values:
\verbatim
  eCouplerEnumFollow
	"follow"
  eCouplerEnumGear
	"gear"
  eCouplerEnumCable
	"cable"
  eCouplerEnumRackAndPinion
	"rackAndPinion"
  eCouplerEnumPosition
	"position"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eCouplerEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCouplerEnum( const char* Type );
     
	//! Constructor
	eCouplerEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCouplerEnum( );
     
	//! Destructor 
	virtual ~eCouplerEnum( );
     
	//! Assign from 'Type'
	const eCouplerEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCouplerEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CouplerEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eCouplerEnum& e1, const eCouplerEnum& e2 );
     
	//! Compare CouplerEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eCouplerEnum& e1, const eCouplerEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCouplerEnum;
extern PLMXML_CONSTRAINT60_API eCouplerEnum eCouplerEnumUnset;
extern PLMXML_CONSTRAINT60_API eCouplerEnum eCouplerEnumFollow;
extern PLMXML_CONSTRAINT60_API eCouplerEnum eCouplerEnumGear;
extern PLMXML_CONSTRAINT60_API eCouplerEnum eCouplerEnumCable;
extern PLMXML_CONSTRAINT60_API eCouplerEnum eCouplerEnumRackAndPinion;
extern PLMXML_CONSTRAINT60_API eCouplerEnum eCouplerEnumPosition;

////////////////////////////////////////////////////////////////////////////////////
//! eCoordinateFrameEnum class
/*!
Allowed Values:
\verbatim
  eCoordinateFrameEnumRelative
	"relative"
  eCoordinateFrameEnumUserDefined
	"userDefined"
  eCoordinateFrameEnumAbsolute
	"absolute"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eCoordinateFrameEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCoordinateFrameEnum( const char* Type );
     
	//! Constructor
	eCoordinateFrameEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCoordinateFrameEnum( );
     
	//! Destructor 
	virtual ~eCoordinateFrameEnum( );
     
	//! Assign from 'Type'
	const eCoordinateFrameEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCoordinateFrameEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CoordinateFrameEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eCoordinateFrameEnum& e1, const eCoordinateFrameEnum& e2 );
     
	//! Compare CoordinateFrameEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eCoordinateFrameEnum& e1, const eCoordinateFrameEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCoordinateFrameEnum;
extern PLMXML_CONSTRAINT60_API eCoordinateFrameEnum eCoordinateFrameEnumUnset;
extern PLMXML_CONSTRAINT60_API eCoordinateFrameEnum eCoordinateFrameEnumRelative;
extern PLMXML_CONSTRAINT60_API eCoordinateFrameEnum eCoordinateFrameEnumUserDefined;
extern PLMXML_CONSTRAINT60_API eCoordinateFrameEnum eCoordinateFrameEnumAbsolute;

////////////////////////////////////////////////////////////////////////////////////
//! eConstraintHelpEnum class
/*!
Allowed Values:
\verbatim
  eConstraintHelpEnumCurvePoint
	"curvePoint"
  eConstraintHelpEnumSurfacePoint
	"surfacePoint"
  eConstraintHelpEnumPoint
	"point"
  eConstraintHelpEnumCentre
	"centre"
  eConstraintHelpEnumBoundary
	"boundary"
  eConstraintHelpEnumParamU
	"paramU"
  eConstraintHelpEnumParamUV
	"paramUV"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConstraintHelpEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConstraintHelpEnum( const char* Type );
     
	//! Constructor
	eConstraintHelpEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConstraintHelpEnum( );
     
	//! Destructor 
	virtual ~eConstraintHelpEnum( );
     
	//! Assign from 'Type'
	const eConstraintHelpEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConstraintHelpEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConstraintHelpEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConstraintHelpEnum& e1, const eConstraintHelpEnum& e2 );
     
	//! Compare ConstraintHelpEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConstraintHelpEnum& e1, const eConstraintHelpEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConstraintHelpEnum;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumUnset;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumCurvePoint;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumSurfacePoint;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumPoint;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumCentre;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumBoundary;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumParamU;
extern PLMXML_CONSTRAINT60_API eConstraintHelpEnum eConstraintHelpEnumParamUV;

////////////////////////////////////////////////////////////////////////////////////
//! eMarkerEnum class
/*!
Allowed Values:
\verbatim
  eMarkerEnumReferenceFrame
	"referenceFrame"
  eMarkerEnumToolFrame
	"toolFrame"
  eMarkerEnumLocator
	"locator"
  eMarkerEnumToolCentrePointFrame
	"toolCentrePointFrame"
  eMarkerEnumBaseFrame
	"baseFrame"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eMarkerEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eMarkerEnum( const char* Type );
     
	//! Constructor
	eMarkerEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eMarkerEnum( );
     
	//! Destructor 
	virtual ~eMarkerEnum( );
     
	//! Assign from 'Type'
	const eMarkerEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eMarkerEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare MarkerEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eMarkerEnum& e1, const eMarkerEnum& e2 );
     
	//! Compare MarkerEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eMarkerEnum& e1, const eMarkerEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumMarkerEnum;
extern PLMXML_CONSTRAINT60_API eMarkerEnum eMarkerEnumUnset;
extern PLMXML_CONSTRAINT60_API eMarkerEnum eMarkerEnumReferenceFrame;
extern PLMXML_CONSTRAINT60_API eMarkerEnum eMarkerEnumToolFrame;
extern PLMXML_CONSTRAINT60_API eMarkerEnum eMarkerEnumLocator;
extern PLMXML_CONSTRAINT60_API eMarkerEnum eMarkerEnumToolCentrePointFrame;
extern PLMXML_CONSTRAINT60_API eMarkerEnum eMarkerEnumBaseFrame;

////////////////////////////////////////////////////////////////////////////////////
//! eConstraintTorusCoincidenceEnum class
/*!
Allowed Values:
\verbatim
  eConstraintTorusCoincidenceEnumCoincidentAroundSpine
	"coincidentAroundSpine"
  eConstraintTorusCoincidenceEnumCoincident
	"coincident"
  eConstraintTorusCoincidenceEnumCoincidentWithSpine
	"coincidentWithSpine"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConstraintTorusCoincidenceEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConstraintTorusCoincidenceEnum( const char* Type );
     
	//! Constructor
	eConstraintTorusCoincidenceEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConstraintTorusCoincidenceEnum( );
     
	//! Destructor 
	virtual ~eConstraintTorusCoincidenceEnum( );
     
	//! Assign from 'Type'
	const eConstraintTorusCoincidenceEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConstraintTorusCoincidenceEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConstraintTorusCoincidenceEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConstraintTorusCoincidenceEnum& e1, const eConstraintTorusCoincidenceEnum& e2 );
     
	//! Compare ConstraintTorusCoincidenceEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConstraintTorusCoincidenceEnum& e1, const eConstraintTorusCoincidenceEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConstraintTorusCoincidenceEnum;
extern PLMXML_CONSTRAINT60_API eConstraintTorusCoincidenceEnum eConstraintTorusCoincidenceEnumUnset;
extern PLMXML_CONSTRAINT60_API eConstraintTorusCoincidenceEnum eConstraintTorusCoincidenceEnumCoincidentAroundSpine;
extern PLMXML_CONSTRAINT60_API eConstraintTorusCoincidenceEnum eConstraintTorusCoincidenceEnumCoincident;
extern PLMXML_CONSTRAINT60_API eConstraintTorusCoincidenceEnum eConstraintTorusCoincidenceEnumCoincidentWithSpine;

////////////////////////////////////////////////////////////////////////////////////
//! eGeometryDefinitionEnum class
/*!
Allowed Values:
\verbatim
  eGeometryDefinitionEnumDirect
	"direct"
  eGeometryDefinitionEnumTwoFaces
	"twoFaces"
  eGeometryDefinitionEnumEdgeStart
	"edgeStart"
  eGeometryDefinitionEnumEdgeEnd
	"edgeEnd"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eGeometryDefinitionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eGeometryDefinitionEnum( const char* Type );
     
	//! Constructor
	eGeometryDefinitionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eGeometryDefinitionEnum( );
     
	//! Destructor 
	virtual ~eGeometryDefinitionEnum( );
     
	//! Assign from 'Type'
	const eGeometryDefinitionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eGeometryDefinitionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare GeometryDefinitionEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eGeometryDefinitionEnum& e1, const eGeometryDefinitionEnum& e2 );
     
	//! Compare GeometryDefinitionEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eGeometryDefinitionEnum& e1, const eGeometryDefinitionEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumGeometryDefinitionEnum;
extern PLMXML_CONSTRAINT60_API eGeometryDefinitionEnum eGeometryDefinitionEnumUnset;
extern PLMXML_CONSTRAINT60_API eGeometryDefinitionEnum eGeometryDefinitionEnumDirect;
extern PLMXML_CONSTRAINT60_API eGeometryDefinitionEnum eGeometryDefinitionEnumTwoFaces;
extern PLMXML_CONSTRAINT60_API eGeometryDefinitionEnum eGeometryDefinitionEnumEdgeStart;
extern PLMXML_CONSTRAINT60_API eGeometryDefinitionEnum eGeometryDefinitionEnumEdgeEnd;

////////////////////////////////////////////////////////////////////////////////////
//! eSolverParameterEnum class
/*!
Allowed Values:
\verbatim
  eSolverParameterEnumMaxKinematicsIterations
	"maxKinematicsIterations"
  eSolverParameterEnumMaxIntegratorIterations
	"maxIntegratorIterations"
  eSolverParameterEnumMaxEquilibriumIterations
	"maxEquilibriumIterations"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eSolverParameterEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSolverParameterEnum( const char* Type );
     
	//! Constructor
	eSolverParameterEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSolverParameterEnum( );
     
	//! Destructor 
	virtual ~eSolverParameterEnum( );
     
	//! Assign from 'Type'
	const eSolverParameterEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSolverParameterEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SolverParameterEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eSolverParameterEnum& e1, const eSolverParameterEnum& e2 );
     
	//! Compare SolverParameterEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eSolverParameterEnum& e1, const eSolverParameterEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSolverParameterEnum;
extern PLMXML_CONSTRAINT60_API eSolverParameterEnum eSolverParameterEnumUnset;
extern PLMXML_CONSTRAINT60_API eSolverParameterEnum eSolverParameterEnumMaxKinematicsIterations;
extern PLMXML_CONSTRAINT60_API eSolverParameterEnum eSolverParameterEnumMaxIntegratorIterations;
extern PLMXML_CONSTRAINT60_API eSolverParameterEnum eSolverParameterEnumMaxEquilibriumIterations;

////////////////////////////////////////////////////////////////////////////////////
//! eConditionEnum class
/*!
Allowed Values:
\verbatim
  eConditionEnumGreaterThan
	"greaterThan"
  eConditionEnumLessThan
	"lessThan"
  eConditionEnumLessThanOrEqual
	"lessThanOrEqual"
  eConditionEnumGreaterThanOrEqual
	"greaterThanOrEqual"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConditionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConditionEnum( const char* Type );
     
	//! Constructor
	eConditionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConditionEnum( );
     
	//! Destructor 
	virtual ~eConditionEnum( );
     
	//! Assign from 'Type'
	const eConditionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConditionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConditionEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConditionEnum& e1, const eConditionEnum& e2 );
     
	//! Compare ConditionEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConditionEnum& e1, const eConditionEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConditionEnum;
extern PLMXML_CONSTRAINT60_API eConditionEnum eConditionEnumUnset;
extern PLMXML_CONSTRAINT60_API eConditionEnum eConditionEnumGreaterThan;
extern PLMXML_CONSTRAINT60_API eConditionEnum eConditionEnumLessThan;
extern PLMXML_CONSTRAINT60_API eConditionEnum eConditionEnumLessThanOrEqual;
extern PLMXML_CONSTRAINT60_API eConditionEnum eConditionEnumGreaterThanOrEqual;

////////////////////////////////////////////////////////////////////////////////////
//! eConstraintHalfSpaceEnum class
/*!
Allowed Values:
\verbatim
  eConstraintHalfSpaceEnumPositive
	"positive"
  eConstraintHalfSpaceEnumNegative
	"negative"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConstraintHalfSpaceEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConstraintHalfSpaceEnum( const char* Type );
     
	//! Constructor
	eConstraintHalfSpaceEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConstraintHalfSpaceEnum( );
     
	//! Destructor 
	virtual ~eConstraintHalfSpaceEnum( );
     
	//! Assign from 'Type'
	const eConstraintHalfSpaceEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConstraintHalfSpaceEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConstraintHalfSpaceEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConstraintHalfSpaceEnum& e1, const eConstraintHalfSpaceEnum& e2 );
     
	//! Compare ConstraintHalfSpaceEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConstraintHalfSpaceEnum& e1, const eConstraintHalfSpaceEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConstraintHalfSpaceEnum;
extern PLMXML_CONSTRAINT60_API eConstraintHalfSpaceEnum eConstraintHalfSpaceEnumUnset;
extern PLMXML_CONSTRAINT60_API eConstraintHalfSpaceEnum eConstraintHalfSpaceEnumPositive;
extern PLMXML_CONSTRAINT60_API eConstraintHalfSpaceEnum eConstraintHalfSpaceEnumNegative;

////////////////////////////////////////////////////////////////////////////////////
//! eMotorEnum class
/*!
Allowed Values:
\verbatim
  eMotorEnumVelocity
	"velocity"
  eMotorEnumForce
	"force"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eMotorEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eMotorEnum( const char* Type );
     
	//! Constructor
	eMotorEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eMotorEnum( );
     
	//! Destructor 
	virtual ~eMotorEnum( );
     
	//! Assign from 'Type'
	const eMotorEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eMotorEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare MotorEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eMotorEnum& e1, const eMotorEnum& e2 );
     
	//! Compare MotorEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eMotorEnum& e1, const eMotorEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumMotorEnum;
extern PLMXML_CONSTRAINT60_API eMotorEnum eMotorEnumUnset;
extern PLMXML_CONSTRAINT60_API eMotorEnum eMotorEnumVelocity;
extern PLMXML_CONSTRAINT60_API eMotorEnum eMotorEnumForce;

////////////////////////////////////////////////////////////////////////////////////
//! eConstraintPrecedenceEnum class
/*!
Allowed Values:
\verbatim
  eConstraintPrecedenceEnumParameterSpace
	"parameterSpace"
  eConstraintPrecedenceEnumModelSpace
	"modelSpace"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eConstraintPrecedenceEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eConstraintPrecedenceEnum( const char* Type );
     
	//! Constructor
	eConstraintPrecedenceEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eConstraintPrecedenceEnum( );
     
	//! Destructor 
	virtual ~eConstraintPrecedenceEnum( );
     
	//! Assign from 'Type'
	const eConstraintPrecedenceEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eConstraintPrecedenceEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ConstraintPrecedenceEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eConstraintPrecedenceEnum& e1, const eConstraintPrecedenceEnum& e2 );
     
	//! Compare ConstraintPrecedenceEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eConstraintPrecedenceEnum& e1, const eConstraintPrecedenceEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumConstraintPrecedenceEnum;
extern PLMXML_CONSTRAINT60_API eConstraintPrecedenceEnum eConstraintPrecedenceEnumUnset;
extern PLMXML_CONSTRAINT60_API eConstraintPrecedenceEnum eConstraintPrecedenceEnumParameterSpace;
extern PLMXML_CONSTRAINT60_API eConstraintPrecedenceEnum eConstraintPrecedenceEnumModelSpace;

////////////////////////////////////////////////////////////////////////////////////
//! eJointEnum class
/*!
Allowed Values:
\verbatim
  eJointEnumRevolute
	"revolute"
  eJointEnumSpherical
	"spherical"
  eJointEnumConstantVelocity
	"constantVelocity"
  eJointEnumPerpendicular
	"perpendicular"
  eJointEnumInline
	"inline"
  eJointEnumFixed
	"fixed"
  eJointEnumInplane
	"inplane"
  eJointEnumUniversal
	"universal"
  eJointEnumAtpoint
	"atpoint"
  eJointEnumParallel
	"parallel"
  eJointEnumScrew
	"screw"
  eJointEnumCylindrical
	"cylindrical"
  eJointEnumTranslational
	"translational"
  eJointEnumOrientation
	"orientation"
  eJointEnumPlanar
	"planar"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eJointEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eJointEnum( const char* Type );
     
	//! Constructor
	eJointEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eJointEnum( );
     
	//! Destructor 
	virtual ~eJointEnum( );
     
	//! Assign from 'Type'
	const eJointEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eJointEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare JointEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eJointEnum& e1, const eJointEnum& e2 );
     
	//! Compare JointEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eJointEnum& e1, const eJointEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumJointEnum;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumUnset;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumRevolute;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumSpherical;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumConstantVelocity;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumPerpendicular;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumInline;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumFixed;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumInplane;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumUniversal;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumAtpoint;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumParallel;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumScrew;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumCylindrical;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumTranslational;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumOrientation;
extern PLMXML_CONSTRAINT60_API eJointEnum eJointEnumPlanar;

////////////////////////////////////////////////////////////////////////////////////
//! eSolverAnalysisEnum class
/*!
Allowed Values:
\verbatim
  eSolverAnalysisEnumKinematics
	"kinematics"
  eSolverAnalysisEnumDynamics
	"dynamics"
  eSolverAnalysisEnumStatics
	"statics"
  
\endverbatim
*/
class PLMXML_CONSTRAINT60_API eSolverAnalysisEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSolverAnalysisEnum( const char* Type );
     
	//! Constructor
	eSolverAnalysisEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSolverAnalysisEnum( );
     
	//! Destructor 
	virtual ~eSolverAnalysisEnum( );
     
	//! Assign from 'Type'
	const eSolverAnalysisEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSolverAnalysisEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SolverAnalysisEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator==( const eSolverAnalysisEnum& e1, const eSolverAnalysisEnum& e2 );
     
	//! Compare SolverAnalysisEnum
	friend plmxml_api::logical PLMXML_CONSTRAINT60_API operator!=( const eSolverAnalysisEnum& e1, const eSolverAnalysisEnum& e2 );
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSolverAnalysisEnum;
extern PLMXML_CONSTRAINT60_API eSolverAnalysisEnum eSolverAnalysisEnumUnset;
extern PLMXML_CONSTRAINT60_API eSolverAnalysisEnum eSolverAnalysisEnumKinematics;
extern PLMXML_CONSTRAINT60_API eSolverAnalysisEnum eSolverAnalysisEnumDynamics;
extern PLMXML_CONSTRAINT60_API eSolverAnalysisEnum eSolverAnalysisEnumStatics;

////////////////////////////////////////////////////////////////////////////////////
//! ConstraintHelp class
/*!
\verbatim

            Constraint Help information. The type attribute determines which other attributes are allowed,
            as follows:

                                point   u       v       precedence

            boundary            no      no      no      no
            centre              no      no      no      no
            point               yes     no      no      no
            paramUV             no      yes     yes     no
            paramU              no      yes     no      no
            surfacePoint        yes     yes     yes     yes
            curvePoint          yes     yes     no      yes

            Attributes:

            type:           specifies the type of Help information included
            point:          2D or 3D point coordinates
            u:              u parameter (curve or surface)
            v:              v parameter (surface)
            precedence:     specifies whether the 3D point, or the parameters are to take precedence. For
                            example, the 3D point may be precise, and the parameter(s) an approximation.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ConstraintHelp : public IdObject
{
public:
     
    //! Default constructor
    ConstraintHelp( );
     
    //! Constructs a ConstraintHelp with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConstraintHelp( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConstraintHelp();

private:

	//! Assignment operator
	ConstraintHelp& operator=( const ConstraintHelp& iSrc );

	//! Copy constructor
	ConstraintHelp( const ConstraintHelp& original );
     
public:

	//! Set Precedence
	plmxml_api::Result SetPrecedence( const eConstraintPrecedenceEnum& arg );

	//! Get Precedence
	eConstraintPrecedenceEnum GetPrecedence() const;

	//! Set Type
	plmxml_api::Result SetType( const eConstraintHelpEnum& arg );

	//! Get Type
	eConstraintHelpEnum GetType() const;

	//! Set Coordinates
	plmxml_api::Result SetCoordinates( const plmxml_api::Array<double>& arg );

	//! Get Coordinates
	plmxml_api::Result GetCoordinates( plmxml_api::Array<double>& arg ) const;

	//! Check if Coordinates is set
	plmxml_api::logical HasCoordinates() const;

	//! Unset Coordinates
	plmxml_api::Result UnsetCoordinates();

	//! Set V
	plmxml_api::Result SetV( double arg );

     //! Get V
	double GetV() const;

	//! Check if V is set
	plmxml_api::logical HasV() const;

	//! Unset V
	plmxml_api::Result UnsetV();

	//! Set U
	plmxml_api::Result SetU( double arg );

     //! Get U
	double GetU() const;

	//! Check if U is set
	plmxml_api::logical HasU() const;

	//! Unset U
	plmxml_api::Result UnsetU();
 
// <PLMXML_UserCode type="functionHeaderConstraintHelp" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassConstraintHelp;


////////////////////////////////////////////////////////////////////////////////////
//! GeometryData class
/*!
\verbatim

            A GeometryData element contains information about a geometric object.

            Attributes:

            geometryType:   the type of the geometry.
            planar:         true if the geometry is a planar curve
            geometrySubType: additional information about the geometry
            definition:     How the geometry is defined.
            targetRefs:     Additional references if the geometry is defined
                            indirectly by more than one reference.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API GeometryData : public IdObject
{
public:
     
    //! Default constructor
    GeometryData( );
     
    //! Constructs a GeometryData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    GeometryData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~GeometryData();

private:

	//! Assignment operator
	GeometryData& operator=( const GeometryData& iSrc );

	//! Copy constructor
	GeometryData( const GeometryData& original );
     
public:

	//! Set Definition
	plmxml_api::Result SetDefinition( const eGeometryDefinitionEnum& arg );

	//! Get Definition
	eGeometryDefinitionEnum GetDefinition() const;

	//! Set GeometryType
	plmxml_api::Result SetGeometryType( const eGeometryTypeEnum& arg );

	//! Get GeometryType
	eGeometryTypeEnum GetGeometryType() const;

	//! Set Planar
	plmxml_api::Result SetPlanar( plmxml_api::logical arg );

	//! Get Planar
	plmxml_api::logical GetPlanar() const;

	//! Check if Planar is set
	plmxml_api::logical HasPlanar() const;

	//! Unset Planar
	plmxml_api::Result UnsetPlanar();

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

	//! Set GeometrySubType
	plmxml_api::Result SetGeometrySubType( const eGeometrySubTypeEnum& arg );

	//! Get GeometrySubType
	eGeometrySubTypeEnum GetGeometrySubType() const;
 
// <PLMXML_UserCode type="functionHeaderGeometryData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassGeometryData;


////////////////////////////////////////////////////////////////////////////////////
//! ConstraintTargetRef class
/*!
\verbatim

            A ConstraintTargetRef is a means of referencing the target of a constraint, typically a
            geometric object, together with associated information required by the constraint. It uses the
            "occurrenceRef" attribute, and "EntityRef" sub-element, inherited from GDEReferenceType.

            Attributes:

            halfSpace:      specifies the relevant halfspace of the geometry.
            occurrenceRef:  Inherited from GDEReference. References a MechanismOccurrence. See the
                            "Representing Feature Semantics" Chapter of the PLM XML Schema Functional
                            Description.
            pathRefs:       Inherited from GDEReference. References a list of MechanismInstances, which
                            defines an occurrence of a Mechanism object by defining a unique path through
                            an instance graph.
            targetRef:      Inherited from GDEReference. References the target Marker, Joint or geometry.
            degreeOfFreedom: If the target of the constraint is a Joint, degreeOfFreedom specifies the
                            degree of freedom of the Joint that the ConstraintTargetRef targets.

            Sub-elements:

            ConstraintHelp: an element derived from ConstraintHelp, which assists the constraint solver.
            GeometryData:   If the target is geometry, GeometryData contains information about the
                            geometric object.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ConstraintTargetRef : public GDEReference
{
public:
     
    //! Default constructor
    ConstraintTargetRef( );
     
    //! Constructs a ConstraintTargetRef with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConstraintTargetRef( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConstraintTargetRef();

private:

	//! Assignment operator
	ConstraintTargetRef& operator=( const ConstraintTargetRef& iSrc );

	//! Copy constructor
	ConstraintTargetRef( const ConstraintTargetRef& original );
     
public:

	//! Set HalfSpace
	plmxml_api::Result SetHalfSpace( const eConstraintHalfSpaceEnum& arg );

	//! Get HalfSpace
	eConstraintHalfSpaceEnum GetHalfSpace() const;

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Add ConstraintHelp child element to this ConstraintTargetRef. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintHelp *AddConstraintHelp();
     
	//! Set ConstraintHelp child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintHelp( ConstraintHelp *arg );
     
	//! Get ConstraintHelp child element of this ConstraintTargetRef.
	ConstraintHelp *GetConstraintHelp() const;
     
	//! Detach and delete ConstraintHelp child element tree from this ConstraintTargetRef.
	void DeleteConstraintHelp();

	//! Add GeometryData child element to this ConstraintTargetRef. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	GeometryData *AddGeometryData();
     
	//! Set GeometryData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetGeometryData( GeometryData *arg );
     
	//! Get GeometryData child element of this ConstraintTargetRef.
	GeometryData *GetGeometryData() const;
     
	//! Detach and delete GeometryData child element tree from this ConstraintTargetRef.
	void DeleteGeometryData();
 
// <PLMXML_UserCode type="functionHeaderConstraintTargetRef" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassConstraintTargetRef;


////////////////////////////////////////////////////////////////////////////////////
//! ConstraintData class
/*!
\verbatim

            A ConstraintData element contains information which defines a constraint.

            Attributes:

            value:          the numerical value of the constraint, in metres or radians.
            dimension:      whether a 2- or 3-dimensional constraint.
            orientation:    surface orientation - "align" or "antiAlign"
            alignment:      direction alignment - "align" or "antiAlign"
            torusCoincidence: additional information for when the constraint involves coincidence with a
                            torus.
            suppressed:     true if this constraint is not to be used when solving the system of
                            constraints.
            rigid:          true if the constraint is "rigid", i.e. it is not necessarily possible to vary
                            the value of the constraint while fixing the values of all the other
                            constraints.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ConstraintData : public IdObject
{
public:
     
    //! Default constructor
    ConstraintData( );
     
    //! Constructs a ConstraintData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConstraintData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConstraintData();

private:

	//! Assignment operator
	ConstraintData& operator=( const ConstraintData& iSrc );

	//! Copy constructor
	ConstraintData( const ConstraintData& original );
     
public:

	//! Set Rigid
	plmxml_api::Result SetRigid( plmxml_api::logical arg );

	//! Get Rigid
	plmxml_api::logical GetRigid() const;

	//! Check if Rigid is set
	plmxml_api::logical HasRigid() const;

	//! Unset Rigid
	plmxml_api::Result UnsetRigid();

	//! Set Orientation
	plmxml_api::Result SetOrientation( const eConstraintAlignmentEnum& arg );

	//! Get Orientation
	eConstraintAlignmentEnum GetOrientation() const;

	//! Set Suppressed
	plmxml_api::Result SetSuppressed( plmxml_api::logical arg );

	//! Get Suppressed
	plmxml_api::logical GetSuppressed() const;

	//! Check if Suppressed is set
	plmxml_api::logical HasSuppressed() const;

	//! Unset Suppressed
	plmxml_api::Result UnsetSuppressed();

	//! Set TorusCoincidence
	plmxml_api::Result SetTorusCoincidence( const eConstraintTorusCoincidenceEnum& arg );

	//! Get TorusCoincidence
	eConstraintTorusCoincidenceEnum GetTorusCoincidence() const;

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();

	//! Set Alignment
	plmxml_api::Result SetAlignment( const eConstraintAlignmentEnum& arg );

	//! Get Alignment
	eConstraintAlignmentEnum GetAlignment() const;

	//! Set Dimension
	plmxml_api::Result SetDimension( int arg );
     
	//! Get Dimension
	int GetDimension() const;
     
	//! Check if Dimension is set
	plmxml_api::logical HasDimension() const;
     
	//! Unset Dimension
	plmxml_api::Result UnsetDimension();
 
// <PLMXML_UserCode type="functionHeaderConstraintData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassConstraintData;


//! Forward class declarations
class JointData;
class FrictionData;
class DriverData;
class ForceData;
class SpringData;
class DamperData;
class BushingData;
class ContactData;
class CouplerData;
class LimitsDependencyData;

////////////////////////////////////////////////////////////////////////////////////
//! Constraint class
/*!
\verbatim

            A Constraint is a subclass of GDE that models a condition applied to
            occurrences of geometric objects in a Product Structure or Mechanism
            objects in a Mechanism Structure.

            Attributes:

            type: The type of the Constraint (concentric, parallel, et cetera).

            Sub-elements:

            ConstraintData: Data defining a geometric Constraint or a Contact
                            Constraint.
            ConstraintTargetRef: References to constrained geometry.
            JointData:      Additional data for a Joint Constraint.
            FrictionData:   Additional data for a Friction Constraint or a Joint
                            Constraint.
            DriverData:     Additional data for a Driver Constraint or a Joint
                            Constraint.
            ForceData:      Additional data for a Force Constraint.
            SpringData:     Additional data for a Spring Constraint.
            DamperData:     Additional data for a Damper Constraint.
            BushingData:    Additional data for a Bushing Constraint.
            ContactData:    Additional data for a Contact Constraint.
            CouplerData:    Additional data for a Coupler Constraint or a Joint
                            Constraint that infers a Joint.
            LimitsDependencyData: Additional data for a Limits Dependency
                            Constraint.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Constraint : public GDE
{
public:
     
    //! Default constructor
    Constraint( );
     
    //! Constructs a Constraint with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Constraint( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Constraint();

private:

	//! Assignment operator
	Constraint& operator=( const Constraint& iSrc );

	//! Copy constructor
	Constraint( const Constraint& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eConstraintEnum& arg );

	//! Get Type
	eConstraintEnum GetType() const;

	//! Add ConstraintData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintData *AddConstraintData();
     
	//! Set ConstraintData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintData( ConstraintData *arg );
     
	//! Get ConstraintData child element of this Constraint.
	ConstraintData *GetConstraintData() const;
     
	//! Detach and delete ConstraintData child element tree from this Constraint.
	void DeleteConstraintData();

	//! Add ConstraintTargetRef child element to this Constraint. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintTargetRef *AddConstraintTargetRef();
     
	//! Add 'arg' as ConstraintTargetRef child element to this Constraint.
	plmxml_api::Result AddConstraintTargetRef( ConstraintTargetRef *arg );

	//! Detach and delete all ConstraintTargetRef child elements.
	void DeleteConstraintTargetRefs();
     
	//! Get number of ConstraintTargetRef child elements.
	int NumberOfConstraintTargetRefs() const;
     
	//! Get i'th ConstraintTargetRef child element.
	ConstraintTargetRef *GetConstraintTargetRef( int i ) const;
     
	//! Get all ConstraintTargetRef child element as an array
	void GetConstraintTargetRefs( plmxml_api::Array<ConstraintTargetRef*> &array ) const;
	     
	//! Detach and delete i'th ConstraintTargetRef child element
	void DeleteConstraintTargetRef( int i );
     
	//! Detach and delete 'arg' if it's one of the ConstraintTargetRef child elements
	void DeleteConstraintTargetRef( ConstraintTargetRef *arg );

	//! Add JointData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	JointData *AddJointData();
     
	//! Set JointData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetJointData( JointData *arg );
     
	//! Get JointData child element of this Constraint.
	JointData *GetJointData() const;
     
	//! Detach and delete JointData child element tree from this Constraint.
	void DeleteJointData();

	//! Add FrictionData child element to this Constraint. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FrictionData *AddFrictionData();
     
	//! Add 'arg' as FrictionData child element to this Constraint.
	plmxml_api::Result AddFrictionData( FrictionData *arg );

	//! Detach and delete all FrictionData child elements.
	void DeleteFrictionDatas();
     
	//! Get number of FrictionData child elements.
	int NumberOfFrictionDatas() const;
     
	//! Get i'th FrictionData child element.
	FrictionData *GetFrictionData( int i ) const;
     
	//! Get all FrictionData child element as an array
	void GetFrictionDatas( plmxml_api::Array<FrictionData*> &array ) const;
	     
	//! Detach and delete i'th FrictionData child element
	void DeleteFrictionData( int i );
     
	//! Detach and delete 'arg' if it's one of the FrictionData child elements
	void DeleteFrictionData( FrictionData *arg );

	//! Add DriverData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DriverData *AddDriverData();
     
	//! Set DriverData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDriverData( DriverData *arg );
     
	//! Get DriverData child element of this Constraint.
	DriverData *GetDriverData() const;
     
	//! Detach and delete DriverData child element tree from this Constraint.
	void DeleteDriverData();

	//! Add ForceData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ForceData *AddForceData();
     
	//! Set ForceData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetForceData( ForceData *arg );
     
	//! Get ForceData child element of this Constraint.
	ForceData *GetForceData() const;
     
	//! Detach and delete ForceData child element tree from this Constraint.
	void DeleteForceData();

	//! Add SpringData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SpringData *AddSpringData();
     
	//! Set SpringData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSpringData( SpringData *arg );
     
	//! Get SpringData child element of this Constraint.
	SpringData *GetSpringData() const;
     
	//! Detach and delete SpringData child element tree from this Constraint.
	void DeleteSpringData();

	//! Add DamperData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DamperData *AddDamperData();
     
	//! Set DamperData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDamperData( DamperData *arg );
     
	//! Get DamperData child element of this Constraint.
	DamperData *GetDamperData() const;
     
	//! Detach and delete DamperData child element tree from this Constraint.
	void DeleteDamperData();

	//! Add BushingData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	BushingData *AddBushingData();
     
	//! Set BushingData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetBushingData( BushingData *arg );
     
	//! Get BushingData child element of this Constraint.
	BushingData *GetBushingData() const;
     
	//! Detach and delete BushingData child element tree from this Constraint.
	void DeleteBushingData();

	//! Add ContactData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ContactData *AddContactData();
     
	//! Set ContactData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetContactData( ContactData *arg );
     
	//! Get ContactData child element of this Constraint.
	ContactData *GetContactData() const;
     
	//! Detach and delete ContactData child element tree from this Constraint.
	void DeleteContactData();

	//! Add CouplerData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	CouplerData *AddCouplerData();
     
	//! Set CouplerData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCouplerData( CouplerData *arg );
     
	//! Get CouplerData child element of this Constraint.
	CouplerData *GetCouplerData() const;
     
	//! Detach and delete CouplerData child element tree from this Constraint.
	void DeleteCouplerData();

	//! Add LimitsDependencyData child element to this Constraint. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	LimitsDependencyData *AddLimitsDependencyData();
     
	//! Set LimitsDependencyData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLimitsDependencyData( LimitsDependencyData *arg );
     
	//! Get LimitsDependencyData child element of this Constraint.
	LimitsDependencyData *GetLimitsDependencyData() const;
     
	//! Detach and delete LimitsDependencyData child element tree from this Constraint.
	void DeleteLimitsDependencyData();
 
// <PLMXML_UserCode type="functionHeaderConstraint" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassConstraint;


//! Forward class declarations
class JointData;
class FrictionData;
class DriverData;
class ForceData;
class SpringData;
class DamperData;
class BushingData;
class ContactData;
class CouplerData;
class LimitsDependencyData;

////////////////////////////////////////////////////////////////////////////////////
//! ConstraintInstance class
/*!
\verbatim

          This subclass of GDEInstance may be used for instancing a Constraint.

          If a particular type of sub-element is present, the ConstraintInstance
          overrides the entire set of sub-elements of that type present under
          the Constraint.

          Sub-elements:

          ConstraintData: Overrides the data defining the geometric Constraint
                        or the Contact Constraint.
          ConstraintTargetRef: Overrides references to constrained geometry.
          JointData:    Overrides additional data for a Joint Constraint.
          FrictionData: Overrides additional data for a Friction Constraint or a
                        Joint Constraint.
          DriverData:   Overrides additional data for a Driver Constraint or a
                        Joint Constraint.
          ForceData:    Overrides additional data for a Force Constraint.
          SpringData:   Overrides additional data for a Spring Constraint.
          DamperData:   Overrides additional data for a Damper Constraint.
          BushingData:  Overrides additional data for a Bushing Constraint.
          ContactData:  Overrides additional data for a Contact Constraint.
          CouplerData:  Overrides additional data for a Coupler Constraint or a
                        Joint Constraint that infers a Joint.
          LimitsDependencyData: Additional data for a Limits Dependency
                        Constraint.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ConstraintInstance : public GDEInstance
{
public:
     
    //! Default constructor
    ConstraintInstance( );
     
    //! Constructs a ConstraintInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConstraintInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConstraintInstance();

private:

	//! Assignment operator
	ConstraintInstance& operator=( const ConstraintInstance& iSrc );

	//! Copy constructor
	ConstraintInstance( const ConstraintInstance& original );
     
public:

	//! Add ConstraintData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintData *AddConstraintData();
     
	//! Set ConstraintData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintData( ConstraintData *arg );
     
	//! Get ConstraintData child element of this ConstraintInstance.
	ConstraintData *GetConstraintData() const;
     
	//! Detach and delete ConstraintData child element tree from this ConstraintInstance.
	void DeleteConstraintData();

	//! Add ConstraintTargetRef child element to this ConstraintInstance. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintTargetRef *AddConstraintTargetRef();
     
	//! Add 'arg' as ConstraintTargetRef child element to this ConstraintInstance.
	plmxml_api::Result AddConstraintTargetRef( ConstraintTargetRef *arg );

	//! Detach and delete all ConstraintTargetRef child elements.
	void DeleteConstraintTargetRefs();
     
	//! Get number of ConstraintTargetRef child elements.
	int NumberOfConstraintTargetRefs() const;
     
	//! Get i'th ConstraintTargetRef child element.
	ConstraintTargetRef *GetConstraintTargetRef( int i ) const;
     
	//! Get all ConstraintTargetRef child element as an array
	void GetConstraintTargetRefs( plmxml_api::Array<ConstraintTargetRef*> &array ) const;
	     
	//! Detach and delete i'th ConstraintTargetRef child element
	void DeleteConstraintTargetRef( int i );
     
	//! Detach and delete 'arg' if it's one of the ConstraintTargetRef child elements
	void DeleteConstraintTargetRef( ConstraintTargetRef *arg );

	//! Add JointData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	JointData *AddJointData();
     
	//! Set JointData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetJointData( JointData *arg );
     
	//! Get JointData child element of this ConstraintInstance.
	JointData *GetJointData() const;
     
	//! Detach and delete JointData child element tree from this ConstraintInstance.
	void DeleteJointData();

	//! Add FrictionData child element to this ConstraintInstance. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FrictionData *AddFrictionData();
     
	//! Add 'arg' as FrictionData child element to this ConstraintInstance.
	plmxml_api::Result AddFrictionData( FrictionData *arg );

	//! Detach and delete all FrictionData child elements.
	void DeleteFrictionDatas();
     
	//! Get number of FrictionData child elements.
	int NumberOfFrictionDatas() const;
     
	//! Get i'th FrictionData child element.
	FrictionData *GetFrictionData( int i ) const;
     
	//! Get all FrictionData child element as an array
	void GetFrictionDatas( plmxml_api::Array<FrictionData*> &array ) const;
	     
	//! Detach and delete i'th FrictionData child element
	void DeleteFrictionData( int i );
     
	//! Detach and delete 'arg' if it's one of the FrictionData child elements
	void DeleteFrictionData( FrictionData *arg );

	//! Add DriverData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DriverData *AddDriverData();
     
	//! Set DriverData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDriverData( DriverData *arg );
     
	//! Get DriverData child element of this ConstraintInstance.
	DriverData *GetDriverData() const;
     
	//! Detach and delete DriverData child element tree from this ConstraintInstance.
	void DeleteDriverData();

	//! Add ForceData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ForceData *AddForceData();
     
	//! Set ForceData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetForceData( ForceData *arg );
     
	//! Get ForceData child element of this ConstraintInstance.
	ForceData *GetForceData() const;
     
	//! Detach and delete ForceData child element tree from this ConstraintInstance.
	void DeleteForceData();

	//! Add SpringData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SpringData *AddSpringData();
     
	//! Set SpringData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSpringData( SpringData *arg );
     
	//! Get SpringData child element of this ConstraintInstance.
	SpringData *GetSpringData() const;
     
	//! Detach and delete SpringData child element tree from this ConstraintInstance.
	void DeleteSpringData();

	//! Add DamperData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DamperData *AddDamperData();
     
	//! Set DamperData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDamperData( DamperData *arg );
     
	//! Get DamperData child element of this ConstraintInstance.
	DamperData *GetDamperData() const;
     
	//! Detach and delete DamperData child element tree from this ConstraintInstance.
	void DeleteDamperData();

	//! Add BushingData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	BushingData *AddBushingData();
     
	//! Set BushingData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetBushingData( BushingData *arg );
     
	//! Get BushingData child element of this ConstraintInstance.
	BushingData *GetBushingData() const;
     
	//! Detach and delete BushingData child element tree from this ConstraintInstance.
	void DeleteBushingData();

	//! Add ContactData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ContactData *AddContactData();
     
	//! Set ContactData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetContactData( ContactData *arg );
     
	//! Get ContactData child element of this ConstraintInstance.
	ContactData *GetContactData() const;
     
	//! Detach and delete ContactData child element tree from this ConstraintInstance.
	void DeleteContactData();

	//! Add CouplerData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	CouplerData *AddCouplerData();
     
	//! Set CouplerData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCouplerData( CouplerData *arg );
     
	//! Get CouplerData child element of this ConstraintInstance.
	CouplerData *GetCouplerData() const;
     
	//! Detach and delete CouplerData child element tree from this ConstraintInstance.
	void DeleteCouplerData();

	//! Add LimitsDependencyData child element to this ConstraintInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	LimitsDependencyData *AddLimitsDependencyData();
     
	//! Set LimitsDependencyData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLimitsDependencyData( LimitsDependencyData *arg );
     
	//! Get LimitsDependencyData child element of this ConstraintInstance.
	LimitsDependencyData *GetLimitsDependencyData() const;
     
	//! Detach and delete LimitsDependencyData child element tree from this ConstraintInstance.
	void DeleteLimitsDependencyData();
 
// <PLMXML_UserCode type="functionHeaderConstraintInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassConstraintInstance;


//! Forward class declarations
class JointData;
class FrictionData;
class DriverData;
class ForceData;
class SpringData;
class DamperData;
class BushingData;
class ContactData;
class CouplerData;
class LimitsDependencyData;

////////////////////////////////////////////////////////////////////////////////////
//! ConstraintOccurrence class
/*!
\verbatim

          This subclass of Occurrence may be used where the Occurrence
          references a Constraint.

          If a particular type of sub-element is present, the
          ConstraintOccurrence overrides the entire set of sub-elements of that
          type present under the ConstraintInstance or Constraint.

          Sub-elements:

          ConstraintData: Overrides the data defining the geometric Constraint
                        or the Contact Constraint.
          ConstraintTargetRef: Overrides references to constrained geometry.
          JointData:    Overrides additional data for a Joint Constraint.
          FrictionData: Overrides additional data for a Friction Constraint or a
                        Joint Constraint.
          DriverData:   Overrides additional data for a Driver Constraint or a
                        Joint Constraint.
          ForceData:    Overrides additional data for a Force Constraint.
          SpringData:   Overrides additional data for a Spring Constraint.
          DamperData:   Overrides additional data for a Damper Constraint.
          BushingData:  Overrides additional data for a Bushing Constraint.
          ContactData:  Overrides additional data for a Contact Constraint.
          CouplerData:  Overrides additional data for a Coupler Constraint or a
                        Joint Constraint that infers a Joint.
          LimitsDependencyData: Additional data for a Limits Dependency
                        Constraint.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ConstraintOccurrence : public Occurrence
{
public:
     
    //! Default constructor
    ConstraintOccurrence( );
     
    //! Constructs a ConstraintOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ConstraintOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ConstraintOccurrence();

private:

	//! Assignment operator
	ConstraintOccurrence& operator=( const ConstraintOccurrence& iSrc );

	//! Copy constructor
	ConstraintOccurrence( const ConstraintOccurrence& original );
     
public:

	//! Add ConstraintData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintData *AddConstraintData();
     
	//! Set ConstraintData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetConstraintData( ConstraintData *arg );
     
	//! Get ConstraintData child element of this ConstraintOccurrence.
	ConstraintData *GetConstraintData() const;
     
	//! Detach and delete ConstraintData child element tree from this ConstraintOccurrence.
	void DeleteConstraintData();

	//! Add ConstraintTargetRef child element to this ConstraintOccurrence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintTargetRef *AddConstraintTargetRef();
     
	//! Add 'arg' as ConstraintTargetRef child element to this ConstraintOccurrence.
	plmxml_api::Result AddConstraintTargetRef( ConstraintTargetRef *arg );

	//! Detach and delete all ConstraintTargetRef child elements.
	void DeleteConstraintTargetRefs();
     
	//! Get number of ConstraintTargetRef child elements.
	int NumberOfConstraintTargetRefs() const;
     
	//! Get i'th ConstraintTargetRef child element.
	ConstraintTargetRef *GetConstraintTargetRef( int i ) const;
     
	//! Get all ConstraintTargetRef child element as an array
	void GetConstraintTargetRefs( plmxml_api::Array<ConstraintTargetRef*> &array ) const;
	     
	//! Detach and delete i'th ConstraintTargetRef child element
	void DeleteConstraintTargetRef( int i );
     
	//! Detach and delete 'arg' if it's one of the ConstraintTargetRef child elements
	void DeleteConstraintTargetRef( ConstraintTargetRef *arg );

	//! Add JointData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	JointData *AddJointData();
     
	//! Set JointData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetJointData( JointData *arg );
     
	//! Get JointData child element of this ConstraintOccurrence.
	JointData *GetJointData() const;
     
	//! Detach and delete JointData child element tree from this ConstraintOccurrence.
	void DeleteJointData();

	//! Add FrictionData child element to this ConstraintOccurrence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	FrictionData *AddFrictionData();
     
	//! Add 'arg' as FrictionData child element to this ConstraintOccurrence.
	plmxml_api::Result AddFrictionData( FrictionData *arg );

	//! Detach and delete all FrictionData child elements.
	void DeleteFrictionDatas();
     
	//! Get number of FrictionData child elements.
	int NumberOfFrictionDatas() const;
     
	//! Get i'th FrictionData child element.
	FrictionData *GetFrictionData( int i ) const;
     
	//! Get all FrictionData child element as an array
	void GetFrictionDatas( plmxml_api::Array<FrictionData*> &array ) const;
	     
	//! Detach and delete i'th FrictionData child element
	void DeleteFrictionData( int i );
     
	//! Detach and delete 'arg' if it's one of the FrictionData child elements
	void DeleteFrictionData( FrictionData *arg );

	//! Add DriverData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DriverData *AddDriverData();
     
	//! Set DriverData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDriverData( DriverData *arg );
     
	//! Get DriverData child element of this ConstraintOccurrence.
	DriverData *GetDriverData() const;
     
	//! Detach and delete DriverData child element tree from this ConstraintOccurrence.
	void DeleteDriverData();

	//! Add ForceData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ForceData *AddForceData();
     
	//! Set ForceData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetForceData( ForceData *arg );
     
	//! Get ForceData child element of this ConstraintOccurrence.
	ForceData *GetForceData() const;
     
	//! Detach and delete ForceData child element tree from this ConstraintOccurrence.
	void DeleteForceData();

	//! Add SpringData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SpringData *AddSpringData();
     
	//! Set SpringData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSpringData( SpringData *arg );
     
	//! Get SpringData child element of this ConstraintOccurrence.
	SpringData *GetSpringData() const;
     
	//! Detach and delete SpringData child element tree from this ConstraintOccurrence.
	void DeleteSpringData();

	//! Add DamperData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DamperData *AddDamperData();
     
	//! Set DamperData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDamperData( DamperData *arg );
     
	//! Get DamperData child element of this ConstraintOccurrence.
	DamperData *GetDamperData() const;
     
	//! Detach and delete DamperData child element tree from this ConstraintOccurrence.
	void DeleteDamperData();

	//! Add BushingData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	BushingData *AddBushingData();
     
	//! Set BushingData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetBushingData( BushingData *arg );
     
	//! Get BushingData child element of this ConstraintOccurrence.
	BushingData *GetBushingData() const;
     
	//! Detach and delete BushingData child element tree from this ConstraintOccurrence.
	void DeleteBushingData();

	//! Add ContactData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ContactData *AddContactData();
     
	//! Set ContactData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetContactData( ContactData *arg );
     
	//! Get ContactData child element of this ConstraintOccurrence.
	ContactData *GetContactData() const;
     
	//! Detach and delete ContactData child element tree from this ConstraintOccurrence.
	void DeleteContactData();

	//! Add CouplerData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	CouplerData *AddCouplerData();
     
	//! Set CouplerData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCouplerData( CouplerData *arg );
     
	//! Get CouplerData child element of this ConstraintOccurrence.
	CouplerData *GetCouplerData() const;
     
	//! Detach and delete CouplerData child element tree from this ConstraintOccurrence.
	void DeleteCouplerData();

	//! Add LimitsDependencyData child element to this ConstraintOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	LimitsDependencyData *AddLimitsDependencyData();
     
	//! Set LimitsDependencyData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetLimitsDependencyData( LimitsDependencyData *arg );
     
	//! Get LimitsDependencyData child element of this ConstraintOccurrence.
	LimitsDependencyData *GetLimitsDependencyData() const;
     
	//! Detach and delete LimitsDependencyData child element tree from this ConstraintOccurrence.
	void DeleteLimitsDependencyData();
 
// <PLMXML_UserCode type="functionHeaderConstraintOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassConstraintOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! Mechanism class
/*!
\verbatim

            A revision-independent Mechanism, analogous to Product in the Product Structure.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Mechanism : public Structure
{
public:
     
    //! Default constructor
    Mechanism( );
     
    //! Constructs a Mechanism with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Mechanism( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Mechanism();

private:

	//! Assignment operator
	Mechanism& operator=( const Mechanism& iSrc );

	//! Copy constructor
	Mechanism( const Mechanism& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMechanism" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanism;


////////////////////////////////////////////////////////////////////////////////////
//! MechanismRevision class
/*!
\verbatim

            A revision of a Mechanism, analogous to a ProductRevision in the Product Structure.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismRevision : public StructureRevision
{
public:
     
    //! Default constructor
    MechanismRevision( );
     
    //! Constructs a MechanismRevision with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismRevision( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismRevision();

private:

	//! Assignment operator
	MechanismRevision& operator=( const MechanismRevision& iSrc );

	//! Copy constructor
	MechanismRevision( const MechanismRevision& original );
     
public:
 
// <PLMXML_UserCode type="functionHeaderMechanismRevision" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismRevision;


////////////////////////////////////////////////////////////////////////////////////
//! SolverParameter class
/*!
\verbatim

              A parameter for a particular Mechanism solver.

              Attributes:

              type:         The type of the Mechanism solver as a SolverEnum.
              title:        The type of the Mechanism solver parameter as a SolverParameterEnum.
              value:        The value of the Mechanism solver parameter.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API SolverParameter : public AttribOwner
{
public:
     
    //! Default constructor
    SolverParameter( );
     
    //! Constructs a SolverParameter with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SolverParameter( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SolverParameter();

private:

	//! Assignment operator
	SolverParameter& operator=( const SolverParameter& iSrc );

	//! Copy constructor
	SolverParameter( const SolverParameter& original );
     
public:

	//! Set Title
	plmxml_api::Result SetTitle( const eSolverParameterEnum& arg );

	//! Get Title
	eSolverParameterEnum GetTitle() const;

	//! Set Type
	plmxml_api::Result SetType( const eSolverEnum& arg );

	//! Get Type
	eSolverEnum GetType() const;

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();
 
// <PLMXML_UserCode type="functionHeaderSolverParameter" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSolverParameter;


////////////////////////////////////////////////////////////////////////////////////
//! MechanismParameters class
/*!
\verbatim

              The parameters for a Mechanism solution.

              Attribute:

              type:         The type of the solution, for which the Mechanism is designed as a
                            SolverAnalysisEnum.
              maxIntegratorStep: The maximum step in SI units of time (seconds) that the integrator of the
                            Mechanism solver is allowed to take.
              integratorError: The maximum relative error allowed in the output of the integrator.

              Sub-element:

              SolverParameter: A parameter for a particular Mechanism solver.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismParameters : public AttribOwner
{
public:
     
    //! Default constructor
    MechanismParameters( );
     
    //! Constructs a MechanismParameters with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismParameters( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismParameters();

private:

	//! Assignment operator
	MechanismParameters& operator=( const MechanismParameters& iSrc );

	//! Copy constructor
	MechanismParameters( const MechanismParameters& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eSolverAnalysisEnum& arg );

	//! Get Type
	eSolverAnalysisEnum GetType() const;

	//! Set MaxIntegratorStep
	plmxml_api::Result SetMaxIntegratorStep( double arg );

     //! Get MaxIntegratorStep
	double GetMaxIntegratorStep() const;

	//! Check if MaxIntegratorStep is set
	plmxml_api::logical HasMaxIntegratorStep() const;

	//! Unset MaxIntegratorStep
	plmxml_api::Result UnsetMaxIntegratorStep();

	//! Set IntegratorError
	plmxml_api::Result SetIntegratorError( double arg );

     //! Get IntegratorError
	double GetIntegratorError() const;

	//! Check if IntegratorError is set
	plmxml_api::logical HasIntegratorError() const;

	//! Unset IntegratorError
	plmxml_api::Result UnsetIntegratorError();

	//! Add SolverParameter child element to this MechanismParameters. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	SolverParameter *AddSolverParameter();
     
	//! Add 'arg' as SolverParameter child element to this MechanismParameters.
	plmxml_api::Result AddSolverParameter( SolverParameter *arg );

	//! Detach and delete all SolverParameter child elements.
	void DeleteSolverParameters();
     
	//! Get number of SolverParameter child elements.
	int NumberOfSolverParameters() const;
     
	//! Get i'th SolverParameter child element.
	SolverParameter *GetSolverParameter( int i ) const;
     
	//! Get all SolverParameter child element as an array
	void GetSolverParameters( plmxml_api::Array<SolverParameter*> &array ) const;
	     
	//! Detach and delete i'th SolverParameter child element
	void DeleteSolverParameter( int i );
     
	//! Detach and delete 'arg' if it's one of the SolverParameter child elements
	void DeleteSolverParameter( SolverParameter *arg );
 
// <PLMXML_UserCode type="functionHeaderMechanismParameters" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismParameters;


////////////////////////////////////////////////////////////////////////////////////
//! MechanismInertia class
/*!
\verbatim

              The inertia of a Mechanism object about Marker.

              Attribute:

              markerRef:    References a Marker, which defines the position, about which the inertia of the
                            Mechanism object is defined. If the Marker also holds orientation information,
                            the inertia is defined in the coordinate system of the Marker. Otherwise, it is
                            defined in the coordinate system of the Mechanism object. (A Marker may not
                            hold orientation information if it has a translational rather than general
                            Transform sub-element or references a Smart Point rather than a Smart Vector.)
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismInertia : public Inertia
{
public:
     
    //! Default constructor
    MechanismInertia( );
     
    //! Constructs a MechanismInertia with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismInertia( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismInertia();

private:

	//! Assignment operator
	MechanismInertia& operator=( const MechanismInertia& iSrc );

	//! Copy constructor
	MechanismInertia( const MechanismInertia& original );
     
public:

	//! Get Marker URI as plmxml_api::String
	plmxml_api::String GetMarkerURI() const;

	//! Set Marker URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMarkerURI( const plmxml_api::String& );
	
	//! Get the handle of Marker URI. Does not resolve the URI.
	plmxml_api::Result GetMarkerURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Marker URI. URI string is unchanged.
	plmxml_api::Result SetMarkerURI( const plmxml_api::Handle& );
	
	//! Resolve Marker URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMarkerURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Marker URI. Clears URI string and handle.
	plmxml_api::Result DeleteMarkerURI();
	
	//! Check if Marker URI is set
	plmxml_api::logical HasMarkerURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderMechanismInertia" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismInertia;


////////////////////////////////////////////////////////////////////////////////////
//! InitialVelocity class
/*!
\verbatim

            The initial translational and rotational velocities of a Mechanism object.

            Attributes:

            translationVelocity: The initial translational velocity of the Mechanism object in SI units,
                            currently metres per second. The default is 0.0, 0.0, 0.0.
            translationOrientationRef: References a Marker, which defines the coordinate system, in which
                            the translational velocity is defined. If the Marker does not hold orientation
                            information, the translational velocity is defined in the coordinate system of
                            the Mechanism object.
            rotationVelocity: The initial rotational velocity of the Mechanism object in SI units,
                            currently radians per second. The default is 0.0, 0.0, 0.0.
            rotationCentreRef: References a Marker, which defines the position of the centre of rotation of
                            the Mechanism object. If the Marker also holds orientation information, the
                            rotational velocity is defined in the coordinate system of the Marker.
                            Otherwise, it is defined in the coordinate system of the Mechanism object. (A
                            Marker may not hold orientation information if it has a translational rather
                            than general Transform sub-element or references a Smart Point rather than a
                            Smart Vector.)
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API InitialVelocity : public Property
{
public:
     
    //! Default constructor
    InitialVelocity( );
     
    //! Constructs a InitialVelocity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    InitialVelocity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~InitialVelocity();

private:

	//! Assignment operator
	InitialVelocity& operator=( const InitialVelocity& iSrc );

	//! Copy constructor
	InitialVelocity( const InitialVelocity& original );
     
public:

	//! Set TranslationVelocity using plmxml_api::Vector components
	plmxml_api::Result SetTranslationVelocity( const plmxml_api::Vector& arg );

	//! Get TranslationVelocity as plmxml_api::Vector
	plmxml_api::Result GetTranslationVelocity( plmxml_api::Vector& arg ) const;

	//! Check if TranslationVelocity is set
	plmxml_api::logical HasTranslationVelocity() const;

	//! Unset TranslationVelocity
	plmxml_api::Result UnsetTranslationVelocity();

	//! Set RotationVelocity using plmxml_api::Vector components
	plmxml_api::Result SetRotationVelocity( const plmxml_api::Vector& arg );

	//! Get RotationVelocity as plmxml_api::Vector
	plmxml_api::Result GetRotationVelocity( plmxml_api::Vector& arg ) const;

	//! Check if RotationVelocity is set
	plmxml_api::logical HasRotationVelocity() const;

	//! Unset RotationVelocity
	plmxml_api::Result UnsetRotationVelocity();

	//! Get TranslationOrientation URI as plmxml_api::String
	plmxml_api::String GetTranslationOrientationURI() const;

	//! Set TranslationOrientation URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTranslationOrientationURI( const plmxml_api::String& );
	
	//! Get the handle of TranslationOrientation URI. Does not resolve the URI.
	plmxml_api::Result GetTranslationOrientationURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TranslationOrientation URI. URI string is unchanged.
	plmxml_api::Result SetTranslationOrientationURI( const plmxml_api::Handle& );
	
	//! Resolve TranslationOrientation URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTranslationOrientationURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TranslationOrientation URI. Clears URI string and handle.
	plmxml_api::Result DeleteTranslationOrientationURI();
	
	//! Check if TranslationOrientation URI is set
	plmxml_api::logical HasTranslationOrientationURI( ) const;
	

	//! Get RotationCentre URI as plmxml_api::String
	plmxml_api::String GetRotationCentreURI() const;

	//! Set RotationCentre URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetRotationCentreURI( const plmxml_api::String& );
	
	//! Get the handle of RotationCentre URI. Does not resolve the URI.
	plmxml_api::Result GetRotationCentreURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of RotationCentre URI. URI string is unchanged.
	plmxml_api::Result SetRotationCentreURI( const plmxml_api::Handle& );
	
	//! Resolve RotationCentre URI and return an object (handle) it points to.
	plmxml_api::Result ResolveRotationCentreURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset RotationCentre URI. Clears URI string and handle.
	plmxml_api::Result DeleteRotationCentreURI();
	
	//! Check if RotationCentre URI is set
	plmxml_api::logical HasRotationCentreURI( ) const;
	
 
// <PLMXML_UserCode type="functionHeaderInitialVelocity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassInitialVelocity;


////////////////////////////////////////////////////////////////////////////////////
//! Gravity class
/*!
\verbatim

              The acceleration due to a gravitational field.

              Attribute:

              value:        The vector value of the acceleration due to the gravitational field in SI
                            units, currently metres per second per second. The default is 0.0, 0.0, 0.0.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Gravity : public Property
{
public:
     
    //! Default constructor
    Gravity( );
     
    //! Constructs a Gravity with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Gravity( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Gravity();

private:

	//! Assignment operator
	Gravity& operator=( const Gravity& iSrc );

	//! Copy constructor
	Gravity( const Gravity& original );
     
public:

	//! Set Value using plmxml_api::Vector components
	plmxml_api::Result SetValue( const plmxml_api::Vector& arg );

	//! Get Value as plmxml_api::Vector
	plmxml_api::Result GetValue( plmxml_api::Vector& arg ) const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();
 
// <PLMXML_UserCode type="functionHeaderGravity" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassGravity;


////////////////////////////////////////////////////////////////////////////////////
//! JointVelocityLimit class
/*!
\verbatim

              The maximum velocity of a Joint.

              Attribute:

              degreeOfFreedom: The degree of freedom along or around which the
                            velocity of the Marker given by the second
                            ConstraintTargetRef of the Joint relative to the
                            Marker given by the second is measured. Represented
                            as a DegreeOfFreedomEnum.

              Sub-element:

              ValueWithUnit: The value of the maximum allowed velocity.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API JointVelocityLimit : public Property
{
public:
     
    //! Default constructor
    JointVelocityLimit( );
     
    //! Constructs a JointVelocityLimit with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    JointVelocityLimit( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~JointVelocityLimit();

private:

	//! Assignment operator
	JointVelocityLimit& operator=( const JointVelocityLimit& iSrc );

	//! Copy constructor
	JointVelocityLimit( const JointVelocityLimit& original );
     
public:

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Add ValueWithUnit child element to this JointVelocityLimit. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this JointVelocityLimit.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this JointVelocityLimit.
	void DeleteValueWithUnit();
 
// <PLMXML_UserCode type="functionHeaderJointVelocityLimit" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassJointVelocityLimit;


////////////////////////////////////////////////////////////////////////////////////
//! JointAccelerationLimit class
/*!
\verbatim

              The maximum acceleration of a Joint.

              Attribute:

              degreeOfFreedom: The degree of freedom along or around which the
                            acceleration of the Marker given by the second
                            ConstraintTargetRef of the Joint relative to the
                            Marker given by the second is measured. Represented
                            as a DegreeOfFreedomEnum.

              Sub-element:

              ValueWithUnit: The value of the maximum allowed acceleration.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API JointAccelerationLimit : public Property
{
public:
     
    //! Default constructor
    JointAccelerationLimit( );
     
    //! Constructs a JointAccelerationLimit with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    JointAccelerationLimit( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~JointAccelerationLimit();

private:

	//! Assignment operator
	JointAccelerationLimit& operator=( const JointAccelerationLimit& iSrc );

	//! Copy constructor
	JointAccelerationLimit( const JointAccelerationLimit& original );
     
public:

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Add ValueWithUnit child element to this JointAccelerationLimit. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Set ValueWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueWithUnit( ValueWithUnit *arg );
     
	//! Get ValueWithUnit child element of this JointAccelerationLimit.
	ValueWithUnit *GetValueWithUnit() const;
     
	//! Detach and delete ValueWithUnit child element tree from this JointAccelerationLimit.
	void DeleteValueWithUnit();
 
// <PLMXML_UserCode type="functionHeaderJointAccelerationLimit" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassJointAccelerationLimit;


//! Forward class declarations
class Marker;

////////////////////////////////////////////////////////////////////////////////////
//! MechanismRevisionView class
/*!
\verbatim

            A view of a revision of a Mechanism, analogous to a ProductRevisionView in the Product
            Structure. MechanismRevisionView elements are used together with MechanismInstance elements in
            an instance graph. At the leaf nodes, they represent conceptual rigid bodies, which may be
            implemented by ProductRevisionView elements. At other levels, they represent sub-assemblies of
            conceptual rigid bodies, known as sub-mechanisms, and at the top level, they represent the
            mechanism definition.

            Attributes:

            id:             Inherited from StructureRevisionView.
            name:           Inherited from StructureRevisionView.
            instanceRefs:   Inherited from StructureRevisionView. References MechanismInstance elements,
                            which represent Mechanism objects.
            gdeInstanceRefs: Inherited from StructureRevisionView. References JointInstance elements.
            propertyRefs:   Inherited from StructureRevisionView. A list of references to elements
                            representing properties such as mass or initial velocity. See also the
                            PropertyGroup sub-element. See the "Defining Mass and Material Properties"
                            Chapter of the PLM XML Schema Functional Description.

            Sub-elements:

            Bound:          Inherited from StructureRevisionView. Represents the bounding box in which the
                            Mechanism object lies. See Section 5.4.2 of the PLM XML Schema Functional
                            Description.
            PropertyGroup:  Inherited from StructureRevisionView. May have sub-elements representing
                            properties such as mass or initial velocity. See also the propertyRefs
                            attribute. See the "Defining Mass and  Material Properties" Chapter of the PLM
                            XML Schema Functional Description.
            MechanismParameters: The parameters for a Mechanism solution.
            Marker:         The Markers on the Mechanism object.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismRevisionView : public StructureRevisionView
{
public:
     
    //! Default constructor
    MechanismRevisionView( );
     
    //! Constructs a MechanismRevisionView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismRevisionView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismRevisionView();

private:

	//! Assignment operator
	MechanismRevisionView& operator=( const MechanismRevisionView& iSrc );

	//! Copy constructor
	MechanismRevisionView( const MechanismRevisionView& original );
     
public:

	//! Add MechanismParameters child element to this MechanismRevisionView. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismParameters *AddMechanismParameters();
     
	//! Set MechanismParameters child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetMechanismParameters( MechanismParameters *arg );
     
	//! Get MechanismParameters child element of this MechanismRevisionView.
	MechanismParameters *GetMechanismParameters() const;
     
	//! Detach and delete MechanismParameters child element tree from this MechanismRevisionView.
	void DeleteMechanismParameters();

	//! Add Marker child element to this MechanismRevisionView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Marker *AddMarker();
     
	//! Add 'arg' as Marker child element to this MechanismRevisionView.
	plmxml_api::Result AddMarker( Marker *arg );

	//! Detach and delete all Marker child elements.
	void DeleteMarkers();
     
	//! Get number of Marker child elements.
	int NumberOfMarkers() const;
     
	//! Get i'th Marker child element.
	Marker *GetMarker( int i ) const;
     
	//! Get all Marker child element as an array
	void GetMarkers( plmxml_api::Array<Marker*> &array ) const;
	     
	//! Detach and delete i'th Marker child element
	void DeleteMarker( int i );
     
	//! Detach and delete 'arg' if it's one of the Marker child elements
	void DeleteMarker( Marker *arg );
 
// <PLMXML_UserCode type="functionHeaderMechanismRevisionView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismRevisionView;


//! Forward class declarations
class Marker;

////////////////////////////////////////////////////////////////////////////////////
//! MechanismInstance class
/*!
\verbatim

            An Instance of a MechanismRevisionView. A MechanismInstance represents an instance of a
            Mechanism object.

            A MechanismInstance may reference geometry in the Product Structure via Reference elements. A
            Reference may reference an Occurrence in the Product Structure via its occurrenceRef attribute.
            A MechanismInstance may correspond to different Occurrence elements for different purposes by
            using more than one Reference. In this case, each Reference has a different value for its type
            attribute.

            Attributes: 

            id:             Inherited from Instance.
            name:           Inherited from Instance.
            partRef:        Inherited from Instance. References a MechanismRevisionView, which represents a
                            Mechanism object.
            propertyRefs:   Inherited from Instance. A list of references to elements representing
                            properties such as mass or initial velocity. See also the PropertyGroup
                            sub-element. See the "Defining Mass and Material Properties" Chapter of the PLM
                            XML Schema Functional Description.

            Sub-elements:

            Bound:          Inherited from Instance. Represents the bounding box in which the Mechanism
                            object lies. See Section 5.4.2 of the PLM XML Schema Functional Description.
            PropertyGroup:  Inherited from Instance. May have sub-elements representing properties such as
                            mass or initial velocity. See also the propertyRefs attribute. See the
                            "Defining Mass and Material Properties" Chapter of the PLM XML Schema
                            Functional Description.
            Marker:         The Markers on the Mechanism object.
            Reference:      Inherited from Instance. The occurrenceRef attribute of a Reference element
                            references an Occurrence in the Product Structure. See the "Representing
                            Feature Semantics" Chapter of the PLM XML Schema Functional Description.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismInstance : public Instance
{
public:
     
    //! Default constructor
    MechanismInstance( );
     
    //! Constructs a MechanismInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismInstance();

private:

	//! Assignment operator
	MechanismInstance& operator=( const MechanismInstance& iSrc );

	//! Copy constructor
	MechanismInstance( const MechanismInstance& original );
     
public:

	//! Add Marker child element to this MechanismInstance. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Marker *AddMarker();
     
	//! Add 'arg' as Marker child element to this MechanismInstance.
	plmxml_api::Result AddMarker( Marker *arg );

	//! Detach and delete all Marker child elements.
	void DeleteMarkers();
     
	//! Get number of Marker child elements.
	int NumberOfMarkers() const;
     
	//! Get i'th Marker child element.
	Marker *GetMarker( int i ) const;
     
	//! Get all Marker child element as an array
	void GetMarkers( plmxml_api::Array<Marker*> &array ) const;
	     
	//! Detach and delete i'th Marker child element
	void DeleteMarker( int i );
     
	//! Detach and delete 'arg' if it's one of the Marker child elements
	void DeleteMarker( Marker *arg );
 
// <PLMXML_UserCode type="functionHeaderMechanismInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismInstance;


//! Forward class declarations
class Marker;

////////////////////////////////////////////////////////////////////////////////////
//! MechanismOccurrence class
/*!
\verbatim

            An Occurrence of a MechanismRevisionView. A MechanismOccurrence represents an occurrence of a
            Mechanism object.

            A MechanismOccurrence may reference geometry in the Product Structure via Reference elements. A
            Reference may reference an Occurrence in the Product Structure via its occurrenceRef attribute.
            A MechanismOccurrence may correspond to different Occurrence elements for different purposes by
            using more than one Reference. In this case, each Reference has a different value for its type
            attribute.

            Attributes:

            id:             Inherited from Occurrence.
            name:           Inherited from Occurrence.
            instanceRefs:   Inherited from Occurrence. References a list of MechanismInstances, which
                            define a particular Mechanism object.
            propertyRefs:   Inherited from Occurrence. A list of references to elements representing
                            properties such as mass or initial velocity. See also the PropertyGroup
                            sub-element. See the "Defining Mass and Material Properties" Chapter of the PLM
                            XML Schema Functional Description.

            Sub-elements:

            Bound:          Inherited from Occurrence. Represents the bounding in which the Mechanism
                            object lies. See Section 5.4.2 of the PLM XML Schema Functional Description.
            PropertyGroup:  Inherited from Occurrence. May have sub-elements representing properties such
                            as mass or initial velocity. See also the propertyRefs attribute. See the
                            "Defining Mass and Material Properties" Chapter of the PLM XML Schema
                            Functional Description.
            Marker:         The Markers on the Mechanism object.
            Reference:      Inherited from Occurrence. The occurrenceRef attribute of a Reference element
                            references an Occurrence in the Product Structure. See the "Representing
                            Feature Semantics" Chapter of the PLM XML Schema Functional Description.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismOccurrence : public Occurrence
{
public:
     
    //! Default constructor
    MechanismOccurrence( );
     
    //! Constructs a MechanismOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismOccurrence();

private:

	//! Assignment operator
	MechanismOccurrence& operator=( const MechanismOccurrence& iSrc );

	//! Copy constructor
	MechanismOccurrence( const MechanismOccurrence& original );
     
public:

	//! Add Marker child element to this MechanismOccurrence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Marker *AddMarker();
     
	//! Add 'arg' as Marker child element to this MechanismOccurrence.
	plmxml_api::Result AddMarker( Marker *arg );

	//! Detach and delete all Marker child elements.
	void DeleteMarkers();
     
	//! Get number of Marker child elements.
	int NumberOfMarkers() const;
     
	//! Get i'th Marker child element.
	Marker *GetMarker( int i ) const;
     
	//! Get all Marker child element as an array
	void GetMarkers( plmxml_api::Array<Marker*> &array ) const;
	     
	//! Detach and delete i'th Marker child element
	void DeleteMarker( int i );
     
	//! Detach and delete 'arg' if it's one of the Marker child elements
	void DeleteMarker( Marker *arg );
 
// <PLMXML_UserCode type="functionHeaderMechanismOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! MechanismView class
/*!
\verbatim

            A View of a Mechanism Structure.

            Attributes:

            id:             Inherited from ConfigurationView.
            name:           Inherited from ConfigurationView.
            rootRefs:       References the MechanismOccurrences and
                            ConstraintOccurrences that are not children of other
                            MechanismOccurrences or ConstraintOccurrences in
                            the MechanismView.
            definition:     Specifies how the MechanismView is defined as a
                            ProductViewDefinitionType.
            usage:          The usage for the MechanismView as a 
                            ProductViewUsageType.

            Sub-elements:

            MechanismOccurrence: The MechanismOccurrences of the MechanismView.
            ConstraintOccurrence: The ConstraintOccurrences of the
                            MechanismView.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismView : public ConfigurationView
{
public:
     
    //! Default constructor
    MechanismView( );
     
    //! Constructs a MechanismView with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismView( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismView();

private:

	//! Assignment operator
	MechanismView& operator=( const MechanismView& iSrc );

	//! Copy constructor
	MechanismView( const MechanismView& original );
     
public:

	//! Set Definition
	plmxml_api::Result SetDefinition( const plmxml60::eProductViewDefinitionType& arg );

	//! Get Definition
	plmxml60::eProductViewDefinitionType GetDefinition() const;

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

	//! Set Usage
	plmxml_api::Result SetUsage( const plmxml60::eProductViewUsageType& arg );

	//! Get Usage
	plmxml60::eProductViewUsageType GetUsage() const;

	//! Add MechanismOccurrence child element to this MechanismView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismOccurrence *AddMechanismOccurrence();
     
	//! Add 'arg' as MechanismOccurrence child element to this MechanismView.
	plmxml_api::Result AddMechanismOccurrence( MechanismOccurrence *arg );

	//! Detach and delete all MechanismOccurrence child elements.
	void DeleteMechanismOccurrences();
     
	//! Get number of MechanismOccurrence child elements.
	int NumberOfMechanismOccurrences() const;
     
	//! Get i'th MechanismOccurrence child element.
	MechanismOccurrence *GetMechanismOccurrence( int i ) const;
     
	//! Get all MechanismOccurrence child element as an array
	void GetMechanismOccurrences( plmxml_api::Array<MechanismOccurrence*> &array ) const;
	     
	//! Detach and delete i'th MechanismOccurrence child element
	void DeleteMechanismOccurrence( int i );
     
	//! Detach and delete 'arg' if it's one of the MechanismOccurrence child elements
	void DeleteMechanismOccurrence( MechanismOccurrence *arg );

	//! Add ConstraintOccurrence child element to this MechanismView. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintOccurrence *AddConstraintOccurrence();
     
	//! Add 'arg' as ConstraintOccurrence child element to this MechanismView.
	plmxml_api::Result AddConstraintOccurrence( ConstraintOccurrence *arg );

	//! Detach and delete all ConstraintOccurrence child elements.
	void DeleteConstraintOccurrences();
     
	//! Get number of ConstraintOccurrence child elements.
	int NumberOfConstraintOccurrences() const;
     
	//! Get i'th ConstraintOccurrence child element.
	ConstraintOccurrence *GetConstraintOccurrence( int i ) const;
     
	//! Get all ConstraintOccurrence child element as an array
	void GetConstraintOccurrences( plmxml_api::Array<ConstraintOccurrence*> &array ) const;
	     
	//! Detach and delete i'th ConstraintOccurrence child element
	void DeleteConstraintOccurrence( int i );
     
	//! Detach and delete 'arg' if it's one of the ConstraintOccurrence child elements
	void DeleteConstraintOccurrence( ConstraintOccurrence *arg );
 
// <PLMXML_UserCode type="functionHeaderMechanismView" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismView;


////////////////////////////////////////////////////////////////////////////////////
//! Marker class
/*!
\verbatim

          A point with orientation in a Mechanism object. The position and
          orientation given by any Smart Point is used in preference to any
          Transform.

          Attributes:

          pointRef:     References a Smart Point or ExternalReference to a Smart
                        Point. See the "Representing Delta Information" Chapter
                        of the PLM XML Schema Functional Description.
          type:         The type of the Marker as a MarkerEnum.
          propertyRefs: References the Properties of the Marker. This method of
                        assigning Properties is preferred over the PropertyGroup
                        sub-element. Where there is a conflict of values of a
                        particular Property, the PropertyGroup method takes
                        precedence.

          Sub-elements:

          Transform:    The position and orientation of the Marker with respect
                        to origin of the Mechanism object. See Section 5.3.1 of
                        the PLM XML Schema Functional Description.
          PropertyGroup: Can hold the Properties of the Marker. The propertyRefs
                        attribute is preferred over this method of assigning
                        Properties. Where there is a conflict of values of a
                        particular Property, this method takes precedence.
         DeterminedPropertyGroup: The Marker Properties determined by a specific
                        method.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Marker : public AttribOwner
{
public:
     
    //! Default constructor
    Marker( );
     
    //! Constructs a Marker with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Marker( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Marker();

private:

	//! Assignment operator
	Marker& operator=( const Marker& iSrc );

	//! Copy constructor
	Marker( const Marker& original );
     
public:

	//! Get number of URIs in Property
	int NumberOfPropertyURIs() const;

	//! Get i'th URI in Property
	plmxml_api::String GetPropertyURI( int i ) const;

	//! Add a URI to Property array. Call ResolvePropertyURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPropertyURI( const plmxml_api::String& u );

	//! Set i'th URI in Property array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPropertyURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Property URI. Does not resolve the URI.
	plmxml_api::Result GetPropertyURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Property array.
	plmxml_api::Result AddPropertyURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Property array to point to 'handle'.
	plmxml_api::Result SetPropertyURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Property points to.
	plmxml_api::Result ResolvePropertyURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Property array.
	plmxml_api::Result DeletePropertyURI( int i );

	//! Remove all URIs from Property array.
	plmxml_api::Result DeletePropertyURIs( );
	
	//! Check if Property is set
	plmxml_api::logical HasPropertyURIs( ) const;

	//! Set Type
	plmxml_api::Result SetType( const eMarkerEnum& arg );

	//! Get Type
	eMarkerEnum GetType() const;

	//! Get Point URI as plmxml_api::String
	plmxml_api::String GetPointURI() const;

	//! Set Point URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetPointURI( const plmxml_api::String& );
	
	//! Get the handle of Point URI. Does not resolve the URI.
	plmxml_api::Result GetPointURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Point URI. URI string is unchanged.
	plmxml_api::Result SetPointURI( const plmxml_api::Handle& );
	
	//! Resolve Point URI and return an object (handle) it points to.
	plmxml_api::Result ResolvePointURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Point URI. Clears URI string and handle.
	plmxml_api::Result DeletePointURI();
	
	//! Check if Point URI is set
	plmxml_api::logical HasPointURI( ) const;
	

	//! Add Transform child element to this Marker. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Transform *AddTransform();
     
	//! Set Transform child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTransform( Transform *arg );
     
	//! Get Transform child element of this Marker.
	Transform *GetTransform() const;
     
	//! Detach and delete Transform child element tree from this Marker.
	void DeleteTransform();

	//! Add PropertyGroup child element to this Marker. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	PropertyGroup *AddPropertyGroup();
     
	//! Set PropertyGroup child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetPropertyGroup( PropertyGroup *arg );
     
	//! Get PropertyGroup child element of this Marker.
	PropertyGroup *GetPropertyGroup() const;
     
	//! Detach and delete PropertyGroup child element tree from this Marker.
	void DeletePropertyGroup();

	//! Add DeterminedPropertyGroup child element to this Marker. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	DeterminedPropertyGroup *AddDeterminedPropertyGroup();
     
	//! Set DeterminedPropertyGroup child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDeterminedPropertyGroup( DeterminedPropertyGroup *arg );
     
	//! Get DeterminedPropertyGroup child element of this Marker.
	DeterminedPropertyGroup *GetDeterminedPropertyGroup() const;
     
	//! Detach and delete DeterminedPropertyGroup child element tree from this Marker.
	void DeleteDeterminedPropertyGroup();
 
// <PLMXML_UserCode type="functionHeaderMarker" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMarker;


////////////////////////////////////////////////////////////////////////////////////
//! JointLimits class
/*!
\verbatim

            The linear limits of a translational Joint or the angular limits of a revolute Joint. May
            appear as a sub-element (inside a PropertyGroup) or be referenced by the Joint Constraint.

            Attributes:

            degreeOfFreedom: The degree of freedom of the Joint that the JointLimits limits. Represented as
                            a DegreeOfFreedomEnum.

            Sub-elements:

            RangeWithUnit:  The linear limits of a translational degree of freedom or the angular limits of
                            a rotational degree of freedom. If the units are not specified, SI units are
                            assumed.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API JointLimits : public Property
{
public:
     
    //! Default constructor
    JointLimits( );
     
    //! Constructs a JointLimits with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    JointLimits( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~JointLimits();

private:

	//! Assignment operator
	JointLimits& operator=( const JointLimits& iSrc );

	//! Copy constructor
	JointLimits( const JointLimits& original );
     
public:

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Add RangeWithUnit child element to this JointLimits. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Set RangeWithUnit child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetRangeWithUnit( RangeWithUnit *arg );
     
	//! Get RangeWithUnit child element of this JointLimits.
	RangeWithUnit *GetRangeWithUnit() const;
     
	//! Detach and delete RangeWithUnit child element tree from this JointLimits.
	void DeleteRangeWithUnit();
 
// <PLMXML_UserCode type="functionHeaderJointLimits" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassJointLimits;


////////////////////////////////////////////////////////////////////////////////////
//! JointData class
/*!
\verbatim

            Additional data for a Joint Constraint. Only one JointData sub-element is allowed in a
            Constraint, ConstraintInstance or ConstraintOccurrence element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.
            type:           The type of the Joint as a JointEnum.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API JointData : public AttribOwner
{
public:
     
    //! Default constructor
    JointData( );
     
    //! Constructs a JointData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    JointData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~JointData();

private:

	//! Assignment operator
	JointData& operator=( const JointData& iSrc );

	//! Copy constructor
	JointData( const JointData& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eJointEnum& arg );

	//! Get Type
	eJointEnum GetType() const;
 
// <PLMXML_UserCode type="functionHeaderJointData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassJointData;


////////////////////////////////////////////////////////////////////////////////////
//! FrictionData class
/*!
\verbatim

            Additional data for a Friction Constraint. Two FrictionData sub-elements are allowed in a
            Constraint, ConstraintInstance or ConstraintOccurrence element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.
            yokeRef:        References one of the ConstraintTargetRef elements, which references one of the
                            Markers of a universal Joint.
            initialOverlap: The initial overlap of a translational or cylindrical Joint in SI units,
                            currently metres.
            overlapDelta:   Whether the overlap increases, decreases or remains constant as a
                            JointOverlapDeltaEnum.
            innerRadius:    The radius of the pin of a revolute, cylindrical or universal Joint in SI
                            units, currently metres.
            ballRadius:     The radius of the ball of a spherical Joint in SI units, currently metres.
            bendingReactionArm: The effective moment arm of the reaction torque due to bending the pin of a
                            revolute, cylindrical or universal Joint in SI units, currently metres.
            frictionArm:    The effective moment arm of the frictional torque at the end of the pin of a
                            revolute, cylindrical or universal Joint in SI units, currently metres.
            reactionArm:    The effective moment arm of the reaction torque due to twisting a translational
                            Joint around its degree of freedom in SI units, currently metres.
            frictionalPreloadForce: The frictional preload force in SI units, currently newtons.
            frictionalPreloadTorque: The frictional preload torque in SI units, currently newton metres.
            preload:        Whether the preload force and the preload torque contribute to the friction
                            model. The default is true, which means the preload force and preload torque
                            are on by default.
            reactionForce:  Whether the Joint reaction forces contribute to the friction model. The default
                            is true, which means the Joint reaction forces are on by default.
            bendingMoment:  Whether the bending moment due to bending the pin of a revolute, cylindrical
                            or universal Joint contributes to the friction model. The default is true,
                            which means the bending moment is on by default.
            torsionalMoment: Whether the torsional moment due to twisting a translational Joint around
                            its degree of freedom contributes to the friction model. The default is true,
                            which means the torsional moment is on by default.
            staticAnalysis: Whether friction is considered in a static solution. The default is true, which
                            means friction is on by default.
            staticCoefficient: The coefficient of static friction. This is a dimensionless quantity. The
                            default is 0.0.
            dynamicCoefficient: The coefficient of dynamic friction. This is a dimensionless quantity. The
                            default is 0.0.
            staticTransitionSpeed: The surface speed at which the transition from static friction to
                            dynamic friction begins in SI units, currently metres per second. The effective
                            coefficient of friction equals the coefficient of static friction.
            dynamicTransitionSpeed: The surface speed at which the transition from static friction to
                            dynamic friction ends in SI units, currently metres per second. The effective
                            coefficient of friction equals the coefficient of dynamic friction.
            maximumDisplacement: The maximum surface displacement allowed during static friction due to the
                            creep of a Joint in SI units, currently metres.
            staticFriction: Whether the static friction contributes to the friction model. The default
                            is true, which means the static friction is on by default.
            dynamicFriction: Whether the dynamic friction contributes to the friction model. The default
                            is true, which means the dynamic friction is on by default.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API FrictionData : public AttribOwner
{
public:
     
    //! Default constructor
    FrictionData( );
     
    //! Constructs a FrictionData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    FrictionData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~FrictionData();

private:

	//! Assignment operator
	FrictionData& operator=( const FrictionData& iSrc );

	//! Copy constructor
	FrictionData( const FrictionData& original );
     
public:

	//! Set FrictionArm
	plmxml_api::Result SetFrictionArm( double arg );

     //! Get FrictionArm
	double GetFrictionArm() const;

	//! Check if FrictionArm is set
	plmxml_api::logical HasFrictionArm() const;

	//! Unset FrictionArm
	plmxml_api::Result UnsetFrictionArm();

	//! Set ReactionForce
	plmxml_api::Result SetReactionForce( plmxml_api::logical arg );

	//! Get ReactionForce
	plmxml_api::logical GetReactionForce() const;

	//! Check if ReactionForce is set
	plmxml_api::logical HasReactionForce() const;

	//! Unset ReactionForce
	plmxml_api::Result UnsetReactionForce();

	//! Set InnerRadius
	plmxml_api::Result SetInnerRadius( double arg );

     //! Get InnerRadius
	double GetInnerRadius() const;

	//! Check if InnerRadius is set
	plmxml_api::logical HasInnerRadius() const;

	//! Unset InnerRadius
	plmxml_api::Result UnsetInnerRadius();

	//! Set BendingReactionArm
	plmxml_api::Result SetBendingReactionArm( double arg );

     //! Get BendingReactionArm
	double GetBendingReactionArm() const;

	//! Check if BendingReactionArm is set
	plmxml_api::logical HasBendingReactionArm() const;

	//! Unset BendingReactionArm
	plmxml_api::Result UnsetBendingReactionArm();

	//! Set StaticCoefficient
	plmxml_api::Result SetStaticCoefficient( double arg );

     //! Get StaticCoefficient
	double GetStaticCoefficient() const;

	//! Check if StaticCoefficient is set
	plmxml_api::logical HasStaticCoefficient() const;

	//! Unset StaticCoefficient
	plmxml_api::Result UnsetStaticCoefficient();

	//! Get Yoke URI as plmxml_api::String
	plmxml_api::String GetYokeURI() const;

	//! Set Yoke URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetYokeURI( const plmxml_api::String& );
	
	//! Get the handle of Yoke URI. Does not resolve the URI.
	plmxml_api::Result GetYokeURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Yoke URI. URI string is unchanged.
	plmxml_api::Result SetYokeURI( const plmxml_api::Handle& );
	
	//! Resolve Yoke URI and return an object (handle) it points to.
	plmxml_api::Result ResolveYokeURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Yoke URI. Clears URI string and handle.
	plmxml_api::Result DeleteYokeURI();
	
	//! Check if Yoke URI is set
	plmxml_api::logical HasYokeURI( ) const;
	

	//! Set DynamicFriction
	plmxml_api::Result SetDynamicFriction( plmxml_api::logical arg );

	//! Get DynamicFriction
	plmxml_api::logical GetDynamicFriction() const;

	//! Check if DynamicFriction is set
	plmxml_api::logical HasDynamicFriction() const;

	//! Unset DynamicFriction
	plmxml_api::Result UnsetDynamicFriction();

	//! Set MaximumDisplacement
	plmxml_api::Result SetMaximumDisplacement( double arg );

     //! Get MaximumDisplacement
	double GetMaximumDisplacement() const;

	//! Check if MaximumDisplacement is set
	plmxml_api::logical HasMaximumDisplacement() const;

	//! Unset MaximumDisplacement
	plmxml_api::Result UnsetMaximumDisplacement();

	//! Set ReactionArm
	plmxml_api::Result SetReactionArm( double arg );

     //! Get ReactionArm
	double GetReactionArm() const;

	//! Check if ReactionArm is set
	plmxml_api::logical HasReactionArm() const;

	//! Unset ReactionArm
	plmxml_api::Result UnsetReactionArm();

	//! Set FrictionalPreloadTorque
	plmxml_api::Result SetFrictionalPreloadTorque( double arg );

     //! Get FrictionalPreloadTorque
	double GetFrictionalPreloadTorque() const;

	//! Check if FrictionalPreloadTorque is set
	plmxml_api::logical HasFrictionalPreloadTorque() const;

	//! Unset FrictionalPreloadTorque
	plmxml_api::Result UnsetFrictionalPreloadTorque();

	//! Set InitialOverlap
	plmxml_api::Result SetInitialOverlap( double arg );

     //! Get InitialOverlap
	double GetInitialOverlap() const;

	//! Check if InitialOverlap is set
	plmxml_api::logical HasInitialOverlap() const;

	//! Unset InitialOverlap
	plmxml_api::Result UnsetInitialOverlap();

	//! Set TorsionalMoment
	plmxml_api::Result SetTorsionalMoment( plmxml_api::logical arg );

	//! Get TorsionalMoment
	plmxml_api::logical GetTorsionalMoment() const;

	//! Check if TorsionalMoment is set
	plmxml_api::logical HasTorsionalMoment() const;

	//! Unset TorsionalMoment
	plmxml_api::Result UnsetTorsionalMoment();

	//! Set StaticAnalysis
	plmxml_api::Result SetStaticAnalysis( plmxml_api::logical arg );

	//! Get StaticAnalysis
	plmxml_api::logical GetStaticAnalysis() const;

	//! Check if StaticAnalysis is set
	plmxml_api::logical HasStaticAnalysis() const;

	//! Unset StaticAnalysis
	plmxml_api::Result UnsetStaticAnalysis();

	//! Set Preload
	plmxml_api::Result SetPreload( plmxml_api::logical arg );

	//! Get Preload
	plmxml_api::logical GetPreload() const;

	//! Check if Preload is set
	plmxml_api::logical HasPreload() const;

	//! Unset Preload
	plmxml_api::Result UnsetPreload();

	//! Set BendingMoment
	plmxml_api::Result SetBendingMoment( plmxml_api::logical arg );

	//! Get BendingMoment
	plmxml_api::logical GetBendingMoment() const;

	//! Check if BendingMoment is set
	plmxml_api::logical HasBendingMoment() const;

	//! Unset BendingMoment
	plmxml_api::Result UnsetBendingMoment();

	//! Set OverlapDelta
	plmxml_api::Result SetOverlapDelta( const eJointOverlapDeltaEnum& arg );

	//! Get OverlapDelta
	eJointOverlapDeltaEnum GetOverlapDelta() const;

	//! Set BallRadius
	plmxml_api::Result SetBallRadius( double arg );

     //! Get BallRadius
	double GetBallRadius() const;

	//! Check if BallRadius is set
	plmxml_api::logical HasBallRadius() const;

	//! Unset BallRadius
	plmxml_api::Result UnsetBallRadius();

	//! Set StaticFriction
	plmxml_api::Result SetStaticFriction( plmxml_api::logical arg );

	//! Get StaticFriction
	plmxml_api::logical GetStaticFriction() const;

	//! Check if StaticFriction is set
	plmxml_api::logical HasStaticFriction() const;

	//! Unset StaticFriction
	plmxml_api::Result UnsetStaticFriction();

	//! Set FrictionalPreloadForce
	plmxml_api::Result SetFrictionalPreloadForce( double arg );

     //! Get FrictionalPreloadForce
	double GetFrictionalPreloadForce() const;

	//! Check if FrictionalPreloadForce is set
	plmxml_api::logical HasFrictionalPreloadForce() const;

	//! Unset FrictionalPreloadForce
	plmxml_api::Result UnsetFrictionalPreloadForce();

	//! Set DynamicCoefficient
	plmxml_api::Result SetDynamicCoefficient( double arg );

     //! Get DynamicCoefficient
	double GetDynamicCoefficient() const;

	//! Check if DynamicCoefficient is set
	plmxml_api::logical HasDynamicCoefficient() const;

	//! Unset DynamicCoefficient
	plmxml_api::Result UnsetDynamicCoefficient();

	//! Set DynamicTransitionSpeed
	plmxml_api::Result SetDynamicTransitionSpeed( double arg );

     //! Get DynamicTransitionSpeed
	double GetDynamicTransitionSpeed() const;

	//! Check if DynamicTransitionSpeed is set
	plmxml_api::logical HasDynamicTransitionSpeed() const;

	//! Unset DynamicTransitionSpeed
	plmxml_api::Result UnsetDynamicTransitionSpeed();

	//! Set StaticTransitionSpeed
	plmxml_api::Result SetStaticTransitionSpeed( double arg );

     //! Get StaticTransitionSpeed
	double GetStaticTransitionSpeed() const;

	//! Check if StaticTransitionSpeed is set
	plmxml_api::logical HasStaticTransitionSpeed() const;

	//! Unset StaticTransitionSpeed
	plmxml_api::Result UnsetStaticTransitionSpeed();
 
// <PLMXML_UserCode type="functionHeaderFrictionData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassFrictionData;


////////////////////////////////////////////////////////////////////////////////////
//! MechanismExpression class
/*!
\verbatim

            A Mechanism expression.

            Attributes:

            expression:     The expression in the syntax of the Mechanism solver as a string.
            format:         The format of the expression as a SolverEnum.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API MechanismExpression : public AttribOwner
{
public:
     
    //! Default constructor
    MechanismExpression( );
     
    //! Constructs a MechanismExpression with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MechanismExpression( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MechanismExpression();

private:

	//! Assignment operator
	MechanismExpression& operator=( const MechanismExpression& iSrc );

	//! Copy constructor
	MechanismExpression( const MechanismExpression& original );
     
public:

	//! Set Format
	plmxml_api::Result SetFormat( const eSolverEnum& arg );

	//! Get Format
	eSolverEnum GetFormat() const;

	//! Get Expression of this MechanismExpression
	plmxml_api::String GetExpression() const;

	//! Set Expression of this MechanismExpression
	plmxml_api::Result SetExpression( const plmxml_api::String &s );
	
	//! Check if Expression is set
	plmxml_api::logical HasExpression( ) const;
	
	//! Unset Expression
	plmxml_api::Result UnsetExpression( );
 
// <PLMXML_UserCode type="functionHeaderMechanismExpression" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMechanismExpression;


////////////////////////////////////////////////////////////////////////////////////
//! DriverComponent class
/*!
\verbatim

          The components of a DriverData. Several degrees of freedom may be
          driven by having several DriverComponent sub-elements in a DriverData
          element.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          type:         The type of the Driver as a DriverEnum.
          degreeOfFreedom: The degree of freedom of the Joint that the Driver
                        drives. Represented as a DegreeOfFreedomEnum.
          displacement: If type is "constant", displacement is the constant
                        displacement if velocity, acceleration & jerk are
                        unspecified and the initial displacement if velocity,
                        acceleration or jerk are specified. If type is
                        "harmonic", displacement is the constant offset of the
                        harmonic component from the origin. The units are SI
                        units, currently metres for translational Drivers or
                        radians for rotational Drivers. The default is 0.0.
          velocity:     The constant velocity of a constant Driver if
                        acceleration & jerk are unspecified. The initial
                        velocity if acceleration or jerk are specified. The
                        units are SI units, currently metres per second for
                        translational Drivers or radians per second for
                        rotational Drivers. The default is 0.0.
          acceleration: The constant acceleration of a constant Driver if jerk
                        is unspecified. The initial acceleration if it is
                        specified. The units are SI units, currently metres per
                        second per second for translational Drivers or radians
                        per second per second for rotational Drivers. The
                        default is 0.0.
          amplitude:    The amplitude of a harmonic Driver in SI units,
                        currently metres for translational Drivers or radians
                        for rotational Drivers. The default is 0.0.
          frequency:    The frequency of a harmonic Driver in SI units,
                        currently radians per second. The default is 0.0.
          phaseAngle:   The phase angle of a harmonic Driver in SI units,
                        currently radians. The default is 0.0.
          motorRef:     A reference to a Motor.
          timingFunctionRef: A reference to a TimingFunction.
          jerk:         The constant jerk of a constant Driver in SI units,
                        currently metres per second cubed for translational
                        Drivers or radians per second cubed for rotational
                        Drivers. The default is 0.0.

          Sub-elements:

          DisplacementExpression: A MechanismExpression that defines the
                        displacement of a general Driver. VelocityExpression and
                        AccelerationExpression must not be present.
          VelocityExpression: A MechanismExpression that defines the velocity of
                        a general Driver. The initial displacement is defined by
                        the displacement attribute. DisplacementExpression and
                        AccelerationExpression must not be present.
          AccelerationExpression: A MechanismExpression that defines the
                        acceleration of a general Driver. The initial velocity
                        is defined by the velocity attribute and the initial
                        displacement is defined by the displacement attribute.
                        DisplacementExpression and VelocityExpression must not
                        be present.
          JerkExpression: A MechanismExpression that defines the jerk of a
                        general Driver. The initial acceleration is defined by
                        the acceleration attribute, the initial velocity by the
                        velocity attribute and the initial displacement by the
                        displacement attribute. DisplacementExpression,
                        VelocityExpression and AccelerationExpression must not
                        be present.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API DriverComponent : public AttribOwner
{
public:
     
    //! Default constructor
    DriverComponent( );
     
    //! Constructs a DriverComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DriverComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DriverComponent();

private:

	//! Assignment operator
	DriverComponent& operator=( const DriverComponent& iSrc );

	//! Copy constructor
	DriverComponent( const DriverComponent& original );
     
public:

	//! Set Amplitude
	plmxml_api::Result SetAmplitude( double arg );

     //! Get Amplitude
	double GetAmplitude() const;

	//! Check if Amplitude is set
	plmxml_api::logical HasAmplitude() const;

	//! Unset Amplitude
	plmxml_api::Result UnsetAmplitude();

	//! Set PhaseAngle
	plmxml_api::Result SetPhaseAngle( double arg );

     //! Get PhaseAngle
	double GetPhaseAngle() const;

	//! Check if PhaseAngle is set
	plmxml_api::logical HasPhaseAngle() const;

	//! Unset PhaseAngle
	plmxml_api::Result UnsetPhaseAngle();

	//! Set Jerk
	plmxml_api::Result SetJerk( double arg );

     //! Get Jerk
	double GetJerk() const;

	//! Check if Jerk is set
	plmxml_api::logical HasJerk() const;

	//! Unset Jerk
	plmxml_api::Result UnsetJerk();

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Get Motor URI as plmxml_api::String
	plmxml_api::String GetMotorURI() const;

	//! Set Motor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMotorURI( const plmxml_api::String& );
	
	//! Get the handle of Motor URI. Does not resolve the URI.
	plmxml_api::Result GetMotorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Motor URI. URI string is unchanged.
	plmxml_api::Result SetMotorURI( const plmxml_api::Handle& );
	
	//! Resolve Motor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMotorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Motor URI. Clears URI string and handle.
	plmxml_api::Result DeleteMotorURI();
	
	//! Check if Motor URI is set
	plmxml_api::logical HasMotorURI( ) const;
	

	//! Set Displacement
	plmxml_api::Result SetDisplacement( double arg );

     //! Get Displacement
	double GetDisplacement() const;

	//! Check if Displacement is set
	plmxml_api::logical HasDisplacement() const;

	//! Unset Displacement
	plmxml_api::Result UnsetDisplacement();

	//! Get TimingFunction URI as plmxml_api::String
	plmxml_api::String GetTimingFunctionURI() const;

	//! Set TimingFunction URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTimingFunctionURI( const plmxml_api::String& );
	
	//! Get the handle of TimingFunction URI. Does not resolve the URI.
	plmxml_api::Result GetTimingFunctionURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TimingFunction URI. URI string is unchanged.
	plmxml_api::Result SetTimingFunctionURI( const plmxml_api::Handle& );
	
	//! Resolve TimingFunction URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTimingFunctionURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TimingFunction URI. Clears URI string and handle.
	plmxml_api::Result DeleteTimingFunctionURI();
	
	//! Check if TimingFunction URI is set
	plmxml_api::logical HasTimingFunctionURI( ) const;
	

	//! Set Type
	plmxml_api::Result SetType( const eDriverEnum& arg );

	//! Get Type
	eDriverEnum GetType() const;

	//! Set Acceleration
	plmxml_api::Result SetAcceleration( double arg );

     //! Get Acceleration
	double GetAcceleration() const;

	//! Check if Acceleration is set
	plmxml_api::logical HasAcceleration() const;

	//! Unset Acceleration
	plmxml_api::Result UnsetAcceleration();

	//! Set Velocity
	plmxml_api::Result SetVelocity( double arg );

     //! Get Velocity
	double GetVelocity() const;

	//! Check if Velocity is set
	plmxml_api::logical HasVelocity() const;

	//! Unset Velocity
	plmxml_api::Result UnsetVelocity();

	//! Set Frequency
	plmxml_api::Result SetFrequency( double arg );

     //! Get Frequency
	double GetFrequency() const;

	//! Check if Frequency is set
	plmxml_api::logical HasFrequency() const;

	//! Unset Frequency
	plmxml_api::Result UnsetFrequency();

	//! Add DisplacementExpression child element to this DriverComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddDisplacementExpression();
     
	//! Set DisplacementExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDisplacementExpression( MechanismExpression *arg );
     
	//! Get DisplacementExpression child element of this DriverComponent.
	MechanismExpression *GetDisplacementExpression() const;
     
	//! Detach and delete DisplacementExpression child element tree from this DriverComponent.
	void DeleteDisplacementExpression();

	//! Add VelocityExpression child element to this DriverComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddVelocityExpression();
     
	//! Set VelocityExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetVelocityExpression( MechanismExpression *arg );
     
	//! Get VelocityExpression child element of this DriverComponent.
	MechanismExpression *GetVelocityExpression() const;
     
	//! Detach and delete VelocityExpression child element tree from this DriverComponent.
	void DeleteVelocityExpression();

	//! Add AccelerationExpression child element to this DriverComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddAccelerationExpression();
     
	//! Set AccelerationExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetAccelerationExpression( MechanismExpression *arg );
     
	//! Get AccelerationExpression child element of this DriverComponent.
	MechanismExpression *GetAccelerationExpression() const;
     
	//! Detach and delete AccelerationExpression child element tree from this DriverComponent.
	void DeleteAccelerationExpression();

	//! Add JerkExpression child element to this DriverComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddJerkExpression();
     
	//! Set JerkExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetJerkExpression( MechanismExpression *arg );
     
	//! Get JerkExpression child element of this DriverComponent.
	MechanismExpression *GetJerkExpression() const;
     
	//! Detach and delete JerkExpression child element tree from this DriverComponent.
	void DeleteJerkExpression();
 
// <PLMXML_UserCode type="functionHeaderDriverComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassDriverComponent;


////////////////////////////////////////////////////////////////////////////////////
//! DriverData class
/*!
\verbatim

            Additional data for a Driver Constraint. Only one DriverData sub-element is allowed in a
            Constraint, ConstraintInstance or ConstraintOccurrence element. Several degrees of freedom may
            be driven by having several DriverComponent sub-elements in a DriverData element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.

            Sub-element:

            DriverComponent: The components of the Driver represented as DriverComponentType.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API DriverData : public AttribOwner
{
public:
     
    //! Default constructor
    DriverData( );
     
    //! Constructs a DriverData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DriverData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DriverData();

private:

	//! Assignment operator
	DriverData& operator=( const DriverData& iSrc );

	//! Copy constructor
	DriverData( const DriverData& original );
     
public:

	//! Add DriverComponent child element to this DriverData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	DriverComponent *AddDriverComponent();
     
	//! Add 'arg' as DriverComponent child element to this DriverData.
	plmxml_api::Result AddDriverComponent( DriverComponent *arg );

	//! Detach and delete all DriverComponent child elements.
	void DeleteDriverComponents();
     
	//! Get number of DriverComponent child elements.
	int NumberOfDriverComponents() const;
     
	//! Get i'th DriverComponent child element.
	DriverComponent *GetDriverComponent( int i ) const;
     
	//! Get all DriverComponent child element as an array
	void GetDriverComponents( plmxml_api::Array<DriverComponent*> &array ) const;
	     
	//! Detach and delete i'th DriverComponent child element
	void DeleteDriverComponent( int i );
     
	//! Detach and delete 'arg' if it's one of the DriverComponent child elements
	void DeleteDriverComponent( DriverComponent *arg );
 
// <PLMXML_UserCode type="functionHeaderDriverData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassDriverData;


////////////////////////////////////////////////////////////////////////////////////
//! ForceComponent class
/*!
\verbatim

          The components of a ForceData. Vector Forces and Torques are
          represented by having several ForceComponent sub-elements in a
          ForceData element.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          constant:     Whether the Force or Torque is a constant or general
                        Force or Torque.
          degreeOfFreedom: The degree of freedom of the Joint along or around
                        which the force or torque acts. Represented as a
                        DegreeOfFreedomEnum.
          force:        The force or torque of a constant Force or Torque in SI
                        units, currently newtons for Forces and newton metres
                        for Torques. The default is 0.0.
          motorRef:     A reference to a Motor.
          timingFunctionRef: A reference to a TimingFunction.

          Sub-element:

          ForceExpression: A MechanismExpression that defines the force or
                        torque of a general Force or Torque.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ForceComponent : public AttribOwner
{
public:
     
    //! Default constructor
    ForceComponent( );
     
    //! Constructs a ForceComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ForceComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ForceComponent();

private:

	//! Assignment operator
	ForceComponent& operator=( const ForceComponent& iSrc );

	//! Copy constructor
	ForceComponent( const ForceComponent& original );
     
public:

	//! Get Motor URI as plmxml_api::String
	plmxml_api::String GetMotorURI() const;

	//! Set Motor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetMotorURI( const plmxml_api::String& );
	
	//! Get the handle of Motor URI. Does not resolve the URI.
	plmxml_api::Result GetMotorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Motor URI. URI string is unchanged.
	plmxml_api::Result SetMotorURI( const plmxml_api::Handle& );
	
	//! Resolve Motor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveMotorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Motor URI. Clears URI string and handle.
	plmxml_api::Result DeleteMotorURI();
	
	//! Check if Motor URI is set
	plmxml_api::logical HasMotorURI( ) const;
	

	//! Get TimingFunction URI as plmxml_api::String
	plmxml_api::String GetTimingFunctionURI() const;

	//! Set TimingFunction URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetTimingFunctionURI( const plmxml_api::String& );
	
	//! Get the handle of TimingFunction URI. Does not resolve the URI.
	plmxml_api::Result GetTimingFunctionURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of TimingFunction URI. URI string is unchanged.
	plmxml_api::Result SetTimingFunctionURI( const plmxml_api::Handle& );
	
	//! Resolve TimingFunction URI and return an object (handle) it points to.
	plmxml_api::Result ResolveTimingFunctionURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset TimingFunction URI. Clears URI string and handle.
	plmxml_api::Result DeleteTimingFunctionURI();
	
	//! Check if TimingFunction URI is set
	plmxml_api::logical HasTimingFunctionURI( ) const;
	

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Set Constant
	plmxml_api::Result SetConstant( plmxml_api::logical arg );

	//! Get Constant
	plmxml_api::logical GetConstant() const;

	//! Check if Constant is set
	plmxml_api::logical HasConstant() const;

	//! Unset Constant
	plmxml_api::Result UnsetConstant();

	//! Set Force
	plmxml_api::Result SetForce( double arg );

     //! Get Force
	double GetForce() const;

	//! Check if Force is set
	plmxml_api::logical HasForce() const;

	//! Unset Force
	plmxml_api::Result UnsetForce();

	//! Add ForceExpression child element to this ForceComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddForceExpression();
     
	//! Set ForceExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetForceExpression( MechanismExpression *arg );
     
	//! Get ForceExpression child element of this ForceComponent.
	MechanismExpression *GetForceExpression() const;
     
	//! Detach and delete ForceExpression child element tree from this ForceComponent.
	void DeleteForceExpression();
 
// <PLMXML_UserCode type="functionHeaderForceComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassForceComponent;


////////////////////////////////////////////////////////////////////////////////////
//! ForceData class
/*!
\verbatim

            Additional data for a Force Constraint. Force Constraints can represent Forces or Torques. Only
            one ForceData sub-element is allowed in a Constraint, ConstraintInstance or
            ConstraintOccurrence element. Vector Forces and Torques are represented by having several
            ForceComponent sub-elements in a ForceData element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.
            scalar:         Whether the Force or Torque is a scalar or vector Force or Torque.
            translation:    Whether the force or torque acts along translational degrees of freedom (in
                            which case it is a Force) or around rotational degrees of freedom (in which
                            case it is a Torque).

            Sub-element:

            ForceComponent: The components of the Force represented as ForceComponentType.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ForceData : public AttribOwner
{
public:
     
    //! Default constructor
    ForceData( );
     
    //! Constructs a ForceData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ForceData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ForceData();

private:

	//! Assignment operator
	ForceData& operator=( const ForceData& iSrc );

	//! Copy constructor
	ForceData( const ForceData& original );
     
public:

	//! Set Scalar
	plmxml_api::Result SetScalar( plmxml_api::logical arg );

	//! Get Scalar
	plmxml_api::logical GetScalar() const;

	//! Check if Scalar is set
	plmxml_api::logical HasScalar() const;

	//! Unset Scalar
	plmxml_api::Result UnsetScalar();

	//! Set Translation
	plmxml_api::Result SetTranslation( plmxml_api::logical arg );

	//! Get Translation
	plmxml_api::logical GetTranslation() const;

	//! Check if Translation is set
	plmxml_api::logical HasTranslation() const;

	//! Unset Translation
	plmxml_api::Result UnsetTranslation();

	//! Add ForceComponent child element to this ForceData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ForceComponent *AddForceComponent();
     
	//! Add 'arg' as ForceComponent child element to this ForceData.
	plmxml_api::Result AddForceComponent( ForceComponent *arg );

	//! Detach and delete all ForceComponent child elements.
	void DeleteForceComponents();
     
	//! Get number of ForceComponent child elements.
	int NumberOfForceComponents() const;
     
	//! Get i'th ForceComponent child element.
	ForceComponent *GetForceComponent( int i ) const;
     
	//! Get all ForceComponent child element as an array
	void GetForceComponents( plmxml_api::Array<ForceComponent*> &array ) const;
	     
	//! Detach and delete i'th ForceComponent child element
	void DeleteForceComponent( int i );
     
	//! Detach and delete 'arg' if it's one of the ForceComponent child elements
	void DeleteForceComponent( ForceComponent *arg );
 
// <PLMXML_UserCode type="functionHeaderForceData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassForceData;


////////////////////////////////////////////////////////////////////////////////////
//! SpringData class
/*!
\verbatim

          Additional data for a Spring Constraint. Only one SpringData
          sub-element is allowed in a Constraint, ConstraintInstance or
          ConstraintOccurrence element.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          degreeOfFreedom: The degree of freedom of the Joint along or around
                        which the Spring acts. Represented as a
                        DegreeOfFreedomEnum.
          preloadForce: The preload force or torque in SI units, currently
                        newtons for forces acting along translational degrees of
                        freedom and newton metres for torques acting around
                        rotational degrees of freedom. The default is 0.0.
          stiffness:    The spring constant of a Spring in SI units, currently
                        newtons per metre for Springs acting along translational
                        degrees of freedom and newton metres per radian for
                        Springs acting around rotational degrees of freedom. The
                        default is 0.0. This is ignored when there is a
                        StiffnessExpression sub-element.
          free:         The free length or angle of a Spring in SI units,
                        currently metres for Springs acting along translational
                        degrees of freedom and radians for Springs acting around
                        rotational degrees of freedom. The default is 0.0.

          Sub-element:

          StiffnessExpression: A MechanismExpression that defines the spring
                        constant of a non-linear Spring in SI units. (newtons
                        per metre along translational degrees of freedom and
                        newton metres per radian around rotational degrees of
                        freedom.)
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API SpringData : public AttribOwner
{
public:
     
    //! Default constructor
    SpringData( );
     
    //! Constructs a SpringData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SpringData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SpringData();

private:

	//! Assignment operator
	SpringData& operator=( const SpringData& iSrc );

	//! Copy constructor
	SpringData( const SpringData& original );
     
public:

	//! Set Free
	plmxml_api::Result SetFree( double arg );

     //! Get Free
	double GetFree() const;

	//! Check if Free is set
	plmxml_api::logical HasFree() const;

	//! Unset Free
	plmxml_api::Result UnsetFree();

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Set PreloadForce
	plmxml_api::Result SetPreloadForce( double arg );

     //! Get PreloadForce
	double GetPreloadForce() const;

	//! Check if PreloadForce is set
	plmxml_api::logical HasPreloadForce() const;

	//! Unset PreloadForce
	plmxml_api::Result UnsetPreloadForce();

	//! Set Stiffness
	plmxml_api::Result SetStiffness( double arg );

     //! Get Stiffness
	double GetStiffness() const;

	//! Check if Stiffness is set
	plmxml_api::logical HasStiffness() const;

	//! Unset Stiffness
	plmxml_api::Result UnsetStiffness();

	//! Add StiffnessExpression child element to this SpringData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddStiffnessExpression();
     
	//! Set StiffnessExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStiffnessExpression( MechanismExpression *arg );
     
	//! Get StiffnessExpression child element of this SpringData.
	MechanismExpression *GetStiffnessExpression() const;
     
	//! Detach and delete StiffnessExpression child element tree from this SpringData.
	void DeleteStiffnessExpression();
 
// <PLMXML_UserCode type="functionHeaderSpringData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSpringData;


////////////////////////////////////////////////////////////////////////////////////
//! DamperData class
/*!
\verbatim

          Additional data for a Damper Constraint. Only one DamperData
          sub-element is allowed in a Constraint, ConstraintInstance or
          ConstraintOccurrence element.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          degreeOfFreedom: The degree of freedom of the Joint along or around
                        which the Damper acts. Represented as a
                        DegreeOfFreedomEnum.
          coefficient:  The viscous damping coefficient of a Damper in SI units,
                        currently newton seconds per metre for Dampers acting
                        along translational degrees of freedom and newton metre
                        seconds per radian for Dampers acting around rotational
                        degrees of freedom. The default is 0.0. This is ignored
                        when there is a CoefficientExpression sub-element.

          Sub-element:

          CoefficientExpression: A MechanismExpression that defines the viscous
                        damping coefficient of a non-linear Damper in SI units.
                        (newton seconds per metre along translational degrees of
                        freedom and newton metre seconds per radian around
                        rotational degrees of freedom.)
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API DamperData : public AttribOwner
{
public:
     
    //! Default constructor
    DamperData( );
     
    //! Constructs a DamperData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    DamperData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~DamperData();

private:

	//! Assignment operator
	DamperData& operator=( const DamperData& iSrc );

	//! Copy constructor
	DamperData( const DamperData& original );
     
public:

	//! Set Coefficient
	plmxml_api::Result SetCoefficient( double arg );

     //! Get Coefficient
	double GetCoefficient() const;

	//! Check if Coefficient is set
	plmxml_api::logical HasCoefficient() const;

	//! Unset Coefficient
	plmxml_api::Result UnsetCoefficient();

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Add CoefficientExpression child element to this DamperData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddCoefficientExpression();
     
	//! Set CoefficientExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCoefficientExpression( MechanismExpression *arg );
     
	//! Get CoefficientExpression child element of this DamperData.
	MechanismExpression *GetCoefficientExpression() const;
     
	//! Detach and delete CoefficientExpression child element tree from this DamperData.
	void DeleteCoefficientExpression();
 
// <PLMXML_UserCode type="functionHeaderDamperData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassDamperData;


//! Forward class declarations
class BushingComponent;

////////////////////////////////////////////////////////////////////////////////////
//! BushingData class
/*!
\verbatim

          Additional data for a Bushing Constraint. Only one BushingData
          sub-element is allowed in a Constraint, ConstraintInstance or
          ConstraintOccurrence element.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          preloadForce: The vector components of the preload force in SI units,
                        currently newtons. The default is 0.0, 0.0, 0.0.
          preloadTorque: The vector components of the preload torque in SI
                        units, currently newton metres. The default is 0.0, 0.0,
                        0.0.
          translationStiffness: The translational vector components of the
                        spring constant of the Bushing in SI units, currently
                        newtons per metre. The default is 0.0, 0.0, 0.0. This is
                        ignored when there is a BushingComponent sub-element.
          rotationStiffness: The rotational vector components of the spring
                        constant of the Bushing in SI units, currently newton
                        metres per radian. The default is 0.0, 0.0, 0.0. This is
                        ignored when there is a BushingComponent sub-element.
          translationCoefficient: The translational vector components of the
                        viscous damping coefficient of the Bushing in SI units,
                        currently newton seconds per metre. The default is 0.0,
                        0.0, 0.0. This is ignored when there is a
                        BushingComponent sub-element.
          rotationCoefficient: The rotational vector components of the viscous
                        damping coefficient of the Bushing in SI units,
                        currently newton metre seconds per radian. The default
                        is 0.0, 0.0, 0.0. This is ignored when there is a
                        BushingComponent sub-element.

          Sub-element:

          BushingComponent: The components of the Bushing represented as
                        BushingComponentType.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API BushingData : public AttribOwner
{
public:
     
    //! Default constructor
    BushingData( );
     
    //! Constructs a BushingData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BushingData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BushingData();

private:

	//! Assignment operator
	BushingData& operator=( const BushingData& iSrc );

	//! Copy constructor
	BushingData( const BushingData& original );
     
public:

	//! Set TranslationStiffness using plmxml_api::Vector components
	plmxml_api::Result SetTranslationStiffness( const plmxml_api::Vector& arg );

	//! Get TranslationStiffness as plmxml_api::Vector
	plmxml_api::Result GetTranslationStiffness( plmxml_api::Vector& arg ) const;

	//! Check if TranslationStiffness is set
	plmxml_api::logical HasTranslationStiffness() const;

	//! Unset TranslationStiffness
	plmxml_api::Result UnsetTranslationStiffness();

	//! Set PreloadTorque using plmxml_api::Vector components
	plmxml_api::Result SetPreloadTorque( const plmxml_api::Vector& arg );

	//! Get PreloadTorque as plmxml_api::Vector
	plmxml_api::Result GetPreloadTorque( plmxml_api::Vector& arg ) const;

	//! Check if PreloadTorque is set
	plmxml_api::logical HasPreloadTorque() const;

	//! Unset PreloadTorque
	plmxml_api::Result UnsetPreloadTorque();

	//! Set PreloadForce using plmxml_api::Vector components
	plmxml_api::Result SetPreloadForce( const plmxml_api::Vector& arg );

	//! Get PreloadForce as plmxml_api::Vector
	plmxml_api::Result GetPreloadForce( plmxml_api::Vector& arg ) const;

	//! Check if PreloadForce is set
	plmxml_api::logical HasPreloadForce() const;

	//! Unset PreloadForce
	plmxml_api::Result UnsetPreloadForce();

	//! Set RotationCoefficient using plmxml_api::Vector components
	plmxml_api::Result SetRotationCoefficient( const plmxml_api::Vector& arg );

	//! Get RotationCoefficient as plmxml_api::Vector
	plmxml_api::Result GetRotationCoefficient( plmxml_api::Vector& arg ) const;

	//! Check if RotationCoefficient is set
	plmxml_api::logical HasRotationCoefficient() const;

	//! Unset RotationCoefficient
	plmxml_api::Result UnsetRotationCoefficient();

	//! Set RotationStiffness using plmxml_api::Vector components
	plmxml_api::Result SetRotationStiffness( const plmxml_api::Vector& arg );

	//! Get RotationStiffness as plmxml_api::Vector
	plmxml_api::Result GetRotationStiffness( plmxml_api::Vector& arg ) const;

	//! Check if RotationStiffness is set
	plmxml_api::logical HasRotationStiffness() const;

	//! Unset RotationStiffness
	plmxml_api::Result UnsetRotationStiffness();

	//! Set TranslationCoefficient using plmxml_api::Vector components
	plmxml_api::Result SetTranslationCoefficient( const plmxml_api::Vector& arg );

	//! Get TranslationCoefficient as plmxml_api::Vector
	plmxml_api::Result GetTranslationCoefficient( plmxml_api::Vector& arg ) const;

	//! Check if TranslationCoefficient is set
	plmxml_api::logical HasTranslationCoefficient() const;

	//! Unset TranslationCoefficient
	plmxml_api::Result UnsetTranslationCoefficient();

	//! Add BushingComponent child element to this BushingData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	BushingComponent *AddBushingComponent();
     
	//! Add 'arg' as BushingComponent child element to this BushingData.
	plmxml_api::Result AddBushingComponent( BushingComponent *arg );

	//! Detach and delete all BushingComponent child elements.
	void DeleteBushingComponents();
     
	//! Get number of BushingComponent child elements.
	int NumberOfBushingComponents() const;
     
	//! Get i'th BushingComponent child element.
	BushingComponent *GetBushingComponent( int i ) const;
     
	//! Get all BushingComponent child element as an array
	void GetBushingComponents( plmxml_api::Array<BushingComponent*> &array ) const;
	     
	//! Detach and delete i'th BushingComponent child element
	void DeleteBushingComponent( int i );
     
	//! Detach and delete 'arg' if it's one of the BushingComponent child elements
	void DeleteBushingComponent( BushingComponent *arg );
 
// <PLMXML_UserCode type="functionHeaderBushingData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassBushingData;


////////////////////////////////////////////////////////////////////////////////////
//! ContactData class
/*!
\verbatim

            Additional data for a Contact Constraint. Only one ContactData sub-element is allowed in a
            Constraint, ConstraintInstance or ConstraintOccurrence element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.
            impact:         Whether the contact model is impact or poisson.
            stiffness:      The spring constant of the Contact in SI units, currently newtons per metre.
                            The default is 0.0.
            stiffnessExponent: The exponent of the penetration in a non-linear spring equation, used to
                            calculate the normal force. The default is 1.0.
            dampingCoefficient: The viscous damping coefficient of the Contact in SI units, currently
                            newton seconds per metre. The default is 0.0.
            boundaryPenetration: The penetration in SI units, currently metres, at which the effective
                            coefficient of damping equals the dampingCoefficient.
            restitution:    The coefficient of restitution. This is a dimensionless quantity.
            staticCoefficient: The coefficient of static friction. This is a dimensionless quantity. The
                            default is 0.0.
            dynamicCoefficient: The coefficient of dynamic friction. This is a dimensionless quantity. The
                            default is 0.0.
            staticTransitionSpeed: The surface speed at which the transition from static friction to
                            dynamic friction begins in SI units, currently metres per second. The effective
                            coefficient of friction equals the coefficient of static friction.
            dynamicTransitionSpeed: The surface speed at which the transition from static friction to
                            dynamic friction ends in SI units, currently metres per second. The effective
                            coefficient of friction equals the coefficient of dynamic friction.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API ContactData : public AttribOwner
{
public:
     
    //! Default constructor
    ContactData( );
     
    //! Constructs a ContactData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ContactData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ContactData();

private:

	//! Assignment operator
	ContactData& operator=( const ContactData& iSrc );

	//! Copy constructor
	ContactData( const ContactData& original );
     
public:

	//! Set Impact
	plmxml_api::Result SetImpact( plmxml_api::logical arg );

	//! Get Impact
	plmxml_api::logical GetImpact() const;

	//! Check if Impact is set
	plmxml_api::logical HasImpact() const;

	//! Unset Impact
	plmxml_api::Result UnsetImpact();

	//! Set DampingCoefficient
	plmxml_api::Result SetDampingCoefficient( double arg );

     //! Get DampingCoefficient
	double GetDampingCoefficient() const;

	//! Check if DampingCoefficient is set
	plmxml_api::logical HasDampingCoefficient() const;

	//! Unset DampingCoefficient
	plmxml_api::Result UnsetDampingCoefficient();

	//! Set StaticCoefficient
	plmxml_api::Result SetStaticCoefficient( double arg );

     //! Get StaticCoefficient
	double GetStaticCoefficient() const;

	//! Check if StaticCoefficient is set
	plmxml_api::logical HasStaticCoefficient() const;

	//! Unset StaticCoefficient
	plmxml_api::Result UnsetStaticCoefficient();

	//! Set Restitution
	plmxml_api::Result SetRestitution( double arg );

     //! Get Restitution
	double GetRestitution() const;

	//! Check if Restitution is set
	plmxml_api::logical HasRestitution() const;

	//! Unset Restitution
	plmxml_api::Result UnsetRestitution();

	//! Set DynamicCoefficient
	plmxml_api::Result SetDynamicCoefficient( double arg );

     //! Get DynamicCoefficient
	double GetDynamicCoefficient() const;

	//! Check if DynamicCoefficient is set
	plmxml_api::logical HasDynamicCoefficient() const;

	//! Unset DynamicCoefficient
	plmxml_api::Result UnsetDynamicCoefficient();

	//! Set StaticTransitionSpeed
	plmxml_api::Result SetStaticTransitionSpeed( double arg );

     //! Get StaticTransitionSpeed
	double GetStaticTransitionSpeed() const;

	//! Check if StaticTransitionSpeed is set
	plmxml_api::logical HasStaticTransitionSpeed() const;

	//! Unset StaticTransitionSpeed
	plmxml_api::Result UnsetStaticTransitionSpeed();

	//! Set Stiffness
	plmxml_api::Result SetStiffness( double arg );

     //! Get Stiffness
	double GetStiffness() const;

	//! Check if Stiffness is set
	plmxml_api::logical HasStiffness() const;

	//! Unset Stiffness
	plmxml_api::Result UnsetStiffness();

	//! Set BoundaryPenetration
	plmxml_api::Result SetBoundaryPenetration( double arg );

     //! Get BoundaryPenetration
	double GetBoundaryPenetration() const;

	//! Check if BoundaryPenetration is set
	plmxml_api::logical HasBoundaryPenetration() const;

	//! Unset BoundaryPenetration
	plmxml_api::Result UnsetBoundaryPenetration();

	//! Set DynamicTransitionSpeed
	plmxml_api::Result SetDynamicTransitionSpeed( double arg );

     //! Get DynamicTransitionSpeed
	double GetDynamicTransitionSpeed() const;

	//! Check if DynamicTransitionSpeed is set
	plmxml_api::logical HasDynamicTransitionSpeed() const;

	//! Unset DynamicTransitionSpeed
	plmxml_api::Result UnsetDynamicTransitionSpeed();

	//! Set StiffnessExponent
	plmxml_api::Result SetStiffnessExponent( double arg );

     //! Get StiffnessExponent
	double GetStiffnessExponent() const;

	//! Check if StiffnessExponent is set
	plmxml_api::logical HasStiffnessExponent() const;

	//! Unset StiffnessExponent
	plmxml_api::Result UnsetStiffnessExponent();
 
// <PLMXML_UserCode type="functionHeaderContactData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassContactData;


////////////////////////////////////////////////////////////////////////////////////
//! CouplerData class
/*!
\verbatim

            Additional data for a Coupler Constraint or a Joint Constraint that
            infers a Coupler. Only one CouplerData sub-element is allowed in a
            Constraint, ConstraintInstance or ConstraintOccurrence element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.
            type:           The type of the Coupler as a CouplerEnum.
            ratio:          The ratio of the first Joint of the Coupler to the
                            second Joint of the Coupler in SI units, currently
                            metres or radians. The default is 1.0. This
                            attribute is deprecated in favour of ratios.
            ratios:         A list of ratio values in SI units, currently metres
                            or radians. The first value represents the ratio of
                            the Joint given by the last ConstraintTargetRef of
                            the Coupler to the Joint given by the first. The
                            second value represents the ratio of the Joint given
                            by the last ConstraintTargetRef of the Coupler to
                            the Joint given by the second. And so on.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API CouplerData : public AttribOwner
{
public:
     
    //! Default constructor
    CouplerData( );
     
    //! Constructs a CouplerData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    CouplerData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~CouplerData();

private:

	//! Assignment operator
	CouplerData& operator=( const CouplerData& iSrc );

	//! Copy constructor
	CouplerData( const CouplerData& original );
     
public:

	//! Set Ratios
	plmxml_api::Result SetRatios( const plmxml_api::Array<double>& arg );

	//! Get Ratios
	plmxml_api::Result GetRatios( plmxml_api::Array<double>& arg ) const;

	//! Check if Ratios is set
	plmxml_api::logical HasRatios() const;

	//! Unset Ratios
	plmxml_api::Result UnsetRatios();

	//! Set Type
	plmxml_api::Result SetType( const eCouplerEnum& arg );

	//! Get Type
	eCouplerEnum GetType() const;

	//! Set Ratio
	plmxml_api::Result SetRatio( double arg );

     //! Get Ratio
	double GetRatio() const;

	//! Check if Ratio is set
	plmxml_api::logical HasRatio() const;

	//! Unset Ratio
	plmxml_api::Result UnsetRatio();
 
// <PLMXML_UserCode type="functionHeaderCouplerData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassCouplerData;


////////////////////////////////////////////////////////////////////////////////////
//! LimitsDependencyData class
/*!
\verbatim

            Additional data for a Limits Dependency Constraint. Only one
            LimitsDependencyData sub-element is allowed in a Constraint,
            ConstraintInstance or ConstraintOccurrence element.

            Attributes:

            id:             Inherited from AttribOwner.
            name:           Inherited from AttribOwner.

            Sub-elements:

            ValueWithUnit:  The list of ValueWithUnit sub-elements represents
                            the values of the independent Joint given by the
                            first ConstraintTargetRef of the Limits Dependency.
                            The limits of the dependent Joint corresponding to a
                            given value are represented by the corresponding
                            RangeWithUnit sub-element. The limits of the
                            dependent Joint at intermediate values of the
                            independent Joint are found by linear interpolation.
            RangeWithUnit:  The list of RangeWithUnit sub-elements represents
                            the limits of the dependent Joint given by the
                            second ConstraintTargetRef of the Limits Dependency.
                            The value of the independent Joint corresponding to
                            given limits is represented by the corresponding
                            ValueWithUnit sub-element. The limits of the
                            dependent Joint at intermediate values of the
                            independent Joint are found by linear interpolation.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API LimitsDependencyData : public AttribOwner
{
public:
     
    //! Default constructor
    LimitsDependencyData( );
     
    //! Constructs a LimitsDependencyData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    LimitsDependencyData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~LimitsDependencyData();

private:

	//! Assignment operator
	LimitsDependencyData& operator=( const LimitsDependencyData& iSrc );

	//! Copy constructor
	LimitsDependencyData( const LimitsDependencyData& original );
     
public:

	//! Add ValueWithUnit child element to this LimitsDependencyData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ValueWithUnit *AddValueWithUnit();
     
	//! Add 'arg' as ValueWithUnit child element to this LimitsDependencyData.
	plmxml_api::Result AddValueWithUnit( ValueWithUnit *arg );

	//! Detach and delete all ValueWithUnit child elements.
	void DeleteValueWithUnits();
     
	//! Get number of ValueWithUnit child elements.
	int NumberOfValueWithUnits() const;
     
	//! Get i'th ValueWithUnit child element.
	ValueWithUnit *GetValueWithUnit( int i ) const;
     
	//! Get all ValueWithUnit child element as an array
	void GetValueWithUnits( plmxml_api::Array<ValueWithUnit*> &array ) const;
	     
	//! Detach and delete i'th ValueWithUnit child element
	void DeleteValueWithUnit( int i );
     
	//! Detach and delete 'arg' if it's one of the ValueWithUnit child elements
	void DeleteValueWithUnit( ValueWithUnit *arg );

	//! Add RangeWithUnit child element to this LimitsDependencyData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	RangeWithUnit *AddRangeWithUnit();
     
	//! Add 'arg' as RangeWithUnit child element to this LimitsDependencyData.
	plmxml_api::Result AddRangeWithUnit( RangeWithUnit *arg );

	//! Detach and delete all RangeWithUnit child elements.
	void DeleteRangeWithUnits();
     
	//! Get number of RangeWithUnit child elements.
	int NumberOfRangeWithUnits() const;
     
	//! Get i'th RangeWithUnit child element.
	RangeWithUnit *GetRangeWithUnit( int i ) const;
     
	//! Get all RangeWithUnit child element as an array
	void GetRangeWithUnits( plmxml_api::Array<RangeWithUnit*> &array ) const;
	     
	//! Detach and delete i'th RangeWithUnit child element
	void DeleteRangeWithUnit( int i );
     
	//! Detach and delete 'arg' if it's one of the RangeWithUnit child elements
	void DeleteRangeWithUnit( RangeWithUnit *arg );
 
// <PLMXML_UserCode type="functionHeaderLimitsDependencyData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassLimitsDependencyData;


////////////////////////////////////////////////////////////////////////////////////
//! BushingComponent class
/*!
\verbatim

          The components of a BushingData. Non-linear bushings are represented
          by having 6 BushingComponent sub-elements under a BushingData, one for
          each degree of freedom.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          degreeOfFreedom: The degree of freedom of the Bushing. Represented as
                        a DegreeOfFreedomEnum.

          Sub-elements:

          StiffnessExpression: A MechanismExpression that defines the spring
                        constant of a non-linear Bushing in SI units. (newtons
                        per metre along translational degrees of freedom and
                        newton metres per radian around rotational degrees of
                        freedom.)
          CoefficientExpression: A MechanismExpression that defines the viscous
                        damping coefficient of a non-linear Bushing in SI units.
                        (newton seconds per metre along translational degrees of
                        freedom and newton metre seconds per radian around
                        rotational degrees of freedom.)
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API BushingComponent : public AttribOwner
{
public:
     
    //! Default constructor
    BushingComponent( );
     
    //! Constructs a BushingComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    BushingComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~BushingComponent();

private:

	//! Assignment operator
	BushingComponent& operator=( const BushingComponent& iSrc );

	//! Copy constructor
	BushingComponent( const BushingComponent& original );
     
public:

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;

	//! Add StiffnessExpression child element to this BushingComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddStiffnessExpression();
     
	//! Set StiffnessExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStiffnessExpression( MechanismExpression *arg );
     
	//! Get StiffnessExpression child element of this BushingComponent.
	MechanismExpression *GetStiffnessExpression() const;
     
	//! Detach and delete StiffnessExpression child element tree from this BushingComponent.
	void DeleteStiffnessExpression();

	//! Add CoefficientExpression child element to this BushingComponent. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddCoefficientExpression();
     
	//! Set CoefficientExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCoefficientExpression( MechanismExpression *arg );
     
	//! Get CoefficientExpression child element of this BushingComponent.
	MechanismExpression *GetCoefficientExpression() const;
     
	//! Detach and delete CoefficientExpression child element tree from this BushingComponent.
	void DeleteCoefficientExpression();
 
// <PLMXML_UserCode type="functionHeaderBushingComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassBushingComponent;


////////////////////////////////////////////////////////////////////////////////////
//! SensorComponent class
/*!
\verbatim

          A component of a Sensor, SensorInstance or SensorOccurrence. None, one
          or 3 SensorComponent sub-elements are allowed under a SensorData.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          degreeOfFreedom: The degree of freedom along or around which the
                        sensor senses. Represented as a DegreeOfFreedomEnum.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API SensorComponent : public AttribOwner
{
public:
     
    //! Default constructor
    SensorComponent( );
     
    //! Constructs a SensorComponent with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SensorComponent( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SensorComponent();

private:

	//! Assignment operator
	SensorComponent& operator=( const SensorComponent& iSrc );

	//! Copy constructor
	SensorComponent( const SensorComponent& original );
     
public:

	//! Set DegreeOfFreedom
	plmxml_api::Result SetDegreeOfFreedom( const eDegreeOfFreedomEnum& arg );

	//! Get DegreeOfFreedom
	eDegreeOfFreedomEnum GetDegreeOfFreedom() const;
 
// <PLMXML_UserCode type="functionHeaderSensorComponent" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSensorComponent;


////////////////////////////////////////////////////////////////////////////////////
//! SensorData class
/*!
\verbatim

          Additional data for a Sensor, SensorInstance or SensorOccurrence. Only
          one SensorData sub-element is allowed.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          translation:  When there are no SensorComponent sub-elements under the
                        SensorData, translation indicates whether the Sensor
                        senses along or around the line joining the Marker given
                        by the first ConstraintTargetRef sub-element under the
                        Sensor, SensorInstance or SensorOccurrence to the Marker
                        given by the second.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API SensorData : public AttribOwner
{
public:
     
    //! Default constructor
    SensorData( );
     
    //! Constructs a SensorData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SensorData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SensorData();

private:

	//! Assignment operator
	SensorData& operator=( const SensorData& iSrc );

	//! Copy constructor
	SensorData( const SensorData& original );
     
public:

	//! Set Translation
	plmxml_api::Result SetTranslation( plmxml_api::logical arg );

	//! Get Translation
	plmxml_api::logical GetTranslation() const;

	//! Check if Translation is set
	plmxml_api::logical HasTranslation() const;

	//! Unset Translation
	plmxml_api::Result UnsetTranslation();

	//! Add SensorComponent child element to this SensorData. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	SensorComponent *AddSensorComponent();
     
	//! Add 'arg' as SensorComponent child element to this SensorData.
	plmxml_api::Result AddSensorComponent( SensorComponent *arg );

	//! Detach and delete all SensorComponent child elements.
	void DeleteSensorComponents();
     
	//! Get number of SensorComponent child elements.
	int NumberOfSensorComponents() const;
     
	//! Get i'th SensorComponent child element.
	SensorComponent *GetSensorComponent( int i ) const;
     
	//! Get all SensorComponent child element as an array
	void GetSensorComponents( plmxml_api::Array<SensorComponent*> &array ) const;
	     
	//! Detach and delete i'th SensorComponent child element
	void DeleteSensorComponent( int i );
     
	//! Detach and delete 'arg' if it's one of the SensorComponent child elements
	void DeleteSensorComponent( SensorComponent *arg );
 
// <PLMXML_UserCode type="functionHeaderSensorData" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSensorData;


////////////////////////////////////////////////////////////////////////////////////
//! Sensor class
/*!
\verbatim

          A Sensor acts like a Constraint in reverse. The value of a Sensor is
          the physical quantity in SI units.

          Attributes:

          type:         The physical quantity that the Sensor senses.

          Sub-elements:

          SensorData:   Additional data for the Sensor.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Sensor : public GDE
{
public:
     
    //! Default constructor
    Sensor( );
     
    //! Constructs a Sensor with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Sensor( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Sensor();

private:

	//! Assignment operator
	Sensor& operator=( const Sensor& iSrc );

	//! Copy constructor
	Sensor( const Sensor& original );
     
public:

	//! Set Type
	plmxml_api::Result SetType( const eSensorEnum& arg );

	//! Get Type
	eSensorEnum GetType() const;

	//! Add SensorData child element to this Sensor. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SensorData *AddSensorData();
     
	//! Set SensorData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSensorData( SensorData *arg );
     
	//! Get SensorData child element of this Sensor.
	SensorData *GetSensorData() const;
     
	//! Detach and delete SensorData child element tree from this Sensor.
	void DeleteSensorData();
 
// <PLMXML_UserCode type="functionHeaderSensor" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSensor;


////////////////////////////////////////////////////////////////////////////////////
//! SensorInstance class
/*!
\verbatim

          An instance of a Sensor.

          Attribute:

          coordinateFrame: The coordinate frame in which the directional and
                        orientational properties of a Sensor are defined.

          Sub-elements:

          ConstraintTargetRef: References the Markers between which the physical
                        quantity is sensed.
          SensorData:   Overrides any additional data for the Sensor.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API SensorInstance : public GDEInstance
{
public:
     
    //! Default constructor
    SensorInstance( );
     
    //! Constructs a SensorInstance with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SensorInstance( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SensorInstance();

private:

	//! Assignment operator
	SensorInstance& operator=( const SensorInstance& iSrc );

	//! Copy constructor
	SensorInstance( const SensorInstance& original );
     
public:

	//! Set CoordinateFrame
	plmxml_api::Result SetCoordinateFrame( const eCoordinateFrameEnum& arg );

	//! Get CoordinateFrame
	eCoordinateFrameEnum GetCoordinateFrame() const;

	//! Add ConstraintTargetRef child element to this SensorInstance. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintTargetRef *AddConstraintTargetRef();
     
	//! Add 'arg' as ConstraintTargetRef child element to this SensorInstance.
	plmxml_api::Result AddConstraintTargetRef( ConstraintTargetRef *arg );

	//! Detach and delete all ConstraintTargetRef child elements.
	void DeleteConstraintTargetRefs();
     
	//! Get number of ConstraintTargetRef child elements.
	int NumberOfConstraintTargetRefs() const;
     
	//! Get i'th ConstraintTargetRef child element.
	ConstraintTargetRef *GetConstraintTargetRef( int i ) const;
     
	//! Get all ConstraintTargetRef child element as an array
	void GetConstraintTargetRefs( plmxml_api::Array<ConstraintTargetRef*> &array ) const;
	     
	//! Detach and delete i'th ConstraintTargetRef child element
	void DeleteConstraintTargetRef( int i );
     
	//! Detach and delete 'arg' if it's one of the ConstraintTargetRef child elements
	void DeleteConstraintTargetRef( ConstraintTargetRef *arg );

	//! Add SensorData child element to this SensorInstance. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SensorData *AddSensorData();
     
	//! Set SensorData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSensorData( SensorData *arg );
     
	//! Get SensorData child element of this SensorInstance.
	SensorData *GetSensorData() const;
     
	//! Detach and delete SensorData child element tree from this SensorInstance.
	void DeleteSensorData();
 
// <PLMXML_UserCode type="functionHeaderSensorInstance" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSensorInstance;


////////////////////////////////////////////////////////////////////////////////////
//! SensorOccurrence class
/*!
\verbatim

          An occurrence of a Sensor or SensorInstance.

          Attribute:

          coordinateFrame: The coordinate frame in which the directional and
                        orientational properties of a Sensor are defined.

          Sub-elements:

          ConstraintTargetRef: Overrides the references to the Markers between
                        which the physical quantity is sensed.
          SensorData:   Overrides any additional data for the Sensor or
                        SensorInstance.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API SensorOccurrence : public Occurrence
{
public:
     
    //! Default constructor
    SensorOccurrence( );
     
    //! Constructs a SensorOccurrence with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    SensorOccurrence( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~SensorOccurrence();

private:

	//! Assignment operator
	SensorOccurrence& operator=( const SensorOccurrence& iSrc );

	//! Copy constructor
	SensorOccurrence( const SensorOccurrence& original );
     
public:

	//! Set CoordinateFrame
	plmxml_api::Result SetCoordinateFrame( const eCoordinateFrameEnum& arg );

	//! Get CoordinateFrame
	eCoordinateFrameEnum GetCoordinateFrame() const;

	//! Add ConstraintTargetRef child element to this SensorOccurrence. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	ConstraintTargetRef *AddConstraintTargetRef();
     
	//! Add 'arg' as ConstraintTargetRef child element to this SensorOccurrence.
	plmxml_api::Result AddConstraintTargetRef( ConstraintTargetRef *arg );

	//! Detach and delete all ConstraintTargetRef child elements.
	void DeleteConstraintTargetRefs();
     
	//! Get number of ConstraintTargetRef child elements.
	int NumberOfConstraintTargetRefs() const;
     
	//! Get i'th ConstraintTargetRef child element.
	ConstraintTargetRef *GetConstraintTargetRef( int i ) const;
     
	//! Get all ConstraintTargetRef child element as an array
	void GetConstraintTargetRefs( plmxml_api::Array<ConstraintTargetRef*> &array ) const;
	     
	//! Detach and delete i'th ConstraintTargetRef child element
	void DeleteConstraintTargetRef( int i );
     
	//! Detach and delete 'arg' if it's one of the ConstraintTargetRef child elements
	void DeleteConstraintTargetRef( ConstraintTargetRef *arg );

	//! Add SensorData child element to this SensorOccurrence. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	SensorData *AddSensorData();
     
	//! Set SensorData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSensorData( SensorData *arg );
     
	//! Get SensorData child element of this SensorOccurrence.
	SensorData *GetSensorData() const;
     
	//! Detach and delete SensorData child element tree from this SensorOccurrence.
	void DeleteSensorData();
 
// <PLMXML_UserCode type="functionHeaderSensorOccurrence" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassSensorOccurrence;


////////////////////////////////////////////////////////////////////////////////////
//! Trigger class
/*!
\verbatim

          A trigger for a Step based on the value of a Sensor, SensorInstance or
          SensorOccurrence.

          Attributes:

          sensorRef:    A reference to a SensorInstance or SensorOccurrence. If
                        sensorRef is set, condition should also be set but delay
                        should not be set.
          threshold:    The value of the SensorInstance or SensorOccurrence, at
                        which the value of the Trigger changes.
          condition:    The binary operator between the value of the Sensor,
                        SensorInstance or SensorOccurrence and threshold (in
                        that order). The expression so formed is the boolean
                        value of the Trigger. If condition is set, sensorRef
                        should also be set but delay should not be set.
          delay:        The time in seconds, after the start of its enclosing
                        TimingFunction, at which the Trigger becomes true. If
                        delay is set, sensorRef and condition should not be set.
          alwaysMonitored: When alwaysMonitored is true, the Step is triggered
                        if the value of the Trigger becomes true any time after
                        the start of the TimingFunction, even if it then becomes
                        false before the start of the Step. When alwaysMonitored
                        is false (the default value) the Step is triggered when
                        the value of the Trigger becomes true after the start of
                        the Step.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Trigger : public AttribOwner
{
public:
     
    //! Default constructor
    Trigger( );
     
    //! Constructs a Trigger with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Trigger( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Trigger();

private:

	//! Assignment operator
	Trigger& operator=( const Trigger& iSrc );

	//! Copy constructor
	Trigger( const Trigger& original );
     
public:

	//! Set Delay
	plmxml_api::Result SetDelay( double arg );

     //! Get Delay
	double GetDelay() const;

	//! Check if Delay is set
	plmxml_api::logical HasDelay() const;

	//! Unset Delay
	plmxml_api::Result UnsetDelay();

	//! Set Threshold
	plmxml_api::Result SetThreshold( double arg );

     //! Get Threshold
	double GetThreshold() const;

	//! Check if Threshold is set
	plmxml_api::logical HasThreshold() const;

	//! Unset Threshold
	plmxml_api::Result UnsetThreshold();

	//! Get Sensor URI as plmxml_api::String
	plmxml_api::String GetSensorURI() const;

	//! Set Sensor URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetSensorURI( const plmxml_api::String& );
	
	//! Get the handle of Sensor URI. Does not resolve the URI.
	plmxml_api::Result GetSensorURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Sensor URI. URI string is unchanged.
	plmxml_api::Result SetSensorURI( const plmxml_api::Handle& );
	
	//! Resolve Sensor URI and return an object (handle) it points to.
	plmxml_api::Result ResolveSensorURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Sensor URI. Clears URI string and handle.
	plmxml_api::Result DeleteSensorURI();
	
	//! Check if Sensor URI is set
	plmxml_api::logical HasSensorURI( ) const;
	

	//! Set Condition
	plmxml_api::Result SetCondition( const eConditionEnum& arg );

	//! Get Condition
	eConditionEnum GetCondition() const;

	//! Set AlwaysMonitored
	plmxml_api::Result SetAlwaysMonitored( plmxml_api::logical arg );

	//! Get AlwaysMonitored
	plmxml_api::logical GetAlwaysMonitored() const;

	//! Check if AlwaysMonitored is set
	plmxml_api::logical HasAlwaysMonitored() const;

	//! Unset AlwaysMonitored
	plmxml_api::Result UnsetAlwaysMonitored();
 
// <PLMXML_UserCode type="functionHeaderTrigger" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassTrigger;


////////////////////////////////////////////////////////////////////////////////////
//! Step class
/*!
\verbatim

          Specifies the value of a TimingFunction for a specified time.

          Attributes:

          delay:        The time in seconds that the Step waits after any
                        Trigger becomes true before the value of the
                        TimingFunction becomes the value of the value attribute.
                        If there is no Trigger, the Step does not wait.
          duration:     The time in seconds that the Step waits after the value
                        of the TimingFunction becomes the value of the value
                        attribute before moving to the next Step.
          value:        The value of the step.

          Sub-elements:

          Trigger:      The trigger for the Step.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Step : public AttribOwner
{
public:
     
    //! Default constructor
    Step( );
     
    //! Constructs a Step with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Step( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Step();

private:

	//! Assignment operator
	Step& operator=( const Step& iSrc );

	//! Copy constructor
	Step( const Step& original );
     
public:

	//! Set Delay
	plmxml_api::Result SetDelay( double arg );

     //! Get Delay
	double GetDelay() const;

	//! Check if Delay is set
	plmxml_api::logical HasDelay() const;

	//! Unset Delay
	plmxml_api::Result UnsetDelay();

	//! Set Duration
	plmxml_api::Result SetDuration( double arg );

     //! Get Duration
	double GetDuration() const;

	//! Check if Duration is set
	plmxml_api::logical HasDuration() const;

	//! Unset Duration
	plmxml_api::Result UnsetDuration();

	//! Set Value
	plmxml_api::Result SetValue( double arg );

     //! Get Value
	double GetValue() const;

	//! Check if Value is set
	plmxml_api::logical HasValue() const;

	//! Unset Value
	plmxml_api::Result UnsetValue();

	//! Add Trigger child element to this Step. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Trigger *AddTrigger();
     
	//! Set Trigger child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetTrigger( Trigger *arg );
     
	//! Get Trigger child element of this Step.
	Trigger *GetTrigger() const;
     
	//! Detach and delete Trigger child element tree from this Step.
	void DeleteTrigger();
 
// <PLMXML_UserCode type="functionHeaderStep" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassStep;


////////////////////////////////////////////////////////////////////////////////////
//! TimingFunction class
/*!
\verbatim

          Specifies a value in discrete timing steps or over a continuous time.

          Attributes:

          closed:       In closed loop control, the signals are controlled by
                        sensors. In open loop control, they are not. The default
                        for the closed attribute is false, meaning the default
                        is open loop control.

          Sub-elements:

          Step:         A list of values of the TimingFunction for specified
                        times.
          ValueExpression: A MechanismExpression that defines the value of the
                        TimingFunction over a specified time.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API TimingFunction : public AttribOwner
{
public:
     
    //! Default constructor
    TimingFunction( );
     
    //! Constructs a TimingFunction with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    TimingFunction( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~TimingFunction();

private:

	//! Assignment operator
	TimingFunction& operator=( const TimingFunction& iSrc );

	//! Copy constructor
	TimingFunction( const TimingFunction& original );
     
public:

	//! Set Closed
	plmxml_api::Result SetClosed( plmxml_api::logical arg );

	//! Get Closed
	plmxml_api::logical GetClosed() const;

	//! Check if Closed is set
	plmxml_api::logical HasClosed() const;

	//! Unset Closed
	plmxml_api::Result UnsetClosed();

	//! Add Step child element to this TimingFunction. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Step *AddStep();
     
	//! Add 'arg' as Step child element to this TimingFunction.
	plmxml_api::Result AddStep( Step *arg );

	//! Detach and delete all Step child elements.
	void DeleteSteps();
     
	//! Get number of Step child elements.
	int NumberOfSteps() const;
     
	//! Get i'th Step child element.
	Step *GetStep( int i ) const;
     
	//! Get all Step child element as an array
	void GetSteps( plmxml_api::Array<Step*> &array ) const;
	     
	//! Detach and delete i'th Step child element
	void DeleteStep( int i );
     
	//! Detach and delete 'arg' if it's one of the Step child elements
	void DeleteStep( Step *arg );

	//! Add ValueExpression child element to this TimingFunction. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MechanismExpression *AddValueExpression();
     
	//! Set ValueExpression child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetValueExpression( MechanismExpression *arg );
     
	//! Get ValueExpression child element of this TimingFunction.
	MechanismExpression *GetValueExpression() const;
     
	//! Detach and delete ValueExpression child element tree from this TimingFunction.
	void DeleteValueExpression();
 
// <PLMXML_UserCode type="functionHeaderTimingFunction" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassTimingFunction;


////////////////////////////////////////////////////////////////////////////////////
//! Motor class
/*!
\verbatim

          A definition of a motor. A motor must be referenced from a force to
          apply a force or from a driver to cause motion.

          Attributes:

          id:           Inherited from AttribOwner.
          name:         Inherited from AttribOwner.
          type:         The type of motor as a MotorEnum.
          initialVelocity: The initial velocity of the rotor of the motor in
                        metres per second for linear motor and radians per
                        second in rotary motors.
          resistance:   The resistance of the motor in ohms.
          inductance:   The inductance of the motor in henries.
          current:      The initial current of the motor in amps.
          backEMFConstant: The back EMF constant in volt seconds per metre for
                        linear motors and volt seconds per radian for rotary
                        motors.
          forceConstant: The force constant of a linear motor in newtons per
                        amp. The torque constant of a rotary motor in newton
                        metres per amp.
          inertia:      The mass of a linear motor in kilogrammes. The moment of
                        inertia of a rotary motor in kilogramme metres squared.
          dampingCoefficient: The damping coefficient in newton seconds per
                        metre for linear motors and newton metre seconds per
                        radian for rotary motors.
          voltage:      The nominal voltage to the motor in volts.
          
\endverbatim
*/
class PLMXML_CONSTRAINT60_API Motor : public AttribOwner
{
public:
     
    //! Default constructor
    Motor( );
     
    //! Constructs a Motor with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Motor( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Motor();

private:

	//! Assignment operator
	Motor& operator=( const Motor& iSrc );

	//! Copy constructor
	Motor( const Motor& original );
     
public:

	//! Set Voltage
	plmxml_api::Result SetVoltage( double arg );

     //! Get Voltage
	double GetVoltage() const;

	//! Check if Voltage is set
	plmxml_api::logical HasVoltage() const;

	//! Unset Voltage
	plmxml_api::Result UnsetVoltage();

	//! Set DampingCoefficient
	plmxml_api::Result SetDampingCoefficient( double arg );

     //! Get DampingCoefficient
	double GetDampingCoefficient() const;

	//! Check if DampingCoefficient is set
	plmxml_api::logical HasDampingCoefficient() const;

	//! Unset DampingCoefficient
	plmxml_api::Result UnsetDampingCoefficient();

	//! Set Current
	plmxml_api::Result SetCurrent( double arg );

     //! Get Current
	double GetCurrent() const;

	//! Check if Current is set
	plmxml_api::logical HasCurrent() const;

	//! Unset Current
	plmxml_api::Result UnsetCurrent();

	//! Set Resistance
	plmxml_api::Result SetResistance( double arg );

     //! Get Resistance
	double GetResistance() const;

	//! Check if Resistance is set
	plmxml_api::logical HasResistance() const;

	//! Unset Resistance
	plmxml_api::Result UnsetResistance();

	//! Set Inductance
	plmxml_api::Result SetInductance( double arg );

     //! Get Inductance
	double GetInductance() const;

	//! Check if Inductance is set
	plmxml_api::logical HasInductance() const;

	//! Unset Inductance
	plmxml_api::Result UnsetInductance();

	//! Set InitialVelocity
	plmxml_api::Result SetInitialVelocity( double arg );

     //! Get InitialVelocity
	double GetInitialVelocity() const;

	//! Check if InitialVelocity is set
	plmxml_api::logical HasInitialVelocity() const;

	//! Unset InitialVelocity
	plmxml_api::Result UnsetInitialVelocity();

	//! Set BackEMFConstant
	plmxml_api::Result SetBackEMFConstant( double arg );

     //! Get BackEMFConstant
	double GetBackEMFConstant() const;

	//! Check if BackEMFConstant is set
	plmxml_api::logical HasBackEMFConstant() const;

	//! Unset BackEMFConstant
	plmxml_api::Result UnsetBackEMFConstant();

	//! Set Type
	plmxml_api::Result SetType( const eMotorEnum& arg );

	//! Get Type
	eMotorEnum GetType() const;

	//! Set Inertia
	plmxml_api::Result SetInertia( double arg );

     //! Get Inertia
	double GetInertia() const;

	//! Check if Inertia is set
	plmxml_api::logical HasInertia() const;

	//! Unset Inertia
	plmxml_api::Result UnsetInertia();

	//! Set ForceConstant
	plmxml_api::Result SetForceConstant( double arg );

     //! Get ForceConstant
	double GetForceConstant() const;

	//! Check if ForceConstant is set
	plmxml_api::logical HasForceConstant() const;

	//! Unset ForceConstant
	plmxml_api::Result UnsetForceConstant();
 
// <PLMXML_UserCode type="functionHeaderMotor" >
     // TODO: Add extra function headers within this block
// </PLMXML_UserCode>
};
extern PLMXML_CONSTRAINT60_API plmxml_api::plmxmlClass plmxmlClassMotor;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
