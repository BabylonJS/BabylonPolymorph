////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_VERTEX_HXX
#define JTK_XT_VERTEX_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTPoint;

///////%{
//
// Class          : JtkXTVertex
//
// Description    : An object defining a vertex within XT topology.
//
// Enums          :
//
// Includes       : JtkXTVertex.h
//
// Inheritance    : JtkXTTopology > JtkXTVertex
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTVertex : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTVertex )

public:
   virtual int    setPoint( JtkXTPoint* point, int &error ) = 0;
   virtual int    getPoint( JtkXTPoint* &point, int &error ) = 0;
   virtual int    deletePoint( int &error ) = 0;

   virtual int    setPrecision( double precision, int &error ) = 0;
   virtual int    setPrecision( JtkUnits units, double precision, int &error ) = 0;
   virtual int    getPrecision( double &precision, int &error ) = 0;
   virtual int    getPrecision( JtkUnits units, double &precision, int &error ) = 0;

   int            operator == ( const JtkXTVertex &rhs )const;

protected:
   JtkXTVertex();
   virtual  ~JtkXTVertex();
};

#endif

