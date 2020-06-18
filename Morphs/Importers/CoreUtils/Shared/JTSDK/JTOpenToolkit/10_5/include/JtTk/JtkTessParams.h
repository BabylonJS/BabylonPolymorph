////////////////////////////////////////////////////////////////////////////////
// Copyright 2007 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_TESSPARAMS_HXX
#define JTK_TESSPARAMS_HXX

#include <JtTk/JtkClientData.h>
#include <JtTk/JtkString.h>

///////%{
//
// Class          : JtkTessParams
//
// Description    : Container class for parameters to control tessellation.
//
// Enums          : TessParamOption
//                    JtkTESSELLATION_CHORDAL -- chordal for tessellation (float)
//                    JtkTESSELLATION_ANGULAR -- angular for tessellation in radians (float)
//                    JtkTESSELLATION_LENGTH -- length for tessellation (float)
//                    JtkTESSELLATION_MAX_ASPECT -- maximum aspect for tessellation (float)
//                    JtkTESSELLATION_MIN_ANGLE -- minimum angle for tessellation (float)
//                    JtkBREP_HOLE_REMOVAL_FRACTION -- brep simplifier (float)
//                    JtkTESSELLATION_MIN_EDGE_LENGTH -- minimum edge length (float)
//                    JtkTESSELLATION_TRIM_SUPPRESS -- boolean flag for trim suppress (int [0,1])
//                    JtkTESSELLATION_LOD_LABEL -- LOD label (JtkString)
//                    JtkADV_COMPRESS_LEVEL -- compression level used when Advanced Compression is enabled (float)
//                    JtkSIMPLIFIER_FRACTION -- auto-LOD generation using simplifier (float)
//                    JtkTESSELLATION_RELATIVE_CHORDAL -- boolean flag for relative chordal (int [0,1])
//
// Includes       : JtkTessParams.h
//
// Inheritance    : JtkClientData > JtkTessParams
//
// Visibility     : public
//
// Theory         :
//
/////////%}
class JTK_TOOLKIT_API JtkTessParams : public JtkClientData
{
   JTK_OBJECT_HEADER( JtkTessParams )

public:

   // equality operator
   int operator            ==( const JtkTessParams &OtherTessParams ) const;

   // Tessellation interface
   enum TessParamOption
   {
      JtkTESSELLATION_CHORDAL          = 1,  // chordal for tessellation (float)
      JtkTESSELLATION_ANGULAR          = 2,  // angular for tessellation (float)
      JtkTESSELLATION_LENGTH           = 3,  // length for tessellation (float)
      JtkTESSELLATION_MAX_ASPECT       = 4,  // max aspect for tess (float)
      JtkTESSELLATION_MIN_ANGLE        = 5,  // min angle for tessellation (float)
      JtkBREP_HOLE_REMOVAL_FRACTION    = 6,  // brep simplifier (float)
      JtkTESSELLATION_MIN_EDGE_LENGTH  = 7,  // minimum edge length (float)
      JtkTESSELLATION_TRIM_SUPPRESS    = 8,  // boolean flag for trim suppress (int [0,1])
      JtkTESSELLATION_LOD_LABEL        = 9,  // LOD label (JtkString)
      JtkADV_COMPRESS_LEVEL            = 10, // compression level used when Advanced Compression is enabled (float)
      JtkSIMPLIFIER_FRACTION           = 11, // auto-LOD generation using simplifier (float)
      JtkTESSELLATION_RELATIVE_CHORDAL = 12, // boolean flag for relative chordal (int [0,1])
   };

   // Get parameters
   virtual int getParameter( TessParamOption TheParam, double &TheValue ) const = 0;
   virtual int getParameter( TessParamOption TheParam, float &TheValue ) const = 0;
   virtual int getParameter( TessParamOption TheParam, JtkString& TheValue ) const = 0;
   virtual int getParameter( TessParamOption TheParam, int &TheValue ) const = 0;
   
   // Set parameters
   virtual int setParameter( TessParamOption TheParam, double TheValue ) = 0;
   virtual int setParameter( TessParamOption TheParam, float TheValue ) = 0;
   virtual int setParameter( TessParamOption TheParam, const JtkString& TheValue ) = 0;
   virtual int setParameter( TessParamOption TheParam, int TheValue ) = 0;
   
protected:
   // Constructor
   JtkTessParams();

   // destructor
   virtual ~JtkTessParams();

private:
};

#endif   // !JTK_TESSPARAMS_HXX

