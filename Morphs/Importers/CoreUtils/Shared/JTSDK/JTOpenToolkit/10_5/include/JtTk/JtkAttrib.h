////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_ATTRIB_HXX
#define JTK_ATTRIB_HXX

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkShaderParam.h>
#include <JtTk/JtkReference.h>

class JtkEntityList;
class JtkPointLight;
class JtkInfiniteLight;
class JtkLight;
class JtkProperty;
class JtkTexImageDescription;
class JtkCrosshatchPattern;

///////%{
//
// Class          : JtkAttrib
//
// Description    : A base object for geometry attributes.
//
// Enums          : Scope
//                    JtkINHERITED -- The attribute will be added to the current node and
//                      those instances that do not already have an attribute of the same type.
//                      This is the default Scope value.
//                    JtkSHARED -- The attribute will be shared by the current node and all its instances.
//                    JtkINSTANCE -- The attribute will be added to the current node.
//
//                  JtkFieldInheritanceType
//                    JtkFIELD_INHERITANCE_NOCHANGE -- The attribute will not alter the current flags.
//                    JtkFIELD_INHERITANCE_UNSET -- Neither the inhibit nor the final flag will be set.
//                    JtkFIELD_INHERITANCE_SUPPRESS -- The inhibit flag for this attribute will be set.
//                    JtkFIELD_INHERITANCE_FINALIZE -- The final flag for this attribute will be set.
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkRefCounted > JtkAttrib
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkAttrib : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkAttrib )

public:
   enum Scope
   {
      JtkINHERITED = 0,
      JtkSHARED   = 1,
      JtkINSTANCE = 2
   };

   enum JtkFieldInheritanceType
   {
      JtkFIELD_INHERITANCE_NOCHANGE = 0,
      JtkFIELD_INHERITANCE_UNSET = 1,
      JtkFIELD_INHERITANCE_SUPPRESS = 2,
      JtkFIELD_INHERITANCE_FINALIZE = 3
   };

   int operator         ==( const JtkAttrib &OtherAttrib )const;

   // Basic ID APIs
   virtual JtkString name() = 0;
   virtual int   setName( const JtkString& ) = 0;
   //virtual int   getName( const JtkString& ) = 0;

   //scope
   virtual int   setScope( JtkAttrib::Scope ) = 0;
   virtual int   getScope( JtkAttrib::Scope & ) = 0 ;


   // Property APIs
   virtual int addProp( JtkProperty* ) = 0;
   virtual int getProp( const JtkString&  Key,
                        JtkProperty* &p1 ) = 0;
   virtual int getProp( int          Index,
                        JtkString&        Key,
                        JtkProperty* &p1 ) = 0;
   virtual int numProps( int &numOfProps ) = 0;
   virtual int deleteProp( const JtkString& Key ) = 0;
   virtual int deleteProp( int Index ) = 0;

protected:
   JtkAttrib();
   virtual  ~JtkAttrib();
};

///////%{
//
// Class          : JtkMaterial
//
// Description    : An attribute object through which colors may be defined and
//                  added to a model.
//
// Enums          :
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkMaterial
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkMaterial : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkMaterial )

