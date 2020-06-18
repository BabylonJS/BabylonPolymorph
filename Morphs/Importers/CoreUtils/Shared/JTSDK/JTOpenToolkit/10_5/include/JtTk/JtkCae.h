////////////////////////////////////////////////////////////////////////////////
// Copyright 2007 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_CAE_HXX
#define JTK_CAE_HXX

#include <JtTk/JtkString.h>
#include <JtTk/JtkEntity.h>
#include <JtTk/JtkEntityList.h>
#include <JtTk/JtkTriStripSet.h>
#include <JtTk/JtkLineStripSet.h>
#include <JtTk/JtkPointSet.h>

class JtkCae;
class JtkCaeVisual;
class JtkCaeColorbar;
class JtkCaeLegend;

///////%{
//
// Class          : JtkCae
//
// Description    : Represents non-geometric CAE visual data.
//
// Enums          :
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkRefCounted > JtkCae
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCae : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkCae )

public:
   virtual int getColorbar( JtkCaeColorbar* &colorbar ) = 0;
   virtual int setColorbar( JtkCaeColorbar* colorbar ) = 0;
   virtual int hasColorbar() = 0;

   virtual int getNumLegends( int &c ) = 0;
   virtual int getLegend( JtkCaeLegend* &legend, int i ) = 0;
   virtual int appendLegend( JtkCaeLegend* legend ) = 0;
   virtual int insertLegend( JtkCaeLegend* legend, int i ) = 0;
   virtual int removeLegend( JtkCaeLegend* legend ) = 0;
   virtual int removeLegend( int start, int n = 1 ) = 0;
   virtual int clearLegends() = 0;
   virtual int hasLegends() = 0;
protected:
   JtkCae();
   virtual  ~JtkCae();
};

///////%{
//
// Class          : JtkCaeVisual
//
// Description    : Base class for JtkCaeLegend and JtkCaeColorbar.
//
// Enums          : JtkCaeFormat
//                    JtkCAE_FORMAT_PRIMITIVE -- Vertex information is provided,
//                      which specifies where to display the JtkCaeVisual.
//                    JtkCAE_FORMAT_DESCRIPTION -- It is up to the consuming
//                      application to decide where to display the JtkCaeVisual.
//
//                  JtkCaeFormatType
//                    JtkCAE_FORMAT_FLOAT -- The JtkCaeVisual is displayed at a
//                      fixed point on the screen.
//                    JtkCAE_FORMAT_ANCHOR -- A leader line is displayed, which
//                      is attached to the anchor point.
//
//                  JtkCaeFormatCoord
//                    JtkCAE_FORMAT_ORTHO -- The anchor point is specified
//                      relative to the clipping window.
//                    JtkCAE_FORMAT_PIXEL -- The anchor point is specified in
//                      screen pixels.
//                    JtkCAE_FORMAT_WORLD -- The anchor point is specified in
//                      the world coordinate system.
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkRefCounted > JtkCaeVisual
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeVisual : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkCaeVisual )

public:
   enum JtkCaeFormat {
      JtkCAE_FORMAT_PRIMITIVE = 1,
      JtkCAE_FORMAT_DESCRIPTION = 2
   };

   enum JtkCaeFormatType {
      JtkCAE_FORMAT_FLOAT = 1,
      JtkCAE_FORMAT_ANCHOR = 2
   };

   enum JtkCaeFormatCoord {
      JtkCAE_FORMAT_ORTHO = 1,
      JtkCAE_FORMAT_PIXEL = 2,
      JtkCAE_FORMAT_WORLD = 3
   };

   virtual int setTitle( const JtkString& str ) = 0;
   virtual JtkString getTitle() = 0;

   virtual int setFormat( JtkCaeFormat format ) = 0;
   virtual int getFormat( JtkCaeFormat &format ) = 0;

   virtual int setFormatType( JtkCaeFormatType type ) = 0;
   virtual int getFormatType( JtkCaeFormatType &type ) = 0;

   virtual int setFormatCoord( JtkCaeFormatCoord coord ) = 0;
   virtual int getFormatCoord( JtkCaeFormatCoord &coord ) = 0;

   virtual int setFormatPosition( int x, int y ) = 0;
   virtual int getFormatPosition( int &x, int &y ) = 0;

   virtual int setFormatExtents( int left, int right, int top, int bottom ) = 0;
   virtual int getFormatExtents( int &left, int &right, int &top, int &bottom ) = 0;

   virtual int setFormatAnchor( float x, float y, float z ) = 0;
   virtual int getFormatAnchor( float &x, float &y, float &z ) = 0;

