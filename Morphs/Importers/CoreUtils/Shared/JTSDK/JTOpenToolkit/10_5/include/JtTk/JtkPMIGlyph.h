////////////////////////////////////////////////////////////////////////////////
// Copyright 2009 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_PMI_FONT_H
#define JTK_PMI_FONT_H


#include <JtTk/JtkEntity.h>

//forward decs
class JtkPMIGlyph;
class _JtkPMIGlyphImpl;
class _JtkPMIGlyphSetTableImpl;
///////%{
//
// Class          : JtkPMIGlyphSetTable
//
// Description    : Class for interaction with GlyphSets. 
//                  GlyphSets are sets of paired integer and PolygonData used to 
//                  represent filled characters in PMI annotation.
//
// Enums          :
//
// Includes       : JtkPMIGlyph.h
//
// Inheritance    : JtkPMIGlyphSetTable
//
// Visibility     : public
//
// Theory         : 
//
/////////%}
class JTK_TOOLKIT_API JtkPMIGlyphSetTable
{
    friend class JtkEntityFactory;
    friend class _JtkUnitHierarchy;
   
private:
    JtkPMIGlyphSetTable();
    ~JtkPMIGlyphSetTable();

    static void init( );
    static void fini( );

public:

    static int numGlyphSets( int& nGlyphSets, int** iFonts = NULL ); 

    static int addGlyphSet( const JtkString& sUID, int nChars, int* iChars, JtkPMIGlyph** glyphs, int& iFont, int optimise = 0 );

    static int getGlyphSet( int iFont, JtkString& sUID, int& nChars, int*& iChars, JtkPMIGlyph**& glyphs );

    static int numGlyphSetCharacters( int iFont, int& nChars, int** iChars = NULL );

    static int addGlyphSetCharacter( int iFont, int iChar, JtkPMIGlyph* glyph, int optimise = 0 );

    static int getGlyphSetCharacter( int iFont, int iChar, JtkPMIGlyph*& glyph );
};
///////%{
//
// Class          : JtkPMIGlyph
//
// Description    : Class for the representation of glyphs
//
// Enums          :
//
// Includes       : JtkPMIGlyph.h
//
// Inheritance    : JtkRefCounted > JtkPMIGlyph
//
// Visibility     : public
//
// Theory         : 
//
/////////%}
class JTK_TOOLKIT_API JtkPMIGlyph : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkPMIGlyph )

   friend class JtkEntityFactory;
   friend class _JtkPMIGlyphSetTableImpl;

protected:
   _JtkPMIGlyphImpl*      _impl;

   JtkPMIGlyph( );
   virtual ~JtkPMIGlyph( );
};
///////%{
//
// Class          : JtkPMIOutlineGlyph
//
// Description    : Class for the representation of glyphs. 
//                  Takes supplied outlineLoops which are tesselated when the Glyph is added to the 
//                  to the JtkPMIGlyphSetTable
//                  Can only be 2D.
//
// Enums          :
//
// Includes       : JtkPMIGlyph.h
//
// Inheritance    : JtkPMIGlyph > JtkPMIOutlineGlyph
//
// Visibility     : public
//
// Theory         : 
//
/////////%}
class JTK_TOOLKIT_API JtkPMIOutlineGlyph : public JtkPMIGlyph
{
   JTK_OBJECT_HEADER( JtkPMIOutlineGlyph )

   friend class JtkEntityFactory;

protected:
   JtkPMIOutlineGlyph();
   virtual ~JtkPMIOutlineGlyph();
   
public:
    int addOutlineLoop( 
        int     outer,
        int     nCurves,
        int*    curveTypes,
        int*    curveIndices,
        int     nVertices,
        double*  vertices );

    int numOutlineLoops( int& nLoops ) const;

    int getOutlineLoop( 
        int      iLoop,
        int&     outer, 
        int&     nCurves,
        int*&    curveTypes,
        int*&    curveIndices,
        int&     nVertices,
        double*&  vertices ) const;

};
///////%{
//
// Class          : JtkPMIPolygonGlyph
//
// Description    : Class for the representation of glyphs
//                  Takes primtive componenets and creates a single glyph definition with unique vertices from them.
//                  Can be 2D or 3D.
//
// Enums          : PMIPolygonPrimType(used by type)
//                     PMI_PRIMTYPE_TRIANGLES -- triangle primitive
//                     PMI_PRIMTYPE_TRIANGLES_STRIP -- triangle strip primitive
//                     PMI_PRIMTYPE_TRIANGLES_FAN -- triangle fan primitive
//                     PMI_PRIMTYPE_POLYGON -- polygon primtive
//
// Includes       : JtkPMIGlyph.h
//
// Inheritance    : JtkPMIGlyph > JtkPMIPolygonGlyph
//
// Visibility     : public
//
// Theory         : 
//
/////////%}
class JTK_TOOLKIT_API JtkPMIPolygonGlyph : public JtkPMIGlyph
{
   JTK_OBJECT_HEADER( JtkPMIPolygonGlyph )

   friend class JtkEntityFactory;
   friend class _JtkPMIGlyphSetTableImpl;

protected:   
   JtkPMIPolygonGlyph( int dimension );
   virtual ~JtkPMIPolygonGlyph();
   
public:
    int getDimension( int& dim ) const;

    int setBindings( int normalBindings,
                     int colourBindings, 
                     int textureBindings );

    int getBindings( int &normalBindings,
                     int &colourBindings, 
                     int &textureBindings )const;

    int addPrimitive( 
       int type,                       
       int nVertices,                       
       float* vertices );

    int addPrimitive( 
        int     type, 
        int     nVertices,
        float*  vertices,
        float*  normals,
        float*  colours,
        float*  textureCoordinates );

    int getInternals( int& polyDim,
                      int& primIndexLength,
                      int& primTypesLength,
                      int& numVertices,
                      int*& primTypes,
                      int*& primIndices,
                      int*& vertIndices, 
                      float*& pgVertices,
                      float*& pgNormals,
                      float*& pgColors, 
                      float*& pgTexCoords ) const;

    int getOutline( int& polyDim,
                    int& nLines,
                    int*& indices,
                    float*& vertices ) const;
};

#endif // JTK_PMI_FONT_H