public:

   // Material primitives accessor methods.
   virtual int             setAmbientColor( float *ambient, JtkAttrib::JtkFieldInheritanceType inheritanceType = JtkAttrib::JtkFIELD_INHERITANCE_NOCHANGE ) = 0;
   virtual int             getAmbientColor( float * &ambient, JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getAmbientColor( JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getAmbientColor(float * &ambient ) = 0;
   
   virtual int             setDiffuseColor( float *diffuse, JtkAttrib::JtkFieldInheritanceType colorInheritanceType = JtkAttrib::JtkFIELD_INHERITANCE_NOCHANGE, 
                                                           JtkAttrib::JtkFieldInheritanceType alphaInheritanceType = JtkAttrib::JtkFIELD_INHERITANCE_NOCHANGE ) = 0;
   virtual int             getDiffuseColor( float * &diffuse, JtkAttrib::JtkFieldInheritanceType &colorInheritanceType, 
                                                              JtkAttrib::JtkFieldInheritanceType &alphaInheritanceType ) = 0;
   virtual int             getDiffuseColor( JtkAttrib::JtkFieldInheritanceType &colorInheritanceType, 
                                            JtkAttrib::JtkFieldInheritanceType &alphaInheritanceType ) = 0;
   virtual int             getDiffuseColor( float * &diffuse ) = 0;
   
   virtual int             setSpecularColor( float *specular, JtkAttrib::JtkFieldInheritanceType inheritanceType = JtkAttrib::JtkFIELD_INHERITANCE_NOCHANGE ) = 0;
   virtual int             getSpecularColor( float * &specular, JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getSpecularColor( JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getSpecularColor( float * &specular ) = 0;
   
   virtual int             setEmissionColor( float *emission, JtkAttrib::JtkFieldInheritanceType inheritanceType = JtkAttrib::JtkFIELD_INHERITANCE_NOCHANGE ) = 0;
   virtual int             getEmissionColor( float * &emission, JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getEmissionColor( JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getEmissionColor( float * &emission ) = 0;
  
   virtual int             setShininess( float shininess ) = 0;
   virtual int             getShininess( float &shininess ) = 0;
  
   virtual int             setBumpiness( float bumpiness, JtkAttrib::JtkFieldInheritanceType inheritanceType = JtkAttrib::JtkFIELD_INHERITANCE_NOCHANGE ) = 0;
   virtual int             getBumpiness( float &bumpiness, JtkAttrib::JtkFieldInheritanceType &inheritanceType) = 0;
   virtual int             getBumpiness( JtkAttrib::JtkFieldInheritanceType &inheritanceType ) = 0;
   virtual int             getBumpiness( float &bumpiness ) = 0;

   // Material Overrides
   virtual int             setOverride( JtkEntityList* PathToDestNode ) = 0;
   virtual int             getOverride( JtkEntityList* &PathToDestNode ) = 0;

   virtual int             setOverride( const JtkReference& PathToDestNode ) = 0;
   virtual int             getOverride( JtkReference& PathToDestNode, int resolve = Jtk_OK ) = 0;

   //crosshatch pattern used to represent material
   virtual int             setPattern( JtkCrosshatchPattern* Pattern ) = 0;
   virtual int             getPattern( JtkCrosshatchPattern*& Pattern ) = 0;

   int operator            ==( const JtkMaterial &OtherMaterial )const;

protected:
   //Constructors and Destructors
   JtkMaterial();
   virtual  ~JtkMaterial();
};

///////%{
//
// Class          : JtkTransform
//
// Description    : An attribute object through which transformation matrices
//                  may be defined and added to a model.
//
// Enums          : AxisID
//                     JtkX -- The 'x' axis.
//                     JtkY -- The 'y' axis.
//                     JtkZ -- The 'z' axis.
//
//                  AngleType
//                     JtkRADIANS -- Angles are radians.
//                     JtkDEGREES -- Angles are degrees.
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkTransform
//
// Visibility     : public
//
/////////%}
class JTK_TOOLKIT_API JtkTransform : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkTransform )

public:
   enum AxisID
   {
      JtkX,
      JtkY,
      JtkZ
   };
   enum AngleType
   {
      JtkRADIANS,
      JtkDEGREES
   };

   virtual int setTElements( float* valarray ) = 0;
   virtual int setTElements( double* valarray ) = 0;
   virtual int getTElements( float* &valarray ) = 0;
   virtual int getTElements( double* &valarray ) = 0;
   virtual int rotate( AxisID axis, AngleType angle, float amount ) = 0;
   virtual int rotate( AxisID axis, AngleType angle, double amount ) = 0;
   virtual int scale( float ) = 0;
   virtual int scale( double ) = 0;
   virtual int translate( float, float, float ) = 0;
   virtual int translate( double, double, double ) = 0;
   virtual int determinant( float &result ) = 0;
   virtual int determinant( double &result ) = 0;

   int operator==( const JtkTransform &OtherXform )const;
   JtkTransform& operator*=( const JtkTransform &OtherXform );
   JtkTransform& operator+=( const JtkTransform &OtherXform );
   JtkTransform& operator-=( const JtkTransform &OtherXform );

   JtkTransform &operator*( const JtkTransform &OtherXform );
   JtkTransform &operator+( const JtkTransform &OtherXform );
   JtkTransform &operator-( const JtkTransform &OtherXform );
  
   virtual JtkTransform* createInverse( ) const = 0;
  
protected:
   JtkTransform();
   virtual~JtkTransform();
};

///////%{
//
// Class          : JtkLight
//
// Description    : An attribute object through which JtkLight-derived lights
//                  may be adding to a model. Base class for all toolkit light
//                  source classes (JtkInfiniteLight and JtkPointLight).
//
// Enums          : JtkLightCoordSys
//                    JtkLIGHTCOORDS_NONE -- Undefined coordinates
//                    JtkLIGHTCOORDS_VPCS -- ViewPOINT coordinates
//                    JtkLIGHTCOORDS_MCS -- Model coordinates
//                    JtkLIGHTCOORDS_WCS -- World coordinates
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkLight
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkLight : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkLight )

public:
   virtual int setAmbientColor( float* ambient ) = 0;
   virtual int getAmbientColor( float* &ambient ) = 0;
   virtual int setDiffuseColor( float* diffuse ) = 0;
   virtual int getDiffuseColor( float* &diffuse ) = 0;
   virtual int setSpecularColor( float* specular ) = 0;
   virtual int getSpecularColor( float* &specular ) = 0;
   virtual int setBrightness( float brightness ) = 0;
   virtual int getBrightness( float &brightness ) = 0;
   enum JtkLightCoordSys
   {
      JtkLIGHTCOORDS_NONE    = 0,   // Undefined coordinates
      JtkLIGHTCOORDS_VPCS    = 1,   // ViewPOINT coordinates
      JtkLIGHTCOORDS_MCS     = 2,   // Model coordinates
      JtkLIGHTCOORDS_WCS     = 3   // World coordinates
   };
   virtual int setCoordSys( JtkLightCoordSys  ) = 0;
   virtual int getCoordSys( JtkLightCoordSys& ) = 0;

   int operator            ==( const JtkLight &OtherLight )const;

protected:
   JtkLight();
   virtual        ~JtkLight();
};


///////%{
//
// Class          : JtkInfiniteLight
//
// Description    : Toolkit class for an infinite light source defined by
//                  direction, ambient color, diffuse color, specular color,
//                  and brightness.
//
// Enums          :
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkLight > JtkInfiniteLight
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkInfiniteLight : public JtkLight
{
   JTK_OBJECT_HEADER( JtkInfiniteLight )

public:
   virtual int setDirection( float* direction ) = 0;
   virtual int getDirection( float* &direction ) = 0;

   int operator            ==( const JtkInfiniteLight &OtherLight )const;

protected:
   JtkInfiniteLight();
   virtual     ~JtkInfiniteLight();
};

///////%{
//
// Class          : JtkPointLight
//
// Description    : Toolkit class for a point light source defined by
//                  position, angle, attenuation, spot intensity, spot
//                  direction,  ambient color, diffuse color, specular
//                  color, and brightness.
//
// Enums          :
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkLight > JtkPointLight
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkPointLight : public JtkLight
{
   JTK_OBJECT_HEADER( JtkPointLight )

public:
   virtual int setPosition( float* position ) = 0;
   virtual int getPosition( float* &position ) = 0;
   virtual int setAngle( float angle ) = 0;
   virtual int getAngle( float &angle ) = 0;
   virtual int setAttenuation( float* attenuation ) = 0;
   virtual int getAttenuation( float* &attenuation ) = 0;
   virtual int setSpotIntensity( int intensity ) = 0;
   virtual int getSpotIntensity( int &intensity ) = 0;
   virtual int setSpotDirection( float* direction ) = 0;
   virtual int getSpotDirection( float* &direction ) = 0;

   int operator            ==( const JtkPointLight &OtherLight )const;

protected:
   JtkPointLight();
   virtual     ~JtkPointLight();
};

///////%{
//
// Class          : JtkTexImage
//
// Description    : An attribute object through which textures may be defined
//                  and added to a model.
//
// Enums          : JtkTexWrapMode
//                     JtkTEXWRAP_NONE --
//                     JtkTEXWRAP_CLAMP --
//                     JtkTEXWRAP_REPEAT --
//                     JtkTEXWRAP_MIRRORED_REPEAT --
//                     JtkTEXWRAP_CLAMP_TO_EDGE --
//                     JtkTEXWRAP_CLAMP_TO_BORDER --
//
//                  JtkTexBlendType
//                     JtkTEXBLEND_NONE --
//                     JtkTEXBLEND_DECAL --
//                     JtkTEXBLEND_MODULATE --
//                     JtkTEXBLEND_REPLACE --
//                     JtkTEXBLEND_BLEND --
//                     JtkTEXBLEND_ADD --
//                     JtkTEXBLEND_COMBINE --
//
//                  JtkTexFilterType
//                     JtkTEXFILTER_NONE --
//                     JtkTEXFILTER_NEAREST --
//                     JtkTEXFILTER_LINEAR --
//                     JtkTEXFILTER_NEAREST_IN_MIP --
//                     JtkTEXFILTER_LINEAR_IN_MIP --
//                     JtkTEXFILTER_NEAREST_BTWN_MIP --
//                     JtkTEXFILTER_LINEAR_BTWN_MIP --
//
//                  JtkTexType
//                     JtkTEXTYPE_NONE --
//                     JtkTEXTYPE_1D -- (Deprecated, use JtkTEXTYPE_IMAGE_1D_POST instead)
//                     JtkTEXTYPE_2D -- (Deprecated, use JtkTEXTYPE_IMAGE_2D_POST instead)
//                     JtkTEXTYPE_BUMPMAP -- (Deprecated, use JtkTEXTYPE_NORMALMAP_TAN instead)
//                     JtkTEXTYPE_CUBEMAP -- (Deprecated, use JtkTEXTYPE_IMAGE_CUBE_POST instead)
//                     JtkTEXTYPE_DEPTHMAP --
//                     JtkTEXTYPE_IMAGE_1D_POST --
//                     JtkTEXTYPE_IMAGE_2D_POST --
//                     JtkTEXTYPE_IMAGE_3D_POST --
//                     JtkTEXTYPE_NORMALMAP_TAN --
//                     JtkTEXTYPE_IMAGE_CUBE_POST --
//                     JtkTEXTYPE_IMAGE_CUBE_PRE --
//                     JtkTEXTYPE_IMAGE_1D_PRE --
//                     JtkTEXTYPE_IMAGE_2D_PRE --
//                     JtkTEXTYPE_IMAGE_3D_PRE --
//                     JtkTEXTYPE_ENVMAP_CUBE --
//                     JtkTEXTYPE_GLOSSMAP_1D --
//                     JtkTEXTYPE_GLOSSMAP_2D --
//                     JtkTEXTYPE_GLOSSMAP_3D --
//                     JtkTEXTYPE_GLOSSMAP_CUBE --
//                     JtkTEXTYPE_BUMPMAP_HEIGHT --
//                     JtkTEXTYPE_NORMALMAP_WCS --
//                     JtkTEXTYPE_ENVMAP_SPHERE --
//                     JtkTEXTYPE_ENVMAP_LATLONG --
//                     JtkTEXTYPE_LMAP_SPHERE_DIFF --
//                     JtkTEXTYPE_LMAP_CUBE_DIFF --
//                     JtkTEXTYPE_LMAP_LATLONG_DIFF --
//                     JtkTEXTYPE_LMAP_SPHERE_SPEC --
//                     JtkTEXTYPE_LMAP_CUBE_SPEC --
//                     JtkTEXTYPE_LMAP_LATLONG_SPEC --
//                     JtkTEXTYPE_SEPARATOR --
//
//                  JtkTexBorderMode
//                     JtkTEXBORDER_NONE --
//                     JtkTEXBORDER_CONSTANT --
//                     JtkTEXBORDER_EXPLICIT --
//
//                  JtkTexCoordGenCoord
//                     JtkTEXCOORTGENCOORD_NONE --
//                     JtkTEXCOORDGENCOORD_S --
//                     JtkTEXCOORDGENCOORD_T --
//                     JtkTEXCOORDGENCOORD_R --
//                     JtkTEXCOORDGENCOORD_Q --
//
//                  JtkTexCoordGenMode
//                     JtkTEXCOORDGENMODE_NONE --
//                     JtkTEXCOORDGENMODE_MCS_LINEAR --
//                     JtkTEXCOORDGENMODE_VCS_LINEAR --
//                     JtkTEXCOORDGENMODE_SPHERE_MAP --
//                     JtkTEXCOORDGENMODE_REFLECTION_MAP --
//                     JtkTEXCOORDGENMODE_NORMAL_MAP --
//
//                 JtkTexImageNamePersistence
//                   JtkTEXIMAGENAME_VERBATIM -- Will persist exactly as supplied.
//                   JtkTEXIMAGENAME_NAME_ONLY -- Remove any path from the persistence and only write the name of the file.
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkTexImage
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTexImage : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkTexImage )

public:
   // TexImage primitives accessor methods.
   virtual void   setImageData( void**  ) = 0;
   virtual int    setImageData( const JtkTexImageDescription* ) =0;
   virtual int    getImageData( JtkTexImageDescription* ) =0;
   virtual void   getImageDataSize( int & ) = 0;
   virtual void   setImageAttributes( int , int ) = 0;
   virtual void   getImageAttributes( int &, int & ) = 0;

   virtual void   setMatrix( float*  ) = 0;
   virtual void   getMatrix( float* & ) = 0;
   virtual void   setTranslation( float*  ) = 0;
   virtual void   getTranslation( float* & ) = 0;
   virtual void   setRotation( float  ) = 0;
   virtual void   getRotation( float & ) = 0;
   virtual void   setScale( float* ) = 0;
   virtual void   getScale( float* & ) = 0;
   virtual void   setCenter( float* ) = 0;
   virtual void   getCenter( float* & ) = 0;

   virtual void   useMipmap( short ) = 0;
   virtual void   getUseMipmap( short & ) = 0;
   virtual void   useEnvironmentMapping( short ) = 0;
   virtual void   getUseEnvironmentMapping( short & ) = 0;

   // TEXDATA_TYPE_NONE   = 0;
   // TEXDATA_TYPE_BYTE   = 1;
   // TEXDATA_TYPE_FLOAT  = 2;
   virtual void   setImageDataType( int ) = 0;
   virtual void   getImageDataType( int & ) = 0;

   // TEXFMT_NONE = 0;
   // TEXFMT_RGB  = 1;
   // TEXFMT_RGBA = 2;
   virtual void   setImageFormat( int ) = 0;
   virtual void   getImageFormat( int &) = 0;

   enum JtkTexWrapMode
   {
      JtkTEXWRAP_NONE = 0,
      JtkTEXWRAP_CLAMP = 1,
      JtkTEXWRAP_REPEAT = 2,
      JtkTEXWRAP_MIRRORED_REPEAT = 3,
      JtkTEXWRAP_CLAMP_TO_EDGE = 4,
      JtkTEXWRAP_CLAMP_TO_BORDER = 5
   };
   virtual int   setWrapMode( JtkTexWrapMode WrapS, JtkTexWrapMode WrapT,
                              JtkTexWrapMode WrapR = JtkTEXWRAP_REPEAT ) = 0;
   virtual int   getWrapMode( JtkTexWrapMode &WrapS,
                              JtkTexWrapMode &WrapT,
                              JtkTexWrapMode &WrapR ) = 0;

   enum JtkTexBlendType
   {
      JtkTEXBLEND_NONE = 0,
      JtkTEXBLEND_DECAL = 1,
      JtkTEXBLEND_MODULATE = 2,
      JtkTEXBLEND_REPLACE = 3,
      JtkTEXBLEND_BLEND = 4,
      JtkTEXBLEND_ADD = 5,
      JtkTEXBLEND_COMBINE = 6
   };
   virtual int   setBlending( JtkTexBlendType ) = 0;
   virtual int   getBlending( JtkTexBlendType & ) = 0;
   virtual int   setBlendColor( const float Color[4] ) = 0;
   virtual int   getBlendColor( float Color[4] ) = 0;

   enum JtkTexFilterType
   {
      JtkTEXFILTER_NONE = 0,
      JtkTEXFILTER_NEAREST = 1,
      JtkTEXFILTER_LINEAR = 2,
      JtkTEXFILTER_NEAREST_IN_MIP = 3,
      JtkTEXFILTER_LINEAR_IN_MIP = 4,
      JtkTEXFILTER_NEAREST_BTWN_MIP = 5,
      JtkTEXFILTER_LINEAR_BTWN_MIP = 6
   };
   virtual int   setFilterType( JtkTexFilterType, JtkTexFilterType ) = 0;
   virtual int   getFilterType( JtkTexFilterType &, JtkTexFilterType & ) = 0;

   //new APIs for GM management project
   enum JtkTexType
   {
      JtkTEXTYPE_NONE              =  0,

      JtkTEXTYPE_IMAGE_1D_POST     =  1,

      JtkTEXTYPE_IMAGE_2D_POST     =  2,

      JtkTEXTYPE_IMAGE_3D_POST     =  3,
      JtkTEXTYPE_NORMALMAP_TAN     =  4,
      JtkTEXTYPE_IMAGE_CUBE_POST   =  5,

      JtkTEXTYPE_DEPTHMAP          =  6,

      JtkTEXTYPE_IMAGE_CUBE_PRE    =  7,
      JtkTEXTYPE_IMAGE_1D_PRE      =  8,
      JtkTEXTYPE_IMAGE_2D_PRE      =  9,
      JtkTEXTYPE_IMAGE_3D_PRE      = 10,
      JtkTEXTYPE_ENVMAP_CUBE       = 11,
      JtkTEXTYPE_GLOSSMAP_1D       = 12,
      JtkTEXTYPE_GLOSSMAP_2D       = 13,
      JtkTEXTYPE_GLOSSMAP_3D       = 14,
      JtkTEXTYPE_GLOSSMAP_CUBE     = 15,
      JtkTEXTYPE_BUMPMAP_HEIGHT    = 16,
      JtkTEXTYPE_NORMALMAP_WCS     = 17,
      JtkTEXTYPE_ENVMAP_SPHERE     = 18,
      JtkTEXTYPE_ENVMAP_LATLONG    = 19,
      JtkTEXTYPE_LMAP_SPHERE_DIFF  = 20,
      JtkTEXTYPE_LMAP_CUBE_DIFF    = 21,
      JtkTEXTYPE_LMAP_LATLONG_DIFF = 22,
      JtkTEXTYPE_LMAP_SPHERE_SPEC  = 23,
      JtkTEXTYPE_LMAP_CUBE_SPEC    = 24,
      JtkTEXTYPE_LMAP_LATLONG_SPEC = 25,

      JtkTEXTYPE_SEPARATOR         = 26
   };
