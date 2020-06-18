////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_TRAVERSER
#define JTK_TRAVERSER
#include <JtTk/JtkEntity.h>
#include <JtTk/JtkHierarchy.h>
#include <JtTk/JtkClientData.h>

///////%[
//
// Method         : int JtkTraverseActionCB( JtkHierarchy* CurrNode, int level, JtkClientData* Info )
//
// Class          : Globals
//
// Description    : A typedef for the callback functions passed to
//                  JtkTraverser::setupPreActionCallback and
//                  JtkTraverser::setupPostActionCallback.
//
// Inputs         : CurrNode -- The current product structure hierarchy node.
//                  level -- The level of the current node in the product structure hierarchy.
//                  Info -- The JtkClientData-derived object passed to JtkTraverser::traverseGraph.
//
// Outputs        :
//
// Returns        : Jtk_OK returned from JtkTraverser::setupPreActionCallback
//                  recurses down into JtkAssembly nodes. Jtk_ERROR prevents
//                  recursion to any lower level.
//                  Jtk_OK returned from JtkTraverser::setupPostActionCallback
//                  allows processing to continue. Jtk_ERROR prevents processing
//                  any further nodes.
//
// Visibility     : public
//
/////////%]
typedef int JtkTraverseActionCB( JtkHierarchy* CurrNode,
                                 int level,
                                 JtkClientData* Info );

///////%{
//
// Class          : JtkTraverser
//
// Description    : A toolkit-specific recursive product structure traversal
//                  object.  Client-defined functions may be invoked both
//                  before and after each recursion step.
//
// Enums          :
//
// Includes       : JtkTraverser.h
//
// Inheritance    : JtkRefCounted > JtkTraverser
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTraverser : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkTraverser )

public:
   virtual int setupPreActionCallback( JtkTraverseActionCB* PreActionCB ) = 0;
   virtual int setupPostActionCallback( JtkTraverseActionCB* PostActionCB ) = 0;
   virtual int traverseGraph( JtkHierarchy* Root, JtkClientData* Info = NULL) = 0;

protected:
   JtkTraverser();
   virtual     ~JtkTraverser();
};
#endif // JTK_TRAVERSER

