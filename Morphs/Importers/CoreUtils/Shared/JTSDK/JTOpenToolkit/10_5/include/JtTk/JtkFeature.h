////////////////////////////////////////////////////////////////////////////////
// Copyright 2015 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_FEATURE_H
#define JTK_FEATURE_H

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkString.h>
#include <JtTk/JtkTriStripSet.h>

//forward declarations
class JtkPMISection;
class JtkPMIReference;

class JtkThreadImpl;
class JtkHoleElementImpl;
class JtkHolePositionImpl;
class JtkFeatureImpl;

///////%{
//
// Class          : JtkThread
//
// Description    : Descriptive information pertaining to a thread
//                  A JtkThread requires that extent, and pitch be set along with a combination of
//                  [type and designate diameter] or [2 out of height, inner diameter, external diameter].
//                  If the extent is set to JtkFINITE then the length must also be set.
//
// Enums          : JtkThreadExtentType:
//                   JtkFINITE -- of specific length
//                   JtkTO_EXTENT -- extent of thread is that of the owning entity
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkRefCounted > JtkThread
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkThread : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkThread )

public:
   enum JtkThreadExtentType
   {
      JtkUNSET = 0,
      JtkFINITE,
      JtkTO_EXTENT
   };

   int setType( const JtkString& );
   int getType( JtkString& ) const;

   int setExtent( JtkThreadExtentType );
   int getExtent( JtkThreadExtentType& ) const;

   int setLength( double );
   int getLength( double& ) const;

   int setOffset( double );
   int getOffset( double& ) const;

   int setNominalDiameter( double );
   int getNominalDiameter( double& ) const;

   int setInternalDiameter( double );
   int getInternalDiameter( double& ) const;

   int setExternalDiameter( double );
   int getExternalDiameter( double& ) const;

   int setDesignateDiameter( const JtkString& );
   int getDesignateDiameter( JtkString& ) const;

   int setEffectiveLength( double );
   int getEffectiveLength( double& ) const;

   int setHeight( double );
   int getHeight( double& ) const;

   int setTaperAngle( double );
   int getTaperAngle( double& ) const;

   int setPitch( double );
   int getPitch( double& ) const;

   int setLeftHanded( int );
   int getLeftHanded( int& ) const;

   int setMethod( const JtkString& );
   int getMethod( JtkString& ) const;

   int setStarts( int );
   int getStarts( int& ) const;

   int setAngle( double );
   int getAngle( double& ) const;

   int setTapDrillDiameter( double );
   int getTapDrillDiameter( double& ) const;

   int setShaftDiameter( double );
   int getShaftDiameter( double& ) const;

   int setMinorDiameter( double );
   int getMinorDiameter( double& ) const;

   int setMajorDiameter( double );
   int getMajorDiameter( double& ) const;

   friend class JtkHoleElementImpl;
   friend class JtkThreadedFeatureImpl;
private:
   JtkThreadImpl*   _impl;

   JtkThread( );
   virtual ~JtkThread( );
};


///////%{
//
// Class          : JtkHoleElement
//
// Description    : Base class for JtkHoleComponent,JtkCounterBore and JtkCounterSink
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkRefCounted > JtkHoleElement
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHoleElement : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkHoleElement )

   friend class JtkHoleFeatureImpl;

   int numFaces( ) const;
   int addFace( int FaceId, const JtkString& Path = JtkString( ) );
   int getFace( int Index, int& FaceId ) const;
   int getFace( int Index, int& FaceId, JtkString& Path ) const;

protected:
   JtkHoleElementImpl*    _impl;

   JtkHoleElement( int );
   virtual ~JtkHoleElement( );
};