protected:
   JtkCaeVisual();
   virtual  ~JtkCaeVisual();
};

///////%{
//
// Class          : JtkCaeColorbar
//
// Description    : Represents a color key displayed as a bar.
//
// Enums          : JtkCaeColorbarType
//                    JtkCAE_COLORBAR_BAND -- The JtkCaeColorbar is rendered
//                      using flat shading.
//                    JtkCAE_COLORBAR_SMOOTH -- The JtkCaeColorbar is rendered
//                      using smooth shading.
//                    JtkCAE_COLORBAR_SCALAR -- Used when the CAE model consists
//                      of scalar data as in a contour plot.
//                    JtkCAE_COLORBAR_DISCRETE -- Used when the CAE model
//                      consists of scalar data as in a contour plot.
//
//                  JtkCaeColorbarDisplay
//                    JtkCAE_COLORBAR_NONE -- The JtkCaeColorbar is not
//                      displayed.
//                    JtkCAE_COLORBAR_LEFT -- The JtkCaeColorbar is displayed on
//                      the left.
//                    JtkCAE_COLORBAR_RIGHT -- The JtkCaeColorbar is displayed
//                      on the right.
//                    JtkCAE_COLORBAR_TOP -- The JtkCaeColorbar is displayed at
//                      the top.
//                    JtkCAE_COLORBAR_BOTTOM -- The JtkCaeColorbar is displayed
//                      at the bottom.
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkCaeVisual > JtkCaeColorbar
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeColorbar : public JtkCaeVisual
{
   JTK_OBJECT_HEADER( JtkCaeColorbar )

public:
   enum JtkCaeColorbarType {
      JtkCAE_COLORBAR_BAND = 1,
      JtkCAE_COLORBAR_SMOOTH = 2,
      JtkCAE_COLORBAR_SCALAR = 3,
      JtkCAE_COLORBAR_DISCRETE = 4
   };

   enum JtkCaeColorbarDisplay {
      JtkCAE_COLORBAR_NONE = 0,
      JtkCAE_COLORBAR_LEFT = 1,
      JtkCAE_COLORBAR_RIGHT = 2,
      JtkCAE_COLORBAR_TOP = 3,
      JtkCAE_COLORBAR_BOTTOM = 4
   };

   virtual int setLegend( JtkCaeLegend* legend ) = 0;
   virtual int getLegend( JtkCaeLegend* &legend ) = 0;
   virtual int hasLegend() = 0;

   virtual int setType( JtkCaeColorbarType type ) = 0;
   virtual int getType( JtkCaeColorbarType &type ) = 0;

   virtual int setDisplay( JtkCaeColorbarDisplay display ) = 0;
   virtual int getDisplay( JtkCaeColorbarDisplay &display ) = 0;

   virtual int getNumLevels( int &c ) = 0;
   virtual int addLevel( double val, float r, float g, float b ) = 0;
   virtual int removeLevel( int start, int c = 1 ) = 0;
   virtual int getLevelValue( int level, double &val ) = 0;
   virtual int setLevelColor( int level, float r, float g, float b ) = 0;
   virtual int getLevelColor( int level, float &r, float &g, float &b ) = 0;

   virtual int getNumSubLevels( int level, int &c ) = 0;
   virtual int addSubLevel( int level, float r, float g, float b ) = 0;
   virtual int removeSubLevel( int level, int start, int c = 1 ) = 0;
   virtual int setSubLevelColor( int level, int sublevel, float r, float g, float b ) = 0;
   virtual int getSubLevelColor( int level, int sublevel, float &r, float &g, float &b ) = 0;
protected:
   JtkCaeColorbar();
   virtual  ~JtkCaeColorbar();
};

