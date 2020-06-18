////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_MOTION_EXPORTER_H_
#define JTK_MOTION_EXPORTER_H_

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkString.h>

// forward references
class JtkHierarchy;
class JtkTransform;
class JtkAssembly;

///////%{
//
// Class          : JtkMotionExporter
//
// Description    : Writes out a motion (VFM) file.
//                  Note: the JtkMotionExporter class has been deprecated
//                  in favor of the JtkMotionManager class and the support there.
//
// Enums          : MatrixType
//                    MTNEXP_ABSOLUTE -- The transforms on the frames
//                      representing the motion include the transforms
//                      corresponding to the static positions of the nodes.
//                    MTNEXP_DELTA -- Both the transforms corresponding to the
//                      static positions of the nodes and the transforms on the
//                      frames representing the motion must be applied to the
//                      nodes to find their actual positions in the motion.
//
//                  MotionFormat
//                    JtkMotionFormat1 -- Stores a list of transforms. The
//                      frames representing the motion of each node are
//                      represented by a list of indices into the transform
//                      list.
//                    JtkMotionFormat2 -- As JtkMotionFormat1 but also stores
//                      CADIDs in legacy multibyte format.
//                    JtkMotionFormat3 -- As JtkMotionFormat1 but also stores
//                      CADIDs in UCS-2 encoded Unicode format.
//                    JtkMotionFormat4 -- As JtkMotionFormat3 but also stores
//                      NGIDs.
//
// Includes       : JtkMotionExporter.h
//
// Inheritance    : JtkRefCounted > JtkMotionExporter
//
// Visibility     : public
//
// Theory         :
//
// Special_Status : deprecated
//
/////////%}
class JTK_TOOLKIT_API JtkMotionExporter : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkMotionExporter )

public:
   enum MatrixType
   {
      MTNEXP_ABSOLUTE= 0,  // all matrices are absolute xformations
      MTNEXP_DELTA
   };

   // xformations are applied to existing
   // ones in assembly
   enum MotionFormat
   {
      JtkMotionFormat1  = 0,
      JtkMotionFormat2,
      JtkMotionFormat3,
      JtkMotionFormat4
   };

   // reset a node's motion list
   virtual int           resetMotionList( JtkHierarchy* node ) = 0;

   //append an array of JtkTransform to the node.
   //numFrames is the number of JtkTransform in sequence array
   virtual int           addFrames( JtkHierarchy*  node,
                                    JtkTransform** sequence,
                                    int            numFrames ) = 0;

   // Set the directory path for the exported motion. _path_ specifies an
   // absolute path to an existing directory where the assembly database is
   // to be written.
   virtual int           setExportPath( const JtkString& path ) = 0;

   // Accessor methods for the current assembly graph.
   virtual void          setCurrentAssembly( JtkAssembly* assm ) = 0;
   virtual JtkHierarchy* currentAssembly() = 0;

   virtual void          setMotionFormat( MotionFormat ) = 0;
   virtual MotionFormat  getMotionFormat() = 0;

   // Returns Jtk_OK if the export process completed without
   // interruption or error.
   virtual int           exportMotion( JtkMotionExporter::MatrixType,
                                       const JtkString& sFileName = JtkString( ) ) = 0;

   // initialize the current animation. this is only needed if
   // you are exporting more than one animation for the current
   // assembly hierarchy.
   virtual int           initAnimation( const JtkString& aname ) = 0;

protected:
   JtkMotionExporter();
   virtual  ~JtkMotionExporter();
};
#endif