///////%{
//
// Class          : JtkCounterSink
//
// Description    : Descriptive information about the Countersink 
//                  of a JtkHoleFeature.
//                  The Countersink requires either a face to be specified,
//                  or all of diameter,length and angle to be set.
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkHoleElement > JtkCounterSink
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCounterSink : public JtkHoleElement
{
   JTK_OBJECT_HEADER( JtkCounterSink )

public:
   int setDiameter( double );
   int getDiameter( double& ) const;

   int setLength( double );
   int getLength( double& ) const;

   int setAngle( double );
   int getAngle( double& ) const;

   friend class JtkHoleFeatureImpl;
protected:
   JtkCounterSink( );
   virtual ~JtkCounterSink( );
};

///////%{
//
// Class          : JtkCounterBore
//
// Description    : Descriptive information about the CounterBore of a 
//                  JtkHoleFeature.
//                  The CounterBore requires either a face to be specified,
//                  or both diameter and length to be set.
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkHoleElement > JtkCounterBore
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCounterBore : public JtkHoleElement
{
   JTK_OBJECT_HEADER( JtkCounterBore )

public:

   int addThread( JtkThread*& );
   int getThread( JtkThread*& ) const;

   int setDiameter( double );
   int getDiameter( double& ) const;

   int setLength( double );
   int getLength( double& ) const;

   friend class JtkHoleFeatureImpl;
protected:
   JtkCounterBore( );
   virtual ~JtkCounterBore( );
};

///////%{
//
// Class          : JtkHoleComponent
//
// Description    : A HoleComponent of a JtkHoleFeature
//                  The HoleComponent requires either a face to be specified,
//                  or both diameter and extent to be set.
//                  If the extent is set to JtkFINITE then length must also be set.
//
// Enums          : JtkHoleExtentType: 
//                   JtkTHROUGH_ALL -- through all faces
//                   JtkTHROUGH_NEXT -- through to the next face in model
//                   JtkFROM_TO -- between specified points
//                   JtkFINITE -- from a specified point for a specified length
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkHoleElement > JtkHoleComponent
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHoleComponent : public JtkHoleElement
{
   JTK_OBJECT_HEADER( JtkHoleComponent )

public:
   enum JtkHoleExtentType
   {
      JtkUNSET = 0,
      JtkTHROUGH_ALL,
      JtkTHROUGH_NEXT,
      JtkFROM_TO,
      JtkFINITE
   };

   int numThreads( ) const;
   int addThread( JtkThread*& );
   int getThread( int Index, JtkThread*& ) const;

   int setDiameter( double );
   int getDiameter( double& ) const;

   int setLength( double );
   int getLength( double& ) const;

   int setExtent( JtkHoleExtentType );
   int getExtent( JtkHoleExtentType& ) const;

   int setTaperAngle( double );
   int getTaperAngle( double& ) const;

   int setBlindHoleAngle( double );
   int getBlindHoleAngle( double& ) const;

   friend class JtkHoleFeatureImpl;
protected:
   JtkHoleComponent( );
   virtual ~JtkHoleComponent( );
};

///////%{
//
// Class          : JtkHolePosition
//
// Description    : Positional and directional information about a 
//                  hole. The position must be specified.
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkRefCounted > JtkHolePosition 
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHolePosition : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkHolePosition )

public:
   int setPosition( double, double, double );
   int getPosition( double&, double&, double& ) const;

   int setDirection( double, double, double );
   int getDirection( double&, double&, double& ) const;

   friend class JtkHoleFeatureImpl;
protected:
   JtkHolePositionImpl*      _impl;

   JtkHolePosition( );
   virtual ~JtkHolePosition( );
};

