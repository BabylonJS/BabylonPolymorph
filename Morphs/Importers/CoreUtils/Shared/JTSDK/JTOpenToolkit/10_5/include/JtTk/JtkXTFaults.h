////////////////////////////////////////////////////////////////////////////////
// Copyright 2009 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_XT_FAULT_HXX
#define JTK_XT_FAULT_HXX

#include <JtTk/JtkFault.h>
#include <JtTk/JtkEntityList.h>
#include <JtTk/JtkEntityFactory.h>
#include <JtTk/JtkXTEntity.h>

class _JtkXTFault;
class _JtkXTGeometryFault;
class _JtkXTSinglePointGeometryFault;
class _JtkXTEntityFault;
class _JtkXTSingleEntityFault;
class _JtkXTMultipleEntityFault;

///////%{
//
// Class          : JtkXTFault
//
// Description    : A toolkit-specific JtkXT fault reporting mechanism.
//                  This is a base class from which different JtkXT fault
//                  types are derived.
//
// Enums          :
//
// Includes       : JtkXTFaults.h
//
// Inheritance    : JtkFault > JtkXTFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTFault: public JtkFault
{
   JTK_OBJECT_HEADER( JtkXTFault )

   friend class _JtkXTFault;

public:

   // accessor
   int getState( ) const;

protected:
  
   // construct
   JtkXTFault( );

   // destruction
   virtual ~JtkXTFault();

private:

   // equality operator
   int operator ==( const JtkXTFault &OtherFault ) const;
};

///////%{
//
// Class          : JtkXTGeometryFault
//
// Description    : A toolkit-specific JtkXT geometric fault reporting class.
//                  This class is the base class for various JtXT geometric
//                  faults.
//
// Enums          :
//
// Includes       : JtkXTFaults.h
//
// Inheritance    : JtkXTFault > JtkXTGeometryFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTGeometryFault: public JtkXTFault
{
   JTK_OBJECT_HEADER( JtkXTGeometryFault )

protected:

   // parameterized constructor
   JtkXTGeometryFault( );

   // destruction
   virtual ~JtkXTGeometryFault( );

private:

   // equality operator
   int operator ==( const JtkXTGeometryFault &OtherFault ) const;
};

///////%{
//
// Class          : JtkXTSinglePointGeometryFault
//
// Description    : JtkXT single point geometry fault reporting class.
//                  This class derives from JtkXTGeomtryFault and contains
//                  a single point indicating the location of the geometric
//                  fault.
//
// Enums          :
//
// Includes       : JtkXTFaults.h
//
// Inheritance    : JtkXTGeometryFault > JtkXTSinglePointGeometryFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSinglePointGeometryFault: public JtkXTGeometryFault
{
   JTK_OBJECT_HEADER( JtkXTSinglePointGeometryFault )

   friend class _JtkXTSinglePointGeometryFault;

public:

   // accessor functions
   int getPoint( double*& xyz ) const;
   int getPoint( double& x, double &y, double& z ) const;

protected:

   //destruction
   virtual ~JtkXTSinglePointGeometryFault( );

private:

   //parameterized constructor
   JtkXTSinglePointGeometryFault( );

   // equality operator 
   int operator ==( const JtkXTSinglePointGeometryFault &OtherFault ) const;
};

///////%{
//
// Class          : JtkXTEntityFault
//
// Description    : JtkXT entity fault reporting class.  This class is the
//                  base class for all types of entity based faults.
//
// Enums          :
//
// Includes       : JtkXTFaults.h
//
// Inheritance    : JtkXTFault > JtkXTEntityFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTEntityFault: public JtkXTFault
{
   JTK_OBJECT_HEADER( JtkXTEntityFault )

public:

   // accessor functions
   int getPoint( double*& xyz ) const;
   int getPoint( double& x, double &y, double& z ) const;

protected:

   //parameterized constructor
   JtkXTEntityFault( );

   //destruction
   virtual ~JtkXTEntityFault();

private:

   // equality operator
   int operator ==( const JtkXTEntityFault &OtherFault ) const;
};

///////%{
//
// Class          : JtkXTSingleEntityFault
//
// Description    : JtkXT entity fault reporting class for single entities. 
//                  This may optionally contain a geometrical point to indicate
//                  the fault location.
//
// Enums          :
//
// Includes       : JtkXTFaults.h
//
// Inheritance    : JtkXTEntityFault > JtkXTSingleEntityFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTSingleEntityFault: public JtkXTEntityFault
{
   JTK_OBJECT_HEADER( JtkXTSingleEntityFault )

   friend class _JtkXTSingleEntityFault;

public:

   JtkXTEntity* getEntity( ) const;

protected:

   //destruction
   virtual ~JtkXTSingleEntityFault();

private:

   //parameterized constructor
   JtkXTSingleEntityFault( );

   // equality operator
   int operator ==( const JtkXTSingleEntityFault &OtherFault ) const;
};


///////%{
//
// Class          : JtkXTMultipleEntityFault
//
// Description    : JtkXT entity fault reporting class for multiple entities.  
//                  May also contain a geometrical point to indicate the fault location.
//
// Enums          :
//
// Includes       : JtkXTFaults.h
//
// Inheritance    : JtkXTEntityFault > JtkXTMultipleEntityFault
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTMultipleEntityFault: public JtkXTEntityFault
{
   JTK_OBJECT_HEADER( JtkXTMultipleEntityFault )

   friend class _JtkXTMultipleEntityFault;

public:

   int getPrimaryEntities( JtkEntityList*& entities ) const;

   int getSecondaryEntities( JtkEntityList*& entities ) const;

protected:

   //destruction
   virtual ~JtkXTMultipleEntityFault( );

private:

   //parameterized constructor
   JtkXTMultipleEntityFault( );

   // equality operator
   int operator ==( const JtkXTMultipleEntityFault &OtherFault ) const;
};

#endif
