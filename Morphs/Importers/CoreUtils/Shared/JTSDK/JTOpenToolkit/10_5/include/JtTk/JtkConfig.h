////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////


#ifndef JTK_CONFIG_HXX
#define JTK_CONFIG_HXX

#include <JtTk/JtkEntity.h>
#include <JtTk/JtkCADExporter.h>
#include <JtTk/JtkCADImporter.h>

class JtkConfigItem;
class JtkConfigGroup;
class JtkConfig;
class JtkParser;


///////%{
//
// Class          : JtkConfigData
//
// Description    : The base container object class to be used to add custom
//                  data within a JtkConfig hierarchy.  This class provides a
//                  means to persist client-specific state within these
//                  objects, which can then be used in the available callbacks.
//                  Note, client usage should supply read and write methods
//                  appropriate for configuration file persistence of the data
//                  stored in any instance of this class.  The supplied write
//                  method should return Jtk_OK to trigger execution of the
//                  corresponding JtkConfigGroup's or JtkConfigItem's write
//                  callback.  Otherwise, the group or item will be skipped.
//
//                  Note: Direct access to the 'InConfigFile' member variable 
//                  is deprecated in favor of the supplied access functions.
//                  At a later release direct access to this variable will be 
//                  removed. 
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigData
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigData : public JtkRefCounted
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigData )

public:
   // Callback types
   typedef int JtkConfigUpdateCB(JtkCADExporter*, JtkCADImporter*, JtkConfigData*);

   virtual int write(ostream &OutStream) = 0;
   virtual int read(JtkParser *Parser) = 0;

   int getInConfigFile( ) const;
   void setInConfigFile( int val );

   int InConfigFile; // 0 = no, 1 = yes

protected:
   // Constructor/destructor
   JtkConfigData();
   virtual ~JtkConfigData();

private:
};

///////%{
//
// Class          : JtkConfigBoolData
//
// Description    : The object for holding and persisting Boolean information
//                  in a JtkConfig hierarchy.  This is predefined for
//                  convenience.
//
//                  Note: Direct access to the 'value' member variable 
//                  is deprecated in favor of the supplied access functions.
//                  At a later release direct access to this variable will be 
//                  removed. 
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigData > JtkConfigBoolData
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigBoolData: public JtkConfigData
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigBoolData )

public:
   int value;

   int getValue( ) const;
   void setValue( int val );

   int write(ostream &OutStream);
   int read(JtkParser *Parser);
};

///////%{
//
// Class          : JtkConfigStringData
//
// Description    : The object for holding and persisting string information
//                  in a JtkConfig hierarchy.  This is predefined for
//                  convenience.
//
//                  Note: Direct access to the 'value' member variable 
//                  is deprecated in favor of the supplied access functions.
//                  At a later release direct access to this variable will be 
//                  removed. 
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigData > JtkConfigStringData
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigStringData: public JtkConfigData
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigStringData )

public:
   JtkString value;

   const JtkString& getValue( ) const;
   void setValue( const JtkString& value );

   int write(ostream &OutStream);
   int read(JtkParser *Parser);

protected:
   ~JtkConfigStringData();
};

///////%{
//
// Class          : JtkConfigFPData
//
// Description    : The object for holding and persisting floating point
//                  information in a JtkConfig hierarchy.  This is predefined
//                  for convenience.
//
//                  Note: Direct access to the 'value' member variable 
//                  is deprecated in favor of the supplied access functions.
//                  At a later release direct access to this variable will be 
//                  removed. 
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigData > JtkConfigFPData
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigFPData: public JtkConfigData
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigFPData )

public:
   double value;

   double getValue( ) const;
   void setValue( double val );

   int write(ostream &OutStream);
   int read(JtkParser *Parser);
};

///////%{
//
// Class          : JtkConfigIntData
//
// Description    : The object for holding and persisting integer information
//                  in a JtkConfig hierarchy.  This is predefined for
//                  convenience.
//
//                  Note: Direct access to the 'value' member variable 
//                  is deprecated in favor of the supplied access functions.
//                  At a later release direct access to this variable will be 
//                  removed. 
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigData > JtkConfigIntData
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigIntData: public JtkConfigData
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigIntData )

public:
   int value;

   int getValue( ) const;
   void setValue( int val );

   int write(ostream &OutStream);
   int read(JtkParser *Parser);
};



///////%{
//
// Class          : JtkConfigItem
//
// Description    : An object for defining atomic control items in a JtkConfig
//                  support hierarchy. An instance of this class is a leaf in a
//                  JtkConfig hierarchy tree.
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigItem
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigItem : public JtkRefCounted
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigItem )

public:
   // Token APIs
   virtual int setToken(const JtkString& TheToken)=0;
   virtual int getTokenSize(int &BufferSize)=0;
   virtual int getToken(JtkString& TheTokenBuffer )=0;

   // Callback types
   typedef int JtkConfigItemReadCB(JtkConfigItem*, JtkParser*);

   // Callback APIs
   virtual int setUpdateCallback(JtkConfigData::JtkConfigUpdateCB* TheCallback)=0;

   // Client-specific data APIs
   virtual int setData(JtkConfigData* TheData)=0;
   virtual int getData(JtkConfigData* &TheData)=0;

protected:
   // Constructor/destructor
   JtkConfigItem();
   virtual ~JtkConfigItem();
};


///////%{
//
// Class          : JtkConfigGroup
//
// Description    : An object for defining JtkConfig support hierarchically.
//                  An instance of this class can reference further group or
//                  item objects as children.
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfigGroup
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfigGroup : public JtkRefCounted
{
   JTK_OBJECT_TYPE_HEADER( JtkConfigGroup )

public:
   // Token APIs
   virtual int setBeginToken( const JtkString& TheToken)=0;
   virtual int getBeginTokenSize(int &BufferSize)=0;
   virtual int getBeginToken(JtkString& TheTokenBuffer )=0;
   virtual int setEndToken(const JtkString& TheToken)=0;
   virtual int getEndTokenSize(int &BufferSize)=0;
   virtual int getEndToken(JtkString& TheTokenBuffer )=0;

   // Callback types
   typedef int JtkConfigGroupCB(JtkConfigGroup*, ostream &OutStream);
   typedef int JtkConfigGroupReadCB(JtkConfigGroup*, JtkParser*);

   // Callback APIs
   virtual int setBeginUpdateCallback(JtkConfigData::JtkConfigUpdateCB* TheCallback)=0;
   virtual int setEndUpdateCallback(JtkConfigData::JtkConfigUpdateCB* TheCallback)=0;

   // Child JtkConfigGroup APIs
   virtual int numGroups()=0;
   virtual JtkConfigGroup* group(int Index)=0;
   virtual int addGroup(JtkConfigGroup* GroupToAdd)=0;
   virtual int deleteGroup(JtkConfigGroup* GroupToDelete)=0;
   virtual int deleteGroup(int Index)=0;

   // Child JtkConfigItem APIs
   virtual int numItems()=0;
   virtual JtkConfigItem* item(int Index)=0;
   virtual int addItem(JtkConfigItem* ItemToAdd)=0;
   virtual int deleteItem(JtkConfigItem* ItemToDelete)=0;
   virtual int deleteItem(int Index)=0;

   // Client-specific data APIs
   virtual int setBeginData(JtkConfigData* TheData)=0;
   virtual int getBeginData(JtkConfigData* &TheData)=0;
   virtual int setEndData(JtkConfigData* TheData)=0;
   virtual int getEndData(JtkConfigData* &TheData)=0;

   // search methods APIs
   virtual int findGroup(JtkConfigGroup* &GroupFound,
      const  JtkString& BeginToken, const JtkString& EndToken = JtkString( ))=0;
   virtual int findItem(JtkConfigItem* &ItemFound, const JtkString& Token)=0;

protected:
   // Constructor/destructor
   JtkConfigGroup();
   virtual ~JtkConfigGroup();
};


///////%{
//
// Class          : JtkConfig
//
// Description    : An object supporting run-time user control of
//                  JtkCADExporter and JtkCADImporter parameters via
//                  configuration files.
//
// Enums          :
//
// Includes       : JtkConfig.h
//
// Inheritance    : JtkRefCounted > JtkConfig
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkConfig : public JtkRefCounted
{
   JTK_OBJECT_TYPE_HEADER( JtkConfig )

public:
   // Main JtkConfig APIs
   virtual int load( const  JtkString& TheFile)=0;
   virtual int load(JtkCADImporter* TheImporter)=0;
   virtual int load(JtkCADExporter* TheExporter)=0;
   virtual int save( const JtkString& TheFile, int Format=0)=0;
   virtual int apply(JtkCADImporter* TheImporter)=0;
   virtual int apply(JtkCADExporter* TheExporter)=0;

   // Callback types
   typedef int JtkConfigCB(JtkConfigGroup*, JtkCADExporter* TheExporter, JtkCADImporter* TheImporter);

   // Callback APIs
   virtual int setPreApplyCallback(JtkConfigCB* TheCallback)=0;
   virtual int setPostApplyCallback(JtkConfigCB* TheCallback)=0;

   // Child JtkGroups per format
   virtual int numFormats()=0;
   virtual JtkConfigGroup* formatGroup(int Index)=0;
   virtual int setFormat(int Format)=0;
   virtual int getFormat(int &Format)=0;

protected:
   // Constructor/destructor
   JtkConfig();
   virtual ~JtkConfig();
};

#endif