///////%{
//
// Class          : JtkFeature
//
// Description    : Base class for describing features of the model
//
// Enums          : SubType : Specific feature type
//                   Threaded -- threaded feature
//                   Hole -- hole feature
//                   ContinuousJoin -- continuous join feature
//                   AdhesiveBead -- adhesive bead feature
//                   ArcWeld -- arc weld feature
//                   FilletWeld -- fillet weld feature 
//                   GrooveWeld -- groove weld feature
//                   PlugSlotWeld -- plut slot weld feature
//                   Datum -- datum feature
//                   PinDatum -- pin datum  feature
//                   SurfaceDatum -- surface datum feature
//                   MeasurementLocator -- measurement locator feature,
//                   DiscreteJoin -- discrete join feature,
//                   AdhesiveDollop -- adhesive dollop feature
//                   ArcSpotWeld -- arc spot weld feature
//                   MechanicalClinch -- mechanical clinch feature
//                   Rivet -- rivet feature
//                   WeldNut -- weld nut feature
//                   WeldStud -- weld stud feature
//                   ResistanceWeld -- resistence weld feature
//                   JointMark -- joint mark feature
//                   AdhesiveFill -- adhesive fill feature
//                   SurfaceWeld --surface weld feature
//                   Group -- a group of features
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkRefCounted > JtkFeature 
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkFeature : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkFeature )

public:

   int setName( const JtkString& );
   int getName( JtkString& ) const;

   int setId( int );
   int getId( int& ) const;
   int getCadType( ) const;

   int setSuppressed( int );
   int getSuppressed( int& ) const;

   int setEditable( int );
   int getEditable( int& ) const;

   int setRevision( const JtkString& Revision );
   int getRevision( JtkString& Revision ) const;

   int setDescription( const JtkString& Description );
   int getDescription( JtkString& Description ) const;

   int setStringId( const JtkString& StringId );
   int getStringId( JtkString& StringId ) const;

   int numProperty( ) const;
   int addProperty( const JtkString& Key, const JtkString& Value, int Hidden = 0 );
   int getProperty( int Index, JtkString& Key, JtkString& Value, int& Hidden ) const;

   int numGeneralAttributes( ) const;
   int addGeneralAttribute( const JtkString& Name, const JtkString& Value,
                            const JtkString& Unit = JtkString( ), const JtkString& Category = JtkString( ),
                            JtkMeasureEnum Dimensionality = MeasureEnumNONE,
                            JtkDataType Type = DataTypeSTRING, int Editable = 0 );
   int getGeneralAttribute( int Index, JtkString& Name, JtkString& Value,
                            JtkString& Unit, JtkString& Category,
                            JtkMeasureEnum& Dimensionality,
                            JtkDataType& Type, int& Editable ) const;

   int numGeneralAttributeListValues( int Index ) const;
   int addGeneralAttributeListValue( int Index, const JtkString& ListValue );
   int getGeneralAttributeListValue( int Index, int ListIndex, JtkString& ListValue ) const;

   enum SubType
   {
      Threaded = 0,
      Hole = 1,
      ContinuousJoin = 2,
      AdhesiveBead = 3,
      ArcWeld = 4,
      FilletWeld = 5,
      GrooveWeld = 6,
      PlugSlotWeld = 7,
      Datum = 8,
      PinDatum = 9,
      SurfaceDatum = 10,
      MeasurementLocator = 11,
      DiscreteJoin = 12,
      AdhesiveDollop = 13,
      ArcSpotWeld = 14,
      MechanicalClinch = 15,
      Rivet = 16,
      WeldNut = 17,
      WeldStud = 18,
      ResistanceWeld = 19,
      JointMark = 20,
      AdhesiveFill = 21,
      SurfaceWeld = 22,
      Group = 23
   };


   SubType getSubType( ) const;

   //display functionality
   int setPolylineData( int IndicesLength, int* Indices,
                        int VerticesLength, float* Vertices );
   int getPolylineData( int& IndicesLength, int*& Indices,
                        int& VerticesLength, float*& Vertices )const;

   int numAssociatedGeometry( ) const;
   int addAssociatedGeometry( int Id, int Type, const JtkString& Path = JtkString( ) );
   int getAssociatedGeometry( int Index, int& Id, int& Type ) const;
   int getAssociatedGeometry( int Index, int& Id, int& Type, JtkString& Path ) const;

   int setLabelParameters( const JtkString& label, double LabelOrigin[3], double LabelXAxis[3], double LabelYAxis[3], int FlatToScreen = 0, double Height = 1.0 );
   int getLabelParameters( JtkString& label, double LabelOrigin[3], double LabelXAxis[3], double LabelYAxis[3], int& FlatToScreen, double& Height ) const;

   friend class JtkEntityFactory;
   friend class JtkFeatureImpl;

