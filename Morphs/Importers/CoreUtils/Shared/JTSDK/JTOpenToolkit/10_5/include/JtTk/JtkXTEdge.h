////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_EDGE_HXX
#define JTK_XT_EDGE_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTSpoke;
class JtkXTCurve;
class JtkTessParams;
class JtkLineStripSet;

///////%{
//
// Class          : JtkXTEdge
//
// Description    : An object defining a edge within XT topology.
//
// Enums          :
//
// Includes       : JtkXTEdge.h
//
// Inheritance    : JtkXTTopology > JtkXTEdge
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTEdge : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTEdge )

public:
   // Brep hierarchy management methods
   virtual int    setStartSpoke( JtkXTSpoke* startSpoke, int &error ) = 0;
   virtual int    setEndSpoke( JtkXTSpoke* endSpoke, int &error ) = 0;
   virtual int    getStartSpoke( JtkXTSpoke* &startSpoke, int &error ) = 0;
   virtual int    getEndSpoke( JtkXTSpoke* &endSpoke, int &error ) = 0;

   virtual int    setCurve( JtkXTCurve* curve, int &error ) = 0;
   virtual int    setCurve( JtkXTCurve* curve, int sense, int &error ) = 0;
   virtual int    getCurve( JtkXTCurve* &curve, int &error ) = 0;
   virtual int    getCurve( JtkXTCurve* &curve, int &sense, int &error ) = 0;
   virtual int    deleteCurve( int &error ) = 0;

   virtual int    setPrecision( double precision, int &error ) = 0;
   virtual int    setPrecision( JtkUnits units, double precision, int &error ) = 0;
   virtual int    getPrecision( double &precision, int &error ) = 0;
   virtual int    getPrecision( JtkUnits units, double &precision, int &error ) = 0;
   
   virtual int    setInterval( double i1, double i2, int &error ) = 0;
   virtual int    getInterval( double &i1, double &i2, int &error ) = 0;

   virtual int    setEntityId( int EntityId, int& Error ) = 0;
   virtual int    getEntityId( int& EntityId, int& Error ) = 0;

   virtual int    tessellate( const JtkTessParams* Params, JtkLineStripSet* &TessResult ) = 0;
   virtual int    tessellate( JtkUnits Units, const JtkTessParams* Params, JtkLineStripSet* &TessResult ) = 0;
   static int     tessellate( PK_EDGE_t edge, const JtkTessParams* Params, JtkLineStripSet* &TessResult );
   static int     tessellate( JtkUnits Units, PK_EDGE_t edge, const JtkTessParams* Params, JtkLineStripSet* &TessResult );

   int            operator == ( const JtkXTEdge &rhs )const;

protected:
   JtkXTEdge();
   virtual ~JtkXTEdge();
};

#endif

