/////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2008 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
//
// This software and related documentation are proprietary to 
// Siemens Product Lifecycle Management Software Inc.
//
// PLM XML Code Generator v7.0.1.19355 18/04/2018 15:11:25
// 
// Schema:	PLMXMLShipSchema.xsd
// Data:	18/04/2018 15:11:21
// Version:	6.0
// Status:	unknown
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLMXML_SHIP60_H__
#define __PLMXML_SHIP60_H__

//////////////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(_WIN64)

#ifdef PLMXML_SHIP60_EXPORTS
#define PLMXML_SHIP60_API __declspec(dllexport)
#else
#define PLMXML_SHIP60_API __declspec(dllimport)
#endif
#else
#define PLMXML_SHIP60_API
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
//! eEdgeEnum class
/*!
Allowed Values:
\verbatim
  eEdgeEnumCutout
	"cutout"
  eEdgeEnumErectionSeam
	"erectionSeam"
  eEdgeEnumStrakingSeam
	"strakingSeam"
  eEdgeEnumScantlingSeam
	"scantlingSeam"
  eEdgeEnumPerimeter
	"perimeter"
  
\endverbatim
*/
class PLMXML_SHIP60_API eEdgeEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eEdgeEnum( const char* Type );
     
	//! Constructor
	eEdgeEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eEdgeEnum( );
     
	//! Destructor 
	virtual ~eEdgeEnum( );
     
	//! Assign from 'Type'
	const eEdgeEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eEdgeEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare EdgeEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eEdgeEnum& e1, const eEdgeEnum& e2 );
     
	//! Compare EdgeEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eEdgeEnum& e1, const eEdgeEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumEdgeEnum;
extern PLMXML_SHIP60_API eEdgeEnum eEdgeEnumUnset;
extern PLMXML_SHIP60_API eEdgeEnum eEdgeEnumCutout;
extern PLMXML_SHIP60_API eEdgeEnum eEdgeEnumErectionSeam;
extern PLMXML_SHIP60_API eEdgeEnum eEdgeEnumStrakingSeam;
extern PLMXML_SHIP60_API eEdgeEnum eEdgeEnumScantlingSeam;
extern PLMXML_SHIP60_API eEdgeEnum eEdgeEnumPerimeter;

////////////////////////////////////////////////////////////////////////////////////
//! eProfileEndcutConnectionEnum class
/*!
Allowed Values:
\verbatim
  eProfileEndcutConnectionEnumFlangeFree
	"flangeFree"
  eProfileEndcutConnectionEnumNone
	"none"
  eProfileEndcutConnectionEnumSniped
	"sniped"
  eProfileEndcutConnectionEnumConnected
	"connected"
  
\endverbatim
*/
class PLMXML_SHIP60_API eProfileEndcutConnectionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eProfileEndcutConnectionEnum( const char* Type );
     
	//! Constructor
	eProfileEndcutConnectionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eProfileEndcutConnectionEnum( );
     
	//! Destructor 
	virtual ~eProfileEndcutConnectionEnum( );
     
	//! Assign from 'Type'
	const eProfileEndcutConnectionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eProfileEndcutConnectionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ProfileEndcutConnectionEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eProfileEndcutConnectionEnum& e1, const eProfileEndcutConnectionEnum& e2 );
     
	//! Compare ProfileEndcutConnectionEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eProfileEndcutConnectionEnum& e1, const eProfileEndcutConnectionEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumProfileEndcutConnectionEnum;
extern PLMXML_SHIP60_API eProfileEndcutConnectionEnum eProfileEndcutConnectionEnumUnset;
extern PLMXML_SHIP60_API eProfileEndcutConnectionEnum eProfileEndcutConnectionEnumFlangeFree;
extern PLMXML_SHIP60_API eProfileEndcutConnectionEnum eProfileEndcutConnectionEnumNone;
extern PLMXML_SHIP60_API eProfileEndcutConnectionEnum eProfileEndcutConnectionEnumSniped;
extern PLMXML_SHIP60_API eProfileEndcutConnectionEnum eProfileEndcutConnectionEnumConnected;

////////////////////////////////////////////////////////////////////////////////////
//! eCompartmentFunctionEnum class
/*!
Allowed Values:
\verbatim
  eCompartmentFunctionEnumAccomodation
	"accomodation"
  eCompartmentFunctionEnumTank
	"tank"
  eCompartmentFunctionEnumMachinery
	"machinery"
  eCompartmentFunctionEnumCargo
	"cargo"
  
\endverbatim
*/
class PLMXML_SHIP60_API eCompartmentFunctionEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eCompartmentFunctionEnum( const char* Type );
     
	//! Constructor
	eCompartmentFunctionEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eCompartmentFunctionEnum( );
     
	//! Destructor 
	virtual ~eCompartmentFunctionEnum( );
     
	//! Assign from 'Type'
	const eCompartmentFunctionEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eCompartmentFunctionEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare CompartmentFunctionEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eCompartmentFunctionEnum& e1, const eCompartmentFunctionEnum& e2 );
     
	//! Compare CompartmentFunctionEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eCompartmentFunctionEnum& e1, const eCompartmentFunctionEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumCompartmentFunctionEnum;
extern PLMXML_SHIP60_API eCompartmentFunctionEnum eCompartmentFunctionEnumUnset;
extern PLMXML_SHIP60_API eCompartmentFunctionEnum eCompartmentFunctionEnumAccomodation;
extern PLMXML_SHIP60_API eCompartmentFunctionEnum eCompartmentFunctionEnumTank;
extern PLMXML_SHIP60_API eCompartmentFunctionEnum eCompartmentFunctionEnumMachinery;
extern PLMXML_SHIP60_API eCompartmentFunctionEnum eCompartmentFunctionEnumCargo;

////////////////////////////////////////////////////////////////////////////////////
//! eStructureObjectEnum class
/*!
Allowed Values:
\verbatim
  eStructureObjectEnumHull
	"hull"
  eStructureObjectEnumBracket
	"bracket"
  eStructureObjectEnumTransverseBulkhead
	"transverseBulkhead"
  eStructureObjectEnumLongtitudinalBulkhead
	"longtitudinalBulkhead"
  eStructureObjectEnumPillar
	"pillar"
  eStructureObjectEnumSuperstructure
	"superstructure"
  eStructureObjectEnumFrame
	"frame"
  eStructureObjectEnumDeck
	"deck"
  
\endverbatim
*/
class PLMXML_SHIP60_API eStructureObjectEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eStructureObjectEnum( const char* Type );
     
	//! Constructor
	eStructureObjectEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eStructureObjectEnum( );
     
	//! Destructor 
	virtual ~eStructureObjectEnum( );
     
	//! Assign from 'Type'
	const eStructureObjectEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eStructureObjectEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare StructureObjectEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eStructureObjectEnum& e1, const eStructureObjectEnum& e2 );
     
	//! Compare StructureObjectEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eStructureObjectEnum& e1, const eStructureObjectEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumStructureObjectEnum;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumUnset;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumHull;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumBracket;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumTransverseBulkhead;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumLongtitudinalBulkhead;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumPillar;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumSuperstructure;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumFrame;
extern PLMXML_SHIP60_API eStructureObjectEnum eStructureObjectEnumDeck;

////////////////////////////////////////////////////////////////////////////////////
//! eVesselEnum class
/*!
Allowed Values:
\verbatim
  eVesselEnumHighspeedcraftPassenger
	"highspeedcraftPassenger"
  eVesselEnumPilotBoat
	"pilotBoat"
  eVesselEnumIceBreaker
	"iceBreaker"
  eVesselEnumDredger
	"dredger"
  eVesselEnumBargePontoon
	"bargePontoon"
  eVesselEnumFloatingHotel
	"floatingHotel"
  eVesselEnumLandingPlatformHelicopter
	"landingPlatformHelicopter"
  eVesselEnumBargeForDeckLoading
	"bargeForDeckLoading"
  eVesselEnumCraneVessel
	"craneVessel"
  eVesselEnumLandingPlatformDock
	"landingPlatformDock"
  eVesselEnumPassengerVessel
	"passengerVessel"
  eVesselEnumOilTanker
	"oilTanker"
  eVesselEnumChemicalTanker
	"chemicalTanker"
  eVesselEnumTankerForRefrigeratedFruitJuice
	"tankerForRefrigeratedFruitJuice"
  eVesselEnumCorvette
	"corvette"
  eVesselEnumGasCarrier
	"gasCarrier"
  eVesselEnumLPGCarrier
	"lPGCarrier"
  eVesselEnumBulkCarrier
	"bulkCarrier"
  eVesselEnumReefer
	"reefer"
  eVesselEnumLNGCarrier
	"lNGCarrier"
  eVesselEnumPatrolForceVessel
	"patrolForceVessel"
  eVesselEnumFloatingDock
	"floatingDock"
  eVesselEnumTug
	"tug"
  eVesselEnumFrigate
	"frigate"
  eVesselEnumHighspeedcraftCargo
	"highspeedcraftCargo"
  eVesselEnumDrillingVessel
	"drillingVessel"
  eVesselEnumSternTrawler
	"sternTrawler"
  eVesselEnumDestroyer
	"destroyer"
  eVesselEnumCruiseLiner
	"cruiseLiner"
  eVesselEnumPipeLayingVessel
	"pipeLayingVessel"
  eVesselEnumGeneralCargoCarrier
	"generalCargoCarrier"
  eVesselEnumCarFerry
	"carFerry"
  eVesselEnumAuxiliaryOiler
	"auxiliaryOiler"
  eVesselEnumFleetAuxiliaryVessel
	"fleetAuxiliaryVessel"
  eVesselEnumOffshoreSupplyVessel
	"offshoreSupplyVessel"
  eVesselEnumWellStimulationVessel
	"wellStimulationVessel"
  eVesselEnumLiquefiedGasTanker
	"liquefiedGasTanker"
  eVesselEnumFireFighter
	"fireFighter"
  eVesselEnumHydrofoil
	"hydrofoil"
  eVesselEnumSubmarine
	"submarine"
  eVesselEnumChemicalTankerType1
	"chemicalTankerType1"
  eVesselEnumMineWarfareShip
	"mineWarfareShip"
  eVesselEnumDryCargoVessel
	"dryCargoVessel"
  eVesselEnumCarCarrier
	"carCarrier"
  eVesselEnumBarge
	"barge"
  eVesselEnumRoroVessel
	"roroVessel"
  eVesselEnumFPSO
	"FPSO"
  eVesselEnumRefrigeratedCargoCarryingShip
	"refrigeratedCargoCarryingShip"
  eVesselEnumOilStorageVessel
	"oilStorageVessel"
  eVesselEnumCargoShipCarryingPassengers
	"cargoShipCarryingPassengers"
  eVesselEnumCruiser
	"cruiser"
  eVesselEnumFPGO
	"FPGO"
  eVesselEnumOilProductionAndStorageVessel
	"oilProductionAndStorageVessel"
  eVesselEnumPusher
	"pusher"
  eVesselEnumSupplyVessel
	"supplyVessel"
  eVesselEnumFishingVessel
	"fishingVessel"
  eVesselEnumSealer
	"sealer"
  eVesselEnumServiceCraft
	"serviceCraft"
  eVesselEnumShuttleTanker
	"shuttleTanker"
  eVesselEnumOilProductionVessel
	"oilProductionVessel"
  eVesselEnumFerry
	"ferry"
  eVesselEnumAircraftCarrier
	"aircraftCarrier"
  eVesselEnumContainerCarrier
	"containerCarrier"
  eVesselEnumUserDefined
	"userDefined"
  eVesselEnumBargeForOil
	"bargeForOil"
  eVesselEnumBargeForLiquefiedGas
	"bargeForLiquefiedGas"
  eVesselEnumOreCarrier
	"oreCarrier"
  eVesselEnumProductTanker
	"productTanker"
  
\endverbatim
*/
class PLMXML_SHIP60_API eVesselEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eVesselEnum( const char* Type );
     
	//! Constructor
	eVesselEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eVesselEnum( );
     
	//! Destructor 
	virtual ~eVesselEnum( );
     
	//! Assign from 'Type'
	const eVesselEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eVesselEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare VesselEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eVesselEnum& e1, const eVesselEnum& e2 );
     
	//! Compare VesselEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eVesselEnum& e1, const eVesselEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumVesselEnum;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumUnset;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumHighspeedcraftPassenger;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumPilotBoat;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumIceBreaker;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumDredger;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumBargePontoon;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFloatingHotel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumLandingPlatformHelicopter;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumBargeForDeckLoading;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCraneVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumLandingPlatformDock;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumPassengerVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumOilTanker;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumChemicalTanker;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumTankerForRefrigeratedFruitJuice;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCorvette;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumGasCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumLPGCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumBulkCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumReefer;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumLNGCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumPatrolForceVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFloatingDock;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumTug;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFrigate;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumHighspeedcraftCargo;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumDrillingVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumSternTrawler;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumDestroyer;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCruiseLiner;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumPipeLayingVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumGeneralCargoCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCarFerry;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumAuxiliaryOiler;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFleetAuxiliaryVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumOffshoreSupplyVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumWellStimulationVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumLiquefiedGasTanker;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFireFighter;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumHydrofoil;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumSubmarine;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumChemicalTankerType1;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumMineWarfareShip;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumDryCargoVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCarCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumBarge;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumRoroVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFPSO;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumRefrigeratedCargoCarryingShip;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumOilStorageVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCargoShipCarryingPassengers;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumCruiser;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFPGO;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumOilProductionAndStorageVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumPusher;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumSupplyVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFishingVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumSealer;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumServiceCraft;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumShuttleTanker;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumOilProductionVessel;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumFerry;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumAircraftCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumContainerCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumUserDefined;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumBargeForOil;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumBargeForLiquefiedGas;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumOreCarrier;