protected:
   int setSubType( SubType FeatureType );

   JtkFeatureImpl*     _impl;

   JtkFeature( );
   JtkFeature( JtkFeatureImpl* );
   virtual ~JtkFeature( );
};

///////%{
//
// Class          : JtkHoleFeature
//
// Description    : Desciptive information about one or more holes which
//                  have the same sequence of JtkHoleElement( JtkHoleComponent,
//                  JtkCounterSink, JtkCounterBore) but which have differeing
//                  positions and directions.
//                  The HoleFeature must have at least 1 JtkHolePosition and 1 JtkHoleElement.
//                  The last HoleElement must be a JtkHoleComponent.
//
// Enums          : JtkHoleOrientationType:
//                   JtkNORMAL_TO_ENTRY_SURFACE -- normal to the face in which the hole lies.
//                   JtkNORMAL_TO_PLACEMENT_PLANE -- normal to a defined plane (not specified)
//                   JtkCOAXIAL -- coaxial with another hole (not specified)
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkHoleFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkHoleFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkHoleFeature )

public:
   enum JtkHoleOrientationType
   {
      JtkUNSET,
      JtkNORMAL_TO_PLACEMENT_PLANE,
      JtkNORMAL_TO_ENTRY_SURFACE,
      JtkCOAXIAL
   };

   int numHolePositions( )const;
   int addHolePosition( JtkHolePosition*& );
   int getHolePosition( int Index, JtkHolePosition*& )const;

   int numHoleElements( )const;
   int addHoleComponent( JtkHoleComponent*& );
   int addCounterBore( JtkCounterBore*& );
   int addCounterSink( JtkCounterSink*& );
   int getHoleElement( int Index, JtkHoleElement*& ) const;

   int setDirection( double, double, double );
   int getDirection( double&, double&, double& ) const;

   int setOrientation( JtkHoleOrientationType );
   int getOrientation( JtkHoleOrientationType& ) const;

   friend class JtkEntityFactory;
private:
   JtkHoleFeature( );
   virtual ~JtkHoleFeature( );
};


///////%{
//
// Class          : JtkThreadedFeature
//
// Description    : Descriptive information about a Thread Feature on the current
//                  part that is not associated with a Hole. 
//                  Only a single position and direction can be specified.
//                  The JtkThreadFeature must have at least 1 JtkThread
//                  and reference a face. Inside must also be set.
//
//                  Note: that if the threading information pertains 
//                  to a hole JtkHoleFeature should be used in preference
//
// Enums          : JtkThreadEntrySettingType:
//                   JtkSTANDARD --
//                   JtkSTRAIGHT_PIPE -- 
//                   JtkTAPERED_PIPE -- 
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkThreadedFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkThreadedFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkThreadedFeature )

public:
   enum JtkThreadEntrySettingType
   {
      JtkSTANDARD = 1,
      JtkSTRAIGHT_PIPE,
      JtkTAPERED_PIPE
   };

   int numThreads( ) const;
   int addThread( JtkThread*& );
   int getThread( int Index, JtkThread*& ) const;

   int setPosition( double, double, double );
   int getPosition( double&, double&, double& ) const;

   int setDirection( double, double, double );
   int getDirection( double&, double&, double& ) const;

   int setInside( int );
   int getInside( int& ) const;

   int setSetting( JtkThreadEntrySettingType );
   int getSetting( JtkThreadEntrySettingType& ) const;

   int numFaces( ) const;
   int addFace( int FaceId, const JtkString& Path = JtkString( ) );
   int getFace( int Index, int& FaceId ) const;
   int getFace( int Index, int& FaceId, JtkString& Path ) const;

   friend class JtkEntityFactory;
