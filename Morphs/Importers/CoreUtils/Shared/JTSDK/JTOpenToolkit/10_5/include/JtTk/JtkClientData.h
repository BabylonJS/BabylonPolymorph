////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_CLIENT_DATA_HXX
#define JTK_CLIENT_DATA_HXX

#include <JtTk/JtkEntity.h>

///////%{
//
// Class          : JtkClientData
//
// Description    : The base container object class intended to transport 
//                  necessary client-specific data within the toolkit.  Use of
//                  objects derived from this class is optional, and does not 
//                  adversely affect toolkit performance or behavior.  Such 
//                  data is not persisted to exported files.
//
//                  Note, this object inherits the reference-counting mechanism
//                  inherent to all JtkEntity-derived objects.  To implement
//                  this mechanism properly, all inheriting classes should
//                  have protected destructors forcing dynamic allocation
//                  (i.e. "new"ed instances) by the client application.  If
//                  these objects are not created dynamically within the
//                  application, catastrophic errors may result.
//
// Enums          :
//
// Includes       : JtkClientData.h
//
// Inheritance    : JtkRefCounted > JtkClientData
//
// Visibility     : public
//
// Theory         : No public data members or methods.  The client application
//                  should inherit their own class objects from this class
//                  adding member data to fit their own purposes.
//
/////////%}
class JTK_TOOLKIT_API JtkClientData : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkClientData )

public:
   int operator            ==( const JtkClientData &OtherClientData )const;

protected:
   JtkClientData();
   virtual  ~JtkClientData();
};
#endif