///////%{
//
// Class          : JtkCaeLegend
//
// Description    : Represents the legend for a colorbar or a CAE model.
//
// Enums          :
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkCaeVisual > JtkCaeLegend
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeLegend : public JtkCaeVisual
{
   JTK_OBJECT_HEADER( JtkCaeLegend )

public:
   virtual int getNumStrings( int &c ) = 0;
   virtual int appendString( const JtkString& str, float r, float g, float b ) = 0;
   virtual int insertString( int i, const JtkString& str, float r, float g, float b ) = 0;
   virtual int removeString( int start, int c = 1 ) = 0;

   virtual int setString( int i, const JtkString& str ) = 0;
   virtual JtkString getString( int i ) = 0;

   virtual int setColor( int i, float r, float g, float b ) = 0;
   virtual int getColor( int i, float &r, float &g, float &b ) = 0;

protected:
   JtkCaeLegend();
   virtual  ~JtkCaeLegend();
};

///////%{
//
// Class          : JtkCaeId
//
// Description    : The object for mapping JtkShapes to CAE model primitives
//                  such as "element" and "node".
//
// Enums          : JtkCaeIdType
//                     JtkCAE_TYPE_NONE --  The JtkCaeId has no type information.
//                                          Provided for completeness only.
//                     JtkCAE_TYPE_NODAL -- The JtkCaeId has a node identifier only. 
//                     JtkCAE_TYPE_ELEMENTAL -- The JtkCaeId has an element identifier only.
//                     JtkCAE_TYPE_ELEMENT_NODAL -- The JtkCaeId has both an element and a node
//                                               identifier.
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkEntity > JtkCaeId
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeId : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkCaeId )

public:

   enum JtkCaeIdType
   {
      JtkCAE_TYPE_NONE = 0,
      JtkCAE_TYPE_NODAL = 1,
      JtkCAE_TYPE_ELEMENTAL = 2,
      JtkCAE_TYPE_ELEMENT_NODAL = 3
   };

   virtual int nodeId( int& nodeId ) = 0;
   virtual int elementId( int& elementId ) = 0;

   virtual JtkCaeIdType type( ) = 0;

   virtual int nodeLocation( float*& NodeLocation ) = 0;
   virtual int add( JtkShape* Shape ) = 0;
   virtual int remove( JtkShape* Shape ) = 0;
   virtual int shapes( JtkEntityList*& Shapes ) = 0;
protected:
   virtual ~JtkCaeId( );
   JtkCaeId( );
};

///////%{
//
// Class          : JtkCaeResultQuantityArray
//
// Description    : Provides a mechanism for representing CAE Results in JtTK.
//
// Enums          : JtkCaeResultQuantityArrayLocation
//                     JtkCAE_LOCATION_NONE -- No location information is specified.
//                                          Provided for completeness only.
//                     JtkCAE_LOCATION_NODAL -- The result variables relate to nodes 
//                                           and are evaluated at the nodes.
//                     JtkCAE_LOCATION_ELEMENTAL -- The result variables relate to 
//                                               elements and are evaluated for the
//                                               elements.
//                     JtkCAE_LOCATION_ELEMENT_NODAL -- The result variables relate 
//                                                   to elements but are evaluated at
//                                                   their nodes.
//
//                  JtkCaeResultQuantityArrayType
//                     JtkCAE_RESULT_TYPE_NONE -- No type information is specified.
//                                             Provided for completeness only.
//                     JtkCAE_RESULT_TYPE_SCALAR -- The result variables are 1-dimensional
//                                               scalars.
//                     JtkCAE_RESULT_TYPE_VECTOR -- The result variables are 3-dimensional
//                                               vectors.
//                     JtkCAE_RESULT_TYPE_TENSOR -- The result variables are 6-dimensional
//                                               tensors.
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkEntity > JtkCaeResultQuantityArray
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeResultQuantityArray : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkCaeResultQuantityArray )
public:
   enum JtkCaeResultQuantityArrayLocation
   {
      JtkCAE_LOCATION_NONE          = 0,
      JtkCAE_LOCATION_NODAL         = 1,
      JtkCAE_LOCATION_ELEMENTAL     = 2,
      JtkCAE_LOCATION_ELEMENT_NODAL = 3
   };

   enum JtkCaeResultQuantityArrayType
   {
      JtkCAE_RESULT_TYPE_NONE          = 0,
      JtkCAE_RESULT_TYPE_SCALAR        = 1,
      JtkCAE_RESULT_TYPE_VECTOR        = 2,
      JtkCAE_RESULT_TYPE_TENSOR        = 3
   };

   virtual int getHeaderInternals( JtkString& ResultType,
                                   JtkString& AnalysisType,
                                   JtkCaeResultQuantityArrayLocation& ResultLocation,
                                   JtkUnits& Units,
                                   JtkString*& Descriptions,
                                   JtkCaeResultQuantityArrayType& DimType ) = 0;

   virtual int numResultQuantityValues( int& NumValues) = 0; 
   virtual int addResultQuantityValues( JtkEntityList* CaeIds,
                                        double* ValueArray ) = 0;
   virtual int getResultQuantityValues( JtkEntityList* CaeIds,
                                        double*& ValueArray ) = 0;
   virtual int getResultQuantityValues( JtkEntityList* CaeIds,
                                        JtkEntityList*& Faults,
                                        double*& ValueArray ) = 0;
   virtual int removeResultQuantityValues( JtkEntityList* CaeIds ) = 0;

   virtual int getResultQuantityValue( JtkCaeId* CaeId, double*& ValueArray ) = 0;
   virtual int getResultQuantityIds( JtkEntityList*& CaeIds ) = 0;