// These enums are replaced as of JtTk 5.1 but
// use a define to make sure the older versions are
// supported. These will be deprecated in the future.
#define JtkTEXTYPE_1D JtkTEXTYPE_IMAGE_1D_POST
#define JtkTEXTYPE_2D JtkTEXTYPE_IMAGE_2D_POST
#define JtkTEXTYPE_3D JtkTEXTYPE_IMAGE_3D_POST
#define JtkTEXTYPE_BUMPMAP JtkTEXTYPE_NORMALMAP_TAN
#define JtkTEXTYPE_CUBEMAP JtkTEXTYPE_IMAGE_CUBE_POST

   virtual int getTextureType( JtkTexType & ) = 0;
   virtual int setTextureChannel( int ) = 0;
   virtual int getTextureChannel( int & ) =0;

   enum JtkTexBorderMode
   {
      JtkTEXBORDER_NONE = 0,
      JtkTEXBORDER_CONSTANT = 1,
      JtkTEXBORDER_EXPLICIT = 2
   };
   virtual int setBorderMode( JtkTexBorderMode ) = 0;
   virtual int getBorderMode( JtkTexBorderMode & ) =0;
   virtual int setBorderColor( const float Color[4] ) = 0;
   virtual int getBorderColor( float Color[4] ) =0;

   enum JtkTexImageNamePersistence
   {
      JtkTEXIMAGENAME_VERBATIM = 0,
      JtkTEXIMAGENAME_NAME_ONLY = 1
   };

   virtual int setImageFileName( const JtkString& FileName, JtkTexImageNamePersistence Persistence = JtkTEXIMAGENAME_VERBATIM ) =0;
   virtual int getImageFileName( JtkString&  ) =0; 

   virtual int setCubeMapImageFileNames( const JtkString& FileName_PlusX,
                                         const JtkString& FileName_PlusY,
                                         const JtkString& FileName_PlusZ,
                                         const JtkString& FileName_NegX,
                                         const JtkString& FileName_NegY,
                                         const JtkString& FileName_NegZ,
                                         JtkTexImageNamePersistence Persistence = JtkTEXIMAGENAME_VERBATIM ) = 0;
   virtual int getCubeMapImageFileNames( JtkString&  FileName_PlusX,
                                         JtkString&  FileName_PlusY,
                                         JtkString&  FileName_PlusZ,
                                         JtkString&  FileName_NegX,
                                         JtkString&  FileName_NegY,
                                         JtkString&  FileName_NegZ ) = 0;

   enum JtkTexCoordGenCoord
   {
      JtkTEXCOORTGENCOORD_NONE = 0,
      JtkTEXCOORDGENCOORD_S = 1,
      JtkTEXCOORDGENCOORD_T = 2,
      JtkTEXCOORDGENCOORD_R = 3,
      JtkTEXCOORDGENCOORD_Q = 4
   };
   enum JtkTexCoordGenMode
   {
      JtkTEXCOORDGENMODE_NONE = 0,
      JtkTEXCOORDGENMODE_MCS_LINEAR = 1,
      JtkTEXCOORDGENMODE_VCS_LINEAR = 2,
      JtkTEXCOORDGENMODE_SPHERE_MAP = 3,
      JtkTEXCOORDGENMODE_REFLECTION_MAP = 4,
      JtkTEXCOORDGENMODE_NORMAL_MAP = 5
   };
   virtual int setTexCoordGenParams( JtkTexCoordGenCoord ,
                                     JtkTexCoordGenMode ,
                                     const float        Params[4] ) = 0;
   virtual int getTexCoordGenParams( JtkTexCoordGenCoord ,
                                     JtkTexCoordGenMode & ,
                                     float  Params[4] ) = 0;
   virtual int setCubeMapImageData( const JtkTexImageDescription* ,
                                    const JtkTexImageDescription* ,
                                    const JtkTexImageDescription* ,
                                    const JtkTexImageDescription* ,
                                    const JtkTexImageDescription* ,
                                    const JtkTexImageDescription*  ) =0;
   virtual int getCubeMapImageData( JtkTexImageDescription* ,
                                    JtkTexImageDescription* ,
                                    JtkTexImageDescription* ,
                                    JtkTexImageDescription* ,
                                    JtkTexImageDescription* ,
                                    JtkTexImageDescription*  ) =0;

   int operator            ==( const JtkTexImage &OtherTexture )const;