extern PLMXML_SHIP60_API eVesselEnum eVesselEnumProductTanker;

////////////////////////////////////////////////////////////////////////////////////
//! eSocietyEnum class
/*!
Allowed Values:
\verbatim
  eSocietyEnumNkk
	"nkk"
  eSocietyEnumGl
	"gl"
  eSocietyEnumKr
	"kr"
  eSocietyEnumRs
	"rs"
  eSocietyEnumDnv
	"dnv"
  eSocietyEnumAbs
	"abs"
  eSocietyEnumCcs
	"ccs"
  eSocietyEnumBv
	"bv"
  eSocietyEnumIacs
	"iacs"
  eSocietyEnumLr
	"lr"
  eSocietyEnumRina
	"rina"
  eSocietyEnumOther
	"other"
  
\endverbatim
*/
class PLMXML_SHIP60_API eSocietyEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eSocietyEnum( const char* Type );
     
	//! Constructor
	eSocietyEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eSocietyEnum( );
     
	//! Destructor 
	virtual ~eSocietyEnum( );
     
	//! Assign from 'Type'
	const eSocietyEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eSocietyEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare SocietyEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eSocietyEnum& e1, const eSocietyEnum& e2 );
     
	//! Compare SocietyEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eSocietyEnum& e1, const eSocietyEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumSocietyEnum;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumUnset;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumNkk;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumGl;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumKr;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumRs;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumDnv;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumAbs;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumCcs;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumBv;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumIacs;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumLr;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumRina;
extern PLMXML_SHIP60_API eSocietyEnum eSocietyEnumOther;

////////////////////////////////////////////////////////////////////////////////////
//! eProfileEndcutLimitEnum class
/*!
Allowed Values:
\verbatim
  eProfileEndcutLimitEnumSquareCut
	"squareCut"
  eProfileEndcutLimitEnumNeatTrim
	"neatTrim"
  
\endverbatim
*/
class PLMXML_SHIP60_API eProfileEndcutLimitEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eProfileEndcutLimitEnum( const char* Type );
     
	//! Constructor
	eProfileEndcutLimitEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eProfileEndcutLimitEnum( );
     
	//! Destructor 
	virtual ~eProfileEndcutLimitEnum( );
     
	//! Assign from 'Type'
	const eProfileEndcutLimitEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eProfileEndcutLimitEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare ProfileEndcutLimitEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eProfileEndcutLimitEnum& e1, const eProfileEndcutLimitEnum& e2 );
     
	//! Compare ProfileEndcutLimitEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eProfileEndcutLimitEnum& e1, const eProfileEndcutLimitEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumProfileEndcutLimitEnum;
extern PLMXML_SHIP60_API eProfileEndcutLimitEnum eProfileEndcutLimitEnumUnset;
extern PLMXML_SHIP60_API eProfileEndcutLimitEnum eProfileEndcutLimitEnumSquareCut;
extern PLMXML_SHIP60_API eProfileEndcutLimitEnum eProfileEndcutLimitEnumNeatTrim;

////////////////////////////////////////////////////////////////////////////////////
//! eTightnessEnum class
/*!
Allowed Values:
\verbatim
  eTightnessEnumWatertight
	"watertight"
  eTightnessEnumAirtight
	"airtight"
  eTightnessEnumNontight
	"nontight"
  eTightnessEnumOiltight
	"oiltight"
  
\endverbatim
*/
class PLMXML_SHIP60_API eTightnessEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eTightnessEnum( const char* Type );
     
	//! Constructor
	eTightnessEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eTightnessEnum( );
     
	//! Destructor 
	virtual ~eTightnessEnum( );
     
	//! Assign from 'Type'
	const eTightnessEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eTightnessEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare TightnessEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eTightnessEnum& e1, const eTightnessEnum& e2 );
     
	//! Compare TightnessEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eTightnessEnum& e1, const eTightnessEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumTightnessEnum;
extern PLMXML_SHIP60_API eTightnessEnum eTightnessEnumUnset;
extern PLMXML_SHIP60_API eTightnessEnum eTightnessEnumWatertight;
extern PLMXML_SHIP60_API eTightnessEnum eTightnessEnumAirtight;
extern PLMXML_SHIP60_API eTightnessEnum eTightnessEnumNontight;
extern PLMXML_SHIP60_API eTightnessEnum eTightnessEnumOiltight;

////////////////////////////////////////////////////////////////////////////////////
//! eStiffenerTerminationEnum class
/*!
Allowed Values:
\verbatim
  eStiffenerTerminationEnumPlate
	"plate"
  eStiffenerTerminationEnumStiffenerEnd
	"stiffenerEnd"
  eStiffenerTerminationEnumTee
	"tee"
  eStiffenerTerminationEnumStiffenerStart
	"stiffenerStart"
  
\endverbatim
*/
class PLMXML_SHIP60_API eStiffenerTerminationEnum : public plmxml_api::EnumBase
{

public:

	//! Constructor
	eStiffenerTerminationEnum( const char* Type );
     
	//! Constructor
	eStiffenerTerminationEnum( const plmxml_api::String& Type );
     
	//! Default Constructor
	eStiffenerTerminationEnum( );
     
	//! Destructor 
	virtual ~eStiffenerTerminationEnum( );
     
	//! Assign from 'Type'
	const eStiffenerTerminationEnum& operator=( const plmxml_api::String& Type );
     
	//! Assign from 'Type'
	const eStiffenerTerminationEnum& operator=( const char* Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const plmxml_api::String& Type );

	//! Set this object equal to 'Type'. Returns FALSE if 'Type' does not match any allowable values.
	virtual plmxml_api::logical Set( const char* Type );

	//! Compare StiffenerTerminationEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator==( const eStiffenerTerminationEnum& e1, const eStiffenerTerminationEnum& e2 );
     
	//! Compare StiffenerTerminationEnum
	friend plmxml_api::logical PLMXML_SHIP60_API operator!=( const eStiffenerTerminationEnum& e1, const eStiffenerTerminationEnum& e2 );
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlFieldType plmxmlFieldEnumStiffenerTerminationEnum;
extern PLMXML_SHIP60_API eStiffenerTerminationEnum eStiffenerTerminationEnumUnset;
extern PLMXML_SHIP60_API eStiffenerTerminationEnum eStiffenerTerminationEnumPlate;
extern PLMXML_SHIP60_API eStiffenerTerminationEnum eStiffenerTerminationEnumStiffenerEnd;
extern PLMXML_SHIP60_API eStiffenerTerminationEnum eStiffenerTerminationEnumTee;
extern PLMXML_SHIP60_API eStiffenerTerminationEnum eStiffenerTerminationEnumStiffenerStart;

//! Forward class declarations
class ShipData;
class ShipStructure;
class ClassData;

////////////////////////////////////////////////////////////////////////////////////
//! Ship class
/*!
\verbatim

      Ship

      Sub-elements:

      RepresentationEntity: Inherited from ProductRevisionView. Represents the
                        format independent geometry for the plates, stiffeners,
                        edge reinforcements, hull form, superstructure,
                        reference surfaces et cetera.
      Representation:   Inherited from ProductRevisionView. Represents a model
                        in a particular format containing the geometry for the
                        plates, stiffeners, edge reinforcements, hull form,
                        superstructure, reference surfaces et cetera. May
                        consist of a union of CompoundRep sub-elements, each
                        representing a single piece of geometry.
      ShipData:         General information about the ship.
      ShipStructure:    Information about the structure of the ship.
      ClassData:        Information about the class of the ship.
      
\endverbatim
*/
class PLMXML_SHIP60_API Ship : public ProductRevisionView
{
public:
     
    //! Default constructor
    Ship( );
     
    //! Constructs a Ship with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Ship( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Ship();

private:

	//! Assignment operator
	Ship& operator=( const Ship& iSrc );

	//! Copy constructor
	Ship( const Ship& original );
     
public:

	//! Add ShipData child element to this Ship. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ShipData *AddShipData();
     
	//! Set ShipData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetShipData( ShipData *arg );
     
	//! Get ShipData child element of this Ship.
	ShipData *GetShipData() const;
     
	//! Detach and delete ShipData child element tree from this Ship.
	void DeleteShipData();

	//! Add ShipStructure child element to this Ship. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ShipStructure *AddShipStructure();
     
	//! Set ShipStructure child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetShipStructure( ShipStructure *arg );
     
	//! Get ShipStructure child element of this Ship.
	ShipStructure *GetShipStructure() const;
     
	//! Detach and delete ShipStructure child element tree from this Ship.
	void DeleteShipStructure();

	//! Add ClassData child element to this Ship. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ClassData *AddClassData();
     
	//! Set ClassData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetClassData( ClassData *arg );
     
	//! Get ClassData child element of this Ship.
	ClassData *GetClassData() const;
     
	//! Detach and delete ClassData child element tree from this Ship.
	void DeleteClassData();

     // <PLMXML_UserCode type="functionHeaderShip" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassShip;


//! Forward class declarations
class Identification;
class OwnerData;
class ShipyardData;
class Grid;
class MainDimensions;
class ReferenceGeometry;
class StockDB;

////////////////////////////////////////////////////////////////////////////////////
//! ShipData class
/*!
\verbatim

      Ship Data

      Sub-elements:

      Identification:   The identification of the ship.
      OwnerData:        Information about the owner of the ship.
      ShipyardData:     Information about the shipyard where the ship was built.
      Grid:             A grid of planes for the general arrangement of the
                        ship.
      MainDimensions:   The main dimensions of the ship.
      ReferenceGeometry: The key and reference geometry of the ship.
      StockDB:          The stock materials used for building the ship.
      
\endverbatim
*/
class PLMXML_SHIP60_API ShipData : public AttribOwner
{
public:
     
    //! Default constructor
    ShipData( );
     
    //! Constructs a ShipData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ShipData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ShipData();

private:

	//! Assignment operator
	ShipData& operator=( const ShipData& iSrc );

	//! Copy constructor
	ShipData( const ShipData& original );
     
public:

	//! Add Identification child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Identification *AddIdentification();
     
	//! Set Identification child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetIdentification( Identification *arg );
     
	//! Get Identification child element of this ShipData.
	Identification *GetIdentification() const;
     
	//! Detach and delete Identification child element tree from this ShipData.
	void DeleteIdentification();

	//! Add OwnerData child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	OwnerData *AddOwnerData();
     
	//! Set OwnerData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwnerData( OwnerData *arg );
     
	//! Get OwnerData child element of this ShipData.
	OwnerData *GetOwnerData() const;
     
	//! Detach and delete OwnerData child element tree from this ShipData.
	void DeleteOwnerData();

	//! Add ShipyardData child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ShipyardData *AddShipyardData();
     
	//! Set ShipyardData child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetShipyardData( ShipyardData *arg );
     
	//! Get ShipyardData child element of this ShipData.
	ShipyardData *GetShipyardData() const;
     
	//! Detach and delete ShipyardData child element tree from this ShipData.
	void DeleteShipyardData();

	//! Add Grid child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Grid *AddGrid();
     
	//! Set Grid child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetGrid( Grid *arg );
     
	//! Get Grid child element of this ShipData.
	Grid *GetGrid() const;
     
	//! Detach and delete Grid child element tree from this ShipData.
	void DeleteGrid();

	//! Add MainDimensions child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	MainDimensions *AddMainDimensions();
     
	//! Set MainDimensions child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetMainDimensions( MainDimensions *arg );
     
	//! Get MainDimensions child element of this ShipData.
	MainDimensions *GetMainDimensions() const;
     
	//! Detach and delete MainDimensions child element tree from this ShipData.
	void DeleteMainDimensions();

	//! Add ReferenceGeometry child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ReferenceGeometry *AddReferenceGeometry();
     
	//! Set ReferenceGeometry child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetReferenceGeometry( ReferenceGeometry *arg );
     