protected:
   JtkCaeResultQuantityArray( );
   virtual ~JtkCaeResultQuantityArray( );
};

///////%{
//
// Class          : JtkCaeResultQuantityStepLegend
//
// Description    : Provides a mechanism for representing color bar legends
//                  for CAE Result steps in JtTK.
//
// Enums          : JtkCaeResultQuantityStepLegendScale
//                     JtkCAE_SCALE_NONE -- There is no scale. Provided for completeness only.
//                     JtkCAE_SCALE_LINEAR -- The scale is linear.
//                     JtkCAE_SCALE_CUSTOM -- The scale if customized.
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkEntity > JtkCaeResultQuantityStepLegend
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeResultQuantityStepLegend : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkCaeResultQuantityStepLegend )
public:
   enum JtkCaeResultQuantityStepLegendScale
   {
      JtkCAE_SCALE_NONE   = 0,
      JtkCAE_SCALE_LINEAR = 1,
      JtkCAE_SCALE_CUSTOM = 2
   };
   virtual int getInternals(JtkCaeResultQuantityStepLegendScale& Scale,
                              double*& CustomInterpolArray,
                              int& NumCustomVals,
                              double& MinLegendVal,
                              double& MaxLegendVal,
                              double*& ColorRampArray,
                              int& NumRampVals,
                              JtkString& ResultType,
                              JtkString& Description,
                              JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayLocation& ResultLocation,
                              int& IsGlobal, 
                              double& DeformScaleFactor,
                              double& ArrowScaleFactor, 
                              int& PointSize) = 0;

   virtual int isGlobal( ) = 0;

   virtual int getInternals( double*& ColorRampArray,
                             int& NumRampVals,
                             double& DeformScaleFactor,
                             double& ArrowScaleFactor,
                             int& PointSize ) = 0;

   virtual int getInternals( JtkCaeResultQuantityStepLegend::JtkCaeResultQuantityStepLegendScale& Scale,
                             double*& ColorRampArray,
                             int& NumRampVals,
                             JtkString& Description,
                             double*& CustomInterpolArray,
                             int& NumCustomVals,
                             double& MinLegendVal,
                             double& MaxLegendVal ) = 0;

protected:
   JtkCaeResultQuantityStepLegend( );
   ~JtkCaeResultQuantityStepLegend( );
};

///////%{
//
// Class          : JtkCaeResultStep
//
// Description    : Provides a mechanism for representing CAE Results steps in 
//                  JtTK.
//
// Enums          :
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkEntity > JtkCaeResultStep
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeResultStep : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkCaeResultStep )

public:
   virtual int name( JtkString& Name ) = 0;
   virtual int label( JtkString& Label ) = 0;
   virtual int numResultQuantityArrays( int& NumArrays ) = 0;
   virtual int addResultQuantityArray( JtkCaeResultQuantityArray* Array ) = 0;
   virtual int remove( JtkCaeResultQuantityArray* Array ) = 0;
   virtual int remove( int Index,
                       int NumToRemove = 1 ) = 0;
   virtual JtkCaeResultQuantityArray* resultQuantityArray( int Index ) = 0;
   virtual JtkCaeResultQuantityArray* find( const JtkString& ResultType, 
                                            JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayLocation ResultLocation,
                                            const JtkString& AnalysisType,
                                            JtkString* Descriptions,
                                            JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayType DimType ) = 0;
   virtual int find( JtkCaeResultQuantityArray* Array,
                     int& Index,
                     int StartAt = 0 ) = 0;
   virtual int numResultQuantityStepLegends( JtkCaeResultQuantityArray* Array,
                                             int& NumLegends ) = 0;
   virtual int addResultQuantityStepLegend( JtkCaeResultQuantityArray* Array,
                                            JtkCaeResultQuantityStepLegend* Legend ) = 0;
   virtual int remove( JtkCaeResultQuantityStepLegend* Legend ) = 0;
   virtual int removeLegendForResultQuantityArray( JtkCaeResultQuantityArray* Array,
                                                   int Index ) = 0;
   virtual JtkCaeResultQuantityStepLegend* resultQuantityStepLegend( JtkCaeResultQuantityArray* Array,
                                                                     int Index ) = 0;
   virtual JtkCaeResultQuantityStepLegend* find( JtkCaeResultQuantityArray* Array,
                                                 const JtkString& Description ) = 0;
protected:
   JtkCaeResultStep( );
   virtual ~JtkCaeResultStep( );
};

///////%{
//
// Class          : JtkCaeResult
//
// Description    : Represents a set of results for CAE analysis.
//
// Enums          :
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkEntity > JtkCaeResult
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeResult : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkCaeResult )

public:
   virtual int name( JtkString& Name ) = 0;
   virtual int numSteps( int& NumSteps ) = 0;
   virtual JtkCaeResultStep* caeResultStep( int Index ) = 0;
   virtual int find( JtkCaeResultStep* ResultStep,
                     int& Index,
                     int StartAt = 0 ) = 0;
   virtual int add( JtkCaeResultStep* ResultStep ) = 0;
   virtual int remove( JtkCaeResultStep* ResultStep ) = 0;
   virtual int remove( int Index,
                       int NumSteps = 1 ) = 0;

protected:
   JtkCaeResult( );
   virtual ~JtkCaeResult( );
};