protected:
   //Constructors and Destructors
   JtkTexImage();
   virtual        ~JtkTexImage();
};


///////%{
//
// Class          : JtkImageStamp
//
// Description    : An attribute object through which Image stamps may be
//                  defined and added to a model.
//
// Enums          : JtkScreenPosition
//                     JtkSCREENPOSITION_TOP_LEFT --
//                     JtkSCREENPOSITION_TOP_CENTER --
//                     JtkSCREENPOSITION_TOP_RIGHT --
//                     JtkSCREENPOSITION_MID_LEFT --
//                     JtkSCREENPOSITION_MID_CENTER --
//                     JtkSCREENPOSITION_MID_RIGHT --
//                     JtkSCREENPOSITION_BOTTOM_LEFT --
//                     JtkSCREENPOSITION_BOTTOM_CENTER --
//                     JtkSCREENPOSITION_BOTTOM_RIGHT -
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkImageStamp
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkImageStamp : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkImageStamp )

public:
   enum JtkScreenPosition
   {
      JtkSCREENPOSITION_TOP_LEFT = 1,
      JtkSCREENPOSITION_TOP_CENTER = 2,
      JtkSCREENPOSITION_TOP_RIGHT = 3,
      JtkSCREENPOSITION_MID_LEFT = 4,
      JtkSCREENPOSITION_MID_CENTER = 5,
      JtkSCREENPOSITION_MID_RIGHT = 6,
      JtkSCREENPOSITION_BOTTOM_LEFT = 7,
      JtkSCREENPOSITION_BOTTOM_CENTER = 8,
      JtkSCREENPOSITION_BOTTOM_RIGHT = 9
   };

   virtual int getDPI( int &nXDPI, int &nYDPI ) = 0;
   virtual int setDPI( int nXDPI, int nYDPI ) = 0;

   virtual int getScreenPosition( JtkScreenPosition &nPosition ) = 0;
   virtual int setScreenPosition( JtkScreenPosition nPosition ) = 0;

   int operator              ==( const JtkImageStamp &OtherImage )const;

