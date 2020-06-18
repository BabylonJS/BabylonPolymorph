////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_TOPOLOGY_HXX
#define JTK_XT_TOPOLOGY_HXX

#include <JtTk/JtkXTEntity.h>

///////%{
//
// Class          : JtkXTTopology
//
// Description    : A base class for all XT topological definition objects.
//
// Enums          :
//
// Includes       : JtkXTTopology.h
//
// Inheritance    : JtkXTEntity > JtkXTTopology
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTTopology : public JtkXTEntity
{
   JTK_OBJECT_HEADER( JtkXTTopology )

public:
   int            operator == ( const JtkXTTopology &OtherGeometry )const;

protected:
   JtkXTTopology();
   virtual ~JtkXTTopology();
};

#endif