///////%{
//
// Class          : JtkCaeManager
//
// Description    : A static object for creating and managing
//                  JtTk CAE representations.
//
// Enums          :
//
// Includes       : JtkCae.h
//
// Inheritance    : JtkEntity > JtkCaeManager
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCaeManager : public JtkEntity
{

   JTK_OBJECT_HEADER( JtkCaeManager )
public:


   //Global simulation items
   virtual int setSimulationTitle( const JtkString& Title ) = 0;
   virtual JtkString simulationTitle( ) = 0;
   virtual int setSimulationVersion( int Version ) = 0;
   virtual int simulationVersion( ) = 0;

   //JtkCaeId related API's
   //creation API's

   //2D element-nodal JtkCaeIds
   virtual int createCaeIds( int* ElementIds,
                             JtkEntityList* TessGroups,
                             int NumElementIds,
                             int** NodeIds,
                             float** NodeLocations,
                             int* NumNodeIds,
                             JtkEntityList*& CaeIds ) = 0;

   virtual int createCaeIds( int* ElementIds,
                             JtkEntityList* TessGroups,
                             int NumElementIds,
                             int** NodeIds,
                             float** NodeLocations,
                             int* NumNodeIds,
                             JtkEntityList*& Faults,
                             JtkEntityList*& CaeIds ) = 0;

   //1D element-nodal JtkCaeIds
   virtual int createCaeIds( int* ElementIds,
                             JtkLineStripSet* LSS,
                             int* Indices,
                             int NumElementIds,
                             int** NodeIds,
                             float** NodeLocations,
                             int* NumNodeIds,
                             JtkEntityList*& CaeIds ) = 0;

   virtual int createCaeIds( int* ElementIds,
                             JtkLineStripSet* LSS,
                             int* Indices,
                             int NumElementIds,
                             int** NodeIds,
                             float** NodeLocations,
                             int* NumNodeIds,
                             JtkEntityList*& Faults,
                             JtkEntityList*& CaeIds ) = 0;

   //2D or 1D nodal JtkCaeIds
   virtual int createCaeIds( int* NodeIds,
                             int NumNodeIds,
                             float** NodeLocations,
                             JtkShape* Shape,
                             JtkEntityList*& CaeIds ) = 0;

   virtual int createCaeIds( int* NodeIds,
                             int NumNodeIds,
                             float** NodeLocations,
                             JtkShape* Shape,
                             JtkEntityList*& Faults,
                             JtkEntityList*& CaeIds ) = 0;

   //2D elemental JtkCaeIds
   virtual int createCaeIds( int* ElementIds,
                             int NumElementIds,
                             JtkEntityList* TessGroups,
                             JtkEntityList*& CaeIds ) = 0;

   virtual int createCaeIds( int* ElementIds,
                             int NumElementIds,
                             JtkEntityList* TessGroups,
                             JtkEntityList*& Faults,
                             JtkEntityList*& CaeIds ) = 0;

   //1D elemental JtkCaeIds
   virtual int createCaeIds( int* ElementIds,
                             int NumElementIds,
                             JtkLineStripSet* LSS,
                             int* Indices,
                             JtkEntityList*& CaeIds ) = 0;

   virtual int createCaeIds( int* ElementIds,
                             int NumElementIds,
                             JtkLineStripSet* LSS,
                             int* Indices,
                             JtkEntityList*& Faults,
                             JtkEntityList*& CaeIds ) = 0;

   //0D elemental JtkCaeIds
   virtual int createCaeIds( int* ElementIds,
                             int NumElementIds,
                             JtkPointSet* PS,
                             int* Indices,
                             JtkEntityList*& CaeIds ) = 0;

   virtual int createCaeIds( int* ElementIds,
                             int NumElementIds,
                             JtkPointSet* PS,
                             int* Indices,
                             JtkEntityList*& Faults,
                             JtkEntityList*& CaeIds ) = 0;

   //Cae Id inquiry API's
   virtual int caeId( int ElementId,
                      int NodeId,
                      JtkCaeId*& CaeId ) = 0;

   virtual int caeId( int Id,
                      JtkCaeId::JtkCaeIdType Type,
                      JtkCaeId*& CaeId ) = 0;

   virtual int caeIds( JtkEntityList*& CaeIds ) = 0;

   //Cae Id destruction API's
   virtual int destroy( JtkCaeId* CaeId ) = 0;

   //JtkCaeResult related API's
   virtual JtkCaeResult* createCaeResult( const JtkString& Name ) = 0;
   virtual int numResults( ) = 0;
   virtual JtkCaeResult* result( int Index ) = 0;
   virtual int findResult( JtkCaeResult* Result,
                           int& Index,
                           int StartAt = 0 ) = 0;
   virtual int findResult( const JtkString& Name,
                           JtkCaeResult*& Result ) = 0;
   virtual int destroy( JtkCaeResult* Result ) = 0;

   //JtkCaeResultStep related API's
   virtual JtkCaeResultStep* createCaeResultStep( const JtkString& Name,
                                                  const JtkString& Label ) = 0;
   virtual int numResultSteps( ) = 0;
   virtual JtkCaeResultStep* resultStep( int Index ) = 0;
   virtual int findResultStep( JtkCaeResultStep* ResultStep,
                               int& Index,
                               int StartAt = 0 ) = 0;
   virtual int findResultStep( const JtkString& Name,
                               const JtkString& Label,
                               JtkCaeResultStep*& ResultStep ) = 0;
   virtual int findResultSteps( const JtkString& Name,
                               const JtkString& Label,
                               JtkEntityList*& ResultSteps ) = 0;
   virtual int destroy( JtkCaeResultStep* ResultStep ) = 0;

   //JtkCaeResultQuantityArray related API's
   //Note: we decided to use strings instead of enum for resultType in the API
   //below because TCVIS does not plan to interpret what the result type means.
   virtual JtkCaeResultQuantityArray* createCaeResultQuantityArray( const JtkString& ResultType,
                                                                    const JtkString& AnalysisType,
                                                                    JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayLocation ResultLocation,
                                                                    JtkUnits Units,
                                                                    JtkString* Descriptions,
                                                                    JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayType DimType ) = 0;
   virtual int numResultQuantityArrays( ) = 0;
   virtual JtkCaeResultQuantityArray* resultQuantityArray( int Index ) = 0;
   virtual int findResultQuantityArray( JtkCaeResultQuantityArray* Array,
                                        int& Index,
                                        int StartAt = 0 ) = 0;
   virtual int findResultQuantityArray( const JtkString& ResultType,
                                        const JtkString& AnalysisType,
                                        JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayLocation ResultLocation,
                                        JtkUnits Units,
                                        JtkString* Descriptions,
                                        JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayType DimType,
                                        JtkCaeResultQuantityArray*& Array ) = 0;
   virtual int destroy( JtkCaeResultQuantityArray* Array ) = 0;

   //JtkCaeResultQuantityStepLegend related API's
   virtual JtkCaeResultQuantityStepLegend*
   createCaeResultQuantityStepLegend( JtkCaeResultQuantityStepLegend::JtkCaeResultQuantityStepLegendScale Scale,
                                      double* CustomInterpolArray,
                                      int NumCustomVals,
                                      double MinLegendVal,
                                      double MaxLegendVal,
                                      double* ColorRampArray,
                                      int NumRampVals,
                                      const JtkString& ResultType,
                                      const JtkString& Description,
                                      JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayLocation ResultLocation,
                                      int IsGlobal = 0,
                                      double DeformScaleFactor = 1.0,
                                      double ArrowScaleFactor = 1.0,
                                      int PointSize = 0 ) = 0;

   virtual JtkCaeResultQuantityStepLegend*
   createCaeResultQuantityStepGlobalLegend( double* ColorRampArray,
                                            int NumRampVals,
                                            double DeformScaleFactor = 1.0,
                                            double ArrowScaleFactor = 1.0,
                                            int PointSize = 0 ) = 0;

   virtual JtkCaeResultQuantityStepLegend*
   createCaeResultQuantityStepLocalLegend( JtkCaeResultQuantityStepLegend::JtkCaeResultQuantityStepLegendScale Scale,
                                           double* ColorRampArray,
                                           int NumRampVals,
                                           const JtkString& Description,
                                           double* CustomInterpolArray = NULL,
                                           int NumCustomVals = 0,
                                           double MinLegendVal = 0.0,
                                           double MaxLegendVal = 0.0
                                           ) = 0;

   virtual int numResultQuantityStepLegends( ) = 0;
   virtual JtkCaeResultQuantityStepLegend* resultQuantityStepLegend( int Index ) = 0;
   virtual int findResultQuantityStepLegend( JtkCaeResultQuantityStepLegend* Legend,
                                             int& Index,
                                             int StartAt = 0 ) = 0;
   virtual int findResultQuantityStepLegend( JtkCaeResultQuantityStepLegend::JtkCaeResultQuantityStepLegendScale Scale,
                                             const JtkString& ResultType,
                                             const JtkString& Description,
                                             JtkCaeResultQuantityArray::JtkCaeResultQuantityArrayLocation ResultLocation,
                                             JtkCaeResultQuantityStepLegend*& Legend ) = 0;
   virtual int findResultQuantityStepGlobalLegend( JtkCaeResultQuantityStepLegend*& Legend ) = 0;
   virtual int findResultQuantityStepLocalLegend( JtkCaeResultQuantityStepLegend::JtkCaeResultQuantityStepLegendScale Scale,
                                                  const JtkString& Description,
                                                  JtkCaeResultQuantityStepLegend*& Legend ) = 0;
   virtual int destroy( JtkCaeResultQuantityStepLegend* Legend ) = 0;

   virtual int destroyAll( ) = 0;

protected:
   JtkCaeManager( );
   virtual ~JtkCaeManager( );
};
#endif //JTK_CAE_HXX