protected:
   JtkImageStamp();
   virtual ~JtkImageStamp();
};

///////%{
//
// Class          : JtkTexImageDescription
//
// Description    : An attribute object through which textures may be defined
//                  and added to a model.
//
// Enums          : JtkPixelDataType
//                     JtkPXLDATA_TYPE_NONE --
//                     JtkPXLDATA_TYPE_BYTE --
//                     JtkPXLDATA_TYPE_FLOAT --
//                     JtkPXLDATA_TYPE_UNSIGNED_BYTE --
//                     JtkPXLDATA_TYPE_BITMAP --
//                     JtkPXLDATA_TYPE_UNSIGNED_SHORT --
//                     JtkPXLDATA_TYPE_SHORT --
//                     JtkPXLDATA_TYPE_UNSIGNED_INT --
//                     JtkPXLDATA_TYPE_INT --
//
//                  JtkPixelFormat
//                     JtkPXLFMT_NONE --
//                     JtkPXLFMT_RGB --
//                     JtkPXLFMT_RGBA --
//                     JtkPXLFMT_LUM --
//                     JtkPXLFMT_LUMA --
//                     JtkPXLFMT_STENCIL_INDEX --
//                     JtkPXLFMT_DEPTH_COMPONENT --
//                     JtkPXLFMT_RED --
//                     JtkPXLFMT_GREEN --
//                     JtkPXLFMT_BLUE --
//                     JtkPXLFMT_ALPHA --
//                     JtkPXLFMT_BGR --
//                     JtkPXLFMT_BGRA --
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkRefCounted > JtkTexImageDescription
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTexImageDescription : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkTexImageDescription )

public:
   virtual int setShareImageFlag( int ) = 0;
   virtual int getShareImageFlag( int & ) = 0;
   virtual int setNumBorderPixels( int ) = 0;
   virtual int getNumBorderPixels( int & )  = 0;
   virtual int setRowAlignment( int ) = 0;
   virtual int getRowAlignment( int & ) = 0;
   enum JtkPixelDataType
   {
      JtkPXLDATA_TYPE_NONE = 0,
      JtkPXLDATA_TYPE_BYTE = 1,
      JtkPXLDATA_TYPE_FLOAT = 2,
      JtkPXLDATA_TYPE_UNSIGNED_BYTE = 3,
      JtkPXLDATA_TYPE_BITMAP = 4,
      JtkPXLDATA_TYPE_UNSIGNED_SHORT = 5,
      JtkPXLDATA_TYPE_SHORT = 6,
      JtkPXLDATA_TYPE_UNSIGNED_INT = 7,
      JtkPXLDATA_TYPE_INT = 8
   };
   enum JtkPixelFormat
   {
      JtkPXLFMT_NONE = 0,
      JtkPXLFMT_RGB = 1,
      JtkPXLFMT_RGBA = 2,
      JtkPXLFMT_LUM = 3,
      JtkPXLFMT_LUMA = 4,
      JtkPXLFMT_STENCIL_INDEX = 5,
      JtkPXLFMT_DEPTH_COMPONENT = 6,
      JtkPXLFMT_RED = 7,
      JtkPXLFMT_GREEN = 8,
      JtkPXLFMT_BLUE = 9,
      JtkPXLFMT_ALPHA = 10,
      JtkPXLFMT_BGR = 11,
      JtkPXLFMT_BGRA = 12
   };
   virtual int setPixelParameters( JtkPixelDataType ,
                                   JtkPixelFormat ) = 0;
   virtual int getPixelParameters( JtkPixelDataType &,
                                   JtkPixelFormat & ) = 0;
   virtual int setImageDimensions( int NumDimensions,
                                   int X_size,
                                   int Y_size = 1,
                                   int Z_size = 1 ) = 0;
   virtual int getImageDimensions( int & NumDimensions ,
                                   int & X_size,
                                   int & Y_size,
                                   int & Z_size ) =0;
   virtual int setNumMipMaps( int ) = 0;
   virtual int getNumMipMaps( int & ) = 0;
   virtual int setImageDataPtr( int,  const void* ) =0;
   virtual int getImageDataPtr( int,  void* & ) = 0;