private:
   JtkThreadedFeature( );
   virtual ~JtkThreadedFeature( );
};

///////%{
//
// Class          : JtkContinuousJoinFeature
//
// Description    : Class for describing continuous join features.
//                  This class can be used to represent the following types of features:
//                    adhesive bead
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkContinuousJoinFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkContinuousJoinFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkContinuousJoinFeature )

public:

   int setLength( double Length );
   int getLength( double& Length ) const;

   int setVolume( double Volume );
   int getVolume( double& Volume ) const;

   friend class JtkEntityFactory;

protected:
   JtkContinuousJoinFeature( );
   JtkContinuousJoinFeature( JtkFeatureImpl* );
   virtual ~JtkContinuousJoinFeature( );
};

///////%{
//
// Class          : JtkArcWeldFeature
//
// Description    : Class for describing arc weld feature.
//                  This class can be used to represent the following types of features:
//                    fillet welds
//                    groove welds
//                    plug/slot welds
//
// Enums          : JtkContour : 
//                   JtkCONTOUR_NONE -- No contour
//                   JtkCONTOUR_FLUSH -- Flush contour (also known as flat)
//                   JtkCONTOUR_CONVEX -- Convex contour
//                   JtkCONTOUR_CONCAVE -- Concave contour
//
//                  JtkGroove :
//                   JtkGROOVE_SQUARE -- Square groove type
//                   JtkGROOVE_V_GROOVE -- V groove type
//                   JtkGROOVE_BEVEL -- Bevel groove type
//                   JtkGROOVE_U_GROOVE -- U groove type
//                   JtkGROOVE_J_GROOVE -- J groove type
//                   JtkGROOVE_FLARED_V -- Flared V groove type
//                   JtkGROOVE_FLARED_BEVEL -- Flared Bevel groove type
//
//                  JtkArcWeldJoint :
//                   JtkARCWELDJOINT_BUTT -- Butt weld joint type
//                   JtkARCWELDJOINT_CORNER -- Corner weld joint type
//                   JtkARCWELDJOINT_EDGE -- Edge weld joint type
//                   JtkARCWELDJOINT_LAP -- Lap weld joint type
//                   JtkARCWELDJOINT_TEE -- Tee weld joint type
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkContinuousJoinFeature > JtkArcWeldFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkArcWeldFeature : public JtkContinuousJoinFeature
{
   JTK_OBJECT_HEADER( JtkArcWeldFeature )

public:

   enum JtkContour
   {
      JtkCONTOUR_UNSET = -1,
      JtkCONTOUR_NONE = 0,
      JtkCONTOUR_FLUSH = 1,
      JtkCONTOUR_CONVEX = 2,
      JtkCONTOUR_CONCAVE = 3
   };

   enum JtkGroove
   {
      JtkGROOVE_UNSET = -1,
      JtkGROOVE_SQUARE = 0,
      JtkGROOVE_V_GROOVE = 1,
      JtkGROOVE_BEVEL = 2,
      JtkGROOVE_U_GROOVE = 3,
      JtkGROOVE_J_GROOVE = 4,
      JtkGROOVE_FLARED_V = 5,
      JtkGROOVE_FLARED_BEVEL = 6
   };

   enum JtkArcWeldJoint
   {
      JtkARCWELDJOINT_UNSET = -1,
      JtkARCWELDJOINT_BUTT = 0,
      JtkARCWELDJOINT_CORNER = 1,
      JtkARCWELDJOINT_EDGE = 2,
      JtkARCWELDJOINT_LAP = 3,
      JtkARCWELDJOINT_TEE = 4
   };

   int setWeldProcess( const JtkString& WeldProcess );
   int getWeldProcess( JtkString& WeldProcess ) const;

   int setContour( JtkContour Contour );
   int getContour( JtkContour& Contour ) const;

   int setHasFillet( int HasFillet );
   int getHasFillet( int& HasFillet ) const;

   int setGrooveType( JtkGroove GrooveType );
   int getGrooveType( JtkGroove& GrooveType ) const;

   int setJointType( JtkArcWeldJoint JointType );
   int getJointType( JtkArcWeldJoint& JointType ) const;

   int setContinuous( int Continuous );
   int getContinuous( int& Continuous ) const;

   int setBeadRadius( double BeadRadius );
   int getBeadRadius( double& BeadRadius ) const;

   int setPitch( double Pitch );
   int getPitch( double& Pitch ) const;

   int setStaggered( int Staggered );
   int getStaggered( int& Staggered) const ;

   int setTangentialPropagation( int TangentialPropagation );
   int getTangentialPropagation( int& TangentialPropagation ) const;

   int setLightweightRepresentation(JtkTriStripSet* TriStripSet);
   int getLightweightRepresentation(JtkTriStripSet*& TriStripSet) const;

   friend class JtkEntityFactory;

protected:
   JtkArcWeldFeature( );
   virtual ~JtkArcWeldFeature( );
};


