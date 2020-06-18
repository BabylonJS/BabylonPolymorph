////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_XT_FACE_HXX
#define JTK_XT_FACE_HXX

#include <JtTk/JtkXTTopology.h>

class JtkXTLoop;
class JtkXTSurface;

class JtkAttrib;
class JtkMaterial;
class JtkXTMaterial;
class JtkTexImage;
class JtkXTEntityMoniker;

class JtkTessParams;
class JtkTriStripSet;

///////%{
//
// Class          : JtkXTFace
//
// Description    : An object defining a face within XT topology.
//
// Enums          :
//
// Includes       : JtkXTFace.h
//
// Inheritance    : JtkXTTopology > JtkXTFace
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkXTFace : public JtkXTTopology
{
   JTK_OBJECT_HEADER( JtkXTFace )

public:
   // Brep hierarchy management methods
   virtual int    addChild( JtkXTLoop* loop, int &error ) = 0;
   virtual int    insertChild( JtkXTLoop* loop, int position, int &error ) = 0;
   virtual int    insertChild( JtkXTLoop* loop, JtkXTLoop* previous, int &error ) = 0;
   virtual int    getChild( JtkXTLoop* &loop, int index, int &error ) = 0;
   virtual int    deleteChild( int index, int &error ) = 0;
   virtual int    numChildren( int &error ) = 0;

   // Face attribute methods
   virtual int    setMaterial( JtkMaterial* material, int &error ) = 0;
   virtual int    getMaterial( JtkMaterial* &material, int &error ) = 0;

   virtual int    setTexImage( JtkTexImage* texImage, int &error ) = 0;
   virtual int    getTexImage( JtkTexImage* &texImage, int &error ) = 0;

   virtual int    addAttrib( JtkAttrib* attrib ) = 0;
   virtual int    deleteAttrib( int index,JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;
   virtual int    deleteAttrib( JtkAttrib* attrib ) = 0;
   virtual int    getAttrib( int index, JtkAttrib* & TheAttrib, JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;
   virtual int    numAttribs( JtkEntity::TypeID Type = JtkEntity::JtkNONE ) = 0;

   // Trimmed surface accessor methods.
   virtual int    setSurface( JtkXTSurface* surface, int &error ) = 0;
   virtual int    setSurface( JtkXTSurface* surface, int sense, int &error ) = 0;
   virtual int    getSurface( JtkXTSurface* &surface, int &error ) = 0;
   virtual int    getSurface( JtkXTSurface* &surface, int &sense, int &error ) = 0;
   virtual int    getUVBox( double &dU1, double &dV1, double &dU2, double &dV2,
                            int& nError ) = 0;
   virtual int    deleteSurface( int &error ) = 0;

   virtual int    findOuterLoop( JtkXTLoop* &loop, int &error ) = 0;

   virtual int    setEntityId( int EntityId, int& Error ) = 0;
   virtual int    getEntityId( int& EntityId, int& Error ) = 0;

   // Monikers related API
   virtual int    addEntityMoniker( JtkXTEntityMoniker* EntityMoniker ) = 0;
   virtual int    numEntityMonikers( ) = 0;
   virtual int    getEntityMoniker( JtkXTEntityMoniker*& EntityMoniker, int Index ) = 0;
   virtual int    deleteEntityMoniker( int Index ) = 0;

   // XT Attributes related API
   virtual int    setXTMaterial( JtkXTMaterial* xtMaterial, int &error ) = 0;
   virtual int    getXTMaterial( JtkXTMaterial* &xtMaterial, int &error ) = 0;
   
   // Static functions to allow setting and getting raw parasolid colors and JtkAttribs on XT faces,
   // when JtkXTFace is not present.
   static int     addAttrib( PK_FACE_t PkFace, JtkAttrib* Attrib, int &Error );
   static int     deleteAttrib(PK_FACE_t PkFace, int Index, int &Error, JtkEntity::TypeID Type = JtkEntity::JtkNONE);
   static int     deleteAttrib(PK_FACE_t PkFace, JtkAttrib* Attrib, int &Error);
   static int     getAttrib( PK_FACE_t PkFace, int Index, JtkAttrib* &Attrib, int &Error, JtkEntity::TypeID Type = JtkEntity::JtkNONE );
   static int     numAttribs( PK_FACE_t PkFace, int &Error, JtkEntity::TypeID Type = JtkEntity::JtkNONE );

   static int     setXTMaterial( PK_FACE_t Face, JtkXTMaterial* xtMaterial, int &error );
   static int     getXTMaterial( PK_FACE_t Face, JtkXTMaterial* &xtMaterial, int &error );

   
   virtual int    tessellate( const JtkTessParams* Params, JtkTriStripSet* &TessResult ) = 0;
   virtual int    tessellate( JtkUnits Units, const JtkTessParams* Params, JtkTriStripSet* &TessResult ) = 0;
   static int     tessellate( PK_FACE_t Face, const JtkTessParams* Params, JtkTriStripSet* &TessResult ); 
   static int     tessellate( JtkUnits Units, PK_FACE_t Face, const JtkTessParams* Params, JtkTriStripSet* &TessResult ); 

   int            operator == ( const JtkXTFace &rhs )const;

protected:
   JtkXTFace();
   virtual ~JtkXTFace();
};

#endif

