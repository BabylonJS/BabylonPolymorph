////////////////////////////////////////////////////////////////////////////////
// Copyright 2007 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_NULLSHAPE_HXX
#define JTK_NULLSHAPE_HXX

#include <JtTk/JtkShape.h>

///////%{
//
// Class          : JtkNullShape
//
// Description    : JtkNullShape is used for a part where its shape type
//                  is unknown and will be determined later by some other
//                  module(s). The JtkNullShape object should be replaced or
//                  deleted after the actual shape of the part is constructed.
//                  Internal use only.
//
// Enums          :
//
// Includes       : JtkNullShape.h
//
// Inheritance    : JtkShape > JtkNullShape
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkNullShape : public JtkShape
{
   JTK_OBJECT_HEADER( JtkNullShape )

public:

protected:

   JtkNullShape();

   virtual  ~JtkNullShape();
};
#endif // !JTK_NULLSHAPE_HXX