///////%{
//
// Class          : JtkDatumFeature
//
// Description    : Class for describing datum feature
//                  This class can be used to represent the following types of features:
//                    pin datums
//                    surface datums
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkDatumFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkDatumFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkDatumFeature )

public:

   int setTransform( double Matrix[16] );
   int getTransform( double Matrix[16] ) const;

   int setControlDirections( int ControlsX, int ControlsY, int ControlsZ );
   int getControlDirections( int& ControlsX, int& ControlsY, int& ControlsZ ) const;

   int setDerived( int Derived );
   int getDerived( int& Derived ) const;

   int setSectionPlane( const JtkString& Name, double Origin[3],
                        double XAxis[3], double ZAxis[3] );
   int getSectionPlane( JtkString& Name, double Origin[3],
                        double XAxis[3], double ZAxis[3] ) const;

   friend class JtkEntityFactory;

protected:
   JtkDatumFeature( );
   virtual ~JtkDatumFeature( );
};


///////%{
//
// Class          : JtkMeasurementLocatorFeature
//
// Description    : Class for describing measurement locator feature.
//
// Enums          : JtkMeasurementType :
//                   JtkMEASUREMENTTYPE_SURFACE -- 
//                   JtkMEASUREMENTTYPE_TRIM -- 
//                   JtkMEASUREMENTTYPE_HOLE -- 
//                   JtkMEASUREMENTTYPE_SLOT -- 
//                   JtkMEASUREMENTTYPE_STUD -- 
//                   JtkMEASUREMENTTYPE_HEM -- 
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkMeasurementLocatorFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkMeasurementLocatorFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkMeasurementLocatorFeature )

public:

   enum JtkMeasurementType
   {
      JtkMEASUREMENTTYPE_UNSET = -1,
      JtkMEASUREMENTTYPE_SURFACE = 0,
      JtkMEASUREMENTTYPE_TRIM = 1,
      JtkMEASUREMENTTYPE_HOLE = 2,
      JtkMEASUREMENTTYPE_SLOT = 3,
      JtkMEASUREMENTTYPE_STUD = 4,
      JtkMEASUREMENTTYPE_HEM = 5
   };

   int setMeasurementType( JtkMeasurementType Type );
   int getMeasurementType( JtkMeasurementType& Type ) const;

   int setTransform( double Matrix[16] );
   int getTransform( double Matrix[16] ) const;

   int setAssociative( int Associative );
   int getAssociative( int& Associative ) const;

   int setNumberOfSheetsJoined( unsigned int NumberOfSheetsJoined );
   int getNumberOfSheetsJoined( unsigned int& NumberOfSheetsJoined ) const;

   friend class JtkEntityFactory;

protected:
   JtkMeasurementLocatorFeature( );
   virtual ~JtkMeasurementLocatorFeature( );
};