	//! Get ReferenceGeometry child element of this ShipData.
	ReferenceGeometry *GetReferenceGeometry() const;
     
	//! Detach and delete ReferenceGeometry child element tree from this ShipData.
	void DeleteReferenceGeometry();

	//! Add StockDB child element to this ShipData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	StockDB *AddStockDB();
     
	//! Set StockDB child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStockDB( StockDB *arg );
     
	//! Get StockDB child element of this ShipData.
	StockDB *GetStockDB() const;
     
	//! Detach and delete StockDB child element tree from this ShipData.
	void DeleteStockDB();

     // <PLMXML_UserCode type="functionHeaderShipData" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassShipData;


////////////////////////////////////////////////////////////////////////////////////
//! Identification class
/*!
\verbatim

      Identification

      Attributes:

      name:             Inherited from AttribOwner. The name of the
                        Identification.
      vessel:           The type of vessel.
      
\endverbatim
*/
class PLMXML_SHIP60_API Identification : public AttribOwner
{
public:
     
    //! Default constructor
    Identification( );
     
    //! Constructs a Identification with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Identification( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Identification();

private:

	//! Assignment operator
	Identification& operator=( const Identification& iSrc );

	//! Copy constructor
	Identification( const Identification& original );
     
public:

	//! Set Vessel
	plmxml_api::Result SetVessel( const eVesselEnum& arg );

	//! Get Vessel
	eVesselEnum GetVessel() const;

     // <PLMXML_UserCode type="functionHeaderIdentification" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassIdentification;


//! Forward class declarations
class Company;

////////////////////////////////////////////////////////////////////////////////////
//! OwnerData class
/*!
\verbatim

      Owner Data

      Sub-elements:

      OwningCompany:  The company that owns the ship.
      OperatingCompany: The company that operates or manages the ship.
      
\endverbatim
*/
class PLMXML_SHIP60_API OwnerData : public AttribOwner
{
public:
     
    //! Default constructor
    OwnerData( );
     
    //! Constructs a OwnerData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    OwnerData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~OwnerData();

private:

	//! Assignment operator
	OwnerData& operator=( const OwnerData& iSrc );

	//! Copy constructor
	OwnerData( const OwnerData& original );
     
public:

	//! Add OwningCompany child element to this OwnerData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Company *AddOwningCompany();
     
	//! Set OwningCompany child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOwningCompany( Company *arg );
     
	//! Get OwningCompany child element of this OwnerData.
	Company *GetOwningCompany() const;
     
	//! Detach and delete OwningCompany child element tree from this OwnerData.
	void DeleteOwningCompany();

	//! Add OperatingCompany child element to this OwnerData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Company *AddOperatingCompany();
     
	//! Set OperatingCompany child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetOperatingCompany( Company *arg );
     
	//! Get OperatingCompany child element of this OwnerData.
	Company *GetOperatingCompany() const;
     
	//! Detach and delete OperatingCompany child element tree from this OwnerData.
	void DeleteOperatingCompany();

     // <PLMXML_UserCode type="functionHeaderOwnerData" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassOwnerData;


////////////////////////////////////////////////////////////////////////////////////
//! Company class
/*!
\verbatim

      Company

      Attributes:

      name:             Inherited from Site. The name of the site.
      ownerRef:         Inherited from Site. References an existing Organisation
                        for the Company. The name attribute of the Organisation
                        represents the name of the Company.
      addressRef:       Inherited from Site. References an existing Address for
                        the Company.
      contactRef:       References an existing Person for the Company. The name
                        attribute of the Person represents the contact for the
                        Company.
      
\endverbatim
*/
class PLMXML_SHIP60_API Company : public Site
{
public:
     
    //! Default constructor
    Company( );
     
    //! Constructs a Company with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Company( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Company();

private:

	//! Assignment operator
	Company& operator=( const Company& iSrc );

	//! Copy constructor
	Company( const Company& original );
     
public:

	//! Get Contact URI as plmxml_api::String
	plmxml_api::String GetContactURI() const;

	//! Set Contact URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetContactURI( const plmxml_api::String& );
	
	//! Get the handle of Contact URI. Does not resolve the URI.
	plmxml_api::Result GetContactURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Contact URI. URI string is unchanged.
	plmxml_api::Result SetContactURI( const plmxml_api::Handle& );
	
	//! Resolve Contact URI and return an object (handle) it points to.
	plmxml_api::Result ResolveContactURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Contact URI. Clears URI string and handle.
	plmxml_api::Result DeleteContactURI();
	
	//! Check if Contact URI is set
	plmxml_api::logical HasContactURI( ) const;
	

     // <PLMXML_UserCode type="functionHeaderCompany" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassCompany;


////////////////////////////////////////////////////////////////////////////////////
//! ShipyardData class
/*!
\verbatim

      Shipyard Data

      Attributes:

      shipName:         The name of the ship.
      hullNumber:       The number of the hull of the ship.
      designDate:       The date that the ship was designed.
      buildDate:        The date that the ship was built.

      Sub-elements:

      DesignAuthority:  The company that approves the design of the ship.
      
\endverbatim
*/
class PLMXML_SHIP60_API ShipyardData : public AttribOwner
{
public:
     
    //! Default constructor
    ShipyardData( );
     
    //! Constructs a ShipyardData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ShipyardData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ShipyardData();

private:

	//! Assignment operator
	ShipyardData& operator=( const ShipyardData& iSrc );

	//! Copy constructor
	ShipyardData( const ShipyardData& original );
     
public:

	//! Get HullNumber of this ShipyardData
	plmxml_api::String GetHullNumber() const;

	//! Set HullNumber of this ShipyardData
	plmxml_api::Result SetHullNumber( const plmxml_api::String &s );
	
	//! Check if HullNumber is set
	plmxml_api::logical HasHullNumber( ) const;
	
	//! Unset HullNumber
	plmxml_api::Result UnsetHullNumber( );

	//! Get BuildDate of this ShipyardData
	plmxml_api::String GetBuildDate() const;

	//! Set BuildDate of this ShipyardData
	plmxml_api::Result SetBuildDate( const plmxml_api::String &s );
	
	//! Check if BuildDate is set
	plmxml_api::logical HasBuildDate( ) const;
	
	//! Unset BuildDate
	plmxml_api::Result UnsetBuildDate( );

	//! Get DesignDate of this ShipyardData
	plmxml_api::String GetDesignDate() const;

	//! Set DesignDate of this ShipyardData
	plmxml_api::Result SetDesignDate( const plmxml_api::String &s );
	
	//! Check if DesignDate is set
	plmxml_api::logical HasDesignDate( ) const;
	
	//! Unset DesignDate
	plmxml_api::Result UnsetDesignDate( );

	//! Get ShipName of this ShipyardData
	plmxml_api::String GetShipName() const;

	//! Set ShipName of this ShipyardData
	plmxml_api::Result SetShipName( const plmxml_api::String &s );
	
	//! Check if ShipName is set
	plmxml_api::logical HasShipName( ) const;
	
	//! Unset ShipName
	plmxml_api::Result UnsetShipName( );

	//! Add DesignAuthority child element to this ShipyardData. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Company *AddDesignAuthority();
     
	//! Set DesignAuthority child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetDesignAuthority( Company *arg );
     
	//! Get DesignAuthority child element of this ShipyardData.
	Company *GetDesignAuthority() const;
     
	//! Detach and delete DesignAuthority child element tree from this ShipyardData.
	void DeleteDesignAuthority();

     // <PLMXML_UserCode type="functionHeaderShipyardData" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassShipyardData;


////////////////////////////////////////////////////////////////////////////////////
//! Grid class
/*!
\verbatim

      Grid

      Sub-elements:

      Transverse:       Transverse planes of existing PlaneType complex type.
      Longitudinal:     Longitudinal planes of existing PlaneType complex type.
      Deck:             Deck planes of existing PlaneType complex type.
      
\endverbatim
*/
class PLMXML_SHIP60_API Grid : public AttribOwner
{
public:
     
    //! Default constructor
    Grid( );
     
    //! Constructs a Grid with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Grid( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Grid();

private:

	//! Assignment operator
	Grid& operator=( const Grid& iSrc );

	//! Copy constructor
	Grid( const Grid& original );
     
public:

	//! Add Transverse child element to this Grid. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddTransverse();
     
	//! Add 'arg' as Transverse child element to this Grid.
	plmxml_api::Result AddTransverse( Plane *arg );

	//! Detach and delete all Transverse child elements.
	void DeleteTransverses();
     
	//! Get number of Transverse child elements.
	int NumberOfTransverses() const;
     
	//! Get i'th Transverse child element.
	Plane *GetTransverse( int i ) const;
     
	//! Get all Transverse child element as an array
	void GetTransverses( plmxml_api::Array<Plane*> &array ) const;
	     
	//! Detach and delete i'th Transverse child element
	void DeleteTransverse( int i );
     
	//! Detach and delete 'arg' if it's one of the Transverse child elements
	void DeleteTransverse( Plane *arg );

	//! Add Longitudinal child element to this Grid. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddLongitudinal();
     
	//! Add 'arg' as Longitudinal child element to this Grid.
	plmxml_api::Result AddLongitudinal( Plane *arg );

	//! Detach and delete all Longitudinal child elements.
	void DeleteLongitudinals();
     
	//! Get number of Longitudinal child elements.
	int NumberOfLongitudinals() const;
     
	//! Get i'th Longitudinal child element.
	Plane *GetLongitudinal( int i ) const;
     
	//! Get all Longitudinal child element as an array
	void GetLongitudinals( plmxml_api::Array<Plane*> &array ) const;
	     
	//! Detach and delete i'th Longitudinal child element
	void DeleteLongitudinal( int i );
     
	//! Detach and delete 'arg' if it's one of the Longitudinal child elements
	void DeleteLongitudinal( Plane *arg );

	//! Add Deck child element to this Grid. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Plane *AddDeck();
     
	//! Add 'arg' as Deck child element to this Grid.
	plmxml_api::Result AddDeck( Plane *arg );

	//! Detach and delete all Deck child elements.
	void DeleteDecks();
     
	//! Get number of Deck child elements.
	int NumberOfDecks() const;
     
	//! Get i'th Deck child element.
	Plane *GetDeck( int i ) const;
     
	//! Get all Deck child element as an array
	void GetDecks( plmxml_api::Array<Plane*> &array ) const;
	     
	//! Detach and delete i'th Deck child element
	void DeleteDeck( int i );
     
	//! Detach and delete 'arg' if it's one of the Deck child elements
	void DeleteDeck( Plane *arg );

     // <PLMXML_UserCode type="functionHeaderGrid" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassGrid;


////////////////////////////////////////////////////////////////////////////////////
//! MainDimensions class
/*!
\verbatim

      The main dimensions of the ship in metres.

      Attributes:

      lengthOverall:    The overall length of the ship.
      mouldedBreadth:   The moulded breadth of the ship.
      mouldedDepth:     The moulded depth of the ship.
      designDraft:      The design draught of the ship.
      aftToFore:        Whether the Main Dimensions are measured aft-to-fore. If
                        true, they are measured aft-to-fore. If false, they are
                        measured fore-to-aft.
      baseLine:         The base line of the ship.
      waterLine:        The water line of the ship
      aftPerpendicular: The aft perpendicular distance of the ship.
      forwardPerpendicular: The forward perpendicular distance of the ship.
      
\endverbatim
*/
class PLMXML_SHIP60_API MainDimensions : public AttribOwner
{
public:
     
    //! Default constructor
    MainDimensions( );
     
    //! Constructs a MainDimensions with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    MainDimensions( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~MainDimensions();

private:

	//! Assignment operator
	MainDimensions& operator=( const MainDimensions& iSrc );

	//! Copy constructor
	MainDimensions( const MainDimensions& original );
     
public:

	//! Set LengthOverall
	plmxml_api::Result SetLengthOverall( double arg );

     //! Get LengthOverall
	double GetLengthOverall() const;

	//! Check if LengthOverall is set
	plmxml_api::logical HasLengthOverall() const;

	//! Unset LengthOverall
	plmxml_api::Result UnsetLengthOverall();

	//! Set AftToFore
	plmxml_api::Result SetAftToFore( plmxml_api::logical arg );

	//! Get AftToFore
	plmxml_api::logical GetAftToFore() const;

	//! Check if AftToFore is set
	plmxml_api::logical HasAftToFore() const;

	//! Unset AftToFore
	plmxml_api::Result UnsetAftToFore();

	//! Set WaterLine
	plmxml_api::Result SetWaterLine( double arg );

     //! Get WaterLine
	double GetWaterLine() const;

	//! Check if WaterLine is set
	plmxml_api::logical HasWaterLine() const;

	//! Unset WaterLine
	plmxml_api::Result UnsetWaterLine();

	//! Set DesignDraft
	plmxml_api::Result SetDesignDraft( double arg );

