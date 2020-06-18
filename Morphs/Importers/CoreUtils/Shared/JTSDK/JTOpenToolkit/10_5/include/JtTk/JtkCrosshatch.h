////////////////////////////////////////////////////////////////////////////////
// Copyright 2012 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_CROSSHATCH_H
#define JTK_CROSSHATCH_H

#include <JtTk/JtkEntityFactory.h>

#ifndef CROSSHATCH_PATTERN_ACCESS
#define CROSSHATCH_PATTERN_ACCESS
#endif

#ifndef JT_CROSSHATCH_PATTERN_ACCESS
#define JT_CROSSHATCH_PATTERN_ACCESS
#endif

#ifndef CROSSHATCH_GROUP_ACCESS
#define CROSSHATCH_GROUP_ACCESS
#endif

class _JtkCrosshatchGroupImpl;
class _JtkCrosshatchPatternImpl;


///////%[
//
// Method         : struct JtkCrosshatchLineSegment( float solid, float phantom  )
//
// Class          : JtkCrosshatchGroup
//
// Description    : A structure describing a portion of a line in terms ithe length of
//                  solid and phantom sections. A line can be made of multiple segments. 
//
// Contains       : solid -- length of solid section (in meters)
//                  phantom -- length of invisible section (in meters)
//
// Visibility     : public
//
/////////%]
struct JTK_TOOLKIT_API JtkCrosshatchLineSegment
{
   float solid;
   float phantom;
};

///////%{
//
// Class          : JtkCrosshatchGroup
//
// Description    : A group of lines to be displayed at a relative angle (in degrees)
//                  and spacing within the JtkCrosshatchPattern.
//                  The groups spacing is determined via a multiplication 
//                  of the scale of the group with the entity using the  
//                  patterns spacing.
//
// Enums          :
//
// Includes       : JtkCrosshatch.h
//
// Inheritance    : JtkRefCounted > JtkCrosshatchGroup
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCrosshatchGroup : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkCrosshatchGroup )
   CROSSHATCH_GROUP_ACCESS
   _JtkCrosshatchGroupImpl* _impl;   

protected:
   JtkCrosshatchGroup( );
   virtual ~JtkCrosshatchGroup( );

public:
   int addLine( int NumSegments, JtkCrosshatchLineSegment* Segments, float Offset  = 0.0f );
   int getLine( int Index, int& NumSegments, JtkCrosshatchLineSegment*& Segments, float& Offset );
   int numLines( );   

   int setAngle( float Angle );
   int getAngle( float& Angle );

   int setScale( float Scale );
   int getScale( float& Scale );
};

///////%{
//
// Class          : JtkCrosshatchPattern
//
// Description    : A definition of a crosshatch pattern. 
//                  The pattern contains a number of JtkCrosshatchGroups    
//                  and is identified via the name.
//                  JtkCrosshatchPatterns can be added to JtkUnitHierarchy 
//                  objects for use with sections pmi and material hatching.
//
//                  The name must not contain ',' or ';' as these are reserved 
//                  within the pattern for syntax purposes.
//
// Enums          :
//
// Includes       : JtkCrosshatch.h
//
// Inheritance    : JtkRefCounted > JtkCrosshatchPattern
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkCrosshatchPattern : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkCrosshatchPattern )
   CROSSHATCH_PATTERN_ACCESS
  _JtkCrosshatchPatternImpl* _impl;

protected:
   JtkCrosshatchPattern( );
   JtkCrosshatchPattern( const JtkString& Name );
   virtual ~JtkCrosshatchPattern( );

public:
   int addGroup( JtkCrosshatchGroup*& Group );
   int getGroup( int Index, JtkCrosshatchGroup*& Group );
   int numGroups( );

   int getName( JtkString& Name );
};

#endif //JTK_CROSSHATCH_H