///////%{
//
// Class          : JtkDiscreteJoinFeature
//
// Description    : Class for describing a discrete join feature
//                  This class can be used to represent the following types of features:
//                    adhesive dollops
//                    arc spot welds
//                    mechanical clinches
//                    rivets
//                    weld nuts
//                    weld studs
//
// Enums          : JtkSymbolType
//                   JtkSYMBOLTYPE_SPHERE -- represent the join with a sphere
//                   JtkSYMBOLTYPE_CYLINDER -- represent the join with a cylinder
//                   JtkSYMBOLTYPE_CONE -- represent the join with a cone
//                   JtkSYMBOLTYPE_PRISM -- represent the join with a 3 sided prism
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkDiscreteJoinFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkDiscreteJoinFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkDiscreteJoinFeature )

public:

   int setGroupId( const JtkString& GroupId );
   int getGroupId( JtkString& GroupId ) const;

   int setNumberOfSheetsJoined( unsigned int NumberOfSheetsJoined );
   int getNumberOfSheetsJoined( unsigned int& NumberOfSheetsJoined ) const;

   int setNumberOfJoinsInGroup( unsigned int NumberOfJoinsInGroup );
   int getNumberOfJoinsInGroup( unsigned int& NumberOfJoinsInGroup ) const;

   int setAssociative( int Associative );
   int getAssociative( int& Associative ) const;

   int setChecked( int Checked );
   int getChecked( int& Checked ) const;

   enum JtkSymbolType
   {
      JtkSYMBOLTYPE_UNSET = -1,
      JtkSYMBOLTYPE_SPHERE = 0,
      JtkSYMBOLTYPE_CYLINDER = 1,
      JtkSYMBOLTYPE_CONE = 2,
      JtkSYMBOLTYPE_PRISM = 3
   };

   int setTransform( double Matrix[16] );
   int getTransform( double Matrix[16] ) const;

   int setWeldSymbol( JtkSymbolType Type, double Radius, double Height = 0.0, unsigned int NumberPrismSides = 3 );
   int getWeldSymbol( JtkSymbolType& Type, double& Radius, double& Height ) const;
   int getWeldSymbol( JtkSymbolType& Type, double& Radius, double& Height, unsigned int &NumberPrismSides) const;

   friend class JtkEntityFactory;

protected:
   JtkDiscreteJoinFeature( );
   JtkDiscreteJoinFeature( JtkFeatureImpl* );
   virtual ~JtkDiscreteJoinFeature( );
};

///////%{
//
// Class          : JtkResistanceWeldFeature
//
// Description    : Class for describing resistance weld features
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkDiscreteJoinFeature > JtkResistanceWeldFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkResistanceWeldFeature : public JtkDiscreteJoinFeature
{
   JTK_OBJECT_HEADER( JtkResistanceWeldFeature )

public:

   int setGoverningMetalThickness( const JtkString& GoverningMetalThickness );
   int getGoverningMetalThickness( JtkString& GoverningMetalThickness ) const;

   int setMetalCombination( const JtkString& MetalCombination );
   int getMetalCombination( JtkString& MetalCombination ) const;

   int setResistance( double Resistance );
   int getResistance( double& Resistance ) const;

   int setSpotDimensionalControl( int SpotDimensionalControl );
   int getSpotDimensionalControl( int& SpotDimensionalControl ) const;

   int setSpotKeyProductCharacteristic( int SpotKeyProductCharacteristic );
   int getSpotKeyProductCharacteristic( int& SpotKeyProductCharacteristic ) const;

   int setSpotKPCJustification( const JtkString& SpotKPCJustification );
   int getSpotKPCJustification( JtkString& SpotKPCJustification ) const;

   int setSpotProcessControl( int SpotProcessControl );
   int getSpotProcessControl( int& SpotProcessControl ) const;

   int setStackup( const JtkString& Stackup );
   int getStackup( JtkString& Stackup ) const;

   int setSymbolName( const JtkString& SymbolName );
   int getSymbolName( JtkString& SymbolName ) const;

   int setTolerance( unsigned int Tolerance );
   int getTolerance( unsigned int& Tolerance ) const;

   int setWeldClass( const JtkString& WeldClass );
   int getWeldClass( JtkString& WeldClass ) const;

   int setWeldForce( double WeldForce );
   int getWeldForce( double& WeldForce ) const;

   friend class JtkEntityFactory;

protected:
   JtkResistanceWeldFeature( );
   virtual ~JtkResistanceWeldFeature( );
};