     //! Get DesignDraft
	double GetDesignDraft() const;

	//! Check if DesignDraft is set
	plmxml_api::logical HasDesignDraft() const;

	//! Unset DesignDraft
	plmxml_api::Result UnsetDesignDraft();

	//! Set BaseLine
	plmxml_api::Result SetBaseLine( double arg );

     //! Get BaseLine
	double GetBaseLine() const;

	//! Check if BaseLine is set
	plmxml_api::logical HasBaseLine() const;

	//! Unset BaseLine
	plmxml_api::Result UnsetBaseLine();

	//! Set MouldedDepth
	plmxml_api::Result SetMouldedDepth( double arg );

     //! Get MouldedDepth
	double GetMouldedDepth() const;

	//! Check if MouldedDepth is set
	plmxml_api::logical HasMouldedDepth() const;

	//! Unset MouldedDepth
	plmxml_api::Result UnsetMouldedDepth();

	//! Set AftPerpendicular
	plmxml_api::Result SetAftPerpendicular( double arg );

     //! Get AftPerpendicular
	double GetAftPerpendicular() const;

	//! Check if AftPerpendicular is set
	plmxml_api::logical HasAftPerpendicular() const;

	//! Unset AftPerpendicular
	plmxml_api::Result UnsetAftPerpendicular();

	//! Set MouldedBreadth
	plmxml_api::Result SetMouldedBreadth( double arg );

     //! Get MouldedBreadth
	double GetMouldedBreadth() const;

	//! Check if MouldedBreadth is set
	plmxml_api::logical HasMouldedBreadth() const;

	//! Unset MouldedBreadth
	plmxml_api::Result UnsetMouldedBreadth();

	//! Set ForwardPerpendicular
	plmxml_api::Result SetForwardPerpendicular( double arg );

     //! Get ForwardPerpendicular
	double GetForwardPerpendicular() const;

	//! Check if ForwardPerpendicular is set
	plmxml_api::logical HasForwardPerpendicular() const;

	//! Unset ForwardPerpendicular
	plmxml_api::Result UnsetForwardPerpendicular();

     // <PLMXML_UserCode type="functionHeaderMainDimensions" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassMainDimensions;


//! Forward class declarations
class HullForm;
class Superstructure;

////////////////////////////////////////////////////////////////////////////////////
//! ReferenceGeometry class
/*!
\verbatim

      Reference Geometry

      Sub-elements:

      HullForm:         The surfaces of the hull.
      Superstructure:   The surfaces of the superstructure.
      ReferenceSurface: Reference surfaces.
      
\endverbatim
*/
class PLMXML_SHIP60_API ReferenceGeometry : public AttribOwner
{
public:
     
    //! Default constructor
    ReferenceGeometry( );
     
    //! Constructs a ReferenceGeometry with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ReferenceGeometry( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ReferenceGeometry();

private:

	//! Assignment operator
	ReferenceGeometry& operator=( const ReferenceGeometry& iSrc );

	//! Copy constructor
	ReferenceGeometry( const ReferenceGeometry& original );
     
public:

	//! Add HullForm child element to this ReferenceGeometry. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	HullForm *AddHullForm();
     
	//! Set HullForm child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetHullForm( HullForm *arg );
     
	//! Get HullForm child element of this ReferenceGeometry.
	HullForm *GetHullForm() const;
     
	//! Detach and delete HullForm child element tree from this ReferenceGeometry.
	void DeleteHullForm();

	//! Add Superstructure child element to this ReferenceGeometry. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	Superstructure *AddSuperstructure();
     
	//! Set Superstructure child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSuperstructure( Superstructure *arg );
     
	//! Get Superstructure child element of this ReferenceGeometry.
	Superstructure *GetSuperstructure() const;
     
	//! Detach and delete Superstructure child element tree from this ReferenceGeometry.
	void DeleteSuperstructure();

	//! Add ReferenceSurface child element to this ReferenceGeometry. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddReferenceSurface();
     
	//! Add 'arg' as ReferenceSurface child element to this ReferenceGeometry.
	plmxml_api::Result AddReferenceSurface( GDEReference *arg );

	//! Detach and delete all ReferenceSurface child elements.
	void DeleteReferenceSurfaces();
     
	//! Get number of ReferenceSurface child elements.
	int NumberOfReferenceSurfaces() const;
     
	//! Get i'th ReferenceSurface child element.
	GDEReference *GetReferenceSurface( int i ) const;
     
	//! Get all ReferenceSurface child element as an array
	void GetReferenceSurfaces( plmxml_api::Array<GDEReference*> &array ) const;
	     
	//! Detach and delete i'th ReferenceSurface child element
	void DeleteReferenceSurface( int i );
     
	//! Detach and delete 'arg' if it's one of the ReferenceSurface child elements
	void DeleteReferenceSurface( GDEReference *arg );

     // <PLMXML_UserCode type="functionHeaderReferenceGeometry" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassReferenceGeometry;


////////////////////////////////////////////////////////////////////////////////////
//! HullForm class
/*!
\verbatim

      Hull Form

      A collection of trimmed surfaces that represent the hull.

      Sub-elements:

      SurfaceReference: References the surface geometry for the Hull Form.
      
\endverbatim
*/
class PLMXML_SHIP60_API HullForm : public AttribOwner
{
public:
     
    //! Default constructor
    HullForm( );
     
    //! Constructs a HullForm with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    HullForm( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~HullForm();

private:

	//! Assignment operator
	HullForm& operator=( const HullForm& iSrc );

	//! Copy constructor
	HullForm( const HullForm& original );
     
public:

	//! Add SurfaceReference child element to this HullForm. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddSurfaceReference();
     
	//! Add 'arg' as SurfaceReference child element to this HullForm.
	plmxml_api::Result AddSurfaceReference( GDEReference *arg );

	//! Detach and delete all SurfaceReference child elements.
	void DeleteSurfaceReferences();
     
	//! Get number of SurfaceReference child elements.
	int NumberOfSurfaceReferences() const;
     
	//! Get i'th SurfaceReference child element.
	GDEReference *GetSurfaceReference( int i ) const;
     
	//! Get all SurfaceReference child element as an array
	void GetSurfaceReferences( plmxml_api::Array<GDEReference*> &array ) const;
	     
	//! Detach and delete i'th SurfaceReference child element
	void DeleteSurfaceReference( int i );
     
	//! Detach and delete 'arg' if it's one of the SurfaceReference child elements
	void DeleteSurfaceReference( GDEReference *arg );

     // <PLMXML_UserCode type="functionHeaderHullForm" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassHullForm;


////////////////////////////////////////////////////////////////////////////////////
//! Superstructure class
/*!
\verbatim

      Superstructure

      A collection of trimmed surfaces that represent the superstructure.

      Sub-elements:

      SurfaceReference: References the surface geometry for the Superstructure.
      
\endverbatim
*/
class PLMXML_SHIP60_API Superstructure : public AttribOwner
{
public:
     
    //! Default constructor
    Superstructure( );
     
    //! Constructs a Superstructure with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Superstructure( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Superstructure();

private:

	//! Assignment operator
	Superstructure& operator=( const Superstructure& iSrc );

	//! Copy constructor
	Superstructure( const Superstructure& original );
     
public:

	//! Add SurfaceReference child element to this Superstructure. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddSurfaceReference();
     
	//! Add 'arg' as SurfaceReference child element to this Superstructure.
	plmxml_api::Result AddSurfaceReference( GDEReference *arg );

	//! Detach and delete all SurfaceReference child elements.
	void DeleteSurfaceReferences();
     
	//! Get number of SurfaceReference child elements.
	int NumberOfSurfaceReferences() const;
     
	//! Get i'th SurfaceReference child element.
	GDEReference *GetSurfaceReference( int i ) const;
     
	//! Get all SurfaceReference child element as an array
	void GetSurfaceReferences( plmxml_api::Array<GDEReference*> &array ) const;
	     
	//! Detach and delete i'th SurfaceReference child element
	void DeleteSurfaceReference( int i );
     
	//! Detach and delete 'arg' if it's one of the SurfaceReference child elements
	void DeleteSurfaceReference( GDEReference *arg );

     // <PLMXML_UserCode type="functionHeaderSuperstructure" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassSuperstructure;


//! Forward class declarations
class Stock;

////////////////////////////////////////////////////////////////////////////////////
//! StockDB class
/*!
\verbatim

      Stock DB

      Sub-elements:

      Stock:            The stock specifications.
      
\endverbatim
*/
class PLMXML_SHIP60_API StockDB : public AttribOwner
{
public:
     
    //! Default constructor
    StockDB( );
     
    //! Constructs a StockDB with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StockDB( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StockDB();

private:

	//! Assignment operator
	StockDB& operator=( const StockDB& iSrc );

	//! Copy constructor
	StockDB( const StockDB& original );
     
public:

	//! Add Stock child element to this StockDB. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Stock *AddStock();
     
	//! Add 'arg' as Stock child element to this StockDB.
	plmxml_api::Result AddStock( Stock *arg );

	//! Detach and delete all Stock child elements.
	void DeleteStocks();
     
	//! Get number of Stock child elements.
	int NumberOfStocks() const;
     
	//! Get i'th Stock child element.
	Stock *GetStock( int i ) const;
     
	//! Get all Stock child element as an array
	void GetStocks( plmxml_api::Array<Stock*> &array ) const;
	     
	//! Detach and delete i'th Stock child element
	void DeleteStock( int i );
     
	//! Detach and delete 'arg' if it's one of the Stock child elements
	void DeleteStock( Stock *arg );

     // <PLMXML_UserCode type="functionHeaderStockDB" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStockDB;


////////////////////////////////////////////////////////////////////////////////////
//! Stock class
/*!
\verbatim

      Stock

      Attributes:

      name:             Inherited from AttribOwner. The name of the Stock.
      stockType:        The type of the Stock.

      Sub-elements:

      Parameter:        The parameters that specify the Stock.
      
\endverbatim
*/
class PLMXML_SHIP60_API Stock : public AttribOwner
{
public:
     
    //! Default constructor
    Stock( );
     
    //! Constructs a Stock with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Stock( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Stock();

private:

	//! Assignment operator
	Stock& operator=( const Stock& iSrc );

	//! Copy constructor
	Stock( const Stock& original );
     
public:

	//! Get StockType of this Stock
	plmxml_api::String GetStockType() const;

	//! Set StockType of this Stock
	plmxml_api::Result SetStockType( const plmxml_api::String &s );
	
	//! Check if StockType is set
	plmxml_api::logical HasStockType( ) const;
	
	//! Unset StockType
	plmxml_api::Result UnsetStockType( );

	//! Add Parameter child element to this Stock. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	UserValue *AddParameter();
     
	//! Add 'arg' as Parameter child element to this Stock.
	plmxml_api::Result AddParameter( UserValue *arg );

	//! Detach and delete all Parameter child elements.
	void DeleteParameters();
     
	//! Get number of Parameter child elements.
	int NumberOfParameters() const;
     
	//! Get i'th Parameter child element.
	UserValue *GetParameter( int i ) const;
     
	//! Get all Parameter child element as an array
	void GetParameters( plmxml_api::Array<UserValue*> &array ) const;
	     
	//! Detach and delete i'th Parameter child element
	void DeleteParameter( int i );
     
	//! Detach and delete 'arg' if it's one of the Parameter child elements
	void DeleteParameter( UserValue *arg );

     // <PLMXML_UserCode type="functionHeaderStock" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStock;


//! Forward class declarations
class StructureObject;
class Compartment;

////////////////////////////////////////////////////////////////////////////////////
//! ShipStructure class
/*!
\verbatim

      Ship Structure

      Sub-elements:

      StructureObject:  The objects comprising the structure of the ship.
      Compartment:      The compartments within the ship.
      
\endverbatim
*/
class PLMXML_SHIP60_API ShipStructure : public AttribOwner
{
public:
     
    //! Default constructor
    ShipStructure( );
     
    //! Constructs a ShipStructure with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ShipStructure( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ShipStructure();

private:

	//! Assignment operator
	ShipStructure& operator=( const ShipStructure& iSrc );

	//! Copy constructor
	ShipStructure( const ShipStructure& original );
     
public:

	//! Add StructureObject child element to this ShipStructure. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StructureObject *AddStructureObject();
     
	//! Add 'arg' as StructureObject child element to this ShipStructure.
	plmxml_api::Result AddStructureObject( StructureObject *arg );

	//! Detach and delete all StructureObject child elements.
	void DeleteStructureObjects();
     
	//! Get number of StructureObject child elements.
	int NumberOfStructureObjects() const;
     
	//! Get i'th StructureObject child element.
	StructureObject *GetStructureObject( int i ) const;
     
	//! Get all StructureObject child element as an array
	void GetStructureObjects( plmxml_api::Array<StructureObject*> &array ) const;
	     