protected:
   //Constructors and Destructors
   JtkTexImageDescription();
   virtual        ~JtkTexImageDescription();
};

///////%{
//
// Class          : JtkShader
//
// Description    : Toolkit class for shader attributes.
//
// Enums          : JtkShaderType
//                     JtkVERTEX_SHADER --
//                     JtkFRAGMENT_SHADER --
//
//                  JtkShaderLanguage
//                     JtkSHADERLANG_CG -- CG shading language
//                     JtkSHADERLANG_GLSL -- GLSL shading language
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkShader
//
// Visibility     : public
//
// Theory         :
//
// Special_Status : deprecated
//
/////////%}
class JTK_TOOLKIT_API JtkShader : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkShader )

public:
   enum JtkShaderType
   {
      JtkVERTEX_SHADER = 1,
      JtkFRAGMENT_SHADER = 2
   };

   enum JtkShaderLanguage
   {
      JtkSHADERLANG_CG = 1,
      JtkSHADERLANG_GLSL = 2
   };

   virtual int getShaderType( JtkShaderType &) = 0;
   
   virtual int getProgramSource( JtkString& SourceCode ) = 0;
   virtual int setProgramSource( const JtkString& SourceCode ) = 0;
   virtual int getProgramLocation( JtkString& FileName ) = 0;
   virtual int setProgramLocation( const JtkString& FileName ) = 0;
   
   virtual int getProgramSource( JtkShaderLanguage &,
                                 JtkString&             SourceCode ) = 0;
   virtual int setProgramSource( JtkShaderLanguage,
                                 const JtkString&        SourceCode ) = 0;
   virtual int getProgramLocation( JtkShaderLanguage &,
                                   JtkString&             FileName ) = 0;
   virtual int setProgramLocation( JtkShaderLanguage ,
                                   const JtkString&        FileName ) = 0;


   virtual int addParameter( const JtkString&             ParamName,
                             const JtkShaderParam*   ) = 0;
   virtual int getParameter( int             Index,
                             JtkString&           ParamName,
                             JtkShaderParam* & ) =0;
   virtual int numParameters( int & ) = 0;

protected:
   JtkShader();
   virtual ~JtkShader();
};

///////%{
//
// Class          : JtkShaderEffects
//
// Description    : Toolkit class for shader effects.
//
// Enums          : JtkBumpMapNormalInterp
//                     JtkTANGENT_SPACE --
//                     JtkOBJECT_SPACE --
//
// Includes       : JtkAttrib.h
//
// Inheritance    : JtkAttrib > JtkShaderEffects
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkShaderEffects : public JtkAttrib
{
   JTK_OBJECT_HEADER( JtkShaderEffects )

public:
   enum JtkBumpMapNormalInterp
   {
      JtkTANGENT_SPACE = 0,
      JtkOBJECT_SPACE = 1
   };

   virtual int getEnvMap( int    &Channel,
                          float  &Reflectivity ) = 0;
   virtual int setEnvMap( int     Channel,
                          float   Reflectivity ) = 0;
   virtual int getBumpMap( int                     &Channel,
                           JtkBumpMapNormalInterp  &,
                           float                   &Bumpiness ) = 0;
   virtual int setBumpMap( int                      Channel,
                           JtkBumpMapNormalInterp,
                           float                    Bumpiness ) = 0;
   virtual int getPhongShading( int  &TrueFalse ) = 0;
   virtual int setPhongShading( int   TrueFalse ) = 0;

protected:
   JtkShaderEffects();
   virtual ~JtkShaderEffects();
};

#endif //JTK_ATTRIB_HXX

