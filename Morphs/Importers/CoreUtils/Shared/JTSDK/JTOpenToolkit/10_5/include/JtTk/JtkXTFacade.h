////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_FACADE_HXX
#define JTK_XT_FACADE_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTFace;

///////%{
//
// Class          : JtkXTFacade
//
// Description    : An object defining a facade within XT topology.
//
// Enums          :
//
// Includes       : JtkXTFacade.h
//
// Inheritance    : JtkXTTopology > JtkXTFacade
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTFacade : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTFacade )

public:
   // Brep hierarchy management methods
   virtual int    addChild( JtkXTFace* face, int &error ) = 0;
   virtual int    getChild( JtkXTFace* &face, int &error ) = 0;
   virtual int    deleteChild( int &error ) = 0;

   virtual int    setSense( int sense, int &error ) = 0;
   virtual int    getSense( int &sense, int &error ) = 0;

   int            operator == ( const JtkXTFacade &rhs )const;

protected:
   JtkXTFacade();
   virtual ~JtkXTFacade();
};

#endif