	//! Detach and delete i'th StructureObject child element
	void DeleteStructureObject( int i );
     
	//! Detach and delete 'arg' if it's one of the StructureObject child elements
	void DeleteStructureObject( StructureObject *arg );

	//! Add Compartment child element to this ShipStructure. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Compartment *AddCompartment();
     
	//! Add 'arg' as Compartment child element to this ShipStructure.
	plmxml_api::Result AddCompartment( Compartment *arg );

	//! Detach and delete all Compartment child elements.
	void DeleteCompartments();
     
	//! Get number of Compartment child elements.
	int NumberOfCompartments() const;
     
	//! Get i'th Compartment child element.
	Compartment *GetCompartment( int i ) const;
     
	//! Get all Compartment child element as an array
	void GetCompartments( plmxml_api::Array<Compartment*> &array ) const;
	     
	//! Detach and delete i'th Compartment child element
	void DeleteCompartment( int i );
     
	//! Detach and delete 'arg' if it's one of the Compartment child elements
	void DeleteCompartment( Compartment *arg );

     // <PLMXML_UserCode type="functionHeaderShipStructure" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassShipStructure;


//! Forward class declarations
class PlateSystem;

////////////////////////////////////////////////////////////////////////////////////
//! StructureObject class
/*!
\verbatim

      Structure Object

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Structure Object.
      structureObjectType: The type of the Structure Object.

      Sub-elements:

      PlateSystem:      The Plate Systems comprising the Structure Object.
      
\endverbatim
*/
class PLMXML_SHIP60_API StructureObject : public ProductRevisionView
{
public:
     
    //! Default constructor
    StructureObject( );
     
    //! Constructs a StructureObject with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StructureObject( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StructureObject();

private:

	//! Assignment operator
	StructureObject& operator=( const StructureObject& iSrc );

	//! Copy constructor
	StructureObject( const StructureObject& original );
     
public:

	//! Set StructureObjectType
	plmxml_api::Result SetStructureObjectType( const eStructureObjectEnum& arg );

	//! Get StructureObjectType
	eStructureObjectEnum GetStructureObjectType() const;

	//! Add PlateSystem child element to this StructureObject. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PlateSystem *AddPlateSystem();
     
	//! Add 'arg' as PlateSystem child element to this StructureObject.
	plmxml_api::Result AddPlateSystem( PlateSystem *arg );

	//! Detach and delete all PlateSystem child elements.
	void DeletePlateSystems();
     
	//! Get number of PlateSystem child elements.
	int NumberOfPlateSystems() const;
     
	//! Get i'th PlateSystem child element.
	PlateSystem *GetPlateSystem( int i ) const;
     
	//! Get all PlateSystem child element as an array
	void GetPlateSystems( plmxml_api::Array<PlateSystem*> &array ) const;
	     
	//! Detach and delete i'th PlateSystem child element
	void DeletePlateSystem( int i );
     
	//! Detach and delete 'arg' if it's one of the PlateSystem child elements
	void DeletePlateSystem( PlateSystem *arg );

     // <PLMXML_UserCode type="functionHeaderStructureObject" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStructureObject;


//! Forward class declarations
class PlateLoop;
class PlateEdge;
class StiffenerSystem;
class EdgeReinforcementSystem;
class PlateSubsystem;

////////////////////////////////////////////////////////////////////////////////////
//! PlateSystem class
/*!
\verbatim

      Plate System

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Plate System.

      Sub-elements:

      Loop:             The Loops of the Plate System.
      Edge:             The Edges of the Plate System.
      StiffenerSystem:  Any Stiffener Systems of the Plate System.
      EdgeReinforcementSystem: Any Edge Reinforcement Systems of the Plate
                        System.
      PlateSubsystem:   The Plate Subsystems comprising the Plate System.
      
\endverbatim
*/
class PLMXML_SHIP60_API PlateSystem : public ProductRevisionView
{
public:
     
    //! Default constructor
    PlateSystem( );
     
    //! Constructs a PlateSystem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlateSystem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlateSystem();

private:

	//! Assignment operator
	PlateSystem& operator=( const PlateSystem& iSrc );

	//! Copy constructor
	PlateSystem( const PlateSystem& original );
     
public:

	//! Add Loop child element to this PlateSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PlateLoop *AddLoop();
     
	//! Add 'arg' as Loop child element to this PlateSystem.
	plmxml_api::Result AddLoop( PlateLoop *arg );

	//! Detach and delete all Loop child elements.
	void DeleteLoops();
     
	//! Get number of Loop child elements.
	int NumberOfLoops() const;
     
	//! Get i'th Loop child element.
	PlateLoop *GetLoop( int i ) const;
     
	//! Get all Loop child element as an array
	void GetLoops( plmxml_api::Array<PlateLoop*> &array ) const;
	     
	//! Detach and delete i'th Loop child element
	void DeleteLoop( int i );
     
	//! Detach and delete 'arg' if it's one of the Loop child elements
	void DeleteLoop( PlateLoop *arg );

	//! Add Edge child element to this PlateSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PlateEdge *AddEdge();
     
	//! Add 'arg' as Edge child element to this PlateSystem.
	plmxml_api::Result AddEdge( PlateEdge *arg );

	//! Detach and delete all Edge child elements.
	void DeleteEdges();
     
	//! Get number of Edge child elements.
	int NumberOfEdges() const;
     
	//! Get i'th Edge child element.
	PlateEdge *GetEdge( int i ) const;
     
	//! Get all Edge child element as an array
	void GetEdges( plmxml_api::Array<PlateEdge*> &array ) const;
	     
	//! Detach and delete i'th Edge child element
	void DeleteEdge( int i );
     
	//! Detach and delete 'arg' if it's one of the Edge child elements
	void DeleteEdge( PlateEdge *arg );

	//! Add StiffenerSystem child element to this PlateSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StiffenerSystem *AddStiffenerSystem();
     
	//! Add 'arg' as StiffenerSystem child element to this PlateSystem.
	plmxml_api::Result AddStiffenerSystem( StiffenerSystem *arg );

	//! Detach and delete all StiffenerSystem child elements.
	void DeleteStiffenerSystems();
     
	//! Get number of StiffenerSystem child elements.
	int NumberOfStiffenerSystems() const;
     
	//! Get i'th StiffenerSystem child element.
	StiffenerSystem *GetStiffenerSystem( int i ) const;
     
	//! Get all StiffenerSystem child element as an array
	void GetStiffenerSystems( plmxml_api::Array<StiffenerSystem*> &array ) const;
	     
	//! Detach and delete i'th StiffenerSystem child element
	void DeleteStiffenerSystem( int i );
     
	//! Detach and delete 'arg' if it's one of the StiffenerSystem child elements
	void DeleteStiffenerSystem( StiffenerSystem *arg );

	//! Add EdgeReinforcementSystem child element to this PlateSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	EdgeReinforcementSystem *AddEdgeReinforcementSystem();
     
	//! Add 'arg' as EdgeReinforcementSystem child element to this PlateSystem.
	plmxml_api::Result AddEdgeReinforcementSystem( EdgeReinforcementSystem *arg );

	//! Detach and delete all EdgeReinforcementSystem child elements.
	void DeleteEdgeReinforcementSystems();
     
	//! Get number of EdgeReinforcementSystem child elements.
	int NumberOfEdgeReinforcementSystems() const;
     
	//! Get i'th EdgeReinforcementSystem child element.
	EdgeReinforcementSystem *GetEdgeReinforcementSystem( int i ) const;
     
	//! Get all EdgeReinforcementSystem child element as an array
	void GetEdgeReinforcementSystems( plmxml_api::Array<EdgeReinforcementSystem*> &array ) const;
	     
	//! Detach and delete i'th EdgeReinforcementSystem child element
	void DeleteEdgeReinforcementSystem( int i );
     
	//! Detach and delete 'arg' if it's one of the EdgeReinforcementSystem child elements
	void DeleteEdgeReinforcementSystem( EdgeReinforcementSystem *arg );

	//! Add PlateSubsystem child element to this PlateSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PlateSubsystem *AddPlateSubsystem();
     
	//! Add 'arg' as PlateSubsystem child element to this PlateSystem.
	plmxml_api::Result AddPlateSubsystem( PlateSubsystem *arg );

	//! Detach and delete all PlateSubsystem child elements.
	void DeletePlateSubsystems();
     
	//! Get number of PlateSubsystem child elements.
	int NumberOfPlateSubsystems() const;
     
	//! Get i'th PlateSubsystem child element.
	PlateSubsystem *GetPlateSubsystem( int i ) const;
     
	//! Get all PlateSubsystem child element as an array
	void GetPlateSubsystems( plmxml_api::Array<PlateSubsystem*> &array ) const;
	     
	//! Detach and delete i'th PlateSubsystem child element
	void DeletePlateSubsystem( int i );
     
	//! Detach and delete 'arg' if it's one of the PlateSubsystem child elements
	void DeletePlateSubsystem( PlateSubsystem *arg );

     // <PLMXML_UserCode type="functionHeaderPlateSystem" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassPlateSystem;


////////////////////////////////////////////////////////////////////////////////////
//! PlateLoop class
/*!
\verbatim

      Loop

      Attributes:

      edgeRefs:         References the Edges of the Loop.
      
\endverbatim
*/
class PLMXML_SHIP60_API PlateLoop : public AttribOwner
{
public:
     
    //! Default constructor
    PlateLoop( );
     
    //! Constructs a PlateLoop with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlateLoop( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlateLoop();

private:

	//! Assignment operator
	PlateLoop& operator=( const PlateLoop& iSrc );

	//! Copy constructor
	PlateLoop( const PlateLoop& original );
     
public:

	//! Get number of URIs in Edge
	int NumberOfEdgeURIs() const;

	//! Get i'th URI in Edge
	plmxml_api::String GetEdgeURI( int i ) const;

	//! Add a URI to Edge array. Call ResolveEdgeURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddEdgeURI( const plmxml_api::String& u );

	//! Set i'th URI in Edge array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetEdgeURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of Edge URI. Does not resolve the URI.
	plmxml_api::Result GetEdgeURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to Edge array.
	plmxml_api::Result AddEdgeURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in Edge array to point to 'handle'.
	plmxml_api::Result SetEdgeURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in Edge points to.
	plmxml_api::Result ResolveEdgeURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from Edge array.
	plmxml_api::Result DeleteEdgeURI( int i );

	//! Remove all URIs from Edge array.
	plmxml_api::Result DeleteEdgeURIs( );
	
	//! Check if Edge is set
	plmxml_api::logical HasEdgeURIs( ) const;

     // <PLMXML_UserCode type="functionHeaderPlateLoop" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassPlateLoop;


////////////////////////////////////////////////////////////////////////////////////
//! PlateEdge class
/*!
\verbatim

      Edge

      edgeType:         The type of the Edge.
      adjacentPlateRefs: References the Plates or sets of Plates adjacent to the
                        Edge.
      reinforcementRef: References the Edge Reinforcement or set of Edge
                        Reinforcements that reinforce the Edge.

      Sub-elements:

      CurveReference:   References the RepresentationEntity under the Plate
                        System representing the format independent curve
                        geometry for the Edge.
      
\endverbatim
*/
class PLMXML_SHIP60_API PlateEdge : public AttribOwner
{
public:
     
    //! Default constructor
    PlateEdge( );
     
    //! Constructs a PlateEdge with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlateEdge( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlateEdge();

private:

	//! Assignment operator
	PlateEdge& operator=( const PlateEdge& iSrc );

	//! Copy constructor
	PlateEdge( const PlateEdge& original );
     
public:

	//! Set EdgeType
	plmxml_api::Result SetEdgeType( const eEdgeEnum& arg );

	//! Get EdgeType
	eEdgeEnum GetEdgeType() const;

	//! Get number of URIs in AdjacentPlate
	int NumberOfAdjacentPlateURIs() const;

	//! Get i'th URI in AdjacentPlate
	plmxml_api::String GetAdjacentPlateURI( int i ) const;

	//! Add a URI to AdjacentPlate array. Call ResolveAdjacentPlateURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddAdjacentPlateURI( const plmxml_api::String& u );

	//! Set i'th URI in AdjacentPlate array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetAdjacentPlateURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of AdjacentPlate URI. Does not resolve the URI.
	plmxml_api::Result GetAdjacentPlateURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to AdjacentPlate array.
	plmxml_api::Result AddAdjacentPlateURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in AdjacentPlate array to point to 'handle'.
	plmxml_api::Result SetAdjacentPlateURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in AdjacentPlate points to.
	plmxml_api::Result ResolveAdjacentPlateURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from AdjacentPlate array.
	plmxml_api::Result DeleteAdjacentPlateURI( int i );

	//! Remove all URIs from AdjacentPlate array.
	plmxml_api::Result DeleteAdjacentPlateURIs( );
	
