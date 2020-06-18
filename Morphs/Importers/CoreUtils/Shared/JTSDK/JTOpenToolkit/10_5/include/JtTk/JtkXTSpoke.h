////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_SPOKE_HXX
#define JTK_XT_SPOKE_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTVertex;

///////%{
//
// Class          : JtkXTSpoke
//
// Description    : An object defining a spoke within XT topology.
//
// Enums          :
//
// Includes       : JtkXTSpoke.h
//
// Inheritance    : JtkXTTopology > JtkXTSpoke
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSpoke : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTSpoke )

public:
   // Brep hierarchy management methods
   virtual int    addChild( JtkXTVertex* vertex, int &error ) = 0;
   virtual int    getChild( JtkXTVertex* &vertex, int &error ) = 0;
   virtual int    deleteChild( int &error ) = 0;

   virtual int    setSense( int sense, int &error ) = 0;
   virtual int    getSense( int &sense, int &error ) = 0;

   int            operator == ( const JtkXTSpoke &rhs )const;

protected:
   JtkXTSpoke();
   virtual  ~JtkXTSpoke();
};

#endif

