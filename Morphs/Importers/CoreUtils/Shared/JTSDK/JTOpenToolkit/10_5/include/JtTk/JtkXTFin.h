////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_FIN_HXX
#define JTK_XT_FIN_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTEdge;
class JtkXTCurve;

///////%{
//
// Class          : JtkXTFin
//
// Description    : An object defining a fin within XT topology.
//
// Enums          :
//
// Includes       : JtkXTFin.h
//
// Inheritance    : JtkXTTopology > JtkXTFin
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTFin : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTFin )

public:
   // Brep hierarchy management methods
   virtual int    setEdge( JtkXTEdge* edge, int &error ) = 0;
   virtual int    getEdge( JtkXTEdge* &edge, int &error ) = 0;
   virtual int    deleteEdge( int &error) = 0;

   // The fin to edge sense.  (1 if same direction, else 0)
   virtual int    setSense( int sense, int &error ) = 0;
   virtual int    getSense( int &sense, int &error ) = 0;

   // The parameter space curve representation for this edge.
   virtual int    setCurve( JtkXTCurve* curve, int &error ) = 0;
   virtual int    setCurve( JtkXTCurve* curve, int sense, int &error ) = 0;
   virtual int    getCurve( JtkXTCurve* &curve, int &error ) = 0;
   virtual int    getCurve( JtkXTCurve* &curve, int &sense, int &error ) = 0;
   virtual int    deleteCurve( int &error) = 0;

   // The interval of the parameter space curve to use.
   virtual int    setInterval( double i1, double i2, int &error ) = 0;
   virtual int    getInterval( double &i1, double &i2, int &error ) = 0;

   int            operator == ( const JtkXTFin &rhs )const;

protected:
   JtkXTFin();
   virtual ~JtkXTFin();
};

#endif