	//! Check if AdjacentPlate is set
	plmxml_api::logical HasAdjacentPlateURIs( ) const;

	//! Get Reinforcement URI as plmxml_api::String
	plmxml_api::String GetReinforcementURI() const;

	//! Set Reinforcement URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetReinforcementURI( const plmxml_api::String& );
	
	//! Get the handle of Reinforcement URI. Does not resolve the URI.
	plmxml_api::Result GetReinforcementURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Reinforcement URI. URI string is unchanged.
	plmxml_api::Result SetReinforcementURI( const plmxml_api::Handle& );
	
	//! Resolve Reinforcement URI and return an object (handle) it points to.
	plmxml_api::Result ResolveReinforcementURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Reinforcement URI. Clears URI string and handle.
	plmxml_api::Result DeleteReinforcementURI();
	
	//! Check if Reinforcement URI is set
	plmxml_api::logical HasReinforcementURI( ) const;
	

	//! Add CurveReference child element to this PlateEdge. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddCurveReference();
     
	//! Set CurveReference child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCurveReference( GDEReference *arg );
     
	//! Get CurveReference child element of this PlateEdge.
	GDEReference *GetCurveReference() const;
     
	//! Detach and delete CurveReference child element tree from this PlateEdge.
	void DeleteCurveReference();

     // <PLMXML_UserCode type="functionHeaderPlateEdge" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassPlateEdge;


//! Forward class declarations
class StiffenerSubsystem;

////////////////////////////////////////////////////////////////////////////////////
//! StiffenerSystem class
/*!
\verbatim

      Stiffener System

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Stiffener System.

      Sub-elements:

      StiffenerSubsystem: The Stiffener Subsystems comprising the Stiffener
                        System.
      
\endverbatim
*/
class PLMXML_SHIP60_API StiffenerSystem : public ProductRevisionView
{
public:
     
    //! Default constructor
    StiffenerSystem( );
     
    //! Constructs a StiffenerSystem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StiffenerSystem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StiffenerSystem();

private:

	//! Assignment operator
	StiffenerSystem& operator=( const StiffenerSystem& iSrc );

	//! Copy constructor
	StiffenerSystem( const StiffenerSystem& original );
     
public:

	//! Add StiffenerSubsystem child element to this StiffenerSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	StiffenerSubsystem *AddStiffenerSubsystem();
     
	//! Add 'arg' as StiffenerSubsystem child element to this StiffenerSystem.
	plmxml_api::Result AddStiffenerSubsystem( StiffenerSubsystem *arg );

	//! Detach and delete all StiffenerSubsystem child elements.
	void DeleteStiffenerSubsystems();
     
	//! Get number of StiffenerSubsystem child elements.
	int NumberOfStiffenerSubsystems() const;
     
	//! Get i'th StiffenerSubsystem child element.
	StiffenerSubsystem *GetStiffenerSubsystem( int i ) const;
     
	//! Get all StiffenerSubsystem child element as an array
	void GetStiffenerSubsystems( plmxml_api::Array<StiffenerSubsystem*> &array ) const;
	     
	//! Detach and delete i'th StiffenerSubsystem child element
	void DeleteStiffenerSubsystem( int i );
     
	//! Detach and delete 'arg' if it's one of the StiffenerSubsystem child elements
	void DeleteStiffenerSubsystem( StiffenerSubsystem *arg );

     // <PLMXML_UserCode type="functionHeaderStiffenerSystem" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStiffenerSystem;


//! Forward class declarations
class Stiffener;

////////////////////////////////////////////////////////////////////////////////////
//! StiffenerSubsystem class
/*!
\verbatim

      Stiffener Subsystem

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Stiffener Subsystem.
      propertyRefs:     Inherited from ProductRevisionView. Can be used to
                        reference a MaterialSpecification representing the
                        material and a MaterialThickness representing the
                        thickness.
      instanceRefs:     Inherited from ProductRevisionView. Can reference
                        ProductInstances of widely re-used parts such as
                        brackets.
      stockRef:         References the stock specification. Used in preference
                        to propertyRefs.
      mouldedSide:      Whether the Stiffener Subsystem lies on the moulded or
                        the reverse side of the Plate System. If true, it lies
                        on the moulded side. If false, it lies on the reverse
                        side.
      startToEnd:       If true, the Stiffener Subsystem is defined from start
                        to end. If false, it is defined from end to start.

      Sub-elements:

      Stiffener:        The Stiffeners comprising the Stiffener Subsystem.
      MountingAngle:    The direction of the web of the Stiffener Subsystem.
      
\endverbatim
*/
class PLMXML_SHIP60_API StiffenerSubsystem : public ProductRevisionView
{
public:
     
    //! Default constructor
    StiffenerSubsystem( );
     
    //! Constructs a StiffenerSubsystem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StiffenerSubsystem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StiffenerSubsystem();

private:

	//! Assignment operator
	StiffenerSubsystem& operator=( const StiffenerSubsystem& iSrc );

	//! Copy constructor
	StiffenerSubsystem( const StiffenerSubsystem& original );
     
public:

	//! Get Stock URI as plmxml_api::String
	plmxml_api::String GetStockURI() const;

	//! Set Stock URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStockURI( const plmxml_api::String& );
	
	//! Get the handle of Stock URI. Does not resolve the URI.
	plmxml_api::Result GetStockURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Stock URI. URI string is unchanged.
	plmxml_api::Result SetStockURI( const plmxml_api::Handle& );
	
	//! Resolve Stock URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStockURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Stock URI. Clears URI string and handle.
	plmxml_api::Result DeleteStockURI();
	
	//! Check if Stock URI is set
	plmxml_api::logical HasStockURI( ) const;
	

	//! Set StartToEnd
	plmxml_api::Result SetStartToEnd( plmxml_api::logical arg );

	//! Get StartToEnd
	plmxml_api::logical GetStartToEnd() const;

	//! Check if StartToEnd is set
	plmxml_api::logical HasStartToEnd() const;

	//! Unset StartToEnd
	plmxml_api::Result UnsetStartToEnd();

	//! Set MouldedSide
	plmxml_api::Result SetMouldedSide( plmxml_api::logical arg );

	//! Get MouldedSide
	plmxml_api::logical GetMouldedSide() const;

	//! Check if MouldedSide is set
	plmxml_api::logical HasMouldedSide() const;

	//! Unset MouldedSide
	plmxml_api::Result UnsetMouldedSide();

	//! Add Stiffener child element to this StiffenerSubsystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Stiffener *AddStiffener();
     
	//! Add 'arg' as Stiffener child element to this StiffenerSubsystem.
	plmxml_api::Result AddStiffener( Stiffener *arg );

	//! Detach and delete all Stiffener child elements.
	void DeleteStiffeners();
     
	//! Get number of Stiffener child elements.
	int NumberOfStiffeners() const;
     
	//! Get i'th Stiffener child element.
	Stiffener *GetStiffener( int i ) const;
     
	//! Get all Stiffener child element as an array
	void GetStiffeners( plmxml_api::Array<Stiffener*> &array ) const;
	     
	//! Detach and delete i'th Stiffener child element
	void DeleteStiffener( int i );
     
	//! Detach and delete 'arg' if it's one of the Stiffener child elements
	void DeleteStiffener( Stiffener *arg );

	//! Add MountingAngle child element to this StiffenerSubsystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	VectorField *AddMountingAngle();
     
	//! Add 'arg' as MountingAngle child element to this StiffenerSubsystem.
	plmxml_api::Result AddMountingAngle( VectorField *arg );

	//! Detach and delete all MountingAngle child elements.
	void DeleteMountingAngles();
     
	//! Get number of MountingAngle child elements.
	int NumberOfMountingAngles() const;
     
	//! Get i'th MountingAngle child element.
	VectorField *GetMountingAngle( int i ) const;
     
	//! Get all MountingAngle child element as an array
	void GetMountingAngles( plmxml_api::Array<VectorField*> &array ) const;
	     
	//! Detach and delete i'th MountingAngle child element
	void DeleteMountingAngle( int i );
     
	//! Detach and delete 'arg' if it's one of the MountingAngle child elements
	void DeleteMountingAngle( VectorField *arg );

     // <PLMXML_UserCode type="functionHeaderStiffenerSubsystem" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStiffenerSubsystem;


//! Forward class declarations
class StiffenerTermination;

////////////////////////////////////////////////////////////////////////////////////
//! Stiffener class
/*!
\verbatim

      Stiffener

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Stiffener.

      Sub-elements:

      Start:            The type of termination at the start of the Stiffener.
      End:              The type of termination at the end of the Stiffener.
      CurveReference:   References the RepresentationEntity under the Ship
                        representing the format independent landing curve
                        geometry for the Stiffener.
      
\endverbatim
*/
class PLMXML_SHIP60_API Stiffener : public ProductRevisionView
{
public:
     
    //! Default constructor
    Stiffener( );
     
    //! Constructs a Stiffener with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Stiffener( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Stiffener();

private:

	//! Assignment operator
	Stiffener& operator=( const Stiffener& iSrc );

	//! Copy constructor
	Stiffener( const Stiffener& original );
     
public:

	//! Add Start child element to this Stiffener. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	StiffenerTermination *AddStart();
     
	//! Set Start child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetStart( StiffenerTermination *arg );
     
	//! Get Start child element of this Stiffener.
	StiffenerTermination *GetStart() const;
     
	//! Detach and delete Start child element tree from this Stiffener.
	void DeleteStart();

	//! Add End child element to this Stiffener. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	StiffenerTermination *AddEnd();
     
	//! Set End child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetEnd( StiffenerTermination *arg );
     
	//! Get End child element of this Stiffener.
	StiffenerTermination *GetEnd() const;
     
	//! Detach and delete End child element tree from this Stiffener.
	void DeleteEnd();

	//! Add CurveReference child element to this Stiffener. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddCurveReference();
     
	//! Set CurveReference child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCurveReference( GDEReference *arg );
     
	//! Get CurveReference child element of this Stiffener.
	GDEReference *GetCurveReference() const;
     
	//! Detach and delete CurveReference child element tree from this Stiffener.
	void DeleteCurveReference();

     // <PLMXML_UserCode type="functionHeaderStiffener" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStiffener;


//! Forward class declarations
class ProfileEndcut;

////////////////////////////////////////////////////////////////////////////////////
//! StiffenerTermination class
/*!
\verbatim

      Stiffener Termination

      Attributes:

      name:             Inherited from AttribOwner. The name of the Stiffener
                        Termination.
      terminationType:  The type of the Stiffener Termination.
      adjacentRef:      References the object that the Stiffener Termination
                        lies adjacent to.

      Sub-elements:

      Endcut:           The type of endcut of the Stiffener Termination.
      
\endverbatim
*/
class PLMXML_SHIP60_API StiffenerTermination : public AttribOwner
{
public:
     
    //! Default constructor
    StiffenerTermination( );
     
    //! Constructs a StiffenerTermination with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    StiffenerTermination( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~StiffenerTermination();

private:

	//! Assignment operator
	StiffenerTermination& operator=( const StiffenerTermination& iSrc );

	//! Copy constructor
	StiffenerTermination( const StiffenerTermination& original );
     
public:

	//! Set TerminationType
	plmxml_api::Result SetTerminationType( const eStiffenerTerminationEnum& arg );

	//! Get TerminationType
	eStiffenerTerminationEnum GetTerminationType() const;

	//! Get Adjacent URI as plmxml_api::String
	plmxml_api::String GetAdjacentURI() const;

	//! Set Adjacent URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetAdjacentURI( const plmxml_api::String& );
	
	//! Get the handle of Adjacent URI. Does not resolve the URI.
	plmxml_api::Result GetAdjacentURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Adjacent URI. URI string is unchanged.
	plmxml_api::Result SetAdjacentURI( const plmxml_api::Handle& );
	
	//! Resolve Adjacent URI and return an object (handle) it points to.
	plmxml_api::Result ResolveAdjacentURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Adjacent URI. Clears URI string and handle.
	plmxml_api::Result DeleteAdjacentURI();
	
	//! Check if Adjacent URI is set
	plmxml_api::logical HasAdjacentURI( ) const;
	

	//! Add Endcut child element to this StiffenerTermination. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ProfileEndcut *AddEndcut();
     
	//! Set Endcut child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetEndcut( ProfileEndcut *arg );
     
	//! Get Endcut child element of this StiffenerTermination.
	ProfileEndcut *GetEndcut() const;
     
	//! Detach and delete Endcut child element tree from this StiffenerTermination.
	void DeleteEndcut();

