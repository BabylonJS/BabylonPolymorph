////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_ENTITY_FACTORY_HXX
#define JTK_XT_ENTITY_FACTORY_HXX

#include <JtTk/JtkStandard.h>

class JtkXTBody;
class JtkXTRegion;
class JtkXTShell;
class JtkXTFacade;
class JtkXTFace;
class JtkXTLoop;
class JtkXTFin;
class JtkXTEdge;
class JtkXTSpoke;
class JtkXTVertex;

class JtkXTSurface;
class JtkXTBSurf;
class JtkXTPlane;
class JtkXTCylinder;
class JtkXTCone;
class JtkXTSphere;
class JtkXTTorus;
class JtkXTOffset;
class JtkXTSwept;
class JtkXTSpun;
class JtkXTMesh;

class JtkXTCurve;
class JtkXTBCurve;
class JtkXTSPCurve;
class JtkXTLine;
class JtkXTCircle;
class JtkXTEllipse;

class JtkXTPoint;

class JtkGuid;
class JtkXTEntityMoniker;
class JtkXTBodyMoniker;
class JtkXTMonikerGuid;

class JtkXTSharingManager;

class JtkXTMaterial;

class JtkEntityList;

///////%{
//
// Class          : JtkXTEntityFactory
//
// Description    : A static factory class used to create all toolkit XTBrep
//                  objects. Client applications should use this class to
//                  create all JtkXTEntity-derived objects instead of C++'s new
//                  command. Object deletion should be accomplished via
//                  JtkEntity::unref() instead of C++'s delete command. Note,
//                  all objects have a ref count of zero when created.
//
// Enums          :
//
// Includes       : JtkXTEntityFactory.h
//
// Inheritance    : JtkXTEntityFactory
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTEntityFactory
{
public:
   static JtkXTSharingManager* getXTSharingManager( );

   // Topology
   static JtkXTBody*       createXTBody(int &error, int bodyId = -1);
   static JtkXTRegion*     createXTRegion( int &error, int entityId = -1 );
   static JtkXTShell*      createXTShell( int &error, int entityId = -1 );
   static JtkXTFacade*     createXTFacade( int &error, int entityId = -1 );
   static JtkXTFace*       createXTFace( int &error, int entityId = -1 );
   static JtkXTLoop*       createXTLoop( int &error, int entityId = -1 );
   static JtkXTFin*        createXTFin( int &error, int entityId = -1 );
   static JtkXTEdge*       createXTEdge( int &error, int entityId = -1 );
   static JtkXTSpoke*      createXTSpoke( int &error, int entityId = -1 );
   static JtkXTVertex*     createXTVertex( int &error, int entityId = -1 );

   // Geometry (surfaces).
   static JtkXTBSurf*      createXTBSurf( int      uDegree,
                                          int      vDegree,
                                          int      uNumCtlPts,
                                          int      vNumCtlPts,
                                          int      dimension,
                                          bool     isRational,
                                          double*  uvCtlPts,
                                          int      uNumKnots,
                                          int      vNumKnots,
                                          int*     uKnotMult,
                                          int*     vKnotMult,
                                          double*  uKnots,
                                          double*  vKnots,
                                          bool     uIsPeriodic,
                                          bool     vIsPeriodic,
                                          bool     uIsClosed,
                                          bool     vIsClosed,
                                          int     &error );

   static JtkXTBSurf*      createXTBSurf( JtkUnits units,
                                          int      uDegree,
                                          int      vDegree,
                                          int      uNumCtlPts,
                                          int      vNumCtlPts,
                                          int      dimension,
                                          bool     isRational,
                                          double*  uvCtlPts,
                                          int      uNumKnots,
                                          int      vNumKnots,
                                          int*     uKnotMult,
                                          int*     vKnotMult,
                                          double*  uKnots,
                                          double*  vKnots,
                                          bool     uIsPeriodic,
                                          bool     vIsPeriodic,
                                          bool     uIsClosed,
                                          bool     vIsClosed,
                                          int     &error );

   static JtkXTPlane*      createXTPlane( double*  location,
                                          double*  reference,
                                          double*  axis,
                                          int     &error );

   static JtkXTPlane*      createXTPlane( JtkUnits units,
                                          double*  location,
                                          double*  reference,
                                          double*  axis,
                                          int     &error );

   static JtkXTCylinder*   createXTCylinder( double*  location,
                                             double*  reference,
                                             double*  axis,
                                             double   radius,
                                             int     &error );
   static JtkXTCylinder*   createXTCylinder( JtkUnits units,
                                             double*  location,
                                             double*  reference,
                                             double*  axis,
                                             double   radius,
                                             int     &error );

   static JtkXTCone*       createXTCone( double*  location,
                                         double*  reference,
                                         double*  axis,
                                         double   radius,
                                         double   halfAngle,
                                         int     &error );
   static JtkXTCone*       createXTCone( JtkUnits units,
                                         double*  location,
                                         double*  reference,
                                         double*  axis,
                                         double   radius,
                                         double   halfAngle,
                                         int     &error );

   static JtkXTSphere*     createXTSphere( double*  location,
                                           double*  reference,
                                           double*  axis,
                                           double   radius,
                                           int     &error );
   static JtkXTSphere*     createXTSphere( JtkUnits units,
                                           double*  location,
                                           double*  reference,
                                           double*  axis,
                                           double   radius,
                                           int     &error );

   static JtkXTTorus*      createXTTorus( double*  location,
                                          double*  reference,
                                          double*  axis,
                                          double   majorRadius,
                                          double   minorRadius,
                                          int     &error );
   static JtkXTTorus*      createXTTorus( JtkUnits  units,
                                          double*  location,
                                          double*  reference,
                                          double*  axis,
                                          double   majorRadius,
                                          double   minorRadius,
                                          int     &error );


   static JtkXTOffset*     createXTOffset( JtkXTSurface*  underlyingSurface,
                                           double         offsetDistance,
                                           int           &error );
  static JtkXTOffset*     createXTOffset( JtkUnits units, 
                                          JtkXTSurface*  underlyingSurface,
                                          double         offsetDistance,
                                          int           &error );

   static JtkXTSwept*      createXTSwept( JtkXTCurve*  curve,
                                          double*      direction,
                                          int         &error );
 
   static JtkXTSpun*       createXTSpun( JtkXTCurve*  curve,
                                         double*      location,
                                         double*      axis,
                                         int         &error );
   static JtkXTSpun*       createXTSpun( JtkUnits units,
                                         JtkXTCurve*  curve,
                                         double*      location,
                                         double*      axis,
                                         int         &error );

   static JtkXTMesh*       createXTMesh(int& Error);
   static JtkXTMesh*       createXTMesh(int SizeEstimate, int& Error);

   // Geometry (curves).

   static JtkXTBCurve*     createXTBCurve( int      degree,
                                           int      numCtlPts,
                                           int      dimension,
                                           bool     isRational,
                                           double*  ctlPts,
                                           int      numKnots,
                                           int*     knotMult,
                                           double*  knots,
                                           bool     isPeriodic,
                                           bool     isClosed,
                                           int     &error );
   static JtkXTBCurve*     createXTBCurve( JtkUnits units,
                                           int      degree,
                                           int      numCtlPts,
                                           int      dimension,
                                           bool     isRational,
                                           double*  ctlPts,
                                           int      numKnots,
                                           int*     knotMult,
                                           double*  knots,
                                           bool     isPeriodic,
                                           bool     isClosed,
                                           int     &error );

   static JtkXTSPCurve*    createXTSPCurve( JtkXTSurface*  surface,
                                            JtkXTCurve*    curve,
                                            int           &error );
 
   static JtkXTLine*       createXTLine( double*  location,
                                         double*  direction,
                                         int     &error );
    static JtkXTLine*       createXTLine( JtkUnits units,
                                          double*  location,
                                          double*  direction,
                                          int     &error );

   static JtkXTCircle*     createXTCircle( double*  location,
                                           double*  reference,
                                           double*  axis,
                                           double   radius,
                                           int     &error );
   static JtkXTCircle*     createXTCircle( JtkUnits units,
                                           double*  location,
                                           double*  reference,
                                           double*  axis,
                                           double   radius,
                                           int     &error );

   static JtkXTEllipse*    createXTEllipse( double*  location,
                                            double*  reference,
                                            double*  axis,
                                            double   radius1,
                                            double   radius2,
                                            int     &error );
   static JtkXTEllipse*    createXTEllipse( JtkUnits units,
                                            double*  location,
                                            double*  reference,
                                            double*  axis,
                                            double   radius1,
                                            double   radius2,
                                            int     &error );

   // Geometry (points).
   static JtkXTPoint*      createXTPoint( double*  xyz,
                                          int     &error  );
   static JtkXTPoint*      createXTPoint( JtkUnits units,
                                          double*  xyz,
                                          int     &error  );

   // Monikers related APIs
   static JtkXTEntityMoniker* createXTEntityMoniker( int EntityId,
                                                     JtkXTMonikerGuid* Guid );
   static JtkXTBodyMoniker* createXTBodyMoniker( int BodyId, const JtkString& AppName );

   //XTMaterial 
   static JtkXTMaterial* createXTMaterial();

   // Measurement units APIs
   static int              setUnits( JtkUnits units, int &error );
   static int              getUnits( JtkUnits &units, int &error );

   // XT from Mesh
   static int              createXTBodies(JtkXTMesh* Mesh, JtkEntityList*& Bodies, JtkEntityList*& Faults, int& Error);
   static int              createXTBodies(JtkXTMesh* Mesh, double Precision, JtkEntityList*& Bodies, JtkEntityList*& Faults, int& Error);
};

#endif

