////////////////////////////////////////////////////////////////////////////////
// Copyright 2014 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_MOTION
#define JTK_MOTION

#include <JtTk/JtkHierarchy.h>
#include <JtTk/JtkReference.h>

//forward declarations
class _JtkMotion;
class _JtkMotionGroup;
class _JtkMotionManager;

///////%{
//
// Class          : JtkMotion
//
// Description    : The motion enacted on a targeted node.
//
// Enums          : 
//
// Includes       : JtkMotion.h
//
// Inheritance    : JtkEntity > JtkMotion
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkMotion : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkMotion )

public:  
   friend class _JtkMotionGroup;
   friend class _JtkMotion;

   const JtkReference& getOccurrencePath( ) const;

   int            addFrames( JtkTransform** Sequence,
                                     int            NumFrames );
   int            numFrames() const;
   JtkTransform*  getFrame( int Index ) const;
   int            getFrames( JtkEntityList*& Frames ) const;
   int            setNumFrames( int Number );

private:
   _JtkMotion*          _impl;

    ~JtkMotion(  );
    JtkMotion( const JtkReference& Path );
};

///////%{
//
// Class          : JtkMotionGroup
//
// Description    : A collection of motions enacted on the hierarchy 
//                  that is the context of this root group.
//                  The JtkMotionGroup can be comprised of multiple JtkMotion objects, each
//                  targetting a specific child of the context. The transforms
//                  within these JtkMotion will all be either delta or absolute matrices as
//                  defined by the JtkMotionGroup matrix type.
//
// Enums          :  MatrixType
//                    MTNEXP_ABSOLUTE -- The transforms within the JtkMotion objects
//                      representing the motion include the transforms
//                      corresponding to the static positions of the targetted occurrence.
//                    MTNEXP_DELTA -- Both the transforms corresponding to the
//                      static positions of the JtkMotion targetted occurrence
//                      and the transforms frames of the JtkMotion must be applied
//                      to find the actual position within in the motion.
//
// Includes       : JtkMotion.h
//
// Inheritance    : JtkEntity > JtkMotionGroup
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkMotionGroup : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkMotionGroup )

public:
   friend class _JtkMotionManager;
   friend class _JtkMotionGroup;

   enum MatrixType
   {
      MTNEXP_ABSOLUTE= 0,  // all matrices are absolute xformations
      MTNEXP_DELTA
   };

   JtkUnitHierarchy*     getContext( ) const;
   
   MatrixType        getMatrixType( ) const;

   JtkMotion*        addMotion( const JtkReference& );
   int               destroy( JtkMotion* );

   int               numMotions( ) const;
   
   int               getMotion( int Index, JtkMotion*& ) const;
   int               getMotion( const JtkReference&, JtkMotion*&  ) const;
   int               getMotions( JtkEntityList*& ) const;

private:
   _JtkMotionGroup*        _impl;

    ~JtkMotionGroup();
    JtkMotionGroup( JtkUnitHierarchy* context, JtkMotionGroup::MatrixType type );
};

///////%{
//
// Class          : JtkMotionManager
//
// Description    : A singleton class for managing all motion content.
//                  This should be used in preference to the deprecated API's on 
//                  JtkCADImporter, JtkMotionExporter and JtkHierarchy.
//
// Enums          : MotionFormat :
//                    JtkMotionFormat1 -- Stores a list of transforms. The
//                      frames representing the motion of each node are
//                      represented by a list of indices into the transform
//                      list.
//                    JtkMotionFormat2 -- As JtkMotionFormat1 but also stores
//                      CADIDs in legacy multibyte format.
//                    JtkMotionFormat3 -- As JtkMotionFormat1 but also stores
//                      CADIDs in UCS-2 encoded Unicode format.
//                    JtkMotionFormat4 -- As JtkMotionFormat3 but stores
//                      NGIDs rather then CADIDs
//             
//
// Includes       : JtkMotion.h
//
// Inheritance    : JtkEntity > JtkMotionManager
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkMotionManager : public JtkEntity
{
   JTK_OBJECT_HEADER( JtkMotionManager )

public:
   friend class JtkEntityFactory;
   friend class _JtkMotionManager;

   enum MotionFormat
   {
      JtkMotionFormat1 ,
      JtkMotionFormat2,
      JtkMotionFormat3,
      JtkMotionFormat4
   };
   
   JtkMotionGroup*   createMotionGroup( JtkUnitHierarchy* Context, JtkMotionGroup::MatrixType GroupType = JtkMotionGroup::MTNEXP_ABSOLUTE );
   JtkMotionGroup*   importMotionGroup( JtkHierarchy* Context, const JtkString& FileName, JtkUnits& Units );
   int               exportMotionGroup( JtkMotionGroup*, const JtkString& OutputDirectory,
                                    MotionFormat Format = JtkMotionFormat3, const JtkString& Filename = JtkString( ) ) const;
   int               destroy( JtkMotionGroup* );

   int               numMotionGroups( ) const;
   JtkMotionGroup*   getMotionGroup( int Index ) const;

private:
    _JtkMotionManager*       _impl;

    ~JtkMotionManager();
    JtkMotionManager();
};

#endif