     // <PLMXML_UserCode type="functionHeaderStiffenerTermination" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassStiffenerTermination;


////////////////////////////////////////////////////////////////////////////////////
//! ProfileEndcut class
/*!
\verbatim

      Profile Endcut

      Attributes:

      limitType:        The type of limit of the Profile Endcut.
      connectionType:   The type of connection of the Profile Endcut.
      flangeSection:    The flange section of the Profile Endcut.
      webSection:       The web section of the Profile Endcut.
      toeSection:       The toe section of the Profile Endcut.
      
\endverbatim
*/
class PLMXML_SHIP60_API ProfileEndcut : public AttribOwner
{
public:
     
    //! Default constructor
    ProfileEndcut( );
     
    //! Constructs a ProfileEndcut with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProfileEndcut( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProfileEndcut();

private:

	//! Assignment operator
	ProfileEndcut& operator=( const ProfileEndcut& iSrc );

	//! Copy constructor
	ProfileEndcut( const ProfileEndcut& original );
     
public:

	//! Get ToeSection of this ProfileEndcut
	plmxml_api::String GetToeSection() const;

	//! Set ToeSection of this ProfileEndcut
	plmxml_api::Result SetToeSection( const plmxml_api::String &s );
	
	//! Check if ToeSection is set
	plmxml_api::logical HasToeSection( ) const;
	
	//! Unset ToeSection
	plmxml_api::Result UnsetToeSection( );

	//! Set LimitType
	plmxml_api::Result SetLimitType( const eProfileEndcutLimitEnum& arg );

	//! Get LimitType
	eProfileEndcutLimitEnum GetLimitType() const;

	//! Set ConnectionType
	plmxml_api::Result SetConnectionType( const eProfileEndcutConnectionEnum& arg );

	//! Get ConnectionType
	eProfileEndcutConnectionEnum GetConnectionType() const;

	//! Get FlangeSection of this ProfileEndcut
	plmxml_api::String GetFlangeSection() const;

	//! Set FlangeSection of this ProfileEndcut
	plmxml_api::Result SetFlangeSection( const plmxml_api::String &s );
	
	//! Check if FlangeSection is set
	plmxml_api::logical HasFlangeSection( ) const;
	
	//! Unset FlangeSection
	plmxml_api::Result UnsetFlangeSection( );

	//! Get WebSection of this ProfileEndcut
	plmxml_api::String GetWebSection() const;

	//! Set WebSection of this ProfileEndcut
	plmxml_api::Result SetWebSection( const plmxml_api::String &s );
	
	//! Check if WebSection is set
	plmxml_api::logical HasWebSection( ) const;
	
	//! Unset WebSection
	plmxml_api::Result UnsetWebSection( );

     // <PLMXML_UserCode type="functionHeaderProfileEndcut" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassProfileEndcut;


//! Forward class declarations
class EdgeReinforcementSubsystem;

////////////////////////////////////////////////////////////////////////////////////
//! EdgeReinforcementSystem class
/*!
\verbatim

      Edge Reinforcement System

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the Edge
                        Reinforcement System.

      Sub-elements:

      EdgeReinforcementSubsystem: The Edge Reinforcement Subsystems comprising
                        the Edge Reinforcement System.
      
\endverbatim
*/
class PLMXML_SHIP60_API EdgeReinforcementSystem : public ProductRevisionView
{
public:
     
    //! Default constructor
    EdgeReinforcementSystem( );
     
    //! Constructs a EdgeReinforcementSystem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    EdgeReinforcementSystem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~EdgeReinforcementSystem();

private:

	//! Assignment operator
	EdgeReinforcementSystem& operator=( const EdgeReinforcementSystem& iSrc );

	//! Copy constructor
	EdgeReinforcementSystem( const EdgeReinforcementSystem& original );
     
public:

	//! Add EdgeReinforcementSubsystem child element to this EdgeReinforcementSystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	EdgeReinforcementSubsystem *AddEdgeReinforcementSubsystem();
     
	//! Add 'arg' as EdgeReinforcementSubsystem child element to this EdgeReinforcementSystem.
	plmxml_api::Result AddEdgeReinforcementSubsystem( EdgeReinforcementSubsystem *arg );

	//! Detach and delete all EdgeReinforcementSubsystem child elements.
	void DeleteEdgeReinforcementSubsystems();
     
	//! Get number of EdgeReinforcementSubsystem child elements.
	int NumberOfEdgeReinforcementSubsystems() const;
     
	//! Get i'th EdgeReinforcementSubsystem child element.
	EdgeReinforcementSubsystem *GetEdgeReinforcementSubsystem( int i ) const;
     
	//! Get all EdgeReinforcementSubsystem child element as an array
	void GetEdgeReinforcementSubsystems( plmxml_api::Array<EdgeReinforcementSubsystem*> &array ) const;
	     
	//! Detach and delete i'th EdgeReinforcementSubsystem child element
	void DeleteEdgeReinforcementSubsystem( int i );
     
	//! Detach and delete 'arg' if it's one of the EdgeReinforcementSubsystem child elements
	void DeleteEdgeReinforcementSubsystem( EdgeReinforcementSubsystem *arg );

     // <PLMXML_UserCode type="functionHeaderEdgeReinforcementSystem" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassEdgeReinforcementSystem;


//! Forward class declarations
class EdgeReinforcement;

////////////////////////////////////////////////////////////////////////////////////
//! EdgeReinforcementSubsystem class
/*!
\verbatim

      Edge Reinforcement Subsystem

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the Edge
                        Reinforcement Subsystem.
      instanceRefs:     Inherited from ProductRevisionView. Can reference
                        ProductInstances of widely re-used parts such as
                        brackets.
      propertyRefs:     Inherited from ProductRevisionView. Can be used to
                        reference a MaterialSpecification representing the
                        material and a MaterialThickness representing the
                        thickness.
      stockRef:         References the stock specification. Used in preference
                        to propertyRefs.

      Sub-elements:

      EdgeReinforcement: The Edge Reinforcements comprising the Edge
                        Reinforcement Subsystem.
      MountingAngle:    The direction of the web of the Edge Reinforcement
                        Subsystem.
      
\endverbatim
*/
class PLMXML_SHIP60_API EdgeReinforcementSubsystem : public ProductRevisionView
{
public:
     
    //! Default constructor
    EdgeReinforcementSubsystem( );
     
    //! Constructs a EdgeReinforcementSubsystem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    EdgeReinforcementSubsystem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~EdgeReinforcementSubsystem();

private:

	//! Assignment operator
	EdgeReinforcementSubsystem& operator=( const EdgeReinforcementSubsystem& iSrc );

	//! Copy constructor
	EdgeReinforcementSubsystem( const EdgeReinforcementSubsystem& original );
     
public:

	//! Get Stock URI as plmxml_api::String
	plmxml_api::String GetStockURI() const;

	//! Set Stock URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStockURI( const plmxml_api::String& );
	
	//! Get the handle of Stock URI. Does not resolve the URI.
	plmxml_api::Result GetStockURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Stock URI. URI string is unchanged.
	plmxml_api::Result SetStockURI( const plmxml_api::Handle& );
	
	//! Resolve Stock URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStockURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Stock URI. Clears URI string and handle.
	plmxml_api::Result DeleteStockURI();
	
	//! Check if Stock URI is set
	plmxml_api::logical HasStockURI( ) const;
	

	//! Add EdgeReinforcement child element to this EdgeReinforcementSubsystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	EdgeReinforcement *AddEdgeReinforcement();
     
	//! Add 'arg' as EdgeReinforcement child element to this EdgeReinforcementSubsystem.
	plmxml_api::Result AddEdgeReinforcement( EdgeReinforcement *arg );

	//! Detach and delete all EdgeReinforcement child elements.
	void DeleteEdgeReinforcements();
     
	//! Get number of EdgeReinforcement child elements.
	int NumberOfEdgeReinforcements() const;
     
	//! Get i'th EdgeReinforcement child element.
	EdgeReinforcement *GetEdgeReinforcement( int i ) const;
     
	//! Get all EdgeReinforcement child element as an array
	void GetEdgeReinforcements( plmxml_api::Array<EdgeReinforcement*> &array ) const;
	     
	//! Detach and delete i'th EdgeReinforcement child element
	void DeleteEdgeReinforcement( int i );
     
	//! Detach and delete 'arg' if it's one of the EdgeReinforcement child elements
	void DeleteEdgeReinforcement( EdgeReinforcement *arg );

	//! Add MountingAngle child element to this EdgeReinforcementSubsystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	VectorField *AddMountingAngle();
     
	//! Add 'arg' as MountingAngle child element to this EdgeReinforcementSubsystem.
	plmxml_api::Result AddMountingAngle( VectorField *arg );

	//! Detach and delete all MountingAngle child elements.
	void DeleteMountingAngles();
     
	//! Get number of MountingAngle child elements.
	int NumberOfMountingAngles() const;
     
	//! Get i'th MountingAngle child element.
	VectorField *GetMountingAngle( int i ) const;
     
	//! Get all MountingAngle child element as an array
	void GetMountingAngles( plmxml_api::Array<VectorField*> &array ) const;
	     
	//! Detach and delete i'th MountingAngle child element
	void DeleteMountingAngle( int i );
     
	//! Detach and delete 'arg' if it's one of the MountingAngle child elements
	void DeleteMountingAngle( VectorField *arg );

     // <PLMXML_UserCode type="functionHeaderEdgeReinforcementSubsystem" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassEdgeReinforcementSubsystem;


////////////////////////////////////////////////////////////////////////////////////
//! EdgeReinforcement class
/*!
\verbatim

      Edge Reinforcement

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the Edge
                        Reinforcement.

      Sub-elements:

      CurveReference:   References the RepresentationEntity under the Ship
                        representing the format independent landing curve
                        geometry for the Edge Reinforcement.
      
\endverbatim
*/
class PLMXML_SHIP60_API EdgeReinforcement : public ProductRevisionView
{
public:
     
    //! Default constructor
    EdgeReinforcement( );
     
    //! Constructs a EdgeReinforcement with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    EdgeReinforcement( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~EdgeReinforcement();

private:

	//! Assignment operator
	EdgeReinforcement& operator=( const EdgeReinforcement& iSrc );

	//! Copy constructor
	EdgeReinforcement( const EdgeReinforcement& original );
     
public:

	//! Add CurveReference child element to this EdgeReinforcement. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddCurveReference();
     
	//! Set CurveReference child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetCurveReference( GDEReference *arg );
     
	//! Get CurveReference child element of this EdgeReinforcement.
	GDEReference *GetCurveReference() const;
     
	//! Detach and delete CurveReference child element tree from this EdgeReinforcement.
	void DeleteCurveReference();

     // <PLMXML_UserCode type="functionHeaderEdgeReinforcement" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassEdgeReinforcement;


//! Forward class declarations
class ProfileCutout;
class Plate;

////////////////////////////////////////////////////////////////////////////////////
//! PlateSubsystem class
/*!
\verbatim

      Plate Subsystem

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Plate Subsystem.
      propertyRefs:     Inherited from ProductRevisionView. Can be used to
                        reference a MaterialSpecification representing the
                        material and a MaterialThickness representing the
                        thickness.
      instanceRefs:     Inherited from ProductRevisionView. Can reference
                        ProductInstances of widely re-used parts such as
                        brackets.
      mouldedSide:      Whether the surface normal indicates the moulded side of
                        the Plate Subsystem. If true, it indicates the moulded
                        side. If false, it indicates the reverse side.
      tightness:        The tightness of the Plate Subsystem.
      stockRef:         References the stock specification. Used in preference
                        to propertyRefs.

      Sub-elements:

      ProfileCutout:    Any Profile Cutouts of the PlateSubsystem.
      Plate:            The Plates comprising the Plate Subsystem.
      
\endverbatim
*/
class PLMXML_SHIP60_API PlateSubsystem : public ProductRevisionView
{
public:
     
    //! Default constructor
    PlateSubsystem( );
     
    //! Constructs a PlateSubsystem with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    PlateSubsystem( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~PlateSubsystem();

private:

	//! Assignment operator
	PlateSubsystem& operator=( const PlateSubsystem& iSrc );

	//! Copy constructor
	PlateSubsystem( const PlateSubsystem& original );
     
public:

	//! Get Stock URI as plmxml_api::String
	plmxml_api::String GetStockURI() const;

	//! Set Stock URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStockURI( const plmxml_api::String& );
	
	//! Get the handle of Stock URI. Does not resolve the URI.
	plmxml_api::Result GetStockURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of Stock URI. URI string is unchanged.
	plmxml_api::Result SetStockURI( const plmxml_api::Handle& );
	
	//! Resolve Stock URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStockURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset Stock URI. Clears URI string and handle.
	plmxml_api::Result DeleteStockURI();
	
	//! Check if Stock URI is set
	plmxml_api::logical HasStockURI( ) const;
	

	//! Set Tightness
	plmxml_api::Result SetTightness( const eTightnessEnum& arg );

	//! Get Tightness
	eTightnessEnum GetTightness() const;

