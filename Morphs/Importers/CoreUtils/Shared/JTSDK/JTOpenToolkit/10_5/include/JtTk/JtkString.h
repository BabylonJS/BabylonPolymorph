////////////////////////////////////////////////////////////////////////////////
// Copyright 2013 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////
#ifndef JTK_STRING_HXX
#define JTK_STRING_HXX

#include <JtTk/JtkStandard.h>

//forward declare and typedefs
struct JtkStringImpl;

typedef char JtkUTF8;
typedef unsigned short  JtkUTF16;

///////%{
//
// Class          : JtkString
//
// Description    : JtkString class.
//
// Includes       : JtkString.h
//
// Inheritance    : JtkString
//
// Visibility     : public
//
// Theory         : 
//
/////////%}
class JTK_TOOLKIT_API JtkString
{
   JtkStringImpl*          m_pImpl;

   JtkString( JtkStringImpl* );
public:
   // constructors
   JtkString( );
   JtkString( const JtkUTF8* stringUTF8 );
   JtkString( const JtkUTF16* stringUTF16 );
   JtkString( const JtkString& );  
   
   //destructor
   ~JtkString( );  

   //assignment operator
   JtkString&  operator = ( const JtkString& rhs );

   //determines if the string is empty
   int         isEmpty ( ) const;
   
   //clears the strings
   int         clear ( );
   
   //length of the unicode string 
   int         length ( ) const;

   //test to see if the string contain another string
   int         contains( const JtkString& ) const;
   
   // Get the index of a substring
   int         find(const JtkString& str, int startAt = 0) const;

   //Get the substring
   int         subString( int index, JtkString& substring, int num = -1 ) const;
   
    //set the value
   int         setString( const JtkUTF8* ) ;
   int         setString( const JtkUTF16* ) ;

   //get the value
   int         getString( JtkUTF8*&, int& length ) const;
   int         getString( JtkUTF16*&, int& length ) const;

   //remove content from string
   int         remove( int index, int num = -1 );

   //helpful operators
   int         operator == ( const JtkString& rhs ) const;
   int         operator != ( const JtkString& rhs ) const; 
   JtkString&  operator += ( const JtkString& rhs );
   JtkString   operator + ( const JtkString& rhs ) const;

   JTK_TOOLKIT_API friend ostream& operator << (ostream& os, const JtkString& rhs);
   
   //static utility abilities
   static int isUTF8Encoded( const JtkUTF8* );

   //access to the implementation
   const JtkStringImpl* constImpl() const;
   JtkStringImpl*       impl();
};


#endif //JTK_STRING_HXX
