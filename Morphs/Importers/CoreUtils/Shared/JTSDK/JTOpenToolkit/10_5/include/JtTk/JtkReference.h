////////////////////////////////////////////////////////////////////////////////
// Copyright 2007 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_REFERENCE_H
#define JTK_REFERENCE_H

#include <JtTk/JtkHierarchy.h>

// Forward class definitions
class _JtkReferenceLink;
class _JtkReference;

///////%{
//
// Class          : JtkReferenceLink
//
// Description    : Represents a single link in a reference chain.
//                  The <tt>JtkReferenceLink</tt> class represents a single link in a reference chain.
//                  If the Jtk node is in memory then its pointer (to a <tt>JtkHierarchy</tt> object)
//                  is available and any associated reference identifiers
//                  can be obtained automatically. If the node is not loaded
//                  then only the reference identifiers can be set by the user.
//                  If both the reference identifiers and the nodes are specified for a link
//                  then the reference identifiers defined on the node
//                  will override any specified explicitly on the link.
//
// Enums          : JtkAbsIdType
//                    JtkOCC_ABS_CONTEXT  -- Absolute occurrence context identifier
//
// Includes       : JtkReference.h
//
// Inheritance    : JtkEntity > JtkReferenceLink
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkReferenceLink : public JtkEntity
{
   JTK_OBJECT_TYPE_HEADER( JtkReferenceLink )

private:

   _JtkReferenceLink*   _impl;

   // constructor
   JtkReferenceLink( );

   // Copy Constructor
   JtkReferenceLink( const JtkReferenceLink& ReferenceLink );

    // assignment operator
   JtkReferenceLink &operator =( const JtkReferenceLink &OtherReferenceLink );

   // equality operator
   int operator           ==( const JtkReferenceLink &OtherReferenceLink )const;

   // destructor
   ~JtkReferenceLink();

public:

   friend class _JtkReference;

   int setNode( JtkHierarchy*  node );
   int getNode( JtkHierarchy*& node ) const;

   int setReferenceId( JtkHierarchy::JtkRefIdType type, const JtkString& Id );
   int getReferenceId( JtkHierarchy::JtkRefIdType type, JtkString& Id ) const;

   enum JtkAbsIdType
   {
      JtkABSID_UNKNOWN = 0,
      JtkOCC_ABS_CONTEXT
   };

   int setAbsoluteId( JtkAbsIdType type, const JtkString& Id );
   int getAbsoluteId( JtkAbsIdType& type, JtkString& Id ) const;
};

///////%{
//
// Class          : JtkReference
//
// Description    : Represents a chain of links in a reference.
//                  The <tt>JtkReference</tt> class represents the chain of links.
//                  <tt>JtkReferenceLink</tt> objects are managed by the <tt>JtkReference</tt> object
//                  through the <tt>addLink</tt> and <tt>getLink</tt> functions. <tt>addLink</tt> returns a pointer
//                  to an empty link for the user to set up.
//                  <tt>getPath</tt> returns the NGID string based on any links added by the user.
//                  The NGID string will be suitable for use in <tt>AddPMIAssociation</tt>.
//                  <tt>setPath</tt> will accept both NGID and CADID strings
//                  and automatically create the chain of links.
//                  Strings output by <tt>GetPMIAssociation</tt> are acceptable.
//
// Enums          :
//
// Includes       : JtkReference.h
//
// Inheritance    : JtkEntity > JtkReference
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkReference : public JtkEntity
{
   JTK_OBJECT_TYPE_HEADER( JtkReference )

private:
   
   friend class _JtkReference;

protected:

   _JtkReference*   _impl;

   // Copy Constructor
   JtkReference( const JtkReference& Reference );

   // Internal constructor
   JtkReference( _JtkReference* Impl );

public:

   // constructor
   JtkReference( );

   // destructor
   virtual ~JtkReference( );

   // assignment operator
   JtkReference &operator =( const JtkReference &OtherReference );

   // equality operator
   int operator            ==( const JtkReference &OtherReference )const;

   // Path - NGID occurrence specification
   int getPath( JtkString& Path ) const;
   int getPath( JtkEntityList*& Path ) const;

   int setPath( const JtkString& Path );
   int setPath( JtkEntityList* Path );

   // link interface
   int numLinks( ) const;
   int addLink( JtkReferenceLink*& Link );
   int getLink( int Index, JtkReferenceLink*& Link ) const;

   // resolve interface
   int resolve( JtkHierarchy* Context, JtkReferenceMap* ReferenceMap = NULL );

   // will get the node from the last link of the reference
   // provided the reference has been successfully resolved
   int getLastLinkNode(JtkHierarchy*& node) const;

   // utility functions
   virtual int isEmpty( ) const;
   virtual int clear( );
};

///////%{
//
// Class          : JtkPMIReference
//
// Description    : Represents a chain of links in a PMI reference. This class encapsulates
//                  the functionality of the <tt>PMIAttrAssociation</tt> structure.
//                  Instances of this class can be used with the <tt>AddPMIAssociation</tt> and
//                  <tt>GetPMIAssociation</tt> functionality provided in the <tt>JtkUnitHierarchy</tt>
//                  class.
//
// Enums          :
//
// Includes       : JtkReference.h
//
// Inheritance    : JtkReference > JtkPMIReference
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPMIReference : public JtkReference
{
   JTK_OBJECT_TYPE_HEADER( JtkPMIReference )

private:

   // equality operator
   int operator            ==( const JtkPMIReference &OtherPMIReference ) const;

   // Copy Constructor
   JtkPMIReference( const JtkPMIReference& PMIReference );

public:

   JtkPMIReference( );

   virtual ~JtkPMIReference( );

   // assignment operator
   JtkPMIReference &operator =( const JtkPMIReference &OtherPMIReference );

   // iSrcType & iDstType of PMIAttrAssociation
   int getEntityType( int& iType ) const;
   int setEntityType( int iType );

   // iSrcType & iDstType of PMIAttrAssociation
   int getEntityId( int& Id ) const;
   int setEntityId( int Id );

   // utility functions
   virtual int isEmpty( ) const;
   virtual int clear( );
};

/////////////////////////////////////////////////

#endif //! JTK_REFERENCE_H