	//! Set MouldedSide
	plmxml_api::Result SetMouldedSide( plmxml_api::logical arg );

	//! Get MouldedSide
	plmxml_api::logical GetMouldedSide() const;

	//! Check if MouldedSide is set
	plmxml_api::logical HasMouldedSide() const;

	//! Unset MouldedSide
	plmxml_api::Result UnsetMouldedSide();

	//! Add ProfileCutout child element to this PlateSubsystem. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	ProfileCutout *AddProfileCutout();
     
	//! Set ProfileCutout child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetProfileCutout( ProfileCutout *arg );
     
	//! Get ProfileCutout child element of this PlateSubsystem.
	ProfileCutout *GetProfileCutout() const;
     
	//! Detach and delete ProfileCutout child element tree from this PlateSubsystem.
	void DeleteProfileCutout();

	//! Add Plate child element to this PlateSubsystem. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	Plate *AddPlate();
     
	//! Add 'arg' as Plate child element to this PlateSubsystem.
	plmxml_api::Result AddPlate( Plate *arg );

	//! Detach and delete all Plate child elements.
	void DeletePlates();
     
	//! Get number of Plate child elements.
	int NumberOfPlates() const;
     
	//! Get i'th Plate child element.
	Plate *GetPlate( int i ) const;
     
	//! Get all Plate child element as an array
	void GetPlates( plmxml_api::Array<Plate*> &array ) const;
	     
	//! Detach and delete i'th Plate child element
	void DeletePlate( int i );
     
	//! Detach and delete 'arg' if it's one of the Plate child elements
	void DeletePlate( Plate *arg );

     // <PLMXML_UserCode type="functionHeaderPlateSubsystem" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassPlateSubsystem;


//! Forward class declarations
class AdditionalCutoutHardware;

////////////////////////////////////////////////////////////////////////////////////
//! ProfileCutout class
/*!
\verbatim

      Profile Cutout

      Attributes:

      name:             Inherited from AttribOwner. The name of the Profile
                        Cutout.
      profileCutoutType: The type of Profile Cutout.
      stiffenerSubsystemRef: References the Stiffener Subsystem.

      Sub-elements:

      AdditionalCutoutHardware: Any Additional Cutout Harware of the Profile Cutout.
      
\endverbatim
*/
class PLMXML_SHIP60_API ProfileCutout : public AttribOwner
{
public:
     
    //! Default constructor
    ProfileCutout( );
     
    //! Constructs a ProfileCutout with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ProfileCutout( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ProfileCutout();

private:

	//! Assignment operator
	ProfileCutout& operator=( const ProfileCutout& iSrc );

	//! Copy constructor
	ProfileCutout( const ProfileCutout& original );
     
public:

	//! Get StiffenerSubsystem URI as plmxml_api::String
	plmxml_api::String GetStiffenerSubsystemURI() const;

	//! Set StiffenerSubsystem URI using plmxml_api::String. The handle is unchanged.
	plmxml_api::Result SetStiffenerSubsystemURI( const plmxml_api::String& );
	
	//! Get the handle of StiffenerSubsystem URI. Does not resolve the URI.
	plmxml_api::Result GetStiffenerSubsystemURI( plmxml_api::Handle& ) const;
	
	//! Set the handle of StiffenerSubsystem URI. URI string is unchanged.
	plmxml_api::Result SetStiffenerSubsystemURI( const plmxml_api::Handle& );
	
	//! Resolve StiffenerSubsystem URI and return an object (handle) it points to.
	plmxml_api::Result ResolveStiffenerSubsystemURI( plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );
	
	//! Reset StiffenerSubsystem URI. Clears URI string and handle.
	plmxml_api::Result DeleteStiffenerSubsystemURI();
	
	//! Check if StiffenerSubsystem URI is set
	plmxml_api::logical HasStiffenerSubsystemURI( ) const;
	

	//! Get ProfileCutoutType of this ProfileCutout
	plmxml_api::String GetProfileCutoutType() const;

	//! Set ProfileCutoutType of this ProfileCutout
	plmxml_api::Result SetProfileCutoutType( const plmxml_api::String &s );
	
	//! Check if ProfileCutoutType is set
	plmxml_api::logical HasProfileCutoutType( ) const;
	
	//! Unset ProfileCutoutType
	plmxml_api::Result UnsetProfileCutoutType( );

	//! Add AdditionalCutoutHardware child element to this ProfileCutout. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	AdditionalCutoutHardware *AddAdditionalCutoutHardware();
     
	//! Set AdditionalCutoutHardware child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetAdditionalCutoutHardware( AdditionalCutoutHardware *arg );
     
	//! Get AdditionalCutoutHardware child element of this ProfileCutout.
	AdditionalCutoutHardware *GetAdditionalCutoutHardware() const;
     
	//! Detach and delete AdditionalCutoutHardware child element tree from this ProfileCutout.
	void DeleteAdditionalCutoutHardware();

     // <PLMXML_UserCode type="functionHeaderProfileCutout" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassProfileCutout;


////////////////////////////////////////////////////////////////////////////////////
//! AdditionalCutoutHardware class
/*!
\verbatim

      Additional Cutout Hardware

      Attributes:

      name:             Inherited from AttribOwner. The name of the Additional
                        Cutout Hardware.
      additionalCutoutHardwareType: The type of Additional Cutout Hardware.
      
\endverbatim
*/
class PLMXML_SHIP60_API AdditionalCutoutHardware : public AttribOwner
{
public:
     
    //! Default constructor
    AdditionalCutoutHardware( );
     
    //! Constructs a AdditionalCutoutHardware with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    AdditionalCutoutHardware( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~AdditionalCutoutHardware();

private:

	//! Assignment operator
	AdditionalCutoutHardware& operator=( const AdditionalCutoutHardware& iSrc );

	//! Copy constructor
	AdditionalCutoutHardware( const AdditionalCutoutHardware& original );
     
public:

	//! Get AdditionalCutoutHardwareType of this AdditionalCutoutHardware
	plmxml_api::String GetAdditionalCutoutHardwareType() const;

	//! Set AdditionalCutoutHardwareType of this AdditionalCutoutHardware
	plmxml_api::Result SetAdditionalCutoutHardwareType( const plmxml_api::String &s );
	
	//! Check if AdditionalCutoutHardwareType is set
	plmxml_api::logical HasAdditionalCutoutHardwareType( ) const;
	
	//! Unset AdditionalCutoutHardwareType
	plmxml_api::Result UnsetAdditionalCutoutHardwareType( );

     // <PLMXML_UserCode type="functionHeaderAdditionalCutoutHardware" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassAdditionalCutoutHardware;


////////////////////////////////////////////////////////////////////////////////////
//! Plate class
/*!
\verbatim

      Plate

      Attributes:

      name:             Inherited from ProductRevisionView. The name of the
                        Plate.

      Sub-elements:

      Loop:             The Loops of the Plate.
      SurfaceReference: References the RepresentationEntity under the Ship
                        representing the format independent surface geometry for
                        the Plate.
      
\endverbatim
*/
class PLMXML_SHIP60_API Plate : public ProductRevisionView
{
public:
     
    //! Default constructor
    Plate( );
     
    //! Constructs a Plate with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Plate( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Plate();

private:

	//! Assignment operator
	Plate& operator=( const Plate& iSrc );

	//! Copy constructor
	Plate( const Plate& original );
     
public:

	//! Add Loop child element to this Plate. A pointer to added element is returned.
	/*!
		Returns NULL if such element already exists.
	*/
	PlateLoop *AddLoop();
     
	//! Add 'arg' as Loop child element to this Plate.
	plmxml_api::Result AddLoop( PlateLoop *arg );

	//! Detach and delete all Loop child elements.
	void DeleteLoops();
     
	//! Get number of Loop child elements.
	int NumberOfLoops() const;
     
	//! Get i'th Loop child element.
	PlateLoop *GetLoop( int i ) const;
     
	//! Get all Loop child element as an array
	void GetLoops( plmxml_api::Array<PlateLoop*> &array ) const;
	     
	//! Detach and delete i'th Loop child element
	void DeleteLoop( int i );
     
	//! Detach and delete 'arg' if it's one of the Loop child elements
	void DeleteLoop( PlateLoop *arg );

	//! Add SurfaceReference child element to this Plate. A pointer to added element is returned. 
	/*!
		Returns NULL if such element already exists.
	*/
	GDEReference *AddSurfaceReference();
     
	//! Set SurfaceReference child element to 'arg'. 'arg' will be managed by the PLMXML toolkit.
	plmxml_api::Result SetSurfaceReference( GDEReference *arg );
     
	//! Get SurfaceReference child element of this Plate.
	GDEReference *GetSurfaceReference() const;
     
	//! Detach and delete SurfaceReference child element tree from this Plate.
	void DeleteSurfaceReference();

     // <PLMXML_UserCode type="functionHeaderPlate" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassPlate;


////////////////////////////////////////////////////////////////////////////////////
//! Compartment class
/*!
\verbatim

      Compartment

      Attributes:

      name:             Inherited from AttribOwner. The name of the Compartment.
      function:         The function of the Compartment.
      plateSubsystemRefs: A list of references to the PlateSubsystem elements
                        contained in the Compartment.
      
\endverbatim
*/
class PLMXML_SHIP60_API Compartment : public AttribOwner
{
public:
     
    //! Default constructor
    Compartment( );
     
    //! Constructs a Compartment with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    Compartment( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~Compartment();

private:

	//! Assignment operator
	Compartment& operator=( const Compartment& iSrc );

	//! Copy constructor
	Compartment( const Compartment& original );
     
public:

	//! Get number of URIs in PlateSubsystem
	int NumberOfPlateSubsystemURIs() const;

	//! Get i'th URI in PlateSubsystem
	plmxml_api::String GetPlateSubsystemURI( int i ) const;

	//! Add a URI to PlateSubsystem array. Call ResolvePlateSubsystemURI to obtain the handle pointed to by 'u'.
	plmxml_api::Result AddPlateSubsystemURI( const plmxml_api::String& u );

	//! Set i'th URI in PlateSubsystem array to 'u'. The array must be big enough for 'i' to be a valid index.
	plmxml_api::Result SetPlateSubsystemURI( int i, const plmxml_api::String& u );

	//! Get the i'th handle of PlateSubsystem URI. Does not resolve the URI.
	plmxml_api::Result GetPlateSubsystemURI( int i, plmxml_api::Handle& ) const;
     
	//! Add a URI pointing to 'handle' to PlateSubsystem array.
	plmxml_api::Result AddPlateSubsystemURI( const plmxml_api::Handle& handle );

	//! Set i'th URI in PlateSubsystem array to point to 'handle'.
	plmxml_api::Result SetPlateSubsystemURI( int i, const plmxml_api::Handle& handle );
     
	//! Obtain the handle i'th URI in PlateSubsystem points to.
	plmxml_api::Result ResolvePlateSubsystemURI( int i, plmxml_api::Handle&, plmxml_api::Configuration* config = NULL );

	//! Remove i'th URI from PlateSubsystem array.
	plmxml_api::Result DeletePlateSubsystemURI( int i );

	//! Remove all URIs from PlateSubsystem array.
	plmxml_api::Result DeletePlateSubsystemURIs( );
	
	//! Check if PlateSubsystem is set
	plmxml_api::logical HasPlateSubsystemURIs( ) const;

	//! Set Function
	plmxml_api::Result SetFunction( const eCompartmentFunctionEnum& arg );

	//! Get Function
	eCompartmentFunctionEnum GetFunction() const;

     // <PLMXML_UserCode type="functionHeaderCompartment" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassCompartment;


////////////////////////////////////////////////////////////////////////////////////
//! ClassData class
/*!
\verbatim

      Class Data

      Attributes:

      society:          The classification society.
      
\endverbatim
*/
class PLMXML_SHIP60_API ClassData : public AttribOwner
{
public:
     
    //! Default constructor
    ClassData( );
     
    //! Constructs a ClassData with the specified parent
    /*!
		If the parent of this object cannot be set a plmxml_api::Exception
		is thrown.
    */
    ClassData( plmxml_api::Object* parent );
         
    //! Destructor
    virtual ~ClassData();

private:

	//! Assignment operator
	ClassData& operator=( const ClassData& iSrc );

	//! Copy constructor
	ClassData( const ClassData& original );
     
public:

	//! Set Society
	plmxml_api::Result SetSociety( const eSocietyEnum& arg );

	//! Get Society
	eSocietyEnum GetSociety() const;

     // <PLMXML_UserCode type="functionHeaderClassData" >
     // TODO: Add extra function headers within this block
     // </PLMXML_UserCode>
};
extern PLMXML_SHIP60_API plmxml_api::plmxmlClass plmxmlClassClassData;


/////////////////////////////////////////////////////////////////////////

PLMXML_END_NAMESPACE

//////////////////////////////////////////////////////////////////////

#endif