///////%{
//
// Class          : JtkSurfaceAddFeature
//
// Description    : Abstract class for surface add features.
//                  This class is intended as a base class only.
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkSurfaceAddFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkSurfaceAddFeature : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkSurfaceAddFeature )

public:

   int setThickness( double Thickness );
   int getThickness( double& Thickness ) const;

   int setVolume( double Volume );
   int getVolume( double& Volume ) const;

protected:
   JtkSurfaceAddFeature( JtkFeatureImpl* );
   virtual ~JtkSurfaceAddFeature( );
};
///////%{
//
// Class          : JtkAdhesiveFillFeature
//
// Description    : Class for describing adhesive fill features.
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkSurfaceAddFeature > JtkAdhesiveFillFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkAdhesiveFillFeature : public JtkSurfaceAddFeature
{
   JTK_OBJECT_HEADER( JtkAdhesiveFillFeature )

public:

   int setLength( double Length );
   int getLength( double& Length ) const;

   friend class JtkEntityFactory;

protected:
   JtkAdhesiveFillFeature( );
   virtual ~JtkAdhesiveFillFeature( );
};


///////%{
//
// Class          : JtkSurfaceWeldFeature
//
// Description    : Class for describing surface weld features.
//
// Enums          : JtkSurfacing :
//                   JtkSURFACING_BUILDUP -- 
//                   JtkSURFACING_BUTTERING --
//                   JtkSURFACING_CLADDING --
//                   JtkSURFACING_HARDFACING --
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkSurfaceAddFeature > JtkSurfaceWeldFeature
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkSurfaceWeldFeature : public JtkSurfaceAddFeature
{
   JTK_OBJECT_HEADER( JtkSurfaceWeldFeature )

public:

   enum JtkSurfacing
   {
      JtkSURFACING_UNSET = -1,
      JtkSURFACING_BUILDUP = 0,
      JtkSURFACING_BUTTERING = 1,
      JtkSURFACING_CLADDING = 2,
      JtkSURFACING_HARDFACING = 3
   };

   int setSurfacingType( JtkSurfacing SurfacingType );
   int getSurfacingType( JtkSurfacing& SurfacingType ) const;

   int setWeldProcess( const JtkString& WeldProcess );
   int getWeldProcess( JtkString& WeldProcess ) const;

   friend class JtkEntityFactory;

protected:
   JtkSurfaceWeldFeature( );
   virtual ~JtkSurfaceWeldFeature( );
};

///////%{
//
// Class          : JtkFeatureGroup
//
// Description    : This class enables you to group multiple
//                  JtkFeatures into one persisted output in order to capture
//                  various grouping scenarios (compound welds or skip welds) and 
//                  additionally to aid with optimisation/declutering of discrete join types.
//    
//                  The child Features added to this class should all be of the
//                  same class types. So you cannot have a JtkFeatureGroup 
//                  with an JtkArcWeldFeature and a JtkDiscreteJoinFeature combined.
//                  You can also not group JtkFeatureGroup within one another.
//
// Enums          :
//
// Includes       : JtkFeature.h
//
// Inheritance    : JtkFeature > JtkFeatureGroup
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkFeatureGroup : public JtkFeature
{
   JTK_OBJECT_HEADER( JtkFeatureGroup )

public:

   int numFeatures( ) const;
   int addFeature( JtkFeature* ChildFeature );
   int getFeature( int Index, JtkFeature*& ChildFeature ) const;

   friend class JtkEntityFactory;

protected:
   JtkFeatureGroup( );
   virtual ~JtkFeatureGroup( );
};

#endif //JTK_FEATURE_H

